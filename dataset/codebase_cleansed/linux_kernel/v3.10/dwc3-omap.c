static inline u32 dwc3_omap_readl(void __iomem *base, u32 offset)
{
return readl(base + offset);
}
static inline void dwc3_omap_writel(void __iomem *base, u32 offset, u32 value)
{
writel(value, base + offset);
}
int dwc3_omap_mailbox(enum omap_dwc3_vbus_id_status status)
{
u32 val;
struct dwc3_omap *omap = _omap;
if (!omap)
return -EPROBE_DEFER;
switch (status) {
case OMAP_DWC3_ID_GROUND:
dev_dbg(omap->dev, "ID GND\n");
val = dwc3_omap_readl(omap->base, USBOTGSS_UTMI_OTG_STATUS);
val &= ~(USBOTGSS_UTMI_OTG_STATUS_IDDIG
| USBOTGSS_UTMI_OTG_STATUS_VBUSVALID
| USBOTGSS_UTMI_OTG_STATUS_SESSEND);
val |= USBOTGSS_UTMI_OTG_STATUS_SESSVALID
| USBOTGSS_UTMI_OTG_STATUS_POWERPRESENT;
dwc3_omap_writel(omap->base, USBOTGSS_UTMI_OTG_STATUS, val);
break;
case OMAP_DWC3_VBUS_VALID:
dev_dbg(omap->dev, "VBUS Connect\n");
val = dwc3_omap_readl(omap->base, USBOTGSS_UTMI_OTG_STATUS);
val &= ~USBOTGSS_UTMI_OTG_STATUS_SESSEND;
val |= USBOTGSS_UTMI_OTG_STATUS_IDDIG
| USBOTGSS_UTMI_OTG_STATUS_VBUSVALID
| USBOTGSS_UTMI_OTG_STATUS_SESSVALID
| USBOTGSS_UTMI_OTG_STATUS_POWERPRESENT;
dwc3_omap_writel(omap->base, USBOTGSS_UTMI_OTG_STATUS, val);
break;
case OMAP_DWC3_ID_FLOAT:
case OMAP_DWC3_VBUS_OFF:
dev_dbg(omap->dev, "VBUS Disconnect\n");
val = dwc3_omap_readl(omap->base, USBOTGSS_UTMI_OTG_STATUS);
val &= ~(USBOTGSS_UTMI_OTG_STATUS_SESSVALID
| USBOTGSS_UTMI_OTG_STATUS_VBUSVALID
| USBOTGSS_UTMI_OTG_STATUS_POWERPRESENT);
val |= USBOTGSS_UTMI_OTG_STATUS_SESSEND
| USBOTGSS_UTMI_OTG_STATUS_IDDIG;
dwc3_omap_writel(omap->base, USBOTGSS_UTMI_OTG_STATUS, val);
break;
default:
dev_dbg(omap->dev, "ID float\n");
}
return 0;
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
static int dwc3_omap_remove_core(struct device *dev, void *c)
{
struct platform_device *pdev = to_platform_device(dev);
platform_device_unregister(pdev);
return 0;
}
static void dwc3_omap_enable_irqs(struct dwc3_omap *omap)
{
u32 reg;
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
}
static void dwc3_omap_disable_irqs(struct dwc3_omap *omap)
{
dwc3_omap_writel(omap->base, USBOTGSS_IRQENABLE_SET_1, 0x00);
dwc3_omap_writel(omap->base, USBOTGSS_IRQENABLE_SET_0, 0x00);
}
static int dwc3_omap_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct dwc3_omap *omap;
struct resource *res;
struct device *dev = &pdev->dev;
int ret = -ENOMEM;
int irq;
int utmi_mode = 0;
u32 reg;
void __iomem *base;
if (!node) {
dev_err(dev, "device node not found\n");
return -EINVAL;
}
omap = devm_kzalloc(dev, sizeof(*omap), GFP_KERNEL);
if (!omap) {
dev_err(dev, "not enough memory\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, omap);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "missing IRQ resource\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "missing memory base resource\n");
return -EINVAL;
}
base = devm_ioremap_nocache(dev, res->start, resource_size(res));
if (!base) {
dev_err(dev, "ioremap failed\n");
return -ENOMEM;
}
spin_lock_init(&omap->lock);
omap->dev = dev;
omap->irq = irq;
omap->base = base;
dev->dma_mask = &dwc3_omap_dma_mask;
_omap = omap;
pm_runtime_enable(dev);
ret = pm_runtime_get_sync(dev);
if (ret < 0) {
dev_err(dev, "get_sync failed with err %d\n", ret);
return ret;
}
reg = dwc3_omap_readl(omap->base, USBOTGSS_UTMI_OTG_STATUS);
of_property_read_u32(node, "utmi-mode", &utmi_mode);
switch (utmi_mode) {
case DWC3_OMAP_UTMI_MODE_SW:
reg |= USBOTGSS_UTMI_OTG_STATUS_SW_MODE;
break;
case DWC3_OMAP_UTMI_MODE_HW:
reg &= ~USBOTGSS_UTMI_OTG_STATUS_SW_MODE;
break;
default:
dev_dbg(dev, "UNKNOWN utmi mode %d\n", utmi_mode);
}
dwc3_omap_writel(omap->base, USBOTGSS_UTMI_OTG_STATUS, reg);
reg = dwc3_omap_readl(omap->base, USBOTGSS_SYSCONFIG);
omap->dma_status = !!(reg & USBOTGSS_SYSCONFIG_DMADISABLE);
ret = devm_request_irq(dev, omap->irq, dwc3_omap_interrupt, 0,
"dwc3-omap", omap);
if (ret) {
dev_err(dev, "failed to request IRQ #%d --> %d\n",
omap->irq, ret);
return ret;
}
dwc3_omap_enable_irqs(omap);
ret = of_platform_populate(node, NULL, NULL, dev);
if (ret) {
dev_err(&pdev->dev, "failed to create dwc3 core\n");
return ret;
}
return 0;
}
static int dwc3_omap_remove(struct platform_device *pdev)
{
struct dwc3_omap *omap = platform_get_drvdata(pdev);
dwc3_omap_disable_irqs(omap);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
device_for_each_child(&pdev->dev, NULL, dwc3_omap_remove_core);
return 0;
}
static int dwc3_omap_prepare(struct device *dev)
{
struct dwc3_omap *omap = dev_get_drvdata(dev);
dwc3_omap_disable_irqs(omap);
return 0;
}
static void dwc3_omap_complete(struct device *dev)
{
struct dwc3_omap *omap = dev_get_drvdata(dev);
dwc3_omap_enable_irqs(omap);
}
static int dwc3_omap_suspend(struct device *dev)
{
struct dwc3_omap *omap = dev_get_drvdata(dev);
omap->utmi_otg_status = dwc3_omap_readl(omap->base,
USBOTGSS_UTMI_OTG_STATUS);
return 0;
}
static int dwc3_omap_resume(struct device *dev)
{
struct dwc3_omap *omap = dev_get_drvdata(dev);
dwc3_omap_writel(omap->base, USBOTGSS_UTMI_OTG_STATUS,
omap->utmi_otg_status);
pm_runtime_disable(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
return 0;
}
