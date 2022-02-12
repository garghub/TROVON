static int usbhs_get_vbus(struct platform_device *pdev)
{
struct usbhs_private *priv = usbhs_get_priv(pdev);
return !((1 << 7) & __raw_readw(priv->cr2));
}
static int usbhs_phy_reset(struct platform_device *pdev)
{
struct usbhs_private *priv = usbhs_get_priv(pdev);
__raw_writew(0x8a0a, priv->cr2);
return 0;
}
static int usbhs_get_id(struct platform_device *pdev)
{
return USBHS_GADGET;
}
static irqreturn_t usbhs_interrupt(int irq, void *data)
{
struct platform_device *pdev = data;
struct usbhs_private *priv = usbhs_get_priv(pdev);
renesas_usbhs_call_notify_hotplug(pdev);
__raw_writew(__raw_readw(priv->phy) | USB_PHY_INT_CLR, priv->phy);
return IRQ_HANDLED;
}
static int usbhs_hardware_init(struct platform_device *pdev)
{
struct usbhs_private *priv = usbhs_get_priv(pdev);
int ret;
__raw_writew(USB_PHY_MODE | USB_PHY_INT_CLR, priv->phy);
ret = request_irq(IRQ15, usbhs_interrupt, IRQF_TRIGGER_HIGH,
dev_name(&pdev->dev), pdev);
if (ret) {
dev_err(&pdev->dev, "request_irq err\n");
return ret;
}
__raw_writew(USB_PHY_MODE | USB_PHY_INT_EN, priv->phy);
return 0;
}
static int usbhs_hardware_exit(struct platform_device *pdev)
{
struct usbhs_private *priv = usbhs_get_priv(pdev);
__raw_writew(USB_PHY_MODE | USB_PHY_INT_CLR, priv->phy);
free_irq(IRQ15, pdev);
return 0;
}
static void __init kzm_init(void)
{
regulator_register_always_on(2, "fixed-1.8V", fixed1v8_power_consumers,
ARRAY_SIZE(fixed1v8_power_consumers), 1800000);
regulator_register_fixed(3, dummy_supplies, ARRAY_SIZE(dummy_supplies));
pinctrl_register_mappings(kzm_pinctrl_map, ARRAY_SIZE(kzm_pinctrl_map));
sh73a0_pinmux_init();
gpio_request_one(224, GPIOF_IN, NULL);
gpio_request_one(222, GPIOF_OUT_INIT_HIGH, NULL);
gpio_request_one(226, GPIOF_OUT_INIT_HIGH, NULL);
gpio_request_one(223, GPIOF_IN, NULL);
#ifdef CONFIG_CACHE_L2X0
l2x0_init(IOMEM(0xf0100000), 0x00400000, 0xc20f0fff);
#endif
i2c_register_board_info(0, i2c0_devices, ARRAY_SIZE(i2c0_devices));
i2c_register_board_info(1, i2c1_devices, ARRAY_SIZE(i2c1_devices));
i2c_register_board_info(3, i2c3_devices, ARRAY_SIZE(i2c3_devices));
sh73a0_add_standard_devices();
platform_add_devices(kzm_devices, ARRAY_SIZE(kzm_devices));
sh73a0_pm_init();
}
static void kzm9g_restart(enum reboot_mode mode, const char *cmd)
{
#define RESCNT2 IOMEM(0xe6188020)
writel((1 << 31), RESCNT2);
}
