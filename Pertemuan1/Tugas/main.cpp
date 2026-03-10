#include <GL/glut.h>

void TampilBentuk(void) 
{
    glClear(GL_COLOR_BUFFER_BIT);

    // 1. GL_LINE_STRIP
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.9, 0.8); 
	glVertex2f(-0.7, 0.6); 
	glVertex2f(-0.5, 0.8);
    glEnd();

    // 2. GL_LINE_LOOP
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.2, 0.8); 
	glVertex2f(-0.3, 0.6); 
	glVertex2f(0.0, 0.6);
    glEnd();

    // 3. GL_TRIANGLE_STRIP
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(0.5, 0.8); 
	glVertex2f(0.5, 0.6);
	glVertex2f(0.7, 0.8); 
	glVertex2f(0.7, 0.6);
    glEnd();

    // 4. GL_TRIANGLE_FAN
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.7, 0.1); 
	glVertex2f(-0.9, 0.4); 
	glVertex2f(-0.5, 0.4); 
	glVertex2f(-0.5, 0.1);
    glEnd();

    // 5. GL_QUADS
    glBegin(GL_QUADS);
    glVertex2f(-0.2, 0.1); 
	glVertex2f(0.2, 0.1); 
	glVertex2f(0.2, 0.4); 
	glVertex2f(-0.2, 0.4);
    glEnd();

    // 6. GL_QUAD_STRIP
    glBegin(GL_QUAD_STRIP);
    glVertex2f(0.5, 0.1); 
	glVertex2f(0.5, 0.4); 
	glVertex2f(0.7, 0.1); 
	glVertex2f(0.7, 0.4); 
	glVertex2f(0.9, 0.1); 
	glVertex2f(0.9, 0.4);
    glEnd();

    // 7. PERSEGI BERTINGKAT
    glRectf(-0.30, -0.60, -0.12, -0.40); 
    glRectf(-0.10, -0.60,  0.08, -0.40); 
    glRectf( 0.10, -0.60,  0.28, -0.40); 
    glRectf(-0.20, -0.38, -0.02, -0.18); 
    glRectf( 0.00, -0.38,  0.18, -0.18); 

    glFlush();
}

int main(int argc, char* argv[]) 
{
    glutInit(&argc, argv);
    glutCreateWindow("Muhammad Akmal Fazli Riyadi (24060124130123)");
    glutDisplayFunc(TampilBentuk);
    glutMainLoop();
    return 0;
}
