static cycle_t read_cyclone(struct clocksource *cs)
{
return (cycle_t)readl(cyclone_ptr);
}
static int __init init_cyclone_clocksource(void)
{
unsigned long base;
unsigned long offset;
u32 __iomem* volatile cyclone_timer;
u32 __iomem* reg;
int i;
if (!use_cyclone)
return -ENODEV;
printk(KERN_INFO "Summit chipset: Starting Cyclone Counter.\n");
offset = CYCLONE_CBAR_ADDR;
reg = ioremap_nocache(offset, sizeof(reg));
if (!reg) {
printk(KERN_ERR "Summit chipset: Could not find valid CBAR register.\n");
return -ENODEV;
}
base = readl(reg);
iounmap(reg);
if (!base) {
printk(KERN_ERR "Summit chipset: Could not find valid CBAR value.\n");
return -ENODEV;
}
offset = base + CYCLONE_PMCC_OFFSET;
reg = ioremap_nocache(offset, sizeof(reg));
if (!reg) {
printk(KERN_ERR "Summit chipset: Could not find valid PMCC register.\n");
return -ENODEV;
}
writel(0x00000001,reg);
iounmap(reg);
offset = base + CYCLONE_MPCS_OFFSET;
reg = ioremap_nocache(offset, sizeof(reg));
if (!reg) {
printk(KERN_ERR "Summit chipset: Could not find valid MPCS register.\n");
return -ENODEV;
}
writel(0x00000001,reg);
iounmap(reg);
offset = base + CYCLONE_MPMC_OFFSET;
cyclone_timer = ioremap_nocache(offset, sizeof(u64));
if (!cyclone_timer) {
printk(KERN_ERR "Summit chipset: Could not find valid MPMC register.\n");
return -ENODEV;
}
for (i = 0; i < 3; i++){
u32 old = readl(cyclone_timer);
int stall = 100;
while (stall--)
barrier();
if (readl(cyclone_timer) == old) {
printk(KERN_ERR "Summit chipset: Counter not counting! DISABLED\n");
iounmap(cyclone_timer);
cyclone_timer = NULL;
return -ENODEV;
}
}
cyclone_ptr = cyclone_timer;
return clocksource_register_hz(&clocksource_cyclone,
CYCLONE_TIMER_FREQ);
}
