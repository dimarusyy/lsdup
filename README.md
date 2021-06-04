#### Description
Write a cross-platform command-line application that receives a directory as parameter and outputs
the groups of files in the directory that are duplicate in terms of contents.
The application should:
• take into account that there might be a very large number of files in the directory
Copyright © 2004 - 2020 Nexthink. All rights reserved. 3• optimise for execution time.
The application should be called e.g.:
```
	$ ./lsdup /path/to/dir/
	[group #1]
	/path/to/dir/file1
	/path/to/dir/file3
	[group #2]
	/path/to/dir/file2
	/path/to/dir/file4
	/path/to/dir/file5
	...
	[group #n]
	/path/to/dir/filex
	/path/to/dir/filey
```
Please ensure proper unit test coverage for your application.

#### Dependencies
* C++17
* doctest for running tests
* boost-iostreams for cross-platform API to memory mapped files

#### Comments
* vcpkg is used to deal with package dependencies, first run may take long time
* smhasher is used for MurmurHashv3 calculation. 

#### Notes
* I'm using 0L as a seed options when calculating MurmurHash. This option could be considered unsafe.