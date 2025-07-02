#include "vector.h"
#include <iostream>

Vector3::Vector3(float x, float y, float z)
    : x(x), y(y), z(z) {

}

Vector3 Vector3::operator+(const Vector3& b) const {
    return Vector3(x + b.x, y + b.y, z + b.z);
}

Vector3 Vector3::operator-(const Vector3& b) const {
    return Vector3(x - b.x, y - b.y, z - b.z);
}

Vector3 Vector3::operator*(float factor) const {
    return Vector3(factor * x, factor * y, factor * z);
}

Vector3 Vector3::operator/(const Vector3& b) const {
    return Vector3(x / b.x, y / b.y, z / b.z);
}

float Vector3::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::normalize() const {
    float len = length();
    if (len != 0) {
        return Vector3(x / len, y / len, z / len);
    }
    return Vector3(0, 0, 0);
}

float Vector3::dotProduct(const Vector3& b) const {
    return x * b.x + y * b.y + z * b.z;
}

Vector3 Vector3::crossproduct(const Vector3& b) const {
    return Vector3(
        y * b.z - z * b.y,
        z * b.x - x * b.z,
        x * b.y - y * b.x
    );
}

void Vector3::print() const
{
    std::cout << x << " " << y << "" << z;
}