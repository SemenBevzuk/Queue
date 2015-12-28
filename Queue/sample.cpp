#include "tqueue.h"
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include "tqueue.h"

void main()
{
	double p, q;
	double temp;
	int K=1;
	TQueue<double> A(100);
	cout << "To enter probability input/output" << endl;
	cin >> p;
	while ( K==1 )
	{
		//srand(time());
		temp = rand() / ((double)RAND_MAX);
		cout << " temp =  "<< temp << endl;
		cout << " p =  " << p << endl;

		if ( temp <= p ) 
		{
			 A.Push(temp);
			 cout << " Insertion in the queue " << endl;
			 A.Print();
		}
		else 
		{
			A.Pop();
			cout << " Extract from the queue " << endl;
			A.Print();
		}
		cout << "Do you want to continue? (yes - 1, no - 0 )" << endl;
		cin >> K;
    }
}
