#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[20];
    int score;
    struct Node *next;
};

struct Node *head = NULL;

void add(char *name, int score) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void delete(char *name) {
    struct Node *current = head;
    struct Node *previous = NULL;
    
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            }else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void print() {
    struct Node *current = head;
    while (current!=NULL) {
        printf("%s %d\n", current->name, current->score);
        current = current->next;
    }
}

void quit() {
    struct Node *current = head;
    while (current != NULL) {
        struct Node *next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    char command[20];
 
    while (1) {
        scanf("%s", command);
 
        if (strcmp(command, "add") == 0) {
            char name[50];
            int score;
            scanf("%s %d", name, &score);
            add(name, score);
 
        } else if (strcmp(command, "delete") == 0) {
            char name[50];
            scanf("%s", name);
            delete(name);
 
        } else if (strcmp(command, "print") == 0) {
            print();
 
        } else if (strcmp(command, "quit") == 0) {
            quit();
            break;
        }
    }
 
    return 0;
}
