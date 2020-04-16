cmake_minimum_required(VERSION 3.5)

project(qml_hello_world LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
SET(QT_USE_QTPLUGIN TRUE)
set(CMAKE_AUTOSTATICPLUGINS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Core Quick QuickControls2 Qml REQUIRED)
#include(QtStaticCMake.cmake)

if(ANDROID)
    add_library(qml_hello_world SHARED
      main.cpp
      qml.qrc
    )
else()
    add_executable(qml_hello_world
      main.cpp
      qml.qrc
    )
endif()

target_compile_definitions(qml_hello_world
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
#target_link_libraries(qml_hello_world
#  PRIVATE Qt5::Core Qt5::Quick Qt5::QuickControls2 Qt5::Qml)
qt5_use_modules(${PROJECT_NAME}
    Core
    Gui
    Qml
    Quick
    QuickControls2
    Concurrent
    Widgets
    )

#qt_generate_plugin_import(${PROJECT_NAME}
##  OUTPUT "example_plugin_import.cpp"
##  OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}
#  VERBOSE)

#qt_generate_qml_plugin_import(${PROJECT_NAME}
##  QML_DIR "/path/to/qtsdk"
#  QML_SRC ${CMAKE_SOURCE_DIR}
##  OUTPUT "example_qml_plugin_import.cpp"
##  OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}
#  VERBOSE)

get_target_property(gui_static_plugins Qt5::Gui STATIC_PLUGINS)
if(gui_static_plugins)
    string(REGEX REPLACE [;]*QVirtualKeyboardPlugin[;]* ";" gui_static_plugins_new "${gui_static_plugins}")
    set_target_properties(Qt5::Gui PROPERTIES STATIC_PLUGINS "${gui_static_plugins_new}")
endif()

qt5_import_plugins(${PROJECT_NAME}
    INCLUDE
    qtquick2plugin
    Qt5::QtQuickControls2Plugin
    Qt5::QtQuick2Plugin
    Qt5::QtQuickLayoutsPlugin
    Qt5::QtQuickTemplates2Plugin
    Qt5::QtQuickWindowPlugin
    Qt5::QtQuick2WindowPlugin
    Qt5::QWindowsIntegrationPlugin

)

