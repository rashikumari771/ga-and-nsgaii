# CMakeList.txt : CMake project for nsgaii, include source and define
# project specific logic here.
#

# Add the source files
file(GLOB SOURCES "*.cpp")

# Create the executable
add_executable(ga ${SOURCES})



if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ga PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
