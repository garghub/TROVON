pitem *
pitem_new(unsigned char *prio64be, void *data)
{
pitem *item = (pitem *) OPENSSL_malloc(sizeof(pitem));
if (item == NULL) return NULL;
memcpy(item->priority,prio64be,sizeof(item->priority));
item->data = data;
item->next = NULL;
return item;
}
void
pitem_free(pitem *item)
{
if (item == NULL) return;
OPENSSL_free(item);
}
pqueue_s *
pqueue_new()
{
pqueue_s *pq = (pqueue_s *) OPENSSL_malloc(sizeof(pqueue_s));
if (pq == NULL) return NULL;
memset(pq, 0x00, sizeof(pqueue_s));
return pq;
}
void
pqueue_free(pqueue_s *pq)
{
if (pq == NULL) return;
OPENSSL_free(pq);
}
pitem *
pqueue_insert(pqueue_s *pq, pitem *item)
{
pitem *curr, *next;
if (pq->items == NULL)
{
pq->items = item;
return item;
}
for(curr = NULL, next = pq->items;
next != NULL;
curr = next, next = next->next)
{
int cmp = memcmp(next->priority, item->priority,8);
if (cmp > 0)
{
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
pitem *
pqueue_peek(pqueue_s *pq)
{
return pq->items;
}
pitem *
pqueue_pop(pqueue_s *pq)
{
pitem *item = pq->items;
if (pq->items != NULL)
pq->items = pq->items->next;
return item;
}
pitem *
pqueue_find(pqueue_s *pq, unsigned char *prio64be)
{
pitem *next;
pitem *found = NULL;
if ( pq->items == NULL)
return NULL;
for ( next = pq->items; next->next != NULL; next = next->next)
{
if ( memcmp(next->priority, prio64be,8) == 0)
{
found = next;
break;
}
}
if ( memcmp(next->priority, prio64be,8) ==0)
found = next;
if ( ! found)
return NULL;
#if 0
if ( prev == NULL)
pq->items = next->next;
else
prev->next = next->next;
#endif
return found;
}
void
pqueue_print(pqueue_s *pq)
{
pitem *item = pq->items;
while(item != NULL)
{
printf("item\t%02x%02x%02x%02x%02x%02x%02x%02x\n",
item->priority[0],item->priority[1],
item->priority[2],item->priority[3],
item->priority[4],item->priority[5],
item->priority[6],item->priority[7]);
item = item->next;
}
}
pitem *
pqueue_iterator(pqueue_s *pq)
{
return pqueue_peek(pq);
}
pitem *
pqueue_next(pitem **item)
{
pitem *ret;
if ( item == NULL || *item == NULL)
return NULL;
ret = *item;
*item = (*item)->next;
return ret;
}
int
pqueue_size(pqueue_s *pq)
{
pitem *item = pq->items;
int count = 0;
while(item != NULL)
{
count++;
item = item->next;
}
return count;
}
