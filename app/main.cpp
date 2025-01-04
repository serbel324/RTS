#include <rengine/core/driver.h>
#include "example_frame.h"
#include <memory>

int main() {
    REngine::Driver driver(std::unique_ptr<REngine::Frame>(new ExampleFrame), {});
    driver.RunFrame();
}
