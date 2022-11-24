#ifndef POINT_H
#define POINT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class tPoint {
protected:
    float _x;
    float _y;
    float _size;

    float _vecX;
    float _vecY;

public:
    tPoint();
    tPoint(float x, float y);

    void setX(float x);
    void setY(float y);
    void setSize(float size);

    float getX();
    float getY();
    float getSize();

    void setVecX(float vecX);
    void setVecY(float vecY);
    float getVecX();
    float getVecY();

    virtual void move();
    virtual void draw(sf::RenderWindow& window, sf::Color color);
};

#endif