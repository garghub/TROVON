static unsigned int blk_flush_policy(unsigned int fflags, struct request *rq)
{
unsigned int policy = 0;
if (blk_rq_sectors(rq))
policy |= REQ_FSEQ_DATA;
if (fflags & REQ_FLUSH) {
if (rq->cmd_flags & REQ_FLUSH)
policy |= REQ_FSEQ_PREFLUSH;
if (!(fflags & REQ_FUA) && (rq->cmd_flags & REQ_FUA))
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
blk_clear_rq_complete(rq);
}
static void mq_flush_data_run(struct work_struct *work)
{
struct request *rq;
rq = container_of(work, struct request, mq_flush_data);
memset(&rq->csd, 0, sizeof(rq->csd));
blk_mq_run_request(rq, true, false);
}
static void blk_mq_flush_data_insert(struct request *rq)
{
INIT_WORK(&rq->mq_flush_data, mq_flush_data_run);
kblockd_schedule_work(rq->q, &rq->mq_flush_data);
}
static bool blk_flush_complete_seq(struct request *rq, unsigned int seq,
int error)
{
struct request_queue *q = rq->q;
struct list_head *pending = &q->flush_queue[q->flush_pending_idx];
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
q->flush_pending_since = jiffies;
list_move_tail(&rq->flush.list, pending);
break;
case REQ_FSEQ_DATA:
list_move_tail(&rq->flush.list, &q->flush_data_in_flight);
if (q->mq_ops)
blk_mq_flush_data_insert(rq);
else {
list_add(&rq->queuelist, &q->queue_head);
queued = true;
}
break;
case REQ_FSEQ_DONE:
BUG_ON(!list_empty(&rq->queuelist));
list_del_init(&rq->flush.list);
blk_flush_restore_request(rq);
if (q->mq_ops)
blk_mq_end_io(rq, error);
else
__blk_end_request_all(rq, error);
break;
default:
BUG();
}
kicked = blk_kick_flush(q);
if (q->mq_ops)
return queued;
return kicked | queued;
}
static void flush_end_io(struct request *flush_rq, int error)
{
struct request_queue *q = flush_rq->q;
struct list_head *running;
bool queued = false;
struct request *rq, *n;
unsigned long flags = 0;
if (q->mq_ops) {
blk_mq_free_request(flush_rq);
spin_lock_irqsave(&q->mq_flush_lock, flags);
}
running = &q->flush_queue[q->flush_running_idx];
BUG_ON(q->flush_pending_idx == q->flush_running_idx);
q->flush_running_idx ^= 1;
if (!q->mq_ops)
elv_completed_request(q, flush_rq);
list_for_each_entry_safe(rq, n, running, flush.list) {
unsigned int seq = blk_flush_cur_seq(rq);
BUG_ON(seq != REQ_FSEQ_PREFLUSH && seq != REQ_FSEQ_POSTFLUSH);
queued |= blk_flush_complete_seq(rq, seq, error);
}
if (queued || q->flush_queue_delayed) {
if (!q->mq_ops)
blk_run_queue_async(q);
else
blk_mq_run_queues(q, true);
}
q->flush_queue_delayed = 0;
if (q->mq_ops)
spin_unlock_irqrestore(&q->mq_flush_lock, flags);
}
static void mq_flush_work(struct work_struct *work)
{
struct request_queue *q;
struct request *rq;
q = container_of(work, struct request_queue, mq_flush_work);
rq = blk_mq_alloc_request(q, WRITE_FLUSH|REQ_FLUSH_SEQ,
__GFP_WAIT|GFP_ATOMIC, true);
rq->cmd_type = REQ_TYPE_FS;
rq->end_io = flush_end_io;
blk_mq_run_request(rq, true, false);
}
static void mq_run_flush(struct request_queue *q)
{
kblockd_schedule_work(q, &q->mq_flush_work);
}
static bool blk_kick_flush(struct request_queue *q)
{
struct list_head *pending = &q->flush_queue[q->flush_pending_idx];
struct request *first_rq =
list_first_entry(pending, struct request, flush.list);
if (q->flush_pending_idx != q->flush_running_idx || list_empty(pending))
return false;
if (!list_empty(&q->flush_data_in_flight) &&
time_before(jiffies,
q->flush_pending_since + FLUSH_PENDING_TIMEOUT))
return false;
q->flush_pending_idx ^= 1;
if (q->mq_ops) {
mq_run_flush(q);
return true;
}
blk_rq_init(q, &q->flush_rq);
q->flush_rq.cmd_type = REQ_TYPE_FS;
q->flush_rq.cmd_flags = WRITE_FLUSH | REQ_FLUSH_SEQ;
q->flush_rq.rq_disk = first_rq->rq_disk;
q->flush_rq.end_io = flush_end_io;
list_add_tail(&q->flush_rq.queuelist, &q->queue_head);
return true;
}
static void flush_data_end_io(struct request *rq, int error)
{
struct request_queue *q = rq->q;
if (blk_flush_complete_seq(rq, REQ_FSEQ_DATA, error))
blk_run_queue_async(q);
}
static void mq_flush_data_end_io(struct request *rq, int error)
{
struct request_queue *q = rq->q;
struct blk_mq_hw_ctx *hctx;
struct blk_mq_ctx *ctx;
unsigned long flags;
ctx = rq->mq_ctx;
hctx = q->mq_ops->map_queue(q, ctx->cpu);
spin_lock_irqsave(&q->mq_flush_lock, flags);
if (blk_flush_complete_seq(rq, REQ_FSEQ_DATA, error))
blk_mq_run_hw_queue(hctx, true);
spin_unlock_irqrestore(&q->mq_flush_lock, flags);
}
void blk_insert_flush(struct request *rq)
{
struct request_queue *q = rq->q;
unsigned int fflags = q->flush_flags;
unsigned int policy = blk_flush_policy(fflags, rq);
rq->cmd_flags &= ~REQ_FLUSH;
if (!(fflags & REQ_FUA))
rq->cmd_flags &= ~REQ_FUA;
if (!policy) {
if (q->mq_ops)
blk_mq_end_io(rq, 0);
else
__blk_end_bidi_request(rq, 0, 0, 0);
return;
}
BUG_ON(rq->bio != rq->biotail);
if ((policy & REQ_FSEQ_DATA) &&
!(policy & (REQ_FSEQ_PREFLUSH | REQ_FSEQ_POSTFLUSH))) {
if (q->mq_ops) {
blk_mq_run_request(rq, false, true);
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
spin_lock_irq(&q->mq_flush_lock);
blk_flush_complete_seq(rq, REQ_FSEQ_ACTIONS & ~policy, 0);
spin_unlock_irq(&q->mq_flush_lock);
return;
}
rq->end_io = flush_data_end_io;
blk_flush_complete_seq(rq, REQ_FSEQ_ACTIONS & ~policy, 0);
}
void blk_abort_flushes(struct request_queue *q)
{
struct request *rq, *n;
int i;
list_for_each_entry_safe(rq, n, &q->flush_data_in_flight, flush.list) {
list_del_init(&rq->flush.list);
blk_flush_restore_request(rq);
}
for (i = 0; i < ARRAY_SIZE(q->flush_queue); i++) {
list_for_each_entry_safe(rq, n, &q->flush_queue[i],
flush.list) {
list_del_init(&rq->flush.list);
blk_flush_restore_request(rq);
list_add_tail(&rq->queuelist, &q->queue_head);
}
}
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
ret = submit_bio_wait(WRITE_FLUSH, bio);
if (error_sector)
*error_sector = bio->bi_sector;
bio_put(bio);
return ret;
}
void blk_mq_init_flush(struct request_queue *q)
{
spin_lock_init(&q->mq_flush_lock);
INIT_WORK(&q->mq_flush_work, mq_flush_work);
}
