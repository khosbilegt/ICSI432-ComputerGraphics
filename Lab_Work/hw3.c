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
int sizeWidth = 600, sizeHeight = 600;


void patternDraw(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, sizeWidth, sizeHeight);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100, 100, 100, 100, 0, 0);
    
    glColor3d(0, 0, 0);
    for(int k = 0; k < 40; k++) {
        glBegin(GL_LINE_LOOP);
        for(int i = 0; i < 6; ++i) {
            float angle = 2 * 3.14 * i / 6 + (k * tilt);
            x = (0.001 + inc * k) * cos(angle);
            y = (0.001 + inc * k) * sin(angle);
            glVertex3f(x, y, 1);
        }
        glEnd();
    }
    
    // Row 1
    for(int nth = 0; nth < 4; nth++) {
        switch(nth) {
            case 0:
                glScissor(0, sizeHeight / 4 * 3, sizeWidth / 4, sizeHeight / 4);
                glColor3d(0, 0, 0);
                for(int k = 0; k < 40; k++) {
                    glBegin(GL_LINE_LOOP);
                    for(int i = 0; i < 6; ++i) {
                        float angle = 2 * 3.14 * i / 6 + (k * tilt);
                        x = (0.001 + inc * k) * cos(angle) - 0.75;
                        y = (0.001 + inc * k) * sin(angle) + 0.75;
                        glVertex3f(x, y, 1);
                    }
                    glEnd();
                }
            case 1:
                glScissor(sizeWidth / 4, sizeHeight / 4 * 3, sizeWidth / 4, sizeHeight / 4);
                for(int k = 0; k < 40; k++) {
                    glBegin(GL_LINE_LOOP);
                    for(int i = 0; i < 6; ++i) {
                        float angle = 2 * 3.14 * i / 6 + (k * tilt);
                        x = (0.001 + inc * k) * cos(-angle) - 0.25;
                        y = (0.001 + inc * k) * sin(-angle) + 0.75;
                        glVertex3f(x, y, 2);
                    }
                    glEnd();
                }
            case 2:
                glScissor(sizeWidth / 2, sizeHeight / 4 * 3, sizeWidth / 4, sizeHeight / 4);
                for(int k = 0; k < 40; k++) {
                    glBegin(GL_LINE_LOOP);
                    for(int i = 0; i < 6; ++i) {
                        float angle = 2 * 3.14 * i / 6 + (k * tilt);
                        x = (0.001 + inc * k) * cos(angle) + 0.25;
                        y = (0.001 + inc * k) * sin(angle) + 0.75;
                        glVertex3f(x, y, 2);
                    }
                    glEnd();
                }
            case 3:
                glScissor(sizeWidth / 4 * 3, sizeHeight / 4 * 3, sizeWidth / 4, sizeHeight / 4);
                for(int k = 0; k < 40; k++) {
                    glBegin(GL_LINE_LOOP);
                    for(int i = 0; i < 6; ++i) {
                        float angle = 2 * 3.14 * i / 6 + (k * tilt);
                        x = (0.001 + inc * k) * cos(-angle) + 0.75;
                        y = (0.001 + inc * k) * sin(-angle) + 0.75;
                        glVertex3f(x, y, 2);
                    }
                    glEnd();
                }
        }
    }
    // Row 2
    for(int nth = 0; nth < 4; nth++) {
        switch(nth) {
            case 0:
                glScissor(0, sizeHeight / 2, sizeWidth / 4, sizeHeight / 4);
                glColor3d(0, 0, 0);
                for(int k = 0; k < 40; k++) {
                    glBegin(GL_LINE_LOOP);
                    for(int i = 0; i < 6; ++i) {
                        float angle = 2 * 3.14 * i / 6 + (k * tilt);
                        x = (0.001 + inc * k) * cos(-angle) - 0.75;
                        y = (0.001 + inc * k) * sin(-angle) + 0.25;
                        glVertex3f(x, y, 1);
                    }
                    glEnd();
                }
            case 1:
                glScissor(sizeWidth / 4, sizeHeight / 2, sizeWidth / 4, sizeHeight / 4);
                for(int k = 0; k < 40; k++) {
                    glBegin(GL_LINE_LOOP);
                    for(int i = 0; i < 6; ++i) {
                        float angle = 2 * 3.14 * i / 6 + (k * tilt);
                        x = (0.001 + inc * k) * cos(angle) - 0.25;
                        y = (0.001 + inc * k) * sin(angle) + 0.25;
                        glVertex3f(x, y, 2);
                    }
                    glEnd();
                }
            case 2:
                glScissor(sizeWidth / 2, sizeHeight / 2, sizeWidth / 4, sizeHeight / 4);
                for(int k = 0; k < 40; k++) {
                    glBegin(GL_LINE_LOOP);
                    for(int i = 0; i < 6; ++i) {
                        float angle = 2 * 3.14 * i / 6 + (k * tilt);
                        x = (0.001 + inc * k) * cos(-angle) + 0.25;
                        y = (0.001 + inc * k) * sin(-angle) + 0.25;
                        glVertex3f(x, y, 2);
                    }
                    glEnd();
                }
            case 3:
                glScissor(sizeWidth / 4 * 3, sizeHeight / 2, sizeWidth / 4, sizeHeight / 4);
                for(int k = 0; k < 40; k++) {
                    glBegin(GL_LINE_LOOP);
                    for(int i = 0; i < 6; ++i) {
                        float angle = 2 * 3.14 * i / 6 + (k * tilt);
                        x = (0.001 + inc * k) * cos(angle) + 0.75;
                        y = (0.001 + inc * k) * sin(angle) + 0.25;
                        glVertex3f(x, y, 2);
                    }
                    glEnd();
                }
        }
    }
    
    // Row 3
    for(int nth = 0; nth < 4; nth++) {
        switch(nth) {
            case 0:
                glScissor(0, sizeHeight / 4, sizeWidth / 4, sizeHeight / 4);
                glColor3d(0, 0, 0);
                for(int k = 0; k < 40; k++) {
                    glBegin(GL_LINE_LOOP);
                    for(int i = 0; i < 6; ++i) {
                        float angle = 2 * 3.14 * i / 6 + (k * tilt);
                        x = (0.001 + inc * k) * cos(angle) - 0.75;
                        y = (0.001 + inc * k) * sin(angle) - 0.25;
                        glVertex3f(x, y, 1);
                    }
                    glEnd();
                }
            case 1:
                glScissor(sizeWidth / 4, sizeHeight / 4, sizeWidth / 4, sizeHeight / 4);
                for(int k = 0; k < 40; k++) {
                    glBegin(GL_LINE_LOOP);
                    for(int i = 0; i < 6; ++i) {
                        float angle = 2 * 3.14 * i / 6 + (k * tilt);
                        x = (0.001 + inc * k) * cos(-angle) - 0.25;
                        y = (0.001 + inc * k) * sin(-angle) - 0.25;
                        glVertex3f(x, y, 2);
                    }
                    glEnd();
                }
            case 2:
                glScissor(sizeWidth / 2, sizeHeight / 4, sizeWidth / 4, sizeHeight / 4);
                for(int k = 0; k < 40; k++) {
                    glBegin(GL_LINE_LOOP);
                    for(int i = 0; i < 6; ++i) {
                        float angle = 2 * 3.14 * i / 6 + (k * tilt);
                        x = (0.001 + inc * k) * cos(angle) + 0.25;
                        y = (0.001 + inc * k) * sin(angle) - 0.25;
                        glVertex3f(x, y, 2);
                    }
                    glEnd();
                }
            case 3:
                glScissor(sizeWidth / 4 * 3, sizeHeight / 4, sizeWidth / 4, sizeHeight / 4);
                for(int k = 0; k < 40; k++) {
                    glBegin(GL_LINE_LOOP);
                    for(int i = 0; i < 6; ++i) {
                        float angle = 2 * 3.14 * i / 6 + (k * tilt);
                        x = (0.001 + inc * k) * cos(-angle) + 0.75;
                        y = (0.001 + inc * k) * sin(-angle) - 0.25;
                        glVertex3f(x, y, 2);
                    }
                    glEnd();
                }
        }
    }
    
    
    // Row 4
    for(int nth = 0; nth < 4; nth++) {
        switch(nth) {
            case 0:
                glScissor(0, 0, sizeWidth / 4, sizeHeight / 4);
                glColor3d(0, 0, 0);
                for(int k = 0; k < 40; k++) {
                    glBegin(GL_LINE_LOOP);
                    for(int i = 0; i < 6; ++i) {
                        float angle = 2 * 3.14 * i / 6 + (k * tilt);
                        x = (0.001 + inc * k) * cos(-angle) - 0.75;
                        y = (0.001 + inc * k) * sin(-angle) - 0.75;
                        glVertex3f(x, y, 1);
                    }
                    glEnd();
                }
            case 1:
                glScissor(sizeWidth / 4, 0, sizeWidth / 4, sizeHeight / 4);
                for(int k = 0; k < 40; k++) {
                    glBegin(GL_LINE_LOOP);
                    for(int i = 0; i < 6; ++i) {
                        float angle = 2 * 3.14 * i / 6 + (k * tilt);
                        x = (0.001 + inc * k) * cos(angle) - 0.25;
                        y = (0.001 + inc * k) * sin(angle) - 0.75;
                        glVertex3f(x, y, 2);
                    }
                    glEnd();
                }
            case 2:
                glScissor(sizeWidth / 2, 0, sizeWidth / 4, sizeHeight / 4);
                for(int k = 0; k < 40; k++) {
                    glBegin(GL_LINE_LOOP);
                    for(int i = 0; i < 6; ++i) {
                        float angle = 2 * 3.14 * i / 6 + (k * tilt);
                        x = (0.001 + inc * k) * cos(-angle) + 0.25;
                        y = (0.001 + inc * k) * sin(-angle) - 0.75;
                        glVertex3f(x, y, 2);
                    }
                    glEnd();
                }
            case 3:
                glScissor(sizeWidth / 4 * 3, 0, sizeWidth / 4, sizeHeight / 4);
                for(int k = 0; k < 40; k++) {
                    glBegin(GL_LINE_LOOP);
                    for(int i = 0; i < 6; ++i) {
                        float angle = 2 * 3.14 * i / 6 + (k * tilt);
                        x = (0.001 + inc * k) * cos(angle) + 0.75;
                        y = (0.001 + inc * k) * sin(angle) - 0.75;
                        glVertex3f(x, y, 2);
                    }
                    glEnd();
                }
        }
    }
   
    glScissor(0, 0, sizeHeight, sizeHeight);
    glutSwapBuffers();
}

static void resize(int width, int height)
{
    if(height != sizeHeight || width != sizeWidth) {
        sizeHeight = sizeHeight + height;
        sizeWidth = sizeWidth + width;
    }
    
    glScissor(0, 0, sizeWidth, sizeHeight);
    glutPostRedisplay();
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
