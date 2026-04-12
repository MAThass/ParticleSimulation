#pragma once

#include "Vector3.hpp"
#include <cmath>

namespace phys::math 
{
    struct  Quaternion 
    {
        float w, x, y, z;

        Quaternion() : w(1), x(0), y(0), z(0) {}
        Quaternion( float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}
        
        inline Quaternion fromAxisAngle(float angle, Vector3 v)
        {
            v = v * sinf(angle/2.0f);
            return { cosf(angle/2.0f), v.x, v.y, v.z };
        }
    };
}