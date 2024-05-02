#include <rengine/core/frame.h>
#include <rengine/core/color.h>
#include <library/vec2.h>

#include <iostream>

class ExampleFrame : public REngine::Frame {
public:
    ExampleFrame()
        : Frame(
            Frame::Settings{
                .id = "MainFrame",
                .screenSize = {800, 800},
            },
            nullptr,
            REngine::MakeGenericWindow({800, 800}, "Demo app"))
    {}

    void Initialize() override {
        std::cout << "Initialize Frame" << std::endl;
    }

    bool Update(float elapsedMs) override {
        return Frame::Update(elapsedMs);
    }

    void Render() override {
        Gr()->SetFillColor(REngine::Color::WHITE);
        Gr()->Fill();

        Gr()->SetFillColor(REngine::Color::BLACK);
        Gr()->DrawCircle(Ic()->mousePosition, 10);
        Frame::Render();
    }

};
