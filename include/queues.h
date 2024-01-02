#define QUEUE_IMPLEMENTATION
#ifdef QUEUE_IMPLEMENTATION

typedef struct NodeQ {
    int value;
    struct NodeS *next;
} NodeQ;

typedef struct {
    NodeQ *head;
    NodeQ *tail;
    int size;
} Queue;

Queue *create_queue();
int queue_size(Queue *queue);
bool is_empty_queue(Queue *queue);
int queue_peek(Queue *queue, bool *status);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue, bool *status);
void destroy_queue(Queue *queue);
void queue_print(Queue *queue);

#endif
