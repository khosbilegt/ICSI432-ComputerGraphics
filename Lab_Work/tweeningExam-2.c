/*
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float color = 0, spinAngle = 2, sides = 4, size = 0.1;
int changerSize = 1, changerColor = 1, height = 0.1;


float tilt = 1, inc = 0.01;
float x = -1, y = 1;

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    // glRotatef(spinAngle, 0, 0, rotZ);
    glRotatef(spinAngle, 0, 0, 1);
    glColor3d(1, 0, color);
    glBegin(GL_POLYGON);
         for(int i = 1; i <= sides; i++){
             float angle = 2 * 3.14 * i / sides;
             float x = 0.8 * cos(angle) * size;
             float y = 0.8 * sin(angle) * size;
             glVertex2f(x, y);
         }
    glEnd();
    
    
    glutSwapBuffers();
}

void Timer(int start)
{
    size += 0.01f * changerSize; // size = size + 0.01
    color += 0.01f * changerColor;
    height += 0.01;
    spinAngle += 0.01;
    if(size > 2.5 || size < -2.5) {
        changerSize = changerSize * -1;
        sides++;
    }
    if(color > 1) {
        changerColor = changerColor * -1;
    } else if(color < 0) {
        color = color * -1;
        changerColor = changerColor * -1;
    }
    if(spinAngle > 5) {
        spinAngle = spinAngle * -1;
    } else if (spinAngle < -5) {
        spinAngle = spinAngle * -1;
    }
    glutPostRedisplay();
    glutTimerFunc(1, Timer, 0);
}


int main(int argc, char **argv) {
   
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    
    glutCreateWindow("Animation");
    
    glClearColor(1, 1, 1, 1);
    glutDisplayFunc(renderScene);
    Timer(0);
    
    glutMainLoop();

    return 1;
}
*/
