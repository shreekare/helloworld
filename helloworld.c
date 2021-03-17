#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 8
typedef struct Chunk
{
    int data[CHUNK_SIZE];
    short filled;
    struct Chunk *next;
} Chunk;

typedef struct Position
{
    Chunk *chunk;
    short index;
} Position;

void incr_pos(Position *p, short incr)
{
    if (p == NULL || p->chunk == NULL)
        return;

    for (int i = 0; i < incr && p->chunk; ++i)
    {
        if (++p->index == p->chunk->filled)
        {
            p->index = 0;
            p->chunk = p->chunk->next;
        }
    }
}

Chunk *scan_seq(const char *msg)
{
    printf("%s:", msg);

    Chunk *head = NULL, *cur = NULL;

    int n;

    while (scanf("%d", &n))
    {
        // check if a new chunk needs to be created
        if (cur == NULL || cur->filled == CHUNK_SIZE)
        {
            if (head == NULL)
            {
                // initialize both head and cur to the newly created node
                cur = head = (Chunk *)malloc(sizeof(Chunk));
            }
            else
            {
                // create new node at cur->next and move cur to the new node
                cur->next = (Chunk *)malloc(sizeof(Chunk));
                cur = cur->next;
            }

            // initialize the new chunk
            cur->filled = 0;
            cur->next = NULL;
        }

        // insert the read character into the chunk at the right place
        cur->data[cur->filled++] = n;

        scanf(",");
    }

    while (getchar() != '$')
        ;

    return head;
}

void print_seq(Chunk *head)
{
    for (Position p = {head, 0}; p.chunk; incr_pos(&p, 1))
    {
        printf("%d", p.chunk->data[p.index]);
        if (p.chunk->next || p.index + 1 < p.chunk->filled)
            printf(",");
    }
    printf("\n");
}

int main()
{
    Chunk *s1 = scan_seq("Enter first sequence");
    print_seq(s1);
    Chunk *s2 = scan_seq("Enter second sequence");
    print_seq(s2);
}
