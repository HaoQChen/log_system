# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/night_fury/aplications/cmake-3.6.0-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/night_fury/aplications/cmake-3.6.0-Linux-x86_64/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/night_fury/Documents/Qt_project/robot_system/log_system

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/night_fury/Documents/Qt_project/robot_system/log_system/build

# Include any dependencies generated for this target.
include CMakeFiles/log_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/log_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/log_test.dir/flags.make

CMakeFiles/log_test.dir/test.cpp.o: CMakeFiles/log_test.dir/flags.make
CMakeFiles/log_test.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/night_fury/Documents/Qt_project/robot_system/log_system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/log_test.dir/test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log_test.dir/test.cpp.o -c /home/night_fury/Documents/Qt_project/robot_system/log_system/test.cpp

CMakeFiles/log_test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log_test.dir/test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/night_fury/Documents/Qt_project/robot_system/log_system/test.cpp > CMakeFiles/log_test.dir/test.cpp.i

CMakeFiles/log_test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log_test.dir/test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/night_fury/Documents/Qt_project/robot_system/log_system/test.cpp -o CMakeFiles/log_test.dir/test.cpp.s

CMakeFiles/log_test.dir/test.cpp.o.requires:

.PHONY : CMakeFiles/log_test.dir/test.cpp.o.requires

CMakeFiles/log_test.dir/test.cpp.o.provides: CMakeFiles/log_test.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/log_test.dir/build.make CMakeFiles/log_test.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/log_test.dir/test.cpp.o.provides

CMakeFiles/log_test.dir/test.cpp.o.provides.build: CMakeFiles/log_test.dir/test.cpp.o


# Object files for target log_test
log_test_OBJECTS = \
"CMakeFiles/log_test.dir/test.cpp.o"

# External object files for target log_test
log_test_EXTERNAL_OBJECTS =

log_test: CMakeFiles/log_test.dir/test.cpp.o
log_test: CMakeFiles/log_test.dir/build.make
log_test: liblog_system.a
log_test: dlib_build/libdlib.a
log_test: /usr/lib/x86_64-linux-gnu/libnsl.so
log_test: /usr/lib/x86_64-linux-gnu/libSM.so
log_test: /usr/lib/x86_64-linux-gnu/libICE.so
log_test: /usr/lib/x86_64-linux-gnu/libX11.so
log_test: /usr/lib/x86_64-linux-gnu/libXext.so
log_test: /usr/lib/x86_64-linux-gnu/libpng.so
log_test: /usr/lib/x86_64-linux-gnu/libz.so
log_test: /usr/lib/x86_64-linux-gnu/libjpeg.so
log_test: /usr/lib/libatlas.so
log_test: /usr/lib/libcblas.so
log_test: /usr/lib/liblapack.so
log_test: /usr/lib/x86_64-linux-gnu/libsqlite3.so
log_test: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.8
log_test: /usr/lib/x86_64-linux-gnu/libopencv_ts.so.2.4.8
log_test: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.8
log_test: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.8
log_test: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.8
log_test: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.8
log_test: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
log_test: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
log_test: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.8
log_test: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
log_test: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
log_test: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
log_test: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
log_test: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
log_test: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
log_test: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
log_test: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
log_test: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
log_test: CMakeFiles/log_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/night_fury/Documents/Qt_project/robot_system/log_system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable log_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/log_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/log_test.dir/build: log_test

.PHONY : CMakeFiles/log_test.dir/build

CMakeFiles/log_test.dir/requires: CMakeFiles/log_test.dir/test.cpp.o.requires

.PHONY : CMakeFiles/log_test.dir/requires

CMakeFiles/log_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/log_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/log_test.dir/clean

CMakeFiles/log_test.dir/depend:
	cd /home/night_fury/Documents/Qt_project/robot_system/log_system/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/night_fury/Documents/Qt_project/robot_system/log_system /home/night_fury/Documents/Qt_project/robot_system/log_system /home/night_fury/Documents/Qt_project/robot_system/log_system/build /home/night_fury/Documents/Qt_project/robot_system/log_system/build /home/night_fury/Documents/Qt_project/robot_system/log_system/build/CMakeFiles/log_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/log_test.dir/depend

