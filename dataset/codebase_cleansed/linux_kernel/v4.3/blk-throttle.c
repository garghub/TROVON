static inline struct throtl_grp *pd_to_tg(struct blkg_policy_data *pd)
{
return pd ? container_of(pd, struct throtl_grp, pd) : NULL;
}
static inline struct throtl_grp *blkg_to_tg(struct blkcg_gq *blkg)
{
return pd_to_tg(blkg_to_pd(blkg, &blkcg_policy_throtl));
}
static inline struct blkcg_gq *tg_to_blkg(struct throtl_grp *tg)
{
return pd_to_blkg(&tg->pd);
}
static struct throtl_grp *sq_to_tg(struct throtl_service_queue *sq)
{
if (sq && sq->parent_sq)
return container_of(sq, struct throtl_grp, service_queue);
else
return NULL;
}
static struct throtl_data *sq_to_td(struct throtl_service_queue *sq)
{
struct throtl_grp *tg = sq_to_tg(sq);
if (tg)
return tg->td;
else
return container_of(sq, struct throtl_data, service_queue);
}
static void throtl_qnode_init(struct throtl_qnode *qn, struct throtl_grp *tg)
{
INIT_LIST_HEAD(&qn->node);
bio_list_init(&qn->bios);
qn->tg = tg;
}
static void throtl_qnode_add_bio(struct bio *bio, struct throtl_qnode *qn,
struct list_head *queued)
{
bio_list_add(&qn->bios, bio);
if (list_empty(&qn->node)) {
list_add_tail(&qn->node, queued);
blkg_get(tg_to_blkg(qn->tg));
}
}
static struct bio *throtl_peek_queued(struct list_head *queued)
{
struct throtl_qnode *qn = list_first_entry(queued, struct throtl_qnode, node);
struct bio *bio;
if (list_empty(queued))
return NULL;
bio = bio_list_peek(&qn->bios);
WARN_ON_ONCE(!bio);
return bio;
}
static struct bio *throtl_pop_queued(struct list_head *queued,
struct throtl_grp **tg_to_put)
{
struct throtl_qnode *qn = list_first_entry(queued, struct throtl_qnode, node);
struct bio *bio;
if (list_empty(queued))
return NULL;
bio = bio_list_pop(&qn->bios);
WARN_ON_ONCE(!bio);
if (bio_list_empty(&qn->bios)) {
list_del_init(&qn->node);
if (tg_to_put)
*tg_to_put = qn->tg;
else
blkg_put(tg_to_blkg(qn->tg));
} else {
list_move_tail(&qn->node, queued);
}
return bio;
}
static void throtl_service_queue_init(struct throtl_service_queue *sq)
{
INIT_LIST_HEAD(&sq->queued[0]);
INIT_LIST_HEAD(&sq->queued[1]);
sq->pending_tree = RB_ROOT;
setup_timer(&sq->pending_timer, throtl_pending_timer_fn,
(unsigned long)sq);
}
static struct blkg_policy_data *throtl_pd_alloc(gfp_t gfp, int node)
{
struct throtl_grp *tg;
int rw;
tg = kzalloc_node(sizeof(*tg), gfp, node);
if (!tg)
return NULL;
throtl_service_queue_init(&tg->service_queue);
for (rw = READ; rw <= WRITE; rw++) {
throtl_qnode_init(&tg->qnode_on_self[rw], tg);
throtl_qnode_init(&tg->qnode_on_parent[rw], tg);
}
RB_CLEAR_NODE(&tg->rb_node);
tg->bps[READ] = -1;
tg->bps[WRITE] = -1;
tg->iops[READ] = -1;
tg->iops[WRITE] = -1;
return &tg->pd;
}
static void throtl_pd_init(struct blkg_policy_data *pd)
{
struct throtl_grp *tg = pd_to_tg(pd);
struct blkcg_gq *blkg = tg_to_blkg(tg);
struct throtl_data *td = blkg->q->td;
struct throtl_service_queue *sq = &tg->service_queue;
sq->parent_sq = &td->service_queue;
if (cgroup_on_dfl(blkg->blkcg->css.cgroup) && blkg->parent)
sq->parent_sq = &blkg_to_tg(blkg->parent)->service_queue;
tg->td = td;
}
static void tg_update_has_rules(struct throtl_grp *tg)
{
struct throtl_grp *parent_tg = sq_to_tg(tg->service_queue.parent_sq);
int rw;
for (rw = READ; rw <= WRITE; rw++)
tg->has_rules[rw] = (parent_tg && parent_tg->has_rules[rw]) ||
(tg->bps[rw] != -1 || tg->iops[rw] != -1);
}
static void throtl_pd_online(struct blkg_policy_data *pd)
{
tg_update_has_rules(pd_to_tg(pd));
}
static void throtl_pd_free(struct blkg_policy_data *pd)
{
struct throtl_grp *tg = pd_to_tg(pd);
del_timer_sync(&tg->service_queue.pending_timer);
kfree(tg);
}
static struct throtl_grp *
throtl_rb_first(struct throtl_service_queue *parent_sq)
{
if (!parent_sq->nr_pending)
return NULL;
if (!parent_sq->first_pending)
parent_sq->first_pending = rb_first(&parent_sq->pending_tree);
if (parent_sq->first_pending)
return rb_entry_tg(parent_sq->first_pending);
return NULL;
}
static void rb_erase_init(struct rb_node *n, struct rb_root *root)
{
rb_erase(n, root);
RB_CLEAR_NODE(n);
}
static void throtl_rb_erase(struct rb_node *n,
struct throtl_service_queue *parent_sq)
{
if (parent_sq->first_pending == n)
parent_sq->first_pending = NULL;
rb_erase_init(n, &parent_sq->pending_tree);
--parent_sq->nr_pending;
}
static void update_min_dispatch_time(struct throtl_service_queue *parent_sq)
{
struct throtl_grp *tg;
tg = throtl_rb_first(parent_sq);
if (!tg)
return;
parent_sq->first_pending_disptime = tg->disptime;
}
static void tg_service_queue_add(struct throtl_grp *tg)
{
struct throtl_service_queue *parent_sq = tg->service_queue.parent_sq;
struct rb_node **node = &parent_sq->pending_tree.rb_node;
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
parent_sq->first_pending = &tg->rb_node;
rb_link_node(&tg->rb_node, parent, node);
rb_insert_color(&tg->rb_node, &parent_sq->pending_tree);
}
static void __throtl_enqueue_tg(struct throtl_grp *tg)
{
tg_service_queue_add(tg);
tg->flags |= THROTL_TG_PENDING;
tg->service_queue.parent_sq->nr_pending++;
}
static void throtl_enqueue_tg(struct throtl_grp *tg)
{
if (!(tg->flags & THROTL_TG_PENDING))
__throtl_enqueue_tg(tg);
}
static void __throtl_dequeue_tg(struct throtl_grp *tg)
{
throtl_rb_erase(&tg->rb_node, tg->service_queue.parent_sq);
tg->flags &= ~THROTL_TG_PENDING;
}
static void throtl_dequeue_tg(struct throtl_grp *tg)
{
if (tg->flags & THROTL_TG_PENDING)
__throtl_dequeue_tg(tg);
}
static void throtl_schedule_pending_timer(struct throtl_service_queue *sq,
unsigned long expires)
{
mod_timer(&sq->pending_timer, expires);
throtl_log(sq, "schedule timer. delay=%lu jiffies=%lu",
expires - jiffies, jiffies);
}
static bool throtl_schedule_next_dispatch(struct throtl_service_queue *sq,
bool force)
{
if (!sq->nr_pending)
return true;
update_min_dispatch_time(sq);
if (force || time_after(sq->first_pending_disptime, jiffies)) {
throtl_schedule_pending_timer(sq, sq->first_pending_disptime);
return true;
}
return false;
}
static inline void throtl_start_new_slice_with_credit(struct throtl_grp *tg,
bool rw, unsigned long start)
{
tg->bytes_disp[rw] = 0;
tg->io_disp[rw] = 0;
if (time_after_eq(start, tg->slice_start[rw]))
tg->slice_start[rw] = start;
tg->slice_end[rw] = jiffies + throtl_slice;
throtl_log(&tg->service_queue,
"[%c] new slice with credit start=%lu end=%lu jiffies=%lu",
rw == READ ? 'R' : 'W', tg->slice_start[rw],
tg->slice_end[rw], jiffies);
}
static inline void throtl_start_new_slice(struct throtl_grp *tg, bool rw)
{
tg->bytes_disp[rw] = 0;
tg->io_disp[rw] = 0;
tg->slice_start[rw] = jiffies;
tg->slice_end[rw] = jiffies + throtl_slice;
throtl_log(&tg->service_queue,
"[%c] new slice start=%lu end=%lu jiffies=%lu",
rw == READ ? 'R' : 'W', tg->slice_start[rw],
tg->slice_end[rw], jiffies);
}
static inline void throtl_set_slice_end(struct throtl_grp *tg, bool rw,
unsigned long jiffy_end)
{
tg->slice_end[rw] = roundup(jiffy_end, throtl_slice);
}
static inline void throtl_extend_slice(struct throtl_grp *tg, bool rw,
unsigned long jiffy_end)
{
tg->slice_end[rw] = roundup(jiffy_end, throtl_slice);
throtl_log(&tg->service_queue,
"[%c] extend slice start=%lu end=%lu jiffies=%lu",
rw == READ ? 'R' : 'W', tg->slice_start[rw],
tg->slice_end[rw], jiffies);
}
static bool throtl_slice_used(struct throtl_grp *tg, bool rw)
{
if (time_in_range(jiffies, tg->slice_start[rw], tg->slice_end[rw]))
return false;
return 1;
}
static inline void throtl_trim_slice(struct throtl_grp *tg, bool rw)
{
unsigned long nr_slices, time_elapsed, io_trim;
u64 bytes_trim, tmp;
BUG_ON(time_before(tg->slice_end[rw], tg->slice_start[rw]));
if (throtl_slice_used(tg, rw))
return;
throtl_set_slice_end(tg, rw, jiffies + throtl_slice);
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
throtl_log(&tg->service_queue,
"[%c] trim slice nr=%lu bytes=%llu io=%lu start=%lu end=%lu jiffies=%lu",
rw == READ ? 'R' : 'W', nr_slices, bytes_trim, io_trim,
tg->slice_start[rw], tg->slice_end[rw], jiffies);
}
static bool tg_with_in_iops_limit(struct throtl_grp *tg, struct bio *bio,
unsigned long *wait)
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
return true;
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
static bool tg_with_in_bps_limit(struct throtl_grp *tg, struct bio *bio,
unsigned long *wait)
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
if (tg->bytes_disp[rw] + bio->bi_iter.bi_size <= bytes_allowed) {
if (wait)
*wait = 0;
return true;
}
extra_bytes = tg->bytes_disp[rw] + bio->bi_iter.bi_size - bytes_allowed;
jiffy_wait = div64_u64(extra_bytes * HZ, tg->bps[rw]);
if (!jiffy_wait)
jiffy_wait = 1;
jiffy_wait = jiffy_wait + (jiffy_elapsed_rnd - jiffy_elapsed);
if (wait)
*wait = jiffy_wait;
return 0;
}
static bool tg_may_dispatch(struct throtl_grp *tg, struct bio *bio,
unsigned long *wait)
{
bool rw = bio_data_dir(bio);
unsigned long bps_wait = 0, iops_wait = 0, max_wait = 0;
BUG_ON(tg->service_queue.nr_queued[rw] &&
bio != throtl_peek_queued(&tg->service_queue.queued[rw]));
if (tg->bps[rw] == -1 && tg->iops[rw] == -1) {
if (wait)
*wait = 0;
return true;
}
if (throtl_slice_used(tg, rw))
throtl_start_new_slice(tg, rw);
else {
if (time_before(tg->slice_end[rw], jiffies + throtl_slice))
throtl_extend_slice(tg, rw, jiffies + throtl_slice);
}
if (tg_with_in_bps_limit(tg, bio, &bps_wait) &&
tg_with_in_iops_limit(tg, bio, &iops_wait)) {
if (wait)
*wait = 0;
return 1;
}
max_wait = max(bps_wait, iops_wait);
if (wait)
*wait = max_wait;
if (time_before(tg->slice_end[rw], jiffies + max_wait))
throtl_extend_slice(tg, rw, jiffies + max_wait);
return 0;
}
static void throtl_charge_bio(struct throtl_grp *tg, struct bio *bio)
{
bool rw = bio_data_dir(bio);
tg->bytes_disp[rw] += bio->bi_iter.bi_size;
tg->io_disp[rw]++;
if (!(bio->bi_rw & REQ_THROTTLED))
bio->bi_rw |= REQ_THROTTLED;
}
static void throtl_add_bio_tg(struct bio *bio, struct throtl_qnode *qn,
struct throtl_grp *tg)
{
struct throtl_service_queue *sq = &tg->service_queue;
bool rw = bio_data_dir(bio);
if (!qn)
qn = &tg->qnode_on_self[rw];
if (!sq->nr_queued[rw])
tg->flags |= THROTL_TG_WAS_EMPTY;
throtl_qnode_add_bio(bio, qn, &sq->queued[rw]);
sq->nr_queued[rw]++;
throtl_enqueue_tg(tg);
}
static void tg_update_disptime(struct throtl_grp *tg)
{
struct throtl_service_queue *sq = &tg->service_queue;
unsigned long read_wait = -1, write_wait = -1, min_wait = -1, disptime;
struct bio *bio;
if ((bio = throtl_peek_queued(&sq->queued[READ])))
tg_may_dispatch(tg, bio, &read_wait);
if ((bio = throtl_peek_queued(&sq->queued[WRITE])))
tg_may_dispatch(tg, bio, &write_wait);
min_wait = min(read_wait, write_wait);
disptime = jiffies + min_wait;
throtl_dequeue_tg(tg);
tg->disptime = disptime;
throtl_enqueue_tg(tg);
tg->flags &= ~THROTL_TG_WAS_EMPTY;
}
static void start_parent_slice_with_credit(struct throtl_grp *child_tg,
struct throtl_grp *parent_tg, bool rw)
{
if (throtl_slice_used(parent_tg, rw)) {
throtl_start_new_slice_with_credit(parent_tg, rw,
child_tg->slice_start[rw]);
}
}
static void tg_dispatch_one_bio(struct throtl_grp *tg, bool rw)
{
struct throtl_service_queue *sq = &tg->service_queue;
struct throtl_service_queue *parent_sq = sq->parent_sq;
struct throtl_grp *parent_tg = sq_to_tg(parent_sq);
struct throtl_grp *tg_to_put = NULL;
struct bio *bio;
bio = throtl_pop_queued(&sq->queued[rw], &tg_to_put);
sq->nr_queued[rw]--;
throtl_charge_bio(tg, bio);
if (parent_tg) {
throtl_add_bio_tg(bio, &tg->qnode_on_parent[rw], parent_tg);
start_parent_slice_with_credit(tg, parent_tg, rw);
} else {
throtl_qnode_add_bio(bio, &tg->qnode_on_parent[rw],
&parent_sq->queued[rw]);
BUG_ON(tg->td->nr_queued[rw] <= 0);
tg->td->nr_queued[rw]--;
}
throtl_trim_slice(tg, rw);
if (tg_to_put)
blkg_put(tg_to_blkg(tg_to_put));
}
static int throtl_dispatch_tg(struct throtl_grp *tg)
{
struct throtl_service_queue *sq = &tg->service_queue;
unsigned int nr_reads = 0, nr_writes = 0;
unsigned int max_nr_reads = throtl_grp_quantum*3/4;
unsigned int max_nr_writes = throtl_grp_quantum - max_nr_reads;
struct bio *bio;
while ((bio = throtl_peek_queued(&sq->queued[READ])) &&
tg_may_dispatch(tg, bio, NULL)) {
tg_dispatch_one_bio(tg, bio_data_dir(bio));
nr_reads++;
if (nr_reads >= max_nr_reads)
break;
}
while ((bio = throtl_peek_queued(&sq->queued[WRITE])) &&
tg_may_dispatch(tg, bio, NULL)) {
tg_dispatch_one_bio(tg, bio_data_dir(bio));
nr_writes++;
if (nr_writes >= max_nr_writes)
break;
}
return nr_reads + nr_writes;
}
static int throtl_select_dispatch(struct throtl_service_queue *parent_sq)
{
unsigned int nr_disp = 0;
while (1) {
struct throtl_grp *tg = throtl_rb_first(parent_sq);
struct throtl_service_queue *sq = &tg->service_queue;
if (!tg)
break;
if (time_before(jiffies, tg->disptime))
break;
throtl_dequeue_tg(tg);
nr_disp += throtl_dispatch_tg(tg);
if (sq->nr_queued[0] || sq->nr_queued[1])
tg_update_disptime(tg);
if (nr_disp >= throtl_quantum)
break;
}
return nr_disp;
}
static void throtl_pending_timer_fn(unsigned long arg)
{
struct throtl_service_queue *sq = (void *)arg;
struct throtl_grp *tg = sq_to_tg(sq);
struct throtl_data *td = sq_to_td(sq);
struct request_queue *q = td->queue;
struct throtl_service_queue *parent_sq;
bool dispatched;
int ret;
spin_lock_irq(q->queue_lock);
again:
parent_sq = sq->parent_sq;
dispatched = false;
while (true) {
throtl_log(sq, "dispatch nr_queued=%u read=%u write=%u",
sq->nr_queued[READ] + sq->nr_queued[WRITE],
sq->nr_queued[READ], sq->nr_queued[WRITE]);
ret = throtl_select_dispatch(sq);
if (ret) {
throtl_log(sq, "bios disp=%u", ret);
dispatched = true;
}
if (throtl_schedule_next_dispatch(sq, false))
break;
spin_unlock_irq(q->queue_lock);
cpu_relax();
spin_lock_irq(q->queue_lock);
}
if (!dispatched)
goto out_unlock;
if (parent_sq) {
if (tg->flags & THROTL_TG_WAS_EMPTY) {
tg_update_disptime(tg);
if (!throtl_schedule_next_dispatch(parent_sq, false)) {
sq = parent_sq;
tg = sq_to_tg(sq);
goto again;
}
}
} else {
queue_work(kthrotld_workqueue, &td->dispatch_work);
}
out_unlock:
spin_unlock_irq(q->queue_lock);
}
static void blk_throtl_dispatch_work_fn(struct work_struct *work)
{
struct throtl_data *td = container_of(work, struct throtl_data,
dispatch_work);
struct throtl_service_queue *td_sq = &td->service_queue;
struct request_queue *q = td->queue;
struct bio_list bio_list_on_stack;
struct bio *bio;
struct blk_plug plug;
int rw;
bio_list_init(&bio_list_on_stack);
spin_lock_irq(q->queue_lock);
for (rw = READ; rw <= WRITE; rw++)
while ((bio = throtl_pop_queued(&td_sq->queued[rw], NULL)))
bio_list_add(&bio_list_on_stack, bio);
spin_unlock_irq(q->queue_lock);
if (!bio_list_empty(&bio_list_on_stack)) {
blk_start_plug(&plug);
while((bio = bio_list_pop(&bio_list_on_stack)))
generic_make_request(bio);
blk_finish_plug(&plug);
}
}
static u64 tg_prfill_conf_u64(struct seq_file *sf, struct blkg_policy_data *pd,
int off)
{
struct throtl_grp *tg = pd_to_tg(pd);
u64 v = *(u64 *)((void *)tg + off);
if (v == -1)
return 0;
return __blkg_prfill_u64(sf, pd, v);
}
static u64 tg_prfill_conf_uint(struct seq_file *sf, struct blkg_policy_data *pd,
int off)
{
struct throtl_grp *tg = pd_to_tg(pd);
unsigned int v = *(unsigned int *)((void *)tg + off);
if (v == -1)
return 0;
return __blkg_prfill_u64(sf, pd, v);
}
static int tg_print_conf_u64(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)), tg_prfill_conf_u64,
&blkcg_policy_throtl, seq_cft(sf)->private, false);
return 0;
}
static int tg_print_conf_uint(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)), tg_prfill_conf_uint,
&blkcg_policy_throtl, seq_cft(sf)->private, false);
return 0;
}
static void tg_conf_updated(struct throtl_grp *tg)
{
struct throtl_service_queue *sq = &tg->service_queue;
struct cgroup_subsys_state *pos_css;
struct blkcg_gq *blkg;
throtl_log(&tg->service_queue,
"limit change rbps=%llu wbps=%llu riops=%u wiops=%u",
tg->bps[READ], tg->bps[WRITE],
tg->iops[READ], tg->iops[WRITE]);
blkg_for_each_descendant_pre(blkg, pos_css, tg_to_blkg(tg))
tg_update_has_rules(blkg_to_tg(blkg));
throtl_start_new_slice(tg, 0);
throtl_start_new_slice(tg, 1);
if (tg->flags & THROTL_TG_PENDING) {
tg_update_disptime(tg);
throtl_schedule_next_dispatch(sq->parent_sq, true);
}
}
static ssize_t tg_set_conf(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off, bool is_u64)
{
struct blkcg *blkcg = css_to_blkcg(of_css(of));
struct blkg_conf_ctx ctx;
struct throtl_grp *tg;
int ret;
u64 v;
ret = blkg_conf_prep(blkcg, &blkcg_policy_throtl, buf, &ctx);
if (ret)
return ret;
ret = -EINVAL;
if (sscanf(ctx.body, "%llu", &v) != 1)
goto out_finish;
if (!v)
v = -1;
tg = blkg_to_tg(ctx.blkg);
if (is_u64)
*(u64 *)((void *)tg + of_cft(of)->private) = v;
else
*(unsigned int *)((void *)tg + of_cft(of)->private) = v;
tg_conf_updated(tg);
ret = 0;
out_finish:
blkg_conf_finish(&ctx);
return ret ?: nbytes;
}
static ssize_t tg_set_conf_u64(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
return tg_set_conf(of, buf, nbytes, off, true);
}
static ssize_t tg_set_conf_uint(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
return tg_set_conf(of, buf, nbytes, off, false);
}
static u64 tg_prfill_max(struct seq_file *sf, struct blkg_policy_data *pd,
int off)
{
struct throtl_grp *tg = pd_to_tg(pd);
const char *dname = blkg_dev_name(pd->blkg);
char bufs[4][21] = { "max", "max", "max", "max" };
if (!dname)
return 0;
if (tg->bps[READ] == -1 && tg->bps[WRITE] == -1 &&
tg->iops[READ] == -1 && tg->iops[WRITE] == -1)
return 0;
if (tg->bps[READ] != -1)
snprintf(bufs[0], sizeof(bufs[0]), "%llu", tg->bps[READ]);
if (tg->bps[WRITE] != -1)
snprintf(bufs[1], sizeof(bufs[1]), "%llu", tg->bps[WRITE]);
if (tg->iops[READ] != -1)
snprintf(bufs[2], sizeof(bufs[2]), "%u", tg->iops[READ]);
if (tg->iops[WRITE] != -1)
snprintf(bufs[3], sizeof(bufs[3]), "%u", tg->iops[WRITE]);
seq_printf(sf, "%s rbps=%s wbps=%s riops=%s wiops=%s\n",
dname, bufs[0], bufs[1], bufs[2], bufs[3]);
return 0;
}
static int tg_print_max(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)), tg_prfill_max,
&blkcg_policy_throtl, seq_cft(sf)->private, false);
return 0;
}
static ssize_t tg_set_max(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
struct blkcg *blkcg = css_to_blkcg(of_css(of));
struct blkg_conf_ctx ctx;
struct throtl_grp *tg;
u64 v[4];
int ret;
ret = blkg_conf_prep(blkcg, &blkcg_policy_throtl, buf, &ctx);
if (ret)
return ret;
tg = blkg_to_tg(ctx.blkg);
v[0] = tg->bps[READ];
v[1] = tg->bps[WRITE];
v[2] = tg->iops[READ];
v[3] = tg->iops[WRITE];
while (true) {
char tok[27];
char *p;
u64 val = -1;
int len;
if (sscanf(ctx.body, "%26s%n", tok, &len) != 1)
break;
if (tok[0] == '\0')
break;
ctx.body += len;
ret = -EINVAL;
p = tok;
strsep(&p, "=");
if (!p || (sscanf(p, "%llu", &val) != 1 && strcmp(p, "max")))
goto out_finish;
ret = -ERANGE;
if (!val)
goto out_finish;
ret = -EINVAL;
if (!strcmp(tok, "rbps"))
v[0] = val;
else if (!strcmp(tok, "wbps"))
v[1] = val;
else if (!strcmp(tok, "riops"))
v[2] = min_t(u64, val, UINT_MAX);
else if (!strcmp(tok, "wiops"))
v[3] = min_t(u64, val, UINT_MAX);
else
goto out_finish;
}
tg->bps[READ] = v[0];
tg->bps[WRITE] = v[1];
tg->iops[READ] = v[2];
tg->iops[WRITE] = v[3];
tg_conf_updated(tg);
ret = 0;
out_finish:
blkg_conf_finish(&ctx);
return ret ?: nbytes;
}
static void throtl_shutdown_wq(struct request_queue *q)
{
struct throtl_data *td = q->td;
cancel_work_sync(&td->dispatch_work);
}
bool blk_throtl_bio(struct request_queue *q, struct blkcg_gq *blkg,
struct bio *bio)
{
struct throtl_qnode *qn = NULL;
struct throtl_grp *tg = blkg_to_tg(blkg ?: q->root_blkg);
struct throtl_service_queue *sq;
bool rw = bio_data_dir(bio);
bool throttled = false;
WARN_ON_ONCE(!rcu_read_lock_held());
if ((bio->bi_rw & REQ_THROTTLED) || !tg->has_rules[rw])
goto out;
spin_lock_irq(q->queue_lock);
if (unlikely(blk_queue_bypass(q)))
goto out_unlock;
sq = &tg->service_queue;
while (true) {
if (sq->nr_queued[rw])
break;
if (!tg_may_dispatch(tg, bio, NULL))
break;
throtl_charge_bio(tg, bio);
throtl_trim_slice(tg, rw);
qn = &tg->qnode_on_parent[rw];
sq = sq->parent_sq;
tg = sq_to_tg(sq);
if (!tg)
goto out_unlock;
}
throtl_log(sq, "[%c] bio. bdisp=%llu sz=%u bps=%llu iodisp=%u iops=%u queued=%d/%d",
rw == READ ? 'R' : 'W',
tg->bytes_disp[rw], bio->bi_iter.bi_size, tg->bps[rw],
tg->io_disp[rw], tg->iops[rw],
sq->nr_queued[READ], sq->nr_queued[WRITE]);
bio_associate_current(bio);
tg->td->nr_queued[rw]++;
throtl_add_bio_tg(bio, qn, tg);
throttled = true;
if (tg->flags & THROTL_TG_WAS_EMPTY) {
tg_update_disptime(tg);
throtl_schedule_next_dispatch(tg->service_queue.parent_sq, true);
}
out_unlock:
spin_unlock_irq(q->queue_lock);
out:
if (!throttled)
bio->bi_rw &= ~REQ_THROTTLED;
return throttled;
}
static void tg_drain_bios(struct throtl_service_queue *parent_sq)
{
struct throtl_grp *tg;
while ((tg = throtl_rb_first(parent_sq))) {
struct throtl_service_queue *sq = &tg->service_queue;
struct bio *bio;
throtl_dequeue_tg(tg);
while ((bio = throtl_peek_queued(&sq->queued[READ])))
tg_dispatch_one_bio(tg, bio_data_dir(bio));
while ((bio = throtl_peek_queued(&sq->queued[WRITE])))
tg_dispatch_one_bio(tg, bio_data_dir(bio));
}
}
void blk_throtl_drain(struct request_queue *q)
__releases(q->queue_lock) __acquires(q->queue_lock)
{
struct throtl_data *td = q->td;
struct blkcg_gq *blkg;
struct cgroup_subsys_state *pos_css;
struct bio *bio;
int rw;
queue_lockdep_assert_held(q);
rcu_read_lock();
blkg_for_each_descendant_post(blkg, pos_css, td->queue->root_blkg)
tg_drain_bios(&blkg_to_tg(blkg)->service_queue);
tg_drain_bios(&td->service_queue);
rcu_read_unlock();
spin_unlock_irq(q->queue_lock);
for (rw = READ; rw <= WRITE; rw++)
while ((bio = throtl_pop_queued(&td->service_queue.queued[rw],
NULL)))
generic_make_request(bio);
spin_lock_irq(q->queue_lock);
}
int blk_throtl_init(struct request_queue *q)
{
struct throtl_data *td;
int ret;
td = kzalloc_node(sizeof(*td), GFP_KERNEL, q->node);
if (!td)
return -ENOMEM;
INIT_WORK(&td->dispatch_work, blk_throtl_dispatch_work_fn);
throtl_service_queue_init(&td->service_queue);
q->td = td;
td->queue = q;
ret = blkcg_activate_policy(q, &blkcg_policy_throtl);
if (ret)
kfree(td);
return ret;
}
void blk_throtl_exit(struct request_queue *q)
{
BUG_ON(!q->td);
throtl_shutdown_wq(q);
blkcg_deactivate_policy(q, &blkcg_policy_throtl);
kfree(q->td);
}
static int __init throtl_init(void)
{
kthrotld_workqueue = alloc_workqueue("kthrotld", WQ_MEM_RECLAIM, 0);
if (!kthrotld_workqueue)
panic("Failed to create kthrotld\n");
return blkcg_policy_register(&blkcg_policy_throtl);
}
