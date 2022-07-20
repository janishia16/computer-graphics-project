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
 
	//glClearColor(1.0,0.0,0.0,0.0);
	
	/*glBegin(GL_LINES);
	glVertex2i(100,100);
	glVertex2i(200,200);
	glEnd();
	
	*/int k; 
	int lc=level_count; 
	int ed=eggs_dropped; 
	int ec=eggs_caught; 
	int me= missed_eggs; 
	
	char x[30]="Level reached:"; 
	char y[30]="No. of eggs dropped="; 
	char z[30]="No. of eggs caught ="; 
	char w[30]="No. of eggs missed ="; 
	
	glColor3f(1,1,0); 
	glRasterPos2i(100,800); 
	for(k=0;k<20;k++) 
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,x[k]); 
	
	glColor3f(1,0,0);	
	glRasterPos2i(200,800); 
	for(k=0;k<20;k++) 		
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,lc); 
  
  	glColor3f(1,1,0);
	glRasterPos2i(100,750); 
	for(k=0;k<20;k++) 
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,y[k]); 
	
	glColor3f(1,1,0);
	glRasterPos2i(100,700); 
	for(k=0;k<20;k++) 
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,z[k]); 
	
	glColor3f(1,1,0);
	glRasterPos2i(100,650); 
	for(k=0;k<20;k++) 
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,w[k]); 
	
	glFlush();
	
} 

int main(int argc,char **argv)
{
	printf("******************************************************************");
	printf("\n\t\t\t\t EGG GAME\n\n");
	printf("******************************************************************");
	printf("\n\tHow to Play..?\n\n <1>The objective of the game is to catch the eggs in the basket.\n\t To move Basket use mouse.\n");
	printf("\n <2> To Start, press key 's' or 'S' or \n\tClick Right mouse button then click 'Start Game'.\n");
	printf("\n <3> To Quit manually, press key 'q' or 'Q' or\n\t Click Right mouse button then click 'Quit'.\n");
	printf("\n\n RULES : If the player misses 10 eggs,then 'Game Over'.\n");
	printf("\nFor each level, speed is Increased\n\n");
	printf("\n\nBEST OF LUCK\n");
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE||GLUT_RGB);
	glutInitWindowSize(a,b);
	glutCreateWindow("EGG GAME");
	glutInitWindowPosition (100, 100);
	
	myinit();
	glutDisplayFunc(print_score);
	glutMainLoop();
}
