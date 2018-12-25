#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

#define WINDOWS 1

void console_clear_screen() {
  #ifdef WINDOWS
  system("cls");
  #endif
  #ifdef LINUX
  system("clear");
  #endif
}

int a[3][3], row, column;

void fill_matrix() // working perfectly
{
	cout << "Give the 8 numbers and one void (0):" << endl;
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			cin >> a[i][j];
		}
	}
}

void show_matrix() // working perfectly
{
	cout << "OUTPUT: " << endl << endl;
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void find_zero() // working perfectly
{
	int i, j;
	bool stmt=false;
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			if (a[i][j]==0)
			{
				row=i;
				column=j;
				stmt=true;
				break;
			}
		}
		if (stmt) break;
	}
}

void swap_right() // working perfectly
{
	a[row][column]=a[row][column+1];
	a[row][column+1]=0;
	column++;
}

void swap_left()
{
	a[row][column]=a[row][column-1];
	a[row][column-1]=0;
	column--;
}

void swap_down()
{
	a[row][column]=a[row+1][column];
	a[row+1][column]=0;
	row++;
}

void swap_up()
{
	
	a[row][column]=a[row-1][column];
	a[row-1][column]=0;
	row--;
}

void control_panel()
{
	char choice;
	cout << "Where do you want to swap zero?" << endl;
	cout << "W: up" << endl << "S: down" << endl << "A: left" << endl << "D: right" << endl << "B: Close the program" << endl;
	cin >> choice;
	while (true)
	{
		if (choice=='B' || choice=='b') break;
		console_clear_screen();
		if (choice=='W' || choice=='w') swap_up();
		if (choice=='S' || choice=='s') swap_down();
		if (choice=='A' || choice=='a') swap_left();
		if (choice=='D' || choice=='d') swap_right();
		show_matrix();
		cout << "Next move: " << endl;	
		cin >> choice;
	}
}
int main()
{
	fill_matrix();
	show_matrix();
	find_zero();
	cout << row+1 << " " << column+1 << endl;
	control_panel();
	cout << row+1 << " " << column+1 << endl;

}
