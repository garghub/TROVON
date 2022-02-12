void __init u8500_map_io(void)
{
iotable_init(u8500_uart_io_desc, ARRAY_SIZE(u8500_uart_io_desc));
ux500_map_io();
iotable_init(u8500_common_io_desc, ARRAY_SIZE(u8500_common_io_desc));
if (cpu_is_ux540_family())
iotable_init(u9540_io_desc, ARRAY_SIZE(u9540_io_desc));
else
iotable_init(u8500_io_desc, ARRAY_SIZE(u8500_io_desc));
}
static irqreturn_t db8500_pmu_handler(int irq, void *dev, irq_handler_t handler)
{
irqreturn_t ret = handler(irq, dev);
int other = !smp_processor_id();
if (ret == IRQ_NONE && cpu_online(other))
irq_set_affinity(irq, cpumask_of(other));
return ret;
}
static const char *db8500_read_soc_id(void)
{
void __iomem *uid = __io_address(U8500_BB_UID_BASE);
add_device_randomness(uid, 0x14);
return kasprintf(GFP_KERNEL, "%08x%08x%08x%08x%08x",
readl((u32 *)uid+0),
readl((u32 *)uid+1), readl((u32 *)uid+2),
readl((u32 *)uid+3), readl((u32 *)uid+4));
}
static struct device * __init db8500_soc_device_init(void)
{
const char *soc_id = db8500_read_soc_id();
return ux500_soc_device_init(soc_id);
}
static void __init u8500_init_machine(void)
{
struct device *parent = db8500_soc_device_init();
if (of_machine_is_compatible("st-ericsson,u8540"))
of_platform_populate(NULL, u8500_local_bus_nodes,
u8540_auxdata_lookup, parent);
else
of_platform_populate(NULL, u8500_local_bus_nodes,
u8500_auxdata_lookup, parent);
}
