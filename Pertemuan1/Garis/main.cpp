#include <gl/glut.h>

void Garis(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // Warna garis putih
    glVertex3f(0.00, 0.20, 0.0); // Titik awal garis
    glVertex3f(0.00, -0.20, 0.0); // Titik akhir garis
    glEnd();
    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Membuat Garis");
    glutDisplayFunc(Garis);    
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Background biru  
    glutMainLoop();    
    return 0;
}
