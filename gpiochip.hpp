#ifndef GPIOCHIP_HPP_
#define GPIOCHIP_HPP_

#include "string"
#include "string_view"

#include "fcntl.h"
#include "sys/ioctl.h"
#include "linux/gpio.h"

namespace gpiopp
{
    /**
     * @brief Represents linux kernel gpiochip device
     * 
     * 
     */
    class gpiochip
    {
        std::string device_name;
        struct gpiochip_info cinfo;
    public:
        gpiochip(const std::string& device_name);
        void update();
        inline const std::string get_name() { return cinfo.name; }
        inline const std::string get_label() { return cinfo.label; }
        inline const u_int32_t lines() { return cinfo.lines; }
    };

} // GPIOPP

#endif // GPIOCHIP_HPP_