# Acquisition file #

An acquisition file contains mostly marker trajectories and analog channel data.

| **File Format** | **Reader** | **Writer** | **Comments** |
|:----------------|:-----------|:-----------|:-------------|
| ANB             | <p align='center'><b>x</b></p> | <p align='center'><b>x</b></p> | _Motion Analysis_ binary file format containing analog channel data|
| ANC             | <p align='center'><b>x</b></p> | <p align='center'><b>x</b></p> | _Motion Analysis_ ASCII file format containing analog channel data|
| ANG<sup>1</sup> | <p align='center'><b>x</b></p> |            | _BTS Bioengineering (Elite)_ binary file format containing (joint) angles|
| BSF<sup>2</sup> | <p align='center'><b>x</b></p> |            | _AMTI_ binary file format containing force platform data.|
| C3D             | <p align='center'><b>x</b></p> | <p align='center'><b>x</b></p> | Most common used file format. More informations on http://www.c3d.org |
| CAL             | <p align='center'><b>x</b></p> | <p align='center'><b>x</b></p> | _Motion Analysis_ ASCII file format for force platform calibration|
| CLB             | <p align='center'><b>x</b></p> |            | _Contec Inc._ binary file format containing analog channel data|
| EMF             | <p align='center'><b>x</b></p> |            | _Ascension Technology Corporation_ ASCII file format containing 3D trajectories|
| EMG             | <p align='center'><b>x</b></p> |            | _Delsys Inc._ binary file format containing EMG data|
| EMG             | <p align='center'><b>x</b></p> |            | _BTS Bioengineering (Elite)_ binary file format containing EMG data|
| GR`*`<sup>3</sup> | <p align='center'><b>x</b></p> |            | _BTS Bioengineering (Elite)_ binary file format containing force platform data|
| MOM<sup>4</sup> | <p align='center'><b>x</b></p> |            | _BTS Bioengineering (Elite)_ binary file format containing joints' moments|
| MDF             | <p align='center'><b>x</b></p> |            | _Charnwood Dynamics Ltd (Codamotion)_ binary file format containing 3D trajectories, analog data and force platform geometry|
| PWR             | <p align='center'><b>x</b></p> |            | _BTS Bioengineering (Elite)_ binary file format containing joints' powers|
| RAH             | <p align='center'><b>x</b></p> |            | _BTS Bioengineering (Elite)_ binary file format containing joints' powers|
| RAW             | <p align='center'><b>x</b></p> |            | _BTS Bioengineering (Elite)_ binary file format containing 3D trajectories|
| RIC             | <p align='center'><b>x</b></p> |            | _BTS Bioengineering (Elite)_ binary file format containing 3D trajectories|
| RIF             | <p align='center'><b>x</b></p> |            | _BTS Bioengineering (Elite)_ binary file format containing 3D trajectories|
| TDF             | <p align='center'><b>x</b></p> |            | _BTS Bioengineering_ binary file format containing 3D trajectories, analog data and force platform geometry |
| TRB             | <p align='center'><b>x</b></p> |            | _Motion Analysis_ binary file format containing 3D trajectories <br>(<b>Experimental</b>: Need more files/informations to implement the writer) <br>
<tr><td> TRC             </td><td> <p align='center'><b>x</b></p> </td><td> <p align='center'><b>x</b></p> </td><td> <i>Motion Analysis</i> ASCII file format containing 3D trajectories </td></tr>
<tr><td> XLS             </td><td> <p align='center'><b>x</b></p> </td><td>            </td><td> <i>Motion Analysis</i> ASCII file format exported from the software <i>Orthotrack</i> </td></tr>
<tr><td> XMOVE           </td><td> <p align='center'><b>x</b></p> </td><td>            </td><td> <i>Charnwood Dynamics Ltd (Codamotion)</i> XML file format containing 3D trajectories, analog data and force platform geometry</td></tr></tbody></table>

<b>Remarks</b>
<ol><li>ANG files are loaded as 3D joints' angles instead of joints' angles separated in each plane (sagittal, frontal, transverse). Moreover, the foot progression angle is separated of the ankle angles for each foot.<br>
</li><li>BSF files with two force platforms and more are partially supported as the location of one platform relatively to the other is missing.<br>
</li><li>GR<code>*</code> files are loaded as force platforms of type I (i.e. ground reaction forces, COP, and ground reaction moments: <code>F(X|Y|Z), P(X|Y), MZ</code>).<br>
</li><li>MOM files contain moments expressed in Nm and stored by plane but values are automatically converted in Nmm and expressed by joints to be coherent with data in BTK.