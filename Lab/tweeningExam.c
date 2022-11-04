/*
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float sizeSmall = 0.4, sizeBig = 0.7;
int direction = 1;
float speed = 0.3;

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glColor3f(0, 0.5, 1);
    
    glRotatef(speed, 1, 1, 1);
    glutWireCube(sizeSmall);
    
    glColor3f(0.5, 0.5, 1);
    glRotatef(speed, 1, 1, 1);
    glutWireCube(sizeBig);
    
    glutSwapBuffers();
}

void Timer(int start)
{
    // Tweening Process
   
    sizeSmall = sizeSmall + 0.01 * direction;
    sizeBig = sizeBig - 0.01 * direction;
    if(sizeSmall > 0.7 && direction == 1) {
        direction = -1;
    }
    if(sizeSmall < 0.4 && direction == -1) {
        direction = 1;
    }
    printf("%f\n", sizeSmall);
    glutPostRedisplay();
    glutTimerFunc(1, Timer, 0);
}

int main(int argc, char **argv) {
   
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    
    glutCreateWindow("Tweening Animation");
    
    glClearColor(0, 0, 0, 1);
    glutDisplayFunc(renderScene);
    Timer(0);
    
    glutMainLoop();

    return 1;
}


*/
