cmake_minimum_required(VERSION 3.9)
project(trace_module)

set(CMAKE_CXX_STANDARD 11)

add_executable(trace_module
        src/module.cc
        src/module.h
        src/instrumentation_pass.cc
        src/instrumentation_pass.h
        src/codelib.cc
        src/codelib.h)

target_include_directories(trace_module PUBLIC
        /opt/artist-sdk/include/external/valgrind
        /opt/artist-sdk/include/external/valgrind/include
        /opt/artist-sdk/include/bionic/libc/private
        /opt/artist-sdk/include/art/runtime
        /opt/artist-sdk/include/art/compiler
        /opt/artist-sdk/include/art/compiler/optimizing
        /opt/artist-sdk/include/libnativehelper/include/nativehelper
        /opt/artist-sdk/include/external/libcxx/include
        /opt/artist-sdk/include/bionic/libc/arch-arm/include
        /opt/artist-sdk/include/bionic/libc/include
        /opt/artist-sdk/include/bionic/libc/kernel/uapi
        /opt/artist-sdk/include/bionic/libc/kernel/uapi/asm-arm
        /opt/artist-sdk/include/bionic/libm/include)
