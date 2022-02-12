static bool blk_mq_hctx_has_pending(struct blk_mq_hw_ctx *hctx)
{
unsigned int i;
for (i = 0; i < hctx->ctx_map.size; i++)
if (hctx->ctx_map.map[i].word)
return true;
return false;
}
static inline struct blk_align_bitmap *get_bm(struct blk_mq_hw_ctx *hctx,
struct blk_mq_ctx *ctx)
{
return &hctx->ctx_map.map[ctx->index_hw / hctx->ctx_map.bits_per_word];
}
static void blk_mq_hctx_mark_pending(struct blk_mq_hw_ctx *hctx,
struct blk_mq_ctx *ctx)
{
struct blk_align_bitmap *bm = get_bm(hctx, ctx);
if (!test_bit(CTX_TO_BIT(hctx, ctx), &bm->word))
set_bit(CTX_TO_BIT(hctx, ctx), &bm->word);
}
static void blk_mq_hctx_clear_pending(struct blk_mq_hw_ctx *hctx,
struct blk_mq_ctx *ctx)
{
struct blk_align_bitmap *bm = get_bm(hctx, ctx);
clear_bit(CTX_TO_BIT(hctx, ctx), &bm->word);
}
void blk_mq_freeze_queue_start(struct request_queue *q)
{
int freeze_depth;
freeze_depth = atomic_inc_return(&q->mq_freeze_depth);
if (freeze_depth == 1) {
percpu_ref_kill(&q->q_usage_counter);
blk_mq_run_hw_queues(q, false);
}
}
static void blk_mq_freeze_queue_wait(struct request_queue *q)
{
wait_event(q->mq_freeze_wq, percpu_ref_is_zero(&q->q_usage_counter));
}
void blk_freeze_queue(struct request_queue *q)
{
blk_mq_freeze_queue_start(q);
blk_mq_freeze_queue_wait(q);
}
void blk_mq_freeze_queue(struct request_queue *q)
{
blk_freeze_queue(q);
}
void blk_mq_unfreeze_queue(struct request_queue *q)
{
int freeze_depth;
freeze_depth = atomic_dec_return(&q->mq_freeze_depth);
WARN_ON_ONCE(freeze_depth < 0);
if (!freeze_depth) {
percpu_ref_reinit(&q->q_usage_counter);
wake_up_all(&q->mq_freeze_wq);
}
}
void blk_mq_wake_waiters(struct request_queue *q)
{
struct blk_mq_hw_ctx *hctx;
unsigned int i;
queue_for_each_hw_ctx(q, hctx, i)
if (blk_mq_hw_queue_mapped(hctx))
blk_mq_tag_wakeup_all(hctx->tags, true);
wake_up_all(&q->mq_freeze_wq);
}
bool blk_mq_can_queue(struct blk_mq_hw_ctx *hctx)
{
return blk_mq_has_free_tags(hctx->tags);
}
static void blk_mq_rq_ctx_init(struct request_queue *q, struct blk_mq_ctx *ctx,
struct request *rq, unsigned int rw_flags)
{
if (blk_queue_io_stat(q))
rw_flags |= REQ_IO_STAT;
INIT_LIST_HEAD(&rq->queuelist);
rq->q = q;
rq->mq_ctx = ctx;
rq->cmd_flags |= rw_flags;
rq->cpu = -1;
INIT_HLIST_NODE(&rq->hash);
RB_CLEAR_NODE(&rq->rb_node);
rq->rq_disk = NULL;
rq->part = NULL;
rq->start_time = jiffies;
#ifdef CONFIG_BLK_CGROUP
rq->rl = NULL;
set_start_time_ns(rq);
rq->io_start_time_ns = 0;
#endif
rq->nr_phys_segments = 0;
#if defined(CONFIG_BLK_DEV_INTEGRITY)
rq->nr_integrity_segments = 0;
#endif
rq->special = NULL;
rq->errors = 0;
rq->cmd = rq->__cmd;
rq->extra_len = 0;
rq->sense_len = 0;
rq->resid_len = 0;
rq->sense = NULL;
INIT_LIST_HEAD(&rq->timeout_list);
rq->timeout = 0;
rq->end_io = NULL;
rq->end_io_data = NULL;
rq->next_rq = NULL;
ctx->rq_dispatched[rw_is_sync(rw_flags)]++;
}
static struct request *
__blk_mq_alloc_request(struct blk_mq_alloc_data *data, int rw)
{
struct request *rq;
unsigned int tag;
tag = blk_mq_get_tag(data);
if (tag != BLK_MQ_TAG_FAIL) {
rq = data->hctx->tags->rqs[tag];
if (blk_mq_tag_busy(data->hctx)) {
rq->cmd_flags = REQ_MQ_INFLIGHT;
atomic_inc(&data->hctx->nr_active);
}
rq->tag = tag;
blk_mq_rq_ctx_init(data->q, data->ctx, rq, rw);
return rq;
}
return NULL;
}
struct request *blk_mq_alloc_request(struct request_queue *q, int rw,
unsigned int flags)
{
struct blk_mq_ctx *ctx;
struct blk_mq_hw_ctx *hctx;
struct request *rq;
struct blk_mq_alloc_data alloc_data;
int ret;
ret = blk_queue_enter(q, flags & BLK_MQ_REQ_NOWAIT);
if (ret)
return ERR_PTR(ret);
ctx = blk_mq_get_ctx(q);
hctx = q->mq_ops->map_queue(q, ctx->cpu);
blk_mq_set_alloc_data(&alloc_data, q, flags, ctx, hctx);
rq = __blk_mq_alloc_request(&alloc_data, rw);
if (!rq && !(flags & BLK_MQ_REQ_NOWAIT)) {
__blk_mq_run_hw_queue(hctx);
blk_mq_put_ctx(ctx);
ctx = blk_mq_get_ctx(q);
hctx = q->mq_ops->map_queue(q, ctx->cpu);
blk_mq_set_alloc_data(&alloc_data, q, flags, ctx, hctx);
rq = __blk_mq_alloc_request(&alloc_data, rw);
ctx = alloc_data.ctx;
}
blk_mq_put_ctx(ctx);
if (!rq) {
blk_queue_exit(q);
return ERR_PTR(-EWOULDBLOCK);
}
return rq;
}
static void __blk_mq_free_request(struct blk_mq_hw_ctx *hctx,
struct blk_mq_ctx *ctx, struct request *rq)
{
const int tag = rq->tag;
struct request_queue *q = rq->q;
if (rq->cmd_flags & REQ_MQ_INFLIGHT)
atomic_dec(&hctx->nr_active);
rq->cmd_flags = 0;
clear_bit(REQ_ATOM_STARTED, &rq->atomic_flags);
blk_mq_put_tag(hctx, tag, &ctx->last_tag);
blk_queue_exit(q);
}
void blk_mq_free_hctx_request(struct blk_mq_hw_ctx *hctx, struct request *rq)
{
struct blk_mq_ctx *ctx = rq->mq_ctx;
ctx->rq_completed[rq_is_sync(rq)]++;
__blk_mq_free_request(hctx, ctx, rq);
}
void blk_mq_free_request(struct request *rq)
{
struct blk_mq_hw_ctx *hctx;
struct request_queue *q = rq->q;
hctx = q->mq_ops->map_queue(q, rq->mq_ctx->cpu);
blk_mq_free_hctx_request(hctx, rq);
}
inline void __blk_mq_end_request(struct request *rq, int error)
{
blk_account_io_done(rq);
if (rq->end_io) {
rq->end_io(rq, error);
} else {
if (unlikely(blk_bidi_rq(rq)))
blk_mq_free_request(rq->next_rq);
blk_mq_free_request(rq);
}
}
void blk_mq_end_request(struct request *rq, int error)
{
if (blk_update_request(rq, error, blk_rq_bytes(rq)))
BUG();
__blk_mq_end_request(rq, error);
}
static void __blk_mq_complete_request_remote(void *data)
{
struct request *rq = data;
rq->q->softirq_done_fn(rq);
}
static void blk_mq_ipi_complete_request(struct request *rq)
{
struct blk_mq_ctx *ctx = rq->mq_ctx;
bool shared = false;
int cpu;
if (!test_bit(QUEUE_FLAG_SAME_COMP, &rq->q->queue_flags)) {
rq->q->softirq_done_fn(rq);
return;
}
cpu = get_cpu();
if (!test_bit(QUEUE_FLAG_SAME_FORCE, &rq->q->queue_flags))
shared = cpus_share_cache(cpu, ctx->cpu);
if (cpu != ctx->cpu && !shared && cpu_online(ctx->cpu)) {
rq->csd.func = __blk_mq_complete_request_remote;
rq->csd.info = rq;
rq->csd.flags = 0;
smp_call_function_single_async(ctx->cpu, &rq->csd);
} else {
rq->q->softirq_done_fn(rq);
}
put_cpu();
}
static void __blk_mq_complete_request(struct request *rq)
{
struct request_queue *q = rq->q;
if (!q->softirq_done_fn)
blk_mq_end_request(rq, rq->errors);
else
blk_mq_ipi_complete_request(rq);
}
void blk_mq_complete_request(struct request *rq, int error)
{
struct request_queue *q = rq->q;
if (unlikely(blk_should_fake_timeout(q)))
return;
if (!blk_mark_rq_complete(rq)) {
rq->errors = error;
__blk_mq_complete_request(rq);
}
}
int blk_mq_request_started(struct request *rq)
{
return test_bit(REQ_ATOM_STARTED, &rq->atomic_flags);
}
void blk_mq_start_request(struct request *rq)
{
struct request_queue *q = rq->q;
trace_block_rq_issue(q, rq);
rq->resid_len = blk_rq_bytes(rq);
if (unlikely(blk_bidi_rq(rq)))
rq->next_rq->resid_len = blk_rq_bytes(rq->next_rq);
blk_add_timer(rq);
smp_mb__before_atomic();
if (!test_bit(REQ_ATOM_STARTED, &rq->atomic_flags))
set_bit(REQ_ATOM_STARTED, &rq->atomic_flags);
if (test_bit(REQ_ATOM_COMPLETE, &rq->atomic_flags))
clear_bit(REQ_ATOM_COMPLETE, &rq->atomic_flags);
if (q->dma_drain_size && blk_rq_bytes(rq)) {
rq->nr_phys_segments++;
}
}
static void __blk_mq_requeue_request(struct request *rq)
{
struct request_queue *q = rq->q;
trace_block_rq_requeue(q, rq);
if (test_and_clear_bit(REQ_ATOM_STARTED, &rq->atomic_flags)) {
if (q->dma_drain_size && blk_rq_bytes(rq))
rq->nr_phys_segments--;
}
}
void blk_mq_requeue_request(struct request *rq)
{
__blk_mq_requeue_request(rq);
BUG_ON(blk_queued_rq(rq));
blk_mq_add_to_requeue_list(rq, true);
}
static void blk_mq_requeue_work(struct work_struct *work)
{
struct request_queue *q =
container_of(work, struct request_queue, requeue_work);
LIST_HEAD(rq_list);
struct request *rq, *next;
unsigned long flags;
spin_lock_irqsave(&q->requeue_lock, flags);
list_splice_init(&q->requeue_list, &rq_list);
spin_unlock_irqrestore(&q->requeue_lock, flags);
list_for_each_entry_safe(rq, next, &rq_list, queuelist) {
if (!(rq->cmd_flags & REQ_SOFTBARRIER))
continue;
rq->cmd_flags &= ~REQ_SOFTBARRIER;
list_del_init(&rq->queuelist);
blk_mq_insert_request(rq, true, false, false);
}
while (!list_empty(&rq_list)) {
rq = list_entry(rq_list.next, struct request, queuelist);
list_del_init(&rq->queuelist);
blk_mq_insert_request(rq, false, false, false);
}
blk_mq_start_hw_queues(q);
}
void blk_mq_add_to_requeue_list(struct request *rq, bool at_head)
{
struct request_queue *q = rq->q;
unsigned long flags;
BUG_ON(rq->cmd_flags & REQ_SOFTBARRIER);
spin_lock_irqsave(&q->requeue_lock, flags);
if (at_head) {
rq->cmd_flags |= REQ_SOFTBARRIER;
list_add(&rq->queuelist, &q->requeue_list);
} else {
list_add_tail(&rq->queuelist, &q->requeue_list);
}
spin_unlock_irqrestore(&q->requeue_lock, flags);
}
void blk_mq_cancel_requeue_work(struct request_queue *q)
{
cancel_work_sync(&q->requeue_work);
}
void blk_mq_kick_requeue_list(struct request_queue *q)
{
kblockd_schedule_work(&q->requeue_work);
}
void blk_mq_abort_requeue_list(struct request_queue *q)
{
unsigned long flags;
LIST_HEAD(rq_list);
spin_lock_irqsave(&q->requeue_lock, flags);
list_splice_init(&q->requeue_list, &rq_list);
spin_unlock_irqrestore(&q->requeue_lock, flags);
while (!list_empty(&rq_list)) {
struct request *rq;
rq = list_first_entry(&rq_list, struct request, queuelist);
list_del_init(&rq->queuelist);
rq->errors = -EIO;
blk_mq_end_request(rq, rq->errors);
}
}
struct request *blk_mq_tag_to_rq(struct blk_mq_tags *tags, unsigned int tag)
{
return tags->rqs[tag];
}
void blk_mq_rq_timed_out(struct request *req, bool reserved)
{
struct blk_mq_ops *ops = req->q->mq_ops;
enum blk_eh_timer_return ret = BLK_EH_RESET_TIMER;
if (!test_bit(REQ_ATOM_STARTED, &req->atomic_flags))
return;
if (ops->timeout)
ret = ops->timeout(req, reserved);
switch (ret) {
case BLK_EH_HANDLED:
__blk_mq_complete_request(req);
break;
case BLK_EH_RESET_TIMER:
blk_add_timer(req);
blk_clear_rq_complete(req);
break;
case BLK_EH_NOT_HANDLED:
break;
default:
printk(KERN_ERR "block: bad eh return: %d\n", ret);
break;
}
}
static void blk_mq_check_expired(struct blk_mq_hw_ctx *hctx,
struct request *rq, void *priv, bool reserved)
{
struct blk_mq_timeout_data *data = priv;
if (!test_bit(REQ_ATOM_STARTED, &rq->atomic_flags)) {
if (unlikely(blk_queue_dying(rq->q))) {
rq->errors = -EIO;
blk_mq_end_request(rq, rq->errors);
}
return;
}
if (time_after_eq(jiffies, rq->deadline)) {
if (!blk_mark_rq_complete(rq))
blk_mq_rq_timed_out(rq, reserved);
} else if (!data->next_set || time_after(data->next, rq->deadline)) {
data->next = rq->deadline;
data->next_set = 1;
}
}
static void blk_mq_timeout_work(struct work_struct *work)
{
struct request_queue *q =
container_of(work, struct request_queue, timeout_work);
struct blk_mq_timeout_data data = {
.next = 0,
.next_set = 0,
};
int i;
if (blk_queue_enter(q, true))
return;
blk_mq_queue_tag_busy_iter(q, blk_mq_check_expired, &data);
if (data.next_set) {
data.next = blk_rq_timeout(round_jiffies_up(data.next));
mod_timer(&q->timeout, data.next);
} else {
struct blk_mq_hw_ctx *hctx;
queue_for_each_hw_ctx(q, hctx, i) {
if (blk_mq_hw_queue_mapped(hctx))
blk_mq_tag_idle(hctx);
}
}
blk_queue_exit(q);
}
static bool blk_mq_attempt_merge(struct request_queue *q,
struct blk_mq_ctx *ctx, struct bio *bio)
{
struct request *rq;
int checked = 8;
list_for_each_entry_reverse(rq, &ctx->rq_list, queuelist) {
int el_ret;
if (!checked--)
break;
if (!blk_rq_merge_ok(rq, bio))
continue;
el_ret = blk_try_merge(rq, bio);
if (el_ret == ELEVATOR_BACK_MERGE) {
if (bio_attempt_back_merge(q, rq, bio)) {
ctx->rq_merged++;
return true;
}
break;
} else if (el_ret == ELEVATOR_FRONT_MERGE) {
if (bio_attempt_front_merge(q, rq, bio)) {
ctx->rq_merged++;
return true;
}
break;
}
}
return false;
}
static void flush_busy_ctxs(struct blk_mq_hw_ctx *hctx, struct list_head *list)
{
struct blk_mq_ctx *ctx;
int i;
for (i = 0; i < hctx->ctx_map.size; i++) {
struct blk_align_bitmap *bm = &hctx->ctx_map.map[i];
unsigned int off, bit;
if (!bm->word)
continue;
bit = 0;
off = i * hctx->ctx_map.bits_per_word;
do {
bit = find_next_bit(&bm->word, bm->depth, bit);
if (bit >= bm->depth)
break;
ctx = hctx->ctxs[bit + off];
clear_bit(bit, &bm->word);
spin_lock(&ctx->lock);
list_splice_tail_init(&ctx->rq_list, list);
spin_unlock(&ctx->lock);
bit++;
} while (1);
}
}
static void __blk_mq_run_hw_queue(struct blk_mq_hw_ctx *hctx)
{
struct request_queue *q = hctx->queue;
struct request *rq;
LIST_HEAD(rq_list);
LIST_HEAD(driver_list);
struct list_head *dptr;
int queued;
WARN_ON(!cpumask_test_cpu(raw_smp_processor_id(), hctx->cpumask));
if (unlikely(test_bit(BLK_MQ_S_STOPPED, &hctx->state)))
return;
hctx->run++;
flush_busy_ctxs(hctx, &rq_list);
if (!list_empty_careful(&hctx->dispatch)) {
spin_lock(&hctx->lock);
if (!list_empty(&hctx->dispatch))
list_splice_init(&hctx->dispatch, &rq_list);
spin_unlock(&hctx->lock);
}
dptr = NULL;
queued = 0;
while (!list_empty(&rq_list)) {
struct blk_mq_queue_data bd;
int ret;
rq = list_first_entry(&rq_list, struct request, queuelist);
list_del_init(&rq->queuelist);
bd.rq = rq;
bd.list = dptr;
bd.last = list_empty(&rq_list);
ret = q->mq_ops->queue_rq(hctx, &bd);
switch (ret) {
case BLK_MQ_RQ_QUEUE_OK:
queued++;
continue;
case BLK_MQ_RQ_QUEUE_BUSY:
list_add(&rq->queuelist, &rq_list);
__blk_mq_requeue_request(rq);
break;
default:
pr_err("blk-mq: bad return on queue: %d\n", ret);
case BLK_MQ_RQ_QUEUE_ERROR:
rq->errors = -EIO;
blk_mq_end_request(rq, rq->errors);
break;
}
if (ret == BLK_MQ_RQ_QUEUE_BUSY)
break;
if (!dptr && rq_list.next != rq_list.prev)
dptr = &driver_list;
}
if (!queued)
hctx->dispatched[0]++;
else if (queued < (1 << (BLK_MQ_MAX_DISPATCH_ORDER - 1)))
hctx->dispatched[ilog2(queued) + 1]++;
if (!list_empty(&rq_list)) {
spin_lock(&hctx->lock);
list_splice(&rq_list, &hctx->dispatch);
spin_unlock(&hctx->lock);
blk_mq_run_hw_queue(hctx, true);
}
}
static int blk_mq_hctx_next_cpu(struct blk_mq_hw_ctx *hctx)
{
if (hctx->queue->nr_hw_queues == 1)
return WORK_CPU_UNBOUND;
if (--hctx->next_cpu_batch <= 0) {
int cpu = hctx->next_cpu, next_cpu;
next_cpu = cpumask_next(hctx->next_cpu, hctx->cpumask);
if (next_cpu >= nr_cpu_ids)
next_cpu = cpumask_first(hctx->cpumask);
hctx->next_cpu = next_cpu;
hctx->next_cpu_batch = BLK_MQ_CPU_WORK_BATCH;
return cpu;
}
return hctx->next_cpu;
}
void blk_mq_run_hw_queue(struct blk_mq_hw_ctx *hctx, bool async)
{
if (unlikely(test_bit(BLK_MQ_S_STOPPED, &hctx->state) ||
!blk_mq_hw_queue_mapped(hctx)))
return;
if (!async) {
int cpu = get_cpu();
if (cpumask_test_cpu(cpu, hctx->cpumask)) {
__blk_mq_run_hw_queue(hctx);
put_cpu();
return;
}
put_cpu();
}
kblockd_schedule_delayed_work_on(blk_mq_hctx_next_cpu(hctx),
&hctx->run_work, 0);
}
void blk_mq_run_hw_queues(struct request_queue *q, bool async)
{
struct blk_mq_hw_ctx *hctx;
int i;
queue_for_each_hw_ctx(q, hctx, i) {
if ((!blk_mq_hctx_has_pending(hctx) &&
list_empty_careful(&hctx->dispatch)) ||
test_bit(BLK_MQ_S_STOPPED, &hctx->state))
continue;
blk_mq_run_hw_queue(hctx, async);
}
}
void blk_mq_stop_hw_queue(struct blk_mq_hw_ctx *hctx)
{
cancel_delayed_work(&hctx->run_work);
cancel_delayed_work(&hctx->delay_work);
set_bit(BLK_MQ_S_STOPPED, &hctx->state);
}
void blk_mq_stop_hw_queues(struct request_queue *q)
{
struct blk_mq_hw_ctx *hctx;
int i;
queue_for_each_hw_ctx(q, hctx, i)
blk_mq_stop_hw_queue(hctx);
}
void blk_mq_start_hw_queue(struct blk_mq_hw_ctx *hctx)
{
clear_bit(BLK_MQ_S_STOPPED, &hctx->state);
blk_mq_run_hw_queue(hctx, false);
}
void blk_mq_start_hw_queues(struct request_queue *q)
{
struct blk_mq_hw_ctx *hctx;
int i;
queue_for_each_hw_ctx(q, hctx, i)
blk_mq_start_hw_queue(hctx);
}
void blk_mq_start_stopped_hw_queues(struct request_queue *q, bool async)
{
struct blk_mq_hw_ctx *hctx;
int i;
queue_for_each_hw_ctx(q, hctx, i) {
if (!test_bit(BLK_MQ_S_STOPPED, &hctx->state))
continue;
clear_bit(BLK_MQ_S_STOPPED, &hctx->state);
blk_mq_run_hw_queue(hctx, async);
}
}
static void blk_mq_run_work_fn(struct work_struct *work)
{
struct blk_mq_hw_ctx *hctx;
hctx = container_of(work, struct blk_mq_hw_ctx, run_work.work);
__blk_mq_run_hw_queue(hctx);
}
static void blk_mq_delay_work_fn(struct work_struct *work)
{
struct blk_mq_hw_ctx *hctx;
hctx = container_of(work, struct blk_mq_hw_ctx, delay_work.work);
if (test_and_clear_bit(BLK_MQ_S_STOPPED, &hctx->state))
__blk_mq_run_hw_queue(hctx);
}
void blk_mq_delay_queue(struct blk_mq_hw_ctx *hctx, unsigned long msecs)
{
if (unlikely(!blk_mq_hw_queue_mapped(hctx)))
return;
kblockd_schedule_delayed_work_on(blk_mq_hctx_next_cpu(hctx),
&hctx->delay_work, msecs_to_jiffies(msecs));
}
static inline void __blk_mq_insert_req_list(struct blk_mq_hw_ctx *hctx,
struct blk_mq_ctx *ctx,
struct request *rq,
bool at_head)
{
trace_block_rq_insert(hctx->queue, rq);
if (at_head)
list_add(&rq->queuelist, &ctx->rq_list);
else
list_add_tail(&rq->queuelist, &ctx->rq_list);
}
static void __blk_mq_insert_request(struct blk_mq_hw_ctx *hctx,
struct request *rq, bool at_head)
{
struct blk_mq_ctx *ctx = rq->mq_ctx;
__blk_mq_insert_req_list(hctx, ctx, rq, at_head);
blk_mq_hctx_mark_pending(hctx, ctx);
}
void blk_mq_insert_request(struct request *rq, bool at_head, bool run_queue,
bool async)
{
struct request_queue *q = rq->q;
struct blk_mq_hw_ctx *hctx;
struct blk_mq_ctx *ctx = rq->mq_ctx, *current_ctx;
current_ctx = blk_mq_get_ctx(q);
if (!cpu_online(ctx->cpu))
rq->mq_ctx = ctx = current_ctx;
hctx = q->mq_ops->map_queue(q, ctx->cpu);
spin_lock(&ctx->lock);
__blk_mq_insert_request(hctx, rq, at_head);
spin_unlock(&ctx->lock);
if (run_queue)
blk_mq_run_hw_queue(hctx, async);
blk_mq_put_ctx(current_ctx);
}
static void blk_mq_insert_requests(struct request_queue *q,
struct blk_mq_ctx *ctx,
struct list_head *list,
int depth,
bool from_schedule)
{
struct blk_mq_hw_ctx *hctx;
struct blk_mq_ctx *current_ctx;
trace_block_unplug(q, depth, !from_schedule);
current_ctx = blk_mq_get_ctx(q);
if (!cpu_online(ctx->cpu))
ctx = current_ctx;
hctx = q->mq_ops->map_queue(q, ctx->cpu);
spin_lock(&ctx->lock);
while (!list_empty(list)) {
struct request *rq;
rq = list_first_entry(list, struct request, queuelist);
list_del_init(&rq->queuelist);
rq->mq_ctx = ctx;
__blk_mq_insert_req_list(hctx, ctx, rq, false);
}
blk_mq_hctx_mark_pending(hctx, ctx);
spin_unlock(&ctx->lock);
blk_mq_run_hw_queue(hctx, from_schedule);
blk_mq_put_ctx(current_ctx);
}
static int plug_ctx_cmp(void *priv, struct list_head *a, struct list_head *b)
{
struct request *rqa = container_of(a, struct request, queuelist);
struct request *rqb = container_of(b, struct request, queuelist);
return !(rqa->mq_ctx < rqb->mq_ctx ||
(rqa->mq_ctx == rqb->mq_ctx &&
blk_rq_pos(rqa) < blk_rq_pos(rqb)));
}
void blk_mq_flush_plug_list(struct blk_plug *plug, bool from_schedule)
{
struct blk_mq_ctx *this_ctx;
struct request_queue *this_q;
struct request *rq;
LIST_HEAD(list);
LIST_HEAD(ctx_list);
unsigned int depth;
list_splice_init(&plug->mq_list, &list);
list_sort(NULL, &list, plug_ctx_cmp);
this_q = NULL;
this_ctx = NULL;
depth = 0;
while (!list_empty(&list)) {
rq = list_entry_rq(list.next);
list_del_init(&rq->queuelist);
BUG_ON(!rq->q);
if (rq->mq_ctx != this_ctx) {
if (this_ctx) {
blk_mq_insert_requests(this_q, this_ctx,
&ctx_list, depth,
from_schedule);
}
this_ctx = rq->mq_ctx;
this_q = rq->q;
depth = 0;
}
depth++;
list_add_tail(&rq->queuelist, &ctx_list);
}
if (this_ctx) {
blk_mq_insert_requests(this_q, this_ctx, &ctx_list, depth,
from_schedule);
}
}
static void blk_mq_bio_to_request(struct request *rq, struct bio *bio)
{
init_request_from_bio(rq, bio);
if (blk_do_io_stat(rq))
blk_account_io_start(rq, 1);
}
static inline bool hctx_allow_merges(struct blk_mq_hw_ctx *hctx)
{
return (hctx->flags & BLK_MQ_F_SHOULD_MERGE) &&
!blk_queue_nomerges(hctx->queue);
}
static inline bool blk_mq_merge_queue_io(struct blk_mq_hw_ctx *hctx,
struct blk_mq_ctx *ctx,
struct request *rq, struct bio *bio)
{
if (!hctx_allow_merges(hctx) || !bio_mergeable(bio)) {
blk_mq_bio_to_request(rq, bio);
spin_lock(&ctx->lock);
insert_rq:
__blk_mq_insert_request(hctx, rq, false);
spin_unlock(&ctx->lock);
return false;
} else {
struct request_queue *q = hctx->queue;
spin_lock(&ctx->lock);
if (!blk_mq_attempt_merge(q, ctx, bio)) {
blk_mq_bio_to_request(rq, bio);
goto insert_rq;
}
spin_unlock(&ctx->lock);
__blk_mq_free_request(hctx, ctx, rq);
return true;
}
}
static struct request *blk_mq_map_request(struct request_queue *q,
struct bio *bio,
struct blk_map_ctx *data)
{
struct blk_mq_hw_ctx *hctx;
struct blk_mq_ctx *ctx;
struct request *rq;
int rw = bio_data_dir(bio);
struct blk_mq_alloc_data alloc_data;
blk_queue_enter_live(q);
ctx = blk_mq_get_ctx(q);
hctx = q->mq_ops->map_queue(q, ctx->cpu);
if (rw_is_sync(bio->bi_rw))
rw |= REQ_SYNC;
trace_block_getrq(q, bio, rw);
blk_mq_set_alloc_data(&alloc_data, q, BLK_MQ_REQ_NOWAIT, ctx, hctx);
rq = __blk_mq_alloc_request(&alloc_data, rw);
if (unlikely(!rq)) {
__blk_mq_run_hw_queue(hctx);
blk_mq_put_ctx(ctx);
trace_block_sleeprq(q, bio, rw);
ctx = blk_mq_get_ctx(q);
hctx = q->mq_ops->map_queue(q, ctx->cpu);
blk_mq_set_alloc_data(&alloc_data, q, 0, ctx, hctx);
rq = __blk_mq_alloc_request(&alloc_data, rw);
ctx = alloc_data.ctx;
hctx = alloc_data.hctx;
}
hctx->queued++;
data->hctx = hctx;
data->ctx = ctx;
return rq;
}
static int blk_mq_direct_issue_request(struct request *rq, blk_qc_t *cookie)
{
int ret;
struct request_queue *q = rq->q;
struct blk_mq_hw_ctx *hctx = q->mq_ops->map_queue(q,
rq->mq_ctx->cpu);
struct blk_mq_queue_data bd = {
.rq = rq,
.list = NULL,
.last = 1
};
blk_qc_t new_cookie = blk_tag_to_qc_t(rq->tag, hctx->queue_num);
ret = q->mq_ops->queue_rq(hctx, &bd);
if (ret == BLK_MQ_RQ_QUEUE_OK) {
*cookie = new_cookie;
return 0;
}
__blk_mq_requeue_request(rq);
if (ret == BLK_MQ_RQ_QUEUE_ERROR) {
*cookie = BLK_QC_T_NONE;
rq->errors = -EIO;
blk_mq_end_request(rq, rq->errors);
return 0;
}
return -1;
}
static blk_qc_t blk_mq_make_request(struct request_queue *q, struct bio *bio)
{
const int is_sync = rw_is_sync(bio->bi_rw);
const int is_flush_fua = bio->bi_rw & (REQ_FLUSH | REQ_FUA);
struct blk_map_ctx data;
struct request *rq;
unsigned int request_count = 0;
struct blk_plug *plug;
struct request *same_queue_rq = NULL;
blk_qc_t cookie;
blk_queue_bounce(q, &bio);
if (bio_integrity_enabled(bio) && bio_integrity_prep(bio)) {
bio_io_error(bio);
return BLK_QC_T_NONE;
}
blk_queue_split(q, &bio, q->bio_split);
if (!is_flush_fua && !blk_queue_nomerges(q)) {
if (blk_attempt_plug_merge(q, bio, &request_count,
&same_queue_rq))
return BLK_QC_T_NONE;
} else
request_count = blk_plug_queued_count(q);
rq = blk_mq_map_request(q, bio, &data);
if (unlikely(!rq))
return BLK_QC_T_NONE;
cookie = blk_tag_to_qc_t(rq->tag, data.hctx->queue_num);
if (unlikely(is_flush_fua)) {
blk_mq_bio_to_request(rq, bio);
blk_insert_flush(rq);
goto run_queue;
}
plug = current->plug;
if (((plug && !blk_queue_nomerges(q)) || is_sync) &&
!(data.hctx->flags & BLK_MQ_F_DEFER_ISSUE)) {
struct request *old_rq = NULL;
blk_mq_bio_to_request(rq, bio);
if (plug) {
if (same_queue_rq && !list_empty(&plug->mq_list)) {
old_rq = same_queue_rq;
list_del_init(&old_rq->queuelist);
}
list_add_tail(&rq->queuelist, &plug->mq_list);
} else
old_rq = rq;
blk_mq_put_ctx(data.ctx);
if (!old_rq)
goto done;
if (!blk_mq_direct_issue_request(old_rq, &cookie))
goto done;
blk_mq_insert_request(old_rq, false, true, true);
goto done;
}
if (!blk_mq_merge_queue_io(data.hctx, data.ctx, rq, bio)) {
run_queue:
blk_mq_run_hw_queue(data.hctx, !is_sync || is_flush_fua);
}
blk_mq_put_ctx(data.ctx);
done:
return cookie;
}
static blk_qc_t blk_sq_make_request(struct request_queue *q, struct bio *bio)
{
const int is_sync = rw_is_sync(bio->bi_rw);
const int is_flush_fua = bio->bi_rw & (REQ_FLUSH | REQ_FUA);
struct blk_plug *plug;
unsigned int request_count = 0;
struct blk_map_ctx data;
struct request *rq;
blk_qc_t cookie;
blk_queue_bounce(q, &bio);
if (bio_integrity_enabled(bio) && bio_integrity_prep(bio)) {
bio_io_error(bio);
return BLK_QC_T_NONE;
}
blk_queue_split(q, &bio, q->bio_split);
if (!is_flush_fua && !blk_queue_nomerges(q) &&
blk_attempt_plug_merge(q, bio, &request_count, NULL))
return BLK_QC_T_NONE;
rq = blk_mq_map_request(q, bio, &data);
if (unlikely(!rq))
return BLK_QC_T_NONE;
cookie = blk_tag_to_qc_t(rq->tag, data.hctx->queue_num);
if (unlikely(is_flush_fua)) {
blk_mq_bio_to_request(rq, bio);
blk_insert_flush(rq);
goto run_queue;
}
plug = current->plug;
if (plug) {
blk_mq_bio_to_request(rq, bio);
if (!request_count)
trace_block_plug(q);
blk_mq_put_ctx(data.ctx);
if (request_count >= BLK_MAX_REQUEST_COUNT) {
blk_flush_plug_list(plug, false);
trace_block_plug(q);
}
list_add_tail(&rq->queuelist, &plug->mq_list);
return cookie;
}
if (!blk_mq_merge_queue_io(data.hctx, data.ctx, rq, bio)) {
run_queue:
blk_mq_run_hw_queue(data.hctx, !is_sync || is_flush_fua);
}
blk_mq_put_ctx(data.ctx);
return cookie;
}
struct blk_mq_hw_ctx *blk_mq_map_queue(struct request_queue *q, const int cpu)
{
return q->queue_hw_ctx[q->mq_map[cpu]];
}
static void blk_mq_free_rq_map(struct blk_mq_tag_set *set,
struct blk_mq_tags *tags, unsigned int hctx_idx)
{
struct page *page;
if (tags->rqs && set->ops->exit_request) {
int i;
for (i = 0; i < tags->nr_tags; i++) {
if (!tags->rqs[i])
continue;
set->ops->exit_request(set->driver_data, tags->rqs[i],
hctx_idx, i);
tags->rqs[i] = NULL;
}
}
while (!list_empty(&tags->page_list)) {
page = list_first_entry(&tags->page_list, struct page, lru);
list_del_init(&page->lru);
kmemleak_free(page_address(page));
__free_pages(page, page->private);
}
kfree(tags->rqs);
blk_mq_free_tags(tags);
}
static size_t order_to_size(unsigned int order)
{
return (size_t)PAGE_SIZE << order;
}
static struct blk_mq_tags *blk_mq_init_rq_map(struct blk_mq_tag_set *set,
unsigned int hctx_idx)
{
struct blk_mq_tags *tags;
unsigned int i, j, entries_per_page, max_order = 4;
size_t rq_size, left;
tags = blk_mq_init_tags(set->queue_depth, set->reserved_tags,
set->numa_node,
BLK_MQ_FLAG_TO_ALLOC_POLICY(set->flags));
if (!tags)
return NULL;
INIT_LIST_HEAD(&tags->page_list);
tags->rqs = kzalloc_node(set->queue_depth * sizeof(struct request *),
GFP_KERNEL | __GFP_NOWARN | __GFP_NORETRY,
set->numa_node);
if (!tags->rqs) {
blk_mq_free_tags(tags);
return NULL;
}
rq_size = round_up(sizeof(struct request) + set->cmd_size,
cache_line_size());
left = rq_size * set->queue_depth;
for (i = 0; i < set->queue_depth; ) {
int this_order = max_order;
struct page *page;
int to_do;
void *p;
while (left < order_to_size(this_order - 1) && this_order)
this_order--;
do {
page = alloc_pages_node(set->numa_node,
GFP_KERNEL | __GFP_NOWARN | __GFP_NORETRY | __GFP_ZERO,
this_order);
if (page)
break;
if (!this_order--)
break;
if (order_to_size(this_order) < rq_size)
break;
} while (1);
if (!page)
goto fail;
page->private = this_order;
list_add_tail(&page->lru, &tags->page_list);
p = page_address(page);
kmemleak_alloc(p, order_to_size(this_order), 1, GFP_KERNEL);
entries_per_page = order_to_size(this_order) / rq_size;
to_do = min(entries_per_page, set->queue_depth - i);
left -= to_do * rq_size;
for (j = 0; j < to_do; j++) {
tags->rqs[i] = p;
if (set->ops->init_request) {
if (set->ops->init_request(set->driver_data,
tags->rqs[i], hctx_idx, i,
set->numa_node)) {
tags->rqs[i] = NULL;
goto fail;
}
}
p += rq_size;
i++;
}
}
return tags;
fail:
blk_mq_free_rq_map(set, tags, hctx_idx);
return NULL;
}
static void blk_mq_free_bitmap(struct blk_mq_ctxmap *bitmap)
{
kfree(bitmap->map);
}
static int blk_mq_alloc_bitmap(struct blk_mq_ctxmap *bitmap, int node)
{
unsigned int bpw = 8, total, num_maps, i;
bitmap->bits_per_word = bpw;
num_maps = ALIGN(nr_cpu_ids, bpw) / bpw;
bitmap->map = kzalloc_node(num_maps * sizeof(struct blk_align_bitmap),
GFP_KERNEL, node);
if (!bitmap->map)
return -ENOMEM;
total = nr_cpu_ids;
for (i = 0; i < num_maps; i++) {
bitmap->map[i].depth = min(total, bitmap->bits_per_word);
total -= bitmap->map[i].depth;
}
return 0;
}
static int blk_mq_hctx_cpu_offline(struct blk_mq_hw_ctx *hctx, int cpu)
{
struct request_queue *q = hctx->queue;
struct blk_mq_ctx *ctx;
LIST_HEAD(tmp);
ctx = __blk_mq_get_ctx(q, cpu);
spin_lock(&ctx->lock);
if (!list_empty(&ctx->rq_list)) {
list_splice_init(&ctx->rq_list, &tmp);
blk_mq_hctx_clear_pending(hctx, ctx);
}
spin_unlock(&ctx->lock);
if (list_empty(&tmp))
return NOTIFY_OK;
ctx = blk_mq_get_ctx(q);
spin_lock(&ctx->lock);
while (!list_empty(&tmp)) {
struct request *rq;
rq = list_first_entry(&tmp, struct request, queuelist);
rq->mq_ctx = ctx;
list_move_tail(&rq->queuelist, &ctx->rq_list);
}
hctx = q->mq_ops->map_queue(q, ctx->cpu);
blk_mq_hctx_mark_pending(hctx, ctx);
spin_unlock(&ctx->lock);
blk_mq_run_hw_queue(hctx, true);
blk_mq_put_ctx(ctx);
return NOTIFY_OK;
}
static int blk_mq_hctx_notify(void *data, unsigned long action,
unsigned int cpu)
{
struct blk_mq_hw_ctx *hctx = data;
if (action == CPU_DEAD || action == CPU_DEAD_FROZEN)
return blk_mq_hctx_cpu_offline(hctx, cpu);
return NOTIFY_OK;
}
static void blk_mq_exit_hctx(struct request_queue *q,
struct blk_mq_tag_set *set,
struct blk_mq_hw_ctx *hctx, unsigned int hctx_idx)
{
unsigned flush_start_tag = set->queue_depth;
blk_mq_tag_idle(hctx);
if (set->ops->exit_request)
set->ops->exit_request(set->driver_data,
hctx->fq->flush_rq, hctx_idx,
flush_start_tag + hctx_idx);
if (set->ops->exit_hctx)
set->ops->exit_hctx(hctx, hctx_idx);
blk_mq_unregister_cpu_notifier(&hctx->cpu_notifier);
blk_free_flush_queue(hctx->fq);
blk_mq_free_bitmap(&hctx->ctx_map);
}
static void blk_mq_exit_hw_queues(struct request_queue *q,
struct blk_mq_tag_set *set, int nr_queue)
{
struct blk_mq_hw_ctx *hctx;
unsigned int i;
queue_for_each_hw_ctx(q, hctx, i) {
if (i == nr_queue)
break;
blk_mq_exit_hctx(q, set, hctx, i);
}
}
static void blk_mq_free_hw_queues(struct request_queue *q,
struct blk_mq_tag_set *set)
{
struct blk_mq_hw_ctx *hctx;
unsigned int i;
queue_for_each_hw_ctx(q, hctx, i)
free_cpumask_var(hctx->cpumask);
}
static int blk_mq_init_hctx(struct request_queue *q,
struct blk_mq_tag_set *set,
struct blk_mq_hw_ctx *hctx, unsigned hctx_idx)
{
int node;
unsigned flush_start_tag = set->queue_depth;
node = hctx->numa_node;
if (node == NUMA_NO_NODE)
node = hctx->numa_node = set->numa_node;
INIT_DELAYED_WORK(&hctx->run_work, blk_mq_run_work_fn);
INIT_DELAYED_WORK(&hctx->delay_work, blk_mq_delay_work_fn);
spin_lock_init(&hctx->lock);
INIT_LIST_HEAD(&hctx->dispatch);
hctx->queue = q;
hctx->queue_num = hctx_idx;
hctx->flags = set->flags & ~BLK_MQ_F_TAG_SHARED;
blk_mq_init_cpu_notifier(&hctx->cpu_notifier,
blk_mq_hctx_notify, hctx);
blk_mq_register_cpu_notifier(&hctx->cpu_notifier);
hctx->tags = set->tags[hctx_idx];
hctx->ctxs = kmalloc_node(nr_cpu_ids * sizeof(void *),
GFP_KERNEL, node);
if (!hctx->ctxs)
goto unregister_cpu_notifier;
if (blk_mq_alloc_bitmap(&hctx->ctx_map, node))
goto free_ctxs;
hctx->nr_ctx = 0;
if (set->ops->init_hctx &&
set->ops->init_hctx(hctx, set->driver_data, hctx_idx))
goto free_bitmap;
hctx->fq = blk_alloc_flush_queue(q, hctx->numa_node, set->cmd_size);
if (!hctx->fq)
goto exit_hctx;
if (set->ops->init_request &&
set->ops->init_request(set->driver_data,
hctx->fq->flush_rq, hctx_idx,
flush_start_tag + hctx_idx, node))
goto free_fq;
return 0;
free_fq:
kfree(hctx->fq);
exit_hctx:
if (set->ops->exit_hctx)
set->ops->exit_hctx(hctx, hctx_idx);
free_bitmap:
blk_mq_free_bitmap(&hctx->ctx_map);
free_ctxs:
kfree(hctx->ctxs);
unregister_cpu_notifier:
blk_mq_unregister_cpu_notifier(&hctx->cpu_notifier);
return -1;
}
static int blk_mq_init_hw_queues(struct request_queue *q,
struct blk_mq_tag_set *set)
{
struct blk_mq_hw_ctx *hctx;
unsigned int i;
queue_for_each_hw_ctx(q, hctx, i) {
if (blk_mq_init_hctx(q, set, hctx, i))
break;
}
if (i == q->nr_hw_queues)
return 0;
blk_mq_exit_hw_queues(q, set, i);
return 1;
}
static void blk_mq_init_cpu_queues(struct request_queue *q,
unsigned int nr_hw_queues)
{
unsigned int i;
for_each_possible_cpu(i) {
struct blk_mq_ctx *__ctx = per_cpu_ptr(q->queue_ctx, i);
struct blk_mq_hw_ctx *hctx;
memset(__ctx, 0, sizeof(*__ctx));
__ctx->cpu = i;
spin_lock_init(&__ctx->lock);
INIT_LIST_HEAD(&__ctx->rq_list);
__ctx->queue = q;
if (!cpu_online(i))
continue;
hctx = q->mq_ops->map_queue(q, i);
if (nr_hw_queues > 1 && hctx->numa_node == NUMA_NO_NODE)
hctx->numa_node = local_memory_node(cpu_to_node(i));
}
}
static void blk_mq_map_swqueue(struct request_queue *q,
const struct cpumask *online_mask)
{
unsigned int i;
struct blk_mq_hw_ctx *hctx;
struct blk_mq_ctx *ctx;
struct blk_mq_tag_set *set = q->tag_set;
mutex_lock(&q->sysfs_lock);
queue_for_each_hw_ctx(q, hctx, i) {
cpumask_clear(hctx->cpumask);
hctx->nr_ctx = 0;
}
queue_for_each_ctx(q, ctx, i) {
if (!cpumask_test_cpu(i, online_mask))
continue;
hctx = q->mq_ops->map_queue(q, i);
cpumask_set_cpu(i, hctx->cpumask);
ctx->index_hw = hctx->nr_ctx;
hctx->ctxs[hctx->nr_ctx++] = ctx;
}
mutex_unlock(&q->sysfs_lock);
queue_for_each_hw_ctx(q, hctx, i) {
struct blk_mq_ctxmap *map = &hctx->ctx_map;
if (!hctx->nr_ctx) {
if (set->tags[i]) {
blk_mq_free_rq_map(set, set->tags[i], i);
set->tags[i] = NULL;
}
hctx->tags = NULL;
continue;
}
if (!set->tags[i])
set->tags[i] = blk_mq_init_rq_map(set, i);
hctx->tags = set->tags[i];
WARN_ON(!hctx->tags);
cpumask_copy(hctx->tags->cpumask, hctx->cpumask);
map->size = DIV_ROUND_UP(hctx->nr_ctx, map->bits_per_word);
hctx->next_cpu = cpumask_first(hctx->cpumask);
hctx->next_cpu_batch = BLK_MQ_CPU_WORK_BATCH;
}
}
static void queue_set_hctx_shared(struct request_queue *q, bool shared)
{
struct blk_mq_hw_ctx *hctx;
int i;
queue_for_each_hw_ctx(q, hctx, i) {
if (shared)
hctx->flags |= BLK_MQ_F_TAG_SHARED;
else
hctx->flags &= ~BLK_MQ_F_TAG_SHARED;
}
}
static void blk_mq_update_tag_set_depth(struct blk_mq_tag_set *set, bool shared)
{
struct request_queue *q;
list_for_each_entry(q, &set->tag_list, tag_set_list) {
blk_mq_freeze_queue(q);
queue_set_hctx_shared(q, shared);
blk_mq_unfreeze_queue(q);
}
}
static void blk_mq_del_queue_tag_set(struct request_queue *q)
{
struct blk_mq_tag_set *set = q->tag_set;
mutex_lock(&set->tag_list_lock);
list_del_init(&q->tag_set_list);
if (list_is_singular(&set->tag_list)) {
set->flags &= ~BLK_MQ_F_TAG_SHARED;
blk_mq_update_tag_set_depth(set, false);
}
mutex_unlock(&set->tag_list_lock);
}
static void blk_mq_add_queue_tag_set(struct blk_mq_tag_set *set,
struct request_queue *q)
{
q->tag_set = set;
mutex_lock(&set->tag_list_lock);
if (!list_empty(&set->tag_list) && !(set->flags & BLK_MQ_F_TAG_SHARED)) {
set->flags |= BLK_MQ_F_TAG_SHARED;
blk_mq_update_tag_set_depth(set, true);
}
if (set->flags & BLK_MQ_F_TAG_SHARED)
queue_set_hctx_shared(q, true);
list_add_tail(&q->tag_set_list, &set->tag_list);
mutex_unlock(&set->tag_list_lock);
}
void blk_mq_release(struct request_queue *q)
{
struct blk_mq_hw_ctx *hctx;
unsigned int i;
queue_for_each_hw_ctx(q, hctx, i) {
if (!hctx)
continue;
kfree(hctx->ctxs);
kfree(hctx);
}
kfree(q->mq_map);
q->mq_map = NULL;
kfree(q->queue_hw_ctx);
free_percpu(q->queue_ctx);
}
struct request_queue *blk_mq_init_queue(struct blk_mq_tag_set *set)
{
struct request_queue *uninit_q, *q;
uninit_q = blk_alloc_queue_node(GFP_KERNEL, set->numa_node);
if (!uninit_q)
return ERR_PTR(-ENOMEM);
q = blk_mq_init_allocated_queue(set, uninit_q);
if (IS_ERR(q))
blk_cleanup_queue(uninit_q);
return q;
}
struct request_queue *blk_mq_init_allocated_queue(struct blk_mq_tag_set *set,
struct request_queue *q)
{
struct blk_mq_hw_ctx **hctxs;
struct blk_mq_ctx __percpu *ctx;
unsigned int *map;
int i;
ctx = alloc_percpu(struct blk_mq_ctx);
if (!ctx)
return ERR_PTR(-ENOMEM);
hctxs = kmalloc_node(set->nr_hw_queues * sizeof(*hctxs), GFP_KERNEL,
set->numa_node);
if (!hctxs)
goto err_percpu;
map = blk_mq_make_queue_map(set);
if (!map)
goto err_map;
for (i = 0; i < set->nr_hw_queues; i++) {
int node = blk_mq_hw_queue_to_node(map, i);
hctxs[i] = kzalloc_node(sizeof(struct blk_mq_hw_ctx),
GFP_KERNEL, node);
if (!hctxs[i])
goto err_hctxs;
if (!zalloc_cpumask_var_node(&hctxs[i]->cpumask, GFP_KERNEL,
node))
goto err_hctxs;
atomic_set(&hctxs[i]->nr_active, 0);
hctxs[i]->numa_node = node;
hctxs[i]->queue_num = i;
}
INIT_WORK(&q->timeout_work, blk_mq_timeout_work);
blk_queue_rq_timeout(q, set->timeout ? set->timeout : 30 * HZ);
q->nr_queues = nr_cpu_ids;
q->nr_hw_queues = set->nr_hw_queues;
q->mq_map = map;
q->queue_ctx = ctx;
q->queue_hw_ctx = hctxs;
q->mq_ops = set->ops;
q->queue_flags |= QUEUE_FLAG_MQ_DEFAULT;
if (!(set->flags & BLK_MQ_F_SG_MERGE))
q->queue_flags |= 1 << QUEUE_FLAG_NO_SG_MERGE;
q->sg_reserved_size = INT_MAX;
INIT_WORK(&q->requeue_work, blk_mq_requeue_work);
INIT_LIST_HEAD(&q->requeue_list);
spin_lock_init(&q->requeue_lock);
if (q->nr_hw_queues > 1)
blk_queue_make_request(q, blk_mq_make_request);
else
blk_queue_make_request(q, blk_sq_make_request);
q->nr_requests = set->queue_depth;
if (set->ops->complete)
blk_queue_softirq_done(q, set->ops->complete);
blk_mq_init_cpu_queues(q, set->nr_hw_queues);
if (blk_mq_init_hw_queues(q, set))
goto err_hctxs;
get_online_cpus();
mutex_lock(&all_q_mutex);
list_add_tail(&q->all_q_node, &all_q_list);
blk_mq_add_queue_tag_set(set, q);
blk_mq_map_swqueue(q, cpu_online_mask);
mutex_unlock(&all_q_mutex);
put_online_cpus();
return q;
err_hctxs:
kfree(map);
for (i = 0; i < set->nr_hw_queues; i++) {
if (!hctxs[i])
break;
free_cpumask_var(hctxs[i]->cpumask);
kfree(hctxs[i]);
}
err_map:
kfree(hctxs);
err_percpu:
free_percpu(ctx);
return ERR_PTR(-ENOMEM);
}
void blk_mq_free_queue(struct request_queue *q)
{
struct blk_mq_tag_set *set = q->tag_set;
mutex_lock(&all_q_mutex);
list_del_init(&q->all_q_node);
mutex_unlock(&all_q_mutex);
blk_mq_del_queue_tag_set(q);
blk_mq_exit_hw_queues(q, set, set->nr_hw_queues);
blk_mq_free_hw_queues(q, set);
}
static void blk_mq_queue_reinit(struct request_queue *q,
const struct cpumask *online_mask)
{
WARN_ON_ONCE(!atomic_read(&q->mq_freeze_depth));
blk_mq_sysfs_unregister(q);
blk_mq_update_queue_map(q->mq_map, q->nr_hw_queues, online_mask);
blk_mq_map_swqueue(q, online_mask);
blk_mq_sysfs_register(q);
}
static int blk_mq_queue_reinit_notify(struct notifier_block *nb,
unsigned long action, void *hcpu)
{
struct request_queue *q;
int cpu = (unsigned long)hcpu;
static struct cpumask online_new;
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_DEAD:
case CPU_UP_CANCELED:
cpumask_copy(&online_new, cpu_online_mask);
break;
case CPU_UP_PREPARE:
cpumask_copy(&online_new, cpu_online_mask);
cpumask_set_cpu(cpu, &online_new);
break;
default:
return NOTIFY_OK;
}
mutex_lock(&all_q_mutex);
list_for_each_entry(q, &all_q_list, all_q_node)
blk_mq_freeze_queue_start(q);
list_for_each_entry(q, &all_q_list, all_q_node) {
blk_mq_freeze_queue_wait(q);
del_timer_sync(&q->timeout);
}
list_for_each_entry(q, &all_q_list, all_q_node)
blk_mq_queue_reinit(q, &online_new);
list_for_each_entry(q, &all_q_list, all_q_node)
blk_mq_unfreeze_queue(q);
mutex_unlock(&all_q_mutex);
return NOTIFY_OK;
}
static int __blk_mq_alloc_rq_maps(struct blk_mq_tag_set *set)
{
int i;
for (i = 0; i < set->nr_hw_queues; i++) {
set->tags[i] = blk_mq_init_rq_map(set, i);
if (!set->tags[i])
goto out_unwind;
}
return 0;
out_unwind:
while (--i >= 0)
blk_mq_free_rq_map(set, set->tags[i], i);
return -ENOMEM;
}
static int blk_mq_alloc_rq_maps(struct blk_mq_tag_set *set)
{
unsigned int depth;
int err;
depth = set->queue_depth;
do {
err = __blk_mq_alloc_rq_maps(set);
if (!err)
break;
set->queue_depth >>= 1;
if (set->queue_depth < set->reserved_tags + BLK_MQ_TAG_MIN) {
err = -ENOMEM;
break;
}
} while (set->queue_depth);
if (!set->queue_depth || err) {
pr_err("blk-mq: failed to allocate request map\n");
return -ENOMEM;
}
if (depth != set->queue_depth)
pr_info("blk-mq: reduced tag depth (%u -> %u)\n",
depth, set->queue_depth);
return 0;
}
struct cpumask *blk_mq_tags_cpumask(struct blk_mq_tags *tags)
{
return tags->cpumask;
}
int blk_mq_alloc_tag_set(struct blk_mq_tag_set *set)
{
BUILD_BUG_ON(BLK_MQ_MAX_DEPTH > 1 << BLK_MQ_UNIQUE_TAG_BITS);
if (!set->nr_hw_queues)
return -EINVAL;
if (!set->queue_depth)
return -EINVAL;
if (set->queue_depth < set->reserved_tags + BLK_MQ_TAG_MIN)
return -EINVAL;
if (!set->ops->queue_rq || !set->ops->map_queue)
return -EINVAL;
if (set->queue_depth > BLK_MQ_MAX_DEPTH) {
pr_info("blk-mq: reduced tag depth to %u\n",
BLK_MQ_MAX_DEPTH);
set->queue_depth = BLK_MQ_MAX_DEPTH;
}
if (is_kdump_kernel()) {
set->nr_hw_queues = 1;
set->queue_depth = min(64U, set->queue_depth);
}
set->tags = kmalloc_node(set->nr_hw_queues *
sizeof(struct blk_mq_tags *),
GFP_KERNEL, set->numa_node);
if (!set->tags)
return -ENOMEM;
if (blk_mq_alloc_rq_maps(set))
goto enomem;
mutex_init(&set->tag_list_lock);
INIT_LIST_HEAD(&set->tag_list);
return 0;
enomem:
kfree(set->tags);
set->tags = NULL;
return -ENOMEM;
}
void blk_mq_free_tag_set(struct blk_mq_tag_set *set)
{
int i;
for (i = 0; i < set->nr_hw_queues; i++) {
if (set->tags[i])
blk_mq_free_rq_map(set, set->tags[i], i);
}
kfree(set->tags);
set->tags = NULL;
}
int blk_mq_update_nr_requests(struct request_queue *q, unsigned int nr)
{
struct blk_mq_tag_set *set = q->tag_set;
struct blk_mq_hw_ctx *hctx;
int i, ret;
if (!set || nr > set->queue_depth)
return -EINVAL;
ret = 0;
queue_for_each_hw_ctx(q, hctx, i) {
ret = blk_mq_tag_update_depth(hctx->tags, nr);
if (ret)
break;
}
if (!ret)
q->nr_requests = nr;
return ret;
}
void blk_mq_disable_hotplug(void)
{
mutex_lock(&all_q_mutex);
}
void blk_mq_enable_hotplug(void)
{
mutex_unlock(&all_q_mutex);
}
static int __init blk_mq_init(void)
{
blk_mq_cpu_init();
hotcpu_notifier(blk_mq_queue_reinit_notify, 0);
return 0;
}
