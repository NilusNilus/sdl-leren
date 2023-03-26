#pragma once
#include <SDL2/SDL.h>

struct Window
{
    int width, height;
    const char* title;
    SDL_Window* handle;
    SDL_GLContext gl_context;
};

void win_init(struct Window* win);