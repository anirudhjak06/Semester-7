//C++ Program to build.

// Write an interactive program to create simple polygons. Your program
// should allow the user to create a polygon by reading points from a file,
// and by interactively adding point coordinates via Keyboard/Mouse
// input. It should also provide options to clear the screen, and exit.

#include <bits/stdc++.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#define MaxNumPts 20

// Import all the required libraries
using namespace std;

// Points array
float point_array[MaxNumPts][2];
int N_Points = 0;

// Window size in pixels
int Height_of_Window;
int Width_of_Window;

void fn_for_removing_First_Point()
{
    int i;
    if (N_Points > 0)
    {
        // Remove the first point, slide the rest down
        N_Points--;
        for (i = 0; i < N_Points; i++)
        {
            point_array[i][0] = point_array[i + 1][0];
            point_array[i][1] = point_array[i + 1][1];
        }
    }
}

// Left button presses place a control point.
// Add a new point to the end of the list.
// Remove the first point in the list if too many points are there.
void removeLastPoint()
{
    if (N_Points > 0)
    {
        N_Points--;
    }
}

// Add a new point .
// Remove the first point in the list if too many points.
void fn_for_adding_New_Point(float x, float y)
{
    if (N_Points >= MaxNumPts)
    {
        fn_for_removing_First_Point();
    }
    point_array[N_Points][0] = x;
    point_array[N_Points][1] = y;
    N_Points++;
}

//
void Fn_my_Mouse_Function(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {

        float xPos = ((float)x) / ((float)(Width_of_Window - 1));
        float yPos = ((float)y) / ((float)(Height_of_Window - 1));

        yPos = 1.0f - yPos; // Flip value since y position is from top row.

        fn_for_adding_New_Point(xPos, yPos);
        glutPostRedisplay();
    }
}

void displayLines(void)
{
    int i;

    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the line segments
    glColor3f(1.0f, 0.0f, 0.0f); // Reddish lines
    if (N_Points > 1)
    {
        glBegin(GL_LINE_STRIP);
        for (i = 0; i < N_Points; i++)
        {
            glVertex2f(point_array[i][0], point_array[i][1]);
        }
        glVertex2f(point_array[0][0], point_array[0][1]);
        glEnd();
    }

    // Draw the interpolated points second.
    glColor3f(0.0f, 0.0f, 0.0f); // Draw points in black
    glBegin(GL_POINTS);
    for (i = 0; i < N_Points; i++)
    {
        glVertex2f(point_array[i][0], point_array[i][1]);
    }
    glEnd();

    glFlush();
}

void displayLinesfromFile()
{
    ifstream myfile;
    myfile.open("point.txt");
    string myline;
    int flag = 0;
    int k = 0;
    bool check = true;
    if (myfile.is_open())

    {

        while (myfile.good())
        {

            getline(myfile, myline);
            // cout << myline << '\n';

            // getting details from the file and resizing the window according to x and y coordinates
            stringstream ss(myline);
            string word;
            while (ss >> word)
            {
                float p = stof(word);
                if (flag == 0)
                {
                    k++;
                    N_Points++;
                }
                if (check)
                {
                    p = ((float)p) / ((float)(Width_of_Window - 1));
                }
                else
                {
                    p = ((float)p) / ((float)(Height_of_Window - 1));
                    p = 1.0f - p;
                }
                point_array[k][flag] = p;
                flag = !flag;
            }
        }

        displayLines();
    }
    else
    {
        cout << "Couldn't open file\n";
    }
}

void initRendering()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Make big points and wide lines.
    glPointSize(4);
    glLineWidth(4);

    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

// resizing the window

void resizeWindow(int w, int h)
{
    Height_of_Window = (h > 1) ? h : 2;
    Width_of_Window = (w > 1) ? w : 2;
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0f, 1.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Adding keyboard functionalities
// click f to remove first point
// click l to remove last point
// click e to exit from execution

void myKeyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'f':
        fn_for_removing_First_Point();
        glutPostRedisplay();
        break;
    case 'l':
        removeLastPoint();
        glutPostRedisplay();
        break;
    case 'e':
        exit(0);
        break;
    }
}

int main(int argc, char **argv)
{
    int choice;
    cout << "Enter 1 to select points by mouse" << endl;
    cout << "Enter 2 to select points from file" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        cout << "Click only a maximum of 20 points" << endl;
        cout << "Enter 'l' to remove last point" << endl;
        cout << "Enter 'f' to remove first point" << endl;
        cout << "Enter 'e' to exit from window" << endl;

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(100, 100);
        glutCreateWindow(argv[0]);
        initRendering();

        glutDisplayFunc(displayLines);
        break;
    }

    case 2:
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(100, 100);
        glutCreateWindow(argv[0]);
        initRendering();
        glutDisplayFunc(displayLinesfromFile);
        break;
    }

    default:
    {
        cout << "Wrong choice is selected";
        exit(0);
    }
    }

    // Function to resize

    glutReshapeFunc(resizeWindow);
    glutKeyboardFunc(myKeyboardFunc);

    // function which implements the clicking functionality

    glutMouseFunc(Fn_my_Mouse_Function);
    glutMainLoop();

    displayLinesfromFile();

    return 0;
}