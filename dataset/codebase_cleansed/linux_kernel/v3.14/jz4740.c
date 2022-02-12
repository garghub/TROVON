static irqreturn_t jz4740_musb_interrupt(int irq, void *__hci)
{
unsigned long flags;
irqreturn_t retval = IRQ_NONE;
struct musb *musb = __hci;
spin_lock_irqsave(&musb->lock, flags);
musb->int_usb = musb_readb(musb->mregs, MUSB_INTRUSB);
musb->int_tx = musb_readw(musb->mregs, MUSB_INTRTX);
musb->int_rx = musb_readw(musb->mregs, MUSB_INTRRX);
musb->int_usb &= MUSB_INTR_SUSPEND | MUSB_INTR_RESUME |
MUSB_INTR_RESET | MUSB_INTR_SOF;
if (musb->int_usb || musb->int_tx || musb->int_rx)
retval = musb_interrupt(musb);
spin_unlock_irqrestore(&musb->lock, flags);
return retval;
}
static int jz4740_musb_init(struct musb *musb)
{
musb->xceiv = usb_get_phy(USB_PHY_TYPE_USB2);
if (!musb->xceiv) {
pr_err("HS UDC: no transceiver configured\n");
return -ENODEV;
}
musb->dyn_fifo = true;
musb->isr = jz4740_musb_interrupt;
return 0;
}
static int jz4740_musb_exit(struct musb *musb)
{
usb_put_phy(musb->xceiv);
return 0;
}
static int jz4740_probe(struct platform_device *pdev)
{
struct musb_hdrc_platform_data *pdata = &jz4740_musb_platform_data;
struct platform_device *musb;
struct jz4740_glue *glue;
struct clk *clk;
int ret;
glue = devm_kzalloc(&pdev->dev, sizeof(*glue), GFP_KERNEL);
if (!glue)
return -ENOMEM;
musb = platform_device_alloc("musb-hdrc", PLATFORM_DEVID_AUTO);
if (!musb) {
dev_err(&pdev->dev, "failed to allocate musb device\n");
return -ENOMEM;
}
clk = devm_clk_get(&pdev->dev, "udc");
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "failed to get clock\n");
ret = PTR_ERR(clk);
goto err_platform_device_put;
}
ret = clk_prepare_enable(clk);
if (ret) {
dev_err(&pdev->dev, "failed to enable clock\n");
goto err_platform_device_put;
}
musb->dev.parent = &pdev->dev;
glue->dev = &pdev->dev;
glue->musb = musb;
glue->clk = clk;
pdata->platform_ops = &jz4740_musb_ops;
platform_set_drvdata(pdev, glue);
ret = platform_device_add_resources(musb, pdev->resource,
pdev->num_resources);
if (ret) {
dev_err(&pdev->dev, "failed to add resources\n");
goto err_clk_disable;
}
ret = platform_device_add_data(musb, pdata, sizeof(*pdata));
if (ret) {
dev_err(&pdev->dev, "failed to add platform_data\n");
goto err_clk_disable;
}
ret = platform_device_add(musb);
if (ret) {
dev_err(&pdev->dev, "failed to register musb device\n");
goto err_clk_disable;
}
return 0;
err_clk_disable:
clk_disable_unprepare(clk);
err_platform_device_put:
platform_device_put(musb);
return ret;
}
static int jz4740_remove(struct platform_device *pdev)
{
struct jz4740_glue *glue = platform_get_drvdata(pdev);
platform_device_unregister(glue->musb);
clk_disable_unprepare(glue->clk);
return 0;
}
