//Sources used: https://github.com/uvmcs120s2021/M4GP-Confettify-Button.git
#include "circle.h"
#include <string>

class CircleButton : public Circle {
private:
    std::string label;
    color originalFill, hoverFill, pressFill;
    bool select;

public:
    CircleButton(color fill, point2D center, unsigned int radius, std::string label);

    CircleButton(color fill, point2D center, unsigned int radius, std::string label, bool select);

    void draw() const override;

    void changeLabel(std::string label);

    bool isOverlapping(int x, int y) const;

    void hover();

    void pressDown();

    void release();

    bool getSelect();

    void setSelect(bool select);
};
