//Sources used: https://github.com/uvmcs120s2021/M4GP-Confettify-Button.git
#include "SquareButton.h"
#include "graphics.h"
using namespace std;

SquareButton::SquareButton(color fill, point2D center, unsigned int width, unsigned int height, std::string label) : Square(fill, center, width, height) {
    this->label = label;
    originalFill = fill;
    hoverFill = {fill.red + 0.5, fill.green + 0.5, fill.blue + 0.5};
    pressFill = {1,0,0};
}

void SquareButton::draw() const {
    Square::draw();
    glColor3f(0, 0, 0);
    glRasterPos2i(center.x - (4 * label.length()), center.y + 7);
    for (const char &letter : label) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
}

void SquareButton::changeLabel(std::string label) {
    this->label = label;
}

/* Returns true if the coordinate is inside the box */
bool SquareButton::isOverlapping(int x, int y) const {
    point2D bottomLeft {(double)(getLeftX()), (double)getBottomY()};
    point2D topRight {(double)getRightX(), (double)getTopY()};

    if((getLeftX() <= x && getRightX() >= x) && (getTopY() <= y && getBottomY() >= y)){
        return true;
    }
    return false;
}

void SquareButton::hover() {
    setColor(hoverFill);
}

void SquareButton::pressDown() {
    setColor(pressFill);
}

void SquareButton::release() {
    setColor(originalFill);
}

bool SquareButton::getSelect() {
    return select;
}

void SquareButton::setSelect(bool select) {
    this->select = select;
    if(select){
        pressFill = {0,1,0,1};
    } else {
        pressFill = {1,0,0,1};
    }
}
