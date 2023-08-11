#include<iostream>
#include<GL/freeglut.h>

int width = 700;
int height = 700;

int count = -1;
struct Points
{
public:
	float x;
	float y;
};
Points p[50];

void DrawPoints(void)
{
	glColor3f(1, 0, 0);
	glPointSize(10);
	glBegin(GL_POINTS);
	for (int i = 0; i <= count; i++)
	{
		glVertex2f(p[i].x, p[i].y);
	}
	glEnd();
	glFlush();
}

void ClearScreen(void)
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void DrawLine(void)
{
	glColor3f(0, 1, 0);
	glLineWidth(5);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= count; i++)
	{
		glVertex2f(p[i].x, p[i].y);
	}
	glEnd();
	glFlush();
}

void Display(void)
{
	ClearScreen();
	DrawPoints();
	DrawLine();
}

void Init(void)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, height, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Mouse(int button, int state, int X, int Y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		count++;
		p[count].x = X;
		p[count].y = Y;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(300, 50);
	glutCreateWindow("EXAM CG SEM");
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutDisplayFunc(Display);
	glutMouseFunc(Mouse);
	Init();

	glutMainLoop();

	return 0;
}