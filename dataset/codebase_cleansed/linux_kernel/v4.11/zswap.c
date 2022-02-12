static bool zswap_is_full(void)
{
return totalram_pages * zswap_max_pool_percent / 100 <
DIV_ROUND_UP(zswap_pool_total_size, PAGE_SIZE);
}
static void zswap_update_total_size(void)
{
struct zswap_pool *pool;
u64 total = 0;
rcu_read_lock();
list_for_each_entry_rcu(pool, &zswap_pools, list)
total += zpool_get_total_size(pool->zpool);
rcu_read_unlock();
zswap_pool_total_size = total;
}
static int __init zswap_entry_cache_create(void)
{
zswap_entry_cache = KMEM_CACHE(zswap_entry, 0);
return zswap_entry_cache == NULL;
}
static void __init zswap_entry_cache_destroy(void)
{
kmem_cache_destroy(zswap_entry_cache);
}
static struct zswap_entry *zswap_entry_cache_alloc(gfp_t gfp)
{
struct zswap_entry *entry;
entry = kmem_cache_alloc(zswap_entry_cache, gfp);
if (!entry)
return NULL;
entry->refcount = 1;
RB_CLEAR_NODE(&entry->rbnode);
return entry;
}
static void zswap_entry_cache_free(struct zswap_entry *entry)
{
kmem_cache_free(zswap_entry_cache, entry);
}
static struct zswap_entry *zswap_rb_search(struct rb_root *root, pgoff_t offset)
{
struct rb_node *node = root->rb_node;
struct zswap_entry *entry;
while (node) {
entry = rb_entry(node, struct zswap_entry, rbnode);
if (entry->offset > offset)
node = node->rb_left;
else if (entry->offset < offset)
node = node->rb_right;
else
return entry;
}
return NULL;
}
static int zswap_rb_insert(struct rb_root *root, struct zswap_entry *entry,
struct zswap_entry **dupentry)
{
struct rb_node **link = &root->rb_node, *parent = NULL;
struct zswap_entry *myentry;
while (*link) {
parent = *link;
myentry = rb_entry(parent, struct zswap_entry, rbnode);
if (myentry->offset > entry->offset)
link = &(*link)->rb_left;
else if (myentry->offset < entry->offset)
link = &(*link)->rb_right;
else {
*dupentry = myentry;
return -EEXIST;
}
}
rb_link_node(&entry->rbnode, parent, link);
rb_insert_color(&entry->rbnode, root);
return 0;
}
static void zswap_rb_erase(struct rb_root *root, struct zswap_entry *entry)
{
if (!RB_EMPTY_NODE(&entry->rbnode)) {
rb_erase(&entry->rbnode, root);
RB_CLEAR_NODE(&entry->rbnode);
}
}
static void zswap_free_entry(struct zswap_entry *entry)
{
zpool_free(entry->pool->zpool, entry->handle);
zswap_pool_put(entry->pool);
zswap_entry_cache_free(entry);
atomic_dec(&zswap_stored_pages);
zswap_update_total_size();
}
static void zswap_entry_get(struct zswap_entry *entry)
{
entry->refcount++;
}
static void zswap_entry_put(struct zswap_tree *tree,
struct zswap_entry *entry)
{
int refcount = --entry->refcount;
BUG_ON(refcount < 0);
if (refcount == 0) {
zswap_rb_erase(&tree->rbroot, entry);
zswap_free_entry(entry);
}
}
static struct zswap_entry *zswap_entry_find_get(struct rb_root *root,
pgoff_t offset)
{
struct zswap_entry *entry;
entry = zswap_rb_search(root, offset);
if (entry)
zswap_entry_get(entry);
return entry;
}
static int zswap_dstmem_prepare(unsigned int cpu)
{
u8 *dst;
dst = kmalloc_node(PAGE_SIZE * 2, GFP_KERNEL, cpu_to_node(cpu));
if (!dst) {
pr_err("can't allocate compressor buffer\n");
return -ENOMEM;
}
per_cpu(zswap_dstmem, cpu) = dst;
return 0;
}
static int zswap_dstmem_dead(unsigned int cpu)
{
u8 *dst;
dst = per_cpu(zswap_dstmem, cpu);
kfree(dst);
per_cpu(zswap_dstmem, cpu) = NULL;
return 0;
}
static int zswap_cpu_comp_prepare(unsigned int cpu, struct hlist_node *node)
{
struct zswap_pool *pool = hlist_entry(node, struct zswap_pool, node);
struct crypto_comp *tfm;
if (WARN_ON(*per_cpu_ptr(pool->tfm, cpu)))
return 0;
tfm = crypto_alloc_comp(pool->tfm_name, 0, 0);
if (IS_ERR_OR_NULL(tfm)) {
pr_err("could not alloc crypto comp %s : %ld\n",
pool->tfm_name, PTR_ERR(tfm));
return -ENOMEM;
}
*per_cpu_ptr(pool->tfm, cpu) = tfm;
return 0;
}
static int zswap_cpu_comp_dead(unsigned int cpu, struct hlist_node *node)
{
struct zswap_pool *pool = hlist_entry(node, struct zswap_pool, node);
struct crypto_comp *tfm;
tfm = *per_cpu_ptr(pool->tfm, cpu);
if (!IS_ERR_OR_NULL(tfm))
crypto_free_comp(tfm);
*per_cpu_ptr(pool->tfm, cpu) = NULL;
return 0;
}
static struct zswap_pool *__zswap_pool_current(void)
{
struct zswap_pool *pool;
pool = list_first_or_null_rcu(&zswap_pools, typeof(*pool), list);
WARN_ONCE(!pool && zswap_has_pool,
"%s: no page storage pool!\n", __func__);
return pool;
}
static struct zswap_pool *zswap_pool_current(void)
{
assert_spin_locked(&zswap_pools_lock);
return __zswap_pool_current();
}
static struct zswap_pool *zswap_pool_current_get(void)
{
struct zswap_pool *pool;
rcu_read_lock();
pool = __zswap_pool_current();
if (!zswap_pool_get(pool))
pool = NULL;
rcu_read_unlock();
return pool;
}
static struct zswap_pool *zswap_pool_last_get(void)
{
struct zswap_pool *pool, *last = NULL;
rcu_read_lock();
list_for_each_entry_rcu(pool, &zswap_pools, list)
last = pool;
WARN_ONCE(!last && zswap_has_pool,
"%s: no page storage pool!\n", __func__);
if (!zswap_pool_get(last))
last = NULL;
rcu_read_unlock();
return last;
}
static struct zswap_pool *zswap_pool_find_get(char *type, char *compressor)
{
struct zswap_pool *pool;
assert_spin_locked(&zswap_pools_lock);
list_for_each_entry_rcu(pool, &zswap_pools, list) {
if (strcmp(pool->tfm_name, compressor))
continue;
if (strcmp(zpool_get_type(pool->zpool), type))
continue;
if (!zswap_pool_get(pool))
continue;
return pool;
}
return NULL;
}
static struct zswap_pool *zswap_pool_create(char *type, char *compressor)
{
struct zswap_pool *pool;
char name[38];
gfp_t gfp = __GFP_NORETRY | __GFP_NOWARN | __GFP_KSWAPD_RECLAIM;
int ret;
if (!zswap_has_pool) {
if (!strcmp(type, ZSWAP_PARAM_UNSET))
return NULL;
if (!strcmp(compressor, ZSWAP_PARAM_UNSET))
return NULL;
}
pool = kzalloc(sizeof(*pool), GFP_KERNEL);
if (!pool) {
pr_err("pool alloc failed\n");
return NULL;
}
snprintf(name, 38, "zswap%x", atomic_inc_return(&zswap_pools_count));
pool->zpool = zpool_create_pool(type, name, gfp, &zswap_zpool_ops);
if (!pool->zpool) {
pr_err("%s zpool not available\n", type);
goto error;
}
pr_debug("using %s zpool\n", zpool_get_type(pool->zpool));
strlcpy(pool->tfm_name, compressor, sizeof(pool->tfm_name));
pool->tfm = alloc_percpu(struct crypto_comp *);
if (!pool->tfm) {
pr_err("percpu alloc failed\n");
goto error;
}
ret = cpuhp_state_add_instance(CPUHP_MM_ZSWP_POOL_PREPARE,
&pool->node);
if (ret)
goto error;
pr_debug("using %s compressor\n", pool->tfm_name);
kref_init(&pool->kref);
INIT_LIST_HEAD(&pool->list);
zswap_pool_debug("created", pool);
return pool;
error:
free_percpu(pool->tfm);
if (pool->zpool)
zpool_destroy_pool(pool->zpool);
kfree(pool);
return NULL;
}
void zswap_pool_destroy(struct zswap_pool *pool)
{
zswap_pool_debug("destroying", pool);
cpuhp_state_remove_instance(CPUHP_MM_ZSWP_POOL_PREPARE, &pool->node);
free_percpu(pool->tfm);
zpool_destroy_pool(pool->zpool);
kfree(pool);
}
static int __must_check zswap_pool_get(struct zswap_pool *pool)
{
if (!pool)
return 0;
return kref_get_unless_zero(&pool->kref);
}
static void __zswap_pool_release(struct work_struct *work)
{
struct zswap_pool *pool = container_of(work, typeof(*pool), work);
synchronize_rcu();
WARN_ON(kref_get_unless_zero(&pool->kref));
zswap_pool_destroy(pool);
}
static void __zswap_pool_empty(struct kref *kref)
{
struct zswap_pool *pool;
pool = container_of(kref, typeof(*pool), kref);
spin_lock(&zswap_pools_lock);
WARN_ON(pool == zswap_pool_current());
list_del_rcu(&pool->list);
INIT_WORK(&pool->work, __zswap_pool_release);
schedule_work(&pool->work);
spin_unlock(&zswap_pools_lock);
}
static void zswap_pool_put(struct zswap_pool *pool)
{
kref_put(&pool->kref, __zswap_pool_empty);
}
static int __zswap_param_set(const char *val, const struct kernel_param *kp,
char *type, char *compressor)
{
struct zswap_pool *pool, *put_pool = NULL;
char *s = strstrip((char *)val);
int ret;
if (zswap_init_failed) {
pr_err("can't set param, initialization failed\n");
return -ENODEV;
}
if (!strcmp(s, *(char **)kp->arg) && zswap_has_pool)
return 0;
if (!zswap_init_started)
return param_set_charp(s, kp);
if (!type) {
if (!zpool_has_pool(s)) {
pr_err("zpool %s not available\n", s);
return -ENOENT;
}
type = s;
} else if (!compressor) {
if (!crypto_has_comp(s, 0, 0)) {
pr_err("compressor %s not available\n", s);
return -ENOENT;
}
compressor = s;
} else {
WARN_ON(1);
return -EINVAL;
}
spin_lock(&zswap_pools_lock);
pool = zswap_pool_find_get(type, compressor);
if (pool) {
zswap_pool_debug("using existing", pool);
WARN_ON(pool == zswap_pool_current());
list_del_rcu(&pool->list);
}
spin_unlock(&zswap_pools_lock);
if (!pool)
pool = zswap_pool_create(type, compressor);
if (pool)
ret = param_set_charp(s, kp);
else
ret = -EINVAL;
spin_lock(&zswap_pools_lock);
if (!ret) {
put_pool = zswap_pool_current();
list_add_rcu(&pool->list, &zswap_pools);
zswap_has_pool = true;
} else if (pool) {
list_add_tail_rcu(&pool->list, &zswap_pools);
put_pool = pool;
}
spin_unlock(&zswap_pools_lock);
if (!zswap_has_pool && !pool) {
ret = param_set_charp(s, kp);
}
if (put_pool)
zswap_pool_put(put_pool);
return ret;
}
static int zswap_compressor_param_set(const char *val,
const struct kernel_param *kp)
{
return __zswap_param_set(val, kp, zswap_zpool_type, NULL);
}
static int zswap_zpool_param_set(const char *val,
const struct kernel_param *kp)
{
return __zswap_param_set(val, kp, NULL, zswap_compressor);
}
static int zswap_enabled_param_set(const char *val,
const struct kernel_param *kp)
{
if (zswap_init_failed) {
pr_err("can't enable, initialization failed\n");
return -ENODEV;
}
if (!zswap_has_pool && zswap_init_started) {
pr_err("can't enable, no pool configured\n");
return -ENODEV;
}
return param_set_bool(val, kp);
}
static int zswap_get_swap_cache_page(swp_entry_t entry,
struct page **retpage)
{
bool page_was_allocated;
*retpage = __read_swap_cache_async(entry, GFP_KERNEL,
NULL, 0, &page_was_allocated);
if (page_was_allocated)
return ZSWAP_SWAPCACHE_NEW;
if (!*retpage)
return ZSWAP_SWAPCACHE_FAIL;
return ZSWAP_SWAPCACHE_EXIST;
}
static int zswap_writeback_entry(struct zpool *pool, unsigned long handle)
{
struct zswap_header *zhdr;
swp_entry_t swpentry;
struct zswap_tree *tree;
pgoff_t offset;
struct zswap_entry *entry;
struct page *page;
struct crypto_comp *tfm;
u8 *src, *dst;
unsigned int dlen;
int ret;
struct writeback_control wbc = {
.sync_mode = WB_SYNC_NONE,
};
zhdr = zpool_map_handle(pool, handle, ZPOOL_MM_RO);
swpentry = zhdr->swpentry;
zpool_unmap_handle(pool, handle);
tree = zswap_trees[swp_type(swpentry)];
offset = swp_offset(swpentry);
spin_lock(&tree->lock);
entry = zswap_entry_find_get(&tree->rbroot, offset);
if (!entry) {
spin_unlock(&tree->lock);
return 0;
}
spin_unlock(&tree->lock);
BUG_ON(offset != entry->offset);
switch (zswap_get_swap_cache_page(swpentry, &page)) {
case ZSWAP_SWAPCACHE_FAIL:
ret = -ENOMEM;
goto fail;
case ZSWAP_SWAPCACHE_EXIST:
put_page(page);
ret = -EEXIST;
goto fail;
case ZSWAP_SWAPCACHE_NEW:
dlen = PAGE_SIZE;
src = (u8 *)zpool_map_handle(entry->pool->zpool, entry->handle,
ZPOOL_MM_RO) + sizeof(struct zswap_header);
dst = kmap_atomic(page);
tfm = *get_cpu_ptr(entry->pool->tfm);
ret = crypto_comp_decompress(tfm, src, entry->length,
dst, &dlen);
put_cpu_ptr(entry->pool->tfm);
kunmap_atomic(dst);
zpool_unmap_handle(entry->pool->zpool, entry->handle);
BUG_ON(ret);
BUG_ON(dlen != PAGE_SIZE);
SetPageUptodate(page);
}
SetPageReclaim(page);
__swap_writepage(page, &wbc, end_swap_bio_write);
put_page(page);
zswap_written_back_pages++;
spin_lock(&tree->lock);
zswap_entry_put(tree, entry);
if (entry == zswap_rb_search(&tree->rbroot, offset))
zswap_entry_put(tree, entry);
spin_unlock(&tree->lock);
goto end;
fail:
spin_lock(&tree->lock);
zswap_entry_put(tree, entry);
spin_unlock(&tree->lock);
end:
return ret;
}
static int zswap_shrink(void)
{
struct zswap_pool *pool;
int ret;
pool = zswap_pool_last_get();
if (!pool)
return -ENOENT;
ret = zpool_shrink(pool->zpool, 1, NULL);
zswap_pool_put(pool);
return ret;
}
static int zswap_frontswap_store(unsigned type, pgoff_t offset,
struct page *page)
{
struct zswap_tree *tree = zswap_trees[type];
struct zswap_entry *entry, *dupentry;
struct crypto_comp *tfm;
int ret;
unsigned int dlen = PAGE_SIZE, len;
unsigned long handle;
char *buf;
u8 *src, *dst;
struct zswap_header *zhdr;
if (!zswap_enabled || !tree) {
ret = -ENODEV;
goto reject;
}
if (zswap_is_full()) {
zswap_pool_limit_hit++;
if (zswap_shrink()) {
zswap_reject_reclaim_fail++;
ret = -ENOMEM;
goto reject;
}
}
entry = zswap_entry_cache_alloc(GFP_KERNEL);
if (!entry) {
zswap_reject_kmemcache_fail++;
ret = -ENOMEM;
goto reject;
}
entry->pool = zswap_pool_current_get();
if (!entry->pool) {
ret = -EINVAL;
goto freepage;
}
dst = get_cpu_var(zswap_dstmem);
tfm = *get_cpu_ptr(entry->pool->tfm);
src = kmap_atomic(page);
ret = crypto_comp_compress(tfm, src, PAGE_SIZE, dst, &dlen);
kunmap_atomic(src);
put_cpu_ptr(entry->pool->tfm);
if (ret) {
ret = -EINVAL;
goto put_dstmem;
}
len = dlen + sizeof(struct zswap_header);
ret = zpool_malloc(entry->pool->zpool, len,
__GFP_NORETRY | __GFP_NOWARN | __GFP_KSWAPD_RECLAIM,
&handle);
if (ret == -ENOSPC) {
zswap_reject_compress_poor++;
goto put_dstmem;
}
if (ret) {
zswap_reject_alloc_fail++;
goto put_dstmem;
}
zhdr = zpool_map_handle(entry->pool->zpool, handle, ZPOOL_MM_RW);
zhdr->swpentry = swp_entry(type, offset);
buf = (u8 *)(zhdr + 1);
memcpy(buf, dst, dlen);
zpool_unmap_handle(entry->pool->zpool, handle);
put_cpu_var(zswap_dstmem);
entry->offset = offset;
entry->handle = handle;
entry->length = dlen;
spin_lock(&tree->lock);
do {
ret = zswap_rb_insert(&tree->rbroot, entry, &dupentry);
if (ret == -EEXIST) {
zswap_duplicate_entry++;
zswap_rb_erase(&tree->rbroot, dupentry);
zswap_entry_put(tree, dupentry);
}
} while (ret == -EEXIST);
spin_unlock(&tree->lock);
atomic_inc(&zswap_stored_pages);
zswap_update_total_size();
return 0;
put_dstmem:
put_cpu_var(zswap_dstmem);
zswap_pool_put(entry->pool);
freepage:
zswap_entry_cache_free(entry);
reject:
return ret;
}
static int zswap_frontswap_load(unsigned type, pgoff_t offset,
struct page *page)
{
struct zswap_tree *tree = zswap_trees[type];
struct zswap_entry *entry;
struct crypto_comp *tfm;
u8 *src, *dst;
unsigned int dlen;
int ret;
spin_lock(&tree->lock);
entry = zswap_entry_find_get(&tree->rbroot, offset);
if (!entry) {
spin_unlock(&tree->lock);
return -1;
}
spin_unlock(&tree->lock);
dlen = PAGE_SIZE;
src = (u8 *)zpool_map_handle(entry->pool->zpool, entry->handle,
ZPOOL_MM_RO) + sizeof(struct zswap_header);
dst = kmap_atomic(page);
tfm = *get_cpu_ptr(entry->pool->tfm);
ret = crypto_comp_decompress(tfm, src, entry->length, dst, &dlen);
put_cpu_ptr(entry->pool->tfm);
kunmap_atomic(dst);
zpool_unmap_handle(entry->pool->zpool, entry->handle);
BUG_ON(ret);
spin_lock(&tree->lock);
zswap_entry_put(tree, entry);
spin_unlock(&tree->lock);
return 0;
}
static void zswap_frontswap_invalidate_page(unsigned type, pgoff_t offset)
{
struct zswap_tree *tree = zswap_trees[type];
struct zswap_entry *entry;
spin_lock(&tree->lock);
entry = zswap_rb_search(&tree->rbroot, offset);
if (!entry) {
spin_unlock(&tree->lock);
return;
}
zswap_rb_erase(&tree->rbroot, entry);
zswap_entry_put(tree, entry);
spin_unlock(&tree->lock);
}
static void zswap_frontswap_invalidate_area(unsigned type)
{
struct zswap_tree *tree = zswap_trees[type];
struct zswap_entry *entry, *n;
if (!tree)
return;
spin_lock(&tree->lock);
rbtree_postorder_for_each_entry_safe(entry, n, &tree->rbroot, rbnode)
zswap_free_entry(entry);
tree->rbroot = RB_ROOT;
spin_unlock(&tree->lock);
kfree(tree);
zswap_trees[type] = NULL;
}
static void zswap_frontswap_init(unsigned type)
{
struct zswap_tree *tree;
tree = kzalloc(sizeof(struct zswap_tree), GFP_KERNEL);
if (!tree) {
pr_err("alloc failed, zswap disabled for swap type %d\n", type);
return;
}
tree->rbroot = RB_ROOT;
spin_lock_init(&tree->lock);
zswap_trees[type] = tree;
}
static int __init zswap_debugfs_init(void)
{
if (!debugfs_initialized())
return -ENODEV;
zswap_debugfs_root = debugfs_create_dir("zswap", NULL);
if (!zswap_debugfs_root)
return -ENOMEM;
debugfs_create_u64("pool_limit_hit", S_IRUGO,
zswap_debugfs_root, &zswap_pool_limit_hit);
debugfs_create_u64("reject_reclaim_fail", S_IRUGO,
zswap_debugfs_root, &zswap_reject_reclaim_fail);
debugfs_create_u64("reject_alloc_fail", S_IRUGO,
zswap_debugfs_root, &zswap_reject_alloc_fail);
debugfs_create_u64("reject_kmemcache_fail", S_IRUGO,
zswap_debugfs_root, &zswap_reject_kmemcache_fail);
debugfs_create_u64("reject_compress_poor", S_IRUGO,
zswap_debugfs_root, &zswap_reject_compress_poor);
debugfs_create_u64("written_back_pages", S_IRUGO,
zswap_debugfs_root, &zswap_written_back_pages);
debugfs_create_u64("duplicate_entry", S_IRUGO,
zswap_debugfs_root, &zswap_duplicate_entry);
debugfs_create_u64("pool_total_size", S_IRUGO,
zswap_debugfs_root, &zswap_pool_total_size);
debugfs_create_atomic_t("stored_pages", S_IRUGO,
zswap_debugfs_root, &zswap_stored_pages);
return 0;
}
static void __exit zswap_debugfs_exit(void)
{
debugfs_remove_recursive(zswap_debugfs_root);
}
static int __init zswap_debugfs_init(void)
{
return 0;
}
static void __exit zswap_debugfs_exit(void) { }
static int __init init_zswap(void)
{
struct zswap_pool *pool;
int ret;
zswap_init_started = true;
if (zswap_entry_cache_create()) {
pr_err("entry cache creation failed\n");
goto cache_fail;
}
ret = cpuhp_setup_state(CPUHP_MM_ZSWP_MEM_PREPARE, "mm/zswap:prepare",
zswap_dstmem_prepare, zswap_dstmem_dead);
if (ret) {
pr_err("dstmem alloc failed\n");
goto dstmem_fail;
}
ret = cpuhp_setup_state_multi(CPUHP_MM_ZSWP_POOL_PREPARE,
"mm/zswap_pool:prepare",
zswap_cpu_comp_prepare,
zswap_cpu_comp_dead);
if (ret)
goto hp_fail;
pool = __zswap_pool_create_fallback();
if (pool) {
pr_info("loaded using pool %s/%s\n", pool->tfm_name,
zpool_get_type(pool->zpool));
list_add(&pool->list, &zswap_pools);
zswap_has_pool = true;
} else {
pr_err("pool creation failed\n");
zswap_enabled = false;
}
frontswap_register_ops(&zswap_frontswap_ops);
if (zswap_debugfs_init())
pr_warn("debugfs initialization failed\n");
return 0;
hp_fail:
cpuhp_remove_state(CPUHP_MM_ZSWP_MEM_PREPARE);
dstmem_fail:
zswap_entry_cache_destroy();
cache_fail:
zswap_init_failed = true;
zswap_enabled = false;
return -ENOMEM;
}
