**Note**: The current version of btkEmulateC3DServer is a beta version as few functions don't give the excepected result compared to C3DServer. If you have more informations on these function, please contact us to resolve these problems.
  * `Appendata`: Can we add directly strings? If yes, what is the syntax for C3Dserver?
  * `AddFrames`: Can we add frames other than at the beginning (-1) or the end (-2)? If yes, what is the syntax for C3Dserver?
  * `GetForceData`: Results are not the same. Need to remove an offset. How is it computed?
  * `GetMomentData`: Results are not the same. Need to remove an offset. How is it computed?

# Introduction #

The program [C3Dserver](http://www.c3dserver.com/) gives access to the content of a C3D file and is able modify it under Windows 32-bit in programs such as Matlab, Labview or Excel.

However, with the development of the computers' architecture (32-bit vs 64-bit) and the variety of the operating systems (Windows, MacOS X, Linux), several users cannot use anymore C3DServer.

To resolve this problem under Matlab, a M-Script file were written to emulate `C3Dserver` using the BTK functions.

This function is named `btkEmulateC3Dserver` and will be provided in the `btk` Matlab toolbox (0.2).

The main difference between `C3Dserver` and its emulated version by BTK is the way you call it. In Matlab, calling `C3Dserver` is done by the code `c3dsrv = actxserver('C3Dserver.C3D');`. Using the emulation, you will use the command `btksrv = btkEmulateC3Dserver();`.

Depending your OS you would use `C3Dserver` or `btkEmulateC3Dserver` without modifying your code each time. You can use the following script to use the native `C3Dserver` under Windows 32-bit and use `btkEmulateC3Dserver` for the other OS.

```
function srv = C3DServer()
    srv = 0;
    % Check if Matlab is installed under Windows 32-bit
    if ~strcmp(computer, 'PCWIN')
      srv = btkEmulateC3Dserver();
    else
      srv = actxserver('C3Dserver.C3D');
    end
```

Because BTK implements functions at a higher level than C3Dserver (you manipulate the content of an acquisition and not the content of a C3D file), you could be interested to use some of the BTK functions. For that, and from the emulated COM object, you have the special function `GetHandle` which will gives you access to the handle used by BTK to interact with the acquisition's content. For example, you can compute easily the point of application of the ground reaction forces (in lots of case equivalent to the COP) expressed in the global frame for any supported force platform in the C3D format by using the command `btkGetGroundReactionWrenches`.

```
srv = btkEmulateC3Dserver();
srv.Open('myFile.c3d',3);
GRW = btkGetGroundReactionWrenches(srv.GetHandle());
plot(GRW(1).P) % plot trajectory for the point of application of the ground reaction forces for the force platform #1
```

# Requirements #
You need at least BTK 0.1.7 compiled with Matlab support. The latest binaries compiled with the Matlab support are proposed [here](MatlabBinaries.md).

# Emulation compatibility #
The emulation gives you access to all the functions furnished with C3Dserver 1.144.0 (at least when writing this documentation). More than 175 tests were build during the development of the this emulator to be sure to have the same than C3Dserver (extraction of data, data modification, input/output format). These tests were realized with [Matlab xUnit](http://www.mathworks.com/matlabcentral/fileexchange/22846-matlab-xunit-test-framework) and are provided in the source code of BTK: `/Testing/Matlab/TDD.m`

However in some case the internal behavior is slightly different due to the different way to handle the content of a C3D file with BTK. The following list gives you the differences:
  * This emulation use function handles and then required for every functions to be used with parenthesis (you cannot call `itf.Close` but `itf.Close()`). Use parenthesis keep your code compatible with C3Dserver.
  * A C3D file is always opened in mode 3.
  * The events in BTK use the new format proposed in the C3D  documentation (using the group EVENT and EVENT\_CONTEXT) which   removes the limits of 18 events (and also the possibility to write  event's label with more than 4 characters). All the events stored in  the C3D header are automatically converted. However, at this moment,  the event's status is not kept (can be added if necessary). Then,  using the following code with BTK: `itf.SetEventStatus(0,'0')` sends a warning and do nothing. To remove the warning, you have to add this command: `warning('OFF','btk:C3Dserver:SetEventStatus')`
  * The group and parameter number are generated from the index instead of using the ID stored in the C3D file. Like that, the user doesn't  need to manage this number. So, if you set the group or parameter  number, a warning will inform you of the impossibility to do it. To remove this warning, type the following command: `warning('OFF','btk:C3Dserver:UniqueNumber')` Removing this warning has an effect on the functions `SetGroupNumber`, `SetParameterNumber`. But also on the function `AddGroup` when you set manually the number.
  * The function `CompressParameterBlocks` is alway activated in BTK as the  group/parameter are regenerated when you write the C3D. Trying to deactivate the compression (by using `CompressParameterBlocks(0)`) will send a warning. To remove the warning, you have to add the command: `warning('OFF','btk:C3Dserver:CompressParameterBlocks')`.
  * If some groups and parameters has the same name in the C3D file (which is the case with the group PROCESSING and its parameter for C3D files generated with Vicon Nexus 1.4), then BTK remove the duplication  (which is not the case of C3Dserver).
  * When you delete a group, it is not possible to keep the associated  parameters (They are stored in the group). If you try to do it, then a warning will be displayed and the parameters are removed. To remove the  warning, use the command: `warning('OFF','btk:C3Dserver:DeleteGroup')`.
  * The parameters are sorted by groups. Then if you select parameter by using hardcoded indices, you could have unexpected results.
  * The parameters' values are managed automatically inside BTK. In the case of parameter with the type 'Char', BTK trims (remove leading and trailing white space) values when you open the C3D file. If you set a number in a parameter with the type Char, then the number is converted into a string.
  * When you modify the parameter's type, then BTK adapts its values. In lots of conversion you can come back to the original value. However, transforming a string which doesn't contain a number creates the value 0. If you convert a Real into an Integer, you lost the  floating information. If you convert an Integer into a Byte and the  value is not in the range `[`-128, 127`]`, then you lost the most  significant part of the number. For example, the conversion (Char->Integer) for 'FOO' creates the number 0. But the conversion (Char->Integer) for '1234' creates the number 1234. The conversion (Integer->Byte) for the number 12456  creates the number 168.
  * Modifying the parameter's type, adapts also its dimensions.  For example, transforming a integer parameter into a char parameter add 1 dimension corresponding to the number of characters. Or, in the other case, transforming a char parameter into an integer, remove.
  * Retrieving a parameter in another index than the original will keep the group for this index.
  * Trying to retrieve a parameter which has the same name than one in  the destination group (other than the original group) will throw an error.
  * An AV ratio equal to 0 in BTK is automatically converted to 1. The  number of analog frames is at least equal to the number of video frames.

# Benchmarks #
Even if the use of an emulation of a program could mean that your program will run slower, it doesn't mean it is not useable or that it is even true every time. And this is specially true when you compare our emulation to the evaluation version of C3Dserver.

Based on the Matlab benchmark program provided in the source code of BTK: `/Testing/Matlab/benchmarkC3DserverEmulation.m`, we test the time required to access to header data, event, groups/parameters, points and analog data.

The following tables gives you the comparisons. The tests were repeated 10 times and then averaged. In some case the emulation is 10 times faster and even more!

## C3Dserver 32-bit ##

The tests were realized using C3Dserver 1.144.0 and BTK 0.1.8 with Matlab R2009a on Windows XP SP3. The configuration of the computer used for these benchmarks was: Intel Core 2 Quad CPU Q4900 @ 2.66GHz 2.67GHz, 3.24 GB of RAM (Pysical Address Extension).

### Evaluation version ###

| **Operation** | **C3Dserver** | **BTK** | **Ratio** |
|:--------------|:--------------|:--------|:----------|
|               | time (sec)    | time (sec) |           |
| COM object creation | 0.001         | 0.056   | 0.020     |
| Open C3D File | 0.005         | 0.009   | 0.568     |
| Access C3D Header data | 0.019         | 0.004   | 4.558     |
| Access C3D Event data | 0.021         | 0.002   | 12.416    |
| Access C3D Parameter data | 1.224         | 0.294   | 4.167     |
| Access C3D Point values (`GetPointData`) | 2.357         | 0.133   | 17.761    |
| Access C3D Point range (`GetPointDataEx`)| 0.590         | 0.048   | 12.178    |
| Access C3D Analog values (`GetAnalogData`) | 2.359         | 0.698   | 3.382     |
| Access C3D Analog range (`GetAnalogDataEx`) | 0.593         | 0.114   | 5.221     |

This difference is mainly explained by the delay introduced in the free version of C3Dserver.

### Licensed version ###

Thanks to the Motion Lab Systems company which provided us a commercial license of C3Dserver, we compared the emulation with it.

| **Operation** | **C3Dserver** | **BTK** | **Ratio** |
|:--------------|:--------------|:--------|:----------|
|               | time (sec)    | time (sec) |           |
| COM object creation | 0.000         | 0.012   | 0.017     |
| Open C3D File | 0.004         | 0.008   | 0.430     |
| Access C3D Header data | 0.000         | 0.001   | 0.162     |
| Access C3D Event data | 0.000         | 0.001   | 0.233     |
| Access C3D Parameter data | 0.009         | 0.293   | 0.031     |
| Access C3D Point values (`GetPointData`) | 0.021         | 0.132   | 0.161     |
| Access C3D Point range (`GetPointDataEx`)| 0.022         | 0.049   | 0.452     |
| Access C3D Analog values (`GetAnalogData`) | 0.028         | 0.696   | 0.041     |
| Access C3D Analog range (`GetAnalogDataEx`) | 0.080         | 0.112   | 0.717     |

As expected the emulation is slower as BTK use high level functions to emulate low level functions (need more operations to do the same). However the average times are correct especialy for the functions `GetPointDataEx` and `GetAnalogDataEx` which might be widely used in programs.

The poor results of the functions `GetPointData` and `GetAnalogData` are explained by the way they are emulated. BTK has no function to extract a single value. So we extract all the data for a point or an analog channel and then return only a single value. If necessary, these emulated functions can be largely improved by implementing native functions returning only a required range.

## C3Dserver 64-bit ##

Since recently (November 5th, 2011), the Motion Lab Systems company provides a beta of C3Dserver 64-bit. The following benchmarks are then not final and will be updated with the next release of C3Dserver.

The tests were realized using Matlab R2010a 64-bit on Windows 7 SP1 x64. The configuration of the computer used for these benchmarks was: Intel Core 2 Quad CPU Q4900 @ 2.66GHz 2.67GHz, 4 GB of RAM.

### Evaluation version ###

| **Operation** | **C3Dserver** | **BTK** | **Ratio** |
|:--------------|:--------------|:--------|:----------|
|               | time (sec)    | time (sec) |           |
| COM object creation | 0.001         | 0.063   | 0.020     |
| Open C3D File | 0.018         | 0.011   | 1.682     |
| Access C3D Header data | 0.150         | 0.005   | 28.696    |
| Access C3D Event data | 0.166         | 0.002   | 69.867    |
| Access C3D Parameter data | 9.606         | 0.341   | 28.170    |
| Access C3D Point values (`GetPointData`) | 18.747        | 0.193   | 97.085    |
| Access C3D Point range (`GetPointDataEx`)| 4.714         | 0.060   | 79.173    |
| Access C3D Analog values (`GetAnalogData`) | 18.870        | 0.852   | 22.138    |
| Access C3D Analog range (`GetAnalogDataEx`) | 4.626         | 0.113   | 40.820    |

### Licensed version ###

Not yet tested.