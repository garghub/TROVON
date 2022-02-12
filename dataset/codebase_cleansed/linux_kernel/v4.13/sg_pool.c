static inline unsigned int sg_pool_index(unsigned short nents)
{
unsigned int index;
BUG_ON(nents > SG_CHUNK_SIZE);
if (nents <= 8)
index = 0;
else
index = get_count_order(nents) - 3;
return index;
}
static void sg_pool_free(struct scatterlist *sgl, unsigned int nents)
{
struct sg_pool *sgp;
sgp = sg_pools + sg_pool_index(nents);
mempool_free(sgl, sgp->pool);
}
static struct scatterlist *sg_pool_alloc(unsigned int nents, gfp_t gfp_mask)
{
struct sg_pool *sgp;
sgp = sg_pools + sg_pool_index(nents);
return mempool_alloc(sgp->pool, gfp_mask);
}
void sg_free_table_chained(struct sg_table *table, bool first_chunk)
{
if (first_chunk && table->orig_nents <= SG_CHUNK_SIZE)
return;
__sg_free_table(table, SG_CHUNK_SIZE, first_chunk, sg_pool_free);
}
int sg_alloc_table_chained(struct sg_table *table, int nents,
struct scatterlist *first_chunk)
{
int ret;
BUG_ON(!nents);
if (first_chunk) {
if (nents <= SG_CHUNK_SIZE) {
table->nents = table->orig_nents = nents;
sg_init_table(table->sgl, nents);
return 0;
}
}
ret = __sg_alloc_table(table, nents, SG_CHUNK_SIZE,
first_chunk, GFP_ATOMIC, sg_pool_alloc);
if (unlikely(ret))
sg_free_table_chained(table, (bool)first_chunk);
return ret;
}
static __init int sg_pool_init(void)
{
int i;
for (i = 0; i < SG_MEMPOOL_NR; i++) {
struct sg_pool *sgp = sg_pools + i;
int size = sgp->size * sizeof(struct scatterlist);
sgp->slab = kmem_cache_create(sgp->name, size, 0,
SLAB_HWCACHE_ALIGN, NULL);
if (!sgp->slab) {
printk(KERN_ERR "SG_POOL: can't init sg slab %s\n",
sgp->name);
goto cleanup_sdb;
}
sgp->pool = mempool_create_slab_pool(SG_MEMPOOL_SIZE,
sgp->slab);
if (!sgp->pool) {
printk(KERN_ERR "SG_POOL: can't init sg mempool %s\n",
sgp->name);
goto cleanup_sdb;
}
}
return 0;
cleanup_sdb:
for (i = 0; i < SG_MEMPOOL_NR; i++) {
struct sg_pool *sgp = sg_pools + i;
if (sgp->pool)
mempool_destroy(sgp->pool);
if (sgp->slab)
kmem_cache_destroy(sgp->slab);
}
return -ENOMEM;
}
static __exit void sg_pool_exit(void)
{
int i;
for (i = 0; i < SG_MEMPOOL_NR; i++) {
struct sg_pool *sgp = sg_pools + i;
mempool_destroy(sgp->pool);
kmem_cache_destroy(sgp->slab);
}
}
