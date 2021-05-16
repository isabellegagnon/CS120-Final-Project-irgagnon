#ifndef GRAPHICS_TRIANGLEBUTTON_H
#define GRAPHICS_TRIANGLEBUTTON_H

#include "triangle.h"
#include <string>

class TriangleButton : public Triangle {
private:
    std::string label;
    color originalFill, hoverFill, pressFill;
    bool select;

public:
    TriangleButton(color fill, point2D center, unsigned int width, unsigned int height, std::string label);
    void draw() const override;
    void changeLabel(std::string label);
    bool isOverlapping(int x, int y) const;
    bool getSelect();
    void setSelect(bool select);
    void hover();
    void pressDown();
    void release();

};

#endif //GRAPHICS_TRIANGLEBUTTON_H
