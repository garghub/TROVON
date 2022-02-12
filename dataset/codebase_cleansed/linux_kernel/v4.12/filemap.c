static int page_cache_tree_insert(struct address_space *mapping,
struct page *page, void **shadowp)
{
struct radix_tree_node *node;
void **slot;
int error;
error = __radix_tree_create(&mapping->page_tree, page->index, 0,
&node, &slot);
if (error)
return error;
if (*slot) {
void *p;
p = radix_tree_deref_slot_protected(slot, &mapping->tree_lock);
if (!radix_tree_exceptional_entry(p))
return -EEXIST;
mapping->nrexceptional--;
if (!dax_mapping(mapping)) {
if (shadowp)
*shadowp = p;
} else {
WARN_ON_ONCE(p !=
dax_radix_locked_entry(0, RADIX_DAX_EMPTY));
dax_wake_mapping_entry_waiter(mapping, page->index, p,
true);
}
}
__radix_tree_replace(&mapping->page_tree, node, slot, page,
workingset_update_node, mapping);
mapping->nrpages++;
return 0;
}
static void page_cache_tree_delete(struct address_space *mapping,
struct page *page, void *shadow)
{
int i, nr;
nr = PageHuge(page) ? 1 : hpage_nr_pages(page);
VM_BUG_ON_PAGE(!PageLocked(page), page);
VM_BUG_ON_PAGE(PageTail(page), page);
VM_BUG_ON_PAGE(nr != 1 && shadow, page);
for (i = 0; i < nr; i++) {
struct radix_tree_node *node;
void **slot;
__radix_tree_lookup(&mapping->page_tree, page->index + i,
&node, &slot);
VM_BUG_ON_PAGE(!node && nr != 1, page);
radix_tree_clear_tags(&mapping->page_tree, node, slot);
__radix_tree_replace(&mapping->page_tree, node, slot, shadow,
workingset_update_node, mapping);
}
if (shadow) {
mapping->nrexceptional += nr;
smp_wmb();
}
mapping->nrpages -= nr;
}
void __delete_from_page_cache(struct page *page, void *shadow)
{
struct address_space *mapping = page->mapping;
int nr = hpage_nr_pages(page);
trace_mm_filemap_delete_from_page_cache(page);
if (PageUptodate(page) && PageMappedToDisk(page))
cleancache_put_page(page);
else
cleancache_invalidate_page(mapping, page);
VM_BUG_ON_PAGE(PageTail(page), page);
VM_BUG_ON_PAGE(page_mapped(page), page);
if (!IS_ENABLED(CONFIG_DEBUG_VM) && unlikely(page_mapped(page))) {
int mapcount;
pr_alert("BUG: Bad page cache in process %s pfn:%05lx\n",
current->comm, page_to_pfn(page));
dump_page(page, "still mapped when deleted");
dump_stack();
add_taint(TAINT_BAD_PAGE, LOCKDEP_NOW_UNRELIABLE);
mapcount = page_mapcount(page);
if (mapping_exiting(mapping) &&
page_count(page) >= mapcount + 2) {
page_mapcount_reset(page);
page_ref_sub(page, mapcount);
}
}
page_cache_tree_delete(mapping, page, shadow);
page->mapping = NULL;
if (!PageHuge(page))
__mod_node_page_state(page_pgdat(page), NR_FILE_PAGES, -nr);
if (PageSwapBacked(page)) {
__mod_node_page_state(page_pgdat(page), NR_SHMEM, -nr);
if (PageTransHuge(page))
__dec_node_page_state(page, NR_SHMEM_THPS);
} else {
VM_BUG_ON_PAGE(PageTransHuge(page) && !PageHuge(page), page);
}
if (WARN_ON_ONCE(PageDirty(page)))
account_page_cleaned(page, mapping, inode_to_wb(mapping->host));
}
void delete_from_page_cache(struct page *page)
{
struct address_space *mapping = page_mapping(page);
unsigned long flags;
void (*freepage)(struct page *);
BUG_ON(!PageLocked(page));
freepage = mapping->a_ops->freepage;
spin_lock_irqsave(&mapping->tree_lock, flags);
__delete_from_page_cache(page, NULL);
spin_unlock_irqrestore(&mapping->tree_lock, flags);
if (freepage)
freepage(page);
if (PageTransHuge(page) && !PageHuge(page)) {
page_ref_sub(page, HPAGE_PMD_NR);
VM_BUG_ON_PAGE(page_count(page) <= 0, page);
} else {
put_page(page);
}
}
int filemap_check_errors(struct address_space *mapping)
{
int ret = 0;
if (test_bit(AS_ENOSPC, &mapping->flags) &&
test_and_clear_bit(AS_ENOSPC, &mapping->flags))
ret = -ENOSPC;
if (test_bit(AS_EIO, &mapping->flags) &&
test_and_clear_bit(AS_EIO, &mapping->flags))
ret = -EIO;
return ret;
}
int __filemap_fdatawrite_range(struct address_space *mapping, loff_t start,
loff_t end, int sync_mode)
{
int ret;
struct writeback_control wbc = {
.sync_mode = sync_mode,
.nr_to_write = LONG_MAX,
.range_start = start,
.range_end = end,
};
if (!mapping_cap_writeback_dirty(mapping))
return 0;
wbc_attach_fdatawrite_inode(&wbc, mapping->host);
ret = do_writepages(mapping, &wbc);
wbc_detach_inode(&wbc);
return ret;
}
static inline int __filemap_fdatawrite(struct address_space *mapping,
int sync_mode)
{
return __filemap_fdatawrite_range(mapping, 0, LLONG_MAX, sync_mode);
}
int filemap_fdatawrite(struct address_space *mapping)
{
return __filemap_fdatawrite(mapping, WB_SYNC_ALL);
}
int filemap_fdatawrite_range(struct address_space *mapping, loff_t start,
loff_t end)
{
return __filemap_fdatawrite_range(mapping, start, end, WB_SYNC_ALL);
}
int filemap_flush(struct address_space *mapping)
{
return __filemap_fdatawrite(mapping, WB_SYNC_NONE);
}
static int __filemap_fdatawait_range(struct address_space *mapping,
loff_t start_byte, loff_t end_byte)
{
pgoff_t index = start_byte >> PAGE_SHIFT;
pgoff_t end = end_byte >> PAGE_SHIFT;
struct pagevec pvec;
int nr_pages;
int ret = 0;
if (end_byte < start_byte)
goto out;
pagevec_init(&pvec, 0);
while ((index <= end) &&
(nr_pages = pagevec_lookup_tag(&pvec, mapping, &index,
PAGECACHE_TAG_WRITEBACK,
min(end - index, (pgoff_t)PAGEVEC_SIZE-1) + 1)) != 0) {
unsigned i;
for (i = 0; i < nr_pages; i++) {
struct page *page = pvec.pages[i];
if (page->index > end)
continue;
wait_on_page_writeback(page);
if (TestClearPageError(page))
ret = -EIO;
}
pagevec_release(&pvec);
cond_resched();
}
out:
return ret;
}
int filemap_fdatawait_range(struct address_space *mapping, loff_t start_byte,
loff_t end_byte)
{
int ret, ret2;
ret = __filemap_fdatawait_range(mapping, start_byte, end_byte);
ret2 = filemap_check_errors(mapping);
if (!ret)
ret = ret2;
return ret;
}
void filemap_fdatawait_keep_errors(struct address_space *mapping)
{
loff_t i_size = i_size_read(mapping->host);
if (i_size == 0)
return;
__filemap_fdatawait_range(mapping, 0, i_size - 1);
}
int filemap_fdatawait(struct address_space *mapping)
{
loff_t i_size = i_size_read(mapping->host);
if (i_size == 0)
return 0;
return filemap_fdatawait_range(mapping, 0, i_size - 1);
}
int filemap_write_and_wait(struct address_space *mapping)
{
int err = 0;
if ((!dax_mapping(mapping) && mapping->nrpages) ||
(dax_mapping(mapping) && mapping->nrexceptional)) {
err = filemap_fdatawrite(mapping);
if (err != -EIO) {
int err2 = filemap_fdatawait(mapping);
if (!err)
err = err2;
}
} else {
err = filemap_check_errors(mapping);
}
return err;
}
int filemap_write_and_wait_range(struct address_space *mapping,
loff_t lstart, loff_t lend)
{
int err = 0;
if ((!dax_mapping(mapping) && mapping->nrpages) ||
(dax_mapping(mapping) && mapping->nrexceptional)) {
err = __filemap_fdatawrite_range(mapping, lstart, lend,
WB_SYNC_ALL);
if (err != -EIO) {
int err2 = filemap_fdatawait_range(mapping,
lstart, lend);
if (!err)
err = err2;
}
} else {
err = filemap_check_errors(mapping);
}
return err;
}
int replace_page_cache_page(struct page *old, struct page *new, gfp_t gfp_mask)
{
int error;
VM_BUG_ON_PAGE(!PageLocked(old), old);
VM_BUG_ON_PAGE(!PageLocked(new), new);
VM_BUG_ON_PAGE(new->mapping, new);
error = radix_tree_preload(gfp_mask & ~__GFP_HIGHMEM);
if (!error) {
struct address_space *mapping = old->mapping;
void (*freepage)(struct page *);
unsigned long flags;
pgoff_t offset = old->index;
freepage = mapping->a_ops->freepage;
get_page(new);
new->mapping = mapping;
new->index = offset;
spin_lock_irqsave(&mapping->tree_lock, flags);
__delete_from_page_cache(old, NULL);
error = page_cache_tree_insert(mapping, new, NULL);
BUG_ON(error);
if (!PageHuge(new))
__inc_node_page_state(new, NR_FILE_PAGES);
if (PageSwapBacked(new))
__inc_node_page_state(new, NR_SHMEM);
spin_unlock_irqrestore(&mapping->tree_lock, flags);
mem_cgroup_migrate(old, new);
radix_tree_preload_end();
if (freepage)
freepage(old);
put_page(old);
}
return error;
}
static int __add_to_page_cache_locked(struct page *page,
struct address_space *mapping,
pgoff_t offset, gfp_t gfp_mask,
void **shadowp)
{
int huge = PageHuge(page);
struct mem_cgroup *memcg;
int error;
VM_BUG_ON_PAGE(!PageLocked(page), page);
VM_BUG_ON_PAGE(PageSwapBacked(page), page);
if (!huge) {
error = mem_cgroup_try_charge(page, current->mm,
gfp_mask, &memcg, false);
if (error)
return error;
}
error = radix_tree_maybe_preload(gfp_mask & ~__GFP_HIGHMEM);
if (error) {
if (!huge)
mem_cgroup_cancel_charge(page, memcg, false);
return error;
}
get_page(page);
page->mapping = mapping;
page->index = offset;
spin_lock_irq(&mapping->tree_lock);
error = page_cache_tree_insert(mapping, page, shadowp);
radix_tree_preload_end();
if (unlikely(error))
goto err_insert;
if (!huge)
__inc_node_page_state(page, NR_FILE_PAGES);
spin_unlock_irq(&mapping->tree_lock);
if (!huge)
mem_cgroup_commit_charge(page, memcg, false, false);
trace_mm_filemap_add_to_page_cache(page);
return 0;
err_insert:
page->mapping = NULL;
spin_unlock_irq(&mapping->tree_lock);
if (!huge)
mem_cgroup_cancel_charge(page, memcg, false);
put_page(page);
return error;
}
int add_to_page_cache_locked(struct page *page, struct address_space *mapping,
pgoff_t offset, gfp_t gfp_mask)
{
return __add_to_page_cache_locked(page, mapping, offset,
gfp_mask, NULL);
}
int add_to_page_cache_lru(struct page *page, struct address_space *mapping,
pgoff_t offset, gfp_t gfp_mask)
{
void *shadow = NULL;
int ret;
__SetPageLocked(page);
ret = __add_to_page_cache_locked(page, mapping, offset,
gfp_mask, &shadow);
if (unlikely(ret))
__ClearPageLocked(page);
else {
if (!(gfp_mask & __GFP_WRITE) &&
shadow && workingset_refault(shadow)) {
SetPageActive(page);
workingset_activation(page);
} else
ClearPageActive(page);
lru_cache_add(page);
}
return ret;
}
struct page *__page_cache_alloc(gfp_t gfp)
{
int n;
struct page *page;
if (cpuset_do_page_mem_spread()) {
unsigned int cpuset_mems_cookie;
do {
cpuset_mems_cookie = read_mems_allowed_begin();
n = cpuset_mem_spread_node();
page = __alloc_pages_node(n, gfp, 0);
} while (!page && read_mems_allowed_retry(cpuset_mems_cookie));
return page;
}
return alloc_pages(gfp, 0);
}
static wait_queue_head_t *page_waitqueue(struct page *page)
{
return &page_wait_table[hash_ptr(page, PAGE_WAIT_TABLE_BITS)];
}
void __init pagecache_init(void)
{
int i;
for (i = 0; i < PAGE_WAIT_TABLE_SIZE; i++)
init_waitqueue_head(&page_wait_table[i]);
page_writeback_init();
}
static int wake_page_function(wait_queue_t *wait, unsigned mode, int sync, void *arg)
{
struct wait_page_key *key = arg;
struct wait_page_queue *wait_page
= container_of(wait, struct wait_page_queue, wait);
if (wait_page->page != key->page)
return 0;
key->page_match = 1;
if (wait_page->bit_nr != key->bit_nr)
return 0;
if (test_bit(key->bit_nr, &key->page->flags))
return 0;
return autoremove_wake_function(wait, mode, sync, key);
}
static void wake_up_page_bit(struct page *page, int bit_nr)
{
wait_queue_head_t *q = page_waitqueue(page);
struct wait_page_key key;
unsigned long flags;
key.page = page;
key.bit_nr = bit_nr;
key.page_match = 0;
spin_lock_irqsave(&q->lock, flags);
__wake_up_locked_key(q, TASK_NORMAL, &key);
if (!waitqueue_active(q) || !key.page_match) {
ClearPageWaiters(page);
}
spin_unlock_irqrestore(&q->lock, flags);
}
static void wake_up_page(struct page *page, int bit)
{
if (!PageWaiters(page))
return;
wake_up_page_bit(page, bit);
}
static inline int wait_on_page_bit_common(wait_queue_head_t *q,
struct page *page, int bit_nr, int state, bool lock)
{
struct wait_page_queue wait_page;
wait_queue_t *wait = &wait_page.wait;
int ret = 0;
init_wait(wait);
wait->func = wake_page_function;
wait_page.page = page;
wait_page.bit_nr = bit_nr;
for (;;) {
spin_lock_irq(&q->lock);
if (likely(list_empty(&wait->task_list))) {
if (lock)
__add_wait_queue_tail_exclusive(q, wait);
else
__add_wait_queue(q, wait);
SetPageWaiters(page);
}
set_current_state(state);
spin_unlock_irq(&q->lock);
if (likely(test_bit(bit_nr, &page->flags))) {
io_schedule();
if (unlikely(signal_pending_state(state, current))) {
ret = -EINTR;
break;
}
}
if (lock) {
if (!test_and_set_bit_lock(bit_nr, &page->flags))
break;
} else {
if (!test_bit(bit_nr, &page->flags))
break;
}
}
finish_wait(q, wait);
return ret;
}
void wait_on_page_bit(struct page *page, int bit_nr)
{
wait_queue_head_t *q = page_waitqueue(page);
wait_on_page_bit_common(q, page, bit_nr, TASK_UNINTERRUPTIBLE, false);
}
int wait_on_page_bit_killable(struct page *page, int bit_nr)
{
wait_queue_head_t *q = page_waitqueue(page);
return wait_on_page_bit_common(q, page, bit_nr, TASK_KILLABLE, false);
}
void add_page_wait_queue(struct page *page, wait_queue_t *waiter)
{
wait_queue_head_t *q = page_waitqueue(page);
unsigned long flags;
spin_lock_irqsave(&q->lock, flags);
__add_wait_queue(q, waiter);
SetPageWaiters(page);
spin_unlock_irqrestore(&q->lock, flags);
}
static inline bool clear_bit_unlock_is_negative_byte(long nr, volatile void *mem)
{
clear_bit_unlock(nr, mem);
return test_bit(PG_waiters, mem);
}
void unlock_page(struct page *page)
{
BUILD_BUG_ON(PG_waiters != 7);
page = compound_head(page);
VM_BUG_ON_PAGE(!PageLocked(page), page);
if (clear_bit_unlock_is_negative_byte(PG_locked, &page->flags))
wake_up_page_bit(page, PG_locked);
}
void end_page_writeback(struct page *page)
{
if (PageReclaim(page)) {
ClearPageReclaim(page);
rotate_reclaimable_page(page);
}
if (!test_clear_page_writeback(page))
BUG();
smp_mb__after_atomic();
wake_up_page(page, PG_writeback);
}
void page_endio(struct page *page, bool is_write, int err)
{
if (!is_write) {
if (!err) {
SetPageUptodate(page);
} else {
ClearPageUptodate(page);
SetPageError(page);
}
unlock_page(page);
} else {
if (err) {
struct address_space *mapping;
SetPageError(page);
mapping = page_mapping(page);
if (mapping)
mapping_set_error(mapping, err);
}
end_page_writeback(page);
}
}
void __lock_page(struct page *__page)
{
struct page *page = compound_head(__page);
wait_queue_head_t *q = page_waitqueue(page);
wait_on_page_bit_common(q, page, PG_locked, TASK_UNINTERRUPTIBLE, true);
}
int __lock_page_killable(struct page *__page)
{
struct page *page = compound_head(__page);
wait_queue_head_t *q = page_waitqueue(page);
return wait_on_page_bit_common(q, page, PG_locked, TASK_KILLABLE, true);
}
int __lock_page_or_retry(struct page *page, struct mm_struct *mm,
unsigned int flags)
{
if (flags & FAULT_FLAG_ALLOW_RETRY) {
if (flags & FAULT_FLAG_RETRY_NOWAIT)
return 0;
up_read(&mm->mmap_sem);
if (flags & FAULT_FLAG_KILLABLE)
wait_on_page_locked_killable(page);
else
wait_on_page_locked(page);
return 0;
} else {
if (flags & FAULT_FLAG_KILLABLE) {
int ret;
ret = __lock_page_killable(page);
if (ret) {
up_read(&mm->mmap_sem);
return 0;
}
} else
__lock_page(page);
return 1;
}
}
pgoff_t page_cache_next_hole(struct address_space *mapping,
pgoff_t index, unsigned long max_scan)
{
unsigned long i;
for (i = 0; i < max_scan; i++) {
struct page *page;
page = radix_tree_lookup(&mapping->page_tree, index);
if (!page || radix_tree_exceptional_entry(page))
break;
index++;
if (index == 0)
break;
}
return index;
}
pgoff_t page_cache_prev_hole(struct address_space *mapping,
pgoff_t index, unsigned long max_scan)
{
unsigned long i;
for (i = 0; i < max_scan; i++) {
struct page *page;
page = radix_tree_lookup(&mapping->page_tree, index);
if (!page || radix_tree_exceptional_entry(page))
break;
index--;
if (index == ULONG_MAX)
break;
}
return index;
}
struct page *find_get_entry(struct address_space *mapping, pgoff_t offset)
{
void **pagep;
struct page *head, *page;
rcu_read_lock();
repeat:
page = NULL;
pagep = radix_tree_lookup_slot(&mapping->page_tree, offset);
if (pagep) {
page = radix_tree_deref_slot(pagep);
if (unlikely(!page))
goto out;
if (radix_tree_exception(page)) {
if (radix_tree_deref_retry(page))
goto repeat;
goto out;
}
head = compound_head(page);
if (!page_cache_get_speculative(head))
goto repeat;
if (compound_head(page) != head) {
put_page(head);
goto repeat;
}
if (unlikely(page != *pagep)) {
put_page(head);
goto repeat;
}
}
out:
rcu_read_unlock();
return page;
}
struct page *find_lock_entry(struct address_space *mapping, pgoff_t offset)
{
struct page *page;
repeat:
page = find_get_entry(mapping, offset);
if (page && !radix_tree_exception(page)) {
lock_page(page);
if (unlikely(page_mapping(page) != mapping)) {
unlock_page(page);
put_page(page);
goto repeat;
}
VM_BUG_ON_PAGE(page_to_pgoff(page) != offset, page);
}
return page;
}
struct page *pagecache_get_page(struct address_space *mapping, pgoff_t offset,
int fgp_flags, gfp_t gfp_mask)
{
struct page *page;
repeat:
page = find_get_entry(mapping, offset);
if (radix_tree_exceptional_entry(page))
page = NULL;
if (!page)
goto no_page;
if (fgp_flags & FGP_LOCK) {
if (fgp_flags & FGP_NOWAIT) {
if (!trylock_page(page)) {
put_page(page);
return NULL;
}
} else {
lock_page(page);
}
if (unlikely(page->mapping != mapping)) {
unlock_page(page);
put_page(page);
goto repeat;
}
VM_BUG_ON_PAGE(page->index != offset, page);
}
if (page && (fgp_flags & FGP_ACCESSED))
mark_page_accessed(page);
no_page:
if (!page && (fgp_flags & FGP_CREAT)) {
int err;
if ((fgp_flags & FGP_WRITE) && mapping_cap_account_dirty(mapping))
gfp_mask |= __GFP_WRITE;
if (fgp_flags & FGP_NOFS)
gfp_mask &= ~__GFP_FS;
page = __page_cache_alloc(gfp_mask);
if (!page)
return NULL;
if (WARN_ON_ONCE(!(fgp_flags & FGP_LOCK)))
fgp_flags |= FGP_LOCK;
if (fgp_flags & FGP_ACCESSED)
__SetPageReferenced(page);
err = add_to_page_cache_lru(page, mapping, offset,
gfp_mask & GFP_RECLAIM_MASK);
if (unlikely(err)) {
put_page(page);
page = NULL;
if (err == -EEXIST)
goto repeat;
}
}
return page;
}
unsigned find_get_entries(struct address_space *mapping,
pgoff_t start, unsigned int nr_entries,
struct page **entries, pgoff_t *indices)
{
void **slot;
unsigned int ret = 0;
struct radix_tree_iter iter;
if (!nr_entries)
return 0;
rcu_read_lock();
radix_tree_for_each_slot(slot, &mapping->page_tree, &iter, start) {
struct page *head, *page;
repeat:
page = radix_tree_deref_slot(slot);
if (unlikely(!page))
continue;
if (radix_tree_exception(page)) {
if (radix_tree_deref_retry(page)) {
slot = radix_tree_iter_retry(&iter);
continue;
}
goto export;
}
head = compound_head(page);
if (!page_cache_get_speculative(head))
goto repeat;
if (compound_head(page) != head) {
put_page(head);
goto repeat;
}
if (unlikely(page != *slot)) {
put_page(head);
goto repeat;
}
export:
indices[ret] = iter.index;
entries[ret] = page;
if (++ret == nr_entries)
break;
}
rcu_read_unlock();
return ret;
}
unsigned find_get_pages(struct address_space *mapping, pgoff_t start,
unsigned int nr_pages, struct page **pages)
{
struct radix_tree_iter iter;
void **slot;
unsigned ret = 0;
if (unlikely(!nr_pages))
return 0;
rcu_read_lock();
radix_tree_for_each_slot(slot, &mapping->page_tree, &iter, start) {
struct page *head, *page;
repeat:
page = radix_tree_deref_slot(slot);
if (unlikely(!page))
continue;
if (radix_tree_exception(page)) {
if (radix_tree_deref_retry(page)) {
slot = radix_tree_iter_retry(&iter);
continue;
}
continue;
}
head = compound_head(page);
if (!page_cache_get_speculative(head))
goto repeat;
if (compound_head(page) != head) {
put_page(head);
goto repeat;
}
if (unlikely(page != *slot)) {
put_page(head);
goto repeat;
}
pages[ret] = page;
if (++ret == nr_pages)
break;
}
rcu_read_unlock();
return ret;
}
unsigned find_get_pages_contig(struct address_space *mapping, pgoff_t index,
unsigned int nr_pages, struct page **pages)
{
struct radix_tree_iter iter;
void **slot;
unsigned int ret = 0;
if (unlikely(!nr_pages))
return 0;
rcu_read_lock();
radix_tree_for_each_contig(slot, &mapping->page_tree, &iter, index) {
struct page *head, *page;
repeat:
page = radix_tree_deref_slot(slot);
if (unlikely(!page))
break;
if (radix_tree_exception(page)) {
if (radix_tree_deref_retry(page)) {
slot = radix_tree_iter_retry(&iter);
continue;
}
break;
}
head = compound_head(page);
if (!page_cache_get_speculative(head))
goto repeat;
if (compound_head(page) != head) {
put_page(head);
goto repeat;
}
if (unlikely(page != *slot)) {
put_page(head);
goto repeat;
}
if (page->mapping == NULL || page_to_pgoff(page) != iter.index) {
put_page(page);
break;
}
pages[ret] = page;
if (++ret == nr_pages)
break;
}
rcu_read_unlock();
return ret;
}
unsigned find_get_pages_tag(struct address_space *mapping, pgoff_t *index,
int tag, unsigned int nr_pages, struct page **pages)
{
struct radix_tree_iter iter;
void **slot;
unsigned ret = 0;
if (unlikely(!nr_pages))
return 0;
rcu_read_lock();
radix_tree_for_each_tagged(slot, &mapping->page_tree,
&iter, *index, tag) {
struct page *head, *page;
repeat:
page = radix_tree_deref_slot(slot);
if (unlikely(!page))
continue;
if (radix_tree_exception(page)) {
if (radix_tree_deref_retry(page)) {
slot = radix_tree_iter_retry(&iter);
continue;
}
continue;
}
head = compound_head(page);
if (!page_cache_get_speculative(head))
goto repeat;
if (compound_head(page) != head) {
put_page(head);
goto repeat;
}
if (unlikely(page != *slot)) {
put_page(head);
goto repeat;
}
pages[ret] = page;
if (++ret == nr_pages)
break;
}
rcu_read_unlock();
if (ret)
*index = pages[ret - 1]->index + 1;
return ret;
}
unsigned find_get_entries_tag(struct address_space *mapping, pgoff_t start,
int tag, unsigned int nr_entries,
struct page **entries, pgoff_t *indices)
{
void **slot;
unsigned int ret = 0;
struct radix_tree_iter iter;
if (!nr_entries)
return 0;
rcu_read_lock();
radix_tree_for_each_tagged(slot, &mapping->page_tree,
&iter, start, tag) {
struct page *head, *page;
repeat:
page = radix_tree_deref_slot(slot);
if (unlikely(!page))
continue;
if (radix_tree_exception(page)) {
if (radix_tree_deref_retry(page)) {
slot = radix_tree_iter_retry(&iter);
continue;
}
goto export;
}
head = compound_head(page);
if (!page_cache_get_speculative(head))
goto repeat;
if (compound_head(page) != head) {
put_page(head);
goto repeat;
}
if (unlikely(page != *slot)) {
put_page(head);
goto repeat;
}
export:
indices[ret] = iter.index;
entries[ret] = page;
if (++ret == nr_entries)
break;
}
rcu_read_unlock();
return ret;
}
static void shrink_readahead_size_eio(struct file *filp,
struct file_ra_state *ra)
{
ra->ra_pages /= 4;
}
static ssize_t do_generic_file_read(struct file *filp, loff_t *ppos,
struct iov_iter *iter, ssize_t written)
{
struct address_space *mapping = filp->f_mapping;
struct inode *inode = mapping->host;
struct file_ra_state *ra = &filp->f_ra;
pgoff_t index;
pgoff_t last_index;
pgoff_t prev_index;
unsigned long offset;
unsigned int prev_offset;
int error = 0;
if (unlikely(*ppos >= inode->i_sb->s_maxbytes))
return 0;
iov_iter_truncate(iter, inode->i_sb->s_maxbytes);
index = *ppos >> PAGE_SHIFT;
prev_index = ra->prev_pos >> PAGE_SHIFT;
prev_offset = ra->prev_pos & (PAGE_SIZE-1);
last_index = (*ppos + iter->count + PAGE_SIZE-1) >> PAGE_SHIFT;
offset = *ppos & ~PAGE_MASK;
for (;;) {
struct page *page;
pgoff_t end_index;
loff_t isize;
unsigned long nr, ret;
cond_resched();
find_page:
if (fatal_signal_pending(current)) {
error = -EINTR;
goto out;
}
page = find_get_page(mapping, index);
if (!page) {
page_cache_sync_readahead(mapping,
ra, filp,
index, last_index - index);
page = find_get_page(mapping, index);
if (unlikely(page == NULL))
goto no_cached_page;
}
if (PageReadahead(page)) {
page_cache_async_readahead(mapping,
ra, filp, page,
index, last_index - index);
}
if (!PageUptodate(page)) {
error = wait_on_page_locked_killable(page);
if (unlikely(error))
goto readpage_error;
if (PageUptodate(page))
goto page_ok;
if (inode->i_blkbits == PAGE_SHIFT ||
!mapping->a_ops->is_partially_uptodate)
goto page_not_up_to_date;
if (unlikely(iter->type & ITER_PIPE))
goto page_not_up_to_date;
if (!trylock_page(page))
goto page_not_up_to_date;
if (!page->mapping)
goto page_not_up_to_date_locked;
if (!mapping->a_ops->is_partially_uptodate(page,
offset, iter->count))
goto page_not_up_to_date_locked;
unlock_page(page);
}
page_ok:
isize = i_size_read(inode);
end_index = (isize - 1) >> PAGE_SHIFT;
if (unlikely(!isize || index > end_index)) {
put_page(page);
goto out;
}
nr = PAGE_SIZE;
if (index == end_index) {
nr = ((isize - 1) & ~PAGE_MASK) + 1;
if (nr <= offset) {
put_page(page);
goto out;
}
}
nr = nr - offset;
if (mapping_writably_mapped(mapping))
flush_dcache_page(page);
if (prev_index != index || offset != prev_offset)
mark_page_accessed(page);
prev_index = index;
ret = copy_page_to_iter(page, offset, nr, iter);
offset += ret;
index += offset >> PAGE_SHIFT;
offset &= ~PAGE_MASK;
prev_offset = offset;
put_page(page);
written += ret;
if (!iov_iter_count(iter))
goto out;
if (ret < nr) {
error = -EFAULT;
goto out;
}
continue;
page_not_up_to_date:
error = lock_page_killable(page);
if (unlikely(error))
goto readpage_error;
page_not_up_to_date_locked:
if (!page->mapping) {
unlock_page(page);
put_page(page);
continue;
}
if (PageUptodate(page)) {
unlock_page(page);
goto page_ok;
}
readpage:
ClearPageError(page);
error = mapping->a_ops->readpage(filp, page);
if (unlikely(error)) {
if (error == AOP_TRUNCATED_PAGE) {
put_page(page);
error = 0;
goto find_page;
}
goto readpage_error;
}
if (!PageUptodate(page)) {
error = lock_page_killable(page);
if (unlikely(error))
goto readpage_error;
if (!PageUptodate(page)) {
if (page->mapping == NULL) {
unlock_page(page);
put_page(page);
goto find_page;
}
unlock_page(page);
shrink_readahead_size_eio(filp, ra);
error = -EIO;
goto readpage_error;
}
unlock_page(page);
}
goto page_ok;
readpage_error:
put_page(page);
goto out;
no_cached_page:
page = page_cache_alloc_cold(mapping);
if (!page) {
error = -ENOMEM;
goto out;
}
error = add_to_page_cache_lru(page, mapping, index,
mapping_gfp_constraint(mapping, GFP_KERNEL));
if (error) {
put_page(page);
if (error == -EEXIST) {
error = 0;
goto find_page;
}
goto out;
}
goto readpage;
}
out:
ra->prev_pos = prev_index;
ra->prev_pos <<= PAGE_SHIFT;
ra->prev_pos |= prev_offset;
*ppos = ((loff_t)index << PAGE_SHIFT) + offset;
file_accessed(filp);
return written ? written : error;
}
ssize_t
generic_file_read_iter(struct kiocb *iocb, struct iov_iter *iter)
{
struct file *file = iocb->ki_filp;
ssize_t retval = 0;
size_t count = iov_iter_count(iter);
if (!count)
goto out;
if (iocb->ki_flags & IOCB_DIRECT) {
struct address_space *mapping = file->f_mapping;
struct inode *inode = mapping->host;
loff_t size;
size = i_size_read(inode);
retval = filemap_write_and_wait_range(mapping, iocb->ki_pos,
iocb->ki_pos + count - 1);
if (retval < 0)
goto out;
file_accessed(file);
retval = mapping->a_ops->direct_IO(iocb, iter);
if (retval >= 0) {
iocb->ki_pos += retval;
count -= retval;
}
iov_iter_revert(iter, count - iov_iter_count(iter));
if (retval < 0 || !count || iocb->ki_pos >= size ||
IS_DAX(inode))
goto out;
}
retval = do_generic_file_read(file, &iocb->ki_pos, iter, retval);
out:
return retval;
}
static int page_cache_read(struct file *file, pgoff_t offset, gfp_t gfp_mask)
{
struct address_space *mapping = file->f_mapping;
struct page *page;
int ret;
do {
page = __page_cache_alloc(gfp_mask|__GFP_COLD);
if (!page)
return -ENOMEM;
ret = add_to_page_cache_lru(page, mapping, offset, gfp_mask & GFP_KERNEL);
if (ret == 0)
ret = mapping->a_ops->readpage(file, page);
else if (ret == -EEXIST)
ret = 0;
put_page(page);
} while (ret == AOP_TRUNCATED_PAGE);
return ret;
}
static void do_sync_mmap_readahead(struct vm_area_struct *vma,
struct file_ra_state *ra,
struct file *file,
pgoff_t offset)
{
struct address_space *mapping = file->f_mapping;
if (vma->vm_flags & VM_RAND_READ)
return;
if (!ra->ra_pages)
return;
if (vma->vm_flags & VM_SEQ_READ) {
page_cache_sync_readahead(mapping, ra, file, offset,
ra->ra_pages);
return;
}
if (ra->mmap_miss < MMAP_LOTSAMISS * 10)
ra->mmap_miss++;
if (ra->mmap_miss > MMAP_LOTSAMISS)
return;
ra->start = max_t(long, 0, offset - ra->ra_pages / 2);
ra->size = ra->ra_pages;
ra->async_size = ra->ra_pages / 4;
ra_submit(ra, mapping, file);
}
static void do_async_mmap_readahead(struct vm_area_struct *vma,
struct file_ra_state *ra,
struct file *file,
struct page *page,
pgoff_t offset)
{
struct address_space *mapping = file->f_mapping;
if (vma->vm_flags & VM_RAND_READ)
return;
if (ra->mmap_miss > 0)
ra->mmap_miss--;
if (PageReadahead(page))
page_cache_async_readahead(mapping, ra, file,
page, offset, ra->ra_pages);
}
int filemap_fault(struct vm_fault *vmf)
{
int error;
struct file *file = vmf->vma->vm_file;
struct address_space *mapping = file->f_mapping;
struct file_ra_state *ra = &file->f_ra;
struct inode *inode = mapping->host;
pgoff_t offset = vmf->pgoff;
pgoff_t max_off;
struct page *page;
int ret = 0;
max_off = DIV_ROUND_UP(i_size_read(inode), PAGE_SIZE);
if (unlikely(offset >= max_off))
return VM_FAULT_SIGBUS;
page = find_get_page(mapping, offset);
if (likely(page) && !(vmf->flags & FAULT_FLAG_TRIED)) {
do_async_mmap_readahead(vmf->vma, ra, file, page, offset);
} else if (!page) {
do_sync_mmap_readahead(vmf->vma, ra, file, offset);
count_vm_event(PGMAJFAULT);
mem_cgroup_count_vm_event(vmf->vma->vm_mm, PGMAJFAULT);
ret = VM_FAULT_MAJOR;
retry_find:
page = find_get_page(mapping, offset);
if (!page)
goto no_cached_page;
}
if (!lock_page_or_retry(page, vmf->vma->vm_mm, vmf->flags)) {
put_page(page);
return ret | VM_FAULT_RETRY;
}
if (unlikely(page->mapping != mapping)) {
unlock_page(page);
put_page(page);
goto retry_find;
}
VM_BUG_ON_PAGE(page->index != offset, page);
if (unlikely(!PageUptodate(page)))
goto page_not_uptodate;
max_off = DIV_ROUND_UP(i_size_read(inode), PAGE_SIZE);
if (unlikely(offset >= max_off)) {
unlock_page(page);
put_page(page);
return VM_FAULT_SIGBUS;
}
vmf->page = page;
return ret | VM_FAULT_LOCKED;
no_cached_page:
error = page_cache_read(file, offset, vmf->gfp_mask);
if (error >= 0)
goto retry_find;
if (error == -ENOMEM)
return VM_FAULT_OOM;
return VM_FAULT_SIGBUS;
page_not_uptodate:
ClearPageError(page);
error = mapping->a_ops->readpage(file, page);
if (!error) {
wait_on_page_locked(page);
if (!PageUptodate(page))
error = -EIO;
}
put_page(page);
if (!error || error == AOP_TRUNCATED_PAGE)
goto retry_find;
shrink_readahead_size_eio(file, ra);
return VM_FAULT_SIGBUS;
}
void filemap_map_pages(struct vm_fault *vmf,
pgoff_t start_pgoff, pgoff_t end_pgoff)
{
struct radix_tree_iter iter;
void **slot;
struct file *file = vmf->vma->vm_file;
struct address_space *mapping = file->f_mapping;
pgoff_t last_pgoff = start_pgoff;
unsigned long max_idx;
struct page *head, *page;
rcu_read_lock();
radix_tree_for_each_slot(slot, &mapping->page_tree, &iter,
start_pgoff) {
if (iter.index > end_pgoff)
break;
repeat:
page = radix_tree_deref_slot(slot);
if (unlikely(!page))
goto next;
if (radix_tree_exception(page)) {
if (radix_tree_deref_retry(page)) {
slot = radix_tree_iter_retry(&iter);
continue;
}
goto next;
}
head = compound_head(page);
if (!page_cache_get_speculative(head))
goto repeat;
if (compound_head(page) != head) {
put_page(head);
goto repeat;
}
if (unlikely(page != *slot)) {
put_page(head);
goto repeat;
}
if (!PageUptodate(page) ||
PageReadahead(page) ||
PageHWPoison(page))
goto skip;
if (!trylock_page(page))
goto skip;
if (page->mapping != mapping || !PageUptodate(page))
goto unlock;
max_idx = DIV_ROUND_UP(i_size_read(mapping->host), PAGE_SIZE);
if (page->index >= max_idx)
goto unlock;
if (file->f_ra.mmap_miss > 0)
file->f_ra.mmap_miss--;
vmf->address += (iter.index - last_pgoff) << PAGE_SHIFT;
if (vmf->pte)
vmf->pte += iter.index - last_pgoff;
last_pgoff = iter.index;
if (alloc_set_pte(vmf, NULL, page))
goto unlock;
unlock_page(page);
goto next;
unlock:
unlock_page(page);
skip:
put_page(page);
next:
if (pmd_trans_huge(*vmf->pmd))
break;
if (iter.index == end_pgoff)
break;
}
rcu_read_unlock();
}
int filemap_page_mkwrite(struct vm_fault *vmf)
{
struct page *page = vmf->page;
struct inode *inode = file_inode(vmf->vma->vm_file);
int ret = VM_FAULT_LOCKED;
sb_start_pagefault(inode->i_sb);
file_update_time(vmf->vma->vm_file);
lock_page(page);
if (page->mapping != inode->i_mapping) {
unlock_page(page);
ret = VM_FAULT_NOPAGE;
goto out;
}
set_page_dirty(page);
wait_for_stable_page(page);
out:
sb_end_pagefault(inode->i_sb);
return ret;
}
int generic_file_mmap(struct file * file, struct vm_area_struct * vma)
{
struct address_space *mapping = file->f_mapping;
if (!mapping->a_ops->readpage)
return -ENOEXEC;
file_accessed(file);
vma->vm_ops = &generic_file_vm_ops;
return 0;
}
int generic_file_readonly_mmap(struct file *file, struct vm_area_struct *vma)
{
if ((vma->vm_flags & VM_SHARED) && (vma->vm_flags & VM_MAYWRITE))
return -EINVAL;
return generic_file_mmap(file, vma);
}
int generic_file_mmap(struct file * file, struct vm_area_struct * vma)
{
return -ENOSYS;
}
int generic_file_readonly_mmap(struct file * file, struct vm_area_struct * vma)
{
return -ENOSYS;
}
static struct page *wait_on_page_read(struct page *page)
{
if (!IS_ERR(page)) {
wait_on_page_locked(page);
if (!PageUptodate(page)) {
put_page(page);
page = ERR_PTR(-EIO);
}
}
return page;
}
static struct page *do_read_cache_page(struct address_space *mapping,
pgoff_t index,
int (*filler)(void *, struct page *),
void *data,
gfp_t gfp)
{
struct page *page;
int err;
repeat:
page = find_get_page(mapping, index);
if (!page) {
page = __page_cache_alloc(gfp | __GFP_COLD);
if (!page)
return ERR_PTR(-ENOMEM);
err = add_to_page_cache_lru(page, mapping, index, gfp);
if (unlikely(err)) {
put_page(page);
if (err == -EEXIST)
goto repeat;
return ERR_PTR(err);
}
filler:
err = filler(data, page);
if (err < 0) {
put_page(page);
return ERR_PTR(err);
}
page = wait_on_page_read(page);
if (IS_ERR(page))
return page;
goto out;
}
if (PageUptodate(page))
goto out;
wait_on_page_locked(page);
if (PageUptodate(page))
goto out;
lock_page(page);
if (!page->mapping) {
unlock_page(page);
put_page(page);
goto repeat;
}
if (PageUptodate(page)) {
unlock_page(page);
goto out;
}
goto filler;
out:
mark_page_accessed(page);
return page;
}
struct page *read_cache_page(struct address_space *mapping,
pgoff_t index,
int (*filler)(void *, struct page *),
void *data)
{
return do_read_cache_page(mapping, index, filler, data, mapping_gfp_mask(mapping));
}
struct page *read_cache_page_gfp(struct address_space *mapping,
pgoff_t index,
gfp_t gfp)
{
filler_t *filler = (filler_t *)mapping->a_ops->readpage;
return do_read_cache_page(mapping, index, filler, NULL, gfp);
}
inline ssize_t generic_write_checks(struct kiocb *iocb, struct iov_iter *from)
{
struct file *file = iocb->ki_filp;
struct inode *inode = file->f_mapping->host;
unsigned long limit = rlimit(RLIMIT_FSIZE);
loff_t pos;
if (!iov_iter_count(from))
return 0;
if (iocb->ki_flags & IOCB_APPEND)
iocb->ki_pos = i_size_read(inode);
pos = iocb->ki_pos;
if (limit != RLIM_INFINITY) {
if (iocb->ki_pos >= limit) {
send_sig(SIGXFSZ, current, 0);
return -EFBIG;
}
iov_iter_truncate(from, limit - (unsigned long)pos);
}
if (unlikely(pos + iov_iter_count(from) > MAX_NON_LFS &&
!(file->f_flags & O_LARGEFILE))) {
if (pos >= MAX_NON_LFS)
return -EFBIG;
iov_iter_truncate(from, MAX_NON_LFS - (unsigned long)pos);
}
if (unlikely(pos >= inode->i_sb->s_maxbytes))
return -EFBIG;
iov_iter_truncate(from, inode->i_sb->s_maxbytes - pos);
return iov_iter_count(from);
}
int pagecache_write_begin(struct file *file, struct address_space *mapping,
loff_t pos, unsigned len, unsigned flags,
struct page **pagep, void **fsdata)
{
const struct address_space_operations *aops = mapping->a_ops;
return aops->write_begin(file, mapping, pos, len, flags,
pagep, fsdata);
}
int pagecache_write_end(struct file *file, struct address_space *mapping,
loff_t pos, unsigned len, unsigned copied,
struct page *page, void *fsdata)
{
const struct address_space_operations *aops = mapping->a_ops;
return aops->write_end(file, mapping, pos, len, copied, page, fsdata);
}
ssize_t
generic_file_direct_write(struct kiocb *iocb, struct iov_iter *from)
{
struct file *file = iocb->ki_filp;
struct address_space *mapping = file->f_mapping;
struct inode *inode = mapping->host;
loff_t pos = iocb->ki_pos;
ssize_t written;
size_t write_len;
pgoff_t end;
write_len = iov_iter_count(from);
end = (pos + write_len - 1) >> PAGE_SHIFT;
written = filemap_write_and_wait_range(mapping, pos, pos + write_len - 1);
if (written)
goto out;
written = invalidate_inode_pages2_range(mapping,
pos >> PAGE_SHIFT, end);
if (written) {
if (written == -EBUSY)
return 0;
goto out;
}
written = mapping->a_ops->direct_IO(iocb, from);
invalidate_inode_pages2_range(mapping,
pos >> PAGE_SHIFT, end);
if (written > 0) {
pos += written;
write_len -= written;
if (pos > i_size_read(inode) && !S_ISBLK(inode->i_mode)) {
i_size_write(inode, pos);
mark_inode_dirty(inode);
}
iocb->ki_pos = pos;
}
iov_iter_revert(from, write_len - iov_iter_count(from));
out:
return written;
}
struct page *grab_cache_page_write_begin(struct address_space *mapping,
pgoff_t index, unsigned flags)
{
struct page *page;
int fgp_flags = FGP_LOCK|FGP_WRITE|FGP_CREAT;
if (flags & AOP_FLAG_NOFS)
fgp_flags |= FGP_NOFS;
page = pagecache_get_page(mapping, index, fgp_flags,
mapping_gfp_mask(mapping));
if (page)
wait_for_stable_page(page);
return page;
}
ssize_t generic_perform_write(struct file *file,
struct iov_iter *i, loff_t pos)
{
struct address_space *mapping = file->f_mapping;
const struct address_space_operations *a_ops = mapping->a_ops;
long status = 0;
ssize_t written = 0;
unsigned int flags = 0;
do {
struct page *page;
unsigned long offset;
unsigned long bytes;
size_t copied;
void *fsdata;
offset = (pos & (PAGE_SIZE - 1));
bytes = min_t(unsigned long, PAGE_SIZE - offset,
iov_iter_count(i));
again:
if (unlikely(iov_iter_fault_in_readable(i, bytes))) {
status = -EFAULT;
break;
}
if (fatal_signal_pending(current)) {
status = -EINTR;
break;
}
status = a_ops->write_begin(file, mapping, pos, bytes, flags,
&page, &fsdata);
if (unlikely(status < 0))
break;
if (mapping_writably_mapped(mapping))
flush_dcache_page(page);
copied = iov_iter_copy_from_user_atomic(page, i, offset, bytes);
flush_dcache_page(page);
status = a_ops->write_end(file, mapping, pos, bytes, copied,
page, fsdata);
if (unlikely(status < 0))
break;
copied = status;
cond_resched();
iov_iter_advance(i, copied);
if (unlikely(copied == 0)) {
bytes = min_t(unsigned long, PAGE_SIZE - offset,
iov_iter_single_seg_count(i));
goto again;
}
pos += copied;
written += copied;
balance_dirty_pages_ratelimited(mapping);
} while (iov_iter_count(i));
return written ? written : status;
}
ssize_t __generic_file_write_iter(struct kiocb *iocb, struct iov_iter *from)
{
struct file *file = iocb->ki_filp;
struct address_space * mapping = file->f_mapping;
struct inode *inode = mapping->host;
ssize_t written = 0;
ssize_t err;
ssize_t status;
current->backing_dev_info = inode_to_bdi(inode);
err = file_remove_privs(file);
if (err)
goto out;
err = file_update_time(file);
if (err)
goto out;
if (iocb->ki_flags & IOCB_DIRECT) {
loff_t pos, endbyte;
written = generic_file_direct_write(iocb, from);
if (written < 0 || !iov_iter_count(from) || IS_DAX(inode))
goto out;
status = generic_perform_write(file, from, pos = iocb->ki_pos);
if (unlikely(status < 0)) {
err = status;
goto out;
}
endbyte = pos + status - 1;
err = filemap_write_and_wait_range(mapping, pos, endbyte);
if (err == 0) {
iocb->ki_pos = endbyte + 1;
written += status;
invalidate_mapping_pages(mapping,
pos >> PAGE_SHIFT,
endbyte >> PAGE_SHIFT);
} else {
}
} else {
written = generic_perform_write(file, from, iocb->ki_pos);
if (likely(written > 0))
iocb->ki_pos += written;
}
out:
current->backing_dev_info = NULL;
return written ? written : err;
}
ssize_t generic_file_write_iter(struct kiocb *iocb, struct iov_iter *from)
{
struct file *file = iocb->ki_filp;
struct inode *inode = file->f_mapping->host;
ssize_t ret;
inode_lock(inode);
ret = generic_write_checks(iocb, from);
if (ret > 0)
ret = __generic_file_write_iter(iocb, from);
inode_unlock(inode);
if (ret > 0)
ret = generic_write_sync(iocb, ret);
return ret;
}
int try_to_release_page(struct page *page, gfp_t gfp_mask)
{
struct address_space * const mapping = page->mapping;
BUG_ON(!PageLocked(page));
if (PageWriteback(page))
return 0;
if (mapping && mapping->a_ops->releasepage)
return mapping->a_ops->releasepage(page, gfp_mask);
return try_to_free_buffers(page);
}
