#include "lab.h"

int main(){
    WeatherStation* station = new WeatherStation();

    Forecast* forecast = new Forecast();
    CConditions* conditions = new CConditions();
    Statistics* statistics = new Statistics();

    station->add(forecast);
    station->add(conditions);
    station->add(statistics);
    
    station->cambiarHumedad(100);
    station->cambiarPresion(140);
    station->cambiarTemperatura(200);

    DisplayDevice* device = new DisplayDevice(forecast, conditions, statistics);
    device->display();
}