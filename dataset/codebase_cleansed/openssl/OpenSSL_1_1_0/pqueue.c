pitem *pitem_new(unsigned char *prio64be, void *data)
{
pitem *item = OPENSSL_malloc(sizeof(*item));
if (item == NULL)
return NULL;
memcpy(item->priority, prio64be, sizeof(item->priority));
item->data = data;
item->next = NULL;
return item;
}
void pitem_free(pitem *item)
{
OPENSSL_free(item);
}
pqueue *pqueue_new()
{
pqueue *pq = OPENSSL_zalloc(sizeof(*pq));
return pq;
}
void pqueue_free(pqueue *pq)
{
OPENSSL_free(pq);
}
pitem *pqueue_insert(pqueue *pq, pitem *item)
{
pitem *curr, *next;
if (pq->items == NULL) {
pq->items = item;
return item;
}
for (curr = NULL, next = pq->items;
next != NULL; curr = next, next = next->next) {
int cmp = memcmp(next->priority, item->priority, 8);
if (cmp > 0) {
item->next = next;
if (curr == NULL)
pq->items = item;
else
curr->next = item;
return item;
}
else if (cmp == 0)
return NULL;
}
item->next = NULL;
curr->next = item;
return item;
}
pitem *pqueue_peek(pqueue *pq)
{
return pq->items;
}
pitem *pqueue_pop(pqueue *pq)
{
pitem *item = pq->items;
if (pq->items != NULL)
pq->items = pq->items->next;
return item;
}
pitem *pqueue_find(pqueue *pq, unsigned char *prio64be)
{
pitem *next;
pitem *found = NULL;
if (pq->items == NULL)
return NULL;
for (next = pq->items; next->next != NULL; next = next->next) {
if (memcmp(next->priority, prio64be, 8) == 0) {
found = next;
break;
}
}
if (memcmp(next->priority, prio64be, 8) == 0)
found = next;
if (!found)
return NULL;
return found;
}
pitem *pqueue_iterator(pqueue *pq)
{
return pqueue_peek(pq);
}
pitem *pqueue_next(pitem **item)
{
pitem *ret;
if (item == NULL || *item == NULL)
return NULL;
ret = *item;
*item = (*item)->next;
return ret;
}
int pqueue_size(pqueue *pq)
{
pitem *item = pq->items;
int count = 0;
while (item != NULL) {
count++;
item = item->next;
}
return count;
}
