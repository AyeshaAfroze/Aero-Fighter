#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED

bool gtl=false;
bool gtr=false;
bool gtu=false;
bool gtd=false;
int p1x=450;//player x axis
int p1y=50;//player y axis
int p1s = 50;//player speed
int heroBulletX=p1x, heroBulletY=p1y,dz=10;

void heroMovemet()
{
	if(p1x<0)
	{
		p1x=0;
		gtl=false;
		gtr=false;
		gtu=false;
		gtd=false;

	}
	if(heroBulletX<0)
	{
		heroBulletX=p1x;
		gtl=false;
		gtr=false;
		gtu=false;
		gtd=false;

	}

	if(p1x+150>=1000)
	{
		p1x=850;
		gtl=false;
		gtr=false;
		gtu=false;
		gtd=false;
	}
	if(heroBulletX+150>=1000)
	{
		heroBulletX=p1x;
		gtl=false;
		gtr=false;
		gtu=false;
		gtd=false;
	}

	if(p1y<=0)
	{
		p1y=0;
		gtl=false;
		gtr=false;
		gtu=false;
		gtd=false;
	}
	if(heroBulletY<=0)
	{
		heroBulletY=p1y;
		//gtl=false;
		//gtr=false;
		//gtu=false;
		//gtd=false;
	}

	if(p1y+150>=600)
	{
		p1y=450;
		gtl=false;
		gtr=false;
		gtu=false;
		gtd=false;
	}

	if(heroBulletY>=600)
	{
		heroBulletY=p1y;
		//gtl=false;
		//gtr=false;
		//gtu=false;
		//gtd=false;
	}
}

#endif // !MYHEADER_H_INCLUDED
