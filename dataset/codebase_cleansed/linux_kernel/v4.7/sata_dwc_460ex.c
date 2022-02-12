static bool sata_dwc_dma_filter(struct dma_chan *chan, void *param)
{
struct dw_dma_slave *dws = &sata_dwc_dma_dws;
if (dws->dma_dev != chan->device->dev)
return false;
chan->private = dws;
return true;
}
static int sata_dwc_dma_get_channel_old(struct sata_dwc_device_port *hsdevp)
{
struct sata_dwc_device *hsdev = hsdevp->hsdev;
struct dw_dma_slave *dws = &sata_dwc_dma_dws;
dma_cap_mask_t mask;
dws->dma_dev = hsdev->dev;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
hsdevp->chan = dma_request_channel(mask, sata_dwc_dma_filter, hsdevp);
if (!hsdevp->chan) {
dev_err(hsdev->dev, "%s: dma channel unavailable\n",
__func__);
return -EAGAIN;
}
return 0;
}
static int sata_dwc_dma_init_old(struct platform_device *pdev,
struct sata_dwc_device *hsdev)
{
struct device_node *np = pdev->dev.of_node;
struct resource *res;
hsdev->dma = devm_kzalloc(&pdev->dev, sizeof(*hsdev->dma), GFP_KERNEL);
if (!hsdev->dma)
return -ENOMEM;
hsdev->dma->dev = &pdev->dev;
hsdev->dma->irq = irq_of_parse_and_map(np, 1);
if (hsdev->dma->irq == NO_IRQ) {
dev_err(&pdev->dev, "no SATA DMA irq\n");
return -ENODEV;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
hsdev->dma->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hsdev->dma->regs)) {
dev_err(&pdev->dev,
"ioremap failed for AHBDMA register address\n");
return PTR_ERR(hsdev->dma->regs);
}
return dw_dma_probe(hsdev->dma);
}
static void sata_dwc_dma_exit_old(struct sata_dwc_device *hsdev)
{
if (!hsdev->dma)
return;
dw_dma_remove(hsdev->dma);
}
static const char *get_prot_descript(u8 protocol)
{
switch ((enum ata_tf_protocols)protocol) {
case ATA_PROT_NODATA:
return "ATA no data";
case ATA_PROT_PIO:
return "ATA PIO";
case ATA_PROT_DMA:
return "ATA DMA";
case ATA_PROT_NCQ:
return "ATA NCQ";
case ATAPI_PROT_NODATA:
return "ATAPI no data";
case ATAPI_PROT_PIO:
return "ATAPI PIO";
case ATAPI_PROT_DMA:
return "ATAPI DMA";
default:
return "unknown";
}
}
static const char *get_dma_dir_descript(int dma_dir)
{
switch ((enum dma_data_direction)dma_dir) {
case DMA_BIDIRECTIONAL:
return "bidirectional";
case DMA_TO_DEVICE:
return "to device";
case DMA_FROM_DEVICE:
return "from device";
default:
return "none";
}
}
static void sata_dwc_tf_dump(struct ata_port *ap, struct ata_taskfile *tf)
{
dev_vdbg(ap->dev,
"taskfile cmd: 0x%02x protocol: %s flags: 0x%lx device: %x\n",
tf->command, get_prot_descript(tf->protocol), tf->flags,
tf->device);
dev_vdbg(ap->dev,
"feature: 0x%02x nsect: 0x%x lbal: 0x%x lbam: 0x%x lbah: 0x%x\n",
tf->feature, tf->nsect, tf->lbal, tf->lbam, tf->lbah);
dev_vdbg(ap->dev,
"hob_feature: 0x%02x hob_nsect: 0x%x hob_lbal: 0x%x hob_lbam: 0x%x hob_lbah: 0x%x\n",
tf->hob_feature, tf->hob_nsect, tf->hob_lbal, tf->hob_lbam,
tf->hob_lbah);
}
static void dma_dwc_xfer_done(void *hsdev_instance)
{
unsigned long flags;
struct sata_dwc_device *hsdev = hsdev_instance;
struct ata_host *host = (struct ata_host *)hsdev->host;
struct ata_port *ap;
struct sata_dwc_device_port *hsdevp;
u8 tag = 0;
unsigned int port = 0;
spin_lock_irqsave(&host->lock, flags);
ap = host->ports[port];
hsdevp = HSDEVP_FROM_AP(ap);
tag = ap->link.active_tag;
hsdevp->dma_interrupt_count++;
sata_dwc_clear_dmacr(hsdevp, tag);
if (hsdevp->dma_pending[tag] == SATA_DWC_DMA_PENDING_NONE) {
dev_err(ap->dev, "DMA not pending tag=0x%02x pending=%d\n",
tag, hsdevp->dma_pending[tag]);
}
if ((hsdevp->dma_interrupt_count % 2) == 0)
sata_dwc_dma_xfer_complete(ap, 1);
spin_unlock_irqrestore(&host->lock, flags);
}
static struct dma_async_tx_descriptor *dma_dwc_xfer_setup(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct sata_dwc_device_port *hsdevp = HSDEVP_FROM_AP(ap);
struct sata_dwc_device *hsdev = HSDEV_FROM_AP(ap);
struct dma_slave_config sconf;
struct dma_async_tx_descriptor *desc;
if (qc->dma_dir == DMA_DEV_TO_MEM) {
sconf.src_addr = hsdev->dmadr;
sconf.device_fc = false;
} else {
sconf.dst_addr = hsdev->dmadr;
sconf.device_fc = false;
}
sconf.direction = qc->dma_dir;
sconf.src_maxburst = AHB_DMA_BRST_DFLT / 4;
sconf.dst_maxburst = AHB_DMA_BRST_DFLT / 4;
sconf.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
sconf.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
dmaengine_slave_config(hsdevp->chan, &sconf);
desc = dmaengine_prep_slave_sg(hsdevp->chan, qc->sg, qc->n_elem,
qc->dma_dir,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc)
return NULL;
desc->callback = dma_dwc_xfer_done;
desc->callback_param = hsdev;
dev_dbg(hsdev->dev, "%s sg: 0x%p, count: %d addr: %pa\n", __func__,
qc->sg, qc->n_elem, &hsdev->dmadr);
return desc;
}
static int sata_dwc_scr_read(struct ata_link *link, unsigned int scr, u32 *val)
{
if (scr > SCR_NOTIFICATION) {
dev_err(link->ap->dev, "%s: Incorrect SCR offset 0x%02x\n",
__func__, scr);
return -EINVAL;
}
*val = sata_dwc_readl(link->ap->ioaddr.scr_addr + (scr * 4));
dev_dbg(link->ap->dev, "%s: id=%d reg=%d val=0x%08x\n", __func__,
link->ap->print_id, scr, *val);
return 0;
}
static int sata_dwc_scr_write(struct ata_link *link, unsigned int scr, u32 val)
{
dev_dbg(link->ap->dev, "%s: id=%d reg=%d val=0x%08x\n", __func__,
link->ap->print_id, scr, val);
if (scr > SCR_NOTIFICATION) {
dev_err(link->ap->dev, "%s: Incorrect SCR offset 0x%02x\n",
__func__, scr);
return -EINVAL;
}
sata_dwc_writel(link->ap->ioaddr.scr_addr + (scr * 4), val);
return 0;
}
static void clear_serror(struct ata_port *ap)
{
u32 val;
sata_dwc_scr_read(&ap->link, SCR_ERROR, &val);
sata_dwc_scr_write(&ap->link, SCR_ERROR, val);
}
static void clear_interrupt_bit(struct sata_dwc_device *hsdev, u32 bit)
{
sata_dwc_writel(&hsdev->sata_dwc_regs->intpr,
sata_dwc_readl(&hsdev->sata_dwc_regs->intpr));
}
static u32 qcmd_tag_to_mask(u8 tag)
{
return 0x00000001 << (tag & 0x1f);
}
static void sata_dwc_error_intr(struct ata_port *ap,
struct sata_dwc_device *hsdev, uint intpr)
{
struct sata_dwc_device_port *hsdevp = HSDEVP_FROM_AP(ap);
struct ata_eh_info *ehi = &ap->link.eh_info;
unsigned int err_mask = 0, action = 0;
struct ata_queued_cmd *qc;
u32 serror;
u8 status, tag;
ata_ehi_clear_desc(ehi);
sata_dwc_scr_read(&ap->link, SCR_ERROR, &serror);
status = ap->ops->sff_check_status(ap);
tag = ap->link.active_tag;
dev_err(ap->dev,
"%s SCR_ERROR=0x%08x intpr=0x%08x status=0x%08x dma_intp=%d pending=%d issued=%d",
__func__, serror, intpr, status, hsdevp->dma_interrupt_count,
hsdevp->dma_pending[tag], hsdevp->cmd_issued[tag]);
clear_serror(ap);
clear_interrupt_bit(hsdev, SATA_DWC_INTPR_ERR);
err_mask |= AC_ERR_HOST_BUS;
action |= ATA_EH_RESET;
ehi->serror |= serror;
ehi->action |= action;
qc = ata_qc_from_tag(ap, tag);
if (qc)
qc->err_mask |= err_mask;
else
ehi->err_mask |= err_mask;
ata_port_abort(ap);
}
static irqreturn_t sata_dwc_isr(int irq, void *dev_instance)
{
struct ata_host *host = (struct ata_host *)dev_instance;
struct sata_dwc_device *hsdev = HSDEV_FROM_HOST(host);
struct ata_port *ap;
struct ata_queued_cmd *qc;
unsigned long flags;
u8 status, tag;
int handled, num_processed, port = 0;
uint intpr, sactive, sactive2, tag_mask;
struct sata_dwc_device_port *hsdevp;
hsdev->sactive_issued = 0;
spin_lock_irqsave(&host->lock, flags);
intpr = sata_dwc_readl(&hsdev->sata_dwc_regs->intpr);
ap = host->ports[port];
hsdevp = HSDEVP_FROM_AP(ap);
dev_dbg(ap->dev, "%s intpr=0x%08x active_tag=%d\n", __func__, intpr,
ap->link.active_tag);
if (intpr & SATA_DWC_INTPR_ERR) {
sata_dwc_error_intr(ap, hsdev, intpr);
handled = 1;
goto DONE;
}
if (intpr & SATA_DWC_INTPR_NEWFP) {
clear_interrupt_bit(hsdev, SATA_DWC_INTPR_NEWFP);
tag = (u8)(sata_dwc_readl(&hsdev->sata_dwc_regs->fptagr));
dev_dbg(ap->dev, "%s: NEWFP tag=%d\n", __func__, tag);
if (hsdevp->cmd_issued[tag] != SATA_DWC_CMD_ISSUED_PEND)
dev_warn(ap->dev, "CMD tag=%d not pending?\n", tag);
hsdev->sactive_issued |= qcmd_tag_to_mask(tag);
qc = ata_qc_from_tag(ap, tag);
qc->ap->link.active_tag = tag;
sata_dwc_bmdma_start_by_tag(qc, tag);
handled = 1;
goto DONE;
}
sata_dwc_scr_read(&ap->link, SCR_ACTIVE, &sactive);
tag_mask = (hsdev->sactive_issued | sactive) ^ sactive;
if (hsdev->sactive_issued == 0 && tag_mask == 0) {
if (ap->link.active_tag == ATA_TAG_POISON)
tag = 0;
else
tag = ap->link.active_tag;
qc = ata_qc_from_tag(ap, tag);
if (unlikely(!qc || (qc->tf.flags & ATA_TFLAG_POLLING))) {
dev_err(ap->dev,
"%s interrupt with no active qc qc=%p\n",
__func__, qc);
ap->ops->sff_check_status(ap);
handled = 1;
goto DONE;
}
status = ap->ops->sff_check_status(ap);
qc->ap->link.active_tag = tag;
hsdevp->cmd_issued[tag] = SATA_DWC_CMD_ISSUED_NOT;
if (status & ATA_ERR) {
dev_dbg(ap->dev, "interrupt ATA_ERR (0x%x)\n", status);
sata_dwc_qc_complete(ap, qc, 1);
handled = 1;
goto DONE;
}
dev_dbg(ap->dev, "%s non-NCQ cmd interrupt, protocol: %s\n",
__func__, get_prot_descript(qc->tf.protocol));
DRVSTILLBUSY:
if (ata_is_dma(qc->tf.protocol)) {
hsdevp->dma_interrupt_count++;
if (hsdevp->dma_pending[tag] == \
SATA_DWC_DMA_PENDING_NONE) {
dev_err(ap->dev,
"%s: DMA not pending intpr=0x%08x status=0x%08x pending=%d\n",
__func__, intpr, status,
hsdevp->dma_pending[tag]);
}
if ((hsdevp->dma_interrupt_count % 2) == 0)
sata_dwc_dma_xfer_complete(ap, 1);
} else if (ata_is_pio(qc->tf.protocol)) {
ata_sff_hsm_move(ap, qc, status, 0);
handled = 1;
goto DONE;
} else {
if (unlikely(sata_dwc_qc_complete(ap, qc, 1)))
goto DRVSTILLBUSY;
}
handled = 1;
goto DONE;
}
sata_dwc_scr_read(&ap->link, SCR_ACTIVE, &sactive);
tag_mask = (hsdev->sactive_issued | sactive) ^ sactive;
if (sactive != 0 || hsdev->sactive_issued > 1 || tag_mask > 1) {
dev_dbg(ap->dev,
"%s NCQ:sactive=0x%08x sactive_issued=0x%08x tag_mask=0x%08x\n",
__func__, sactive, hsdev->sactive_issued, tag_mask);
}
if ((tag_mask | hsdev->sactive_issued) != hsdev->sactive_issued) {
dev_warn(ap->dev,
"Bad tag mask? sactive=0x%08x sactive_issued=0x%08x tag_mask=0x%08x\n",
sactive, hsdev->sactive_issued, tag_mask);
}
status = ap->ops->sff_check_status(ap);
dev_dbg(ap->dev, "%s ATA status register=0x%x\n", __func__, status);
tag = 0;
num_processed = 0;
while (tag_mask) {
num_processed++;
while (!(tag_mask & 0x00000001)) {
tag++;
tag_mask <<= 1;
}
tag_mask &= (~0x00000001);
qc = ata_qc_from_tag(ap, tag);
qc->ap->link.active_tag = tag;
hsdevp->cmd_issued[tag] = SATA_DWC_CMD_ISSUED_NOT;
if (status & ATA_ERR) {
dev_dbg(ap->dev, "%s ATA_ERR (0x%x)\n", __func__,
status);
sata_dwc_qc_complete(ap, qc, 1);
handled = 1;
goto DONE;
}
dev_dbg(ap->dev, "%s NCQ command, protocol: %s\n", __func__,
get_prot_descript(qc->tf.protocol));
if (ata_is_dma(qc->tf.protocol)) {
hsdevp->dma_interrupt_count++;
if (hsdevp->dma_pending[tag] == \
SATA_DWC_DMA_PENDING_NONE)
dev_warn(ap->dev, "%s: DMA not pending?\n",
__func__);
if ((hsdevp->dma_interrupt_count % 2) == 0)
sata_dwc_dma_xfer_complete(ap, 1);
} else {
if (unlikely(sata_dwc_qc_complete(ap, qc, 1)))
goto STILLBUSY;
}
continue;
STILLBUSY:
ap->stats.idle_irq++;
dev_warn(ap->dev, "STILL BUSY IRQ ata%d: irq trap\n",
ap->print_id);
}
sata_dwc_scr_read(&ap->link, SCR_ACTIVE, &sactive2);
if (sactive2 != sactive) {
dev_dbg(ap->dev,
"More completed - sactive=0x%x sactive2=0x%x\n",
sactive, sactive2);
}
handled = 1;
DONE:
spin_unlock_irqrestore(&host->lock, flags);
return IRQ_RETVAL(handled);
}
static void sata_dwc_clear_dmacr(struct sata_dwc_device_port *hsdevp, u8 tag)
{
struct sata_dwc_device *hsdev = HSDEV_FROM_HSDEVP(hsdevp);
u32 dmacr = sata_dwc_readl(&hsdev->sata_dwc_regs->dmacr);
if (hsdevp->dma_pending[tag] == SATA_DWC_DMA_PENDING_RX) {
dmacr = SATA_DWC_DMACR_RX_CLEAR(dmacr);
sata_dwc_writel(&hsdev->sata_dwc_regs->dmacr, dmacr);
} else if (hsdevp->dma_pending[tag] == SATA_DWC_DMA_PENDING_TX) {
dmacr = SATA_DWC_DMACR_TX_CLEAR(dmacr);
sata_dwc_writel(&hsdev->sata_dwc_regs->dmacr, dmacr);
} else {
dev_err(hsdev->dev,
"%s DMA protocol RX and TX DMA not pending tag=0x%02x pending=%d dmacr: 0x%08x\n",
__func__, tag, hsdevp->dma_pending[tag], dmacr);
sata_dwc_writel(&hsdev->sata_dwc_regs->dmacr,
SATA_DWC_DMACR_TXRXCH_CLEAR);
}
}
static void sata_dwc_dma_xfer_complete(struct ata_port *ap, u32 check_status)
{
struct ata_queued_cmd *qc;
struct sata_dwc_device_port *hsdevp = HSDEVP_FROM_AP(ap);
struct sata_dwc_device *hsdev = HSDEV_FROM_AP(ap);
u8 tag = 0;
tag = ap->link.active_tag;
qc = ata_qc_from_tag(ap, tag);
if (!qc) {
dev_err(ap->dev, "failed to get qc");
return;
}
#ifdef DEBUG_NCQ
if (tag > 0) {
dev_info(ap->dev,
"%s tag=%u cmd=0x%02x dma dir=%s proto=%s dmacr=0x%08x\n",
__func__, qc->tag, qc->tf.command,
get_dma_dir_descript(qc->dma_dir),
get_prot_descript(qc->tf.protocol),
sata_dwc_readl(&hsdev->sata_dwc_regs->dmacr));
}
#endif
if (ata_is_dma(qc->tf.protocol)) {
if (hsdevp->dma_pending[tag] == SATA_DWC_DMA_PENDING_NONE) {
dev_err(ap->dev,
"%s DMA protocol RX and TX DMA not pending dmacr: 0x%08x\n",
__func__,
sata_dwc_readl(&hsdev->sata_dwc_regs->dmacr));
}
hsdevp->dma_pending[tag] = SATA_DWC_DMA_PENDING_NONE;
sata_dwc_qc_complete(ap, qc, check_status);
ap->link.active_tag = ATA_TAG_POISON;
} else {
sata_dwc_qc_complete(ap, qc, check_status);
}
}
static int sata_dwc_qc_complete(struct ata_port *ap, struct ata_queued_cmd *qc,
u32 check_status)
{
u8 status = 0;
u32 mask = 0x0;
u8 tag = qc->tag;
struct sata_dwc_device *hsdev = HSDEV_FROM_AP(ap);
struct sata_dwc_device_port *hsdevp = HSDEVP_FROM_AP(ap);
hsdev->sactive_queued = 0;
dev_dbg(ap->dev, "%s checkstatus? %x\n", __func__, check_status);
if (hsdevp->dma_pending[tag] == SATA_DWC_DMA_PENDING_TX)
dev_err(ap->dev, "TX DMA PENDING\n");
else if (hsdevp->dma_pending[tag] == SATA_DWC_DMA_PENDING_RX)
dev_err(ap->dev, "RX DMA PENDING\n");
dev_dbg(ap->dev,
"QC complete cmd=0x%02x status=0x%02x ata%u: protocol=%d\n",
qc->tf.command, status, ap->print_id, qc->tf.protocol);
mask = (~(qcmd_tag_to_mask(tag)));
hsdev->sactive_queued = hsdev->sactive_queued & mask;
hsdev->sactive_issued = hsdev->sactive_issued & mask;
ata_qc_complete(qc);
return 0;
}
static void sata_dwc_enable_interrupts(struct sata_dwc_device *hsdev)
{
sata_dwc_writel(&hsdev->sata_dwc_regs->intmr,
SATA_DWC_INTMR_ERRM |
SATA_DWC_INTMR_NEWFPM |
SATA_DWC_INTMR_PMABRTM |
SATA_DWC_INTMR_DMATM);
sata_dwc_writel(&hsdev->sata_dwc_regs->errmr, SATA_DWC_SERROR_ERR_BITS);
dev_dbg(hsdev->dev, "%s: INTMR = 0x%08x, ERRMR = 0x%08x\n",
__func__, sata_dwc_readl(&hsdev->sata_dwc_regs->intmr),
sata_dwc_readl(&hsdev->sata_dwc_regs->errmr));
}
static void sata_dwc_setup_port(struct ata_ioports *port, void __iomem *base)
{
port->cmd_addr = base + 0x00;
port->data_addr = base + 0x00;
port->error_addr = base + 0x04;
port->feature_addr = base + 0x04;
port->nsect_addr = base + 0x08;
port->lbal_addr = base + 0x0c;
port->lbam_addr = base + 0x10;
port->lbah_addr = base + 0x14;
port->device_addr = base + 0x18;
port->command_addr = base + 0x1c;
port->status_addr = base + 0x1c;
port->altstatus_addr = base + 0x20;
port->ctl_addr = base + 0x20;
}
static int sata_dwc_dma_get_channel(struct sata_dwc_device_port *hsdevp)
{
struct sata_dwc_device *hsdev = hsdevp->hsdev;
struct device *dev = hsdev->dev;
#ifdef CONFIG_SATA_DWC_OLD_DMA
if (!of_find_property(dev->of_node, "dmas", NULL))
return sata_dwc_dma_get_channel_old(hsdevp);
#endif
hsdevp->chan = dma_request_chan(dev, "sata-dma");
if (IS_ERR(hsdevp->chan)) {
dev_err(dev, "failed to allocate dma channel: %ld\n",
PTR_ERR(hsdevp->chan));
return PTR_ERR(hsdevp->chan);
}
return 0;
}
static int sata_dwc_port_start(struct ata_port *ap)
{
int err = 0;
struct sata_dwc_device *hsdev;
struct sata_dwc_device_port *hsdevp = NULL;
struct device *pdev;
int i;
hsdev = HSDEV_FROM_AP(ap);
dev_dbg(ap->dev, "%s: port_no=%d\n", __func__, ap->port_no);
hsdev->host = ap->host;
pdev = ap->host->dev;
if (!pdev) {
dev_err(ap->dev, "%s: no ap->host->dev\n", __func__);
err = -ENODEV;
goto CLEANUP;
}
hsdevp = kzalloc(sizeof(*hsdevp), GFP_KERNEL);
if (!hsdevp) {
dev_err(ap->dev, "%s: kmalloc failed for hsdevp\n", __func__);
err = -ENOMEM;
goto CLEANUP;
}
hsdevp->hsdev = hsdev;
err = sata_dwc_dma_get_channel(hsdevp);
if (err)
goto CLEANUP_ALLOC;
err = phy_power_on(hsdev->phy);
if (err)
goto CLEANUP_ALLOC;
for (i = 0; i < SATA_DWC_QCMD_MAX; i++)
hsdevp->cmd_issued[i] = SATA_DWC_CMD_ISSUED_NOT;
ap->bmdma_prd = NULL;
ap->bmdma_prd_dma = 0;
if (ap->port_no == 0) {
dev_dbg(ap->dev, "%s: clearing TXCHEN, RXCHEN in DMAC\n",
__func__);
sata_dwc_writel(&hsdev->sata_dwc_regs->dmacr,
SATA_DWC_DMACR_TXRXCH_CLEAR);
dev_dbg(ap->dev, "%s: setting burst size in DBTSR\n",
__func__);
sata_dwc_writel(&hsdev->sata_dwc_regs->dbtsr,
(SATA_DWC_DBTSR_MWR(AHB_DMA_BRST_DFLT) |
SATA_DWC_DBTSR_MRD(AHB_DMA_BRST_DFLT)));
}
clear_serror(ap);
ap->private_data = hsdevp;
dev_dbg(ap->dev, "%s: done\n", __func__);
return 0;
CLEANUP_ALLOC:
kfree(hsdevp);
CLEANUP:
dev_dbg(ap->dev, "%s: fail. ap->id = %d\n", __func__, ap->print_id);
return err;
}
static void sata_dwc_port_stop(struct ata_port *ap)
{
struct sata_dwc_device_port *hsdevp = HSDEVP_FROM_AP(ap);
struct sata_dwc_device *hsdev = HSDEV_FROM_AP(ap);
dev_dbg(ap->dev, "%s: ap->id = %d\n", __func__, ap->print_id);
dmaengine_terminate_sync(hsdevp->chan);
dma_release_channel(hsdevp->chan);
phy_power_off(hsdev->phy);
kfree(hsdevp);
ap->private_data = NULL;
}
static void sata_dwc_exec_command_by_tag(struct ata_port *ap,
struct ata_taskfile *tf,
u8 tag, u32 cmd_issued)
{
struct sata_dwc_device_port *hsdevp = HSDEVP_FROM_AP(ap);
dev_dbg(ap->dev, "%s cmd(0x%02x): %s tag=%d\n", __func__, tf->command,
ata_get_cmd_descript(tf->command), tag);
hsdevp->cmd_issued[tag] = cmd_issued;
clear_serror(ap);
ata_sff_exec_command(ap, tf);
}
static void sata_dwc_bmdma_setup_by_tag(struct ata_queued_cmd *qc, u8 tag)
{
sata_dwc_exec_command_by_tag(qc->ap, &qc->tf, tag,
SATA_DWC_CMD_ISSUED_PEND);
}
static void sata_dwc_bmdma_setup(struct ata_queued_cmd *qc)
{
u8 tag = qc->tag;
if (ata_is_ncq(qc->tf.protocol)) {
dev_dbg(qc->ap->dev, "%s: ap->link.sactive=0x%08x tag=%d\n",
__func__, qc->ap->link.sactive, tag);
} else {
tag = 0;
}
sata_dwc_bmdma_setup_by_tag(qc, tag);
}
static void sata_dwc_bmdma_start_by_tag(struct ata_queued_cmd *qc, u8 tag)
{
int start_dma;
u32 reg;
struct sata_dwc_device *hsdev = HSDEV_FROM_QC(qc);
struct ata_port *ap = qc->ap;
struct sata_dwc_device_port *hsdevp = HSDEVP_FROM_AP(ap);
struct dma_async_tx_descriptor *desc = hsdevp->desc[tag];
int dir = qc->dma_dir;
if (hsdevp->cmd_issued[tag] != SATA_DWC_CMD_ISSUED_NOT) {
start_dma = 1;
if (dir == DMA_TO_DEVICE)
hsdevp->dma_pending[tag] = SATA_DWC_DMA_PENDING_TX;
else
hsdevp->dma_pending[tag] = SATA_DWC_DMA_PENDING_RX;
} else {
dev_err(ap->dev,
"%s: Command not pending cmd_issued=%d (tag=%d) DMA NOT started\n",
__func__, hsdevp->cmd_issued[tag], tag);
start_dma = 0;
}
dev_dbg(ap->dev,
"%s qc=%p tag: %x cmd: 0x%02x dma_dir: %s start_dma? %x\n",
__func__, qc, tag, qc->tf.command,
get_dma_dir_descript(qc->dma_dir), start_dma);
sata_dwc_tf_dump(ap, &qc->tf);
if (start_dma) {
sata_dwc_scr_read(&ap->link, SCR_ERROR, &reg);
if (reg & SATA_DWC_SERROR_ERR_BITS) {
dev_err(ap->dev, "%s: ****** SError=0x%08x ******\n",
__func__, reg);
}
if (dir == DMA_TO_DEVICE)
sata_dwc_writel(&hsdev->sata_dwc_regs->dmacr,
SATA_DWC_DMACR_TXCHEN);
else
sata_dwc_writel(&hsdev->sata_dwc_regs->dmacr,
SATA_DWC_DMACR_RXCHEN);
dmaengine_submit(desc);
dma_async_issue_pending(hsdevp->chan);
}
}
static void sata_dwc_bmdma_start(struct ata_queued_cmd *qc)
{
u8 tag = qc->tag;
if (ata_is_ncq(qc->tf.protocol)) {
dev_dbg(qc->ap->dev, "%s: ap->link.sactive=0x%08x tag=%d\n",
__func__, qc->ap->link.sactive, tag);
} else {
tag = 0;
}
dev_dbg(qc->ap->dev, "%s\n", __func__);
sata_dwc_bmdma_start_by_tag(qc, tag);
}
static unsigned int sata_dwc_qc_issue(struct ata_queued_cmd *qc)
{
u32 sactive;
u8 tag = qc->tag;
struct ata_port *ap = qc->ap;
struct sata_dwc_device_port *hsdevp = HSDEVP_FROM_AP(ap);
#ifdef DEBUG_NCQ
if (qc->tag > 0 || ap->link.sactive > 1)
dev_info(ap->dev,
"%s ap id=%d cmd(0x%02x)=%s qc tag=%d prot=%s ap active_tag=0x%08x ap sactive=0x%08x\n",
__func__, ap->print_id, qc->tf.command,
ata_get_cmd_descript(qc->tf.command),
qc->tag, get_prot_descript(qc->tf.protocol),
ap->link.active_tag, ap->link.sactive);
#endif
if (!ata_is_ncq(qc->tf.protocol))
tag = 0;
if (ata_is_dma(qc->tf.protocol)) {
hsdevp->desc[tag] = dma_dwc_xfer_setup(qc);
if (!hsdevp->desc[tag])
return AC_ERR_SYSTEM;
} else {
hsdevp->desc[tag] = NULL;
}
if (ata_is_ncq(qc->tf.protocol)) {
sata_dwc_scr_read(&ap->link, SCR_ACTIVE, &sactive);
sactive |= (0x00000001 << tag);
sata_dwc_scr_write(&ap->link, SCR_ACTIVE, sactive);
dev_dbg(qc->ap->dev,
"%s: tag=%d ap->link.sactive = 0x%08x sactive=0x%08x\n",
__func__, tag, qc->ap->link.sactive, sactive);
ap->ops->sff_tf_load(ap, &qc->tf);
sata_dwc_exec_command_by_tag(ap, &qc->tf, tag,
SATA_DWC_CMD_ISSUED_PEND);
} else {
return ata_bmdma_qc_issue(qc);
}
return 0;
}
static void sata_dwc_error_handler(struct ata_port *ap)
{
ata_sff_error_handler(ap);
}
static int sata_dwc_hardreset(struct ata_link *link, unsigned int *class,
unsigned long deadline)
{
struct sata_dwc_device *hsdev = HSDEV_FROM_AP(link->ap);
int ret;
ret = sata_sff_hardreset(link, class, deadline);
sata_dwc_enable_interrupts(hsdev);
sata_dwc_writel(&hsdev->sata_dwc_regs->dmacr,
SATA_DWC_DMACR_TXRXCH_CLEAR);
sata_dwc_writel(&hsdev->sata_dwc_regs->dbtsr,
SATA_DWC_DBTSR_MWR(AHB_DMA_BRST_DFLT) |
SATA_DWC_DBTSR_MRD(AHB_DMA_BRST_DFLT));
return ret;
}
static void sata_dwc_dev_select(struct ata_port *ap, unsigned int device)
{
}
static int sata_dwc_probe(struct platform_device *ofdev)
{
struct sata_dwc_device *hsdev;
u32 idr, versionr;
char *ver = (char *)&versionr;
void __iomem *base;
int err = 0;
int irq;
struct ata_host *host;
struct ata_port_info pi = sata_dwc_port_info[0];
const struct ata_port_info *ppi[] = { &pi, NULL };
struct device_node *np = ofdev->dev.of_node;
struct resource *res;
host = ata_host_alloc_pinfo(&ofdev->dev, ppi, SATA_DWC_MAX_PORTS);
hsdev = devm_kzalloc(&ofdev->dev, sizeof(*hsdev), GFP_KERNEL);
if (!host || !hsdev)
return -ENOMEM;
host->private_data = hsdev;
res = platform_get_resource(ofdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&ofdev->dev, res);
if (IS_ERR(base)) {
dev_err(&ofdev->dev,
"ioremap failed for SATA register address\n");
return PTR_ERR(base);
}
dev_dbg(&ofdev->dev, "ioremap done for SATA register address\n");
hsdev->sata_dwc_regs = base + SATA_DWC_REG_OFFSET;
hsdev->dmadr = res->start + SATA_DWC_REG_OFFSET + offsetof(struct sata_dwc_regs, dmadr);
host->ports[0]->ioaddr.cmd_addr = base;
host->ports[0]->ioaddr.scr_addr = base + SATA_DWC_SCR_OFFSET;
sata_dwc_setup_port(&host->ports[0]->ioaddr, base);
idr = sata_dwc_readl(&hsdev->sata_dwc_regs->idr);
versionr = sata_dwc_readl(&hsdev->sata_dwc_regs->versionr);
dev_notice(&ofdev->dev, "id %d, controller version %c.%c%c\n",
idr, ver[0], ver[1], ver[2]);
hsdev->dev = &ofdev->dev;
sata_dwc_enable_interrupts(hsdev);
irq = irq_of_parse_and_map(np, 0);
if (irq == NO_IRQ) {
dev_err(&ofdev->dev, "no SATA DMA irq\n");
err = -ENODEV;
goto error_out;
}
#ifdef CONFIG_SATA_DWC_OLD_DMA
if (!of_find_property(np, "dmas", NULL)) {
err = sata_dwc_dma_init_old(ofdev, hsdev);
if (err)
goto error_out;
}
#endif
hsdev->phy = devm_phy_optional_get(hsdev->dev, "sata-phy");
if (IS_ERR(hsdev->phy)) {
err = PTR_ERR(hsdev->phy);
hsdev->phy = NULL;
goto error_out;
}
err = phy_init(hsdev->phy);
if (err)
goto error_out;
err = ata_host_activate(host, irq, sata_dwc_isr, 0, &sata_dwc_sht);
if (err)
dev_err(&ofdev->dev, "failed to activate host");
dev_set_drvdata(&ofdev->dev, host);
return 0;
error_out:
phy_exit(hsdev->phy);
return err;
}
static int sata_dwc_remove(struct platform_device *ofdev)
{
struct device *dev = &ofdev->dev;
struct ata_host *host = dev_get_drvdata(dev);
struct sata_dwc_device *hsdev = host->private_data;
ata_host_detach(host);
phy_exit(hsdev->phy);
#ifdef CONFIG_SATA_DWC_OLD_DMA
sata_dwc_dma_exit_old(hsdev);
#endif
dev_dbg(&ofdev->dev, "done\n");
return 0;
}
