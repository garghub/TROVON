static void dsps_mod_timer(struct dsps_glue *glue, int wait_ms)
{
int wait;
if (wait_ms < 0)
wait = msecs_to_jiffies(glue->wrp->poll_timeout);
else
wait = msecs_to_jiffies(wait_ms);
mod_timer(&glue->timer, jiffies + wait);
}
static void dsps_mod_timer_optional(struct dsps_glue *glue)
{
if (glue->vbus_irq)
return;
dsps_mod_timer(glue, -1);
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
musb_writel(reg_base, wrp->epintr_set, epmask);
musb_writel(reg_base, wrp->coreintr_set, coremask);
if (musb->xceiv->otg->state == OTG_STATE_B_IDLE &&
musb->port_mode == MUSB_PORT_MODE_DUAL_ROLE)
dsps_mod_timer(glue, -1);
}
static void dsps_musb_disable(struct musb *musb)
{
struct device *dev = musb->controller;
struct platform_device *pdev = to_platform_device(dev->parent);
struct dsps_glue *glue = platform_get_drvdata(pdev);
const struct dsps_musb_wrapper *wrp = glue->wrp;
void __iomem *reg_base = musb->ctrl_base;
musb_writel(reg_base, wrp->coreintr_clear, wrp->usb_bitmap);
musb_writel(reg_base, wrp->epintr_clear,
wrp->txep_bitmap | wrp->rxep_bitmap);
del_timer_sync(&glue->timer);
}
static int dsps_check_status(struct musb *musb, void *unused)
{
void __iomem *mregs = musb->mregs;
struct device *dev = musb->controller;
struct dsps_glue *glue = dev_get_drvdata(dev->parent);
const struct dsps_musb_wrapper *wrp = glue->wrp;
u8 devctl;
int skip_session = 0;
if (glue->vbus_irq)
del_timer(&glue->timer);
devctl = musb_readb(mregs, MUSB_DEVCTL);
dev_dbg(musb->controller, "Poll devctl %02x (%s)\n", devctl,
usb_otg_state_string(musb->xceiv->otg->state));
switch (musb->xceiv->otg->state) {
case OTG_STATE_A_WAIT_VRISE:
dsps_mod_timer_optional(glue);
break;
case OTG_STATE_A_WAIT_BCON:
if (musb->port_mode == MUSB_PORT_MODE_HOST) {
dsps_mod_timer_optional(glue);
break;
}
musb_writeb(musb->mregs, MUSB_DEVCTL, 0);
skip_session = 1;
case OTG_STATE_A_IDLE:
case OTG_STATE_B_IDLE:
if (!glue->vbus_irq) {
if (devctl & MUSB_DEVCTL_BDEVICE) {
musb->xceiv->otg->state = OTG_STATE_B_IDLE;
MUSB_DEV_MODE(musb);
} else {
musb->xceiv->otg->state = OTG_STATE_A_IDLE;
MUSB_HST_MODE(musb);
}
if (!(devctl & MUSB_DEVCTL_SESSION) && !skip_session)
musb_writeb(mregs, MUSB_DEVCTL,
MUSB_DEVCTL_SESSION);
}
dsps_mod_timer_optional(glue);
break;
case OTG_STATE_A_WAIT_VFALL:
musb->xceiv->otg->state = OTG_STATE_A_WAIT_VRISE;
musb_writel(musb->ctrl_base, wrp->coreintr_set,
MUSB_INTR_VBUSERROR << wrp->usb_shift);
break;
default:
break;
}
return 0;
}
static void otg_timer(unsigned long _musb)
{
struct musb *musb = (void *)_musb;
struct device *dev = musb->controller;
unsigned long flags;
int err;
err = pm_runtime_get(dev);
if ((err != -EINPROGRESS) && err < 0) {
dev_err(dev, "Poll could not pm_runtime_get: %i\n", err);
pm_runtime_put_noidle(dev);
return;
}
spin_lock_irqsave(&musb->lock, flags);
err = musb_queue_resume_work(musb, dsps_check_status, NULL);
if (err < 0)
dev_err(dev, "%s resume work: %i\n", __func__, err);
spin_unlock_irqrestore(&musb->lock, flags);
pm_runtime_mark_last_busy(dev);
pm_runtime_put_autosuspend(dev);
}
static void dsps_musb_clear_ep_rxintr(struct musb *musb, int epnum)
{
u32 epintr;
struct dsps_glue *glue = dev_get_drvdata(musb->controller->parent);
const struct dsps_musb_wrapper *wrp = glue->wrp;
epintr = (1 << epnum) << wrp->rxep_shift;
musb_writel(musb->ctrl_base, wrp->epintr_status, epintr);
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
epintr = musb_readl(reg_base, wrp->epintr_status);
musb->int_rx = (epintr & wrp->rxep_bitmap) >> wrp->rxep_shift;
musb->int_tx = (epintr & wrp->txep_bitmap) >> wrp->txep_shift;
if (epintr)
musb_writel(reg_base, wrp->epintr_status, epintr);
usbintr = musb_readl(reg_base, wrp->coreintr_status);
if (!usbintr && !epintr)
goto out;
musb->int_usb = (usbintr & wrp->usb_bitmap) >> wrp->usb_shift;
if (usbintr)
musb_writel(reg_base, wrp->coreintr_status, usbintr);
dev_dbg(musb->controller, "usbintr (%x) epintr(%x)\n",
usbintr, epintr);
if (usbintr & ((1 << wrp->drvvbus) << wrp->usb_shift)) {
int drvvbus = musb_readl(reg_base, wrp->status);
void __iomem *mregs = musb->mregs;
u8 devctl = musb_readb(mregs, MUSB_DEVCTL);
int err;
err = musb->int_usb & MUSB_INTR_VBUSERROR;
if (err) {
musb->int_usb &= ~MUSB_INTR_VBUSERROR;
musb->xceiv->otg->state = OTG_STATE_A_WAIT_VFALL;
dsps_mod_timer_optional(glue);
WARNING("VBUS error workaround (delay coming)\n");
} else if (drvvbus) {
MUSB_HST_MODE(musb);
musb->xceiv->otg->default_a = 1;
musb->xceiv->otg->state = OTG_STATE_A_WAIT_VRISE;
dsps_mod_timer_optional(glue);
} else {
musb->is_active = 0;
MUSB_DEV_MODE(musb);
musb->xceiv->otg->default_a = 0;
musb->xceiv->otg->state = OTG_STATE_B_IDLE;
}
dev_dbg(musb->controller, "VBUS %s (%s)%s, devctl %02x\n",
drvvbus ? "on" : "off",
usb_otg_state_string(musb->xceiv->otg->state),
err ? " ERROR" : "",
devctl);
ret = IRQ_HANDLED;
}
if (musb->int_tx || musb->int_rx || musb->int_usb)
ret |= musb_interrupt(musb);
switch (musb->xceiv->otg->state) {
case OTG_STATE_B_IDLE:
case OTG_STATE_A_WAIT_BCON:
dsps_mod_timer_optional(glue);
break;
default:
break;
}
out:
spin_unlock_irqrestore(&musb->lock, flags);
return ret;
}
static int dsps_musb_dbg_init(struct musb *musb, struct dsps_glue *glue)
{
struct dentry *root;
struct dentry *file;
char buf[128];
sprintf(buf, "%s.dsps", dev_name(musb->controller));
root = debugfs_create_dir(buf, NULL);
if (!root)
return -ENOMEM;
glue->dbgfs_root = root;
glue->regset.regs = dsps_musb_regs;
glue->regset.nregs = ARRAY_SIZE(dsps_musb_regs);
glue->regset.base = musb->ctrl_base;
file = debugfs_create_regset32("regdump", S_IRUGO, root, &glue->regset);
if (!file) {
debugfs_remove_recursive(root);
return -ENOMEM;
}
return 0;
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
int ret;
r = platform_get_resource_byname(parent, IORESOURCE_MEM, "control");
reg_base = devm_ioremap_resource(dev, r);
if (IS_ERR(reg_base))
return PTR_ERR(reg_base);
musb->ctrl_base = reg_base;
musb->xceiv = devm_usb_get_phy_by_phandle(dev->parent, "phys", 0);
if (IS_ERR(musb->xceiv))
return PTR_ERR(musb->xceiv);
musb->phy = devm_phy_get(dev->parent, "usb2-phy");
rev = musb_readl(reg_base, wrp->revision);
if (!rev)
return -ENODEV;
usb_phy_init(musb->xceiv);
if (IS_ERR(musb->phy)) {
musb->phy = NULL;
} else {
ret = phy_init(musb->phy);
if (ret < 0)
return ret;
ret = phy_power_on(musb->phy);
if (ret) {
phy_exit(musb->phy);
return ret;
}
}
setup_timer(&glue->timer, otg_timer, (unsigned long) musb);
musb_writel(reg_base, wrp->control, (1 << wrp->reset));
musb->isr = dsps_interrupt;
val = musb_readl(reg_base, wrp->phy_utmi);
val &= ~(1 << wrp->otg_disable);
musb_writel(musb->ctrl_base, wrp->phy_utmi, val);
val = musb_readb(musb->mregs, MUSB_BABBLE_CTL);
if (val & MUSB_BABBLE_RCV_DISABLE) {
glue->sw_babble_enabled = true;
val |= MUSB_BABBLE_SW_SESSION_CTRL;
musb_writeb(musb->mregs, MUSB_BABBLE_CTL, val);
}
dsps_mod_timer(glue, -1);
return dsps_musb_dbg_init(musb, glue);
}
static int dsps_musb_exit(struct musb *musb)
{
struct device *dev = musb->controller;
struct dsps_glue *glue = dev_get_drvdata(dev->parent);
del_timer_sync(&glue->timer);
usb_phy_shutdown(musb->xceiv);
phy_power_off(musb->phy);
phy_exit(musb->phy);
debugfs_remove_recursive(glue->dbgfs_root);
return 0;
}
static int dsps_musb_set_mode(struct musb *musb, u8 mode)
{
struct device *dev = musb->controller;
struct dsps_glue *glue = dev_get_drvdata(dev->parent);
const struct dsps_musb_wrapper *wrp = glue->wrp;
void __iomem *ctrl_base = musb->ctrl_base;
u32 reg;
reg = musb_readl(ctrl_base, wrp->mode);
switch (mode) {
case MUSB_HOST:
reg &= ~(1 << wrp->iddig);
reg |= (1 << wrp->iddig_mux);
musb_writel(ctrl_base, wrp->mode, reg);
musb_writel(ctrl_base, wrp->phy_utmi, 0x02);
break;
case MUSB_PERIPHERAL:
reg |= (1 << wrp->iddig);
reg |= (1 << wrp->iddig_mux);
musb_writel(ctrl_base, wrp->mode, reg);
break;
case MUSB_OTG:
musb_writel(ctrl_base, wrp->phy_utmi, 0x02);
break;
default:
dev_err(glue->dev, "unsupported mode %d\n", mode);
return -EINVAL;
}
return 0;
}
static bool dsps_sw_babble_control(struct musb *musb)
{
u8 babble_ctl;
bool session_restart = false;
babble_ctl = musb_readb(musb->mregs, MUSB_BABBLE_CTL);
dev_dbg(musb->controller, "babble: MUSB_BABBLE_CTL value %x\n",
babble_ctl);
dev_dbg(musb->controller, "STUCK_J is %s\n",
babble_ctl & MUSB_BABBLE_STUCK_J ? "set" : "reset");
if (babble_ctl & MUSB_BABBLE_STUCK_J) {
int timeout = 10;
babble_ctl = musb_readb(musb->mregs, MUSB_BABBLE_CTL);
babble_ctl |= MUSB_BABBLE_FORCE_TXIDLE;
musb_writeb(musb->mregs, MUSB_BABBLE_CTL, babble_ctl);
dev_dbg(musb->controller, "Set TXIDLE, wait J to clear\n");
do {
babble_ctl = musb_readb(musb->mregs, MUSB_BABBLE_CTL);
udelay(1);
} while ((babble_ctl & MUSB_BABBLE_STUCK_J) && timeout--);
if (babble_ctl & MUSB_BABBLE_STUCK_J) {
dev_dbg(musb->controller, "J not cleared, misc (%x)\n",
babble_ctl);
session_restart = true;
}
} else {
session_restart = true;
}
return session_restart;
}
static int dsps_musb_recover(struct musb *musb)
{
struct device *dev = musb->controller;
struct dsps_glue *glue = dev_get_drvdata(dev->parent);
int session_restart = 0;
if (glue->sw_babble_enabled)
session_restart = dsps_sw_babble_control(musb);
else
session_restart = 1;
return session_restart ? 0 : -EPIPE;
}
static void dsps_read_fifo32(struct musb_hw_ep *hw_ep, u16 len, u8 *dst)
{
void __iomem *fifo = hw_ep->fifo;
if (len >= 4) {
ioread32_rep(fifo, dst, len >> 2);
dst += len & ~0x03;
len &= 0x03;
}
if (len > 0) {
u32 val = musb_readl(fifo, 0);
memcpy(dst, &val, len);
}
}
static void dsps_dma_controller_callback(struct dma_controller *c)
{
struct musb *musb = c->musb;
struct dsps_glue *glue = dev_get_drvdata(musb->controller->parent);
void __iomem *usbss_base = glue->usbss_base;
u32 status;
status = musb_readl(usbss_base, USBSS_IRQ_STATUS);
if (status & USBSS_IRQ_PD_COMP)
musb_writel(usbss_base, USBSS_IRQ_STATUS, USBSS_IRQ_PD_COMP);
}
static struct dma_controller *
dsps_dma_controller_create(struct musb *musb, void __iomem *base)
{
struct dma_controller *controller;
struct dsps_glue *glue = dev_get_drvdata(musb->controller->parent);
void __iomem *usbss_base = glue->usbss_base;
controller = cppi41_dma_controller_create(musb, base);
if (IS_ERR_OR_NULL(controller))
return controller;
musb_writel(usbss_base, USBSS_IRQ_ENABLER, USBSS_IRQ_PD_COMP);
controller->dma_callback = dsps_dma_controller_callback;
return controller;
}
static void dsps_dma_controller_destroy(struct dma_controller *c)
{
struct musb *musb = c->musb;
struct dsps_glue *glue = dev_get_drvdata(musb->controller->parent);
void __iomem *usbss_base = glue->usbss_base;
musb_writel(usbss_base, USBSS_IRQ_CLEARR, USBSS_IRQ_PD_COMP);
cppi41_dma_controller_destroy(c);
}
static void dsps_dma_controller_suspend(struct dsps_glue *glue)
{
void __iomem *usbss_base = glue->usbss_base;
musb_writel(usbss_base, USBSS_IRQ_CLEARR, USBSS_IRQ_PD_COMP);
}
static void dsps_dma_controller_resume(struct dsps_glue *glue)
{
void __iomem *usbss_base = glue->usbss_base;
musb_writel(usbss_base, USBSS_IRQ_ENABLER, USBSS_IRQ_PD_COMP);
}
static void dsps_dma_controller_suspend(struct dsps_glue *glue) {}
static void dsps_dma_controller_resume(struct dsps_glue *glue) {}
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
mode = usb_get_dr_mode(dev);
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
int ret, val;
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
musb = platform_device_alloc("musb-hdrc",
(resources[0].start & 0xFFF) == 0x400 ? 0 : 1);
if (!musb) {
dev_err(dev, "failed to allocate musb device\n");
return -ENOMEM;
}
musb->dev.parent = dev;
musb->dev.dma_mask = &musb_dmamask;
musb->dev.coherent_dma_mask = musb_dmamask;
glue->musb = musb;
ret = platform_device_add_resources(musb, resources,
ARRAY_SIZE(resources));
if (ret) {
dev_err(dev, "failed to add resources\n");
goto err;
}
config = devm_kzalloc(&parent->dev, sizeof(*config), GFP_KERNEL);
if (!config) {
ret = -ENOMEM;
goto err;
}
pdata.config = config;
pdata.platform_ops = &dsps_ops;
config->num_eps = get_int_prop(dn, "mentor,num-eps");
config->ram_bits = get_int_prop(dn, "mentor,ram-bits");
config->host_port_deassert_reset_at_resume = 1;
pdata.mode = get_musb_port_mode(dev);
pdata.power = get_int_prop(dn, "mentor,power") / 2;
ret = of_property_read_u32(dn, "mentor,multipoint", &val);
if (!ret && val)
config->multipoint = true;
config->maximum_speed = usb_get_maximum_speed(&parent->dev);
switch (config->maximum_speed) {
case USB_SPEED_LOW:
case USB_SPEED_FULL:
break;
case USB_SPEED_SUPER:
dev_warn(dev, "ignore incorrect maximum_speed "
"(super-speed) setting in dts");
default:
config->maximum_speed = USB_SPEED_HIGH;
}
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
static irqreturn_t dsps_vbus_threaded_irq(int irq, void *priv)
{
struct dsps_glue *glue = priv;
struct musb *musb = platform_get_drvdata(glue->musb);
if (!musb)
return IRQ_NONE;
dev_dbg(glue->dev, "VBUS interrupt\n");
dsps_mod_timer(glue, 0);
return IRQ_HANDLED;
}
static int dsps_setup_optional_vbus_irq(struct platform_device *pdev,
struct dsps_glue *glue)
{
int error;
glue->vbus_irq = platform_get_irq_byname(pdev, "vbus");
if (glue->vbus_irq == -EPROBE_DEFER)
return -EPROBE_DEFER;
if (glue->vbus_irq <= 0) {
glue->vbus_irq = 0;
return 0;
}
error = devm_request_threaded_irq(glue->dev, glue->vbus_irq,
NULL, dsps_vbus_threaded_irq,
IRQF_ONESHOT,
"vbus", glue);
if (error) {
glue->vbus_irq = 0;
return error;
}
dev_dbg(glue->dev, "VBUS irq %i configured\n", glue->vbus_irq);
return 0;
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
if (of_device_is_compatible(pdev->dev.of_node, "ti,musb-dm816"))
dsps_ops.read_fifo = dsps_read_fifo32;
glue = devm_kzalloc(&pdev->dev, sizeof(*glue), GFP_KERNEL);
if (!glue)
return -ENOMEM;
glue->dev = &pdev->dev;
glue->wrp = wrp;
glue->usbss_base = of_iomap(pdev->dev.parent->of_node, 0);
if (!glue->usbss_base)
return -ENXIO;
if (usb_get_dr_mode(&pdev->dev) == USB_DR_MODE_PERIPHERAL) {
ret = dsps_setup_optional_vbus_irq(pdev, glue);
if (ret)
goto err_iounmap;
}
platform_set_drvdata(pdev, glue);
pm_runtime_enable(&pdev->dev);
ret = dsps_create_musb_pdev(glue, pdev);
if (ret)
goto err;
return 0;
err:
pm_runtime_disable(&pdev->dev);
err_iounmap:
iounmap(glue->usbss_base);
return ret;
}
static int dsps_remove(struct platform_device *pdev)
{
struct dsps_glue *glue = platform_get_drvdata(pdev);
platform_device_unregister(glue->musb);
pm_runtime_disable(&pdev->dev);
iounmap(glue->usbss_base);
return 0;
}
static int dsps_suspend(struct device *dev)
{
struct dsps_glue *glue = dev_get_drvdata(dev);
const struct dsps_musb_wrapper *wrp = glue->wrp;
struct musb *musb = platform_get_drvdata(glue->musb);
void __iomem *mbase;
int ret;
if (!musb)
return 0;
ret = pm_runtime_get_sync(dev);
if (ret < 0) {
pm_runtime_put_noidle(dev);
return ret;
}
del_timer_sync(&glue->timer);
mbase = musb->ctrl_base;
glue->context.control = musb_readl(mbase, wrp->control);
glue->context.epintr = musb_readl(mbase, wrp->epintr_set);
glue->context.coreintr = musb_readl(mbase, wrp->coreintr_set);
glue->context.phy_utmi = musb_readl(mbase, wrp->phy_utmi);
glue->context.mode = musb_readl(mbase, wrp->mode);
glue->context.tx_mode = musb_readl(mbase, wrp->tx_mode);
glue->context.rx_mode = musb_readl(mbase, wrp->rx_mode);
dsps_dma_controller_suspend(glue);
return 0;
}
static int dsps_resume(struct device *dev)
{
struct dsps_glue *glue = dev_get_drvdata(dev);
const struct dsps_musb_wrapper *wrp = glue->wrp;
struct musb *musb = platform_get_drvdata(glue->musb);
void __iomem *mbase;
if (!musb)
return 0;
dsps_dma_controller_resume(glue);
mbase = musb->ctrl_base;
musb_writel(mbase, wrp->control, glue->context.control);
musb_writel(mbase, wrp->epintr_set, glue->context.epintr);
musb_writel(mbase, wrp->coreintr_set, glue->context.coreintr);
musb_writel(mbase, wrp->phy_utmi, glue->context.phy_utmi);
musb_writel(mbase, wrp->mode, glue->context.mode);
musb_writel(mbase, wrp->tx_mode, glue->context.tx_mode);
musb_writel(mbase, wrp->rx_mode, glue->context.rx_mode);
if (musb->xceiv->otg->state == OTG_STATE_B_IDLE &&
musb->port_mode == MUSB_PORT_MODE_DUAL_ROLE)
dsps_mod_timer(glue, -1);
pm_runtime_put(dev);
return 0;
}
