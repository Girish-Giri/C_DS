#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct sll
{
	FILE *pt;
	char *str;
	struct sll *link;
}node; 

node *first = NULL; 
node *last = NULL;

void create_node(char *arr)
{
	node *new = (node*)malloc(sizeof(node)); 
	new->pt = fopen(arr, "r"); //data entry
	new->str=arr;
	new->link = NULL; //link entry, newest will hold null link

    if(first == NULL)
    {
        first = new;
        last = new;
    }
    else
    {
    	last->link = new;
    	last = new;    
    }
    
}

void search(char *ar)
{
	int i, count;
	node *temp = first; 
	do
	{
		count = 0;
		for(i=0; i<=9; i++)
		{
			if(ar[i] == (temp->str)[i])
			//printf("%c\n", ar[i]);
			count++;
			else
			break;//temp = temp->link;
		}
	char buff[20];	
		if(count==10)
		{
		fscanf(temp->pt, "%s", buff);//fscanf(temp->link->pt, "%s", buff);
		printf("A call from: %s\n",buff);
		//fclose(temp->pt);
		return;//to break the func
		}
		else
		temp = temp->link;
	}while(temp->pt!=NULL);
}



void create_txt(char *ar)
{
node *new = (node*)malloc(sizeof(node)); 
if(new->pt == NULL)//
	{
	char in[15];
		printf("File not Found, create new here:\nEnter as id.txt:\n");
		scanf("%s", in);
		new->pt = fopen(in, "w"); 

	char str[20];
	printf("Enter contact name(Hit ctrl+D after finishing)\n");
	while(fgets(str,20,stdin)!=NULL)
	{
		fprintf(new->pt,"%s",str);//types in txt file till it encounters NULL
	}
	fclose(new->pt);
	create_node(in);//calling a function to create the file as a node		
	}
}

/****FOR DEBUGGING*****/
/*
void display()
{
	if(first == NULL)
	{
		printf("List is empty\n");
		return; 
	}

	else
	{
		node *temp = first; 
		do	
		{
			printf("%s\t",temp->str);
			temp = temp->link;
		}while(temp!=NULL);
	}
}
*/
int main() 
{
	char inp[10];	
	printf("\tENTER TO YOUR VERY OWN TRUECALLER!!\t\n");
	
	create_node("9167510917.txt");
	create_node("9886039323.txt");
	create_node("8722253933.txt");
	create_node("9508794656.txt");
	printf("\nEnter Caller's No.:\n");
	scanf("%s", inp);
	search(inp);
	//search("9886039323");
    return 0;
}
