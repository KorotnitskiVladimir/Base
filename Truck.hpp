//
//  Truck.hpp
//  Base
//
//  Created by Коротницкий Владимир on 15.07.2024.
//

#ifndef Truck_hpp
#define Truck_hpp

#include <stdio.h>
#include "Vehicle.hpp"
#include "Base.hpp"

class Truck:public Vehicle
{
private:
    double load;
    double maxLoad;
public:
    Truck();
    Truck(double p, double t, double c, double l, double m);
    void setCurrentLoad(double l);
    void setMaxLoad(double m);
    double getCurrentLoad() const;
    double getMaxLoad() const;
    void arrive();
    bool leave();
};

#endif /* Truck_hpp */
