/*
 * 12_14b
 * Doubly LL - insert at begin, at end, after a value searched & Doubly LL - first, last, search and delete
 * Name: Sayooj K
 * Roll no: 45
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
  struct node* prev;
}*HEADER;

int deleteAll() {
  struct node *currentNode = HEADER, *previousNode;
  while (currentNode != NULL) {
    previousNode = currentNode;
    currentNode = currentNode->next;
    free(previousNode);
  }
  return (0);
}
struct node* newNode() {
  struct node* newptr = malloc(sizeof(struct node));
  if (newptr == NULL) {
    printf("Memory overflow\n");
    deleteAll();
    exit(0);
  }
  return (newptr);
}
int insertNodeFront (int data) {
  struct node *new = newNode();
  new->data = data;
  new->prev = HEADER;
  new->next = HEADER->next;
  HEADER->next = new;
  if (new->next != NULL)
    new->next->prev = new;
  return (0);
}
int insertNodeBefore(int data, int nextData) {
  struct node *new = newNode(), *currentNode=HEADER;
  new->data = data;
  while (currentNode->next != NULL && currentNode->data != nextData) {
    currentNode = currentNode->next;
  }
  if (currentNode->data == nextData) {
    new->next = currentNode;
    new->prev = currentNode->prev;
    currentNode->prev = new;
    if (new->next != NULL)
      new->prev->next = new;
  } else {
    printf("Insertion failed. Element not found\n");
  }
  return (0);
}
int insertNodeAfter(int data, int prevData) {
  struct node *new = newNode(), *currentNode=HEADER->next;
  new->data = data;
  while (currentNode != NULL && currentNode->data != prevData) {
    currentNode = currentNode->next;
  }
  if (currentNode->data != prevData) {
    printf("Insertion failed. Element not found\n");
  } else {
    new->prev = currentNode;
    new->next = currentNode->next;
    currentNode->next = new;
    if (new->next != NULL) {
      new->next->prev = new;
    }
  }
  return (0);
}
int insertNodeBack (int data) {
  struct node *new = newNode(), *currentNode=HEADER;
  while (currentNode->next != NULL) {
    currentNode = currentNode->next;
  }
  new->data = data;
  new->next = NULL;
  new->prev = currentNode;
  currentNode->next = new;
  return (0);
}
int deleteFirstNode () {
  struct node *currentNode = HEADER->next;
  if (HEADER->next == NULL) {
    printf("Empty linked list\n");
  } else {
    HEADER->next = HEADER->next->next;
    HEADER->next->prev = HEADER;
    free(currentNode);
  }
  return (0);
}
int deleteLastNode () {
  struct node *currentNode = HEADER;
  while (currentNode->next != NULL) {
    currentNode = currentNode->next;
  }
  if (currentNode == HEADER) {
    printf ("Empty linked list");
  } else {
    currentNode->prev->next = NULL;
    free(currentNode);
  }
  return (0);
}
int deleteNode(int data) {
  struct node *currentNode = HEADER;
  while (currentNode->next != NULL && currentNode->data != data) {
    currentNode = currentNode->next;
  }
  if (currentNode->data != data) {
    printf("Deletion failed. Node with matching data not found\n");
  } else {
    currentNode->prev->next = currentNode->next;
    if (currentNode->next != NULL) {
      currentNode->next->prev = currentNode->prev;
    }
    free(currentNode);
  }
  return (0);
}
int printAll() {
  struct node* currentNode = HEADER->next;
  printf("NULL<-HEADER<->");
  while (currentNode->next != NULL) {
    printf("%d<->", currentNode->data);
    currentNode = currentNode->next;
  }
  printf("%d->NULL\n", currentNode->data);
  return (0);
}
int showMenu() {
  char choice;
  int data, previousData, nextData;
  while (1) {
    printf("\n\n\tDoubly Linked List\n");
    printf("1. Insert at Front\n");
    printf("2. Insert before\n");
    printf("3. Insert after\n");
    printf("4. Insert at End\n");
    printf("5. Print Linked List\n");
    printf("6. Delete first node\n");
    printf("7. Delete node\n");
    printf("8. Delete last node\n");
    printf("9. Delete all\n");
    printf("0. Exit\n");
    printf("Enter your choice : ");
    scanf(" %c", &choice);
    printf("\n");
    switch (choice) {
      case '1':
        printf("Enter new data : ");
        scanf("%d", &data);
        insertNodeFront(data);
        break;
      case '2': 
        printf("Enter new data : ");
        scanf("%d", &data);
        printf("Enter data of the node before which new node is to be created : ");
        scanf("%d", &nextData);
        insertNodeBefore(data, nextData);
        break;
      case '3': 
        printf("Enter new data : ");
        scanf("%d", &data);
        printf("Enter data of the node after which new node is to be created : ");
        scanf("%d", &previousData);
        insertNodeAfter(data, previousData);
        break;
      case '4':
        printf("Enter new data : ");
        scanf("%d", &data);
        insertNodeBack(data);
        break;
      case '5':
        printAll();
        break;
      case '6':
        deleteFirstNode();
        break;
      case '7':
        printf("Enter data of the node to be deleted : ");
        scanf("%d", &data);
        deleteNode(data);
        break;
      case '8':
        deleteLastNode();
        break;
      case '9':
        deleteAll();
        break;
      case '0':
        deleteAll();
        exit(0);
        break;
    }
  }
  return (0);
}
int main() {
  // Initialise Linked list
  HEADER = malloc(sizeof(struct node));
  HEADER->data = 0;
  HEADER->next = NULL;
  HEADER->prev = NULL;
  
  // Menu
  showMenu();
  return (0);
}

/*
OUTPUT:
	Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 1

Enter new data : 12


	Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 1

Enter new data : 34


	Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 2

Enter new data : 34
Enter data of the node before which new node is to be created : 34


	Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 3

Enter new data : 65 
Enter data of the node after which new node is to be created : 12


	Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 4

Enter new data : 89


	Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 5

NULL<-HEADER<->34<->34<->12<->65<->89->NULL


	Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 6



	Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 7

Enter data of the node to be deleted : 34


	Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 8



	Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 5

NULL<-HEADER<->12<->65->NULL


	Doubly Linked List
1. Insert at Front
2. Insert before
3. Insert after
4. Insert at End
5. Print Linked List
6. Delete first node
7. Delete node
8. Delete last node
9. Delete all
0. Exit
Enter your choice : 9
*/