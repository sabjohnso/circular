configure_file(config.hpp.in config.hpp)

add_library(circular_header INTERFACE)
set_target_properties(circular_header PROPERTIES EXPORT_NAME header)
target_include_directories(circular_header
  INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<INSTALL_INTERFACE:${circular_INSTALL_INCLUDEDIR}>)

add_library(circular::header ALIAS circular_header)
  
install(TARGETS circular_header
  EXPORT circular_EXPORTS
  RUNTIME DESTINATION ${circular_INSTALL_BINDIR}
  LIBRARY DESTINATION ${circular_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${circular_INSTALL_LIBDIR})

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  DESTINATION ${circular_INSTALL_INCLUDEDIR}/circular)
