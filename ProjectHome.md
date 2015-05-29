<table width='100%'><tr><td valign='top'>This is an open-source Biomechanical ToolKit named BTK.</td><td align='right'><a href='http://b-tk.googlecode.com/files/btk-256.png'><img src='http://b-tk.googlecode.com/files/btk-256.png' /></a></td></tr></table>

<h1>News</h1>
<table>

<tr>
<td width='130px'><i>February 17, 2014</i></td>
<td><b>Peer-reviewed article for Biomechanical ToolKit</b></td>
</tr><tr>
<td></td><td>We have the pleasure to announce you that a peer-reviewed <a href='http://www.sciencedirect.com/science/article/pii/S0169260714000248'>article</a> is now available for BTK and Mokka. This paper can be used to cite the project in your study.</td>
</tr>

<tr>
<td width='130px'><i>January 9, 2014</i></td>
<td><b>Python package for BTK 0.3 released</b></td>
</tr><tr>
<td></td><td>The Python binding of BTK 0.3 is available in the PythonBinaries page. The package for Linux is now proposed using the DEB and RPM formats which automatically install the required dependencies.</td>
</tr>

<tr>
<td width='130px'><i>January 9, 2014</i></td>
<td><b>Matlab toolbox for BTK 0.3 released</b></td>
</tr><tr>
<td></td><td>A new version of the <code>btk</code> toolbox for Matlab (32-bit and 64-bit) under Windows, MacOS X, and Linux is available in the MatlabBinaries page.</td>
</tr>

<tr>
<td width='130px'><i>January 9, 2014</i></td>
<td><b>BTKCore 0.3 released</b></td>
</tr><tr>
<td></td><td>This is the first release of BTK since the modification in the <a href='GitRepositories.md'>structure</a> of the project. This release improves mostly the internal behavior of the C++ API and fix issues related to the Python/Octave/Matlab bindings. <a href='https://code.google.com/p/b-tk/downloads/detail?name=btk-core-0.3.0_src.zip'>Download</a>, <a href='BTKCore_030.md'>Detailed changelog</a></td>
</tr>

<tr>
<td width='130px'><i>November 5, 2013</i></td>
<td><b>Official mirror on GitHub</b></td>
</tr><tr>
<td></td><td>The Biomechanical ToolKit has now also Git repositories on <a href='https://github.com/Biomechanical-ToolKit'>GitHub</a>. These repositories will be mostly used to test the modifications in the code (i.e. for the continuous integration).</td>
</tr>

<tr>
<td width='130px'><i>October 1, 2013</i></td>
<td><b>Biomechanical ToolKit switched from SVN to Git</b></td>
</tr><tr>
<td></td><td>The Biomechanical ToolKit project switched from SVN to Git and was split into different parts to facilitate the development. More information on the wiki page GitRepositories.</td>
</tr>

<tr>
<td width='130px'><i>May 23, 2013</i></td>
<td><b>Matlab toolbox for BTK 0.2.1 released</b></td>
</tr><tr>
<td></td><td>The MEX functions for Matlab (32-bit and 64-bit) under Windows and MacOS X are available in the MatlabBinaries page.</td>
</tr>

<tr>
<td width='130px'><i>May 7, 2013</i></td>
<td><b>Mokka 0.6.2 released</b></td>
</tr><tr>
<td></td><td>Maintenance release for Mokka 0.6 focused on the automatic update. <a href='http://b-tk.googlecode.com/svn/web/mokka/index.html'>Download</a><img src='http://b-tk.googlecode.com/svn/web/images/external-link.gif' />, <a href='http://b-tk.googlecode.com/svn/web/mokka/news.html#Mokka_0.6.2'>Changelog</a><img src='http://b-tk.googlecode.com/svn/web/images/external-link.gif' /></td>
</tr>

</table>

# Introduction #
BTK is an open-source and cross-platform library for biomechanical analysis. BTK read and write [acquisition files](FileFormatSupported.md) and can modify them. All these operations can be done by the use of the C++ API or by the wrappers included (Matlab, Octave, and Python).

The core of BTK is primary based on a pipeline design and on shared pointers. Each process can be linked (the output of previous is the input of the next) and scheduled together. The use of shared pointers permits to avoid the need of memory allocation/deletion, the choice of object's owner and the possibilities of memory leaks. Since BTK 0.1.7, the binary files (C3D, TRB, ANB, RIC, etc) use the [memory-mapped file](http://en.wikipedia.org/wiki/Memory-mapped_file)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif) mechanism to be read and written faster (2x and more).

# Changelog #
The list of changes in the releases of BTK is available [here](Changelog.md)

# Support #
If you have any question or you think you found a bug, you can send an email to the [BTK Users](http://groups.google.com/group/btk-users)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif) group. You can also tweet [@btkwww](http://twitter.com/btkwww)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif) for any informations.

# Download #
The latest packaged sources are for [BTK Core 0.3](https://code.google.com/p/b-tk/downloads/detail?name=btk-core-0.3.0_src.zip).

## Mokka software ##
The latest binaries for Mokka are available on the [mini-website](http://b-tk.googlecode.com/svn/web/mokka/index.html)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif) by clicking on the button _Download Now_. These binaries are available for MacOS 10.7+ (64-bit) and for Windows (32/64-bit).

## Python binding ##

The latest packages for the Python binding are accessible on the page PythonBinaries.

## Matlab binding ##

The latest packages for the Matlab binding are accessible on the page MatlabBinaries.

# Documentation #
The documentation presented below is also centralized in this [page](SummaryDocumentation.md). You will find also the official [logos](SummaryDocumentation#Logo.md) used by BTK and Mokka and also some informations to [cite](SummaryDocumentation#Publication.md) the project Biomechanical ToolKit in your papers.

## Build instructions ##

The BTK sources include a `Readme.html` which details the configuration, compilation and install steps.

## C++ API ##

The API documentation for the latest release can be found [here](http://b-tk.googlecode.com/svn/doc/API/0.3/index.html)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif). It includes also tutorials to integrate BTK in your project.

## Python ##

The binding is proposed into a package named `btk`. Even if you can find the binding documentation by using the command `help(btk)`, there is also an online documentation [here](http://b-tk.googlecode.com/svn/doc/Python/0.3/index.html)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif). It includes, tutorials, FAQ and a description for each function.

You can download the latest binaries for Python by using the informations in the PythonBinaries page.

## Matlab/Octave ##

Each binding is packaged into a toolbox named `btk`. Even if you can find the binding documentation by using the command `help btk`, there is also an online documentation [here](http://b-tk.googlecode.com/svn/doc/Matlab/0.3/index.html)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif). It includes, tutorials, FAQ and a description for each function.

You can download the latest binaries for Matlab by using the informations in the MatlabBinaries page.

Detailed instructions to build Octave are available in the wiki page OctaveBuildInstructions.

### C3DServer emulation ###
The program C3Dserver gives access to the content of a C3D file and is able modify it under Windows 32-bit in programs such as Matlab, Labview or Excel. However, with the development of the computers' architecture (32-bit vs 64-bit) and the variety of the operating systems (Windows, MacOS X, Linux), several users cannot use anymore C3DServer.

To resolve this problem under Matlab/Octave, a M-Script file was written to emulate C3Dserver using the BTK functions. All the informations to see how to use it as well as benchmarks are in the wiki page [C3DServerEmulationForMatlab](C3DServerEmulationForMatlab.md).

## Mokka ##

Mokka (MOtion Kinematics & Kinetics Analyzer) is a standalone cross platform software which uses heavily BTK. Started only as a demo software to show the possibilities to display markers' data in a 3D environment, it is today a valuable tool to explore biomechanical data (markers, forceplates, EMGs, video, etc).

Mokka has a [mini-website](http://b-tk.googlecode.com/svn/web/mokka/index.html)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif) to show its main features and to download the latest release. There is also a [UserVoice](http://mokka.uservoice.com/forums/158152-mokka)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif) page where you can add and vote for the next features to implement! The help integrated into Mokka is also available online (using the screenshot for MacOS X). You can find the documentation for the latest relase of Mokka [here](http://b-tk.googlecode.com/svn/doc/Mokka/0.6/index.html)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif).

### Roadmap ###

You can check the [roadmap](MokkaRoadmap.md) for the next releases of Mokka. If you would like some specific features or improvement, please contact us.

# Projects using BTK #

If your project is not in the following list, don't hesitate to send us an email to tell how BTK helps you!

**Extensions**

  * [Moiré Pattern Tracking System](http://www.metriainnovation.com/?page_id=76)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif), Read output from the MPT system developed by [Metria Innovation](http://www.metriainnovation.com/)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif).

**Software applications**

The following projects use BTK to open biomechanical data stored in C3D files:
  * [ICT4Rehab](http://www.ict4rehab.org)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif), Advanced ICT Platform for Rehabilitation.
  * [FusionBox](http://homepages.ulb.ac.be/~labo/biomechanics/The_lhpFusionBox.html)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif), Dedicated software system for heterogeneous data fusion.
  * [OpenMAF](http://www.openmaf.org/)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif), Multimod Application Framework, a software framework for the rapid development of computer aided medicine applications.
  * [NMS Physiome](http://www.nmsphysiome.eu/)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif), Personalised models of the neuromusculoskeletal system.

**OpenSim projects**

  * [London Lower Limb Model](https://simtk.org/home/low_limb_london)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif), The London Lower Limb Model model is based on one of the most recent anatomical dataset published in the literature (Klein Horsman, 2007).
  * [Matlab Opensim Pipeline Tools](https://simtk.org/project/xml/downloads.xml?group_id=660#package_id1072)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif), Tools for taking motion capture data from C3D files and generating the required input files.

**Laboratories / Researchers**

Many laboratories and researchers around the world use Biomechanical ToolKit in their studies. If you want to add your location on the map, send us an email!
&lt;wiki:gadget url="http://b-tk.googlecode.com/svn/wiki/BTKGoogleMapGadget.xml" width="850" height="500" /&gt;

View [BTK Users and Collaborators Map](https://maps.google.com/maps/ms?msid=203459523619791700710.0004cb4a8d20c6df8f6b8&msa=0&ll=27.683528,38.847656&spn=114.354491,228.339844)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif) in a larger map.

# Requirements #
BTK already contains required library to compile its core. It uses a modified version of [CxxTest](http://cxxtest.sf.net)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif) for unit and regressions tests and [Eigen3](http://eigen.tuxfamily.org)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif) for matrix computations.

However, to build BTK, it is required to download and install [CMake](http://www.cmake.org)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif) plus a compiler (GCC 3.3 or above, MSVC 2003 or above, ...). The documentation requires [Doxygen](http://www.doxygen.org)![http://b-tk.googlecode.com/svn/web/images/external-link.gif](http://b-tk.googlecode.com/svn/web/images/external-link.gif) to be generated.

For more informations on the options available in BTK, you should read the file `Readme.html` included with the source code.

# Copyright Notice #
BTK use the generous open-source New BSD license. Yes, you can use BTK in commercial products. The complete text of the copyright is included in BTK sources.