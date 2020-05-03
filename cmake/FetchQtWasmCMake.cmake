include(FetchContent)

FetchContent_Declare(
  QtWasmCMake
  GIT_REPOSITORY https://github.com/OlivierLDff/QtWasmCMake
  GIT_TAG        master
)

FetchContent_MakeAvailable(QtWasmCMake)