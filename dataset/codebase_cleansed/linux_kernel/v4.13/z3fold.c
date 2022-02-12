static int size_to_chunks(size_t size)
{
return (size + CHUNK_SIZE - 1) >> CHUNK_SHIFT;
}
static struct z3fold_header *init_z3fold_page(struct page *page)
{
struct z3fold_header *zhdr = page_address(page);
INIT_LIST_HEAD(&page->lru);
clear_bit(PAGE_HEADLESS, &page->private);
clear_bit(MIDDLE_CHUNK_MAPPED, &page->private);
spin_lock_init(&zhdr->page_lock);
kref_init(&zhdr->refcount);
zhdr->first_chunks = 0;
zhdr->middle_chunks = 0;
zhdr->last_chunks = 0;
zhdr->first_num = 0;
zhdr->start_middle = 0;
INIT_LIST_HEAD(&zhdr->buddy);
return zhdr;
}
static void free_z3fold_page(struct page *page)
{
__free_page(page);
}
static void release_z3fold_page(struct kref *ref)
{
struct z3fold_header *zhdr;
struct page *page;
zhdr = container_of(ref, struct z3fold_header, refcount);
page = virt_to_page(zhdr);
if (!list_empty(&zhdr->buddy))
list_del(&zhdr->buddy);
if (!list_empty(&page->lru))
list_del(&page->lru);
free_z3fold_page(page);
}
static inline void z3fold_page_lock(struct z3fold_header *zhdr)
{
spin_lock(&zhdr->page_lock);
}
static inline int z3fold_page_trylock(struct z3fold_header *zhdr)
{
return spin_trylock(&zhdr->page_lock);
}
static inline void z3fold_page_unlock(struct z3fold_header *zhdr)
{
spin_unlock(&zhdr->page_lock);
}
static unsigned long encode_handle(struct z3fold_header *zhdr, enum buddy bud)
{
unsigned long handle;
handle = (unsigned long)zhdr;
if (bud != HEADLESS)
handle += (bud + zhdr->first_num) & BUDDY_MASK;
return handle;
}
static struct z3fold_header *handle_to_z3fold_header(unsigned long handle)
{
return (struct z3fold_header *)(handle & PAGE_MASK);
}
static enum buddy handle_to_buddy(unsigned long handle)
{
struct z3fold_header *zhdr = handle_to_z3fold_header(handle);
return (handle - zhdr->first_num) & BUDDY_MASK;
}
static int num_free_chunks(struct z3fold_header *zhdr)
{
int nfree;
if (zhdr->middle_chunks != 0) {
int nfree_before = zhdr->first_chunks ?
0 : zhdr->start_middle - ZHDR_CHUNKS;
int nfree_after = zhdr->last_chunks ?
0 : TOTAL_CHUNKS -
(zhdr->start_middle + zhdr->middle_chunks);
nfree = max(nfree_before, nfree_after);
} else
nfree = NCHUNKS - zhdr->first_chunks - zhdr->last_chunks;
return nfree;
}
static struct z3fold_pool *z3fold_create_pool(gfp_t gfp,
const struct z3fold_ops *ops)
{
struct z3fold_pool *pool;
int i;
pool = kzalloc(sizeof(struct z3fold_pool), gfp);
if (!pool)
return NULL;
spin_lock_init(&pool->lock);
for_each_unbuddied_list(i, 0)
INIT_LIST_HEAD(&pool->unbuddied[i]);
INIT_LIST_HEAD(&pool->lru);
atomic64_set(&pool->pages_nr, 0);
pool->ops = ops;
return pool;
}
static void z3fold_destroy_pool(struct z3fold_pool *pool)
{
kfree(pool);
}
static inline void *mchunk_memmove(struct z3fold_header *zhdr,
unsigned short dst_chunk)
{
void *beg = zhdr;
return memmove(beg + (dst_chunk << CHUNK_SHIFT),
beg + (zhdr->start_middle << CHUNK_SHIFT),
zhdr->middle_chunks << CHUNK_SHIFT);
}
static int z3fold_compact_page(struct z3fold_header *zhdr)
{
struct page *page = virt_to_page(zhdr);
if (test_bit(MIDDLE_CHUNK_MAPPED, &page->private))
return 0;
if (zhdr->middle_chunks == 0)
return 0;
if (zhdr->first_chunks == 0 && zhdr->last_chunks == 0) {
mchunk_memmove(zhdr, ZHDR_CHUNKS);
zhdr->first_chunks = zhdr->middle_chunks;
zhdr->middle_chunks = 0;
zhdr->start_middle = 0;
zhdr->first_num++;
return 1;
}
if (zhdr->first_chunks != 0 && zhdr->last_chunks == 0 &&
zhdr->start_middle - (zhdr->first_chunks + ZHDR_CHUNKS) >=
BIG_CHUNK_GAP) {
mchunk_memmove(zhdr, zhdr->first_chunks + ZHDR_CHUNKS);
zhdr->start_middle = zhdr->first_chunks + ZHDR_CHUNKS;
return 1;
} else if (zhdr->last_chunks != 0 && zhdr->first_chunks == 0 &&
TOTAL_CHUNKS - (zhdr->last_chunks + zhdr->start_middle
+ zhdr->middle_chunks) >=
BIG_CHUNK_GAP) {
unsigned short new_start = TOTAL_CHUNKS - zhdr->last_chunks -
zhdr->middle_chunks;
mchunk_memmove(zhdr, new_start);
zhdr->start_middle = new_start;
return 1;
}
return 0;
}
static int z3fold_alloc(struct z3fold_pool *pool, size_t size, gfp_t gfp,
unsigned long *handle)
{
int chunks = 0, i, freechunks;
struct z3fold_header *zhdr = NULL;
enum buddy bud;
struct page *page;
if (!size || (gfp & __GFP_HIGHMEM))
return -EINVAL;
if (size > PAGE_SIZE)
return -ENOSPC;
if (size > PAGE_SIZE - ZHDR_SIZE_ALIGNED - CHUNK_SIZE)
bud = HEADLESS;
else {
chunks = size_to_chunks(size);
zhdr = NULL;
for_each_unbuddied_list(i, chunks) {
spin_lock(&pool->lock);
zhdr = list_first_entry_or_null(&pool->unbuddied[i],
struct z3fold_header, buddy);
if (!zhdr || !z3fold_page_trylock(zhdr)) {
spin_unlock(&pool->lock);
continue;
}
kref_get(&zhdr->refcount);
list_del_init(&zhdr->buddy);
spin_unlock(&pool->lock);
page = virt_to_page(zhdr);
if (zhdr->first_chunks == 0) {
if (zhdr->middle_chunks != 0 &&
chunks >= zhdr->start_middle)
bud = LAST;
else
bud = FIRST;
} else if (zhdr->last_chunks == 0)
bud = LAST;
else if (zhdr->middle_chunks == 0)
bud = MIDDLE;
else {
z3fold_page_unlock(zhdr);
spin_lock(&pool->lock);
if (kref_put(&zhdr->refcount,
release_z3fold_page))
atomic64_dec(&pool->pages_nr);
spin_unlock(&pool->lock);
pr_err("No free chunks in unbuddied\n");
WARN_ON(1);
continue;
}
goto found;
}
bud = FIRST;
}
page = alloc_page(gfp);
if (!page)
return -ENOMEM;
atomic64_inc(&pool->pages_nr);
zhdr = init_z3fold_page(page);
if (bud == HEADLESS) {
set_bit(PAGE_HEADLESS, &page->private);
spin_lock(&pool->lock);
goto headless;
}
z3fold_page_lock(zhdr);
found:
if (bud == FIRST)
zhdr->first_chunks = chunks;
else if (bud == LAST)
zhdr->last_chunks = chunks;
else {
zhdr->middle_chunks = chunks;
zhdr->start_middle = zhdr->first_chunks + ZHDR_CHUNKS;
}
spin_lock(&pool->lock);
if (zhdr->first_chunks == 0 || zhdr->last_chunks == 0 ||
zhdr->middle_chunks == 0) {
freechunks = num_free_chunks(zhdr);
list_add(&zhdr->buddy, &pool->unbuddied[freechunks]);
}
headless:
if (!list_empty(&page->lru))
list_del(&page->lru);
list_add(&page->lru, &pool->lru);
*handle = encode_handle(zhdr, bud);
spin_unlock(&pool->lock);
if (bud != HEADLESS)
z3fold_page_unlock(zhdr);
return 0;
}
static void z3fold_free(struct z3fold_pool *pool, unsigned long handle)
{
struct z3fold_header *zhdr;
int freechunks;
struct page *page;
enum buddy bud;
zhdr = handle_to_z3fold_header(handle);
page = virt_to_page(zhdr);
if (test_bit(PAGE_HEADLESS, &page->private)) {
bud = HEADLESS;
} else {
z3fold_page_lock(zhdr);
bud = handle_to_buddy(handle);
switch (bud) {
case FIRST:
zhdr->first_chunks = 0;
break;
case MIDDLE:
zhdr->middle_chunks = 0;
zhdr->start_middle = 0;
break;
case LAST:
zhdr->last_chunks = 0;
break;
default:
pr_err("%s: unknown bud %d\n", __func__, bud);
WARN_ON(1);
z3fold_page_unlock(zhdr);
return;
}
}
if (bud == HEADLESS) {
spin_lock(&pool->lock);
list_del(&page->lru);
spin_unlock(&pool->lock);
free_z3fold_page(page);
atomic64_dec(&pool->pages_nr);
} else {
if (zhdr->first_chunks != 0 || zhdr->middle_chunks != 0 ||
zhdr->last_chunks != 0) {
z3fold_compact_page(zhdr);
spin_lock(&pool->lock);
if (!list_empty(&zhdr->buddy))
list_del(&zhdr->buddy);
freechunks = num_free_chunks(zhdr);
list_add(&zhdr->buddy, &pool->unbuddied[freechunks]);
spin_unlock(&pool->lock);
}
z3fold_page_unlock(zhdr);
spin_lock(&pool->lock);
if (kref_put(&zhdr->refcount, release_z3fold_page))
atomic64_dec(&pool->pages_nr);
spin_unlock(&pool->lock);
}
}
static int z3fold_reclaim_page(struct z3fold_pool *pool, unsigned int retries)
{
int i, ret = 0, freechunks;
struct z3fold_header *zhdr;
struct page *page;
unsigned long first_handle = 0, middle_handle = 0, last_handle = 0;
spin_lock(&pool->lock);
if (!pool->ops || !pool->ops->evict || retries == 0) {
spin_unlock(&pool->lock);
return -EINVAL;
}
for (i = 0; i < retries; i++) {
if (list_empty(&pool->lru)) {
spin_unlock(&pool->lock);
return -EINVAL;
}
page = list_last_entry(&pool->lru, struct page, lru);
list_del_init(&page->lru);
zhdr = page_address(page);
if (!test_bit(PAGE_HEADLESS, &page->private)) {
if (!list_empty(&zhdr->buddy))
list_del_init(&zhdr->buddy);
kref_get(&zhdr->refcount);
spin_unlock(&pool->lock);
z3fold_page_lock(zhdr);
first_handle = 0;
last_handle = 0;
middle_handle = 0;
if (zhdr->first_chunks)
first_handle = encode_handle(zhdr, FIRST);
if (zhdr->middle_chunks)
middle_handle = encode_handle(zhdr, MIDDLE);
if (zhdr->last_chunks)
last_handle = encode_handle(zhdr, LAST);
z3fold_page_unlock(zhdr);
} else {
first_handle = encode_handle(zhdr, HEADLESS);
last_handle = middle_handle = 0;
spin_unlock(&pool->lock);
}
if (middle_handle) {
ret = pool->ops->evict(pool, middle_handle);
if (ret)
goto next;
}
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
if (test_bit(PAGE_HEADLESS, &page->private)) {
if (ret == 0) {
free_z3fold_page(page);
return 0;
} else {
spin_lock(&pool->lock);
}
} else {
z3fold_page_lock(zhdr);
if ((zhdr->first_chunks || zhdr->last_chunks ||
zhdr->middle_chunks) &&
!(zhdr->first_chunks && zhdr->last_chunks &&
zhdr->middle_chunks)) {
z3fold_compact_page(zhdr);
spin_lock(&pool->lock);
freechunks = num_free_chunks(zhdr);
list_add(&zhdr->buddy,
&pool->unbuddied[freechunks]);
spin_unlock(&pool->lock);
}
z3fold_page_unlock(zhdr);
spin_lock(&pool->lock);
if (kref_put(&zhdr->refcount, release_z3fold_page)) {
spin_unlock(&pool->lock);
atomic64_dec(&pool->pages_nr);
return 0;
}
}
list_add(&page->lru, &pool->lru);
}
spin_unlock(&pool->lock);
return -EAGAIN;
}
static void *z3fold_map(struct z3fold_pool *pool, unsigned long handle)
{
struct z3fold_header *zhdr;
struct page *page;
void *addr;
enum buddy buddy;
zhdr = handle_to_z3fold_header(handle);
addr = zhdr;
page = virt_to_page(zhdr);
if (test_bit(PAGE_HEADLESS, &page->private))
goto out;
z3fold_page_lock(zhdr);
buddy = handle_to_buddy(handle);
switch (buddy) {
case FIRST:
addr += ZHDR_SIZE_ALIGNED;
break;
case MIDDLE:
addr += zhdr->start_middle << CHUNK_SHIFT;
set_bit(MIDDLE_CHUNK_MAPPED, &page->private);
break;
case LAST:
addr += PAGE_SIZE - (zhdr->last_chunks << CHUNK_SHIFT);
break;
default:
pr_err("unknown buddy id %d\n", buddy);
WARN_ON(1);
addr = NULL;
break;
}
z3fold_page_unlock(zhdr);
out:
return addr;
}
static void z3fold_unmap(struct z3fold_pool *pool, unsigned long handle)
{
struct z3fold_header *zhdr;
struct page *page;
enum buddy buddy;
zhdr = handle_to_z3fold_header(handle);
page = virt_to_page(zhdr);
if (test_bit(PAGE_HEADLESS, &page->private))
return;
z3fold_page_lock(zhdr);
buddy = handle_to_buddy(handle);
if (buddy == MIDDLE)
clear_bit(MIDDLE_CHUNK_MAPPED, &page->private);
z3fold_page_unlock(zhdr);
}
static u64 z3fold_get_pool_size(struct z3fold_pool *pool)
{
return atomic64_read(&pool->pages_nr);
}
static int z3fold_zpool_evict(struct z3fold_pool *pool, unsigned long handle)
{
if (pool->zpool && pool->zpool_ops && pool->zpool_ops->evict)
return pool->zpool_ops->evict(pool->zpool, handle);
else
return -ENOENT;
}
static void *z3fold_zpool_create(const char *name, gfp_t gfp,
const struct zpool_ops *zpool_ops,
struct zpool *zpool)
{
struct z3fold_pool *pool;
pool = z3fold_create_pool(gfp, zpool_ops ? &z3fold_zpool_ops : NULL);
if (pool) {
pool->zpool = zpool;
pool->zpool_ops = zpool_ops;
}
return pool;
}
static void z3fold_zpool_destroy(void *pool)
{
z3fold_destroy_pool(pool);
}
static int z3fold_zpool_malloc(void *pool, size_t size, gfp_t gfp,
unsigned long *handle)
{
return z3fold_alloc(pool, size, gfp, handle);
}
static void z3fold_zpool_free(void *pool, unsigned long handle)
{
z3fold_free(pool, handle);
}
static int z3fold_zpool_shrink(void *pool, unsigned int pages,
unsigned int *reclaimed)
{
unsigned int total = 0;
int ret = -EINVAL;
while (total < pages) {
ret = z3fold_reclaim_page(pool, 8);
if (ret < 0)
break;
total++;
}
if (reclaimed)
*reclaimed = total;
return ret;
}
static void *z3fold_zpool_map(void *pool, unsigned long handle,
enum zpool_mapmode mm)
{
return z3fold_map(pool, handle);
}
static void z3fold_zpool_unmap(void *pool, unsigned long handle)
{
z3fold_unmap(pool, handle);
}
static u64 z3fold_zpool_total_size(void *pool)
{
return z3fold_get_pool_size(pool) * PAGE_SIZE;
}
static int __init init_z3fold(void)
{
BUILD_BUG_ON(ZHDR_SIZE_ALIGNED > PAGE_SIZE);
zpool_register_driver(&z3fold_zpool_driver);
return 0;
}
static void __exit exit_z3fold(void)
{
zpool_unregister_driver(&z3fold_zpool_driver);
}
