# Introduction #

The Biomechanical ToolKit (BTK) is proposed for Python as a package called `btk`. After the installation of the package, you will need only to use the command `import btk` within a Python script to use BTK.

A first test to know if the toolbox is installed is to type `import btk` in a Python console. If no error is displayed, then BTK is correctly loaded. You can then use the command `help(btk)` to access to the embedded documentation.

The documentation is also available [online](http://b-tk.googlecode.com/svn/doc/Python/0.3/index.html)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif), including [tutorials](http://b-tk.googlecode.com/svn/doc/Python/0.3/_getting_started.html.html)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif).

# Installation #

To facilitate the installation of the Python binding, native installer are proposed under Windows and Linux. For these OS you only need to double-click on the downloaded file corresponding to your configuration. For MacOS X, the Python EGG format is still used. After downloading the EGG file, you only need to type the following command in a terminal `sudo easy_install -N btk-x.y-py2.7_macos-10.z-intel.egg`.

# Available binaries #

## Windows (Installer) ##

  * [python-btk-0.3.0\_win-amd64.exe](http://code.google.com/p/b-tk/downloads/detail?name=python-btk-0.3.0_win-amd64.exe) (64-bit installer)
  * [python-btk-0.3.0\_win32.exe](http://code.google.com/p/b-tk/downloads/detail?name=python-btk-0.3.0_win32.exe) (32-bit installer)

**Note**: The Windows installer cannot install the NumPy dependency automatically. Except if you use SciPy, you must download the NumPy installer yourself and install it. The NumPy installer is available in [32-bit](http://sourceforge.net/projects/numpy/files/NumPy/)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif) and [64-bit](http://www.lfd.uci.edu/~gohlke/pythonlibs/#numpy)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif).

## MacOS X ##

  * [btk-0.3.0-py2.7\_macosx-10.7-intel.egg](https://code.google.com/p/b-tk/downloads/detail?name=btk-0.3.0-py2.7_macosx-10.7-intel.egg) (MacOS X 10.7 or greater / Python framework 2.7 - 64-bit)

## Linux ##

  * **DEB package**
    * [python-btk\_0.3.0-1\_amd64.deb](https://code.google.com/p/b-tk/downloads/detail?name=python-btk_0.3.0-1_amd64.deb) (64-bit installer)
    * [python-btk\_0.3.0-1\_i386.deb](https://code.google.com/p/b-tk/downloads/detail?name=python-btk_0.3.0-1_i386.deb) (32-bit installer)

  * **RPM package**
    * [python-btk-0.3.0-1\_x86\_64.rpm](https://code.google.com/p/b-tk/downloads/detail?name=python-btk-0.3.0-1_x86_64.rpm) (64-bit installer)
    * [python-btk-0.3.0-1\_i686.rpm](https://code.google.com/p/b-tk/downloads/detail?name=python-btk-0.3.0-1_i686.rpm) (32-bit installer)