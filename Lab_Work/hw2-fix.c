
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>
#else
#include <GLUT/GLUT.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int width = 800, height = 600;
float xl = 0, yl = 0, xf, yf, xp, yp, draw = 0, i = 0, ip;

void mouse(int button, int state, int x, int y) {
    if(state == GLUT_DOWN) {
        draw = 1;
        i++;
    } else {
        draw = 0;
    }
}

void motion(int x, int y) {
    xf = (float)x;
    yf = (float)y;
    
    if(x <= width / 2) {
        xl = xf - (width / 2);
        xl = xl / (width / 2);
    } else if(x > width / 2) {
        xl = xf - (width / 2);
        xl = xl / (width / 2);
    }
    
    if(yf <= height / 2) {
        yl = yf - 400;
        yl = -1 * yl;
        yl = yl - (height / 6);
        yl = yl / (height / 2);
    } else if(yf > height / 2) {
        yl = yf - (height / 2);
        yl = -1 * yl;
        yl = yl / (height / 2);
    }
    printf("%f %f\n", xl, yl);
    if(draw == 1) {
        glutPostRedisplay();
    }
}


void display(void)
{
    if(i != ip) {
        glColor3f(0, 0, 0);
    } else {
        glColor3f(1, 1, 1);
    }
    glBegin(GL_LINE_STRIP);
    glVertex2f(xl, yl);
    glVertex2f(xp, yp);
    glEnd();
    i++;
    xp = xl;
    yp = yl;
    ip = i;
    glutSwapBuffers();
}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Change");
    
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    
    
    glutMainLoop();
    return EXIT_SUCCESS;
}



