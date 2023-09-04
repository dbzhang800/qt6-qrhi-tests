## About QRhi

QRhi(The Qt Rendering Hardware Interface) is an abstraction for hardware accelerated graphics APIs, such as, OpenGL, OpenGL ES, Direct3D, Metal, and Vulkan.

* In Qt 6.5 or older version, the RHI (Rendering Hardware Interface) API is private.
* In Qt 6.6, the RHI API is semi-public.
* In Qt 6.7, the QRhiWidget class is introduced.

Please note that the code in this repository is based on the specific branches and versions mentioned above.

Documents can be found in:

* https://doc-snapshots.qt.io/qt6-6.6/qrhi.html
* https://doc-snapshots.qt.io/qt6-dev/qrhi.html

### rhi tests

Examples in this repository are copied from the 6.5 branch of qtbase in the qtbase/tests/manual/rhi directory.

### Build

To build and run the code in this repository, please follow the steps below:

0. Install Qt 6.5
1. Install the Vulkan SDK, which can be found at https://www.lunarg.com/vulkan-sdk/.
2. Open the toplevel CMakeLists.txt in QtCreator
3. Click build button



### Shader?

In these tests, shader files .comp/.vert/.frag have been compile to .qsb files already.

You can regenerate them through the batch file buildshaders.bat.

Step1: set proper environment
```
C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat" -arch=amd64
D:\Qt\Online\6.5.0\msvc2019_64\bin\qtenv2.bat
```

Step2: run the batch file
```
buildshaders.bat
```
