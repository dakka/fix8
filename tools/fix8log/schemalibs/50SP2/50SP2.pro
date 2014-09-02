######################################################################
# Automatically generated by qmake (3.0) Thu Aug 7 14:43:58 2014
######################################################################

TEMPLATE = lib
TARGET = 50SP2

unix {
message("Unix Compile.")
QMAKE_CXXFLAGS += -Wno-missing-field-initializers -Wno-ignored-qualifiers -Wno-missing-field-initializers -Wno-uninitialized -Wno-unused-variable -Wno-unused-parameter -std=c++11
INCLUDEPATH += .  /usr/local/include/fix8
LIBS += -lz -L/usr/local/lib  -lrt -lfix8 -ltbb  -lPocoFoundation -lPocoNet -lPocoUtil
}
win32 {
     message("Windows Compile")
    CONFIG += console
    QMAKE_CXXFLAGS += /bigobj -D WIN32_LEAN_AND_MEAN
    INCLUDEPATH += . \
                ../../../../msvc/packages/fix8.dev.1.3.20140831.1/build/native/include \
                ../../../../msvc/packages/fix8.dependencies.getopt.1.0.20140509.1/build/native/include/fix8 \
                ../../../../msvc/packages/fix8.dependencies.openssl.1.0.20140509.1/build/native/include/x64/v120/Release/Desktop \
                ../../../../msvc/packages/fix8.dependencies.poco.1.5.20140509.1/build/native/include \
                ../../../../msvc/packages/fix8.dependencies.tbb.4.2.20140416.1/build/native/include

release {
 message("Release")
   LIBS +=  rpcrt4.lib \
        ../../../../msvc/packages/fix8.dev.1.3.20140831.1/build/native/lib/x64/v120/Release/Desktop/fix8.lib \
        ../../../../msvc/packages/fix8.dependencies.tbb.4.2.20140416.1/build/native/lib/x64/v120/Release/Desktop/tbb.lib \
        ../../../../msvc/packages/fix8.dependencies.tbb.4.2.20140416.1/build/native/lib/x64/v120/Release/Desktop/tbbmalloc_proxy.lib \
        ../../../../msvc/packages/fix8.dependencies.tbb.4.2.20140416.1/build/native/lib/x64/v120/Release/Desktop/tbbmalloc.lib \
        ../../../../msvc/packages/fix8.dependencies.poco.1.5.20140509.1/build/native/lib/x64/v120/Release/Desktop/PocoFoundation.lib \
        ../../../../msvc/packages/fix8.dependencies.poco.1.5.20140509.1/build/native/lib/x64/v120/Release/Desktop/PocoNet.lib \
        ../../../../msvc/packages/fix8.dependencies.poco.1.5.20140509.1/build/native/lib/x64/v120/Release/Desktop/PocoNetSSL.lib \
        ../../../../msvc/packages/fix8.dependencies.poco.1.5.20140509.1/build/native/lib/x64/v120/Release/Desktop/PocoCrypto.lib \
        ../../../../msvc/packages/fix8.dependencies.poco.1.5.20140509.1/build/native/lib/x64/v120/Release/Desktop/PocoUtil.lib
}
}

# Input
HEADERS += Myfix_classes.hpp Myfix_router.hpp Myfix_types.hpp
SOURCES += Myfix_classes.cpp Myfix_traits.cpp Myfix_types.cpp
