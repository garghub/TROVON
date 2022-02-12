static int __init net2272_init(void)
{
#if IS_ENABLED(CONFIG_USB_NET2272)
int ret;
ret = gpio_request(GPIO_PG14, "net2272");
if (ret)
return ret;
gpio_direction_output(GPIO_PG14, 0);
mdelay(2);
gpio_set_value(GPIO_PG14, 1);
#endif
return 0;
}
static int __init tcm_bf537_init(void)
{
printk(KERN_INFO "%s(): registering device resources\n", __func__);
platform_add_devices(cm_bf537_devices, ARRAY_SIZE(cm_bf537_devices));
#if IS_ENABLED(CONFIG_SPI_BFIN5XX)
spi_register_board_info(bfin_spi_board_info, ARRAY_SIZE(bfin_spi_board_info));
#endif
#if IS_ENABLED(CONFIG_PATA_PLATFORM)
irq_set_status_flags(PATA_INT, IRQ_NOAUTOEN);
#endif
if (net2272_init())
pr_warning("unable to configure net2272; it probably won't work\n");
return 0;
}
void __init native_machine_early_platform_add_devices(void)
{
printk(KERN_INFO "register early platform devices\n");
early_platform_add_devices(cm_bf537_early_devices,
ARRAY_SIZE(cm_bf537_early_devices));
}
int bfin_get_ether_addr(char *addr)
{
return 1;
}
