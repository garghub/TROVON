static void bfqg_stats_update_group_wait_time(struct bfqg_stats *stats)
{
unsigned long long now;
if (!bfqg_stats_waiting(stats))
return;
now = sched_clock();
if (time_after64(now, stats->start_group_wait_time))
blkg_stat_add(&stats->group_wait_time,
now - stats->start_group_wait_time);
bfqg_stats_clear_waiting(stats);
}
static void bfqg_stats_set_start_group_wait_time(struct bfq_group *bfqg,
struct bfq_group *curr_bfqg)
{
struct bfqg_stats *stats = &bfqg->stats;
if (bfqg_stats_waiting(stats))
return;
if (bfqg == curr_bfqg)
return;
stats->start_group_wait_time = sched_clock();
bfqg_stats_mark_waiting(stats);
}
static void bfqg_stats_end_empty_time(struct bfqg_stats *stats)
{
unsigned long long now;
if (!bfqg_stats_empty(stats))
return;
now = sched_clock();
if (time_after64(now, stats->start_empty_time))
blkg_stat_add(&stats->empty_time,
now - stats->start_empty_time);
bfqg_stats_clear_empty(stats);
}
void bfqg_stats_update_dequeue(struct bfq_group *bfqg)
{
blkg_stat_add(&bfqg->stats.dequeue, 1);
}
void bfqg_stats_set_start_empty_time(struct bfq_group *bfqg)
{
struct bfqg_stats *stats = &bfqg->stats;
if (blkg_rwstat_total(&stats->queued))
return;
if (bfqg_stats_empty(stats))
return;
stats->start_empty_time = sched_clock();
bfqg_stats_mark_empty(stats);
}
void bfqg_stats_update_idle_time(struct bfq_group *bfqg)
{
struct bfqg_stats *stats = &bfqg->stats;
if (bfqg_stats_idling(stats)) {
unsigned long long now = sched_clock();
if (time_after64(now, stats->start_idle_time))
blkg_stat_add(&stats->idle_time,
now - stats->start_idle_time);
bfqg_stats_clear_idling(stats);
}
}
void bfqg_stats_set_start_idle_time(struct bfq_group *bfqg)
{
struct bfqg_stats *stats = &bfqg->stats;
stats->start_idle_time = sched_clock();
bfqg_stats_mark_idling(stats);
}
void bfqg_stats_update_avg_queue_size(struct bfq_group *bfqg)
{
struct bfqg_stats *stats = &bfqg->stats;
blkg_stat_add(&stats->avg_queue_size_sum,
blkg_rwstat_total(&stats->queued));
blkg_stat_add(&stats->avg_queue_size_samples, 1);
bfqg_stats_update_group_wait_time(stats);
}
static struct bfq_group *pd_to_bfqg(struct blkg_policy_data *pd)
{
return pd ? container_of(pd, struct bfq_group, pd) : NULL;
}
struct blkcg_gq *bfqg_to_blkg(struct bfq_group *bfqg)
{
return pd_to_blkg(&bfqg->pd);
}
static struct bfq_group *blkg_to_bfqg(struct blkcg_gq *blkg)
{
return pd_to_bfqg(blkg_to_pd(blkg, &blkcg_policy_bfq));
}
static struct bfq_group *bfqg_parent(struct bfq_group *bfqg)
{
struct blkcg_gq *pblkg = bfqg_to_blkg(bfqg)->parent;
return pblkg ? blkg_to_bfqg(pblkg) : NULL;
}
struct bfq_group *bfqq_group(struct bfq_queue *bfqq)
{
struct bfq_entity *group_entity = bfqq->entity.parent;
return group_entity ? container_of(group_entity, struct bfq_group,
entity) :
bfqq->bfqd->root_group;
}
static void bfqg_get(struct bfq_group *bfqg)
{
bfqg->ref++;
}
void bfqg_put(struct bfq_group *bfqg)
{
bfqg->ref--;
if (bfqg->ref == 0)
kfree(bfqg);
}
static void bfqg_and_blkg_get(struct bfq_group *bfqg)
{
bfqg_get(bfqg);
blkg_get(bfqg_to_blkg(bfqg));
}
void bfqg_and_blkg_put(struct bfq_group *bfqg)
{
bfqg_put(bfqg);
blkg_put(bfqg_to_blkg(bfqg));
}
void bfqg_stats_update_io_add(struct bfq_group *bfqg, struct bfq_queue *bfqq,
unsigned int op)
{
blkg_rwstat_add(&bfqg->stats.queued, op, 1);
bfqg_stats_end_empty_time(&bfqg->stats);
if (!(bfqq == ((struct bfq_data *)bfqg->bfqd)->in_service_queue))
bfqg_stats_set_start_group_wait_time(bfqg, bfqq_group(bfqq));
}
void bfqg_stats_update_io_remove(struct bfq_group *bfqg, unsigned int op)
{
blkg_rwstat_add(&bfqg->stats.queued, op, -1);
}
void bfqg_stats_update_io_merged(struct bfq_group *bfqg, unsigned int op)
{
blkg_rwstat_add(&bfqg->stats.merged, op, 1);
}
void bfqg_stats_update_completion(struct bfq_group *bfqg, uint64_t start_time,
uint64_t io_start_time, unsigned int op)
{
struct bfqg_stats *stats = &bfqg->stats;
unsigned long long now = sched_clock();
if (time_after64(now, io_start_time))
blkg_rwstat_add(&stats->service_time, op,
now - io_start_time);
if (time_after64(io_start_time, start_time))
blkg_rwstat_add(&stats->wait_time, op,
io_start_time - start_time);
}
static void bfqg_stats_reset(struct bfqg_stats *stats)
{
blkg_rwstat_reset(&stats->merged);
blkg_rwstat_reset(&stats->service_time);
blkg_rwstat_reset(&stats->wait_time);
blkg_stat_reset(&stats->time);
blkg_stat_reset(&stats->avg_queue_size_sum);
blkg_stat_reset(&stats->avg_queue_size_samples);
blkg_stat_reset(&stats->dequeue);
blkg_stat_reset(&stats->group_wait_time);
blkg_stat_reset(&stats->idle_time);
blkg_stat_reset(&stats->empty_time);
}
static void bfqg_stats_add_aux(struct bfqg_stats *to, struct bfqg_stats *from)
{
if (!to || !from)
return;
blkg_rwstat_add_aux(&to->merged, &from->merged);
blkg_rwstat_add_aux(&to->service_time, &from->service_time);
blkg_rwstat_add_aux(&to->wait_time, &from->wait_time);
blkg_stat_add_aux(&from->time, &from->time);
blkg_stat_add_aux(&to->avg_queue_size_sum, &from->avg_queue_size_sum);
blkg_stat_add_aux(&to->avg_queue_size_samples,
&from->avg_queue_size_samples);
blkg_stat_add_aux(&to->dequeue, &from->dequeue);
blkg_stat_add_aux(&to->group_wait_time, &from->group_wait_time);
blkg_stat_add_aux(&to->idle_time, &from->idle_time);
blkg_stat_add_aux(&to->empty_time, &from->empty_time);
}
static void bfqg_stats_xfer_dead(struct bfq_group *bfqg)
{
struct bfq_group *parent;
if (!bfqg)
return;
parent = bfqg_parent(bfqg);
lockdep_assert_held(bfqg_to_blkg(bfqg)->q->queue_lock);
if (unlikely(!parent))
return;
bfqg_stats_add_aux(&parent->stats, &bfqg->stats);
bfqg_stats_reset(&bfqg->stats);
}
void bfq_init_entity(struct bfq_entity *entity, struct bfq_group *bfqg)
{
struct bfq_queue *bfqq = bfq_entity_to_bfqq(entity);
entity->weight = entity->new_weight;
entity->orig_weight = entity->new_weight;
if (bfqq) {
bfqq->ioprio = bfqq->new_ioprio;
bfqq->ioprio_class = bfqq->new_ioprio_class;
bfqg_and_blkg_get(bfqg);
}
entity->parent = bfqg->my_entity;
entity->sched_data = &bfqg->sched_data;
}
static void bfqg_stats_exit(struct bfqg_stats *stats)
{
blkg_rwstat_exit(&stats->merged);
blkg_rwstat_exit(&stats->service_time);
blkg_rwstat_exit(&stats->wait_time);
blkg_rwstat_exit(&stats->queued);
blkg_stat_exit(&stats->time);
blkg_stat_exit(&stats->avg_queue_size_sum);
blkg_stat_exit(&stats->avg_queue_size_samples);
blkg_stat_exit(&stats->dequeue);
blkg_stat_exit(&stats->group_wait_time);
blkg_stat_exit(&stats->idle_time);
blkg_stat_exit(&stats->empty_time);
}
static int bfqg_stats_init(struct bfqg_stats *stats, gfp_t gfp)
{
if (blkg_rwstat_init(&stats->merged, gfp) ||
blkg_rwstat_init(&stats->service_time, gfp) ||
blkg_rwstat_init(&stats->wait_time, gfp) ||
blkg_rwstat_init(&stats->queued, gfp) ||
blkg_stat_init(&stats->time, gfp) ||
blkg_stat_init(&stats->avg_queue_size_sum, gfp) ||
blkg_stat_init(&stats->avg_queue_size_samples, gfp) ||
blkg_stat_init(&stats->dequeue, gfp) ||
blkg_stat_init(&stats->group_wait_time, gfp) ||
blkg_stat_init(&stats->idle_time, gfp) ||
blkg_stat_init(&stats->empty_time, gfp)) {
bfqg_stats_exit(stats);
return -ENOMEM;
}
return 0;
}
static struct bfq_group_data *cpd_to_bfqgd(struct blkcg_policy_data *cpd)
{
return cpd ? container_of(cpd, struct bfq_group_data, pd) : NULL;
}
static struct bfq_group_data *blkcg_to_bfqgd(struct blkcg *blkcg)
{
return cpd_to_bfqgd(blkcg_to_cpd(blkcg, &blkcg_policy_bfq));
}
struct blkcg_policy_data *bfq_cpd_alloc(gfp_t gfp)
{
struct bfq_group_data *bgd;
bgd = kzalloc(sizeof(*bgd), gfp);
if (!bgd)
return NULL;
return &bgd->pd;
}
void bfq_cpd_init(struct blkcg_policy_data *cpd)
{
struct bfq_group_data *d = cpd_to_bfqgd(cpd);
d->weight = cgroup_subsys_on_dfl(io_cgrp_subsys) ?
CGROUP_WEIGHT_DFL : BFQ_WEIGHT_LEGACY_DFL;
}
void bfq_cpd_free(struct blkcg_policy_data *cpd)
{
kfree(cpd_to_bfqgd(cpd));
}
struct blkg_policy_data *bfq_pd_alloc(gfp_t gfp, int node)
{
struct bfq_group *bfqg;
bfqg = kzalloc_node(sizeof(*bfqg), gfp, node);
if (!bfqg)
return NULL;
if (bfqg_stats_init(&bfqg->stats, gfp)) {
kfree(bfqg);
return NULL;
}
bfqg_get(bfqg);
return &bfqg->pd;
}
void bfq_pd_init(struct blkg_policy_data *pd)
{
struct blkcg_gq *blkg = pd_to_blkg(pd);
struct bfq_group *bfqg = blkg_to_bfqg(blkg);
struct bfq_data *bfqd = blkg->q->elevator->elevator_data;
struct bfq_entity *entity = &bfqg->entity;
struct bfq_group_data *d = blkcg_to_bfqgd(blkg->blkcg);
entity->orig_weight = entity->weight = entity->new_weight = d->weight;
entity->my_sched_data = &bfqg->sched_data;
bfqg->my_entity = entity;
bfqg->bfqd = bfqd;
bfqg->active_entities = 0;
bfqg->rq_pos_tree = RB_ROOT;
}
void bfq_pd_free(struct blkg_policy_data *pd)
{
struct bfq_group *bfqg = pd_to_bfqg(pd);
bfqg_stats_exit(&bfqg->stats);
bfqg_put(bfqg);
}
void bfq_pd_reset_stats(struct blkg_policy_data *pd)
{
struct bfq_group *bfqg = pd_to_bfqg(pd);
bfqg_stats_reset(&bfqg->stats);
}
static void bfq_group_set_parent(struct bfq_group *bfqg,
struct bfq_group *parent)
{
struct bfq_entity *entity;
entity = &bfqg->entity;
entity->parent = parent->my_entity;
entity->sched_data = &parent->sched_data;
}
static struct bfq_group *bfq_lookup_bfqg(struct bfq_data *bfqd,
struct blkcg *blkcg)
{
struct blkcg_gq *blkg;
blkg = blkg_lookup(blkcg, bfqd->queue);
if (likely(blkg))
return blkg_to_bfqg(blkg);
return NULL;
}
struct bfq_group *bfq_find_set_group(struct bfq_data *bfqd,
struct blkcg *blkcg)
{
struct bfq_group *bfqg, *parent;
struct bfq_entity *entity;
bfqg = bfq_lookup_bfqg(bfqd, blkcg);
if (unlikely(!bfqg))
return NULL;
entity = &bfqg->entity;
for_each_entity(entity) {
bfqg = container_of(entity, struct bfq_group, entity);
if (bfqg != bfqd->root_group) {
parent = bfqg_parent(bfqg);
if (!parent)
parent = bfqd->root_group;
bfq_group_set_parent(bfqg, parent);
}
}
return bfqg;
}
void bfq_bfqq_move(struct bfq_data *bfqd, struct bfq_queue *bfqq,
struct bfq_group *bfqg)
{
struct bfq_entity *entity = &bfqq->entity;
if (bfqq == bfqd->in_service_queue)
bfq_bfqq_expire(bfqd, bfqd->in_service_queue,
false, BFQQE_PREEMPTED);
if (bfq_bfqq_busy(bfqq))
bfq_deactivate_bfqq(bfqd, bfqq, false, false);
else if (entity->on_st)
bfq_put_idle_entity(bfq_entity_service_tree(entity), entity);
bfqg_and_blkg_put(bfqq_group(bfqq));
entity->parent = bfqg->my_entity;
entity->sched_data = &bfqg->sched_data;
bfqg_and_blkg_get(bfqg);
if (bfq_bfqq_busy(bfqq)) {
bfq_pos_tree_add_move(bfqd, bfqq);
bfq_activate_bfqq(bfqd, bfqq);
}
if (!bfqd->in_service_queue && !bfqd->rq_in_driver)
bfq_schedule_dispatch(bfqd);
}
static struct bfq_group *__bfq_bic_change_cgroup(struct bfq_data *bfqd,
struct bfq_io_cq *bic,
struct blkcg *blkcg)
{
struct bfq_queue *async_bfqq = bic_to_bfqq(bic, 0);
struct bfq_queue *sync_bfqq = bic_to_bfqq(bic, 1);
struct bfq_group *bfqg;
struct bfq_entity *entity;
bfqg = bfq_find_set_group(bfqd, blkcg);
if (unlikely(!bfqg))
bfqg = bfqd->root_group;
if (async_bfqq) {
entity = &async_bfqq->entity;
if (entity->sched_data != &bfqg->sched_data) {
bic_set_bfqq(bic, NULL, 0);
bfq_log_bfqq(bfqd, async_bfqq,
"bic_change_group: %p %d",
async_bfqq, async_bfqq->ref);
bfq_put_queue(async_bfqq);
}
}
if (sync_bfqq) {
entity = &sync_bfqq->entity;
if (entity->sched_data != &bfqg->sched_data)
bfq_bfqq_move(bfqd, sync_bfqq, bfqg);
}
return bfqg;
}
void bfq_bic_update_cgroup(struct bfq_io_cq *bic, struct bio *bio)
{
struct bfq_data *bfqd = bic_to_bfqd(bic);
struct bfq_group *bfqg = NULL;
uint64_t serial_nr;
rcu_read_lock();
serial_nr = bio_blkcg(bio)->css.serial_nr;
if (unlikely(!bfqd) || likely(bic->blkcg_serial_nr == serial_nr))
goto out;
bfqg = __bfq_bic_change_cgroup(bfqd, bic, bio_blkcg(bio));
blkg_path(bfqg_to_blkg(bfqg), bfqg->blkg_path, sizeof(bfqg->blkg_path));
bic->blkcg_serial_nr = serial_nr;
out:
rcu_read_unlock();
}
static void bfq_flush_idle_tree(struct bfq_service_tree *st)
{
struct bfq_entity *entity = st->first_idle;
for (; entity ; entity = st->first_idle)
__bfq_deactivate_entity(entity, false);
}
static void bfq_reparent_leaf_entity(struct bfq_data *bfqd,
struct bfq_entity *entity)
{
struct bfq_queue *bfqq = bfq_entity_to_bfqq(entity);
bfq_bfqq_move(bfqd, bfqq, bfqd->root_group);
}
static void bfq_reparent_active_entities(struct bfq_data *bfqd,
struct bfq_group *bfqg,
struct bfq_service_tree *st)
{
struct rb_root *active = &st->active;
struct bfq_entity *entity = NULL;
if (!RB_EMPTY_ROOT(&st->active))
entity = bfq_entity_of(rb_first(active));
for (; entity ; entity = bfq_entity_of(rb_first(active)))
bfq_reparent_leaf_entity(bfqd, entity);
if (bfqg->sched_data.in_service_entity)
bfq_reparent_leaf_entity(bfqd,
bfqg->sched_data.in_service_entity);
}
void bfq_pd_offline(struct blkg_policy_data *pd)
{
struct bfq_service_tree *st;
struct bfq_group *bfqg = pd_to_bfqg(pd);
struct bfq_data *bfqd = bfqg->bfqd;
struct bfq_entity *entity = bfqg->my_entity;
unsigned long flags;
int i;
if (!entity)
return;
spin_lock_irqsave(&bfqd->lock, flags);
for (i = 0; i < BFQ_IOPRIO_CLASSES; i++) {
st = bfqg->sched_data.service_tree + i;
bfq_flush_idle_tree(st);
bfq_reparent_active_entities(bfqd, bfqg, st);
}
__bfq_deactivate_entity(entity, false);
bfq_put_async_queues(bfqd, bfqg);
spin_unlock_irqrestore(&bfqd->lock, flags);
bfqg_stats_xfer_dead(bfqg);
}
void bfq_end_wr_async(struct bfq_data *bfqd)
{
struct blkcg_gq *blkg;
list_for_each_entry(blkg, &bfqd->queue->blkg_list, q_node) {
struct bfq_group *bfqg = blkg_to_bfqg(blkg);
bfq_end_wr_async_queues(bfqd, bfqg);
}
bfq_end_wr_async_queues(bfqd, bfqd->root_group);
}
static int bfq_io_show_weight(struct seq_file *sf, void *v)
{
struct blkcg *blkcg = css_to_blkcg(seq_css(sf));
struct bfq_group_data *bfqgd = blkcg_to_bfqgd(blkcg);
unsigned int val = 0;
if (bfqgd)
val = bfqgd->weight;
seq_printf(sf, "%u\n", val);
return 0;
}
static int bfq_io_set_weight_legacy(struct cgroup_subsys_state *css,
struct cftype *cftype,
u64 val)
{
struct blkcg *blkcg = css_to_blkcg(css);
struct bfq_group_data *bfqgd = blkcg_to_bfqgd(blkcg);
struct blkcg_gq *blkg;
int ret = -ERANGE;
if (val < BFQ_MIN_WEIGHT || val > BFQ_MAX_WEIGHT)
return ret;
ret = 0;
spin_lock_irq(&blkcg->lock);
bfqgd->weight = (unsigned short)val;
hlist_for_each_entry(blkg, &blkcg->blkg_list, blkcg_node) {
struct bfq_group *bfqg = blkg_to_bfqg(blkg);
if (!bfqg)
continue;
if ((unsigned short)val != bfqg->entity.new_weight) {
bfqg->entity.new_weight = (unsigned short)val;
smp_wmb();
bfqg->entity.prio_changed = 1;
}
}
spin_unlock_irq(&blkcg->lock);
return ret;
}
static ssize_t bfq_io_set_weight(struct kernfs_open_file *of,
char *buf, size_t nbytes,
loff_t off)
{
u64 weight;
int ret = kstrtoull(strim(buf), 0, &weight);
if (ret)
return ret;
return bfq_io_set_weight_legacy(of_css(of), NULL, weight);
}
static int bfqg_print_stat(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)), blkg_prfill_stat,
&blkcg_policy_bfq, seq_cft(sf)->private, false);
return 0;
}
static int bfqg_print_rwstat(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)), blkg_prfill_rwstat,
&blkcg_policy_bfq, seq_cft(sf)->private, true);
return 0;
}
static u64 bfqg_prfill_stat_recursive(struct seq_file *sf,
struct blkg_policy_data *pd, int off)
{
u64 sum = blkg_stat_recursive_sum(pd_to_blkg(pd),
&blkcg_policy_bfq, off);
return __blkg_prfill_u64(sf, pd, sum);
}
static u64 bfqg_prfill_rwstat_recursive(struct seq_file *sf,
struct blkg_policy_data *pd, int off)
{
struct blkg_rwstat sum = blkg_rwstat_recursive_sum(pd_to_blkg(pd),
&blkcg_policy_bfq,
off);
return __blkg_prfill_rwstat(sf, pd, &sum);
}
static int bfqg_print_stat_recursive(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)),
bfqg_prfill_stat_recursive, &blkcg_policy_bfq,
seq_cft(sf)->private, false);
return 0;
}
static int bfqg_print_rwstat_recursive(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)),
bfqg_prfill_rwstat_recursive, &blkcg_policy_bfq,
seq_cft(sf)->private, true);
return 0;
}
static u64 bfqg_prfill_sectors(struct seq_file *sf, struct blkg_policy_data *pd,
int off)
{
u64 sum = blkg_rwstat_total(&pd->blkg->stat_bytes);
return __blkg_prfill_u64(sf, pd, sum >> 9);
}
static int bfqg_print_stat_sectors(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)),
bfqg_prfill_sectors, &blkcg_policy_bfq, 0, false);
return 0;
}
static u64 bfqg_prfill_sectors_recursive(struct seq_file *sf,
struct blkg_policy_data *pd, int off)
{
struct blkg_rwstat tmp = blkg_rwstat_recursive_sum(pd->blkg, NULL,
offsetof(struct blkcg_gq, stat_bytes));
u64 sum = atomic64_read(&tmp.aux_cnt[BLKG_RWSTAT_READ]) +
atomic64_read(&tmp.aux_cnt[BLKG_RWSTAT_WRITE]);
return __blkg_prfill_u64(sf, pd, sum >> 9);
}
static int bfqg_print_stat_sectors_recursive(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)),
bfqg_prfill_sectors_recursive, &blkcg_policy_bfq, 0,
false);
return 0;
}
static u64 bfqg_prfill_avg_queue_size(struct seq_file *sf,
struct blkg_policy_data *pd, int off)
{
struct bfq_group *bfqg = pd_to_bfqg(pd);
u64 samples = blkg_stat_read(&bfqg->stats.avg_queue_size_samples);
u64 v = 0;
if (samples) {
v = blkg_stat_read(&bfqg->stats.avg_queue_size_sum);
v = div64_u64(v, samples);
}
__blkg_prfill_u64(sf, pd, v);
return 0;
}
static int bfqg_print_avg_queue_size(struct seq_file *sf, void *v)
{
blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)),
bfqg_prfill_avg_queue_size, &blkcg_policy_bfq,
0, false);
return 0;
}
struct bfq_group *bfq_create_group_hierarchy(struct bfq_data *bfqd, int node)
{
int ret;
ret = blkcg_activate_policy(bfqd->queue, &blkcg_policy_bfq);
if (ret)
return NULL;
return blkg_to_bfqg(bfqd->queue->root_blkg);
}
void bfqg_stats_update_io_add(struct bfq_group *bfqg, struct bfq_queue *bfqq,
unsigned int op) { }
void bfqg_stats_update_io_remove(struct bfq_group *bfqg, unsigned int op) { }
void bfqg_stats_update_io_merged(struct bfq_group *bfqg, unsigned int op) { }
void bfqg_stats_update_completion(struct bfq_group *bfqg, uint64_t start_time,
uint64_t io_start_time, unsigned int op) { }
void bfqg_stats_update_dequeue(struct bfq_group *bfqg) { }
void bfqg_stats_set_start_empty_time(struct bfq_group *bfqg) { }
void bfqg_stats_update_idle_time(struct bfq_group *bfqg) { }
void bfqg_stats_set_start_idle_time(struct bfq_group *bfqg) { }
void bfqg_stats_update_avg_queue_size(struct bfq_group *bfqg) { }
void bfq_bfqq_move(struct bfq_data *bfqd, struct bfq_queue *bfqq,
struct bfq_group *bfqg) {}
void bfq_init_entity(struct bfq_entity *entity, struct bfq_group *bfqg)
{
struct bfq_queue *bfqq = bfq_entity_to_bfqq(entity);
entity->weight = entity->new_weight;
entity->orig_weight = entity->new_weight;
if (bfqq) {
bfqq->ioprio = bfqq->new_ioprio;
bfqq->ioprio_class = bfqq->new_ioprio_class;
}
entity->sched_data = &bfqg->sched_data;
}
void bfq_bic_update_cgroup(struct bfq_io_cq *bic, struct bio *bio) {}
void bfq_end_wr_async(struct bfq_data *bfqd)
{
bfq_end_wr_async_queues(bfqd, bfqd->root_group);
}
struct bfq_group *bfq_find_set_group(struct bfq_data *bfqd, struct blkcg *blkcg)
{
return bfqd->root_group;
}
struct bfq_group *bfqq_group(struct bfq_queue *bfqq)
{
return bfqq->bfqd->root_group;
}
struct bfq_group *bfq_create_group_hierarchy(struct bfq_data *bfqd, int node)
{
struct bfq_group *bfqg;
int i;
bfqg = kmalloc_node(sizeof(*bfqg), GFP_KERNEL | __GFP_ZERO, node);
if (!bfqg)
return NULL;
for (i = 0; i < BFQ_IOPRIO_CLASSES; i++)
bfqg->sched_data.service_tree[i] = BFQ_SERVICE_TREE_INIT;
return bfqg;
}
