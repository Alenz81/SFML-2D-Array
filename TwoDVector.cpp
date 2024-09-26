//
// Created by super on 2/28/2023.
//

#include "TwoDVector.h"

TwoDVector::TwoDVector() : rows(1), cols(1), arr(createArray()){}


TwoDVector::TwoDVector(TwoDVector& vector){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            *(*(arr + i) + j) = *(*(vector.arr + i) + j);
        }
    }
}

TwoDVector::~TwoDVector(){
    deleteArray();
}

sf::RectangleShape** TwoDVector::createArray() {
    deleteArray();
    arr = new sf::RectangleShape*[rows];
    for (int i = 0; i < cols; ++i) {
        *(arr + i) = new sf::RectangleShape[cols];
    }
    fillArray();
    return arr;
}

void TwoDVector::fillArray() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            *(*(arr + i) + j) = newRectangleShape(i, j);
        }
    }
}

sf::RectangleShape TwoDVector::newRectangleShape(float x, float y) {
    sf::Vector2f size(10/4, 5.625/4);
    sf::Vector2f pos(x * 10/4, y * 5.625/4);
    sf::RectangleShape rectangle(size);
    rectangle.setPosition(pos);
    return rectangle;
}

void TwoDVector::deleteArray() {
    for (int i = 0; i < cols; ++i) {
        delete [](arr);
    }
    delete []arr;
}

void TwoDVector::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            window.draw(*(*(arr + i) + j), states);
        }
    }
}

void TwoDVector::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && rows < 231){
        rows++;
        cols++;
        createArray();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && rows > 0){
        rows--;
        cols--;
        createArray();
    }
}

void TwoDVector::changeColors(){
    int r, g, b;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            r = rand()%252;
            g = rand()%252;
            b = rand()%252;
            (*(*(arr + i) + j)).setFillColor(sf::Color(r, g, b));
        }
    }
}
