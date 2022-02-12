static void __init db5500_add_gpios(struct device *parent)
{
struct nmk_gpio_platform_data pdata = {
};
dbx500_add_gpios(parent, ARRAY_AND_SIZE(db5500_gpio_base),
IRQ_DB5500_GPIO0, &pdata);
}
void __init u5500_map_io(void)
{
iotable_init(u5500_uart_io_desc, ARRAY_SIZE(u5500_uart_io_desc));
ux500_map_io();
iotable_init(u5500_io_desc, ARRAY_SIZE(u5500_io_desc));
_PRCMU_BASE = __io_address(U5500_PRCMU_BASE);
}
static void __init db5500_pmu_init(void)
{
struct resource res[] = {
[0] = {
.start = IRQ_DB5500_PMU0,
.end = IRQ_DB5500_PMU0,
.flags = IORESOURCE_IRQ,
},
[1] = {
.start = IRQ_DB5500_PMU1,
.end = IRQ_DB5500_PMU1,
.flags = IORESOURCE_IRQ,
},
};
platform_device_register_simple("arm-pmu", ARM_PMU_DEVICE_CPU,
res, ARRAY_SIZE(res));
}
static const char *db5500_read_soc_id(void)
{
return kasprintf(GFP_KERNEL, "u5500 currently unsupported\n");
}
static struct device * __init db5500_soc_device_init(void)
{
const char *soc_id = db5500_read_soc_id();
return ux500_soc_device_init(soc_id);
}
struct device * __init u5500_init_devices(void)
{
struct device *parent;
int i;
parent = db5500_soc_device_init();
db5500_add_gpios(parent);
db5500_pmu_init();
db5500_dma_init(parent);
db5500_add_rtc(parent);
db5500_add_usb(parent, usb_db5500_rx_dma_cfg, usb_db5500_tx_dma_cfg);
for (i = 0; i < ARRAY_SIZE(db5500_platform_devs); i++)
db5500_platform_devs[i]->dev.parent = parent;
platform_add_devices(db5500_platform_devs,
ARRAY_SIZE(db5500_platform_devs));
return parent;
}
