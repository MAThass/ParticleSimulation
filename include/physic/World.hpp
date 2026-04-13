#include "Geometry.hpp"
#include "Collision.hpp"
#include "Vector3.hpp"

namespace phys::math 
{   
    class World 
    {
        // Definicja pudełka (wymiary od 0,0,0 do boxSize.x, .y, .z)
        math::Vector3 boxSize;
        float gravity;
        ParticleSystem particles;

        World(math::Vector3 size) : boxSize(size), gravity(-9.81f) {}

        // Główna funkcja aktualizująca cały stan świata
        void step(float dt);
    };
}