static void __init r8a7779_map_io(void)
{
debug_ll_io_init();
iotable_init(r8a7779_io_desc, ARRAY_SIZE(r8a7779_io_desc));
}
static void __init r8a7779_init_irq_dt(void)
{
irqchip_init();
__raw_writel(0xffffffff, INT2NTSR0);
__raw_writel(0x3fffffff, INT2NTSR1);
__raw_writel(0xfffffff0, INT2SMSKCR0);
__raw_writel(0xfff7ffff, INT2SMSKCR1);
__raw_writel(0xfffbffdf, INT2SMSKCR2);
__raw_writel(0xbffffffc, INT2SMSKCR3);
__raw_writel(0x003fee3f, INT2SMSKCR4);
}
static u32 __init r8a7779_read_mode_pins(void)
{
static u32 mode;
static bool mode_valid;
if (!mode_valid) {
void __iomem *modemr = ioremap_nocache(MODEMR, PAGE_SIZE);
BUG_ON(!modemr);
mode = ioread32(modemr);
iounmap(modemr);
mode_valid = true;
}
return mode;
}
static void __init r8a7779_init_time(void)
{
r8a7779_clocks_init(r8a7779_read_mode_pins());
clocksource_of_init();
}
