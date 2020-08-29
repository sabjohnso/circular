cmake_minimum_required(VERSION 3.12)

project(circular VERSION 0.1.0 LANGUAGES C CXX)

option(circular_BUILD_TESTING "Build the circular tests" ON)

include(GNUInstallDirs)
set(circular_INSTALL_BINDIR ${CMAKE_INSTALL_BINDIR})
set(circular_INSTALL_LIBDIR ${CMAKE_INSTALL_LIBDIR})
set(circular_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_INCLUDEDIR})
set(circular_INSTALL_CONFDIR ${circular_INSTALL_LIBDIR}/cmake/circular-${PROJECT_VERSION})

list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake)
include(circular_deps)

add_subdirectory(circular)

if(circular_BUILD_TESTING)
  include(CTest)
  if(BUILD_TESTING)
    add_subdirectory(circular_testing)
  endif()
endif()

install(EXPORT circular_EXPORTS
  NAMESPACE circular::
  FILE circular-exports.cmake
  DESTINATION ${circular_INSTALL_CONFDIR})

configure_file(circular-config.cmake.in circular-config.cmake)
install(FILES ${PROJECT_BINARY_DIR}/circular-config.cmake
  DESTINATION ${circular_INSTALL_CONFDIR})








