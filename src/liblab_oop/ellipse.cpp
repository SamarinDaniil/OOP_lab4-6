#include "ellipse.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

tEllipse::tEllipse(float A, float B)
{
	setA(A);
	setB(B);
}

void tEllipse::setA(float A)
{
	this->_A = A;
}

void tEllipse::setB(float B)
{
	this->_B = B;
}

void tEllipse::setAngle(float Angle)
{
	this->_Angle = grTOrad(Angle);
}

void tEllipse::setR()
{
	this->_R = (getA() * getB()) / (sqrt(pow(getB(), 2) * pow(cos(getAngle()), 2) + pow(getA(), 2) * pow(sin(getAngle()), 2)));
}

void tEllipse::settX()
{
	this->_tX = getX() + (getR() * cos(getAngle() + getfi()));
}

void tEllipse::settY()
{
	this->_tY = getY() + (getR() * sin(getAngle() + getfi()));
}

float tEllipse::getA()
{
	return this->_A;
}

float tEllipse::getB()
{
	return this->_B;
}

float tEllipse::getR()
{
	return this->_R;
}

float tEllipse::getAngle()
{
	return this->_Angle;
}

float tEllipse::gettX()
{
	return this->_tX;
}

float tEllipse::gettY()
{
	return this->_tY;
}

float tEllipse::grTOrad(float Gr)
{
	return Gr * M_PI / 180;
}

void tEllipse::move()
{
	this->setX(this->getX() + (this->getVecX() * 0.01));
	this->setY(this->getY() + (this->getVecY() * 0.01));
	settX();
	settY();
}

void tEllipse::setfi(float fi)
{
	this->_fi = fi;
}

float tEllipse::getfi()
{
	return this->_fi;
}

void tEllipse::rotate(float Gr)
{
	float Rad = this->grTOrad(Gr);
	setfi(Rad);
}

void tEllipse::draw(sf::RenderWindow& window, sf::Color color1)
{
    sf::VertexArray lines(sf::Lines, 360 /*количество точек*/);
    for (size_t i = 0; i < 360; i+=2)
	{
		this->setAngle(i);
		this->setR();
		this->settX();
		this->settY();
        lines[i].position = sf::Vector2f(this->gettX(), this->gettY());
        lines[i].color = color1;
        this->setAngle(i + 1);
        this->setR();
		this->settX();
		this->settY();
        lines[i+1].position = sf::Vector2f(this->gettX(), this->gettY());
        lines[i+1].color = color1;
	}
    window.draw(lines);
}
