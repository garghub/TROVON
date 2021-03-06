void blk_mq_sched_free_hctx_data(struct request_queue *q,
void (*exit)(struct blk_mq_hw_ctx *))
{
struct blk_mq_hw_ctx *hctx;
int i;
queue_for_each_hw_ctx(q, hctx, i) {
if (exit && hctx->sched_data)
exit(hctx);
kfree(hctx->sched_data);
hctx->sched_data = NULL;
}
}
int blk_mq_sched_init_hctx_data(struct request_queue *q, size_t size,
int (*init)(struct blk_mq_hw_ctx *),
void (*exit)(struct blk_mq_hw_ctx *))
{
struct blk_mq_hw_ctx *hctx;
int ret;
int i;
queue_for_each_hw_ctx(q, hctx, i) {
hctx->sched_data = kmalloc_node(size, GFP_KERNEL, hctx->numa_node);
if (!hctx->sched_data) {
ret = -ENOMEM;
goto error;
}
if (init) {
ret = init(hctx);
if (ret) {
kfree(hctx->sched_data);
hctx->sched_data = NULL;
goto error;
}
}
}
return 0;
error:
blk_mq_sched_free_hctx_data(q, exit);
return ret;
}
static void __blk_mq_sched_assign_ioc(struct request_queue *q,
struct request *rq,
struct bio *bio,
struct io_context *ioc)
{
struct io_cq *icq;
spin_lock_irq(q->queue_lock);
icq = ioc_lookup_icq(ioc, q);
spin_unlock_irq(q->queue_lock);
if (!icq) {
icq = ioc_create_icq(ioc, q, GFP_ATOMIC);
if (!icq)
return;
}
rq->elv.icq = icq;
if (!blk_mq_sched_get_rq_priv(q, rq, bio)) {
rq->rq_flags |= RQF_ELVPRIV;
get_io_context(icq->ioc);
return;
}
rq->elv.icq = NULL;
}
static void blk_mq_sched_assign_ioc(struct request_queue *q,
struct request *rq, struct bio *bio)
{
struct io_context *ioc;
ioc = rq_ioc(bio);
if (ioc)
__blk_mq_sched_assign_ioc(q, rq, bio, ioc);
}
struct request *blk_mq_sched_get_request(struct request_queue *q,
struct bio *bio,
unsigned int op,
struct blk_mq_alloc_data *data)
{
struct elevator_queue *e = q->elevator;
struct request *rq;
blk_queue_enter_live(q);
data->q = q;
if (likely(!data->ctx))
data->ctx = blk_mq_get_ctx(q);
if (likely(!data->hctx))
data->hctx = blk_mq_map_queue(q, data->ctx->cpu);
if (e) {
data->flags |= BLK_MQ_REQ_INTERNAL;
if (!op_is_flush(op) && e->type->ops.mq.get_request) {
rq = e->type->ops.mq.get_request(q, op, data);
if (rq)
rq->rq_flags |= RQF_QUEUED;
} else
rq = __blk_mq_alloc_request(data, op);
} else {
rq = __blk_mq_alloc_request(data, op);
}
if (rq) {
if (!op_is_flush(op)) {
rq->elv.icq = NULL;
if (e && e->type->icq_cache)
blk_mq_sched_assign_ioc(q, rq, bio);
}
data->hctx->queued++;
return rq;
}
blk_queue_exit(q);
return NULL;
}
void blk_mq_sched_put_request(struct request *rq)
{
struct request_queue *q = rq->q;
struct elevator_queue *e = q->elevator;
if (rq->rq_flags & RQF_ELVPRIV) {
blk_mq_sched_put_rq_priv(rq->q, rq);
if (rq->elv.icq) {
put_io_context(rq->elv.icq->ioc);
rq->elv.icq = NULL;
}
}
if ((rq->rq_flags & RQF_QUEUED) && e && e->type->ops.mq.put_request)
e->type->ops.mq.put_request(rq);
else
blk_mq_finish_request(rq);
}
void blk_mq_sched_dispatch_requests(struct blk_mq_hw_ctx *hctx)
{
struct request_queue *q = hctx->queue;
struct elevator_queue *e = q->elevator;
const bool has_sched_dispatch = e && e->type->ops.mq.dispatch_request;
bool did_work = false;
LIST_HEAD(rq_list);
if (unlikely(blk_mq_hctx_stopped(hctx)))
return;
hctx->run++;
if (!list_empty_careful(&hctx->dispatch)) {
spin_lock(&hctx->lock);
if (!list_empty(&hctx->dispatch))
list_splice_init(&hctx->dispatch, &rq_list);
spin_unlock(&hctx->lock);
}
if (!list_empty(&rq_list)) {
blk_mq_sched_mark_restart_hctx(hctx);
did_work = blk_mq_dispatch_rq_list(q, &rq_list);
} else if (!has_sched_dispatch) {
blk_mq_flush_busy_ctxs(hctx, &rq_list);
blk_mq_dispatch_rq_list(q, &rq_list);
}
if (!did_work && has_sched_dispatch) {
do {
struct request *rq;
rq = e->type->ops.mq.dispatch_request(hctx);
if (!rq)
break;
list_add(&rq->queuelist, &rq_list);
} while (blk_mq_dispatch_rq_list(q, &rq_list));
}
}
bool blk_mq_sched_try_merge(struct request_queue *q, struct bio *bio,
struct request **merged_request)
{
struct request *rq;
switch (elv_merge(q, &rq, bio)) {
case ELEVATOR_BACK_MERGE:
if (!blk_mq_sched_allow_merge(q, rq, bio))
return false;
if (!bio_attempt_back_merge(q, rq, bio))
return false;
*merged_request = attempt_back_merge(q, rq);
if (!*merged_request)
elv_merged_request(q, rq, ELEVATOR_BACK_MERGE);
return true;
case ELEVATOR_FRONT_MERGE:
if (!blk_mq_sched_allow_merge(q, rq, bio))
return false;
if (!bio_attempt_front_merge(q, rq, bio))
return false;
*merged_request = attempt_front_merge(q, rq);
if (!*merged_request)
elv_merged_request(q, rq, ELEVATOR_FRONT_MERGE);
return true;
default:
return false;
}
}
bool __blk_mq_sched_bio_merge(struct request_queue *q, struct bio *bio)
{
struct elevator_queue *e = q->elevator;
if (e->type->ops.mq.bio_merge) {
struct blk_mq_ctx *ctx = blk_mq_get_ctx(q);
struct blk_mq_hw_ctx *hctx = blk_mq_map_queue(q, ctx->cpu);
blk_mq_put_ctx(ctx);
return e->type->ops.mq.bio_merge(hctx, bio);
}
return false;
}
bool blk_mq_sched_try_insert_merge(struct request_queue *q, struct request *rq)
{
return rq_mergeable(rq) && elv_attempt_insert_merge(q, rq);
}
void blk_mq_sched_request_inserted(struct request *rq)
{
trace_block_rq_insert(rq->q, rq);
}
static bool blk_mq_sched_bypass_insert(struct blk_mq_hw_ctx *hctx,
struct request *rq)
{
if (rq->tag == -1) {
rq->rq_flags |= RQF_SORTED;
return false;
}
spin_lock(&hctx->lock);
list_add(&rq->queuelist, &hctx->dispatch);
spin_unlock(&hctx->lock);
return true;
}
static bool blk_mq_sched_restart_hctx(struct blk_mq_hw_ctx *hctx)
{
if (test_bit(BLK_MQ_S_SCHED_RESTART, &hctx->state)) {
clear_bit(BLK_MQ_S_SCHED_RESTART, &hctx->state);
if (blk_mq_hctx_has_pending(hctx)) {
blk_mq_run_hw_queue(hctx, true);
return true;
}
}
return false;
}
void blk_mq_sched_restart(struct blk_mq_hw_ctx *const hctx)
{
struct blk_mq_tags *const tags = hctx->tags;
struct blk_mq_tag_set *const set = hctx->queue->tag_set;
struct request_queue *const queue = hctx->queue, *q;
struct blk_mq_hw_ctx *hctx2;
unsigned int i, j;
if (set->flags & BLK_MQ_F_TAG_SHARED) {
rcu_read_lock();
list_for_each_entry_rcu_rr(q, queue, &set->tag_list,
tag_set_list) {
queue_for_each_hw_ctx(q, hctx2, i)
if (hctx2->tags == tags &&
blk_mq_sched_restart_hctx(hctx2))
goto done;
}
j = hctx->queue_num + 1;
for (i = 0; i < queue->nr_hw_queues; i++, j++) {
if (j == queue->nr_hw_queues)
j = 0;
hctx2 = queue->queue_hw_ctx[j];
if (hctx2->tags == tags &&
blk_mq_sched_restart_hctx(hctx2))
break;
}
done:
rcu_read_unlock();
} else {
blk_mq_sched_restart_hctx(hctx);
}
}
static void blk_mq_sched_insert_flush(struct blk_mq_hw_ctx *hctx,
struct request *rq, bool can_block)
{
if (blk_mq_get_driver_tag(rq, &hctx, can_block)) {
blk_insert_flush(rq);
blk_mq_run_hw_queue(hctx, true);
} else
blk_mq_add_to_requeue_list(rq, false, true);
}
void blk_mq_sched_insert_request(struct request *rq, bool at_head,
bool run_queue, bool async, bool can_block)
{
struct request_queue *q = rq->q;
struct elevator_queue *e = q->elevator;
struct blk_mq_ctx *ctx = rq->mq_ctx;
struct blk_mq_hw_ctx *hctx = blk_mq_map_queue(q, ctx->cpu);
if (rq->tag == -1 && op_is_flush(rq->cmd_flags)) {
blk_mq_sched_insert_flush(hctx, rq, can_block);
return;
}
if (e && blk_mq_sched_bypass_insert(hctx, rq))
goto run;
if (e && e->type->ops.mq.insert_requests) {
LIST_HEAD(list);
list_add(&rq->queuelist, &list);
e->type->ops.mq.insert_requests(hctx, &list, at_head);
} else {
spin_lock(&ctx->lock);
__blk_mq_insert_request(hctx, rq, at_head);
spin_unlock(&ctx->lock);
}
run:
if (run_queue)
blk_mq_run_hw_queue(hctx, async);
}
void blk_mq_sched_insert_requests(struct request_queue *q,
struct blk_mq_ctx *ctx,
struct list_head *list, bool run_queue_async)
{
struct blk_mq_hw_ctx *hctx = blk_mq_map_queue(q, ctx->cpu);
struct elevator_queue *e = hctx->queue->elevator;
if (e) {
struct request *rq, *next;
list_for_each_entry_safe(rq, next, list, queuelist) {
if (WARN_ON_ONCE(rq->tag != -1)) {
list_del_init(&rq->queuelist);
blk_mq_sched_bypass_insert(hctx, rq);
}
}
}
if (e && e->type->ops.mq.insert_requests)
e->type->ops.mq.insert_requests(hctx, list, false);
else
blk_mq_insert_requests(hctx, ctx, list);
blk_mq_run_hw_queue(hctx, run_queue_async);
}
static void blk_mq_sched_free_tags(struct blk_mq_tag_set *set,
struct blk_mq_hw_ctx *hctx,
unsigned int hctx_idx)
{
if (hctx->sched_tags) {
blk_mq_free_rqs(set, hctx->sched_tags, hctx_idx);
blk_mq_free_rq_map(hctx->sched_tags);
hctx->sched_tags = NULL;
}
}
static int blk_mq_sched_alloc_tags(struct request_queue *q,
struct blk_mq_hw_ctx *hctx,
unsigned int hctx_idx)
{
struct blk_mq_tag_set *set = q->tag_set;
int ret;
hctx->sched_tags = blk_mq_alloc_rq_map(set, hctx_idx, q->nr_requests,
set->reserved_tags);
if (!hctx->sched_tags)
return -ENOMEM;
ret = blk_mq_alloc_rqs(set, hctx->sched_tags, hctx_idx, q->nr_requests);
if (ret)
blk_mq_sched_free_tags(set, hctx, hctx_idx);
return ret;
}
static void blk_mq_sched_tags_teardown(struct request_queue *q)
{
struct blk_mq_tag_set *set = q->tag_set;
struct blk_mq_hw_ctx *hctx;
int i;
queue_for_each_hw_ctx(q, hctx, i)
blk_mq_sched_free_tags(set, hctx, i);
}
int blk_mq_sched_init_hctx(struct request_queue *q, struct blk_mq_hw_ctx *hctx,
unsigned int hctx_idx)
{
struct elevator_queue *e = q->elevator;
if (!e)
return 0;
return blk_mq_sched_alloc_tags(q, hctx, hctx_idx);
}
void blk_mq_sched_exit_hctx(struct request_queue *q, struct blk_mq_hw_ctx *hctx,
unsigned int hctx_idx)
{
struct elevator_queue *e = q->elevator;
if (!e)
return;
blk_mq_sched_free_tags(q->tag_set, hctx, hctx_idx);
}
int blk_mq_init_sched(struct request_queue *q, struct elevator_type *e)
{
struct blk_mq_hw_ctx *hctx;
unsigned int i;
int ret;
if (!e) {
q->elevator = NULL;
return 0;
}
q->nr_requests = 2 * BLKDEV_MAX_RQ;
queue_for_each_hw_ctx(q, hctx, i) {
ret = blk_mq_sched_alloc_tags(q, hctx, i);
if (ret)
goto err;
}
ret = e->ops.mq.init_sched(q, e);
if (ret)
goto err;
return 0;
err:
blk_mq_sched_tags_teardown(q);
q->elevator = NULL;
return ret;
}
void blk_mq_exit_sched(struct request_queue *q, struct elevator_queue *e)
{
if (e->type->ops.mq.exit_sched)
e->type->ops.mq.exit_sched(e);
blk_mq_sched_tags_teardown(q);
q->elevator = NULL;
}
int blk_mq_sched_init(struct request_queue *q)
{
int ret;
mutex_lock(&q->sysfs_lock);
ret = elevator_init(q, NULL);
mutex_unlock(&q->sysfs_lock);
return ret;
}
