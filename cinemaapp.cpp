#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>


using namespace std;

struct stime
{
	string hour, min, ampm;
	int hr, minute;
};

struct theatre
{
	string id;
	int capacity;
	bool rSeats[10][10];
};

struct ScreeningInfo
{
	string theatre;
	string screen;
	stime screening_time;
};

struct actor
{
	string first, last;
};

struct director
{
	string first, last;
};

struct mname
{
	string first, last;
};

struct category
{
	string first, last;
};

struct movie
{
	ScreeningInfo sinfo[2];
	actor actor[2];
	director directors;
	category genre;
	mname title;
	string rating;
};

void DisplayHeader()
{
	system("cls");

	cout << endl;

	// Upper Border

	cout << " \xC9";

	for (int i = 0; i < 76; i++)

		cout << "\xCD";

	cout << "\xBB";

	cout << endl;

	// Middle Border

	cout << " \xBA";

	//      [FROM_HERE                                                            TO_HERE]

	cout << "                          Movie Reservation System                          ";

	cout << "\xBA";

	cout << endl;

	// Upper Border

	cout << " \xC8";

	for (int i = 0; i < 76; i++)

		cout << "\xCD";

	cout << "\xBC";

	cout << endl;

	cout << endl;

}

void setcolor(unsigned short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

void screen()
{
	setcolor(14);
	std::cout << "\t\t\tSCREEN" << endl;
	setcolor(7);
	std::cout << endl;
}

void seats() {
	char seats[10][10];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			seats[i][j] = 'O';

	cout << endl;
	cout << "The Seats Shape : " << endl;
	cout << endl;
	screen();
	cout << "|_         " << "c1  " << "c2  " << "c3  " << "c4  " << "c5  " << "c6  " << "c7  " << "c8 " << " c9 " << " c10 " << endl;
	for (int i = 0; i < 9; i++)
	{
		std::cout << "|_ row " << i + 1 << "  _" << seats[i][0] << "_|" << "_" << seats[i][1] << "_|" << "_" << seats[i][2] << "_|" << "_" << seats[i][3] << "_|" << "_" << seats[i][4] << "_|" << "_" << seats[i][5] << "_|" << "_" << seats[i][6] << "_|" << "_" << seats[i][7] << "_|" << "_" << seats[i][8] << "_|_" << seats[i][9] << "_|" << endl;
	}
	cout << "|_ row 10 ";
	for (int i = 0; i < 10; i++)
	{
		cout << "_" << seats[9][i] << "_|";
	}
}
int exit() {
	return 0;
}

int cancellation(stime t)
{
	theatre count;
	count.capacity = 0;
	int Mnum, Mhr;  //Movie number , Movie hour
	int mn = 0;
	int hr[6][2] = { 12, 14,12, 14,12, 14,12, 14,17,19,17,19 };//movie's time(hour)
	int min[6][2] = { 0,30,0,30,0,30,0,30,0,30,0,30 };//movie's time(minute)
	if (t.minute == 0)
	{
		cout << "Global time is:  " << t.hr << ":" << t.minute << mn << endl << endl;
	}
	else
	{
		cout << "Global time is:  " << t.hr << ":" << t.minute << endl << endl;
	}
	std::cout << "1.Black Panther		(12:00pm/14:30pm)\n2.Red Sparrow		(12:00pm/14:30pm)\n3.Slumber		(12:00pm/14:30pm)\n4.Rampage		(12:00pm/14:30pm)\n5.Tomb Raider		(17:00pm/19:30pm)\n6.Death Wish		(17:00pm/19:30pm)\n\n";
	std::cout << "Which movie would you like to cancel?\n";
	std::cout << "Movie number: ";
	cin >> Mnum;
	std::cout << "Which time did you book?(1/2)\n";
	std::cout << "Time: ";
	cin >> Mhr;

	if (Mnum == 1 && Mhr == 1)
	{
		if (hr[0][0] - 1 == t.hr && t.minute >= min[0][0])
		{
			int row = 0, col;
			bool  rSeats[10][10];

			string FileName = "movie1.1.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					input >> rSeats[i][j];
					if (rSeats[i][j] == 1)
						count.capacity++;
				}
			}



			if (count.capacity != 0)
			{
				std::cout << "How Many Seats You Want To Cancel? : ";
				int cnum, counter = 0;
				cin >> cnum;

				while (counter < cnum)
				{
					for (int i = 0; i < 10; i++)
						for (int j = 0; j < 10; j++)
							input >> rSeats[i][j];

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					cout << "--------------------------------------------------" << endl;
					cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							cout << "Row: ";
							cin >> row;
							cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 1)
							{
								rSeats[row][col] = 0;
								cout << endl;
								break;
							}
							else if (rSeats[row][col] == 0)
							{
								cout << "Seat is not booked! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					cout << "The Ticket Has Been cancelled!" << endl;
				}
			}
			else
			{
				cout << "There are no tickets booked!";
			}
		}
		else
		{
			cout << "The ticket can't be cancelled " << endl;
		}
	}
	if (Mnum == 1 && Mhr == 2)
	{
		if (hr[0][1] - 1 == t.hr && t.minute >= min[0][1])
		{
			int row = 0, col;
			bool  rSeats[10][10];

			string FileName = "movie1.2.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					input >> rSeats[i][j];
					if (rSeats[i][j] == 1)
						count.capacity++;
				}
			}



			if (count.capacity != 0)
			{
				std::cout << "How Many Seats You Want To Cancel? : ";
				int cnum, counter = 0;
				cin >> cnum;

				while (counter < cnum)
				{
					for (int i = 0; i < 10; i++)
						for (int j = 0; j < 10; j++)
							input >> rSeats[i][j];

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					cout << "--------------------------------------------------" << endl;
					cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							cout << "Row: ";
							cin >> row;
							cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 1)
							{
								rSeats[row][col] = 0;
								cout << endl;
								break;
							}
							else if (rSeats[row][col] == 0)
							{
								cout << "Seat is not booked! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					cout << "The Ticket Has Been cancelled!" << endl;
				}
			}
			else
			{
				cout << "There are no tickets booked!";
			}
		}
		else
		{
			cout << "The ticket can't be cancelled " << endl;
		}
	}

	if (Mnum == 2 && Mhr == 1)
	{
		if (hr[1][0] - 1 == t.hr && t.minute >= min[1][0])
		{
			int row = 0, col;
			bool  rSeats[10][10];

			string FileName = "movie2.1.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					input >> rSeats[i][j];
					if (rSeats[i][j] == 1)
						count.capacity++;
				}
			}



			if (count.capacity != 0)
			{
				std::cout << "How Many Seats You Want To Cancel? : ";
				int cnum, counter = 0;
				cin >> cnum;

				while (counter < cnum)
				{
					for (int i = 0; i < 10; i++)
						for (int j = 0; j < 10; j++)
							input >> rSeats[i][j];

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					cout << "--------------------------------------------------" << endl;
					cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							cout << "Row: ";
							cin >> row;
							cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 1)
							{
								rSeats[row][col] = 0;
								cout << endl;
								break;
							}
							else if (rSeats[row][col] == 0)
							{
								cout << "Seat is not booked! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					cout << "The Ticket Has Been cancelled!" << endl;
				}
			}
			else
			{
				cout << "There are no tickets booked!";
			}
		}
		else
		{
			cout << "The ticket can't be cancelled " << endl;
		}
	}
	if (Mnum == 2 && Mhr == 2)
	{
		if (hr[1][1] - 1 == t.hr && t.minute >= min[1][1])
		{
			int row = 0, col;
			bool  rSeats[10][10];

			string FileName = "movie2.2.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					input >> rSeats[i][j];
					if (rSeats[i][j] == 1)
						count.capacity++;
				}
			}



			if (count.capacity != 0)
			{
				std::cout << "How Many Seats You Want To Cancel? : ";
				int cnum, counter = 0;
				cin >> cnum;

				while (counter < cnum)
				{
					for (int i = 0; i < 10; i++)
						for (int j = 0; j < 10; j++)
							input >> rSeats[i][j];

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					cout << "--------------------------------------------------" << endl;
					cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							cout << "Row: ";
							cin >> row;
							cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 1)
							{
								rSeats[row][col] = 0;
								cout << endl;
								break;
							}
							else if (rSeats[row][col] == 0)
							{
								cout << "Seat is not booked! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					cout << "The Ticket Has Been cancelled!" << endl;
				}
			}
			else
			{
				cout << "There are no tickets booked!";
			}
		}
		else
		{
			cout << "The ticket can't be cancelled " << endl;
		}
	}

	if (Mnum == 3 && Mhr == 1)
	{
		if (hr[2][0] - 1 == t.hr && t.minute >= min[2][0])
		{
			int row = 0, col;
			bool  rSeats[10][10];

			string FileName = "movie3.1.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					input >> rSeats[i][j];
					if (rSeats[i][j] == 1)
						count.capacity++;
				}
			}



			if (count.capacity != 0)
			{
				std::cout << "How Many Seats You Want To Cancel? : ";
				int cnum, counter = 0;
				cin >> cnum;

				while (counter < cnum)
				{
					for (int i = 0; i < 10; i++)
						for (int j = 0; j < 10; j++)
							input >> rSeats[i][j];

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					cout << "--------------------------------------------------" << endl;
					cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							cout << "Row: ";
							cin >> row;
							cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 1)
							{
								rSeats[row][col] = 0;
								cout << endl;
								break;
							}
							else if (rSeats[row][col] == 0)
							{
								cout << "Seat is not booked! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					cout << "The Ticket Has Been cancelled!" << endl;
				}
			}
			else
			{
				cout << "There are no tickets booked!";
			}
		}
		else
		{
			cout << "The ticket can't be cancelled " << endl;
		}
	}
	if (Mnum == 3 && Mhr == 2)
	{
		if (hr[2][1] - 1 == t.hr && t.minute >= min[2][1])
		{
			int row = 0, col;
			bool  rSeats[10][10];

			string FileName = "movie3.2.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					input >> rSeats[i][j];
					if (rSeats[i][j] == 1)
						count.capacity++;
				}
			}



			if (count.capacity != 0)
			{
				std::cout << "How Many Seats You Want To Cancel? : ";
				int cnum, counter = 0;
				cin >> cnum;

				while (counter < cnum)
				{
					for (int i = 0; i < 10; i++)
						for (int j = 0; j < 10; j++)
							input >> rSeats[i][j];

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					cout << "--------------------------------------------------" << endl;
					cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							cout << "Row: ";
							cin >> row;
							cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 1)
							{
								rSeats[row][col] = 0;
								cout << endl;
								break;
							}
							else if (rSeats[row][col] == 0)
							{
								cout << "Seat is not booked! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					cout << "The Ticket Has Been cancelled!" << endl;
				}
			}
			else
			{
				cout << "There are no tickets booked!";
			}
		}
		else
		{
			cout << "The ticket can't be cancelled " << endl;
		}
	}

	if (Mnum == 4 && Mhr == 1)
	{
		if (hr[3][0] - 1 == t.hr && t.minute >= min[3][0])
		{
			int row = 0, col;
			bool  rSeats[10][10];

			string FileName = "movie4.1.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					input >> rSeats[i][j];
					if (rSeats[i][j] == 1)
						count.capacity++;
				}
			}



			if (count.capacity != 0)
			{
				std::cout << "How Many Seats You Want To Cancel? : ";
				int cnum, counter = 0;
				cin >> cnum;

				while (counter < cnum)
				{
					for (int i = 0; i < 10; i++)
						for (int j = 0; j < 10; j++)
							input >> rSeats[i][j];

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					cout << "--------------------------------------------------" << endl;
					cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							cout << "Row: ";
							cin >> row;
							cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 1)
							{
								rSeats[row][col] = 0;
								cout << endl;
								break;
							}
							else if (rSeats[row][col] == 0)
							{
								cout << "Seat is not booked! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					cout << "The Ticket Has Been cancelled!" << endl;
				}
			}
			else
			{
				cout << "There are no tickets booked!";
			}
		}
		else
		{
			cout << "The ticket can't be cancelled " << endl;
		}
	}
	if (Mnum == 4 && Mhr == 2)
	{
		if (hr[3][1] - 1 == t.hr && t.minute >= min[3][1])
		{
			int row = 0, col;
			bool  rSeats[10][10];

			string FileName = "movie4.2.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					input >> rSeats[i][j];
					if (rSeats[i][j] == 1)
						count.capacity++;
				}
			}



			if (count.capacity != 0)
			{
				std::cout << "How Many Seats You Want To Cancel? : ";
				int cnum, counter = 0;
				cin >> cnum;

				while (counter < cnum)
				{
					for (int i = 0; i < 10; i++)
						for (int j = 0; j < 10; j++)
							input >> rSeats[i][j];

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					cout << "--------------------------------------------------" << endl;
					cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							cout << "Row: ";
							cin >> row;
							cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 1)
							{
								rSeats[row][col] = 0;
								cout << endl;
								break;
							}
							else if (rSeats[row][col] == 0)
							{
								cout << "Seat is not booked! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					cout << "The Ticket Has Been cancelled!" << endl;
				}
			}
			else
			{
				cout << "There are no tickets booked!";
			}
		}
		else
		{
			cout << "The ticket can't be cancelled " << endl;
		}
	}

	if (Mnum == 5 && Mhr == 1)
	{
		if (hr[4][0] - 1 == t.hr && t.minute >= min[4][0])
		{
			int row = 0, col;
			bool  rSeats[10][10];

			string FileName = "movie5.1.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					input >> rSeats[i][j];
					if (rSeats[i][j] == 1)
						count.capacity++;
				}
			}



			if (count.capacity != 0)
			{
				std::cout << "How Many Seats You Want To Cancel? : ";
				int cnum, counter = 0;
				cin >> cnum;

				while (counter < cnum)
				{
					for (int i = 0; i < 10; i++)
						for (int j = 0; j < 10; j++)
							input >> rSeats[i][j];

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					cout << "--------------------------------------------------" << endl;
					cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							cout << "Row: ";
							cin >> row;
							cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 1)
							{
								rSeats[row][col] = 0;
								cout << endl;
								break;
							}
							else if (rSeats[row][col] == 0)
							{
								cout << "Seat is not booked! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					cout << "The Ticket Has Been cancelled!" << endl;
				}
			}
			else
			{
				cout << "There are no tickets booked!";
			}
		}
		else
		{
			cout << "The ticket can't be cancelled " << endl;
		}
	}
	if (Mnum == 5 && Mhr == 2)
	{
		if (hr[4][1] - 1 == t.hr && t.minute >= min[4][1])
		{
			int row = 0, col;
			bool  rSeats[10][10];

			string FileName = "movie5.2.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					input >> rSeats[i][j];
					if (rSeats[i][j] == 1)
						count.capacity++;
				}
			}



			if (count.capacity != 0)
			{
				std::cout << "How Many Seats You Want To Cancel? : ";
				int cnum, counter = 0;
				cin >> cnum;

				while (counter < cnum)
				{
					for (int i = 0; i < 10; i++)
						for (int j = 0; j < 10; j++)
							input >> rSeats[i][j];

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					cout << "--------------------------------------------------" << endl;
					cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							cout << "Row: ";
							cin >> row;
							cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 1)
							{
								rSeats[row][col] = 0;
								cout << endl;
								break;
							}
							else if (rSeats[row][col] == 0)
							{
								cout << "Seat is not booked! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					cout << "The Ticket Has Been cancelled!" << endl;
				}
			}
			else
			{
				cout << "There are no tickets booked!";
			}
		}
		else
		{
			cout << "The ticket can't be cancelled " << endl;
		}
	}

	if (Mnum == 6 && Mhr == 1)
	{
		if (hr[5][0] - 1 == t.hr && t.minute >= min[5][0])
		{
			int row = 0, col;
			bool  rSeats[10][10];

			string FileName = "movie6.1.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					input >> rSeats[i][j];
					if (rSeats[i][j] == 1)
						count.capacity++;
				}
			}



			if (count.capacity != 0)
			{
				std::cout << "How Many Seats You Want To Cancel? : ";
				int cnum, counter = 0;
				cin >> cnum;

				while (counter < cnum)
				{
					for (int i = 0; i < 10; i++)
						for (int j = 0; j < 10; j++)
							input >> rSeats[i][j];

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					cout << "--------------------------------------------------" << endl;
					cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							cout << "Row: ";
							cin >> row;
							cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 1)
							{
								rSeats[row][col] = 0;
								cout << endl;
								break;
							}
							else if (rSeats[row][col] == 0)
							{
								cout << "Seat is not booked! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					cout << "The Ticket Has Been cancelled!" << endl;
				}
			}
			else
			{
				cout << "There are no tickets booked!";
			}
		}
		else
		{
			cout << "The ticket can't be cancelled " << endl;
		}
	}
	if (Mnum == 6 && Mhr == 2)
	{
		if (hr[5][1] - 1 == t.hr && t.minute >= min[5][1])
		{
			int row = 0, col;
			bool  rSeats[10][10];

			string FileName = "movie6.2.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					input >> rSeats[i][j];
					if (rSeats[i][j] == 1)
						count.capacity++;
				}
			}



			if (count.capacity != 0)
			{
				std::cout << "How Many Seats You Want To Cancel? : ";
				int cnum, counter = 0;
				cin >> cnum;

				while (counter < cnum)
				{
					for (int i = 0; i < 10; i++)
						for (int j = 0; j < 10; j++)
							input >> rSeats[i][j];

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					cout << "--------------------------------------------------" << endl;
					cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							cout << "Row: ";
							cin >> row;
							cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 1)
							{
								rSeats[row][col] = 0;
								cout << endl;
								break;
							}
							else if (rSeats[row][col] == 0)
							{
								cout << "Seat is not booked! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					cout << "The Ticket Has Been cancelled!" << endl;
				}
			}
			else
			{
				cout << "There are no tickets booked!";
			}
		}
		else
		{
			cout << "The ticket can't be cancelled " << endl;
		}
	}
	return 0;
}

int booking(stime t)
{
	theatre count;
	int mn = 0;
	int row = 0, col;
	bool  rSeats[10][10];
	int cnum, counter = 0;
	int hr[6][2] = { 12, 14,12, 14,12, 14,12, 14,17,19,17,19 };//movie's time(hour)
	int min[6][2] = { 0,30,0,30,0,30,0,30,0,30,0,30 };//movie's time(minute)
	int Mnum, Mhr;  //Movie number , Movie hour

	if (t.minute == 0)
	{
		cout << "Global time is:  " << t.hr << ":" << t.minute << mn << endl << endl;
	}
	else
	{
		cout << "Global time is:  " << t.hr << ":" << t.minute << endl << endl;
	}
	cout << "1.Black Panther		(12:00pm / 14:30pm)\n2.Red Sparrow		(12:00pm / 14:30pm)\n3.Slumber		(12:00pm / 14:30pm)\n4.Rampage		(12:00pm / 14:30pm)\n5.Tomb Raider		(17:00pm / 19:30pm)\n6.Death Wish		(17:00pm / 19:30pm)\n\n";
	cout << "Which movie would you like to watch?\n";
	cout << "Movie number: ";
	cin >> Mnum;
	cout << "Which time do you want to book?(1/2)\n";
	cout << "Time: ";
	cin >> Mhr;



	if (Mnum == 1 && Mhr == 1)
	{
		//if the user can reserve the movie at that moment of time 
		if ((hr[0][0] == t.hr && (t.minute == min[0][0] || t.minute - min[0][0] <= 15)) //if global time = the movie's time

			|| (hr[0][0] - 1 == t.hr && t.minute >= min[0][0]))  //if movie's time greater than global time with 1hour
		{
			string FileName = "movie1.1.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);
			count.capacity = 0;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					input >> rSeats[i][j];
					if (rSeats[i][j] == 0)
					{
						count.capacity++;
					}
				}
			}

			if (count.capacity != 0)
			{
				std::cout << "How Many Seats You Want To Book? : ";
				cin >> cnum;
				if (cnum <= count.capacity)
				{

					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					cout << "--------------------------------------------------" << endl;
					cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							cout << "Row: ";
							cin >> row;
							cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 0)
							{
								rSeats[row][col] = 1;
								std::cout << endl;
								break;
							}
							else if (rSeats[row][col] == 1)
							{
								std::cout << "Seat is already taken! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					std::cout << "The Ticket Has Been Booked" << endl;
				}
				else
				{
					cout << "There are " << count.capacity << " seats left only" << endl << "Do you want to book them?(y/n): ";
					char t;
					cin >> t;
					if (t == 'y')
					{
						int counter = 0;
						string FileName = "movie1.1.txt";
						fstream input(FileName, ios::in | ios::out | ios::app);
						int row = 0, col = 0;
						bool  rSeats[10][10];

						while (counter < count.capacity)
						{
							for (int i = 0; i < 10; i++)
								for (int j = 0; j < 10; j++)
									input >> rSeats[i][j];

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									if (rSeats[i][j] == 0)
										rSeats[i][j] = 1;
								}
								counter++;
							}

							ofstream Rewrite(FileName);

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									Rewrite << rSeats[i][j] << " ";
								}
								Rewrite << endl;
							}
						}
						cout << "--------------------------------------------------" << endl;
						cout << "Seats : " << endl;
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (rSeats[i][j] == 0)
								{
									cout << "_";
									setcolor(10);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
								else if (rSeats[i][j] == 1)
								{
									cout << "_";
									setcolor(12);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
							}
							cout << endl;
						}
						cout << endl;
						cout << "--------------------------------------------------" << endl;
						cout << "The Ticket Has Been Booked" << endl;

					}
				}
			}
			else
			{
				cout << endl;
				cout << "Sorry, there are no seats available!";
			}

		}
		//if the user can't reserve the movie at that moment of time (early time)
		else if ((hr[0][0] - 1 == t.hr && min[0][0] - t.minute >= 1) || hr[0][0] - t.hr > 1)
		{
			if (hr[0][0] - 1 == t.hr && min[0][0] - t.minute >= 1)
			{
				cout << "Sorry it's early to reserve this movie please try again after: " << min[0][0] - t.minute << " minute" << endl;
			}
			else if (hr[0][0] - t.hr > 1)
			{
				if (min[0][0] > t.minute)
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[0][0] - t.hr) - 1 << " hour and " << min[0][0] - t.minute << " minute" << endl;
				}
				else if (t.minute > min[0][0])
				{
					if ((hr[0][0] - t.hr) - 2 == 0)
					{
						cout << "Sorry it's early to reserve this movie please try again after: " << (60 - t.minute) + min[0][0] << " minute" << endl;
					}
					else
						cout << "Sorry it's early to reserve this movie please trt again after: " << (hr[0][0] - t.hr) - 2 << " hour and " << (60 - t.minute) + min[0][0] << " minute" << endl;
				}
				else if (t.minute == min[0][0])
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[0][0] - t.hr) - 1 << " hour " << endl;
				}
			}
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
		//if the user can't reserve the movie at that moment of time (late time)
		else if (t.hr > hr[0][0] || (t.hr == hr[0][0] && t.minute - min[0][0] > 15))
		{
			cout << "Sorry It's too late to reserve this movie " << endl;
			char answer;
			cout << endl;
			
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}
		}

	}
	if (Mnum == 1 && Mhr == 2)
	{
		//if the user can reserve the movie at that moment of time 
		if ((hr[0][1] == t.hr && (t.minute == min[0][1] || t.minute - min[0][1] <= 15)) //if global time = the movie's time

			|| (hr[0][1] - 1 == t.hr && t.minute >= min[0][1]))  //if movie's time greater than global time with 1hour
		{
			count.capacity = 0;
			int cnum, counter = 0;
			string FileName = "movie1.2.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);
			int row = 0, col;
			bool  rSeats[10][10];

			while (true)
			{
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						input >> rSeats[i][j];
						if (rSeats[i][j] == 0)
							count.capacity++;
					}
				}

				if (count.capacity == 0)
				{
					cout << "There are no available seats!\n";
					exit();
					break;
				}

				cout << "How Many Seats You Want To Book? : ";
				cin >> cnum;
				if (cnum <= count.capacity)
				{

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
					}
					std::cout << "--------------------------------------------------" << endl;
					std::cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							std::cout << "Row: ";
							cin >> row;
							std::cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 0)
							{
								rSeats[row][col] = 1;
								std::cout << endl;
								break;
							}
							else if (rSeats[row][col] == 1)
							{
								std::cout << "Seat is already taken! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					cout << "The Ticket Has Been Booked" << endl;
				}
				else {
					cout << "there are only " << count.capacity << " seats left do you want to book them?(y/n) ";
					char t;
					cin >> t;
					if (t == 'y')
					{
						string FileName = "movie1.2.txt";
						fstream input(FileName, ios::in | ios::out | ios::app);
						int row = 0, col = 0;
						bool  rSeats[10][10];

						while (counter < count.capacity)
						{
							for (int i = 0; i < 10; i++)
								for (int j = 0; j < 10; j++)
									input >> rSeats[i][j];

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									if (rSeats[i][j] == 0)
										rSeats[i][j] = 1;
								}
								counter++;
							}

							ofstream Rewrite(FileName);

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									Rewrite << rSeats[i][j] << " ";
								}
								Rewrite << endl;
							}
						}
						cout << "--------------------------------------------------" << endl;
						cout << "Seats : " << endl;
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (rSeats[i][j] == 0)
								{
									cout << "_";
									setcolor(10);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
								else if (rSeats[i][j] == 1)
								{
									cout << "_";
									setcolor(12);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
							}
							cout << endl;
						}
						cout << endl;
						cout << "--------------------------------------------------" << endl;
						cout << "The Ticket Has Been Booked" << endl;
					}
					else
					{
						cout << "\t THANK YOU" << endl;
						exit();
					}
				}
				counter++;
				if (counter == cnum)
					break;
			}
		}
		//if the user can't reserve the movie at that moment of time (early time)
		else if ((hr[0][1] - 1 == t.hr && min[0][1] - t.minute >= 1) || hr[0][1] - t.hr > 1)
		{
			if (hr[0][1] - 1 == t.hr && min[0][1] - t.minute >= 1)
			{
				cout << "Sorry it's early to reserve this movie please try again after: " << min[0][1] - t.minute << " minute" << endl;
			}
			else if (hr[0][1] - t.hr > 1)
			{
				if (min[0][1] > t.minute)
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[0][1] - t.hr) - 1 << " hour and " << min[0][1] - t.minute << " minute" << endl;
				}
				else if (t.minute > min[0][1])
				{
					if ((hr[0][1] - t.hr) - 2 == 0)
					{
						cout << "Sorry it's early to reserve this movie please try again after: " << (60 - t.minute) + min[0][1] << " minute" << endl;
					}
					else
						cout << "Sorry it's early to reserve this movie please trt again after: " << (hr[0][1] - t.hr) - 2 << " hour and " << (60 - t.minute) + min[0][1] << " minute" << endl;
				}
				else if (t.minute == min[0][1])
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[0][1] - t.hr) - 1 << " hour " << endl;
				}
			}
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
		//if the user can't reserve the movie at that moment of time (late time)
		else if (t.hr > hr[0][1] || (t.hr == hr[0][1] && t.minute - min[0][1] > 15))
		{
			cout << "Sorry It's too late to reserve this movie " << endl;
			char answer;
			cout << endl;
			cout << endl;
			cout << "It's " << t.hr << ":" << t.min << " you can still watch ....... ";
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}
		}
	}

	if (Mnum == 2 && Mhr == 1)
	{
		//if the user can reserve the movie at that moment of time 
		if ((hr[1][0] == t.hr && (t.minute == min[1][0] || t.minute - min[1][0] <= 15)) //if global time = the movie's time

			|| (hr[1][0] - 1 == t.hr && t.minute >= min[1][0]))  //if movie's time greater than global time with 1hour
		{
			string FileName = "movie2.1.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);
			count.capacity = 0;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					input >> rSeats[i][j];
					if (rSeats[i][j] == 0)
					{
						count.capacity++;
					}
				}
			}

			if (count.capacity != 0)
			{
				std::cout << "How Many Seats You Want To Book? : ";
				cin >> cnum;
				if (cnum <= count.capacity)
				{

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					cout << "--------------------------------------------------" << endl;
					cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							cout << "Row: ";
							cin >> row;
							cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 0)
							{
								rSeats[row][col] = 1;
								std::cout << endl;
								break;
							}
							else if (rSeats[row][col] == 1)
							{
								std::cout << "Seat is already taken! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					std::cout << "The Ticket Has Been Booked" << endl;
				}
				else
				{
					cout << "There are " << count.capacity << " seats left only" << endl << "Do you want to book them?(y/n): ";
					char t;
					cin >> t;
					if (t == 'y')
					{
						int counter = 0;
						string FileName = "movie2.1.txt";
						fstream input(FileName, ios::in | ios::out | ios::app);
						int row = 0, col = 0;
						bool  rSeats[10][10];

						while (counter < count.capacity)
						{
							for (int i = 0; i < 10; i++)
								for (int j = 0; j < 10; j++)
									input >> rSeats[i][j];

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									if (rSeats[i][j] == 0)
										rSeats[i][j] = 1;
								}
								counter++;
							}

							ofstream Rewrite(FileName);

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									Rewrite << rSeats[i][j] << " ";
								}
								Rewrite << endl;
							}
						}
						cout << "--------------------------------------------------" << endl;
						cout << "Seats : " << endl;
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (rSeats[i][j] == 0)
								{
									cout << "_";
									setcolor(10);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
								else if (rSeats[i][j] == 1)
								{
									cout << "_";
									setcolor(12);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
							}
							cout << endl;
						}
						cout << endl;
						cout << "--------------------------------------------------" << endl;
						cout << "The Ticket Has Been Booked" << endl;
					}


				}
			}
			else
			{
				cout << endl;
				cout << "Sorry, there are no seats available!";
			}
		}
		//if the user can't reserve the movie at that moment of time (early time)
		else if ((hr[1][0] - 1 == t.hr && min[1][0] - t.minute >= 1) || hr[1][0] - t.hr > 1)
		{
			if (hr[1][0] - 1 == t.hr && min[1][0] - t.minute >= 1)
			{
				cout << "Sorry it's early to reserve this movie please try again after: " << min[1][0] - t.minute << " minute" << endl;
			}
			else if (hr[1][0] - t.hr > 1)
			{
				if (min[1][0] > t.minute)
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[1][0] - t.hr) - 1 << " hour and " << min[1][0] - t.minute << " minute" << endl;
				}
				else if (t.minute > min[1][0])
				{
					if ((hr[1][0] - t.hr) - 2 == 0)
					{
						cout << "Sorry it's early to reserve this movie please try again after: " << (60 - t.minute) + min[1][0] << " minute" << endl;
					}
					else
						cout << "Sorry it's early to reserve this movie please trt again after: " << (hr[1][0] - t.hr) - 2 << " hour and " << (60 - t.minute) + min[1][0] << " minute" << endl;
				}
				else if (t.minute == min[1][0])
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[1][0] - t.hr) - 1 << " hour " << endl;
				}
			}
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
		//if the user can't reserve the movie at that moment of time (late time)
		else if (t.hr > hr[1][0] || (t.hr == hr[1][0] && t.minute - min[1][0] > 15))
		{
			cout << "Sorry It's too late to reserve this movie " << endl;
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
	}
	if (Mnum == 2 && Mhr == 2)
	{
		//if the user can reserve the movie at that moment of time 
		if ((hr[1][1] == t.hr && (t.minute == min[1][1] || t.minute - min[1][1] <= 15)) //if global time = the movie's time

			|| (hr[1][1] - 1 == t.hr && t.minute >= min[1][1]))  //if movie's time greater than global time with 1hour
		{
			count.capacity = 0;
			int cnum, counter = 0;
			string FileName = "movie2.2.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);
			int row = 0, col;
			bool  rSeats[10][10];

			while (true)
			{
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						input >> rSeats[i][j];
						if (rSeats[i][j] == 0)
							count.capacity++;
					}
				}
				if (count.capacity == 0)
				{
					cout << "There are no available seats!\n";
					exit();
					break;
				}
				cout << "How Many Seats You Want To Book? : ";
				cin >> cnum;
				if (cnum <= count.capacity)
				{

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					std::cout << "--------------------------------------------------" << endl;
					std::cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++) {

						cout << "Row: ";
						cin >> row;
						cout << "\nColumn: ";
						cin >> col;
						if (rSeats[row][col] == 0)
							rSeats[row][col] = 1;
						cout << endl;
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					cout << "The Ticket Has Been Booked" << endl;
				}
				else {
					cout << "there are only " << count.capacity << " seats left do you want to book them?(y/n) ";
					char t;
					cin >> t;
					if (t == 'y')
					{

						string FileName = "movie2.2.txt";
						fstream input(FileName, ios::in | ios::out | ios::app);
						int row = 0, col = 0;
						bool  rSeats[10][10];

						while (counter < count.capacity)
						{
							for (int i = 0; i < 10; i++)
								for (int j = 0; j < 10; j++)
									input >> rSeats[i][j];

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									if (rSeats[i][j] == 0)
										rSeats[i][j] = 1;
								}
								counter++;
							}

							ofstream Rewrite(FileName);

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									Rewrite << rSeats[i][j] << " ";
								}
								Rewrite << endl;
							}
						}
						cout << "--------------------------------------------------" << endl;
						cout << "Seats : " << endl;
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (rSeats[i][j] == 0)
								{
									cout << "_";
									setcolor(10);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
								else if (rSeats[i][j] == 1)
								{
									cout << "_";
									setcolor(12);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
							}
							cout << endl;
						}
						cout << endl;
						cout << "--------------------------------------------------" << endl;
						cout << "The Ticket Has Been Booked" << endl;
					}
					else {
						cout << "\t THANK YOU" << endl;
						exit();
					}
				}
				if (counter == cnum)
					break;
			}
		}
		//if the user can't reserve the movie at that moment of time (early time)
		else if ((hr[1][1] - 1 == t.hr && min[1][1] - t.minute >= 1) || hr[1][1] - t.hr > 1)
		{
			if (hr[1][1] - 1 == t.hr && min[1][1] - t.minute >= 1)
			{
				cout << "Sorry it's early to reserve this movie please try again after: " << min[1][1] - t.minute << " minute" << endl;
			}
			else if (hr[1][1] - t.hr > 1)
			{
				if (min[1][1] > t.minute)
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[1][1] - t.hr) - 1 << " hour and " << min[1][1] - t.minute << " minute" << endl;
				}
				else if (t.minute > min[1][1])
				{
					if ((hr[1][1] - t.hr) - 2 == 0)
					{
						cout << "Sorry it's early to reserve this movie please try again after: " << (60 - t.minute) + min[1][1] << " minute" << endl;
					}
					else
						cout << "Sorry it's early to reserve this movie please trt again after: " << (hr[1][1] - t.hr) - 2 << " hour and " << (60 - t.minute) + min[1][1] << " minute" << endl;
				}
				else if (t.minute == min[1][1])
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[1][1] - t.hr) - 1 << " hour " << endl;
				}
			}
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
		//if the user can't reserve the movie at that moment of time (late time)
		else if (t.hr > hr[1][1] || (t.hr == hr[1][1] && t.minute - min[1][1] > 15))
		{
			cout << "Sorry It's too late to reserve this movie " << endl;
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
	}

	if (Mnum == 3 && Mhr == 1)
	{
		//if the user can reserve the movie at that moment of time 
		if ((hr[2][0] == t.hr && (t.minute == min[2][0] || t.minute - min[2][0] <= 15)) //if global time = the movie's time

			|| (hr[2][0] - 1 == t.hr && t.minute >= min[2][0]))  //if movie's time greater than global time with 1hour
		{
			string FileName = "movie3.1.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);
			count.capacity = 0;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					input >> rSeats[i][j];
					if (rSeats[i][j] == 0)
					{
						count.capacity++;
					}
				}
			}

			if (count.capacity != 0)
			{
				std::cout << "How Many Seats You Want To Book? : ";
				cin >> cnum;
				if (cnum <= count.capacity)
				{

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					cout << "--------------------------------------------------" << endl;
					cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							cout << "Row: ";
							cin >> row;
							cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 0)
							{
								rSeats[row][col] = 1;
								std::cout << endl;
								break;
							}
							else if (rSeats[row][col] == 1)
							{
								std::cout << "Seat is already taken! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					std::cout << "The Ticket Has Been Booked" << endl;
				}
				else
				{
					cout << "There are " << count.capacity << " seats left only" << endl << "Do you want to book them?(y/n): ";
					char t;
					cin >> t;
					if (t == 'y')
					{
						int counter = 0;
						string FileName = "movie3.1.txt";
						fstream input(FileName, ios::in | ios::out | ios::app);
						int row = 0, col = 0;
						bool  rSeats[10][10];

						while (counter < count.capacity)
						{
							for (int i = 0; i < 10; i++)
								for (int j = 0; j < 10; j++)
									input >> rSeats[i][j];

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									if (rSeats[i][j] == 0)
										rSeats[i][j] = 1;
								}
								counter++;
							}

							ofstream Rewrite(FileName);

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									Rewrite << rSeats[i][j] << " ";
								}
								Rewrite << endl;
							}
						}
						cout << "--------------------------------------------------" << endl;
						cout << "Seats : " << endl;
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (rSeats[i][j] == 0)
								{
									cout << "_";
									setcolor(10);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
								else if (rSeats[i][j] == 1)
								{
									cout << "_";
									setcolor(12);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
							}
							cout << endl;

						}
						cout << "--------------------------------------------------" << endl;
						cout << "The Ticket Has Been Booked" << endl;
					}

				}
			}
			else
			{
				cout << endl;
				cout << "Sorry, there are no seats available!";
			}
		}
		//if the user can't reserve the movie at that moment of time (early time)
		else if ((hr[2][0] - 1 == t.hr && min[2][0] - t.minute >= 1) || hr[2][0] - t.hr > 1)
		{
			if (hr[2][0] - 1 == t.hr && min[2][0] - t.minute >= 1)
			{
				cout << "Sorry it's early to reserve this movie please try again after: " << min[2][0] - t.minute << " minute" << endl;
			}
			else if (hr[2][0] - t.hr > 1)
			{
				if (min[2][0] > t.minute)
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[2][0] - t.hr) - 1 << " hour and " << min[2][0] - t.minute << " minute" << endl;
				}
				else if (t.minute > min[2][0])
				{
					if ((hr[2][0] - t.hr) - 2 == 0)
					{
						cout << "Sorry it's early to reserve this movie please try again after: " << (60 - t.minute) + min[2][0] << " minute" << endl;
					}
					else
						cout << "Sorry it's early to reserve this movie please trt again after: " << (hr[2][0] - t.hr) - 2 << " hour and " << (60 - t.minute) + min[2][0] << " minute" << endl;
				}
				else if (t.minute == min[2][0])
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[2][0] - t.hr) - 1 << " hour " << endl;
				}
			}
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
		//if the user can't reserve the movie at that moment of time (late time)
		else if (t.hr > hr[2][0] || (t.hr == hr[2][0] && t.minute - min[2][0] > 15))
		{
			cout << "Sorry It's too late to reserve this movie " << endl;
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
	}
	if (Mnum == 3 && Mhr == 2)
	{
		//if the user can reserve the movie at that moment of time 
		if ((hr[2][1] == t.hr && (t.minute == min[2][1] || t.minute - min[2][1] <= 15)) //if global time = the movie's time

			|| (hr[2][1] - 1 == t.hr && t.minute >= min[2][1]))  //if movie's time greater than global time with 1hour
		{
			count.capacity = 0;
			int cnum, counter = 0;
			string FileName = "movie3.2.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);
			int row = 0, col;
			bool  rSeats[10][10];

			while (true)
			{
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						input >> rSeats[i][j];
						if (rSeats[i][j] == 0)
							count.capacity++;
					}
				}
				if (count.capacity == 0)
				{
					cout << "There are no available seats!\n";
					exit();
					break;
				}
				cout << "How Many Seats You Want To Book? : ";
				cin >> cnum;
				if (cnum <= count.capacity)
				{

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					std::cout << "--------------------------------------------------" << endl;
					std::cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++) {

						cout << "Row: ";
						cin >> row;
						cout << "\nColumn: ";
						cin >> col;
						if (rSeats[row][col] == 0)
							rSeats[row][col] = 1;
						cout << endl;
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					cout << "The Ticket Has Been Booked" << endl;
				}
				else {
					cout << "there are only " << count.capacity << " seats left do you want to book them?(y/n) ";
					char t;
					cin >> t;
					if (t == 'y')
					{
						string FileName = "movie3.2.txt";
						fstream input(FileName, ios::in | ios::out | ios::app);
						int row = 0, col = 0;
						bool  rSeats[10][10];

						while (counter < count.capacity)
						{
							for (int i = 0; i < 10; i++)
								for (int j = 0; j < 10; j++)
									input >> rSeats[i][j];

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									if (rSeats[i][j] == 0)
										rSeats[i][j] = 1;
								}
								counter++;
							}

							ofstream Rewrite(FileName);

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									Rewrite << rSeats[i][j] << " ";
								}
								Rewrite << endl;
							}
						}
						cout << "--------------------------------------------------" << endl;
						cout << "Seats : " << endl;
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (rSeats[i][j] == 0)
								{
									cout << "_";
									setcolor(10);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
								else if (rSeats[i][j] == 1)
								{
									cout << "_";
									setcolor(12);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
							}
							cout << endl;
						}
						cout << endl;
						cout << "--------------------------------------------------" << endl;
						cout << "The Ticket Has Been Booked" << endl;
					}
					else {
						cout << "\t THANK YOU" << endl;
						exit();
					}
				}
				if (counter == cnum)
					break;
			}
		}
		//if the user can't reserve the movie at that moment of time (early time)
		else if ((hr[2][1] - 1 == t.hr && min[2][1] - t.minute >= 1) || hr[2][1] - t.hr > 1)
		{
			if (hr[2][1] - 1 == t.hr && min[2][1] - t.minute >= 1)
			{
				cout << "Sorry it's early to reserve this movie please try again after: " << min[2][1] - t.minute << " minute" << endl;
			}
			else if (hr[2][1] - t.hr > 1)
			{
				if (min[2][1] > t.minute)
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[2][1] - t.hr) - 1 << " hour and " << min[2][1] - t.minute << " minute" << endl;
				}
				else if (t.minute > min[2][1])
				{
					if ((hr[2][1] - t.hr) - 2 == 0)
					{
						cout << "Sorry it's early to reserve this movie please try again after: " << (60 - t.minute) + min[2][1] << " minute" << endl;
					}
					else
						cout << "Sorry it's early to reserve this movie please trt again after: " << (hr[2][1] - t.hr) - 2 << " hour and " << (60 - t.minute) + min[2][1] << " minute" << endl;
				}
				else if (t.minute == min[2][1])
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[2][1] - t.hr) - 1 << " hour " << endl;
				}
			}
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
		//if the user can't reserve the movie at that moment of time (late time)
		else if (t.hr > hr[2][1] || (t.hr == hr[2][1] && t.minute - min[2][1] > 15))
		{
			cout << "Sorry It's too late to reserve this movie " << endl;
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
	}

	if (Mnum == 4 && Mhr == 1)
	{
		//if the user can reserve the movie at that moment of time 
		if ((hr[3][0] == t.hr && (t.minute == min[3][0] || t.minute - min[3][0] <= 15)) //if global time = the movie's time

			|| (hr[3][0] - 1 == t.hr && t.minute >= min[3][0]))  //if movie's time greater than global time with 1hour
		{
			string FileName = "movie4.1.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);
			count.capacity = 0;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					input >> rSeats[i][j];
					if (rSeats[i][j] == 0)
					{
						count.capacity++;
					}
				}
			}

			if (count.capacity != 0)
			{
				std::cout << "How Many Seats You Want To Book? : ";
				cin >> cnum;
				if (cnum <= count.capacity)
				{

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					cout << "--------------------------------------------------" << endl;
					cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							cout << "Row: ";
							cin >> row;
							cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 0)
							{
								rSeats[row][col] = 1;
								std::cout << endl;
								break;
							}
							else if (rSeats[row][col] == 1)
							{
								std::cout << "Seat is already taken! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					std::cout << "The Ticket Has Been Booked" << endl;
				}
				else
				{
					cout << "There are " << count.capacity << " seats left only" << endl << "Do you want to book them?(y/n): ";
					char t;
					cin >> t;
					if (t == 'y')
					{
						int counter = 0;
						string FileName = "movie4.1.txt";
						fstream input(FileName, ios::in | ios::out | ios::app);
						int row = 0, col = 0;
						bool  rSeats[10][10];

						while (counter < count.capacity)
						{
							for (int i = 0; i < 10; i++)
								for (int j = 0; j < 10; j++)
									input >> rSeats[i][j];

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									if (rSeats[i][j] == 0)
										rSeats[i][j] = 1;
								}
								counter++;
							}

							ofstream Rewrite(FileName);

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									Rewrite << rSeats[i][j] << " ";
								}
								Rewrite << endl;
							}
						}
						cout << "--------------------------------------------------" << endl;
						cout << "Seats : " << endl;
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (rSeats[i][j] == 0)
								{
									cout << "_";
									setcolor(10);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
								else if (rSeats[i][j] == 1)
								{
									cout << "_";
									setcolor(12);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
							}
							cout << endl;
						}
						cout << endl;
						cout << "--------------------------------------------------" << endl;
						cout << "The Ticket Has Been Booked" << endl;
					}


				}
			}
			else
			{
				cout << endl;
				cout << "Sorry, there are no seats available!";
			}
		}
		//if the user can't reserve the movie at that moment of time (early time)
		else if ((hr[3][0] - 1 == t.hr && min[3][0] - t.minute >= 1) || hr[3][0] - t.hr > 1)
		{
			if (hr[3][0] - 1 == t.hr && min[3][0] - t.minute >= 1)
			{
				cout << "Sorry it's early to reserve this movie please try again after: " << min[3][0] - t.minute << " minute" << endl;
			}
			else if (hr[3][0] - t.hr > 1)
			{
				if (min[3][0] > t.minute)
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[3][0] - t.hr) - 1 << " hour and " << min[3][0] - t.minute << " minute" << endl;
				}
				else if (t.minute > min[3][0])
				{
					if ((hr[3][0] - t.hr) - 2 == 0)
					{
						cout << "Sorry it's early to reserve this movie please try again after: " << (60 - t.minute) + min[3][0] << " minute" << endl;
					}
					else
						cout << "Sorry it's early to reserve this movie please trt again after: " << (hr[3][0] - t.hr) - 2 << " hour and " << (60 - t.minute) + min[3][0] << " minute" << endl;
				}
				else if (t.minute == min[3][0])
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[3][0] - t.hr) - 1 << " hour " << endl;
				}
			}
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
		//if the user can't reserve the movie at that moment of time (late time)
		else if (t.hr > hr[3][0] || (t.hr == hr[3][0] && t.minute - min[3][0] > 15))
		{
			cout << "Sorry It's too late to reserve this movie " << endl;
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
	}
	if (Mnum == 4 && Mhr == 2)
	{
		if ((hr[3][1] == t.hr && (t.minute == min[3][1] || t.minute - min[3][1] <= 15)) //if global time = the movie's time

			|| (hr[3][1] - 1 == t.hr && t.minute >= min[3][1]))  //if movie's time greater than global time with 1hour
		{
			count.capacity = 0;
			int cnum, counter = 0;
			string FileName = "movie4.2.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);
			int row = 0, col;
			bool  rSeats[10][10];

			while (true)
			{
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						input >> rSeats[i][j];
						if (rSeats[i][j] == 0)
							count.capacity++;
					}
				}
				if (count.capacity == 0)
				{
					cout << "There are no available seats!\n";
					exit();
					break;
				}
				cout << "How Many Seats You Want To Book? : ";
				cin >> cnum;
				if (cnum <= count.capacity)
				{

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					std::cout << "--------------------------------------------------" << endl;
					std::cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++) {

						cout << "Row: ";
						cin >> row;
						cout << "\nColumn: ";
						cin >> col;
						if (rSeats[row][col] == 0)
							rSeats[row][col] = 1;
						cout << endl;
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					cout << "The Ticket Has Been Booked" << endl;
				}
				else {
					cout << "there are only " << count.capacity << " seats left do you want to book them?(y/n) ";
					char t;
					cin >> t;
					if (t == 'y')
					{
						string FileName = "movie4.2.txt";
						fstream input(FileName, ios::in | ios::out | ios::app);
						int row = 0, col = 0;
						bool  rSeats[10][10];

						while (counter < count.capacity)
						{
							for (int i = 0; i < 10; i++)
								for (int j = 0; j < 10; j++)
									input >> rSeats[i][j];

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									if (rSeats[i][j] == 0)
										rSeats[i][j] = 1;
								}
								counter++;
							}

							ofstream Rewrite(FileName);

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									Rewrite << rSeats[i][j] << " ";
								}
								Rewrite << endl;
							}
						}
						cout << "--------------------------------------------------" << endl;
						cout << "Seats : " << endl;
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (rSeats[i][j] == 0)
								{
									cout << "_";
									setcolor(10);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
								else if (rSeats[i][j] == 1)
								{
									cout << "_";
									setcolor(12);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
							}
							cout << endl;
						}
						cout << endl;
						cout << "--------------------------------------------------" << endl;
						cout << "The Ticket Has Been Booked" << endl;
					}
					else {
						cout << "\t THANK YOU" << endl;
						exit();
					}
				}
				if (counter == cnum)
					break;
			}
		}
		//if the user can't reserve the movie at that moment of time (early time)
		else if ((hr[3][1] - 1 == t.hr && min[3][1] - t.minute >= 1) || hr[3][1] - t.hr > 1)
		{
			if (hr[3][1] - 1 == t.hr && min[3][1] - t.minute >= 1)
			{
				cout << "Sorry it's early to reserve this movie please try again after: " << min[3][1] - t.minute << " minute" << endl;
			}
			else if (hr[3][1] - t.hr > 1)
			{
				if (min[3][1] > t.minute)
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[3][1] - t.hr) - 1 << " hour and " << min[3][1] - t.minute << " minute" << endl;
				}
				else if (t.minute > min[3][1])
				{
					if ((hr[3][1] - t.hr) - 2 == 0)
					{
						cout << "Sorry it's early to reserve this movie please try again after: " << (60 - t.minute) + min[3][1] << " minute" << endl;
					}
					else
						cout << "Sorry it's early to reserve this movie please trt again after: " << (hr[3][1] - t.hr) - 2 << " hour and " << (60 - t.minute) + min[3][1] << " minute" << endl;
				}
				else if (t.minute == min[3][1])
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[3][1] - t.hr) - 1 << " hour " << endl;
				}
			}
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
		//if the user can't reserve the movie at that moment of time (late time)
		else if (t.hr > hr[3][1] || (t.hr == hr[3][1] && t.minute - min[3][1] > 15))
		{
			cout << "Sorry It's too late to reserve this movie " << endl;
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
	}

	if (Mnum == 5 && Mhr == 1)
	{
		if ((hr[4][0] == t.hr && (t.minute == min[4][0] || t.minute - min[4][0] <= 15)) //if global time = the movie's time

			|| (hr[4][0] - 1 == t.hr && t.minute >= min[4][0]))  //if movie's time greater than global time with 1hour
		{
			string FileName = "movie5.1.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);
			count.capacity = 0;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					input >> rSeats[i][j];
					if (rSeats[i][j] == 0)
					{
						count.capacity++;
					}
				}
			}

			if (count.capacity != 0)
			{
				std::cout << "How Many Seats You Want To Book? : ";
				cin >> cnum;
				if (cnum <= count.capacity)
				{

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					cout << "--------------------------------------------------" << endl;
					cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							cout << "Row: ";
							cin >> row;
							cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 0)
							{
								rSeats[row][col] = 1;
								std::cout << endl;
								break;
							}
							else if (rSeats[row][col] == 1)
							{
								std::cout << "Seat is already taken! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					std::cout << "The Ticket Has Been Booked" << endl;
				}
				else
				{
					cout << "There are " << count.capacity << " seats left only" << endl << "Do you want to book them?(y/n): ";
					char t;
					cin >> t;
					if (t == 'y')
					{
						int counter = 0;
						string FileName = "movie5.1.txt";
						fstream input(FileName, ios::in | ios::out | ios::app);
						int row = 0, col = 0;
						bool  rSeats[10][10];

						while (counter < count.capacity)
						{
							for (int i = 0; i < 10; i++)
								for (int j = 0; j < 10; j++)
									input >> rSeats[i][j];

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									if (rSeats[i][j] == 0)
										rSeats[i][j] = 1;
								}
								counter++;
							}

							ofstream Rewrite(FileName);

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									Rewrite << rSeats[i][j] << " ";
								}
								Rewrite << endl;
							}
						}
						cout << "--------------------------------------------------" << endl;
						cout << "Seats : " << endl;
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (rSeats[i][j] == 0)
								{
									cout << "_";
									setcolor(10);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
								else if (rSeats[i][j] == 1)
								{
									cout << "_";
									setcolor(12);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
							}
							cout << endl;
						}
						cout << endl;
						cout << "--------------------------------------------------" << endl;
						cout << "The Ticket Has Been Booked" << endl;
					}


				}
			}
			else
			{
				cout << endl;
				cout << "Sorry, there are no seats available!";
			}
		}
		//if the user can't reserve the movie at that moment of time (early time)
		else if ((hr[4][0] - 1 == t.hr && min[4][0] - t.minute >= 1) || hr[4][0] - t.hr > 1)
		{
			if (hr[4][0] - 1 == t.hr && min[4][0] - t.minute >= 1)
			{
				cout << "Sorry it's early to reserve this movie please try again after: " << min[4][0] - t.minute << " minute" << endl;
			}
			else if (hr[4][0] - t.hr > 1)
			{
				if (min[4][0] > t.minute)
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[4][0] - t.hr) - 1 << " hour and " << min[4][0] - t.minute << " minute" << endl;
				}
				else if (t.minute > min[4][0])
				{
					if ((hr[4][0] - t.hr) - 2 == 0)
					{
						cout << "Sorry it's early to reserve this movie please try again after: " << (60 - t.minute) + min[4][0] << " minute" << endl;
					}
					else
						cout << "Sorry it's early to reserve this movie please trt again after: " << (hr[4][0] - t.hr) - 2 << " hour and " << (60 - t.minute) + min[4][0] << " minute" << endl;
				}
				else if (t.minute == min[4][0])
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[4][0] - t.hr) - 1 << " hour " << endl;
				}
			}
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
		//if the user can't reserve the movie at that moment of time (late time)
		else if (t.hr > hr[4][0] || (t.hr == hr[4][0] && t.minute - min[4][0] > 15))
		{
			cout << "Sorry It's too late to reserve this movie " << endl;
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
	}
	if (Mnum == 5 && Mhr == 2)
	{
		if ((hr[4][1] == t.hr && (t.minute == min[4][1] || t.minute - min[4][1] <= 15)) //if global time = the movie's time

			|| (hr[4][1] - 1 == t.hr && t.minute >= min[4][1]))  //if movie's time greater than global time with 1hour
		{
			count.capacity = 0;
			int cnum, counter = 0;
			string FileName = "movie5.2.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);
			int row = 0, col;
			bool  rSeats[10][10];

			while (true)
			{
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						input >> rSeats[i][j];
						if (rSeats[i][j] == 0)
							count.capacity++;
					}
				}
				if (count.capacity == 0)
				{
					cout << "There are no available seats!\n";
					exit();
					break;
				}
				cout << "How Many Seats You Want To Book? : ";
				cin >> cnum;
				if (cnum <= count.capacity)
				{

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					std::cout << "--------------------------------------------------" << endl;
					std::cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++) {

						cout << "Row: ";
						cin >> row;
						cout << "\nColumn: ";
						cin >> col;
						if (rSeats[row][col] == 0)
							rSeats[row][col] = 1;
						cout << endl;
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					cout << "The Ticket Has Been Booked" << endl;
				}
				else {
					cout << "there are only " << count.capacity << " seats left do you want to book them?(y/n) ";
					char t;
					cin >> t;
					if (t == 'y')
					{
						string FileName = "movie5.2.txt";
						fstream input(FileName, ios::in | ios::out | ios::app);
						int row = 0, col = 0;
						bool  rSeats[10][10];

						while (counter < count.capacity)
						{
							for (int i = 0; i < 10; i++)
								for (int j = 0; j < 10; j++)
									input >> rSeats[i][j];

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									if (rSeats[i][j] == 0)
										rSeats[i][j] = 1;
								}
								counter++;
							}

							ofstream Rewrite(FileName);

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									Rewrite << rSeats[i][j] << " ";
								}
								Rewrite << endl;
							}
						}
						cout << "--------------------------------------------------" << endl;
						cout << "Seats : " << endl;
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (rSeats[i][j] == 0)
								{
									cout << "_";
									setcolor(10);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
								else if (rSeats[i][j] == 1)
								{
									cout << "_";
									setcolor(12);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
							}
							cout << endl;
						}
						cout << endl;
						cout << "--------------------------------------------------" << endl;
						cout << "The Ticket Has Been Booked" << endl;
					}
					else {
						cout << "\t THANK YOU" << endl;
						exit();
					}
				}
				if (counter == cnum)
					break;
			}
		}
		//if the user can't reserve the movie at that moment of time (early time)
		else if ((hr[4][1] - 1 == t.hr && min[4][1] - t.minute >= 1) || hr[4][1] - t.hr > 1)
		{
			if (hr[4][1] - 1 == t.hr && min[4][1] - t.minute >= 1)
			{
				cout << "Sorry it's early to reserve this movie please try again after: " << min[4][1] - t.minute << " minute" << endl;
			}
			else if (hr[4][1] - t.hr > 1)
			{
				if (min[4][1] > t.minute)
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[4][1] - t.hr) - 1 << " hour and " << min[4][1] - t.minute << " minute" << endl;
				}
				else if (t.minute > min[4][1])
				{
					if ((hr[4][1] - t.hr) - 2 == 0)
					{
						cout << "Sorry it's early to reserve this movie please try again after: " << (60 - t.minute) + min[4][1] << " minute" << endl;
					}
					else
						cout << "Sorry it's early to reserve this movie please trt again after: " << (hr[4][1] - t.hr) - 2 << " hour and " << (60 - t.minute) + min[4][1] << " minute" << endl;
				}
				else if (t.minute == min[4][1])
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[4][1] - t.hr) - 1 << " hour " << endl;
				}
			}
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
		//if the user can't reserve the movie at that moment of time (late time)
		else if (t.hr > hr[4][1] || (t.hr == hr[4][1] && t.minute - min[4][1] > 15))
		{
			cout << "Sorry It's too late to reserve this movie " << endl;
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
	}

	if (Mnum == 6 && Mhr == 1)
	{
		if ((hr[5][0] == t.hr && (t.minute == min[5][0] || t.minute - min[5][0] <= 15)) //if global time = the movie's time

			|| (hr[5][0] - 1 == t.hr && t.minute >= min[5][0]))  //if movie's time greater than global time with 1hour
		{
			string FileName = "movie6.1.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);
			count.capacity = 0;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					input >> rSeats[i][j];
					if (rSeats[i][j] == 0)
					{
						count.capacity++;
					}
				}
			}

			if (count.capacity != 0)
			{
				std::cout << "How Many Seats You Want To Book? : ";
				cin >> cnum;
				if (cnum <= count.capacity)
				{

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;

					}
					cout << "--------------------------------------------------" << endl;
					cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++)
					{

						while (true)
						{
							cout << "Row: ";
							cin >> row;
							cout << "\nColumn: ";
							cin >> col;
							if (rSeats[row][col] == 0)
							{
								rSeats[row][col] = 1;
								std::cout << endl;
								break;
							}
							else if (rSeats[row][col] == 1)
							{
								std::cout << "Seat is already taken! Choose another seat.\n";
							}
						}
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					std::cout << "The Ticket Has Been Booked" << endl;
				}
				else
				{
					cout << "There are " << count.capacity << " seats left only" << endl << "Do you want to book them?(y/n): ";
					char t;
					cin >> t;
					if (t == 'y')
					{
						int counter = 0;
						string FileName = "movie6.1.txt";
						fstream input(FileName, ios::in | ios::out | ios::app);
						int row = 0, col = 0;
						bool  rSeats[10][10];

						while (counter < count.capacity)
						{
							for (int i = 0; i < 10; i++)
								for (int j = 0; j < 10; j++)
									input >> rSeats[i][j];

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									if (rSeats[i][j] == 0)
										rSeats[i][j] = 1;
								}
								counter++;
							}

							ofstream Rewrite(FileName);

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									Rewrite << rSeats[i][j] << " ";
								}
								Rewrite << endl;
							}
						}
						cout << "--------------------------------------------------" << endl;
						cout << "Seats : " << endl;
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (rSeats[i][j] == 0)
								{
									cout << "_";
									setcolor(10);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
								else if (rSeats[i][j] == 1)
								{
									cout << "_";
									setcolor(12);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
							}
							cout << endl;
						}
						cout << endl;
						cout << "--------------------------------------------------" << endl;
						cout << "The Ticket Has Been Booked" << endl;
					}


				}
			}
			else
			{
				cout << endl;
				cout << "Sorry, there are no seats available!";
			}
		}
		//if the user can't reserve the movie at that moment of time (early time)
		else if ((hr[5][0] - 1 == t.hr && min[5][0] - t.minute >= 1) || hr[5][0] - t.hr > 1)
		{
			if (hr[5][0] - 1 == t.hr && min[5][0] - t.minute >= 1)
			{
				cout << "Sorry it's early to reserve this movie please try again after: " << min[5][0] - t.minute << " minute" << endl;
			}
			else if (hr[5][0] - t.hr > 1)
			{
				if (min[5][0] > t.minute)
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[5][0] - t.hr) - 1 << " hour and " << min[5][0] - t.minute << " minute" << endl;
				}
				else if (t.minute > min[5][0])
				{
					if ((hr[5][0] - t.hr) - 2 == 0)
					{
						cout << "Sorry it's early to reserve this movie please try again after: " << (60 - t.minute) + min[5][0] << " minute" << endl;
					}
					else
						cout << "Sorry it's early to reserve this movie please trt again after: " << (hr[5][0] - t.hr) - 2 << " hour and " << (60 - t.minute) + min[5][0] << " minute" << endl;
				}
				else if (t.minute == min[5][0])
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[5][0] - t.hr) - 1 << " hour " << endl;
				}
			}
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
		//if the user can't reserve the movie at that moment of time (late time)
		else if (t.hr > hr[5][0] || (t.hr == hr[5][0] && t.minute - min[5][0] > 15))
		{
			cout << "Sorry It's too late to reserve this movie " << endl;
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
	}
	if (Mnum == 6 && Mhr == 2)
	{
		if ((hr[5][1] == t.hr && (t.minute == min[5][1] || t.minute - min[5][1] <= 15)) //if global time = the movie's time

			|| (hr[5][1] - 1 == t.hr && t.minute >= min[5][1]))  //if movie's time greater than global time with 1hour
		{
			count.capacity = 0;
			int cnum, counter = 0;
			string FileName = "movie6.2.txt";
			fstream input(FileName, ios::in | ios::out | ios::app);
			int row = 0, col;
			bool  rSeats[10][10];

			while (true)
			{
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						input >> rSeats[i][j];
						if (rSeats[i][j] == 0)
							count.capacity++;
					}
				}
				if (count.capacity == 0)
				{
					cout << "There are no available seats!\n";
					exit();
					break;
				}
				cout << "How Many Seats You Want To Book? : ";
				cin >> cnum;
				if (cnum <= count.capacity)
				{

					cout << "--------------------------------------------------" << endl;
					cout << "Seats : " << endl;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (rSeats[i][j] == 0)
							{
								cout << "_";
								setcolor(10);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
							else if (rSeats[i][j] == 1)
							{
								cout << "_";
								setcolor(12);
								cout << rSeats[i][j];
								setcolor(7);
								cout << "_";
							}
						}
						cout << endl;
						counter++;
					}
					std::cout << "--------------------------------------------------" << endl;
					std::cout << "enter row(s) and colum(s) : " << endl;;
					for (int i = 0; i < cnum; i++) {

						cout << "Row: ";
						cin >> row;
						cout << "\nColumn: ";
						cin >> col;
						if (rSeats[row][col] == 0)
							rSeats[row][col] = 1;
						cout << endl;
					}
					ofstream Rewrite(FileName);

					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							Rewrite << rSeats[i][j] << " ";
						}
						Rewrite << endl;
					}
					cout << "The Ticket Has Been Booked" << endl;
				}
				else {
					cout << "there are only " << count.capacity << " seats left do you want to book them?(y/n) ";
					char t;
					cin >> t;
					if (t == 'y')
					{
						string FileName = "movie6.2.txt";
						fstream input(FileName, ios::in | ios::out | ios::app);
						int row = 0, col = 0;
						bool  rSeats[10][10];

						while (counter < count.capacity)
						{
							for (int i = 0; i < 10; i++)
								for (int j = 0; j < 10; j++)
									input >> rSeats[i][j];

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									if (rSeats[i][j] == 0)
										rSeats[i][j] = 1;
								}
								counter++;
							}

							ofstream Rewrite(FileName);

							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									Rewrite << rSeats[i][j] << " ";
								}
								Rewrite << endl;
							}
						}
						cout << "--------------------------------------------------" << endl;
						cout << "Seats : " << endl;
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (rSeats[i][j] == 0)
								{
									cout << "_";
									setcolor(10);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
								else if (rSeats[i][j] == 1)
								{
									cout << "_";
									setcolor(12);
									cout << rSeats[i][j];
									setcolor(7);
									cout << "_";
								}
							}
							cout << endl;
						}
						cout << endl;
						cout << "--------------------------------------------------" << endl;
						cout << "The Ticket Has Been Booked" << endl;
					}
					else {
						cout << "\t THANK YOU" << endl;
						exit();
					}
				}
				if (counter == cnum)
					break;
			}
		}
		//if the user can't reserve the movie at that moment of time (early time)
		else if ((hr[5][1] - 1 == t.hr && min[5][1] - t.minute >= 1) || hr[5][1] - t.hr > 1)
		{
			if (hr[5][1] - 1 == t.hr && min[5][1] - t.minute >= 1)
			{
				cout << "Sorry it's early to reserve this movie please try again after: " << min[5][1] - t.minute << " minute" << endl;
			}
			else if (hr[5][1] - t.hr > 1)
			{
				if (min[5][1] > t.minute)
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[5][1] - t.hr) - 1 << " hour and " << min[5][1] - t.minute << " minute" << endl;
				}
				else if (t.minute > min[5][1])
				{
					if ((hr[5][1] - t.hr) - 2 == 0)
					{
						cout << "Sorry it's early to reserve this movie please try again after: " << (60 - t.minute) + min[5][1] << " minute" << endl;
					}
					else
						cout << "Sorry it's early to reserve this movie please trt again after: " << (hr[5][1] - t.hr) - 2 << " hour and " << (60 - t.minute) + min[5][1] << " minute" << endl;
				}
				else if (t.minute == min[5][1])
				{
					cout << "Sorry it's early to reserve this movie please try again after: " << (hr[5][1] - t.hr) - 1 << " hour " << endl;
				}
			}
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
		//if the user can't reserve the movie at that moment of time (late time)
		else if (t.hr > hr[5][1] || (t.hr == hr[5][1] && t.minute - min[5][1] > 15))
		{
			cout << "Sorry It's too late to reserve this movie " << endl;
			char answer;
			cout << endl;
			cout << "Do you want to try to reserve another movie or try to reserve this movie but the other version of time(y/n) : ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				booking(t);
			}
			else
			{
				exit();
			}

		}
	}
	return 0;
}

int readInfo(int choice)
{
	movie m[6];
	bool isNum = false, isNumber = false, check = false;
	switch (choice)
	{

	case 1:
	{

		check = true;
		ifstream cinema("Movie1.txt");

		cinema >> m[choice - 1].title.first >> m[choice - 1].title.last;

		if (m[choice - 1].title.last >= "0.1" && m[choice - 1].title.last <= "9.9")
		{
			m[choice - 1].rating = m[choice - 1].title.last;
			isNum = true;

		}
		else
		{
			cinema >> m[choice - 1].rating;
		}

		cinema >> m[choice - 1].genre.first >> m[choice - 1].genre.last;

		if (m[choice - 1].genre.last >= "0" && m[choice - 1].genre.last <= "12")
		{
			m[choice - 1].sinfo[0].screening_time.hour = m[choice - 1].genre.last;
			isNumber = true;
		}
		else
		{
			cinema >> m[choice - 1].sinfo[0].screening_time.hour;
		}

		cinema >> m[choice - 1].sinfo[0].screening_time.min >> m[choice - 1].sinfo[0].screening_time.ampm;
		cinema >> m[choice - 1].sinfo[1].screening_time.hour >> m[choice - 1].sinfo[1].screening_time.min >> m[choice - 1].sinfo[1].screening_time.ampm;
		cinema >> m[choice - 1].sinfo[0].theatre;
		cinema >> m[choice - 1].sinfo[0].screen;
		cinema >> m[choice - 1].directors.first >> m[choice - 1].directors.last;
		cinema >> m[choice - 1].actor[0].first >> m[choice - 1].actor[0].last;
		cinema >> m[choice - 1].actor[1].first >> m[choice - 1].actor[1].last;
		break;
	}

	case 2:
	{
		check = true;
		ifstream cinema("Movie2.txt");

		cinema >> m[choice - 1].title.first >> m[choice - 1].title.last;

		if (m[choice - 1].title.last >= "0.1" && m[choice - 1].title.last <= "9.9")
		{
			m[choice - 1].rating = m[choice - 1].title.last;
			isNum = true;
		}
		else
		{
			cinema >> m[choice - 1].rating;
		}
		cinema >> m[choice - 1].genre.first >> m[choice - 1].genre.last;

		if (m[choice - 1].genre.last >= "0" && m[choice - 1].genre.last <= "12")
		{
			m[choice - 1].sinfo[0].screening_time.hour = m[choice - 1].genre.last;
			isNumber = true;
		}
		else
		{
			cinema >> m[choice - 1].sinfo[0].screening_time.hour;
		}

		cinema >> m[choice - 1].sinfo[0].screening_time.min >> m[choice - 1].sinfo[0].screening_time.ampm;
		cinema >> m[choice - 1].sinfo[1].screening_time.hour >> m[choice - 1].sinfo[1].screening_time.min >> m[choice - 1].sinfo[1].screening_time.ampm;
		cinema >> m[choice - 1].sinfo[0].theatre;
		cinema >> m[choice - 1].sinfo[0].screen;
		cinema >> m[choice - 1].directors.first >> m[choice - 1].directors.last;
		cinema >> m[choice - 1].actor[0].first >> m[choice - 1].actor[0].last;
		cinema >> m[choice - 1].actor[1].first >> m[choice - 1].actor[1].last;
		break;
	}

	case 3:
	{
		check = true;
		ifstream cinema("Movie3.txt");

		cinema >> m[choice - 1].title.first >> m[choice - 1].title.last;

		if (m[choice - 1].title.last >= "0.1" && m[choice - 1].title.last <= "9.9")
		{
			m[choice - 1].rating = m[choice - 1].title.last;
			isNum = true;
		}
		else
		{
			cinema >> m[choice - 1].rating;
		}

		cinema >> m[choice - 1].genre.first >> m[choice - 1].genre.last;

		if (m[choice - 1].genre.last >= "0" && m[choice - 1].genre.last <= "12")
		{
			m[choice - 1].sinfo[0].screening_time.hour = m[choice - 1].genre.last;
			isNumber = true;
		}
		else
		{
			cinema >> m[choice - 1].sinfo[0].screening_time.hour;
		}

		cinema >> m[choice - 1].sinfo[0].screening_time.min >> m[choice - 1].sinfo[0].screening_time.ampm;
		cinema >> m[choice - 1].sinfo[1].screening_time.hour >> m[choice - 1].sinfo[1].screening_time.min >> m[choice - 1].sinfo[1].screening_time.ampm;
		cinema >> m[choice - 1].sinfo[0].theatre;
		cinema >> m[choice - 1].sinfo[0].screen;
		cinema >> m[choice - 1].directors.first >> m[choice - 1].directors.last;
		cinema >> m[choice - 1].actor[0].first >> m[choice - 1].actor[0].last;
		cinema >> m[choice - 1].actor[1].first >> m[choice - 1].actor[1].last;
		break;
	}

	case 4:
	{
		check = true;
		ifstream cinema("Movie4.txt");

		cinema >> m[choice - 1].title.first >> m[choice - 1].title.last;

		if (m[choice - 1].title.last >= "0.1" && m[choice - 1].title.last <= "9.9")
		{
			m[choice - 1].rating = m[choice - 1].title.last;
			isNum = true;
		}
		else
		{
			cinema >> m[choice - 1].rating;
		}
		cinema >> m[choice - 1].genre.first >> m[choice - 1].genre.last;

		if (m[choice - 1].genre.last >= "0" && m[choice - 1].genre.last <= "12")
		{
			m[choice - 1].sinfo[0].screening_time.hour = m[choice - 1].genre.last;
			isNumber = true;
		}
		else
		{
			cinema >> m[choice - 1].sinfo[0].screening_time.hour;
		}

		cinema >> m[choice - 1].sinfo[0].screening_time.min >> m[choice - 1].sinfo[0].screening_time.ampm;
		cinema >> m[choice - 1].sinfo[1].screening_time.hour >> m[choice - 1].sinfo[1].screening_time.min >> m[choice - 1].sinfo[1].screening_time.ampm;
		cinema >> m[choice - 1].sinfo[0].theatre;
		cinema >> m[choice - 1].sinfo[0].screen;
		cinema >> m[choice - 1].directors.first >> m[choice - 1].directors.last;
		cinema >> m[choice - 1].actor[0].first >> m[choice - 1].actor[0].last;
		cinema >> m[choice - 1].actor[1].first >> m[choice - 1].actor[1].last;
		break;
	}

	case 5:
	{
		check = true;
		ifstream cinema("Movie5.txt");

		cinema >> m[choice - 1].title.first >> m[choice - 1].title.last;

		if (m[choice - 1].title.last >= "0.1" && m[choice - 1].title.last <= "9.9")
		{
			m[choice - 1].rating = m[choice - 1].title.last;
			isNum = true;
		}
		else
		{
			cinema >> m[choice - 1].rating;
		}
		cinema >> m[choice - 1].genre.first >> m[choice - 1].genre.last;

		if (m[choice - 1].genre.last >= "0" && m[choice - 1].genre.last <= "12")
		{
			m[choice - 1].sinfo[0].screening_time.hour = m[choice - 1].genre.last;
			isNumber = true;
		}
		else
		{
			cinema >> m[choice - 1].sinfo[0].screening_time.hour;
		}

		cinema >> m[choice - 1].sinfo[0].screening_time.min >> m[choice - 1].sinfo[0].screening_time.ampm;
		cinema >> m[choice - 1].sinfo[1].screening_time.hour >> m[choice - 1].sinfo[1].screening_time.min >> m[choice - 1].sinfo[1].screening_time.ampm;
		cinema >> m[choice - 1].sinfo[0].theatre;
		cinema >> m[choice - 1].sinfo[0].screen;
		cinema >> m[choice - 1].directors.first >> m[choice - 1].directors.last;
		cinema >> m[choice - 1].actor[0].first >> m[choice - 1].actor[0].last;
		cinema >> m[choice - 1].actor[1].first >> m[choice - 1].actor[1].last;
		break;
	}

	case 6:
	{
		check = true;
		ifstream cinema("Movie6.txt");

		cinema >> m[choice - 1].title.first >> m[choice - 1].title.last;

		if (m[choice - 1].title.last >= "0.1" && m[choice - 1].title.last <= "9.9")
		{
			m[choice - 1].rating = m[choice - 1].title.last;
			isNum = true;
		}
		else
		{
			cinema >> m[choice - 1].rating;
		}
		cinema >> m[choice - 1].genre.first >> m[choice - 1].genre.last;

		if (m[choice - 1].genre.last >= "0" && m[choice - 1].genre.last <= "12")
		{
			m[choice - 1].sinfo[0].screening_time.hour = m[choice - 1].genre.last;
			isNumber = true;
		}
		else
		{
			cinema >> m[choice - 1].sinfo[0].screening_time.hour;
		}

		cinema >> m[choice - 1].sinfo[0].screening_time.min >> m[choice - 1].sinfo[0].screening_time.ampm;
		cinema >> m[choice - 1].sinfo[1].screening_time.hour >> m[choice - 1].sinfo[1].screening_time.min >> m[choice - 1].sinfo[1].screening_time.ampm;
		cinema >> m[choice - 1].sinfo[0].theatre;
		cinema >> m[choice - 1].sinfo[0].screen;
		cinema >> m[choice - 1].directors.first >> m[choice - 1].directors.last;
		cinema >> m[choice - 1].actor[0].first >> m[choice - 1].actor[0].last;
		cinema >> m[choice - 1].actor[1].first >> m[choice - 1].actor[1].last;
		break;
	}

	default:
	{
		system("CLS");
		cout << "Invalid choice! Choose again or type '0' to exit.\nChoice: ";
	}

	}

	if (check)
	{
		system("CLS");
		DisplayHeader();
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "Name:		" << m[choice - 1].title.first;

		if (isNum)
		{
			cout << endl << "Ratings:	" << m[choice - 1].rating << "/10" << endl;
		}
		else
		{
			cout << " " << m[choice - 1].title.last << endl;
			cout << "Ratings:	" << m[choice - 1].rating << "/10" << endl;
		}
		cout << "Genre:		" << m[choice - 1].genre.first;

		if (isNumber)
		{
			cout << endl << "Time:		" << m[choice - 1].sinfo[0].screening_time.hour;
		}
		else
		{
			cout << " " << m[choice - 1].genre.last;
			cout << endl << "Time:		" << m[choice - 1].sinfo[0].screening_time.hour;
		}

		cout << ":" << m[choice - 1].sinfo[0].screening_time.min << " " << m[choice - 1].sinfo[0].screening_time.ampm << endl;
		cout << "		" << m[choice - 1].sinfo[1].screening_time.hour << ":" << m[choice - 1].sinfo[1].screening_time.min << " " << m[choice - 1].sinfo[1].screening_time.ampm << endl;
		cout << "Theatre:	" << m[choice - 1].sinfo[0].theatre << endl;
		cout << "Screen:		" << m[choice - 1].sinfo[0].screen << endl;
		cout << "Director:	" << m[choice - 1].directors.first << " " << m[choice - 1].directors.last << endl;
		cout << "Actors:		" << m[choice - 1].actor[0].first << " " << m[choice - 1].actor[0].last << ", " << m[choice - 1].actor[1].first << " " << m[choice - 1].actor[1].last << endl;
	}
	return 0;
}

void showMenu()
{
	DisplayHeader();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "     Main Menu   " << endl;
	cout << "=================" << endl;
	cout << endl;
	cout << "  1-Show All Movies  " << endl;
	cout << "  2-Booking  " << endl;
	cout << "  3-Cancel Ticket " << endl;
	cout << "  4-Show Seats Shape" << endl;
	cout << "  5-Exit" << endl << endl;

	cout << " Enter Your Choice : ";
}

void mainmenu(int ch)
{
	stime t;
	t.hr = 12; //global time(hour) (24-hour system)
	t.minute = 59; //global time(minute)
	int choicee;
	char chh;
	switch (ch)
	{
	case 1:
		system("cls");
		DisplayHeader();
		cout << endl;
		cout << endl;
		cout << endl;
		while (true)
		{
			cout << "1.Black Panther\n2.Red Sparrow\n3.Slumber\n4.Rampage\n5.Tomb Raider\n6.Death Wish\n\nYour choice: ";
			cin >> choicee;
			readInfo(choicee);
			cout << "Do you want to choose another movie? (y/n): ";
			cin >> chh;
			if (chh == 'n')
				break;
			else
			{
				system("cls");
				DisplayHeader();
				cout << endl;
				cout << endl;
				cout << endl;
				continue;
			}
		}
		break;
	case 2:
		system("cls");
		DisplayHeader();
		cout << endl;
		cout << endl;
		cout << endl;
		booking(t);
		break;
	case 3:
		system("cls");
		DisplayHeader();
		cout << endl;
		cout << endl;
		cout << endl;
		cancellation(t);
		break;
	case 4:
		system("cls");
		DisplayHeader();
		cout << endl;
		cout << endl;
		cout << endl;
		seats();
		break;
	case 5:
		system("cls");
		DisplayHeader();
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "Thank you!";
		exit();
		break;
	default:
		system("cls");
		DisplayHeader();
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "Wrong Choice Try Again" << endl;
	}

}

int main()
{

	while (true)
	{
		int ch;
		showMenu();
		cin >> ch;
		if (ch == 5)
			break;
		mainmenu(ch);
		char answer;

		cout << endl;

		cout << "Do You Want To Go To Main Menu Again?(y/n) ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			showMenu();
		}
		else
		{
			system("cls");
			DisplayHeader();
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "thank you" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}
