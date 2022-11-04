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
int i = 3;

 

void display(void) {
GLfloat x = 0.0, y = 0.0;
float radius = 0.8;
GLfloat twicePi = 2.0f * M_PI;
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
glVertex2f(x,y);

 

for(int k = 0; k<=i; k++)
{
glVertex2f((x+(radius*cos(k*twicePi/i))),(y + (radius *sin(k * twicePi/i))));

 

}
glEnd();
glFlush();
}
void mSpecial(int k, int x,int y){
if(k == GLUT_KEY_UP){
i++;
} else if (k == GLUT_KEY_DOWN){
i--;
}
glutPostRedisplay();
}
void colorchange(unsigned char key , int x , int y){
   switch (key){
        case 'r':
            glClearColor (1.0, 0.0, 0.0, 0.0);
            break;

 

        case 'g':
            glClearColor (0.0, 1.0, 0.0, 0.0);
        break;

 

        case 'b':
            glClearColor (0.0, 0.0, 1.0, 0.0);
        break;

 

        default:
         break;
    }
    glutPostRedisplay();

 

}

 


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Draw Triangle");
    glutDisplayFunc(display);
    glutKeyboardFunc(colorchange);
    glutSpecialFunc(mSpecial);
    glutMainLoop();
return 0;
}
*/
