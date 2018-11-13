#include<stdio.h>
int n_element,Count_element,Count_average,Sum_aray,Aray_element[20];
float average;
void main(){
	//Nhap so luong phan tu
	do{
		printf("Nhap vao so luong so can nhap(0-20):");
		scanf("%d",&n_element);
	}
	while(n_element<0 || n_element>20);
	//Nhap gia tri cho tung phan tu
	for(Count_element=0; Count_element< n_element; Count_element++)
	{
		printf("Nhap so thu %d: ", Count_element+1);
		scanf("%d",&Aray_element[Count_element]);
		Sum_aray+=Aray_element[Count_element];
	}
	//Tinh trung binh cong
	average=(float)Sum_aray / n_element;
	//Dem so co gia tri nho hon so trung binh cong
	for(Count_element=0; Count_element< n_element; Count_element++)
	{
		if(Aray_element[Count_element] < average) Count_average++;
	}
	//In ket qua:
	printf("So trung binh cong la: %f \a", average);
	printf("\nSo luong so nho hon so trung binh cong la: %d", Count_average);
	printf("\nCac so do la:");
	for(Count_element=0; Count_element< n_element; Count_element++)
	{
		if(Aray_element[Count_element] < average) printf(" %d,",Aray_element[Count_element]);
	}
	getch();
}
