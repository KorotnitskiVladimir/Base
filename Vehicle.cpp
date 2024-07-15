//
//  Vehicle.cpp
//  Base
//
//  Created by Коротницкий Владимир on 15.07.2024.
//

#include "Vehicle.hpp"
#include <iostream>

Vehicle::Vehicle()
{
    petrolAmount = tankVolume = consumption = 0;
}

Vehicle::Vehicle(double p, double t, double c)
{
    petrolAmount = p;
    tankVolume = t;
    consumption = c;
}

void Vehicle::setPetrol(double p)
{
    if (tankVolume == 0)
        cout << "you should set tank volume first" << endl;
    else
    {
        if (p>=0 && p<=tankVolume)
            petrolAmount = p;
        else
            cout << "value out of allowed range" << endl;
    }
}

void Vehicle::setTank(double t)
{
    if (t>0)
        tankVolume = t;
}

void Vehicle::setConsumption(double c)
{
    if (tankVolume!=0 && consumption!=0)
        if (c>0 && c<=petrolAmount)
            consumption = c;
}

double Vehicle::getPetrol() const
{
    return petrolAmount;
}

double Vehicle::getTank() const
{
    return tankVolume;
}

double Vehicle::getConsumption() const
{
    return consumption;
}

void Vehicle::arrive()
{
    petrolAmount-=consumption;
    Base::petrolOnBase+=petrolAmount;
    petrolAmount = 0;
    Base::vehiclesOnBase++;
    Base::peopleOnBase++;
}

bool Vehicle::leave()
{
    if (Base::petrolOnBase>=tankVolume && Base::peopleOnBase>0)
    {
        petrolAmount = tankVolume;
        Base::petrolOnBase-=tankVolume;
        Base::peopleOnBase--;
        Base::vehiclesOnBase--;
        return true;
    }
    else
        return false;
}
