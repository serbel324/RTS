#pragma once
#include <memory>
#include <string>

#include <core/graphics.h>
#include <core/input.h>
#include <library/vec2.h>

#include <SFML/Graphics.hpp>

namespace REngine {

class Frame {
public:
    struct Settings {
        std::string name;
        Vec2<size_t> screenDimensions;
    };

public:
    Frame(Settings settings);

    virtual void Initialize() = 0;
    virtual bool Update(float elapsedMs);
    virtual void Render();
    virtual void PollEvents();

    virtual ~Frame() = default;

protected:
    Graphics* Gr();
    InputController* Ic();

private:
    Settings _settings;
    std::shared_ptr<sf::RenderWindow> _window;

    std::unique_ptr<Graphics> _graphics;
    std::unique_ptr<InputController> _inputController;
    
    bool _isRunning;
};

} // namespace REngine
