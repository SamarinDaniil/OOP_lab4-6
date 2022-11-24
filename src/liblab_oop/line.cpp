#include "line.hpp"
#include "tPoint.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

tLine::tLine() : tPoint()
{
    setX_2(getX() + 10 * getVecX());
    setY_2(getY() + 10 * getVecY());
    setRadius();
}

tLine::tLine(float x, float y, float x_2, float y_2) : tPoint(x, y)
{
    setX_2(x_2);
    setY_2(y_2);
    setRadius();
}

void tLine::setX_2(float x_2)
{
    this->_X_2 = x_2;
}

void tLine::setY_2(float y_2)
{
    this->_Y_2 = y_2;
}

void tLine::setRadius()
{
    this->_Radius = (sqrt(pow(abs(this->_X_2 - this->_x), 2) + pow(abs(this->_Y_2 - this->_y), 2))) / 2;
}

void tLine::setAngle()
{
	this->_Angle = atan(abs(this->_Y_2 - this->_y) / abs(this->_X_2 - this->_x));
}

float tLine::getX_2()
{
    return this->_X_2;
}

float tLine::getY_2()
{
    return this->_Y_2;
}

float tLine::getRadius()
{
    return this->_Radius;
}

float tLine::getAngle()
{
	return this->_Angle;
}

void tLine::rotate(float Gr)
{
	float Rad = this->grTOrad(Gr);
    float c = 0;
    if (this->_X_2 > this->_x) {
        c = this->_x;
    } else {
        c = this->_X_2;
    }
    this->_X_2 = c + (this->getRadius() * cos(this->getAngle() + Rad));
    this->_X_2 = c + (this->getRadius() * cos(M_PI + this->getAngle() + Rad));
    if (this->_Y_2 > this->_y) {
        c = this->_y;
    } else {
        c = this->_Y_2;
    }
    this->_Y_2 = c + (this->getRadius() * sin(this->getAngle() + Rad));
    this->_y = c +(this->getRadius() * sin(M_PI + this->getAngle() + Rad));
}

float tLine::grTOrad(float Gr)
{
	return Gr * M_PI / 180;
}

void tLine::move()
{
	this->setX(this->getX() + (this->getVecX() * 0.1));
	this->setY(this->getY() + (this->getVecY() * 0.1));
    this->setX_2(this->getX_2() + (this->getVecX() * 0.1));
	this->setY_2(this->getY_2() + (this->getVecY() * 0.1));
}

void tLine::draw (sf::RenderWindow& window, sf::Color color) 
{
    sf::Vertex tline[] =
    {
        sf::Vertex(sf::Vector2f(this->_x, this->_y), color),
        sf::Vertex(sf::Vector2f(this->_X_2, this->_Y_2), color)
    };
    window.draw(tline, 2, sf::Lines);
}