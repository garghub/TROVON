void bdi_lock_two(struct bdi_writeback *wb1, struct bdi_writeback *wb2)
{
if (wb1 < wb2) {
spin_lock(&wb1->list_lock);
spin_lock_nested(&wb2->list_lock, 1);
} else {
spin_lock(&wb2->list_lock);
spin_lock_nested(&wb1->list_lock, 1);
}
}
static void bdi_debug_init(void)
{
bdi_debug_root = debugfs_create_dir("bdi", NULL);
}
static int bdi_debug_stats_show(struct seq_file *m, void *v)
{
struct backing_dev_info *bdi = m->private;
struct bdi_writeback *wb = &bdi->wb;
unsigned long background_thresh;
unsigned long dirty_thresh;
unsigned long bdi_thresh;
unsigned long nr_dirty, nr_io, nr_more_io;
struct inode *inode;
nr_dirty = nr_io = nr_more_io = 0;
spin_lock(&wb->list_lock);
list_for_each_entry(inode, &wb->b_dirty, i_wb_list)
nr_dirty++;
list_for_each_entry(inode, &wb->b_io, i_wb_list)
nr_io++;
list_for_each_entry(inode, &wb->b_more_io, i_wb_list)
nr_more_io++;
spin_unlock(&wb->list_lock);
global_dirty_limits(&background_thresh, &dirty_thresh);
bdi_thresh = bdi_dirty_limit(bdi, dirty_thresh);
#define K(x) ((x) << (PAGE_SHIFT - 10))
seq_printf(m,
"BdiWriteback: %10lu kB\n"
"BdiReclaimable: %10lu kB\n"
"BdiDirtyThresh: %10lu kB\n"
"DirtyThresh: %10lu kB\n"
"BackgroundThresh: %10lu kB\n"
"BdiDirtied: %10lu kB\n"
"BdiWritten: %10lu kB\n"
"BdiWriteBandwidth: %10lu kBps\n"
"b_dirty: %10lu\n"
"b_io: %10lu\n"
"b_more_io: %10lu\n"
"bdi_list: %10u\n"
"state: %10lx\n",
(unsigned long) K(bdi_stat(bdi, BDI_WRITEBACK)),
(unsigned long) K(bdi_stat(bdi, BDI_RECLAIMABLE)),
K(bdi_thresh),
K(dirty_thresh),
K(background_thresh),
(unsigned long) K(bdi_stat(bdi, BDI_DIRTIED)),
(unsigned long) K(bdi_stat(bdi, BDI_WRITTEN)),
(unsigned long) K(bdi->write_bandwidth),
nr_dirty,
nr_io,
nr_more_io,
!list_empty(&bdi->bdi_list), bdi->state);
#undef K
return 0;
}
static int bdi_debug_stats_open(struct inode *inode, struct file *file)
{
return single_open(file, bdi_debug_stats_show, inode->i_private);
}
static void bdi_debug_register(struct backing_dev_info *bdi, const char *name)
{
bdi->debug_dir = debugfs_create_dir(name, bdi_debug_root);
bdi->debug_stats = debugfs_create_file("stats", 0444, bdi->debug_dir,
bdi, &bdi_debug_stats_fops);
}
static void bdi_debug_unregister(struct backing_dev_info *bdi)
{
debugfs_remove(bdi->debug_stats);
debugfs_remove(bdi->debug_dir);
}
static inline void bdi_debug_init(void)
{
}
static inline void bdi_debug_register(struct backing_dev_info *bdi,
const char *name)
{
}
static inline void bdi_debug_unregister(struct backing_dev_info *bdi)
{
}
static ssize_t read_ahead_kb_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct backing_dev_info *bdi = dev_get_drvdata(dev);
unsigned long read_ahead_kb;
ssize_t ret;
ret = kstrtoul(buf, 10, &read_ahead_kb);
if (ret < 0)
return ret;
bdi->ra_pages = read_ahead_kb >> (PAGE_SHIFT - 10);
return count;
}
static ssize_t min_ratio_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct backing_dev_info *bdi = dev_get_drvdata(dev);
unsigned int ratio;
ssize_t ret;
ret = kstrtouint(buf, 10, &ratio);
if (ret < 0)
return ret;
ret = bdi_set_min_ratio(bdi, ratio);
if (!ret)
ret = count;
return ret;
}
static ssize_t max_ratio_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct backing_dev_info *bdi = dev_get_drvdata(dev);
unsigned int ratio;
ssize_t ret;
ret = kstrtouint(buf, 10, &ratio);
if (ret < 0)
return ret;
ret = bdi_set_max_ratio(bdi, ratio);
if (!ret)
ret = count;
return ret;
}
static ssize_t stable_pages_required_show(struct device *dev,
struct device_attribute *attr,
char *page)
{
struct backing_dev_info *bdi = dev_get_drvdata(dev);
return snprintf(page, PAGE_SIZE-1, "%d\n",
bdi_cap_stable_pages_required(bdi) ? 1 : 0);
}
static __init int bdi_class_init(void)
{
bdi_class = class_create(THIS_MODULE, "bdi");
if (IS_ERR(bdi_class))
return PTR_ERR(bdi_class);
bdi_class->dev_groups = bdi_dev_groups;
bdi_debug_init();
return 0;
}
static int __init default_bdi_init(void)
{
int err;
bdi_wq = alloc_workqueue("writeback", WQ_MEM_RECLAIM | WQ_FREEZABLE |
WQ_UNBOUND | WQ_SYSFS, 0);
if (!bdi_wq)
return -ENOMEM;
err = bdi_init(&default_backing_dev_info);
if (!err)
bdi_register(&default_backing_dev_info, NULL, "default");
err = bdi_init(&noop_backing_dev_info);
return err;
}
int bdi_has_dirty_io(struct backing_dev_info *bdi)
{
return wb_has_dirty_io(&bdi->wb);
}
void bdi_wakeup_thread_delayed(struct backing_dev_info *bdi)
{
unsigned long timeout;
timeout = msecs_to_jiffies(dirty_writeback_interval * 10);
mod_delayed_work(bdi_wq, &bdi->wb.dwork, timeout);
}
static void bdi_remove_from_list(struct backing_dev_info *bdi)
{
spin_lock_bh(&bdi_lock);
list_del_rcu(&bdi->bdi_list);
spin_unlock_bh(&bdi_lock);
synchronize_rcu_expedited();
INIT_LIST_HEAD(&bdi->bdi_list);
}
int bdi_register(struct backing_dev_info *bdi, struct device *parent,
const char *fmt, ...)
{
va_list args;
struct device *dev;
if (bdi->dev)
return 0;
va_start(args, fmt);
dev = device_create_vargs(bdi_class, parent, MKDEV(0, 0), bdi, fmt, args);
va_end(args);
if (IS_ERR(dev))
return PTR_ERR(dev);
bdi->dev = dev;
bdi_debug_register(bdi, dev_name(dev));
set_bit(BDI_registered, &bdi->state);
spin_lock_bh(&bdi_lock);
list_add_tail_rcu(&bdi->bdi_list, &bdi_list);
spin_unlock_bh(&bdi_lock);
trace_writeback_bdi_register(bdi);
return 0;
}
int bdi_register_dev(struct backing_dev_info *bdi, dev_t dev)
{
return bdi_register(bdi, NULL, "%u:%u", MAJOR(dev), MINOR(dev));
}
static void bdi_wb_shutdown(struct backing_dev_info *bdi)
{
if (!bdi_cap_writeback_dirty(bdi))
return;
bdi_remove_from_list(bdi);
mod_delayed_work(bdi_wq, &bdi->wb.dwork, 0);
flush_delayed_work(&bdi->wb.dwork);
WARN_ON(!list_empty(&bdi->work_list));
cancel_delayed_work_sync(&bdi->wb.dwork);
}
static void bdi_prune_sb(struct backing_dev_info *bdi)
{
struct super_block *sb;
spin_lock(&sb_lock);
list_for_each_entry(sb, &super_blocks, s_list) {
if (sb->s_bdi == bdi)
sb->s_bdi = &default_backing_dev_info;
}
spin_unlock(&sb_lock);
}
void bdi_unregister(struct backing_dev_info *bdi)
{
struct device *dev = bdi->dev;
if (dev) {
bdi_set_min_ratio(bdi, 0);
trace_writeback_bdi_unregister(bdi);
bdi_prune_sb(bdi);
bdi_wb_shutdown(bdi);
bdi_debug_unregister(bdi);
spin_lock_bh(&bdi->wb_lock);
bdi->dev = NULL;
spin_unlock_bh(&bdi->wb_lock);
device_unregister(dev);
}
}
static void bdi_wb_init(struct bdi_writeback *wb, struct backing_dev_info *bdi)
{
memset(wb, 0, sizeof(*wb));
wb->bdi = bdi;
wb->last_old_flush = jiffies;
INIT_LIST_HEAD(&wb->b_dirty);
INIT_LIST_HEAD(&wb->b_io);
INIT_LIST_HEAD(&wb->b_more_io);
spin_lock_init(&wb->list_lock);
INIT_DELAYED_WORK(&wb->dwork, bdi_writeback_workfn);
}
int bdi_init(struct backing_dev_info *bdi)
{
int i, err;
bdi->dev = NULL;
bdi->min_ratio = 0;
bdi->max_ratio = 100;
bdi->max_prop_frac = FPROP_FRAC_BASE;
spin_lock_init(&bdi->wb_lock);
INIT_LIST_HEAD(&bdi->bdi_list);
INIT_LIST_HEAD(&bdi->work_list);
bdi_wb_init(&bdi->wb, bdi);
for (i = 0; i < NR_BDI_STAT_ITEMS; i++) {
err = percpu_counter_init(&bdi->bdi_stat[i], 0);
if (err)
goto err;
}
bdi->dirty_exceeded = 0;
bdi->bw_time_stamp = jiffies;
bdi->written_stamp = 0;
bdi->balanced_dirty_ratelimit = INIT_BW;
bdi->dirty_ratelimit = INIT_BW;
bdi->write_bandwidth = INIT_BW;
bdi->avg_write_bandwidth = INIT_BW;
err = fprop_local_init_percpu(&bdi->completions);
if (err) {
err:
while (i--)
percpu_counter_destroy(&bdi->bdi_stat[i]);
}
return err;
}
void bdi_destroy(struct backing_dev_info *bdi)
{
int i;
if (bdi_has_dirty_io(bdi)) {
struct bdi_writeback *dst = &default_backing_dev_info.wb;
bdi_lock_two(&bdi->wb, dst);
list_splice(&bdi->wb.b_dirty, &dst->b_dirty);
list_splice(&bdi->wb.b_io, &dst->b_io);
list_splice(&bdi->wb.b_more_io, &dst->b_more_io);
spin_unlock(&bdi->wb.list_lock);
spin_unlock(&dst->list_lock);
}
bdi_unregister(bdi);
cancel_delayed_work_sync(&bdi->wb.dwork);
for (i = 0; i < NR_BDI_STAT_ITEMS; i++)
percpu_counter_destroy(&bdi->bdi_stat[i]);
fprop_local_destroy_percpu(&bdi->completions);
}
int bdi_setup_and_register(struct backing_dev_info *bdi, char *name,
unsigned int cap)
{
int err;
bdi->name = name;
bdi->capabilities = cap;
err = bdi_init(bdi);
if (err)
return err;
err = bdi_register(bdi, NULL, "%.28s-%ld", name,
atomic_long_inc_return(&bdi_seq));
if (err) {
bdi_destroy(bdi);
return err;
}
return 0;
}
void clear_bdi_congested(struct backing_dev_info *bdi, int sync)
{
enum bdi_state bit;
wait_queue_head_t *wqh = &congestion_wqh[sync];
bit = sync ? BDI_sync_congested : BDI_async_congested;
if (test_and_clear_bit(bit, &bdi->state))
atomic_dec(&nr_bdi_congested[sync]);
smp_mb__after_clear_bit();
if (waitqueue_active(wqh))
wake_up(wqh);
}
void set_bdi_congested(struct backing_dev_info *bdi, int sync)
{
enum bdi_state bit;
bit = sync ? BDI_sync_congested : BDI_async_congested;
if (!test_and_set_bit(bit, &bdi->state))
atomic_inc(&nr_bdi_congested[sync]);
}
long congestion_wait(int sync, long timeout)
{
long ret;
unsigned long start = jiffies;
DEFINE_WAIT(wait);
wait_queue_head_t *wqh = &congestion_wqh[sync];
prepare_to_wait(wqh, &wait, TASK_UNINTERRUPTIBLE);
ret = io_schedule_timeout(timeout);
finish_wait(wqh, &wait);
trace_writeback_congestion_wait(jiffies_to_usecs(timeout),
jiffies_to_usecs(jiffies - start));
return ret;
}
long wait_iff_congested(struct zone *zone, int sync, long timeout)
{
long ret;
unsigned long start = jiffies;
DEFINE_WAIT(wait);
wait_queue_head_t *wqh = &congestion_wqh[sync];
if (atomic_read(&nr_bdi_congested[sync]) == 0 ||
!zone_is_reclaim_congested(zone)) {
cond_resched();
ret = timeout - (jiffies - start);
if (ret < 0)
ret = 0;
goto out;
}
prepare_to_wait(wqh, &wait, TASK_UNINTERRUPTIBLE);
ret = io_schedule_timeout(timeout);
finish_wait(wqh, &wait);
out:
trace_writeback_wait_iff_congested(jiffies_to_usecs(timeout),
jiffies_to_usecs(jiffies - start));
return ret;
}
int pdflush_proc_obsolete(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
char kbuf[] = "0\n";
if (*ppos || *lenp < sizeof(kbuf)) {
*lenp = 0;
return 0;
}
if (copy_to_user(buffer, kbuf, sizeof(kbuf)))
return -EFAULT;
printk_once(KERN_WARNING "%s exported in /proc is scheduled for removal\n",
table->procname);
*lenp = 2;
*ppos += *lenp;
return 2;
}
