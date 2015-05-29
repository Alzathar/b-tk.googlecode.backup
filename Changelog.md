<h1>Changelog</h1>

This page contains the changelog for BTK. The changelog for Mokka moved [here](https://b-tk.googlecode.com/svn/web/mokka/news.html).



<table width='100%'><tr><td>

<h2>BTKCore 0.3</h2>
<hr />
Released on January 9, 2014<br>
<br>
<ul><li><b>General</b>
<ul><li><font color='red'>IMPORTANT:</font> The source code for Mokka and the BTKVTK module (used only by Mokka) was removed from BTKCore.<br>
</li><li>UPD: Eigen 3 updated from Eigen 3.1.2 to Eigen 3.2</li></ul></li></ul>

<ul><li><b>CMake</b>
<ul><li>UPD: General improvement of the unit tests for the Matlab/Octave/Python bindings (e.g. the use of command <code>'make test'</code> will launch the unit tests for all the compiled libraries and bindings)<br>
</li><li>UPD: CMake option BTK_WRAP_SCILAB discarded until the Scilab team fix the issue <a href='http://bugzilla.scilab.org/show_bug.cgi?id=6886'>6886</a>.<br>
</li><li>UPD: CMake option BTK_USE_SYSTEM_EIGEN3 removed  as the embedded version was modified to include "plugins" for the VectorOp class. Moreover, the code in btkEigen was not found if BTK_USE_SYSTEM_EIGEN3 was used.<br>
</li><li>UPD: CMake scripts added to package the Python binging in native installers (Linux, Windows) or as EGG package when not possible (MacOS X).</li></ul></li></ul>

<ul><li><b>Common</b>
<ul><li><font color='red'>IMPORTANT:</font> Macro <code>SharedPtr</code> renamed <code>btkSharedPtr</code> as the scope of the macro cannot be limited to the namespace <code>btk</code>.<br>
</li><li>ENH: New classes <code>btk::Point::Data</code> and <code>btk::Analog::Data</code> to store the data associated with points and analog channels. It will give the possibility to set data from one measure to another without the copy of the values (and other informations, like point's residual).<br>
</li><li>ENH: New class <code>btk::Logger</code> to manage debug/warning/error messages more easily. See the macro <code>btkDebugMacro</code>, <code>btkWarningMacro</code>, and <code>btkErrorMacro</code>
</li><li>ENH: Introduction of the <code>btk::NullPtr</code> class and static <code>Null()</code> method for all classes deriving of the class <code>btk::DataObject</code>. This should simplify the syntax to test the nullity of a shared pointer without to know the exact API behind the macro <code>btkSharedPtr</code> (i.e. for the class <code>(boost|std)::[tr1::]shared_ptr</code>).<br>
</li><li>ENH: BTK error messages split to distinguish warning messages from error messages<br>
</li><li>UPD: New methods to access to the front and back items in a <code>btk::Collection</code>.<br>
</li><li>UPD :Modification to create a force platform. The class <code>btk::ForcePlatformTypes</code> is now only a convenient class used to create <code>btk::ForcePlatform::Pointer</code> objects by using its <code>New()</code> method.<br>
</li><li>UPD: Macro <code>btkIOErrorMacro</code> removed and replaced by the use of <code>btkWarningMacro</code> with two arguments.<br>
</li><li>UPD: If the number of outputs is modified in a filter, then the outputs already created are no more replaced.<br>
</li><li>UPD: The source associated with existing outputs will be set to null when the number of outputs of a filter is reduced.<br>
</li><li>FIX: Corrupted memory in some case when point and analog data are resized under Linux (Ubuntu 12.04 - 64bit, GCC 4.6).<br>
</li><li>FIX: Adapted events’ time are wrongly delayed of +1 frame in the method <code>btk::Acquistion::SetFirstFrame</code>.</li></ul></li></ul>

<ul><li><b>IO</b>
<ul><li>ENH: Experimental file reader for the BSF file format (AMTI).<br>
</li><li>UPD: <a href='https://code.google.com/p/b-tk/issues/detail?id=#70'>Issue #70</a>: "Support TRC file with unnamed markers"<br>
</li><li>UPD: Class <code>btk::AcquisitionFileIO</code> has an advanced option to specify how file format internals are generated. Only the C3D file format uses this advanced option to generate the groups/parameters from data (default) or use existing ones.<br>
</li><li>UPD: New class (<code>btk::AcquisitionFileIORegister</code>) to add dynamically and more easily a new acquisition file IO<br>
</li><li>UPD: New unit tests for the reading of the path encoded in UTF-8.</li></ul></li></ul>

<ul><li><b>BasicFilters</b>
<ul><li>UPD: Modification of the class <code>btk::IMUsExtractor</code> and the metadata required to extract an optionnal calibration matrix as well as extra channels.</li></ul></li></ul>

<ul><li><b>Bindings</b>
<ul><li>ENH: Matlab/Octave: New function <code>btkCloseAcquisistion</code> (alias for the function <code>btkDeleteAcquisistion</code>).<br>
</li><li>ENH: Matlab/Octave: New function <code>btkSetMetaData</code>.<br>
</li><li>ENH: Matlab/Octave: New function <code>btkSetMetaDataValues</code>.<br>
</li><li>UPD: Python: Binding updated to take into account the latest modifications in the C++ modules.<br>
</li><li>UPD: Matlab/Octave: The function <code>btkWriteAcquisition</code> has a new option <code>RegenerateInternals</code> to specify how the internals of a file format are generated (if any).<br>
</li><li>UPD: Matlab/Octave: The function <code>btkGetPoint</code> has a new third output which contains details (true label, description, frequency, units) on the extracted point.<br>
</li><li>UPD: Matlab/Octave: The second output of the functions <code>btkGetAnalog</code>, <code>btkGetAnalogs</code>, and <code>btkGetPoints</code> has two new fields which store the (true) label and the description of the extracted item.<br>
</li><li>UPD: Matlab/Octave: Improvement of the function <code>btkEmulateC3Dserver</code> to fit the same behaviour than C3Dserver regarding the events’ command (events stored in the C3D header section, only events stored in the header are listed, etc.).<br>
</li><li>FIX: Python: Some C++ method for the class <code>btk::ForcePlatform</code> wrongly wrapped in the Python binding.<br>
</li><li>FIX: Python: Missing a second optional argument in the method <code>btk.btkAcquisition.SetFirstFrame</code>.<br>
</li><li>FIX: Matlab/Octave: <a href='https://code.google.com/p/b-tk/issues/detail?id=#74'>Issue #74</a>: "Matlab C3Dserver emulator SetParameterValue Problem".<br>
</li><li>FIX: Matlab/Octave <a href='https://code.google.com/p/b-tk/issues/detail?id=#66'>Issue #66</a>: “Fix the issue related to btkAppendMetaData and the possible missing field numdims”.<br>
</li><li>FIX: Matlab/Octave: Default groups/parameters are now generated within the emulation of the C3Dserver command <code>NewFile</code>.<br>
</li><li>FIX: Matlab/Octave: Wrong data type passed into <code>btkSet*</code> can corrupt acquisition data (using single type instead of double)<br>
</li><li>FIX: Matlab/Octave: Wrong checks in the data type / number of elements for the value to set in a metadata using <code>btkSetMetaDataValue</code>.<br>
</li><li>FIX: Matlab/Octave: Generation of the internal ID fixed when <code>btkEmulateC3Dserver</code> is called more than once in the same function.<br>
</li><li>FIX: Octave: Infinite loop with Octave 3.6.4 when a warning message was print from BTK (<code>std::cerr</code> redirection to <code>mexPrintf</code> or <code>mexWarnMsgIdAndTxt</code>).</li></ul></li></ul>

</td></tr><tr><td>

<h2>BTK 0.2.1</h2>
<hr />
Released on May 3, 2013. Revision <a href='https://code.google.com/p/b-tk/source/detail?r=1763'>r1763</a>

<ul><li><b>General</b>
<ul><li>UPD: The list of methods for each class in the Doxygen documentation for the Python API and the C++ API are now sorted alphabetically.<br>
</li><li>FIX: Missing some export DLL symbols.</li></ul></li></ul>

<ul><li><b>CMake</b>
<ul><li>UPD: FindMatlab.cmake: possibility to force the compilation of MEX functions in 32-bit mode under MacOS X to release the library for the Matlab Mac student version (32-bit mode only).<br>
</li><li>FIX: FindMatlab.cmake doesn't find Matlab 32-bit under Windows 64-bit.</li></ul></li></ul>

<ul><li><b>IO</b>
<ul><li>UPD: C3D: Improvement of the computation of the general scale in C3D files.<br>
</li><li>FIX: C3D: <a href='https://code.google.com/p/b-tk/issues/detail?id=#57'>Issue #57</a>: Negative analog scale factor triggers the computation of the analog general scale.<br>
</li><li>FIX: C3D: The scale factor computed for new added analog channels can sometimes create aliasing. The new proposed method cannot give exactly the same results than in the original file use for the tests. However, it should work for every configuration and give the possibility to modify slightly values' range (+25%).<br>
</li><li>FIX: ANB: <a href='https://code.google.com/p/b-tk/issues/detail?id=58'>Issue 58</a> fixed: Invalid ANB file written from Matlab</li></ul></li></ul>

<ul><li><b>BasicFilters</b>
<ul><li>FIX: Loading an acquisition with 3 force platforms in Mokka and loading another acquisition with only 2 force platforms still show the force vector of the third one.</li></ul></li></ul>

<ul><li><b>VTK</b>
<ul><li>FIX: VTK 5.10.1 doesn't export the symbol vtkContextMouseEvent::GetModifiers() when compiled as shared libraries.</li></ul></li></ul>

<ul><li><b>Bindings</b>
<ul><li>UPD: PYTHON: New tutorial for Python.<br>
</li><li>FIX: PYTHON: The typemap used by SWIG for the class btk::Analog::Values has nothing to do in the fragment used by SWIG to map Eigen classes.<br>
</li><li>FIX: PYTHON: Wrong documentation for the Python method btk.btkAcquisition.ResizeFrameNumber and btk.btkAcquisition.ResizeFrameNumberFromEnd.<br>
</li><li>FIX: PYTHON: The internal link btkAcquisition does not work with Doxygen for the Python documentation and was replaced by btk.btkAcquisition.<br>
</li><li>UPD: MATLAB: Matlab function btkAppendForcePlatformType2 adds more details for each added analog channel (offset, gain, scale).<br>
</li><li>FIX: MATLAB: Compiler errors between Matlab R2012b and MSVC 2010.<br>
</li><li>FIX: MATLAB: btkSetAnalogGain: The given index doesn't set correctly the analog gain.<br>
</li><li>FIX: MATLAB: The Matlab function btkFindMetaData throws a Matlab error when more than one label is given and the first one doesn't exist.</li></ul></li></ul>

<ul><li><b>Batch</b>
<ul><li>FIX: EasyInstall doesn't use the good development environment if Matlab 32-bit is used under Windows 64-bit.</li></ul></li></ul>

</td></tr><tr><td>

<h2>BTK 0.2</h2>
<hr />
Released on February 16, 2013. Revision <a href='https://code.google.com/p/b-tk/source/detail?r=1568'>r1568</a>
<ul><li><b>Core</b>
<ul><li>ENH: The camera mask used in a btk::Point object to know the "contribution" of each camera in its reconstruction is removed as this information is limited to the markers only. Moreover, due to the specifications of the C3D file format, the mask was limited to store the informations of only 7 cameras.<br>
</li><li>ENH: New classes to represent an inertial measurement unit (IMU).<br>
</li><li>ENH: New classes to create a triangle mesh from points.<br>
</li><li>UPD: Update mechanism updated to use only the inputs and not their source to test if the current block has to be update. Moreover, the outputs' timestamp is no more updated, as it is possible that some of them were not modified during the update process.<br>
</li><li>UPD: The methods <code>btk::Point::SetFrame</code> and <code>btk::Analog::SetFrame</code> were renamed <code>btk::Point::SetDataSlice</code> and <code>btk::Analog::SetDataSlice</code> to remove some potential conflict or miscomprehension with the method <code>btk::Acquisition::SetFirstFrame</code> (e.g. the use of a frame's index in one case and frame's value in the other case).<br>
</li><li>UPD: The method <code>btk::Acquisition::SetFirstFrame</code> has now an option to adapt also event's frame/time.<br>
</li><li>UPD: The method <code>btk::DataObject::Modified</code> is now a public method. It gives the possibility to force the update of a pipeline.<br>
</li><li>UPD: Functions <code>btk::MetaDataCreateChild</code> and <code>btk::MetaDataCreateChild2D</code> refactored and renamed into <code>btk::MetaDataCreateChild</code>.<br>
</li><li>UPD: New macro <code>btkNumberOfDigits</code> to extract the number of digits in an integer.<br>
</li><li>UPD: The private headers (<code>*_p.h</code>) are no more installed.<br>
</li><li>UPD: Doxygen documentation updated for Doxygen 1.8.2<br>
</li><li>FIX: The method <code>ProcessObject::Modified</code> sets now only the modification flag to true. The time stamp is now only updated when the filter is updated. This fix a problem when a new input is set (introduced in revision <a href='https://code.google.com/p/b-tk/source/detail?r=1309'>r1309</a>). The method <code>ProcessObject::Update</code> was also adapted in consequence.<br>
</li><li>FIX: The method <code>btk::Collection::Clear</code> doesn't modify the time stamp of the object.<br>
</li><li>FIX: Potential bug if an object's parent is deleted before these children.<br>
</li><li>FIX: Resizing an acquisition with the same number of points doesn't set the parent of the points.<br>
</li><li>FIX: Resizing an acquisition with the same number of analog channels doesn't set the parent of the analog channels.<br>
</li><li>FIX: Missing informations in BTKConfig.cmake (No Octave wrap option, No Python wrap option, BTK_LIBRARIES does not include BTKVTK).<br>
</li><li>FIX: Impossible to use the CMake variable BTK_LIBRARIES internally to link an executable<br>
</li><li>FIX: Conflict between the macro <code>static_pointer_cast</code> and the function <code>static_pointer_cast</code> defined in installed Boost library.<br>
</li><li>FIX: Clang 3.1 error (Unqualified lookup in templates).<br>
</li><li>FIX: GCC 3.3 compiler issues (ambiguous overload) fixed with the refactoring of the functions.<br>
</li><li>FIX: The compiler delivered with Ubuntu 12.10 send errors for some templates declared after their use.<br>
</li></ul></li><li><b>IO</b>
<ul><li>ENH: New API to add more easily file formats.<br>
</li><li>ENH: New file format: XMOVE (Thanks to the company Codamotion and the open-source library Open3DMotion).<br>
</li><li>ENH: New file format: MDF (Thanks to the company Codamotion and the open-source library Open3DMotion).<br>
</li><li>ENH: New file format: Delsys EMG (Thanks to the company Delsys for their original Matlab code).<br>
</li><li>ENH: New file format: CLB (Contec Inc.).<br>
</li><li>ENH: New filter <code>btk::ASCIIFileWriter</code> to export acquisition data to ASCII file.<br>
</li><li>ENH: New filter <code>btk::btkMultiSTLFileWriter</code> to write STL files from an acquisition and a triangle mesh.<br>
</li><li>UPD: Better support for C3D template file (acquisition is not configured when there is no data).<br>
</li><li>UPD: The C3D parser was adapted to be flexible when the size of a metadata is wrong compared to the offset to go to the next metadata.<br>
</li><li>UPD: The writer of C3D file automatically adapts the value of the general analog scale factor if any analog channel scale value is lower than 1.0e-5<br>
</li><li>FIX: Index error in the STL writer if the first frame doesn't start from 1.<br>
</li><li>FIX: The TDF reader doesn't support a number of force platforms different between the data block and the configuration block.<br>
</li><li>FIX: The implementation of the writer for the TRC file format exports every points and not only markers.<br>
</li><li>FIX: Analogs' unit is not saved in the C3D file format.<br>
</li><li>FIX: The type of some angles and forces extracted from XLS OrthoTrak files are not set correctly.<br>
</li><li>FIX: The extraction of the XLS angles are now set in the order FE/AA/RIE and not RIE/AA/FE.<br>
</li></ul></li><li><b>BasicFilters</b>
<ul><li>ENH: New filter <code>btk::SubAcquisitionFilter</code> to extract a part of an acquisition.<br>
</li><li>ENH: New filter <code>btk::AnalogOffsetRemover</code> to remove an offset for some analog channels using a reference acquisition.<br>
</li><li>ENH: New filter <code>btk::btkVerticalGroundReactionForceGaitEventDetector</code> to detect heel strike and foot off events during gait using the vertical ground reaction force!<br>
</li><li>ENH: New class <code>btk::CollectionAssembly</code> to group several collection of the same type (Point, Analog, etc.) together.<br>
</li><li>ENH: New filter to extract IMU informations from an acquisition (work in progress).<br>
</li><li>UPD: Methods and members in the class <code>btk::SeparateKnownVirtualMarkersFilters</code> were renamed to be simpler to use.<br>
</li><li>UPD: Filter <code>btk::ForcePlatformsExtractor</code> optimized. If the content of the data used (metadata and some analog channels) was not modified, then the output is not regenerated.<br>
</li><li>UPD: Code optimized for the filter <code>btk::DownsampleFilter</code> if the ratio is equal to one.<br>
</li><li>UPD: The filter <code>btk::SeparateKnownVirtualMarkersFilter</code> has now a fifth output containing all the markers (real and virtual) as stored in the input acquisition.<br>
</li><li>UPD: New enum values to use with the method <code>btk::SeparateKnownVirtualMarkersFilter::GetOutput</code> to extract the selected output.<br>
</li><li>FIX: From data stored in TDF file, it seems that force plate type I stores moments around the COP. The filter <code>btk::ForcePlatformWrenchFilter</code> is adapted in consequence.<br>
</li><li>FIX: Wrenches computed by the filter <code>btk::GroundReactionWrenchFilter</code> has the same name than for the filter <code>btk::ForcePlatformWrenchFilter</code>.<br>
</li><li>FIX: Wrenches extracted by the filter <code>btk::DownsampleDataFilter</code> has no name.<br>
</li></ul></li><li><b>VTK</b>
<ul><li>ENH: New engine for the charts based on VTK 5.8/5.10.<br>
</li><li>UPD: New method <code>btk::VTKSegmentsFramesSource::GetNumberOfDefinitions()</code>.<br>
</li><li>UPD: The number of inputs for the class <code>btk::VTKMarkersFramesSource</code> is reset to 1. To display several collections together use a <code>btk::CollectionAssembly</code> object.<br>
</li><li>UPD: New method <code>btk::VTKMarkersFramesSource::GetTrajectoryVisibility</code>.<br>
</li><li>UPD: Small modification in the mechanism used by the BTK -> VTK adapter, but the behavior remains the same.<br>
</li><li>FIX: Missing vtkCharts library for the module BTKVTK when compiled as a shared library.<br>
</li><li>FIX: Possible crash if only one input is given to the class <code>btk::VTKMarkersFramesSource</code>.<br>
</li><li>FIX: Memory leaks fixed<br>
</li></ul></li><li><b>Bindings</b>
<ul><li>ENH: PYTHON: New Python binding!<br>
</li><li>ENH: MATLAB: All the informations related to cameras' mask were removed. You only need to set the residual to a negative value to indicate if a marker is occluded or not.<br>
</li><li>ENH: MATLAB: New M function <code>btkAppendForcePlatformType2</code> to easily integrate a force platform into an acquisition.<br>
</li><li>ENH: MATLAB: New M function <code>btkTransformTDFToViconC3DFile</code> to easily transform a TDF file (BTS Bioengineering) to a C3D file compatible the Vicon software products.<br>
</li><li>ENH: MATLAB: New M function <code>btkCropAcquisition</code>.<br>
</li><li>ENH: MATLAB: New MEX functions <code>btkGetPointsValues</code> and btkSetPointsValues.<br>
</li><li>ENH: MATLAB: New MEX functions <code>btkGetPointsResiduals</code> and <code>btkSetPointsResiduals</code>.<br>
</li><li>ENH: MATLAB: New MEX functions <code>btkGetMarkersResiduals</code> and btkSetMarkersResiduals.<br>
</li><li>ENH: MATLAB: New MEX function <code>btkSetAnalogUnit</code>.<br>
</li><li>ENH: MATLAB: New MEX function <code>btkGetPointsUnits</code>.<br>
</li><li>UPD: MATLAB: Function btkSetPointUnits renamed <code>btkSetPointsUnits</code> for a better consistency into functions' name.<br>
</li><li>UPD: MATLAB: New option for the Matlab function <code>btkSetFirstFrame</code> to adapt also events' time/frame.<br>
</li><li>UPD: MATLAB: Functions <code>btkAppendMetaData</code> and <code>btkMetaDataInfo</code> updated to be able to set the number of dimensions. This new parameters seems only necessary for a 2D array of strings with only one item.<br>
</li><li>UPD: MATLAB: Function <code>btkSetAnalogResolution</code> supports now the 10-bit ADC value.<br>
</li><li>FIX: MATLAB: Adding new data into an acquisition can crash Matlab under Un*x when MEX functions are unloaded.<br>
</li><li>FIX: MATLAB: Missing <code>std::cerr</code> redirection into the function btkGetForcePlatformWrenches.<br>
</li><li>FIX: MATLAB: From the feedback of a user, Matlab under Vista needs to use the same MEX functions than under Windows 7 (and not Windows XP).<br>
</li><li>FIX: OCTAVE: The warning messages sent to the standard error (<code>std::cerr</code>) are not displayed.<br>
</li></ul></li><li><b>Batch</b>
<ul><li>UPD: The EasyInstall batch file for Windows checks now first the Windows SDK before MSVC.<br>
</li><li>UPD: EasyInstall manages correctly the use of Matlab 32-bit under Windows 64-bit.<br>
</li><li>FIX: The detection of Matlab in <code>EasyInstall_MSVC.bat</code> doesn't work if the current path contains space.</li></ul></li></ul>

</td></tr><tr><td>

<h2>BTK 0.1.10</h2>
<hr />
Released on April 11, 2012. Revision <a href='https://code.google.com/p/b-tk/source/detail?r=1047'>r1047</a>
<ul><li><b>General</b>
<ul><li>UPD: New doxygen documentation for building BTK with the support of Octave.<br>
</li><li>UPD: Doxygen documentation updated to be used with Doxygen 1.8.0<br>
</li><li>FIX: Uninitialised values detected by Valgrind.<br>
</li></ul></li><li><b>CMake</b>
<ul><li>ENH: FindQtMobility: New CMake script to find Qt Mobility.<br>
</li><li>UPD: FindOctave: Try to find Octave in a third subfolder from <code>C:\Octave*</code>.<br>
</li><li>UPD: FindOctave: Fatal error triggered when finding Octave under Windows if the compiler used is not the same than the one used to compile Octave.<br>
</li><li>UPD: FindOctave: Rewriting manually <code>OCTAVE_ROOT</code> updates the others variables related to Octave.<br>
</li><li>UPD: FindOctave: FindOctave.cmake adapted for Octave 3.6.<br>
</li><li>FIX: Extra debug flags for the compiler are concatenated again and again each time the CMake project is configured.<br>
</li></ul></li><li><b>Common</b>
<ul><li>UPD: New methods <code>btk::Analog::SetFrame</code> and <code>btk::Point::SetFrame</code> to easily set values for a given frame.<br>
</li><li>UPD: New method <code>btk::MetaDataInfo::HasValues</code>.<br>
</li><li>UPD: Setting the analog resolution to 10-bit is now possible.<br>
</li></ul></li><li><b>Basic Filters</b>
<ul><li>ENH: Class <code>btk::WrenchDirectionAngleFilter</code>: New filter to compute the direction angle of wrenches' force.<br>
</li><li>FIX: Mokka 0.4 crashes when opening c3d file created by Qualysis (<a href='https://code.google.com/p/b-tk/issues/detail?id=20'>issue 20</a>).<br>
</li><li>FIX: Computation of the ground reaction forces crashes when the channel indices are lower than 0.<br>
</li></ul></li><li><b>IO</b>
<ul><li>ENH: New file format: TDF (BTS Bioengineering) - Supported only by the reader.<br>
</li><li>ENH: New acquisition file IO (reader only): AMTI force and moment file (.ASC)<br>
</li><li>UPD: New methods <code>btk::BinaryFileStream::ReadI32</code> and <code>btk::BinaryFileStream::ReadU32</code> to extract signed and unsigned 32-bit integer(s) from binary file stream.<br>
</li><li>FIX: Camera mask used in the TRB file format is not compatible with the C3D file format.<br>
</li><li>FIX: Some arrays were not initialized.<br>
</li><li>FIX: XLS Orthotrak seems to use zero based indexing (first frame starts from 0) instead of one based indexing.<br>
</li></ul></li><li><b>VTK</b>
<ul><li>UPD: Class <code>btk::VTKGRFsFramesSource</code> is able to display butterfly diagram (<a href='https://code.google.com/p/b-tk/issues/detail?id=26'>issue 26</a>).<br>
</li><li>UPD: The path of the GRFs can be shown in 3D (<a href='https://code.google.com/p/b-tk/issues/detail?id=27'>issue 27</a>).<br>
</li><li>UPD: The ticks used on the axis in a VTK chart can now be shifted and scaled.<br>
</li><li>FIX: Force platform index not shown depending of the scaling unit value.<br>
</li><li>FIX: Data containing value +/-Inf are not plotted in a chart (<a href='https://code.google.com/p/b-tk/issues/detail?id=23'>issue 23</a>).<br>
</li></ul></li><li><b>Matlab wrapping</b>
<ul><li>FIX: Implementation errors in the function SaveFile for the C3Dserver emulation.</li></ul></li></ul>

</td></tr><tr><td>

<h2>BTK 0.1.9</h2>
<hr />
Released on December 9, 2011. Revision <a href='https://code.google.com/p/b-tk/source/detail?r=903'>r903</a>
<ul><li><b>General</b>
<ul><li>ENH: New wrapper for Octave: Use exactly the same syntax than the wrapper for Matlab (<a href='https://code.google.com/p/b-tk/issues/detail?id=17'>issue 17</a>, <a href='https://code.google.com/p/b-tk/issues/detail?id=18'>issue  18</a>).<br>
</li><li>FIX: Unit tests crashed on Unix 32 bits (<a href='https://code.google.com/p/b-tk/issues/detail?id=11'>issue 11</a>).<br>
</li><li>FIX: Build fails under linux when compiling <code>Code/VisSupport/VTK/btkVTKSegmentsFramesSource.cpp</code> (<a href='https://code.google.com/p/b-tk/issues/detail?id=15'>issue 15</a>)<br>
</li><li>FIX: Mokka does not run after 'make install' under linux (<a href='https://code.google.com/p/b-tk/issues/detail?id=16'>issue 16</a>)<br>
</li><li>FIX: Mokka: File <code>Tools/Mokka/moc_LoggerWidget.cxx</code> fails to compile in linux (<a href='https://code.google.com/p/b-tk/issues/detail?id=19'>issue 19</a>)<br>
</li></ul></li><li><b>CMake</b>
<ul><li>ENH: New script to detect Octave<br>
</li><li>FIX: Script to detect the version of VTK doesn't work.<br>
</li></ul></li><li><b>Common</b>
<ul><li>UPD: Analog class supports more gains.<br>
</li><li>UPD: New method <code>btk::Wrench::GetComponent</code>.<br>
</li><li>FIX: The methods <code>btk:Wrench::SetForce</code> and <code>btk::Wrench::SetMoment</code> wrongly force the type of the wrench's position instead of the new force or moment.<br>
</li><li>FIX: The default unit for the Scalar point is empty while it is set to "mm" when reseting the acquisition.<br>
</li></ul></li><li><b>IO</b>
<ul><li>ENH: New acquisition file writer to export Motion Analysis force plateform calibration (CAL).<br>
</li><li>UPD: ANC file writer improved to better export analog data.<br>
</li><li>UPD: The TRB reader doesn't set correctly the residual/mask for invalid coordinates.<br>
</li><li>UPD: Detection of the size of the calibration matrix in the CAF file updated<br>
</li><li>UPD: The RIC file reader can now read RIF file as BTS Bioengineering provide both.<br>
</li><li>UPD: The RIC/RIF reader creates the metadata POINT:MARKERS_FILTERED to know if the data were filtered or not.<br>
</li><li>FIX: The data from the OrthoTrack XLS files are wrongly extracted<br>
</li><li>FIX: Empty (NULL) C3D file crashed the C3D parser.<br>
</li><li>FIX: In some case, the RIC/RIF file has no markers' label section and BTK throws an "end of file" exception.<br>
</li><li>FIX: The units written in a C3D file correspond only to the default units (mm, N, Nmm, etc.).<br>
</li><li>FIX: The revision <a href='https://code.google.com/p/b-tk/source/detail?r=618'>r618</a> introduces a bug in the reading of C3D files containing analog channels which are not correctly tagged as unsigned 16 bits.<br>
</li></ul></li><li><b>BasicFilters</b>
<ul><li>UPD: New rule to merge acquisitions: You can select if you want to keep all the frames or only from the highest first frame.<br>
</li><li>UPD: Filter to merge acquisitions improved when merging Motion Analysis files with the first frame not set to 1. New metadata to check this: BTK_POINT_CONFIG:NO_FIRST_FRAME created for acquisitions imported from ANC and CAL files.<br>
</li><li>FIX: An acquisition with wrong analog channel index for calibrated force plate throws an exception.<br>
</li></ul></li><li><b>VTK</b>
<ul><li>ENH: New class <code>btk::VTKChartTimeSeries</code> to expand methods of the class vtkChartXY under VTK 5.6<br>
</li><li>ENH: New class <code>btk::VTKAxis</code> to expand methods of the class vtkAxis under VTK 5.6<br>
</li><li>ENH: New class <code>btk::VTKChartLegend</code>  to expand methods of the class vtkChartLegend under VTK 5.6<br>
</li><li>ENH: New class <code>btk::VTKContextScene</code> to be able to remove context items from a scene with VTK 5.6.<br>
</li><li>UPD: The rotation range around the global vertical axis is now set to 360 degrees instead of 180.<br>
</li><li>FIX: The location of the axes frame associated with a force platform is not correctly calculated when the scale is not set to 1.<br>
</li></ul></li><li><b>Matlab Wrapping</b>
<ul><li>ENH: New Matlab function to emulate C3Dserver: <code>btkEmulateC3Dserver</code> 1.0b1. More informations here: <a href='http://code.google.com/p/b-tk/wiki/C3DServerEmulationForMatlab'>http://code.google.com/p/b-tk/wiki/C3DServerEmulationForMatlab</a>
</li><li>ENH: New MEX function: <code>btkSetAnalogNumber</code>.<br>
</li><li>UPD Should fix some Matlab crashes due to the display of some C++ error messages.</li></ul></li></ul>

</td></tr><tr><td>

<h2>BTK 0.1.8</h2>
<hr />
Released on June 16, 2011. Revision <a href='https://code.google.com/p/b-tk/source/detail?r=652'>r652</a>
<ul><li><b>BTK Basic Filters</b>
<ul><li>FIX: btk::ForcePlatformsExtractor: Acquisition with force plaform type 4 configuration with not enough number of analog channels crashed the filter.<br>
</li></ul></li><li><b>BTK IO</b>
<ul><li>UPD: C3D: Files generated by Motion Analysis uses the value 9999999 in coordinates X/Y/Z to represent occluded markers. When found, they are replaced by 0 and the associated mask and residual are set to -1.<br>
</li><li>UPD: C3D: Give the possibility to the parser to continue the extraction of the acquisition even if some data in the Data section (points and analogs data) are missing.<br>
</li><li>FIX: C3D: Writing analog data sampled on 16 bits is no more forced to be set as UNSIGNED data. (Motion Analysis generate C3D file with SIGNED 16 bits data. Rewriting the C3D file as UNSIGNED 16 bits and reading it again corrupt the extracted data.)<br>
</li><li>FIX: C3D: Final parameter/group pointing into the data section can trigger the "Bad data first block" exception.<br>
</li><li>FIX: C3D: Header data are trusted instead of these of the Parameter section (was the reverse before) to be able to open correctly corrupted C3D files generated by Cortex (Motion Analysis Corp.).<br>
</li><li>FIX: C3D: file generated by the system OptiTrack throws an error (byte for description's length of the parameter is missing).<br>
</li><li>FIX: ANC: Wrong number of extracted channels when some labels are empty.<br>
</li><li>FIX: ANC: Force platforms detection limited to check for index between 0 and 5 (update to check between 0 and 10).<br>
</li><li>FIX: ANC: Wrong scale for file with resolution on 16 bits.<br>
</li><li>FIX: ANB: Resolution for the analog to digital converter (ADC) is set to 65552 but waiting for the value 16... Resolution is forced to 16 bit when the value is greater or equal than 65535. Need more files from system using 16 bit ADC.<br>
</li></ul></li><li><b>BTK VTK</b>
<ul><li>ENH: btk::VTKSegmentsFramesSource: New VTK source to visualize segments as sets of links between markers.<br>
</li><li>UPD: btk::VTKMarkersFramesSource: Options for the default radius and the default color.<br>
</li><li>UPD: btk::VTKGRFsFramesSource: Huge time speed up to create ground reactions forces.<br>
</li><li>UPD: btk::VTKForcePlatformsSource: Options to show axes and indices.<br>
</li><li>UPD: btk::VTKGroundSource: Option to select the default orientation associated with the automatic detection.<br>
</li><li>FIX: btk::VTKForcePlatformsSource: Should adapt correctly the size of the force platform index.<br>
</li></ul></li><li><b>BTK Matlab</b>
<ul><li>UPD: Matlab R2011a included into FindMatlab.cmake.<br>
</li><li>FIX: The revision <a href='https://code.google.com/p/b-tk/source/detail?r=369'>r369</a> creates compiler errors with Matlab r2010b and MSVC 2010. The workaround was updated to stay compatible with Matlab r2010b or greater.</li></ul></li></ul>

</td></tr><tr><td>

<h2>BTK 0.1.7</h2>
<hr />
Released on February 12, 2011. Revision <a href='https://code.google.com/p/b-tk/source/detail?r=592'>r592</a>
<ul><li><b>General</b>
<ul><li>ENH: Web documentation for Matlab, including tutorials<br>
</li><li>ENH: Tutorials for the C++ API<br>
</li><li>UPD: <code>Utility/EasyInstall</code>: New subproject to build <code>EasyInstallWithRedistribuableMatlabToolbox.jar</code>, a java tool to easily compile and install BTK for Windows/Mac/Linux. The previous batch files for Matlab and Scilab are redirected into the subfolder Batch.<br>
</li><li>UPD: Update Eigen to the release 2.0.15.<br>
</li><li>FIX: The TDD executable cannot be linked using CL64.<br>
</li><li>FIX: Impossible to include "../../Utilities/stdint.h" when you use the installed headers.<br>
</li><li>FIX: CMake installation script for PCL.<br>
</li><li>FIX: Several minor fixes not listed below.<br>
</li></ul></li><li><b>CMake</b>
<ul><li>ENH: New CMake option to force the generation of the whole API documentation.<br>
</li><li>UPD: Adding a CMake option to add extra compiler flags for GCC (warning options) when compiling in Debug mode.<br>
</li><li>UPD: <code>FindMatlab.cmake</code>: Default paths for linux has been added.<br>
</li><li>UPD: <code>FindBTK.cmake</code> ready to be used for external project.<br>
</li></ul></li><li><b>BTK Core</b> (Common)<br>
<ul><li>ENH: Setting values in a <code>MetadataInfo</code> object is now more flexible.<br>
</li><li>UPD: Method <code>btk::Collection::GetIndexOf</code> added.<br>
</li><li>FIX: Method <code>btk::Analog::SetGain</code>, the test between the new gain and the current one is wrong.<br>
</li><li>FIX: Method <code>btk::Acquisition::ResizePointNumber</code> doesn't check if the new number of points is equal to the old one.<br>
</li><li>FIX: Method <code>btk::Acquisition::ResizeAnalogNumber</code> doesn't check if the new number of analog channels is equal to the old one.<br>
</li></ul></li><li><b>BTK Basic Filters</b>
<ul><li>ENH: <code>btkSeparateKnownVirtualMarkersFilter</code>: Possibility to add a prefix during the separation.<br>
</li><li>UPD: Add an option to express force platform wrench in global/local frame.<br>
</li><li>UPD: Code refactoring between the classes <code>btk::ForcePlatformWrenchFilter</code> and <code>btk::GroundReactionWrenchFilter</code> to remove the code redundancy.<br>
</li><li>FIX: <code>btkSeparateKnownVirtualMarkersFilter</code>: Using marker with the same name than one possible axis put it in the wrong category.<br>
</li></ul></li><li><b>BTK IO</b>
<ul><li>ENH: EXPERIMENTAL: Acquisition file format TRB (Motion Analysis Corporation) added. Need more tests and files.<br>
</li><li>ENH: New file format EMF form the company Ascension Technology Inc.<br>
</li><li>ENH: New file stream using the memory file mapping mechanism (method faster than using the I/O methods).<br>
</li><li>ENH: New class <code>btk::NativeBinaryFileStream</code> known as the native binary filestream choosen by the compiler.<br>
</li><li>UPD: Class <code>btk::BinaryFileStream</code> and inherited classes has now constructors which are independent of a <code>std::fstream</code>. Can now be used as independent filestream.<br>
</li><li>UPD: Byte order and storage format of an acquisition file can now be returned as a string.<br>
</li><li>UPD: Events in the Elite files (RIC, RAH, RAW) use now the same ID than Vicon (Foot Strike: 1, Foot Off: 2).<br>
</li><li>UPD: C3D: The reader is now more flexible to detect the processor type and try to continue is the value is set as 1,2,3 instead of 84,85,86.<br>
</li><li>UPD: C3D: Instead of triggering an exception when the offset between group/parameter is negative, the reader attempt to continue.<br>
</li><li>UPD: C3D: The first word in the parameter section is not checked to prevent possible errors (as now proposed by the C3D documentation).<br>
</li><li>UPD: C3D: Faster way to determine the greatest absolute value in the point's coordinates.<br>
</li><li>UPD: C3D: Read the <code>MaxInterpolationGap</code> data from a C3D file instead of flushing it.<br>
</li><li>UPD: C3D: Write the <code>MaxInterpolationGap</code> data from an acquisition object instead of writing the default value 10.<br>
</li><li>FIX: C3D: Format for the values of the parameter EVENT:TIMES is set to represent a column vector instead of a table with two columns.<br>
</li><li>FIX: C3D: Float round-off error when computing the frame number in a C3D file.<br>
</li><li>FIX: TRC: File without final carriage return (CR) throws the exception "Unexpected end of file".<br>
</li><li>FIX: XLS: Reader doesn't shift the event's frame by the initial first frame value.<br>
</li><li>FIX: The headers for the kit BTKIO are installed in the folder BTKIO instead of IO.<br>
</li></ul></li><li><b>BTK VTK</b>
<ul><li>ENH: <code>btk::VTKMarkersFramesSource</code>: New methods to show/hide all trajectories.<br>
</li><li>ENH: New VTK process to display the ground (with the possibility to automatically determinate the orientation of the ground, based on the metadata POINT:Y_SCREEN).<br>
</li><li>ENH: Addition of a rubber band in the interactor style to select cells from polydata and then marker ID.<br>
</li><li>ENH: <code>btk::VTKInteractorStyleTrackballFixedUpCamera</code> uses now the global up vector to rotate around the vertical axis and limits the rotations to 180 and 90 degrees for the vertical and horizontal axis, respectively.<br>
</li><li>UPD: VTK style interactor <code>btk::VTKInteractorStyleTrackballFixedUpCamera</code> uses the member <code>RotationEnabled</code> to enable/disable every rotation functions (Rotate, Spin, Pan, Dolly).<br>
</li><li>UPD: VTK style interactor <code>btk::VTKInteractorStyleTrackballFixedUpCamera</code> uses the member   <code>CharEventEnabled</code> to enable/disable default VTK key events.<br>
</li><li>UPD: Picker can now invoke the event <code>VTKMarkersToggleTrajectoryEvent</code> when clicking on a cell using the sequence Alt button + Left mouse button.<br>
</li><li>UPD: The class <code>VTKInteractorStyleTrackballFixedUpCamera</code> has an option to enable/disable the camera's rotation.<br>
</li><li>UPD: <code>VTKForcePlatformsSource</code>: Display the axis frame of each force platform.<br>
</li><li>UPD: <code>VTKForcePlatformsSource</code>: Display the index of each force platform if the number of force plateform is greater than 1.<br>
</li><li>FIX: <code>VTKForcePlatformsSource</code>: In some case, VTK send and error about a wrong coordinate system.<br>
</li></ul></li><li><b>BTK MATLAB WRAPPING</b>
<ul><li>ENH: New MEX function: <code>btkSetEventSubject</code>
</li><li>ENH: New MEX function: <code> btkGetPoint</code>
</li><li>ENH: New MEX function: <code>btkGetAnalog</code>
</li><li>ENH: New MEX function: <code>btkGetForcePlatformWrenches</code>
</li><li>ENH: New MEX function: <code>btkGetMaxInterpolationGap</code>
</li><li>ENH: New NEX function: <code>btkSetAnalogSampleNumberPerFrame</code>
</li><li>ENH: New NEX function: <code>btkSetAnalogValues</code>
</li><li>ENH: New NEX function: <code>btkSetEventLabel</code>
</li><li>ENH: New MEX function: <code>btkSetMaxInterpolationGap</code>
</li><li>ENH: New MEX function: <code>btkSetMetaDataDescritpion</code>
</li><li>ENH: New MEX function: <code>btkSetMetaDataDimensions</code>
</li><li>ENH: New MEX function: <code>btkSetMetaDataFormat</code>
</li><li>ENH: New MEX function: <code>btkSetMetaDataLabel</code>
</li><li>ENH: New MEX function: <code>btkSetMetaDataUnlock</code>
</li><li>ENH: New MEX function: <code>btkSetMetaDataValue</code>
</li><li>ENH: New MEX function: <code>btkSetPointMasks</code>
</li><li>ENH: New MEX function: <code>btkSetPointResiduals</code>
</li><li>ENH: New MEX function: <code>btkSetPointValues</code>
</li><li>ENH: New M function: <code>btkConvertBinaryMasks2Decimals</code>
</li><li>ENH: New M function: <code>btkFindMetaData</code>
</li><li>ENH: New M function: <code>btkGetAnalogSampleNumberPerFrame</code>
</li><li>ENH: New M function: <code>btkGetEventNumber</code>
</li><li>ENH: New M function: <code>btkGetVersion</code>
</li><li>UPD: Warnings generated by BTK and transfered to Matlab have now an identifier to be enabled/disabled.<br>
</li><li>UPD: MEX function <code>btkGetMetadata</code> has more fields (unlocked and info.dims).<br>
</li><li>UPD: MEX function <code>btkGetPoint</code> has more fields (pointsInfo.residuals and pointsInfo.masks).<br>
</li><li>UPD: MEX function <code>btkReadAcquisition</code> has more outputs (byte order and storage format).<br>
</li><li>UPD: MEX function <code>btkRemoveEvent</code> can now remove event based on an index.<br>
</li><li>FIX: <a href='https://code.google.com/p/b-tk/issues/detail?id=7'>Issue 7</a> (related to the use of BTK into Matlab 64-bit under linux 64-bit).<br>
</li><li>FIX: <a href='https://code.google.com/p/b-tk/issues/detail?id=8'>Issue 8</a> (related to the use of BTK into Matlab 64-bit under linux 64-bit).<br>
</li><li>FIX: <a href='https://code.google.com/p/b-tk/issues/detail?id=9'>Issue 9</a> (related to the use of BTK into Matlab 64-bit under linux 64-bit).<br>
</li><li>FIX: <a href='https://code.google.com/p/b-tk/issues/detail?id=10'>Issue 10</a> (related to the use of BTK into Matlab 64-bit under linux 64-bit).</li></ul></li></ul>

</td></tr><tr><td>

<h2>BTK 0.1.6</h2>
<hr />
Released on June 16, 2010. Revision <a href='https://code.google.com/p/b-tk/source/detail?r=380'>r380</a>
<ul><li>ENH: New filter to separate marker and virtual markers based on their label: <code>SeparateKnownVirtualMarkersFilter</code>;<br>
</li><li>ENH: New Matlab script function: <code>btkGetLastFrame</code>;<br>
</li><li>ENH: Addition of an utility to create easily command line options, PCL: Parser for the Command Line;<br>
</li><li>UPD: The BTK-VTK filter <code>VTKMarkersFramesSource</code> accepts a second optional input;<br>
</li><li>UPD: Updating Eigen to the release 2.0.13;<br>
</li><li>UPD: Add new macros for the BTK release number (<code>BTK_VERSION_MAJOR</code>, <code>BTK_VERSION_MINOR</code>, <code>BTK_VERSION_PATCH</code>);<br>
</li><li>UPD: Documentation added for the input TYPE in the function <code>btkAppendPoint</code>.<br>
</li><li>FIX: Impossible to compile the Matlab Wrapper with MSVC 2010.<br>
<table></table>
<h2>BTK 0.1.5</h2>
<hr />
Released on May 21, 2010. Revision <a href='https://code.google.com/p/b-tk/source/detail?r=349'>r349</a>
</li><li>ENH: <b>EXPERIMENTAL</b>: New readers for the Elite acquisition files (BTS Bioengineering): RAH, RAW, RIC, ANG, MOM, PWR, GR<code>*</code>, EMG. More tests are required and especially on the EMG file. Files EMF & EMR have to be added but require more informations about the configuration of the EMG channels.<br>
</li><li>ENH: New MEX function to append an analog channel: <code>btkAppendAnalog</code>.<br>
</li><li>ENH: New MEX function to clear analog channels: <code>btkClearAnalogs</code>.<br>
</li><li>ENH: New MEX function to clear metadata: <code>btkClearMetadata</code>.<br>
</li><li>ENH: New MEX function to clear points: <code>btkClearPoints</code>.<br>
</li><li>ENH: New MEX function to clone an acquisition: <code>btkCloneAcquisition</code>.<br>
</li><li>ENH: New MEX function to remove an analog channel: <code>btkRemoveAnalog</code>.<br>
</li><li>ENH: New MEX function to remove a metadata entry: <code>btkRemoveMetadata</code>.<br>
</li><li>UPD: <code>FindMatlab.cmake</code> updated to include Matlab 2010a.<br>
</li><li>UPD: Should be able to compile BTK with Matlab 6.5.<br>
</li><li>UPD: The reader for the C3D files try now to continue to extract the parameters when it discovers an overflow between the number of blocks to read and the number of blocks wrote in the file.<br>
</li><li>UPD: Minor API updates/changes.<br>
</li><li>FIX: Pre-processor error when compiling BTK under Windows 7 x64.<br>
</li><li>FIX: Impossible to compile BTK in 64 bits mode when using the batch files <code>EasyInstallWith...</code> (Requires Windows SDK 7 when using MSVC EE).<br>
</li><li>FIX: Impossible to install BTK on Windows 7 by using the batch files <code>EasyInstallWith...</code> (UAC privileges).<br>
</li><li>FIX: Removing the last point using its label crashes BTK.<br>
</li><li>FIX: Analog values not initialized when resized from the end.<br>
</li><li>FIX: Fixes <a href='https://code.google.com/p/b-tk/issues/detail?id=3'>issue 3</a>: "<code>btk::AcquisitionFileWriter</code> modifies the input when you write it in a C3D File".<br>
</li><li>FIX: Fixes <a href='https://code.google.com/p/b-tk/issues/detail?id=2'>issue 2</a>: "Handle large C3D file (65536+ frames) ".<br>
</li><li>FIX: Warning message (Analog channel gain's value) when reading a C3D file exported in C3D and coming from an acquisition stored in a ANC file.<br>
</li><li>FIX: Rounding error for the number of frames in ANC file under MS Windows (error since the previous patch to fix the same problem under Linux).<br>
</li><li>FIX: Wrong exception message when an ANB file is truncated (i.e. corrupted).<br>
</li><li>FIX: Wrong byte order when writing float values into an ANB file from a computer using a processor with the big-endian format.<br>
</li><li>FIX: <code>btk::MergeAcquisitionFilter</code>: Wrong number of frames when merging acquisitions with the first frame not equals to 1.<br>
</li><li>FIX: <code>btk::MergeAcquisitionsFilter</code>: Code enhanced to priorize the point data.<br>
</li><li>FIX: <code>btk::MergeAcquisitionsFilter</code>: Analog acquisitions with different frame rates can be merged and inconsistent measures.<br>
</li><li>FIX: Matlab crashes randomly under Windows 7 when BTK is compiled with the option <code>BTK_WRAP_MATLAB_REDISTRIBUABLE_FILES</code> => Remove the static linking under Windows 7.<br>
</li><li>FIX: Matlab not found when Mendeley is installed.<br>
</li><li>FIX: Wrong BTK toolbox release number in Matlab. Now generated automatically with CMake.<br>
</li><li>FIX: Matlab libraries (libmex, libmx, libmat) not detected for Matlab x64.<br>
</li><li>FIX: Using <code>btkSetFrameNumber</code> with only 2 arguments crashed Matlab.<br>
<ul><li>FIX: <code>FindScilab.cmake</code> doesn't detect Scilab under Mac OS X. Missing the library libscicore to link the toolbox under Mac OS X (symbol <i>com</i> missing).</li></ul></li></ul>

</td></tr><tr><td>

<h2>BTK 0.1.4a</h2>
<hr />
Released on February 3, 2011. Revision <a href='https://code.google.com/p/b-tk/source/detail?r=285'>r285</a>
<ul><li>FIX: Variables not initialized in the Matlab/Scilab function <code>btkGetEvents</code> when there is no event.<br>
</li><li>FIX: Matlab/Scilab wrapping functions are build in Debug mode (and are not redistribuable) when using the <code>EasyInstallWithRedistribuable*Toolbox_MSVC</code> batch scripts.<br>
<table></table>
<h2>BTK 0.1.4</h2>
<hr />
Released on February 2, 2011. Revision <a href='https://code.google.com/p/b-tk/source/detail?r=283'>r283</a>
</li><li>ENH: ANB acquisition file format reading/writing support<br>
</li><li>ENH: Orthotrack XLS acquisition file format reading support<br>
</li><li>ENH: Motion Analysis Corp. force platform calibration (CAL) file format reading support<br>
</li><li>ENH: Filter to merge acquisitions<br>
</li><li>ENH: New wrapper for Scilab, 100% compatible with the Matlab wrapping functions and vice-versa;<br>
</li><li>ENH: Filter to convert acquisition's units<br>
</li><li>ENH: New Matlab functions<br>
</li><li>UPD: ANC file writer uses by default the generation #2;<br>
</li><li>UPD: Compatible with 64 bits OS;<br>
</li><li>UPD: CMake script FindMatlab detects now all Matlab release under Windows / Mac OS X / Linux;<br>
</li><li>UPD: BTK can now be compiled with GCC 3.3 or above;<br>
</li><li>UPD: BTK can now be compiled with MSVC 2003 or above;<br>
</li><li>UPD: Update Eigen to the release 2.0.11.<br>
</li><li>FIX: Wrong number of frames when reading and writing ANC files.</li></ul>

</td></tr><tr><td>

<h2>BTK 0.1.3</h2>
<hr />
Released on October 16, 2009. <a href='https://code.google.com/p/b-tk/source/detail?r=233'>Revision 233</a>
<ul><li>ENH: VTK: Add option to display markers' trajectory in the output port 1.<br>
</li><li>ENH: New Matlab wrapping functions.<br>
</li><li>FIX: CMake script FindMatlab is not compatible with CMake 2.6.2 (parenthesis error).<br>
</li><li>FIX: CMake script FindMatlab doesn't find Matlab 7.0.4.<br>
</li><li>FIX: Ground reaction wrench calculation error for force platform type I.<br>
</li><li>FIX: BTK crashes when groups have no parameters during reading C3D files.<br>
</li><li>FIX: Events' ID are lost after saving a C3D file.<br>
</li><li>FIX: EVENT_CONTEXT group contains duplicated labels in generated C3D files.<br>
</li><li>FIX: C3D File generated from BTK crashed Polygon.<br>
</li><li>FIX: Memory leaks during the generation of markers' positions.<br>
</li><li>FIX: Memory leak in VTKMarkersFramesSource.</li></ul>

</td></tr><tr><td>

<h2>BTK 0.1.2</h2>
<hr />
Released on September 10, 2009. Revision <a href='https://code.google.com/p/b-tk/source/detail?r=212'>r212</a>
<ul><li>ENH: New filter to downsample data.<br>
</li><li>ENH: New classes to wrap BTK data into VTK library.<br>
</li><li>ENH: Lots of new Matlab wrapping functions.<br>
</li><li>UPD: Readme.html updated.<br>
</li><li>UPD: Eigen library updated from 2.0.3 to 2.0.5.<br>
</li><li>FIX: btkVTKForcePlatformsSource sends errors when the origin is set to (0,0,0).<br>
</li><li>FIX: Some analog values corrupted for unsigned analog data in C3D files.<br>
</li><li>FIX: Analog resolution was not saved during the reading of C3D files.<br>
</li><li>FIX: Wrong extraction of arrays of characters with number of dimensions greater than 3 in C3D files.<br>
</li><li>FIX: Parameter POINT:TYPE_GROUPS is a 3D array not 2D when exporting to C3D file.</li></ul>

</td></tr><tr><td>

<h2>BTK 0.1.1</h2>
<hr />
Released on July 28, 2009. Revision <a href='https://code.google.com/p/b-tk/source/detail?r=166'>r166</a>
<ul><li>ENH: ANC acquisition file format reading/writing support<br>
</li><li>ENH: New filter to compute ground reaction wrench from force platform data.<br>
</li><li>UPD: New Matlab functions.<br>
</li><li>FIX: C3D file from EvaRT/Cortex imports correctly point's label.</li></ul>

</td></tr><tr><td>

<h2>BTK 0.1.0</h2>
<hr />
Released on July 13, 2009. Initial release<br>
<ul><li>ENH: C3D acquisition file format reading/writing support<br>
</li><li>ENH: TRC acquisition file format reading/writing support<br>
</li><li>ENH: Matlab wrapping functions.</li></ul>

</td></tr></table>