add_library(CKLogger Logger.cpp)

target_include_directories(
  CKLogger
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include # target linking to library must
         # include these
  PRIVATE ${log4cxx_SOURCE_DIR}/src/main/include
  PRIVATE ${log4cxx_BINARY_DIR}/src/main/include)

target_link_libraries(CKLogger PRIVATE log4cxx)
target_link_libraries(CKLogger PUBLIC global_compiler_flags)
if(APPLE)
  target_link_libraries(CKLogger PRIVATE aprutil-1 apr-1)
endif()
