// hello world.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<stdio.h>
#include <iostream>
#include<stdio.h>
#define n 5
#define days 6
using namespace std;
void main()
{
	int schedule[n][days] = {
		{0,1,2,3,4,'o'},
		{'o',0,1,2,3,4},
		{4,'o',0,1,2,3},
		{3,4,'o',0,1,2},
		{2,3,4,'o',0,1}
	};
	int port_matched[n];
	int ship_matched[n];
	int result[n];//ship matched to port
	int i,j;
	// initializing parts matched and ships matched to 0
	for (int i = 0; i < n; i++)
	{
		port_matched[i] = 0;
		ship_matched[i] = 0;
	}
	/*for (i = 0; i < n; i++)
	{
		cout <<endl<< "enter schedule for ship-" << i << "enter o for sea" << endl << endl;
		for (j = 0; j < days; j++)
		{
			cout << "day -- " << j << "  port -- ";
			cin >> schedule[i][j];
		}
	}*/
	int preference[n][n];
	for (i = 0; i < n; i++)
	{
			for (int k = days-1,j=0; k >= 0 && j<n; k--)
			{
				if (schedule[i][k] != 'o')
				{
					preference[i][j] = schedule[i][k];
					j++;
				}
			}
	}
	for (i = 0; i < n; i++)
	{
		cout <<endl<< "schedule for ship --  " << i << endl;
		for (j = 0; j < n; j++)
		{
			cout << preference[i][j]<<"  ";
		}
	}
	int count = 0,port;
	while (count < n)
	{
		for (int i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				port = preference[i][j];
				if (ship_matched[i] == 0 && port_matched[port] == 0)
				{
					ship_matched[i] = 1;
					port_matched[port] = 1;
					result[i] = port;
					count++;
					break;
				}

			}
		}
	}
	for (i = 0; i < n; i++)
	{
		cout <<endl<< "ship --  " << i << "schedule" << endl;
		for (j = 0; j < days; j++)
		{
			if (schedule[i][j] == result[i])
				break;
			cout << "    " << schedule[i][j];
		}
	}


}