#include "iostream"

#include "gpiopp.hpp"
#include "gpiochip.hpp"

int main() {
    
    gpiopp::gpiochip chip0("/dev/gpiochip0");
    std::cout << "chip.name: " << chip0.get_name() << std::endl;
    std::cout << "chip.label: " << chip0.get_label() << std::endl;
    std::cout << "chip.lines: " << chip0.lines() << std::endl;
}