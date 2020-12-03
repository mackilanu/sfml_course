#include "Window.h"

Window::Window()
{
    setup("Window", sf::Vector2u(640, 480));
}

Window::Window(const std::string &l_title, const sf::Vector2u &l_size)
{
    setup(l_title, l_size);
}

Window::~Window()
{
    destroy();
}

void Window::setup(const std::string &l_title, const sf::Vector2u &l_size)
{
    m_windowTitle = l_title;
    m_WindowSize = l_size;
    m_isFullscreen = false;
    m_isDone = false;
    create();
}

void Window::create()
{
    auto style = (m_isFullscreen ? sf::Style::Fullscreen: sf::Style::Default);
    m_window.create({m_WindowSize.x, m_WindowSize.y, 32}, m_windowTitle, style);
    m_window.setFramerateLimit(60);
}

void Window::destroy()
{
    m_window.close();
}

void Window::update()
{
    sf::Event e;

    while (m_window.pollEvent(e)) {
        if(e.type == sf::Event::Closed) {
            m_isDone = true;
        } else if(e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::F5) {
            toggleFullscreen();
        }
    }
}

void Window::toggleFullscreen()
{
    m_isFullscreen = !m_isFullscreen;
    destroy();
    create();
}

void Window::beginDraw()
{
    m_window.clear(sf::Color::Black);
}

void Window::endDraw()
{
    m_window.display();
}

bool Window::isDone()
{
    return m_isDone;
}

bool Window::isFullscreen()
{
    return m_isFullscreen;
}

void Window::draw(sf::Drawable &l_drawable)
{
    m_window.draw(l_drawable);
}

sf::Vector2u Window::getWindowsSize()
{
    return m_window.getSize();
}

