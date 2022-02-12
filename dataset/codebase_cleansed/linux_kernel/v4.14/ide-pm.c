int generic_ide_suspend(struct device *dev, pm_message_t mesg)
{
ide_drive_t *drive = to_ide_device(dev);
ide_drive_t *pair = ide_get_pair_dev(drive);
ide_hwif_t *hwif = drive->hwif;
struct request *rq;
struct ide_pm_state rqpm;
int ret;
if (ide_port_acpi(hwif)) {
if ((drive->dn & 1) == 0 || pair == NULL)
ide_acpi_get_timing(hwif);
}
memset(&rqpm, 0, sizeof(rqpm));
rq = blk_get_request(drive->queue, REQ_OP_DRV_IN, __GFP_RECLAIM);
ide_req(rq)->type = ATA_PRIV_PM_SUSPEND;
rq->special = &rqpm;
rqpm.pm_step = IDE_PM_START_SUSPEND;
if (mesg.event == PM_EVENT_PRETHAW)
mesg.event = PM_EVENT_FREEZE;
rqpm.pm_state = mesg.event;
blk_execute_rq(drive->queue, NULL, rq, 0);
ret = scsi_req(rq)->result ? -EIO : 0;
blk_put_request(rq);
if (ret == 0 && ide_port_acpi(hwif)) {
if ((drive->dn & 1) || pair == NULL)
ide_acpi_set_state(hwif, 0);
}
return ret;
}
static void ide_end_sync_rq(struct request *rq, blk_status_t error)
{
complete(rq->end_io_data);
}
static int ide_pm_execute_rq(struct request *rq)
{
struct request_queue *q = rq->q;
DECLARE_COMPLETION_ONSTACK(wait);
rq->end_io_data = &wait;
rq->end_io = ide_end_sync_rq;
spin_lock_irq(q->queue_lock);
if (unlikely(blk_queue_dying(q))) {
rq->rq_flags |= RQF_QUIET;
scsi_req(rq)->result = -ENXIO;
__blk_end_request_all(rq, BLK_STS_OK);
spin_unlock_irq(q->queue_lock);
return -ENXIO;
}
__elv_add_request(q, rq, ELEVATOR_INSERT_FRONT);
__blk_run_queue_uncond(q);
spin_unlock_irq(q->queue_lock);
wait_for_completion_io(&wait);
return scsi_req(rq)->result ? -EIO : 0;
}
int generic_ide_resume(struct device *dev)
{
ide_drive_t *drive = to_ide_device(dev);
ide_drive_t *pair = ide_get_pair_dev(drive);
ide_hwif_t *hwif = drive->hwif;
struct request *rq;
struct ide_pm_state rqpm;
int err;
if (ide_port_acpi(hwif)) {
if ((drive->dn & 1) == 0 || pair == NULL) {
ide_acpi_set_state(hwif, 1);
ide_acpi_push_timing(hwif);
}
ide_acpi_exec_tfs(drive);
}
memset(&rqpm, 0, sizeof(rqpm));
rq = blk_get_request(drive->queue, REQ_OP_DRV_IN, __GFP_RECLAIM);
ide_req(rq)->type = ATA_PRIV_PM_RESUME;
rq->rq_flags |= RQF_PREEMPT;
rq->special = &rqpm;
rqpm.pm_step = IDE_PM_START_RESUME;
rqpm.pm_state = PM_EVENT_ON;
err = ide_pm_execute_rq(rq);
blk_put_request(rq);
if (err == 0 && dev->driver) {
struct ide_driver *drv = to_ide_driver(dev->driver);
if (drv->resume)
drv->resume(drive);
}
return err;
}
void ide_complete_power_step(ide_drive_t *drive, struct request *rq)
{
struct ide_pm_state *pm = rq->special;
#ifdef DEBUG_PM
printk(KERN_INFO "%s: complete_power_step(step: %d)\n",
drive->name, pm->pm_step);
#endif
if (drive->media != ide_disk)
return;
switch (pm->pm_step) {
case IDE_PM_FLUSH_CACHE:
if (pm->pm_state == PM_EVENT_FREEZE)
pm->pm_step = IDE_PM_COMPLETED;
else
pm->pm_step = IDE_PM_STANDBY;
break;
case IDE_PM_STANDBY:
pm->pm_step = IDE_PM_COMPLETED;
break;
case IDE_PM_RESTORE_PIO:
pm->pm_step = IDE_PM_IDLE;
break;
case IDE_PM_IDLE:
pm->pm_step = IDE_PM_RESTORE_DMA;
break;
}
}
ide_startstop_t ide_start_power_step(ide_drive_t *drive, struct request *rq)
{
struct ide_pm_state *pm = rq->special;
struct ide_cmd cmd = { };
switch (pm->pm_step) {
case IDE_PM_FLUSH_CACHE:
if (drive->media != ide_disk)
break;
if (ata_id_flush_enabled(drive->id) == 0 ||
(drive->dev_flags & IDE_DFLAG_WCACHE) == 0) {
ide_complete_power_step(drive, rq);
return ide_stopped;
}
if (ata_id_flush_ext_enabled(drive->id))
cmd.tf.command = ATA_CMD_FLUSH_EXT;
else
cmd.tf.command = ATA_CMD_FLUSH;
goto out_do_tf;
case IDE_PM_STANDBY:
cmd.tf.command = ATA_CMD_STANDBYNOW1;
goto out_do_tf;
case IDE_PM_RESTORE_PIO:
ide_set_max_pio(drive);
if (drive->media != ide_disk)
pm->pm_step = IDE_PM_RESTORE_DMA;
else
ide_complete_power_step(drive, rq);
return ide_stopped;
case IDE_PM_IDLE:
cmd.tf.command = ATA_CMD_IDLEIMMEDIATE;
goto out_do_tf;
case IDE_PM_RESTORE_DMA:
if (drive->hwif->dma_ops == NULL)
break;
ide_set_dma(drive);
break;
}
pm->pm_step = IDE_PM_COMPLETED;
return ide_stopped;
out_do_tf:
cmd.valid.out.tf = IDE_VALID_OUT_TF | IDE_VALID_DEVICE;
cmd.valid.in.tf = IDE_VALID_IN_TF | IDE_VALID_DEVICE;
cmd.protocol = ATA_PROT_NODATA;
return do_rw_taskfile(drive, &cmd);
}
void ide_complete_pm_rq(ide_drive_t *drive, struct request *rq)
{
struct request_queue *q = drive->queue;
struct ide_pm_state *pm = rq->special;
unsigned long flags;
ide_complete_power_step(drive, rq);
if (pm->pm_step != IDE_PM_COMPLETED)
return;
#ifdef DEBUG_PM
printk("%s: completing PM request, %s\n", drive->name,
(ide_req(rq)->type == ATA_PRIV_PM_SUSPEND) ? "suspend" : "resume");
#endif
spin_lock_irqsave(q->queue_lock, flags);
if (ide_req(rq)->type == ATA_PRIV_PM_SUSPEND)
blk_stop_queue(q);
else
drive->dev_flags &= ~IDE_DFLAG_BLOCKED;
spin_unlock_irqrestore(q->queue_lock, flags);
drive->hwif->rq = NULL;
if (blk_end_request(rq, BLK_STS_OK, 0))
BUG();
}
void ide_check_pm_state(ide_drive_t *drive, struct request *rq)
{
struct ide_pm_state *pm = rq->special;
if (blk_rq_is_private(rq) &&
ide_req(rq)->type == ATA_PRIV_PM_SUSPEND &&
pm->pm_step == IDE_PM_START_SUSPEND)
drive->dev_flags |= IDE_DFLAG_BLOCKED;
else if (blk_rq_is_private(rq) &&
ide_req(rq)->type == ATA_PRIV_PM_RESUME &&
pm->pm_step == IDE_PM_START_RESUME) {
ide_hwif_t *hwif = drive->hwif;
const struct ide_tp_ops *tp_ops = hwif->tp_ops;
struct request_queue *q = drive->queue;
unsigned long flags;
int rc;
#ifdef DEBUG_PM
printk("%s: Wakeup request inited, waiting for !BSY...\n", drive->name);
#endif
rc = ide_wait_not_busy(hwif, 35000);
if (rc)
printk(KERN_WARNING "%s: bus not ready on wakeup\n", drive->name);
tp_ops->dev_select(drive);
tp_ops->write_devctl(hwif, ATA_DEVCTL_OBS);
rc = ide_wait_not_busy(hwif, 100000);
if (rc)
printk(KERN_WARNING "%s: drive not ready on wakeup\n", drive->name);
spin_lock_irqsave(q->queue_lock, flags);
blk_start_queue(q);
spin_unlock_irqrestore(q->queue_lock, flags);
}
}
