# QQuickStaticHelloWorld

Minimal working cmake application that can be compiled with a static Qt library.

## 🚀 Build and run

```bash
git clone https://github.com/OlivierLDff/QQuickStaticHelloWorld
cd QQuickStaticHelloWorld
mkdir build && cd build
cmake -DCMAKE_PREFIX_PATH=/path/to/qt-static ..
cmake --build . --config Release
./QQuickStaticHelloWorld
```

### 🍎 iOs

To compile for iOs you need to be on a mac with latest version of XCode.

```bash
git clone https://github.com/OlivierLDff/QQuickStaticHelloWorld
cd QQuickStaticHelloWorld && mkdir build && cd build
git clone https://github.com/OlivierLDff/IosCMakeToolchain
cmake -DCMAKE_PREFIX_PATH=/Path/To/Qt/5.12.3/ios \
-DDEPLOYMENT_TARGET=12.0 \
-DCMAKE_TOOLCHAIN_FILE=./IosCMakeToolchain/ios.toolchain.cmake \
-DPLATFORM=OS64 \
-G "Xcode" \
-DENABLE_BITCODE=FALSE \
-DENABLE_VISIBILITY=TRUE \
-DCMAKE_OSX_SYSROOT=/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS12.2.sdk/ \
..
```

An xcode project is then available inside `build/`. You can then start it on real iPhone/iPad or in emulator.

### 📱Android

*todo*.

### 🌍 WebAssembly

This project can be build with [Qt for WebAssembly](https://doc.qt.io/qt-5/wasm.html) and is available [here](https://olivierldff.github.io/QQuickStaticHelloWorld/). 

To build this application i use a [Docker Image](https://hub.docker.com/r/reivilo1234/qt-webassembly-cmake).

```bash
git clone https://github.com/OlivierLDff/QQuickStaticHelloWorld
cd QQuickStaticHelloWorld
docker run -it --rm -v $(pwd):/src/ -u $(id -u):$(id -g) reivilo1234/qt-webassembly-cmake:qt5.15-em1.39.10 bash
mkdir build && cd build
cmake ..
make -j
exit
```

This generate couple of file:

|       Generated file        |     Brief Description      |
| :-------------------------: | :------------------------: |
| QQuickStaticHelloWorld.html |       HTML container       |
|         qtloader.js         | JS API for loading Qt apps |
|  QQuickStaticHelloWorld.js  | JS API for loading Qt apps |
| QQuickStaticHelloWorld.wasm |   emscripten app binary    |

Then simply start a web server

```bash
mv QQuickStaticHelloWorld.html index.html
python -m SimpleHTTPServer
```

Simply time `localhost:8000` in your web brower.