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
        float width;
        float height;
    };
}