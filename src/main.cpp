#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "core/engine.h"

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char** argv) {
  
  Engine::GetInstance()->Init();

  while(Engine::GetInstance()->IsRunning()) {
    Engine::GetInstance()->Events();
    Engine::GetInstance()->Update();
    Engine::GetInstance()->Render();
  }

  Engine::GetInstance()->Clean();

  return 0;
}