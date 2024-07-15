//
//  Truck.cpp
//  Base
//
//  Created by Коротницкий Владимир on 15.07.2024.
//

#include "Truck.hpp"
#include <iostream>

Truck::Truck()
{
    petrolAmount = tankVolume = consumption = load = maxLoad = 0;
}

Truck::Truck(double p, double t, double c, double l, double m): Vehicle(p, t, c)
{
    load = l;
    maxLoad = m;
}

void Truck::setCurrentLoad(double l)
{
    if (maxLoad!=0)
        if (l>=0 && l<=maxLoad)
            load = l;
}

void Truck::setMaxLoad(double m)
{
    if (m>0)
        maxLoad = m;
}

double Truck::getCurrentLoad() const
{
    return load;
}

double Truck::getMaxLoad() const
{
    return maxLoad;
}

void Truck::arrive()
{
    Vehicle::arrive();
    Base::goodsOnBase+=load;
    load = 0;
}

bool Truck::leave()
{
    if (Vehicle::leave()==true)
    {
        if (Base::goodsOnBase>=maxLoad)
        {
            load = maxLoad;
            Base::goodsOnBase-=maxLoad;
        }
        else
        {
            load = Base::goodsOnBase;
            Base::goodsOnBase-=load;
        }
        return true;
    }
    else
        return false;
}
