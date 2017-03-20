#include<GL/glut.h>
GLfloat vertices[][3]={{-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1},{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1}};
GLfloat color[][3]={{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
static GLfloat theta[]={0,0,0};
static GLint axis=2;
void polygon(int a,int b,int c,int d)
{
glBegin(GL_POLYGON);
glColor3fv(color[a]);
glVertex3fv(vertices[a]);
glColor3fv(color[b]);
glVertex3fv(vertices[b]);
glColor3fv(color[c]);
glVertex3fv(vertices[c]);
glColor3fv(color[d]);
glVertex3fv(vertices[d]);
glEnd();
}
void Colorcube()
{
polygon(0,1,2,3);
polygon(2,6,7,3);
polygon(4,5,6,7);
polygon(0,1,5,4);
polygon(1,2,6,5);
polygon(0,4,7,3);
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glRotatef(theta[0],1,0,0);
glRotatef(theta[1],0,1,0);
glRotatef(theta[2],0,0,1);
Colorcube();
glFlush();
glutSwapBuffers();
}
void spincube()
{
theta[axis]+=2.0;
if(theta[axis]>360)
theta[axis]-=360;
glutPostRedisplay();
}
void mymouse(int bln,int state,int a,int y)
{
if(bln=GLUT_LEFT_BUTTON && state==GLUT_DOWN)
axis=0;
if(bln=GLUT_LEFT_BUTTON && state==GLUT_DOWN)
axis=1;
if(bln=GLUT_LEFT_BUTTON && state==GLUT_DOWN)
axis=2;
}
void myreshape(int w,int h)
{
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-2,2,-2,2,-2,2);
glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char**argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutCreateWindow("cube");
glutReshapeFunc(myreshape);
glutDisplayFunc(display);
glutIdleFunc(spincube);
glutMouseFunc(mymouse);
glEnable(GL_DEPTH_TEST);
glClearColor(1,1,1,1);
glutMainLoop();
}
