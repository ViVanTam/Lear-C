#include<stdio.h>

float p_chu_nhat(float a,float b);
float s_chu_nhat(float a,float b);
void main()
{
	float a,b;
	printf("TINH CHU VI, DIEN TICH HINH CHU NHAT");
	printf("\nNhap chieu dai va chieu rong: ");
	scanf("%f %f",&a,&b);
	printf("Chu vi hinh chu nhat la: %.2f",p_chu_nhat(a,b));
	printf("\nDien tich hinh chu nhat la: %.2f",s_chu_nhat(a,b));
}
float p_chu_nhat(float a,float b)
{
	return (a+b)*2;
}
float s_chu_nhat(float a,float b)
{
	return a*b;
}
