#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char col,row;
char turn='X';
int draw=1;
void display()
{
  
 std:: cout<<"\t\t\t\tTICK_TAC_TOE_GAME\n";
 std:: cout<<"--------------------------------------------------------------------------------\n\n";
 std:: cout<<"PLAYER-1 [X] \nPLAYER-2 [O]\nEXIT-10\n\n";
  std::cout<<"\t\t\t\t"<<"     |     |     <<\n";
  std::cout<<"\t\t\t\t"<<"  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"\n";
 std:: cout<<"\t\t\t\t"<<"-----|-----|-----"<<"\n";
  std::cout<<"\t\t\t\t"<<"  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"<<\n";
  std::cout<<"\t\t\t\t"<<"-----|-----|-----"<<"<<\n";
  std::cout<<"\t\t\t\t"<<"  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"<<\n";
  std::cout<<"\t\t\t\t"<<"     |     |     "<<"<<\n";
}


void player()
{
  int choice;

  if(turn=='X')
  {
     std::cout<<"\nPlayer 1 [X] Enter a number:->";
  }
  else if(turn=='O'){
     std::cout<<"\nPlayer 2 [O] Enter a number:->";
  }
  std::cin>>choice;
  switch(choice)
  {
    case 1:row=0; col=0;break;
    case 2:row=0; col=1;break;
    case 3:row=0; col=2;break;
    case 4:row=1; col=0;break;
    case 5:row=1; col=1;break;
    case 6:row=1; col=2;break;
    case 7:row=2; col=0;break;
    case 8:row=2; col=1;break;
    case 9:row=2; col=2;break;
    case 10:exit(10);break;
    default:
	  std::cout<<"\n\n\t\t\t[ ERROR: !Invalid choice ]";
	  break;
  }
  if(turn=='X' && board[row][col]!='X' && board[row][col]!='O')
  {
     board[row][col]='X';
     turn='O';
  }
  else if(turn=='O' && board[row][col]!='X' && board[row][col]!='O')
  {
     board[row][col]='O';
     turn='X';
  }
  else
  {
    std::cout<<"\n\t\t\tBox already filed..please try again..."<<"<<\n";
    player();
  }
}

int game_over()
{
  //game win
  for(int i=0;i<3;i++)
  {
     if(board[i][0]==board[i][1] && board[i][0]==board[i][2] ||
	board[0][i]==board[1][i] && board[0][i]==board[2][i])
     {
	return 0;
     }
     else if(board[0][0]==board[1][1] && board[0][0]==board[2][2] ||
     board[0][2]==board[1][1] && board[0][2]==board[2][0])
     {
	 return 0;
     }
  }

  //check box empty
  int i;
  for(i=0;i<3;i++)
     for(int j=0;j<3;j++)
       if(board[i][j]!= 'X' && board[i][j]!= 'O')
	  return 1;

  //game draw

     std:: cout<<"Game is draw";
      getch();
      return 0;
}
int main()
{

   while(game_over())
   {
      display();
      player();
      game_over();
      display();
   }

   if(turn=='O')
      std::cout<<"\n\n\t\tPLAYER-1 [X] WIN GAME"<<"<<\n";
   else if(turn=='X')
    std::cout<<"\n\n\t\tPLAYER-2 [O] WIN GAME";

   getch();
   return 0;
}