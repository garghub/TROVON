static int iop_wait_ready_itl(struct hptiop_hba *hba, u32 millisec)
{
u32 req = 0;
int i;
for (i = 0; i < millisec; i++) {
req = readl(&hba->u.itl.iop->inbound_queue);
if (req != IOPMU_QUEUE_EMPTY)
break;
msleep(1);
}
if (req != IOPMU_QUEUE_EMPTY) {
writel(req, &hba->u.itl.iop->outbound_queue);
readl(&hba->u.itl.iop->outbound_intstatus);
return 0;
}
return -1;
}
static int iop_wait_ready_mv(struct hptiop_hba *hba, u32 millisec)
{
return iop_send_sync_msg(hba, IOPMU_INBOUND_MSG0_NOP, millisec);
}
static void hptiop_request_callback_itl(struct hptiop_hba *hba, u32 tag)
{
if (tag & IOPMU_QUEUE_ADDR_HOST_BIT)
hptiop_host_request_callback_itl(hba,
tag & ~IOPMU_QUEUE_ADDR_HOST_BIT);
else
hptiop_iop_request_callback_itl(hba, tag);
}
static void hptiop_drain_outbound_queue_itl(struct hptiop_hba *hba)
{
u32 req;
while ((req = readl(&hba->u.itl.iop->outbound_queue)) !=
IOPMU_QUEUE_EMPTY) {
if (req & IOPMU_QUEUE_MASK_HOST_BITS)
hptiop_request_callback_itl(hba, req);
else {
struct hpt_iop_request_header __iomem * p;
p = (struct hpt_iop_request_header __iomem *)
((char __iomem *)hba->u.itl.iop + req);
if (readl(&p->flags) & IOP_REQUEST_FLAG_SYNC_REQUEST) {
if (readl(&p->context))
hptiop_request_callback_itl(hba, req);
else
writel(1, &p->context);
}
else
hptiop_request_callback_itl(hba, req);
}
}
}
static int iop_intr_itl(struct hptiop_hba *hba)
{
struct hpt_iopmu_itl __iomem *iop = hba->u.itl.iop;
void __iomem *plx = hba->u.itl.plx;
u32 status;
int ret = 0;
if (plx && readl(plx + 0x11C5C) & 0xf)
writel(1, plx + 0x11C60);
status = readl(&iop->outbound_intstatus);
if (status & IOPMU_OUTBOUND_INT_MSG0) {
u32 msg = readl(&iop->outbound_msgaddr0);
dprintk("received outbound msg %x\n", msg);
writel(IOPMU_OUTBOUND_INT_MSG0, &iop->outbound_intstatus);
hptiop_message_callback(hba, msg);
ret = 1;
}
if (status & IOPMU_OUTBOUND_INT_POSTQUEUE) {
hptiop_drain_outbound_queue_itl(hba);
ret = 1;
}
return ret;
}
static u64 mv_outbound_read(struct hpt_iopmu_mv __iomem *mu)
{
u32 outbound_tail = readl(&mu->outbound_tail);
u32 outbound_head = readl(&mu->outbound_head);
if (outbound_tail != outbound_head) {
u64 p;
memcpy_fromio(&p, &mu->outbound_q[mu->outbound_tail], 8);
outbound_tail++;
if (outbound_tail == MVIOP_QUEUE_LEN)
outbound_tail = 0;
writel(outbound_tail, &mu->outbound_tail);
return p;
} else
return 0;
}
static void mv_inbound_write(u64 p, struct hptiop_hba *hba)
{
u32 inbound_head = readl(&hba->u.mv.mu->inbound_head);
u32 head = inbound_head + 1;
if (head == MVIOP_QUEUE_LEN)
head = 0;
memcpy_toio(&hba->u.mv.mu->inbound_q[inbound_head], &p, 8);
writel(head, &hba->u.mv.mu->inbound_head);
writel(MVIOP_MU_INBOUND_INT_POSTQUEUE,
&hba->u.mv.regs->inbound_doorbell);
}
static void hptiop_request_callback_mv(struct hptiop_hba *hba, u64 tag)
{
u32 req_type = (tag >> 5) & 0x7;
struct hpt_iop_request_scsi_command *req;
dprintk("hptiop_request_callback_mv: tag=%llx\n", tag);
BUG_ON((tag & MVIOP_MU_QUEUE_REQUEST_RETURN_CONTEXT) == 0);
switch (req_type) {
case IOP_REQUEST_TYPE_GET_CONFIG:
case IOP_REQUEST_TYPE_SET_CONFIG:
hba->msg_done = 1;
break;
case IOP_REQUEST_TYPE_SCSI_COMMAND:
req = hba->reqs[tag >> 8].req_virt;
if (likely(tag & MVIOP_MU_QUEUE_REQUEST_RESULT_BIT))
req->header.result = cpu_to_le32(IOP_RESULT_SUCCESS);
hptiop_finish_scsi_req(hba, tag>>8, req);
break;
default:
break;
}
}
static int iop_intr_mv(struct hptiop_hba *hba)
{
u32 status;
int ret = 0;
status = readl(&hba->u.mv.regs->outbound_doorbell);
writel(~status, &hba->u.mv.regs->outbound_doorbell);
if (status & MVIOP_MU_OUTBOUND_INT_MSG) {
u32 msg;
msg = readl(&hba->u.mv.mu->outbound_msg);
dprintk("received outbound msg %x\n", msg);
hptiop_message_callback(hba, msg);
ret = 1;
}
if (status & MVIOP_MU_OUTBOUND_INT_POSTQUEUE) {
u64 tag;
while ((tag = mv_outbound_read(hba->u.mv.mu)))
hptiop_request_callback_mv(hba, tag);
ret = 1;
}
return ret;
}
static int iop_send_sync_request_itl(struct hptiop_hba *hba,
void __iomem *_req, u32 millisec)
{
struct hpt_iop_request_header __iomem *req = _req;
u32 i;
writel(readl(&req->flags) | IOP_REQUEST_FLAG_SYNC_REQUEST, &req->flags);
writel(0, &req->context);
writel((unsigned long)req - (unsigned long)hba->u.itl.iop,
&hba->u.itl.iop->inbound_queue);
readl(&hba->u.itl.iop->outbound_intstatus);
for (i = 0; i < millisec; i++) {
iop_intr_itl(hba);
if (readl(&req->context))
return 0;
msleep(1);
}
return -1;
}
static int iop_send_sync_request_mv(struct hptiop_hba *hba,
u32 size_bits, u32 millisec)
{
struct hpt_iop_request_header *reqhdr = hba->u.mv.internal_req;
u32 i;
hba->msg_done = 0;
reqhdr->flags |= cpu_to_le32(IOP_REQUEST_FLAG_SYNC_REQUEST);
mv_inbound_write(hba->u.mv.internal_req_phy |
MVIOP_MU_QUEUE_ADDR_HOST_BIT | size_bits, hba);
for (i = 0; i < millisec; i++) {
iop_intr_mv(hba);
if (hba->msg_done)
return 0;
msleep(1);
}
return -1;
}
static void hptiop_post_msg_itl(struct hptiop_hba *hba, u32 msg)
{
writel(msg, &hba->u.itl.iop->inbound_msgaddr0);
readl(&hba->u.itl.iop->outbound_intstatus);
}
static void hptiop_post_msg_mv(struct hptiop_hba *hba, u32 msg)
{
writel(msg, &hba->u.mv.mu->inbound_msg);
writel(MVIOP_MU_INBOUND_INT_MSG, &hba->u.mv.regs->inbound_doorbell);
readl(&hba->u.mv.regs->inbound_doorbell);
}
static int iop_send_sync_msg(struct hptiop_hba *hba, u32 msg, u32 millisec)
{
u32 i;
hba->msg_done = 0;
hba->ops->post_msg(hba, msg);
for (i = 0; i < millisec; i++) {
spin_lock_irq(hba->host->host_lock);
hba->ops->iop_intr(hba);
spin_unlock_irq(hba->host->host_lock);
if (hba->msg_done)
break;
msleep(1);
}
return hba->msg_done? 0 : -1;
}
static int iop_get_config_itl(struct hptiop_hba *hba,
struct hpt_iop_request_get_config *config)
{
u32 req32;
struct hpt_iop_request_get_config __iomem *req;
req32 = readl(&hba->u.itl.iop->inbound_queue);
if (req32 == IOPMU_QUEUE_EMPTY)
return -1;
req = (struct hpt_iop_request_get_config __iomem *)
((unsigned long)hba->u.itl.iop + req32);
writel(0, &req->header.flags);
writel(IOP_REQUEST_TYPE_GET_CONFIG, &req->header.type);
writel(sizeof(struct hpt_iop_request_get_config), &req->header.size);
writel(IOP_RESULT_PENDING, &req->header.result);
if (iop_send_sync_request_itl(hba, req, 20000)) {
dprintk("Get config send cmd failed\n");
return -1;
}
memcpy_fromio(config, req, sizeof(*config));
writel(req32, &hba->u.itl.iop->outbound_queue);
return 0;
}
static int iop_get_config_mv(struct hptiop_hba *hba,
struct hpt_iop_request_get_config *config)
{
struct hpt_iop_request_get_config *req = hba->u.mv.internal_req;
req->header.flags = cpu_to_le32(IOP_REQUEST_FLAG_OUTPUT_CONTEXT);
req->header.type = cpu_to_le32(IOP_REQUEST_TYPE_GET_CONFIG);
req->header.size =
cpu_to_le32(sizeof(struct hpt_iop_request_get_config));
req->header.result = cpu_to_le32(IOP_RESULT_PENDING);
req->header.context = cpu_to_le32(IOP_REQUEST_TYPE_GET_CONFIG<<5);
req->header.context_hi32 = 0;
if (iop_send_sync_request_mv(hba, 0, 20000)) {
dprintk("Get config send cmd failed\n");
return -1;
}
memcpy(config, req, sizeof(struct hpt_iop_request_get_config));
return 0;
}
static int iop_set_config_itl(struct hptiop_hba *hba,
struct hpt_iop_request_set_config *config)
{
u32 req32;
struct hpt_iop_request_set_config __iomem *req;
req32 = readl(&hba->u.itl.iop->inbound_queue);
if (req32 == IOPMU_QUEUE_EMPTY)
return -1;
req = (struct hpt_iop_request_set_config __iomem *)
((unsigned long)hba->u.itl.iop + req32);
memcpy_toio((u8 __iomem *)req + sizeof(struct hpt_iop_request_header),
(u8 *)config + sizeof(struct hpt_iop_request_header),
sizeof(struct hpt_iop_request_set_config) -
sizeof(struct hpt_iop_request_header));
writel(0, &req->header.flags);
writel(IOP_REQUEST_TYPE_SET_CONFIG, &req->header.type);
writel(sizeof(struct hpt_iop_request_set_config), &req->header.size);
writel(IOP_RESULT_PENDING, &req->header.result);
if (iop_send_sync_request_itl(hba, req, 20000)) {
dprintk("Set config send cmd failed\n");
return -1;
}
writel(req32, &hba->u.itl.iop->outbound_queue);
return 0;
}
static int iop_set_config_mv(struct hptiop_hba *hba,
struct hpt_iop_request_set_config *config)
{
struct hpt_iop_request_set_config *req = hba->u.mv.internal_req;
memcpy(req, config, sizeof(struct hpt_iop_request_set_config));
req->header.flags = cpu_to_le32(IOP_REQUEST_FLAG_OUTPUT_CONTEXT);
req->header.type = cpu_to_le32(IOP_REQUEST_TYPE_SET_CONFIG);
req->header.size =
cpu_to_le32(sizeof(struct hpt_iop_request_set_config));
req->header.result = cpu_to_le32(IOP_RESULT_PENDING);
req->header.context = cpu_to_le32(IOP_REQUEST_TYPE_SET_CONFIG<<5);
req->header.context_hi32 = 0;
if (iop_send_sync_request_mv(hba, 0, 20000)) {
dprintk("Set config send cmd failed\n");
return -1;
}
return 0;
}
static void hptiop_enable_intr_itl(struct hptiop_hba *hba)
{
writel(~(IOPMU_OUTBOUND_INT_POSTQUEUE | IOPMU_OUTBOUND_INT_MSG0),
&hba->u.itl.iop->outbound_intmask);
}
static void hptiop_enable_intr_mv(struct hptiop_hba *hba)
{
writel(MVIOP_MU_OUTBOUND_INT_POSTQUEUE | MVIOP_MU_OUTBOUND_INT_MSG,
&hba->u.mv.regs->outbound_intmask);
}
static int hptiop_initialize_iop(struct hptiop_hba *hba)
{
hba->ops->enable_intr(hba);
hba->initialized = 1;
if (iop_send_sync_msg(hba,
IOPMU_INBOUND_MSG0_START_BACKGROUND_TASK, 5000)) {
printk(KERN_ERR "scsi%d: fail to start background task\n",
hba->host->host_no);
return -1;
}
return 0;
}
static void __iomem *hptiop_map_pci_bar(struct hptiop_hba *hba, int index)
{
u32 mem_base_phy, length;
void __iomem *mem_base_virt;
struct pci_dev *pcidev = hba->pcidev;
if (!(pci_resource_flags(pcidev, index) & IORESOURCE_MEM)) {
printk(KERN_ERR "scsi%d: pci resource invalid\n",
hba->host->host_no);
return NULL;
}
mem_base_phy = pci_resource_start(pcidev, index);
length = pci_resource_len(pcidev, index);
mem_base_virt = ioremap(mem_base_phy, length);
if (!mem_base_virt) {
printk(KERN_ERR "scsi%d: Fail to ioremap memory space\n",
hba->host->host_no);
return NULL;
}
return mem_base_virt;
}
static int hptiop_map_pci_bar_itl(struct hptiop_hba *hba)
{
struct pci_dev *pcidev = hba->pcidev;
hba->u.itl.iop = hptiop_map_pci_bar(hba, 0);
if (hba->u.itl.iop == NULL)
return -1;
if ((pcidev->device & 0xff00) == 0x4400) {
hba->u.itl.plx = hba->u.itl.iop;
hba->u.itl.iop = hptiop_map_pci_bar(hba, 2);
if (hba->u.itl.iop == NULL) {
iounmap(hba->u.itl.plx);
return -1;
}
}
return 0;
}
static void hptiop_unmap_pci_bar_itl(struct hptiop_hba *hba)
{
if (hba->u.itl.plx)
iounmap(hba->u.itl.plx);
iounmap(hba->u.itl.iop);
}
static int hptiop_map_pci_bar_mv(struct hptiop_hba *hba)
{
hba->u.mv.regs = hptiop_map_pci_bar(hba, 0);
if (hba->u.mv.regs == NULL)
return -1;
hba->u.mv.mu = hptiop_map_pci_bar(hba, 2);
if (hba->u.mv.mu == NULL) {
iounmap(hba->u.mv.regs);
return -1;
}
return 0;
}
static void hptiop_unmap_pci_bar_mv(struct hptiop_hba *hba)
{
iounmap(hba->u.mv.regs);
iounmap(hba->u.mv.mu);
}
static void hptiop_message_callback(struct hptiop_hba *hba, u32 msg)
{
dprintk("iop message 0x%x\n", msg);
if (msg == IOPMU_INBOUND_MSG0_NOP)
hba->msg_done = 1;
if (!hba->initialized)
return;
if (msg == IOPMU_INBOUND_MSG0_RESET) {
atomic_set(&hba->resetting, 0);
wake_up(&hba->reset_wq);
}
else if (msg <= IOPMU_INBOUND_MSG0_MAX)
hba->msg_done = 1;
}
static struct hptiop_request *get_req(struct hptiop_hba *hba)
{
struct hptiop_request *ret;
dprintk("get_req : req=%p\n", hba->req_list);
ret = hba->req_list;
if (ret)
hba->req_list = ret->next;
return ret;
}
static void free_req(struct hptiop_hba *hba, struct hptiop_request *req)
{
dprintk("free_req(%d, %p)\n", req->index, req);
req->next = hba->req_list;
hba->req_list = req;
}
static void hptiop_finish_scsi_req(struct hptiop_hba *hba, u32 tag,
struct hpt_iop_request_scsi_command *req)
{
struct scsi_cmnd *scp;
dprintk("hptiop_finish_scsi_req: req=%p, type=%d, "
"result=%d, context=0x%x tag=%d\n",
req, req->header.type, req->header.result,
req->header.context, tag);
BUG_ON(!req->header.result);
BUG_ON(req->header.type != cpu_to_le32(IOP_REQUEST_TYPE_SCSI_COMMAND));
scp = hba->reqs[tag].scp;
if (HPT_SCP(scp)->mapped)
scsi_dma_unmap(scp);
switch (le32_to_cpu(req->header.result)) {
case IOP_RESULT_SUCCESS:
scsi_set_resid(scp,
scsi_bufflen(scp) - le32_to_cpu(req->dataxfer_length));
scp->result = (DID_OK<<16);
break;
case IOP_RESULT_BAD_TARGET:
scp->result = (DID_BAD_TARGET<<16);
break;
case IOP_RESULT_BUSY:
scp->result = (DID_BUS_BUSY<<16);
break;
case IOP_RESULT_RESET:
scp->result = (DID_RESET<<16);
break;
case IOP_RESULT_FAIL:
scp->result = (DID_ERROR<<16);
break;
case IOP_RESULT_INVALID_REQUEST:
scp->result = (DID_ABORT<<16);
break;
case IOP_RESULT_CHECK_CONDITION:
scsi_set_resid(scp,
scsi_bufflen(scp) - le32_to_cpu(req->dataxfer_length));
scp->result = SAM_STAT_CHECK_CONDITION;
memcpy(scp->sense_buffer, &req->sg_list,
min_t(size_t, SCSI_SENSE_BUFFERSIZE,
le32_to_cpu(req->dataxfer_length)));
break;
default:
scp->result = DRIVER_INVALID << 24 | DID_ABORT << 16;
break;
}
dprintk("scsi_done(%p)\n", scp);
scp->scsi_done(scp);
free_req(hba, &hba->reqs[tag]);
}
static void hptiop_host_request_callback_itl(struct hptiop_hba *hba, u32 _tag)
{
struct hpt_iop_request_scsi_command *req;
u32 tag;
if (hba->iopintf_v2) {
tag = _tag & ~IOPMU_QUEUE_REQUEST_RESULT_BIT;
req = hba->reqs[tag].req_virt;
if (likely(_tag & IOPMU_QUEUE_REQUEST_RESULT_BIT))
req->header.result = cpu_to_le32(IOP_RESULT_SUCCESS);
} else {
tag = _tag;
req = hba->reqs[tag].req_virt;
}
hptiop_finish_scsi_req(hba, tag, req);
}
void hptiop_iop_request_callback_itl(struct hptiop_hba *hba, u32 tag)
{
struct hpt_iop_request_header __iomem *req;
struct hpt_iop_request_ioctl_command __iomem *p;
struct hpt_ioctl_k *arg;
req = (struct hpt_iop_request_header __iomem *)
((unsigned long)hba->u.itl.iop + tag);
dprintk("hptiop_iop_request_callback_itl: req=%p, type=%d, "
"result=%d, context=0x%x tag=%d\n",
req, readl(&req->type), readl(&req->result),
readl(&req->context), tag);
BUG_ON(!readl(&req->result));
BUG_ON(readl(&req->type) != IOP_REQUEST_TYPE_IOCTL_COMMAND);
p = (struct hpt_iop_request_ioctl_command __iomem *)req;
arg = (struct hpt_ioctl_k *)(unsigned long)
(readl(&req->context) |
((u64)readl(&req->context_hi32)<<32));
if (readl(&req->result) == IOP_RESULT_SUCCESS) {
arg->result = HPT_IOCTL_RESULT_OK;
if (arg->outbuf_size)
memcpy_fromio(arg->outbuf,
&p->buf[(readl(&p->inbuf_size) + 3)& ~3],
arg->outbuf_size);
if (arg->bytes_returned)
*arg->bytes_returned = arg->outbuf_size;
}
else
arg->result = HPT_IOCTL_RESULT_FAILED;
arg->done(arg);
writel(tag, &hba->u.itl.iop->outbound_queue);
}
static irqreturn_t hptiop_intr(int irq, void *dev_id)
{
struct hptiop_hba *hba = dev_id;
int handled;
unsigned long flags;
spin_lock_irqsave(hba->host->host_lock, flags);
handled = hba->ops->iop_intr(hba);
spin_unlock_irqrestore(hba->host->host_lock, flags);
return handled;
}
static int hptiop_buildsgl(struct scsi_cmnd *scp, struct hpt_iopsg *psg)
{
struct Scsi_Host *host = scp->device->host;
struct hptiop_hba *hba = (struct hptiop_hba *)host->hostdata;
struct scatterlist *sg;
int idx, nseg;
nseg = scsi_dma_map(scp);
BUG_ON(nseg < 0);
if (!nseg)
return 0;
HPT_SCP(scp)->sgcnt = nseg;
HPT_SCP(scp)->mapped = 1;
BUG_ON(HPT_SCP(scp)->sgcnt > hba->max_sg_descriptors);
scsi_for_each_sg(scp, sg, HPT_SCP(scp)->sgcnt, idx) {
psg[idx].pci_address = cpu_to_le64(sg_dma_address(sg));
psg[idx].size = cpu_to_le32(sg_dma_len(sg));
psg[idx].eot = (idx == HPT_SCP(scp)->sgcnt - 1) ?
cpu_to_le32(1) : 0;
}
return HPT_SCP(scp)->sgcnt;
}
static void hptiop_post_req_itl(struct hptiop_hba *hba,
struct hptiop_request *_req)
{
struct hpt_iop_request_header *reqhdr = _req->req_virt;
reqhdr->context = cpu_to_le32(IOPMU_QUEUE_ADDR_HOST_BIT |
(u32)_req->index);
reqhdr->context_hi32 = 0;
if (hba->iopintf_v2) {
u32 size, size_bits;
size = le32_to_cpu(reqhdr->size);
if (size < 256)
size_bits = IOPMU_QUEUE_REQUEST_SIZE_BIT;
else if (size < 512)
size_bits = IOPMU_QUEUE_ADDR_HOST_BIT;
else
size_bits = IOPMU_QUEUE_REQUEST_SIZE_BIT |
IOPMU_QUEUE_ADDR_HOST_BIT;
writel(_req->req_shifted_phy | size_bits,
&hba->u.itl.iop->inbound_queue);
} else
writel(_req->req_shifted_phy | IOPMU_QUEUE_ADDR_HOST_BIT,
&hba->u.itl.iop->inbound_queue);
}
static void hptiop_post_req_mv(struct hptiop_hba *hba,
struct hptiop_request *_req)
{
struct hpt_iop_request_header *reqhdr = _req->req_virt;
u32 size, size_bit;
reqhdr->context = cpu_to_le32(_req->index<<8 |
IOP_REQUEST_TYPE_SCSI_COMMAND<<5);
reqhdr->context_hi32 = 0;
size = le32_to_cpu(reqhdr->size);
if (size <= 256)
size_bit = 0;
else if (size <= 256*2)
size_bit = 1;
else if (size <= 256*3)
size_bit = 2;
else
size_bit = 3;
mv_inbound_write((_req->req_shifted_phy << 5) |
MVIOP_MU_QUEUE_ADDR_HOST_BIT | size_bit, hba);
}
static int hptiop_queuecommand_lck(struct scsi_cmnd *scp,
void (*done)(struct scsi_cmnd *))
{
struct Scsi_Host *host = scp->device->host;
struct hptiop_hba *hba = (struct hptiop_hba *)host->hostdata;
struct hpt_iop_request_scsi_command *req;
int sg_count = 0;
struct hptiop_request *_req;
BUG_ON(!done);
scp->scsi_done = done;
_req = get_req(hba);
if (_req == NULL) {
dprintk("hptiop_queuecmd : no free req\n");
return SCSI_MLQUEUE_HOST_BUSY;
}
_req->scp = scp;
dprintk("hptiop_queuecmd(scp=%p) %d/%d/%d/%d cdb=(%x-%x-%x) "
"req_index=%d, req=%p\n",
scp,
host->host_no, scp->device->channel,
scp->device->id, scp->device->lun,
((u32 *)scp->cmnd)[0],
((u32 *)scp->cmnd)[1],
((u32 *)scp->cmnd)[2],
_req->index, _req->req_virt);
scp->result = 0;
if (scp->device->channel || scp->device->lun ||
scp->device->id > hba->max_devices) {
scp->result = DID_BAD_TARGET << 16;
free_req(hba, _req);
goto cmd_done;
}
req = _req->req_virt;
sg_count = hptiop_buildsgl(scp, req->sg_list);
if (!sg_count)
HPT_SCP(scp)->mapped = 0;
req->header.flags = cpu_to_le32(IOP_REQUEST_FLAG_OUTPUT_CONTEXT);
req->header.type = cpu_to_le32(IOP_REQUEST_TYPE_SCSI_COMMAND);
req->header.result = cpu_to_le32(IOP_RESULT_PENDING);
req->dataxfer_length = cpu_to_le32(scsi_bufflen(scp));
req->channel = scp->device->channel;
req->target = scp->device->id;
req->lun = scp->device->lun;
req->header.size = cpu_to_le32(
sizeof(struct hpt_iop_request_scsi_command)
- sizeof(struct hpt_iopsg)
+ sg_count * sizeof(struct hpt_iopsg));
memcpy(req->cdb, scp->cmnd, sizeof(req->cdb));
hba->ops->post_req(hba, _req);
return 0;
cmd_done:
dprintk("scsi_done(scp=%p)\n", scp);
scp->scsi_done(scp);
return 0;
}
static int hptiop_reset_hba(struct hptiop_hba *hba)
{
if (atomic_xchg(&hba->resetting, 1) == 0) {
atomic_inc(&hba->reset_count);
hba->ops->post_msg(hba, IOPMU_INBOUND_MSG0_RESET);
}
wait_event_timeout(hba->reset_wq,
atomic_read(&hba->resetting) == 0, 60 * HZ);
if (atomic_read(&hba->resetting)) {
printk(KERN_ERR "scsi%d: reset failed\n", hba->host->host_no);
return -1;
}
if (iop_send_sync_msg(hba,
IOPMU_INBOUND_MSG0_START_BACKGROUND_TASK, 5000)) {
dprintk("scsi%d: fail to start background task\n",
hba->host->host_no);
}
return 0;
}
static int hptiop_reset(struct scsi_cmnd *scp)
{
struct Scsi_Host * host = scp->device->host;
struct hptiop_hba * hba = (struct hptiop_hba *)host->hostdata;
printk(KERN_WARNING "hptiop_reset(%d/%d/%d) scp=%p\n",
scp->device->host->host_no, scp->device->channel,
scp->device->id, scp);
return hptiop_reset_hba(hba)? FAILED : SUCCESS;
}
static int hptiop_adjust_disk_queue_depth(struct scsi_device *sdev,
int queue_depth, int reason)
{
struct hptiop_hba *hba = (struct hptiop_hba *)sdev->host->hostdata;
if (reason != SCSI_QDEPTH_DEFAULT)
return -EOPNOTSUPP;
if (queue_depth > hba->max_requests)
queue_depth = hba->max_requests;
scsi_adjust_queue_depth(sdev, MSG_ORDERED_TAG, queue_depth);
return queue_depth;
}
static ssize_t hptiop_show_version(struct device *dev,
struct device_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", driver_ver);
}
static ssize_t hptiop_show_fw_version(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *host = class_to_shost(dev);
struct hptiop_hba *hba = (struct hptiop_hba *)host->hostdata;
return snprintf(buf, PAGE_SIZE, "%d.%d.%d.%d\n",
hba->firmware_version >> 24,
(hba->firmware_version >> 16) & 0xff,
(hba->firmware_version >> 8) & 0xff,
hba->firmware_version & 0xff);
}
static int hptiop_internal_memalloc_mv(struct hptiop_hba *hba)
{
hba->u.mv.internal_req = dma_alloc_coherent(&hba->pcidev->dev,
0x800, &hba->u.mv.internal_req_phy, GFP_KERNEL);
if (hba->u.mv.internal_req)
return 0;
else
return -1;
}
static int hptiop_internal_memfree_mv(struct hptiop_hba *hba)
{
if (hba->u.mv.internal_req) {
dma_free_coherent(&hba->pcidev->dev, 0x800,
hba->u.mv.internal_req, hba->u.mv.internal_req_phy);
return 0;
} else
return -1;
}
static int __devinit hptiop_probe(struct pci_dev *pcidev,
const struct pci_device_id *id)
{
struct Scsi_Host *host = NULL;
struct hptiop_hba *hba;
struct hpt_iop_request_get_config iop_config;
struct hpt_iop_request_set_config set_config;
dma_addr_t start_phy;
void *start_virt;
u32 offset, i, req_size;
dprintk("hptiop_probe(%p)\n", pcidev);
if (pci_enable_device(pcidev)) {
printk(KERN_ERR "hptiop: fail to enable pci device\n");
return -ENODEV;
}
printk(KERN_INFO "adapter at PCI %d:%d:%d, IRQ %d\n",
pcidev->bus->number, pcidev->devfn >> 3, pcidev->devfn & 7,
pcidev->irq);
pci_set_master(pcidev);
if (pci_set_dma_mask(pcidev, DMA_BIT_MASK(64))) {
if (pci_set_dma_mask(pcidev, DMA_BIT_MASK(32))) {
printk(KERN_ERR "hptiop: fail to set dma_mask\n");
goto disable_pci_device;
}
}
if (pci_request_regions(pcidev, driver_name)) {
printk(KERN_ERR "hptiop: pci_request_regions failed\n");
goto disable_pci_device;
}
host = scsi_host_alloc(&driver_template, sizeof(struct hptiop_hba));
if (!host) {
printk(KERN_ERR "hptiop: fail to alloc scsi host\n");
goto free_pci_regions;
}
hba = (struct hptiop_hba *)host->hostdata;
hba->ops = (struct hptiop_adapter_ops *)id->driver_data;
hba->pcidev = pcidev;
hba->host = host;
hba->initialized = 0;
hba->iopintf_v2 = 0;
atomic_set(&hba->resetting, 0);
atomic_set(&hba->reset_count, 0);
init_waitqueue_head(&hba->reset_wq);
init_waitqueue_head(&hba->ioctl_wq);
host->max_lun = 1;
host->max_channel = 0;
host->io_port = 0;
host->n_io_port = 0;
host->irq = pcidev->irq;
if (hba->ops->map_pci_bar(hba))
goto free_scsi_host;
if (hba->ops->iop_wait_ready(hba, 20000)) {
printk(KERN_ERR "scsi%d: firmware not ready\n",
hba->host->host_no);
goto unmap_pci_bar;
}
if (hba->ops->internal_memalloc) {
if (hba->ops->internal_memalloc(hba)) {
printk(KERN_ERR "scsi%d: internal_memalloc failed\n",
hba->host->host_no);
goto unmap_pci_bar;
}
}
if (hba->ops->get_config(hba, &iop_config)) {
printk(KERN_ERR "scsi%d: get config failed\n",
hba->host->host_no);
goto unmap_pci_bar;
}
hba->max_requests = min(le32_to_cpu(iop_config.max_requests),
HPTIOP_MAX_REQUESTS);
hba->max_devices = le32_to_cpu(iop_config.max_devices);
hba->max_request_size = le32_to_cpu(iop_config.request_size);
hba->max_sg_descriptors = le32_to_cpu(iop_config.max_sg_count);
hba->firmware_version = le32_to_cpu(iop_config.firmware_version);
hba->interface_version = le32_to_cpu(iop_config.interface_version);
hba->sdram_size = le32_to_cpu(iop_config.sdram_size);
if (hba->firmware_version > 0x01020000 ||
hba->interface_version > 0x01020000)
hba->iopintf_v2 = 1;
host->max_sectors = le32_to_cpu(iop_config.data_transfer_length) >> 9;
host->max_id = le32_to_cpu(iop_config.max_devices);
host->sg_tablesize = le32_to_cpu(iop_config.max_sg_count);
host->can_queue = le32_to_cpu(iop_config.max_requests);
host->cmd_per_lun = le32_to_cpu(iop_config.max_requests);
host->max_cmd_len = 16;
req_size = sizeof(struct hpt_iop_request_scsi_command)
+ sizeof(struct hpt_iopsg) * (hba->max_sg_descriptors - 1);
if ((req_size & 0x1f) != 0)
req_size = (req_size + 0x1f) & ~0x1f;
memset(&set_config, 0, sizeof(struct hpt_iop_request_set_config));
set_config.iop_id = cpu_to_le32(host->host_no);
set_config.vbus_id = cpu_to_le16(host->host_no);
set_config.max_host_request_size = cpu_to_le16(req_size);
if (hba->ops->set_config(hba, &set_config)) {
printk(KERN_ERR "scsi%d: set config failed\n",
hba->host->host_no);
goto unmap_pci_bar;
}
pci_set_drvdata(pcidev, host);
if (request_irq(pcidev->irq, hptiop_intr, IRQF_SHARED,
driver_name, hba)) {
printk(KERN_ERR "scsi%d: request irq %d failed\n",
hba->host->host_no, pcidev->irq);
goto unmap_pci_bar;
}
dprintk("req_size=%d, max_requests=%d\n", req_size, hba->max_requests);
hba->req_size = req_size;
start_virt = dma_alloc_coherent(&pcidev->dev,
hba->req_size*hba->max_requests + 0x20,
&start_phy, GFP_KERNEL);
if (!start_virt) {
printk(KERN_ERR "scsi%d: fail to alloc request mem\n",
hba->host->host_no);
goto free_request_irq;
}
hba->dma_coherent = start_virt;
hba->dma_coherent_handle = start_phy;
if ((start_phy & 0x1f) != 0)
{
offset = ((start_phy + 0x1f) & ~0x1f) - start_phy;
start_phy += offset;
start_virt += offset;
}
hba->req_list = start_virt;
for (i = 0; i < hba->max_requests; i++) {
hba->reqs[i].next = NULL;
hba->reqs[i].req_virt = start_virt;
hba->reqs[i].req_shifted_phy = start_phy >> 5;
hba->reqs[i].index = i;
free_req(hba, &hba->reqs[i]);
start_virt = (char *)start_virt + hba->req_size;
start_phy = start_phy + hba->req_size;
}
if (hptiop_initialize_iop(hba))
goto free_request_mem;
if (scsi_add_host(host, &pcidev->dev)) {
printk(KERN_ERR "scsi%d: scsi_add_host failed\n",
hba->host->host_no);
goto free_request_mem;
}
scsi_scan_host(host);
dprintk("scsi%d: hptiop_probe successfully\n", hba->host->host_no);
return 0;
free_request_mem:
dma_free_coherent(&hba->pcidev->dev,
hba->req_size * hba->max_requests + 0x20,
hba->dma_coherent, hba->dma_coherent_handle);
free_request_irq:
free_irq(hba->pcidev->irq, hba);
unmap_pci_bar:
if (hba->ops->internal_memfree)
hba->ops->internal_memfree(hba);
hba->ops->unmap_pci_bar(hba);
free_scsi_host:
scsi_host_put(host);
free_pci_regions:
pci_release_regions(pcidev);
disable_pci_device:
pci_disable_device(pcidev);
dprintk("scsi%d: hptiop_probe fail\n", host ? host->host_no : 0);
return -ENODEV;
}
static void hptiop_shutdown(struct pci_dev *pcidev)
{
struct Scsi_Host *host = pci_get_drvdata(pcidev);
struct hptiop_hba *hba = (struct hptiop_hba *)host->hostdata;
dprintk("hptiop_shutdown(%p)\n", hba);
if (iop_send_sync_msg(hba, IOPMU_INBOUND_MSG0_SHUTDOWN, 60000))
printk(KERN_ERR "scsi%d: shutdown the iop timeout\n",
hba->host->host_no);
hba->ops->disable_intr(hba);
}
static void hptiop_disable_intr_itl(struct hptiop_hba *hba)
{
u32 int_mask;
int_mask = readl(&hba->u.itl.iop->outbound_intmask);
writel(int_mask |
IOPMU_OUTBOUND_INT_MSG0 | IOPMU_OUTBOUND_INT_POSTQUEUE,
&hba->u.itl.iop->outbound_intmask);
readl(&hba->u.itl.iop->outbound_intmask);
}
static void hptiop_disable_intr_mv(struct hptiop_hba *hba)
{
writel(0, &hba->u.mv.regs->outbound_intmask);
readl(&hba->u.mv.regs->outbound_intmask);
}
static void hptiop_remove(struct pci_dev *pcidev)
{
struct Scsi_Host *host = pci_get_drvdata(pcidev);
struct hptiop_hba *hba = (struct hptiop_hba *)host->hostdata;
dprintk("scsi%d: hptiop_remove\n", hba->host->host_no);
scsi_remove_host(host);
hptiop_shutdown(pcidev);
free_irq(hba->pcidev->irq, hba);
dma_free_coherent(&hba->pcidev->dev,
hba->req_size * hba->max_requests + 0x20,
hba->dma_coherent,
hba->dma_coherent_handle);
if (hba->ops->internal_memfree)
hba->ops->internal_memfree(hba);
hba->ops->unmap_pci_bar(hba);
pci_release_regions(hba->pcidev);
pci_set_drvdata(hba->pcidev, NULL);
pci_disable_device(hba->pcidev);
scsi_host_put(host);
}
static int __init hptiop_module_init(void)
{
printk(KERN_INFO "%s %s\n", driver_name_long, driver_ver);
return pci_register_driver(&hptiop_pci_driver);
}
static void __exit hptiop_module_exit(void)
{
pci_unregister_driver(&hptiop_pci_driver);
}
