static void write_reg(u8 value, int reg)
{
inw(reg_base + 1);
inw(reg_base + 1);
outb(3, reg_base + 2);
outb(value, reg_base + reg);
outb(0x83, reg_base + 2);
}
static u8 read_reg(int reg)
{
u8 ret = 0;
inw(reg_base + 1);
inw(reg_base + 1);
outb(3, reg_base + 2);
ret = inb(reg_base + reg);
outb(0x83, reg_base + 2);
return ret;
}
static void opti621_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
ide_drive_t *pair = ide_get_pair_dev(drive);
unsigned long flags;
unsigned long mode = drive->pio_mode, pair_mode;
const u8 pio = mode - XFER_PIO_0;
u8 tim, misc, addr_pio = pio, clk;
static const u8 addr_timings[2][5] = {
{ 0x20, 0x10, 0x00, 0x00, 0x00 },
{ 0x10, 0x10, 0x00, 0x00, 0x00 },
};
static const u8 data_rec_timings[2][5] = {
{ 0x5b, 0x45, 0x32, 0x21, 0x20 },
{ 0x48, 0x34, 0x21, 0x10, 0x10 }
};
ide_set_drivedata(drive, (void *)mode);
if (pair) {
pair_mode = (unsigned long)ide_get_drivedata(pair);
if (pair_mode && pair_mode < mode)
addr_pio = pair_mode - XFER_PIO_0;
}
spin_lock_irqsave(&opti621_lock, flags);
reg_base = hwif->io_ports.data_addr;
outb(0xc0, reg_base + CNTRL_REG);
outb(0xff, reg_base + 5);
(void)inb(reg_base + CNTRL_REG);
read_reg(CNTRL_REG);
clk = read_reg(STRAP_REG) & 1;
printk(KERN_INFO "%s: CLK = %d MHz\n", hwif->name, clk ? 25 : 33);
tim = data_rec_timings[clk][pio];
misc = addr_timings[clk][addr_pio];
write_reg(drive->dn & 1, MISC_REG);
write_reg(tim, READ_REG);
write_reg(tim, WRITE_REG);
write_reg(0x85, CNTRL_REG);
write_reg(misc, MISC_REG);
spin_unlock_irqrestore(&opti621_lock, flags);
}
static int __devinit opti621_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
return ide_pci_init_one(dev, &opti621_chipset, NULL);
}
static int __init opti621_ide_init(void)
{
return ide_pci_register_driver(&opti621_pci_driver);
}
static void __exit opti621_ide_exit(void)
{
pci_unregister_driver(&opti621_pci_driver);
}
