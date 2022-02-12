static int set_io_32bit(ide_drive_t *drive, int arg)
{
if (drive->dev_flags & IDE_DFLAG_NO_IO_32BIT)
return -EPERM;
if (arg < 0 || arg > 1 + (SUPPORT_VLB_SYNC << 1))
return -EINVAL;
drive->io_32bit = arg;
return 0;
}
static int set_ksettings(ide_drive_t *drive, int arg)
{
if (arg < 0 || arg > 1)
return -EINVAL;
if (arg)
drive->dev_flags |= IDE_DFLAG_KEEP_SETTINGS;
else
drive->dev_flags &= ~IDE_DFLAG_KEEP_SETTINGS;
return 0;
}
static int set_using_dma(ide_drive_t *drive, int arg)
{
#ifdef CONFIG_BLK_DEV_IDEDMA
int err = -EPERM;
if (arg < 0 || arg > 1)
return -EINVAL;
if (ata_id_has_dma(drive->id) == 0)
goto out;
if (drive->hwif->dma_ops == NULL)
goto out;
err = 0;
if (arg) {
if (ide_set_dma(drive))
err = -EIO;
} else
ide_dma_off(drive);
out:
return err;
#else
if (arg < 0 || arg > 1)
return -EINVAL;
return -EPERM;
#endif
}
static int set_pio_mode_abuse(ide_hwif_t *hwif, u8 req_pio)
{
switch (req_pio) {
case 202:
case 201:
case 200:
case 102:
case 101:
case 100:
return (hwif->host_flags & IDE_HFLAG_ABUSE_DMA_MODES) ? 1 : 0;
case 9:
case 8:
return (hwif->host_flags & IDE_HFLAG_ABUSE_PREFETCH) ? 1 : 0;
case 7:
case 6:
return (hwif->host_flags & IDE_HFLAG_ABUSE_FAST_DEVSEL) ? 1 : 0;
default:
return 0;
}
}
static int set_pio_mode(ide_drive_t *drive, int arg)
{
ide_hwif_t *hwif = drive->hwif;
const struct ide_port_ops *port_ops = hwif->port_ops;
if (arg < 0 || arg > 255)
return -EINVAL;
if (port_ops == NULL || port_ops->set_pio_mode == NULL ||
(hwif->host_flags & IDE_HFLAG_NO_SET_MODE))
return -ENOSYS;
if (set_pio_mode_abuse(drive->hwif, arg)) {
drive->pio_mode = arg + XFER_PIO_0;
if (arg == 8 || arg == 9) {
unsigned long flags;
spin_lock_irqsave(&hwif->lock, flags);
port_ops->set_pio_mode(hwif, drive);
spin_unlock_irqrestore(&hwif->lock, flags);
} else
port_ops->set_pio_mode(hwif, drive);
} else {
int keep_dma = !!(drive->dev_flags & IDE_DFLAG_USING_DMA);
ide_set_pio(drive, arg);
if (hwif->host_flags & IDE_HFLAG_SET_PIO_MODE_KEEP_DMA) {
if (keep_dma)
ide_dma_on(drive);
}
}
return 0;
}
static int set_unmaskirq(ide_drive_t *drive, int arg)
{
if (drive->dev_flags & IDE_DFLAG_NO_UNMASK)
return -EPERM;
if (arg < 0 || arg > 1)
return -EINVAL;
if (arg)
drive->dev_flags |= IDE_DFLAG_UNMASK;
else
drive->dev_flags &= ~IDE_DFLAG_UNMASK;
return 0;
}
int ide_devset_execute(ide_drive_t *drive, const struct ide_devset *setting,
int arg)
{
struct request_queue *q = drive->queue;
struct request *rq;
int ret = 0;
if (!(setting->flags & DS_SYNC))
return setting->set(drive, arg);
rq = blk_get_request(q, REQ_OP_DRV_IN, __GFP_RECLAIM);
scsi_req_init(rq);
ide_req(rq)->type = ATA_PRIV_MISC;
scsi_req(rq)->cmd_len = 5;
scsi_req(rq)->cmd[0] = REQ_DEVSET_EXEC;
*(int *)&scsi_req(rq)->cmd[1] = arg;
rq->special = setting->set;
if (blk_execute_rq(q, NULL, rq, 0))
ret = rq->errors;
blk_put_request(rq);
return ret;
}
ide_startstop_t ide_do_devset(ide_drive_t *drive, struct request *rq)
{
int err, (*setfunc)(ide_drive_t *, int) = rq->special;
err = setfunc(drive, *(int *)&scsi_req(rq)->cmd[1]);
if (err)
rq->errors = err;
ide_complete_rq(drive, err, blk_rq_bytes(rq));
return ide_stopped;
}
