static void __init db5500_add_gpios(void)
{
struct nmk_gpio_platform_data pdata = {
};
dbx500_add_gpios(ARRAY_AND_SIZE(db5500_gpio_base),
IRQ_DB5500_GPIO0, &pdata);
}
void __init u5500_map_io(void)
{
iotable_init(u5500_uart_io_desc, ARRAY_SIZE(u5500_uart_io_desc));
ux500_map_io();
iotable_init(u5500_io_desc, ARRAY_SIZE(u5500_io_desc));
_PRCMU_BASE = __io_address(U5500_PRCMU_BASE);
}
void __init u5500_init_devices(void)
{
db5500_add_gpios();
db5500_dma_init();
db5500_add_rtc();
db5500_add_usb(usb_db5500_rx_dma_cfg, usb_db5500_tx_dma_cfg);
platform_add_devices(db5500_platform_devs,
ARRAY_SIZE(db5500_platform_devs));
}
