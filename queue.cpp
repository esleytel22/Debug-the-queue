// On some compilers this works as expected, but ...
// on some  .... try it and see what happens.

#include <iostream>
using namespace std;


class queue
{
private:
	char* s;
	int F, R, size;
public:
	queue(int i = 4)
	{
		s = new char[i];
		size = i;
		F = R = -1;
	}

	~queue()
	{
		delete[]s;
	}

	bool empty()
	{
		return F == R;
	}

	/*	bool full()//this is for a non circular queue
		{
			if (F==-1 && R==size-1)
				return true;
			for (int i=0; i<=F; i++)
				s[i]=s[F+i+1];
			R=R-F-1;
			F=-1;
			return false;
		}*/

	bool full()
	{
		if ((R + 1) % 5 == F)
			return true;
		return false;
	}


	/*	void add (char c)//non circular add
		{
			if (full())
			{
				cout << "queue is full";
				exit(1);
			}
			R++;
			s[R]=c;
		}*/

	void add(char c)
	{
		if (full())
		{
			cout << "queue is full";
			exit(1);
		}
		R = (R + 1) % size;
		s[R] = c;
	}

	/*	char del()// non circular
		{
			if (empty())
			{
				cout << "queue empty";
				exit(1);
			}
			F++;
			return s[F];
		}*/

	char del()
	{
		if (empty())
		{
			cout << "queue empty";
			exit(1);
		}
		F = (F + 1) % size;//only difference
		return s[F];
	}


};

int main()
{
	queue q;
	q.add('a');
	q.add('b');
	q.add('c');
	q.add('g');
	//cout << q.del() << q.del() << q.del() << q.del();
	cout << q.del();
	cout << q.del();
	cout << q.del();
	cout << q.del();

	std::cin.get();
	return 0;
}
/*when doing a cout in a seperate lines we get the output to be normal as first come first serve
but when we get the cout all in one line the output gets reversed. 
normally a, b, c, g gets entered 'a' should be del, the b, c, g. but if the cout is in one line 
the output shows gbca which is wrong. 
to fix this we by seperating the cout with each line.
*/