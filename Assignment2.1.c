#include<stdio.h>
float s_chu_nhat(float duong_cheo, float chu_vi)
{
	float tong_2_canh;
	tong_2_canh=chu_vi/2; //Tinh lay nua chu vi(Tong do dai hai canh)
	return  -((duong_cheo*duong_cheo) - (tong_2_canh*tong_2_canh))/2;
}

void main()
{
	float duong_cheo,chu_vi;
	NhapThongSo:
		printf("Nhap vao chu vi: ");
		scanf("%f",&chu_vi);
		printf("Nhap vao duong cheo: ");
		scanf("%f",&duong_cheo);
	// Kiem tra xem, neu duong cheo nhap vao lon hon hoac bang tong hai canh(nua chu vi)
	// thi thong so nay khong tao duoc hinh chu nhat--Khong hop le
	if(duong_cheo >= chu_vi/2)
	{	system("cls");
		printf("Thong so khong the tao hinh chu nhat! Moi nhap lai.\n");
		goto NhapThongSo;
	}
	else
	{
		printf("Dien tich hinh chu nhat la: %.2f",s_chu_nhat(duong_cheo,chu_vi));
	}
	getch();
}
