static int q40ide_default_irq(unsigned long base)
{
switch (base) {
case 0x1f0: return 14;
case 0x170: return 15;
case 0x1e8: return 11;
default:
return 0;
}
}
static void q40_ide_setup_ports(struct ide_hw *hw, unsigned long base, int irq)
{
memset(hw, 0, sizeof(*hw));
hw->io_ports.data_addr = Q40_ISA_IO_W(base);
hw->io_ports.error_addr = Q40_ISA_IO_B(base + 1);
hw->io_ports.nsect_addr = Q40_ISA_IO_B(base + 2);
hw->io_ports.lbal_addr = Q40_ISA_IO_B(base + 3);
hw->io_ports.lbam_addr = Q40_ISA_IO_B(base + 4);
hw->io_ports.lbah_addr = Q40_ISA_IO_B(base + 5);
hw->io_ports.device_addr = Q40_ISA_IO_B(base + 6);
hw->io_ports.status_addr = Q40_ISA_IO_B(base + 7);
hw->io_ports.ctl_addr = Q40_ISA_IO_B(base + 0x206);
hw->irq = irq;
}
static void q40ide_input_data(ide_drive_t *drive, struct ide_cmd *cmd,
void *buf, unsigned int len)
{
unsigned long data_addr = drive->hwif->io_ports.data_addr;
if (drive->media == ide_disk && cmd && (cmd->tf_flags & IDE_TFLAG_FS)) {
__ide_mm_insw(data_addr, buf, (len + 1) / 2);
return;
}
raw_insw_swapw((u16 *)data_addr, buf, (len + 1) / 2);
}
static void q40ide_output_data(ide_drive_t *drive, struct ide_cmd *cmd,
void *buf, unsigned int len)
{
unsigned long data_addr = drive->hwif->io_ports.data_addr;
if (drive->media == ide_disk && cmd && (cmd->tf_flags & IDE_TFLAG_FS)) {
__ide_mm_outsw(data_addr, buf, (len + 1) / 2);
return;
}
raw_outsw_swapw((u16 *)data_addr, buf, (len + 1) / 2);
}
static int __init q40ide_init(void)
{
int i;
struct ide_hw hw[Q40IDE_NUM_HWIFS], *hws[] = { NULL, NULL };
if (!MACH_IS_Q40)
return -ENODEV;
printk(KERN_INFO "ide: Q40 IDE controller\n");
for (i = 0; i < Q40IDE_NUM_HWIFS; i++) {
const char *name = q40_ide_names[i];
if (!request_region(pcide_bases[i], 8, name)) {
printk("could not reserve ports %lx-%lx for %s\n",
pcide_bases[i],pcide_bases[i]+8,name);
continue;
}
if (!request_region(pcide_bases[i]+0x206, 1, name)) {
printk("could not reserve port %lx for %s\n",
pcide_bases[i]+0x206,name);
release_region(pcide_bases[i], 8);
continue;
}
q40_ide_setup_ports(&hw[i], pcide_bases[i],
q40ide_default_irq(pcide_bases[i]));
hws[i] = &hw[i];
}
return ide_host_add(&q40ide_port_info, hws, Q40IDE_NUM_HWIFS, NULL);
}
