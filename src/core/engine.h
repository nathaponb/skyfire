#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

// singleton engine
class Engine {
  private:
    Engine() {}
    bool m_Is_Running;
    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;
    static Engine* s_Instance;

  public:
    static Engine* GetInstance() {
      return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
    };

    bool Init();
    bool Clean();
    void Quit();
    void Update();
    void Render();
    void Events();

    inline bool IsRunning() {return m_Is_Running;};
    inline SDL_Renderer* GetRenderer() {return m_Renderer;};
};

#endif