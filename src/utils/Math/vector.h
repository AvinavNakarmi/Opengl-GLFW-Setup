#pragma once
#include <cmath>

class Vector3 {
public:
    float x, y, z;

    Vector3(float x = 0, float y = 0, float z = 0);

    Vector3 operator+(const Vector3& b) const;
    Vector3 operator-(const Vector3& b) const;
    Vector3 operator*(float factor) const;
    Vector3 operator/(const Vector3& b) const;

    float length() const;
    Vector3 normalize() const;
    float dotProduct(const Vector3& b) const;
    Vector3 crossproduct(const Vector3& b) const;
    void print() const;
};
