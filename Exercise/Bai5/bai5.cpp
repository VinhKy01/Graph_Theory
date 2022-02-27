#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 20
#define FileInp "E:\\LTDT\\BaiTapLTDT\\Bai5\\input5.txt"




int DocFile(char *);
void DFS(int);
void BFS(int);
void tryBFS(int);
void KtraLT();

int n, solt;
int a[MAX][MAX], chuaxet[MAX], truoc[MAX], hangdoi[MAX];
int pos = 1;


int main()
{
	int i, v;
	
	if (DocFile(FileInp)==1)
	{
		KtraLT();
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
	   {
			truoc[i]=v;
			DFS(i);
	   }
   
}


void BFS(int v)
{
	
	chuaxet[v]=1;
	for(int i=1; i<=n; i++)
		if(a[v][i]==1 && chuaxet[i]==0) 
		{
			//printf("%d ", i);
			hangdoi[pos] = i;
			pos++;
			chuaxet[i] = 1;
		}	
}

void tryBFS(int v){
	//printf("%d ", v);
	for(int i = 1; i < n; i++){
		if(hangdoi[i] != 0)
			BFS(hangdoi[i]);
	}
}

void KtraLT()
{
	int i, j;
	int solt=0;
	
	
	//kiem tra solt bang BFS
	for (i=1; i<=n; i++) 
		chuaxet[i]=0;
	
	for (i=1; i<=n; i++)
		if (chuaxet[i]==0)
		{
			solt++;
			hangdoi[pos] = i;
			pos++;
			tryBFS(i);
		}
	if (solt==1) printf("\n--- Do thi lien thong!---");
	else
	{
		printf("\nDo thi co %d thanh phan lien thong", solt);

	}
	
	//in cac tp bang DFS
	solt=0;
	for (i=1; i<=n; i++) 
		chuaxet[i]=0;
		
	for (i=1; i<=n; i++)
		if (chuaxet[i]==0)
		{
			printf("\nTP%d:", solt+1);
			solt++;
			DFS(i);
		}
}

