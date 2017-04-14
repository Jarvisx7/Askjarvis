#include <termios.h>
#include <stdio.h>
#include<string.h> 
#include<stdlib.h>
void gotoxy(int x,int y)
 {
 printf("%c[%d;%df",0x1B,y,x);
 }
static struct termios old, new;
 
/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); //grab old terminal i/o settings
  new = old; //make new settings same as old settings
  new.c_lflag &= ~ICANON; //disable buffered i/o
  new.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
  tcsetattr(0, TCSANOW, &new); //apply terminal io settings
}
 
/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}
 
/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}
 
/* 
Read 1 character without echo 
getch() function definition.
*/
char getch(void) 
{
  return getch_(0);
}
 
/* 
Read 1 character with echo 
getche() function definition.
*/
char getche(void) 
{
  return getch_(1);
}
 
int main(void) 
{
  char pass[5];
  char pass1[6];
 char pass2[5];
char x[21]="Jarvis,please answer:";
int j=0;
int count=0;
char ch='a';
	int i=0;
	printf("\n\n Pass : ");
	pass[0]=getch();
	while(j<21)
	{
		i++;
		printf("%c",x[j]);
		j++;
		if(pass[i-1]=='.'||ch!='.')
		{      if(pass[i-1]=='.')
			 ch='.';
	    		pass[i]=getch();
			count++;
		}
		else
		pass1[i-1]=getch();
	}
		
	printf("\n\n");
	gotoxy(50,15);	
	printf("HELLO I AM JARVIS \n");
	gotoxy(50,16);
	printf("ENTER YOUR QUESTION I CAN ANSWER ANYTHING \n");
	gotoxy(40,20);
	scanf("%s",pass2);
	gotoxy(40,21);
	for(i=0;i<count-1;i++)
	{
	printf("%c",pass[i]);
	}
	printf("\n\n");
  return 0;
}
