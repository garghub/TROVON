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
static uint64_t throtl_adjusted_limit(uint64_t low, struct throtl_data *td)
{
if (td->scale < 4096 && time_after_eq(jiffies,
td->low_upgrade_time + td->scale * td->throtl_slice))
td->scale = (jiffies - td->low_upgrade_time) / td->throtl_slice;
return low + (low >> 1) * td->scale;
}
static uint64_t tg_bps_limit(struct throtl_grp *tg, int rw)
{
struct blkcg_gq *blkg = tg_to_blkg(tg);
struct throtl_data *td;
uint64_t ret;
if (cgroup_subsys_on_dfl(io_cgrp_subsys) && !blkg->parent)
return U64_MAX;
td = tg->td;
ret = tg->bps[rw][td->limit_index];
if (ret == 0 && td->limit_index == LIMIT_LOW) {
if (!list_empty(&blkg->blkcg->css.children) ||
tg->iops[rw][td->limit_index])
return U64_MAX;
else
return MIN_THROTL_BPS;
}
if (td->limit_index == LIMIT_MAX && tg->bps[rw][LIMIT_LOW] &&
tg->bps[rw][LIMIT_LOW] != tg->bps[rw][LIMIT_MAX]) {
uint64_t adjusted;
adjusted = throtl_adjusted_limit(tg->bps[rw][LIMIT_LOW], td);
ret = min(tg->bps[rw][LIMIT_MAX], adjusted);
}
return ret;
}
static unsigned int tg_iops_limit(struct throtl_grp *tg, int rw)
{
struct blkcg_gq *blkg = tg_to_blkg(tg);
struct throtl_data *td;
unsigned int ret;
if (cgroup_subsys_on_dfl(io_cgrp_subsys) && !blkg->parent)
return UINT_MAX;
td = tg->td;
ret = tg->iops[rw][td->limit_index];
if (ret == 0 && tg->td->limit_index == LIMIT_LOW) {
if (!list_empty(&blkg->blkcg->css.children) ||
tg->bps[rw][td->limit_index])
return UINT_MAX;
else
return MIN_THROTL_IOPS;
}
if (td->limit_index == LIMIT_MAX && tg->iops[rw][LIMIT_LOW] &&
tg->iops[rw][LIMIT_LOW] != tg->iops[rw][LIMIT_MAX]) {
uint64_t adjusted;
adjusted = throtl_adjusted_limit(tg->iops[rw][LIMIT_LOW], td);
if (adjusted > UINT_MAX)
adjusted = UINT_MAX;
ret = min_t(unsigned int, tg->iops[rw][LIMIT_MAX], adjusted);
}
return ret;
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
tg->bps[READ][LIMIT_MAX] = U64_MAX;
tg->bps[WRITE][LIMIT_MAX] = U64_MAX;
tg->iops[READ][LIMIT_MAX] = UINT_MAX;
tg->iops[WRITE][LIMIT_MAX] = UINT_MAX;
tg->bps_conf[READ][LIMIT_MAX] = U64_MAX;
tg->bps_conf[WRITE][LIMIT_MAX] = U64_MAX;
tg->iops_conf[READ][LIMIT_MAX] = UINT_MAX;
tg->iops_conf[WRITE][LIMIT_MAX] = UINT_MAX;
tg->latency_target = DFL_LATENCY_TARGET;
tg->latency_target_conf = DFL_LATENCY_TARGET;
tg->idletime_threshold = DFL_IDLE_THRESHOLD;
tg->idletime_threshold_conf = DFL_IDLE_THRESHOLD;
return &tg->pd;
}
static void throtl_pd_init(struct blkg_policy_data *pd)
{
struct throtl_grp *tg = pd_to_tg(pd);
struct blkcg_gq *blkg = tg_to_blkg(tg);
struct throtl_data *td = blkg->q->td;
struct throtl_service_queue *sq = &tg->service_queue;
sq->parent_sq = &td->service_queue;
if (cgroup_subsys_on_dfl(io_cgrp_subsys) && blkg->parent)
sq->parent_sq = &blkg_to_tg(blkg->parent)->service_queue;
tg->td = td;
}
static void tg_update_has_rules(struct throtl_grp *tg)
{
struct throtl_grp *parent_tg = sq_to_tg(tg->service_queue.parent_sq);
struct throtl_data *td = tg->td;
int rw;
for (rw = READ; rw <= WRITE; rw++)
tg->has_rules[rw] = (parent_tg && parent_tg->has_rules[rw]) ||
(td->limit_valid[td->limit_index] &&
(tg_bps_limit(tg, rw) != U64_MAX ||
tg_iops_limit(tg, rw) != UINT_MAX));
}
static void throtl_pd_online(struct blkg_policy_data *pd)
{
struct throtl_grp *tg = pd_to_tg(pd);
tg_update_has_rules(tg);
}
static void blk_throtl_update_limit_valid(struct throtl_data *td)
{
struct cgroup_subsys_state *pos_css;
struct blkcg_gq *blkg;
bool low_valid = false;
rcu_read_lock();
blkg_for_each_descendant_post(blkg, pos_css, td->queue->root_blkg) {
struct throtl_grp *tg = blkg_to_tg(blkg);
if (tg->bps[READ][LIMIT_LOW] || tg->bps[WRITE][LIMIT_LOW] ||
tg->iops[READ][LIMIT_LOW] || tg->iops[WRITE][LIMIT_LOW])
low_valid = true;
}
rcu_read_unlock();
td->limit_valid[LIMIT_LOW] = low_valid;
}
static void throtl_pd_offline(struct blkg_policy_data *pd)
{
struct throtl_grp *tg = pd_to_tg(pd);
tg->bps[READ][LIMIT_LOW] = 0;
tg->bps[WRITE][LIMIT_LOW] = 0;
tg->iops[READ][LIMIT_LOW] = 0;
tg->iops[WRITE][LIMIT_LOW] = 0;
blk_throtl_update_limit_valid(tg->td);
if (!tg->td->limit_valid[tg->td->limit_index])
throtl_upgrade_state(tg->td);
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
unsigned long max_expire = jiffies + 8 * sq_to_td(sq)->throtl_slice;
if (time_after(expires, max_expire))
expires = max_expire;
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
tg->slice_end[rw] = jiffies + tg->td->throtl_slice;
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
tg->slice_end[rw] = jiffies + tg->td->throtl_slice;
throtl_log(&tg->service_queue,
"[%c] new slice start=%lu end=%lu jiffies=%lu",
rw == READ ? 'R' : 'W', tg->slice_start[rw],
tg->slice_end[rw], jiffies);
}
static inline void throtl_set_slice_end(struct throtl_grp *tg, bool rw,
unsigned long jiffy_end)
{
tg->slice_end[rw] = roundup(jiffy_end, tg->td->throtl_slice);
}
static inline void throtl_extend_slice(struct throtl_grp *tg, bool rw,
unsigned long jiffy_end)
{
tg->slice_end[rw] = roundup(jiffy_end, tg->td->throtl_slice);
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
throtl_set_slice_end(tg, rw, jiffies + tg->td->throtl_slice);
time_elapsed = jiffies - tg->slice_start[rw];
nr_slices = time_elapsed / tg->td->throtl_slice;
if (!nr_slices)
return;
tmp = tg_bps_limit(tg, rw) * tg->td->throtl_slice * nr_slices;
do_div(tmp, HZ);
bytes_trim = tmp;
io_trim = (tg_iops_limit(tg, rw) * tg->td->throtl_slice * nr_slices) /
HZ;
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
tg->slice_start[rw] += nr_slices * tg->td->throtl_slice;
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
jiffy_elapsed_rnd = tg->td->throtl_slice;
jiffy_elapsed_rnd = roundup(jiffy_elapsed_rnd, tg->td->throtl_slice);
tmp = (u64)tg_iops_limit(tg, rw) * jiffy_elapsed_rnd;
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
jiffy_wait = ((tg->io_disp[rw] + 1) * HZ) / tg_iops_limit(tg, rw) + 1;
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
jiffy_elapsed_rnd = tg->td->throtl_slice;
jiffy_elapsed_rnd = roundup(jiffy_elapsed_rnd, tg->td->throtl_slice);
tmp = tg_bps_limit(tg, rw) * jiffy_elapsed_rnd;
do_div(tmp, HZ);
bytes_allowed = tmp;
if (tg->bytes_disp[rw] + bio->bi_iter.bi_size <= bytes_allowed) {
if (wait)
*wait = 0;
return true;
}
extra_bytes = tg->bytes_disp[rw] + bio->bi_iter.bi_size - bytes_allowed;
jiffy_wait = div64_u64(extra_bytes * HZ, tg_bps_limit(tg, rw));
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
if (tg_bps_limit(tg, rw) == U64_MAX &&
tg_iops_limit(tg, rw) == UINT_MAX) {
if (wait)
*wait = 0;
return true;
}
if (throtl_slice_used(tg, rw) && !(tg->service_queue.nr_queued[rw]))
throtl_start_new_slice(tg, rw);
else {
if (time_before(tg->slice_end[rw],
jiffies + tg->td->throtl_slice))
throtl_extend_slice(tg, rw,
jiffies + tg->td->throtl_slice);
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
tg->last_bytes_disp[rw] += bio->bi_iter.bi_size;
tg->last_io_disp[rw]++;
if (!bio_flagged(bio, BIO_THROTTLED))
bio_set_flag(bio, BIO_THROTTLED);
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
bio = throtl_peek_queued(&sq->queued[READ]);
if (bio)
tg_may_dispatch(tg, bio, &read_wait);
bio = throtl_peek_queued(&sq->queued[WRITE]);
if (bio)
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
if (throtl_can_upgrade(td, NULL))
throtl_upgrade_state(td);
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
if (v == U64_MAX)
return 0;
return __blkg_prfill_u64(sf, pd, v);
}
static u64 tg_prfill_conf_uint(struct seq_file *sf, struct blkg_policy_data *pd,
int off)
{
struct throtl_grp *tg = pd_to_tg(pd);
unsigned int v = *(unsigned int *)((void *)tg + off);
if (v == UINT_MAX)
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
static void tg_conf_updated(struct throtl_grp *tg, bool global)
{
struct throtl_service_queue *sq = &tg->service_queue;
struct cgroup_subsys_state *pos_css;
struct blkcg_gq *blkg;
throtl_log(&tg->service_queue,
"limit change rbps=%llu wbps=%llu riops=%u wiops=%u",
tg_bps_limit(tg, READ), tg_bps_limit(tg, WRITE),
tg_iops_limit(tg, READ), tg_iops_limit(tg, WRITE));
blkg_for_each_descendant_pre(blkg, pos_css,
global ? tg->td->queue->root_blkg : tg_to_blkg(tg)) {
struct throtl_grp *this_tg = blkg_to_tg(blkg);
struct throtl_grp *parent_tg;
tg_update_has_rules(this_tg);
if (!cgroup_subsys_on_dfl(io_cgrp_subsys) || !blkg->parent ||
!blkg->parent->parent)
continue;
parent_tg = blkg_to_tg(blkg->parent);
this_tg->idletime_threshold = min(this_tg->idletime_threshold,
parent_tg->idletime_threshold);
this_tg->latency_target = max(this_tg->latency_target,
parent_tg->latency_target);
}
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
v = U64_MAX;
tg = blkg_to_tg(ctx.blkg);
if (is_u64)
*(u64 *)((void *)tg + of_cft(of)->private) = v;
else
*(unsigned int *)((void *)tg + of_cft(of)->private) = v;
tg_conf_updated(tg, false);
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
static u64 tg_prfill_limit(struct seq_file *sf, struct blkg_policy_data *pd,
int off)
{
struct throtl_grp *tg = pd_to_tg(pd);
const char *dname = blkg_dev_name(pd->blkg);
char bufs[4][21] = { "max", "max", "max", "max" };
u64 bps_dft;
unsigned int iops_dft;
char idle_time[26] = "";
char latency_time[26] = "";
if (!dname)
return 0;
if (off == LIMIT_LOW) {
bps_dft = 0;
iops_dft = 0;
} else {
bps_dft = U64_MAX;
iops_dft = UINT_MAX;
}
if (tg->bps_conf[READ][off] == bps_dft &&
tg->bps_conf[WRITE][off] == bps_dft &&
tg->iops_conf[READ][off] == iops_dft &&
tg->iops_conf[WRITE][off] == iops_dft &&
(off != LIMIT_LOW ||
(tg->idletime_threshold_conf == DFL_IDLE_THRESHOLD &&
tg->latency_target_conf == DFL_LATENCY_TARGET)))
return 0;
if (tg->bps_conf[READ][off] != U64_MAX)
snprintf(bufs[0], sizeof(bufs[0]), "%llu",
tg->bps_conf[READ][off]);
if (tg->bps_conf[WRITE][off] != U64_MAX)
snprintf(bufs[1], sizeof(bufs[1]), "%llu",
tg->bps_conf[WRITE][off]);
if (tg->iops_conf[READ][off] != UINT_MAX)
snprintf(bufs[2], sizeof(bufs[2]), "%u",
tg->iops_conf[READ][off]);
if (tg->iops_conf[WRITE][off] != UINT_MAX)
snprintf(bufs[3], sizeof(bufs[3]), "%u",
tg->iops_conf[WRITE][off]);
if (off == LIMIT_LOW) {
if (tg->idletime_threshold_conf == ULONG_MAX)
strcpy(idle_time, " idle=max");
else
snprintf(idle_time, sizeof(idle_time), " idle=%lu",
tg->idletime_threshold_conf);
if (tg->latency_target_conf == ULONG_MAX)
strcpy(latency_time, " latency=max");
else
snprintf(latency_time, sizeof(latency_time),
" latency=%lu", tg->latency_target_conf);
}
seq_printf(sf, "%s rbps=%s wbps=%s riops=%s wiops=%s%s%s\n",
dname, bufs[0], bufs[1], bufs[2], bufs[3], idle_time,
latency_time);
return 0;
}
static int tg_print_limit(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)), tg_prfill_limit,
&blkcg_policy_throtl, seq_cft(sf)->private, false);
return 0;
}
static ssize_t tg_set_limit(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
struct blkcg *blkcg = css_to_blkcg(of_css(of));
struct blkg_conf_ctx ctx;
struct throtl_grp *tg;
u64 v[4];
unsigned long idle_time;
unsigned long latency_time;
int ret;
int index = of_cft(of)->private;
ret = blkg_conf_prep(blkcg, &blkcg_policy_throtl, buf, &ctx);
if (ret)
return ret;
tg = blkg_to_tg(ctx.blkg);
v[0] = tg->bps_conf[READ][index];
v[1] = tg->bps_conf[WRITE][index];
v[2] = tg->iops_conf[READ][index];
v[3] = tg->iops_conf[WRITE][index];
idle_time = tg->idletime_threshold_conf;
latency_time = tg->latency_target_conf;
while (true) {
char tok[27];
char *p;
u64 val = U64_MAX;
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
else if (off == LIMIT_LOW && !strcmp(tok, "idle"))
idle_time = val;
else if (off == LIMIT_LOW && !strcmp(tok, "latency"))
latency_time = val;
else
goto out_finish;
}
tg->bps_conf[READ][index] = v[0];
tg->bps_conf[WRITE][index] = v[1];
tg->iops_conf[READ][index] = v[2];
tg->iops_conf[WRITE][index] = v[3];
if (index == LIMIT_MAX) {
tg->bps[READ][index] = v[0];
tg->bps[WRITE][index] = v[1];
tg->iops[READ][index] = v[2];
tg->iops[WRITE][index] = v[3];
}
tg->bps[READ][LIMIT_LOW] = min(tg->bps_conf[READ][LIMIT_LOW],
tg->bps_conf[READ][LIMIT_MAX]);
tg->bps[WRITE][LIMIT_LOW] = min(tg->bps_conf[WRITE][LIMIT_LOW],
tg->bps_conf[WRITE][LIMIT_MAX]);
tg->iops[READ][LIMIT_LOW] = min(tg->iops_conf[READ][LIMIT_LOW],
tg->iops_conf[READ][LIMIT_MAX]);
tg->iops[WRITE][LIMIT_LOW] = min(tg->iops_conf[WRITE][LIMIT_LOW],
tg->iops_conf[WRITE][LIMIT_MAX]);
tg->idletime_threshold_conf = idle_time;
tg->latency_target_conf = latency_time;
if (!(tg->bps[READ][LIMIT_LOW] || tg->iops[READ][LIMIT_LOW] ||
tg->bps[WRITE][LIMIT_LOW] || tg->iops[WRITE][LIMIT_LOW]) ||
tg->idletime_threshold_conf == DFL_IDLE_THRESHOLD ||
tg->latency_target_conf == DFL_LATENCY_TARGET) {
tg->bps[READ][LIMIT_LOW] = 0;
tg->bps[WRITE][LIMIT_LOW] = 0;
tg->iops[READ][LIMIT_LOW] = 0;
tg->iops[WRITE][LIMIT_LOW] = 0;
tg->idletime_threshold = DFL_IDLE_THRESHOLD;
tg->latency_target = DFL_LATENCY_TARGET;
} else if (index == LIMIT_LOW) {
tg->idletime_threshold = tg->idletime_threshold_conf;
tg->latency_target = tg->latency_target_conf;
}
blk_throtl_update_limit_valid(tg->td);
if (tg->td->limit_valid[LIMIT_LOW]) {
if (index == LIMIT_LOW)
tg->td->limit_index = LIMIT_LOW;
} else
tg->td->limit_index = LIMIT_MAX;
tg_conf_updated(tg, index == LIMIT_LOW &&
tg->td->limit_valid[LIMIT_LOW]);
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
static unsigned long __tg_last_low_overflow_time(struct throtl_grp *tg)
{
unsigned long rtime = jiffies, wtime = jiffies;
if (tg->bps[READ][LIMIT_LOW] || tg->iops[READ][LIMIT_LOW])
rtime = tg->last_low_overflow_time[READ];
if (tg->bps[WRITE][LIMIT_LOW] || tg->iops[WRITE][LIMIT_LOW])
wtime = tg->last_low_overflow_time[WRITE];
return min(rtime, wtime);
}
static unsigned long tg_last_low_overflow_time(struct throtl_grp *tg)
{
struct throtl_service_queue *parent_sq;
struct throtl_grp *parent = tg;
unsigned long ret = __tg_last_low_overflow_time(tg);
while (true) {
parent_sq = parent->service_queue.parent_sq;
parent = sq_to_tg(parent_sq);
if (!parent)
break;
if (!parent->bps[READ][LIMIT_LOW] &&
!parent->iops[READ][LIMIT_LOW] &&
!parent->bps[WRITE][LIMIT_LOW] &&
!parent->iops[WRITE][LIMIT_LOW])
continue;
if (time_after(__tg_last_low_overflow_time(parent), ret))
ret = __tg_last_low_overflow_time(parent);
}
return ret;
}
static bool throtl_tg_is_idle(struct throtl_grp *tg)
{
unsigned long time;
bool ret;
time = min_t(unsigned long, MAX_IDLE_TIME, 4 * tg->idletime_threshold);
ret = tg->latency_target == DFL_LATENCY_TARGET ||
tg->idletime_threshold == DFL_IDLE_THRESHOLD ||
(ktime_get_ns() >> 10) - tg->last_finish_time > time ||
tg->avg_idletime > tg->idletime_threshold ||
(tg->latency_target && tg->bio_cnt &&
tg->bad_bio_cnt * 5 < tg->bio_cnt);
throtl_log(&tg->service_queue,
"avg_idle=%ld, idle_threshold=%ld, bad_bio=%d, total_bio=%d, is_idle=%d, scale=%d",
tg->avg_idletime, tg->idletime_threshold, tg->bad_bio_cnt,
tg->bio_cnt, ret, tg->td->scale);
return ret;
}
static bool throtl_tg_can_upgrade(struct throtl_grp *tg)
{
struct throtl_service_queue *sq = &tg->service_queue;
bool read_limit, write_limit;
read_limit = tg->bps[READ][LIMIT_LOW] || tg->iops[READ][LIMIT_LOW];
write_limit = tg->bps[WRITE][LIMIT_LOW] || tg->iops[WRITE][LIMIT_LOW];
if (!read_limit && !write_limit)
return true;
if (read_limit && sq->nr_queued[READ] &&
(!write_limit || sq->nr_queued[WRITE]))
return true;
if (write_limit && sq->nr_queued[WRITE] &&
(!read_limit || sq->nr_queued[READ]))
return true;
if (time_after_eq(jiffies,
tg_last_low_overflow_time(tg) + tg->td->throtl_slice) &&
throtl_tg_is_idle(tg))
return true;
return false;
}
static bool throtl_hierarchy_can_upgrade(struct throtl_grp *tg)
{
while (true) {
if (throtl_tg_can_upgrade(tg))
return true;
tg = sq_to_tg(tg->service_queue.parent_sq);
if (!tg || !tg_to_blkg(tg)->parent)
return false;
}
return false;
}
static bool throtl_can_upgrade(struct throtl_data *td,
struct throtl_grp *this_tg)
{
struct cgroup_subsys_state *pos_css;
struct blkcg_gq *blkg;
if (td->limit_index != LIMIT_LOW)
return false;
if (time_before(jiffies, td->low_downgrade_time + td->throtl_slice))
return false;
rcu_read_lock();
blkg_for_each_descendant_post(blkg, pos_css, td->queue->root_blkg) {
struct throtl_grp *tg = blkg_to_tg(blkg);
if (tg == this_tg)
continue;
if (!list_empty(&tg_to_blkg(tg)->blkcg->css.children))
continue;
if (!throtl_hierarchy_can_upgrade(tg)) {
rcu_read_unlock();
return false;
}
}
rcu_read_unlock();
return true;
}
static void throtl_upgrade_check(struct throtl_grp *tg)
{
unsigned long now = jiffies;
if (tg->td->limit_index != LIMIT_LOW)
return;
if (time_after(tg->last_check_time + tg->td->throtl_slice, now))
return;
tg->last_check_time = now;
if (!time_after_eq(now,
__tg_last_low_overflow_time(tg) + tg->td->throtl_slice))
return;
if (throtl_can_upgrade(tg->td, NULL))
throtl_upgrade_state(tg->td);
}
static void throtl_upgrade_state(struct throtl_data *td)
{
struct cgroup_subsys_state *pos_css;
struct blkcg_gq *blkg;
throtl_log(&td->service_queue, "upgrade to max");
td->limit_index = LIMIT_MAX;
td->low_upgrade_time = jiffies;
td->scale = 0;
rcu_read_lock();
blkg_for_each_descendant_post(blkg, pos_css, td->queue->root_blkg) {
struct throtl_grp *tg = blkg_to_tg(blkg);
struct throtl_service_queue *sq = &tg->service_queue;
tg->disptime = jiffies - 1;
throtl_select_dispatch(sq);
throtl_schedule_next_dispatch(sq, false);
}
rcu_read_unlock();
throtl_select_dispatch(&td->service_queue);
throtl_schedule_next_dispatch(&td->service_queue, false);
queue_work(kthrotld_workqueue, &td->dispatch_work);
}
static void throtl_downgrade_state(struct throtl_data *td, int new)
{
td->scale /= 2;
throtl_log(&td->service_queue, "downgrade, scale %d", td->scale);
if (td->scale) {
td->low_upgrade_time = jiffies - td->scale * td->throtl_slice;
return;
}
td->limit_index = new;
td->low_downgrade_time = jiffies;
}
static bool throtl_tg_can_downgrade(struct throtl_grp *tg)
{
struct throtl_data *td = tg->td;
unsigned long now = jiffies;
if (time_after_eq(now, td->low_upgrade_time + td->throtl_slice) &&
time_after_eq(now, tg_last_low_overflow_time(tg) +
td->throtl_slice) &&
(!throtl_tg_is_idle(tg) ||
!list_empty(&tg_to_blkg(tg)->blkcg->css.children)))
return true;
return false;
}
static bool throtl_hierarchy_can_downgrade(struct throtl_grp *tg)
{
while (true) {
if (!throtl_tg_can_downgrade(tg))
return false;
tg = sq_to_tg(tg->service_queue.parent_sq);
if (!tg || !tg_to_blkg(tg)->parent)
break;
}
return true;
}
static void throtl_downgrade_check(struct throtl_grp *tg)
{
uint64_t bps;
unsigned int iops;
unsigned long elapsed_time;
unsigned long now = jiffies;
if (tg->td->limit_index != LIMIT_MAX ||
!tg->td->limit_valid[LIMIT_LOW])
return;
if (!list_empty(&tg_to_blkg(tg)->blkcg->css.children))
return;
if (time_after(tg->last_check_time + tg->td->throtl_slice, now))
return;
elapsed_time = now - tg->last_check_time;
tg->last_check_time = now;
if (time_before(now, tg_last_low_overflow_time(tg) +
tg->td->throtl_slice))
return;
if (tg->bps[READ][LIMIT_LOW]) {
bps = tg->last_bytes_disp[READ] * HZ;
do_div(bps, elapsed_time);
if (bps >= tg->bps[READ][LIMIT_LOW])
tg->last_low_overflow_time[READ] = now;
}
if (tg->bps[WRITE][LIMIT_LOW]) {
bps = tg->last_bytes_disp[WRITE] * HZ;
do_div(bps, elapsed_time);
if (bps >= tg->bps[WRITE][LIMIT_LOW])
tg->last_low_overflow_time[WRITE] = now;
}
if (tg->iops[READ][LIMIT_LOW]) {
iops = tg->last_io_disp[READ] * HZ / elapsed_time;
if (iops >= tg->iops[READ][LIMIT_LOW])
tg->last_low_overflow_time[READ] = now;
}
if (tg->iops[WRITE][LIMIT_LOW]) {
iops = tg->last_io_disp[WRITE] * HZ / elapsed_time;
if (iops >= tg->iops[WRITE][LIMIT_LOW])
tg->last_low_overflow_time[WRITE] = now;
}
if (throtl_hierarchy_can_downgrade(tg))
throtl_downgrade_state(tg->td, LIMIT_LOW);
tg->last_bytes_disp[READ] = 0;
tg->last_bytes_disp[WRITE] = 0;
tg->last_io_disp[READ] = 0;
tg->last_io_disp[WRITE] = 0;
}
static void blk_throtl_update_idletime(struct throtl_grp *tg)
{
unsigned long now = ktime_get_ns() >> 10;
unsigned long last_finish_time = tg->last_finish_time;
if (now <= last_finish_time || last_finish_time == 0 ||
last_finish_time == tg->checked_last_finish_time)
return;
tg->avg_idletime = (tg->avg_idletime * 7 + now - last_finish_time) >> 3;
tg->checked_last_finish_time = last_finish_time;
}
static void throtl_update_latency_buckets(struct throtl_data *td)
{
struct avg_latency_bucket avg_latency[LATENCY_BUCKET_SIZE];
int i, cpu;
unsigned long last_latency = 0;
unsigned long latency;
if (!blk_queue_nonrot(td->queue))
return;
if (time_before(jiffies, td->last_calculate_time + HZ))
return;
td->last_calculate_time = jiffies;
memset(avg_latency, 0, sizeof(avg_latency));
for (i = 0; i < LATENCY_BUCKET_SIZE; i++) {
struct latency_bucket *tmp = &td->tmp_buckets[i];
for_each_possible_cpu(cpu) {
struct latency_bucket *bucket;
bucket = per_cpu_ptr(td->latency_buckets, cpu);
tmp->total_latency += bucket[i].total_latency;
tmp->samples += bucket[i].samples;
bucket[i].total_latency = 0;
bucket[i].samples = 0;
}
if (tmp->samples >= 32) {
int samples = tmp->samples;
latency = tmp->total_latency;
tmp->total_latency = 0;
tmp->samples = 0;
latency /= samples;
if (latency == 0)
continue;
avg_latency[i].latency = latency;
}
}
for (i = 0; i < LATENCY_BUCKET_SIZE; i++) {
if (!avg_latency[i].latency) {
if (td->avg_buckets[i].latency < last_latency)
td->avg_buckets[i].latency = last_latency;
continue;
}
if (!td->avg_buckets[i].valid)
latency = avg_latency[i].latency;
else
latency = (td->avg_buckets[i].latency * 7 +
avg_latency[i].latency) >> 3;
td->avg_buckets[i].latency = max(latency, last_latency);
td->avg_buckets[i].valid = true;
last_latency = td->avg_buckets[i].latency;
}
for (i = 0; i < LATENCY_BUCKET_SIZE; i++)
throtl_log(&td->service_queue,
"Latency bucket %d: latency=%ld, valid=%d", i,
td->avg_buckets[i].latency, td->avg_buckets[i].valid);
}
static inline void throtl_update_latency_buckets(struct throtl_data *td)
{
}
static void blk_throtl_assoc_bio(struct throtl_grp *tg, struct bio *bio)
{
#ifdef CONFIG_BLK_DEV_THROTTLING_LOW
int ret;
ret = bio_associate_current(bio);
if (ret == 0 || ret == -EBUSY)
bio->bi_cg_private = tg;
blk_stat_set_issue(&bio->bi_issue_stat, bio_sectors(bio));
#else
bio_associate_current(bio);
#endif
}
bool blk_throtl_bio(struct request_queue *q, struct blkcg_gq *blkg,
struct bio *bio)
{
struct throtl_qnode *qn = NULL;
struct throtl_grp *tg = blkg_to_tg(blkg ?: q->root_blkg);
struct throtl_service_queue *sq;
bool rw = bio_data_dir(bio);
bool throttled = false;
struct throtl_data *td = tg->td;
WARN_ON_ONCE(!rcu_read_lock_held());
if (bio_flagged(bio, BIO_THROTTLED) || !tg->has_rules[rw])
goto out;
spin_lock_irq(q->queue_lock);
throtl_update_latency_buckets(td);
if (unlikely(blk_queue_bypass(q)))
goto out_unlock;
blk_throtl_assoc_bio(tg, bio);
blk_throtl_update_idletime(tg);
sq = &tg->service_queue;
again:
while (true) {
if (tg->last_low_overflow_time[rw] == 0)
tg->last_low_overflow_time[rw] = jiffies;
throtl_downgrade_check(tg);
throtl_upgrade_check(tg);
if (sq->nr_queued[rw])
break;
if (!tg_may_dispatch(tg, bio, NULL)) {
tg->last_low_overflow_time[rw] = jiffies;
if (throtl_can_upgrade(td, tg)) {
throtl_upgrade_state(td);
goto again;
}
break;
}
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
tg->bytes_disp[rw], bio->bi_iter.bi_size,
tg_bps_limit(tg, rw),
tg->io_disp[rw], tg_iops_limit(tg, rw),
sq->nr_queued[READ], sq->nr_queued[WRITE]);
tg->last_low_overflow_time[rw] = jiffies;
td->nr_queued[rw]++;
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
bio_clear_flag(bio, BIO_THROTTLED);
#ifdef CONFIG_BLK_DEV_THROTTLING_LOW
if (throttled || !td->track_bio_latency)
bio->bi_issue_stat.stat |= SKIP_LATENCY;
#endif
return throttled;
}
static void throtl_track_latency(struct throtl_data *td, sector_t size,
int op, unsigned long time)
{
struct latency_bucket *latency;
int index;
if (!td || td->limit_index != LIMIT_LOW || op != REQ_OP_READ ||
!blk_queue_nonrot(td->queue))
return;
index = request_bucket_index(size);
latency = get_cpu_ptr(td->latency_buckets);
latency[index].total_latency += time;
latency[index].samples++;
put_cpu_ptr(td->latency_buckets);
}
void blk_throtl_stat_add(struct request *rq, u64 time_ns)
{
struct request_queue *q = rq->q;
struct throtl_data *td = q->td;
throtl_track_latency(td, blk_stat_size(&rq->issue_stat),
req_op(rq), time_ns >> 10);
}
void blk_throtl_bio_endio(struct bio *bio)
{
struct throtl_grp *tg;
u64 finish_time_ns;
unsigned long finish_time;
unsigned long start_time;
unsigned long lat;
tg = bio->bi_cg_private;
if (!tg)
return;
bio->bi_cg_private = NULL;
finish_time_ns = ktime_get_ns();
tg->last_finish_time = finish_time_ns >> 10;
start_time = blk_stat_time(&bio->bi_issue_stat) >> 10;
finish_time = __blk_stat_time(finish_time_ns) >> 10;
if (!start_time || finish_time <= start_time)
return;
lat = finish_time - start_time;
if (!(bio->bi_issue_stat.stat & SKIP_LATENCY))
throtl_track_latency(tg->td, blk_stat_size(&bio->bi_issue_stat),
bio_op(bio), lat);
if (tg->latency_target && lat >= tg->td->filtered_latency) {
int bucket;
unsigned int threshold;
bucket = request_bucket_index(
blk_stat_size(&bio->bi_issue_stat));
threshold = tg->td->avg_buckets[bucket].latency +
tg->latency_target;
if (lat > threshold)
tg->bad_bio_cnt++;
tg->bio_cnt++;
}
if (time_after(jiffies, tg->bio_cnt_reset_time) || tg->bio_cnt > 1024) {
tg->bio_cnt_reset_time = tg->td->throtl_slice + jiffies;
tg->bio_cnt /= 2;
tg->bad_bio_cnt /= 2;
}
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
td->latency_buckets = __alloc_percpu(sizeof(struct latency_bucket) *
LATENCY_BUCKET_SIZE, __alignof__(u64));
if (!td->latency_buckets) {
kfree(td);
return -ENOMEM;
}
INIT_WORK(&td->dispatch_work, blk_throtl_dispatch_work_fn);
throtl_service_queue_init(&td->service_queue);
q->td = td;
td->queue = q;
td->limit_valid[LIMIT_MAX] = true;
td->limit_index = LIMIT_MAX;
td->low_upgrade_time = jiffies;
td->low_downgrade_time = jiffies;
ret = blkcg_activate_policy(q, &blkcg_policy_throtl);
if (ret) {
free_percpu(td->latency_buckets);
kfree(td);
}
return ret;
}
void blk_throtl_exit(struct request_queue *q)
{
BUG_ON(!q->td);
throtl_shutdown_wq(q);
blkcg_deactivate_policy(q, &blkcg_policy_throtl);
free_percpu(q->td->latency_buckets);
kfree(q->td);
}
void blk_throtl_register_queue(struct request_queue *q)
{
struct throtl_data *td;
int i;
td = q->td;
BUG_ON(!td);
if (blk_queue_nonrot(q)) {
td->throtl_slice = DFL_THROTL_SLICE_SSD;
td->filtered_latency = LATENCY_FILTERED_SSD;
} else {
td->throtl_slice = DFL_THROTL_SLICE_HD;
td->filtered_latency = LATENCY_FILTERED_HD;
for (i = 0; i < LATENCY_BUCKET_SIZE; i++)
td->avg_buckets[i].latency = DFL_HD_BASELINE_LATENCY;
}
#ifndef CONFIG_BLK_DEV_THROTTLING_LOW
td->throtl_slice = DFL_THROTL_SLICE_HD;
#endif
td->track_bio_latency = !q->mq_ops && !q->request_fn;
if (!td->track_bio_latency)
blk_stat_enable_accounting(q);
}
ssize_t blk_throtl_sample_time_show(struct request_queue *q, char *page)
{
if (!q->td)
return -EINVAL;
return sprintf(page, "%u\n", jiffies_to_msecs(q->td->throtl_slice));
}
ssize_t blk_throtl_sample_time_store(struct request_queue *q,
const char *page, size_t count)
{
unsigned long v;
unsigned long t;
if (!q->td)
return -EINVAL;
if (kstrtoul(page, 10, &v))
return -EINVAL;
t = msecs_to_jiffies(v);
if (t == 0 || t > MAX_THROTL_SLICE)
return -EINVAL;
q->td->throtl_slice = t;
return count;
}
static int __init throtl_init(void)
{
kthrotld_workqueue = alloc_workqueue("kthrotld", WQ_MEM_RECLAIM, 0);
if (!kthrotld_workqueue)
panic("Failed to create kthrotld\n");
return blkcg_policy_register(&blkcg_policy_throtl);
}
