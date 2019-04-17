#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED

bool gtl=false;
bool gtr=false;
bool gtu=false;
bool gtd=false;
int bx=0;//player x axis
//int p1y=50;//player y axis
int p1s = 10;//player speed

void bossMovemet()
{
	if(bx<0)
	{
		bx=0;
		gtl=false;
		gtr=false;
		gtu=false;
		gtd=false;
	}
	if(bx>=1000)
	{
		bx=850;
		gtl=false;
		gtr=false;
		gtu=false;
		gtd=false;
	}
	/*if(p1y<=0)
	{
		p1y=0;
		gtl=false;
		gtr=false;
		gtu=false;
		gtd=false;
	}
	if(p1y+150>=600)
	{
		p1y=450;
		gtl=false;
		gtr=false;
		gtu=false;
		gtd=false;
	}*/
}

#endif // !MYHEADER_H_INCLUDED
