static void blk_end_sync_rq(struct request *rq, blk_status_t error)
{
struct completion *waiting = rq->end_io_data;
rq->end_io_data = NULL;
complete(waiting);
}
void blk_execute_rq_nowait(struct request_queue *q, struct gendisk *bd_disk,
struct request *rq, int at_head,
rq_end_io_fn *done)
{
int where = at_head ? ELEVATOR_INSERT_FRONT : ELEVATOR_INSERT_BACK;
WARN_ON(irqs_disabled());
WARN_ON(!blk_rq_is_passthrough(rq));
rq->rq_disk = bd_disk;
rq->end_io = done;
if (q->mq_ops) {
blk_mq_sched_insert_request(rq, at_head, true, false, false);
return;
}
spin_lock_irq(q->queue_lock);
if (unlikely(blk_queue_dying(q))) {
rq->rq_flags |= RQF_QUIET;
__blk_end_request_all(rq, BLK_STS_IOERR);
spin_unlock_irq(q->queue_lock);
return;
}
__elv_add_request(q, rq, where);
__blk_run_queue(q);
spin_unlock_irq(q->queue_lock);
}
void blk_execute_rq(struct request_queue *q, struct gendisk *bd_disk,
struct request *rq, int at_head)
{
DECLARE_COMPLETION_ONSTACK(wait);
unsigned long hang_check;
rq->end_io_data = &wait;
blk_execute_rq_nowait(q, bd_disk, rq, at_head, blk_end_sync_rq);
hang_check = sysctl_hung_task_timeout_secs;
if (hang_check)
while (!wait_for_completion_io_timeout(&wait, hang_check * (HZ/2)));
else
wait_for_completion_io(&wait);
}
