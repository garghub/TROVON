static void __init ath79_usb_setup(void)
{
void __iomem *usb_ctrl_base;
ath79_device_reset_set(AR71XX_USB_RESET_MASK);
mdelay(1000);
ath79_device_reset_clear(AR71XX_USB_RESET_MASK);
usb_ctrl_base = ioremap(AR71XX_USB_CTRL_BASE, AR71XX_USB_CTRL_SIZE);
__raw_writel(0xf0000, usb_ctrl_base + AR71XX_USB_CTRL_REG_CONFIG);
__raw_writel(0x20c00, usb_ctrl_base + AR71XX_USB_CTRL_REG_FLADJ);
iounmap(usb_ctrl_base);
mdelay(900);
ath79_ohci_resources[0].start = AR71XX_OHCI_BASE;
ath79_ohci_resources[0].end = AR71XX_OHCI_BASE + AR71XX_OHCI_SIZE - 1;
platform_device_register(&ath79_ohci_device);
ath79_ehci_resources[0].start = AR71XX_EHCI_BASE;
ath79_ehci_resources[0].end = AR71XX_EHCI_BASE + AR71XX_EHCI_SIZE - 1;
ath79_ehci_device.dev.platform_data = &ath79_ehci_pdata_v1;
platform_device_register(&ath79_ehci_device);
}
static void __init ar7240_usb_setup(void)
{
void __iomem *usb_ctrl_base;
ath79_device_reset_clear(AR7240_RESET_OHCI_DLL);
ath79_device_reset_set(AR7240_RESET_USB_HOST);
mdelay(1000);
ath79_device_reset_set(AR7240_RESET_OHCI_DLL);
ath79_device_reset_clear(AR7240_RESET_USB_HOST);
usb_ctrl_base = ioremap(AR7240_USB_CTRL_BASE, AR7240_USB_CTRL_SIZE);
__raw_writel(0x3, usb_ctrl_base + AR71XX_USB_CTRL_REG_FLADJ);
iounmap(usb_ctrl_base);
ath79_ohci_resources[0].start = AR7240_OHCI_BASE;
ath79_ohci_resources[0].end = AR7240_OHCI_BASE + AR7240_OHCI_SIZE - 1;
platform_device_register(&ath79_ohci_device);
}
static void __init ar724x_usb_setup(void)
{
ath79_device_reset_set(AR724X_RESET_USBSUS_OVERRIDE);
mdelay(10);
ath79_device_reset_clear(AR724X_RESET_USB_HOST);
mdelay(10);
ath79_device_reset_clear(AR724X_RESET_USB_PHY);
mdelay(10);
ath79_ehci_resources[0].start = AR724X_EHCI_BASE;
ath79_ehci_resources[0].end = AR724X_EHCI_BASE + AR724X_EHCI_SIZE - 1;
ath79_ehci_device.dev.platform_data = &ath79_ehci_pdata_v2;
platform_device_register(&ath79_ehci_device);
}
static void __init ar913x_usb_setup(void)
{
ath79_device_reset_set(AR913X_RESET_USBSUS_OVERRIDE);
mdelay(10);
ath79_device_reset_clear(AR913X_RESET_USB_HOST);
mdelay(10);
ath79_device_reset_clear(AR913X_RESET_USB_PHY);
mdelay(10);
ath79_ehci_resources[0].start = AR913X_EHCI_BASE;
ath79_ehci_resources[0].end = AR913X_EHCI_BASE + AR913X_EHCI_SIZE - 1;
ath79_ehci_device.dev.platform_data = &ath79_ehci_pdata_v2;
platform_device_register(&ath79_ehci_device);
}
static void __init ar933x_usb_setup(void)
{
ath79_device_reset_set(AR933X_RESET_USBSUS_OVERRIDE);
mdelay(10);
ath79_device_reset_clear(AR933X_RESET_USB_HOST);
mdelay(10);
ath79_device_reset_clear(AR933X_RESET_USB_PHY);
mdelay(10);
ath79_ehci_resources[0].start = AR933X_EHCI_BASE;
ath79_ehci_resources[0].end = AR933X_EHCI_BASE + AR933X_EHCI_SIZE - 1;
ath79_ehci_device.dev.platform_data = &ath79_ehci_pdata_v2;
platform_device_register(&ath79_ehci_device);
}
void __init ath79_register_usb(void)
{
if (soc_is_ar71xx())
ath79_usb_setup();
else if (soc_is_ar7240())
ar7240_usb_setup();
else if (soc_is_ar7241() || soc_is_ar7242())
ar724x_usb_setup();
else if (soc_is_ar913x())
ar913x_usb_setup();
else if (soc_is_ar933x())
ar933x_usb_setup();
else
BUG();
}
