#include "raylib.h"
#include <vector>

int main() {
    
    const int screenWidth = 1200;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Particle - Parallel Simulation");



    SetTargetFPS(120); 

    
    while (!WindowShouldClose()) {
  
        float dt = GetFrameTime();

      
        BeginDrawing();
            ClearBackground(BLACK);
            DrawFPS(10, 10);
           
            DrawText("work ", 10, 40, 20, RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}