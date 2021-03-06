unsigned long total_swapcache_pages(void)
{
int i;
unsigned long ret = 0;
for (i = 0; i < MAX_SWAPFILES; i++)
ret += swapper_spaces[i].nrpages;
return ret;
}
void show_swap_cache_info(void)
{
printk("%lu pages in swap cache\n", total_swapcache_pages());
printk("Swap cache stats: add %lu, delete %lu, find %lu/%lu\n",
swap_cache_info.add_total, swap_cache_info.del_total,
swap_cache_info.find_success, swap_cache_info.find_total);
printk("Free swap = %ldkB\n",
get_nr_swap_pages() << (PAGE_SHIFT - 10));
printk("Total swap = %lukB\n", total_swap_pages << (PAGE_SHIFT - 10));
}
static int __add_to_swap_cache(struct page *page, swp_entry_t entry)
{
int error;
struct address_space *address_space;
VM_BUG_ON(!PageLocked(page));
VM_BUG_ON(PageSwapCache(page));
VM_BUG_ON(!PageSwapBacked(page));
page_cache_get(page);
SetPageSwapCache(page);
set_page_private(page, entry.val);
address_space = swap_address_space(entry);
spin_lock_irq(&address_space->tree_lock);
error = radix_tree_insert(&address_space->page_tree,
entry.val, page);
if (likely(!error)) {
address_space->nrpages++;
__inc_zone_page_state(page, NR_FILE_PAGES);
INC_CACHE_INFO(add_total);
}
spin_unlock_irq(&address_space->tree_lock);
if (unlikely(error)) {
VM_BUG_ON(error == -EEXIST);
set_page_private(page, 0UL);
ClearPageSwapCache(page);
page_cache_release(page);
}
return error;
}
int add_to_swap_cache(struct page *page, swp_entry_t entry, gfp_t gfp_mask)
{
int error;
error = radix_tree_preload(gfp_mask);
if (!error) {
error = __add_to_swap_cache(page, entry);
radix_tree_preload_end();
}
return error;
}
void __delete_from_swap_cache(struct page *page)
{
swp_entry_t entry;
struct address_space *address_space;
VM_BUG_ON(!PageLocked(page));
VM_BUG_ON(!PageSwapCache(page));
VM_BUG_ON(PageWriteback(page));
entry.val = page_private(page);
address_space = swap_address_space(entry);
radix_tree_delete(&address_space->page_tree, page_private(page));
set_page_private(page, 0);
ClearPageSwapCache(page);
address_space->nrpages--;
__dec_zone_page_state(page, NR_FILE_PAGES);
INC_CACHE_INFO(del_total);
}
int add_to_swap(struct page *page)
{
swp_entry_t entry;
int err;
VM_BUG_ON(!PageLocked(page));
VM_BUG_ON(!PageUptodate(page));
entry = get_swap_page();
if (!entry.val)
return 0;
if (unlikely(PageTransHuge(page)))
if (unlikely(split_huge_page(page))) {
swapcache_free(entry, NULL);
return 0;
}
err = add_to_swap_cache(page, entry,
__GFP_HIGH|__GFP_NOMEMALLOC|__GFP_NOWARN);
if (!err) {
SetPageDirty(page);
return 1;
} else {
swapcache_free(entry, NULL);
return 0;
}
}
void delete_from_swap_cache(struct page *page)
{
swp_entry_t entry;
struct address_space *address_space;
entry.val = page_private(page);
address_space = swap_address_space(entry);
spin_lock_irq(&address_space->tree_lock);
__delete_from_swap_cache(page);
spin_unlock_irq(&address_space->tree_lock);
swapcache_free(entry, page);
page_cache_release(page);
}
static inline void free_swap_cache(struct page *page)
{
if (PageSwapCache(page) && !page_mapped(page) && trylock_page(page)) {
try_to_free_swap(page);
unlock_page(page);
}
}
void free_page_and_swap_cache(struct page *page)
{
free_swap_cache(page);
page_cache_release(page);
}
void free_pages_and_swap_cache(struct page **pages, int nr)
{
struct page **pagep = pages;
lru_add_drain();
while (nr) {
int todo = min(nr, PAGEVEC_SIZE);
int i;
for (i = 0; i < todo; i++)
free_swap_cache(pagep[i]);
release_pages(pagep, todo, 0);
pagep += todo;
nr -= todo;
}
}
struct page * lookup_swap_cache(swp_entry_t entry)
{
struct page *page;
page = find_get_page(swap_address_space(entry), entry.val);
if (page)
INC_CACHE_INFO(find_success);
INC_CACHE_INFO(find_total);
return page;
}
struct page *read_swap_cache_async(swp_entry_t entry, gfp_t gfp_mask,
struct vm_area_struct *vma, unsigned long addr)
{
struct page *found_page, *new_page = NULL;
int err;
do {
found_page = find_get_page(swap_address_space(entry),
entry.val);
if (found_page)
break;
if (!new_page) {
new_page = alloc_page_vma(gfp_mask, vma, addr);
if (!new_page)
break;
}
err = radix_tree_preload(gfp_mask & GFP_KERNEL);
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
swap_readpage(new_page);
return new_page;
}
radix_tree_preload_end();
ClearPageSwapBacked(new_page);
__clear_page_locked(new_page);
swapcache_free(entry, NULL);
} while (err != -ENOMEM);
if (new_page)
page_cache_release(new_page);
return found_page;
}
struct page *swapin_readahead(swp_entry_t entry, gfp_t gfp_mask,
struct vm_area_struct *vma, unsigned long addr)
{
struct page *page;
unsigned long offset = swp_offset(entry);
unsigned long start_offset, end_offset;
unsigned long mask = (1UL << page_cluster) - 1;
struct blk_plug plug;
start_offset = offset & ~mask;
end_offset = offset | mask;
if (!start_offset)
start_offset++;
blk_start_plug(&plug);
for (offset = start_offset; offset <= end_offset ; offset++) {
page = read_swap_cache_async(swp_entry(swp_type(entry), offset),
gfp_mask, vma, addr);
if (!page)
continue;
page_cache_release(page);
}
blk_finish_plug(&plug);
lru_add_drain();
return read_swap_cache_async(entry, gfp_mask, vma, addr);
}
