static inline long sync_writeback_pages(unsigned long dirtied)
{
if (dirtied < ratelimit_pages)
dirtied = ratelimit_pages;
return dirtied + dirtied / 2;
}
static int calc_period_shift(void)
{
unsigned long dirty_total;
if (vm_dirty_bytes)
dirty_total = vm_dirty_bytes / PAGE_SIZE;
else
dirty_total = (vm_dirty_ratio * determine_dirtyable_memory()) /
100;
return 2 + ilog2(dirty_total - 1);
}
static void update_completion_period(void)
{
int shift = calc_period_shift();
prop_change_shift(&vm_completions, shift);
prop_change_shift(&vm_dirties, shift);
}
int dirty_background_ratio_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp,
loff_t *ppos)
{
int ret;
ret = proc_dointvec_minmax(table, write, buffer, lenp, ppos);
if (ret == 0 && write)
dirty_background_bytes = 0;
return ret;
}
int dirty_background_bytes_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp,
loff_t *ppos)
{
int ret;
ret = proc_doulongvec_minmax(table, write, buffer, lenp, ppos);
if (ret == 0 && write)
dirty_background_ratio = 0;
return ret;
}
int dirty_ratio_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp,
loff_t *ppos)
{
int old_ratio = vm_dirty_ratio;
int ret;
ret = proc_dointvec_minmax(table, write, buffer, lenp, ppos);
if (ret == 0 && write && vm_dirty_ratio != old_ratio) {
update_completion_period();
vm_dirty_bytes = 0;
}
return ret;
}
int dirty_bytes_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp,
loff_t *ppos)
{
unsigned long old_bytes = vm_dirty_bytes;
int ret;
ret = proc_doulongvec_minmax(table, write, buffer, lenp, ppos);
if (ret == 0 && write && vm_dirty_bytes != old_bytes) {
update_completion_period();
vm_dirty_ratio = 0;
}
return ret;
}
static inline void __bdi_writeout_inc(struct backing_dev_info *bdi)
{
__prop_inc_percpu_max(&vm_completions, &bdi->completions,
bdi->max_prop_frac);
}
void bdi_writeout_inc(struct backing_dev_info *bdi)
{
unsigned long flags;
local_irq_save(flags);
__bdi_writeout_inc(bdi);
local_irq_restore(flags);
}
void task_dirty_inc(struct task_struct *tsk)
{
prop_inc_single(&vm_dirties, &tsk->dirties);
}
static void bdi_writeout_fraction(struct backing_dev_info *bdi,
long *numerator, long *denominator)
{
if (bdi_cap_writeback_dirty(bdi)) {
prop_fraction_percpu(&vm_completions, &bdi->completions,
numerator, denominator);
} else {
*numerator = 0;
*denominator = 1;
}
}
static inline void task_dirties_fraction(struct task_struct *tsk,
long *numerator, long *denominator)
{
prop_fraction_single(&vm_dirties, &tsk->dirties,
numerator, denominator);
}
static unsigned long task_dirty_limit(struct task_struct *tsk,
unsigned long bdi_dirty)
{
long numerator, denominator;
unsigned long dirty = bdi_dirty;
u64 inv = dirty >> 3;
task_dirties_fraction(tsk, &numerator, &denominator);
inv *= numerator;
do_div(inv, denominator);
dirty -= inv;
return max(dirty, bdi_dirty/2);
}
int bdi_set_min_ratio(struct backing_dev_info *bdi, unsigned int min_ratio)
{
int ret = 0;
spin_lock_bh(&bdi_lock);
if (min_ratio > bdi->max_ratio) {
ret = -EINVAL;
} else {
min_ratio -= bdi->min_ratio;
if (bdi_min_ratio + min_ratio < 100) {
bdi_min_ratio += min_ratio;
bdi->min_ratio += min_ratio;
} else {
ret = -EINVAL;
}
}
spin_unlock_bh(&bdi_lock);
return ret;
}
int bdi_set_max_ratio(struct backing_dev_info *bdi, unsigned max_ratio)
{
int ret = 0;
if (max_ratio > 100)
return -EINVAL;
spin_lock_bh(&bdi_lock);
if (bdi->min_ratio > max_ratio) {
ret = -EINVAL;
} else {
bdi->max_ratio = max_ratio;
bdi->max_prop_frac = (PROP_FRAC_BASE * max_ratio) / 100;
}
spin_unlock_bh(&bdi_lock);
return ret;
}
static unsigned long highmem_dirtyable_memory(unsigned long total)
{
#ifdef CONFIG_HIGHMEM
int node;
unsigned long x = 0;
for_each_node_state(node, N_HIGH_MEMORY) {
struct zone *z =
&NODE_DATA(node)->node_zones[ZONE_HIGHMEM];
x += zone_page_state(z, NR_FREE_PAGES) +
zone_reclaimable_pages(z);
}
return min(x, total);
#else
return 0;
#endif
}
unsigned long determine_dirtyable_memory(void)
{
unsigned long x;
x = global_page_state(NR_FREE_PAGES) + global_reclaimable_pages();
if (!vm_highmem_is_dirtyable)
x -= highmem_dirtyable_memory(x);
return x + 1;
}
void global_dirty_limits(unsigned long *pbackground, unsigned long *pdirty)
{
unsigned long background;
unsigned long dirty;
unsigned long uninitialized_var(available_memory);
struct task_struct *tsk;
if (!vm_dirty_bytes || !dirty_background_bytes)
available_memory = determine_dirtyable_memory();
if (vm_dirty_bytes)
dirty = DIV_ROUND_UP(vm_dirty_bytes, PAGE_SIZE);
else
dirty = (vm_dirty_ratio * available_memory) / 100;
if (dirty_background_bytes)
background = DIV_ROUND_UP(dirty_background_bytes, PAGE_SIZE);
else
background = (dirty_background_ratio * available_memory) / 100;
if (background >= dirty)
background = dirty / 2;
tsk = current;
if (tsk->flags & PF_LESS_THROTTLE || rt_task(tsk)) {
background += background / 4;
dirty += dirty / 4;
}
*pbackground = background;
*pdirty = dirty;
}
unsigned long bdi_dirty_limit(struct backing_dev_info *bdi, unsigned long dirty)
{
u64 bdi_dirty;
long numerator, denominator;
bdi_writeout_fraction(bdi, &numerator, &denominator);
bdi_dirty = (dirty * (100 - bdi_min_ratio)) / 100;
bdi_dirty *= numerator;
do_div(bdi_dirty, denominator);
bdi_dirty += (dirty * bdi->min_ratio) / 100;
if (bdi_dirty > (dirty * bdi->max_ratio) / 100)
bdi_dirty = dirty * bdi->max_ratio / 100;
return bdi_dirty;
}
static void balance_dirty_pages(struct address_space *mapping,
unsigned long write_chunk)
{
long nr_reclaimable, bdi_nr_reclaimable;
long nr_writeback, bdi_nr_writeback;
unsigned long background_thresh;
unsigned long dirty_thresh;
unsigned long bdi_thresh;
unsigned long pages_written = 0;
unsigned long pause = 1;
bool dirty_exceeded = false;
struct backing_dev_info *bdi = mapping->backing_dev_info;
for (;;) {
struct writeback_control wbc = {
.sync_mode = WB_SYNC_NONE,
.older_than_this = NULL,
.nr_to_write = write_chunk,
.range_cyclic = 1,
};
nr_reclaimable = global_page_state(NR_FILE_DIRTY) +
global_page_state(NR_UNSTABLE_NFS);
nr_writeback = global_page_state(NR_WRITEBACK);
global_dirty_limits(&background_thresh, &dirty_thresh);
if (nr_reclaimable + nr_writeback <=
(background_thresh + dirty_thresh) / 2)
break;
bdi_thresh = bdi_dirty_limit(bdi, dirty_thresh);
bdi_thresh = task_dirty_limit(current, bdi_thresh);
if (bdi_thresh < 2*bdi_stat_error(bdi)) {
bdi_nr_reclaimable = bdi_stat_sum(bdi, BDI_RECLAIMABLE);
bdi_nr_writeback = bdi_stat_sum(bdi, BDI_WRITEBACK);
} else {
bdi_nr_reclaimable = bdi_stat(bdi, BDI_RECLAIMABLE);
bdi_nr_writeback = bdi_stat(bdi, BDI_WRITEBACK);
}
dirty_exceeded =
(bdi_nr_reclaimable + bdi_nr_writeback > bdi_thresh)
|| (nr_reclaimable + nr_writeback > dirty_thresh);
if (!dirty_exceeded)
break;
if (!bdi->dirty_exceeded)
bdi->dirty_exceeded = 1;
trace_wbc_balance_dirty_start(&wbc, bdi);
if (bdi_nr_reclaimable > bdi_thresh) {
writeback_inodes_wb(&bdi->wb, &wbc);
pages_written += write_chunk - wbc.nr_to_write;
trace_wbc_balance_dirty_written(&wbc, bdi);
if (pages_written >= write_chunk)
break;
}
trace_wbc_balance_dirty_wait(&wbc, bdi);
__set_current_state(TASK_UNINTERRUPTIBLE);
io_schedule_timeout(pause);
pause <<= 1;
if (pause > HZ / 10)
pause = HZ / 10;
}
if (!dirty_exceeded && bdi->dirty_exceeded)
bdi->dirty_exceeded = 0;
if (writeback_in_progress(bdi))
return;
if ((laptop_mode && pages_written) ||
(!laptop_mode && (nr_reclaimable > background_thresh)))
bdi_start_background_writeback(bdi);
}
void set_page_dirty_balance(struct page *page, int page_mkwrite)
{
if (set_page_dirty(page) || page_mkwrite) {
struct address_space *mapping = page_mapping(page);
if (mapping)
balance_dirty_pages_ratelimited(mapping);
}
}
void balance_dirty_pages_ratelimited_nr(struct address_space *mapping,
unsigned long nr_pages_dirtied)
{
unsigned long ratelimit;
unsigned long *p;
ratelimit = ratelimit_pages;
if (mapping->backing_dev_info->dirty_exceeded)
ratelimit = 8;
preempt_disable();
p = &__get_cpu_var(bdp_ratelimits);
*p += nr_pages_dirtied;
if (unlikely(*p >= ratelimit)) {
ratelimit = sync_writeback_pages(*p);
*p = 0;
preempt_enable();
balance_dirty_pages(mapping, ratelimit);
return;
}
preempt_enable();
}
void throttle_vm_writeout(gfp_t gfp_mask)
{
unsigned long background_thresh;
unsigned long dirty_thresh;
for ( ; ; ) {
global_dirty_limits(&background_thresh, &dirty_thresh);
dirty_thresh += dirty_thresh / 10;
if (global_page_state(NR_UNSTABLE_NFS) +
global_page_state(NR_WRITEBACK) <= dirty_thresh)
break;
congestion_wait(BLK_RW_ASYNC, HZ/10);
if ((gfp_mask & (__GFP_FS|__GFP_IO)) != (__GFP_FS|__GFP_IO))
break;
}
}
int dirty_writeback_centisecs_handler(ctl_table *table, int write,
void __user *buffer, size_t *length, loff_t *ppos)
{
proc_dointvec(table, write, buffer, length, ppos);
bdi_arm_supers_timer();
return 0;
}
void laptop_mode_timer_fn(unsigned long data)
{
struct request_queue *q = (struct request_queue *)data;
int nr_pages = global_page_state(NR_FILE_DIRTY) +
global_page_state(NR_UNSTABLE_NFS);
if (bdi_has_dirty_io(&q->backing_dev_info))
bdi_start_writeback(&q->backing_dev_info, nr_pages);
}
void laptop_io_completion(struct backing_dev_info *info)
{
mod_timer(&info->laptop_mode_wb_timer, jiffies + laptop_mode);
}
void laptop_sync_completion(void)
{
struct backing_dev_info *bdi;
rcu_read_lock();
list_for_each_entry_rcu(bdi, &bdi_list, bdi_list)
del_timer(&bdi->laptop_mode_wb_timer);
rcu_read_unlock();
}
void writeback_set_ratelimit(void)
{
ratelimit_pages = vm_total_pages / (num_online_cpus() * 32);
if (ratelimit_pages < 16)
ratelimit_pages = 16;
if (ratelimit_pages * PAGE_CACHE_SIZE > 4096 * 1024)
ratelimit_pages = (4096 * 1024) / PAGE_CACHE_SIZE;
}
static int __cpuinit
ratelimit_handler(struct notifier_block *self, unsigned long u, void *v)
{
writeback_set_ratelimit();
return NOTIFY_DONE;
}
void __init page_writeback_init(void)
{
int shift;
writeback_set_ratelimit();
register_cpu_notifier(&ratelimit_nb);
shift = calc_period_shift();
prop_descriptor_init(&vm_completions, shift);
prop_descriptor_init(&vm_dirties, shift);
}
void tag_pages_for_writeback(struct address_space *mapping,
pgoff_t start, pgoff_t end)
{
#define WRITEBACK_TAG_BATCH 4096
unsigned long tagged;
do {
spin_lock_irq(&mapping->tree_lock);
tagged = radix_tree_range_tag_if_tagged(&mapping->page_tree,
&start, end, WRITEBACK_TAG_BATCH,
PAGECACHE_TAG_DIRTY, PAGECACHE_TAG_TOWRITE);
spin_unlock_irq(&mapping->tree_lock);
WARN_ON_ONCE(tagged > WRITEBACK_TAG_BATCH);
cond_resched();
} while (tagged >= WRITEBACK_TAG_BATCH && start);
}
int write_cache_pages(struct address_space *mapping,
struct writeback_control *wbc, writepage_t writepage,
void *data)
{
int ret = 0;
int done = 0;
struct pagevec pvec;
int nr_pages;
pgoff_t uninitialized_var(writeback_index);
pgoff_t index;
pgoff_t end;
pgoff_t done_index;
int cycled;
int range_whole = 0;
int tag;
pagevec_init(&pvec, 0);
if (wbc->range_cyclic) {
writeback_index = mapping->writeback_index;
index = writeback_index;
if (index == 0)
cycled = 1;
else
cycled = 0;
end = -1;
} else {
index = wbc->range_start >> PAGE_CACHE_SHIFT;
end = wbc->range_end >> PAGE_CACHE_SHIFT;
if (wbc->range_start == 0 && wbc->range_end == LLONG_MAX)
range_whole = 1;
cycled = 1;
}
if (wbc->sync_mode == WB_SYNC_ALL)
tag = PAGECACHE_TAG_TOWRITE;
else
tag = PAGECACHE_TAG_DIRTY;
retry:
if (wbc->sync_mode == WB_SYNC_ALL)
tag_pages_for_writeback(mapping, index, end);
done_index = index;
while (!done && (index <= end)) {
int i;
nr_pages = pagevec_lookup_tag(&pvec, mapping, &index, tag,
min(end - index, (pgoff_t)PAGEVEC_SIZE-1) + 1);
if (nr_pages == 0)
break;
for (i = 0; i < nr_pages; i++) {
struct page *page = pvec.pages[i];
if (page->index > end) {
done = 1;
break;
}
done_index = page->index;
lock_page(page);
if (unlikely(page->mapping != mapping)) {
continue_unlock:
unlock_page(page);
continue;
}
if (!PageDirty(page)) {
goto continue_unlock;
}
if (PageWriteback(page)) {
if (wbc->sync_mode != WB_SYNC_NONE)
wait_on_page_writeback(page);
else
goto continue_unlock;
}
BUG_ON(PageWriteback(page));
if (!clear_page_dirty_for_io(page))
goto continue_unlock;
trace_wbc_writepage(wbc, mapping->backing_dev_info);
ret = (*writepage)(page, wbc, data);
if (unlikely(ret)) {
if (ret == AOP_WRITEPAGE_ACTIVATE) {
unlock_page(page);
ret = 0;
} else {
done_index = page->index + 1;
done = 1;
break;
}
}
if (--wbc->nr_to_write <= 0 &&
wbc->sync_mode == WB_SYNC_NONE) {
done = 1;
break;
}
}
pagevec_release(&pvec);
cond_resched();
}
if (!cycled && !done) {
cycled = 1;
index = 0;
end = writeback_index - 1;
goto retry;
}
if (wbc->range_cyclic || (range_whole && wbc->nr_to_write > 0))
mapping->writeback_index = done_index;
return ret;
}
static int __writepage(struct page *page, struct writeback_control *wbc,
void *data)
{
struct address_space *mapping = data;
int ret = mapping->a_ops->writepage(page, wbc);
mapping_set_error(mapping, ret);
return ret;
}
int generic_writepages(struct address_space *mapping,
struct writeback_control *wbc)
{
struct blk_plug plug;
int ret;
if (!mapping->a_ops->writepage)
return 0;
blk_start_plug(&plug);
ret = write_cache_pages(mapping, wbc, __writepage, mapping);
blk_finish_plug(&plug);
return ret;
}
int do_writepages(struct address_space *mapping, struct writeback_control *wbc)
{
int ret;
if (wbc->nr_to_write <= 0)
return 0;
if (mapping->a_ops->writepages)
ret = mapping->a_ops->writepages(mapping, wbc);
else
ret = generic_writepages(mapping, wbc);
return ret;
}
int write_one_page(struct page *page, int wait)
{
struct address_space *mapping = page->mapping;
int ret = 0;
struct writeback_control wbc = {
.sync_mode = WB_SYNC_ALL,
.nr_to_write = 1,
};
BUG_ON(!PageLocked(page));
if (wait)
wait_on_page_writeback(page);
if (clear_page_dirty_for_io(page)) {
page_cache_get(page);
ret = mapping->a_ops->writepage(page, &wbc);
if (ret == 0 && wait) {
wait_on_page_writeback(page);
if (PageError(page))
ret = -EIO;
}
page_cache_release(page);
} else {
unlock_page(page);
}
return ret;
}
int __set_page_dirty_no_writeback(struct page *page)
{
if (!PageDirty(page))
return !TestSetPageDirty(page);
return 0;
}
void account_page_dirtied(struct page *page, struct address_space *mapping)
{
if (mapping_cap_account_dirty(mapping)) {
__inc_zone_page_state(page, NR_FILE_DIRTY);
__inc_zone_page_state(page, NR_DIRTIED);
__inc_bdi_stat(mapping->backing_dev_info, BDI_RECLAIMABLE);
task_dirty_inc(current);
task_io_account_write(PAGE_CACHE_SIZE);
}
}
void account_page_writeback(struct page *page)
{
inc_zone_page_state(page, NR_WRITEBACK);
inc_zone_page_state(page, NR_WRITTEN);
}
int __set_page_dirty_nobuffers(struct page *page)
{
if (!TestSetPageDirty(page)) {
struct address_space *mapping = page_mapping(page);
struct address_space *mapping2;
if (!mapping)
return 1;
spin_lock_irq(&mapping->tree_lock);
mapping2 = page_mapping(page);
if (mapping2) {
BUG_ON(mapping2 != mapping);
WARN_ON_ONCE(!PagePrivate(page) && !PageUptodate(page));
account_page_dirtied(page, mapping);
radix_tree_tag_set(&mapping->page_tree,
page_index(page), PAGECACHE_TAG_DIRTY);
}
spin_unlock_irq(&mapping->tree_lock);
if (mapping->host) {
__mark_inode_dirty(mapping->host, I_DIRTY_PAGES);
}
return 1;
}
return 0;
}
int redirty_page_for_writepage(struct writeback_control *wbc, struct page *page)
{
wbc->pages_skipped++;
return __set_page_dirty_nobuffers(page);
}
int set_page_dirty(struct page *page)
{
struct address_space *mapping = page_mapping(page);
if (likely(mapping)) {
int (*spd)(struct page *) = mapping->a_ops->set_page_dirty;
ClearPageReclaim(page);
#ifdef CONFIG_BLOCK
if (!spd)
spd = __set_page_dirty_buffers;
#endif
return (*spd)(page);
}
if (!PageDirty(page)) {
if (!TestSetPageDirty(page))
return 1;
}
return 0;
}
int set_page_dirty_lock(struct page *page)
{
int ret;
lock_page(page);
ret = set_page_dirty(page);
unlock_page(page);
return ret;
}
int clear_page_dirty_for_io(struct page *page)
{
struct address_space *mapping = page_mapping(page);
BUG_ON(!PageLocked(page));
if (mapping && mapping_cap_account_dirty(mapping)) {
if (page_mkclean(page))
set_page_dirty(page);
if (TestClearPageDirty(page)) {
dec_zone_page_state(page, NR_FILE_DIRTY);
dec_bdi_stat(mapping->backing_dev_info,
BDI_RECLAIMABLE);
return 1;
}
return 0;
}
return TestClearPageDirty(page);
}
int test_clear_page_writeback(struct page *page)
{
struct address_space *mapping = page_mapping(page);
int ret;
if (mapping) {
struct backing_dev_info *bdi = mapping->backing_dev_info;
unsigned long flags;
spin_lock_irqsave(&mapping->tree_lock, flags);
ret = TestClearPageWriteback(page);
if (ret) {
radix_tree_tag_clear(&mapping->page_tree,
page_index(page),
PAGECACHE_TAG_WRITEBACK);
if (bdi_cap_account_writeback(bdi)) {
__dec_bdi_stat(bdi, BDI_WRITEBACK);
__bdi_writeout_inc(bdi);
}
}
spin_unlock_irqrestore(&mapping->tree_lock, flags);
} else {
ret = TestClearPageWriteback(page);
}
if (ret)
dec_zone_page_state(page, NR_WRITEBACK);
return ret;
}
int test_set_page_writeback(struct page *page)
{
struct address_space *mapping = page_mapping(page);
int ret;
if (mapping) {
struct backing_dev_info *bdi = mapping->backing_dev_info;
unsigned long flags;
spin_lock_irqsave(&mapping->tree_lock, flags);
ret = TestSetPageWriteback(page);
if (!ret) {
radix_tree_tag_set(&mapping->page_tree,
page_index(page),
PAGECACHE_TAG_WRITEBACK);
if (bdi_cap_account_writeback(bdi))
__inc_bdi_stat(bdi, BDI_WRITEBACK);
}
if (!PageDirty(page))
radix_tree_tag_clear(&mapping->page_tree,
page_index(page),
PAGECACHE_TAG_DIRTY);
radix_tree_tag_clear(&mapping->page_tree,
page_index(page),
PAGECACHE_TAG_TOWRITE);
spin_unlock_irqrestore(&mapping->tree_lock, flags);
} else {
ret = TestSetPageWriteback(page);
}
if (!ret)
account_page_writeback(page);
return ret;
}
int mapping_tagged(struct address_space *mapping, int tag)
{
int ret;
rcu_read_lock();
ret = radix_tree_tagged(&mapping->page_tree, tag);
rcu_read_unlock();
return ret;
}
