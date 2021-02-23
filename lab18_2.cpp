#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *R1,Rect *R2){
	double p1[2]={R1->x,R1->y};
	double p2[2]={(R1->x)+(R1->w),R1->y};
	double p3[2]={R1->x,(R1->y)-(R1->h)};

	double s1[2]={R2->x,R2->y};
	double s2[2]={(R2->x)+(R2->w),R2->y};
	double s3[2]={R2->x,(R2->y)-(R2->h)};

	double L1=(max(p1[0],s1[0])-min(p2[0],s2[0]));
	double aL1=abs(L1);
	double L2=(min(p1[1],s1[1])-max(p3[1],s3[1]));
	double aL2=abs(L2);

	cout<<L1<<" "<<L2<<endl;
	cout<<aL1<<" "<<L2<<endl;
	
		if(L1>=0&&L2>=0){
		return 0;
	}else{
		return aL1*aL2;
	}
	

}

int main(){
	Rect R1={1,1,5,5};
	Rect R2={2,2,5,5};
	Rect R3 = {1,1,5,5};
	Rect R4 = {7,2,3,3};
	Rect R5 = {-1,2,6.9,9.6};
	Rect R6 = {0,0,1.2,2.5};
	cout<<overlap(&R1,&R2)<<endl;
	cout<<overlap(&R3,&R4)<<endl;
	cout<<overlap(&R5,&R6)<<endl;
}
