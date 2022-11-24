#ifndef LINE_H
#define LINE_H

#include "tPoint.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

class tLine : public tPoint {
private:
    float _X_2;
    float _Y_2;

    float _Radius;
    float _Angle;

public:
    tLine();
    tLine(float x, float y, float x_2, float y_2);

    void setX_2(float x_2);
    void setY_2(float y_2);
    void setRadius();
    void setAngle();

    float getX_2();
    float getY_2();
    float getRadius();
    float getAngle();
    		
    float grTOrad(float Gr);
	void rotate(float Gr);
	void move() override;
    void draw(sf::RenderWindow& window, sf::Color color) override;
};

#endif