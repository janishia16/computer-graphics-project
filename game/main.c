#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int eggs_caught=0,missed_eggs=0,level_count=1,points=0;
int egg_x,egg_y; //egg coordinates
int basket_x,basket_y;//basket coordinates
char text[20];
int number,x;
int a=900,b=900; // for default size of the screen
int s=0,c=0,d=0;// for menu option
int eggs_dropped=0;
int speed_1=1,speed_2=1.5,speed_3=2,speed_4=2.5;
int w=48,h=48;
int lc=0,me=0,ed=0,ec=0;
void myinit();
void start_screen();
void egg();
void basket(int,int);
void print_score();
void egg_start();
void score();
void display(void);
void basket_set(int,int);
void myReshape(int,int);
void keys(unsigned char,int,int);
void menu(int);

void timerc(int e)
{
	x=x+3;
	if(x>=400)
	{	
		x=0;
		glutPostRedisplay();
		glutTimerFunc(300,timerc,0);
	}
	else
	{
		glutPostRedisplay();
		glutTimerFunc(100,timerc,0);
	}
}

void timer1(int e)
{
	
	egg_y=egg_y-1;
	glutPostRedisplay();
	glutTimerFunc(20000,timer1,0);
}

void timer2(int e)
{
	egg_y=egg_y-1;
	glutPostRedisplay();
	glutTimerFunc(19900,timer2,0);
}
void timer3(int e)
{
	egg_y=egg_y-1;
	glutPostRedisplay();
	glutTimerFunc(19850,timer3,0);
}
void timer4(int e)
{
	egg_y=egg_y-1;
	glutPostRedisplay();
	glutTimerFunc(19800,timer4,0);
}

void myinit()
{
	glViewport(0,0,a,b);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,900.0,0,900.0,-900.0,900.0);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void start_screen()
{
	int j;
	char* str1= "MANGALORE INSTITUTE OF TECHNOLOGY & ENGINEERING";
	char* str2 = "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING";
	char* str3 = "COMPUTER GRAPHICS AND VISUALIZATION";
	char* str4 = "MINI PROJECT";
	char* str10= "ON";
	char* str5 = "HATCH OR CATCH";
	char* str6 = "TEAM MEMBERS:";
	char* str7 = "JANISHIA NORONHA: 4MT19CS060";
	char* str8 = "CASEY NAZARETH: 4MT19CS039";
	char* str9 = "PRESS S TO START";
	
	glColor3f(1,0,0);
	glRasterPos2i(120,600);
	for(j=0;j<strlen(str1);j++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str1[j]);
	
	glColor3f(0,0,0);
	glRasterPos2i(120,530);
	for(j=0;j<strlen(str2);j++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str2[j]);
	
	glColor3f(0, 0, 1);
	glRasterPos2i(200,500);
	for(j=0;j<strlen(str3);j++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str3[j]);
		
		
	glColor3f(0.3, 0, 0.3);	
	glRasterPos3f(350, 440,0);
	for (j = 0; j<strlen(str4); j++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str4[j]);
		
	glColor3f(0.3, 0, 0.3);	
	glRasterPos3f(420, 410,0);
	for (j = 0; j<strlen(str10); j++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str10[j]);
	
	glColor3f(1, 0, 0);
	glRasterPos3f(330, 380,0);
	for (j = 0; j<strlen(str5); j++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str5[j]);
		
		
	glRasterPos3f(50, 300,0);
	glColor3f(0.1, 0.2, 0.5);
	for (j = 0; j<strlen(str6); j++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str6[j]);
		
	glRasterPos3f(50, 250,0);
	glColor3f(0.1, 0.2, 0.5);
	for (j = 0; j<strlen(str8); j++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str8[j]);

	glRasterPos3f(50, 200,0);
	glColor3f(0, 1, 0);
	for (j = 0; j<strlen(str7); j++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str7[j]);

	glRasterPos3f(300, 100,0);
	glColor3f(0,0,0);
	for (j = 0; j<strlen(str9); j++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str9[j]);
		
}

void ground()
{
	
	glBegin(GL_POLYGON);
	glVertex2i(0,0);
	glVertex2i(900,0);
	glVertex2i(900,360);
	glVertex2i(0,360);
	glEnd();
	glFlush();

}

void sky()
{
	
	glBegin(GL_POLYGON);
	glVertex2i(0,360);
	glVertex2i(900,360);
	glVertex2i(900,900);
	glVertex2i(0,900);
	glEnd();
	glFlush();
}

void sun(int i,int j)
{
	glPushMatrix();
	glTranslatef(490.0+i,420.0+j,0.0);
	glutSolidSphere(70.0,50,40);
	glPopMatrix();
	glEnd();
	glFlush();
}

void mountain()	
{
	glBegin(GL_POLYGON);
	glVertex2i(0,360);
	glVertex2i(250,550);
	glVertex2i(500,360);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2i(500,360);
	glVertex2i(700,550);
	glVertex2i(900,360);
	glEnd();
	glFlush();
}

void line()	
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(0,395);
	glVertex2i(900,395);
	glEnd();
	glFlush();	

}
void cloud()
{

	//cloud1
	
	glColor3f(1,1,1);
	glPushMatrix();
	glTranslatef(515,650,0);
	glutSolidSphere(30,100,100);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(550,650,0);
	glutSolidSphere(35,100,100);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(575,650,0);
	glutSolidSphere(30,100,100);
	glPopMatrix();
	glFlush();

	//cloud-2
	glPushMatrix();
	glTranslatef(215,600,0);
	glutSolidSphere(30,100,100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(250,600,0);
	glutSolidSphere(35,100,100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(280,600,0);
	glutSolidSphere(30,100,100);
	glPopMatrix();
	glFlush();
}
void bush(int i,int j)
{
	
	glRecti(50+i,370+j,160+i,320+j);
	
	glPushMatrix();
	glTranslatef(45+i,340+j,0);
	glutSolidSphere(20,100,100);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(60+i,372+j,0);
	glutSolidSphere(20,100,100);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(105+i,380+j,0);
	glutSolidSphere(30,100,100);
	glPopMatrix();
	

	glPushMatrix();
	glTranslatef(150+i,372+j,0);
	glutSolidSphere(20,100,100);
	glPopMatrix();	
	
	glPushMatrix();
	glTranslatef(160+i,340+j,0);
	glutSolidSphere(20,100,100);
	glPopMatrix();
	
	glFlush();
	
}
void egg()
{
	float x,y,z;
	int t;
	glColor3f(1.0,10,1.0);
	glBegin(GL_POLYGON);
	for(t=0;t<=360;t+=1)
	{
		x = egg_x+8*(cos(t));
		y = egg_y+16*(sin(t));
		z = 0;
		glVertex3f(x,y,z);
	}
	glEnd();
}

void basket(int i,int j)
{
	j=10; //height of basket
	a=900;
	if(i>=a-60)
		i=a-60;
	glColor3f(0.6,0.2,0.1);
	
	glBegin(GL_POLYGON);
	glVertex2f(0.0+i,55.0+j);
	glVertex2f(20.0+i,10.0+j);
	glVertex2f(60.0+i,10.0+j);
	glVertex2f(80.0+i,55.0+j);
	glEnd();
}

void birds(int i,int j)
{
	int t,x,y,z;
	
	//bird-tri(LEFT)
	glColor3f(1.0,0.949,0.1921);
	glBegin(GL_TRIANGLES);
	glVertex2i(75+i,20+j);
	glVertex2i(75+i,100+j);
	glVertex2i(35+i,60+j);
	glEnd();

	//bird-tri(RIGHT)
	glColor3f(1.0,0.949,0.1921);
	glBegin(GL_TRIANGLES);
	glVertex2i(85+i,20+j);
	glVertex2i(85+i,100+j);
	glVertex2i(125+i,60+j);
	glEnd();
		
	//head
	glColor3f(1.0,0.99607,0.5686);
	glPushMatrix();
	glTranslatef(80+i,115+j,0);
	glutSolidSphere(20,50,50);
	glPopMatrix();
	
	//point
	glColor3f(0.0,0.0,0.0);
	glPointSize(7);
	
	glBegin(GL_POINTS);
	glVertex2f(85+i,120+j);
	glEnd();
	glFlush();
	
	//wings
	glColor3f(1.0,0.99607,0.5686);
	glBegin(GL_POLYGON);
	glVertex2i(75+i,25+j);
	glVertex2i(85+i,25+j);
	glVertex2i(105+i,0+j-10);
	glVertex2i(80+i,10+j-70);
	glVertex2i(55+i,0+j-10);
	glEnd();
	
	
	//LINE
	
	glColor3f(0.4,0.1,0);
	glBegin(GL_LINES);
	glVertex2i(80+i,25+j);
	glVertex2i(65+i,10+j-30);
	glEnd();
	
	glColor3f(0.4,0.1,0);
	glBegin(GL_LINES);
	glVertex2i(80+i,25+j);
	glVertex2i(95+i,10+j-30);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2i(80+i,25+j);
	glVertex2i(80+i,10+j-60);
	glEnd();
	
	//body
	glColor3f(1.0,0.866,0.152);
	glBegin(GL_POLYGON);
	for(t=0;t<=360;t+=1)
	{
		x = 80+i+20*(cos(t));
		y = 60+j+40*(sin(t));
		z = 0;
		glVertex3f(x,y,z);
	}
	glEnd();
	
	//BEAK
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_TRIANGLES);
	glVertex2i(98+i,126+j);
	glVertex2i(120+i,120+j);
	glVertex2i(100+i,110+j);
	glEnd();
	
	//top lines
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(80+i,137+j);
	glVertex2f(70+i,152+j);
	glVertex2f(80+i,145+j);
	glVertex2f(90+i,152+j);
	glEnd();
	glFlush();

}
void star(int i,int j)
{
	glPointSize(4);
	glBegin(GL_POINTS);
	glVertex2f(0+i,680+j);
	glVertex2f(100+i,580+j);
	glVertex2f(200+i,600+j);
	glVertex2f(300+i,530+j);
	glVertex2f(400+i,650+j);
	glVertex2f(500+i,570+j);
	glVertex2f(600+i,610+j);
	glVertex2f(700+i,530+j);
	glVertex2f(550+i,640+j);
	glVertex2f(450+i,600+j);
	glEnd();
	glFlush();
}
void next()
{
	//glClearColor()

	glColor3f(1,1,1);
	glRecti(100,140,800,450);
	
	int k,i,num; 
	int lc=level_count; 
	int ed=eggs_dropped; 
	int ec=eggs_caught; 
	int me= missed_eggs; 
	
	char x[30]="Level reached:"; 
	char y[30]="No. of eggs dropped="; 
	char z[30]="No. of eggs caught ="; 
	char w[30]="No. of eggs missed ="; 
	char cc[30]="QUIT BY THE PLAYER"; 
	char dd[30]="GAME OVER"; 
	char sc[30]=" SCORE:";
	
	if(c==1)
	{
		glColor3f(0,0,1); 
		glRasterPos2i(200,400); 
		for(k=0;k<20;k++) 
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,cc[k]); 
	}
	
	if(d==1)
	{
		glColor3f(0,0,1); 
		glRasterPos2i(200,400); 
		for(k=0;k<20;k++) 
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,dd[k]); 
	}
	glColor3f(0,0,1); 
	glRasterPos2i(200,350); 
	for(k=0;k<20;k++) 
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,x[k]); 
  
  	glColor3f(0,0,1);
	glRasterPos2i(200,300); 
	for(k=0;k<20;k++) 
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,y[k]); 
	
	glColor3f(0,0,1);
	glRasterPos2i(200,250); 
	for(k=0;k<20;k++) 
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,z[k]); 
	
	glColor3f(0,0,1);
	glRasterPos2i(200,200); 
	for(k=0;k<20;k++) 
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,w[k]); 
	
	glColor3f(0,0,0);
	glRasterPos2i(250,150); 
	for(k=0;k<20;k++) 
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,sc[k]); 
	
	
	//level
	glColor3f(1,0,0);
	sprintf(text, "%d",lc);
	glRasterPos2i(500,350);	
	for(i=0;i<10;i++)	
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text[i]);
		
	//dropped
	sprintf(text, "%d",ed);
	glRasterPos2i(500,300);	
	for(i=0;i<10;i++)	
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text[i]);
	
	//caught
	sprintf(text, "%d",ec);
	glRasterPos2i(500,250);	
	for(i=0;i<10;i++)	
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text[i]);
		
	//missed
	sprintf(text, "%d",me);
	glRasterPos2i(500,200);	
	for(i=0;i<10;i++)	
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text[i]);
		
	//score
	glColor3f(0,0,0);
	number=eggs_caught*2;
	sprintf(text, "%d",number);
	glRasterPos2i(500,150);	
	for(i=0;i<10;i++)	
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text[i]);	
		
	glEnd();
	glutPostRedisplay();
	glutSwapBuffers();
	glFlush();
	
	
	
}
void print_score()
{
	next();
	/*printf("\nLevel reached: %d\n\n",level_count);
	printf("\nNo. of eggs dropped= %d \n",eggs_dropped);
	printf("\nNo. of eggs caught = %d\n",eggs_caught);
	printf("\nNo. of eggs missed = %d\n",missed_eggs);*/
	getchar();
	exit(0);

}

void egg_start()
{
	egg_y=375;
	if(missed_eggs>=10)
	{
		d=1;
		print_score();
	}
	eggs_dropped++;
	
	switch(rand()%9)
	{
		case 0:egg_x=100; break;
		case 1:egg_x=415; break;
		case 2:egg_x=786; break;
		case 5:egg_x=100; break;
		case 3:egg_x=415; break;
		case 4:egg_x=786; break;
		case 7:egg_x=100; break;
		case 6:egg_x=415; break;
		case 8:egg_x=786; break;
	}
}


void score()
{
	if(egg_y<=50 && (egg_x>=basket_x&&egg_x<=basket_x+60))
	{
		printf("\a");
		eggs_caught++;
		egg_y=-10;
	}
	missed_eggs=eggs_dropped-eggs_caught;
}


void convert(int number)
{
	int i;
	number=eggs_caught*2;
	sprintf(text, "%d", number);
	glRasterPos2i(750,640);	
	for(i=0;i<10;i++)	
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13,text[i]);
}
void screen()
{
	int i;
	char level1[12]="LEVEL 1";
	char level2[12]="LEVEL 2";
	char level3[12]="LEVEL 3";
	char level4[12]="LEVEL 4";
	char sscore[7]="SCORE: ";
	GLint point;
	number=eggs_caught;
	
		glColor3f(0,0,1);
		if(level_count==1)
		{
			//sky
			glColor3f(0.678,0.941,0.984);
			sky();
	
			//cloud
			glPushMatrix();
			glTranslatef(x,0,0);
			cloud();
			glPopMatrix();
			
			//sun
			glColor3f(1.0,0.7,0.0);
			sun(0,0);	
	
			//ground
			glColor3f(0.172,0.878,0.337);
			ground();
	
			//mountain
			glColor3f(0.7607,0.6078,0.4196);
			mountain();
	
			//bush
			glColor3f(0,0.6,0);
			bush(-50,30);
			bush(70,30);
			bush(190,30);
			bush(240,30);
	
			bush(550,30);
			bush(590,30);
			bush(710,30);
			bush(770,30);
	
			//line
			glColor3f(0.0,0.0,0.0);
			line();

			birds(20,375);
			birds(330,375);
			birds(700,375);
			
			//number=eggs_caught*2;
			
			glColor3f(0,0,0);
			glRasterPos2i(700,660);
			for(i=0;i<12;i++)
				glutBitmapCharacter(GLUT_BITMAP_8_BY_13,level1[i]);
				
			glRasterPos2i(700,640);
			for(i=0;i<7;i++)
				glutBitmapCharacter(GLUT_BITMAP_8_BY_13,sscore[i]);
			
			convert(number);
			
			
		}
		else if(level_count==2)
		{
			
			//sky
			glColor3f(0.9,0.7,0);
			sky();
	
			//cloud
			glPushMatrix();
			glTranslatef(x+1.0,0,0);
			cloud();
			glPopMatrix();
	
			//sun
			glColor3f(1.0,1.0,0.1);
			sun(10,150);	
	
			//ground
			glColor3f(0.172,0.878,0.337);
			ground();
	
			//mountain
			glColor3f(0.7607,0.6078,0.4196);
			mountain();
	
			//bush
			glColor3f(0,0.6,0);
			bush(-50,30);
			bush(70,30);
			bush(190,30);
			bush(240,30);
	
			bush(550,30);
			bush(590,30);
			bush(710,30);
			bush(770,30);
	
			//line
			glColor3f(0.0,0.0,0.0);
			line();

			birds(20,375);
			birds(330,375);
			birds(700,375);
			
			glColor3f(0,0,0);
			glRasterPos2i(700,660);
			for(i=0;i<12;i++)
				glutBitmapCharacter(GLUT_BITMAP_8_BY_13,level2[i]);
				
			glRasterPos2i(700,640);
			for(i=0;i<7;i++)
				glutBitmapCharacter(GLUT_BITMAP_8_BY_13,sscore[i]);
				
			convert(number);
		}
		else if(level_count==3)
		{
			//sky
			glColor3f(1,0.8,0.3);
			sky();
	
			//cloud
			glPushMatrix();
			glTranslatef(x,0,0);
			cloud();
			glPopMatrix();
	
			//sun
			glColor3f(1.0,0.6,0.0);
			sun(-300,100);	
	
			//ground
			glColor3f(0.172,0.878,0.337);
			ground();
	
			//mountain
			glColor3f(0.5,0.3,0.1);
			mountain();
	
			//bush
			glColor3f(0.5,0.9,0.3);
			bush(-50,30);
			bush(70,30);
			bush(190,30);
			bush(240,30);
	
			bush(550,30);
			bush(590,30);
			bush(710,30);
			bush(770,30);
	
			//line
			glColor3f(0.0,0.0,0.0);
			line();

			birds(20,375);
			birds(330,375);
			birds(700,375);
			
			glColor3f(0,0,0);
			glRasterPos2i(700,660);
			for(i=0;i<12;i++)
				glutBitmapCharacter(GLUT_BITMAP_8_BY_13,level3[i]);
				
			glRasterPos2i(700,640);
			for(i=0;i<7;i++)
				glutBitmapCharacter(GLUT_BITMAP_8_BY_13,sscore[i]);
				
			convert(number);
		}
		if(level_count==4)
		{
			//sky
			glColor3f(0.1,0,0.6);
			sky();
	
			//stars
			glColor3f(1,1,1);
			star(0,0);
			star(-40,-30);
			star(-40,-70);
			star(-40,-150);
			star(-150,40);
			star(-250,30);
			star(-350,30);
			star(-370,-20);
			star(370,20);
			star(370,-20);
			star(150,90);
			//cloud
			glPushMatrix();
			glTranslatef(x,0,0);
			cloud();
			glPopMatrix();
	
			//sun
			glColor3f(1.0,1.0,1.0);
			sun(-330,170);	
	
			//ground
			glColor3f(0,0.6,0.4);
			ground();
	
			//mountain
			glColor3f(0.7607,0.6078,0.4196);
			mountain();
	
			//bush
			glColor3f(0,0.9,0.7);
			bush(-50,30);
			bush(70,30);
			bush(190,30);
			bush(240,30);
	
			bush(550,30);
			bush(590,30);
			bush(710,30);
			bush(770,30);
	
			//line
			glColor3f(0.0,0.0,0.0);
			line();

			birds(20,375);
			birds(330,375);
			birds(700,375);
			
			glColor3f(1,0,0);
			glRasterPos2i(700,660);
			for(i=0;i<12;i++)
				glutBitmapCharacter(GLUT_BITMAP_8_BY_13,level4[i]);
			
			glRasterPos2i(700,640);
			for(i=0;i<7;i++)
				glutBitmapCharacter(GLUT_BITMAP_8_BY_13,sscore[i]);
				
			convert(number);
		}

		if(egg_y<=10)
			egg_start(); //becoz j=10 
		egg();
		basket(basket_x,basket_y);

		if(eggs_caught>=0)
		{
			//egg_y-=speed_1;
			timer1(0);
			level_count=1;
		}
		if(eggs_caught>=10)
		{
			//egg_y-=speed_2;
			timer2(0);
			level_count=2;
		}

		if(eggs_caught>=20)
		{
			//egg_y-=speed_3;
			timer3(0);
			level_count=3;
		}

		if(eggs_caught>=30)
		{
			//egg_y-=speed_4;
			timer4(0);	
			level_count=4;
		}
		score();
		
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	if(s>=1)
		screen();
	else
	{	
		start_screen();
	}
	
	//glFlush();
	glutSwapBuffers();
}

void basket_set(int a,int b)
{
	basket_x=a;
	basket_y=b;
	glutPostRedisplay();
}

void myReshape(int w,int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,(GLdouble)w,0.0,(GLdouble)h,0,(GLdouble)b);	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glViewport(0,0,w,h);
	a=w;
	b=h;
}

void keys(unsigned char key,int x,int y)
{
	if(key=='q'||key=='Q')
	{
		c=1;
		//printf("\n\n\n\t\tQUIT BY PLAYER\n\n");
		print_score();
	}
	
	if(key=='s'||key=='S') 
	{
		s=+1;
	}
}

void menu(int id)
{
	switch(id)
	{
		case 1: s+=1;
		break;
		
		case 2:
		print_score();
		break;
		
		case 3: c=1;
		print_score();
		break;
		
		default:exit(0);
	}
	glutPostRedisplay();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(900,900);
	glutInitWindowPosition (0, 0);
	glutCreateWindow("HATCH OR CATCH");
	glutDisplayFunc(display);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	myinit();
	glutCreateMenu(menu);
	glutAddMenuEntry("Start game",1);
	glutAddMenuEntry("score",2);
	glutAddMenuEntry("Quit",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutKeyboardFunc(keys);
	glutPassiveMotionFunc(basket_set);
	glutIdleFunc(display);
	glutReshapeFunc(myReshape);
	timerc(0);
	glutMainLoop();
}

