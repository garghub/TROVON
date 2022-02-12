static inline void
region_put(struct nouveau_mm *rmm, struct nouveau_mm_node *a)
{
list_del(&a->nl_entry);
list_del(&a->fl_entry);
kfree(a);
}
static struct nouveau_mm_node *
region_split(struct nouveau_mm *rmm, struct nouveau_mm_node *a, u32 size)
{
struct nouveau_mm_node *b;
if (a->length == size)
return a;
b = kmalloc(sizeof(*b), GFP_KERNEL);
if (unlikely(b == NULL))
return NULL;
b->offset = a->offset;
b->length = size;
b->type = a->type;
a->offset += size;
a->length -= size;
list_add_tail(&b->nl_entry, &a->nl_entry);
if (b->type == 0)
list_add_tail(&b->fl_entry, &a->fl_entry);
return b;
}
void
nouveau_mm_put(struct nouveau_mm *rmm, struct nouveau_mm_node *this)
{
struct nouveau_mm_node *prev = node(this, prev);
struct nouveau_mm_node *next = node(this, next);
list_add(&this->fl_entry, &rmm->free);
this->type = 0;
if (prev && prev->type == 0) {
prev->length += this->length;
region_put(rmm, this);
this = prev;
}
if (next && next->type == 0) {
next->offset = this->offset;
next->length += this->length;
region_put(rmm, this);
}
}
int
nouveau_mm_get(struct nouveau_mm *rmm, int type, u32 size, u32 size_nc,
u32 align, struct nouveau_mm_node **pnode)
{
struct nouveau_mm_node *prev, *this, *next;
u32 min = size_nc ? size_nc : size;
u32 align_mask = align - 1;
u32 splitoff;
u32 s, e;
list_for_each_entry(this, &rmm->free, fl_entry) {
e = this->offset + this->length;
s = this->offset;
prev = node(this, prev);
if (prev && prev->type != type)
s = roundup(s, rmm->block_size);
next = node(this, next);
if (next && next->type != type)
e = rounddown(e, rmm->block_size);
s = (s + align_mask) & ~align_mask;
e &= ~align_mask;
if (s > e || e - s < min)
continue;
splitoff = s - this->offset;
if (splitoff && !region_split(rmm, this, splitoff))
return -ENOMEM;
this = region_split(rmm, this, min(size, e - s));
if (!this)
return -ENOMEM;
this->type = type;
list_del(&this->fl_entry);
*pnode = this;
return 0;
}
return -ENOSPC;
}
int
nouveau_mm_init(struct nouveau_mm **prmm, u32 offset, u32 length, u32 block)
{
struct nouveau_mm *rmm;
struct nouveau_mm_node *heap;
heap = kzalloc(sizeof(*heap), GFP_KERNEL);
if (!heap)
return -ENOMEM;
heap->offset = roundup(offset, block);
heap->length = rounddown(offset + length, block) - heap->offset;
rmm = kzalloc(sizeof(*rmm), GFP_KERNEL);
if (!rmm) {
kfree(heap);
return -ENOMEM;
}
rmm->block_size = block;
mutex_init(&rmm->mutex);
INIT_LIST_HEAD(&rmm->nodes);
INIT_LIST_HEAD(&rmm->free);
list_add(&heap->nl_entry, &rmm->nodes);
list_add(&heap->fl_entry, &rmm->free);
*prmm = rmm;
return 0;
}
int
nouveau_mm_fini(struct nouveau_mm **prmm)
{
struct nouveau_mm *rmm = *prmm;
struct nouveau_mm_node *heap =
list_first_entry(&rmm->nodes, struct nouveau_mm_node, nl_entry);
if (!list_is_singular(&rmm->nodes))
return -EBUSY;
kfree(heap);
kfree(rmm);
*prmm = NULL;
return 0;
}
