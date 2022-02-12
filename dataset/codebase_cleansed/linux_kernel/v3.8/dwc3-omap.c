static inline u32 dwc3_omap_readl(void __iomem *base, u32 offset)
{
return readl(base + offset);
}
static inline void dwc3_omap_writel(void __iomem *base, u32 offset, u32 value)
{
writel(value, base + offset);
}
static int dwc3_omap_register_phys(struct dwc3_omap *omap)
{
struct nop_usb_xceiv_platform_data pdata;
struct platform_device *pdev;
int ret;
memset(&pdata, 0x00, sizeof(pdata));
pdev = platform_device_alloc("nop_usb_xceiv", 0);
if (!pdev)
return -ENOMEM;
omap->usb2_phy = pdev;
pdata.type = USB_PHY_TYPE_USB2;
ret = platform_device_add_data(omap->usb2_phy, &pdata, sizeof(pdata));
if (ret)
goto err1;
pdev = platform_device_alloc("nop_usb_xceiv", 1);
if (!pdev) {
ret = -ENOMEM;
goto err1;
}
omap->usb3_phy = pdev;
pdata.type = USB_PHY_TYPE_USB3;
ret = platform_device_add_data(omap->usb3_phy, &pdata, sizeof(pdata));
if (ret)
goto err2;
ret = platform_device_add(omap->usb2_phy);
if (ret)
goto err2;
ret = platform_device_add(omap->usb3_phy);
if (ret)
goto err3;
return 0;
err3:
platform_device_del(omap->usb2_phy);
err2:
platform_device_put(omap->usb3_phy);
err1:
platform_device_put(omap->usb2_phy);
return ret;
}
static irqreturn_t dwc3_omap_interrupt(int irq, void *_omap)
{
struct dwc3_omap *omap = _omap;
u32 reg;
spin_lock(&omap->lock);
reg = dwc3_omap_readl(omap->base, USBOTGSS_IRQSTATUS_1);
if (reg & USBOTGSS_IRQ1_DMADISABLECLR) {
dev_dbg(omap->dev, "DMA Disable was Cleared\n");
omap->dma_status = false;
}
if (reg & USBOTGSS_IRQ1_OEVT)
dev_dbg(omap->dev, "OTG Event\n");
if (reg & USBOTGSS_IRQ1_DRVVBUS_RISE)
dev_dbg(omap->dev, "DRVVBUS Rise\n");
if (reg & USBOTGSS_IRQ1_CHRGVBUS_RISE)
dev_dbg(omap->dev, "CHRGVBUS Rise\n");
if (reg & USBOTGSS_IRQ1_DISCHRGVBUS_RISE)
dev_dbg(omap->dev, "DISCHRGVBUS Rise\n");
if (reg & USBOTGSS_IRQ1_IDPULLUP_RISE)
dev_dbg(omap->dev, "IDPULLUP Rise\n");
if (reg & USBOTGSS_IRQ1_DRVVBUS_FALL)
dev_dbg(omap->dev, "DRVVBUS Fall\n");
if (reg & USBOTGSS_IRQ1_CHRGVBUS_FALL)
dev_dbg(omap->dev, "CHRGVBUS Fall\n");
if (reg & USBOTGSS_IRQ1_DISCHRGVBUS_FALL)
dev_dbg(omap->dev, "DISCHRGVBUS Fall\n");
if (reg & USBOTGSS_IRQ1_IDPULLUP_FALL)
dev_dbg(omap->dev, "IDPULLUP Fall\n");
dwc3_omap_writel(omap->base, USBOTGSS_IRQSTATUS_1, reg);
reg = dwc3_omap_readl(omap->base, USBOTGSS_IRQSTATUS_0);
dwc3_omap_writel(omap->base, USBOTGSS_IRQSTATUS_0, reg);
spin_unlock(&omap->lock);
return IRQ_HANDLED;
}
static int dwc3_omap_probe(struct platform_device *pdev)
{
struct dwc3_omap_data *pdata = pdev->dev.platform_data;
struct device_node *node = pdev->dev.of_node;
struct platform_device *dwc3;
struct dwc3_omap *omap;
struct resource *res;
struct device *dev = &pdev->dev;
int size;
int ret = -ENOMEM;
int irq;
const u32 *utmi_mode;
u32 reg;
void __iomem *base;
void *context;
omap = devm_kzalloc(dev, sizeof(*omap), GFP_KERNEL);
if (!omap) {
dev_err(dev, "not enough memory\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, omap);
irq = platform_get_irq(pdev, 1);
if (irq < 0) {
dev_err(dev, "missing IRQ resource\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res) {
dev_err(dev, "missing memory base resource\n");
return -EINVAL;
}
base = devm_ioremap_nocache(dev, res->start, resource_size(res));
if (!base) {
dev_err(dev, "ioremap failed\n");
return -ENOMEM;
}
ret = dwc3_omap_register_phys(omap);
if (ret) {
dev_err(dev, "couldn't register PHYs\n");
return ret;
}
dwc3 = platform_device_alloc("dwc3", PLATFORM_DEVID_AUTO);
if (!dwc3) {
dev_err(dev, "couldn't allocate dwc3 device\n");
return -ENOMEM;
}
context = devm_kzalloc(dev, resource_size(res), GFP_KERNEL);
if (!context) {
dev_err(dev, "couldn't allocate dwc3 context memory\n");
goto err2;
}
spin_lock_init(&omap->lock);
dma_set_coherent_mask(&dwc3->dev, dev->coherent_dma_mask);
dwc3->dev.parent = dev;
dwc3->dev.dma_mask = dev->dma_mask;
dwc3->dev.dma_parms = dev->dma_parms;
omap->resource_size = resource_size(res);
omap->context = context;
omap->dev = dev;
omap->irq = irq;
omap->base = base;
omap->dwc3 = dwc3;
reg = dwc3_omap_readl(omap->base, USBOTGSS_UTMI_OTG_STATUS);
utmi_mode = of_get_property(node, "utmi-mode", &size);
if (utmi_mode && size == sizeof(*utmi_mode)) {
reg |= *utmi_mode;
} else {
if (!pdata) {
dev_dbg(dev, "missing platform data\n");
} else {
switch (pdata->utmi_mode) {
case DWC3_OMAP_UTMI_MODE_SW:
reg |= USBOTGSS_UTMI_OTG_STATUS_SW_MODE;
break;
case DWC3_OMAP_UTMI_MODE_HW:
reg &= ~USBOTGSS_UTMI_OTG_STATUS_SW_MODE;
break;
default:
dev_dbg(dev, "UNKNOWN utmi mode %d\n",
pdata->utmi_mode);
}
}
}
dwc3_omap_writel(omap->base, USBOTGSS_UTMI_OTG_STATUS, reg);
reg = dwc3_omap_readl(omap->base, USBOTGSS_SYSCONFIG);
omap->dma_status = !!(reg & USBOTGSS_SYSCONFIG_DMADISABLE);
reg &= ~(USBOTGSS_STANDBYMODE_MASK
| USBOTGSS_IDLEMODE_MASK);
reg |= (USBOTGSS_SYSCONFIG_STANDBYMODE(USBOTGSS_STANDBYMODE_NO_STANDBY)
| USBOTGSS_SYSCONFIG_IDLEMODE(USBOTGSS_IDLEMODE_NO_IDLE));
dwc3_omap_writel(omap->base, USBOTGSS_SYSCONFIG, reg);
ret = devm_request_irq(dev, omap->irq, dwc3_omap_interrupt, 0,
"dwc3-omap", omap);
if (ret) {
dev_err(dev, "failed to request IRQ #%d --> %d\n",
omap->irq, ret);
goto err2;
}
reg = USBOTGSS_IRQO_COREIRQ_ST;
dwc3_omap_writel(omap->base, USBOTGSS_IRQENABLE_SET_0, reg);
reg = (USBOTGSS_IRQ1_OEVT |
USBOTGSS_IRQ1_DRVVBUS_RISE |
USBOTGSS_IRQ1_CHRGVBUS_RISE |
USBOTGSS_IRQ1_DISCHRGVBUS_RISE |
USBOTGSS_IRQ1_IDPULLUP_RISE |
USBOTGSS_IRQ1_DRVVBUS_FALL |
USBOTGSS_IRQ1_CHRGVBUS_FALL |
USBOTGSS_IRQ1_DISCHRGVBUS_FALL |
USBOTGSS_IRQ1_IDPULLUP_FALL);
dwc3_omap_writel(omap->base, USBOTGSS_IRQENABLE_SET_1, reg);
ret = platform_device_add_resources(dwc3, pdev->resource,
pdev->num_resources);
if (ret) {
dev_err(dev, "couldn't add resources to dwc3 device\n");
goto err2;
}
ret = platform_device_add(dwc3);
if (ret) {
dev_err(dev, "failed to register dwc3 device\n");
goto err2;
}
return 0;
err2:
platform_device_put(dwc3);
return ret;
}
static int dwc3_omap_remove(struct platform_device *pdev)
{
struct dwc3_omap *omap = platform_get_drvdata(pdev);
platform_device_unregister(omap->dwc3);
platform_device_unregister(omap->usb2_phy);
platform_device_unregister(omap->usb3_phy);
return 0;
}
