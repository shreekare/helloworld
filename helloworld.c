#include <stdio.h>

int main()
{
    printf("Hello World!\n");
    printf("Hello Shreekar\n");
}

scan_seq()
{
    Chunk *head = NULL, *cur = NULL;

    while (read next number into 'n')
    {
        if (cur == NULL || cur->filled == CHUNK_SIZE)
        {
            if (head == NULL)
            {
                cur = head = (Chunk *) malloc(sizeof(Chunk));
            }
            else
            {
                cur->next = (Chunk *) malloc(sizeof(Chunk));
                cur = cur->next;
            }
            cur->filled = 0;
            cur->next = NULL;
        }
        cur->data[cur->filled++] = n;
    }
    return head;
}