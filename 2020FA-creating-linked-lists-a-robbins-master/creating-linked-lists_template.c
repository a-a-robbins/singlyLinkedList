#include <stdio.h>
#include <stdlib.h>

typedef struct node_def node;
struct node_def
{
    int val;
    node *next;
};

node *makeNode(int val);
node *insertFront(node *head, node *new);
void printList(node *head);
node *deleteNode(node *head, int val);
node *modifyNode(node *head, int old, int new);
int inList(node *head, int val);
void lookForDupes(node *L);
int length(node *L);

int main()
{
  int numNodes = 0;
  int userNum; 
  int modNum; 
  int removeNum; 
  node *head = NULL; 
  node *temp = NULL; 
 
  printf("How many nodes? ");
  scanf("%d", &numNodes); 
 
  head = makeNode(numNodes);
 
  printList(head); 
 
  printf("Enter a number to search for: "); 
  scanf("%d", &userNum); 

  
  if(inList(head, userNum) != 0)
  {
    printf("Found in list\n"); 
    printf("Change to what value? "); 
    scanf("%d", &modNum); 
    modifyNode(head, userNum, modNum); 
    printList(head); 

    printf("Enter a number to remove: "); 
    scanf("%d", &removeNum); 
    deleteNode(head, removeNum);  
    printList(head); 
  }
  else
  {
    printf("Not in list\n"); 
    printf("Enter a number to remove: "); 
    scanf("%d", &removeNum);  
    deleteNode(head, removeNum); 
    printList(head);  
  }

  lookForDupes(head); 
  

	return 0;
}

/**
 * create a node for your list
 * return a pointer to that node (node *)
 */  

node *makeNode(int val)
{
  node *head = NULL; 
  node *temp = NULL; 

  for(int i = 0; i < val; i++)
  {
    temp = malloc(sizeof(node)); 
    temp->val = rand() % 9999; 
    temp->next = head; 
    head = temp; 
    temp = NULL;
  }

  return head; 
}


/**
 * add a node to the front of the list
 * return new front of list
 */
 
node *insertFront(node *head, node *new)
{
  node *temp = head; 
  head = new; 
  head->next = temp; 

  return head; 
}

/**
 * P: print out the linked list (10 per line)
 */
 
void printList(node *head)
{
  int i = 0; 

  while(head != NULL)
  {
    if(i < 10)
    {
      printf("%4d ", head->val); 
      head = head->next;
      i++; 
    }
    else
    {
      printf("\n"); 
      i = 0; 
    } 
  }
  printf("\n");
}

/**
 * P: given a value, search the list and remove the node with that value
 */

node *deleteNode(node *head, int val)
{
  node *t = malloc(sizeof(node));

  while(head != NULL)
  {
    if(head->val == val)
    {
      head->val = t->val; 
      head = head->next;      
    }

    head = head->next;
  }

  return head;
}

/**
 * given a new and old value, search the list for the old value and change it to the new one
 */
 
node *modifyNode(node *head, int old, int new)
{
  while(head != NULL)
  {
    if(head->val == old)
    {
      head->val = new; 
    }
    head = head->next;
  }

  return head;
}

/**
 * given a value, searches the list for that value
 * return true or false (or an integer 0 or 1 that you can use as true or false)
 */
 
int inList(node *head, int val)
{
  int numNode = 0; 
 
  while(head != NULL)
  {
    if(head->val == val)
    {
      numNode = 1; 
    }

    head = head->next; 
  }

  return numNode; 
}

/**
 * P: search the linked list looking for any duplicate values in the list
 */

void lookForDupes(node *L)
{
  node *currVal = L; 
  L = L->next;
  int dupeFound = 0; 

  while(L != NULL)
  {
    
    if(inList(L, currVal->val) != 0)
    {
      printf("Dupe found: %d\n", currVal->val);
      dupeFound = 1;
    } 

    currVal = L; 
    L = L->next; 
    
  }
  

  if(dupeFound == 0)
  {
    printf("No dupes found :(\n");
  }
  
}

/*
 * --Optional--
 * returns the number of nodes in a given list
*/
 int length(node *L)
 {
   int len = 0; 

   for(len = 0; L != NULL; len++)
   {
     L = L->next; 
   }

   return len; 
 }
