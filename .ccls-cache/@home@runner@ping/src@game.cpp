#include "game.hpp"

#include <iostream>
#include <SDL2/SDL.h>

void Game::init(const char* title, int width, int height)
{
  m_window = SDL_CreateWindow(title
    , SDL_WINDOWPOS_CENTERED
    , SDL_WINDOWPOS_CENTERED
    , width
    , height
    , false);

  Renderer = SDL_CreateRenderer(m_window, -1, false);

  Running = true;
}

void Game::handleEvents()
{
  SDL_Event e;

  while ( SDL_PollEvent( &e ) != 0)
  {
    if (e.type == SDL_QUIT)
      close();
  }
}

void Game::update(double lag)
{
  std::cout << static_cast<int>(count++) << '\n';
  std::cout << "Updating game at: x" << lag << " speed.\n";
}

void Game::render()
{
}

void Game::close()
{
  SDL_DestroyWindow(m_window);
  SDL_Quit();
  Running = false;
}