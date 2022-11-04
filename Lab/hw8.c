/*
#include "def.h"

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
bool mouseDown = false;
float xdiff = 0.0f;
float ydiff = 0.0f;
struct point{
GLfloat x, y, z;
};
struct face{
int a, b, c;
};
//dragon unshih bol
struct face f[100001];
struct point p[50001];

void loadPoints() {
    FILE *fp;
    int read, i=1;
    GLfloat x, y, z;
    //dragon
    char ch, path[100] = "/Users/xocoo/Desktop/Classes/2nd Year/Computer Graphics/Test/Test/dragon.obj";
    fp = fopen(path, "r");
    if (!fp) {
    printf("can't open file dragon.obj\n");
    exit(1);
    } else {
        while (!(feof(fp))) {
            read = fscanf(fp, "%c %f %f %f", &ch, &x, &y, &z);
            if (ch == 'v') {
            p[i].x = x;
            p[i].y = y;
            p[i].z = z;
            i++;
            }
        }
}
glEndList();
}

void loadFaces()
{
    FILE *fp;
    int read, i=1, a, b, c;
    //dragon
    char ch, path[100] = "/Users/xocoo/Desktop/Classes/2nd Year/Computer Graphics/Test/Test/dragon.obj";
    fp = fopen(path, "r");
    if (!fp) {
    printf("can't open file dragon.obj\n");
    exit(1);
    } else {
        while (!(feof(fp)))
        {
        read = fscanf(fp, "%c %d %d %d", &ch, &a, &b, &c);
        if (ch == 'f') {
            f[i].a = a;
            f[i].b = b;
            f[i].c = c;
            i++;
            }
        }
    }
    glEndList();
}

void displayDragon(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0);
    GLfloat nx, ny, nz;
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for(int i=1; i<100001; i++){
    glVertex3f( p [f[i].a].x, p [f[i].a].y, p [f[i].a].z );
    glVertex3f( p [f[i].b].x, p [f[i].b].y, p [f[i].b].z );
    glVertex3f( p [f[i].c].x, p [f[i].c].y, p [f[i].c].z );
    }
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}

void SpecialKeys(int key, int x, int y)
{
    if(key == GLUT_KEY_UP)
        xRot-= 5.0f;
    if(key == GLUT_KEY_DOWN)
        xRot += 5.0f;
    if(key == GLUT_KEY_LEFT)
        yRot -= 5.0f;
    if(key == GLUT_KEY_RIGHT)
        yRot += 5.0f;
    xRot = (GLfloat)((const int)xRot % 360);
    yRot = (GLfloat)((const int)yRot % 360);
    glutPostRedisplay();
}

void reshape(int w, int h){
    glOrtho(0, 0, 0, 0, 0, 0);
    glViewport(0, 0, w, h);
}

void mouse(int button, int state, int x, int y){
    if(state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
        mouseDown = true;
        xdiff = x - yRot;
        ydiff = -y + xRot;
    } else {
        mouseDown = false;
    }
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yRot = x - xdiff;
        xRot = y + ydiff;
        glutPostRedisplay();
    }
}

int main (int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    
    glutCreateWindow("Dragon");
    loadPoints();
    loadFaces();
    glutDisplayFunc(displayDragon);
    glutReshapeFunc(reshape);
    glutSpecialFunc(SpecialKeys);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutMainLoop();
    return 0;
}

*/
