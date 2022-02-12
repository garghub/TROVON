static inline void phy_on(void)
{
u32 cfgchip2 = __raw_readl(CFGCHIP2);
cfgchip2 &= ~(CFGCHIP2_RESET | CFGCHIP2_PHYPWRDN | CFGCHIP2_OTGPWRDN);
cfgchip2 |= CFGCHIP2_PHY_PLLON;
__raw_writel(cfgchip2, CFGCHIP2);
pr_info("Waiting for USB PHY clock good...\n");
while (!(__raw_readl(CFGCHIP2) & CFGCHIP2_PHYCLKGD))
cpu_relax();
}
static inline void phy_off(void)
{
u32 cfgchip2 = __raw_readl(CFGCHIP2);
if (!(cfgchip2 & CFGCHIP2_USB1PHYCLKMUX) &&
(cfgchip2 & CFGCHIP2_USB1SUSPENDM)) {
pr_warning("USB 1.1 clocked from USB 2.0 PHY -- "
"can't power it down\n");
return;
}
cfgchip2 |= CFGCHIP2_PHYPWRDN | CFGCHIP2_OTGPWRDN;
__raw_writel(cfgchip2, CFGCHIP2);
}
static void da8xx_musb_enable(struct musb *musb)
{
void __iomem *reg_base = musb->ctrl_base;
u32 mask;
mask = ((musb->epmask & DA8XX_USB_TX_EP_MASK) << DA8XX_INTR_TX_SHIFT) |
((musb->epmask & DA8XX_USB_RX_EP_MASK) << DA8XX_INTR_RX_SHIFT) |
DA8XX_INTR_USB_MASK;
musb_writel(reg_base, DA8XX_USB_INTR_MASK_SET_REG, mask);
musb_writel(reg_base, DA8XX_USB_INTR_SRC_SET_REG,
DA8XX_INTR_DRVVBUS << DA8XX_INTR_USB_SHIFT);
}
static void da8xx_musb_disable(struct musb *musb)
{
void __iomem *reg_base = musb->ctrl_base;
musb_writel(reg_base, DA8XX_USB_INTR_MASK_CLEAR_REG,
DA8XX_INTR_USB_MASK |
DA8XX_INTR_TX_MASK | DA8XX_INTR_RX_MASK);
musb_writeb(musb->mregs, MUSB_DEVCTL, 0);
musb_writel(reg_base, DA8XX_USB_END_OF_INTR_REG, 0);
}
static void da8xx_musb_set_vbus(struct musb *musb, int is_on)
{
WARN_ON(is_on && is_peripheral_active(musb));
}
static void otg_timer(unsigned long _musb)
{
struct musb *musb = (void *)_musb;
void __iomem *mregs = musb->mregs;
u8 devctl;
unsigned long flags;
devctl = musb_readb(mregs, MUSB_DEVCTL);
dev_dbg(musb->controller, "Poll devctl %02x (%s)\n", devctl,
usb_otg_state_string(musb->xceiv->otg->state));
spin_lock_irqsave(&musb->lock, flags);
switch (musb->xceiv->otg->state) {
case OTG_STATE_A_WAIT_BCON:
devctl &= ~MUSB_DEVCTL_SESSION;
musb_writeb(musb->mregs, MUSB_DEVCTL, devctl);
devctl = musb_readb(musb->mregs, MUSB_DEVCTL);
if (devctl & MUSB_DEVCTL_BDEVICE) {
musb->xceiv->otg->state = OTG_STATE_B_IDLE;
MUSB_DEV_MODE(musb);
} else {
musb->xceiv->otg->state = OTG_STATE_A_IDLE;
MUSB_HST_MODE(musb);
}
break;
case OTG_STATE_A_WAIT_VFALL:
if (devctl & MUSB_DEVCTL_VBUS) {
mod_timer(&otg_workaround, jiffies + POLL_SECONDS * HZ);
break;
}
musb->xceiv->otg->state = OTG_STATE_A_WAIT_VRISE;
musb_writel(musb->ctrl_base, DA8XX_USB_INTR_SRC_SET_REG,
MUSB_INTR_VBUSERROR << DA8XX_INTR_USB_SHIFT);
break;
case OTG_STATE_B_IDLE:
musb_writeb(mregs, MUSB_DEVCTL, devctl | MUSB_DEVCTL_SESSION);
devctl = musb_readb(mregs, MUSB_DEVCTL);
if (devctl & MUSB_DEVCTL_BDEVICE)
mod_timer(&otg_workaround, jiffies + POLL_SECONDS * HZ);
else
musb->xceiv->otg->state = OTG_STATE_A_IDLE;
break;
default:
break;
}
spin_unlock_irqrestore(&musb->lock, flags);
}
static void da8xx_musb_try_idle(struct musb *musb, unsigned long timeout)
{
static unsigned long last_timer;
if (timeout == 0)
timeout = jiffies + msecs_to_jiffies(3);
if (musb->is_active || (musb->a_wait_bcon == 0 &&
musb->xceiv->otg->state == OTG_STATE_A_WAIT_BCON)) {
dev_dbg(musb->controller, "%s active, deleting timer\n",
usb_otg_state_string(musb->xceiv->otg->state));
del_timer(&otg_workaround);
last_timer = jiffies;
return;
}
if (time_after(last_timer, timeout) && timer_pending(&otg_workaround)) {
dev_dbg(musb->controller, "Longer idle timer already pending, ignoring...\n");
return;
}
last_timer = timeout;
dev_dbg(musb->controller, "%s inactive, starting idle timer for %u ms\n",
usb_otg_state_string(musb->xceiv->otg->state),
jiffies_to_msecs(timeout - jiffies));
mod_timer(&otg_workaround, timeout);
}
static irqreturn_t da8xx_musb_interrupt(int irq, void *hci)
{
struct musb *musb = hci;
void __iomem *reg_base = musb->ctrl_base;
struct usb_otg *otg = musb->xceiv->otg;
unsigned long flags;
irqreturn_t ret = IRQ_NONE;
u32 status;
spin_lock_irqsave(&musb->lock, flags);
status = musb_readl(reg_base, DA8XX_USB_INTR_SRC_MASKED_REG);
if (!status)
goto eoi;
musb_writel(reg_base, DA8XX_USB_INTR_SRC_CLEAR_REG, status);
dev_dbg(musb->controller, "USB IRQ %08x\n", status);
musb->int_rx = (status & DA8XX_INTR_RX_MASK) >> DA8XX_INTR_RX_SHIFT;
musb->int_tx = (status & DA8XX_INTR_TX_MASK) >> DA8XX_INTR_TX_SHIFT;
musb->int_usb = (status & DA8XX_INTR_USB_MASK) >> DA8XX_INTR_USB_SHIFT;
if (status & (DA8XX_INTR_DRVVBUS << DA8XX_INTR_USB_SHIFT)) {
int drvvbus = musb_readl(reg_base, DA8XX_USB_STAT_REG);
void __iomem *mregs = musb->mregs;
u8 devctl = musb_readb(mregs, MUSB_DEVCTL);
int err;
err = musb->int_usb & MUSB_INTR_VBUSERROR;
if (err) {
musb->int_usb &= ~MUSB_INTR_VBUSERROR;
musb->xceiv->otg->state = OTG_STATE_A_WAIT_VFALL;
mod_timer(&otg_workaround, jiffies + POLL_SECONDS * HZ);
WARNING("VBUS error workaround (delay coming)\n");
} else if (drvvbus) {
MUSB_HST_MODE(musb);
otg->default_a = 1;
musb->xceiv->otg->state = OTG_STATE_A_WAIT_VRISE;
portstate(musb->port1_status |= USB_PORT_STAT_POWER);
del_timer(&otg_workaround);
} else {
musb->is_active = 0;
MUSB_DEV_MODE(musb);
otg->default_a = 0;
musb->xceiv->otg->state = OTG_STATE_B_IDLE;
portstate(musb->port1_status &= ~USB_PORT_STAT_POWER);
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
eoi:
if (ret == IRQ_HANDLED || status)
musb_writel(reg_base, DA8XX_USB_END_OF_INTR_REG, 0);
if (musb->xceiv->otg->state == OTG_STATE_B_IDLE)
mod_timer(&otg_workaround, jiffies + POLL_SECONDS * HZ);
spin_unlock_irqrestore(&musb->lock, flags);
return ret;
}
static int da8xx_musb_set_mode(struct musb *musb, u8 musb_mode)
{
u32 cfgchip2 = __raw_readl(CFGCHIP2);
cfgchip2 &= ~CFGCHIP2_OTGMODE;
switch (musb_mode) {
case MUSB_HOST:
cfgchip2 |= CFGCHIP2_FORCE_HOST;
break;
case MUSB_PERIPHERAL:
cfgchip2 |= CFGCHIP2_FORCE_DEVICE;
break;
case MUSB_OTG:
cfgchip2 |= CFGCHIP2_NO_OVERRIDE;
break;
default:
dev_dbg(musb->controller, "Trying to set unsupported mode %u\n", musb_mode);
}
__raw_writel(cfgchip2, CFGCHIP2);
return 0;
}
static int da8xx_musb_init(struct musb *musb)
{
void __iomem *reg_base = musb->ctrl_base;
u32 rev;
int ret = -ENODEV;
musb->mregs += DA8XX_MENTOR_CORE_OFFSET;
rev = musb_readl(reg_base, DA8XX_USB_REVISION_REG);
if (!rev)
goto fail;
musb->xceiv = usb_get_phy(USB_PHY_TYPE_USB2);
if (IS_ERR_OR_NULL(musb->xceiv)) {
ret = -EPROBE_DEFER;
goto fail;
}
setup_timer(&otg_workaround, otg_timer, (unsigned long)musb);
musb_writel(reg_base, DA8XX_USB_CTRL_REG, DA8XX_SOFT_RESET_MASK);
phy_on();
msleep(5);
pr_debug("DA8xx OTG revision %08x, PHY %03x, control %02x\n",
rev, __raw_readl(CFGCHIP2),
musb_readb(reg_base, DA8XX_USB_CTRL_REG));
musb->isr = da8xx_musb_interrupt;
return 0;
fail:
return ret;
}
static int da8xx_musb_exit(struct musb *musb)
{
del_timer_sync(&otg_workaround);
phy_off();
usb_put_phy(musb->xceiv);
return 0;
}
static int da8xx_probe(struct platform_device *pdev)
{
struct resource musb_resources[2];
struct musb_hdrc_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct platform_device *musb;
struct da8xx_glue *glue;
struct platform_device_info pinfo;
struct clk *clk;
int ret = -ENOMEM;
glue = kzalloc(sizeof(*glue), GFP_KERNEL);
if (!glue) {
dev_err(&pdev->dev, "failed to allocate glue context\n");
goto err0;
}
clk = clk_get(&pdev->dev, "usb20");
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "failed to get clock\n");
ret = PTR_ERR(clk);
goto err3;
}
ret = clk_enable(clk);
if (ret) {
dev_err(&pdev->dev, "failed to enable clock\n");
goto err4;
}
glue->dev = &pdev->dev;
glue->clk = clk;
pdata->platform_ops = &da8xx_ops;
glue->phy = usb_phy_generic_register();
if (IS_ERR(glue->phy)) {
ret = PTR_ERR(glue->phy);
goto err5;
}
platform_set_drvdata(pdev, glue);
memset(musb_resources, 0x00, sizeof(*musb_resources) *
ARRAY_SIZE(musb_resources));
musb_resources[0].name = pdev->resource[0].name;
musb_resources[0].start = pdev->resource[0].start;
musb_resources[0].end = pdev->resource[0].end;
musb_resources[0].flags = pdev->resource[0].flags;
musb_resources[1].name = pdev->resource[1].name;
musb_resources[1].start = pdev->resource[1].start;
musb_resources[1].end = pdev->resource[1].end;
musb_resources[1].flags = pdev->resource[1].flags;
pinfo = da8xx_dev_info;
pinfo.parent = &pdev->dev;
pinfo.res = musb_resources;
pinfo.num_res = ARRAY_SIZE(musb_resources);
pinfo.data = pdata;
pinfo.size_data = sizeof(*pdata);
glue->musb = musb = platform_device_register_full(&pinfo);
if (IS_ERR(musb)) {
ret = PTR_ERR(musb);
dev_err(&pdev->dev, "failed to register musb device: %d\n", ret);
goto err6;
}
return 0;
err6:
usb_phy_generic_unregister(glue->phy);
err5:
clk_disable(clk);
err4:
clk_put(clk);
err3:
kfree(glue);
err0:
return ret;
}
static int da8xx_remove(struct platform_device *pdev)
{
struct da8xx_glue *glue = platform_get_drvdata(pdev);
platform_device_unregister(glue->musb);
usb_phy_generic_unregister(glue->phy);
clk_disable(glue->clk);
clk_put(glue->clk);
kfree(glue);
return 0;
}
