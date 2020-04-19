# QQuickStaticHelloWorld

Demonstrate the use of `QtStaticCMake.cmake` script to compile with a static qt version a qt quick application. This CMake project demonstrate how to link to static plugin.

## Build and run

```bash
git clone https://github.com/OlivierLDff/QQuickStaticHelloWorld
cd QQuickStaticHelloWorld
mkdir build && cd build
cmake -DCMAKE_PREFIX_PATH=/path/to/qt-static ..
cmake --build . --config Release
./QQuickStaticHelloWorld
```

## Overview

The main issue when linking to a static version of qt is to get all the plugin at execution time. For that qt provide a `Q_IMPORT_PLUGIN` macro that force the linking of a plugin.

**Qt 5.14** a new `qt5_import_plugin` macro, and by itself provide some `.cpp` file with the `Q_IMPORT_PLUGIN` for some plugin such as Svg.

But qt isn't providing linking to qml plugin (library found in `qml/` folder). This project show how to import plugin by scanning your qml files and using the `qt_generate_qml_plugin_import` function from [QtStaticCMake](https://github.com/OlivierLDff/QtStaticCMake) project.

This project will require update for Qt 5.15 and Qt 6 since lot of stuff are going to move and change. Only use this project with Qt 5.14 or lower for now.

Feel free to improve, comment, etc.