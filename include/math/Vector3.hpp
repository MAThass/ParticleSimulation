#pragma once
#include <cmath>



namespace phys::math 
{
    struct  Vector3 
    {
        static constexpr float EPSILON = 1e-5f;
        float x, y, z;

        Vector3() : x(0), y(0), z(0) {}
        Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

        inline Vector3 operator+(const Vector3& v) const
        {
            return {x + v.x, y + v.y, z + v.z};
        }
        inline Vector3 operator-(const Vector3& v) const
        {
            return {x - v.x, y - v.y, z - v.z};
        }
        inline Vector3 operator*(float s) const 
        { 
            return {x * s, y * s, z * s}; 
        }
        inline Vector3 operator/(float s) const 
        { 
            return {x / s, y / s, z / s}; 
        }

        inline void operator+=(const Vector3& v)
        {
            x = x + v.x;
            y = y + v.y;
            z = z + v.z;
        }
        inline void operator-=(const Vector3& v)
        {
            x = x - v.x;
            y = y - v.y;
            z = z - v.z;
        }
        inline void operator*=(float s)
        {
            x = x * s;
            y = y * s;
            z = z * s;
        }
        inline void operator/=(float s)
        {
            x = x / s;
            y = y / s;
            z = z / s;
        }

        inline Vector3 operator-() const
        {
            return {-x,-y,-z};
        }

        inline bool operator==(const Vector3& v) const
        {
            if(( std::fabsf(x-v.x) < EPSILON ) && ( std::fabsf(y-v.y) < EPSILON ) && ( std::fabsf(z-v.z) < EPSILON ) )
                return true;
            else
                return false;
        } 
        inline bool operator!=(const Vector3& v) const
        {
            if(( std::fabsf(x-v.x) < EPSILON ) && ( std::fabsf(y-v.y) < EPSILON ) && ( std::fabsf(z-v.z) < EPSILON ) )
                return false;
            else
                return true;
        }

        inline float dotProduct(const Vector3& v) const
        {
            return x * v.x + y * v.y + z * v.z ;
        }
        inline Vector3 crossProduct(const Vector3& v) const
        {
            return {y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x};
        }
        inline float lengthSq() const { return x*x + y*y + z*z; }
        inline float length() const 
        { 
            return sqrtf(x*x + y*y + z*z); 
        }
        inline Vector3 normalize() const
        {
            float lenght = this->length();
            if( lenght == 0)
                return {0, 0, 0};
            float L = 1 / lenght;
            return {x*L, y*L, z*L } ;
        }

        inline static Vector3 Zero() { return {0,0,0}; }

    };

    
}