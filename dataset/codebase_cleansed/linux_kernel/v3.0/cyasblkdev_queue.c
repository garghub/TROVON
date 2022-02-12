void verbose_rq_flags(int flags)
{
int i;
uint32_t j;
j = 1;
for (i = 0; i < 32; i++) {
if (flags & j)
DBGPRN("<1>%s", rq_flag_bit_names[i]);
j = j << 1;
}
}
static int cyasblkdev_prep_request(
struct request_queue *q, struct request *req)
{
DBGPRN_FUNC_NAME;
if (req->cmd_type != REQ_TYPE_FS && !(req->cmd_flags & REQ_DISCARD)) {
#ifndef WESTBRIDGE_NDEBUG
cy_as_hal_print_message("%s:%x bad request received\n",
__func__, current->pid);
#endif
blk_dump_rq_flags(req, "cyasblkdev bad request");
return BLKPREP_KILL;
}
req->cmd_flags |= REQ_DONTPREP;
return BLKPREP_OK;
}
static int cyasblkdev_queue_thread(void *d)
{
DECLARE_WAITQUEUE(wait, current);
struct cyasblkdev_queue *bq = d;
struct request_queue *q = bq->queue;
u32 qth_pid;
DBGPRN_FUNC_NAME;
daemonize("cyasblkdev_queue_thread");
complete(&bq->thread_complete);
down(&bq->thread_sem);
add_wait_queue(&bq->thread_wq, &wait);
qth_pid = current->pid;
#ifndef WESTBRIDGE_NDEBUG
cy_as_hal_print_message(
"%s:%x started, bq:%p, q:%p\n", __func__, qth_pid, bq, q);
#endif
do {
struct request *req = NULL;
set_current_state(TASK_INTERRUPTIBLE);
spin_lock_irq(q->queue_lock);
#ifndef WESTBRIDGE_NDEBUG
cy_as_hal_print_message(
"%s: for bq->queue is null\n", __func__);
#endif
if (!bq->req) {
if (!blk_queue_plugged(q)) {
bq->req = req = blk_fetch_request(q);
#ifndef WESTBRIDGE_NDEBUG
cy_as_hal_print_message(
"%s: blk_fetch_request:%x\n",
__func__, (uint32_t)req);
#endif
} else {
#ifndef WESTBRIDGE_NDEBUG
cy_as_hal_print_message(
"%s: queue plugged, "
"skip blk_fetch()\n", __func__);
#endif
}
}
spin_unlock_irq(q->queue_lock);
#ifndef WESTBRIDGE_NDEBUG
cy_as_hal_print_message(
"%s: checking if request queue is null\n", __func__);
#endif
if (!req) {
if (bq->flags & CYASBLKDEV_QUEUE_EXIT) {
#ifndef WESTBRIDGE_NDEBUG
cy_as_hal_print_message(
"%s:got QUEUE_EXIT flag\n", __func__);
#endif
break;
}
#ifndef WESTBRIDGE_NDEBUG
cy_as_hal_print_message(
"%s: request queue is null, goto sleep, "
"thread_sem->count=%d\n",
__func__, bq->thread_sem.count);
if (spin_is_locked(q->queue_lock)) {
cy_as_hal_print_message("%s: queue_lock "
"is locked, need to release\n", __func__);
spin_unlock(q->queue_lock);
if (spin_is_locked(q->queue_lock))
cy_as_hal_print_message(
"%s: unlock did not work\n",
__func__);
} else {
cy_as_hal_print_message(
"%s: checked lock, is not locked\n",
__func__);
}
#endif
up(&bq->thread_sem);
schedule();
down(&bq->thread_sem);
#ifndef WESTBRIDGE_NDEBUG
cy_as_hal_print_message(
"%s: wake_up,continue\n",
__func__);
#endif
continue;
}
set_current_state(TASK_RUNNING);
#ifndef WESTBRIDGE_NDEBUG
cy_as_hal_print_message(
"%s: issued a RQ:%x\n",
__func__, (uint32_t)req);
#endif
bq->issue_fn(bq, req);
#ifndef WESTBRIDGE_NDEBUG
cy_as_hal_print_message(
"%s: bq->issue_fn() returned\n",
__func__);
#endif
} while (1);
set_current_state(TASK_RUNNING);
remove_wait_queue(&bq->thread_wq, &wait);
up(&bq->thread_sem);
complete_and_exit(&bq->thread_complete, 0);
#ifndef WESTBRIDGE_NDEBUG
cy_as_hal_print_message("%s: is finished\n", __func__);
#endif
return 0;
}
static void cyasblkdev_request(struct request_queue *q)
{
struct cyasblkdev_queue *bq = q->queuedata;
DBGPRN_FUNC_NAME;
#ifndef WESTBRIDGE_NDEBUG
cy_as_hal_print_message(
"%s new request on cyasblkdev_queue_t bq:=%x\n",
__func__, (uint32_t)bq);
#endif
if (!bq->req) {
#ifndef WESTBRIDGE_NDEBUG
cy_as_hal_print_message("%s wake_up(&bq->thread_wq)\n",
__func__);
#endif
wake_up(&bq->thread_wq);
} else {
#ifndef WESTBRIDGE_NDEBUG
cy_as_hal_print_message("%s: don't wake Q_thr, bq->req:%x\n",
__func__, (uint32_t)bq->req);
#endif
}
}
int cyasblkdev_init_queue(struct cyasblkdev_queue *bq, spinlock_t *lock)
{
int ret;
DBGPRN_FUNC_NAME;
bq->queue = blk_init_queue(cyasblkdev_request, lock);
if (!bq->queue)
return -ENOMEM;
blk_queue_prep_rq(bq->queue, cyasblkdev_prep_request);
blk_queue_bounce_limit(bq->queue, BLK_BOUNCE_ANY);
blk_queue_max_hw_sectors(bq->queue, Q_MAX_SECTORS);
blk_queue_max_segments(bq->queue, Q_MAX_SGS);
blk_queue_max_segment_size(bq->queue, 512*Q_MAX_SECTORS);
bq->queue->queuedata = bq;
bq->req = NULL;
init_completion(&bq->thread_complete);
init_waitqueue_head(&bq->thread_wq);
sema_init(&bq->thread_sem, 1);
ret = kernel_thread(cyasblkdev_queue_thread, bq, CLONE_KERNEL);
if (ret >= 0) {
wait_for_completion(&bq->thread_complete);
init_completion(&bq->thread_complete);
ret = 0;
goto out;
}
out:
return ret;
}
void cyasblkdev_cleanup_queue(struct cyasblkdev_queue *bq)
{
DBGPRN_FUNC_NAME;
bq->flags |= CYASBLKDEV_QUEUE_EXIT;
wake_up(&bq->thread_wq);
wait_for_completion(&bq->thread_complete);
blk_cleanup_queue(bq->queue);
}
void cyasblkdev_queue_suspend(struct cyasblkdev_queue *bq)
{
struct request_queue *q = bq->queue;
unsigned long flags;
DBGPRN_FUNC_NAME;
if (!(bq->flags & CYASBLKDEV_QUEUE_SUSPENDED)) {
bq->flags |= CYASBLKDEV_QUEUE_SUSPENDED;
spin_lock_irqsave(q->queue_lock, flags);
blk_stop_queue(q);
spin_unlock_irqrestore(q->queue_lock, flags);
down(&bq->thread_sem);
}
}
void cyasblkdev_queue_resume(struct cyasblkdev_queue *bq)
{
struct request_queue *q = bq->queue;
unsigned long flags;
DBGPRN_FUNC_NAME;
if (bq->flags & CYASBLKDEV_QUEUE_SUSPENDED) {
bq->flags &= ~CYASBLKDEV_QUEUE_SUSPENDED;
up(&bq->thread_sem);
spin_lock_irqsave(q->queue_lock, flags);
blk_start_queue(q);
spin_unlock_irqrestore(q->queue_lock, flags);
}
}
