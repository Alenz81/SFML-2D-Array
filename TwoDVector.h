//
// Created by super on 2/28/2023.
//

#ifndef SFML_2D_ARRAY_TWODVECTOR_H
#define SFML_2D_ARRAY_TWODVECTOR_H
#include <SFML/Graphics.hpp>
#include <ctime>

class TwoDVector : public sf::Drawable
{
private:
    int rows, cols;
    sf::RectangleShape** arr;
    //dynamically create an array of current row and col size
    sf::RectangleShape** createArray();

    //fills the array with sf::RectangleShapes
    void fillArray();

    //returns a rectangle shape that is positioned at x and y
    sf::RectangleShape newRectangleShape(float x, float y);

    //deletes the arr
    void deleteArray();
public:
    ////Big Three Goes here
    TwoDVector();
    TwoDVector(TwoDVector &vector);
    ~TwoDVector();

    //loop through 2D array and draw each rectangle
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //increases the array size when right arrow is pressed, decreases when left is pressed
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void changeColors();
};


#endif //SFML_2D_ARRAY_TWODVECTOR_H
