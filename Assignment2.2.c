#include<stdio.h>
int so_phan_tu,dem,temp;
int mang[100];
void xuat_mang(char p[50])
{
	printf(p);
	for(dem=0; dem<so_phan_tu; dem++)
	{
		printf("%d ",mang[dem]);
	}	
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
		printf("\nThem phan tu vao mang: ");
		scanf("%d",&temp);
		for(dem=0; dem<so_phan_tu-1; dem++)
		{
			mang[dem]=mang[dem+1];
		}
		mang[so_phan_tu-1]=temp;
		xuat_mang("Mang sau khi them moi la:\n");
	}
	getch();
}
