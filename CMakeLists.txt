cmake_minimum_required(VERSION 3.26)

# set the project name and version
project(CKLogging VERSION 1.0)
# generates the "compile_commands.json" file used by clangd to locate c++ files
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# interface library for the compiler flags
add_library(global_compiler_flags INTERFACE)
# Add compiler feature cxx_std_11 to tutorial_compiler_flags Hint: Use
target_compile_features(global_compiler_flags INTERFACE cxx_std_17)

add_subdirectory(dependencies)
add_subdirectory(src)
