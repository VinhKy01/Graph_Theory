#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 20
#define FileInp "E:\\LTDT\\BaiTapLTDT\\Bai2\\input2.txt"
#define FileOut "E:\\LTDT\\BaiTapLTDT\\Bai2\\output2.txt"

int DocFile(char *);
void GhiFile(char *);
void TinhBac();

int n;
int a[MAX][MAX], bacvao[MAX], bacra[MAX];


int main()
{
	if (DocFile(FileInp)==1)
	{
		TinhBac();
		GhiFile(FileOut);
	}
	printf("---Da thuc hien xong---");

	return 0;
}

int DocFile(char *file)
{
	FILE *f;
	int i, j;
	if ((f = fopen(file,"r"))==NULL)
	{
		printf("Khong the mo file.\n");
		getch();
		return 0;
	}
	fscanf(f,"%d", &n);
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			fscanf(f,"%d", &a[i][j]);
	fclose(f);
	return 1;
}

void GhiFile(char *file)
{
	FILE *f;
	int i;
	if ((f = fopen(file, "w"))==NULL)
	{
		printf("Khong the mo file.\n");
		getch();
		exit(1);
	}
	fprintf(f,"%d\n",n);

	for(int i = 0; i < n; i++)
	{
		fprintf(f,"%d ",bacvao[i]);
		fprintf(f,"%d ",bacra[i]);
		fprintf(f, "\n");
	}
	fclose(f);
}

void TinhBac()
{
	for (int i = 0; i < n; i++)
	{
		bacvao[i] = 0;
		bacra[i] = 0;
	}
	
	int i,j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(a[i][j]>0)
			{
				bacra[i]++;
				bacvao[j]++;
			}
		}		
	}					
}

