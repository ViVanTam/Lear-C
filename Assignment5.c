#include<stdio.h>
#include<string.h>
void TestSrec(unsigned char Dong[80]);

int main()
{
	FILE *TepTin = fopen("Ass5.srec","r");
	unsigned 	char Dong[80];
	while(fgets(Dong,80,TepTin))
	{
		TestSrec(Dong);
	}
	fclose(TepTin);
	return 0;
}

void TestSrec(unsigned char Dong[80])
{
	unsigned char Rf[3]="",Bc[3]="",Add[9]="",Data[65]="",Cs[3]="",Temp[3]="";
	int CheckBcSrt=0,CheckBC_Data=0,dem,CheckCs_Data=0,SumCheckCs_Data=0,CheckCs_Str=0,Temp2=0;
	
	strncpy(Rf,Dong,2);
	strncpy(Bc,(Dong+2),2);
	strncpy(Cs,Dong+(strlen(Dong)-3),2);
	if(strcmp(Rf,"S0")==0 | strcmp(Rf,"S1")==0 | strcmp(Rf,"S5")==0 | strcmp(Rf,"S9")==0)
	{
		strncpy(Add,Dong+4,4);
		strncpy(Data,Dong+8,(strlen(Dong)-11));		
	}
	if(strcmp(Rf,"S2")==0 | strcmp(Rf,"S6")==0 | strcmp(Rf,"S8")==0)
	{
		strncpy(Add,Dong+4,6);
		strncpy(Data,Dong+10,(strlen(Dong)-13));
	}
	if(strcmp(Rf,"S3")==0 | strcmp(Rf,"S7")==0)
	{
		strncpy(Add,Dong+4,8);
		strncpy(Data,Dong+12,(strlen(Dong)-15));
	}
	
	CheckBcSrt=(strlen(Add)+strlen(Data)+strlen(Cs))/2;
	sscanf(Bc,"%x",&CheckBC_Data);
	
	for(dem=2;dem<strlen(Dong)-3;dem+=2)
	{
		Temp[0]=Dong[dem];
		Temp[1]=Dong[dem+1];
		sscanf(Temp,"%2x",&CheckCs_Data);
		SumCheckCs_Data+=CheckCs_Data;
	}
	SumCheckCs_Data=0xff-SumCheckCs_Data&0xff;
	sscanf(Cs,"%x",&CheckCs_Str);
	
	if(CheckBcSrt == CheckBC_Data && SumCheckCs_Data==CheckCs_Str)
	{	
		printf("Address: %s\tData: %s\t",Add,Data);
		if(strcmp(Rf,"S0")==0)
		{	
			for(dem=0;dem<strlen(Data);dem+=2)
			{
				Temp[0]=Data[dem];
				Temp[1]=Data[dem+1];
				sscanf(Temp,"%2x",&Temp2);
				printf("%c",Temp2);
			}
		}
		else printf("\"Day khong phai dang van ban\"");
		printf("\n");
	}
}
