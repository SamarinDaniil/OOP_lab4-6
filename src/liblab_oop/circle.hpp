#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "tPoint.hpp"

class tCircle : public tPoint
{
	private:
		float _R;
	public:
		tCircle(float X, float Y, float R);

		void setR(float R);
		float getR();

		float getTmpX(float fi);
		float getTmpY(float fi);
		float grTOrad(float Gr);

		void move() override;
		void draw(sf::RenderWindow& window, sf::Color color) override;
};

#endif
