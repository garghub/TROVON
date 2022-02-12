static struct cfq_rb_root *st_for(struct cfq_group *cfqg,
enum wl_class_t class,
enum wl_type_t type)
{
if (!cfqg)
return NULL;
if (class == IDLE_WORKLOAD)
return &cfqg->service_tree_idle;
return &cfqg->service_trees[class][type];
}
static void cfqg_stats_update_group_wait_time(struct cfqg_stats *stats)
{
unsigned long long now;
if (!cfqg_stats_waiting(stats))
return;
now = sched_clock();
if (time_after64(now, stats->start_group_wait_time))
blkg_stat_add(&stats->group_wait_time,
now - stats->start_group_wait_time);
cfqg_stats_clear_waiting(stats);
}
static void cfqg_stats_set_start_group_wait_time(struct cfq_group *cfqg,
struct cfq_group *curr_cfqg)
{
struct cfqg_stats *stats = &cfqg->stats;
if (cfqg_stats_waiting(stats))
return;
if (cfqg == curr_cfqg)
return;
stats->start_group_wait_time = sched_clock();
cfqg_stats_mark_waiting(stats);
}
static void cfqg_stats_end_empty_time(struct cfqg_stats *stats)
{
unsigned long long now;
if (!cfqg_stats_empty(stats))
return;
now = sched_clock();
if (time_after64(now, stats->start_empty_time))
blkg_stat_add(&stats->empty_time,
now - stats->start_empty_time);
cfqg_stats_clear_empty(stats);
}
static void cfqg_stats_update_dequeue(struct cfq_group *cfqg)
{
blkg_stat_add(&cfqg->stats.dequeue, 1);
}
static void cfqg_stats_set_start_empty_time(struct cfq_group *cfqg)
{
struct cfqg_stats *stats = &cfqg->stats;
if (blkg_rwstat_total(&stats->queued))
return;
if (cfqg_stats_empty(stats))
return;
stats->start_empty_time = sched_clock();
cfqg_stats_mark_empty(stats);
}
static void cfqg_stats_update_idle_time(struct cfq_group *cfqg)
{
struct cfqg_stats *stats = &cfqg->stats;
if (cfqg_stats_idling(stats)) {
unsigned long long now = sched_clock();
if (time_after64(now, stats->start_idle_time))
blkg_stat_add(&stats->idle_time,
now - stats->start_idle_time);
cfqg_stats_clear_idling(stats);
}
}
static void cfqg_stats_set_start_idle_time(struct cfq_group *cfqg)
{
struct cfqg_stats *stats = &cfqg->stats;
BUG_ON(cfqg_stats_idling(stats));
stats->start_idle_time = sched_clock();
cfqg_stats_mark_idling(stats);
}
static void cfqg_stats_update_avg_queue_size(struct cfq_group *cfqg)
{
struct cfqg_stats *stats = &cfqg->stats;
blkg_stat_add(&stats->avg_queue_size_sum,
blkg_rwstat_total(&stats->queued));
blkg_stat_add(&stats->avg_queue_size_samples, 1);
cfqg_stats_update_group_wait_time(stats);
}
static inline void cfqg_stats_set_start_group_wait_time(struct cfq_group *cfqg, struct cfq_group *curr_cfqg) { }
static inline void cfqg_stats_end_empty_time(struct cfqg_stats *stats) { }
static inline void cfqg_stats_update_dequeue(struct cfq_group *cfqg) { }
static inline void cfqg_stats_set_start_empty_time(struct cfq_group *cfqg) { }
static inline void cfqg_stats_update_idle_time(struct cfq_group *cfqg) { }
static inline void cfqg_stats_set_start_idle_time(struct cfq_group *cfqg) { }
static inline void cfqg_stats_update_avg_queue_size(struct cfq_group *cfqg) { }
static inline struct cfq_group *pd_to_cfqg(struct blkg_policy_data *pd)
{
return pd ? container_of(pd, struct cfq_group, pd) : NULL;
}
static struct cfq_group_data
*cpd_to_cfqgd(struct blkcg_policy_data *cpd)
{
return cpd ? container_of(cpd, struct cfq_group_data, cpd) : NULL;
}
static inline struct blkcg_gq *cfqg_to_blkg(struct cfq_group *cfqg)
{
return pd_to_blkg(&cfqg->pd);
}
static inline struct cfq_group *blkg_to_cfqg(struct blkcg_gq *blkg)
{
return pd_to_cfqg(blkg_to_pd(blkg, &blkcg_policy_cfq));
}
static struct cfq_group_data *blkcg_to_cfqgd(struct blkcg *blkcg)
{
return cpd_to_cfqgd(blkcg_to_cpd(blkcg, &blkcg_policy_cfq));
}
static inline struct cfq_group *cfqg_parent(struct cfq_group *cfqg)
{
struct blkcg_gq *pblkg = cfqg_to_blkg(cfqg)->parent;
return pblkg ? blkg_to_cfqg(pblkg) : NULL;
}
static inline bool cfqg_is_descendant(struct cfq_group *cfqg,
struct cfq_group *ancestor)
{
return cgroup_is_descendant(cfqg_to_blkg(cfqg)->blkcg->css.cgroup,
cfqg_to_blkg(ancestor)->blkcg->css.cgroup);
}
static inline void cfqg_get(struct cfq_group *cfqg)
{
return blkg_get(cfqg_to_blkg(cfqg));
}
static inline void cfqg_put(struct cfq_group *cfqg)
{
return blkg_put(cfqg_to_blkg(cfqg));
}
static inline void cfqg_stats_update_io_add(struct cfq_group *cfqg,
struct cfq_group *curr_cfqg,
unsigned int op)
{
blkg_rwstat_add(&cfqg->stats.queued, op, 1);
cfqg_stats_end_empty_time(&cfqg->stats);
cfqg_stats_set_start_group_wait_time(cfqg, curr_cfqg);
}
static inline void cfqg_stats_update_timeslice_used(struct cfq_group *cfqg,
uint64_t time, unsigned long unaccounted_time)
{
blkg_stat_add(&cfqg->stats.time, time);
#ifdef CONFIG_DEBUG_BLK_CGROUP
blkg_stat_add(&cfqg->stats.unaccounted_time, unaccounted_time);
#endif
}
static inline void cfqg_stats_update_io_remove(struct cfq_group *cfqg,
unsigned int op)
{
blkg_rwstat_add(&cfqg->stats.queued, op, -1);
}
static inline void cfqg_stats_update_io_merged(struct cfq_group *cfqg,
unsigned int op)
{
blkg_rwstat_add(&cfqg->stats.merged, op, 1);
}
static inline void cfqg_stats_update_completion(struct cfq_group *cfqg,
uint64_t start_time, uint64_t io_start_time,
unsigned int op)
{
struct cfqg_stats *stats = &cfqg->stats;
unsigned long long now = sched_clock();
if (time_after64(now, io_start_time))
blkg_rwstat_add(&stats->service_time, op, now - io_start_time);
if (time_after64(io_start_time, start_time))
blkg_rwstat_add(&stats->wait_time, op,
io_start_time - start_time);
}
static void cfqg_stats_reset(struct cfqg_stats *stats)
{
blkg_rwstat_reset(&stats->merged);
blkg_rwstat_reset(&stats->service_time);
blkg_rwstat_reset(&stats->wait_time);
blkg_stat_reset(&stats->time);
#ifdef CONFIG_DEBUG_BLK_CGROUP
blkg_stat_reset(&stats->unaccounted_time);
blkg_stat_reset(&stats->avg_queue_size_sum);
blkg_stat_reset(&stats->avg_queue_size_samples);
blkg_stat_reset(&stats->dequeue);
blkg_stat_reset(&stats->group_wait_time);
blkg_stat_reset(&stats->idle_time);
blkg_stat_reset(&stats->empty_time);
#endif
}
static void cfqg_stats_add_aux(struct cfqg_stats *to, struct cfqg_stats *from)
{
blkg_rwstat_add_aux(&to->merged, &from->merged);
blkg_rwstat_add_aux(&to->service_time, &from->service_time);
blkg_rwstat_add_aux(&to->wait_time, &from->wait_time);
blkg_stat_add_aux(&from->time, &from->time);
#ifdef CONFIG_DEBUG_BLK_CGROUP
blkg_stat_add_aux(&to->unaccounted_time, &from->unaccounted_time);
blkg_stat_add_aux(&to->avg_queue_size_sum, &from->avg_queue_size_sum);
blkg_stat_add_aux(&to->avg_queue_size_samples, &from->avg_queue_size_samples);
blkg_stat_add_aux(&to->dequeue, &from->dequeue);
blkg_stat_add_aux(&to->group_wait_time, &from->group_wait_time);
blkg_stat_add_aux(&to->idle_time, &from->idle_time);
blkg_stat_add_aux(&to->empty_time, &from->empty_time);
#endif
}
static void cfqg_stats_xfer_dead(struct cfq_group *cfqg)
{
struct cfq_group *parent = cfqg_parent(cfqg);
lockdep_assert_held(cfqg_to_blkg(cfqg)->q->queue_lock);
if (unlikely(!parent))
return;
cfqg_stats_add_aux(&parent->stats, &cfqg->stats);
cfqg_stats_reset(&cfqg->stats);
}
static inline struct cfq_group *cfqg_parent(struct cfq_group *cfqg) { return NULL; }
static inline bool cfqg_is_descendant(struct cfq_group *cfqg,
struct cfq_group *ancestor)
{
return true;
}
static inline void cfqg_get(struct cfq_group *cfqg) { }
static inline void cfqg_put(struct cfq_group *cfqg) { }
static inline void cfqg_stats_update_io_add(struct cfq_group *cfqg,
struct cfq_group *curr_cfqg, unsigned int op) { }
static inline void cfqg_stats_update_timeslice_used(struct cfq_group *cfqg,
uint64_t time, unsigned long unaccounted_time) { }
static inline void cfqg_stats_update_io_remove(struct cfq_group *cfqg,
unsigned int op) { }
static inline void cfqg_stats_update_io_merged(struct cfq_group *cfqg,
unsigned int op) { }
static inline void cfqg_stats_update_completion(struct cfq_group *cfqg,
uint64_t start_time, uint64_t io_start_time,
unsigned int op) { }
static inline bool iops_mode(struct cfq_data *cfqd)
{
if (!cfqd->cfq_slice_idle && cfqd->hw_tag)
return true;
else
return false;
}
static inline enum wl_class_t cfqq_class(struct cfq_queue *cfqq)
{
if (cfq_class_idle(cfqq))
return IDLE_WORKLOAD;
if (cfq_class_rt(cfqq))
return RT_WORKLOAD;
return BE_WORKLOAD;
}
static enum wl_type_t cfqq_type(struct cfq_queue *cfqq)
{
if (!cfq_cfqq_sync(cfqq))
return ASYNC_WORKLOAD;
if (!cfq_cfqq_idle_window(cfqq))
return SYNC_NOIDLE_WORKLOAD;
return SYNC_WORKLOAD;
}
static inline int cfq_group_busy_queues_wl(enum wl_class_t wl_class,
struct cfq_data *cfqd,
struct cfq_group *cfqg)
{
if (wl_class == IDLE_WORKLOAD)
return cfqg->service_tree_idle.count;
return cfqg->service_trees[wl_class][ASYNC_WORKLOAD].count +
cfqg->service_trees[wl_class][SYNC_NOIDLE_WORKLOAD].count +
cfqg->service_trees[wl_class][SYNC_WORKLOAD].count;
}
static inline int cfqg_busy_async_queues(struct cfq_data *cfqd,
struct cfq_group *cfqg)
{
return cfqg->service_trees[RT_WORKLOAD][ASYNC_WORKLOAD].count +
cfqg->service_trees[BE_WORKLOAD][ASYNC_WORKLOAD].count;
}
static inline struct cfq_io_cq *icq_to_cic(struct io_cq *icq)
{
return container_of(icq, struct cfq_io_cq, icq);
}
static inline struct cfq_io_cq *cfq_cic_lookup(struct cfq_data *cfqd,
struct io_context *ioc)
{
if (ioc)
return icq_to_cic(ioc_lookup_icq(ioc, cfqd->queue));
return NULL;
}
static inline struct cfq_queue *cic_to_cfqq(struct cfq_io_cq *cic, bool is_sync)
{
return cic->cfqq[is_sync];
}
static inline void cic_set_cfqq(struct cfq_io_cq *cic, struct cfq_queue *cfqq,
bool is_sync)
{
cic->cfqq[is_sync] = cfqq;
}
static inline struct cfq_data *cic_to_cfqd(struct cfq_io_cq *cic)
{
return cic->icq.q->elevator->elevator_data;
}
static inline void cfq_schedule_dispatch(struct cfq_data *cfqd)
{
if (cfqd->busy_queues) {
cfq_log(cfqd, "schedule dispatch");
kblockd_schedule_work(&cfqd->unplug_work);
}
}
static inline u64 cfq_prio_slice(struct cfq_data *cfqd, bool sync,
unsigned short prio)
{
u64 base_slice = cfqd->cfq_slice[sync];
u64 slice = div_u64(base_slice, CFQ_SLICE_SCALE);
WARN_ON(prio >= IOPRIO_BE_NR);
return base_slice + (slice * (4 - prio));
}
static inline u64
cfq_prio_to_slice(struct cfq_data *cfqd, struct cfq_queue *cfqq)
{
return cfq_prio_slice(cfqd, cfq_cfqq_sync(cfqq), cfqq->ioprio);
}
static inline u64 cfqg_scale_charge(u64 charge,
unsigned int vfraction)
{
u64 c = charge << CFQ_SERVICE_SHIFT;
c <<= CFQ_SERVICE_SHIFT;
return div_u64(c, vfraction);
}
static inline u64 max_vdisktime(u64 min_vdisktime, u64 vdisktime)
{
s64 delta = (s64)(vdisktime - min_vdisktime);
if (delta > 0)
min_vdisktime = vdisktime;
return min_vdisktime;
}
static void update_min_vdisktime(struct cfq_rb_root *st)
{
if (!RB_EMPTY_ROOT(&st->rb.rb_root)) {
struct cfq_group *cfqg = rb_entry_cfqg(st->rb.rb_leftmost);
st->min_vdisktime = max_vdisktime(st->min_vdisktime,
cfqg->vdisktime);
}
}
static inline unsigned cfq_group_get_avg_queues(struct cfq_data *cfqd,
struct cfq_group *cfqg, bool rt)
{
unsigned min_q, max_q;
unsigned mult = cfq_hist_divisor - 1;
unsigned round = cfq_hist_divisor / 2;
unsigned busy = cfq_group_busy_queues_wl(rt, cfqd, cfqg);
min_q = min(cfqg->busy_queues_avg[rt], busy);
max_q = max(cfqg->busy_queues_avg[rt], busy);
cfqg->busy_queues_avg[rt] = (mult * max_q + min_q + round) /
cfq_hist_divisor;
return cfqg->busy_queues_avg[rt];
}
static inline u64
cfq_group_slice(struct cfq_data *cfqd, struct cfq_group *cfqg)
{
return cfqd->cfq_target_latency * cfqg->vfraction >> CFQ_SERVICE_SHIFT;
}
static inline u64
cfq_scaled_cfqq_slice(struct cfq_data *cfqd, struct cfq_queue *cfqq)
{
u64 slice = cfq_prio_to_slice(cfqd, cfqq);
if (cfqd->cfq_latency) {
unsigned iq = cfq_group_get_avg_queues(cfqd, cfqq->cfqg,
cfq_class_rt(cfqq));
u64 sync_slice = cfqd->cfq_slice[1];
u64 expect_latency = sync_slice * iq;
u64 group_slice = cfq_group_slice(cfqd, cfqq->cfqg);
if (expect_latency > group_slice) {
u64 base_low_slice = 2 * cfqd->cfq_slice_idle;
u64 low_slice;
low_slice = div64_u64(base_low_slice*slice, sync_slice);
low_slice = min(slice, low_slice);
slice = div64_u64(slice*group_slice, expect_latency);
slice = max(slice, low_slice);
}
}
return slice;
}
static inline void
cfq_set_prio_slice(struct cfq_data *cfqd, struct cfq_queue *cfqq)
{
u64 slice = cfq_scaled_cfqq_slice(cfqd, cfqq);
u64 now = ktime_get_ns();
cfqq->slice_start = now;
cfqq->slice_end = now + slice;
cfqq->allocated_slice = slice;
cfq_log_cfqq(cfqd, cfqq, "set_slice=%llu", cfqq->slice_end - now);
}
static inline bool cfq_slice_used(struct cfq_queue *cfqq)
{
if (cfq_cfqq_slice_new(cfqq))
return false;
if (ktime_get_ns() < cfqq->slice_end)
return false;
return true;
}
static struct request *
cfq_choose_req(struct cfq_data *cfqd, struct request *rq1, struct request *rq2, sector_t last)
{
sector_t s1, s2, d1 = 0, d2 = 0;
unsigned long back_max;
#define CFQ_RQ1_WRAP 0x01
#define CFQ_RQ2_WRAP 0x02
unsigned wrap = 0;
if (rq1 == NULL || rq1 == rq2)
return rq2;
if (rq2 == NULL)
return rq1;
if (rq_is_sync(rq1) != rq_is_sync(rq2))
return rq_is_sync(rq1) ? rq1 : rq2;
if ((rq1->cmd_flags ^ rq2->cmd_flags) & REQ_PRIO)
return rq1->cmd_flags & REQ_PRIO ? rq1 : rq2;
s1 = blk_rq_pos(rq1);
s2 = blk_rq_pos(rq2);
back_max = cfqd->cfq_back_max * 2;
if (s1 >= last)
d1 = s1 - last;
else if (s1 + back_max >= last)
d1 = (last - s1) * cfqd->cfq_back_penalty;
else
wrap |= CFQ_RQ1_WRAP;
if (s2 >= last)
d2 = s2 - last;
else if (s2 + back_max >= last)
d2 = (last - s2) * cfqd->cfq_back_penalty;
else
wrap |= CFQ_RQ2_WRAP;
switch (wrap) {
case 0:
if (d1 < d2)
return rq1;
else if (d2 < d1)
return rq2;
else {
if (s1 >= s2)
return rq1;
else
return rq2;
}
case CFQ_RQ2_WRAP:
return rq1;
case CFQ_RQ1_WRAP:
return rq2;
case (CFQ_RQ1_WRAP|CFQ_RQ2_WRAP):
default:
if (s1 <= s2)
return rq1;
else
return rq2;
}
}
static struct cfq_queue *cfq_rb_first(struct cfq_rb_root *root)
{
if (!root->count)
return NULL;
return rb_entry(rb_first_cached(&root->rb), struct cfq_queue, rb_node);
}
static struct cfq_group *cfq_rb_first_group(struct cfq_rb_root *root)
{
return rb_entry_cfqg(rb_first_cached(&root->rb));
}
static void cfq_rb_erase(struct rb_node *n, struct cfq_rb_root *root)
{
if (root->rb_rightmost == n)
root->rb_rightmost = rb_prev(n);
rb_erase_cached(n, &root->rb);
RB_CLEAR_NODE(n);
--root->count;
}
static struct request *
cfq_find_next_rq(struct cfq_data *cfqd, struct cfq_queue *cfqq,
struct request *last)
{
struct rb_node *rbnext = rb_next(&last->rb_node);
struct rb_node *rbprev = rb_prev(&last->rb_node);
struct request *next = NULL, *prev = NULL;
BUG_ON(RB_EMPTY_NODE(&last->rb_node));
if (rbprev)
prev = rb_entry_rq(rbprev);
if (rbnext)
next = rb_entry_rq(rbnext);
else {
rbnext = rb_first(&cfqq->sort_list);
if (rbnext && rbnext != &last->rb_node)
next = rb_entry_rq(rbnext);
}
return cfq_choose_req(cfqd, next, prev, blk_rq_pos(last));
}
static u64 cfq_slice_offset(struct cfq_data *cfqd,
struct cfq_queue *cfqq)
{
return (cfqq->cfqg->nr_cfqq - 1) * (cfq_prio_slice(cfqd, 1, 0) -
cfq_prio_slice(cfqd, cfq_cfqq_sync(cfqq), cfqq->ioprio));
}
static inline s64
cfqg_key(struct cfq_rb_root *st, struct cfq_group *cfqg)
{
return cfqg->vdisktime - st->min_vdisktime;
}
static void
__cfq_group_service_tree_add(struct cfq_rb_root *st, struct cfq_group *cfqg)
{
struct rb_node **node = &st->rb.rb_root.rb_node;
struct rb_node *parent = NULL;
struct cfq_group *__cfqg;
s64 key = cfqg_key(st, cfqg);
bool leftmost = true, rightmost = true;
while (*node != NULL) {
parent = *node;
__cfqg = rb_entry_cfqg(parent);
if (key < cfqg_key(st, __cfqg)) {
node = &parent->rb_left;
rightmost = false;
} else {
node = &parent->rb_right;
leftmost = false;
}
}
if (rightmost)
st->rb_rightmost = &cfqg->rb_node;
rb_link_node(&cfqg->rb_node, parent, node);
rb_insert_color_cached(&cfqg->rb_node, &st->rb, leftmost);
}
static void
cfq_update_group_weight(struct cfq_group *cfqg)
{
if (cfqg->new_weight) {
cfqg->weight = cfqg->new_weight;
cfqg->new_weight = 0;
}
}
static void
cfq_update_group_leaf_weight(struct cfq_group *cfqg)
{
BUG_ON(!RB_EMPTY_NODE(&cfqg->rb_node));
if (cfqg->new_leaf_weight) {
cfqg->leaf_weight = cfqg->new_leaf_weight;
cfqg->new_leaf_weight = 0;
}
}
static void
cfq_group_service_tree_add(struct cfq_rb_root *st, struct cfq_group *cfqg)
{
unsigned int vfr = 1 << CFQ_SERVICE_SHIFT;
struct cfq_group *pos = cfqg;
struct cfq_group *parent;
bool propagate;
BUG_ON(!RB_EMPTY_NODE(&cfqg->rb_node));
cfq_update_group_leaf_weight(cfqg);
__cfq_group_service_tree_add(st, cfqg);
propagate = !pos->nr_active++;
pos->children_weight += pos->leaf_weight;
vfr = vfr * pos->leaf_weight / pos->children_weight;
while ((parent = cfqg_parent(pos))) {
if (propagate) {
cfq_update_group_weight(pos);
propagate = !parent->nr_active++;
parent->children_weight += pos->weight;
}
vfr = vfr * pos->weight / parent->children_weight;
pos = parent;
}
cfqg->vfraction = max_t(unsigned, vfr, 1);
}
static inline u64 cfq_get_cfqg_vdisktime_delay(struct cfq_data *cfqd)
{
if (!iops_mode(cfqd))
return CFQ_SLICE_MODE_GROUP_DELAY;
else
return CFQ_IOPS_MODE_GROUP_DELAY;
}
static void
cfq_group_notify_queue_add(struct cfq_data *cfqd, struct cfq_group *cfqg)
{
struct cfq_rb_root *st = &cfqd->grp_service_tree;
struct cfq_group *__cfqg;
struct rb_node *n;
cfqg->nr_cfqq++;
if (!RB_EMPTY_NODE(&cfqg->rb_node))
return;
n = st->rb_rightmost;
if (n) {
__cfqg = rb_entry_cfqg(n);
cfqg->vdisktime = __cfqg->vdisktime +
cfq_get_cfqg_vdisktime_delay(cfqd);
} else
cfqg->vdisktime = st->min_vdisktime;
cfq_group_service_tree_add(st, cfqg);
}
static void
cfq_group_service_tree_del(struct cfq_rb_root *st, struct cfq_group *cfqg)
{
struct cfq_group *pos = cfqg;
bool propagate;
propagate = !--pos->nr_active;
pos->children_weight -= pos->leaf_weight;
while (propagate) {
struct cfq_group *parent = cfqg_parent(pos);
WARN_ON_ONCE(pos->children_weight);
pos->vfraction = 0;
if (!parent)
break;
propagate = !--parent->nr_active;
parent->children_weight -= pos->weight;
pos = parent;
}
if (!RB_EMPTY_NODE(&cfqg->rb_node))
cfq_rb_erase(&cfqg->rb_node, st);
}
static void
cfq_group_notify_queue_del(struct cfq_data *cfqd, struct cfq_group *cfqg)
{
struct cfq_rb_root *st = &cfqd->grp_service_tree;
BUG_ON(cfqg->nr_cfqq < 1);
cfqg->nr_cfqq--;
if (cfqg->nr_cfqq)
return;
cfq_log_cfqg(cfqd, cfqg, "del_from_rr group");
cfq_group_service_tree_del(st, cfqg);
cfqg->saved_wl_slice = 0;
cfqg_stats_update_dequeue(cfqg);
}
static inline u64 cfq_cfqq_slice_usage(struct cfq_queue *cfqq,
u64 *unaccounted_time)
{
u64 slice_used;
u64 now = ktime_get_ns();
if (!cfqq->slice_start || cfqq->slice_start == now) {
slice_used = max_t(u64, (now - cfqq->dispatch_start),
jiffies_to_nsecs(1));
} else {
slice_used = now - cfqq->slice_start;
if (slice_used > cfqq->allocated_slice) {
*unaccounted_time = slice_used - cfqq->allocated_slice;
slice_used = cfqq->allocated_slice;
}
if (cfqq->slice_start > cfqq->dispatch_start)
*unaccounted_time += cfqq->slice_start -
cfqq->dispatch_start;
}
return slice_used;
}
static void cfq_group_served(struct cfq_data *cfqd, struct cfq_group *cfqg,
struct cfq_queue *cfqq)
{
struct cfq_rb_root *st = &cfqd->grp_service_tree;
u64 used_sl, charge, unaccounted_sl = 0;
int nr_sync = cfqg->nr_cfqq - cfqg_busy_async_queues(cfqd, cfqg)
- cfqg->service_tree_idle.count;
unsigned int vfr;
u64 now = ktime_get_ns();
BUG_ON(nr_sync < 0);
used_sl = charge = cfq_cfqq_slice_usage(cfqq, &unaccounted_sl);
if (iops_mode(cfqd))
charge = cfqq->slice_dispatch;
else if (!cfq_cfqq_sync(cfqq) && !nr_sync)
charge = cfqq->allocated_slice;
vfr = cfqg->vfraction;
cfq_group_service_tree_del(st, cfqg);
cfqg->vdisktime += cfqg_scale_charge(charge, vfr);
cfq_group_service_tree_add(st, cfqg);
if (cfqd->workload_expires > now) {
cfqg->saved_wl_slice = cfqd->workload_expires - now;
cfqg->saved_wl_type = cfqd->serving_wl_type;
cfqg->saved_wl_class = cfqd->serving_wl_class;
} else
cfqg->saved_wl_slice = 0;
cfq_log_cfqg(cfqd, cfqg, "served: vt=%llu min_vt=%llu", cfqg->vdisktime,
st->min_vdisktime);
cfq_log_cfqq(cfqq->cfqd, cfqq,
"sl_used=%llu disp=%llu charge=%llu iops=%u sect=%lu",
used_sl, cfqq->slice_dispatch, charge,
iops_mode(cfqd), cfqq->nr_sectors);
cfqg_stats_update_timeslice_used(cfqg, used_sl, unaccounted_sl);
cfqg_stats_set_start_empty_time(cfqg);
}
static void cfq_init_cfqg_base(struct cfq_group *cfqg)
{
struct cfq_rb_root *st;
int i, j;
for_each_cfqg_st(cfqg, i, j, st)
*st = CFQ_RB_ROOT;
RB_CLEAR_NODE(&cfqg->rb_node);
cfqg->ttime.last_end_request = ktime_get_ns();
}
static void cfqg_stats_exit(struct cfqg_stats *stats)
{
blkg_rwstat_exit(&stats->merged);
blkg_rwstat_exit(&stats->service_time);
blkg_rwstat_exit(&stats->wait_time);
blkg_rwstat_exit(&stats->queued);
blkg_stat_exit(&stats->time);
#ifdef CONFIG_DEBUG_BLK_CGROUP
blkg_stat_exit(&stats->unaccounted_time);
blkg_stat_exit(&stats->avg_queue_size_sum);
blkg_stat_exit(&stats->avg_queue_size_samples);
blkg_stat_exit(&stats->dequeue);
blkg_stat_exit(&stats->group_wait_time);
blkg_stat_exit(&stats->idle_time);
blkg_stat_exit(&stats->empty_time);
#endif
}
static int cfqg_stats_init(struct cfqg_stats *stats, gfp_t gfp)
{
if (blkg_rwstat_init(&stats->merged, gfp) ||
blkg_rwstat_init(&stats->service_time, gfp) ||
blkg_rwstat_init(&stats->wait_time, gfp) ||
blkg_rwstat_init(&stats->queued, gfp) ||
blkg_stat_init(&stats->time, gfp))
goto err;
#ifdef CONFIG_DEBUG_BLK_CGROUP
if (blkg_stat_init(&stats->unaccounted_time, gfp) ||
blkg_stat_init(&stats->avg_queue_size_sum, gfp) ||
blkg_stat_init(&stats->avg_queue_size_samples, gfp) ||
blkg_stat_init(&stats->dequeue, gfp) ||
blkg_stat_init(&stats->group_wait_time, gfp) ||
blkg_stat_init(&stats->idle_time, gfp) ||
blkg_stat_init(&stats->empty_time, gfp))
goto err;
#endif
return 0;
err:
cfqg_stats_exit(stats);
return -ENOMEM;
}
static struct blkcg_policy_data *cfq_cpd_alloc(gfp_t gfp)
{
struct cfq_group_data *cgd;
cgd = kzalloc(sizeof(*cgd), gfp);
if (!cgd)
return NULL;
return &cgd->cpd;
}
static void cfq_cpd_init(struct blkcg_policy_data *cpd)
{
struct cfq_group_data *cgd = cpd_to_cfqgd(cpd);
unsigned int weight = cgroup_subsys_on_dfl(io_cgrp_subsys) ?
CGROUP_WEIGHT_DFL : CFQ_WEIGHT_LEGACY_DFL;
if (cpd_to_blkcg(cpd) == &blkcg_root)
weight *= 2;
cgd->weight = weight;
cgd->leaf_weight = weight;
}
static void cfq_cpd_free(struct blkcg_policy_data *cpd)
{
kfree(cpd_to_cfqgd(cpd));
}
static void cfq_cpd_bind(struct blkcg_policy_data *cpd)
{
struct blkcg *blkcg = cpd_to_blkcg(cpd);
bool on_dfl = cgroup_subsys_on_dfl(io_cgrp_subsys);
unsigned int weight = on_dfl ? CGROUP_WEIGHT_DFL : CFQ_WEIGHT_LEGACY_DFL;
if (blkcg == &blkcg_root)
weight *= 2;
WARN_ON_ONCE(__cfq_set_weight(&blkcg->css, weight, on_dfl, true, false));
WARN_ON_ONCE(__cfq_set_weight(&blkcg->css, weight, on_dfl, true, true));
}
static struct blkg_policy_data *cfq_pd_alloc(gfp_t gfp, int node)
{
struct cfq_group *cfqg;
cfqg = kzalloc_node(sizeof(*cfqg), gfp, node);
if (!cfqg)
return NULL;
cfq_init_cfqg_base(cfqg);
if (cfqg_stats_init(&cfqg->stats, gfp)) {
kfree(cfqg);
return NULL;
}
return &cfqg->pd;
}
static void cfq_pd_init(struct blkg_policy_data *pd)
{
struct cfq_group *cfqg = pd_to_cfqg(pd);
struct cfq_group_data *cgd = blkcg_to_cfqgd(pd->blkg->blkcg);
cfqg->weight = cgd->weight;
cfqg->leaf_weight = cgd->leaf_weight;
}
static void cfq_pd_offline(struct blkg_policy_data *pd)
{
struct cfq_group *cfqg = pd_to_cfqg(pd);
int i;
for (i = 0; i < IOPRIO_BE_NR; i++) {
if (cfqg->async_cfqq[0][i])
cfq_put_queue(cfqg->async_cfqq[0][i]);
if (cfqg->async_cfqq[1][i])
cfq_put_queue(cfqg->async_cfqq[1][i]);
}
if (cfqg->async_idle_cfqq)
cfq_put_queue(cfqg->async_idle_cfqq);
cfqg_stats_xfer_dead(cfqg);
}
static void cfq_pd_free(struct blkg_policy_data *pd)
{
struct cfq_group *cfqg = pd_to_cfqg(pd);
cfqg_stats_exit(&cfqg->stats);
return kfree(cfqg);
}
static void cfq_pd_reset_stats(struct blkg_policy_data *pd)
{
struct cfq_group *cfqg = pd_to_cfqg(pd);
cfqg_stats_reset(&cfqg->stats);
}
static struct cfq_group *cfq_lookup_cfqg(struct cfq_data *cfqd,
struct blkcg *blkcg)
{
struct blkcg_gq *blkg;
blkg = blkg_lookup(blkcg, cfqd->queue);
if (likely(blkg))
return blkg_to_cfqg(blkg);
return NULL;
}
static void cfq_link_cfqq_cfqg(struct cfq_queue *cfqq, struct cfq_group *cfqg)
{
cfqq->cfqg = cfqg;
cfqg_get(cfqg);
}
static u64 cfqg_prfill_weight_device(struct seq_file *sf,
struct blkg_policy_data *pd, int off)
{
struct cfq_group *cfqg = pd_to_cfqg(pd);
if (!cfqg->dev_weight)
return 0;
return __blkg_prfill_u64(sf, pd, cfqg->dev_weight);
}
static int cfqg_print_weight_device(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)),
cfqg_prfill_weight_device, &blkcg_policy_cfq,
0, false);
return 0;
}
static u64 cfqg_prfill_leaf_weight_device(struct seq_file *sf,
struct blkg_policy_data *pd, int off)
{
struct cfq_group *cfqg = pd_to_cfqg(pd);
if (!cfqg->dev_leaf_weight)
return 0;
return __blkg_prfill_u64(sf, pd, cfqg->dev_leaf_weight);
}
static int cfqg_print_leaf_weight_device(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)),
cfqg_prfill_leaf_weight_device, &blkcg_policy_cfq,
0, false);
return 0;
}
static int cfq_print_weight(struct seq_file *sf, void *v)
{
struct blkcg *blkcg = css_to_blkcg(seq_css(sf));
struct cfq_group_data *cgd = blkcg_to_cfqgd(blkcg);
unsigned int val = 0;
if (cgd)
val = cgd->weight;
seq_printf(sf, "%u\n", val);
return 0;
}
static int cfq_print_leaf_weight(struct seq_file *sf, void *v)
{
struct blkcg *blkcg = css_to_blkcg(seq_css(sf));
struct cfq_group_data *cgd = blkcg_to_cfqgd(blkcg);
unsigned int val = 0;
if (cgd)
val = cgd->leaf_weight;
seq_printf(sf, "%u\n", val);
return 0;
}
static ssize_t __cfqg_set_weight_device(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off,
bool on_dfl, bool is_leaf_weight)
{
unsigned int min = on_dfl ? CGROUP_WEIGHT_MIN : CFQ_WEIGHT_LEGACY_MIN;
unsigned int max = on_dfl ? CGROUP_WEIGHT_MAX : CFQ_WEIGHT_LEGACY_MAX;
struct blkcg *blkcg = css_to_blkcg(of_css(of));
struct blkg_conf_ctx ctx;
struct cfq_group *cfqg;
struct cfq_group_data *cfqgd;
int ret;
u64 v;
ret = blkg_conf_prep(blkcg, &blkcg_policy_cfq, buf, &ctx);
if (ret)
return ret;
if (sscanf(ctx.body, "%llu", &v) == 1) {
ret = -ERANGE;
if (!v && on_dfl)
goto out_finish;
} else if (!strcmp(strim(ctx.body), "default")) {
v = 0;
} else {
ret = -EINVAL;
goto out_finish;
}
cfqg = blkg_to_cfqg(ctx.blkg);
cfqgd = blkcg_to_cfqgd(blkcg);
ret = -ERANGE;
if (!v || (v >= min && v <= max)) {
if (!is_leaf_weight) {
cfqg->dev_weight = v;
cfqg->new_weight = v ?: cfqgd->weight;
} else {
cfqg->dev_leaf_weight = v;
cfqg->new_leaf_weight = v ?: cfqgd->leaf_weight;
}
ret = 0;
}
out_finish:
blkg_conf_finish(&ctx);
return ret ?: nbytes;
}
static ssize_t cfqg_set_weight_device(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
return __cfqg_set_weight_device(of, buf, nbytes, off, false, false);
}
static ssize_t cfqg_set_leaf_weight_device(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
return __cfqg_set_weight_device(of, buf, nbytes, off, false, true);
}
static int __cfq_set_weight(struct cgroup_subsys_state *css, u64 val,
bool on_dfl, bool reset_dev, bool is_leaf_weight)
{
unsigned int min = on_dfl ? CGROUP_WEIGHT_MIN : CFQ_WEIGHT_LEGACY_MIN;
unsigned int max = on_dfl ? CGROUP_WEIGHT_MAX : CFQ_WEIGHT_LEGACY_MAX;
struct blkcg *blkcg = css_to_blkcg(css);
struct blkcg_gq *blkg;
struct cfq_group_data *cfqgd;
int ret = 0;
if (val < min || val > max)
return -ERANGE;
spin_lock_irq(&blkcg->lock);
cfqgd = blkcg_to_cfqgd(blkcg);
if (!cfqgd) {
ret = -EINVAL;
goto out;
}
if (!is_leaf_weight)
cfqgd->weight = val;
else
cfqgd->leaf_weight = val;
hlist_for_each_entry(blkg, &blkcg->blkg_list, blkcg_node) {
struct cfq_group *cfqg = blkg_to_cfqg(blkg);
if (!cfqg)
continue;
if (!is_leaf_weight) {
if (reset_dev)
cfqg->dev_weight = 0;
if (!cfqg->dev_weight)
cfqg->new_weight = cfqgd->weight;
} else {
if (reset_dev)
cfqg->dev_leaf_weight = 0;
if (!cfqg->dev_leaf_weight)
cfqg->new_leaf_weight = cfqgd->leaf_weight;
}
}
out:
spin_unlock_irq(&blkcg->lock);
return ret;
}
static int cfq_set_weight(struct cgroup_subsys_state *css, struct cftype *cft,
u64 val)
{
return __cfq_set_weight(css, val, false, false, false);
}
static int cfq_set_leaf_weight(struct cgroup_subsys_state *css,
struct cftype *cft, u64 val)
{
return __cfq_set_weight(css, val, false, false, true);
}
static int cfqg_print_stat(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)), blkg_prfill_stat,
&blkcg_policy_cfq, seq_cft(sf)->private, false);
return 0;
}
static int cfqg_print_rwstat(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)), blkg_prfill_rwstat,
&blkcg_policy_cfq, seq_cft(sf)->private, true);
return 0;
}
static u64 cfqg_prfill_stat_recursive(struct seq_file *sf,
struct blkg_policy_data *pd, int off)
{
u64 sum = blkg_stat_recursive_sum(pd_to_blkg(pd),
&blkcg_policy_cfq, off);
return __blkg_prfill_u64(sf, pd, sum);
}
static u64 cfqg_prfill_rwstat_recursive(struct seq_file *sf,
struct blkg_policy_data *pd, int off)
{
struct blkg_rwstat sum = blkg_rwstat_recursive_sum(pd_to_blkg(pd),
&blkcg_policy_cfq, off);
return __blkg_prfill_rwstat(sf, pd, &sum);
}
static int cfqg_print_stat_recursive(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)),
cfqg_prfill_stat_recursive, &blkcg_policy_cfq,
seq_cft(sf)->private, false);
return 0;
}
static int cfqg_print_rwstat_recursive(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)),
cfqg_prfill_rwstat_recursive, &blkcg_policy_cfq,
seq_cft(sf)->private, true);
return 0;
}
static u64 cfqg_prfill_sectors(struct seq_file *sf, struct blkg_policy_data *pd,
int off)
{
u64 sum = blkg_rwstat_total(&pd->blkg->stat_bytes);
return __blkg_prfill_u64(sf, pd, sum >> 9);
}
static int cfqg_print_stat_sectors(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)),
cfqg_prfill_sectors, &blkcg_policy_cfq, 0, false);
return 0;
}
static u64 cfqg_prfill_sectors_recursive(struct seq_file *sf,
struct blkg_policy_data *pd, int off)
{
struct blkg_rwstat tmp = blkg_rwstat_recursive_sum(pd->blkg, NULL,
offsetof(struct blkcg_gq, stat_bytes));
u64 sum = atomic64_read(&tmp.aux_cnt[BLKG_RWSTAT_READ]) +
atomic64_read(&tmp.aux_cnt[BLKG_RWSTAT_WRITE]);
return __blkg_prfill_u64(sf, pd, sum >> 9);
}
static int cfqg_print_stat_sectors_recursive(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)),
cfqg_prfill_sectors_recursive, &blkcg_policy_cfq, 0,
false);
return 0;
}
static u64 cfqg_prfill_avg_queue_size(struct seq_file *sf,
struct blkg_policy_data *pd, int off)
{
struct cfq_group *cfqg = pd_to_cfqg(pd);
u64 samples = blkg_stat_read(&cfqg->stats.avg_queue_size_samples);
u64 v = 0;
if (samples) {
v = blkg_stat_read(&cfqg->stats.avg_queue_size_sum);
v = div64_u64(v, samples);
}
__blkg_prfill_u64(sf, pd, v);
return 0;
}
static int cfqg_print_avg_queue_size(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)),
cfqg_prfill_avg_queue_size, &blkcg_policy_cfq,
0, false);
return 0;
}
static int cfq_print_weight_on_dfl(struct seq_file *sf, void *v)
{
struct blkcg *blkcg = css_to_blkcg(seq_css(sf));
struct cfq_group_data *cgd = blkcg_to_cfqgd(blkcg);
seq_printf(sf, "default %u\n", cgd->weight);
blkcg_print_blkgs(sf, blkcg, cfqg_prfill_weight_device,
&blkcg_policy_cfq, 0, false);
return 0;
}
static ssize_t cfq_set_weight_on_dfl(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
char *endp;
int ret;
u64 v;
buf = strim(buf);
v = simple_strtoull(buf, &endp, 0);
if (*endp == '\0' || sscanf(buf, "default %llu", &v) == 1) {
ret = __cfq_set_weight(of_css(of), v, true, false, false);
return ret ?: nbytes;
}
return __cfqg_set_weight_device(of, buf, nbytes, off, true, false);
}
static struct cfq_group *cfq_lookup_cfqg(struct cfq_data *cfqd,
struct blkcg *blkcg)
{
return cfqd->root_group;
}
static inline void
cfq_link_cfqq_cfqg(struct cfq_queue *cfqq, struct cfq_group *cfqg) {
cfqq->cfqg = cfqg;
}
static void cfq_service_tree_add(struct cfq_data *cfqd, struct cfq_queue *cfqq,
bool add_front)
{
struct rb_node **p, *parent;
struct cfq_queue *__cfqq;
u64 rb_key;
struct cfq_rb_root *st;
bool leftmost = true;
int new_cfqq = 1;
u64 now = ktime_get_ns();
st = st_for(cfqq->cfqg, cfqq_class(cfqq), cfqq_type(cfqq));
if (cfq_class_idle(cfqq)) {
rb_key = CFQ_IDLE_DELAY;
parent = st->rb_rightmost;
if (parent && parent != &cfqq->rb_node) {
__cfqq = rb_entry(parent, struct cfq_queue, rb_node);
rb_key += __cfqq->rb_key;
} else
rb_key += now;
} else if (!add_front) {
rb_key = cfq_slice_offset(cfqd, cfqq) + now;
rb_key -= cfqq->slice_resid;
cfqq->slice_resid = 0;
} else {
rb_key = -NSEC_PER_SEC;
__cfqq = cfq_rb_first(st);
rb_key += __cfqq ? __cfqq->rb_key : now;
}
if (!RB_EMPTY_NODE(&cfqq->rb_node)) {
new_cfqq = 0;
if (rb_key == cfqq->rb_key && cfqq->service_tree == st)
return;
cfq_rb_erase(&cfqq->rb_node, cfqq->service_tree);
cfqq->service_tree = NULL;
}
parent = NULL;
cfqq->service_tree = st;
p = &st->rb.rb_root.rb_node;
while (*p) {
parent = *p;
__cfqq = rb_entry(parent, struct cfq_queue, rb_node);
if (rb_key < __cfqq->rb_key)
p = &parent->rb_left;
else {
p = &parent->rb_right;
leftmost = false;
}
}
cfqq->rb_key = rb_key;
rb_link_node(&cfqq->rb_node, parent, p);
rb_insert_color_cached(&cfqq->rb_node, &st->rb, leftmost);
st->count++;
if (add_front || !new_cfqq)
return;
cfq_group_notify_queue_add(cfqd, cfqq->cfqg);
}
static struct cfq_queue *
cfq_prio_tree_lookup(struct cfq_data *cfqd, struct rb_root *root,
sector_t sector, struct rb_node **ret_parent,
struct rb_node ***rb_link)
{
struct rb_node **p, *parent;
struct cfq_queue *cfqq = NULL;
parent = NULL;
p = &root->rb_node;
while (*p) {
struct rb_node **n;
parent = *p;
cfqq = rb_entry(parent, struct cfq_queue, p_node);
if (sector > blk_rq_pos(cfqq->next_rq))
n = &(*p)->rb_right;
else if (sector < blk_rq_pos(cfqq->next_rq))
n = &(*p)->rb_left;
else
break;
p = n;
cfqq = NULL;
}
*ret_parent = parent;
if (rb_link)
*rb_link = p;
return cfqq;
}
static void cfq_prio_tree_add(struct cfq_data *cfqd, struct cfq_queue *cfqq)
{
struct rb_node **p, *parent;
struct cfq_queue *__cfqq;
if (cfqq->p_root) {
rb_erase(&cfqq->p_node, cfqq->p_root);
cfqq->p_root = NULL;
}
if (cfq_class_idle(cfqq))
return;
if (!cfqq->next_rq)
return;
cfqq->p_root = &cfqd->prio_trees[cfqq->org_ioprio];
__cfqq = cfq_prio_tree_lookup(cfqd, cfqq->p_root,
blk_rq_pos(cfqq->next_rq), &parent, &p);
if (!__cfqq) {
rb_link_node(&cfqq->p_node, parent, p);
rb_insert_color(&cfqq->p_node, cfqq->p_root);
} else
cfqq->p_root = NULL;
}
static void cfq_resort_rr_list(struct cfq_data *cfqd, struct cfq_queue *cfqq)
{
if (cfq_cfqq_on_rr(cfqq)) {
cfq_service_tree_add(cfqd, cfqq, 0);
cfq_prio_tree_add(cfqd, cfqq);
}
}
static void cfq_add_cfqq_rr(struct cfq_data *cfqd, struct cfq_queue *cfqq)
{
cfq_log_cfqq(cfqd, cfqq, "add_to_rr");
BUG_ON(cfq_cfqq_on_rr(cfqq));
cfq_mark_cfqq_on_rr(cfqq);
cfqd->busy_queues++;
if (cfq_cfqq_sync(cfqq))
cfqd->busy_sync_queues++;
cfq_resort_rr_list(cfqd, cfqq);
}
static void cfq_del_cfqq_rr(struct cfq_data *cfqd, struct cfq_queue *cfqq)
{
cfq_log_cfqq(cfqd, cfqq, "del_from_rr");
BUG_ON(!cfq_cfqq_on_rr(cfqq));
cfq_clear_cfqq_on_rr(cfqq);
if (!RB_EMPTY_NODE(&cfqq->rb_node)) {
cfq_rb_erase(&cfqq->rb_node, cfqq->service_tree);
cfqq->service_tree = NULL;
}
if (cfqq->p_root) {
rb_erase(&cfqq->p_node, cfqq->p_root);
cfqq->p_root = NULL;
}
cfq_group_notify_queue_del(cfqd, cfqq->cfqg);
BUG_ON(!cfqd->busy_queues);
cfqd->busy_queues--;
if (cfq_cfqq_sync(cfqq))
cfqd->busy_sync_queues--;
}
static void cfq_del_rq_rb(struct request *rq)
{
struct cfq_queue *cfqq = RQ_CFQQ(rq);
const int sync = rq_is_sync(rq);
BUG_ON(!cfqq->queued[sync]);
cfqq->queued[sync]--;
elv_rb_del(&cfqq->sort_list, rq);
if (cfq_cfqq_on_rr(cfqq) && RB_EMPTY_ROOT(&cfqq->sort_list)) {
if (cfqq->p_root) {
rb_erase(&cfqq->p_node, cfqq->p_root);
cfqq->p_root = NULL;
}
}
}
static void cfq_add_rq_rb(struct request *rq)
{
struct cfq_queue *cfqq = RQ_CFQQ(rq);
struct cfq_data *cfqd = cfqq->cfqd;
struct request *prev;
cfqq->queued[rq_is_sync(rq)]++;
elv_rb_add(&cfqq->sort_list, rq);
if (!cfq_cfqq_on_rr(cfqq))
cfq_add_cfqq_rr(cfqd, cfqq);
prev = cfqq->next_rq;
cfqq->next_rq = cfq_choose_req(cfqd, cfqq->next_rq, rq, cfqd->last_position);
if (prev != cfqq->next_rq)
cfq_prio_tree_add(cfqd, cfqq);
BUG_ON(!cfqq->next_rq);
}
static void cfq_reposition_rq_rb(struct cfq_queue *cfqq, struct request *rq)
{
elv_rb_del(&cfqq->sort_list, rq);
cfqq->queued[rq_is_sync(rq)]--;
cfqg_stats_update_io_remove(RQ_CFQG(rq), rq->cmd_flags);
cfq_add_rq_rb(rq);
cfqg_stats_update_io_add(RQ_CFQG(rq), cfqq->cfqd->serving_group,
rq->cmd_flags);
}
static struct request *
cfq_find_rq_fmerge(struct cfq_data *cfqd, struct bio *bio)
{
struct task_struct *tsk = current;
struct cfq_io_cq *cic;
struct cfq_queue *cfqq;
cic = cfq_cic_lookup(cfqd, tsk->io_context);
if (!cic)
return NULL;
cfqq = cic_to_cfqq(cic, op_is_sync(bio->bi_opf));
if (cfqq)
return elv_rb_find(&cfqq->sort_list, bio_end_sector(bio));
return NULL;
}
static void cfq_activate_request(struct request_queue *q, struct request *rq)
{
struct cfq_data *cfqd = q->elevator->elevator_data;
cfqd->rq_in_driver++;
cfq_log_cfqq(cfqd, RQ_CFQQ(rq), "activate rq, drv=%d",
cfqd->rq_in_driver);
cfqd->last_position = blk_rq_pos(rq) + blk_rq_sectors(rq);
}
static void cfq_deactivate_request(struct request_queue *q, struct request *rq)
{
struct cfq_data *cfqd = q->elevator->elevator_data;
WARN_ON(!cfqd->rq_in_driver);
cfqd->rq_in_driver--;
cfq_log_cfqq(cfqd, RQ_CFQQ(rq), "deactivate rq, drv=%d",
cfqd->rq_in_driver);
}
static void cfq_remove_request(struct request *rq)
{
struct cfq_queue *cfqq = RQ_CFQQ(rq);
if (cfqq->next_rq == rq)
cfqq->next_rq = cfq_find_next_rq(cfqq->cfqd, cfqq, rq);
list_del_init(&rq->queuelist);
cfq_del_rq_rb(rq);
cfqq->cfqd->rq_queued--;
cfqg_stats_update_io_remove(RQ_CFQG(rq), rq->cmd_flags);
if (rq->cmd_flags & REQ_PRIO) {
WARN_ON(!cfqq->prio_pending);
cfqq->prio_pending--;
}
}
static enum elv_merge cfq_merge(struct request_queue *q, struct request **req,
struct bio *bio)
{
struct cfq_data *cfqd = q->elevator->elevator_data;
struct request *__rq;
__rq = cfq_find_rq_fmerge(cfqd, bio);
if (__rq && elv_bio_merge_ok(__rq, bio)) {
*req = __rq;
return ELEVATOR_FRONT_MERGE;
}
return ELEVATOR_NO_MERGE;
}
static void cfq_merged_request(struct request_queue *q, struct request *req,
enum elv_merge type)
{
if (type == ELEVATOR_FRONT_MERGE) {
struct cfq_queue *cfqq = RQ_CFQQ(req);
cfq_reposition_rq_rb(cfqq, req);
}
}
static void cfq_bio_merged(struct request_queue *q, struct request *req,
struct bio *bio)
{
cfqg_stats_update_io_merged(RQ_CFQG(req), bio->bi_opf);
}
static void
cfq_merged_requests(struct request_queue *q, struct request *rq,
struct request *next)
{
struct cfq_queue *cfqq = RQ_CFQQ(rq);
struct cfq_data *cfqd = q->elevator->elevator_data;
if (!list_empty(&rq->queuelist) && !list_empty(&next->queuelist) &&
next->fifo_time < rq->fifo_time &&
cfqq == RQ_CFQQ(next)) {
list_move(&rq->queuelist, &next->queuelist);
rq->fifo_time = next->fifo_time;
}
if (cfqq->next_rq == next)
cfqq->next_rq = rq;
cfq_remove_request(next);
cfqg_stats_update_io_merged(RQ_CFQG(rq), next->cmd_flags);
cfqq = RQ_CFQQ(next);
if (cfq_cfqq_on_rr(cfqq) && RB_EMPTY_ROOT(&cfqq->sort_list) &&
cfqq != cfqd->active_queue)
cfq_del_cfqq_rr(cfqd, cfqq);
}
static int cfq_allow_bio_merge(struct request_queue *q, struct request *rq,
struct bio *bio)
{
struct cfq_data *cfqd = q->elevator->elevator_data;
bool is_sync = op_is_sync(bio->bi_opf);
struct cfq_io_cq *cic;
struct cfq_queue *cfqq;
if (is_sync && !rq_is_sync(rq))
return false;
cic = cfq_cic_lookup(cfqd, current->io_context);
if (!cic)
return false;
cfqq = cic_to_cfqq(cic, is_sync);
return cfqq == RQ_CFQQ(rq);
}
static int cfq_allow_rq_merge(struct request_queue *q, struct request *rq,
struct request *next)
{
return RQ_CFQQ(rq) == RQ_CFQQ(next);
}
static inline void cfq_del_timer(struct cfq_data *cfqd, struct cfq_queue *cfqq)
{
hrtimer_try_to_cancel(&cfqd->idle_slice_timer);
cfqg_stats_update_idle_time(cfqq->cfqg);
}
static void __cfq_set_active_queue(struct cfq_data *cfqd,
struct cfq_queue *cfqq)
{
if (cfqq) {
cfq_log_cfqq(cfqd, cfqq, "set_active wl_class:%d wl_type:%d",
cfqd->serving_wl_class, cfqd->serving_wl_type);
cfqg_stats_update_avg_queue_size(cfqq->cfqg);
cfqq->slice_start = 0;
cfqq->dispatch_start = ktime_get_ns();
cfqq->allocated_slice = 0;
cfqq->slice_end = 0;
cfqq->slice_dispatch = 0;
cfqq->nr_sectors = 0;
cfq_clear_cfqq_wait_request(cfqq);
cfq_clear_cfqq_must_dispatch(cfqq);
cfq_clear_cfqq_must_alloc_slice(cfqq);
cfq_clear_cfqq_fifo_expire(cfqq);
cfq_mark_cfqq_slice_new(cfqq);
cfq_del_timer(cfqd, cfqq);
}
cfqd->active_queue = cfqq;
}
static void
__cfq_slice_expired(struct cfq_data *cfqd, struct cfq_queue *cfqq,
bool timed_out)
{
cfq_log_cfqq(cfqd, cfqq, "slice expired t=%d", timed_out);
if (cfq_cfqq_wait_request(cfqq))
cfq_del_timer(cfqd, cfqq);
cfq_clear_cfqq_wait_request(cfqq);
cfq_clear_cfqq_wait_busy(cfqq);
if (cfq_cfqq_coop(cfqq) && CFQQ_SEEKY(cfqq))
cfq_mark_cfqq_split_coop(cfqq);
if (timed_out) {
if (cfq_cfqq_slice_new(cfqq))
cfqq->slice_resid = cfq_scaled_cfqq_slice(cfqd, cfqq);
else
cfqq->slice_resid = cfqq->slice_end - ktime_get_ns();
cfq_log_cfqq(cfqd, cfqq, "resid=%lld", cfqq->slice_resid);
}
cfq_group_served(cfqd, cfqq->cfqg, cfqq);
if (cfq_cfqq_on_rr(cfqq) && RB_EMPTY_ROOT(&cfqq->sort_list))
cfq_del_cfqq_rr(cfqd, cfqq);
cfq_resort_rr_list(cfqd, cfqq);
if (cfqq == cfqd->active_queue)
cfqd->active_queue = NULL;
if (cfqd->active_cic) {
put_io_context(cfqd->active_cic->icq.ioc);
cfqd->active_cic = NULL;
}
}
static inline void cfq_slice_expired(struct cfq_data *cfqd, bool timed_out)
{
struct cfq_queue *cfqq = cfqd->active_queue;
if (cfqq)
__cfq_slice_expired(cfqd, cfqq, timed_out);
}
static struct cfq_queue *cfq_get_next_queue(struct cfq_data *cfqd)
{
struct cfq_rb_root *st = st_for(cfqd->serving_group,
cfqd->serving_wl_class, cfqd->serving_wl_type);
if (!cfqd->rq_queued)
return NULL;
if (!st)
return NULL;
if (RB_EMPTY_ROOT(&st->rb.rb_root))
return NULL;
return cfq_rb_first(st);
}
static struct cfq_queue *cfq_get_next_queue_forced(struct cfq_data *cfqd)
{
struct cfq_group *cfqg;
struct cfq_queue *cfqq;
int i, j;
struct cfq_rb_root *st;
if (!cfqd->rq_queued)
return NULL;
cfqg = cfq_get_next_cfqg(cfqd);
if (!cfqg)
return NULL;
for_each_cfqg_st(cfqg, i, j, st) {
cfqq = cfq_rb_first(st);
if (cfqq)
return cfqq;
}
return NULL;
}
static struct cfq_queue *cfq_set_active_queue(struct cfq_data *cfqd,
struct cfq_queue *cfqq)
{
if (!cfqq)
cfqq = cfq_get_next_queue(cfqd);
__cfq_set_active_queue(cfqd, cfqq);
return cfqq;
}
static inline sector_t cfq_dist_from_last(struct cfq_data *cfqd,
struct request *rq)
{
if (blk_rq_pos(rq) >= cfqd->last_position)
return blk_rq_pos(rq) - cfqd->last_position;
else
return cfqd->last_position - blk_rq_pos(rq);
}
static inline int cfq_rq_close(struct cfq_data *cfqd, struct cfq_queue *cfqq,
struct request *rq)
{
return cfq_dist_from_last(cfqd, rq) <= CFQQ_CLOSE_THR;
}
static struct cfq_queue *cfqq_close(struct cfq_data *cfqd,
struct cfq_queue *cur_cfqq)
{
struct rb_root *root = &cfqd->prio_trees[cur_cfqq->org_ioprio];
struct rb_node *parent, *node;
struct cfq_queue *__cfqq;
sector_t sector = cfqd->last_position;
if (RB_EMPTY_ROOT(root))
return NULL;
__cfqq = cfq_prio_tree_lookup(cfqd, root, sector, &parent, NULL);
if (__cfqq)
return __cfqq;
__cfqq = rb_entry(parent, struct cfq_queue, p_node);
if (cfq_rq_close(cfqd, cur_cfqq, __cfqq->next_rq))
return __cfqq;
if (blk_rq_pos(__cfqq->next_rq) < sector)
node = rb_next(&__cfqq->p_node);
else
node = rb_prev(&__cfqq->p_node);
if (!node)
return NULL;
__cfqq = rb_entry(node, struct cfq_queue, p_node);
if (cfq_rq_close(cfqd, cur_cfqq, __cfqq->next_rq))
return __cfqq;
return NULL;
}
static struct cfq_queue *cfq_close_cooperator(struct cfq_data *cfqd,
struct cfq_queue *cur_cfqq)
{
struct cfq_queue *cfqq;
if (cfq_class_idle(cur_cfqq))
return NULL;
if (!cfq_cfqq_sync(cur_cfqq))
return NULL;
if (CFQQ_SEEKY(cur_cfqq))
return NULL;
if (cur_cfqq->cfqg->nr_cfqq == 1)
return NULL;
cfqq = cfqq_close(cfqd, cur_cfqq);
if (!cfqq)
return NULL;
if (cur_cfqq->cfqg != cfqq->cfqg)
return NULL;
if (!cfq_cfqq_sync(cfqq))
return NULL;
if (CFQQ_SEEKY(cfqq))
return NULL;
if (cfq_class_rt(cfqq) != cfq_class_rt(cur_cfqq))
return NULL;
return cfqq;
}
static bool cfq_should_idle(struct cfq_data *cfqd, struct cfq_queue *cfqq)
{
enum wl_class_t wl_class = cfqq_class(cfqq);
struct cfq_rb_root *st = cfqq->service_tree;
BUG_ON(!st);
BUG_ON(!st->count);
if (!cfqd->cfq_slice_idle)
return false;
if (wl_class == IDLE_WORKLOAD)
return false;
if (cfq_cfqq_idle_window(cfqq) &&
!(blk_queue_nonrot(cfqd->queue) && cfqd->hw_tag))
return true;
if (st->count == 1 && cfq_cfqq_sync(cfqq) &&
!cfq_io_thinktime_big(cfqd, &st->ttime, false))
return true;
cfq_log_cfqq(cfqd, cfqq, "Not idling. st->count:%d", st->count);
return false;
}
static void cfq_arm_slice_timer(struct cfq_data *cfqd)
{
struct cfq_queue *cfqq = cfqd->active_queue;
struct cfq_rb_root *st = cfqq->service_tree;
struct cfq_io_cq *cic;
u64 sl, group_idle = 0;
u64 now = ktime_get_ns();
if (blk_queue_nonrot(cfqd->queue) && cfqd->hw_tag &&
!cfqd->cfq_group_idle)
return;
WARN_ON(!RB_EMPTY_ROOT(&cfqq->sort_list));
WARN_ON(cfq_cfqq_slice_new(cfqq));
if (!cfq_should_idle(cfqd, cfqq)) {
if (cfqd->cfq_group_idle)
group_idle = cfqd->cfq_group_idle;
else
return;
}
if (cfqq->dispatched)
return;
cic = cfqd->active_cic;
if (!cic || !atomic_read(&cic->icq.ioc->active_ref))
return;
if (sample_valid(cic->ttime.ttime_samples) &&
(cfqq->slice_end - now < cic->ttime.ttime_mean)) {
cfq_log_cfqq(cfqd, cfqq, "Not idling. think_time:%llu",
cic->ttime.ttime_mean);
return;
}
if (group_idle &&
(cfqq->cfqg->nr_cfqq > 1 ||
cfq_io_thinktime_big(cfqd, &st->ttime, true)))
return;
cfq_mark_cfqq_wait_request(cfqq);
if (group_idle)
sl = cfqd->cfq_group_idle;
else
sl = cfqd->cfq_slice_idle;
hrtimer_start(&cfqd->idle_slice_timer, ns_to_ktime(sl),
HRTIMER_MODE_REL);
cfqg_stats_set_start_idle_time(cfqq->cfqg);
cfq_log_cfqq(cfqd, cfqq, "arm_idle: %llu group_idle: %d", sl,
group_idle ? 1 : 0);
}
static void cfq_dispatch_insert(struct request_queue *q, struct request *rq)
{
struct cfq_data *cfqd = q->elevator->elevator_data;
struct cfq_queue *cfqq = RQ_CFQQ(rq);
cfq_log_cfqq(cfqd, cfqq, "dispatch_insert");
cfqq->next_rq = cfq_find_next_rq(cfqd, cfqq, rq);
cfq_remove_request(rq);
cfqq->dispatched++;
(RQ_CFQG(rq))->dispatched++;
elv_dispatch_sort(q, rq);
cfqd->rq_in_flight[cfq_cfqq_sync(cfqq)]++;
cfqq->nr_sectors += blk_rq_sectors(rq);
}
static struct request *cfq_check_fifo(struct cfq_queue *cfqq)
{
struct request *rq = NULL;
if (cfq_cfqq_fifo_expire(cfqq))
return NULL;
cfq_mark_cfqq_fifo_expire(cfqq);
if (list_empty(&cfqq->fifo))
return NULL;
rq = rq_entry_fifo(cfqq->fifo.next);
if (ktime_get_ns() < rq->fifo_time)
rq = NULL;
return rq;
}
static inline int
cfq_prio_to_maxrq(struct cfq_data *cfqd, struct cfq_queue *cfqq)
{
const int base_rq = cfqd->cfq_slice_async_rq;
WARN_ON(cfqq->ioprio >= IOPRIO_BE_NR);
return 2 * base_rq * (IOPRIO_BE_NR - cfqq->ioprio);
}
static int cfqq_process_refs(struct cfq_queue *cfqq)
{
int process_refs, io_refs;
io_refs = cfqq->allocated[READ] + cfqq->allocated[WRITE];
process_refs = cfqq->ref - io_refs;
BUG_ON(process_refs < 0);
return process_refs;
}
static void cfq_setup_merge(struct cfq_queue *cfqq, struct cfq_queue *new_cfqq)
{
int process_refs, new_process_refs;
struct cfq_queue *__cfqq;
if (!cfqq_process_refs(new_cfqq))
return;
while ((__cfqq = new_cfqq->new_cfqq)) {
if (__cfqq == cfqq)
return;
new_cfqq = __cfqq;
}
process_refs = cfqq_process_refs(cfqq);
new_process_refs = cfqq_process_refs(new_cfqq);
if (process_refs == 0 || new_process_refs == 0)
return;
if (new_process_refs >= process_refs) {
cfqq->new_cfqq = new_cfqq;
new_cfqq->ref += process_refs;
} else {
new_cfqq->new_cfqq = cfqq;
cfqq->ref += new_process_refs;
}
}
static enum wl_type_t cfq_choose_wl_type(struct cfq_data *cfqd,
struct cfq_group *cfqg, enum wl_class_t wl_class)
{
struct cfq_queue *queue;
int i;
bool key_valid = false;
u64 lowest_key = 0;
enum wl_type_t cur_best = SYNC_NOIDLE_WORKLOAD;
for (i = 0; i <= SYNC_WORKLOAD; ++i) {
queue = cfq_rb_first(st_for(cfqg, wl_class, i));
if (queue &&
(!key_valid || queue->rb_key < lowest_key)) {
lowest_key = queue->rb_key;
cur_best = i;
key_valid = true;
}
}
return cur_best;
}
static void
choose_wl_class_and_type(struct cfq_data *cfqd, struct cfq_group *cfqg)
{
u64 slice;
unsigned count;
struct cfq_rb_root *st;
u64 group_slice;
enum wl_class_t original_class = cfqd->serving_wl_class;
u64 now = ktime_get_ns();
if (cfq_group_busy_queues_wl(RT_WORKLOAD, cfqd, cfqg))
cfqd->serving_wl_class = RT_WORKLOAD;
else if (cfq_group_busy_queues_wl(BE_WORKLOAD, cfqd, cfqg))
cfqd->serving_wl_class = BE_WORKLOAD;
else {
cfqd->serving_wl_class = IDLE_WORKLOAD;
cfqd->workload_expires = now + jiffies_to_nsecs(1);
return;
}
if (original_class != cfqd->serving_wl_class)
goto new_workload;
st = st_for(cfqg, cfqd->serving_wl_class, cfqd->serving_wl_type);
count = st->count;
if (count && !(now > cfqd->workload_expires))
return;
new_workload:
cfqd->serving_wl_type = cfq_choose_wl_type(cfqd, cfqg,
cfqd->serving_wl_class);
st = st_for(cfqg, cfqd->serving_wl_class, cfqd->serving_wl_type);
count = st->count;
group_slice = cfq_group_slice(cfqd, cfqg);
slice = div_u64(group_slice * count,
max_t(unsigned, cfqg->busy_queues_avg[cfqd->serving_wl_class],
cfq_group_busy_queues_wl(cfqd->serving_wl_class, cfqd,
cfqg)));
if (cfqd->serving_wl_type == ASYNC_WORKLOAD) {
u64 tmp;
tmp = cfqd->cfq_target_latency *
cfqg_busy_async_queues(cfqd, cfqg);
tmp = div_u64(tmp, cfqd->busy_queues);
slice = min_t(u64, slice, tmp);
slice = div64_u64(slice*cfqd->cfq_slice[0], cfqd->cfq_slice[1]);
} else
slice = max(slice, 2 * cfqd->cfq_slice_idle);
slice = max_t(u64, slice, CFQ_MIN_TT);
cfq_log(cfqd, "workload slice:%llu", slice);
cfqd->workload_expires = now + slice;
}
static struct cfq_group *cfq_get_next_cfqg(struct cfq_data *cfqd)
{
struct cfq_rb_root *st = &cfqd->grp_service_tree;
struct cfq_group *cfqg;
if (RB_EMPTY_ROOT(&st->rb.rb_root))
return NULL;
cfqg = cfq_rb_first_group(st);
update_min_vdisktime(st);
return cfqg;
}
static void cfq_choose_cfqg(struct cfq_data *cfqd)
{
struct cfq_group *cfqg = cfq_get_next_cfqg(cfqd);
u64 now = ktime_get_ns();
cfqd->serving_group = cfqg;
if (cfqg->saved_wl_slice) {
cfqd->workload_expires = now + cfqg->saved_wl_slice;
cfqd->serving_wl_type = cfqg->saved_wl_type;
cfqd->serving_wl_class = cfqg->saved_wl_class;
} else
cfqd->workload_expires = now - 1;
choose_wl_class_and_type(cfqd, cfqg);
}
static struct cfq_queue *cfq_select_queue(struct cfq_data *cfqd)
{
struct cfq_queue *cfqq, *new_cfqq = NULL;
u64 now = ktime_get_ns();
cfqq = cfqd->active_queue;
if (!cfqq)
goto new_queue;
if (!cfqd->rq_queued)
return NULL;
if (cfq_cfqq_wait_busy(cfqq) && !RB_EMPTY_ROOT(&cfqq->sort_list))
goto expire;
if (cfq_slice_used(cfqq) && !cfq_cfqq_must_dispatch(cfqq)) {
if (cfqq->cfqg->nr_cfqq == 1 && RB_EMPTY_ROOT(&cfqq->sort_list)
&& cfqq->dispatched && cfq_should_idle(cfqd, cfqq)) {
cfqq = NULL;
goto keep_queue;
} else
goto check_group_idle;
}
if (!RB_EMPTY_ROOT(&cfqq->sort_list))
goto keep_queue;
new_cfqq = cfq_close_cooperator(cfqd, cfqq);
if (new_cfqq) {
if (!cfqq->new_cfqq)
cfq_setup_merge(cfqq, new_cfqq);
goto expire;
}
if (hrtimer_active(&cfqd->idle_slice_timer)) {
cfqq = NULL;
goto keep_queue;
}
if (CFQQ_SEEKY(cfqq) && cfq_cfqq_idle_window(cfqq) &&
(cfq_cfqq_slice_new(cfqq) ||
(cfqq->slice_end - now > now - cfqq->slice_start))) {
cfq_clear_cfqq_deep(cfqq);
cfq_clear_cfqq_idle_window(cfqq);
}
if (cfqq->dispatched && cfq_should_idle(cfqd, cfqq)) {
cfqq = NULL;
goto keep_queue;
}
check_group_idle:
if (cfqd->cfq_group_idle && cfqq->cfqg->nr_cfqq == 1 &&
cfqq->cfqg->dispatched &&
!cfq_io_thinktime_big(cfqd, &cfqq->cfqg->ttime, true)) {
cfqq = NULL;
goto keep_queue;
}
expire:
cfq_slice_expired(cfqd, 0);
new_queue:
if (!new_cfqq)
cfq_choose_cfqg(cfqd);
cfqq = cfq_set_active_queue(cfqd, new_cfqq);
keep_queue:
return cfqq;
}
static int __cfq_forced_dispatch_cfqq(struct cfq_queue *cfqq)
{
int dispatched = 0;
while (cfqq->next_rq) {
cfq_dispatch_insert(cfqq->cfqd->queue, cfqq->next_rq);
dispatched++;
}
BUG_ON(!list_empty(&cfqq->fifo));
__cfq_slice_expired(cfqq->cfqd, cfqq, 0);
return dispatched;
}
static int cfq_forced_dispatch(struct cfq_data *cfqd)
{
struct cfq_queue *cfqq;
int dispatched = 0;
cfq_slice_expired(cfqd, 0);
while ((cfqq = cfq_get_next_queue_forced(cfqd)) != NULL) {
__cfq_set_active_queue(cfqd, cfqq);
dispatched += __cfq_forced_dispatch_cfqq(cfqq);
}
BUG_ON(cfqd->busy_queues);
cfq_log(cfqd, "forced_dispatch=%d", dispatched);
return dispatched;
}
static inline bool cfq_slice_used_soon(struct cfq_data *cfqd,
struct cfq_queue *cfqq)
{
u64 now = ktime_get_ns();
if (cfq_cfqq_slice_new(cfqq))
return true;
if (now + cfqd->cfq_slice_idle * cfqq->dispatched > cfqq->slice_end)
return true;
return false;
}
static bool cfq_may_dispatch(struct cfq_data *cfqd, struct cfq_queue *cfqq)
{
unsigned int max_dispatch;
if (cfq_cfqq_must_dispatch(cfqq))
return true;
if (cfq_should_idle(cfqd, cfqq) && cfqd->rq_in_flight[BLK_RW_ASYNC])
return false;
if (cfqd->rq_in_flight[BLK_RW_SYNC] && !cfq_cfqq_sync(cfqq))
return false;
max_dispatch = max_t(unsigned int, cfqd->cfq_quantum / 2, 1);
if (cfq_class_idle(cfqq))
max_dispatch = 1;
if (cfqq->dispatched >= max_dispatch) {
bool promote_sync = false;
if (cfq_class_idle(cfqq))
return false;
if (cfq_cfqq_sync(cfqq) && cfqd->busy_sync_queues == 1)
promote_sync = true;
if (cfqd->busy_queues > 1 && cfq_slice_used_soon(cfqd, cfqq) &&
!promote_sync)
return false;
if (cfqd->busy_queues == 1 || promote_sync)
max_dispatch = -1;
else
max_dispatch = cfqd->cfq_quantum;
}
if (!cfq_cfqq_sync(cfqq) && cfqd->cfq_latency) {
u64 last_sync = ktime_get_ns() - cfqd->last_delayed_sync;
unsigned int depth;
depth = div64_u64(last_sync, cfqd->cfq_slice[1]);
if (!depth && !cfqq->dispatched)
depth = 1;
if (depth < max_dispatch)
max_dispatch = depth;
}
return cfqq->dispatched < max_dispatch;
}
static bool cfq_dispatch_request(struct cfq_data *cfqd, struct cfq_queue *cfqq)
{
struct request *rq;
BUG_ON(RB_EMPTY_ROOT(&cfqq->sort_list));
rq = cfq_check_fifo(cfqq);
if (rq)
cfq_mark_cfqq_must_dispatch(cfqq);
if (!cfq_may_dispatch(cfqd, cfqq))
return false;
if (!rq)
rq = cfqq->next_rq;
else
cfq_log_cfqq(cfqq->cfqd, cfqq, "fifo=%p", rq);
cfq_dispatch_insert(cfqd->queue, rq);
if (!cfqd->active_cic) {
struct cfq_io_cq *cic = RQ_CIC(rq);
atomic_long_inc(&cic->icq.ioc->refcount);
cfqd->active_cic = cic;
}
return true;
}
static int cfq_dispatch_requests(struct request_queue *q, int force)
{
struct cfq_data *cfqd = q->elevator->elevator_data;
struct cfq_queue *cfqq;
if (!cfqd->busy_queues)
return 0;
if (unlikely(force))
return cfq_forced_dispatch(cfqd);
cfqq = cfq_select_queue(cfqd);
if (!cfqq)
return 0;
if (!cfq_dispatch_request(cfqd, cfqq))
return 0;
cfqq->slice_dispatch++;
cfq_clear_cfqq_must_dispatch(cfqq);
if (cfqd->busy_queues > 1 && ((!cfq_cfqq_sync(cfqq) &&
cfqq->slice_dispatch >= cfq_prio_to_maxrq(cfqd, cfqq)) ||
cfq_class_idle(cfqq))) {
cfqq->slice_end = ktime_get_ns() + 1;
cfq_slice_expired(cfqd, 0);
}
cfq_log_cfqq(cfqd, cfqq, "dispatched a request");
return 1;
}
static void cfq_put_queue(struct cfq_queue *cfqq)
{
struct cfq_data *cfqd = cfqq->cfqd;
struct cfq_group *cfqg;
BUG_ON(cfqq->ref <= 0);
cfqq->ref--;
if (cfqq->ref)
return;
cfq_log_cfqq(cfqd, cfqq, "put_queue");
BUG_ON(rb_first(&cfqq->sort_list));
BUG_ON(cfqq->allocated[READ] + cfqq->allocated[WRITE]);
cfqg = cfqq->cfqg;
if (unlikely(cfqd->active_queue == cfqq)) {
__cfq_slice_expired(cfqd, cfqq, 0);
cfq_schedule_dispatch(cfqd);
}
BUG_ON(cfq_cfqq_on_rr(cfqq));
kmem_cache_free(cfq_pool, cfqq);
cfqg_put(cfqg);
}
static void cfq_put_cooperator(struct cfq_queue *cfqq)
{
struct cfq_queue *__cfqq, *next;
__cfqq = cfqq->new_cfqq;
while (__cfqq) {
if (__cfqq == cfqq) {
WARN(1, "cfqq->new_cfqq loop detected\n");
break;
}
next = __cfqq->new_cfqq;
cfq_put_queue(__cfqq);
__cfqq = next;
}
}
static void cfq_exit_cfqq(struct cfq_data *cfqd, struct cfq_queue *cfqq)
{
if (unlikely(cfqq == cfqd->active_queue)) {
__cfq_slice_expired(cfqd, cfqq, 0);
cfq_schedule_dispatch(cfqd);
}
cfq_put_cooperator(cfqq);
cfq_put_queue(cfqq);
}
static void cfq_init_icq(struct io_cq *icq)
{
struct cfq_io_cq *cic = icq_to_cic(icq);
cic->ttime.last_end_request = ktime_get_ns();
}
static void cfq_exit_icq(struct io_cq *icq)
{
struct cfq_io_cq *cic = icq_to_cic(icq);
struct cfq_data *cfqd = cic_to_cfqd(cic);
if (cic_to_cfqq(cic, false)) {
cfq_exit_cfqq(cfqd, cic_to_cfqq(cic, false));
cic_set_cfqq(cic, NULL, false);
}
if (cic_to_cfqq(cic, true)) {
cfq_exit_cfqq(cfqd, cic_to_cfqq(cic, true));
cic_set_cfqq(cic, NULL, true);
}
}
static void cfq_init_prio_data(struct cfq_queue *cfqq, struct cfq_io_cq *cic)
{
struct task_struct *tsk = current;
int ioprio_class;
if (!cfq_cfqq_prio_changed(cfqq))
return;
ioprio_class = IOPRIO_PRIO_CLASS(cic->ioprio);
switch (ioprio_class) {
default:
printk(KERN_ERR "cfq: bad prio %x\n", ioprio_class);
case IOPRIO_CLASS_NONE:
cfqq->ioprio = task_nice_ioprio(tsk);
cfqq->ioprio_class = task_nice_ioclass(tsk);
break;
case IOPRIO_CLASS_RT:
cfqq->ioprio = IOPRIO_PRIO_DATA(cic->ioprio);
cfqq->ioprio_class = IOPRIO_CLASS_RT;
break;
case IOPRIO_CLASS_BE:
cfqq->ioprio = IOPRIO_PRIO_DATA(cic->ioprio);
cfqq->ioprio_class = IOPRIO_CLASS_BE;
break;
case IOPRIO_CLASS_IDLE:
cfqq->ioprio_class = IOPRIO_CLASS_IDLE;
cfqq->ioprio = 7;
cfq_clear_cfqq_idle_window(cfqq);
break;
}
cfqq->org_ioprio = cfqq->ioprio;
cfqq->org_ioprio_class = cfqq->ioprio_class;
cfq_clear_cfqq_prio_changed(cfqq);
}
static void check_ioprio_changed(struct cfq_io_cq *cic, struct bio *bio)
{
int ioprio = cic->icq.ioc->ioprio;
struct cfq_data *cfqd = cic_to_cfqd(cic);
struct cfq_queue *cfqq;
if (unlikely(!cfqd) || likely(cic->ioprio == ioprio))
return;
cfqq = cic_to_cfqq(cic, false);
if (cfqq) {
cfq_put_queue(cfqq);
cfqq = cfq_get_queue(cfqd, BLK_RW_ASYNC, cic, bio);
cic_set_cfqq(cic, cfqq, false);
}
cfqq = cic_to_cfqq(cic, true);
if (cfqq)
cfq_mark_cfqq_prio_changed(cfqq);
cic->ioprio = ioprio;
}
static void cfq_init_cfqq(struct cfq_data *cfqd, struct cfq_queue *cfqq,
pid_t pid, bool is_sync)
{
RB_CLEAR_NODE(&cfqq->rb_node);
RB_CLEAR_NODE(&cfqq->p_node);
INIT_LIST_HEAD(&cfqq->fifo);
cfqq->ref = 0;
cfqq->cfqd = cfqd;
cfq_mark_cfqq_prio_changed(cfqq);
if (is_sync) {
if (!cfq_class_idle(cfqq))
cfq_mark_cfqq_idle_window(cfqq);
cfq_mark_cfqq_sync(cfqq);
}
cfqq->pid = pid;
}
static void check_blkcg_changed(struct cfq_io_cq *cic, struct bio *bio)
{
struct cfq_data *cfqd = cic_to_cfqd(cic);
struct cfq_queue *cfqq;
uint64_t serial_nr;
rcu_read_lock();
serial_nr = bio_blkcg(bio)->css.serial_nr;
rcu_read_unlock();
if (unlikely(!cfqd) || likely(cic->blkcg_serial_nr == serial_nr))
return;
cfqq = cic_to_cfqq(cic, false);
if (cfqq) {
cfq_log_cfqq(cfqd, cfqq, "changed cgroup");
cic_set_cfqq(cic, NULL, false);
cfq_put_queue(cfqq);
}
cfqq = cic_to_cfqq(cic, true);
if (cfqq) {
cfq_log_cfqq(cfqd, cfqq, "changed cgroup");
cic_set_cfqq(cic, NULL, true);
cfq_put_queue(cfqq);
}
cic->blkcg_serial_nr = serial_nr;
}
static inline void check_blkcg_changed(struct cfq_io_cq *cic, struct bio *bio)
{
}
static struct cfq_queue **
cfq_async_queue_prio(struct cfq_group *cfqg, int ioprio_class, int ioprio)
{
switch (ioprio_class) {
case IOPRIO_CLASS_RT:
return &cfqg->async_cfqq[0][ioprio];
case IOPRIO_CLASS_NONE:
ioprio = IOPRIO_NORM;
case IOPRIO_CLASS_BE:
return &cfqg->async_cfqq[1][ioprio];
case IOPRIO_CLASS_IDLE:
return &cfqg->async_idle_cfqq;
default:
BUG();
}
}
static struct cfq_queue *
cfq_get_queue(struct cfq_data *cfqd, bool is_sync, struct cfq_io_cq *cic,
struct bio *bio)
{
int ioprio_class = IOPRIO_PRIO_CLASS(cic->ioprio);
int ioprio = IOPRIO_PRIO_DATA(cic->ioprio);
struct cfq_queue **async_cfqq = NULL;
struct cfq_queue *cfqq;
struct cfq_group *cfqg;
rcu_read_lock();
cfqg = cfq_lookup_cfqg(cfqd, bio_blkcg(bio));
if (!cfqg) {
cfqq = &cfqd->oom_cfqq;
goto out;
}
if (!is_sync) {
if (!ioprio_valid(cic->ioprio)) {
struct task_struct *tsk = current;
ioprio = task_nice_ioprio(tsk);
ioprio_class = task_nice_ioclass(tsk);
}
async_cfqq = cfq_async_queue_prio(cfqg, ioprio_class, ioprio);
cfqq = *async_cfqq;
if (cfqq)
goto out;
}
cfqq = kmem_cache_alloc_node(cfq_pool,
GFP_NOWAIT | __GFP_ZERO | __GFP_NOWARN,
cfqd->queue->node);
if (!cfqq) {
cfqq = &cfqd->oom_cfqq;
goto out;
}
cfqq->ioprio_class = IOPRIO_CLASS_NONE;
cfq_init_cfqq(cfqd, cfqq, current->pid, is_sync);
cfq_init_prio_data(cfqq, cic);
cfq_link_cfqq_cfqg(cfqq, cfqg);
cfq_log_cfqq(cfqd, cfqq, "alloced");
if (async_cfqq) {
cfqq->ref++;
*async_cfqq = cfqq;
}
out:
cfqq->ref++;
rcu_read_unlock();
return cfqq;
}
static void
__cfq_update_io_thinktime(struct cfq_ttime *ttime, u64 slice_idle)
{
u64 elapsed = ktime_get_ns() - ttime->last_end_request;
elapsed = min(elapsed, 2UL * slice_idle);
ttime->ttime_samples = (7*ttime->ttime_samples + 256) / 8;
ttime->ttime_total = div_u64(7*ttime->ttime_total + 256*elapsed, 8);
ttime->ttime_mean = div64_ul(ttime->ttime_total + 128,
ttime->ttime_samples);
}
static void
cfq_update_io_thinktime(struct cfq_data *cfqd, struct cfq_queue *cfqq,
struct cfq_io_cq *cic)
{
if (cfq_cfqq_sync(cfqq)) {
__cfq_update_io_thinktime(&cic->ttime, cfqd->cfq_slice_idle);
__cfq_update_io_thinktime(&cfqq->service_tree->ttime,
cfqd->cfq_slice_idle);
}
#ifdef CONFIG_CFQ_GROUP_IOSCHED
__cfq_update_io_thinktime(&cfqq->cfqg->ttime, cfqd->cfq_group_idle);
#endif
}
static void
cfq_update_io_seektime(struct cfq_data *cfqd, struct cfq_queue *cfqq,
struct request *rq)
{
sector_t sdist = 0;
sector_t n_sec = blk_rq_sectors(rq);
if (cfqq->last_request_pos) {
if (cfqq->last_request_pos < blk_rq_pos(rq))
sdist = blk_rq_pos(rq) - cfqq->last_request_pos;
else
sdist = cfqq->last_request_pos - blk_rq_pos(rq);
}
cfqq->seek_history <<= 1;
if (blk_queue_nonrot(cfqd->queue))
cfqq->seek_history |= (n_sec < CFQQ_SECT_THR_NONROT);
else
cfqq->seek_history |= (sdist > CFQQ_SEEK_THR);
}
static inline bool req_noidle(struct request *req)
{
return req_op(req) == REQ_OP_WRITE &&
(req->cmd_flags & (REQ_SYNC | REQ_IDLE)) == REQ_SYNC;
}
static void
cfq_update_idle_window(struct cfq_data *cfqd, struct cfq_queue *cfqq,
struct cfq_io_cq *cic)
{
int old_idle, enable_idle;
if (!cfq_cfqq_sync(cfqq) || cfq_class_idle(cfqq))
return;
enable_idle = old_idle = cfq_cfqq_idle_window(cfqq);
if (cfqq->queued[0] + cfqq->queued[1] >= 4)
cfq_mark_cfqq_deep(cfqq);
if (cfqq->next_rq && req_noidle(cfqq->next_rq))
enable_idle = 0;
else if (!atomic_read(&cic->icq.ioc->active_ref) ||
!cfqd->cfq_slice_idle ||
(!cfq_cfqq_deep(cfqq) && CFQQ_SEEKY(cfqq)))
enable_idle = 0;
else if (sample_valid(cic->ttime.ttime_samples)) {
if (cic->ttime.ttime_mean > cfqd->cfq_slice_idle)
enable_idle = 0;
else
enable_idle = 1;
}
if (old_idle != enable_idle) {
cfq_log_cfqq(cfqd, cfqq, "idle=%d", enable_idle);
if (enable_idle)
cfq_mark_cfqq_idle_window(cfqq);
else
cfq_clear_cfqq_idle_window(cfqq);
}
}
static bool
cfq_should_preempt(struct cfq_data *cfqd, struct cfq_queue *new_cfqq,
struct request *rq)
{
struct cfq_queue *cfqq;
cfqq = cfqd->active_queue;
if (!cfqq)
return false;
if (cfq_class_idle(new_cfqq))
return false;
if (cfq_class_idle(cfqq))
return true;
if (cfq_class_rt(cfqq) && !cfq_class_rt(new_cfqq))
return false;
if (rq_is_sync(rq) && !cfq_cfqq_sync(cfqq) && !cfq_cfqq_must_dispatch(cfqq))
return true;
if (!cfqg_is_descendant(cfqq->cfqg, new_cfqq->cfqg))
return false;
if (cfq_slice_used(cfqq))
return true;
if (cfq_class_rt(new_cfqq) && !cfq_class_rt(cfqq))
return true;
WARN_ON_ONCE(cfqq->ioprio_class != new_cfqq->ioprio_class);
if (cfqd->serving_wl_type == SYNC_NOIDLE_WORKLOAD &&
cfqq_type(new_cfqq) == SYNC_NOIDLE_WORKLOAD &&
RB_EMPTY_ROOT(&cfqq->sort_list))
return true;
if ((rq->cmd_flags & REQ_PRIO) && !cfqq->prio_pending)
return true;
if (RB_EMPTY_ROOT(&cfqq->sort_list) && !cfq_should_idle(cfqd, cfqq))
return true;
if (!cfqd->active_cic || !cfq_cfqq_wait_request(cfqq))
return false;
if (cfq_rq_close(cfqd, cfqq, rq))
return true;
return false;
}
static void cfq_preempt_queue(struct cfq_data *cfqd, struct cfq_queue *cfqq)
{
enum wl_type_t old_type = cfqq_type(cfqd->active_queue);
cfq_log_cfqq(cfqd, cfqq, "preempt");
cfq_slice_expired(cfqd, 1);
if (old_type != cfqq_type(cfqq))
cfqq->cfqg->saved_wl_slice = 0;
BUG_ON(!cfq_cfqq_on_rr(cfqq));
cfq_service_tree_add(cfqd, cfqq, 1);
cfqq->slice_end = 0;
cfq_mark_cfqq_slice_new(cfqq);
}
static void
cfq_rq_enqueued(struct cfq_data *cfqd, struct cfq_queue *cfqq,
struct request *rq)
{
struct cfq_io_cq *cic = RQ_CIC(rq);
cfqd->rq_queued++;
if (rq->cmd_flags & REQ_PRIO)
cfqq->prio_pending++;
cfq_update_io_thinktime(cfqd, cfqq, cic);
cfq_update_io_seektime(cfqd, cfqq, rq);
cfq_update_idle_window(cfqd, cfqq, cic);
cfqq->last_request_pos = blk_rq_pos(rq) + blk_rq_sectors(rq);
if (cfqq == cfqd->active_queue) {
if (cfq_cfqq_wait_request(cfqq)) {
if (blk_rq_bytes(rq) > PAGE_SIZE ||
cfqd->busy_queues > 1) {
cfq_del_timer(cfqd, cfqq);
cfq_clear_cfqq_wait_request(cfqq);
__blk_run_queue(cfqd->queue);
} else {
cfqg_stats_update_idle_time(cfqq->cfqg);
cfq_mark_cfqq_must_dispatch(cfqq);
}
}
} else if (cfq_should_preempt(cfqd, cfqq, rq)) {
cfq_preempt_queue(cfqd, cfqq);
__blk_run_queue(cfqd->queue);
}
}
static void cfq_insert_request(struct request_queue *q, struct request *rq)
{
struct cfq_data *cfqd = q->elevator->elevator_data;
struct cfq_queue *cfqq = RQ_CFQQ(rq);
cfq_log_cfqq(cfqd, cfqq, "insert_request");
cfq_init_prio_data(cfqq, RQ_CIC(rq));
rq->fifo_time = ktime_get_ns() + cfqd->cfq_fifo_expire[rq_is_sync(rq)];
list_add_tail(&rq->queuelist, &cfqq->fifo);
cfq_add_rq_rb(rq);
cfqg_stats_update_io_add(RQ_CFQG(rq), cfqd->serving_group,
rq->cmd_flags);
cfq_rq_enqueued(cfqd, cfqq, rq);
}
static void cfq_update_hw_tag(struct cfq_data *cfqd)
{
struct cfq_queue *cfqq = cfqd->active_queue;
if (cfqd->rq_in_driver > cfqd->hw_tag_est_depth)
cfqd->hw_tag_est_depth = cfqd->rq_in_driver;
if (cfqd->hw_tag == 1)
return;
if (cfqd->rq_queued <= CFQ_HW_QUEUE_MIN &&
cfqd->rq_in_driver <= CFQ_HW_QUEUE_MIN)
return;
if (cfqq && cfq_cfqq_idle_window(cfqq) &&
cfqq->dispatched + cfqq->queued[0] + cfqq->queued[1] <
CFQ_HW_QUEUE_MIN && cfqd->rq_in_driver < CFQ_HW_QUEUE_MIN)
return;
if (cfqd->hw_tag_samples++ < 50)
return;
if (cfqd->hw_tag_est_depth >= CFQ_HW_QUEUE_MIN)
cfqd->hw_tag = 1;
else
cfqd->hw_tag = 0;
}
static bool cfq_should_wait_busy(struct cfq_data *cfqd, struct cfq_queue *cfqq)
{
struct cfq_io_cq *cic = cfqd->active_cic;
u64 now = ktime_get_ns();
if (!RB_EMPTY_ROOT(&cfqq->sort_list))
return false;
if (cfqq->cfqg->nr_cfqq > 1)
return false;
if (cfq_io_thinktime_big(cfqd, &cfqq->cfqg->ttime, true))
return false;
if (cfq_slice_used(cfqq))
return true;
if (cic && sample_valid(cic->ttime.ttime_samples)
&& (cfqq->slice_end - now < cic->ttime.ttime_mean))
return true;
if (cfqq->slice_end - now <= jiffies_to_nsecs(1))
return true;
return false;
}
static void cfq_completed_request(struct request_queue *q, struct request *rq)
{
struct cfq_queue *cfqq = RQ_CFQQ(rq);
struct cfq_data *cfqd = cfqq->cfqd;
const int sync = rq_is_sync(rq);
u64 now = ktime_get_ns();
cfq_log_cfqq(cfqd, cfqq, "complete rqnoidle %d", req_noidle(rq));
cfq_update_hw_tag(cfqd);
WARN_ON(!cfqd->rq_in_driver);
WARN_ON(!cfqq->dispatched);
cfqd->rq_in_driver--;
cfqq->dispatched--;
(RQ_CFQG(rq))->dispatched--;
cfqg_stats_update_completion(cfqq->cfqg, rq_start_time_ns(rq),
rq_io_start_time_ns(rq), rq->cmd_flags);
cfqd->rq_in_flight[cfq_cfqq_sync(cfqq)]--;
if (sync) {
struct cfq_rb_root *st;
RQ_CIC(rq)->ttime.last_end_request = now;
if (cfq_cfqq_on_rr(cfqq))
st = cfqq->service_tree;
else
st = st_for(cfqq->cfqg, cfqq_class(cfqq),
cfqq_type(cfqq));
st->ttime.last_end_request = now;
if (!time_after(rq->start_time +
nsecs_to_jiffies(cfqd->cfq_fifo_expire[1]),
jiffies))
cfqd->last_delayed_sync = now;
}
#ifdef CONFIG_CFQ_GROUP_IOSCHED
cfqq->cfqg->ttime.last_end_request = now;
#endif
if (cfqd->active_queue == cfqq) {
const bool cfqq_empty = RB_EMPTY_ROOT(&cfqq->sort_list);
if (cfq_cfqq_slice_new(cfqq)) {
cfq_set_prio_slice(cfqd, cfqq);
cfq_clear_cfqq_slice_new(cfqq);
}
if (cfq_should_wait_busy(cfqd, cfqq)) {
u64 extend_sl = cfqd->cfq_slice_idle;
if (!cfqd->cfq_slice_idle)
extend_sl = cfqd->cfq_group_idle;
cfqq->slice_end = now + extend_sl;
cfq_mark_cfqq_wait_busy(cfqq);
cfq_log_cfqq(cfqd, cfqq, "will busy wait");
}
if (cfq_slice_used(cfqq) || cfq_class_idle(cfqq))
cfq_slice_expired(cfqd, 1);
else if (sync && cfqq_empty &&
!cfq_close_cooperator(cfqd, cfqq)) {
cfq_arm_slice_timer(cfqd);
}
}
if (!cfqd->rq_in_driver)
cfq_schedule_dispatch(cfqd);
}
static void cfqq_boost_on_prio(struct cfq_queue *cfqq, unsigned int op)
{
if (!(op & REQ_PRIO)) {
cfqq->ioprio_class = cfqq->org_ioprio_class;
cfqq->ioprio = cfqq->org_ioprio;
} else {
if (cfq_class_idle(cfqq))
cfqq->ioprio_class = IOPRIO_CLASS_BE;
if (cfqq->ioprio > IOPRIO_NORM)
cfqq->ioprio = IOPRIO_NORM;
}
}
static inline int __cfq_may_queue(struct cfq_queue *cfqq)
{
if (cfq_cfqq_wait_request(cfqq) && !cfq_cfqq_must_alloc_slice(cfqq)) {
cfq_mark_cfqq_must_alloc_slice(cfqq);
return ELV_MQUEUE_MUST;
}
return ELV_MQUEUE_MAY;
}
static int cfq_may_queue(struct request_queue *q, unsigned int op)
{
struct cfq_data *cfqd = q->elevator->elevator_data;
struct task_struct *tsk = current;
struct cfq_io_cq *cic;
struct cfq_queue *cfqq;
cic = cfq_cic_lookup(cfqd, tsk->io_context);
if (!cic)
return ELV_MQUEUE_MAY;
cfqq = cic_to_cfqq(cic, op_is_sync(op));
if (cfqq) {
cfq_init_prio_data(cfqq, cic);
cfqq_boost_on_prio(cfqq, op);
return __cfq_may_queue(cfqq);
}
return ELV_MQUEUE_MAY;
}
static void cfq_put_request(struct request *rq)
{
struct cfq_queue *cfqq = RQ_CFQQ(rq);
if (cfqq) {
const int rw = rq_data_dir(rq);
BUG_ON(!cfqq->allocated[rw]);
cfqq->allocated[rw]--;
cfqg_put(RQ_CFQG(rq));
rq->elv.priv[0] = NULL;
rq->elv.priv[1] = NULL;
cfq_put_queue(cfqq);
}
}
static struct cfq_queue *
cfq_merge_cfqqs(struct cfq_data *cfqd, struct cfq_io_cq *cic,
struct cfq_queue *cfqq)
{
cfq_log_cfqq(cfqd, cfqq, "merging with queue %p", cfqq->new_cfqq);
cic_set_cfqq(cic, cfqq->new_cfqq, 1);
cfq_mark_cfqq_coop(cfqq->new_cfqq);
cfq_put_queue(cfqq);
return cic_to_cfqq(cic, 1);
}
static struct cfq_queue *
split_cfqq(struct cfq_io_cq *cic, struct cfq_queue *cfqq)
{
if (cfqq_process_refs(cfqq) == 1) {
cfqq->pid = current->pid;
cfq_clear_cfqq_coop(cfqq);
cfq_clear_cfqq_split_coop(cfqq);
return cfqq;
}
cic_set_cfqq(cic, NULL, 1);
cfq_put_cooperator(cfqq);
cfq_put_queue(cfqq);
return NULL;
}
static int
cfq_set_request(struct request_queue *q, struct request *rq, struct bio *bio,
gfp_t gfp_mask)
{
struct cfq_data *cfqd = q->elevator->elevator_data;
struct cfq_io_cq *cic = icq_to_cic(rq->elv.icq);
const int rw = rq_data_dir(rq);
const bool is_sync = rq_is_sync(rq);
struct cfq_queue *cfqq;
spin_lock_irq(q->queue_lock);
check_ioprio_changed(cic, bio);
check_blkcg_changed(cic, bio);
new_queue:
cfqq = cic_to_cfqq(cic, is_sync);
if (!cfqq || cfqq == &cfqd->oom_cfqq) {
if (cfqq)
cfq_put_queue(cfqq);
cfqq = cfq_get_queue(cfqd, is_sync, cic, bio);
cic_set_cfqq(cic, cfqq, is_sync);
} else {
if (cfq_cfqq_coop(cfqq) && cfq_cfqq_split_coop(cfqq)) {
cfq_log_cfqq(cfqd, cfqq, "breaking apart cfqq");
cfqq = split_cfqq(cic, cfqq);
if (!cfqq)
goto new_queue;
}
if (cfqq->new_cfqq)
cfqq = cfq_merge_cfqqs(cfqd, cic, cfqq);
}
cfqq->allocated[rw]++;
cfqq->ref++;
cfqg_get(cfqq->cfqg);
rq->elv.priv[0] = cfqq;
rq->elv.priv[1] = cfqq->cfqg;
spin_unlock_irq(q->queue_lock);
return 0;
}
static void cfq_kick_queue(struct work_struct *work)
{
struct cfq_data *cfqd =
container_of(work, struct cfq_data, unplug_work);
struct request_queue *q = cfqd->queue;
spin_lock_irq(q->queue_lock);
__blk_run_queue(cfqd->queue);
spin_unlock_irq(q->queue_lock);
}
static enum hrtimer_restart cfq_idle_slice_timer(struct hrtimer *timer)
{
struct cfq_data *cfqd = container_of(timer, struct cfq_data,
idle_slice_timer);
struct cfq_queue *cfqq;
unsigned long flags;
int timed_out = 1;
cfq_log(cfqd, "idle timer fired");
spin_lock_irqsave(cfqd->queue->queue_lock, flags);
cfqq = cfqd->active_queue;
if (cfqq) {
timed_out = 0;
if (cfq_cfqq_must_dispatch(cfqq))
goto out_kick;
if (cfq_slice_used(cfqq))
goto expire;
if (!cfqd->busy_queues)
goto out_cont;
if (!RB_EMPTY_ROOT(&cfqq->sort_list))
goto out_kick;
cfq_clear_cfqq_deep(cfqq);
}
expire:
cfq_slice_expired(cfqd, timed_out);
out_kick:
cfq_schedule_dispatch(cfqd);
out_cont:
spin_unlock_irqrestore(cfqd->queue->queue_lock, flags);
return HRTIMER_NORESTART;
}
static void cfq_shutdown_timer_wq(struct cfq_data *cfqd)
{
hrtimer_cancel(&cfqd->idle_slice_timer);
cancel_work_sync(&cfqd->unplug_work);
}
static void cfq_exit_queue(struct elevator_queue *e)
{
struct cfq_data *cfqd = e->elevator_data;
struct request_queue *q = cfqd->queue;
cfq_shutdown_timer_wq(cfqd);
spin_lock_irq(q->queue_lock);
if (cfqd->active_queue)
__cfq_slice_expired(cfqd, cfqd->active_queue, 0);
spin_unlock_irq(q->queue_lock);
cfq_shutdown_timer_wq(cfqd);
#ifdef CONFIG_CFQ_GROUP_IOSCHED
blkcg_deactivate_policy(q, &blkcg_policy_cfq);
#else
kfree(cfqd->root_group);
#endif
kfree(cfqd);
}
static int cfq_init_queue(struct request_queue *q, struct elevator_type *e)
{
struct cfq_data *cfqd;
struct blkcg_gq *blkg __maybe_unused;
int i, ret;
struct elevator_queue *eq;
eq = elevator_alloc(q, e);
if (!eq)
return -ENOMEM;
cfqd = kzalloc_node(sizeof(*cfqd), GFP_KERNEL, q->node);
if (!cfqd) {
kobject_put(&eq->kobj);
return -ENOMEM;
}
eq->elevator_data = cfqd;
cfqd->queue = q;
spin_lock_irq(q->queue_lock);
q->elevator = eq;
spin_unlock_irq(q->queue_lock);
cfqd->grp_service_tree = CFQ_RB_ROOT;
#ifdef CONFIG_CFQ_GROUP_IOSCHED
ret = blkcg_activate_policy(q, &blkcg_policy_cfq);
if (ret)
goto out_free;
cfqd->root_group = blkg_to_cfqg(q->root_blkg);
#else
ret = -ENOMEM;
cfqd->root_group = kzalloc_node(sizeof(*cfqd->root_group),
GFP_KERNEL, cfqd->queue->node);
if (!cfqd->root_group)
goto out_free;
cfq_init_cfqg_base(cfqd->root_group);
cfqd->root_group->weight = 2 * CFQ_WEIGHT_LEGACY_DFL;
cfqd->root_group->leaf_weight = 2 * CFQ_WEIGHT_LEGACY_DFL;
#endif
for (i = 0; i < CFQ_PRIO_LISTS; i++)
cfqd->prio_trees[i] = RB_ROOT;
cfq_init_cfqq(cfqd, &cfqd->oom_cfqq, 1, 0);
cfqd->oom_cfqq.ref++;
spin_lock_irq(q->queue_lock);
cfq_link_cfqq_cfqg(&cfqd->oom_cfqq, cfqd->root_group);
cfqg_put(cfqd->root_group);
spin_unlock_irq(q->queue_lock);
hrtimer_init(&cfqd->idle_slice_timer, CLOCK_MONOTONIC,
HRTIMER_MODE_REL);
cfqd->idle_slice_timer.function = cfq_idle_slice_timer;
INIT_WORK(&cfqd->unplug_work, cfq_kick_queue);
cfqd->cfq_quantum = cfq_quantum;
cfqd->cfq_fifo_expire[0] = cfq_fifo_expire[0];
cfqd->cfq_fifo_expire[1] = cfq_fifo_expire[1];
cfqd->cfq_back_max = cfq_back_max;
cfqd->cfq_back_penalty = cfq_back_penalty;
cfqd->cfq_slice[0] = cfq_slice_async;
cfqd->cfq_slice[1] = cfq_slice_sync;
cfqd->cfq_target_latency = cfq_target_latency;
cfqd->cfq_slice_async_rq = cfq_slice_async_rq;
cfqd->cfq_slice_idle = cfq_slice_idle;
cfqd->cfq_group_idle = cfq_group_idle;
cfqd->cfq_latency = 1;
cfqd->hw_tag = -1;
cfqd->last_delayed_sync = ktime_get_ns() - NSEC_PER_SEC;
return 0;
out_free:
kfree(cfqd);
kobject_put(&eq->kobj);
return ret;
}
static void cfq_registered_queue(struct request_queue *q)
{
struct elevator_queue *e = q->elevator;
struct cfq_data *cfqd = e->elevator_data;
if (blk_queue_nonrot(q))
cfqd->cfq_slice_idle = 0;
wbt_disable_default(q);
}
static ssize_t
cfq_var_show(unsigned int var, char *page)
{
return sprintf(page, "%u\n", var);
}
static void
cfq_var_store(unsigned int *var, const char *page)
{
char *p = (char *) page;
*var = simple_strtoul(p, &p, 10);
}
static int __init cfq_init(void)
{
int ret;
#ifdef CONFIG_CFQ_GROUP_IOSCHED
ret = blkcg_policy_register(&blkcg_policy_cfq);
if (ret)
return ret;
#else
cfq_group_idle = 0;
#endif
ret = -ENOMEM;
cfq_pool = KMEM_CACHE(cfq_queue, 0);
if (!cfq_pool)
goto err_pol_unreg;
ret = elv_register(&iosched_cfq);
if (ret)
goto err_free_pool;
return 0;
err_free_pool:
kmem_cache_destroy(cfq_pool);
err_pol_unreg:
#ifdef CONFIG_CFQ_GROUP_IOSCHED
blkcg_policy_unregister(&blkcg_policy_cfq);
#endif
return ret;
}
static void __exit cfq_exit(void)
{
#ifdef CONFIG_CFQ_GROUP_IOSCHED
blkcg_policy_unregister(&blkcg_policy_cfq);
#endif
elv_unregister(&iosched_cfq);
kmem_cache_destroy(cfq_pool);
}
