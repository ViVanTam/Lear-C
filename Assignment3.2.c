#include<stdio.h>
void nhap_ma_tran(int mang[][100],int hang,int cot, char* ten_ma_tran);
void in_ma_tran(int mang[][100],int hang,int cot, char* ten_ma_tran);
void cong_ma_tran(int mangA[][100],int mangB[][100], int hang, int cot);
void nhan_ma_tran(int mangA[][100],int mangB[][100], int hang, int cot);
void main()
{
	int A[100][100],B[100][100],h,c;
	printf("TINH TONG VA TICH HAI MA TRAN KICH THUOC\n");
	printf("Nhap kich thuc ma tran: ");
	scanf("%d %d",&h,&c);
	
	nhap_ma_tran(A,h,c,"A");
	nhap_ma_tran(B,h,c,"B");
	system("cls");
	in_ma_tran(A,h,c,": A");
	in_ma_tran(B,h,c,": B");
	
	cong_ma_tran(A,B,h,c);
	nhan_ma_tran(A,B,h,c);
	getch();
}

void nhap_ma_tran(int mang[][100],int hang,int cot, char* ten_ma_tran)
{
	int r,c;
	printf("Nhap ma tran %s:\n",ten_ma_tran);
	for(r = 0; r < hang; r++)
	{
		for(c = 0; c < cot; c++)
		{
			printf("%s[%d][%d]= ",ten_ma_tran,r,c);
			scanf("%d",&mang[r][c]);
		}
	}
}

void in_ma_tran(int mang[][100],int hang,int cot, char* ten_ma_tran)
{
	int r,c;
	printf("Ma tran %s\n",ten_ma_tran);
	for(r = 0; r < hang; r++)
	{
		for(c = 0; c < cot; c++)
		{
			printf("%d\t",mang[r][c]);
		}
		printf("\n");
	}
}
void cong_ma_tran(int mangA[][100],int mangB[][100], int hang, int cot)
{
	int temp[100][100],r,c;
	for(r = 0; r < hang; r++)
	{
		for(c = 0; c < cot; c++)
		{
			temp[r][c] = mangA[r][c] + mangB[r][c];
		}
	}
	in_ma_tran(temp,r,c,"sau khi cong la: ");
}
void nhan_ma_tran(int mangA[][100],int mangB[][100], int hang, int cot)
{
	if(hang==cot)
	{
		int temp[100][100],r,c,k;
		for(r = 0; r < hang; r++)
		{
			for(c = 0; c < cot; c++)
			{
				temp[r][c]=0;  
				for(k=0;k<cot;k++)  
				{  
				temp[r][c]+=mangA[r][k]*mangB[k][c];
				}  
			}
		}	
		in_ma_tran(temp,r,c,"sau khi nhan la: ");
	}
	else printf("Loi, khong the nhan ma tran vi so hang ma tran A khac so cot ma tran B!");
}
