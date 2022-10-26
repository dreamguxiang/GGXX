#pragma once

//
// Created by Admin on 2022/10/25.
//
#include "Global.h"
#ifndef GGXX_VEC2_H
#define GGXX_VEC2_H

#endif //GGXX_VEC2_H

class Vec2 {
public:
    float x, y;

    Vec2(float a, float b) : x(a), y(b){};

    inline std::string toString() const {
        return std::to_string(x) + "," + std::to_string(y);
    }

    inline Vec2 operator*(float num) const {
        return {x * num, y * num};
    }

    inline Vec2 operator+(const Vec2& b) const {
        return {this->x + b.x, this->y + b.y};
    }

    inline Vec2 operator-(const Vec2& b) const {
        return {this->x - b.x, this->y - b.y};
    }

};