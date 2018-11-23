#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
struct NV
{
	char MS[20];
    char Ten[20];
    char Acc[20];
    float DTB;
};

struct Node
{
    NV ThongTin;
    Node *Next;
};

Node* TaoNode(NV x)
{
    Node *p;
    p=new Node;
    if(p==NULL)  exit(1);
    p->ThongTin=x;
    p->Next=NULL;
    return p;
}

struct DanhSach
{
    Node *Dau;
    Node *Cuoi;
};

void TaoDanhSach (DanhSach &DS)
{
    DS.Dau=DS.Cuoi=NULL;
}

void ThemVaoNode (DanhSach &DS, Node *p)
{
    if(DS.Dau==NULL)  DS.Dau=DS.Cuoi=p;
    else
    {
        DS.Cuoi->Next=p;
        DS.Cuoi=p;
    }
}

void NhapThongTin(NV &x)
{
    printf("\nNhap MSNV: ");  fflush(stdin); gets(x.MS);
    printf("\nNhap ten: ");  fflush(stdin); gets(x.Ten);  
	printf("\nNhap Account: ");  fflush(stdin); gets(x.Acc); 
    printf("\nNhap DTB: "); scanf("%f", &x.DTB);
}

void NhapNhanVien (DanhSach &DS)
{
    NV x;
    system("cls");
    printf("\n\t\tTHEM NHAN VIEN");
    NhapThongTin(x);
    Node *p=TaoNode(x);
    ThemVaoNode(DS,p);
}

void XuatThongTin(NV &x)
{
    printf("\nMSNV: %s    Ten: %s    Account: %s    Diem TB: %.1f",x.MS,x.Ten,x.Acc,x.DTB);
}

void XuatNhanVien(DanhSach DS)
{
    Node *p;
    p=DS.Dau;
    while(p!=NULL)
    {
        XuatThongTin(p->ThongTin);
        p=p->Next;
    }
    printf("\n");
}

void XoaNhanVien(DanhSach &L)
{
    Node *p, *q;
    char MS[20];
    p=L.Dau;
    q=NULL;
    printf("\n\t\tXoa NHAN VIEN");
    printf("\nNhap MSSV can xoa: ");
    fflush(stdin);
    gets(MS);
    while (p!=NULL)
    {
        if(strcmp(MS, p->ThongTin.MS)==0)    break;
        else printf("\nKhong tim thay thong tin sinh vien can xoa.");
        q=p;
        p=p->Next;
    }
    if(q!=NULL)
    {
        if(p!=NULL)
        {
            q->Next=p->Next;
            delete (p);
            if(p==L.Cuoi)  L.Cuoi=q;
            delete(p);
        }
    }
    else
    {
        L.Dau=p->Next;
        delete(p);
        if(L.Dau==NULL)  L.Cuoi=NULL;
    }
    system("cls");
    printf("\nDa xoa nhan vien!");
}
void SapXepNhanVien (DanhSach &L)
{
    Node *p,*q,*pTemp;
    p=L.Dau;
    NV temp;
    char Chon;
    printf("\n\t\tSAP XEP NHAN VIEN");
	printf("\n\t1. Theo ten A-Z.");
	printf("\n\t2. Theo ten Z-A.");
	printf("\n\t3. Theo diem 0-10.");
	printf("\n\t4. Theo diem 10-0.");
	Chon=getch();
    while (p!=L.Cuoi)
    {
        pTemp=p;
        q=p->Next;
        while (q!=NULL)
        {
        	switch(Chon)
        	{
            	case '1': if(strcmp(q->ThongTin.Ten, pTemp->ThongTin.Ten)<0)  pTemp=q; break;
            	case '2': if(strcmp(q->ThongTin.Ten, pTemp->ThongTin.Ten)>0)  pTemp=q; break;
            	case '3': if(q->ThongTin.DTB < pTemp->ThongTin.DTB)  pTemp=q; break;
            	case '4': if(q->ThongTin.DTB > pTemp->ThongTin.DTB)  pTemp=q; break;
            }
            q=q->Next;
        }
        temp=p->ThongTin;
        p->ThongTin=pTemp->ThongTin;
        pTemp->ThongTin=temp;
        p=p->Next;
    }
    system("cls");
    printf("\nDa sap xep thanh cong!");
}
void Menu()
{
	DanhSach DS;
	TaoDanhSach(DS);
    char Chon;
    do
	{
    	printf("\n\t\tMENU");
        printf("\n\t1. Nhap danh sach nhan vien.");
        printf("\n\t2. In danh sach nhan vien.");
        printf("\n\t3. Xoa nhan vien.");
        printf("\n\t4. Sap xep nhan vien.");
        printf("\n\tNhap 0 de thoat");
        Chon=getch();	
         switch(Chon)
        {
            case '1':  
            			NhapNhanVien (DS);
            			system("cls");
						printf("\n\t\tTHONG TIN NHAN VIEN SAU KHI THEM");
						XuatNhanVien(DS);
						break;
			case '2':  
						system("cls");
						printf("\n\t\tTHONG TIN NHAN VIEN");
            			XuatNhanVien(DS);
						break;
			case '3':  
            			XoaNhanVien(DS);
            			system("cls");
						printf("\n\t\tTHONG TIN NHAN VIEN SAU KHI XOA");
						XuatNhanVien(DS);
						break;
			case '4':  
            			SapXepNhanVien(DS);
						system("cls");
						printf("\n\t\tTHONG TIN NHAN VIEN SAU KHI SAP XEP");
						XuatNhanVien(DS);
						break;
			case '0': exit(1);
        }
        
	}while(Chon != '0');
}
int main()
{
	while(1)
	{
		Menu();
	}
	return 0;
}
