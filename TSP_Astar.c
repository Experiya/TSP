/*
	Name: TSP
	Copyright: 
	Author: 
	Date: 17-02-20 03:20
	Description: TSP with A*
*/
#include<stdio.h>
#include<malloc.h>
struct node{
int huristic;
int from;
int to;
int total;
struct node *next;
};
int t=1;;
void TSP(int n , int a[][n+1] , struct node *chead , struct node *ohead, int total,int s){
    printf("\n closed \n");
    printans(chead);
    printf("\n open \n");
    printans(ohead);
    printf("2\n");
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    int min1=1000,min2=1000,min3=1000,min4=1000;
    temp=chead;
    while(temp->next!=NULL){
            printf("3\n");
        if(temp->to==n-1){
            if(temp->total<min1)
                min1=temp->total;
        }
        temp=temp->next;
    }
    if(temp->to==n-1){
            if(temp->total<min1)
                min1=temp->total;
        }
    temp=ohead;
    while(temp->next!=NULL){
        printf("4\n");
            if(temp->total<min2)
                min2=temp->total;
            temp=temp->next;
    }
    if(temp->total<min2)
            min2=temp->total;
    if(min1<min2){
        printf("5\n");
        printans(chead);
        return ;
    }else{
            printf("6\n");
            temp=ohead;
            int i=0;
            for(i=0;i<n;i++){
                printf("7\n");
                if(temp==NULL){
                    printf("8\n");
                    temp->huristic=a[i][n];
                    temp->from=s;
                    temp->to=i;
                    temp->total=total-a[s][n]+a[i][n]+a[s][i];
                    temp->next=NULL;
                }else{
                    printf("9\n");
                    while(temp->next!=NULL){
                        printf("10\n");
                        temp=temp->next;
                    }
                    struct node *new1=NULL;
                    new1=(struct node *)malloc(sizeof(struct node));
                    new1->huristic=a[i][n];
                    new1->from=s;
                    new1->to=i;
                    new1->total=total-a[s][n]+a[i][n]+a[s][i];
                    new1->next=NULL;
                    temp->next=new1;

                }
            }
            //t++;
            printf("11\n");
            struct node *temp2=NULL;
            temp2=(struct node*)malloc(sizeof(struct node));
            temp=ohead;
            int p=0,t=0;
            while(temp->next!=NULL){
                    printf("12\n");
                if(min3>temp->total){
                    printf("13\n");
                    min3=temp->total;
                    temp2=temp;
                    t=p;
                }
                temp=temp->next;
                p++;
            }
            if(min3>temp->total){
                printf("14\n");
                min3=temp->total;
                temp2=temp;
                t=p;
            }
            //t--;
            temp=ohead;
            if(t<0)
                t=0;
            while(t--)
            {
                printf("15\n");
                temp=temp->next;
            }
            temp->next=temp2->next;
            temp=chead;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=temp2;
            temp2->next=NULL;
            printf("16\n");
        temp=ohead;
        while(temp->next!=NULL){
                printf("17\n");
            if(min4>temp->total){
                printf("18\n");
                min4=temp->total;
                temp2=temp;
            }
            temp=temp->next;
        }
        if(min4>temp->total){
            printf("19\n");
            min4=temp->total;
            temp2=temp;
        }
        s=temp2->to;
        total=temp2->total;
        printf("20\n");
        TSP(n,a,chead,ohead,total,s);
    }
}

printans(struct node *chead){
    while(chead->next!=NULL){
        printf("%d   ",chead->to);
        chead=chead->next;
    }
    printf("%d   ",chead->to);
}

int main(){
int n,i,j;
scanf("%d",&n);
int a[n][n+1];
printf("write value : ");

for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        scanf("%d",&a[i][j]);
    }
}
printf("write huiristic : ");
for(i=0;i<n;i++){
    scanf("%d",&a[i][n+1]);
}
struct node *chead=NULL,*ohead=NULL;
chead=(struct node *)malloc(sizeof(struct node));
ohead=(struct node *)malloc(sizeof(struct node));
ohead->next=NULL;
chead->next=NULL;
printf("1\n");
TSP(n,a,chead,ohead,0,0);
}
