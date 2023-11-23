#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>
#include<windows.h>
using namespace std;
// Structure to store player scores
struct scoredetail
{
  string name;
  int wins;
};

// Global variables
string boxes = { '0','1','2','3','4','5','6','7','8','\0' };
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// Function to set the cursor position
void gotoxy(short x, short y) {
  COORD pos = { x, y };
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// Function to display the welcome page
void  welcome_page() {
  SetConsoleTextAttribute(hConsole, 7);
  gotoxy(5, 6);
  cout << "######################################################################" << endl;
  gotoxy(5, 7);
  cout << "#                                                                    #" << endl;
  gotoxy(5, 8);
  cout << "#                                                                    #" << endl;
  gotoxy(5, 9);
  cout << "#                              WELCOME                               #" << endl;
  gotoxy(5, 10);
  cout << "#                             TO X-O GAME                            #" << endl;
  gotoxy(5, 11);
  cout << "#                                                                    #" << endl;
  gotoxy(5, 12);
  cout << "#                                                                    #" << endl;
  gotoxy(5, 13);
  cout << "#                                                                    #" << endl;
  gotoxy(5, 14);
  cout << "######################################################################" << endl;

  gotoxy(5, 16);
  system("pause");
  system("CLS");
  //-----------------------------------------------------------------------------------------------------------------------
}
//// Function to display the main menu
void menu() {
  SetConsoleTextAttribute(hConsole, 11);
  cout << "********************************" << endl;
  cout << "|1.PLAY                  |\n";
  cout << "|2.SCORES                |\n";
  cout << "|3.EXIT                  |\n";
  cout << "********************************" << endl;
  cout << "|CHOICE- ";
}
//function to display the gaming board
void display(string& boxes) {
  gotoxy(6, 1);
  SetConsoleTextAttribute(hConsole, 9);
  cout << "*****************************************************" << endl;
  gotoxy(6, 2);
  cout << "                      X-O GAME                       " << endl;
  gotoxy(6, 3);
  cout << "*****************************************************" << endl;
  SetConsoleTextAttribute(hConsole, 10);
  gotoxy(15, 6);
  cout << "        |" << "        |" << endl;
  gotoxy(15, 7);
  cout << boxes[0] << "       | " << boxes[1] << "      | " << boxes[2] << endl;
  gotoxy(15, 8);
  cout << "________" << "|" << "________" << "|" << "_________" << endl;
  gotoxy(15, 9);
  cout << "        |" << "        |" << endl;
  gotoxy(15, 10);
  cout << boxes[3] << "       | " << boxes[4] << "      | " << boxes[5] << endl;
  gotoxy(15, 11);
  cout << "________" << "|" << "________" << "|" << "_________" << endl;
  gotoxy(15, 12);
  cout << "        |" << "        |" << endl;
  gotoxy(15, 13);
  cout << boxes[6] << "       | " << boxes[7] << "      | " << boxes[8] << endl;
}
// function to check the winner after every entery and store the result after the winner is find
int checkwinner(string& postions, string name) {
  string messge = name + " WINS";
  if ((postions[0] == postions[1] && postions[1] == postions[2]) || (postions[3] == postions[4] && postions[4] == postions[5])) {
    ifstream file;
    scoredetail t;
    vector<scoredetail>score;
    file.open("bestscore.txt", ios::in);
    int set = 0;
    while (file >> t.name >> t.wins) {
      score.push_back(t);
      if (t.name == name) {
        score.pop_back();
        file.close();
        t.wins = t.wins + 1;
        score.push_back(t);
        set = 1;
      }
    }
    if (set != 1) {
      t.name = name;
      t.wins = 1;
      score.push_back(t);
    }
    ofstream fil;
    fil.open("bestscore.txt", ios::out);
    for (int i = 0;i < score.size();i++) {
      fil << score[i].name << "\t" << score[i].wins << endl;
    }
    fil.close();
    system("cls");
    display(boxes);
    gotoxy(10, 15);
    cout << "\n" << messge << endl;
    system("pause");
    return 0;
  }
  else if ((postions[6] == postions[7] && postions[7] == postions[8]) || (postions[0] == postions[3] && postions[3] == postions[6])) {
    ifstream file;
    scoredetail t;
    vector<scoredetail>score;
    file.open("bestscore.txt", ios::in);
    int set = 0;
    while (file >> t.name >> t.wins) {
      score.push_back(t);
      if (t.name == name) {
        score.pop_back();
        file.close();
        t.wins = t.wins + 1;
        score.push_back(t);
        set = 1;
      }
    }
    if (set != 1) {
      t.name = name;
      t.wins = 1;
      score.push_back(t);
    }
    ofstream fil;
    fil.open("bestscore.txt", ios::out);
    for (int i = 0;i < score.size();i++) {
      fil << score[i].name << "\t" << score[i].wins << endl;
    }
    fil.close();
    system("cls");
    display(boxes);
    gotoxy(10, 15);
    cout << "\n" << messge << endl;
    system("pause");
    return 0;
  }
  else if ((postions[1] == postions[4] && postions[4] == postions[7]) || (postions[2] == postions[5] && postions[5] == postions[8])) {
    ifstream file;
    scoredetail t;
    vector<scoredetail>score;
    file.open("bestscore.txt", ios::in);
    int set = 0;
    while (file >> t.name >> t.wins) {
      score.push_back(t);
      if (t.name == name) {
        score.pop_back();
        file.close();
        t.wins = t.wins + 1;
        score.push_back(t);
        set = 1;
      }
    }
    if (set != 1) {
      t.name = name;
      t.wins = 1;
      score.push_back(t);
    }
    ofstream fil;
    fil.open("bestscore.txt", ios::out);
    for (int i = 0;i < score.size();i++) {
      fil << score[i].name << "\t" << score[i].wins << endl;
    }
    fil.close();
    system("cls");
    display(boxes);
    gotoxy(10, 15);
    cout << "\n" << messge << endl;
    system("pause");
    return 0;
  }
  else if ((postions[0] == postions[4] && postions[4] == postions[8]) || (postions[2] == postions[4] && postions[4] == postions[6])) {
    ifstream file;
    scoredetail t;
    vector<scoredetail>score;
    file.open("bestscore.txt", ios::in);
    int set = 0;
    while (file >> t.name >> t.wins) {
      score.push_back(t);
      if (t.name == name) {
        score.pop_back();
        file.close();
        t.wins = t.wins + 1;
        score.push_back(t);
        set = 1;
      }
    }
    if (set != 1) {
      t.name = name;
      t.wins = 1;
      score.push_back(t);
    }
    ofstream fil;
    fil.open("bestscore.txt", ios::out);
    for (int i = 0;i < score.size();i++) {
      fil << score[i].name << "\t" << score[i].wins << endl;
    }
    fil.close();
    system("cls");
    display(boxes);
    gotoxy(10, 15);
    cout << "\n" << messge << endl;
    system("pause");
    return 0;
  }
  else {
    string boxes = { '0','1','2','3','4','5','6','7','8' };
    int count = 0;
    for (int i = 0;i <= 8;i++) {
      if (postions[i] != boxes[i]) {
        count++;
      }
    }
    if (count == 9) {
      system("cls");
      display(boxes);
      gotoxy(15, 15);
      messge = " DRAW";
      cout << "\n" << messge << endl;
      system("pause");
      return 0;
    }
    else
      return 1;
  }
}

//function to accept the players name and to play the game by taking the numbers and assign 'O' and 'X' to choosen places
int player(string& positions) {
  string player1, player2;
  cin.ignore();
  cout << " PLAYER1 NAME: ";
  getline(cin, player1);
  cout << " PLAYER2 NAME: ";
  getline(cin, player2);
  system("cls");
  for (int i = 0;i < 9;i++) {
    int num;
    system("cls");
    display(positions);
    gotoxy(5, 15);
    cout << player1 << ": ";
    cin >> num;
    positions[num] = 'X';
    display(positions);
    if (checkwinner(positions, player1) == 0) {
      break;
    }
    system("cls");
    display(positions);
    gotoxy(5, 15);
    cout << player2 << ": ";
    cin >> num;
    positions[num] = 'O';
    display(positions);
    if (checkwinner(positions, player2) == 0) {
      break;
    }
  }
  return 0;
};

//to display the scores from the text file
void scores() {
  ifstream file("bestscore.txt");
  scoredetail
    m;
  cout << "NAME   " << " WINS" << endl;
  while (file >> m.name >> m.wins) {
    cout << m.name << "\t" << m.wins << endl;
  }
  file.close();
};
int main() {
  int choice, quit;
  welcome_page();
  menu();
  cin >> choice;
  system("cls");
  switch (choice) {
  case 1:
    quit = player(boxes);
    display(boxes);
    if (quit == 0) {
      return 0;
    }
    break;
  case 2:
    scores();
    break;
  case 3:
    break;
  default:
    cout << "INVALID INPUT:" << endl;
    break;
  }
  return 0;
}
