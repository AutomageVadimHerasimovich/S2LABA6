//
// Created by Вадим Герасимович on 4/21/23.
//

#include "FFF.h"
int input(int min, int max) {
    int x;
    while (scanf("%d", &x) != 1 || x < min || x > max || x % 1 != 0 || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    return x;
}

queue* new_queue_node(int data) {
        queue* new_node = (queue*)malloc(sizeof(queue));
        new_node->data = data;
        new_node->next = NULL;
        return new_node;
    }

// Функция для вставки элемента в очередь
void insert_element_in_queue(queue** rear, queue** front, int data) {
        queue* new_node = new_queue_node(data);

        if (*rear == NULL) {
            *rear = new_node;
            *front = new_node;
            return;
        }

        (*rear)->next = new_node;
        *rear = new_node;
    }

// Функция для определения размера очереди
int size(queue* front) {
    int count = 0;
    while (front != NULL) {
        count++;
        front = front->next;
    }
    return count;
}

void print_Queue(queue* head) {
    queue* current = head;
    printf("\nОчередь: ");
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

void get_char(char* temp){
    fflush(stdin);
    *temp=getc(stdin);
    fflush(stdin);
}

void clear_Queue(queue** head) {
    queue* current = *head;
    queue* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int task1() {
    queue *front = NULL;
    queue *rear = NULL;
    int max_size;
    char data, i = 0;
    char target;
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &max_size);
    printf("Enter the target character: ");
    get_char(&target);
    printf("Enter the elements of the queue: \n");
    while (size(front) < max_size) {
        i++;
        printf("\nВведите символ №%d : ", i);
        get_char(&data);
        if (data == target) break;
        insert_element_in_queue(&rear, &front, data);
    }
    printf("Size of the queue: %d\n", size(front));
    printf("Работа функции вывода --> ");
    print_Queue(front);
    clear_Queue(&front);
    return 0;
}

struct Deck *create_right(struct Deck *tail, char x) {
    struct Deck *n;
    n = (struct Deck *) malloc(sizeof(struct Deck));
    n->next = NULL;
    n->prev = NULL;
    n->data = x;
    if (tail == NULL) {
        tail = n;
    } else {
        n->prev = tail;
        tail->next = n;

        tail = n;
    }
    return tail;
}

struct Deck *create_left(struct Deck *head, char x) {
    struct Deck *n;
    n = (struct Deck *) malloc(sizeof(struct Deck));
    n->next = NULL;
    n->prev = NULL;
    n->data = x;
    if (head == NULL) {
        head = n;
    } else {
        n->next = head;
        head->prev = n;

        head = n;
    }
    return head;
}

void print_Deck(struct Deck *head) {
    struct Deck *p = head;
    int i = 0;
    while (p != NULL) {
        printf("%c ", p->data);
        p = p->next;
        i++;
    }
}

int count_Deck(struct Deck *tail) {
    struct Deck *p = tail;
    int count = 0;

    while (p != NULL) {
        count++;
        p = p->prev;
    }

    return count;
}

struct Deck *pop_Deck(struct Deck *head) {
    struct Deck *temp = head;
    if (head != NULL) {
        head = head->next;
        free(temp);
        return head;
    } else
        return NULL;
}

void free_Deck(struct Deck **head) {
    while (*head != NULL) {
        *head = pop_Deck(*head);
    }
    free(*head);
}

int task2() {
    struct Deck *head = NULL;
    struct Deck *tail = NULL;
    char num, target;
    printf("\nInput max size of queue: ");
    int i = 0, ch = 0, size = input(1, INT_MAX);
    printf("\nInput target symbol: ");
    get_char(&target);
    while (i!=size) {
        if (i == 0) {
            printf("\nInput %d element of queue: ", i + 1);
            get_char(&num);
            if (target == num) break;
            tail = create_right(tail, num);
            if (head == NULL) {
                head = tail;
            }
        } else {
            printf("\nInput %d element of queue: ", i + 1);
            get_char(&num);
            if (target == num) break;
            if (ch % 2 == 0)
                tail = create_right(tail, num);
            else
                head = create_left(head, num);
            ch++;
        }
        i++;
    }
    printf("\nQueue: ");
    print_Deck(head);
    printf("\n\nSize : %d", count_Deck(tail));
    free_Deck(&head);
    return 0;
}