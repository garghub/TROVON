static int lis302_setup(void)
{
int err;
int irq1 = LIS302_IRQ1_GPIO;
int irq2 = LIS302_IRQ2_GPIO;
err = gpio_request(irq1, "lis3lv02dl_irq1");
if (err) {
printk(KERN_ERR "lis3lv02dl: gpio request failed\n");
goto out;
}
err = gpio_request(irq2, "lis3lv02dl_irq2");
if (err) {
gpio_free(irq1);
printk(KERN_ERR "lis3lv02dl: gpio request failed\n");
goto out;
}
gpio_direction_input(irq1);
gpio_direction_input(irq2);
out:
return err;
}
static int lis302_release(void)
{
gpio_free(LIS302_IRQ1_GPIO);
gpio_free(LIS302_IRQ2_GPIO);
return 0;
}
static int rx51_lp5523_setup(void)
{
return gpio_request_one(RX51_LP5523_CHIP_EN_GPIO, GPIOF_DIR_OUT,
"lp5523_enable");
}
static void rx51_lp5523_release(void)
{
gpio_free(RX51_LP5523_CHIP_EN_GPIO);
}
static void rx51_lp5523_enable(bool state)
{
gpio_set_value(RX51_LP5523_CHIP_EN_GPIO, !!state);
}
static void rx51_charger_set_power(bool on)
{
gpio_set_value(RX51_USB_TRANSCEIVER_RST_GPIO, on);
}
static void __init rx51_charger_init(void)
{
WARN_ON(gpio_request_one(RX51_USB_TRANSCEIVER_RST_GPIO,
GPIOF_OUT_INIT_HIGH, "isp1704_reset"));
platform_device_register(&rx51_charger_device);
}
static void __init rx51_add_gpio_keys(void)
{
platform_device_register(&rx51_gpio_keys_device);
}
static void __init rx51_add_gpio_keys(void)
{
}
static void rx51_mmc2_remux(struct device *dev, int slot, int power_on)
{
if (power_on)
omap_mux_write_array(partition, rx51_mmc2_on_mux);
else
omap_mux_write_array(partition, rx51_mmc2_off_mux);
}
static __init void rx51_init_si4713(void)
{
int err;
err = gpio_request_one(RX51_FMTX_IRQ, GPIOF_DIR_IN, "si4713 irq");
if (err) {
printk(KERN_ERR "Cannot request si4713 irq gpio. %d\n", err);
return;
}
rx51_si4713_board_info.irq = gpio_to_irq(RX51_FMTX_IRQ);
platform_device_register(&rx51_si4713_dev);
}
static int rx51_twlgpio_setup(struct device *dev, unsigned gpio, unsigned n)
{
gpio_request_one(gpio + 6, GPIOF_OUT_INIT_LOW, "backlight_pwm");
gpio_request_one(gpio + 7, GPIOF_OUT_INIT_LOW, "speaker_en");
return 0;
}
static int __init rx51_i2c_init(void)
{
if ((system_rev >= SYSTEM_REV_S_USES_VAUX3 && system_rev < 0x100) ||
system_rev >= SYSTEM_REV_B_USES_VAUX3) {
rx51_twldata.vaux3 = &rx51_vaux3_mmc;
rx51_vmmc2.num_consumer_supplies--;
} else {
rx51_twldata.vaux3 = &rx51_vaux3_cam;
}
rx51_twldata.vmmc2 = &rx51_vmmc2;
omap3_pmic_get_config(&rx51_twldata,
TWL_COMMON_PDATA_USB | TWL_COMMON_PDATA_MADC,
TWL_COMMON_REGULATOR_VDAC);
rx51_twldata.vdac->constraints.apply_uV = true;
rx51_twldata.vdac->constraints.name = "VDAC";
omap_pmic_init(1, 2200, "twl5030", 7 + OMAP_INTC_START, &rx51_twldata);
omap_register_i2c_bus(2, 100, rx51_peripherals_i2c_board_info_2,
ARRAY_SIZE(rx51_peripherals_i2c_board_info_2));
#if defined(CONFIG_SENSORS_LIS3_I2C) || defined(CONFIG_SENSORS_LIS3_I2C_MODULE)
rx51_lis3lv02d_data.irq2 = gpio_to_irq(LIS302_IRQ2_GPIO);
rx51_peripherals_i2c_board_info_3[0].irq = gpio_to_irq(LIS302_IRQ1_GPIO);
#endif
omap_register_i2c_bus(3, 400, rx51_peripherals_i2c_board_info_3,
ARRAY_SIZE(rx51_peripherals_i2c_board_info_3));
return 0;
}
static void __init board_smc91x_init(void)
{
omap_mux_init_gpio(54, OMAP_PIN_INPUT_PULLDOWN);
omap_mux_init_gpio(86, OMAP_PIN_OUTPUT);
omap_mux_init_gpio(164, OMAP_PIN_OUTPUT);
gpmc_smc91x_init(&board_smc91x_data);
}
static inline void board_smc91x_init(void)
{
}
static void rx51_wl1251_set_power(bool enable)
{
gpio_set_value(RX51_WL1251_POWER_GPIO, enable);
}
static void __init rx51_init_wl1251(void)
{
int irq, ret;
ret = gpio_request_array(rx51_wl1251_gpios,
ARRAY_SIZE(rx51_wl1251_gpios));
if (ret < 0)
goto error;
irq = gpio_to_irq(RX51_WL1251_IRQ_GPIO);
if (irq < 0)
goto err_irq;
wl1251_pdata.set_power = rx51_wl1251_set_power;
rx51_peripherals_spi_board_info[RX51_SPI_WL1251].irq = irq;
return;
err_irq:
gpio_free(RX51_WL1251_IRQ_GPIO);
gpio_free(RX51_WL1251_POWER_GPIO);
error:
printk(KERN_ERR "wl1251 board initialisation failed\n");
wl1251_pdata.set_power = NULL;
}
static void rx51_tsc2005_set_reset(bool enable)
{
gpio_set_value(RX51_TSC2005_RESET_GPIO, enable);
}
static void __init rx51_init_tsc2005(void)
{
int r;
omap_mux_init_gpio(RX51_TSC2005_RESET_GPIO, OMAP_PIN_OUTPUT);
omap_mux_init_gpio(RX51_TSC2005_IRQ_GPIO, OMAP_PIN_INPUT_PULLUP);
r = gpio_request_array(rx51_tsc2005_gpios,
ARRAY_SIZE(rx51_tsc2005_gpios));
if (r < 0) {
printk(KERN_ERR "tsc2005 board initialization failed\n");
tsc2005_pdata.esd_timeout_ms = 0;
return;
}
tsc2005_pdata.set_reset = rx51_tsc2005_set_reset;
rx51_peripherals_spi_board_info[RX51_SPI_TSC2005].irq =
gpio_to_irq(RX51_TSC2005_IRQ_GPIO);
}
static void __init rx51_init_lirc(void)
{
platform_device_register(&rx51_lirc_device);
}
static void __init rx51_init_lirc(void)
{
}
void __init rx51_peripherals_init(void)
{
rx51_i2c_init();
regulator_has_full_constraints();
gpmc_onenand_init(board_onenand_data);
board_smc91x_init();
rx51_add_gpio_keys();
rx51_init_wl1251();
rx51_init_tsc2005();
rx51_init_si4713();
rx51_init_lirc();
spi_register_board_info(rx51_peripherals_spi_board_info,
ARRAY_SIZE(rx51_peripherals_spi_board_info));
partition = omap_mux_get("core");
if (partition)
omap_hsmmc_init(mmc);
rx51_charger_init();
}
