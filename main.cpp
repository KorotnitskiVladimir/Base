//
//  main.cpp
//  Base
//
//  Created by Коротницкий Владимир on 15.07.2024.
//

#include <iostream>
#include "Base.hpp"
#include "Bus.hpp"
#include "Truck.hpp"

int main(int argc, const char * argv[]) {
    Base base;
    Bus bus(200, 200, 100, 0, 45);
    bus.arrive();
    bus.leave();
    Truck t(500, 700, 400, 100, 14000);
    t.arrive();
    t.leave();
    cout << Base::petrolOnBase << " " << Base::peopleOnBase << " " << Base::goodsOnBase << " " << Base::vehiclesOnBase << endl;
    cout << bus.getTank() << " " << bus.getPetrol() << " " << bus.getPeople() << endl;
    cout << t.getCurrentLoad() << " " << t.getPetrol() << endl;
    
    return 0;
}
