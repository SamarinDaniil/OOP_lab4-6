#include "main.hpp"
#include "../liblab_oop/circle.hpp"
#include "../liblab_oop/ellipse.hpp"
#include "../liblab_oop/line.hpp"
#include "../liblab_oop/rhombus.hpp"
#include "../liblab_oop/tPoint.hpp"
#include "../liblab_oop/tRectangle.hpp"
#include "../liblab_oop/triangle.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
#include <cmath>

using namespace std;
using namespace sf;



void work(int figur, int action, RenderWindow& window, Color color, tPoint *figure[7])
{
    switch (figur) {
        case 0:
            switch (action) {
            case 0: {
                // случайное движение с отражением.
                if (figure[0]->getX() <= 10 || figure[0]->getX() >= 590) {
                    figure[0]->setVecX(figure[0]->getVecX() * -1);
                } else {
                    figure[0]->setVecX(figure[0]->getVecX() * pow(-1, rand() % 2));
                }
                if (figure[0]->getY() <= 10 || figure[0]->getY() >= 590) {
                    figure[0]->setVecY(figure[0]->getVecY() * -1);
                } else {
                    figure[0]->setVecY(figure[0]->getVecY() * pow(-1, rand() % 2));
                }
                break;
            }
            case 2: case 1: {
                // Прямолинейное движение с отражением от стенок экрана.
                if (figure[0]->getX() <= 10 || figure[0]->getX() >= 590)
                    figure[0]->setVecX(figure[0]->getVecX() * -1);
                if (figure[0]->getY() <= 10 || figure[0]->getY() >= 590)
                    figure[0]->setVecY(figure[0]->getVecY() * -1);
            }
            default:
                break;
            }
        figure[0]->move();
        figure[0]->draw(window, color);
        break;
    case 1:
            if (figure[1]->getX() <= 10 || figure[1]->getX() >= 590)
                    figure[0]->setVecX(figure[1]->getVecX() * -1);
            if (figure[1]->getY() <= 10 || figure[1]->getY() >= 590)
                    figure[1]->setVecY(figure[1]->getVecY() * -1);
        figure[1]->move();
        figure[1]->draw(window, color);
        break;
    case 2:
        for (size_t i = 0; i < 360; i++) {
            if (static_cast<tRectangle*>(figure[2])->getXtl() < 0 || static_cast<tRectangle*>(figure[2])->getXtr() < 0 || static_cast<tRectangle*>(figure[2])->getXbl() < 0
                || static_cast<tRectangle*>(figure[2])->getXbr() < 0)
                static_cast<tRectangle*>(figure[2])->setVecX(-1 * static_cast<tRectangle*>(figure[2])->getVecX());
            if (static_cast<tRectangle*>(figure[2])->getYtl() < 0 || static_cast<tRectangle*>(figure[2])->getYtr() < 0 || static_cast<tRectangle*>(figure[2])->getYbl() < 0
                || static_cast<tRectangle*>(figure[2])->getYbr() < 0)
                static_cast<tRectangle*>(figure[2])->setVecY(-1 * static_cast<tRectangle*>(figure[2])->getVecY());
            if (static_cast<tRectangle*>(figure[2])->getXtl() > win_size || static_cast<tRectangle*>(figure[2])->getXtr() > win_size
                || static_cast<tRectangle*>(figure[2])->getXbl() > win_size || static_cast<tRectangle*>(figure[2])->getXbr() > win_size)
                static_cast<tRectangle*>(figure[2])->setVecX(-1 * static_cast<tRectangle*>(figure[2])->getVecX());
            if (static_cast<tRectangle*>(figure[2])->getYtl() > win_size || static_cast<tRectangle*>(figure[2])->getYtr() > win_size
                || static_cast<tRectangle*>(figure[2])->getYbl() > win_size || static_cast<tRectangle*>(figure[2])->getYbr() > win_size)
                static_cast<tRectangle*>(figure[2])->setVecY(-1 * static_cast<tRectangle*>(figure[2])->getVecY());
            switch (action) {
            case 0:
                static_cast<tRectangle*>(figure[2])->move();
                break;
            case 1:
                static_cast<tRectangle*>(figure[2])->rotate(i);
                break;
            case 2:
                static_cast<tRectangle*>(figure[2])->move();
                static_cast<tRectangle*>(figure[2])->rotate(i);
                break;
            }
        }
        static_cast<tRectangle*>(figure[2])->draw(window, color);
        break;
    case 3:
        for (size_t i = 0; i < 360; i++) {
            if (static_cast<tTriangle*>(figure[3])->getV1X() < 0 || static_cast<tTriangle*>(figure[2])->getV2X() < 0 || static_cast<tTriangle*>(figure[3])->getV3X() < 0)
                static_cast<tTriangle*>(figure[3])->setVecX(-1 * static_cast<tTriangle*>(figure[3])->getVecX());
            if (static_cast<tTriangle*>(figure[3])->getV1Y() < 0 || static_cast<tTriangle*>(figure[3])->getV2Y() < 0 || static_cast<tTriangle*>(figure[3])->getV3Y() < 0)
                static_cast<tTriangle*>(figure[3])->setVecY(-1 * static_cast<tTriangle*>(figure[3])->getVecY());
            if (static_cast<tTriangle*>(figure[3])->getV1X() > win_size || static_cast<tTriangle*>(figure[3])->getV2X() > win_size
                || static_cast<tTriangle*>(figure[3])->getV3X() > win_size)
                static_cast<tTriangle*>(figure[3])->setVecX(-1 * static_cast<tTriangle*>(figure[3])->getVecX());
            if (static_cast<tTriangle*>(figure[3])->getV1Y() > win_size || static_cast<tTriangle*>(figure[3])->getV2Y() > win_size
                || static_cast<tTriangle*>(figure[3])->getV3Y() > win_size)
                static_cast<tTriangle*>(figure[3])->setVecY(-1 * static_cast<tTriangle*>(figure[3])->getVecY());
            switch (action) {
            case 0:
                static_cast<tTriangle*>(figure[3])->move();
                break;
            case 1:
                static_cast<tTriangle*>(figure[3])->rotate(i);
                break;
            case 2:
                static_cast<tTriangle*>(figure[3])->move();
                static_cast<tTriangle*>(figure[3])->rotate(i);
                break;
            }
        }
        //static_cast<tTriangle*>(figure[3])->rotate(rand()%200);
        static_cast<tTriangle*>(figure[3])->draw(window, color);
        break;
    case 4:
        if (static_cast<tCircle*>(figure[4])->getR() > static_cast<tCircle*>(figure[4])->getX() || static_cast<tCircle*>(figure[4])->getR() > (win_size - static_cast<tCircle*>(figure[4])->getX()))
            static_cast<tCircle*>(figure[4])->setVecX(-1 * static_cast<tCircle*>(figure[4])->getVecX());
        if (static_cast<tCircle*>(figure[4])->getR() > static_cast<tCircle*>(figure[4])->getY() || static_cast<tCircle*>(figure[4])->getR() > (win_size - static_cast<tCircle*>(figure[4])->getY()))
            static_cast<tCircle*>(figure[4])->setVecY(-1 * static_cast<tCircle*>(figure[4])->getVecY());
        static_cast<tCircle*>(figure[4])->move();
        static_cast<tCircle*>(figure[4])->draw(window, color);
        break;
    case 5:
        for (size_t i = 0; i < 360; i++) {
            if (static_cast<tRhombus*>(figure[5])->getXtl() < 0 || static_cast<tRhombus*>(figure[5])->getXtr() < 0 || static_cast<tRhombus*>(figure[5])->getXbl() < 0
                || static_cast<tRhombus*>(figure[5])->getXbr() < 0)
                static_cast<tRhombus*>(figure[5])->setVecX(-1 * static_cast<tRhombus*>(figure[5])->getVecX());
            if (static_cast<tRhombus*>(figure[5])->getYtl() < 0 || static_cast<tRhombus*>(figure[5])->getYtr() < 0 || static_cast<tRhombus*>(figure[5])->getYbl() < 0
                || static_cast<tRhombus*>(figure[5])->getYbr() < 0)
                static_cast<tRhombus*>(figure[5])->setVecY(-1 * static_cast<tRhombus*>(figure[5])->getVecY());
            if (static_cast<tRhombus*>(figure[5])->getXtl() > win_size || static_cast<tRhombus*>(figure[5])->getXtr() > win_size
                || static_cast<tRhombus*>(figure[5])->getXbl() > win_size || static_cast<tRhombus*>(figure[5])->getXbr() > win_size)
                static_cast<tRhombus*>(figure[5])->setVecX(-1 * static_cast<tRhombus*>(figure[5])->getVecX());
            if (static_cast<tRhombus*>(figure[5])->getYtl() > win_size || static_cast<tRhombus*>(figure[5])->getYtr() > win_size
                || static_cast<tRhombus*>(figure[5])->getYbl() > win_size || static_cast<tRhombus*>(figure[5])->getYbr() > win_size)
                static_cast<tRhombus*>(figure[5])->setVecY(-1 * static_cast<tRhombus*>(figure[5])->getVecY());
            switch (action) {
            case 0:
                static_cast<tRhombus*>(figure[5])->move();
                break;
            case 1:
                static_cast<tRhombus*>(figure[5])->rotate(i);
                break;
            case 2:
                static_cast<tRhombus*>(figure[5])->move();
                static_cast<tRhombus*>(figure[5])->rotate(i);

                break;
            }
        }
        static_cast<tRhombus*>(figure[5])->draw(window, color);
        break;
    case 6:
        for (size_t i = 0; i < 360; i++) {
            if (static_cast<tEllipse*>(figure[6])->getA() > static_cast<tEllipse*>(figure[6])->getX() || static_cast<tEllipse*>(figure[6])->getA() > (win_size - static_cast<tEllipse*>(figure[6])->getX()))
                static_cast<tEllipse*>(figure[6])->setVecX(-1 * static_cast<tEllipse*>(figure[6])->getVecX());
            if (static_cast<tEllipse*>(figure[6])->getB() > static_cast<tEllipse*>(figure[6])->getY() || static_cast<tEllipse*>(figure[6])->getB() > (win_size - static_cast<tEllipse*>(figure[6])->getY()))
                static_cast<tEllipse*>(figure[6])->setVecY(-1 * static_cast<tEllipse*>(figure[6])->getVecY());
            switch (action) {
            case 0:
                static_cast<tEllipse*>(figure[6])->move();
                break;
            case 1:
                static_cast<tEllipse*>(figure[6])->rotate(i);
                break;
            case 2:
                static_cast<tEllipse*>(figure[6])->move();
                static_cast<tEllipse*>(figure[6])->rotate(i);
                break;
            }
        }
        static_cast<tEllipse*>(figure[6])->draw(window, color);
        break;
    }
}

int main()
{
    tPoint *figure[7];
    figure[0] = new tPoint();
    figure[1] = new tLine(100, 100, 300, 300);
    figure[2] = new tRectangle(50, 20);
    figure[3] = new tTriangle(100, 0, 100, 120, 50, 240);
    figure[4] = new tCircle(250, 250, 50);
    figure[5] = new tRhombus(100, 50);
    figure[6] = new tEllipse(100, 50);
    // Создание окна
    Vector2i centerWindow(
            (VideoMode::getDesktopMode().width / 2) - 300,
            (VideoMode::getDesktopMode().height / 2) - 300);
    RenderWindow window(VideoMode(600, 600), "lab_3");
    window.setPosition(centerWindow);
    // Создаю элементы
    Event event;
    Clock clock;
    Color color(120, 122,  123);
    float timer = 0, delay = 0.05, times;
    srand(time(NULL) * rand());
    int figure_number = 0;
    // Запускаю работу графического интерфейса
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            // Проверяет срабатывание различных ситуаций.(нажатие кнопки,
            // движение мыши и т.д.)
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape)
                    window.close();
                if (event.key.code == Keyboard::Num0 )
                    figure_number = 0;
                if (event.key.code == Keyboard::Num1 )
                    figure_number = 1;
                if (event.key.code == Keyboard::Num2 )
                    figure_number = 2;
                if (event.key.code == Keyboard::Num3 )
                    figure_number = 3;
                if (event.key.code == Keyboard::Num4 )
                    figure_number = 4;
                if (event.key.code == Keyboard::Num5 )
                    figure_number = 5;
                if (event.key.code == Keyboard::Num6 )
                    figure_number = 6;
            }
        }
        // Включаю таймер для того, чтобы отрисовывать графику через
        // определенные промежутки времени.
        times = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += times;
        if (timer > delay) {
            // Выполняем необходимые действия по отрисовке
            window.clear();
            // figure[1]->draw(window, color);
            // figure[1]->move();
            // figure[0]->draw(window, color);
            //figure[3]->draw(window,color);
            work(figure_number, 2, window, color, figure);
            window.display();
            timer = 0;
        }
    }
    return 0;
}