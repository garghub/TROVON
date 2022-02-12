static int initialize_gpio(int gpio, char *desc)
{
int ret;
ret = gpio_request(gpio, desc);
if (ret < 0) {
pr_err_ratelimited("cannot open %s gpio\n", desc);
return -ENOSYS;
}
gpio_direction_input(gpio);
return gpio;
}
static int mmc_get_cd(int index)
{
static int gpio;
if (!gpio)
gpio = initialize_gpio(EVM_MMC_CD_GPIO, "mmc card detect");
if (gpio < 0)
return gpio;
return gpio_get_value(gpio) ? 0 : 1;
}
static int mmc_get_ro(int index)
{
static int gpio;
if (!gpio)
gpio = initialize_gpio(EVM_MMC_WP_GPIO, "mmc write protect");
if (gpio < 0)
return gpio;
return gpio_get_value(gpio) ? 1 : 0;
}
static void spi_select_device(int cs)
{
static int gpio;
if (!gpio) {
int ret;
ret = gpio_request(EVM_SPI_CS_GPIO, "spi chipsel");
if (ret < 0) {
pr_err("cannot open spi chipsel gpio\n");
gpio = -ENOSYS;
return;
} else {
gpio = EVM_SPI_CS_GPIO;
gpio_direction_output(gpio, 0);
}
}
if (gpio < 0)
return;
return gpio_set_value(gpio, cs ? 1 : 0);
}
static __init void tnetv107x_evm_board_init(void)
{
davinci_cfg_reg_list(sdio1_pins);
davinci_cfg_reg_list(uart1_pins);
davinci_cfg_reg_list(ssp_pins);
tnetv107x_devices_init(&evm_device_info);
spi_register_board_info(spi_info, ARRAY_SIZE(spi_info));
}
static int __init tnetv107x_evm_console_init(void)
{
return add_preferred_console("ttyS", 0, "115200");
}
