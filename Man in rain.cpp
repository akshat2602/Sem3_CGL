#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;
float x = 92;
float y = 400;
int flag = 0;


void Init(void) {
	glClearColor(0, 0, 0, 1); // black color diya
}


void Reshape(int w, int h) {
	// viewport ready aur matrix mode tayaar kiya
	glViewport(0, 0, w, h); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// ek alag matrix aur use  kiya yaha pe
	gluOrtho2D(0, 1000, 500, 0);
	glMatrixMode(GL_MODELVIEW);
}


void DrawMan() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	float angle; // umbrella ke liye variable
	glBegin(GL_POLYGON); // umbrella draw karne ke liye 
	for (int i = 180; i < 360; i++){
		angle = i * 3.142 / 180; // angle ko radian me kiya
		glColor3f(1, 1, 0); // white color
		glVertex2f((x - 2) + 29 * cos(angle), (y - 27) + 29 * sin(angle)); // unbrella draw karne ke liye hai ye
	}
	glEnd();

	float angle2; // khopdi draw karne ke liye
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++){
		angle2 = i * 3.142 / 180; // angle to radian
		glColor3f(0, 1, 1);
		glVertex2f(x + 11 * cos(angle2), (y - 11) + 11 * sin(angle2)); // khopdi ke liye
	}
	glEnd();

	//stick
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(x - 10, y - 26);
	glVertex2f(x - 10, y - 10);
	glEnd();

	//hand right
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(x + 1, y + 9);
	glVertex2f(x + 15, y + 18);
	glEnd();

	//leg left 
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(x - 1, y + 33);
	glVertex2f(x - 13, y + 43);
	glEnd();

	//leg right
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(x + 1, y + 33);
	glVertex2f(x + 15, y + 43);
	glEnd();

	/*
	//hand left
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(x - 5, y - 10);
	glVertex2f(x - 23, y + 5);
	glEnd();

	//hand left ka palm jisse umbrella pakdi hai
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(x - 23, y + 5);
	glVertex2f(x - 1, y + 9);
	glEnd();
	*/

	// left hand
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex2f(x, y + 9);
	glVertex2f(x - 10, y - 10);
	glEnd();

	//body
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(x, y);
	glVertex2f(x, y + 33);
	glEnd();

	//land
	glBegin(GL_POLYGON);
	glColor3f(.4, .26, .13);
	glVertex2f(0, 443);
	glVertex2f(999, 443);
	glVertex2f(999, 499);
	glVertex2f(0, 499);	
	glEnd();

	// baarish ke liye hai ye
	glBegin(GL_LINES);
	for (int t = 0; t < 10; t++) {
		int x1 = rand() % 999;
		int y1 = rand() % 499;
		glColor3f(1, 1, 1);
		glVertex2f(x1, y1);
		glVertex2f(x1, y1 + 10);
	}
	glEnd();

	glutSwapBuffers();

}


void OnIdle() {
	glutPostRedisplay();
	if (x < 950) // haar second aage chalta rahega
		x += 0.009;
}


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowPosition(0, 0);// window size aur position hai yaha pe
	glutInitWindowSize(1000, 500);

	glutCreateWindow("Rain Man");
	Init();
	glutDisplayFunc(DrawMan); // inbuilt chhezo me pass kiya hamare likhe functions aur run
	glutReshapeFunc(Reshape);
	glutIdleFunc(OnIdle);
	glutMainLoop();
	return 0;
}