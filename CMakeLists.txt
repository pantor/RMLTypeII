cmake_minimum_required(VERSION 3.10.0)


project(RMLTypeII VERSION 1.2.7 LANGUAGES CXX)


option(BUILD_EXAMPLES "Build example programs" ON)
option(BUILD_TESTS "Build test programs" ON)


set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_STANDARD 11)


file(GLOB ReflexxesTypeII_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "src/*.cpp"
)
add_library(ReflexxesTypeII SHARED ${ReflexxesTypeII_SRC})
target_include_directories(ReflexxesTypeII PUBLIC include/RMLTypeII)


if(BUILD_EXAMPLES)
  foreach(example IN ITEMS
    01_RMLPositionSampleApplication
    02_RMLPositionSampleApplication
    03_RMLPositionSampleApplication
    04_RMLVelocitySampleApplication
    05_RMLVelocitySampleApplication
    06_RMLVelocitySampleApplication
    07_RMLPositionSampleApplication
    08_RMLVelocitySampleApplication
  )
    add_executable(${example} "examples/${example}.cpp")
    target_link_libraries(${example} ReflexxesTypeII)
  endforeach()
endif()


if(BUILD_TESTS)
  add_executable(trajectory-csv test/trajectory-csv.cpp)
  target_link_libraries(trajectory-csv ReflexxesTypeII)
endif()
