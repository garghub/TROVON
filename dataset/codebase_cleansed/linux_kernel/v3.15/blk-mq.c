static struct blk_mq_ctx *__blk_mq_get_ctx(struct request_queue *q,
unsigned int cpu)
{
return per_cpu_ptr(q->queue_ctx, cpu);
}
static struct blk_mq_ctx *blk_mq_get_ctx(struct request_queue *q)
{
return __blk_mq_get_ctx(q, get_cpu());
}
static void blk_mq_put_ctx(struct blk_mq_ctx *ctx)
{
put_cpu();
}
static bool blk_mq_hctx_has_pending(struct blk_mq_hw_ctx *hctx)
{
unsigned int i;
for (i = 0; i < hctx->nr_ctx_map; i++)
if (hctx->ctx_map[i])
return true;
return false;
}
static void blk_mq_hctx_mark_pending(struct blk_mq_hw_ctx *hctx,
struct blk_mq_ctx *ctx)
{
if (!test_bit(ctx->index_hw, hctx->ctx_map))
set_bit(ctx->index_hw, hctx->ctx_map);
}
static struct request *__blk_mq_alloc_request(struct blk_mq_hw_ctx *hctx,
gfp_t gfp, bool reserved)
{
struct request *rq;
unsigned int tag;
tag = blk_mq_get_tag(hctx->tags, gfp, reserved);
if (tag != BLK_MQ_TAG_FAIL) {
rq = hctx->rqs[tag];
rq->tag = tag;
return rq;
}
return NULL;
}
static int blk_mq_queue_enter(struct request_queue *q)
{
int ret;
__percpu_counter_add(&q->mq_usage_counter, 1, 1000000);
smp_wmb();
if (!blk_queue_bypass(q) || !blk_queue_init_done(q))
return 0;
__percpu_counter_add(&q->mq_usage_counter, -1, 1000000);
spin_lock_irq(q->queue_lock);
ret = wait_event_interruptible_lock_irq(q->mq_freeze_wq,
!blk_queue_bypass(q) || blk_queue_dying(q),
*q->queue_lock);
if (!ret && !blk_queue_dying(q))
__percpu_counter_add(&q->mq_usage_counter, 1, 1000000);
else if (blk_queue_dying(q))
ret = -ENODEV;
spin_unlock_irq(q->queue_lock);
return ret;
}
static void blk_mq_queue_exit(struct request_queue *q)
{
__percpu_counter_add(&q->mq_usage_counter, -1, 1000000);
}
static void __blk_mq_drain_queue(struct request_queue *q)
{
while (true) {
s64 count;
spin_lock_irq(q->queue_lock);
count = percpu_counter_sum(&q->mq_usage_counter);
spin_unlock_irq(q->queue_lock);
if (count == 0)
break;
blk_mq_run_queues(q, false);
msleep(10);
}
}
static void blk_mq_freeze_queue(struct request_queue *q)
{
bool drain;
spin_lock_irq(q->queue_lock);
drain = !q->bypass_depth++;
queue_flag_set(QUEUE_FLAG_BYPASS, q);
spin_unlock_irq(q->queue_lock);
if (drain)
__blk_mq_drain_queue(q);
}
void blk_mq_drain_queue(struct request_queue *q)
{
__blk_mq_drain_queue(q);
}
static void blk_mq_unfreeze_queue(struct request_queue *q)
{
bool wake = false;
spin_lock_irq(q->queue_lock);
if (!--q->bypass_depth) {
queue_flag_clear(QUEUE_FLAG_BYPASS, q);
wake = true;
}
WARN_ON_ONCE(q->bypass_depth < 0);
spin_unlock_irq(q->queue_lock);
if (wake)
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
rq->mq_ctx = ctx;
rq->cmd_flags = rw_flags;
rq->start_time = jiffies;
set_start_time_ns(rq);
ctx->rq_dispatched[rw_is_sync(rw_flags)]++;
}
static struct request *blk_mq_alloc_request_pinned(struct request_queue *q,
int rw, gfp_t gfp,
bool reserved)
{
struct request *rq;
do {
struct blk_mq_ctx *ctx = blk_mq_get_ctx(q);
struct blk_mq_hw_ctx *hctx = q->mq_ops->map_queue(q, ctx->cpu);
rq = __blk_mq_alloc_request(hctx, gfp & ~__GFP_WAIT, reserved);
if (rq) {
blk_mq_rq_ctx_init(q, ctx, rq, rw);
break;
}
blk_mq_put_ctx(ctx);
if (!(gfp & __GFP_WAIT))
break;
__blk_mq_run_hw_queue(hctx);
blk_mq_wait_for_tags(hctx->tags);
} while (1);
return rq;
}
struct request *blk_mq_alloc_request(struct request_queue *q, int rw, gfp_t gfp)
{
struct request *rq;
if (blk_mq_queue_enter(q))
return NULL;
rq = blk_mq_alloc_request_pinned(q, rw, gfp, false);
if (rq)
blk_mq_put_ctx(rq->mq_ctx);
return rq;
}
struct request *blk_mq_alloc_reserved_request(struct request_queue *q, int rw,
gfp_t gfp)
{
struct request *rq;
if (blk_mq_queue_enter(q))
return NULL;
rq = blk_mq_alloc_request_pinned(q, rw, gfp, true);
if (rq)
blk_mq_put_ctx(rq->mq_ctx);
return rq;
}
void blk_mq_rq_init(struct blk_mq_hw_ctx *hctx, struct request *rq)
{
blk_rq_init(hctx->queue, rq);
if (hctx->cmd_size)
rq->special = blk_mq_rq_to_pdu(rq);
}
static void __blk_mq_free_request(struct blk_mq_hw_ctx *hctx,
struct blk_mq_ctx *ctx, struct request *rq)
{
const int tag = rq->tag;
struct request_queue *q = rq->q;
blk_mq_rq_init(hctx, rq);
blk_mq_put_tag(hctx->tags, tag);
blk_mq_queue_exit(q);
}
void blk_mq_free_request(struct request *rq)
{
struct blk_mq_ctx *ctx = rq->mq_ctx;
struct blk_mq_hw_ctx *hctx;
struct request_queue *q = rq->q;
ctx->rq_completed[rq_is_sync(rq)]++;
hctx = q->mq_ops->map_queue(q, ctx->cpu);
__blk_mq_free_request(hctx, ctx, rq);
}
bool blk_mq_end_io_partial(struct request *rq, int error, unsigned int nr_bytes)
{
if (blk_update_request(rq, error, blk_rq_bytes(rq)))
return true;
blk_account_io_done(rq);
if (rq->end_io)
rq->end_io(rq, error);
else
blk_mq_free_request(rq);
return false;
}
static void __blk_mq_complete_request_remote(void *data)
{
struct request *rq = data;
rq->q->softirq_done_fn(rq);
}
void __blk_mq_complete_request(struct request *rq)
{
struct blk_mq_ctx *ctx = rq->mq_ctx;
int cpu;
if (!ctx->ipi_redirect) {
rq->q->softirq_done_fn(rq);
return;
}
cpu = get_cpu();
if (cpu != ctx->cpu && cpu_online(ctx->cpu)) {
rq->csd.func = __blk_mq_complete_request_remote;
rq->csd.info = rq;
rq->csd.flags = 0;
smp_call_function_single_async(ctx->cpu, &rq->csd);
} else {
rq->q->softirq_done_fn(rq);
}
put_cpu();
}
void blk_mq_complete_request(struct request *rq)
{
if (unlikely(blk_should_fake_timeout(rq->q)))
return;
if (!blk_mark_rq_complete(rq))
__blk_mq_complete_request(rq);
}
static void blk_mq_start_request(struct request *rq, bool last)
{
struct request_queue *q = rq->q;
trace_block_rq_issue(q, rq);
rq->deadline = jiffies + q->rq_timeout;
set_bit(REQ_ATOM_STARTED, &rq->atomic_flags);
if (q->dma_drain_size && blk_rq_bytes(rq)) {
rq->nr_phys_segments++;
}
if (last)
rq->cmd_flags |= REQ_END;
}
static void blk_mq_requeue_request(struct request *rq)
{
struct request_queue *q = rq->q;
trace_block_rq_requeue(q, rq);
clear_bit(REQ_ATOM_STARTED, &rq->atomic_flags);
rq->cmd_flags &= ~REQ_END;
if (q->dma_drain_size && blk_rq_bytes(rq))
rq->nr_phys_segments--;
}
static void blk_mq_timeout_check(void *__data, unsigned long *free_tags)
{
struct blk_mq_timeout_data *data = __data;
struct blk_mq_hw_ctx *hctx = data->hctx;
unsigned int tag;
tag = 0;
do {
struct request *rq;
tag = find_next_zero_bit(free_tags, hctx->queue_depth, tag);
if (tag >= hctx->queue_depth)
break;
rq = hctx->rqs[tag++];
if (!test_bit(REQ_ATOM_STARTED, &rq->atomic_flags))
continue;
blk_rq_check_expired(rq, data->next, data->next_set);
} while (1);
}
static void blk_mq_hw_ctx_check_timeout(struct blk_mq_hw_ctx *hctx,
unsigned long *next,
unsigned int *next_set)
{
struct blk_mq_timeout_data data = {
.hctx = hctx,
.next = next,
.next_set = next_set,
};
blk_mq_tag_busy_iter(hctx->tags, blk_mq_timeout_check, &data);
}
static void blk_mq_rq_timer(unsigned long data)
{
struct request_queue *q = (struct request_queue *) data;
struct blk_mq_hw_ctx *hctx;
unsigned long next = 0;
int i, next_set = 0;
queue_for_each_hw_ctx(q, hctx, i)
blk_mq_hw_ctx_check_timeout(hctx, &next, &next_set);
if (next_set)
mod_timer(&q->timeout, round_jiffies_up(next));
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
void blk_mq_add_timer(struct request *rq)
{
__blk_add_timer(rq, NULL);
}
static void __blk_mq_run_hw_queue(struct blk_mq_hw_ctx *hctx)
{
struct request_queue *q = hctx->queue;
struct blk_mq_ctx *ctx;
struct request *rq;
LIST_HEAD(rq_list);
int bit, queued;
if (unlikely(test_bit(BLK_MQ_S_STOPPED, &hctx->state)))
return;
hctx->run++;
for_each_set_bit(bit, hctx->ctx_map, hctx->nr_ctx) {
clear_bit(bit, hctx->ctx_map);
ctx = hctx->ctxs[bit];
BUG_ON(bit != ctx->index_hw);
spin_lock(&ctx->lock);
list_splice_tail_init(&ctx->rq_list, &rq_list);
spin_unlock(&ctx->lock);
}
if (!list_empty_careful(&hctx->dispatch)) {
spin_lock(&hctx->lock);
if (!list_empty(&hctx->dispatch))
list_splice_init(&hctx->dispatch, &rq_list);
spin_unlock(&hctx->lock);
}
queued = 0;
while (!list_empty(&rq_list)) {
int ret;
rq = list_first_entry(&rq_list, struct request, queuelist);
list_del_init(&rq->queuelist);
blk_mq_start_request(rq, list_empty(&rq_list));
ret = q->mq_ops->queue_rq(hctx, rq);
switch (ret) {
case BLK_MQ_RQ_QUEUE_OK:
queued++;
continue;
case BLK_MQ_RQ_QUEUE_BUSY:
list_add(&rq->queuelist, &rq_list);
blk_mq_requeue_request(rq);
break;
default:
pr_err("blk-mq: bad return on queue: %d\n", ret);
case BLK_MQ_RQ_QUEUE_ERROR:
rq->errors = -EIO;
blk_mq_end_io(rq, rq->errors);
break;
}
if (ret == BLK_MQ_RQ_QUEUE_BUSY)
break;
}
if (!queued)
hctx->dispatched[0]++;
else if (queued < (1 << (BLK_MQ_MAX_DISPATCH_ORDER - 1)))
hctx->dispatched[ilog2(queued) + 1]++;
if (!list_empty(&rq_list)) {
spin_lock(&hctx->lock);
list_splice(&rq_list, &hctx->dispatch);
spin_unlock(&hctx->lock);
}
}
void blk_mq_run_hw_queue(struct blk_mq_hw_ctx *hctx, bool async)
{
if (unlikely(test_bit(BLK_MQ_S_STOPPED, &hctx->state)))
return;
if (!async)
__blk_mq_run_hw_queue(hctx);
else {
struct request_queue *q = hctx->queue;
kblockd_schedule_delayed_work(q, &hctx->delayed_work, 0);
}
}
void blk_mq_run_queues(struct request_queue *q, bool async)
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
cancel_delayed_work(&hctx->delayed_work);
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
__blk_mq_run_hw_queue(hctx);
}
void blk_mq_start_stopped_hw_queues(struct request_queue *q)
{
struct blk_mq_hw_ctx *hctx;
int i;
queue_for_each_hw_ctx(q, hctx, i) {
if (!test_bit(BLK_MQ_S_STOPPED, &hctx->state))
continue;
clear_bit(BLK_MQ_S_STOPPED, &hctx->state);
blk_mq_run_hw_queue(hctx, true);
}
}
static void blk_mq_work_fn(struct work_struct *work)
{
struct blk_mq_hw_ctx *hctx;
hctx = container_of(work, struct blk_mq_hw_ctx, delayed_work.work);
__blk_mq_run_hw_queue(hctx);
}
static void __blk_mq_insert_request(struct blk_mq_hw_ctx *hctx,
struct request *rq, bool at_head)
{
struct blk_mq_ctx *ctx = rq->mq_ctx;
trace_block_rq_insert(hctx->queue, rq);
if (at_head)
list_add(&rq->queuelist, &ctx->rq_list);
else
list_add_tail(&rq->queuelist, &ctx->rq_list);
blk_mq_hctx_mark_pending(hctx, ctx);
blk_mq_add_timer(rq);
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
if (rq->cmd_flags & (REQ_FLUSH | REQ_FUA) &&
!(rq->cmd_flags & (REQ_FLUSH_SEQ))) {
blk_insert_flush(rq);
} else {
spin_lock(&ctx->lock);
__blk_mq_insert_request(hctx, rq, at_head);
spin_unlock(&ctx->lock);
}
blk_mq_put_ctx(current_ctx);
if (run_queue)
blk_mq_run_hw_queue(hctx, async);
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
__blk_mq_insert_request(hctx, rq, false);
}
spin_unlock(&ctx->lock);
blk_mq_put_ctx(current_ctx);
blk_mq_run_hw_queue(hctx, from_schedule);
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
blk_account_io_start(rq, 1);
}
static void blk_mq_make_request(struct request_queue *q, struct bio *bio)
{
struct blk_mq_hw_ctx *hctx;
struct blk_mq_ctx *ctx;
const int is_sync = rw_is_sync(bio->bi_rw);
const int is_flush_fua = bio->bi_rw & (REQ_FLUSH | REQ_FUA);
int rw = bio_data_dir(bio);
struct request *rq;
unsigned int use_plug, request_count = 0;
use_plug = !is_flush_fua && ((q->nr_hw_queues == 1) || !is_sync);
blk_queue_bounce(q, &bio);
if (bio_integrity_enabled(bio) && bio_integrity_prep(bio)) {
bio_endio(bio, -EIO);
return;
}
if (use_plug && blk_attempt_plug_merge(q, bio, &request_count))
return;
if (blk_mq_queue_enter(q)) {
bio_endio(bio, -EIO);
return;
}
ctx = blk_mq_get_ctx(q);
hctx = q->mq_ops->map_queue(q, ctx->cpu);
if (is_sync)
rw |= REQ_SYNC;
trace_block_getrq(q, bio, rw);
rq = __blk_mq_alloc_request(hctx, GFP_ATOMIC, false);
if (likely(rq))
blk_mq_rq_ctx_init(q, ctx, rq, rw);
else {
blk_mq_put_ctx(ctx);
trace_block_sleeprq(q, bio, rw);
rq = blk_mq_alloc_request_pinned(q, rw, __GFP_WAIT|GFP_ATOMIC,
false);
ctx = rq->mq_ctx;
hctx = q->mq_ops->map_queue(q, ctx->cpu);
}
hctx->queued++;
if (unlikely(is_flush_fua)) {
blk_mq_bio_to_request(rq, bio);
blk_mq_put_ctx(ctx);
blk_insert_flush(rq);
goto run_queue;
}
if (use_plug) {
struct blk_plug *plug = current->plug;
if (plug) {
blk_mq_bio_to_request(rq, bio);
if (list_empty(&plug->mq_list))
trace_block_plug(q);
else if (request_count >= BLK_MAX_REQUEST_COUNT) {
blk_flush_plug_list(plug, false);
trace_block_plug(q);
}
list_add_tail(&rq->queuelist, &plug->mq_list);
blk_mq_put_ctx(ctx);
return;
}
}
spin_lock(&ctx->lock);
if ((hctx->flags & BLK_MQ_F_SHOULD_MERGE) &&
blk_mq_attempt_merge(q, ctx, bio))
__blk_mq_free_request(hctx, ctx, rq);
else {
blk_mq_bio_to_request(rq, bio);
__blk_mq_insert_request(hctx, rq, false);
}
spin_unlock(&ctx->lock);
blk_mq_put_ctx(ctx);
run_queue:
blk_mq_run_hw_queue(hctx, !is_sync || is_flush_fua);
}
struct blk_mq_hw_ctx *blk_mq_map_queue(struct request_queue *q, const int cpu)
{
return q->queue_hw_ctx[q->mq_map[cpu]];
}
struct blk_mq_hw_ctx *blk_mq_alloc_single_hw_queue(struct blk_mq_reg *reg,
unsigned int hctx_index)
{
return kmalloc_node(sizeof(struct blk_mq_hw_ctx),
GFP_KERNEL | __GFP_ZERO, reg->numa_node);
}
void blk_mq_free_single_hw_queue(struct blk_mq_hw_ctx *hctx,
unsigned int hctx_index)
{
kfree(hctx);
}
static void blk_mq_hctx_notify(void *data, unsigned long action,
unsigned int cpu)
{
struct blk_mq_hw_ctx *hctx = data;
struct request_queue *q = hctx->queue;
struct blk_mq_ctx *ctx;
LIST_HEAD(tmp);
if (action != CPU_DEAD && action != CPU_DEAD_FROZEN)
return;
ctx = __blk_mq_get_ctx(q, cpu);
spin_lock(&ctx->lock);
if (!list_empty(&ctx->rq_list)) {
list_splice_init(&ctx->rq_list, &tmp);
clear_bit(ctx->index_hw, hctx->ctx_map);
}
spin_unlock(&ctx->lock);
if (list_empty(&tmp))
return;
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
blk_mq_put_ctx(ctx);
blk_mq_run_hw_queue(hctx, true);
}
static int blk_mq_init_hw_commands(struct blk_mq_hw_ctx *hctx,
int (*init)(void *, struct blk_mq_hw_ctx *,
struct request *, unsigned int),
void *data)
{
unsigned int i;
int ret = 0;
for (i = 0; i < hctx->queue_depth; i++) {
struct request *rq = hctx->rqs[i];
ret = init(data, hctx, rq, i);
if (ret)
break;
}
return ret;
}
int blk_mq_init_commands(struct request_queue *q,
int (*init)(void *, struct blk_mq_hw_ctx *,
struct request *, unsigned int),
void *data)
{
struct blk_mq_hw_ctx *hctx;
unsigned int i;
int ret = 0;
queue_for_each_hw_ctx(q, hctx, i) {
ret = blk_mq_init_hw_commands(hctx, init, data);
if (ret)
break;
}
return ret;
}
static void blk_mq_free_hw_commands(struct blk_mq_hw_ctx *hctx,
void (*free)(void *, struct blk_mq_hw_ctx *,
struct request *, unsigned int),
void *data)
{
unsigned int i;
for (i = 0; i < hctx->queue_depth; i++) {
struct request *rq = hctx->rqs[i];
free(data, hctx, rq, i);
}
}
void blk_mq_free_commands(struct request_queue *q,
void (*free)(void *, struct blk_mq_hw_ctx *,
struct request *, unsigned int),
void *data)
{
struct blk_mq_hw_ctx *hctx;
unsigned int i;
queue_for_each_hw_ctx(q, hctx, i)
blk_mq_free_hw_commands(hctx, free, data);
}
static void blk_mq_free_rq_map(struct blk_mq_hw_ctx *hctx)
{
struct page *page;
while (!list_empty(&hctx->page_list)) {
page = list_first_entry(&hctx->page_list, struct page, lru);
list_del_init(&page->lru);
__free_pages(page, page->private);
}
kfree(hctx->rqs);
if (hctx->tags)
blk_mq_free_tags(hctx->tags);
}
static size_t order_to_size(unsigned int order)
{
size_t ret = PAGE_SIZE;
while (order--)
ret *= 2;
return ret;
}
static int blk_mq_init_rq_map(struct blk_mq_hw_ctx *hctx,
unsigned int reserved_tags, int node)
{
unsigned int i, j, entries_per_page, max_order = 4;
size_t rq_size, left;
INIT_LIST_HEAD(&hctx->page_list);
hctx->rqs = kmalloc_node(hctx->queue_depth * sizeof(struct request *),
GFP_KERNEL, node);
if (!hctx->rqs)
return -ENOMEM;
rq_size = round_up(sizeof(struct request) + hctx->cmd_size,
cache_line_size());
left = rq_size * hctx->queue_depth;
for (i = 0; i < hctx->queue_depth;) {
int this_order = max_order;
struct page *page;
int to_do;
void *p;
while (left < order_to_size(this_order - 1) && this_order)
this_order--;
do {
page = alloc_pages_node(node, GFP_KERNEL, this_order);
if (page)
break;
if (!this_order--)
break;
if (order_to_size(this_order) < rq_size)
break;
} while (1);
if (!page)
break;
page->private = this_order;
list_add_tail(&page->lru, &hctx->page_list);
p = page_address(page);
entries_per_page = order_to_size(this_order) / rq_size;
to_do = min(entries_per_page, hctx->queue_depth - i);
left -= to_do * rq_size;
for (j = 0; j < to_do; j++) {
hctx->rqs[i] = p;
blk_mq_rq_init(hctx, hctx->rqs[i]);
p += rq_size;
i++;
}
}
if (i < (reserved_tags + BLK_MQ_TAG_MIN))
goto err_rq_map;
else if (i != hctx->queue_depth) {
hctx->queue_depth = i;
pr_warn("%s: queue depth set to %u because of low memory\n",
__func__, i);
}
hctx->tags = blk_mq_init_tags(hctx->queue_depth, reserved_tags, node);
if (!hctx->tags) {
err_rq_map:
blk_mq_free_rq_map(hctx);
return -ENOMEM;
}
return 0;
}
static int blk_mq_init_hw_queues(struct request_queue *q,
struct blk_mq_reg *reg, void *driver_data)
{
struct blk_mq_hw_ctx *hctx;
unsigned int i, j;
queue_for_each_hw_ctx(q, hctx, i) {
unsigned int num_maps;
int node;
node = hctx->numa_node;
if (node == NUMA_NO_NODE)
node = hctx->numa_node = reg->numa_node;
INIT_DELAYED_WORK(&hctx->delayed_work, blk_mq_work_fn);
spin_lock_init(&hctx->lock);
INIT_LIST_HEAD(&hctx->dispatch);
hctx->queue = q;
hctx->queue_num = i;
hctx->flags = reg->flags;
hctx->queue_depth = reg->queue_depth;
hctx->cmd_size = reg->cmd_size;
blk_mq_init_cpu_notifier(&hctx->cpu_notifier,
blk_mq_hctx_notify, hctx);
blk_mq_register_cpu_notifier(&hctx->cpu_notifier);
if (blk_mq_init_rq_map(hctx, reg->reserved_tags, node))
break;
hctx->ctxs = kmalloc_node(nr_cpu_ids * sizeof(void *),
GFP_KERNEL, node);
if (!hctx->ctxs)
break;
num_maps = ALIGN(nr_cpu_ids, BITS_PER_LONG) / BITS_PER_LONG;
hctx->ctx_map = kzalloc_node(num_maps * sizeof(unsigned long),
GFP_KERNEL, node);
if (!hctx->ctx_map)
break;
hctx->nr_ctx_map = num_maps;
hctx->nr_ctx = 0;
if (reg->ops->init_hctx &&
reg->ops->init_hctx(hctx, driver_data, i))
break;
}
if (i == q->nr_hw_queues)
return 0;
queue_for_each_hw_ctx(q, hctx, j) {
if (i == j)
break;
if (reg->ops->exit_hctx)
reg->ops->exit_hctx(hctx, j);
blk_mq_unregister_cpu_notifier(&hctx->cpu_notifier);
blk_mq_free_rq_map(hctx);
kfree(hctx->ctxs);
}
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
hctx = q->mq_ops->map_queue(q, i);
hctx->nr_ctx++;
if (!cpu_online(i))
continue;
if (nr_hw_queues > 1 && hctx->numa_node == NUMA_NO_NODE)
hctx->numa_node = cpu_to_node(i);
}
}
static void blk_mq_map_swqueue(struct request_queue *q)
{
unsigned int i;
struct blk_mq_hw_ctx *hctx;
struct blk_mq_ctx *ctx;
queue_for_each_hw_ctx(q, hctx, i) {
hctx->nr_ctx = 0;
}
queue_for_each_ctx(q, ctx, i) {
hctx = q->mq_ops->map_queue(q, i);
ctx->index_hw = hctx->nr_ctx;
hctx->ctxs[hctx->nr_ctx++] = ctx;
}
}
struct request_queue *blk_mq_init_queue(struct blk_mq_reg *reg,
void *driver_data)
{
struct blk_mq_hw_ctx **hctxs;
struct blk_mq_ctx *ctx;
struct request_queue *q;
int i;
if (!reg->nr_hw_queues ||
!reg->ops->queue_rq || !reg->ops->map_queue ||
!reg->ops->alloc_hctx || !reg->ops->free_hctx)
return ERR_PTR(-EINVAL);
if (!reg->queue_depth)
reg->queue_depth = BLK_MQ_MAX_DEPTH;
else if (reg->queue_depth > BLK_MQ_MAX_DEPTH) {
pr_err("blk-mq: queuedepth too large (%u)\n", reg->queue_depth);
reg->queue_depth = BLK_MQ_MAX_DEPTH;
}
if (reg->queue_depth < (reg->reserved_tags + BLK_MQ_TAG_MIN))
return ERR_PTR(-EINVAL);
ctx = alloc_percpu(struct blk_mq_ctx);
if (!ctx)
return ERR_PTR(-ENOMEM);
hctxs = kmalloc_node(reg->nr_hw_queues * sizeof(*hctxs), GFP_KERNEL,
reg->numa_node);
if (!hctxs)
goto err_percpu;
for (i = 0; i < reg->nr_hw_queues; i++) {
hctxs[i] = reg->ops->alloc_hctx(reg, i);
if (!hctxs[i])
goto err_hctxs;
hctxs[i]->numa_node = NUMA_NO_NODE;
hctxs[i]->queue_num = i;
}
q = blk_alloc_queue_node(GFP_KERNEL, reg->numa_node);
if (!q)
goto err_hctxs;
q->mq_map = blk_mq_make_queue_map(reg);
if (!q->mq_map)
goto err_map;
setup_timer(&q->timeout, blk_mq_rq_timer, (unsigned long) q);
blk_queue_rq_timeout(q, 30000);
q->nr_queues = nr_cpu_ids;
q->nr_hw_queues = reg->nr_hw_queues;
q->queue_ctx = ctx;
q->queue_hw_ctx = hctxs;
q->mq_ops = reg->ops;
q->queue_flags |= QUEUE_FLAG_MQ_DEFAULT;
q->sg_reserved_size = INT_MAX;
blk_queue_make_request(q, blk_mq_make_request);
blk_queue_rq_timed_out(q, reg->ops->timeout);
if (reg->timeout)
blk_queue_rq_timeout(q, reg->timeout);
if (reg->ops->complete)
blk_queue_softirq_done(q, reg->ops->complete);
blk_mq_init_flush(q);
blk_mq_init_cpu_queues(q, reg->nr_hw_queues);
q->flush_rq = kzalloc(round_up(sizeof(struct request) + reg->cmd_size,
cache_line_size()), GFP_KERNEL);
if (!q->flush_rq)
goto err_hw;
if (blk_mq_init_hw_queues(q, reg, driver_data))
goto err_flush_rq;
blk_mq_map_swqueue(q);
mutex_lock(&all_q_mutex);
list_add_tail(&q->all_q_node, &all_q_list);
mutex_unlock(&all_q_mutex);
return q;
err_flush_rq:
kfree(q->flush_rq);
err_hw:
kfree(q->mq_map);
err_map:
blk_cleanup_queue(q);
err_hctxs:
for (i = 0; i < reg->nr_hw_queues; i++) {
if (!hctxs[i])
break;
reg->ops->free_hctx(hctxs[i], i);
}
kfree(hctxs);
err_percpu:
free_percpu(ctx);
return ERR_PTR(-ENOMEM);
}
void blk_mq_free_queue(struct request_queue *q)
{
struct blk_mq_hw_ctx *hctx;
int i;
queue_for_each_hw_ctx(q, hctx, i) {
kfree(hctx->ctx_map);
kfree(hctx->ctxs);
blk_mq_free_rq_map(hctx);
blk_mq_unregister_cpu_notifier(&hctx->cpu_notifier);
if (q->mq_ops->exit_hctx)
q->mq_ops->exit_hctx(hctx, i);
q->mq_ops->free_hctx(hctx, i);
}
free_percpu(q->queue_ctx);
kfree(q->queue_hw_ctx);
kfree(q->mq_map);
q->queue_ctx = NULL;
q->queue_hw_ctx = NULL;
q->mq_map = NULL;
mutex_lock(&all_q_mutex);
list_del_init(&q->all_q_node);
mutex_unlock(&all_q_mutex);
}
static void blk_mq_queue_reinit(struct request_queue *q)
{
blk_mq_freeze_queue(q);
blk_mq_update_queue_map(q->mq_map, q->nr_hw_queues);
blk_mq_map_swqueue(q);
blk_mq_unfreeze_queue(q);
}
static int blk_mq_queue_reinit_notify(struct notifier_block *nb,
unsigned long action, void *hcpu)
{
struct request_queue *q;
if (action != CPU_DEAD && action != CPU_DEAD_FROZEN &&
action != CPU_ONLINE && action != CPU_ONLINE_FROZEN)
return NOTIFY_OK;
mutex_lock(&all_q_mutex);
list_for_each_entry(q, &all_q_list, all_q_node)
blk_mq_queue_reinit(q);
mutex_unlock(&all_q_mutex);
return NOTIFY_OK;
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
hotcpu_notifier(blk_mq_queue_reinit_notify, -10);
return 0;
}
