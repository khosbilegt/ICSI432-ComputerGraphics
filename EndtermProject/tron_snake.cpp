// B. Khosbilegt 20b1num2325
// W, A, S, D for Controls
// R for Restart
// Score added per movement | motion.

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>
#include <GLUT/glutbitmap.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

// Store Path Variables
struct Path {
    int x, z;
};

int cubeX = 0, cubeZ = 0; // Player Position via glTranslatef
int currentScore, lost = 0;
Path path[500]; // Array to store Paths for rendering
int maxScore;

// Check if Cube overlapping with Paths
int checkLost() {
    int i;
    for(i = 0; i < currentScore; i++) {
        if(cubeX == path[i].x && cubeZ == path[i].z) {
            return 1;
        }
    }
    return 0;
}

// Render Score
void renderScore(char *string, char *scoreChar) {
    glColor3f(0, 0.5, 1);
    glRasterPos2f(0, 2);
    int len, len2, i;
    len = (int)strlen(string);
    len2 = (int)strlen(scoreChar);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
    }
    for (i = 0; i < 3; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scoreChar[i]);
    }
}

// Render Game Over Text
void renderLost(char *string) {
    glColor3f(1, 0, 0);
    glRasterPos2f(10, 2);
    int len, i;
    len = (int)strlen(string);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
    }
}

// Render Max Score
void renderMax(char *string, char *maxScore) {
    glColor3f(0, 0.5, 1);
    glRasterPos2f(0, 2);
    int i, len;
    len = (int)strlen(string);
    glRasterPos2f(0, 4);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
    }
    for (i = 0; i < 3; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, maxScore[i]);
    }
}

// Render Paths (Red Line)
void renderPath() {
    int i;
    for(i = 0; i < currentScore; i++) {
        glColor3f(1, 0, 0);
        glBegin(GL_POLYGON); // All Polygons form faces of cubes that make up path
        glVertex3f(path[i].x - 0.5, 0.4, path[i].z + 0.5);
        glVertex3f(path[i].x + 0.5, 0.4, path[i].z + 0.5);
        glVertex3f(path[i].x + 0.5, 0.4, path[i].z - 0.5);
        glVertex3f(path[i].x - 0.5, 0.4, path[i].z - 0.5);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(path[i].x - 0.5, 0.4, path[i].z + 0.5);
        glVertex3f(path[i].x + 0.5, 0.4, path[i].z + 0.5);
        glVertex3f(path[i].x + 0.5, -0.2, path[i].z + 0.5);
        glVertex3f(path[i].x - 0.5, -0.2, path[i].z + 0.5);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(path[i].x - 0.5, 0.4, path[i].z - 0.5);
        glVertex3f(path[i].x + 0.5, 0.4, path[i].z - 0.5);
        glVertex3f(path[i].x + 0.5, -0.2, path[i].z - 0.5);
        glVertex3f(path[i].x - 0.5, -0.2, path[i].z - 0.5);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(path[i].x + 0.5, 0.4, path[i].z - 0.5);
        glVertex3f(path[i].x + 0.5, 0.4, path[i].z + 0.5);
        glVertex3f(path[i].x + 0.5, -0.2, path[i].z + 0.5);
        glVertex3f(path[i].x + 0.5, -0.2, path[i].z - 0.5);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(path[i].x - 0.5, 0.4, path[i].z - 0.5);
        glVertex3f(path[i].x - 0.5, 0.4, path[i].z + 0.5);
        glVertex3f(path[i].x - 0.5, -0.2, path[i].z + 0.5);
        glVertex3f(path[i].x - 0.5, -0.2, path[i].z - 0.5);
        glEnd();
    }
}

// Render Player
void renderCube() {
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(cubeX, 0, cubeZ); // Controls through transform
    glutSolidCube(0.6);
    glPopMatrix(); // Makes transform apply only to cube and not other objects after Push Matrix.
}

// Render Ground
void renderGrid() {
    int i;
    glColor3f(1, 1, 1);
    glLineWidth(1);
    for(i = 0; i < 40; i++) {
        glPushMatrix();
        if(i < 20) {
            glTranslatef(0, 0, i);
        }
        if(i >= 20) {
            glTranslatef(i - 20, 0, 0);
            glRotatef(-90, 0, 1, 0);
        }
        glBegin(GL_LINES);
        glVertex3f(0, -0.1, 0);
        glVertex3f(19, -0.1, 0); // 19 is length, can't be changed
        glEnd();
        glPopMatrix();
    }
}

void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-10, 0, -50); // Setting Camera Location (by changing field location)
    glRotatef(30, 1, 0, 0);
    
    renderGrid(); // Render Ground
    renderCube(); // Render Player
    renderPath(); // Render Path
    string scoreString = to_string(currentScore); // Convert score to string to show as text
    char scoreChar[3];
    strcpy(scoreChar, scoreString.c_str());renderScore("Score: ", scoreChar);string maxString = to_string(maxScore);
    char maxChar[10];
    strcpy(maxChar, maxString.c_str());
    renderMax("Max Score: ", maxChar);
    if(lost == 1) {
        renderLost("GAME OVER");
    }
    glutSwapBuffers();
}f

// Setup
void initScene() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(35, 1, 0.5, 1000); // Set Camera Location
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
}

// Control Function
void gameControls(unsigned char key, int x, int y) {
    if(lost == 0) {
        if(key == 'w' && cubeZ > 0) {
            cubeZ -= 1;
            currentScore++; // Each movement increases score by 1
        }
        if(key == 'a' && cubeX > 0) {
            cubeX -= 1;
            currentScore++;
        }
        if(key == 's' && cubeZ < 19) {
            cubeZ += 1;
            currentScore++;
        }
        if(key == 'd' && cubeX < 19) {
            cubeX += 1;
            currentScore++;
        }
        path[currentScore].x = cubeX; // Setting Path Location for X
        path[currentScore].z = cubeZ; // Setting Path Location for X
        lost = checkLost(); // Check if lost
        if(currentScore > maxScore) { // Update High Score
            maxScore = currentScore;
        }
    } else {
        if(key == 'r') { // Restart Function
            int i;
            lost = 0;
            cubeX = 0;
            cubeZ = 0;
            for(i = 0; i < currentScore; i++) { // Emptying Array
                path[i].x = 0;
                path[i].z = 0;
            }
            currentScore = 0;
        }
    }
    glutPostRedisplay(); // Must use to display changes
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE); // Double Buffered, one for drawing and another for displaying
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tron Copy");
    glClearColor(0.5, 0.5, 1, 1); // Set Background Color
    initScene();
    glutDisplayFunc(renderScene); // Adding Graphics
    glutKeyboardFunc(gameControls); // Adding Keyboard Controls
    glutMainLoop(); // Looping program until closed
    return 0;
}


