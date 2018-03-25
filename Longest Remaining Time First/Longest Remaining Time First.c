#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct Process{
	int Process_Id;
	int Burst_Time;
	int Finish_Time;
	bool Completed;
}Process;
typedef struct Gantt{
	int Process_Id;
	int Start_Time;
	int Finish_Time;
}Gantt;
Process Process_Queue[]={{2132,2,0,false},{2453,4,0,false},{2102,8,0,false}};
Gantt Gantt_Chart[15];
int Time_Value=0;
int Turnaround_Time[3],Waiting_Time[3];

void Display_Sequence();
int Display_Avg();
int main(){
	int i,count=0;
	Process *t,*pq;
	Gantt *g=Gantt_Chart;
	int artime=0;
	while(count<3){
		t=Process_Queue;
		pq=Process_Queue;
		for(i=1;i<3;i++){
			*pq++;
			if(!t->Completed){
				if(pq->Burst_Time>t->Burst_Time)t=pq;
				else if(pq->Burst_Time==t->Burst_Time)
					if(pq->Process_Id<t->Process_Id)t=pq;
				else ;				
			}
		}
		printf("%d\t%d\t",t->Burst_Time,t->Process_Id);
		g->Process_Id=t->Process_Id;
		g->Start_Time=artime;
		g->Finish_Time=artime+1;
		*g++;
		t->Burst_Time-=1;
		Time_Value++;
		if(t->Burst_Time<=0){
			t->Finish_Time=Time_Value;
			t->Completed=true;
			count++;
		}
		printf("%d %d %d\n",g->Process_Id,g->Start_Time=artime,g->Finish_Time);
	}
	printf("Completed");
	Display_Sequence();
	Display_Avg();
	return 0;
}
int Display_Avg(){
	
}
void Display_Sequence(){
	Gantt *g;int i;
	g=Gantt_Chart;
	for(i=0;i<Time_Value;i++){
		printf("| P%d | ",g->Process_Id);
		*g++;
	}
	printf("\n");
	g=Gantt_Chart;
	for(i=0;i<Time_Value;i++){
		printf("%d  %d",g->Start_Time,g->Finish_Time);
		*g++;
	}
}
