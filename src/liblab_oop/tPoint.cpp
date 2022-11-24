#include "tPoint.hpp"
#include "../lab_oop/main.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

tPoint::tPoint()
{
    srand(time(NULL) * rand());
    setX(rand() % 400 + 100);
    setY(rand() % 400 + 100);
    setVecX(5 * pow(-1, rand() % 2));
    setVecY(5 * pow(-1, rand() % 2));
    setSize(5);
}

tPoint::tPoint(float x, float y)
{
    srand(time(NULL) * rand());
    setX(x);
    setY(y);
    setVecX(5 * pow(-1, rand() % 2));
    setVecY(5 * pow(-1, rand() % 2));
    setSize(5);
}

void tPoint::setX(float x)
{
    this->_x = x;
}

void tPoint::setY(float y)
{
    this->_y = y;
}

void tPoint::setSize(float size)
{
    this->_size = size;
}

float tPoint::getX()
{
    return this->_x;
}

float tPoint::getY()
{
    return this->_y;
}

float tPoint::getSize()
{
    return this->_size;
}

void tPoint::setVecX(float vecX)
{
    this->_vecX = vecX;
}

void tPoint::setVecY(float vecY)
{
    this->_vecY = vecY;
}

float tPoint::getVecX()
{
    return this->_vecX;
}

float tPoint::getVecY()
{
    return this->_vecY;
}

void tPoint::move()
{
    this->setX(this->getX() + this->getVecX() * 0.1);
    this->setY(this->getY() + this->getVecY() * 0.1);
}

void tPoint::draw(sf::RenderWindow& window, sf::Color color)
{
    sf::CircleShape circle;
    circle.setFillColor(color);
    circle.setRadius(this->_size);
    circle.setPosition(this->_x, this->_y);
    window.draw(circle);
}