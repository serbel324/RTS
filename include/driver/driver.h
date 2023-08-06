#pragma once
#include <vector>
#include <string>

#include <core/frame.h>
#include <memory>

namespace REngine {

class Driver {

public:
    struct Settings {
        std::string mainFrameConfigPath;
    };

public:

    Driver(std::unique_ptr<Frame>&& mainFrame, Settings settings = {});

    void Initialize();
    void Run();

private:
    Settings _settings;
    std::unique_ptr<Frame> _mainFrame;

};

} // namespace REngine
