#include <stdio.h>
#include <stdlib.h>
#include "linked_op.h"


int addNode(struct node **head,int data)
{
    struct node *current=NULL;
    int state=-1;

    if(*head==NULL)
    {
        (*head)=(struct node*)malloc(sizeof(struct node));
        (*head)->data=data;
        (*head)->next=NULL;
        state=0;
        printf(" head %d \n",(*head)->data);
    }
    else 
    {
        current=(*head);
        while (current->next!=NULL) {
            current=current->next;
        }
        current->next=(struct node*)malloc(sizeof(struct node));
        current=current->next;
        current->data=data;
        current->next=NULL;
        state=0;
    }

    return state;
}

void display(struct node* head)
{
    struct node *current=NULL;
    int n=0;
    current=head;
    while (current!=NULL) {
        printf("Node numero : %d \n\tNode data : %d\n\n",n,current->data);
        current=current->next;
        n++;
    }

}

int addHeadNode(struct node **head,int data)
{
    int status=-1;
    struct node *buffer=NULL;
    buffer=(struct node*)malloc(sizeof(struct node));
    buffer->data=data;
    buffer->next=(*head);
    *head=buffer;
    status=0;

    return status;
}

int addNodePos(struct node **head,int data,int pos)
{
    int status=-1,found=0,n=1 ;
    struct node *newnode=NULL,*buffer=NULL;
    
    buffer=(*head);
    while (buffer!=NULL && !found) {
        if(n==pos){
            found=1;
        }
        buffer=buffer->next;
        n++;
    }
    
    if(found){
        n=buffer->data;
        buffer->data=data;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=n;
        newnode->next=buffer->next;
        buffer->next=newnode;
        status=0;
    }


    return status;
}

int deleteNodeTete(struct node **head)
{
    int status=-1;
    struct node *todelete=NULL;
    
    if((*head)->next==NULL){printf("Erreur :Single Node \n");return status;}
    todelete=(*head);
    (*head)=(*head)->next;

    status=todelete->data;
    todelete->next=NULL;
    free(todelete);

    return status;
}

int deleteNodePos(struct node **head,int pos)
{
    int status=-1,num=1;
    struct node *todelete=NULL,*current=NULL;

    if((*head)->next==NULL){printf("Error :Single Node \n");return status;}
    if(pos==0){deleteNodeTete(head);return 0;}

    current=(*head);
    while(current!=NULL){
        if(pos==num)
            break;
        current=current->next;
        num++;
    }

    todelete=current->next;
    if(todelete==NULL)
    {   
        printf("Erreur pas de node a la positon\n");
        return status;
    }
    else if(todelete->next==NULL) 
    {
        current->next=NULL;
    }
    else
    {
        current->next=todelete->next;
        todelete->next=NULL;
    }

    free(todelete);
    printf("Node (position = %d , valeur = %d) deleted succefully\n",pos,status);

    return status;
}

int deleteNodeValeur(struct node **head,int data)
{
    int status=-1,pos=0;
    struct node *current=NULL;

    current=(*head);
    while (current!=NULL) {
        if(current->data==data)
        {
            status=pos;
            break;
        }
        pos++;
        current=current->next;
    }
    if (status>0)
    {
        deleteNodePos(head,status);
    }

    return status;
}

int findNode(struct node *head,int data)
{
    int status=-1,pos=0;
    struct node *current=NULL;
    current=head;

    while (current!=NULL) {
        if(current->data==data)
        {
            status=pos;
            break;
        }
        pos++;
        current=current->next;
    }

    if (status>=0) {
        printf("Node valeur %d trouver a la position %d \n\tNode pos : %d \n\tValeur : %d \n\n"
        ,data,status,status,current->data);
    }

    return status;

}

int sizeNode(struct node *head)
{
    int n=0;
    struct node *current=NULL;

    if (head !=NULL) {
        
        current=head;
        while (current) {
            current=current->next;
            n++;
        }        
    }

    return n;
}

int updateNodePos(struct node **head,int pos,int data)
{
    int status=-1,found=0,n=1;
    struct node *buffer=NULL;

    buffer=(*head);

    while (buffer!=NULL && !found) {
        if(n==pos){
            found=1;
        }
        buffer=buffer->next;
        n++;
    }

    if(found){
        buffer->data=data;
        status=0;
    }

    return  status;
}

int updateNodeValeur(struct node **head,int old_data,int new_data)
{
    int status=-1,n=0;
    struct node *buffer=NULL;

    buffer=(*head);

    while (buffer!=NULL) {
        if(buffer->data==old_data){
            buffer->data=new_data;
            status=n;
            break;
        }
        buffer=buffer->next;
        n++;
    }

    return status;
}

int sortNode(struct node **head)
{
    int status=-1,tmp;
    struct node *buff1=NULL,*buff2=NULL;

    for(buff1=(*head);buff1->next!=NULL;buff1=buff1->next)
    {
        for(buff2=buff1->next;buff2!=NULL;buff2=buff2->next)
        {
            if(buff1->data>buff2->data)
            {
                tmp=buff1->data;
                buff1->data=buff2->data;
                buff2->data=tmp;
            }
        }
    }

    return status;
}

int reverseNode(struct node **head)
{
    int status=-1;
    struct node *current=NULL,*next=NULL,*prev=NULL;

    current=(*head);
    while (current!=NULL) {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }

    *head=prev;
    status=0;


    return status;
}

int deleteAllNode(struct node **head)
{
    int state=-1;
    struct node *current=NULL,*next=NULL;

    current=*head;

    do{
        
        next=current->next;
        free(current);
        current=next;
    }while(current);

    *head=NULL;
    state=0;
    
    return state;
}
