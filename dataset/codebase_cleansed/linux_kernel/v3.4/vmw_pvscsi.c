static struct device *
pvscsi_dev(const struct pvscsi_adapter *adapter)
{
return &(adapter->dev->dev);
}
static struct pvscsi_ctx *
pvscsi_find_context(const struct pvscsi_adapter *adapter, struct scsi_cmnd *cmd)
{
struct pvscsi_ctx *ctx, *end;
end = &adapter->cmd_map[adapter->req_depth];
for (ctx = adapter->cmd_map; ctx < end; ctx++)
if (ctx->cmd == cmd)
return ctx;
return NULL;
}
static struct pvscsi_ctx *
pvscsi_acquire_context(struct pvscsi_adapter *adapter, struct scsi_cmnd *cmd)
{
struct pvscsi_ctx *ctx;
if (list_empty(&adapter->cmd_pool))
return NULL;
ctx = list_first_entry(&adapter->cmd_pool, struct pvscsi_ctx, list);
ctx->cmd = cmd;
list_del(&ctx->list);
return ctx;
}
static void pvscsi_release_context(struct pvscsi_adapter *adapter,
struct pvscsi_ctx *ctx)
{
ctx->cmd = NULL;
list_add(&ctx->list, &adapter->cmd_pool);
}
static u64 pvscsi_map_context(const struct pvscsi_adapter *adapter,
const struct pvscsi_ctx *ctx)
{
return ctx - adapter->cmd_map + 1;
}
static struct pvscsi_ctx *
pvscsi_get_context(const struct pvscsi_adapter *adapter, u64 context)
{
return &adapter->cmd_map[context - 1];
}
static void pvscsi_reg_write(const struct pvscsi_adapter *adapter,
u32 offset, u32 val)
{
writel(val, adapter->mmioBase + offset);
}
static u32 pvscsi_reg_read(const struct pvscsi_adapter *adapter, u32 offset)
{
return readl(adapter->mmioBase + offset);
}
static u32 pvscsi_read_intr_status(const struct pvscsi_adapter *adapter)
{
return pvscsi_reg_read(adapter, PVSCSI_REG_OFFSET_INTR_STATUS);
}
static void pvscsi_write_intr_status(const struct pvscsi_adapter *adapter,
u32 val)
{
pvscsi_reg_write(adapter, PVSCSI_REG_OFFSET_INTR_STATUS, val);
}
static void pvscsi_unmask_intr(const struct pvscsi_adapter *adapter)
{
u32 intr_bits;
intr_bits = PVSCSI_INTR_CMPL_MASK;
if (adapter->use_msg)
intr_bits |= PVSCSI_INTR_MSG_MASK;
pvscsi_reg_write(adapter, PVSCSI_REG_OFFSET_INTR_MASK, intr_bits);
}
static void pvscsi_mask_intr(const struct pvscsi_adapter *adapter)
{
pvscsi_reg_write(adapter, PVSCSI_REG_OFFSET_INTR_MASK, 0);
}
static void pvscsi_write_cmd_desc(const struct pvscsi_adapter *adapter,
u32 cmd, const void *desc, size_t len)
{
const u32 *ptr = desc;
size_t i;
len /= sizeof(*ptr);
pvscsi_reg_write(adapter, PVSCSI_REG_OFFSET_COMMAND, cmd);
for (i = 0; i < len; i++)
pvscsi_reg_write(adapter,
PVSCSI_REG_OFFSET_COMMAND_DATA, ptr[i]);
}
static void pvscsi_abort_cmd(const struct pvscsi_adapter *adapter,
const struct pvscsi_ctx *ctx)
{
struct PVSCSICmdDescAbortCmd cmd = { 0 };
cmd.target = ctx->cmd->device->id;
cmd.context = pvscsi_map_context(adapter, ctx);
pvscsi_write_cmd_desc(adapter, PVSCSI_CMD_ABORT_CMD, &cmd, sizeof(cmd));
}
static void pvscsi_kick_rw_io(const struct pvscsi_adapter *adapter)
{
pvscsi_reg_write(adapter, PVSCSI_REG_OFFSET_KICK_RW_IO, 0);
}
static void pvscsi_process_request_ring(const struct pvscsi_adapter *adapter)
{
pvscsi_reg_write(adapter, PVSCSI_REG_OFFSET_KICK_NON_RW_IO, 0);
}
static int scsi_is_rw(unsigned char op)
{
return op == READ_6 || op == WRITE_6 ||
op == READ_10 || op == WRITE_10 ||
op == READ_12 || op == WRITE_12 ||
op == READ_16 || op == WRITE_16;
}
static void pvscsi_kick_io(const struct pvscsi_adapter *adapter,
unsigned char op)
{
if (scsi_is_rw(op))
pvscsi_kick_rw_io(adapter);
else
pvscsi_process_request_ring(adapter);
}
static void ll_adapter_reset(const struct pvscsi_adapter *adapter)
{
dev_dbg(pvscsi_dev(adapter), "Adapter Reset on %p\n", adapter);
pvscsi_write_cmd_desc(adapter, PVSCSI_CMD_ADAPTER_RESET, NULL, 0);
}
static void ll_bus_reset(const struct pvscsi_adapter *adapter)
{
dev_dbg(pvscsi_dev(adapter), "Reseting bus on %p\n", adapter);
pvscsi_write_cmd_desc(adapter, PVSCSI_CMD_RESET_BUS, NULL, 0);
}
static void ll_device_reset(const struct pvscsi_adapter *adapter, u32 target)
{
struct PVSCSICmdDescResetDevice cmd = { 0 };
dev_dbg(pvscsi_dev(adapter), "Reseting device: target=%u\n", target);
cmd.target = target;
pvscsi_write_cmd_desc(adapter, PVSCSI_CMD_RESET_DEVICE,
&cmd, sizeof(cmd));
}
static void pvscsi_create_sg(struct pvscsi_ctx *ctx,
struct scatterlist *sg, unsigned count)
{
unsigned i;
struct PVSCSISGElement *sge;
BUG_ON(count > PVSCSI_MAX_NUM_SG_ENTRIES_PER_SEGMENT);
sge = &ctx->sgl->sge[0];
for (i = 0; i < count; i++, sg++) {
sge[i].addr = sg_dma_address(sg);
sge[i].length = sg_dma_len(sg);
sge[i].flags = 0;
}
}
static void pvscsi_map_buffers(struct pvscsi_adapter *adapter,
struct pvscsi_ctx *ctx, struct scsi_cmnd *cmd,
struct PVSCSIRingReqDesc *e)
{
unsigned count;
unsigned bufflen = scsi_bufflen(cmd);
struct scatterlist *sg;
e->dataLen = bufflen;
e->dataAddr = 0;
if (bufflen == 0)
return;
sg = scsi_sglist(cmd);
count = scsi_sg_count(cmd);
if (count != 0) {
int segs = scsi_dma_map(cmd);
if (segs > 1) {
pvscsi_create_sg(ctx, sg, segs);
e->flags |= PVSCSI_FLAG_CMD_WITH_SG_LIST;
ctx->sglPA = pci_map_single(adapter->dev, ctx->sgl,
SGL_SIZE, PCI_DMA_TODEVICE);
e->dataAddr = ctx->sglPA;
} else
e->dataAddr = sg_dma_address(sg);
} else {
ctx->dataPA = pci_map_single(adapter->dev, sg, bufflen,
cmd->sc_data_direction);
e->dataAddr = ctx->dataPA;
}
}
static void pvscsi_unmap_buffers(const struct pvscsi_adapter *adapter,
struct pvscsi_ctx *ctx)
{
struct scsi_cmnd *cmd;
unsigned bufflen;
cmd = ctx->cmd;
bufflen = scsi_bufflen(cmd);
if (bufflen != 0) {
unsigned count = scsi_sg_count(cmd);
if (count != 0) {
scsi_dma_unmap(cmd);
if (ctx->sglPA) {
pci_unmap_single(adapter->dev, ctx->sglPA,
SGL_SIZE, PCI_DMA_TODEVICE);
ctx->sglPA = 0;
}
} else
pci_unmap_single(adapter->dev, ctx->dataPA, bufflen,
cmd->sc_data_direction);
}
if (cmd->sense_buffer)
pci_unmap_single(adapter->dev, ctx->sensePA,
SCSI_SENSE_BUFFERSIZE, PCI_DMA_FROMDEVICE);
}
static int __devinit pvscsi_allocate_rings(struct pvscsi_adapter *adapter)
{
adapter->rings_state = pci_alloc_consistent(adapter->dev, PAGE_SIZE,
&adapter->ringStatePA);
if (!adapter->rings_state)
return -ENOMEM;
adapter->req_pages = min(PVSCSI_MAX_NUM_PAGES_REQ_RING,
pvscsi_ring_pages);
adapter->req_depth = adapter->req_pages
* PVSCSI_MAX_NUM_REQ_ENTRIES_PER_PAGE;
adapter->req_ring = pci_alloc_consistent(adapter->dev,
adapter->req_pages * PAGE_SIZE,
&adapter->reqRingPA);
if (!adapter->req_ring)
return -ENOMEM;
adapter->cmp_pages = min(PVSCSI_MAX_NUM_PAGES_CMP_RING,
pvscsi_ring_pages);
adapter->cmp_ring = pci_alloc_consistent(adapter->dev,
adapter->cmp_pages * PAGE_SIZE,
&adapter->cmpRingPA);
if (!adapter->cmp_ring)
return -ENOMEM;
BUG_ON(!IS_ALIGNED(adapter->ringStatePA, PAGE_SIZE));
BUG_ON(!IS_ALIGNED(adapter->reqRingPA, PAGE_SIZE));
BUG_ON(!IS_ALIGNED(adapter->cmpRingPA, PAGE_SIZE));
if (!adapter->use_msg)
return 0;
adapter->msg_pages = min(PVSCSI_MAX_NUM_PAGES_MSG_RING,
pvscsi_msg_ring_pages);
adapter->msg_ring = pci_alloc_consistent(adapter->dev,
adapter->msg_pages * PAGE_SIZE,
&adapter->msgRingPA);
if (!adapter->msg_ring)
return -ENOMEM;
BUG_ON(!IS_ALIGNED(adapter->msgRingPA, PAGE_SIZE));
return 0;
}
static void pvscsi_setup_all_rings(const struct pvscsi_adapter *adapter)
{
struct PVSCSICmdDescSetupRings cmd = { 0 };
dma_addr_t base;
unsigned i;
cmd.ringsStatePPN = adapter->ringStatePA >> PAGE_SHIFT;
cmd.reqRingNumPages = adapter->req_pages;
cmd.cmpRingNumPages = adapter->cmp_pages;
base = adapter->reqRingPA;
for (i = 0; i < adapter->req_pages; i++) {
cmd.reqRingPPNs[i] = base >> PAGE_SHIFT;
base += PAGE_SIZE;
}
base = adapter->cmpRingPA;
for (i = 0; i < adapter->cmp_pages; i++) {
cmd.cmpRingPPNs[i] = base >> PAGE_SHIFT;
base += PAGE_SIZE;
}
memset(adapter->rings_state, 0, PAGE_SIZE);
memset(adapter->req_ring, 0, adapter->req_pages * PAGE_SIZE);
memset(adapter->cmp_ring, 0, adapter->cmp_pages * PAGE_SIZE);
pvscsi_write_cmd_desc(adapter, PVSCSI_CMD_SETUP_RINGS,
&cmd, sizeof(cmd));
if (adapter->use_msg) {
struct PVSCSICmdDescSetupMsgRing cmd_msg = { 0 };
cmd_msg.numPages = adapter->msg_pages;
base = adapter->msgRingPA;
for (i = 0; i < adapter->msg_pages; i++) {
cmd_msg.ringPPNs[i] = base >> PAGE_SHIFT;
base += PAGE_SIZE;
}
memset(adapter->msg_ring, 0, adapter->msg_pages * PAGE_SIZE);
pvscsi_write_cmd_desc(adapter, PVSCSI_CMD_SETUP_MSG_RING,
&cmd_msg, sizeof(cmd_msg));
}
}
static void pvscsi_complete_request(struct pvscsi_adapter *adapter,
const struct PVSCSIRingCmpDesc *e)
{
struct pvscsi_ctx *ctx;
struct scsi_cmnd *cmd;
u32 btstat = e->hostStatus;
u32 sdstat = e->scsiStatus;
ctx = pvscsi_get_context(adapter, e->context);
cmd = ctx->cmd;
pvscsi_unmap_buffers(adapter, ctx);
pvscsi_release_context(adapter, ctx);
cmd->result = 0;
if (sdstat != SAM_STAT_GOOD &&
(btstat == BTSTAT_SUCCESS ||
btstat == BTSTAT_LINKED_COMMAND_COMPLETED ||
btstat == BTSTAT_LINKED_COMMAND_COMPLETED_WITH_FLAG)) {
cmd->result = (DID_OK << 16) | sdstat;
if (sdstat == SAM_STAT_CHECK_CONDITION && cmd->sense_buffer)
cmd->result |= (DRIVER_SENSE << 24);
} else
switch (btstat) {
case BTSTAT_SUCCESS:
case BTSTAT_LINKED_COMMAND_COMPLETED:
case BTSTAT_LINKED_COMMAND_COMPLETED_WITH_FLAG:
cmd->result = (DID_OK << 16);
break;
case BTSTAT_DATARUN:
case BTSTAT_DATA_UNDERRUN:
scsi_set_resid(cmd, scsi_bufflen(cmd) - e->dataLen);
cmd->result = (DID_ERROR << 16);
break;
case BTSTAT_SELTIMEO:
cmd->result = (DID_BAD_TARGET << 16);
break;
case BTSTAT_LUNMISMATCH:
case BTSTAT_TAGREJECT:
case BTSTAT_BADMSG:
cmd->result = (DRIVER_INVALID << 24);
case BTSTAT_HAHARDWARE:
case BTSTAT_INVPHASE:
case BTSTAT_HATIMEOUT:
case BTSTAT_NORESPONSE:
case BTSTAT_DISCONNECT:
case BTSTAT_HASOFTWARE:
case BTSTAT_BUSFREE:
case BTSTAT_SENSFAILED:
cmd->result |= (DID_ERROR << 16);
break;
case BTSTAT_SENTRST:
case BTSTAT_RECVRST:
case BTSTAT_BUSRESET:
cmd->result = (DID_RESET << 16);
break;
case BTSTAT_ABORTQUEUE:
cmd->result = (DID_ABORT << 16);
break;
case BTSTAT_SCSIPARITY:
cmd->result = (DID_PARITY << 16);
break;
default:
cmd->result = (DID_ERROR << 16);
scmd_printk(KERN_DEBUG, cmd,
"Unknown completion status: 0x%x\n",
btstat);
}
dev_dbg(&cmd->device->sdev_gendev,
"cmd=%p %x ctx=%p result=0x%x status=0x%x,%x\n",
cmd, cmd->cmnd[0], ctx, cmd->result, btstat, sdstat);
cmd->scsi_done(cmd);
}
static void pvscsi_process_completion_ring(struct pvscsi_adapter *adapter)
{
struct PVSCSIRingsState *s = adapter->rings_state;
struct PVSCSIRingCmpDesc *ring = adapter->cmp_ring;
u32 cmp_entries = s->cmpNumEntriesLog2;
while (s->cmpConsIdx != s->cmpProdIdx) {
struct PVSCSIRingCmpDesc *e = ring + (s->cmpConsIdx &
MASK(cmp_entries));
barrier();
pvscsi_complete_request(adapter, e);
barrier();
s->cmpConsIdx++;
}
}
static int pvscsi_queue_ring(struct pvscsi_adapter *adapter,
struct pvscsi_ctx *ctx, struct scsi_cmnd *cmd)
{
struct PVSCSIRingsState *s;
struct PVSCSIRingReqDesc *e;
struct scsi_device *sdev;
u32 req_entries;
s = adapter->rings_state;
sdev = cmd->device;
req_entries = s->reqNumEntriesLog2;
if (s->reqProdIdx - s->cmpConsIdx >= 1 << req_entries) {
scmd_printk(KERN_ERR, cmd, "vmw_pvscsi: "
"ring full: reqProdIdx=%d cmpConsIdx=%d\n",
s->reqProdIdx, s->cmpConsIdx);
return -1;
}
e = adapter->req_ring + (s->reqProdIdx & MASK(req_entries));
e->bus = sdev->channel;
e->target = sdev->id;
memset(e->lun, 0, sizeof(e->lun));
e->lun[1] = sdev->lun;
if (cmd->sense_buffer) {
ctx->sensePA = pci_map_single(adapter->dev, cmd->sense_buffer,
SCSI_SENSE_BUFFERSIZE,
PCI_DMA_FROMDEVICE);
e->senseAddr = ctx->sensePA;
e->senseLen = SCSI_SENSE_BUFFERSIZE;
} else {
e->senseLen = 0;
e->senseAddr = 0;
}
e->cdbLen = cmd->cmd_len;
e->vcpuHint = smp_processor_id();
memcpy(e->cdb, cmd->cmnd, e->cdbLen);
e->tag = SIMPLE_QUEUE_TAG;
if (sdev->tagged_supported &&
(cmd->tag == HEAD_OF_QUEUE_TAG ||
cmd->tag == ORDERED_QUEUE_TAG))
e->tag = cmd->tag;
if (cmd->sc_data_direction == DMA_FROM_DEVICE)
e->flags = PVSCSI_FLAG_CMD_DIR_TOHOST;
else if (cmd->sc_data_direction == DMA_TO_DEVICE)
e->flags = PVSCSI_FLAG_CMD_DIR_TODEVICE;
else if (cmd->sc_data_direction == DMA_NONE)
e->flags = PVSCSI_FLAG_CMD_DIR_NONE;
else
e->flags = 0;
pvscsi_map_buffers(adapter, ctx, cmd, e);
e->context = pvscsi_map_context(adapter, ctx);
barrier();
s->reqProdIdx++;
return 0;
}
static int pvscsi_queue_lck(struct scsi_cmnd *cmd, void (*done)(struct scsi_cmnd *))
{
struct Scsi_Host *host = cmd->device->host;
struct pvscsi_adapter *adapter = shost_priv(host);
struct pvscsi_ctx *ctx;
unsigned long flags;
spin_lock_irqsave(&adapter->hw_lock, flags);
ctx = pvscsi_acquire_context(adapter, cmd);
if (!ctx || pvscsi_queue_ring(adapter, ctx, cmd) != 0) {
if (ctx)
pvscsi_release_context(adapter, ctx);
spin_unlock_irqrestore(&adapter->hw_lock, flags);
return SCSI_MLQUEUE_HOST_BUSY;
}
cmd->scsi_done = done;
dev_dbg(&cmd->device->sdev_gendev,
"queued cmd %p, ctx %p, op=%x\n", cmd, ctx, cmd->cmnd[0]);
spin_unlock_irqrestore(&adapter->hw_lock, flags);
pvscsi_kick_io(adapter, cmd->cmnd[0]);
return 0;
}
void pvscsi_reset_all(struct pvscsi_adapter *adapter)
{
unsigned i;
for (i = 0; i < adapter->req_depth; i++) {
struct pvscsi_ctx *ctx = &adapter->cmd_map[i];
struct scsi_cmnd *cmd = ctx->cmd;
if (cmd) {
scmd_printk(KERN_ERR, cmd,
"Forced reset on cmd %p\n", cmd);
pvscsi_unmap_buffers(adapter, ctx);
pvscsi_release_context(adapter, ctx);
cmd->result = (DID_RESET << 16);
cmd->scsi_done(cmd);
}
}
}
static int pvscsi_host_reset(struct scsi_cmnd *cmd)
{
struct Scsi_Host *host = cmd->device->host;
struct pvscsi_adapter *adapter = shost_priv(host);
unsigned long flags;
bool use_msg;
scmd_printk(KERN_INFO, cmd, "SCSI Host reset\n");
spin_lock_irqsave(&adapter->hw_lock, flags);
use_msg = adapter->use_msg;
if (use_msg) {
adapter->use_msg = 0;
spin_unlock_irqrestore(&adapter->hw_lock, flags);
flush_workqueue(adapter->workqueue);
spin_lock_irqsave(&adapter->hw_lock, flags);
}
pvscsi_process_request_ring(adapter);
ll_adapter_reset(adapter);
pvscsi_process_completion_ring(adapter);
pvscsi_reset_all(adapter);
adapter->use_msg = use_msg;
pvscsi_setup_all_rings(adapter);
pvscsi_unmask_intr(adapter);
spin_unlock_irqrestore(&adapter->hw_lock, flags);
return SUCCESS;
}
static int pvscsi_bus_reset(struct scsi_cmnd *cmd)
{
struct Scsi_Host *host = cmd->device->host;
struct pvscsi_adapter *adapter = shost_priv(host);
unsigned long flags;
scmd_printk(KERN_INFO, cmd, "SCSI Bus reset\n");
spin_lock_irqsave(&adapter->hw_lock, flags);
pvscsi_process_request_ring(adapter);
ll_bus_reset(adapter);
pvscsi_process_completion_ring(adapter);
spin_unlock_irqrestore(&adapter->hw_lock, flags);
return SUCCESS;
}
static int pvscsi_device_reset(struct scsi_cmnd *cmd)
{
struct Scsi_Host *host = cmd->device->host;
struct pvscsi_adapter *adapter = shost_priv(host);
unsigned long flags;
scmd_printk(KERN_INFO, cmd, "SCSI device reset on scsi%u:%u\n",
host->host_no, cmd->device->id);
spin_lock_irqsave(&adapter->hw_lock, flags);
pvscsi_process_request_ring(adapter);
ll_device_reset(adapter, cmd->device->id);
pvscsi_process_completion_ring(adapter);
spin_unlock_irqrestore(&adapter->hw_lock, flags);
return SUCCESS;
}
static const char *pvscsi_info(struct Scsi_Host *host)
{
struct pvscsi_adapter *adapter = shost_priv(host);
static char buf[256];
sprintf(buf, "VMware PVSCSI storage adapter rev %d, req/cmp/msg rings: "
"%u/%u/%u pages, cmd_per_lun=%u", adapter->rev,
adapter->req_pages, adapter->cmp_pages, adapter->msg_pages,
pvscsi_template.cmd_per_lun);
return buf;
}
static void pvscsi_process_msg(const struct pvscsi_adapter *adapter,
const struct PVSCSIRingMsgDesc *e)
{
struct PVSCSIRingsState *s = adapter->rings_state;
struct Scsi_Host *host = adapter->host;
struct scsi_device *sdev;
printk(KERN_INFO "vmw_pvscsi: msg type: 0x%x - MSG RING: %u/%u (%u) \n",
e->type, s->msgProdIdx, s->msgConsIdx, s->msgNumEntriesLog2);
BUILD_BUG_ON(PVSCSI_MSG_LAST != 2);
if (e->type == PVSCSI_MSG_DEV_ADDED) {
struct PVSCSIMsgDescDevStatusChanged *desc;
desc = (struct PVSCSIMsgDescDevStatusChanged *)e;
printk(KERN_INFO
"vmw_pvscsi: msg: device added at scsi%u:%u:%u\n",
desc->bus, desc->target, desc->lun[1]);
if (!scsi_host_get(host))
return;
sdev = scsi_device_lookup(host, desc->bus, desc->target,
desc->lun[1]);
if (sdev) {
printk(KERN_INFO "vmw_pvscsi: device already exists\n");
scsi_device_put(sdev);
} else
scsi_add_device(adapter->host, desc->bus,
desc->target, desc->lun[1]);
scsi_host_put(host);
} else if (e->type == PVSCSI_MSG_DEV_REMOVED) {
struct PVSCSIMsgDescDevStatusChanged *desc;
desc = (struct PVSCSIMsgDescDevStatusChanged *)e;
printk(KERN_INFO
"vmw_pvscsi: msg: device removed at scsi%u:%u:%u\n",
desc->bus, desc->target, desc->lun[1]);
if (!scsi_host_get(host))
return;
sdev = scsi_device_lookup(host, desc->bus, desc->target,
desc->lun[1]);
if (sdev) {
scsi_remove_device(sdev);
scsi_device_put(sdev);
} else
printk(KERN_INFO
"vmw_pvscsi: failed to lookup scsi%u:%u:%u\n",
desc->bus, desc->target, desc->lun[1]);
scsi_host_put(host);
}
}
static int pvscsi_msg_pending(const struct pvscsi_adapter *adapter)
{
struct PVSCSIRingsState *s = adapter->rings_state;
return s->msgProdIdx != s->msgConsIdx;
}
static void pvscsi_process_msg_ring(const struct pvscsi_adapter *adapter)
{
struct PVSCSIRingsState *s = adapter->rings_state;
struct PVSCSIRingMsgDesc *ring = adapter->msg_ring;
u32 msg_entries = s->msgNumEntriesLog2;
while (pvscsi_msg_pending(adapter)) {
struct PVSCSIRingMsgDesc *e = ring + (s->msgConsIdx &
MASK(msg_entries));
barrier();
pvscsi_process_msg(adapter, e);
barrier();
s->msgConsIdx++;
}
}
static void pvscsi_msg_workqueue_handler(struct work_struct *data)
{
struct pvscsi_adapter *adapter;
adapter = container_of(data, struct pvscsi_adapter, work);
pvscsi_process_msg_ring(adapter);
}
static int pvscsi_setup_msg_workqueue(struct pvscsi_adapter *adapter)
{
char name[32];
if (!pvscsi_use_msg)
return 0;
pvscsi_reg_write(adapter, PVSCSI_REG_OFFSET_COMMAND,
PVSCSI_CMD_SETUP_MSG_RING);
if (pvscsi_reg_read(adapter, PVSCSI_REG_OFFSET_COMMAND_STATUS) == -1)
return 0;
snprintf(name, sizeof(name),
"vmw_pvscsi_wq_%u", adapter->host->host_no);
adapter->workqueue = create_singlethread_workqueue(name);
if (!adapter->workqueue) {
printk(KERN_ERR "vmw_pvscsi: failed to create work queue\n");
return 0;
}
INIT_WORK(&adapter->work, pvscsi_msg_workqueue_handler);
return 1;
}
static irqreturn_t pvscsi_isr(int irq, void *devp)
{
struct pvscsi_adapter *adapter = devp;
int handled;
if (adapter->use_msi || adapter->use_msix)
handled = true;
else {
u32 val = pvscsi_read_intr_status(adapter);
handled = (val & PVSCSI_INTR_ALL_SUPPORTED) != 0;
if (handled)
pvscsi_write_intr_status(devp, val);
}
if (handled) {
unsigned long flags;
spin_lock_irqsave(&adapter->hw_lock, flags);
pvscsi_process_completion_ring(adapter);
if (adapter->use_msg && pvscsi_msg_pending(adapter))
queue_work(adapter->workqueue, &adapter->work);
spin_unlock_irqrestore(&adapter->hw_lock, flags);
}
return IRQ_RETVAL(handled);
}
static void pvscsi_free_sgls(const struct pvscsi_adapter *adapter)
{
struct pvscsi_ctx *ctx = adapter->cmd_map;
unsigned i;
for (i = 0; i < adapter->req_depth; ++i, ++ctx)
free_pages((unsigned long)ctx->sgl, get_order(SGL_SIZE));
}
static int pvscsi_setup_msix(const struct pvscsi_adapter *adapter,
unsigned int *irq)
{
struct msix_entry entry = { 0, PVSCSI_VECTOR_COMPLETION };
int ret;
ret = pci_enable_msix(adapter->dev, &entry, 1);
if (ret)
return ret;
*irq = entry.vector;
return 0;
}
static void pvscsi_shutdown_intr(struct pvscsi_adapter *adapter)
{
if (adapter->irq) {
free_irq(adapter->irq, adapter);
adapter->irq = 0;
}
if (adapter->use_msi) {
pci_disable_msi(adapter->dev);
adapter->use_msi = 0;
} else if (adapter->use_msix) {
pci_disable_msix(adapter->dev);
adapter->use_msix = 0;
}
}
static void pvscsi_release_resources(struct pvscsi_adapter *adapter)
{
pvscsi_shutdown_intr(adapter);
if (adapter->workqueue)
destroy_workqueue(adapter->workqueue);
if (adapter->mmioBase)
pci_iounmap(adapter->dev, adapter->mmioBase);
pci_release_regions(adapter->dev);
if (adapter->cmd_map) {
pvscsi_free_sgls(adapter);
kfree(adapter->cmd_map);
}
if (adapter->rings_state)
pci_free_consistent(adapter->dev, PAGE_SIZE,
adapter->rings_state, adapter->ringStatePA);
if (adapter->req_ring)
pci_free_consistent(adapter->dev,
adapter->req_pages * PAGE_SIZE,
adapter->req_ring, adapter->reqRingPA);
if (adapter->cmp_ring)
pci_free_consistent(adapter->dev,
adapter->cmp_pages * PAGE_SIZE,
adapter->cmp_ring, adapter->cmpRingPA);
if (adapter->msg_ring)
pci_free_consistent(adapter->dev,
adapter->msg_pages * PAGE_SIZE,
adapter->msg_ring, adapter->msgRingPA);
}
static int __devinit pvscsi_allocate_sg(struct pvscsi_adapter *adapter)
{
struct pvscsi_ctx *ctx;
int i;
ctx = adapter->cmd_map;
BUILD_BUG_ON(sizeof(struct pvscsi_sg_list) > SGL_SIZE);
for (i = 0; i < adapter->req_depth; ++i, ++ctx) {
ctx->sgl = (void *)__get_free_pages(GFP_KERNEL,
get_order(SGL_SIZE));
ctx->sglPA = 0;
BUG_ON(!IS_ALIGNED(((unsigned long)ctx->sgl), PAGE_SIZE));
if (!ctx->sgl) {
for (; i >= 0; --i, --ctx) {
free_pages((unsigned long)ctx->sgl,
get_order(SGL_SIZE));
ctx->sgl = NULL;
}
return -ENOMEM;
}
}
return 0;
}
static u32 pvscsi_get_max_targets(struct pvscsi_adapter *adapter)
{
struct PVSCSICmdDescConfigCmd cmd;
struct PVSCSIConfigPageHeader *header;
struct device *dev;
dma_addr_t configPagePA;
void *config_page;
u32 numPhys = 16;
dev = pvscsi_dev(adapter);
config_page = pci_alloc_consistent(adapter->dev, PAGE_SIZE,
&configPagePA);
if (!config_page) {
dev_warn(dev, "vmw_pvscsi: failed to allocate memory for config page\n");
goto exit;
}
BUG_ON(configPagePA & ~PAGE_MASK);
cmd.configPageAddress = ((u64)PVSCSI_CONFIG_CONTROLLER_ADDRESS) << 32;
cmd.configPageNum = PVSCSI_CONFIG_PAGE_CONTROLLER;
cmd.cmpAddr = configPagePA;
cmd._pad = 0;
header = config_page;
memset(header, 0, sizeof *header);
header->hostStatus = BTSTAT_INVPARAM;
header->scsiStatus = SDSTAT_CHECK;
pvscsi_write_cmd_desc(adapter, PVSCSI_CMD_CONFIG, &cmd, sizeof cmd);
if (header->hostStatus == BTSTAT_SUCCESS &&
header->scsiStatus == SDSTAT_GOOD) {
struct PVSCSIConfigPageController *config;
config = config_page;
numPhys = config->numPhys;
} else
dev_warn(dev, "vmw_pvscsi: PVSCSI_CMD_CONFIG failed. hostStatus = 0x%x, scsiStatus = 0x%x\n",
header->hostStatus, header->scsiStatus);
pci_free_consistent(adapter->dev, PAGE_SIZE, config_page, configPagePA);
exit:
return numPhys;
}
static int __devinit pvscsi_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct pvscsi_adapter *adapter;
struct Scsi_Host *host;
struct device *dev;
unsigned int i;
unsigned long flags = 0;
int error;
error = -ENODEV;
if (pci_enable_device(pdev))
return error;
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(64)) == 0 &&
pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64)) == 0) {
printk(KERN_INFO "vmw_pvscsi: using 64bit dma\n");
} else if (pci_set_dma_mask(pdev, DMA_BIT_MASK(32)) == 0 &&
pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32)) == 0) {
printk(KERN_INFO "vmw_pvscsi: using 32bit dma\n");
} else {
printk(KERN_ERR "vmw_pvscsi: failed to set DMA mask\n");
goto out_disable_device;
}
pvscsi_template.can_queue =
min(PVSCSI_MAX_NUM_PAGES_REQ_RING, pvscsi_ring_pages) *
PVSCSI_MAX_NUM_REQ_ENTRIES_PER_PAGE;
pvscsi_template.cmd_per_lun =
min(pvscsi_template.can_queue, pvscsi_cmd_per_lun);
host = scsi_host_alloc(&pvscsi_template, sizeof(struct pvscsi_adapter));
if (!host) {
printk(KERN_ERR "vmw_pvscsi: failed to allocate host\n");
goto out_disable_device;
}
adapter = shost_priv(host);
memset(adapter, 0, sizeof(*adapter));
adapter->dev = pdev;
adapter->host = host;
spin_lock_init(&adapter->hw_lock);
host->max_channel = 0;
host->max_id = 16;
host->max_lun = 1;
host->max_cmd_len = 16;
adapter->rev = pdev->revision;
if (pci_request_regions(pdev, "vmw_pvscsi")) {
printk(KERN_ERR "vmw_pvscsi: pci memory selection failed\n");
goto out_free_host;
}
for (i = 0; i < DEVICE_COUNT_RESOURCE; i++) {
if ((pci_resource_flags(pdev, i) & PCI_BASE_ADDRESS_SPACE_IO))
continue;
if (pci_resource_len(pdev, i) < PVSCSI_MEM_SPACE_SIZE)
continue;
break;
}
if (i == DEVICE_COUNT_RESOURCE) {
printk(KERN_ERR
"vmw_pvscsi: adapter has no suitable MMIO region\n");
goto out_release_resources;
}
adapter->mmioBase = pci_iomap(pdev, i, PVSCSI_MEM_SPACE_SIZE);
if (!adapter->mmioBase) {
printk(KERN_ERR
"vmw_pvscsi: can't iomap for BAR %d memsize %lu\n",
i, PVSCSI_MEM_SPACE_SIZE);
goto out_release_resources;
}
pci_set_master(pdev);
pci_set_drvdata(pdev, host);
ll_adapter_reset(adapter);
adapter->use_msg = pvscsi_setup_msg_workqueue(adapter);
error = pvscsi_allocate_rings(adapter);
if (error) {
printk(KERN_ERR "vmw_pvscsi: unable to allocate ring memory\n");
goto out_release_resources;
}
host->max_id = pvscsi_get_max_targets(adapter);
dev = pvscsi_dev(adapter);
dev_info(dev, "vmw_pvscsi: host->max_id: %u\n", host->max_id);
pvscsi_setup_all_rings(adapter);
adapter->cmd_map = kcalloc(adapter->req_depth,
sizeof(struct pvscsi_ctx), GFP_KERNEL);
if (!adapter->cmd_map) {
printk(KERN_ERR "vmw_pvscsi: failed to allocate memory.\n");
error = -ENOMEM;
goto out_reset_adapter;
}
INIT_LIST_HEAD(&adapter->cmd_pool);
for (i = 0; i < adapter->req_depth; i++) {
struct pvscsi_ctx *ctx = adapter->cmd_map + i;
list_add(&ctx->list, &adapter->cmd_pool);
}
error = pvscsi_allocate_sg(adapter);
if (error) {
printk(KERN_ERR "vmw_pvscsi: unable to allocate s/g table\n");
goto out_reset_adapter;
}
if (!pvscsi_disable_msix &&
pvscsi_setup_msix(adapter, &adapter->irq) == 0) {
printk(KERN_INFO "vmw_pvscsi: using MSI-X\n");
adapter->use_msix = 1;
} else if (!pvscsi_disable_msi && pci_enable_msi(pdev) == 0) {
printk(KERN_INFO "vmw_pvscsi: using MSI\n");
adapter->use_msi = 1;
adapter->irq = pdev->irq;
} else {
printk(KERN_INFO "vmw_pvscsi: using INTx\n");
adapter->irq = pdev->irq;
flags = IRQF_SHARED;
}
error = request_irq(adapter->irq, pvscsi_isr, flags,
"vmw_pvscsi", adapter);
if (error) {
printk(KERN_ERR
"vmw_pvscsi: unable to request IRQ: %d\n", error);
adapter->irq = 0;
goto out_reset_adapter;
}
error = scsi_add_host(host, &pdev->dev);
if (error) {
printk(KERN_ERR
"vmw_pvscsi: scsi_add_host failed: %d\n", error);
goto out_reset_adapter;
}
dev_info(&pdev->dev, "VMware PVSCSI rev %d host #%u\n",
adapter->rev, host->host_no);
pvscsi_unmask_intr(adapter);
scsi_scan_host(host);
return 0;
out_reset_adapter:
ll_adapter_reset(adapter);
out_release_resources:
pvscsi_release_resources(adapter);
out_free_host:
scsi_host_put(host);
out_disable_device:
pci_set_drvdata(pdev, NULL);
pci_disable_device(pdev);
return error;
}
static void __pvscsi_shutdown(struct pvscsi_adapter *adapter)
{
pvscsi_mask_intr(adapter);
if (adapter->workqueue)
flush_workqueue(adapter->workqueue);
pvscsi_shutdown_intr(adapter);
pvscsi_process_request_ring(adapter);
pvscsi_process_completion_ring(adapter);
ll_adapter_reset(adapter);
}
static void pvscsi_shutdown(struct pci_dev *dev)
{
struct Scsi_Host *host = pci_get_drvdata(dev);
struct pvscsi_adapter *adapter = shost_priv(host);
__pvscsi_shutdown(adapter);
}
static void pvscsi_remove(struct pci_dev *pdev)
{
struct Scsi_Host *host = pci_get_drvdata(pdev);
struct pvscsi_adapter *adapter = shost_priv(host);
scsi_remove_host(host);
__pvscsi_shutdown(adapter);
pvscsi_release_resources(adapter);
scsi_host_put(host);
pci_set_drvdata(pdev, NULL);
pci_disable_device(pdev);
}
static int __init pvscsi_init(void)
{
pr_info("%s - version %s\n",
PVSCSI_LINUX_DRIVER_DESC, PVSCSI_DRIVER_VERSION_STRING);
return pci_register_driver(&pvscsi_pci_driver);
}
static void __exit pvscsi_exit(void)
{
pci_unregister_driver(&pvscsi_pci_driver);
}
