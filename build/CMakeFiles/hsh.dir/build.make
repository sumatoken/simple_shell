# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xmta/Desktop/ALX/shell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xmta/Desktop/ALX/shell/build

# Include any dependencies generated for this target.
include CMakeFiles/hsh.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hsh.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hsh.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hsh.dir/flags.make

CMakeFiles/hsh.dir/helloWorld.c.o: CMakeFiles/hsh.dir/flags.make
CMakeFiles/hsh.dir/helloWorld.c.o: ../helloWorld.c
CMakeFiles/hsh.dir/helloWorld.c.o: CMakeFiles/hsh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xmta/Desktop/ALX/shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/hsh.dir/helloWorld.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/hsh.dir/helloWorld.c.o -MF CMakeFiles/hsh.dir/helloWorld.c.o.d -o CMakeFiles/hsh.dir/helloWorld.c.o -c /home/xmta/Desktop/ALX/shell/helloWorld.c

CMakeFiles/hsh.dir/helloWorld.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hsh.dir/helloWorld.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/xmta/Desktop/ALX/shell/helloWorld.c > CMakeFiles/hsh.dir/helloWorld.c.i

CMakeFiles/hsh.dir/helloWorld.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hsh.dir/helloWorld.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/xmta/Desktop/ALX/shell/helloWorld.c -o CMakeFiles/hsh.dir/helloWorld.c.s

# Object files for target hsh
hsh_OBJECTS = \
"CMakeFiles/hsh.dir/helloWorld.c.o"

# External object files for target hsh
hsh_EXTERNAL_OBJECTS =

hsh: CMakeFiles/hsh.dir/helloWorld.c.o
hsh: CMakeFiles/hsh.dir/build.make
hsh: CMakeFiles/hsh.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xmta/Desktop/ALX/shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable hsh"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hsh.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hsh.dir/build: hsh
.PHONY : CMakeFiles/hsh.dir/build

CMakeFiles/hsh.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hsh.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hsh.dir/clean

CMakeFiles/hsh.dir/depend:
	cd /home/xmta/Desktop/ALX/shell/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xmta/Desktop/ALX/shell /home/xmta/Desktop/ALX/shell /home/xmta/Desktop/ALX/shell/build /home/xmta/Desktop/ALX/shell/build /home/xmta/Desktop/ALX/shell/build/CMakeFiles/hsh.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hsh.dir/depend

