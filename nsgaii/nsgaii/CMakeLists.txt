# CMakeList.txt : CMake project for nsgaii, include source and define
# project specific logic here.
#

# Add the source files
file(GLOB SOURCES "*.cpp")

# Create the executable
add_executable(nsgaii ${SOURCES})

# Add source to this project's executable.
#add_executable (nsgaii "main.cpp" "nsgaii.cpp" "comparator.cpp" "crossover.cpp" 
#"gnuplot_interface.cpp" "individual.cpp" "intilization.cpp"  "log.cpp" "mutation.cpp" 
#"problem_DTLZ.cpp" "math_aux.cpp" "nondominated_sort.cpp" "survivor_selection.cpp"  "crowding_distance.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET nsgaii PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
