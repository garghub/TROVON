static inline void ehci_write(void __iomem *base, u32 reg, u32 val)
{
__raw_writel(val, base + reg);
}
static inline u32 ehci_read(void __iomem *base, u32 reg)
{
return __raw_readl(base + reg);
}
static void omap_ehci_soft_phy_reset(struct platform_device *pdev, u8 port)
{
struct usb_hcd *hcd = dev_get_drvdata(&pdev->dev);
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
dev_dbg(&pdev->dev, "phy reset operation timed out\n");
break;
}
}
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
struct ehci_hcd *omap_ehci;
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
ret = omap_usbhs_enable(dev);
if (ret) {
dev_err(dev, "failed to start usbhs with err %d\n", ret);
goto err_enable;
}
ehci_write(regs, EHCI_INSNREG04,
EHCI_INSNREG04_DISABLE_UNSUSPEND);
if (pdata->port_mode[0] == OMAP_EHCI_PORT_MODE_PHY)
omap_ehci_soft_phy_reset(pdev, 0);
if (pdata->port_mode[1] == OMAP_EHCI_PORT_MODE_PHY)
omap_ehci_soft_phy_reset(pdev, 1);
omap_ehci = hcd_to_ehci(hcd);
omap_ehci->sbrn = 0x20;
omap_ehci->caps = hcd->regs;
omap_ehci->regs = hcd->regs
+ HC_LENGTH(ehci, readl(&omap_ehci->caps->hc_capbase));
dbg_hcs_params(omap_ehci, "reset");
dbg_hcc_params(omap_ehci, "reset");
omap_ehci->hcs_params = readl(&omap_ehci->caps->hcs_params);
ret = usb_add_hcd(hcd, irq, IRQF_DISABLED | IRQF_SHARED);
if (ret) {
dev_err(dev, "failed to add hcd with err %d\n", ret);
goto err_add_hcd;
}
ehci_port_power(omap_ehci, 1);
return 0;
err_add_hcd:
omap_usbhs_disable(dev);
err_enable:
disable_put_regulator(pdata);
usb_put_hcd(hcd);
err_io:
iounmap(regs);
return ret;
}
static int ehci_hcd_omap_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct usb_hcd *hcd = dev_get_drvdata(dev);
usb_remove_hcd(hcd);
omap_usbhs_disable(dev);
disable_put_regulator(dev->platform_data);
iounmap(hcd->regs);
usb_put_hcd(hcd);
return 0;
}
static void ehci_hcd_omap_shutdown(struct platform_device *pdev)
{
struct usb_hcd *hcd = dev_get_drvdata(&pdev->dev);
if (hcd->driver->shutdown)
hcd->driver->shutdown(hcd);
}
