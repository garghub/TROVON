static inline u32 dwc3_omap_readl(void __iomem *base, u32 offset)
{
return readl(base + offset);
}
static inline void dwc3_omap_writel(void __iomem *base, u32 offset, u32 value)
{
writel(value, base + offset);
}
static u32 dwc3_omap_read_utmi_ctrl(struct dwc3_omap *omap)
{
return dwc3_omap_readl(omap->base, USBOTGSS_UTMI_OTG_CTRL +
omap->utmi_otg_offset);
}
static void dwc3_omap_write_utmi_ctrl(struct dwc3_omap *omap, u32 value)
{
dwc3_omap_writel(omap->base, USBOTGSS_UTMI_OTG_CTRL +
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
static void dwc3_omap_write_irqmisc_clr(struct dwc3_omap *omap, u32 value)
{
dwc3_omap_writel(omap->base, USBOTGSS_IRQENABLE_CLR_MISC +
omap->irqmisc_offset, value);
}
static void dwc3_omap_write_irq0_clr(struct dwc3_omap *omap, u32 value)
{
dwc3_omap_writel(omap->base, USBOTGSS_IRQENABLE_CLR_0 -
omap->irq0_offset, value);
}
static void dwc3_omap_set_mailbox(struct dwc3_omap *omap,
enum omap_dwc3_vbus_id_status status)
{
int ret;
u32 val;
switch (status) {
case OMAP_DWC3_ID_GROUND:
if (omap->vbus_reg) {
ret = regulator_enable(omap->vbus_reg);
if (ret) {
dev_err(omap->dev, "regulator enable failed\n");
return;
}
}
val = dwc3_omap_read_utmi_ctrl(omap);
val &= ~(USBOTGSS_UTMI_OTG_CTRL_IDDIG
| USBOTGSS_UTMI_OTG_CTRL_VBUSVALID
| USBOTGSS_UTMI_OTG_CTRL_SESSEND);
val |= USBOTGSS_UTMI_OTG_CTRL_SESSVALID
| USBOTGSS_UTMI_OTG_CTRL_POWERPRESENT;
dwc3_omap_write_utmi_ctrl(omap, val);
break;
case OMAP_DWC3_VBUS_VALID:
val = dwc3_omap_read_utmi_ctrl(omap);
val &= ~USBOTGSS_UTMI_OTG_CTRL_SESSEND;
val |= USBOTGSS_UTMI_OTG_CTRL_IDDIG
| USBOTGSS_UTMI_OTG_CTRL_VBUSVALID
| USBOTGSS_UTMI_OTG_CTRL_SESSVALID
| USBOTGSS_UTMI_OTG_CTRL_POWERPRESENT;
dwc3_omap_write_utmi_ctrl(omap, val);
break;
case OMAP_DWC3_ID_FLOAT:
if (omap->vbus_reg)
regulator_disable(omap->vbus_reg);
case OMAP_DWC3_VBUS_OFF:
val = dwc3_omap_read_utmi_ctrl(omap);
val &= ~(USBOTGSS_UTMI_OTG_CTRL_SESSVALID
| USBOTGSS_UTMI_OTG_CTRL_VBUSVALID
| USBOTGSS_UTMI_OTG_CTRL_POWERPRESENT);
val |= USBOTGSS_UTMI_OTG_CTRL_SESSEND
| USBOTGSS_UTMI_OTG_CTRL_IDDIG;
dwc3_omap_write_utmi_ctrl(omap, val);
break;
default:
dev_WARN(omap->dev, "invalid state\n");
}
}
static irqreturn_t dwc3_omap_interrupt(int irq, void *_omap)
{
struct dwc3_omap *omap = _omap;
u32 reg;
reg = dwc3_omap_read_irqmisc_status(omap);
dwc3_omap_write_irqmisc_status(omap, reg);
reg = dwc3_omap_read_irq0_status(omap);
dwc3_omap_write_irq0_status(omap, reg);
return IRQ_HANDLED;
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
u32 reg;
reg = USBOTGSS_IRQO_COREIRQ_ST;
dwc3_omap_write_irq0_clr(omap, reg);
reg = (USBOTGSS_IRQMISC_OEVT |
USBOTGSS_IRQMISC_DRVVBUS_RISE |
USBOTGSS_IRQMISC_CHRGVBUS_RISE |
USBOTGSS_IRQMISC_DISCHRGVBUS_RISE |
USBOTGSS_IRQMISC_IDPULLUP_RISE |
USBOTGSS_IRQMISC_DRVVBUS_FALL |
USBOTGSS_IRQMISC_CHRGVBUS_FALL |
USBOTGSS_IRQMISC_DISCHRGVBUS_FALL |
USBOTGSS_IRQMISC_IDPULLUP_FALL);
dwc3_omap_write_irqmisc_clr(omap, reg);
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
static void dwc3_omap_map_offset(struct dwc3_omap *omap)
{
struct device_node *node = omap->dev->of_node;
if (of_device_is_compatible(node, "ti,am437x-dwc3")) {
omap->irq_eoi_offset = USBOTGSS_EOI_OFFSET;
omap->irq0_offset = USBOTGSS_IRQ0_OFFSET;
omap->irqmisc_offset = USBOTGSS_IRQMISC_OFFSET;
omap->utmi_otg_offset = USBOTGSS_UTMI_OTG_OFFSET;
omap->debug_offset = USBOTGSS_DEBUG_OFFSET;
}
}
static void dwc3_omap_set_utmi_mode(struct dwc3_omap *omap)
{
u32 reg;
struct device_node *node = omap->dev->of_node;
int utmi_mode = 0;
reg = dwc3_omap_read_utmi_ctrl(omap);
of_property_read_u32(node, "utmi-mode", &utmi_mode);
switch (utmi_mode) {
case DWC3_OMAP_UTMI_MODE_SW:
reg |= USBOTGSS_UTMI_OTG_CTRL_SW_MODE;
break;
case DWC3_OMAP_UTMI_MODE_HW:
reg &= ~USBOTGSS_UTMI_OTG_CTRL_SW_MODE;
break;
default:
dev_WARN(omap->dev, "UNKNOWN utmi mode %d\n", utmi_mode);
}
dwc3_omap_write_utmi_ctrl(omap, reg);
}
static int dwc3_omap_extcon_register(struct dwc3_omap *omap)
{
int ret;
struct device_node *node = omap->dev->of_node;
struct extcon_dev *edev;
if (of_property_read_bool(node, "extcon")) {
edev = extcon_get_edev_by_phandle(omap->dev, 0);
if (IS_ERR(edev)) {
dev_vdbg(omap->dev, "couldn't get extcon device\n");
return -EPROBE_DEFER;
}
omap->vbus_nb.notifier_call = dwc3_omap_vbus_notifier;
ret = extcon_register_notifier(edev, EXTCON_USB,
&omap->vbus_nb);
if (ret < 0)
dev_vdbg(omap->dev, "failed to register notifier for USB\n");
omap->id_nb.notifier_call = dwc3_omap_id_notifier;
ret = extcon_register_notifier(edev, EXTCON_USB_HOST,
&omap->id_nb);
if (ret < 0)
dev_vdbg(omap->dev, "failed to register notifier for USB-HOST\n");
if (extcon_get_cable_state_(edev, EXTCON_USB) == true)
dwc3_omap_set_mailbox(omap, OMAP_DWC3_VBUS_VALID);
if (extcon_get_cable_state_(edev, EXTCON_USB_HOST) == true)
dwc3_omap_set_mailbox(omap, OMAP_DWC3_ID_GROUND);
omap->edev = edev;
}
return 0;
}
static int dwc3_omap_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct dwc3_omap *omap;
struct resource *res;
struct device *dev = &pdev->dev;
struct regulator *vbus_reg = NULL;
int ret;
int irq;
u32 reg;
void __iomem *base;
if (!node) {
dev_err(dev, "device node not found\n");
return -EINVAL;
}
omap = devm_kzalloc(dev, sizeof(*omap), GFP_KERNEL);
if (!omap)
return -ENOMEM;
platform_set_drvdata(pdev, omap);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "missing IRQ resource\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
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
omap->dev = dev;
omap->irq = irq;
omap->base = base;
omap->vbus_reg = vbus_reg;
pm_runtime_enable(dev);
ret = pm_runtime_get_sync(dev);
if (ret < 0) {
dev_err(dev, "get_sync failed with err %d\n", ret);
goto err1;
}
dwc3_omap_map_offset(omap);
dwc3_omap_set_utmi_mode(omap);
reg = dwc3_omap_readl(omap->base, USBOTGSS_SYSCONFIG);
ret = devm_request_irq(dev, omap->irq, dwc3_omap_interrupt, 0,
"dwc3-omap", omap);
if (ret) {
dev_err(dev, "failed to request IRQ #%d --> %d\n",
omap->irq, ret);
goto err1;
}
ret = dwc3_omap_extcon_register(omap);
if (ret < 0)
goto err1;
ret = of_platform_populate(node, NULL, NULL, dev);
if (ret) {
dev_err(&pdev->dev, "failed to create dwc3 core\n");
goto err2;
}
dwc3_omap_enable_irqs(omap);
return 0;
err2:
extcon_unregister_notifier(omap->edev, EXTCON_USB, &omap->vbus_nb);
extcon_unregister_notifier(omap->edev, EXTCON_USB_HOST, &omap->id_nb);
err1:
pm_runtime_put_sync(dev);
pm_runtime_disable(dev);
return ret;
}
static int dwc3_omap_remove(struct platform_device *pdev)
{
struct dwc3_omap *omap = platform_get_drvdata(pdev);
extcon_unregister_notifier(omap->edev, EXTCON_USB, &omap->vbus_nb);
extcon_unregister_notifier(omap->edev, EXTCON_USB_HOST, &omap->id_nb);
dwc3_omap_disable_irqs(omap);
of_platform_depopulate(omap->dev);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int dwc3_omap_suspend(struct device *dev)
{
struct dwc3_omap *omap = dev_get_drvdata(dev);
omap->utmi_otg_ctrl = dwc3_omap_read_utmi_ctrl(omap);
dwc3_omap_disable_irqs(omap);
return 0;
}
static int dwc3_omap_resume(struct device *dev)
{
struct dwc3_omap *omap = dev_get_drvdata(dev);
dwc3_omap_write_utmi_ctrl(omap, omap->utmi_otg_ctrl);
dwc3_omap_enable_irqs(omap);
pm_runtime_disable(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
return 0;
}
