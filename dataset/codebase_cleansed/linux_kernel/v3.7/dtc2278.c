static void sub22 (char b, char c)
{
int i;
for(i = 0; i < 3; ++i) {
inb(0x3f6);
outb_p(b,0xb0);
inb(0x3f6);
outb_p(c,0xb4);
inb(0x3f6);
if(inb(0xb4) == c) {
outb_p(7,0xb0);
inb(0x3f6);
return;
}
}
}
static void dtc2278_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
unsigned long flags;
if (drive->pio_mode >= XFER_PIO_3) {
spin_lock_irqsave(&dtc2278_lock, flags);
sub22(1,0xc3);
sub22(0,0xa0);
spin_unlock_irqrestore(&dtc2278_lock, flags);
} else {
}
}
static int __init dtc2278_probe(void)
{
unsigned long flags;
local_irq_save(flags);
outb_p(4,0xb0);
inb(0x3f6);
outb_p(0x20,0xb4);
inb(0x3f6);
#ifdef ALWAYS_SET_DTC2278_PIO_MODE
sub22(1,0xc3);
sub22(0,0xa0);
#endif
local_irq_restore(flags);
return ide_legacy_device_add(&dtc2278_port_info, 0);
}
static int __init dtc2278_init(void)
{
if (probe_dtc2278 == 0)
return -ENODEV;
if (dtc2278_probe()) {
printk(KERN_ERR "dtc2278: ide interfaces already in use!\n");
return -EBUSY;
}
return 0;
}
