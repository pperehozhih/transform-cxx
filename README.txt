-----------------
  Transform SWF
-----------------
The Transform SWF framework is a collection of classes for each of the data 
structures and tags that make up the Flash File Format Specification from 
Macromedia. The classes provide a completely object-oriented API to encode and
decode Flash (.swf) files. Transform SWF supports Flash MX 2004 (Flash 7).

The documentation that accompanied this release contains a description of the 
each of the classes along with examples on how they may be used to decode, 
process and encode Flash (.swf) files. Flagstone Software's web site, 
www.flagstonesoftware.com also contains more detailed information and advanced
examples.

-------------
  Licensing
-------------
Transform SWF is made available under the terms of the Berkeley Software 
Distribution (BSD) license. This allow you complete freedom to use and 
distribute the code in source and/or binary form as long as you respect the 
original copyright. Please see the LICENSE.txt file for exact terms.

----------------
  Requirements
----------------
To compile and use the classes in Transform SWF you must have:

    zlib 1.1 or higher.

1. zlib
Transform SWF (and Flash) uses the zlib compression library to compress and
expand encoded files (from Flash Version 6 onwards). On Unix and Mac OS X you
should have zlib already installed. For Windows there are compiled versions of
the library available for Visual Studio from the Flagstone web site, 
http://www.flagstonesoftware.com/downloads/index.html#zlib. You can also obtain
the source for the latest distribution from http://www.zlib.net/

-------------------------
  Compiling Using CMake
-------------------------
CMake is a cross-platform tool which can be used to build makefiles (Borland, 
NMake or Unix) or Visual Studio project files to compile a project. The latest
release can be found at http://www.cmake.org

To generate the files used to build the transform library run the CMakeSetup
application:

1. Select the directory where the CMakeLists.txt file is located as the 
location of the source code - the files are specified relative to this file.

2. Select the directory where the files used to compile the library will be 
generated. The directory will be created if it does not exist.

3. Click the configure button twice to identify the installed compiler and 
other environment variables.

4. Click the ok button to generate the project files.

5. Build the Transform library, with the toolset you selecting, using the 
generated project files.

CMake will try to find the location of zlib automatically by searching your
PATH for the directories containing the header and library files. For WIN32
systems you should set the path to the zlib files explicity, by editing lines
296-299:

IF(WIN32)
	SET(CMAKE_INCLUDE_PATH C:/MinGW/include ${CMAKE_INCLUDE_PATH})
	SET(CMAKE_LIBRARY_PATH C:/MinGW/lib ${CMAKE_LIBRARY_PATH})
ENDIF(WIN32)

By Default the CMake file only builds a shared library. If you want to build 
a static library then uncomment lines 309-312.


--------------------------
  Additional Information
--------------------------

For Further Information please contact:

Stuart MacKay
Flagstone Software Ltd.
92 High Street
Wick, Caithness KW1 4LY
Scotland

www.flagstonesoftware.com
