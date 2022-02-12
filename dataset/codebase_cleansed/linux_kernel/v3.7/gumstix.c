static void __init gumstix_mmc_init(void)
{
pxa_set_mci_info(&gumstix_mci_platform_data);
}
static void __init gumstix_mmc_init(void)
{
pr_debug("Gumstix mmc disabled\n");
}
static void __init gumstix_udc_init(void)
{
platform_device_register(&gumstix_gpio_vbus);
}
static void gumstix_udc_init(void)
{
pr_debug("Gumstix udc is disabled\n");
}
static void gumstix_setup_bt_clock(void)
{
int timeout = 500;
if (!(OSCC & OSCC_OOK))
pr_warning("32kHz clock was not on. Bootloader may need to "
"be updated\n");
else
return;
OSCC |= OSCC_OON;
do {
if (OSCC & OSCC_OOK)
break;
udelay(1);
} while (--timeout);
if (!timeout)
pr_err("Failed to start 32kHz clock\n");
}
static void __init gumstix_bluetooth_init(void)
{
int err;
gumstix_setup_bt_clock();
err = gpio_request(GPIO_GUMSTIX_BTRESET, "BTRST");
if (err) {
pr_err("gumstix: failed request gpio for bluetooth reset\n");
return;
}
err = gpio_direction_output(GPIO_GUMSTIX_BTRESET, 1);
if (err) {
pr_err("gumstix: can't reset bluetooth\n");
return;
}
gpio_set_value(GPIO_GUMSTIX_BTRESET, 0);
udelay(100);
gpio_set_value(GPIO_GUMSTIX_BTRESET, 1);
}
static void gumstix_bluetooth_init(void)
{
pr_debug("Gumstix Bluetooth is disabled\n");
}
static void __init carrier_board_init(void)
{
am200_init();
am300_init();
}
static void __init gumstix_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(gumstix_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
pxa_set_hwuart_info(NULL);
gumstix_bluetooth_init();
gumstix_udc_init();
gumstix_mmc_init();
(void) platform_add_devices(devices, ARRAY_SIZE(devices));
carrier_board_init();
}
