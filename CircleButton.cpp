//Sources used: https://github.com/uvmcs120s2021/M4GP-Confettify-Button.git
#include "CircleButton.h"
#include "graphics.h"
using namespace std;

CircleButton::CircleButton(color fill, point2D center, unsigned int radius, std::string label) : Circle(fill, center, radius) {
    this->label = label;
    originalFill = fill;
    hoverFill = {fill.red + 0.5, fill.green + 0.5, fill.blue + 0.5};
    pressFill = {0,1,0};
}

CircleButton::CircleButton(color fill, point2D center, unsigned int radius, std::string label, bool select) : Circle(fill, center, radius){
    this->select = select;
    this->label = label;
    originalFill = fill;
    hoverFill = {fill.red + 0.5, fill.green + 0.5, fill.blue + 0.5};
    pressFill = {0,1,0};
}

void CircleButton::draw() const {
    Circle::draw();
    glColor3f(0, 0, 0);
    glRasterPos2i(center.x - (4 * label.length()), center.y + 7);
    for (const char &letter : label) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
}

void CircleButton::changeLabel(std::string label) {
    this->label = label;
}

bool CircleButton::isOverlapping(int x, int y) const {
    double diffX = x - getCenterX();
    double diffY = y - getCenterY();
    double d = sqrt( (diffX*diffX) + (diffY*diffY) );

    if(d < getRadius() || d == getRadius()){
        return true;
    }
    return false;
}

void CircleButton::hover() {
    setColor(hoverFill);
}

void CircleButton::pressDown() {
    setColor(pressFill);
}

void CircleButton::release() {
    setColor(originalFill);
}

bool CircleButton::getSelect() {
    return select;
}

void CircleButton::setSelect(bool select) {
    this->select = select;
    if(select){
        pressFill = {0,1,0,1};
    } else {
        pressFill = {1,0,0,1};
    }
}

