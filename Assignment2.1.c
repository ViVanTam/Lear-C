#include<stdio.h>
float tim_hinh_chu_nhat(float c, float p)
{
	float s;
	p=p/2;
	s=-((c*c)-(p*p))/2;
	printf("Dien tich hinh chu nhat la: %.2f",s);
}

void main()
{
	float duong_cheo,chu_vi;
	NhapThongSo:
		printf("Nhap vao chu vi: ");
		scanf("%f",&chu_vi);
		printf("Nhap vao duong cheo: ");
		scanf("%f",&duong_cheo);
	if(duong_cheo>chu_vi/2)
	{
		printf("Thong so khong the tao hinh chu nhat! Moi nhap lai.\n");
		goto NhapThongSo;
	}
	else
	{
		tim_hinh_chu_nhat(duong_cheo,chu_vi);
	}
	getch();
}
