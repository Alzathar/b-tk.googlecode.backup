/* 
 * The Biomechanical ToolKit
 * Copyright (c) 2009-2010, Arnaud Barré
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 *     * Redistributions of source code must retain the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *     * Neither the name(s) of the copyright holders nor the names
 *       of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written
 *       permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __btkGroundReactionWrenchFilter_h
#define __btkGroundReactionWrenchFilter_h

#include "btkProcessObject.h"
#include "btkForcePlatformCollection.h"
#include "btkForcePlatformTypes.h"
#include "btkWrenchCollection.h"

#include <Eigen/Array>
#include <Eigen/Geometry>

namespace btk
{
  class GroundReactionWrenchFilter : public ProcessObject
  {
  public:
    typedef SharedPtr<GroundReactionWrenchFilter> Pointer;
    typedef SharedPtr<const GroundReactionWrenchFilter> ConstPointer;

    static Pointer New() {return Pointer(new GroundReactionWrenchFilter());};
    
    // ~GroundReactionWrenchFilter(); // Implicit

    bool GetThresholdState() const {return this->m_ThresholdActivated;};
    BTK_BASICFILTERS_EXPORT void SetThresholdState(bool activated = false);
    double GetThresholdValue() const {return this->m_ThresholdValue;};
    BTK_BASICFILTERS_EXPORT void SetThresholdValue(double v);
    
    ForcePlatformCollection::Pointer GetInput() {return this->GetInput(0);};
    void SetInput(ForcePlatform::Pointer input)
    {
      ForcePlatformCollection::Pointer col = ForcePlatformCollection::New();
      col->InsertItem(input);
      this->SetNthInput(0, col);
    };
    void SetInput(ForcePlatformCollection::Pointer input) {this->SetNthInput(0, input);};
    WrenchCollection::Pointer GetOutput() {return this->GetOutput(0);};

  protected:
    BTK_BASICFILTERS_EXPORT GroundReactionWrenchFilter();
    
    ForcePlatformCollection::Pointer GetInput(int idx) {return static_pointer_cast<ForcePlatformCollection>(this->GetNthInput(idx));};  
    WrenchCollection::Pointer GetOutput(int idx) {return static_pointer_cast<WrenchCollection>(this->GetNthOutput(idx));};
    BTK_BASICFILTERS_EXPORT virtual DataObject::Pointer MakeOutput(int idx);
    BTK_BASICFILTERS_EXPORT virtual void GenerateData();
    
  private:
    inline void FinishGRWComputation(Wrench::Pointer grw, const ForcePlatform::Origin& o) const;
    inline void TransformGRWToGlobal(Wrench::Pointer grw, const ForcePlatform::Corners& c) const;

    GroundReactionWrenchFilter(const GroundReactionWrenchFilter& ); // Not implemented.
    GroundReactionWrenchFilter& operator=(const GroundReactionWrenchFilter& ); // Not implemented.

    bool m_ThresholdActivated;
    double m_ThresholdValue;
  };

  void GroundReactionWrenchFilter::FinishGRWComputation(Wrench::Pointer grw, const ForcePlatform::Origin& o) const
  { 
    typedef Eigen::Matrix<double, Eigen::Dynamic, 1> Component;
    Component Fx = grw->GetForce()->GetValues().col(0);
    Component Fy = grw->GetForce()->GetValues().col(1);
    Component Fz = grw->GetForce()->GetValues().col(2);
    Component Mx = grw->GetMoment()->GetValues().col(0);
    Component My = grw->GetMoment()->GetValues().col(1);
    Component Mz = grw->GetMoment()->GetValues().col(2);
    Component Px = grw->GetPosition()->GetValues().col(0);
    Component Py = grw->GetPosition()->GetValues().col(1);
    Component Pz = grw->GetPosition()->GetValues().col(2);

    // Square norm of the forces.
    Component sNF =  grw->GetForce()->GetValues().rowwise().squaredNorm();
    // M_s = M_o + F x OS
    Mx += Fy * o.z() - o.y() * Fz;
    My += Fz * o.x() - o.z() * Fx;
    Mz += Fx * o.y() - o.x() * Fy;
    // PWA
    // For explanations of the PWA calculation, see Shimba T. (1984), 
    // "An estimation of center of gravity from force platform data", 
    // Journal of Biomechanics 17(1), 53–60.
    Px = (Fy.cwise() * Mz - Fz.cwise() * My).cwise() / sNF
         - (Fx.cwise().square().cwise() * My - Fx.cwise() * (Fy.cwise() * Mx)).cwise() / (sNF.cwise() * Fz);
    Py = (Fz.cwise() * Mx - Fx.cwise() * Mz).cwise() / sNF
         - (Fx.cwise() * (Fy.cwise() * My) - Fy.cwise().square().cwise() * Mx).cwise() / (sNF.cwise() * Fz);
    Pz.setZero();
    // Suppress false PWA
    if (this->m_ThresholdActivated)
    {
      for (int i = 0 ; i < Fz.rows() ; ++i)
      {
        if (fabs(Fz.coeffRef(i)) <= this->m_ThresholdValue)
        {
          Px.coeffRef(i) = 0.0;
          Py.coeffRef(i) = 0.0;
          Pz.coeffRef(i) = 0.0;
          grw->GetPosition()->GetResiduals().coeffRef(i) = -1.0;
          grw->GetPosition()->GetMasks().coeffRef(i) = -1.0;
        }
      }
    }
    // M_pwa = M_s + F_s x PWA
    Mx += Fy.cwise() * Pz - Py.cwise() * Fz;
    My += Fz.cwise() * Px - Pz.cwise() * Fx;
    Mz += Fx.cwise() * Py - Px.cwise() * Fy;

    grw->GetForce()->GetValues().col(0) = Fx;
    grw->GetForce()->GetValues().col(1) = Fy;
    grw->GetForce()->GetValues().col(2) = Fz;
    grw->GetMoment()->GetValues().col(0) = Mx;
    grw->GetMoment()->GetValues().col(1) = My;
    grw->GetMoment()->GetValues().col(2) = Mz;
    grw->GetPosition()->GetValues().col(0) = Px;
    grw->GetPosition()->GetValues().col(1) = Py;
    grw->GetPosition()->GetValues().col(2) = Pz;
  };

  void GroundReactionWrenchFilter::TransformGRWToGlobal(Wrench::Pointer grw, const ForcePlatform::Corners& c) const
  {
    Eigen::Matrix<double, 3, 3> R;
    Eigen::Matrix<double, 3, 1> t;

    R.col(0) = c.col(0) - c.col(1);
    R.col(0).normalize();
    R.col(1) = c.col(0) - c.col(3);
    R.col(1).normalize();
    R.col(2) = R.col(0).cross(R.col(1));
    t = (c.col(0) + c.col(2)) / 2;
    // Forces & Moments rotation
    grw->GetForce()->GetValues() *= R.transpose();
    grw->GetMoment()->GetValues() *= R.transpose();
    // Position rotation
    grw->GetPosition()->GetValues() *= R.transpose();
    // Position translation
    grw->GetPosition()->GetValues().col(0).cwise() += t.x();
    grw->GetPosition()->GetValues().col(1).cwise() += t.y();
    grw->GetPosition()->GetValues().col(2).cwise() += t.z();
  };
};

#endif // __btkGroundReactionWrenchFilter_h

