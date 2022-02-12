static void __init highbank_scu_map_io(void)
{
unsigned long base;
asm("mrc p15, 4, %0, c15, c0, 0" : "=r" (base));
scu_base_addr = ioremap(base, SZ_4K);
}
void highbank_set_cpu_jump(int cpu, void *jump_addr)
{
cpu = MPIDR_AFFINITY_LEVEL(cpu_logical_map(cpu), 0);
writel(virt_to_phys(jump_addr), HB_JUMP_TABLE_VIRT(cpu));
__cpuc_flush_dcache_area(HB_JUMP_TABLE_VIRT(cpu), 16);
outer_clean_range(HB_JUMP_TABLE_PHYS(cpu),
HB_JUMP_TABLE_PHYS(cpu) + 15);
}
static void highbank_l2x0_disable(void)
{
highbank_smc1(0x102, 0x0);
}
static void __init highbank_init_irq(void)
{
irqchip_init();
if (of_find_compatible_node(NULL, NULL, "arm,cortex-a9"))
highbank_scu_map_io();
#ifdef CONFIG_CACHE_L2X0
highbank_smc1(0x102, 0x1);
l2x0_of_init(0, ~0UL);
outer_cache.disable = highbank_l2x0_disable;
#endif
}
static void __init highbank_timer_init(void)
{
int irq;
struct device_node *np;
void __iomem *timer_base;
np = of_find_compatible_node(NULL, NULL, "calxeda,hb-sregs");
sregs_base = of_iomap(np, 0);
WARN_ON(!sregs_base);
np = of_find_compatible_node(NULL, NULL, "arm,sp804");
timer_base = of_iomap(np, 0);
WARN_ON(!timer_base);
irq = irq_of_parse_and_map(np, 0);
of_clk_init(NULL);
lookup.clk = of_clk_get(np, 0);
clkdev_add(&lookup);
sp804_clocksource_and_sched_clock_init(timer_base + 0x20, "timer1");
sp804_clockevents_init(timer_base, irq, "timer0");
twd_local_timer_of_register();
arch_timer_of_register();
arch_timer_sched_clock_init();
}
static void highbank_power_off(void)
{
highbank_set_pwr_shutdown();
while (1)
cpu_do_idle();
}
static int highbank_platform_notifier(struct notifier_block *nb,
unsigned long event, void *__dev)
{
struct resource *res;
int reg = -1;
struct device *dev = __dev;
if (event != BUS_NOTIFY_ADD_DEVICE)
return NOTIFY_DONE;
if (of_device_is_compatible(dev->of_node, "calxeda,hb-ahci"))
reg = 0xc;
else if (of_device_is_compatible(dev->of_node, "calxeda,hb-sdhci"))
reg = 0x18;
else if (of_device_is_compatible(dev->of_node, "arm,pl330"))
reg = 0x20;
else if (of_device_is_compatible(dev->of_node, "calxeda,hb-xgmac")) {
res = platform_get_resource(to_platform_device(dev),
IORESOURCE_MEM, 0);
if (res) {
if (res->start == 0xfff50000)
reg = 0;
else if (res->start == 0xfff51000)
reg = 4;
}
}
if (reg < 0)
return NOTIFY_DONE;
if (of_property_read_bool(dev->of_node, "dma-coherent")) {
writel(0xff31, sregs_base + reg);
set_dma_ops(dev, &arm_coherent_dma_ops);
} else
writel(0, sregs_base + reg);
return NOTIFY_OK;
}
static void __init highbank_init(void)
{
pm_power_off = highbank_power_off;
highbank_pm_init();
bus_register_notifier(&platform_bus_type, &highbank_platform_nb);
bus_register_notifier(&amba_bustype, &highbank_amba_nb);
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
