#include <windows.h>  
 #include <gl/Gl.h>  
 #include <gl/glut.h>  
 #include <cmath>  
    
 int screenheight = 600;  
 int screenwidth = 800;  
 bool flag = true;  
 int first = 0;  
   
 double angle = 30;   
 //The angle for the rotation (in degrees)  
 typedef struct{  
   float x;  
   float y;  
 }Point2D;  
   
 Point2D p1,p2,p3,p4;  
   
 void DrawPolygonSegment(Point2D pt1, Point2D pt2, Point2D pt3, Point2D pt4){  
     glPointSize(1.0);  
        glBegin(GL_POLYGON);  
             glVertex2i(pt1.x, pt1.y);  
             glVertex2i(pt2.x, pt2.y);  
             glVertex2i(pt3.x, pt3.y);  
             glVertex2i(pt4.x, pt4.y);  
     glEnd();  
   
     glPointSize(6.0);  
     glBegin(GL_POINTS);  
       glVertex2i(pt2.x, pt2.y);  
        glVertex2i(pt3.x, pt3.y);  
        glVertex2i(pt4.x, pt4.y);  
     glEnd();  
     glFlush();  
   
 }  
   
 Point2D rotate(Point2D p, float ang){  
   ang = ang * 3.14 / 180.0;                 //angle in radians  
   Point2D ptemp;  
   
   ptemp.x = p.x * cos(ang) - p.y * sin(ang);  
   ptemp.y = p.x * sin(ang) + p.y * cos(ang);  
   
      return ptemp;  
 }  
   
 void myMouse(int button, int state, int x, int y) {  
     if(state == GLUT_DOWN) {  
        if(button == GLUT_LEFT_BUTTON) {  
            glClear(GL_COLOR_BUFFER_BIT);  
   
                           switch(first)  
                               {  
                               case 0:   
                                     p1.x = x;  
                                     p1.y =screenheight - y;  
                                    first = 1;  
                                    break;  
                               case 1:  
                                    p2.x = x;  
                                    p2.y = screenheight - y;  
                                    first = 2;  
                                    break;       
                               case 2:  
                                    p3.x = x;  
                                    p3.y = screenheight - y;  
                                    first = 3;  
                                    break;  
                               case 3:  
                                    p4.x = x;  
                                    p4.y = screenheight - y;  
                                    DrawPolygonSegment(p1,p2,p3,p4);  
                                    first = 0;  
                                    break;       
                               }  
                       
        }  
        else if (button == GLUT_RIGHT_BUTTON) {  
            Point2D Rotated_p1 = rotate(p1,angle);  
          Point2D Rotated_p2 = rotate(p2,angle);  
            Point2D Rotated_p3 = rotate(p3,angle);  
            Point2D Rotated_p4 = rotate(p4,angle);  
          DrawPolygonSegment(Rotated_p1,Rotated_p2,Rotated_p3,Rotated_p4);  
        }  
     }  
 }  
   
   
 void myDisplay(){  
     glClearColor(1.0f, 1.0f, 1.0f, 0.0f);  
     glClear(GL_COLOR_BUFFER_BIT);  
     glColor3f(0.0f, 0.0f, 0.0f);  
 }  
    
 int main( int argc, char ** argv ) {  
     glutInit( &argc, argv );  
     glutInitWindowPosition( 0, 0 );  
     glutInitWindowSize( 800, 600 );  
     glutCreateWindow( "Rotate Polygon" );  
        glMatrixMode( GL_PROJECTION );  
     glLoadIdentity();  
     gluOrtho2D( 0, 800, 0, 600 );  
     glViewport(0, 0, 800, 600);  
   
     glutDisplayFunc( myDisplay );  
     glutMouseFunc( myMouse );  
   
     glutMainLoop();  
     return( 0 );  
 }  