//
// Created by kae on 07/08/24.
//

#pragma once
#include <SDL2/SDL_render.h>

struct SDL_Window;

class Game
{
public:

  void init(const char* title, int width, int height);

  void handleEvents();
  void update(double lag);
  void render();

  void close();

public:
  SDL_Renderer *Renderer { nullptr };
  bool Running {};

private:
  SDL_Window *m_window { nullptr };
  uint8_t count {};
};