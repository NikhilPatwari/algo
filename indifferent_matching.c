// hello world.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<stdio.h>
#include <iostream>
#include<stdio.h>
#define n 5
using namespace std;
bool is_prefer_m_over_m1(int women_preference[n][n],int women_preference_rank[n][n],int men1,int men2,int women)
{
	int j, x, y;
	for (j = 0; j < n; j++)
	{
		if (women_preference[women][j] == men2)
		{	
			x = women_preference_rank[women][j];
		}
		if (women_preference[women][j] == men1)
		{
			y = women_preference_rank[women][j];
		}
	}
	if (y < x)
	{
		return true;
	}
	else if (y >= x)
		return false;

}
void main()
{
	int men_preference[n][n]={
		{1,0,3,4,2},
		{3,1,0,2,4},
		{1,4,2,3,0},
		{0,3,2,1,4},
		{1,3,0,4,2}
	};;
	int women_preference[n][n] = {
		{4,0,1,3,2},
		{2,1,3,0,4},
		{1,2,3,4,0},
		{0,4,3,2,1},
		{3,1,4,2,0}
	};
	int men_preference_rank[n][n] = {
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5}
	};
	int women_preference_rank[n][n] = {
		{1,1,1,4,5},
		{1,2,3,4,5},
		{1,2,3,3,5},
		{1,3,3,4,5},
		{1,2,3,3,5}
	};
	int result[n];//women mathed to men
	bool men_matched[n];
	bool women_matched[n];
	int i, j, count, x, y, z,men,women,men2;
	// initialization of men_matched and women_matched to 0
	for (i = 0; i < n; i++)
	{
		men_matched[i] = 0;
		women_matched[i] = 0;
	}
	//taking input of rank and preference for men and women
	/*for (i = 0; i < n; i++)
	{
		cout <<endl<< "  enter men  -- "<<i<<"  preference with ranking  " << endl;
		
		for (j = 0; j < n; j++)
		{
			cout << "  preference";
			cin >> men_preference[i][j]; cout << "    rank"; cin >> men_preference_rank[i][j]; cout << endl;
		}
	}
	cout << endl;
	{
		cout << endl << "  enter men  -- " << i << "  preference with ranking  " << endl;
		cout << "  preference" << "     rank" << endl;
		for (j = 0; j < n; j++)
		{
			cin >> women_preference[i][j]; cout << "     "; cin >> women_preference_rank[i][j];
		}
	}*/
	count = 0;
	while (count < n)
	{
		i = 0;//i is man
		j = 0;
		while (men_matched[i] == true && i<n)
			i++;
		while (men_matched[i] == false && j<n && i<n)
		{
			women = men_preference[i][j];
			if (women_matched[women] == false)
			{
				men_matched[i] = true;
				women_matched[women] = true;
				result[women] = i;
				count++;
				break;
			}else if (women_matched[women] == true && men_matched[i] == false && is_prefer_m_over_m1(women_preference, women_preference_rank, i, result[women], women))
			{
				men2 = result[women];
				men_matched[i] = true;
				women_matched[women] = true;
				men_matched[men2] = false;
				result[women] = i;
				break;
			}else
			{
				j++;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << endl << "woman -- " << i << "  matched to men -- " << result[i];
	}
}