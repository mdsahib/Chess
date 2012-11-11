# include "iGraphics.h"

int f=1;
int x=203,y=193;
int pg=1;
int board_i=0,board_h=0,board_j=0,board_l=0;
/*
Function iDraw() is called again and again by the system.
*/
void iDraw()
{
//place your drawing codes here
	iClear();
	if(pg==2)
	{

	/*********drawing board***************/

		iSetcolor(0,255,0);

	for(board_i=0,board_h=0;board_i<8;board_i++,board_h+=64)
	{
		for(board_j=0,board_l=0;board_j<8;board_j++,board_l+=64)
		{
			if((board_i%2)==0)
			{
				if((board_j%2)==0)
				{
					iSetcolor(255,0,0);
					iFilledRectangle(board_l,board_h,64,64);
				}
				else
				{
					iSetcolor(0,0,0);
					iFilledRectangle(board_l,board_h,64,64);
				}
			}

			else
			{
				if((board_j%2)==1)
				{
					iSetcolor(255,0,0);
					iFilledRectangle(board_l,board_h,64,64);
				}
				else
				{
					iSetcolor(255,255,255);
					iFilledRectangle(board_l,board_h,64,64);
				}
			}
		}
	}
}
/*
Function iMouseMove() is called when the user presses and drags
the mouse.(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
//place your codes here
}
/*
Function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
{
//place your codes here
	if(mx>=x&&mx<=(x+50)&&my>=y&&my<=(y+25))
	{
		x+=50;
		y-=30;
	}

}
if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
{
//place your codes here
}
}
/*
Function iKeyboard() is called whenever the user hits a key in
keyboard. key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
if(key == 'q')
{
//do something with 'q'
}
//place your codes for other keys here
}
/*
Function iSpecialKeyboard() is called whenver user hits special keys
like- function keys, home, end, pg up, pg down, arraows etc. you have
to use appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5,
GLUT_KEY_F6, GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10,
GLUT_KEY_F11, GLUT_KEY_F12, GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT,
GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME,
GLUT_KEY_END, GLUT_KEY_INSERT.
*/
void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_END)
	{
		iText(50, 60, "Hello", GLUT_BITMAP_8_BY_13);
	}
	//place your codes for other keys here
}
int main()
{
	//place your own initialization codes here before iInitialize().
	iInitialize(400, 400, "demooo");
	return 0;
}
