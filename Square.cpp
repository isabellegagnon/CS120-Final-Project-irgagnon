//Sourced used: https://github.com/uvmcs120s2021/M4GP-Confettify-Button.git
#include "Square.h"
#include "graphics.h"

Square::Square() {
    fill = {1, 0, 0,1};
    center = {100, 100};
    width = 50;
    height = 50;
}

Square::Square(color fill, point2D center, unsigned int width, unsigned int height) {
    this->fill = fill;
    this->center = center;
    this->width = width;
    this->height = height;
}

int Square::getTopY() const {
    return center.y - (height / 2);
}

int Square::getBottomY() const {
    return center.y + (height / 2);
}

int Square::getRightX() const {
    return center.x + (width / 2);
}

int Square::getLeftX() const {
    return center.x - (width / 2);
}

unsigned int Square::getHeight() const {
    return height;
}

unsigned int Square::getWidth() const {
    return width;
}


void Square::draw() const {
    // Set drawing color to fill color
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_QUADS);
// glVertex2i takes a 2-D (x, y) coordinate
    glVertex2i(getLeftX(), getTopY());
    glVertex2i(getLeftX(), getBottomY());
    glVertex2i(getRightX(), getBottomY());
    glVertex2i(getRightX(), getTopY());
    glEnd();
}