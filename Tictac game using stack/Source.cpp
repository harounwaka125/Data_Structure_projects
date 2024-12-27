/*
	Team 4 + عمرو خالد لو مسجلتوش
	Data Structures Ass1 in C++
	Tic Tac Toe Game
	2022-2023
*/

#include<iostream>
#include<string>
#include<Windows.h>//to clean the screen after any choice using system("cls") function
#define SIZE 20
using namespace std;
char ArrayOfXO[3][3];//global array to push and pop in it to check win or draw
/*---------------------------stack tic tac game to use undo and redo ------------------*/
class StackXO {
	int top;
	int XO[SIZE];
public:
	StackXO() { top = -1; }//use constructor to initialize the top and put a defult value to it
	void push(int value);//adding new elements at the top of the stack
	int pop();//to remove or 'pop' an element from the top of the stack
	bool is_empty();//to check and verify if a Stack is empty or not
	bool is_full();//to check and verify if a Stack is full or not
};
bool StackXO::is_empty() {
	if (top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool StackXO::is_full() {
	if (top == SIZE - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void StackXO::push(int value) {
	if (is_full())
		cout << "Error push" << endl;
	else
	{
		XO[++top] = value;
	}
}
int StackXO::pop()
{
	if (is_empty())
		cout << "Error empty" << endl;
	else
	{
		return XO[top--];
	}
}
/*-------------------------------------------checkwin win---------------------------------------*/
bool checkwinwin()//check if one of the players is acheive the statement and make him the winer..
{
	if (((ArrayOfXO[0][0] == 'X' && ArrayOfXO[0][1] == 'X' && ArrayOfXO[0][2] == 'X')) || ((ArrayOfXO[1][0] == 'X' && ArrayOfXO[1][1] == 'X' && ArrayOfXO[1][2] == 'X')) || ((ArrayOfXO[2][0] == 'X' && ArrayOfXO[2][1] == 'X' && ArrayOfXO[2][2] == 'X')) ||
		((ArrayOfXO[0][0] == 'X' && ArrayOfXO[1][0] == 'X' && ArrayOfXO[2][0] == 'X')) || ((ArrayOfXO[0][1] == 'X' && ArrayOfXO[1][1] == 'X' && ArrayOfXO[2][1] == 'X')) || ((ArrayOfXO[0][2] == 'X' && ArrayOfXO[1][2] == 'X' && ArrayOfXO[2][2] == 'X')) ||
		((ArrayOfXO[0][0] == 'O' && ArrayOfXO[0][1] == 'O' && ArrayOfXO[0][2] == 'O')) || ((ArrayOfXO[1][0] == 'O' && ArrayOfXO[1][1] == 'O' && ArrayOfXO[1][2] == 'O')) || ((ArrayOfXO[2][0] == 'O' && ArrayOfXO[2][1] == 'O' && ArrayOfXO[2][2] == 'O')) ||
		((ArrayOfXO[0][0] == 'O' && ArrayOfXO[1][0] == 'O' && ArrayOfXO[2][0] == 'O')) || ((ArrayOfXO[0][1] == 'O' && ArrayOfXO[1][1] == 'O' && ArrayOfXO[2][1] == 'O')) || ((ArrayOfXO[0][2] == 'O' && ArrayOfXO[1][2] == 'O' && ArrayOfXO[2][2] == 'O')) ||
		((ArrayOfXO[0][0] == 'X' && ArrayOfXO[1][1] == 'X' && ArrayOfXO[2][2] == 'X')) || ((ArrayOfXO[0][2] == 'X' && ArrayOfXO[1][1] == 'X' && ArrayOfXO[2][0] == 'X')) ||
		((ArrayOfXO[0][0] == 'O' && ArrayOfXO[1][1] == 'O' && ArrayOfXO[2][2] == 'O')) || ((ArrayOfXO[0][2] == 'X' && ArrayOfXO[1][1] == 'X' && ArrayOfXO[2][0] == 'X')))
	{
		return 1;
	}
	return 0;
}
bool CheckDraw()//chekc if all the statement of  checkwin is not achieved we print draw
{
	if ((ArrayOfXO[0][0] == 'X' || ArrayOfXO[0][0] == 'O') && (ArrayOfXO[0][1] == 'X' || ArrayOfXO[0][1] == 'O') && (ArrayOfXO[0][2] == 'X' || ArrayOfXO[0][2] == 'O') && (ArrayOfXO[1][0] == 'X' || ArrayOfXO[1][0] == 'O') && (ArrayOfXO[1][1] == 'X' || ArrayOfXO[1][1] == 'O') && (ArrayOfXO[1][2] == 'X' || ArrayOfXO[1][2] == 'O') && (ArrayOfXO[2][0] == 'X' || ArrayOfXO[2][0] == 'O') && (ArrayOfXO[2][1] == 'X' || ArrayOfXO[2][1] == 'O') && (ArrayOfXO[2][2] == 'X' || ArrayOfXO[2][2] == 'O'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*--------------------print-----------------------------------*/
void printShape()// function to print the output of the game..
{
	system("cls");//clean the cmd screen to make the output looks tidy
	for (int row = 0; row < 3; row++)
	{
		cout << "| ";
		for (int colum = 0; colum < 3; colum++)
		{
			if (ArrayOfXO[row][colum] == 'X' || ArrayOfXO[row][colum] == 'O')
			{
				cout << ArrayOfXO[row][colum] << " | ";
			}
			else
			{
				cout << "-" << " | ";
			}
		}
		cout << endl;
	}
	if (checkwinwin())
	{
		cout << "\t\t\t\t\tWinner Winner\n" << endl;
	}
	if (CheckDraw())
	{
		cout << "\t\t\t\t\tDRAW\n" << endl;
	}
}
/*----------------------------main---------------------------------------------------------------*/
int main() {
	StackXO n1, n2;//create two objects from the stack to push and pop from them
	int row, colom;//to choice where to add X or O
	int colom1=4, row1=4, colom2=4, row2=4;//to backup the pop (undo) to use them in redo and put a value in it that will in some if conditions
	string name1, name2;
	int choice, start, player;
	cout << "Enter name the first  player : \t";
	cin >> name1;
	cout << "Enter name the second player : \t";
	cin >> name2;
	cout << "player one " << name1 << " will play with 'x' character and player two "
		<< name2 << "  will play with 'o'character " << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "Which player will start  1 - player one ( " << name1 << " )       2 - player two ( " << name2 << " ) : " << endl;
	cin >> player;
	while ((!(checkwinwin()) && (!(CheckDraw())))) /*----------------continos play  while -----------------------------------------------*/
	{
		switch (player)// choose one of three statements to play 1- for choose the position 2- for undo 3- for redo..
		{
		case 1: { // put the value of the raw and column of any player who will play in that time and if the position is allready token
			// will print thats its invalid and make him put another position..
			start = 1;
			while (start == 1)
			{
				cout << name1 << " pleas enter 1- cell posetion 2-undo 3-redo : ";
				cin >> choice;
				switch (choice) {
				case 1: {     //--------------replace--------------------------------------------
					cout << "please enter row and col to put  " << name1 << " : ";
					cin >> row >> colom;
					if ((row == 0 || row == 1 || row == 2) && (colom == 0 || colom == 1 || colom == 2))
					{
						if (ArrayOfXO[row][colom] == 'X' || ArrayOfXO[row][colom] == 'O')
						{
							cout << "Invalid position" << endl;
							start = 1;
						}
						else
						{
							n1.push(row);
							n1.push(colom);
							ArrayOfXO[row][colom] = 'X';
							start = 0;
						}
					}
					else {
						cout << "Invalid position \n";
						start = 1;
					}
					break;
				}
				case 2: { // deleate the value that player put after save it..
					if (n1.is_empty())
					{
						cout << "There is no movements to undo yet" << endl;
						start = 1;
					}
					else
					{
						colom1 = n1.pop();
						row1 = n1.pop();
						ArrayOfXO[row1][colom1] = '-';
						start = 1;
						printShape();
					}
					break;
				}
				case 3: {  // return back the value that the player delete it with undo...

					if (!((row1 == 0 || row1 == 1 || row1 == 2) && (colom1 == 0 || colom1 == 1 || colom1 == 2)))
					{
						start = n1.pop();
					}
					else
					{
						if ((ArrayOfXO[row1][colom1] == 'X' || ArrayOfXO[row1][colom1] == 'O'))
						{
							cout << "There is no movements to redo yet 1" << endl;
							start = 1;
						}
						else
						{
							n1.push(row1);
							n1.push(colom1);
							ArrayOfXO[row1][colom1] = 'X';
							start = 1;
							printShape();
					
						}
						break;
					}
				}
				default:
				{
					start = 1;
					cout << "invalid input 1" << endl;
					break;
				}
				}
			}
			printShape();
			if (checkwinwin())
			{
				system("pause");
				return 0;
			}
			player = 2;
			break;
		}
			  /*------------------------------------------------------play two same function as player one -------------------------------*/
		case 2: {
			start = 1;
			while (start == 1)
			{
				cout << name2 << " : enter 1-position 2-undo 3-redo : ";
				cin >> choice;
				switch (choice)
				{
				case 1: {
					cout << "enter position " << name2 << " : ";
					cin >> row >> colom;
					if ((row == 0 || row == 1 || row == 2) && (colom == 0 || colom == 1 || colom == 2))
					{
						if (ArrayOfXO[row][colom] == 'X' || ArrayOfXO[row][colom] == 'O')
						{
							cout << "Invalid position" << endl;
							start = 1;
						}
						else
						{
							n2.push(row);
							n2.push(colom);
							ArrayOfXO[row][colom] = 'O';
							start = 0;
						}
					}
					else {
						cout << "error,try again" << endl;
						start = 1;
					}
					break;
				}
				case 2: {
					if (n2.is_empty())
					{
						cout << "There is no movements to undo yet 2" << endl;
						start = 1;
					}
					else
					{
						colom2 = n2.pop();
						row2 = n2.pop();
						ArrayOfXO[row2][colom2] = '-';
						start = 1;
						printShape();
					}
					break;
				}
				case 3: {  
					if (!((row2 == 0 || row2 == 1 || row2 == 2) && (colom2 == 0 || colom2 == 1 || colom2 == 2)))
					{
						start = n2.pop();
					}
					else
					{
						if ((ArrayOfXO[row2][colom2] == 'X' || ArrayOfXO[row2][colom2] == 'O'))
						{
							cout << "There is no movements to redo yet 2" << endl;
							start = 1;
						}
						else
						{
							n2.push(row2);
							n2.push(colom2);
							ArrayOfXO[row2][colom2] = 'O';
							start = 1;
							printShape();
						}
						break;
					}
				}
				default: {
					start = 1;
					cout << "invalid input 2" << endl;
					break;
				}
				}
			}
			printShape();// print the wineer massage or draw massage..
			if (checkwinwin())
			{
				system("pause");
				return 0;
			}
			player = 1;
			break;
		}
		default: {cout << "error , invalid number" << endl;//if he put wrong number that not 1 or 2 will make him put another number..
			cout << "who do you want first play 1-player 1 2-player 2 : ";
			cin >> player;
			start = 1;
		}
		}
	}
	system("pause");
	return 0;
}