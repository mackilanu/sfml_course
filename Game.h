//
// Created by marcus on 12/2/20.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "Window.h"

class Game {
public:
    Game();
    ~Game();

    void handleInput();
    void update();
    void render();
    Window* getWindow();

    sf::Time getElapsed();
    void restartClock();

private:
    void moveMushroom();
    Window m_window;
    sf::Texture m_mushroomTexture;
    sf::Sprite m_mushroom;
    sf::Vector2i m_increment;
    sf::Clock m_clock;
    sf::Time m_elapsed;
};

#endif //GAME_GAME_H
