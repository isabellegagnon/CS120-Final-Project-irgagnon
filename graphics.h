//Sources used: https://github.com/uvmcs120s2021/M4GP-Confettify-Button.git
#ifndef graphics_h
#define graphics_h

#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void init();

void InitGL();

void cursor(int x, int y);

void timer(int dummy);

void mouse(int button, int state, int x, int y);

void display();

void kbd(unsigned char key, int x, int y);

void kbdS(int key, int x, int y);

#endif graphics_h