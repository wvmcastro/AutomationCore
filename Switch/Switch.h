#ifndef __SWITCH_H
#define __SWITCH_H
#include <Arduino.h>
#include <string>

class Switch
{
  public:
    Switch(int pin, const char* name="SW", bool initial_state=LOW): 
          _pin{pin}, _name{name}
    {
        pinMode(_pin, OUTPUT);
        _state = initial_state;
        digitalWrite(_pin, initial_state);   
    }
    
    void on()
    {
        ESP_LOGI("SW", "Switch %s ON\n", _name.c_str());
        digitalWrite(_pin, HIGH);
        _state = HIGH;
    }

    void off()
    {
        ESP_LOGI("SW", "Switch %s OFF\n", _name.c_str());
        digitalWrite(_pin, LOW);
        _state = LOW;
    }

    void toggle()
    {
        ESP_LOGI("SW", "Switch %s TOGGLED\n", _name.c_str());
        _state = !_state;
        digitalWrite(_pin, _state);
    }

    bool state()
    {
        return _state;
    }

  private:
    const int _pin;
    std::string _name;
    bool _state;
};
#endif // __SWITCH_H