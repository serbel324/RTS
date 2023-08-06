#include <core/frame.h>
#include <core/color.h>
#include <library/vec2.h>

#include <iostream>

class ExampleFrame : public REngine::Frame {
public:
    ExampleFrame()
        : Frame(REngine::Frame::Settings{
            .name = "Example App",
            .screenDimensions = {800, 800},
        })
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
