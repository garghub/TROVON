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
struct frontswap_ops frontswap_register_ops(struct frontswap_ops *ops)
{
struct frontswap_ops old = frontswap_ops;
frontswap_ops = *ops;
frontswap_enabled = true;
return old;
}
void frontswap_writethrough(bool enable)
{
frontswap_writethrough_enabled = enable;
}
void __frontswap_init(unsigned type)
{
struct swap_info_struct *sis = swap_info[type];
BUG_ON(sis == NULL);
if (sis->frontswap_map == NULL)
return;
if (frontswap_enabled)
(*frontswap_ops.init)(type);
}
int __frontswap_store(struct page *page)
{
int ret = -1, dup = 0;
swp_entry_t entry = { .val = page_private(page), };
int type = swp_type(entry);
struct swap_info_struct *sis = swap_info[type];
pgoff_t offset = swp_offset(entry);
BUG_ON(!PageLocked(page));
BUG_ON(sis == NULL);
if (frontswap_test(sis, offset))
dup = 1;
ret = (*frontswap_ops.store)(type, offset, page);
if (ret == 0) {
frontswap_set(sis, offset);
inc_frontswap_succ_stores();
if (!dup)
atomic_inc(&sis->frontswap_pages);
} else if (dup) {
frontswap_clear(sis, offset);
atomic_dec(&sis->frontswap_pages);
inc_frontswap_failed_stores();
} else
inc_frontswap_failed_stores();
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
if (frontswap_test(sis, offset))
ret = (*frontswap_ops.load)(type, offset, page);
if (ret == 0)
inc_frontswap_loads();
return ret;
}
void __frontswap_invalidate_page(unsigned type, pgoff_t offset)
{
struct swap_info_struct *sis = swap_info[type];
BUG_ON(sis == NULL);
if (frontswap_test(sis, offset)) {
(*frontswap_ops.invalidate_page)(type, offset);
atomic_dec(&sis->frontswap_pages);
frontswap_clear(sis, offset);
inc_frontswap_invalidates();
}
}
void __frontswap_invalidate_area(unsigned type)
{
struct swap_info_struct *sis = swap_info[type];
BUG_ON(sis == NULL);
if (sis->frontswap_map == NULL)
return;
(*frontswap_ops.invalidate_area)(type);
atomic_set(&sis->frontswap_pages, 0);
memset(sis->frontswap_map, 0, sis->max / sizeof(long));
}
void frontswap_shrink(unsigned long target_pages)
{
struct swap_info_struct *si = NULL;
int si_frontswap_pages;
unsigned long total_pages = 0, total_pages_to_unuse;
unsigned long pages = 0, pages_to_unuse = 0;
int type;
bool locked = false;
spin_lock(&swap_lock);
locked = true;
total_pages = 0;
for (type = swap_list.head; type >= 0; type = si->next) {
si = swap_info[type];
total_pages += atomic_read(&si->frontswap_pages);
}
if (total_pages <= target_pages)
goto out;
total_pages_to_unuse = total_pages - target_pages;
for (type = swap_list.head; type >= 0; type = si->next) {
si = swap_info[type];
si_frontswap_pages = atomic_read(&si->frontswap_pages);
if (total_pages_to_unuse < si_frontswap_pages)
pages = pages_to_unuse = total_pages_to_unuse;
else {
pages = si_frontswap_pages;
pages_to_unuse = 0;
}
if (security_vm_enough_memory_mm(current->mm, pages))
continue;
vm_unacct_memory(pages);
break;
}
if (type < 0)
goto out;
locked = false;
spin_unlock(&swap_lock);
try_to_unuse(type, true, pages_to_unuse);
out:
if (locked)
spin_unlock(&swap_lock);
return;
}
unsigned long frontswap_curr_pages(void)
{
int type;
unsigned long totalpages = 0;
struct swap_info_struct *si = NULL;
spin_lock(&swap_lock);
for (type = swap_list.head; type >= 0; type = si->next) {
si = swap_info[type];
totalpages += atomic_read(&si->frontswap_pages);
}
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
