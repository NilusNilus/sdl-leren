#define SDL_MAIN_HANDLED
#include "gamecontainer/gamecontainer.h"

int main(int argc, char* argv[])
{
    struct GameContainer gc = {};
    struct Window win = {};
    gc_init(&gc, &win);
    win_init(&win);
    gc_loop();
    return 0;
}
