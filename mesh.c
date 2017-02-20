#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#define dx 10
#define dy 10
GLfloat R=0.0,G=0.0,B=0.0,bg=1,br=1,bb=1;
void display()
{
GLint i,j;

glClear(GL_COLOR_BUFFER_BIT);
glColor3f(R,G,B);
for(i=10;i<300;i+=dx)
for(j=10;j<300;j+=dy)
{
glBegin(GL_LINE_LOOP);
glVertex2i(i,j);
glVertex2i(i+dx,j);
glVertex2i(i+dx,j+dy);
glVertex2i(i,j+dy);
glEnd();
}
glFlush();
}
int main(int argc,char **argv)
{
printf("enter R,G,B color values");
scanf("%f%f%f",&R,&G,&B);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(50,20);
glutInitWindowSize(500,500);
glutCreateWindow("rectangular mesh");
glClearColor(br,bg,bb,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,500.0,0.0,500.0);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
