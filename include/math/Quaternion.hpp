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
        
        inline static Quaternion fromAxisAngle(float angle, Vector3 v)
        {
            v = v * sinf(angle/2.0f);
            return { cosf(angle/2.0f), v.x, v.y, v.z };
        }
        static Quaternion LookRotation(Vector3 forward, Vector3 up = Vector3(0, 1, 0))
        {
            if (forward.lengthSq() < EPSILON) return Quaternion();

            forward = forward.normalize();
            Vector3 right = (up.crossProduct(forward)).normalize();

            if (right.lengthSq() < EPSILON) 
            {
                right = Vector3(1, 0, 0).crossProduct(forward).normalize();
                if (right.lengthSq() < EPSILON) 
                    right = Vector3(0, 0, 1).crossProduct(forward).normalize();
            }

            up = forward.crossProduct(right);

            float m00 = right.x;   float m01 = up.x;   float m02 = forward.x;
            float m10 = right.y;   float m11 = up.y;   float m12 = forward.y;
            float m20 = right.z;   float m21 = up.z;   float m22 = forward.z;

            float tr = m00 + m11 + m22;
            Quaternion q;

            if (tr > 0) {
                float s = sqrtf(tr + 1.0f) * 2.0f; 
                q.w = 0.25f * s;
                q.x = (m21 - m12) / s;
                q.y = (m02 - m20) / s;
                q.z = (m10 - m01) / s;
            } else if ((m00 > m11) && (m00 > m22)) {
                float s = sqrtf(1.0f + m00 - m11 - m22) * 2.0f;
                q.w = (m21 - m12) / s;
                q.x = 0.25f * s;
                q.y = (m01 + m10) / s;
                q.z = (m02 + m20) / s;
            } else if (m11 > m22) {
                float s = sqrtf(1.0f + m11 - m00 - m22) * 2.0f;
                q.w = (m02 - m20) / s;
                q.x = (m01 + m10) / s;
                q.y = 0.25f * s;
                q.z = (m12 + m21) / s;
            } else {
                float s = sqrtf(1.0f + m22 - m00 - m11) * 2.0f;
                q.w = (m10 - m01) / s;
                q.x = (m02 + m20) / s;
                q.y = (m12 + m21) / s;
                q.z = 0.25f * s;
            }
            return q.normalize();
        }


        inline Quaternion fromEulerAngle(){}
        inline float length() const 
        { 
            return sqrtf(w*w + x*x + y*y + z*z); 
        }
        inline Quaternion normalize () const
        {
            float lenght = this->length();
            if( lenght == 0)
                return {0, 0, 0, 0};
            float L = 1 / lenght;
            return {w*L, x*L, y*L, z*L } ;
        }
        inline Quaternion conjugate() const { return {w, -x, -y, -z}; }
        


        inline Quaternion operator*(const Quaternion& q) const
        {
            Vector3 this_v = { x, y, z};
            Vector3 q_v = {q.x, q.y, q.z};
            float new_w = this->w*q.w - this_v.dotProduct(q_v);
            this_v = w*q_v + q.w*this_v + this_v.crossProduct(q_v);
            return { new_w, this_v.x, this_v.y, this_v.z };
        }
        inline Vector3 operator*(const Vector3& v) const
        {
            // v′=v+2q​v​×(q​v​×v+wv)
            Vector3 q_v = { x, y, z};
            return v + (2*q_v).crossProduct(q_v.crossProduct(v) + w*v); 
        }
        
    };
}