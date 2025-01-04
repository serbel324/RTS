#include <rengine/sfml_implementation/sfml_frame.h>
#include <rengine/core/color.h>
#include <library/vec2.h>

#include <iostream>

class ExampleFrame : public REngine::SFMLFrame {
public:
    ExampleFrame()
        : SFMLFrame(
            Frame::Settings{
                .screen_size = {800, 800},
                .window_name = "MainFrame",
            })
    {}

    virtual void Initialize() override {
        std::cout << "Initialize Frame" << std::endl;
    }

    bool Update(float elapsed_sec) override {
        return Frame::Update(elapsed_sec);
    }

    void Render() override {
        Gr()->Fill(REngine::Color::WHITE);
        Gr()->DrawCircle(Ic()->GetMousePosition(), 10, REngine::Color::BLACK);
        Frame::Render();
    }

};
