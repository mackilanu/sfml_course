#include "Game.h"

Game::Game(): m_window("Chapter 2", sf::Vector2u(800, 600)) {
    m_mushroomTexture.loadFromFile("../assets/index.png");
    m_mushroom.setTexture(m_mushroomTexture);
    m_increment = sf::Vector2i(400, 400);
}

Game::~Game(){}

void Game::update()
{
    m_window.update();
    moveMushroom();
}

void Game::moveMushroom()
{
    sf::Vector2u l_windSize = m_window.getWindowsSize();
    sf::Vector2u l_textSize = m_mushroomTexture.getSize();

    if((m_mushroom.getPosition().x >
        l_windSize.x - l_textSize.x&&m_increment.x> 0) ||
       (m_mushroom.getPosition().x < 0 &&m_increment.x< 0)){
        m_increment.x = -m_increment.x;
    }

    if((m_mushroom.getPosition().y >
        l_windSize.y - l_textSize.y&&m_increment.y> 0) ||
       (m_mushroom.getPosition().y < 0 &&m_increment.y< 0)){
        m_increment.y = -m_increment.y;
    }

    float fElapsed = m_elapsed.asSeconds();
    m_mushroom.setPosition(
            m_mushroom.getPosition().x + (m_increment.x * fElapsed),
            m_mushroom.getPosition().y + (m_increment.y * fElapsed));

    std::cout << fElapsed << std::endl;
}

void Game::render()
{
    m_window.beginDraw();
    m_window.draw(m_mushroom);
    m_window.endDraw();
}

Window* Game::getWindow()
{
    return &m_window;
}

void moveMushroom() {};

void handleInput() {};

sf::Time Game::getElapsed()
{
    return m_elapsed;
}

void Game::restartClock()
{
    m_elapsed = m_clock.restart();
}