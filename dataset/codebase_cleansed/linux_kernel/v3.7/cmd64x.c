static void cmd64x_program_timings(ide_drive_t *drive, u8 mode)
{
ide_hwif_t *hwif = drive->hwif;
struct pci_dev *dev = to_pci_dev(drive->hwif->dev);
int bus_speed = ide_pci_clk ? ide_pci_clk : 33;
const unsigned long T = 1000000 / bus_speed;
static const u8 recovery_values[] =
{15, 15, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0};
static const u8 setup_values[] = {0x40, 0x40, 0x40, 0x80, 0, 0xc0};
static const u8 arttim_regs[4] = {ARTTIM0, ARTTIM1, ARTTIM23, ARTTIM23};
static const u8 drwtim_regs[4] = {DRWTIM0, DRWTIM1, DRWTIM2, DRWTIM3};
struct ide_timing t;
u8 arttim = 0;
ide_timing_compute(drive, mode, &t, T, 0);
if (t.recover > 16) {
t.active += t.recover - 16;
t.recover = 16;
}
if (t.active > 16)
t.active = 16;
t.recover = recovery_values[t.recover];
t.active &= 0x0f;
pci_write_config_byte(dev, drwtim_regs[drive->dn],
(t.active << 4) | t.recover);
if (hwif->channel) {
ide_drive_t *pair = ide_get_pair_dev(drive);
if (pair) {
struct ide_timing tp;
ide_timing_compute(pair, pair->pio_mode, &tp, T, 0);
ide_timing_merge(&t, &tp, &t, IDE_TIMING_SETUP);
if (pair->dma_mode) {
ide_timing_compute(pair, pair->dma_mode,
&tp, T, 0);
ide_timing_merge(&tp, &t, &t, IDE_TIMING_SETUP);
}
}
}
if (t.setup > 5)
t.setup = 5;
(void) pci_read_config_byte (dev, arttim_regs[drive->dn], &arttim);
if (hwif->channel)
arttim &= ~ARTTIM23_INTR_CH1;
arttim &= ~0xc0;
arttim |= setup_values[t.setup];
(void) pci_write_config_byte(dev, arttim_regs[drive->dn], arttim);
}
static void cmd64x_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
const u8 pio = drive->pio_mode - XFER_PIO_0;
if (pio == 8 || pio == 9)
return;
cmd64x_program_timings(drive, XFER_PIO_0 + pio);
}
static void cmd64x_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
u8 unit = drive->dn & 0x01;
u8 regU = 0, pciU = hwif->channel ? UDIDETCR1 : UDIDETCR0;
const u8 speed = drive->dma_mode;
pci_read_config_byte(dev, pciU, &regU);
regU &= ~(unit ? 0xCA : 0x35);
switch(speed) {
case XFER_UDMA_5:
regU |= unit ? 0x0A : 0x05;
break;
case XFER_UDMA_4:
regU |= unit ? 0x4A : 0x15;
break;
case XFER_UDMA_3:
regU |= unit ? 0x8A : 0x25;
break;
case XFER_UDMA_2:
regU |= unit ? 0x42 : 0x11;
break;
case XFER_UDMA_1:
regU |= unit ? 0x82 : 0x21;
break;
case XFER_UDMA_0:
regU |= unit ? 0xC2 : 0x31;
break;
case XFER_MW_DMA_2:
case XFER_MW_DMA_1:
case XFER_MW_DMA_0:
cmd64x_program_timings(drive, speed);
break;
}
pci_write_config_byte(dev, pciU, regU);
}
static void cmd648_clear_irq(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
struct pci_dev *dev = to_pci_dev(hwif->dev);
unsigned long base = pci_resource_start(dev, 4);
u8 irq_mask = hwif->channel ? MRDMODE_INTR_CH1 :
MRDMODE_INTR_CH0;
u8 mrdmode = inb(base + 1);
outb((mrdmode & ~(MRDMODE_INTR_CH0 | MRDMODE_INTR_CH1)) | irq_mask,
base + 1);
}
static void cmd64x_clear_irq(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
struct pci_dev *dev = to_pci_dev(hwif->dev);
int irq_reg = hwif->channel ? ARTTIM23 : CFR;
u8 irq_mask = hwif->channel ? ARTTIM23_INTR_CH1 :
CFR_INTR_CH0;
u8 irq_stat = 0;
(void) pci_read_config_byte(dev, irq_reg, &irq_stat);
(void) pci_write_config_byte(dev, irq_reg, irq_stat | irq_mask);
}
static int cmd648_test_irq(ide_hwif_t *hwif)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
unsigned long base = pci_resource_start(dev, 4);
u8 irq_mask = hwif->channel ? MRDMODE_INTR_CH1 :
MRDMODE_INTR_CH0;
u8 mrdmode = inb(base + 1);
pr_debug("%s: mrdmode: 0x%02x irq_mask: 0x%02x\n",
hwif->name, mrdmode, irq_mask);
return (mrdmode & irq_mask) ? 1 : 0;
}
static int cmd64x_test_irq(ide_hwif_t *hwif)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
int irq_reg = hwif->channel ? ARTTIM23 : CFR;
u8 irq_mask = hwif->channel ? ARTTIM23_INTR_CH1 :
CFR_INTR_CH0;
u8 irq_stat = 0;
(void) pci_read_config_byte(dev, irq_reg, &irq_stat);
pr_debug("%s: irq_stat: 0x%02x irq_mask: 0x%02x\n",
hwif->name, irq_stat, irq_mask);
return (irq_stat & irq_mask) ? 1 : 0;
}
static int cmd646_1_dma_end(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
u8 dma_stat = 0, dma_cmd = 0;
dma_stat = inb(hwif->dma_base + ATA_DMA_STATUS);
dma_cmd = inb(hwif->dma_base + ATA_DMA_CMD);
outb(dma_cmd & ~1, hwif->dma_base + ATA_DMA_CMD);
outb(dma_stat | 6, hwif->dma_base + ATA_DMA_STATUS);
return (dma_stat & 7) != 4;
}
static int init_chipset_cmd64x(struct pci_dev *dev)
{
u8 mrdmode = 0;
(void) pci_write_config_byte(dev, PCI_LATENCY_TIMER, 64);
(void) pci_read_config_byte (dev, MRDMODE, &mrdmode);
mrdmode &= ~0x30;
(void) pci_write_config_byte(dev, MRDMODE, (mrdmode | 0x02));
return 0;
}
static u8 cmd64x_cable_detect(ide_hwif_t *hwif)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
u8 bmidecsr = 0, mask = hwif->channel ? 0x02 : 0x01;
switch (dev->device) {
case PCI_DEVICE_ID_CMD_648:
case PCI_DEVICE_ID_CMD_649:
pci_read_config_byte(dev, BMIDECSR, &bmidecsr);
return (bmidecsr & mask) ? ATA_CBL_PATA80 : ATA_CBL_PATA40;
default:
return ATA_CBL_PATA40;
}
}
static int __devinit cmd64x_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
struct ide_port_info d;
u8 idx = id->driver_data;
d = cmd64x_chipsets[idx];
if (idx == 1) {
if (dev->revision < 5) {
d.udma_mask = 0x00;
if (dev->revision < 3) {
d.enablebits[0].reg = 0;
d.port_ops = &cmd64x_port_ops;
if (dev->revision == 1)
d.dma_ops = &cmd646_rev1_dma_ops;
}
}
}
return ide_pci_init_one(dev, &d, NULL);
}
static int __init cmd64x_ide_init(void)
{
return ide_pci_register_driver(&cmd64x_pci_driver);
}
static void __exit cmd64x_ide_exit(void)
{
pci_unregister_driver(&cmd64x_pci_driver);
}
