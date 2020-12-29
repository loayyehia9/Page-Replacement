
#include<iostream>
using namespace std;
int main()
{
	//initialization
	int  NOFrames, NOPages, Page_Fault = 0, j, hit = 0; 
	int* ArrayP, * ArrayF;
	int Flag;
	//Take user input
	cout << "Enter page numbers =  ";
	cin >> NOPages;
	ArrayP = new int[NOPages];
	cout << "Enter the pages : " << endl;
	for (int i = 0; i < NOPages; i++)
	{
		cin >> ArrayP[i];
	}
 	cout << "Enter number of frames =  ";
	cin >> NOFrames;
	ArrayF = new int[NOFrames];
	//Fill the frames array with -1(free)
	for (int l = 0; l < NOFrames; l++)
	{
		ArrayF[l] = -1;
	}
	j = 0;
	cout << ".------------------------------------------------------------." << endl;
	cout << "Frames Display" << endl;
	//Nested loop 
	for (int p = 0; p < NOPages; p++)// For loop on pages array   
	{
		cout << " Page num :" << ArrayP[p] << "\t";
		Flag = 0;
		for (int h = 0; h <= NOFrames - 1; h++)// For loop on Frames array  
		{
			if (ArrayF[h] == ArrayP[p])//See if this page is in the frames or not 
			{
				Flag = 1;
				hit++;
			}
		}
		if (Flag == 0)//Page is not in the frames  -->  make swipe in nad swipe out 
		{
			ArrayF[j] = ArrayP[p];
			j = (j + 1) % NOFrames;
			Page_Fault++;

			for (int k = 0; k < NOFrames; k++)// display the pages in the frames  
				cout << ArrayF[k] << "\t";
		}
		cout << endl;
	}
	// Display Number of page fault and hit 
	cout << ".------------------------------------------------------------." << endl;
	cout << "Num of Page Fault =  " << Page_Fault << endl;
	cout << " Num of Hit = " << hit;
	return 0;
}