struct bfq_queue *bic_to_bfqq(struct bfq_io_cq *bic, bool is_sync)
{
return bic->bfqq[is_sync];
}
void bic_set_bfqq(struct bfq_io_cq *bic, struct bfq_queue *bfqq, bool is_sync)
{
bic->bfqq[is_sync] = bfqq;
}
struct bfq_data *bic_to_bfqd(struct bfq_io_cq *bic)
{
return bic->icq.q->elevator->elevator_data;
}
static struct bfq_io_cq *icq_to_bic(struct io_cq *icq)
{
return container_of(icq, struct bfq_io_cq, icq);
}
static struct bfq_io_cq *bfq_bic_lookup(struct bfq_data *bfqd,
struct io_context *ioc,
struct request_queue *q)
{
if (ioc) {
unsigned long flags;
struct bfq_io_cq *icq;
spin_lock_irqsave(q->queue_lock, flags);
icq = icq_to_bic(ioc_lookup_icq(ioc, q));
spin_unlock_irqrestore(q->queue_lock, flags);
return icq;
}
return NULL;
}
void bfq_schedule_dispatch(struct bfq_data *bfqd)
{
if (bfqd->queued != 0) {
bfq_log(bfqd, "schedule dispatch");
blk_mq_run_hw_queues(bfqd->queue, true);
}
}
static struct request *bfq_choose_req(struct bfq_data *bfqd,
struct request *rq1,
struct request *rq2,
sector_t last)
{
sector_t s1, s2, d1 = 0, d2 = 0;
unsigned long back_max;
#define BFQ_RQ1_WRAP 0x01
#define BFQ_RQ2_WRAP 0x02
unsigned int wrap = 0;
if (!rq1 || rq1 == rq2)
return rq2;
if (!rq2)
return rq1;
if (rq_is_sync(rq1) && !rq_is_sync(rq2))
return rq1;
else if (rq_is_sync(rq2) && !rq_is_sync(rq1))
return rq2;
if ((rq1->cmd_flags & REQ_META) && !(rq2->cmd_flags & REQ_META))
return rq1;
else if ((rq2->cmd_flags & REQ_META) && !(rq1->cmd_flags & REQ_META))
return rq2;
s1 = blk_rq_pos(rq1);
s2 = blk_rq_pos(rq2);
back_max = bfqd->bfq_back_max * 2;
if (s1 >= last)
d1 = s1 - last;
else if (s1 + back_max >= last)
d1 = (last - s1) * bfqd->bfq_back_penalty;
else
wrap |= BFQ_RQ1_WRAP;
if (s2 >= last)
d2 = s2 - last;
else if (s2 + back_max >= last)
d2 = (last - s2) * bfqd->bfq_back_penalty;
else
wrap |= BFQ_RQ2_WRAP;
switch (wrap) {
case 0:
if (d1 < d2)
return rq1;
else if (d2 < d1)
return rq2;
if (s1 >= s2)
return rq1;
else
return rq2;
case BFQ_RQ2_WRAP:
return rq1;
case BFQ_RQ1_WRAP:
return rq2;
case BFQ_RQ1_WRAP|BFQ_RQ2_WRAP:
default:
if (s1 <= s2)
return rq1;
else
return rq2;
}
}
static struct bfq_queue *
bfq_rq_pos_tree_lookup(struct bfq_data *bfqd, struct rb_root *root,
sector_t sector, struct rb_node **ret_parent,
struct rb_node ***rb_link)
{
struct rb_node **p, *parent;
struct bfq_queue *bfqq = NULL;
parent = NULL;
p = &root->rb_node;
while (*p) {
struct rb_node **n;
parent = *p;
bfqq = rb_entry(parent, struct bfq_queue, pos_node);
if (sector > blk_rq_pos(bfqq->next_rq))
n = &(*p)->rb_right;
else if (sector < blk_rq_pos(bfqq->next_rq))
n = &(*p)->rb_left;
else
break;
p = n;
bfqq = NULL;
}
*ret_parent = parent;
if (rb_link)
*rb_link = p;
bfq_log(bfqd, "rq_pos_tree_lookup %llu: returning %d",
(unsigned long long)sector,
bfqq ? bfqq->pid : 0);
return bfqq;
}
void bfq_pos_tree_add_move(struct bfq_data *bfqd, struct bfq_queue *bfqq)
{
struct rb_node **p, *parent;
struct bfq_queue *__bfqq;
if (bfqq->pos_root) {
rb_erase(&bfqq->pos_node, bfqq->pos_root);
bfqq->pos_root = NULL;
}
if (bfq_class_idle(bfqq))
return;
if (!bfqq->next_rq)
return;
bfqq->pos_root = &bfq_bfqq_to_bfqg(bfqq)->rq_pos_tree;
__bfqq = bfq_rq_pos_tree_lookup(bfqd, bfqq->pos_root,
blk_rq_pos(bfqq->next_rq), &parent, &p);
if (!__bfqq) {
rb_link_node(&bfqq->pos_node, parent, p);
rb_insert_color(&bfqq->pos_node, bfqq->pos_root);
} else
bfqq->pos_root = NULL;
}
static bool bfq_differentiated_weights(struct bfq_data *bfqd)
{
return (!RB_EMPTY_ROOT(&bfqd->queue_weights_tree) &&
(bfqd->queue_weights_tree.rb_node->rb_left ||
bfqd->queue_weights_tree.rb_node->rb_right)
#ifdef CONFIG_BFQ_GROUP_IOSCHED
) ||
(!RB_EMPTY_ROOT(&bfqd->group_weights_tree) &&
(bfqd->group_weights_tree.rb_node->rb_left ||
bfqd->group_weights_tree.rb_node->rb_right)
#endif
);
}
static bool bfq_symmetric_scenario(struct bfq_data *bfqd)
{
return !bfq_differentiated_weights(bfqd);
}
void bfq_weights_tree_add(struct bfq_data *bfqd, struct bfq_entity *entity,
struct rb_root *root)
{
struct rb_node **new = &(root->rb_node), *parent = NULL;
if (entity->weight_counter)
return;
while (*new) {
struct bfq_weight_counter *__counter = container_of(*new,
struct bfq_weight_counter,
weights_node);
parent = *new;
if (entity->weight == __counter->weight) {
entity->weight_counter = __counter;
goto inc_counter;
}
if (entity->weight < __counter->weight)
new = &((*new)->rb_left);
else
new = &((*new)->rb_right);
}
entity->weight_counter = kzalloc(sizeof(struct bfq_weight_counter),
GFP_ATOMIC);
if (unlikely(!entity->weight_counter))
return;
entity->weight_counter->weight = entity->weight;
rb_link_node(&entity->weight_counter->weights_node, parent, new);
rb_insert_color(&entity->weight_counter->weights_node, root);
inc_counter:
entity->weight_counter->num_active++;
}
void bfq_weights_tree_remove(struct bfq_data *bfqd, struct bfq_entity *entity,
struct rb_root *root)
{
if (!entity->weight_counter)
return;
entity->weight_counter->num_active--;
if (entity->weight_counter->num_active > 0)
goto reset_entity_pointer;
rb_erase(&entity->weight_counter->weights_node, root);
kfree(entity->weight_counter);
reset_entity_pointer:
entity->weight_counter = NULL;
}
static struct request *bfq_check_fifo(struct bfq_queue *bfqq,
struct request *last)
{
struct request *rq;
if (bfq_bfqq_fifo_expire(bfqq))
return NULL;
bfq_mark_bfqq_fifo_expire(bfqq);
rq = rq_entry_fifo(bfqq->fifo.next);
if (rq == last || ktime_get_ns() < rq->fifo_time)
return NULL;
bfq_log_bfqq(bfqq->bfqd, bfqq, "check_fifo: returned %p", rq);
return rq;
}
static struct request *bfq_find_next_rq(struct bfq_data *bfqd,
struct bfq_queue *bfqq,
struct request *last)
{
struct rb_node *rbnext = rb_next(&last->rb_node);
struct rb_node *rbprev = rb_prev(&last->rb_node);
struct request *next, *prev = NULL;
next = bfq_check_fifo(bfqq, last);
if (next)
return next;
if (rbprev)
prev = rb_entry_rq(rbprev);
if (rbnext)
next = rb_entry_rq(rbnext);
else {
rbnext = rb_first(&bfqq->sort_list);
if (rbnext && rbnext != &last->rb_node)
next = rb_entry_rq(rbnext);
}
return bfq_choose_req(bfqd, next, prev, blk_rq_pos(last));
}
static unsigned long bfq_serv_to_charge(struct request *rq,
struct bfq_queue *bfqq)
{
if (bfq_bfqq_sync(bfqq) || bfqq->wr_coeff > 1)
return blk_rq_sectors(rq);
if (bfqq->bfqd->wr_busy_queues == 0)
return blk_rq_sectors(rq) * bfq_async_charge_factor;
return blk_rq_sectors(rq) * 2 * bfq_async_charge_factor;
}
static void bfq_updated_next_req(struct bfq_data *bfqd,
struct bfq_queue *bfqq)
{
struct bfq_entity *entity = &bfqq->entity;
struct request *next_rq = bfqq->next_rq;
unsigned long new_budget;
if (!next_rq)
return;
if (bfqq == bfqd->in_service_queue)
return;
new_budget = max_t(unsigned long, bfqq->max_budget,
bfq_serv_to_charge(next_rq, bfqq));
if (entity->budget != new_budget) {
entity->budget = new_budget;
bfq_log_bfqq(bfqd, bfqq, "updated next rq: new budget %lu",
new_budget);
bfq_requeue_bfqq(bfqd, bfqq);
}
}
static void
bfq_bfqq_resume_state(struct bfq_queue *bfqq, struct bfq_io_cq *bic)
{
if (bic->saved_idle_window)
bfq_mark_bfqq_idle_window(bfqq);
else
bfq_clear_bfqq_idle_window(bfqq);
if (bic->saved_IO_bound)
bfq_mark_bfqq_IO_bound(bfqq);
else
bfq_clear_bfqq_IO_bound(bfqq);
bfqq->ttime = bic->saved_ttime;
bfqq->wr_coeff = bic->saved_wr_coeff;
bfqq->wr_start_at_switch_to_srt = bic->saved_wr_start_at_switch_to_srt;
bfqq->last_wr_start_finish = bic->saved_last_wr_start_finish;
bfqq->wr_cur_max_time = bic->saved_wr_cur_max_time;
if (bfqq->wr_coeff > 1 && (bfq_bfqq_in_large_burst(bfqq) ||
time_is_before_jiffies(bfqq->last_wr_start_finish +
bfqq->wr_cur_max_time))) {
bfq_log_bfqq(bfqq->bfqd, bfqq,
"resume state: switching off wr");
bfqq->wr_coeff = 1;
}
bfqq->entity.prio_changed = 1;
}
static int bfqq_process_refs(struct bfq_queue *bfqq)
{
return bfqq->ref - bfqq->allocated - bfqq->entity.on_st;
}
static void bfq_reset_burst_list(struct bfq_data *bfqd, struct bfq_queue *bfqq)
{
struct bfq_queue *item;
struct hlist_node *n;
hlist_for_each_entry_safe(item, n, &bfqd->burst_list, burst_list_node)
hlist_del_init(&item->burst_list_node);
hlist_add_head(&bfqq->burst_list_node, &bfqd->burst_list);
bfqd->burst_size = 1;
bfqd->burst_parent_entity = bfqq->entity.parent;
}
static void bfq_add_to_burst(struct bfq_data *bfqd, struct bfq_queue *bfqq)
{
bfqd->burst_size++;
if (bfqd->burst_size == bfqd->bfq_large_burst_thresh) {
struct bfq_queue *pos, *bfqq_item;
struct hlist_node *n;
bfqd->large_burst = true;
hlist_for_each_entry(bfqq_item, &bfqd->burst_list,
burst_list_node)
bfq_mark_bfqq_in_large_burst(bfqq_item);
bfq_mark_bfqq_in_large_burst(bfqq);
hlist_for_each_entry_safe(pos, n, &bfqd->burst_list,
burst_list_node)
hlist_del_init(&pos->burst_list_node);
} else
hlist_add_head(&bfqq->burst_list_node, &bfqd->burst_list);
}
static void bfq_handle_burst(struct bfq_data *bfqd, struct bfq_queue *bfqq)
{
if (!hlist_unhashed(&bfqq->burst_list_node) ||
bfq_bfqq_in_large_burst(bfqq) ||
time_is_after_eq_jiffies(bfqq->split_time +
msecs_to_jiffies(10)))
return;
if (time_is_before_jiffies(bfqd->last_ins_in_burst +
bfqd->bfq_burst_interval) ||
bfqq->entity.parent != bfqd->burst_parent_entity) {
bfqd->large_burst = false;
bfq_reset_burst_list(bfqd, bfqq);
goto end;
}
if (bfqd->large_burst) {
bfq_mark_bfqq_in_large_burst(bfqq);
goto end;
}
bfq_add_to_burst(bfqd, bfqq);
end:
bfqd->last_ins_in_burst = jiffies;
}
static int bfq_bfqq_budget_left(struct bfq_queue *bfqq)
{
struct bfq_entity *entity = &bfqq->entity;
return entity->budget - entity->service;
}
static int bfq_max_budget(struct bfq_data *bfqd)
{
if (bfqd->budgets_assigned < bfq_stats_min_budgets)
return bfq_default_max_budget;
else
return bfqd->bfq_max_budget;
}
static int bfq_min_budget(struct bfq_data *bfqd)
{
if (bfqd->budgets_assigned < bfq_stats_min_budgets)
return bfq_default_max_budget / 32;
else
return bfqd->bfq_max_budget / 32;
}
static bool bfq_bfqq_update_budg_for_activation(struct bfq_data *bfqd,
struct bfq_queue *bfqq,
bool arrived_in_time,
bool wr_or_deserves_wr)
{
struct bfq_entity *entity = &bfqq->entity;
if (bfq_bfqq_non_blocking_wait_rq(bfqq) && arrived_in_time) {
entity->budget = min_t(unsigned long,
bfq_bfqq_budget_left(bfqq),
bfqq->max_budget);
return true;
}
entity->budget = max_t(unsigned long, bfqq->max_budget,
bfq_serv_to_charge(bfqq->next_rq, bfqq));
bfq_clear_bfqq_non_blocking_wait_rq(bfqq);
return wr_or_deserves_wr;
}
static unsigned int bfq_wr_duration(struct bfq_data *bfqd)
{
u64 dur;
if (bfqd->bfq_wr_max_time > 0)
return bfqd->bfq_wr_max_time;
dur = bfqd->RT_prod;
do_div(dur, bfqd->peak_rate);
if (dur > msecs_to_jiffies(13000))
dur = msecs_to_jiffies(13000);
else if (dur < msecs_to_jiffies(3000))
dur = msecs_to_jiffies(3000);
return dur;
}
static void bfq_update_bfqq_wr_on_rq_arrival(struct bfq_data *bfqd,
struct bfq_queue *bfqq,
unsigned int old_wr_coeff,
bool wr_or_deserves_wr,
bool interactive,
bool in_burst,
bool soft_rt)
{
if (old_wr_coeff == 1 && wr_or_deserves_wr) {
if (interactive) {
bfqq->wr_coeff = bfqd->bfq_wr_coeff;
bfqq->wr_cur_max_time = bfq_wr_duration(bfqd);
} else {
bfqq->wr_start_at_switch_to_srt = jiffies;
bfqq->wr_coeff = bfqd->bfq_wr_coeff *
BFQ_SOFTRT_WEIGHT_FACTOR;
bfqq->wr_cur_max_time =
bfqd->bfq_wr_rt_max_time;
}
bfqq->entity.budget = min_t(unsigned long,
bfqq->entity.budget,
2 * bfq_min_budget(bfqd));
} else if (old_wr_coeff > 1) {
if (interactive) {
bfqq->wr_coeff = bfqd->bfq_wr_coeff;
bfqq->wr_cur_max_time = bfq_wr_duration(bfqd);
} else if (in_burst)
bfqq->wr_coeff = 1;
else if (soft_rt) {
if (bfqq->wr_cur_max_time !=
bfqd->bfq_wr_rt_max_time) {
bfqq->wr_start_at_switch_to_srt =
bfqq->last_wr_start_finish;
bfqq->wr_cur_max_time =
bfqd->bfq_wr_rt_max_time;
bfqq->wr_coeff = bfqd->bfq_wr_coeff *
BFQ_SOFTRT_WEIGHT_FACTOR;
}
bfqq->last_wr_start_finish = jiffies;
}
}
}
static bool bfq_bfqq_idle_for_long_time(struct bfq_data *bfqd,
struct bfq_queue *bfqq)
{
return bfqq->dispatched == 0 &&
time_is_before_jiffies(
bfqq->budget_timeout +
bfqd->bfq_wr_min_idle_time);
}
static void bfq_bfqq_handle_idle_busy_switch(struct bfq_data *bfqd,
struct bfq_queue *bfqq,
int old_wr_coeff,
struct request *rq,
bool *interactive)
{
bool soft_rt, in_burst, wr_or_deserves_wr,
bfqq_wants_to_preempt,
idle_for_long_time = bfq_bfqq_idle_for_long_time(bfqd, bfqq),
arrived_in_time = ktime_get_ns() <=
bfqq->ttime.last_end_request +
bfqd->bfq_slice_idle * 3;
bfqg_stats_update_io_add(bfqq_group(RQ_BFQQ(rq)), bfqq, rq->cmd_flags);
in_burst = bfq_bfqq_in_large_burst(bfqq);
soft_rt = bfqd->bfq_wr_max_softrt_rate > 0 &&
!in_burst &&
time_is_before_jiffies(bfqq->soft_rt_next_start);
*interactive = !in_burst && idle_for_long_time;
wr_or_deserves_wr = bfqd->low_latency &&
(bfqq->wr_coeff > 1 ||
(bfq_bfqq_sync(bfqq) &&
bfqq->bic && (*interactive || soft_rt)));
bfqq_wants_to_preempt =
bfq_bfqq_update_budg_for_activation(bfqd, bfqq,
arrived_in_time,
wr_or_deserves_wr);
if (likely(!bfq_bfqq_just_created(bfqq)) &&
idle_for_long_time &&
time_is_before_jiffies(
bfqq->budget_timeout +
msecs_to_jiffies(10000))) {
hlist_del_init(&bfqq->burst_list_node);
bfq_clear_bfqq_in_large_burst(bfqq);
}
bfq_clear_bfqq_just_created(bfqq);
if (!bfq_bfqq_IO_bound(bfqq)) {
if (arrived_in_time) {
bfqq->requests_within_timer++;
if (bfqq->requests_within_timer >=
bfqd->bfq_requests_within_timer)
bfq_mark_bfqq_IO_bound(bfqq);
} else
bfqq->requests_within_timer = 0;
}
if (bfqd->low_latency) {
if (unlikely(time_is_after_jiffies(bfqq->split_time)))
bfqq->split_time =
jiffies - bfqd->bfq_wr_min_idle_time - 1;
if (time_is_before_jiffies(bfqq->split_time +
bfqd->bfq_wr_min_idle_time)) {
bfq_update_bfqq_wr_on_rq_arrival(bfqd, bfqq,
old_wr_coeff,
wr_or_deserves_wr,
*interactive,
in_burst,
soft_rt);
if (old_wr_coeff != bfqq->wr_coeff)
bfqq->entity.prio_changed = 1;
}
}
bfqq->last_idle_bklogged = jiffies;
bfqq->service_from_backlogged = 0;
bfq_clear_bfqq_softrt_update(bfqq);
bfq_add_bfqq_busy(bfqd, bfqq);
if (bfqd->in_service_queue && bfqq_wants_to_preempt &&
bfqd->in_service_queue->wr_coeff < bfqq->wr_coeff &&
next_queue_may_preempt(bfqd))
bfq_bfqq_expire(bfqd, bfqd->in_service_queue,
false, BFQQE_PREEMPTED);
}
static void bfq_add_request(struct request *rq)
{
struct bfq_queue *bfqq = RQ_BFQQ(rq);
struct bfq_data *bfqd = bfqq->bfqd;
struct request *next_rq, *prev;
unsigned int old_wr_coeff = bfqq->wr_coeff;
bool interactive = false;
bfq_log_bfqq(bfqd, bfqq, "add_request %d", rq_is_sync(rq));
bfqq->queued[rq_is_sync(rq)]++;
bfqd->queued++;
elv_rb_add(&bfqq->sort_list, rq);
prev = bfqq->next_rq;
next_rq = bfq_choose_req(bfqd, bfqq->next_rq, rq, bfqd->last_position);
bfqq->next_rq = next_rq;
if (prev != bfqq->next_rq)
bfq_pos_tree_add_move(bfqd, bfqq);
if (!bfq_bfqq_busy(bfqq))
bfq_bfqq_handle_idle_busy_switch(bfqd, bfqq, old_wr_coeff,
rq, &interactive);
else {
if (bfqd->low_latency && old_wr_coeff == 1 && !rq_is_sync(rq) &&
time_is_before_jiffies(
bfqq->last_wr_start_finish +
bfqd->bfq_wr_min_inter_arr_async)) {
bfqq->wr_coeff = bfqd->bfq_wr_coeff;
bfqq->wr_cur_max_time = bfq_wr_duration(bfqd);
bfqd->wr_busy_queues++;
bfqq->entity.prio_changed = 1;
}
if (prev != bfqq->next_rq)
bfq_updated_next_req(bfqd, bfqq);
}
if (bfqd->low_latency &&
(old_wr_coeff == 1 || bfqq->wr_coeff == 1 || interactive))
bfqq->last_wr_start_finish = jiffies;
}
static struct request *bfq_find_rq_fmerge(struct bfq_data *bfqd,
struct bio *bio,
struct request_queue *q)
{
struct bfq_queue *bfqq = bfqd->bio_bfqq;
if (bfqq)
return elv_rb_find(&bfqq->sort_list, bio_end_sector(bio));
return NULL;
}
static sector_t get_sdist(sector_t last_pos, struct request *rq)
{
if (last_pos)
return abs(blk_rq_pos(rq) - last_pos);
return 0;
}
static void bfq_remove_request(struct request_queue *q,
struct request *rq)
{
struct bfq_queue *bfqq = RQ_BFQQ(rq);
struct bfq_data *bfqd = bfqq->bfqd;
const int sync = rq_is_sync(rq);
if (bfqq->next_rq == rq) {
bfqq->next_rq = bfq_find_next_rq(bfqd, bfqq, rq);
bfq_updated_next_req(bfqd, bfqq);
}
if (rq->queuelist.prev != &rq->queuelist)
list_del_init(&rq->queuelist);
bfqq->queued[sync]--;
bfqd->queued--;
elv_rb_del(&bfqq->sort_list, rq);
elv_rqhash_del(q, rq);
if (q->last_merge == rq)
q->last_merge = NULL;
if (RB_EMPTY_ROOT(&bfqq->sort_list)) {
bfqq->next_rq = NULL;
if (bfq_bfqq_busy(bfqq) && bfqq != bfqd->in_service_queue) {
bfq_del_bfqq_busy(bfqd, bfqq, false);
bfqq->entity.budget = bfqq->entity.service = 0;
}
if (bfqq->pos_root) {
rb_erase(&bfqq->pos_node, bfqq->pos_root);
bfqq->pos_root = NULL;
}
}
if (rq->cmd_flags & REQ_META)
bfqq->meta_pending--;
bfqg_stats_update_io_remove(bfqq_group(bfqq), rq->cmd_flags);
}
static bool bfq_bio_merge(struct blk_mq_hw_ctx *hctx, struct bio *bio)
{
struct request_queue *q = hctx->queue;
struct bfq_data *bfqd = q->elevator->elevator_data;
struct request *free = NULL;
struct bfq_io_cq *bic = bfq_bic_lookup(bfqd, current->io_context, q);
bool ret;
spin_lock_irq(&bfqd->lock);
if (bic)
bfqd->bio_bfqq = bic_to_bfqq(bic, op_is_sync(bio->bi_opf));
else
bfqd->bio_bfqq = NULL;
bfqd->bio_bic = bic;
ret = blk_mq_sched_try_merge(q, bio, &free);
if (free)
blk_mq_free_request(free);
spin_unlock_irq(&bfqd->lock);
return ret;
}
static int bfq_request_merge(struct request_queue *q, struct request **req,
struct bio *bio)
{
struct bfq_data *bfqd = q->elevator->elevator_data;
struct request *__rq;
__rq = bfq_find_rq_fmerge(bfqd, bio, q);
if (__rq && elv_bio_merge_ok(__rq, bio)) {
*req = __rq;
return ELEVATOR_FRONT_MERGE;
}
return ELEVATOR_NO_MERGE;
}
static void bfq_request_merged(struct request_queue *q, struct request *req,
enum elv_merge type)
{
if (type == ELEVATOR_FRONT_MERGE &&
rb_prev(&req->rb_node) &&
blk_rq_pos(req) <
blk_rq_pos(container_of(rb_prev(&req->rb_node),
struct request, rb_node))) {
struct bfq_queue *bfqq = RQ_BFQQ(req);
struct bfq_data *bfqd = bfqq->bfqd;
struct request *prev, *next_rq;
elv_rb_del(&bfqq->sort_list, req);
elv_rb_add(&bfqq->sort_list, req);
prev = bfqq->next_rq;
next_rq = bfq_choose_req(bfqd, bfqq->next_rq, req,
bfqd->last_position);
bfqq->next_rq = next_rq;
if (prev != bfqq->next_rq) {
bfq_updated_next_req(bfqd, bfqq);
bfq_pos_tree_add_move(bfqd, bfqq);
}
}
}
static void bfq_requests_merged(struct request_queue *q, struct request *rq,
struct request *next)
{
struct bfq_queue *bfqq = RQ_BFQQ(rq), *next_bfqq = RQ_BFQQ(next);
if (!RB_EMPTY_NODE(&rq->rb_node))
goto end;
spin_lock_irq(&bfqq->bfqd->lock);
if (bfqq == next_bfqq &&
!list_empty(&rq->queuelist) && !list_empty(&next->queuelist) &&
next->fifo_time < rq->fifo_time) {
list_del_init(&rq->queuelist);
list_replace_init(&next->queuelist, &rq->queuelist);
rq->fifo_time = next->fifo_time;
}
if (bfqq->next_rq == next)
bfqq->next_rq = rq;
bfq_remove_request(q, next);
spin_unlock_irq(&bfqq->bfqd->lock);
end:
bfqg_stats_update_io_merged(bfqq_group(bfqq), next->cmd_flags);
}
static void bfq_bfqq_end_wr(struct bfq_queue *bfqq)
{
if (bfq_bfqq_busy(bfqq))
bfqq->bfqd->wr_busy_queues--;
bfqq->wr_coeff = 1;
bfqq->wr_cur_max_time = 0;
bfqq->last_wr_start_finish = jiffies;
bfqq->entity.prio_changed = 1;
}
void bfq_end_wr_async_queues(struct bfq_data *bfqd,
struct bfq_group *bfqg)
{
int i, j;
for (i = 0; i < 2; i++)
for (j = 0; j < IOPRIO_BE_NR; j++)
if (bfqg->async_bfqq[i][j])
bfq_bfqq_end_wr(bfqg->async_bfqq[i][j]);
if (bfqg->async_idle_bfqq)
bfq_bfqq_end_wr(bfqg->async_idle_bfqq);
}
static void bfq_end_wr(struct bfq_data *bfqd)
{
struct bfq_queue *bfqq;
spin_lock_irq(&bfqd->lock);
list_for_each_entry(bfqq, &bfqd->active_list, bfqq_list)
bfq_bfqq_end_wr(bfqq);
list_for_each_entry(bfqq, &bfqd->idle_list, bfqq_list)
bfq_bfqq_end_wr(bfqq);
bfq_end_wr_async(bfqd);
spin_unlock_irq(&bfqd->lock);
}
static sector_t bfq_io_struct_pos(void *io_struct, bool request)
{
if (request)
return blk_rq_pos(io_struct);
else
return ((struct bio *)io_struct)->bi_iter.bi_sector;
}
static int bfq_rq_close_to_sector(void *io_struct, bool request,
sector_t sector)
{
return abs(bfq_io_struct_pos(io_struct, request) - sector) <=
BFQQ_CLOSE_THR;
}
static struct bfq_queue *bfqq_find_close(struct bfq_data *bfqd,
struct bfq_queue *bfqq,
sector_t sector)
{
struct rb_root *root = &bfq_bfqq_to_bfqg(bfqq)->rq_pos_tree;
struct rb_node *parent, *node;
struct bfq_queue *__bfqq;
if (RB_EMPTY_ROOT(root))
return NULL;
__bfqq = bfq_rq_pos_tree_lookup(bfqd, root, sector, &parent, NULL);
if (__bfqq)
return __bfqq;
__bfqq = rb_entry(parent, struct bfq_queue, pos_node);
if (bfq_rq_close_to_sector(__bfqq->next_rq, true, sector))
return __bfqq;
if (blk_rq_pos(__bfqq->next_rq) < sector)
node = rb_next(&__bfqq->pos_node);
else
node = rb_prev(&__bfqq->pos_node);
if (!node)
return NULL;
__bfqq = rb_entry(node, struct bfq_queue, pos_node);
if (bfq_rq_close_to_sector(__bfqq->next_rq, true, sector))
return __bfqq;
return NULL;
}
static struct bfq_queue *bfq_find_close_cooperator(struct bfq_data *bfqd,
struct bfq_queue *cur_bfqq,
sector_t sector)
{
struct bfq_queue *bfqq;
bfqq = bfqq_find_close(bfqd, cur_bfqq, sector);
if (!bfqq || bfqq == cur_bfqq)
return NULL;
return bfqq;
}
static struct bfq_queue *
bfq_setup_merge(struct bfq_queue *bfqq, struct bfq_queue *new_bfqq)
{
int process_refs, new_process_refs;
struct bfq_queue *__bfqq;
if (!bfqq_process_refs(new_bfqq))
return NULL;
while ((__bfqq = new_bfqq->new_bfqq)) {
if (__bfqq == bfqq)
return NULL;
new_bfqq = __bfqq;
}
process_refs = bfqq_process_refs(bfqq);
new_process_refs = bfqq_process_refs(new_bfqq);
if (process_refs == 0 || new_process_refs == 0)
return NULL;
bfq_log_bfqq(bfqq->bfqd, bfqq, "scheduling merge with queue %d",
new_bfqq->pid);
bfqq->new_bfqq = new_bfqq;
new_bfqq->ref += process_refs;
return new_bfqq;
}
static bool bfq_may_be_close_cooperator(struct bfq_queue *bfqq,
struct bfq_queue *new_bfqq)
{
if (bfq_class_idle(bfqq) || bfq_class_idle(new_bfqq) ||
(bfqq->ioprio_class != new_bfqq->ioprio_class))
return false;
if (BFQQ_SEEKY(bfqq) || BFQQ_SEEKY(new_bfqq))
return false;
if (!bfq_bfqq_sync(bfqq) || !bfq_bfqq_sync(new_bfqq))
return false;
return true;
}
static bool wr_from_too_long(struct bfq_queue *bfqq)
{
return bfqq->wr_coeff > 1 &&
time_is_before_jiffies(bfqq->last_wr_start_finish +
msecs_to_jiffies(100));
}
static struct bfq_queue *
bfq_setup_cooperator(struct bfq_data *bfqd, struct bfq_queue *bfqq,
void *io_struct, bool request)
{
struct bfq_queue *in_service_bfqq, *new_bfqq;
if (bfqq->new_bfqq)
return bfqq->new_bfqq;
if (!io_struct ||
wr_from_too_long(bfqq) ||
unlikely(bfqq == &bfqd->oom_bfqq))
return NULL;
if (bfqd->busy_queues == 1)
return NULL;
in_service_bfqq = bfqd->in_service_queue;
if (!in_service_bfqq || in_service_bfqq == bfqq
|| wr_from_too_long(in_service_bfqq) ||
unlikely(in_service_bfqq == &bfqd->oom_bfqq))
goto check_scheduled;
if (bfq_rq_close_to_sector(io_struct, request, bfqd->last_position) &&
bfqq->entity.parent == in_service_bfqq->entity.parent &&
bfq_may_be_close_cooperator(bfqq, in_service_bfqq)) {
new_bfqq = bfq_setup_merge(bfqq, in_service_bfqq);
if (new_bfqq)
return new_bfqq;
}
check_scheduled:
new_bfqq = bfq_find_close_cooperator(bfqd, bfqq,
bfq_io_struct_pos(io_struct, request));
if (new_bfqq && !wr_from_too_long(new_bfqq) &&
likely(new_bfqq != &bfqd->oom_bfqq) &&
bfq_may_be_close_cooperator(bfqq, new_bfqq))
return bfq_setup_merge(bfqq, new_bfqq);
return NULL;
}
static void bfq_bfqq_save_state(struct bfq_queue *bfqq)
{
struct bfq_io_cq *bic = bfqq->bic;
if (!bic)
return;
bic->saved_ttime = bfqq->ttime;
bic->saved_idle_window = bfq_bfqq_idle_window(bfqq);
bic->saved_IO_bound = bfq_bfqq_IO_bound(bfqq);
bic->saved_in_large_burst = bfq_bfqq_in_large_burst(bfqq);
bic->was_in_burst_list = !hlist_unhashed(&bfqq->burst_list_node);
bic->saved_wr_coeff = bfqq->wr_coeff;
bic->saved_wr_start_at_switch_to_srt = bfqq->wr_start_at_switch_to_srt;
bic->saved_last_wr_start_finish = bfqq->last_wr_start_finish;
bic->saved_wr_cur_max_time = bfqq->wr_cur_max_time;
}
static void
bfq_merge_bfqqs(struct bfq_data *bfqd, struct bfq_io_cq *bic,
struct bfq_queue *bfqq, struct bfq_queue *new_bfqq)
{
bfq_log_bfqq(bfqd, bfqq, "merging with queue %lu",
(unsigned long)new_bfqq->pid);
bfq_bfqq_save_state(bfqq);
bfq_bfqq_save_state(new_bfqq);
if (bfq_bfqq_IO_bound(bfqq))
bfq_mark_bfqq_IO_bound(new_bfqq);
bfq_clear_bfqq_IO_bound(bfqq);
if (new_bfqq->wr_coeff == 1 && bfqq->wr_coeff > 1) {
new_bfqq->wr_coeff = bfqq->wr_coeff;
new_bfqq->wr_cur_max_time = bfqq->wr_cur_max_time;
new_bfqq->last_wr_start_finish = bfqq->last_wr_start_finish;
new_bfqq->wr_start_at_switch_to_srt =
bfqq->wr_start_at_switch_to_srt;
if (bfq_bfqq_busy(new_bfqq))
bfqd->wr_busy_queues++;
new_bfqq->entity.prio_changed = 1;
}
if (bfqq->wr_coeff > 1) {
bfqq->wr_coeff = 1;
bfqq->entity.prio_changed = 1;
if (bfq_bfqq_busy(bfqq))
bfqd->wr_busy_queues--;
}
bfq_log_bfqq(bfqd, new_bfqq, "merge_bfqqs: wr_busy %d",
bfqd->wr_busy_queues);
bic_set_bfqq(bic, new_bfqq, 1);
bfq_mark_bfqq_coop(new_bfqq);
new_bfqq->bic = NULL;
bfqq->bic = NULL;
bfq_put_queue(bfqq);
}
static bool bfq_allow_bio_merge(struct request_queue *q, struct request *rq,
struct bio *bio)
{
struct bfq_data *bfqd = q->elevator->elevator_data;
bool is_sync = op_is_sync(bio->bi_opf);
struct bfq_queue *bfqq = bfqd->bio_bfqq, *new_bfqq;
if (is_sync && !rq_is_sync(rq))
return false;
if (!bfqq)
return false;
new_bfqq = bfq_setup_cooperator(bfqd, bfqq, bio, false);
if (new_bfqq) {
bfq_merge_bfqqs(bfqd, bfqd->bio_bic, bfqq,
new_bfqq);
bfqq = new_bfqq;
bfqd->bio_bfqq = bfqq;
}
return bfqq == RQ_BFQQ(rq);
}
static void bfq_set_budget_timeout(struct bfq_data *bfqd,
struct bfq_queue *bfqq)
{
unsigned int timeout_coeff;
if (bfqq->wr_cur_max_time == bfqd->bfq_wr_rt_max_time)
timeout_coeff = 1;
else
timeout_coeff = bfqq->entity.weight / bfqq->entity.orig_weight;
bfqd->last_budget_start = ktime_get();
bfqq->budget_timeout = jiffies +
bfqd->bfq_timeout * timeout_coeff;
}
static void __bfq_set_in_service_queue(struct bfq_data *bfqd,
struct bfq_queue *bfqq)
{
if (bfqq) {
bfqg_stats_update_avg_queue_size(bfqq_group(bfqq));
bfq_clear_bfqq_fifo_expire(bfqq);
bfqd->budgets_assigned = (bfqd->budgets_assigned * 7 + 256) / 8;
if (time_is_before_jiffies(bfqq->last_wr_start_finish) &&
bfqq->wr_coeff > 1 &&
bfqq->wr_cur_max_time == bfqd->bfq_wr_rt_max_time &&
time_is_before_jiffies(bfqq->budget_timeout)) {
if (time_after(bfqq->budget_timeout,
bfqq->last_wr_start_finish))
bfqq->last_wr_start_finish +=
jiffies - bfqq->budget_timeout;
else
bfqq->last_wr_start_finish = jiffies;
}
bfq_set_budget_timeout(bfqd, bfqq);
bfq_log_bfqq(bfqd, bfqq,
"set_in_service_queue, cur-budget = %d",
bfqq->entity.budget);
}
bfqd->in_service_queue = bfqq;
}
static struct bfq_queue *bfq_set_in_service_queue(struct bfq_data *bfqd)
{
struct bfq_queue *bfqq = bfq_get_next_queue(bfqd);
__bfq_set_in_service_queue(bfqd, bfqq);
return bfqq;
}
static void bfq_arm_slice_timer(struct bfq_data *bfqd)
{
struct bfq_queue *bfqq = bfqd->in_service_queue;
u32 sl;
bfq_mark_bfqq_wait_request(bfqq);
sl = bfqd->bfq_slice_idle;
if (BFQQ_SEEKY(bfqq) && bfqq->wr_coeff == 1 &&
bfq_symmetric_scenario(bfqd))
sl = min_t(u64, sl, BFQ_MIN_TT);
bfqd->last_idling_start = ktime_get();
hrtimer_start(&bfqd->idle_slice_timer, ns_to_ktime(sl),
HRTIMER_MODE_REL);
bfqg_stats_set_start_idle_time(bfqq_group(bfqq));
}
static unsigned long bfq_calc_max_budget(struct bfq_data *bfqd)
{
return (u64)bfqd->peak_rate * USEC_PER_MSEC *
jiffies_to_msecs(bfqd->bfq_timeout)>>BFQ_RATE_SHIFT;
}
static void update_thr_responsiveness_params(struct bfq_data *bfqd)
{
int dev_type = blk_queue_nonrot(bfqd->queue);
if (bfqd->bfq_user_max_budget == 0)
bfqd->bfq_max_budget =
bfq_calc_max_budget(bfqd);
if (bfqd->device_speed == BFQ_BFQD_FAST &&
bfqd->peak_rate < device_speed_thresh[dev_type]) {
bfqd->device_speed = BFQ_BFQD_SLOW;
bfqd->RT_prod = R_slow[dev_type] *
T_slow[dev_type];
} else if (bfqd->device_speed == BFQ_BFQD_SLOW &&
bfqd->peak_rate > device_speed_thresh[dev_type]) {
bfqd->device_speed = BFQ_BFQD_FAST;
bfqd->RT_prod = R_fast[dev_type] *
T_fast[dev_type];
}
bfq_log(bfqd,
"dev_type %s dev_speed_class = %s (%llu sects/sec), thresh %llu setcs/sec",
dev_type == 0 ? "ROT" : "NONROT",
bfqd->device_speed == BFQ_BFQD_FAST ? "FAST" : "SLOW",
bfqd->device_speed == BFQ_BFQD_FAST ?
(USEC_PER_SEC*(u64)R_fast[dev_type])>>BFQ_RATE_SHIFT :
(USEC_PER_SEC*(u64)R_slow[dev_type])>>BFQ_RATE_SHIFT,
(USEC_PER_SEC*(u64)device_speed_thresh[dev_type])>>
BFQ_RATE_SHIFT);
}
static void bfq_reset_rate_computation(struct bfq_data *bfqd,
struct request *rq)
{
if (rq != NULL) {
bfqd->last_dispatch = bfqd->first_dispatch = ktime_get_ns();
bfqd->peak_rate_samples = 1;
bfqd->sequential_samples = 0;
bfqd->tot_sectors_dispatched = bfqd->last_rq_max_size =
blk_rq_sectors(rq);
} else
bfqd->peak_rate_samples = 0;
bfq_log(bfqd,
"reset_rate_computation at end, sample %u/%u tot_sects %llu",
bfqd->peak_rate_samples, bfqd->sequential_samples,
bfqd->tot_sectors_dispatched);
}
static void bfq_update_rate_reset(struct bfq_data *bfqd, struct request *rq)
{
u32 rate, weight, divisor;
if (bfqd->peak_rate_samples < BFQ_RATE_MIN_SAMPLES ||
bfqd->delta_from_first < BFQ_RATE_MIN_INTERVAL)
goto reset_computation;
bfqd->delta_from_first =
max_t(u64, bfqd->delta_from_first,
bfqd->last_completion - bfqd->first_dispatch);
rate = div64_ul(bfqd->tot_sectors_dispatched<<BFQ_RATE_SHIFT,
div_u64(bfqd->delta_from_first, NSEC_PER_USEC));
if ((bfqd->sequential_samples < (3 * bfqd->peak_rate_samples)>>2 &&
rate <= bfqd->peak_rate) ||
rate > 20<<BFQ_RATE_SHIFT)
goto reset_computation;
weight = (9 * bfqd->sequential_samples) / bfqd->peak_rate_samples;
weight = min_t(u32, 8,
div_u64(weight * bfqd->delta_from_first,
BFQ_RATE_REF_INTERVAL));
divisor = 10 - weight;
bfqd->peak_rate *= divisor-1;
bfqd->peak_rate /= divisor;
rate /= divisor;
bfqd->peak_rate += rate;
update_thr_responsiveness_params(bfqd);
reset_computation:
bfq_reset_rate_computation(bfqd, rq);
}
static void bfq_update_peak_rate(struct bfq_data *bfqd, struct request *rq)
{
u64 now_ns = ktime_get_ns();
if (bfqd->peak_rate_samples == 0) {
bfq_log(bfqd, "update_peak_rate: goto reset, samples %d",
bfqd->peak_rate_samples);
bfq_reset_rate_computation(bfqd, rq);
goto update_last_values;
}
if (now_ns - bfqd->last_dispatch > 100*NSEC_PER_MSEC &&
bfqd->rq_in_driver == 0)
goto update_rate_and_reset;
bfqd->peak_rate_samples++;
if ((bfqd->rq_in_driver > 0 ||
now_ns - bfqd->last_completion < BFQ_MIN_TT)
&& get_sdist(bfqd->last_position, rq) < BFQQ_SEEK_THR)
bfqd->sequential_samples++;
bfqd->tot_sectors_dispatched += blk_rq_sectors(rq);
if (likely(bfqd->peak_rate_samples % 32))
bfqd->last_rq_max_size =
max_t(u32, blk_rq_sectors(rq), bfqd->last_rq_max_size);
else
bfqd->last_rq_max_size = blk_rq_sectors(rq);
bfqd->delta_from_first = now_ns - bfqd->first_dispatch;
if (bfqd->delta_from_first < BFQ_RATE_REF_INTERVAL)
goto update_last_values;
update_rate_and_reset:
bfq_update_rate_reset(bfqd, rq);
update_last_values:
bfqd->last_position = blk_rq_pos(rq) + blk_rq_sectors(rq);
bfqd->last_dispatch = now_ns;
}
static void bfq_dispatch_remove(struct request_queue *q, struct request *rq)
{
struct bfq_queue *bfqq = RQ_BFQQ(rq);
bfqq->dispatched++;
bfq_update_peak_rate(q->elevator->elevator_data, rq);
bfq_remove_request(q, rq);
}
static void __bfq_bfqq_expire(struct bfq_data *bfqd, struct bfq_queue *bfqq)
{
if (bfq_bfqq_coop(bfqq) && BFQQ_SEEKY(bfqq))
bfq_mark_bfqq_split_coop(bfqq);
if (RB_EMPTY_ROOT(&bfqq->sort_list)) {
if (bfqq->dispatched == 0)
bfqq->budget_timeout = jiffies;
bfq_del_bfqq_busy(bfqd, bfqq, true);
} else {
bfq_requeue_bfqq(bfqd, bfqq);
bfq_pos_tree_add_move(bfqd, bfqq);
}
__bfq_bfqd_reset_in_service(bfqd);
}
static void __bfq_bfqq_recalc_budget(struct bfq_data *bfqd,
struct bfq_queue *bfqq,
enum bfqq_expiration reason)
{
struct request *next_rq;
int budget, min_budget;
min_budget = bfq_min_budget(bfqd);
if (bfqq->wr_coeff == 1)
budget = bfqq->max_budget;
else
budget = 2 * min_budget;
bfq_log_bfqq(bfqd, bfqq, "recalc_budg: last budg %d, budg left %d",
bfqq->entity.budget, bfq_bfqq_budget_left(bfqq));
bfq_log_bfqq(bfqd, bfqq, "recalc_budg: last max_budg %d, min budg %d",
budget, bfq_min_budget(bfqd));
bfq_log_bfqq(bfqd, bfqq, "recalc_budg: sync %d, seeky %d",
bfq_bfqq_sync(bfqq), BFQQ_SEEKY(bfqd->in_service_queue));
if (bfq_bfqq_sync(bfqq) && bfqq->wr_coeff == 1) {
switch (reason) {
case BFQQE_TOO_IDLE:
if (bfqq->dispatched > 0)
budget = min(budget * 2, bfqd->bfq_max_budget);
else {
if (budget > 5 * min_budget)
budget -= 4 * min_budget;
else
budget = min_budget;
}
break;
case BFQQE_BUDGET_TIMEOUT:
budget = min(budget * 2, bfqd->bfq_max_budget);
break;
case BFQQE_BUDGET_EXHAUSTED:
budget = min(budget * 4, bfqd->bfq_max_budget);
break;
case BFQQE_NO_MORE_REQUESTS:
budget = max_t(int, bfqq->entity.service, min_budget);
break;
default:
return;
}
} else if (!bfq_bfqq_sync(bfqq)) {
budget = bfqd->bfq_max_budget;
}
bfqq->max_budget = budget;
if (bfqd->budgets_assigned >= bfq_stats_min_budgets &&
!bfqd->bfq_user_max_budget)
bfqq->max_budget = min(bfqq->max_budget, bfqd->bfq_max_budget);
next_rq = bfqq->next_rq;
if (next_rq)
bfqq->entity.budget = max_t(unsigned long, bfqq->max_budget,
bfq_serv_to_charge(next_rq, bfqq));
bfq_log_bfqq(bfqd, bfqq, "head sect: %u, new budget %d",
next_rq ? blk_rq_sectors(next_rq) : 0,
bfqq->entity.budget);
}
static bool bfq_bfqq_is_slow(struct bfq_data *bfqd, struct bfq_queue *bfqq,
bool compensate, enum bfqq_expiration reason,
unsigned long *delta_ms)
{
ktime_t delta_ktime;
u32 delta_usecs;
bool slow = BFQQ_SEEKY(bfqq);
if (!bfq_bfqq_sync(bfqq))
return false;
if (compensate)
delta_ktime = bfqd->last_idling_start;
else
delta_ktime = ktime_get();
delta_ktime = ktime_sub(delta_ktime, bfqd->last_budget_start);
delta_usecs = ktime_to_us(delta_ktime);
if (delta_usecs < 1000) {
if (blk_queue_nonrot(bfqd->queue))
*delta_ms = BFQ_MIN_TT / NSEC_PER_MSEC;
else
*delta_ms = bfq_slice_idle / NSEC_PER_MSEC;
return slow;
}
*delta_ms = delta_usecs / USEC_PER_MSEC;
if (delta_usecs > 20000) {
slow = bfqq->entity.service < bfqd->bfq_max_budget / 2;
}
bfq_log_bfqq(bfqd, bfqq, "bfq_bfqq_is_slow: slow %d", slow);
return slow;
}
static unsigned long bfq_bfqq_softrt_next_start(struct bfq_data *bfqd,
struct bfq_queue *bfqq)
{
return max(bfqq->last_idle_bklogged +
HZ * bfqq->service_from_backlogged /
bfqd->bfq_wr_max_softrt_rate,
jiffies + nsecs_to_jiffies(bfqq->bfqd->bfq_slice_idle) + 4);
}
static unsigned long bfq_greatest_from_now(void)
{
return jiffies + MAX_JIFFY_OFFSET;
}
static unsigned long bfq_smallest_from_now(void)
{
return jiffies - MAX_JIFFY_OFFSET;
}
void bfq_bfqq_expire(struct bfq_data *bfqd,
struct bfq_queue *bfqq,
bool compensate,
enum bfqq_expiration reason)
{
bool slow;
unsigned long delta = 0;
struct bfq_entity *entity = &bfqq->entity;
int ref;
slow = bfq_bfqq_is_slow(bfqd, bfqq, compensate, reason, &delta);
bfqq->service_from_backlogged += entity->service;
if (bfqq->wr_coeff == 1 &&
(slow ||
(reason == BFQQE_BUDGET_TIMEOUT &&
bfq_bfqq_budget_left(bfqq) >= entity->budget / 3)))
bfq_bfqq_charge_time(bfqd, bfqq, delta);
if (reason == BFQQE_TOO_IDLE &&
entity->service <= 2 * entity->budget / 10)
bfq_clear_bfqq_IO_bound(bfqq);
if (bfqd->low_latency && bfqq->wr_coeff == 1)
bfqq->last_wr_start_finish = jiffies;
if (bfqd->low_latency && bfqd->bfq_wr_max_softrt_rate > 0 &&
RB_EMPTY_ROOT(&bfqq->sort_list)) {
if (bfqq->dispatched == 0)
bfqq->soft_rt_next_start =
bfq_bfqq_softrt_next_start(bfqd, bfqq);
else {
bfqq->soft_rt_next_start =
bfq_greatest_from_now();
bfq_mark_bfqq_softrt_update(bfqq);
}
}
bfq_log_bfqq(bfqd, bfqq,
"expire (%d, slow %d, num_disp %d, idle_win %d)", reason,
slow, bfqq->dispatched, bfq_bfqq_idle_window(bfqq));
__bfq_bfqq_recalc_budget(bfqd, bfqq, reason);
ref = bfqq->ref;
__bfq_bfqq_expire(bfqd, bfqq);
if (ref > 1 && !bfq_bfqq_busy(bfqq) &&
reason != BFQQE_BUDGET_TIMEOUT &&
reason != BFQQE_BUDGET_EXHAUSTED)
bfq_mark_bfqq_non_blocking_wait_rq(bfqq);
}
static bool bfq_bfqq_budget_timeout(struct bfq_queue *bfqq)
{
return time_is_before_eq_jiffies(bfqq->budget_timeout);
}
static bool bfq_may_expire_for_budg_timeout(struct bfq_queue *bfqq)
{
bfq_log_bfqq(bfqq->bfqd, bfqq,
"may_budget_timeout: wait_request %d left %d timeout %d",
bfq_bfqq_wait_request(bfqq),
bfq_bfqq_budget_left(bfqq) >= bfqq->entity.budget / 3,
bfq_bfqq_budget_timeout(bfqq));
return (!bfq_bfqq_wait_request(bfqq) ||
bfq_bfqq_budget_left(bfqq) >= bfqq->entity.budget / 3)
&&
bfq_bfqq_budget_timeout(bfqq);
}
static bool bfq_bfqq_may_idle(struct bfq_queue *bfqq)
{
struct bfq_data *bfqd = bfqq->bfqd;
bool idling_boosts_thr, idling_boosts_thr_without_issues,
idling_needed_for_service_guarantees,
asymmetric_scenario;
if (bfqd->strict_guarantees)
return true;
idling_boosts_thr = !bfqd->hw_tag ||
(!blk_queue_nonrot(bfqd->queue) && bfq_bfqq_IO_bound(bfqq) &&
bfq_bfqq_idle_window(bfqq));
idling_boosts_thr_without_issues = idling_boosts_thr &&
bfqd->wr_busy_queues == 0;
asymmetric_scenario = bfqq->wr_coeff > 1 ||
!bfq_symmetric_scenario(bfqd);
idling_needed_for_service_guarantees =
asymmetric_scenario && !bfq_bfqq_in_large_burst(bfqq);
return bfq_bfqq_sync(bfqq) &&
(idling_boosts_thr_without_issues ||
idling_needed_for_service_guarantees);
}
static bool bfq_bfqq_must_idle(struct bfq_queue *bfqq)
{
struct bfq_data *bfqd = bfqq->bfqd;
return RB_EMPTY_ROOT(&bfqq->sort_list) && bfqd->bfq_slice_idle != 0 &&
bfq_bfqq_may_idle(bfqq);
}
static struct bfq_queue *bfq_select_queue(struct bfq_data *bfqd)
{
struct bfq_queue *bfqq;
struct request *next_rq;
enum bfqq_expiration reason = BFQQE_BUDGET_TIMEOUT;
bfqq = bfqd->in_service_queue;
if (!bfqq)
goto new_queue;
bfq_log_bfqq(bfqd, bfqq, "select_queue: already in-service queue");
if (bfq_may_expire_for_budg_timeout(bfqq) &&
!bfq_bfqq_wait_request(bfqq) &&
!bfq_bfqq_must_idle(bfqq))
goto expire;
check_queue:
next_rq = bfqq->next_rq;
if (next_rq) {
if (bfq_serv_to_charge(next_rq, bfqq) >
bfq_bfqq_budget_left(bfqq)) {
reason = BFQQE_BUDGET_EXHAUSTED;
goto expire;
} else {
if (bfq_bfqq_wait_request(bfqq)) {
bfq_clear_bfqq_wait_request(bfqq);
hrtimer_try_to_cancel(&bfqd->idle_slice_timer);
bfqg_stats_update_idle_time(bfqq_group(bfqq));
}
goto keep_queue;
}
}
if (bfq_bfqq_wait_request(bfqq) ||
(bfqq->dispatched != 0 && bfq_bfqq_may_idle(bfqq))) {
bfqq = NULL;
goto keep_queue;
}
reason = BFQQE_NO_MORE_REQUESTS;
expire:
bfq_bfqq_expire(bfqd, bfqq, false, reason);
new_queue:
bfqq = bfq_set_in_service_queue(bfqd);
if (bfqq) {
bfq_log_bfqq(bfqd, bfqq, "select_queue: checking new queue");
goto check_queue;
}
keep_queue:
if (bfqq)
bfq_log_bfqq(bfqd, bfqq, "select_queue: returned this queue");
else
bfq_log(bfqd, "select_queue: no queue returned");
return bfqq;
}
static void bfq_update_wr_data(struct bfq_data *bfqd, struct bfq_queue *bfqq)
{
struct bfq_entity *entity = &bfqq->entity;
if (bfqq->wr_coeff > 1) {
bfq_log_bfqq(bfqd, bfqq,
"raising period dur %u/%u msec, old coeff %u, w %d(%d)",
jiffies_to_msecs(jiffies - bfqq->last_wr_start_finish),
jiffies_to_msecs(bfqq->wr_cur_max_time),
bfqq->wr_coeff,
bfqq->entity.weight, bfqq->entity.orig_weight);
if (entity->prio_changed)
bfq_log_bfqq(bfqd, bfqq, "WARN: pending prio change");
if (bfq_bfqq_in_large_burst(bfqq))
bfq_bfqq_end_wr(bfqq);
else if (time_is_before_jiffies(bfqq->last_wr_start_finish +
bfqq->wr_cur_max_time)) {
if (bfqq->wr_cur_max_time != bfqd->bfq_wr_rt_max_time ||
time_is_before_jiffies(bfqq->wr_start_at_switch_to_srt +
bfq_wr_duration(bfqd)))
bfq_bfqq_end_wr(bfqq);
else {
bfqq->wr_coeff = bfqd->bfq_wr_coeff;
bfqq->wr_cur_max_time = bfq_wr_duration(bfqd);
bfqq->last_wr_start_finish =
bfqq->wr_start_at_switch_to_srt;
bfqq->entity.prio_changed = 1;
}
}
}
if ((entity->weight > entity->orig_weight) != (bfqq->wr_coeff > 1))
__bfq_entity_update_weight_prio(
bfq_entity_service_tree(entity),
entity);
}
static struct request *bfq_dispatch_rq_from_bfqq(struct bfq_data *bfqd,
struct bfq_queue *bfqq)
{
struct request *rq = bfqq->next_rq;
unsigned long service_to_charge;
service_to_charge = bfq_serv_to_charge(rq, bfqq);
bfq_bfqq_served(bfqq, service_to_charge);
bfq_dispatch_remove(bfqd->queue, rq);
bfq_update_wr_data(bfqd, bfqq);
if (bfqd->busy_queues > 1 && bfq_class_idle(bfqq))
goto expire;
return rq;
expire:
bfq_bfqq_expire(bfqd, bfqq, false, BFQQE_BUDGET_EXHAUSTED);
return rq;
}
static bool bfq_has_work(struct blk_mq_hw_ctx *hctx)
{
struct bfq_data *bfqd = hctx->queue->elevator->elevator_data;
return !list_empty_careful(&bfqd->dispatch) ||
bfqd->busy_queues > 0;
}
static struct request *__bfq_dispatch_request(struct blk_mq_hw_ctx *hctx)
{
struct bfq_data *bfqd = hctx->queue->elevator->elevator_data;
struct request *rq = NULL;
struct bfq_queue *bfqq = NULL;
if (!list_empty(&bfqd->dispatch)) {
rq = list_first_entry(&bfqd->dispatch, struct request,
queuelist);
list_del_init(&rq->queuelist);
bfqq = RQ_BFQQ(rq);
if (bfqq) {
bfqq->dispatched++;
goto inc_in_driver_start_rq;
}
goto start_rq;
}
bfq_log(bfqd, "dispatch requests: %d busy queues", bfqd->busy_queues);
if (bfqd->busy_queues == 0)
goto exit;
if (bfqd->strict_guarantees && bfqd->rq_in_driver > 0)
goto exit;
bfqq = bfq_select_queue(bfqd);
if (!bfqq)
goto exit;
rq = bfq_dispatch_rq_from_bfqq(bfqd, bfqq);
if (rq) {
inc_in_driver_start_rq:
bfqd->rq_in_driver++;
start_rq:
rq->rq_flags |= RQF_STARTED;
}
exit:
return rq;
}
static struct request *bfq_dispatch_request(struct blk_mq_hw_ctx *hctx)
{
struct bfq_data *bfqd = hctx->queue->elevator->elevator_data;
struct request *rq;
spin_lock_irq(&bfqd->lock);
rq = __bfq_dispatch_request(hctx);
spin_unlock_irq(&bfqd->lock);
return rq;
}
void bfq_put_queue(struct bfq_queue *bfqq)
{
#ifdef CONFIG_BFQ_GROUP_IOSCHED
struct bfq_group *bfqg = bfqq_group(bfqq);
#endif
if (bfqq->bfqd)
bfq_log_bfqq(bfqq->bfqd, bfqq, "put_queue: %p %d",
bfqq, bfqq->ref);
bfqq->ref--;
if (bfqq->ref)
return;
if (bfq_bfqq_sync(bfqq))
hlist_del_init(&bfqq->burst_list_node);
kmem_cache_free(bfq_pool, bfqq);
#ifdef CONFIG_BFQ_GROUP_IOSCHED
bfqg_and_blkg_put(bfqg);
#endif
}
static void bfq_put_cooperator(struct bfq_queue *bfqq)
{
struct bfq_queue *__bfqq, *next;
__bfqq = bfqq->new_bfqq;
while (__bfqq) {
if (__bfqq == bfqq)
break;
next = __bfqq->new_bfqq;
bfq_put_queue(__bfqq);
__bfqq = next;
}
}
static void bfq_exit_bfqq(struct bfq_data *bfqd, struct bfq_queue *bfqq)
{
if (bfqq == bfqd->in_service_queue) {
__bfq_bfqq_expire(bfqd, bfqq);
bfq_schedule_dispatch(bfqd);
}
bfq_log_bfqq(bfqd, bfqq, "exit_bfqq: %p, %d", bfqq, bfqq->ref);
bfq_put_cooperator(bfqq);
bfq_put_queue(bfqq);
}
static void bfq_exit_icq_bfqq(struct bfq_io_cq *bic, bool is_sync)
{
struct bfq_queue *bfqq = bic_to_bfqq(bic, is_sync);
struct bfq_data *bfqd;
if (bfqq)
bfqd = bfqq->bfqd;
if (bfqq && bfqd) {
unsigned long flags;
spin_lock_irqsave(&bfqd->lock, flags);
bfq_exit_bfqq(bfqd, bfqq);
bic_set_bfqq(bic, NULL, is_sync);
spin_unlock_irqrestore(&bfqd->lock, flags);
}
}
static void bfq_exit_icq(struct io_cq *icq)
{
struct bfq_io_cq *bic = icq_to_bic(icq);
bfq_exit_icq_bfqq(bic, true);
bfq_exit_icq_bfqq(bic, false);
}
static void
bfq_set_next_ioprio_data(struct bfq_queue *bfqq, struct bfq_io_cq *bic)
{
struct task_struct *tsk = current;
int ioprio_class;
struct bfq_data *bfqd = bfqq->bfqd;
if (!bfqd)
return;
ioprio_class = IOPRIO_PRIO_CLASS(bic->ioprio);
switch (ioprio_class) {
default:
dev_err(bfqq->bfqd->queue->backing_dev_info->dev,
"bfq: bad prio class %d\n", ioprio_class);
case IOPRIO_CLASS_NONE:
bfqq->new_ioprio = task_nice_ioprio(tsk);
bfqq->new_ioprio_class = task_nice_ioclass(tsk);
break;
case IOPRIO_CLASS_RT:
bfqq->new_ioprio = IOPRIO_PRIO_DATA(bic->ioprio);
bfqq->new_ioprio_class = IOPRIO_CLASS_RT;
break;
case IOPRIO_CLASS_BE:
bfqq->new_ioprio = IOPRIO_PRIO_DATA(bic->ioprio);
bfqq->new_ioprio_class = IOPRIO_CLASS_BE;
break;
case IOPRIO_CLASS_IDLE:
bfqq->new_ioprio_class = IOPRIO_CLASS_IDLE;
bfqq->new_ioprio = 7;
bfq_clear_bfqq_idle_window(bfqq);
break;
}
if (bfqq->new_ioprio >= IOPRIO_BE_NR) {
pr_crit("bfq_set_next_ioprio_data: new_ioprio %d\n",
bfqq->new_ioprio);
bfqq->new_ioprio = IOPRIO_BE_NR;
}
bfqq->entity.new_weight = bfq_ioprio_to_weight(bfqq->new_ioprio);
bfqq->entity.prio_changed = 1;
}
static void bfq_check_ioprio_change(struct bfq_io_cq *bic, struct bio *bio)
{
struct bfq_data *bfqd = bic_to_bfqd(bic);
struct bfq_queue *bfqq;
int ioprio = bic->icq.ioc->ioprio;
if (unlikely(!bfqd) || likely(bic->ioprio == ioprio))
return;
bic->ioprio = ioprio;
bfqq = bic_to_bfqq(bic, false);
if (bfqq) {
bfq_put_queue(bfqq);
bfqq = bfq_get_queue(bfqd, bio, BLK_RW_ASYNC, bic);
bic_set_bfqq(bic, bfqq, false);
}
bfqq = bic_to_bfqq(bic, true);
if (bfqq)
bfq_set_next_ioprio_data(bfqq, bic);
}
static void bfq_init_bfqq(struct bfq_data *bfqd, struct bfq_queue *bfqq,
struct bfq_io_cq *bic, pid_t pid, int is_sync)
{
RB_CLEAR_NODE(&bfqq->entity.rb_node);
INIT_LIST_HEAD(&bfqq->fifo);
INIT_HLIST_NODE(&bfqq->burst_list_node);
bfqq->ref = 0;
bfqq->bfqd = bfqd;
if (bic)
bfq_set_next_ioprio_data(bfqq, bic);
if (is_sync) {
if (!bfq_class_idle(bfqq))
bfq_mark_bfqq_idle_window(bfqq);
bfq_mark_bfqq_sync(bfqq);
bfq_mark_bfqq_just_created(bfqq);
} else
bfq_clear_bfqq_sync(bfqq);
bfqq->ttime.last_end_request = ktime_get_ns() + 1;
bfq_mark_bfqq_IO_bound(bfqq);
bfqq->pid = pid;
bfqq->max_budget = (2 * bfq_max_budget(bfqd)) / 3;
bfqq->budget_timeout = bfq_smallest_from_now();
bfqq->wr_coeff = 1;
bfqq->last_wr_start_finish = jiffies;
bfqq->wr_start_at_switch_to_srt = bfq_smallest_from_now();
bfqq->split_time = bfq_smallest_from_now();
bfqq->soft_rt_next_start = bfq_greatest_from_now();
bfqq->seek_history = 1;
}
static struct bfq_queue **bfq_async_queue_prio(struct bfq_data *bfqd,
struct bfq_group *bfqg,
int ioprio_class, int ioprio)
{
switch (ioprio_class) {
case IOPRIO_CLASS_RT:
return &bfqg->async_bfqq[0][ioprio];
case IOPRIO_CLASS_NONE:
ioprio = IOPRIO_NORM;
case IOPRIO_CLASS_BE:
return &bfqg->async_bfqq[1][ioprio];
case IOPRIO_CLASS_IDLE:
return &bfqg->async_idle_bfqq;
default:
return NULL;
}
}
static struct bfq_queue *bfq_get_queue(struct bfq_data *bfqd,
struct bio *bio, bool is_sync,
struct bfq_io_cq *bic)
{
const int ioprio = IOPRIO_PRIO_DATA(bic->ioprio);
const int ioprio_class = IOPRIO_PRIO_CLASS(bic->ioprio);
struct bfq_queue **async_bfqq = NULL;
struct bfq_queue *bfqq;
struct bfq_group *bfqg;
rcu_read_lock();
bfqg = bfq_find_set_group(bfqd, bio_blkcg(bio));
if (!bfqg) {
bfqq = &bfqd->oom_bfqq;
goto out;
}
if (!is_sync) {
async_bfqq = bfq_async_queue_prio(bfqd, bfqg, ioprio_class,
ioprio);
bfqq = *async_bfqq;
if (bfqq)
goto out;
}
bfqq = kmem_cache_alloc_node(bfq_pool,
GFP_NOWAIT | __GFP_ZERO | __GFP_NOWARN,
bfqd->queue->node);
if (bfqq) {
bfq_init_bfqq(bfqd, bfqq, bic, current->pid,
is_sync);
bfq_init_entity(&bfqq->entity, bfqg);
bfq_log_bfqq(bfqd, bfqq, "allocated");
} else {
bfqq = &bfqd->oom_bfqq;
bfq_log_bfqq(bfqd, bfqq, "using oom bfqq");
goto out;
}
if (async_bfqq) {
bfqq->ref++;
bfq_log_bfqq(bfqd, bfqq, "get_queue, bfqq not in async: %p, %d",
bfqq, bfqq->ref);
*async_bfqq = bfqq;
}
out:
bfqq->ref++;
bfq_log_bfqq(bfqd, bfqq, "get_queue, at end: %p, %d", bfqq, bfqq->ref);
rcu_read_unlock();
return bfqq;
}
static void bfq_update_io_thinktime(struct bfq_data *bfqd,
struct bfq_queue *bfqq)
{
struct bfq_ttime *ttime = &bfqq->ttime;
u64 elapsed = ktime_get_ns() - bfqq->ttime.last_end_request;
elapsed = min_t(u64, elapsed, 2ULL * bfqd->bfq_slice_idle);
ttime->ttime_samples = (7*bfqq->ttime.ttime_samples + 256) / 8;
ttime->ttime_total = div_u64(7*ttime->ttime_total + 256*elapsed, 8);
ttime->ttime_mean = div64_ul(ttime->ttime_total + 128,
ttime->ttime_samples);
}
static void
bfq_update_io_seektime(struct bfq_data *bfqd, struct bfq_queue *bfqq,
struct request *rq)
{
bfqq->seek_history <<= 1;
bfqq->seek_history |=
get_sdist(bfqq->last_request_pos, rq) > BFQQ_SEEK_THR &&
(!blk_queue_nonrot(bfqd->queue) ||
blk_rq_sectors(rq) < BFQQ_SECT_THR_NONROT);
}
static void bfq_update_idle_window(struct bfq_data *bfqd,
struct bfq_queue *bfqq,
struct bfq_io_cq *bic)
{
int enable_idle;
if (!bfq_bfqq_sync(bfqq) || bfq_class_idle(bfqq))
return;
if (time_is_after_eq_jiffies(bfqq->split_time +
bfqd->bfq_wr_min_idle_time))
return;
enable_idle = bfq_bfqq_idle_window(bfqq);
if (atomic_read(&bic->icq.ioc->active_ref) == 0 ||
bfqd->bfq_slice_idle == 0 ||
(bfqd->hw_tag && BFQQ_SEEKY(bfqq) &&
bfqq->wr_coeff == 1))
enable_idle = 0;
else if (bfq_sample_valid(bfqq->ttime.ttime_samples)) {
if (bfqq->ttime.ttime_mean > bfqd->bfq_slice_idle &&
bfqq->wr_coeff == 1)
enable_idle = 0;
else
enable_idle = 1;
}
bfq_log_bfqq(bfqd, bfqq, "update_idle_window: enable_idle %d",
enable_idle);
if (enable_idle)
bfq_mark_bfqq_idle_window(bfqq);
else
bfq_clear_bfqq_idle_window(bfqq);
}
static void bfq_rq_enqueued(struct bfq_data *bfqd, struct bfq_queue *bfqq,
struct request *rq)
{
struct bfq_io_cq *bic = RQ_BIC(rq);
if (rq->cmd_flags & REQ_META)
bfqq->meta_pending++;
bfq_update_io_thinktime(bfqd, bfqq);
bfq_update_io_seektime(bfqd, bfqq, rq);
if (bfqq->entity.service > bfq_max_budget(bfqd) / 8 ||
!BFQQ_SEEKY(bfqq))
bfq_update_idle_window(bfqd, bfqq, bic);
bfq_log_bfqq(bfqd, bfqq,
"rq_enqueued: idle_window=%d (seeky %d)",
bfq_bfqq_idle_window(bfqq), BFQQ_SEEKY(bfqq));
bfqq->last_request_pos = blk_rq_pos(rq) + blk_rq_sectors(rq);
if (bfqq == bfqd->in_service_queue && bfq_bfqq_wait_request(bfqq)) {
bool small_req = bfqq->queued[rq_is_sync(rq)] == 1 &&
blk_rq_sectors(rq) < 32;
bool budget_timeout = bfq_bfqq_budget_timeout(bfqq);
if (small_req && !budget_timeout)
return;
bfq_clear_bfqq_wait_request(bfqq);
hrtimer_try_to_cancel(&bfqd->idle_slice_timer);
bfqg_stats_update_idle_time(bfqq_group(bfqq));
if (budget_timeout)
bfq_bfqq_expire(bfqd, bfqq, false,
BFQQE_BUDGET_TIMEOUT);
}
}
static void __bfq_insert_request(struct bfq_data *bfqd, struct request *rq)
{
struct bfq_queue *bfqq = RQ_BFQQ(rq),
*new_bfqq = bfq_setup_cooperator(bfqd, bfqq, rq, true);
if (new_bfqq) {
if (bic_to_bfqq(RQ_BIC(rq), 1) != bfqq)
new_bfqq = bic_to_bfqq(RQ_BIC(rq), 1);
new_bfqq->allocated++;
bfqq->allocated--;
new_bfqq->ref++;
bfq_clear_bfqq_just_created(bfqq);
if (bic_to_bfqq(RQ_BIC(rq), 1) == bfqq)
bfq_merge_bfqqs(bfqd, RQ_BIC(rq),
bfqq, new_bfqq);
bfq_put_queue(bfqq);
rq->elv.priv[1] = new_bfqq;
bfqq = new_bfqq;
}
bfq_add_request(rq);
rq->fifo_time = ktime_get_ns() + bfqd->bfq_fifo_expire[rq_is_sync(rq)];
list_add_tail(&rq->queuelist, &bfqq->fifo);
bfq_rq_enqueued(bfqd, bfqq, rq);
}
static void bfq_insert_request(struct blk_mq_hw_ctx *hctx, struct request *rq,
bool at_head)
{
struct request_queue *q = hctx->queue;
struct bfq_data *bfqd = q->elevator->elevator_data;
spin_lock_irq(&bfqd->lock);
if (blk_mq_sched_try_insert_merge(q, rq)) {
spin_unlock_irq(&bfqd->lock);
return;
}
spin_unlock_irq(&bfqd->lock);
blk_mq_sched_request_inserted(rq);
spin_lock_irq(&bfqd->lock);
if (at_head || blk_rq_is_passthrough(rq)) {
if (at_head)
list_add(&rq->queuelist, &bfqd->dispatch);
else
list_add_tail(&rq->queuelist, &bfqd->dispatch);
} else {
__bfq_insert_request(bfqd, rq);
if (rq_mergeable(rq)) {
elv_rqhash_add(q, rq);
if (!q->last_merge)
q->last_merge = rq;
}
}
spin_unlock_irq(&bfqd->lock);
}
static void bfq_insert_requests(struct blk_mq_hw_ctx *hctx,
struct list_head *list, bool at_head)
{
while (!list_empty(list)) {
struct request *rq;
rq = list_first_entry(list, struct request, queuelist);
list_del_init(&rq->queuelist);
bfq_insert_request(hctx, rq, at_head);
}
}
static void bfq_update_hw_tag(struct bfq_data *bfqd)
{
bfqd->max_rq_in_driver = max_t(int, bfqd->max_rq_in_driver,
bfqd->rq_in_driver);
if (bfqd->hw_tag == 1)
return;
if (bfqd->rq_in_driver + bfqd->queued < BFQ_HW_QUEUE_THRESHOLD)
return;
if (bfqd->hw_tag_samples++ < BFQ_HW_QUEUE_SAMPLES)
return;
bfqd->hw_tag = bfqd->max_rq_in_driver > BFQ_HW_QUEUE_THRESHOLD;
bfqd->max_rq_in_driver = 0;
bfqd->hw_tag_samples = 0;
}
static void bfq_completed_request(struct bfq_queue *bfqq, struct bfq_data *bfqd)
{
u64 now_ns;
u32 delta_us;
bfq_update_hw_tag(bfqd);
bfqd->rq_in_driver--;
bfqq->dispatched--;
if (!bfqq->dispatched && !bfq_bfqq_busy(bfqq)) {
bfqq->budget_timeout = jiffies;
bfq_weights_tree_remove(bfqd, &bfqq->entity,
&bfqd->queue_weights_tree);
}
now_ns = ktime_get_ns();
bfqq->ttime.last_end_request = now_ns;
delta_us = div_u64(now_ns - bfqd->last_completion, NSEC_PER_USEC);
if (delta_us > BFQ_MIN_TT/NSEC_PER_USEC &&
(bfqd->last_rq_max_size<<BFQ_RATE_SHIFT)/delta_us <
1UL<<(BFQ_RATE_SHIFT - 10))
bfq_update_rate_reset(bfqd, NULL);
bfqd->last_completion = now_ns;
if (bfq_bfqq_softrt_update(bfqq) && bfqq->dispatched == 0 &&
RB_EMPTY_ROOT(&bfqq->sort_list))
bfqq->soft_rt_next_start =
bfq_bfqq_softrt_next_start(bfqd, bfqq);
if (bfqd->in_service_queue == bfqq) {
if (bfqq->dispatched == 0 && bfq_bfqq_must_idle(bfqq)) {
bfq_arm_slice_timer(bfqd);
return;
} else if (bfq_may_expire_for_budg_timeout(bfqq))
bfq_bfqq_expire(bfqd, bfqq, false,
BFQQE_BUDGET_TIMEOUT);
else if (RB_EMPTY_ROOT(&bfqq->sort_list) &&
(bfqq->dispatched == 0 ||
!bfq_bfqq_may_idle(bfqq)))
bfq_bfqq_expire(bfqd, bfqq, false,
BFQQE_NO_MORE_REQUESTS);
}
}
static void bfq_put_rq_priv_body(struct bfq_queue *bfqq)
{
bfqq->allocated--;
bfq_put_queue(bfqq);
}
static void bfq_put_rq_private(struct request_queue *q, struct request *rq)
{
struct bfq_queue *bfqq = RQ_BFQQ(rq);
struct bfq_data *bfqd = bfqq->bfqd;
if (rq->rq_flags & RQF_STARTED)
bfqg_stats_update_completion(bfqq_group(bfqq),
rq_start_time_ns(rq),
rq_io_start_time_ns(rq),
rq->cmd_flags);
if (likely(rq->rq_flags & RQF_STARTED)) {
unsigned long flags;
spin_lock_irqsave(&bfqd->lock, flags);
bfq_completed_request(bfqq, bfqd);
bfq_put_rq_priv_body(bfqq);
spin_unlock_irqrestore(&bfqd->lock, flags);
} else {
if (!RB_EMPTY_NODE(&rq->rb_node))
bfq_remove_request(q, rq);
bfq_put_rq_priv_body(bfqq);
}
rq->elv.priv[0] = NULL;
rq->elv.priv[1] = NULL;
}
static struct bfq_queue *
bfq_split_bfqq(struct bfq_io_cq *bic, struct bfq_queue *bfqq)
{
bfq_log_bfqq(bfqq->bfqd, bfqq, "splitting queue");
if (bfqq_process_refs(bfqq) == 1) {
bfqq->pid = current->pid;
bfq_clear_bfqq_coop(bfqq);
bfq_clear_bfqq_split_coop(bfqq);
return bfqq;
}
bic_set_bfqq(bic, NULL, 1);
bfq_put_cooperator(bfqq);
bfq_put_queue(bfqq);
return NULL;
}
static struct bfq_queue *bfq_get_bfqq_handle_split(struct bfq_data *bfqd,
struct bfq_io_cq *bic,
struct bio *bio,
bool split, bool is_sync,
bool *new_queue)
{
struct bfq_queue *bfqq = bic_to_bfqq(bic, is_sync);
if (likely(bfqq && bfqq != &bfqd->oom_bfqq))
return bfqq;
if (new_queue)
*new_queue = true;
if (bfqq)
bfq_put_queue(bfqq);
bfqq = bfq_get_queue(bfqd, bio, is_sync, bic);
bic_set_bfqq(bic, bfqq, is_sync);
if (split && is_sync) {
if ((bic->was_in_burst_list && bfqd->large_burst) ||
bic->saved_in_large_burst)
bfq_mark_bfqq_in_large_burst(bfqq);
else {
bfq_clear_bfqq_in_large_burst(bfqq);
if (bic->was_in_burst_list)
hlist_add_head(&bfqq->burst_list_node,
&bfqd->burst_list);
}
bfqq->split_time = jiffies;
}
return bfqq;
}
static int bfq_get_rq_private(struct request_queue *q, struct request *rq,
struct bio *bio)
{
struct bfq_data *bfqd = q->elevator->elevator_data;
struct bfq_io_cq *bic = icq_to_bic(rq->elv.icq);
const int is_sync = rq_is_sync(rq);
struct bfq_queue *bfqq;
bool new_queue = false;
bool split = false;
spin_lock_irq(&bfqd->lock);
if (!bic)
goto queue_fail;
bfq_check_ioprio_change(bic, bio);
bfq_bic_update_cgroup(bic, bio);
bfqq = bfq_get_bfqq_handle_split(bfqd, bic, bio, false, is_sync,
&new_queue);
if (likely(!new_queue)) {
if (bfq_bfqq_coop(bfqq) && bfq_bfqq_split_coop(bfqq)) {
bfq_log_bfqq(bfqd, bfqq, "breaking apart bfqq");
if (bfq_bfqq_in_large_burst(bfqq))
bic->saved_in_large_burst = true;
bfqq = bfq_split_bfqq(bic, bfqq);
split = true;
if (!bfqq)
bfqq = bfq_get_bfqq_handle_split(bfqd, bic, bio,
true, is_sync,
NULL);
}
}
bfqq->allocated++;
bfqq->ref++;
bfq_log_bfqq(bfqd, bfqq, "get_request %p: bfqq %p, %d",
rq, bfqq, bfqq->ref);
rq->elv.priv[0] = bic;
rq->elv.priv[1] = bfqq;
if (likely(bfqq != &bfqd->oom_bfqq) && bfqq_process_refs(bfqq) == 1) {
bfqq->bic = bic;
if (split) {
bfq_bfqq_resume_state(bfqq, bic);
}
}
if (unlikely(bfq_bfqq_just_created(bfqq)))
bfq_handle_burst(bfqd, bfqq);
spin_unlock_irq(&bfqd->lock);
return 0;
queue_fail:
spin_unlock_irq(&bfqd->lock);
return 1;
}
static void bfq_idle_slice_timer_body(struct bfq_queue *bfqq)
{
struct bfq_data *bfqd = bfqq->bfqd;
enum bfqq_expiration reason;
unsigned long flags;
spin_lock_irqsave(&bfqd->lock, flags);
bfq_clear_bfqq_wait_request(bfqq);
if (bfqq != bfqd->in_service_queue) {
spin_unlock_irqrestore(&bfqd->lock, flags);
return;
}
if (bfq_bfqq_budget_timeout(bfqq))
reason = BFQQE_BUDGET_TIMEOUT;
else if (bfqq->queued[0] == 0 && bfqq->queued[1] == 0)
reason = BFQQE_TOO_IDLE;
else
goto schedule_dispatch;
bfq_bfqq_expire(bfqd, bfqq, true, reason);
schedule_dispatch:
spin_unlock_irqrestore(&bfqd->lock, flags);
bfq_schedule_dispatch(bfqd);
}
static enum hrtimer_restart bfq_idle_slice_timer(struct hrtimer *timer)
{
struct bfq_data *bfqd = container_of(timer, struct bfq_data,
idle_slice_timer);
struct bfq_queue *bfqq = bfqd->in_service_queue;
if (bfqq)
bfq_idle_slice_timer_body(bfqq);
return HRTIMER_NORESTART;
}
static void __bfq_put_async_bfqq(struct bfq_data *bfqd,
struct bfq_queue **bfqq_ptr)
{
struct bfq_queue *bfqq = *bfqq_ptr;
bfq_log(bfqd, "put_async_bfqq: %p", bfqq);
if (bfqq) {
bfq_bfqq_move(bfqd, bfqq, bfqd->root_group);
bfq_log_bfqq(bfqd, bfqq, "put_async_bfqq: putting %p, %d",
bfqq, bfqq->ref);
bfq_put_queue(bfqq);
*bfqq_ptr = NULL;
}
}
void bfq_put_async_queues(struct bfq_data *bfqd, struct bfq_group *bfqg)
{
int i, j;
for (i = 0; i < 2; i++)
for (j = 0; j < IOPRIO_BE_NR; j++)
__bfq_put_async_bfqq(bfqd, &bfqg->async_bfqq[i][j]);
__bfq_put_async_bfqq(bfqd, &bfqg->async_idle_bfqq);
}
static void bfq_exit_queue(struct elevator_queue *e)
{
struct bfq_data *bfqd = e->elevator_data;
struct bfq_queue *bfqq, *n;
hrtimer_cancel(&bfqd->idle_slice_timer);
spin_lock_irq(&bfqd->lock);
list_for_each_entry_safe(bfqq, n, &bfqd->idle_list, bfqq_list)
bfq_deactivate_bfqq(bfqd, bfqq, false, false);
spin_unlock_irq(&bfqd->lock);
hrtimer_cancel(&bfqd->idle_slice_timer);
#ifdef CONFIG_BFQ_GROUP_IOSCHED
blkcg_deactivate_policy(bfqd->queue, &blkcg_policy_bfq);
#else
spin_lock_irq(&bfqd->lock);
bfq_put_async_queues(bfqd, bfqd->root_group);
kfree(bfqd->root_group);
spin_unlock_irq(&bfqd->lock);
#endif
kfree(bfqd);
}
static void bfq_init_root_group(struct bfq_group *root_group,
struct bfq_data *bfqd)
{
int i;
#ifdef CONFIG_BFQ_GROUP_IOSCHED
root_group->entity.parent = NULL;
root_group->my_entity = NULL;
root_group->bfqd = bfqd;
#endif
root_group->rq_pos_tree = RB_ROOT;
for (i = 0; i < BFQ_IOPRIO_CLASSES; i++)
root_group->sched_data.service_tree[i] = BFQ_SERVICE_TREE_INIT;
root_group->sched_data.bfq_class_idle_last_service = jiffies;
}
static int bfq_init_queue(struct request_queue *q, struct elevator_type *e)
{
struct bfq_data *bfqd;
struct elevator_queue *eq;
eq = elevator_alloc(q, e);
if (!eq)
return -ENOMEM;
bfqd = kzalloc_node(sizeof(*bfqd), GFP_KERNEL, q->node);
if (!bfqd) {
kobject_put(&eq->kobj);
return -ENOMEM;
}
eq->elevator_data = bfqd;
spin_lock_irq(q->queue_lock);
q->elevator = eq;
spin_unlock_irq(q->queue_lock);
bfq_init_bfqq(bfqd, &bfqd->oom_bfqq, NULL, 1, 0);
bfqd->oom_bfqq.ref++;
bfqd->oom_bfqq.new_ioprio = BFQ_DEFAULT_QUEUE_IOPRIO;
bfqd->oom_bfqq.new_ioprio_class = IOPRIO_CLASS_BE;
bfqd->oom_bfqq.entity.new_weight =
bfq_ioprio_to_weight(bfqd->oom_bfqq.new_ioprio);
bfq_clear_bfqq_just_created(&bfqd->oom_bfqq);
bfqd->oom_bfqq.entity.prio_changed = 1;
bfqd->queue = q;
INIT_LIST_HEAD(&bfqd->dispatch);
hrtimer_init(&bfqd->idle_slice_timer, CLOCK_MONOTONIC,
HRTIMER_MODE_REL);
bfqd->idle_slice_timer.function = bfq_idle_slice_timer;
bfqd->queue_weights_tree = RB_ROOT;
bfqd->group_weights_tree = RB_ROOT;
INIT_LIST_HEAD(&bfqd->active_list);
INIT_LIST_HEAD(&bfqd->idle_list);
INIT_HLIST_HEAD(&bfqd->burst_list);
bfqd->hw_tag = -1;
bfqd->bfq_max_budget = bfq_default_max_budget;
bfqd->bfq_fifo_expire[0] = bfq_fifo_expire[0];
bfqd->bfq_fifo_expire[1] = bfq_fifo_expire[1];
bfqd->bfq_back_max = bfq_back_max;
bfqd->bfq_back_penalty = bfq_back_penalty;
bfqd->bfq_slice_idle = bfq_slice_idle;
bfqd->bfq_timeout = bfq_timeout;
bfqd->bfq_requests_within_timer = 120;
bfqd->bfq_large_burst_thresh = 8;
bfqd->bfq_burst_interval = msecs_to_jiffies(180);
bfqd->low_latency = true;
bfqd->bfq_wr_coeff = 30;
bfqd->bfq_wr_rt_max_time = msecs_to_jiffies(300);
bfqd->bfq_wr_max_time = 0;
bfqd->bfq_wr_min_idle_time = msecs_to_jiffies(2000);
bfqd->bfq_wr_min_inter_arr_async = msecs_to_jiffies(500);
bfqd->bfq_wr_max_softrt_rate = 7000;
bfqd->wr_busy_queues = 0;
bfqd->RT_prod = R_fast[blk_queue_nonrot(bfqd->queue)] *
T_fast[blk_queue_nonrot(bfqd->queue)];
bfqd->peak_rate = R_fast[blk_queue_nonrot(bfqd->queue)] * 2 / 3;
bfqd->device_speed = BFQ_BFQD_FAST;
spin_lock_init(&bfqd->lock);
bfqd->root_group = bfq_create_group_hierarchy(bfqd, q->node);
if (!bfqd->root_group)
goto out_free;
bfq_init_root_group(bfqd->root_group, bfqd);
bfq_init_entity(&bfqd->oom_bfqq.entity, bfqd->root_group);
return 0;
out_free:
kfree(bfqd);
kobject_put(&eq->kobj);
return -ENOMEM;
}
static void bfq_slab_kill(void)
{
kmem_cache_destroy(bfq_pool);
}
static int __init bfq_slab_setup(void)
{
bfq_pool = KMEM_CACHE(bfq_queue, 0);
if (!bfq_pool)
return -ENOMEM;
return 0;
}
static ssize_t bfq_var_show(unsigned int var, char *page)
{
return sprintf(page, "%u\n", var);
}
static ssize_t bfq_var_store(unsigned long *var, const char *page,
size_t count)
{
unsigned long new_val;
int ret = kstrtoul(page, 10, &new_val);
if (ret == 0)
*var = new_val;
return count;
}
static ssize_t bfq_max_budget_store(struct elevator_queue *e,
const char *page, size_t count)
{
struct bfq_data *bfqd = e->elevator_data;
unsigned long uninitialized_var(__data);
int ret = bfq_var_store(&__data, (page), count);
if (__data == 0)
bfqd->bfq_max_budget = bfq_calc_max_budget(bfqd);
else {
if (__data > INT_MAX)
__data = INT_MAX;
bfqd->bfq_max_budget = __data;
}
bfqd->bfq_user_max_budget = __data;
return ret;
}
static ssize_t bfq_timeout_sync_store(struct elevator_queue *e,
const char *page, size_t count)
{
struct bfq_data *bfqd = e->elevator_data;
unsigned long uninitialized_var(__data);
int ret = bfq_var_store(&__data, (page), count);
if (__data < 1)
__data = 1;
else if (__data > INT_MAX)
__data = INT_MAX;
bfqd->bfq_timeout = msecs_to_jiffies(__data);
if (bfqd->bfq_user_max_budget == 0)
bfqd->bfq_max_budget = bfq_calc_max_budget(bfqd);
return ret;
}
static ssize_t bfq_strict_guarantees_store(struct elevator_queue *e,
const char *page, size_t count)
{
struct bfq_data *bfqd = e->elevator_data;
unsigned long uninitialized_var(__data);
int ret = bfq_var_store(&__data, (page), count);
if (__data > 1)
__data = 1;
if (!bfqd->strict_guarantees && __data == 1
&& bfqd->bfq_slice_idle < 8 * NSEC_PER_MSEC)
bfqd->bfq_slice_idle = 8 * NSEC_PER_MSEC;
bfqd->strict_guarantees = __data;
return ret;
}
static ssize_t bfq_low_latency_store(struct elevator_queue *e,
const char *page, size_t count)
{
struct bfq_data *bfqd = e->elevator_data;
unsigned long uninitialized_var(__data);
int ret = bfq_var_store(&__data, (page), count);
if (__data > 1)
__data = 1;
if (__data == 0 && bfqd->low_latency != 0)
bfq_end_wr(bfqd);
bfqd->low_latency = __data;
return ret;
}
static int __init bfq_init(void)
{
int ret;
#ifdef CONFIG_BFQ_GROUP_IOSCHED
ret = blkcg_policy_register(&blkcg_policy_bfq);
if (ret)
return ret;
#endif
ret = -ENOMEM;
if (bfq_slab_setup())
goto err_pol_unreg;
T_slow[0] = msecs_to_jiffies(3500);
T_slow[1] = msecs_to_jiffies(6000);
T_fast[0] = msecs_to_jiffies(7000);
T_fast[1] = msecs_to_jiffies(2500);
device_speed_thresh[0] = (4 * R_slow[0]) / 3;
device_speed_thresh[1] = (4 * R_slow[1]) / 3;
ret = elv_register(&iosched_bfq_mq);
if (ret)
goto err_pol_unreg;
return 0;
err_pol_unreg:
#ifdef CONFIG_BFQ_GROUP_IOSCHED
blkcg_policy_unregister(&blkcg_policy_bfq);
#endif
return ret;
}
static void __exit bfq_exit(void)
{
elv_unregister(&iosched_bfq_mq);
#ifdef CONFIG_BFQ_GROUP_IOSCHED
blkcg_policy_unregister(&blkcg_policy_bfq);
#endif
bfq_slab_kill();
}
