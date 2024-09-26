#include <iostream>
#include "TwoDVector.h"

int main() {
    sf::RenderWindow window({570, 320, 32}, "SFML 2D Array");
    window.setFramerateLimit(60);

    TwoDVector test;

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                window.close();
            test.eventHandler(window, event);
        }
        window.clear();
        test.changeColors();
        window.draw(test);
        window.display();
    }
    return 0;
}
