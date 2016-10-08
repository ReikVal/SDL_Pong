#include <stdexcept>
#include "Game.h"

Game::Game(std::string title, int w, int h):
    title(title), w(w), h(h) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error(SDL_GetError());
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    if(window == nullptr) {
        SDL_Quit();
        throw std::runtime_error(SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        throw std::runtime_error(SDL_GetError());
    }
}

Game::~Game() {
    quit();
}

void Game::quit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::handleInput() {
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT) {
            running = false;
        }
        paddle1.handleInput(e);
    }
}

void Game::update() {
    paddle1.update();
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
    SDL_RenderClear(renderer);
    //Render paddles:
    paddle1.render(renderer);

    //Render central line:
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for(int i = 0; i < 17; i+=2) {
        SDL_RenderDrawLine(renderer, w/2, i*h/17, w/2, (i+1)*h/17);
    }
    //Present:
    SDL_RenderPresent(renderer);
}

bool Game::isRunning() {
    return running;
}
