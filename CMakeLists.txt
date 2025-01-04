cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(WindowsKeys VERSION 0.0.1)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(WindowsKeys main.cpp)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Link libraries (if any)
# target_link_libraries(WindowsKeys <library_name>)

# Install targets
install(TARGETS WindowsKeys DESTINATION bin)
install(FILES ${PROJECT_SOURCE_DIR}/include/WindowsKeys.h DESTINATION include)

# Add tests (if any)
# enable_testing()
# add_test(NAME test1 COMMAND WindowsKeys)
