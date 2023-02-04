#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <stdbool.h>
struct letter_node
{
    char c;
    struct letter_node* next;
    struct letter_node* prev;
};
typedef struct letter_node letter_node;
letter_node *headd = NULL;

void insert_letter (char c)   //at end
{
    letter_node * new_letter = malloc (sizeof(letter_node));
   new_letter->c = c ;
   new_letter->next=NULL;

   if (headd==NULL)
   {
       new_letter->prev=NULL;
       headd = new_letter;
       return;
   }
       letter_node * temp = headd ;
       while (temp->next!= NULL)
       {
           temp=temp->next;
       }
       temp->next = new_letter;
       new_letter->prev=temp;
   return;
}

letter_node* gettail()
{
    letter_node *temp=headd;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    return temp;
}

void display_letters()
{
    letter_node * temp = headd ;
       while (temp!=NULL)
       {
           printf("%c",temp->c);

           //if(temp->c=='.' &&temp->next=='\n')
           // {
            // printf("\n");
            //}
            //
            temp=temp->next;
       }

}

void capital_letters()
{
    letter_node * temp = headd ;
    temp->c = toupper(temp->c);
    while(temp->next !=NULL)
    {
    if(temp->c=='\n')
    {
        temp->next->c = toupper(temp->next->c);
    }
    temp=temp->next;
    }
}
void insertAfter(struct letter_node* prev_node, char new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }

    /* 2. allocate new node */
    struct letter_node* new_node = (struct letter_node*)malloc(sizeof(struct letter_node));

    /* 3. put in the data  */
    new_node->c = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. Make the next of prev_node as new_node */
    prev_node->next = new_node;

    /* 6. Make prev_node as previous of new_node */
    new_node->prev = prev_node;

    /* 7. Change previous of new_node's next node */
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}
void goback()
{
    letter_node*temp=gettail();
    while(temp->c!=' ')
    {
        temp=temp->prev;
    }
    insertAfter(temp,'(');

}
void delete_Enterfrom_fgets(char *name)
{
    char temp[20]={'\0'};
    int i=0;
   while(name[i]!='\n')   //deleting '\n' from array of characters
    {temp[i]=name[i];
    i++;}
    temp[i]='\0';
    strcpy(name,temp);

}

int main()
{
   FILE * ptr1 ;
   ptr1=NULL;
   ptr1 = fopen("Input.txt","r");
   if(ptr1==NULL)
    printf("error \n");


int select;
char name[20];
char target[20];
//char target2[20];

printf("If you want to Correct All enter : 1 \n");
printf("If you want to Correct certain Name enter : 2 \n");
printf("If you want to Exit program enter : 3 \n");

printf("---Your selection--- : ");
scanf("%d",&select);

while(select!=3)
{


//printf("---Your selection--- : ");
//scanf("%d",&select);
printf("\n");

if(select==2)
{
    printf("Enter name of selection : ");
   scanf(" %[^\n]%*c",name);  //get whole sentence
   char ch;
   fgets(target,20,ptr1);

   //int j=0;
   //while(target[j]!='\n')
   //{
    //insert_letter(target[j]);
   //j++;}
   //insert_letter(target[j]);

   delete_Enterfrom_fgets(target);
   ch=fgetc(ptr1);

//printf("ch : %c",ch);
//return;
bool test=false;
  while(ch!=EOF)
   {

    if(!strcmp(name,target))
    {
     printf("\nName Found\n\n");
     test=true;
     insert_letter(toupper(ch));
      while(ch!='\n')
     {
     if(ch==' ')
       {
         insert_letter(' ');
           ch=fgetc(ptr1);
           while(ch==' ')
           {
            ch=fgetc(ptr1);
           }
           insert_letter(ch);
           if(ch=='(')
       {
            while(ch!=' ')
           {
            ch=fgetc(ptr1);
            if(ch==' ')
            {
                continue;
            }
            insert_letter(ch);
           }
           insert_letter(')');
       }
       }
       else if(ch==','||ch==';')
       {
           insert_letter(ch);
           insert_letter(' ');
           insert_letter(toupper(fgetc(ptr1)));
       }
       else if(ch=='.')
       {
           insert_letter(ch);
           insert_letter(' ');
           //insert_letter('\n');
           ch='\n';;
           }
        else if(ch=='!')
        {
            insert_letter(ch);
           insert_letter(' ');
        }
        else if(ch==')')

        {
            insert_letter(ch);
            goback();
        }
       else if(test)
             {test=false;}
       else
            insert_letter(ch);
        ch=fgetc(ptr1);
        }

     }
    else
      while(ch!='\n')
      {
        insert_letter(ch);
        ch=fgetc(ptr1);
      }
      fgets(target,20,ptr1);
      insert_letter('\n');
      delete_Enterfrom_fgets(target);
      ch=fgetc(ptr1);
}
insert_letter('\n');

}
else
{

char ch ;
   ch=fgetc(ptr1);
   while(ch!=EOF)
   {
        if(ch==' ')
       {
         insert_letter(' ');
           ch=fgetc(ptr1);
           while(ch==' ')
           {
            ch=fgetc(ptr1);
           }
           insert_letter(ch);
           if(ch=='(')
       {
            while(ch!=' '&&ch!=')')
           {
            ch=fgetc(ptr1);
            if(ch==' ')
            {
                continue;
            }
            insert_letter(ch);
           }
           if(ch!=')')
           {
            insert_letter(')');
           insert_letter(' ');
           }

       }
       }
       else if(ch=='(')
   {
       insert_letter(ch);
            while(ch!=' ')
           {
            ch=fgetc(ptr1);
            if(ch==' ')
            {
                continue;
            }
            insert_letter(ch);
           }
           insert_letter(')');
           insert_letter(' ');
       }
       else if(ch==','||ch==';'||ch=='.')
       {
           insert_letter(ch);
           insert_letter(' ');
           insert_letter(toupper(fgetc(ptr1)));
       }
        else if(ch=='!')
        {
            insert_letter(ch);
           insert_letter(' ');
        }
        else if(ch==')')

        {
            insert_letter(ch);
            goback();
        }
       else

            insert_letter(ch);
        ch=fgetc(ptr1);
   }
capital_letters();
   }
   fclose(ptr1);


  display_letters();

  printf("\n---Your selection--- : ");
scanf("%d",&select);


}
    return 0;
}
