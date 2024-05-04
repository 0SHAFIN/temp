#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

struct building1
{
    float x, y;
    float h, w;
    float floor, flat;
    float br=0.0, bg=0.0, bb=0.0, wr=0.0, wg=0.0, wb=0.0;
};
vector<building1> build1;
float bgX=-1.0;

void box2(float x, float y,float z, float width,float height,float r,float g,float b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+width, y);
    glVertex2f(x+width, y+height);
    glVertex2f(x,  y+height);
    glEnd();
}


void planeBox(float x,float y,float z, float r,float g,float b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+.01/z, y);
    glVertex2f(x+.01/z, y+.01/z);
    glVertex2f(x,  y+.01/z);
    glEnd();
}
void box(float x, float y, float width,float height,float r,float g,float b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+width, y);
    glVertex2f(x+width, y+height);
    glVertex2f(x,  y+height);
    glEnd();
}

void drawBuilding(building1 b)
{
    glColor3f(b.br,b.bg,b.bb);
    glBegin(GL_POLYGON);
    glVertex2f(b.x, b.y);
    glVertex2f(b.x+b.w, b.y);
    glVertex2f(b.x+b.w, b.y+b.h);
    glVertex2f(b.x,  b.y+b.h);
    glEnd();
    float fH=.06,x=b.x+0.03;
    float fW=.05,y=b.y+0.04;





    for(int i=1; i<b.floor; i++)
    {

            int temp=b.flat;
            if(temp%2==0)
            {
                glColor3f(b.wr,b.wg,b.wb);
                glBegin(GL_POLYGON);
                glVertex2f(x, y);
                glVertex2f(x+fW, y);
                glVertex2f(x+fW, y+fH);
                glVertex2f(x, y+fH);
                glEnd();
                x+=fW+.02;
                glColor3f(b.wr,b.wg,b.wb);
                glBegin(GL_POLYGON);
                glVertex2f(x, y);
                glVertex2f(x+fW, y);
                glVertex2f(x+fW, y+fH);
                glVertex2f(x, y+fH);
                glEnd();
                x=b.x+.03;

            }
            else
            {
                for(int i=0; i<b.flat-1; i++)
                {
                    if(i==1)
                    {
                        glColor3f(b.wr,b.wg,b.wb);
                        glBegin(GL_POLYGON);
                        glVertex2f(x, y);
                        glVertex2f(x+fW+.04, y);
                        glVertex2f(x+fW+.04, y+fH);
                        glVertex2f(x, y+fH);
                        glEnd();
                        x+=fW+.04+.02;
                    }
                    glColor3f(b.wr,b.wg,b.wb);
                    glBegin(GL_POLYGON);
                    glVertex2f(x, y);
                    glVertex2f(x+fW, y);
                    glVertex2f(x+fW, y+fH);
                    glVertex2f(x, y+fH);
                    glEnd();
                    x+=fW+.02;
                }
                x=b.x+.03;
            }



        y+=fH+.05;

    }
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set up a 2D orthographic projection
    //Draw buildings
    // missile(2);


    for(auto b:build1)
    {
        drawBuilding(b);
    }
    glFlush();
}
bool ck=false;
void keyFun(unsigned char key, int x, int y)
{
    // Check if the spacebar is pressed
    if (key == ' ')
    {
        // Loop through each building
        for (auto& b : build1)
        {

                 b.floor--;
                if (b.floor <= 0) {
                b.floor = 0; // Minimum floor count to prevent negative values
                }

                cout<<b.floor<<endl;

                 if(b.floor==1)
                 {
                     b.h=0;
                 }
                 else
                 {
                     float newH=b.h-.11;
                        if(newH>0)
                     {
                         b.h=newH;
                     }
                     else
                     {
                         b.h=0;
                     }
                 }

            }





        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(500, 50);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Example");

    glClearColor(0.30, 0.71, 0.81, 1.0f);  // White background
//glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set clear color to black
    // Define a building


    float x=-.8;
     building1 b1;
        b1= {x,-0.4,.9,.29,9,3,0.79,0.79,0.79,1,1,1};
        build1.push_back(b1);
        x+=.35;
        building1 b2;
            b2= {x,-0.4,.6,.19,6,2,1,0,0,1,1,1};
            build1.push_back(b2);
            x+=.25;
            building1 b3;
            b3= {x,-0.4,.9,.19,9,2,0.79,0.79,0.79,1,1,1};
            build1.push_back(b3);
            x+=.25;
             building1 b4;
            b4= {x,-0.4,.5,.19,5,2,1,0,0,1,1,1};
            build1.push_back(b4);
            x+=.25;
                building1 b5;
        b5= {x,-0.4,.28,.29,3,3,0.79,0.79,0.79,1,1,1};
        build1.push_back(b5);
        x+=.35;


    //cout<<build1.size()<<endl;

    glutKeyboardFunc(keyFun);
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
