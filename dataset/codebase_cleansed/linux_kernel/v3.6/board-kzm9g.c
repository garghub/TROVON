static int usbhs_get_vbus(struct platform_device *pdev)
{
struct usbhs_private *priv = usbhs_get_priv(pdev);
return !((1 << 7) & __raw_readw(priv->cr2));
}
static void usbhs_phy_reset(struct platform_device *pdev)
{
struct usbhs_private *priv = usbhs_get_priv(pdev);
__raw_writew(0x8a0a, priv->cr2);
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
static void usbhs_hardware_exit(struct platform_device *pdev)
{
struct usbhs_private *priv = usbhs_get_priv(pdev);
__raw_writew(USB_PHY_MODE | USB_PHY_INT_CLR, priv->phy);
free_irq(IRQ15, pdev);
}
static int __init as3711_enable_lcdc_backlight(void)
{
struct i2c_adapter *a = i2c_get_adapter(0);
struct i2c_msg msg;
int i, ret;
__u8 magic[] = {
0x40, 0x2a,
0x43, 0x3c,
0x44, 0x3c,
0x45, 0x3c,
0x54, 0x03,
0x51, 0x00,
0x51, 0x01,
0xff, 0x00,
0x43, 0xf0,
0x44, 0xf0,
0x45, 0xf0,
};
if (!machine_is_kzm9g())
return 0;
if (!a)
return 0;
msg.addr = 0x40;
msg.len = 2;
msg.flags = 0;
for (i = 0; i < ARRAY_SIZE(magic); i += 2) {
msg.buf = magic + i;
if (0xff == msg.buf[0]) {
udelay(500);
continue;
}
ret = i2c_transfer(a, &msg, 1);
if (ret < 0) {
pr_err("i2c transfer fail\n");
break;
}
}
return 0;
}
static void __init kzm_init(void)
{
regulator_register_always_on(0, "fixed-1.8V", fixed1v8_power_consumers,
ARRAY_SIZE(fixed1v8_power_consumers), 1800000);
regulator_register_always_on(1, "fixed-2.8V", fixed2v8_power_consumers,
ARRAY_SIZE(fixed2v8_power_consumers), 2800000);
regulator_register_fixed(2, dummy_supplies, ARRAY_SIZE(dummy_supplies));
sh73a0_pinmux_init();
gpio_request(GPIO_FN_SCIFA4_TXD, NULL);
gpio_request(GPIO_FN_SCIFA4_RXD, NULL);
gpio_request(GPIO_FN_SCIFA4_RTS_, NULL);
gpio_request(GPIO_FN_SCIFA4_CTS_, NULL);
gpio_request(GPIO_FN_CS4_, NULL);
gpio_request(GPIO_PORT224, NULL);
gpio_direction_input(GPIO_PORT224);
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
gpio_request(GPIO_PORT222, NULL);
gpio_request(GPIO_PORT226, NULL);
gpio_direction_output(GPIO_PORT222, 1);
gpio_direction_output(GPIO_PORT226, 1);
gpio_request(GPIO_PORT223, NULL);
gpio_direction_input(GPIO_PORT223);
gpio_request(GPIO_FN_MMCCLK0, NULL);
gpio_request(GPIO_FN_MMCCMD0_PU, NULL);
gpio_request(GPIO_FN_MMCD0_0_PU, NULL);
gpio_request(GPIO_FN_MMCD0_1_PU, NULL);
gpio_request(GPIO_FN_MMCD0_2_PU, NULL);
gpio_request(GPIO_FN_MMCD0_3_PU, NULL);
gpio_request(GPIO_FN_MMCD0_4_PU, NULL);
gpio_request(GPIO_FN_MMCD0_5_PU, NULL);
gpio_request(GPIO_FN_MMCD0_6_PU, NULL);
gpio_request(GPIO_FN_MMCD0_7_PU, NULL);
gpio_request(GPIO_FN_SDHIWP0, NULL);
gpio_request(GPIO_FN_SDHICD0, NULL);
gpio_request(GPIO_FN_SDHICMD0, NULL);
gpio_request(GPIO_FN_SDHICLK0, NULL);
gpio_request(GPIO_FN_SDHID0_3, NULL);
gpio_request(GPIO_FN_SDHID0_2, NULL);
gpio_request(GPIO_FN_SDHID0_1, NULL);
gpio_request(GPIO_FN_SDHID0_0, NULL);
gpio_request(GPIO_FN_SDHI0_VCCQ_MC0_ON, NULL);
gpio_request(GPIO_PORT15, NULL);
gpio_direction_output(GPIO_PORT15, 1);
gpio_request(GPIO_FN_SDHID2_0, NULL);
gpio_request(GPIO_FN_SDHID2_1, NULL);
gpio_request(GPIO_FN_SDHID2_2, NULL);
gpio_request(GPIO_FN_SDHID2_3, NULL);
gpio_request(GPIO_FN_SDHICMD2, NULL);
gpio_request(GPIO_FN_SDHICLK2, NULL);
gpio_request(GPIO_PORT14, NULL);
gpio_direction_output(GPIO_PORT14, 1);
gpio_request(GPIO_FN_PORT27_I2C_SCL3, NULL);
gpio_request(GPIO_FN_PORT28_I2C_SDA3, NULL);
gpio_request(GPIO_FN_FSIACK, NULL);
gpio_request(GPIO_FN_FSIAILR, NULL);
gpio_request(GPIO_FN_FSIAIBT, NULL);
gpio_request(GPIO_FN_FSIAISLD, NULL);
gpio_request(GPIO_FN_FSIAOSLD, NULL);
gpio_request(GPIO_FN_VBUS_0, NULL);
#ifdef CONFIG_CACHE_L2X0
l2x0_init(IOMEM(0xf0100000), 0x40460000, 0x82000fff);
#endif
i2c_register_board_info(0, i2c0_devices, ARRAY_SIZE(i2c0_devices));
i2c_register_board_info(1, i2c1_devices, ARRAY_SIZE(i2c1_devices));
i2c_register_board_info(3, i2c3_devices, ARRAY_SIZE(i2c3_devices));
sh73a0_add_standard_devices();
platform_add_devices(kzm_devices, ARRAY_SIZE(kzm_devices));
}
