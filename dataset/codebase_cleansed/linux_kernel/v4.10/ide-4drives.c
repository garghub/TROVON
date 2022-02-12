static void ide_4drives_init_dev(ide_drive_t *drive)
{
if (drive->hwif->channel)
drive->select ^= 0x20;
}
static int __init ide_4drives_init(void)
{
unsigned long base = 0x1f0, ctl = 0x3f6;
struct ide_hw hw, *hws[] = { &hw, &hw };
if (probe_4drives == 0)
return -ENODEV;
if (!request_region(base, 8, DRV_NAME)) {
printk(KERN_ERR "%s: I/O resource 0x%lX-0x%lX not free.\n",
DRV_NAME, base, base + 7);
return -EBUSY;
}
if (!request_region(ctl, 1, DRV_NAME)) {
printk(KERN_ERR "%s: I/O resource 0x%lX not free.\n",
DRV_NAME, ctl);
release_region(base, 8);
return -EBUSY;
}
memset(&hw, 0, sizeof(hw));
ide_std_init_ports(&hw, base, ctl);
hw.irq = 14;
return ide_host_add(&ide_4drives_port_info, hws, 2, NULL);
}
