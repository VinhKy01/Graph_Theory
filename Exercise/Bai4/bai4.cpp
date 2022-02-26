#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 20
#define FileInp "E:\\LTDT\\BaiTapLTDT\\Bai4\\input4.txt"


int DocFile(char *);
void DFS(int);
void BFS(int);

void tryBFS(int v);
 
int n;
int a[MAX][MAX], chuaxet[MAX], hangdoi[MAX];
int pos = 1;
int main()
{
	int i,j, v;
	
	if (DocFile(FileInp)==1)
	{
		printf("\nDinh bat dau: ");
		scanf("%d",&v);
		
		printf("chuoi duyet DFS la: ");
		for (i=1; i<=n; i++)
   			chuaxet[i]=0;
   		DFS(v);
		
		printf("\nchuoi duyet BFS la: ");
		for (i=1; i<=n; i++){
   			chuaxet[i]=0;
		}

		hangdoi[pos] = v;
		pos++;
		tryBFS(v); 
	}
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
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
			fscanf(f,"%d", &a[i][j]);
	fclose(f);
	return 1;
}


void DFS(int v)
{
	printf("%d ", v);
	chuaxet[v]=1;
	for(int i=1; i<=n; i++)
	if(a[v][i]==1 && chuaxet[i]==0) 
			DFS(i);
	}

void BFS(int v)
{
	
	chuaxet[v]=1;
	for(int i=1; i<=n; i++)
		if(a[v][i]==1 && chuaxet[i]==0) 
		{
			printf("%d ", i);
			hangdoi[pos] = i;
			pos++;
			chuaxet[i] = 1;
		}	
}

void tryBFS(int v){
	printf("%d ", v);
	for(int i = 1; i < n; i++){
		if(hangdoi[i] != 0)
			BFS(hangdoi[i]);
	}
}


