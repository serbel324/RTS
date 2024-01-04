#include <driver/driver.h>
#include "example_frame.h"

int main() {
    REngine::Driver::Promote(std::make_unique<REngine::SingleFrameDriver>(
            std::make_unique<ExampleFrame>(),
            REngine::SingleFrameDriver::Settings{ .minimumUpdateDelayMs = 0 } ));
    REngine::Driver::King()->Initialize();
    REngine::Driver::King()->Run();
}
