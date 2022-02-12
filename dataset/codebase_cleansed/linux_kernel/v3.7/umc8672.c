static void out_umc(char port, char wert)
{
outb_p(port, 0x108);
outb_p(wert, 0x109);
}
static inline u8 in_umc(char port)
{
outb_p(port, 0x108);
return inb_p(0x109);
}
static void umc_set_speeds(u8 speeds[])
{
int i, tmp;
outb_p(0x5A, 0x108);
out_umc(0xd7, (speedtab[0][speeds[2]] | (speedtab[0][speeds[3]]<<4)));
out_umc(0xd6, (speedtab[0][speeds[0]] | (speedtab[0][speeds[1]]<<4)));
tmp = 0;
for (i = 3; i >= 0; i--)
tmp = (tmp << 2) | speedtab[1][speeds[i]];
out_umc(0xdc, tmp);
for (i = 0; i < 4; i++) {
out_umc(0xd0 + i, speedtab[2][speeds[i]]);
out_umc(0xd8 + i, speedtab[2][speeds[i]]);
}
outb_p(0xa5, 0x108);
printk("umc8672: drive speeds [0 to 11]: %d %d %d %d\n",
speeds[0], speeds[1], speeds[2], speeds[3]);
}
static void umc_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
ide_hwif_t *mate = hwif->mate;
unsigned long uninitialized_var(flags);
const u8 pio = drive->pio_mode - XFER_PIO_0;
printk("%s: setting umc8672 to PIO mode%d (speed %d)\n",
drive->name, pio, pio_to_umc[pio]);
if (mate)
spin_lock_irqsave(&mate->lock, flags);
if (mate && mate->handler) {
printk(KERN_ERR "umc8672: other interface is busy: exiting tune_umc()\n");
} else {
current_speeds[drive->name[2] - 'a'] = pio_to_umc[pio];
umc_set_speeds(current_speeds);
}
if (mate)
spin_unlock_irqrestore(&mate->lock, flags);
}
static int __init umc8672_probe(void)
{
unsigned long flags;
if (!request_region(0x108, 2, "umc8672")) {
printk(KERN_ERR "umc8672: ports 0x108-0x109 already in use.\n");
return 1;
}
local_irq_save(flags);
outb_p(0x5A, 0x108);
if (in_umc (0xd5) != 0xa0) {
local_irq_restore(flags);
printk(KERN_ERR "umc8672: not found\n");
release_region(0x108, 2);
return 1;
}
outb_p(0xa5, 0x108);
umc_set_speeds(current_speeds);
local_irq_restore(flags);
return ide_legacy_device_add(&umc8672_port_info, 0);
}
static int __init umc8672_init(void)
{
if (probe_umc8672 == 0)
goto out;
if (umc8672_probe() == 0)
return 0;
out:
return -ENODEV;
}
