cmake_minimum_required(VERSION 3.6.0)


project(RMLTypeII VERSION 1.2.7 LANGUAGES CXX)


option(BUILD_EXAMPLES "Build example programs" ON)
option(BUILD_TESTS "Build test programs" ON)


set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_STANDARD 11)


file(GLOB ReflexxesTypeII_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "src/*.cpp"
)
add_library(ReflexxesTypeII SHARED ${ReflexxesTypeII_SRC})
target_include_directories(ReflexxesTypeII
  PUBLIC
    $<INSTALL_INTERFACE:include/RMLTypeII>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/RMLTypeII>
)

add_library(RMLTypeII::ReflexxesTypeII ALIAS ReflexxesTypeII)

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

  add_executable(generator-csv test/generator-csv.cpp)
  target_link_libraries(generator-csv ReflexxesTypeII)
endif()


## Install
include(GNUInstallDirs)
set(INSTALL_CMAKE_CONFIG_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/RMLTypeII)

install(TARGETS ReflexxesTypeII
  EXPORT RMLTypeIITargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(DIRECTORY include/RMLTypeII DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

export(EXPORT RMLTypeIITargets
  NAMESPACE RMLTypeII::
  FILE ${CMAKE_CURRENT_BINARY_DIR}/RMLTypeIITargets.cmake
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/RMLTypeIIConfigVersion.cmake
  COMPATIBILITY SameMajorVersion
)
configure_package_config_file(cmake/RMLTypeIIConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/RMLTypeIIConfig.cmake
  INSTALL_DESTINATION ${INSTALL_CMAKE_CONFIG_DIR}
)

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/RMLTypeIIConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/RMLTypeIIConfigVersion.cmake
  DESTINATION ${INSTALL_CMAKE_CONFIG_DIR}
)
install(EXPORT RMLTypeIITargets
  NAMESPACE RMLTypeII::
  DESTINATION ${INSTALL_CMAKE_CONFIG_DIR}
)
