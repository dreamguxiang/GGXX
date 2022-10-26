cmake_minimum_required(VERSION 3.21)

project(ggxx)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release)

file(GLOB_RECURSE SRC_FILES_DIR
    ${PROJECT_SOURCE_DIR}/src/*.c
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/*.h
    ${PROJECT_SOURCE_DIR}/src/Utils/*.cpp
    ${PROJECT_SOURCE_DIR}/src/Logger/*.h
    ${PROJECT_SOURCE_DIR}/src/Hook/*.cpp
    ${PROJECT_SOURCE_DIR}/src/MC/*.cpp
)

include_directories(
    ${CMAKE_SOURCE_DIR}/SDK/include
)

link_directories(
    ${CMAKE_SOURCE_DIR}/SDK/lib
)

add_definitions(
    -D"NDEBUG"
    -D"NOMINMAX"
    -D"TEMPLATE_EXPORTS"
    -D"UNICODE"
    -D"WIN32_LEAN_AND_MEAN"
    -D"_AMD64_"
    -D"_CRT_SECURE_NO_WARNINGS"
    -D"_UNICODE"
    -D"_USRDLL"
    -D"_WINDLL"
    -D"_WINDOWS"
)

add_compile_options(
    /diagnostics:column
    /EHsc
    /FC
    /GL
    /MD
    /nologo
    /permissive-
    /sdl
    /utf-8
    /Zc:inline
    /Zi
)

add_link_options(
    /DEBUG
    /DLL
    /IGNORE:4199
    /INCREMENTAL:NO
    /LTCG:INCREMENTAL
    /MANIFESTUAC:NO
    /MACHINE:X64
    /NOLOGO
    /OPT:ICF
    /OPT:REF
    /SUBSYSTEM:CONSOLE
)

add_library(ggxx SHARED ${SRC_FILES_DIR} src/MC/ClientInstance.cpp src/MC/ClientInstance.h  src/MC/GuiData.h src/MC/Vec3.h src/MC/BlockPos.h src/MC/Vec2.h src/MC/Player.cpp src/MC/Player.h src/MC/Actor.cpp src/MC/Actor.h src/MC/Global.h src/MC/enums.h src/MC/types.h src/MC/Mob.h src/Hook/Hook.cpp src/MC/Level.cpp src/MC/Level.h src/GlobalService.h)

target_link_libraries(ggxx 
	"${CMAKE_SOURCE_DIR}/SDK/lib/detours.lib"
)

