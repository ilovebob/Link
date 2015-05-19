#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
//未优化功能：返回主界面； 
struct node *creat(struct node *head);
struct node *insert (struct node *head, char *pstr, int n);
struct node *delet (struct node *head, char *pstr);
void search(struct node *head, char *pstr);
void print (struct node *head);

struct node 
{
	int num;
	char str[20];
	struct node *next;
};

int main( )
{
    system("CLS");
	struct node *head;
	char str2[20],ch;
	int n;
	head=NULL; 
	head=creat(head); 
out1: ;
	printf("\nplease input the number of function: 1.insert 2.delete 3.search 4.print 5.quit \n");
	while(1){
        scanf("%c",&ch);
        if(ch=='1') {
            system("CLS");
            printf("\n input inserted num,name:\n");
            scanf("%d",&n); /*输入学号*/
            scanf("%s",str2); /*输入姓名*/
            head=insert (head, str2, n);
			goto out1; 
        }
        if(ch=='2'){
            system("CLS");
            printf("\n input deleted name:\n");
            scanf("%s",str2);  /*输入被删姓名*/
            head=delet(head,str2); 
            goto out1;
        }
        if(ch=='3'){
            system("CLS");
            printf("\n input name:\n");
            scanf("%s",str2);  /*输入寻找姓名*/
            search(head,str2); 
            goto out1;
        }
        if(ch=='4'){
            system("CLS");
            print(head);
            goto out1;
        }
        if(ch=='5') break;
	}
	return 0;
}

/* * * 创建链表* * * * * * * * * * * */
struct node *creat(struct node *head)
{
	char temp[30];
	struct node *p1,*p2;
	p1=p2=(struct node*) malloc(sizeof(struct node));
	printf ("input num, name: \n");
	printf("exit:double times Enter!\n");
	gets(temp);
	gets(p1->str);
	p1->num=atoi (temp);
	p1->next=NULL;
	while (strlen(p1->str)>0)
	{
		if (head==NULL) head=p1;
		else p2->next=p1;
		p2=p1;
		p1=(struct node *)malloc(sizeof(struct node));
		printf ("input num, name: \n");
		printf("exit:double times Enter!\n"); 
		gets(temp);
		gets(p1->str);
		p1->num=atoi (temp);
		p1->next=NULL;
	}
	system("CLS");
	return head;
}

/* * * * * * * * * * 插入节点* * * * * * * * * */
struct node *insert (struct node *head, char *pstr, int n)
{
	struct node *p1,*p2,*p3;
	p1=(struct node*)malloc(sizeof(struct node));
	strcpy (p1->str, pstr);
	p1->num=n;
	p2=head;
	if (head==NULL) {head=p1;p1->next=NULL;}
	else{
		while (n>p2->num&&p2->next!=NULL){
            p3=p2;
            p2=p2->next;
            }
            if (n<=p2->num){
                if (head==p2){
                    head=p1;p1->next=p2;
                }else{
                    p3->next=p1;
                    p1->next=p2;
                }
            }else{
                p2->next=p1;
                p1->next=NULL;
            }
    }
	return head;
}

/* * * * * 删除节点* * * * * * * * * * * * */
struct node *delet (struct node *head, char *pstr)
{
	struct node *temp,*p;
	temp=head;
	if (head==NULL) printf("\nList is null!\n");
	else{
        temp=head;
        while (strcmp(temp->str,pstr)!=0&&temp->next!=NULL){
            p=temp;
            temp=temp->next;
            }
        if(strcmp(temp->str,pstr)==0){
            if(temp==head){
                head=head->next;
                free(temp);
            }else{
                p->next =temp->next;
                printf("delete string :%s\n",temp->str);
                free(temp);
            }
        }else printf("\nno find string!\n");
    }
	return(head);
}

/* * * * *寻找节点* * * * * * * * * * * * */
void search(struct node *head, char *pstr)
{
    struct node *temp;
    temp=head;
    printf("\n the message of the student:\n");
    while (1){
        if(strcmp(temp->str,pstr)==0){
            printf("\n%d----%s\n",temp->num,temp->str);
            break;}
        temp=temp->next;
    }
}

/* * * * * * * * * * 链表各节点的输出* * * * * * * * * */ 
void print (struct node *head)
{
    struct node *temp;
    temp=head;
    printf("\n output strings:\n");
    while (temp!=NULL){
    printf("\n%d----%s\n",temp->num,temp->str);
    temp=temp->next;
    }
} 

