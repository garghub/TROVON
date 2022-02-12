void __init u8500_map_io(void)
{
iotable_init(u8500_uart_io_desc, ARRAY_SIZE(u8500_uart_io_desc));
ux500_map_io();
iotable_init(u8500_io_desc, ARRAY_SIZE(u8500_io_desc));
_PRCMU_BASE = __io_address(U8500_PRCMU_BASE);
}
static irqreturn_t db8500_pmu_handler(int irq, void *dev, irq_handler_t handler)
{
irqreturn_t ret = handler(irq, dev);
int other = !smp_processor_id();
if (ret == IRQ_NONE && cpu_online(other))
irq_set_affinity(irq, cpumask_of(other));
return ret;
}
static void __init db8500_add_gpios(struct device *parent)
{
struct nmk_gpio_platform_data pdata = {
.supports_sleepmode = true,
};
dbx500_add_gpios(parent, ARRAY_AND_SIZE(db8500_gpio_base),
IRQ_DB8500_GPIO0, &pdata);
}
static const char *db8500_read_soc_id(void)
{
void __iomem *uid = __io_address(U8500_BB_UID_BASE);
return kasprintf(GFP_KERNEL, "%08x%08x%08x%08x%08x",
readl((u32 *)uid+1),
readl((u32 *)uid+1), readl((u32 *)uid+2),
readl((u32 *)uid+3), readl((u32 *)uid+4));
}
static struct device * __init db8500_soc_device_init(void)
{
const char *soc_id = db8500_read_soc_id();
return ux500_soc_device_init(soc_id);
}
struct device * __init u8500_init_devices(void)
{
struct device *parent;
int i;
parent = db8500_soc_device_init();
db8500_add_rtc(parent);
db8500_add_gpios(parent);
db8500_add_usb(parent, usb_db8500_rx_dma_cfg, usb_db8500_tx_dma_cfg);
platform_device_register_data(parent,
"cpufreq-u8500", -1, NULL, 0);
for (i = 0; i < ARRAY_SIZE(platform_devs); i++)
platform_devs[i]->dev.parent = parent;
platform_add_devices(platform_devs, ARRAY_SIZE(platform_devs));
return parent;
}
