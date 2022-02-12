static inline u32 skd_reg_read32(struct skd_device *skdev, u32 offset)
{
u32 val;
if (likely(skdev->dbg_level < 2))
return readl(skdev->mem_map[1] + offset);
else {
barrier();
val = readl(skdev->mem_map[1] + offset);
barrier();
pr_debug("%s:%s:%d offset %x = %x\n",
skdev->name, __func__, __LINE__, offset, val);
return val;
}
}
static inline void skd_reg_write32(struct skd_device *skdev, u32 val,
u32 offset)
{
if (likely(skdev->dbg_level < 2)) {
writel(val, skdev->mem_map[1] + offset);
barrier();
} else {
barrier();
writel(val, skdev->mem_map[1] + offset);
barrier();
pr_debug("%s:%s:%d offset %x = %x\n",
skdev->name, __func__, __LINE__, offset, val);
}
}
static inline void skd_reg_write64(struct skd_device *skdev, u64 val,
u32 offset)
{
if (likely(skdev->dbg_level < 2)) {
writeq(val, skdev->mem_map[1] + offset);
barrier();
} else {
barrier();
writeq(val, skdev->mem_map[1] + offset);
barrier();
pr_debug("%s:%s:%d offset %x = %016llx\n",
skdev->name, __func__, __LINE__, offset, val);
}
}
static void skd_fail_all_pending(struct skd_device *skdev)
{
struct request_queue *q = skdev->queue;
struct request *req;
for (;; ) {
req = blk_peek_request(q);
if (req == NULL)
break;
blk_start_request(req);
__blk_end_request_all(req, -EIO);
}
}
static void
skd_prep_rw_cdb(struct skd_scsi_request *scsi_req,
int data_dir, unsigned lba,
unsigned count)
{
if (data_dir == READ)
scsi_req->cdb[0] = 0x28;
else
scsi_req->cdb[0] = 0x2a;
scsi_req->cdb[1] = 0;
scsi_req->cdb[2] = (lba & 0xff000000) >> 24;
scsi_req->cdb[3] = (lba & 0xff0000) >> 16;
scsi_req->cdb[4] = (lba & 0xff00) >> 8;
scsi_req->cdb[5] = (lba & 0xff);
scsi_req->cdb[6] = 0;
scsi_req->cdb[7] = (count & 0xff00) >> 8;
scsi_req->cdb[8] = count & 0xff;
scsi_req->cdb[9] = 0;
}
static void
skd_prep_zerosize_flush_cdb(struct skd_scsi_request *scsi_req,
struct skd_request_context *skreq)
{
skreq->flush_cmd = 1;
scsi_req->cdb[0] = 0x35;
scsi_req->cdb[1] = 0;
scsi_req->cdb[2] = 0;
scsi_req->cdb[3] = 0;
scsi_req->cdb[4] = 0;
scsi_req->cdb[5] = 0;
scsi_req->cdb[6] = 0;
scsi_req->cdb[7] = 0;
scsi_req->cdb[8] = 0;
scsi_req->cdb[9] = 0;
}
static void skd_request_fn(struct request_queue *q)
{
struct skd_device *skdev = q->queuedata;
struct skd_fitmsg_context *skmsg = NULL;
struct fit_msg_hdr *fmh = NULL;
struct skd_request_context *skreq;
struct request *req = NULL;
struct skd_scsi_request *scsi_req;
unsigned long io_flags;
int error;
u32 lba;
u32 count;
int data_dir;
u32 be_lba;
u32 be_count;
u64 be_dmaa;
u64 cmdctxt;
u32 timo_slot;
void *cmd_ptr;
int flush, fua;
if (skdev->state != SKD_DRVR_STATE_ONLINE) {
skd_request_fn_not_online(q);
return;
}
if (blk_queue_stopped(skdev->queue)) {
if (skdev->skmsg_free_list == NULL ||
skdev->skreq_free_list == NULL ||
skdev->in_flight >= skdev->queue_low_water_mark)
return;
queue_flag_clear(QUEUE_FLAG_STOPPED, skdev->queue);
}
for (;; ) {
flush = fua = 0;
req = blk_peek_request(q);
if (req == NULL)
break;
lba = (u32)blk_rq_pos(req);
count = blk_rq_sectors(req);
data_dir = rq_data_dir(req);
io_flags = req->cmd_flags;
if (req_op(req) == REQ_OP_FLUSH)
flush++;
if (io_flags & REQ_FUA)
fua++;
pr_debug("%s:%s:%d new req=%p lba=%u(0x%x) "
"count=%u(0x%x) dir=%d\n",
skdev->name, __func__, __LINE__,
req, lba, lba, count, count, data_dir);
if (skdev->in_flight >= skdev->cur_max_queue_depth) {
pr_debug("%s:%s:%d qdepth %d, limit %d\n",
skdev->name, __func__, __LINE__,
skdev->in_flight, skdev->cur_max_queue_depth);
break;
}
skreq = skdev->skreq_free_list;
if (skreq == NULL) {
pr_debug("%s:%s:%d Out of req=%p\n",
skdev->name, __func__, __LINE__, q);
break;
}
SKD_ASSERT(skreq->state == SKD_REQ_STATE_IDLE);
SKD_ASSERT((skreq->id & SKD_ID_INCR) == 0);
if (skmsg == NULL) {
if (skdev->skmsg_free_list == NULL) {
pr_debug("%s:%s:%d Out of msg\n",
skdev->name, __func__, __LINE__);
break;
}
}
skreq->flush_cmd = 0;
skreq->n_sg = 0;
skreq->sg_byte_count = 0;
blk_start_request(req);
skreq->req = req;
skreq->fitmsg_id = 0;
if (skmsg == NULL) {
skmsg = skdev->skmsg_free_list;
if (skmsg == NULL) {
pr_debug("%s:%s:%d Out of msg skdev=%p\n",
skdev->name, __func__, __LINE__,
skdev);
break;
}
SKD_ASSERT(skmsg->state == SKD_MSG_STATE_IDLE);
SKD_ASSERT((skmsg->id & SKD_ID_INCR) == 0);
skdev->skmsg_free_list = skmsg->next;
skmsg->state = SKD_MSG_STATE_BUSY;
skmsg->id += SKD_ID_INCR;
fmh = (struct fit_msg_hdr *)skmsg->msg_buf;
memset(fmh, 0, sizeof(*fmh));
fmh->protocol_id = FIT_PROTOCOL_ID_SOFIT;
skmsg->length = sizeof(*fmh);
}
skreq->fitmsg_id = skmsg->id;
cmd_ptr = &skmsg->msg_buf[skmsg->length];
memset(cmd_ptr, 0, 32);
be_lba = cpu_to_be32(lba);
be_count = cpu_to_be32(count);
be_dmaa = cpu_to_be64((u64)skreq->sksg_dma_address);
cmdctxt = skreq->id + SKD_ID_INCR;
scsi_req = cmd_ptr;
scsi_req->hdr.tag = cmdctxt;
scsi_req->hdr.sg_list_dma_address = be_dmaa;
if (data_dir == READ)
skreq->sg_data_dir = SKD_DATA_DIR_CARD_TO_HOST;
else
skreq->sg_data_dir = SKD_DATA_DIR_HOST_TO_CARD;
if (flush == SKD_FLUSH_ZERO_SIZE_FIRST) {
skd_prep_zerosize_flush_cdb(scsi_req, skreq);
SKD_ASSERT(skreq->flush_cmd == 1);
} else {
skd_prep_rw_cdb(scsi_req, data_dir, lba, count);
}
if (fua)
scsi_req->cdb[1] |= SKD_FUA_NV;
if (!req->bio)
goto skip_sg;
error = skd_preop_sg_list(skdev, skreq);
if (error != 0) {
pr_debug("%s:%s:%d error Out\n",
skdev->name, __func__, __LINE__);
skd_end_request(skdev, skreq, error);
continue;
}
skip_sg:
scsi_req->hdr.sg_list_len_bytes =
cpu_to_be32(skreq->sg_byte_count);
skdev->skreq_free_list = skreq->next;
skreq->state = SKD_REQ_STATE_BUSY;
skreq->id += SKD_ID_INCR;
skmsg->length += sizeof(struct skd_scsi_request);
fmh->num_protocol_cmds_coalesced++;
skreq->timeout_stamp = skdev->timeout_stamp;
timo_slot = skreq->timeout_stamp & SKD_TIMEOUT_SLOT_MASK;
skdev->timeout_slot[timo_slot]++;
skdev->in_flight++;
pr_debug("%s:%s:%d req=0x%x busy=%d\n",
skdev->name, __func__, __LINE__,
skreq->id, skdev->in_flight);
if (skmsg->length >= SKD_N_FITMSG_BYTES ||
fmh->num_protocol_cmds_coalesced >= skd_max_req_per_msg) {
skd_send_fitmsg(skdev, skmsg);
skmsg = NULL;
fmh = NULL;
}
}
if (skmsg != NULL) {
if (skmsg->length > sizeof(struct fit_msg_hdr)) {
pr_debug("%s:%s:%d sending msg=%p, len %d\n",
skdev->name, __func__, __LINE__,
skmsg, skmsg->length);
skd_send_fitmsg(skdev, skmsg);
} else {
skmsg->state = SKD_MSG_STATE_IDLE;
skmsg->id += SKD_ID_INCR;
skmsg->next = skdev->skmsg_free_list;
skdev->skmsg_free_list = skmsg;
}
skmsg = NULL;
fmh = NULL;
}
if (req)
blk_stop_queue(skdev->queue);
}
static void skd_end_request(struct skd_device *skdev,
struct skd_request_context *skreq, int error)
{
if (unlikely(error)) {
struct request *req = skreq->req;
char *cmd = (rq_data_dir(req) == READ) ? "read" : "write";
u32 lba = (u32)blk_rq_pos(req);
u32 count = blk_rq_sectors(req);
pr_err("(%s): Error cmd=%s sect=%u count=%u id=0x%x\n",
skd_name(skdev), cmd, lba, count, skreq->id);
} else
pr_debug("%s:%s:%d id=0x%x error=%d\n",
skdev->name, __func__, __LINE__, skreq->id, error);
__blk_end_request_all(skreq->req, error);
}
static int skd_preop_sg_list(struct skd_device *skdev,
struct skd_request_context *skreq)
{
struct request *req = skreq->req;
int writing = skreq->sg_data_dir == SKD_DATA_DIR_HOST_TO_CARD;
int pci_dir = writing ? PCI_DMA_TODEVICE : PCI_DMA_FROMDEVICE;
struct scatterlist *sg = &skreq->sg[0];
int n_sg;
int i;
skreq->sg_byte_count = 0;
n_sg = blk_rq_map_sg(skdev->queue, req, sg);
if (n_sg <= 0)
return -EINVAL;
n_sg = pci_map_sg(skdev->pdev, sg, n_sg, pci_dir);
if (n_sg <= 0)
return -EINVAL;
SKD_ASSERT(n_sg <= skdev->sgs_per_request);
skreq->n_sg = n_sg;
for (i = 0; i < n_sg; i++) {
struct fit_sg_descriptor *sgd = &skreq->sksg_list[i];
u32 cnt = sg_dma_len(&sg[i]);
uint64_t dma_addr = sg_dma_address(&sg[i]);
sgd->control = FIT_SGD_CONTROL_NOT_LAST;
sgd->byte_count = cnt;
skreq->sg_byte_count += cnt;
sgd->host_side_addr = dma_addr;
sgd->dev_side_addr = 0;
}
skreq->sksg_list[n_sg - 1].next_desc_ptr = 0LL;
skreq->sksg_list[n_sg - 1].control = FIT_SGD_CONTROL_LAST;
if (unlikely(skdev->dbg_level > 1)) {
pr_debug("%s:%s:%d skreq=%x sksg_list=%p sksg_dma=%llx\n",
skdev->name, __func__, __LINE__,
skreq->id, skreq->sksg_list, skreq->sksg_dma_address);
for (i = 0; i < n_sg; i++) {
struct fit_sg_descriptor *sgd = &skreq->sksg_list[i];
pr_debug("%s:%s:%d sg[%d] count=%u ctrl=0x%x "
"addr=0x%llx next=0x%llx\n",
skdev->name, __func__, __LINE__,
i, sgd->byte_count, sgd->control,
sgd->host_side_addr, sgd->next_desc_ptr);
}
}
return 0;
}
static void skd_postop_sg_list(struct skd_device *skdev,
struct skd_request_context *skreq)
{
int writing = skreq->sg_data_dir == SKD_DATA_DIR_HOST_TO_CARD;
int pci_dir = writing ? PCI_DMA_TODEVICE : PCI_DMA_FROMDEVICE;
skreq->sksg_list[skreq->n_sg - 1].next_desc_ptr =
skreq->sksg_dma_address +
((skreq->n_sg) * sizeof(struct fit_sg_descriptor));
pci_unmap_sg(skdev->pdev, &skreq->sg[0], skreq->n_sg, pci_dir);
}
static void skd_request_fn_not_online(struct request_queue *q)
{
struct skd_device *skdev = q->queuedata;
int error;
SKD_ASSERT(skdev->state != SKD_DRVR_STATE_ONLINE);
skd_log_skdev(skdev, "req_not_online");
switch (skdev->state) {
case SKD_DRVR_STATE_PAUSING:
case SKD_DRVR_STATE_PAUSED:
case SKD_DRVR_STATE_STARTING:
case SKD_DRVR_STATE_RESTARTING:
case SKD_DRVR_STATE_WAIT_BOOT:
case SKD_DRVR_STATE_BUSY:
case SKD_DRVR_STATE_BUSY_IMMINENT:
case SKD_DRVR_STATE_BUSY_ERASE:
case SKD_DRVR_STATE_DRAINING_TIMEOUT:
return;
case SKD_DRVR_STATE_BUSY_SANITIZE:
case SKD_DRVR_STATE_STOPPING:
case SKD_DRVR_STATE_SYNCING:
case SKD_DRVR_STATE_FAULT:
case SKD_DRVR_STATE_DISAPPEARED:
default:
error = -EIO;
break;
}
skd_fail_all_pending(skdev);
}
static void skd_timer_tick(ulong arg)
{
struct skd_device *skdev = (struct skd_device *)arg;
u32 timo_slot;
u32 overdue_timestamp;
unsigned long reqflags;
u32 state;
if (skdev->state == SKD_DRVR_STATE_FAULT)
return;
spin_lock_irqsave(&skdev->lock, reqflags);
state = SKD_READL(skdev, FIT_STATUS);
state &= FIT_SR_DRIVE_STATE_MASK;
if (state != skdev->drive_state)
skd_isr_fwstate(skdev);
if (skdev->state != SKD_DRVR_STATE_ONLINE) {
skd_timer_tick_not_online(skdev);
goto timer_func_out;
}
skdev->timeout_stamp++;
timo_slot = skdev->timeout_stamp & SKD_TIMEOUT_SLOT_MASK;
if (skdev->timeout_slot[timo_slot] == 0)
goto timer_func_out;
overdue_timestamp = skdev->timeout_stamp - SKD_N_TIMEOUT_SLOT;
pr_debug("%s:%s:%d found %d timeouts, draining busy=%d\n",
skdev->name, __func__, __LINE__,
skdev->timeout_slot[timo_slot], skdev->in_flight);
pr_err("(%s): Overdue IOs (%d), busy %d\n",
skd_name(skdev), skdev->timeout_slot[timo_slot],
skdev->in_flight);
skdev->timer_countdown = SKD_DRAINING_TIMO;
skdev->state = SKD_DRVR_STATE_DRAINING_TIMEOUT;
skdev->timo_slot = timo_slot;
blk_stop_queue(skdev->queue);
timer_func_out:
mod_timer(&skdev->timer, (jiffies + HZ));
spin_unlock_irqrestore(&skdev->lock, reqflags);
}
static void skd_timer_tick_not_online(struct skd_device *skdev)
{
switch (skdev->state) {
case SKD_DRVR_STATE_IDLE:
case SKD_DRVR_STATE_LOAD:
break;
case SKD_DRVR_STATE_BUSY_SANITIZE:
pr_debug("%s:%s:%d drive busy sanitize[%x], driver[%x]\n",
skdev->name, __func__, __LINE__,
skdev->drive_state, skdev->state);
if (skdev->timer_countdown > 0) {
skdev->timer_countdown--;
return;
}
skd_recover_requests(skdev, 0);
break;
case SKD_DRVR_STATE_BUSY:
case SKD_DRVR_STATE_BUSY_IMMINENT:
case SKD_DRVR_STATE_BUSY_ERASE:
pr_debug("%s:%s:%d busy[%x], countdown=%d\n",
skdev->name, __func__, __LINE__,
skdev->state, skdev->timer_countdown);
if (skdev->timer_countdown > 0) {
skdev->timer_countdown--;
return;
}
pr_debug("%s:%s:%d busy[%x], timedout=%d, restarting device.",
skdev->name, __func__, __LINE__,
skdev->state, skdev->timer_countdown);
skd_restart_device(skdev);
break;
case SKD_DRVR_STATE_WAIT_BOOT:
case SKD_DRVR_STATE_STARTING:
if (skdev->timer_countdown > 0) {
skdev->timer_countdown--;
return;
}
skdev->state = SKD_DRVR_STATE_FAULT;
pr_err("(%s): DriveFault Connect Timeout (%x)\n",
skd_name(skdev), skdev->drive_state);
blk_start_queue(skdev->queue);
skdev->gendisk_on = -1;
wake_up_interruptible(&skdev->waitq);
break;
case SKD_DRVR_STATE_ONLINE:
break;
case SKD_DRVR_STATE_PAUSING:
case SKD_DRVR_STATE_PAUSED:
break;
case SKD_DRVR_STATE_DRAINING_TIMEOUT:
pr_debug("%s:%s:%d "
"draining busy [%d] tick[%d] qdb[%d] tmls[%d]\n",
skdev->name, __func__, __LINE__,
skdev->timo_slot,
skdev->timer_countdown,
skdev->in_flight,
skdev->timeout_slot[skdev->timo_slot]);
if (skdev->timeout_slot[skdev->timo_slot] == 0) {
pr_debug("%s:%s:%d Slot drained, starting queue.\n",
skdev->name, __func__, __LINE__);
skdev->state = SKD_DRVR_STATE_ONLINE;
blk_start_queue(skdev->queue);
return;
}
if (skdev->timer_countdown > 0) {
skdev->timer_countdown--;
return;
}
skd_restart_device(skdev);
break;
case SKD_DRVR_STATE_RESTARTING:
if (skdev->timer_countdown > 0) {
skdev->timer_countdown--;
return;
}
skdev->state = SKD_DRVR_STATE_FAULT;
pr_err("(%s): DriveFault Reconnect Timeout (%x)\n",
skd_name(skdev), skdev->drive_state);
if ((skdev->drive_state == FIT_SR_DRIVE_SOFT_RESET) ||
(skdev->drive_state == FIT_SR_DRIVE_FAULT) ||
(skdev->drive_state == FIT_SR_DRIVE_STATE_MASK))
skd_recover_requests(skdev, 0);
else {
pr_err("(%s): Disable BusMaster (%x)\n",
skd_name(skdev), skdev->drive_state);
pci_disable_device(skdev->pdev);
skd_disable_interrupts(skdev);
skd_recover_requests(skdev, 0);
}
blk_start_queue(skdev->queue);
skdev->gendisk_on = -1;
wake_up_interruptible(&skdev->waitq);
break;
case SKD_DRVR_STATE_RESUMING:
case SKD_DRVR_STATE_STOPPING:
case SKD_DRVR_STATE_SYNCING:
case SKD_DRVR_STATE_FAULT:
case SKD_DRVR_STATE_DISAPPEARED:
default:
break;
}
}
static int skd_start_timer(struct skd_device *skdev)
{
int rc;
init_timer(&skdev->timer);
setup_timer(&skdev->timer, skd_timer_tick, (ulong)skdev);
rc = mod_timer(&skdev->timer, (jiffies + HZ));
if (rc)
pr_err("%s: failed to start timer %d\n",
__func__, rc);
return rc;
}
static void skd_kill_timer(struct skd_device *skdev)
{
del_timer_sync(&skdev->timer);
}
static int skd_bdev_ioctl(struct block_device *bdev, fmode_t mode,
uint cmd_in, ulong arg)
{
static const int sg_version_num = 30527;
int rc = 0, timeout;
struct gendisk *disk = bdev->bd_disk;
struct skd_device *skdev = disk->private_data;
int __user *p = (int __user *)arg;
pr_debug("%s:%s:%d %s: CMD[%s] ioctl mode 0x%x, cmd 0x%x arg %0lx\n",
skdev->name, __func__, __LINE__,
disk->disk_name, current->comm, mode, cmd_in, arg);
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
switch (cmd_in) {
case SG_SET_TIMEOUT:
rc = get_user(timeout, p);
if (!rc)
disk->queue->sg_timeout = clock_t_to_jiffies(timeout);
break;
case SG_GET_TIMEOUT:
rc = jiffies_to_clock_t(disk->queue->sg_timeout);
break;
case SG_GET_VERSION_NUM:
rc = put_user(sg_version_num, p);
break;
case SG_IO:
rc = skd_ioctl_sg_io(skdev, mode, (void __user *)arg);
break;
default:
rc = -ENOTTY;
break;
}
pr_debug("%s:%s:%d %s: completion rc %d\n",
skdev->name, __func__, __LINE__, disk->disk_name, rc);
return rc;
}
static int skd_ioctl_sg_io(struct skd_device *skdev, fmode_t mode,
void __user *argp)
{
int rc;
struct skd_sg_io sksgio;
memset(&sksgio, 0, sizeof(sksgio));
sksgio.mode = mode;
sksgio.argp = argp;
sksgio.iov = &sksgio.no_iov_iov;
switch (skdev->state) {
case SKD_DRVR_STATE_ONLINE:
case SKD_DRVR_STATE_BUSY_IMMINENT:
break;
default:
pr_debug("%s:%s:%d drive not online\n",
skdev->name, __func__, __LINE__);
rc = -ENXIO;
goto out;
}
rc = skd_sg_io_get_and_check_args(skdev, &sksgio);
if (rc)
goto out;
rc = skd_sg_io_obtain_skspcl(skdev, &sksgio);
if (rc)
goto out;
rc = skd_sg_io_prep_buffering(skdev, &sksgio);
if (rc)
goto out;
rc = skd_sg_io_copy_buffer(skdev, &sksgio, SG_DXFER_TO_DEV);
if (rc)
goto out;
rc = skd_sg_io_send_fitmsg(skdev, &sksgio);
if (rc)
goto out;
rc = skd_sg_io_await(skdev, &sksgio);
if (rc)
goto out;
rc = skd_sg_io_copy_buffer(skdev, &sksgio, SG_DXFER_FROM_DEV);
if (rc)
goto out;
rc = skd_sg_io_put_status(skdev, &sksgio);
if (rc)
goto out;
rc = 0;
out:
skd_sg_io_release_skspcl(skdev, &sksgio);
if (sksgio.iov != NULL && sksgio.iov != &sksgio.no_iov_iov)
kfree(sksgio.iov);
return rc;
}
static int skd_sg_io_get_and_check_args(struct skd_device *skdev,
struct skd_sg_io *sksgio)
{
struct sg_io_hdr *sgp = &sksgio->sg;
int i, acc;
if (!access_ok(VERIFY_WRITE, sksgio->argp, sizeof(sg_io_hdr_t))) {
pr_debug("%s:%s:%d access sg failed %p\n",
skdev->name, __func__, __LINE__, sksgio->argp);
return -EFAULT;
}
if (__copy_from_user(sgp, sksgio->argp, sizeof(sg_io_hdr_t))) {
pr_debug("%s:%s:%d copy_from_user sg failed %p\n",
skdev->name, __func__, __LINE__, sksgio->argp);
return -EFAULT;
}
if (sgp->interface_id != SG_INTERFACE_ID_ORIG) {
pr_debug("%s:%s:%d interface_id invalid 0x%x\n",
skdev->name, __func__, __LINE__, sgp->interface_id);
return -EINVAL;
}
if (sgp->cmd_len > sizeof(sksgio->cdb)) {
pr_debug("%s:%s:%d cmd_len invalid %d\n",
skdev->name, __func__, __LINE__, sgp->cmd_len);
return -EINVAL;
}
if (sgp->iovec_count > 256) {
pr_debug("%s:%s:%d iovec_count invalid %d\n",
skdev->name, __func__, __LINE__, sgp->iovec_count);
return -EINVAL;
}
if (sgp->dxfer_len > (PAGE_SIZE * SKD_N_SG_PER_SPECIAL)) {
pr_debug("%s:%s:%d dxfer_len invalid %d\n",
skdev->name, __func__, __LINE__, sgp->dxfer_len);
return -EINVAL;
}
switch (sgp->dxfer_direction) {
case SG_DXFER_NONE:
acc = -1;
break;
case SG_DXFER_TO_DEV:
acc = VERIFY_READ;
break;
case SG_DXFER_FROM_DEV:
case SG_DXFER_TO_FROM_DEV:
acc = VERIFY_WRITE;
break;
default:
pr_debug("%s:%s:%d dxfer_dir invalid %d\n",
skdev->name, __func__, __LINE__, sgp->dxfer_direction);
return -EINVAL;
}
if (copy_from_user(sksgio->cdb, sgp->cmdp, sgp->cmd_len)) {
pr_debug("%s:%s:%d copy_from_user cmdp failed %p\n",
skdev->name, __func__, __LINE__, sgp->cmdp);
return -EFAULT;
}
if (sgp->mx_sb_len != 0) {
if (!access_ok(VERIFY_WRITE, sgp->sbp, sgp->mx_sb_len)) {
pr_debug("%s:%s:%d access sbp failed %p\n",
skdev->name, __func__, __LINE__, sgp->sbp);
return -EFAULT;
}
}
if (sgp->iovec_count == 0) {
sksgio->iov[0].iov_base = sgp->dxferp;
sksgio->iov[0].iov_len = sgp->dxfer_len;
sksgio->iovcnt = 1;
sksgio->dxfer_len = sgp->dxfer_len;
} else {
struct sg_iovec *iov;
uint nbytes = sizeof(*iov) * sgp->iovec_count;
size_t iov_data_len;
iov = kmalloc(nbytes, GFP_KERNEL);
if (iov == NULL) {
pr_debug("%s:%s:%d alloc iovec failed %d\n",
skdev->name, __func__, __LINE__,
sgp->iovec_count);
return -ENOMEM;
}
sksgio->iov = iov;
sksgio->iovcnt = sgp->iovec_count;
if (copy_from_user(iov, sgp->dxferp, nbytes)) {
pr_debug("%s:%s:%d copy_from_user iovec failed %p\n",
skdev->name, __func__, __LINE__, sgp->dxferp);
return -EFAULT;
}
iov_data_len = 0;
for (i = 0; i < sgp->iovec_count; i++) {
if (iov_data_len + iov[i].iov_len < iov_data_len)
return -EINVAL;
iov_data_len += iov[i].iov_len;
}
if (sgp->dxfer_len < iov_data_len) {
sksgio->iovcnt = iov_shorten((struct iovec *)iov,
sgp->iovec_count,
sgp->dxfer_len);
sksgio->dxfer_len = sgp->dxfer_len;
} else
sksgio->dxfer_len = iov_data_len;
}
if (sgp->dxfer_direction != SG_DXFER_NONE) {
struct sg_iovec *iov = sksgio->iov;
for (i = 0; i < sksgio->iovcnt; i++, iov++) {
if (!access_ok(acc, iov->iov_base, iov->iov_len)) {
pr_debug("%s:%s:%d access data failed %p/%d\n",
skdev->name, __func__, __LINE__,
iov->iov_base, (int)iov->iov_len);
return -EFAULT;
}
}
}
return 0;
}
static int skd_sg_io_obtain_skspcl(struct skd_device *skdev,
struct skd_sg_io *sksgio)
{
struct skd_special_context *skspcl = NULL;
int rc;
for (;;) {
ulong flags;
spin_lock_irqsave(&skdev->lock, flags);
skspcl = skdev->skspcl_free_list;
if (skspcl != NULL) {
skdev->skspcl_free_list =
(struct skd_special_context *)skspcl->req.next;
skspcl->req.id += SKD_ID_INCR;
skspcl->req.state = SKD_REQ_STATE_SETUP;
skspcl->orphaned = 0;
skspcl->req.n_sg = 0;
}
spin_unlock_irqrestore(&skdev->lock, flags);
if (skspcl != NULL) {
rc = 0;
break;
}
pr_debug("%s:%s:%d blocking\n",
skdev->name, __func__, __LINE__);
rc = wait_event_interruptible_timeout(
skdev->waitq,
(skdev->skspcl_free_list != NULL),
msecs_to_jiffies(sksgio->sg.timeout));
pr_debug("%s:%s:%d unblocking, rc=%d\n",
skdev->name, __func__, __LINE__, rc);
if (rc <= 0) {
if (rc == 0)
rc = -ETIMEDOUT;
else
rc = -EINTR;
break;
}
}
sksgio->skspcl = skspcl;
return rc;
}
static int skd_skreq_prep_buffering(struct skd_device *skdev,
struct skd_request_context *skreq,
u32 dxfer_len)
{
u32 resid = dxfer_len;
resid += (-resid) & 3;
skreq->sg_byte_count = resid;
skreq->n_sg = 0;
while (resid > 0) {
u32 nbytes = PAGE_SIZE;
u32 ix = skreq->n_sg;
struct scatterlist *sg = &skreq->sg[ix];
struct fit_sg_descriptor *sksg = &skreq->sksg_list[ix];
struct page *page;
if (nbytes > resid)
nbytes = resid;
page = alloc_page(GFP_KERNEL);
if (page == NULL)
return -ENOMEM;
sg_set_page(sg, page, nbytes, 0);
sksg->control = FIT_SGD_CONTROL_NOT_LAST;
sksg->byte_count = nbytes;
sksg->host_side_addr = sg_phys(sg);
sksg->dev_side_addr = 0;
sksg->next_desc_ptr = skreq->sksg_dma_address +
(ix + 1) * sizeof(*sksg);
skreq->n_sg++;
resid -= nbytes;
}
if (skreq->n_sg > 0) {
u32 ix = skreq->n_sg - 1;
struct fit_sg_descriptor *sksg = &skreq->sksg_list[ix];
sksg->control = FIT_SGD_CONTROL_LAST;
sksg->next_desc_ptr = 0;
}
if (unlikely(skdev->dbg_level > 1)) {
u32 i;
pr_debug("%s:%s:%d skreq=%x sksg_list=%p sksg_dma=%llx\n",
skdev->name, __func__, __LINE__,
skreq->id, skreq->sksg_list, skreq->sksg_dma_address);
for (i = 0; i < skreq->n_sg; i++) {
struct fit_sg_descriptor *sgd = &skreq->sksg_list[i];
pr_debug("%s:%s:%d sg[%d] count=%u ctrl=0x%x "
"addr=0x%llx next=0x%llx\n",
skdev->name, __func__, __LINE__,
i, sgd->byte_count, sgd->control,
sgd->host_side_addr, sgd->next_desc_ptr);
}
}
return 0;
}
static int skd_sg_io_prep_buffering(struct skd_device *skdev,
struct skd_sg_io *sksgio)
{
struct skd_special_context *skspcl = sksgio->skspcl;
struct skd_request_context *skreq = &skspcl->req;
u32 dxfer_len = sksgio->dxfer_len;
int rc;
rc = skd_skreq_prep_buffering(skdev, skreq, dxfer_len);
return rc;
}
static int skd_sg_io_copy_buffer(struct skd_device *skdev,
struct skd_sg_io *sksgio, int dxfer_dir)
{
struct skd_special_context *skspcl = sksgio->skspcl;
u32 iov_ix = 0;
struct sg_iovec curiov;
u32 sksg_ix = 0;
u8 *bufp = NULL;
u32 buf_len = 0;
u32 resid = sksgio->dxfer_len;
int rc;
curiov.iov_len = 0;
curiov.iov_base = NULL;
if (dxfer_dir != sksgio->sg.dxfer_direction) {
if (dxfer_dir != SG_DXFER_TO_DEV ||
sksgio->sg.dxfer_direction != SG_DXFER_TO_FROM_DEV)
return 0;
}
while (resid > 0) {
u32 nbytes = PAGE_SIZE;
if (curiov.iov_len == 0) {
curiov = sksgio->iov[iov_ix++];
continue;
}
if (buf_len == 0) {
struct page *page;
page = sg_page(&skspcl->req.sg[sksg_ix++]);
bufp = page_address(page);
buf_len = PAGE_SIZE;
}
nbytes = min_t(u32, nbytes, resid);
nbytes = min_t(u32, nbytes, curiov.iov_len);
nbytes = min_t(u32, nbytes, buf_len);
if (dxfer_dir == SG_DXFER_TO_DEV)
rc = __copy_from_user(bufp, curiov.iov_base, nbytes);
else
rc = __copy_to_user(curiov.iov_base, bufp, nbytes);
if (rc)
return -EFAULT;
resid -= nbytes;
curiov.iov_len -= nbytes;
curiov.iov_base += nbytes;
buf_len -= nbytes;
}
return 0;
}
static int skd_sg_io_send_fitmsg(struct skd_device *skdev,
struct skd_sg_io *sksgio)
{
struct skd_special_context *skspcl = sksgio->skspcl;
struct fit_msg_hdr *fmh = (struct fit_msg_hdr *)skspcl->msg_buf;
struct skd_scsi_request *scsi_req = (struct skd_scsi_request *)&fmh[1];
memset(skspcl->msg_buf, 0, SKD_N_SPECIAL_FITMSG_BYTES);
fmh->protocol_id = FIT_PROTOCOL_ID_SOFIT;
fmh->num_protocol_cmds_coalesced = 1;
if (sksgio->sg.dxfer_direction != SG_DXFER_NONE)
scsi_req->hdr.sg_list_dma_address =
cpu_to_be64(skspcl->req.sksg_dma_address);
scsi_req->hdr.tag = skspcl->req.id;
scsi_req->hdr.sg_list_len_bytes =
cpu_to_be32(skspcl->req.sg_byte_count);
memcpy(scsi_req->cdb, sksgio->cdb, sizeof(scsi_req->cdb));
skspcl->req.state = SKD_REQ_STATE_BUSY;
skd_send_special_fitmsg(skdev, skspcl);
return 0;
}
static int skd_sg_io_await(struct skd_device *skdev, struct skd_sg_io *sksgio)
{
unsigned long flags;
int rc;
rc = wait_event_interruptible_timeout(skdev->waitq,
(sksgio->skspcl->req.state !=
SKD_REQ_STATE_BUSY),
msecs_to_jiffies(sksgio->sg.
timeout));
spin_lock_irqsave(&skdev->lock, flags);
if (sksgio->skspcl->req.state == SKD_REQ_STATE_ABORTED) {
pr_debug("%s:%s:%d skspcl %p aborted\n",
skdev->name, __func__, __LINE__, sksgio->skspcl);
sksgio->skspcl->req.completion.status =
SAM_STAT_CHECK_CONDITION;
memset(&sksgio->skspcl->req.err_info, 0,
sizeof(sksgio->skspcl->req.err_info));
sksgio->skspcl->req.err_info.type = 0x70;
sksgio->skspcl->req.err_info.key = ABORTED_COMMAND;
sksgio->skspcl->req.err_info.code = 0x44;
sksgio->skspcl->req.err_info.qual = 0;
rc = 0;
} else if (sksgio->skspcl->req.state != SKD_REQ_STATE_BUSY)
rc = 0;
else {
sksgio->skspcl->orphaned = 1;
sksgio->skspcl = NULL;
if (rc == 0) {
pr_debug("%s:%s:%d timed out %p (%u ms)\n",
skdev->name, __func__, __LINE__,
sksgio, sksgio->sg.timeout);
rc = -ETIMEDOUT;
} else {
pr_debug("%s:%s:%d cntlc %p\n",
skdev->name, __func__, __LINE__, sksgio);
rc = -EINTR;
}
}
spin_unlock_irqrestore(&skdev->lock, flags);
return rc;
}
static int skd_sg_io_put_status(struct skd_device *skdev,
struct skd_sg_io *sksgio)
{
struct sg_io_hdr *sgp = &sksgio->sg;
struct skd_special_context *skspcl = sksgio->skspcl;
int resid = 0;
u32 nb = be32_to_cpu(skspcl->req.completion.num_returned_bytes);
sgp->status = skspcl->req.completion.status;
resid = sksgio->dxfer_len - nb;
sgp->masked_status = sgp->status & STATUS_MASK;
sgp->msg_status = 0;
sgp->host_status = 0;
sgp->driver_status = 0;
sgp->resid = resid;
if (sgp->masked_status || sgp->host_status || sgp->driver_status)
sgp->info |= SG_INFO_CHECK;
pr_debug("%s:%s:%d status %x masked %x resid 0x%x\n",
skdev->name, __func__, __LINE__,
sgp->status, sgp->masked_status, sgp->resid);
if (sgp->masked_status == SAM_STAT_CHECK_CONDITION) {
if (sgp->mx_sb_len > 0) {
struct fit_comp_error_info *ei = &skspcl->req.err_info;
u32 nbytes = sizeof(*ei);
nbytes = min_t(u32, nbytes, sgp->mx_sb_len);
sgp->sb_len_wr = nbytes;
if (__copy_to_user(sgp->sbp, ei, nbytes)) {
pr_debug("%s:%s:%d copy_to_user sense failed %p\n",
skdev->name, __func__, __LINE__,
sgp->sbp);
return -EFAULT;
}
}
}
if (__copy_to_user(sksgio->argp, sgp, sizeof(sg_io_hdr_t))) {
pr_debug("%s:%s:%d copy_to_user sg failed %p\n",
skdev->name, __func__, __LINE__, sksgio->argp);
return -EFAULT;
}
return 0;
}
static int skd_sg_io_release_skspcl(struct skd_device *skdev,
struct skd_sg_io *sksgio)
{
struct skd_special_context *skspcl = sksgio->skspcl;
if (skspcl != NULL) {
ulong flags;
sksgio->skspcl = NULL;
spin_lock_irqsave(&skdev->lock, flags);
skd_release_special(skdev, skspcl);
spin_unlock_irqrestore(&skdev->lock, flags);
}
return 0;
}
static int skd_format_internal_skspcl(struct skd_device *skdev)
{
struct skd_special_context *skspcl = &skdev->internal_skspcl;
struct fit_sg_descriptor *sgd = &skspcl->req.sksg_list[0];
struct fit_msg_hdr *fmh;
uint64_t dma_address;
struct skd_scsi_request *scsi;
fmh = (struct fit_msg_hdr *)&skspcl->msg_buf[0];
fmh->protocol_id = FIT_PROTOCOL_ID_SOFIT;
fmh->num_protocol_cmds_coalesced = 1;
scsi = (struct skd_scsi_request *)&skspcl->msg_buf[64];
memset(scsi, 0, sizeof(*scsi));
dma_address = skspcl->req.sksg_dma_address;
scsi->hdr.sg_list_dma_address = cpu_to_be64(dma_address);
sgd->control = FIT_SGD_CONTROL_LAST;
sgd->byte_count = 0;
sgd->host_side_addr = skspcl->db_dma_address;
sgd->dev_side_addr = 0;
sgd->next_desc_ptr = 0LL;
return 1;
}
static void skd_send_internal_skspcl(struct skd_device *skdev,
struct skd_special_context *skspcl,
u8 opcode)
{
struct fit_sg_descriptor *sgd = &skspcl->req.sksg_list[0];
struct skd_scsi_request *scsi;
unsigned char *buf = skspcl->data_buf;
int i;
if (skspcl->req.state != SKD_REQ_STATE_IDLE)
return;
SKD_ASSERT((skspcl->req.id & SKD_ID_INCR) == 0);
skspcl->req.state = SKD_REQ_STATE_BUSY;
skspcl->req.id += SKD_ID_INCR;
scsi = (struct skd_scsi_request *)&skspcl->msg_buf[64];
scsi->hdr.tag = skspcl->req.id;
memset(scsi->cdb, 0, sizeof(scsi->cdb));
switch (opcode) {
case TEST_UNIT_READY:
scsi->cdb[0] = TEST_UNIT_READY;
sgd->byte_count = 0;
scsi->hdr.sg_list_len_bytes = 0;
break;
case READ_CAPACITY:
scsi->cdb[0] = READ_CAPACITY;
sgd->byte_count = SKD_N_READ_CAP_BYTES;
scsi->hdr.sg_list_len_bytes = cpu_to_be32(sgd->byte_count);
break;
case INQUIRY:
scsi->cdb[0] = INQUIRY;
scsi->cdb[1] = 0x01;
scsi->cdb[2] = 0x80;
scsi->cdb[4] = 0x10;
sgd->byte_count = 16;
scsi->hdr.sg_list_len_bytes = cpu_to_be32(sgd->byte_count);
break;
case SYNCHRONIZE_CACHE:
scsi->cdb[0] = SYNCHRONIZE_CACHE;
sgd->byte_count = 0;
scsi->hdr.sg_list_len_bytes = 0;
break;
case WRITE_BUFFER:
scsi->cdb[0] = WRITE_BUFFER;
scsi->cdb[1] = 0x02;
scsi->cdb[7] = (WR_BUF_SIZE & 0xFF00) >> 8;
scsi->cdb[8] = WR_BUF_SIZE & 0xFF;
sgd->byte_count = WR_BUF_SIZE;
scsi->hdr.sg_list_len_bytes = cpu_to_be32(sgd->byte_count);
for (i = 0; i < sgd->byte_count; i++)
buf[i] = i & 0xFF;
break;
case READ_BUFFER:
scsi->cdb[0] = READ_BUFFER;
scsi->cdb[1] = 0x02;
scsi->cdb[7] = (WR_BUF_SIZE & 0xFF00) >> 8;
scsi->cdb[8] = WR_BUF_SIZE & 0xFF;
sgd->byte_count = WR_BUF_SIZE;
scsi->hdr.sg_list_len_bytes = cpu_to_be32(sgd->byte_count);
memset(skspcl->data_buf, 0, sgd->byte_count);
break;
default:
SKD_ASSERT("Don't know what to send");
return;
}
skd_send_special_fitmsg(skdev, skspcl);
}
static void skd_refresh_device_data(struct skd_device *skdev)
{
struct skd_special_context *skspcl = &skdev->internal_skspcl;
skd_send_internal_skspcl(skdev, skspcl, TEST_UNIT_READY);
}
static int skd_chk_read_buf(struct skd_device *skdev,
struct skd_special_context *skspcl)
{
unsigned char *buf = skspcl->data_buf;
int i;
for (i = 0; i < WR_BUF_SIZE; i++)
if (buf[i] != (i & 0xFF))
return 1;
return 0;
}
static void skd_log_check_status(struct skd_device *skdev, u8 status, u8 key,
u8 code, u8 qual, u8 fruc)
{
if ((status == SAM_STAT_CHECK_CONDITION) && (key == 0x02)
&& (code == 0x04) && (qual == 0x06)) {
pr_err("(%s): *** LOST_WRITE_DATA ERROR *** key/asc/"
"ascq/fruc %02x/%02x/%02x/%02x\n",
skd_name(skdev), key, code, qual, fruc);
}
}
static void skd_complete_internal(struct skd_device *skdev,
volatile struct fit_completion_entry_v1
*skcomp,
volatile struct fit_comp_error_info *skerr,
struct skd_special_context *skspcl)
{
u8 *buf = skspcl->data_buf;
u8 status;
int i;
struct skd_scsi_request *scsi =
(struct skd_scsi_request *)&skspcl->msg_buf[64];
SKD_ASSERT(skspcl == &skdev->internal_skspcl);
pr_debug("%s:%s:%d complete internal %x\n",
skdev->name, __func__, __LINE__, scsi->cdb[0]);
skspcl->req.completion = *skcomp;
skspcl->req.state = SKD_REQ_STATE_IDLE;
skspcl->req.id += SKD_ID_INCR;
status = skspcl->req.completion.status;
skd_log_check_status(skdev, status, skerr->key, skerr->code,
skerr->qual, skerr->fruc);
switch (scsi->cdb[0]) {
case TEST_UNIT_READY:
if (status == SAM_STAT_GOOD)
skd_send_internal_skspcl(skdev, skspcl, WRITE_BUFFER);
else if ((status == SAM_STAT_CHECK_CONDITION) &&
(skerr->key == MEDIUM_ERROR))
skd_send_internal_skspcl(skdev, skspcl, WRITE_BUFFER);
else {
if (skdev->state == SKD_DRVR_STATE_STOPPING) {
pr_debug("%s:%s:%d TUR failed, don't send anymore state 0x%x\n",
skdev->name, __func__, __LINE__,
skdev->state);
return;
}
pr_debug("%s:%s:%d **** TUR failed, retry skerr\n",
skdev->name, __func__, __LINE__);
skd_send_internal_skspcl(skdev, skspcl, 0x00);
}
break;
case WRITE_BUFFER:
if (status == SAM_STAT_GOOD)
skd_send_internal_skspcl(skdev, skspcl, READ_BUFFER);
else {
if (skdev->state == SKD_DRVR_STATE_STOPPING) {
pr_debug("%s:%s:%d write buffer failed, don't send anymore state 0x%x\n",
skdev->name, __func__, __LINE__,
skdev->state);
return;
}
pr_debug("%s:%s:%d **** write buffer failed, retry skerr\n",
skdev->name, __func__, __LINE__);
skd_send_internal_skspcl(skdev, skspcl, 0x00);
}
break;
case READ_BUFFER:
if (status == SAM_STAT_GOOD) {
if (skd_chk_read_buf(skdev, skspcl) == 0)
skd_send_internal_skspcl(skdev, skspcl,
READ_CAPACITY);
else {
pr_err(
"(%s):*** W/R Buffer mismatch %d ***\n",
skd_name(skdev), skdev->connect_retries);
if (skdev->connect_retries <
SKD_MAX_CONNECT_RETRIES) {
skdev->connect_retries++;
skd_soft_reset(skdev);
} else {
pr_err(
"(%s): W/R Buffer Connect Error\n",
skd_name(skdev));
return;
}
}
} else {
if (skdev->state == SKD_DRVR_STATE_STOPPING) {
pr_debug("%s:%s:%d "
"read buffer failed, don't send anymore state 0x%x\n",
skdev->name, __func__, __LINE__,
skdev->state);
return;
}
pr_debug("%s:%s:%d "
"**** read buffer failed, retry skerr\n",
skdev->name, __func__, __LINE__);
skd_send_internal_skspcl(skdev, skspcl, 0x00);
}
break;
case READ_CAPACITY:
skdev->read_cap_is_valid = 0;
if (status == SAM_STAT_GOOD) {
skdev->read_cap_last_lba =
(buf[0] << 24) | (buf[1] << 16) |
(buf[2] << 8) | buf[3];
skdev->read_cap_blocksize =
(buf[4] << 24) | (buf[5] << 16) |
(buf[6] << 8) | buf[7];
pr_debug("%s:%s:%d last lba %d, bs %d\n",
skdev->name, __func__, __LINE__,
skdev->read_cap_last_lba,
skdev->read_cap_blocksize);
set_capacity(skdev->disk, skdev->read_cap_last_lba + 1);
skdev->read_cap_is_valid = 1;
skd_send_internal_skspcl(skdev, skspcl, INQUIRY);
} else if ((status == SAM_STAT_CHECK_CONDITION) &&
(skerr->key == MEDIUM_ERROR)) {
skdev->read_cap_last_lba = ~0;
set_capacity(skdev->disk, skdev->read_cap_last_lba + 1);
pr_debug("%s:%s:%d "
"**** MEDIUM ERROR caused READCAP to fail, ignore failure and continue to inquiry\n",
skdev->name, __func__, __LINE__);
skd_send_internal_skspcl(skdev, skspcl, INQUIRY);
} else {
pr_debug("%s:%s:%d **** READCAP failed, retry TUR\n",
skdev->name, __func__, __LINE__);
skd_send_internal_skspcl(skdev, skspcl,
TEST_UNIT_READY);
}
break;
case INQUIRY:
skdev->inquiry_is_valid = 0;
if (status == SAM_STAT_GOOD) {
skdev->inquiry_is_valid = 1;
for (i = 0; i < 12; i++)
skdev->inq_serial_num[i] = buf[i + 4];
skdev->inq_serial_num[12] = 0;
}
if (skd_unquiesce_dev(skdev) < 0)
pr_debug("%s:%s:%d **** failed, to ONLINE device\n",
skdev->name, __func__, __LINE__);
skdev->connect_retries = 0;
break;
case SYNCHRONIZE_CACHE:
if (status == SAM_STAT_GOOD)
skdev->sync_done = 1;
else
skdev->sync_done = -1;
wake_up_interruptible(&skdev->waitq);
break;
default:
SKD_ASSERT("we didn't send this");
}
}
static void skd_send_fitmsg(struct skd_device *skdev,
struct skd_fitmsg_context *skmsg)
{
u64 qcmd;
struct fit_msg_hdr *fmh;
pr_debug("%s:%s:%d dma address 0x%llx, busy=%d\n",
skdev->name, __func__, __LINE__,
skmsg->mb_dma_address, skdev->in_flight);
pr_debug("%s:%s:%d msg_buf 0x%p, offset %x\n",
skdev->name, __func__, __LINE__,
skmsg->msg_buf, skmsg->offset);
qcmd = skmsg->mb_dma_address;
qcmd |= FIT_QCMD_QID_NORMAL;
fmh = (struct fit_msg_hdr *)skmsg->msg_buf;
skmsg->outstanding = fmh->num_protocol_cmds_coalesced;
if (unlikely(skdev->dbg_level > 1)) {
u8 *bp = (u8 *)skmsg->msg_buf;
int i;
for (i = 0; i < skmsg->length; i += 8) {
pr_debug("%s:%s:%d msg[%2d] %8ph\n",
skdev->name, __func__, __LINE__, i, &bp[i]);
if (i == 0)
i = 64 - 8;
}
}
if (skmsg->length > 256)
qcmd |= FIT_QCMD_MSGSIZE_512;
else if (skmsg->length > 128)
qcmd |= FIT_QCMD_MSGSIZE_256;
else if (skmsg->length > 64)
qcmd |= FIT_QCMD_MSGSIZE_128;
else
qcmd |= FIT_QCMD_MSGSIZE_64;
SKD_WRITEQ(skdev, qcmd, FIT_Q_COMMAND);
}
static void skd_send_special_fitmsg(struct skd_device *skdev,
struct skd_special_context *skspcl)
{
u64 qcmd;
if (unlikely(skdev->dbg_level > 1)) {
u8 *bp = (u8 *)skspcl->msg_buf;
int i;
for (i = 0; i < SKD_N_SPECIAL_FITMSG_BYTES; i += 8) {
pr_debug("%s:%s:%d spcl[%2d] %8ph\n",
skdev->name, __func__, __LINE__, i, &bp[i]);
if (i == 0)
i = 64 - 8;
}
pr_debug("%s:%s:%d skspcl=%p id=%04x sksg_list=%p sksg_dma=%llx\n",
skdev->name, __func__, __LINE__,
skspcl, skspcl->req.id, skspcl->req.sksg_list,
skspcl->req.sksg_dma_address);
for (i = 0; i < skspcl->req.n_sg; i++) {
struct fit_sg_descriptor *sgd =
&skspcl->req.sksg_list[i];
pr_debug("%s:%s:%d sg[%d] count=%u ctrl=0x%x "
"addr=0x%llx next=0x%llx\n",
skdev->name, __func__, __LINE__,
i, sgd->byte_count, sgd->control,
sgd->host_side_addr, sgd->next_desc_ptr);
}
}
qcmd = skspcl->mb_dma_address;
qcmd |= FIT_QCMD_QID_NORMAL + FIT_QCMD_MSGSIZE_128;
SKD_WRITEQ(skdev, qcmd, FIT_Q_COMMAND);
}
static enum skd_check_status_action
skd_check_status(struct skd_device *skdev,
u8 cmp_status, volatile struct fit_comp_error_info *skerr)
{
int i, n;
pr_err("(%s): key/asc/ascq/fruc %02x/%02x/%02x/%02x\n",
skd_name(skdev), skerr->key, skerr->code, skerr->qual,
skerr->fruc);
pr_debug("%s:%s:%d stat: t=%02x stat=%02x k=%02x c=%02x q=%02x fruc=%02x\n",
skdev->name, __func__, __LINE__, skerr->type, cmp_status,
skerr->key, skerr->code, skerr->qual, skerr->fruc);
n = sizeof(skd_chkstat_table) / sizeof(skd_chkstat_table[0]);
for (i = 0; i < n; i++) {
struct sns_info *sns = &skd_chkstat_table[i];
if (sns->mask & 0x10)
if (skerr->type != sns->type)
continue;
if (sns->mask & 0x08)
if (cmp_status != sns->stat)
continue;
if (sns->mask & 0x04)
if (skerr->key != sns->key)
continue;
if (sns->mask & 0x02)
if (skerr->code != sns->asc)
continue;
if (sns->mask & 0x01)
if (skerr->qual != sns->ascq)
continue;
if (sns->action == SKD_CHECK_STATUS_REPORT_SMART_ALERT) {
pr_err("(%s): SMART Alert: sense key/asc/ascq "
"%02x/%02x/%02x\n",
skd_name(skdev), skerr->key,
skerr->code, skerr->qual);
}
return sns->action;
}
if (cmp_status) {
pr_debug("%s:%s:%d status check: error\n",
skdev->name, __func__, __LINE__);
return SKD_CHECK_STATUS_REPORT_ERROR;
}
pr_debug("%s:%s:%d status check good default\n",
skdev->name, __func__, __LINE__);
return SKD_CHECK_STATUS_REPORT_GOOD;
}
static void skd_resolve_req_exception(struct skd_device *skdev,
struct skd_request_context *skreq)
{
u8 cmp_status = skreq->completion.status;
switch (skd_check_status(skdev, cmp_status, &skreq->err_info)) {
case SKD_CHECK_STATUS_REPORT_GOOD:
case SKD_CHECK_STATUS_REPORT_SMART_ALERT:
skd_end_request(skdev, skreq, 0);
break;
case SKD_CHECK_STATUS_BUSY_IMMINENT:
skd_log_skreq(skdev, skreq, "retry(busy)");
blk_requeue_request(skdev->queue, skreq->req);
pr_info("(%s) drive BUSY imminent\n", skd_name(skdev));
skdev->state = SKD_DRVR_STATE_BUSY_IMMINENT;
skdev->timer_countdown = SKD_TIMER_MINUTES(20);
skd_quiesce_dev(skdev);
break;
case SKD_CHECK_STATUS_REQUEUE_REQUEST:
if ((unsigned long) ++skreq->req->special < SKD_MAX_RETRIES) {
skd_log_skreq(skdev, skreq, "retry");
blk_requeue_request(skdev->queue, skreq->req);
break;
}
case SKD_CHECK_STATUS_REPORT_ERROR:
default:
skd_end_request(skdev, skreq, -EIO);
break;
}
}
static void skd_release_skreq(struct skd_device *skdev,
struct skd_request_context *skreq)
{
u32 msg_slot;
struct skd_fitmsg_context *skmsg;
u32 timo_slot;
msg_slot = skreq->fitmsg_id & SKD_ID_SLOT_MASK;
SKD_ASSERT(msg_slot < skdev->num_fitmsg_context);
skmsg = &skdev->skmsg_table[msg_slot];
if (skmsg->id == skreq->fitmsg_id) {
SKD_ASSERT(skmsg->state == SKD_MSG_STATE_BUSY);
SKD_ASSERT(skmsg->outstanding > 0);
skmsg->outstanding--;
if (skmsg->outstanding == 0) {
skmsg->state = SKD_MSG_STATE_IDLE;
skmsg->id += SKD_ID_INCR;
skmsg->next = skdev->skmsg_free_list;
skdev->skmsg_free_list = skmsg;
}
}
SKD_ASSERT(skdev->in_flight > 0);
skdev->in_flight -= 1;
timo_slot = skreq->timeout_stamp & SKD_TIMEOUT_SLOT_MASK;
SKD_ASSERT(skdev->timeout_slot[timo_slot] > 0);
skdev->timeout_slot[timo_slot] -= 1;
skreq->req = NULL;
skreq->state = SKD_REQ_STATE_IDLE;
skreq->id += SKD_ID_INCR;
skreq->next = skdev->skreq_free_list;
skdev->skreq_free_list = skreq;
}
static void skd_do_inq_page_00(struct skd_device *skdev,
volatile struct fit_completion_entry_v1 *skcomp,
volatile struct fit_comp_error_info *skerr,
uint8_t *cdb, uint8_t *buf)
{
uint16_t insert_pt, max_bytes, drive_pages, drive_bytes, new_size;
pr_debug("%s:%s:%d skd_do_driver_inquiry: modify supported pages.\n",
skdev->name, __func__, __LINE__);
if (skcomp->status == SAM_STAT_CHECK_CONDITION &&
skerr->key == ILLEGAL_REQUEST && skerr->code == 0x24)
return;
max_bytes = (cdb[3] << 8) | cdb[4];
drive_pages = (buf[2] << 8) | buf[3];
drive_bytes = drive_pages + 4;
new_size = drive_pages + 1;
for (insert_pt = 4; insert_pt < drive_bytes; insert_pt++) {
if (buf[insert_pt] == DRIVER_INQ_EVPD_PAGE_CODE)
return;
else if (buf[insert_pt] > DRIVER_INQ_EVPD_PAGE_CODE)
break;
}
if (insert_pt < max_bytes) {
uint16_t u;
for (u = new_size + 3; u > insert_pt; u--)
buf[u] = buf[u - 1];
buf[insert_pt] = DRIVER_INQ_EVPD_PAGE_CODE;
skcomp->num_returned_bytes =
be32_to_cpu(skcomp->num_returned_bytes) + 1;
skcomp->num_returned_bytes =
be32_to_cpu(skcomp->num_returned_bytes);
}
buf[2] = (uint8_t)((new_size >> 8) & 0xFF);
buf[3] = (uint8_t)((new_size >> 0) & 0xFF);
}
static void skd_get_link_info(struct pci_dev *pdev, u8 *speed, u8 *width)
{
int pcie_reg;
u16 pci_bus_speed;
u8 pci_lanes;
pcie_reg = pci_find_capability(pdev, PCI_CAP_ID_EXP);
if (pcie_reg) {
u16 linksta;
pci_read_config_word(pdev, pcie_reg + PCI_EXP_LNKSTA, &linksta);
pci_bus_speed = linksta & 0xF;
pci_lanes = (linksta & 0x3F0) >> 4;
} else {
*speed = STEC_LINK_UNKNOWN;
*width = 0xFF;
return;
}
switch (pci_bus_speed) {
case 1:
*speed = STEC_LINK_2_5GTS;
break;
case 2:
*speed = STEC_LINK_5GTS;
break;
case 3:
*speed = STEC_LINK_8GTS;
break;
default:
*speed = STEC_LINK_UNKNOWN;
break;
}
if (pci_lanes <= 0x20)
*width = pci_lanes;
else
*width = 0xFF;
}
static void skd_do_inq_page_da(struct skd_device *skdev,
volatile struct fit_completion_entry_v1 *skcomp,
volatile struct fit_comp_error_info *skerr,
uint8_t *cdb, uint8_t *buf)
{
struct pci_dev *pdev = skdev->pdev;
unsigned max_bytes;
struct driver_inquiry_data inq;
u16 val;
pr_debug("%s:%s:%d skd_do_driver_inquiry: return driver page\n",
skdev->name, __func__, __LINE__);
memset(&inq, 0, sizeof(inq));
inq.page_code = DRIVER_INQ_EVPD_PAGE_CODE;
skd_get_link_info(pdev, &inq.pcie_link_speed, &inq.pcie_link_lanes);
inq.pcie_bus_number = cpu_to_be16(pdev->bus->number);
inq.pcie_device_number = PCI_SLOT(pdev->devfn);
inq.pcie_function_number = PCI_FUNC(pdev->devfn);
pci_read_config_word(pdev, PCI_VENDOR_ID, &val);
inq.pcie_vendor_id = cpu_to_be16(val);
pci_read_config_word(pdev, PCI_DEVICE_ID, &val);
inq.pcie_device_id = cpu_to_be16(val);
pci_read_config_word(pdev, PCI_SUBSYSTEM_VENDOR_ID, &val);
inq.pcie_subsystem_vendor_id = cpu_to_be16(val);
pci_read_config_word(pdev, PCI_SUBSYSTEM_ID, &val);
inq.pcie_subsystem_device_id = cpu_to_be16(val);
inq.driver_version_length = sizeof(inq.driver_version);
memset(&inq.driver_version, ' ', sizeof(inq.driver_version));
memcpy(inq.driver_version, DRV_VER_COMPL,
min(sizeof(inq.driver_version), strlen(DRV_VER_COMPL)));
inq.page_length = cpu_to_be16((sizeof(inq) - 4));
skcomp->status = SAM_STAT_GOOD;
memset((void *)skerr, 0, sizeof(*skerr));
max_bytes = (cdb[3] << 8) | cdb[4];
memcpy(buf, &inq, min_t(unsigned, max_bytes, sizeof(inq)));
skcomp->num_returned_bytes =
be32_to_cpu(min_t(uint16_t, max_bytes, sizeof(inq)));
}
static void skd_do_driver_inq(struct skd_device *skdev,
volatile struct fit_completion_entry_v1 *skcomp,
volatile struct fit_comp_error_info *skerr,
uint8_t *cdb, uint8_t *buf)
{
if (!buf)
return;
else if (cdb[0] != INQUIRY)
return;
else if ((cdb[1] & 1) == 0)
return;
else if (cdb[2] == 0)
skd_do_inq_page_00(skdev, skcomp, skerr, cdb, buf);
else if (cdb[2] == DRIVER_INQ_EVPD_PAGE_CODE)
skd_do_inq_page_da(skdev, skcomp, skerr, cdb, buf);
}
static unsigned char *skd_sg_1st_page_ptr(struct scatterlist *sg)
{
if (!sg)
return NULL;
if (!sg_page(sg))
return NULL;
return sg_virt(sg);
}
static void skd_process_scsi_inq(struct skd_device *skdev,
volatile struct fit_completion_entry_v1
*skcomp,
volatile struct fit_comp_error_info *skerr,
struct skd_special_context *skspcl)
{
uint8_t *buf;
struct fit_msg_hdr *fmh = (struct fit_msg_hdr *)skspcl->msg_buf;
struct skd_scsi_request *scsi_req = (struct skd_scsi_request *)&fmh[1];
dma_sync_sg_for_cpu(skdev->class_dev, skspcl->req.sg, skspcl->req.n_sg,
skspcl->req.sg_data_dir);
buf = skd_sg_1st_page_ptr(skspcl->req.sg);
if (buf)
skd_do_driver_inq(skdev, skcomp, skerr, scsi_req->cdb, buf);
}
static int skd_isr_completion_posted(struct skd_device *skdev,
int limit, int *enqueued)
{
volatile struct fit_completion_entry_v1 *skcmp = NULL;
volatile struct fit_comp_error_info *skerr;
u16 req_id;
u32 req_slot;
struct skd_request_context *skreq;
u16 cmp_cntxt = 0;
u8 cmp_status = 0;
u8 cmp_cycle = 0;
u32 cmp_bytes = 0;
int rc = 0;
int processed = 0;
for (;; ) {
SKD_ASSERT(skdev->skcomp_ix < SKD_N_COMPLETION_ENTRY);
skcmp = &skdev->skcomp_table[skdev->skcomp_ix];
cmp_cycle = skcmp->cycle;
cmp_cntxt = skcmp->tag;
cmp_status = skcmp->status;
cmp_bytes = be32_to_cpu(skcmp->num_returned_bytes);
skerr = &skdev->skerr_table[skdev->skcomp_ix];
pr_debug("%s:%s:%d "
"cycle=%d ix=%d got cycle=%d cmdctxt=0x%x stat=%d "
"busy=%d rbytes=0x%x proto=%d\n",
skdev->name, __func__, __LINE__, skdev->skcomp_cycle,
skdev->skcomp_ix, cmp_cycle, cmp_cntxt, cmp_status,
skdev->in_flight, cmp_bytes, skdev->proto_ver);
if (cmp_cycle != skdev->skcomp_cycle) {
pr_debug("%s:%s:%d end of completions\n",
skdev->name, __func__, __LINE__);
break;
}
skdev->skcomp_ix++;
if (skdev->skcomp_ix >= SKD_N_COMPLETION_ENTRY) {
skdev->skcomp_ix = 0;
skdev->skcomp_cycle++;
}
req_id = cmp_cntxt;
req_slot = req_id & SKD_ID_SLOT_AND_TABLE_MASK;
if (req_slot >= skdev->num_req_context) {
skd_complete_other(skdev, skcmp, skerr);
continue;
}
skreq = &skdev->skreq_table[req_slot];
if (skreq->id != req_id) {
pr_debug("%s:%s:%d mismatch comp_id=0x%x req_id=0x%x\n",
skdev->name, __func__, __LINE__,
req_id, skreq->id);
{
u16 new_id = cmp_cntxt;
pr_err("(%s): Completion mismatch "
"comp_id=0x%04x skreq=0x%04x new=0x%04x\n",
skd_name(skdev), req_id,
skreq->id, new_id);
continue;
}
}
SKD_ASSERT(skreq->state == SKD_REQ_STATE_BUSY);
if (skreq->state == SKD_REQ_STATE_ABORTED) {
pr_debug("%s:%s:%d reclaim req %p id=%04x\n",
skdev->name, __func__, __LINE__,
skreq, skreq->id);
skd_release_skreq(skdev, skreq);
continue;
}
skreq->completion = *skcmp;
if (unlikely(cmp_status == SAM_STAT_CHECK_CONDITION)) {
skreq->err_info = *skerr;
skd_log_check_status(skdev, cmp_status, skerr->key,
skerr->code, skerr->qual,
skerr->fruc);
}
if (skreq->n_sg > 0)
skd_postop_sg_list(skdev, skreq);
if (!skreq->req) {
pr_debug("%s:%s:%d NULL backptr skdreq %p, "
"req=0x%x req_id=0x%x\n",
skdev->name, __func__, __LINE__,
skreq, skreq->id, req_id);
} else {
if (likely(cmp_status == SAM_STAT_GOOD))
skd_end_request(skdev, skreq, 0);
else
skd_resolve_req_exception(skdev, skreq);
}
skd_release_skreq(skdev, skreq);
if (limit) {
if (++processed >= limit) {
rc = 1;
break;
}
}
}
if ((skdev->state == SKD_DRVR_STATE_PAUSING)
&& (skdev->in_flight) == 0) {
skdev->state = SKD_DRVR_STATE_PAUSED;
wake_up_interruptible(&skdev->waitq);
}
return rc;
}
static void skd_complete_other(struct skd_device *skdev,
volatile struct fit_completion_entry_v1 *skcomp,
volatile struct fit_comp_error_info *skerr)
{
u32 req_id = 0;
u32 req_table;
u32 req_slot;
struct skd_special_context *skspcl;
req_id = skcomp->tag;
req_table = req_id & SKD_ID_TABLE_MASK;
req_slot = req_id & SKD_ID_SLOT_MASK;
pr_debug("%s:%s:%d table=0x%x id=0x%x slot=%d\n",
skdev->name, __func__, __LINE__,
req_table, req_id, req_slot);
switch (req_table) {
case SKD_ID_RW_REQUEST:
break;
case SKD_ID_SPECIAL_REQUEST:
if (req_slot < skdev->n_special) {
skspcl = &skdev->skspcl_table[req_slot];
if (skspcl->req.id == req_id &&
skspcl->req.state == SKD_REQ_STATE_BUSY) {
skd_complete_special(skdev,
skcomp, skerr, skspcl);
return;
}
}
break;
case SKD_ID_INTERNAL:
if (req_slot == 0) {
skspcl = &skdev->internal_skspcl;
if (skspcl->req.id == req_id &&
skspcl->req.state == SKD_REQ_STATE_BUSY) {
skd_complete_internal(skdev,
skcomp, skerr, skspcl);
return;
}
}
break;
case SKD_ID_FIT_MSG:
break;
default:
break;
}
}
static void skd_complete_special(struct skd_device *skdev,
volatile struct fit_completion_entry_v1
*skcomp,
volatile struct fit_comp_error_info *skerr,
struct skd_special_context *skspcl)
{
pr_debug("%s:%s:%d completing special request %p\n",
skdev->name, __func__, __LINE__, skspcl);
if (skspcl->orphaned) {
pr_debug("%s:%s:%d release orphaned %p\n",
skdev->name, __func__, __LINE__, skspcl);
skd_release_special(skdev, skspcl);
return;
}
skd_process_scsi_inq(skdev, skcomp, skerr, skspcl);
skspcl->req.state = SKD_REQ_STATE_COMPLETED;
skspcl->req.completion = *skcomp;
skspcl->req.err_info = *skerr;
skd_log_check_status(skdev, skspcl->req.completion.status, skerr->key,
skerr->code, skerr->qual, skerr->fruc);
wake_up_interruptible(&skdev->waitq);
}
static void skd_release_special(struct skd_device *skdev,
struct skd_special_context *skspcl)
{
int i, was_depleted;
for (i = 0; i < skspcl->req.n_sg; i++) {
struct page *page = sg_page(&skspcl->req.sg[i]);
__free_page(page);
}
was_depleted = (skdev->skspcl_free_list == NULL);
skspcl->req.state = SKD_REQ_STATE_IDLE;
skspcl->req.id += SKD_ID_INCR;
skspcl->req.next =
(struct skd_request_context *)skdev->skspcl_free_list;
skdev->skspcl_free_list = (struct skd_special_context *)skspcl;
if (was_depleted) {
pr_debug("%s:%s:%d skspcl was depleted\n",
skdev->name, __func__, __LINE__);
wake_up_interruptible(&skdev->waitq);
}
}
static void skd_reset_skcomp(struct skd_device *skdev)
{
u32 nbytes;
struct fit_completion_entry_v1 *skcomp;
nbytes = sizeof(*skcomp) * SKD_N_COMPLETION_ENTRY;
nbytes += sizeof(struct fit_comp_error_info) * SKD_N_COMPLETION_ENTRY;
memset(skdev->skcomp_table, 0, nbytes);
skdev->skcomp_ix = 0;
skdev->skcomp_cycle = 1;
}
static void skd_completion_worker(struct work_struct *work)
{
struct skd_device *skdev =
container_of(work, struct skd_device, completion_worker);
unsigned long flags;
int flush_enqueued = 0;
spin_lock_irqsave(&skdev->lock, flags);
skd_isr_completion_posted(skdev, 0, &flush_enqueued);
skd_request_fn(skdev->queue);
spin_unlock_irqrestore(&skdev->lock, flags);
}
static irqreturn_t
skd_isr(int irq, void *ptr)
{
struct skd_device *skdev;
u32 intstat;
u32 ack;
int rc = 0;
int deferred = 0;
int flush_enqueued = 0;
skdev = (struct skd_device *)ptr;
spin_lock(&skdev->lock);
for (;; ) {
intstat = SKD_READL(skdev, FIT_INT_STATUS_HOST);
ack = FIT_INT_DEF_MASK;
ack &= intstat;
pr_debug("%s:%s:%d intstat=0x%x ack=0x%x\n",
skdev->name, __func__, __LINE__, intstat, ack);
if (ack == 0) {
if (rc == 0)
if (likely (skdev->state
== SKD_DRVR_STATE_ONLINE))
deferred = 1;
break;
}
rc = IRQ_HANDLED;
SKD_WRITEL(skdev, ack, FIT_INT_STATUS_HOST);
if (likely((skdev->state != SKD_DRVR_STATE_LOAD) &&
(skdev->state != SKD_DRVR_STATE_STOPPING))) {
if (intstat & FIT_ISH_COMPLETION_POSTED) {
if (deferred == 0)
deferred =
skd_isr_completion_posted(skdev,
skd_isr_comp_limit, &flush_enqueued);
}
if (intstat & FIT_ISH_FW_STATE_CHANGE) {
skd_isr_fwstate(skdev);
if (skdev->state == SKD_DRVR_STATE_FAULT ||
skdev->state ==
SKD_DRVR_STATE_DISAPPEARED) {
spin_unlock(&skdev->lock);
return rc;
}
}
if (intstat & FIT_ISH_MSG_FROM_DEV)
skd_isr_msg_from_dev(skdev);
}
}
if (unlikely(flush_enqueued))
skd_request_fn(skdev->queue);
if (deferred)
schedule_work(&skdev->completion_worker);
else if (!flush_enqueued)
skd_request_fn(skdev->queue);
spin_unlock(&skdev->lock);
return rc;
}
static void skd_drive_fault(struct skd_device *skdev)
{
skdev->state = SKD_DRVR_STATE_FAULT;
pr_err("(%s): Drive FAULT\n", skd_name(skdev));
}
static void skd_drive_disappeared(struct skd_device *skdev)
{
skdev->state = SKD_DRVR_STATE_DISAPPEARED;
pr_err("(%s): Drive DISAPPEARED\n", skd_name(skdev));
}
static void skd_isr_fwstate(struct skd_device *skdev)
{
u32 sense;
u32 state;
u32 mtd;
int prev_driver_state = skdev->state;
sense = SKD_READL(skdev, FIT_STATUS);
state = sense & FIT_SR_DRIVE_STATE_MASK;
pr_err("(%s): s1120 state %s(%d)=>%s(%d)\n",
skd_name(skdev),
skd_drive_state_to_str(skdev->drive_state), skdev->drive_state,
skd_drive_state_to_str(state), state);
skdev->drive_state = state;
switch (skdev->drive_state) {
case FIT_SR_DRIVE_INIT:
if (skdev->state == SKD_DRVR_STATE_PROTOCOL_MISMATCH) {
skd_disable_interrupts(skdev);
break;
}
if (skdev->state == SKD_DRVR_STATE_RESTARTING)
skd_recover_requests(skdev, 0);
if (skdev->state == SKD_DRVR_STATE_WAIT_BOOT) {
skdev->timer_countdown = SKD_STARTING_TIMO;
skdev->state = SKD_DRVR_STATE_STARTING;
skd_soft_reset(skdev);
break;
}
mtd = FIT_MXD_CONS(FIT_MTD_FITFW_INIT, 0, 0);
SKD_WRITEL(skdev, mtd, FIT_MSG_TO_DEVICE);
skdev->last_mtd = mtd;
break;
case FIT_SR_DRIVE_ONLINE:
skdev->cur_max_queue_depth = skd_max_queue_depth;
if (skdev->cur_max_queue_depth > skdev->dev_max_queue_depth)
skdev->cur_max_queue_depth = skdev->dev_max_queue_depth;
skdev->queue_low_water_mark =
skdev->cur_max_queue_depth * 2 / 3 + 1;
if (skdev->queue_low_water_mark < 1)
skdev->queue_low_water_mark = 1;
pr_info(
"(%s): Queue depth limit=%d dev=%d lowat=%d\n",
skd_name(skdev),
skdev->cur_max_queue_depth,
skdev->dev_max_queue_depth, skdev->queue_low_water_mark);
skd_refresh_device_data(skdev);
break;
case FIT_SR_DRIVE_BUSY:
skdev->state = SKD_DRVR_STATE_BUSY;
skdev->timer_countdown = SKD_BUSY_TIMO;
skd_quiesce_dev(skdev);
break;
case FIT_SR_DRIVE_BUSY_SANITIZE:
skdev->state = SKD_DRVR_STATE_BUSY_SANITIZE;
skdev->timer_countdown = SKD_TIMER_SECONDS(3);
blk_start_queue(skdev->queue);
break;
case FIT_SR_DRIVE_BUSY_ERASE:
skdev->state = SKD_DRVR_STATE_BUSY_ERASE;
skdev->timer_countdown = SKD_BUSY_TIMO;
break;
case FIT_SR_DRIVE_OFFLINE:
skdev->state = SKD_DRVR_STATE_IDLE;
break;
case FIT_SR_DRIVE_SOFT_RESET:
switch (skdev->state) {
case SKD_DRVR_STATE_STARTING:
case SKD_DRVR_STATE_RESTARTING:
break;
default:
skdev->state = SKD_DRVR_STATE_RESTARTING;
break;
}
break;
case FIT_SR_DRIVE_FW_BOOTING:
pr_debug("%s:%s:%d ISR FIT_SR_DRIVE_FW_BOOTING %s\n",
skdev->name, __func__, __LINE__, skdev->name);
skdev->state = SKD_DRVR_STATE_WAIT_BOOT;
skdev->timer_countdown = SKD_WAIT_BOOT_TIMO;
break;
case FIT_SR_DRIVE_DEGRADED:
case FIT_SR_PCIE_LINK_DOWN:
case FIT_SR_DRIVE_NEED_FW_DOWNLOAD:
break;
case FIT_SR_DRIVE_FAULT:
skd_drive_fault(skdev);
skd_recover_requests(skdev, 0);
blk_start_queue(skdev->queue);
break;
case 0xFF:
pr_info("(%s): state=0x%x sense=0x%x\n",
skd_name(skdev), state, sense);
skd_drive_disappeared(skdev);
skd_recover_requests(skdev, 0);
blk_start_queue(skdev->queue);
break;
default:
break;
}
pr_err("(%s): Driver state %s(%d)=>%s(%d)\n",
skd_name(skdev),
skd_skdev_state_to_str(prev_driver_state), prev_driver_state,
skd_skdev_state_to_str(skdev->state), skdev->state);
}
static void skd_recover_requests(struct skd_device *skdev, int requeue)
{
int i;
for (i = 0; i < skdev->num_req_context; i++) {
struct skd_request_context *skreq = &skdev->skreq_table[i];
if (skreq->state == SKD_REQ_STATE_BUSY) {
skd_log_skreq(skdev, skreq, "recover");
SKD_ASSERT((skreq->id & SKD_ID_INCR) != 0);
SKD_ASSERT(skreq->req != NULL);
if (skreq->n_sg > 0)
skd_postop_sg_list(skdev, skreq);
if (requeue &&
(unsigned long) ++skreq->req->special <
SKD_MAX_RETRIES)
blk_requeue_request(skdev->queue, skreq->req);
else
skd_end_request(skdev, skreq, -EIO);
skreq->req = NULL;
skreq->state = SKD_REQ_STATE_IDLE;
skreq->id += SKD_ID_INCR;
}
if (i > 0)
skreq[-1].next = skreq;
skreq->next = NULL;
}
skdev->skreq_free_list = skdev->skreq_table;
for (i = 0; i < skdev->num_fitmsg_context; i++) {
struct skd_fitmsg_context *skmsg = &skdev->skmsg_table[i];
if (skmsg->state == SKD_MSG_STATE_BUSY) {
skd_log_skmsg(skdev, skmsg, "salvaged");
SKD_ASSERT((skmsg->id & SKD_ID_INCR) != 0);
skmsg->state = SKD_MSG_STATE_IDLE;
skmsg->id += SKD_ID_INCR;
}
if (i > 0)
skmsg[-1].next = skmsg;
skmsg->next = NULL;
}
skdev->skmsg_free_list = skdev->skmsg_table;
for (i = 0; i < skdev->n_special; i++) {
struct skd_special_context *skspcl = &skdev->skspcl_table[i];
if (skspcl->req.state == SKD_REQ_STATE_BUSY) {
if (skspcl->orphaned) {
pr_debug("%s:%s:%d orphaned %p\n",
skdev->name, __func__, __LINE__,
skspcl);
skd_release_special(skdev, skspcl);
} else {
pr_debug("%s:%s:%d not orphaned %p\n",
skdev->name, __func__, __LINE__,
skspcl);
skspcl->req.state = SKD_REQ_STATE_ABORTED;
}
}
}
skdev->skspcl_free_list = skdev->skspcl_table;
for (i = 0; i < SKD_N_TIMEOUT_SLOT; i++)
skdev->timeout_slot[i] = 0;
skdev->in_flight = 0;
}
static void skd_isr_msg_from_dev(struct skd_device *skdev)
{
u32 mfd;
u32 mtd;
u32 data;
mfd = SKD_READL(skdev, FIT_MSG_FROM_DEVICE);
pr_debug("%s:%s:%d mfd=0x%x last_mtd=0x%x\n",
skdev->name, __func__, __LINE__, mfd, skdev->last_mtd);
if (FIT_MXD_TYPE(mfd) != FIT_MXD_TYPE(skdev->last_mtd))
return;
switch (FIT_MXD_TYPE(mfd)) {
case FIT_MTD_FITFW_INIT:
skdev->proto_ver = FIT_PROTOCOL_MAJOR_VER(mfd);
if (skdev->proto_ver != FIT_PROTOCOL_VERSION_1) {
pr_err("(%s): protocol mismatch\n",
skdev->name);
pr_err("(%s): got=%d support=%d\n",
skdev->name, skdev->proto_ver,
FIT_PROTOCOL_VERSION_1);
pr_err("(%s): please upgrade driver\n",
skdev->name);
skdev->state = SKD_DRVR_STATE_PROTOCOL_MISMATCH;
skd_soft_reset(skdev);
break;
}
mtd = FIT_MXD_CONS(FIT_MTD_GET_CMDQ_DEPTH, 0, 0);
SKD_WRITEL(skdev, mtd, FIT_MSG_TO_DEVICE);
skdev->last_mtd = mtd;
break;
case FIT_MTD_GET_CMDQ_DEPTH:
skdev->dev_max_queue_depth = FIT_MXD_DATA(mfd);
mtd = FIT_MXD_CONS(FIT_MTD_SET_COMPQ_DEPTH, 0,
SKD_N_COMPLETION_ENTRY);
SKD_WRITEL(skdev, mtd, FIT_MSG_TO_DEVICE);
skdev->last_mtd = mtd;
break;
case FIT_MTD_SET_COMPQ_DEPTH:
SKD_WRITEQ(skdev, skdev->cq_dma_address, FIT_MSG_TO_DEVICE_ARG);
mtd = FIT_MXD_CONS(FIT_MTD_SET_COMPQ_ADDR, 0, 0);
SKD_WRITEL(skdev, mtd, FIT_MSG_TO_DEVICE);
skdev->last_mtd = mtd;
break;
case FIT_MTD_SET_COMPQ_ADDR:
skd_reset_skcomp(skdev);
mtd = FIT_MXD_CONS(FIT_MTD_CMD_LOG_HOST_ID, 0, skdev->devno);
SKD_WRITEL(skdev, mtd, FIT_MSG_TO_DEVICE);
skdev->last_mtd = mtd;
break;
case FIT_MTD_CMD_LOG_HOST_ID:
skdev->connect_time_stamp = get_seconds();
data = skdev->connect_time_stamp & 0xFFFF;
mtd = FIT_MXD_CONS(FIT_MTD_CMD_LOG_TIME_STAMP_LO, 0, data);
SKD_WRITEL(skdev, mtd, FIT_MSG_TO_DEVICE);
skdev->last_mtd = mtd;
break;
case FIT_MTD_CMD_LOG_TIME_STAMP_LO:
skdev->drive_jiffies = FIT_MXD_DATA(mfd);
data = (skdev->connect_time_stamp >> 16) & 0xFFFF;
mtd = FIT_MXD_CONS(FIT_MTD_CMD_LOG_TIME_STAMP_HI, 0, data);
SKD_WRITEL(skdev, mtd, FIT_MSG_TO_DEVICE);
skdev->last_mtd = mtd;
break;
case FIT_MTD_CMD_LOG_TIME_STAMP_HI:
skdev->drive_jiffies |= (FIT_MXD_DATA(mfd) << 16);
mtd = FIT_MXD_CONS(FIT_MTD_ARM_QUEUE, 0, 0);
SKD_WRITEL(skdev, mtd, FIT_MSG_TO_DEVICE);
skdev->last_mtd = mtd;
pr_err("(%s): Time sync driver=0x%x device=0x%x\n",
skd_name(skdev),
skdev->connect_time_stamp, skdev->drive_jiffies);
break;
case FIT_MTD_ARM_QUEUE:
skdev->last_mtd = 0;
break;
default:
break;
}
}
static void skd_disable_interrupts(struct skd_device *skdev)
{
u32 sense;
sense = SKD_READL(skdev, FIT_CONTROL);
sense &= ~FIT_CR_ENABLE_INTERRUPTS;
SKD_WRITEL(skdev, sense, FIT_CONTROL);
pr_debug("%s:%s:%d sense 0x%x\n",
skdev->name, __func__, __LINE__, sense);
SKD_WRITEL(skdev, ~0, FIT_INT_MASK_HOST);
}
static void skd_enable_interrupts(struct skd_device *skdev)
{
u32 val;
val = FIT_ISH_FW_STATE_CHANGE +
FIT_ISH_COMPLETION_POSTED + FIT_ISH_MSG_FROM_DEV;
SKD_WRITEL(skdev, ~val, FIT_INT_MASK_HOST);
pr_debug("%s:%s:%d interrupt mask=0x%x\n",
skdev->name, __func__, __LINE__, ~val);
val = SKD_READL(skdev, FIT_CONTROL);
val |= FIT_CR_ENABLE_INTERRUPTS;
pr_debug("%s:%s:%d control=0x%x\n",
skdev->name, __func__, __LINE__, val);
SKD_WRITEL(skdev, val, FIT_CONTROL);
}
static void skd_soft_reset(struct skd_device *skdev)
{
u32 val;
val = SKD_READL(skdev, FIT_CONTROL);
val |= (FIT_CR_SOFT_RESET);
pr_debug("%s:%s:%d control=0x%x\n",
skdev->name, __func__, __LINE__, val);
SKD_WRITEL(skdev, val, FIT_CONTROL);
}
static void skd_start_device(struct skd_device *skdev)
{
unsigned long flags;
u32 sense;
u32 state;
spin_lock_irqsave(&skdev->lock, flags);
SKD_WRITEL(skdev, FIT_INT_DEF_MASK, FIT_INT_STATUS_HOST);
sense = SKD_READL(skdev, FIT_STATUS);
pr_debug("%s:%s:%d initial status=0x%x\n",
skdev->name, __func__, __LINE__, sense);
state = sense & FIT_SR_DRIVE_STATE_MASK;
skdev->drive_state = state;
skdev->last_mtd = 0;
skdev->state = SKD_DRVR_STATE_STARTING;
skdev->timer_countdown = SKD_STARTING_TIMO;
skd_enable_interrupts(skdev);
switch (skdev->drive_state) {
case FIT_SR_DRIVE_OFFLINE:
pr_err("(%s): Drive offline...\n", skd_name(skdev));
break;
case FIT_SR_DRIVE_FW_BOOTING:
pr_debug("%s:%s:%d FIT_SR_DRIVE_FW_BOOTING %s\n",
skdev->name, __func__, __LINE__, skdev->name);
skdev->state = SKD_DRVR_STATE_WAIT_BOOT;
skdev->timer_countdown = SKD_WAIT_BOOT_TIMO;
break;
case FIT_SR_DRIVE_BUSY_SANITIZE:
pr_info("(%s): Start: BUSY_SANITIZE\n",
skd_name(skdev));
skdev->state = SKD_DRVR_STATE_BUSY_SANITIZE;
skdev->timer_countdown = SKD_STARTED_BUSY_TIMO;
break;
case FIT_SR_DRIVE_BUSY_ERASE:
pr_info("(%s): Start: BUSY_ERASE\n", skd_name(skdev));
skdev->state = SKD_DRVR_STATE_BUSY_ERASE;
skdev->timer_countdown = SKD_STARTED_BUSY_TIMO;
break;
case FIT_SR_DRIVE_INIT:
case FIT_SR_DRIVE_ONLINE:
skd_soft_reset(skdev);
break;
case FIT_SR_DRIVE_BUSY:
pr_err("(%s): Drive Busy...\n", skd_name(skdev));
skdev->state = SKD_DRVR_STATE_BUSY;
skdev->timer_countdown = SKD_STARTED_BUSY_TIMO;
break;
case FIT_SR_DRIVE_SOFT_RESET:
pr_err("(%s) drive soft reset in prog\n",
skd_name(skdev));
break;
case FIT_SR_DRIVE_FAULT:
skd_drive_fault(skdev);
pr_debug("%s:%s:%d starting %s queue\n",
skdev->name, __func__, __LINE__, skdev->name);
blk_start_queue(skdev->queue);
skdev->gendisk_on = -1;
wake_up_interruptible(&skdev->waitq);
break;
case 0xFF:
skd_drive_disappeared(skdev);
pr_debug("%s:%s:%d starting %s queue to error-out reqs\n",
skdev->name, __func__, __LINE__, skdev->name);
blk_start_queue(skdev->queue);
skdev->gendisk_on = -1;
wake_up_interruptible(&skdev->waitq);
break;
default:
pr_err("(%s) Start: unknown state %x\n",
skd_name(skdev), skdev->drive_state);
break;
}
state = SKD_READL(skdev, FIT_CONTROL);
pr_debug("%s:%s:%d FIT Control Status=0x%x\n",
skdev->name, __func__, __LINE__, state);
state = SKD_READL(skdev, FIT_INT_STATUS_HOST);
pr_debug("%s:%s:%d Intr Status=0x%x\n",
skdev->name, __func__, __LINE__, state);
state = SKD_READL(skdev, FIT_INT_MASK_HOST);
pr_debug("%s:%s:%d Intr Mask=0x%x\n",
skdev->name, __func__, __LINE__, state);
state = SKD_READL(skdev, FIT_MSG_FROM_DEVICE);
pr_debug("%s:%s:%d Msg from Dev=0x%x\n",
skdev->name, __func__, __LINE__, state);
state = SKD_READL(skdev, FIT_HW_VERSION);
pr_debug("%s:%s:%d HW version=0x%x\n",
skdev->name, __func__, __LINE__, state);
spin_unlock_irqrestore(&skdev->lock, flags);
}
static void skd_stop_device(struct skd_device *skdev)
{
unsigned long flags;
struct skd_special_context *skspcl = &skdev->internal_skspcl;
u32 dev_state;
int i;
spin_lock_irqsave(&skdev->lock, flags);
if (skdev->state != SKD_DRVR_STATE_ONLINE) {
pr_err("(%s): skd_stop_device not online no sync\n",
skd_name(skdev));
goto stop_out;
}
if (skspcl->req.state != SKD_REQ_STATE_IDLE) {
pr_err("(%s): skd_stop_device no special\n",
skd_name(skdev));
goto stop_out;
}
skdev->state = SKD_DRVR_STATE_SYNCING;
skdev->sync_done = 0;
skd_send_internal_skspcl(skdev, skspcl, SYNCHRONIZE_CACHE);
spin_unlock_irqrestore(&skdev->lock, flags);
wait_event_interruptible_timeout(skdev->waitq,
(skdev->sync_done), (10 * HZ));
spin_lock_irqsave(&skdev->lock, flags);
switch (skdev->sync_done) {
case 0:
pr_err("(%s): skd_stop_device no sync\n",
skd_name(skdev));
break;
case 1:
pr_err("(%s): skd_stop_device sync done\n",
skd_name(skdev));
break;
default:
pr_err("(%s): skd_stop_device sync error\n",
skd_name(skdev));
}
stop_out:
skdev->state = SKD_DRVR_STATE_STOPPING;
spin_unlock_irqrestore(&skdev->lock, flags);
skd_kill_timer(skdev);
spin_lock_irqsave(&skdev->lock, flags);
skd_disable_interrupts(skdev);
SKD_WRITEL(skdev, FIT_INT_DEF_MASK, FIT_INT_STATUS_HOST);
SKD_WRITEL(skdev, FIT_CR_SOFT_RESET, FIT_CONTROL);
spin_unlock_irqrestore(&skdev->lock, flags);
for (i = 0; i < 10; i++) {
dev_state =
SKD_READL(skdev, FIT_STATUS) & FIT_SR_DRIVE_STATE_MASK;
if (dev_state == FIT_SR_DRIVE_INIT)
break;
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(msecs_to_jiffies(100));
}
if (dev_state != FIT_SR_DRIVE_INIT)
pr_err("(%s): skd_stop_device state error 0x%02x\n",
skd_name(skdev), dev_state);
}
static void skd_restart_device(struct skd_device *skdev)
{
u32 state;
SKD_WRITEL(skdev, FIT_INT_DEF_MASK, FIT_INT_STATUS_HOST);
state = SKD_READL(skdev, FIT_STATUS);
pr_debug("%s:%s:%d drive status=0x%x\n",
skdev->name, __func__, __LINE__, state);
state &= FIT_SR_DRIVE_STATE_MASK;
skdev->drive_state = state;
skdev->last_mtd = 0;
skdev->state = SKD_DRVR_STATE_RESTARTING;
skdev->timer_countdown = SKD_RESTARTING_TIMO;
skd_soft_reset(skdev);
}
static int skd_quiesce_dev(struct skd_device *skdev)
{
int rc = 0;
switch (skdev->state) {
case SKD_DRVR_STATE_BUSY:
case SKD_DRVR_STATE_BUSY_IMMINENT:
pr_debug("%s:%s:%d stopping %s queue\n",
skdev->name, __func__, __LINE__, skdev->name);
blk_stop_queue(skdev->queue);
break;
case SKD_DRVR_STATE_ONLINE:
case SKD_DRVR_STATE_STOPPING:
case SKD_DRVR_STATE_SYNCING:
case SKD_DRVR_STATE_PAUSING:
case SKD_DRVR_STATE_PAUSED:
case SKD_DRVR_STATE_STARTING:
case SKD_DRVR_STATE_RESTARTING:
case SKD_DRVR_STATE_RESUMING:
default:
rc = -EINVAL;
pr_debug("%s:%s:%d state [%d] not implemented\n",
skdev->name, __func__, __LINE__, skdev->state);
}
return rc;
}
static int skd_unquiesce_dev(struct skd_device *skdev)
{
int prev_driver_state = skdev->state;
skd_log_skdev(skdev, "unquiesce");
if (skdev->state == SKD_DRVR_STATE_ONLINE) {
pr_debug("%s:%s:%d **** device already ONLINE\n",
skdev->name, __func__, __LINE__);
return 0;
}
if (skdev->drive_state != FIT_SR_DRIVE_ONLINE) {
skdev->state = SKD_DRVR_STATE_BUSY;
pr_debug("%s:%s:%d drive BUSY state\n",
skdev->name, __func__, __LINE__);
return 0;
}
switch (skdev->state) {
case SKD_DRVR_STATE_PAUSED:
case SKD_DRVR_STATE_BUSY:
case SKD_DRVR_STATE_BUSY_IMMINENT:
case SKD_DRVR_STATE_BUSY_ERASE:
case SKD_DRVR_STATE_STARTING:
case SKD_DRVR_STATE_RESTARTING:
case SKD_DRVR_STATE_FAULT:
case SKD_DRVR_STATE_IDLE:
case SKD_DRVR_STATE_LOAD:
skdev->state = SKD_DRVR_STATE_ONLINE;
pr_err("(%s): Driver state %s(%d)=>%s(%d)\n",
skd_name(skdev),
skd_skdev_state_to_str(prev_driver_state),
prev_driver_state, skd_skdev_state_to_str(skdev->state),
skdev->state);
pr_debug("%s:%s:%d **** device ONLINE...starting block queue\n",
skdev->name, __func__, __LINE__);
pr_debug("%s:%s:%d starting %s queue\n",
skdev->name, __func__, __LINE__, skdev->name);
pr_info("(%s): STEC s1120 ONLINE\n", skd_name(skdev));
blk_start_queue(skdev->queue);
skdev->gendisk_on = 1;
wake_up_interruptible(&skdev->waitq);
break;
case SKD_DRVR_STATE_DISAPPEARED:
default:
pr_debug("%s:%s:%d **** driver state %d, not implemented \n",
skdev->name, __func__, __LINE__,
skdev->state);
return -EBUSY;
}
return 0;
}
static irqreturn_t skd_reserved_isr(int irq, void *skd_host_data)
{
struct skd_device *skdev = skd_host_data;
unsigned long flags;
spin_lock_irqsave(&skdev->lock, flags);
pr_debug("%s:%s:%d MSIX = 0x%x\n",
skdev->name, __func__, __LINE__,
SKD_READL(skdev, FIT_INT_STATUS_HOST));
pr_err("(%s): MSIX reserved irq %d = 0x%x\n", skd_name(skdev),
irq, SKD_READL(skdev, FIT_INT_STATUS_HOST));
SKD_WRITEL(skdev, FIT_INT_RESERVED_MASK, FIT_INT_STATUS_HOST);
spin_unlock_irqrestore(&skdev->lock, flags);
return IRQ_HANDLED;
}
static irqreturn_t skd_statec_isr(int irq, void *skd_host_data)
{
struct skd_device *skdev = skd_host_data;
unsigned long flags;
spin_lock_irqsave(&skdev->lock, flags);
pr_debug("%s:%s:%d MSIX = 0x%x\n",
skdev->name, __func__, __LINE__,
SKD_READL(skdev, FIT_INT_STATUS_HOST));
SKD_WRITEL(skdev, FIT_ISH_FW_STATE_CHANGE, FIT_INT_STATUS_HOST);
skd_isr_fwstate(skdev);
spin_unlock_irqrestore(&skdev->lock, flags);
return IRQ_HANDLED;
}
static irqreturn_t skd_comp_q(int irq, void *skd_host_data)
{
struct skd_device *skdev = skd_host_data;
unsigned long flags;
int flush_enqueued = 0;
int deferred;
spin_lock_irqsave(&skdev->lock, flags);
pr_debug("%s:%s:%d MSIX = 0x%x\n",
skdev->name, __func__, __LINE__,
SKD_READL(skdev, FIT_INT_STATUS_HOST));
SKD_WRITEL(skdev, FIT_ISH_COMPLETION_POSTED, FIT_INT_STATUS_HOST);
deferred = skd_isr_completion_posted(skdev, skd_isr_comp_limit,
&flush_enqueued);
if (flush_enqueued)
skd_request_fn(skdev->queue);
if (deferred)
schedule_work(&skdev->completion_worker);
else if (!flush_enqueued)
skd_request_fn(skdev->queue);
spin_unlock_irqrestore(&skdev->lock, flags);
return IRQ_HANDLED;
}
static irqreturn_t skd_msg_isr(int irq, void *skd_host_data)
{
struct skd_device *skdev = skd_host_data;
unsigned long flags;
spin_lock_irqsave(&skdev->lock, flags);
pr_debug("%s:%s:%d MSIX = 0x%x\n",
skdev->name, __func__, __LINE__,
SKD_READL(skdev, FIT_INT_STATUS_HOST));
SKD_WRITEL(skdev, FIT_ISH_MSG_FROM_DEV, FIT_INT_STATUS_HOST);
skd_isr_msg_from_dev(skdev);
spin_unlock_irqrestore(&skdev->lock, flags);
return IRQ_HANDLED;
}
static irqreturn_t skd_qfull_isr(int irq, void *skd_host_data)
{
struct skd_device *skdev = skd_host_data;
unsigned long flags;
spin_lock_irqsave(&skdev->lock, flags);
pr_debug("%s:%s:%d MSIX = 0x%x\n",
skdev->name, __func__, __LINE__,
SKD_READL(skdev, FIT_INT_STATUS_HOST));
SKD_WRITEL(skdev, FIT_INT_QUEUE_FULL, FIT_INT_STATUS_HOST);
spin_unlock_irqrestore(&skdev->lock, flags);
return IRQ_HANDLED;
}
static int skd_acquire_msix(struct skd_device *skdev)
{
int i, rc;
struct pci_dev *pdev = skdev->pdev;
rc = pci_alloc_irq_vectors(pdev, SKD_MAX_MSIX_COUNT, SKD_MAX_MSIX_COUNT,
PCI_IRQ_MSIX);
if (rc < 0) {
pr_err("(%s): failed to enable MSI-X %d\n",
skd_name(skdev), rc);
goto out;
}
skdev->msix_entries = kcalloc(SKD_MAX_MSIX_COUNT,
sizeof(struct skd_msix_entry), GFP_KERNEL);
if (!skdev->msix_entries) {
rc = -ENOMEM;
pr_err("(%s): msix table allocation error\n",
skd_name(skdev));
goto out;
}
for (i = 0; i < SKD_MAX_MSIX_COUNT; i++) {
struct skd_msix_entry *qentry = &skdev->msix_entries[i];
snprintf(qentry->isr_name, sizeof(qentry->isr_name),
"%s%d-msix %s", DRV_NAME, skdev->devno,
msix_entries[i].name);
rc = devm_request_irq(&skdev->pdev->dev,
pci_irq_vector(skdev->pdev, i),
msix_entries[i].handler, 0,
qentry->isr_name, skdev);
if (rc) {
pr_err("(%s): Unable to register(%d) MSI-X "
"handler %d: %s\n",
skd_name(skdev), rc, i, qentry->isr_name);
goto msix_out;
}
}
pr_debug("%s:%s:%d %s: <%s> msix %d irq(s) enabled\n",
skdev->name, __func__, __LINE__,
pci_name(pdev), skdev->name, SKD_MAX_MSIX_COUNT);
return 0;
msix_out:
while (--i >= 0)
devm_free_irq(&pdev->dev, pci_irq_vector(pdev, i), skdev);
out:
kfree(skdev->msix_entries);
skdev->msix_entries = NULL;
return rc;
}
static int skd_acquire_irq(struct skd_device *skdev)
{
struct pci_dev *pdev = skdev->pdev;
unsigned int irq_flag = PCI_IRQ_LEGACY;
int rc;
if (skd_isr_type == SKD_IRQ_MSIX) {
rc = skd_acquire_msix(skdev);
if (!rc)
return 0;
pr_err("(%s): failed to enable MSI-X, re-trying with MSI %d\n",
skd_name(skdev), rc);
}
snprintf(skdev->isr_name, sizeof(skdev->isr_name), "%s%d", DRV_NAME,
skdev->devno);
if (skd_isr_type != SKD_IRQ_LEGACY)
irq_flag |= PCI_IRQ_MSI;
rc = pci_alloc_irq_vectors(pdev, 1, 1, irq_flag);
if (rc < 0) {
pr_err("(%s): failed to allocate the MSI interrupt %d\n",
skd_name(skdev), rc);
return rc;
}
rc = devm_request_irq(&pdev->dev, pdev->irq, skd_isr,
pdev->msi_enabled ? 0 : IRQF_SHARED,
skdev->isr_name, skdev);
if (rc) {
pci_free_irq_vectors(pdev);
pr_err("(%s): failed to allocate interrupt %d\n",
skd_name(skdev), rc);
return rc;
}
return 0;
}
static void skd_release_irq(struct skd_device *skdev)
{
struct pci_dev *pdev = skdev->pdev;
if (skdev->msix_entries) {
int i;
for (i = 0; i < SKD_MAX_MSIX_COUNT; i++) {
devm_free_irq(&pdev->dev, pci_irq_vector(pdev, i),
skdev);
}
kfree(skdev->msix_entries);
skdev->msix_entries = NULL;
} else {
devm_free_irq(&pdev->dev, pdev->irq, skdev);
}
pci_free_irq_vectors(pdev);
}
static int skd_cons_skcomp(struct skd_device *skdev)
{
int rc = 0;
struct fit_completion_entry_v1 *skcomp;
u32 nbytes;
nbytes = sizeof(*skcomp) * SKD_N_COMPLETION_ENTRY;
nbytes += sizeof(struct fit_comp_error_info) * SKD_N_COMPLETION_ENTRY;
pr_debug("%s:%s:%d comp pci_alloc, total bytes %d entries %d\n",
skdev->name, __func__, __LINE__,
nbytes, SKD_N_COMPLETION_ENTRY);
skcomp = pci_zalloc_consistent(skdev->pdev, nbytes,
&skdev->cq_dma_address);
if (skcomp == NULL) {
rc = -ENOMEM;
goto err_out;
}
skdev->skcomp_table = skcomp;
skdev->skerr_table = (struct fit_comp_error_info *)((char *)skcomp +
sizeof(*skcomp) *
SKD_N_COMPLETION_ENTRY);
err_out:
return rc;
}
static int skd_cons_skmsg(struct skd_device *skdev)
{
int rc = 0;
u32 i;
pr_debug("%s:%s:%d skmsg_table kzalloc, struct %lu, count %u total %lu\n",
skdev->name, __func__, __LINE__,
sizeof(struct skd_fitmsg_context),
skdev->num_fitmsg_context,
sizeof(struct skd_fitmsg_context) * skdev->num_fitmsg_context);
skdev->skmsg_table = kzalloc(sizeof(struct skd_fitmsg_context)
*skdev->num_fitmsg_context, GFP_KERNEL);
if (skdev->skmsg_table == NULL) {
rc = -ENOMEM;
goto err_out;
}
for (i = 0; i < skdev->num_fitmsg_context; i++) {
struct skd_fitmsg_context *skmsg;
skmsg = &skdev->skmsg_table[i];
skmsg->id = i + SKD_ID_FIT_MSG;
skmsg->state = SKD_MSG_STATE_IDLE;
skmsg->msg_buf = pci_alloc_consistent(skdev->pdev,
SKD_N_FITMSG_BYTES + 64,
&skmsg->mb_dma_address);
if (skmsg->msg_buf == NULL) {
rc = -ENOMEM;
goto err_out;
}
skmsg->offset = (u32)((u64)skmsg->msg_buf &
(~FIT_QCMD_BASE_ADDRESS_MASK));
skmsg->msg_buf += ~FIT_QCMD_BASE_ADDRESS_MASK;
skmsg->msg_buf = (u8 *)((u64)skmsg->msg_buf &
FIT_QCMD_BASE_ADDRESS_MASK);
skmsg->mb_dma_address += ~FIT_QCMD_BASE_ADDRESS_MASK;
skmsg->mb_dma_address &= FIT_QCMD_BASE_ADDRESS_MASK;
memset(skmsg->msg_buf, 0, SKD_N_FITMSG_BYTES);
skmsg->next = &skmsg[1];
}
skdev->skmsg_table[i - 1].next = NULL;
skdev->skmsg_free_list = skdev->skmsg_table;
err_out:
return rc;
}
static struct fit_sg_descriptor *skd_cons_sg_list(struct skd_device *skdev,
u32 n_sg,
dma_addr_t *ret_dma_addr)
{
struct fit_sg_descriptor *sg_list;
u32 nbytes;
nbytes = sizeof(*sg_list) * n_sg;
sg_list = pci_alloc_consistent(skdev->pdev, nbytes, ret_dma_addr);
if (sg_list != NULL) {
uint64_t dma_address = *ret_dma_addr;
u32 i;
memset(sg_list, 0, nbytes);
for (i = 0; i < n_sg - 1; i++) {
uint64_t ndp_off;
ndp_off = (i + 1) * sizeof(struct fit_sg_descriptor);
sg_list[i].next_desc_ptr = dma_address + ndp_off;
}
sg_list[i].next_desc_ptr = 0LL;
}
return sg_list;
}
static int skd_cons_skreq(struct skd_device *skdev)
{
int rc = 0;
u32 i;
pr_debug("%s:%s:%d skreq_table kzalloc, struct %lu, count %u total %lu\n",
skdev->name, __func__, __LINE__,
sizeof(struct skd_request_context),
skdev->num_req_context,
sizeof(struct skd_request_context) * skdev->num_req_context);
skdev->skreq_table = kzalloc(sizeof(struct skd_request_context)
* skdev->num_req_context, GFP_KERNEL);
if (skdev->skreq_table == NULL) {
rc = -ENOMEM;
goto err_out;
}
pr_debug("%s:%s:%d alloc sg_table sg_per_req %u scatlist %lu total %lu\n",
skdev->name, __func__, __LINE__,
skdev->sgs_per_request, sizeof(struct scatterlist),
skdev->sgs_per_request * sizeof(struct scatterlist));
for (i = 0; i < skdev->num_req_context; i++) {
struct skd_request_context *skreq;
skreq = &skdev->skreq_table[i];
skreq->id = i + SKD_ID_RW_REQUEST;
skreq->state = SKD_REQ_STATE_IDLE;
skreq->sg = kzalloc(sizeof(struct scatterlist) *
skdev->sgs_per_request, GFP_KERNEL);
if (skreq->sg == NULL) {
rc = -ENOMEM;
goto err_out;
}
sg_init_table(skreq->sg, skdev->sgs_per_request);
skreq->sksg_list = skd_cons_sg_list(skdev,
skdev->sgs_per_request,
&skreq->sksg_dma_address);
if (skreq->sksg_list == NULL) {
rc = -ENOMEM;
goto err_out;
}
skreq->next = &skreq[1];
}
skdev->skreq_table[i - 1].next = NULL;
skdev->skreq_free_list = skdev->skreq_table;
err_out:
return rc;
}
static int skd_cons_skspcl(struct skd_device *skdev)
{
int rc = 0;
u32 i, nbytes;
pr_debug("%s:%s:%d skspcl_table kzalloc, struct %lu, count %u total %lu\n",
skdev->name, __func__, __LINE__,
sizeof(struct skd_special_context),
skdev->n_special,
sizeof(struct skd_special_context) * skdev->n_special);
skdev->skspcl_table = kzalloc(sizeof(struct skd_special_context)
* skdev->n_special, GFP_KERNEL);
if (skdev->skspcl_table == NULL) {
rc = -ENOMEM;
goto err_out;
}
for (i = 0; i < skdev->n_special; i++) {
struct skd_special_context *skspcl;
skspcl = &skdev->skspcl_table[i];
skspcl->req.id = i + SKD_ID_SPECIAL_REQUEST;
skspcl->req.state = SKD_REQ_STATE_IDLE;
skspcl->req.next = &skspcl[1].req;
nbytes = SKD_N_SPECIAL_FITMSG_BYTES;
skspcl->msg_buf =
pci_zalloc_consistent(skdev->pdev, nbytes,
&skspcl->mb_dma_address);
if (skspcl->msg_buf == NULL) {
rc = -ENOMEM;
goto err_out;
}
skspcl->req.sg = kzalloc(sizeof(struct scatterlist) *
SKD_N_SG_PER_SPECIAL, GFP_KERNEL);
if (skspcl->req.sg == NULL) {
rc = -ENOMEM;
goto err_out;
}
skspcl->req.sksg_list = skd_cons_sg_list(skdev,
SKD_N_SG_PER_SPECIAL,
&skspcl->req.
sksg_dma_address);
if (skspcl->req.sksg_list == NULL) {
rc = -ENOMEM;
goto err_out;
}
}
skdev->skspcl_table[i - 1].req.next = NULL;
skdev->skspcl_free_list = skdev->skspcl_table;
return rc;
err_out:
return rc;
}
static int skd_cons_sksb(struct skd_device *skdev)
{
int rc = 0;
struct skd_special_context *skspcl;
u32 nbytes;
skspcl = &skdev->internal_skspcl;
skspcl->req.id = 0 + SKD_ID_INTERNAL;
skspcl->req.state = SKD_REQ_STATE_IDLE;
nbytes = SKD_N_INTERNAL_BYTES;
skspcl->data_buf = pci_zalloc_consistent(skdev->pdev, nbytes,
&skspcl->db_dma_address);
if (skspcl->data_buf == NULL) {
rc = -ENOMEM;
goto err_out;
}
nbytes = SKD_N_SPECIAL_FITMSG_BYTES;
skspcl->msg_buf = pci_zalloc_consistent(skdev->pdev, nbytes,
&skspcl->mb_dma_address);
if (skspcl->msg_buf == NULL) {
rc = -ENOMEM;
goto err_out;
}
skspcl->req.sksg_list = skd_cons_sg_list(skdev, 1,
&skspcl->req.sksg_dma_address);
if (skspcl->req.sksg_list == NULL) {
rc = -ENOMEM;
goto err_out;
}
if (!skd_format_internal_skspcl(skdev)) {
rc = -EINVAL;
goto err_out;
}
err_out:
return rc;
}
static int skd_cons_disk(struct skd_device *skdev)
{
int rc = 0;
struct gendisk *disk;
struct request_queue *q;
unsigned long flags;
disk = alloc_disk(SKD_MINORS_PER_DEVICE);
if (!disk) {
rc = -ENOMEM;
goto err_out;
}
skdev->disk = disk;
sprintf(disk->disk_name, DRV_NAME "%u", skdev->devno);
disk->major = skdev->major;
disk->first_minor = skdev->devno * SKD_MINORS_PER_DEVICE;
disk->fops = &skd_blockdev_ops;
disk->private_data = skdev;
q = blk_init_queue(skd_request_fn, &skdev->lock);
if (!q) {
rc = -ENOMEM;
goto err_out;
}
skdev->queue = q;
disk->queue = q;
q->queuedata = skdev;
blk_queue_write_cache(q, true, true);
blk_queue_max_segments(q, skdev->sgs_per_request);
blk_queue_max_hw_sectors(q, SKD_N_MAX_SECTORS);
blk_queue_io_opt(q, 8192);
queue_flag_set_unlocked(QUEUE_FLAG_NONROT, q);
queue_flag_clear_unlocked(QUEUE_FLAG_ADD_RANDOM, q);
spin_lock_irqsave(&skdev->lock, flags);
pr_debug("%s:%s:%d stopping %s queue\n",
skdev->name, __func__, __LINE__, skdev->name);
blk_stop_queue(skdev->queue);
spin_unlock_irqrestore(&skdev->lock, flags);
err_out:
return rc;
}
static struct skd_device *skd_construct(struct pci_dev *pdev)
{
struct skd_device *skdev;
int blk_major = skd_major;
int rc;
skdev = kzalloc(sizeof(*skdev), GFP_KERNEL);
if (!skdev) {
pr_err(PFX "(%s): memory alloc failure\n",
pci_name(pdev));
return NULL;
}
skdev->state = SKD_DRVR_STATE_LOAD;
skdev->pdev = pdev;
skdev->devno = skd_next_devno++;
skdev->major = blk_major;
sprintf(skdev->name, DRV_NAME "%d", skdev->devno);
skdev->dev_max_queue_depth = 0;
skdev->num_req_context = skd_max_queue_depth;
skdev->num_fitmsg_context = skd_max_queue_depth;
skdev->n_special = skd_max_pass_thru;
skdev->cur_max_queue_depth = 1;
skdev->queue_low_water_mark = 1;
skdev->proto_ver = 99;
skdev->sgs_per_request = skd_sgs_per_request;
skdev->dbg_level = skd_dbg_level;
atomic_set(&skdev->device_count, 0);
spin_lock_init(&skdev->lock);
INIT_WORK(&skdev->completion_worker, skd_completion_worker);
pr_debug("%s:%s:%d skcomp\n", skdev->name, __func__, __LINE__);
rc = skd_cons_skcomp(skdev);
if (rc < 0)
goto err_out;
pr_debug("%s:%s:%d skmsg\n", skdev->name, __func__, __LINE__);
rc = skd_cons_skmsg(skdev);
if (rc < 0)
goto err_out;
pr_debug("%s:%s:%d skreq\n", skdev->name, __func__, __LINE__);
rc = skd_cons_skreq(skdev);
if (rc < 0)
goto err_out;
pr_debug("%s:%s:%d skspcl\n", skdev->name, __func__, __LINE__);
rc = skd_cons_skspcl(skdev);
if (rc < 0)
goto err_out;
pr_debug("%s:%s:%d sksb\n", skdev->name, __func__, __LINE__);
rc = skd_cons_sksb(skdev);
if (rc < 0)
goto err_out;
pr_debug("%s:%s:%d disk\n", skdev->name, __func__, __LINE__);
rc = skd_cons_disk(skdev);
if (rc < 0)
goto err_out;
pr_debug("%s:%s:%d VICTORY\n", skdev->name, __func__, __LINE__);
return skdev;
err_out:
pr_debug("%s:%s:%d construct failed\n",
skdev->name, __func__, __LINE__);
skd_destruct(skdev);
return NULL;
}
static void skd_free_skcomp(struct skd_device *skdev)
{
if (skdev->skcomp_table != NULL) {
u32 nbytes;
nbytes = sizeof(skdev->skcomp_table[0]) *
SKD_N_COMPLETION_ENTRY;
pci_free_consistent(skdev->pdev, nbytes,
skdev->skcomp_table, skdev->cq_dma_address);
}
skdev->skcomp_table = NULL;
skdev->cq_dma_address = 0;
}
static void skd_free_skmsg(struct skd_device *skdev)
{
u32 i;
if (skdev->skmsg_table == NULL)
return;
for (i = 0; i < skdev->num_fitmsg_context; i++) {
struct skd_fitmsg_context *skmsg;
skmsg = &skdev->skmsg_table[i];
if (skmsg->msg_buf != NULL) {
skmsg->msg_buf += skmsg->offset;
skmsg->mb_dma_address += skmsg->offset;
pci_free_consistent(skdev->pdev, SKD_N_FITMSG_BYTES,
skmsg->msg_buf,
skmsg->mb_dma_address);
}
skmsg->msg_buf = NULL;
skmsg->mb_dma_address = 0;
}
kfree(skdev->skmsg_table);
skdev->skmsg_table = NULL;
}
static void skd_free_sg_list(struct skd_device *skdev,
struct fit_sg_descriptor *sg_list,
u32 n_sg, dma_addr_t dma_addr)
{
if (sg_list != NULL) {
u32 nbytes;
nbytes = sizeof(*sg_list) * n_sg;
pci_free_consistent(skdev->pdev, nbytes, sg_list, dma_addr);
}
}
static void skd_free_skreq(struct skd_device *skdev)
{
u32 i;
if (skdev->skreq_table == NULL)
return;
for (i = 0; i < skdev->num_req_context; i++) {
struct skd_request_context *skreq;
skreq = &skdev->skreq_table[i];
skd_free_sg_list(skdev, skreq->sksg_list,
skdev->sgs_per_request,
skreq->sksg_dma_address);
skreq->sksg_list = NULL;
skreq->sksg_dma_address = 0;
kfree(skreq->sg);
}
kfree(skdev->skreq_table);
skdev->skreq_table = NULL;
}
static void skd_free_skspcl(struct skd_device *skdev)
{
u32 i;
u32 nbytes;
if (skdev->skspcl_table == NULL)
return;
for (i = 0; i < skdev->n_special; i++) {
struct skd_special_context *skspcl;
skspcl = &skdev->skspcl_table[i];
if (skspcl->msg_buf != NULL) {
nbytes = SKD_N_SPECIAL_FITMSG_BYTES;
pci_free_consistent(skdev->pdev, nbytes,
skspcl->msg_buf,
skspcl->mb_dma_address);
}
skspcl->msg_buf = NULL;
skspcl->mb_dma_address = 0;
skd_free_sg_list(skdev, skspcl->req.sksg_list,
SKD_N_SG_PER_SPECIAL,
skspcl->req.sksg_dma_address);
skspcl->req.sksg_list = NULL;
skspcl->req.sksg_dma_address = 0;
kfree(skspcl->req.sg);
}
kfree(skdev->skspcl_table);
skdev->skspcl_table = NULL;
}
static void skd_free_sksb(struct skd_device *skdev)
{
struct skd_special_context *skspcl;
u32 nbytes;
skspcl = &skdev->internal_skspcl;
if (skspcl->data_buf != NULL) {
nbytes = SKD_N_INTERNAL_BYTES;
pci_free_consistent(skdev->pdev, nbytes,
skspcl->data_buf, skspcl->db_dma_address);
}
skspcl->data_buf = NULL;
skspcl->db_dma_address = 0;
if (skspcl->msg_buf != NULL) {
nbytes = SKD_N_SPECIAL_FITMSG_BYTES;
pci_free_consistent(skdev->pdev, nbytes,
skspcl->msg_buf, skspcl->mb_dma_address);
}
skspcl->msg_buf = NULL;
skspcl->mb_dma_address = 0;
skd_free_sg_list(skdev, skspcl->req.sksg_list, 1,
skspcl->req.sksg_dma_address);
skspcl->req.sksg_list = NULL;
skspcl->req.sksg_dma_address = 0;
}
static void skd_free_disk(struct skd_device *skdev)
{
struct gendisk *disk = skdev->disk;
if (disk != NULL) {
struct request_queue *q = disk->queue;
if (disk->flags & GENHD_FL_UP)
del_gendisk(disk);
if (q)
blk_cleanup_queue(q);
put_disk(disk);
}
skdev->disk = NULL;
}
static void skd_destruct(struct skd_device *skdev)
{
if (skdev == NULL)
return;
pr_debug("%s:%s:%d disk\n", skdev->name, __func__, __LINE__);
skd_free_disk(skdev);
pr_debug("%s:%s:%d sksb\n", skdev->name, __func__, __LINE__);
skd_free_sksb(skdev);
pr_debug("%s:%s:%d skspcl\n", skdev->name, __func__, __LINE__);
skd_free_skspcl(skdev);
pr_debug("%s:%s:%d skreq\n", skdev->name, __func__, __LINE__);
skd_free_skreq(skdev);
pr_debug("%s:%s:%d skmsg\n", skdev->name, __func__, __LINE__);
skd_free_skmsg(skdev);
pr_debug("%s:%s:%d skcomp\n", skdev->name, __func__, __LINE__);
skd_free_skcomp(skdev);
pr_debug("%s:%s:%d skdev\n", skdev->name, __func__, __LINE__);
kfree(skdev);
}
static int skd_bdev_getgeo(struct block_device *bdev, struct hd_geometry *geo)
{
struct skd_device *skdev;
u64 capacity;
skdev = bdev->bd_disk->private_data;
pr_debug("%s:%s:%d %s: CMD[%s] getgeo device\n",
skdev->name, __func__, __LINE__,
bdev->bd_disk->disk_name, current->comm);
if (skdev->read_cap_is_valid) {
capacity = get_capacity(skdev->disk);
geo->heads = 64;
geo->sectors = 255;
geo->cylinders = (capacity) / (255 * 64);
return 0;
}
return -EIO;
}
static int skd_bdev_attach(struct device *parent, struct skd_device *skdev)
{
pr_debug("%s:%s:%d add_disk\n", skdev->name, __func__, __LINE__);
device_add_disk(parent, skdev->disk);
return 0;
}
static char *skd_pci_info(struct skd_device *skdev, char *str)
{
int pcie_reg;
strcpy(str, "PCIe (");
pcie_reg = pci_find_capability(skdev->pdev, PCI_CAP_ID_EXP);
if (pcie_reg) {
char lwstr[6];
uint16_t pcie_lstat, lspeed, lwidth;
pcie_reg += 0x12;
pci_read_config_word(skdev->pdev, pcie_reg, &pcie_lstat);
lspeed = pcie_lstat & (0xF);
lwidth = (pcie_lstat & 0x3F0) >> 4;
if (lspeed == 1)
strcat(str, "2.5GT/s ");
else if (lspeed == 2)
strcat(str, "5.0GT/s ");
else
strcat(str, "<unknown> ");
snprintf(lwstr, sizeof(lwstr), "%dX)", lwidth);
strcat(str, lwstr);
}
return str;
}
static int skd_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int i;
int rc = 0;
char pci_str[32];
struct skd_device *skdev;
pr_info("STEC s1120 Driver(%s) version %s-b%s\n",
DRV_NAME, DRV_VERSION, DRV_BUILD_ID);
pr_info("(skd?:??:[%s]): vendor=%04X device=%04x\n",
pci_name(pdev), pdev->vendor, pdev->device);
rc = pci_enable_device(pdev);
if (rc)
return rc;
rc = pci_request_regions(pdev, DRV_NAME);
if (rc)
goto err_out;
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(64));
if (!rc) {
if (pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64))) {
pr_err("(%s): consistent DMA mask error %d\n",
pci_name(pdev), rc);
}
} else {
(rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(32)));
if (rc) {
pr_err("(%s): DMA mask error %d\n",
pci_name(pdev), rc);
goto err_out_regions;
}
}
if (!skd_major) {
rc = register_blkdev(0, DRV_NAME);
if (rc < 0)
goto err_out_regions;
BUG_ON(!rc);
skd_major = rc;
}
skdev = skd_construct(pdev);
if (skdev == NULL) {
rc = -ENOMEM;
goto err_out_regions;
}
skd_pci_info(skdev, pci_str);
pr_info("(%s): %s 64bit\n", skd_name(skdev), pci_str);
pci_set_master(pdev);
rc = pci_enable_pcie_error_reporting(pdev);
if (rc) {
pr_err(
"(%s): bad enable of PCIe error reporting rc=%d\n",
skd_name(skdev), rc);
skdev->pcie_error_reporting_is_enabled = 0;
} else
skdev->pcie_error_reporting_is_enabled = 1;
pci_set_drvdata(pdev, skdev);
for (i = 0; i < SKD_MAX_BARS; i++) {
skdev->mem_phys[i] = pci_resource_start(pdev, i);
skdev->mem_size[i] = (u32)pci_resource_len(pdev, i);
skdev->mem_map[i] = ioremap(skdev->mem_phys[i],
skdev->mem_size[i]);
if (!skdev->mem_map[i]) {
pr_err("(%s): Unable to map adapter memory!\n",
skd_name(skdev));
rc = -ENODEV;
goto err_out_iounmap;
}
pr_debug("%s:%s:%d mem_map=%p, phyd=%016llx, size=%d\n",
skdev->name, __func__, __LINE__,
skdev->mem_map[i],
(uint64_t)skdev->mem_phys[i], skdev->mem_size[i]);
}
rc = skd_acquire_irq(skdev);
if (rc) {
pr_err("(%s): interrupt resource error %d\n",
skd_name(skdev), rc);
goto err_out_iounmap;
}
rc = skd_start_timer(skdev);
if (rc)
goto err_out_timer;
init_waitqueue_head(&skdev->waitq);
skd_start_device(skdev);
rc = wait_event_interruptible_timeout(skdev->waitq,
(skdev->gendisk_on),
(SKD_START_WAIT_SECONDS * HZ));
if (skdev->gendisk_on > 0) {
skd_bdev_attach(&pdev->dev, skdev);
rc = 0;
} else {
pr_err(
"(%s): error: waiting for s1120 timed out %d!\n",
skd_name(skdev), rc);
if (!rc)
rc = -ENXIO;
goto err_out_timer;
}
#ifdef SKD_VMK_POLL_HANDLER
if (skdev->irq_type == SKD_IRQ_MSIX) {
vmklnx_scsi_register_poll_handler(skdev->scsi_host,
skdev->msix_entries[5].vector,
skd_comp_q, skdev);
} else {
vmklnx_scsi_register_poll_handler(skdev->scsi_host,
skdev->pdev->irq, skd_isr,
skdev);
}
#endif
return rc;
err_out_timer:
skd_stop_device(skdev);
skd_release_irq(skdev);
err_out_iounmap:
for (i = 0; i < SKD_MAX_BARS; i++)
if (skdev->mem_map[i])
iounmap(skdev->mem_map[i]);
if (skdev->pcie_error_reporting_is_enabled)
pci_disable_pcie_error_reporting(pdev);
skd_destruct(skdev);
err_out_regions:
pci_release_regions(pdev);
err_out:
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
return rc;
}
static void skd_pci_remove(struct pci_dev *pdev)
{
int i;
struct skd_device *skdev;
skdev = pci_get_drvdata(pdev);
if (!skdev) {
pr_err("%s: no device data for PCI\n", pci_name(pdev));
return;
}
skd_stop_device(skdev);
skd_release_irq(skdev);
for (i = 0; i < SKD_MAX_BARS; i++)
if (skdev->mem_map[i])
iounmap((u32 *)skdev->mem_map[i]);
if (skdev->pcie_error_reporting_is_enabled)
pci_disable_pcie_error_reporting(pdev);
skd_destruct(skdev);
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
return;
}
static int skd_pci_suspend(struct pci_dev *pdev, pm_message_t state)
{
int i;
struct skd_device *skdev;
skdev = pci_get_drvdata(pdev);
if (!skdev) {
pr_err("%s: no device data for PCI\n", pci_name(pdev));
return -EIO;
}
skd_stop_device(skdev);
skd_release_irq(skdev);
for (i = 0; i < SKD_MAX_BARS; i++)
if (skdev->mem_map[i])
iounmap((u32 *)skdev->mem_map[i]);
if (skdev->pcie_error_reporting_is_enabled)
pci_disable_pcie_error_reporting(pdev);
pci_release_regions(pdev);
pci_save_state(pdev);
pci_disable_device(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int skd_pci_resume(struct pci_dev *pdev)
{
int i;
int rc = 0;
struct skd_device *skdev;
skdev = pci_get_drvdata(pdev);
if (!skdev) {
pr_err("%s: no device data for PCI\n", pci_name(pdev));
return -1;
}
pci_set_power_state(pdev, PCI_D0);
pci_enable_wake(pdev, PCI_D0, 0);
pci_restore_state(pdev);
rc = pci_enable_device(pdev);
if (rc)
return rc;
rc = pci_request_regions(pdev, DRV_NAME);
if (rc)
goto err_out;
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(64));
if (!rc) {
if (pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64))) {
pr_err("(%s): consistent DMA mask error %d\n",
pci_name(pdev), rc);
}
} else {
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc) {
pr_err("(%s): DMA mask error %d\n",
pci_name(pdev), rc);
goto err_out_regions;
}
}
pci_set_master(pdev);
rc = pci_enable_pcie_error_reporting(pdev);
if (rc) {
pr_err("(%s): bad enable of PCIe error reporting rc=%d\n",
skdev->name, rc);
skdev->pcie_error_reporting_is_enabled = 0;
} else
skdev->pcie_error_reporting_is_enabled = 1;
for (i = 0; i < SKD_MAX_BARS; i++) {
skdev->mem_phys[i] = pci_resource_start(pdev, i);
skdev->mem_size[i] = (u32)pci_resource_len(pdev, i);
skdev->mem_map[i] = ioremap(skdev->mem_phys[i],
skdev->mem_size[i]);
if (!skdev->mem_map[i]) {
pr_err("(%s): Unable to map adapter memory!\n",
skd_name(skdev));
rc = -ENODEV;
goto err_out_iounmap;
}
pr_debug("%s:%s:%d mem_map=%p, phyd=%016llx, size=%d\n",
skdev->name, __func__, __LINE__,
skdev->mem_map[i],
(uint64_t)skdev->mem_phys[i], skdev->mem_size[i]);
}
rc = skd_acquire_irq(skdev);
if (rc) {
pr_err("(%s): interrupt resource error %d\n",
pci_name(pdev), rc);
goto err_out_iounmap;
}
rc = skd_start_timer(skdev);
if (rc)
goto err_out_timer;
init_waitqueue_head(&skdev->waitq);
skd_start_device(skdev);
return rc;
err_out_timer:
skd_stop_device(skdev);
skd_release_irq(skdev);
err_out_iounmap:
for (i = 0; i < SKD_MAX_BARS; i++)
if (skdev->mem_map[i])
iounmap(skdev->mem_map[i]);
if (skdev->pcie_error_reporting_is_enabled)
pci_disable_pcie_error_reporting(pdev);
err_out_regions:
pci_release_regions(pdev);
err_out:
pci_disable_device(pdev);
return rc;
}
static void skd_pci_shutdown(struct pci_dev *pdev)
{
struct skd_device *skdev;
pr_err("skd_pci_shutdown called\n");
skdev = pci_get_drvdata(pdev);
if (!skdev) {
pr_err("%s: no device data for PCI\n", pci_name(pdev));
return;
}
pr_err("%s: calling stop\n", skd_name(skdev));
skd_stop_device(skdev);
}
static const char *skd_name(struct skd_device *skdev)
{
memset(skdev->id_str, 0, sizeof(skdev->id_str));
if (skdev->inquiry_is_valid)
snprintf(skdev->id_str, sizeof(skdev->id_str), "%s:%s:[%s]",
skdev->name, skdev->inq_serial_num,
pci_name(skdev->pdev));
else
snprintf(skdev->id_str, sizeof(skdev->id_str), "%s:??:[%s]",
skdev->name, pci_name(skdev->pdev));
return skdev->id_str;
}
const char *skd_drive_state_to_str(int state)
{
switch (state) {
case FIT_SR_DRIVE_OFFLINE:
return "OFFLINE";
case FIT_SR_DRIVE_INIT:
return "INIT";
case FIT_SR_DRIVE_ONLINE:
return "ONLINE";
case FIT_SR_DRIVE_BUSY:
return "BUSY";
case FIT_SR_DRIVE_FAULT:
return "FAULT";
case FIT_SR_DRIVE_DEGRADED:
return "DEGRADED";
case FIT_SR_PCIE_LINK_DOWN:
return "INK_DOWN";
case FIT_SR_DRIVE_SOFT_RESET:
return "SOFT_RESET";
case FIT_SR_DRIVE_NEED_FW_DOWNLOAD:
return "NEED_FW";
case FIT_SR_DRIVE_INIT_FAULT:
return "INIT_FAULT";
case FIT_SR_DRIVE_BUSY_SANITIZE:
return "BUSY_SANITIZE";
case FIT_SR_DRIVE_BUSY_ERASE:
return "BUSY_ERASE";
case FIT_SR_DRIVE_FW_BOOTING:
return "FW_BOOTING";
default:
return "???";
}
}
const char *skd_skdev_state_to_str(enum skd_drvr_state state)
{
switch (state) {
case SKD_DRVR_STATE_LOAD:
return "LOAD";
case SKD_DRVR_STATE_IDLE:
return "IDLE";
case SKD_DRVR_STATE_BUSY:
return "BUSY";
case SKD_DRVR_STATE_STARTING:
return "STARTING";
case SKD_DRVR_STATE_ONLINE:
return "ONLINE";
case SKD_DRVR_STATE_PAUSING:
return "PAUSING";
case SKD_DRVR_STATE_PAUSED:
return "PAUSED";
case SKD_DRVR_STATE_DRAINING_TIMEOUT:
return "DRAINING_TIMEOUT";
case SKD_DRVR_STATE_RESTARTING:
return "RESTARTING";
case SKD_DRVR_STATE_RESUMING:
return "RESUMING";
case SKD_DRVR_STATE_STOPPING:
return "STOPPING";
case SKD_DRVR_STATE_SYNCING:
return "SYNCING";
case SKD_DRVR_STATE_FAULT:
return "FAULT";
case SKD_DRVR_STATE_DISAPPEARED:
return "DISAPPEARED";
case SKD_DRVR_STATE_BUSY_ERASE:
return "BUSY_ERASE";
case SKD_DRVR_STATE_BUSY_SANITIZE:
return "BUSY_SANITIZE";
case SKD_DRVR_STATE_BUSY_IMMINENT:
return "BUSY_IMMINENT";
case SKD_DRVR_STATE_WAIT_BOOT:
return "WAIT_BOOT";
default:
return "???";
}
}
static const char *skd_skmsg_state_to_str(enum skd_fit_msg_state state)
{
switch (state) {
case SKD_MSG_STATE_IDLE:
return "IDLE";
case SKD_MSG_STATE_BUSY:
return "BUSY";
default:
return "???";
}
}
static const char *skd_skreq_state_to_str(enum skd_req_state state)
{
switch (state) {
case SKD_REQ_STATE_IDLE:
return "IDLE";
case SKD_REQ_STATE_SETUP:
return "SETUP";
case SKD_REQ_STATE_BUSY:
return "BUSY";
case SKD_REQ_STATE_COMPLETED:
return "COMPLETED";
case SKD_REQ_STATE_TIMEOUT:
return "TIMEOUT";
case SKD_REQ_STATE_ABORTED:
return "ABORTED";
default:
return "???";
}
}
static void skd_log_skdev(struct skd_device *skdev, const char *event)
{
pr_debug("%s:%s:%d (%s) skdev=%p event='%s'\n",
skdev->name, __func__, __LINE__, skdev->name, skdev, event);
pr_debug("%s:%s:%d drive_state=%s(%d) driver_state=%s(%d)\n",
skdev->name, __func__, __LINE__,
skd_drive_state_to_str(skdev->drive_state), skdev->drive_state,
skd_skdev_state_to_str(skdev->state), skdev->state);
pr_debug("%s:%s:%d busy=%d limit=%d dev=%d lowat=%d\n",
skdev->name, __func__, __LINE__,
skdev->in_flight, skdev->cur_max_queue_depth,
skdev->dev_max_queue_depth, skdev->queue_low_water_mark);
pr_debug("%s:%s:%d timestamp=0x%x cycle=%d cycle_ix=%d\n",
skdev->name, __func__, __LINE__,
skdev->timeout_stamp, skdev->skcomp_cycle, skdev->skcomp_ix);
}
static void skd_log_skmsg(struct skd_device *skdev,
struct skd_fitmsg_context *skmsg, const char *event)
{
pr_debug("%s:%s:%d (%s) skmsg=%p event='%s'\n",
skdev->name, __func__, __LINE__, skdev->name, skmsg, event);
pr_debug("%s:%s:%d state=%s(%d) id=0x%04x length=%d\n",
skdev->name, __func__, __LINE__,
skd_skmsg_state_to_str(skmsg->state), skmsg->state,
skmsg->id, skmsg->length);
}
static void skd_log_skreq(struct skd_device *skdev,
struct skd_request_context *skreq, const char *event)
{
pr_debug("%s:%s:%d (%s) skreq=%p event='%s'\n",
skdev->name, __func__, __LINE__, skdev->name, skreq, event);
pr_debug("%s:%s:%d state=%s(%d) id=0x%04x fitmsg=0x%04x\n",
skdev->name, __func__, __LINE__,
skd_skreq_state_to_str(skreq->state), skreq->state,
skreq->id, skreq->fitmsg_id);
pr_debug("%s:%s:%d timo=0x%x sg_dir=%d n_sg=%d\n",
skdev->name, __func__, __LINE__,
skreq->timeout_stamp, skreq->sg_data_dir, skreq->n_sg);
if (skreq->req != NULL) {
struct request *req = skreq->req;
u32 lba = (u32)blk_rq_pos(req);
u32 count = blk_rq_sectors(req);
pr_debug("%s:%s:%d "
"req=%p lba=%u(0x%x) count=%u(0x%x) dir=%d\n",
skdev->name, __func__, __LINE__,
req, lba, lba, count, count,
(int)rq_data_dir(req));
} else
pr_debug("%s:%s:%d req=NULL\n",
skdev->name, __func__, __LINE__);
}
static int __init skd_init(void)
{
pr_info(PFX " v%s-b%s loaded\n", DRV_VERSION, DRV_BUILD_ID);
switch (skd_isr_type) {
case SKD_IRQ_LEGACY:
case SKD_IRQ_MSI:
case SKD_IRQ_MSIX:
break;
default:
pr_err(PFX "skd_isr_type %d invalid, re-set to %d\n",
skd_isr_type, SKD_IRQ_DEFAULT);
skd_isr_type = SKD_IRQ_DEFAULT;
}
if (skd_max_queue_depth < 1 ||
skd_max_queue_depth > SKD_MAX_QUEUE_DEPTH) {
pr_err(PFX "skd_max_queue_depth %d invalid, re-set to %d\n",
skd_max_queue_depth, SKD_MAX_QUEUE_DEPTH_DEFAULT);
skd_max_queue_depth = SKD_MAX_QUEUE_DEPTH_DEFAULT;
}
if (skd_max_req_per_msg < 1 || skd_max_req_per_msg > 14) {
pr_err(PFX "skd_max_req_per_msg %d invalid, re-set to %d\n",
skd_max_req_per_msg, SKD_MAX_REQ_PER_MSG_DEFAULT);
skd_max_req_per_msg = SKD_MAX_REQ_PER_MSG_DEFAULT;
}
if (skd_sgs_per_request < 1 || skd_sgs_per_request > 4096) {
pr_err(PFX "skd_sg_per_request %d invalid, re-set to %d\n",
skd_sgs_per_request, SKD_N_SG_PER_REQ_DEFAULT);
skd_sgs_per_request = SKD_N_SG_PER_REQ_DEFAULT;
}
if (skd_dbg_level < 0 || skd_dbg_level > 2) {
pr_err(PFX "skd_dbg_level %d invalid, re-set to %d\n",
skd_dbg_level, 0);
skd_dbg_level = 0;
}
if (skd_isr_comp_limit < 0) {
pr_err(PFX "skd_isr_comp_limit %d invalid, set to %d\n",
skd_isr_comp_limit, 0);
skd_isr_comp_limit = 0;
}
if (skd_max_pass_thru < 1 || skd_max_pass_thru > 50) {
pr_err(PFX "skd_max_pass_thru %d invalid, re-set to %d\n",
skd_max_pass_thru, SKD_N_SPECIAL_CONTEXT);
skd_max_pass_thru = SKD_N_SPECIAL_CONTEXT;
}
return pci_register_driver(&skd_driver);
}
static void __exit skd_exit(void)
{
pr_info(PFX " v%s-b%s unloading\n", DRV_VERSION, DRV_BUILD_ID);
pci_unregister_driver(&skd_driver);
if (skd_major)
unregister_blkdev(skd_major, DRV_NAME);
}
