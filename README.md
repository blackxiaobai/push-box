# push-box

推箱子小游戏
下面是实验报告，以供借鉴

一、	问题描述
实现一个可以运行的推箱子程序

（一）基本要求  
 设计多个关卡的地图等数据,玩家通过键盘控制小人推动箱子到指定位置,全部到位后果下一关.能够实现玩家记录,排名。
 
（二）提高要求  
 能够实现重复演示,记录当前状态。
 
（三）测试数据要求 
应该大量的进行数据测试,多次记录游戏记录。
数据测试时应输入多次不同的数据，测试数据的排序功能。

二、需求分析

（一）	软件的基本功能
实现了多个地图，玩家可以通过WSDA键控制小人移动，在判定通过后会自动跳转下一关。

（二）	软件的提高功能
实现了在每名玩家结束游戏后对其游戏数据的存储，并对其游戏数据进行排名，在玩家走到死路时可以选择按K键进行自杀，自杀后可选择重新开始本关或者跳过本关进行下一关。

（三）	输入/输出形式
输入：通过getch()函数进行连续的输入字符。
输出：通过清屏函数以及二维数组的改变在视觉上来实现人物移动的输出形式。

三、概要设计

（一）	抽象数据类型
int play(int map[9][11]);

int drawmain(int map[9][11]);

int push(int map[9][11]);

int isWin(int map[9][11]);

void save();

void save1();

void read();

void read1();


（二）	主程序流程

![image](https://github.com/blackxiaobai/push-box/assets/135434098/82549e32-98ba-45e9-b0da-82a3fd0727fe)

 
（三）	模块调用关系

![image](https://github.com/blackxiaobai/push-box/assets/135434098/f57b55e6-65c3-4355-aba4-0c806d260523)

 
四、详细设计

（一）实现概要设计的数据类型
记录数据int型
实现二维数组的变换来实现人物的移动输入为char型

（二）核心模块的算法实现与分析
运用switch case语句实现了地图的打印，通过将二维数组中的数字赋予形状来实现。

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
   
			printf("■");
   
			break;
   
			case 2:
   
			printf("♀");
   
			break;
   
			case 3:
   
			printf("☆");
   
			break;
   
			case 4:
   
			printf("◎");
   
			break;
   
			case 6:
   
			printf("♂");
   
			break;
   
			case 7:
   
			printf("★");
   
			break;	
   
				}
    
			}
   
			printf("\n");
   
		}
  
	}
 
通过二维数组的变化在视觉上呈现出人物移动的效果，需要分多种情况进行分析

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
  
     case 's'://键值 
     
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
   
//左 

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

通过判断场上是否还有箱子来判定该关是否通过

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

通过文件的读写来实现每次玩家的游戏记录

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
    
      	printf("                                                           第%d名所用步数:%d\n",rank,a[i]);
       
	  }
   
        fclose(p);
	
    	fclose(fp);
     
	}
 
五、编码与调试分析

（一）开发环境配置

Dev-C++

（二）编码与调试过程中遇到的问题及解决办法：

文件读写过程中由于之前没有学过，编写这部分时非常生疏，解决方法是与同学一起讨论解决。
文件读写完成后需要对文件中的数据提取到数组中进行排序，会出现乱码的问题，我在询问老师后进行调试，最终找到了问题所在并成功解决。

（三）待解决问题

关卡数目还较少的问题和悔棋方法

六、使用说明

介绍你开发的这个系统的使用方法。
使用WSAD键进行上下左右移动，使用K键实现玩家在某一关中自杀并重新选关。

七、测试结果

对题目中的每个要求都要给出测试结果，并附运行效果截图。

①	多个关卡地图
 
 
②	通过关卡后进入下一关以及完成全部关卡
 
 
③	实现玩家数据记录和排名
 
 
④	实现关卡重复演示
 
八、自学知识

你本次课设学到的，教材以外的知识点。


学会了用switch case语句打印地图
关于文件操作的相关知识，文件指针FILE*fp，文件的打开操作fp=fopen(“文件名”,“操作方式”），数组向文件写入数据fprintf函数形式（fp,“%s”，a）;文件向数组读入数据fscanf(fp,“%s”，&a),其中&非常重要。

学会了清屏函数system("cls");

九、心得体会

通过本次课设,学习到了一些C语言的语法技巧以及之前从未接触过的文件的读写方法，深刻领悟了switch case语句的要义，虽然在实施文件的读写过程中遇到了一些困难，但经过反思理解，进一步具体实验，通过与同学进行探讨，最终克服了文件的读写这一难题，我也确切的感受到与同学合作的乐趣，和自身对于编写小游戏的兴趣，体会到了完成一项小游戏所带给我的成就感和喜悦，虽然过程曲折，但通过努力最终取得了成功，在今后的python学习中，会更加细心努力，认真学习编程知识，争取更进一步。
