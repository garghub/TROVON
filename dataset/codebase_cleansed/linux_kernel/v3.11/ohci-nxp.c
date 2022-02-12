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
__raw_writel(__raw_readl(USB_CTRL) | USB_HOST_NEED_CLK_EN, USB_CTRL);
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
static void nxp_start_hc(void)
{
unsigned long tmp = __raw_readl(USB_OTG_STAT_CONTROL) | HOST_EN;
__raw_writel(tmp, USB_OTG_STAT_CONTROL);
isp1301_vbus_on();
}
static void nxp_stop_hc(void)
{
unsigned long tmp;
isp1301_vbus_off();
tmp = __raw_readl(USB_OTG_STAT_CONTROL) & ~HOST_EN;
__raw_writel(tmp, USB_OTG_STAT_CONTROL);
}
static int ohci_nxp_start(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
int ret;
if ((ret = ohci_init(ohci)) < 0)
return ret;
if ((ret = ohci_run(ohci)) < 0) {
dev_err(hcd->self.controller, "can't start\n");
ohci_stop(hcd);
return ret;
}
return 0;
}
static int usb_hcd_nxp_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd = 0;
struct ohci_hcd *ohci;
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
if (!isp1301_i2c_client) {
return -EPROBE_DEFER;
}
pdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
pdev->dev.dma_mask = &pdev->dev.coherent_dma_mask;
dev_dbg(&pdev->dev, "%s: " DRIVER_DESC " (nxp)\n", hcd_name);
if (usb_disabled()) {
dev_err(&pdev->dev, "USB is disabled\n");
ret = -ENODEV;
goto fail_disable;
}
__raw_writel(USB_SLAVE_HCLK_EN | PAD_CONTROL_LAST_DRIVEN, USB_CTRL);
usb_pll_clk = clk_get(&pdev->dev, "ck_pll5");
if (IS_ERR(usb_pll_clk)) {
dev_err(&pdev->dev, "failed to acquire USB PLL\n");
ret = PTR_ERR(usb_pll_clk);
goto fail_pll;
}
ret = clk_enable(usb_pll_clk);
if (ret < 0) {
dev_err(&pdev->dev, "failed to start USB PLL\n");
goto fail_pllen;
}
ret = clk_set_rate(usb_pll_clk, 48000);
if (ret < 0) {
dev_err(&pdev->dev, "failed to set USB clock rate\n");
goto fail_rate;
}
usb_dev_clk = clk_get(&pdev->dev, "ck_usbd");
if (IS_ERR(usb_dev_clk)) {
dev_err(&pdev->dev, "failed to acquire USB DEV Clock\n");
ret = PTR_ERR(usb_dev_clk);
goto fail_dev;
}
ret = clk_enable(usb_dev_clk);
if (ret < 0) {
dev_err(&pdev->dev, "failed to start USB DEV Clock\n");
goto fail_deven;
}
usb_otg_clk = clk_get(&pdev->dev, "ck_usb_otg");
if (IS_ERR(usb_otg_clk)) {
dev_err(&pdev->dev, "failed to acquire USB DEV Clock\n");
ret = PTR_ERR(usb_otg_clk);
goto fail_otg;
}
__raw_writel(__raw_readl(USB_CTRL) | USB_HOST_NEED_CLK_EN, USB_CTRL);
ret = clk_enable(usb_otg_clk);
if (ret < 0) {
dev_err(&pdev->dev, "failed to start USB DEV Clock\n");
goto fail_otgen;
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
nxp_start_hc();
platform_set_drvdata(pdev, hcd);
ohci = hcd_to_ohci(hcd);
ohci_hcd_init(ohci);
dev_info(&pdev->dev, "at 0x%p, irq %d\n", hcd->regs, hcd->irq);
ret = usb_add_hcd(hcd, irq, 0);
if (ret == 0)
return ret;
nxp_stop_hc();
fail_resource:
usb_put_hcd(hcd);
fail_hcd:
clk_disable(usb_otg_clk);
fail_otgen:
clk_put(usb_otg_clk);
fail_otg:
clk_disable(usb_dev_clk);
fail_deven:
clk_put(usb_dev_clk);
fail_dev:
fail_rate:
clk_disable(usb_pll_clk);
fail_pllen:
clk_put(usb_pll_clk);
fail_pll:
fail_disable:
isp1301_i2c_client = NULL;
return ret;
}
static int usb_hcd_nxp_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
nxp_stop_hc();
usb_put_hcd(hcd);
clk_disable(usb_pll_clk);
clk_put(usb_pll_clk);
clk_disable(usb_dev_clk);
clk_put(usb_dev_clk);
i2c_unregister_device(isp1301_i2c_client);
isp1301_i2c_client = NULL;
return 0;
}
