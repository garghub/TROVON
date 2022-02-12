static inline struct hlist_bl_head *mb_cache_entry_head(struct mb_cache *cache,
u32 key)
{
return &cache->c_hash[hash_32(key, cache->c_bucket_bits)];
}
int mb_cache_entry_create(struct mb_cache *cache, gfp_t mask, u32 key,
u64 value, bool reusable)
{
struct mb_cache_entry *entry, *dup;
struct hlist_bl_node *dup_node;
struct hlist_bl_head *head;
if (cache->c_entry_count >= cache->c_max_entries)
schedule_work(&cache->c_shrink_work);
if (cache->c_entry_count >= 2*cache->c_max_entries)
mb_cache_shrink(cache, SYNC_SHRINK_BATCH);
entry = kmem_cache_alloc(mb_entry_cache, mask);
if (!entry)
return -ENOMEM;
INIT_LIST_HEAD(&entry->e_list);
atomic_set(&entry->e_refcnt, 1);
entry->e_key = key;
entry->e_value = value;
entry->e_reusable = reusable;
head = mb_cache_entry_head(cache, key);
hlist_bl_lock(head);
hlist_bl_for_each_entry(dup, dup_node, head, e_hash_list) {
if (dup->e_key == key && dup->e_value == value) {
hlist_bl_unlock(head);
kmem_cache_free(mb_entry_cache, entry);
return -EBUSY;
}
}
hlist_bl_add_head(&entry->e_hash_list, head);
hlist_bl_unlock(head);
spin_lock(&cache->c_list_lock);
list_add_tail(&entry->e_list, &cache->c_list);
atomic_inc(&entry->e_refcnt);
cache->c_entry_count++;
spin_unlock(&cache->c_list_lock);
return 0;
}
void __mb_cache_entry_free(struct mb_cache_entry *entry)
{
kmem_cache_free(mb_entry_cache, entry);
}
static struct mb_cache_entry *__entry_find(struct mb_cache *cache,
struct mb_cache_entry *entry,
u32 key)
{
struct mb_cache_entry *old_entry = entry;
struct hlist_bl_node *node;
struct hlist_bl_head *head;
head = mb_cache_entry_head(cache, key);
hlist_bl_lock(head);
if (entry && !hlist_bl_unhashed(&entry->e_hash_list))
node = entry->e_hash_list.next;
else
node = hlist_bl_first(head);
while (node) {
entry = hlist_bl_entry(node, struct mb_cache_entry,
e_hash_list);
if (entry->e_key == key && entry->e_reusable) {
atomic_inc(&entry->e_refcnt);
goto out;
}
node = node->next;
}
entry = NULL;
out:
hlist_bl_unlock(head);
if (old_entry)
mb_cache_entry_put(cache, old_entry);
return entry;
}
struct mb_cache_entry *mb_cache_entry_find_first(struct mb_cache *cache,
u32 key)
{
return __entry_find(cache, NULL, key);
}
struct mb_cache_entry *mb_cache_entry_find_next(struct mb_cache *cache,
struct mb_cache_entry *entry)
{
return __entry_find(cache, entry, entry->e_key);
}
struct mb_cache_entry *mb_cache_entry_get(struct mb_cache *cache, u32 key,
u64 value)
{
struct hlist_bl_node *node;
struct hlist_bl_head *head;
struct mb_cache_entry *entry;
head = mb_cache_entry_head(cache, key);
hlist_bl_lock(head);
hlist_bl_for_each_entry(entry, node, head, e_hash_list) {
if (entry->e_key == key && entry->e_value == value) {
atomic_inc(&entry->e_refcnt);
goto out;
}
}
entry = NULL;
out:
hlist_bl_unlock(head);
return entry;
}
void mb_cache_entry_delete(struct mb_cache *cache, u32 key, u64 value)
{
struct hlist_bl_node *node;
struct hlist_bl_head *head;
struct mb_cache_entry *entry;
head = mb_cache_entry_head(cache, key);
hlist_bl_lock(head);
hlist_bl_for_each_entry(entry, node, head, e_hash_list) {
if (entry->e_key == key && entry->e_value == value) {
hlist_bl_del_init(&entry->e_hash_list);
hlist_bl_unlock(head);
spin_lock(&cache->c_list_lock);
if (!list_empty(&entry->e_list)) {
list_del_init(&entry->e_list);
cache->c_entry_count--;
atomic_dec(&entry->e_refcnt);
}
spin_unlock(&cache->c_list_lock);
mb_cache_entry_put(cache, entry);
return;
}
}
hlist_bl_unlock(head);
}
void mb_cache_entry_touch(struct mb_cache *cache,
struct mb_cache_entry *entry)
{
entry->e_referenced = 1;
}
static unsigned long mb_cache_count(struct shrinker *shrink,
struct shrink_control *sc)
{
struct mb_cache *cache = container_of(shrink, struct mb_cache,
c_shrink);
return cache->c_entry_count;
}
static unsigned long mb_cache_shrink(struct mb_cache *cache,
unsigned long nr_to_scan)
{
struct mb_cache_entry *entry;
struct hlist_bl_head *head;
unsigned long shrunk = 0;
spin_lock(&cache->c_list_lock);
while (nr_to_scan-- && !list_empty(&cache->c_list)) {
entry = list_first_entry(&cache->c_list,
struct mb_cache_entry, e_list);
if (entry->e_referenced) {
entry->e_referenced = 0;
list_move_tail(&entry->e_list, &cache->c_list);
continue;
}
list_del_init(&entry->e_list);
cache->c_entry_count--;
spin_unlock(&cache->c_list_lock);
head = mb_cache_entry_head(cache, entry->e_key);
hlist_bl_lock(head);
if (!hlist_bl_unhashed(&entry->e_hash_list)) {
hlist_bl_del_init(&entry->e_hash_list);
atomic_dec(&entry->e_refcnt);
}
hlist_bl_unlock(head);
if (mb_cache_entry_put(cache, entry))
shrunk++;
cond_resched();
spin_lock(&cache->c_list_lock);
}
spin_unlock(&cache->c_list_lock);
return shrunk;
}
static unsigned long mb_cache_scan(struct shrinker *shrink,
struct shrink_control *sc)
{
struct mb_cache *cache = container_of(shrink, struct mb_cache,
c_shrink);
return mb_cache_shrink(cache, sc->nr_to_scan);
}
static void mb_cache_shrink_worker(struct work_struct *work)
{
struct mb_cache *cache = container_of(work, struct mb_cache,
c_shrink_work);
mb_cache_shrink(cache, cache->c_max_entries / SHRINK_DIVISOR);
}
struct mb_cache *mb_cache_create(int bucket_bits)
{
struct mb_cache *cache;
unsigned long bucket_count = 1UL << bucket_bits;
unsigned long i;
cache = kzalloc(sizeof(struct mb_cache), GFP_KERNEL);
if (!cache)
goto err_out;
cache->c_bucket_bits = bucket_bits;
cache->c_max_entries = bucket_count << 4;
INIT_LIST_HEAD(&cache->c_list);
spin_lock_init(&cache->c_list_lock);
cache->c_hash = kmalloc(bucket_count * sizeof(struct hlist_bl_head),
GFP_KERNEL);
if (!cache->c_hash) {
kfree(cache);
goto err_out;
}
for (i = 0; i < bucket_count; i++)
INIT_HLIST_BL_HEAD(&cache->c_hash[i]);
cache->c_shrink.count_objects = mb_cache_count;
cache->c_shrink.scan_objects = mb_cache_scan;
cache->c_shrink.seeks = DEFAULT_SEEKS;
if (register_shrinker(&cache->c_shrink)) {
kfree(cache->c_hash);
kfree(cache);
goto err_out;
}
INIT_WORK(&cache->c_shrink_work, mb_cache_shrink_worker);
return cache;
err_out:
return NULL;
}
void mb_cache_destroy(struct mb_cache *cache)
{
struct mb_cache_entry *entry, *next;
unregister_shrinker(&cache->c_shrink);
list_for_each_entry_safe(entry, next, &cache->c_list, e_list) {
if (!hlist_bl_unhashed(&entry->e_hash_list)) {
hlist_bl_del_init(&entry->e_hash_list);
atomic_dec(&entry->e_refcnt);
} else
WARN_ON(1);
list_del(&entry->e_list);
WARN_ON(atomic_read(&entry->e_refcnt) != 1);
mb_cache_entry_put(cache, entry);
}
kfree(cache->c_hash);
kfree(cache);
}
static int __init mbcache_init(void)
{
mb_entry_cache = kmem_cache_create("mbcache",
sizeof(struct mb_cache_entry), 0,
SLAB_RECLAIM_ACCOUNT|SLAB_MEM_SPREAD, NULL);
if (!mb_entry_cache)
return -ENOMEM;
return 0;
}
static void __exit mbcache_exit(void)
{
kmem_cache_destroy(mb_entry_cache);
}
