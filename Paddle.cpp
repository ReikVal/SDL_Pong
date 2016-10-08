#include "Paddle.h"

void Paddle::handleInput(SDL_Event &e) {
    if(e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        switch(e.key.keysym.sym) {
            case SDLK_DOWN:
                dy += v;
                break;
            case SDLK_UP:
                dy -= v;
                break;
        }
    } else if(e.type == SDL_KEYUP) {
        switch(e.key.keysym.sym) {
            case SDLK_DOWN:
                dy -= v;
                break;
            case SDLK_UP:
                dy += v;
                break;
        }
    }
}

void Paddle::update() {
    y += dy;
    if(y < 20) {
        y = 20;
    } else if(y + h > 460) {
        y = 460-h;
    }
    paddle.y = y;
}

void Paddle::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &paddle);
}
