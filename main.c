#include <stdio.h>
#include <stdlib.h>
#include "linked_op.h"

int main(int argc,char **argv)
{
    struct node *head=NULL;
    int x;
    char c;

    printf("Select Option :\n\t\t\t1-Add Node\n\t/\
            2-Display Nodes\n\t/\
            3-Add Head Node\n\t/\
            4-Add Node at a given Pos\n\t/\
            5-Delete Node Tete\n\t/\
            6-Delete node at a given position\n\t/\
            7-Delete node from value\n\t/\
            8-Get the node from position\n\t/\
            9-Get size linked list\n\t/\
            u-Update a node at a position\n\t/\
            v-update node corresponding to the data value\n\t/\
            s-sort node\n\t/\
            r-reverse list\n\n");
            
    while (c!='q') {

        
        printf("Entre choix :");
        c=getchar();
        printf("your choice is %c\n",c);
        printf("wtf\n");
        
        switch (c) {
            case '1':
                printf("Entrer Data :");
                scanf("%d",&x);
                if(addNode(&head,x)==0)
                    printf("Node Ajouter Avec Success\n");
                else{

                    printf("Erreur ");
                    goto Quit;
                }
            break;

            case '2':
                printf("case 2\n\n");
                if(head!=NULL)
                    display(head);
            break;

            case '3':
                addHeadNode(&head,123);
                printf("Node added succefuly\n");
            break;

            case '4':/*add node valeur 554 at pos 3*/
                addNodePos(&head, 554, 3);
                printf("Added Succefully at pos === 3\n");
            break;

            case '5':/*delete node tete*/
                x=deleteNodeTete(&head);
                printf("Node valeur : %d deleted\n",x);
            break;
            
            case '6':/*delete node position ==3*/
                deleteNodePos(&head,3);
            break;

            case '7':/*supprimer node valeur ==83*/
                printf("node %d pos %d supprimer \n",88,deleteNodeValeur(&head,88));
            break;

            case '8':/*return position of node with data= 24*/
                findNode(head,24);
            break;

            case '9':
                printf("There is %d node in the list \n",sizeNode(head));
            break;

            case 'u':
                if(updateNodePos(&head, 4, 124)==0)
                    printf("Succefuly updated \n");
                else
                    printf("Update node return -1\n");
            break;

            case 'v':
                x=updateNodeValeur(&head,233,33);
                printf("Node pos %d updated\n",x);
            break;

            case 's':
                sortNode(&head);
                printf("Node Sorted\n");
            break;

            case 'r':
                if(0==reverseNode(&head))
                    printf("Reversed done\n");
                else
                    printf("Reverse Node Error \n");
            break;

        }
    }
    
Quit:
    if(head!=NULL)
        deleteAllNode(&head);
    return 0;
}