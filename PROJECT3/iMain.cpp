#include "iGraphics.h"
#include "bitmap_loader.h"
# include "HeroMovement.h"
# include "bossMovement.h"

void showable(void);
void read(void);
int level1=0;





int x = 300, y = 300, r = 20;
int len=0;


int i,j,k;
int flag=0;
int h=600;
int w=1000;
int image1,image2,image3,image4,image5,image6,image7,image8,plane1,image9,image10,image11,image12,image13,plane2,bullet, bossbullet;
int ee,eflag = 0;
char nameShow[10];
int point=0;
char pname[100];
int enemyPassedCounter = 0,collisionCounter=0,bulletCollision=0;
char str[20],str2[20];
int mode=1;
int damagex[5]  ={9000,9000,9000,9000,9000};
int damagey[5] ={10000,10000,10000,10000,10000};
int index = 0;


int bby=10;

int bb;

int dx=5,dy=7;
 int f;
 int enemypassed=0,enemypassed2=0;

int ey[6] = {600, 1500, 700, 1000, 1100, 1600};


int ex[6] = {0, 150, 300, 450, 600, 750};


int by[6] = {585, 1500, 700, 1000, 1100, 1600};


int bx[6] = {35, 150, 300, 450, 600, 750};

int life=0;


int bossbulletX =500, bossbulletY = 400 , bossbulletdx=10;
int bossX = 400 , bossY = 400 , ddx=10;
int bossTimer;


int bossbulletTimer;
int win=0;

int heroBulletTimer;

int dflag=0,points1=0;

/*
 function iDraw() is called again and again by the system.

 */

void drawTextBox()//name inputing box for scores
{
	iSetColor(150, 150, 150);
	iRectangle(50, 250, 250, 30);
}


void pageChange()
{
	
	if(flag == 13)//user input for showing scores
	{
	
		drawTextBox();
		iSetColor(255, 255, 255);
		iText(55, 260, str);
	}	
	
	if(eflag == 1)//game resuming
	{
		iResumeTimer(ee);		

	}

	if(eflag == 0)//game pausing
	{
		iPauseTimer(ee);		

	}		
	
	if(flag==0){	
		iShowImage(0,0,w,h,image1);//1st page
		iSetColor(0,255,0);
		iText(420,100,"click here to start", GLUT_BITMAP_TIMES_ROMAN_24);
	}
		if(flag==1)
		{
			iShowImage(0,0,w,h,image2);//2nd page
		}

		else if(flag==2 )
		{
			iShowImage(0,0,w,h,image3);//instruction page
		}
	else if(flag==3)
		{

			iShowImage(0,0,w,h,image7);//score page
			read();
			showable();

		}
		else if(flag==4)
		{

			iShowImage(0,0,w,h,image4);//about page

		}
	else if(flag==5)
		{

			exit(0);//exit game from 1st page option

		}
		else if(flag==6)////////////////////////////////////////////////////////////////////////////////////////////level1
		{

			iShowImage(0,0,w,h,image5);//level 1 background
			
			for(i=0;i<6;i++){
				iShowImage(ex[i],ey[i],80,80,plane2);//enemy			
			}
			
			iShowImage(p1x,p1y,100,100,plane1);//player
			
			//iText(100,100,"press b to complete level1");
			point = (enemyPassedCounter*10)-(collisionCounter*2);
			collisionCounter=0;
			
			char scoreText[6];
			sprintf(scoreText,"%d",point);
			//iText(100,100,"press d to complete level2");
			iSetColor(255,255,255);
			iText(900,545,scoreText, GLUT_BITMAP_TIMES_ROMAN_24);

		}	
	else if(flag==7)
		{

			iShowImage(0,0,w,h,image9);//level 1 complete 
			iText(100,100,"press next to move to level2 or exit to move to mainmenu");

		}
		else if(flag==8)////////////////////////////////////////////////////////////////////////////level2
		{

			iShowImage(0,0,w,h,image6);//level 2 background
			iShowImage(heroBulletX,heroBulletY,40,40,bullet);//herobullet
			for(i=0;i<6;i++){
				iShowImage(ex[i],ey[i],80,80,plane2);//enemy			
			}
			for(i=0;i<6;i++){
				iShowImage(bx[i+1]+35,by[i+1]-15,20,20,bossbullet);//bullet
			}			
			iShowImage(p1x,p1y,70,70,plane1);//player

			point = (enemyPassedCounter*10)-(collisionCounter*2);
			collisionCounter=0;
			char scoreText[6];
			sprintf(scoreText,"%d",point);
			
			iSetColor(255,255,255);
			iText(900,545,scoreText, GLUT_BITMAP_TIMES_ROMAN_24);
			

		
		}
	else if(flag==9)
		{

			iShowImage(0,0,w,h,image10);//level 2 complete
			iText(100,100,"press next to move to level3 or exit to main menu");
		}

    else if(flag==10)/////////////////////////////////////////////////////////////////////////////////////////////////////level3
		{

			iShowImage(0,0,w,h,image8);//level 3  background
			iShowImage(bossX,bossY,200,200,image13);//boss
			
			iShowImage(bossbulletX,bossbulletY,40,40,bossbullet);//bossbullet

			iShowImage(heroBulletX,heroBulletY,40,40,bullet);//herobullet
			iShowImage(p1x,p1y,100,100,plane1);//player


		

			point = enemyPassedCounter*10-collisionCounter*5;
			char scoreText[6];
			sprintf(scoreText,"%d",point);
			
			iSetColor(255,255,255);
			iText(900,545,scoreText, GLUT_BITMAP_TIMES_ROMAN_24);


		}
	else if(flag==11)
		{

			iShowImage(0,0,w,h,image11);//final level complete
			
		}
}
void bossMovement()//1st enemy movement
{
	bossX +=ddx;
	if(bossX<=0 || bossX>=800)
		ddx = -ddx;
}
void enemyMovement()//enemy movement
{ if(flag==8||flag==6){
	for(i=0;i<6;i++){
	ey[i]-=dy;
	if(ey[i]<=0)
	{
		enemyPassedCounter++;
		ey[i]=h;
		enemypassed++;
		enemypassed2++;
		if(enemypassed==10&&flag==6)
		{
			flag=7;
		}
		else if(enemypassed2==25&&flag==8)
		{
			flag=9;
		}
	}
	}
}

}

void bulletMovement()//bullet movement
{
	if(flag==8){
	for(i=0;i<6;i++){
	by[i]-=bby;
	if(by[i]<=0)
	{
		by[i]=ey[i];

	}
}
	}
}

void bossBullet()//bullet movement
{
	
	 bossbulletY-=bossbulletdx;
	if (bossbulletY<=0)
	{
		 bossbulletY=bossY;
		  bossbulletX=bossX+100;

	}

}








void heroBullet()
{
if(flag==10||flag==8){
	if(f==1){
	
	heroBulletY+=dz;
	if(heroBulletY>=600)
	{

		heroBulletY=p1y;
		heroBulletX=p1x;
		f=0;

	}
}
}
}
void winGame()
{
	if((heroBulletX>=bossX)&&(heroBulletX<=bossX+200)&&(heroBulletY>=bossY)&&(heroBulletY<=bossY+200))
	{
		win++;
		
		enemyPassedCounter++;

	}
	if(win==1)
	{
		flag=11;
	}

}
void hitEnemy()
{for(i=0;i<6;i++){
	if((heroBulletX>=ex[i] && heroBulletX<=ex[i]+80) && (heroBulletY+80>=ey[i] && heroBulletY+80<=ey[i]+80) )
	{
		

		enemyPassedCounter++;
		ey[i]=h;


	}
	
}
}
void iDraw()
{
	//place your drawing codes here
	iClear();
	

	hitEnemy();//function call for hitting enemy
	

	pageChange();//function call for pages

	heroMovemet();//function call from header
	if(flag==10)
	{
		winGame();
	}
	/////////////////***********************************************************************///////////////////////////////////////////////////////
	
	//collision and life increment logics
	if(flag == 6 || flag == 8){
		
		for(i=0;i<6;i++){
			
			if(life>350)
			{

	break;

			}
	if( (p1x>=ex[i] && p1x<=ex[i]+80) && (p1y+80>=ey[i] && p1y+80<=ey[i]+80)    )
	{
		
			life++;
			ey[i+1] = h;
			
			collisionCounter++;
			
		
	}
	else if(ey[0]<=0 || ey[1]<=0 ||ey[2]<=0 || ey[3]<=0 ||ey[4]<=0 || ey[5]<=0){
		
		point=point+10;
		}
	}
	
		}
	if(flag==10)
	{
		if((bossbulletX>=p1x)&&(bossbulletX<=p1x+100)&&(bossbulletY>=p1y)&&(bossbulletY<=p1y+100))
			life++;
		collisionCounter++;

	}

	if (flag==8)
	{
		for(i=0;i<6;i++){
		 if((bx[i]>=p1x)&&(bx[i]<=p1x+100)&&(by[i]>=p1y)&&(by[i]<=p1y+100))
		
	{
		
			
			by[i] =ey[i];
			printf("hit");

			collisionCounter++;
	
		
	}
		}
	}

	
	
	
	if(level1==10)
	{
		flag=7;
	}
	
	
	if(life>300)//level ending condition

	{
		flag = 13;
		eflag = 0;
		life = 0;
	}
	
}

void iPassiveMouse(int x, int y)
{
	;
}

/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
	
	//place your codes here
}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
			//printf("x = %d, y= %d\n",mx,my);
		printf("x = %d, y= %d\n", mx, my);
	if(mx>=422 && mx<=601 && my>=101 && my<=122 && flag==0)//main menu page
    	{		
			flag=1;
		}
	if(mx>=23 && mx<=243 && my>=16 && my<=95 && flag==1)//instruction
		{
			flag=2;				
		}

 if(mx>=266 && mx<=482 && my>=16 && my<=95 && flag==1)//score
		{
			flag=3;
		}
 if(mx>=512 && mx<=726 && my>=16 && my<=95 && flag==1)//about
		{
			flag=4;
		}
 if(mx>=750 && mx<=1328 && my>=16 && my<=95 && flag==1)//exit
		{
			flag=5;
		}
 if(mx>=801 && mx<=939 && my>=41 && my<=93 && flag==2)//insback
		{
			flag=1;
		}
 if(mx>=801 && mx<=939 && my>=41 && my<=93 && flag==4)//aboutbackoption
		{
			flag=1;
		}

 if(mx>=801 && mx<=939 && my>=41 && my<=93 && flag==3)//scorebackoption
		{
			flag=1;
		}
 if(mx>=389 && mx<=626 && my>=389 && my<=540 && flag==1)//play
		{
			flag=6;
			eflag = 1;
		}
 if(mx>=173 && mx<=432 && my>=192 && my<=374 && flag==7)//level 1 exit option
		{
			flag=1;
		}
 if(mx>=552 && mx<=812 && my>=293 && my<=377 && flag==7)//level 1 next option
		{
			flag=8;
		}

 if(mx>=213 && mx<=476 && my>=294 && my<=376 && flag==9)//level 2 exit option
		{
			flag=1;
		}
 if(mx>=540 && mx<=803 && my>=294 && my<=378 && flag==9)//level 2 next option
		{
			flag=10;
		}



	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		
	}
}

/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
	
	
	if(key == ' ' &&( flag == 10 ||flag == 8 ))
	{
		f=1;
		if(f==1){
			heroBulletTimer = iSetTimer(10, heroBullet);}
	}


	
	int i;
	//name inputting condition for scores
	if(flag == 13)
	{
        if(key == '\r')//if enter is pressed after giving a name in testbox it come back to the menu page
		{
			
			strcpy(pname, str);
			printf("%s\n", str2);
			for(i = 0; i < len; i++)
		    str[i] = 0;
			flag = 1;
			len = 0;
		
		}
		else
		{
			str[len] = key;
			len++;
		}


}
}

/*
 function iSpecialKeyboard() is called whenver user hits special keys like-
 function keys, home, end, pg up, pg down, arraows etc. you have to use
 appropriate constants to detect them. A list is:
 GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
 GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
 GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
 GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
 */
void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_LEFT)//player movement speed
	{
		p1x-=p1s;
			heroBulletX-=p1s;
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		p1x+=p1s;
		heroBulletX+=p1s;
	}
	else if (key == GLUT_KEY_UP)
	{
		p1y+=p1s;
		heroBulletY+=p1s;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		p1y-=p1s;
		heroBulletY-=p1s;
	}
	
	//place your codes for other keys here
}

//structure for inputing name and scores
struct Player {
	char player_name [30];
	int score;

    Player(){
		strcpy(player_name, "kabir");
		score = 0;
	}

	
	Player(char* pn, int _score)
	  {
		strcpy(player_name,pn);
		score = _score;
	  }

	Player(char* pn1)
	  {
		strcpy(player_name,pn1);
		score = 0;
	  }

	char* getPlayerName(){
		return player_name;
	}

	void setPlayerName(char* _player_name){
		strcpy(player_name, _player_name);
	}

	int getScore(){
		return score;
	}

	void setScore(int _score){
		score = _score;
	}

};

Player winner[10];

void read()
{
	//reading name and scores from the text file
	FILE *fp = fopen("score.txt", "r");
	for(int i=0; i<5; i++){
		char s[30];
		int sc;
		fscanf(fp, "%s %d", s, &sc);
		winner[i].setPlayerName(s);//putiing name in structure type array
		winner[i].setScore(sc);////putiing score in structure type array
	}
	winner[5].setPlayerName(pname);
		winner[5].setScore(point);

	fclose(fp);
	int temp;
	
	//bubble sorting the score in higher order
	for(int i=0; i<6; i++){
		for(int j=i+1; j<6; j++){
			if(winner[i].getScore() <winner[j].getScore()){
				/*swap(topPlayers[j].score ,topPlayers[j+1].score );
				swap(topPlayers[j].player_name ,topPlayers[j+1].player_name);*/

				temp = winner[i].score ;
				winner[i].score = winner[j].score ;
				winner[j].score = temp;

				strcpy(nameShow, winner[i].player_name);
				strcpy(winner[i].player_name, winner[j].player_name);
				strcpy(winner[j].player_name, nameShow);

			}
		}
	}
	
 


}
//showing name and score in the games score page
void showable(){


	
	sprintf(nameShow, "%s", winner[0].getPlayerName());//will take playes name from winner array to s
		iText(158, 350,nameShow, GLUT_BITMAP_TIMES_ROMAN_24);//will show players name in score page

		sprintf(nameShow, "%d", winner[0].getScore());
		iText(700, 350,nameShow, GLUT_BITMAP_TIMES_ROMAN_24);



	sprintf(nameShow, "%s", winner[1].getPlayerName());
		iText(158, 310, nameShow, GLUT_BITMAP_TIMES_ROMAN_24);

		sprintf(nameShow, "%d", winner[1].getScore());
		iText(700, 310,nameShow, GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf(nameShow, "%s", winner[2].getPlayerName());
		iText(158, 270, nameShow, GLUT_BITMAP_TIMES_ROMAN_24);

		sprintf(nameShow, "%d", winner[2].getScore());
		iText(700, 270,nameShow, GLUT_BITMAP_TIMES_ROMAN_24);


	sprintf(nameShow, "%s", winner[3].getPlayerName());
		iText(158, 230, nameShow, GLUT_BITMAP_TIMES_ROMAN_24);

		sprintf(nameShow, "%d", winner[3].getScore());
		iText(700, 230,nameShow, GLUT_BITMAP_TIMES_ROMAN_24);



	sprintf(nameShow, "%s", winner[4].getPlayerName());
		iText(158, 190, nameShow, GLUT_BITMAP_TIMES_ROMAN_24);


		sprintf(nameShow, "%d", winner[4].getScore());
		iText(700, 190,nameShow, GLUT_BITMAP_TIMES_ROMAN_24);



		sprintf(nameShow, "%s", winner[5].getPlayerName());//user input player name
		iText(158, 150, nameShow, GLUT_BITMAP_TIMES_ROMAN_24);

	    sprintf(nameShow, "%d", winner[5].getScore());//new player score
		iText(700, 150, nameShow, GLUT_BITMAP_TIMES_ROMAN_24);

}



int main()
{
	read();
	

	//enemy movement timing
	ee = iSetTimer(58,enemyMovement);
	bb = iSetTimer(30,bulletMovement);	
	bossTimer = iSetTimer(20, bossMovement);
	bossbulletTimer = iSetTimer(70, bossBullet);

	iInitialize(1000, 600, "Demo");
	image1=iLoadImage("images\\plane1.png");//1st page
	image2=iLoadImage("images\\plane2.png");//2nd page
	image3=iLoadImage("images\\instruction.png");//instruction page
	image4=iLoadImage("images\\about.png");//about us page
	image5=iLoadImage("images\\level1.png");// level 1 background
	image6=iLoadImage("images\\level2.png");//level 2 background
	image7=iLoadImage("images\\score.png");//score page
	image8=iLoadImage("images\\level3.png");//level 3 background
    image9=iLoadImage("images\\after1.png");//level 1 complete
	image10=iLoadImage("images\\after2.png");//level 2 complete
	image11=iLoadImage("images\\finallevel.png");
	image12=iLoadImage("images\\after2.png");
	image13=iLoadImage("images\\bossfinal.png"); //boss
	
	plane1=iLoadImage("images\\hero.png");//air fighter(hero)
    plane2=iLoadImage("images\\enemy.png");
	bullet=iLoadImage("images\\heroBullet.png");//bullet
	bossbullet=iLoadImage("images\\bossBullet.png");//bossbullet
	
	iStart(); // it will start drawing

	return 0;
}