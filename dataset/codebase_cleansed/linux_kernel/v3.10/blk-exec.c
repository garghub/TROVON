static void blk_end_sync_rq(struct request *rq, int error)
{
struct completion *waiting = rq->end_io_data;
rq->end_io_data = NULL;
__blk_put_request(rq->q, rq);
complete(waiting);
}
void blk_execute_rq_nowait(struct request_queue *q, struct gendisk *bd_disk,
struct request *rq, int at_head,
rq_end_io_fn *done)
{
int where = at_head ? ELEVATOR_INSERT_FRONT : ELEVATOR_INSERT_BACK;
bool is_pm_resume;
WARN_ON(irqs_disabled());
rq->rq_disk = bd_disk;
rq->end_io = done;
is_pm_resume = rq->cmd_type == REQ_TYPE_PM_RESUME;
spin_lock_irq(q->queue_lock);
if (unlikely(blk_queue_dying(q))) {
rq->errors = -ENXIO;
if (rq->end_io)
rq->end_io(rq, rq->errors);
spin_unlock_irq(q->queue_lock);
return;
}
__elv_add_request(q, rq, where);
__blk_run_queue(q);
if (is_pm_resume)
__blk_run_queue_uncond(q);
spin_unlock_irq(q->queue_lock);
}
int blk_execute_rq(struct request_queue *q, struct gendisk *bd_disk,
struct request *rq, int at_head)
{
DECLARE_COMPLETION_ONSTACK(wait);
char sense[SCSI_SENSE_BUFFERSIZE];
int err = 0;
unsigned long hang_check;
rq->ref_count++;
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
return err;
}
