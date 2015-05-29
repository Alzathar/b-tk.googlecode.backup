**Note**: Due the compatibility mechanism integrated in Matlab, you cannot use MEX functions compiled for a version of Matlab released after the version you use. For example, if BTK is compiled with Matlab R2008b and you are using Matlab R2007a, you cannot use the MEX functions. Matlab will send you an error message.

# Introduction #

There is no installation required to use BTK with Matlab. Download the ZIP file and decompress it. Copy the folder BTK where you want (for example C:\Progam Files under Windows or /Applications under MacOS X).
In Matlab add only the path `btk` using the menu File > "Set path..."

A first test to know if the toolbox is recognized by Matlab is to type `help btk` in the command window. The content of the Matlab help is also available [online](http://b-tk.googlecode.com/svn/doc/Matlab/0.3/index.html)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif), including [tutorials](http://b-tk.googlecode.com/svn/doc/Matlab/0.3/_tutorial.html)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif).

# Available binaries #

## Windows ##
**Note**: If you are using Matlab 32-bit under Windows 7 64-bit, you must download "BTK x.y.z for Windows 7 with Matlab R2008b 32-bit"

  * Matlab 32-bit
    * [BTK 0.3 binding for Matlab R2008b or greater (32-bit) / \*Windows XP only\*](https://code.google.com/p/b-tk/downloads/detail?name=btk-0.3.0_WinXP_MatlabR2008b_32bit.zip)
    * [BTK 0.3 binding for Matlab R2008b or greater (32-bit) / Windows Vista/7/8/8.1](https://code.google.com/p/b-tk/downloads/detail?name=btk-0.3.0_Win7_MatlabR2008b_32bit.zip)
  * Matlab 64-bit
    * [BTK 0.3 binding for Matlab R2009b or greater (64-bit) / Windows Vista/7/8/8.1](https://code.google.com/p/b-tk/downloads/detail?name=btk-0.3.0_Win7_MatlabR2009b_64bit.zip)

## MacOS X ##

  * Matlab 64-bit
    * [BTK 0.3 binding for Matlab R2009b or greater (64-bit) / MacOS X 10.7+](https://code.google.com/p/b-tk/downloads/detail?name=btk-0.3.0_MacOS10.7_MatlabR2009b_64bit.zip)

  * Matlab 32-bit
    * [BTK 0.3 binding for Matlab R2009b or greater (32-bit) / MacOS X 10.7+](https://code.google.com/p/b-tk/downloads/detail?name=btk-0.3.0_MacOS10.7_MatlabR2009b_32bit.zip)

**Note**: The toolbox was compiled under MacOS 10.9 with the option to be compatible with MacOS 10.7. Please report any problem if it doesn't work on your computer. The 32-bit version should be only used with the Matlab student version

## Linux ##

  * Matlab 64-bit
    * [BTK 0.3 binding for Matlab R2009a or greater (64-bit) / Linux](https://code.google.com/p/b-tk/downloads/detail?name=btk-0.3.0_Linux_MatlabR2009a_64bit.tar.gz)

  * Matlab 32-bit
    * [BTK 0.3 binding for Matlab R2009a or greater (32-bit) / Linux](https://code.google.com/p/b-tk/downloads/detail?name=btk-0.3.0_Linux_MatlabR2009a_32bit.tar.gz)

**Note**: Under Linux 64-bit, you need to follow the instructions in the README file. Moreover, after the copy of the libraries, you need to update the dynamic loader. To do so, you have to open a terminal and type the command 'sudo ldconfig' (without the quote). This will update the dynamic loader which will discover the libraries copied for BTK.

**Note**: If Matlab send you an error about an unknown version of GLIBCXX, it is because Matlab embeds is own version and conflicts with the version in your computer. The only way found to fix this is to move the files `libstdc++.so.6.*` to another folder (for example the subfolder `_btk_fix_glibcxx`). The location of these files depends on the version of Matlab. Under Matlab R2009a, the files are in the folder `MATLABXY/sys/os/glnx(86|a64)`, while with Matlab R2012a, they are in the folder `MATLABXY/bin/glnx(86|a64)`. This modifcation won't affect the behavior of Matlab as it will use then the computer's version of libstdc++.