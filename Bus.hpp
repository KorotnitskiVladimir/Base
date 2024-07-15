//
//  Bus.hpp
//  Base
//
//  Created by Коротницкий Владимир on 15.07.2024.
//

#ifndef Bus_hpp
#define Bus_hpp

#include <stdio.h>
#include "Vehicle.hpp"
#include "Base.hpp"

class Bus:public Vehicle
{
private:
    int people;
    int maxPeople;
public:
    Bus();
    Bus(double p, double t, double c, int ppl, int m);
    void setPeople(int p);
    void setMaxPeople(int m);
    int getPeople() const;
    int getMaxPeople() const;
    void arrive();
    bool leave();
};

#endif /* Bus_hpp */
