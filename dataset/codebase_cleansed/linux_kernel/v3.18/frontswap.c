static inline void inc_frontswap_loads(void) {
frontswap_loads++;
}
static inline void inc_frontswap_succ_stores(void) {
frontswap_succ_stores++;
}
static inline void inc_frontswap_failed_stores(void) {
frontswap_failed_stores++;
}
static inline void inc_frontswap_invalidates(void) {
frontswap_invalidates++;
}
static inline void inc_frontswap_loads(void) { }
static inline void inc_frontswap_succ_stores(void) { }
static inline void inc_frontswap_failed_stores(void) { }
static inline void inc_frontswap_invalidates(void) { }
struct frontswap_ops *frontswap_register_ops(struct frontswap_ops *ops)
{
struct frontswap_ops *old = frontswap_ops;
int i;
for (i = 0; i < MAX_SWAPFILES; i++) {
if (test_and_clear_bit(i, need_init)) {
struct swap_info_struct *sis = swap_info[i];
if (!sis->frontswap_map)
return ERR_PTR(-EINVAL);
ops->init(i);
}
}
barrier();
frontswap_ops = ops;
return old;
}
void frontswap_writethrough(bool enable)
{
frontswap_writethrough_enabled = enable;
}
void frontswap_tmem_exclusive_gets(bool enable)
{
frontswap_tmem_exclusive_gets_enabled = enable;
}
void __frontswap_init(unsigned type, unsigned long *map)
{
struct swap_info_struct *sis = swap_info[type];
BUG_ON(sis == NULL);
if (WARN_ON(!map))
return;
frontswap_map_set(sis, map);
if (frontswap_ops)
frontswap_ops->init(type);
else {
BUG_ON(type > MAX_SWAPFILES);
set_bit(type, need_init);
}
}
bool __frontswap_test(struct swap_info_struct *sis,
pgoff_t offset)
{
bool ret = false;
if (frontswap_ops && sis->frontswap_map)
ret = test_bit(offset, sis->frontswap_map);
return ret;
}
static inline void __frontswap_clear(struct swap_info_struct *sis,
pgoff_t offset)
{
clear_bit(offset, sis->frontswap_map);
atomic_dec(&sis->frontswap_pages);
}
int __frontswap_store(struct page *page)
{
int ret = -1, dup = 0;
swp_entry_t entry = { .val = page_private(page), };
int type = swp_type(entry);
struct swap_info_struct *sis = swap_info[type];
pgoff_t offset = swp_offset(entry);
if (!frontswap_ops)
return ret;
BUG_ON(!PageLocked(page));
BUG_ON(sis == NULL);
if (__frontswap_test(sis, offset))
dup = 1;
ret = frontswap_ops->store(type, offset, page);
if (ret == 0) {
set_bit(offset, sis->frontswap_map);
inc_frontswap_succ_stores();
if (!dup)
atomic_inc(&sis->frontswap_pages);
} else {
inc_frontswap_failed_stores();
if (dup) {
__frontswap_clear(sis, offset);
frontswap_ops->invalidate_page(type, offset);
}
}
if (frontswap_writethrough_enabled)
ret = -1;
return ret;
}
int __frontswap_load(struct page *page)
{
int ret = -1;
swp_entry_t entry = { .val = page_private(page), };
int type = swp_type(entry);
struct swap_info_struct *sis = swap_info[type];
pgoff_t offset = swp_offset(entry);
BUG_ON(!PageLocked(page));
BUG_ON(sis == NULL);
if (__frontswap_test(sis, offset))
ret = frontswap_ops->load(type, offset, page);
if (ret == 0) {
inc_frontswap_loads();
if (frontswap_tmem_exclusive_gets_enabled) {
SetPageDirty(page);
__frontswap_clear(sis, offset);
}
}
return ret;
}
void __frontswap_invalidate_page(unsigned type, pgoff_t offset)
{
struct swap_info_struct *sis = swap_info[type];
BUG_ON(sis == NULL);
if (__frontswap_test(sis, offset)) {
frontswap_ops->invalidate_page(type, offset);
__frontswap_clear(sis, offset);
inc_frontswap_invalidates();
}
}
void __frontswap_invalidate_area(unsigned type)
{
struct swap_info_struct *sis = swap_info[type];
if (frontswap_ops) {
BUG_ON(sis == NULL);
if (sis->frontswap_map == NULL)
return;
frontswap_ops->invalidate_area(type);
atomic_set(&sis->frontswap_pages, 0);
bitmap_zero(sis->frontswap_map, sis->max);
}
clear_bit(type, need_init);
}
static unsigned long __frontswap_curr_pages(void)
{
unsigned long totalpages = 0;
struct swap_info_struct *si = NULL;
assert_spin_locked(&swap_lock);
plist_for_each_entry(si, &swap_active_head, list)
totalpages += atomic_read(&si->frontswap_pages);
return totalpages;
}
static int __frontswap_unuse_pages(unsigned long total, unsigned long *unused,
int *swapid)
{
int ret = -EINVAL;
struct swap_info_struct *si = NULL;
int si_frontswap_pages;
unsigned long total_pages_to_unuse = total;
unsigned long pages = 0, pages_to_unuse = 0;
assert_spin_locked(&swap_lock);
plist_for_each_entry(si, &swap_active_head, list) {
si_frontswap_pages = atomic_read(&si->frontswap_pages);
if (total_pages_to_unuse < si_frontswap_pages) {
pages = pages_to_unuse = total_pages_to_unuse;
} else {
pages = si_frontswap_pages;
pages_to_unuse = 0;
}
if (security_vm_enough_memory_mm(current->mm, pages)) {
ret = -ENOMEM;
continue;
}
vm_unacct_memory(pages);
*unused = pages_to_unuse;
*swapid = si->type;
ret = 0;
break;
}
return ret;
}
static int __frontswap_shrink(unsigned long target_pages,
unsigned long *pages_to_unuse,
int *type)
{
unsigned long total_pages = 0, total_pages_to_unuse;
assert_spin_locked(&swap_lock);
total_pages = __frontswap_curr_pages();
if (total_pages <= target_pages) {
*pages_to_unuse = 0;
return 1;
}
total_pages_to_unuse = total_pages - target_pages;
return __frontswap_unuse_pages(total_pages_to_unuse, pages_to_unuse, type);
}
void frontswap_shrink(unsigned long target_pages)
{
unsigned long pages_to_unuse = 0;
int uninitialized_var(type), ret;
spin_lock(&swap_lock);
ret = __frontswap_shrink(target_pages, &pages_to_unuse, &type);
spin_unlock(&swap_lock);
if (ret == 0)
try_to_unuse(type, true, pages_to_unuse);
return;
}
unsigned long frontswap_curr_pages(void)
{
unsigned long totalpages = 0;
spin_lock(&swap_lock);
totalpages = __frontswap_curr_pages();
spin_unlock(&swap_lock);
return totalpages;
}
static int __init init_frontswap(void)
{
#ifdef CONFIG_DEBUG_FS
struct dentry *root = debugfs_create_dir("frontswap", NULL);
if (root == NULL)
return -ENXIO;
debugfs_create_u64("loads", S_IRUGO, root, &frontswap_loads);
debugfs_create_u64("succ_stores", S_IRUGO, root, &frontswap_succ_stores);
debugfs_create_u64("failed_stores", S_IRUGO, root,
&frontswap_failed_stores);
debugfs_create_u64("invalidates", S_IRUGO,
root, &frontswap_invalidates);
#endif
return 0;
}
