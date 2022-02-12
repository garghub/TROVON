u8 get_omap3_evm_rev(void)
{
return omap3_evm_version;
}
static void __init omap3_evm_get_revision(void)
{
void __iomem *ioaddr;
unsigned int smsc_id;
ioaddr = ioremap_nocache(OMAP3EVM_ETHR_START, SZ_1K);
if (!ioaddr)
return;
smsc_id = readl(ioaddr + OMAP3EVM_ETHR_ID_REV) & 0xFFFF0000;
iounmap(ioaddr);
switch (smsc_id) {
case 0x01150000:
omap3_evm_version = OMAP3EVM_BOARD_GEN_1;
break;
case 0x92200000:
default:
omap3_evm_version = OMAP3EVM_BOARD_GEN_2;
}
}
static inline void __init omap3evm_init_smsc911x(void)
{
struct clk *l3ck;
unsigned int rate;
l3ck = clk_get(NULL, "l3_ck");
if (IS_ERR(l3ck))
rate = 100000000;
else
rate = clk_get_rate(l3ck);
if (cpu_is_omap3430()) {
if (get_omap3_evm_rev() == OMAP3EVM_BOARD_GEN_1)
smsc911x_cfg.gpio_reset = OMAP3EVM_GEN1_ETHR_GPIO_RST;
else
smsc911x_cfg.gpio_reset = OMAP3EVM_GEN2_ETHR_GPIO_RST;
}
gpmc_smsc911x_init(&smsc911x_cfg);
}
static inline void __init omap3evm_init_smsc911x(void) { return; }
static void __init omap3_evm_display_init(void)
{
int r;
r = gpio_request_array(omap3_evm_dss_gpios,
ARRAY_SIZE(omap3_evm_dss_gpios));
if (r)
printk(KERN_ERR "failed to get lcd_panel_* gpios\n");
}
static int omap3_evm_enable_lcd(struct omap_dss_device *dssdev)
{
if (dvi_enabled) {
printk(KERN_ERR "cannot enable LCD, DVI is enabled\n");
return -EINVAL;
}
gpio_set_value(OMAP3EVM_LCD_PANEL_ENVDD, 0);
if (get_omap3_evm_rev() >= OMAP3EVM_BOARD_GEN_2)
gpio_set_value_cansleep(OMAP3EVM_LCD_PANEL_BKLIGHT_GPIO, 0);
else
gpio_set_value_cansleep(OMAP3EVM_LCD_PANEL_BKLIGHT_GPIO, 1);
lcd_enabled = 1;
return 0;
}
static void omap3_evm_disable_lcd(struct omap_dss_device *dssdev)
{
gpio_set_value(OMAP3EVM_LCD_PANEL_ENVDD, 1);
if (get_omap3_evm_rev() >= OMAP3EVM_BOARD_GEN_2)
gpio_set_value_cansleep(OMAP3EVM_LCD_PANEL_BKLIGHT_GPIO, 1);
else
gpio_set_value_cansleep(OMAP3EVM_LCD_PANEL_BKLIGHT_GPIO, 0);
lcd_enabled = 0;
}
static int omap3_evm_enable_tv(struct omap_dss_device *dssdev)
{
return 0;
}
static void omap3_evm_disable_tv(struct omap_dss_device *dssdev)
{
}
static int omap3_evm_enable_dvi(struct omap_dss_device *dssdev)
{
if (lcd_enabled) {
printk(KERN_ERR "cannot enable DVI, LCD is enabled\n");
return -EINVAL;
}
gpio_set_value_cansleep(OMAP3EVM_DVI_PANEL_EN_GPIO, 1);
dvi_enabled = 1;
return 0;
}
static void omap3_evm_disable_dvi(struct omap_dss_device *dssdev)
{
gpio_set_value_cansleep(OMAP3EVM_DVI_PANEL_EN_GPIO, 0);
dvi_enabled = 0;
}
static int omap3evm_twl_gpio_setup(struct device *dev,
unsigned gpio, unsigned ngpio)
{
int r, lcd_bl_en;
omap_mux_init_gpio(63, OMAP_PIN_INPUT);
mmc[0].gpio_cd = gpio + 0;
omap2_hsmmc_init(mmc);
omap3evm_vmmc1_supply.dev = mmc[0].dev;
omap3evm_vsim_supply.dev = mmc[0].dev;
lcd_bl_en = get_omap3_evm_rev() >= OMAP3EVM_BOARD_GEN_2 ?
GPIOF_OUT_INIT_HIGH : GPIOF_OUT_INIT_LOW;
r = gpio_request_one(gpio + TWL4030_GPIO_MAX, lcd_bl_en, "EN_LCD_BKL");
if (r)
printk(KERN_ERR "failed to get/set lcd_bkl gpio\n");
gpio_request_one(gpio + 7, GPIOF_OUT_INIT_LOW, "EN_DVI");
gpio_leds[2].gpio = gpio + TWL4030_GPIO_MAX + 1;
platform_device_register(&leds_gpio);
return 0;
}
static int __init omap3_evm_i2c_init(void)
{
omap3_pmic_init("twl4030", &omap3evm_twldata);
omap_register_i2c_bus(2, 400, NULL, 0);
omap_register_i2c_bus(3, 400, NULL, 0);
return 0;
}
static void __init omap3_evm_init_early(void)
{
omap2_init_common_infrastructure();
omap2_init_common_devices(mt46h32m32lf6_sdrc_params, NULL);
}
static void __init omap3_evm_init(void)
{
omap3_evm_get_revision();
if (cpu_is_omap3630())
omap3_mux_init(omap36x_board_mux, OMAP_PACKAGE_CBB);
else
omap3_mux_init(omap35x_board_mux, OMAP_PACKAGE_CBB);
omap_board_config = omap3_evm_config;
omap_board_config_size = ARRAY_SIZE(omap3_evm_config);
omap3_evm_i2c_init();
omap_display_init(&omap3_evm_dss_data);
omap_serial_init();
usb_nop_xceiv_register();
if (get_omap3_evm_rev() >= OMAP3EVM_BOARD_GEN_2) {
omap_mux_init_gpio(OMAP3_EVM_EHCI_VBUS, OMAP_PIN_INPUT_PULLUP);
omap_mux_init_gpio(OMAP3_EVM_EHCI_SELECT,
OMAP_PIN_INPUT_PULLUP);
gpio_request_array(omap3_evm_ehci_gpios,
ARRAY_SIZE(omap3_evm_ehci_gpios));
omap_mux_init_gpio(21, OMAP_PIN_INPUT_PULLUP);
usbhs_bdata.reset_gpio_port[1] = 21;
musb_board_data.power = 500;
musb_board_data.extvbus = 1;
} else {
omap_mux_init_gpio(135, OMAP_PIN_OUTPUT);
usbhs_bdata.reset_gpio_port[1] = 135;
}
usb_musb_init(&musb_board_data);
usbhs_init(&usbhs_bdata);
omap_ads7846_init(1, OMAP3_EVM_TS_GPIO, 310, NULL);
omap3evm_init_smsc911x();
omap3_evm_display_init();
#ifdef CONFIG_WL12XX_PLATFORM_DATA
if (wl12xx_set_platform_data(&omap3evm_wlan_data))
pr_err("error setting wl12xx data\n");
platform_device_register(&omap3evm_wlan_regulator);
#endif
}
