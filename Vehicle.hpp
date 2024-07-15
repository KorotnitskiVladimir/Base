//
//  Vehicle.hpp
//  Base
//
//  Created by Коротницкий Владимир on 15.07.2024.
//

#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <stdio.h>
#include "Base.hpp"

using namespace std;

class Vehicle
{
protected:
    double petrolAmount;
    double tankVolume;
    double consumption;
public:
    Vehicle();
    Vehicle(double p, double t, double c);
    void setPetrol(double p);
    void setTank(double t);
    void setConsumption(double c);
    double getPetrol() const;
    double getTank() const;
    double getConsumption() const;
    void arrive();
    bool leave();
};

#endif /* Vehicle_hpp */
