static inline size_t chunk_size(const struct gen_pool_chunk *chunk)
{
return chunk->end_addr - chunk->start_addr + 1;
}
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
pool->algo = gen_pool_first_fit;
pool->data = NULL;
}
return pool;
}
int gen_pool_add_virt(struct gen_pool *pool, unsigned long virt, phys_addr_t phys,
size_t size, int nid)
{
struct gen_pool_chunk *chunk;
int nbits = size >> pool->min_alloc_order;
int nbytes = sizeof(struct gen_pool_chunk) +
BITS_TO_LONGS(nbits) * sizeof(long);
chunk = kzalloc_node(nbytes, GFP_KERNEL, nid);
if (unlikely(chunk == NULL))
return -ENOMEM;
chunk->phys_addr = phys;
chunk->start_addr = virt;
chunk->end_addr = virt + size - 1;
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
if (addr >= chunk->start_addr && addr <= chunk->end_addr) {
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
end_bit = chunk_size(chunk) >> order;
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
end_bit = chunk_size(chunk) >> order;
retry:
start_bit = pool->algo(chunk->bits, end_bit, start_bit, nbits,
pool->data);
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
void *gen_pool_dma_alloc(struct gen_pool *pool, size_t size, dma_addr_t *dma)
{
unsigned long vaddr;
if (!pool)
return NULL;
vaddr = gen_pool_alloc(pool, size);
if (!vaddr)
return NULL;
*dma = gen_pool_virt_to_phys(pool, vaddr);
return (void *)vaddr;
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
if (addr >= chunk->start_addr && addr <= chunk->end_addr) {
BUG_ON(addr + size - 1 > chunk->end_addr);
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
size += chunk_size(chunk);
rcu_read_unlock();
return size;
}
void gen_pool_set_algo(struct gen_pool *pool, genpool_algo_t algo, void *data)
{
rcu_read_lock();
pool->algo = algo;
if (!pool->algo)
pool->algo = gen_pool_first_fit;
pool->data = data;
rcu_read_unlock();
}
unsigned long gen_pool_first_fit(unsigned long *map, unsigned long size,
unsigned long start, unsigned int nr, void *data)
{
return bitmap_find_next_zero_area(map, size, start, nr, 0);
}
unsigned long gen_pool_best_fit(unsigned long *map, unsigned long size,
unsigned long start, unsigned int nr, void *data)
{
unsigned long start_bit = size;
unsigned long len = size + 1;
unsigned long index;
index = bitmap_find_next_zero_area(map, size, start, nr, 0);
while (index < size) {
int next_bit = find_next_bit(map, size, index + nr);
if ((next_bit - index) < len) {
len = next_bit - index;
start_bit = index;
if (len == nr)
return start_bit;
}
index = bitmap_find_next_zero_area(map, size,
next_bit + 1, nr, 0);
}
return start_bit;
}
static void devm_gen_pool_release(struct device *dev, void *res)
{
gen_pool_destroy(*(struct gen_pool **)res);
}
struct gen_pool *devm_gen_pool_create(struct device *dev, int min_alloc_order,
int nid)
{
struct gen_pool **ptr, *pool;
ptr = devres_alloc(devm_gen_pool_release, sizeof(*ptr), GFP_KERNEL);
pool = gen_pool_create(min_alloc_order, nid);
if (pool) {
*ptr = pool;
devres_add(dev, ptr);
} else {
devres_free(ptr);
}
return pool;
}
struct gen_pool *dev_get_gen_pool(struct device *dev)
{
struct gen_pool **p = devres_find(dev, devm_gen_pool_release, NULL,
NULL);
if (!p)
return NULL;
return *p;
}
struct gen_pool *of_get_named_gen_pool(struct device_node *np,
const char *propname, int index)
{
struct platform_device *pdev;
struct device_node *np_pool;
np_pool = of_parse_phandle(np, propname, index);
if (!np_pool)
return NULL;
pdev = of_find_device_by_node(np_pool);
if (!pdev)
return NULL;
return dev_get_gen_pool(&pdev->dev);
}
