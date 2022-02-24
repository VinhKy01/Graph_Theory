#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 20
#define FileInp "E:\\LTDT\\BaiTapLTDT\\Bai1\\input1.txt"
#define FileOut "E:\\LTDT\\BaiTapLTDT\\Bai1\\output1.txt"

int DocFile(char *);
void GhiFile(char *);
void TinhBac();

int n;
int a[MAX][MAX], bac[MAX];

int main()
{
	if (DocFile(FileInp)==1)
	{
		TinhBac();
		GhiFile(FileOut);
		for(int i = 0; i < n; i++)
			printf("%d  ", bac[i]);
	}
	printf("---Chuong trinh ket thuc---");
	return 0;
}

int DocFile(char *file)
{
	FILE *f;
	if ((f = fopen(file,"r"))==NULL)
	{
		printf("Khong the mo file.\n");
		getch();
		return 0;
	}
	fscanf(f,"%d", &n);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			fscanf(f,"%d", &a[i][j]);
	fclose(f);
	return 1;
}

void GhiFile(char *file)
{
	FILE *f;
	if ((f = fopen(file, "w"))==NULL)
	{
		printf("Khong the mo file.\n");
		getch();
		exit(1);
	}
	fprintf(f,"%d\n",n);
	for(int i = 0; i < n; i++)
		fprintf(f,"%d ",bac[i]);
	fclose(f);
}

void TinhBac()
{
	bac[0] = 0;
	int i,j;
	for (int i = 0; i < n; i++)
	{
		bac[i]=0;
	}
	
	for(i = 0; i < n; i++) 
		for(j = 0; j < n; j++)
			if(a[i][j]>0)
				bac[i]++;
}
