# include "Vector3.hpp"

namespace phys::geometry 
{
    struct Sphere 
    {
        math::Vector3 center;
        float radius;
    };

    struct Plane 
    {
        math::Vector3 normal;
        float distance;
    };

    struct Quad 
    {
        math::Vector3 center;
        math::Vector3 normal;
        math::Vector3 up;
        float width;
        float height;
    };

    struct AABB {
        math::Vector3 min;
        math::Vector3 max;
    };
}