static inline void
__spin_lock_mb_cache_entry(struct mb_cache_entry *ce)
{
spin_lock(bgl_lock_ptr(mb_cache_bg_lock,
MB_CACHE_ENTRY_LOCK_INDEX(ce)));
}
static inline void
__spin_unlock_mb_cache_entry(struct mb_cache_entry *ce)
{
spin_unlock(bgl_lock_ptr(mb_cache_bg_lock,
MB_CACHE_ENTRY_LOCK_INDEX(ce)));
}
static inline int
__mb_cache_entry_is_block_hashed(struct mb_cache_entry *ce)
{
return !hlist_bl_unhashed(&ce->e_block_list);
}
static inline void
__mb_cache_entry_unhash_block(struct mb_cache_entry *ce)
{
if (__mb_cache_entry_is_block_hashed(ce))
hlist_bl_del_init(&ce->e_block_list);
}
static inline int
__mb_cache_entry_is_index_hashed(struct mb_cache_entry *ce)
{
return !hlist_bl_unhashed(&ce->e_index.o_list);
}
static inline void
__mb_cache_entry_unhash_index(struct mb_cache_entry *ce)
{
if (__mb_cache_entry_is_index_hashed(ce))
hlist_bl_del_init(&ce->e_index.o_list);
}
static inline void
__mb_cache_entry_unhash_unlock(struct mb_cache_entry *ce)
{
__mb_cache_entry_unhash_index(ce);
hlist_bl_unlock(ce->e_index_hash_p);
__mb_cache_entry_unhash_block(ce);
hlist_bl_unlock(ce->e_block_hash_p);
}
static void
__mb_cache_entry_forget(struct mb_cache_entry *ce, gfp_t gfp_mask)
{
struct mb_cache *cache = ce->e_cache;
mb_assert(!(ce->e_used || ce->e_queued || atomic_read(&ce->e_refcnt)));
kmem_cache_free(cache->c_entry_cache, ce);
atomic_dec(&cache->c_entry_count);
}
static void
__mb_cache_entry_release(struct mb_cache_entry *ce)
{
__spin_lock_mb_cache_entry(ce);
if (ce->e_queued)
wake_up_all(&mb_cache_queue);
if (ce->e_used >= MB_CACHE_WRITER)
ce->e_used -= MB_CACHE_WRITER;
ce->e_used--;
if (!(ce->e_used || ce->e_queued || atomic_read(&ce->e_refcnt))) {
if (!__mb_cache_entry_is_block_hashed(ce)) {
__spin_unlock_mb_cache_entry(ce);
goto forget;
}
spin_lock(&mb_cache_spinlock);
if (list_empty(&ce->e_lru_list))
list_add_tail(&ce->e_lru_list, &mb_cache_lru_list);
spin_unlock(&mb_cache_spinlock);
}
__spin_unlock_mb_cache_entry(ce);
return;
forget:
mb_assert(list_empty(&ce->e_lru_list));
__mb_cache_entry_forget(ce, GFP_KERNEL);
}
static unsigned long
mb_cache_shrink_scan(struct shrinker *shrink, struct shrink_control *sc)
{
LIST_HEAD(free_list);
struct mb_cache_entry *entry, *tmp;
int nr_to_scan = sc->nr_to_scan;
gfp_t gfp_mask = sc->gfp_mask;
unsigned long freed = 0;
mb_debug("trying to free %d entries", nr_to_scan);
spin_lock(&mb_cache_spinlock);
while ((nr_to_scan-- > 0) && !list_empty(&mb_cache_lru_list)) {
struct mb_cache_entry *ce =
list_entry(mb_cache_lru_list.next,
struct mb_cache_entry, e_lru_list);
list_del_init(&ce->e_lru_list);
if (ce->e_used || ce->e_queued || atomic_read(&ce->e_refcnt))
continue;
spin_unlock(&mb_cache_spinlock);
hlist_bl_lock(ce->e_block_hash_p);
hlist_bl_lock(ce->e_index_hash_p);
if (ce->e_used || ce->e_queued || atomic_read(&ce->e_refcnt) ||
!list_empty(&ce->e_lru_list)) {
hlist_bl_unlock(ce->e_index_hash_p);
hlist_bl_unlock(ce->e_block_hash_p);
spin_lock(&mb_cache_spinlock);
continue;
}
__mb_cache_entry_unhash_unlock(ce);
list_add_tail(&ce->e_lru_list, &free_list);
spin_lock(&mb_cache_spinlock);
}
spin_unlock(&mb_cache_spinlock);
list_for_each_entry_safe(entry, tmp, &free_list, e_lru_list) {
__mb_cache_entry_forget(entry, gfp_mask);
freed++;
}
return freed;
}
static unsigned long
mb_cache_shrink_count(struct shrinker *shrink, struct shrink_control *sc)
{
struct mb_cache *cache;
unsigned long count = 0;
spin_lock(&mb_cache_spinlock);
list_for_each_entry(cache, &mb_cache_list, c_cache_list) {
mb_debug("cache %s (%d)", cache->c_name,
atomic_read(&cache->c_entry_count));
count += atomic_read(&cache->c_entry_count);
}
spin_unlock(&mb_cache_spinlock);
return vfs_pressure_ratio(count);
}
struct mb_cache *
mb_cache_create(const char *name, int bucket_bits)
{
int n, bucket_count = 1 << bucket_bits;
struct mb_cache *cache = NULL;
if (!mb_cache_bg_lock) {
mb_cache_bg_lock = kmalloc(sizeof(struct blockgroup_lock),
GFP_KERNEL);
if (!mb_cache_bg_lock)
return NULL;
bgl_lock_init(mb_cache_bg_lock);
}
cache = kmalloc(sizeof(struct mb_cache), GFP_KERNEL);
if (!cache)
return NULL;
cache->c_name = name;
atomic_set(&cache->c_entry_count, 0);
cache->c_bucket_bits = bucket_bits;
cache->c_block_hash = kmalloc(bucket_count *
sizeof(struct hlist_bl_head), GFP_KERNEL);
if (!cache->c_block_hash)
goto fail;
for (n=0; n<bucket_count; n++)
INIT_HLIST_BL_HEAD(&cache->c_block_hash[n]);
cache->c_index_hash = kmalloc(bucket_count *
sizeof(struct hlist_bl_head), GFP_KERNEL);
if (!cache->c_index_hash)
goto fail;
for (n=0; n<bucket_count; n++)
INIT_HLIST_BL_HEAD(&cache->c_index_hash[n]);
if (!mb_cache_kmem_cache) {
mb_cache_kmem_cache = kmem_cache_create(name,
sizeof(struct mb_cache_entry), 0,
SLAB_RECLAIM_ACCOUNT|SLAB_MEM_SPREAD, NULL);
if (!mb_cache_kmem_cache)
goto fail2;
}
cache->c_entry_cache = mb_cache_kmem_cache;
cache->c_max_entries = bucket_count << 4;
spin_lock(&mb_cache_spinlock);
list_add(&cache->c_cache_list, &mb_cache_list);
spin_unlock(&mb_cache_spinlock);
return cache;
fail2:
kfree(cache->c_index_hash);
fail:
kfree(cache->c_block_hash);
kfree(cache);
return NULL;
}
void
mb_cache_shrink(struct block_device *bdev)
{
LIST_HEAD(free_list);
struct list_head *l;
struct mb_cache_entry *ce, *tmp;
l = &mb_cache_lru_list;
spin_lock(&mb_cache_spinlock);
while (!list_is_last(l, &mb_cache_lru_list)) {
l = l->next;
ce = list_entry(l, struct mb_cache_entry, e_lru_list);
if (ce->e_bdev == bdev) {
list_del_init(&ce->e_lru_list);
if (ce->e_used || ce->e_queued ||
atomic_read(&ce->e_refcnt))
continue;
spin_unlock(&mb_cache_spinlock);
hlist_bl_lock(ce->e_block_hash_p);
hlist_bl_lock(ce->e_index_hash_p);
if (ce->e_used || ce->e_queued ||
atomic_read(&ce->e_refcnt) ||
!list_empty(&ce->e_lru_list)) {
hlist_bl_unlock(ce->e_index_hash_p);
hlist_bl_unlock(ce->e_block_hash_p);
l = &mb_cache_lru_list;
spin_lock(&mb_cache_spinlock);
continue;
}
__mb_cache_entry_unhash_unlock(ce);
mb_assert(!(ce->e_used || ce->e_queued ||
atomic_read(&ce->e_refcnt)));
list_add_tail(&ce->e_lru_list, &free_list);
l = &mb_cache_lru_list;
spin_lock(&mb_cache_spinlock);
}
}
spin_unlock(&mb_cache_spinlock);
list_for_each_entry_safe(ce, tmp, &free_list, e_lru_list) {
__mb_cache_entry_forget(ce, GFP_KERNEL);
}
}
void
mb_cache_destroy(struct mb_cache *cache)
{
LIST_HEAD(free_list);
struct mb_cache_entry *ce, *tmp;
spin_lock(&mb_cache_spinlock);
list_for_each_entry_safe(ce, tmp, &mb_cache_lru_list, e_lru_list) {
if (ce->e_cache == cache)
list_move_tail(&ce->e_lru_list, &free_list);
}
list_del(&cache->c_cache_list);
spin_unlock(&mb_cache_spinlock);
list_for_each_entry_safe(ce, tmp, &free_list, e_lru_list) {
list_del_init(&ce->e_lru_list);
hlist_bl_lock(ce->e_block_hash_p);
hlist_bl_lock(ce->e_index_hash_p);
mb_assert(!(ce->e_used || ce->e_queued ||
atomic_read(&ce->e_refcnt)));
__mb_cache_entry_unhash_unlock(ce);
__mb_cache_entry_forget(ce, GFP_KERNEL);
}
if (atomic_read(&cache->c_entry_count) > 0) {
mb_error("cache %s: %d orphaned entries",
cache->c_name,
atomic_read(&cache->c_entry_count));
}
if (list_empty(&mb_cache_list)) {
kmem_cache_destroy(mb_cache_kmem_cache);
mb_cache_kmem_cache = NULL;
}
kfree(cache->c_index_hash);
kfree(cache->c_block_hash);
kfree(cache);
}
struct mb_cache_entry *
mb_cache_entry_alloc(struct mb_cache *cache, gfp_t gfp_flags)
{
struct mb_cache_entry *ce;
if (atomic_read(&cache->c_entry_count) >= cache->c_max_entries) {
struct list_head *l;
l = &mb_cache_lru_list;
spin_lock(&mb_cache_spinlock);
while (!list_is_last(l, &mb_cache_lru_list)) {
l = l->next;
ce = list_entry(l, struct mb_cache_entry, e_lru_list);
if (ce->e_cache == cache) {
list_del_init(&ce->e_lru_list);
if (ce->e_used || ce->e_queued ||
atomic_read(&ce->e_refcnt))
continue;
spin_unlock(&mb_cache_spinlock);
hlist_bl_lock(ce->e_block_hash_p);
hlist_bl_lock(ce->e_index_hash_p);
if (ce->e_used || ce->e_queued ||
atomic_read(&ce->e_refcnt) ||
!list_empty(&ce->e_lru_list)) {
hlist_bl_unlock(ce->e_index_hash_p);
hlist_bl_unlock(ce->e_block_hash_p);
l = &mb_cache_lru_list;
spin_lock(&mb_cache_spinlock);
continue;
}
mb_assert(list_empty(&ce->e_lru_list));
mb_assert(!(ce->e_used || ce->e_queued ||
atomic_read(&ce->e_refcnt)));
__mb_cache_entry_unhash_unlock(ce);
goto found;
}
}
spin_unlock(&mb_cache_spinlock);
}
ce = kmem_cache_alloc(cache->c_entry_cache, gfp_flags);
if (!ce)
return NULL;
atomic_inc(&cache->c_entry_count);
INIT_LIST_HEAD(&ce->e_lru_list);
INIT_HLIST_BL_NODE(&ce->e_block_list);
INIT_HLIST_BL_NODE(&ce->e_index.o_list);
ce->e_cache = cache;
ce->e_queued = 0;
atomic_set(&ce->e_refcnt, 0);
found:
ce->e_block_hash_p = &cache->c_block_hash[0];
ce->e_index_hash_p = &cache->c_index_hash[0];
ce->e_used = 1 + MB_CACHE_WRITER;
return ce;
}
int
mb_cache_entry_insert(struct mb_cache_entry *ce, struct block_device *bdev,
sector_t block, unsigned int key)
{
struct mb_cache *cache = ce->e_cache;
unsigned int bucket;
struct hlist_bl_node *l;
struct hlist_bl_head *block_hash_p;
struct hlist_bl_head *index_hash_p;
struct mb_cache_entry *lce;
mb_assert(ce);
bucket = hash_long((unsigned long)bdev + (block & 0xffffffff),
cache->c_bucket_bits);
block_hash_p = &cache->c_block_hash[bucket];
hlist_bl_lock(block_hash_p);
hlist_bl_for_each_entry(lce, l, block_hash_p, e_block_list) {
if (lce->e_bdev == bdev && lce->e_block == block) {
hlist_bl_unlock(block_hash_p);
return -EBUSY;
}
}
mb_assert(!__mb_cache_entry_is_block_hashed(ce));
__mb_cache_entry_unhash_block(ce);
__mb_cache_entry_unhash_index(ce);
ce->e_bdev = bdev;
ce->e_block = block;
ce->e_block_hash_p = block_hash_p;
ce->e_index.o_key = key;
hlist_bl_add_head(&ce->e_block_list, block_hash_p);
hlist_bl_unlock(block_hash_p);
bucket = hash_long(key, cache->c_bucket_bits);
index_hash_p = &cache->c_index_hash[bucket];
hlist_bl_lock(index_hash_p);
ce->e_index_hash_p = index_hash_p;
hlist_bl_add_head(&ce->e_index.o_list, index_hash_p);
hlist_bl_unlock(index_hash_p);
return 0;
}
void
mb_cache_entry_release(struct mb_cache_entry *ce)
{
__mb_cache_entry_release(ce);
}
void
mb_cache_entry_free(struct mb_cache_entry *ce)
{
mb_assert(ce);
mb_assert(list_empty(&ce->e_lru_list));
hlist_bl_lock(ce->e_index_hash_p);
__mb_cache_entry_unhash_index(ce);
hlist_bl_unlock(ce->e_index_hash_p);
hlist_bl_lock(ce->e_block_hash_p);
__mb_cache_entry_unhash_block(ce);
hlist_bl_unlock(ce->e_block_hash_p);
__mb_cache_entry_release(ce);
}
struct mb_cache_entry *
mb_cache_entry_get(struct mb_cache *cache, struct block_device *bdev,
sector_t block)
{
unsigned int bucket;
struct hlist_bl_node *l;
struct mb_cache_entry *ce;
struct hlist_bl_head *block_hash_p;
bucket = hash_long((unsigned long)bdev + (block & 0xffffffff),
cache->c_bucket_bits);
block_hash_p = &cache->c_block_hash[bucket];
hlist_bl_lock(block_hash_p);
hlist_bl_for_each_entry(ce, l, block_hash_p, e_block_list) {
mb_assert(ce->e_block_hash_p == block_hash_p);
if (ce->e_bdev == bdev && ce->e_block == block) {
atomic_inc(&ce->e_refcnt);
hlist_bl_unlock(block_hash_p);
__spin_lock_mb_cache_entry(ce);
atomic_dec(&ce->e_refcnt);
if (ce->e_used > 0) {
DEFINE_WAIT(wait);
while (ce->e_used > 0) {
ce->e_queued++;
prepare_to_wait(&mb_cache_queue, &wait,
TASK_UNINTERRUPTIBLE);
__spin_unlock_mb_cache_entry(ce);
schedule();
__spin_lock_mb_cache_entry(ce);
ce->e_queued--;
}
finish_wait(&mb_cache_queue, &wait);
}
ce->e_used += 1 + MB_CACHE_WRITER;
__spin_unlock_mb_cache_entry(ce);
if (!list_empty(&ce->e_lru_list)) {
spin_lock(&mb_cache_spinlock);
list_del_init(&ce->e_lru_list);
spin_unlock(&mb_cache_spinlock);
}
if (!__mb_cache_entry_is_block_hashed(ce)) {
__mb_cache_entry_release(ce);
return NULL;
}
return ce;
}
}
hlist_bl_unlock(block_hash_p);
return NULL;
}
static struct mb_cache_entry *
__mb_cache_entry_find(struct hlist_bl_node *l, struct hlist_bl_head *head,
struct block_device *bdev, unsigned int key)
{
while (l != NULL) {
struct mb_cache_entry *ce =
hlist_bl_entry(l, struct mb_cache_entry,
e_index.o_list);
mb_assert(ce->e_index_hash_p == head);
if (ce->e_bdev == bdev && ce->e_index.o_key == key) {
atomic_inc(&ce->e_refcnt);
hlist_bl_unlock(head);
__spin_lock_mb_cache_entry(ce);
atomic_dec(&ce->e_refcnt);
ce->e_used++;
if (ce->e_used >= MB_CACHE_WRITER) {
DEFINE_WAIT(wait);
while (ce->e_used >= MB_CACHE_WRITER) {
ce->e_queued++;
prepare_to_wait(&mb_cache_queue, &wait,
TASK_UNINTERRUPTIBLE);
__spin_unlock_mb_cache_entry(ce);
schedule();
__spin_lock_mb_cache_entry(ce);
ce->e_queued--;
}
finish_wait(&mb_cache_queue, &wait);
}
__spin_unlock_mb_cache_entry(ce);
if (!list_empty(&ce->e_lru_list)) {
spin_lock(&mb_cache_spinlock);
list_del_init(&ce->e_lru_list);
spin_unlock(&mb_cache_spinlock);
}
if (!__mb_cache_entry_is_block_hashed(ce)) {
__mb_cache_entry_release(ce);
return ERR_PTR(-EAGAIN);
}
return ce;
}
l = l->next;
}
hlist_bl_unlock(head);
return NULL;
}
struct mb_cache_entry *
mb_cache_entry_find_first(struct mb_cache *cache, struct block_device *bdev,
unsigned int key)
{
unsigned int bucket = hash_long(key, cache->c_bucket_bits);
struct hlist_bl_node *l;
struct mb_cache_entry *ce = NULL;
struct hlist_bl_head *index_hash_p;
index_hash_p = &cache->c_index_hash[bucket];
hlist_bl_lock(index_hash_p);
if (!hlist_bl_empty(index_hash_p)) {
l = hlist_bl_first(index_hash_p);
ce = __mb_cache_entry_find(l, index_hash_p, bdev, key);
} else
hlist_bl_unlock(index_hash_p);
return ce;
}
struct mb_cache_entry *
mb_cache_entry_find_next(struct mb_cache_entry *prev,
struct block_device *bdev, unsigned int key)
{
struct mb_cache *cache = prev->e_cache;
unsigned int bucket = hash_long(key, cache->c_bucket_bits);
struct hlist_bl_node *l;
struct mb_cache_entry *ce;
struct hlist_bl_head *index_hash_p;
index_hash_p = &cache->c_index_hash[bucket];
mb_assert(prev->e_index_hash_p == index_hash_p);
hlist_bl_lock(index_hash_p);
mb_assert(!hlist_bl_empty(index_hash_p));
l = prev->e_index.o_list.next;
ce = __mb_cache_entry_find(l, index_hash_p, bdev, key);
__mb_cache_entry_release(prev);
return ce;
}
static int __init init_mbcache(void)
{
register_shrinker(&mb_cache_shrinker);
return 0;
}
static void __exit exit_mbcache(void)
{
unregister_shrinker(&mb_cache_shrinker);
}
