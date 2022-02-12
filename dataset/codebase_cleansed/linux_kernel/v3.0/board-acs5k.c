static int acs5k_pca9555_setup(struct i2c_client *client,
unsigned gpio_base, unsigned ngpio,
void *context)
{
static int acs5k_gpio_value[] = {
-1, -1, -1, -1, -1, -1, -1, 0, 1, 1, -1, 0, 1, 0, -1, -1
};
int n;
for (n = 0; n < ARRAY_SIZE(acs5k_gpio_value); ++n) {
gpio_request(gpio_base + n, "ACS-5000 GPIO Expander");
if (acs5k_gpio_value[n] < 0)
gpio_direction_input(gpio_base + n);
else
gpio_direction_output(gpio_base + n,
acs5k_gpio_value[n]);
gpio_export(gpio_base + n, 0);
}
return 0;
}
static void __devinit acs5k_i2c_init(void)
{
platform_device_register(&acs5k_i2c_device);
i2c_register_board_info(0, acs5k_i2c_devs,
ARRAY_SIZE(acs5k_i2c_devs));
}
static void __init acs5k_register_nor(void)
{
int ret;
if (acs5k_nor_partitions[0].mask_flags == 0)
printk(KERN_WARNING "Warning: Unprotecting bootloader and configuration partition\n");
ret = platform_device_register(&acs5k_device_nor);
if (ret < 0)
printk(KERN_ERR "failed to register physmap-flash device\n");
}
static int __init acs5k_protection_setup(char *s)
{
if (strcmp(s, "no") == 0)
acs5k_nor_partitions[0].mask_flags = 0;
return 1;
}
static void __init acs5k_init_gpio(void)
{
int i;
ks8695_register_gpios();
for (i = 0; i < 4; ++i)
gpio_request(i, "ACS5K IRQ");
gpio_request(7, "ACS5K KS_FRDY");
for (i = 8; i < 16; ++i)
gpio_request(i, "ACS5K Unused");
gpio_request(3, "ACS5K CAN Control");
gpio_request(6, "ACS5K Heartbeat");
gpio_direction_output(3, 1);
gpio_direction_output(6, 0);
gpio_export(3, 0);
gpio_export(6, 0);
}
static void __init acs5k_init(void)
{
acs5k_init_gpio();
ks8695_add_device_lan();
ks8695_add_device_wan();
acs5k_register_nor();
acs5k_i2c_init();
}
