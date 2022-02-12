static inline void usbtll_write(void __iomem *base, u32 reg, u32 val)
{
writel_relaxed(val, base + reg);
}
static inline u32 usbtll_read(void __iomem *base, u32 reg)
{
return readl_relaxed(base + reg);
}
static inline void usbtll_writeb(void __iomem *base, u8 reg, u8 val)
{
writeb_relaxed(val, base + reg);
}
static inline u8 usbtll_readb(void __iomem *base, u8 reg)
{
return readb_relaxed(base + reg);
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
static int usbtll_omap_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct usbtll_omap *tll;
int ret = 0;
int i, ver;
dev_dbg(dev, "starting TI HSUSB TLL Controller\n");
tll = devm_kzalloc(dev, sizeof(struct usbtll_omap), GFP_KERNEL);
if (!tll) {
dev_err(dev, "Memory allocation failed\n");
return -ENOMEM;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
tll->base = devm_ioremap_resource(dev, res);
if (IS_ERR(tll->base))
return PTR_ERR(tll->base);
platform_set_drvdata(pdev, tll);
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
ver = usbtll_read(tll->base, OMAP_USBTLL_REVISION);
switch (ver) {
case OMAP_USBTLL_REV1:
case OMAP_USBTLL_REV4:
tll->nch = OMAP_TLL_CHANNEL_COUNT;
break;
case OMAP_USBTLL_REV2:
case OMAP_USBTLL_REV3:
tll->nch = OMAP_REV2_TLL_CHANNEL_COUNT;
break;
default:
tll->nch = OMAP_TLL_CHANNEL_COUNT;
dev_dbg(dev,
"USB TLL Rev : 0x%x not recognized, assuming %d channels\n",
ver, tll->nch);
break;
}
tll->ch_clk = devm_kzalloc(dev, sizeof(struct clk *) * tll->nch,
GFP_KERNEL);
if (!tll->ch_clk) {
ret = -ENOMEM;
dev_err(dev, "Couldn't allocate memory for channel clocks\n");
goto err_clk_alloc;
}
for (i = 0; i < tll->nch; i++) {
char clkname[] = "usb_tll_hs_usb_chx_clk";
snprintf(clkname, sizeof(clkname),
"usb_tll_hs_usb_ch%d_clk", i);
tll->ch_clk[i] = clk_get(dev, clkname);
if (IS_ERR(tll->ch_clk[i]))
dev_dbg(dev, "can't get clock : %s\n", clkname);
else
clk_prepare(tll->ch_clk[i]);
}
pm_runtime_put_sync(dev);
spin_lock(&tll_lock);
tll_dev = dev;
spin_unlock(&tll_lock);
return 0;
err_clk_alloc:
pm_runtime_put_sync(dev);
pm_runtime_disable(dev);
return ret;
}
static int usbtll_omap_remove(struct platform_device *pdev)
{
struct usbtll_omap *tll = platform_get_drvdata(pdev);
int i;
spin_lock(&tll_lock);
tll_dev = NULL;
spin_unlock(&tll_lock);
for (i = 0; i < tll->nch; i++) {
if (!IS_ERR(tll->ch_clk[i])) {
clk_unprepare(tll->ch_clk[i]);
clk_put(tll->ch_clk[i]);
}
}
pm_runtime_disable(&pdev->dev);
return 0;
}
int omap_tll_init(struct usbhs_omap_platform_data *pdata)
{
int i;
bool needs_tll;
unsigned reg;
struct usbtll_omap *tll;
if (!tll_dev)
return -ENODEV;
pm_runtime_get_sync(tll_dev);
spin_lock(&tll_lock);
tll = dev_get_drvdata(tll_dev);
needs_tll = false;
for (i = 0; i < tll->nch; i++)
needs_tll |= omap_usb_mode_needs_tll(pdata->port_mode[i]);
if (needs_tll) {
void __iomem *base = tll->base;
reg = usbtll_read(base, OMAP_TLL_SHARED_CONF);
reg |= (OMAP_TLL_SHARED_CONF_FCLK_IS_ON
| OMAP_TLL_SHARED_CONF_USB_DIVRATION);
reg &= ~OMAP_TLL_SHARED_CONF_USB_90D_DDR_EN;
reg &= ~OMAP_TLL_SHARED_CONF_USB_180D_SDR_EN;
usbtll_write(base, OMAP_TLL_SHARED_CONF, reg);
for (i = 0; i < tll->nch; i++) {
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
} else if (pdata->port_mode[i] ==
OMAP_EHCI_PORT_MODE_HSIC) {
reg |= OMAP_TLL_CHANNEL_CONF_DRVVBUS
| OMAP_TLL_CHANNEL_CONF_CHRGVBUS
| OMAP_TLL_CHANNEL_CONF_MODE_TRANSPARENT_UTMI
| OMAP_TLL_CHANNEL_CONF_ULPINOBITSTUFF;
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
spin_unlock(&tll_lock);
pm_runtime_put_sync(tll_dev);
return 0;
}
int omap_tll_enable(struct usbhs_omap_platform_data *pdata)
{
int i;
struct usbtll_omap *tll;
if (!tll_dev)
return -ENODEV;
pm_runtime_get_sync(tll_dev);
spin_lock(&tll_lock);
tll = dev_get_drvdata(tll_dev);
for (i = 0; i < tll->nch; i++) {
if (omap_usb_mode_needs_tll(pdata->port_mode[i])) {
int r;
if (IS_ERR(tll->ch_clk[i]))
continue;
r = clk_enable(tll->ch_clk[i]);
if (r) {
dev_err(tll_dev,
"Error enabling ch %d clock: %d\n", i, r);
}
}
}
spin_unlock(&tll_lock);
return 0;
}
int omap_tll_disable(struct usbhs_omap_platform_data *pdata)
{
int i;
struct usbtll_omap *tll;
if (!tll_dev)
return -ENODEV;
spin_lock(&tll_lock);
tll = dev_get_drvdata(tll_dev);
for (i = 0; i < tll->nch; i++) {
if (omap_usb_mode_needs_tll(pdata->port_mode[i])) {
if (!IS_ERR(tll->ch_clk[i]))
clk_disable(tll->ch_clk[i]);
}
}
spin_unlock(&tll_lock);
pm_runtime_put_sync(tll_dev);
return 0;
}
static int __init omap_usbtll_drvinit(void)
{
return platform_driver_register(&usbtll_omap_driver);
}
static void __exit omap_usbtll_drvexit(void)
{
platform_driver_unregister(&usbtll_omap_driver);
}
