#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;
const int N=34;
const int k=3;
//const int kk=23;
const int b=2;
string shifr (int k,string c,int b,int N)
{
	for (int i=0; i<c.length();i++)
	{
		int m=(int)c[i],x,y,n;
		if (m==43)
			x=32;
		else if (m==32)
			x=33;
		else
			x=m+32;
		y=(k*x+b)%N;
		if (y==32)
			n=43;
		else if (y==33)
			n=32;
		else
			n=y-32;
		c[i]=(char)n;
	}
return c;
}
string deshifr (int kk, string c, int b, int N)
{
	for (int i=0;i<c.length();i++)
	{
		int m=(int)c[i],x,y,n;
		if (m==43)
			y=32;
		else if (m==32)
			y=33;
		else
			y=m+32;
		if (y-b<0)
			x=-abs((y-b)*kk%N)+N;
		else
		x=(y-b)*kk%N;
		if (x==32)
			n=43;
		else if (x==33)
			n=32;
		else
			n=x-32;
		c[i]=(char)n;
	}
	return c;
}
int evklid (int k, int b, int N)
{
	if ((k<=0)||(k>=N)||(b<=0)||(b>=N))
	{
		cout<<"Заданные значения k,b и N некорректны, программа выполняться не будет"<<endl;
		system("pause");
		exit(0);
	}
	int i=0,q,x0=1,x1=0,y0=0,y1=1,a=1,kk,N0=N;
	while (a==1)
	{
		q=k/N;
		int newk=N;
		int newN=k%N;
		int newx0=x1;
		int newx1=x0-q*x1;
		int newy0=y1;
		int newy1=y0-q*y1;
		k=newk;
		N=newN;
		x0=newx0;
		x1=newx1;
		y0=newy0;
		y1=newy1;
		if (N==0)
		{
			if (k!=1)
			{
				cout<<"НОД k и N не равен 1, программа выполняться не будет"<<endl;
				system("pause");
				exit(0);
			}
			else
			{
				kk=x0;
				if (kk<0)
					kk=-abs(kk)%N0+N0;
				a=0;
			}
		}
	}
	return kk;
}
int main()
{
	int com;
	setlocale(LC_ALL, "rus");
	SetConsoleCP (1251);
	SetConsoleOutputCP (1251);
	int kk=evklid (k,b,N);
	//cout<<"это kk "<<kk<<endl;
	do
	{
		cout<<"Введите число от 1 до 2"<<endl;
		cout<<"1-шифровать,2-дешифровать"<<endl;
		cout<<"Выход-0"<<endl;
		//int m=evklid(51,45,55);
		int m=evklid(13,2,22);
		cout<<m<<endl;
		int a = pow(9.0,9.0);
		int b = pow(3.0,15.0);
		cout<<int(b)%23<<endl;
		cin>>com;
		while (cin.fail() || com<0 || com>2)
	    {
		    cin.clear ();
	        //cin.ignore (numeric_limits <streamsize>::max(), '\n');
			cin.sync();
            cout <<"Введено некорр. знач. Введите com:";
		    cin >> com;
		}
			switch(com)
			{
			case 1:
				{
					int a=0;
					string c,d;
					cin.get();
	                cout<<"Введите строку для шифрования"<<endl;
	                getline(cin,c);
	                cout<<"Введённая строка: "<<c<<endl;
	                while (a==0)
	                {
		            for (int i=0; i<c.length(); i++)
		            {
			        if (((int)c[i]<-32)||(((int)c[i]>-1)&&((int)c[i]!=43)&&((int)c[i]!=32)))
				    a=1;
		            }
		            break;
	                }
	                if (a!=0)
	                {
		            cout<<"В строке запрещённые символы"<<endl;
		            break;
	                }
					d=shifr(k,c,b,N);
					cout<<"Зашифрованная строка: "<<d<<endl;
					break;
				}
			case 2:
				{
					int a=0;
					string c,e;
					cin.get();
	                cout<<"Введите строку для дешифрации"<<endl;
	                getline(cin,c);
	                cout<<"Введённая строка"<<c<<endl;
	                while (a==0)
	                {
		            for (int i=0; i<c.length(); i++)
		            {
			        if (((int)c[i]<-32)||(((int)c[i]>-1)&&((int)c[i]!=43)&&((int)c[i]!=32)))
				    a=1;
		            }
		            break;
	                }
	                if (a!=0)
	                {
		            cout<<"В строке запрещённые символы"<<endl;
		            break;
	                }
					e=deshifr(kk,c,b,N);
					cout<<"Расшифрованная строка: "<<e<<endl;
					break;
				}
			}
	}while (com!=0);
	system("pause");
	return 0;
}