static int mmc_prep_request(struct request_queue *q, struct request *req)
{
struct mmc_queue *mq = q->queuedata;
if (mq && (mmc_card_removed(mq->card) || mmc_access_rpmb(mq)))
return BLKPREP_KILL;
req->rq_flags |= RQF_DONTPREP;
return BLKPREP_OK;
}
static int mmc_queue_thread(void *d)
{
struct mmc_queue *mq = d;
struct request_queue *q = mq->queue;
struct mmc_context_info *cntx = &mq->card->host->context_info;
current->flags |= PF_MEMALLOC;
down(&mq->thread_sem);
do {
struct request *req;
spin_lock_irq(q->queue_lock);
set_current_state(TASK_INTERRUPTIBLE);
req = blk_fetch_request(q);
mq->asleep = false;
cntx->is_waiting_last_req = false;
cntx->is_new_req = false;
if (!req) {
if (mq->qcnt)
cntx->is_waiting_last_req = true;
else
mq->asleep = true;
}
spin_unlock_irq(q->queue_lock);
if (req || mq->qcnt) {
set_current_state(TASK_RUNNING);
mmc_blk_issue_rq(mq, req);
cond_resched();
} else {
if (kthread_should_stop()) {
set_current_state(TASK_RUNNING);
break;
}
up(&mq->thread_sem);
schedule();
down(&mq->thread_sem);
}
} while (1);
up(&mq->thread_sem);
return 0;
}
static void mmc_request_fn(struct request_queue *q)
{
struct mmc_queue *mq = q->queuedata;
struct request *req;
struct mmc_context_info *cntx;
if (!mq) {
while ((req = blk_fetch_request(q)) != NULL) {
req->rq_flags |= RQF_QUIET;
__blk_end_request_all(req, BLK_STS_IOERR);
}
return;
}
cntx = &mq->card->host->context_info;
if (cntx->is_waiting_last_req) {
cntx->is_new_req = true;
wake_up_interruptible(&cntx->wait);
}
if (mq->asleep)
wake_up_process(mq->thread);
}
static struct scatterlist *mmc_alloc_sg(int sg_len, gfp_t gfp)
{
struct scatterlist *sg;
sg = kmalloc_array(sg_len, sizeof(*sg), gfp);
if (sg)
sg_init_table(sg, sg_len);
return sg;
}
static void mmc_queue_setup_discard(struct request_queue *q,
struct mmc_card *card)
{
unsigned max_discard;
max_discard = mmc_calc_max_discard(card);
if (!max_discard)
return;
queue_flag_set_unlocked(QUEUE_FLAG_DISCARD, q);
blk_queue_max_discard_sectors(q, max_discard);
q->limits.discard_granularity = card->pref_erase << 9;
if (card->pref_erase > max_discard)
q->limits.discard_granularity = 0;
if (mmc_can_secure_erase_trim(card))
queue_flag_set_unlocked(QUEUE_FLAG_SECERASE, q);
}
static unsigned int mmc_queue_calc_bouncesz(struct mmc_host *host)
{
unsigned int bouncesz = MMC_QUEUE_BOUNCESZ;
if (host->max_segs != 1 || (host->caps & MMC_CAP_NO_BOUNCE_BUFF))
return 0;
if (bouncesz > host->max_req_size)
bouncesz = host->max_req_size;
if (bouncesz > host->max_seg_size)
bouncesz = host->max_seg_size;
if (bouncesz > host->max_blk_count * 512)
bouncesz = host->max_blk_count * 512;
if (bouncesz <= 512)
return 0;
return bouncesz;
}
static int mmc_init_request(struct request_queue *q, struct request *req,
gfp_t gfp)
{
struct mmc_queue_req *mq_rq = req_to_mmc_queue_req(req);
struct mmc_queue *mq = q->queuedata;
struct mmc_card *card = mq->card;
struct mmc_host *host = card->host;
if (card->bouncesz) {
mq_rq->bounce_buf = kmalloc(card->bouncesz, gfp);
if (!mq_rq->bounce_buf)
return -ENOMEM;
if (card->bouncesz > 512) {
mq_rq->sg = mmc_alloc_sg(1, gfp);
if (!mq_rq->sg)
return -ENOMEM;
mq_rq->bounce_sg = mmc_alloc_sg(card->bouncesz / 512,
gfp);
if (!mq_rq->bounce_sg)
return -ENOMEM;
}
} else {
mq_rq->bounce_buf = NULL;
mq_rq->bounce_sg = NULL;
mq_rq->sg = mmc_alloc_sg(host->max_segs, gfp);
if (!mq_rq->sg)
return -ENOMEM;
}
return 0;
}
static void mmc_exit_request(struct request_queue *q, struct request *req)
{
struct mmc_queue_req *mq_rq = req_to_mmc_queue_req(req);
kfree(mq_rq->bounce_sg);
mq_rq->bounce_sg = NULL;
kfree(mq_rq->bounce_buf);
mq_rq->bounce_buf = NULL;
kfree(mq_rq->sg);
mq_rq->sg = NULL;
}
int mmc_init_queue(struct mmc_queue *mq, struct mmc_card *card,
spinlock_t *lock, const char *subname)
{
struct mmc_host *host = card->host;
u64 limit = BLK_BOUNCE_HIGH;
int ret = -ENOMEM;
if (mmc_dev(host)->dma_mask && *mmc_dev(host)->dma_mask)
limit = (u64)dma_max_pfn(mmc_dev(host)) << PAGE_SHIFT;
mq->card = card;
mq->queue = blk_alloc_queue(GFP_KERNEL);
if (!mq->queue)
return -ENOMEM;
mq->queue->queue_lock = lock;
mq->queue->request_fn = mmc_request_fn;
mq->queue->init_rq_fn = mmc_init_request;
mq->queue->exit_rq_fn = mmc_exit_request;
mq->queue->cmd_size = sizeof(struct mmc_queue_req);
mq->queue->queuedata = mq;
mq->qcnt = 0;
ret = blk_init_allocated_queue(mq->queue);
if (ret) {
blk_cleanup_queue(mq->queue);
return ret;
}
blk_queue_prep_rq(mq->queue, mmc_prep_request);
queue_flag_set_unlocked(QUEUE_FLAG_NONROT, mq->queue);
queue_flag_clear_unlocked(QUEUE_FLAG_ADD_RANDOM, mq->queue);
if (mmc_can_erase(card))
mmc_queue_setup_discard(mq->queue, card);
card->bouncesz = mmc_queue_calc_bouncesz(host);
if (card->bouncesz) {
blk_queue_max_hw_sectors(mq->queue, card->bouncesz / 512);
blk_queue_max_segments(mq->queue, card->bouncesz / 512);
blk_queue_max_segment_size(mq->queue, card->bouncesz);
} else {
blk_queue_bounce_limit(mq->queue, limit);
blk_queue_max_hw_sectors(mq->queue,
min(host->max_blk_count, host->max_req_size / 512));
blk_queue_max_segments(mq->queue, host->max_segs);
blk_queue_max_segment_size(mq->queue, host->max_seg_size);
}
sema_init(&mq->thread_sem, 1);
mq->thread = kthread_run(mmc_queue_thread, mq, "mmcqd/%d%s",
host->index, subname ? subname : "");
if (IS_ERR(mq->thread)) {
ret = PTR_ERR(mq->thread);
goto cleanup_queue;
}
return 0;
cleanup_queue:
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
mq->card = NULL;
}
void mmc_queue_suspend(struct mmc_queue *mq)
{
struct request_queue *q = mq->queue;
unsigned long flags;
if (!mq->suspended) {
mq->suspended |= true;
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
if (mq->suspended) {
mq->suspended = false;
up(&mq->thread_sem);
spin_lock_irqsave(q->queue_lock, flags);
blk_start_queue(q);
spin_unlock_irqrestore(q->queue_lock, flags);
}
}
unsigned int mmc_queue_map_sg(struct mmc_queue *mq, struct mmc_queue_req *mqrq)
{
unsigned int sg_len;
size_t buflen;
struct scatterlist *sg;
struct request *req = mmc_queue_req_to_req(mqrq);
int i;
if (!mqrq->bounce_buf)
return blk_rq_map_sg(mq->queue, req, mqrq->sg);
sg_len = blk_rq_map_sg(mq->queue, req, mqrq->bounce_sg);
mqrq->bounce_sg_len = sg_len;
buflen = 0;
for_each_sg(mqrq->bounce_sg, sg, sg_len, i)
buflen += sg->length;
sg_init_one(mqrq->sg, mqrq->bounce_buf, buflen);
return 1;
}
void mmc_queue_bounce_pre(struct mmc_queue_req *mqrq)
{
if (!mqrq->bounce_buf)
return;
if (rq_data_dir(mmc_queue_req_to_req(mqrq)) != WRITE)
return;
sg_copy_to_buffer(mqrq->bounce_sg, mqrq->bounce_sg_len,
mqrq->bounce_buf, mqrq->sg[0].length);
}
void mmc_queue_bounce_post(struct mmc_queue_req *mqrq)
{
if (!mqrq->bounce_buf)
return;
if (rq_data_dir(mmc_queue_req_to_req(mqrq)) != READ)
return;
sg_copy_from_buffer(mqrq->bounce_sg, mqrq->bounce_sg_len,
mqrq->bounce_buf, mqrq->sg[0].length);
}
