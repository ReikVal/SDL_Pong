#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <string>
#include "Paddle.h"

class Game {
    public:
        Game(std::string title, int w, int h);
        ~Game();

        void quit();
        void handleInput();
        void update();
        void render();

        bool isRunning();
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool running{true};
        std::string title;
        int w, h;
        Paddle paddle1;
};

#endif // GAME_H
