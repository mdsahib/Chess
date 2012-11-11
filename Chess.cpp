# include "iGraphics.h"





/********************************       Work to do         *********************

class possible move function
check king check function//  alada function
setmousetimer a condition dea+idrawte dea 
mouse holder pix thik kora
player er name input nea







/***********************************************************************************************/
/*                          page number 1 variable                                            */



int pg=1;					/*index of page*/





/******************  NOTE ABOUT PAGE NUMBER & button*******************************************/

/*
    introduction page=1
	start page =2
	sound page =3
	help page =4
	about page=5
	credit page=6
	contact page=7

	
	 


  start button=1
  sound button=2
  help  button=3
  contact button=4
  about button=5
  exit button=6                     */



int start_x=620,start_y=600+50;
int sound_x=620,sound_y=650-75;
int help_x=620,help_y=650-160;
int abt_x=615,abt_y=650-240;
int con_x=620,con_y=650-400;
int cre_x=620,cre_y=650-320;
int exit_x=620,exit_y=650-470;
int pg1_but=0;







/**********                 start page2  variable            *****************************/

/**********************************************************************************************/


int board_i=0;
int board_j=0;
int board_h=64;
int board_l=64;
int turn=0,turn1=0;

int	boardid[8][8]={	
		{140,160,0,0,0,0,260,240},
		{130,161,0,0,0,0,261,230},
		{150,162,0,0,0,0,262,250},
		{120,163,0,0,0,0,263,220},
		{110,164,0,0,0,0,264,210},
		{151,165,0,0,0,0,265,251},
		{131,166,0,0,0,0,266,231},
		{141,167,0,0,0,0,267,241}	
	};

int cp_boardid[8][8]={	
		{140,160,0,0,0,0,260,240},
		{130,161,0,0,0,0,261,230},
		{150,162,0,0,0,0,262,250},
		{120,163,0,0,0,0,263,220},
		{110,164,0,0,0,0,264,210},
		{151,165,0,0,0,0,265,251},
		{131,166,0,0,0,0,266,231},
		{141,167,0,0,0,0,267,241}	
	};

int draw_i=0;

int player=1;//index of current player

int move=0;//for dragging condition
int move_rt=0;
int move_x=0;
int move_y=0;
int move_p=0;
int check=50;


int p_move[8][8]={
				0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0
			};	


int pg2_but=0;
int pg2_con=0;	
int winner=0;
int sound=1;
int mouse=0;
int kcheck=0;
int temp_bi=0;
int temp1_bi=0;


				
/***************        note about object identifier       **************



raza=1
montri=2
ghora=3
nouka=4
hati=5
solder=6


player1=1
player2=2

exmpl:161 means its player 1's solder#1 

cx=current row postion
cy=current column pstion
lx=last row postion
ly=last coulmn postion
bi=board identifier of that object







  **********************************************************************/










/*****************************************************************************************/
/*                          move functions variable                                      */



//****************************  move slide variable           ***************************/

int slide_x=50,slide_y=200;			/*co-ordinate of slide*/


int slide_num=0;     /*keep the index of current slide*/
char slide[20][15]={"board_1.bmp","board_2.bmp","board_3.bmp","board_4.bmp","board_5.bmp",
					"board_6.bmp","board_7.bmp","board_8.bmp","board_8.bmp","board_9.bmp",
					"board_10.bmp","board_11.bmp","board_12.bmp","board_13.bmp"};

/*Its the bmp image name of slideshows*/


/******************        move menu variable			 ************************************/

int menu_x=562-128,menu_y=650+64
;

int menu_condition=0;



/***********************************************************************************************/
/*            end              move functions variable                                            */


/******           mabs definition           ****************************************/


int mabs(int para)
{
	if(para<0)
		return -para;
	else return para;
}



void check_king(int para);











/***********************************************************************************************/









/****************                   object declarations                         ***************/





/********    player 1 objects                     ***************************************/


class raza_c1 
{
public:
int cx,cy,lx,ly,bi,ax,ay,dx,dy,dead;

  
raza_c1(int para,int para1,int para2)
  {
	bi=110+para;
	cx=para1;
	cy=para2;
	lx=cx;
	ly=cy;
	ax=cx*64+144;
	ay=cy*64+144;
	dx=0;
	dy=144+7*64;
	dead=1;


  }

void set_ax(int para)
{
	ax=para;
}

void set_ay(int para)
{
	ay=para;
}  

void set_cx(int para)
{
	cx=para;
}

void set_cy(int para)
{
	cy=para;
}
void set_lx()
{
	lx=cx;
}
void set_ly()
{
	ly=cy;
}

void set_dead()
{
	dead=0;
	ax=dx;
	ay=dy;
}





int get_ax()
{
	return ax;
}

int get_ay()
{
	return ay;
}

int get_cx()
{
	return cx;
}
int get_cy()
{
	return cy;
}
int get_lx()			
{
	return lx;
}
int get_ly()
{
	return ly;
}
int get_bi()
{
	return bi;
}

int get_dx()
{
	return dx;
}

int get_dy()
{
	return dy;
}


int get_dead()
{
	return dead;
}

void check_m()
{
	check=50;
	check_king(2);
	
	if(cx==lx && cy==ly)
		check=50;
	else
	{
		if(mabs(cx-lx)==1 && mabs(cy-ly)==1 && kcheck!=1)
		{
			
			if(boardid[cx][cy]==0)
				check=1;
			if(boardid[cx][cy]/100==2)
				check=2;
		}
		if(((mabs(cx-lx)==0 && mabs(cy-ly)==1)||(mabs(cx-lx)==1 && mabs(cy-ly)==0)) && kcheck!=1)
		{
			if(boardid[cx][cy]==0)
				check=1;
			if(boardid[cx][cy]/100==2)
				check=2;
		}
	}


}//end of check function



void check_k(int p1,int p2)
{
	 
	if(p1==lx && p2==ly)
		kcheck=50;
	else
	{
		if(mabs(p1-lx)==1 && mabs(p2-ly)==1)
		{
			
				kcheck=1;
			
		}
		if((mabs(p1-lx)==0 && mabs(p2-ly)==1)||(mabs(p1-lx)==1 && mabs(p2-ly)==0))
		{
			
				kcheck=1;
			
		}
	}


}//end of check function




}raza1(0,4,0);//end of class




class montri_c1 
{
public:
int cx,cy,lx,ly,bi,ax,ay,dx,dy,dead,i;

  
montri_c1(int para,int para1,int para2)
  {
	bi=120+para;
	cx=para1;
	cy=para2;
	lx=cx;
	ly=cy;
	ax=cx*64+144;
	ay=cy*64+144;
	dx=0;
	dy=144+6*64;
	dead=1;


  }

void set_ax(int para)
{
	ax=para;
}

void set_ay(int para)
{
	ay=para;
}

  void set_cx(int para)
{
	cx=para;
}

void set_cy(int para)
{
	cy=para;
}
void set_lx()
{
	lx=cx;
}
void set_ly()
{
	ly=cy;
}

void set_dead()
{
	dead=0;
	ax=dx;
	ay=dy;
}




int get_ax()
{
	return ax;
}

int get_ay()
{
	return ay;
}

int get_cx()
{
	return cx;
}
int get_cy()
{
	return cy;
}
int get_lx()			
{
	return lx;
}
int get_ly()
{
	return ly;
}
int get_bi()
{
	return bi;
}



int get_dx()
{
	return dx;
}

int get_dy()
{
	return dy;
}


int get_dead()
{
	return dead;
}


void check_m()
{
	check=50;
	if(cx==lx && cy==ly)
		check=50;
	else
	{
	if(mabs(cx-lx)==0||mabs(cy-ly)==0)
	{
		for(i=1;;i++)
		{
			if(mabs(cy-ly)==0)
			{
			
			if(cx>lx)
			{
				
				if(boardid[lx+i][cy]!=0)
								
					break;
					
				
			}
			if(cx<lx)
			{
				if(boardid[lx-i][cy]!=0)
				
					break;
					
				
			}
			
			}//cy=ly condition


			if(mabs(cx-lx)==0)
			{
			
			if(cy>ly)
			{
				
				if(boardid[lx][ly+i]!=0)
					
					
						break;
				
			}
			if(cy<ly)
			{
				if(boardid[lx][ly-i]!=0)
						break;
				
			}
			
			}//cx=lx condition
			
			
			if(lx+i==cx||lx-i==cx||ly+i==cy||ly-i==cy)
			{
			
				break;
			}
			
		}
		
		if(lx+i==cx||lx-i==cx||ly+i==cy||ly-i==cy)
		{
			if(boardid[cx][cy]==0)
				check=1;
			if(boardid[cx][cy]/100==2)
				check=2;
		}
			
	}//condition of possible legal movement


	
	  if(mabs(cx-lx)==mabs(cy-ly))
	{
		for(i=1;;i++)
		{
			
			if(cx>lx)
			{
				if(cy>ly)
				{
					if(boardid[lx+i][ly+i]!=0)
						break;
					
				}
				 if(cy<ly)
				{
					if(boardid[lx+i][ly-i]!=0||boardid[lx+i][ly+i]==2)
						break;
				}
				
			}
			if(cx<lx)
			{
				if(cy>ly)
				{
					if(boardid[lx-i][ly+i]!=0)
						break;
					
				}
				 if(cy<ly)
				{
					if(boardid[lx-i][ly-i]!=0)
						break;
				}
				
			}
			if(lx+i==cx||lx-i==cx)
				break;
			
		}
		if(lx+i==cx||lx-i==cx)
		{
			if(boardid[cx][cy]==0)
				check=1;
			if(boardid[cx][cy]/100==2)
				check=2;
		}
			
	}


	}//condition of no movement
}//end of check function



void check_k(int p1,int p2)
{
	 
	
	
	if(p1==lx && p2==ly)
		kcheck=50;
	else
	{
	if(mabs(p1-lx)==0||mabs(p2-ly)==0)
	{
		for(i=1;;i++)
		{
			if(mabs(p2-ly)==0)
			{
			
			if(p1>lx)
			{
				
				if(boardid[lx+i][p2]!=0)
								
					break;
					
				
			}
			if(p1<lx)
			{
				if(boardid[lx-i][p2]!=0)
				
					break;
					
				
			}
			
			}//p2=ly condition


			if(mabs(p1-lx)==0)
			{
			
			if(p2>ly)
			{
				
				if(boardid[lx][ly+i]!=0)
					
					
						break;
				
			}
			if(p2<ly)
			{
				if(boardid[lx][ly-i]!=0)
						break;
				
			}
			
			}//p1=lx condition
			
			
			if(lx+i==p1||lx-i==p1||ly+i==p2||ly-i==p2)
			{
			
				break;
			}
			
		}
		
		if(lx+i==p1||lx-i==p1||ly+i==p2||ly-i==p2)
		{
		
				kcheck=1;
			
		}
			
	}//condition of possible legal movement


	
	  if(mabs(p1-lx)==mabs(p2-ly))
	{
		for(i=1;;i++)
		{
			
			if(p1>lx)
			{
				if(p2>ly)
				{
					if(boardid[lx+i][ly+i]!=0)
						break;
					
				}
				 if(p2<ly)
				{
					if(boardid[lx+i][ly-i]!=0||boardid[lx+i][ly+i]==2)
						break;
				}
				
			}
			if(p1<lx)
			{
				if(p2>ly)
				{
					if(boardid[lx-i][ly+i]!=0)
						break;
					
				}
				 if(p2<ly)
				{
					if(boardid[lx-i][ly-i]!=0)
						break;
				}
				
			}
			if(lx+i==p1||lx-i==p1)
				break;
			
		}
		if(lx+i==p1||lx-i==p1)
		{
			
				kcheck=1;
			
		}
			
	}


	}//condition of no movement

	
}//end of check function






}montri1(0,3,0);//end of class


class ghora_c1 
{
public:
int cx,cy,lx,ly,bi,ax,ay,dx,dy,dead;

  
ghora_c1(int para,int para1,int para2)
  {
	bi=130+para;
	cx=para1;
	cy=para2;
	lx=cx;
	ly=cy;
	ax=cx*64+144;
	ay=cy*64+144;
	dx=0;
	dy=144+(4+para)*64;
	dead=1;

  }

void set_ax(int para)
{
	ax=para;

}

void set_ay(int para)
{
	ay=para;
	
}
 
 void set_cx(int para)
{
	cx=para;
	
}

void set_cy(int para)
{
	cy=para;
	
}
void set_lx()
{
	lx=cx;
}
void set_ly()
{
	ly=cy;
}

void set_dead()
{
	dead=0;
	ax=dx;
	ay=dy;
}


int get_ax()
{
	return ax;
}

int get_ay()
{
	return ay;
}

int get_cx()
{

	return cx;
}
int get_cy()
{

	return cy;
}
int get_lx()			
{
	return lx;
}
int get_ly()
{
	return ly;
}
int get_bi()
{
	return bi;
}



int get_dx()
{
	return dx;
}

int get_dy()
{
	return dy;
}


int get_dead()
{
	return dead;
}


 void check_m()
{
	check=50;
	 if(mabs(cx-lx)==1)
	{
		if(mabs(cy-ly)==2)
		{
			if(boardid[cx][cy]==0)
			{
				check=1;
			}
			else if(boardid[cx][cy]/100==2)
				{
					check=2;
					
				}
					
			
		}
			
		
	}


	 if(mabs(cy-ly)==1)
	{
		if(mabs(cx-lx)==2)
		{
			if(boardid[cx][cy]==0)
			{
				check=1;
			}
			else
			{
				if(boardid[cx][cy]/100==2)
				{
					check=2;
					
				}
					
			}
		}
			
		
	}


}


 void check_k(int p1,int p2)
{
	 
/*	 temp1_bi=boardid[cx][cy];
	 boardid[cx][cy]=bi;
	
*/	 
		 
		 
		 if(mabs(p1-lx)==1)
	{
		if(mabs(p2-ly)==2)
		{
			
				kcheck=1;
				
			
		}
			
		
	}


	 if(mabs(p2-ly)==1)
	{
		if(mabs(p1-lx)==2)
		{
			kcheck=1;
		}
			
		
	}

//	 boardid[cx][cy]=temp1_bi;


}



}ghora1[2]={ghora_c1(0,1,0),ghora_c1(1,6,0)};//end of class


class nouka_c1 
{
public:
int cx,cy,lx,ly,bi,ax,ay,dx,dy,dead,i;

  
nouka_c1(int para,int para1,int para2)
  {
	bi=140+para;
	cx=para1;
	cy=para2;
	lx=cx;
	ly=cy;
	ax=cx*64+144;
	ay=cy*64+144;
	dx=0;
	dy=144+(0+para)*64;
	dead=1;



  }

void set_ax(int para)
{
	ax=para;
}

void set_ay(int para)
{
	ay=para;
}  




  void set_cx(int para)
{
	cx=para;
}

void set_cy(int para)
{
	cy=para;
}
void set_lx()
{
	lx=cx;
}
void set_ly()
{
	ly=cy;
}

void set_dead()
{
	dead=0;
	ax=dx;
	ay=dy;
}




int get_ax()
{
	return ax;
}

int get_ay()
{
	return ay;
}

int get_cx()
{
	return cx;
}
int get_cy()
{
	return cy;
}
int get_lx()			
{
	return lx;
}
int get_ly()
{
	return ly;
}
int get_bi()
{
	return bi;
}

int get_dx()
{
	return dx;
}

int get_dy()
{
	return dy;
}


int get_dead()
{
	return dead;
}


void check_m()
{
	check=50;
	if(cx==lx && cy==ly)
		check=50;
	else
	{
	if(mabs(cx-lx)==0||mabs(cy-ly)==0)
	{
		for(i=1;;i++)
		{
			if(mabs(cy-ly)==0)
			{
			
			if(cx>lx)
			{
				
				if(boardid[lx+i][cy]!=0)
				{	
					
					break;
				}	
				
			}
			if(cx<lx)
			{
				if(boardid[lx-i][cy]!=0)
				{	
						
						break;
				}		
				
			}
			
			}//cy=ly condition


			if(mabs(cx-lx)==0)
			{
			
			if(cy>ly)
			{
				
				if(boardid[lx][ly+i]!=0)
				{	
					
						break;
				}
			}
			if(cy<ly)
			{
				if(boardid[lx][ly-i]!=0)
						break;
				
			}
			
			}//cx=lx condition
			
			
			if(lx+i==cx||lx-i==cx||ly+i==cy||ly-i==cy)
			{
			
				break;
			}
			
		}
		
		if(lx+i==cx||lx-i==cx||ly+i==cy||ly-i==cy)
		{
			if(boardid[cx][cy]==0)
				check=1;
			if(boardid[cx][cy]/100==2)
				check=2;
		}
			
	}//condition of possible legal movement
	}//condition of no movement

}//end of check function



void check_k(int p1,int p2)
{
	 
	if(p1==lx && p2==ly)
		kcheck=50;
	else
	{
	if(mabs(p1-lx)==0||mabs(p2-ly)==0)
	{
		for(i=1;;i++)
		{
			if(mabs(p2-ly)==0)
			{
			
			if(p1>lx)
			{
				
				if(boardid[lx+i][p2]!=0)
				{	
				
					break;
				}	
				
			}
			if(p1<lx)
			{
				if(boardid[lx-i][p2]!=0)
				{	
					
						break;
				}		
				
			}
			
			}//p2=ly condition


			if(mabs(p1-lx)==0)
			{
			
			if(p2>ly)
			{
				
				if(boardid[lx][ly+i]!=0)
				{	
						
						break;
				}
			}
			if(p2<ly)
			{
				if(boardid[lx][ly-i]!=0)
						break;
				
			}
			
			}//p1=lx condition
			
			
			if(lx+i==p1||lx-i==p1||ly+i==p2||ly-i==p2)
			{
			
				break;
			}
			
		}
		
		if(lx+i==p1||lx-i==p1||ly+i==p2||ly-i==p2)
		{
			
				kcheck=1;
			
		}
			
	}//condition of possible legal movement
	}//condition of no movement

}//end of check function




}nouka1[2]={nouka_c1(0,0,0),nouka_c1(1,7,0)};//end of class


class hati_c1 
{
public:
int cx,cy,lx,ly,bi,ax,ay,dx,dy,dead,i,j;

  
hati_c1(int para,int para1,int para2)
  {
	bi=150+para;
	cx=para1;
	cy=para2;
	lx=cx;
	ly=cy;
	ax=cx*64+144;
	ay=cy*64+144;
	dx=0;
	dy=144+(2+para)*64;
	dead=1;


  }


void set_ax(int para)
{
	ax=para;
}

void set_ay(int para)
{
	ay=para;
}

  void set_cx(int para)
{
	cx=para;
}

void set_cy(int para)
{
	cy=para;
}
void set_lx()
{
	lx=cx;
}
void set_ly()
{
	ly=cy;
}

void set_dead()
{
	dead=0;
	ax=dx;
	ay=dy;
}







int get_ax()
{
	return ax;
}

int get_ay()
{
	return ay;
}

int get_cx()
{
	return cx;
}
int get_cy()
{
	return cy;
}
int get_lx()			
{
	return lx;
}
int get_ly()
{
	return ly;
}
int get_bi()
{
	return bi;
}


int get_dx()
{
	return dx;
}

int get_dy()
{
	return dy;
}


int get_dead()
{
	return dead;
}

void check_m()
{
	check=50;
	if(cx==lx && cy==ly)
		check=50;
	else
	{


	  if(mabs(cx-lx)==mabs(cy-ly))
	{
		for(i=1;;i++)
		{
			
			if(cx>lx)
			{
				if(cy>ly)
				{
					if(boardid[lx+i][ly+i]!=0)
						break;
					
				}
				 if(cy<ly)
				{
					if(boardid[lx+i][ly-i]!=0||boardid[lx+i][ly+i]==2)
						break;
				}
				
			}
			if(cx<lx)
			{
				if(cy>ly)
				{
					if(boardid[lx-i][ly+i]!=0)
						break;
					
				}
				 if(cy<ly)
				{
					if(boardid[lx-i][ly-i]!=0)
						break;
				}
				
			}
			if(lx+i==cx||lx-i==cx)
				break;
			
		}
		if(lx+i==cx||lx-i==cx)
		{
			if(boardid[cx][cy]==0)
				check=1;
			if(boardid[cx][cy]/100==2)
				check=2;
		}
			
	}
	}

}//end of check function





void check_k(int p1,int p2)
{
	 
	if(p1==lx && p2==ly)
		kcheck=50;
	else
	{


	  if(mabs(p1-lx)==mabs(p2-ly))
	{
		for(i=1;;i++)
		{
			
			if(p1>lx)
			{
				if(p2>ly)
				{
					if(boardid[lx+i][ly+i]!=0)
						break;
					
				}
				 if(p2<ly)
				{
					if(boardid[lx+i][ly-i]!=0||boardid[lx+i][ly+i]==2)
						break;
				}
				
			}
			if(p1<lx)
			{
				if(p2>ly)
				{
					if(boardid[lx-i][ly+i]!=0)
						break;
					
				}
				 if(p2<ly)
				{
					if(boardid[lx-i][ly-i]!=0)
						break;
				}
				
			}
			if(lx+i==p1||lx-i==p1)
				break;
			
		}
		if(lx+i==p1||lx-i==p1)
		{
			
				kcheck=1;
			
		}
			
	}
	}

}//end of check function



}hati1[2]={hati_c1(0,2,0),hati_c1(1,5,0)};//end of class



class solder_c1 
{
public:
int cx,cy,lx,ly,bi,ax,ay,dx,dy,dead,tr;

  
solder_c1(int para,int para1,int para2)
  {
	bi=160+para;
	cx=para1;
	cy=para2;
	lx=cx;
	ly=cy;
	ax=cx*64+144;
	ay=cy*64+144;
	dx=64;
	dy=144+para*64;
	dead=1;
	tr=0;
	

  }

void set_ax(int para)
{
	ax=para;

}

void set_ay(int para)
{
	ay=para;

}

  void set_cx(int para)
{
	cx=para;

	

}

void set_cy(int para)
{
	cy=para;

}
void set_lx()
{
	lx=cx;

}
void set_ly()
{
	ly=cy;

}

void set_dead()
{
	dead=0;
	ax=dx;
	ay=dy;
}

int get_dx()
{
	return dx;
}

int get_dy()
{
	return dy;
}


int get_dead()
{
	return dead;
}


int get_ax()
{
	return ax;
}

int get_ay()
{
	return ay;
}

int get_cx()
{
	return cx;
}
int get_cy()
{
	return cy;
}
int get_lx()			
{

	return lx;
}
int get_ly()
{

	return ly;
}
int get_bi()
{
	return bi;
}

void check_m()
{

	check=50;
	if(cx==lx && cy==ly)
		check=50;
	else{

	if(cx-lx!=0 && mabs(cx -lx)!=1)
			check=0;			//its a illegal move condition
	else		//checking whether its a legal move
	{
		if(cx-lx==0)			//  dif of x co-o is zero
		{
			if(tr==0)		//1st turn of this object
			{
				if(cy-ly==1|| cy-ly==2)		
					
				{
					
					tr++;
				
					check=1;				//dif of 2 or 1 y co-ordinate allowed
				}
				else check=0;				//its a illegal move
			}
			else							//turn is second and dif of x co is zero
			{
				
				if(cy-ly==1)
				{
					if(boardid[cx][cy]!=0)	//x dif is zero and piece is there
						check=0;
					else check=1;			//x dif is zero and empty square
				}
				else check=15;			//illegal move
			}

		}
		else								//cx-lx!=0						
		{
			if(mabs(cx-lx)==1 && cy-ly==1) //x dif 1,and y dif 1,condition for eating
		{
			if(boardid[cx][cy]/100==2)		//opponent is there
				check=2;
			else check=0;						//opponent isnt there
		}
			else check=0;					//cx-lx!=0 && eating isnt possible
		}
	
	}


	}

}//end of check



void check_k(int p1,int p2)
{

	 
	if(p1==lx && p2==ly)
		kcheck=50;
	else{

	if(p1-lx!=0 && mabs(p1 -lx)!=1)
			kcheck=0;			//its a illegal move condition
	else		//kchecking whether its a legal move
	{
		
										//p1-lx!=0						
		
			if(mabs(p1-lx)==1 && p2-ly==1) //x dif 1,and y dif 1,condition for eating
		{
			if(boardid[p1][p2]/100==2)		//opponent is there
				kcheck=1;
							//cx-lx!=0 && eating isnt possible
		
	
		}


	}

	}

}//end of check





}solder1[8]={solder_c1(0,0,1),solder_c1(1,1,1),solder_c1(2,2,1),solder_c1(3,3,1),
				solder_c1(4,4,1),solder_c1(5,5,1),solder_c1(6,6,1),solder_c1(7,7,1)};





/**************** player 2 objects       ***********************************************/


class raza_c2 
{
public:
int cx,cy,lx,ly,bi,ax,ay,dx,dy,dead;

  
raza_c2(int para,int para1,int para2)
  {
	bi=210+para;
	cx=para1;
	cy=para2;
	lx=cx;
	ly=cy;
	ax=cx*64+144;
	ay=cy*64+144;
	dx=800-64;
	dy=144+7*64;
	dead=1;

  }


void set_ax(int para)
{
	ax=para;
}

void set_ay(int para)
{
	ay=para;
}

  void set_cx(int para)
{
	cx=para;
}

void set_cy(int para)
{
	cy=para;
}
void set_lx()
{
	lx=cx;
}
void set_ly()
{
	ly=cy;
}

void set_dead()
{
	dead=0;
	ax=dx;
	ay=dy;
}

int get_dx()
{
	return dx;
}

int get_dy()
{
	return dy;
}


int get_dead()
{
	return dead;
}


int get_ax()
{
	return ax;
}

int get_ay()
{
	return ay;
}

int get_cx()
{
	return cx;
}
int get_cy()
{
	return cy;
}
int get_lx()			
{
	return lx;
}
int get_ly()
{
	return ly;
}
int get_bi()
{
	return bi;
}

void check_m()
{
	check=50;
	check_king(1);
	
	if(cx==lx && cy==ly)
		check=50;
	else
	{
		if(mabs(cx-lx)==1 && mabs(cy-ly)==1 && kcheck!=1)
		{
			
			if(boardid[cx][cy]==0)
				check=1;
			if(boardid[cx][cy]/100==2)
				check=2;
		}
		if(((mabs(cx-lx)==0 && mabs(cy-ly)==1)||(mabs(cx-lx)==1 && mabs(cy-ly)==0)) && kcheck!=1)
		{
			if(boardid[cx][cy]==0)
				check=1;
			if(boardid[cx][cy]/100==2)
				check=2;
		}
	}


}//end of check function



void check_k(int p1,int p2)
{
	 
	if(p1==lx && p2==ly)
		kcheck=50;
	else
	{
		if(mabs(p1-lx)==1 && mabs(p2-ly)==1)
		{
			
				kcheck=1;
			
		}
		if((mabs(p1-lx)==0 && mabs(p2-ly)==1)||(mabs(p1-lx)==1 && mabs(p2-ly)==0))
		{
			
				kcheck=1;
			
		}
	}


}//end of check function


}raza2(0,4,7);//end of class




class montri_c2 
{
public:
int cx,cy,lx,ly,bi,ax,ay,dx,dy,dead,i;

  
montri_c2(int para,int para1,int para2)
  {
	bi=220+para;
	cx=para1;
	cy=para2;
	lx=cx;
	ly=cy;
	ax=cx*64+144;
	ay=cy*64+144;
	dx=800-64;
	dy=144+6*64;
	dead=1;

  }

void set_ax(int para)
{
	ax=para;
}

void set_ay(int para)
{
	ay=para;
} 

 void set_cx(int para)
{
	cx=para;
}

void set_cy(int para)
{
	cy=para;
}
void set_lx()
{
	lx=cx;
}
void set_ly()
{
	ly=cy;
}


void set_dead()
{
	dead=0;
	ax=dx;
	ay=dy;
}

int get_dx()
{
	return dx;
}

int get_dy()
{
	return dy;
}


int get_dead()
{
	return dead;
}


int get_ax()
{
	return ax;
}

int get_ay()
{
	return ay;
}

int get_cx()
{
	return cx;
}
int get_cy()
{
	return cy;
}
int get_lx()			
{
	return lx;
}
int get_ly()
{
	return ly;
}
int get_bi()
{
	return bi;
}

void check_m()
{
	check=50;
	if(cx==lx && cy==ly)
		check=50;
	else
	{
	if(mabs(cx-lx)==0||mabs(cy-ly)==0)
	{
		for(i=1;;i++)
		{
			if(mabs(cy-ly)==0)
			{
			
			if(cx>lx)
			{
				
				if(boardid[lx+i][cy]!=0)
				{	
				
					break;
				}	
				
			}
			if(cx<lx)
			{
				if(boardid[lx-i][cy]!=0)
				{	
					
						break;
				}		
				
			}
			
			}//cy=ly condition


			if(mabs(cx-lx)==0)
			{
			
			if(cy>ly)
			{
				
				if(boardid[lx][ly+i]!=0)
				{	
					
						break;
				}
			}
			if(cy<ly)
			{
				if(boardid[lx][ly-i]!=0)
						break;
				
			}
			
			}//cx=lx condition
			
			
			if(lx+i==cx||lx-i==cx||ly+i==cy||ly-i==cy)
			{
			
				break;
			}
			
		}
		
		if(lx+i==cx||lx-i==cx||ly+i==cy||ly-i==cy)
		{
			if(boardid[cx][cy]==0)
				check=1;
			if(boardid[cx][cy]/100==1)
				check=2;
		}
			
	}//condition of possible legal movement


	
	  if(mabs(cx-lx)==mabs(cy-ly))
	{
		for(i=1;;i++)
		{
			
			if(cx>lx)
			{
				if(cy>ly)
				{
					if(boardid[lx+i][ly+i]!=0)
						break;
					
				}
				 if(cy<ly)
				{
					if(boardid[lx+i][ly-i]!=0||boardid[lx+i][ly+i]==2)
						break;
				}
				
			}
			if(cx<lx)
			{
				if(cy>ly)
				{
					if(boardid[lx-i][ly+i]!=0)
						break;
					
				}
				 if(cy<ly)
				{
					if(boardid[lx-i][ly-i]!=0)
						break;
				}
				
			}
			if(lx+i==cx||lx-i==cx)
				break;
			
		}
		if(lx+i==cx||lx-i==cx)
		{
			if(boardid[cx][cy]==0)
				check=1;
			if(boardid[cx][cy]/100==1)
				check=2;
		}
			
	}


	}//condition of no movement
}//end of check function


void check_k(int p1,int p2)
{
	 
	if(p1==lx && p2==ly)
		kcheck=50;
	else
	{
	if(mabs(p1-lx)==0||mabs(p2-ly)==0)
	{
		for(i=1;;i++)
		{
			if(mabs(p2-ly)==0)
			{
			
			if(p1>lx)
			{
				
				if(boardid[lx+i][p2]!=0)
								
					break;
					
				
			}
			if(p1<lx)
			{
				if(boardid[lx-i][p2]!=0)
				
					break;
					
				
			}
			
			}//p2=ly condition


			if(mabs(p1-lx)==0)
			{
			
			if(p2>ly)
			{
				
				if(boardid[lx][ly+i]!=0)
					
					
						break;
				
			}
			if(p2<ly)
			{
				if(boardid[lx][ly-i]!=0)
						break;
				
			}
			
			}//p1=lx condition
			
			
			if(lx+i==p1||lx-i==p1||ly+i==p2||ly-i==p2)
			{
			
				break;
			}
			
		}
		
		if(lx+i==p1||lx-i==p1||ly+i==p2||ly-i==p2)
		{
		
				kcheck=1;
			
		}
			
	}//condition of possible legal movement


	
	  if(mabs(p1-lx)==mabs(p2-ly))
	{
		for(i=1;;i++)
		{
			
			if(p1>lx)
			{
				if(p2>ly)
				{
					if(boardid[lx+i][ly+i]!=0)
						break;
					
				}
				 if(p2<ly)
				{
					if(boardid[lx+i][ly-i]!=0||boardid[lx+i][ly+i]==2)
						break;
				}
				
			}
			if(p1<lx)
			{
				if(p2>ly)
				{
					if(boardid[lx-i][ly+i]!=0)
						break;
					
				}
				 if(p2<ly)
				{
					if(boardid[lx-i][ly-i]!=0)
						break;
				}
				
			}
			if(lx+i==p1||lx-i==p1)
				break;
			
		}
		if(lx+i==p1||lx-i==p1)
		{
			
				kcheck=1;
			
		}
			
	}


	}//condition of no movement
}//end of check function





}montri2(0,3,7);//end of class


class ghora_c2 
{
public:
int cx,cy,lx,ly,bi,ax,ay,dx,dy,dead;

  
ghora_c2(int para,int para1,int para2)
  {
	bi=230+para;
	cx=para1;
	cy=para2;
	lx=cx;
	ly=cy;
	ax=cx*64+144;
	ay=cy*64+144;
	dx=800-64;
	dy=144+(4+para)*64;
	dead=1;


  }

void set_ax(int para)
{
	ax=para;
}

void set_ay(int para)
{
	ay=para;
}

  void set_cx(int para)
{
	cx=para;
}

void set_cy(int para)
{
	cy=para;
}
void set_lx()
{
	lx=cx;
}
void set_ly()
{
	ly=cy;
}

void set_dead()
{
	dead=0;
	ax=dx;
	ay=dy;
}




int get_dx()
{
	return dx;
}

int get_dy()
{
	return dy;
}


int get_dead()
{
	return dead;
}


int get_ax()
{
	return ax;
}

int get_ay()
{
	return ay;
}

int get_cx()
{
	return cx;
}
int get_cy()
{
	return cy;
}
int get_lx()			
{
	return lx;
}
int get_ly()
{
	return ly;
}
int get_bi()
{
	return bi;
}

 void check_m()
{
	check=50;
	if(cx==lx && cy==ly)
		check=50;

	 if(mabs(cx-lx)==1)
	{
		if(mabs(cy-ly)==2)
		{
			if(boardid[cx][cy]==0)
			{
				check=1;
			}
			else if(boardid[cx][cy]/100==1)
				{
					check=2;
					
				}
					
			
		}
			
		
	}


	 if(mabs(cy-ly)==1)
	{
		if(mabs(cx-lx)==2)
		{
			if(boardid[cx][cy]==0)
			{
				check=1;
			}
			else
			{
				if(boardid[cx][cy]/100==1)
				{
					check=2;
					
				}
					
			}
		}
			
		
	}


}//end of check function



 void check_k(int p1,int p2)
{
	 
	if(p1==lx && p2==ly)
		kcheck=50;

	 if(mabs(p1-lx)==1)
	{
		if(mabs(p2-ly)==2)
		{
			
				kcheck=1;
				
			
		}
			
		
	}


	 if(mabs(p2-ly)==1)
	{
		if(mabs(p1-lx)==2)
		{
			
				kcheck=1;
			
		}
			
		
	}


}//end of check function




}ghora2[2]={ghora_c2(0,1,7),ghora_c2(1,6,7)};//end of class


class nouka_c2 
{
public:
int cx,cy,lx,ly,bi,ax,ay,dx,dy,dead,i;

  
nouka_c2(int para,int para1,int para2)
  {
	bi=240+para;
	cx=para1;
	cy=para2;
	lx=cx;
	ly=cy;
	ax=cx*64+144;
	ay=cy*64+144;
	dx=800-64;
	dy=144+(0+para)*64;
	dead=1;

  }

void set_ax(int para)
{
	ax=para;
}

void set_ay(int para)
{
	ay=para;
}  


void set_cx(int para)
{
	cx=para;
}

void set_cy(int para)
{
	cy=para;
}
void set_lx()
{
	lx=cx;
}
void set_ly()
{
	ly=cy;
}

void set_dead()
{
	dead=0;
	ax=dx;
	ay=dy;
}




int get_dx()
{
	return dx;
}

int get_dy()
{
	return dy;
}


int get_dead()
{
	return dead;
}


int get_ax()
{
	return ax;
}

int get_ay()
{
	return ay;
}

int get_cx()
{
	return cx;
}
int get_cy()
{
	return cy;
}
int get_lx()			
{
	return lx;
}
int get_ly()
{
	return ly;
}
int get_bi()
{
	return bi;
}

void check_m()
{
	check=50;
	if(cx==lx && cy==ly)
		check=50;
	else
	{
	if(mabs(cx-lx)==0||mabs(cy-ly)==0)
	{
		for(i=1;;i++)
		{
			if(mabs(cy-ly)==0)
			{
			
			if(cx>lx)
			{
				
				if(boardid[lx+i][cy]!=0)
				{	
				
					break;
				}	
				
			}
			if(cx<lx)
			{
				if(boardid[lx-i][cy]!=0)
				{	
					
						break;
				}		
				
			}
			
			}//cy=ly condition


			if(mabs(cx-lx)==0)
			{
			
			if(cy>ly)
			{
				
				if(boardid[lx][ly+i]!=0)
				{	
						
						break;
				}
			}
			if(cy<ly)
			{
				if(boardid[lx][ly-i]!=0)
						break;
				
			}
			
			}//cx=lx condition
			
			
			if(lx+i==cx||lx-i==cx||ly+i==cy||ly-i==cy)
			{
			
				break;
			}
			
		}
		
		if(lx+i==cx||lx-i==cx||ly+i==cy||ly-i==cy)
		{
			if(boardid[cx][cy]==0)
				check=1;
			if(boardid[cx][cy]/100==1)
				check=2;
		}
			
	}//condition of possible legal movement
	}//condition of no movement

}//end of check function



void check_k(int p1,int p2)
{
	 
	if(p1==lx && p2==ly)
		kcheck=50;
	else
	{
	if(mabs(p1-lx)==0||mabs(p2-ly)==0)
	{
		for(i=1;;i++)
		{
			if(mabs(p2-ly)==0)
			{
			
			if(p1>lx)
			{
				
				if(boardid[lx+i][p2]!=0)
				{	
				
					break;
				}	
				
			}
			if(p1<lx)
			{
				if(boardid[lx-i][p2]!=0)
				{	
					
						break;
				}		
				
			}
			
			}//p2=ly condition


			if(mabs(p1-lx)==0)
			{
			
			if(p2>ly)
			{
				
				if(boardid[lx][ly+i]!=0)
				{	
						
						break;
				}
			}
			if(p2<ly)
			{
				if(boardid[lx][ly-i]!=0)
						break;
				
			}
			
			}//p1=lx condition
			
			
			if(lx+i==p1||lx-i==p1||ly+i==p2||ly-i==p2)
			{
			
				break;
			}
			
		}
		
		if(lx+i==p1||lx-i==p1||ly+i==p2||ly-i==p2)
		{
			
				kcheck=1;
			
		}
			
	}//condition of possible legal movement
	}//condition of no movement

}//end of check function






}nouka2[2]={nouka_c2(0,0,7),nouka_c2(1,7,7)};//end of class


class hati_c2 
{
public:
int cx,cy,lx,ly,bi,ax,ay,dx,dy,dead,i;

  
hati_c2(int para,int para1,int para2)
  {
	bi=250+para;
	cx=para1;
	cy=para2;
	lx=cx;
	ly=cy;
	ax=cx*64+144;
	ay=cy*64+144;
	dx=800-64;
	dy=144+(2+para)*64;
	dead=1;
  }

void set_ax(int para)
{
	ax=para;
}

void set_ay(int para)
{
	ay=para;
}  

void set_cx(int para)
{
	cx=para;
}

void set_cy(int para)
{
	cy=para;
}
void set_lx()
{
	lx=cx;
}
void set_ly()
{
	ly=cy;
}

void set_dead()
{
	dead=0;
	ax=dx;
	ay=dy;
}




int get_dx()
{
	return dx;
}

int get_dy()
{
	return dy;
}


int get_dead()
{
	return dead;
}



int get_ax()
{
	return ax;
}

int get_ay()
{
	return ay;
}

int get_cx()
{
	return cx;
}
int get_cy()
{
	return cy;
}
int get_lx()			
{
	return lx;
}
int get_ly()
{
	return ly;
}
int get_bi()
{
	return bi;
}

void check_m()
{
	check=50;
	if(cx==lx && cy==ly)
		check=50;
	else
	{


	  if(mabs(cx-lx)==mabs(cy-ly))
	{
		for(i=1;;i++)
		{
			
			if(cx>lx)
			{
				if(cy>ly)
				{
					if(boardid[lx+i][ly+i]!=0)
						break;
					
				}
				 if(cy<ly)
				{
					if(boardid[lx+i][ly-i]!=0)
						break;
				}
				
			}
			if(cx<lx)
			{
				if(cy>ly)
				{
					if(boardid[lx-i][ly+i]!=0)
						break;
					
				}
				 if(cy<ly)
				{
					if(boardid[lx-i][ly-i]!=0)
						break;
				}
				
			}
			if(lx+i==cx||lx-i==cx)
				break;
			
		}
		if(lx+i==cx||lx-i==cx)
		{
			if(boardid[cx][cy]==0)
				check=1;
			if(boardid[cx][cy]/100==1)
				check=2;
		}
			
	}
	}

}//end of check function




void check_k(int p1,int p2)
{
	 
	if(p1==lx && p2==ly)
		kcheck=50;
	else
	{


	  if(mabs(p1-lx)==mabs(p2-ly))
	{
		for(i=1;;i++)
		{
			
			if(p1>lx)
			{
				if(p2>ly)
				{
					if(boardid[lx+i][ly+i]!=0)
						break;
					
				}
				 if(p2<ly)
				{
					if(boardid[lx+i][ly-i]!=0||boardid[lx+i][ly+i]==2)
						break;
				}
				
			}
			if(p1<lx)
			{
				if(p2>ly)
				{
					if(boardid[lx-i][ly+i]!=0)
						break;
					
				}
				 if(p2<ly)
				{
					if(boardid[lx-i][ly-i]!=0)
						break;
				}
				
			}
			if(lx+i==p1||lx-i==p1)
				break;
			
		}
		if(lx+i==p1||lx-i==p1)
		{
			
				kcheck=1;
			
		}
			
	}
	}

}//end of check function


}hati2[2]={hati_c2(0,2,7),hati_c2(1,5,7)};//end of class






class solder_c2 
{
public:
int cx,cy,lx,ly,bi,ax,ay,dx,dy,dead,tr;

  
solder_c2(int para,int para1,int para2)
  {
	bi=260+para;
	cx=para1;
	cy=para2;
	lx=cx;
	ly=cy;
	ax=cx*64+144;
	ay=cy*64+144;
	dx=800-128;
	dy=144+(0+para)*64;
	dead=1;
	tr=0;

  }

void set_ax(int para)
{
	ax=para;
}

void set_ay(int para)
{
	ay=para;
}

  void set_cx(int para)
{
	cx=para;
}

void set_cy(int para)
{
	cy=para;
}
void set_lx()
{
	lx=cx;
}
void set_ly()
{
	ly=cy;
}

void set_dead()
{
	dead=0;
	ax=dx;
	ay=dy;
}




int get_dx()
{
	return dx;
}

int get_dy()
{
	return dy;
}


int get_dead()
{
	return dead;
}


int get_ax()
{
	return ax;
}

int get_ay()
{
	return ay;
}

int get_cx()
{
	return cx;
}
int get_cy()
{
	return cy;
}
int get_lx()			
{
	return lx;
}
int get_ly()
{
	return ly;
}
int get_bi()
{
	return bi;
}

void check_m()
{

	check=50;
	if(cx==lx && cy==ly)
		check=50;
	else{

	if(cx-lx!=0 && mabs(cx -lx)!=1)
			check=0;			//its a illegal move condition
	else		//checking whether its a legal move
	{
		if(cx-lx==0)			//  dif of x co-o is zero
		{
			if(tr==0)		//1st turn of this object
			{
				if(cy-ly==-1 || cy-ly==-2)		
					
				{
					
					tr++;
				
					check=1;				//dif of 2 or 1 y co-ordinate allowed
				}
				else check=0;				//its a illegal move
			}
			else							//turn is second and dif of x co is zero
			{
				
				if(cy-ly==-1)
				{
					if(boardid[cx][cy]!=0)	//x dif is zero and piece is there
						check=0;
					else check=1;			//x dif is zero and empty square
				}
				else check=15;			//illegal move
			}

		}
		else								//cx-lx!=0						
		{
			if(mabs(cx-lx)==1 && cy-ly==-1) //x dif 1,and y dif 1,condition for eating
		{
			if(boardid[cx][cy]/100==1)			//opponent is there
				check=2;
			else check=0;						//opponent isnt there
		}
			else check=0;					//cx-lx!=0 && eating isnt possible
		}
	
	}


	}

}//end of check



void check_k(int p1,int p2)
{

	 
	if(p1==lx && p2==ly)
		kcheck=50;
	else{

	if(p1-lx!=0 && mabs(p1 -lx)!=1)
			kcheck=0;			//its a illegal move condition
	else		//kchecking whether its a legal move
	{
		
										//p1-lx!=0						
		
			if(mabs(p1-lx)==1 && p2-ly==-1) //x dif 1,and y dif 1,condition for eating
		{
			if(boardid[p1][p2]/100==2)		//opponent is there
				kcheck=1;
							//cx-lx!=0 && eating isnt possible
		
	
		}


	}

	}

}//end of check




}solder2[8]={solder_c2(0,0,6),solder_c2(1,1,6),solder_c2(2,2,6),solder_c2(3,3,6),
				solder_c2(4,4,6),solder_c2(5,5,6),solder_c2(6,6,6),solder_c2(7,7,6)};







/*********                           end of object declaration                *************/


/*******************************functions for page 2    *****************************/



/********************************************************************************************/



/*******                   verify king check                   *********************************************/


void check_king (int para)
{
	kcheck=50;
	if(para==1)
	{
		if(kcheck!=1)
		{
			if(boardid[raza1.get_cx()][raza1.get_cy()]/100!=2)
				raza1.check_k(raza2.get_cx(),raza2.get_cy());
		}
		if(kcheck!=1)
		{
			if(boardid[montri1.get_cx()][montri1.get_cy()]/100!=2)
				montri1.check_k(raza2.get_cx(),raza2.get_cy());
		}
		if(kcheck!=1)
		{
				for(draw_i=0;draw_i<2;draw_i++)
			{
			
					if(boardid[hati1[draw_i].get_cx()][hati1[draw_i].get_cy()]/100!=2)
						hati1[draw_i].check_k(raza2.get_cx(),raza2.get_cy());
			}
		}
		
		if(kcheck!=1)
		{

		
			for(draw_i=0;draw_i<2;draw_i++)
			{
			if(boardid[ghora1[draw_i].get_cx()][ghora1[draw_i].get_cy()]/100!=2)
				ghora1[draw_i].check_k(raza2.get_cx(),raza2.get_cy());
			}
		
		}
		
		if(kcheck!=1)
		{
			for(draw_i=0;draw_i<2;draw_i++)
			{
			if(boardid[nouka1[draw_i].get_cx()][nouka1[draw_i].get_cy()]/100!=2)
				nouka1[draw_i].check_k(raza2.get_cx(),raza2.get_cy());
			}
		}

		if(kcheck!=1)
		{
			for(draw_i=0;draw_i<8;draw_i++)
			{
			if(boardid[solder1[draw_i].get_cx()][solder1[draw_i].get_cy()]/100!=2)
				solder1[draw_i].check_k(raza2.get_cx(),raza2.get_cy());
			}
		}

	}



	if(para==2)
	{
		
		if(kcheck!=1)
		{
			if(boardid[raza2.get_cx()][raza2.get_cy()]/100!=1)
				raza2.check_k(raza1.get_cx(),raza1.get_cy());
		}
		if(kcheck!=1)
		{
			if(boardid[montri2.get_cx()][montri2.get_cy()]/100!=1)
				montri2.check_k(raza1.get_cx(),raza1.get_cy());
			
		}

		if(kcheck!=1)
		{
			for(draw_i=0;draw_i<2;draw_i++)
		{
			if(boardid[hati2[draw_i].get_cx()][hati2[draw_i].get_cy()]/100!=1)
						hati2[draw_i].check_k(raza1.get_cx(),raza1.get_cy());
		}
		}
		
		if(kcheck!=1)
		{
			for(draw_i=0;draw_i<2;draw_i++)
		{
			if(boardid[ghora2[draw_i].get_cx()][ghora2[draw_i].get_cy()]/100!=1)
				ghora2[draw_i].check_k(raza1.get_cx(),raza1.get_cy());
		}
		}

		if(kcheck!=1)
		{
			for(draw_i=0;draw_i<2;draw_i++)
		{
			if(boardid[nouka2[draw_i].get_cx()][nouka2[draw_i].get_cy()]/100!=1)
				nouka2[draw_i].check_k(raza1.get_cx(),raza1.get_cy());
		}
		}
	
		if(kcheck!=1)
		{
			for(draw_i=0;draw_i<8;draw_i++)
		{
			if(boardid[solder2[draw_i].get_cx()][solder2[draw_i].get_cy()]/100!=1)
				solder2[draw_i].check_k(raza1.get_cx(),raza1.get_cy());
		}
		}
	}





}

















/**********************                eat pieces                   ///////////*************************/

void make_dead()
{
	/**    eat plaer 1 pieces     */
	if(move_p/100==1)
	{
		if(move_p/10==11)
		{
			winner=2;
			raza1.set_dead();
			if(sound==1)
				printf("\a");
		}
		
		if(move_p/10==12)
			montri1.set_dead();

		if(move_p/10==13)
			ghora1[move_p%10].set_dead();

		if(move_p/10==14)
			nouka1[move_p%10].set_dead();
		
		if(move_p/10==15)
			hati1[move_p%10].set_dead();

		if(move_p/10==16)
		{
			solder1[move_p%10].set_dead();
		
		}

	}


	if(move_p/100==2)
	{
		if(move_p/10==21)
		{
			winner=1;
			raza2.set_dead();
			if(sound==1)
				printf("\a");
		}
		
		if(move_p/10==22)
		{
			montri2.set_dead();
			
		}
		if(move_p/10==23)
			ghora2[move_p%10].set_dead();

		if(move_p/10==24)
			nouka2[move_p%10].set_dead();
		
		if(move_p/10==25)
			hati2[move_p%10].set_dead();

		if(move_p/10==26)
			solder2[move_p%10].set_dead();

	}




}//end of make_dead







/***********************************************************************************************/









/*
Function iDraw() is called again and again by the system.
*/
void iDraw()
{
//place your drawing codes here
	iClear();
	

	/***          for intro page    *****************/
	if(pg==1)
	{
		iSetcolor(255,0,0);
		iShowBMP(slide_x,slide_y,slide[slide_num]);
		iShowBMP(menu_x,menu_y,"menu.bmp");
		iShowBMP(sound_x,sound_y,"sound.bmp");
		iShowBMP(exit_x,exit_y,"exit.bmp");
		iShowBMP(help_x,help_y,"help.bmp");
		iShowBMP(start_x,start_y,"start.bmp");
		iShowBMP(abt_x,abt_y,"about.bmp");
		iShowBMP(con_x,con_y,"contact.bmp");
		iShowBMP(cre_x,cre_y,"credits.bmp");
		
	}
	
/* *****************  for start page       */

	if(pg==2)
	{

	/*********drawing board***************/

		iSetcolor(0,0,0);
		iFilledRectangle(0,0,800,800);
		iShowBMP(144-16,144-16,"border3.bmp");
		iShowBMP(144,144-16,"border1.bmp");
		iShowBMP(800-144,144-16,"border3.bmp");
		iShowBMP(800-144,144,"border2.bmp");
		iShowBMP(800-144,800-144,"border3.bmp");
		iShowBMP(144,800-144,"border1.bmp");
		iShowBMP(144-16,144,"border2.bmp");
		iShowBMP(144-16,512+144,"border1.bmp");


	for(board_i=0,board_h=144;board_i<8;board_i++,board_h=board_h+64)
	{
		for(board_j=0,board_l=144;board_j<8;board_j++,board_l=board_l+64)
		{
			if((board_i%2)==0)
			{
				if((board_j%2)==0)
				{
					iSetcolor(0,0,0);
					iFilledRectangle(board_l,board_h,64,64);
				}
				else
				{
					iSetcolor(255,255,255);
					iFilledRectangle(board_l,board_h,64,64);
				}
			}

			else
			{
				if((board_j%2)==1)
				{
					iSetcolor(0,0,0);
					iFilledRectangle(board_l,board_h,64,64);
				}
				else
				{
					iSetcolor(255,255,255);
					iFilledRectangle(board_l,board_h,64,64);
				}
			}
		}/*end of boar_j loop*/
	}/*end of for loop*/


	//player 1 raza
	if(player==2)
	{

	if(raza1.get_ax()<144 || raza1.get_ax()>144+512 || raza1.get_ay()<144 || raza1.get_ay()>144+512)
	{
		if(raza1.get_dead()==0)
			iShowBMP(raza1.get_dx(),raza1.get_dy(),"raza12.bmp");	
	}

	else	
	{
		if(raza1.get_cx()%2==0)
		{
			if(raza1.get_cy()%2==0)
				iShowBMP((raza1.get_cx()*64)+144,(raza1.get_cy()*64)+144,"raza12.bmp");
			else iShowBMP((raza1.get_cx()*64)+144,(raza1.get_cy()*64)+144,"raza11.bmp");

		}
		else
		{
			if(raza1.get_cy()%2==0)
				iShowBMP((raza1.get_cx()*64)+144,(raza1.get_cy()*64)+144,"raza11.bmp");
			else iShowBMP((raza1.get_cx()*64)+144,(raza1.get_cy()*64)+144,"raza12.bmp");
		}
	}
	






	//player 1 montri

	if(montri1.get_ax()<144 || montri1.get_ax()>144+512 || montri1.get_ay()<144 || montri1.get_ay()>144+512)
	{
			if(montri1.get_ax()<144 || montri1.get_ax()>144+512 || montri1.get_ay()<144 || montri1.get_ay()>144+512)
			{
				if(montri1.get_dead()==0)
					iShowBMP(montri1.get_dx(),montri1.get_dy(),"montri12.bmp");	
			}

	
	}

	else	
	{


		if(montri1.get_cx()%2==0)
		{
			if(montri1.get_cy()%2==0)
				iShowBMP((montri1.get_cx()*64)+144,(montri1.get_cy()*64)+144,"montri12.bmp");
			else iShowBMP((montri1.get_cx()*64)+144,(montri1.get_cy()*64)+144,"montri11.bmp");

		}
		else
		{
			if(montri1.get_cy()%2==0)
				iShowBMP((montri1.get_cx()*64)+144,(montri1.get_cy()*64)+144,"montri11.bmp");
			else iShowBMP((montri1.get_cx()*64)+144,(montri1.get_cy()*64)+144,"montri12.bmp");
		}

	}
		
	
	
	
	
	
	//player 1 ghora

	for(draw_i=0;draw_i<2;draw_i++)
	{
		if(ghora1[draw_i].get_ax()<144 || ghora1[draw_i].get_ax()>144+512 || ghora1[draw_i].get_ay()<144 || ghora1[draw_i].get_ay()>144+512)
	{
			if(ghora1[draw_i].get_ax()<144 || ghora1[draw_i].get_ax()>144+512 || ghora1[draw_i].get_ay()<144 || ghora1[draw_i].get_ay()>144+512)
			{
				if(ghora1[draw_i].get_dead()==0)
					iShowBMP(ghora1[draw_i].get_dx(),ghora1[draw_i].get_dy(),"ghora12.bmp");	
			}

	
	}

	else	
	{

		if(ghora1[draw_i].get_cx()%2==0)
		{
			if(ghora1[draw_i].get_cy()%2==0)
				iShowBMP((ghora1[draw_i].get_cx()*64)+144,(ghora1[draw_i].get_cy()*64)+144,"ghora12.bmp");
			else iShowBMP((ghora1[draw_i].get_cx()*64)+144,(ghora1[draw_i].get_cy()*64)+144,"ghora11.bmp");

		}
		else
		{
			if(ghora1[draw_i].get_cy()%2==0)
				iShowBMP((ghora1[draw_i].get_cx()*64)+144,(ghora1[draw_i].get_cy()*64)+144,"ghora11.bmp");
			else iShowBMP((ghora1[draw_i].get_cx()*64)+144,(ghora1[draw_i].get_cy()*64)+144,"ghora12.bmp");
		}

	}
		
	}//end of draw_i loop
	
	
	
	
	
	
	
	//player 1 nouka

	for(draw_i=0;draw_i<2;draw_i++)
	{
		if(nouka1[draw_i].get_ax()<144 || nouka1[draw_i].get_ax()>144+512 || nouka1[draw_i].get_ay()<144 || nouka1[draw_i].get_ay()>144+512)
	{
			if(nouka1[draw_i].get_ax()<144 || nouka1[draw_i].get_ax()>144+512 || nouka1[draw_i].get_ay()<144 || nouka1[draw_i].get_ay()>144+512)
			{
				if(nouka1[draw_i].get_dead()==0)
					iShowBMP(nouka1[draw_i].get_dx(),nouka1[draw_i].get_dy(),"nouka12.bmp");	
			}

	
	}

	else	
	{

		
		if(nouka1[draw_i].get_cx()%2==0)
		{
			if(nouka1[draw_i].get_cy()%2==0)
				iShowBMP((nouka1[draw_i].get_cx()*64)+144,(nouka1[draw_i].get_cy()*64)+144,"nouka12.bmp");
			else iShowBMP((nouka1[draw_i].get_cx()*64)+144,(nouka1[draw_i].get_cy()*64)+144,"nouka11.bmp");

		}
		else
		{
			if(nouka1[draw_i].get_cy()%2==0)
				iShowBMP((nouka1[draw_i].get_cx()*64)+144,(nouka1[draw_i].get_cy()*64)+144,"nouka11.bmp");
			else iShowBMP((nouka1[draw_i].get_cx()*64)+144,(nouka1[draw_i].get_cy()*64)+144,"nouka12.bmp");
		}
		
	}
	}//end of draw_i loop
	
	
	
	
	//player 1 hati

	for(draw_i=0;draw_i<2;draw_i++)
	{
		if(hati1[draw_i].get_ax()<144 || hati1[draw_i].get_ax()>144+512 || hati1[draw_i].get_ay()<144 || hati1[draw_i].get_ay()>144+512)
	{
			if(hati1[draw_i].get_ax()<144 || hati1[draw_i].get_ax()>144+512 || hati1[draw_i].get_ay()<144 || hati1[draw_i].get_ay()>144+512)
			{
				if(hati1[draw_i].get_dead()==0)
					iShowBMP(hati1[draw_i].get_dx(),hati1[draw_i].get_dy(),"hati12.bmp");	
			}

	
	}

	else	
	{

		
		if(hati1[draw_i].get_cx()%2==0)
		{
			if(hati1[draw_i].get_cy()%2==0)
				iShowBMP((hati1[draw_i].get_cx()*64)+144,(hati1[draw_i].get_cy()*64)+144,"hati12.bmp");
			else iShowBMP((hati1[draw_i].get_cx()*64)+144,(hati1[draw_i].get_cy()*64)+144,"hati11.bmp");

		}
		else
		{
			if(hati1[draw_i].get_cy()%2==0)
				iShowBMP((hati1[draw_i].get_cx()*64)+144,(hati1[draw_i].get_cy()*64)+144,"hati11.bmp");
			else iShowBMP((hati1[draw_i].get_cx()*64)+144,(hati1[draw_i].get_cy()*64)+144,"hati12.bmp");
		}
	}
		
	}//end of draw_i loop


//player 1 solder

	for(draw_i=0;draw_i<8;draw_i++)
	{
		if(solder1[draw_i].get_ax()<144 || solder1[draw_i].get_ax()>144+512 || solder1[draw_i].get_ay()<144 || solder1[draw_i].get_ay()>144+512)
	{
			if(solder1[draw_i].get_ax()<144 || solder1[draw_i].get_ax()>144+512 || solder1[draw_i].get_ay()<144 || solder1[draw_i].get_ay()>144+512)
			{
				if(solder1[draw_i].get_dead()==0)
					iShowBMP(solder1[draw_i].get_dx(),solder1[draw_i].get_dy(),"solder12.bmp");	
			}

	
	}

	else	
	{

		
		if(solder1[draw_i].get_cx()%2==0)
		{
			if(solder1[draw_i].get_cy()%2==0)
				iShowBMP((solder1[draw_i].get_cx()*64)+144,(solder1[draw_i].get_cy()*64)+144,"solder12.bmp");
			else iShowBMP((solder1[draw_i].get_cx()*64)+144,(solder1[draw_i].get_cy()*64)+144,"solder11.bmp");

		}
		else
		{
			if(solder1[draw_i].get_cy()%2==0)
				iShowBMP((solder1[draw_i].get_cx()*64)+144,(solder1[draw_i].get_cy()*64)+144,"solder11.bmp");
			else iShowBMP((solder1[draw_i].get_cx()*64)+144,(solder1[draw_i].get_cy()*64)+144,"solder12.bmp");
		}

	}
		
	}//end of draw_i loop

	
/********************************   player  2   *********************************************/

	
	//player 2 raza

		if(raza2.get_ax()<144 || raza2.get_ax()>144+512 || raza2.get_ay()<144 || raza2.get_ay()>144+512)
	{
		if(raza2.get_dead()==0)
			iShowBMP(raza2.get_dx(),raza2.get_dy(),"raza22.bmp");	
	}

	else	
	{
		if(raza2.get_cx()%2==0)
		{
			if(raza2.get_cy()%2==0)
				iShowBMP((raza2.get_cx()*64)+144,(raza2.get_cy()*64)+144,"raza22.bmp");
			else iShowBMP((raza2.get_cx()*64)+144,(raza2.get_cy()*64)+144,"raza21.bmp");

		}
		else
		{
			if(raza2.get_cy()%2==0)
				iShowBMP((raza2.get_cx()*64)+144,(raza2.get_cy()*64)+144,"raza21.bmp");
			else iShowBMP((raza2.get_cx()*64)+144,(raza2.get_cy()*64)+144,"raza22.bmp");
		}
		
	}






	//player 2 montri



		if(montri2.get_ax()<144 || montri2.get_ax()>144+512 || montri2.get_ay()<144 || montri2.get_ay()>144+512)
	{
		if(montri2.get_dead()==0)
			iShowBMP(montri2.get_dx(),montri2.get_dy(),"montri22.bmp");	
	}

	else	
	{
		if(montri2.get_cx()%2==0)
		{
			if(montri2.get_cy()%2==0)
				iShowBMP((montri2.get_cx()*64)+144,(montri2.get_cy()*64)+144,"montri22.bmp");
			else iShowBMP((montri2.get_cx()*64)+144,(montri2.get_cy()*64)+144,"montri21.bmp");

		}
		else
		{
			if(montri2.get_cy()%2==0)
				iShowBMP((montri2.get_cx()*64)+144,(montri2.get_cy()*64)+144,"montri21.bmp");
			else iShowBMP((montri2.get_cx()*64)+144,(montri2.get_cy()*64)+144,"montri22.bmp");
		}
		
	
	}
	
	
	
	//player 2 ghora

	for(draw_i=0;draw_i<2;draw_i++)
	{
		if(ghora2[draw_i].get_ax()<144 || ghora2[draw_i].get_ax()>144+512 || ghora2[draw_i].get_ay()<144 || ghora2[draw_i].get_ay()>144+512)
	{
			if(ghora2[draw_i].get_ax()<144 || ghora2[draw_i].get_ax()>144+512 || ghora2[draw_i].get_ay()<144 || ghora2[draw_i].get_ay()>144+512)
			{
				if(ghora2[draw_i].get_dead()==0)
					iShowBMP(ghora2[draw_i].get_dx(),ghora2[draw_i].get_dy(),"ghora22.bmp");	
			}

	
	}

	else	
	{

		
		if(ghora2[draw_i].get_cx()%2==0)
		{
			if(ghora2[draw_i].get_cy()%2==0)
				iShowBMP((ghora2[draw_i].get_cx()*64)+144,(ghora2[draw_i].get_cy()*64)+144,"ghora22.bmp");
			else iShowBMP((ghora2[draw_i].get_cx()*64)+144,(ghora2[draw_i].get_cy()*64)+144,"ghora21.bmp");

		}
		else
		{
			if(ghora2[draw_i].get_cy()%2==0)
				iShowBMP((ghora2[draw_i].get_cx()*64)+144,(ghora2[draw_i].get_cy()*64)+144,"ghora21.bmp");
			else iShowBMP((ghora2[draw_i].get_cx()*64)+144,(ghora2[draw_i].get_cy()*64)+144,"ghora22.bmp");
		}
		
	}
	}//end of draw_i loop
	
	
	
	
	
	
	//player 2 nouka

	for(draw_i=0;draw_i<2;draw_i++)
	{
		if(nouka2[draw_i].get_ax()<144 || nouka2[draw_i].get_ax()>144+512 || nouka2[draw_i].get_ay()<144 || nouka2[draw_i].get_ay()>144+512)
	{
			if(nouka2[draw_i].get_ax()<144 || nouka2[draw_i].get_ax()>144+512 || nouka2[draw_i].get_ay()<144 || nouka2[draw_i].get_ay()>144+512)
			{
				if(nouka2[draw_i].get_dead()==0)
					iShowBMP(nouka2[draw_i].get_dx(),nouka2[draw_i].get_dy(),"nouka22.bmp");	
			}

	
	}

	else	
	{

		
		if(nouka2[draw_i].get_cx()%2==0)
		{
			if(nouka2[draw_i].get_cy()%2==0)
				iShowBMP((nouka2[draw_i].get_cx()*64)+144,(nouka2[draw_i].get_cy()*64)+144,"nouka22.bmp");
			else iShowBMP((nouka2[draw_i].get_cx()*64)+144,(nouka2[draw_i].get_cy()*64)+144,"nouka21.bmp");

		}
		else
		{
			if(nouka2[draw_i].get_cy()%2==0)
				iShowBMP((nouka2[draw_i].get_cx()*64)+144,(nouka2[draw_i].get_cy()*64)+144,"nouka21.bmp");
			else iShowBMP((nouka2[draw_i].get_cx()*64)+144,(nouka2[draw_i].get_cy()*64)+144,"nouka22.bmp");
		}
		
	}
	}//end of draw_i loop
	
	
	
	
	//player 2 hati

	for(draw_i=0;draw_i<2;draw_i++)
	{
		if(hati2[draw_i].get_ax()<144 || hati2[draw_i].get_ax()>144+512 || hati2[draw_i].get_ay()<144 || hati2[draw_i].get_ay()>144+512)
	{
			if(hati2[draw_i].get_ax()<144 || hati2[draw_i].get_ax()>144+512 || hati2[draw_i].get_ay()<144 || hati2[draw_i].get_ay()>144+512)
			{
				if(hati2[draw_i].get_dead()==0)
					iShowBMP(hati2[draw_i].get_dx(),hati2[draw_i].get_dy(),"hati22.bmp");	
			}

	
	}

	else	
	{

		
		if(hati2[draw_i].get_cx()%2==0)
		{
			if(hati2[draw_i].get_cy()%2==0)
				iShowBMP((hati2[draw_i].get_cx()*64)+144,(hati2[draw_i].get_cy()*64)+144,"hati22.bmp");
			else iShowBMP((hati2[draw_i].get_cx()*64)+144,(hati2[draw_i].get_cy()*64)+144,"hati21.bmp");

		}
		else
		{
			if(hati2[draw_i].get_cy()%2==0)
				iShowBMP((hati2[draw_i].get_cx()*64)+144,(hati2[draw_i].get_cy()*64)+144,"hati21.bmp");
			else iShowBMP((hati2[draw_i].get_cx()*64)+144,(hati2[draw_i].get_cy()*64)+144,"hati22.bmp");
		}

	}
		
	}//end of draw_i loop
	
	
	
	//player 2 solder

	for(draw_i=0;draw_i<8;draw_i++)
	{
		if(solder2[draw_i].get_ax()<144 || solder2[draw_i].get_ax()>144+512 || solder2[draw_i].get_ay()<144 || solder2[draw_i].get_ay()>144+512)
	{
			if(solder2[draw_i].get_ax()<144 || solder2[draw_i].get_ax()>144+512 || solder2[draw_i].get_ay()<144 || solder2[draw_i].get_ay()>144+512)
			{
				if(solder2[draw_i].get_dead()==0)
					iShowBMP(solder2[draw_i].get_dx(),solder2[draw_i].get_dy(),"solder22.bmp");	
			}

	
	}

	else	
	{

		
		if(solder2[draw_i].get_cx()%2==0)
		{
			if(solder2[draw_i].get_cy()%2==0)
				iShowBMP((solder2[draw_i].get_cx()*64)+144,(solder2[draw_i].get_cy()*64)+144,"solder22.bmp");
			else iShowBMP((solder2[draw_i].get_cx()*64)+144,(solder2[draw_i].get_cy()*64)+144,"solder21.bmp");

		}
		else
		{
			if(solder2[draw_i].get_cy()%2==0)
				iShowBMP((solder2[draw_i].get_cx()*64)+144,(solder2[draw_i].get_cy()*64)+144,"solder21.bmp");
			else iShowBMP((solder2[draw_i].get_cx()*64)+144,(solder2[draw_i].get_cy()*64)+144,"solder22.bmp");
		}
		
	}
	}//end of draw_i loop
	}//end of priority condition

	if(player==1)
	{

/********************************   player  2   *********************************************/

	
	//player 2 raza

		if(raza2.get_ax()<144 || raza2.get_ax()>144+512 || raza2.get_ay()<144 || raza2.get_ay()>144+512)
	{
		if(raza2.get_dead()==0)
			iShowBMP(raza2.get_dx(),raza2.get_dy(),"raza22.bmp");	
	}

	else	
	{
		if(raza2.get_cx()%2==0)
		{
			if(raza2.get_cy()%2==0)
				iShowBMP((raza2.get_cx()*64)+144,(raza2.get_cy()*64)+144,"raza22.bmp");
			else iShowBMP((raza2.get_cx()*64)+144,(raza2.get_cy()*64)+144,"raza21.bmp");

		}
		else
		{
			if(raza2.get_cy()%2==0)
				iShowBMP((raza2.get_cx()*64)+144,(raza2.get_cy()*64)+144,"raza21.bmp");
			else iShowBMP((raza2.get_cx()*64)+144,(raza2.get_cy()*64)+144,"raza22.bmp");
		}
		
	}






	//player 2 montri



		if(montri2.get_ax()<144 || montri2.get_ax()>144+512 || montri2.get_ay()<144 || montri2.get_ay()>144+512)
	{
		if(montri2.get_dead()==0)
			iShowBMP(montri2.get_dx(),montri2.get_dy(),"montri22.bmp");	
	}

	else	
	{
		if(montri2.get_cx()%2==0)
		{
			if(montri2.get_cy()%2==0)
				iShowBMP((montri2.get_cx()*64)+144,(montri2.get_cy()*64)+144,"montri22.bmp");
			else iShowBMP((montri2.get_cx()*64)+144,(montri2.get_cy()*64)+144,"montri21.bmp");

		}
		else
		{
			if(montri2.get_cy()%2==0)
				iShowBMP((montri2.get_cx()*64)+144,(montri2.get_cy()*64)+144,"montri21.bmp");
			else iShowBMP((montri2.get_cx()*64)+144,(montri2.get_cy()*64)+144,"montri22.bmp");
		}
		
	
	}
	
	
	
	//player 2 ghora

	for(draw_i=0;draw_i<2;draw_i++)
	{
		if(ghora2[draw_i].get_ax()<144 || ghora2[draw_i].get_ax()>144+512 || ghora2[draw_i].get_ay()<144 || ghora2[draw_i].get_ay()>144+512)
	{
			if(ghora2[draw_i].get_ax()<144 || ghora2[draw_i].get_ax()>144+512 || ghora2[draw_i].get_ay()<144 || ghora2[draw_i].get_ay()>144+512)
			{
				if(ghora2[draw_i].get_dead()==0)
					iShowBMP(ghora2[draw_i].get_dx(),ghora2[draw_i].get_dy(),"ghora22.bmp");	
			}

	
	}

	else	
	{

		
		if(ghora2[draw_i].get_cx()%2==0)
		{
			if(ghora2[draw_i].get_cy()%2==0)
				iShowBMP((ghora2[draw_i].get_cx()*64)+144,(ghora2[draw_i].get_cy()*64)+144,"ghora22.bmp");
			else iShowBMP((ghora2[draw_i].get_cx()*64)+144,(ghora2[draw_i].get_cy()*64)+144,"ghora21.bmp");

		}
		else
		{
			if(ghora2[draw_i].get_cy()%2==0)
				iShowBMP((ghora2[draw_i].get_cx()*64)+144,(ghora2[draw_i].get_cy()*64)+144,"ghora21.bmp");
			else iShowBMP((ghora2[draw_i].get_cx()*64)+144,(ghora2[draw_i].get_cy()*64)+144,"ghora22.bmp");
		}
		
	}
	}//end of draw_i loop
	
	
	
	
	
	
	//player 2 nouka

	for(draw_i=0;draw_i<2;draw_i++)
	{
		if(nouka2[draw_i].get_ax()<144 || nouka2[draw_i].get_ax()>144+512 || nouka2[draw_i].get_ay()<144 || nouka2[draw_i].get_ay()>144+512)
	{
			if(nouka2[draw_i].get_ax()<144 || nouka2[draw_i].get_ax()>144+512 || nouka2[draw_i].get_ay()<144 || nouka2[draw_i].get_ay()>144+512)
			{
				if(nouka2[draw_i].get_dead()==0)
					iShowBMP(nouka2[draw_i].get_dx(),nouka2[draw_i].get_dy(),"nouka22.bmp");	
			}

	
	}

	else	
	{

		
		if(nouka2[draw_i].get_cx()%2==0)
		{
			if(nouka2[draw_i].get_cy()%2==0)
				iShowBMP((nouka2[draw_i].get_cx()*64)+144,(nouka2[draw_i].get_cy()*64)+144,"nouka22.bmp");
			else iShowBMP((nouka2[draw_i].get_cx()*64)+144,(nouka2[draw_i].get_cy()*64)+144,"nouka21.bmp");

		}
		else
		{
			if(nouka2[draw_i].get_cy()%2==0)
				iShowBMP((nouka2[draw_i].get_cx()*64)+144,(nouka2[draw_i].get_cy()*64)+144,"nouka21.bmp");
			else iShowBMP((nouka2[draw_i].get_cx()*64)+144,(nouka2[draw_i].get_cy()*64)+144,"nouka22.bmp");
		}
		
	}
	}//end of draw_i loop
	
	
	
	
	//player 2 hati

	for(draw_i=0;draw_i<2;draw_i++)
	{
		if(hati2[draw_i].get_ax()<144 || hati2[draw_i].get_ax()>144+512 || hati2[draw_i].get_ay()<144 || hati2[draw_i].get_ay()>144+512)
	{
			if(hati2[draw_i].get_ax()<144 || hati2[draw_i].get_ax()>144+512 || hati2[draw_i].get_ay()<144 || hati2[draw_i].get_ay()>144+512)
			{
				if(hati2[draw_i].get_dead()==0)
					iShowBMP(hati2[draw_i].get_dx(),hati2[draw_i].get_dy(),"hati22.bmp");	
			}

	
	}

	else	
	{

		
		if(hati2[draw_i].get_cx()%2==0)
		{
			if(hati2[draw_i].get_cy()%2==0)
				iShowBMP((hati2[draw_i].get_cx()*64)+144,(hati2[draw_i].get_cy()*64)+144,"hati22.bmp");
			else iShowBMP((hati2[draw_i].get_cx()*64)+144,(hati2[draw_i].get_cy()*64)+144,"hati21.bmp");

		}
		else
		{
			if(hati2[draw_i].get_cy()%2==0)
				iShowBMP((hati2[draw_i].get_cx()*64)+144,(hati2[draw_i].get_cy()*64)+144,"hati21.bmp");
			else iShowBMP((hati2[draw_i].get_cx()*64)+144,(hati2[draw_i].get_cy()*64)+144,"hati22.bmp");
		}

	}
		
	}//end of draw_i loop
	
	
	
	//player 2 solder

	for(draw_i=0;draw_i<8;draw_i++)
	{
		if(solder2[draw_i].get_ax()<144 || solder2[draw_i].get_ax()>144+512 || solder2[draw_i].get_ay()<144 || solder2[draw_i].get_ay()>144+512)
	{
			if(solder2[draw_i].get_ax()<144 || solder2[draw_i].get_ax()>144+512 || solder2[draw_i].get_ay()<144 || solder2[draw_i].get_ay()>144+512)
			{
				if(solder2[draw_i].get_dead()==0)
					iShowBMP(solder2[draw_i].get_dx(),solder2[draw_i].get_dy(),"solder22.bmp");	
			}

	
	}

	else	
	{

		
		if(solder2[draw_i].get_cx()%2==0)
		{
			if(solder2[draw_i].get_cy()%2==0)
				iShowBMP((solder2[draw_i].get_cx()*64)+144,(solder2[draw_i].get_cy()*64)+144,"solder22.bmp");
			else iShowBMP((solder2[draw_i].get_cx()*64)+144,(solder2[draw_i].get_cy()*64)+144,"solder21.bmp");

		}
		else
		{
			if(solder2[draw_i].get_cy()%2==0)
				iShowBMP((solder2[draw_i].get_cx()*64)+144,(solder2[draw_i].get_cy()*64)+144,"solder21.bmp");
			else iShowBMP((solder2[draw_i].get_cx()*64)+144,(solder2[draw_i].get_cy()*64)+144,"solder22.bmp");
		}
		
	}
	}//end of draw_i loop



/********************         end of player 2              ***********************************  **/
	if(raza1.get_ax()<144 || raza1.get_ax()>144+512 || raza1.get_ay()<144 || raza1.get_ay()>144+512)
	{
		if(raza1.get_dead()==0)
			iShowBMP(raza1.get_dx(),raza1.get_dy(),"raza12.bmp");	
	}

	else	
	{
		if(raza1.get_cx()%2==0)
		{
			if(raza1.get_cy()%2==0)
				iShowBMP((raza1.get_cx()*64)+144,(raza1.get_cy()*64)+144,"raza12.bmp");
			else iShowBMP((raza1.get_cx()*64)+144,(raza1.get_cy()*64)+144,"raza11.bmp");

		}
		else
		{
			if(raza1.get_cy()%2==0)
				iShowBMP((raza1.get_cx()*64)+144,(raza1.get_cy()*64)+144,"raza11.bmp");
			else iShowBMP((raza1.get_cx()*64)+144,(raza1.get_cy()*64)+144,"raza12.bmp");
		}
	}
	






	//player 1 montri

	if(montri1.get_ax()<144 || montri1.get_ax()>144+512 || montri1.get_ay()<144 || montri1.get_ay()>144+512)
	{
			if(montri1.get_ax()<144 || montri1.get_ax()>144+512 || montri1.get_ay()<144 || montri1.get_ay()>144+512)
			{
				if(montri1.get_dead()==0)
					iShowBMP(montri1.get_dx(),montri1.get_dy(),"montri12.bmp");	
			}

	
	}

	else	
	{


		if(montri1.get_cx()%2==0)
		{
			if(montri1.get_cy()%2==0)
				iShowBMP((montri1.get_cx()*64)+144,(montri1.get_cy()*64)+144,"montri12.bmp");
			else iShowBMP((montri1.get_cx()*64)+144,(montri1.get_cy()*64)+144,"montri11.bmp");

		}
		else
		{
			if(montri1.get_cy()%2==0)
				iShowBMP((montri1.get_cx()*64)+144,(montri1.get_cy()*64)+144,"montri11.bmp");
			else iShowBMP((montri1.get_cx()*64)+144,(montri1.get_cy()*64)+144,"montri12.bmp");
		}

	}
		
	
	
	
	
	
	//player 1 ghora

	for(draw_i=0;draw_i<2;draw_i++)
	{
		if(ghora1[draw_i].get_ax()<144 || ghora1[draw_i].get_ax()>144+512 || ghora1[draw_i].get_ay()<144 || ghora1[draw_i].get_ay()>144+512)
	{
			if(ghora1[draw_i].get_ax()<144 || ghora1[draw_i].get_ax()>144+512 || ghora1[draw_i].get_ay()<144 || ghora1[draw_i].get_ay()>144+512)
			{
				if(ghora1[draw_i].get_dead()==0)
					iShowBMP(ghora1[draw_i].get_dx(),ghora1[draw_i].get_dy(),"ghora12.bmp");	
			}

	
	}

	else	
	{

		if(ghora1[draw_i].get_cx()%2==0)
		{
			if(ghora1[draw_i].get_cy()%2==0)
				iShowBMP((ghora1[draw_i].get_cx()*64)+144,(ghora1[draw_i].get_cy()*64)+144,"ghora12.bmp");
			else iShowBMP((ghora1[draw_i].get_cx()*64)+144,(ghora1[draw_i].get_cy()*64)+144,"ghora11.bmp");

		}
		else
		{
			if(ghora1[draw_i].get_cy()%2==0)
				iShowBMP((ghora1[draw_i].get_cx()*64)+144,(ghora1[draw_i].get_cy()*64)+144,"ghora11.bmp");
			else iShowBMP((ghora1[draw_i].get_cx()*64)+144,(ghora1[draw_i].get_cy()*64)+144,"ghora12.bmp");
		}

	}
		
	}//end of draw_i loop
	
	
	
	
	
	
	
	//player 1 nouka

	for(draw_i=0;draw_i<2;draw_i++)
	{
		if(nouka1[draw_i].get_ax()<144 || nouka1[draw_i].get_ax()>144+512 || nouka1[draw_i].get_ay()<144 || nouka1[draw_i].get_ay()>144+512)
	{
			if(nouka1[draw_i].get_ax()<144 || nouka1[draw_i].get_ax()>144+512 || nouka1[draw_i].get_ay()<144 || nouka1[draw_i].get_ay()>144+512)
			{
				if(nouka1[draw_i].get_dead()==0)
					iShowBMP(nouka1[draw_i].get_dx(),nouka1[draw_i].get_dy(),"nouka12.bmp");	
			}

	
	}

	else	
	{

		
		if(nouka1[draw_i].get_cx()%2==0)
		{
			if(nouka1[draw_i].get_cy()%2==0)
				iShowBMP((nouka1[draw_i].get_cx()*64)+144,(nouka1[draw_i].get_cy()*64)+144,"nouka12.bmp");
			else iShowBMP((nouka1[draw_i].get_cx()*64)+144,(nouka1[draw_i].get_cy()*64)+144,"nouka11.bmp");

		}
		else
		{
			if(nouka1[draw_i].get_cy()%2==0)
				iShowBMP((nouka1[draw_i].get_cx()*64)+144,(nouka1[draw_i].get_cy()*64)+144,"nouka11.bmp");
			else iShowBMP((nouka1[draw_i].get_cx()*64)+144,(nouka1[draw_i].get_cy()*64)+144,"nouka12.bmp");
		}
		
	}
	}//end of draw_i loop
	
	
	
	
	//player 1 hati

	for(draw_i=0;draw_i<2;draw_i++)
	{
		if(hati1[draw_i].get_ax()<144 || hati1[draw_i].get_ax()>144+512 || hati1[draw_i].get_ay()<144 || hati1[draw_i].get_ay()>144+512)
	{
			if(hati1[draw_i].get_ax()<144 || hati1[draw_i].get_ax()>144+512 || hati1[draw_i].get_ay()<144 || hati1[draw_i].get_ay()>144+512)
			{
				if(hati1[draw_i].get_dead()==0)
					iShowBMP(hati1[draw_i].get_dx(),hati1[draw_i].get_dy(),"hati12.bmp");	
			}

	
	}

	else	
	{

		
		if(hati1[draw_i].get_cx()%2==0)
		{
			if(hati1[draw_i].get_cy()%2==0)
				iShowBMP((hati1[draw_i].get_cx()*64)+144,(hati1[draw_i].get_cy()*64)+144,"hati12.bmp");
			else iShowBMP((hati1[draw_i].get_cx()*64)+144,(hati1[draw_i].get_cy()*64)+144,"hati11.bmp");

		}
		else
		{
			if(hati1[draw_i].get_cy()%2==0)
				iShowBMP((hati1[draw_i].get_cx()*64)+144,(hati1[draw_i].get_cy()*64)+144,"hati11.bmp");
			else iShowBMP((hati1[draw_i].get_cx()*64)+144,(hati1[draw_i].get_cy()*64)+144,"hati12.bmp");
		}
	}
		
	}//end of draw_i loop


//player 1 solder

	for(draw_i=0;draw_i<8;draw_i++)
	{
		if(solder1[draw_i].get_ax()<144 || solder1[draw_i].get_ax()>144+512 || solder1[draw_i].get_ay()<144 || solder1[draw_i].get_ay()>144+512)
	{
			if(solder1[draw_i].get_ax()<144 || solder1[draw_i].get_ax()>144+512 || solder1[draw_i].get_ay()<144 || solder1[draw_i].get_ay()>144+512)
			{
				if(solder1[draw_i].get_dead()==0)
					iShowBMP(solder1[draw_i].get_dx(),solder1[draw_i].get_dy(),"solder12.bmp");	
			}

	
	}

	else	
	{

		
		if(solder1[draw_i].get_cx()%2==0)
		{
			if(solder1[draw_i].get_cy()%2==0)
				iShowBMP((solder1[draw_i].get_cx()*64)+144,(solder1[draw_i].get_cy()*64)+144,"solder12.bmp");
			else iShowBMP((solder1[draw_i].get_cx()*64)+144,(solder1[draw_i].get_cy()*64)+144,"solder11.bmp");

		}
		else
		{
			if(solder1[draw_i].get_cy()%2==0)
				iShowBMP((solder1[draw_i].get_cx()*64)+144,(solder1[draw_i].get_cy()*64)+144,"solder11.bmp");
			else iShowBMP((solder1[draw_i].get_cx()*64)+144,(solder1[draw_i].get_cy()*64)+144,"solder12.bmp");
		}

	}
		
	}//end of draw_i loop

	


	
}//end of priority condition

	if(pg2_but==0)
	iShowBMP(0,800-32,"menu1.bmp");
	if(pg2_but==1)
	{
		iShowBMP(0,800-32,"menu2.bmp");
		iShowBMP(0,800-32-64,"menu3.bmp");

	}
	
	iSetcolor(0,100,0);
	if(mouse%2==1)
			iText((800/2)-70,144-40,"Mouse locked",GLUT_BITMAP_TIMES_ROMAN_24);
	if(winner!=0)
	{
		iSetcolor(100,0,0);
		if(winner==1)
			iText((800/2)-80,(800/2),"Player 1 Wins",GLUT_BITMAP_TIMES_ROMAN_24);
		if(winner==2)
			iText((800/2)-80,(800/2),"Player 2 Wins",GLUT_BITMAP_TIMES_ROMAN_24);
	}

	iSetcolor(0,0,100);
	if(player==2)
		iText((800/2)-73,800-144+75,"Player 2's Turn",GLUT_BITMAP_TIMES_ROMAN_24);
	if(player==1)
		iText((800/2)-73,100,"Player 1's Turn",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetcolor(100,0,0);
	if(kcheck==1 && player==1)
		iText((800/2)-47,80,"CHECK",GLUT_BITMAP_TIMES_ROMAN_24);
	if(kcheck==1 && player==2)
		iText((800/2)-47,800-100,"CHECK",GLUT_BITMAP_TIMES_ROMAN_24);

	
}/*end of page 2 condition*/

if(pg==3)
{
	if(pg2_but==0)
	iShowBMP(0,800-32,"menu1.bmp");
	if(pg2_but==1)
	{
		iShowBMP(0,800-32,"menu2.bmp");
		iShowBMP(0,800-32-64,"menu3.bmp");

	}
	iShowBMP(144,144,"sound1.bmp");
}



if(pg==4)
{
	if(pg2_but==0)
	iShowBMP(0,800-32,"menu1.bmp");
	if(pg2_but==1)
	{
		iShowBMP(0,800-32,"menu2.bmp");
		iShowBMP(0,800-32-64,"menu3.bmp");

	}
	iShowBMP(144,144,"help1.bmp");
}

if(pg==5)
{
	if(pg2_but==0)
	iShowBMP(0,800-32,"menu1.bmp");
	if(pg2_but==1)
	{
		iShowBMP(0,800-32,"menu2.bmp");
		iShowBMP(0,800-32-64,"menu3.bmp");

	}
	iShowBMP(144,144,"about1.bmp");
}


if(pg==6)
{
	if(pg2_but==0)
	iShowBMP(0,800-32,"menu1.bmp");
	if(pg2_but==1)
	{
		iShowBMP(0,800-32,"menu2.bmp");
		iShowBMP(0,800-32-64,"menu3.bmp");

	}
	iShowBMP(144,144,"credits1.bmp");

}


if(pg==7)
{
	iShowBMP(144,144,"contact1.bmp");
	if(pg2_but==0)
	iShowBMP(0,800-32,"menu1.bmp");
	if(pg2_but==1)
	{
		iShowBMP(0,800-32,"menu2.bmp");
		iShowBMP(0,800-32-64,"menu3.bmp");

	}
}







	
}/*end of idraw*/




	 
	 
	 
	 
	 
	 
	 
	 /*
Function iMouseMove() is called when the user presses and drags
the mouse.(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
//place your codes here

move_x=(mx-144)/64;
move_y=(my-144)/64;
	
	

	

if(pg==2)
{






///***************         player 1 move                        /*****************************/ 

	
	//raza 
		if(move/10==11)
{
	
	raza1.set_cx(move_x);
	raza1.set_cy(move_y);
	raza1.set_ax(mx);
	raza1.set_ay(my);
}
	
//montri 
		if(move/10==12)
{
	
	montri1.set_cx(move_x);
	montri1.set_cy(move_y);
	montri1.set_ax(mx);
	montri1.set_ay(my);


}		

		//ghora
	if(move/10==13)
{
	
	ghora1[move%10].set_cx(move_x);
	ghora1[move%10].set_cy(move_y);
	ghora1[move%10].set_ax(mx);
	ghora1[move%10].set_ay(my);
}
		
		//nouka
	if(move/10==14)
{
	
	nouka1[move%10].set_cx(move_x);
	nouka1[move%10].set_cy(move_y);
	nouka1[move%10].set_ax(mx);
	nouka1[move%10].set_ay(my);
}
	
			//hati
	if(move/10==15)
{
	
	hati1[move%10].set_cx(move_x);
	hati1[move%10].set_cy(move_y);
	hati1[move%10].set_ax(mx);
	hati1[move%10].set_ay(my);
}	
	
	
	//solder 
	if(move/10==16)
{
	
	solder1[move%10].set_cx(move_x);
	solder1[move%10].set_cy(move_y);
	solder1[move%10].set_ax(mx);
	solder1[move%10].set_ay(my);
}

///***************         player 2 move                        /*****************************/ 

	
	//raza 
		if(move/10==21)
{
	
	raza2.set_cx(move_x);
	raza2.set_cy(move_y);
	raza2.set_ax(mx);
	raza2.set_ay(my);
}
	
//montri 
		if(move/10==22)
{
	
	montri2.set_cx(move_x);
	montri2.set_cy(move_y);
	montri2.set_ax(mx);
	montri2.set_ay(my);
}		

		//ghora
	if(move/10==23)
{
	
	ghora2[move%10].set_cx(move_x);
	ghora2[move%10].set_cy(move_y);
	ghora2[move%10].set_ax(mx);
	ghora2[move%10].set_ay(my);
}
		
		//nouka
	if(move/10==24)
{
	
	nouka2[move%10].set_cx(move_x);
	nouka2[move%10].set_cy(move_y);
	nouka2[move%10].set_ax(mx);
	nouka2[move%10].set_ay(my);
}
	
			//hati
	if(move/10==25)
{
	
	hati2[move%10].set_cx(move_x);
	hati2[move%10].set_cy(move_y);
	hati2[move%10].set_ax(mx);
	hati2[move%10].set_ay(my);
}	
	
	
	//solder 
	if(move/10==26)
{
	
	solder2[move%10].set_cx(move_x);
	solder2[move%10].set_cy(move_y);
	solder2[move%10].set_ax(mx);
	solder2[move%10].set_ay(my);
}



	
}//page 2 condition

//}//ending player 1 move condition

/*************************************   end of player 1 move*************************/






	


}//end of iMouseMove








/*
Function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{


move_x=(mx-144)/64;
move_y=(my-144)/64;

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
//place your codes here
//printf("%d %d\t",mx,my);	


	/****************************************************************************************/
	/*******   start<<<<        animation of page=1 button            *******************************/



	/*****************  start<<    start button                    ****************************/



	
if(pg==1 && mx>=start_x && mx<=(start_x+128) && my>=start_y && my<=(start_y+64))

{
	start_y=start_y-5;
	pg1_but=1;


}



/*****************  start<<    sound button                    ****************************/




if(pg==1 && mx>=sound_x && mx<=(sound_x+128) && my>=sound_y && my<=(sound_y+64))

{
	sound_y=sound_y-5;
	pg1_but=2;


}








/*****************  start<<    help button                    ****************************/




if(pg==1 && mx>=help_x && mx<=(help_x+128) && my>=help_y && my<=(help_y+64))

{
	help_y=help_y-5;
	pg1_but=3;


}

/***************            about button              *************************************/




if(pg==1 && mx>=abt_x && mx<=(abt_x+128) && my>=abt_y && my<=(abt_y+64))

{
	abt_y=abt_y-5;
	pg1_but=4;


}



/******************            credits button            *******************************/

if(pg==1 && mx>=cre_x && mx<=(cre_x+128) && my>=cre_y && my<=(cre_y+64))

{
	cre_y=cre_y-5;
	pg1_but=5;


}





/******************            contact button            *******************************/

if(pg==1 && mx>=con_x && mx<=(con_x+128) && my>=con_y && my<=(con_y+64))

{
	con_y=con_y-5;
	pg1_but=6;


}








/*****************  start<<    exit button                    ****************************/


if(pg==1 && mx>=exit_x && mx<=(exit_x+128) && my>=exit_y && my<=(exit_y+64))

{
	exit_y=exit_y-5;
	pg1_but=7;


}


	/*******       end<<<<    animation of page=1 button            *******************************/
	/****************************************************************************************/





/*************         page 2 moves            ******************************************/


/*************       menu conditions             ********************************/



if(pg>=2&&pg<=8)
{
	if(mx>=0&&mx<=128&&my>=800-32&&my<=800&&pg2_but==0)
	{
		pg2_but=1;
	}
	if(mx>=0&&mx<=256&&my>=800-64&&my<=800-32&&pg2_but==1)
	{
		pg2_but=0;
		pg=1;

	}
	else 
	{
		if(mx>=0&&mx<=256&&my>=800-96&&my<=800-64&&pg2_but==1)
		{
			pg2_but=0;
			printf("\n\n\n\n\t\t\t\tThanks For Playing\n\n\n\n\n");
			exit(0);
		}
		else if((mx>=0&&mx<=800&&my>=0&&my<=800-96)||(mx>=256&&mx<=800&&my>=0&&my<=800)||(mx>=128&&mx<=800))
		{
			pg2_but=0;
			
		}
	}
	
}//end of menu condition







/*************************  player 1 moves      **************************************/

move_x=(mx-144)/64;
move_y=(my-144)/64;




if(pg==2 && boardid[move_x][move_y]/100==player && mx>=144 && mx<=144+512 && my>=144 && my<=144+512 && winner==0)
	
{	
	/******solder move*****************/

	if(boardid[move_x][move_y]/10==11)
		move=110+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==12)
		move=120+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==13)
		move=130+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==14)
		move=140+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==15)
		move=150+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==16)
		move=160+((boardid[move_x][move_y])%10);
	
//player 2
	
	
	if(boardid[move_x][move_y]/10==21)
		move=210+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==22)
		move=220+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==23)
		move=230+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==24)
		move=240+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==25)
		move=250+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==26)
		move=260+((boardid[move_x][move_y])%10);
	
}

if(pg==3)
{
	if(mx>=240&&mx<=308&&my>=397&&my<=430)
	{
		sound=0;
		pg=1;
	}
	if(mx>=460&&mx<=508&&my>=398&&my<=426)
	{
		sound=1;
		pg=1;
	}

}



}///end of mouse click condition




if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
{
//place your codes here


	/****************************************************************************************/
	/*******   start<<<<        animation of page=1 button            *******************************/


/*              for star button     */
	
move_x=(mx-144)/64;

move_y=(my-144)/64;




	if(pg==1 && pg1_but==1)
	{
		pg=2;
		start_y=start_y+5;
		pg1_but=0;
		

	}

/*     for sound button       */


if(pg==1 && pg1_but==2)
	{
		pg=3;
		sound_y=sound_y+5;
		pg1_but=0;
	}

/*    for help button    */

if(pg==1 && pg1_but==3)
	{
		pg=4;
		help_y=help_y+5;
		pg1_but=0;

	}

/*     for about button       */


if(pg==1 && pg1_but==4)
	{
		pg=5;
		abt_y=abt_y+5;
		pg1_but=0;
	}


/*     for credits button       */


if(pg==1 && pg1_but==5)
	{
		pg=6;
		cre_y=cre_y+5;
		pg1_but=0;
	}



/*     for con button       */


if(pg==1 && pg1_but==6)
	{
		pg=7;
		con_y=con_y+5;
		pg1_but=0;
	}


/**        for exit button                        */
if(pg==1 && pg1_but==7)
	{
		pg1_but=0;
		printf("\n\n\n\n\t\t\t\tThanks For Playing\n\n\n\n\n");
		exit(0);	
	

	}




	/*******       end<<<<    animation of page=1 button            *******************************/
	/********************************************************************************************/
/************************      pg 2 condition   *****************************************/




if(pg==2)
{











///***************         player 1 move                        /*****************************/ 

	
	//raza 
		if(move/10==11)
{
	
	
		raza1.check_m();
		
		

	if(mx<144 || mx>144+512 || my<144 || my>144+512)
	{
		raza1.set_cx(montri1.get_lx());
		raza1.set_cy(raza1.get_ly());
		raza1.set_ax((raza1.get_lx()*64)+144);
		raza1.set_ay((raza1.get_ly()*64)+144);
		move=0;
		check=50;
		if(sound==1)
			printf("\a");

	}

	else 
	{
		
		if(check==0)
	{
		raza1.set_cx(raza1.get_lx());
		raza1.set_cy(raza1.get_ly());
		raza1.set_ax((raza1.get_lx()*64)+144);
		raza1.set_ay((raza1.get_ly()*64)+144);
	
		move=0;
		check=50;
		if(sound==1)
			printf("\a");
	
	}
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[raza1.get_lx()][raza1.get_ly()]=0;
			raza1.set_lx();
			raza1.set_ly();
			raza1.set_ax((raza1.get_lx()*64)+144);
			raza1.set_ay((raza1.get_ly()*64)+144);
			boardid[move_x][move_y]=raza1.get_bi();
		
			move=0;
			check=50;
			player=2;
		
		}
		else 
		{
			if(check==2)
		{
			boardid[raza1.get_lx()][raza1.get_ly()]=0;
			raza1.set_lx();
			raza1.set_ly();
			raza1.set_ax((raza1.get_lx()*64)+144);
			raza1.set_ay((raza1.get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=raza1.get_bi();
		
			move=0;
			check=50;
			player=2;
		}
			else 
			{
				raza1.set_cx(raza1.get_lx());
				raza1.set_cy(raza1.get_ly());
				raza1.set_ax((raza1.get_lx()*64)+144);
				raza1.set_ay((raza1.get_ly()*64)+144);
	
				move=0;
				check=50;
				if(sound==1)
			printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition
}//
	



//montri player 1
		if(move/10==12)
{
	
		montri1.check_m();

		temp_bi=boardid[montri1.get_lx()][montri1.get_ly()];
		temp1_bi=boardid[montri1.get_cx()][montri1.get_cy()];
		boardid[montri1.get_lx()][montri1.get_ly()]=0;
		
		
		boardid[montri1.get_cx()][montri1.get_cy()]=montri1.get_bi();
		
		check_king(2);
		boardid[montri1.get_lx()][montri1.get_ly()]=temp_bi;
		
		boardid[montri1.get_cx()][montri1.get_cy()]=temp1_bi;
		

	if(mx<144 || mx>144+512 || my<144 || my>144+512||kcheck==1)
	{
		montri1.set_cx(montri1.get_lx());
		montri1.set_cy(montri1.get_ly());
		montri1.set_ax((montri1.get_lx()*64)+144);
		montri1.set_ay((montri1.get_ly()*64)+144);
		move=0;
		check=50;
		if(sound==1)
			printf("\a");
	
	}//out of board

	else 
	{
		
		if(check==0)
	{
		montri1.set_cx(montri1.get_lx());
		montri1.set_cy(montri1.get_ly());
		montri1.set_ax((montri1.get_lx()*64)+144);
		montri1.set_ay((montri1.get_ly()*64)+144);
	
		move=0;
		check=50;
		if(sound==1)
			printf("\a");
	
	}//illegal move
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[montri1.get_lx()][montri1.get_ly()]=0;
			montri1.set_lx();
			montri1.set_ly();
			montri1.set_ax((montri1.get_lx()*64)+144);
			montri1.set_ay((montri1.get_ly()*64)+144);
			boardid[move_x][move_y]=montri1.get_bi();
			player=2;
			move=0;
			check=50;
			turn++;
		
		}//legal and emty place
		else 
		{
			if(check==2)
		{
			boardid[montri1.get_lx()][montri1.get_ly()]=0;
			montri1.set_lx();
			montri1.set_ly();
			montri1.set_ax((montri1.get_lx()*64)+144);
			montri1.set_ay((montri1.get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=montri1.get_bi();
			player=2;
			move=0;
			check=50;
			turn++;
		}//eaten pieces
			else 
			{
				montri1.set_cx(montri1.get_lx());
				montri1.set_cy(montri1.get_ly());
				montri1.set_ax((montri1.get_lx()*64)+144);
				montri1.set_ay((montri1.get_ly()*64)+144);
	
				move=0;
				check=50;
				if(sound==1)
					printf("\a");
			}//no condition matches so illegal
		
	}//end of legal but not emty square

	}//end of else condition
	
	}//end of out of board else condition


}		

		//ghora player 1
	if(move/10==13)
{
	
	ghora1[move%10].check_m();
		
			
		temp_bi=boardid[ghora1[move%10].get_lx()][ghora1[move%10].get_ly()];
		temp1_bi=boardid[(ghora1[move%10]).get_cx()][(ghora1[move%10]).get_cy()];
		boardid[ghora1[move%10].get_lx()][ghora1[move%10].get_ly()]=0;
	
		printf("temp=%d ",temp_bi);

		
		boardid[(ghora1[move%10]).get_cx()][(ghora1[move%10]).get_cy()]=ghora1[move%10].get_bi();
		
		check_king(2);
		
		boardid[(ghora1[move%10]).get_lx()][(ghora1[move%10]).get_ly()]=temp_bi;

		boardid[ghora1[move%10].get_cx()][ghora1[move%10].get_cy()]=temp1_bi;
		

	if(mx<144 || mx>144+512 || my<144 || my>144+512||turn==0||kcheck==1)
	{
		ghora1[move%10].set_cx(ghora1[move%10].get_lx());
	
		ghora1[move%10].set_cy(ghora1[move%10].get_ly());
	
		ghora1[move%10].set_ax((ghora1[move%10].get_lx()*64)+144);
		ghora1[move%10].set_ay((ghora1[move%10].get_ly()*64)+144);
		move=0;
		check=50;
		boardid[ghora1[move%10].get_lx()][ghora1[move%10].get_ly()]=temp_bi;
		if(sound==1)
			printf("\a");
	
	}

	else 
	{
		
		if(check==0)
	{
		ghora1[move%10].set_cx(ghora1[move%10].get_lx());
		ghora1[move%10].set_cy(ghora1[move%10].get_ly());
		ghora1[move%10].set_ax((ghora1[move%10].get_lx()*64)+144);
		ghora1[move%10].set_ay((ghora1[move%10].get_ly()*64)+144);
	
		move=0;
		check=50;
		boardid[ghora1[move%10].get_lx()][ghora1[move%10].get_ly()]=temp_bi;
		if(sound==1)
			printf("\a");
		
	}
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[ghora1[move%10].get_lx()][ghora1[move%10].get_ly()]=0;
			ghora1[move%10].set_lx();
			ghora1[move%10].set_ly();
			ghora1[move%10].set_ax((ghora1[move%10].get_lx()*64)+144);
			ghora1[move%10].set_ay((ghora1[move%10].get_ly()*64)+144);
			boardid[move_x][move_y]=ghora1[move%10].get_bi();
			player=2;
			move=0;
			check=50;
		
		}
		else 
		{
			if(check==2)
		{
			boardid[ghora1[move%10].get_lx()][ghora1[move%10].get_ly()]=0;
			ghora1[move%10].set_lx();
			ghora1[move%10].set_ly();
			ghora1[move%10].set_ax((ghora1[move%10].get_lx()*64)+144);
			ghora1[move%10].set_ay((ghora1[move%10].get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=ghora1[move%10].get_bi();
			move=0;
			check=50;
			player=2;
		}
			else 
			{
				ghora1[move%10].set_cx(ghora1[move%10].get_lx());
				ghora1[move%10].set_cy(ghora1[move%10].get_ly());
				ghora1[move%10].set_ax((ghora1[move%10].get_lx()*64)+144);
				ghora1[move%10].set_ay((ghora1[move%10].get_ly()*64)+144);
	
				move=0;
				check=50;
				boardid[ghora1[move%10].get_lx()][ghora1[move%10].get_ly()]=temp_bi;
				if(sound==1)
					printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition

}
		
		//nouka player 1
	if(move/10==14)
{
	
	nouka1[move%10].check_m();

		temp_bi=boardid[nouka1[move%10].get_lx()][nouka1[move%10].get_ly()];
		temp1_bi=boardid[nouka1[move%10].get_cx()][nouka1[move%10].get_cy()];
		boardid[nouka1[move%10].get_lx()][nouka1[move%10].get_ly()]=0;
		
		
		boardid[nouka1[move%10].get_cx()][nouka1[move%10].get_cy()]=nouka1[move%10].get_bi();
		
		check_king(2);
		
		boardid[nouka1[move%10].get_lx()][nouka1[move%10].get_ly()]=temp_bi;
		boardid[nouka1[move%10].get_cx()][nouka1[move%10].get_cy()]=temp1_bi;


	if(mx<144 || mx>144+512 || my<144 || my>144+512 || kcheck==1)
	{
		nouka1[move%10].set_cx(nouka1[move%10].get_lx());
		nouka1[move%10].set_cy(nouka1[move%10].get_ly());
		nouka1[move%10].set_ax((nouka1[move%10].get_lx()*64)+144);
		nouka1[move%10].set_ay((nouka1[move%10].get_ly()*64)+144);
		move=0;
		check=50;
		if(sound==1)
			printf("\a");
	
	}

	else 
	{
		
		if(check==0)
	{
		nouka1[move%10].set_cx(nouka1[move%10].get_lx());
		nouka1[move%10].set_cy(nouka1[move%10].get_ly());
		nouka1[move%10].set_ax((nouka1[move%10].get_lx()*64)+144);
		nouka1[move%10].set_ay((nouka1[move%10].get_ly()*64)+144);
	
		move=0;
		check=50;
		if(sound==1)
			printf("\a");

	}
	else 
	{	
		

		if(check==1)
		{
			
		
			boardid[nouka1[move%10].get_lx()][nouka1[move%10].get_ly()]=0;
			nouka1[move%10].set_lx();
			nouka1[move%10].set_ly();
			nouka1[move%10].set_ax((nouka1[move%10].get_lx()*64)+144);
			nouka1[move%10].set_ay((nouka1[move%10].get_ly()*64)+144);
			boardid[move_x][move_y]=nouka1[move%10].get_bi();
			player=2;
			move=0;
			check=50;
			turn++;
		
		}
		else 
		{
			if(check==2)
		{
			boardid[nouka1[move%10].get_lx()][nouka1[move%10].get_ly()]=0;
			nouka1[move%10].set_lx();
			nouka1[move%10].set_ly();
			nouka1[move%10].set_ax((nouka1[move%10].get_lx()*64)+144);
			nouka1[move%10].set_ay((nouka1[move%10].get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=nouka1[move%10].get_bi();
		
			move=0;
			check=50;
			turn++;
			player=2;
		}
			else 
			{
				nouka1[move%10].set_cx(nouka1[move%10].get_lx());
				nouka1[move%10].set_cy(nouka1[move%10].get_ly());
				nouka1[move%10].set_ax((nouka1[move%10].get_lx()*64)+144);
				nouka1[move%10].set_ay((nouka1[move%10].get_ly()*64)+144);
	
				move=0;
				check=50;
				if(sound==1)
					printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition
}
	

	
	
	//hati player 1
	if(move/10==15)
{
	
	hati1[move%10].check_m();

		temp_bi=boardid[hati1[move%10].get_lx()][hati1[move%10].get_ly()];
		temp1_bi=boardid[hati1[move%10].get_cx()][hati1[move%10].get_cy()];
		boardid[hati1[move%10].get_lx()][hati1[move%10].get_ly()]=0;
		
		
		boardid[hati1[move%10].get_cx()][hati1[move%10].get_cy()]=hati1[move%10].get_bi();
		
		check_king(2);
		
		boardid[hati1[move%10].get_lx()][hati1[move%10].get_ly()]=temp_bi;
		boardid[hati1[move%10].get_cx()][hati1[move%10].get_cy()]=temp1_bi;


	if(mx<144 || mx>144+512 || my<144 || my>144+512 ||kcheck==1)
	{
		hati1[move%10].set_cx(hati1[move%10].get_lx());
		hati1[move%10].set_cy(hati1[move%10].get_ly());
		hati1[move%10].set_ax((hati1[move%10].get_lx()*64)+144);
		hati1[move%10].set_ay((hati1[move%10].get_ly()*64)+144);
		move=0;
		check=50;
			if(sound==1)
					printf("\a");

	}

	else 
	{
		
		if(check==0)
	{
		hati1[move%10].set_cx(hati1[move%10].get_lx());
		hati1[move%10].set_cy(hati1[move%10].get_ly());
		hati1[move%10].set_ax((hati1[move%10].get_lx()*64)+144);
		hati1[move%10].set_ay((hati1[move%10].get_ly()*64)+144);
	
		move=0;
		check=50;
			if(sound==1)
					printf("\a");

	}
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[hati1[move%10].get_lx()][hati1[move%10].get_ly()]=0;
			hati1[move%10].set_lx();
			hati1[move%10].set_ly();
			hati1[move%10].set_ax((hati1[move%10].get_lx()*64)+144);
			hati1[move%10].set_ay((hati1[move%10].get_ly()*64)+144);
			boardid[move_x][move_y]=hati1[move%10].get_bi();
	
			move=0;
			check=50;
			turn++;
			player=2;
		
		}
		else 
		{
			if(check==2)
		{
			boardid[hati1[move%10].get_lx()][hati1[move%10].get_ly()]=0;
			hati1[move%10].set_lx();
			hati1[move%10].set_ly();
			hati1[move%10].set_ax((hati1[move%10].get_lx()*64)+144);
			hati1[move%10].set_ay((hati1[move%10].get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=hati1[move%10].get_bi();
		
			move=0;
			check=50;
			player=2;
		}
			else 
			{
				hati1[move%10].set_cx(hati1[move%10].get_lx());
				hati1[move%10].set_cy(hati1[move%10].get_ly());
				hati1[move%10].set_ax((hati1[move%10].get_lx()*64)+144);
				hati1[move%10].set_ay((hati1[move%10].get_ly()*64)+144);
	
				move=0;
				check=50;
					if(sound==1)
					printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition
}	
	
	
	//solder 
	if(move/10==16)
{
	solder1[move%10].check_m();

		temp_bi=boardid[solder1[move%10].get_lx()][solder1[move%10].get_ly()];
		temp1_bi=boardid[solder1[move%10].get_cx()][solder1[move%10].get_cy()];
		boardid[solder1[move%10].get_lx()][solder1[move%10].get_ly()]=0;
		
		
		boardid[solder1[move%10].get_cx()][solder1[move%10].get_cy()]=solder1[move%10].get_bi();
		
		check_king(2);
		
		boardid[solder1[move%10].get_lx()][solder1[move%10].get_ly()]=temp_bi;
		boardid[solder1[move%10].get_cx()][solder1[move%10].get_cy()]=temp1_bi;

	if(mx<144 || mx>144+512 || my<144 || my>144+512||kcheck==1)
	{
		solder1[move%10].set_cx(solder1[move%10].get_lx());
		solder1[move%10].set_cy(solder1[move%10].get_ly());
		solder1[move%10].set_ax((solder1[move%10].get_lx()*64)+144);
		solder1[move%10].set_ay((solder1[move%10].get_ly()*64)+144);
		move=0;
		check=50;
			if(sound==1)
					printf("\a");
	
	}

	else 
	{
		
		if(check==0)
	{
		solder1[move%10].set_cx(solder1[move%10].get_lx());
		solder1[move%10].set_cy(solder1[move%10].get_ly());
		solder1[move%10].set_ax((solder1[move%10].get_lx()*64)+144);
		solder1[move%10].set_ay((solder1[move%10].get_ly()*64)+144);
	
		move=0;
		check=50;
			if(sound==1)
					printf("\a");

	}
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[solder1[move%10].get_lx()][solder1[move%10].get_ly()]=0;
			solder1[move%10].set_lx();
			solder1[move%10].set_ly();
			solder1[move%10].set_ax((solder1[move%10].get_lx()*64)+144);
			solder1[move%10].set_ay((solder1[move%10].get_ly()*64)+144);
			boardid[move_x][move_y]=solder1[move%10].get_bi();
		
			move=0;
			check=50;
			turn++;
			player=2;

		
		}
		else 
		{
			if(check==2)
		{
			boardid[solder1[move%10].get_lx()][solder1[move%10].get_ly()]=0;
			solder1[move%10].set_lx();
			solder1[move%10].set_ly();
			solder1[move%10].set_ax((solder1[move%10].get_lx()*64)+144);
			solder1[move%10].set_ay((solder1[move%10].get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=solder1[move%10].get_bi();
	
			move=0;
			check=50;
			turn++;
			player=2;
		}
			else 
			{
				solder1[move%10].set_cx(solder1[move%10].get_lx());
				solder1[move%10].set_cy(solder1[move%10].get_ly());
				solder1[move%10].set_ax((solder1[move%10].get_lx()*64)+144);
				solder1[move%10].set_ay((solder1[move%10].get_ly()*64)+144);
	
				move=0;
				check=50;
					if(sound==1)
					printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition

}//end of solder

///***************         player 2 move                        /*****************************/ 

	
	//raza 
		if(move/10==21)
{
	
		
		raza2.check_m();

		

	if(mx<144 || mx>144+512 || my<144 || my>144+512)
	{
		raza2.set_cx(montri1.get_lx());
		raza2.set_cy(raza2.get_ly());
		raza2.set_ax((raza2.get_lx()*64)+144);
		raza2.set_ay((raza2.get_ly()*64)+144);
		move=0;
		check=50;
			if(sound==1)
					printf("\a");

	}

	else 
	{
		
		if(check==0)
	{
		raza2.set_cx(raza2.get_lx());
		raza2.set_cy(raza2.get_ly());
		raza2.set_ax((raza2.get_lx()*64)+144);
		raza2.set_ay((raza2.get_ly()*64)+144);
	
		move=0;
		check=50;
			if(sound==1)
					printf("\a");
	
	}
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[raza2.get_lx()][raza2.get_ly()]=0;
			raza2.set_lx();
			raza2.set_ly();
			raza2.set_ax((raza2.get_lx()*64)+144);
			raza2.set_ay((raza2.get_ly()*64)+144);
			boardid[move_x][move_y]=raza2.get_bi();
		
			move=0;
			check=50;
			player=1;
		
		}
		else 
		{
			if(check==2)
		{
			boardid[raza2.get_lx()][raza2.get_ly()]=0;
			raza2.set_lx();
			raza2.set_ly();
			raza2.set_ax((raza2.get_lx()*64)+144);
			raza2.set_ay((raza2.get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=raza2.get_bi();
		
			move=0;
			check=50;
			player=1;
		}
			else 
			{
				raza2.set_cx(raza2.get_lx());
				raza2.set_cy(raza2.get_ly());
				raza2.set_ax((raza2.get_lx()*64)+144);
				raza2.set_ay((raza2.get_ly()*64)+144);
	
				move=0;
				check=50;
					if(sound==1)
					printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition

}
	
//montri player 2
		if(move/10==22)
{
	
		montri2.check_m();
		temp_bi=boardid[montri2.get_lx()][montri2.get_ly()];
		temp1_bi=boardid[montri2.get_cx()][montri2.get_cy()];
		boardid[montri2.get_lx()][montri2.get_ly()]=0;
		
		
		boardid[montri2.get_cx()][montri2.get_cy()]=montri2.get_bi();
		
		check_king(1);
		
		boardid[montri2.get_lx()][montri2.get_ly()]=temp_bi;
		boardid[montri2.get_cx()][montri2.get_cy()]=temp1_bi;

	if(mx<144 || mx>144+512 || my<144 || my>144+512||kcheck==1)
	{
		
		montri2.set_cx(montri2.get_lx());
		montri2.set_cy(montri2.get_ly());
		montri2.set_ax((montri2.get_lx()*64)+144);
		montri2.set_ay((montri2.get_ly()*64)+144);
		move=0;
		check=50;
			if(sound==1)
					printf("\a");
	}

	else 
	{
		
		if(check==0)
	{
		montri2.set_cx(montri2.get_lx());
		montri2.set_cy(montri2.get_ly());
		montri2.set_ax((montri2.get_lx()*64)+144);
		montri2.set_ay((montri2.get_ly()*64)+144);
	
		move=0;
		check=50;
			if(sound==1)
					printf("\a");
	
	}
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[montri2.get_lx()][montri2.get_ly()]=0;
			montri2.set_lx();
			montri2.set_ly();
			montri2.set_ax((montri2.get_lx()*64)+144);
			montri2.set_ay((montri2.get_ly()*64)+144);
			boardid[move_x][move_y]=montri2.get_bi();
		
			move=0;
			check=50;
			player=1;
		
		}
		else 
		{
			if(check==2)
		{
			boardid[montri2.get_lx()][montri2.get_ly()]=0;
			montri2.set_lx();
			montri2.set_ly();
			montri2.set_ax((montri2.get_lx()*64)+144);
			montri2.set_ay((montri2.get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=montri2.get_bi();
		
			move=0;
			check=50;
			player=1;
		}
			else 
			{
				montri2.set_cx(montri2.get_lx());
				montri2.set_cy(montri2.get_ly());
				montri2.set_ax((montri2.get_lx()*64)+144);
				montri2.set_ay((montri2.get_ly()*64)+144);
	
				move=0;
				check=50;
					if(sound==1)
					printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition


}		

		//ghora player 2
	if(move/10==23)
{
	
	ghora2[move%10].check_m();

		temp_bi=boardid[ghora2[move%10].get_lx()][ghora2[move%10].get_ly()];
		temp1_bi=boardid[ghora2[move%10].get_cx()][ghora2[move%10].get_cy()];
		boardid[ghora2[move%10].get_lx()][ghora2[move%10].get_ly()]=0;
		
		
		boardid[ghora2[move%10].get_cx()][ghora2[move%10].get_cy()]=ghora2[move%10].get_bi();
		
		check_king(1);
		
		boardid[ghora2[move%10].get_lx()][ghora2[move%10].get_ly()]=temp_bi;
		boardid[ghora2[move%10].get_cx()][ghora2[move%10].get_cy()]=temp1_bi;	

	if(mx<144 || mx>144+512 || my<144 || my>144+512||turn1==0||kcheck==1)
	{
		ghora2[move%10].set_cx(ghora2[move%10].get_lx());
	
		ghora2[move%10].set_cy(ghora2[move%10].get_ly());
	
		ghora2[move%10].set_ax((ghora2[move%10].get_lx()*64)+144);
		ghora2[move%10].set_ay((ghora2[move%10].get_ly()*64)+144);
		move=0;
		check=50;
			if(sound==1)
					printf("\a");
	}
	else 
	{
		
		if(check==0)
	{
		ghora2[move%10].set_cx(ghora2[move%10].get_lx());
		ghora2[move%10].set_cy(ghora2[move%10].get_ly());
		ghora2[move%10].set_ax((ghora2[move%10].get_lx()*64)+144);
		ghora2[move%10].set_ay((ghora2[move%10].get_ly()*64)+144);
	
		move=0;
		check=50;
			if(sound==1)
					printf("\a");
		
	}
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[ghora2[move%10].get_lx()][ghora2[move%10].get_ly()]=0;
			ghora2[move%10].set_lx();
			ghora2[move%10].set_ly();
			ghora2[move%10].set_ax((ghora2[move%10].get_lx()*64)+144);
			ghora2[move%10].set_ay((ghora2[move%10].get_ly()*64)+144);
			boardid[move_x][move_y]=ghora2[move%10].get_bi();
		
			move=0;
			check=50;
			player=1;
		
		}
		else 
		{
			if(check==2)
		{
			boardid[ghora2[move%10].get_lx()][ghora2[move%10].get_ly()]=0;
			ghora2[move%10].set_lx();
			ghora2[move%10].set_ly();
			ghora2[move%10].set_ax((ghora2[move%10].get_lx()*64)+144);
			ghora2[move%10].set_ay((ghora2[move%10].get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=ghora2[move%10].get_bi();
			player=1;
			move=0;
			check=50;
		}
			else 
			{
				ghora2[move%10].set_cx(ghora2[move%10].get_lx());
				ghora2[move%10].set_cy(ghora2[move%10].get_ly());
				ghora2[move%10].set_ax((ghora2[move%10].get_lx()*64)+144);
				ghora2[move%10].set_ay((ghora2[move%10].get_ly()*64)+144);
	
				move=0;
				check=50;
					if(sound==1)
					printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition

}
		
		//nouka player 2
	if(move/10==24)
{
	
	nouka2[move%10].check_m();
	
	temp_bi=boardid[nouka2[move%10].get_lx()][nouka2[move%10].get_ly()];
	temp1_bi=boardid[nouka2[move%10].get_cx()][nouka2[move%10].get_cy()];
	boardid[nouka2[move%10].get_lx()][nouka2[move%10].get_ly()]=0;
		

	boardid[nouka2[move%10].get_cx()][nouka2[move%10].get_cy()]=nouka2[move%10].get_bi();
		
	check_king(1);
		
	boardid[nouka2[move%10].get_lx()][nouka2[move%10].get_ly()]=temp_bi;
	boardid[nouka2[move%10].get_cx()][nouka2[move%10].get_cy()]=temp1_bi;

	if(mx<144 || mx>144+512 || my<144 || my>144+512||kcheck==1)
	{
		nouka2[move%10].set_cx(nouka2[move%10].get_lx());
		nouka2[move%10].set_cy(nouka2[move%10].get_ly());
		nouka2[move%10].set_ax((nouka2[move%10].get_lx()*64)+144);
		nouka2[move%10].set_ay((nouka2[move%10].get_ly()*64)+144);
		move=0;
		check=50;
			if(sound==1)
					printf("\a");
	
	}

	else 
	{
		
		if(check==0)
	{
		nouka2[move%10].set_cx(nouka2[move%10].get_lx());
		nouka2[move%10].set_cy(nouka2[move%10].get_ly());
		nouka2[move%10].set_ax((nouka2[move%10].get_lx()*64)+144);
		nouka2[move%10].set_ay((nouka2[move%10].get_ly()*64)+144);
	
		move=0;
		check=50;
			if(sound==1)
					printf("\a");

	}
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[nouka2[move%10].get_lx()][nouka2[move%10].get_ly()]=0;
			nouka2[move%10].set_lx();
			nouka2[move%10].set_ly();
			nouka2[move%10].set_ax((nouka2[move%10].get_lx()*64)+144);
			nouka2[move%10].set_ay((nouka2[move%10].get_ly()*64)+144);
			boardid[move_x][move_y]=nouka2[move%10].get_bi();
		
			move=0;
			check=50;
			player=1;
		
		}
		else 
		{
			if(check==2)
		{
			boardid[nouka2[move%10].get_lx()][nouka2[move%10].get_ly()]=0;
			nouka2[move%10].set_lx();
			nouka2[move%10].set_ly();
			nouka2[move%10].set_ax((nouka2[move%10].get_lx()*64)+144);
			nouka2[move%10].set_ay((nouka2[move%10].get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=nouka2[move%10].get_bi();
	
			move=0;
			check=50;
			player=1;
		}
			else 
			{
				nouka2[move%10].set_cx(nouka2[move%10].get_lx());
				nouka2[move%10].set_cy(nouka2[move%10].get_ly());
				nouka2[move%10].set_ax((nouka2[move%10].get_lx()*64)+144);
				nouka2[move%10].set_ay((nouka2[move%10].get_ly()*64)+144);
	
				move=0;
				check=50;
					if(sound==1)
					printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition
}
	

	
	
	//hati player2
	if(move/10==25)
{
	
	hati2[move%10].check_m();
	
	
		temp_bi=boardid[hati2[move%10].get_lx()][hati2[move%10].get_ly()];
		temp1_bi=boardid[hati2[move%10].get_cx()][hati2[move%10].get_cy()];
		boardid[hati2[move%10].get_lx()][hati2[move%10].get_ly()]=0;
		
		
		boardid[hati2[move%10].get_cx()][hati2[move%10].get_cy()]=hati2[move%10].get_bi();
		
		check_king(1);
		
		boardid[hati2[move%10].get_lx()][hati2[move%10].get_ly()]=temp_bi;
		boardid[hati2[move%10].get_cx()][hati2[move%10].get_cy()]=temp1_bi;
	if(mx<144 || mx>144+512 || my<144 || my>144+512||kcheck==1)
	{
		hati2[move%10].set_cx(hati2[move%10].get_lx());
		hati2[move%10].set_cy(hati2[move%10].get_ly());
		hati2[move%10].set_ax((hati2[move%10].get_lx()*64)+144);
		hati2[move%10].set_ay((hati2[move%10].get_ly()*64)+144);
		move=0;
		check=50;
			if(sound==1)
					printf("\a");
	
	}

	else 
	{
		
		if(check==0)
	{
		hati2[move%10].set_cx(hati2[move%10].get_lx());
		hati2[move%10].set_cy(hati2[move%10].get_ly());
		hati2[move%10].set_ax((hati2[move%10].get_lx()*64)+144);
		hati2[move%10].set_ay((hati2[move%10].get_ly()*64)+144);
	
		move=0;
		check=50;
			if(sound==1)
					printf("\a");

	}
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[hati2[move%10].get_lx()][hati2[move%10].get_ly()]=0;
			hati2[move%10].set_lx();
			hati2[move%10].set_ly();
			hati2[move%10].set_ax((hati2[move%10].get_lx()*64)+144);
			hati2[move%10].set_ay((hati2[move%10].get_ly()*64)+144);
			boardid[move_x][move_y]=hati2[move%10].get_bi();
	
			move=0;
			check=50;
			player=1;
		
		}
		else 
		{
			if(check==2)
		{
			boardid[hati2[move%10].get_lx()][hati2[move%10].get_ly()]=0;
			hati2[move%10].set_lx();
			hati2[move%10].set_ly();
			hati2[move%10].set_ax((hati2[move%10].get_lx()*64)+144);
			hati2[move%10].set_ay((hati2[move%10].get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=hati2[move%10].get_bi();
	
			move=0;
			check=50;
		
			player=1;
		}
			else 
			{
				hati2[move%10].set_cx(hati2[move%10].get_lx());
				hati2[move%10].set_cy(hati2[move%10].get_ly());
				hati2[move%10].set_ax((hati2[move%10].get_lx()*64)+144);
				hati2[move%10].set_ay((hati2[move%10].get_ly()*64)+144);
	
				move=0;
				check=50;
					if(sound==1)
					printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition
}	
	
	
	//solder player2
	if(move/10==26)
{
	solder2[move%10].check_m();
	
	
		temp_bi=boardid[solder2[move%10].get_lx()][solder2[move%10].get_ly()];
		temp1_bi=boardid[solder2[move%10].get_cx()][solder2[move%10].get_cy()];
		boardid[solder2[move%10].get_lx()][solder2[move%10].get_ly()]=0;
		
		
		boardid[solder2[move%10].get_cx()][solder2[move%10].get_cy()]=solder2[move%10].get_bi();
		
		check_king(1);
		
		boardid[solder2[move%10].get_lx()][solder2[move%10].get_ly()]=temp_bi;
		boardid[solder2[move%10].get_cx()][solder2[move%10].get_cy()]=temp1_bi;

	if(mx<144 || mx>144+512 || my<144 || my>144+512|| kcheck==1)
	{
		solder2[move%10].set_cx(solder2[move%10].get_lx());
		solder2[move%10].set_cy(solder2[move%10].get_ly());
		solder2[move%10].set_ax((solder2[move%10].get_lx()*64)+144);
		solder2[move%10].set_ay((solder2[move%10].get_ly()*64)+144);
		move=0;
		check=50;
			if(sound==1)
					printf("\a");

	}//out of board

	else 
	{
		
		if(check==0)
	{
		solder2[move%10].set_cx(solder2[move%10].get_lx());
		solder2[move%10].set_cy(solder2[move%10].get_ly());
		solder2[move%10].set_ax((solder2[move%10].get_lx()*64)+144);
		solder2[move%10].set_ay((solder2[move%10].get_ly()*64)+144);
	
		move=0;
		check=50;
			if(sound==1)
					printf("\a");

	}//illegal move
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[solder2[move%10].get_lx()][solder2[move%10].get_ly()]=0;
			solder2[move%10].set_lx();
			solder2[move%10].set_ly();
			solder2[move%10].set_ax((solder2[move%10].get_lx()*64)+144);
			solder2[move%10].set_ay((solder2[move%10].get_ly()*64)+144);
			boardid[move_x][move_y]=solder2[move%10].get_bi();
		
			move=0;
			check=50;
			turn1++;
			player=1;
		
		}//legal move
		else 
		{
			if(check==2)
		{
			boardid[solder2[move%10].get_lx()][solder2[move%10].get_ly()]=0;
			solder2[move%10].set_lx();
			solder2[move%10].set_ly();
			solder2[move%10].set_ax((solder2[move%10].get_lx()*64)+144);
			solder2[move%10].set_ay((solder2[move%10].get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=solder2[move%10].get_bi();
	
			move=0;
			check=50;
			turn1++;
			player=1;
		}//legal move wit eaten piece
			else 
			{
				solder2[move%10].set_cx(solder2[move%10].get_lx());
				solder2[move%10].set_cy(solder2[move%10].get_ly());
				solder2[move%10].set_ax((solder2[move%10].get_lx()*64)+144);
				solder2[move%10].set_ay((solder2[move%10].get_ly()*64)+144);
	
				move=0;
				check=50;
					if(sound==1)
					printf("\a");
			}//no condition matches so illegal move
		
	}//end of legal and  eaten piece condition

	}//end of else condition
	
	}//end of out of board else condition

}//end of solder






}//end of pg 2 condition








}//end of up condition


if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
{
	mouse++;
	if(mouse==20)
		mouse=0;
	
	if(mouse%2==0)
	{
		



if(pg==2)
{






///***************         player 1 move                        /*****************************/ 

	
	//raza 
		if(move_rt/10==11)
{
	
	raza1.set_cx(move_x);
	raza1.set_cy(move_y);
	raza1.set_ax(mx);
	raza1.set_ay(my);
}
	
//montri 
		if(move_rt/10==12)
{
	
	montri1.set_cx(move_x);
	montri1.set_cy(move_y);
	montri1.set_ax(mx);
	montri1.set_ay(my);


}		

		//ghora
	if(move_rt/10==13)
{
	
	ghora1[move_rt%10].set_cx(move_x);
	ghora1[move_rt%10].set_cy(move_y);
	ghora1[move_rt%10].set_ax(mx);
	ghora1[move_rt%10].set_ay(my);
}
		
		//nouka
	if(move_rt/10==14)
{
	
	nouka1[move_rt%10].set_cx(move_x);
	nouka1[move_rt%10].set_cy(move_y);
	nouka1[move_rt%10].set_ax(mx);
	nouka1[move_rt%10].set_ay(my);
}
	
			//hati
	if(move_rt/10==15)
{
	
	hati1[move_rt%10].set_cx(move_x);
	hati1[move_rt%10].set_cy(move_y);
	hati1[move_rt%10].set_ax(mx);
	hati1[move_rt%10].set_ay(my);
}	
	
	
	//solder 
	if(move_rt/10==16)
{
	
	solder1[move_rt%10].set_cx(move_x);
	solder1[move_rt%10].set_cy(move_y);
	solder1[move_rt%10].set_ax(mx);
	solder1[move_rt%10].set_ay(my);
}

///***************         player 2 move                        /*****************************/ 

	
	//raza 
		if(move_rt/10==21)
{
	
	raza2.set_cx(move_x);
	raza2.set_cy(move_y);
	raza2.set_ax(mx);
	raza2.set_ay(my);
}
	
//montri 
		if(move_rt/10==22)
{
	
	montri2.set_cx(move_x);
	montri2.set_cy(move_y);
	montri2.set_ax(mx);
	montri2.set_ay(my);
}		

		//ghora
	if(move_rt/10==23)
{
	
	ghora2[move_rt%10].set_cx(move_x);
	ghora2[move_rt%10].set_cy(move_y);
	ghora2[move_rt%10].set_ax(mx);
	ghora2[move_rt%10].set_ay(my);
}
		
		//nouka
	if(move_rt/10==24)
{
	
	nouka2[move_rt%10].set_cx(move_x);
	nouka2[move_rt%10].set_cy(move_y);
	nouka2[move_rt%10].set_ax(mx);
	nouka2[move_rt%10].set_ay(my);
}
	
			//hati
	if(move_rt/10==25)
{
	
	hati2[move_rt%10].set_cx(move_x);
	hati2[move_rt%10].set_cy(move_y);
	hati2[move_rt%10].set_ax(mx);
	hati2[move_rt%10].set_ay(my);
}	
	
	
	//solder 
	if(move_rt/10==26)
{
	
	solder2[move_rt%10].set_cx(move_x);
	solder2[move_rt%10].set_cy(move_y);
	solder2[move_rt%10].set_ax(mx);
	solder2[move_rt%10].set_ay(my);
}



	
}//page 2 condition

//}//ending player 1 move condition

/*************************************   end of player 1 move*************************/


if(pg==2)
{











///***************         player 1 move                        /*****************************/ 

	
	//raza 
		if(move_rt/10==11)
{
	
	
		raza1.check_m();
		
		

	if(mx<144 || mx>144+512 || my<144 || my>144+512)
	{
		raza1.set_cx(montri1.get_lx());
		raza1.set_cy(raza1.get_ly());
		raza1.set_ax((raza1.get_lx()*64)+144);
		raza1.set_ay((raza1.get_ly()*64)+144);
		move_rt=0;
		check=50;
		if(sound==1)
			printf("\a");

	}

	else 
	{
		
		if(check==0)
	{
		raza1.set_cx(raza1.get_lx());
		raza1.set_cy(raza1.get_ly());
		raza1.set_ax((raza1.get_lx()*64)+144);
		raza1.set_ay((raza1.get_ly()*64)+144);
	
		move_rt=0;
		check=50;
		if(sound==1)
			printf("\a");
	
	}
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[raza1.get_lx()][raza1.get_ly()]=0;
			raza1.set_lx();
			raza1.set_ly();
			raza1.set_ax((raza1.get_lx()*64)+144);
			raza1.set_ay((raza1.get_ly()*64)+144);
			boardid[move_x][move_y]=raza1.get_bi();
		
			move_rt=0;
			check=50;
			player=2;
		
		}
		else 
		{
			if(check==2)
		{
			boardid[raza1.get_lx()][raza1.get_ly()]=0;
			raza1.set_lx();
			raza1.set_ly();
			raza1.set_ax((raza1.get_lx()*64)+144);
			raza1.set_ay((raza1.get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=raza1.get_bi();
		
			move_rt=0;
			check=50;
			player=2;
		}
			else 
			{
				raza1.set_cx(raza1.get_lx());
				raza1.set_cy(raza1.get_ly());
				raza1.set_ax((raza1.get_lx()*64)+144);
				raza1.set_ay((raza1.get_ly()*64)+144);
	
				move_rt=0;
				check=50;
				if(sound==1)
			printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition
}//
	



//montri player 1
		if(move_rt/10==12)
{
	
		montri1.check_m();

		temp_bi=boardid[montri1.get_lx()][montri1.get_ly()];
		boardid[montri1.get_lx()][montri1.get_ly()]=0;
		
		temp1_bi=boardid[montri1.get_cx()][montri1.get_cy()];
		boardid[montri1.get_cx()][montri1.get_cy()]=montri1.get_bi();
		
		check_king(2);
		boardid[montri1.get_lx()][montri1.get_ly()]=temp_bi;
		
		boardid[montri1.get_cx()][montri1.get_cy()]=temp1_bi;
		

	if(mx<144 || mx>144+512 || my<144 || my>144+512||kcheck==1)
	{
		montri1.set_cx(montri1.get_lx());
		montri1.set_cy(montri1.get_ly());
		montri1.set_ax((montri1.get_lx()*64)+144);
		montri1.set_ay((montri1.get_ly()*64)+144);
		move_rt=0;
		check=50;
		if(sound==1)
			printf("\a");
	
	}//out of board

	else 
	{
		
		if(check==0)
	{
		montri1.set_cx(montri1.get_lx());
		montri1.set_cy(montri1.get_ly());
		montri1.set_ax((montri1.get_lx()*64)+144);
		montri1.set_ay((montri1.get_ly()*64)+144);
	
		move_rt=0;
		check=50;
		if(sound==1)
			printf("\a");
	
	}//illegal move
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[montri1.get_lx()][montri1.get_ly()]=0;
			montri1.set_lx();
			montri1.set_ly();
			montri1.set_ax((montri1.get_lx()*64)+144);
			montri1.set_ay((montri1.get_ly()*64)+144);
			boardid[move_x][move_y]=montri1.get_bi();
			player=2;
			move_rt=0;
			check=50;
			turn++;
		
		}//legal and emty place
		else 
		{
			if(check==2)
		{
			boardid[montri1.get_lx()][montri1.get_ly()]=0;
			montri1.set_lx();
			montri1.set_ly();
			montri1.set_ax((montri1.get_lx()*64)+144);
			montri1.set_ay((montri1.get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=montri1.get_bi();
			player=2;
			move_rt=0;
			check=50;
			turn++;
		}//eaten pieces
			else 
			{
				montri1.set_cx(montri1.get_lx());
				montri1.set_cy(montri1.get_ly());
				montri1.set_ax((montri1.get_lx()*64)+144);
				montri1.set_ay((montri1.get_ly()*64)+144);
	
				move_rt=0;
				check=50;
				if(sound==1)
					printf("\a");
			}//no condition matches so illegal
		
	}//end of legal but not emty square

	}//end of else condition
	
	}//end of out of board else condition


}		

		//ghora player 1
	if(move_rt/10==13)
{
	
	ghora1[move_rt%10].check_m();

		temp_bi=boardid[ghora1[move_rt%10].get_lx()][ghora1[move_rt%10].get_ly()];
		boardid[ghora1[move_rt%10].get_lx()][ghora1[move_rt%10].get_ly()]=0;
		
		temp1_bi=boardid[ghora1[move_rt%10].get_cx()][ghora1[move_rt%10].get_cy()];
		boardid[ghora1[move_rt%10].get_cx()][ghora1[move_rt%10].get_cy()]=ghora1[move_rt%10].get_bi();
		
		check_king(2);
		boardid[ghora1[move_rt%10].get_lx()][ghora1[move_rt%10].get_ly()]=temp_bi;

		boardid[ghora1[move_rt%10].get_cx()][ghora1[move_rt%10].get_cy()]=temp1_bi;

	if(mx<144 || mx>144+512 || my<144 || my>144+512||turn==0||kcheck==1)
	{
		ghora1[move_rt%10].set_cx(ghora1[move_rt%10].get_lx());
	
		ghora1[move_rt%10].set_cy(ghora1[move_rt%10].get_ly());
	
		ghora1[move_rt%10].set_ax((ghora1[move_rt%10].get_lx()*64)+144);
		ghora1[move_rt%10].set_ay((ghora1[move_rt%10].get_ly()*64)+144);
		move_rt=0;
		check=50;
		if(sound==1)
			printf("\a");
	
	}

	else 
	{
		
		if(check==0)
	{
		ghora1[move_rt%10].set_cx(ghora1[move_rt%10].get_lx());
		ghora1[move_rt%10].set_cy(ghora1[move_rt%10].get_ly());
		ghora1[move_rt%10].set_ax((ghora1[move_rt%10].get_lx()*64)+144);
		ghora1[move_rt%10].set_ay((ghora1[move_rt%10].get_ly()*64)+144);
	
		move_rt=0;
		check=50;
		if(sound==1)
			printf("\a");
		
	}
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[ghora1[move_rt%10].get_lx()][ghora1[move_rt%10].get_ly()]=0;
			ghora1[move_rt%10].set_lx();
			ghora1[move_rt%10].set_ly();
			ghora1[move_rt%10].set_ax((ghora1[move_rt%10].get_lx()*64)+144);
			ghora1[move_rt%10].set_ay((ghora1[move_rt%10].get_ly()*64)+144);
			boardid[move_x][move_y]=ghora1[move_rt%10].get_bi();
			player=2;
			move_rt=0;
			check=50;
		
		}
		else 
		{
			if(check==2)
		{
			boardid[ghora1[move_rt%10].get_lx()][ghora1[move_rt%10].get_ly()]=0;
			ghora1[move_rt%10].set_lx();
			ghora1[move_rt%10].set_ly();
			ghora1[move_rt%10].set_ax((ghora1[move_rt%10].get_lx()*64)+144);
			ghora1[move_rt%10].set_ay((ghora1[move_rt%10].get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=ghora1[move_rt%10].get_bi();
			move_rt=0;
			check=50;
			player=2;
		}
			else 
			{
				ghora1[move_rt%10].set_cx(ghora1[move_rt%10].get_lx());
				ghora1[move_rt%10].set_cy(ghora1[move_rt%10].get_ly());
				ghora1[move_rt%10].set_ax((ghora1[move_rt%10].get_lx()*64)+144);
				ghora1[move_rt%10].set_ay((ghora1[move_rt%10].get_ly()*64)+144);
	
				move_rt=0;
				check=50;
				if(sound==1)
					printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition

}
		
		//nouka player 1
	if(move_rt/10==14)
{
	
	nouka1[move_rt%10].check_m();

		temp_bi=boardid[nouka1[move_rt%10].get_lx()][nouka1[move_rt%10].get_ly()];
		boardid[nouka1[move_rt%10].get_lx()][nouka1[move_rt%10].get_ly()]=0;
		
		temp1_bi=boardid[nouka1[move_rt%10].get_cx()][nouka1[move_rt%10].get_cy()];
		boardid[nouka1[move_rt%10].get_cx()][nouka1[move_rt%10].get_cy()]=nouka1[move_rt%10].get_bi();
		
		check_king(2);
		
		boardid[nouka1[move_rt%10].get_lx()][nouka1[move_rt%10].get_ly()]=temp_bi;
		boardid[nouka1[move_rt%10].get_cx()][nouka1[move_rt%10].get_cy()]=temp1_bi;


	if(mx<144 || mx>144+512 || my<144 || my>144+512 || kcheck==1)
	{
		nouka1[move_rt%10].set_cx(nouka1[move_rt%10].get_lx());
		nouka1[move_rt%10].set_cy(nouka1[move_rt%10].get_ly());
		nouka1[move_rt%10].set_ax((nouka1[move_rt%10].get_lx()*64)+144);
		nouka1[move_rt%10].set_ay((nouka1[move_rt%10].get_ly()*64)+144);
		move_rt=0;
		check=50;
		if(sound==1)
			printf("\a");
	
	}

	else 
	{
		
		if(check==0)
	{
		nouka1[move_rt%10].set_cx(nouka1[move_rt%10].get_lx());
		nouka1[move_rt%10].set_cy(nouka1[move_rt%10].get_ly());
		nouka1[move_rt%10].set_ax((nouka1[move_rt%10].get_lx()*64)+144);
		nouka1[move_rt%10].set_ay((nouka1[move_rt%10].get_ly()*64)+144);
	
		move_rt=0;
		check=50;
		if(sound==1)
			printf("\a");

	}
	else 
	{	
		

		if(check==1)
		{
			
		
			boardid[nouka1[move_rt%10].get_lx()][nouka1[move_rt%10].get_ly()]=0;
			nouka1[move_rt%10].set_lx();
			nouka1[move_rt%10].set_ly();
			nouka1[move_rt%10].set_ax((nouka1[move_rt%10].get_lx()*64)+144);
			nouka1[move_rt%10].set_ay((nouka1[move_rt%10].get_ly()*64)+144);
			boardid[move_x][move_y]=nouka1[move_rt%10].get_bi();
			player=2;
			move_rt=0;
			check=50;
			turn++;
		
		}
		else 
		{
			if(check==2)
		{
			boardid[nouka1[move_rt%10].get_lx()][nouka1[move_rt%10].get_ly()]=0;
			nouka1[move_rt%10].set_lx();
			nouka1[move_rt%10].set_ly();
			nouka1[move_rt%10].set_ax((nouka1[move_rt%10].get_lx()*64)+144);
			nouka1[move_rt%10].set_ay((nouka1[move_rt%10].get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=nouka1[move_rt%10].get_bi();
		
			move_rt=0;
			check=50;
			turn++;
			player=2;
		}
			else 
			{
				nouka1[move_rt%10].set_cx(nouka1[move_rt%10].get_lx());
				nouka1[move_rt%10].set_cy(nouka1[move_rt%10].get_ly());
				nouka1[move_rt%10].set_ax((nouka1[move_rt%10].get_lx()*64)+144);
				nouka1[move_rt%10].set_ay((nouka1[move_rt%10].get_ly()*64)+144);
	
				move_rt=0;
				check=50;
				if(sound==1)
					printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition
}
	

	
	
	//hati player 1
	if(move_rt/10==15)
{
	
	hati1[move_rt%10].check_m();

		temp_bi=boardid[hati1[move_rt%10].get_lx()][hati1[move_rt%10].get_ly()];
		boardid[hati1[move_rt%10].get_lx()][hati1[move_rt%10].get_ly()]=0;
		
		temp1_bi=boardid[hati1[move_rt%10].get_cx()][hati1[move_rt%10].get_cy()];
		boardid[hati1[move_rt%10].get_cx()][hati1[move_rt%10].get_cy()]=hati1[move_rt%10].get_bi();
		
		check_king(2);
		
		boardid[hati1[move_rt%10].get_lx()][hati1[move_rt%10].get_ly()]=temp_bi;
		boardid[hati1[move_rt%10].get_cx()][hati1[move_rt%10].get_cy()]=temp1_bi;


	if(mx<144 || mx>144+512 || my<144 || my>144+512 ||kcheck==1)
	{
		hati1[move_rt%10].set_cx(hati1[move_rt%10].get_lx());
		hati1[move_rt%10].set_cy(hati1[move_rt%10].get_ly());
		hati1[move_rt%10].set_ax((hati1[move_rt%10].get_lx()*64)+144);
		hati1[move_rt%10].set_ay((hati1[move_rt%10].get_ly()*64)+144);
		move_rt=0;
		check=50;
			if(sound==1)
					printf("\a");

	}

	else 
	{
		
		if(check==0)
	{
		hati1[move_rt%10].set_cx(hati1[move_rt%10].get_lx());
		hati1[move_rt%10].set_cy(hati1[move_rt%10].get_ly());
		hati1[move_rt%10].set_ax((hati1[move_rt%10].get_lx()*64)+144);
		hati1[move_rt%10].set_ay((hati1[move_rt%10].get_ly()*64)+144);
	
		move_rt=0;
		check=50;
			if(sound==1)
					printf("\a");

	}
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[hati1[move_rt%10].get_lx()][hati1[move_rt%10].get_ly()]=0;
			hati1[move_rt%10].set_lx();
			hati1[move_rt%10].set_ly();
			hati1[move_rt%10].set_ax((hati1[move_rt%10].get_lx()*64)+144);
			hati1[move_rt%10].set_ay((hati1[move_rt%10].get_ly()*64)+144);
			boardid[move_x][move_y]=hati1[move_rt%10].get_bi();
	
			move_rt=0;
			check=50;
			turn++;
			player=2;
		
		}
		else 
		{
			if(check==2)
		{
			boardid[hati1[move_rt%10].get_lx()][hati1[move_rt%10].get_ly()]=0;
			hati1[move_rt%10].set_lx();
			hati1[move_rt%10].set_ly();
			hati1[move_rt%10].set_ax((hati1[move_rt%10].get_lx()*64)+144);
			hati1[move_rt%10].set_ay((hati1[move_rt%10].get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=hati1[move_rt%10].get_bi();
		
			move_rt=0;
			check=50;
			player=2;
		}
			else 
			{
				hati1[move_rt%10].set_cx(hati1[move_rt%10].get_lx());
				hati1[move_rt%10].set_cy(hati1[move_rt%10].get_ly());
				hati1[move_rt%10].set_ax((hati1[move_rt%10].get_lx()*64)+144);
				hati1[move_rt%10].set_ay((hati1[move_rt%10].get_ly()*64)+144);
	
				move_rt=0;
				check=50;
					if(sound==1)
					printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition
}	
	
	
	//solder 
	if(move_rt/10==16)
{
	solder1[move_rt%10].check_m();

		temp_bi=boardid[solder1[move_rt%10].get_lx()][solder1[move_rt%10].get_ly()];
		boardid[solder1[move_rt%10].get_lx()][solder1[move_rt%10].get_ly()]=0;
		
		temp1_bi=boardid[solder1[move_rt%10].get_cx()][solder1[move_rt%10].get_cy()];
		boardid[solder1[move_rt%10].get_cx()][solder1[move_rt%10].get_cy()]=solder1[move_rt%10].get_bi();
		
		check_king(2);
		
		boardid[solder1[move_rt%10].get_lx()][solder1[move_rt%10].get_ly()]=temp_bi;
		boardid[solder1[move_rt%10].get_cx()][solder1[move_rt%10].get_cy()]=temp1_bi;

	if(mx<144 || mx>144+512 || my<144 || my>144+512||kcheck==1)
	{
		solder1[move_rt%10].set_cx(solder1[move_rt%10].get_lx());
		solder1[move_rt%10].set_cy(solder1[move_rt%10].get_ly());
		solder1[move_rt%10].set_ax((solder1[move_rt%10].get_lx()*64)+144);
		solder1[move_rt%10].set_ay((solder1[move_rt%10].get_ly()*64)+144);
		move_rt=0;
		check=50;
			if(sound==1)
					printf("\a");
	
	}

	else 
	{
		
		if(check==0)
	{
		solder1[move_rt%10].set_cx(solder1[move_rt%10].get_lx());
		solder1[move_rt%10].set_cy(solder1[move_rt%10].get_ly());
		solder1[move_rt%10].set_ax((solder1[move_rt%10].get_lx()*64)+144);
		solder1[move_rt%10].set_ay((solder1[move_rt%10].get_ly()*64)+144);
	
		move_rt=0;
		check=50;
			if(sound==1)
					printf("\a");

	}
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[solder1[move_rt%10].get_lx()][solder1[move_rt%10].get_ly()]=0;
			solder1[move_rt%10].set_lx();
			solder1[move_rt%10].set_ly();
			solder1[move_rt%10].set_ax((solder1[move_rt%10].get_lx()*64)+144);
			solder1[move_rt%10].set_ay((solder1[move_rt%10].get_ly()*64)+144);
			boardid[move_x][move_y]=solder1[move_rt%10].get_bi();
		
			move_rt=0;
			check=50;
			turn++;
			player=2;

		
		}
		else 
		{
			if(check==2)
		{
			boardid[solder1[move_rt%10].get_lx()][solder1[move_rt%10].get_ly()]=0;
			solder1[move_rt%10].set_lx();
			solder1[move_rt%10].set_ly();
			solder1[move_rt%10].set_ax((solder1[move_rt%10].get_lx()*64)+144);
			solder1[move_rt%10].set_ay((solder1[move_rt%10].get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=solder1[move_rt%10].get_bi();
	
			move_rt=0;
			check=50;
			turn++;
			player=2;
		}
			else 
			{
				solder1[move_rt%10].set_cx(solder1[move_rt%10].get_lx());
				solder1[move_rt%10].set_cy(solder1[move_rt%10].get_ly());
				solder1[move_rt%10].set_ax((solder1[move_rt%10].get_lx()*64)+144);
				solder1[move_rt%10].set_ay((solder1[move_rt%10].get_ly()*64)+144);
	
				move_rt=0;
				check=50;
					if(sound==1)
					printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition

}//end of solder

///***************         player 2 move                        /*****************************/ 

	
	//raza 
		if(move_rt/10==21)
{
	
		
		raza2.check_m();

		

	if(mx<144 || mx>144+512 || my<144 || my>144+512)
	{
		raza2.set_cx(montri1.get_lx());
		raza2.set_cy(raza2.get_ly());
		raza2.set_ax((raza2.get_lx()*64)+144);
		raza2.set_ay((raza2.get_ly()*64)+144);
		move_rt=0;
		check=50;
			if(sound==1)
					printf("\a");

	}

	else 
	{
		
		if(check==0)
	{
		raza2.set_cx(raza2.get_lx());
		raza2.set_cy(raza2.get_ly());
		raza2.set_ax((raza2.get_lx()*64)+144);
		raza2.set_ay((raza2.get_ly()*64)+144);
	
		move_rt=0;
		check=50;
			if(sound==1)
					printf("\a");
	
	}
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[raza2.get_lx()][raza2.get_ly()]=0;
			raza2.set_lx();
			raza2.set_ly();
			raza2.set_ax((raza2.get_lx()*64)+144);
			raza2.set_ay((raza2.get_ly()*64)+144);
			boardid[move_x][move_y]=raza2.get_bi();
		
			move_rt=0;
			check=50;
			player=1;
		
		}
		else 
		{
			if(check==2)
		{
			boardid[raza2.get_lx()][raza2.get_ly()]=0;
			raza2.set_lx();
			raza2.set_ly();
			raza2.set_ax((raza2.get_lx()*64)+144);
			raza2.set_ay((raza2.get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=raza2.get_bi();
		
			move_rt=0;
			check=50;
			player=1;
		}
			else 
			{
				raza2.set_cx(raza2.get_lx());
				raza2.set_cy(raza2.get_ly());
				raza2.set_ax((raza2.get_lx()*64)+144);
				raza2.set_ay((raza2.get_ly()*64)+144);
	
				move_rt=0;
				check=50;
					if(sound==1)
					printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition

}
	
//montri player 2
		if(move_rt/10==22)
{
	
		montri2.check_m();
		temp_bi=boardid[montri2.get_lx()][montri2.get_ly()];
		boardid[montri2.get_lx()][montri2.get_ly()]=0;
		
		temp1_bi=boardid[montri2.get_cx()][montri2.get_cy()];
		boardid[montri2.get_cx()][montri2.get_cy()]=montri2.get_bi();
		
		check_king(1);
		
		boardid[montri2.get_lx()][montri2.get_ly()]=temp_bi;
		boardid[montri2.get_cx()][montri2.get_cy()]=temp1_bi;

	if(mx<144 || mx>144+512 || my<144 || my>144+512||kcheck==1)
	{
		
		montri2.set_cx(montri2.get_lx());
		montri2.set_cy(montri2.get_ly());
		montri2.set_ax((montri2.get_lx()*64)+144);
		montri2.set_ay((montri2.get_ly()*64)+144);
		move_rt=0;
		check=50;
			if(sound==1)
					printf("\a");
	}

	else 
	{
		
		if(check==0)
	{
		montri2.set_cx(montri2.get_lx());
		montri2.set_cy(montri2.get_ly());
		montri2.set_ax((montri2.get_lx()*64)+144);
		montri2.set_ay((montri2.get_ly()*64)+144);
	
		move_rt=0;
		check=50;
			if(sound==1)
					printf("\a");
	
	}
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[montri2.get_lx()][montri2.get_ly()]=0;
			montri2.set_lx();
			montri2.set_ly();
			montri2.set_ax((montri2.get_lx()*64)+144);
			montri2.set_ay((montri2.get_ly()*64)+144);
			boardid[move_x][move_y]=montri2.get_bi();
		
			move_rt=0;
			check=50;
			player=1;
		
		}
		else 
		{
			if(check==2)
		{
			boardid[montri2.get_lx()][montri2.get_ly()]=0;
			montri2.set_lx();
			montri2.set_ly();
			montri2.set_ax((montri2.get_lx()*64)+144);
			montri2.set_ay((montri2.get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=montri2.get_bi();
		
			move_rt=0;
			check=50;
			player=1;
		}
			else 
			{
				montri2.set_cx(montri2.get_lx());
				montri2.set_cy(montri2.get_ly());
				montri2.set_ax((montri2.get_lx()*64)+144);
				montri2.set_ay((montri2.get_ly()*64)+144);
	
				move_rt=0;
				check=50;
					if(sound==1)
					printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition


}		

		//ghora player 2
	if(move_rt/10==23)
{
	
	ghora2[move_rt%10].check_m();

		temp_bi=boardid[ghora2[move_rt%10].get_lx()][ghora2[move_rt%10].get_ly()];
		boardid[ghora2[move_rt%10].get_lx()][ghora2[move_rt%10].get_ly()]=0;
		
		temp1_bi=boardid[ghora2[move_rt%10].get_cx()][ghora2[move_rt%10].get_cy()];
		boardid[ghora2[move_rt%10].get_cx()][ghora2[move_rt%10].get_cy()]=ghora2[move_rt%10].get_bi();
		
		check_king(1);
		
		boardid[ghora2[move_rt%10].get_lx()][ghora2[move_rt%10].get_ly()]=temp_bi;
		boardid[ghora2[move_rt%10].get_cx()][ghora2[move_rt%10].get_cy()]=temp1_bi;	

	if(mx<144 || mx>144+512 || my<144 || my>144+512||turn1==0||kcheck==1)
	{
		ghora2[move_rt%10].set_cx(ghora2[move_rt%10].get_lx());
	
		ghora2[move_rt%10].set_cy(ghora2[move_rt%10].get_ly());
	
		ghora2[move_rt%10].set_ax((ghora2[move_rt%10].get_lx()*64)+144);
		ghora2[move_rt%10].set_ay((ghora2[move_rt%10].get_ly()*64)+144);
		move_rt=0;
		check=50;
			if(sound==1)
					printf("\a");
	}
	else 
	{
		
		if(check==0)
	{
		ghora2[move_rt%10].set_cx(ghora2[move_rt%10].get_lx());
		ghora2[move_rt%10].set_cy(ghora2[move_rt%10].get_ly());
		ghora2[move_rt%10].set_ax((ghora2[move_rt%10].get_lx()*64)+144);
		ghora2[move_rt%10].set_ay((ghora2[move_rt%10].get_ly()*64)+144);
	
		move_rt=0;
		check=50;
			if(sound==1)
					printf("\a");
		
	}
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[ghora2[move_rt%10].get_lx()][ghora2[move_rt%10].get_ly()]=0;
			ghora2[move_rt%10].set_lx();
			ghora2[move_rt%10].set_ly();
			ghora2[move_rt%10].set_ax((ghora2[move_rt%10].get_lx()*64)+144);
			ghora2[move_rt%10].set_ay((ghora2[move_rt%10].get_ly()*64)+144);
			boardid[move_x][move_y]=ghora2[move_rt%10].get_bi();
		
			move_rt=0;
			check=50;
			player=1;
		
		}
		else 
		{
			if(check==2)
		{
			boardid[ghora2[move_rt%10].get_lx()][ghora2[move_rt%10].get_ly()]=0;
			ghora2[move_rt%10].set_lx();
			ghora2[move_rt%10].set_ly();
			ghora2[move_rt%10].set_ax((ghora2[move_rt%10].get_lx()*64)+144);
			ghora2[move_rt%10].set_ay((ghora2[move_rt%10].get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=ghora2[move_rt%10].get_bi();
			player=1;
			move_rt=0;
			check=50;
		}
			else 
			{
				ghora2[move_rt%10].set_cx(ghora2[move_rt%10].get_lx());
				ghora2[move_rt%10].set_cy(ghora2[move_rt%10].get_ly());
				ghora2[move_rt%10].set_ax((ghora2[move_rt%10].get_lx()*64)+144);
				ghora2[move_rt%10].set_ay((ghora2[move_rt%10].get_ly()*64)+144);
	
				move_rt=0;
				check=50;
					if(sound==1)
					printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition

}
		
		//nouka player 2
	if(move_rt/10==24)
{
	
	nouka2[move_rt%10].check_m();
	
	temp_bi=boardid[nouka2[move_rt%10].get_lx()][nouka2[move_rt%10].get_ly()];
	boardid[nouka2[move_rt%10].get_lx()][nouka2[move_rt%10].get_ly()]=0;
		
	temp1_bi=boardid[nouka2[move_rt%10].get_cx()][nouka2[move_rt%10].get_cy()];
	boardid[nouka2[move_rt%10].get_cx()][nouka2[move_rt%10].get_cy()]=nouka2[move_rt%10].get_bi();
		
	check_king(1);
		
	boardid[nouka2[move_rt%10].get_lx()][nouka2[move_rt%10].get_ly()]=temp_bi;
	boardid[nouka2[move_rt%10].get_cx()][nouka2[move_rt%10].get_cy()]=temp1_bi;

	if(mx<144 || mx>144+512 || my<144 || my>144+512||kcheck==1)
	{
		nouka2[move_rt%10].set_cx(nouka2[move_rt%10].get_lx());
		nouka2[move_rt%10].set_cy(nouka2[move_rt%10].get_ly());
		nouka2[move_rt%10].set_ax((nouka2[move_rt%10].get_lx()*64)+144);
		nouka2[move_rt%10].set_ay((nouka2[move_rt%10].get_ly()*64)+144);
		move_rt=0;
		check=50;
			if(sound==1)
					printf("\a");
	
	}

	else 
	{
		
		if(check==0)
	{
		nouka2[move_rt%10].set_cx(nouka2[move_rt%10].get_lx());
		nouka2[move_rt%10].set_cy(nouka2[move_rt%10].get_ly());
		nouka2[move_rt%10].set_ax((nouka2[move_rt%10].get_lx()*64)+144);
		nouka2[move_rt%10].set_ay((nouka2[move_rt%10].get_ly()*64)+144);
	
		move_rt=0;
		check=50;
			if(sound==1)
					printf("\a");

	}
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[nouka2[move_rt%10].get_lx()][nouka2[move_rt%10].get_ly()]=0;
			nouka2[move_rt%10].set_lx();
			nouka2[move_rt%10].set_ly();
			nouka2[move_rt%10].set_ax((nouka2[move_rt%10].get_lx()*64)+144);
			nouka2[move_rt%10].set_ay((nouka2[move_rt%10].get_ly()*64)+144);
			boardid[move_x][move_y]=nouka2[move_rt%10].get_bi();
		
			move_rt=0;
			check=50;
			player=1;
		
		}
		else 
		{
			if(check==2)
		{
			boardid[nouka2[move_rt%10].get_lx()][nouka2[move_rt%10].get_ly()]=0;
			nouka2[move_rt%10].set_lx();
			nouka2[move_rt%10].set_ly();
			nouka2[move_rt%10].set_ax((nouka2[move_rt%10].get_lx()*64)+144);
			nouka2[move_rt%10].set_ay((nouka2[move_rt%10].get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=nouka2[move_rt%10].get_bi();
	
			move_rt=0;
			check=50;
			player=1;
		}
			else 
			{
				nouka2[move_rt%10].set_cx(nouka2[move_rt%10].get_lx());
				nouka2[move_rt%10].set_cy(nouka2[move_rt%10].get_ly());
				nouka2[move_rt%10].set_ax((nouka2[move_rt%10].get_lx()*64)+144);
				nouka2[move_rt%10].set_ay((nouka2[move_rt%10].get_ly()*64)+144);
	
				move_rt=0;
				check=50;
					if(sound==1)
					printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition
}
	

	
	
	//hati player2
	if(move_rt/10==25)
{
	
	hati2[move_rt%10].check_m();
	
	
		temp_bi=boardid[hati2[move_rt%10].get_lx()][hati2[move_rt%10].get_ly()];
		boardid[hati2[move_rt%10].get_lx()][hati2[move_rt%10].get_ly()]=0;
		
		temp1_bi=boardid[hati2[move_rt%10].get_cx()][hati2[move_rt%10].get_cy()];
		boardid[hati2[move_rt%10].get_cx()][hati2[move_rt%10].get_cy()]=hati2[move_rt%10].get_bi();
		
		check_king(1);
		
		boardid[hati2[move_rt%10].get_lx()][hati2[move_rt%10].get_ly()]=temp_bi;
		boardid[hati2[move_rt%10].get_cx()][hati2[move_rt%10].get_cy()]=temp1_bi;
	if(mx<144 || mx>144+512 || my<144 || my>144+512||kcheck==1)
	{
		hati2[move_rt%10].set_cx(hati2[move_rt%10].get_lx());
		hati2[move_rt%10].set_cy(hati2[move_rt%10].get_ly());
		hati2[move_rt%10].set_ax((hati2[move_rt%10].get_lx()*64)+144);
		hati2[move_rt%10].set_ay((hati2[move_rt%10].get_ly()*64)+144);
		move_rt=0;
		check=50;
			if(sound==1)
					printf("\a");
	
	}

	else 
	{
		
		if(check==0)
	{
		hati2[move_rt%10].set_cx(hati2[move_rt%10].get_lx());
		hati2[move_rt%10].set_cy(hati2[move_rt%10].get_ly());
		hati2[move_rt%10].set_ax((hati2[move_rt%10].get_lx()*64)+144);
		hati2[move_rt%10].set_ay((hati2[move_rt%10].get_ly()*64)+144);
	
		move_rt=0;
		check=50;
			if(sound==1)
					printf("\a");

	}
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[hati2[move_rt%10].get_lx()][hati2[move_rt%10].get_ly()]=0;
			hati2[move_rt%10].set_lx();
			hati2[move_rt%10].set_ly();
			hati2[move_rt%10].set_ax((hati2[move_rt%10].get_lx()*64)+144);
			hati2[move_rt%10].set_ay((hati2[move_rt%10].get_ly()*64)+144);
			boardid[move_x][move_y]=hati2[move_rt%10].get_bi();
	
			move_rt=0;
			check=50;
			player=1;
		
		}
		else 
		{
			if(check==2)
		{
			boardid[hati2[move_rt%10].get_lx()][hati2[move_rt%10].get_ly()]=0;
			hati2[move_rt%10].set_lx();
			hati2[move_rt%10].set_ly();
			hati2[move_rt%10].set_ax((hati2[move_rt%10].get_lx()*64)+144);
			hati2[move_rt%10].set_ay((hati2[move_rt%10].get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=hati2[move_rt%10].get_bi();
	
			move_rt=0;
			check=50;
		
			player=1;
		}
			else 
			{
				hati2[move_rt%10].set_cx(hati2[move_rt%10].get_lx());
				hati2[move_rt%10].set_cy(hati2[move_rt%10].get_ly());
				hati2[move_rt%10].set_ax((hati2[move_rt%10].get_lx()*64)+144);
				hati2[move_rt%10].set_ay((hati2[move_rt%10].get_ly()*64)+144);
	
				move_rt=0;
				check=50;
					if(sound==1)
					printf("\a");
			}
		
	}

	}//end of else condition
	
	}//end of out of board else condition
}	
	
	
	//solder player2
	if(move_rt/10==26)
{
	solder2[move_rt%10].check_m();
	
	
		temp_bi=boardid[solder2[move_rt%10].get_lx()][solder2[move_rt%10].get_ly()];
		boardid[solder2[move_rt%10].get_lx()][solder2[move_rt%10].get_ly()]=0;
		
		temp1_bi=boardid[solder2[move_rt%10].get_cx()][solder2[move_rt%10].get_cy()];
		boardid[solder2[move_rt%10].get_cx()][solder2[move_rt%10].get_cy()]=solder2[move_rt%10].get_bi();
		
		check_king(1);
		
		boardid[solder2[move_rt%10].get_lx()][solder2[move_rt%10].get_ly()]=temp_bi;
		boardid[solder2[move_rt%10].get_cx()][solder2[move_rt%10].get_cy()]=temp1_bi;

	if(mx<144 || mx>144+512 || my<144 || my>144+512|| kcheck==1)
	{
		solder2[move_rt%10].set_cx(solder2[move_rt%10].get_lx());
		solder2[move_rt%10].set_cy(solder2[move_rt%10].get_ly());
		solder2[move_rt%10].set_ax((solder2[move_rt%10].get_lx()*64)+144);
		solder2[move_rt%10].set_ay((solder2[move_rt%10].get_ly()*64)+144);
		move_rt=0;
		check=50;
			if(sound==1)
					printf("\a");

	}//out of board

	else 
	{
		
		if(check==0)
	{
		solder2[move_rt%10].set_cx(solder2[move_rt%10].get_lx());
		solder2[move_rt%10].set_cy(solder2[move_rt%10].get_ly());
		solder2[move_rt%10].set_ax((solder2[move_rt%10].get_lx()*64)+144);
		solder2[move_rt%10].set_ay((solder2[move_rt%10].get_ly()*64)+144);
	
		move_rt=0;
		check=50;
			if(sound==1)
					printf("\a");

	}//illegal move
	else 
	{	
		

		if(check==1)
		{
	
		
			boardid[solder2[move_rt%10].get_lx()][solder2[move_rt%10].get_ly()]=0;
			solder2[move_rt%10].set_lx();
			solder2[move_rt%10].set_ly();
			solder2[move_rt%10].set_ax((solder2[move_rt%10].get_lx()*64)+144);
			solder2[move_rt%10].set_ay((solder2[move_rt%10].get_ly()*64)+144);
			boardid[move_x][move_y]=solder2[move_rt%10].get_bi();
		
			move_rt=0;
			check=50;
			turn1++;
			player=1;
		
		}//legal move
		else 
		{
			if(check==2)
		{
			boardid[solder2[move_rt%10].get_lx()][solder2[move_rt%10].get_ly()]=0;
			solder2[move_rt%10].set_lx();
			solder2[move_rt%10].set_ly();
			solder2[move_rt%10].set_ax((solder2[move_rt%10].get_lx()*64)+144);
			solder2[move_rt%10].set_ay((solder2[move_rt%10].get_ly()*64)+144);
			move_p=boardid[move_x][move_y];
			make_dead();
			boardid[move_x][move_y]=solder2[move_rt%10].get_bi();
	
			move_rt=0;
			check=50;
			turn1++;
			player=1;
		}//legal move wit eaten piece
			else 
			{
				solder2[move_rt%10].set_cx(solder2[move_rt%10].get_lx());
				solder2[move_rt%10].set_cy(solder2[move_rt%10].get_ly());
				solder2[move_rt%10].set_ax((solder2[move_rt%10].get_lx()*64)+144);
				solder2[move_rt%10].set_ay((solder2[move_rt%10].get_ly()*64)+144);
	
				move_rt=0;
				check=50;
					if(sound==1)
					printf("\a");
			}//no condition matches so illegal move
		
	}//end of legal and  eaten piece condition

	}//end of else condition
	
	}//end of out of board else condition

}//end of solder






}//end of pg 2 condition

	}//end of unlock condition

if(mouse%2==1)
{
	move_x=(mx-144)/64;

	move_y=(my-144)/64;

//	mouse=0;

if(pg==2 && boardid[move_x][move_y]/100==player && mx>=144 && mx<=144+512 && my>=144 && my<=144+512 && winner==0)
	
{	
	/******solder move*****************/

	
	if(boardid[move_x][move_y]/10==11)
		move_rt=110+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==12)
		move_rt=120+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==13)
		move_rt=130+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==14)
		move_rt=140+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==15)
		move_rt=150+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==16)
		move_rt=160+((boardid[move_x][move_y])%10);
	
//player 2
	
	
	if(boardid[move_x][move_y]/10==21)
		move_rt=210+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==22)
		move_rt=220+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==23)
		move_rt=230+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==24)
		move_rt=240+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==25)
		move_rt=250+((boardid[move_x][move_y])%10);
	if(boardid[move_x][move_y]/10==26)
		move_rt=260+((boardid[move_x][move_y])%10);
	
}

}//end of mouse lock condition





}//end of down conditon of right button




}/*end of mouse*/





 
 
 
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
		
	}
	//place your codes for other keys here
}










/************************************************************************************************/
/*                                    move functions                                            */


void move_pg_one()
{


	slide_num++;
	if(slide_num==14)
		slide_num=0;
}



void move_menu()
{

	if(menu_x==50)
		menu_condition=1;
	if(menu_x==(50+512-128))
		menu_condition=0;
	if(menu_condition==1)
		menu_x+=2;
	if(menu_condition==0)
		menu_x=menu_x-2;
	
		
	
}




/************************************************************************************************/
/*                                    move functions                                            */
/************************************************************************************************/
				







int main()
{
	//place your own initialization codes here before iInitialize().
	iSettimer(2500,move_pg_one);
	iSettimer(50,move_menu);
	iInitialize(800, 800, "CHESS");
	return 0;
}
