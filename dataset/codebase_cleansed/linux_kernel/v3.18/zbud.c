static int zbud_zpool_evict(struct zbud_pool *pool, unsigned long handle)
{
return zpool_evict(pool, handle);
}
static void *zbud_zpool_create(gfp_t gfp, struct zpool_ops *zpool_ops)
{
return zbud_create_pool(gfp, &zbud_zpool_ops);
}
static void zbud_zpool_destroy(void *pool)
{
zbud_destroy_pool(pool);
}
static int zbud_zpool_malloc(void *pool, size_t size, gfp_t gfp,
unsigned long *handle)
{
return zbud_alloc(pool, size, gfp, handle);
}
static void zbud_zpool_free(void *pool, unsigned long handle)
{
zbud_free(pool, handle);
}
static int zbud_zpool_shrink(void *pool, unsigned int pages,
unsigned int *reclaimed)
{
unsigned int total = 0;
int ret = -EINVAL;
while (total < pages) {
ret = zbud_reclaim_page(pool, 8);
if (ret < 0)
break;
total++;
}
if (reclaimed)
*reclaimed = total;
return ret;
}
static void *zbud_zpool_map(void *pool, unsigned long handle,
enum zpool_mapmode mm)
{
return zbud_map(pool, handle);
}
static void zbud_zpool_unmap(void *pool, unsigned long handle)
{
zbud_unmap(pool, handle);
}
static u64 zbud_zpool_total_size(void *pool)
{
return zbud_get_pool_size(pool) * PAGE_SIZE;
}
static int size_to_chunks(size_t size)
{
return (size + CHUNK_SIZE - 1) >> CHUNK_SHIFT;
}
static struct zbud_header *init_zbud_page(struct page *page)
{
struct zbud_header *zhdr = page_address(page);
zhdr->first_chunks = 0;
zhdr->last_chunks = 0;
INIT_LIST_HEAD(&zhdr->buddy);
INIT_LIST_HEAD(&zhdr->lru);
zhdr->under_reclaim = 0;
return zhdr;
}
static void free_zbud_page(struct zbud_header *zhdr)
{
__free_page(virt_to_page(zhdr));
}
static unsigned long encode_handle(struct zbud_header *zhdr, enum buddy bud)
{
unsigned long handle;
handle = (unsigned long)zhdr;
if (bud == FIRST)
handle += ZHDR_SIZE_ALIGNED;
else
handle += PAGE_SIZE - (zhdr->last_chunks << CHUNK_SHIFT);
return handle;
}
static struct zbud_header *handle_to_zbud_header(unsigned long handle)
{
return (struct zbud_header *)(handle & PAGE_MASK);
}
static int num_free_chunks(struct zbud_header *zhdr)
{
return NCHUNKS - zhdr->first_chunks - zhdr->last_chunks;
}
struct zbud_pool *zbud_create_pool(gfp_t gfp, struct zbud_ops *ops)
{
struct zbud_pool *pool;
int i;
pool = kmalloc(sizeof(struct zbud_pool), gfp);
if (!pool)
return NULL;
spin_lock_init(&pool->lock);
for_each_unbuddied_list(i, 0)
INIT_LIST_HEAD(&pool->unbuddied[i]);
INIT_LIST_HEAD(&pool->buddied);
INIT_LIST_HEAD(&pool->lru);
pool->pages_nr = 0;
pool->ops = ops;
return pool;
}
void zbud_destroy_pool(struct zbud_pool *pool)
{
kfree(pool);
}
int zbud_alloc(struct zbud_pool *pool, size_t size, gfp_t gfp,
unsigned long *handle)
{
int chunks, i, freechunks;
struct zbud_header *zhdr = NULL;
enum buddy bud;
struct page *page;
if (!size || (gfp & __GFP_HIGHMEM))
return -EINVAL;
if (size > PAGE_SIZE - ZHDR_SIZE_ALIGNED - CHUNK_SIZE)
return -ENOSPC;
chunks = size_to_chunks(size);
spin_lock(&pool->lock);
zhdr = NULL;
for_each_unbuddied_list(i, chunks) {
if (!list_empty(&pool->unbuddied[i])) {
zhdr = list_first_entry(&pool->unbuddied[i],
struct zbud_header, buddy);
list_del(&zhdr->buddy);
if (zhdr->first_chunks == 0)
bud = FIRST;
else
bud = LAST;
goto found;
}
}
spin_unlock(&pool->lock);
page = alloc_page(gfp);
if (!page)
return -ENOMEM;
spin_lock(&pool->lock);
pool->pages_nr++;
zhdr = init_zbud_page(page);
bud = FIRST;
found:
if (bud == FIRST)
zhdr->first_chunks = chunks;
else
zhdr->last_chunks = chunks;
if (zhdr->first_chunks == 0 || zhdr->last_chunks == 0) {
freechunks = num_free_chunks(zhdr);
list_add(&zhdr->buddy, &pool->unbuddied[freechunks]);
} else {
list_add(&zhdr->buddy, &pool->buddied);
}
if (!list_empty(&zhdr->lru))
list_del(&zhdr->lru);
list_add(&zhdr->lru, &pool->lru);
*handle = encode_handle(zhdr, bud);
spin_unlock(&pool->lock);
return 0;
}
void zbud_free(struct zbud_pool *pool, unsigned long handle)
{
struct zbud_header *zhdr;
int freechunks;
spin_lock(&pool->lock);
zhdr = handle_to_zbud_header(handle);
if ((handle - ZHDR_SIZE_ALIGNED) & ~PAGE_MASK)
zhdr->last_chunks = 0;
else
zhdr->first_chunks = 0;
if (zhdr->under_reclaim) {
spin_unlock(&pool->lock);
return;
}
list_del(&zhdr->buddy);
if (zhdr->first_chunks == 0 && zhdr->last_chunks == 0) {
list_del(&zhdr->lru);
free_zbud_page(zhdr);
pool->pages_nr--;
} else {
freechunks = num_free_chunks(zhdr);
list_add(&zhdr->buddy, &pool->unbuddied[freechunks]);
}
spin_unlock(&pool->lock);
}
int zbud_reclaim_page(struct zbud_pool *pool, unsigned int retries)
{
int i, ret, freechunks;
struct zbud_header *zhdr;
unsigned long first_handle = 0, last_handle = 0;
spin_lock(&pool->lock);
if (!pool->ops || !pool->ops->evict || list_empty(&pool->lru) ||
retries == 0) {
spin_unlock(&pool->lock);
return -EINVAL;
}
for (i = 0; i < retries; i++) {
zhdr = list_tail_entry(&pool->lru, struct zbud_header, lru);
list_del(&zhdr->lru);
list_del(&zhdr->buddy);
zhdr->under_reclaim = true;
first_handle = 0;
last_handle = 0;
if (zhdr->first_chunks)
first_handle = encode_handle(zhdr, FIRST);
if (zhdr->last_chunks)
last_handle = encode_handle(zhdr, LAST);
spin_unlock(&pool->lock);
if (first_handle) {
ret = pool->ops->evict(pool, first_handle);
if (ret)
goto next;
}
if (last_handle) {
ret = pool->ops->evict(pool, last_handle);
if (ret)
goto next;
}
next:
spin_lock(&pool->lock);
zhdr->under_reclaim = false;
if (zhdr->first_chunks == 0 && zhdr->last_chunks == 0) {
free_zbud_page(zhdr);
pool->pages_nr--;
spin_unlock(&pool->lock);
return 0;
} else if (zhdr->first_chunks == 0 ||
zhdr->last_chunks == 0) {
freechunks = num_free_chunks(zhdr);
list_add(&zhdr->buddy, &pool->unbuddied[freechunks]);
} else {
list_add(&zhdr->buddy, &pool->buddied);
}
list_add(&zhdr->lru, &pool->lru);
}
spin_unlock(&pool->lock);
return -EAGAIN;
}
void *zbud_map(struct zbud_pool *pool, unsigned long handle)
{
return (void *)(handle);
}
void zbud_unmap(struct zbud_pool *pool, unsigned long handle)
{
}
u64 zbud_get_pool_size(struct zbud_pool *pool)
{
return pool->pages_nr;
}
static int __init init_zbud(void)
{
BUILD_BUG_ON(sizeof(struct zbud_header) > ZHDR_SIZE_ALIGNED);
pr_info("loaded\n");
#ifdef CONFIG_ZPOOL
zpool_register_driver(&zbud_zpool_driver);
#endif
return 0;
}
static void __exit exit_zbud(void)
{
#ifdef CONFIG_ZPOOL
zpool_unregister_driver(&zbud_zpool_driver);
#endif
pr_info("unloaded\n");
}
