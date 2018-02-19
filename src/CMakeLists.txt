# in SOURCE
# path of headers
include_directories(${PROJECT_SOURCE_DIR}/include/clrprint)
# include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(clrprint main.cpp)
add_library(palette palette.cpp)
target_link_libraries(clrprint palette)
