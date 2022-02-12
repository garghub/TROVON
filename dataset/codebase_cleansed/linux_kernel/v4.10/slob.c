static inline int slob_page_free(struct page *sp)
{
return PageSlobFree(sp);
}
static void set_slob_page_free(struct page *sp, struct list_head *list)
{
list_add(&sp->lru, list);
__SetPageSlobFree(sp);
}
static inline void clear_slob_page_free(struct page *sp)
{
list_del(&sp->lru);
__ClearPageSlobFree(sp);
}
static void set_slob(slob_t *s, slobidx_t size, slob_t *next)
{
slob_t *base = (slob_t *)((unsigned long)s & PAGE_MASK);
slobidx_t offset = next - base;
if (size > 1) {
s[0].units = size;
s[1].units = offset;
} else
s[0].units = -offset;
}
static slobidx_t slob_units(slob_t *s)
{
if (s->units > 0)
return s->units;
return 1;
}
static slob_t *slob_next(slob_t *s)
{
slob_t *base = (slob_t *)((unsigned long)s & PAGE_MASK);
slobidx_t next;
if (s[0].units < 0)
next = -s[0].units;
else
next = s[1].units;
return base+next;
}
static int slob_last(slob_t *s)
{
return !((unsigned long)slob_next(s) & ~PAGE_MASK);
}
static void *slob_new_pages(gfp_t gfp, int order, int node)
{
void *page;
#ifdef CONFIG_NUMA
if (node != NUMA_NO_NODE)
page = __alloc_pages_node(node, gfp, order);
else
#endif
page = alloc_pages(gfp, order);
if (!page)
return NULL;
return page_address(page);
}
static void slob_free_pages(void *b, int order)
{
if (current->reclaim_state)
current->reclaim_state->reclaimed_slab += 1 << order;
free_pages((unsigned long)b, order);
}
static void *slob_page_alloc(struct page *sp, size_t size, int align)
{
slob_t *prev, *cur, *aligned = NULL;
int delta = 0, units = SLOB_UNITS(size);
for (prev = NULL, cur = sp->freelist; ; prev = cur, cur = slob_next(cur)) {
slobidx_t avail = slob_units(cur);
if (align) {
aligned = (slob_t *)ALIGN((unsigned long)cur, align);
delta = aligned - cur;
}
if (avail >= units + delta) {
slob_t *next;
if (delta) {
next = slob_next(cur);
set_slob(aligned, avail - delta, next);
set_slob(cur, delta, aligned);
prev = cur;
cur = aligned;
avail = slob_units(cur);
}
next = slob_next(cur);
if (avail == units) {
if (prev)
set_slob(prev, slob_units(prev), next);
else
sp->freelist = next;
} else {
if (prev)
set_slob(prev, slob_units(prev), cur + units);
else
sp->freelist = cur + units;
set_slob(cur + units, avail - units, next);
}
sp->units -= units;
if (!sp->units)
clear_slob_page_free(sp);
return cur;
}
if (slob_last(cur))
return NULL;
}
}
static void *slob_alloc(size_t size, gfp_t gfp, int align, int node)
{
struct page *sp;
struct list_head *prev;
struct list_head *slob_list;
slob_t *b = NULL;
unsigned long flags;
if (size < SLOB_BREAK1)
slob_list = &free_slob_small;
else if (size < SLOB_BREAK2)
slob_list = &free_slob_medium;
else
slob_list = &free_slob_large;
spin_lock_irqsave(&slob_lock, flags);
list_for_each_entry(sp, slob_list, lru) {
#ifdef CONFIG_NUMA
if (node != NUMA_NO_NODE && page_to_nid(sp) != node)
continue;
#endif
if (sp->units < SLOB_UNITS(size))
continue;
prev = sp->lru.prev;
b = slob_page_alloc(sp, size, align);
if (!b)
continue;
if (prev != slob_list->prev &&
slob_list->next != prev->next)
list_move_tail(slob_list, prev->next);
break;
}
spin_unlock_irqrestore(&slob_lock, flags);
if (!b) {
b = slob_new_pages(gfp & ~__GFP_ZERO, 0, node);
if (!b)
return NULL;
sp = virt_to_page(b);
__SetPageSlab(sp);
spin_lock_irqsave(&slob_lock, flags);
sp->units = SLOB_UNITS(PAGE_SIZE);
sp->freelist = b;
INIT_LIST_HEAD(&sp->lru);
set_slob(b, SLOB_UNITS(PAGE_SIZE), b + SLOB_UNITS(PAGE_SIZE));
set_slob_page_free(sp, slob_list);
b = slob_page_alloc(sp, size, align);
BUG_ON(!b);
spin_unlock_irqrestore(&slob_lock, flags);
}
if (unlikely((gfp & __GFP_ZERO) && b))
memset(b, 0, size);
return b;
}
static void slob_free(void *block, int size)
{
struct page *sp;
slob_t *prev, *next, *b = (slob_t *)block;
slobidx_t units;
unsigned long flags;
struct list_head *slob_list;
if (unlikely(ZERO_OR_NULL_PTR(block)))
return;
BUG_ON(!size);
sp = virt_to_page(block);
units = SLOB_UNITS(size);
spin_lock_irqsave(&slob_lock, flags);
if (sp->units + units == SLOB_UNITS(PAGE_SIZE)) {
if (slob_page_free(sp))
clear_slob_page_free(sp);
spin_unlock_irqrestore(&slob_lock, flags);
__ClearPageSlab(sp);
page_mapcount_reset(sp);
slob_free_pages(b, 0);
return;
}
if (!slob_page_free(sp)) {
sp->units = units;
sp->freelist = b;
set_slob(b, units,
(void *)((unsigned long)(b +
SLOB_UNITS(PAGE_SIZE)) & PAGE_MASK));
if (size < SLOB_BREAK1)
slob_list = &free_slob_small;
else if (size < SLOB_BREAK2)
slob_list = &free_slob_medium;
else
slob_list = &free_slob_large;
set_slob_page_free(sp, slob_list);
goto out;
}
sp->units += units;
if (b < (slob_t *)sp->freelist) {
if (b + units == sp->freelist) {
units += slob_units(sp->freelist);
sp->freelist = slob_next(sp->freelist);
}
set_slob(b, units, sp->freelist);
sp->freelist = b;
} else {
prev = sp->freelist;
next = slob_next(prev);
while (b > next) {
prev = next;
next = slob_next(prev);
}
if (!slob_last(prev) && b + units == next) {
units += slob_units(next);
set_slob(b, units, slob_next(next));
} else
set_slob(b, units, next);
if (prev + slob_units(prev) == b) {
units = slob_units(b) + slob_units(prev);
set_slob(prev, units, slob_next(b));
} else
set_slob(prev, slob_units(prev), b);
}
out:
spin_unlock_irqrestore(&slob_lock, flags);
}
static __always_inline void *
__do_kmalloc_node(size_t size, gfp_t gfp, int node, unsigned long caller)
{
unsigned int *m;
int align = max_t(size_t, ARCH_KMALLOC_MINALIGN, ARCH_SLAB_MINALIGN);
void *ret;
gfp &= gfp_allowed_mask;
lockdep_trace_alloc(gfp);
if (size < PAGE_SIZE - align) {
if (!size)
return ZERO_SIZE_PTR;
m = slob_alloc(size + align, gfp, align, node);
if (!m)
return NULL;
*m = size;
ret = (void *)m + align;
trace_kmalloc_node(caller, ret,
size, size + align, gfp, node);
} else {
unsigned int order = get_order(size);
if (likely(order))
gfp |= __GFP_COMP;
ret = slob_new_pages(gfp, order, node);
trace_kmalloc_node(caller, ret,
size, PAGE_SIZE << order, gfp, node);
}
kmemleak_alloc(ret, size, 1, gfp);
return ret;
}
void *__kmalloc(size_t size, gfp_t gfp)
{
return __do_kmalloc_node(size, gfp, NUMA_NO_NODE, _RET_IP_);
}
void *__kmalloc_track_caller(size_t size, gfp_t gfp, unsigned long caller)
{
return __do_kmalloc_node(size, gfp, NUMA_NO_NODE, caller);
}
void *__kmalloc_node_track_caller(size_t size, gfp_t gfp,
int node, unsigned long caller)
{
return __do_kmalloc_node(size, gfp, node, caller);
}
void kfree(const void *block)
{
struct page *sp;
trace_kfree(_RET_IP_, block);
if (unlikely(ZERO_OR_NULL_PTR(block)))
return;
kmemleak_free(block);
sp = virt_to_page(block);
if (PageSlab(sp)) {
int align = max_t(size_t, ARCH_KMALLOC_MINALIGN, ARCH_SLAB_MINALIGN);
unsigned int *m = (unsigned int *)(block - align);
slob_free(m, *m + align);
} else
__free_pages(sp, compound_order(sp));
}
size_t ksize(const void *block)
{
struct page *sp;
int align;
unsigned int *m;
BUG_ON(!block);
if (unlikely(block == ZERO_SIZE_PTR))
return 0;
sp = virt_to_page(block);
if (unlikely(!PageSlab(sp)))
return PAGE_SIZE << compound_order(sp);
align = max_t(size_t, ARCH_KMALLOC_MINALIGN, ARCH_SLAB_MINALIGN);
m = (unsigned int *)(block - align);
return SLOB_UNITS(*m) * SLOB_UNIT;
}
int __kmem_cache_create(struct kmem_cache *c, unsigned long flags)
{
if (flags & SLAB_DESTROY_BY_RCU) {
c->size += sizeof(struct slob_rcu);
}
c->flags = flags;
return 0;
}
static void *slob_alloc_node(struct kmem_cache *c, gfp_t flags, int node)
{
void *b;
flags &= gfp_allowed_mask;
lockdep_trace_alloc(flags);
if (c->size < PAGE_SIZE) {
b = slob_alloc(c->size, flags, c->align, node);
trace_kmem_cache_alloc_node(_RET_IP_, b, c->object_size,
SLOB_UNITS(c->size) * SLOB_UNIT,
flags, node);
} else {
b = slob_new_pages(flags, get_order(c->size), node);
trace_kmem_cache_alloc_node(_RET_IP_, b, c->object_size,
PAGE_SIZE << get_order(c->size),
flags, node);
}
if (b && c->ctor)
c->ctor(b);
kmemleak_alloc_recursive(b, c->size, 1, c->flags, flags);
return b;
}
void *kmem_cache_alloc(struct kmem_cache *cachep, gfp_t flags)
{
return slob_alloc_node(cachep, flags, NUMA_NO_NODE);
}
void *__kmalloc_node(size_t size, gfp_t gfp, int node)
{
return __do_kmalloc_node(size, gfp, node, _RET_IP_);
}
void *kmem_cache_alloc_node(struct kmem_cache *cachep, gfp_t gfp, int node)
{
return slob_alloc_node(cachep, gfp, node);
}
static void __kmem_cache_free(void *b, int size)
{
if (size < PAGE_SIZE)
slob_free(b, size);
else
slob_free_pages(b, get_order(size));
}
static void kmem_rcu_free(struct rcu_head *head)
{
struct slob_rcu *slob_rcu = (struct slob_rcu *)head;
void *b = (void *)slob_rcu - (slob_rcu->size - sizeof(struct slob_rcu));
__kmem_cache_free(b, slob_rcu->size);
}
void kmem_cache_free(struct kmem_cache *c, void *b)
{
kmemleak_free_recursive(b, c->flags);
if (unlikely(c->flags & SLAB_DESTROY_BY_RCU)) {
struct slob_rcu *slob_rcu;
slob_rcu = b + (c->size - sizeof(struct slob_rcu));
slob_rcu->size = c->size;
call_rcu(&slob_rcu->head, kmem_rcu_free);
} else {
__kmem_cache_free(b, c->size);
}
trace_kmem_cache_free(_RET_IP_, b);
}
void kmem_cache_free_bulk(struct kmem_cache *s, size_t size, void **p)
{
__kmem_cache_free_bulk(s, size, p);
}
int kmem_cache_alloc_bulk(struct kmem_cache *s, gfp_t flags, size_t size,
void **p)
{
return __kmem_cache_alloc_bulk(s, flags, size, p);
}
int __kmem_cache_shutdown(struct kmem_cache *c)
{
return 0;
}
void __kmem_cache_release(struct kmem_cache *c)
{
}
int __kmem_cache_shrink(struct kmem_cache *d)
{
return 0;
}
void __init kmem_cache_init(void)
{
kmem_cache = &kmem_cache_boot;
slab_state = UP;
}
void __init kmem_cache_init_late(void)
{
slab_state = FULL;
}
