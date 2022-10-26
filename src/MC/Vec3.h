#pragma once

//
// Created by Admin on 2022/10/25.
//
#include <iostream>
#include <string>

#ifndef GGXX_VEC3_H
#define GGXX_VEC3_H

#endif //GGXX_VEC3_H

#include "Global.h"
#include "BlockPos.h"
class BloclPos;
class Vec3 {
public:
    float x{}, y{}, z{};

    inline Vec3() = default;

    inline Vec3(float _x, float _y, float _z)
            : x(_x), y(_y), z(_z) {};

    inline explicit Vec3(BlockPos &pos)
            : x((float) pos.x), y((float) pos.y), z((float) pos.z) {};

    inline Vec3(double _x, double _y, double _z)
            : x((float) _x), y((float) _y), z((float) _z) {};

    inline Vec3(int _x, int _y, int _z)
            : x((float) _x), y((float) _y), z((float) _z) {};

    inline std::string toString() const {
        return std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z);
    }

    inline Vec3 add(float dx, float dy, float dz) const {
        return {x + dx, y + dy, z + dz};
    }

    inline Vec3 normalize() const {
        float l = length();
        return {x / l, y / l, z / l};
    }

    inline float length() const {
        return sqrt(lengthSqr());
    }

    inline float lengthSqr() const {
        return this->dot(*this);
    }

    inline float distanceTo(Vec3 const& b) const {
        return (*this - b).length();
    }

    inline float distanceToSqr(Vec3 const& b) const {
        return (*this - b).lengthSqr();
    }

    float& operator[](int index) {
        if (index < 0 || index > 2) {
            return (&x)[0];
        }
        return (&x)[index];
    }

    constexpr bool operator==(const Vec3& b) const {
        return x == b.x && y == b.y && z == b.z;
    }

    constexpr bool operator!=(const Vec3& b) const {
        return x != b.x || y != b.y || z != b.z;
    }

    inline Vec3 operator*(float b) const {
        return {x * b, y * b, z * b};
    }

    inline Vec3 operator/(float b) const {
        return {x / b, y / b, z / b};
    }

    inline Vec3 operator+(float b) const {
        return {x + b, y + b, z + b};
    }

    inline Vec3 operator-(float b) const {
        return {x - b, y - b, z - b};
    }

    constexpr Vec3& operator+=(float b) {
        x += b;
        y += b;
        z += b;
        return *this;
    }

    constexpr Vec3& operator-=(float b) {
        x -= b;
        y -= b;
        z -= b;
        return *this;
    }

    constexpr Vec3& operator*=(float b) {
        x *= b;
        y *= b;
        z *= b;
        return *this;
    }

    constexpr Vec3& operator/=(float b) {
        x /= b;
        y /= b;
        z /= b;
        return *this;
    }

    constexpr Vec3& operator+=(Vec3 const& b) {
        x += b.x;
        y += b.y;
        z += b.z;
        return *this;
    }

    constexpr Vec3& operator-=(Vec3 const& b) {
        x -= b.x;
        y -= b.y;
        z -= b.z;
        return *this;
    }

    constexpr Vec3& operator*=(Vec3 const& b) {
        x *= b.x;
        y *= b.y;
        z *= b.z;
        return *this;
    }

    constexpr Vec3& operator/=(Vec3 const& b) {
        x /= b.x;
        y /= b.y;
        z /= b.z;
        return *this;
    }

    inline Vec3 operator+(Vec3 const& b) const {
        return {x + b.x, y + b.y, z + b.z};
    }

    inline Vec3 operator*(Vec3 const& b) const {
        return {x * b.x, y * b.y, z * b.z};
    }

    inline Vec3 operator/(Vec3 const& b) const {
        return {x / b.x, y / b.y, z / b.z};
    }

    inline Vec3 operator-(Vec3 const& b) const {
        return {x - b.x, y - b.y, z - b.z};
    }

    inline float dot(const Vec3& b) const {
        return x * b.x + y * b.y + z * b.z;
    }

    inline Vec3 cross(const Vec3& b) const {
        return {y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x};
    }

    inline bool operator<(const Vec3& b) const {
        return this->lengthSqr() < b.lengthSqr();
    }

    inline bool operator>(const Vec3& b) const {
        return this->lengthSqr() > b.lengthSqr();
    }
};