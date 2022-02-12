static int carm_bdev_getgeo(struct block_device *bdev, struct hd_geometry *geo)
{
struct carm_port *port = bdev->bd_disk->private_data;
geo->heads = (u8) port->dev_geom_head;
geo->sectors = (u8) port->dev_geom_sect;
geo->cylinders = port->dev_geom_cyl;
return 0;
}
static inline int carm_lookup_bucket(u32 msg_size)
{
int i;
for (i = 0; i < ARRAY_SIZE(msg_sizes); i++)
if (msg_size <= msg_sizes[i])
return i;
return -ENOENT;
}
static void carm_init_buckets(void __iomem *mmio)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(msg_sizes); i++)
writel(msg_sizes[i], mmio + CARM_CMS0 + (4 * i));
}
static inline void *carm_ref_msg(struct carm_host *host,
unsigned int msg_idx)
{
return host->msg_base + (msg_idx * CARM_MSG_SIZE);
}
static inline dma_addr_t carm_ref_msg_dma(struct carm_host *host,
unsigned int msg_idx)
{
return host->msg_dma + (msg_idx * CARM_MSG_SIZE);
}
static int carm_send_msg(struct carm_host *host,
struct carm_request *crq)
{
void __iomem *mmio = host->mmio;
u32 msg = (u32) carm_ref_msg_dma(host, crq->tag);
u32 cm_bucket = crq->msg_bucket;
u32 tmp;
int rc = 0;
VPRINTK("ENTER\n");
tmp = readl(mmio + CARM_HMUC);
if (tmp & CARM_Q_FULL) {
#if 0
tmp = readl(mmio + CARM_INT_MASK);
tmp |= INT_Q_AVAILABLE;
writel(tmp, mmio + CARM_INT_MASK);
readl(mmio + CARM_INT_MASK);
#endif
DPRINTK("host msg queue full\n");
rc = -EBUSY;
} else {
writel(msg | (cm_bucket << 1), mmio + CARM_IHQP);
readl(mmio + CARM_IHQP);
}
return rc;
}
static struct carm_request *carm_get_request(struct carm_host *host)
{
unsigned int i;
if (host->hw_sg_used >= (CARM_MAX_HOST_SG - CARM_MAX_REQ_SG))
return NULL;
for (i = 0; i < max_queue; i++)
if ((host->msg_alloc & (1ULL << i)) == 0) {
struct carm_request *crq = &host->req[i];
crq->port = NULL;
crq->n_elem = 0;
host->msg_alloc |= (1ULL << i);
host->n_msgs++;
assert(host->n_msgs <= CARM_MAX_REQ);
sg_init_table(crq->sg, CARM_MAX_REQ_SG);
return crq;
}
DPRINTK("no request available, returning NULL\n");
return NULL;
}
static int carm_put_request(struct carm_host *host, struct carm_request *crq)
{
assert(crq->tag < max_queue);
if (unlikely((host->msg_alloc & (1ULL << crq->tag)) == 0))
return -EINVAL;
assert(host->hw_sg_used >= crq->n_elem);
host->msg_alloc &= ~(1ULL << crq->tag);
host->hw_sg_used -= crq->n_elem;
host->n_msgs--;
return 0;
}
static struct carm_request *carm_get_special(struct carm_host *host)
{
unsigned long flags;
struct carm_request *crq = NULL;
struct request *rq;
int tries = 5000;
while (tries-- > 0) {
spin_lock_irqsave(&host->lock, flags);
crq = carm_get_request(host);
spin_unlock_irqrestore(&host->lock, flags);
if (crq)
break;
msleep(10);
}
if (!crq)
return NULL;
rq = blk_get_request(host->oob_q, WRITE , GFP_KERNEL);
if (!rq) {
spin_lock_irqsave(&host->lock, flags);
carm_put_request(host, crq);
spin_unlock_irqrestore(&host->lock, flags);
return NULL;
}
crq->rq = rq;
return crq;
}
static int carm_array_info (struct carm_host *host, unsigned int array_idx)
{
struct carm_msg_ioctl *ioc;
unsigned int idx;
u32 msg_data;
dma_addr_t msg_dma;
struct carm_request *crq;
int rc;
crq = carm_get_special(host);
if (!crq) {
rc = -ENOMEM;
goto err_out;
}
idx = crq->tag;
ioc = carm_ref_msg(host, idx);
msg_dma = carm_ref_msg_dma(host, idx);
msg_data = (u32) (msg_dma + sizeof(struct carm_array_info));
crq->msg_type = CARM_MSG_ARRAY;
crq->msg_subtype = CARM_ARRAY_INFO;
rc = carm_lookup_bucket(sizeof(struct carm_msg_ioctl) +
sizeof(struct carm_array_info));
BUG_ON(rc < 0);
crq->msg_bucket = (u32) rc;
memset(ioc, 0, sizeof(*ioc));
ioc->type = CARM_MSG_ARRAY;
ioc->subtype = CARM_ARRAY_INFO;
ioc->array_id = (u8) array_idx;
ioc->handle = cpu_to_le32(TAG_ENCODE(idx));
ioc->data_addr = cpu_to_le32(msg_data);
spin_lock_irq(&host->lock);
assert(host->state == HST_DEV_SCAN_START ||
host->state == HST_DEV_SCAN);
spin_unlock_irq(&host->lock);
DPRINTK("blk_execute_rq_nowait, tag == %u\n", idx);
crq->rq->cmd_type = REQ_TYPE_SPECIAL;
crq->rq->special = crq;
blk_execute_rq_nowait(host->oob_q, NULL, crq->rq, true, NULL);
return 0;
err_out:
spin_lock_irq(&host->lock);
host->state = HST_ERROR;
spin_unlock_irq(&host->lock);
return rc;
}
static int carm_send_special (struct carm_host *host, carm_sspc_t func)
{
struct carm_request *crq;
struct carm_msg_ioctl *ioc;
void *mem;
unsigned int idx, msg_size;
int rc;
crq = carm_get_special(host);
if (!crq)
return -ENOMEM;
idx = crq->tag;
mem = carm_ref_msg(host, idx);
msg_size = func(host, idx, mem);
ioc = mem;
crq->msg_type = ioc->type;
crq->msg_subtype = ioc->subtype;
rc = carm_lookup_bucket(msg_size);
BUG_ON(rc < 0);
crq->msg_bucket = (u32) rc;
DPRINTK("blk_execute_rq_nowait, tag == %u\n", idx);
crq->rq->cmd_type = REQ_TYPE_SPECIAL;
crq->rq->special = crq;
blk_execute_rq_nowait(host->oob_q, NULL, crq->rq, true, NULL);
return 0;
}
static unsigned int carm_fill_sync_time(struct carm_host *host,
unsigned int idx, void *mem)
{
struct timeval tv;
struct carm_msg_sync_time *st = mem;
do_gettimeofday(&tv);
memset(st, 0, sizeof(*st));
st->type = CARM_MSG_MISC;
st->subtype = MISC_SET_TIME;
st->handle = cpu_to_le32(TAG_ENCODE(idx));
st->timestamp = cpu_to_le32(tv.tv_sec);
return sizeof(struct carm_msg_sync_time);
}
static unsigned int carm_fill_alloc_buf(struct carm_host *host,
unsigned int idx, void *mem)
{
struct carm_msg_allocbuf *ab = mem;
memset(ab, 0, sizeof(*ab));
ab->type = CARM_MSG_MISC;
ab->subtype = MISC_ALLOC_MEM;
ab->handle = cpu_to_le32(TAG_ENCODE(idx));
ab->n_sg = 1;
ab->sg_type = SGT_32BIT;
ab->addr = cpu_to_le32(host->shm_dma + (PDC_SHM_SIZE >> 1));
ab->len = cpu_to_le32(PDC_SHM_SIZE >> 1);
ab->evt_pool = cpu_to_le32(host->shm_dma + (16 * 1024));
ab->n_evt = cpu_to_le32(1024);
ab->rbuf_pool = cpu_to_le32(host->shm_dma);
ab->n_rbuf = cpu_to_le32(RMSG_Q_LEN);
ab->msg_pool = cpu_to_le32(host->shm_dma + RBUF_LEN);
ab->n_msg = cpu_to_le32(CARM_Q_LEN);
ab->sg[0].start = cpu_to_le32(host->shm_dma + (PDC_SHM_SIZE >> 1));
ab->sg[0].len = cpu_to_le32(65536);
return sizeof(struct carm_msg_allocbuf);
}
static unsigned int carm_fill_scan_channels(struct carm_host *host,
unsigned int idx, void *mem)
{
struct carm_msg_ioctl *ioc = mem;
u32 msg_data = (u32) (carm_ref_msg_dma(host, idx) +
IOC_SCAN_CHAN_OFFSET);
memset(ioc, 0, sizeof(*ioc));
ioc->type = CARM_MSG_IOCTL;
ioc->subtype = CARM_IOC_SCAN_CHAN;
ioc->handle = cpu_to_le32(TAG_ENCODE(idx));
ioc->data_addr = cpu_to_le32(msg_data);
mem += IOC_SCAN_CHAN_OFFSET;
memset(mem, IOC_SCAN_CHAN_NODEV, CARM_MAX_PORTS);
return IOC_SCAN_CHAN_OFFSET + CARM_MAX_PORTS;
}
static unsigned int carm_fill_get_fw_ver(struct carm_host *host,
unsigned int idx, void *mem)
{
struct carm_msg_get_fw_ver *ioc = mem;
u32 msg_data = (u32) (carm_ref_msg_dma(host, idx) + sizeof(*ioc));
memset(ioc, 0, sizeof(*ioc));
ioc->type = CARM_MSG_MISC;
ioc->subtype = MISC_GET_FW_VER;
ioc->handle = cpu_to_le32(TAG_ENCODE(idx));
ioc->data_addr = cpu_to_le32(msg_data);
return sizeof(struct carm_msg_get_fw_ver) +
sizeof(struct carm_fw_ver);
}
static inline void carm_end_request_queued(struct carm_host *host,
struct carm_request *crq,
int error)
{
struct request *req = crq->rq;
int rc;
__blk_end_request_all(req, error);
rc = carm_put_request(host, crq);
assert(rc == 0);
}
static inline void carm_push_q (struct carm_host *host, struct request_queue *q)
{
unsigned int idx = host->wait_q_prod % CARM_MAX_WAIT_Q;
blk_stop_queue(q);
VPRINTK("STOPPED QUEUE %p\n", q);
host->wait_q[idx] = q;
host->wait_q_prod++;
BUG_ON(host->wait_q_prod == host->wait_q_cons);
}
static inline struct request_queue *carm_pop_q(struct carm_host *host)
{
unsigned int idx;
if (host->wait_q_prod == host->wait_q_cons)
return NULL;
idx = host->wait_q_cons % CARM_MAX_WAIT_Q;
host->wait_q_cons++;
return host->wait_q[idx];
}
static inline void carm_round_robin(struct carm_host *host)
{
struct request_queue *q = carm_pop_q(host);
if (q) {
blk_start_queue(q);
VPRINTK("STARTED QUEUE %p\n", q);
}
}
static inline void carm_end_rq(struct carm_host *host, struct carm_request *crq,
int error)
{
carm_end_request_queued(host, crq, error);
if (max_queue == 1)
carm_round_robin(host);
else if ((host->n_msgs <= CARM_MSG_LOW_WATER) &&
(host->hw_sg_used <= CARM_SG_LOW_WATER)) {
carm_round_robin(host);
}
}
static void carm_oob_rq_fn(struct request_queue *q)
{
struct carm_host *host = q->queuedata;
struct carm_request *crq;
struct request *rq;
int rc;
while (1) {
DPRINTK("get req\n");
rq = blk_fetch_request(q);
if (!rq)
break;
crq = rq->special;
assert(crq != NULL);
assert(crq->rq == rq);
crq->n_elem = 0;
DPRINTK("send req\n");
rc = carm_send_msg(host, crq);
if (rc) {
blk_requeue_request(q, rq);
carm_push_q(host, q);
return;
}
}
}
static void carm_rq_fn(struct request_queue *q)
{
struct carm_port *port = q->queuedata;
struct carm_host *host = port->host;
struct carm_msg_rw *msg;
struct carm_request *crq;
struct request *rq;
struct scatterlist *sg;
int writing = 0, pci_dir, i, n_elem, rc;
u32 tmp;
unsigned int msg_size;
queue_one_request:
VPRINTK("get req\n");
rq = blk_peek_request(q);
if (!rq)
return;
crq = carm_get_request(host);
if (!crq) {
carm_push_q(host, q);
return;
}
crq->rq = rq;
blk_start_request(rq);
if (rq_data_dir(rq) == WRITE) {
writing = 1;
pci_dir = PCI_DMA_TODEVICE;
} else {
pci_dir = PCI_DMA_FROMDEVICE;
}
sg = &crq->sg[0];
n_elem = blk_rq_map_sg(q, rq, sg);
if (n_elem <= 0) {
carm_end_rq(host, crq, -EIO);
return;
}
n_elem = pci_map_sg(host->pdev, sg, n_elem, pci_dir);
if (n_elem <= 0) {
carm_end_rq(host, crq, -EIO);
return;
}
crq->n_elem = n_elem;
crq->port = port;
host->hw_sg_used += n_elem;
VPRINTK("build msg\n");
msg = (struct carm_msg_rw *) carm_ref_msg(host, crq->tag);
if (writing) {
msg->type = CARM_MSG_WRITE;
crq->msg_type = CARM_MSG_WRITE;
} else {
msg->type = CARM_MSG_READ;
crq->msg_type = CARM_MSG_READ;
}
msg->id = port->port_no;
msg->sg_count = n_elem;
msg->sg_type = SGT_32BIT;
msg->handle = cpu_to_le32(TAG_ENCODE(crq->tag));
msg->lba = cpu_to_le32(blk_rq_pos(rq) & 0xffffffff);
tmp = (blk_rq_pos(rq) >> 16) >> 16;
msg->lba_high = cpu_to_le16( (u16) tmp );
msg->lba_count = cpu_to_le16(blk_rq_sectors(rq));
msg_size = sizeof(struct carm_msg_rw) - sizeof(msg->sg);
for (i = 0; i < n_elem; i++) {
struct carm_msg_sg *carm_sg = &msg->sg[i];
carm_sg->start = cpu_to_le32(sg_dma_address(&crq->sg[i]));
carm_sg->len = cpu_to_le32(sg_dma_len(&crq->sg[i]));
msg_size += sizeof(struct carm_msg_sg);
}
rc = carm_lookup_bucket(msg_size);
BUG_ON(rc < 0);
crq->msg_bucket = (u32) rc;
VPRINTK("send msg, tag == %u\n", crq->tag);
rc = carm_send_msg(host, crq);
if (rc) {
carm_put_request(host, crq);
blk_requeue_request(q, rq);
carm_push_q(host, q);
return;
}
goto queue_one_request;
}
static void carm_handle_array_info(struct carm_host *host,
struct carm_request *crq, u8 *mem,
int error)
{
struct carm_port *port;
u8 *msg_data = mem + sizeof(struct carm_array_info);
struct carm_array_info *desc = (struct carm_array_info *) msg_data;
u64 lo, hi;
int cur_port;
size_t slen;
DPRINTK("ENTER\n");
carm_end_rq(host, crq, error);
if (error)
goto out;
if (le32_to_cpu(desc->array_status) & ARRAY_NO_EXIST)
goto out;
cur_port = host->cur_scan_dev;
if ((cur_port < 0) || (cur_port >= CARM_MAX_PORTS)) {
printk(KERN_ERR PFX "BUG: cur_scan_dev==%d, array_id==%d\n",
cur_port, (int) desc->array_id);
goto out;
}
port = &host->port[cur_port];
lo = (u64) le32_to_cpu(desc->size);
hi = (u64) le16_to_cpu(desc->size_hi);
port->capacity = lo | (hi << 32);
port->dev_geom_head = le16_to_cpu(desc->head);
port->dev_geom_sect = le16_to_cpu(desc->sect);
port->dev_geom_cyl = le16_to_cpu(desc->cyl);
host->dev_active |= (1 << cur_port);
strncpy(port->name, desc->name, sizeof(port->name));
port->name[sizeof(port->name) - 1] = 0;
slen = strlen(port->name);
while (slen && (port->name[slen - 1] == ' ')) {
port->name[slen - 1] = 0;
slen--;
}
printk(KERN_INFO DRV_NAME "(%s): port %u device %Lu sectors\n",
pci_name(host->pdev), port->port_no,
(unsigned long long) port->capacity);
printk(KERN_INFO DRV_NAME "(%s): port %u device \"%s\"\n",
pci_name(host->pdev), port->port_no, port->name);
out:
assert(host->state == HST_DEV_SCAN);
schedule_work(&host->fsm_task);
}
static void carm_handle_scan_chan(struct carm_host *host,
struct carm_request *crq, u8 *mem,
int error)
{
u8 *msg_data = mem + IOC_SCAN_CHAN_OFFSET;
unsigned int i, dev_count = 0;
int new_state = HST_DEV_SCAN_START;
DPRINTK("ENTER\n");
carm_end_rq(host, crq, error);
if (error) {
new_state = HST_ERROR;
goto out;
}
for (i = 0; i < 8; i++)
if (msg_data[i] == 0) {
host->dev_present |= (1 << i);
dev_count++;
}
printk(KERN_INFO DRV_NAME "(%s): found %u interesting devices\n",
pci_name(host->pdev), dev_count);
out:
assert(host->state == HST_PORT_SCAN);
host->state = new_state;
schedule_work(&host->fsm_task);
}
static void carm_handle_generic(struct carm_host *host,
struct carm_request *crq, int error,
int cur_state, int next_state)
{
DPRINTK("ENTER\n");
carm_end_rq(host, crq, error);
assert(host->state == cur_state);
if (error)
host->state = HST_ERROR;
else
host->state = next_state;
schedule_work(&host->fsm_task);
}
static inline void carm_handle_rw(struct carm_host *host,
struct carm_request *crq, int error)
{
int pci_dir;
VPRINTK("ENTER\n");
if (rq_data_dir(crq->rq) == WRITE)
pci_dir = PCI_DMA_TODEVICE;
else
pci_dir = PCI_DMA_FROMDEVICE;
pci_unmap_sg(host->pdev, &crq->sg[0], crq->n_elem, pci_dir);
carm_end_rq(host, crq, error);
}
static inline void carm_handle_resp(struct carm_host *host,
__le32 ret_handle_le, u32 status)
{
u32 handle = le32_to_cpu(ret_handle_le);
unsigned int msg_idx;
struct carm_request *crq;
int error = (status == RMSG_OK) ? 0 : -EIO;
u8 *mem;
VPRINTK("ENTER, handle == 0x%x\n", handle);
if (unlikely(!TAG_VALID(handle))) {
printk(KERN_ERR DRV_NAME "(%s): BUG: invalid tag 0x%x\n",
pci_name(host->pdev), handle);
return;
}
msg_idx = TAG_DECODE(handle);
VPRINTK("tag == %u\n", msg_idx);
crq = &host->req[msg_idx];
if (likely(crq->msg_type == CARM_MSG_READ ||
crq->msg_type == CARM_MSG_WRITE)) {
carm_handle_rw(host, crq, error);
return;
}
mem = carm_ref_msg(host, msg_idx);
switch (crq->msg_type) {
case CARM_MSG_IOCTL: {
switch (crq->msg_subtype) {
case CARM_IOC_SCAN_CHAN:
carm_handle_scan_chan(host, crq, mem, error);
break;
default:
goto err_out;
}
break;
}
case CARM_MSG_MISC: {
switch (crq->msg_subtype) {
case MISC_ALLOC_MEM:
carm_handle_generic(host, crq, error,
HST_ALLOC_BUF, HST_SYNC_TIME);
break;
case MISC_SET_TIME:
carm_handle_generic(host, crq, error,
HST_SYNC_TIME, HST_GET_FW_VER);
break;
case MISC_GET_FW_VER: {
struct carm_fw_ver *ver = (struct carm_fw_ver *)
(mem + sizeof(struct carm_msg_get_fw_ver));
if (!error) {
host->fw_ver = le32_to_cpu(ver->version);
host->flags |= (ver->features & FL_FW_VER_MASK);
}
carm_handle_generic(host, crq, error,
HST_GET_FW_VER, HST_PORT_SCAN);
break;
}
default:
goto err_out;
}
break;
}
case CARM_MSG_ARRAY: {
switch (crq->msg_subtype) {
case CARM_ARRAY_INFO:
carm_handle_array_info(host, crq, mem, error);
break;
default:
goto err_out;
}
break;
}
default:
goto err_out;
}
return;
err_out:
printk(KERN_WARNING DRV_NAME "(%s): BUG: unhandled message type %d/%d\n",
pci_name(host->pdev), crq->msg_type, crq->msg_subtype);
carm_end_rq(host, crq, -EIO);
}
static inline void carm_handle_responses(struct carm_host *host)
{
void __iomem *mmio = host->mmio;
struct carm_response *resp = (struct carm_response *) host->shm;
unsigned int work = 0;
unsigned int idx = host->resp_idx % RMSG_Q_LEN;
while (1) {
u32 status = le32_to_cpu(resp[idx].status);
if (status == 0xffffffff) {
VPRINTK("ending response on index %u\n", idx);
writel(idx << 3, mmio + CARM_RESP_IDX);
break;
}
else if ((status & (1 << 31)) == 0) {
VPRINTK("handling msg response on index %u\n", idx);
carm_handle_resp(host, resp[idx].ret_handle, status);
resp[idx].status = cpu_to_le32(0xffffffff);
}
else if ((status & 0xff000000) == (1 << 31)) {
u8 *evt_type_ptr = (u8 *) &resp[idx];
u8 evt_type = *evt_type_ptr;
printk(KERN_WARNING DRV_NAME "(%s): unhandled event type %d\n",
pci_name(host->pdev), (int) evt_type);
resp[idx].status = cpu_to_le32(0xffffffff);
}
idx = NEXT_RESP(idx);
work++;
}
VPRINTK("EXIT, work==%u\n", work);
host->resp_idx += work;
}
static irqreturn_t carm_interrupt(int irq, void *__host)
{
struct carm_host *host = __host;
void __iomem *mmio;
u32 mask;
int handled = 0;
unsigned long flags;
if (!host) {
VPRINTK("no host\n");
return IRQ_NONE;
}
spin_lock_irqsave(&host->lock, flags);
mmio = host->mmio;
mask = readl(mmio + CARM_INT_STAT);
if (mask == 0 || mask == 0xffffffff) {
VPRINTK("no work, mask == 0x%x\n", mask);
goto out;
}
if (mask & INT_ACK_MASK)
writel(mask, mmio + CARM_INT_STAT);
if (unlikely(host->state == HST_INVALID)) {
VPRINTK("not initialized yet, mask = 0x%x\n", mask);
goto out;
}
if (mask & CARM_HAVE_RESP) {
handled = 1;
carm_handle_responses(host);
}
out:
spin_unlock_irqrestore(&host->lock, flags);
VPRINTK("EXIT\n");
return IRQ_RETVAL(handled);
}
static void carm_fsm_task (struct work_struct *work)
{
struct carm_host *host =
container_of(work, struct carm_host, fsm_task);
unsigned long flags;
unsigned int state;
int rc, i, next_dev;
int reschedule = 0;
int new_state = HST_INVALID;
spin_lock_irqsave(&host->lock, flags);
state = host->state;
spin_unlock_irqrestore(&host->lock, flags);
DPRINTK("ENTER, state == %s\n", state_name[state]);
switch (state) {
case HST_PROBE_START:
new_state = HST_ALLOC_BUF;
reschedule = 1;
break;
case HST_ALLOC_BUF:
rc = carm_send_special(host, carm_fill_alloc_buf);
if (rc) {
new_state = HST_ERROR;
reschedule = 1;
}
break;
case HST_SYNC_TIME:
rc = carm_send_special(host, carm_fill_sync_time);
if (rc) {
new_state = HST_ERROR;
reschedule = 1;
}
break;
case HST_GET_FW_VER:
rc = carm_send_special(host, carm_fill_get_fw_ver);
if (rc) {
new_state = HST_ERROR;
reschedule = 1;
}
break;
case HST_PORT_SCAN:
rc = carm_send_special(host, carm_fill_scan_channels);
if (rc) {
new_state = HST_ERROR;
reschedule = 1;
}
break;
case HST_DEV_SCAN_START:
host->cur_scan_dev = -1;
new_state = HST_DEV_SCAN;
reschedule = 1;
break;
case HST_DEV_SCAN:
next_dev = -1;
for (i = host->cur_scan_dev + 1; i < CARM_MAX_PORTS; i++)
if (host->dev_present & (1 << i)) {
next_dev = i;
break;
}
if (next_dev >= 0) {
host->cur_scan_dev = next_dev;
rc = carm_array_info(host, next_dev);
if (rc) {
new_state = HST_ERROR;
reschedule = 1;
}
} else {
new_state = HST_DEV_ACTIVATE;
reschedule = 1;
}
break;
case HST_DEV_ACTIVATE: {
int activated = 0;
for (i = 0; i < CARM_MAX_PORTS; i++)
if (host->dev_active & (1 << i)) {
struct carm_port *port = &host->port[i];
struct gendisk *disk = port->disk;
set_capacity(disk, port->capacity);
add_disk(disk);
activated++;
}
printk(KERN_INFO DRV_NAME "(%s): %d ports activated\n",
pci_name(host->pdev), activated);
new_state = HST_PROBE_FINISHED;
reschedule = 1;
break;
}
case HST_PROBE_FINISHED:
complete(&host->probe_comp);
break;
case HST_ERROR:
break;
default:
printk(KERN_ERR PFX "BUG: unknown state %d\n", state);
assert(0);
break;
}
if (new_state != HST_INVALID) {
spin_lock_irqsave(&host->lock, flags);
host->state = new_state;
spin_unlock_irqrestore(&host->lock, flags);
}
if (reschedule)
schedule_work(&host->fsm_task);
}
static int carm_init_wait(void __iomem *mmio, u32 bits, unsigned int test_bit)
{
unsigned int i;
for (i = 0; i < 50000; i++) {
u32 tmp = readl(mmio + CARM_LMUC);
udelay(100);
if (test_bit) {
if ((tmp & bits) == bits)
return 0;
} else {
if ((tmp & bits) == 0)
return 0;
}
cond_resched();
}
printk(KERN_ERR PFX "carm_init_wait timeout, bits == 0x%x, test_bit == %s\n",
bits, test_bit ? "yes" : "no");
return -EBUSY;
}
static void carm_init_responses(struct carm_host *host)
{
void __iomem *mmio = host->mmio;
unsigned int i;
struct carm_response *resp = (struct carm_response *) host->shm;
for (i = 0; i < RMSG_Q_LEN; i++)
resp[i].status = cpu_to_le32(0xffffffff);
writel(0, mmio + CARM_RESP_IDX);
}
static int carm_init_host(struct carm_host *host)
{
void __iomem *mmio = host->mmio;
u32 tmp;
u8 tmp8;
int rc;
DPRINTK("ENTER\n");
writel(0, mmio + CARM_INT_MASK);
tmp8 = readb(mmio + CARM_INITC);
if (tmp8 & 0x01) {
tmp8 &= ~0x01;
writeb(tmp8, mmio + CARM_INITC);
readb(mmio + CARM_INITC);
DPRINTK("snooze...\n");
msleep(5000);
}
tmp = readl(mmio + CARM_HMUC);
if (tmp & CARM_CME) {
DPRINTK("CME bit present, waiting\n");
rc = carm_init_wait(mmio, CARM_CME, 1);
if (rc) {
DPRINTK("EXIT, carm_init_wait 1 failed\n");
return rc;
}
}
if (tmp & CARM_RME) {
DPRINTK("RME bit present, waiting\n");
rc = carm_init_wait(mmio, CARM_RME, 1);
if (rc) {
DPRINTK("EXIT, carm_init_wait 2 failed\n");
return rc;
}
}
tmp &= ~(CARM_RME | CARM_CME);
writel(tmp, mmio + CARM_HMUC);
readl(mmio + CARM_HMUC);
rc = carm_init_wait(mmio, CARM_RME | CARM_CME, 0);
if (rc) {
DPRINTK("EXIT, carm_init_wait 3 failed\n");
return rc;
}
carm_init_buckets(mmio);
writel(host->shm_dma & 0xffffffff, mmio + RBUF_ADDR_LO);
writel((host->shm_dma >> 16) >> 16, mmio + RBUF_ADDR_HI);
writel(RBUF_LEN, mmio + RBUF_BYTE_SZ);
tmp = readl(mmio + CARM_HMUC);
tmp |= (CARM_RME | CARM_CME | CARM_WZBC);
writel(tmp, mmio + CARM_HMUC);
readl(mmio + CARM_HMUC);
rc = carm_init_wait(mmio, CARM_RME | CARM_CME, 1);
if (rc) {
DPRINTK("EXIT, carm_init_wait 4 failed\n");
return rc;
}
writel(0, mmio + CARM_HMPHA);
writel(INT_DEF_MASK, mmio + CARM_INT_MASK);
carm_init_responses(host);
spin_lock_irq(&host->lock);
assert(host->state == HST_INVALID);
host->state = HST_PROBE_START;
spin_unlock_irq(&host->lock);
schedule_work(&host->fsm_task);
DPRINTK("EXIT\n");
return 0;
}
static int carm_init_disks(struct carm_host *host)
{
unsigned int i;
int rc = 0;
for (i = 0; i < CARM_MAX_PORTS; i++) {
struct gendisk *disk;
struct request_queue *q;
struct carm_port *port;
port = &host->port[i];
port->host = host;
port->port_no = i;
disk = alloc_disk(CARM_MINORS_PER_MAJOR);
if (!disk) {
rc = -ENOMEM;
break;
}
port->disk = disk;
sprintf(disk->disk_name, DRV_NAME "/%u",
(unsigned int) (host->id * CARM_MAX_PORTS) + i);
disk->major = host->major;
disk->first_minor = i * CARM_MINORS_PER_MAJOR;
disk->fops = &carm_bd_ops;
disk->private_data = port;
q = blk_init_queue(carm_rq_fn, &host->lock);
if (!q) {
rc = -ENOMEM;
break;
}
disk->queue = q;
blk_queue_max_segments(q, CARM_MAX_REQ_SG);
blk_queue_segment_boundary(q, CARM_SG_BOUNDARY);
q->queuedata = port;
}
return rc;
}
static void carm_free_disks(struct carm_host *host)
{
unsigned int i;
for (i = 0; i < CARM_MAX_PORTS; i++) {
struct gendisk *disk = host->port[i].disk;
if (disk) {
struct request_queue *q = disk->queue;
if (disk->flags & GENHD_FL_UP)
del_gendisk(disk);
if (q)
blk_cleanup_queue(q);
put_disk(disk);
}
}
}
static int carm_init_shm(struct carm_host *host)
{
host->shm = pci_alloc_consistent(host->pdev, CARM_SHM_SIZE,
&host->shm_dma);
if (!host->shm)
return -ENOMEM;
host->msg_base = host->shm + RBUF_LEN;
host->msg_dma = host->shm_dma + RBUF_LEN;
memset(host->shm, 0xff, RBUF_LEN);
memset(host->msg_base, 0, PDC_SHM_SIZE - RBUF_LEN);
return 0;
}
static int carm_init_one (struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct carm_host *host;
unsigned int pci_dac;
int rc;
struct request_queue *q;
unsigned int i;
printk_once(KERN_DEBUG DRV_NAME " version " DRV_VERSION "\n");
rc = pci_enable_device(pdev);
if (rc)
return rc;
rc = pci_request_regions(pdev, DRV_NAME);
if (rc)
goto err_out;
#ifdef IF_64BIT_DMA_IS_POSSIBLE
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(64));
if (!rc) {
rc = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64));
if (rc) {
printk(KERN_ERR DRV_NAME "(%s): consistent DMA mask failure\n",
pci_name(pdev));
goto err_out_regions;
}
pci_dac = 1;
} else {
#endif
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc) {
printk(KERN_ERR DRV_NAME "(%s): DMA mask failure\n",
pci_name(pdev));
goto err_out_regions;
}
pci_dac = 0;
#ifdef IF_64BIT_DMA_IS_POSSIBLE
}
#endif
host = kzalloc(sizeof(*host), GFP_KERNEL);
if (!host) {
printk(KERN_ERR DRV_NAME "(%s): memory alloc failure\n",
pci_name(pdev));
rc = -ENOMEM;
goto err_out_regions;
}
host->pdev = pdev;
host->flags = pci_dac ? FL_DAC : 0;
spin_lock_init(&host->lock);
INIT_WORK(&host->fsm_task, carm_fsm_task);
init_completion(&host->probe_comp);
for (i = 0; i < ARRAY_SIZE(host->req); i++)
host->req[i].tag = i;
host->mmio = ioremap(pci_resource_start(pdev, 0),
pci_resource_len(pdev, 0));
if (!host->mmio) {
printk(KERN_ERR DRV_NAME "(%s): MMIO alloc failure\n",
pci_name(pdev));
rc = -ENOMEM;
goto err_out_kfree;
}
rc = carm_init_shm(host);
if (rc) {
printk(KERN_ERR DRV_NAME "(%s): DMA SHM alloc failure\n",
pci_name(pdev));
goto err_out_iounmap;
}
q = blk_init_queue(carm_oob_rq_fn, &host->lock);
if (!q) {
printk(KERN_ERR DRV_NAME "(%s): OOB queue alloc failure\n",
pci_name(pdev));
rc = -ENOMEM;
goto err_out_pci_free;
}
host->oob_q = q;
q->queuedata = host;
if (!test_and_set_bit(0, &carm_major_alloc))
host->major = 160;
else if (!test_and_set_bit(1, &carm_major_alloc))
host->major = 161;
else
host->flags |= FL_DYN_MAJOR;
host->id = carm_host_id;
sprintf(host->name, DRV_NAME "%d", carm_host_id);
rc = register_blkdev(host->major, host->name);
if (rc < 0)
goto err_out_free_majors;
if (host->flags & FL_DYN_MAJOR)
host->major = rc;
rc = carm_init_disks(host);
if (rc)
goto err_out_blkdev_disks;
pci_set_master(pdev);
rc = request_irq(pdev->irq, carm_interrupt, IRQF_SHARED, DRV_NAME, host);
if (rc) {
printk(KERN_ERR DRV_NAME "(%s): irq alloc failure\n",
pci_name(pdev));
goto err_out_blkdev_disks;
}
rc = carm_init_host(host);
if (rc)
goto err_out_free_irq;
DPRINTK("waiting for probe_comp\n");
wait_for_completion(&host->probe_comp);
printk(KERN_INFO "%s: pci %s, ports %d, io %llx, irq %u, major %d\n",
host->name, pci_name(pdev), (int) CARM_MAX_PORTS,
(unsigned long long)pci_resource_start(pdev, 0),
pdev->irq, host->major);
carm_host_id++;
pci_set_drvdata(pdev, host);
return 0;
err_out_free_irq:
free_irq(pdev->irq, host);
err_out_blkdev_disks:
carm_free_disks(host);
unregister_blkdev(host->major, host->name);
err_out_free_majors:
if (host->major == 160)
clear_bit(0, &carm_major_alloc);
else if (host->major == 161)
clear_bit(1, &carm_major_alloc);
blk_cleanup_queue(host->oob_q);
err_out_pci_free:
pci_free_consistent(pdev, CARM_SHM_SIZE, host->shm, host->shm_dma);
err_out_iounmap:
iounmap(host->mmio);
err_out_kfree:
kfree(host);
err_out_regions:
pci_release_regions(pdev);
err_out:
pci_disable_device(pdev);
return rc;
}
static void carm_remove_one (struct pci_dev *pdev)
{
struct carm_host *host = pci_get_drvdata(pdev);
if (!host) {
printk(KERN_ERR PFX "BUG: no host data for PCI(%s)\n",
pci_name(pdev));
return;
}
free_irq(pdev->irq, host);
carm_free_disks(host);
unregister_blkdev(host->major, host->name);
if (host->major == 160)
clear_bit(0, &carm_major_alloc);
else if (host->major == 161)
clear_bit(1, &carm_major_alloc);
blk_cleanup_queue(host->oob_q);
pci_free_consistent(pdev, CARM_SHM_SIZE, host->shm, host->shm_dma);
iounmap(host->mmio);
kfree(host);
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
}
static int __init carm_init(void)
{
return pci_register_driver(&carm_driver);
}
static void __exit carm_exit(void)
{
pci_unregister_driver(&carm_driver);
}
