/*
#include "def.h"

void display();
void reshape(int,int);
void SpecialKeys(int,int,int);

char which;
#define SIL GLU_SILHOUETTE
#define FILL GLU_LINE
GLfloat winWidth, winHeight;
void read_file (char **argv);
float vertices [50000][3];
int facets [100000][3];
float scale = 1;
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

void init() {
    glClearColor(0.239 , 0.282 , 0.982 , 1);
    GLfloat ambient[] = {1,0,0,1};
    GLfloat diffuse[] = {1,1,1,1};
    GLfloat specular[] = {1,1,1,1};
    GLfloat position[] = {0,0,5,0}; // Light Position

    GLfloat lmodel_ambient[] = {0.2,0.2,0.2,1};
    GLfloat local_view[] = {0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

    glFrontFace(GL_CW);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
}

void normalize(float*v) {
    float length = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
    for(int i = 0; i<3; i++) {
        v[i] = v[i]/length;
    }
}

float *crossProduct(float*a,float*b) {
    float result[] = {a[1]*b[2]-a[2]*b[1], - (a[0]*b[2]-a[2]*b[0]), a[0]*b[1]-a[1]*b[0]};
    normalize(result);
    return result;
}

float *calcNormal(float *a, float *b, float *c) {
    float x[] = {b[0]-a[0],b[1]-a[1],b[2]-a[2]};
    float y[] = {c[0]-a[0],c[1]-a[1],c[2]-a[2]};
    float *result = crossProduct(x,y);
    return result;
}

void drawDragon(GLfloat x, GLfloat y, GLfloat ambientRed, GLfloat ambientGreen, GLfloat ambientBlue, GLfloat diffuseRed, GLfloat diffuseGreen, GLfloat diffuseBlue,GLfloat specularRed, GLfloat specularGreen, GLfloat specularBlue, GLfloat shine) {
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 0.0f, 1.0f);
    GLfloat mat[4];
    int i;
    float normal[3];
    glTranslatef(x, y, 0.0);
    mat[0] = ambientRed;
    mat[1] = ambientGreen;
    mat[2] = ambientBlue;
    mat[3] = 1.0;
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
    
    mat[0] = diffuseRed;
    mat[1] = diffuseGreen;
    mat[2] = diffuseBlue;
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
    
    mat[0] = specularRed;
    mat[1] = specularBlue;
    mat[2] = specularGreen;
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
    
    glMaterialf(GL_FRONT, GL_SHININESS, shine);

    glBegin(GL_TRIANGLES);
    glColor3f(0,1,0);
    for (i = 0; i <100000; ++i) {
        glNormal3fv(calcNormal(vertices[facets[i][0]-1],vertices[facets[i][1]-1],vertices[facets[i][2]-1]));
        glVertex3fv(vertices[facets[i][0]-1]);
        glVertex3fv(vertices[facets[i][1]-1]);
        glVertex3fv(vertices[facets[i][2]-1]);
    }
    glEnd();
}

void display() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1,1,-1,1,1,-1);
    glViewport(0,0,1000,1000);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Black Plastic
    drawDragon(0, 0, 0, 0, 0, 0.01, 0.01, 0.01, 0.5, 0.5, 0.5, 1);
    glutSwapBuffers();
}

void reshape(int w, int h) {
    if(h == 0) {
        h = 1;
    }
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w <= h ) {
        winHeight=250*h/w;
        winWidth=250;
    } else {
        winWidth=250*w/h;
        winHeight=250;
    }
    glOrtho(0, winWidth, 0, winHeight, 1, -1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void readFile(char **argv) {
    int loopv = 0;
    int loopf = 0;

    FILE *dragon;
    dragon = fopen("/Users/xocoo/Desktop/Classes/2nd Year/Computer Graphics/Test/Test/dragon.obj", "r");

    if (dragon == NULL)
    {
        printf("\ncan't open input file\n");
        exit (1);
    }

    while(!feof(dragon)){
        fscanf(dragon,"%c",&which);
        if(which == 'v')
        {
            fscanf(dragon,"%f",&vertices[loopv][0]);
            fscanf(dragon,"%f",&vertices[loopv][1]);
            fscanf(dragon,"%f",&vertices[loopv][2]);
            loopv = loopv+1;
        }
        else if(which == 'f')
        {
            fscanf(dragon,"%d",&facets[loopf][0]);
            fscanf(dragon,"%d",&facets[loopf][1]);
            fscanf(dragon,"%d",&facets[loopf][2]);
            loopf = loopf+1;
        }
    }
}

void SpecialKeys(int key, int x, int y) {
    if(key == GLUT_KEY_UP)
        xRot-= 5.0f;

    if(key == GLUT_KEY_DOWN)
        xRot += 5.0f;

    if(key == GLUT_KEY_LEFT)
        yRot -= 5.0f;

    if(key == GLUT_KEY_RIGHT)
        yRot += 5.0f;

    if(key > 356.0f)
        xRot = 0.0f;

    if(key < -1.0f)
        xRot = 355.0f;

    if(key > 356.0f)
        yRot = 0.0f;

    if(key < -1.0f)
        yRot = 355.0f;

    if(key == '+')
        scale+=5.0f;
    if(key == '-')
        scale-=5.0f;

    glutPostRedisplay();
}


int main(int args, char**argv) {
    glutInit(&args,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(400,0);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Display Dragon");
    glutDisplayFunc(display);
    glutSpecialFunc(SpecialKeys);

    glutReshapeFunc(reshape);
    readFile(argv);
    init();
    glutMainLoop();
}
*/
