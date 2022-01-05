#include<GL/glut.h>
static float Xt = 0.0, Yt = 0.0; 
static float Angle = 0.0; 
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);

   glLoadIdentity();

glTranslatef(Xt, Yt, -15.0);

 glRotatef(Angle, 0.0, 1.0, 0.0);

 glColor3f(0.0, 1.0, 0.0);

glutWireCube(5.0);

   glutSwapBuffers();
}
void init() 
{
   glClearColor(1.0, 1.0, 1.0, 0.0);
}
void key1(unsigned char key, int x, int y)
{
   switch (key) 
   {

      case ' ':
         Angle += 10.0;
         glutPostRedisplay();
         break;
      case 27:
         exit(0);
         break;
    default:
       break;
   }
}
void key2(int key, int x, int y)
{
   if(key == GLUT_KEY_UP) Yt += 0.1;
   if(key == GLUT_KEY_DOWN) Yt -= 0.1;
   if(key == GLUT_KEY_LEFT) Xt -= 0.1;
   if(key == GLUT_KEY_RIGHT) Xt += 0.1;
   glutPostRedisplay();
   
   
   }
   void resize(int w, int h)
{
   glViewport(0, 0, w, h); 
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.);

   glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv) 
{
   glutInit(&argc, argv);

  

   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100); 
   glutCreateWindow("box");
   glutDisplayFunc(display); 
   glutReshapeFunc(resize);  
   glutKeyboardFunc(key1);

   glutSpecialFunc(key2);
   
  init(); 

   glutMainLoop(); 
}
