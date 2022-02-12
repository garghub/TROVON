pitem *
pitem_new(PQ_64BIT priority, void *data)
{
pitem *item = (pitem *) OPENSSL_malloc(sizeof(pitem));
if (item == NULL) return NULL;
pq_64bit_init(&(item->priority));
pq_64bit_assign(&item->priority, &priority);
item->data = data;
item->next = NULL;
return item;
}
void
pitem_free(pitem *item)
{
if (item == NULL) return;
pq_64bit_free(&(item->priority));
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
if (pq_64bit_gt(&(next->priority), &(item->priority)))
{
item->next = next;
if (curr == NULL)
pq->items = item;
else
curr->next = item;
return item;
}
if (pq_64bit_eq(&(item->priority), &(next->priority)))
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
pqueue_find(pqueue_s *pq, PQ_64BIT priority)
{
pitem *next, *prev = NULL;
pitem *found = NULL;
if ( pq->items == NULL)
return NULL;
for ( next = pq->items; next->next != NULL;
prev = next, next = next->next)
{
if ( pq_64bit_eq(&(next->priority), &priority))
{
found = next;
break;
}
}
if ( pq_64bit_eq(&(next->priority), &priority))
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
printf("item\t" PQ_64BIT_PRINT "\n", item->priority);
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
