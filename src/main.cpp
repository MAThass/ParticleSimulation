#include "raylib.h"
#include <vector>
#include "Config.hpp"

int main() {
    AppConfig cfg = AppConfig::load("../config.toml");
    InitWindow(cfg.windowWidth, cfg.windowHeight, cfg.windowTitle.c_str());



    SetTargetFPS(cfg.fps); 

    
    while (!WindowShouldClose()) {
  
        float dt = GetFrameTime();

      
        BeginDrawing();
            ClearBackground(BLACK);
            DrawFPS(10, 10);
           
            DrawText("work ", 10, 40, 20, RAYWHITE);
            DrawCircle(120, 300, 40, YELLOW);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}