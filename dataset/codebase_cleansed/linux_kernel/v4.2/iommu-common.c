static inline bool need_flush(struct iommu_map_table *iommu)
{
return (iommu->lazy_flush != NULL &&
(iommu->flags & IOMMU_NEED_FLUSH) != 0);
}
static inline void set_flush(struct iommu_map_table *iommu)
{
iommu->flags |= IOMMU_NEED_FLUSH;
}
static inline void clear_flush(struct iommu_map_table *iommu)
{
iommu->flags &= ~IOMMU_NEED_FLUSH;
}
static void setup_iommu_pool_hash(void)
{
unsigned int i;
static bool do_once;
if (do_once)
return;
do_once = true;
for_each_possible_cpu(i)
per_cpu(iommu_hash_common, i) = hash_32(i, IOMMU_POOL_HASHBITS);
}
void iommu_tbl_pool_init(struct iommu_map_table *iommu,
unsigned long num_entries,
u32 table_shift,
void (*lazy_flush)(struct iommu_map_table *),
bool large_pool, u32 npools,
bool skip_span_boundary_check)
{
unsigned int start, i;
struct iommu_pool *p = &(iommu->large_pool);
setup_iommu_pool_hash();
if (npools == 0)
iommu->nr_pools = IOMMU_NR_POOLS;
else
iommu->nr_pools = npools;
BUG_ON(npools > IOMMU_NR_POOLS);
iommu->table_shift = table_shift;
iommu->lazy_flush = lazy_flush;
start = 0;
if (skip_span_boundary_check)
iommu->flags |= IOMMU_NO_SPAN_BOUND;
if (large_pool)
iommu->flags |= IOMMU_HAS_LARGE_POOL;
if (!large_pool)
iommu->poolsize = num_entries/iommu->nr_pools;
else
iommu->poolsize = (num_entries * 3 / 4)/iommu->nr_pools;
for (i = 0; i < iommu->nr_pools; i++) {
spin_lock_init(&(iommu->pools[i].lock));
iommu->pools[i].start = start;
iommu->pools[i].hint = start;
start += iommu->poolsize;
iommu->pools[i].end = start - 1;
}
if (!large_pool)
return;
spin_lock_init(&(p->lock));
p->start = start;
p->hint = p->start;
p->end = num_entries;
}
unsigned long iommu_tbl_range_alloc(struct device *dev,
struct iommu_map_table *iommu,
unsigned long npages,
unsigned long *handle,
unsigned long mask,
unsigned int align_order)
{
unsigned int pool_hash = __this_cpu_read(iommu_hash_common);
unsigned long n, end, start, limit, boundary_size;
struct iommu_pool *pool;
int pass = 0;
unsigned int pool_nr;
unsigned int npools = iommu->nr_pools;
unsigned long flags;
bool large_pool = ((iommu->flags & IOMMU_HAS_LARGE_POOL) != 0);
bool largealloc = (large_pool && npages > iommu_large_alloc);
unsigned long shift;
unsigned long align_mask = 0;
if (align_order > 0)
align_mask = ~0ul >> (BITS_PER_LONG - align_order);
if (unlikely(npages == 0)) {
WARN_ON_ONCE(1);
return DMA_ERROR_CODE;
}
if (largealloc) {
pool = &(iommu->large_pool);
pool_nr = 0;
} else {
pool_nr = pool_hash & (npools - 1);
pool = &(iommu->pools[pool_nr]);
}
spin_lock_irqsave(&pool->lock, flags);
again:
if (pass == 0 && handle && *handle &&
(*handle >= pool->start) && (*handle < pool->end))
start = *handle;
else
start = pool->hint;
limit = pool->end;
if (start >= limit)
start = pool->start;
shift = iommu->table_map_base >> iommu->table_shift;
if (limit + shift > mask) {
limit = mask - shift + 1;
if ((start & mask) >= limit || pass > 0) {
spin_unlock(&(pool->lock));
pool = &(iommu->pools[0]);
spin_lock(&(pool->lock));
start = pool->start;
} else {
start &= mask;
}
}
if (dev)
boundary_size = ALIGN(dma_get_seg_boundary(dev) + 1,
1 << iommu->table_shift);
else
boundary_size = ALIGN(1ULL << 32, 1 << iommu->table_shift);
boundary_size = boundary_size >> iommu->table_shift;
if ((iommu->flags & IOMMU_NO_SPAN_BOUND) != 0) {
shift = 0;
boundary_size = iommu->poolsize * iommu->nr_pools;
}
n = iommu_area_alloc(iommu->map, limit, start, npages, shift,
boundary_size, align_mask);
if (n == -1) {
if (likely(pass == 0)) {
pool->hint = pool->start;
set_flush(iommu);
pass++;
goto again;
} else if (!largealloc && pass <= iommu->nr_pools) {
spin_unlock(&(pool->lock));
pool_nr = (pool_nr + 1) & (iommu->nr_pools - 1);
pool = &(iommu->pools[pool_nr]);
spin_lock(&(pool->lock));
pool->hint = pool->start;
set_flush(iommu);
pass++;
goto again;
} else {
n = DMA_ERROR_CODE;
goto bail;
}
}
if (n < pool->hint || need_flush(iommu)) {
clear_flush(iommu);
iommu->lazy_flush(iommu);
}
end = n + npages;
pool->hint = end;
if (handle)
*handle = end;
bail:
spin_unlock_irqrestore(&(pool->lock), flags);
return n;
}
static struct iommu_pool *get_pool(struct iommu_map_table *tbl,
unsigned long entry)
{
struct iommu_pool *p;
unsigned long largepool_start = tbl->large_pool.start;
bool large_pool = ((tbl->flags & IOMMU_HAS_LARGE_POOL) != 0);
if (large_pool && entry >= largepool_start) {
p = &tbl->large_pool;
} else {
unsigned int pool_nr = entry / tbl->poolsize;
BUG_ON(pool_nr >= tbl->nr_pools);
p = &tbl->pools[pool_nr];
}
return p;
}
void iommu_tbl_range_free(struct iommu_map_table *iommu, u64 dma_addr,
unsigned long npages, unsigned long entry)
{
struct iommu_pool *pool;
unsigned long flags;
unsigned long shift = iommu->table_shift;
if (entry == DMA_ERROR_CODE)
entry = (dma_addr - iommu->table_map_base) >> shift;
pool = get_pool(iommu, entry);
spin_lock_irqsave(&(pool->lock), flags);
bitmap_clear(iommu->map, entry, npages);
spin_unlock_irqrestore(&(pool->lock), flags);
}
