static inline u8 dsps_readb(const void __iomem *addr, unsigned offset)
{ return __raw_readb(addr + offset); }
static inline u32 dsps_readl(const void __iomem *addr, unsigned offset)
{ return __raw_readl(addr + offset); }
static inline void dsps_writeb(void __iomem *addr, unsigned offset, u8 data)
{ __raw_writeb(data, addr + offset); }
static inline void dsps_writel(void __iomem *addr, unsigned offset, u32 data)
{ __raw_writel(data, addr + offset); }
static void musb_dsps_phy_control(struct dsps_glue *glue, u8 id, u8 on)
{
u32 usbphycfg;
usbphycfg = readl(glue->usb_ctrl[id]);
if (on) {
usbphycfg &= ~(USBPHY_CM_PWRDN | USBPHY_OTG_PWRDN);
usbphycfg |= USBPHY_OTGVDET_EN | USBPHY_OTGSESSEND_EN;
} else {
usbphycfg |= USBPHY_CM_PWRDN | USBPHY_OTG_PWRDN;
}
writel(usbphycfg, glue->usb_ctrl[id]);
}
static void dsps_musb_enable(struct musb *musb)
{
struct device *dev = musb->controller;
struct platform_device *pdev = to_platform_device(dev->parent);
struct dsps_glue *glue = platform_get_drvdata(pdev);
const struct dsps_musb_wrapper *wrp = glue->wrp;
void __iomem *reg_base = musb->ctrl_base;
u32 epmask, coremask;
epmask = ((musb->epmask & wrp->txep_mask) << wrp->txep_shift) |
((musb->epmask & wrp->rxep_mask) << wrp->rxep_shift);
coremask = (wrp->usb_bitmap & ~MUSB_INTR_SOF);
dsps_writel(reg_base, wrp->epintr_set, epmask);
dsps_writel(reg_base, wrp->coreintr_set, coremask);
dsps_writel(reg_base, wrp->coreintr_set,
(1 << wrp->drvvbus) << wrp->usb_shift);
}
static void dsps_musb_disable(struct musb *musb)
{
struct device *dev = musb->controller;
struct platform_device *pdev = to_platform_device(dev->parent);
struct dsps_glue *glue = platform_get_drvdata(pdev);
const struct dsps_musb_wrapper *wrp = glue->wrp;
void __iomem *reg_base = musb->ctrl_base;
dsps_writel(reg_base, wrp->coreintr_clear, wrp->usb_bitmap);
dsps_writel(reg_base, wrp->epintr_clear,
wrp->txep_bitmap | wrp->rxep_bitmap);
dsps_writeb(musb->mregs, MUSB_DEVCTL, 0);
dsps_writel(reg_base, wrp->eoi, 0);
}
static void otg_timer(unsigned long _musb)
{
struct musb *musb = (void *)_musb;
void __iomem *mregs = musb->mregs;
struct device *dev = musb->controller;
struct platform_device *pdev = to_platform_device(dev);
struct dsps_glue *glue = dev_get_drvdata(dev->parent);
const struct dsps_musb_wrapper *wrp = glue->wrp;
u8 devctl;
unsigned long flags;
devctl = dsps_readb(mregs, MUSB_DEVCTL);
dev_dbg(musb->controller, "Poll devctl %02x (%s)\n", devctl,
usb_otg_state_string(musb->xceiv->state));
spin_lock_irqsave(&musb->lock, flags);
switch (musb->xceiv->state) {
case OTG_STATE_A_WAIT_BCON:
devctl &= ~MUSB_DEVCTL_SESSION;
dsps_writeb(musb->mregs, MUSB_DEVCTL, devctl);
devctl = dsps_readb(musb->mregs, MUSB_DEVCTL);
if (devctl & MUSB_DEVCTL_BDEVICE) {
musb->xceiv->state = OTG_STATE_B_IDLE;
MUSB_DEV_MODE(musb);
} else {
musb->xceiv->state = OTG_STATE_A_IDLE;
MUSB_HST_MODE(musb);
}
break;
case OTG_STATE_A_WAIT_VFALL:
musb->xceiv->state = OTG_STATE_A_WAIT_VRISE;
dsps_writel(musb->ctrl_base, wrp->coreintr_set,
MUSB_INTR_VBUSERROR << wrp->usb_shift);
break;
case OTG_STATE_B_IDLE:
devctl = dsps_readb(mregs, MUSB_DEVCTL);
if (devctl & MUSB_DEVCTL_BDEVICE)
mod_timer(&glue->timer[pdev->id],
jiffies + wrp->poll_seconds * HZ);
else
musb->xceiv->state = OTG_STATE_A_IDLE;
break;
default:
break;
}
spin_unlock_irqrestore(&musb->lock, flags);
}
static void dsps_musb_try_idle(struct musb *musb, unsigned long timeout)
{
struct device *dev = musb->controller;
struct platform_device *pdev = to_platform_device(dev);
struct dsps_glue *glue = dev_get_drvdata(dev->parent);
if (timeout == 0)
timeout = jiffies + msecs_to_jiffies(3);
if (musb->is_active || (musb->a_wait_bcon == 0 &&
musb->xceiv->state == OTG_STATE_A_WAIT_BCON)) {
dev_dbg(musb->controller, "%s active, deleting timer\n",
usb_otg_state_string(musb->xceiv->state));
del_timer(&glue->timer[pdev->id]);
glue->last_timer[pdev->id] = jiffies;
return;
}
if (time_after(glue->last_timer[pdev->id], timeout) &&
timer_pending(&glue->timer[pdev->id])) {
dev_dbg(musb->controller,
"Longer idle timer already pending, ignoring...\n");
return;
}
glue->last_timer[pdev->id] = timeout;
dev_dbg(musb->controller, "%s inactive, starting idle timer for %u ms\n",
usb_otg_state_string(musb->xceiv->state),
jiffies_to_msecs(timeout - jiffies));
mod_timer(&glue->timer[pdev->id], timeout);
}
static irqreturn_t dsps_interrupt(int irq, void *hci)
{
struct musb *musb = hci;
void __iomem *reg_base = musb->ctrl_base;
struct device *dev = musb->controller;
struct platform_device *pdev = to_platform_device(dev);
struct dsps_glue *glue = dev_get_drvdata(dev->parent);
const struct dsps_musb_wrapper *wrp = glue->wrp;
unsigned long flags;
irqreturn_t ret = IRQ_NONE;
u32 epintr, usbintr;
spin_lock_irqsave(&musb->lock, flags);
epintr = dsps_readl(reg_base, wrp->epintr_status);
musb->int_rx = (epintr & wrp->rxep_bitmap) >> wrp->rxep_shift;
musb->int_tx = (epintr & wrp->txep_bitmap) >> wrp->txep_shift;
if (epintr)
dsps_writel(reg_base, wrp->epintr_status, epintr);
usbintr = dsps_readl(reg_base, wrp->coreintr_status);
if (!usbintr && !epintr)
goto eoi;
musb->int_usb = (usbintr & wrp->usb_bitmap) >> wrp->usb_shift;
if (usbintr)
dsps_writel(reg_base, wrp->coreintr_status, usbintr);
dev_dbg(musb->controller, "usbintr (%x) epintr(%x)\n",
usbintr, epintr);
if (is_host_active(musb) && usbintr & MUSB_INTR_BABBLE)
pr_info("CAUTION: musb: Babble Interrupt Occurred\n");
if (usbintr & ((1 << wrp->drvvbus) << wrp->usb_shift)) {
int drvvbus = dsps_readl(reg_base, wrp->status);
void __iomem *mregs = musb->mregs;
u8 devctl = dsps_readb(mregs, MUSB_DEVCTL);
int err;
err = musb->int_usb & MUSB_INTR_VBUSERROR;
if (err) {
musb->int_usb &= ~MUSB_INTR_VBUSERROR;
musb->xceiv->state = OTG_STATE_A_WAIT_VFALL;
mod_timer(&glue->timer[pdev->id],
jiffies + wrp->poll_seconds * HZ);
WARNING("VBUS error workaround (delay coming)\n");
} else if (drvvbus) {
musb->is_active = 1;
MUSB_HST_MODE(musb);
musb->xceiv->otg->default_a = 1;
musb->xceiv->state = OTG_STATE_A_WAIT_VRISE;
del_timer(&glue->timer[pdev->id]);
} else {
musb->is_active = 0;
MUSB_DEV_MODE(musb);
musb->xceiv->otg->default_a = 0;
musb->xceiv->state = OTG_STATE_B_IDLE;
}
dev_dbg(musb->controller, "VBUS %s (%s)%s, devctl %02x\n",
drvvbus ? "on" : "off",
usb_otg_state_string(musb->xceiv->state),
err ? " ERROR" : "",
devctl);
ret = IRQ_HANDLED;
}
if (musb->int_tx || musb->int_rx || musb->int_usb)
ret |= musb_interrupt(musb);
eoi:
if (ret == IRQ_HANDLED || epintr || usbintr)
dsps_writel(reg_base, wrp->eoi, 1);
if (musb->xceiv->state == OTG_STATE_B_IDLE)
mod_timer(&glue->timer[pdev->id],
jiffies + wrp->poll_seconds * HZ);
spin_unlock_irqrestore(&musb->lock, flags);
return ret;
}
static int dsps_musb_init(struct musb *musb)
{
struct device *dev = musb->controller;
struct platform_device *pdev = to_platform_device(dev);
struct dsps_glue *glue = dev_get_drvdata(dev->parent);
const struct dsps_musb_wrapper *wrp = glue->wrp;
void __iomem *reg_base = musb->ctrl_base;
u32 rev, val;
int status;
musb->mregs += wrp->musb_core_offset;
usb_nop_xceiv_register();
musb->xceiv = usb_get_phy(USB_PHY_TYPE_USB2);
if (IS_ERR_OR_NULL(musb->xceiv))
return -EPROBE_DEFER;
rev = dsps_readl(reg_base, wrp->revision);
if (!rev) {
status = -ENODEV;
goto err0;
}
setup_timer(&glue->timer[pdev->id], otg_timer, (unsigned long) musb);
dsps_writel(reg_base, wrp->control, (1 << wrp->reset));
musb_dsps_phy_control(glue, pdev->id, 1);
musb->isr = dsps_interrupt;
val = dsps_readl(reg_base, wrp->phy_utmi);
val &= ~(1 << wrp->otg_disable);
dsps_writel(musb->ctrl_base, wrp->phy_utmi, val);
dsps_writel(reg_base, wrp->eoi, 0);
return 0;
err0:
usb_put_phy(musb->xceiv);
usb_nop_xceiv_unregister();
return status;
}
static int dsps_musb_exit(struct musb *musb)
{
struct device *dev = musb->controller;
struct platform_device *pdev = to_platform_device(dev);
struct dsps_glue *glue = dev_get_drvdata(dev->parent);
del_timer_sync(&glue->timer[pdev->id]);
musb_dsps_phy_control(glue, pdev->id, 0);
usb_put_phy(musb->xceiv);
usb_nop_xceiv_unregister();
return 0;
}
static int dsps_create_musb_pdev(struct dsps_glue *glue, u8 id)
{
struct device *dev = glue->dev;
struct platform_device *pdev = to_platform_device(dev);
struct musb_hdrc_platform_data *pdata = dev->platform_data;
struct device_node *np = pdev->dev.of_node;
struct musb_hdrc_config *config;
struct platform_device *musb;
struct resource *res;
struct resource resources[2];
char res_name[11];
int ret;
resources[0].start = dsps_control_module_phys[id];
resources[0].end = resources[0].start + SZ_4 - 1;
resources[0].flags = IORESOURCE_MEM;
glue->usb_ctrl[id] = devm_ioremap_resource(&pdev->dev, resources);
if (IS_ERR(glue->usb_ctrl[id])) {
ret = PTR_ERR(glue->usb_ctrl[id]);
goto err0;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, id + 1);
if (!res) {
dev_err(dev, "failed to get memory for instance %d\n", id);
ret = -ENODEV;
goto err0;
}
res->parent = NULL;
resources[0] = *res;
res = platform_get_resource(pdev, IORESOURCE_IRQ, id + 1);
if (!res) {
dev_err(dev, "failed to get irq for instance %d\n", id);
ret = -ENODEV;
goto err0;
}
res->parent = NULL;
resources[1] = *res;
resources[1].name = "mc";
musb = platform_device_alloc("musb-hdrc", PLATFORM_DEVID_AUTO);
if (!musb) {
dev_err(dev, "failed to allocate musb device\n");
ret = -ENOMEM;
goto err0;
}
musb->dev.parent = dev;
musb->dev.dma_mask = &musb_dmamask;
musb->dev.coherent_dma_mask = musb_dmamask;
glue->musb[id] = musb;
ret = platform_device_add_resources(musb, resources, 2);
if (ret) {
dev_err(dev, "failed to add resources\n");
goto err2;
}
if (np) {
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata) {
dev_err(&pdev->dev,
"failed to allocate musb platform data\n");
ret = -ENOMEM;
goto err2;
}
config = devm_kzalloc(&pdev->dev, sizeof(*config), GFP_KERNEL);
if (!config) {
dev_err(&pdev->dev,
"failed to allocate musb hdrc config\n");
ret = -ENOMEM;
goto err2;
}
of_property_read_u32(np, "num-eps", (u32 *)&config->num_eps);
of_property_read_u32(np, "ram-bits", (u32 *)&config->ram_bits);
snprintf(res_name, sizeof(res_name), "port%d-mode", id);
of_property_read_u32(np, res_name, (u32 *)&pdata->mode);
of_property_read_u32(np, "power", (u32 *)&pdata->power);
config->multipoint = of_property_read_bool(np, "multipoint");
pdata->config = config;
}
pdata->platform_ops = &dsps_ops;
ret = platform_device_add_data(musb, pdata, sizeof(*pdata));
if (ret) {
dev_err(dev, "failed to add platform_data\n");
goto err2;
}
ret = platform_device_add(musb);
if (ret) {
dev_err(dev, "failed to register musb device\n");
goto err2;
}
return 0;
err2:
platform_device_put(musb);
err0:
return ret;
}
static int dsps_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
const struct dsps_musb_wrapper *wrp;
struct dsps_glue *glue;
struct resource *iomem;
int ret, i;
match = of_match_node(musb_dsps_of_match, pdev->dev.of_node);
if (!match) {
dev_err(&pdev->dev, "fail to get matching of_match struct\n");
ret = -EINVAL;
goto err0;
}
wrp = match->data;
glue = kzalloc(sizeof(*glue), GFP_KERNEL);
if (!glue) {
dev_err(&pdev->dev, "unable to allocate glue memory\n");
ret = -ENOMEM;
goto err0;
}
iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!iomem) {
dev_err(&pdev->dev, "failed to get usbss mem resourse\n");
ret = -ENODEV;
goto err1;
}
glue->dev = &pdev->dev;
glue->wrp = kmemdup(wrp, sizeof(*wrp), GFP_KERNEL);
if (!glue->wrp) {
dev_err(&pdev->dev, "failed to duplicate wrapper struct memory\n");
ret = -ENOMEM;
goto err1;
}
platform_set_drvdata(pdev, glue);
pm_runtime_enable(&pdev->dev);
ret = pm_runtime_get_sync(&pdev->dev);
if (ret < 0) {
dev_err(&pdev->dev, "pm_runtime_get_sync FAILED");
goto err2;
}
for (i = 0; i < wrp->instances ; i++) {
ret = dsps_create_musb_pdev(glue, i);
if (ret != 0) {
dev_err(&pdev->dev, "failed to create child pdev\n");
for (i--; i >= 0 ; i--)
platform_device_unregister(glue->musb[i]);
goto err3;
}
}
return 0;
err3:
pm_runtime_put(&pdev->dev);
err2:
pm_runtime_disable(&pdev->dev);
kfree(glue->wrp);
err1:
kfree(glue);
err0:
return ret;
}
static int dsps_remove(struct platform_device *pdev)
{
struct dsps_glue *glue = platform_get_drvdata(pdev);
const struct dsps_musb_wrapper *wrp = glue->wrp;
int i;
for (i = 0; i < wrp->instances ; i++)
platform_device_unregister(glue->musb[i]);
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
kfree(glue->wrp);
kfree(glue);
return 0;
}
static int dsps_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev->parent);
struct dsps_glue *glue = platform_get_drvdata(pdev);
const struct dsps_musb_wrapper *wrp = glue->wrp;
int i;
for (i = 0; i < wrp->instances; i++)
musb_dsps_phy_control(glue, i, 0);
return 0;
}
static int dsps_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev->parent);
struct dsps_glue *glue = platform_get_drvdata(pdev);
const struct dsps_musb_wrapper *wrp = glue->wrp;
int i;
for (i = 0; i < wrp->instances; i++)
musb_dsps_phy_control(glue, i, 1);
return 0;
}
static int __init dsps_init(void)
{
return platform_driver_register(&dsps_usbss_driver);
}
static void __exit dsps_exit(void)
{
platform_driver_unregister(&dsps_usbss_driver);
}
