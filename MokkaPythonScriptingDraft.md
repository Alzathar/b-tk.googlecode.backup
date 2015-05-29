# Introduction #

Because it was requested on [UserVoice](http://mokka.uservoice.com/forums/158152-mokka/suggestions/2774903-to-have-a-shell-python-for-example-for-implemen) and also because it is a desire of this project, the software [Mokka](http://b-tk.googlecode.com/svn/web/mokka/index.html) will embed a scripting language to interact efficiently with the user interface and even more!

# Scope statement #
While the embedding of a script language is very powerful, it doesn't mean that the software has to be implemented around it. Indeed, Mokka is already highly advanced for the visualization of biomechanical data and the scripting language should take advantage of this and not the opposite. As a result, the following concerns were taken into account during the choice of the script language:
  * Should take advantage of the current third-party libraries used ([BTK](http://code.google.com/p/b-tk/), [Qt](http://qt.nokia.com/), [VTK](http://www.vtk.org/))
  * Based on an already existing scripting language ([Lua](http://www.lua.org/), [Python](http://www.python.org/), etc.)
    * Already adopted in the scientific community
    * Not dependent of commercial software
    * Compatible with the BSD license used in this project
  * Easy integration of the next features of BTK/Mokka in the script language
  * Extendable by the users
  * Reduced code refactoring (if possible)

Lots of scripting languages exist (Python, Perl, Lua, Tcl, Ruby, Matlab, Octave, QtScript, JavaScript etc.), however only the [Python](http://www.python.org/) language was known to fulfill all the concerns presented previously. Indeed, using [SWIG](http://swig.org/), it is possible to create Python library for C++ code. Moreover, several modules exist (e.g. [Numpy](http://numpy.scipy.org/)) for scientific computing but also to create connection with database, etc. An other advantage is also that some projects developed Python console using Qt ([PythonQt](http://pythonqt.sourceforge.net/), [CTK](http://www.commontk.org/), [QConsole](http://qconsole.sourceforge.net/)). However, the strongest point in favor of Python was the possibility to integrate directly Qt C++ objects into a Python environment without the use of any external definition file or other extra works by using [PythonQt](http://pythonqt.sourceforge.net/). The developers can then continue to focus on the development of the C++ with a limited amount of time for the development of the scripting language.

# Implementation #

The implementation will require to include the third-party library [PythonQt](http://pythonqt.sourceforge.net/) which will be included as a dynamic library (dll,so,dylib) due to the LGPL 2.1 license used by the project (because it cannot be linked statically to a non (L)GPL project).

The implementation and debugging of a Python console could take also lots of time (even if [PythonQt](http://pythonqt.sourceforge.net/) reduce dramatically the time required). It was then decided to choose the Python console proposed by [CTK](http://www.commontk.org/) as the license used (Apache 2.0) is compatible with the BSD license. Moreover, the implementation proposed by CTK is highly advanced and propose to launch directly Python script during the initialization of the Python interpreter. Finally, the interpreter (model) is separeted of the widget (view), giving the possibility to have several views of the Python console but using the same workspace.

However, several refactoring in the code of Mokka are required to propose the above syntax for the scripting language. This refactoring will be also the possibility for the project to add unit test for the user interface (using [QTestLib](http://qt-project.org/doc/qt-4.8/qtestlib-manual.html)) and to implement the class with the pimpl idiom (opaque pointer) provided by [Qt](http://qt.nokia.com/).

Finally, the scripting language will take advantage of the Python module `btk` planned in the next release of BTK (BTK 0.2).

# Syntax #

Note: The following is only an example of the possible syntax and could be modified in the final version

All the functions will packaged in the module `mokka` and shared between the following part:
  * `mokka.app`: methods related to the application (open/save file, etc.)
  * `mokka.settings`: access to the settings of the applications
  * `mokka.acquisition`: access to the content of the loaded acquisition
  * `mokka.model`: access to the content of the loaded model
  * `mokka.tool`: predefined operations on the data
  * `mokka.logger`: to send message to the logger, clear the logger
  * `mokka.ui`: access to user interface (layout, file info, show/hide acquisition explorer, ...)
  * `mokka.util`: other function which could be necessary ... data converting, etc.

The page MokkaPythonScriptingDraftApi proposes a possible API for the module `mokka`.

# Roadmap #

This feature will be included in Mokka 0.7 which is expected for ~~december 2012~~ (postponed to an unknown date). The implementation will start in the `mokka-python-script` branch when Mokka 0.6 and BTK 0.2 will be released.