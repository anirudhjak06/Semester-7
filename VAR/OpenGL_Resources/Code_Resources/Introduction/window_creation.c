#include <GL/gl.h>
#include <GL/glut.h>
  
void display (void) 
{  
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Clear the background of our window to red  
	glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)  
	glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations  
	glFlush(); // Flush the OpenGL buffers to the window  
}  
  
int main (int argc, char **argv) 
{  
	glutInit(&argc, argv); // Initialize GLUT  
	glutInitWindowSize (700, 700); // Set the width and height of the window  
	glutInitWindowPosition(300, 300); // Set the position of the window  
	glutCreateWindow ("Your first OpenGL Window"); // Set the title for the window  
	glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering  
	glutMainLoop(); // Enter GLUT's main loop  
}  