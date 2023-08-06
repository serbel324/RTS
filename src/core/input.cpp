#include <core/input.h>

namespace REngine {

void InputController::HandleEvent(sf::Event event) {
    switch (event.type)
    {
    case sf::Event::KeyPressed:
        KeyPressed(event.key);
        KeyPressed(event.key);
        break;
    case sf::Event::KeyReleased:
        KeyPressed(event.key);
        break;
    case sf::Event::MouseButtonPressed:
        MousePressed(event.mouseButton);
        break;
    case sf::Event::MouseButtonReleased:
        MouseReleased(event.mouseButton);
        break;
    case sf::Event::MouseMoved:
        MouseMoved(event.mouseMove);
        break;
    default:
        break;
    }
}

void InputController::KeyPressed(sf::Event::KeyEvent& event)
{
    switch (event.code) {
    case sf::Keyboard::W:
        w = true;
        break;
    case sf::Keyboard::A:
        a = true;
        break;
    case sf::Keyboard::S:
        s = true;
        break;
    case sf::Keyboard::D:
        d = true;
        break;
    case sf::Keyboard::Space:
        space = true;
        break;
    default:
        break;
    }
}

void InputController::KeyReleased(sf::Event::KeyEvent& event)
{
    switch (event.code) {
    case sf::Keyboard::W:
        w = false;
        break;
    case sf::Keyboard::A:
        a = false;
        break;
    case sf::Keyboard::S:
        s = false;
        break;
    case sf::Keyboard::D:
        d = false;
        break;
    case sf::Keyboard::Space:
        space = false;
        break;
    default:
        break;
    }
}

void InputController::MouseMoved(sf::Event::MouseMoveEvent& event)
{
    mousePosition.Set(event.x, event.y);
}

void InputController::MousePressed(sf::Event::MouseButtonEvent& event)
{
    switch (event.button) {
    case sf::Mouse::Left:
        lmb = true;
        break;
    case sf::Mouse::Right:
        rmb = true;
        break;
    default:
        break;
    }
}

void InputController::MouseReleased(sf::Event::MouseButtonEvent& event)
{
    switch (event.button) {
    case sf::Mouse::Left:
        lmb = false;
        break;
    case sf::Mouse::Right:
        rmb = false;
        break;
    default:
        break;
    }
}

} // namespace REngine
