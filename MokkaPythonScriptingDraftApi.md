The following lines give an example of the functions which will be within the scripting language embedded in Mokka.

```
# Application properties
mokka.app.platform
mokka.app.arch
mokka.app.os
mokka.app.majorVersion
mokka.app.minorVersion
mokka.app.patchVersion
# Application operations
mokka.app.quit()
mokka.app.restart()
mokka.app.openAcquisition(string)
mokka.app.closeAcquisition()
mokka.app.importAcquisition(string)
mokka.app.exportAcquisition(string)
mokka.app.saveAcquisition()
mokka.app.saveAsAcquisition(string)
mokka.app.loadModelVisualConfiguration(string)
...
# Acquisition properties
mokka.acquisition.fileName()
...
# - Points operations
mokka.acquisition.insertPoint(id,label,coord,residual,description)
mokka.acquisition.removePoint(id)
mokka.acquisition.pointCount()
# - Points properties
mokka.acquisition.pointLabel(id)
mokka.acquisition.setPointLabel(id,string)
mokka.acquisition.pointDescription(id)
mokka.acquisition.setPointDescription(id,string)
mokka.acquisition.markerRadius(id)
mokka.acquisition.setMarkersRadius(id,double)
...
# - Event operations
mokka.acquisition.insertEvent(id,label,frame,subject,description,iconid)
mokka.acquisition.removeEvent(id)
mokka.acquisition.eventCount()
# - Event properties
mokka.acquisition.eventLabel(id)
mokka.acquisition.setEventLabel(id,string)
mokka.acquisition.eventDescription(id)
mokka.acquisition.setEventDescription(id,string)
mokka.acquisition.eventContext(id)
mokka.acquisition.setEventContext(id,string)
mokka.acquisition.eventSubject(id)
mokka.acquisition.setEventSubject(id,string)
mokka.acquisition.eventFrame(id)
mokka.acquisition.setEventFrame(id,frame)
mokka.acquisition.eventTime(id)
mokka.acquisition.setEventTime(id,double)
mokka.acquisition.eventIconId(id)
mokka.acquisition.setEventIconId(id,idx)
# - Analog operations
...
# - Analog properties
...

# Model
# - Segment operations
...

# Tools
mokka.tool.createAverageMarker(markerLabels)
...

# Settings
mokka.settings.defaultModelVisualConfigurationUsed()
mokka.settings.setDefaultModelVisualConfigurationUsed(bool)
mokka.settings.defaultModelVisualConfigurationPath()
mokka.settings.setDefaultModelVisualConfigurationPath(string)
mokka.settings.defaultGroundOrientation()
mokka.settings.setDefaultGroundOrientation(enum)
...

# UI
mokka.ui.activateLayout(index)
mokka.ui.removeLayout(index)
mokka.ui.aboutMokka()
mokka.ui.openAcquisitionInformation()
mokka.ui.closeAcquisitionInformation()
mokka.ui.showAcquisitionExplorer()
mokka.ui.hideAcquisitionExplorer()
mokka.ui.setAcquisitionExplorerVisible(bool)
...

# Logger
mokka.logger.info(string)
mokka.logger.warning(string)
mokka.logger.critical(string)
mokka.logger.clear()

# Util
...
```