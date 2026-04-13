


void drawParticles(const phys::ParticleSystem& system) {
    for (size_t i = 0; i < system.positions.size(); ++i) {
        ::Vector3 rlPos = { system.positions[i].x, system.positions[i].y, system.positions[i].z };
        
        DrawSphere(rlPos, system.radii[i], RED);
        
        // simple light
        DrawSphereWires(rlPos, system.radii[i], 8, 8, MAROON); 
    }
}