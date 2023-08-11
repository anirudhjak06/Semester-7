// Draw and Rotate a Triangle about the Origin and a Fixed Point


#include <GL/glew.h> // Include the GLEW header file
#include <GL/glut.h> // Include the GLUT header file

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
    //glBegin(GL_QUADS);
     
    // First polygon
    glColor3f(1, 0, 0); // Red
    glBegin(GL_LINE_LOOP);
    //glBegin(GL_TRIANGLES);
    glVertex2f(0.1, 0.4);
    glVertex2f(0.7, 0.4);
    glVertex2f(0.4, 0.8);
    //glVertex2f(-0.3f,  0.3f);
   	glEnd();

    // Rotation based on pivot/fixed point
    glTranslatef(0.7, 0.4,0);
    glRotatef(45,0,0,1);
   	glTranslatef(-0.7, -0.4,0);

   	//glScalef(0.5, 1.0, 0); 
   	//Second Polygon
   	glColor3f(0, 1, 0); // Green
   	glBegin(GL_LINE_LOOP);
    glVertex2f(0.1, 0.4);
    glVertex2f(0.7, 0.4);
    glVertex2f(0.4, 0.8);
    //glVertex2f(-0.3f,  0.3f);
   	glEnd();
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("Rotation_Example");
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}