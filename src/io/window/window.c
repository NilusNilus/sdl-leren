#include <stdio.h>
#include <assert.h>
#include <glad/glad.h>
#include "io/window/window.h"

static struct Window* self = NULL;

void win_init(struct Window* win)
{
    self = win;

    SDL_DisplayMode dm;
    assert(SDL_GetCurrentDisplayMode(0, &dm) == 0);
    self->width = dm.w / 2;
    self->height = dm.h / 2;
    self->title = "sdl leren";

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_WINDOW_FOREIGN, 1);

    self->handle = SDL_CreateWindow(
        self->title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        self->width,
        self->height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );
    assert(self->handle != NULL);

    self->gl_context = SDL_GL_CreateContext(self->handle);
    assert(self->gl_context != NULL);

    assert(gladLoadGLLoader(SDL_GL_GetProcAddress) != 0);

    glViewport(0, 0, self->width, self->height);

    printf(
        "\nvendor:%s\nrenderer:%s\nversion:%s\nshading language:%s\n",
        glGetString(GL_VENDOR),
        glGetString(GL_RENDERER),
        glGetString(GL_VERSION),
        glGetString(GL_SHADING_LANGUAGE_VERSION)
    );
}