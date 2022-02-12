static int smartbot_otg_init(struct platform_device *pdev)
{
return mx31_initialize_usb_hw(pdev->id, MXC_EHCI_POWER_PINS_ENABLED);
}
static int __init smartbot_otg_host_init(void)
{
struct platform_device *pdev;
otg_host_pdata.otg = imx_otg_ulpi_create(ULPI_OTG_DRVVBUS |
ULPI_OTG_DRVVBUS_EXT);
if (!otg_host_pdata.otg)
return -ENODEV;
pdev = imx31_add_mxc_ehci_otg(&otg_host_pdata);
return PTR_ERR_OR_ZERO(pdev);
}
static inline int smartbot_otg_host_init(void) { return 0; }
static void smartbot_resets_init(void)
{
if (!gpio_request(POWER_EN, "power-enable")) {
gpio_direction_output(POWER_EN, 0);
gpio_export(POWER_EN, false);
}
if (!gpio_request(DSPIC_RST_B, "dspic-rst")) {
gpio_direction_output(DSPIC_RST_B, 0);
gpio_export(DSPIC_RST_B, false);
}
if (!gpio_request(TRSLAT_RST_B, "translator-rst")) {
gpio_direction_output(TRSLAT_RST_B, 0);
gpio_export(TRSLAT_RST_B, false);
}
if (!gpio_request(TRSLAT_SRC_CHOICE, "translator-src-choice")) {
gpio_direction_output(TRSLAT_SRC_CHOICE, 0);
gpio_export(TRSLAT_SRC_CHOICE, false);
}
}
void __init mx31moboard_smartbot_init(int board)
{
printk(KERN_INFO "Initializing mx31smartbot peripherals\n");
mxc_iomux_setup_multiple_pins(smartbot_pins, ARRAY_SIZE(smartbot_pins),
"smartbot");
imx31_add_imx_uart1(&uart_pdata);
switch (board) {
case MX31SMARTBOT:
imx31_add_fsl_usb2_udc(&usb_pdata);
break;
case MX31EYEBOT:
smartbot_otg_host_init();
break;
default:
printk(KERN_WARNING "Unknown board %d, USB OTG not initialized",
board);
}
smartbot_resets_init();
}
