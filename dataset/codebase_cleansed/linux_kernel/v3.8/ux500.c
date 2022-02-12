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
musb->xceiv = usb_get_phy(USB_PHY_TYPE_USB2);
if (IS_ERR_OR_NULL(musb->xceiv)) {
pr_err("HS USB OTG: no transceiver configured\n");
return -ENODEV;
}
musb->isr = ux500_musb_interrupt;
return 0;
}
static int ux500_musb_exit(struct musb *musb)
{
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
ret = clk_enable(clk);
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
clk_disable(clk);
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
clk_disable(glue->clk);
clk_put(glue->clk);
kfree(glue);
return 0;
}
static int ux500_suspend(struct device *dev)
{
struct ux500_glue *glue = dev_get_drvdata(dev);
struct musb *musb = glue_to_musb(glue);
usb_phy_set_suspend(musb->xceiv, 1);
clk_disable(glue->clk);
return 0;
}
static int ux500_resume(struct device *dev)
{
struct ux500_glue *glue = dev_get_drvdata(dev);
struct musb *musb = glue_to_musb(glue);
int ret;
ret = clk_enable(glue->clk);
if (ret) {
dev_err(dev, "failed to enable clock\n");
return ret;
}
usb_phy_set_suspend(musb->xceiv, 0);
return 0;
}
