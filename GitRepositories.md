Starting from 1 October 2013, the project Biomechanical ToolKit switched from the versioning control system subversion (SVN) to Git. At the same time it was also decided to split the code into several pieces to have the possibility to create more releases of each component instead of waiting for the finalization of all of them. Hence, the project was divided in three parts:
  * BTKCore: Modules to represent biomechanical data, file formats and processing;
  * BTKQt: UIs for BTKCore using the cross-platform library [Qt](http://qt-project.org);
  * Mokka: Dedicated user interface to visualize and process biomechanical data.

The data used for the unit tests also moved out of the sources in another part: BTKData.

Each part has its own Git repository:
  * BTKCore is in the repository [b-tk.core](https://code.google.com/p/b-tk/source/list?repo=core)
  * BTKQt is in the repository [b-tk.qt](https://code.google.com/p/b-tk/source/list?repo=qt) **(not yet available)**
  * BTKData is in the repository [b-tk.data](https://code.google.com/p/b-tk/source/list?repo=data)
  * Mokka is in the repository [b-tk.mokka](https://code.google.com/p/b-tk/source/list?repo=mokka) **(not yet available)**

**Note**: By default Google Code proposes a default Git repository but this one is not used. That's why when you click on the "Source" tab, the list of changes is empty. You need to select one of the other listed repositories to see their content.