# detect the OS
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set(TGUI_OS_WINDOWS 1)

    # detect the architecture (note: this test won't work for cross-compilation)
    include(CheckTypeSize)
    check_type_size(void* SIZEOF_VOID_PTR)
    if(${SIZEOF_VOID_PTR} STREQUAL "4")
        set(ARCH_32BITS 1)
    elseif(${SIZEOF_VOID_PTR} STREQUAL "8")
        set(ARCH_64BITS 1)
    else()
        message(FATAL_ERROR "Unsupported architecture")
        return()
    endif()
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(TGUI_OS_UNIX 1)
    if(ANDROID)
        set(TGUI_OS_ANDROID 1)
    else()
        set(TGUI_OS_LINUX 1)
    endif()
elseif(CMAKE_SYSTEM_NAME MATCHES "^k?FreeBSD$")
    set(TGUI_OS_FREEBSD 1)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    if(IOS)
        set(TGUI_OS_IOS 1)
    else()
        set(TGUI_OS_MACOSX 1)

        # detect OS X version. (use '/usr/bin/sw_vers -productVersion' to extract V from '10.V.x'.)
        EXEC_PROGRAM(/usr/bin/sw_vers ARGS -productVersion OUTPUT_VARIABLE MACOSX_VERSION_RAW)
        STRING(REGEX REPLACE "10\\.([0-9]+).*" "\\1" MACOSX_VERSION "${MACOSX_VERSION_RAW}")
        if(${MACOSX_VERSION} LESS 7)
            message(FATAL_ERROR "Unsupported version of OS X: ${MACOSX_VERSION_RAW}")
            return()
        endif()
    endif()
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Android")
    set(TGUI_OS_ANDROID 1)
else()
    message(FATAL_ERROR "Unsupported operating system or environment")
    return()
endif()

# detect the compiler and its version
# Note: on some platforms (OS X), CMAKE_COMPILER_IS_GNUCXX is true
# even when CLANG is used, therefore the Clang test is done first
if(CMAKE_CXX_COMPILER MATCHES ".*clang[+][+]" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
   # CMAKE_CXX_COMPILER_ID is an internal CMake variable subject to change,
   # but there is no other way to detect CLang at the moment
   set(TGUI_COMPILER_CLANG 1)
   execute_process(COMMAND "${CMAKE_CXX_COMPILER}" "--version" OUTPUT_VARIABLE CLANG_VERSION_OUTPUT)
   string(REGEX REPLACE ".*clang version ([0-9]+\\.[0-9]+).*" "\\1" TGUI_CLANG_VERSION "${CLANG_VERSION_OUTPUT}")
elseif(CMAKE_COMPILER_IS_GNUCXX)
    set(TGUI_COMPILER_GCC 1)
    execute_process(COMMAND "${CMAKE_CXX_COMPILER}" "-dumpversion" OUTPUT_VARIABLE GCC_VERSION_OUTPUT)
    string(REGEX REPLACE "([0-9]+\\.[0-9]+).*" "\\1" TGUI_GCC_VERSION "${GCC_VERSION_OUTPUT}")
    execute_process(COMMAND "${CMAKE_CXX_COMPILER}" "--version" OUTPUT_VARIABLE GCC_COMPILER_VERSION)
    string(REGEX MATCHALL ".*(tdm[64]*-[1-9]).*" TGUI_COMPILER_GCC_TDM "${GCC_COMPILER_VERSION}")
    execute_process(COMMAND "${CMAKE_CXX_COMPILER}" "-dumpmachine" OUTPUT_VARIABLE GCC_MACHINE)
    string(STRIP "${GCC_MACHINE}" GCC_MACHINE)
    if(GCC_MACHINE MATCHES ".*w64.*")
        set(TGUI_COMPILER_GCC_W64 1)
    endif()
elseif(MSVC)
    set(TGUI_COMPILER_MSVC 1)
else()
    message(FATAL_ERROR "Unsupported compiler")
    return()
endif()
