#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 20
#define FileInp "E:\\LTDT\\BaiTapLTDT\\Bai3\\dscanhIP.txt"
#define FileOut "E:\\LTDT\\BaiTapLTDT\\Bai3\\dscanhOP.txt"

int DocFile(char *);
void GhiFile(char *);
void TinhBac();

int n, m;
int a[MAX][MAX], Bac[MAX];

void Xuatmatran(int a[][MAX])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	
	if (DocFile(FileInp)==1)
	{
		
		TinhBac();
		GhiFile(FileOut);

	}
	printf("---Da thuc hien xong---");

	printf("\n");
	Xuatmatran(a);

return 0;
}

int DocFile(char *file)
{
	FILE *f;
	int i, j, u, v;
	if ((f = fopen(file,"r"))==NULL)
	{
		printf("Khong the mo file.\n");
		getch();
		return 0;
	}
	fscanf(f,"%d", &n);
	fscanf(f,"%d", &m);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			fscanf(f,"%d", &a[i][j]);
		}
		
	}
	
//			luu vao ma tran a
	

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
	for(i=0;i<n;i++)
		fprintf(f,"%d ",Bac[i]);
	
	fclose(f);
	
}

void TinhBac()
{
	int i,j;
	for (int i = 0; i < n; i++)
	{
		Bac[i] = 0;
	}
	
	for(i=0; i<m; i++) 
		for(j=0; j<2; j++)
			for (int k = 0; k < n; k++)
			{
				if (a[i][j] == (k+1))
				{
					Bac[k]++;
				}	
			}				
}

