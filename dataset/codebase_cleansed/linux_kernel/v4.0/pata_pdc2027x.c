static inline void __iomem *port_mmio(struct ata_port *ap, unsigned int offset)
{
return ap->host->iomap[PDC_MMIO_BAR] + ap->port_no * 0x100 + offset;
}
static inline void __iomem *dev_mmio(struct ata_port *ap, struct ata_device *adev, unsigned int offset)
{
u8 adj = (adev->devno) ? 0x08 : 0x00;
return port_mmio(ap, offset) + adj;
}
static int pdc2027x_cable_detect(struct ata_port *ap)
{
u32 cgcr;
cgcr = ioread32(port_mmio(ap, PDC_GLOBAL_CTL));
if (cgcr & (1 << 26))
goto cbl40;
PDPRINTK("No cable or 80-conductor cable on port %d\n", ap->port_no);
return ATA_CBL_PATA80;
cbl40:
printk(KERN_INFO DRV_NAME ": 40-conductor cable detected on port %d\n", ap->port_no);
return ATA_CBL_PATA40;
}
static inline int pdc2027x_port_enabled(struct ata_port *ap)
{
return ioread8(port_mmio(ap, PDC_ATA_CTL)) & 0x02;
}
static int pdc2027x_prereset(struct ata_link *link, unsigned long deadline)
{
if (!pdc2027x_port_enabled(link->ap))
return -ENOENT;
return ata_sff_prereset(link, deadline);
}
static unsigned long pdc2027x_mode_filter(struct ata_device *adev, unsigned long mask)
{
unsigned char model_num[ATA_ID_PROD_LEN + 1];
struct ata_device *pair = ata_dev_pair(adev);
if (adev->class != ATA_DEV_ATA || adev->devno == 0 || pair == NULL)
return mask;
ata_id_c_string(pair->id, model_num, ATA_ID_PROD,
ATA_ID_PROD_LEN + 1);
if (strstr(model_num, "Maxtor") == NULL && pair->dma_mode == XFER_UDMA_6)
mask &= ~ (1 << (6 + ATA_SHIFT_UDMA));
return mask;
}
static void pdc2027x_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
unsigned int pio = adev->pio_mode - XFER_PIO_0;
u32 ctcr0, ctcr1;
PDPRINTK("adev->pio_mode[%X]\n", adev->pio_mode);
if (pio > 4) {
printk(KERN_ERR DRV_NAME ": Unknown pio mode [%d] ignored\n", pio);
return;
}
PDPRINTK("Set pio regs... \n");
ctcr0 = ioread32(dev_mmio(ap, adev, PDC_CTCR0));
ctcr0 &= 0xffff0000;
ctcr0 |= pdc2027x_pio_timing_tbl[pio].value0 |
(pdc2027x_pio_timing_tbl[pio].value1 << 8);
iowrite32(ctcr0, dev_mmio(ap, adev, PDC_CTCR0));
ctcr1 = ioread32(dev_mmio(ap, adev, PDC_CTCR1));
ctcr1 &= 0x00ffffff;
ctcr1 |= (pdc2027x_pio_timing_tbl[pio].value2 << 24);
iowrite32(ctcr1, dev_mmio(ap, adev, PDC_CTCR1));
PDPRINTK("Set pio regs done\n");
PDPRINTK("Set to pio mode[%u] \n", pio);
}
static void pdc2027x_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
unsigned int dma_mode = adev->dma_mode;
u32 ctcr0, ctcr1;
if ((dma_mode >= XFER_UDMA_0) &&
(dma_mode <= XFER_UDMA_6)) {
unsigned int udma_mode = dma_mode & 0x07;
if (dma_mode == XFER_UDMA_2) {
ctcr1 = ioread32(dev_mmio(ap, adev, PDC_CTCR1));
iowrite32(ctcr1 & ~(1 << 7), dev_mmio(ap, adev, PDC_CTCR1));
}
PDPRINTK("Set udma regs... \n");
ctcr1 = ioread32(dev_mmio(ap, adev, PDC_CTCR1));
ctcr1 &= 0xff000000;
ctcr1 |= pdc2027x_udma_timing_tbl[udma_mode].value0 |
(pdc2027x_udma_timing_tbl[udma_mode].value1 << 8) |
(pdc2027x_udma_timing_tbl[udma_mode].value2 << 16);
iowrite32(ctcr1, dev_mmio(ap, adev, PDC_CTCR1));
PDPRINTK("Set udma regs done\n");
PDPRINTK("Set to udma mode[%u] \n", udma_mode);
} else if ((dma_mode >= XFER_MW_DMA_0) &&
(dma_mode <= XFER_MW_DMA_2)) {
unsigned int mdma_mode = dma_mode & 0x07;
PDPRINTK("Set mdma regs... \n");
ctcr0 = ioread32(dev_mmio(ap, adev, PDC_CTCR0));
ctcr0 &= 0x0000ffff;
ctcr0 |= (pdc2027x_mdma_timing_tbl[mdma_mode].value0 << 16) |
(pdc2027x_mdma_timing_tbl[mdma_mode].value1 << 24);
iowrite32(ctcr0, dev_mmio(ap, adev, PDC_CTCR0));
PDPRINTK("Set mdma regs done\n");
PDPRINTK("Set to mdma mode[%u] \n", mdma_mode);
} else {
printk(KERN_ERR DRV_NAME ": Unknown dma mode [%u] ignored\n", dma_mode);
}
}
static int pdc2027x_set_mode(struct ata_link *link, struct ata_device **r_failed)
{
struct ata_port *ap = link->ap;
struct ata_device *dev;
int rc;
rc = ata_do_set_mode(link, r_failed);
if (rc < 0)
return rc;
ata_for_each_dev(dev, link, ENABLED) {
pdc2027x_set_piomode(ap, dev);
if (dev->xfer_shift == ATA_SHIFT_PIO) {
u32 ctcr1 = ioread32(dev_mmio(ap, dev, PDC_CTCR1));
ctcr1 |= (1 << 25);
iowrite32(ctcr1, dev_mmio(ap, dev, PDC_CTCR1));
PDPRINTK("Turn on prefetch\n");
} else {
pdc2027x_set_dmamode(ap, dev);
}
}
return 0;
}
static int pdc2027x_check_atapi_dma(struct ata_queued_cmd *qc)
{
struct scsi_cmnd *cmd = qc->scsicmd;
u8 *scsicmd = cmd->cmnd;
int rc = 1;
switch (scsicmd[0]) {
case READ_10:
case WRITE_10:
case READ_12:
case WRITE_12:
case READ_6:
case WRITE_6:
case 0xad:
case 0xbe:
rc = 0;
break;
default:
;
}
return rc;
}
static long pdc_read_counter(struct ata_host *host)
{
void __iomem *mmio_base = host->iomap[PDC_MMIO_BAR];
long counter;
int retry = 1;
u32 bccrl, bccrh, bccrlv, bccrhv;
retry:
bccrl = ioread32(mmio_base + PDC_BYTE_COUNT) & 0x7fff;
bccrh = ioread32(mmio_base + PDC_BYTE_COUNT + 0x100) & 0x7fff;
bccrlv = ioread32(mmio_base + PDC_BYTE_COUNT) & 0x7fff;
bccrhv = ioread32(mmio_base + PDC_BYTE_COUNT + 0x100) & 0x7fff;
counter = (bccrh << 15) | bccrl;
PDPRINTK("bccrh [%X] bccrl [%X]\n", bccrh, bccrl);
PDPRINTK("bccrhv[%X] bccrlv[%X]\n", bccrhv, bccrlv);
if (retry && !(bccrh == bccrhv && bccrl >= bccrlv)) {
retry--;
PDPRINTK("rereading counter\n");
goto retry;
}
return counter;
}
static void pdc_adjust_pll(struct ata_host *host, long pll_clock, unsigned int board_idx)
{
void __iomem *mmio_base = host->iomap[PDC_MMIO_BAR];
u16 pll_ctl;
long pll_clock_khz = pll_clock / 1000;
long pout_required = board_idx? PDC_133_MHZ:PDC_100_MHZ;
long ratio = pout_required / pll_clock_khz;
int F, R;
if (unlikely(pll_clock_khz < 5000L || pll_clock_khz > 70000L)) {
printk(KERN_ERR DRV_NAME ": Invalid PLL input clock %ldkHz, give up!\n", pll_clock_khz);
return;
}
#ifdef PDC_DEBUG
PDPRINTK("pout_required is %ld\n", pout_required);
pll_ctl = ioread16(mmio_base + PDC_PLL_CTL);
PDPRINTK("pll_ctl[%X]\n", pll_ctl);
#endif
if (ratio < 8600L) {
R = 0x0d;
} else if (ratio < 12900L) {
R = 0x08;
} else if (ratio < 16100L) {
R = 0x06;
} else if (ratio < 64000L) {
R = 0x00;
} else {
printk(KERN_ERR DRV_NAME ": Invalid ratio %ld, give up!\n", ratio);
return;
}
F = (ratio * (R+2)) / 1000 - 2;
if (unlikely(F < 0 || F > 127)) {
printk(KERN_ERR DRV_NAME ": F[%d] invalid!\n", F);
return;
}
PDPRINTK("F[%d] R[%d] ratio*1000[%ld]\n", F, R, ratio);
pll_ctl = (R << 8) | F;
PDPRINTK("Writing pll_ctl[%X]\n", pll_ctl);
iowrite16(pll_ctl, mmio_base + PDC_PLL_CTL);
ioread16(mmio_base + PDC_PLL_CTL);
mdelay(30);
#ifdef PDC_DEBUG
pll_ctl = ioread16(mmio_base + PDC_PLL_CTL);
PDPRINTK("pll_ctl[%X]\n", pll_ctl);
#endif
return;
}
static long pdc_detect_pll_input_clock(struct ata_host *host)
{
void __iomem *mmio_base = host->iomap[PDC_MMIO_BAR];
u32 scr;
long start_count, end_count;
ktime_t start_time, end_time;
long pll_clock, usec_elapsed;
scr = ioread32(mmio_base + PDC_SYS_CTL);
PDPRINTK("scr[%X]\n", scr);
iowrite32(scr | (0x01 << 14), mmio_base + PDC_SYS_CTL);
ioread32(mmio_base + PDC_SYS_CTL);
start_count = pdc_read_counter(host);
start_time = ktime_get();
mdelay(100);
end_count = pdc_read_counter(host);
end_time = ktime_get();
scr = ioread32(mmio_base + PDC_SYS_CTL);
PDPRINTK("scr[%X]\n", scr);
iowrite32(scr & ~(0x01 << 14), mmio_base + PDC_SYS_CTL);
ioread32(mmio_base + PDC_SYS_CTL);
usec_elapsed = (long) ktime_us_delta(end_time, start_time);
pll_clock = ((start_count - end_count) & 0x3fffffff) / 100 *
(100000000 / usec_elapsed);
PDPRINTK("start[%ld] end[%ld] \n", start_count, end_count);
PDPRINTK("PLL input clock[%ld]Hz\n", pll_clock);
return pll_clock;
}
static int pdc_hardware_init(struct ata_host *host, unsigned int board_idx)
{
long pll_clock;
pll_clock = pdc_detect_pll_input_clock(host);
dev_info(host->dev, "PLL input clock %ld kHz\n", pll_clock/1000);
pdc_adjust_pll(host, pll_clock, board_idx);
return 0;
}
static void pdc_ata_setup_port(struct ata_ioports *port, void __iomem *base)
{
port->cmd_addr =
port->data_addr = base;
port->feature_addr =
port->error_addr = base + 0x05;
port->nsect_addr = base + 0x0a;
port->lbal_addr = base + 0x0f;
port->lbam_addr = base + 0x10;
port->lbah_addr = base + 0x15;
port->device_addr = base + 0x1a;
port->command_addr =
port->status_addr = base + 0x1f;
port->altstatus_addr =
port->ctl_addr = base + 0x81a;
}
static int pdc2027x_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
static const unsigned long cmd_offset[] = { 0x17c0, 0x15c0 };
static const unsigned long bmdma_offset[] = { 0x1000, 0x1008 };
unsigned int board_idx = (unsigned int) ent->driver_data;
const struct ata_port_info *ppi[] =
{ &pdc2027x_port_info[board_idx], NULL };
struct ata_host *host;
void __iomem *mmio_base;
int i, rc;
ata_print_version_once(&pdev->dev, DRV_VERSION);
host = ata_host_alloc_pinfo(&pdev->dev, ppi, 2);
if (!host)
return -ENOMEM;
rc = pcim_enable_device(pdev);
if (rc)
return rc;
rc = pcim_iomap_regions(pdev, 1 << PDC_MMIO_BAR, DRV_NAME);
if (rc)
return rc;
host->iomap = pcim_iomap_table(pdev);
rc = pci_set_dma_mask(pdev, ATA_DMA_MASK);
if (rc)
return rc;
rc = pci_set_consistent_dma_mask(pdev, ATA_DMA_MASK);
if (rc)
return rc;
mmio_base = host->iomap[PDC_MMIO_BAR];
for (i = 0; i < 2; i++) {
struct ata_port *ap = host->ports[i];
pdc_ata_setup_port(&ap->ioaddr, mmio_base + cmd_offset[i]);
ap->ioaddr.bmdma_addr = mmio_base + bmdma_offset[i];
ata_port_pbar_desc(ap, PDC_MMIO_BAR, -1, "mmio");
ata_port_pbar_desc(ap, PDC_MMIO_BAR, cmd_offset[i], "cmd");
}
if (pdc_hardware_init(host, board_idx) != 0)
return -EIO;
pci_set_master(pdev);
return ata_host_activate(host, pdev->irq, ata_bmdma_interrupt,
IRQF_SHARED, &pdc2027x_sht);
}
static int pdc2027x_reinit_one(struct pci_dev *pdev)
{
struct ata_host *host = pci_get_drvdata(pdev);
unsigned int board_idx;
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
if (pdev->device == PCI_DEVICE_ID_PROMISE_20268 ||
pdev->device == PCI_DEVICE_ID_PROMISE_20270)
board_idx = PDC_UDMA_100;
else
board_idx = PDC_UDMA_133;
if (pdc_hardware_init(host, board_idx))
return -EIO;
ata_host_resume(host);
return 0;
}
