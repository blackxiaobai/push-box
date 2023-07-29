#include<stdio.h>
#include<conio.h>
#include<windows.h>
int kill=0;
int choose=0;
int step=0;
int times=0;
int times1=0;
int step1=0;
int step2=0;
int barrier=0;
int map1[9][11]={
 {0,0,0,0,0,0,0,0,0,0,0},
 {0,0,0,1,1,1,0,0,0,0,0},
 {0,0,0,1,4,1,0,0,0,0,0},
 {0,0,0,1,0,1,1,1,1,0,0},
 {0,1,1,1,3,0,3,4,1,0,0},
 {0,1,4,0,3,2,1,1,1,0,0},
 {0,1,1,1,1,3,1,0,0,0,0},
 {0,0,0,0,1,4,1,0,0,0,0},
 {0,0,0,0,1,1,1,0,0,0,0},
};
int map3[9][11]={
 {0,0,0,0,0,0,0,0,0,0,0},
 {0,0,0,1,1,1,0,0,0,0,0},
 {0,0,0,1,4,1,0,0,0,0,0},
 {0,0,0,1,0,1,1,1,1,0,0},
 {0,1,1,1,3,0,3,4,1,0,0},
 {0,1,4,0,3,2,1,1,1,0,0},
 {0,1,1,1,1,3,1,0,0,0,0},
 {0,0,0,0,1,4,1,0,0,0,0},
 {0,0,0,0,1,1,1,0,0,0,0},
};
int map2[9][11]={
 {1,1,1,1,1,0,0,0,0,0,0},
 {1,2,0,0,1,0,0,0,0,0,0},
 {1,0,3,3,1,0,1,1,1,0,0},
 {1,0,3,0,1,0,1,4,1,0,0},
 {1,1,1,0,1,1,1,4,1,0,0},
 {0,1,1,0,0,0,0,4,1,0,0},
 {0,1,0,0,0,1,0,0,1,0,0},
 {0,1,0,0,0,1,1,1,1,0,0},
 {0,1,1,1,1,1,0,0,0,0,0}, 
};
int map4[9][11]={
 {1,1,1,1,1,0,0,0,0,0,0},
 {1,2,0,0,1,0,0,0,0,0,0},
 {1,0,3,3,1,0,1,1,1,0,0},
 {1,0,3,0,1,0,1,4,1,0,0},
 {1,1,1,0,1,1,1,4,1,0,0},
 {0,1,1,0,0,0,0,4,1,0,0},
 {0,1,0,0,0,1,0,0,1,0,0},
 {0,1,0,0,0,1,1,1,1,0,0},
 {0,1,1,1,1,1,0,0,0,0,0}, 
};
int play(int map[9][11]);
int drawmain(int map[9][11]);
int push(int map[9][11]);
int isWin(int map[9][11]);
void save();
void save1();
void read();
void read1();
int main()                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
{
	char l; 
	printf("                   ��������������������������������������\n"); 
	printf("                   ������������ӭ������������Ϸ����������\n");
	printf("                   ����������׼���ý�����Ϸ���𣿡�������\n");
	printf("                   ����������������Y or N����������������\n");
	printf("                   ��������������������������������������\n");
	scanf("%c",&l);
	while(l!='N'&&l!='n'&&l=='Y'||l=='y'){ 
	while(1)
	{
	system("cls");
	barrier=1;
	play(map1);
	times++;
	save();
	if(choose==1&&barrier==1)
	{
		choose=0;
	    kill=0;
	    times++;
		play(map3);
		save();
	}
    if(choose==2)
	{
		choose=0;
		kill=0;
		barrier=2;
		times1++;
	    play(map2);
	    save1();
	    
    }
    barrier=2;
    play(map2);
    times1++;
    save1();
    if(choose!=1)
	{
	break;
    }
    if(choose==1&&barrier==2)
    {
    	kill=0;
    	times1++;
    	play(map4);
    	save1();
	}
	break;
	}
	 system("cls");
	 printf("\nŶ���Ѿ�û�йؿ���\n���ɹ�ͨ�������йؿ�\n����ɫ�����꣬�����ڵ���\n���ڴ�������ٴ����\n�ټ���");	 
	return 0;
	} 
}
int drawmain(int map[9][11])
	{
		int i,j;
		for(i=0;i<9;i++)
		{
			for(j=0;j<11;j++)
			{
			switch(map[i][j])
			    {
			case 0:
			printf("  ");
			break;
			case 1:
			printf("��");
			break;
			case 2:
			printf("��");
			break;
			case 3:
			printf("��");
			break;
			case 4:
			printf("��");
			break;
			case 6:
			printf("��");
			break;
			case 7:
			printf("��");
			break;	
				}	
			}
			printf("\n");
		}
	}
int push(int map[9][11])
{
	int count,caw=0;
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<11;j++){
			if(map[i][j]==2||map[i][j]==6)
			{
				count=i;
				caw=j;
			}
		}
	}
	char tui;
	tui=getch();
	switch (tui)
	{
		case 'W':
		case 'w':
		if(map[count-1][caw]==0||map[count-1][caw]==4)
    {
    map[count][caw]-=2;
    map[count-1][caw]+=2;
    } 
    else if(map[count-1][caw]==3||map[count-1][caw]==7)
    {
    if(map[count-2][caw]==0||map[count-2][caw]==4)
    {
      map[count][caw]-=2;
      map[count-1][caw]-=1;
      map[count-2][caw]+=3;
    }
   }
  break;
  case 'S':
     case 's'://��ֵ 
       if(map[count+1][caw]==0||map[count+1][caw]==4)
   {
    map[count][caw]-=2;
    map[count+1][caw]+=2;
   }
  
    else if(map[count+2][caw]==0||map[count+2][caw]==4)
   {
       if(map[count+1][caw]==3||map[count+1][caw]==7)
    {
         map[count][caw]-=2;
      map[count+1][caw]-=1;
      map[count+2][caw]+=3;
    }
   }
   break;
//�� 
     case 'A':
     case 'a':
        if(map[count][caw-1]==0||map[count][caw-1]==4)
    {
    map[count][caw]-=2;
    map[count][caw-1]+=2;
    }
  
     else if(map[count][caw-2]==0||map[count][caw-2]==4)
   {
       if(map[count][caw-1]==3||map[count][caw-1]==7)
    {
         map[count][caw]-=2;
      map[count][caw-1]-=1;
      map[count][caw-2]+=3;
    }
   }
         break;
 
     case 'D':
     case 'd':
        if(map[count][caw+1]==0||map[count][caw+1]==4)
    {
    map[count][caw]-=2;
    map[count][caw+1]+=2;
    }
  
     else if(map[count][caw+2]==0||map[count][caw+2]==4)
    {
        if(map[count][caw+1]==3||map[count][caw+1]==7)
    {
         map[count][caw]-=2;
      map[count][caw+1]-=1;
      map[count][caw+2]+=3;
    }
   }
      break;
      
       	case 'k':
       	case 'K':
       	 kill=1;
       	break; 
	}

	
}
int isWin(int map[9][11])
{
	int i,j,m=0;
	for(i=0;i<9;i++){
		for(j=0;j<11;j++){
		if(map[i][j]==3)
		m++;
		}
	}
	if(m==0)
	return 1;
	return 0;
}
int play(int map[9][11])
{
	int i=0;
     step1=0;
 	while(!isWin(map))
    {
    	system("cls");
    	printf("                                                              \n");
    	printf("                                            ���Ѿ��ƶ��Ĳ���%d",step1);
    	printf("                                                              \n");
    	printf("                             ________________________________ \n");
    	printf("                            |                                |\n");
    	printf("                            |���á�W����A����S����D�������ƶ�|\n");
    	printf("                            |    ��ӭ��������������          |\n");
    	printf("                            |                                |\n");
		printf("                            |________________________________|\n");
		printf("       ����K������������ѡ�أ�������ע�⣬��ÿ��ֻ�����λ���Ӵ\n");

		//read(); 
		if(barrier==1)
		{
		read();
	    }
	    if(barrier==2)
	    {
	    read1();
		}
        drawmain(map);
        push(map);
        if(kill==1)
		{
        system("cls");
        break;
        }
    step1++;
    }
    i++;
    system("cls");
    if(kill==1&&i<2)
	{ 
    	printf("\n���ڱ�������ѡ����ɱ\n��ÿ��ֻ�����λ���Ӵ\n�������ƶ���������\n����1���¿�ʼ����\n����2������һ��");
		scanf("%d",&choose);
		system("cls"); 
	}
    if(kill!=1&&i<2)
	{
    printf("�ۣ�������������ˣ�\n������һ�ذɣ�\n���������������һ��");
    getch(); 
    } 
    else if(i==2)
	{
    system("cls");  
    }
} 
void save()
    {
    	step=step1;
    	FILE *fp;
    	FILE *p;
    	p = fopen("./save1.txt", "w");
    	fprintf(p," %d\n",times);
    	fp = fopen("./save.txt", "a+");
    	fprintf(fp," %d\n",step);
    	fclose(p);
    	fclose(fp);
	}
void read()
    {
    	int a[100]={0};
    	FILE *fp;
    	FILE *p;
		p =fopen("./save1.txt","r+");
		fscanf(p,"%d",&times);
    	fp =fopen("./save.txt","r+");
    	for(int i=0;i<times;i++){
    	fscanf(fp,"%d",&step);
    	a[i]=step;
    	//printf("                                                         %d\n",step);
    }
    //printf("%d",a[0]);
       int side=0;
       int rank=0;
       for(int i=0;i<times;i++)
       {
	   for(int j=0;j<times-i;j++)
	   {
       	if(a[j+1]<=a[j])
       	{   
		   side=a[j+1];
       	   a[j+1]=a[j];
       	   a[j]=side;
		}
	   }
      }
      for(int i=0;i<times+1;i++)
      {
      	rank++;
      	if(a[i]<10)
      	{
		    rank--;
      		continue;
		  }
      	printf("                                                           ��%d�����ò���:%d\n",rank,a[i]);
	  }
        fclose(p);
    	fclose(fp);
	}
void save1()
{
	step2=step1;
	FILE *m;
	FILE *fm;
	m=fopen("./save2.txt","w");
	fprintf(m,"%d",times1);
	fm=fopen("./save3.txt","a+");
	fprintf(fm,"%d\n",step2);
	fclose(m);
	fclose(fm);
}
void read1()
{           
	    FILE *jk;
    	FILE *j;
    	int a[100];
		j =fopen("./save2.txt","r+");
		fscanf(j,"%d",&times1);
    	jk =fopen("./save3.txt","r+");
    	for(int i=0;i<times1;i++)
		{
    	fscanf(jk,"%d",&step2);
    	a[i]=step2;
    	//printf("                                                         %d\n",step2);
        }
        //printf("%d",a[0]);
       int side=0;
       int rank=0;
       for(int i=0;i<times1;i++)
       {
	   for(int j=0;j<times1-i;j++)
	   {
       	if(a[j+1]<=a[j])
       	{   
		   side=a[j+1];
       	   a[j+1]=a[j];
       	   a[j]=side;   
		}
	   }
      }
      for(int i=0;i<times1+1;i++)
      {
      	rank++;
        if(a[i]<50)
        {
        	rank--;
        	continue;
		}
      	printf("                                                            ��%d�����õĲ�����%d\n",rank,a[i]);
	  }
        fclose(j);
    	fclose(jk);
}
