static void mop500_tc35892_init(struct tc3589x *tc3589x, unsigned int base)
{
struct device *parent = NULL;
#if 0
parent = tc3589x->dev;
#endif
mop500_sdi_tc35892_init(parent);
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
regulator_enable(prox_regulator);
return 0;
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
int i2c0_devs;
int i;
mop500_gpio_keys[0].gpio = GPIO_PROX_SENSOR;
mop500_pinmaps_init();
parent = u8500_init_devices(&ab8500_platdata);
for (i = 0; i < ARRAY_SIZE(mop500_platform_devs); i++)
mop500_platform_devs[i]->dev.parent = parent;
platform_add_devices(mop500_platform_devs,
ARRAY_SIZE(mop500_platform_devs));
mop500_i2c_init(parent);
mop500_sdi_init(parent);
mop500_spi_init(parent);
mop500_msp_init(parent);
mop500_uart_init(parent);
u8500_cryp1_hash1_init(parent);
i2c0_devs = ARRAY_SIZE(mop500_i2c0_devices);
i2c_register_board_info(0, mop500_i2c0_devices, i2c0_devs);
i2c_register_board_info(2, mop500_i2c2_devices,
ARRAY_SIZE(mop500_i2c2_devices));
regulator_has_full_constraints();
mop500_uib_init();
}
static void __init snowball_init_machine(void)
{
struct device *parent = NULL;
int i;
snowball_pinmaps_init();
parent = u8500_init_devices(&ab8500_platdata);
for (i = 0; i < ARRAY_SIZE(snowball_platform_devs); i++)
snowball_platform_devs[i]->dev.parent = parent;
platform_add_devices(snowball_platform_devs,
ARRAY_SIZE(snowball_platform_devs));
mop500_i2c_init(parent);
snowball_sdi_init(parent);
mop500_spi_init(parent);
mop500_msp_init(parent);
mop500_uart_init(parent);
regulator_has_full_constraints();
}
static void __init hrefv60_init_machine(void)
{
struct device *parent = NULL;
int i2c0_devs;
int i;
mop500_gpio_keys[0].gpio = HREFV60_PROX_SENSE_GPIO;
hrefv60_pinmaps_init();
parent = u8500_init_devices(&ab8500_platdata);
for (i = 0; i < ARRAY_SIZE(mop500_platform_devs); i++)
mop500_platform_devs[i]->dev.parent = parent;
platform_add_devices(mop500_platform_devs,
ARRAY_SIZE(mop500_platform_devs));
mop500_i2c_init(parent);
hrefv60_sdi_init(parent);
mop500_spi_init(parent);
mop500_msp_init(parent);
mop500_uart_init(parent);
i2c0_devs = ARRAY_SIZE(mop500_i2c0_devices);
i2c0_devs -= NUM_PRE_V60_I2C0_DEVICES;
i2c_register_board_info(0, mop500_i2c0_devices, i2c0_devs);
i2c_register_board_info(2, mop500_i2c2_devices,
ARRAY_SIZE(mop500_i2c2_devices));
regulator_has_full_constraints();
mop500_uib_init();
}
static void __init u8500_init_machine(void)
{
struct device *parent = NULL;
int i2c0_devs;
int i;
if (of_machine_is_compatible("st-ericsson,mop500"))
mop500_pinmaps_init();
else if (of_machine_is_compatible("calaosystems,snowball-a9500"))
snowball_pinmaps_init();
else if (of_machine_is_compatible("st-ericsson,hrefv60+"))
hrefv60_pinmaps_init();
parent = u8500_of_init_devices();
for (i = 0; i < ARRAY_SIZE(mop500_platform_devs); i++)
mop500_platform_devs[i]->dev.parent = parent;
of_platform_populate(NULL, u8500_local_bus_nodes, u8500_auxdata_lookup, parent);
if (of_machine_is_compatible("st-ericsson,mop500")) {
mop500_gpio_keys[0].gpio = GPIO_PROX_SENSOR;
platform_add_devices(mop500_platform_devs,
ARRAY_SIZE(mop500_platform_devs));
mop500_sdi_init(parent);
mop500_msp_init(parent);
i2c0_devs = ARRAY_SIZE(mop500_i2c0_devices);
i2c_register_board_info(0, mop500_i2c0_devices, i2c0_devs);
i2c_register_board_info(2, mop500_i2c2_devices,
ARRAY_SIZE(mop500_i2c2_devices));
mop500_uib_init();
} else if (of_machine_is_compatible("calaosystems,snowball-a9500")) {
mop500_msp_init(parent);
} else if (of_machine_is_compatible("st-ericsson,hrefv60+")) {
mop500_gpio_keys[0].gpio = HREFV60_PROX_SENSE_GPIO;
platform_add_devices(mop500_platform_devs,
ARRAY_SIZE(mop500_platform_devs));
hrefv60_sdi_init(parent);
mop500_msp_init(parent);
i2c0_devs = ARRAY_SIZE(mop500_i2c0_devices);
i2c0_devs -= NUM_PRE_V60_I2C0_DEVICES;
i2c_register_board_info(0, mop500_i2c0_devices, i2c0_devs);
i2c_register_board_info(2, mop500_i2c2_devices,
ARRAY_SIZE(mop500_i2c2_devices));
mop500_uib_init();
}
regulator_has_full_constraints();
}
