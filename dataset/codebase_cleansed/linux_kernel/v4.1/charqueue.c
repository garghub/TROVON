struct charqueue *visor_charqueue_create(ulong nslots)
{
int alloc_size = sizeof(struct charqueue) + nslots + 1;
struct charqueue *cq;
cq = kmalloc(alloc_size, GFP_KERNEL|__GFP_NORETRY);
if (cq == NULL)
return NULL;
cq->alloc_size = alloc_size;
cq->nslots = nslots;
cq->head = 0;
cq->tail = 0;
spin_lock_init(&cq->lock);
return cq;
}
void visor_charqueue_enqueue(struct charqueue *charqueue, unsigned char c)
{
int alloc_slots = charqueue->nslots+1;
spin_lock(&charqueue->lock);
charqueue->head = (charqueue->head+1) % alloc_slots;
if (charqueue->head == charqueue->tail)
charqueue->tail = (charqueue->tail+1) % alloc_slots;
charqueue->buf[charqueue->head] = c;
spin_unlock(&charqueue->lock);
}
BOOL visor_charqueue_is_empty(struct charqueue *charqueue)
{
BOOL b;
spin_lock(&charqueue->lock);
b = IS_EMPTY(charqueue);
spin_unlock(&charqueue->lock);
return b;
}
static int charqueue_dequeue_1(struct charqueue *charqueue)
{
int alloc_slots = charqueue->nslots + 1;
if (IS_EMPTY(charqueue))
return -1;
charqueue->tail = (charqueue->tail+1) % alloc_slots;
return charqueue->buf[charqueue->tail];
}
int charqueue_dequeue(struct charqueue *charqueue)
{
int rc;
spin_lock(&charqueue->lock);
rc = charqueue_dequeue_1(charqueue);
spin_unlock(&charqueue->lock);
return rc;
}
int visor_charqueue_dequeue_n(struct charqueue *charqueue, unsigned char *buf,
int n)
{
int rc, counter = 0, c;
spin_lock(&charqueue->lock);
for (;;) {
if (n <= 0)
break;
c = charqueue_dequeue_1(charqueue);
if (c < 0)
break;
*buf = (unsigned char)(c);
buf++;
n--;
counter++;
}
rc = counter;
spin_unlock(&charqueue->lock);
return rc;
}
void visor_charqueue_destroy(struct charqueue *charqueue)
{
if (charqueue == NULL)
return;
kfree(charqueue);
}
