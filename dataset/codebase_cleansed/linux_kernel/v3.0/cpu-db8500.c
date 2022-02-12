void __init u8500_map_io(void)
{
iotable_init(u8500_uart_io_desc, ARRAY_SIZE(u8500_uart_io_desc));
ux500_map_io();
iotable_init(u8500_io_desc, ARRAY_SIZE(u8500_io_desc));
if (cpu_is_u8500ed())
iotable_init(u8500_ed_io_desc, ARRAY_SIZE(u8500_ed_io_desc));
else if (cpu_is_u8500v1())
iotable_init(u8500_v1_io_desc, ARRAY_SIZE(u8500_v1_io_desc));
else if (cpu_is_u8500v2())
iotable_init(u8500_v2_io_desc, ARRAY_SIZE(u8500_v2_io_desc));
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
static void __init db8500_add_gpios(void)
{
struct nmk_gpio_platform_data pdata = {
};
if (cpu_is_u8500v2())
pdata.supports_sleepmode = true;
dbx500_add_gpios(ARRAY_AND_SIZE(db8500_gpio_base),
IRQ_DB8500_GPIO0, &pdata);
}
void __init u8500_init_devices(void)
{
if (cpu_is_u8500ed())
dma40_u8500ed_fixup();
db8500_add_rtc();
db8500_add_gpios();
db8500_add_usb(usb_db8500_rx_dma_cfg, usb_db8500_tx_dma_cfg);
platform_device_register_simple("cpufreq-u8500", -1, NULL, 0);
platform_add_devices(platform_devs, ARRAY_SIZE(platform_devs));
return ;
}
