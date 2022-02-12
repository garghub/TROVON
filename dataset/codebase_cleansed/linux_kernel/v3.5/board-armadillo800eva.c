static int usbhsf_get_id(struct platform_device *pdev)
{
return USBHS_GADGET;
}
static void usbhsf_power_ctrl(struct platform_device *pdev,
void __iomem *base, int enable)
{
struct usbhsf_private *priv = usbhsf_get_priv(pdev);
if (enable) {
clk_enable(priv->usb24);
clk_enable(priv->pci);
clk_enable(priv->host);
clk_enable(priv->func);
clk_enable(priv->phy);
__raw_writew(0xd750, USBCR1);
mdelay(1);
__raw_writel(0x0000000c, priv->usbh_base + USBH_USBCTR);
__raw_writel(0x00000008, priv->usbh_base + USBH_USBCTR);
mdelay(10);
__raw_writew(0xd770, USBCR1);
__raw_writew(0x4000, base + 0x102);
} else {
__raw_writel(0x0000010f, priv->usbh_base + USBH_USBCTR);
__raw_writew(0xd7c0, USBCR1);
clk_disable(priv->phy);
clk_disable(priv->func);
clk_disable(priv->host);
clk_disable(priv->pci);
clk_disable(priv->usb24);
}
}
static void usbhsf_hardware_exit(struct platform_device *pdev)
{
struct usbhsf_private *priv = usbhsf_get_priv(pdev);
if (!IS_ERR(priv->phy))
clk_put(priv->phy);
if (!IS_ERR(priv->usb24))
clk_put(priv->usb24);
if (!IS_ERR(priv->pci))
clk_put(priv->pci);
if (!IS_ERR(priv->host))
clk_put(priv->host);
if (!IS_ERR(priv->func))
clk_put(priv->func);
if (priv->usbh_base)
iounmap(priv->usbh_base);
priv->phy = NULL;
priv->usb24 = NULL;
priv->pci = NULL;
priv->host = NULL;
priv->func = NULL;
priv->usbh_base = NULL;
}
static int usbhsf_hardware_init(struct platform_device *pdev)
{
struct usbhsf_private *priv = usbhsf_get_priv(pdev);
priv->phy = clk_get(&pdev->dev, "phy");
priv->usb24 = clk_get(&pdev->dev, "usb24");
priv->pci = clk_get(&pdev->dev, "pci");
priv->func = clk_get(&pdev->dev, "func");
priv->host = clk_get(&pdev->dev, "host");
priv->usbh_base = ioremap_nocache(USBH, 0x20000);
if (IS_ERR(priv->phy) ||
IS_ERR(priv->usb24) ||
IS_ERR(priv->pci) ||
IS_ERR(priv->host) ||
IS_ERR(priv->func) ||
!priv->usbh_base) {
dev_err(&pdev->dev, "USB clock setting failed\n");
usbhsf_hardware_exit(pdev);
return -EIO;
}
clk_set_rate(priv->usb24,
clk_get_rate(clk_get_parent(priv->usb24)));
return 0;
}
static void __init eva_clock_init(void)
{
struct clk *system = clk_get(NULL, "system_clk");
struct clk *xtal1 = clk_get(NULL, "extal1");
struct clk *usb24s = clk_get(NULL, "usb24s");
if (IS_ERR(system) ||
IS_ERR(xtal1) ||
IS_ERR(usb24s)) {
pr_err("armadillo800eva board clock init failed\n");
goto clock_error;
}
clk_set_rate(xtal1, 24000000);
clk_set_parent(usb24s, system);
clock_error:
if (!IS_ERR(system))
clk_put(system);
if (!IS_ERR(xtal1))
clk_put(xtal1);
if (!IS_ERR(usb24s))
clk_put(usb24s);
}
static void __init eva_init(void)
{
eva_clock_init();
r8a7740_pinmux_init();
gpio_request(GPIO_FN_SCIFA1_RXD, NULL);
gpio_request(GPIO_FN_SCIFA1_TXD, NULL);
gpio_request(GPIO_FN_LCDC0_SELECT, NULL);
gpio_request(GPIO_FN_LCD0_D0, NULL);
gpio_request(GPIO_FN_LCD0_D1, NULL);
gpio_request(GPIO_FN_LCD0_D2, NULL);
gpio_request(GPIO_FN_LCD0_D3, NULL);
gpio_request(GPIO_FN_LCD0_D4, NULL);
gpio_request(GPIO_FN_LCD0_D5, NULL);
gpio_request(GPIO_FN_LCD0_D6, NULL);
gpio_request(GPIO_FN_LCD0_D7, NULL);
gpio_request(GPIO_FN_LCD0_D8, NULL);
gpio_request(GPIO_FN_LCD0_D9, NULL);
gpio_request(GPIO_FN_LCD0_D10, NULL);
gpio_request(GPIO_FN_LCD0_D11, NULL);
gpio_request(GPIO_FN_LCD0_D12, NULL);
gpio_request(GPIO_FN_LCD0_D13, NULL);
gpio_request(GPIO_FN_LCD0_D14, NULL);
gpio_request(GPIO_FN_LCD0_D15, NULL);
gpio_request(GPIO_FN_LCD0_D16, NULL);
gpio_request(GPIO_FN_LCD0_D17, NULL);
gpio_request(GPIO_FN_LCD0_D18_PORT40, NULL);
gpio_request(GPIO_FN_LCD0_D19_PORT4, NULL);
gpio_request(GPIO_FN_LCD0_D20_PORT3, NULL);
gpio_request(GPIO_FN_LCD0_D21_PORT2, NULL);
gpio_request(GPIO_FN_LCD0_D22_PORT0, NULL);
gpio_request(GPIO_FN_LCD0_D23_PORT1, NULL);
gpio_request(GPIO_FN_LCD0_DCK, NULL);
gpio_request(GPIO_FN_LCD0_VSYN, NULL);
gpio_request(GPIO_FN_LCD0_HSYN, NULL);
gpio_request(GPIO_FN_LCD0_DISP, NULL);
gpio_request(GPIO_FN_LCD0_LCLK_PORT165, NULL);
gpio_request(GPIO_PORT61, NULL);
gpio_direction_output(GPIO_PORT61, 1);
gpio_request(GPIO_PORT202, NULL);
gpio_direction_output(GPIO_PORT202, 0);
gpio_request(GPIO_FN_IRQ10, NULL);
gpio_request(GPIO_PORT166, NULL);
gpio_direction_output(GPIO_PORT166, 1);
gpio_request(GPIO_FN_ET_CRS, NULL);
gpio_request(GPIO_FN_ET_MDC, NULL);
gpio_request(GPIO_FN_ET_MDIO, NULL);
gpio_request(GPIO_FN_ET_TX_ER, NULL);
gpio_request(GPIO_FN_ET_RX_ER, NULL);
gpio_request(GPIO_FN_ET_ERXD0, NULL);
gpio_request(GPIO_FN_ET_ERXD1, NULL);
gpio_request(GPIO_FN_ET_ERXD2, NULL);
gpio_request(GPIO_FN_ET_ERXD3, NULL);
gpio_request(GPIO_FN_ET_TX_CLK, NULL);
gpio_request(GPIO_FN_ET_TX_EN, NULL);
gpio_request(GPIO_FN_ET_ETXD0, NULL);
gpio_request(GPIO_FN_ET_ETXD1, NULL);
gpio_request(GPIO_FN_ET_ETXD2, NULL);
gpio_request(GPIO_FN_ET_ETXD3, NULL);
gpio_request(GPIO_FN_ET_PHY_INT, NULL);
gpio_request(GPIO_FN_ET_COL, NULL);
gpio_request(GPIO_FN_ET_RX_DV, NULL);
gpio_request(GPIO_FN_ET_RX_CLK, NULL);
gpio_request(GPIO_PORT18, NULL);
gpio_direction_output(GPIO_PORT18, 1);
gpio_request(GPIO_PORT159, NULL);
gpio_direction_input(GPIO_PORT159);
if (gpio_get_value(GPIO_PORT159)) {
} else {
gpio_request(GPIO_FN_VBUS, NULL);
platform_device_register(&usbhsf_device);
}
gpio_request(GPIO_FN_SDHI0_CMD, NULL);
gpio_request(GPIO_FN_SDHI0_CLK, NULL);
gpio_request(GPIO_FN_SDHI0_D0, NULL);
gpio_request(GPIO_FN_SDHI0_D1, NULL);
gpio_request(GPIO_FN_SDHI0_D2, NULL);
gpio_request(GPIO_FN_SDHI0_D3, NULL);
gpio_request(GPIO_FN_SDHI0_WP, NULL);
gpio_request(GPIO_PORT17, NULL);
gpio_request(GPIO_PORT74, NULL);
gpio_request(GPIO_PORT75, NULL);
gpio_direction_output(GPIO_PORT17, 0);
gpio_direction_output(GPIO_PORT74, 1);
gpio_direction_output(GPIO_PORT75, 1);
gpio_request(GPIO_FN_MMC1_CLK_PORT103, NULL);
gpio_request(GPIO_FN_MMC1_CMD_PORT104, NULL);
gpio_request(GPIO_FN_MMC1_D0_PORT149, NULL);
gpio_request(GPIO_FN_MMC1_D1_PORT148, NULL);
gpio_request(GPIO_FN_MMC1_D2_PORT147, NULL);
gpio_request(GPIO_FN_MMC1_D3_PORT146, NULL);
gpio_request(GPIO_FN_MMC1_D4_PORT145, NULL);
gpio_request(GPIO_FN_MMC1_D5_PORT144, NULL);
gpio_request(GPIO_FN_MMC1_D6_PORT143, NULL);
gpio_request(GPIO_FN_MMC1_D7_PORT142, NULL);
gpio_request(GPIO_PORT176, NULL);
gpio_direction_output(GPIO_PORT176, 1);
gpio_request(GPIO_PORT6, NULL);
gpio_direction_input(GPIO_PORT6);
if (gpio_get_value(GPIO_PORT6)) {
} else {
gpio_request(GPIO_FN_SDHI1_CLK, NULL);
gpio_request(GPIO_FN_SDHI1_CMD, NULL);
gpio_request(GPIO_FN_SDHI1_D0, NULL);
gpio_request(GPIO_FN_SDHI1_D1, NULL);
gpio_request(GPIO_FN_SDHI1_D2, NULL);
gpio_request(GPIO_FN_SDHI1_D3, NULL);
gpio_request(GPIO_FN_SDHI1_CD, NULL);
gpio_request(GPIO_FN_SDHI1_WP, NULL);
gpio_request(GPIO_PORT16, NULL);
gpio_direction_output(GPIO_PORT16, 1);
platform_device_register(&sdhi1_device);
}
#ifdef CONFIG_CACHE_L2X0
l2x0_init(__io(0xf0002000), 0x40440000, 0x82000fff);
#endif
i2c_register_board_info(0, i2c0_devices, ARRAY_SIZE(i2c0_devices));
r8a7740_add_standard_devices();
platform_add_devices(eva_devices,
ARRAY_SIZE(eva_devices));
}
static void __init eva_earlytimer_init(void)
{
r8a7740_clock_init(MD_CK0 | MD_CK2);
shmobile_earlytimer_init();
}
static void __init eva_add_early_devices(void)
{
r8a7740_add_early_devices();
shmobile_timer.init = eva_earlytimer_init;
}
