#ifndef LINKED_OP
#define LINKED_OP

    struct node {
        int data;
        struct node *next;
    };

    int addNode(struct node**,int);
    void display(struct node*);
    int addHeadNode(struct node**,int);
    int addNodePos(struct node**,int,int);
    int deleteNodeTete(struct node**);
    int deleteNodePos(struct node**,int);
    int deleteNodeValeur(struct node**,int);
    int findNode(struct node*,int);
    int sizeNode(struct node*);
    int updateNodePos(struct node **,int,int);
    int updateNodeValeur(struct node **,int,int);
    int sortNode(struct node **);
    int reverseNode(struct node**);
    int deleteAllNode(struct node**);

#endif