void __init u8500_map_io(void)
{
iotable_init(u8500_uart_io_desc, ARRAY_SIZE(u8500_uart_io_desc));
ux500_map_io();
iotable_init(u8500_common_io_desc, ARRAY_SIZE(u8500_common_io_desc));
if (cpu_is_ux540_family())
iotable_init(u9540_io_desc, ARRAY_SIZE(u9540_io_desc));
else
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
dbx500_add_pinctrl(parent, "pinctrl-db8500", U8500_PRCMU_BASE);
}
static const char *db8500_read_soc_id(void)
{
void __iomem *uid = __io_address(U8500_BB_UID_BASE);
add_device_randomness(uid, 0x14);
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
struct device * __init u8500_init_devices(struct ab8500_platform_data *ab8500)
{
struct device *parent;
int i;
parent = db8500_soc_device_init();
db8500_add_rtc(parent);
db8500_add_gpios(parent);
db8500_add_usb(parent, usb_db8500_rx_dma_cfg, usb_db8500_tx_dma_cfg);
for (i = 0; i < ARRAY_SIZE(platform_devs); i++)
platform_devs[i]->dev.parent = parent;
db8500_prcmu_device.dev.platform_data = ab8500;
platform_add_devices(platform_devs, ARRAY_SIZE(platform_devs));
return parent;
}
static struct device * __init u8500_of_init_devices(void)
{
struct device *parent = db8500_soc_device_init();
db8500_add_usb(parent, usb_db8500_rx_dma_cfg, usb_db8500_tx_dma_cfg);
u8500_dma40_device.dev.parent = parent;
platform_device_register(&u8500_dma40_device);
return parent;
}
static void __init u8500_init_machine(void)
{
struct device *parent = NULL;
if (of_machine_is_compatible("st-ericsson,mop500"))
mop500_pinmaps_init();
else if (of_machine_is_compatible("calaosystems,snowball-a9500"))
snowball_pinmaps_init();
else if (of_machine_is_compatible("st-ericsson,hrefv60+"))
hrefv60_pinmaps_init();
else if (of_machine_is_compatible("st-ericsson,ccu9540")) {}
parent = u8500_of_init_devices();
of_platform_populate(NULL, u8500_local_bus_nodes, u8500_auxdata_lookup, parent);
}
