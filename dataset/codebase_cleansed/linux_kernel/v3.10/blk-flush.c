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
}
static bool blk_flush_complete_seq(struct request *rq, unsigned int seq,
int error)
{
struct request_queue *q = rq->q;
struct list_head *pending = &q->flush_queue[q->flush_pending_idx];
bool queued = false;
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
list_add(&rq->queuelist, &q->queue_head);
queued = true;
break;
case REQ_FSEQ_DONE:
BUG_ON(!list_empty(&rq->queuelist));
list_del_init(&rq->flush.list);
blk_flush_restore_request(rq);
__blk_end_request_all(rq, error);
break;
default:
BUG();
}
return blk_kick_flush(q) | queued;
}
static void flush_end_io(struct request *flush_rq, int error)
{
struct request_queue *q = flush_rq->q;
struct list_head *running = &q->flush_queue[q->flush_running_idx];
bool queued = false;
struct request *rq, *n;
BUG_ON(q->flush_pending_idx == q->flush_running_idx);
q->flush_running_idx ^= 1;
elv_completed_request(q, flush_rq);
list_for_each_entry_safe(rq, n, running, flush.list) {
unsigned int seq = blk_flush_cur_seq(rq);
BUG_ON(seq != REQ_FSEQ_PREFLUSH && seq != REQ_FSEQ_POSTFLUSH);
queued |= blk_flush_complete_seq(rq, seq, error);
}
if (queued || q->flush_queue_delayed)
blk_run_queue_async(q);
q->flush_queue_delayed = 0;
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
blk_rq_init(q, &q->flush_rq);
q->flush_rq.cmd_type = REQ_TYPE_FS;
q->flush_rq.cmd_flags = WRITE_FLUSH | REQ_FLUSH_SEQ;
q->flush_rq.rq_disk = first_rq->rq_disk;
q->flush_rq.end_io = flush_end_io;
q->flush_pending_idx ^= 1;
list_add_tail(&q->flush_rq.queuelist, &q->queue_head);
return true;
}
static void flush_data_end_io(struct request *rq, int error)
{
struct request_queue *q = rq->q;
if (blk_flush_complete_seq(rq, REQ_FSEQ_DATA, error))
blk_run_queue_async(q);
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
__blk_end_bidi_request(rq, 0, 0, 0);
return;
}
BUG_ON(rq->bio != rq->biotail);
if ((policy & REQ_FSEQ_DATA) &&
!(policy & (REQ_FSEQ_PREFLUSH | REQ_FSEQ_POSTFLUSH))) {
list_add_tail(&rq->queuelist, &q->queue_head);
return;
}
memset(&rq->flush, 0, sizeof(rq->flush));
INIT_LIST_HEAD(&rq->flush.list);
rq->cmd_flags |= REQ_FLUSH_SEQ;
rq->flush.saved_end_io = rq->end_io;
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
static void bio_end_flush(struct bio *bio, int err)
{
if (err)
clear_bit(BIO_UPTODATE, &bio->bi_flags);
if (bio->bi_private)
complete(bio->bi_private);
bio_put(bio);
}
int blkdev_issue_flush(struct block_device *bdev, gfp_t gfp_mask,
sector_t *error_sector)
{
DECLARE_COMPLETION_ONSTACK(wait);
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
bio->bi_end_io = bio_end_flush;
bio->bi_bdev = bdev;
bio->bi_private = &wait;
bio_get(bio);
submit_bio(WRITE_FLUSH, bio);
wait_for_completion_io(&wait);
if (error_sector)
*error_sector = bio->bi_sector;
if (!bio_flagged(bio, BIO_UPTODATE))
ret = -EIO;
bio_put(bio);
return ret;
}
