# in SOURCE

# --path of self-defined headers--
include_directories(${PROJECT_SOURCE_DIR}/include/clrprint)
add_executable(clrprint main.cpp)
add_library(palette palette.cpp)
target_link_libraries(clrprint palette)

# --global installed libs--
# check if boost is installed
find_package(Boost 1.66.0 REQUIRED COMPONENTS program_options)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  # add_executable(clrprint main.cpp)
  # target_link_libraries(clrprint ${Boost_LIBRARIES} palette)
  target_link_libraries(clrprint ${Boost_LIBRARIES})
endif()
