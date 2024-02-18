#include "engine.h"
#include <iostream>
#include "SDL2/SDL_image.h"

Engine* Engine::s_Instance = nullptr;

bool Engine::Init() {
  // init SDL engine
  if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
    SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
    return false;
  }

  // create Screen window
  m_Window = SDL_CreateWindow("Skyfire", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  if (m_Window == nullptr) {
    SDL_Log("Failed to create Window: %s", SDL_GetError());
    return false;
  }

  // create renderer
  m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (m_Renderer == nullptr) {
    SDL_Log("Failed to create Renderer: %s", SDL_GetError());
    return false;
  }

  return true;
}

bool Engine::Clean() {
  return true;
}

void Engine::Update() {
  SDL_SetRenderDrawColor(m_Renderer, 124,218, 254, 255);
  SDL_RenderPresent(m_Renderer);
}

void Engine::Render() {

}

void Engine::Events() {
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type)
  {
  case SDL_QUIT:
    // call quit
    Quit();
    break;
  }
}

void Engine::Quit() {
  m_Is_Running = false;
}

