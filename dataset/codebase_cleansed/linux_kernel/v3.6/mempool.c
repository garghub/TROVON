static void add_element(mempool_t *pool, void *element)
{
BUG_ON(pool->curr_nr >= pool->min_nr);
pool->elements[pool->curr_nr++] = element;
}
static void *remove_element(mempool_t *pool)
{
BUG_ON(pool->curr_nr <= 0);
return pool->elements[--pool->curr_nr];
}
void mempool_destroy(mempool_t *pool)
{
while (pool->curr_nr) {
void *element = remove_element(pool);
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
pool = kmalloc_node(sizeof(*pool), gfp_mask | __GFP_ZERO, node_id);
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
int mempool_resize(mempool_t *pool, int new_min_nr, gfp_t gfp_mask)
{
void *element;
void **new_elements;
unsigned long flags;
BUG_ON(new_min_nr <= 0);
spin_lock_irqsave(&pool->lock, flags);
if (new_min_nr <= pool->min_nr) {
while (new_min_nr < pool->curr_nr) {
element = remove_element(pool);
spin_unlock_irqrestore(&pool->lock, flags);
pool->free(element, pool->pool_data);
spin_lock_irqsave(&pool->lock, flags);
}
pool->min_nr = new_min_nr;
goto out_unlock;
}
spin_unlock_irqrestore(&pool->lock, flags);
new_elements = kmalloc(new_min_nr * sizeof(*new_elements), gfp_mask);
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
element = pool->alloc(gfp_mask, pool->pool_data);
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
void * mempool_alloc(mempool_t *pool, gfp_t gfp_mask)
{
void *element;
unsigned long flags;
wait_queue_t wait;
gfp_t gfp_temp;
might_sleep_if(gfp_mask & __GFP_WAIT);
gfp_mask |= __GFP_NOMEMALLOC;
gfp_mask |= __GFP_NORETRY;
gfp_mask |= __GFP_NOWARN;
gfp_temp = gfp_mask & ~(__GFP_WAIT|__GFP_IO);
repeat_alloc:
element = pool->alloc(gfp_temp, pool->pool_data);
if (likely(element != NULL))
return element;
spin_lock_irqsave(&pool->lock, flags);
if (likely(pool->curr_nr)) {
element = remove_element(pool);
spin_unlock_irqrestore(&pool->lock, flags);
smp_wmb();
return element;
}
if (gfp_temp != gfp_mask) {
spin_unlock_irqrestore(&pool->lock, flags);
gfp_temp = gfp_mask;
goto repeat_alloc;
}
if (!(gfp_mask & __GFP_WAIT)) {
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
if (pool->curr_nr < pool->min_nr) {
spin_lock_irqsave(&pool->lock, flags);
if (pool->curr_nr < pool->min_nr) {
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
