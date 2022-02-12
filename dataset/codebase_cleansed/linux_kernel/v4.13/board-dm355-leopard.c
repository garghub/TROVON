static void dm355leopard_mmcsd_gpios(unsigned gpio)
{
gpio_request(gpio + 0, "mmc0_ro");
gpio_request(gpio + 1, "mmc0_cd");
gpio_request(gpio + 2, "mmc1_ro");
gpio_request(gpio + 3, "mmc1_cd");
leopard_mmc_gpio = gpio;
}
static void __init leopard_init_i2c(void)
{
davinci_init_i2c(&i2c_pdata);
gpio_request(5, "dm355leopard_msp");
gpio_direction_input(5);
dm355leopard_i2c_info[0].irq = gpio_to_irq(5);
i2c_register_board_info(1, dm355leopard_i2c_info,
ARRAY_SIZE(dm355leopard_i2c_info));
}
static void __init dm355_leopard_map_io(void)
{
dm355_init();
}
static int dm355leopard_mmc_get_cd(int module)
{
if (!gpio_is_valid(leopard_mmc_gpio))
return -ENXIO;
return !gpio_get_value_cansleep(leopard_mmc_gpio + 2 * module + 1);
}
static int dm355leopard_mmc_get_ro(int module)
{
if (!gpio_is_valid(leopard_mmc_gpio))
return -ENXIO;
return gpio_get_value_cansleep(leopard_mmc_gpio + 2 * module + 0);
}
static __init void dm355_leopard_init(void)
{
struct clk *aemif;
int ret;
ret = dm355_gpio_register();
if (ret)
pr_warn("%s: GPIO init failed: %d\n", __func__, ret);
gpio_request(9, "dm9000");
gpio_direction_input(9);
dm355leopard_dm9000_rsrc[2].start = gpio_to_irq(9);
aemif = clk_get(&dm355leopard_dm9000.dev, "aemif");
if (!WARN(IS_ERR(aemif), "unable to get AEMIF clock\n"))
clk_prepare_enable(aemif);
platform_add_devices(davinci_leopard_devices,
ARRAY_SIZE(davinci_leopard_devices));
leopard_init_i2c();
davinci_serial_init(dm355_serial_device);
gpio_request(2, "usb_id_toggle");
gpio_direction_output(2, USB_ID_VALUE);
davinci_setup_usb(1000, 8);
davinci_setup_mmc(0, &dm355leopard_mmc_config);
davinci_setup_mmc(1, &dm355leopard_mmc_config);
dm355_init_spi0(BIT(0), dm355_leopard_spi_info,
ARRAY_SIZE(dm355_leopard_spi_info));
}
