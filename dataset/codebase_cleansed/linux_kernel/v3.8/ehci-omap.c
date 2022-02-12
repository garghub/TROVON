static inline void ehci_write(void __iomem *base, u32 reg, u32 val)
{
__raw_writel(val, base + reg);
}
static inline u32 ehci_read(void __iomem *base, u32 reg)
{
return __raw_readl(base + reg);
}
static void omap_ehci_soft_phy_reset(struct usb_hcd *hcd, u8 port)
{
unsigned long timeout = jiffies + msecs_to_jiffies(1000);
unsigned reg = 0;
reg = ULPI_FUNC_CTRL_RESET
| (ULPI_SET(ULPI_FUNC_CTRL) << EHCI_INSNREG05_ULPI_REGADD_SHIFT)
| (2 << EHCI_INSNREG05_ULPI_OPSEL_SHIFT)
| ((port + 1) << EHCI_INSNREG05_ULPI_PORTSEL_SHIFT)
| (1 << EHCI_INSNREG05_ULPI_CONTROL_SHIFT);
ehci_write(hcd->regs, EHCI_INSNREG05_ULPI, reg);
while ((ehci_read(hcd->regs, EHCI_INSNREG05_ULPI)
& (1 << EHCI_INSNREG05_ULPI_CONTROL_SHIFT))) {
cpu_relax();
if (time_after(jiffies, timeout)) {
dev_dbg(hcd->self.controller,
"phy reset operation timed out\n");
break;
}
}
}
static int omap_ehci_init(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int rc;
struct ehci_hcd_omap_platform_data *pdata;
pdata = hcd->self.controller->platform_data;
if (pdata->phy_reset) {
if (gpio_is_valid(pdata->reset_gpio_port[0]))
gpio_set_value_cansleep(pdata->reset_gpio_port[0], 0);
if (gpio_is_valid(pdata->reset_gpio_port[1]))
gpio_set_value_cansleep(pdata->reset_gpio_port[1], 0);
udelay(10);
}
if (pdata->port_mode[0] == OMAP_EHCI_PORT_MODE_PHY)
omap_ehci_soft_phy_reset(hcd, 0);
if (pdata->port_mode[1] == OMAP_EHCI_PORT_MODE_PHY)
omap_ehci_soft_phy_reset(hcd, 1);
ehci->caps = hcd->regs;
rc = ehci_setup(hcd);
if (pdata->phy_reset) {
udelay(10);
if (gpio_is_valid(pdata->reset_gpio_port[0]))
gpio_set_value_cansleep(pdata->reset_gpio_port[0], 1);
if (gpio_is_valid(pdata->reset_gpio_port[1]))
gpio_set_value_cansleep(pdata->reset_gpio_port[1], 1);
}
return rc;
}
static void disable_put_regulator(
struct ehci_hcd_omap_platform_data *pdata)
{
int i;
for (i = 0 ; i < OMAP3_HS_USB_PORTS ; i++) {
if (pdata->regulator[i]) {
regulator_disable(pdata->regulator[i]);
regulator_put(pdata->regulator[i]);
}
}
}
static int ehci_hcd_omap_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ehci_hcd_omap_platform_data *pdata = dev->platform_data;
struct resource *res;
struct usb_hcd *hcd;
void __iomem *regs;
int ret = -ENODEV;
int irq;
int i;
char supply[7];
if (usb_disabled())
return -ENODEV;
if (!dev->parent) {
dev_err(dev, "Missing parent device\n");
return -ENODEV;
}
irq = platform_get_irq_byname(pdev, "ehci-irq");
if (irq < 0) {
dev_err(dev, "EHCI irq failed\n");
return -ENODEV;
}
res = platform_get_resource_byname(pdev,
IORESOURCE_MEM, "ehci");
if (!res) {
dev_err(dev, "UHH EHCI get resource failed\n");
return -ENODEV;
}
regs = ioremap(res->start, resource_size(res));
if (!regs) {
dev_err(dev, "UHH EHCI ioremap failed\n");
return -ENOMEM;
}
hcd = usb_create_hcd(&ehci_omap_hc_driver, dev,
dev_name(dev));
if (!hcd) {
dev_err(dev, "failed to create hcd with err %d\n", ret);
ret = -ENOMEM;
goto err_io;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->regs = regs;
for (i = 0 ; i < OMAP3_HS_USB_PORTS ; i++) {
if (pdata->port_mode[i] != OMAP_EHCI_PORT_MODE_PHY) {
pdata->regulator[i] = NULL;
continue;
}
snprintf(supply, sizeof(supply), "hsusb%d", i);
pdata->regulator[i] = regulator_get(dev, supply);
if (IS_ERR(pdata->regulator[i])) {
pdata->regulator[i] = NULL;
dev_dbg(dev,
"failed to get ehci port%d regulator\n", i);
} else {
regulator_enable(pdata->regulator[i]);
}
}
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
ehci_write(regs, EHCI_INSNREG04,
EHCI_INSNREG04_DISABLE_UNSUSPEND);
ret = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (ret) {
dev_err(dev, "failed to add hcd with err %d\n", ret);
goto err_pm_runtime;
}
return 0;
err_pm_runtime:
disable_put_regulator(pdata);
pm_runtime_put_sync(dev);
usb_put_hcd(hcd);
err_io:
iounmap(regs);
return ret;
}
static int ehci_hcd_omap_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct ehci_hcd_omap_platform_data *pdata = dev->platform_data;
usb_remove_hcd(hcd);
disable_put_regulator(dev->platform_data);
iounmap(hcd->regs);
usb_put_hcd(hcd);
pm_runtime_put_sync(dev);
pm_runtime_disable(dev);
if (pdata->phy_reset) {
if (gpio_is_valid(pdata->reset_gpio_port[0]))
gpio_free(pdata->reset_gpio_port[0]);
if (gpio_is_valid(pdata->reset_gpio_port[1]))
gpio_free(pdata->reset_gpio_port[1]);
}
return 0;
}
static void ehci_hcd_omap_shutdown(struct platform_device *pdev)
{
struct usb_hcd *hcd = dev_get_drvdata(&pdev->dev);
if (hcd->driver->shutdown)
hcd->driver->shutdown(hcd);
}
