#include "iostream"
#include "string"
#include "sstream"
#include "string_view"
#include "cerrno"
#include "cstring"
#include "stdexcept"

#include "unistd.h"
#include "fcntl.h"
#include "sys/ioctl.h"
#include "linux/gpio.h"

#include "gpiochip.hpp"

namespace gpiopp
{
    gpiochip::gpiochip(const std::string& device_name) {
        this->device_name = device_name;
        update();
    }
    void gpiochip::update() {
        int fd = open(device_name.c_str(), 0);

        if (fd < 0) {
            std::stringstream err_str;
            err_str << "Could not open " << device_name << " as gpiochip. errno: " << errno << " interpretation: " << std::strerror(errno) << std::endl;
            throw std::runtime_error(err_str.str());
        }

        int ret = ioctl(fd, GPIO_GET_CHIPINFO_IOCTL, &cinfo);

        if (ret < 0) {
            std::stringstream err_str;
            err_str << "Failed to issue CHIPINFO IOCTL. errno: " << errno << " interpretation: " << std::strerror(errno) << std::endl;
            close(fd);
            throw std::runtime_error(err_str.str());
        }
        close(fd);
    }

    // const std::string gpiochip::get_name() {
    //     return cinfo.name;
    // }

    // const std::string gpiochip::get_label() {
    //     return cinfo.label;
    // }

    // const u_int32_t gpiochip::lines() {
    //     return cinfo.lines;
    // }
} // gpiopp