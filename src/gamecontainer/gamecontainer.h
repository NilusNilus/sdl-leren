#pragma once
#include "io/window/window.h"

struct GameContainer
{
    struct Window* win;
};  

void gc_init(struct GameContainer* gc, struct Window* win);
void gc_loop(void);