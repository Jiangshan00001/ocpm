cmake_minimum_required(VERSION 3.22)

#project name
project(ocpm VERSION 1.1)


SET( CMAKE_VERBOSE_MAKEFILE on )

#static link 
set(BUILD_SHARED_LIBS OFF)
if(MSVC)
add_compile_options(
	$<$<CONFIG:>:/MT>
	$<$<CONFIG:Debug>:/MTd>
	$<$<CONFIG:Release>:/MT>
)
else()
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -static")
endif()


include(FetchContent)
FetchContent_Declare(oflex URL https://github.com/Jiangshan00001/oflex/archive/refs/heads/master.zip)
FetchContent_MakeAvailable(oflex)

FetchContent_Declare(obison URL https://github.com/Jiangshan00001/obison/archive/refs/heads/main.zip)
FetchContent_MakeAvailable(obison)



#head file path
include_directories(src)


add_subdirectory(src)
add_subdirectory(test)

