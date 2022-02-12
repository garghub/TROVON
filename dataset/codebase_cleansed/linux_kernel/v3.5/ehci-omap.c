static inline void ehci_write(void __iomem *base, u32 reg, u32 val)
{
__raw_writel(val, base + reg);
}
static inline u32 ehci_read(void __iomem *base, u32 reg)
{
return __raw_readl(base + reg);
}
static void omap_ehci_erratum_i693(struct ehci_hcd *ehci)
{
int ret = 0;
ret = clk_set_parent(utmi_p1_fck, init_60m_fclk);
if (ret != 0)
ehci_err(ehci, "init_60m_fclk set parent"
"failed error:%d\n", ret);
ret = clk_set_parent(utmi_p2_fck, init_60m_fclk);
if (ret != 0)
ehci_err(ehci, "init_60m_fclk set parent"
"failed error:%d\n", ret);
clk_enable(usbhost_p1_fck);
clk_enable(usbhost_p2_fck);
mdelay(1);
ret = clk_set_parent(utmi_p1_fck, xclk60mhsp1_ck);
if (ret != 0)
ehci_err(ehci, "xclk60mhsp1_ck set parent"
"failed error:%d\n", ret);
ret = clk_set_parent(utmi_p2_fck, xclk60mhsp2_ck);
if (ret != 0)
ehci_err(ehci, "xclk60mhsp2_ck set parent"
"failed error:%d\n", ret);
clk_disable(usbhost_p1_fck);
clk_disable(usbhost_p2_fck);
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
static int omap_ehci_hub_control(
struct usb_hcd *hcd,
u16 typeReq,
u16 wValue,
u16 wIndex,
char *buf,
u16 wLength
)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
u32 __iomem *status_reg = &ehci->regs->port_status[
(wIndex & 0xff) - 1];
u32 temp;
unsigned long flags;
int retval = 0;
spin_lock_irqsave(&ehci->lock, flags);
if (typeReq == SetPortFeature && wValue == USB_PORT_FEAT_SUSPEND) {
temp = ehci_readl(ehci, status_reg);
if ((temp & PORT_PE) == 0 || (temp & PORT_RESET) != 0) {
retval = -EPIPE;
goto done;
}
temp &= ~PORT_WKCONN_E;
temp |= PORT_WKDISC_E | PORT_WKOC_E;
ehci_writel(ehci, temp | PORT_SUSPEND, status_reg);
omap_ehci_erratum_i693(ehci);
set_bit((wIndex & 0xff) - 1, &ehci->suspended_ports);
goto done;
}
spin_unlock_irqrestore(&ehci->lock, flags);
return ehci_hub_control(hcd, typeReq, wValue, wIndex, buf, wLength);
done:
spin_unlock_irqrestore(&ehci->lock, flags);
return retval;
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
if (pdata->phy_reset) {
if (gpio_is_valid(pdata->reset_gpio_port[0]))
gpio_set_value_cansleep(pdata->reset_gpio_port[0], 0);
if (gpio_is_valid(pdata->reset_gpio_port[1]))
gpio_set_value_cansleep(pdata->reset_gpio_port[1], 0);
udelay(10);
}
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
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
ehci_reset(omap_ehci);
ret = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (ret) {
dev_err(dev, "failed to add hcd with err %d\n", ret);
goto err_add_hcd;
}
if (pdata->phy_reset) {
udelay(10);
if (gpio_is_valid(pdata->reset_gpio_port[0]))
gpio_set_value_cansleep(pdata->reset_gpio_port[0], 1);
if (gpio_is_valid(pdata->reset_gpio_port[1]))
gpio_set_value_cansleep(pdata->reset_gpio_port[1], 1);
}
ehci_port_power(omap_ehci, 1);
utmi_p1_fck = clk_get(dev, "utmi_p1_gfclk");
if (IS_ERR(utmi_p1_fck)) {
ret = PTR_ERR(utmi_p1_fck);
dev_err(dev, "utmi_p1_gfclk failed error:%d\n", ret);
goto err_add_hcd;
}
xclk60mhsp1_ck = clk_get(dev, "xclk60mhsp1_ck");
if (IS_ERR(xclk60mhsp1_ck)) {
ret = PTR_ERR(xclk60mhsp1_ck);
dev_err(dev, "xclk60mhsp1_ck failed error:%d\n", ret);
goto err_utmi_p1_fck;
}
utmi_p2_fck = clk_get(dev, "utmi_p2_gfclk");
if (IS_ERR(utmi_p2_fck)) {
ret = PTR_ERR(utmi_p2_fck);
dev_err(dev, "utmi_p2_gfclk failed error:%d\n", ret);
goto err_xclk60mhsp1_ck;
}
xclk60mhsp2_ck = clk_get(dev, "xclk60mhsp2_ck");
if (IS_ERR(xclk60mhsp2_ck)) {
ret = PTR_ERR(xclk60mhsp2_ck);
dev_err(dev, "xclk60mhsp2_ck failed error:%d\n", ret);
goto err_utmi_p2_fck;
}
usbhost_p1_fck = clk_get(dev, "usb_host_hs_utmi_p1_clk");
if (IS_ERR(usbhost_p1_fck)) {
ret = PTR_ERR(usbhost_p1_fck);
dev_err(dev, "usbhost_p1_fck failed error:%d\n", ret);
goto err_xclk60mhsp2_ck;
}
usbhost_p2_fck = clk_get(dev, "usb_host_hs_utmi_p2_clk");
if (IS_ERR(usbhost_p2_fck)) {
ret = PTR_ERR(usbhost_p2_fck);
dev_err(dev, "usbhost_p2_fck failed error:%d\n", ret);
goto err_usbhost_p1_fck;
}
init_60m_fclk = clk_get(dev, "init_60m_fclk");
if (IS_ERR(init_60m_fclk)) {
ret = PTR_ERR(init_60m_fclk);
dev_err(dev, "init_60m_fclk failed error:%d\n", ret);
goto err_usbhost_p2_fck;
}
return 0;
err_usbhost_p2_fck:
clk_put(usbhost_p2_fck);
err_usbhost_p1_fck:
clk_put(usbhost_p1_fck);
err_xclk60mhsp2_ck:
clk_put(xclk60mhsp2_ck);
err_utmi_p2_fck:
clk_put(utmi_p2_fck);
err_xclk60mhsp1_ck:
clk_put(xclk60mhsp1_ck);
err_utmi_p1_fck:
clk_put(utmi_p1_fck);
err_add_hcd:
disable_put_regulator(pdata);
pm_runtime_put_sync(dev);
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
clk_put(utmi_p1_fck);
clk_put(utmi_p2_fck);
clk_put(xclk60mhsp1_ck);
clk_put(xclk60mhsp2_ck);
clk_put(usbhost_p1_fck);
clk_put(usbhost_p2_fck);
clk_put(init_60m_fclk);
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
