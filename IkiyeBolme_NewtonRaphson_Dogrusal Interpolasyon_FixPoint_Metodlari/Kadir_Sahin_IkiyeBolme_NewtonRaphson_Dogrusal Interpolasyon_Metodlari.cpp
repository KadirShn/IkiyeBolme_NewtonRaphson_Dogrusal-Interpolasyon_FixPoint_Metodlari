#include<iostream>
#include<math.h>
#include<limits>
using namespace std;
float fonkHesap(float x);
float IkiyeBolmeHata(float a, float b, int n);
int IkiyeBolmeMetodu(float a, float b);
float NewtonRaphsonHata(float x1, float x2);
float fonkTurevHesap(float x);
int NewtonRaphsonMetodu(float k,float x);
int DogrusalInterpolasyonMetodu(float a, float b);
float DogrusalInterpolasyonHata(float x1, float x2);
float DIKokHesap(float a, float b);
main()
{
	float a=0,b=2;
	int DI_Ulasma=0,NR_Ulasma=0,IB_Ulasma=0;
	cout<<"--- F(x) = e^(-0.5*x)-x-0.2 [0,2] araliginda ---"<<endl;
	cout<<"Fonksiyonun alt sinir degeri(a): "<<a<<endl;
	cout<<"Fonksiyonun ust sinir degeri(b): "<<b<<endl;
	cout<<endl<<"\t\tIkiye Bolme Metodu"<<endl<<endl;
	IB_Ulasma=IkiyeBolmeMetodu(a,b);
	cout<<endl<<endl<<"\t\tNewton Raphson Metodu"<<endl<<endl;
	NR_Ulasma=NewtonRaphsonMetodu(a,b);
	cout<<endl<<endl<<"\tDogrusal Interpolasyon Metodu"<<endl<<endl;
	DI_Ulasma=DogrusalInterpolasyonMetodu(a,b);
	int kucuk = 0;
	if(IB_Ulasma<NR_Ulasma)
	{
		kucuk=IB_Ulasma;
	}
	else if(IB_Ulasma>NR_Ulasma)
	{
		kucuk=NR_Ulasma;
	}
	else if(IB_Ulasma==NR_Ulasma)
	{
		kucuk = IB_Ulasma;
	}
	if(DI_Ulasma<kucuk)
	{
		kucuk=DI_Ulasma;
	}
	if(IB_Ulasma==kucuk)
	{
		cout<<endl<<"Ikiye bolme Metodu ile 0.02 den daha kucuk bir hata degerine "<<IB_Ulasma<<". adimda ulasilmistir."<<endl;
	}
	if(NR_Ulasma==kucuk)
	{
		cout<<endl<<"Newton Raphson Metodu ile 0.02 den daha kucuk bir hata degerine "<<NR_Ulasma<<". adimda ulasilmistir."<<endl;
	}
	if(DI_Ulasma==kucuk)
	{
		cout<<endl<<"Dogrusal Interpolasyon Metodu ile 0.02 den daha kucuk bir hata degerine "<<DI_Ulasma<<". adimda ulasilmistir."<<endl;
	}
	cout<<endl<<" @Kadir_Sahin"<<endl;
	
}
float fonkHesap(float x)
{
	float fonkS=0;
	fonkS= exp(-0.5*x)- x -0.2;
	return fonkS;
}
float IkiyeBolmeHata(float a, float b, int n)
{
	float IBhata= (b-a)/pow(2,n);
	return IBhata;
}
int IkiyeBolmeMetodu(float a, float b)
{
	float c,gcc,gcc1,gcc2,IBhata_n;
	int t=1,IB_Ulasma=0;
			gcc1=fonkHesap(a);
			gcc2=fonkHesap(b);
			
			if((gcc1*gcc2)<0)
			{
				cout<<"Iterasyon\tKok Degeri\t\tHata(e) Degeri:"<<endl;
				cout<<"--------------------------------------------------------"<<endl;	
				do
				{
					c=(a+b)/2;
					gcc=fonkHesap(c);
					IBhata_n=IkiyeBolmeHata(a,b,t);
					if(t<7)
					{
						cout<<t<<".ADIM"<<"\t\t"<<c<<"\t\t\t"<<IBhata_n<<endl;
					}
					else
					{
						cout<<t<<".ADIM"<<"\t\t"<<c<<"\t\t"<<IBhata_n<<endl;
					}
					
					if((gcc*gcc2)<0)
					{
						a=c;	
					}
					else
					{
						b=c;	
					}
					t++;
					if(IBhata_n>0.02)
					{
						IB_Ulasma=t;	
					}
				}
				while(t<11);
				
				return IB_Ulasma;
			}
			else
			{
				cout<<endl<<"Istenilen sinirlar icinde koku olup olmadigi belli olmadigi icin islem yapilamamistir.";
			}	
}
float NewtonRaphsonHata(float x1, float x2)
{
	float NRhata = fabs(x2-x1);
	return NRhata;
}
float fonkTurevHesap(float x)
{
	float fonkTH=0;
	fonkTH= -exp(-0.5*x)/2-1;
	return fonkTH;
}
int NewtonRaphsonMetodu(float k,float x)
{
	float gecici_x=0,gcc1,gcc2,NRhata_n;
	int t=1,NR_Ulasma=0;
	
	gcc1=fonkHesap(k);
	gcc2=fonkHesap(x);
			
	if((gcc1*gcc2)<0)
	{
		cout<<"Iterasyon\tKok Degeri\t\tHata(e) Degeri:"<<endl;
		cout<<"--------------------------------------------------------"<<endl;	
    	while (t<11)
    	{
    		gecici_x = x; 
        	x = x - fonkHesap(x)/fonkTurevHesap(x);
        	NRhata_n = NewtonRaphsonHata(x,gecici_x);
        	
        	cout<<t<<".ADIM"<<"\t\t"<<x<<"\t\t"<<NRhata_n<<endl;
        	t++;
        	if(NRhata_n>0.02)
			{
			NR_Ulasma=t;	
			}   
    	}
		return NR_Ulasma;
   }
   else
	{	
		cout<<endl<<"Istenilen sinirlar icinde koku olup olmadigi belli olmadigi icin islem yapilamamistir.";
	}
}

int DogrusalInterpolasyonMetodu(float a, float b)
{
	float x,gcc,gcc1,gcc2,DIhata_n=0,onceki_x = 0;
	int t=1,DI_Ulasma=0;
			gcc1=fonkHesap(a);
			gcc2=fonkHesap(b);
			
			if((gcc1*gcc2)<0)
			{
				cout<<"Iterasyon\tKok Degeri\t\tHata(e) Degeri:"<<endl;
				cout<<"--------------------------------------------------------"<<endl;
				do
				{
					x= DIKokHesap(a,b);
					gcc=fonkHesap(x);
					DIhata_n = DogrusalInterpolasyonHata(onceki_x,x);
					onceki_x=x;
					cout<<t<<".ADIM"<<"\t\t"<<x<<"\t\t"<<DIhata_n<<endl;
					if((gcc*gcc2)<0)
					{
						a=x;	
					}
					else
					{
						b=x;	
					}
					t++;
					if(DIhata_n>0.02)
					{
						DI_Ulasma=t;	
					}
				}
				while(t<11);
				
			return DI_Ulasma;	
			}
			else
			{
				cout<<endl<<"Istenilen sinirlar icinde koku olup olmadigi belli olmadigi icin islem yapilamamistir.";
			}
}
float DogrusalInterpolasyonHata(float x1, float x2)
{
	float DIhata = fabs(x2-x1);
	return DIhata;
}
float DIKokHesap(float a, float b)
{
	float DIKok = ((a*fonkHesap(b))-(b*fonkHesap(a)))/(fonkHesap(b)-fonkHesap(a)); 
	return DIKok;
}
