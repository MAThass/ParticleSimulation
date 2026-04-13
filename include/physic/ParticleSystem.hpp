#pragma once

#include "math/Vector3.hpp"
#include <vector>

namespace phys {
    struct ParticleSystem {
        std::vector<math::Vector3> positions;
        std::vector<math::Vector3> velocities;
        std::vector<float> radii; 
        std::vector<float> masses;

        
        void reserve(size_t count) {
            positions.reserve(count);
            velocities.reserve(count);
            radii.reserve(count);
            masses.reserve(count);
        }

        void addParticle(math::Vector3 pos, math::Vector3 vel, float radius) {
            positions.push_back(pos);
            velocities.push_back(vel);
            radii.push_back(radius);
            
            // Mass: 4/3 * PI * r^3 (density = 1.0f)
            float m = (4.0f / 3.0f) * 3.14159f * (radius * radius * radius);
            masses.push_back(m);
        }
        
        size_t size() const { return positions.size(); }
    };
}