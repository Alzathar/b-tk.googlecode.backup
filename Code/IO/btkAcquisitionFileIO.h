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

#ifndef __btkAcquisitionFileIO_h
#define __btkAcquisitionFileIO_h

#include "btkAcquisition.h"

#include <string>

namespace btk
{
  class AcquisitionFileIO
  {
  public:
    typedef SharedPtr<AcquisitionFileIO> Pointer;
    typedef SharedPtr<const AcquisitionFileIO> ConstPointer;
    
    typedef enum {TypeNotApplicable, ASCII, Binary} FileType;
    typedef enum {OrderNotApplicable = 0, IEEE_LittleEndian, VAX_LittleEndian, IEEE_BigEndian} ByteOrder;
    typedef enum {StorageNotApplicable = 0, Float = -1, Integer = 1} StorageFormat;

    FileType GetFileType() const {return this->m_FileType;};
    ByteOrder GetByteOrder() const {return this->m_ByteOrder;};
    void SetByteOrder(ByteOrder b) {this->m_ByteOrder = b;};
    StorageFormat GetStorageFormat() const {return this->m_StorageFormat;};
    void SetStorageFormat(StorageFormat s) {this->m_StorageFormat = s;};

    BTK_IO_EXPORT virtual bool CanReadFile(const std::string& filename) = 0;
    BTK_IO_EXPORT virtual bool CanWriteFile(const std::string& filename) = 0;
    BTK_IO_EXPORT virtual void Read(const std::string& filename, Acquisition::Pointer output) = 0;
    BTK_IO_EXPORT virtual void Write(const std::string& filename, Acquisition::Pointer input) = 0;
    
  protected:
    BTK_IO_EXPORT AcquisitionFileIO();
    virtual ~AcquisitionFileIO() {};
    
    void SetFileType(FileType f) {this->m_FileType = f;};
        
    FileType m_FileType;
    ByteOrder m_ByteOrder;
    StorageFormat m_StorageFormat;
    
  private:
    AcquisitionFileIO(const AcquisitionFileIO& ); // Not implemented.
    AcquisitionFileIO& operator=(const AcquisitionFileIO& ); // Not implemented.
  };
};

#endif // __btkAcquisitionFileIO_h
