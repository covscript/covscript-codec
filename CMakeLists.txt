cmake_minimum_required(VERSION 3.4)

project(covscript-codec)
include_directories(include)

if (DEFINED ENV{CS_DEV_PATH})
    include_directories($ENV{CS_DEV_PATH}/include)
    link_directories($ENV{CS_DEV_PATH}/lib)
endif ()

if (DEFINED ENV{CS_DEV_OUTPUT})
    set(LIBRARY_OUTPUT_PATH $ENV{CS_DEV_OUTPUT})
    set(EXECUTABLE_OUTPUT_PATH $ENV{CS_DEV_OUTPUT})
endif ()

# Compiler Options
set(CMAKE_CXX_STANDARD 14)

if (MSVC)
    set(CMAKE_CXX_FLAGS "/O2 /EHsc /utf-8 /w")
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
elseif (CMAKE_COMPILER_IS_GNUCXX)
    if (WIN32)
        set(CMAKE_C_FLAGS "--static -fPIC -s -O3")
        set(CMAKE_CXX_FLAGS "--static -fPIC -s -O3")
    else ()
        set(CMAKE_C_FLAGS "-fPIC -s -O3")
        set(CMAKE_CXX_FLAGS "-fPIC -s -O3")
    endif ()
else ()
    set(CMAKE_C_FLAGS "-fPIC -O3")
    set(CMAKE_CXX_FLAGS "-fPIC -O3")
endif ()

SET(jsoncpp_sources
        lib_json/json_tool.h
        lib_json/json_reader.cpp
        lib_json/json_valueiterator.inl
        lib_json/json_value.cpp
        lib_json/json_writer.cpp)

add_library(jsoncpp_lib STATIC ${jsoncpp_sources})

SET(hashlib_sources
        hash-library/crc32.cpp
        hash-library/md5.cpp
        hash-library/sha1.cpp
        hash-library/sha256.cpp)

add_library(hashlib STATIC ${hashlib_sources})

add_library(codec SHARED codec.cpp)

target_link_libraries(codec jsoncpp_lib hashlib covscript)

set_target_properties(codec PROPERTIES OUTPUT_NAME codec)
set_target_properties(codec PROPERTIES PREFIX "")
set_target_properties(codec PROPERTIES SUFFIX ".cse")