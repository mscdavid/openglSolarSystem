#include <GL/freeglut.h>
#include <math.h>
#define PI 3.141592

static int Day = 0, Time = 0, Year = 0;
float camX = 0.0f, camY = 6.0f, camZ = 0.01f;
float dragX = 0.0f, dragY = 0.0f, dragZ = 0.0f;
float dragMovedX, dragMovedY, dragMovedZ;
float dragrotatedX, dragrotatedY, dragrotatedZ;
float lookX = 0.0f, lookY = 0.0f, lookZ = 0.0f;
float ThetaX = 0.0f, ThetaY = 0.0f, ThetaZ = 0.0f;

float tempX, tempY, tempZ;
float zoomFactor = 1.0f;

int mouseX, mouseY;

bool isLeftButtonPressed = false, isRightButtonPressed = false;



void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    dragMovedX = camX * zoomFactor;
    dragMovedY = camY * zoomFactor;
    dragMovedZ = camZ * zoomFactor;

    dragrotatedX = lookX + dragX;
    dragrotatedY = lookY;
    dragrotatedZ = lookZ - dragZ;

    

    tempX = dragMovedX;
    tempY = dragMovedY * cos(ThetaZ * PI / 180.0) + dragMovedZ * sin(ThetaZ * PI / 180.0);
    tempZ = dragMovedZ * cos(ThetaZ * PI / 180.0) - dragMovedY * sin(ThetaZ * PI / 180.0);
    dragMovedX = tempX;
    dragMovedY = tempY;
    dragMovedZ = tempZ;

    tempX = dragMovedX * cos(ThetaX * PI / 180.0) + dragMovedZ * sin(ThetaX * PI / 180.0);
    tempY = dragMovedY; 
    tempZ = dragMovedZ * cos(ThetaX * PI / 180.0) - dragMovedX * sin(ThetaX * PI / 180.0);
    dragMovedX = tempX;
    dragMovedY = tempY;
    dragMovedZ = tempZ;


    gluLookAt(dragMovedX + dragX , dragMovedY, dragMovedZ - dragZ,
        dragrotatedX, dragrotatedY, dragrotatedZ,
        0.0, 1.0, 0.0);

    //Sun
    glColor3f(1.0, 0.2, 0.2);
    glRotatef(90, 1.0, 0.0, 0.0);
    glutWireSphere(0.4, 40, 20);

    // Earth
    glPushMatrix();
        glRotatef(-(GLfloat)Year/GLfloat(5), 0.0, 0.0, 1.0);
        glTranslatef(2.0, 0.0, 0.0);
        glRotatef((GLfloat)Day, 0.0, 0.0, 1.0);
        glColor3f(0.3, 1.0, 0.3);
        glutWireSphere(0.04, 30, 8);

    // Moon
        glPushMatrix();
            glRotatef(-(GLfloat)Year/GLfloat(4), 0.0, 0.0, 1.0);
            glTranslatef(0.2, 0.0, 0.0);
            glRotatef((GLfloat)Day/GLfloat(4), 0.0, 0.0, 1.0);
            glColor3f(0.9, 0.8, 0.2);
            glutWireSphere(0.01, 10, 8);
        glPopMatrix();
    glPopMatrix();

    ///Mercury

    glPushMatrix();
        glRotatef(-(GLfloat)Year / GLfloat(1.3), 0.0, 0.0, 1.0);
        glTranslatef(0.8, 0.0, 0.0);
        glRotatef((GLfloat)Day, 0.0, 0.0, 1.0);
        glColor3f(0.1, 0.2, 0.8);
        glutWireSphere(0.02, 10, 8);
    glPopMatrix();

    ///Venus
    glPushMatrix();
        glRotatef(-(GLfloat)Year / GLfloat(2.3), 0.0, 0.0, 1.0);
        glTranslatef(1.2, 0.0, 0.0);
        glRotatef(-(GLfloat)Day, 0.0, 0.0, 1.0);
        glColor3f(0.8, 0.5, 0.3);
        glutWireSphere(0.03, 10, 8);
    glPopMatrix();

    ///Mars
    glPushMatrix();
        glRotatef(-(GLfloat)Year / GLfloat(5.5), 0.0, 0.0, 1.0);
        glTranslatef(2.6, 0.0, 0.0);
        glRotatef(-(GLfloat)Day, 0.0, 0.0, 1.0);
        glColor3f(0.8, 0.5, 0.3);
        glutWireSphere(0.03, 10, 8);
    glPopMatrix();

    ///Jupiter
    glPushMatrix();
        glRotatef(-(GLfloat)Year / GLfloat(6.0), 0.0, 0.0, 1.0);
        glTranslatef(3.1, 0.0, 0.0);
        glRotatef(-(GLfloat)Day, 0.0, 0.0, 1.0);
        glColor3f(0.8, 0.8, 0.1);
        glutWireSphere(0.09, 10, 8);
    glPopMatrix();

    ////Saturn
    glPushMatrix();
        glRotatef(-(GLfloat)Year / GLfloat(6.6), 0.0, 0.0, 1.0);
        glTranslatef(3.5, 0.0, 0.0);
        glRotatef(-(GLfloat)Day, 0.0, 0.0, 1.0);
        glColor3f(0.8, 0.5, 0.3);
        glutWireSphere(0.1, 10, 8);
    glPopMatrix();

    ///Uranus
    glPushMatrix();
        glRotatef(-(GLfloat)Year / GLfloat(7.0), 0.0, 0.0, 1.0);
        glTranslatef(4.0, 0.0, 0.0);
        glRotatef(-(GLfloat)Day, 0.0, 0.0, 1.0);
        glColor3f(0.1, 0.2, 0.9);
        glutWireSphere(0.06, 10, 8);
    glPopMatrix();

    ////Neptune
    glPushMatrix();
        glRotatef(-(GLfloat)Year / GLfloat(7.5), 0.0, 0.0, 1.0);
        glTranslatef(4.4, 0.0, 0.0);
        glRotatef(-(GLfloat)Day, 0.0, 0.0, 1.0);
        glColor3f(0.1, 0.5, 0.9);
        glutWireSphere(0.05, 10, 8);
    glPopMatrix();


    glutSwapBuffers();
}

void MyKeyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'd':
        Day = (Day + 10) % 360;
        glutPostRedisplay();
        break;
    case 't':
        Time = (Time + 5) % 360;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 1000.0);
}

void OnMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            mouseX = x;
            mouseY = y;
            isLeftButtonPressed = true;
        }
        else {
            isLeftButtonPressed = false;
        }
    }
    else if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            mouseX = x;
            mouseY = y;
            isRightButtonPressed = true;
        }
        else {
            isRightButtonPressed = false;
        }
    }
 
}

void OnMouseMove(int x, int y) {
    int dx = x - mouseX;
    int dz = y - mouseY;
    mouseX = x;
    mouseY = y;

    if (isLeftButtonPressed) {
        // Rotate camera around the origin
        dragX += dx * 0.001f;
        dragZ += dz * 0.001f;
    }

    if (isRightButtonPressed) {
        // Adjust the target point (where the camera looks)
        ThetaX -= dx * 0.07f;
        ThetaZ += dz * 0.07f;
       
    }

    glutPostRedisplay();
}

void OnMouseWheel(int button, int dir, int x, int y) {
    if (dir > 0) {
        // Zoom in
        zoomFactor *= 0.9f;
    }
    else {
        // Zoom out
        zoomFactor *= 1.1f;
    }
    glutPostRedisplay();
}


void IdleFunction() {
    Year = (Year + 1) ;
    Day = (Day + 1) ;
    Time = (Time + 1) ;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Sample Drawing");
    glClearColor(0.0, 0.0, 0.0, 1.0);

  

    
    glutReshapeFunc(MyReshape);
    glutKeyboardFunc(MyKeyboard);
    glutIdleFunc(IdleFunction); 
    glutMouseFunc(OnMouseClick);
    glutMotionFunc(OnMouseMove);
    glutMouseWheelFunc(OnMouseWheel);
    glutDisplayFunc(MyDisplay);

    
    glutMainLoop();
    return 0;
}
