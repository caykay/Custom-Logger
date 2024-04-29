# executable for testing
add_executable(Logger_exe main.cpp)
target_link_libraries(Logger_exe CKLogger)

option(COPY_CONFIGS OFF)
set(CONFIG_SOURCE_SUBDIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/config/)
set(CONFIG_BINARY_SUBDIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/config/)
if(${COPY_CONFIGS})
  add_custom_command(
    TARGET Logger_exe
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
            ${CONFIG_SOURCE_SUBDIRECTORY} ${CONFIG_BINARY_SUBDIRECTORY})
  # COMMENT "Copying files from ${SOURCE_SUBDIRECTORY} to
  # ${BINARY_SUBDIRECTORY}"
endif()
