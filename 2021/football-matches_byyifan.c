/*
说明与要求：10个足球队进行9轮循环赛，胜一场积3分，平一场积1分，输一场积0分，
如果两个队积分相同，进行净胜球的比较，如果净胜球再相同进行总进球的比较。
编写一程序输入每轮比赛的比分，并可以存储。最后统计出每轮比赛的积分榜。
*/
#include<stdio.h>
#include <stdlib.h>
#include <windows.h> 

//比赛结构体
typedef struct {
	int score = 0;            //总分 
	int Goals_For = 0;        //进球数 
	int Goals_Against = 0;    //失球数 
	int Goal_Difference = 0;  //净胜球数 
}Match; 

int main(){
	system("color 75\n");
	int i,j,b,t,NUM;
	int e = 1,a = -2;
	int count = 0;
	mark2:
	printf("足球比赛排名系统 \n------------------- \n请输入球队数\n");
	scanf("%d",&NUM);
	Match s[NUM];
	printf("请选择模式(输入后点击回车确认)：\n   1    手动输入信息 \n   2    自动输入信息（模拟）\n");
	mark1:
	scanf("%d",&t);
	for(int i = 0; i < NUM; i++){
	    for(int j = 0; j < NUM; j++){
	        if(i >= j)
	            continue;
	        if(t == 1){
	        	if(e == 1){
				printf("注意！输入格式为：【整数】【空格】【整数】\n 点击回车进行下一组输入 \n");
				}
	        	printf("\n%d VS %d 请输入比赛双方进球数  \n",i+1,j+1);	
				scanf("%d",&a);
				scanf("%d",&b);
				e = 0;
			}
	        else if(t == 2){
	        	a= rand() % 5;
				b = rand() % 5;
	        }
	        else{
	        	printf("输入错误！请输入 1 或 2 ！");
				goto mark1; 
	        }
				s[i].Goals_For += a;
	            s[i].Goals_Against += b;
	            s[j].Goals_For += b;
	            s[j].Goals_Against += b;
				         
	            if (s[i].Goals_For == s[j].Goals_For){
	                s[i].score += 1;
	                s[j].score += 1;
	            }
	            if (s[i].Goals_For > s[j].Goals_For){
	                s[i].score += 3;
	                s[j].score += 0;
	            }
	            if (s[i].Goals_For < s[j].Goals_For){
	                s[i].score += 0;
	                s[j].score += 3;
	            }
	            count = count + 1;
	            if(j == 10){
	               printf(" \n第%d场: \n  第%d队 vs 第%d队 ", count, i + 1, j + 1);
	            }
	            else {
	                printf(" \n第%d场: \n 第%d队 vs 第%d队 ",count, i + 1, j + 1);
	            	printf("\n %d  :  %d \n",a, b);
	        	}
	      }
	    }
	    for(int i = 0; i < NUM; i++){
	        s[i].Goal_Difference= s[i].Goals_For - s[i].Goals_Against;
	        printf("\n%d队, 总分: %d,净胜球数: %d, 总进球数 %d", i+1,s[i].score,s[i].Goal_Difference,s[i].Goals_For);
	    }    
	    printf("\n--------------------------------------\n");
		for(j = 0;j < NUM;j++){
			if(j != NUM){
				for(i = 0;i < NUM;i++){
					if(s[i].score > a){
						a = s[i].score;
						b = i;
					} 
					if(s[b].score == s[i].score){
						if(s[i].Goal_Difference > s[b].Goal_Difference){
							b = i;	
						}
						else if(s[i].Goal_Difference == s[b].Goal_Difference){
							if(s[i].Goals_For > s[b].Goals_For)
							b = i;
						}
					}
				}
			printf("\n第名%d: %d队, 总分: %d, 净胜球数: %d, 总进球数 %d",j+1, b+1, s[b].score, s[b].Goal_Difference, s[b].Goals_For);
			s[b].score = -1;
			a = -2;
			}
			else{
				for(i = 0;i < NUM;i++){
					if(s[i].score != -1){
						b = i;
					}		
				printf("\n第名%d: %d队, 总分: %d, 净胜球数: %d, 总进球数 %d",j+1, b+1, s[b].score, s[b].Goal_Difference, s[b].Goals_For);
				}
			}
		}
		printf("\n\n排名结束\n"); 
		printf("    重新开始请输入 1\n    结束程序输入其他键\n");
		scanf("%d",&a);
		if(a == 1){
			goto mark2;
		}
return 0;
}
