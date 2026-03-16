#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898

void LingkaranSolid(float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); 
    for (int i = 0; i <= 100; i++) {
        float angle = 2 * PI * i / 100;
        glVertex2f(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}

void GambarMobil2D(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Matahari
    glPushMatrix();
    glTranslatef(0.7f, 0.7f, 0.0f); 
    glColor3f(1.0f, 0.8f, 0.0f);    
    LingkaranSolid(0.15f);
    glPopMatrix();
    
    // Awan kiri
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(-0.7f, 0.65f, 0.0f);     
    LingkaranSolid(0.10f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.6f, 0.68f, 0.0f); 
    LingkaranSolid(0.10f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.5f, 0.65f, 0.0f);  
    LingkaranSolid(0.10f);
    glPopMatrix();
    
    // Awan kanan
    glPushMatrix();
    glTranslatef(0.1f, 0.68f, 0.0f);   
    LingkaranSolid(0.10f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.2f, 0.71f, 0.0f);    
    LingkaranSolid(0.10f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.3f, 0.68f, 0.0f);   
    LingkaranSolid(0.10f);
    glPopMatrix();


	// Jalan raya
    glColor3f(0.2f, 0.2f, 0.2f); 
    glRectf(-1.0f, -1.0f, 1.0f, -0.4f);


    // MOBIL
    glPushMatrix(); 
    glTranslatef(0.0f, -0.2f, 0.0f); 

    // Bodi bawah
    glColor3f(0.1f, 0.1f, 0.1f); 
    glBegin(GL_QUADS);
    glVertex2f(-0.6f, -0.1f); 
    glVertex2f( 0.6f, -0.1f); 
    glVertex2f( 0.6f,  0.2f); 
    glVertex2f(-0.6f,  0.2f); 
    glEnd();

    // Kabin atas
    glColor3f(0.9f, 0.9f, 0.9f); 
    glRectf(-0.4f, 0.2f, 0.3f, 0.45f);

    // Jendela 
    glColor3f(0.2f, 0.3f, 0.4f); // Kaca gelap
    glRectf(-0.35f, 0.25f, -0.05f, 0.40f); // Jendela belakang
    glRectf( 0.00f, 0.25f,  0.25f, 0.40f); // Jendela depan

    // Sirine 
    glPushMatrix();
    glTranslatef(-0.05f, 0.45f, 0.0f); 
    glColor3f(1.0f, 0.0f, 0.0f);       // Kotak merah
    glRectf(-0.1f, 0.0f, 0.0f, 0.08f);
    glColor3f(0.0f, 0.0f, 1.0f);       // Kotak biru
    glRectf(0.0f, 0.0f, 0.1f, 0.08f);
    glPopMatrix();
    
    // Roda belakang
    glPushMatrix(); 
    glTranslatef(-0.35f, -0.1f, 0.0f);  
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f); 
    
    glColor3f(0.05f, 0.05f, 0.05f); LingkaranSolid(0.15f); // Ban
    glColor3f(0.7f, 0.7f, 0.7f);    LingkaranSolid(0.08f); // Velg
    
    glColor3f(1.0f, 1.0f, 1.0f); 
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.08f, 0.0f); glVertex2f(0.08f, 0.0f); 
    glVertex2f(0.0f, -0.08f); glVertex2f(0.0f, 0.08f); 
    glEnd();
    glPopMatrix();

    // Roda depan
    glPushMatrix(); 
    glTranslatef(0.35f, -0.1f, 0.0f);   
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f); 
    
    glColor3f(0.05f, 0.05f, 0.05f); LingkaranSolid(0.15f);
    glColor3f(0.7f, 0.7f, 0.7f);    LingkaranSolid(0.08f);
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.08f, 0.0f); glVertex2f(0.08f, 0.0f);
    glVertex2f(0.0f, -0.08f); glVertex2f(0.0f, 0.08f);
    glEnd();
    glPopMatrix();

    glPopMatrix(); 

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(700, 500); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    
    glutCreateWindow("Muhammad Akmal Fazli Riyadi (24060124130123)");
    glutDisplayFunc(GambarMobil2D);
    
    glClearColor(0.5f, 0.7f, 1.0f, 1.0f); 
    
    glutMainLoop();
    return 0;
}
