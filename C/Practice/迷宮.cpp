#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void push(char *rec,char value){
	
	*rec=value;
	
}

void pop(char *rec){
	*rec=0;
}


int main(){
	
	int n,t=0,h=1,k=1;
	scanf("%d",&n);
	int s[n+2][n+2];
	char *rec;
	rec=(char*)malloc(n*n*sizeof(char));
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			scanf("%d",&s[i][j]);
		}
	}
	while(h!=(n)||k!=(n)){
		if(s[h][k+1]==1){
			char value='E';
			push(rec+t,value);
	
			s[h][k]=-1;
			k++;
			t++;
			continue;
		}
		else if(s[h+1][k]==1){
			char value='S';
			push(rec+t,value);
			
			s[h][k]=-1;
			h++;
			t++;
			continue;
		}
		else if(s[h][k-1]==1){
			char value='W';
			push(rec+t,value);
			
			s[h][k]=-1;
			k--;
			t++;
			continue;
		}
		else if(s[h-1][k]==1){
			char value='N';
			push(rec+t,value);
				
			s[h][k]=-1;
			h--;
			t++;
			continue;
		}
		else{
			s[h][k]=0;
			char c=*(rec+(t-1));
			
			
			pop(rec+(t-1));
			t--;
			if(c=='E'){
				k--;
			}
			else if(c=='S'){
				h--;
			}
			else if(c=='W'){
				k++;
			}
			else if(c=='N'){
				h++;
			}
		
			
			
		}
	}

	for(int i=0;i<t;i++){
		printf("%c",*(rec+i));
	}
	
	
	
	
	
	
}
