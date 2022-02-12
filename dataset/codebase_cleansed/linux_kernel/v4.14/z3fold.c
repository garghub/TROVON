static int size_to_chunks(size_t size)
{
return (size + CHUNK_SIZE - 1) >> CHUNK_SHIFT;
}
static struct z3fold_header *init_z3fold_page(struct page *page,
struct z3fold_pool *pool)
{
struct z3fold_header *zhdr = page_address(page);
INIT_LIST_HEAD(&page->lru);
clear_bit(PAGE_HEADLESS, &page->private);
clear_bit(MIDDLE_CHUNK_MAPPED, &page->private);
clear_bit(NEEDS_COMPACTING, &page->private);
clear_bit(PAGE_STALE, &page->private);
spin_lock_init(&zhdr->page_lock);
kref_init(&zhdr->refcount);
zhdr->first_chunks = 0;
zhdr->middle_chunks = 0;
zhdr->last_chunks = 0;
zhdr->first_num = 0;
zhdr->start_middle = 0;
zhdr->cpu = -1;
zhdr->pool = pool;
INIT_LIST_HEAD(&zhdr->buddy);
INIT_WORK(&zhdr->work, compact_page_work);
return zhdr;
}
static void free_z3fold_page(struct page *page)
{
__free_page(page);
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
static void __release_z3fold_page(struct z3fold_header *zhdr, bool locked)
{
struct page *page = virt_to_page(zhdr);
struct z3fold_pool *pool = zhdr->pool;
WARN_ON(!list_empty(&zhdr->buddy));
set_bit(PAGE_STALE, &page->private);
clear_bit(NEEDS_COMPACTING, &page->private);
spin_lock(&pool->lock);
if (!list_empty(&page->lru))
list_del(&page->lru);
spin_unlock(&pool->lock);
if (locked)
z3fold_page_unlock(zhdr);
spin_lock(&pool->stale_lock);
list_add(&zhdr->buddy, &pool->stale);
queue_work(pool->release_wq, &pool->work);
spin_unlock(&pool->stale_lock);
}
static void release_z3fold_page_locked(struct kref *ref)
{
struct z3fold_header *zhdr = container_of(ref, struct z3fold_header,
refcount);
WARN_ON(z3fold_page_trylock(zhdr));
__release_z3fold_page(zhdr, true);
}
static void release_z3fold_page_locked_list(struct kref *ref)
{
struct z3fold_header *zhdr = container_of(ref, struct z3fold_header,
refcount);
spin_lock(&zhdr->pool->lock);
list_del_init(&zhdr->buddy);
spin_unlock(&zhdr->pool->lock);
WARN_ON(z3fold_page_trylock(zhdr));
__release_z3fold_page(zhdr, true);
}
static void free_pages_work(struct work_struct *w)
{
struct z3fold_pool *pool = container_of(w, struct z3fold_pool, work);
spin_lock(&pool->stale_lock);
while (!list_empty(&pool->stale)) {
struct z3fold_header *zhdr = list_first_entry(&pool->stale,
struct z3fold_header, buddy);
struct page *page = virt_to_page(zhdr);
list_del(&zhdr->buddy);
if (WARN_ON(!test_bit(PAGE_STALE, &page->private)))
continue;
spin_unlock(&pool->stale_lock);
cancel_work_sync(&zhdr->work);
free_z3fold_page(page);
cond_resched();
spin_lock(&pool->stale_lock);
}
spin_unlock(&pool->stale_lock);
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
static void do_compact_page(struct z3fold_header *zhdr, bool locked)
{
struct z3fold_pool *pool = zhdr->pool;
struct page *page;
struct list_head *unbuddied;
int fchunks;
page = virt_to_page(zhdr);
if (locked)
WARN_ON(z3fold_page_trylock(zhdr));
else
z3fold_page_lock(zhdr);
if (test_bit(PAGE_STALE, &page->private) ||
!test_and_clear_bit(NEEDS_COMPACTING, &page->private)) {
z3fold_page_unlock(zhdr);
return;
}
spin_lock(&pool->lock);
list_del_init(&zhdr->buddy);
spin_unlock(&pool->lock);
z3fold_compact_page(zhdr);
unbuddied = get_cpu_ptr(pool->unbuddied);
fchunks = num_free_chunks(zhdr);
if (fchunks < NCHUNKS &&
(!zhdr->first_chunks || !zhdr->middle_chunks ||
!zhdr->last_chunks)) {
spin_lock(&pool->lock);
list_add(&zhdr->buddy, &unbuddied[fchunks]);
spin_unlock(&pool->lock);
zhdr->cpu = smp_processor_id();
}
put_cpu_ptr(pool->unbuddied);
z3fold_page_unlock(zhdr);
}
static void compact_page_work(struct work_struct *w)
{
struct z3fold_header *zhdr = container_of(w, struct z3fold_header,
work);
do_compact_page(zhdr, false);
}
static struct z3fold_pool *z3fold_create_pool(const char *name, gfp_t gfp,
const struct z3fold_ops *ops)
{
struct z3fold_pool *pool = NULL;
int i, cpu;
pool = kzalloc(sizeof(struct z3fold_pool), gfp);
if (!pool)
goto out;
spin_lock_init(&pool->lock);
spin_lock_init(&pool->stale_lock);
pool->unbuddied = __alloc_percpu(sizeof(struct list_head)*NCHUNKS, 2);
for_each_possible_cpu(cpu) {
struct list_head *unbuddied =
per_cpu_ptr(pool->unbuddied, cpu);
for_each_unbuddied_list(i, 0)
INIT_LIST_HEAD(&unbuddied[i]);
}
INIT_LIST_HEAD(&pool->lru);
INIT_LIST_HEAD(&pool->stale);
atomic64_set(&pool->pages_nr, 0);
pool->name = name;
pool->compact_wq = create_singlethread_workqueue(pool->name);
if (!pool->compact_wq)
goto out;
pool->release_wq = create_singlethread_workqueue(pool->name);
if (!pool->release_wq)
goto out_wq;
INIT_WORK(&pool->work, free_pages_work);
pool->ops = ops;
return pool;
out_wq:
destroy_workqueue(pool->compact_wq);
out:
kfree(pool);
return NULL;
}
static void z3fold_destroy_pool(struct z3fold_pool *pool)
{
destroy_workqueue(pool->release_wq);
destroy_workqueue(pool->compact_wq);
kfree(pool);
}
static int z3fold_alloc(struct z3fold_pool *pool, size_t size, gfp_t gfp,
unsigned long *handle)
{
int chunks = 0, i, freechunks;
struct z3fold_header *zhdr = NULL;
struct page *page = NULL;
enum buddy bud;
bool can_sleep = (gfp & __GFP_RECLAIM) == __GFP_RECLAIM;
if (!size || (gfp & __GFP_HIGHMEM))
return -EINVAL;
if (size > PAGE_SIZE)
return -ENOSPC;
if (size > PAGE_SIZE - ZHDR_SIZE_ALIGNED - CHUNK_SIZE)
bud = HEADLESS;
else {
struct list_head *unbuddied;
chunks = size_to_chunks(size);
lookup:
unbuddied = get_cpu_ptr(pool->unbuddied);
for_each_unbuddied_list(i, chunks) {
struct list_head *l = &unbuddied[i];
zhdr = list_first_entry_or_null(READ_ONCE(l),
struct z3fold_header, buddy);
if (!zhdr)
continue;
spin_lock(&pool->lock);
l = &unbuddied[i];
if (unlikely(zhdr != list_first_entry(READ_ONCE(l),
struct z3fold_header, buddy)) ||
!z3fold_page_trylock(zhdr)) {
spin_unlock(&pool->lock);
put_cpu_ptr(pool->unbuddied);
goto lookup;
}
list_del_init(&zhdr->buddy);
zhdr->cpu = -1;
spin_unlock(&pool->lock);
page = virt_to_page(zhdr);
if (test_bit(NEEDS_COMPACTING, &page->private)) {
z3fold_page_unlock(zhdr);
zhdr = NULL;
put_cpu_ptr(pool->unbuddied);
if (can_sleep)
cond_resched();
goto lookup;
}
kref_get(&zhdr->refcount);
break;
}
put_cpu_ptr(pool->unbuddied);
if (zhdr) {
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
if (kref_put(&zhdr->refcount,
release_z3fold_page_locked))
atomic64_dec(&pool->pages_nr);
else
z3fold_page_unlock(zhdr);
pr_err("No free chunks in unbuddied\n");
WARN_ON(1);
goto lookup;
}
goto found;
}
bud = FIRST;
}
spin_lock(&pool->stale_lock);
zhdr = list_first_entry_or_null(&pool->stale,
struct z3fold_header, buddy);
if (zhdr && (can_sleep || !work_pending(&zhdr->work))) {
list_del(&zhdr->buddy);
spin_unlock(&pool->stale_lock);
if (can_sleep)
cancel_work_sync(&zhdr->work);
page = virt_to_page(zhdr);
} else {
spin_unlock(&pool->stale_lock);
page = alloc_page(gfp);
}
if (!page)
return -ENOMEM;
atomic64_inc(&pool->pages_nr);
zhdr = init_z3fold_page(page, pool);
if (bud == HEADLESS) {
set_bit(PAGE_HEADLESS, &page->private);
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
if (zhdr->first_chunks == 0 || zhdr->last_chunks == 0 ||
zhdr->middle_chunks == 0) {
struct list_head *unbuddied = get_cpu_ptr(pool->unbuddied);
freechunks = num_free_chunks(zhdr);
spin_lock(&pool->lock);
list_add(&zhdr->buddy, &unbuddied[freechunks]);
spin_unlock(&pool->lock);
zhdr->cpu = smp_processor_id();
put_cpu_ptr(pool->unbuddied);
}
headless:
spin_lock(&pool->lock);
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
return;
}
if (kref_put(&zhdr->refcount, release_z3fold_page_locked_list)) {
atomic64_dec(&pool->pages_nr);
return;
}
if (test_and_set_bit(NEEDS_COMPACTING, &page->private)) {
z3fold_page_unlock(zhdr);
return;
}
if (zhdr->cpu < 0 || !cpu_online(zhdr->cpu)) {
spin_lock(&pool->lock);
list_del_init(&zhdr->buddy);
spin_unlock(&pool->lock);
zhdr->cpu = -1;
do_compact_page(zhdr, true);
return;
}
queue_work_on(zhdr->cpu, pool->compact_wq, &zhdr->work);
z3fold_page_unlock(zhdr);
}
static int z3fold_reclaim_page(struct z3fold_pool *pool, unsigned int retries)
{
int i, ret = 0;
struct z3fold_header *zhdr = NULL;
struct page *page = NULL;
struct list_head *pos;
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
list_for_each_prev(pos, &pool->lru) {
page = list_entry(pos, struct page, lru);
if (test_bit(PAGE_HEADLESS, &page->private))
break;
zhdr = page_address(page);
if (!z3fold_page_trylock(zhdr))
continue;
kref_get(&zhdr->refcount);
list_del_init(&zhdr->buddy);
zhdr->cpu = -1;
}
list_del_init(&page->lru);
spin_unlock(&pool->lock);
if (!test_bit(PAGE_HEADLESS, &page->private)) {
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
spin_lock(&pool->lock);
if (test_bit(PAGE_HEADLESS, &page->private)) {
if (ret == 0) {
spin_unlock(&pool->lock);
free_z3fold_page(page);
return 0;
}
} else if (kref_put(&zhdr->refcount, release_z3fold_page)) {
atomic64_dec(&pool->pages_nr);
spin_unlock(&pool->lock);
return 0;
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
pool = z3fold_create_pool(name, gfp,
zpool_ops ? &z3fold_zpool_ops : NULL);
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
