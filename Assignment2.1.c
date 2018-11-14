#include<stdio.h>
#include<math.h>

void main()
{
    float a,b,d,p,s,h,a1,a2,b1,b2,s1,s2;// d: la delta; h la duong cheo; p la chu vi; s la dien tich; a la chieu dai; b la chieu rong//
    printf("Nhap vao gia tri chu vi p: ");
    scanf("%f", &p);
    printf("\nNhap vao gia tri duong cheo h: ");
    scanf("%f", &h);
    d = ((p/2)*(p/2))-(4*((((p/2)*(p/2))-(h*h))/2));
    printf("d: %f",d);
    if(d<0)
    	printf("\nHinh chu nhat khong ton tai!");
    else if (d==0)
    	{
    	a=(p/4);
    	b=(p/2)-a;
    	s=(a*b);
    	printf("\nDien tich hinh chu nhat la: %f",s);
		}
	else 
		{
			a1=((p/2)-sqrt((((p/2)*(p/2))-(4*((((p/2)*(p/2))-(h*h))/2)))))/2;
			printf("\na1: %f ",a1);
			b1=((p/2)-a1);
			printf("\nb1: %f",b1);
			if (a1>=b1)
				{
					s1=a1*b1;
					printf("\nDien tich hinh chu nhat ung voi a1 va b1 la: %f",s1);
				}
			a2=((p/2)+sqrt((((p/2)*(p/2))-(4*((((p/2)*(p/2))-(h*h))/2)))))/2;
			printf("\na2: %f ",a2);
			b2=((p/2)-a2);
			printf("\nb2: %f",b2);
			if(a2>=b2)
				{
				s2=a2*b2;
				printf("\nDien tich hinh chu nhat ung voi a2 va b2 la: %f",s2);
				}
		}
			
}
