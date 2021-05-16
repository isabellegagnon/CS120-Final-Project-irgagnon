//Sources used: https://github.com/uvmcs120s2021/M4GP-Confettify-Button.git
#include "graphics.h"
#include "CircleButton.h"
#include "SquareButton.h"
#include "TriangleButton.h"
#include <iostream>
#include <vector>
#include <sstream>;
using namespace std;

GLdouble width, height;
int wd;

CircleButton circleButton = CircleButton({0.77,0.77,0.77,1},{250, 250},15, "");
point2D circleCenter;

SquareButton squareButton = SquareButton({0.77, 0.77, 0.77, 1}, {100, 100}, 25, 25, "");
point2D squareCenter;

TriangleButton triangleButton = TriangleButton({0.77, 0.77, 0.77, 1}, {100, 100}, 25, 25, "");
point2D triangleCenter;


int score = 0;
string shapeToSelect = "";

bool running = false;
time_t currentTime;
time_t endTime;

void drawCircle() {
    srand(time(0));
    circleButton.setColor(0.06,0.69,0.26,1);
    double circleX = (rand() % 450) + 30;
    double circleY = (rand() % 325) + 75;

    circleCenter = {circleX,circleY};
    circleButton.setCenter(circleCenter);
    circleButton.draw();
    glFlush();
}

void drawTriangle() {
    srand(time(0));
    triangleButton.setColor(0.96,0.26,0.50,1);
    double triangleX = (rand() % 450) + 30;
    double triangleY = (rand() % 325) + 75;

    while(circleButton.isOverlapping(triangleX,triangleY)){
        triangleX = (rand() % 450) + 30;
        triangleY = (rand() % 325) + 75;
    }
    triangleCenter = {triangleX, triangleY};
    triangleButton.setCenter(triangleCenter);
    triangleButton.draw();
}

void drawSquare(){
    srand(time(0));
    squareButton.setColor(0.96,0.26,0.50,1);
    double quadX = (rand() % 450) + 30;
    double quadY = (rand() % 325) + 75;

    while(circleButton.isOverlapping(quadX,quadY)){
        quadX = (rand() % 450) + 30;
        quadY = (rand() % 325) + 75;
    }
    squareCenter = {quadX, quadY};
    squareButton.setCenter(squareCenter);
    squareButton.draw();
}

void generateSelectShape(){
    srand(time(0));
    int selectType = rand() % 2;
    if(selectType == 0){
        circleButton.setSelect(true);
        squareButton.setSelect(false);
        triangleButton.setSelect(false);
        shapeToSelect = "Click the circle accurately to get a point" ;
    } else if(selectType == 1) {
        circleButton.setSelect(false);
        squareButton.setSelect(true);
        triangleButton.setSelect(false);
        shapeToSelect = "Click the square accurately to get a point";
    }else {
        triangleButton.setSelect(true);
        squareButton.setSelect(false);
        triangleButton.setSelect(false);
        shapeToSelect = "Click the triangle accurately to get a point";

    }
}

void game(){
    running = true;
    score = 0;
    endTime = time(NULL) + 60;
    generateSelectShape();
    drawCircle();
    drawSquare();
    drawTriangle();
}

void init() {
    width = 500;
    height = 500;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.40, 0.77, 0.77, 1); // Black and opaque
}


void display() {
    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

    // Clear the color buffer with current clearing color
    glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE

    circleButton.draw();
    squareButton.draw();
    triangleButton.draw();

    string label = "Score: " + to_string(score);

    glColor3f(0, 0, 0);
    glRasterPos2i(15, 25);
    for (const char &letter : label) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    Square startRectangle = Square({0.40, 0.77, 0.77, 1}, {250, 450}, 400, 50);
    startRectangle.draw();
    string startLabel = "Press Space to Start or Reset the game";
    glColor3f(0, 0, 0);
    glRasterPos2i(125, 450);
    for (const char &letter : startLabel) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
    glColor3f(0, 0, 0);
    glRasterPos2i(125, 50);
    for (const char &letter : shapeToSelect) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    currentTime = time(NULL);
    if(currentTime >= endTime){
        currentTime = time(NULL);
        running = false;
        circleButton.setColor(0.40, 0.77, 0.77, 1);
        squareButton.setColor(0.40, 0.77, 0.77, 1);
        triangleButton.setColor(0.40, 0.77, 0.77, 1);
    }
    stringstream ss;
    string timerString;
    if(running){
        ss << "Time: " << endTime - currentTime;
        timerString = ss.str();
    } else {
        ss << "Time: " << 0;
        timerString = ss.str();
    }
    glColor3f(0, 0, 0);
    glRasterPos2i(425, 25);
    for (const char &letter : timerString) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
    glFlush();
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    } else if(key == 32){
        game();
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && running) {
        if(circleButton.getSelect()){
            if(circleButton.isOverlapping(x,y)){
                circleButton.pressDown();
                score++;
            }
            else if(squareButton.isOverlapping(x,y)){
                squareButton.pressDown();
                score--;
            }
            else if (triangleButton.isOverlapping(x,y)) {
                triangleButton.pressDown();
                score--;
            }
        }
        else if(squareButton.getSelect()){
            if(squareButton.isOverlapping(x,y)){
                squareButton.pressDown();
                score++;
            }
            else if (triangleButton.isOverlapping(x,y)) {
                triangleButton.pressDown();
                score--;
            }
            else if(circleButton.isOverlapping(x,y)){
                circleButton.pressDown();
                score--;
            }
        }else if(triangleButton.getSelect()){
            if(triangleButton.isOverlapping(x,y)){
                triangleButton.pressDown();
                score++;
            }
            else if(squareButton.isOverlapping(x,y)){
                squareButton.pressDown();
                score--;
            }
            else if(circleButton.isOverlapping(x,y)){
                circleButton.pressDown();
                score--;
            }
        }
    }

    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && running){
        drawCircle();
        drawSquare();
        drawTriangle();
    }
    glutPostRedisplay();
}

void timer(int dummy) {
    glutPostRedisplay();
    glutTimerFunc(0, timer, dummy);
}

int main(int argc, char** argv) {
    init();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200);
    wd = glutCreateWindow("Mouse Click Game");
    glutDisplayFunc(display);
    initGL();
    glutKeyboardFunc(kbd);
    glutMouseFunc(mouse);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}