include(FetchContent)

FetchContent_Declare(
  QtIosCMake
  GIT_REPOSITORY https://github.com/OlivierLDff/QtIosCMake
  GIT_TAG        master
)

FetchContent_MakeAvailable(QtIosCMake)