static int bu21013_gpio_board_init(int reset_pin)
{
int retval = 0;
bu21013_devices++;
if (bu21013_devices == 1) {
retval = gpio_request(reset_pin, "touchp_reset");
if (retval) {
printk(KERN_ERR "Unable to request gpio reset_pin");
return retval;
}
retval = gpio_direction_output(reset_pin, 1);
if (retval < 0) {
printk(KERN_ERR "%s: gpio direction failed\n",
__func__);
return retval;
}
}
return retval;
}
static int bu21013_gpio_board_exit(int reset_pin)
{
int retval = 0;
if (bu21013_devices == 1) {
retval = gpio_direction_output(reset_pin, 0);
if (retval < 0) {
printk(KERN_ERR "%s: gpio direction failed\n",
__func__);
return retval;
}
gpio_set_value(reset_pin, 0);
}
bu21013_devices--;
return retval;
}
static int bu21013_read_pin_val(void)
{
return gpio_get_value(TOUCH_GPIO_PIN);
}
void __init mop500_stuib_init(void)
{
if (machine_is_hrefv60()) {
tsc_plat_device.cs_pin = HREFV60_TOUCH_RST_GPIO;
tsc_plat2_device.cs_pin = HREFV60_TOUCH_RST_GPIO;
} else {
tsc_plat_device.cs_pin = GPIO_BU21013_CS;
tsc_plat2_device.cs_pin = GPIO_BU21013_CS;
}
mop500_uib_i2c_add(0, mop500_i2c0_devices_stuib,
ARRAY_SIZE(mop500_i2c0_devices_stuib));
mop500_uib_i2c_add(3, u8500_i2c3_devices_stuib,
ARRAY_SIZE(u8500_i2c3_devices_stuib));
}
