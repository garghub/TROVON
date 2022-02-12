static void isp1301_configure_lpc32xx(void)
{
i2c_smbus_write_byte_data(isp1301_i2c_client,
(ISP1301_I2C_MODE_CONTROL_1 | ISP1301_I2C_REG_CLEAR_ADDR),
MC1_UART_EN);
i2c_smbus_write_byte_data(isp1301_i2c_client,
(ISP1301_I2C_MODE_CONTROL_1 | ISP1301_I2C_REG_CLEAR_ADDR),
~MC1_SPEED_REG);
i2c_smbus_write_byte_data(isp1301_i2c_client,
ISP1301_I2C_MODE_CONTROL_1, MC1_SPEED_REG);
i2c_smbus_write_byte_data(isp1301_i2c_client,
(ISP1301_I2C_MODE_CONTROL_2 | ISP1301_I2C_REG_CLEAR_ADDR),
~0);
i2c_smbus_write_byte_data(isp1301_i2c_client,
ISP1301_I2C_MODE_CONTROL_2,
(MC2_BI_DI | MC2_PSW_EN | MC2_SPD_SUSP_CTRL));
i2c_smbus_write_byte_data(isp1301_i2c_client,
(ISP1301_I2C_OTG_CONTROL_1 | ISP1301_I2C_REG_CLEAR_ADDR), ~0);
i2c_smbus_write_byte_data(isp1301_i2c_client,
ISP1301_I2C_MODE_CONTROL_1, MC1_DAT_SE0);
i2c_smbus_write_byte_data(isp1301_i2c_client,
ISP1301_I2C_OTG_CONTROL_1,
(OTG1_DM_PULLDOWN | OTG1_DP_PULLDOWN));
i2c_smbus_write_byte_data(isp1301_i2c_client,
(ISP1301_I2C_OTG_CONTROL_1 | ISP1301_I2C_REG_CLEAR_ADDR),
(OTG1_DM_PULLUP | OTG1_DP_PULLUP));
i2c_smbus_write_byte_data(isp1301_i2c_client,
ISP1301_I2C_INTERRUPT_LATCH | ISP1301_I2C_REG_CLEAR_ADDR, ~0);
i2c_smbus_write_byte_data(isp1301_i2c_client,
ISP1301_I2C_INTERRUPT_FALLING | ISP1301_I2C_REG_CLEAR_ADDR,
~0);
i2c_smbus_write_byte_data(isp1301_i2c_client,
ISP1301_I2C_INTERRUPT_RISING | ISP1301_I2C_REG_CLEAR_ADDR, ~0);
printk(KERN_INFO "ISP1301 Vendor ID : 0x%04x\n",
i2c_smbus_read_word_data(isp1301_i2c_client, 0x00));
printk(KERN_INFO "ISP1301 Product ID : 0x%04x\n",
i2c_smbus_read_word_data(isp1301_i2c_client, 0x02));
printk(KERN_INFO "ISP1301 Version ID : 0x%04x\n",
i2c_smbus_read_word_data(isp1301_i2c_client, 0x14));
}
static void isp1301_configure(void)
{
isp1301_configure_lpc32xx();
}
static inline void isp1301_vbus_on(void)
{
i2c_smbus_write_byte_data(isp1301_i2c_client, ISP1301_I2C_OTG_CONTROL_1,
OTG1_VBUS_DRV);
}
static inline void isp1301_vbus_off(void)
{
i2c_smbus_write_byte_data(isp1301_i2c_client,
ISP1301_I2C_OTG_CONTROL_1 | ISP1301_I2C_REG_CLEAR_ADDR,
OTG1_VBUS_DRV);
}
static void ohci_nxp_start_hc(void)
{
unsigned long tmp = __raw_readl(USB_OTG_STAT_CONTROL) | HOST_EN;
__raw_writel(tmp, USB_OTG_STAT_CONTROL);
isp1301_vbus_on();
}
static void ohci_nxp_stop_hc(void)
{
unsigned long tmp;
isp1301_vbus_off();
tmp = __raw_readl(USB_OTG_STAT_CONTROL) & ~HOST_EN;
__raw_writel(tmp, USB_OTG_STAT_CONTROL);
}
static int ohci_hcd_nxp_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd = 0;
const struct hc_driver *driver = &ohci_nxp_hc_driver;
struct resource *res;
int ret = 0, irq;
struct device_node *isp1301_node;
if (pdev->dev.of_node) {
isp1301_node = of_parse_phandle(pdev->dev.of_node,
"transceiver", 0);
} else {
isp1301_node = NULL;
}
isp1301_i2c_client = isp1301_get_client(isp1301_node);
if (!isp1301_i2c_client)
return -EPROBE_DEFER;
ret = dma_coerce_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (ret)
goto fail_disable;
dev_dbg(&pdev->dev, "%s: " DRIVER_DESC " (nxp)\n", hcd_name);
if (usb_disabled()) {
dev_err(&pdev->dev, "USB is disabled\n");
ret = -ENODEV;
goto fail_disable;
}
usb_host_clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(usb_host_clk)) {
dev_err(&pdev->dev, "failed to acquire USB OHCI clock\n");
ret = PTR_ERR(usb_host_clk);
goto fail_disable;
}
ret = clk_prepare_enable(usb_host_clk);
if (ret < 0) {
dev_err(&pdev->dev, "failed to start USB OHCI clock\n");
goto fail_disable;
}
isp1301_configure();
hcd = usb_create_hcd(driver, &pdev->dev, dev_name(&pdev->dev));
if (!hcd) {
dev_err(&pdev->dev, "Failed to allocate HC buffer\n");
ret = -ENOMEM;
goto fail_hcd;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hcd->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hcd->regs)) {
ret = PTR_ERR(hcd->regs);
goto fail_resource;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
ret = -ENXIO;
goto fail_resource;
}
ohci_nxp_start_hc();
platform_set_drvdata(pdev, hcd);
dev_info(&pdev->dev, "at 0x%p, irq %d\n", hcd->regs, hcd->irq);
ret = usb_add_hcd(hcd, irq, 0);
if (ret == 0) {
device_wakeup_enable(hcd->self.controller);
return ret;
}
ohci_nxp_stop_hc();
fail_resource:
usb_put_hcd(hcd);
fail_hcd:
clk_disable_unprepare(usb_host_clk);
fail_disable:
isp1301_i2c_client = NULL;
return ret;
}
static int ohci_hcd_nxp_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
ohci_nxp_stop_hc();
usb_put_hcd(hcd);
clk_disable_unprepare(usb_host_clk);
isp1301_i2c_client = NULL;
return 0;
}
static int __init ohci_nxp_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info("%s: " DRIVER_DESC "\n", hcd_name);
ohci_init_driver(&ohci_nxp_hc_driver, NULL);
return platform_driver_register(&ohci_hcd_nxp_driver);
}
static void __exit ohci_nxp_cleanup(void)
{
platform_driver_unregister(&ohci_hcd_nxp_driver);
}
