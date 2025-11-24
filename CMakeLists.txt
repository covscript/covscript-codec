cmake_minimum_required(VERSION 3.16)

project(covscript-codec)
include_directories(include)

if (DEFINED ENV{CS_DEV_PATH})
    message("-- CovScript SDK detected at $ENV{CS_DEV_PATH}")
    include("$ENV{CS_DEV_PATH}/csbuild.cmake")
    include_directories($ENV{CS_DEV_PATH}/include)
    link_directories($ENV{CS_DEV_PATH}/lib)
else ()
    message(FATAL_ERROR "-- CovScript SDK not detected. Please set environment variable CS_DEV_PATH")
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