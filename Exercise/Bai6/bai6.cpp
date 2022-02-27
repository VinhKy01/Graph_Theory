#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 20
#define FileInp "E:\\LTDT\\BaiTapLTDT\\Bai6\\Euler.txt"


int DocFile(char *);
int KtraEuler();
void TimEuler();
void TinhBac();


int n, soBacLe;
int a[MAX][MAX], chuaxet[MAX], truoc[MAX], bac[MAX];


int main()
{
	int i, v;
	
	if (DocFile(FileInp)==1)
		if(KtraEuler())
			TimEuler();
		else
			printf("\nKHONG co chu trinh Euer");
	
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

int KtraEuler()
{
	TinhBac();
	soBacLe = 0;
     for (int i=1;i<=n;i++)
	{
		if(bac[i] %2 != 0){
			soBacLe++;
		}
    }
    return soBacLe;
}

void TinhBac()
{
	bac[0] = 0;
	int i,j;
	for(i = 0; i < n; i++) 
		for(j = 0; j < n; j++)
			if(a[i][j]>0)
				bac[i]++;
}

void TimEuler()
{         
	//mang ket qua
	int CE[MAX], nCE = 0, dinh, ke; 
	//stack dinh         
    int STACK[MAX], top = 1;
    
    STACK[top] = 1;
    while(top>0)
    {
	    dinh = STACK[top];
	    ke = 1;
	    while(ke<=n && a[dinh][ke]==0){
	    	ke++;
		}
		
		//kh con canh nao ke
		if(ke>n){
			nCE++;
			CE[nCE] = dinh;
			top--;
		}
		//ke la canh ke cua dinh
		else{
			top++;
			STACK[top] = ke;
			a[dinh][ke] = 0;
			a[ke][dinh] = 0;
		}
    }
    printf("\nnCE=%d\n\n",nCE);
	printf("\nChu trinh Euler tim duoc la: ");
    for(int i = 1; i <= nCE; i++){
    	printf("%d ", CE[i]);
	}
}



