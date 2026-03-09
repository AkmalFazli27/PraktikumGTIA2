#include <GL/glut.h>

void TampilBentuk(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // 1. GL_LINE_STRIP (Minimal 3 titik)
    glBegin(GL_LINE_STRIP); 
    glVertex2f(-0.8, 0.8); 
	glVertex2f(-0.6, 0.6); 
	glVertex2f(-0.4, 0.8);
    glEnd();

    // 2. GL_LINE_LOOP (Minimal 3 titik)
    glBegin(GL_LINE_LOOP); 
    glVertex2f(0.4, 0.8); 
	glVertex2f(0.6, 0.6); 
	glVertex2f(0.8, 0.8);
    glEnd();

    // 3. GL_TRIANGLE_STRIP (Minimal 4 titik)
    glBegin(GL_TRIANGLE_STRIP); 
    glVertex2f(-0.8, 0.2); 
	glVertex2f(-0.6, -0.2); 
	glVertex2f(-0.4, 0.2); 
	glVertex2f(-0.2, -0.2);
    glEnd();

    // 4. GL_TRIANGLE_FAN (Minimal 4 titik)
    glBegin(GL_TRIANGLE_FAN); 
    glVertex2f(0.5, 0.0); 
	glVertex2f(0.3, 0.3); 
	glVertex2f(0.7, 0.3); 
	glVertex2f(0.9, 0.0);
    glEnd();

    // 5. GL_QUADS (Minimal 4 titik)
    glBegin(GL_QUADS); 
    glVertex2f(-0.8, -0.8); 
	glVertex2f(-0.4, -0.8); 
	glVertex2f(-0.4, -0.4); 
	glVertex2f(-0.8, -0.4);
    glEnd();

    // 6. GL_QUAD_STRIP (Minimal 6 titik)
    glBegin(GL_QUAD_STRIP); 
    glVertex2f(0.2, -0.8); 
	glVertex2f(0.2, -0.4); 
	glVertex2f(0.5, -0.8); 
	glVertex2f(0.5, -0.4); 
	glVertex2f(0.8, -0.8); 
	glVertex2f(0.8, -0.4);
    glEnd();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutCreateWindow("Muhammad Akmal Fazli Riyadi (24060124130123)");
    glutDisplayFunc(TampilBentuk);
    glutMainLoop();
    return 0;
}
