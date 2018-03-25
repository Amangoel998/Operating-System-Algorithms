#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct Process{
	int Process_Id;
	int Burst_Time;
}Process;
typedef struct Gantt{
	int Process_Id;
	int Start_Time;
	int Finish_Time;
}Gantt;
Process Process_Queue[]={{2132,2},{2453,4},{2102,8}};
Gantt Gantt_Chart[14];
bool completed[3]={false,false,false};
int Sequence[8];
int count=0;
float Turnaround_Time,Waiting_Time;

int main(){
	int i,gi=0;
	Process *t,*pq;
	Gantt *g;
	int artime=0;
	while(count<3){
		*g=Gantt_Chart[gi];
		*t=Process_Queue[0];
		*pq=Process_Queue[1];
		for(i=1;i<3;i++){
			if(!completed[i]){
				if(pq->Burst_Time>t->Burst_Time)t=pq;
				else if(pq->Burst_Time==t->Burst_Time)
					if(pq->Process_Id<t->Process_Id)t=pq;
				else ;				
			}
			*pq++;
		}
		g->Process_Id=t->Process_Id;
		g->Start_Time=artime;
		g->Start_Time=artime+1;
		t->Burst_Time-=1;
		if(t->Burst_Time==0)completed[t->Process_Id]=true;
	}
	*g=Gantt_Chart[0];
	for(i=0;i<15;i++){
		printf("| P%d | ",g->Process_Id);
	}
	*g=Gantt_Chart[0];
	for(i=0;i<15;i++){
		printf("&d  &d",g->Start_Time,g->Finish_Time);
	}
}
