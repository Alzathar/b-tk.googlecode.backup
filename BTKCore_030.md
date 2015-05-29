# Modifications between BTK 0.2.1 and BTKCore 0.3 #

_BTKCore 0.3 was released the 9 January 2014._

**Note**
The Biomechanical ToolKit project was split in three parts to facilitate the release cycles
  * BTKCore: contains the C++ modules (Common/IO/BasicFilters/...) + the bindings (Matlab/Octave & Python)
  * BTKQt: Qt5 widgets to display biomechanical data (not yet available)
  * Mokka: All the code of BTK/Tools/Mokka has now is own repository (not yet available)

The modifications presented below are only for BTKCore. The source code is available in the git repository  [b-tk.core](https://code.google.com/p/b-tk/source/list?repo=core)


---


This release improves mostly the internal behavior of the C++ API and fix issues related to the Python/Octave/Matlab bindings. Lots of works were done to consolidate the basis of this project. For example, continuous integration was configured on MacOS X, Linux, and Windows platforms with hundred of cases tested at each modification of the code.

# General #
  * <font color='red'>IMPORTANT:</font> The source code for Mokka and the BTKVTK module (used only by Mokka) was removed from BTKCore.
  * Eigen 3 updated from Eigen 3.1.2 to Eigen 3.2
  * New unit tests for the reading of the path encoded in UTF-8.
  * General improvement of the unit tests for the Matlab/Octave/Python bindings (e.g. the use of command `'make test'` will launch the unit tests for all the compiled libraries and bindings)
  * BTK error messages split to distinguish warning messages from error messages
  * CMake option BTK\_WRAP\_SCILAB discarded until the Scilab team fix the issue [6886](http://bugzilla.scilab.org/show_bug.cgi?id=6886).
  * CMake option BTK\_USE\_SYSTEM\_EIGEN3 removed  as the embedded version was modified to include "plugins" for the VectorOp class. Moreover, the code in btkEigen was not found if BTK\_USE\_SYSTEM\_EIGEN3 was used.
  * CMake scripts added to package the Python binging in native installers (Linux, Windows) or as EGG package when not possible (MacOS X).

# Modules #
> ## Common ##
    * **Enhancements**
      * New classes `btk::Point::Data` and `btk::Analog::Data` to store the data associated with points and analog channels. It will give the possibility to set data from one measure to another without the copy of the values (and other informations, like point's residual).
      * New class `btk::Logger` to manage debug/warning/error messages more easily. See the macro `btkDebugMacro`, `btkWarningMacro`, and `btkErrorMacro`
      * Introduction of the `btk::NullPtr` class and static `Null()` method for all classes deriving of the class `btk::DataObject`. This should simplify the syntax to test the nullity of a shared pointer without to know the exact API behind the macro `btkSharedPtr` (i.e. for the class `(boost|std)::[tr1::]shared_ptr`).
    * **Updates**
      * <font color='red'>IMPORTANT:</font> Macro `SharedPtr` renamed `btkSharedPtr` as the scope of the macro cannot be limited to the namespace `btk`.
      * New methods to access to the front and back items in a `btk::Collection`.
      * Modification to create a force platform. The class `btk::ForcePlatformTypes` is now only a convenient class used to create `btk::ForcePlatform::Pointer` objects by using its `New()` method.
      * Macro `btkIOErrorMacro` removed and replaced by the use of `btkWarningMacro` with two arguments.
      * If the number of outputs is modified in a filter, then the outputs already created are no more replaced.
      * The source associated with existing outputs will be set to null when the number of outputs of a filter is reduced.
    * **Fixes**
      * Corrupted memory in some case when point and analog data are resized under Linux (Ubuntu 12.04 - 64bit, GCC 4.6).
      * Adapted events’ time are wrongly delayed of +1 frame in the method `btk::Acquistion::SetFirstFrame`.
> ## IO ##
    * **Enhancements**
      * Experimental file reader for the BSF file format (AMTI).
    * **Updates**
      * [Issue #70](https://code.google.com/p/b-tk/issues/detail?id=#70): "Support TRC file with unnamed markers"
      * Class `btk::AcquisitionFileIO` has an advanced option to specify how file format internals are generated. Only the C3D file format uses this advanced option to generate the groups/parameters from data (default) or use existing ones.
      * New class (`btk::AcquisitionFileIORegister`) to add dynamically and more easily a new acquisition file IO
> ## BasicFilters ##
    * **Updates**
      * Modification of the class `btk::IMUsExtractor` and the metadata required to extract an optionnal calibration matrix as well as extra channels.

# Bindings #
> ## Matlab/Octave ##
    * **Enhancements**
      * New function `btkCloseAcquisistion` (alias for the function `btkDeleteAcquisistion`).
      * New function `btkSetMetaData`.
      * New function `btkSetMetaDataValues`.
    * **Updates**
      * The function `btkWriteAcquisition` has a new option `RegenerateInternals` to specify how the internals of a file format are generated (if any).
      * The function `btkGetPoint` has a new third output which contains details (true label, description, frequency, units) on the extracted point.
      * The second output of the functions `btkGetAnalog`, `btkGetAnalogs`, and `btkGetPoints` has two new fields which store the (true) label and the description of the extracted item.
      * Improvement of the function `btkEmulateC3Dserver` to fit the same behaviour than C3Dserver regarding the events’ command (events stored in the C3D header section, only events stored in the header are listed, etc.).
    * **Fixes**
      * [Issue #74](https://code.google.com/p/b-tk/issues/detail?id=#74): "Matlab C3Dserver emulator SetParameterValue Problem".
      * [Issue #66](https://code.google.com/p/b-tk/issues/detail?id=#66): “Fix the issue related to btkAppendMetaData and the possible missing field numdims”.
      * Default groups/parameters are now generated within the C3Dserver command `NewFile`.
      * Wrong data type passed into `btkSet*` can corrupt acquisition data (using single type instead of double)
      * Wrong checks in the data type / number of elements for the value to set in a metadata using `btkSetMetaDataValue`.
      * Generation of the internal ID fixed when `btkEmulateC3Dserver` is called more than once in the same function.
> ## Octave ##
    * **Fixes**
      * Infinite loop with Octave 3.6.4 when a warning message was print from BTK (`std::cerr` redirection to `mexPrintf` or `mexWarnMsgIdAndTxt`).
> ## Python ##
    * **Updates**
      * Binding updated to take into account the latest modifications in the C++ modules.
    * **Fixes**
      * Some C++ method for the class `btk::ForcePlatform` wrongly wrapped in the Python binding.
      * Missing a second optional argument in the method `btk.btkAcquisition.SetFirstFrame`.