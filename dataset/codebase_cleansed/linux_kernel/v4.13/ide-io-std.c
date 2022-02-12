static u8 ide_inb(unsigned long port)
{
return (u8) inb(port);
}
static void ide_outb(u8 val, unsigned long port)
{
outb(val, port);
}
static u8 ide_mm_inb(unsigned long port)
{
return (u8) readb((void __iomem *) port);
}
static void ide_mm_outb(u8 value, unsigned long port)
{
writeb(value, (void __iomem *) port);
}
void ide_exec_command(ide_hwif_t *hwif, u8 cmd)
{
if (hwif->host_flags & IDE_HFLAG_MMIO)
writeb(cmd, (void __iomem *)hwif->io_ports.command_addr);
else
outb(cmd, hwif->io_ports.command_addr);
}
u8 ide_read_status(ide_hwif_t *hwif)
{
if (hwif->host_flags & IDE_HFLAG_MMIO)
return readb((void __iomem *)hwif->io_ports.status_addr);
else
return inb(hwif->io_ports.status_addr);
}
u8 ide_read_altstatus(ide_hwif_t *hwif)
{
if (hwif->host_flags & IDE_HFLAG_MMIO)
return readb((void __iomem *)hwif->io_ports.ctl_addr);
else
return inb(hwif->io_ports.ctl_addr);
}
void ide_write_devctl(ide_hwif_t *hwif, u8 ctl)
{
if (hwif->host_flags & IDE_HFLAG_MMIO)
writeb(ctl, (void __iomem *)hwif->io_ports.ctl_addr);
else
outb(ctl, hwif->io_ports.ctl_addr);
}
void ide_dev_select(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
u8 select = drive->select | ATA_DEVICE_OBS;
if (hwif->host_flags & IDE_HFLAG_MMIO)
writeb(select, (void __iomem *)hwif->io_ports.device_addr);
else
outb(select, hwif->io_ports.device_addr);
}
void ide_tf_load(ide_drive_t *drive, struct ide_taskfile *tf, u8 valid)
{
ide_hwif_t *hwif = drive->hwif;
struct ide_io_ports *io_ports = &hwif->io_ports;
void (*tf_outb)(u8 addr, unsigned long port);
u8 mmio = (hwif->host_flags & IDE_HFLAG_MMIO) ? 1 : 0;
if (mmio)
tf_outb = ide_mm_outb;
else
tf_outb = ide_outb;
if (valid & IDE_VALID_FEATURE)
tf_outb(tf->feature, io_ports->feature_addr);
if (valid & IDE_VALID_NSECT)
tf_outb(tf->nsect, io_ports->nsect_addr);
if (valid & IDE_VALID_LBAL)
tf_outb(tf->lbal, io_ports->lbal_addr);
if (valid & IDE_VALID_LBAM)
tf_outb(tf->lbam, io_ports->lbam_addr);
if (valid & IDE_VALID_LBAH)
tf_outb(tf->lbah, io_ports->lbah_addr);
if (valid & IDE_VALID_DEVICE)
tf_outb(tf->device, io_ports->device_addr);
}
void ide_tf_read(ide_drive_t *drive, struct ide_taskfile *tf, u8 valid)
{
ide_hwif_t *hwif = drive->hwif;
struct ide_io_ports *io_ports = &hwif->io_ports;
u8 (*tf_inb)(unsigned long port);
u8 mmio = (hwif->host_flags & IDE_HFLAG_MMIO) ? 1 : 0;
if (mmio)
tf_inb = ide_mm_inb;
else
tf_inb = ide_inb;
if (valid & IDE_VALID_ERROR)
tf->error = tf_inb(io_ports->feature_addr);
if (valid & IDE_VALID_NSECT)
tf->nsect = tf_inb(io_ports->nsect_addr);
if (valid & IDE_VALID_LBAL)
tf->lbal = tf_inb(io_ports->lbal_addr);
if (valid & IDE_VALID_LBAM)
tf->lbam = tf_inb(io_ports->lbam_addr);
if (valid & IDE_VALID_LBAH)
tf->lbah = tf_inb(io_ports->lbah_addr);
if (valid & IDE_VALID_DEVICE)
tf->device = tf_inb(io_ports->device_addr);
}
static void ata_vlb_sync(unsigned long port)
{
(void)inb(port);
(void)inb(port);
(void)inb(port);
}
void ide_input_data(ide_drive_t *drive, struct ide_cmd *cmd, void *buf,
unsigned int len)
{
ide_hwif_t *hwif = drive->hwif;
struct ide_io_ports *io_ports = &hwif->io_ports;
unsigned long data_addr = io_ports->data_addr;
unsigned int words = (len + 1) >> 1;
u8 io_32bit = drive->io_32bit;
u8 mmio = (hwif->host_flags & IDE_HFLAG_MMIO) ? 1 : 0;
if (io_32bit) {
unsigned long uninitialized_var(flags);
if ((io_32bit & 2) && !mmio) {
local_irq_save(flags);
ata_vlb_sync(io_ports->nsect_addr);
}
words >>= 1;
if (mmio)
__ide_mm_insl((void __iomem *)data_addr, buf, words);
else
insl(data_addr, buf, words);
if ((io_32bit & 2) && !mmio)
local_irq_restore(flags);
if (((len + 1) & 3) < 2)
return;
buf += len & ~3;
words = 1;
}
if (mmio)
__ide_mm_insw((void __iomem *)data_addr, buf, words);
else
insw(data_addr, buf, words);
}
void ide_output_data(ide_drive_t *drive, struct ide_cmd *cmd, void *buf,
unsigned int len)
{
ide_hwif_t *hwif = drive->hwif;
struct ide_io_ports *io_ports = &hwif->io_ports;
unsigned long data_addr = io_ports->data_addr;
unsigned int words = (len + 1) >> 1;
u8 io_32bit = drive->io_32bit;
u8 mmio = (hwif->host_flags & IDE_HFLAG_MMIO) ? 1 : 0;
if (io_32bit) {
unsigned long uninitialized_var(flags);
if ((io_32bit & 2) && !mmio) {
local_irq_save(flags);
ata_vlb_sync(io_ports->nsect_addr);
}
words >>= 1;
if (mmio)
__ide_mm_outsl((void __iomem *)data_addr, buf, words);
else
outsl(data_addr, buf, words);
if ((io_32bit & 2) && !mmio)
local_irq_restore(flags);
if (((len + 1) & 3) < 2)
return;
buf += len & ~3;
words = 1;
}
if (mmio)
__ide_mm_outsw((void __iomem *)data_addr, buf, words);
else
outsw(data_addr, buf, words);
}
