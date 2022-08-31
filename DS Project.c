#include <stdio.h>
#include<string.h>
#include<stdlib.h>
struct book
{
	int bookno;
	char bookname[100];
	char author[100];
	struct book *next;
}*start=NULL,*newnode,*ptr,*pre;
struct lend
{
	int lb1;
	char lbname[100];
	char lauthor[100];
	struct lend *jump;
}*root=NULL,*newlend,*lptr,*lpre;
struct lend *borrow()
{
	newlend=malloc(sizeof(struct lend));
	printf("Enter the book you needed : ");
	int n;
	scanf("%d",&n);
	ptr=start;
    while(ptr->next!=NULL)
    {
    	pre=ptr;
        if(ptr->bookno==n)
            break;
        ptr=ptr->next;
    }
    newlend->lb1=ptr->bookno;
    strcpy(newlend->lbname,ptr->bookname);
    strcpy(newlend->lauthor,ptr->author);
    if(root==NULL)
    {
        root=newlend;
        newlend->jump=NULL;
    }
    else
    {
    lptr=root;
    while(lptr->jump!=NULL)
    	lptr=lptr->jump;
    lptr->jump=newlend;
    newlend->jump=NULL;
    }
    pre->next=ptr->next;
    free(ptr);
	return root;
}
void displaylend()
{
	printf(".......................................................................................................................\n................................................    BORROWED BOOKS    .................................................\n.......................................................................................................................\n");
	if(root==NULL)
		printf("..........No books were Taken..........");
	else{
    lptr=root;
    while(lptr!=NULL)
    {
        printf("[Book Number : %d ,",lptr->lb1);
        printf("Book Name : %s ,",lptr->lbname);
        printf("Author : %s]",lptr->lauthor);
        printf("\n");
        lptr=lptr->jump;
    }
}
}
struct book *create(struct book *start)
{
    newnode=malloc(sizeof(struct book));
    printf("ENTER BOOK NUMBER : ");
    scanf("%d",&newnode->bookno);
    fflush(stdin);
    printf("\nEnter Book Name : ");
    fflush(stdin);
    scanf("%[^\n]",newnode->bookname);
    fflush(stdin);
    printf("\nEnter Author Name : ");
    scanf("%[^\n]",newnode->author);
    if(start==NULL)
    {
        start=newnode;
        newnode->next=NULL;
    }
    else
    {
    ptr=start;
    while(ptr->next!=NULL)
    ptr=ptr->next;
    ptr->next=newnode;
    newnode->next=NULL;
    }
    
    return start;
}
struct book *deletesp(struct book *start)
{
    int pos,count=1;
    printf("\nENTER BOOK NO");
    scanf("%d",&pos);
    ptr=start;
    while(pos!=ptr->bookno)
    {
        pre=ptr;
        ptr=ptr->next;
    }
    pre->next=ptr->next;
    free(ptr);
    return start;
}
void display(struct book *start)
{
	printf(".......................................................................................................................\n.................................................    LIBRARY BOOKS    .................................................\n.......................................................................................................................\n");
	if(start==NULL)
		printf("..........No Books Available..........");
    else{
	ptr=start;
    while(ptr!=NULL)
    {
        printf("[Book Number : %d ,",ptr->bookno);
        printf("Book Name : %s ,",ptr->bookname);
        printf("Author : %s]",ptr->author);
        printf("\n");
        ptr=ptr->next;
    }
}
}
void count(struct book *start)
{
    int c=0;
     ptr=start;
    while(ptr!=NULL)
    {
        c++;
        ptr=ptr->next;
    }
    printf("..........Number Of Books : %d ..........",c);
}
void search(struct book *start)
{
	int x=0;
    char key[100];
    printf("ENTER BOOK NAME");
	fflush(stdin);
    scanf("%[^\n]",key);
     ptr=start;
    while(ptr->next!=NULL)
    {
        if(ptr->bookname==key)
        {
            x=1;
            break;
        }
        ptr=ptr->next;
    }
    if(strcmp(ptr->bookname,key)==0)
    printf("Book Is Available");
    else
    printf("Sorry,Book Is Not Available");
}
int main()
{
	printf("________________________________________________________________________________________________________________________");
	printf("\n|.....................................................................................................................|\n|..........................................<<  LIBRARY MANAGEMENT SYSTEM  >>..........................................|\n|.....................................................................................................................|\n");
	printf("_______________________________________________________________________________________________________________________");
	int ch;
	while(1)
	{
		printf("\n1.Add A New Book\n2.Remove A Book\n3.Display Books\n4.Number of Books\n5.Search For A Book\n6.Take away Book\n7.Display Borrowed Books\n");
		scanf("%d",&ch);
		printf("________________________________________________________________________________________________________________________");
		switch(ch)
		{
			case 1: start=create(start);
			break;
			case 2: start=deletesp(start);
			break;
			case 3: display(start);
			break;
			case 4: count(start);
			break;
			case 5:search(start);
			break;
			case 6:root=borrow();
			break;
			case 7:displaylend();
			break;
		}
	}
}
