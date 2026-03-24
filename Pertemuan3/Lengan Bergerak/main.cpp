#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

static int shoulder = 0, elbow = 0;
static int fingerJointCount[5] = {2, 3, 3, 3, 3};
static int fingerAngles[5][3] = {
    {0, 0, 0}, // jempol
    {0, 0, 0}, // telunjuk
    {0, 0, 0}, // tengah
    {0, 0, 0}, // manis
    {0, 0, 0}  // kelingking
};

void adjustFingerJoint(int finger, int joint, int delta) {
    if (finger < 0 || finger > 4) return;
    if (joint < 0 || joint >= fingerJointCount[finger]) return;

    fingerAngles[finger][joint] += delta;
    if (fingerAngles[finger][joint] > 90) fingerAngles[finger][joint] = 90;
    if (fingerAngles[finger][joint] < 0) fingerAngles[finger][joint] = 0;
}

void drawPhalanx(float length, float thickness) {
    glPushMatrix();
    glTranslatef(length * 0.5f, 0.0f, 0.0f);
    glScalef(length, thickness, thickness);
    glutWireCube(1.0);
    glPopMatrix();
}

void drawFinger3(int index, float yOffset) {
    float a1 = (GLfloat)fingerAngles[index][0];
    float a2 = (GLfloat)fingerAngles[index][1];
    float a3 = (GLfloat)fingerAngles[index][2];

    glPushMatrix();
    glTranslatef(0.6f, yOffset, 0.0f);
    glRotatef(a1, 0.0, -1.0, 0.0);
    drawPhalanx(0.45f, 0.12f);

    glTranslatef(0.45f, 0.0f, 0.0f);
    glRotatef(a2, 0.0, -1.0, 0.0);
    drawPhalanx(0.32f, 0.10f);

    glTranslatef(0.32f, 0.0f, 0.0f);
    glRotatef(a3, 0.0, -1.0, 0.0);
    drawPhalanx(0.24f, 0.09f);

    glPopMatrix();
}

void drawThumb2(int index, float yOffset) {
    float a1 = (GLfloat)fingerAngles[index][0];
    float a2 = (GLfloat)fingerAngles[index][1];

    glPushMatrix();
    glTranslatef(0.45f, yOffset, 0.0f);
    glRotatef(35.0f, 0.0, 0.0, 1.0);
    glRotatef(a1, 0.0, -1.0, 0.0);
    drawPhalanx(0.38f, 0.13f);

    glTranslatef(0.38f, 0.0f, 0.0f);
    glRotatef(a2, 0.0, -1.0, 0.0);
    drawPhalanx(0.28f, 0.11f);

    glPopMatrix();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Pergelangan + telapak tangan
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    // ROTASI DIHAPUS DISINI AGAR JARI MERENTANG LURUS KE SUMBU X
    // glRotatef(-90.0f, 0.0f, 1.0f, 0.0f); 

    glPushMatrix();
    glTranslatef(0.3f, 0.0f, 0.0f);
    glScalef(0.6f, 1.0f, 0.6f);
    glutWireCube(1.0);
    glPopMatrix();

    // 5 jari: jempol (2 ruas) + 4 jari (3 ruas)
    drawThumb2(0,  0.55f);
    drawFinger3(1,  0.25f);
    drawFinger3(2,  0.05f);
    drawFinger3(3, -0.15f);
    drawFinger3(4, -0.35f);

    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Bahu & siku
        case 'u': shoulder = (shoulder + 5) % 360; glutPostRedisplay(); break;
        case 'U': shoulder = (shoulder - 5) % 360; glutPostRedisplay(); break;
        case 'i': elbow = (elbow + 5) % 360; glutPostRedisplay(); break;
        case 'I': elbow = (elbow - 5) % 360; glutPostRedisplay(); break;

        // Jempol (2 ruas): q/Q, w/W
        case 'q': adjustFingerJoint(0, 0, 5); glutPostRedisplay(); break;
        case 'Q': adjustFingerJoint(0, 0, -5); glutPostRedisplay(); break;
        case 'w': adjustFingerJoint(0, 1, 5); glutPostRedisplay(); break;
        case 'W': adjustFingerJoint(0, 1, -5); glutPostRedisplay(); break;

        // Telunjuk (3 ruas): a/A, s/S, d/D
        case 'a': adjustFingerJoint(1, 0, 5); glutPostRedisplay(); break;
        case 'A': adjustFingerJoint(1, 0, -5); glutPostRedisplay(); break;
        case 's': adjustFingerJoint(1, 1, 5); glutPostRedisplay(); break;
        case 'S': adjustFingerJoint(1, 1, -5); glutPostRedisplay(); break;
        case 'd': adjustFingerJoint(1, 2, 5); glutPostRedisplay(); break;
        case 'D': adjustFingerJoint(1, 2, -5); glutPostRedisplay(); break;

        // Tengah (3 ruas): z/Z, x/X, c/C
        case 'z': adjustFingerJoint(2, 0, 5); glutPostRedisplay(); break;
        case 'Z': adjustFingerJoint(2, 0, -5); glutPostRedisplay(); break;
        case 'x': adjustFingerJoint(2, 1, 5); glutPostRedisplay(); break;
        case 'X': adjustFingerJoint(2, 1, -5); glutPostRedisplay(); break;
        case 'c': adjustFingerJoint(2, 2, 5); glutPostRedisplay(); break;
        case 'C': adjustFingerJoint(2, 2, -5); glutPostRedisplay(); break;

        // Manis (3 ruas): e/E, r/R, t/T
        case 'e': adjustFingerJoint(3, 0, 5); glutPostRedisplay(); break;
        case 'E': adjustFingerJoint(3, 0, -5); glutPostRedisplay(); break;
        case 'r': adjustFingerJoint(3, 1, 5); glutPostRedisplay(); break;
        case 'R': adjustFingerJoint(3, 1, -5); glutPostRedisplay(); break;
        case 't': adjustFingerJoint(3, 2, 5); glutPostRedisplay(); break;
        case 'T': adjustFingerJoint(3, 2, -5); glutPostRedisplay(); break;

        // Kelingking (3 ruas): f/F, g/G, h/H
        case 'f': adjustFingerJoint(4, 0, 5); glutPostRedisplay(); break;
        case 'F': adjustFingerJoint(4, 0, -5); glutPostRedisplay(); break;
        case 'g': adjustFingerJoint(4, 1, 5); glutPostRedisplay(); break;
        case 'G': adjustFingerJoint(4, 1, -5); glutPostRedisplay(); break;
        case 'h': adjustFingerJoint(4, 2, 5); glutPostRedisplay(); break;
        case 'H': adjustFingerJoint(4, 2, -5); glutPostRedisplay(); break;
        case 27: exit(0); break;
        default: break;
    }
}

int main(int argc, char** argv) {
    printf("Kontrol:\n");
    printf("- Bahu: u/U, Siku: i/I\n");
    printf("- Jempol(2 ruas): q/Q, w/W\n");
    printf("- Telunjuk(3 ruas): a/A, s/S, d/D\n");
    printf("- Tengah(3 ruas): z/Z, x/X, c/C\n");
    printf("- Manis(3 ruas): e/E, r/R, t/T\n");
    printf("- Kelingking(3 ruas): f/F, g/G, h/H\n");
    printf("- ESC: keluar\n");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Muhammad Akmal Fazli Riyadi (24060124130123)");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}