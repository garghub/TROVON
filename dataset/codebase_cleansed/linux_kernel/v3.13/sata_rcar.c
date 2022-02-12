static void sata_rcar_phy_initialize(struct sata_rcar_priv *priv)
{
void __iomem *base = priv->base;
iowrite32(0, base + SATAPHYADDR_REG);
iowrite32(SATAPHYRESET_PHYRST, base + SATAPHYRESET_REG);
udelay(10);
iowrite32(0, base + SATAPHYRESET_REG);
}
static void sata_rcar_phy_write(struct sata_rcar_priv *priv, u16 reg, u32 val,
int group)
{
void __iomem *base = priv->base;
int timeout;
iowrite32(0, base + SATAPHYRESET_REG);
iowrite32(SATAPHYACCEN_PHYLANE, base + SATAPHYACCEN_REG);
iowrite32(val, base + SATAPHYWDATA_REG);
if (group)
reg |= SATAPHYADDR_PHYRATEMODE;
iowrite32(SATAPHYADDR_PHYCMD_WRITE | reg, base + SATAPHYADDR_REG);
for (timeout = 0; timeout < 100; timeout++) {
val = ioread32(base + SATAPHYACK_REG);
if (val & SATAPHYACK_PHYACK)
break;
}
if (timeout >= 100)
pr_err("%s timeout\n", __func__);
iowrite32(0, base + SATAPHYADDR_REG);
}
static void sata_rcar_freeze(struct ata_port *ap)
{
struct sata_rcar_priv *priv = ap->host->private_data;
iowrite32(0x7ff, priv->base + SATAINTMASK_REG);
ata_sff_freeze(ap);
}
static void sata_rcar_thaw(struct ata_port *ap)
{
struct sata_rcar_priv *priv = ap->host->private_data;
void __iomem *base = priv->base;
iowrite32(~(u32)SATA_RCAR_INT_MASK, base + SATAINTSTAT_REG);
ata_sff_thaw(ap);
iowrite32(0x7ff & ~SATA_RCAR_INT_MASK, base + SATAINTMASK_REG);
}
static void sata_rcar_ioread16_rep(void __iomem *reg, void *buffer, int count)
{
u16 *ptr = buffer;
while (count--) {
u16 data = ioread32(reg);
*ptr++ = data;
}
}
static void sata_rcar_iowrite16_rep(void __iomem *reg, void *buffer, int count)
{
const u16 *ptr = buffer;
while (count--)
iowrite32(*ptr++, reg);
}
static u8 sata_rcar_check_status(struct ata_port *ap)
{
return ioread32(ap->ioaddr.status_addr);
}
static u8 sata_rcar_check_altstatus(struct ata_port *ap)
{
return ioread32(ap->ioaddr.altstatus_addr);
}
static void sata_rcar_set_devctl(struct ata_port *ap, u8 ctl)
{
iowrite32(ctl, ap->ioaddr.ctl_addr);
}
static void sata_rcar_dev_select(struct ata_port *ap, unsigned int device)
{
iowrite32(ATA_DEVICE_OBS, ap->ioaddr.device_addr);
ata_sff_pause(ap);
}
static unsigned int sata_rcar_ata_devchk(struct ata_port *ap,
unsigned int device)
{
struct ata_ioports *ioaddr = &ap->ioaddr;
u8 nsect, lbal;
sata_rcar_dev_select(ap, device);
iowrite32(0x55, ioaddr->nsect_addr);
iowrite32(0xaa, ioaddr->lbal_addr);
iowrite32(0xaa, ioaddr->nsect_addr);
iowrite32(0x55, ioaddr->lbal_addr);
iowrite32(0x55, ioaddr->nsect_addr);
iowrite32(0xaa, ioaddr->lbal_addr);
nsect = ioread32(ioaddr->nsect_addr);
lbal = ioread32(ioaddr->lbal_addr);
if (nsect == 0x55 && lbal == 0xaa)
return 1;
return 0;
}
static int sata_rcar_wait_after_reset(struct ata_link *link,
unsigned long deadline)
{
struct ata_port *ap = link->ap;
ata_msleep(ap, ATA_WAIT_AFTER_RESET);
return ata_sff_wait_ready(link, deadline);
}
static int sata_rcar_bus_softreset(struct ata_port *ap, unsigned long deadline)
{
struct ata_ioports *ioaddr = &ap->ioaddr;
DPRINTK("ata%u: bus reset via SRST\n", ap->print_id);
iowrite32(ap->ctl, ioaddr->ctl_addr);
udelay(20);
iowrite32(ap->ctl | ATA_SRST, ioaddr->ctl_addr);
udelay(20);
iowrite32(ap->ctl, ioaddr->ctl_addr);
ap->last_ctl = ap->ctl;
return sata_rcar_wait_after_reset(&ap->link, deadline);
}
static int sata_rcar_softreset(struct ata_link *link, unsigned int *classes,
unsigned long deadline)
{
struct ata_port *ap = link->ap;
unsigned int devmask = 0;
int rc;
u8 err;
if (sata_rcar_ata_devchk(ap, 0))
devmask |= 1 << 0;
DPRINTK("about to softreset, devmask=%x\n", devmask);
rc = sata_rcar_bus_softreset(ap, deadline);
if (rc && (rc != -ENODEV || sata_scr_valid(link))) {
ata_link_err(link, "SRST failed (errno=%d)\n", rc);
return rc;
}
classes[0] = ata_sff_dev_classify(&link->device[0], devmask, &err);
DPRINTK("classes[0]=%u\n", classes[0]);
return 0;
}
static void sata_rcar_tf_load(struct ata_port *ap,
const struct ata_taskfile *tf)
{
struct ata_ioports *ioaddr = &ap->ioaddr;
unsigned int is_addr = tf->flags & ATA_TFLAG_ISADDR;
if (tf->ctl != ap->last_ctl) {
iowrite32(tf->ctl, ioaddr->ctl_addr);
ap->last_ctl = tf->ctl;
ata_wait_idle(ap);
}
if (is_addr && (tf->flags & ATA_TFLAG_LBA48)) {
iowrite32(tf->hob_feature, ioaddr->feature_addr);
iowrite32(tf->hob_nsect, ioaddr->nsect_addr);
iowrite32(tf->hob_lbal, ioaddr->lbal_addr);
iowrite32(tf->hob_lbam, ioaddr->lbam_addr);
iowrite32(tf->hob_lbah, ioaddr->lbah_addr);
VPRINTK("hob: feat 0x%X nsect 0x%X, lba 0x%X 0x%X 0x%X\n",
tf->hob_feature,
tf->hob_nsect,
tf->hob_lbal,
tf->hob_lbam,
tf->hob_lbah);
}
if (is_addr) {
iowrite32(tf->feature, ioaddr->feature_addr);
iowrite32(tf->nsect, ioaddr->nsect_addr);
iowrite32(tf->lbal, ioaddr->lbal_addr);
iowrite32(tf->lbam, ioaddr->lbam_addr);
iowrite32(tf->lbah, ioaddr->lbah_addr);
VPRINTK("feat 0x%X nsect 0x%X lba 0x%X 0x%X 0x%X\n",
tf->feature,
tf->nsect,
tf->lbal,
tf->lbam,
tf->lbah);
}
if (tf->flags & ATA_TFLAG_DEVICE) {
iowrite32(tf->device, ioaddr->device_addr);
VPRINTK("device 0x%X\n", tf->device);
}
ata_wait_idle(ap);
}
static void sata_rcar_tf_read(struct ata_port *ap, struct ata_taskfile *tf)
{
struct ata_ioports *ioaddr = &ap->ioaddr;
tf->command = sata_rcar_check_status(ap);
tf->feature = ioread32(ioaddr->error_addr);
tf->nsect = ioread32(ioaddr->nsect_addr);
tf->lbal = ioread32(ioaddr->lbal_addr);
tf->lbam = ioread32(ioaddr->lbam_addr);
tf->lbah = ioread32(ioaddr->lbah_addr);
tf->device = ioread32(ioaddr->device_addr);
if (tf->flags & ATA_TFLAG_LBA48) {
iowrite32(tf->ctl | ATA_HOB, ioaddr->ctl_addr);
tf->hob_feature = ioread32(ioaddr->error_addr);
tf->hob_nsect = ioread32(ioaddr->nsect_addr);
tf->hob_lbal = ioread32(ioaddr->lbal_addr);
tf->hob_lbam = ioread32(ioaddr->lbam_addr);
tf->hob_lbah = ioread32(ioaddr->lbah_addr);
iowrite32(tf->ctl, ioaddr->ctl_addr);
ap->last_ctl = tf->ctl;
}
}
static void sata_rcar_exec_command(struct ata_port *ap,
const struct ata_taskfile *tf)
{
DPRINTK("ata%u: cmd 0x%X\n", ap->print_id, tf->command);
iowrite32(tf->command, ap->ioaddr.command_addr);
ata_sff_pause(ap);
}
static unsigned int sata_rcar_data_xfer(struct ata_device *dev,
unsigned char *buf,
unsigned int buflen, int rw)
{
struct ata_port *ap = dev->link->ap;
void __iomem *data_addr = ap->ioaddr.data_addr;
unsigned int words = buflen >> 1;
if (rw == READ)
sata_rcar_ioread16_rep(data_addr, buf, words);
else
sata_rcar_iowrite16_rep(data_addr, buf, words);
if (unlikely(buflen & 0x01)) {
unsigned char pad[2] = { };
buf += buflen - 1;
if (rw == READ) {
sata_rcar_ioread16_rep(data_addr, pad, 1);
*buf = pad[0];
} else {
pad[0] = *buf;
sata_rcar_iowrite16_rep(data_addr, pad, 1);
}
words++;
}
return words << 1;
}
static void sata_rcar_drain_fifo(struct ata_queued_cmd *qc)
{
int count;
struct ata_port *ap;
if (qc == NULL || qc->dma_dir == DMA_TO_DEVICE)
return;
ap = qc->ap;
for (count = 0; (ap->ops->sff_check_status(ap) & ATA_DRQ) &&
count < 65536; count += 2)
ioread32(ap->ioaddr.data_addr);
if (count)
ata_port_dbg(ap, "drained %d bytes to clear DRQ\n", count);
}
static int sata_rcar_scr_read(struct ata_link *link, unsigned int sc_reg,
u32 *val)
{
if (sc_reg > SCR_ACTIVE)
return -EINVAL;
*val = ioread32(link->ap->ioaddr.scr_addr + (sc_reg << 2));
return 0;
}
static int sata_rcar_scr_write(struct ata_link *link, unsigned int sc_reg,
u32 val)
{
if (sc_reg > SCR_ACTIVE)
return -EINVAL;
iowrite32(val, link->ap->ioaddr.scr_addr + (sc_reg << 2));
return 0;
}
static void sata_rcar_bmdma_fill_sg(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct ata_bmdma_prd *prd = ap->bmdma_prd;
struct scatterlist *sg;
unsigned int si;
for_each_sg(qc->sg, sg, qc->n_elem, si) {
u32 addr, sg_len;
addr = (u32)sg_dma_address(sg);
sg_len = sg_dma_len(sg);
prd[si].addr = cpu_to_le32(addr);
prd[si].flags_len = cpu_to_le32(sg_len);
VPRINTK("PRD[%u] = (0x%X, 0x%X)\n", si, addr, sg_len);
}
prd[si - 1].addr |= cpu_to_le32(SATA_RCAR_DTEND);
}
static void sata_rcar_qc_prep(struct ata_queued_cmd *qc)
{
if (!(qc->flags & ATA_QCFLAG_DMAMAP))
return;
sata_rcar_bmdma_fill_sg(qc);
}
static void sata_rcar_bmdma_setup(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
unsigned int rw = qc->tf.flags & ATA_TFLAG_WRITE;
struct sata_rcar_priv *priv = ap->host->private_data;
void __iomem *base = priv->base;
u32 dmactl;
mb();
iowrite32(ap->bmdma_prd_dma, base + ATAPI_DTB_ADR_REG);
dmactl = ioread32(base + ATAPI_CONTROL1_REG);
dmactl &= ~(ATAPI_CONTROL1_RW | ATAPI_CONTROL1_STOP);
if (dmactl & ATAPI_CONTROL1_START) {
dmactl &= ~ATAPI_CONTROL1_START;
dmactl |= ATAPI_CONTROL1_STOP;
}
if (!rw)
dmactl |= ATAPI_CONTROL1_RW;
iowrite32(dmactl, base + ATAPI_CONTROL1_REG);
ap->ops->sff_exec_command(ap, &qc->tf);
}
static void sata_rcar_bmdma_start(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct sata_rcar_priv *priv = ap->host->private_data;
void __iomem *base = priv->base;
u32 dmactl;
dmactl = ioread32(base + ATAPI_CONTROL1_REG);
dmactl &= ~ATAPI_CONTROL1_STOP;
dmactl |= ATAPI_CONTROL1_START;
iowrite32(dmactl, base + ATAPI_CONTROL1_REG);
}
static void sata_rcar_bmdma_stop(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct sata_rcar_priv *priv = ap->host->private_data;
void __iomem *base = priv->base;
u32 dmactl;
dmactl = ioread32(base + ATAPI_CONTROL1_REG);
if (dmactl & ATAPI_CONTROL1_START) {
dmactl &= ~ATAPI_CONTROL1_START;
dmactl |= ATAPI_CONTROL1_STOP;
iowrite32(dmactl, base + ATAPI_CONTROL1_REG);
}
ata_sff_dma_pause(ap);
}
static u8 sata_rcar_bmdma_status(struct ata_port *ap)
{
struct sata_rcar_priv *priv = ap->host->private_data;
u8 host_stat = 0;
u32 status;
status = ioread32(priv->base + ATAPI_STATUS_REG);
if (status & ATAPI_STATUS_DEVINT)
host_stat |= ATA_DMA_INTR;
if (status & ATAPI_STATUS_ACT)
host_stat |= ATA_DMA_ACTIVE;
return host_stat;
}
static void sata_rcar_serr_interrupt(struct ata_port *ap)
{
struct sata_rcar_priv *priv = ap->host->private_data;
struct ata_eh_info *ehi = &ap->link.eh_info;
int freeze = 0;
u32 serror;
serror = ioread32(priv->base + SCRSERR_REG);
if (!serror)
return;
DPRINTK("SError @host_intr: 0x%x\n", serror);
ata_ehi_clear_desc(ehi);
if (serror & (SERR_DEV_XCHG | SERR_PHYRDY_CHG)) {
ata_ehi_hotplugged(ehi);
ata_ehi_push_desc(ehi, "%s", "hotplug");
freeze = serror & SERR_COMM_WAKE ? 0 : 1;
}
if (freeze)
ata_port_freeze(ap);
else
ata_port_abort(ap);
}
static void sata_rcar_ata_interrupt(struct ata_port *ap)
{
struct ata_queued_cmd *qc;
int handled = 0;
qc = ata_qc_from_tag(ap, ap->link.active_tag);
if (qc)
handled |= ata_bmdma_port_intr(ap, qc);
if (!handled)
sata_rcar_check_status(ap);
}
static irqreturn_t sata_rcar_interrupt(int irq, void *dev_instance)
{
struct ata_host *host = dev_instance;
struct sata_rcar_priv *priv = host->private_data;
void __iomem *base = priv->base;
unsigned int handled = 0;
struct ata_port *ap;
u32 sataintstat;
unsigned long flags;
spin_lock_irqsave(&host->lock, flags);
sataintstat = ioread32(base + SATAINTSTAT_REG);
sataintstat &= SATA_RCAR_INT_MASK;
if (!sataintstat)
goto done;
iowrite32(~sataintstat & 0x7ff, base + SATAINTSTAT_REG);
ap = host->ports[0];
if (sataintstat & SATAINTSTAT_ATA)
sata_rcar_ata_interrupt(ap);
if (sataintstat & SATAINTSTAT_SERR)
sata_rcar_serr_interrupt(ap);
handled = 1;
done:
spin_unlock_irqrestore(&host->lock, flags);
return IRQ_RETVAL(handled);
}
static void sata_rcar_setup_port(struct ata_host *host)
{
struct ata_port *ap = host->ports[0];
struct ata_ioports *ioaddr = &ap->ioaddr;
struct sata_rcar_priv *priv = host->private_data;
void __iomem *base = priv->base;
ap->ops = &sata_rcar_port_ops;
ap->pio_mask = ATA_PIO4;
ap->udma_mask = ATA_UDMA6;
ap->flags |= ATA_FLAG_SATA;
ioaddr->cmd_addr = base + SDATA_REG;
ioaddr->ctl_addr = base + SSDEVCON_REG;
ioaddr->scr_addr = base + SCRSSTS_REG;
ioaddr->altstatus_addr = ioaddr->ctl_addr;
ioaddr->data_addr = ioaddr->cmd_addr + (ATA_REG_DATA << 2);
ioaddr->error_addr = ioaddr->cmd_addr + (ATA_REG_ERR << 2);
ioaddr->feature_addr = ioaddr->cmd_addr + (ATA_REG_FEATURE << 2);
ioaddr->nsect_addr = ioaddr->cmd_addr + (ATA_REG_NSECT << 2);
ioaddr->lbal_addr = ioaddr->cmd_addr + (ATA_REG_LBAL << 2);
ioaddr->lbam_addr = ioaddr->cmd_addr + (ATA_REG_LBAM << 2);
ioaddr->lbah_addr = ioaddr->cmd_addr + (ATA_REG_LBAH << 2);
ioaddr->device_addr = ioaddr->cmd_addr + (ATA_REG_DEVICE << 2);
ioaddr->status_addr = ioaddr->cmd_addr + (ATA_REG_STATUS << 2);
ioaddr->command_addr = ioaddr->cmd_addr + (ATA_REG_CMD << 2);
}
static void sata_rcar_init_controller(struct ata_host *host)
{
struct sata_rcar_priv *priv = host->private_data;
void __iomem *base = priv->base;
u32 val;
sata_rcar_phy_initialize(priv);
sata_rcar_phy_write(priv, SATAPCTLR1_REG, 0x00200188, 0);
sata_rcar_phy_write(priv, SATAPCTLR1_REG, 0x00200188, 1);
sata_rcar_phy_write(priv, SATAPCTLR3_REG, 0x0000A061, 0);
sata_rcar_phy_write(priv, SATAPCTLR2_REG, 0x20000000, 0);
sata_rcar_phy_write(priv, SATAPCTLR2_REG, 0x20000000, 1);
sata_rcar_phy_write(priv, SATAPCTLR4_REG, 0x28E80000, 0);
val = ioread32(base + ATAPI_CONTROL1_REG);
val |= ATAPI_CONTROL1_RESET;
iowrite32(val, base + ATAPI_CONTROL1_REG);
val = ioread32(base + ATAPI_CONTROL1_REG);
val |= ATAPI_CONTROL1_ISM;
val |= ATAPI_CONTROL1_DESE;
val |= ATAPI_CONTROL1_DTA32M;
iowrite32(val, base + ATAPI_CONTROL1_REG);
val = ioread32(base + ATAPI_CONTROL1_REG);
val &= ~ATAPI_CONTROL1_RESET;
iowrite32(val, base + ATAPI_CONTROL1_REG);
iowrite32(0, base + SATAINTSTAT_REG);
iowrite32(0x7ff, base + SATAINTMASK_REG);
iowrite32(ATAPI_INT_ENABLE_SATAINT, base + ATAPI_INT_ENABLE_REG);
}
static int sata_rcar_probe(struct platform_device *pdev)
{
struct ata_host *host;
struct sata_rcar_priv *priv;
struct resource *mem;
int irq;
int ret = 0;
irq = platform_get_irq(pdev, 0);
if (irq <= 0)
return -EINVAL;
priv = devm_kzalloc(&pdev->dev, sizeof(struct sata_rcar_priv),
GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(priv->clk)) {
dev_err(&pdev->dev, "failed to get access to sata clock\n");
return PTR_ERR(priv->clk);
}
clk_prepare_enable(priv->clk);
host = ata_host_alloc(&pdev->dev, 1);
if (!host) {
dev_err(&pdev->dev, "ata_host_alloc failed\n");
ret = -ENOMEM;
goto cleanup;
}
host->private_data = priv;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(priv->base)) {
ret = PTR_ERR(priv->base);
goto cleanup;
}
sata_rcar_setup_port(host);
sata_rcar_init_controller(host);
ret = ata_host_activate(host, irq, sata_rcar_interrupt, 0,
&sata_rcar_sht);
if (!ret)
return 0;
cleanup:
clk_disable_unprepare(priv->clk);
return ret;
}
static int sata_rcar_remove(struct platform_device *pdev)
{
struct ata_host *host = platform_get_drvdata(pdev);
struct sata_rcar_priv *priv = host->private_data;
void __iomem *base = priv->base;
ata_host_detach(host);
iowrite32(0, base + ATAPI_INT_ENABLE_REG);
iowrite32(0, base + SATAINTSTAT_REG);
iowrite32(0x7ff, base + SATAINTMASK_REG);
clk_disable_unprepare(priv->clk);
return 0;
}
static int sata_rcar_suspend(struct device *dev)
{
struct ata_host *host = dev_get_drvdata(dev);
struct sata_rcar_priv *priv = host->private_data;
void __iomem *base = priv->base;
int ret;
ret = ata_host_suspend(host, PMSG_SUSPEND);
if (!ret) {
iowrite32(0, base + ATAPI_INT_ENABLE_REG);
iowrite32(0x7ff, base + SATAINTMASK_REG);
clk_disable_unprepare(priv->clk);
}
return ret;
}
static int sata_rcar_resume(struct device *dev)
{
struct ata_host *host = dev_get_drvdata(dev);
struct sata_rcar_priv *priv = host->private_data;
void __iomem *base = priv->base;
clk_prepare_enable(priv->clk);
iowrite32(0, base + SATAINTSTAT_REG);
iowrite32(0x7ff, base + SATAINTMASK_REG);
iowrite32(ATAPI_INT_ENABLE_SATAINT, base + ATAPI_INT_ENABLE_REG);
ata_host_resume(host);
return 0;
}
