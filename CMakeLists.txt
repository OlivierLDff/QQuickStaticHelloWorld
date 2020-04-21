
cmake_minimum_required(VERSION 3.14)

project(QQuickStaticHelloWorld LANGUAGES CXX)

# Find all required package, if some is missing it will result in error in target_link_libraries
find_package(Qt5Core            CONFIG REQUIRED NO_CMAKE_SYSTEM_PATH)
find_package(Qt5Gui             CONFIG REQUIRED NO_CMAKE_SYSTEM_PATH)
find_package(Qt5Qml             CONFIG REQUIRED NO_CMAKE_SYSTEM_PATH)
find_package(Qt5QmlWorkerScript CONFIG NO_CMAKE_SYSTEM_PATH)
find_package(Qt5Quick           CONFIG REQUIRED NO_CMAKE_SYSTEM_PATH)
find_package(Qt5QuickControls2  CONFIG REQUIRED NO_CMAKE_SYSTEM_PATH)
find_package(Qt5Svg             CONFIG REQUIRED NO_CMAKE_SYSTEM_PATH)
find_package(Qt5Xml             CONFIG REQUIRED NO_CMAKE_SYSTEM_PATH)

add_executable(QQuickStaticHelloWorld src/main.cpp qml/qml.qrc)

# Require cmake 3.8 but way nicer than writing to global CMAKE_CXX_STANDARD
target_compile_features(QQuickStaticHelloWorld PUBLIC cxx_std_11)

# Better to use the target PROPERTIES and not global set(CMAKE_AUTOMOC ON)
# Otherwise if superbuild, moc will try to moc dependencies too.
set_target_properties(QQuickStaticHelloWorld PROPERTIES AUTORCC TRUE)
set_target_properties(QQuickStaticHelloWorld PROPERTIES AUTOMOC TRUE)

# target_link_libraries and not qt5_use_module because it is deprecated
target_link_libraries(QQuickStaticHelloWorld
  Qt5::Core
  Qt5::Gui
  Qt5::Svg
  Qt5::Xml
  Qt5::Qml
  Qt5::Quick
  Qt5::QuickControls2
)

# Only use static macro if linking with static qt
get_target_property(QT_TARGET_TYPE Qt5::Core TYPE)
if(${QT_TARGET_TYPE} STREQUAL "STATIC_LIBRARY")
  include(cmake/FetchQtStaticCMake.cmake)

  qt_generate_plugin_import(QQuickStaticHelloWorld VERBOSE)

  # EXTRA_PLUGIN are the one required by plugin loaded by qt_generate_plugin_import
  # It's not automatic yet :( All this workflow might change in future version of qt
  # with better and better cmake support
  qt_generate_qml_plugin_import(QQuickStaticHelloWorld
    QML_SRC ${CMAKE_CURRENT_SOURCE_DIR}/qml
    EXTRA_PLUGIN
      QtQuickVirtualKeyboardPlugin
      QtQuickVirtualKeyboardSettingsPlugin
      QtQuickVirtualKeyboardStylesPlugin
      QmlFolderListModelPlugin
      QQuickLayoutsPlugin
    VERBOSE
  )

endif()

# This target needs to be linked after qt_generate_qml_plugin_import call.
# This is hiding a bug somewhere ...
if(TARGET Qt5::QmlWorkerScript)
  target_link_libraries(QQuickStaticHelloWorld Qt5::QmlWorkerScript)
endif()