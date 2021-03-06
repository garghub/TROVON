static void ali_fifo_control(ide_hwif_t *hwif, ide_drive_t *drive, int on)
{
struct pci_dev *pdev = to_pci_dev(hwif->dev);
int pio_fifo = 0x54 + hwif->channel;
u8 fifo;
int shift = 4 * (drive->dn & 1);
pci_read_config_byte(pdev, pio_fifo, &fifo);
fifo &= ~(0x0F << shift);
fifo |= (on << shift);
pci_write_config_byte(pdev, pio_fifo, fifo);
}
static void ali_program_timings(ide_hwif_t *hwif, ide_drive_t *drive,
struct ide_timing *t, u8 ultra)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
int port = hwif->channel ? 0x5c : 0x58;
int udmat = 0x56 + hwif->channel;
u8 unit = drive->dn & 1, udma;
int shift = 4 * unit;
pci_read_config_byte(dev, udmat, &udma);
udma &= ~(0x0F << shift);
udma |= ultra << shift;
pci_write_config_byte(dev, udmat, udma);
if (t == NULL)
return;
t->setup = clamp_val(t->setup, 1, 8) & 7;
t->act8b = clamp_val(t->act8b, 1, 8) & 7;
t->rec8b = clamp_val(t->rec8b, 1, 16) & 15;
t->active = clamp_val(t->active, 1, 8) & 7;
t->recover = clamp_val(t->recover, 1, 16) & 15;
pci_write_config_byte(dev, port, t->setup);
pci_write_config_byte(dev, port + 1, (t->act8b << 4) | t->rec8b);
pci_write_config_byte(dev, port + unit + 2,
(t->active << 4) | t->recover);
}
static void ali_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
ide_drive_t *pair = ide_get_pair_dev(drive);
int bus_speed = ide_pci_clk ? ide_pci_clk : 33;
unsigned long T = 1000000 / bus_speed;
struct ide_timing t;
ide_timing_compute(drive, drive->pio_mode, &t, T, 1);
if (pair) {
struct ide_timing p;
ide_timing_compute(pair, pair->pio_mode, &p, T, 1);
ide_timing_merge(&p, &t, &t,
IDE_TIMING_SETUP | IDE_TIMING_8BIT);
if (pair->dma_mode) {
ide_timing_compute(pair, pair->dma_mode, &p, T, 1);
ide_timing_merge(&p, &t, &t,
IDE_TIMING_SETUP | IDE_TIMING_8BIT);
}
}
ali_fifo_control(hwif, drive, (drive->media == ide_disk) ? 0x05 : 0x00);
ali_program_timings(hwif, drive, &t, 0);
}
static u8 ali_udma_filter(ide_drive_t *drive)
{
if (m5229_revision > 0x20 && m5229_revision < 0xC2) {
if (drive->media != ide_disk)
return 0;
if (chip_is_1543c_e &&
strstr((char *)&drive->id[ATA_ID_PROD], "WDC "))
return 0;
}
return drive->hwif->ultra_mask;
}
static void ali_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
static u8 udma_timing[7] = { 0xC, 0xB, 0xA, 0x9, 0x8, 0xF, 0xD };
struct pci_dev *dev = to_pci_dev(hwif->dev);
ide_drive_t *pair = ide_get_pair_dev(drive);
int bus_speed = ide_pci_clk ? ide_pci_clk : 33;
unsigned long T = 1000000 / bus_speed;
const u8 speed = drive->dma_mode;
u8 tmpbyte = 0x00;
struct ide_timing t;
if (speed < XFER_UDMA_0) {
ide_timing_compute(drive, drive->dma_mode, &t, T, 1);
if (pair) {
struct ide_timing p;
ide_timing_compute(pair, pair->pio_mode, &p, T, 1);
ide_timing_merge(&p, &t, &t,
IDE_TIMING_SETUP | IDE_TIMING_8BIT);
if (pair->dma_mode) {
ide_timing_compute(pair, pair->dma_mode,
&p, T, 1);
ide_timing_merge(&p, &t, &t,
IDE_TIMING_SETUP | IDE_TIMING_8BIT);
}
}
ali_program_timings(hwif, drive, &t, 0);
} else {
ali_program_timings(hwif, drive, NULL,
udma_timing[speed - XFER_UDMA_0]);
if (speed >= XFER_UDMA_3) {
pci_read_config_byte(dev, 0x4b, &tmpbyte);
tmpbyte |= 1;
pci_write_config_byte(dev, 0x4b, tmpbyte);
}
}
}
static int ali_dma_check(ide_drive_t *drive, struct ide_cmd *cmd)
{
if (m5229_revision < 0xC2 && drive->media != ide_disk) {
if (cmd->tf_flags & IDE_TFLAG_WRITE)
return 1;
}
return 0;
}
static int init_chipset_ali15x3(struct pci_dev *dev)
{
unsigned long flags;
u8 tmpbyte;
struct pci_dev *north = pci_get_slot(dev->bus, PCI_DEVFN(0,0));
m5229_revision = dev->revision;
isa_dev = pci_get_device(PCI_VENDOR_ID_AL, PCI_DEVICE_ID_AL_M1533, NULL);
local_irq_save(flags);
if (m5229_revision < 0xC2) {
pci_read_config_byte(dev, 0x4b, &tmpbyte);
pci_write_config_byte(dev, 0x4b, tmpbyte & 0x7F);
if (m5229_revision >= 0x20 && isa_dev) {
pci_read_config_byte(isa_dev, 0x5e, &tmpbyte);
chip_is_1543c_e = ((tmpbyte & 0x1e) == 0x12) ? 1: 0;
}
goto out;
}
pci_read_config_byte(dev, 0x4b, &tmpbyte);
pci_write_config_byte(dev, 0x4b, tmpbyte | 0x08);
if (north && north->vendor != PCI_VENDOR_ID_AL)
goto out;
if (m5229_revision < 0xC5 && isa_dev)
{
pci_read_config_byte(isa_dev, 0x79, &tmpbyte);
if (m5229_revision == 0xC2) {
pci_write_config_byte(isa_dev, 0x79, tmpbyte | 0x04);
} else if (m5229_revision >= 0xC3) {
pci_write_config_byte(isa_dev, 0x79, tmpbyte | 0x02);
}
}
out:
if (m5229_revision >= 0x20) {
pci_read_config_byte(dev, 0x53, &tmpbyte);
if (m5229_revision <= 0x20)
tmpbyte = (tmpbyte & (~0x02)) | 0x01;
else if (m5229_revision == 0xc7 || m5229_revision == 0xc8)
tmpbyte |= 0x03;
else
tmpbyte |= 0x01;
pci_write_config_byte(dev, 0x53, tmpbyte);
}
pci_dev_put(north);
pci_dev_put(isa_dev);
local_irq_restore(flags);
return 0;
}
static int ali_cable_override(struct pci_dev *pdev)
{
if (pdev->subsystem_vendor == 0x10CF &&
pdev->subsystem_device == 0x10AF)
return 1;
if (pdev->subsystem_vendor == 0x1071 &&
pdev->subsystem_device == 0x8317)
return 1;
if (dmi_check_system(cable_dmi_table))
return 1;
return 0;
}
static u8 ali_cable_detect(ide_hwif_t *hwif)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
u8 cbl = ATA_CBL_PATA40, tmpbyte;
if (m5229_revision >= 0xC2) {
if (ali_cable_override(dev))
cbl = ATA_CBL_PATA40_SHORT;
else {
pci_read_config_byte(dev, 0x4a, &tmpbyte);
if ((tmpbyte & (1 << hwif->channel)) == 0)
cbl = ATA_CBL_PATA80;
}
}
return cbl;
}
static void __devinit init_hwif_ali15x3 (ide_hwif_t *hwif)
{
u8 ideic, inmir;
s8 irq_routing_table[] = { -1, 9, 3, 10, 4, 5, 7, 6,
1, 11, 0, 12, 0, 14, 0, 15 };
int irq = -1;
if (isa_dev) {
pci_read_config_byte(isa_dev, 0x58, &ideic);
ideic = ideic & 0x03;
if ((hwif->channel && ideic == 0x03) ||
(!hwif->channel && !ideic)) {
pci_read_config_byte(isa_dev, 0x44, &inmir);
inmir = inmir & 0x0f;
irq = irq_routing_table[inmir];
} else if (hwif->channel && !(ideic & 0x01)) {
pci_read_config_byte(isa_dev, 0x75, &inmir);
inmir = inmir & 0x0f;
irq = irq_routing_table[inmir];
}
if(irq >= 0)
hwif->irq = irq;
}
}
static int __devinit init_dma_ali15x3(ide_hwif_t *hwif,
const struct ide_port_info *d)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
unsigned long base = ide_pci_dma_base(hwif, d);
if (base == 0)
return -1;
hwif->dma_base = base;
if (ide_pci_check_simplex(hwif, d) < 0)
return -1;
if (ide_pci_set_master(dev, d->name) < 0)
return -1;
if (!hwif->channel)
outb(inb(base + 2) & 0x60, base + 2);
printk(KERN_INFO " %s: BM-DMA at 0x%04lx-0x%04lx\n",
hwif->name, base, base + 7);
if (ide_allocate_dma_engine(hwif))
return -1;
return 0;
}
static int __devinit alim15x3_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
struct ide_port_info d = ali15x3_chipset;
u8 rev = dev->revision, idx = id->driver_data;
if (rev <= 0xC4)
d.host_flags |= IDE_HFLAG_NO_LBA48_DMA;
if (rev >= 0x20) {
if (rev == 0x20)
d.host_flags |= IDE_HFLAG_NO_ATAPI_DMA;
if (rev < 0xC2)
d.udma_mask = ATA_UDMA2;
else if (rev == 0xC2 || rev == 0xC3)
d.udma_mask = ATA_UDMA4;
else if (rev == 0xC4)
d.udma_mask = ATA_UDMA5;
else
d.udma_mask = ATA_UDMA6;
d.dma_ops = &ali_dma_ops;
} else {
d.host_flags |= IDE_HFLAG_NO_DMA;
d.mwdma_mask = d.swdma_mask = 0;
}
if (idx == 0)
d.host_flags |= IDE_HFLAG_CLEAR_SIMPLEX;
return ide_pci_init_one(dev, &d, NULL);
}
static int __init ali15x3_ide_init(void)
{
return ide_pci_register_driver(&alim15x3_pci_driver);
}
static void __exit ali15x3_ide_exit(void)
{
pci_unregister_driver(&alim15x3_pci_driver);
}
