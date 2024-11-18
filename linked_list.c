#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void insertNode(struct Node** p_head, struct Node* position, int data) 
{
     struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if (*p_head == NULL || position == *p_head) { // Thêm vào đầu
        new_node->next = *p_head;
        *p_head = new_node;
    } else { // Tìm vị trí chèn
        struct Node* temp = *p_head;
        while (temp->next != NULL && temp->next != position) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void pushBack(struct Node** p_head, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*p_head == NULL) { // Danh sách rỗng
        *p_head = new_node;
    } else { // Duyệt đến cuối danh sách
        struct Node* temp = *p_head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void deleteNode(struct Node** p_head, struct Node* position) 
{
   if (*p_head == NULL || position == NULL) return;

    if (*p_head == position) { // Xóa node đầu
        struct Node* temp = *p_head;
        *p_head = (*p_head)->next;
        free(temp);
    } else { // Duyệt tìm node trước node cần xóa
        struct Node* temp = *p_head;
        while (temp->next != NULL && temp->next != position) {
            temp = temp->next;
        }
        if (temp->next == position) {
            temp->next = position->next;
            free(position);
        }
    }
}

int sizeOfList(struct Node* head) 
{
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void deleteList(struct Node **p_head)
{
    // your implementation
}

// Display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// display the linked list to a string output
void displayListToString(struct Node* head, char* output) {
    sprintf(output, "%s", "");
    char temp_str[100];
    struct Node* temp = head;
    while (temp != NULL) {
        sprintf(temp_str, "%d -> ", temp->data);
        strcat(output, temp_str);
        temp = temp->next;
        
    }
    // concatenate NULL to the output string    
    sprintf(temp_str, "NULL");
    strcat(output, temp_str);
}
