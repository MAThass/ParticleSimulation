#include "Geometry.hpp"
#include "Vector3.hpp"


namespace phys::collision {
    inline bool checkSphereSphere(geometry::Sphere s1, geometry::Sphere s2) {
        float distSq = (s1.center - s2.center).lengthSq();
        float rSum = s1.radius + s2.radius;
        return distSq <= (rSum * rSum);
    }

    inline float distanceToPlane(math::Vector3 pos, math::Vector3 normal, float d) {
        return (pos.dot(normal)) - d; 
    }
}