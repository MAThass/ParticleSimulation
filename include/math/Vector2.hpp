#pragma once
#include <cmath>
#include <iostream>

// for debuging
#include <cassert>



namespace phys::math 
{
    struct  Vector2 
    {
        static constexpr float EPSILON = 1e-5f;
        float x, y;

        Vector2() : x(0), y(0) {}
        Vector2(float x, float y) : x(x), y(y) {}

        inline Vector2 operator+(const Vector2& v) const
        {
            return {x + v.x, y + v.y};
        }
        inline Vector2 operator-(const Vector2& v) const
        {
            return {x - v.x, y - v.y};
        }
        inline Vector2 operator*(float s) const 
        { 
            return {x * s, y * s}; 
        }
        inline Vector2 operator/(float s) const 
        { 
            return {x / s, y / s}; 
        }

        inline void operator+=(const Vector2& v)
        {
            x = x + v.x;
            y = y + v.y;
        }
        inline void operator-=(const Vector2& v)
        {
            x = x - v.x;
            y = y - v.y;
        }
        inline void operator*=(float s)
        {
            x = x * s;
            y = y * s;
        }
        inline void operator/=(float s)
        {
            x = x / s;
            y = y / s;
        }

        inline Vector2 operator-() const
        {
            return {-x,-y};
        }

        inline bool operator==(const Vector2& v) const
        {
            if(( std::fabsf(x-v.x) < EPSILON ) && ( std::fabsf(y-v.y) < EPSILON ))
                return true;
            else
                return false;
        } 
        inline bool operator!=(const Vector2& v) const
        {
            if(( std::fabsf(x-v.x) < EPSILON ) && ( std::fabsf(y-v.y) < EPSILON ))
                return false;
            else
                return true;
        }

        inline float& operator[](int i)
        {
            assert(i >= 0 && i < 2);
            float* ptr = &x;
            return ptr[i];
        }
        inline float operator[](int i) const
        {
            assert(i >= 0 && i < 2);
            const float* ptr = &x;
            return ptr[i];
        }

        inline float dotProduct(const Vector2& v) const
        {
            return x*v.x + y*v.y;
        }
        inline float crossProduct(const Vector2& v) const
        {
            return x*v.y - y*v.x;
        }
        inline float lengthSq() const { return x*x + y*y; }
        inline float length() const 
        { 
            return sqrtf(x*x + y*y); 
        }
        inline Vector2 normalize() const
        {
            float lenght = this->length();
            if( lenght == 0)
                return {0, 0};
            float L = 1 / lenght;
            return {x*L, y*L } ;
        }
        inline Vector2 reflect(const Vector2& n) const
        {
            return (*this) - n * (this->dotProduct(n) * 2.0f); 
        }
        inline Vector2 project(const Vector2& v) const
        {
            return v * (this->dotProduct(v) / v.lengthSq());
        }
        inline Vector2 perpendicular() const { return {-y, x}; }
        inline Vector2 rotate(float angle) const 
        {
            float s = std::sinf(angle);
            float c = std::cosf(angle);
            return { x * c - y * s, x * s + y * c };
        }


        inline static Vector2 Zero() { return {0,0}; }

    };

    inline Vector2 operator*(float s, const Vector2& v) { return v * s; }

    inline std::ostream& operator<<(std::ostream& os, const Vector2& v) 
    {
        os <<"[" << v.x << ", " << v.y << "]"; 
        return os;
    }
    
}