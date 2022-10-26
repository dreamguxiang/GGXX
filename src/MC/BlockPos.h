//
// Created by Admin on 2022/10/25.
//

#ifndef GGXX_BLOCKPOS_H
#define GGXX_BLOCKPOS_H
#pragma once

#include "Global.h"

#endif //GGXX_BLOCKPOS_H
class Vec3;
class BlockPos {
public:
    int x, y, z;

    inline BlockPos() : BlockPos(0, 0, 0) {};

    inline BlockPos(int mx, int my, int mz) : x(mx), y(my), z(mz) {};

    std::vector<BlockPos> getNeighbors() const {
        std::vector<BlockPos> res;
        res.push_back({x, y - 1, z});
        res.push_back({x, y + 1, z});
        res.push_back({x, y, z - 1});
        res.push_back({x, y, z + 1});
        res.push_back({x - 1, y, z});
        res.push_back({x + 1, y, z});
        return res;
    }

    inline std::string toString() const {
        return std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z);
    }

    inline BlockPos add(int dx) const {
        return {x + dx, y, z};
    }

    inline BlockPos add(int dx, int dy) const {
        return {x + dx, y + dy, z};
    }

    inline BlockPos add(int dx, int dy, int dz) const {
        return {x + dx, y + dy, z + dz};
    }


    int& operator[](int index) {
        if (index < 0 || index > 2) {
            return (&x)[0];
        }
        return (&x)[index];
    }

    constexpr inline bool operator==(BlockPos const& b) const {
        return x == b.x && y == b.y && z == b.z;
    }

    constexpr bool operator!=(BlockPos const& b) const {
        return x != b.x || y != b.y || z != b.z;
    }

    constexpr BlockPos& operator+=(BlockPos const& b) {
        x += b.x;
        y += b.y;
        z += b.z;
        return *this;
    }

    constexpr BlockPos& operator-=(BlockPos const& b) {
        x -= b.x;
        y -= b.y;
        z -= b.z;
        return *this;
    }

    constexpr BlockPos& operator*=(BlockPos const& b) {
        x *= b.x;
        y *= b.y;
        z *= b.z;
        return *this;
    }

    constexpr BlockPos& operator/=(BlockPos const& b) {
        x /= b.x;
        y /= b.y;
        z /= b.z;
        return *this;
    }

    inline BlockPos operator+(BlockPos const& b) const {
        return {x + b.x, y + b.y, z + b.z};
    }

    inline BlockPos operator*(BlockPos const& b) const {
        return {x * b.x, y * b.y, z * b.z};
    }

    inline BlockPos operator/(BlockPos const& b) const {
        return {x / b.x, y / b.y, z / b.z};
    }

    inline BlockPos operator-(BlockPos const& b) const {
        return {x - b.x, y - b.y, z - b.z};
    }

    inline BlockPos operator*(int b) const {
        return {x * b, y * b, z * b};
    }

    inline BlockPos operator/(int b) const {
        return {x / b, y / b, z / b};
    }

    inline BlockPos operator+(int b) const {
        return {x + b, y + b, z + b};
    }

    inline BlockPos operator-(int b) const {
        return {x - b, y - b, z - b};
    }

    constexpr BlockPos& operator+=(int b) {
        x += b;
        y += b;
        z += b;
        return *this;
    }

    constexpr BlockPos& operator-=(int b) {
        x -= b;
        y -= b;
        z -= b;
        return *this;
    }

    constexpr BlockPos& operator*=(int b) {
        x *= b;
        y *= b;
        z *= b;
        return *this;
    }

    constexpr BlockPos& operator/=(int b) {
        x /= b;
        y /= b;
        z /= b;
        return *this;
    }

    inline bool containedWithin(BlockPos const& a, BlockPos const& b) const {
        return x >= a.x && y >= a.y && z >= a.z && x <= b.x && y <= b.y && z <= b.z;
    }

    inline double length() const {
        return sqrt(x * x + y * y + z * z);
    }

    inline double distanceTo(BlockPos const& a) const {
        return (*this - a).length();
    }

};