#include <iostream>
using namespace std;

int board[6][7] = {
                    {0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0}
};

void displayBoard(int x[6][7]){
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 7; j++){
      if(x[i][j] == 1){
        cout<<"o\t";
      } else if (x[i][j] == 2){
        cout<<"x\t";
      } else {
        cout<< "-\t";
      }
    }
    cout<<'\n';
  }
  cout<<'\n';
} 

void game(){
  
  int playerChoice;
  int playerChoiceTwo;
  
  cout << "Player 1's turn: ";
  cin >> playerChoice;

  for(int i = 5; i < 6; i--){
    if(board[i][playerChoice-1]==0){
      board[i][playerChoice-1] = 1;
      break;
    } else {
      board[i+1][playerChoice-1] = 1;
    }
  }
  
  displayBoard(board);
  
  cout<<"Player 2's turn: ";
  cin>>playerChoiceTwo;

  for(int i = 5; i < 6; i--){
    if(board[i][playerChoiceTwo-1]==0){
      board[i][playerChoiceTwo-1] = 2;
      break;
    } else {
      board[i+1][playerChoiceTwo-1] = 2;
    }
  }

  displayBoard(board);
  
  game();
  
}