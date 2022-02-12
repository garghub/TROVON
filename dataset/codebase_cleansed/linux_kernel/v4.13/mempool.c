static void poison_error(mempool_t *pool, void *element, size_t size,
size_t byte)
{
const int nr = pool->curr_nr;
const int start = max_t(int, byte - (BITS_PER_LONG / 8), 0);
const int end = min_t(int, byte + (BITS_PER_LONG / 8), size);
int i;
pr_err("BUG: mempool element poison mismatch\n");
pr_err("Mempool %p size %zu\n", pool, size);
pr_err(" nr=%d @ %p: %s0x", nr, element, start > 0 ? "... " : "");
for (i = start; i < end; i++)
pr_cont("%x ", *(u8 *)(element + i));
pr_cont("%s\n", end < size ? "..." : "");
dump_stack();
}
static void __check_element(mempool_t *pool, void *element, size_t size)
{
u8 *obj = element;
size_t i;
for (i = 0; i < size; i++) {
u8 exp = (i < size - 1) ? POISON_FREE : POISON_END;
if (obj[i] != exp) {
poison_error(pool, element, size, i);
return;
}
}
memset(obj, POISON_INUSE, size);
}
static void check_element(mempool_t *pool, void *element)
{
if (pool->free == mempool_free_slab || pool->free == mempool_kfree)
__check_element(pool, element, ksize(element));
if (pool->free == mempool_free_pages) {
int order = (int)(long)pool->pool_data;
void *addr = kmap_atomic((struct page *)element);
__check_element(pool, addr, 1UL << (PAGE_SHIFT + order));
kunmap_atomic(addr);
}
}
static void __poison_element(void *element, size_t size)
{
u8 *obj = element;
memset(obj, POISON_FREE, size - 1);
obj[size - 1] = POISON_END;
}
static void poison_element(mempool_t *pool, void *element)
{
if (pool->alloc == mempool_alloc_slab || pool->alloc == mempool_kmalloc)
__poison_element(element, ksize(element));
if (pool->alloc == mempool_alloc_pages) {
int order = (int)(long)pool->pool_data;
void *addr = kmap_atomic((struct page *)element);
__poison_element(addr, 1UL << (PAGE_SHIFT + order));
kunmap_atomic(addr);
}
}
static inline void check_element(mempool_t *pool, void *element)
{
}
static inline void poison_element(mempool_t *pool, void *element)
{
}
static void kasan_poison_element(mempool_t *pool, void *element)
{
if (pool->alloc == mempool_alloc_slab || pool->alloc == mempool_kmalloc)
kasan_poison_kfree(element);
if (pool->alloc == mempool_alloc_pages)
kasan_free_pages(element, (unsigned long)pool->pool_data);
}
static void kasan_unpoison_element(mempool_t *pool, void *element, gfp_t flags)
{
if (pool->alloc == mempool_alloc_slab || pool->alloc == mempool_kmalloc)
kasan_unpoison_slab(element);
if (pool->alloc == mempool_alloc_pages)
kasan_alloc_pages(element, (unsigned long)pool->pool_data);
}
static void add_element(mempool_t *pool, void *element)
{
BUG_ON(pool->curr_nr >= pool->min_nr);
poison_element(pool, element);
kasan_poison_element(pool, element);
pool->elements[pool->curr_nr++] = element;
}
static void *remove_element(mempool_t *pool, gfp_t flags)
{
void *element = pool->elements[--pool->curr_nr];
BUG_ON(pool->curr_nr < 0);
kasan_unpoison_element(pool, element, flags);
check_element(pool, element);
return element;
}
void mempool_destroy(mempool_t *pool)
{
if (unlikely(!pool))
return;
while (pool->curr_nr) {
void *element = remove_element(pool, GFP_KERNEL);
pool->free(element, pool->pool_data);
}
kfree(pool->elements);
kfree(pool);
}
mempool_t *mempool_create(int min_nr, mempool_alloc_t *alloc_fn,
mempool_free_t *free_fn, void *pool_data)
{
return mempool_create_node(min_nr,alloc_fn,free_fn, pool_data,
GFP_KERNEL, NUMA_NO_NODE);
}
mempool_t *mempool_create_node(int min_nr, mempool_alloc_t *alloc_fn,
mempool_free_t *free_fn, void *pool_data,
gfp_t gfp_mask, int node_id)
{
mempool_t *pool;
pool = kzalloc_node(sizeof(*pool), gfp_mask, node_id);
if (!pool)
return NULL;
pool->elements = kmalloc_node(min_nr * sizeof(void *),
gfp_mask, node_id);
if (!pool->elements) {
kfree(pool);
return NULL;
}
spin_lock_init(&pool->lock);
pool->min_nr = min_nr;
pool->pool_data = pool_data;
init_waitqueue_head(&pool->wait);
pool->alloc = alloc_fn;
pool->free = free_fn;
while (pool->curr_nr < pool->min_nr) {
void *element;
element = pool->alloc(gfp_mask, pool->pool_data);
if (unlikely(!element)) {
mempool_destroy(pool);
return NULL;
}
add_element(pool, element);
}
return pool;
}
int mempool_resize(mempool_t *pool, int new_min_nr)
{
void *element;
void **new_elements;
unsigned long flags;
BUG_ON(new_min_nr <= 0);
might_sleep();
spin_lock_irqsave(&pool->lock, flags);
if (new_min_nr <= pool->min_nr) {
while (new_min_nr < pool->curr_nr) {
element = remove_element(pool, GFP_KERNEL);
spin_unlock_irqrestore(&pool->lock, flags);
pool->free(element, pool->pool_data);
spin_lock_irqsave(&pool->lock, flags);
}
pool->min_nr = new_min_nr;
goto out_unlock;
}
spin_unlock_irqrestore(&pool->lock, flags);
new_elements = kmalloc_array(new_min_nr, sizeof(*new_elements),
GFP_KERNEL);
if (!new_elements)
return -ENOMEM;
spin_lock_irqsave(&pool->lock, flags);
if (unlikely(new_min_nr <= pool->min_nr)) {
spin_unlock_irqrestore(&pool->lock, flags);
kfree(new_elements);
goto out;
}
memcpy(new_elements, pool->elements,
pool->curr_nr * sizeof(*new_elements));
kfree(pool->elements);
pool->elements = new_elements;
pool->min_nr = new_min_nr;
while (pool->curr_nr < pool->min_nr) {
spin_unlock_irqrestore(&pool->lock, flags);
element = pool->alloc(GFP_KERNEL, pool->pool_data);
if (!element)
goto out;
spin_lock_irqsave(&pool->lock, flags);
if (pool->curr_nr < pool->min_nr) {
add_element(pool, element);
} else {
spin_unlock_irqrestore(&pool->lock, flags);
pool->free(element, pool->pool_data);
goto out;
}
}
out_unlock:
spin_unlock_irqrestore(&pool->lock, flags);
out:
return 0;
}
void *mempool_alloc(mempool_t *pool, gfp_t gfp_mask)
{
void *element;
unsigned long flags;
wait_queue_entry_t wait;
gfp_t gfp_temp;
VM_WARN_ON_ONCE(gfp_mask & __GFP_ZERO);
might_sleep_if(gfp_mask & __GFP_DIRECT_RECLAIM);
gfp_mask |= __GFP_NOMEMALLOC;
gfp_mask |= __GFP_NORETRY;
gfp_mask |= __GFP_NOWARN;
gfp_temp = gfp_mask & ~(__GFP_DIRECT_RECLAIM|__GFP_IO);
repeat_alloc:
element = pool->alloc(gfp_temp, pool->pool_data);
if (likely(element != NULL))
return element;
spin_lock_irqsave(&pool->lock, flags);
if (likely(pool->curr_nr)) {
element = remove_element(pool, gfp_temp);
spin_unlock_irqrestore(&pool->lock, flags);
smp_wmb();
kmemleak_update_trace(element);
return element;
}
if (gfp_temp != gfp_mask) {
spin_unlock_irqrestore(&pool->lock, flags);
gfp_temp = gfp_mask;
goto repeat_alloc;
}
if (!(gfp_mask & __GFP_DIRECT_RECLAIM)) {
spin_unlock_irqrestore(&pool->lock, flags);
return NULL;
}
init_wait(&wait);
prepare_to_wait(&pool->wait, &wait, TASK_UNINTERRUPTIBLE);
spin_unlock_irqrestore(&pool->lock, flags);
io_schedule_timeout(5*HZ);
finish_wait(&pool->wait, &wait);
goto repeat_alloc;
}
void mempool_free(void *element, mempool_t *pool)
{
unsigned long flags;
if (unlikely(element == NULL))
return;
smp_rmb();
if (unlikely(pool->curr_nr < pool->min_nr)) {
spin_lock_irqsave(&pool->lock, flags);
if (likely(pool->curr_nr < pool->min_nr)) {
add_element(pool, element);
spin_unlock_irqrestore(&pool->lock, flags);
wake_up(&pool->wait);
return;
}
spin_unlock_irqrestore(&pool->lock, flags);
}
pool->free(element, pool->pool_data);
}
void *mempool_alloc_slab(gfp_t gfp_mask, void *pool_data)
{
struct kmem_cache *mem = pool_data;
VM_BUG_ON(mem->ctor);
return kmem_cache_alloc(mem, gfp_mask);
}
void mempool_free_slab(void *element, void *pool_data)
{
struct kmem_cache *mem = pool_data;
kmem_cache_free(mem, element);
}
void *mempool_kmalloc(gfp_t gfp_mask, void *pool_data)
{
size_t size = (size_t)pool_data;
return kmalloc(size, gfp_mask);
}
void mempool_kfree(void *element, void *pool_data)
{
kfree(element);
}
void *mempool_alloc_pages(gfp_t gfp_mask, void *pool_data)
{
int order = (int)(long)pool_data;
return alloc_pages(gfp_mask, order);
}
void mempool_free_pages(void *element, void *pool_data)
{
int order = (int)(long)pool_data;
__free_pages(element, order);
}
