static void __init intcp_map_io(void)
{
iotable_init(intcp_io_desc, ARRAY_SIZE(intcp_io_desc));
}
static unsigned int mmc_status(struct device *dev)
{
unsigned int status = readl(__io_address(0xca000000 + 4));
writel(8, intcp_con_base + 8);
return status & 8;
}
static u64 notrace intcp_read_sched_clock(void)
{
unsigned int val;
regmap_read(cm_map, CM_COUNTER_OFFSET, &val);
return val;
}
static void __init intcp_init_early(void)
{
cm_map = syscon_regmap_lookup_by_compatible("arm,core-module-integrator");
if (IS_ERR(cm_map))
return;
sched_clock_register(intcp_read_sched_clock, 32, 24000000);
}
static void __init intcp_init_irq_of(void)
{
cm_init();
irqchip_init();
}
static void __init intcp_init_of(void)
{
struct device_node *cpcon;
cpcon = of_find_matching_node(NULL, intcp_syscon_match);
if (!cpcon)
return;
intcp_con_base = of_iomap(cpcon, 0);
if (!intcp_con_base)
return;
of_platform_default_populate(NULL, intcp_auxdata_lookup, NULL);
}
