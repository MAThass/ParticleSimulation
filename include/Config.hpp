#pragma once
#include <toml++/toml.hpp>
#include <string>
#include <iostream>

struct AppConfig {
    int windowWidth;
    int windowHeight;
    std::string windowTitle;

    float gravity;
    int particleCount;
    float boxSize;
    float box_width;
    float box_height;
    float box_lenght;

    static AppConfig load(const std::string& path) {
        AppConfig config;
        try {
            auto data = toml::parse_file(path);
            
            config.windowWidth = data["window"]["width"].value_or(800);
            config.windowHeight = data["window"]["height"].value_or(600);
            config.windowTitle = data["window"]["title"].value_or("Sim");

            config.gravity = data["physics"]["gravity"].value_or(-9.81f);
            config.particleCount = data["physics"]["particle_count"].value_or(1000);
            config.boxSize = data["physics"]["box_size"].value_or(50.0f);
            config.box_width = data["physics"]["box_width"].value_or(50.0f);
            config.box_height = data["physics"]["box_height"].value_or(50.0f);
            config.box_lenght = data["physics"]["box_lenght"].value_or(50.0f);
        } 
        catch (const toml::parse_error& err) {
            std::cerr << "configu parse error: " << err << std::endl;
        }
        return config;
    }
};