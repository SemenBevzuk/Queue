#pragma once

#include <iostream>
#include <stdio.h>
#include <conio.h>
 #include <iomanip>


using namespace std;

template <class T>
class TQueue {
	int begin, end, len, maxsize;
	T *mas;
public:
	TQueue( int _maxsize); 
	~TQueue();
	TQueue (const TQueue & ); // конструктор копирования

	TQueue &operator =(const TQueue & ); 

	int IsFull(); // проверка полноты
	int IsEmpty(); // проверка пустоты

	void Push(T ); // вставить элемент
	T Pop(); // извдечь элемент

	void Print();
};

template <class T>
TQueue <T> :: TQueue( int _maxsize)
{
	if ( _maxsize >0) {
		maxsize = _maxsize;
	    mas = new T [maxsize];
		len = 0;
		begin = 0;
		end = -1;
	}
	else throw maxsize;
}

template <class T>
TQueue <T> :: ~TQueue()
{
	delete[] mas;
}

template <class T>   // конструктор копирования
TQueue <T> :: TQueue( const TQueue & Q)
{
	 maxsize = Q.maxsize;
	 begin = Q.begin;
	 end = Q.end;
	 len = Q.len;
	 mas = new ValType [maxsize];
	 for (int i=0; i<= len; i++)
	 mas[i] = Q.mas[i]; 
}


template <class T>
TQueue<T> &TQueue <T> :: operator=( const TQueue & Q)
{
	 if (maxsize != Q.maxsize)
	 {
		 delete [] mas;
		 mas = new T [Q.maxsize];
	 }
	 maxsize = Q.maxsize;
	 begin = Q.begin;
	 end = Q.end;
	 len = Q.len;
	 for (int i=0; i<= len; i++)
	 mas[i] = Q.mas[i];
	 return *this;
}

template <class T>   // проверка полноты
int TQueue <T> :: IsFull()
{
	return  ( len  == maxsize );
}

template <class T>  // проверка пустоты
int TQueue <T> :: IsEmpty()
{
	return  ( len  == 0);
}


template <class T>   // вставить элемент
void TQueue <T> :: Push(T elem)
{
	if ( IsFull() ) throw maxsize;
	else 
		if (end == maxsize-1) end=0;
		else 
			{
		       end++;
			   mas[end] = elem;
	           len++;
	        }
}

template <class T>   // извлечь элемент
T TQueue <T> :: Pop()
{
	if ( IsEmpty() ) throw len;
	else
	{
		T elem = mas[begin];
		if ( begin == maxsize-1 ) begin = 0;
		else 
			begin --;
		len--;
		return elem;
	}

}

template <class T>   // печатать очередь
void TQueue <T> :: Print()
{
	int i = len-1;//i = len; // по идее len больше индекса на 1...
	while( i >= 0 ) // нулевой индекс обрабатываться должен 
		{
			cout << ' '<< mas[i] << endl;
		  //printf("%.6f", mas[i]);
			//printf("%g", mas[i]) ;
			/*cout.setf(ios::fixed);
            cout << setw(10)<<setprecision(6)<<mas[i];
			cout.unsetf(ios::fixed);*/
		  cout << ' ' ; //зачем столько пробелов? 
		  i--;
	    }
	cout << '\n';
} 
