static void mop500_tc35892_init(struct tc3589x *tc3589x, unsigned int base)
{
struct device *parent = NULL;
#if 0
parent = tc3589x->dev;
#endif
mop500_sdi_tc35892_init(parent);
}
static int __init mop500_i2c_board_init(void)
{
if (machine_is_u8500())
mop500_uib_i2c_add(0, mop500_i2c0_devices,
ARRAY_SIZE(mop500_i2c0_devices));
mop500_uib_i2c_add(2, mop500_i2c2_devices,
ARRAY_SIZE(mop500_i2c2_devices));
return 0;
}
static void __init mop500_i2c_init(struct device *parent)
{
db8500_add_i2c0(parent, NULL);
db8500_add_i2c1(parent, NULL);
db8500_add_i2c2(parent, NULL);
db8500_add_i2c3(parent, NULL);
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
return regulator_enable(prox_regulator);
}
static void mop500_prox_deactivate(struct device *dev)
{
regulator_disable(prox_regulator);
regulator_put(prox_regulator);
}
static void __init mop500_spi_init(struct device *parent)
{
db8500_add_ssp0(parent, &ssp0_plat);
}
static void __init mop500_uart_init(struct device *parent)
{
db8500_add_uart0(parent, &uart0_plat);
db8500_add_uart1(parent, &uart1_plat);
db8500_add_uart2(parent, &uart2_plat);
}
static void __init u8500_cryp1_hash1_init(struct device *parent)
{
db8500_add_cryp1(parent, &u8500_cryp1_platform_data);
db8500_add_hash1(parent, &u8500_hash1_platform_data);
}
static void __init mop500_init_machine(void)
{
struct device *parent = NULL;
int i;
platform_device_register(&db8500_prcmu_device);
mop500_gpio_keys[0].gpio = GPIO_PROX_SENSOR;
sdi0_reg_info.enable_gpio = GPIO_SDMMC_EN;
sdi0_reg_info.gpios[0].gpio = GPIO_SDMMC_1V8_3V_SEL;
mop500_pinmaps_init();
parent = u8500_init_devices();
for (i = 0; i < ARRAY_SIZE(mop500_platform_devs); i++)
mop500_platform_devs[i]->dev.parent = parent;
platform_add_devices(mop500_platform_devs,
ARRAY_SIZE(mop500_platform_devs));
mop500_i2c_init(parent);
mop500_sdi_init(parent);
mop500_spi_init(parent);
mop500_audio_init(parent);
mop500_uart_init(parent);
u8500_cryp1_hash1_init(parent);
regulator_has_full_constraints();
}
static void __init snowball_init_machine(void)
{
struct device *parent = NULL;
int i;
platform_device_register(&db8500_prcmu_device);
sdi0_reg_info.enable_gpio = SNOWBALL_SDMMC_EN_GPIO;
sdi0_reg_info.gpios[0].gpio = SNOWBALL_SDMMC_1V8_3V_GPIO;
snowball_pinmaps_init();
parent = u8500_init_devices();
for (i = 0; i < ARRAY_SIZE(snowball_platform_devs); i++)
snowball_platform_devs[i]->dev.parent = parent;
platform_add_devices(snowball_platform_devs,
ARRAY_SIZE(snowball_platform_devs));
mop500_i2c_init(parent);
snowball_sdi_init(parent);
mop500_spi_init(parent);
mop500_audio_init(parent);
mop500_uart_init(parent);
u8500_cryp1_hash1_init(parent);
regulator_has_full_constraints();
}
static void __init hrefv60_init_machine(void)
{
struct device *parent = NULL;
int i;
platform_device_register(&db8500_prcmu_device);
mop500_gpio_keys[0].gpio = HREFV60_PROX_SENSE_GPIO;
sdi0_reg_info.enable_gpio = HREFV60_SDMMC_EN_GPIO;
sdi0_reg_info.gpios[0].gpio = HREFV60_SDMMC_1V8_3V_GPIO;
hrefv60_pinmaps_init();
parent = u8500_init_devices();
for (i = 0; i < ARRAY_SIZE(mop500_platform_devs); i++)
mop500_platform_devs[i]->dev.parent = parent;
platform_add_devices(mop500_platform_devs,
ARRAY_SIZE(mop500_platform_devs));
mop500_i2c_init(parent);
hrefv60_sdi_init(parent);
mop500_spi_init(parent);
mop500_audio_init(parent);
mop500_uart_init(parent);
regulator_has_full_constraints();
}
