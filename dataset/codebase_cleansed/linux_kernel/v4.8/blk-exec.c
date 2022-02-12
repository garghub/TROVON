static void blk_end_sync_rq(struct request *rq, int error)
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
WARN_ON(rq->cmd_type == REQ_TYPE_FS);
rq->rq_disk = bd_disk;
rq->end_io = done;
if (q->mq_ops) {
blk_mq_insert_request(rq, at_head, true, false);
return;
}
spin_lock_irq(q->queue_lock);
if (unlikely(blk_queue_dying(q))) {
rq->cmd_flags |= REQ_QUIET;
rq->errors = -ENXIO;
__blk_end_request_all(rq, rq->errors);
spin_unlock_irq(q->queue_lock);
return;
}
__elv_add_request(q, rq, where);
__blk_run_queue(q);
spin_unlock_irq(q->queue_lock);
}
int blk_execute_rq(struct request_queue *q, struct gendisk *bd_disk,
struct request *rq, int at_head)
{
DECLARE_COMPLETION_ONSTACK(wait);
char sense[SCSI_SENSE_BUFFERSIZE];
int err = 0;
unsigned long hang_check;
if (!rq->sense) {
memset(sense, 0, sizeof(sense));
rq->sense = sense;
rq->sense_len = 0;
}
rq->end_io_data = &wait;
blk_execute_rq_nowait(q, bd_disk, rq, at_head, blk_end_sync_rq);
hang_check = sysctl_hung_task_timeout_secs;
if (hang_check)
while (!wait_for_completion_io_timeout(&wait, hang_check * (HZ/2)));
else
wait_for_completion_io(&wait);
if (rq->errors)
err = -EIO;
if (rq->sense == sense) {
rq->sense = NULL;
rq->sense_len = 0;
}
return err;
}
