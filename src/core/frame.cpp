#include <core/frame.h>

namespace REngine {

Frame::Frame(Frame::Settings settings)
    : _settings(std::move(settings))
    , _window(std::make_shared<sf::RenderWindow>(
        sf::VideoMode(_settings.screenDimensions.x, _settings.screenDimensions.y), 
        _settings.name, 
        sf::Style::Close
    ))
    , _graphics(std::make_unique<Graphics>(_window, _settings.screenDimensions))
    , _inputController(std::make_unique<InputController>())
    , _isRunning(true)
{
    std::cout << _settings.screenDimensions << std::endl;
}

Graphics* Frame::Gr() {
    return _graphics.get();
}

InputController* Frame::Ic() {
    return _inputController.get();
}

void Frame::Render() {
    Gr()->Present();
}

bool Frame::Update(float) {
    PollEvents();
    return _isRunning;
}

void Frame::PollEvents() {
    sf::Event e;

    while (_window->pollEvent(e)) {
        switch (e.type) {
        case sf::Event::Closed:
            _window->close();
            _isRunning = false;
            break;

        default:
            Ic()->HandleEvent(e);
            break;
        }
    }
}

} // namespace REngine
