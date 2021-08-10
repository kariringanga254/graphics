#include<GL/glut.h>

void display();
void reshape(int,int);
void timer(int);
void init()
{
    glClearColor(0,0,0,1.0);
    glEnable(GL_DEPTH_TEST);
}



int main(int argc,char**argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE|GLUT_DEPTH);

    glutInitWindowPosition(200,100);
    glutInitWindowSize(500,500);



    glutCreateWindow("window 1");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    init();

    glutMainLoop();

}
float angle=0.0;


void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0,0.0,-12.0);
    glRotatef(angle,1.0,0.0,0.0);
    glRotatef(angle,0.0,1.0,0.0);
    glRotatef(angle,0.0,0.0,1.0);
//draw
    glBegin(GL_QUADS);


    //front
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-4.0,2.0,2.0);
    glVertex3f(-4.0,-2.0,2.0);
    glVertex3f(4.0,-2.0,2.0);
    glVertex3f(4.0,2.0,2.0);

    /*door
    glColor3f (0.8,0.7,1.0);
    glVertex3f (-4.0,2.0,2.0);
    glVertex3f (-2.0,1.0,1.0);
    glVertex3f (1.0,2.0,2.0);
    glVertex3f (1.0,0.0,2.0);*/
    //back
    glColor3f(1.0,0.0,1.0);
    glVertex3f(4.0,2.0,-2.0);
    glVertex3f(4.0,-2.0,-2.0);
    glVertex3f(-4.0,-2.0,-2.0);
    glVertex3f(-4.0,2.0,-2.0);


    //right
    glColor3f(0.0,0.0,1.0);
    glVertex3f(4.0,2.0,2.0);
    glVertex3f(4.0,-2.0,2.0);
    glVertex3f(4.0,-2.0,-2.0);
    glVertex3f(4.0,2.0,-2.0);
   //left
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-4.0,2.0,-2.0);
    glVertex3f(-4.0,-2.0,-2.0);
    glVertex3f(-4.0,-2.0,2.0);
    glVertex3f(-4.0,2.0,2.0);
    //top1
    glColor3f(0.0,1.0,1.0);
    glVertex3f(4.0,4.0,0.0);
    glVertex3f(4.0,2.0,-2.0);
    glVertex3f(-4.0,2.0,-2.0);
    glVertex3f(-4.0,4.0,0.0);

    //top2
    glColor3f(0.5,0.7,1.0);
    glVertex3f(-4.0,4.0,0.0);
    glVertex3f(-4.0,2.0,2.0);
    glVertex3f(4.0,2.0,2.0);
    glVertex3f(4.0,4.0,0.0);

    //bottom
    glColor3f(0.0,1.0,0.0);
    glVertex3f(-4.0,-2.0,-2.0);
    glVertex3f(-4.0,-2.0,2.0);
    glVertex3f(4.0,-2.0,2.0);
    glVertex3f(4.0,-2.0,-2.0);

    //triangle1
    glColor3f(1.0,1.0,1.0);
    glVertex3f(4.0,4.0,0.0);
    glVertex3f(4.0,2.0,2.0);
    glVertex3f(4.0,2.0,-2.0);
    glVertex3f(4.0,2.0,-2.0);

    //triangle2
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-4.0,4.0,0.0);
    glVertex3f(-4.0,2.0,2.0);
    glVertex3f(-4.0,2.0,-2.0);
    glVertex3f(-4.0,4.0,0.0);

    glEnd();

    glutSwapBuffers();
}
void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1,2.0,30.0);
    glMatrixMode(GL_MODELVIEW);

}
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);

    angle+=2*0.3;
    if(angle>360.0)
        angle=angle-360.0;

   /*switch(state)
    {
         case 1:
        if(x_position<-5)
            x_position+=0.30;
        else
            state=-1;
        break;
    case -1:
        if(x_position>-15)
            x_position-=0.30;
        else
            state=1;
        break;
    }*/
}
