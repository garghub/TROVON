static int __init ux500_l2x0_unlock(void)
{
int i;
struct device_node *np;
void __iomem *l2x0_base;
np = of_find_compatible_node(NULL, NULL, "arm,pl310-cache");
l2x0_base = of_iomap(np, 0);
of_node_put(np);
if (!l2x0_base)
return -ENODEV;
for (i = 0; i < 8; i++) {
writel_relaxed(0x0, l2x0_base + L2X0_LOCKDOWN_WAY_D_BASE +
i * L2X0_LOCKDOWN_STRIDE);
writel_relaxed(0x0, l2x0_base + L2X0_LOCKDOWN_WAY_I_BASE +
i * L2X0_LOCKDOWN_STRIDE);
}
iounmap(l2x0_base);
return 0;
}
static void ux500_l2c310_write_sec(unsigned long val, unsigned reg)
{
}
static void __init ux500_init_irq(void)
{
struct device_node *np;
struct resource r;
irqchip_init();
np = of_find_compatible_node(NULL, NULL, "stericsson,db8500-prcmu");
of_address_to_resource(np, 0, &r);
of_node_put(np);
if (!r.start) {
pr_err("could not find PRCMU base resource\n");
return;
}
prcmu_early_init(r.start, r.end-r.start);
ux500_pm_init(r.start, r.end-r.start);
ux500_l2x0_unlock();
outer_cache.write_sec = ux500_l2c310_write_sec;
}
static void ux500_restart(enum reboot_mode mode, const char *cmd)
{
local_irq_disable();
local_fiq_disable();
prcmu_system_reset(0);
}
static irqreturn_t db8500_pmu_handler(int irq, void *dev, irq_handler_t handler)
{
irqreturn_t ret = handler(irq, dev);
int other = !smp_processor_id();
if (ret == IRQ_NONE && cpu_online(other))
irq_set_affinity(irq, cpumask_of(other));
return ret;
}
static void __init u8500_init_machine(void)
{
ux500_pm_domains_init();
if (of_machine_is_compatible("st-ericsson,u8540"))
of_platform_populate(NULL, u8500_local_bus_nodes,
u8540_auxdata_lookup, NULL);
else
of_platform_populate(NULL, u8500_local_bus_nodes,
u8500_auxdata_lookup, NULL);
}
