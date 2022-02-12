static u64 notrace versatile_sys_24mhz_read(void)
{
return readl(versatile_sys_24mhz);
}
static void __init versatile_sched_clock_init(struct device_node *node)
{
void __iomem *base = of_iomap(node, 0);
if (!base)
return;
versatile_sys_24mhz = base + SYS_24MHZ;
sched_clock_register(versatile_sys_24mhz_read, 32, 24000000);
}
