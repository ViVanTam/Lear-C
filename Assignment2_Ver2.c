#include<stdio.h>
int so_phan_tu,dem,temp,temp1;
int mang[100];
void them_mang(int data)
{
	for(dem=0; dem<so_phan_tu-1; dem++)
	{
		mang[dem]=mang[dem+1];
	}
	mang[so_phan_tu-1]=data;
}
void xuat_mang(char p[50])
{
	printf(p);
	for(dem=0; dem<so_phan_tu; dem++)
	{
		printf("%d ",mang[dem]);
	}
	printf("\n");	
}
void main()
{
	do
	{
		printf("Nhap vao so luong phan tu: ");
		scanf("%d",&so_phan_tu);
	}while(so_phan_tu <= 0);
	//Nhap mang
	for(dem=0; dem <so_phan_tu ; dem++)
	{
		printf("Nhap phan tu thu %d: ",dem);
		scanf("%d",&mang[dem]);
	}
	xuat_mang("Mang vua nhap:\n");
	while(1)
	{
		printf("\nNhap vao so \"1\" de them, \"2\" de xoa phan tu trong mang. Nhap \"0\" de thoat chuong trinh: ");
		scanf("%d",&temp1);
		if(temp1>0)
		{
			switch(temp1)
			{
			case 1:
				printf("\nThem phan tu vao mang: ");
				scanf("%d",&temp);
				printf("Phan tu bi xoa di: %d ",mang[0]);
				them_mang(temp);
				xuat_mang("\nMang sau khi them moi la:\n");
				break;
			case 2:
				them_mang(0);
				printf("Mang sau khi xoa la: ");
				for(dem=0; dem<so_phan_tu-1; dem++)
				{
					printf("%d ",mang[dem]);
				}
				break;
			}
		}
		else break;
	}
//	getch();
}
