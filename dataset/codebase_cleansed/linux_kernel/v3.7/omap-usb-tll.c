static inline void usbtll_write(void __iomem *base, u32 reg, u32 val)
{
__raw_writel(val, base + reg);
}
static inline u32 usbtll_read(void __iomem *base, u32 reg)
{
return __raw_readl(base + reg);
}
static inline void usbtll_writeb(void __iomem *base, u8 reg, u8 val)
{
__raw_writeb(val, base + reg);
}
static inline u8 usbtll_readb(void __iomem *base, u8 reg)
{
return __raw_readb(base + reg);
}
static bool is_ohci_port(enum usbhs_omap_port_mode pmode)
{
switch (pmode) {
case OMAP_OHCI_PORT_MODE_PHY_6PIN_DATSE0:
case OMAP_OHCI_PORT_MODE_PHY_6PIN_DPDM:
case OMAP_OHCI_PORT_MODE_PHY_3PIN_DATSE0:
case OMAP_OHCI_PORT_MODE_PHY_4PIN_DPDM:
case OMAP_OHCI_PORT_MODE_TLL_6PIN_DATSE0:
case OMAP_OHCI_PORT_MODE_TLL_6PIN_DPDM:
case OMAP_OHCI_PORT_MODE_TLL_3PIN_DATSE0:
case OMAP_OHCI_PORT_MODE_TLL_4PIN_DPDM:
case OMAP_OHCI_PORT_MODE_TLL_2PIN_DATSE0:
case OMAP_OHCI_PORT_MODE_TLL_2PIN_DPDM:
return true;
default:
return false;
}
}
static unsigned ohci_omap3_fslsmode(enum usbhs_omap_port_mode mode)
{
switch (mode) {
case OMAP_USBHS_PORT_MODE_UNUSED:
case OMAP_OHCI_PORT_MODE_PHY_6PIN_DATSE0:
return OMAP_TLL_FSLSMODE_6PIN_PHY_DAT_SE0;
case OMAP_OHCI_PORT_MODE_PHY_6PIN_DPDM:
return OMAP_TLL_FSLSMODE_6PIN_PHY_DP_DM;
case OMAP_OHCI_PORT_MODE_PHY_3PIN_DATSE0:
return OMAP_TLL_FSLSMODE_3PIN_PHY;
case OMAP_OHCI_PORT_MODE_PHY_4PIN_DPDM:
return OMAP_TLL_FSLSMODE_4PIN_PHY;
case OMAP_OHCI_PORT_MODE_TLL_6PIN_DATSE0:
return OMAP_TLL_FSLSMODE_6PIN_TLL_DAT_SE0;
case OMAP_OHCI_PORT_MODE_TLL_6PIN_DPDM:
return OMAP_TLL_FSLSMODE_6PIN_TLL_DP_DM;
case OMAP_OHCI_PORT_MODE_TLL_3PIN_DATSE0:
return OMAP_TLL_FSLSMODE_3PIN_TLL;
case OMAP_OHCI_PORT_MODE_TLL_4PIN_DPDM:
return OMAP_TLL_FSLSMODE_4PIN_TLL;
case OMAP_OHCI_PORT_MODE_TLL_2PIN_DATSE0:
return OMAP_TLL_FSLSMODE_2PIN_TLL_DAT_SE0;
case OMAP_OHCI_PORT_MODE_TLL_2PIN_DPDM:
return OMAP_TLL_FSLSMODE_2PIN_DAT_DP_DM;
default:
pr_warn("Invalid port mode, using default\n");
return OMAP_TLL_FSLSMODE_6PIN_PHY_DAT_SE0;
}
}
static int __devinit usbtll_omap_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct usbtll_omap_platform_data *pdata = dev->platform_data;
void __iomem *base;
struct resource *res;
struct usbtll_omap *tll;
unsigned reg;
unsigned long flags;
int ret = 0;
int i, ver, count;
dev_dbg(dev, "starting TI HSUSB TLL Controller\n");
tll = kzalloc(sizeof(struct usbtll_omap), GFP_KERNEL);
if (!tll) {
dev_err(dev, "Memory allocation failed\n");
ret = -ENOMEM;
goto end;
}
spin_lock_init(&tll->lock);
for (i = 0; i < OMAP3_HS_USB_PORTS; i++)
tll->platdata.port_mode[i] = pdata->port_mode[i];
tll->usbtll_p1_fck = clk_get(dev, "usb_tll_hs_usb_ch0_clk");
if (IS_ERR(tll->usbtll_p1_fck)) {
ret = PTR_ERR(tll->usbtll_p1_fck);
dev_err(dev, "usbtll_p1_fck failed error:%d\n", ret);
goto err_tll;
}
tll->usbtll_p2_fck = clk_get(dev, "usb_tll_hs_usb_ch1_clk");
if (IS_ERR(tll->usbtll_p2_fck)) {
ret = PTR_ERR(tll->usbtll_p2_fck);
dev_err(dev, "usbtll_p2_fck failed error:%d\n", ret);
goto err_usbtll_p1_fck;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "usb tll get resource failed\n");
ret = -ENODEV;
goto err_usbtll_p2_fck;
}
base = ioremap(res->start, resource_size(res));
if (!base) {
dev_err(dev, "TLL ioremap failed\n");
ret = -ENOMEM;
goto err_usbtll_p2_fck;
}
platform_set_drvdata(pdev, tll);
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
spin_lock_irqsave(&tll->lock, flags);
ver = usbtll_read(base, OMAP_USBTLL_REVISION);
switch (ver) {
case OMAP_USBTLL_REV1:
case OMAP_USBTLL_REV2:
count = OMAP_TLL_CHANNEL_COUNT;
break;
case OMAP_USBTLL_REV3:
count = OMAP_REV2_TLL_CHANNEL_COUNT;
break;
default:
dev_err(dev, "TLL version failed\n");
ret = -ENODEV;
goto err_ioremap;
}
if (is_ehci_tll_mode(pdata->port_mode[0]) ||
is_ehci_tll_mode(pdata->port_mode[1]) ||
is_ehci_tll_mode(pdata->port_mode[2]) ||
is_ohci_port(pdata->port_mode[0]) ||
is_ohci_port(pdata->port_mode[1]) ||
is_ohci_port(pdata->port_mode[2])) {
reg = usbtll_read(base, OMAP_TLL_SHARED_CONF);
reg |= (OMAP_TLL_SHARED_CONF_FCLK_IS_ON
| OMAP_TLL_SHARED_CONF_USB_DIVRATION);
reg &= ~OMAP_TLL_SHARED_CONF_USB_90D_DDR_EN;
reg &= ~OMAP_TLL_SHARED_CONF_USB_180D_SDR_EN;
usbtll_write(base, OMAP_TLL_SHARED_CONF, reg);
for (i = 0; i < count; i++) {
reg = usbtll_read(base, OMAP_TLL_CHANNEL_CONF(i));
if (is_ohci_port(pdata->port_mode[i])) {
reg |= ohci_omap3_fslsmode(pdata->port_mode[i])
<< OMAP_TLL_CHANNEL_CONF_FSLSMODE_SHIFT;
reg |= OMAP_TLL_CHANNEL_CONF_CHANMODE_FSLS;
} else if (pdata->port_mode[i] ==
OMAP_EHCI_PORT_MODE_TLL) {
reg &= ~(OMAP_TLL_CHANNEL_CONF_UTMIAUTOIDLE
| OMAP_TLL_CHANNEL_CONF_ULPINOBITSTUFF
| OMAP_TLL_CHANNEL_CONF_ULPIDDRMODE);
} else {
continue;
}
reg |= OMAP_TLL_CHANNEL_CONF_CHANEN;
usbtll_write(base, OMAP_TLL_CHANNEL_CONF(i), reg);
usbtll_writeb(base,
OMAP_TLL_ULPI_SCRATCH_REGISTER(i),
0xbe);
}
}
err_ioremap:
spin_unlock_irqrestore(&tll->lock, flags);
iounmap(base);
pm_runtime_put_sync(dev);
tll_pdev = pdev;
if (!ret)
goto end;
pm_runtime_disable(dev);
err_usbtll_p2_fck:
clk_put(tll->usbtll_p2_fck);
err_usbtll_p1_fck:
clk_put(tll->usbtll_p1_fck);
err_tll:
kfree(tll);
end:
return ret;
}
static int __devexit usbtll_omap_remove(struct platform_device *pdev)
{
struct usbtll_omap *tll = platform_get_drvdata(pdev);
clk_put(tll->usbtll_p2_fck);
clk_put(tll->usbtll_p1_fck);
pm_runtime_disable(&pdev->dev);
kfree(tll);
return 0;
}
static int usbtll_runtime_resume(struct device *dev)
{
struct usbtll_omap *tll = dev_get_drvdata(dev);
struct usbtll_omap_platform_data *pdata = &tll->platdata;
unsigned long flags;
dev_dbg(dev, "usbtll_runtime_resume\n");
if (!pdata) {
dev_dbg(dev, "missing platform_data\n");
return -ENODEV;
}
spin_lock_irqsave(&tll->lock, flags);
if (is_ehci_tll_mode(pdata->port_mode[0]))
clk_enable(tll->usbtll_p1_fck);
if (is_ehci_tll_mode(pdata->port_mode[1]))
clk_enable(tll->usbtll_p2_fck);
spin_unlock_irqrestore(&tll->lock, flags);
return 0;
}
static int usbtll_runtime_suspend(struct device *dev)
{
struct usbtll_omap *tll = dev_get_drvdata(dev);
struct usbtll_omap_platform_data *pdata = &tll->platdata;
unsigned long flags;
dev_dbg(dev, "usbtll_runtime_suspend\n");
if (!pdata) {
dev_dbg(dev, "missing platform_data\n");
return -ENODEV;
}
spin_lock_irqsave(&tll->lock, flags);
if (is_ehci_tll_mode(pdata->port_mode[0]))
clk_disable(tll->usbtll_p1_fck);
if (is_ehci_tll_mode(pdata->port_mode[1]))
clk_disable(tll->usbtll_p2_fck);
spin_unlock_irqrestore(&tll->lock, flags);
return 0;
}
int omap_tll_enable(void)
{
if (!tll_pdev) {
pr_err("missing omap usbhs tll platform_data\n");
return -ENODEV;
}
return pm_runtime_get_sync(&tll_pdev->dev);
}
int omap_tll_disable(void)
{
if (!tll_pdev) {
pr_err("missing omap usbhs tll platform_data\n");
return -ENODEV;
}
return pm_runtime_put_sync(&tll_pdev->dev);
}
static int __init omap_usbtll_drvinit(void)
{
return platform_driver_register(&usbtll_omap_driver);
}
static void __exit omap_usbtll_drvexit(void)
{
platform_driver_unregister(&usbtll_omap_driver);
}
