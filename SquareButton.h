//Sources used: https://github.com/uvmcs120s2021/M4GP-Confettify-Button.git
#ifndef SQUARE_BUTTON_H
#define SQUARE_BUTTON_H
#include "Square.h"
#include <string>

class SquareButton : public Square {
private:
    std::string label;
    color originalFill, hoverFill, pressFill;
    bool select;

public:
    SquareButton(color fill, point2D center, unsigned int width, unsigned int height, std::string label);
    void draw() const override;
    void changeLabel(std::string label);
    bool isOverlapping(int x, int y) const;
    bool getSelect();
    void setSelect(bool select);
    void hover();
    void pressDown();
    void release();

};

#endif SQUARE_BUTTON_H