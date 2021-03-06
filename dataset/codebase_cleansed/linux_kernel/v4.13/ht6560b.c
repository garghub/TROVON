static inline u8 HT_CONFIG(ide_drive_t *drive)
{
return ((unsigned long)ide_get_drivedata(drive) & 0xff00) >> 8;
}
static inline u8 HT_TIMING(ide_drive_t *drive)
{
return (unsigned long)ide_get_drivedata(drive) & 0x00ff;
}
static void ht6560b_dev_select(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
unsigned long flags;
static u8 current_select = 0;
static u8 current_timing = 0;
u8 select, timing;
local_irq_save(flags);
select = HT_CONFIG(drive);
timing = HT_TIMING(drive);
if (drive->media != ide_disk ||
(drive->dev_flags & IDE_DFLAG_PRESENT) == 0)
select |= HT_PREFETCH_MODE;
if (select != current_select || timing != current_timing) {
current_select = select;
current_timing = timing;
(void)inb(HT_CONFIG_PORT);
(void)inb(HT_CONFIG_PORT);
(void)inb(HT_CONFIG_PORT);
(void)inb(HT_CONFIG_PORT);
outb(select, HT_CONFIG_PORT);
outb(timing, hwif->io_ports.device_addr);
(void)inb(hwif->io_ports.status_addr);
#ifdef DEBUG
printk("ht6560b: %s: select=%#x timing=%#x\n",
drive->name, select, timing);
#endif
}
local_irq_restore(flags);
outb(drive->select | ATA_DEVICE_OBS, hwif->io_ports.device_addr);
}
static int __init try_to_init_ht6560b(void)
{
u8 orig_value;
int i;
if ((orig_value = inb(HT_CONFIG_PORT)) == 0xff)
return 0;
for (i=3;i>0;i--) {
outb(0x00, HT_CONFIG_PORT);
if (!( (~inb(HT_CONFIG_PORT)) & 0x3f )) {
outb(orig_value, HT_CONFIG_PORT);
return 0;
}
}
outb(0x00, HT_CONFIG_PORT);
if ((~inb(HT_CONFIG_PORT))& 0x3f) {
outb(orig_value, HT_CONFIG_PORT);
return 0;
}
outb(HT_CONFIG_DEFAULT, HT_CONFIG_PORT);
outb(HT_TIMING_DEFAULT, 0x1f6);
(void)inb(0x1f7);
printk("ht6560b " HT6560B_VERSION
": chipset detected and initialized"
#ifdef DEBUG
" with debug enabled"
#endif
"\n"
);
return 1;
}
static u8 ht_pio2timings(ide_drive_t *drive, const u8 pio)
{
int active_time, recovery_time;
int active_cycles, recovery_cycles;
int bus_speed = ide_vlb_clk ? ide_vlb_clk : 50;
if (pio) {
unsigned int cycle_time;
struct ide_timing *t = ide_timing_find_mode(XFER_PIO_0 + pio);
cycle_time = ide_pio_cycle_time(drive, pio);
active_time = t->active;
recovery_time = cycle_time - active_time - t->setup;
active_cycles = (active_time * bus_speed + 999) / 1000;
recovery_cycles = (recovery_time * bus_speed + 999) / 1000;
if (active_cycles < 2) active_cycles = 2;
if (recovery_cycles < 2) recovery_cycles = 2;
if (active_cycles > 15) active_cycles = 15;
if (recovery_cycles > 15) recovery_cycles = 0;
#ifdef DEBUG
printk("ht6560b: drive %s setting pio=%d recovery=%d (%dns) active=%d (%dns)\n", drive->name, pio, recovery_cycles, recovery_time, active_cycles, active_time);
#endif
return (u8)((recovery_cycles << 4) | active_cycles);
} else {
#ifdef DEBUG
printk("ht6560b: drive %s setting pio=0\n", drive->name);
#endif
return HT_TIMING_DEFAULT;
}
}
static void ht_set_prefetch(ide_drive_t *drive, u8 state)
{
unsigned long flags, config;
int t = HT_PREFETCH_MODE << 8;
spin_lock_irqsave(&ht6560b_lock, flags);
config = (unsigned long)ide_get_drivedata(drive);
if (state) {
config |= t;
drive->dev_flags |= IDE_DFLAG_NO_UNMASK;
drive->dev_flags &= ~IDE_DFLAG_UNMASK;
} else {
config &= ~t;
drive->dev_flags &= ~IDE_DFLAG_NO_UNMASK;
}
ide_set_drivedata(drive, (void *)config);
spin_unlock_irqrestore(&ht6560b_lock, flags);
#ifdef DEBUG
printk("ht6560b: drive %s prefetch mode %sabled\n", drive->name, (state ? "en" : "dis"));
#endif
}
static void ht6560b_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
unsigned long flags, config;
const u8 pio = drive->pio_mode - XFER_PIO_0;
u8 timing;
switch (pio) {
case 8:
case 9:
ht_set_prefetch(drive, pio & 1);
return;
}
timing = ht_pio2timings(drive, pio);
spin_lock_irqsave(&ht6560b_lock, flags);
config = (unsigned long)ide_get_drivedata(drive);
config &= 0xff00;
config |= timing;
ide_set_drivedata(drive, (void *)config);
spin_unlock_irqrestore(&ht6560b_lock, flags);
#ifdef DEBUG
printk("ht6560b: drive %s tuned to pio mode %#x timing=%#x\n", drive->name, pio, timing);
#endif
}
static void __init ht6560b_init_dev(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
int t = (HT_CONFIG_DEFAULT << 8) | HT_TIMING_DEFAULT;
if (hwif->channel)
t |= (HT_SECONDARY_IF << 8);
ide_set_drivedata(drive, (void *)t);
}
static int __init ht6560b_init(void)
{
if (probe_ht6560b == 0)
return -ENODEV;
if (!request_region(HT_CONFIG_PORT, 1, DRV_NAME)) {
printk(KERN_NOTICE "%s: HT_CONFIG_PORT not found\n",
__func__);
return -ENODEV;
}
if (!try_to_init_ht6560b()) {
printk(KERN_NOTICE "%s: HBA not found\n", __func__);
goto release_region;
}
return ide_legacy_device_add(&ht6560b_port_info, 0);
release_region:
release_region(HT_CONFIG_PORT, 1);
return -ENODEV;
}
