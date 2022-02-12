static int gplugd_eth_init(void)
{
if (unlikely(gpio_request(104, "ETH_RESET_N"))) {
printk(KERN_ERR "Can't get hold of GPIO 104 to bring Ethernet "
"PHY out of reset\n");
return -EIO;
}
gpio_direction_output(104, 1);
gpio_free(104);
return 0;
}
static void __init select_disp_freq(void)
{
if (unlikely(gpio_request(35, "DISP_FREQ_SEL"))) {
printk(KERN_ERR "Can't get hold of GPIO 35 to select display "
"frequency\n");
} else {
gpio_direction_output(35, 1);
gpio_free(35);
}
if (unlikely(gpio_request(85, "DISP_FREQ_SEL_2"))) {
printk(KERN_ERR "Can't get hold of GPIO 85 to select display "
"frequency\n");
} else {
gpio_direction_output(85, 0);
gpio_free(85);
}
}
static void __init gplugd_init(void)
{
mfp_config(ARRAY_AND_SIZE(gplugd_pin_config));
select_disp_freq();
pxa168_add_uart(3);
pxa168_add_ssp(1);
pxa168_add_twsi(0, NULL, ARRAY_AND_SIZE(gplugd_i2c_board_info));
platform_device_add_data(&pxa168_device_gpio, &pxa168_gpio_pdata,
sizeof(struct pxa_gpio_platform_data));
platform_device_register(&pxa168_device_gpio);
pxa168_add_eth(&gplugd_eth_platform_data);
}
