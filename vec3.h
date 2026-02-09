//
// Created by Hosna on 2/8/2026.
//

#ifndef TRACY_VEC3_H
#define TRACY_VEC3_H

#include <cmath>
#include <iostream>


class vec3 {
public:
    double e[3];

    vec3() : e {0, 0, 0} {}
    vec3(double x, double y, double z) : e{x, y, z} {}

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    vec3 operator -() const { return vec3{-e[0], -e[1], -e[2]}; }
    double operator[](int i) const { return e[i]; }
    double& operator[](int i ){return  e[i]; }

    vec3& operator += (const vec3& v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
        return *this;
    }

    vec3& operator*= (double s) {
        e[0] *= s;
        e[1] *= s;
        e[2] *= s;
        return *this;
    }

    vec3& operator/= (double s) {

        return *this *= 1/s ;
    }

    double length() const {
        return sqrt(length_squared());
    }

    double length_squared() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }

};

using point3 = vec3;

inline std::ostream& operator <<( std::ostream& out, const vec3& v ) {
    return out << v.e[0] << " " << v.e[1] << " " << v.e[2];

}

inline vec3 operator + (const vec3& v , const vec3& u ) {

    return {v.e[0] + u.e[0], v.e[1] + u.e[1], v.e[2] + u.e[2]};
}

inline vec3 operator - (const vec3& v , const vec3& u ) {
    return {v.e[0] - u.e[0], v.e[1] - u.e[1], v.e[2] - u.e[2]};
}

inline vec3 operator * (const vec3& v , const vec3& u ) {
    return {v.e[0] * u.e[0], v.e[1] * u.e[1], v.e[2] * u.e[2]};
}

inline vec3 operator * (const vec3& v , double s ) {

    return {v.e[0] * s, v.e[1] * s, v.e[2] * s};
}

inline vec3 operator * (double s, const vec3& v ) {

    return {v.e[0] * s, v.e[1] * s, v.e[2] * s};
}

inline double dot(const vec3& v , const vec3& u ) {
    return
        v.e[0] * u.e[0] +
        v.e[1] * u.e[1] +
        v.e[2] * u.e[2];
}

inline vec3 cross(const vec3& u , const vec3& v ) {
    return {
        u.e[1] * v.e[2] - u.e[2] * v.e[1],
        u.e[2] * v.e[0] - u.e[0] * v.e[2],
        u.e[0] * v.e[1] - u.e[1] * v.e[0]
    };
}

inline vec3 operator / (const vec3& v , double s ) {

    return {v.e[0] / s, v.e[1] / s, v.e[2] / s};
}

inline vec3 unit_vector(vec3& v) {
    return v / v.length();
}

#endif //TRACY_VEC3_H