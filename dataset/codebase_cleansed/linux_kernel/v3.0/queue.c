static int mmc_prep_request(struct request_queue *q, struct request *req)
{
if (req->cmd_type != REQ_TYPE_FS && !(req->cmd_flags & REQ_DISCARD)) {
blk_dump_rq_flags(req, "MMC bad request");
return BLKPREP_KILL;
}
req->cmd_flags |= REQ_DONTPREP;
return BLKPREP_OK;
}
static int mmc_queue_thread(void *d)
{
struct mmc_queue *mq = d;
struct request_queue *q = mq->queue;
current->flags |= PF_MEMALLOC;
down(&mq->thread_sem);
do {
struct request *req = NULL;
spin_lock_irq(q->queue_lock);
set_current_state(TASK_INTERRUPTIBLE);
req = blk_fetch_request(q);
mq->req = req;
spin_unlock_irq(q->queue_lock);
if (!req) {
if (kthread_should_stop()) {
set_current_state(TASK_RUNNING);
break;
}
up(&mq->thread_sem);
schedule();
down(&mq->thread_sem);
continue;
}
set_current_state(TASK_RUNNING);
mq->issue_fn(mq, req);
} while (1);
up(&mq->thread_sem);
return 0;
}
static void mmc_request(struct request_queue *q)
{
struct mmc_queue *mq = q->queuedata;
struct request *req;
if (!mq) {
while ((req = blk_fetch_request(q)) != NULL) {
req->cmd_flags |= REQ_QUIET;
__blk_end_request_all(req, -EIO);
}
return;
}
if (!mq->req)
wake_up_process(mq->thread);
}
int mmc_init_queue(struct mmc_queue *mq, struct mmc_card *card,
spinlock_t *lock, const char *subname)
{
struct mmc_host *host = card->host;
u64 limit = BLK_BOUNCE_HIGH;
int ret;
if (mmc_dev(host)->dma_mask && *mmc_dev(host)->dma_mask)
limit = *mmc_dev(host)->dma_mask;
mq->card = card;
mq->queue = blk_init_queue(mmc_request, lock);
if (!mq->queue)
return -ENOMEM;
mq->queue->queuedata = mq;
mq->req = NULL;
blk_queue_prep_rq(mq->queue, mmc_prep_request);
queue_flag_set_unlocked(QUEUE_FLAG_NONROT, mq->queue);
if (mmc_can_erase(card)) {
queue_flag_set_unlocked(QUEUE_FLAG_DISCARD, mq->queue);
mq->queue->limits.max_discard_sectors = UINT_MAX;
if (card->erased_byte == 0)
mq->queue->limits.discard_zeroes_data = 1;
mq->queue->limits.discard_granularity = card->pref_erase << 9;
if (mmc_can_secure_erase_trim(card))
queue_flag_set_unlocked(QUEUE_FLAG_SECDISCARD,
mq->queue);
}
#ifdef CONFIG_MMC_BLOCK_BOUNCE
if (host->max_segs == 1) {
unsigned int bouncesz;
bouncesz = MMC_QUEUE_BOUNCESZ;
if (bouncesz > host->max_req_size)
bouncesz = host->max_req_size;
if (bouncesz > host->max_seg_size)
bouncesz = host->max_seg_size;
if (bouncesz > (host->max_blk_count * 512))
bouncesz = host->max_blk_count * 512;
if (bouncesz > 512) {
mq->bounce_buf = kmalloc(bouncesz, GFP_KERNEL);
if (!mq->bounce_buf) {
printk(KERN_WARNING "%s: unable to "
"allocate bounce buffer\n",
mmc_card_name(card));
}
}
if (mq->bounce_buf) {
blk_queue_bounce_limit(mq->queue, BLK_BOUNCE_ANY);
blk_queue_max_hw_sectors(mq->queue, bouncesz / 512);
blk_queue_max_segments(mq->queue, bouncesz / 512);
blk_queue_max_segment_size(mq->queue, bouncesz);
mq->sg = kmalloc(sizeof(struct scatterlist),
GFP_KERNEL);
if (!mq->sg) {
ret = -ENOMEM;
goto cleanup_queue;
}
sg_init_table(mq->sg, 1);
mq->bounce_sg = kmalloc(sizeof(struct scatterlist) *
bouncesz / 512, GFP_KERNEL);
if (!mq->bounce_sg) {
ret = -ENOMEM;
goto cleanup_queue;
}
sg_init_table(mq->bounce_sg, bouncesz / 512);
}
}
#endif
if (!mq->bounce_buf) {
blk_queue_bounce_limit(mq->queue, limit);
blk_queue_max_hw_sectors(mq->queue,
min(host->max_blk_count, host->max_req_size / 512));
blk_queue_max_segments(mq->queue, host->max_segs);
blk_queue_max_segment_size(mq->queue, host->max_seg_size);
mq->sg = kmalloc(sizeof(struct scatterlist) *
host->max_segs, GFP_KERNEL);
if (!mq->sg) {
ret = -ENOMEM;
goto cleanup_queue;
}
sg_init_table(mq->sg, host->max_segs);
}
sema_init(&mq->thread_sem, 1);
mq->thread = kthread_run(mmc_queue_thread, mq, "mmcqd/%d%s",
host->index, subname ? subname : "");
if (IS_ERR(mq->thread)) {
ret = PTR_ERR(mq->thread);
goto free_bounce_sg;
}
return 0;
free_bounce_sg:
if (mq->bounce_sg)
kfree(mq->bounce_sg);
mq->bounce_sg = NULL;
cleanup_queue:
if (mq->sg)
kfree(mq->sg);
mq->sg = NULL;
if (mq->bounce_buf)
kfree(mq->bounce_buf);
mq->bounce_buf = NULL;
blk_cleanup_queue(mq->queue);
return ret;
}
void mmc_cleanup_queue(struct mmc_queue *mq)
{
struct request_queue *q = mq->queue;
unsigned long flags;
mmc_queue_resume(mq);
kthread_stop(mq->thread);
spin_lock_irqsave(q->queue_lock, flags);
q->queuedata = NULL;
blk_start_queue(q);
spin_unlock_irqrestore(q->queue_lock, flags);
if (mq->bounce_sg)
kfree(mq->bounce_sg);
mq->bounce_sg = NULL;
kfree(mq->sg);
mq->sg = NULL;
if (mq->bounce_buf)
kfree(mq->bounce_buf);
mq->bounce_buf = NULL;
mq->card = NULL;
}
void mmc_queue_suspend(struct mmc_queue *mq)
{
struct request_queue *q = mq->queue;
unsigned long flags;
if (!(mq->flags & MMC_QUEUE_SUSPENDED)) {
mq->flags |= MMC_QUEUE_SUSPENDED;
spin_lock_irqsave(q->queue_lock, flags);
blk_stop_queue(q);
spin_unlock_irqrestore(q->queue_lock, flags);
down(&mq->thread_sem);
}
}
void mmc_queue_resume(struct mmc_queue *mq)
{
struct request_queue *q = mq->queue;
unsigned long flags;
if (mq->flags & MMC_QUEUE_SUSPENDED) {
mq->flags &= ~MMC_QUEUE_SUSPENDED;
up(&mq->thread_sem);
spin_lock_irqsave(q->queue_lock, flags);
blk_start_queue(q);
spin_unlock_irqrestore(q->queue_lock, flags);
}
}
unsigned int mmc_queue_map_sg(struct mmc_queue *mq)
{
unsigned int sg_len;
size_t buflen;
struct scatterlist *sg;
int i;
if (!mq->bounce_buf)
return blk_rq_map_sg(mq->queue, mq->req, mq->sg);
BUG_ON(!mq->bounce_sg);
sg_len = blk_rq_map_sg(mq->queue, mq->req, mq->bounce_sg);
mq->bounce_sg_len = sg_len;
buflen = 0;
for_each_sg(mq->bounce_sg, sg, sg_len, i)
buflen += sg->length;
sg_init_one(mq->sg, mq->bounce_buf, buflen);
return 1;
}
void mmc_queue_bounce_pre(struct mmc_queue *mq)
{
if (!mq->bounce_buf)
return;
if (rq_data_dir(mq->req) != WRITE)
return;
sg_copy_to_buffer(mq->bounce_sg, mq->bounce_sg_len,
mq->bounce_buf, mq->sg[0].length);
}
void mmc_queue_bounce_post(struct mmc_queue *mq)
{
if (!mq->bounce_buf)
return;
if (rq_data_dir(mq->req) != READ)
return;
sg_copy_from_buffer(mq->bounce_sg, mq->bounce_sg_len,
mq->bounce_buf, mq->sg[0].length);
}
