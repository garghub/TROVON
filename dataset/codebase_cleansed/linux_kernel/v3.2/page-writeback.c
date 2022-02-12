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
writeback_set_ratelimit();
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
__inc_bdi_stat(bdi, BDI_WRITTEN);
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
static void bdi_writeout_fraction(struct backing_dev_info *bdi,
long *numerator, long *denominator)
{
prop_fraction_percpu(&vm_completions, &bdi->completions,
numerator, denominator);
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
static unsigned long dirty_freerun_ceiling(unsigned long thresh,
unsigned long bg_thresh)
{
return (thresh + bg_thresh) / 2;
}
static unsigned long hard_dirty_limit(unsigned long thresh)
{
return max(thresh, global_dirty_limit);
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
trace_global_dirty_state(background, dirty);
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
static unsigned long bdi_position_ratio(struct backing_dev_info *bdi,
unsigned long thresh,
unsigned long bg_thresh,
unsigned long dirty,
unsigned long bdi_thresh,
unsigned long bdi_dirty)
{
unsigned long write_bw = bdi->avg_write_bandwidth;
unsigned long freerun = dirty_freerun_ceiling(thresh, bg_thresh);
unsigned long limit = hard_dirty_limit(thresh);
unsigned long x_intercept;
unsigned long setpoint;
unsigned long bdi_setpoint;
unsigned long span;
long long pos_ratio;
long x;
if (unlikely(dirty >= limit))
return 0;
setpoint = (freerun + limit) / 2;
x = div_s64((setpoint - dirty) << RATELIMIT_CALC_SHIFT,
limit - setpoint + 1);
pos_ratio = x;
pos_ratio = pos_ratio * x >> RATELIMIT_CALC_SHIFT;
pos_ratio = pos_ratio * x >> RATELIMIT_CALC_SHIFT;
pos_ratio += 1 << RATELIMIT_CALC_SHIFT;
if (unlikely(bdi_thresh > thresh))
bdi_thresh = thresh;
bdi_thresh = max(bdi_thresh, (limit - dirty) / 8);
x = div_u64((u64)bdi_thresh << 16, thresh + 1);
bdi_setpoint = setpoint * (u64)x >> 16;
span = (thresh - bdi_thresh + 8 * write_bw) * (u64)x >> 16;
x_intercept = bdi_setpoint + span;
if (bdi_dirty < x_intercept - span / 4) {
pos_ratio = div_u64(pos_ratio * (x_intercept - bdi_dirty),
x_intercept - bdi_setpoint + 1);
} else
pos_ratio /= 4;
x_intercept = bdi_thresh / 2;
if (bdi_dirty < x_intercept) {
if (bdi_dirty > x_intercept / 8)
pos_ratio = div_u64(pos_ratio * x_intercept, bdi_dirty);
else
pos_ratio *= 8;
}
return pos_ratio;
}
static void bdi_update_write_bandwidth(struct backing_dev_info *bdi,
unsigned long elapsed,
unsigned long written)
{
const unsigned long period = roundup_pow_of_two(3 * HZ);
unsigned long avg = bdi->avg_write_bandwidth;
unsigned long old = bdi->write_bandwidth;
u64 bw;
bw = written - bdi->written_stamp;
bw *= HZ;
if (unlikely(elapsed > period)) {
do_div(bw, elapsed);
avg = bw;
goto out;
}
bw += (u64)bdi->write_bandwidth * (period - elapsed);
bw >>= ilog2(period);
if (avg > old && old >= (unsigned long)bw)
avg -= (avg - old) >> 3;
if (avg < old && old <= (unsigned long)bw)
avg += (old - avg) >> 3;
out:
bdi->write_bandwidth = bw;
bdi->avg_write_bandwidth = avg;
}
static void update_dirty_limit(unsigned long thresh, unsigned long dirty)
{
unsigned long limit = global_dirty_limit;
if (limit < thresh) {
limit = thresh;
goto update;
}
thresh = max(thresh, dirty);
if (limit > thresh) {
limit -= (limit - thresh) >> 5;
goto update;
}
return;
update:
global_dirty_limit = limit;
}
static void global_update_bandwidth(unsigned long thresh,
unsigned long dirty,
unsigned long now)
{
static DEFINE_SPINLOCK(dirty_lock);
static unsigned long update_time;
if (time_before(now, update_time + BANDWIDTH_INTERVAL))
return;
spin_lock(&dirty_lock);
if (time_after_eq(now, update_time + BANDWIDTH_INTERVAL)) {
update_dirty_limit(thresh, dirty);
update_time = now;
}
spin_unlock(&dirty_lock);
}
static void bdi_update_dirty_ratelimit(struct backing_dev_info *bdi,
unsigned long thresh,
unsigned long bg_thresh,
unsigned long dirty,
unsigned long bdi_thresh,
unsigned long bdi_dirty,
unsigned long dirtied,
unsigned long elapsed)
{
unsigned long freerun = dirty_freerun_ceiling(thresh, bg_thresh);
unsigned long limit = hard_dirty_limit(thresh);
unsigned long setpoint = (freerun + limit) / 2;
unsigned long write_bw = bdi->avg_write_bandwidth;
unsigned long dirty_ratelimit = bdi->dirty_ratelimit;
unsigned long dirty_rate;
unsigned long task_ratelimit;
unsigned long balanced_dirty_ratelimit;
unsigned long pos_ratio;
unsigned long step;
unsigned long x;
dirty_rate = (dirtied - bdi->dirtied_stamp) * HZ / elapsed;
pos_ratio = bdi_position_ratio(bdi, thresh, bg_thresh, dirty,
bdi_thresh, bdi_dirty);
task_ratelimit = (u64)dirty_ratelimit *
pos_ratio >> RATELIMIT_CALC_SHIFT;
task_ratelimit++;
balanced_dirty_ratelimit = div_u64((u64)task_ratelimit * write_bw,
dirty_rate | 1);
step = 0;
if (dirty < setpoint) {
x = min(bdi->balanced_dirty_ratelimit,
min(balanced_dirty_ratelimit, task_ratelimit));
if (dirty_ratelimit < x)
step = x - dirty_ratelimit;
} else {
x = max(bdi->balanced_dirty_ratelimit,
max(balanced_dirty_ratelimit, task_ratelimit));
if (dirty_ratelimit > x)
step = dirty_ratelimit - x;
}
step >>= dirty_ratelimit / (2 * step + 1);
step = (step + 7) / 8;
if (dirty_ratelimit < balanced_dirty_ratelimit)
dirty_ratelimit += step;
else
dirty_ratelimit -= step;
bdi->dirty_ratelimit = max(dirty_ratelimit, 1UL);
bdi->balanced_dirty_ratelimit = balanced_dirty_ratelimit;
trace_bdi_dirty_ratelimit(bdi, dirty_rate, task_ratelimit);
}
void __bdi_update_bandwidth(struct backing_dev_info *bdi,
unsigned long thresh,
unsigned long bg_thresh,
unsigned long dirty,
unsigned long bdi_thresh,
unsigned long bdi_dirty,
unsigned long start_time)
{
unsigned long now = jiffies;
unsigned long elapsed = now - bdi->bw_time_stamp;
unsigned long dirtied;
unsigned long written;
if (elapsed < BANDWIDTH_INTERVAL)
return;
dirtied = percpu_counter_read(&bdi->bdi_stat[BDI_DIRTIED]);
written = percpu_counter_read(&bdi->bdi_stat[BDI_WRITTEN]);
if (elapsed > HZ && time_before(bdi->bw_time_stamp, start_time))
goto snapshot;
if (thresh) {
global_update_bandwidth(thresh, dirty, now);
bdi_update_dirty_ratelimit(bdi, thresh, bg_thresh, dirty,
bdi_thresh, bdi_dirty,
dirtied, elapsed);
}
bdi_update_write_bandwidth(bdi, elapsed, written);
snapshot:
bdi->dirtied_stamp = dirtied;
bdi->written_stamp = written;
bdi->bw_time_stamp = now;
}
static void bdi_update_bandwidth(struct backing_dev_info *bdi,
unsigned long thresh,
unsigned long bg_thresh,
unsigned long dirty,
unsigned long bdi_thresh,
unsigned long bdi_dirty,
unsigned long start_time)
{
if (time_is_after_eq_jiffies(bdi->bw_time_stamp + BANDWIDTH_INTERVAL))
return;
spin_lock(&bdi->wb.list_lock);
__bdi_update_bandwidth(bdi, thresh, bg_thresh, dirty,
bdi_thresh, bdi_dirty, start_time);
spin_unlock(&bdi->wb.list_lock);
}
static unsigned long dirty_poll_interval(unsigned long dirty,
unsigned long thresh)
{
if (thresh > dirty)
return 1UL << (ilog2(thresh - dirty) >> 1);
return 1;
}
static unsigned long bdi_max_pause(struct backing_dev_info *bdi,
unsigned long bdi_dirty)
{
unsigned long bw = bdi->avg_write_bandwidth;
unsigned long hi = ilog2(bw);
unsigned long lo = ilog2(bdi->dirty_ratelimit);
unsigned long t;
t = HZ / 50;
if (hi > lo)
t += (hi - lo) * (20 * HZ) / 1024;
t = min(t, bdi_dirty * HZ / (8 * bw + 1));
return clamp_val(t, 4, MAX_PAUSE);
}
static void balance_dirty_pages(struct address_space *mapping,
unsigned long pages_dirtied)
{
unsigned long nr_reclaimable;
unsigned long bdi_reclaimable;
unsigned long nr_dirty;
unsigned long bdi_dirty;
unsigned long freerun;
unsigned long background_thresh;
unsigned long dirty_thresh;
unsigned long bdi_thresh;
long pause = 0;
long uninitialized_var(max_pause);
bool dirty_exceeded = false;
unsigned long task_ratelimit;
unsigned long uninitialized_var(dirty_ratelimit);
unsigned long pos_ratio;
struct backing_dev_info *bdi = mapping->backing_dev_info;
unsigned long start_time = jiffies;
for (;;) {
nr_reclaimable = global_page_state(NR_FILE_DIRTY) +
global_page_state(NR_UNSTABLE_NFS);
nr_dirty = nr_reclaimable + global_page_state(NR_WRITEBACK);
global_dirty_limits(&background_thresh, &dirty_thresh);
freerun = dirty_freerun_ceiling(dirty_thresh,
background_thresh);
if (nr_dirty <= freerun)
break;
if (unlikely(!writeback_in_progress(bdi)))
bdi_start_background_writeback(bdi);
bdi_thresh = bdi_dirty_limit(bdi, dirty_thresh);
if (bdi_thresh < 2 * bdi_stat_error(bdi)) {
bdi_reclaimable = bdi_stat_sum(bdi, BDI_RECLAIMABLE);
bdi_dirty = bdi_reclaimable +
bdi_stat_sum(bdi, BDI_WRITEBACK);
} else {
bdi_reclaimable = bdi_stat(bdi, BDI_RECLAIMABLE);
bdi_dirty = bdi_reclaimable +
bdi_stat(bdi, BDI_WRITEBACK);
}
dirty_exceeded = (bdi_dirty > bdi_thresh) ||
(nr_dirty > dirty_thresh);
if (dirty_exceeded && !bdi->dirty_exceeded)
bdi->dirty_exceeded = 1;
bdi_update_bandwidth(bdi, dirty_thresh, background_thresh,
nr_dirty, bdi_thresh, bdi_dirty,
start_time);
max_pause = bdi_max_pause(bdi, bdi_dirty);
dirty_ratelimit = bdi->dirty_ratelimit;
pos_ratio = bdi_position_ratio(bdi, dirty_thresh,
background_thresh, nr_dirty,
bdi_thresh, bdi_dirty);
task_ratelimit = ((u64)dirty_ratelimit * pos_ratio) >>
RATELIMIT_CALC_SHIFT;
if (unlikely(task_ratelimit == 0)) {
pause = max_pause;
goto pause;
}
pause = HZ * pages_dirtied / task_ratelimit;
if (unlikely(pause <= 0)) {
trace_balance_dirty_pages(bdi,
dirty_thresh,
background_thresh,
nr_dirty,
bdi_thresh,
bdi_dirty,
dirty_ratelimit,
task_ratelimit,
pages_dirtied,
pause,
start_time);
pause = 1;
break;
}
pause = min(pause, max_pause);
pause:
trace_balance_dirty_pages(bdi,
dirty_thresh,
background_thresh,
nr_dirty,
bdi_thresh,
bdi_dirty,
dirty_ratelimit,
task_ratelimit,
pages_dirtied,
pause,
start_time);
__set_current_state(TASK_KILLABLE);
io_schedule_timeout(pause);
if (task_ratelimit)
break;
if (bdi_dirty <= bdi_stat_error(bdi))
break;
if (fatal_signal_pending(current))
break;
}
if (!dirty_exceeded && bdi->dirty_exceeded)
bdi->dirty_exceeded = 0;
current->nr_dirtied = 0;
if (pause == 0) {
current->nr_dirtied_pause =
dirty_poll_interval(nr_dirty, dirty_thresh);
} else if (pause <= max_pause / 4 &&
pages_dirtied >= current->nr_dirtied_pause) {
current->nr_dirtied_pause = clamp_val(
dirty_ratelimit * (max_pause / 2) / HZ,
pages_dirtied + pages_dirtied / 8,
pages_dirtied * 4);
} else if (pause >= max_pause) {
current->nr_dirtied_pause = 1 | clamp_val(
dirty_ratelimit * (max_pause / 2) / HZ,
pages_dirtied / 4,
pages_dirtied - pages_dirtied / 8);
}
if (writeback_in_progress(bdi))
return;
if (laptop_mode)
return;
if (nr_reclaimable > background_thresh)
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
struct backing_dev_info *bdi = mapping->backing_dev_info;
int ratelimit;
int *p;
if (!bdi_cap_account_dirty(bdi))
return;
ratelimit = current->nr_dirtied_pause;
if (bdi->dirty_exceeded)
ratelimit = min(ratelimit, 32 >> (PAGE_SHIFT - 10));
current->nr_dirtied += nr_pages_dirtied;
preempt_disable();
p = &__get_cpu_var(bdp_ratelimits);
if (unlikely(current->nr_dirtied >= ratelimit))
*p = 0;
else {
*p += nr_pages_dirtied;
if (unlikely(*p >= ratelimit_pages)) {
*p = 0;
ratelimit = 0;
}
}
preempt_enable();
if (unlikely(current->nr_dirtied >= ratelimit))
balance_dirty_pages(mapping, current->nr_dirtied);
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
bdi_start_writeback(&q->backing_dev_info, nr_pages,
WB_REASON_LAPTOP_TIMER);
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
unsigned long background_thresh;
unsigned long dirty_thresh;
global_dirty_limits(&background_thresh, &dirty_thresh);
ratelimit_pages = dirty_thresh / (num_online_cpus() * 32);
if (ratelimit_pages < 16)
ratelimit_pages = 16;
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
if (wbc->sync_mode == WB_SYNC_ALL || wbc->tagged_writepages)
tag = PAGECACHE_TAG_TOWRITE;
else
tag = PAGECACHE_TAG_DIRTY;
retry:
if (wbc->sync_mode == WB_SYNC_ALL || wbc->tagged_writepages)
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
__inc_bdi_stat(mapping->backing_dev_info, BDI_DIRTIED);
task_io_account_write(PAGE_CACHE_SIZE);
}
}
void account_page_writeback(struct page *page)
{
inc_zone_page_state(page, NR_WRITEBACK);
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
if (ret) {
dec_zone_page_state(page, NR_WRITEBACK);
inc_zone_page_state(page, NR_WRITTEN);
}
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
return radix_tree_tagged(&mapping->page_tree, tag);
}
