static inline u32 dwc3_omap_readl(void __iomem *base, u32 offset)
{
return readl(base + offset);
}
static inline void dwc3_omap_writel(void __iomem *base, u32 offset, u32 value)
{
writel(value, base + offset);
}
static u32 dwc3_omap_read_utmi_status(struct dwc3_omap *omap)
{
return dwc3_omap_readl(omap->base, USBOTGSS_UTMI_OTG_STATUS +
omap->utmi_otg_offset);
}
static void dwc3_omap_write_utmi_status(struct dwc3_omap *omap, u32 value)
{
dwc3_omap_writel(omap->base, USBOTGSS_UTMI_OTG_STATUS +
omap->utmi_otg_offset, value);
}
static u32 dwc3_omap_read_irq0_status(struct dwc3_omap *omap)
{
return dwc3_omap_readl(omap->base, USBOTGSS_IRQSTATUS_0 -
omap->irq0_offset);
}
static void dwc3_omap_write_irq0_status(struct dwc3_omap *omap, u32 value)
{
dwc3_omap_writel(omap->base, USBOTGSS_IRQSTATUS_0 -
omap->irq0_offset, value);
}
static u32 dwc3_omap_read_irqmisc_status(struct dwc3_omap *omap)
{
return dwc3_omap_readl(omap->base, USBOTGSS_IRQSTATUS_MISC +
omap->irqmisc_offset);
}
static void dwc3_omap_write_irqmisc_status(struct dwc3_omap *omap, u32 value)
{
dwc3_omap_writel(omap->base, USBOTGSS_IRQSTATUS_MISC +
omap->irqmisc_offset, value);
}
static void dwc3_omap_write_irqmisc_set(struct dwc3_omap *omap, u32 value)
{
dwc3_omap_writel(omap->base, USBOTGSS_IRQENABLE_SET_MISC +
omap->irqmisc_offset, value);
}
static void dwc3_omap_write_irq0_set(struct dwc3_omap *omap, u32 value)
{
dwc3_omap_writel(omap->base, USBOTGSS_IRQENABLE_SET_0 -
omap->irq0_offset, value);
}
static void dwc3_omap_set_mailbox(struct dwc3_omap *omap,
enum omap_dwc3_vbus_id_status status)
{
int ret;
u32 val;
switch (status) {
case OMAP_DWC3_ID_GROUND:
dev_dbg(omap->dev, "ID GND\n");
if (omap->vbus_reg) {
ret = regulator_enable(omap->vbus_reg);
if (ret) {
dev_dbg(omap->dev, "regulator enable failed\n");
return;
}
}
val = dwc3_omap_read_utmi_status(omap);
val &= ~(USBOTGSS_UTMI_OTG_STATUS_IDDIG
| USBOTGSS_UTMI_OTG_STATUS_VBUSVALID
| USBOTGSS_UTMI_OTG_STATUS_SESSEND);
val |= USBOTGSS_UTMI_OTG_STATUS_SESSVALID
| USBOTGSS_UTMI_OTG_STATUS_POWERPRESENT;
dwc3_omap_write_utmi_status(omap, val);
break;
case OMAP_DWC3_VBUS_VALID:
dev_dbg(omap->dev, "VBUS Connect\n");
val = dwc3_omap_read_utmi_status(omap);
val &= ~USBOTGSS_UTMI_OTG_STATUS_SESSEND;
val |= USBOTGSS_UTMI_OTG_STATUS_IDDIG
| USBOTGSS_UTMI_OTG_STATUS_VBUSVALID
| USBOTGSS_UTMI_OTG_STATUS_SESSVALID
| USBOTGSS_UTMI_OTG_STATUS_POWERPRESENT;
dwc3_omap_write_utmi_status(omap, val);
break;
case OMAP_DWC3_ID_FLOAT:
if (omap->vbus_reg)
regulator_disable(omap->vbus_reg);
case OMAP_DWC3_VBUS_OFF:
dev_dbg(omap->dev, "VBUS Disconnect\n");
val = dwc3_omap_read_utmi_status(omap);
val &= ~(USBOTGSS_UTMI_OTG_STATUS_SESSVALID
| USBOTGSS_UTMI_OTG_STATUS_VBUSVALID
| USBOTGSS_UTMI_OTG_STATUS_POWERPRESENT);
val |= USBOTGSS_UTMI_OTG_STATUS_SESSEND
| USBOTGSS_UTMI_OTG_STATUS_IDDIG;
dwc3_omap_write_utmi_status(omap, val);
break;
default:
dev_dbg(omap->dev, "invalid state\n");
}
}
static irqreturn_t dwc3_omap_interrupt(int irq, void *_omap)
{
struct dwc3_omap *omap = _omap;
u32 reg;
spin_lock(&omap->lock);
reg = dwc3_omap_read_irqmisc_status(omap);
if (reg & USBOTGSS_IRQMISC_DMADISABLECLR) {
dev_dbg(omap->dev, "DMA Disable was Cleared\n");
omap->dma_status = false;
}
if (reg & USBOTGSS_IRQMISC_OEVT)
dev_dbg(omap->dev, "OTG Event\n");
if (reg & USBOTGSS_IRQMISC_DRVVBUS_RISE)
dev_dbg(omap->dev, "DRVVBUS Rise\n");
if (reg & USBOTGSS_IRQMISC_CHRGVBUS_RISE)
dev_dbg(omap->dev, "CHRGVBUS Rise\n");
if (reg & USBOTGSS_IRQMISC_DISCHRGVBUS_RISE)
dev_dbg(omap->dev, "DISCHRGVBUS Rise\n");
if (reg & USBOTGSS_IRQMISC_IDPULLUP_RISE)
dev_dbg(omap->dev, "IDPULLUP Rise\n");
if (reg & USBOTGSS_IRQMISC_DRVVBUS_FALL)
dev_dbg(omap->dev, "DRVVBUS Fall\n");
if (reg & USBOTGSS_IRQMISC_CHRGVBUS_FALL)
dev_dbg(omap->dev, "CHRGVBUS Fall\n");
if (reg & USBOTGSS_IRQMISC_DISCHRGVBUS_FALL)
dev_dbg(omap->dev, "DISCHRGVBUS Fall\n");
if (reg & USBOTGSS_IRQMISC_IDPULLUP_FALL)
dev_dbg(omap->dev, "IDPULLUP Fall\n");
dwc3_omap_write_irqmisc_status(omap, reg);
reg = dwc3_omap_read_irq0_status(omap);
dwc3_omap_write_irq0_status(omap, reg);
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
dwc3_omap_write_irq0_set(omap, reg);
reg = (USBOTGSS_IRQMISC_OEVT |
USBOTGSS_IRQMISC_DRVVBUS_RISE |
USBOTGSS_IRQMISC_CHRGVBUS_RISE |
USBOTGSS_IRQMISC_DISCHRGVBUS_RISE |
USBOTGSS_IRQMISC_IDPULLUP_RISE |
USBOTGSS_IRQMISC_DRVVBUS_FALL |
USBOTGSS_IRQMISC_CHRGVBUS_FALL |
USBOTGSS_IRQMISC_DISCHRGVBUS_FALL |
USBOTGSS_IRQMISC_IDPULLUP_FALL);
dwc3_omap_write_irqmisc_set(omap, reg);
}
static void dwc3_omap_disable_irqs(struct dwc3_omap *omap)
{
dwc3_omap_write_irqmisc_set(omap, 0x00);
dwc3_omap_write_irq0_set(omap, 0x00);
}
static int dwc3_omap_id_notifier(struct notifier_block *nb,
unsigned long event, void *ptr)
{
struct dwc3_omap *omap = container_of(nb, struct dwc3_omap, id_nb);
if (event)
dwc3_omap_set_mailbox(omap, OMAP_DWC3_ID_GROUND);
else
dwc3_omap_set_mailbox(omap, OMAP_DWC3_ID_FLOAT);
return NOTIFY_DONE;
}
static int dwc3_omap_vbus_notifier(struct notifier_block *nb,
unsigned long event, void *ptr)
{
struct dwc3_omap *omap = container_of(nb, struct dwc3_omap, vbus_nb);
if (event)
dwc3_omap_set_mailbox(omap, OMAP_DWC3_VBUS_VALID);
else
dwc3_omap_set_mailbox(omap, OMAP_DWC3_VBUS_OFF);
return NOTIFY_DONE;
}
static int dwc3_omap_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct dwc3_omap *omap;
struct resource *res;
struct device *dev = &pdev->dev;
struct extcon_dev *edev;
struct regulator *vbus_reg = NULL;
int ret = -ENOMEM;
int irq;
int utmi_mode = 0;
int x_major;
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
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
if (of_property_read_bool(node, "vbus-supply")) {
vbus_reg = devm_regulator_get(dev, "vbus");
if (IS_ERR(vbus_reg)) {
dev_err(dev, "vbus init failed\n");
return PTR_ERR(vbus_reg);
}
}
spin_lock_init(&omap->lock);
omap->dev = dev;
omap->irq = irq;
omap->base = base;
omap->vbus_reg = vbus_reg;
dev->dma_mask = &dwc3_omap_dma_mask;
pm_runtime_enable(dev);
ret = pm_runtime_get_sync(dev);
if (ret < 0) {
dev_err(dev, "get_sync failed with err %d\n", ret);
goto err0;
}
reg = dwc3_omap_readl(omap->base, USBOTGSS_REVISION);
omap->revision = reg;
x_major = USBOTGSS_REVISION_XMAJOR(reg);
switch (x_major) {
case USBOTGSS_REVISION_XMAJOR1:
case USBOTGSS_REVISION_XMAJOR2:
omap->irq_eoi_offset = 0;
omap->irq0_offset = 0;
omap->irqmisc_offset = 0;
omap->utmi_otg_offset = 0;
omap->debug_offset = 0;
break;
default:
omap->irq_eoi_offset = USBOTGSS_EOI_OFFSET;
omap->irq0_offset = USBOTGSS_IRQ0_OFFSET;
omap->irqmisc_offset = USBOTGSS_IRQMISC_OFFSET;
omap->utmi_otg_offset = USBOTGSS_UTMI_OTG_OFFSET;
omap->debug_offset = USBOTGSS_DEBUG_OFFSET;
break;
}
if (of_device_is_compatible(node, "ti,am437x-dwc3")) {
omap->irq_eoi_offset = USBOTGSS_EOI_OFFSET;
omap->irq0_offset = USBOTGSS_IRQ0_OFFSET;
omap->irqmisc_offset = USBOTGSS_IRQMISC_OFFSET;
omap->utmi_otg_offset = USBOTGSS_UTMI_OTG_OFFSET;
omap->debug_offset = USBOTGSS_DEBUG_OFFSET;
}
reg = dwc3_omap_read_utmi_status(omap);
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
dwc3_omap_write_utmi_status(omap, reg);
reg = dwc3_omap_readl(omap->base, USBOTGSS_SYSCONFIG);
omap->dma_status = !!(reg & USBOTGSS_SYSCONFIG_DMADISABLE);
ret = devm_request_irq(dev, omap->irq, dwc3_omap_interrupt, 0,
"dwc3-omap", omap);
if (ret) {
dev_err(dev, "failed to request IRQ #%d --> %d\n",
omap->irq, ret);
goto err1;
}
dwc3_omap_enable_irqs(omap);
if (of_property_read_bool(node, "extcon")) {
edev = of_extcon_get_extcon_dev(dev, 0);
if (IS_ERR(edev)) {
dev_vdbg(dev, "couldn't get extcon device\n");
ret = PTR_ERR(edev);
goto err2;
}
omap->vbus_nb.notifier_call = dwc3_omap_vbus_notifier;
ret = extcon_register_interest(&omap->extcon_vbus_dev,
edev->name, "USB", &omap->vbus_nb);
if (ret < 0)
dev_vdbg(dev, "failed to register notifier for USB\n");
omap->id_nb.notifier_call = dwc3_omap_id_notifier;
ret = extcon_register_interest(&omap->extcon_id_dev, edev->name,
"USB-HOST", &omap->id_nb);
if (ret < 0)
dev_vdbg(dev,
"failed to register notifier for USB-HOST\n");
if (extcon_get_cable_state(edev, "USB") == true)
dwc3_omap_set_mailbox(omap, OMAP_DWC3_VBUS_VALID);
if (extcon_get_cable_state(edev, "USB-HOST") == true)
dwc3_omap_set_mailbox(omap, OMAP_DWC3_ID_GROUND);
}
ret = of_platform_populate(node, NULL, NULL, dev);
if (ret) {
dev_err(&pdev->dev, "failed to create dwc3 core\n");
goto err3;
}
return 0;
err3:
if (omap->extcon_vbus_dev.edev)
extcon_unregister_interest(&omap->extcon_vbus_dev);
if (omap->extcon_id_dev.edev)
extcon_unregister_interest(&omap->extcon_id_dev);
err2:
dwc3_omap_disable_irqs(omap);
err1:
pm_runtime_put_sync(dev);
err0:
pm_runtime_disable(dev);
return ret;
}
static int dwc3_omap_remove(struct platform_device *pdev)
{
struct dwc3_omap *omap = platform_get_drvdata(pdev);
if (omap->extcon_vbus_dev.edev)
extcon_unregister_interest(&omap->extcon_vbus_dev);
if (omap->extcon_id_dev.edev)
extcon_unregister_interest(&omap->extcon_id_dev);
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
omap->utmi_otg_status = dwc3_omap_read_utmi_status(omap);
return 0;
}
static int dwc3_omap_resume(struct device *dev)
{
struct dwc3_omap *omap = dev_get_drvdata(dev);
dwc3_omap_write_utmi_status(omap, omap->utmi_otg_status);
pm_runtime_disable(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
return 0;
}
