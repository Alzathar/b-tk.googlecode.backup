This page concerns the exportation of C3D files which could be used in Vicon products later (i.e., Polygon, Workstation or Nexus).

## Introduction ##
The following explanations are not limitations or bugs in BTK. They present the required parameters' format and values to be compatible with Vicon products (i.e. to not crash the software if some cases was not managed or to display informations correctly).

Only one known case is not automatically handled by BTK. This is the event's id (EVENT:ICON\_IDS). This choice was done to not overwrite the user's decision.

## Software crash ##
The following list reports the parameters' format which are not supported by Vicon products.
  * A null frequency (POINT:RATE) is impossible.
  * The description of each point (POINT:DESCRIPTIONS) can't be empty.
  * The description of each analog channel(ANALOG:DESCRIPTIONS) can't be empty.
  * The description of the parameter in the analysis (ANALYSIS:DESCRIPTIONS) can't be empty.
  * The subject associated which each parameter in the analysis (ANALYSIS:SUBJECTS) can't be empty.

By default, during the writing of a C3D file, BTK checks theses data and adapt them to be readable in Polygon.

## Informations display ##
Vicon products (Workstation and Nexus) use the parameter EVENT:ICON\_IDS to determine the type of the event (i.e. General, Foot Strike, Foot Off). Then, if the correct id is not set, their display are not correct. Even if there is no rule for the id value, these 3 next values are used in Vicon Workstation and Nexus:
  * General event: 0
  * Foot Strike: 1
  * Foot Off: 2
Without the use of these values, it is  known that Workstation and Nexus put all events in general (the default value is 0 in BTK). For Polygon, one user reported that some points had their values set to 0 when all events have their id set to 0.