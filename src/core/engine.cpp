#include "engine.h"
#include <iostream>
#include "SDL2/SDL_image.h"

Engine* Engine::s_Instance = nullptr;

bool Engine::Init() {
  return true;
}

bool Engine::Clean() {
  return true;
}

void Engine::Quit() {

}

void Engine::Update() {
  std::cout << "Updating..." << std::endl;
}

void Engine::Render() {

}

void Engine::Events() {
  
}

