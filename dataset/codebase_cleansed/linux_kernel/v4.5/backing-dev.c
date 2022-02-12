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
unsigned long wb_thresh;
unsigned long nr_dirty, nr_io, nr_more_io, nr_dirty_time;
struct inode *inode;
nr_dirty = nr_io = nr_more_io = nr_dirty_time = 0;
spin_lock(&wb->list_lock);
list_for_each_entry(inode, &wb->b_dirty, i_io_list)
nr_dirty++;
list_for_each_entry(inode, &wb->b_io, i_io_list)
nr_io++;
list_for_each_entry(inode, &wb->b_more_io, i_io_list)
nr_more_io++;
list_for_each_entry(inode, &wb->b_dirty_time, i_io_list)
if (inode->i_state & I_DIRTY_TIME)
nr_dirty_time++;
spin_unlock(&wb->list_lock);
global_dirty_limits(&background_thresh, &dirty_thresh);
wb_thresh = wb_calc_thresh(wb, dirty_thresh);
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
"b_dirty_time: %10lu\n"
"bdi_list: %10u\n"
"state: %10lx\n",
(unsigned long) K(wb_stat(wb, WB_WRITEBACK)),
(unsigned long) K(wb_stat(wb, WB_RECLAIMABLE)),
K(wb_thresh),
K(dirty_thresh),
K(background_thresh),
(unsigned long) K(wb_stat(wb, WB_DIRTIED)),
(unsigned long) K(wb_stat(wb, WB_WRITTEN)),
(unsigned long) K(wb->write_bandwidth),
nr_dirty,
nr_io,
nr_more_io,
nr_dirty_time,
!list_empty(&bdi->bdi_list), bdi->wb.state);
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
err = bdi_init(&noop_backing_dev_info);
return err;
}
void wb_wakeup_delayed(struct bdi_writeback *wb)
{
unsigned long timeout;
timeout = msecs_to_jiffies(dirty_writeback_interval * 10);
spin_lock_bh(&wb->work_lock);
if (test_bit(WB_registered, &wb->state))
queue_delayed_work(bdi_wq, &wb->dwork, timeout);
spin_unlock_bh(&wb->work_lock);
}
static int wb_init(struct bdi_writeback *wb, struct backing_dev_info *bdi,
int blkcg_id, gfp_t gfp)
{
int i, err;
memset(wb, 0, sizeof(*wb));
wb->bdi = bdi;
wb->last_old_flush = jiffies;
INIT_LIST_HEAD(&wb->b_dirty);
INIT_LIST_HEAD(&wb->b_io);
INIT_LIST_HEAD(&wb->b_more_io);
INIT_LIST_HEAD(&wb->b_dirty_time);
spin_lock_init(&wb->list_lock);
wb->bw_time_stamp = jiffies;
wb->balanced_dirty_ratelimit = INIT_BW;
wb->dirty_ratelimit = INIT_BW;
wb->write_bandwidth = INIT_BW;
wb->avg_write_bandwidth = INIT_BW;
spin_lock_init(&wb->work_lock);
INIT_LIST_HEAD(&wb->work_list);
INIT_DELAYED_WORK(&wb->dwork, wb_workfn);
wb->congested = wb_congested_get_create(bdi, blkcg_id, gfp);
if (!wb->congested)
return -ENOMEM;
err = fprop_local_init_percpu(&wb->completions, gfp);
if (err)
goto out_put_cong;
for (i = 0; i < NR_WB_STAT_ITEMS; i++) {
err = percpu_counter_init(&wb->stat[i], 0, gfp);
if (err)
goto out_destroy_stat;
}
return 0;
out_destroy_stat:
while (i--)
percpu_counter_destroy(&wb->stat[i]);
fprop_local_destroy_percpu(&wb->completions);
out_put_cong:
wb_congested_put(wb->congested);
return err;
}
static void wb_shutdown(struct bdi_writeback *wb)
{
spin_lock_bh(&wb->work_lock);
if (!test_and_clear_bit(WB_registered, &wb->state)) {
spin_unlock_bh(&wb->work_lock);
return;
}
spin_unlock_bh(&wb->work_lock);
mod_delayed_work(bdi_wq, &wb->dwork, 0);
flush_delayed_work(&wb->dwork);
WARN_ON(!list_empty(&wb->work_list));
}
static void wb_exit(struct bdi_writeback *wb)
{
int i;
WARN_ON(delayed_work_pending(&wb->dwork));
for (i = 0; i < NR_WB_STAT_ITEMS; i++)
percpu_counter_destroy(&wb->stat[i]);
fprop_local_destroy_percpu(&wb->completions);
wb_congested_put(wb->congested);
}
struct bdi_writeback_congested *
wb_congested_get_create(struct backing_dev_info *bdi, int blkcg_id, gfp_t gfp)
{
struct bdi_writeback_congested *new_congested = NULL, *congested;
struct rb_node **node, *parent;
unsigned long flags;
retry:
spin_lock_irqsave(&cgwb_lock, flags);
node = &bdi->cgwb_congested_tree.rb_node;
parent = NULL;
while (*node != NULL) {
parent = *node;
congested = container_of(parent, struct bdi_writeback_congested,
rb_node);
if (congested->blkcg_id < blkcg_id)
node = &parent->rb_left;
else if (congested->blkcg_id > blkcg_id)
node = &parent->rb_right;
else
goto found;
}
if (new_congested) {
congested = new_congested;
new_congested = NULL;
rb_link_node(&congested->rb_node, parent, node);
rb_insert_color(&congested->rb_node, &bdi->cgwb_congested_tree);
goto found;
}
spin_unlock_irqrestore(&cgwb_lock, flags);
new_congested = kzalloc(sizeof(*new_congested), gfp);
if (!new_congested)
return NULL;
atomic_set(&new_congested->refcnt, 0);
new_congested->bdi = bdi;
new_congested->blkcg_id = blkcg_id;
goto retry;
found:
atomic_inc(&congested->refcnt);
spin_unlock_irqrestore(&cgwb_lock, flags);
kfree(new_congested);
return congested;
}
void wb_congested_put(struct bdi_writeback_congested *congested)
{
unsigned long flags;
local_irq_save(flags);
if (!atomic_dec_and_lock(&congested->refcnt, &cgwb_lock)) {
local_irq_restore(flags);
return;
}
if (congested->bdi) {
rb_erase(&congested->rb_node,
&congested->bdi->cgwb_congested_tree);
congested->bdi = NULL;
}
spin_unlock_irqrestore(&cgwb_lock, flags);
kfree(congested);
}
static void cgwb_release_workfn(struct work_struct *work)
{
struct bdi_writeback *wb = container_of(work, struct bdi_writeback,
release_work);
struct backing_dev_info *bdi = wb->bdi;
spin_lock_irq(&cgwb_lock);
list_del_rcu(&wb->bdi_node);
spin_unlock_irq(&cgwb_lock);
wb_shutdown(wb);
css_put(wb->memcg_css);
css_put(wb->blkcg_css);
fprop_local_destroy_percpu(&wb->memcg_completions);
percpu_ref_exit(&wb->refcnt);
wb_exit(wb);
kfree_rcu(wb, rcu);
if (atomic_dec_and_test(&bdi->usage_cnt))
wake_up_all(&cgwb_release_wait);
}
static void cgwb_release(struct percpu_ref *refcnt)
{
struct bdi_writeback *wb = container_of(refcnt, struct bdi_writeback,
refcnt);
schedule_work(&wb->release_work);
}
static void cgwb_kill(struct bdi_writeback *wb)
{
lockdep_assert_held(&cgwb_lock);
WARN_ON(!radix_tree_delete(&wb->bdi->cgwb_tree, wb->memcg_css->id));
list_del(&wb->memcg_node);
list_del(&wb->blkcg_node);
percpu_ref_kill(&wb->refcnt);
}
static int cgwb_create(struct backing_dev_info *bdi,
struct cgroup_subsys_state *memcg_css, gfp_t gfp)
{
struct mem_cgroup *memcg;
struct cgroup_subsys_state *blkcg_css;
struct blkcg *blkcg;
struct list_head *memcg_cgwb_list, *blkcg_cgwb_list;
struct bdi_writeback *wb;
unsigned long flags;
int ret = 0;
memcg = mem_cgroup_from_css(memcg_css);
blkcg_css = cgroup_get_e_css(memcg_css->cgroup, &io_cgrp_subsys);
blkcg = css_to_blkcg(blkcg_css);
memcg_cgwb_list = mem_cgroup_cgwb_list(memcg);
blkcg_cgwb_list = &blkcg->cgwb_list;
spin_lock_irqsave(&cgwb_lock, flags);
wb = radix_tree_lookup(&bdi->cgwb_tree, memcg_css->id);
if (wb && wb->blkcg_css != blkcg_css) {
cgwb_kill(wb);
wb = NULL;
}
spin_unlock_irqrestore(&cgwb_lock, flags);
if (wb)
goto out_put;
wb = kmalloc(sizeof(*wb), gfp);
if (!wb)
return -ENOMEM;
ret = wb_init(wb, bdi, blkcg_css->id, gfp);
if (ret)
goto err_free;
ret = percpu_ref_init(&wb->refcnt, cgwb_release, 0, gfp);
if (ret)
goto err_wb_exit;
ret = fprop_local_init_percpu(&wb->memcg_completions, gfp);
if (ret)
goto err_ref_exit;
wb->memcg_css = memcg_css;
wb->blkcg_css = blkcg_css;
INIT_WORK(&wb->release_work, cgwb_release_workfn);
set_bit(WB_registered, &wb->state);
ret = -ENODEV;
spin_lock_irqsave(&cgwb_lock, flags);
if (test_bit(WB_registered, &bdi->wb.state) &&
blkcg_cgwb_list->next && memcg_cgwb_list->next) {
ret = radix_tree_insert(&bdi->cgwb_tree, memcg_css->id, wb);
if (!ret) {
atomic_inc(&bdi->usage_cnt);
list_add_tail_rcu(&wb->bdi_node, &bdi->wb_list);
list_add(&wb->memcg_node, memcg_cgwb_list);
list_add(&wb->blkcg_node, blkcg_cgwb_list);
css_get(memcg_css);
css_get(blkcg_css);
}
}
spin_unlock_irqrestore(&cgwb_lock, flags);
if (ret) {
if (ret == -EEXIST)
ret = 0;
goto err_fprop_exit;
}
goto out_put;
err_fprop_exit:
fprop_local_destroy_percpu(&wb->memcg_completions);
err_ref_exit:
percpu_ref_exit(&wb->refcnt);
err_wb_exit:
wb_exit(wb);
err_free:
kfree(wb);
out_put:
css_put(blkcg_css);
return ret;
}
struct bdi_writeback *wb_get_create(struct backing_dev_info *bdi,
struct cgroup_subsys_state *memcg_css,
gfp_t gfp)
{
struct bdi_writeback *wb;
might_sleep_if(gfpflags_allow_blocking(gfp));
if (!memcg_css->parent)
return &bdi->wb;
do {
rcu_read_lock();
wb = radix_tree_lookup(&bdi->cgwb_tree, memcg_css->id);
if (wb) {
struct cgroup_subsys_state *blkcg_css;
blkcg_css = cgroup_get_e_css(memcg_css->cgroup,
&io_cgrp_subsys);
if (unlikely(wb->blkcg_css != blkcg_css ||
!wb_tryget(wb)))
wb = NULL;
css_put(blkcg_css);
}
rcu_read_unlock();
} while (!wb && !cgwb_create(bdi, memcg_css, gfp));
return wb;
}
static int cgwb_bdi_init(struct backing_dev_info *bdi)
{
int ret;
INIT_RADIX_TREE(&bdi->cgwb_tree, GFP_ATOMIC);
bdi->cgwb_congested_tree = RB_ROOT;
atomic_set(&bdi->usage_cnt, 1);
ret = wb_init(&bdi->wb, bdi, 1, GFP_KERNEL);
if (!ret) {
bdi->wb.memcg_css = &root_mem_cgroup->css;
bdi->wb.blkcg_css = blkcg_root_css;
}
return ret;
}
static void cgwb_bdi_destroy(struct backing_dev_info *bdi)
{
struct radix_tree_iter iter;
struct rb_node *rbn;
void **slot;
WARN_ON(test_bit(WB_registered, &bdi->wb.state));
spin_lock_irq(&cgwb_lock);
radix_tree_for_each_slot(slot, &bdi->cgwb_tree, &iter, 0)
cgwb_kill(*slot);
while ((rbn = rb_first(&bdi->cgwb_congested_tree))) {
struct bdi_writeback_congested *congested =
rb_entry(rbn, struct bdi_writeback_congested, rb_node);
rb_erase(rbn, &bdi->cgwb_congested_tree);
congested->bdi = NULL;
}
spin_unlock_irq(&cgwb_lock);
atomic_dec(&bdi->usage_cnt);
wait_event(cgwb_release_wait, !atomic_read(&bdi->usage_cnt));
}
void wb_memcg_offline(struct mem_cgroup *memcg)
{
LIST_HEAD(to_destroy);
struct list_head *memcg_cgwb_list = mem_cgroup_cgwb_list(memcg);
struct bdi_writeback *wb, *next;
spin_lock_irq(&cgwb_lock);
list_for_each_entry_safe(wb, next, memcg_cgwb_list, memcg_node)
cgwb_kill(wb);
memcg_cgwb_list->next = NULL;
spin_unlock_irq(&cgwb_lock);
}
void wb_blkcg_offline(struct blkcg *blkcg)
{
LIST_HEAD(to_destroy);
struct bdi_writeback *wb, *next;
spin_lock_irq(&cgwb_lock);
list_for_each_entry_safe(wb, next, &blkcg->cgwb_list, blkcg_node)
cgwb_kill(wb);
blkcg->cgwb_list.next = NULL;
spin_unlock_irq(&cgwb_lock);
}
static int cgwb_bdi_init(struct backing_dev_info *bdi)
{
int err;
bdi->wb_congested = kzalloc(sizeof(*bdi->wb_congested), GFP_KERNEL);
if (!bdi->wb_congested)
return -ENOMEM;
err = wb_init(&bdi->wb, bdi, 1, GFP_KERNEL);
if (err) {
kfree(bdi->wb_congested);
return err;
}
return 0;
}
static void cgwb_bdi_destroy(struct backing_dev_info *bdi) { }
int bdi_init(struct backing_dev_info *bdi)
{
int ret;
bdi->dev = NULL;
bdi->min_ratio = 0;
bdi->max_ratio = 100;
bdi->max_prop_frac = FPROP_FRAC_BASE;
INIT_LIST_HEAD(&bdi->bdi_list);
INIT_LIST_HEAD(&bdi->wb_list);
init_waitqueue_head(&bdi->wb_waitq);
ret = cgwb_bdi_init(bdi);
list_add_tail_rcu(&bdi->wb.bdi_node, &bdi->wb_list);
return ret;
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
set_bit(WB_registered, &bdi->wb.state);
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
static void bdi_remove_from_list(struct backing_dev_info *bdi)
{
spin_lock_bh(&bdi_lock);
list_del_rcu(&bdi->bdi_list);
spin_unlock_bh(&bdi_lock);
synchronize_rcu_expedited();
}
void bdi_unregister(struct backing_dev_info *bdi)
{
bdi_remove_from_list(bdi);
wb_shutdown(&bdi->wb);
cgwb_bdi_destroy(bdi);
if (bdi->dev) {
bdi_debug_unregister(bdi);
device_unregister(bdi->dev);
bdi->dev = NULL;
}
}
void bdi_exit(struct backing_dev_info *bdi)
{
WARN_ON_ONCE(bdi->dev);
wb_exit(&bdi->wb);
}
void bdi_destroy(struct backing_dev_info *bdi)
{
bdi_unregister(bdi);
bdi_exit(bdi);
}
int bdi_setup_and_register(struct backing_dev_info *bdi, char *name)
{
int err;
bdi->name = name;
bdi->capabilities = 0;
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
void clear_wb_congested(struct bdi_writeback_congested *congested, int sync)
{
wait_queue_head_t *wqh = &congestion_wqh[sync];
enum wb_state bit;
bit = sync ? WB_sync_congested : WB_async_congested;
if (test_and_clear_bit(bit, &congested->state))
atomic_dec(&nr_wb_congested[sync]);
smp_mb__after_atomic();
if (waitqueue_active(wqh))
wake_up(wqh);
}
void set_wb_congested(struct bdi_writeback_congested *congested, int sync)
{
enum wb_state bit;
bit = sync ? WB_sync_congested : WB_async_congested;
if (!test_and_set_bit(bit, &congested->state))
atomic_inc(&nr_wb_congested[sync]);
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
if (atomic_read(&nr_wb_congested[sync]) == 0 ||
!test_bit(ZONE_CONGESTED, &zone->flags)) {
if (current->flags & PF_WQ_WORKER)
schedule_timeout_uninterruptible(1);
else
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
