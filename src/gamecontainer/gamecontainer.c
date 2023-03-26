#include <stdio.h>
#include <assert.h>
#include "gamecontainer/gamecontainer.h"

#include "io/gfx/vao.h"
#include "io/gfx/vbo.h"

static struct GameContainer* self = NULL;

void gc_init(struct GameContainer* gc, struct Window* win)
{
    self = gc;
    self->win = win;

    assert(SDL_Init(SDL_INIT_EVERYTHING) == 0);
}

void gc_loop(void)
{
    SDL_Event e;
    int running = 1;

    double lastTime = 0.0f;
    double unprocessed = 0.0f;
    double timer = 0.0f;

    int frames = 0;
    int updates = 0;

    double max_unprocessed = 1.0f / 120.0f;

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };  

    struct VAO vao = { 0 };
    struct VBO vbo = { 0 };

    vao_create(&vao);
    vao_bind(&vao);
    
    vbo_create(&vbo, GL_ARRAY_BUFFER, 0);
    vbo_bind(&vbo);

    vbo_data(&vbo, sizeof(vertices) / sizeof(float), vertices);
    vao_attrib(
        &vao,
        &vbo,
        0,
        (sizeof(vertices) / sizeof(float)) * sizeof(GL_FLOAT),
        GL_FLOAT,
        0
    );

    vao_unbind();

    while(running)
    {
        double firstTime = SDL_GetTicks64() * .001f;
        double dt = firstTime - lastTime;
        lastTime = firstTime;

        unprocessed += dt;
        timer += dt;

        while(unprocessed >= max_unprocessed)
        {
            unprocessed -= max_unprocessed;

            while(SDL_PollEvent(&e) != 0)
                switch(e.type)
                {
                    case SDL_QUIT:
                        running = 0;
                }
            
            if(timer >= 1.0f)
            {
                printf("%d %d\n", frames, updates);
                timer = 0;
                frames = 0;
                updates = 0;
            }

            updates++;
        }

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        
        vao_bind(&vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        vao_unbind();

        SDL_GL_SwapWindow(self->win->handle);
        frames++;
    }

    vao_destroy(&vao);
    vbo_destroy(&vbo);

    SDL_DestroyWindow(self->win->handle);
    SDL_Quit();
}