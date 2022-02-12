static u8 scc_ide_inb(unsigned long port)
{
u32 data = in_be32((void*)port);
return (u8)data;
}
static void scc_exec_command(ide_hwif_t *hwif, u8 cmd)
{
out_be32((void *)hwif->io_ports.command_addr, cmd);
eieio();
in_be32((void *)(hwif->dma_base + 0x01c));
eieio();
}
static u8 scc_read_status(ide_hwif_t *hwif)
{
return (u8)in_be32((void *)hwif->io_ports.status_addr);
}
static u8 scc_read_altstatus(ide_hwif_t *hwif)
{
return (u8)in_be32((void *)hwif->io_ports.ctl_addr);
}
static u8 scc_dma_sff_read_status(ide_hwif_t *hwif)
{
return (u8)in_be32((void *)(hwif->dma_base + 4));
}
static void scc_write_devctl(ide_hwif_t *hwif, u8 ctl)
{
out_be32((void *)hwif->io_ports.ctl_addr, ctl);
eieio();
in_be32((void *)(hwif->dma_base + 0x01c));
eieio();
}
static void scc_ide_insw(unsigned long port, void *addr, u32 count)
{
u16 *ptr = (u16 *)addr;
while (count--) {
*ptr++ = le16_to_cpu(in_be32((void*)port));
}
}
static void scc_ide_insl(unsigned long port, void *addr, u32 count)
{
u16 *ptr = (u16 *)addr;
while (count--) {
*ptr++ = le16_to_cpu(in_be32((void*)port));
*ptr++ = le16_to_cpu(in_be32((void*)port));
}
}
static void scc_ide_outb(u8 addr, unsigned long port)
{
out_be32((void*)port, addr);
}
static void
scc_ide_outsw(unsigned long port, void *addr, u32 count)
{
u16 *ptr = (u16 *)addr;
while (count--) {
out_be32((void*)port, cpu_to_le16(*ptr++));
}
}
static void
scc_ide_outsl(unsigned long port, void *addr, u32 count)
{
u16 *ptr = (u16 *)addr;
while (count--) {
out_be32((void*)port, cpu_to_le16(*ptr++));
out_be32((void*)port, cpu_to_le16(*ptr++));
}
}
static void scc_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct scc_ports *ports = ide_get_hwifdata(hwif);
unsigned long ctl_base = ports->ctl;
unsigned long cckctrl_port = ctl_base + 0xff0;
unsigned long piosht_port = ctl_base + 0x000;
unsigned long pioct_port = ctl_base + 0x004;
unsigned long reg;
int offset;
const u8 pio = drive->pio_mode - XFER_PIO_0;
reg = in_be32((void __iomem *)cckctrl_port);
if (reg & CCKCTRL_ATACLKOEN) {
offset = 1;
} else {
offset = 0;
}
reg = JCHSTtbl[offset][pio] << 16 | JCHHTtbl[offset][pio];
out_be32((void __iomem *)piosht_port, reg);
reg = JCHCTtbl[offset][pio];
out_be32((void __iomem *)pioct_port, reg);
}
static void scc_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct scc_ports *ports = ide_get_hwifdata(hwif);
unsigned long ctl_base = ports->ctl;
unsigned long cckctrl_port = ctl_base + 0xff0;
unsigned long mdmact_port = ctl_base + 0x008;
unsigned long mcrcst_port = ctl_base + 0x00c;
unsigned long sdmact_port = ctl_base + 0x010;
unsigned long scrcst_port = ctl_base + 0x014;
unsigned long udenvt_port = ctl_base + 0x018;
unsigned long tdvhsel_port = ctl_base + 0x020;
int is_slave = drive->dn & 1;
int offset, idx;
unsigned long reg;
unsigned long jcactsel;
const u8 speed = drive->dma_mode;
reg = in_be32((void __iomem *)cckctrl_port);
if (reg & CCKCTRL_ATACLKOEN) {
offset = 1;
} else {
offset = 0;
}
idx = speed - XFER_UDMA_0;
jcactsel = JCACTSELtbl[offset][idx];
if (is_slave) {
out_be32((void __iomem *)sdmact_port, JCHDCTxtbl[offset][idx]);
out_be32((void __iomem *)scrcst_port, JCSTWTxtbl[offset][idx]);
jcactsel = jcactsel << 2;
out_be32((void __iomem *)tdvhsel_port, (in_be32((void __iomem *)tdvhsel_port) & ~TDVHSEL_SLAVE) | jcactsel);
} else {
out_be32((void __iomem *)mdmact_port, JCHDCTxtbl[offset][idx]);
out_be32((void __iomem *)mcrcst_port, JCSTWTxtbl[offset][idx]);
out_be32((void __iomem *)tdvhsel_port, (in_be32((void __iomem *)tdvhsel_port) & ~TDVHSEL_MASTER) | jcactsel);
}
reg = JCTSStbl[offset][idx] << 16 | JCENVTtbl[offset][idx];
out_be32((void __iomem *)udenvt_port, reg);
}
static void scc_dma_host_set(ide_drive_t *drive, int on)
{
ide_hwif_t *hwif = drive->hwif;
u8 unit = drive->dn & 1;
u8 dma_stat = scc_dma_sff_read_status(hwif);
if (on)
dma_stat |= (1 << (5 + unit));
else
dma_stat &= ~(1 << (5 + unit));
scc_ide_outb(dma_stat, hwif->dma_base + 4);
}
static int scc_dma_setup(ide_drive_t *drive, struct ide_cmd *cmd)
{
ide_hwif_t *hwif = drive->hwif;
u32 rw = (cmd->tf_flags & IDE_TFLAG_WRITE) ? 0 : ATA_DMA_WR;
u8 dma_stat;
if (ide_build_dmatable(drive, cmd) == 0)
return 1;
out_be32((void __iomem *)(hwif->dma_base + 8), hwif->dmatable_dma);
out_be32((void __iomem *)hwif->dma_base, rw);
dma_stat = scc_dma_sff_read_status(hwif);
out_be32((void __iomem *)(hwif->dma_base + 4), dma_stat | 6);
return 0;
}
static void scc_dma_start(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
u8 dma_cmd = scc_ide_inb(hwif->dma_base);
scc_ide_outb(dma_cmd | 1, hwif->dma_base);
}
static int __scc_dma_end(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
u8 dma_stat, dma_cmd;
dma_cmd = scc_ide_inb(hwif->dma_base);
scc_ide_outb(dma_cmd & ~1, hwif->dma_base);
dma_stat = scc_dma_sff_read_status(hwif);
scc_ide_outb(dma_stat | 6, hwif->dma_base + 4);
return (dma_stat & 7) != 4 ? (0x10 | dma_stat) : 0;
}
static int scc_dma_end(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
void __iomem *dma_base = (void __iomem *)hwif->dma_base;
unsigned long intsts_port = hwif->dma_base + 0x014;
u32 reg;
int dma_stat, data_loss = 0;
static int retry = 0;
if (!(in_be32((void __iomem *)hwif->io_ports.ctl_addr)
& ATA_ERR) &&
drive->media == ide_disk && drive->current_speed > XFER_UDMA_4) {
reg = in_be32((void __iomem *)intsts_port);
if (!(reg & INTSTS_ACTEINT)) {
printk(KERN_WARNING "%s: operation failed (transfer data loss)\n",
drive->name);
data_loss = 1;
if (retry++) {
struct request *rq = hwif->rq;
ide_drive_t *drive;
int i;
if (rq)
rq->errors |= ERROR_RESET;
ide_port_for_each_dev(i, drive, hwif)
drive->crc_count++;
}
}
}
while (1) {
reg = in_be32((void __iomem *)intsts_port);
if (reg & INTSTS_SERROR) {
printk(KERN_WARNING "%s: SERROR\n", SCC_PATA_NAME);
out_be32((void __iomem *)intsts_port, INTSTS_SERROR|INTSTS_BMSINT);
out_be32(dma_base, in_be32(dma_base) & ~QCHCD_IOS_SS);
continue;
}
if (reg & INTSTS_PRERR) {
u32 maea0, maec0;
unsigned long ctl_base = hwif->config_data;
maea0 = in_be32((void __iomem *)(ctl_base + 0xF50));
maec0 = in_be32((void __iomem *)(ctl_base + 0xF54));
printk(KERN_WARNING "%s: PRERR [addr:%x cmd:%x]\n", SCC_PATA_NAME, maea0, maec0);
out_be32((void __iomem *)intsts_port, INTSTS_PRERR|INTSTS_BMSINT);
out_be32(dma_base, in_be32(dma_base) & ~QCHCD_IOS_SS);
continue;
}
if (reg & INTSTS_RERR) {
printk(KERN_WARNING "%s: Response Error\n", SCC_PATA_NAME);
out_be32((void __iomem *)intsts_port, INTSTS_RERR|INTSTS_BMSINT);
out_be32(dma_base, in_be32(dma_base) & ~QCHCD_IOS_SS);
continue;
}
if (reg & INTSTS_ICERR) {
out_be32(dma_base, in_be32(dma_base) & ~QCHCD_IOS_SS);
printk(KERN_WARNING "%s: Illegal Configuration\n", SCC_PATA_NAME);
out_be32((void __iomem *)intsts_port, INTSTS_ICERR|INTSTS_BMSINT);
continue;
}
if (reg & INTSTS_BMSINT) {
printk(KERN_WARNING "%s: Internal Bus Error\n", SCC_PATA_NAME);
out_be32((void __iomem *)intsts_port, INTSTS_BMSINT);
ide_do_reset(drive);
continue;
}
if (reg & INTSTS_BMHE) {
out_be32((void __iomem *)intsts_port, INTSTS_BMHE);
continue;
}
if (reg & INTSTS_ACTEINT) {
out_be32((void __iomem *)intsts_port, INTSTS_ACTEINT);
continue;
}
if (reg & INTSTS_IOIRQS) {
out_be32((void __iomem *)intsts_port, INTSTS_IOIRQS);
continue;
}
break;
}
dma_stat = __scc_dma_end(drive);
if (data_loss)
dma_stat |= 2;
return dma_stat;
}
static int scc_dma_test_irq(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
u32 int_stat = in_be32((void __iomem *)hwif->dma_base + 0x014);
if ((in_be32((void __iomem *)hwif->io_ports.ctl_addr)
& ATA_ERR) &&
(int_stat & INTSTS_INTRQ))
return 1;
if (int_stat & INTSTS_IOIRQS)
return 1;
return 0;
}
static u8 scc_udma_filter(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
u8 mask = hwif->ultra_mask;
if ((drive->media != ide_disk) && (mask & 0xE0)) {
printk(KERN_INFO "%s: limit %s to UDMA4\n",
SCC_PATA_NAME, drive->name);
mask = ATA_UDMA4;
}
return mask;
}
static int setup_mmio_scc (struct pci_dev *dev, const char *name)
{
void __iomem *ctl_addr;
void __iomem *dma_addr;
int i, ret;
for (i = 0; i < MAX_HWIFS; i++) {
if (scc_ports[i].ctl == 0)
break;
}
if (i >= MAX_HWIFS)
return -ENOMEM;
ret = pci_request_selected_regions(dev, (1 << 2) - 1, name);
if (ret < 0) {
printk(KERN_ERR "%s: can't reserve resources\n", name);
return ret;
}
ctl_addr = pci_ioremap_bar(dev, 0);
if (!ctl_addr)
goto fail_0;
dma_addr = pci_ioremap_bar(dev, 1);
if (!dma_addr)
goto fail_1;
pci_set_master(dev);
scc_ports[i].ctl = (unsigned long)ctl_addr;
scc_ports[i].dma = (unsigned long)dma_addr;
pci_set_drvdata(dev, (void *) &scc_ports[i]);
return 1;
fail_1:
iounmap(ctl_addr);
fail_0:
return -ENOMEM;
}
static int scc_ide_setup_pci_device(struct pci_dev *dev,
const struct ide_port_info *d)
{
struct scc_ports *ports = pci_get_drvdata(dev);
struct ide_host *host;
struct ide_hw hw, *hws[] = { &hw };
int i, rc;
memset(&hw, 0, sizeof(hw));
for (i = 0; i <= 8; i++)
hw.io_ports_array[i] = ports->dma + 0x20 + i * 4;
hw.irq = dev->irq;
hw.dev = &dev->dev;
rc = ide_host_add(d, hws, 1, &host);
if (rc)
return rc;
ports->host = host;
return 0;
}
static int init_setup_scc(struct pci_dev *dev, const struct ide_port_info *d)
{
unsigned long ctl_base;
unsigned long dma_base;
unsigned long cckctrl_port;
unsigned long intmask_port;
unsigned long mode_port;
unsigned long ecmode_port;
u32 reg = 0;
struct scc_ports *ports;
int rc;
rc = pci_enable_device(dev);
if (rc)
goto end;
rc = setup_mmio_scc(dev, d->name);
if (rc < 0)
goto end;
ports = pci_get_drvdata(dev);
ctl_base = ports->ctl;
dma_base = ports->dma;
cckctrl_port = ctl_base + 0xff0;
intmask_port = dma_base + 0x010;
mode_port = ctl_base + 0x024;
ecmode_port = ctl_base + 0xf00;
reg = 0;
out_be32((void*)cckctrl_port, reg);
reg |= CCKCTRL_ATACLKOEN;
out_be32((void*)cckctrl_port, reg);
reg |= CCKCTRL_LCLKEN | CCKCTRL_OCLKEN;
out_be32((void*)cckctrl_port, reg);
reg |= CCKCTRL_CRST;
out_be32((void*)cckctrl_port, reg);
for (;;) {
reg = in_be32((void*)cckctrl_port);
if (reg & CCKCTRL_CRST)
break;
udelay(5000);
}
reg |= CCKCTRL_ATARESET;
out_be32((void*)cckctrl_port, reg);
out_be32((void*)ecmode_port, ECMODE_VALUE);
out_be32((void*)mode_port, MODE_JCUSFEN);
out_be32((void*)intmask_port, INTMASK_MSK);
rc = scc_ide_setup_pci_device(dev, d);
end:
return rc;
}
static void scc_tf_load(ide_drive_t *drive, struct ide_taskfile *tf, u8 valid)
{
struct ide_io_ports *io_ports = &drive->hwif->io_ports;
if (valid & IDE_VALID_FEATURE)
scc_ide_outb(tf->feature, io_ports->feature_addr);
if (valid & IDE_VALID_NSECT)
scc_ide_outb(tf->nsect, io_ports->nsect_addr);
if (valid & IDE_VALID_LBAL)
scc_ide_outb(tf->lbal, io_ports->lbal_addr);
if (valid & IDE_VALID_LBAM)
scc_ide_outb(tf->lbam, io_ports->lbam_addr);
if (valid & IDE_VALID_LBAH)
scc_ide_outb(tf->lbah, io_ports->lbah_addr);
if (valid & IDE_VALID_DEVICE)
scc_ide_outb(tf->device, io_ports->device_addr);
}
static void scc_tf_read(ide_drive_t *drive, struct ide_taskfile *tf, u8 valid)
{
struct ide_io_ports *io_ports = &drive->hwif->io_ports;
if (valid & IDE_VALID_ERROR)
tf->error = scc_ide_inb(io_ports->feature_addr);
if (valid & IDE_VALID_NSECT)
tf->nsect = scc_ide_inb(io_ports->nsect_addr);
if (valid & IDE_VALID_LBAL)
tf->lbal = scc_ide_inb(io_ports->lbal_addr);
if (valid & IDE_VALID_LBAM)
tf->lbam = scc_ide_inb(io_ports->lbam_addr);
if (valid & IDE_VALID_LBAH)
tf->lbah = scc_ide_inb(io_ports->lbah_addr);
if (valid & IDE_VALID_DEVICE)
tf->device = scc_ide_inb(io_ports->device_addr);
}
static void scc_input_data(ide_drive_t *drive, struct ide_cmd *cmd,
void *buf, unsigned int len)
{
unsigned long data_addr = drive->hwif->io_ports.data_addr;
len++;
if (drive->io_32bit) {
scc_ide_insl(data_addr, buf, len / 4);
if ((len & 3) >= 2)
scc_ide_insw(data_addr, (u8 *)buf + (len & ~3), 1);
} else
scc_ide_insw(data_addr, buf, len / 2);
}
static void scc_output_data(ide_drive_t *drive, struct ide_cmd *cmd,
void *buf, unsigned int len)
{
unsigned long data_addr = drive->hwif->io_ports.data_addr;
len++;
if (drive->io_32bit) {
scc_ide_outsl(data_addr, buf, len / 4);
if ((len & 3) >= 2)
scc_ide_outsw(data_addr, (u8 *)buf + (len & ~3), 1);
} else
scc_ide_outsw(data_addr, buf, len / 2);
}
static void init_mmio_iops_scc(ide_hwif_t *hwif)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
struct scc_ports *ports = pci_get_drvdata(dev);
unsigned long dma_base = ports->dma;
ide_set_hwifdata(hwif, ports);
hwif->dma_base = dma_base;
hwif->config_data = ports->ctl;
}
static void init_iops_scc(ide_hwif_t *hwif)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
hwif->hwif_data = NULL;
if (pci_get_drvdata(dev) == NULL)
return;
init_mmio_iops_scc(hwif);
}
static int scc_init_dma(ide_hwif_t *hwif, const struct ide_port_info *d)
{
return ide_allocate_dma_engine(hwif);
}
static u8 scc_cable_detect(ide_hwif_t *hwif)
{
return ATA_CBL_PATA80;
}
static void init_hwif_scc(ide_hwif_t *hwif)
{
out_be32((void __iomem *)(hwif->dma_base + 0x018), hwif->dmatable_dma);
if (in_be32((void __iomem *)(hwif->config_data + 0xff0)) & CCKCTRL_ATACLKOEN)
hwif->ultra_mask = ATA_UDMA6;
else
hwif->ultra_mask = ATA_UDMA5;
}
static int scc_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
return init_setup_scc(dev, &scc_chipset);
}
static void scc_remove(struct pci_dev *dev)
{
struct scc_ports *ports = pci_get_drvdata(dev);
struct ide_host *host = ports->host;
ide_host_remove(host);
iounmap((void*)ports->dma);
iounmap((void*)ports->ctl);
pci_release_selected_regions(dev, (1 << 2) - 1);
memset(ports, 0, sizeof(*ports));
}
static int __init scc_ide_init(void)
{
return ide_pci_register_driver(&scc_pci_driver);
}
static void __exit scc_ide_exit(void)
{
pci_unregister_driver(&scc_pci_driver);
}
