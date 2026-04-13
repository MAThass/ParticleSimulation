cmake_minimum_required(VERSION 3.16)
project(ParticleSimulation)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(FetchContent)
FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG        5.0
)
FetchContent_Declare(
  tomlplusplus
  GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
  GIT_TAG        v3.4.0
)



set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(raylib)
FetchContent_MakeAvailable(tomlplusplus)

find_package(TBB REQUIRED)


#set(MATH_SOURCES include/math/Vector3.hpp) # Header-only, ale warto widzieć w IDE
#set(PHYS_SOURCES src/physics/ParticleSystem.cpp)
#set(GFX_SOURCES  src/visualization/Renderer.cpp)

add_executable(${PROJECT_NAME} 
    src/main.cpp 
    # ${PHYS_SOURCES} 
    # ${GFX_SOURCES}
)


target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE tomlplusplus::tomlplusplus)


target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
    raylib 
    TBB::tbb
    m           
    pthread     
    dl 
    rt 
    X11         
)


find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME} PUBLIC OpenMP::OpenMP_CXX)
endif()