#include "shape.h"
#ifndef GRAPHICS_TRIANGLE_H
#define GRAPHICS_TRIANGLE_H

class Triangle : public Shape{
protected:
    unsigned int width;
    unsigned int height;

public:
    Triangle();
    Triangle(color fill, point2D center, unsigned int width, unsigned int height);

    int getRightX() const;
    int getLeftX() const;
    int getTopY() const;
    int getBottomY() const;

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    void draw() const override;
};


#endif //GRAPHICS_TRIANGLE_H
