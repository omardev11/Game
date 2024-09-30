
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
struct gametools 
{
    int paper=1;
    int stone=2;
    int scissor=3;
};
void ringBell() {
    std::cout << '\a';  // Output the ASCII bell character
}
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}
int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
string whowin(int player1choise, int computerchoise, int& player1Wins, int& computerWins, int& noWinnerRounds) {
    if (player1choise == computerchoise) {
        system("color 6e");
        noWinnerRounds++;
        return "Round winner   {No winner} :  \n";
    }
    else if ((player1choise == 1 && computerchoise == 2) ||
        (player1choise == 2 && computerchoise == 3) ||
        (player1choise == 3 && computerchoise == 1)) {
        system("color 2f");
        player1Wins++;
        return "Round winner   {Player 1} :  \n";
    }
    else {
        system("color 4f");
        computerWins++;
        ringBell();
        return "Round winner   {Computer} :  \n";
    }
}
void showgameresult(int playerwins, int computerwins, int nowinnersrounds,int roundtimes)
{
    cout << "\n\n      ------------------------------------------------------------------------\n\n";
    cout << "                         ***G A M E   O V E R***                                 \n\n";
    cout << "          -------------------------------------------------------------------------\n\n\n";
    cout << "          ------------------[ Game result ]-------------------------------------------\n\n";
    cout << "Game rounds                  :" << roundtimes << endl;
    cout << "Player 1 won times           :" << playerwins << endl;
    cout << "computer won times           :" << computerwins << endl;
    cout << "Draw times                   :" << nowinnersrounds << endl;
    if (playerwins > computerwins)
    {
        cout << "Final winner                 :" << "Player one" << endl;
    }
    else if (computerwins > playerwins)
    {
        cout << "Final winner                 :" << "Computer" << endl;
    }
    else 
        cout << "Final winner                 :" << "No winner" << endl;
    

    
}
void showresult(int player1choise, int& player1Wins, int& computerWins, int& noWinnerRounds)
{
       int computerchoise = RandomNumber(1, 3);
    cout << "\n-----------------------------[ROUND[1]-------------------------\n";
    cout << "Player 1 choise: " << player1choise << endl;
    cout << "Computer choise:  " << computerchoise << endl;
    cout << whowin(player1choise, computerchoise,player1Wins,computerWins,noWinnerRounds) << endl;
    cout << "\n--------------------------------------------------------------\n\n\n";

        
  
}
void begingame()
{
    int player1choise, player1Wins=0, computerWins=0, noWinnerRounds=0;
    int roundtimegame = ReadPositiveNumber("enter how many rounds do you want 1 to 10");
    for (int i = 1; i <= roundtimegame; i++)
    {
        cout << "Round ["<<i<<"] begins:\n\n";
        cout << "Your choise: [1]:paper, [2]:stone, [3]:scissor ?";
        cin >> player1choise;
        if (player1choise == 1 || player1choise == 2 || player1choise == 3)
        {
            showresult(player1choise, player1Wins, computerWins, noWinnerRounds);
        }
        else
        {
            cout << "\nYou Must Choise Between 1 to 3" << endl;
            return;
        }

    }
    showgameresult(player1Wins, computerWins, noWinnerRounds, roundtimegame);
}
void startgame()
{
    begingame();
    char answer;
    cout << "Do you want to play again? Y/N?  " << endl;
    cin >> answer;
    if (answer == 'y')
    {
        system("cls");
        system("color 0f");
        begingame();
    }
   
        
}
int main()
{
    srand((unsigned)time(NULL));
    startgame();
}

