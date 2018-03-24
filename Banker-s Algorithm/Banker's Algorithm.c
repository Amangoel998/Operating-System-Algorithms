#include<stdio.h>
int n=3,m=3,i=0;

int Resource_Available[][3]={{8,4,2},{3,0,0},{1,2,2}};
int Resource_Allocated[][3]={{0,0,1},{3,2,0},{2,1,1}};
int Process_Maximum_Need[][3]={{8,4,3},{6,2,0},{3,3,3}};
int Process_Current_Need[3][3];

int *RAv,*RAl,*PMx,*PNd;

void Display_Table();
int Request_Algo(int,int);
int Check_Algo(int,int);

int main(){
	int i,j;
	Calculate_Need();
	Display_Table();
	int a[]={0,0,2};
	int *R=a;
	Check_Algo(0,R);
	int b[]={2,0,0};
	R=b;
	//Check_Algo(1,R);
}

int Request_Algo(int pid,int *R){
	//1
	int i;
	RAv=Resource_Available[pid];
	RAl=Resource_Allocated[pid];
	PMx=Process_Maximum_Need[pid];
	PNd=Process_Current_Need[pid];
	for(i=0;i<m;i++){
		if(*(R+i)<*(PNd+i))return 0;
		if(*(R+i)<*(RAv+i))return 0;
	}
	//2
	printf("Process %d is possible to continue\n",pid);
	for(i=0;i<m;i++){
		*(RAl+i)+=*(R+i);
		*(RAv+i)-=*(R+i);
		*(PNd+pid+i)+=*(R+i);
	}
	return 1;
}
int Check_Algo(int pid,int *R){
	if(Request_Algo(pid,R)==1){
		printf("Request Satisfied\nChecking Safety\n");
	}
	else {
		printf("Request Not Satisfied\n");
		return 0;
	}
}
void Calculate_Need(){
	int pid,i,j;
	for(pid=0;pid<n;pid++){
		PNd=Process_Current_Need[pid];
		RAl=Resource_Allocated[pid];
		PMx=Process_Maximum_Need[pid];
		for(i=0;i<m;i++){
			*(PNd+i)=*(PMx+i)-*(RAl+i);
		}
	}
}
void Display_Table(){
	int i,j;
	printf("Process\tMaximum\t\tAllocated\tNeed\n");
  	for(j=0;j<n;j++){
		RAl=Resource_Allocated[j];
		PMx=Process_Maximum_Need[j];
		PNd=Process_Current_Need[j];
		printf("P%d\t",j);
		for(i=0;i<m;i++){
			printf("%d ",*(PMx+i));
		}
		printf("\t\t");
		for(i=0;i<m;i++){
			printf("%d ",*(RAl+i));
		}
		printf("\t\t");
		for(i=0;i<m;i++){
			printf("%d ",*(PNd+i));
		}
		printf("\n");
	}
	printf("\n");
}
