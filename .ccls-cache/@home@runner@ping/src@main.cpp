#include <SDL2/SDL_events.h>
#include <SDL2/SDL_timer.h>

#include "game.hpp"

int TargetFPS { 60 };
int TickRate { 20 };
double FrameDelay { 1000.0 / TickRate };

int main()
{
  Game game;

  game.init("wah", 640, 480);

  uint32_t frameStart {};
  uint32_t frameLast = SDL_GetTicks64();
  int frameDelta {};
  int frameAccumulator {};

  while (game.Running)
  {
    frameStart = SDL_GetTicks64();
    frameDelta = frameStart - frameLast;
    frameLast = frameStart;
    frameAccumulator += frameDelta;

    game.handleEvents();

    // Only update at fixed tickrate
    while (frameAccumulator >= FrameDelay)
    {
      game.update(frameAccumulator / FrameDelay);
      frameAccumulator -= FrameDelay;
    }

    game.render();
  }
}