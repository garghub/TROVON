static void mop500_tc35892_init(struct tc3589x *tc3589x, unsigned int base)
{
mop500_sdi_tc35892_init();
}
static void __init mop500_i2c_init(void)
{
db8500_add_i2c0(&u8500_i2c0_data);
db8500_add_i2c1(&u8500_i2c1_data);
db8500_add_i2c2(&u8500_i2c2_data);
db8500_add_i2c3(&u8500_i2c3_data);
}
static int mop500_prox_activate(struct device *dev)
{
prox_regulator = regulator_get(&mop500_gpio_keys_device.dev,
"vcc");
if (IS_ERR(prox_regulator)) {
dev_err(&mop500_gpio_keys_device.dev,
"no regulator\n");
return PTR_ERR(prox_regulator);
}
regulator_enable(prox_regulator);
return 0;
}
static void mop500_prox_deactivate(struct device *dev)
{
regulator_disable(prox_regulator);
regulator_put(prox_regulator);
}
static void __init mop500_spi_init(void)
{
db8500_add_ssp0(&ssp0_platform_data);
}
static void ux500_uart0_reset(void)
{
void __iomem *prcc_rst_set, *prcc_rst_clr;
prcc_rst_set = (void __iomem *)IO_ADDRESS(U8500_CLKRST1_BASE +
PRCC_K_SOFTRST_SET);
prcc_rst_clr = (void __iomem *)IO_ADDRESS(U8500_CLKRST1_BASE +
PRCC_K_SOFTRST_CLEAR);
writel((readl(prcc_rst_clr) | 0x1), prcc_rst_clr);
udelay(1);
writel((readl(prcc_rst_set) | 0x1), prcc_rst_set);
udelay(1);
}
static void ux500_uart0_init(void)
{
int ret;
ret = nmk_config_pins(mop500_pins_uart0,
ARRAY_SIZE(mop500_pins_uart0));
if (ret < 0)
pr_err("pl011: uart pins_enable failed\n");
}
static void ux500_uart0_exit(void)
{
int ret;
ret = nmk_config_pins_sleep(mop500_pins_uart0,
ARRAY_SIZE(mop500_pins_uart0));
if (ret < 0)
pr_err("pl011: uart pins_disable failed\n");
}
static void __init mop500_uart_init(void)
{
db8500_add_uart0(&uart0_plat);
db8500_add_uart1(&uart1_plat);
db8500_add_uart2(&uart2_plat);
}
static void __init mop500_init_machine(void)
{
int i2c0_devs;
if (machine_is_hrefv60())
mop500_gpio_keys[0].gpio = HREFV60_PROX_SENSE_GPIO;
else
mop500_gpio_keys[0].gpio = GPIO_PROX_SENSOR;
u8500_init_devices();
mop500_pins_init();
platform_add_devices(platform_devs, ARRAY_SIZE(platform_devs));
mop500_i2c_init();
mop500_sdi_init();
mop500_spi_init();
mop500_uart_init();
platform_device_register(&ab8500_device);
i2c0_devs = ARRAY_SIZE(mop500_i2c0_devices);
if (machine_is_hrefv60())
i2c0_devs -= NUM_PRE_V60_I2C0_DEVICES;
i2c_register_board_info(0, mop500_i2c0_devices, i2c0_devs);
i2c_register_board_info(2, mop500_i2c2_devices,
ARRAY_SIZE(mop500_i2c2_devices));
}
