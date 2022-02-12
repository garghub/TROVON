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
struct da8xx_glue *glue = dev_get_drvdata(musb->controller->parent);
enum phy_mode phy_mode;
if (!musb->is_initialized)
return phy_set_mode(glue->phy, PHY_MODE_USB_OTG);
switch (musb_mode) {
case MUSB_HOST:
phy_mode = PHY_MODE_USB_HOST;
break;
case MUSB_PERIPHERAL:
phy_mode = PHY_MODE_USB_DEVICE;
break;
case MUSB_OTG:
phy_mode = PHY_MODE_USB_OTG;
break;
default:
return -EINVAL;
}
return phy_set_mode(glue->phy, phy_mode);
}
static int da8xx_musb_init(struct musb *musb)
{
struct da8xx_glue *glue = dev_get_drvdata(musb->controller->parent);
void __iomem *reg_base = musb->ctrl_base;
u32 rev;
int ret = -ENODEV;
musb->mregs += DA8XX_MENTOR_CORE_OFFSET;
ret = clk_prepare_enable(glue->clk);
if (ret) {
dev_err(glue->dev, "failed to enable clock\n");
return ret;
}
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
ret = phy_init(glue->phy);
if (ret) {
dev_err(glue->dev, "Failed to init phy.\n");
goto fail;
}
ret = phy_power_on(glue->phy);
if (ret) {
dev_err(glue->dev, "Failed to power on phy.\n");
goto err_phy_power_on;
}
msleep(5);
pr_debug("DA8xx OTG revision %08x, control %02x\n", rev,
musb_readb(reg_base, DA8XX_USB_CTRL_REG));
musb->isr = da8xx_musb_interrupt;
return 0;
err_phy_power_on:
phy_exit(glue->phy);
fail:
clk_disable_unprepare(glue->clk);
return ret;
}
static int da8xx_musb_exit(struct musb *musb)
{
struct da8xx_glue *glue = dev_get_drvdata(musb->controller->parent);
del_timer_sync(&otg_workaround);
phy_power_off(glue->phy);
phy_exit(glue->phy);
clk_disable_unprepare(glue->clk);
usb_put_phy(musb->xceiv);
return 0;
}
static inline u8 get_vbus_power(struct device *dev)
{
struct regulator *vbus_supply;
int current_uA;
vbus_supply = regulator_get_optional(dev, "vbus");
if (IS_ERR(vbus_supply))
return 255;
current_uA = regulator_get_current_limit(vbus_supply);
regulator_put(vbus_supply);
if (current_uA <= 0 || current_uA > 510000)
return 255;
return current_uA / 1000 / 2;
}
static void da8xx_dma_controller_callback(struct dma_controller *c)
{
struct musb *musb = c->musb;
void __iomem *reg_base = musb->ctrl_base;
musb_writel(reg_base, DA8XX_USB_END_OF_INTR_REG, 0);
}
static struct dma_controller *
da8xx_dma_controller_create(struct musb *musb, void __iomem *base)
{
struct dma_controller *controller;
controller = cppi41_dma_controller_create(musb, base);
if (IS_ERR_OR_NULL(controller))
return controller;
controller->dma_callback = da8xx_dma_controller_callback;
return controller;
}
static int da8xx_probe(struct platform_device *pdev)
{
struct resource musb_resources[2];
struct musb_hdrc_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct da8xx_glue *glue;
struct platform_device_info pinfo;
struct clk *clk;
struct device_node *np = pdev->dev.of_node;
int ret;
glue = devm_kzalloc(&pdev->dev, sizeof(*glue), GFP_KERNEL);
if (!glue)
return -ENOMEM;
clk = devm_clk_get(&pdev->dev, "usb20");
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "failed to get clock\n");
return PTR_ERR(clk);
}
glue->phy = devm_phy_get(&pdev->dev, "usb-phy");
if (IS_ERR(glue->phy)) {
if (PTR_ERR(glue->phy) != -EPROBE_DEFER)
dev_err(&pdev->dev, "failed to get phy\n");
return PTR_ERR(glue->phy);
}
glue->dev = &pdev->dev;
glue->clk = clk;
if (IS_ENABLED(CONFIG_OF) && np) {
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
pdata->config = &da8xx_config;
pdata->mode = musb_get_mode(&pdev->dev);
pdata->power = get_vbus_power(&pdev->dev);
}
pdata->platform_ops = &da8xx_ops;
glue->usb_phy = usb_phy_generic_register();
ret = PTR_ERR_OR_ZERO(glue->usb_phy);
if (ret) {
dev_err(&pdev->dev, "failed to register usb_phy\n");
return ret;
}
platform_set_drvdata(pdev, glue);
ret = of_platform_populate(pdev->dev.of_node, NULL,
da8xx_auxdata_lookup, &pdev->dev);
if (ret)
return ret;
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
glue->musb = platform_device_register_full(&pinfo);
ret = PTR_ERR_OR_ZERO(glue->musb);
if (ret) {
dev_err(&pdev->dev, "failed to register musb device: %d\n", ret);
usb_phy_generic_unregister(glue->usb_phy);
}
return ret;
}
static int da8xx_remove(struct platform_device *pdev)
{
struct da8xx_glue *glue = platform_get_drvdata(pdev);
platform_device_unregister(glue->musb);
usb_phy_generic_unregister(glue->usb_phy);
return 0;
}
static int da8xx_suspend(struct device *dev)
{
int ret;
struct da8xx_glue *glue = dev_get_drvdata(dev);
ret = phy_power_off(glue->phy);
if (ret)
return ret;
clk_disable_unprepare(glue->clk);
return 0;
}
static int da8xx_resume(struct device *dev)
{
int ret;
struct da8xx_glue *glue = dev_get_drvdata(dev);
ret = clk_prepare_enable(glue->clk);
if (ret)
return ret;
return phy_power_on(glue->phy);
}
