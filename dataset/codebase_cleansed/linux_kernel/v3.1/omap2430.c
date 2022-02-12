static void musb_do_idle(unsigned long _musb)
{
struct musb *musb = (void *)_musb;
unsigned long flags;
u8 power;
u8 devctl;
spin_lock_irqsave(&musb->lock, flags);
switch (musb->xceiv->state) {
case OTG_STATE_A_WAIT_BCON:
devctl = musb_readb(musb->mregs, MUSB_DEVCTL);
if (devctl & MUSB_DEVCTL_BDEVICE) {
musb->xceiv->state = OTG_STATE_B_IDLE;
MUSB_DEV_MODE(musb);
} else {
musb->xceiv->state = OTG_STATE_A_IDLE;
MUSB_HST_MODE(musb);
}
break;
case OTG_STATE_A_SUSPEND:
if (musb->port1_status & MUSB_PORT_STAT_RESUME) {
power = musb_readb(musb->mregs, MUSB_POWER);
power &= ~MUSB_POWER_RESUME;
dev_dbg(musb->controller, "root port resume stopped, power %02x\n", power);
musb_writeb(musb->mregs, MUSB_POWER, power);
musb->is_active = 1;
musb->port1_status &= ~(USB_PORT_STAT_SUSPEND
| MUSB_PORT_STAT_RESUME);
musb->port1_status |= USB_PORT_STAT_C_SUSPEND << 16;
usb_hcd_poll_rh_status(musb_to_hcd(musb));
musb->xceiv->state = OTG_STATE_A_HOST;
}
break;
case OTG_STATE_A_HOST:
devctl = musb_readb(musb->mregs, MUSB_DEVCTL);
if (devctl & MUSB_DEVCTL_BDEVICE)
musb->xceiv->state = OTG_STATE_B_IDLE;
else
musb->xceiv->state = OTG_STATE_A_WAIT_BCON;
default:
break;
}
spin_unlock_irqrestore(&musb->lock, flags);
}
static void omap2430_musb_try_idle(struct musb *musb, unsigned long timeout)
{
unsigned long default_timeout = jiffies + msecs_to_jiffies(3);
static unsigned long last_timer;
if (timeout == 0)
timeout = default_timeout;
if (musb->is_active || ((musb->a_wait_bcon == 0)
&& (musb->xceiv->state == OTG_STATE_A_WAIT_BCON))) {
dev_dbg(musb->controller, "%s active, deleting timer\n",
otg_state_string(musb->xceiv->state));
del_timer(&musb_idle_timer);
last_timer = jiffies;
return;
}
if (time_after(last_timer, timeout)) {
if (!timer_pending(&musb_idle_timer))
last_timer = timeout;
else {
dev_dbg(musb->controller, "Longer idle timer already pending, ignoring\n");
return;
}
}
last_timer = timeout;
dev_dbg(musb->controller, "%s inactive, for idle timer for %lu ms\n",
otg_state_string(musb->xceiv->state),
(unsigned long)jiffies_to_msecs(timeout - jiffies));
mod_timer(&musb_idle_timer, timeout);
}
static void omap2430_musb_set_vbus(struct musb *musb, int is_on)
{
u8 devctl;
unsigned long timeout = jiffies + msecs_to_jiffies(1000);
int ret = 1;
devctl = musb_readb(musb->mregs, MUSB_DEVCTL);
if (is_on) {
if (musb->xceiv->state == OTG_STATE_A_IDLE) {
devctl |= MUSB_DEVCTL_SESSION;
musb_writeb(musb->mregs, MUSB_DEVCTL, devctl);
while (musb_readb(musb->mregs, MUSB_DEVCTL) & 0x80) {
cpu_relax();
if (time_after(jiffies, timeout)) {
dev_err(musb->controller,
"configured as A device timeout");
ret = -EINVAL;
break;
}
}
if (ret && musb->xceiv->set_vbus)
otg_set_vbus(musb->xceiv, 1);
} else {
musb->is_active = 1;
musb->xceiv->default_a = 1;
musb->xceiv->state = OTG_STATE_A_WAIT_VRISE;
devctl |= MUSB_DEVCTL_SESSION;
MUSB_HST_MODE(musb);
}
} else {
musb->is_active = 0;
musb->xceiv->default_a = 0;
musb->xceiv->state = OTG_STATE_B_IDLE;
devctl &= ~MUSB_DEVCTL_SESSION;
MUSB_DEV_MODE(musb);
}
musb_writeb(musb->mregs, MUSB_DEVCTL, devctl);
dev_dbg(musb->controller, "VBUS %s, devctl %02x "
"\n",
otg_state_string(musb->xceiv->state),
musb_readb(musb->mregs, MUSB_DEVCTL));
}
static int omap2430_musb_set_mode(struct musb *musb, u8 musb_mode)
{
u8 devctl = musb_readb(musb->mregs, MUSB_DEVCTL);
devctl |= MUSB_DEVCTL_SESSION;
musb_writeb(musb->mregs, MUSB_DEVCTL, devctl);
return 0;
}
static inline void omap2430_low_level_exit(struct musb *musb)
{
u32 l;
l = musb_readl(musb->mregs, OTG_FORCESTDBY);
l |= ENABLEFORCE;
musb_writel(musb->mregs, OTG_FORCESTDBY, l);
}
static inline void omap2430_low_level_init(struct musb *musb)
{
u32 l;
l = musb_readl(musb->mregs, OTG_FORCESTDBY);
l &= ~ENABLEFORCE;
musb_writel(musb->mregs, OTG_FORCESTDBY, l);
}
static int musb_otg_notifications(struct notifier_block *nb,
unsigned long event, void *unused)
{
struct musb *musb = container_of(nb, struct musb, nb);
struct device *dev = musb->controller;
struct musb_hdrc_platform_data *pdata = dev->platform_data;
struct omap_musb_board_data *data = pdata->board_data;
switch (event) {
case USB_EVENT_ID:
dev_dbg(musb->controller, "ID GND\n");
if (is_otg_enabled(musb)) {
if (musb->gadget_driver) {
pm_runtime_get_sync(musb->controller);
otg_init(musb->xceiv);
omap2430_musb_set_vbus(musb, 1);
}
} else {
pm_runtime_get_sync(musb->controller);
otg_init(musb->xceiv);
omap2430_musb_set_vbus(musb, 1);
}
break;
case USB_EVENT_VBUS:
dev_dbg(musb->controller, "VBUS Connect\n");
if (musb->gadget_driver)
pm_runtime_get_sync(musb->controller);
otg_init(musb->xceiv);
break;
case USB_EVENT_NONE:
dev_dbg(musb->controller, "VBUS Disconnect\n");
if (is_otg_enabled(musb) || is_peripheral_enabled(musb))
if (musb->gadget_driver) {
pm_runtime_mark_last_busy(musb->controller);
pm_runtime_put_autosuspend(musb->controller);
}
if (data->interface_type == MUSB_INTERFACE_UTMI) {
if (musb->xceiv->set_vbus)
otg_set_vbus(musb->xceiv, 0);
}
otg_shutdown(musb->xceiv);
break;
default:
dev_dbg(musb->controller, "ID float\n");
return NOTIFY_DONE;
}
return NOTIFY_OK;
}
static int omap2430_musb_init(struct musb *musb)
{
u32 l, status = 0;
struct device *dev = musb->controller;
struct musb_hdrc_platform_data *plat = dev->platform_data;
struct omap_musb_board_data *data = plat->board_data;
musb->xceiv = otg_get_transceiver();
if (!musb->xceiv) {
pr_err("HS USB OTG: no transceiver configured\n");
return -ENODEV;
}
status = pm_runtime_get_sync(dev);
if (status < 0) {
dev_err(dev, "pm_runtime_get_sync FAILED");
goto err1;
}
l = musb_readl(musb->mregs, OTG_INTERFSEL);
if (data->interface_type == MUSB_INTERFACE_UTMI) {
l &= ~ULPI_12PIN;
l |= UTMI_8BIT;
} else {
l |= ULPI_12PIN;
}
musb_writel(musb->mregs, OTG_INTERFSEL, l);
pr_debug("HS USB OTG: revision 0x%x, sysconfig 0x%02x, "
"sysstatus 0x%x, intrfsel 0x%x, simenable 0x%x\n",
musb_readl(musb->mregs, OTG_REVISION),
musb_readl(musb->mregs, OTG_SYSCONFIG),
musb_readl(musb->mregs, OTG_SYSSTATUS),
musb_readl(musb->mregs, OTG_INTERFSEL),
musb_readl(musb->mregs, OTG_SIMENABLE));
musb->nb.notifier_call = musb_otg_notifications;
status = otg_register_notifier(musb->xceiv, &musb->nb);
if (status)
dev_dbg(musb->controller, "notification register failed\n");
setup_timer(&musb_idle_timer, musb_do_idle, (unsigned long) musb);
return 0;
err1:
pm_runtime_disable(dev);
return status;
}
static void omap2430_musb_enable(struct musb *musb)
{
u8 devctl;
unsigned long timeout = jiffies + msecs_to_jiffies(1000);
struct device *dev = musb->controller;
struct musb_hdrc_platform_data *pdata = dev->platform_data;
struct omap_musb_board_data *data = pdata->board_data;
switch (musb->xceiv->last_event) {
case USB_EVENT_ID:
otg_init(musb->xceiv);
if (data->interface_type == MUSB_INTERFACE_UTMI) {
devctl = musb_readb(musb->mregs, MUSB_DEVCTL);
devctl |= MUSB_DEVCTL_SESSION;
musb_writeb(musb->mregs, MUSB_DEVCTL, devctl);
while (musb_readb(musb->mregs, MUSB_DEVCTL) &
MUSB_DEVCTL_BDEVICE) {
cpu_relax();
if (time_after(jiffies, timeout)) {
dev_err(musb->controller,
"configured as A device timeout");
break;
}
}
}
break;
case USB_EVENT_VBUS:
otg_init(musb->xceiv);
break;
default:
break;
}
}
static void omap2430_musb_disable(struct musb *musb)
{
if (musb->xceiv->last_event)
otg_shutdown(musb->xceiv);
}
static int omap2430_musb_exit(struct musb *musb)
{
del_timer_sync(&musb_idle_timer);
omap2430_low_level_exit(musb);
otg_put_transceiver(musb->xceiv);
return 0;
}
static int __init omap2430_probe(struct platform_device *pdev)
{
struct musb_hdrc_platform_data *pdata = pdev->dev.platform_data;
struct platform_device *musb;
struct omap2430_glue *glue;
int ret = -ENOMEM;
glue = kzalloc(sizeof(*glue), GFP_KERNEL);
if (!glue) {
dev_err(&pdev->dev, "failed to allocate glue context\n");
goto err0;
}
musb = platform_device_alloc("musb-hdrc", -1);
if (!musb) {
dev_err(&pdev->dev, "failed to allocate musb device\n");
goto err1;
}
musb->dev.parent = &pdev->dev;
musb->dev.dma_mask = &omap2430_dmamask;
musb->dev.coherent_dma_mask = omap2430_dmamask;
glue->dev = &pdev->dev;
glue->musb = musb;
pdata->platform_ops = &omap2430_ops;
platform_set_drvdata(pdev, glue);
ret = platform_device_add_resources(musb, pdev->resource,
pdev->num_resources);
if (ret) {
dev_err(&pdev->dev, "failed to add resources\n");
goto err2;
}
ret = platform_device_add_data(musb, pdata, sizeof(*pdata));
if (ret) {
dev_err(&pdev->dev, "failed to add platform_data\n");
goto err2;
}
ret = platform_device_add(musb);
if (ret) {
dev_err(&pdev->dev, "failed to register musb device\n");
goto err2;
}
pm_runtime_enable(&pdev->dev);
return 0;
err2:
platform_device_put(musb);
err1:
kfree(glue);
err0:
return ret;
}
static int __exit omap2430_remove(struct platform_device *pdev)
{
struct omap2430_glue *glue = platform_get_drvdata(pdev);
platform_device_del(glue->musb);
platform_device_put(glue->musb);
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
kfree(glue);
return 0;
}
static int omap2430_runtime_suspend(struct device *dev)
{
struct omap2430_glue *glue = dev_get_drvdata(dev);
struct musb *musb = glue_to_musb(glue);
omap2430_low_level_exit(musb);
otg_set_suspend(musb->xceiv, 1);
return 0;
}
static int omap2430_runtime_resume(struct device *dev)
{
struct omap2430_glue *glue = dev_get_drvdata(dev);
struct musb *musb = glue_to_musb(glue);
omap2430_low_level_init(musb);
otg_set_suspend(musb->xceiv, 0);
return 0;
}
static int __init omap2430_init(void)
{
return platform_driver_probe(&omap2430_driver, omap2430_probe);
}
static void __exit omap2430_exit(void)
{
platform_driver_unregister(&omap2430_driver);
}
