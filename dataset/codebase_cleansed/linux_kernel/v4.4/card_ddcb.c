static int queue_empty(struct ddcb_queue *queue)
{
return queue->ddcb_next == queue->ddcb_act;
}
static int queue_enqueued_ddcbs(struct ddcb_queue *queue)
{
if (queue->ddcb_next >= queue->ddcb_act)
return queue->ddcb_next - queue->ddcb_act;
return queue->ddcb_max - (queue->ddcb_act - queue->ddcb_next);
}
static int queue_free_ddcbs(struct ddcb_queue *queue)
{
int free_ddcbs = queue->ddcb_max - queue_enqueued_ddcbs(queue) - 1;
if (WARN_ON_ONCE(free_ddcbs < 0)) {
return 0;
}
return free_ddcbs;
}
static inline void ddcb_mark_tapped(struct ddcb *pddcb)
{
pddcb->priv[7] = 0xbb;
}
static inline void ddcb_mark_appended(struct ddcb *pddcb)
{
pddcb->priv[7] = 0xaa;
}
static inline void ddcb_mark_cleared(struct ddcb *pddcb)
{
pddcb->priv[6] = 0xcc;
}
static inline void ddcb_mark_finished(struct ddcb *pddcb)
{
pddcb->priv[6] = 0xff;
}
static inline void ddcb_mark_unused(struct ddcb *pddcb)
{
pddcb->priv_64 = cpu_to_be64(0);
}
static inline u16 genwqe_crc16(const u8 *buff, size_t len, u16 init)
{
return crc_itu_t(init, buff, len);
}
static void print_ddcb_info(struct genwqe_dev *cd, struct ddcb_queue *queue)
{
int i;
struct ddcb *pddcb;
unsigned long flags;
struct pci_dev *pci_dev = cd->pci_dev;
spin_lock_irqsave(&cd->print_lock, flags);
dev_info(&pci_dev->dev,
"DDCB list for card #%d (ddcb_act=%d / ddcb_next=%d):\n",
cd->card_idx, queue->ddcb_act, queue->ddcb_next);
pddcb = queue->ddcb_vaddr;
for (i = 0; i < queue->ddcb_max; i++) {
dev_err(&pci_dev->dev,
" %c %-3d: RETC=%03x SEQ=%04x HSI=%02X SHI=%02x PRIV=%06llx CMD=%03x\n",
i == queue->ddcb_act ? '>' : ' ',
i,
be16_to_cpu(pddcb->retc_16),
be16_to_cpu(pddcb->seqnum_16),
pddcb->hsi,
pddcb->shi,
be64_to_cpu(pddcb->priv_64),
pddcb->cmd);
pddcb++;
}
spin_unlock_irqrestore(&cd->print_lock, flags);
}
struct genwqe_ddcb_cmd *ddcb_requ_alloc(void)
{
struct ddcb_requ *req;
req = kzalloc(sizeof(*req), GFP_KERNEL);
if (!req)
return NULL;
return &req->cmd;
}
void ddcb_requ_free(struct genwqe_ddcb_cmd *cmd)
{
struct ddcb_requ *req = container_of(cmd, struct ddcb_requ, cmd);
kfree(req);
}
static inline enum genwqe_requ_state ddcb_requ_get_state(struct ddcb_requ *req)
{
return req->req_state;
}
static inline void ddcb_requ_set_state(struct ddcb_requ *req,
enum genwqe_requ_state new_state)
{
req->req_state = new_state;
}
static inline int ddcb_requ_collect_debug_data(struct ddcb_requ *req)
{
return req->cmd.ddata_addr != 0x0;
}
static int ddcb_requ_finished(struct genwqe_dev *cd, struct ddcb_requ *req)
{
return (ddcb_requ_get_state(req) == GENWQE_REQU_FINISHED) ||
(cd->card_state != GENWQE_CARD_USED);
}
static int enqueue_ddcb(struct genwqe_dev *cd, struct ddcb_queue *queue,
struct ddcb *pddcb, int ddcb_no)
{
unsigned int try;
int prev_no;
struct ddcb *prev_ddcb;
__be32 old, new, icrc_hsi_shi;
u64 num;
ddcb_mark_unused(pddcb);
prev_no = (ddcb_no == 0) ? queue->ddcb_max - 1 : ddcb_no - 1;
prev_ddcb = &queue->ddcb_vaddr[prev_no];
ddcb_mark_appended(pddcb);
for (try = 0; try < 2; try++) {
old = prev_ddcb->icrc_hsi_shi_32;
if ((old & DDCB_COMPLETED_BE32) != 0x00000000)
break;
new = (old | DDCB_NEXT_BE32);
wmb();
icrc_hsi_shi = cmpxchg(&prev_ddcb->icrc_hsi_shi_32, old, new);
if (icrc_hsi_shi == old)
return RET_DDCB_APPENDED;
}
ddcb_mark_tapped(pddcb);
num = (u64)ddcb_no << 8;
wmb();
__genwqe_writeq(cd, queue->IO_QUEUE_OFFSET, num);
return RET_DDCB_TAPPED;
}
static void copy_ddcb_results(struct ddcb_requ *req, int ddcb_no)
{
struct ddcb_queue *queue = req->queue;
struct ddcb *pddcb = &queue->ddcb_vaddr[req->num];
memcpy(&req->cmd.asv[0], &pddcb->asv[0], DDCB_ASV_LENGTH);
req->cmd.vcrc = be16_to_cpu(pddcb->vcrc_16);
req->cmd.deque_ts = be64_to_cpu(pddcb->deque_ts_64);
req->cmd.cmplt_ts = be64_to_cpu(pddcb->cmplt_ts_64);
req->cmd.attn = be16_to_cpu(pddcb->attn_16);
req->cmd.progress = be32_to_cpu(pddcb->progress_32);
req->cmd.retc = be16_to_cpu(pddcb->retc_16);
if (ddcb_requ_collect_debug_data(req)) {
int prev_no = (ddcb_no == 0) ?
queue->ddcb_max - 1 : ddcb_no - 1;
struct ddcb *prev_pddcb = &queue->ddcb_vaddr[prev_no];
memcpy(&req->debug_data.ddcb_finished, pddcb,
sizeof(req->debug_data.ddcb_finished));
memcpy(&req->debug_data.ddcb_prev, prev_pddcb,
sizeof(req->debug_data.ddcb_prev));
}
}
static int genwqe_check_ddcb_queue(struct genwqe_dev *cd,
struct ddcb_queue *queue)
{
unsigned long flags;
int ddcbs_finished = 0;
struct pci_dev *pci_dev = cd->pci_dev;
spin_lock_irqsave(&queue->ddcb_lock, flags);
while (!queue_empty(queue) && (ddcbs_finished < queue->ddcb_max)) {
struct ddcb *pddcb;
struct ddcb_requ *req;
u16 vcrc, vcrc_16, retc_16;
pddcb = &queue->ddcb_vaddr[queue->ddcb_act];
if ((pddcb->icrc_hsi_shi_32 & DDCB_COMPLETED_BE32) ==
0x00000000)
goto go_home;
wmb();
req = queue->ddcb_req[queue->ddcb_act];
if (req == NULL) {
goto pick_next_one;
}
retc_16 = be16_to_cpu(pddcb->retc_16);
if ((pddcb->hsi == 0x44) && (retc_16 <= 0x101)) {
u64 errcnts, status;
u64 ddcb_offs = (u64)pddcb - (u64)queue->ddcb_vaddr;
errcnts = __genwqe_readq(cd, queue->IO_QUEUE_ERRCNTS);
status = __genwqe_readq(cd, queue->IO_QUEUE_STATUS);
dev_err(&pci_dev->dev,
"[%s] SEQN=%04x HSI=%02x RETC=%03x Q_ERRCNTS=%016llx Q_STATUS=%016llx DDCB_DMA_ADDR=%016llx\n",
__func__, be16_to_cpu(pddcb->seqnum_16),
pddcb->hsi, retc_16, errcnts, status,
queue->ddcb_daddr + ddcb_offs);
}
copy_ddcb_results(req, queue->ddcb_act);
queue->ddcb_req[queue->ddcb_act] = NULL;
dev_dbg(&pci_dev->dev, "FINISHED DDCB#%d\n", req->num);
genwqe_hexdump(pci_dev, pddcb, sizeof(*pddcb));
ddcb_mark_finished(pddcb);
vcrc = genwqe_crc16(pddcb->asv,
VCRC_LENGTH(req->cmd.asv_length),
0xffff);
vcrc_16 = be16_to_cpu(pddcb->vcrc_16);
if (vcrc != vcrc_16) {
printk_ratelimited(KERN_ERR
"%s %s: err: wrong VCRC pre=%02x vcrc_len=%d bytes vcrc_data=%04x is not vcrc_card=%04x\n",
GENWQE_DEVNAME, dev_name(&pci_dev->dev),
pddcb->pre, VCRC_LENGTH(req->cmd.asv_length),
vcrc, vcrc_16);
}
ddcb_requ_set_state(req, GENWQE_REQU_FINISHED);
queue->ddcbs_completed++;
queue->ddcbs_in_flight--;
wake_up_interruptible(&queue->ddcb_waitqs[queue->ddcb_act]);
wake_up_interruptible(&queue->busy_waitq);
pick_next_one:
queue->ddcb_act = (queue->ddcb_act + 1) % queue->ddcb_max;
ddcbs_finished++;
}
go_home:
spin_unlock_irqrestore(&queue->ddcb_lock, flags);
return ddcbs_finished;
}
int __genwqe_wait_ddcb(struct genwqe_dev *cd, struct ddcb_requ *req)
{
int rc;
unsigned int ddcb_no;
struct ddcb_queue *queue;
struct pci_dev *pci_dev = cd->pci_dev;
if (req == NULL)
return -EINVAL;
queue = req->queue;
if (queue == NULL)
return -EINVAL;
ddcb_no = req->num;
if (ddcb_no >= queue->ddcb_max)
return -EINVAL;
rc = wait_event_interruptible_timeout(queue->ddcb_waitqs[ddcb_no],
ddcb_requ_finished(cd, req),
genwqe_ddcb_software_timeout * HZ);
if (rc == 0) {
struct ddcb_queue *queue = req->queue;
struct ddcb *pddcb;
genwqe_check_ddcb_queue(cd, req->queue);
if (ddcb_requ_finished(cd, req))
return rc;
dev_err(&pci_dev->dev,
"[%s] err: DDCB#%d timeout rc=%d state=%d req @ %p\n",
__func__, req->num, rc, ddcb_requ_get_state(req),
req);
dev_err(&pci_dev->dev,
"[%s] IO_QUEUE_STATUS=0x%016llx\n", __func__,
__genwqe_readq(cd, queue->IO_QUEUE_STATUS));
pddcb = &queue->ddcb_vaddr[req->num];
genwqe_hexdump(pci_dev, pddcb, sizeof(*pddcb));
print_ddcb_info(cd, req->queue);
return -ETIMEDOUT;
} else if (rc == -ERESTARTSYS) {
return rc;
} else if (rc < 0) {
dev_err(&pci_dev->dev,
"[%s] err: DDCB#%d unknown result (rc=%d) %d!\n",
__func__, req->num, rc, ddcb_requ_get_state(req));
return -EINVAL;
}
if (cd->card_state != GENWQE_CARD_USED) {
dev_err(&pci_dev->dev,
"[%s] err: DDCB#%d forced to stop (rc=%d)\n",
__func__, req->num, rc);
return -EIO;
}
return rc;
}
static struct ddcb *get_next_ddcb(struct genwqe_dev *cd,
struct ddcb_queue *queue,
int *num)
{
u64 *pu64;
struct ddcb *pddcb;
if (queue_free_ddcbs(queue) == 0)
return NULL;
pddcb = &queue->ddcb_vaddr[queue->ddcb_next];
if ((pddcb->icrc_hsi_shi_32 & DDCB_COMPLETED_BE32) == 0x00000000)
return NULL;
*num = queue->ddcb_next;
queue->ddcb_next = (queue->ddcb_next + 1) % queue->ddcb_max;
pu64 = (u64 *)pddcb;
pu64[0] = 0ULL;
pu64[1] = 0ULL;
pu64[0x80/8] = 0ULL;
pu64[0x88/8] = 0ULL;
pu64[0x90/8] = 0ULL;
pu64[0x98/8] = 0ULL;
pu64[0xd0/8] = 0ULL;
pddcb->pre = DDCB_PRESET_PRE;
pddcb->seqnum_16 = cpu_to_be16(queue->ddcb_seq++);
return pddcb;
}
int __genwqe_purge_ddcb(struct genwqe_dev *cd, struct ddcb_requ *req)
{
struct ddcb *pddcb = NULL;
unsigned int t;
unsigned long flags;
struct ddcb_queue *queue = req->queue;
struct pci_dev *pci_dev = cd->pci_dev;
u64 queue_status;
__be32 icrc_hsi_shi = 0x0000;
__be32 old, new;
if (genwqe_ddcb_software_timeout <= 0) {
dev_err(&pci_dev->dev,
"[%s] err: software timeout is not set!\n", __func__);
return -EFAULT;
}
pddcb = &queue->ddcb_vaddr[req->num];
for (t = 0; t < genwqe_ddcb_software_timeout * 10; t++) {
spin_lock_irqsave(&queue->ddcb_lock, flags);
if (ddcb_requ_get_state(req) == GENWQE_REQU_FINISHED)
goto go_home;
old = pddcb->icrc_hsi_shi_32;
if ((old & DDCB_FETCHED_BE32) == 0x00000000) {
new = (old | DDCB_PURGE_BE32);
icrc_hsi_shi = cmpxchg(&pddcb->icrc_hsi_shi_32,
old, new);
if (icrc_hsi_shi == old)
goto finish_ddcb;
}
barrier();
icrc_hsi_shi = pddcb->icrc_hsi_shi_32;
if (icrc_hsi_shi & DDCB_COMPLETED_BE32)
goto finish_ddcb;
spin_unlock_irqrestore(&queue->ddcb_lock, flags);
copy_ddcb_results(req, req->num);
msleep(100);
continue;
finish_ddcb:
copy_ddcb_results(req, req->num);
ddcb_requ_set_state(req, GENWQE_REQU_FINISHED);
queue->ddcbs_in_flight--;
queue->ddcb_req[req->num] = NULL;
ddcb_mark_cleared(pddcb);
icrc_hsi_shi = pddcb->icrc_hsi_shi_32;
if ((icrc_hsi_shi & DDCB_COMPLETED_BE32) &&
(queue->ddcb_act == req->num)) {
queue->ddcb_act = ((queue->ddcb_act + 1) %
queue->ddcb_max);
}
go_home:
spin_unlock_irqrestore(&queue->ddcb_lock, flags);
return 0;
}
queue_status = __genwqe_readq(cd, queue->IO_QUEUE_STATUS);
dev_dbg(&pci_dev->dev, "UN/FINISHED DDCB#%d\n", req->num);
genwqe_hexdump(pci_dev, pddcb, sizeof(*pddcb));
dev_err(&pci_dev->dev,
"[%s] err: DDCB#%d not purged and not completed after %d seconds QSTAT=%016llx!!\n",
__func__, req->num, genwqe_ddcb_software_timeout,
queue_status);
print_ddcb_info(cd, req->queue);
return -EFAULT;
}
int genwqe_init_debug_data(struct genwqe_dev *cd, struct genwqe_debug_data *d)
{
int len;
struct pci_dev *pci_dev = cd->pci_dev;
if (d == NULL) {
dev_err(&pci_dev->dev,
"[%s] err: invalid memory for debug data!\n",
__func__);
return -EFAULT;
}
len = sizeof(d->driver_version);
snprintf(d->driver_version, len, "%s", DRV_VERSION);
d->slu_unitcfg = cd->slu_unitcfg;
d->app_unitcfg = cd->app_unitcfg;
return 0;
}
int __genwqe_enqueue_ddcb(struct genwqe_dev *cd, struct ddcb_requ *req,
unsigned int f_flags)
{
struct ddcb *pddcb;
unsigned long flags;
struct ddcb_queue *queue;
struct pci_dev *pci_dev = cd->pci_dev;
u16 icrc;
retry:
if (cd->card_state != GENWQE_CARD_USED) {
printk_ratelimited(KERN_ERR
"%s %s: [%s] Card is unusable/PCIe problem Req#%d\n",
GENWQE_DEVNAME, dev_name(&pci_dev->dev),
__func__, req->num);
return -EIO;
}
queue = req->queue = &cd->queue;
if (genwqe_polling_enabled)
genwqe_check_ddcb_queue(cd, queue);
spin_lock_irqsave(&queue->ddcb_lock, flags);
pddcb = get_next_ddcb(cd, queue, &req->num);
if (pddcb == NULL) {
int rc;
spin_unlock_irqrestore(&queue->ddcb_lock, flags);
if (f_flags & O_NONBLOCK) {
queue->return_on_busy++;
return -EBUSY;
}
queue->wait_on_busy++;
rc = wait_event_interruptible(queue->busy_waitq,
queue_free_ddcbs(queue) != 0);
dev_dbg(&pci_dev->dev, "[%s] waiting for free DDCB: rc=%d\n",
__func__, rc);
if (rc == -ERESTARTSYS)
return rc;
goto retry;
}
if (queue->ddcb_req[req->num] != NULL) {
spin_unlock_irqrestore(&queue->ddcb_lock, flags);
dev_err(&pci_dev->dev,
"[%s] picked DDCB %d with req=%p still in use!!\n",
__func__, req->num, req);
return -EFAULT;
}
ddcb_requ_set_state(req, GENWQE_REQU_ENQUEUED);
queue->ddcb_req[req->num] = req;
pddcb->cmdopts_16 = cpu_to_be16(req->cmd.cmdopts);
pddcb->cmd = req->cmd.cmd;
pddcb->acfunc = req->cmd.acfunc;
if ((cd->slu_unitcfg & 0xFFFF0ull) > 0x34199ull)
pddcb->xdir = 0x1;
else
pddcb->xdir = 0x0;
pddcb->psp = (((req->cmd.asiv_length / 8) << 4) |
((req->cmd.asv_length / 8)));
pddcb->disp_ts_64 = cpu_to_be64(req->cmd.disp_ts);
if (genwqe_get_slu_id(cd) <= 0x2) {
memcpy(&pddcb->__asiv[0],
&req->cmd.__asiv[0],
DDCB_ASIV_LENGTH);
} else {
pddcb->n.ats_64 = cpu_to_be64(req->cmd.ats);
memcpy(&pddcb->n.asiv[0],
&req->cmd.asiv[0],
DDCB_ASIV_LENGTH_ATS);
}
pddcb->icrc_hsi_shi_32 = cpu_to_be32(0x00000000);
icrc = genwqe_crc16((const u8 *)pddcb,
ICRC_LENGTH(req->cmd.asiv_length), 0xffff);
pddcb->icrc_hsi_shi_32 = cpu_to_be32((u32)icrc << 16);
if (!genwqe_polling_enabled)
pddcb->icrc_hsi_shi_32 |= DDCB_INTR_BE32;
dev_dbg(&pci_dev->dev, "INPUT DDCB#%d\n", req->num);
genwqe_hexdump(pci_dev, pddcb, sizeof(*pddcb));
if (ddcb_requ_collect_debug_data(req)) {
genwqe_init_debug_data(cd, &req->debug_data);
memcpy(&req->debug_data.ddcb_before, pddcb,
sizeof(req->debug_data.ddcb_before));
}
enqueue_ddcb(cd, queue, pddcb, req->num);
queue->ddcbs_in_flight++;
if (queue->ddcbs_in_flight > queue->ddcbs_max_in_flight)
queue->ddcbs_max_in_flight = queue->ddcbs_in_flight;
ddcb_requ_set_state(req, GENWQE_REQU_TAPPED);
spin_unlock_irqrestore(&queue->ddcb_lock, flags);
wake_up_interruptible(&cd->queue_waitq);
return 0;
}
int __genwqe_execute_raw_ddcb(struct genwqe_dev *cd,
struct genwqe_ddcb_cmd *cmd,
unsigned int f_flags)
{
int rc = 0;
struct pci_dev *pci_dev = cd->pci_dev;
struct ddcb_requ *req = container_of(cmd, struct ddcb_requ, cmd);
if (cmd->asiv_length > DDCB_ASIV_LENGTH) {
dev_err(&pci_dev->dev, "[%s] err: wrong asiv_length of %d\n",
__func__, cmd->asiv_length);
return -EINVAL;
}
if (cmd->asv_length > DDCB_ASV_LENGTH) {
dev_err(&pci_dev->dev, "[%s] err: wrong asv_length of %d\n",
__func__, cmd->asiv_length);
return -EINVAL;
}
rc = __genwqe_enqueue_ddcb(cd, req, f_flags);
if (rc != 0)
return rc;
rc = __genwqe_wait_ddcb(cd, req);
if (rc < 0)
goto err_exit;
if (ddcb_requ_collect_debug_data(req)) {
if (copy_to_user((struct genwqe_debug_data __user *)
(unsigned long)cmd->ddata_addr,
&req->debug_data,
sizeof(struct genwqe_debug_data)))
return -EFAULT;
}
if (cmd->retc != DDCB_RETC_COMPLETE) {
rc = -EBADMSG;
}
return rc;
err_exit:
__genwqe_purge_ddcb(cd, req);
if (ddcb_requ_collect_debug_data(req)) {
if (copy_to_user((struct genwqe_debug_data __user *)
(unsigned long)cmd->ddata_addr,
&req->debug_data,
sizeof(struct genwqe_debug_data)))
return -EFAULT;
}
return rc;
}
static int genwqe_next_ddcb_ready(struct genwqe_dev *cd)
{
unsigned long flags;
struct ddcb *pddcb;
struct ddcb_queue *queue = &cd->queue;
spin_lock_irqsave(&queue->ddcb_lock, flags);
if (queue_empty(queue)) {
spin_unlock_irqrestore(&queue->ddcb_lock, flags);
return 0;
}
pddcb = &queue->ddcb_vaddr[queue->ddcb_act];
if (pddcb->icrc_hsi_shi_32 & DDCB_COMPLETED_BE32) {
spin_unlock_irqrestore(&queue->ddcb_lock, flags);
return 1;
}
spin_unlock_irqrestore(&queue->ddcb_lock, flags);
return 0;
}
int genwqe_ddcbs_in_flight(struct genwqe_dev *cd)
{
unsigned long flags;
int ddcbs_in_flight = 0;
struct ddcb_queue *queue = &cd->queue;
spin_lock_irqsave(&queue->ddcb_lock, flags);
ddcbs_in_flight += queue->ddcbs_in_flight;
spin_unlock_irqrestore(&queue->ddcb_lock, flags);
return ddcbs_in_flight;
}
static int setup_ddcb_queue(struct genwqe_dev *cd, struct ddcb_queue *queue)
{
int rc, i;
struct ddcb *pddcb;
u64 val64;
unsigned int queue_size;
struct pci_dev *pci_dev = cd->pci_dev;
if (genwqe_ddcb_max < 2)
return -EINVAL;
queue_size = roundup(genwqe_ddcb_max * sizeof(struct ddcb), PAGE_SIZE);
queue->ddcbs_in_flight = 0;
queue->ddcbs_max_in_flight = 0;
queue->ddcbs_completed = 0;
queue->return_on_busy = 0;
queue->wait_on_busy = 0;
queue->ddcb_seq = 0x100;
queue->ddcb_max = genwqe_ddcb_max;
queue->ddcb_vaddr = __genwqe_alloc_consistent(cd, queue_size,
&queue->ddcb_daddr);
if (queue->ddcb_vaddr == NULL) {
dev_err(&pci_dev->dev,
"[%s] **err: could not allocate DDCB **\n", __func__);
return -ENOMEM;
}
memset(queue->ddcb_vaddr, 0, queue_size);
queue->ddcb_req = kzalloc(sizeof(struct ddcb_requ *) *
queue->ddcb_max, GFP_KERNEL);
if (!queue->ddcb_req) {
rc = -ENOMEM;
goto free_ddcbs;
}
queue->ddcb_waitqs = kzalloc(sizeof(wait_queue_head_t) *
queue->ddcb_max, GFP_KERNEL);
if (!queue->ddcb_waitqs) {
rc = -ENOMEM;
goto free_requs;
}
for (i = 0; i < queue->ddcb_max; i++) {
pddcb = &queue->ddcb_vaddr[i];
pddcb->icrc_hsi_shi_32 = DDCB_COMPLETED_BE32;
pddcb->retc_16 = cpu_to_be16(0xfff);
queue->ddcb_req[i] = NULL;
init_waitqueue_head(&queue->ddcb_waitqs[i]);
}
queue->ddcb_act = 0;
queue->ddcb_next = 0;
spin_lock_init(&queue->ddcb_lock);
init_waitqueue_head(&queue->busy_waitq);
val64 = ((u64)(queue->ddcb_max - 1) << 8);
__genwqe_writeq(cd, queue->IO_QUEUE_CONFIG, 0x07);
__genwqe_writeq(cd, queue->IO_QUEUE_SEGMENT, queue->ddcb_daddr);
__genwqe_writeq(cd, queue->IO_QUEUE_INITSQN, queue->ddcb_seq);
__genwqe_writeq(cd, queue->IO_QUEUE_WRAP, val64);
return 0;
free_requs:
kfree(queue->ddcb_req);
queue->ddcb_req = NULL;
free_ddcbs:
__genwqe_free_consistent(cd, queue_size, queue->ddcb_vaddr,
queue->ddcb_daddr);
queue->ddcb_vaddr = NULL;
queue->ddcb_daddr = 0ull;
return -ENODEV;
}
static int ddcb_queue_initialized(struct ddcb_queue *queue)
{
return queue->ddcb_vaddr != NULL;
}
static void free_ddcb_queue(struct genwqe_dev *cd, struct ddcb_queue *queue)
{
unsigned int queue_size;
queue_size = roundup(queue->ddcb_max * sizeof(struct ddcb), PAGE_SIZE);
kfree(queue->ddcb_req);
queue->ddcb_req = NULL;
if (queue->ddcb_vaddr) {
__genwqe_free_consistent(cd, queue_size, queue->ddcb_vaddr,
queue->ddcb_daddr);
queue->ddcb_vaddr = NULL;
queue->ddcb_daddr = 0ull;
}
}
static irqreturn_t genwqe_pf_isr(int irq, void *dev_id)
{
u64 gfir;
struct genwqe_dev *cd = (struct genwqe_dev *)dev_id;
struct pci_dev *pci_dev = cd->pci_dev;
cd->irqs_processed++;
wake_up_interruptible(&cd->queue_waitq);
gfir = __genwqe_readq(cd, IO_SLC_CFGREG_GFIR);
if (((gfir & GFIR_ERR_TRIGGER) != 0x0) &&
!pci_channel_offline(pci_dev)) {
if (cd->use_platform_recovery) {
readq(cd->mmio + IO_SLC_CFGREG_GFIR);
if (pci_channel_offline(pci_dev))
goto exit;
}
wake_up_interruptible(&cd->health_waitq);
dev_err_ratelimited(&pci_dev->dev,
"[%s] GFIR=%016llx\n",
__func__, gfir);
}
exit:
return IRQ_HANDLED;
}
static irqreturn_t genwqe_vf_isr(int irq, void *dev_id)
{
struct genwqe_dev *cd = (struct genwqe_dev *)dev_id;
cd->irqs_processed++;
wake_up_interruptible(&cd->queue_waitq);
return IRQ_HANDLED;
}
static int genwqe_card_thread(void *data)
{
int should_stop = 0, rc = 0;
struct genwqe_dev *cd = (struct genwqe_dev *)data;
while (!kthread_should_stop()) {
genwqe_check_ddcb_queue(cd, &cd->queue);
if (genwqe_polling_enabled) {
rc = wait_event_interruptible_timeout(
cd->queue_waitq,
genwqe_ddcbs_in_flight(cd) ||
(should_stop = kthread_should_stop()), 1);
} else {
rc = wait_event_interruptible_timeout(
cd->queue_waitq,
genwqe_next_ddcb_ready(cd) ||
(should_stop = kthread_should_stop()), HZ);
}
if (should_stop)
break;
cond_resched();
}
return 0;
}
int genwqe_setup_service_layer(struct genwqe_dev *cd)
{
int rc;
struct ddcb_queue *queue;
struct pci_dev *pci_dev = cd->pci_dev;
if (genwqe_is_privileged(cd)) {
rc = genwqe_card_reset(cd);
if (rc < 0) {
dev_err(&pci_dev->dev,
"[%s] err: reset failed.\n", __func__);
return rc;
}
genwqe_read_softreset(cd);
}
queue = &cd->queue;
queue->IO_QUEUE_CONFIG = IO_SLC_QUEUE_CONFIG;
queue->IO_QUEUE_STATUS = IO_SLC_QUEUE_STATUS;
queue->IO_QUEUE_SEGMENT = IO_SLC_QUEUE_SEGMENT;
queue->IO_QUEUE_INITSQN = IO_SLC_QUEUE_INITSQN;
queue->IO_QUEUE_OFFSET = IO_SLC_QUEUE_OFFSET;
queue->IO_QUEUE_WRAP = IO_SLC_QUEUE_WRAP;
queue->IO_QUEUE_WTIME = IO_SLC_QUEUE_WTIME;
queue->IO_QUEUE_ERRCNTS = IO_SLC_QUEUE_ERRCNTS;
queue->IO_QUEUE_LRW = IO_SLC_QUEUE_LRW;
rc = setup_ddcb_queue(cd, queue);
if (rc != 0) {
rc = -ENODEV;
goto err_out;
}
init_waitqueue_head(&cd->queue_waitq);
cd->card_thread = kthread_run(genwqe_card_thread, cd,
GENWQE_DEVNAME "%d_thread",
cd->card_idx);
if (IS_ERR(cd->card_thread)) {
rc = PTR_ERR(cd->card_thread);
cd->card_thread = NULL;
goto stop_free_queue;
}
rc = genwqe_set_interrupt_capability(cd, GENWQE_MSI_IRQS);
if (rc)
goto stop_kthread;
init_waitqueue_head(&cd->health_waitq);
if (genwqe_is_privileged(cd)) {
rc = request_irq(pci_dev->irq, genwqe_pf_isr, IRQF_SHARED,
GENWQE_DEVNAME, cd);
} else {
rc = request_irq(pci_dev->irq, genwqe_vf_isr, IRQF_SHARED,
GENWQE_DEVNAME, cd);
}
if (rc < 0) {
dev_err(&pci_dev->dev, "irq %d not free.\n", pci_dev->irq);
goto stop_irq_cap;
}
cd->card_state = GENWQE_CARD_USED;
return 0;
stop_irq_cap:
genwqe_reset_interrupt_capability(cd);
stop_kthread:
kthread_stop(cd->card_thread);
cd->card_thread = NULL;
stop_free_queue:
free_ddcb_queue(cd, queue);
err_out:
return rc;
}
static int queue_wake_up_all(struct genwqe_dev *cd)
{
unsigned int i;
unsigned long flags;
struct ddcb_queue *queue = &cd->queue;
spin_lock_irqsave(&queue->ddcb_lock, flags);
for (i = 0; i < queue->ddcb_max; i++)
wake_up_interruptible(&queue->ddcb_waitqs[queue->ddcb_act]);
wake_up_interruptible(&queue->busy_waitq);
spin_unlock_irqrestore(&queue->ddcb_lock, flags);
return 0;
}
int genwqe_finish_queue(struct genwqe_dev *cd)
{
int i, rc = 0, in_flight;
int waitmax = genwqe_ddcb_software_timeout;
struct pci_dev *pci_dev = cd->pci_dev;
struct ddcb_queue *queue = &cd->queue;
if (!ddcb_queue_initialized(queue))
return 0;
if (cd->card_state == GENWQE_CARD_USED)
cd->card_state = GENWQE_CARD_UNUSED;
queue_wake_up_all(cd);
for (i = 0; i < waitmax; i++) {
in_flight = genwqe_ddcbs_in_flight(cd);
if (in_flight == 0)
break;
dev_dbg(&pci_dev->dev,
" DEBUG [%d/%d] waiting for queue to get empty: %d requests!\n",
i, waitmax, in_flight);
msleep(1000);
}
if (i == waitmax) {
dev_err(&pci_dev->dev, " [%s] err: queue is not empty!!\n",
__func__);
rc = -EIO;
}
return rc;
}
int genwqe_release_service_layer(struct genwqe_dev *cd)
{
struct pci_dev *pci_dev = cd->pci_dev;
if (!ddcb_queue_initialized(&cd->queue))
return 1;
free_irq(pci_dev->irq, cd);
genwqe_reset_interrupt_capability(cd);
if (cd->card_thread != NULL) {
kthread_stop(cd->card_thread);
cd->card_thread = NULL;
}
free_ddcb_queue(cd, &cd->queue);
return 0;
}
