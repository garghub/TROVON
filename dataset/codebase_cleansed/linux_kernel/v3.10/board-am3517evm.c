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
static __init void am3517_evm_mcbsp1_init(void)
{
u32 devconf0;
devconf0 = omap_ctrl_readl(OMAP2_CONTROL_DEVCONF0);
devconf0 |= OMAP2_MCBSP1_CLKR_MASK | OMAP2_MCBSP1_FSR_MASK;
omap_ctrl_writel(devconf0, OMAP2_CONTROL_DEVCONF0);
}
static void am3517_evm_hecc_init(struct ti_hecc_platform_data *pdata)
{
am3517_hecc_device.dev.platform_data = pdata;
platform_device_register(&am3517_hecc_device);
}
static void __init am3517_evm_init(void)
{
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
am3517_evm_i2c_init();
omap_display_init(&am3517_evm_dss_data);
omap_serial_init();
omap_sdrc_init(NULL, NULL);
omap_mux_init_gpio(57, OMAP_PIN_OUTPUT);
usbhs_init_phys(phy_data, ARRAY_SIZE(phy_data));
usbhs_init(&usbhs_bdata);
am3517_evm_hecc_init(&am3517_evm_hecc_pdata);
am3517_evm_rtc_init();
i2c_register_board_info(1, am3517evm_i2c1_boardinfo,
ARRAY_SIZE(am3517evm_i2c1_boardinfo));
am35xx_emac_init(AM35XX_DEFAULT_MDIO_FREQUENCY, 1);
am3517_evm_musb_init();
am3517_evm_mcbsp1_init();
omap_hsmmc_init(mmc);
}
