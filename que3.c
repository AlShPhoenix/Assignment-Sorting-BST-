/*-- PROGRAM-3 --
-->Make a program to construct a BST for the following set of names:  
    Arthi Christy Dorothy Fraser Eliza 
    Insert a name "David" into BST 
---------------------------------------------------------------------------------------------
 BY: Alok Sharma (11911001 CSE)
---------------------------------------------------------------------------------------------*/

#include<string.h>
#include<stdio.h>
#include<stdlib.h>         

typedef struct node{                    //defining structure of the tree node
    char data[10];      
      //data will be a string here       
    struct node* left;
    struct node* right;
} tnode;

tnode* root;                //declare root of the binary tree

tnode* newnode(char s[20])
{               //function to create a node
    struct node* new=(struct node*)malloc(sizeof(struct node));
    
    strcpy(new->data,s);

    new->left=NULL;
    new->right=NULL;
    
    return new;

}
void initialise()           //function to create the BST as given in the qestion 
{
    root=newnode("Arthi");
    
    root->right=newnode("Christy");
    
    root->right->right=newnode("Dorothy");
    
    root->right->right->right=newnode("Fraser");
    
    root->right->right->right->left=newnode("Eliza");

}
/*
    binary tree is:
            "Arthi"
                \
                "Christy"
                    \
                    "Dorothy"
                        \
                        "Fraser"
                           /
                      "Eliza"
*/



void insert(struct node* t,char* s)      //function to insert the node into the given binary tree
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=t;
    while(1)
    {
        if(temp)
        {
            if(strcmp(temp->data,s)>0)         //move to left if node data is greator than the new node
            {
                
                if(temp->left)
                    temp=temp->left;
                
                else
                {
                    temp->left=newnode(s); ;          //if a node is null then create a new node
            
                    return;
                }
                
            }
            else
            {
                
                if(temp->right)             //move to right if node data is smaller than the new node
                    temp=temp->right;
                
                else
                {
                    temp->right=newnode(s);          //if a node is null then create a new node
            
                    return;
                }
                
            }
        }
        
    }
    
    
}

/*function to print the tree in preorder*/
void preorder(struct node* t)
{
    if(!t)
    {
        return;
    }
    if(t)
    {        
        puts(t->data);
        preorder(t->left);
        preorder(t->right);
    }
    
}

void main()
{
    printf("\n (3). INSERTING A NODE IN A B.S.T. OF STRINGS\n");


    initialise();               //create the binary search tree as given

    
    printf("\n Initially the binary tree in preorder is : \n");

    preorder(root);                     //print the initial BST

    printf("\n Now, after inserting \"David\" into this BST : \n");

    insert(root,"David");           //call insert function

    preorder(root);                 //print the new BST in preorder

}