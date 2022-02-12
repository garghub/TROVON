unsigned long total_swapcache_pages(void)
{
unsigned int i, j, nr;
unsigned long ret = 0;
struct address_space *spaces;
rcu_read_lock();
for (i = 0; i < MAX_SWAPFILES; i++) {
nr = nr_swapper_spaces[i];
spaces = rcu_dereference(swapper_spaces[i]);
if (!nr || !spaces)
continue;
for (j = 0; j < nr; j++)
ret += spaces[j].nrpages;
}
rcu_read_unlock();
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
int __add_to_swap_cache(struct page *page, swp_entry_t entry)
{
int error, i, nr = hpage_nr_pages(page);
struct address_space *address_space;
pgoff_t idx = swp_offset(entry);
VM_BUG_ON_PAGE(!PageLocked(page), page);
VM_BUG_ON_PAGE(PageSwapCache(page), page);
VM_BUG_ON_PAGE(!PageSwapBacked(page), page);
page_ref_add(page, nr);
SetPageSwapCache(page);
address_space = swap_address_space(entry);
spin_lock_irq(&address_space->tree_lock);
for (i = 0; i < nr; i++) {
set_page_private(page + i, entry.val + i);
error = radix_tree_insert(&address_space->page_tree,
idx + i, page + i);
if (unlikely(error))
break;
}
if (likely(!error)) {
address_space->nrpages += nr;
__mod_node_page_state(page_pgdat(page), NR_FILE_PAGES, nr);
ADD_CACHE_INFO(add_total, nr);
} else {
VM_BUG_ON(error == -EEXIST);
set_page_private(page + i, 0UL);
while (i--) {
radix_tree_delete(&address_space->page_tree, idx + i);
set_page_private(page + i, 0UL);
}
ClearPageSwapCache(page);
page_ref_sub(page, nr);
}
spin_unlock_irq(&address_space->tree_lock);
return error;
}
int add_to_swap_cache(struct page *page, swp_entry_t entry, gfp_t gfp_mask)
{
int error;
error = radix_tree_maybe_preload_order(gfp_mask, compound_order(page));
if (!error) {
error = __add_to_swap_cache(page, entry);
radix_tree_preload_end();
}
return error;
}
void __delete_from_swap_cache(struct page *page)
{
struct address_space *address_space;
int i, nr = hpage_nr_pages(page);
swp_entry_t entry;
pgoff_t idx;
VM_BUG_ON_PAGE(!PageLocked(page), page);
VM_BUG_ON_PAGE(!PageSwapCache(page), page);
VM_BUG_ON_PAGE(PageWriteback(page), page);
entry.val = page_private(page);
address_space = swap_address_space(entry);
idx = swp_offset(entry);
for (i = 0; i < nr; i++) {
radix_tree_delete(&address_space->page_tree, idx + i);
set_page_private(page + i, 0);
}
ClearPageSwapCache(page);
address_space->nrpages -= nr;
__mod_node_page_state(page_pgdat(page), NR_FILE_PAGES, -nr);
ADD_CACHE_INFO(del_total, nr);
}
int add_to_swap(struct page *page)
{
swp_entry_t entry;
int err;
VM_BUG_ON_PAGE(!PageLocked(page), page);
VM_BUG_ON_PAGE(!PageUptodate(page), page);
entry = get_swap_page(page);
if (!entry.val)
return 0;
if (mem_cgroup_try_charge_swap(page, entry))
goto fail;
err = add_to_swap_cache(page, entry,
__GFP_HIGH|__GFP_NOMEMALLOC|__GFP_NOWARN);
if (err)
goto fail;
set_page_dirty(page);
return 1;
fail:
put_swap_page(page, entry);
return 0;
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
put_swap_page(page, entry);
page_ref_sub(page, hpage_nr_pages(page));
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
if (!is_huge_zero_page(page))
put_page(page);
}
void free_pages_and_swap_cache(struct page **pages, int nr)
{
struct page **pagep = pages;
int i;
lru_add_drain();
for (i = 0; i < nr; i++)
free_swap_cache(pagep[i]);
release_pages(pagep, nr, false);
}
struct page *lookup_swap_cache(swp_entry_t entry, struct vm_area_struct *vma,
unsigned long addr)
{
struct page *page;
unsigned long ra_info;
int win, hits, readahead;
page = find_get_page(swap_address_space(entry), swp_offset(entry));
INC_CACHE_INFO(find_total);
if (page) {
INC_CACHE_INFO(find_success);
if (unlikely(PageTransCompound(page)))
return page;
readahead = TestClearPageReadahead(page);
if (vma) {
ra_info = GET_SWAP_RA_VAL(vma);
win = SWAP_RA_WIN(ra_info);
hits = SWAP_RA_HITS(ra_info);
if (readahead)
hits = min_t(int, hits + 1, SWAP_RA_HITS_MAX);
atomic_long_set(&vma->swap_readahead_info,
SWAP_RA_VAL(addr, win, hits));
}
if (readahead) {
count_vm_event(SWAP_RA_HIT);
if (!vma)
atomic_inc(&swapin_readahead_hits);
}
}
return page;
}
struct page *__read_swap_cache_async(swp_entry_t entry, gfp_t gfp_mask,
struct vm_area_struct *vma, unsigned long addr,
bool *new_page_allocated)
{
struct page *found_page, *new_page = NULL;
struct address_space *swapper_space = swap_address_space(entry);
int err;
*new_page_allocated = false;
do {
found_page = find_get_page(swapper_space, swp_offset(entry));
if (found_page)
break;
if (!__swp_swapcount(entry) && swap_slot_cache_enabled)
break;
if (!new_page) {
new_page = alloc_page_vma(gfp_mask, vma, addr);
if (!new_page)
break;
}
err = radix_tree_maybe_preload(gfp_mask & GFP_KERNEL);
if (err)
break;
err = swapcache_prepare(entry);
if (err == -EEXIST) {
radix_tree_preload_end();
cond_resched();
continue;
}
if (err) {
radix_tree_preload_end();
break;
}
__SetPageLocked(new_page);
__SetPageSwapBacked(new_page);
err = __add_to_swap_cache(new_page, entry);
if (likely(!err)) {
radix_tree_preload_end();
lru_cache_add_anon(new_page);
*new_page_allocated = true;
return new_page;
}
radix_tree_preload_end();
__ClearPageLocked(new_page);
put_swap_page(new_page, entry);
} while (err != -ENOMEM);
if (new_page)
put_page(new_page);
return found_page;
}
struct page *read_swap_cache_async(swp_entry_t entry, gfp_t gfp_mask,
struct vm_area_struct *vma, unsigned long addr, bool do_poll)
{
bool page_was_allocated;
struct page *retpage = __read_swap_cache_async(entry, gfp_mask,
vma, addr, &page_was_allocated);
if (page_was_allocated)
swap_readpage(retpage, do_poll);
return retpage;
}
static unsigned int __swapin_nr_pages(unsigned long prev_offset,
unsigned long offset,
int hits,
int max_pages,
int prev_win)
{
unsigned int pages, last_ra;
pages = hits + 2;
if (pages == 2) {
if (offset != prev_offset + 1 && offset != prev_offset - 1)
pages = 1;
} else {
unsigned int roundup = 4;
while (roundup < pages)
roundup <<= 1;
pages = roundup;
}
if (pages > max_pages)
pages = max_pages;
last_ra = prev_win / 2;
if (pages < last_ra)
pages = last_ra;
return pages;
}
static unsigned long swapin_nr_pages(unsigned long offset)
{
static unsigned long prev_offset;
unsigned int hits, pages, max_pages;
static atomic_t last_readahead_pages;
max_pages = 1 << READ_ONCE(page_cluster);
if (max_pages <= 1)
return 1;
hits = atomic_xchg(&swapin_readahead_hits, 0);
pages = __swapin_nr_pages(prev_offset, offset, hits, max_pages,
atomic_read(&last_readahead_pages));
if (!hits)
prev_offset = offset;
atomic_set(&last_readahead_pages, pages);
return pages;
}
struct page *swapin_readahead(swp_entry_t entry, gfp_t gfp_mask,
struct vm_area_struct *vma, unsigned long addr)
{
struct page *page;
unsigned long entry_offset = swp_offset(entry);
unsigned long offset = entry_offset;
unsigned long start_offset, end_offset;
unsigned long mask;
struct blk_plug plug;
bool do_poll = true, page_allocated;
mask = swapin_nr_pages(offset) - 1;
if (!mask)
goto skip;
do_poll = false;
start_offset = offset & ~mask;
end_offset = offset | mask;
if (!start_offset)
start_offset++;
blk_start_plug(&plug);
for (offset = start_offset; offset <= end_offset ; offset++) {
page = __read_swap_cache_async(
swp_entry(swp_type(entry), offset),
gfp_mask, vma, addr, &page_allocated);
if (!page)
continue;
if (page_allocated) {
swap_readpage(page, false);
if (offset != entry_offset &&
likely(!PageTransCompound(page))) {
SetPageReadahead(page);
count_vm_event(SWAP_RA);
}
}
put_page(page);
}
blk_finish_plug(&plug);
lru_add_drain();
skip:
return read_swap_cache_async(entry, gfp_mask, vma, addr, do_poll);
}
int init_swap_address_space(unsigned int type, unsigned long nr_pages)
{
struct address_space *spaces, *space;
unsigned int i, nr;
nr = DIV_ROUND_UP(nr_pages, SWAP_ADDRESS_SPACE_PAGES);
spaces = kvzalloc(sizeof(struct address_space) * nr, GFP_KERNEL);
if (!spaces)
return -ENOMEM;
for (i = 0; i < nr; i++) {
space = spaces + i;
INIT_RADIX_TREE(&space->page_tree, GFP_ATOMIC|__GFP_NOWARN);
atomic_set(&space->i_mmap_writable, 0);
space->a_ops = &swap_aops;
mapping_set_no_writeback_tags(space);
spin_lock_init(&space->tree_lock);
}
nr_swapper_spaces[type] = nr;
rcu_assign_pointer(swapper_spaces[type], spaces);
return 0;
}
void exit_swap_address_space(unsigned int type)
{
struct address_space *spaces;
spaces = swapper_spaces[type];
nr_swapper_spaces[type] = 0;
rcu_assign_pointer(swapper_spaces[type], NULL);
synchronize_rcu();
kvfree(spaces);
}
static inline void swap_ra_clamp_pfn(struct vm_area_struct *vma,
unsigned long faddr,
unsigned long lpfn,
unsigned long rpfn,
unsigned long *start,
unsigned long *end)
{
*start = max3(lpfn, PFN_DOWN(vma->vm_start),
PFN_DOWN(faddr & PMD_MASK));
*end = min3(rpfn, PFN_DOWN(vma->vm_end),
PFN_DOWN((faddr & PMD_MASK) + PMD_SIZE));
}
struct page *swap_readahead_detect(struct vm_fault *vmf,
struct vma_swap_readahead *swap_ra)
{
struct vm_area_struct *vma = vmf->vma;
unsigned long swap_ra_info;
struct page *page;
swp_entry_t entry;
unsigned long faddr, pfn, fpfn;
unsigned long start, end;
pte_t *pte;
unsigned int max_win, hits, prev_win, win, left;
#ifndef CONFIG_64BIT
pte_t *tpte;
#endif
max_win = 1 << min_t(unsigned int, READ_ONCE(page_cluster),
SWAP_RA_ORDER_CEILING);
if (max_win == 1) {
swap_ra->win = 1;
return NULL;
}
faddr = vmf->address;
entry = pte_to_swp_entry(vmf->orig_pte);
if ((unlikely(non_swap_entry(entry))))
return NULL;
page = lookup_swap_cache(entry, vma, faddr);
if (page)
return page;
fpfn = PFN_DOWN(faddr);
swap_ra_info = GET_SWAP_RA_VAL(vma);
pfn = PFN_DOWN(SWAP_RA_ADDR(swap_ra_info));
prev_win = SWAP_RA_WIN(swap_ra_info);
hits = SWAP_RA_HITS(swap_ra_info);
swap_ra->win = win = __swapin_nr_pages(pfn, fpfn, hits,
max_win, prev_win);
atomic_long_set(&vma->swap_readahead_info,
SWAP_RA_VAL(faddr, win, 0));
if (win == 1)
return NULL;
if (fpfn == pfn + 1)
swap_ra_clamp_pfn(vma, faddr, fpfn, fpfn + win, &start, &end);
else if (pfn == fpfn + 1)
swap_ra_clamp_pfn(vma, faddr, fpfn - win + 1, fpfn + 1,
&start, &end);
else {
left = (win - 1) / 2;
swap_ra_clamp_pfn(vma, faddr, fpfn - left, fpfn + win - left,
&start, &end);
}
swap_ra->nr_pte = end - start;
swap_ra->offset = fpfn - start;
pte = vmf->pte - swap_ra->offset;
#ifdef CONFIG_64BIT
swap_ra->ptes = pte;
#else
tpte = swap_ra->ptes;
for (pfn = start; pfn != end; pfn++)
*tpte++ = *pte++;
#endif
return NULL;
}
struct page *do_swap_page_readahead(swp_entry_t fentry, gfp_t gfp_mask,
struct vm_fault *vmf,
struct vma_swap_readahead *swap_ra)
{
struct blk_plug plug;
struct vm_area_struct *vma = vmf->vma;
struct page *page;
pte_t *pte, pentry;
swp_entry_t entry;
unsigned int i;
bool page_allocated;
if (swap_ra->win == 1)
goto skip;
blk_start_plug(&plug);
for (i = 0, pte = swap_ra->ptes; i < swap_ra->nr_pte;
i++, pte++) {
pentry = *pte;
if (pte_none(pentry))
continue;
if (pte_present(pentry))
continue;
entry = pte_to_swp_entry(pentry);
if (unlikely(non_swap_entry(entry)))
continue;
page = __read_swap_cache_async(entry, gfp_mask, vma,
vmf->address, &page_allocated);
if (!page)
continue;
if (page_allocated) {
swap_readpage(page, false);
if (i != swap_ra->offset &&
likely(!PageTransCompound(page))) {
SetPageReadahead(page);
count_vm_event(SWAP_RA);
}
}
put_page(page);
}
blk_finish_plug(&plug);
lru_add_drain();
skip:
return read_swap_cache_async(fentry, gfp_mask, vma, vmf->address,
swap_ra->win == 1);
}
static ssize_t vma_ra_enabled_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%s\n", swap_vma_readahead ? "true" : "false");
}
static ssize_t vma_ra_enabled_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
if (!strncmp(buf, "true", 4) || !strncmp(buf, "1", 1))
swap_vma_readahead = true;
else if (!strncmp(buf, "false", 5) || !strncmp(buf, "0", 1))
swap_vma_readahead = false;
else
return -EINVAL;
return count;
}
static int __init swap_init_sysfs(void)
{
int err;
struct kobject *swap_kobj;
swap_kobj = kobject_create_and_add("swap", mm_kobj);
if (!swap_kobj) {
pr_err("failed to create swap kobject\n");
return -ENOMEM;
}
err = sysfs_create_group(swap_kobj, &swap_attr_group);
if (err) {
pr_err("failed to register swap group\n");
goto delete_obj;
}
return 0;
delete_obj:
kobject_put(swap_kobj);
return err;
}
