static inline struct throtl_grp *tg_of_blkg(struct blkio_group *blkg)
{
if (blkg)
return container_of(blkg, struct throtl_grp, blkg);
return NULL;
}
static inline unsigned int total_nr_queued(struct throtl_data *td)
{
return td->nr_queued[0] + td->nr_queued[1];
}
static inline struct throtl_grp *throtl_ref_get_tg(struct throtl_grp *tg)
{
atomic_inc(&tg->ref);
return tg;
}
static void throtl_free_tg(struct rcu_head *head)
{
struct throtl_grp *tg;
tg = container_of(head, struct throtl_grp, rcu_head);
free_percpu(tg->blkg.stats_cpu);
kfree(tg);
}
static void throtl_put_tg(struct throtl_grp *tg)
{
BUG_ON(atomic_read(&tg->ref) <= 0);
if (!atomic_dec_and_test(&tg->ref))
return;
call_rcu(&tg->rcu_head, throtl_free_tg);
}
static void throtl_init_group(struct throtl_grp *tg)
{
INIT_HLIST_NODE(&tg->tg_node);
RB_CLEAR_NODE(&tg->rb_node);
bio_list_init(&tg->bio_lists[0]);
bio_list_init(&tg->bio_lists[1]);
tg->limits_changed = false;
tg->bps[0] = tg->bps[1] = -1;
tg->iops[0] = tg->iops[1] = -1;
atomic_set(&tg->ref, 1);
}
static void
throtl_add_group_to_td_list(struct throtl_data *td, struct throtl_grp *tg)
{
hlist_add_head(&tg->tg_node, &td->tg_list);
td->nr_undestroyed_grps++;
}
static void
__throtl_tg_fill_dev_details(struct throtl_data *td, struct throtl_grp *tg)
{
struct backing_dev_info *bdi = &td->queue->backing_dev_info;
unsigned int major, minor;
if (!tg || tg->blkg.dev)
return;
if (bdi->dev && dev_name(bdi->dev)) {
sscanf(dev_name(bdi->dev), "%u:%u", &major, &minor);
tg->blkg.dev = MKDEV(major, minor);
}
}
static void
throtl_tg_fill_dev_details(struct throtl_data *td, struct throtl_grp *tg)
{
if (!tg || tg->blkg.dev)
return;
spin_lock_irq(td->queue->queue_lock);
__throtl_tg_fill_dev_details(td, tg);
spin_unlock_irq(td->queue->queue_lock);
}
static void throtl_init_add_tg_lists(struct throtl_data *td,
struct throtl_grp *tg, struct blkio_cgroup *blkcg)
{
__throtl_tg_fill_dev_details(td, tg);
blkiocg_add_blkio_group(blkcg, &tg->blkg, (void *)td,
tg->blkg.dev, BLKIO_POLICY_THROTL);
tg->bps[READ] = blkcg_get_read_bps(blkcg, tg->blkg.dev);
tg->bps[WRITE] = blkcg_get_write_bps(blkcg, tg->blkg.dev);
tg->iops[READ] = blkcg_get_read_iops(blkcg, tg->blkg.dev);
tg->iops[WRITE] = blkcg_get_write_iops(blkcg, tg->blkg.dev);
throtl_add_group_to_td_list(td, tg);
}
static struct throtl_grp *throtl_alloc_tg(struct throtl_data *td)
{
struct throtl_grp *tg = NULL;
int ret;
tg = kzalloc_node(sizeof(*tg), GFP_ATOMIC, td->queue->node);
if (!tg)
return NULL;
ret = blkio_alloc_blkg_stats(&tg->blkg);
if (ret) {
kfree(tg);
return NULL;
}
throtl_init_group(tg);
return tg;
}
static struct
throtl_grp *throtl_find_tg(struct throtl_data *td, struct blkio_cgroup *blkcg)
{
struct throtl_grp *tg = NULL;
void *key = td;
if (blkcg == &blkio_root_cgroup)
tg = td->root_tg;
else
tg = tg_of_blkg(blkiocg_lookup_group(blkcg, key));
__throtl_tg_fill_dev_details(td, tg);
return tg;
}
static struct throtl_grp * throtl_get_tg(struct throtl_data *td)
{
struct throtl_grp *tg = NULL, *__tg = NULL;
struct blkio_cgroup *blkcg;
struct request_queue *q = td->queue;
if (unlikely(test_bit(QUEUE_FLAG_DEAD, &q->queue_flags)))
return NULL;
rcu_read_lock();
blkcg = task_blkio_cgroup(current);
tg = throtl_find_tg(td, blkcg);
if (tg) {
rcu_read_unlock();
return tg;
}
rcu_read_unlock();
spin_unlock_irq(q->queue_lock);
tg = throtl_alloc_tg(td);
spin_lock_irq(q->queue_lock);
if (unlikely(test_bit(QUEUE_FLAG_DEAD, &q->queue_flags))) {
kfree(tg);
return NULL;
}
rcu_read_lock();
blkcg = task_blkio_cgroup(current);
__tg = throtl_find_tg(td, blkcg);
if (__tg) {
kfree(tg);
rcu_read_unlock();
return __tg;
}
if (!tg) {
tg = td->root_tg;
return tg;
}
throtl_init_add_tg_lists(td, tg, blkcg);
rcu_read_unlock();
return tg;
}
static struct throtl_grp *throtl_rb_first(struct throtl_rb_root *root)
{
if (!root->count)
return NULL;
if (!root->left)
root->left = rb_first(&root->rb);
if (root->left)
return rb_entry_tg(root->left);
return NULL;
}
static void rb_erase_init(struct rb_node *n, struct rb_root *root)
{
rb_erase(n, root);
RB_CLEAR_NODE(n);
}
static void throtl_rb_erase(struct rb_node *n, struct throtl_rb_root *root)
{
if (root->left == n)
root->left = NULL;
rb_erase_init(n, &root->rb);
--root->count;
}
static void update_min_dispatch_time(struct throtl_rb_root *st)
{
struct throtl_grp *tg;
tg = throtl_rb_first(st);
if (!tg)
return;
st->min_disptime = tg->disptime;
}
static void
tg_service_tree_add(struct throtl_rb_root *st, struct throtl_grp *tg)
{
struct rb_node **node = &st->rb.rb_node;
struct rb_node *parent = NULL;
struct throtl_grp *__tg;
unsigned long key = tg->disptime;
int left = 1;
while (*node != NULL) {
parent = *node;
__tg = rb_entry_tg(parent);
if (time_before(key, __tg->disptime))
node = &parent->rb_left;
else {
node = &parent->rb_right;
left = 0;
}
}
if (left)
st->left = &tg->rb_node;
rb_link_node(&tg->rb_node, parent, node);
rb_insert_color(&tg->rb_node, &st->rb);
}
static void __throtl_enqueue_tg(struct throtl_data *td, struct throtl_grp *tg)
{
struct throtl_rb_root *st = &td->tg_service_tree;
tg_service_tree_add(st, tg);
throtl_mark_tg_on_rr(tg);
st->count++;
}
static void throtl_enqueue_tg(struct throtl_data *td, struct throtl_grp *tg)
{
if (!throtl_tg_on_rr(tg))
__throtl_enqueue_tg(td, tg);
}
static void __throtl_dequeue_tg(struct throtl_data *td, struct throtl_grp *tg)
{
throtl_rb_erase(&tg->rb_node, &td->tg_service_tree);
throtl_clear_tg_on_rr(tg);
}
static void throtl_dequeue_tg(struct throtl_data *td, struct throtl_grp *tg)
{
if (throtl_tg_on_rr(tg))
__throtl_dequeue_tg(td, tg);
}
static void throtl_schedule_next_dispatch(struct throtl_data *td)
{
struct throtl_rb_root *st = &td->tg_service_tree;
if (!total_nr_queued(td))
return;
BUG_ON(!st->count);
update_min_dispatch_time(st);
if (time_before_eq(st->min_disptime, jiffies))
throtl_schedule_delayed_work(td, 0);
else
throtl_schedule_delayed_work(td, (st->min_disptime - jiffies));
}
static inline void
throtl_start_new_slice(struct throtl_data *td, struct throtl_grp *tg, bool rw)
{
tg->bytes_disp[rw] = 0;
tg->io_disp[rw] = 0;
tg->slice_start[rw] = jiffies;
tg->slice_end[rw] = jiffies + throtl_slice;
throtl_log_tg(td, tg, "[%c] new slice start=%lu end=%lu jiffies=%lu",
rw == READ ? 'R' : 'W', tg->slice_start[rw],
tg->slice_end[rw], jiffies);
}
static inline void throtl_set_slice_end(struct throtl_data *td,
struct throtl_grp *tg, bool rw, unsigned long jiffy_end)
{
tg->slice_end[rw] = roundup(jiffy_end, throtl_slice);
}
static inline void throtl_extend_slice(struct throtl_data *td,
struct throtl_grp *tg, bool rw, unsigned long jiffy_end)
{
tg->slice_end[rw] = roundup(jiffy_end, throtl_slice);
throtl_log_tg(td, tg, "[%c] extend slice start=%lu end=%lu jiffies=%lu",
rw == READ ? 'R' : 'W', tg->slice_start[rw],
tg->slice_end[rw], jiffies);
}
static bool
throtl_slice_used(struct throtl_data *td, struct throtl_grp *tg, bool rw)
{
if (time_in_range(jiffies, tg->slice_start[rw], tg->slice_end[rw]))
return 0;
return 1;
}
static inline void
throtl_trim_slice(struct throtl_data *td, struct throtl_grp *tg, bool rw)
{
unsigned long nr_slices, time_elapsed, io_trim;
u64 bytes_trim, tmp;
BUG_ON(time_before(tg->slice_end[rw], tg->slice_start[rw]));
if (throtl_slice_used(td, tg, rw))
return;
throtl_set_slice_end(td, tg, rw, jiffies + throtl_slice);
time_elapsed = jiffies - tg->slice_start[rw];
nr_slices = time_elapsed / throtl_slice;
if (!nr_slices)
return;
tmp = tg->bps[rw] * throtl_slice * nr_slices;
do_div(tmp, HZ);
bytes_trim = tmp;
io_trim = (tg->iops[rw] * throtl_slice * nr_slices)/HZ;
if (!bytes_trim && !io_trim)
return;
if (tg->bytes_disp[rw] >= bytes_trim)
tg->bytes_disp[rw] -= bytes_trim;
else
tg->bytes_disp[rw] = 0;
if (tg->io_disp[rw] >= io_trim)
tg->io_disp[rw] -= io_trim;
else
tg->io_disp[rw] = 0;
tg->slice_start[rw] += nr_slices * throtl_slice;
throtl_log_tg(td, tg, "[%c] trim slice nr=%lu bytes=%llu io=%lu"
" start=%lu end=%lu jiffies=%lu",
rw == READ ? 'R' : 'W', nr_slices, bytes_trim, io_trim,
tg->slice_start[rw], tg->slice_end[rw], jiffies);
}
static bool tg_with_in_iops_limit(struct throtl_data *td, struct throtl_grp *tg,
struct bio *bio, unsigned long *wait)
{
bool rw = bio_data_dir(bio);
unsigned int io_allowed;
unsigned long jiffy_elapsed, jiffy_wait, jiffy_elapsed_rnd;
u64 tmp;
jiffy_elapsed = jiffy_elapsed_rnd = jiffies - tg->slice_start[rw];
if (!jiffy_elapsed)
jiffy_elapsed_rnd = throtl_slice;
jiffy_elapsed_rnd = roundup(jiffy_elapsed_rnd, throtl_slice);
tmp = (u64)tg->iops[rw] * jiffy_elapsed_rnd;
do_div(tmp, HZ);
if (tmp > UINT_MAX)
io_allowed = UINT_MAX;
else
io_allowed = tmp;
if (tg->io_disp[rw] + 1 <= io_allowed) {
if (wait)
*wait = 0;
return 1;
}
jiffy_wait = ((tg->io_disp[rw] + 1) * HZ)/tg->iops[rw] + 1;
if (jiffy_wait > jiffy_elapsed)
jiffy_wait = jiffy_wait - jiffy_elapsed;
else
jiffy_wait = 1;
if (wait)
*wait = jiffy_wait;
return 0;
}
static bool tg_with_in_bps_limit(struct throtl_data *td, struct throtl_grp *tg,
struct bio *bio, unsigned long *wait)
{
bool rw = bio_data_dir(bio);
u64 bytes_allowed, extra_bytes, tmp;
unsigned long jiffy_elapsed, jiffy_wait, jiffy_elapsed_rnd;
jiffy_elapsed = jiffy_elapsed_rnd = jiffies - tg->slice_start[rw];
if (!jiffy_elapsed)
jiffy_elapsed_rnd = throtl_slice;
jiffy_elapsed_rnd = roundup(jiffy_elapsed_rnd, throtl_slice);
tmp = tg->bps[rw] * jiffy_elapsed_rnd;
do_div(tmp, HZ);
bytes_allowed = tmp;
if (tg->bytes_disp[rw] + bio->bi_size <= bytes_allowed) {
if (wait)
*wait = 0;
return 1;
}
extra_bytes = tg->bytes_disp[rw] + bio->bi_size - bytes_allowed;
jiffy_wait = div64_u64(extra_bytes * HZ, tg->bps[rw]);
if (!jiffy_wait)
jiffy_wait = 1;
jiffy_wait = jiffy_wait + (jiffy_elapsed_rnd - jiffy_elapsed);
if (wait)
*wait = jiffy_wait;
return 0;
}
static bool tg_no_rule_group(struct throtl_grp *tg, bool rw) {
if (tg->bps[rw] == -1 && tg->iops[rw] == -1)
return 1;
return 0;
}
static bool tg_may_dispatch(struct throtl_data *td, struct throtl_grp *tg,
struct bio *bio, unsigned long *wait)
{
bool rw = bio_data_dir(bio);
unsigned long bps_wait = 0, iops_wait = 0, max_wait = 0;
BUG_ON(tg->nr_queued[rw] && bio != bio_list_peek(&tg->bio_lists[rw]));
if (tg->bps[rw] == -1 && tg->iops[rw] == -1) {
if (wait)
*wait = 0;
return 1;
}
if (throtl_slice_used(td, tg, rw))
throtl_start_new_slice(td, tg, rw);
else {
if (time_before(tg->slice_end[rw], jiffies + throtl_slice))
throtl_extend_slice(td, tg, rw, jiffies + throtl_slice);
}
if (tg_with_in_bps_limit(td, tg, bio, &bps_wait)
&& tg_with_in_iops_limit(td, tg, bio, &iops_wait)) {
if (wait)
*wait = 0;
return 1;
}
max_wait = max(bps_wait, iops_wait);
if (wait)
*wait = max_wait;
if (time_before(tg->slice_end[rw], jiffies + max_wait))
throtl_extend_slice(td, tg, rw, jiffies + max_wait);
return 0;
}
static void throtl_charge_bio(struct throtl_grp *tg, struct bio *bio)
{
bool rw = bio_data_dir(bio);
bool sync = rw_is_sync(bio->bi_rw);
tg->bytes_disp[rw] += bio->bi_size;
tg->io_disp[rw]++;
blkiocg_update_dispatch_stats(&tg->blkg, bio->bi_size, rw, sync);
}
static void throtl_add_bio_tg(struct throtl_data *td, struct throtl_grp *tg,
struct bio *bio)
{
bool rw = bio_data_dir(bio);
bio_list_add(&tg->bio_lists[rw], bio);
throtl_ref_get_tg(tg);
tg->nr_queued[rw]++;
td->nr_queued[rw]++;
throtl_enqueue_tg(td, tg);
}
static void tg_update_disptime(struct throtl_data *td, struct throtl_grp *tg)
{
unsigned long read_wait = -1, write_wait = -1, min_wait = -1, disptime;
struct bio *bio;
if ((bio = bio_list_peek(&tg->bio_lists[READ])))
tg_may_dispatch(td, tg, bio, &read_wait);
if ((bio = bio_list_peek(&tg->bio_lists[WRITE])))
tg_may_dispatch(td, tg, bio, &write_wait);
min_wait = min(read_wait, write_wait);
disptime = jiffies + min_wait;
throtl_dequeue_tg(td, tg);
tg->disptime = disptime;
throtl_enqueue_tg(td, tg);
}
static void tg_dispatch_one_bio(struct throtl_data *td, struct throtl_grp *tg,
bool rw, struct bio_list *bl)
{
struct bio *bio;
bio = bio_list_pop(&tg->bio_lists[rw]);
tg->nr_queued[rw]--;
throtl_put_tg(tg);
BUG_ON(td->nr_queued[rw] <= 0);
td->nr_queued[rw]--;
throtl_charge_bio(tg, bio);
bio_list_add(bl, bio);
bio->bi_rw |= REQ_THROTTLED;
throtl_trim_slice(td, tg, rw);
}
static int throtl_dispatch_tg(struct throtl_data *td, struct throtl_grp *tg,
struct bio_list *bl)
{
unsigned int nr_reads = 0, nr_writes = 0;
unsigned int max_nr_reads = throtl_grp_quantum*3/4;
unsigned int max_nr_writes = throtl_grp_quantum - max_nr_reads;
struct bio *bio;
while ((bio = bio_list_peek(&tg->bio_lists[READ]))
&& tg_may_dispatch(td, tg, bio, NULL)) {
tg_dispatch_one_bio(td, tg, bio_data_dir(bio), bl);
nr_reads++;
if (nr_reads >= max_nr_reads)
break;
}
while ((bio = bio_list_peek(&tg->bio_lists[WRITE]))
&& tg_may_dispatch(td, tg, bio, NULL)) {
tg_dispatch_one_bio(td, tg, bio_data_dir(bio), bl);
nr_writes++;
if (nr_writes >= max_nr_writes)
break;
}
return nr_reads + nr_writes;
}
static int throtl_select_dispatch(struct throtl_data *td, struct bio_list *bl)
{
unsigned int nr_disp = 0;
struct throtl_grp *tg;
struct throtl_rb_root *st = &td->tg_service_tree;
while (1) {
tg = throtl_rb_first(st);
if (!tg)
break;
if (time_before(jiffies, tg->disptime))
break;
throtl_dequeue_tg(td, tg);
nr_disp += throtl_dispatch_tg(td, tg, bl);
if (tg->nr_queued[0] || tg->nr_queued[1]) {
tg_update_disptime(td, tg);
throtl_enqueue_tg(td, tg);
}
if (nr_disp >= throtl_quantum)
break;
}
return nr_disp;
}
static void throtl_process_limit_change(struct throtl_data *td)
{
struct throtl_grp *tg;
struct hlist_node *pos, *n;
if (!td->limits_changed)
return;
xchg(&td->limits_changed, false);
throtl_log(td, "limits changed");
hlist_for_each_entry_safe(tg, pos, n, &td->tg_list, tg_node) {
if (!tg->limits_changed)
continue;
if (!xchg(&tg->limits_changed, false))
continue;
throtl_log_tg(td, tg, "limit change rbps=%llu wbps=%llu"
" riops=%u wiops=%u", tg->bps[READ], tg->bps[WRITE],
tg->iops[READ], tg->iops[WRITE]);
throtl_start_new_slice(td, tg, 0);
throtl_start_new_slice(td, tg, 1);
if (throtl_tg_on_rr(tg))
tg_update_disptime(td, tg);
}
}
static int throtl_dispatch(struct request_queue *q)
{
struct throtl_data *td = q->td;
unsigned int nr_disp = 0;
struct bio_list bio_list_on_stack;
struct bio *bio;
struct blk_plug plug;
spin_lock_irq(q->queue_lock);
throtl_process_limit_change(td);
if (!total_nr_queued(td))
goto out;
bio_list_init(&bio_list_on_stack);
throtl_log(td, "dispatch nr_queued=%u read=%u write=%u",
total_nr_queued(td), td->nr_queued[READ],
td->nr_queued[WRITE]);
nr_disp = throtl_select_dispatch(td, &bio_list_on_stack);
if (nr_disp)
throtl_log(td, "bios disp=%u", nr_disp);
throtl_schedule_next_dispatch(td);
out:
spin_unlock_irq(q->queue_lock);
if (nr_disp) {
blk_start_plug(&plug);
while((bio = bio_list_pop(&bio_list_on_stack)))
generic_make_request(bio);
blk_finish_plug(&plug);
}
return nr_disp;
}
void blk_throtl_work(struct work_struct *work)
{
struct throtl_data *td = container_of(work, struct throtl_data,
throtl_work.work);
struct request_queue *q = td->queue;
throtl_dispatch(q);
}
static void
throtl_schedule_delayed_work(struct throtl_data *td, unsigned long delay)
{
struct delayed_work *dwork = &td->throtl_work;
if (total_nr_queued(td) || td->limits_changed) {
__cancel_delayed_work(dwork);
queue_delayed_work(kthrotld_workqueue, dwork, delay);
throtl_log(td, "schedule work. delay=%lu jiffies=%lu",
delay, jiffies);
}
}
static void
throtl_destroy_tg(struct throtl_data *td, struct throtl_grp *tg)
{
BUG_ON(hlist_unhashed(&tg->tg_node));
hlist_del_init(&tg->tg_node);
throtl_put_tg(tg);
td->nr_undestroyed_grps--;
}
static void throtl_release_tgs(struct throtl_data *td)
{
struct hlist_node *pos, *n;
struct throtl_grp *tg;
hlist_for_each_entry_safe(tg, pos, n, &td->tg_list, tg_node) {
if (!blkiocg_del_blkio_group(&tg->blkg))
throtl_destroy_tg(td, tg);
}
}
void throtl_unlink_blkio_group(void *key, struct blkio_group *blkg)
{
unsigned long flags;
struct throtl_data *td = key;
spin_lock_irqsave(td->queue->queue_lock, flags);
throtl_destroy_tg(td, tg_of_blkg(blkg));
spin_unlock_irqrestore(td->queue->queue_lock, flags);
}
static void throtl_update_blkio_group_common(struct throtl_data *td,
struct throtl_grp *tg)
{
xchg(&tg->limits_changed, true);
xchg(&td->limits_changed, true);
throtl_schedule_delayed_work(td, 0);
}
static void throtl_update_blkio_group_read_bps(void *key,
struct blkio_group *blkg, u64 read_bps)
{
struct throtl_data *td = key;
struct throtl_grp *tg = tg_of_blkg(blkg);
tg->bps[READ] = read_bps;
throtl_update_blkio_group_common(td, tg);
}
static void throtl_update_blkio_group_write_bps(void *key,
struct blkio_group *blkg, u64 write_bps)
{
struct throtl_data *td = key;
struct throtl_grp *tg = tg_of_blkg(blkg);
tg->bps[WRITE] = write_bps;
throtl_update_blkio_group_common(td, tg);
}
static void throtl_update_blkio_group_read_iops(void *key,
struct blkio_group *blkg, unsigned int read_iops)
{
struct throtl_data *td = key;
struct throtl_grp *tg = tg_of_blkg(blkg);
tg->iops[READ] = read_iops;
throtl_update_blkio_group_common(td, tg);
}
static void throtl_update_blkio_group_write_iops(void *key,
struct blkio_group *blkg, unsigned int write_iops)
{
struct throtl_data *td = key;
struct throtl_grp *tg = tg_of_blkg(blkg);
tg->iops[WRITE] = write_iops;
throtl_update_blkio_group_common(td, tg);
}
static void throtl_shutdown_wq(struct request_queue *q)
{
struct throtl_data *td = q->td;
cancel_delayed_work_sync(&td->throtl_work);
}
bool blk_throtl_bio(struct request_queue *q, struct bio *bio)
{
struct throtl_data *td = q->td;
struct throtl_grp *tg;
bool rw = bio_data_dir(bio), update_disptime = true;
struct blkio_cgroup *blkcg;
bool throttled = false;
if (bio->bi_rw & REQ_THROTTLED) {
bio->bi_rw &= ~REQ_THROTTLED;
goto out;
}
rcu_read_lock();
blkcg = task_blkio_cgroup(current);
tg = throtl_find_tg(td, blkcg);
if (tg) {
throtl_tg_fill_dev_details(td, tg);
if (tg_no_rule_group(tg, rw)) {
blkiocg_update_dispatch_stats(&tg->blkg, bio->bi_size,
rw, rw_is_sync(bio->bi_rw));
rcu_read_unlock();
goto out;
}
}
rcu_read_unlock();
spin_lock_irq(q->queue_lock);
tg = throtl_get_tg(td);
if (unlikely(!tg))
goto out_unlock;
if (tg->nr_queued[rw]) {
update_disptime = false;
goto queue_bio;
}
if (tg_may_dispatch(td, tg, bio, NULL)) {
throtl_charge_bio(tg, bio);
throtl_trim_slice(td, tg, rw);
goto out_unlock;
}
queue_bio:
throtl_log_tg(td, tg, "[%c] bio. bdisp=%llu sz=%u bps=%llu"
" iodisp=%u iops=%u queued=%d/%d",
rw == READ ? 'R' : 'W',
tg->bytes_disp[rw], bio->bi_size, tg->bps[rw],
tg->io_disp[rw], tg->iops[rw],
tg->nr_queued[READ], tg->nr_queued[WRITE]);
throtl_add_bio_tg(q->td, tg, bio);
throttled = true;
if (update_disptime) {
tg_update_disptime(td, tg);
throtl_schedule_next_dispatch(td);
}
out_unlock:
spin_unlock_irq(q->queue_lock);
out:
return throttled;
}
void blk_throtl_drain(struct request_queue *q)
__releases(q->queue_lock) __acquires(q->queue_lock)
{
struct throtl_data *td = q->td;
struct throtl_rb_root *st = &td->tg_service_tree;
struct throtl_grp *tg;
struct bio_list bl;
struct bio *bio;
WARN_ON_ONCE(!queue_is_locked(q));
bio_list_init(&bl);
while ((tg = throtl_rb_first(st))) {
throtl_dequeue_tg(td, tg);
while ((bio = bio_list_peek(&tg->bio_lists[READ])))
tg_dispatch_one_bio(td, tg, bio_data_dir(bio), &bl);
while ((bio = bio_list_peek(&tg->bio_lists[WRITE])))
tg_dispatch_one_bio(td, tg, bio_data_dir(bio), &bl);
}
spin_unlock_irq(q->queue_lock);
while ((bio = bio_list_pop(&bl)))
generic_make_request(bio);
spin_lock_irq(q->queue_lock);
}
int blk_throtl_init(struct request_queue *q)
{
struct throtl_data *td;
struct throtl_grp *tg;
td = kzalloc_node(sizeof(*td), GFP_KERNEL, q->node);
if (!td)
return -ENOMEM;
INIT_HLIST_HEAD(&td->tg_list);
td->tg_service_tree = THROTL_RB_ROOT;
td->limits_changed = false;
INIT_DELAYED_WORK(&td->throtl_work, blk_throtl_work);
td->queue = q;
tg = throtl_alloc_tg(td);
if (!tg) {
kfree(td);
return -ENOMEM;
}
td->root_tg = tg;
rcu_read_lock();
throtl_init_add_tg_lists(td, tg, &blkio_root_cgroup);
rcu_read_unlock();
q->td = td;
return 0;
}
void blk_throtl_exit(struct request_queue *q)
{
struct throtl_data *td = q->td;
bool wait = false;
BUG_ON(!td);
throtl_shutdown_wq(q);
spin_lock_irq(q->queue_lock);
throtl_release_tgs(td);
if (td->nr_undestroyed_grps > 0)
wait = true;
spin_unlock_irq(q->queue_lock);
if (wait)
synchronize_rcu();
throtl_shutdown_wq(q);
}
void blk_throtl_release(struct request_queue *q)
{
kfree(q->td);
}
static int __init throtl_init(void)
{
kthrotld_workqueue = alloc_workqueue("kthrotld", WQ_MEM_RECLAIM, 0);
if (!kthrotld_workqueue)
panic("Failed to create kthrotld\n");
blkio_policy_register(&blkio_policy_throtl);
return 0;
}
