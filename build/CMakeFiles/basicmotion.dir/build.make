# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jess-linux/Documents/Projects/BasicMotion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jess-linux/Documents/Projects/BasicMotion/build

# Include any dependencies generated for this target.
include CMakeFiles/basicmotion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/basicmotion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/basicmotion.dir/flags.make

src/moc_BasicMotion.cpp: ../src/BasicMotion.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/jess-linux/Documents/Projects/BasicMotion/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating src/moc_BasicMotion.cpp"
	cd /home/jess-linux/Documents/Projects/BasicMotion/build/src && /usr/lib/x86_64-linux-gnu/qt5/bin/moc @/home/jess-linux/Documents/Projects/BasicMotion/build/src/moc_BasicMotion.cpp_parameters

src/moc_workerThread.cpp: ../src/workerThread.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/jess-linux/Documents/Projects/BasicMotion/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating src/moc_workerThread.cpp"
	cd /home/jess-linux/Documents/Projects/BasicMotion/build/src && /usr/lib/x86_64-linux-gnu/qt5/bin/moc @/home/jess-linux/Documents/Projects/BasicMotion/build/src/moc_workerThread.cpp_parameters

src/moc_jscontroller.cpp: ../src/jscontroller.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/jess-linux/Documents/Projects/BasicMotion/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating src/moc_jscontroller.cpp"
	cd /home/jess-linux/Documents/Projects/BasicMotion/build/src && /usr/lib/x86_64-linux-gnu/qt5/bin/moc @/home/jess-linux/Documents/Projects/BasicMotion/build/src/moc_jscontroller.cpp_parameters

CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.o: CMakeFiles/basicmotion.dir/flags.make
CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.o: src/moc_BasicMotion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jess-linux/Documents/Projects/BasicMotion/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.o -c /home/jess-linux/Documents/Projects/BasicMotion/build/src/moc_BasicMotion.cpp

CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jess-linux/Documents/Projects/BasicMotion/build/src/moc_BasicMotion.cpp > CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.i

CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jess-linux/Documents/Projects/BasicMotion/build/src/moc_BasicMotion.cpp -o CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.s

CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.o.requires:

.PHONY : CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.o.requires

CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.o.provides: CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.o.requires
	$(MAKE) -f CMakeFiles/basicmotion.dir/build.make CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.o.provides.build
.PHONY : CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.o.provides

CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.o.provides.build: CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.o


CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.o: CMakeFiles/basicmotion.dir/flags.make
CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.o: src/moc_workerThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jess-linux/Documents/Projects/BasicMotion/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.o -c /home/jess-linux/Documents/Projects/BasicMotion/build/src/moc_workerThread.cpp

CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jess-linux/Documents/Projects/BasicMotion/build/src/moc_workerThread.cpp > CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.i

CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jess-linux/Documents/Projects/BasicMotion/build/src/moc_workerThread.cpp -o CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.s

CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.o.requires:

.PHONY : CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.o.requires

CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.o.provides: CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.o.requires
	$(MAKE) -f CMakeFiles/basicmotion.dir/build.make CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.o.provides.build
.PHONY : CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.o.provides

CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.o.provides.build: CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.o


CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.o: CMakeFiles/basicmotion.dir/flags.make
CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.o: src/moc_jscontroller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jess-linux/Documents/Projects/BasicMotion/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.o -c /home/jess-linux/Documents/Projects/BasicMotion/build/src/moc_jscontroller.cpp

CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jess-linux/Documents/Projects/BasicMotion/build/src/moc_jscontroller.cpp > CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.i

CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jess-linux/Documents/Projects/BasicMotion/build/src/moc_jscontroller.cpp -o CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.s

CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.o.requires:

.PHONY : CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.o.requires

CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.o.provides: CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.o.requires
	$(MAKE) -f CMakeFiles/basicmotion.dir/build.make CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.o.provides.build
.PHONY : CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.o.provides

CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.o.provides.build: CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.o


CMakeFiles/basicmotion.dir/src/main.cpp.o: CMakeFiles/basicmotion.dir/flags.make
CMakeFiles/basicmotion.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jess-linux/Documents/Projects/BasicMotion/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/basicmotion.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basicmotion.dir/src/main.cpp.o -c /home/jess-linux/Documents/Projects/BasicMotion/src/main.cpp

CMakeFiles/basicmotion.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basicmotion.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jess-linux/Documents/Projects/BasicMotion/src/main.cpp > CMakeFiles/basicmotion.dir/src/main.cpp.i

CMakeFiles/basicmotion.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basicmotion.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jess-linux/Documents/Projects/BasicMotion/src/main.cpp -o CMakeFiles/basicmotion.dir/src/main.cpp.s

CMakeFiles/basicmotion.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/basicmotion.dir/src/main.cpp.o.requires

CMakeFiles/basicmotion.dir/src/main.cpp.o.provides: CMakeFiles/basicmotion.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/basicmotion.dir/build.make CMakeFiles/basicmotion.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/basicmotion.dir/src/main.cpp.o.provides

CMakeFiles/basicmotion.dir/src/main.cpp.o.provides.build: CMakeFiles/basicmotion.dir/src/main.cpp.o


CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.o: CMakeFiles/basicmotion.dir/flags.make
CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.o: ../src/BasicMotion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jess-linux/Documents/Projects/BasicMotion/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.o -c /home/jess-linux/Documents/Projects/BasicMotion/src/BasicMotion.cpp

CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jess-linux/Documents/Projects/BasicMotion/src/BasicMotion.cpp > CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.i

CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jess-linux/Documents/Projects/BasicMotion/src/BasicMotion.cpp -o CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.s

CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.o.requires:

.PHONY : CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.o.requires

CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.o.provides: CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.o.requires
	$(MAKE) -f CMakeFiles/basicmotion.dir/build.make CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.o.provides.build
.PHONY : CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.o.provides

CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.o.provides.build: CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.o


CMakeFiles/basicmotion.dir/src/workerThread.cpp.o: CMakeFiles/basicmotion.dir/flags.make
CMakeFiles/basicmotion.dir/src/workerThread.cpp.o: ../src/workerThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jess-linux/Documents/Projects/BasicMotion/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/basicmotion.dir/src/workerThread.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basicmotion.dir/src/workerThread.cpp.o -c /home/jess-linux/Documents/Projects/BasicMotion/src/workerThread.cpp

CMakeFiles/basicmotion.dir/src/workerThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basicmotion.dir/src/workerThread.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jess-linux/Documents/Projects/BasicMotion/src/workerThread.cpp > CMakeFiles/basicmotion.dir/src/workerThread.cpp.i

CMakeFiles/basicmotion.dir/src/workerThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basicmotion.dir/src/workerThread.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jess-linux/Documents/Projects/BasicMotion/src/workerThread.cpp -o CMakeFiles/basicmotion.dir/src/workerThread.cpp.s

CMakeFiles/basicmotion.dir/src/workerThread.cpp.o.requires:

.PHONY : CMakeFiles/basicmotion.dir/src/workerThread.cpp.o.requires

CMakeFiles/basicmotion.dir/src/workerThread.cpp.o.provides: CMakeFiles/basicmotion.dir/src/workerThread.cpp.o.requires
	$(MAKE) -f CMakeFiles/basicmotion.dir/build.make CMakeFiles/basicmotion.dir/src/workerThread.cpp.o.provides.build
.PHONY : CMakeFiles/basicmotion.dir/src/workerThread.cpp.o.provides

CMakeFiles/basicmotion.dir/src/workerThread.cpp.o.provides.build: CMakeFiles/basicmotion.dir/src/workerThread.cpp.o


CMakeFiles/basicmotion.dir/src/jscontroller.cpp.o: CMakeFiles/basicmotion.dir/flags.make
CMakeFiles/basicmotion.dir/src/jscontroller.cpp.o: ../src/jscontroller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jess-linux/Documents/Projects/BasicMotion/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/basicmotion.dir/src/jscontroller.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basicmotion.dir/src/jscontroller.cpp.o -c /home/jess-linux/Documents/Projects/BasicMotion/src/jscontroller.cpp

CMakeFiles/basicmotion.dir/src/jscontroller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basicmotion.dir/src/jscontroller.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jess-linux/Documents/Projects/BasicMotion/src/jscontroller.cpp > CMakeFiles/basicmotion.dir/src/jscontroller.cpp.i

CMakeFiles/basicmotion.dir/src/jscontroller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basicmotion.dir/src/jscontroller.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jess-linux/Documents/Projects/BasicMotion/src/jscontroller.cpp -o CMakeFiles/basicmotion.dir/src/jscontroller.cpp.s

CMakeFiles/basicmotion.dir/src/jscontroller.cpp.o.requires:

.PHONY : CMakeFiles/basicmotion.dir/src/jscontroller.cpp.o.requires

CMakeFiles/basicmotion.dir/src/jscontroller.cpp.o.provides: CMakeFiles/basicmotion.dir/src/jscontroller.cpp.o.requires
	$(MAKE) -f CMakeFiles/basicmotion.dir/build.make CMakeFiles/basicmotion.dir/src/jscontroller.cpp.o.provides.build
.PHONY : CMakeFiles/basicmotion.dir/src/jscontroller.cpp.o.provides

CMakeFiles/basicmotion.dir/src/jscontroller.cpp.o.provides.build: CMakeFiles/basicmotion.dir/src/jscontroller.cpp.o


# Object files for target basicmotion
basicmotion_OBJECTS = \
"CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.o" \
"CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.o" \
"CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.o" \
"CMakeFiles/basicmotion.dir/src/main.cpp.o" \
"CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.o" \
"CMakeFiles/basicmotion.dir/src/workerThread.cpp.o" \
"CMakeFiles/basicmotion.dir/src/jscontroller.cpp.o"

# External object files for target basicmotion
basicmotion_EXTERNAL_OBJECTS =

../bin/basicmotion: CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.o
../bin/basicmotion: CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.o
../bin/basicmotion: CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.o
../bin/basicmotion: CMakeFiles/basicmotion.dir/src/main.cpp.o
../bin/basicmotion: CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.o
../bin/basicmotion: CMakeFiles/basicmotion.dir/src/workerThread.cpp.o
../bin/basicmotion: CMakeFiles/basicmotion.dir/src/jscontroller.cpp.o
../bin/basicmotion: CMakeFiles/basicmotion.dir/build.make
../bin/basicmotion: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.5.1
../bin/basicmotion: /usr/lib/x86_64-linux-gnu/libQt5SerialPort.so.5.5.1
../bin/basicmotion: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.5.1
../bin/basicmotion: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.5.1
../bin/basicmotion: CMakeFiles/basicmotion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jess-linux/Documents/Projects/BasicMotion/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable ../bin/basicmotion"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/basicmotion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/basicmotion.dir/build: ../bin/basicmotion

.PHONY : CMakeFiles/basicmotion.dir/build

CMakeFiles/basicmotion.dir/requires: CMakeFiles/basicmotion.dir/src/moc_BasicMotion.cpp.o.requires
CMakeFiles/basicmotion.dir/requires: CMakeFiles/basicmotion.dir/src/moc_workerThread.cpp.o.requires
CMakeFiles/basicmotion.dir/requires: CMakeFiles/basicmotion.dir/src/moc_jscontroller.cpp.o.requires
CMakeFiles/basicmotion.dir/requires: CMakeFiles/basicmotion.dir/src/main.cpp.o.requires
CMakeFiles/basicmotion.dir/requires: CMakeFiles/basicmotion.dir/src/BasicMotion.cpp.o.requires
CMakeFiles/basicmotion.dir/requires: CMakeFiles/basicmotion.dir/src/workerThread.cpp.o.requires
CMakeFiles/basicmotion.dir/requires: CMakeFiles/basicmotion.dir/src/jscontroller.cpp.o.requires

.PHONY : CMakeFiles/basicmotion.dir/requires

CMakeFiles/basicmotion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/basicmotion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/basicmotion.dir/clean

CMakeFiles/basicmotion.dir/depend: src/moc_BasicMotion.cpp
CMakeFiles/basicmotion.dir/depend: src/moc_workerThread.cpp
CMakeFiles/basicmotion.dir/depend: src/moc_jscontroller.cpp
	cd /home/jess-linux/Documents/Projects/BasicMotion/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jess-linux/Documents/Projects/BasicMotion /home/jess-linux/Documents/Projects/BasicMotion /home/jess-linux/Documents/Projects/BasicMotion/build /home/jess-linux/Documents/Projects/BasicMotion/build /home/jess-linux/Documents/Projects/BasicMotion/build/CMakeFiles/basicmotion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/basicmotion.dir/depend

