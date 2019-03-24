#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<graphics.h>
#include<X11/Xlib.h>

int usleep(useconds_t usec);
//function prototype
void tra(int);
int qdel(int);
 void qins(int,char);
 void signal1(char);
void signal2(char);
void lights();
void glights();
//void delay(int);
//global
int rearc,frontc;
char s[10];
char n1,e1,s1,w1,n2,n3,e2,e3,s2,s3,w2,w3;
int n21,e21,s21,w21,n22,n23,e22,e23,s22,s23,w22,w23;
//circular queue

void main()
{
	XInitThreads();
	int o,n,i,M;
	int gd =DETECT, gm;
	  
	   				
	 //char v;
	 rearc=-1;  //initializing
	 frontc = -1;
	 n=4;  //max count for signals
	// initalize circular queue 
	//'N'; 
	 qins(n,'N');
	 // 'E';
	 qins(n,'E');
	// 'S';
	 qins(n,'S');
	 //'W';
	 qins(n,'W');
	//clrscr();
	system("clear");
	//directions
	printf("                                   TRAFFIC SIGNALS                 \n");
	printf("\n                                        N                        \n");
	printf("\n                                W               E                \n");
	printf("\n                                        S                        \n");
	//clrscr();

	usleep(3000000);
	system("clear");
	printf("\nMENU:\n 1:SIMPLE REPRESENTATION\n2: GRAPHICAL REPRESENTATION\n");
	scanf("%d",&M);
	system("clear");
		//loop	
	for(i=0;i<20;i++)
	{
			o=qdel(n);//obtaining signal direction
			if(M==1)
			{		
			signal1(o);
			qins(n,o);//inserting same again
			}
			if(M==2)
			{
	        initgraph(&gd, &gm, " ");
		
			signal2(o);
			qins(n,o);//inserting same again
			
			}		
			
	}

	getch();
	closegraph();
}
			void signal1(char o)
			{
				switch(o)
				{
					// for directions
					case 'N': 
						//for  green signals
						
						n3='X'; s3='-';w3='-';e3='-';//GREEN
						e2='-';n2='-';s2='-';w2='-';//YELLOW
						e1='X';s1='X';w1='X';n1='-';//RED
						lights();//call to light() function
						// creating delay 
						usleep(8000000);
						//clrscr();
						system("clear");
						 //for yellow signals
						
						e2='-';n2='X';s2='-';w2='-';
						s3='-';w3='-';e3='-';n3='-';
						e1='X';s1='X';w1='X';n1='-';
						lights();//call to light() function
						// creating delay 
						usleep(4000000);
						//clrscr();
						system("clear");						
						break;
					case 'E' :
						
						
						e2='-';n2='-';s2='-';w2='-';
						s3='-';w3='-';n3='-';e3='X';
						n1='X';s1='X';w1='X';e1='-';
						lights();
						usleep(8000000);
						//clrscr();
				     		system("clear");
						
						
						e2='X';n2='-';s2='-';w2='-';
						s3='-';w3='-';n3='-';e3='-';
						n1='X';s1='X';w1='X';e1='-';
						lights();
						usleep(4000000);
						//clrscr();
				     		system("clear");
						break;
					case 'S' :
						
						
						e2='-';n2='-';s2='-';w2='-';
						e3='-';w3='-';n3='-';s3='X';
						n1='X';e1='X';w1='X';s1='-';
						lights();
						usleep(8000000);
						//clrscr();
						system("clear");
						
						
						e2='-';n2='-';s2='X';w2='-';
						e3='-';w3='-';n3='-';s3='-';
						n1='X';e1='X';w1='X';s1='-';
						lights();
						usleep(4000000);
						//clrscr();
						system("clear");
						break;
					case 'W' :
						
						
						e2='-';n2='-';s2='-';w2='-';
						e3='-';s3='-';n3='-';w3='X';
						n1='X';e1='X';s1='X';w1='-';
						lights();
						usleep(8000000);
						//clrscr();
						system("clear");
						
						
						e2='-';n2='-';s2='-';w2='X';
						e3='-';s3='-';n3='-';w3='-';
						n1='X';e1='X';s1='X';w1='-';
						lights();
						usleep(4000000);
						//clrscr();
						system("clear");
						break;
				}
			}
            void signal2(char o)
			{ 
				switch(o)
				{
					// for directions
					case 'N': 
						//for  green signals
						
						n23=2;e23=0;s23=0;w23=0;//GREEN
						n22=0;e22=0;s22=0;w22=0;//YELLOW
						n21=0;e21=4;s21=4;w21=4;//RED
						glights();//call to light() function
						// creating delay 
						usleep(4000000);
						//clrscr();
						cleardevice();
						 //for yellow signals
						
						n23=0;e23=0;s23=0;w23=0;//GREEN
						n22=14;e22=0;s22=0;w22=0;//YELLOW
						n21=0;e21=4;s21=4;w21=4;//red
						glights();//call to light() function
						// creating delay 
						usleep(2000000);
						//clrscr();
						cleardevice();					
						break;
					case 'E' :
						//for  green signals
						
						n23=0;e23=2;s23=0;w23=0;//GREEN
						n22=0;e22=0;s22=0;w22=0;//YELLOW
						n21=4;e21=0;s21=4;w21=4;//RED
						glights();//call to light() function
						// creating delay 
						usleep(4000000);
						//clrscr();
						cleardevice();
						 //for yellow signals
						
						n23=0;e23=0;s23=0;w23=0;//GREEN
						n22=0;e22=14;s22=0;w22=0;//YELLOW
						n21=4;e21=0;s21=4;w21=4;//red
						glights();//call to light() function
						// creating delay 
						usleep(2000000);
						//clrscr();
						cleardevice();	
						
						break;
					case 'S' :
						
						
						//for  green signals
						
						n23=0;e23=0;s23=2;w23=0;//GREEN
						n22=0;e22=0;s22=0;w22=0;//YELLOW
						n21=4;e21=4;s21=0;w21=4;//RED
						glights();//call to light() function
						// creating delay 
						usleep(4000000);
						//clrscr();
						cleardevice();
						 //for yellow signals
						
						n23=0;e23=0;s23=0;w23=0;//GREEN
						n22=0;e22=0;s22=14;w22=0;//YELLOW
						n21=4;e21=4;s21=0;w21=4;//red
						glights();//call to light() function
						// creating delay 
						usleep(2000000);
						//clrscr();
						cleardevice();	
						break;
					case 'W' :
						
						//for  green signals
						
						n23=0;e23=0;s23=0;w23=2;//GREEN
						n22=0;e22=0;s22=0;w22=0;//YELLOW
						n21=4;e21=4;s21=4;w21=0;//RED
						glights();//call to light() function
						// creating delay 
						usleep(4000000);
						//clrscr();
						cleardevice();
						 //for yellow signals
						
						n23=0;e23=0;s23=0;w23=0;//GREEN
						n22=0;e22=0;s22=0;w22=14;//YELLOW
						n21=4;e21=4;s21=4;w21=0;//red
						glights();//call to light() function
						// creating delay 
						usleep(2000000);
						//clrscr();
						cleardevice();	
						break;
				}
				
			}
		void lights()
		{
			/*
			printf("\n       N              E            S            W        \n");
			printf("\n     -------        -------     -------      -------     \n");
			printf("\n    |  ---  |      |  ---  |   |  ---  |    |  ---  |    \n");
			printf("\n    | | %d| |      | |%d | |   | |%d | |    | |%d|  |    \n",n1,e1,s1,w1);
			printf("\n    |  ---  |      |  ---  |   |  ---  |    |  ---  |    \n");
			printf("\n    |  ---  |      |  ---  |   |  ---  |    |  ---  |    \n");
			printf("\n    | |%d | |      | |%d | |   | |%d | |    | | %d| |    \n",n2,e2,s2,w2);
			printf("\n    |  ---  |      |  ---  |   |  ---  |    |  ---  |    \n");
			printf("\n    |  ---  |      |  ---  |   |  ---  |    |  ---  |    \n");
			printf("\n    | | %d| |      | |%d | |   | |%d | |    | |%d | |    \n",n3,e3,s3,w3);
			printf("\n    |  ---  |      |  ---  |   |  ---  |    |  ---  |    \n");
			printf("\n     -------        -------     -------      -------     \n");
			printf("\n       | |            | |         | |          | |       \n");
			*/
			printf("\n\t\t\tSIGNALS")	;			
			printf("\n        \t N \t E \t S \t W\n");
			printf("\n RED    \t %c \t %c \t %c \t %c \n",n1,e1,s1,w1);
			printf("\n YELLOW \t %c \t %c \t %c \t %c \n",n2,e2,s2,w2);
			printf("\n GREEN  \t %c \t %c \t %c \t %c \n",n3,e3,s3,w3);
		}
		void glights()
		{
			 outtextxy(250,50,"   TRAFFIC SIGNALS  ");
			rectangle(200,40,450,70);
				 //settextstyle(0,0,4);
				setcolor(15);
				   outtextxy(98,125,"N");
				rectangle(80,110,120,150);
				rectangle(50,150,150,400);
				 setcolor(15);
				 circle(100,200,25);  
				setcolor(n21);
				 floodfill(100,200,WHITE);
				 setcolor(15);
				 circle(100,275,25);
				setcolor(n22);
				 floodfill(100,275,WHITE);
				 setcolor(15);
				 circle(100,350,25);
				setcolor(n23);
				 floodfill(100,350,WHITE);
				 setcolor(15);
 				bar(90,400,110,470);
				   //
				 outtextxy(248,125,"E");
				rectangle(230,110,270,150);
				 setcolor(15);
				 rectangle(200,150,300,400);
				  setcolor(15);
				  circle(250,200,25); 
				  setcolor(e21);
				  floodfill(250,200,WHITE);
				 setcolor(15);
				 circle(250,275,25);
				setcolor(e22);
				 floodfill(250,275,WHITE);
				 setcolor(15);
				 circle(250,350,25);
				setcolor(e23);
				 floodfill(250,350,WHITE);
				setcolor(15);
 				bar(240,400,260,470);
				//
				//
				  outtextxy(398,125,"S");
				rectangle(380,110,420,150);
				 setcolor(15);
				 rectangle(350,150,450,400);
				 setcolor(15);  
				   circle(400,200,25);
				setcolor(s21);
				   floodfill(400,200,WHITE);
				   setcolor(15);
				   circle(400,275,25);
				setcolor(s22);
				   floodfill(400,275,WHITE);
				  setcolor(15);
				   circle(400,350,25);
				 setcolor(s23);
				   floodfill(400,350,WHITE);
				setcolor(15);
				 bar(390,400,410,470);
					//
				  outtextxy(548,125,"W");
				rectangle(530,110,570,150);
				 setcolor(15);
				 rectangle(500,150,600,400);
				  setcolor(15);
				   circle(550,200,25);
				 setcolor(w21);
				   floodfill(550,200,WHITE);
				  setcolor(15);
				   circle(550,275,25);
				 setcolor(w22);
				   floodfill(550,275,WHITE);
				  setcolor(15);
				   circle(550,350,25);
				 setcolor(w23);
				   floodfill(550,350,WHITE);
				setcolor(15);
				 bar(540,400,560,470);
				
		}
			//enqueue
		 void qins( int n , char v)
		{
			  if((frontc==0&&rearc ==n-1)||(rearc==(frontc-1)%(n-1)))//for full queue
				{
			  	printf("overflow");
			  	}
			  else if( frontc==-1 && rearc==-1)// for first element
			  {
				  frontc=0;
				  rearc=0;
				  s[rearc]=v;
			  }
			else if( frontc != 0 && rearc == n-1)// making queue circular
			  {
				  rearc=0;
				  s[rearc]=v;
			  }
			  else
			  {
				  rearc = rearc+1;
				  s[rearc]=v;
			  }
		  }
			//dequeue
		 int qdel(int n)
		  {
			  int item;
			  if(frontc==-1)//empty queue
			  {
				  printf("empty");
			  }
			  else
			  {
				  item=s[frontc];
				 s[frontc]=0;
				if(frontc == rearc)//last element
				 	{ frontc=-1;
					  rearc =-1;
					}
				else if(frontc== n-1)// for making it circular queue
				{
					frontc=0;
				}
				else
				{
					frontc++;
				}  
			}
			  return item;
		  }
		
		
		

//traversal		   
			void tra(int n)
			{
			    int i,j;
			    if(frontc==-1&&rearc==-1)
			    {
				printf("Queue is underflow\n");
			    }
			    if(frontc>rearc)
			    {
				
				for(j=frontc;j<=n-1;j++)
				    printf("\t%d",s[j]);
				for(i=0;i<=rearc;i++)
				    printf("\t%d",s[i]);
				
			    }
			    else
			    {
				for(i=frontc;i<=rearc;i++)
				{
				 printf("\t%d",s[i]);
				}
			       
			    }
			    printf("\n");
			}
 
/*void delay(int n)
		{
		//creating delay 
		int i,j,t;
		int a[1000000];
		///n=50000;
			for(i=0;i<n;i++)
			{t=n;
			a[i]=t;
			t--;
			}
			for(i=0;i<n;i++)
				{
					for(j=n-1;j>=i+1;j--)
					{
						if(a[j]<a[j-1])	
						{					
						t=a[j];	
						a[j]=a[j-1];
						a[j-1]=t;
						}
					}
				}
			
		/*int i;
		for(i=0;i<100000000;i++);
		{
		}
}*/
