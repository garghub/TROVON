struct gen_pool *gen_pool_create(int min_alloc_order, int nid)
{
struct gen_pool *pool;
pool = kmalloc_node(sizeof(struct gen_pool), GFP_KERNEL, nid);
if (pool != NULL) {
rwlock_init(&pool->lock);
INIT_LIST_HEAD(&pool->chunks);
pool->min_alloc_order = min_alloc_order;
}
return pool;
}
int gen_pool_add_virt(struct gen_pool *pool, unsigned long virt, phys_addr_t phys,
size_t size, int nid)
{
struct gen_pool_chunk *chunk;
int nbits = size >> pool->min_alloc_order;
int nbytes = sizeof(struct gen_pool_chunk) +
(nbits + BITS_PER_BYTE - 1) / BITS_PER_BYTE;
chunk = kmalloc_node(nbytes, GFP_KERNEL | __GFP_ZERO, nid);
if (unlikely(chunk == NULL))
return -ENOMEM;
spin_lock_init(&chunk->lock);
chunk->phys_addr = phys;
chunk->start_addr = virt;
chunk->end_addr = virt + size;
write_lock(&pool->lock);
list_add(&chunk->next_chunk, &pool->chunks);
write_unlock(&pool->lock);
return 0;
}
phys_addr_t gen_pool_virt_to_phys(struct gen_pool *pool, unsigned long addr)
{
struct list_head *_chunk;
struct gen_pool_chunk *chunk;
read_lock(&pool->lock);
list_for_each(_chunk, &pool->chunks) {
chunk = list_entry(_chunk, struct gen_pool_chunk, next_chunk);
if (addr >= chunk->start_addr && addr < chunk->end_addr)
return chunk->phys_addr + addr - chunk->start_addr;
}
read_unlock(&pool->lock);
return -1;
}
void gen_pool_destroy(struct gen_pool *pool)
{
struct list_head *_chunk, *_next_chunk;
struct gen_pool_chunk *chunk;
int order = pool->min_alloc_order;
int bit, end_bit;
list_for_each_safe(_chunk, _next_chunk, &pool->chunks) {
chunk = list_entry(_chunk, struct gen_pool_chunk, next_chunk);
list_del(&chunk->next_chunk);
end_bit = (chunk->end_addr - chunk->start_addr) >> order;
bit = find_next_bit(chunk->bits, end_bit, 0);
BUG_ON(bit < end_bit);
kfree(chunk);
}
kfree(pool);
return;
}
unsigned long gen_pool_alloc(struct gen_pool *pool, size_t size)
{
struct list_head *_chunk;
struct gen_pool_chunk *chunk;
unsigned long addr, flags;
int order = pool->min_alloc_order;
int nbits, start_bit, end_bit;
if (size == 0)
return 0;
nbits = (size + (1UL << order) - 1) >> order;
read_lock(&pool->lock);
list_for_each(_chunk, &pool->chunks) {
chunk = list_entry(_chunk, struct gen_pool_chunk, next_chunk);
end_bit = (chunk->end_addr - chunk->start_addr) >> order;
spin_lock_irqsave(&chunk->lock, flags);
start_bit = bitmap_find_next_zero_area(chunk->bits, end_bit, 0,
nbits, 0);
if (start_bit >= end_bit) {
spin_unlock_irqrestore(&chunk->lock, flags);
continue;
}
addr = chunk->start_addr + ((unsigned long)start_bit << order);
bitmap_set(chunk->bits, start_bit, nbits);
spin_unlock_irqrestore(&chunk->lock, flags);
read_unlock(&pool->lock);
return addr;
}
read_unlock(&pool->lock);
return 0;
}
void gen_pool_free(struct gen_pool *pool, unsigned long addr, size_t size)
{
struct list_head *_chunk;
struct gen_pool_chunk *chunk;
unsigned long flags;
int order = pool->min_alloc_order;
int bit, nbits;
nbits = (size + (1UL << order) - 1) >> order;
read_lock(&pool->lock);
list_for_each(_chunk, &pool->chunks) {
chunk = list_entry(_chunk, struct gen_pool_chunk, next_chunk);
if (addr >= chunk->start_addr && addr < chunk->end_addr) {
BUG_ON(addr + size > chunk->end_addr);
spin_lock_irqsave(&chunk->lock, flags);
bit = (addr - chunk->start_addr) >> order;
while (nbits--)
__clear_bit(bit++, chunk->bits);
spin_unlock_irqrestore(&chunk->lock, flags);
break;
}
}
BUG_ON(nbits > 0);
read_unlock(&pool->lock);
}
