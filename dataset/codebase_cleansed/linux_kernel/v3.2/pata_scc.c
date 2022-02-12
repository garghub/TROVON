static void scc_set_piomode (struct ata_port *ap, struct ata_device *adev)
{
unsigned int pio = adev->pio_mode - XFER_PIO_0;
void __iomem *ctrl_base = ap->host->iomap[SCC_CTRL_BAR];
void __iomem *cckctrl_port = ctrl_base + SCC_CTL_CCKCTRL;
void __iomem *piosht_port = ctrl_base + SCC_CTL_PIOSHT;
void __iomem *pioct_port = ctrl_base + SCC_CTL_PIOCT;
unsigned long reg;
int offset;
reg = in_be32(cckctrl_port);
if (reg & CCKCTRL_ATACLKOEN)
offset = 1;
else
offset = 0;
reg = JCHSTtbl[offset][pio] << 16 | JCHHTtbl[offset][pio];
out_be32(piosht_port, reg);
reg = JCHCTtbl[offset][pio];
out_be32(pioct_port, reg);
}
static void scc_set_dmamode (struct ata_port *ap, struct ata_device *adev)
{
unsigned int udma = adev->dma_mode;
unsigned int is_slave = (adev->devno != 0);
u8 speed = udma;
void __iomem *ctrl_base = ap->host->iomap[SCC_CTRL_BAR];
void __iomem *cckctrl_port = ctrl_base + SCC_CTL_CCKCTRL;
void __iomem *mdmact_port = ctrl_base + SCC_CTL_MDMACT;
void __iomem *mcrcst_port = ctrl_base + SCC_CTL_MCRCST;
void __iomem *sdmact_port = ctrl_base + SCC_CTL_SDMACT;
void __iomem *scrcst_port = ctrl_base + SCC_CTL_SCRCST;
void __iomem *udenvt_port = ctrl_base + SCC_CTL_UDENVT;
void __iomem *tdvhsel_port = ctrl_base + SCC_CTL_TDVHSEL;
int offset, idx;
if (in_be32(cckctrl_port) & CCKCTRL_ATACLKOEN)
offset = 1;
else
offset = 0;
if (speed >= XFER_UDMA_0)
idx = speed - XFER_UDMA_0;
else
return;
if (is_slave) {
out_be32(sdmact_port, JCHDCTxtbl[offset][idx]);
out_be32(scrcst_port, JCSTWTxtbl[offset][idx]);
out_be32(tdvhsel_port,
(in_be32(tdvhsel_port) & ~TDVHSEL_SLAVE) | (JCACTSELtbl[offset][idx] << 2));
} else {
out_be32(mdmact_port, JCHDCTxtbl[offset][idx]);
out_be32(mcrcst_port, JCSTWTxtbl[offset][idx]);
out_be32(tdvhsel_port,
(in_be32(tdvhsel_port) & ~TDVHSEL_MASTER) | JCACTSELtbl[offset][idx]);
}
out_be32(udenvt_port,
JCTSStbl[offset][idx] << 16 | JCENVTtbl[offset][idx]);
}
unsigned long scc_mode_filter(struct ata_device *adev, unsigned long mask)
{
if (adev->class == ATA_DEV_ATAPI &&
(mask & (0xE0 << ATA_SHIFT_UDMA))) {
printk(KERN_INFO "%s: limit ATAPI UDMA to UDMA4\n", DRV_NAME);
mask &= ~(0xE0 << ATA_SHIFT_UDMA);
}
return mask;
}
static void scc_tf_load (struct ata_port *ap, const struct ata_taskfile *tf)
{
struct ata_ioports *ioaddr = &ap->ioaddr;
unsigned int is_addr = tf->flags & ATA_TFLAG_ISADDR;
if (tf->ctl != ap->last_ctl) {
out_be32(ioaddr->ctl_addr, tf->ctl);
ap->last_ctl = tf->ctl;
ata_wait_idle(ap);
}
if (is_addr && (tf->flags & ATA_TFLAG_LBA48)) {
out_be32(ioaddr->feature_addr, tf->hob_feature);
out_be32(ioaddr->nsect_addr, tf->hob_nsect);
out_be32(ioaddr->lbal_addr, tf->hob_lbal);
out_be32(ioaddr->lbam_addr, tf->hob_lbam);
out_be32(ioaddr->lbah_addr, tf->hob_lbah);
VPRINTK("hob: feat 0x%X nsect 0x%X, lba 0x%X 0x%X 0x%X\n",
tf->hob_feature,
tf->hob_nsect,
tf->hob_lbal,
tf->hob_lbam,
tf->hob_lbah);
}
if (is_addr) {
out_be32(ioaddr->feature_addr, tf->feature);
out_be32(ioaddr->nsect_addr, tf->nsect);
out_be32(ioaddr->lbal_addr, tf->lbal);
out_be32(ioaddr->lbam_addr, tf->lbam);
out_be32(ioaddr->lbah_addr, tf->lbah);
VPRINTK("feat 0x%X nsect 0x%X lba 0x%X 0x%X 0x%X\n",
tf->feature,
tf->nsect,
tf->lbal,
tf->lbam,
tf->lbah);
}
if (tf->flags & ATA_TFLAG_DEVICE) {
out_be32(ioaddr->device_addr, tf->device);
VPRINTK("device 0x%X\n", tf->device);
}
ata_wait_idle(ap);
}
static u8 scc_check_status (struct ata_port *ap)
{
return in_be32(ap->ioaddr.status_addr);
}
static void scc_tf_read (struct ata_port *ap, struct ata_taskfile *tf)
{
struct ata_ioports *ioaddr = &ap->ioaddr;
tf->command = scc_check_status(ap);
tf->feature = in_be32(ioaddr->error_addr);
tf->nsect = in_be32(ioaddr->nsect_addr);
tf->lbal = in_be32(ioaddr->lbal_addr);
tf->lbam = in_be32(ioaddr->lbam_addr);
tf->lbah = in_be32(ioaddr->lbah_addr);
tf->device = in_be32(ioaddr->device_addr);
if (tf->flags & ATA_TFLAG_LBA48) {
out_be32(ioaddr->ctl_addr, tf->ctl | ATA_HOB);
tf->hob_feature = in_be32(ioaddr->error_addr);
tf->hob_nsect = in_be32(ioaddr->nsect_addr);
tf->hob_lbal = in_be32(ioaddr->lbal_addr);
tf->hob_lbam = in_be32(ioaddr->lbam_addr);
tf->hob_lbah = in_be32(ioaddr->lbah_addr);
out_be32(ioaddr->ctl_addr, tf->ctl);
ap->last_ctl = tf->ctl;
}
}
static void scc_exec_command (struct ata_port *ap,
const struct ata_taskfile *tf)
{
DPRINTK("ata%u: cmd 0x%X\n", ap->print_id, tf->command);
out_be32(ap->ioaddr.command_addr, tf->command);
ata_sff_pause(ap);
}
static u8 scc_check_altstatus (struct ata_port *ap)
{
return in_be32(ap->ioaddr.altstatus_addr);
}
static void scc_dev_select (struct ata_port *ap, unsigned int device)
{
u8 tmp;
if (device == 0)
tmp = ATA_DEVICE_OBS;
else
tmp = ATA_DEVICE_OBS | ATA_DEV1;
out_be32(ap->ioaddr.device_addr, tmp);
ata_sff_pause(ap);
}
static void scc_set_devctl(struct ata_port *ap, u8 ctl)
{
out_be32(ap->ioaddr.ctl_addr, ctl);
}
static void scc_bmdma_setup (struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
unsigned int rw = (qc->tf.flags & ATA_TFLAG_WRITE);
u8 dmactl;
void __iomem *mmio = ap->ioaddr.bmdma_addr;
out_be32(mmio + SCC_DMA_TABLE_OFS, ap->bmdma_prd_dma);
dmactl = in_be32(mmio + SCC_DMA_CMD);
dmactl &= ~(ATA_DMA_WR | ATA_DMA_START);
if (!rw)
dmactl |= ATA_DMA_WR;
out_be32(mmio + SCC_DMA_CMD, dmactl);
ap->ops->sff_exec_command(ap, &qc->tf);
}
static void scc_bmdma_start (struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
u8 dmactl;
void __iomem *mmio = ap->ioaddr.bmdma_addr;
dmactl = in_be32(mmio + SCC_DMA_CMD);
out_be32(mmio + SCC_DMA_CMD, dmactl | ATA_DMA_START);
}
static unsigned int scc_devchk (struct ata_port *ap,
unsigned int device)
{
struct ata_ioports *ioaddr = &ap->ioaddr;
u8 nsect, lbal;
ap->ops->sff_dev_select(ap, device);
out_be32(ioaddr->nsect_addr, 0x55);
out_be32(ioaddr->lbal_addr, 0xaa);
out_be32(ioaddr->nsect_addr, 0xaa);
out_be32(ioaddr->lbal_addr, 0x55);
out_be32(ioaddr->nsect_addr, 0x55);
out_be32(ioaddr->lbal_addr, 0xaa);
nsect = in_be32(ioaddr->nsect_addr);
lbal = in_be32(ioaddr->lbal_addr);
if ((nsect == 0x55) && (lbal == 0xaa))
return 1;
return 0;
}
static int scc_wait_after_reset(struct ata_link *link, unsigned int devmask,
unsigned long deadline)
{
struct ata_port *ap = link->ap;
struct ata_ioports *ioaddr = &ap->ioaddr;
unsigned int dev0 = devmask & (1 << 0);
unsigned int dev1 = devmask & (1 << 1);
int rc, ret = 0;
ata_msleep(ap, 150);
rc = ata_sff_wait_ready(link, deadline);
if (rc)
return rc;
if (dev1) {
int i;
ap->ops->sff_dev_select(ap, 1);
for (i = 0; i < 2; i++) {
u8 nsect, lbal;
nsect = in_be32(ioaddr->nsect_addr);
lbal = in_be32(ioaddr->lbal_addr);
if ((nsect == 1) && (lbal == 1))
break;
ata_msleep(ap, 50);
}
rc = ata_sff_wait_ready(link, deadline);
if (rc) {
if (rc != -ENODEV)
return rc;
ret = rc;
}
}
ap->ops->sff_dev_select(ap, 0);
if (dev1)
ap->ops->sff_dev_select(ap, 1);
if (dev0)
ap->ops->sff_dev_select(ap, 0);
return ret;
}
static unsigned int scc_bus_softreset(struct ata_port *ap, unsigned int devmask,
unsigned long deadline)
{
struct ata_ioports *ioaddr = &ap->ioaddr;
DPRINTK("ata%u: bus reset via SRST\n", ap->print_id);
out_be32(ioaddr->ctl_addr, ap->ctl);
udelay(20);
out_be32(ioaddr->ctl_addr, ap->ctl | ATA_SRST);
udelay(20);
out_be32(ioaddr->ctl_addr, ap->ctl);
scc_wait_after_reset(&ap->link, devmask, deadline);
return 0;
}
static int scc_softreset(struct ata_link *link, unsigned int *classes,
unsigned long deadline)
{
struct ata_port *ap = link->ap;
unsigned int slave_possible = ap->flags & ATA_FLAG_SLAVE_POSS;
unsigned int devmask = 0, err_mask;
u8 err;
DPRINTK("ENTER\n");
if (scc_devchk(ap, 0))
devmask |= (1 << 0);
if (slave_possible && scc_devchk(ap, 1))
devmask |= (1 << 1);
ap->ops->sff_dev_select(ap, 0);
DPRINTK("about to softreset, devmask=%x\n", devmask);
err_mask = scc_bus_softreset(ap, devmask, deadline);
if (err_mask) {
ata_port_err(ap, "SRST failed (err_mask=0x%x)\n", err_mask);
return -EIO;
}
classes[0] = ata_sff_dev_classify(&ap->link.device[0],
devmask & (1 << 0), &err);
if (slave_possible && err != 0x81)
classes[1] = ata_sff_dev_classify(&ap->link.device[1],
devmask & (1 << 1), &err);
DPRINTK("EXIT, classes[0]=%u [1]=%u\n", classes[0], classes[1]);
return 0;
}
static void scc_bmdma_stop (struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
void __iomem *ctrl_base = ap->host->iomap[SCC_CTRL_BAR];
void __iomem *bmid_base = ap->host->iomap[SCC_BMID_BAR];
u32 reg;
while (1) {
reg = in_be32(bmid_base + SCC_DMA_INTST);
if (reg & INTSTS_SERROR) {
printk(KERN_WARNING "%s: SERROR\n", DRV_NAME);
out_be32(bmid_base + SCC_DMA_INTST, INTSTS_SERROR|INTSTS_BMSINT);
out_be32(bmid_base + SCC_DMA_CMD,
in_be32(bmid_base + SCC_DMA_CMD) & ~ATA_DMA_START);
continue;
}
if (reg & INTSTS_PRERR) {
u32 maea0, maec0;
maea0 = in_be32(ctrl_base + SCC_CTL_MAEA0);
maec0 = in_be32(ctrl_base + SCC_CTL_MAEC0);
printk(KERN_WARNING "%s: PRERR [addr:%x cmd:%x]\n", DRV_NAME, maea0, maec0);
out_be32(bmid_base + SCC_DMA_INTST, INTSTS_PRERR|INTSTS_BMSINT);
out_be32(bmid_base + SCC_DMA_CMD,
in_be32(bmid_base + SCC_DMA_CMD) & ~ATA_DMA_START);
continue;
}
if (reg & INTSTS_RERR) {
printk(KERN_WARNING "%s: Response Error\n", DRV_NAME);
out_be32(bmid_base + SCC_DMA_INTST, INTSTS_RERR|INTSTS_BMSINT);
out_be32(bmid_base + SCC_DMA_CMD,
in_be32(bmid_base + SCC_DMA_CMD) & ~ATA_DMA_START);
continue;
}
if (reg & INTSTS_ICERR) {
out_be32(bmid_base + SCC_DMA_CMD,
in_be32(bmid_base + SCC_DMA_CMD) & ~ATA_DMA_START);
printk(KERN_WARNING "%s: Illegal Configuration\n", DRV_NAME);
out_be32(bmid_base + SCC_DMA_INTST, INTSTS_ICERR|INTSTS_BMSINT);
continue;
}
if (reg & INTSTS_BMSINT) {
unsigned int classes;
unsigned long deadline = ata_deadline(jiffies, ATA_TMOUT_BOOT);
printk(KERN_WARNING "%s: Internal Bus Error\n", DRV_NAME);
out_be32(bmid_base + SCC_DMA_INTST, INTSTS_BMSINT);
scc_softreset(&ap->link, &classes, deadline);
continue;
}
if (reg & INTSTS_BMHE) {
out_be32(bmid_base + SCC_DMA_INTST, INTSTS_BMHE);
continue;
}
if (reg & INTSTS_ACTEINT) {
out_be32(bmid_base + SCC_DMA_INTST, INTSTS_ACTEINT);
continue;
}
if (reg & INTSTS_IOIRQS) {
out_be32(bmid_base + SCC_DMA_INTST, INTSTS_IOIRQS);
continue;
}
break;
}
out_be32(bmid_base + SCC_DMA_CMD,
in_be32(bmid_base + SCC_DMA_CMD) & ~ATA_DMA_START);
ata_sff_dma_pause(ap);
}
static u8 scc_bmdma_status (struct ata_port *ap)
{
void __iomem *mmio = ap->ioaddr.bmdma_addr;
u8 host_stat = in_be32(mmio + SCC_DMA_STATUS);
u32 int_status = in_be32(mmio + SCC_DMA_INTST);
struct ata_queued_cmd *qc = ata_qc_from_tag(ap, ap->link.active_tag);
static int retry = 0;
if (!(in_be32(mmio + SCC_DMA_CMD) & ATA_DMA_START))
return host_stat;
if ((scc_check_altstatus(ap) & ATA_ERR)
&& (int_status & INTSTS_INTRQ))
return (host_stat | ATA_DMA_INTR);
if (int_status & INTSTS_IOIRQS) {
host_stat |= ATA_DMA_INTR;
if ((qc->tf.protocol == ATA_PROT_DMA &&
qc->dev->xfer_mode > XFER_UDMA_4)) {
if (!(int_status & INTSTS_ACTEINT)) {
printk(KERN_WARNING "ata%u: operation failed (transfer data loss)\n",
ap->print_id);
host_stat |= ATA_DMA_ERR;
if (retry++)
ap->udma_mask &= ~(1 << qc->dev->xfer_mode);
} else
retry = 0;
}
}
return host_stat;
}
static unsigned int scc_data_xfer (struct ata_device *dev, unsigned char *buf,
unsigned int buflen, int rw)
{
struct ata_port *ap = dev->link->ap;
unsigned int words = buflen >> 1;
unsigned int i;
__le16 *buf16 = (__le16 *) buf;
void __iomem *mmio = ap->ioaddr.data_addr;
if (rw == READ)
for (i = 0; i < words; i++)
buf16[i] = cpu_to_le16(in_be32(mmio));
else
for (i = 0; i < words; i++)
out_be32(mmio, le16_to_cpu(buf16[i]));
if (unlikely(buflen & 0x01)) {
__le16 align_buf[1] = { 0 };
unsigned char *trailing_buf = buf + buflen - 1;
if (rw == READ) {
align_buf[0] = cpu_to_le16(in_be32(mmio));
memcpy(trailing_buf, align_buf, 1);
} else {
memcpy(align_buf, trailing_buf, 1);
out_be32(mmio, le16_to_cpu(align_buf[0]));
}
words++;
}
return words << 1;
}
static void scc_postreset(struct ata_link *link, unsigned int *classes)
{
struct ata_port *ap = link->ap;
DPRINTK("ENTER\n");
if (classes[0] != ATA_DEV_NONE)
ap->ops->sff_dev_select(ap, 1);
if (classes[1] != ATA_DEV_NONE)
ap->ops->sff_dev_select(ap, 0);
if (classes[0] == ATA_DEV_NONE && classes[1] == ATA_DEV_NONE) {
DPRINTK("EXIT, no device\n");
return;
}
out_be32(ap->ioaddr.ctl_addr, ap->ctl);
DPRINTK("EXIT\n");
}
static void scc_irq_clear (struct ata_port *ap)
{
void __iomem *mmio = ap->ioaddr.bmdma_addr;
if (!mmio)
return;
out_be32(mmio + SCC_DMA_STATUS, in_be32(mmio + SCC_DMA_STATUS));
}
static int scc_port_start (struct ata_port *ap)
{
void __iomem *mmio = ap->ioaddr.bmdma_addr;
int rc;
rc = ata_bmdma_port_start(ap);
if (rc)
return rc;
out_be32(mmio + SCC_DMA_PTERADD, ap->bmdma_prd_dma);
return 0;
}
static void scc_port_stop (struct ata_port *ap)
{
void __iomem *mmio = ap->ioaddr.bmdma_addr;
out_be32(mmio + SCC_DMA_PTERADD, 0);
}
static int scc_reset_controller(struct ata_host *host)
{
void __iomem *ctrl_base = host->iomap[SCC_CTRL_BAR];
void __iomem *bmid_base = host->iomap[SCC_BMID_BAR];
void __iomem *cckctrl_port = ctrl_base + SCC_CTL_CCKCTRL;
void __iomem *mode_port = ctrl_base + SCC_CTL_MODEREG;
void __iomem *ecmode_port = ctrl_base + SCC_CTL_ECMODE;
void __iomem *intmask_port = bmid_base + SCC_DMA_INTMASK;
void __iomem *dmastatus_port = bmid_base + SCC_DMA_STATUS;
u32 reg = 0;
out_be32(cckctrl_port, reg);
reg |= CCKCTRL_ATACLKOEN;
out_be32(cckctrl_port, reg);
reg |= CCKCTRL_LCLKEN | CCKCTRL_OCLKEN;
out_be32(cckctrl_port, reg);
reg |= CCKCTRL_CRST;
out_be32(cckctrl_port, reg);
for (;;) {
reg = in_be32(cckctrl_port);
if (reg & CCKCTRL_CRST)
break;
udelay(5000);
}
reg |= CCKCTRL_ATARESET;
out_be32(cckctrl_port, reg);
out_be32(ecmode_port, ECMODE_VALUE);
out_be32(mode_port, MODE_JCUSFEN);
out_be32(intmask_port, INTMASK_MSK);
if (in_be32(dmastatus_port) & QCHSD_STPDIAG) {
printk(KERN_WARNING "%s: failed to detect 80c cable. (PDIAG# is high)\n", DRV_NAME);
return -EIO;
}
return 0;
}
static void scc_setup_ports (struct ata_ioports *ioaddr, void __iomem *base)
{
ioaddr->cmd_addr = base + SCC_REG_CMD_ADDR;
ioaddr->altstatus_addr = ioaddr->cmd_addr + SCC_REG_ALTSTATUS;
ioaddr->ctl_addr = ioaddr->cmd_addr + SCC_REG_ALTSTATUS;
ioaddr->bmdma_addr = base;
ioaddr->data_addr = ioaddr->cmd_addr + SCC_REG_DATA;
ioaddr->error_addr = ioaddr->cmd_addr + SCC_REG_ERR;
ioaddr->feature_addr = ioaddr->cmd_addr + SCC_REG_FEATURE;
ioaddr->nsect_addr = ioaddr->cmd_addr + SCC_REG_NSECT;
ioaddr->lbal_addr = ioaddr->cmd_addr + SCC_REG_LBAL;
ioaddr->lbam_addr = ioaddr->cmd_addr + SCC_REG_LBAM;
ioaddr->lbah_addr = ioaddr->cmd_addr + SCC_REG_LBAH;
ioaddr->device_addr = ioaddr->cmd_addr + SCC_REG_DEVICE;
ioaddr->status_addr = ioaddr->cmd_addr + SCC_REG_STATUS;
ioaddr->command_addr = ioaddr->cmd_addr + SCC_REG_CMD;
}
static int scc_host_init(struct ata_host *host)
{
struct pci_dev *pdev = to_pci_dev(host->dev);
int rc;
rc = scc_reset_controller(host);
if (rc)
return rc;
rc = pci_set_dma_mask(pdev, ATA_DMA_MASK);
if (rc)
return rc;
rc = pci_set_consistent_dma_mask(pdev, ATA_DMA_MASK);
if (rc)
return rc;
scc_setup_ports(&host->ports[0]->ioaddr, host->iomap[SCC_BMID_BAR]);
pci_set_master(pdev);
return 0;
}
static int scc_init_one (struct pci_dev *pdev, const struct pci_device_id *ent)
{
unsigned int board_idx = (unsigned int) ent->driver_data;
const struct ata_port_info *ppi[] = { &scc_port_info[board_idx], NULL };
struct ata_host *host;
int rc;
ata_print_version_once(&pdev->dev, DRV_VERSION);
host = ata_host_alloc_pinfo(&pdev->dev, ppi, 1);
if (!host)
return -ENOMEM;
rc = pcim_enable_device(pdev);
if (rc)
return rc;
rc = pcim_iomap_regions(pdev, (1 << SCC_CTRL_BAR) | (1 << SCC_BMID_BAR), DRV_NAME);
if (rc == -EBUSY)
pcim_pin_device(pdev);
if (rc)
return rc;
host->iomap = pcim_iomap_table(pdev);
ata_port_pbar_desc(host->ports[0], SCC_CTRL_BAR, -1, "ctrl");
ata_port_pbar_desc(host->ports[0], SCC_BMID_BAR, -1, "bmid");
rc = scc_host_init(host);
if (rc)
return rc;
return ata_host_activate(host, pdev->irq, ata_bmdma_interrupt,
IRQF_SHARED, &scc_sht);
}
static int __init scc_init (void)
{
int rc;
DPRINTK("pci_register_driver\n");
rc = pci_register_driver(&scc_pci_driver);
if (rc)
return rc;
DPRINTK("done\n");
return 0;
}
static void __exit scc_exit (void)
{
pci_unregister_driver(&scc_pci_driver);
}
