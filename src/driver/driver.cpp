#include <driver/driver.h>
#include <cassert>
#include <chrono>
#include <ctime>
#include <iostream>

namespace REngine {

Driver::Driver(std::unique_ptr<Frame>&& mainFrame, Settings settings)
    : _mainFrame(std::move(mainFrame))
    , _settings(settings)
{
    assert(_mainFrame);
}

void Driver::Initialize() {
    _mainFrame->Initialize();
}

void Driver::Run() {
    using SystemClock = std::chrono::system_clock;
    using Timestamp = std::chrono::time_point<SystemClock>;
    Timestamp startTime = SystemClock::now();

    while (true) {
        Timestamp currentTime = SystemClock::now();
        int64_t elapsedUs = std::chrono::duration_cast<std::chrono::microseconds>(currentTime - startTime).count();
        float elapsedMs = 0.001 * elapsedUs;
        startTime = currentTime;

        if (!_mainFrame->Update(elapsedMs)) {
            break;
        }
        _mainFrame->Render();
    }
}


} // namespace REngine