cmake_minimum_required(VERSION 3.8)

project(qml_hello_world LANGUAGES CXX)

# Find all required package, if some is missing it will result in error in target_link_libraries
find_package(Qt5Core            CONFIG REQUIRED NO_CMAKE_SYSTEM_PATH)
find_package(Qt5Gui             CONFIG REQUIRED NO_CMAKE_SYSTEM_PATH)
find_package(Qt5Qml             CONFIG REQUIRED NO_CMAKE_SYSTEM_PATH)
find_package(Qt5QmlWorkerScript CONFIG REQUIRED NO_CMAKE_SYSTEM_PATH)
find_package(Qt5Quick           CONFIG REQUIRED NO_CMAKE_SYSTEM_PATH)
find_package(Qt5QuickControls2  CONFIG REQUIRED NO_CMAKE_SYSTEM_PATH)
find_package(Qt5Svg             CONFIG REQUIRED NO_CMAKE_SYSTEM_PATH)
find_package(Qt5Xml             CONFIG REQUIRED NO_CMAKE_SYSTEM_PATH)

add_executable(qml_hello_world main.cpp qml.qrc)

# Require cmake 3.8 but way nicer than writing to global CMAKE_CXX_STANDARD
target_compile_features(qml_hello_world PUBLIC cxx_std_11)

# Better to use the target PROPERTIES and not global set(CMAKE_AUTOMOC ON)
# Otherwise if superbuild, moc will try to moc dependencies too.
set_target_properties(qml_hello_world PROPERTIES AUTORCC TRUE)
set_target_properties(qml_hello_world PROPERTIES AUTOMOC TRUE)
# target_link_libraries and not qt5_use_module because it is deprecated
target_link_libraries(qml_hello_world
    Qt5::Core
    Qt5::Gui
    Qt5::Svg
    Qt5::Xml
    Qt5::Qml
    Qt5::QmlWorkerScript
    Qt5::Quick
    Qt5::QuickControls2)

include(QtStaticCMake.cmake)

qt_generate_plugin_import(qml_hello_world VERBOSE)

# EXTRA_PLUGIN are the one required by plugin loaded by qt_generate_plugin_import
# It's not automatic yet :( All this workflow might change in future version of qt
# with better and better cmake support
qt_generate_qml_plugin_import(qml_hello_world
    QML_SRC ${CMAKE_CURRENT_SOURCE_DIR}
    EXTRA_PLUGIN
      QtQuickVirtualKeyboardPlugin
      QtQuickVirtualKeyboardSettingsPlugin
      QtQuickVirtualKeyboardStylesPlugin
      QmlFolderListModelPlugin
      QQuickLayoutsPlugin
    VERBOSE
    )