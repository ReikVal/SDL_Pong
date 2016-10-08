#ifndef PADDLE_H
#define PADDLE_H

#include <SDL.h>

class Paddle {
    public:
        Paddle() {}
        void handleInput(SDL_Event &e);
        void update();
        void render(SDL_Renderer *renderer);
    private:
        int x{5};
        int y{20};
        int w{8};
        int h{32};
        SDL_Rect paddle{x, y, w, h};

        int v{8};
        int dy{0};
};

#endif // PADDLE_H
