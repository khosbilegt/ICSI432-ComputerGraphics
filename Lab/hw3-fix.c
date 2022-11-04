/*
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>
#else
#include <GLUT/GLUT.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float tilt = 1, inc = 0.01;
float x = -1, y = 1, prevX, prevY;
int sizeWidth = 700, sizeHeight = 600, changer;

void patternDraw(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, sizeWidth, sizeHeight);
    
    
    for(int l = 0; l < 4; l++) {
        for(int j = 0; j < 5; j++) {
            if(l == 0 || l == 1) {
                glScissor(0 + sizeWidth / 5 * j, sizeHeight / 4 * 3 - (sizeHeight / 4 * l), sizeWidth / 5, sizeHeight / 4);
            } else {
                glScissor(0 + sizeWidth / 5 * j, 0 + sizeHeight / 4 * (l - 2), sizeWidth / 5, sizeHeight / 4);
            }
            glColor3d(0, 0, 0);
            if(l == 0 | l == 2) {
                if(j == 0) {
                    glOrtho(-1, 1, -1, 1, -1, 1);
                } else {
                    glOrtho(-1, 1, 1, -1, -1, 1);
                }
                for(int k = 0; k < 40; k++) {
                    glBegin(GL_LINE_LOOP);
                    for(int i = 0; i < 6; i++) {
                        float angle = 2 * 3.14 * i / 6 + (k * tilt);
                        x = (0.001 + inc * k) * cos(angle) + -0.8 + (0.4 * j);
                        if(l == 0) {
                            if(j == 1 || j == 3) {
                                y = (0.001 + inc * k) * sin(angle) - 0.75 + (0.5 * l);
                            } else {
                                y = (0.001 + inc * k) * sin(angle) + 0.75 - (0.5 * l);
                            }
                        } else {
                            if(j == 1 || j == 3) {
                                y = (0.001 + inc * k) * sin(angle) - 0.75;
                            } else {
                                y = (0.001 + inc * k) * sin(angle) + 0.75;
                            }
                        }
                        glVertex2f(x, y);
                    }
                    glEnd();
                }
            } else if(l == 1 || l == 3) {
                glOrtho(-1, 1, 1, -1, -1, 1);
                for(int k = 0; k < 40; k++) {
                    glBegin(GL_LINE_LOOP);
                    for(int i = 0; i < 6; ++i) {
                        float angle = 2 * 3.14 * i / 6 + (k * tilt);
                        x = (0.001 + inc * k) * cos(angle) + -0.8 + (0.4 * j);
                        if(l == 1) {
                            if(j == 1 || j == 3 || j == 5) {
                                y = (0.001 + inc * k) * sin(angle) + 0.75 - (0.5 * l);
                            } else {
                                y = (0.001 + inc * k) * sin(angle) - 0.75 + (0.5 * l);
                            }
                        } else {
                            if(j == 1 || j == 3 || j == 5) {
                                y = (0.001 + inc * k) * sin(angle) + 0.25;
                            } else {
                                y = (0.001 + inc * k) * sin(angle) - 0.25;
                            }
                        }
                        glVertex2f(x, y);
                    }
                    glEnd();
                }
            }
            glOrtho(-1, 1, -1, 1, -1, 1);
        }
    }
    glScissor(0, 0, sizeWidth, sizeHeight);
    glutSwapBuffers();
}


int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(sizeWidth, sizeHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Draw Pattern");
    
    glClearColor(1, 1, 1, 1);
    glutDisplayFunc(patternDraw);
    
    
    glEnable(GL_SCISSOR_TEST);
    
    glutMainLoop();
    return EXIT_SUCCESS;
}




*/
