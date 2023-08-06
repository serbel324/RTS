#include <driver/driver.h>
#include "example_frame.h"

int main() {
    std::unique_ptr<ExampleFrame> mainFrame = std::make_unique<ExampleFrame>();
    REngine::Driver driver(std::move(mainFrame), {});
    driver.Initialize();
    driver.Run();
}
