cmake_minimum_required(VERSION 4.0.0)
set(CMAKE_C_COMPILER "/usr/bin/clang")
project(rlclone)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

set(RAYLIB_VERSION 6.0)
find_package(raylib ${RAYLIB_VERSION} QUIET)

if (NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )

  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED)
    set(FETCHCONTENT_QUIET NO)
    FetchContent_MakeAvailable(raylib)
  endif()
endif()
include(CMakeDependentOption)

set(mod_name OFF)
function(add_module moddir opt_name)
  option(${opt_name}_MOD "Build module ${opt_name}" ON)
  if(${opt_name}_MOD)
    set(mod_name ${opt_name}_MOD)
    add_subdirectory(${moddir})
  endif()
endfunction()

add_subdirectory("./src")
