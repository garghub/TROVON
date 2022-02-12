static u32 hpt3x2n_find_mode(struct ata_port *ap, int speed)
{
struct hpt_clock *clocks = hpt3x2n_clocks;
while (clocks->xfer_speed) {
if (clocks->xfer_speed == speed)
return clocks->timing;
clocks++;
}
BUG();
return 0xffffffffU;
}
static unsigned long hpt372n_filter(struct ata_device *adev, unsigned long mask)
{
if (ata_id_is_sata(adev->id))
mask &= ~((0xE << ATA_SHIFT_UDMA) | ATA_MASK_MWDMA);
return mask;
}
static int hpt3x2n_cable_detect(struct ata_port *ap)
{
u8 scr2, ata66;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
pci_read_config_byte(pdev, 0x5B, &scr2);
pci_write_config_byte(pdev, 0x5B, scr2 & ~0x01);
udelay(10);
pci_read_config_byte(pdev, 0x5A, &ata66);
pci_write_config_byte(pdev, 0x5B, scr2);
if (ata66 & (2 >> ap->port_no))
return ATA_CBL_PATA40;
else
return ATA_CBL_PATA80;
}
static int hpt3x2n_pre_reset(struct ata_link *link, unsigned long deadline)
{
struct ata_port *ap = link->ap;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
pci_write_config_byte(pdev, 0x50 + 4 * ap->port_no, 0x37);
udelay(100);
return ata_sff_prereset(link, deadline);
}
static void hpt3x2n_set_mode(struct ata_port *ap, struct ata_device *adev,
u8 mode)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u32 addr1, addr2;
u32 reg, timing, mask;
u8 fast;
addr1 = 0x40 + 4 * (adev->devno + 2 * ap->port_no);
addr2 = 0x51 + 4 * ap->port_no;
pci_read_config_byte(pdev, addr2, &fast);
fast &= ~0x07;
pci_write_config_byte(pdev, addr2, fast);
if (mode < XFER_MW_DMA_0)
mask = 0xcfc3ffff;
else if (mode < XFER_UDMA_0)
mask = 0x31c001ff;
else
mask = 0x303c0000;
timing = hpt3x2n_find_mode(ap, mode);
pci_read_config_dword(pdev, addr1, &reg);
reg = (reg & ~mask) | (timing & mask);
pci_write_config_dword(pdev, addr1, reg);
}
static void hpt3x2n_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
hpt3x2n_set_mode(ap, adev, adev->pio_mode);
}
static void hpt3x2n_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
hpt3x2n_set_mode(ap, adev, adev->dma_mode);
}
static void hpt3x2n_bmdma_stop(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int mscreg = 0x50 + 2 * ap->port_no;
u8 bwsr_stat, msc_stat;
pci_read_config_byte(pdev, 0x6A, &bwsr_stat);
pci_read_config_byte(pdev, mscreg, &msc_stat);
if (bwsr_stat & (1 << ap->port_no))
pci_write_config_byte(pdev, mscreg, msc_stat | 0x30);
ata_bmdma_stop(qc);
}
static void hpt3x2n_set_clock(struct ata_port *ap, int source)
{
void __iomem *bmdma = ap->ioaddr.bmdma_addr - ap->port_no * 8;
iowrite8(0x80, bmdma+0x73);
iowrite8(0x80, bmdma+0x77);
iowrite8(source, bmdma+0x7B);
iowrite8(0xC0, bmdma+0x79);
iowrite8(ioread8(bmdma+0x70) | 0x32, bmdma+0x70);
iowrite8(ioread8(bmdma+0x74) | 0x32, bmdma+0x74);
iowrite8(0x00, bmdma+0x79);
iowrite8(0x00, bmdma+0x73);
iowrite8(0x00, bmdma+0x77);
}
static int hpt3x2n_use_dpll(struct ata_port *ap, int writing)
{
long flags = (long)ap->host->private_data;
if (writing)
return USE_DPLL;
if (flags & PCI66)
return USE_DPLL;
return 0;
}
static int hpt3x2n_qc_defer(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct ata_port *alt = ap->host->ports[ap->port_no ^ 1];
int rc, flags = (long)ap->host->private_data;
int dpll = hpt3x2n_use_dpll(ap, qc->tf.flags & ATA_TFLAG_WRITE);
rc = ata_std_qc_defer(qc);
if (rc != 0)
return rc;
if ((flags & USE_DPLL) != dpll && alt->qc_active)
return ATA_DEFER_PORT;
return 0;
}
static unsigned int hpt3x2n_qc_issue(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
int flags = (long)ap->host->private_data;
int dpll = hpt3x2n_use_dpll(ap, qc->tf.flags & ATA_TFLAG_WRITE);
if ((flags & USE_DPLL) != dpll) {
flags &= ~USE_DPLL;
flags |= dpll;
ap->host->private_data = (void *)(long)flags;
hpt3x2n_set_clock(ap, dpll ? 0x21 : 0x23);
}
return ata_bmdma_qc_issue(qc);
}
static int hpt3xn_calibrate_dpll(struct pci_dev *dev)
{
u8 reg5b;
u32 reg5c;
int tries;
for (tries = 0; tries < 0x5000; tries++) {
udelay(50);
pci_read_config_byte(dev, 0x5b, &reg5b);
if (reg5b & 0x80) {
for (tries = 0; tries < 0x1000; tries++) {
pci_read_config_byte(dev, 0x5b, &reg5b);
if ((reg5b & 0x80) == 0)
return 0;
}
pci_read_config_dword(dev, 0x5c, &reg5c);
pci_write_config_dword(dev, 0x5c, reg5c & ~0x100);
return 1;
}
}
return 0;
}
static int hpt3x2n_pci_clock(struct pci_dev *pdev)
{
unsigned long freq;
u32 fcnt;
unsigned long iobase = pci_resource_start(pdev, 4);
fcnt = inl(iobase + 0x90);
if ((fcnt >> 12) != 0xABCDE) {
int i;
u16 sr;
u32 total = 0;
pr_warn("BIOS clock data not set\n");
for (i = 0; i < 128; i++) {
pci_read_config_word(pdev, 0x78, &sr);
total += sr & 0x1FF;
udelay(15);
}
fcnt = total / 128;
}
fcnt &= 0x1FF;
freq = (fcnt * 77) / 192;
if (freq < 40)
return 33;
if (freq < 45)
return 40;
if (freq < 55)
return 50;
return 66;
}
static int hpt3x2n_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
static const struct ata_port_info info_hpt372n = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA6,
.port_ops = &hpt372n_port_ops
};
static const struct ata_port_info info_hpt3xxn = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA6,
.port_ops = &hpt3xxn_port_ops
};
const struct ata_port_info *ppi[] = { &info_hpt3xxn, NULL };
u8 rev = dev->revision;
u8 irqmask;
unsigned int pci_mhz;
unsigned int f_low, f_high;
int adjust;
unsigned long iobase = pci_resource_start(dev, 4);
void *hpriv = (void *)USE_DPLL;
int rc;
rc = pcim_enable_device(dev);
if (rc)
return rc;
switch (dev->device) {
case PCI_DEVICE_ID_TTI_HPT366:
if (rev < 6)
return -ENODEV;
goto hpt372n;
case PCI_DEVICE_ID_TTI_HPT371:
if (rev < 2)
return -ENODEV;
break;
case PCI_DEVICE_ID_TTI_HPT372:
if (rev < 2)
return -ENODEV;
goto hpt372n;
case PCI_DEVICE_ID_TTI_HPT302:
if (rev < 2)
return -ENODEV;
break;
case PCI_DEVICE_ID_TTI_HPT372N:
hpt372n:
ppi[0] = &info_hpt372n;
break;
default:
pr_err("PCI table is bogus, please report (%d)\n", dev->device);
return -ENODEV;
}
pci_write_config_byte(dev, PCI_CACHE_LINE_SIZE, (L1_CACHE_BYTES / 4));
pci_write_config_byte(dev, PCI_LATENCY_TIMER, 0x78);
pci_write_config_byte(dev, PCI_MIN_GNT, 0x08);
pci_write_config_byte(dev, PCI_MAX_LAT, 0x08);
pci_read_config_byte(dev, 0x5A, &irqmask);
irqmask &= ~0x10;
pci_write_config_byte(dev, 0x5a, irqmask);
if (dev->device == PCI_DEVICE_ID_TTI_HPT371) {
u8 mcr1;
pci_read_config_byte(dev, 0x50, &mcr1);
mcr1 &= ~0x04;
pci_write_config_byte(dev, 0x50, mcr1);
}
pci_mhz = hpt3x2n_pci_clock(dev);
f_low = (pci_mhz * 48) / 66;
f_high = f_low + 2;
pci_write_config_dword(dev, 0x5C, (f_high << 16) | f_low | 0x100);
pci_write_config_byte(dev, 0x5B, 0x21);
for (adjust = 0; adjust < 8; adjust++) {
if (hpt3xn_calibrate_dpll(dev))
break;
pci_write_config_dword(dev, 0x5C, (f_high << 16) | f_low);
}
if (adjust == 8) {
pr_err("DPLL did not stabilize!\n");
return -ENODEV;
}
pr_info("bus clock %dMHz, using 66MHz DPLL\n", pci_mhz);
if (pci_mhz > 60)
hpriv = (void *)(PCI66 | USE_DPLL);
if (dev->device == PCI_DEVICE_ID_TTI_HPT371)
outb(inb(iobase + 0x9c) | 0x04, iobase + 0x9c);
return ata_pci_bmdma_init_one(dev, ppi, &hpt3x2n_sht, hpriv, 0);
}
