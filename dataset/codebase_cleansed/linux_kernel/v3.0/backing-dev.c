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
spin_lock(&inode_wb_list_lock);
list_for_each_entry(inode, &wb->b_dirty, i_wb_list)
nr_dirty++;
list_for_each_entry(inode, &wb->b_io, i_wb_list)
nr_io++;
list_for_each_entry(inode, &wb->b_more_io, i_wb_list)
nr_more_io++;
spin_unlock(&inode_wb_list_lock);
global_dirty_limits(&background_thresh, &dirty_thresh);
bdi_thresh = bdi_dirty_limit(bdi, dirty_thresh);
#define K(x) ((x) << (PAGE_SHIFT - 10))
seq_printf(m,
"BdiWriteback: %8lu kB\n"
"BdiReclaimable: %8lu kB\n"
"BdiDirtyThresh: %8lu kB\n"
"DirtyThresh: %8lu kB\n"
"BackgroundThresh: %8lu kB\n"
"b_dirty: %8lu\n"
"b_io: %8lu\n"
"b_more_io: %8lu\n"
"bdi_list: %8u\n"
"state: %8lx\n",
(unsigned long) K(bdi_stat(bdi, BDI_WRITEBACK)),
(unsigned long) K(bdi_stat(bdi, BDI_RECLAIMABLE)),
K(bdi_thresh), K(dirty_thresh),
K(background_thresh), nr_dirty, nr_io, nr_more_io,
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
char *end;
unsigned long read_ahead_kb;
ssize_t ret = -EINVAL;
read_ahead_kb = simple_strtoul(buf, &end, 10);
if (*buf && (end[0] == '\0' || (end[0] == '\n' && end[1] == '\0'))) {
bdi->ra_pages = read_ahead_kb >> (PAGE_SHIFT - 10);
ret = count;
}
return ret;
}
static ssize_t min_ratio_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct backing_dev_info *bdi = dev_get_drvdata(dev);
char *end;
unsigned int ratio;
ssize_t ret = -EINVAL;
ratio = simple_strtoul(buf, &end, 10);
if (*buf && (end[0] == '\0' || (end[0] == '\n' && end[1] == '\0'))) {
ret = bdi_set_min_ratio(bdi, ratio);
if (!ret)
ret = count;
}
return ret;
}
static ssize_t max_ratio_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct backing_dev_info *bdi = dev_get_drvdata(dev);
char *end;
unsigned int ratio;
ssize_t ret = -EINVAL;
ratio = simple_strtoul(buf, &end, 10);
if (*buf && (end[0] == '\0' || (end[0] == '\n' && end[1] == '\0'))) {
ret = bdi_set_max_ratio(bdi, ratio);
if (!ret)
ret = count;
}
return ret;
}
static __init int bdi_class_init(void)
{
bdi_class = class_create(THIS_MODULE, "bdi");
if (IS_ERR(bdi_class))
return PTR_ERR(bdi_class);
bdi_class->dev_attrs = bdi_dev_attrs;
bdi_debug_init();
return 0;
}
static int __init default_bdi_init(void)
{
int err;
sync_supers_tsk = kthread_run(bdi_sync_supers, NULL, "sync_supers");
BUG_ON(IS_ERR(sync_supers_tsk));
setup_timer(&sync_supers_timer, sync_supers_timer_fn, 0);
bdi_arm_supers_timer();
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
static void bdi_flush_io(struct backing_dev_info *bdi)
{
struct writeback_control wbc = {
.sync_mode = WB_SYNC_NONE,
.older_than_this = NULL,
.range_cyclic = 1,
.nr_to_write = 1024,
};
writeback_inodes_wb(&bdi->wb, &wbc);
}
static int bdi_sync_supers(void *unused)
{
set_user_nice(current, 0);
while (!kthread_should_stop()) {
set_current_state(TASK_INTERRUPTIBLE);
schedule();
sync_supers();
}
return 0;
}
void bdi_arm_supers_timer(void)
{
unsigned long next;
if (!dirty_writeback_interval)
return;
next = msecs_to_jiffies(dirty_writeback_interval * 10) + jiffies;
mod_timer(&sync_supers_timer, round_jiffies_up(next));
}
static void sync_supers_timer_fn(unsigned long unused)
{
wake_up_process(sync_supers_tsk);
bdi_arm_supers_timer();
}
static void wakeup_timer_fn(unsigned long data)
{
struct backing_dev_info *bdi = (struct backing_dev_info *)data;
spin_lock_bh(&bdi->wb_lock);
if (bdi->wb.task) {
trace_writeback_wake_thread(bdi);
wake_up_process(bdi->wb.task);
} else {
trace_writeback_wake_forker_thread(bdi);
wake_up_process(default_backing_dev_info.wb.task);
}
spin_unlock_bh(&bdi->wb_lock);
}
void bdi_wakeup_thread_delayed(struct backing_dev_info *bdi)
{
unsigned long timeout;
timeout = msecs_to_jiffies(dirty_writeback_interval * 10);
mod_timer(&bdi->wb.wakeup_timer, jiffies + timeout);
}
static unsigned long bdi_longest_inactive(void)
{
unsigned long interval;
interval = msecs_to_jiffies(dirty_writeback_interval * 10);
return max(5UL * 60 * HZ, interval);
}
static int bdi_forker_thread(void *ptr)
{
struct bdi_writeback *me = ptr;
current->flags |= PF_SWAPWRITE;
set_freezable();
set_user_nice(current, 0);
for (;;) {
struct task_struct *task = NULL;
struct backing_dev_info *bdi;
enum {
NO_ACTION,
FORK_THREAD,
KILL_THREAD,
} action = NO_ACTION;
if (wb_has_dirty_io(me) || !list_empty(&me->bdi->work_list)) {
del_timer(&me->wakeup_timer);
wb_do_writeback(me, 0);
}
spin_lock_bh(&bdi_lock);
set_current_state(TASK_INTERRUPTIBLE);
list_for_each_entry(bdi, &bdi_list, bdi_list) {
bool have_dirty_io;
if (!bdi_cap_writeback_dirty(bdi) ||
bdi_cap_flush_forker(bdi))
continue;
WARN(!test_bit(BDI_registered, &bdi->state),
"bdi %p/%s is not registered!\n", bdi, bdi->name);
have_dirty_io = !list_empty(&bdi->work_list) ||
wb_has_dirty_io(&bdi->wb);
if (!bdi->wb.task && have_dirty_io) {
set_bit(BDI_pending, &bdi->state);
action = FORK_THREAD;
break;
}
spin_lock(&bdi->wb_lock);
if (bdi->wb.task && !have_dirty_io &&
time_after(jiffies, bdi->wb.last_active +
bdi_longest_inactive())) {
task = bdi->wb.task;
bdi->wb.task = NULL;
spin_unlock(&bdi->wb_lock);
set_bit(BDI_pending, &bdi->state);
action = KILL_THREAD;
break;
}
spin_unlock(&bdi->wb_lock);
}
spin_unlock_bh(&bdi_lock);
if (!list_empty(&me->bdi->work_list))
__set_current_state(TASK_RUNNING);
switch (action) {
case FORK_THREAD:
__set_current_state(TASK_RUNNING);
task = kthread_create(bdi_writeback_thread, &bdi->wb,
"flush-%s", dev_name(bdi->dev));
if (IS_ERR(task)) {
bdi_flush_io(bdi);
} else {
spin_lock_bh(&bdi->wb_lock);
bdi->wb.task = task;
spin_unlock_bh(&bdi->wb_lock);
wake_up_process(task);
}
break;
case KILL_THREAD:
__set_current_state(TASK_RUNNING);
kthread_stop(task);
break;
case NO_ACTION:
if (!wb_has_dirty_io(me) || !dirty_writeback_interval)
schedule_timeout(bdi_longest_inactive());
else
schedule_timeout(msecs_to_jiffies(dirty_writeback_interval * 10));
try_to_freeze();
continue;
}
clear_bit(BDI_pending, &bdi->state);
smp_mb__after_clear_bit();
wake_up_bit(&bdi->state, BDI_pending);
}
return 0;
}
static void bdi_remove_from_list(struct backing_dev_info *bdi)
{
spin_lock_bh(&bdi_lock);
list_del_rcu(&bdi->bdi_list);
spin_unlock_bh(&bdi_lock);
synchronize_rcu();
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
if (bdi_cap_flush_forker(bdi)) {
struct bdi_writeback *wb = &bdi->wb;
wb->task = kthread_run(bdi_forker_thread, wb, "bdi-%s",
dev_name(dev));
if (IS_ERR(wb->task))
return PTR_ERR(wb->task);
}
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
wait_on_bit(&bdi->state, BDI_pending, bdi_sched_wait,
TASK_UNINTERRUPTIBLE);
if (bdi->wb.task) {
thaw_process(bdi->wb.task);
kthread_stop(bdi->wb.task);
}
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
if (bdi->dev) {
trace_writeback_bdi_unregister(bdi);
bdi_prune_sb(bdi);
del_timer_sync(&bdi->wb.wakeup_timer);
if (!bdi_cap_flush_forker(bdi))
bdi_wb_shutdown(bdi);
bdi_debug_unregister(bdi);
device_unregister(bdi->dev);
bdi->dev = NULL;
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
setup_timer(&wb->wakeup_timer, wakeup_timer_fn, (unsigned long)bdi);
}
int bdi_init(struct backing_dev_info *bdi)
{
int i, err;
bdi->dev = NULL;
bdi->min_ratio = 0;
bdi->max_ratio = 100;
bdi->max_prop_frac = PROP_FRAC_BASE;
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
err = prop_local_init_percpu(&bdi->completions);
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
spin_lock(&inode_wb_list_lock);
list_splice(&bdi->wb.b_dirty, &dst->b_dirty);
list_splice(&bdi->wb.b_io, &dst->b_io);
list_splice(&bdi->wb.b_more_io, &dst->b_more_io);
spin_unlock(&inode_wb_list_lock);
}
bdi_unregister(bdi);
for (i = 0; i < NR_BDI_STAT_ITEMS; i++)
percpu_counter_destroy(&bdi->bdi_stat[i]);
prop_local_destroy_percpu(&bdi->completions);
}
int bdi_setup_and_register(struct backing_dev_info *bdi, char *name,
unsigned int cap)
{
char tmp[32];
int err;
bdi->name = name;
bdi->capabilities = cap;
err = bdi_init(bdi);
if (err)
return err;
sprintf(tmp, "%.28s%s", name, "-%d");
err = bdi_register(bdi, NULL, tmp, atomic_long_inc_return(&bdi_seq));
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
