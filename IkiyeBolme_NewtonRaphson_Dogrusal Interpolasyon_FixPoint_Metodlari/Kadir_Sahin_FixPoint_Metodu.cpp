#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>
using namespace std;
float fonkHesap(float x);
float fonk2(float x);
void FixedPointMethod(float a, float b);

int main()
{
	float a=0,b=1;
	FixedPointMethod(a,b);
}
float fonkHesap(float x)
{
	float fonkS=0;
	fonkS= exp(-0.5*x)- x -0.2;
	return fonkS;
}
float fonk2(float x)
{
	float fonkS=0;
	fonkS= exp(-0.5*x)-0.2;
	return fonkS;
}
void FixedPointMethod(float a, float b)
{
		float x,gecici_x,gcc1,gcc2,FPhata_n;
	int t=1,FP_Ulasma;
	x=b;
		gcc1=fonkHesap(a);
		gcc2=fonkHesap(b);	
		if((gcc1*gcc2)<0)
		{
			cout<<"ITERASYON\tKOK\t\tHATA"<<endl;
			do
			{
    		gecici_x = x; 
        	x = fonk2(x);
        	FPhata_n=fabs(x-gecici_x);
        	cout<<t<<".ADIM\t\t"<<x<<"\t"<<FPhata_n<<endl;
        	t++;
        	if(FPhata_n>0.0003)
				{
					FP_Ulasma=t;	
				}
    		}
			while (t<11 && FPhata_n>0.0003);
					cout<<endl<<"0.0003 hata degerinin altina "<<FP_Ulasma<<". adimda ulasmistir.";	
		}
		else
		{
			cout<<endl<<"Istenilen sinirlar icinde koku olup olmadigi belli olmadigi icin islem yapilamamistir.";
		}
}
