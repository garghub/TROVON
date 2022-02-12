static int mackerel_set_brightness(int brightness)
{
gpio_set_value(GPIO_PORT31, brightness);
return 0;
}
static void __init hdmi_init_pm_clock(void)
{
struct clk *hdmi_ick = clk_get(&hdmi_device.dev, "ick");
int ret;
long rate;
if (IS_ERR(hdmi_ick)) {
ret = PTR_ERR(hdmi_ick);
pr_err("Cannot get HDMI ICK: %d\n", ret);
goto out;
}
ret = clk_set_parent(&sh7372_pllc2_clk, &sh7372_dv_clki_div2_clk);
if (ret < 0) {
pr_err("Cannot set PLLC2 parent: %d, %d users\n",
ret, sh7372_pllc2_clk.usecount);
goto out;
}
pr_debug("PLLC2 initial frequency %lu\n",
clk_get_rate(&sh7372_pllc2_clk));
rate = clk_round_rate(&sh7372_pllc2_clk, 594000000);
if (rate < 0) {
pr_err("Cannot get suitable rate: %ld\n", rate);
ret = rate;
goto out;
}
ret = clk_set_rate(&sh7372_pllc2_clk, rate);
if (ret < 0) {
pr_err("Cannot set rate %ld: %d\n", rate, ret);
goto out;
}
pr_debug("PLLC2 set frequency %lu\n", rate);
ret = clk_set_parent(hdmi_ick, &sh7372_pllc2_clk);
if (ret < 0)
pr_err("Cannot set HDMI parent: %d\n", ret);
out:
if (!IS_ERR(hdmi_ick))
clk_put(hdmi_ick);
}
static int usbhs_get_vbus(struct platform_device *pdev)
{
return usbhs_is_connected(usbhs_get_priv(pdev));
}
static void usbhs_phy_reset(struct platform_device *pdev)
{
struct usbhs_private *priv = usbhs_get_priv(pdev);
__raw_writew(0x8a0a, priv->usbcrcaddr);
}
static int usbhs0_get_id(struct platform_device *pdev)
{
return USBHS_GADGET;
}
static void usbhs0_work_function(struct work_struct *work)
{
struct usbhs_private *priv = container_of(work, struct usbhs_private,
work.work);
renesas_usbhs_call_notify_hotplug(priv->pdev);
schedule_delayed_work(&priv->work, USBHS0_POLL_INTERVAL);
}
static int usbhs0_hardware_init(struct platform_device *pdev)
{
struct usbhs_private *priv = usbhs_get_priv(pdev);
priv->pdev = pdev;
INIT_DELAYED_WORK(&priv->work, usbhs0_work_function);
schedule_delayed_work(&priv->work, USBHS0_POLL_INTERVAL);
return 0;
}
static void usbhs0_hardware_exit(struct platform_device *pdev)
{
struct usbhs_private *priv = usbhs_get_priv(pdev);
cancel_delayed_work_sync(&priv->work);
}
static irqreturn_t usbhs1_interrupt(int irq, void *data)
{
struct platform_device *pdev = data;
struct usbhs_private *priv = usbhs_get_priv(pdev);
dev_dbg(&pdev->dev, "%s\n", __func__);
renesas_usbhs_call_notify_hotplug(pdev);
__raw_writew(__raw_readw(priv->usbphyaddr) | USB_PHY_INT_CLR,
priv->usbphyaddr);
return IRQ_HANDLED;
}
static int usbhs1_hardware_init(struct platform_device *pdev)
{
struct usbhs_private *priv = usbhs_get_priv(pdev);
int ret;
__raw_writew(USB_PHY_MODE | USB_PHY_INT_CLR, priv->usbphyaddr);
ret = request_irq(IRQ8, usbhs1_interrupt, IRQF_TRIGGER_HIGH,
dev_name(&pdev->dev), pdev);
if (ret) {
dev_err(&pdev->dev, "request_irq err\n");
return ret;
}
__raw_writew(USB_PHY_MODE | USB_PHY_INT_EN, priv->usbphyaddr);
return 0;
}
static void usbhs1_hardware_exit(struct platform_device *pdev)
{
struct usbhs_private *priv = usbhs_get_priv(pdev);
__raw_writew(USB_PHY_MODE | USB_PHY_INT_CLR, priv->usbphyaddr);
free_irq(IRQ8, pdev);
}
static int usbhs1_get_id(struct platform_device *pdev)
{
return USBHS_HOST;
}
static int slot_cn7_get_cd(struct platform_device *pdev)
{
return !gpio_get_value(GPIO_PORT41);
}
static int slot_cn23_get_cd(struct platform_device *pdev)
{
return !gpio_get_value(GPIO_PORT162);
}
static int camera_set_capture(struct soc_camera_platform_info *info,
int enable)
{
return 0;
}
static void mackerel_camera_release(struct device *dev)
{
soc_camera_platform_release(&camera_device);
}
static int mackerel_camera_add(struct soc_camera_device *icd)
{
return soc_camera_platform_add(icd, &camera_device, &camera_link,
mackerel_camera_release, 0);
}
static void mackerel_camera_del(struct soc_camera_device *icd)
{
soc_camera_platform_del(icd, camera_device, &camera_link);
}
static void __init mackerel_init(void)
{
struct pm_domain_device domain_devices[] = {
{ "A4LC", &lcdc_device, },
{ "A4LC", &hdmi_lcdc_device, },
{ "A4LC", &meram_device, },
{ "A4MP", &fsi_device, },
{ "A3SP", &usbhs0_device, },
{ "A3SP", &usbhs1_device, },
{ "A3SP", &nand_flash_device, },
{ "A3SP", &sh_mmcif_device, },
{ "A3SP", &sdhi0_device, },
#if !defined(CONFIG_MMC_SH_MMCIF) && !defined(CONFIG_MMC_SH_MMCIF_MODULE)
{ "A3SP", &sdhi1_device, },
#endif
{ "A3SP", &sdhi2_device, },
{ "A4R", &ceu_device, },
};
u32 srcr4;
struct clk *clk;
regulator_register_always_on(0, "fixed-1.8V", fixed1v8_power_consumers,
ARRAY_SIZE(fixed1v8_power_consumers), 1800000);
regulator_register_always_on(1, "fixed-3.3V", fixed3v3_power_consumers,
ARRAY_SIZE(fixed3v3_power_consumers), 3300000);
regulator_register_fixed(2, dummy_supplies, ARRAY_SIZE(dummy_supplies));
clk_set_rate(&sh7372_dv_clki_clk, 27000000);
sh7372_pinmux_init();
gpio_request(GPIO_FN_SCIFA0_TXD, NULL);
gpio_request(GPIO_FN_SCIFA0_RXD, NULL);
gpio_request(GPIO_FN_CS5A, NULL);
gpio_request(GPIO_FN_IRQ6_39, NULL);
gpio_request(GPIO_FN_LCDD23, NULL);
gpio_request(GPIO_FN_LCDD22, NULL);
gpio_request(GPIO_FN_LCDD21, NULL);
gpio_request(GPIO_FN_LCDD20, NULL);
gpio_request(GPIO_FN_LCDD19, NULL);
gpio_request(GPIO_FN_LCDD18, NULL);
gpio_request(GPIO_FN_LCDD17, NULL);
gpio_request(GPIO_FN_LCDD16, NULL);
gpio_request(GPIO_FN_LCDD15, NULL);
gpio_request(GPIO_FN_LCDD14, NULL);
gpio_request(GPIO_FN_LCDD13, NULL);
gpio_request(GPIO_FN_LCDD12, NULL);
gpio_request(GPIO_FN_LCDD11, NULL);
gpio_request(GPIO_FN_LCDD10, NULL);
gpio_request(GPIO_FN_LCDD9, NULL);
gpio_request(GPIO_FN_LCDD8, NULL);
gpio_request(GPIO_FN_LCDD7, NULL);
gpio_request(GPIO_FN_LCDD6, NULL);
gpio_request(GPIO_FN_LCDD5, NULL);
gpio_request(GPIO_FN_LCDD4, NULL);
gpio_request(GPIO_FN_LCDD3, NULL);
gpio_request(GPIO_FN_LCDD2, NULL);
gpio_request(GPIO_FN_LCDD1, NULL);
gpio_request(GPIO_FN_LCDD0, NULL);
gpio_request(GPIO_FN_LCDDISP, NULL);
gpio_request(GPIO_FN_LCDDCK, NULL);
gpio_request_one(GPIO_PORT31, GPIOF_OUT_INIT_LOW, NULL);
gpio_request_one(GPIO_PORT151, GPIOF_OUT_INIT_HIGH, NULL);
gpio_request(GPIO_FN_VBUS0_0, NULL);
gpio_request_pulldown(GPIO_PORT168CR);
gpio_request(GPIO_FN_VBUS0_1, NULL);
gpio_request_pulldown(GPIO_PORT167CR);
gpio_request(GPIO_FN_IDIN_1_113, NULL);
gpio_request(GPIO_FN_FSIAIBT, NULL);
gpio_request(GPIO_FN_FSIAILR, NULL);
gpio_request(GPIO_FN_FSIAISLD, NULL);
gpio_request(GPIO_FN_FSIAOSLD, NULL);
gpio_request_one(GPIO_PORT161, GPIOF_OUT_INIT_LOW, NULL);
gpio_request(GPIO_PORT9, NULL);
gpio_request(GPIO_PORT10, NULL);
gpio_direction_none(GPIO_PORT9CR);
gpio_direction_none(GPIO_PORT10CR);
intc_set_priority(IRQ_FSI, 3);
gpio_request(GPIO_FN_FSIBCK, NULL);
__raw_writew(__raw_readw(USCCR1) & ~(1 << 6), USCCR1);
clk = clk_get(NULL, "spu_clk");
if (!IS_ERR(clk)) {
clk_set_rate(clk, clk_round_rate(clk, 119600000));
clk_put(clk);
}
gpio_request(GPIO_FN_IRQ9_42, NULL);
irq_set_irq_type(IRQ9, IRQ_TYPE_LEVEL_HIGH);
gpio_request(GPIO_FN_IRQ7_40, NULL);
irq_set_irq_type(IRQ7, IRQ_TYPE_LEVEL_LOW);
gpio_request(GPIO_FN_IRQ21, NULL);
irq_set_irq_type(IRQ21, IRQ_TYPE_LEVEL_HIGH);
gpio_request(GPIO_FN_SDHIWP0, NULL);
gpio_request(GPIO_FN_SDHICMD0, NULL);
gpio_request(GPIO_FN_SDHICLK0, NULL);
gpio_request(GPIO_FN_SDHID0_3, NULL);
gpio_request(GPIO_FN_SDHID0_2, NULL);
gpio_request(GPIO_FN_SDHID0_1, NULL);
gpio_request(GPIO_FN_SDHID0_0, NULL);
gpio_request(GPIO_FN_IRQ26_172, NULL);
#if !defined(CONFIG_MMC_SH_MMCIF) && !defined(CONFIG_MMC_SH_MMCIF_MODULE)
gpio_request(GPIO_FN_SDHICMD1, NULL);
gpio_request(GPIO_FN_SDHICLK1, NULL);
gpio_request(GPIO_FN_SDHID1_3, NULL);
gpio_request(GPIO_FN_SDHID1_2, NULL);
gpio_request(GPIO_FN_SDHID1_1, NULL);
gpio_request(GPIO_FN_SDHID1_0, NULL);
#endif
gpio_request_one(GPIO_PORT41, GPIOF_IN, NULL);
gpio_request(GPIO_FN_SDHICMD2, NULL);
gpio_request(GPIO_FN_SDHICLK2, NULL);
gpio_request(GPIO_FN_SDHID2_3, NULL);
gpio_request(GPIO_FN_SDHID2_2, NULL);
gpio_request(GPIO_FN_SDHID2_1, NULL);
gpio_request(GPIO_FN_SDHID2_0, NULL);
gpio_request_one(GPIO_PORT162, GPIOF_IN, NULL);
gpio_request(GPIO_FN_MMCD0_0, NULL);
gpio_request(GPIO_FN_MMCD0_1, NULL);
gpio_request(GPIO_FN_MMCD0_2, NULL);
gpio_request(GPIO_FN_MMCD0_3, NULL);
gpio_request(GPIO_FN_MMCD0_4, NULL);
gpio_request(GPIO_FN_MMCD0_5, NULL);
gpio_request(GPIO_FN_MMCD0_6, NULL);
gpio_request(GPIO_FN_MMCD0_7, NULL);
gpio_request(GPIO_FN_MMCCMD0, NULL);
gpio_request(GPIO_FN_MMCCLK0, NULL);
gpio_request(GPIO_FN_D0_NAF0, NULL);
gpio_request(GPIO_FN_D1_NAF1, NULL);
gpio_request(GPIO_FN_D2_NAF2, NULL);
gpio_request(GPIO_FN_D3_NAF3, NULL);
gpio_request(GPIO_FN_D4_NAF4, NULL);
gpio_request(GPIO_FN_D5_NAF5, NULL);
gpio_request(GPIO_FN_D6_NAF6, NULL);
gpio_request(GPIO_FN_D7_NAF7, NULL);
gpio_request(GPIO_FN_D8_NAF8, NULL);
gpio_request(GPIO_FN_D9_NAF9, NULL);
gpio_request(GPIO_FN_D10_NAF10, NULL);
gpio_request(GPIO_FN_D11_NAF11, NULL);
gpio_request(GPIO_FN_D12_NAF12, NULL);
gpio_request(GPIO_FN_D13_NAF13, NULL);
gpio_request(GPIO_FN_D14_NAF14, NULL);
gpio_request(GPIO_FN_D15_NAF15, NULL);
gpio_request(GPIO_FN_FCE0, NULL);
gpio_request(GPIO_FN_WE0_FWE, NULL);
gpio_request(GPIO_FN_FRB, NULL);
gpio_request(GPIO_FN_A4_FOE, NULL);
gpio_request(GPIO_FN_A5_FCDE, NULL);
gpio_request(GPIO_FN_RD_FSC, NULL);
gpio_request(GPIO_FN_SCIFA2_TXD1, NULL);
gpio_request(GPIO_FN_SCIFA2_RXD1, NULL);
gpio_request(GPIO_FN_VIO_CLK, NULL);
gpio_request(GPIO_FN_VIO_VD, NULL);
gpio_request(GPIO_FN_VIO_HD, NULL);
gpio_request(GPIO_FN_VIO_FIELD, NULL);
gpio_request(GPIO_FN_VIO_CKO, NULL);
gpio_request(GPIO_FN_VIO_D7, NULL);
gpio_request(GPIO_FN_VIO_D6, NULL);
gpio_request(GPIO_FN_VIO_D5, NULL);
gpio_request(GPIO_FN_VIO_D4, NULL);
gpio_request(GPIO_FN_VIO_D3, NULL);
gpio_request(GPIO_FN_VIO_D2, NULL);
gpio_request(GPIO_FN_VIO_D1, NULL);
gpio_request(GPIO_FN_VIO_D0, NULL);
gpio_request(GPIO_FN_HDMI_HPD, NULL);
gpio_request(GPIO_FN_HDMI_CEC, NULL);
srcr4 = __raw_readl(SRCR4);
__raw_writel(srcr4 | (1 << 13), SRCR4);
udelay(50);
__raw_writel(srcr4 & ~(1 << 13), SRCR4);
i2c_register_board_info(0, i2c0_devices,
ARRAY_SIZE(i2c0_devices));
i2c_register_board_info(1, i2c1_devices,
ARRAY_SIZE(i2c1_devices));
sh7372_add_standard_devices();
platform_add_devices(mackerel_devices, ARRAY_SIZE(mackerel_devices));
rmobile_add_devices_to_domains(domain_devices,
ARRAY_SIZE(domain_devices));
hdmi_init_pm_clock();
sh7372_pm_init();
pm_clk_add(&fsi_device.dev, "spu2");
pm_clk_add(&hdmi_lcdc_device.dev, "hdmi");
}
