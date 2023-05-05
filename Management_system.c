#include <stdio.h>
#include <stdlib.h>

// initialize node
typedef struct node
{
    int data;
    struct node *next;
};

// insert value ke node pertama
void push(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// insert value ke node setelahnya
void insertAfter(struct node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// insert end
void insertEnd(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}

// Delete data paling baru
void deleteRecent(struct node **head, int position)
{
    struct node *temp;
    struct node *prev;
    temp = *head;
    prev = *head;
    for (int i = 0; i < position; i++)
    {
        if (i == 0 && position == 1)
        {
            *head = (*head)->next;
            free(temp);
        }
        else
        {
            if (i == position - 1 && temp)
            {
                prev->next = temp->next;
                free(temp);
            }
            else
            {
                prev = temp;
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
}

void print(struct node *node)
{
    printf("Item yang tersedia adalah : ");
    while (node != NULL)
    {
        printf(" %d", node->data);
        node = node->next;
    }
}

// driver
int main()
{
    int role;
    int command;
    int data;
    char ch;
    struct node *head = NULL;
begin:
    printf("----------------Selamat Datang di Agri Management System---------------- \n");
    printf("Silakan pilih salah satu operasi di bawah ini : \n");
    printf("1. Admin\n");
    printf("2. Pegawai\n");
    printf("silakan ketik -9 untuk keluar\n");
    printf("----------------------------------------------------------------------- \n");
    printf("command: ");

    scanf("%d", &role);
    
    while (role != -9)
    {
        printf("\n");
        if (role == 1) // admin
        {
        admin_choice:
            printf("\n");
            printf("-------------Selamat datang di sistem admin------------\n");
            printf("Silakan pilih operasi sebagai berikut: \n");
            printf("1. Insert data pada sistem\n");
            printf("2. Hapus data pada terbaru pada sistem\n");
            printf("3. Cetak data pada sistem\n");
            printf("silakan ketik -9 untuk keluar\n");
            printf("----------------------------------------------------------------------- \n");
            printf("command: ");
            scanf("%d", &command);

            // insert data
            if (command == 1)
            {
                printf("Silakan masukkan data: ");
                scanf("%d", &data);
                push(&head, data);
                goto admin_choice;
            }

            else if (command == 2)
            {

                deleteRecent(&head, 1);
                goto admin_choice;
            }

            else if (command == 3)
            {
                print(head);
                goto admin_choice;
            }

            // keluar dari sistem
            else if (command == -9)
            {
                printf("\n");
                goto begin;
            }
        }
        else if (role == 2)
        {
            /* code */
        }
        scanf("%d", &role);
    }
}