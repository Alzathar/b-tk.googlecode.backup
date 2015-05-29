# BTKCore Roadmap #

The next sections lists the proposed fixes, updates, and improvements of the BTKCore project as the developers would like to do. No schedule is proposed to release each new version as it depends mainly of the availabilities of each contributor.

Keep looking for any modifications in this wiki page. More details will be given on each proposed release along the time.


---


## v0.4 ##
  * **Common**
    * Refactorting of the metadata stored in an acquisition:
      * All the metadata will be flattened to simplify their extraction.
      * The class `btk::MetaDataInfo` will be removed and the values will be stored in the metadata.
      * Simplification of the API to extract value(s) even if the metadata does not exist.
    * Each class inheriting of the class `btk::DataObject` could contain a dictionnary of metadata.
  * **IO**
    * <font color='orange'>NOTE:</font> : The listed file formats can change in case there is no way to implement the reader without breaking possible copyrights.
    * Implementation of a reader for the HPF (Delsys) file format.
    * Implementation of a reader for the QTM (Qualysis) file format.
    * Implementation of a reader for the GT3X (Actigraph) file format.
  * **BasicFilters**
    * Update of the filters to use known metadata when the required inputs are not given.
  * **Bindings**
    * Matlab/Octave/Python
      * Update of the bindings regarding the modification of the C++ API.

---


## v0.5 ##
  * **Models** <font color='green'>(New module)</font>
    * Implementation of classes to represent generic biomechanical models (e.g. Segment, Joint, Model, ReferenceFrame, etc.).
    * Implementation of filters to process biomechanical models (e.g. Computation of segments' poses during time using geometric estimation, Algorithms for functionnal calibration, Estimation of joint kinematics).
  * **Bindings**
    * Python
      * Wrapping of the Models module.

---


## v0.6 ##

  * **Models**
    * Integration of pre-defined biomechanical models.
      * <font color='orange'>NOTE:</font> :  The following list can change depending of the result of the validation tests.
      * ISB (from the articles of Wu et al. 2002, 2005)
      * PlugInGait (Vicon)
      * Helen Hayes (Motion Analysis Inc.)
    * Development of additional filters to be able to extract outputs used in a Clinical Gait Analysis (CGA).
  * **Bindings**
    * Matlab/Octave
      * Wrapping of the Models module to easily use pre-defined biomechanical models and access to their contents
    * Python
      * Update of the wrapping to include modifications in the Models module.