#include "circle.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

tCircle::tCircle(float X, float Y, float R)
{
	setX(X);
	setY(Y);
	setR(R);
}

void tCircle::setR(float R)
{
	this->_R = R;
}

float tCircle::getR()
{
	return this->_R;
}

float tCircle::getTmpX(float fi)
{
	return getX() + (getR() * cos(grTOrad(fi)));
}

float tCircle::getTmpY(float fi)
{
	return getY() + (getR() * sin(grTOrad(fi)));
}

float tCircle::grTOrad(float Gr)
{
	return Gr * M_PI / 180;
}

void tCircle::move()
{
	this->setX(this->getX() + (this->getVecX() * 0.1));
	this->setY(this->getY() + (this->getVecY() * 0.1));
}

void tCircle::draw(sf::RenderWindow& window, sf::Color color1)
{
    sf::VertexArray lines(sf::Lines, 360 /*количество точек*/);
    
    for (size_t i = 0; i < 360; i+=2)
	{
        lines[i].position = sf::Vector2f(this->getTmpX(i), this->getTmpY(i));
        lines[i].color = color1;
        lines[i+1].position = sf::Vector2f(this->getTmpX(i+1), this->getTmpY(i+1));
        lines[i+1].color = color1;
	}
    window.draw(lines);
}
