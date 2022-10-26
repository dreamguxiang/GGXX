#pragma once

#ifndef FMT_HEADER_ONLY
#define FMT_HEADER_ONLY
#endif

#include <Windows.h>
#include <filesystem>
#include <FMT/chrono.h>
#include <FMT/color.h>
#include <FMT/core.h>
#include <FMT/os.h>
#include "FMT/printf.h"
#include "Utils/StringHelper.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <utility>

#define COLOR_TIME fmt::color::light_blue
#define COLOR_INFO_PREFIX fmt::color::light_sea_green
#define COLOR_INFO_TEXT fmt::terminal_color::white
#define COLOR_WARN_PREFIX fmt::terminal_color::bright_yellow
#define COLOR_WARN_TEXT fmt::color::yellow2
#define COLOR_ERROR_PREFIX fmt::terminal_color::bright_red
#define COLOR_ERROR_TEXT fmt::color::red2

#define LOG_PREFIX(prefix, color1, color2)                                                                              \
    fmt::print(fmt::format("{:%H:%M:%S}", fmt::localtime(_time64(0)))); \
    fmt::print(fmt::format(prefix, fmt::localtime(_time64(0))));
#define LOG(color1, color2, prefix)                                            \
    LOG_PREFIX(prefix, color1, color2);                                        \
    std::string str = fmt::format("[GGXX] ", fmt::localtime(_time64(0))); \
    str += fmt::format(formatStr, args...);                                    \
    str.append(1, '\n');

template <typename... Args>
void inline Info(const std::string& formatStr, const Args&... args) {
    LOG(COLOR_TIME, COLOR_INFO_PREFIX, " INFO ");
    fmt::print( str);
}

template <typename... Args>
void inline Warn(const std::string& formatStr, const Args&... args) {
    LOG(COLOR_TIME, COLOR_WARN_PREFIX, " WARN ");
    fmt::print( str);
}

template <typename... Args>
void inline Error(const std::string& formatStr, const Args&... args) {
    LOG(COLOR_TIME, COLOR_ERROR_PREFIX, " ERROR ");
    fmt::print( str);
}