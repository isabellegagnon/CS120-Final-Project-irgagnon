#include "triangle.h"
#include "graphics.h"

Triangle::Triangle() {
    fill = {1, 0, 0,1};
    center = {100, 100};
    width = 50;
    height = 50;
}

Triangle::Triangle(color fill, point2D center, unsigned int width, unsigned int height) {
    this->fill = fill;
    this->center = center;
    this->width = width;
    this->height = height;
}

int Triangle::getRightX() const {
    return center.x + (width / 2);
}

int Triangle::getLeftX() const {
    return center.x - (width / 2);
}

int Triangle::getTopY() const {
    return center.y - (height / 2);
}

int Triangle::getBottomY() const {
    return center.y + (height / 2);
}


unsigned int Triangle::getWidth() const {
    return width;
}

unsigned int Triangle::getHeight() const {
    return height;
}

void Triangle::draw() const {
    // Set drawing color to fill color
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_TRIANGLES);
// glVertex2i takes a 2-D (x, y) coordinate
    glColor3f( 1, 0, 0 ); // red
    glVertex2f( -0.8, -0.8 );
    glColor3f( 0, 1, 0 ); // green
    glVertex2f( 0.8, -0.8 );
    glColor3f( 0, 0, 1 ); // blue
    glVertex2f( 0, 0.9 );
    glEnd();
}

