#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int eggs_caught=0,missed_eggs=0,level_count=1,points=0,eggs_dropped; 
int lc,ed,ec,mc;
int a=900,b=900;

void myinit()
{
	glViewport(0,0,a,b);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,(GLdouble)a,0,(GLdouble)b,0,(GLdouble)b);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void print_score() 
{ 
 
	glClearColor(1.0,1.0,1.0,0.0);

	glColor3f(1,1,1);
	glRecti(100,300,800,600);
	
	int k; 
	int lc=level_count; 
	int ed=eggs_dropped; 
	int ec=eggs_caught; 
	int me= missed_eggs; 
	
	char x[30]="Level reached:"; 
	char y[30]="No. of eggs dropped="; 
	char z[30]="No. of eggs caught ="; 
	char w[30]="No. of eggs missed ="; 
	
	glColor3f(0,0,1); 
	glRasterPos2i(200,550); 
	for(k=0;k<20;k++) 
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,x[k]); 
  
  	glColor3f(0,0,1);
	glRasterPos2i(200,500); 
	for(k=0;k<20;k++) 
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,y[k]); 
	
	glColor3f(0,0,1);
	glRasterPos2i(200,450); 
	for(k=0;k<20;k++) 
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,z[k]); 
	
	glColor3f(0,0,1);
	glRasterPos2i(200,400); 
	for(k=0;k<20;k++) 
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,w[k]); 
	
	glutSwapBuffers();
	glFlush();
	
	
} 

int main(int argc,char **argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(a,b);
	glutCreateWindow("EGG GAME");
	glutInitWindowPosition (100, 100);
	
	myinit();
	glutDisplayFunc(print_score);
	glutMainLoop();
}

