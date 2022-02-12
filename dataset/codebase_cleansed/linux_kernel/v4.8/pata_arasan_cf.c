static void cf_dumpregs(struct arasan_cf_dev *acdev)
{
struct device *dev = acdev->host->dev;
dev_dbg(dev, ": =========== REGISTER DUMP ===========");
dev_dbg(dev, ": CFI_STS: %x", readl(acdev->vbase + CFI_STS));
dev_dbg(dev, ": IRQ_STS: %x", readl(acdev->vbase + IRQ_STS));
dev_dbg(dev, ": IRQ_EN: %x", readl(acdev->vbase + IRQ_EN));
dev_dbg(dev, ": OP_MODE: %x", readl(acdev->vbase + OP_MODE));
dev_dbg(dev, ": CLK_CFG: %x", readl(acdev->vbase + CLK_CFG));
dev_dbg(dev, ": TM_CFG: %x", readl(acdev->vbase + TM_CFG));
dev_dbg(dev, ": XFER_CTR: %x", readl(acdev->vbase + XFER_CTR));
dev_dbg(dev, ": GIRQ_STS: %x", readl(acdev->vbase + GIRQ_STS));
dev_dbg(dev, ": GIRQ_STS_EN: %x", readl(acdev->vbase + GIRQ_STS_EN));
dev_dbg(dev, ": GIRQ_SGN_EN: %x", readl(acdev->vbase + GIRQ_SGN_EN));
dev_dbg(dev, ": =====================================");
}
static void cf_ginterrupt_enable(struct arasan_cf_dev *acdev, bool enable)
{
writel(enable, acdev->vbase + GIRQ_STS_EN);
writel(enable, acdev->vbase + GIRQ_SGN_EN);
}
static inline void
cf_interrupt_enable(struct arasan_cf_dev *acdev, u32 mask, bool enable)
{
u32 val = readl(acdev->vbase + IRQ_EN);
if (enable) {
writel(mask, acdev->vbase + IRQ_STS);
writel(val | mask, acdev->vbase + IRQ_EN);
} else
writel(val & ~mask, acdev->vbase + IRQ_EN);
}
static inline void cf_card_reset(struct arasan_cf_dev *acdev)
{
u32 val = readl(acdev->vbase + OP_MODE);
writel(val | CARD_RESET, acdev->vbase + OP_MODE);
udelay(200);
writel(val & ~CARD_RESET, acdev->vbase + OP_MODE);
}
static inline void cf_ctrl_reset(struct arasan_cf_dev *acdev)
{
writel(readl(acdev->vbase + OP_MODE) & ~CFHOST_ENB,
acdev->vbase + OP_MODE);
writel(readl(acdev->vbase + OP_MODE) | CFHOST_ENB,
acdev->vbase + OP_MODE);
}
static void cf_card_detect(struct arasan_cf_dev *acdev, bool hotplugged)
{
struct ata_port *ap = acdev->host->ports[0];
struct ata_eh_info *ehi = &ap->link.eh_info;
u32 val = readl(acdev->vbase + CFI_STS);
if (!(val & (CARD_DETECT1 | CARD_DETECT2))) {
if (acdev->card_present)
return;
acdev->card_present = 1;
cf_card_reset(acdev);
} else {
if (!acdev->card_present)
return;
acdev->card_present = 0;
}
if (hotplugged) {
ata_ehi_hotplugged(ehi);
ata_port_freeze(ap);
}
}
static int cf_init(struct arasan_cf_dev *acdev)
{
struct arasan_cf_pdata *pdata = dev_get_platdata(acdev->host->dev);
unsigned int if_clk;
unsigned long flags;
int ret = 0;
ret = clk_prepare_enable(acdev->clk);
if (ret) {
dev_dbg(acdev->host->dev, "clock enable failed");
return ret;
}
ret = clk_set_rate(acdev->clk, 166000000);
if (ret) {
dev_warn(acdev->host->dev, "clock set rate failed");
clk_disable_unprepare(acdev->clk);
return ret;
}
spin_lock_irqsave(&acdev->host->lock, flags);
if_clk = CF_IF_CLK_166M;
if (pdata && pdata->cf_if_clk <= CF_IF_CLK_200M)
if_clk = pdata->cf_if_clk;
writel(if_clk, acdev->vbase + CLK_CFG);
writel(TRUE_IDE_MODE | CFHOST_ENB, acdev->vbase + OP_MODE);
cf_interrupt_enable(acdev, CARD_DETECT_IRQ, 1);
cf_ginterrupt_enable(acdev, 1);
spin_unlock_irqrestore(&acdev->host->lock, flags);
return ret;
}
static void cf_exit(struct arasan_cf_dev *acdev)
{
unsigned long flags;
spin_lock_irqsave(&acdev->host->lock, flags);
cf_ginterrupt_enable(acdev, 0);
cf_interrupt_enable(acdev, TRUE_IDE_IRQS, 0);
cf_card_reset(acdev);
writel(readl(acdev->vbase + OP_MODE) & ~CFHOST_ENB,
acdev->vbase + OP_MODE);
spin_unlock_irqrestore(&acdev->host->lock, flags);
clk_disable_unprepare(acdev->clk);
}
static void dma_callback(void *dev)
{
struct arasan_cf_dev *acdev = dev;
complete(&acdev->dma_completion);
}
static inline void dma_complete(struct arasan_cf_dev *acdev)
{
struct ata_queued_cmd *qc = acdev->qc;
unsigned long flags;
acdev->qc = NULL;
ata_sff_interrupt(acdev->irq, acdev->host);
spin_lock_irqsave(&acdev->host->lock, flags);
if (unlikely(qc->err_mask) && ata_is_dma(qc->tf.protocol))
ata_ehi_push_desc(&qc->ap->link.eh_info, "DMA Failed: Timeout");
spin_unlock_irqrestore(&acdev->host->lock, flags);
}
static inline int wait4buf(struct arasan_cf_dev *acdev)
{
if (!wait_for_completion_timeout(&acdev->cf_completion, TIMEOUT)) {
u32 rw = acdev->qc->tf.flags & ATA_TFLAG_WRITE;
dev_err(acdev->host->dev, "%s TimeOut", rw ? "write" : "read");
return -ETIMEDOUT;
}
if (acdev->dma_status & ATA_DMA_ERR)
return -EAGAIN;
return 0;
}
static int
dma_xfer(struct arasan_cf_dev *acdev, dma_addr_t src, dma_addr_t dest, u32 len)
{
struct dma_async_tx_descriptor *tx;
struct dma_chan *chan = acdev->dma_chan;
dma_cookie_t cookie;
unsigned long flags = DMA_PREP_INTERRUPT;
int ret = 0;
tx = chan->device->device_prep_dma_memcpy(chan, dest, src, len, flags);
if (!tx) {
dev_err(acdev->host->dev, "device_prep_dma_memcpy failed\n");
return -EAGAIN;
}
tx->callback = dma_callback;
tx->callback_param = acdev;
cookie = tx->tx_submit(tx);
ret = dma_submit_error(cookie);
if (ret) {
dev_err(acdev->host->dev, "dma_submit_error\n");
return ret;
}
chan->device->device_issue_pending(chan);
if (!wait_for_completion_timeout(&acdev->dma_completion, TIMEOUT)) {
dmaengine_terminate_all(chan);
dev_err(acdev->host->dev, "wait_for_completion_timeout\n");
return -ETIMEDOUT;
}
return ret;
}
static int sg_xfer(struct arasan_cf_dev *acdev, struct scatterlist *sg)
{
dma_addr_t dest = 0, src = 0;
u32 xfer_cnt, sglen, dma_len, xfer_ctr;
u32 write = acdev->qc->tf.flags & ATA_TFLAG_WRITE;
unsigned long flags;
int ret = 0;
sglen = sg_dma_len(sg);
if (write) {
src = sg_dma_address(sg);
dest = acdev->pbase + EXT_WRITE_PORT;
} else {
dest = sg_dma_address(sg);
src = acdev->pbase + EXT_READ_PORT;
}
while (sglen) {
xfer_cnt = min(sglen, MAX_XFER_COUNT);
spin_lock_irqsave(&acdev->host->lock, flags);
xfer_ctr = readl(acdev->vbase + XFER_CTR) &
~XFER_COUNT_MASK;
writel(xfer_ctr | xfer_cnt | XFER_START,
acdev->vbase + XFER_CTR);
spin_unlock_irqrestore(&acdev->host->lock, flags);
while (xfer_cnt) {
if (!write) {
ret = wait4buf(acdev);
if (ret)
goto fail;
}
dma_len = min(xfer_cnt, FIFO_SIZE);
ret = dma_xfer(acdev, src, dest, dma_len);
if (ret) {
dev_err(acdev->host->dev, "dma failed");
goto fail;
}
if (write)
src += dma_len;
else
dest += dma_len;
sglen -= dma_len;
xfer_cnt -= dma_len;
if (write) {
ret = wait4buf(acdev);
if (ret)
goto fail;
}
}
}
fail:
spin_lock_irqsave(&acdev->host->lock, flags);
writel(readl(acdev->vbase + XFER_CTR) & ~XFER_START,
acdev->vbase + XFER_CTR);
spin_unlock_irqrestore(&acdev->host->lock, flags);
return ret;
}
static void data_xfer(struct work_struct *work)
{
struct arasan_cf_dev *acdev = container_of(work, struct arasan_cf_dev,
work);
struct ata_queued_cmd *qc = acdev->qc;
struct scatterlist *sg;
unsigned long flags;
u32 temp;
int ret = 0;
acdev->dma_chan = dma_request_slave_channel(acdev->host->dev, "data");
if (!acdev->dma_chan) {
dev_err(acdev->host->dev, "Unable to get dma_chan\n");
goto chan_request_fail;
}
for_each_sg(qc->sg, sg, qc->n_elem, temp) {
ret = sg_xfer(acdev, sg);
if (ret)
break;
}
dma_release_channel(acdev->dma_chan);
if (!ret) {
u32 status;
spin_lock_irqsave(&acdev->host->lock, flags);
status = ioread8(qc->ap->ioaddr.altstatus_addr);
spin_unlock_irqrestore(&acdev->host->lock, flags);
if (status & (ATA_BUSY | ATA_DRQ)) {
ata_sff_queue_delayed_work(&acdev->dwork, 1);
return;
}
goto sff_intr;
}
cf_dumpregs(acdev);
chan_request_fail:
spin_lock_irqsave(&acdev->host->lock, flags);
qc->err_mask |= AC_ERR_HOST_BUS;
qc->ap->hsm_task_state = HSM_ST_ERR;
cf_ctrl_reset(acdev);
spin_unlock_irqrestore(&acdev->host->lock, flags);
sff_intr:
dma_complete(acdev);
}
static void delayed_finish(struct work_struct *work)
{
struct arasan_cf_dev *acdev = container_of(work, struct arasan_cf_dev,
dwork.work);
struct ata_queued_cmd *qc = acdev->qc;
unsigned long flags;
u8 status;
spin_lock_irqsave(&acdev->host->lock, flags);
status = ioread8(qc->ap->ioaddr.altstatus_addr);
spin_unlock_irqrestore(&acdev->host->lock, flags);
if (status & (ATA_BUSY | ATA_DRQ))
ata_sff_queue_delayed_work(&acdev->dwork, 1);
else
dma_complete(acdev);
}
static irqreturn_t arasan_cf_interrupt(int irq, void *dev)
{
struct arasan_cf_dev *acdev = ((struct ata_host *)dev)->private_data;
unsigned long flags;
u32 irqsts;
irqsts = readl(acdev->vbase + GIRQ_STS);
if (!(irqsts & GIRQ_CF))
return IRQ_NONE;
spin_lock_irqsave(&acdev->host->lock, flags);
irqsts = readl(acdev->vbase + IRQ_STS);
writel(irqsts, acdev->vbase + IRQ_STS);
writel(GIRQ_CF, acdev->vbase + GIRQ_STS);
irqsts &= ~IGNORED_IRQS;
if (irqsts & CARD_DETECT_IRQ) {
cf_card_detect(acdev, 1);
spin_unlock_irqrestore(&acdev->host->lock, flags);
return IRQ_HANDLED;
}
if (irqsts & PIO_XFER_ERR_IRQ) {
acdev->dma_status = ATA_DMA_ERR;
writel(readl(acdev->vbase + XFER_CTR) & ~XFER_START,
acdev->vbase + XFER_CTR);
spin_unlock_irqrestore(&acdev->host->lock, flags);
complete(&acdev->cf_completion);
dev_err(acdev->host->dev, "pio xfer err irq\n");
return IRQ_HANDLED;
}
spin_unlock_irqrestore(&acdev->host->lock, flags);
if (irqsts & BUF_AVAIL_IRQ) {
complete(&acdev->cf_completion);
return IRQ_HANDLED;
}
if (irqsts & XFER_DONE_IRQ) {
struct ata_queued_cmd *qc = acdev->qc;
if (qc->tf.flags & ATA_TFLAG_WRITE)
complete(&acdev->cf_completion);
}
return IRQ_HANDLED;
}
static void arasan_cf_freeze(struct ata_port *ap)
{
struct arasan_cf_dev *acdev = ap->host->private_data;
writel(readl(acdev->vbase + XFER_CTR) & ~XFER_START,
acdev->vbase + XFER_CTR);
cf_ctrl_reset(acdev);
acdev->dma_status = ATA_DMA_ERR;
ata_sff_dma_pause(ap);
ata_sff_freeze(ap);
}
static void arasan_cf_error_handler(struct ata_port *ap)
{
struct arasan_cf_dev *acdev = ap->host->private_data;
cancel_work_sync(&acdev->work);
cancel_delayed_work_sync(&acdev->dwork);
return ata_sff_error_handler(ap);
}
static void arasan_cf_dma_start(struct arasan_cf_dev *acdev)
{
struct ata_queued_cmd *qc = acdev->qc;
struct ata_port *ap = qc->ap;
struct ata_taskfile *tf = &qc->tf;
u32 xfer_ctr = readl(acdev->vbase + XFER_CTR) & ~XFER_DIR_MASK;
u32 write = tf->flags & ATA_TFLAG_WRITE;
xfer_ctr |= write ? XFER_WRITE : XFER_READ;
writel(xfer_ctr, acdev->vbase + XFER_CTR);
ap->ops->sff_exec_command(ap, tf);
ata_sff_queue_work(&acdev->work);
}
static unsigned int arasan_cf_qc_issue(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct arasan_cf_dev *acdev = ap->host->private_data;
if (!ata_is_dma(qc->tf.protocol))
return ata_sff_qc_issue(qc);
ata_wait_idle(ap);
ata_sff_dev_select(ap, qc->dev->devno);
ata_wait_idle(ap);
switch (qc->tf.protocol) {
case ATA_PROT_DMA:
WARN_ON_ONCE(qc->tf.flags & ATA_TFLAG_POLLING);
ap->ops->sff_tf_load(ap, &qc->tf);
acdev->dma_status = 0;
acdev->qc = qc;
arasan_cf_dma_start(acdev);
ap->hsm_task_state = HSM_ST_LAST;
break;
default:
WARN_ON(1);
return AC_ERR_SYSTEM;
}
return 0;
}
static void arasan_cf_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
struct arasan_cf_dev *acdev = ap->host->private_data;
u8 pio = adev->pio_mode - XFER_PIO_0;
unsigned long flags;
u32 val;
if (pio > 6) {
dev_err(ap->dev, "Unknown PIO mode\n");
return;
}
spin_lock_irqsave(&acdev->host->lock, flags);
val = readl(acdev->vbase + OP_MODE) &
~(ULTRA_DMA_ENB | MULTI_WORD_DMA_ENB | DRQ_BLOCK_SIZE_MASK);
writel(val, acdev->vbase + OP_MODE);
val = readl(acdev->vbase + TM_CFG) & ~TRUEIDE_PIO_TIMING_MASK;
val |= pio << TRUEIDE_PIO_TIMING_SHIFT;
writel(val, acdev->vbase + TM_CFG);
cf_interrupt_enable(acdev, BUF_AVAIL_IRQ | XFER_DONE_IRQ, 0);
cf_interrupt_enable(acdev, PIO_XFER_ERR_IRQ, 1);
spin_unlock_irqrestore(&acdev->host->lock, flags);
}
static void arasan_cf_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
struct arasan_cf_dev *acdev = ap->host->private_data;
u32 opmode, tmcfg, dma_mode = adev->dma_mode;
unsigned long flags;
spin_lock_irqsave(&acdev->host->lock, flags);
opmode = readl(acdev->vbase + OP_MODE) &
~(MULTI_WORD_DMA_ENB | ULTRA_DMA_ENB);
tmcfg = readl(acdev->vbase + TM_CFG);
if ((dma_mode >= XFER_UDMA_0) && (dma_mode <= XFER_UDMA_6)) {
opmode |= ULTRA_DMA_ENB;
tmcfg &= ~ULTRA_DMA_TIMING_MASK;
tmcfg |= (dma_mode - XFER_UDMA_0) << ULTRA_DMA_TIMING_SHIFT;
} else if ((dma_mode >= XFER_MW_DMA_0) && (dma_mode <= XFER_MW_DMA_4)) {
opmode |= MULTI_WORD_DMA_ENB;
tmcfg &= ~TRUEIDE_MWORD_DMA_TIMING_MASK;
tmcfg |= (dma_mode - XFER_MW_DMA_0) <<
TRUEIDE_MWORD_DMA_TIMING_SHIFT;
} else {
dev_err(ap->dev, "Unknown DMA mode\n");
spin_unlock_irqrestore(&acdev->host->lock, flags);
return;
}
writel(opmode, acdev->vbase + OP_MODE);
writel(tmcfg, acdev->vbase + TM_CFG);
writel(DMA_XFER_MODE, acdev->vbase + XFER_CTR);
cf_interrupt_enable(acdev, PIO_XFER_ERR_IRQ, 0);
cf_interrupt_enable(acdev, BUF_AVAIL_IRQ | XFER_DONE_IRQ, 1);
spin_unlock_irqrestore(&acdev->host->lock, flags);
}
static int arasan_cf_probe(struct platform_device *pdev)
{
struct arasan_cf_dev *acdev;
struct arasan_cf_pdata *pdata = dev_get_platdata(&pdev->dev);
struct ata_host *host;
struct ata_port *ap;
struct resource *res;
u32 quirk;
irq_handler_t irq_handler = NULL;
int ret = 0;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -EINVAL;
if (!devm_request_mem_region(&pdev->dev, res->start, resource_size(res),
DRIVER_NAME)) {
dev_warn(&pdev->dev, "Failed to get memory region resource\n");
return -ENOENT;
}
acdev = devm_kzalloc(&pdev->dev, sizeof(*acdev), GFP_KERNEL);
if (!acdev) {
dev_warn(&pdev->dev, "kzalloc fail\n");
return -ENOMEM;
}
if (pdata)
quirk = pdata->quirk;
else
quirk = CF_BROKEN_UDMA;
acdev->irq = platform_get_irq(pdev, 0);
if (acdev->irq)
irq_handler = arasan_cf_interrupt;
else
quirk |= CF_BROKEN_MWDMA | CF_BROKEN_UDMA;
acdev->pbase = res->start;
acdev->vbase = devm_ioremap_nocache(&pdev->dev, res->start,
resource_size(res));
if (!acdev->vbase) {
dev_warn(&pdev->dev, "ioremap fail\n");
return -ENOMEM;
}
acdev->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(acdev->clk)) {
dev_warn(&pdev->dev, "Clock not found\n");
return PTR_ERR(acdev->clk);
}
host = ata_host_alloc(&pdev->dev, 1);
if (!host) {
dev_warn(&pdev->dev, "alloc host fail\n");
return -ENOMEM;
}
ap = host->ports[0];
host->private_data = acdev;
acdev->host = host;
ap->ops = &arasan_cf_ops;
ap->pio_mask = ATA_PIO6;
ap->mwdma_mask = ATA_MWDMA4;
ap->udma_mask = ATA_UDMA6;
init_completion(&acdev->cf_completion);
init_completion(&acdev->dma_completion);
INIT_WORK(&acdev->work, data_xfer);
INIT_DELAYED_WORK(&acdev->dwork, delayed_finish);
dma_cap_set(DMA_MEMCPY, acdev->mask);
if (quirk) {
if (quirk & CF_BROKEN_PIO) {
ap->ops->set_piomode = NULL;
ap->pio_mask = 0;
}
if (quirk & CF_BROKEN_MWDMA)
ap->mwdma_mask = 0;
if (quirk & CF_BROKEN_UDMA)
ap->udma_mask = 0;
}
ap->flags |= ATA_FLAG_PIO_POLLING | ATA_FLAG_NO_ATAPI;
ap->ioaddr.cmd_addr = acdev->vbase + ATA_DATA_PORT;
ap->ioaddr.data_addr = acdev->vbase + ATA_DATA_PORT;
ap->ioaddr.error_addr = acdev->vbase + ATA_ERR_FTR;
ap->ioaddr.feature_addr = acdev->vbase + ATA_ERR_FTR;
ap->ioaddr.nsect_addr = acdev->vbase + ATA_SC;
ap->ioaddr.lbal_addr = acdev->vbase + ATA_SN;
ap->ioaddr.lbam_addr = acdev->vbase + ATA_CL;
ap->ioaddr.lbah_addr = acdev->vbase + ATA_CH;
ap->ioaddr.device_addr = acdev->vbase + ATA_SH;
ap->ioaddr.status_addr = acdev->vbase + ATA_STS_CMD;
ap->ioaddr.command_addr = acdev->vbase + ATA_STS_CMD;
ap->ioaddr.altstatus_addr = acdev->vbase + ATA_ASTS_DCTR;
ap->ioaddr.ctl_addr = acdev->vbase + ATA_ASTS_DCTR;
ata_port_desc(ap, "phy_addr %llx virt_addr %p",
(unsigned long long) res->start, acdev->vbase);
ret = cf_init(acdev);
if (ret)
return ret;
cf_card_detect(acdev, 0);
ret = ata_host_activate(host, acdev->irq, irq_handler, 0,
&arasan_cf_sht);
if (!ret)
return 0;
cf_exit(acdev);
return ret;
}
static int arasan_cf_remove(struct platform_device *pdev)
{
struct ata_host *host = platform_get_drvdata(pdev);
struct arasan_cf_dev *acdev = host->ports[0]->private_data;
ata_host_detach(host);
cf_exit(acdev);
return 0;
}
static int arasan_cf_suspend(struct device *dev)
{
struct ata_host *host = dev_get_drvdata(dev);
struct arasan_cf_dev *acdev = host->ports[0]->private_data;
if (acdev->dma_chan)
dmaengine_terminate_all(acdev->dma_chan);
cf_exit(acdev);
return ata_host_suspend(host, PMSG_SUSPEND);
}
static int arasan_cf_resume(struct device *dev)
{
struct ata_host *host = dev_get_drvdata(dev);
struct arasan_cf_dev *acdev = host->ports[0]->private_data;
cf_init(acdev);
ata_host_resume(host);
return 0;
}
