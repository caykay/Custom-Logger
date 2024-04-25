FetchContent_Declare(
  log4cxx_target
  GIT_REPOSITORY "https://github.com/apache/logging-log4cxx.git"
  GIT_TAG v1.1.0-RC2
  FIND_PACKAGE_ARGS NAMES log4cxx # fetchcontent uses find_package to see if
                                  # package alr
  # exists before downloading
)

message(STATUS "Fetching log4cxx...")
# log4cxx cmake options
set(BUILD_TESTING OFF)
set(LOG4CXX_QT_SUPPORT OFF)

FetchContent_MakeAvailable(log4cxx_target)
