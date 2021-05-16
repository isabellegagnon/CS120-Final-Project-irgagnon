//Sourced used: https://github.com/uvmcs120s2021/M4GP-Confettify-Button.git
#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : public Shape{
protected:
    unsigned int width;
    unsigned int height;

public:
    Square();
    Square(color fill, point2D center, unsigned int width, unsigned int height);
    int getTopY() const;
    int getBottomY() const;
    int getRightX() const;
    int getLeftX() const;
    unsigned int getHeight() const;
    unsigned int getWidth() const;
    void draw() const override;
};

#endif SQUARE_H