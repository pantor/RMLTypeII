# RMLTypeII

Type II Reflexxes Motion Library

---------------------------------------------------------------
 Example Projects for the Type II Reflexxes Motion Library
---------------------------------------------------------------


***************************************************************
Directory Contents

- include: Folder for all header files of the Reflexxes API
  and the Type II Reflexxes Motion Library
- src: Folder for the source code files of the Type II
  Reflexxes Motion Library and the six sample applications


***************************************************************
Getting Started
***************************************************************

To build the library, just use the default CMake commands:

```
mkdir build
cd build
cmake .. -DBUILD_TYPE=Release
make
```

If everything compiles without error messages, you can take a look at one of
the simple sample applications in the 'examples' folder to learn
about the simple and clean Reflexxes API and to use it for
your own applications. In case of problems or issues with this
procedure, please contact us at support@reflexxes.com.


***************************************************************
Appendix - Entire Folder Structure

- include Folder for all header files of the Reflexxes API and the source code of the Type II Reflexxes Motion Library
- Linux Folder with example makefiles for Linux
		+ RMLPositionSampleApplications Folder for the makefile of 01_RMLPositionSampleApplication.cpp, 02_RMLPositionSampleApplication.cpp, 03_RMLPositionSampleApplication.cpp, and 07_RMLPositionSampleApplication.cpp
		+ RMLVelocitySampleApplications Folder for the makefile of 04_RMLVelocitySampleApplication.cpp, 05_RMLVelocitySampleApplication.cpp, 06_RMLVelocitySampleApplication.cpp, and 08_RMLVelocitySampleApplication.cpp
		+ TypeIIRML Folder for the makefile of the Type II Reflexxes Motion Library                
		+ x64 Binary files for 64-bit environments
			  # debug Files with debug information (non-optimized)
					* bin Executable files of all sample applications
					* lib This folder contains the Reflexxes Type II Motion Library.
					* obj Object files
			  # release Files without debug information (fully optimized)
					* bin Executable files of all sample applications
					* lib This folder contains the Reflexxes Type II Motion Library.
					* obj Object files
		+ x86 Binary files for 32-bit environments
			  # debug Files with debug information (non-optimized)
					* bin Executable files of all sample applications
					* lib This folder contains the Reflexxes Type II Motion Library.
					* obj Object files
			  # release Files without debug information (fully optimized)
					* bin Executable files of all sample applications
					* lib This folder contains the Reflexxes Type II Motion Library.
					* obj Object files
- MacOS Folder with example makefiles for Mac OS X
		+ RMLPositionSampleApplications Folder for the makefile of 01_RMLPositionSampleApplication.cpp, 02_RMLPositionSampleApplication.cpp, 03_RMLPositionSampleApplication.cpp, and 07_RMLPositionSampleApplication.cpp
		+ RMLVelocitySampleApplications Folder for the makefile of 04_RMLVelocitySampleApplication.cpp, 05_RMLVelocitySampleApplication.cpp, 06_RMLVelocitySampleApplication.cpp, and 08_RMLVelocitySampleApplication.cpp
		+ TypeIIRML Folder for the makefile of the Type II Reflexxes Motion Library
		+ x64 Binary files for 32-bit environments
			  # debug Files with debug information (non-optimized)
					* bin Executable files of all sample applications
					* lib This folder contains the Reflexxes Type II Motion Library.
					* obj Object files
			  # release Files without debug information (fully optimized)
					* bin Executable files of all sample applications
					* lib This folder contains the Reflexxes Type II Motion Library.
					* obj Object files
		+ x86 Binary files for 32-bit environments
			  # debug Files with debug information (non-optimized)
					* bin Executable files of all sample applications
					* lib This folder contains the Reflexxes Type II Motion Library.
					* obj Object files
			  # release Files without debug information (fully optimized)
					* bin Executable files of all sample applications
					* lib This folder contains the Reflexxes Type II Motion Library.
					* obj Object files							
- src Folder for the source code files of the six sample applications
		+ RMLPositionSampleApplications Source code of 01_RMLPositionSampleApplication.cpp, 02_RMLPositionSampleApplication.cpp, 03_RMLPositionSampleApplication.cpp, and 07_RMLPositionSampleApplication.cpp
		+ RMLVelocitySampleApplications Source code of 04_RMLVelocitySampleApplication.cpp, 05_RMLVelocitySampleApplication.cpp, 06_RMLVelocitySampleApplication.cpp, and 08_RMLVelocitySampleApplication.cpp
		+ TypeIIRML Source code of the Type II Reflexxes Motion Library
- Windows Folder with example project files for Microsoft Windows (Visual Studio 2008 Express)
		+ Debug Binary files with debug information (non-optimized)
		+ Release Binary files without debug information (fully optimized)
		+ 01_RMLPositionSampleApplication Folder for the project file of 01_RMLPositionSampleApplication.cpp
		+ 02_RMLPositionSampleApplication Folder for the project file of 02_RMLPositionSampleApplication.cpp
		+ 03_RMLPositionSampleApplication Folder for the project file of 03_RMLPositionSampleApplication.cpp
		+ 04_RMLVelocitySampleApplication Folder for the project file of 04_RMLVelocitySampleApplication.cpp
		+ 05_RMLVelocitySampleApplication Folder for the project file of 05_RMLVelocitySampleApplication.cpp
		+ 06_RMLVelocitySampleApplication Folder for the project file of 06_RMLVelocitySampleApplication.cpp
		+ 07_RMLPositionSampleApplication Folder for the project file of 07_RMLPositionSampleApplication.cpp
		+ 08_RMLVelocitySampleApplication Folder for the project file of 08_RMLVelocitySampleApplication.cpp				
		+ TypeIIRML Folder for the project file of the Type II Reflexxes Motion Library

---------------------------------------------------------------
Copyright (C) 2015 Google, Inc.
