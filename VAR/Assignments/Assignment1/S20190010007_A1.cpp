#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;
#define MNP 50

vector<pair<float, float>> plotPnts;

int maxHeight;
int maxWidth;

// deletes the last point
void delLP()
{
	auto itr = plotPnts.end();
	plotPnts.erase(itr);
}

// deletes the first point
void delFP()
{
	auto itr = plotPnts.begin();
	plotPnts.erase(itr);
}

// adds input point
void addInputPnt(float x, float y)
{
	int NumPts = plotPnts.size();
	if (NumPts >= MNP)
	{
		delFP();
	}
	plotPnts.push_back({x, y});
}

// handles mouse input
void mosInp(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		float X_Pos = ((float)x) / ((float)(maxWidth - 1));
		float Y_Pos = ((float)y) / ((float)(maxHeight - 1));

		Y_Pos = 1.0f - Y_Pos;

		addInputPnt(X_Pos, Y_Pos);
		glutPostRedisplay();
	}
}

// get points from the input textfiles and prase the data
vector<float> getPnt(string s)
{
	vector<float> pnt;
	stringstream ss(s);
	string word;
	while (ss >> word)
	{
		float p = stof(word);
		pnt.push_back(p);
	}
	return pnt;
}

// loads input data from the text file
void loadInputFile()
{
	plotPnts.clear();
	fstream myFile;
	myFile.open("points.txt");
	string myText;

	if (myFile.is_open())
	{
		// get each line from the input file
		while (getline(myFile, myText))
		{
			vector<float> pnt = getPnt(myText);

			float X_Pos = pnt[0], Y_Pos = pnt[1];
			if (X_Pos > 1 || X_Pos < 0)
				X_Pos = ((float)pnt[0]) / ((float)(maxWidth - 1));
			if (Y_Pos > 1 || Y_Pos < 0)
				Y_Pos = ((float)pnt[1]) / ((float)(maxHeight - 1));

			plotPnts.push_back({X_Pos, Y_Pos});
		}
		myFile.close();
	}
}

// display the output figure
void display(void)
{
	int i, NumPts = plotPnts.size();
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0f, 1.0f, 0.0f);
	if (NumPts > 1)
	{
		glBegin(GL_LINE_STRIP);
		for (i = 0; i < NumPts; i++)
		{
			glVertex2f(plotPnts[i].first, plotPnts[i].second);
		}
		glVertex2f(plotPnts[0].first, plotPnts[0].second);
		glEnd();
	}

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	for (i = 0; i < NumPts; i++)
	{
		glVertex2f(plotPnts[i].first, plotPnts[i].second);
	}
	glEnd();

	glFlush();
}

// initializing rendering of the figure
void initializeRendering()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glPointSize(8);
	glLineWidth(5);

	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void reSize(int width, int height)
{
	maxHeight = (height > 1) ? height : 2;
	maxWidth = (width > 1) ? width : 2;
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, 1.0f, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// handling keyboard inputs
void keyboardInput(unsigned char key, int x, int y)
{
    // cout << "Click only a maximum of 50 points" << endl;
    // cout << "Enter 'l' to remove last point" << endl;
    // cout << "Enter 'f' to remove first point" << endl;
    // cout << "Enter 'e' to exit from window" << endl;

	switch (key)
	{
        case 'f':
            loadInputFile();
            glutPostRedisplay();
            break;
        case 'c':
            plotPnts.clear();
            glutPostRedisplay();
            break;
        case 'r':
            delFP();
            glutPostRedisplay();
            break;
        case 'l':
            delLP();
            glutPostRedisplay();
            break;
        case 'e':
            exit(0);
            break;
	}
}

int main(int argc, char **argv)
{
    cout<<"------------------------------------------"<<endl;
    cout << "NOTE: Click only a maximum of 50 points" << endl;
    cout<<"------------------------------------------"<<endl;

    cout<<"INSTRUCTIONS: "<<endl;
    cout<<"------------------------------------------"<<endl;
    cout << "Enter 'r' to remove first point" << endl;
    cout << "Enter 'l' to remove last point" << endl;
    cout << "Enter 'f' for file input" << endl;
    cout << "Enter 'e' to exit from window" << endl;
    

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	initializeRendering();

	glutDisplayFunc(display);
	glutReshapeFunc(reSize);
	glutKeyboardFunc(keyboardInput);
	glutMouseFunc(mosInp);
	glutMainLoop();

	return 0;
}
