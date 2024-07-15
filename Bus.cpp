//
//  Bus.cpp
//  Base
//
//  Created by Коротницкий Владимир on 15.07.2024.
//

#include "Bus.hpp"
#include <iostream>

Bus::Bus()
{
    petrolAmount = tankVolume = consumption = people = maxPeople = 0;
}

Bus::Bus(double p, double t, double c, int ppl, int m): Vehicle(p, t, c)
{
    people = ppl;
    maxPeople = m;
}

void Bus::setPeople(int p)
{
    if (maxPeople == 0)
        cout << "please set capacity first" << endl;
    else
    {
        if (p>=0 && p<=maxPeople)
            people = p;
        else
            cout << "value out of allowed range" << endl;
    }
}

void Bus::setMaxPeople(int m)
{
    if (m>0)
        maxPeople = m;
}

int Bus::getPeople() const
{
    return people;
}

int Bus::getMaxPeople() const
{
    return maxPeople;
}

void Bus::arrive()
{
    Vehicle::arrive();
    Base::peopleOnBase+=people;
    people = 0;
}

bool Bus::leave()
{
    if (Vehicle::leave()==true)
    {
        if (Base::peopleOnBase>=maxPeople)
        {
            people = maxPeople;
            Base::peopleOnBase-=maxPeople;
        }
        else
        {
            people = Base::peopleOnBase;
            Base::peopleOnBase-=people;
        }
        return true;
    }
    else
        return false;
}
