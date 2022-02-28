#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10
#define FileInp "E:\\LTDT\\BaiTapLTDT\\Bai7\\bai7_2.txt"
 int DocFile(char *file);
void FordBellman(int G[MAX][MAX], int n, int startnode);
int G[MAX][MAX],i,j,n,u, tempDistance;
int cost[MAX][MAX], distance[MAX],pred[MAX];

 
int main()
{
	
	if (DocFile(FileInp)==1){
	}
	else
		printf("\nKhong mo duoc file");
	
	printf("\nNhap diem bat dau:");
	scanf("%d",&u);
	
	FordBellman(G,n,u);
	
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
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			fscanf(f,"%d", &G[i][j]);
	fclose(f);
	return 1;
}

int checkInfinity(){
	distance[u]=0;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j<=n; j++)
		{
			if(distance[j] + G[i][j] < distance[j]){
				return 0;
			}
		}
	}
	return 1;
}
 
void FordBellman(int G[MAX][MAX],int n,int startnode)
{
	
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
				
	//initialize pred[],distance[] and visited[]
	for(i=1;i<=n;i++)
	{
		distance[i]=INFINITY;
		pred[i]= 0;
	}
	
	distance[startnode]=0;

	
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j<=n; j++)
		{
			tempDistance = distance[i] + cost[i][j];
			if(tempDistance < distance[j]){
				distance[j] = tempDistance;
				pred[j] = i;
			}
		}
	}
	
	if(checkInfinity()){
		printf("Ton tai vong lap am");
	}	
	else{
		for(i=1;i<=n;i++)
			if(i!=startnode && pred[i]!=0)
			{
				printf("\nDo dai duong di tu dinh %d den dinh %d la %d, chu trinh: ",startnode, i, distance[i]);
				printf("%d",i);
				j=i;
				do
				{
					j=pred[j];
					printf("  <-  %d",j);
				}while(j!=startnode);
			}
	}
}
