/*Tic tac toe (AI and multiplayer)
 * Damian Escobedo
 * 
 * status: Release
 * Finished at 04/24/2015 11:03 pm
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>


using namespace std;
//prototypes
void Set_position(char board[3][3]);
void Display_board(char board[3][3]);
bool CanWinInRow(char board[3][3], int row, char player);
bool CanWinInColumn(char board[3][3], int column, char player);
bool CanWinInDiagTopLeft(char board[3][3], char player);
bool CanWinInDiagBottomLeft(char board[3][3], char player);
char GetTopLeft(char board[3][3], int cell);
char GetBottomLeft(char board[3][3], int cell);
//char GetInRow(char board[3][3], int row);
//global variables
bool valid_movement;
int Game_mode;
int turn=1;


int main(void){
    char board[3][3];
    int free_slots;
    bool winner=false;
    
     srand (time(NULL));
    /*this assigns the postion of the borad numbers form the 1 to in ASCII 
     * for an easier tranformation to 'X' an 'O'
    */
    for(int i=0, n=49; i < 3; i++)
    {
        for(int j=0; j < 3; j++, n++)
        {
            board[i][j]=n;
        }
    }  
    do
    {
        cout.flush();
        cout  << "how do you what to play" << endl;
        cout << "Enter '1' for player vs player" << endl;
        cout << "Enter '2' for player vs CPU" << endl;
        cin >> Game_mode;
        cin.ignore();

    }while (Game_mode != 1 && Game_mode != 2);
        
    cout << "This is the tic tac board \n";
    
    Display_board(board);
    
    do
    {
        Set_position(board);
    
        Display_board(board);
        
        free_slots = 9;
        for(int i=0, n=49; i < 3 && winner==false; i++)
        {
            if(board[i][0]==board[i][1] && board[i][0]==board[i][2])
            {
                winner=true;
                cout << "The " << board[i][0] << " has won\n GAME OVER" << endl;
            }
            
            if(board[0][i]==board[1][i] && board[0][i]==board[2][i])
            {
                winner=true;
                cout << "The " << board[0][i] << " has won\n GAME OVER" << endl;
            }
            
            if(board[0][0]==board[1][1] && board[0][0]==board[2][2])
            {
                winner=true;
                cout << "The " << board[0][0] << " has won\n GAME OVER" << endl;
            }
            
            if(board[2][0]==board[1][1] && board[2][0]==board[0][2])
            {
                winner=true;
                cout << "The " << board[2][0] << " has won\n GAME OVER" << endl;
            }
            
            //counts free slot
            for(int j=0; j < 3; j++, n++)
            {
                if(board[i][j] != n)
                    free_slots--;
            }
        }
         //check for free slots
        if(free_slots <= 0)
            cout << "Draw!\n GAME OVER" << endl;
        
    }while(winner==false && free_slots > 0);
    
    cin.ignore();
    cin.get();
    
    //return 0;
}
/**
 * Sets the 'X' or the 'O' in it's place of the board
 */
void Set_position(char board[3][3])
{
    int position;
    
    valid_movement=false;
    
        do
        {   //checks if the palyer will make the move or the computer
            if(turn==1 || (Game_mode==1 && turn==0))
            {
                cout << "where would you like to place your piece? ";
                cin >> position;
            }
            
            else //checks if there is two X or two O with the posibility of winning
                //if there is true makes the move there, else, makes a random move 
            {   
                bool Cpu_CanWin=false;
                for(int i=0, movementMade=0; i < 3; i++){
                    
                    //checks if the user can win
                    if(CanWinInDiagBottomLeft(board, 'X') && Cpu_CanWin==false)
                    {
                        if(board[2][0]!='X' &&  board[2][0]!='O')
                        {
                            position = board[2][0]-48;
                            movementMade=1;
                        }
                        if(board[1][1]!='X' &&  board[1][1]!='O')
                        {
                            position = board[1][1]-48;
                           movementMade=1;
                        }
                        if(board[0][2]!='X' &&  board[0][2]!='O')
                        {
                            position= board[0][2]-48;
                            movementMade=1;
                        }
                    }
                        
                    if(CanWinInDiagTopLeft(board, 'X') && Cpu_CanWin==false)
                    {
                        if(board[0][0]!='X' &&  board[0][0]!='O')
                        {
                            position = board[0][0]-48;
                            movementMade=1;

                        }
                        if(board[1][1]!='X' &&  board[1][1]!='O')
                        {
                            position = board[1][1]-48;
                            movementMade=1;
                        }
                        if(board[2][2]!='X' &&  board[2][2]!='O')
                        {
                            position = board[2][2]-48;
                            movementMade=1;
                        }
                    }
                    
                    if(CanWinInColumn(board, i, 'X') && Cpu_CanWin==false)
                    {
                        if(board[0][i]!='X' &&  board[0][i]!='O')
                        {
                            position=board[0][i]-48;
                            movementMade=1;
                        }
                        if(board[1][i]!='X' &&  board[1][i]!='O')
                        {
                            position=board[1][i]-48;
                            movementMade=1;
                        }
                        if(board[2][i]!='X' &&  board[2][i]!='O')
                        {
                            position=board[2][i]-48;
                            movementMade=1;
                        }
                    }
                    
                    if(CanWinInRow(board, i, 'X') && Cpu_CanWin==false)
                    {
                        if(board[i][0]!='X' &&  board[1][0]!='O')
                        {
                            position=board[i][0]-48;
                            movementMade=1;
                        }
                        if(board[i][1]!='X' &&  board[i][1]!='O')
                        {
                            position=board[i][1]-48;
                           movementMade=1; 
                        }
                        if(board[i][2]!='X' &&  board[i][2]!='O')
                        {
                            position=board[i][2]-48;
                            movementMade=1;
                        }
                    }
                    
                    //checks if CPU can win
                    if(CanWinInDiagBottomLeft(board, 'O'))
                    {
                        if(board[2][0]!='O' && board[2][0]!='X')
                        {
                            position = board[2][0]-48;
                            movementMade=1;
                            Cpu_CanWin=true;
                        }
                        if(board[1][1]!='O' && board[1][1]!='X')
                        {
                            position = board[1][1]-48;
                            movementMade=1;
                            Cpu_CanWin=true;
                        }
                        if(board[0][2]!='O' && board[0][2]!='X')
                        {
                            position= board[0][2]-48;
                            movementMade=1;
                            Cpu_CanWin=true;
                        }
                    }
                        
                    if(CanWinInDiagTopLeft(board, 'O'))
                    {
                        if(board[0][0]!='O' && board[0][0]!='X')
                        {
                            position = board[0][0]-48;
                            movementMade=1;
                            Cpu_CanWin=true;
                        }
                        if(board[1][1]!='O' && board[1][1]!='X')
                        {
                            position = board[1][1]-48;
                            movementMade=1;
                            Cpu_CanWin=true;
                        }
                        if(board[2][2]!='O' && board[2][2]!='X')
                        {
                            position = board[2][2]-48;
                            movementMade=1;
                            Cpu_CanWin=true;
                        }
                    }
                    
                    if(CanWinInColumn(board, i, 'O'))
                    {
                        if(board[0][i]!='O' && board[0][1]!='X')
                        {
                            position=board[i][0]-48;
                            movementMade=1;
                            Cpu_CanWin=true;
                        }
                        if(board[1][i]!='O' && board[1][i]!='X')
                        {
                            position=board[i][1]-48;
                            movementMade=1;
                            Cpu_CanWin=true;
                        }
                        if(board[2][i]!='O' && board[2][i]!='X')
                        {
                            position=board[i][2]-48;
                            movementMade=1;
                            Cpu_CanWin=true;
                        }
                    }
                    
                    if(CanWinInRow(board, i, 'O'))
                    {
                        if(board[i][0]!='O' && board[i][0]!='X')
                        {
                            position=board[i][0]-48;
                            movementMade=1;
                            Cpu_CanWin=true;
                        }
                        if(board[i][1]!='O' && board[i][1]!='X')
                        {
                            position=board[i][1]-48;
                            movementMade=1;
                            Cpu_CanWin=true;
                        }
                        if(board[i][2]!='O' && board[1][2]!='X')
                        {
                            position=board[i][2]-48;
                            movementMade=1;
                            Cpu_CanWin=true;
                        }
                    }
                    
                    if(movementMade==0 && i>=2)
                    { 
                       
                        position = (rand() % 9) +1;
                    }
                    
                }
            }
            for(int i=0;i<3;i++)
            {
                for (int j=0;j<3;j++)
                {
                    if(position+48==board[i][j])
                    {
                        if(turn==1)
                        {
                            board[i][j]='X';
                            turn=0;
                        }
                        else
                        {
                            board[i][j]='O';
                            turn=1;
                        }
                        valid_movement=true;
                    }
                }
            }
            
            if(turn==1 || (Game_mode==1 && turn==0))
                if(valid_movement==false)
                {
                    cout << "Movement not valid, please write a number from the board: ";
                }
            
    }while(valid_movement==false);
    
    return;
}

/*
 * This function shows the current board 
 */
void Display_board(char board[3][3])
{
    cout << endl << endl;
     for(int i=0; i < 3; i++)
     {
        for(int j=0; j < 3; j++)
        {
            cout << board[i][j] << " ";
            
            if(j != 2)
                cout << "| ";
        }
        
        if(i != 2)
        cout << endl << "---------";
        
        cout << endl;
    }
     
     cout <<  endl << endl;
     
     return;
}

bool CanWinInRow(char board[3][3], int row, char player)
{   
    int count=0;
    for(int i=0; i < 3; i++){
                if(board[row][i] == player)
                    count++;
    }
    return count >= 2;
}

bool CanWinInColumn(char board[3][3], int column, char player)
{
    int count=0;
        if(board[0][column] == player)
            count++;
        
         if(board[1][column] == player)
            count++;
        
         if(board[2][column] == player)
            count++;
    
    return count >= 2;
}

bool CanWinInDiagTopLeft(char board[3][3], char player)
{
   int count=0;
    for(int i=0; i < 3; i++)
    {
        if(GetTopLeft(board, i) == player)
            count++;
    }
   
   return count >= 2;
}

char GetTopLeft(char board[3][3], int cell)
{
    if(cell==0)
        return board[0][0];
    if(cell==1)
        return board[1][1];
    if(cell==2)
        return board[2][2];
}

bool CanWinInDiagBottomLeft(char board[3][3], char player)
{
   int count=0;
    for(int i=0; i < 3; i++)
    {
        if(GetBottomLeft(board, i) == player)
            count++;
    }
   
   return count >=2;
}

char GetBottomLeft(char board[3][3], int cell)
{
    if(cell==0)
        return board[2][0];
    if(cell==1)
        return board[1][1];
    if(cell==2)
        return board[0][2];
}

/*char GetInRow(char board[3][3], int row)
{
    if(row)
}*/