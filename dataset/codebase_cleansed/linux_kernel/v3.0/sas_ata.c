static enum ata_completion_errors sas_to_ata_err(struct task_status_struct *ts)
{
if (ts->resp == SAS_TASK_UNDELIVERED)
return AC_ERR_ATA_BUS;
switch (ts->stat) {
case SAS_DEV_NO_RESPONSE:
return AC_ERR_TIMEOUT;
case SAS_INTERRUPTED:
case SAS_PHY_DOWN:
case SAS_NAK_R_ERR:
return AC_ERR_ATA_BUS;
case SAS_DATA_UNDERRUN:
return 0;
case SAS_DATA_OVERRUN:
case SAS_QUEUE_FULL:
case SAS_DEVICE_UNKNOWN:
case SAS_SG_ERR:
return AC_ERR_INVALID;
case SAS_OPEN_TO:
case SAS_OPEN_REJECT:
SAS_DPRINTK("%s: Saw error %d. What to do?\n",
__func__, ts->stat);
return AC_ERR_OTHER;
case SAM_STAT_CHECK_CONDITION:
case SAS_ABORTED_TASK:
return AC_ERR_DEV;
case SAS_PROTO_RESPONSE:
return 0;
default:
return 0;
}
}
static void sas_ata_task_done(struct sas_task *task)
{
struct ata_queued_cmd *qc = task->uldd_task;
struct domain_device *dev;
struct task_status_struct *stat = &task->task_status;
struct ata_task_resp *resp = (struct ata_task_resp *)stat->buf;
struct sas_ha_struct *sas_ha;
enum ata_completion_errors ac;
unsigned long flags;
struct ata_link *link;
if (!qc)
goto qc_already_gone;
dev = qc->ap->private_data;
sas_ha = dev->port->ha;
link = &dev->sata_dev.ap->link;
spin_lock_irqsave(dev->sata_dev.ap->lock, flags);
if (stat->stat == SAS_PROTO_RESPONSE || stat->stat == SAM_STAT_GOOD ||
((stat->stat == SAM_STAT_CHECK_CONDITION &&
dev->sata_dev.command_set == ATAPI_COMMAND_SET))) {
ata_tf_from_fis(resp->ending_fis, &dev->sata_dev.tf);
if (!link->sactive) {
qc->err_mask |= ac_err_mask(dev->sata_dev.tf.command);
} else {
link->eh_info.err_mask |= ac_err_mask(dev->sata_dev.tf.command);
if (unlikely(link->eh_info.err_mask))
qc->flags |= ATA_QCFLAG_FAILED;
}
dev->sata_dev.sstatus = resp->sstatus;
dev->sata_dev.serror = resp->serror;
dev->sata_dev.scontrol = resp->scontrol;
} else {
ac = sas_to_ata_err(stat);
if (ac) {
SAS_DPRINTK("%s: SAS error %x\n", __func__,
stat->stat);
if (!link->sactive) {
qc->err_mask = ac;
} else {
link->eh_info.err_mask |= AC_ERR_DEV;
qc->flags |= ATA_QCFLAG_FAILED;
}
dev->sata_dev.tf.feature = 0x04;
dev->sata_dev.tf.command = ATA_ERR;
}
}
qc->lldd_task = NULL;
if (qc->scsicmd)
ASSIGN_SAS_TASK(qc->scsicmd, NULL);
ata_qc_complete(qc);
spin_unlock_irqrestore(dev->sata_dev.ap->lock, flags);
spin_lock_irqsave(&task->task_state_lock, flags);
if (qc->scsicmd && task->task_state_flags & SAS_TASK_STATE_ABORTED)
scsi_eh_finish_cmd(qc->scsicmd, &sas_ha->eh_done_q);
spin_unlock_irqrestore(&task->task_state_lock, flags);
qc_already_gone:
list_del_init(&task->list);
sas_free_task(task);
}
static unsigned int sas_ata_qc_issue(struct ata_queued_cmd *qc)
{
int res;
struct sas_task *task;
struct domain_device *dev = qc->ap->private_data;
struct sas_ha_struct *sas_ha = dev->port->ha;
struct Scsi_Host *host = sas_ha->core.shost;
struct sas_internal *i = to_sas_internal(host->transportt);
struct scatterlist *sg;
unsigned int xfer = 0;
unsigned int si;
if (dev->gone)
return AC_ERR_SYSTEM;
task = sas_alloc_task(GFP_ATOMIC);
if (!task)
return AC_ERR_SYSTEM;
task->dev = dev;
task->task_proto = SAS_PROTOCOL_STP;
task->task_done = sas_ata_task_done;
if (qc->tf.command == ATA_CMD_FPDMA_WRITE ||
qc->tf.command == ATA_CMD_FPDMA_READ) {
qc->tf.nsect = 0;
}
ata_tf_to_fis(&qc->tf, 1, 0, (u8*)&task->ata_task.fis);
task->uldd_task = qc;
if (ata_is_atapi(qc->tf.protocol)) {
memcpy(task->ata_task.atapi_packet, qc->cdb, qc->dev->cdb_len);
task->total_xfer_len = qc->nbytes;
task->num_scatter = qc->n_elem;
} else {
for_each_sg(qc->sg, sg, qc->n_elem, si)
xfer += sg->length;
task->total_xfer_len = xfer;
task->num_scatter = si;
}
task->data_dir = qc->dma_dir;
task->scatter = qc->sg;
task->ata_task.retry_count = 1;
task->task_state_flags = SAS_TASK_STATE_PENDING;
qc->lldd_task = task;
switch (qc->tf.protocol) {
case ATA_PROT_NCQ:
task->ata_task.use_ncq = 1;
case ATAPI_PROT_DMA:
case ATA_PROT_DMA:
task->ata_task.dma_xfer = 1;
break;
}
if (qc->scsicmd)
ASSIGN_SAS_TASK(qc->scsicmd, task);
if (sas_ha->lldd_max_execute_num < 2)
res = i->dft->lldd_execute_task(task, 1, GFP_ATOMIC);
else
res = sas_queue_up(task);
if (res) {
SAS_DPRINTK("lldd_execute_task returned: %d\n", res);
if (qc->scsicmd)
ASSIGN_SAS_TASK(qc->scsicmd, NULL);
sas_free_task(task);
return AC_ERR_SYSTEM;
}
return 0;
}
static bool sas_ata_qc_fill_rtf(struct ata_queued_cmd *qc)
{
struct domain_device *dev = qc->ap->private_data;
memcpy(&qc->result_tf, &dev->sata_dev.tf, sizeof(qc->result_tf));
return true;
}
static int sas_ata_hard_reset(struct ata_link *link, unsigned int *class,
unsigned long deadline)
{
struct ata_port *ap = link->ap;
struct domain_device *dev = ap->private_data;
struct sas_internal *i =
to_sas_internal(dev->port->ha->core.shost->transportt);
int res = TMF_RESP_FUNC_FAILED;
int ret = 0;
if (i->dft->lldd_I_T_nexus_reset)
res = i->dft->lldd_I_T_nexus_reset(dev);
if (res != TMF_RESP_FUNC_COMPLETE) {
SAS_DPRINTK("%s: Unable to reset I T nexus?\n", __func__);
ret = -EAGAIN;
}
switch (dev->sata_dev.command_set) {
case ATA_COMMAND_SET:
SAS_DPRINTK("%s: Found ATA device.\n", __func__);
*class = ATA_DEV_ATA;
break;
case ATAPI_COMMAND_SET:
SAS_DPRINTK("%s: Found ATAPI device.\n", __func__);
*class = ATA_DEV_ATAPI;
break;
default:
SAS_DPRINTK("%s: Unknown SATA command set: %d.\n",
__func__,
dev->sata_dev.command_set);
*class = ATA_DEV_UNKNOWN;
break;
}
ap->cbl = ATA_CBL_SATA;
return ret;
}
static int sas_ata_soft_reset(struct ata_link *link, unsigned int *class,
unsigned long deadline)
{
struct ata_port *ap = link->ap;
struct domain_device *dev = ap->private_data;
struct sas_internal *i =
to_sas_internal(dev->port->ha->core.shost->transportt);
int res = TMF_RESP_FUNC_FAILED;
int ret = 0;
if (i->dft->lldd_ata_soft_reset)
res = i->dft->lldd_ata_soft_reset(dev);
if (res != TMF_RESP_FUNC_COMPLETE) {
SAS_DPRINTK("%s: Unable to soft reset\n", __func__);
ret = -EAGAIN;
}
switch (dev->sata_dev.command_set) {
case ATA_COMMAND_SET:
SAS_DPRINTK("%s: Found ATA device.\n", __func__);
*class = ATA_DEV_ATA;
break;
case ATAPI_COMMAND_SET:
SAS_DPRINTK("%s: Found ATAPI device.\n", __func__);
*class = ATA_DEV_ATAPI;
break;
default:
SAS_DPRINTK("%s: Unknown SATA command set: %d.\n",
__func__, dev->sata_dev.command_set);
*class = ATA_DEV_UNKNOWN;
break;
}
ap->cbl = ATA_CBL_SATA;
return ret;
}
static void sas_ata_post_internal(struct ata_queued_cmd *qc)
{
if (qc->flags & ATA_QCFLAG_FAILED)
qc->err_mask |= AC_ERR_OTHER;
if (qc->err_mask) {
struct sas_task *task = qc->lldd_task;
unsigned long flags;
qc->lldd_task = NULL;
if (task) {
spin_lock_irqsave(&task->task_state_lock, flags);
task->task_state_flags |= SAS_TASK_NEED_DEV_RESET;
spin_unlock_irqrestore(&task->task_state_lock, flags);
task->uldd_task = NULL;
__sas_task_abort(task);
}
}
}
int sas_ata_init_host_and_port(struct domain_device *found_dev,
struct scsi_target *starget)
{
struct Scsi_Host *shost = dev_to_shost(&starget->dev);
struct sas_ha_struct *ha = SHOST_TO_SAS_HA(shost);
struct ata_port *ap;
ata_host_init(&found_dev->sata_dev.ata_host,
ha->dev,
sata_port_info.flags,
&sas_sata_ops);
ap = ata_sas_port_alloc(&found_dev->sata_dev.ata_host,
&sata_port_info,
shost);
if (!ap) {
SAS_DPRINTK("ata_sas_port_alloc failed.\n");
return -ENODEV;
}
ap->private_data = found_dev;
ap->cbl = ATA_CBL_SATA;
ap->scsi_host = shost;
found_dev->sata_dev.ap = ap;
return 0;
}
void sas_ata_task_abort(struct sas_task *task)
{
struct ata_queued_cmd *qc = task->uldd_task;
struct completion *waiting;
if (qc->scsicmd) {
struct request_queue *q = qc->scsicmd->device->request_queue;
unsigned long flags;
spin_lock_irqsave(q->queue_lock, flags);
blk_abort_request(qc->scsicmd->request);
spin_unlock_irqrestore(q->queue_lock, flags);
scsi_schedule_eh(qc->scsicmd->device->host);
return;
}
qc->flags &= ~ATA_QCFLAG_ACTIVE;
qc->flags |= ATA_QCFLAG_FAILED;
qc->err_mask |= AC_ERR_TIMEOUT;
waiting = qc->private_data;
complete(waiting);
}
static void sas_task_timedout(unsigned long _task)
{
struct sas_task *task = (void *) _task;
unsigned long flags;
spin_lock_irqsave(&task->task_state_lock, flags);
if (!(task->task_state_flags & SAS_TASK_STATE_DONE))
task->task_state_flags |= SAS_TASK_STATE_ABORTED;
spin_unlock_irqrestore(&task->task_state_lock, flags);
complete(&task->completion);
}
static void sas_disc_task_done(struct sas_task *task)
{
if (!del_timer(&task->timer))
return;
complete(&task->completion);
}
static int sas_execute_task(struct sas_task *task, void *buffer, int size,
enum dma_data_direction dma_dir)
{
int res = 0;
struct scatterlist *scatter = NULL;
struct task_status_struct *ts = &task->task_status;
int num_scatter = 0;
int retries = 0;
struct sas_internal *i =
to_sas_internal(task->dev->port->ha->core.shost->transportt);
if (dma_dir != DMA_NONE) {
scatter = kzalloc(sizeof(*scatter), GFP_KERNEL);
if (!scatter)
goto out;
sg_init_one(scatter, buffer, size);
num_scatter = 1;
}
task->task_proto = task->dev->tproto;
task->scatter = scatter;
task->num_scatter = num_scatter;
task->total_xfer_len = size;
task->data_dir = dma_dir;
task->task_done = sas_disc_task_done;
if (dma_dir != DMA_NONE &&
sas_protocol_ata(task->task_proto)) {
task->num_scatter = dma_map_sg(task->dev->port->ha->dev,
task->scatter,
task->num_scatter,
task->data_dir);
}
for (retries = 0; retries < 5; retries++) {
task->task_state_flags = SAS_TASK_STATE_PENDING;
init_completion(&task->completion);
task->timer.data = (unsigned long) task;
task->timer.function = sas_task_timedout;
task->timer.expires = jiffies + SAS_DEV_TIMEOUT*HZ;
add_timer(&task->timer);
res = i->dft->lldd_execute_task(task, 1, GFP_KERNEL);
if (res) {
del_timer(&task->timer);
SAS_DPRINTK("executing SAS discovery task failed:%d\n",
res);
goto ex_err;
}
wait_for_completion(&task->completion);
res = -ECOMM;
if (task->task_state_flags & SAS_TASK_STATE_ABORTED) {
int res2;
SAS_DPRINTK("task aborted, flags:0x%x\n",
task->task_state_flags);
res2 = i->dft->lldd_abort_task(task);
SAS_DPRINTK("came back from abort task\n");
if (!(task->task_state_flags & SAS_TASK_STATE_DONE)) {
if (res2 == TMF_RESP_FUNC_COMPLETE)
continue;
else
goto ex_err;
}
}
if (task->task_status.stat == SAM_STAT_BUSY ||
task->task_status.stat == SAM_STAT_TASK_SET_FULL ||
task->task_status.stat == SAS_QUEUE_FULL) {
SAS_DPRINTK("task: q busy, sleeping...\n");
schedule_timeout_interruptible(HZ);
} else if (task->task_status.stat == SAM_STAT_CHECK_CONDITION) {
struct scsi_sense_hdr shdr;
if (!scsi_normalize_sense(ts->buf, ts->buf_valid_size,
&shdr)) {
SAS_DPRINTK("couldn't normalize sense\n");
continue;
}
if ((shdr.sense_key == 6 && shdr.asc == 0x29) ||
(shdr.sense_key == 2 && shdr.asc == 4 &&
shdr.ascq == 1)) {
SAS_DPRINTK("device %016llx LUN: %016llx "
"powering up or not ready yet, "
"sleeping...\n",
SAS_ADDR(task->dev->sas_addr),
SAS_ADDR(task->ssp_task.LUN));
schedule_timeout_interruptible(5*HZ);
} else if (shdr.sense_key == 1) {
res = 0;
break;
} else if (shdr.sense_key == 5) {
break;
} else {
SAS_DPRINTK("dev %016llx LUN: %016llx "
"sense key:0x%x ASC:0x%x ASCQ:0x%x"
"\n",
SAS_ADDR(task->dev->sas_addr),
SAS_ADDR(task->ssp_task.LUN),
shdr.sense_key,
shdr.asc, shdr.ascq);
}
} else if (task->task_status.resp != SAS_TASK_COMPLETE ||
task->task_status.stat != SAM_STAT_GOOD) {
SAS_DPRINTK("task finished with resp:0x%x, "
"stat:0x%x\n",
task->task_status.resp,
task->task_status.stat);
goto ex_err;
} else {
res = 0;
break;
}
}
ex_err:
if (dma_dir != DMA_NONE) {
if (sas_protocol_ata(task->task_proto))
dma_unmap_sg(task->dev->port->ha->dev,
task->scatter, task->num_scatter,
task->data_dir);
kfree(scatter);
}
out:
return res;
}
static void sas_get_ata_command_set(struct domain_device *dev)
{
struct dev_to_host_fis *fis =
(struct dev_to_host_fis *) dev->frame_rcvd;
if ((fis->sector_count == 1 &&
fis->lbal == 1 &&
fis->lbam == 0 &&
fis->lbah == 0 &&
fis->device == 0)
||
(fis->sector_count == 0 &&
fis->lbal == 0 &&
fis->lbam == 0xCE &&
fis->lbah == 0xAA &&
(fis->device & ~0x10) == 0))
dev->sata_dev.command_set = ATA_COMMAND_SET;
else if ((fis->interrupt_reason == 1 &&
fis->lbal == 1 &&
fis->byte_count_low == 0x14 &&
fis->byte_count_high == 0xEB &&
(fis->device & ~0x10) == 0))
dev->sata_dev.command_set = ATAPI_COMMAND_SET;
else if ((fis->sector_count == 1 &&
fis->lbal == 1 &&
fis->lbam == 0x3C &&
fis->lbah == 0xC3 &&
fis->device == 0)
||
(fis->interrupt_reason == 1 &&
fis->lbal == 1 &&
fis->byte_count_low == 0x69 &&
fis->byte_count_high == 0x96 &&
(fis->device & ~0x10) == 0))
dev->sata_dev.command_set = ATAPI_COMMAND_SET;
}
static int sas_issue_ata_cmd(struct domain_device *dev, u8 command,
u8 features, void *buffer, int size,
enum dma_data_direction dma_dir)
{
int res = 0;
struct sas_task *task;
struct dev_to_host_fis *d2h_fis = (struct dev_to_host_fis *)
&dev->frame_rcvd[0];
res = -ENOMEM;
task = sas_alloc_task(GFP_KERNEL);
if (!task)
goto out;
task->dev = dev;
task->ata_task.fis.fis_type = 0x27;
task->ata_task.fis.command = command;
task->ata_task.fis.features = features;
task->ata_task.fis.device = d2h_fis->device;
task->ata_task.retry_count = 1;
res = sas_execute_task(task, buffer, size, dma_dir);
sas_free_task(task);
out:
return res;
}
static int sas_discover_sata_dev(struct domain_device *dev)
{
int res;
__le16 *identify_x;
u8 command;
identify_x = kzalloc(512, GFP_KERNEL);
if (!identify_x)
return -ENOMEM;
if (dev->sata_dev.command_set == ATA_COMMAND_SET) {
dev->sata_dev.identify_device = identify_x;
command = ATA_IDENTIFY_DEV;
} else {
dev->sata_dev.identify_packet_device = identify_x;
command = ATA_IDENTIFY_PACKET_DEV;
}
res = sas_issue_ata_cmd(dev, command, 0, identify_x, 512,
DMA_FROM_DEVICE);
if (res)
goto out_err;
if (le16_to_cpu(identify_x[0]) & 4) {
SAS_DPRINTK("sending SET FEATURE/PUP_STBY_SPIN_UP to "
"dev %llx\n", SAS_ADDR(dev->sas_addr));
if (!(identify_x[83] & cpu_to_le16(1<<6)))
goto cont1;
res = sas_issue_ata_cmd(dev, ATA_SET_FEATURES,
ATA_FEATURE_PUP_STBY_SPIN_UP,
NULL, 0, DMA_NONE);
if (res)
goto cont1;
schedule_timeout_interruptible(5*HZ);
res = sas_issue_ata_cmd(dev, command, 0, identify_x, 512,
DMA_FROM_DEVICE);
if (res)
goto out_err;
}
cont1:
sas_fill_in_rphy(dev, dev->rphy);
return 0;
out_err:
dev->sata_dev.identify_packet_device = NULL;
dev->sata_dev.identify_device = NULL;
kfree(identify_x);
return res;
}
static int sas_discover_sata_pm(struct domain_device *dev)
{
return -ENODEV;
}
int sas_discover_sata(struct domain_device *dev)
{
int res;
sas_get_ata_command_set(dev);
res = sas_notify_lldd_dev_found(dev);
if (res)
return res;
switch (dev->dev_type) {
case SATA_DEV:
res = sas_discover_sata_dev(dev);
break;
case SATA_PM:
res = sas_discover_sata_pm(dev);
break;
default:
break;
}
sas_notify_lldd_dev_gone(dev);
if (!res) {
sas_notify_lldd_dev_found(dev);
res = sas_rphy_add(dev->rphy);
}
return res;
}
void sas_ata_strategy_handler(struct Scsi_Host *shost)
{
struct scsi_device *sdev;
shost_for_each_device(sdev, shost) {
struct domain_device *ddev = sdev_to_domain_dev(sdev);
struct ata_port *ap = ddev->sata_dev.ap;
if (!dev_is_sata(ddev))
continue;
ata_port_printk(ap, KERN_DEBUG, "sas eh calling libata port error handler");
ata_scsi_port_error_handler(shost, ap);
}
}
int sas_ata_timed_out(struct scsi_cmnd *cmd, struct sas_task *task,
enum blk_eh_timer_return *rtn)
{
struct domain_device *ddev = cmd_to_domain_dev(cmd);
if (!dev_is_sata(ddev) || task)
return 0;
*rtn = BLK_EH_NOT_HANDLED;
return 1;
}
int sas_ata_eh(struct Scsi_Host *shost, struct list_head *work_q,
struct list_head *done_q)
{
int rtn = 0;
struct scsi_cmnd *cmd, *n;
struct ata_port *ap;
do {
LIST_HEAD(sata_q);
ap = NULL;
list_for_each_entry_safe(cmd, n, work_q, eh_entry) {
struct domain_device *ddev = cmd_to_domain_dev(cmd);
if (!dev_is_sata(ddev) || TO_SAS_TASK(cmd))
continue;
if (ap && ap != ddev->sata_dev.ap)
continue;
ap = ddev->sata_dev.ap;
rtn = 1;
list_move(&cmd->eh_entry, &sata_q);
}
if (!list_empty(&sata_q)) {
ata_port_printk(ap, KERN_DEBUG, "sas eh calling libata cmd error handler\n");
ata_scsi_cmd_error_handler(shost, ap, &sata_q);
while (!list_empty(&sata_q))
list_del_init(sata_q.next);
}
} while (ap);
return rtn;
}
