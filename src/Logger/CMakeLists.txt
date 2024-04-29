set(LIBRARY_NAME CKLogger)

get_filename_component(EXCEPTIONS_DIR ../Exceptions ABSOLUTE)
message(STATUS ${EXCEPTIONS_DIR})

file(GLOB CKLogger_SRC "*.cpp")
add_library(${LIBRARY_NAME} ${CKLogger_SRC})

target_include_directories(
  ${LIBRARY_NAME}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include # target linking to library must
         # include these
  PUBLIC ${EXCEPTIONS_DIR}/include
  PRIVATE ${log4cxx_SOURCE_DIR}/src/main/include
  PRIVATE ${log4cxx_BINARY_DIR}/src/main/include)

target_link_libraries(${LIBRARY_NAME} PRIVATE log4cxx)
target_link_libraries(${LIBRARY_NAME} PUBLIC global_compiler_flags)
if(APPLE)
  target_link_libraries(${LIBRARY_NAME} PRIVATE aprutil-1 apr-1)
endif()
