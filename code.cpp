#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100], nTail;
char dir;
void Setup()
	{
	gameOver = false;
	dir = 'S';
	x = width/2;
	y = height/2;
	randomize();
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
	}

void Draw()
	{
	clrscr();
	for(int i = 0; i < width + 2; i++)
		cout<< "#";
	cout << endl;
	for(int i = 0; i < height; i++)
		{
   	for (int j = 0; j<width; j++)
      	{
			if( j == 0)
				cout << "#";
			if(i == y &&  j == x)
				cout << "O";
			else
         	if(i == fruitY && j == fruitX)
					cout << "F";
				else
         	{
            	bool print = false;
					for (int k = 0; k < nTail; k++)
						{
						if(tailX[k] == j && tailY[k] == i)
				  			{
              				print = true;
              				cout << "o";
                     }
               	}
            	if(!print)
         			cout <<" ";
            }
         if( j == width - 1)
				cout<< "#";
			}
   	cout<< endl;
		}
	for(int i = 0; i < width+2; i++)
	cout<< "#";
	cout<< endl;
	cout<< score;
	for (int i = 0; i < pow (9, 6);i++);
	}

void Input ()
	{
	if (kbhit ())
		{
   	switch (_getch())
			{
         case 'a':
				dir = 'L';
				break;
			case 'd':
				dir = 'R';
				break;
         case 'w':
				dir = 'U';
				break;
         case 's':
				dir = 'D';
				break;
			case 'x':
				gameOver = true;
				break;
			}
      }
	}

void Logic()
	{
		int prevX=tailX[0], prevY=tailY[0], prev2X,prev2Y;
      tailX[0] = x;
		tailY[0] = y;
      for(int i = 1; i<nTail; i++)
			{
         prev2X = tailX[i];
         prev2Y = tailY[i];
			tailX[i]=prevX;
			tailY[i] = prevY;
			prevX=prev2X;
			prevY = prev2Y;
         }
      switch (dir)
			{
         case 'L':
				x--;
				break;
         case 'R':
				x++;
            break;
         case 'U':
				y--;
				break;
			case 'D':
				y++;
				break;
         }
		if(x	>	width || x	<	0 || y	> height || y	<	0)
			gameOver = true;
		for (int i = 0; i< nTail; i++)
			if (tailX[i] == x && tailY[i] == y)
         	gameOver = true;
      if(x == fruitX && y==fruitY)
			{
				score +=10;
				fruitX =rand() % width;
				fruitY =rand() % height;
				nTail++;
         }
	}

int main ()
	{
   Setup();
   while (!gameOver)
		{
		Draw ();
		Input ();
		Logic ();
		}
	cout<<"GAME OVER\n YOU SCORED:"<< score << "POINTS";
	getch();
	return 0;
	}
