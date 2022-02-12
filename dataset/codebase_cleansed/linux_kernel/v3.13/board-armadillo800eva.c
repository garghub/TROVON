static int usbhsf_get_id(struct platform_device *pdev)
{
return USBHS_GADGET;
}
static int usbhsf_power_ctrl(struct platform_device *pdev,
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
return 0;
}
static int usbhsf_get_vbus(struct platform_device *pdev)
{
return gpio_get_value(209);
}
static irqreturn_t usbhsf_interrupt(int irq, void *data)
{
struct platform_device *pdev = data;
renesas_usbhs_call_notify_hotplug(pdev);
return IRQ_HANDLED;
}
static int usbhsf_hardware_exit(struct platform_device *pdev)
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
free_irq(IRQ7, pdev);
return 0;
}
static int usbhsf_hardware_init(struct platform_device *pdev)
{
struct usbhsf_private *priv = usbhsf_get_priv(pdev);
int ret;
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
ret = request_irq(IRQ7, usbhsf_interrupt, IRQF_TRIGGER_NONE,
dev_name(&pdev->dev), pdev);
if (ret) {
dev_err(&pdev->dev, "request_irq err\n");
return ret;
}
irq_set_irq_type(IRQ7, IRQ_TYPE_EDGE_BOTH);
clk_set_rate(priv->usb24,
clk_get_rate(clk_get_parent(priv->usb24)));
return 0;
}
static int mt9t111_power(struct device *dev, int mode)
{
struct clk *mclk = clk_get(NULL, "video1");
if (IS_ERR(mclk)) {
dev_err(dev, "can't get video1 clock\n");
return -EINVAL;
}
if (mode) {
clk_set_rate(mclk, clk_round_rate(mclk, 24000000));
clk_enable(mclk);
gpio_set_value(158, 1);
} else {
gpio_set_value(158, 0);
clk_disable(mclk);
}
clk_put(mclk);
return 0;
}
static void __init eva_clock_init(void)
{
struct clk *system = clk_get(NULL, "system_clk");
struct clk *xtal1 = clk_get(NULL, "extal1");
struct clk *usb24s = clk_get(NULL, "usb24s");
struct clk *fsibck = clk_get(NULL, "fsibck");
if (IS_ERR(system) ||
IS_ERR(xtal1) ||
IS_ERR(usb24s) ||
IS_ERR(fsibck)) {
pr_err("armadillo800eva board clock init failed\n");
goto clock_error;
}
clk_set_rate(xtal1, 24000000);
clk_set_parent(usb24s, system);
clk_set_rate(fsibck, 12288000);
clock_error:
if (!IS_ERR(system))
clk_put(system);
if (!IS_ERR(xtal1))
clk_put(xtal1);
if (!IS_ERR(usb24s))
clk_put(usb24s);
if (!IS_ERR(fsibck))
clk_put(fsibck);
}
static void __init eva_init(void)
{
struct platform_device *usb = NULL;
regulator_register_always_on(0, "fixed-3.3V", fixed3v3_power_consumers,
ARRAY_SIZE(fixed3v3_power_consumers), 3300000);
regulator_register_always_on(3, "fixed-5.0V", fixed5v0_power_consumers,
ARRAY_SIZE(fixed5v0_power_consumers), 5000000);
pinctrl_register_mappings(eva_pinctrl_map, ARRAY_SIZE(eva_pinctrl_map));
pwm_add_table(pwm_lookup, ARRAY_SIZE(pwm_lookup));
r8a7740_pinmux_init();
r8a7740_meram_workaround();
gpio_request_one(61, GPIOF_OUT_INIT_HIGH, NULL);
gpio_request_one(18, GPIOF_OUT_INIT_HIGH, NULL);
gpio_request_one(159, GPIOF_IN, NULL);
if (gpio_get_value(159)) {
} else {
gpio_request_one(209, GPIOF_IN, NULL);
platform_device_register(&usbhsf_device);
usb = &usbhsf_device;
}
gpio_request_one(173, GPIOF_OUT_INIT_LOW, NULL);
gpio_request_one(172, GPIOF_OUT_INIT_HIGH, NULL);
gpio_request_one(158, GPIOF_OUT_INIT_LOW, NULL);
gpio_request(7, NULL);
gpio_request(8, NULL);
gpio_direction_none(GPIO_PORT7CR);
gpio_direction_none(GPIO_PORT8CR);
gpio_request_one(176, GPIOF_OUT_INIT_HIGH, NULL);
gpio_request_one(6, GPIOF_IN, NULL);
if (gpio_get_value(6)) {
} else {
pinctrl_register_mappings(eva_sdhi1_pinctrl_map,
ARRAY_SIZE(eva_sdhi1_pinctrl_map));
platform_device_register(&vcc_sdhi1);
platform_device_register(&sdhi1_device);
}
#ifdef CONFIG_CACHE_L2X0
l2x0_init(IOMEM(0xf0002000), 0x40440000, 0x82000fff);
#endif
i2c_register_board_info(0, i2c0_devices, ARRAY_SIZE(i2c0_devices));
i2c_register_board_info(2, i2c2_devices, ARRAY_SIZE(i2c2_devices));
r8a7740_add_standard_devices();
platform_add_devices(eva_devices,
ARRAY_SIZE(eva_devices));
rmobile_add_device_to_domain("A4LC", &lcdc0_device);
rmobile_add_device_to_domain("A4LC", &hdmi_lcdc_device);
if (usb)
rmobile_add_device_to_domain("A3SP", usb);
r8a7740_pm_init();
}
static void __init eva_earlytimer_init(void)
{
r8a7740_clock_init(MD_CK0 | MD_CK2);
shmobile_earlytimer_init();
eva_clock_init();
}
static void __init eva_add_early_devices(void)
{
r8a7740_add_early_devices();
}
static void eva_restart(enum reboot_mode mode, const char *cmd)
{
writel((1 << 31), RESCNT2);
}
