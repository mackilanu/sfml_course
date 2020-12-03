#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    // Program entry point.
    Game game; // Creating our game object.
    while(!game.getWindow()->isDone()){
        // Game loop.
        game.update();
        game.render();
        game.restartClock();
    }
}
