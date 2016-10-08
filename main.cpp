#include <SDL.h>
#include <stdexcept>
#include <iostream>
#include "Game.h"

int main(int argc, char* argv[]) {
    try {
        Game game("Pong", 640, 480);
        while(game.isRunning()) {
            game.handleInput();
            game.update();
            game.render();
        }
        game.quit();
    } catch(std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
