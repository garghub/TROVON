static int __init net2272_init(void)
{
#if defined(CONFIG_USB_NET2272) || defined(CONFIG_USB_NET2272_MODULE)
int ret;
ret = gpio_request(GPIO_PF46, "net2272");
if (ret)
return ret;
gpio_direction_output(GPIO_PF46, 0);
mdelay(2);
gpio_set_value(GPIO_PF46, 1);
#endif
return 0;
}
static int __init cm_bf561_init(void)
{
printk(KERN_INFO "%s(): registering device resources\n", __func__);
platform_add_devices(cm_bf561_devices, ARRAY_SIZE(cm_bf561_devices));
#if defined(CONFIG_SPI_BFIN) || defined(CONFIG_SPI_BFIN_MODULE)
spi_register_board_info(bfin_spi_board_info, ARRAY_SIZE(bfin_spi_board_info));
#endif
#if defined(CONFIG_PATA_PLATFORM) || defined(CONFIG_PATA_PLATFORM_MODULE)
irq_set_status_flags(PATA_INT, IRQ_NOAUTOEN);
#endif
if (net2272_init())
pr_warning("unable to configure net2272; it probably won't work\n");
return 0;
}
void __init native_machine_early_platform_add_devices(void)
{
printk(KERN_INFO "register early platform devices\n");
early_platform_add_devices(cm_bf561_early_devices,
ARRAY_SIZE(cm_bf561_early_devices));
}
