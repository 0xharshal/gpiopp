#include "gpiopp.hpp"
#include "gpiochip.hpp"

int main() {
    
    gpiopp::gpiochip chip0("/dev/gpiochip0");
    chip0.get_name();
}