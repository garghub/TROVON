static inline u8 dsps_readb(const void __iomem *addr, unsigned offset)
{ return __raw_readb(addr + offset); }
static inline u32 dsps_readl(const void __iomem *addr, unsigned offset)
{ return __raw_readl(addr + offset); }
static inline void dsps_writeb(void __iomem *addr, unsigned offset, u8 data)
{ __raw_writeb(data, addr + offset); }
static inline void dsps_writel(void __iomem *addr, unsigned offset, u32 data)
{ __raw_writel(data, addr + offset); }
static void dsps_musb_try_idle(struct musb *musb, unsigned long timeout)
{
struct device *dev = musb->controller;
struct dsps_glue *glue = dev_get_drvdata(dev->parent);
if (timeout == 0)
timeout = jiffies + msecs_to_jiffies(3);
if (musb->is_active || (musb->a_wait_bcon == 0 &&
musb->xceiv->state == OTG_STATE_A_WAIT_BCON)) {
dev_dbg(musb->controller, "%s active, deleting timer\n",
usb_otg_state_string(musb->xceiv->state));
del_timer(&glue->timer);
glue->last_timer = jiffies;
return;
}
if (musb->port_mode != MUSB_PORT_MODE_DUAL_ROLE)
return;
if (!musb->g.dev.driver)
return;
if (time_after(glue->last_timer, timeout) &&
timer_pending(&glue->timer)) {
dev_dbg(musb->controller,
"Longer idle timer already pending, ignoring...\n");
return;
}
glue->last_timer = timeout;
dev_dbg(musb->controller, "%s inactive, starting idle timer for %u ms\n",
usb_otg_state_string(musb->xceiv->state),
jiffies_to_msecs(timeout - jiffies));
mod_timer(&glue->timer, timeout);
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
dsps_musb_try_idle(musb, 0);
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
}
static void otg_timer(unsigned long _musb)
{
struct musb *musb = (void *)_musb;
void __iomem *mregs = musb->mregs;
struct device *dev = musb->controller;
struct dsps_glue *glue = dev_get_drvdata(dev->parent);
const struct dsps_musb_wrapper *wrp = glue->wrp;
u8 devctl;
unsigned long flags;
int skip_session = 0;
devctl = dsps_readb(mregs, MUSB_DEVCTL);
dev_dbg(musb->controller, "Poll devctl %02x (%s)\n", devctl,
usb_otg_state_string(musb->xceiv->state));
spin_lock_irqsave(&musb->lock, flags);
switch (musb->xceiv->state) {
case OTG_STATE_A_WAIT_BCON:
dsps_writeb(musb->mregs, MUSB_DEVCTL, 0);
skip_session = 1;
case OTG_STATE_A_IDLE:
case OTG_STATE_B_IDLE:
if (devctl & MUSB_DEVCTL_BDEVICE) {
musb->xceiv->state = OTG_STATE_B_IDLE;
MUSB_DEV_MODE(musb);
} else {
musb->xceiv->state = OTG_STATE_A_IDLE;
MUSB_HST_MODE(musb);
}
if (!(devctl & MUSB_DEVCTL_SESSION) && !skip_session)
dsps_writeb(mregs, MUSB_DEVCTL, MUSB_DEVCTL_SESSION);
mod_timer(&glue->timer, jiffies + wrp->poll_seconds * HZ);
break;
case OTG_STATE_A_WAIT_VFALL:
musb->xceiv->state = OTG_STATE_A_WAIT_VRISE;
dsps_writel(musb->ctrl_base, wrp->coreintr_set,
MUSB_INTR_VBUSERROR << wrp->usb_shift);
break;
default:
break;
}
spin_unlock_irqrestore(&musb->lock, flags);
}
static irqreturn_t dsps_interrupt(int irq, void *hci)
{
struct musb *musb = hci;
void __iomem *reg_base = musb->ctrl_base;
struct device *dev = musb->controller;
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
goto out;
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
mod_timer(&glue->timer,
jiffies + wrp->poll_seconds * HZ);
WARNING("VBUS error workaround (delay coming)\n");
} else if (drvvbus) {
MUSB_HST_MODE(musb);
musb->xceiv->otg->default_a = 1;
musb->xceiv->state = OTG_STATE_A_WAIT_VRISE;
del_timer(&glue->timer);
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
if (musb->xceiv->state == OTG_STATE_B_IDLE)
mod_timer(&glue->timer, jiffies + wrp->poll_seconds * HZ);
out:
spin_unlock_irqrestore(&musb->lock, flags);
return ret;
}
static int dsps_musb_init(struct musb *musb)
{
struct device *dev = musb->controller;
struct dsps_glue *glue = dev_get_drvdata(dev->parent);
struct platform_device *parent = to_platform_device(dev->parent);
const struct dsps_musb_wrapper *wrp = glue->wrp;
void __iomem *reg_base;
struct resource *r;
u32 rev, val;
r = platform_get_resource_byname(parent, IORESOURCE_MEM, "control");
if (!r)
return -EINVAL;
reg_base = devm_ioremap_resource(dev, r);
if (IS_ERR(reg_base))
return PTR_ERR(reg_base);
musb->ctrl_base = reg_base;
musb->xceiv = devm_usb_get_phy_by_phandle(dev, "phys", 0);
if (IS_ERR(musb->xceiv))
return PTR_ERR(musb->xceiv);
rev = dsps_readl(reg_base, wrp->revision);
if (!rev)
return -ENODEV;
usb_phy_init(musb->xceiv);
setup_timer(&glue->timer, otg_timer, (unsigned long) musb);
dsps_writel(reg_base, wrp->control, (1 << wrp->reset));
musb->isr = dsps_interrupt;
val = dsps_readl(reg_base, wrp->phy_utmi);
val &= ~(1 << wrp->otg_disable);
dsps_writel(musb->ctrl_base, wrp->phy_utmi, val);
return 0;
}
static int dsps_musb_exit(struct musb *musb)
{
struct device *dev = musb->controller;
struct dsps_glue *glue = dev_get_drvdata(dev->parent);
del_timer_sync(&glue->timer);
usb_phy_shutdown(musb->xceiv);
return 0;
}
static int get_int_prop(struct device_node *dn, const char *s)
{
int ret;
u32 val;
ret = of_property_read_u32(dn, s, &val);
if (ret)
return 0;
return val;
}
static int get_musb_port_mode(struct device *dev)
{
enum usb_dr_mode mode;
mode = of_usb_get_dr_mode(dev->of_node);
switch (mode) {
case USB_DR_MODE_HOST:
return MUSB_PORT_MODE_HOST;
case USB_DR_MODE_PERIPHERAL:
return MUSB_PORT_MODE_GADGET;
case USB_DR_MODE_UNKNOWN:
case USB_DR_MODE_OTG:
default:
return MUSB_PORT_MODE_DUAL_ROLE;
}
}
static int dsps_create_musb_pdev(struct dsps_glue *glue,
struct platform_device *parent)
{
struct musb_hdrc_platform_data pdata;
struct resource resources[2];
struct resource *res;
struct device *dev = &parent->dev;
struct musb_hdrc_config *config;
struct platform_device *musb;
struct device_node *dn = parent->dev.of_node;
int ret;
memset(resources, 0, sizeof(resources));
res = platform_get_resource_byname(parent, IORESOURCE_MEM, "mc");
if (!res) {
dev_err(dev, "failed to get memory.\n");
return -EINVAL;
}
resources[0] = *res;
res = platform_get_resource_byname(parent, IORESOURCE_IRQ, "mc");
if (!res) {
dev_err(dev, "failed to get irq.\n");
return -EINVAL;
}
resources[1] = *res;
musb = platform_device_alloc("musb-hdrc", PLATFORM_DEVID_AUTO);
if (!musb) {
dev_err(dev, "failed to allocate musb device\n");
return -ENOMEM;
}
musb->dev.parent = dev;
musb->dev.dma_mask = &musb_dmamask;
musb->dev.coherent_dma_mask = musb_dmamask;
musb->dev.of_node = of_node_get(dn);
glue->musb = musb;
ret = platform_device_add_resources(musb, resources,
ARRAY_SIZE(resources));
if (ret) {
dev_err(dev, "failed to add resources\n");
goto err;
}
config = devm_kzalloc(&parent->dev, sizeof(*config), GFP_KERNEL);
if (!config) {
dev_err(dev, "failed to allocate musb hdrc config\n");
ret = -ENOMEM;
goto err;
}
pdata.config = config;
pdata.platform_ops = &dsps_ops;
config->num_eps = get_int_prop(dn, "mentor,num-eps");
config->ram_bits = get_int_prop(dn, "mentor,ram-bits");
pdata.mode = get_musb_port_mode(dev);
pdata.power = get_int_prop(dn, "mentor,power") / 2;
config->multipoint = of_property_read_bool(dn, "mentor,multipoint");
ret = platform_device_add_data(musb, &pdata, sizeof(pdata));
if (ret) {
dev_err(dev, "failed to add platform_data\n");
goto err;
}
ret = platform_device_add(musb);
if (ret) {
dev_err(dev, "failed to register musb device\n");
goto err;
}
return 0;
err:
platform_device_put(musb);
return ret;
}
static int dsps_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
const struct dsps_musb_wrapper *wrp;
struct dsps_glue *glue;
int ret;
if (!strcmp(pdev->name, "musb-hdrc"))
return -ENODEV;
match = of_match_node(musb_dsps_of_match, pdev->dev.of_node);
if (!match) {
dev_err(&pdev->dev, "fail to get matching of_match struct\n");
return -EINVAL;
}
wrp = match->data;
glue = kzalloc(sizeof(*glue), GFP_KERNEL);
if (!glue) {
dev_err(&pdev->dev, "unable to allocate glue memory\n");
return -ENOMEM;
}
glue->dev = &pdev->dev;
glue->wrp = wrp;
platform_set_drvdata(pdev, glue);
pm_runtime_enable(&pdev->dev);
ret = pm_runtime_get_sync(&pdev->dev);
if (ret < 0) {
dev_err(&pdev->dev, "pm_runtime_get_sync FAILED");
goto err2;
}
ret = dsps_create_musb_pdev(glue, pdev);
if (ret)
goto err3;
return 0;
err3:
pm_runtime_put(&pdev->dev);
err2:
pm_runtime_disable(&pdev->dev);
kfree(glue);
return ret;
}
static int dsps_remove(struct platform_device *pdev)
{
struct dsps_glue *glue = platform_get_drvdata(pdev);
platform_device_unregister(glue->musb);
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
kfree(glue);
return 0;
}
