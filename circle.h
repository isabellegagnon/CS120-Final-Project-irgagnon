//Sources used: https://github.com/uvmcs120s2021/Graphics-Jeopardy.git
#include "shape.h"

class Circle : public Shape {
private:
    double radius;
public:
    Circle();
    explicit Circle(double radius);
    explicit Circle(color fill);
    explicit Circle(point2D center);
    Circle(color fill, point2D center);
    Circle(double red, double green, double blue, double alpha);
    Circle(double x, double y);
    Circle(double red, double green, double blue, double alpha, double x, double y);
    Circle(color fill, double x, double y);
    Circle(double red, double green, double blue, double alpha, point2D center);
    Circle(color fill, double radius);
    Circle(point2D center, double radius);
    Circle(color fill, point2D center, double radius);
    Circle(double red, double green, double blue, double alpha, double radius);
    Circle(double x, double y, double radius);
    Circle(double red, double green, double blue, double alpha, double x, double y, double radius);
    Circle(color fill, double x, double y, double radius);
    Circle(double red, double green, double blue, double alpha, point2D center, double radius);

    virtual ~Circle() = default;

    double getRadius() const;

    void setRadius(double r);
    void changeRadius(double delta);

    void draw() const override;

};
