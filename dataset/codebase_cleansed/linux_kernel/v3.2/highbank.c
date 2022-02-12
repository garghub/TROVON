static void __init highbank_scu_map_io(void)
{
unsigned long base;
asm("mrc p15, 4, %0, c15, c0, 0" : "=r" (base));
scu_io_desc.pfn = __phys_to_pfn(base);
iotable_init(&scu_io_desc, 1);
}
static void __init highbank_map_io(void)
{
highbank_scu_map_io();
highbank_lluart_map_io();
}
void highbank_set_cpu_jump(int cpu, void *jump_addr)
{
#ifdef CONFIG_SMP
cpu = cpu_logical_map(cpu);
#endif
writel(BSYM(virt_to_phys(jump_addr)), HB_JUMP_TABLE_VIRT(cpu));
__cpuc_flush_dcache_area(HB_JUMP_TABLE_VIRT(cpu), 16);
outer_clean_range(HB_JUMP_TABLE_PHYS(cpu),
HB_JUMP_TABLE_PHYS(cpu) + 15);
}
static void __init highbank_init_irq(void)
{
of_irq_init(irq_match);
l2x0_of_init(0, ~0UL);
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
highbank_clocks_init();
sp804_clocksource_init(timer_base + 0x20, "timer1");
sp804_clockevents_init(timer_base, irq, "timer0");
}
static void highbank_power_off(void)
{
hignbank_set_pwr_shutdown();
scu_power_mode(scu_base_addr, SCU_PM_POWEROFF);
while (1)
cpu_do_idle();
}
static void __init highbank_init(void)
{
pm_power_off = highbank_power_off;
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
