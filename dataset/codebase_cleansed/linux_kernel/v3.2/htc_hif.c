static int ath6kldev_cp_scat_dma_buf(struct hif_scatter_req *req, bool from_dma)
{
u8 *buf;
int i;
buf = req->virt_dma_buf;
for (i = 0; i < req->scat_entries; i++) {
if (from_dma)
memcpy(req->scat_list[i].buf, buf,
req->scat_list[i].len);
else
memcpy(buf, req->scat_list[i].buf,
req->scat_list[i].len);
buf += req->scat_list[i].len;
}
return 0;
}
int ath6kldev_rw_comp_handler(void *context, int status)
{
struct htc_packet *packet = context;
ath6kl_dbg(ATH6KL_DBG_HTC_RECV,
"ath6kldev_rw_comp_handler (pkt:0x%p , status: %d\n",
packet, status);
packet->status = status;
packet->completion(packet->context, packet);
return 0;
}
static int ath6kldev_proc_dbg_intr(struct ath6kl_device *dev)
{
u32 dummy;
int status;
ath6kl_err("target debug interrupt\n");
ath6kl_target_failure(dev->ar);
status = hif_read_write_sync(dev->ar, COUNT_DEC_ADDRESS,
(u8 *)&dummy, 4, HIF_RD_SYNC_BYTE_INC);
if (status)
WARN_ON(1);
return status;
}
int ath6kldev_poll_mboxmsg_rx(struct ath6kl_device *dev, u32 *lk_ahd,
int timeout)
{
struct ath6kl_irq_proc_registers *rg;
int status = 0, i;
u8 htc_mbox = 1 << HTC_MAILBOX;
for (i = timeout / ATH6KL_TIME_QUANTUM; i > 0; i--) {
status = hif_read_write_sync(dev->ar, HOST_INT_STATUS_ADDRESS,
(u8 *) &dev->irq_proc_reg,
sizeof(dev->irq_proc_reg),
HIF_RD_SYNC_BYTE_INC);
if (status) {
ath6kl_err("failed to read reg table\n");
return status;
}
if (dev->irq_proc_reg.host_int_status & htc_mbox) {
if (dev->irq_proc_reg.rx_lkahd_valid &
htc_mbox) {
rg = &dev->irq_proc_reg;
*lk_ahd =
le32_to_cpu(rg->rx_lkahd[HTC_MAILBOX]);
break;
}
}
mdelay(ATH6KL_TIME_QUANTUM);
ath6kl_dbg(ATH6KL_DBG_HTC_RECV, "retry mbox poll : %d\n", i);
}
if (i == 0) {
ath6kl_err("timeout waiting for recv message\n");
status = -ETIME;
if (dev->irq_proc_reg.counter_int_status &
ATH6KL_TARGET_DEBUG_INTR_MASK)
ath6kldev_proc_dbg_intr(dev);
}
return status;
}
int ath6kldev_rx_control(struct ath6kl_device *dev, bool enable_rx)
{
struct ath6kl_irq_enable_reg regs;
int status = 0;
spin_lock_bh(&dev->lock);
if (enable_rx)
dev->irq_en_reg.int_status_en |=
SM(INT_STATUS_ENABLE_MBOX_DATA, 0x01);
else
dev->irq_en_reg.int_status_en &=
~SM(INT_STATUS_ENABLE_MBOX_DATA, 0x01);
memcpy(&regs, &dev->irq_en_reg, sizeof(regs));
spin_unlock_bh(&dev->lock);
status = hif_read_write_sync(dev->ar, INT_STATUS_ENABLE_ADDRESS,
&regs.int_status_en,
sizeof(struct ath6kl_irq_enable_reg),
HIF_WR_SYNC_BYTE_INC);
return status;
}
int ath6kldev_submit_scat_req(struct ath6kl_device *dev,
struct hif_scatter_req *scat_req, bool read)
{
int status = 0;
if (read) {
scat_req->req = HIF_RD_SYNC_BLOCK_FIX;
scat_req->addr = dev->ar->mbox_info.htc_addr;
} else {
scat_req->req = HIF_WR_ASYNC_BLOCK_INC;
scat_req->addr =
(scat_req->len > HIF_MBOX_WIDTH) ?
dev->ar->mbox_info.htc_ext_addr :
dev->ar->mbox_info.htc_addr;
}
ath6kl_dbg((ATH6KL_DBG_HTC_RECV | ATH6KL_DBG_HTC_SEND),
"ath6kldev_submit_scat_req, entries: %d, total len: %d mbox:0x%X (mode: %s : %s)\n",
scat_req->scat_entries, scat_req->len,
scat_req->addr, !read ? "async" : "sync",
(read) ? "rd" : "wr");
if (!read && scat_req->virt_scat) {
status = ath6kldev_cp_scat_dma_buf(scat_req, false);
if (status) {
scat_req->status = status;
scat_req->complete(dev->ar->htc_target, scat_req);
return 0;
}
}
status = ath6kl_hif_scat_req_rw(dev->ar, scat_req);
if (read) {
scat_req->status = status;
if (!status && scat_req->virt_scat)
scat_req->status =
ath6kldev_cp_scat_dma_buf(scat_req, true);
}
return status;
}
static int ath6kldev_proc_counter_intr(struct ath6kl_device *dev)
{
u8 counter_int_status;
ath6kl_dbg(ATH6KL_DBG_IRQ, "counter interrupt\n");
counter_int_status = dev->irq_proc_reg.counter_int_status &
dev->irq_en_reg.cntr_int_status_en;
ath6kl_dbg(ATH6KL_DBG_IRQ,
"valid interrupt source(s) in COUNTER_INT_STATUS: 0x%x\n",
counter_int_status);
if (counter_int_status & ATH6KL_TARGET_DEBUG_INTR_MASK)
return ath6kldev_proc_dbg_intr(dev);
return 0;
}
static int ath6kldev_proc_err_intr(struct ath6kl_device *dev)
{
int status;
u8 error_int_status;
u8 reg_buf[4];
ath6kl_dbg(ATH6KL_DBG_IRQ, "error interrupt\n");
error_int_status = dev->irq_proc_reg.error_int_status & 0x0F;
if (!error_int_status) {
WARN_ON(1);
return -EIO;
}
ath6kl_dbg(ATH6KL_DBG_IRQ,
"valid interrupt source(s) in ERROR_INT_STATUS: 0x%x\n",
error_int_status);
if (MS(ERROR_INT_STATUS_WAKEUP, error_int_status))
ath6kl_dbg(ATH6KL_DBG_IRQ, "error : wakeup\n");
if (MS(ERROR_INT_STATUS_RX_UNDERFLOW, error_int_status))
ath6kl_err("rx underflow\n");
if (MS(ERROR_INT_STATUS_TX_OVERFLOW, error_int_status))
ath6kl_err("tx overflow\n");
dev->irq_proc_reg.error_int_status &= ~error_int_status;
reg_buf[0] = error_int_status;
reg_buf[1] = 0;
reg_buf[2] = 0;
reg_buf[3] = 0;
status = hif_read_write_sync(dev->ar, ERROR_INT_STATUS_ADDRESS,
reg_buf, 4, HIF_WR_SYNC_BYTE_FIX);
if (status)
WARN_ON(1);
return status;
}
static int ath6kldev_proc_cpu_intr(struct ath6kl_device *dev)
{
int status;
u8 cpu_int_status;
u8 reg_buf[4];
ath6kl_dbg(ATH6KL_DBG_IRQ, "cpu interrupt\n");
cpu_int_status = dev->irq_proc_reg.cpu_int_status &
dev->irq_en_reg.cpu_int_status_en;
if (!cpu_int_status) {
WARN_ON(1);
return -EIO;
}
ath6kl_dbg(ATH6KL_DBG_IRQ,
"valid interrupt source(s) in CPU_INT_STATUS: 0x%x\n",
cpu_int_status);
dev->irq_proc_reg.cpu_int_status &= ~cpu_int_status;
reg_buf[0] = cpu_int_status;
reg_buf[1] = 0;
reg_buf[2] = 0;
reg_buf[3] = 0;
status = hif_read_write_sync(dev->ar, CPU_INT_STATUS_ADDRESS,
reg_buf, 4, HIF_WR_SYNC_BYTE_FIX);
if (status)
WARN_ON(1);
return status;
}
static int proc_pending_irqs(struct ath6kl_device *dev, bool *done)
{
struct ath6kl_irq_proc_registers *rg;
int status = 0;
u8 host_int_status = 0;
u32 lk_ahd = 0;
u8 htc_mbox = 1 << HTC_MAILBOX;
ath6kl_dbg(ATH6KL_DBG_IRQ, "proc_pending_irqs: (dev: 0x%p)\n", dev);
if (dev->irq_en_reg.int_status_en) {
status = hif_read_write_sync(dev->ar, HOST_INT_STATUS_ADDRESS,
(u8 *) &dev->irq_proc_reg,
sizeof(dev->irq_proc_reg),
HIF_RD_SYNC_BYTE_INC);
if (status)
goto out;
if (AR_DBG_LVL_CHECK(ATH6KL_DBG_IRQ))
ath6kl_dump_registers(dev, &dev->irq_proc_reg,
&dev->irq_en_reg);
host_int_status = dev->irq_proc_reg.host_int_status &
dev->irq_en_reg.int_status_en;
if (host_int_status & htc_mbox) {
host_int_status &= ~htc_mbox;
if (dev->irq_proc_reg.rx_lkahd_valid &
htc_mbox) {
rg = &dev->irq_proc_reg;
lk_ahd = le32_to_cpu(rg->rx_lkahd[HTC_MAILBOX]);
if (!lk_ahd)
ath6kl_err("lookAhead is zero!\n");
}
}
}
if (!host_int_status && !lk_ahd) {
*done = true;
goto out;
}
if (lk_ahd) {
int fetched = 0;
ath6kl_dbg(ATH6KL_DBG_IRQ,
"pending mailbox msg, lk_ahd: 0x%X\n", lk_ahd);
status = ath6kl_htc_rxmsg_pending_handler(dev->htc_cnxt,
&lk_ahd, &fetched);
if (status)
goto out;
if (!fetched)
dev->htc_cnxt->chk_irq_status_cnt = 0;
}
ath6kl_dbg(ATH6KL_DBG_IRQ,
"valid interrupt source(s) for other interrupts: 0x%x\n",
host_int_status);
if (MS(HOST_INT_STATUS_CPU, host_int_status)) {
status = ath6kldev_proc_cpu_intr(dev);
if (status)
goto out;
}
if (MS(HOST_INT_STATUS_ERROR, host_int_status)) {
status = ath6kldev_proc_err_intr(dev);
if (status)
goto out;
}
if (MS(HOST_INT_STATUS_COUNTER, host_int_status))
status = ath6kldev_proc_counter_intr(dev);
out:
ath6kl_dbg(ATH6KL_DBG_IRQ,
"bypassing irq status re-check, forcing done\n");
if (!dev->htc_cnxt->chk_irq_status_cnt)
*done = true;
ath6kl_dbg(ATH6KL_DBG_IRQ,
"proc_pending_irqs: (done:%d, status=%d\n", *done, status);
return status;
}
int ath6kldev_intr_bh_handler(struct ath6kl *ar)
{
struct ath6kl_device *dev = ar->htc_target->dev;
int status = 0;
bool done = false;
dev->htc_cnxt->chk_irq_status_cnt = 0;
while (!done) {
status = proc_pending_irqs(dev, &done);
if (status)
break;
}
return status;
}
static int ath6kldev_enable_intrs(struct ath6kl_device *dev)
{
struct ath6kl_irq_enable_reg regs;
int status;
spin_lock_bh(&dev->lock);
dev->irq_en_reg.int_status_en =
SM(INT_STATUS_ENABLE_ERROR, 0x01) |
SM(INT_STATUS_ENABLE_CPU, 0x01) |
SM(INT_STATUS_ENABLE_COUNTER, 0x01);
dev->irq_en_reg.int_status_en |= SM(INT_STATUS_ENABLE_MBOX_DATA, 0x01);
dev->irq_en_reg.cpu_int_status_en = 0;
dev->irq_en_reg.err_int_status_en =
SM(ERROR_STATUS_ENABLE_RX_UNDERFLOW, 0x01) |
SM(ERROR_STATUS_ENABLE_TX_OVERFLOW, 0x1);
dev->irq_en_reg.cntr_int_status_en = SM(COUNTER_INT_STATUS_ENABLE_BIT,
ATH6KL_TARGET_DEBUG_INTR_MASK);
memcpy(&regs, &dev->irq_en_reg, sizeof(regs));
spin_unlock_bh(&dev->lock);
status = hif_read_write_sync(dev->ar, INT_STATUS_ENABLE_ADDRESS,
&regs.int_status_en, sizeof(regs),
HIF_WR_SYNC_BYTE_INC);
if (status)
ath6kl_err("failed to update interrupt ctl reg err: %d\n",
status);
return status;
}
int ath6kldev_disable_intrs(struct ath6kl_device *dev)
{
struct ath6kl_irq_enable_reg regs;
spin_lock_bh(&dev->lock);
dev->irq_en_reg.int_status_en = 0;
dev->irq_en_reg.cpu_int_status_en = 0;
dev->irq_en_reg.err_int_status_en = 0;
dev->irq_en_reg.cntr_int_status_en = 0;
memcpy(&regs, &dev->irq_en_reg, sizeof(regs));
spin_unlock_bh(&dev->lock);
return hif_read_write_sync(dev->ar, INT_STATUS_ENABLE_ADDRESS,
&regs.int_status_en, sizeof(regs),
HIF_WR_SYNC_BYTE_INC);
}
int ath6kldev_unmask_intrs(struct ath6kl_device *dev)
{
int status = 0;
ath6kldev_disable_intrs(dev);
ath6kl_hif_irq_enable(dev->ar);
status = ath6kldev_enable_intrs(dev);
return status;
}
int ath6kldev_mask_intrs(struct ath6kl_device *dev)
{
ath6kl_hif_irq_disable(dev->ar);
return ath6kldev_disable_intrs(dev);
}
int ath6kldev_setup(struct ath6kl_device *dev)
{
int status = 0;
spin_lock_init(&dev->lock);
dev->htc_cnxt->block_sz = dev->ar->mbox_info.block_size;
if ((dev->htc_cnxt->block_sz & (dev->htc_cnxt->block_sz - 1)) != 0) {
WARN_ON(1);
goto fail_setup;
}
dev->htc_cnxt->block_mask = dev->htc_cnxt->block_sz - 1;
ath6kl_dbg(ATH6KL_DBG_TRC, "block size: %d, mbox addr:0x%X\n",
dev->htc_cnxt->block_sz, dev->ar->mbox_info.htc_addr);
ath6kl_dbg(ATH6KL_DBG_TRC,
"hif interrupt processing is sync only\n");
status = ath6kldev_disable_intrs(dev);
fail_setup:
return status;
}
