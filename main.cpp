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

bool checkVert(){
  bool rhubarb;
  int col[6];
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 7; j++){
      col[j] = board[j][i];
    }
    for(int b = 0; b < 4; b++){
      if(col[b] == col[b+1] && col[b+2] && col[b+3]){
        rhubarb = true;
        break;
      } else {
        rhubarb = false;
      }
    }
  }
  return rhubarb;
}

bool checkHoriz(){
  bool bruh;
  int row[7];
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 7; j++){
      row[j] = board[i][j];
    }
    for(int l = 0; l < 4; l++){
      if(row[l] == row[l+1] && row[l+2] && row[l+3]){
        bruh = true;
        break;
      } else {
        bruh = false;
      }
    }
  }
  return bruh;
}

bool checkRightDiag(){
  return false;
}

bool checkLeftDiag(){
  return false;
}

bool winCheck(){

  if(checkVert() == true || checkHoriz() == true || checkRightDiag() == true || checkLeftDiag() == true){
    return true;
  } else {
    return false;
  }
}

void displayBoard(int x[6][7]){
  cout<< "1\t2\t3\t4\t5\t6\t7\n";
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

bool playerOneTurn(){
  int playerChoice;
  
  cout << "Player 1's turn: ";
  cin >> playerChoice;

  for(int i = 5; i < 6; i--){
    if(board[i][playerChoice-1] == 0){
      board[i][playerChoice-1] = 1;
      break;
    } else if(board[i][playerChoice-1] != 1){
      board[i + 1][playerChoice-1] = 1;
    }
  }
  
  displayBoard(board);
  winCheck();
  return winCheck();
}

bool playerTwoTurn(){
  int playerChoiceTwo;
  
  cout<<"Player 2's turn: ";
  cin>>playerChoiceTwo;

  for(int i = 5; i < 6; i--){
    if(board[i][playerChoiceTwo-1] == 0){
      board[i][playerChoiceTwo-1] = 2;
      break;
    } else if(board[i][playerChoiceTwo-1] != 2) {
      board[i+1][playerChoiceTwo-1] = 2;
    }
  }

  displayBoard(board);
  winCheck();
  return winCheck();
}

void game(){
  
  while(winCheck() == false){
    playerOneTurn();
    if(winCheck() == false){
      playerTwoTurn();
    }
  }

  cout<<"chamblergrambl";
  
  
}

int main() {

  game();

}