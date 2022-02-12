static ssize_t
queue_var_show(unsigned long var, char *page)
{
return sprintf(page, "%lu\n", var);
}
static ssize_t
queue_var_store(unsigned long *var, const char *page, size_t count)
{
int err;
unsigned long v;
err = kstrtoul(page, 10, &v);
if (err || v > UINT_MAX)
return -EINVAL;
*var = v;
return count;
}
static ssize_t queue_requests_show(struct request_queue *q, char *page)
{
return queue_var_show(q->nr_requests, (page));
}
static ssize_t
queue_requests_store(struct request_queue *q, const char *page, size_t count)
{
unsigned long nr;
int ret, err;
if (!q->request_fn && !q->mq_ops)
return -EINVAL;
ret = queue_var_store(&nr, page, count);
if (ret < 0)
return ret;
if (nr < BLKDEV_MIN_RQ)
nr = BLKDEV_MIN_RQ;
if (q->request_fn)
err = blk_update_nr_requests(q, nr);
else
err = blk_mq_update_nr_requests(q, nr);
if (err)
return err;
return ret;
}
static ssize_t queue_ra_show(struct request_queue *q, char *page)
{
unsigned long ra_kb = q->backing_dev_info.ra_pages <<
(PAGE_SHIFT - 10);
return queue_var_show(ra_kb, (page));
}
static ssize_t
queue_ra_store(struct request_queue *q, const char *page, size_t count)
{
unsigned long ra_kb;
ssize_t ret = queue_var_store(&ra_kb, page, count);
if (ret < 0)
return ret;
q->backing_dev_info.ra_pages = ra_kb >> (PAGE_SHIFT - 10);
return ret;
}
static ssize_t queue_max_sectors_show(struct request_queue *q, char *page)
{
int max_sectors_kb = queue_max_sectors(q) >> 1;
return queue_var_show(max_sectors_kb, (page));
}
static ssize_t queue_max_segments_show(struct request_queue *q, char *page)
{
return queue_var_show(queue_max_segments(q), (page));
}
static ssize_t queue_max_integrity_segments_show(struct request_queue *q, char *page)
{
return queue_var_show(q->limits.max_integrity_segments, (page));
}
static ssize_t queue_max_segment_size_show(struct request_queue *q, char *page)
{
if (blk_queue_cluster(q))
return queue_var_show(queue_max_segment_size(q), (page));
return queue_var_show(PAGE_SIZE, (page));
}
static ssize_t queue_logical_block_size_show(struct request_queue *q, char *page)
{
return queue_var_show(queue_logical_block_size(q), page);
}
static ssize_t queue_physical_block_size_show(struct request_queue *q, char *page)
{
return queue_var_show(queue_physical_block_size(q), page);
}
static ssize_t queue_io_min_show(struct request_queue *q, char *page)
{
return queue_var_show(queue_io_min(q), page);
}
static ssize_t queue_io_opt_show(struct request_queue *q, char *page)
{
return queue_var_show(queue_io_opt(q), page);
}
static ssize_t queue_discard_granularity_show(struct request_queue *q, char *page)
{
return queue_var_show(q->limits.discard_granularity, page);
}
static ssize_t queue_discard_max_hw_show(struct request_queue *q, char *page)
{
return sprintf(page, "%llu\n",
(unsigned long long)q->limits.max_hw_discard_sectors << 9);
}
static ssize_t queue_discard_max_show(struct request_queue *q, char *page)
{
return sprintf(page, "%llu\n",
(unsigned long long)q->limits.max_discard_sectors << 9);
}
static ssize_t queue_discard_max_store(struct request_queue *q,
const char *page, size_t count)
{
unsigned long max_discard;
ssize_t ret = queue_var_store(&max_discard, page, count);
if (ret < 0)
return ret;
if (max_discard & (q->limits.discard_granularity - 1))
return -EINVAL;
max_discard >>= 9;
if (max_discard > UINT_MAX)
return -EINVAL;
if (max_discard > q->limits.max_hw_discard_sectors)
max_discard = q->limits.max_hw_discard_sectors;
q->limits.max_discard_sectors = max_discard;
return ret;
}
static ssize_t queue_discard_zeroes_data_show(struct request_queue *q, char *page)
{
return queue_var_show(queue_discard_zeroes_data(q), page);
}
static ssize_t queue_write_same_max_show(struct request_queue *q, char *page)
{
return sprintf(page, "%llu\n",
(unsigned long long)q->limits.max_write_same_sectors << 9);
}
static ssize_t
queue_max_sectors_store(struct request_queue *q, const char *page, size_t count)
{
unsigned long max_sectors_kb,
max_hw_sectors_kb = queue_max_hw_sectors(q) >> 1,
page_kb = 1 << (PAGE_SHIFT - 10);
ssize_t ret = queue_var_store(&max_sectors_kb, page, count);
if (ret < 0)
return ret;
max_hw_sectors_kb = min_not_zero(max_hw_sectors_kb, (unsigned long)
q->limits.max_dev_sectors >> 1);
if (max_sectors_kb > max_hw_sectors_kb || max_sectors_kb < page_kb)
return -EINVAL;
spin_lock_irq(q->queue_lock);
q->limits.max_sectors = max_sectors_kb << 1;
spin_unlock_irq(q->queue_lock);
return ret;
}
static ssize_t queue_max_hw_sectors_show(struct request_queue *q, char *page)
{
int max_hw_sectors_kb = queue_max_hw_sectors(q) >> 1;
return queue_var_show(max_hw_sectors_kb, (page));
}
static ssize_t queue_nomerges_show(struct request_queue *q, char *page)
{
return queue_var_show((blk_queue_nomerges(q) << 1) |
blk_queue_noxmerges(q), page);
}
static ssize_t queue_nomerges_store(struct request_queue *q, const char *page,
size_t count)
{
unsigned long nm;
ssize_t ret = queue_var_store(&nm, page, count);
if (ret < 0)
return ret;
spin_lock_irq(q->queue_lock);
queue_flag_clear(QUEUE_FLAG_NOMERGES, q);
queue_flag_clear(QUEUE_FLAG_NOXMERGES, q);
if (nm == 2)
queue_flag_set(QUEUE_FLAG_NOMERGES, q);
else if (nm)
queue_flag_set(QUEUE_FLAG_NOXMERGES, q);
spin_unlock_irq(q->queue_lock);
return ret;
}
static ssize_t queue_rq_affinity_show(struct request_queue *q, char *page)
{
bool set = test_bit(QUEUE_FLAG_SAME_COMP, &q->queue_flags);
bool force = test_bit(QUEUE_FLAG_SAME_FORCE, &q->queue_flags);
return queue_var_show(set << force, page);
}
static ssize_t
queue_rq_affinity_store(struct request_queue *q, const char *page, size_t count)
{
ssize_t ret = -EINVAL;
#ifdef CONFIG_SMP
unsigned long val;
ret = queue_var_store(&val, page, count);
if (ret < 0)
return ret;
spin_lock_irq(q->queue_lock);
if (val == 2) {
queue_flag_set(QUEUE_FLAG_SAME_COMP, q);
queue_flag_set(QUEUE_FLAG_SAME_FORCE, q);
} else if (val == 1) {
queue_flag_set(QUEUE_FLAG_SAME_COMP, q);
queue_flag_clear(QUEUE_FLAG_SAME_FORCE, q);
} else if (val == 0) {
queue_flag_clear(QUEUE_FLAG_SAME_COMP, q);
queue_flag_clear(QUEUE_FLAG_SAME_FORCE, q);
}
spin_unlock_irq(q->queue_lock);
#endif
return ret;
}
static ssize_t queue_poll_show(struct request_queue *q, char *page)
{
return queue_var_show(test_bit(QUEUE_FLAG_POLL, &q->queue_flags), page);
}
static ssize_t queue_poll_store(struct request_queue *q, const char *page,
size_t count)
{
unsigned long poll_on;
ssize_t ret;
if (!q->mq_ops || !q->mq_ops->poll)
return -EINVAL;
ret = queue_var_store(&poll_on, page, count);
if (ret < 0)
return ret;
spin_lock_irq(q->queue_lock);
if (poll_on)
queue_flag_set(QUEUE_FLAG_POLL, q);
else
queue_flag_clear(QUEUE_FLAG_POLL, q);
spin_unlock_irq(q->queue_lock);
return ret;
}
static ssize_t
queue_attr_show(struct kobject *kobj, struct attribute *attr, char *page)
{
struct queue_sysfs_entry *entry = to_queue(attr);
struct request_queue *q =
container_of(kobj, struct request_queue, kobj);
ssize_t res;
if (!entry->show)
return -EIO;
mutex_lock(&q->sysfs_lock);
if (blk_queue_dying(q)) {
mutex_unlock(&q->sysfs_lock);
return -ENOENT;
}
res = entry->show(q, page);
mutex_unlock(&q->sysfs_lock);
return res;
}
static ssize_t
queue_attr_store(struct kobject *kobj, struct attribute *attr,
const char *page, size_t length)
{
struct queue_sysfs_entry *entry = to_queue(attr);
struct request_queue *q;
ssize_t res;
if (!entry->store)
return -EIO;
q = container_of(kobj, struct request_queue, kobj);
mutex_lock(&q->sysfs_lock);
if (blk_queue_dying(q)) {
mutex_unlock(&q->sysfs_lock);
return -ENOENT;
}
res = entry->store(q, page, length);
mutex_unlock(&q->sysfs_lock);
return res;
}
static void blk_free_queue_rcu(struct rcu_head *rcu_head)
{
struct request_queue *q = container_of(rcu_head, struct request_queue,
rcu_head);
kmem_cache_free(blk_requestq_cachep, q);
}
static void blk_release_queue(struct kobject *kobj)
{
struct request_queue *q =
container_of(kobj, struct request_queue, kobj);
bdi_exit(&q->backing_dev_info);
blkcg_exit_queue(q);
if (q->elevator) {
spin_lock_irq(q->queue_lock);
ioc_clear_queue(q);
spin_unlock_irq(q->queue_lock);
elevator_exit(q->elevator);
}
blk_exit_rl(&q->root_rl);
if (q->queue_tags)
__blk_queue_free_tags(q);
if (!q->mq_ops)
blk_free_flush_queue(q->fq);
else
blk_mq_release(q);
blk_trace_shutdown(q);
if (q->bio_split)
bioset_free(q->bio_split);
ida_simple_remove(&blk_queue_ida, q->id);
call_rcu(&q->rcu_head, blk_free_queue_rcu);
}
int blk_register_queue(struct gendisk *disk)
{
int ret;
struct device *dev = disk_to_dev(disk);
struct request_queue *q = disk->queue;
if (WARN_ON(!q))
return -ENXIO;
if (!blk_queue_init_done(q)) {
queue_flag_set_unlocked(QUEUE_FLAG_INIT_DONE, q);
percpu_ref_switch_to_percpu(&q->q_usage_counter);
blk_queue_bypass_end(q);
}
ret = blk_trace_init_sysfs(dev);
if (ret)
return ret;
ret = kobject_add(&q->kobj, kobject_get(&dev->kobj), "%s", "queue");
if (ret < 0) {
blk_trace_remove_sysfs(dev);
return ret;
}
kobject_uevent(&q->kobj, KOBJ_ADD);
if (q->mq_ops)
blk_mq_register_disk(disk);
if (!q->request_fn)
return 0;
ret = elv_register_queue(q);
if (ret) {
kobject_uevent(&q->kobj, KOBJ_REMOVE);
kobject_del(&q->kobj);
blk_trace_remove_sysfs(dev);
kobject_put(&dev->kobj);
return ret;
}
return 0;
}
void blk_unregister_queue(struct gendisk *disk)
{
struct request_queue *q = disk->queue;
if (WARN_ON(!q))
return;
if (q->mq_ops)
blk_mq_unregister_disk(disk);
if (q->request_fn)
elv_unregister_queue(q);
kobject_uevent(&q->kobj, KOBJ_REMOVE);
kobject_del(&q->kobj);
blk_trace_remove_sysfs(disk_to_dev(disk));
kobject_put(&disk_to_dev(disk)->kobj);
}
