#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int numcomp, numcopies;
const int maxnum=10000;

void swapem(double &a, double &b)
{
    double temp;
    temp=a;
    a=b;
    b=temp;
    numcopies+=3;
}

void quicksort1(double a[], int left, int right)
{
	int j,k;
    if (left<right)
    {
        j=left+1;
        k=right;
        while (j<=k)
        {
            while (a[j]<a[left])
			{		
				j++;
				numcomp++;
			}
			while (a[k]>a[left])
			{
				k--;
				numcomp++;
			}
			if (j<k)
				swapem(a[j],a[k]);
        }
		swapem(a[left],a[k]);
        quicksort1(a,left,k-1);
        quicksort1(a,k+1,right);
    }
}
void bubblesort(double a[])
{
    int i,j;
    for (i=0;i<maxnum-1; i++)
    {
        for (j=0; j<maxnum-1; j++)
        {
			numcomp++;
            if (a[j]>a[j+1])
			{
				swapem (a[j],a[j+1]);
				numcopies++;
			}
		}
	}
}
void selectionsort(double a[])
{
    int j,k,small;
    if (maxnum>0)
    {
        for (k=0;k<maxnum-1;k++)
		{
            small=k;
            for (j=k+1;j<maxnum;j++)
            {
                if (a[j]<a[small])
				{
                    small=j;
				}
			    numcomp++;
			}
			if (k!=small)
            {
                swapem (a[k],a[small]); 
			    numcopies++;
			}
		}
		
	}
}
        
void insertionsort(double a[])
{
    int j,k;
	double save;
	for (k=maxnum-2;k>=0;k--)
	{
		j=k+1;
		save=a[k];
		numcopies++;
		a[maxnum]=save;
	
		while (save>a[j])
	{
		a[j-1]=a[j];
		j=j+1;
		numcomp++;
	}
		a[j-1]=save;
	}
}
void readem(double a[])
{
	int i;
    ifstream inf("Data.dat");
    for (i=0;i<maxnum;i++)
	{
		inf >> a[i];
	}
}
void printem(double a[], int i, ofstream &outf)
{
	switch(i)
	   {
	   case 0: outf << "bubblesort	N = " << maxnum << endl;
		   outf << a[999] << "	" << a[1999] << "	" << a[2999] << "	" << a[3999] << "	" << a[4999] << endl;
		   outf << a[5999] <<"	" << a[6999] << "	" << a[7999] << "	" << a[8999] << "	" << a[9999] << endl;
		   outf << "Number of compares = " << numcomp << "		Number of moves = " << numcopies << endl;
		   outf << "Relative # of compares = " << double (numcomp)/maxnum << "		Relative # of moves = " << double (numcopies)/maxnum << endl;
		   break;
	   case 1: outf << "selectionsort	N = " << maxnum << endl;
		   outf << a[999] << "	" << a[1999] << "	" << a[2999] << "	" << a[3999] << "	" << a[4999] << endl;
		   outf << a[5999] <<"	" << a[6999] << "	" << a[7999] << "	" << a[8999] << "	" << a[9999] << endl;
		   outf << "Number of compares = " << numcomp << "		Number of moves = " << numcopies << endl;
		   outf << "Relative # of compares = " << double (numcomp)/maxnum << "		Relative # of moves = " << double (numcopies)/maxnum << endl;
		   break;
	   case 2: outf << "insertionsort	N = " << maxnum << endl;
		   outf << a[999] << "	" << a[1999] << "	" << a[2999] << "	" << a[3999] << "	" << a[4999] << endl;
		   outf << a[5999] <<"	" << a[6999] << "	" << a[7999] << "	" << a[8999] << "	" << a[9999] << endl;
		   outf << "Number of compares = " << numcomp << "		Number of moves = " << numcopies << endl;
		   outf << "Relative # of compares = " << double (numcomp)/maxnum << "		Relative # of moves = " << double (numcopies)/maxnum << endl;
		   break;
	   case 3: outf << "quicksort1	N = " << maxnum << endl;
		   outf << a[999] << "	" << a[1999] << "	" << a[2999] << "	" << a[3999] << "	" << a[4999] << endl;
		   outf << a[5999] <<"	" << a[6999] << "	" << a[7999] << "	" << a[8999] << "	" << a[9999] << endl;
		   outf << "Number of compares = " << numcomp << "		Number of moves = " << numcopies << endl;
		   outf << "Relative # of compares = " << double (numcomp)/maxnum << "		Relative # of moves = " << double (numcopies)/maxnum << endl;
		   break;
	   }
}
void main()
                    
{
   int numloops=4;
   int i;
   double a[maxnum+1];
   ofstream outf("Output.out");
   outf.precision(4);
   outf.setf(ios::fixed);
   for (i=0;i<numloops;i++)
   {
	   readem (a);
	   numcomp=0;
	   numcopies=0;
	   switch(i)
	   {
	   case 0: bubblesort(a);
		       break;
	   case 1: selectionsort(a);
		       break;
	   case 2: insertionsort(a);
		       break;
	   case 3: quicksort1(a,0,maxnum-1);
			   break;
	   }
	   printem (a,i, outf);
   }
}