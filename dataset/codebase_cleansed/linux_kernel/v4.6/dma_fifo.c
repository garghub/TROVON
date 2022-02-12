static bool addr_check(unsigned check, unsigned lo, unsigned hi)
{
return check - (lo + 1) < (hi - 1) - lo;
}
void dma_fifo_init(struct dma_fifo *fifo)
{
memset(fifo, 0, sizeof(*fifo));
INIT_LIST_HEAD(&fifo->pending);
}
int dma_fifo_alloc(struct dma_fifo *fifo, int size, unsigned align,
int tx_limit, int open_limit, gfp_t gfp_mask)
{
int capacity;
if (!is_power_of_2(align) || size < 0)
return -EINVAL;
size = round_up(size, align);
capacity = size + align * open_limit + align * DMA_FIFO_GUARD;
fifo->data = kmalloc(capacity, gfp_mask);
if (!fifo->data)
return -ENOMEM;
fifo->in = 0;
fifo->out = 0;
fifo->done = 0;
fifo->size = size;
fifo->avail = size;
fifo->align = align;
fifo->tx_limit = max_t(int, round_down(tx_limit, align), align);
fifo->open = 0;
fifo->open_limit = open_limit;
fifo->guard = size + align * open_limit;
fifo->capacity = capacity;
fifo->corrupt = 0;
return 0;
}
void dma_fifo_free(struct dma_fifo *fifo)
{
struct dma_pending *pending, *next;
if (!fifo->data)
return;
list_for_each_entry_safe(pending, next, &fifo->pending, link)
list_del_init(&pending->link);
kfree(fifo->data);
fifo->data = NULL;
}
void dma_fifo_reset(struct dma_fifo *fifo)
{
struct dma_pending *pending, *next;
if (!fifo->data)
return;
list_for_each_entry_safe(pending, next, &fifo->pending, link)
list_del_init(&pending->link);
fifo->in = 0;
fifo->out = 0;
fifo->done = 0;
fifo->avail = fifo->size;
fifo->open = 0;
fifo->corrupt = 0;
}
int dma_fifo_in(struct dma_fifo *fifo, const void *src, int n)
{
int ofs, l;
if (!fifo->data)
return -ENOENT;
if (fifo->corrupt)
return -ENXIO;
if (n > fifo->avail)
n = fifo->avail;
if (n <= 0)
return 0;
ofs = fifo->in % fifo->capacity;
l = min(n, fifo->capacity - ofs);
memcpy(fifo->data + ofs, src, l);
memcpy(fifo->data, src + l, n - l);
if (FAIL(fifo, addr_check(fifo->done, fifo->in, fifo->in + n) ||
fifo->avail < n,
"fifo corrupt: in:%u out:%u done:%u n:%d avail:%d",
fifo->in, fifo->out, fifo->done, n, fifo->avail))
return -ENXIO;
fifo->in += n;
fifo->avail -= n;
df_trace("in:%u out:%u done:%u n:%d avail:%d", fifo->in, fifo->out,
fifo->done, n, fifo->avail);
return n;
}
int dma_fifo_out_pend(struct dma_fifo *fifo, struct dma_pending *pended)
{
unsigned len, n, ofs, l, limit;
if (!fifo->data)
return -ENOENT;
if (fifo->corrupt)
return -ENXIO;
pended->len = 0;
pended->data = NULL;
pended->out = fifo->out;
len = fifo->in - fifo->out;
if (!len)
return -ENODATA;
if (fifo->open == fifo->open_limit)
return -EAGAIN;
n = len;
ofs = fifo->out % fifo->capacity;
l = fifo->capacity - ofs;
limit = min_t(unsigned, l, fifo->tx_limit);
if (n > limit) {
n = limit;
fifo->out += limit;
} else if (ofs + n > fifo->guard) {
fifo->out += l;
fifo->in = fifo->out;
} else {
fifo->out += round_up(n, fifo->align);
fifo->in = fifo->out;
}
df_trace("in: %u out: %u done: %u n: %d len: %u avail: %d", fifo->in,
fifo->out, fifo->done, n, len, fifo->avail);
pended->len = n;
pended->data = fifo->data + ofs;
pended->next = fifo->out;
list_add_tail(&pended->link, &fifo->pending);
++fifo->open;
if (FAIL(fifo, fifo->open > fifo->open_limit,
"past open limit:%d (limit:%d)",
fifo->open, fifo->open_limit))
return -ENXIO;
if (FAIL(fifo, fifo->out & (fifo->align - 1),
"fifo out unaligned:%u (align:%u)",
fifo->out, fifo->align))
return -ENXIO;
return len - n;
}
int dma_fifo_out_complete(struct dma_fifo *fifo, struct dma_pending *complete)
{
struct dma_pending *pending, *next, *tmp;
if (!fifo->data)
return -ENOENT;
if (fifo->corrupt)
return -ENXIO;
if (list_empty(&fifo->pending) && fifo->open == 0)
return -EINVAL;
if (FAIL(fifo, list_empty(&fifo->pending) != (fifo->open == 0),
"pending list disagrees with open count:%d",
fifo->open))
return -ENXIO;
tmp = complete->data;
*tmp = *complete;
list_replace(&complete->link, &tmp->link);
dp_mark_completed(tmp);
list_for_each_entry_safe(pending, next, &fifo->pending, link) {
if (!dp_is_completed(pending)) {
df_trace("still pending: saved out: %u len: %d",
pending->out, pending->len);
break;
}
if (FAIL(fifo, pending->out != fifo->done ||
addr_check(fifo->in, fifo->done, pending->next),
"in:%u out:%u done:%u saved:%u next:%u",
fifo->in, fifo->out, fifo->done, pending->out,
pending->next))
return -ENXIO;
list_del_init(&pending->link);
fifo->done = pending->next;
fifo->avail += pending->len;
--fifo->open;
df_trace("in: %u out: %u done: %u len: %u avail: %d", fifo->in,
fifo->out, fifo->done, pending->len, fifo->avail);
}
if (FAIL(fifo, fifo->open < 0, "open dma:%d < 0", fifo->open))
return -ENXIO;
if (FAIL(fifo, fifo->avail > fifo->size, "fifo avail:%d > size:%d",
fifo->avail, fifo->size))
return -ENXIO;
return 0;
}
