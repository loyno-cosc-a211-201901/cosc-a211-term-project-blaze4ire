//Program Name: Candy Land
/*Purpose:  Two player game of candy land first one to 40 wins!*/
//Author: Justin Hunter
//Date Last Modified: April 25, 2019
#include <iostream>
using namespace std;

string start_game;
int p1_position;
int p2_position;
int roll;
int current_player = 1;
int cardnumber;


//rolls dice function
void rolling_dice(){
  unsigned seed;
  seed = time(0);
  srand(seed);
//random nubmer between 1-3
  roll = rand() % (3 - 1 + 1) + 1;
//rolls a 1
  if(roll == 1){
  cout << "You rolled a " << roll << endl;
  }
//rolls a 2
  else if (roll == 2){
    cout << "You rolled a " << roll << endl;
  }
//rolls a special or back to 1 or 2
  else if (roll == 3){
    //special roll
    if(cardnumber != 5) {
        int roll2;
        roll2 = rand() % (2 - 1 + 1) + 1;
        //steel mill roll
        if(roll2 == 1){
          if(current_player == 1){
            p1_position = 10;
            roll = 0;
          }else if(current_player == 2){
            p2_position = 10;
            roll = 0;
          }
          cout << "You rolled steel mell!" << endl;
        }else if (roll2 == 2){
          //tool shed roll
          if(current_player == 1){
            p1_position = 35;
            roll = 0;
          } else if(current_player == 2){
            p2_position = 35;
            roll = 0;
          }
          cout << "You rolled tool shed!" << endl;
        }
        cardnumber++;
        cout << "Special rolls left: " << 5 - cardnumber << endl;
      } else if(cardnumber == 5){
      roll = rand() %(2 - 1 + 1) + 1;
      cout << "You rolled a " << roll << endl;
    }
  }
}
void player_move(){
  if(current_player == 1){
    p1_position = p1_position + roll;
  } else if(current_player == 2){
    p2_position = p2_position + roll;
  }
}
void player_position(){
  cout << "Player 1: " << p1_position << endl;
  cout << "Player 2: " << p2_position << endl;
}
void player_turn(){
  int choice;
  cout << "Player " << current_player << " turn:" << endl;
  cout << "1. Roll dice" << endl;
  cin >> choice;
  if (choice == 1){
    rolling_dice();
  }
}
void switch_player(){
  if (current_player == 1) {
    current_player = 2;
  } else {
    current_player = 1;
  }
}
bool check_win(){
  if(p1_position >= 40 || p2_position >= 40){
    return true;
  } else {
    return false;
  }
}

bool play_again(){
  int playAgain;
  cout << "Do you want to play again? 1(Y)/2(N): ";
  cin >> playAgain;
  if(playAgain == 1){
    return true;
  } else if(playAgain == 2){
    return false;
  }
}

void startGame(){
  p1_position = 0;
  p2_position = 0;
  current_player = 1;
  cardnumber = 0;
  do{
  player_position();
  player_turn();
  player_move();
  check_win();
  switch_player();
  } while(check_win()!= true);
  cout << "Player " << current_player << " wins!" << endl;
  cout << "game over" << endl;
  play_again();
}



int main() {
  cout << "Welcome to Candy land?" << endl;
  cout << "Start Game Y/N?";
  cin >> start_game;
  if (start_game == "Y" || start_game == "y" ) {
      startGame();
    } else {
    return 0;
  }
  play_again();
  if (play_again() == true){
    startGame();
  } else
  {
    return 0;
  }
}
