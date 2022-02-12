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
static int usbhs_phy_reset(struct platform_device *pdev)
{
struct usbhs_private *priv = usbhs_get_priv(pdev);
__raw_writew(0x8a0a, priv->usbcrcaddr);
return 0;
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
static int usbhs0_hardware_exit(struct platform_device *pdev)
{
struct usbhs_private *priv = usbhs_get_priv(pdev);
cancel_delayed_work_sync(&priv->work);
return 0;
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
static int usbhs1_hardware_exit(struct platform_device *pdev)
{
struct usbhs_private *priv = usbhs_get_priv(pdev);
__raw_writew(USB_PHY_MODE | USB_PHY_INT_CLR, priv->usbphyaddr);
free_irq(IRQ8, pdev);
return 0;
}
static int usbhs1_get_id(struct platform_device *pdev)
{
return USBHS_HOST;
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
{ "A3SP", &sdhi0_device, },
#if !IS_ENABLED(CONFIG_MMC_SH_MMCIF)
{ "A3SP", &sdhi1_device, },
#else
{ "A3SP", &sh_mmcif_device, },
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
pinctrl_register_mappings(mackerel_pinctrl_map,
ARRAY_SIZE(mackerel_pinctrl_map));
sh7372_pinmux_init();
gpio_request_one(151, GPIOF_OUT_INIT_HIGH, NULL);
gpio_request_pulldown(GPIO_PORT168CR);
gpio_request_pulldown(GPIO_PORT167CR);
gpio_request_one(161, GPIOF_OUT_INIT_LOW, NULL);
gpio_request(9, NULL);
gpio_request(10, NULL);
gpio_direction_none(GPIO_PORT9CR);
gpio_direction_none(GPIO_PORT10CR);
intc_set_priority(IRQ_FSI, 3);
__raw_writew(__raw_readw(USCCR1) & ~(1 << 6), USCCR1);
clk = clk_get(NULL, "spu_clk");
if (!IS_ERR(clk)) {
clk_set_rate(clk, clk_round_rate(clk, 119600000));
clk_put(clk);
}
irq_set_irq_type(IRQ9, IRQ_TYPE_LEVEL_HIGH);
irq_set_irq_type(IRQ7, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IRQ21, IRQ_TYPE_LEVEL_HIGH);
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
