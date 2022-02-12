static int isp1301_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
return 0;
}
static int isp1301_remove(struct i2c_client *client)
{
return 0;
}
static void i2c_write(u8 buf, u8 subaddr)
{
char tmpbuf[2];
tmpbuf[0] = subaddr;
tmpbuf[1] = buf;
i2c_master_send(isp1301_i2c_client, &tmpbuf[0], 2);
}
static void isp1301_configure(void)
{
i2c_write(MC1_DAT_SE0 | MC1_SPEED_REG, ISP1301_I2C_MODE_CONTROL_1);
i2c_write(~(MC1_DAT_SE0 | MC1_SPEED_REG),
ISP1301_I2C_MODE_CONTROL_1 | ISP1301_I2C_REG_CLEAR_ADDR);
i2c_write(MC2_BI_DI | MC2_PSW_EN | MC2_SPD_SUSP_CTRL,
ISP1301_I2C_MODE_CONTROL_2);
i2c_write(~(MC2_BI_DI | MC2_PSW_EN | MC2_SPD_SUSP_CTRL),
ISP1301_I2C_MODE_CONTROL_2 | ISP1301_I2C_REG_CLEAR_ADDR);
i2c_write(OTG1_DM_PULLDOWN | OTG1_DP_PULLDOWN,
ISP1301_I2C_OTG_CONTROL_1);
i2c_write(~(OTG1_DM_PULLDOWN | OTG1_DP_PULLDOWN),
ISP1301_I2C_OTG_CONTROL_1 | ISP1301_I2C_REG_CLEAR_ADDR);
i2c_write(0xFF,
ISP1301_I2C_INTERRUPT_LATCH | ISP1301_I2C_REG_CLEAR_ADDR);
i2c_write(0xFF,
ISP1301_I2C_INTERRUPT_FALLING | ISP1301_I2C_REG_CLEAR_ADDR);
i2c_write(0xFF,
ISP1301_I2C_INTERRUPT_RISING | ISP1301_I2C_REG_CLEAR_ADDR);
}
static inline void isp1301_vbus_on(void)
{
i2c_write(OTG1_VBUS_DRV, ISP1301_I2C_OTG_CONTROL_1);
}
static inline void isp1301_vbus_off(void)
{
i2c_write(OTG1_VBUS_DRV,
ISP1301_I2C_OTG_CONTROL_1 | ISP1301_I2C_REG_CLEAR_ADDR);
}
static void pnx4008_start_hc(void)
{
unsigned long tmp = __raw_readl(USB_OTG_STAT_CONTROL) | HOST_EN;
__raw_writel(tmp, USB_OTG_STAT_CONTROL);
isp1301_vbus_on();
}
static void pnx4008_stop_hc(void)
{
unsigned long tmp;
isp1301_vbus_off();
tmp = __raw_readl(USB_OTG_STAT_CONTROL) & ~HOST_EN;
__raw_writel(tmp, USB_OTG_STAT_CONTROL);
}
static int __devinit ohci_pnx4008_start(struct usb_hcd *hcd)
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
static void pnx4008_set_usb_bits(void)
{
start_int_set_falling_edge(SE_USB_OTG_ATX_INT_N);
start_int_ack(SE_USB_OTG_ATX_INT_N);
start_int_umask(SE_USB_OTG_ATX_INT_N);
start_int_set_rising_edge(SE_USB_OTG_TIMER_INT);
start_int_ack(SE_USB_OTG_TIMER_INT);
start_int_umask(SE_USB_OTG_TIMER_INT);
start_int_set_rising_edge(SE_USB_I2C_INT);
start_int_ack(SE_USB_I2C_INT);
start_int_umask(SE_USB_I2C_INT);
start_int_set_rising_edge(SE_USB_INT);
start_int_ack(SE_USB_INT);
start_int_umask(SE_USB_INT);
start_int_set_rising_edge(SE_USB_NEED_CLK_INT);
start_int_ack(SE_USB_NEED_CLK_INT);
start_int_umask(SE_USB_NEED_CLK_INT);
start_int_set_rising_edge(SE_USB_AHB_NEED_CLK_INT);
start_int_ack(SE_USB_AHB_NEED_CLK_INT);
start_int_umask(SE_USB_AHB_NEED_CLK_INT);
}
static void pnx4008_unset_usb_bits(void)
{
start_int_mask(SE_USB_OTG_ATX_INT_N);
start_int_mask(SE_USB_OTG_TIMER_INT);
start_int_mask(SE_USB_I2C_INT);
start_int_mask(SE_USB_INT);
start_int_mask(SE_USB_NEED_CLK_INT);
start_int_mask(SE_USB_AHB_NEED_CLK_INT);
}
static int __devinit usb_hcd_pnx4008_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd = 0;
struct ohci_hcd *ohci;
const struct hc_driver *driver = &ohci_pnx4008_hc_driver;
struct i2c_adapter *i2c_adap;
struct i2c_board_info i2c_info;
int ret = 0, irq;
dev_dbg(&pdev->dev, "%s: " DRIVER_DESC " (pnx4008)\n", hcd_name);
if (usb_disabled()) {
err("USB is disabled");
ret = -ENODEV;
goto out;
}
if (pdev->num_resources != 2
|| pdev->resource[0].flags != IORESOURCE_MEM
|| pdev->resource[1].flags != IORESOURCE_IRQ) {
err("Invalid resource configuration");
ret = -ENODEV;
goto out;
}
__raw_writel(USB_SLAVE_HCLK_EN | (1 << 19), USB_CTRL);
ret = i2c_add_driver(&isp1301_driver);
if (ret < 0) {
err("failed to add ISP1301 driver");
goto out;
}
i2c_adap = i2c_get_adapter(2);
memset(&i2c_info, 0, sizeof(struct i2c_board_info));
strlcpy(i2c_info.type, "isp1301_pnx", I2C_NAME_SIZE);
isp1301_i2c_client = i2c_new_probed_device(i2c_adap, &i2c_info,
normal_i2c, NULL);
i2c_put_adapter(i2c_adap);
if (!isp1301_i2c_client) {
err("failed to connect I2C to ISP1301 USB Transceiver");
ret = -ENODEV;
goto out_i2c_driver;
}
isp1301_configure();
usb_clk = clk_get(&pdev->dev, "ck_pll5");
if (IS_ERR(usb_clk)) {
err("failed to acquire USB PLL");
ret = PTR_ERR(usb_clk);
goto out1;
}
ret = clk_enable(usb_clk);
if (ret < 0) {
err("failed to start USB PLL");
goto out2;
}
ret = clk_set_rate(usb_clk, 48000);
if (ret < 0) {
err("failed to set USB clock rate");
goto out3;
}
__raw_writel(__raw_readl(USB_CTRL) | USB_HOST_NEED_CLK_EN, USB_CTRL);
__raw_writel(USB_CLOCK_MASK, USB_OTG_CLK_CTRL);
while ((__raw_readl(USB_OTG_CLK_STAT) & USB_CLOCK_MASK) !=
USB_CLOCK_MASK) ;
hcd = usb_create_hcd (driver, &pdev->dev, dev_name(&pdev->dev));
if (!hcd) {
err("Failed to allocate HC buffer");
ret = -ENOMEM;
goto out3;
}
pnx4008_set_usb_bits();
hcd->rsrc_start = pdev->resource[0].start;
hcd->rsrc_len = pdev->resource[0].end - pdev->resource[0].start + 1;
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
dev_dbg(&pdev->dev, "request_mem_region failed\n");
ret = -ENOMEM;
goto out4;
}
hcd->regs = (void __iomem *)pdev->resource[0].start;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
ret = -ENXIO;
goto out4;
}
pnx4008_start_hc();
platform_set_drvdata(pdev, hcd);
ohci = hcd_to_ohci(hcd);
ohci_hcd_init(ohci);
dev_info(&pdev->dev, "at 0x%p, irq %d\n", hcd->regs, hcd->irq);
ret = usb_add_hcd(hcd, irq, 0);
if (ret == 0)
return ret;
pnx4008_stop_hc();
out4:
pnx4008_unset_usb_bits();
usb_put_hcd(hcd);
out3:
clk_disable(usb_clk);
out2:
clk_put(usb_clk);
out1:
i2c_unregister_device(isp1301_i2c_client);
isp1301_i2c_client = NULL;
out_i2c_driver:
i2c_del_driver(&isp1301_driver);
out:
return ret;
}
static int usb_hcd_pnx4008_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
pnx4008_stop_hc();
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
pnx4008_unset_usb_bits();
clk_disable(usb_clk);
clk_put(usb_clk);
i2c_unregister_device(isp1301_i2c_client);
isp1301_i2c_client = NULL;
i2c_del_driver(&isp1301_driver);
platform_set_drvdata(pdev, NULL);
return 0;
}
