static irqreturn_t dwc3_omap_interrupt(int irq, void *_omap)
{
struct dwc3_omap *omap = _omap;
u32 reg;
spin_lock(&omap->lock);
reg = dwc3_readl(omap->base, USBOTGSS_IRQSTATUS_1);
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
dwc3_writel(omap->base, USBOTGSS_IRQSTATUS_1, reg);
reg = dwc3_readl(omap->base, USBOTGSS_IRQSTATUS_0);
dwc3_writel(omap->base, USBOTGSS_IRQSTATUS_0, reg);
spin_unlock(&omap->lock);
return IRQ_HANDLED;
}
static int __devinit dwc3_omap_probe(struct platform_device *pdev)
{
struct dwc3_omap_data *pdata = pdev->dev.platform_data;
struct platform_device *dwc3;
struct dwc3_omap *omap;
struct resource *res;
int ret = -ENOMEM;
int irq;
u32 reg;
void __iomem *base;
void *context;
omap = kzalloc(sizeof(*omap), GFP_KERNEL);
if (!omap) {
dev_err(&pdev->dev, "not enough memory\n");
goto err0;
}
platform_set_drvdata(pdev, omap);
irq = platform_get_irq(pdev, 1);
if (irq < 0) {
dev_err(&pdev->dev, "missing IRQ resource\n");
ret = -EINVAL;
goto err1;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res) {
dev_err(&pdev->dev, "missing memory base resource\n");
ret = -EINVAL;
goto err1;
}
base = ioremap_nocache(res->start, resource_size(res));
if (!base) {
dev_err(&pdev->dev, "ioremap failed\n");
goto err1;
}
dwc3 = platform_device_alloc("dwc3-omap", -1);
if (!dwc3) {
dev_err(&pdev->dev, "couldn't allocate dwc3 device\n");
goto err2;
}
context = kzalloc(resource_size(res), GFP_KERNEL);
if (!context) {
dev_err(&pdev->dev, "couldn't allocate dwc3 context memory\n");
goto err3;
}
spin_lock_init(&omap->lock);
dma_set_coherent_mask(&dwc3->dev, pdev->dev.coherent_dma_mask);
dwc3->dev.parent = &pdev->dev;
dwc3->dev.dma_mask = pdev->dev.dma_mask;
dwc3->dev.dma_parms = pdev->dev.dma_parms;
omap->resource_size = resource_size(res);
omap->context = context;
omap->dev = &pdev->dev;
omap->irq = irq;
omap->base = base;
omap->dwc3 = dwc3;
reg = dwc3_readl(omap->base, USBOTGSS_UTMI_OTG_STATUS);
if (!pdata) {
dev_dbg(&pdev->dev, "missing platform data\n");
} else {
switch (pdata->utmi_mode) {
case DWC3_OMAP_UTMI_MODE_SW:
reg |= USBOTGSS_UTMI_OTG_STATUS_SW_MODE;
break;
case DWC3_OMAP_UTMI_MODE_HW:
reg &= ~USBOTGSS_UTMI_OTG_STATUS_SW_MODE;
break;
default:
dev_dbg(&pdev->dev, "UNKNOWN utmi mode %d\n",
pdata->utmi_mode);
}
}
dwc3_writel(omap->base, USBOTGSS_UTMI_OTG_STATUS, reg);
reg = dwc3_readl(omap->base, USBOTGSS_SYSCONFIG);
omap->dma_status = !!(reg & USBOTGSS_SYSCONFIG_DMADISABLE);
reg &= ~(USBOTGSS_STANDBYMODE_MASK
| USBOTGSS_IDLEMODE_MASK);
reg |= (USBOTGSS_SYSCONFIG_STANDBYMODE(USBOTGSS_STANDBYMODE_NO_STANDBY)
| USBOTGSS_SYSCONFIG_IDLEMODE(USBOTGSS_IDLEMODE_NO_IDLE));
dwc3_writel(omap->base, USBOTGSS_SYSCONFIG, reg);
ret = request_irq(omap->irq, dwc3_omap_interrupt, 0,
"dwc3-omap", omap);
if (ret) {
dev_err(&pdev->dev, "failed to request IRQ #%d --> %d\n",
omap->irq, ret);
goto err4;
}
reg = USBOTGSS_IRQO_COREIRQ_ST;
dwc3_writel(omap->base, USBOTGSS_IRQENABLE_SET_0, reg);
reg = (USBOTGSS_IRQ1_OEVT |
USBOTGSS_IRQ1_DRVVBUS_RISE |
USBOTGSS_IRQ1_CHRGVBUS_RISE |
USBOTGSS_IRQ1_DISCHRGVBUS_RISE |
USBOTGSS_IRQ1_IDPULLUP_RISE |
USBOTGSS_IRQ1_DRVVBUS_FALL |
USBOTGSS_IRQ1_CHRGVBUS_FALL |
USBOTGSS_IRQ1_DISCHRGVBUS_FALL |
USBOTGSS_IRQ1_IDPULLUP_FALL);
dwc3_writel(omap->base, USBOTGSS_IRQENABLE_SET_1, reg);
ret = platform_device_add_resources(dwc3, pdev->resource,
pdev->num_resources);
if (ret) {
dev_err(&pdev->dev, "couldn't add resources to dwc3 device\n");
goto err5;
}
ret = platform_device_add(dwc3);
if (ret) {
dev_err(&pdev->dev, "failed to register dwc3 device\n");
goto err5;
}
return 0;
err5:
free_irq(omap->irq, omap);
err4:
kfree(omap->context);
err3:
platform_device_put(dwc3);
err2:
iounmap(base);
err1:
kfree(omap);
err0:
return ret;
}
static int __devexit dwc3_omap_remove(struct platform_device *pdev)
{
struct dwc3_omap *omap = platform_get_drvdata(pdev);
platform_device_unregister(omap->dwc3);
free_irq(omap->irq, omap);
iounmap(omap->base);
kfree(omap->context);
kfree(omap);
return 0;
}
static int __devinit dwc3_omap_init(void)
{
return platform_driver_register(&dwc3_omap_driver);
}
static void __exit dwc3_omap_exit(void)
{
platform_driver_unregister(&dwc3_omap_driver);
}
