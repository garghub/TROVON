static int zswap_comp_op(enum comp_op op, const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen)
{
struct crypto_comp *tfm;
int ret;
tfm = *per_cpu_ptr(zswap_comp_pcpu_tfms, get_cpu());
switch (op) {
case ZSWAP_COMPOP_COMPRESS:
ret = crypto_comp_compress(tfm, src, slen, dst, dlen);
break;
case ZSWAP_COMPOP_DECOMPRESS:
ret = crypto_comp_decompress(tfm, src, slen, dst, dlen);
break;
default:
ret = -EINVAL;
}
put_cpu();
return ret;
}
static int __init zswap_comp_init(void)
{
if (!crypto_has_comp(zswap_compressor, 0, 0)) {
pr_info("%s compressor not available\n", zswap_compressor);
zswap_compressor = ZSWAP_COMPRESSOR_DEFAULT;
if (!crypto_has_comp(zswap_compressor, 0, 0))
return -ENODEV;
}
pr_info("using %s compressor\n", zswap_compressor);
zswap_comp_pcpu_tfms = alloc_percpu(struct crypto_comp *);
if (!zswap_comp_pcpu_tfms)
return -ENOMEM;
return 0;
}
static void __init zswap_comp_exit(void)
{
free_percpu(zswap_comp_pcpu_tfms);
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
zpool_free(zswap_pool, entry->handle);
zswap_entry_cache_free(entry);
atomic_dec(&zswap_stored_pages);
zswap_pool_total_size = zpool_get_total_size(zswap_pool);
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
struct zswap_entry *entry = NULL;
entry = zswap_rb_search(root, offset);
if (entry)
zswap_entry_get(entry);
return entry;
}
static int __zswap_cpu_notifier(unsigned long action, unsigned long cpu)
{
struct crypto_comp *tfm;
u8 *dst;
switch (action) {
case CPU_UP_PREPARE:
tfm = crypto_alloc_comp(zswap_compressor, 0, 0);
if (IS_ERR(tfm)) {
pr_err("can't allocate compressor transform\n");
return NOTIFY_BAD;
}
*per_cpu_ptr(zswap_comp_pcpu_tfms, cpu) = tfm;
dst = kmalloc_node(PAGE_SIZE * 2, GFP_KERNEL, cpu_to_node(cpu));
if (!dst) {
pr_err("can't allocate compressor buffer\n");
crypto_free_comp(tfm);
*per_cpu_ptr(zswap_comp_pcpu_tfms, cpu) = NULL;
return NOTIFY_BAD;
}
per_cpu(zswap_dstmem, cpu) = dst;
break;
case CPU_DEAD:
case CPU_UP_CANCELED:
tfm = *per_cpu_ptr(zswap_comp_pcpu_tfms, cpu);
if (tfm) {
crypto_free_comp(tfm);
*per_cpu_ptr(zswap_comp_pcpu_tfms, cpu) = NULL;
}
dst = per_cpu(zswap_dstmem, cpu);
kfree(dst);
per_cpu(zswap_dstmem, cpu) = NULL;
break;
default:
break;
}
return NOTIFY_OK;
}
static int zswap_cpu_notifier(struct notifier_block *nb,
unsigned long action, void *pcpu)
{
unsigned long cpu = (unsigned long)pcpu;
return __zswap_cpu_notifier(action, cpu);
}
static int __init zswap_cpu_init(void)
{
unsigned long cpu;
cpu_notifier_register_begin();
for_each_online_cpu(cpu)
if (__zswap_cpu_notifier(CPU_UP_PREPARE, cpu) != NOTIFY_OK)
goto cleanup;
__register_cpu_notifier(&zswap_cpu_notifier_block);
cpu_notifier_register_done();
return 0;
cleanup:
for_each_online_cpu(cpu)
__zswap_cpu_notifier(CPU_UP_CANCELED, cpu);
cpu_notifier_register_done();
return -ENOMEM;
}
static bool zswap_is_full(void)
{
return totalram_pages * zswap_max_pool_percent / 100 <
DIV_ROUND_UP(zswap_pool_total_size, PAGE_SIZE);
}
static int zswap_get_swap_cache_page(swp_entry_t entry,
struct page **retpage)
{
struct page *found_page, *new_page = NULL;
struct address_space *swapper_space = swap_address_space(entry);
int err;
*retpage = NULL;
do {
found_page = find_get_page(swapper_space, entry.val);
if (found_page)
break;
if (!new_page) {
new_page = alloc_page(GFP_KERNEL);
if (!new_page)
break;
}
err = radix_tree_preload(GFP_KERNEL);
if (err)
break;
err = swapcache_prepare(entry);
if (err == -EEXIST) {
radix_tree_preload_end();
continue;
}
if (err) {
radix_tree_preload_end();
break;
}
__set_page_locked(new_page);
SetPageSwapBacked(new_page);
err = __add_to_swap_cache(new_page, entry);
if (likely(!err)) {
radix_tree_preload_end();
lru_cache_add_anon(new_page);
*retpage = new_page;
return ZSWAP_SWAPCACHE_NEW;
}
radix_tree_preload_end();
ClearPageSwapBacked(new_page);
__clear_page_locked(new_page);
swapcache_free(entry);
} while (err != -ENOMEM);
if (new_page)
page_cache_release(new_page);
if (!found_page)
return ZSWAP_SWAPCACHE_FAIL;
*retpage = found_page;
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
page_cache_release(page);
ret = -EEXIST;
goto fail;
case ZSWAP_SWAPCACHE_NEW:
dlen = PAGE_SIZE;
src = (u8 *)zpool_map_handle(zswap_pool, entry->handle,
ZPOOL_MM_RO) + sizeof(struct zswap_header);
dst = kmap_atomic(page);
ret = zswap_comp_op(ZSWAP_COMPOP_DECOMPRESS, src,
entry->length, dst, &dlen);
kunmap_atomic(dst);
zpool_unmap_handle(zswap_pool, entry->handle);
BUG_ON(ret);
BUG_ON(dlen != PAGE_SIZE);
SetPageUptodate(page);
}
SetPageReclaim(page);
__swap_writepage(page, &wbc, end_swap_bio_write);
page_cache_release(page);
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
static int zswap_frontswap_store(unsigned type, pgoff_t offset,
struct page *page)
{
struct zswap_tree *tree = zswap_trees[type];
struct zswap_entry *entry, *dupentry;
int ret;
unsigned int dlen = PAGE_SIZE, len;
unsigned long handle;
char *buf;
u8 *src, *dst;
struct zswap_header *zhdr;
if (!tree) {
ret = -ENODEV;
goto reject;
}
if (zswap_is_full()) {
zswap_pool_limit_hit++;
if (zpool_shrink(zswap_pool, 1, NULL)) {
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
dst = get_cpu_var(zswap_dstmem);
src = kmap_atomic(page);
ret = zswap_comp_op(ZSWAP_COMPOP_COMPRESS, src, PAGE_SIZE, dst, &dlen);
kunmap_atomic(src);
if (ret) {
ret = -EINVAL;
goto freepage;
}
len = dlen + sizeof(struct zswap_header);
ret = zpool_malloc(zswap_pool, len, __GFP_NORETRY | __GFP_NOWARN,
&handle);
if (ret == -ENOSPC) {
zswap_reject_compress_poor++;
goto freepage;
}
if (ret) {
zswap_reject_alloc_fail++;
goto freepage;
}
zhdr = zpool_map_handle(zswap_pool, handle, ZPOOL_MM_RW);
zhdr->swpentry = swp_entry(type, offset);
buf = (u8 *)(zhdr + 1);
memcpy(buf, dst, dlen);
zpool_unmap_handle(zswap_pool, handle);
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
zswap_pool_total_size = zpool_get_total_size(zswap_pool);
return 0;
freepage:
put_cpu_var(zswap_dstmem);
zswap_entry_cache_free(entry);
reject:
return ret;
}
static int zswap_frontswap_load(unsigned type, pgoff_t offset,
struct page *page)
{
struct zswap_tree *tree = zswap_trees[type];
struct zswap_entry *entry;
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
src = (u8 *)zpool_map_handle(zswap_pool, entry->handle,
ZPOOL_MM_RO) + sizeof(struct zswap_header);
dst = kmap_atomic(page);
ret = zswap_comp_op(ZSWAP_COMPOP_DECOMPRESS, src, entry->length,
dst, &dlen);
kunmap_atomic(dst);
zpool_unmap_handle(zswap_pool, entry->handle);
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
gfp_t gfp = __GFP_NORETRY | __GFP_NOWARN;
if (!zswap_enabled)
return 0;
pr_info("loading zswap\n");
zswap_pool = zpool_create_pool(zswap_zpool_type, "zswap", gfp,
&zswap_zpool_ops);
if (!zswap_pool && strcmp(zswap_zpool_type, ZSWAP_ZPOOL_DEFAULT)) {
pr_info("%s zpool not available\n", zswap_zpool_type);
zswap_zpool_type = ZSWAP_ZPOOL_DEFAULT;
zswap_pool = zpool_create_pool(zswap_zpool_type, "zswap", gfp,
&zswap_zpool_ops);
}
if (!zswap_pool) {
pr_err("%s zpool not available\n", zswap_zpool_type);
pr_err("zpool creation failed\n");
goto error;
}
pr_info("using %s pool\n", zswap_zpool_type);
if (zswap_entry_cache_create()) {
pr_err("entry cache creation failed\n");
goto cachefail;
}
if (zswap_comp_init()) {
pr_err("compressor initialization failed\n");
goto compfail;
}
if (zswap_cpu_init()) {
pr_err("per-cpu initialization failed\n");
goto pcpufail;
}
frontswap_register_ops(&zswap_frontswap_ops);
if (zswap_debugfs_init())
pr_warn("debugfs initialization failed\n");
return 0;
pcpufail:
zswap_comp_exit();
compfail:
zswap_entry_cache_destroy();
cachefail:
zpool_destroy_pool(zswap_pool);
error:
return -ENOMEM;
}
