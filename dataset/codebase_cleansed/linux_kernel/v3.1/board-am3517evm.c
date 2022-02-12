static void am3517_enable_ethernet_int(void)
{
u32 regval;
regval = omap_ctrl_readl(AM35XX_CONTROL_LVL_INTR_CLEAR);
regval = (regval | AM35XX_CPGMAC_C0_RX_PULSE_CLR |
AM35XX_CPGMAC_C0_TX_PULSE_CLR |
AM35XX_CPGMAC_C0_MISC_PULSE_CLR |
AM35XX_CPGMAC_C0_RX_THRESH_CLR);
omap_ctrl_writel(regval, AM35XX_CONTROL_LVL_INTR_CLEAR);
regval = omap_ctrl_readl(AM35XX_CONTROL_LVL_INTR_CLEAR);
}
static void am3517_disable_ethernet_int(void)
{
u32 regval;
regval = omap_ctrl_readl(AM35XX_CONTROL_LVL_INTR_CLEAR);
regval = (regval | AM35XX_CPGMAC_C0_RX_PULSE_CLR |
AM35XX_CPGMAC_C0_TX_PULSE_CLR);
omap_ctrl_writel(regval, AM35XX_CONTROL_LVL_INTR_CLEAR);
regval = omap_ctrl_readl(AM35XX_CONTROL_LVL_INTR_CLEAR);
}
static void am3517_evm_ethernet_init(struct emac_platform_data *pdata)
{
unsigned int regval;
pdata->ctrl_reg_offset = AM35XX_EMAC_CNTRL_OFFSET;
pdata->ctrl_mod_reg_offset = AM35XX_EMAC_CNTRL_MOD_OFFSET;
pdata->ctrl_ram_offset = AM35XX_EMAC_CNTRL_RAM_OFFSET;
pdata->ctrl_ram_size = AM35XX_EMAC_CNTRL_RAM_SIZE;
pdata->version = EMAC_VERSION_2;
pdata->hw_ram_addr = AM35XX_EMAC_HW_RAM_ADDR;
pdata->interrupt_enable = am3517_enable_ethernet_int;
pdata->interrupt_disable = am3517_disable_ethernet_int;
am3517_emac_device.dev.platform_data = pdata;
platform_device_register(&am3517_emac_device);
platform_device_register(&am3517_mdio_device);
clk_add_alias(NULL, dev_name(&am3517_mdio_device.dev),
NULL, &am3517_emac_device.dev);
regval = omap_ctrl_readl(AM35XX_CONTROL_IP_SW_RESET);
regval = regval & (~(AM35XX_CPGMACSS_SW_RST));
omap_ctrl_writel(regval, AM35XX_CONTROL_IP_SW_RESET);
regval = omap_ctrl_readl(AM35XX_CONTROL_IP_SW_RESET);
return ;
}
static void __init am3517_evm_rtc_init(void)
{
int r;
omap_mux_init_gpio(GPIO_RTCS35390A_IRQ, OMAP_PIN_INPUT_PULLUP);
r = gpio_request_one(GPIO_RTCS35390A_IRQ, GPIOF_IN, "rtcs35390a-irq");
if (r < 0) {
printk(KERN_WARNING "failed to request GPIO#%d\n",
GPIO_RTCS35390A_IRQ);
return;
}
am3517evm_i2c1_boardinfo[0].irq = gpio_to_irq(GPIO_RTCS35390A_IRQ);
}
static int __init am3517_evm_i2c_init(void)
{
omap_register_i2c_bus(1, 400, NULL, 0);
omap_register_i2c_bus(2, 400, am3517evm_i2c2_boardinfo,
ARRAY_SIZE(am3517evm_i2c2_boardinfo));
omap_register_i2c_bus(3, 400, am3517evm_i2c3_boardinfo,
ARRAY_SIZE(am3517evm_i2c3_boardinfo));
return 0;
}
static void __init am3517_evm_display_init(void)
{
int r;
omap_mux_init_gpio(LCD_PANEL_PWR, OMAP_PIN_INPUT_PULLUP);
omap_mux_init_gpio(LCD_PANEL_BKLIGHT_PWR, OMAP_PIN_INPUT_PULLDOWN);
omap_mux_init_gpio(LCD_PANEL_PWM, OMAP_PIN_INPUT_PULLDOWN);
r = gpio_request_array(am3517_evm_dss_gpios,
ARRAY_SIZE(am3517_evm_dss_gpios));
if (r) {
printk(KERN_ERR "failed to get DSS panel control GPIOs\n");
return;
}
printk(KERN_INFO "Display initialized successfully\n");
}
static void __init am3517_evm_display_init(void) {}
static int am3517_evm_panel_enable_lcd(struct omap_dss_device *dssdev)
{
if (dvi_enabled) {
printk(KERN_ERR "cannot enable LCD, DVI is enabled\n");
return -EINVAL;
}
gpio_set_value(LCD_PANEL_PWR, 1);
lcd_enabled = 1;
return 0;
}
static void am3517_evm_panel_disable_lcd(struct omap_dss_device *dssdev)
{
gpio_set_value(LCD_PANEL_PWR, 0);
lcd_enabled = 0;
}
static int am3517_evm_panel_enable_tv(struct omap_dss_device *dssdev)
{
return 0;
}
static void am3517_evm_panel_disable_tv(struct omap_dss_device *dssdev)
{
}
static int am3517_evm_panel_enable_dvi(struct omap_dss_device *dssdev)
{
if (lcd_enabled) {
printk(KERN_ERR "cannot enable DVI, LCD is enabled\n");
return -EINVAL;
}
dvi_enabled = 1;
return 0;
}
static void am3517_evm_panel_disable_dvi(struct omap_dss_device *dssdev)
{
dvi_enabled = 0;
}
static void __init am3517_evm_init_early(void)
{
omap2_init_common_infrastructure();
omap2_init_common_devices(NULL, NULL);
}
static __init void am3517_evm_musb_init(void)
{
u32 devconf2;
devconf2 = omap_ctrl_readl(AM35XX_CONTROL_DEVCONF2);
devconf2 &= ~(CONF2_REFFREQ | CONF2_OTGMODE | CONF2_PHY_GPIOMODE);
devconf2 |= CONF2_REFFREQ_13MHZ | CONF2_SESENDEN | CONF2_VBDTCTEN
| CONF2_DATPOL;
omap_ctrl_writel(devconf2, AM35XX_CONTROL_DEVCONF2);
usb_musb_init(&musb_board_data);
}
static void am3517_evm_hecc_init(struct ti_hecc_platform_data *pdata)
{
am3517_hecc_device.dev.platform_data = pdata;
platform_device_register(&am3517_hecc_device);
}
static void __init am3517_evm_init(void)
{
omap_board_config = am3517_evm_config;
omap_board_config_size = ARRAY_SIZE(am3517_evm_config);
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
am3517_evm_i2c_init();
omap_display_init(&am3517_evm_dss_data);
omap_serial_init();
omap_mux_init_gpio(57, OMAP_PIN_OUTPUT);
usbhs_init(&usbhs_bdata);
am3517_evm_hecc_init(&am3517_evm_hecc_pdata);
am3517_evm_display_init();
am3517_evm_rtc_init();
i2c_register_board_info(1, am3517evm_i2c1_boardinfo,
ARRAY_SIZE(am3517evm_i2c1_boardinfo));
am3517_evm_ethernet_init(&am3517_evm_emac_pdata);
am3517_evm_musb_init();
}
