static inline u8 inReg(u8 reg)
{
outb_p(reg, regPort);
return inb(dataPort);
}
static void outReg(u8 data, u8 reg)
{
outb_p(reg, regPort);
outb_p(data, dataPort);
}
static void ali14xx_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
int driveNum;
int time1, time2;
u8 param1, param2, param3, param4;
unsigned long flags;
int bus_speed = ide_vlb_clk ? ide_vlb_clk : 50;
const u8 pio = drive->pio_mode - XFER_PIO_0;
struct ide_timing *t = ide_timing_find_mode(XFER_PIO_0 + pio);
time1 = ide_pio_cycle_time(drive, pio);
time2 = t->active;
param3 = param1 = (time2 * bus_speed + 999) / 1000;
param4 = param2 = (time1 * bus_speed + 999) / 1000 - param1;
if (pio < 3) {
param3 += 8;
param4 += 8;
}
printk(KERN_DEBUG "%s: PIO mode%d, t1=%dns, t2=%dns, cycles = %d+%d, %d+%d\n",
drive->name, pio, time1, time2, param1, param2, param3, param4);
driveNum = (drive->hwif->index << 1) + (drive->dn & 1);
spin_lock_irqsave(&ali14xx_lock, flags);
outb_p(regOn, basePort);
outReg(param1, regTab[driveNum].reg1);
outReg(param2, regTab[driveNum].reg2);
outReg(param3, regTab[driveNum].reg3);
outReg(param4, regTab[driveNum].reg4);
outb_p(regOff, basePort);
spin_unlock_irqrestore(&ali14xx_lock, flags);
}
static int __init findPort(void)
{
int i;
u8 t;
unsigned long flags;
local_irq_save(flags);
for (i = 0; i < ALI_NUM_PORTS; ++i) {
basePort = ports[i];
regOff = inb(basePort);
for (regOn = 0x30; regOn <= 0x33; ++regOn) {
outb_p(regOn, basePort);
if (inb(basePort) == regOn) {
regPort = basePort + 4;
dataPort = basePort + 8;
t = inReg(0) & 0xf0;
outb_p(regOff, basePort);
local_irq_restore(flags);
if (t != 0x50)
return 0;
return 1;
}
}
outb_p(regOff, basePort);
}
local_irq_restore(flags);
return 0;
}
static int __init initRegisters(void)
{
const RegInitializer *p;
u8 t;
unsigned long flags;
local_irq_save(flags);
outb_p(regOn, basePort);
for (p = initData; p->reg != 0; ++p)
outReg(p->data, p->reg);
outb_p(0x01, regPort);
t = inb(regPort) & 0x01;
outb_p(regOff, basePort);
local_irq_restore(flags);
return t;
}
static int __init ali14xx_probe(void)
{
printk(KERN_DEBUG "ali14xx: base=0x%03x, regOn=0x%02x.\n",
basePort, regOn);
if (!initRegisters()) {
printk(KERN_ERR "ali14xx: Chip initialization failed.\n");
return 1;
}
return ide_legacy_device_add(&ali14xx_port_info, 0);
}
static int __init ali14xx_init(void)
{
if (probe_ali14xx == 0)
goto out;
if (findPort()) {
if (ali14xx_probe())
return -ENODEV;
return 0;
}
printk(KERN_ERR "ali14xx: not found.\n");
out:
return -ENODEV;
}
