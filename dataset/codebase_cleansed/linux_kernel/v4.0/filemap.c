static void page_cache_tree_delete(struct address_space *mapping,
struct page *page, void *shadow)
{
struct radix_tree_node *node;
unsigned long index;
unsigned int offset;
unsigned int tag;
void **slot;
VM_BUG_ON(!PageLocked(page));
__radix_tree_lookup(&mapping->page_tree, page->index, &node, &slot);
if (shadow) {
mapping->nrshadows++;
smp_wmb();
}
mapping->nrpages--;
if (!node) {
mapping->page_tree.gfp_mask &= __GFP_BITS_MASK;
radix_tree_replace_slot(slot, shadow);
return;
}
index = page->index;
offset = index & RADIX_TREE_MAP_MASK;
for (tag = 0; tag < RADIX_TREE_MAX_TAGS; tag++) {
if (test_bit(offset, node->tags[tag]))
radix_tree_tag_clear(&mapping->page_tree, index, tag);
}
radix_tree_replace_slot(slot, shadow);
workingset_node_pages_dec(node);
if (shadow)
workingset_node_shadows_inc(node);
else
if (__radix_tree_delete_node(&mapping->page_tree, node))
return;
if (!workingset_node_pages(node) &&
list_empty(&node->private_list)) {
node->private_data = mapping;
list_lru_add(&workingset_shadow_nodes, &node->private_list);
}
}
void __delete_from_page_cache(struct page *page, void *shadow)
{
struct address_space *mapping = page->mapping;
trace_mm_filemap_delete_from_page_cache(page);
if (PageUptodate(page) && PageMappedToDisk(page))
cleancache_put_page(page);
else
cleancache_invalidate_page(mapping, page);
page_cache_tree_delete(mapping, page, shadow);
page->mapping = NULL;
__dec_zone_page_state(page, NR_FILE_PAGES);
if (PageSwapBacked(page))
__dec_zone_page_state(page, NR_SHMEM);
BUG_ON(page_mapped(page));
if (PageDirty(page) && mapping_cap_account_dirty(mapping)) {
dec_zone_page_state(page, NR_FILE_DIRTY);
dec_bdi_stat(inode_to_bdi(mapping->host), BDI_RECLAIMABLE);
}
}
void delete_from_page_cache(struct page *page)
{
struct address_space *mapping = page->mapping;
void (*freepage)(struct page *);
BUG_ON(!PageLocked(page));
freepage = mapping->a_ops->freepage;
spin_lock_irq(&mapping->tree_lock);
__delete_from_page_cache(page, NULL);
spin_unlock_irq(&mapping->tree_lock);
if (freepage)
freepage(page);
page_cache_release(page);
}
static int filemap_check_errors(struct address_space *mapping)
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
ret = do_writepages(mapping, &wbc);
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
int filemap_fdatawait_range(struct address_space *mapping, loff_t start_byte,
loff_t end_byte)
{
pgoff_t index = start_byte >> PAGE_CACHE_SHIFT;
pgoff_t end = end_byte >> PAGE_CACHE_SHIFT;
struct pagevec pvec;
int nr_pages;
int ret2, ret = 0;
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
ret2 = filemap_check_errors(mapping);
if (!ret)
ret = ret2;
return ret;
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
if (mapping->nrpages) {
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
if (mapping->nrpages) {
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
pgoff_t offset = old->index;
freepage = mapping->a_ops->freepage;
page_cache_get(new);
new->mapping = mapping;
new->index = offset;
spin_lock_irq(&mapping->tree_lock);
__delete_from_page_cache(old, NULL);
error = radix_tree_insert(&mapping->page_tree, offset, new);
BUG_ON(error);
mapping->nrpages++;
__inc_zone_page_state(new, NR_FILE_PAGES);
if (PageSwapBacked(new))
__inc_zone_page_state(new, NR_SHMEM);
spin_unlock_irq(&mapping->tree_lock);
mem_cgroup_migrate(old, new, true);
radix_tree_preload_end();
if (freepage)
freepage(old);
page_cache_release(old);
}
return error;
}
static int page_cache_tree_insert(struct address_space *mapping,
struct page *page, void **shadowp)
{
struct radix_tree_node *node;
void **slot;
int error;
error = __radix_tree_create(&mapping->page_tree, page->index,
&node, &slot);
if (error)
return error;
if (*slot) {
void *p;
p = radix_tree_deref_slot_protected(slot, &mapping->tree_lock);
if (!radix_tree_exceptional_entry(p))
return -EEXIST;
if (shadowp)
*shadowp = p;
mapping->nrshadows--;
if (node)
workingset_node_shadows_dec(node);
}
radix_tree_replace_slot(slot, page);
mapping->nrpages++;
if (node) {
workingset_node_pages_inc(node);
if (!list_empty(&node->private_list))
list_lru_del(&workingset_shadow_nodes,
&node->private_list);
}
return 0;
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
gfp_mask, &memcg);
if (error)
return error;
}
error = radix_tree_maybe_preload(gfp_mask & ~__GFP_HIGHMEM);
if (error) {
if (!huge)
mem_cgroup_cancel_charge(page, memcg);
return error;
}
page_cache_get(page);
page->mapping = mapping;
page->index = offset;
spin_lock_irq(&mapping->tree_lock);
error = page_cache_tree_insert(mapping, page, shadowp);
radix_tree_preload_end();
if (unlikely(error))
goto err_insert;
__inc_zone_page_state(page, NR_FILE_PAGES);
spin_unlock_irq(&mapping->tree_lock);
if (!huge)
mem_cgroup_commit_charge(page, memcg, false);
trace_mm_filemap_add_to_page_cache(page);
return 0;
err_insert:
page->mapping = NULL;
spin_unlock_irq(&mapping->tree_lock);
if (!huge)
mem_cgroup_cancel_charge(page, memcg);
page_cache_release(page);
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
__set_page_locked(page);
ret = __add_to_page_cache_locked(page, mapping, offset,
gfp_mask, &shadow);
if (unlikely(ret))
__clear_page_locked(page);
else {
if (shadow && workingset_refault(shadow)) {
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
page = alloc_pages_exact_node(n, gfp, 0);
} while (!page && read_mems_allowed_retry(cpuset_mems_cookie));
return page;
}
return alloc_pages(gfp, 0);
}
wait_queue_head_t *page_waitqueue(struct page *page)
{
const struct zone *zone = page_zone(page);
return &zone->wait_table[hash_ptr(page, zone->wait_table_bits)];
}
void wait_on_page_bit(struct page *page, int bit_nr)
{
DEFINE_WAIT_BIT(wait, &page->flags, bit_nr);
if (test_bit(bit_nr, &page->flags))
__wait_on_bit(page_waitqueue(page), &wait, bit_wait_io,
TASK_UNINTERRUPTIBLE);
}
int wait_on_page_bit_killable(struct page *page, int bit_nr)
{
DEFINE_WAIT_BIT(wait, &page->flags, bit_nr);
if (!test_bit(bit_nr, &page->flags))
return 0;
return __wait_on_bit(page_waitqueue(page), &wait,
bit_wait_io, TASK_KILLABLE);
}
int wait_on_page_bit_killable_timeout(struct page *page,
int bit_nr, unsigned long timeout)
{
DEFINE_WAIT_BIT(wait, &page->flags, bit_nr);
wait.key.timeout = jiffies + timeout;
if (!test_bit(bit_nr, &page->flags))
return 0;
return __wait_on_bit(page_waitqueue(page), &wait,
bit_wait_io_timeout, TASK_KILLABLE);
}
void add_page_wait_queue(struct page *page, wait_queue_t *waiter)
{
wait_queue_head_t *q = page_waitqueue(page);
unsigned long flags;
spin_lock_irqsave(&q->lock, flags);
__add_wait_queue(q, waiter);
spin_unlock_irqrestore(&q->lock, flags);
}
void unlock_page(struct page *page)
{
VM_BUG_ON_PAGE(!PageLocked(page), page);
clear_bit_unlock(PG_locked, &page->flags);
smp_mb__after_atomic();
wake_up_page(page, PG_locked);
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
void page_endio(struct page *page, int rw, int err)
{
if (rw == READ) {
if (!err) {
SetPageUptodate(page);
} else {
ClearPageUptodate(page);
SetPageError(page);
}
unlock_page(page);
} else {
if (err) {
SetPageError(page);
if (page->mapping)
mapping_set_error(page->mapping, err);
}
end_page_writeback(page);
}
}
void __lock_page(struct page *page)
{
DEFINE_WAIT_BIT(wait, &page->flags, PG_locked);
__wait_on_bit_lock(page_waitqueue(page), &wait, bit_wait_io,
TASK_UNINTERRUPTIBLE);
}
int __lock_page_killable(struct page *page)
{
DEFINE_WAIT_BIT(wait, &page->flags, PG_locked);
return __wait_on_bit_lock(page_waitqueue(page), &wait,
bit_wait_io, TASK_KILLABLE);
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
struct page *page;
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
if (!page_cache_get_speculative(page))
goto repeat;
if (unlikely(page != *pagep)) {
page_cache_release(page);
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
if (unlikely(page->mapping != mapping)) {
unlock_page(page);
page_cache_release(page);
goto repeat;
}
VM_BUG_ON_PAGE(page->index != offset, page);
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
page_cache_release(page);
return NULL;
}
} else {
lock_page(page);
}
if (unlikely(page->mapping != mapping)) {
unlock_page(page);
page_cache_release(page);
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
page_cache_release(page);
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
restart:
radix_tree_for_each_slot(slot, &mapping->page_tree, &iter, start) {
struct page *page;
repeat:
page = radix_tree_deref_slot(slot);
if (unlikely(!page))
continue;
if (radix_tree_exception(page)) {
if (radix_tree_deref_retry(page))
goto restart;
goto export;
}
if (!page_cache_get_speculative(page))
goto repeat;
if (unlikely(page != *slot)) {
page_cache_release(page);
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
restart:
radix_tree_for_each_slot(slot, &mapping->page_tree, &iter, start) {
struct page *page;
repeat:
page = radix_tree_deref_slot(slot);
if (unlikely(!page))
continue;
if (radix_tree_exception(page)) {
if (radix_tree_deref_retry(page)) {
WARN_ON(iter.index);
goto restart;
}
continue;
}
if (!page_cache_get_speculative(page))
goto repeat;
if (unlikely(page != *slot)) {
page_cache_release(page);
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
restart:
radix_tree_for_each_contig(slot, &mapping->page_tree, &iter, index) {
struct page *page;
repeat:
page = radix_tree_deref_slot(slot);
if (unlikely(!page))
break;
if (radix_tree_exception(page)) {
if (radix_tree_deref_retry(page)) {
goto restart;
}
break;
}
if (!page_cache_get_speculative(page))
goto repeat;
if (unlikely(page != *slot)) {
page_cache_release(page);
goto repeat;
}
if (page->mapping == NULL || page->index != iter.index) {
page_cache_release(page);
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
restart:
radix_tree_for_each_tagged(slot, &mapping->page_tree,
&iter, *index, tag) {
struct page *page;
repeat:
page = radix_tree_deref_slot(slot);
if (unlikely(!page))
continue;
if (radix_tree_exception(page)) {
if (radix_tree_deref_retry(page)) {
goto restart;
}
continue;
}
if (!page_cache_get_speculative(page))
goto repeat;
if (unlikely(page != *slot)) {
page_cache_release(page);
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
index = *ppos >> PAGE_CACHE_SHIFT;
prev_index = ra->prev_pos >> PAGE_CACHE_SHIFT;
prev_offset = ra->prev_pos & (PAGE_CACHE_SIZE-1);
last_index = (*ppos + iter->count + PAGE_CACHE_SIZE-1) >> PAGE_CACHE_SHIFT;
offset = *ppos & ~PAGE_CACHE_MASK;
for (;;) {
struct page *page;
pgoff_t end_index;
loff_t isize;
unsigned long nr, ret;
cond_resched();
find_page:
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
if (inode->i_blkbits == PAGE_CACHE_SHIFT ||
!mapping->a_ops->is_partially_uptodate)
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
end_index = (isize - 1) >> PAGE_CACHE_SHIFT;
if (unlikely(!isize || index > end_index)) {
page_cache_release(page);
goto out;
}
nr = PAGE_CACHE_SIZE;
if (index == end_index) {
nr = ((isize - 1) & ~PAGE_CACHE_MASK) + 1;
if (nr <= offset) {
page_cache_release(page);
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
index += offset >> PAGE_CACHE_SHIFT;
offset &= ~PAGE_CACHE_MASK;
prev_offset = offset;
page_cache_release(page);
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
page_cache_release(page);
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
page_cache_release(page);
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
page_cache_release(page);
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
page_cache_release(page);
goto out;
no_cached_page:
page = page_cache_alloc_cold(mapping);
if (!page) {
error = -ENOMEM;
goto out;
}
error = add_to_page_cache_lru(page, mapping,
index, GFP_KERNEL);
if (error) {
page_cache_release(page);
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
ra->prev_pos <<= PAGE_CACHE_SHIFT;
ra->prev_pos |= prev_offset;
*ppos = ((loff_t)index << PAGE_CACHE_SHIFT) + offset;
file_accessed(filp);
return written ? written : error;
}
ssize_t
generic_file_read_iter(struct kiocb *iocb, struct iov_iter *iter)
{
struct file *file = iocb->ki_filp;
ssize_t retval = 0;
loff_t *ppos = &iocb->ki_pos;
loff_t pos = *ppos;
if (io_is_direct(file)) {
struct address_space *mapping = file->f_mapping;
struct inode *inode = mapping->host;
size_t count = iov_iter_count(iter);
loff_t size;
if (!count)
goto out;
size = i_size_read(inode);
retval = filemap_write_and_wait_range(mapping, pos,
pos + count - 1);
if (!retval) {
struct iov_iter data = *iter;
retval = mapping->a_ops->direct_IO(READ, iocb, &data, pos);
}
if (retval > 0) {
*ppos = pos + retval;
iov_iter_advance(iter, retval);
}
if (retval < 0 || !iov_iter_count(iter) || *ppos >= size ||
IS_DAX(inode)) {
file_accessed(file);
goto out;
}
}
retval = do_generic_file_read(file, ppos, iter, retval);
out:
return retval;
}
static int page_cache_read(struct file *file, pgoff_t offset)
{
struct address_space *mapping = file->f_mapping;
struct page *page;
int ret;
do {
page = page_cache_alloc_cold(mapping);
if (!page)
return -ENOMEM;
ret = add_to_page_cache_lru(page, mapping, offset, GFP_KERNEL);
if (ret == 0)
ret = mapping->a_ops->readpage(file, page);
else if (ret == -EEXIST)
ret = 0;
page_cache_release(page);
} while (ret == AOP_TRUNCATED_PAGE);
return ret;
}
static void do_sync_mmap_readahead(struct vm_area_struct *vma,
struct file_ra_state *ra,
struct file *file,
pgoff_t offset)
{
unsigned long ra_pages;
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
ra_pages = max_sane_readahead(ra->ra_pages);
ra->start = max_t(long, 0, offset - ra_pages / 2);
ra->size = ra_pages;
ra->async_size = ra_pages / 4;
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
int filemap_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
int error;
struct file *file = vma->vm_file;
struct address_space *mapping = file->f_mapping;
struct file_ra_state *ra = &file->f_ra;
struct inode *inode = mapping->host;
pgoff_t offset = vmf->pgoff;
struct page *page;
loff_t size;
int ret = 0;
size = round_up(i_size_read(inode), PAGE_CACHE_SIZE);
if (offset >= size >> PAGE_CACHE_SHIFT)
return VM_FAULT_SIGBUS;
page = find_get_page(mapping, offset);
if (likely(page) && !(vmf->flags & FAULT_FLAG_TRIED)) {
do_async_mmap_readahead(vma, ra, file, page, offset);
} else if (!page) {
do_sync_mmap_readahead(vma, ra, file, offset);
count_vm_event(PGMAJFAULT);
mem_cgroup_count_vm_event(vma->vm_mm, PGMAJFAULT);
ret = VM_FAULT_MAJOR;
retry_find:
page = find_get_page(mapping, offset);
if (!page)
goto no_cached_page;
}
if (!lock_page_or_retry(page, vma->vm_mm, vmf->flags)) {
page_cache_release(page);
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
size = round_up(i_size_read(inode), PAGE_CACHE_SIZE);
if (unlikely(offset >= size >> PAGE_CACHE_SHIFT)) {
unlock_page(page);
page_cache_release(page);
return VM_FAULT_SIGBUS;
}
vmf->page = page;
return ret | VM_FAULT_LOCKED;
no_cached_page:
error = page_cache_read(file, offset);
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
page_cache_release(page);
if (!error || error == AOP_TRUNCATED_PAGE)
goto retry_find;
shrink_readahead_size_eio(file, ra);
return VM_FAULT_SIGBUS;
}
void filemap_map_pages(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct radix_tree_iter iter;
void **slot;
struct file *file = vma->vm_file;
struct address_space *mapping = file->f_mapping;
loff_t size;
struct page *page;
unsigned long address = (unsigned long) vmf->virtual_address;
unsigned long addr;
pte_t *pte;
rcu_read_lock();
radix_tree_for_each_slot(slot, &mapping->page_tree, &iter, vmf->pgoff) {
if (iter.index > vmf->max_pgoff)
break;
repeat:
page = radix_tree_deref_slot(slot);
if (unlikely(!page))
goto next;
if (radix_tree_exception(page)) {
if (radix_tree_deref_retry(page))
break;
else
goto next;
}
if (!page_cache_get_speculative(page))
goto repeat;
if (unlikely(page != *slot)) {
page_cache_release(page);
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
size = round_up(i_size_read(mapping->host), PAGE_CACHE_SIZE);
if (page->index >= size >> PAGE_CACHE_SHIFT)
goto unlock;
pte = vmf->pte + page->index - vmf->pgoff;
if (!pte_none(*pte))
goto unlock;
if (file->f_ra.mmap_miss > 0)
file->f_ra.mmap_miss--;
addr = address + (page->index - vmf->pgoff) * PAGE_SIZE;
do_set_pte(vma, addr, page, pte, false, false);
unlock_page(page);
goto next;
unlock:
unlock_page(page);
skip:
page_cache_release(page);
next:
if (iter.index == vmf->max_pgoff)
break;
}
rcu_read_unlock();
}
int filemap_page_mkwrite(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct page *page = vmf->page;
struct inode *inode = file_inode(vma->vm_file);
int ret = VM_FAULT_LOCKED;
sb_start_pagefault(inode->i_sb);
file_update_time(vma->vm_file);
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
page_cache_release(page);
page = ERR_PTR(-EIO);
}
}
return page;
}
static struct page *__read_cache_page(struct address_space *mapping,
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
page_cache_release(page);
if (err == -EEXIST)
goto repeat;
return ERR_PTR(err);
}
err = filler(data, page);
if (err < 0) {
page_cache_release(page);
page = ERR_PTR(err);
} else {
page = wait_on_page_read(page);
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
retry:
page = __read_cache_page(mapping, index, filler, data, gfp);
if (IS_ERR(page))
return page;
if (PageUptodate(page))
goto out;
lock_page(page);
if (!page->mapping) {
unlock_page(page);
page_cache_release(page);
goto retry;
}
if (PageUptodate(page)) {
unlock_page(page);
goto out;
}
err = filler(data, page);
if (err < 0) {
page_cache_release(page);
return ERR_PTR(err);
} else {
page = wait_on_page_read(page);
if (IS_ERR(page))
return page;
}
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
inline int generic_write_checks(struct file *file, loff_t *pos, size_t *count, int isblk)
{
struct inode *inode = file->f_mapping->host;
unsigned long limit = rlimit(RLIMIT_FSIZE);
if (unlikely(*pos < 0))
return -EINVAL;
if (!isblk) {
if (file->f_flags & O_APPEND)
*pos = i_size_read(inode);
if (limit != RLIM_INFINITY) {
if (*pos >= limit) {
send_sig(SIGXFSZ, current, 0);
return -EFBIG;
}
if (*count > limit - (typeof(limit))*pos) {
*count = limit - (typeof(limit))*pos;
}
}
}
if (unlikely(*pos + *count > MAX_NON_LFS &&
!(file->f_flags & O_LARGEFILE))) {
if (*pos >= MAX_NON_LFS) {
return -EFBIG;
}
if (*count > MAX_NON_LFS - (unsigned long)*pos) {
*count = MAX_NON_LFS - (unsigned long)*pos;
}
}
if (likely(!isblk)) {
if (unlikely(*pos >= inode->i_sb->s_maxbytes)) {
if (*count || *pos > inode->i_sb->s_maxbytes) {
return -EFBIG;
}
}
if (unlikely(*pos + *count > inode->i_sb->s_maxbytes))
*count = inode->i_sb->s_maxbytes - *pos;
} else {
#ifdef CONFIG_BLOCK
loff_t isize;
if (bdev_read_only(I_BDEV(inode)))
return -EPERM;
isize = i_size_read(inode);
if (*pos >= isize) {
if (*count || *pos > isize)
return -ENOSPC;
}
if (*pos + *count > isize)
*count = isize - *pos;
#else
return -EPERM;
#endif
}
return 0;
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
generic_file_direct_write(struct kiocb *iocb, struct iov_iter *from, loff_t pos)
{
struct file *file = iocb->ki_filp;
struct address_space *mapping = file->f_mapping;
struct inode *inode = mapping->host;
ssize_t written;
size_t write_len;
pgoff_t end;
struct iov_iter data;
write_len = iov_iter_count(from);
end = (pos + write_len - 1) >> PAGE_CACHE_SHIFT;
written = filemap_write_and_wait_range(mapping, pos, pos + write_len - 1);
if (written)
goto out;
if (mapping->nrpages) {
written = invalidate_inode_pages2_range(mapping,
pos >> PAGE_CACHE_SHIFT, end);
if (written) {
if (written == -EBUSY)
return 0;
goto out;
}
}
data = *from;
written = mapping->a_ops->direct_IO(WRITE, iocb, &data, pos);
if (mapping->nrpages) {
invalidate_inode_pages2_range(mapping,
pos >> PAGE_CACHE_SHIFT, end);
}
if (written > 0) {
pos += written;
iov_iter_advance(from, written);
if (pos > i_size_read(inode) && !S_ISBLK(inode->i_mode)) {
i_size_write(inode, pos);
mark_inode_dirty(inode);
}
iocb->ki_pos = pos;
}
out:
return written;
}
struct page *grab_cache_page_write_begin(struct address_space *mapping,
pgoff_t index, unsigned flags)
{
struct page *page;
int fgp_flags = FGP_LOCK|FGP_ACCESSED|FGP_WRITE|FGP_CREAT;
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
if (!iter_is_iovec(i))
flags |= AOP_FLAG_UNINTERRUPTIBLE;
do {
struct page *page;
unsigned long offset;
unsigned long bytes;
size_t copied;
void *fsdata;
offset = (pos & (PAGE_CACHE_SIZE - 1));
bytes = min_t(unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_count(i));
again:
if (unlikely(iov_iter_fault_in_readable(i, bytes))) {
status = -EFAULT;
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
bytes = min_t(unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_single_seg_count(i));
goto again;
}
pos += copied;
written += copied;
balance_dirty_pages_ratelimited(mapping);
if (fatal_signal_pending(current)) {
status = -EINTR;
break;
}
} while (iov_iter_count(i));
return written ? written : status;
}
ssize_t __generic_file_write_iter(struct kiocb *iocb, struct iov_iter *from)
{
struct file *file = iocb->ki_filp;
struct address_space * mapping = file->f_mapping;
struct inode *inode = mapping->host;
loff_t pos = iocb->ki_pos;
ssize_t written = 0;
ssize_t err;
ssize_t status;
size_t count = iov_iter_count(from);
current->backing_dev_info = inode_to_bdi(inode);
err = generic_write_checks(file, &pos, &count, S_ISBLK(inode->i_mode));
if (err)
goto out;
if (count == 0)
goto out;
iov_iter_truncate(from, count);
err = file_remove_suid(file);
if (err)
goto out;
err = file_update_time(file);
if (err)
goto out;
if (io_is_direct(file)) {
loff_t endbyte;
written = generic_file_direct_write(iocb, from, pos);
if (written < 0 || written == count || IS_DAX(inode))
goto out;
pos += written;
count -= written;
status = generic_perform_write(file, from, pos);
if (unlikely(status < 0)) {
err = status;
goto out;
}
iocb->ki_pos = pos + status;
endbyte = pos + status - 1;
err = filemap_write_and_wait_range(file->f_mapping, pos, endbyte);
if (err == 0) {
written += status;
invalidate_mapping_pages(mapping,
pos >> PAGE_CACHE_SHIFT,
endbyte >> PAGE_CACHE_SHIFT);
} else {
}
} else {
written = generic_perform_write(file, from, pos);
if (likely(written >= 0))
iocb->ki_pos = pos + written;
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
mutex_lock(&inode->i_mutex);
ret = __generic_file_write_iter(iocb, from);
mutex_unlock(&inode->i_mutex);
if (ret > 0) {
ssize_t err;
err = generic_write_sync(file, iocb->ki_pos - ret, ret);
if (err < 0)
ret = err;
}
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
