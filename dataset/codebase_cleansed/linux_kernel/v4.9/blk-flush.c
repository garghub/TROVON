static unsigned int blk_flush_policy(unsigned long fflags, struct request *rq)
{
unsigned int policy = 0;
if (blk_rq_sectors(rq))
policy |= REQ_FSEQ_DATA;
if (fflags & (1UL << QUEUE_FLAG_WC)) {
if (rq->cmd_flags & REQ_PREFLUSH)
policy |= REQ_FSEQ_PREFLUSH;
if (!(fflags & (1UL << QUEUE_FLAG_FUA)) &&
(rq->cmd_flags & REQ_FUA))
policy |= REQ_FSEQ_POSTFLUSH;
}
return policy;
}
static unsigned int blk_flush_cur_seq(struct request *rq)
{
return 1 << ffz(rq->flush.seq);
}
static void blk_flush_restore_request(struct request *rq)
{
rq->bio = rq->biotail;
rq->cmd_flags &= ~REQ_FLUSH_SEQ;
rq->end_io = rq->flush.saved_end_io;
}
static bool blk_flush_queue_rq(struct request *rq, bool add_front)
{
if (rq->q->mq_ops) {
struct request_queue *q = rq->q;
blk_mq_add_to_requeue_list(rq, add_front);
blk_mq_kick_requeue_list(q);
return false;
} else {
if (add_front)
list_add(&rq->queuelist, &rq->q->queue_head);
else
list_add_tail(&rq->queuelist, &rq->q->queue_head);
return true;
}
}
static bool blk_flush_complete_seq(struct request *rq,
struct blk_flush_queue *fq,
unsigned int seq, int error)
{
struct request_queue *q = rq->q;
struct list_head *pending = &fq->flush_queue[fq->flush_pending_idx];
bool queued = false, kicked;
BUG_ON(rq->flush.seq & seq);
rq->flush.seq |= seq;
if (likely(!error))
seq = blk_flush_cur_seq(rq);
else
seq = REQ_FSEQ_DONE;
switch (seq) {
case REQ_FSEQ_PREFLUSH:
case REQ_FSEQ_POSTFLUSH:
if (list_empty(pending))
fq->flush_pending_since = jiffies;
list_move_tail(&rq->flush.list, pending);
break;
case REQ_FSEQ_DATA:
list_move_tail(&rq->flush.list, &fq->flush_data_in_flight);
queued = blk_flush_queue_rq(rq, true);
break;
case REQ_FSEQ_DONE:
BUG_ON(!list_empty(&rq->queuelist));
list_del_init(&rq->flush.list);
blk_flush_restore_request(rq);
if (q->mq_ops)
blk_mq_end_request(rq, error);
else
__blk_end_request_all(rq, error);
break;
default:
BUG();
}
kicked = blk_kick_flush(q, fq);
return kicked | queued;
}
static void flush_end_io(struct request *flush_rq, int error)
{
struct request_queue *q = flush_rq->q;
struct list_head *running;
bool queued = false;
struct request *rq, *n;
unsigned long flags = 0;
struct blk_flush_queue *fq = blk_get_flush_queue(q, flush_rq->mq_ctx);
if (q->mq_ops) {
struct blk_mq_hw_ctx *hctx;
spin_lock_irqsave(&fq->mq_flush_lock, flags);
hctx = blk_mq_map_queue(q, flush_rq->mq_ctx->cpu);
blk_mq_tag_set_rq(hctx, flush_rq->tag, fq->orig_rq);
flush_rq->tag = -1;
}
running = &fq->flush_queue[fq->flush_running_idx];
BUG_ON(fq->flush_pending_idx == fq->flush_running_idx);
fq->flush_running_idx ^= 1;
if (!q->mq_ops)
elv_completed_request(q, flush_rq);
list_for_each_entry_safe(rq, n, running, flush.list) {
unsigned int seq = blk_flush_cur_seq(rq);
BUG_ON(seq != REQ_FSEQ_PREFLUSH && seq != REQ_FSEQ_POSTFLUSH);
queued |= blk_flush_complete_seq(rq, fq, seq, error);
}
if (queued || fq->flush_queue_delayed) {
WARN_ON(q->mq_ops);
blk_run_queue_async(q);
}
fq->flush_queue_delayed = 0;
if (q->mq_ops)
spin_unlock_irqrestore(&fq->mq_flush_lock, flags);
}
static bool blk_kick_flush(struct request_queue *q, struct blk_flush_queue *fq)
{
struct list_head *pending = &fq->flush_queue[fq->flush_pending_idx];
struct request *first_rq =
list_first_entry(pending, struct request, flush.list);
struct request *flush_rq = fq->flush_rq;
if (fq->flush_pending_idx != fq->flush_running_idx || list_empty(pending))
return false;
if (!list_empty(&fq->flush_data_in_flight) &&
time_before(jiffies,
fq->flush_pending_since + FLUSH_PENDING_TIMEOUT))
return false;
fq->flush_pending_idx ^= 1;
blk_rq_init(q, flush_rq);
if (q->mq_ops) {
struct blk_mq_hw_ctx *hctx;
flush_rq->mq_ctx = first_rq->mq_ctx;
flush_rq->tag = first_rq->tag;
fq->orig_rq = first_rq;
hctx = blk_mq_map_queue(q, first_rq->mq_ctx->cpu);
blk_mq_tag_set_rq(hctx, first_rq->tag, flush_rq);
}
flush_rq->cmd_type = REQ_TYPE_FS;
req_set_op_attrs(flush_rq, REQ_OP_FLUSH, WRITE_FLUSH | REQ_FLUSH_SEQ);
flush_rq->rq_disk = first_rq->rq_disk;
flush_rq->end_io = flush_end_io;
return blk_flush_queue_rq(flush_rq, false);
}
static void flush_data_end_io(struct request *rq, int error)
{
struct request_queue *q = rq->q;
struct blk_flush_queue *fq = blk_get_flush_queue(q, NULL);
elv_completed_request(q, rq);
rq->cmd_flags &= ~REQ_STARTED;
if (blk_flush_complete_seq(rq, fq, REQ_FSEQ_DATA, error))
blk_run_queue_async(q);
}
static void mq_flush_data_end_io(struct request *rq, int error)
{
struct request_queue *q = rq->q;
struct blk_mq_hw_ctx *hctx;
struct blk_mq_ctx *ctx = rq->mq_ctx;
unsigned long flags;
struct blk_flush_queue *fq = blk_get_flush_queue(q, ctx);
hctx = blk_mq_map_queue(q, ctx->cpu);
spin_lock_irqsave(&fq->mq_flush_lock, flags);
if (blk_flush_complete_seq(rq, fq, REQ_FSEQ_DATA, error))
blk_mq_run_hw_queue(hctx, true);
spin_unlock_irqrestore(&fq->mq_flush_lock, flags);
}
void blk_insert_flush(struct request *rq)
{
struct request_queue *q = rq->q;
unsigned long fflags = q->queue_flags;
unsigned int policy = blk_flush_policy(fflags, rq);
struct blk_flush_queue *fq = blk_get_flush_queue(q, rq->mq_ctx);
rq->cmd_flags &= ~REQ_PREFLUSH;
if (!(fflags & (1UL << QUEUE_FLAG_FUA)))
rq->cmd_flags &= ~REQ_FUA;
if (!policy) {
if (q->mq_ops)
blk_mq_end_request(rq, 0);
else
__blk_end_bidi_request(rq, 0, 0, 0);
return;
}
BUG_ON(rq->bio != rq->biotail);
if ((policy & REQ_FSEQ_DATA) &&
!(policy & (REQ_FSEQ_PREFLUSH | REQ_FSEQ_POSTFLUSH))) {
if (q->mq_ops) {
blk_mq_insert_request(rq, false, false, true);
} else
list_add_tail(&rq->queuelist, &q->queue_head);
return;
}
memset(&rq->flush, 0, sizeof(rq->flush));
INIT_LIST_HEAD(&rq->flush.list);
rq->cmd_flags |= REQ_FLUSH_SEQ;
rq->flush.saved_end_io = rq->end_io;
if (q->mq_ops) {
rq->end_io = mq_flush_data_end_io;
spin_lock_irq(&fq->mq_flush_lock);
blk_flush_complete_seq(rq, fq, REQ_FSEQ_ACTIONS & ~policy, 0);
spin_unlock_irq(&fq->mq_flush_lock);
return;
}
rq->end_io = flush_data_end_io;
blk_flush_complete_seq(rq, fq, REQ_FSEQ_ACTIONS & ~policy, 0);
}
int blkdev_issue_flush(struct block_device *bdev, gfp_t gfp_mask,
sector_t *error_sector)
{
struct request_queue *q;
struct bio *bio;
int ret = 0;
if (bdev->bd_disk == NULL)
return -ENXIO;
q = bdev_get_queue(bdev);
if (!q)
return -ENXIO;
if (!q->make_request_fn)
return -ENXIO;
bio = bio_alloc(gfp_mask, 0);
bio->bi_bdev = bdev;
bio_set_op_attrs(bio, REQ_OP_WRITE, WRITE_FLUSH);
ret = submit_bio_wait(bio);
if (error_sector)
*error_sector = bio->bi_iter.bi_sector;
bio_put(bio);
return ret;
}
struct blk_flush_queue *blk_alloc_flush_queue(struct request_queue *q,
int node, int cmd_size)
{
struct blk_flush_queue *fq;
int rq_sz = sizeof(struct request);
fq = kzalloc_node(sizeof(*fq), GFP_KERNEL, node);
if (!fq)
goto fail;
if (q->mq_ops) {
spin_lock_init(&fq->mq_flush_lock);
rq_sz = round_up(rq_sz + cmd_size, cache_line_size());
}
fq->flush_rq = kzalloc_node(rq_sz, GFP_KERNEL, node);
if (!fq->flush_rq)
goto fail_rq;
INIT_LIST_HEAD(&fq->flush_queue[0]);
INIT_LIST_HEAD(&fq->flush_queue[1]);
INIT_LIST_HEAD(&fq->flush_data_in_flight);
return fq;
fail_rq:
kfree(fq);
fail:
return NULL;
}
void blk_free_flush_queue(struct blk_flush_queue *fq)
{
if (!fq)
return;
kfree(fq->flush_rq);
kfree(fq);
}
