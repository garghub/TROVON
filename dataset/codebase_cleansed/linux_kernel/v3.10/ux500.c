static void ux500_musb_set_vbus(struct musb *musb, int is_on)
{
u8 devctl;
unsigned long timeout = jiffies + msecs_to_jiffies(1000);
devctl = musb_readb(musb->mregs, MUSB_DEVCTL);
if (is_on) {
if (musb->xceiv->state == OTG_STATE_A_IDLE) {
devctl |= MUSB_DEVCTL_SESSION;
musb_writeb(musb->mregs, MUSB_DEVCTL, devctl);
while (musb_readb(musb->mregs, MUSB_DEVCTL) & 0x80) {
if (time_after(jiffies, timeout)) {
dev_err(musb->controller,
"configured as A device timeout");
break;
}
}
} else {
musb->is_active = 1;
musb->xceiv->otg->default_a = 1;
musb->xceiv->state = OTG_STATE_A_WAIT_VRISE;
devctl |= MUSB_DEVCTL_SESSION;
MUSB_HST_MODE(musb);
}
} else {
musb->is_active = 0;
musb->xceiv->otg->default_a = 0;
devctl &= ~MUSB_DEVCTL_SESSION;
MUSB_DEV_MODE(musb);
}
musb_writeb(musb->mregs, MUSB_DEVCTL, devctl);
if (!is_on)
mdelay(200);
dev_dbg(musb->controller, "VBUS %s, devctl %02x\n",
usb_otg_state_string(musb->xceiv->state),
musb_readb(musb->mregs, MUSB_DEVCTL));
}
static int musb_otg_notifications(struct notifier_block *nb,
unsigned long event, void *unused)
{
struct musb *musb = container_of(nb, struct musb, nb);
dev_dbg(musb->controller, "musb_otg_notifications %ld %s\n",
event, usb_otg_state_string(musb->xceiv->state));
switch (event) {
case UX500_MUSB_ID:
dev_dbg(musb->controller, "ID GND\n");
ux500_musb_set_vbus(musb, 1);
break;
case UX500_MUSB_VBUS:
dev_dbg(musb->controller, "VBUS Connect\n");
break;
case UX500_MUSB_NONE:
dev_dbg(musb->controller, "VBUS Disconnect\n");
if (is_host_active(musb))
ux500_musb_set_vbus(musb, 0);
else
musb->xceiv->state = OTG_STATE_B_IDLE;
break;
default:
dev_dbg(musb->controller, "ID float\n");
return NOTIFY_DONE;
}
return NOTIFY_OK;
}
static irqreturn_t ux500_musb_interrupt(int irq, void *__hci)
{
unsigned long flags;
irqreturn_t retval = IRQ_NONE;
struct musb *musb = __hci;
spin_lock_irqsave(&musb->lock, flags);
musb->int_usb = musb_readb(musb->mregs, MUSB_INTRUSB);
musb->int_tx = musb_readw(musb->mregs, MUSB_INTRTX);
musb->int_rx = musb_readw(musb->mregs, MUSB_INTRRX);
if (musb->int_usb || musb->int_tx || musb->int_rx)
retval = musb_interrupt(musb);
spin_unlock_irqrestore(&musb->lock, flags);
return retval;
}
static int ux500_musb_init(struct musb *musb)
{
int status;
musb->xceiv = usb_get_phy(USB_PHY_TYPE_USB2);
if (IS_ERR_OR_NULL(musb->xceiv)) {
pr_err("HS USB OTG: no transceiver configured\n");
return -EPROBE_DEFER;
}
musb->nb.notifier_call = musb_otg_notifications;
status = usb_register_notifier(musb->xceiv, &musb->nb);
if (status < 0) {
dev_dbg(musb->controller, "notification register failed\n");
return status;
}
musb->isr = ux500_musb_interrupt;
return 0;
}
static int ux500_musb_exit(struct musb *musb)
{
usb_unregister_notifier(musb->xceiv, &musb->nb);
usb_put_phy(musb->xceiv);
return 0;
}
static int ux500_probe(struct platform_device *pdev)
{
struct musb_hdrc_platform_data *pdata = pdev->dev.platform_data;
struct platform_device *musb;
struct ux500_glue *glue;
struct clk *clk;
int ret = -ENOMEM;
glue = kzalloc(sizeof(*glue), GFP_KERNEL);
if (!glue) {
dev_err(&pdev->dev, "failed to allocate glue context\n");
goto err0;
}
musb = platform_device_alloc("musb-hdrc", PLATFORM_DEVID_AUTO);
if (!musb) {
dev_err(&pdev->dev, "failed to allocate musb device\n");
goto err1;
}
clk = clk_get(&pdev->dev, "usb");
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "failed to get clock\n");
ret = PTR_ERR(clk);
goto err3;
}
ret = clk_prepare_enable(clk);
if (ret) {
dev_err(&pdev->dev, "failed to enable clock\n");
goto err4;
}
musb->dev.parent = &pdev->dev;
musb->dev.dma_mask = pdev->dev.dma_mask;
musb->dev.coherent_dma_mask = pdev->dev.coherent_dma_mask;
glue->dev = &pdev->dev;
glue->musb = musb;
glue->clk = clk;
pdata->platform_ops = &ux500_ops;
platform_set_drvdata(pdev, glue);
ret = platform_device_add_resources(musb, pdev->resource,
pdev->num_resources);
if (ret) {
dev_err(&pdev->dev, "failed to add resources\n");
goto err5;
}
ret = platform_device_add_data(musb, pdata, sizeof(*pdata));
if (ret) {
dev_err(&pdev->dev, "failed to add platform_data\n");
goto err5;
}
ret = platform_device_add(musb);
if (ret) {
dev_err(&pdev->dev, "failed to register musb device\n");
goto err5;
}
return 0;
err5:
clk_disable_unprepare(clk);
err4:
clk_put(clk);
err3:
platform_device_put(musb);
err1:
kfree(glue);
err0:
return ret;
}
static int ux500_remove(struct platform_device *pdev)
{
struct ux500_glue *glue = platform_get_drvdata(pdev);
platform_device_unregister(glue->musb);
clk_disable_unprepare(glue->clk);
clk_put(glue->clk);
kfree(glue);
return 0;
}
static int ux500_suspend(struct device *dev)
{
struct ux500_glue *glue = dev_get_drvdata(dev);
struct musb *musb = glue_to_musb(glue);
usb_phy_set_suspend(musb->xceiv, 1);
clk_disable_unprepare(glue->clk);
return 0;
}
static int ux500_resume(struct device *dev)
{
struct ux500_glue *glue = dev_get_drvdata(dev);
struct musb *musb = glue_to_musb(glue);
int ret;
ret = clk_prepare_enable(glue->clk);
if (ret) {
dev_err(dev, "failed to enable clock\n");
return ret;
}
usb_phy_set_suspend(musb->xceiv, 0);
return 0;
}
