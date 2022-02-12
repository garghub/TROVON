static int set_bits_ll(unsigned long *addr, unsigned long mask_to_set)
{
unsigned long val, nval;
nval = *addr;
do {
val = nval;
if (val & mask_to_set)
return -EBUSY;
cpu_relax();
} while ((nval = cmpxchg(addr, val, val | mask_to_set)) != val);
return 0;
}
static int clear_bits_ll(unsigned long *addr, unsigned long mask_to_clear)
{
unsigned long val, nval;
nval = *addr;
do {
val = nval;
if ((val & mask_to_clear) != mask_to_clear)
return -EBUSY;
cpu_relax();
} while ((nval = cmpxchg(addr, val, val & ~mask_to_clear)) != val);
return 0;
}
static int bitmap_set_ll(unsigned long *map, int start, int nr)
{
unsigned long *p = map + BIT_WORD(start);
const int size = start + nr;
int bits_to_set = BITS_PER_LONG - (start % BITS_PER_LONG);
unsigned long mask_to_set = BITMAP_FIRST_WORD_MASK(start);
while (nr - bits_to_set >= 0) {
if (set_bits_ll(p, mask_to_set))
return nr;
nr -= bits_to_set;
bits_to_set = BITS_PER_LONG;
mask_to_set = ~0UL;
p++;
}
if (nr) {
mask_to_set &= BITMAP_LAST_WORD_MASK(size);
if (set_bits_ll(p, mask_to_set))
return nr;
}
return 0;
}
static int bitmap_clear_ll(unsigned long *map, int start, int nr)
{
unsigned long *p = map + BIT_WORD(start);
const int size = start + nr;
int bits_to_clear = BITS_PER_LONG - (start % BITS_PER_LONG);
unsigned long mask_to_clear = BITMAP_FIRST_WORD_MASK(start);
while (nr - bits_to_clear >= 0) {
if (clear_bits_ll(p, mask_to_clear))
return nr;
nr -= bits_to_clear;
bits_to_clear = BITS_PER_LONG;
mask_to_clear = ~0UL;
p++;
}
if (nr) {
mask_to_clear &= BITMAP_LAST_WORD_MASK(size);
if (clear_bits_ll(p, mask_to_clear))
return nr;
}
return 0;
}
struct gen_pool *gen_pool_create(int min_alloc_order, int nid)
{
struct gen_pool *pool;
pool = kmalloc_node(sizeof(struct gen_pool), GFP_KERNEL, nid);
if (pool != NULL) {
spin_lock_init(&pool->lock);
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
chunk->phys_addr = phys;
chunk->start_addr = virt;
chunk->end_addr = virt + size;
atomic_set(&chunk->avail, size);
spin_lock(&pool->lock);
list_add_rcu(&chunk->next_chunk, &pool->chunks);
spin_unlock(&pool->lock);
return 0;
}
phys_addr_t gen_pool_virt_to_phys(struct gen_pool *pool, unsigned long addr)
{
struct gen_pool_chunk *chunk;
phys_addr_t paddr = -1;
rcu_read_lock();
list_for_each_entry_rcu(chunk, &pool->chunks, next_chunk) {
if (addr >= chunk->start_addr && addr < chunk->end_addr) {
paddr = chunk->phys_addr + (addr - chunk->start_addr);
break;
}
}
rcu_read_unlock();
return paddr;
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
struct gen_pool_chunk *chunk;
unsigned long addr = 0;
int order = pool->min_alloc_order;
int nbits, start_bit = 0, end_bit, remain;
#ifndef CONFIG_ARCH_HAVE_NMI_SAFE_CMPXCHG
BUG_ON(in_nmi());
#endif
if (size == 0)
return 0;
nbits = (size + (1UL << order) - 1) >> order;
rcu_read_lock();
list_for_each_entry_rcu(chunk, &pool->chunks, next_chunk) {
if (size > atomic_read(&chunk->avail))
continue;
end_bit = (chunk->end_addr - chunk->start_addr) >> order;
retry:
start_bit = bitmap_find_next_zero_area(chunk->bits, end_bit,
start_bit, nbits, 0);
if (start_bit >= end_bit)
continue;
remain = bitmap_set_ll(chunk->bits, start_bit, nbits);
if (remain) {
remain = bitmap_clear_ll(chunk->bits, start_bit,
nbits - remain);
BUG_ON(remain);
goto retry;
}
addr = chunk->start_addr + ((unsigned long)start_bit << order);
size = nbits << order;
atomic_sub(size, &chunk->avail);
break;
}
rcu_read_unlock();
return addr;
}
void gen_pool_free(struct gen_pool *pool, unsigned long addr, size_t size)
{
struct gen_pool_chunk *chunk;
int order = pool->min_alloc_order;
int start_bit, nbits, remain;
#ifndef CONFIG_ARCH_HAVE_NMI_SAFE_CMPXCHG
BUG_ON(in_nmi());
#endif
nbits = (size + (1UL << order) - 1) >> order;
rcu_read_lock();
list_for_each_entry_rcu(chunk, &pool->chunks, next_chunk) {
if (addr >= chunk->start_addr && addr < chunk->end_addr) {
BUG_ON(addr + size > chunk->end_addr);
start_bit = (addr - chunk->start_addr) >> order;
remain = bitmap_clear_ll(chunk->bits, start_bit, nbits);
BUG_ON(remain);
size = nbits << order;
atomic_add(size, &chunk->avail);
rcu_read_unlock();
return;
}
}
rcu_read_unlock();
BUG();
}
void gen_pool_for_each_chunk(struct gen_pool *pool,
void (*func)(struct gen_pool *pool, struct gen_pool_chunk *chunk, void *data),
void *data)
{
struct gen_pool_chunk *chunk;
rcu_read_lock();
list_for_each_entry_rcu(chunk, &(pool)->chunks, next_chunk)
func(pool, chunk, data);
rcu_read_unlock();
}
size_t gen_pool_avail(struct gen_pool *pool)
{
struct gen_pool_chunk *chunk;
size_t avail = 0;
rcu_read_lock();
list_for_each_entry_rcu(chunk, &pool->chunks, next_chunk)
avail += atomic_read(&chunk->avail);
rcu_read_unlock();
return avail;
}
size_t gen_pool_size(struct gen_pool *pool)
{
struct gen_pool_chunk *chunk;
size_t size = 0;
rcu_read_lock();
list_for_each_entry_rcu(chunk, &pool->chunks, next_chunk)
size += chunk->end_addr - chunk->start_addr;
rcu_read_unlock();
return size;
}
