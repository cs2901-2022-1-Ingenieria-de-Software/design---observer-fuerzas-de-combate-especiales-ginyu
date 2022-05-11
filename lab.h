#ifndef LAB
#define LAB

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;


class Observer 
{
  protected:
  	//int id;
  	double T, P, H;
  
  public:
    Observer(){
        T = 0;
        P = 0;
        H = 0; 
    };

  	void update(double _T, double _P, double _H)
    {
      T = _T;
      P = _P;
			H = _H;
    };

    void display(){};
};


class Forecast : public Observer
{
	private:
  	    double R = 100;
  
};


class CConditions : public Observer
{
  private:
  	string weather = "soleado"; // soleado, nublado, etc
public:
    void display(){cout<< weather << " " << T << endl;}
};


class Statistics : public Observer
{
  private:
  	double media = (T + P + H)/3.0;
};


class DisplayDevice 
{
public:
  DisplayDevice(Forecast* f, CConditions* c, Statistics* s){
        obs.push_back(f);
        obs.push_back(c);
        obs.push_back(s);
    }
  void display(){
        for(int i = 0; i<obs.size(); i++){
            obs[i]->display();
        }
    }
private:
	string id;
  vector<Observer*> obs;
};


class Sensor 
{ 
public:
    Sensor(){};
    Sensor(string _id) : id(_id){}
    inline void cambiar(float _lectura){lectura = _lectura;}
    float get(){return lectura;}
  
private:
  float lectura = 0;
  string id;
};


class WeatherStation 
{
public:
  WeatherStation(){
    sensores["Humidity"] = Sensor("Humidity");
    sensores["Temperature"] = Sensor("Temperature");
    sensores["Pressure"] = Sensor("Pressure");
  }
  
  void cambiarHumedad(float _v){
    sensores["Humidity"].cambiar(_v);
    notify();
  }
  void cambiarTemperatura(float _v){
    sensores["Temperature"].cambiar(_v);
    notify();
	}
  void cambiarPresion(float _v){
    sensores["Pressure"].cambiar(_v);
    notify();
  }
  
  void add(Observer* d){
    displays.push_back(d);
  }
  void remove(Observer* d){
    displays.remove(d);
  }
  
  void notify(){
    double T = sensores["Temperature"].get();
    double P = sensores["Pressure"].get();
	double H = sensores["Humidity"].get();
    
    for(auto d = displays.begin(); d!=displays.end(); d++){
      (*d)->update(T, P, H);
    }
  }
  
private:
  unordered_map<string, Sensor> sensores;
  list<Observer*> displays;
};

#endif