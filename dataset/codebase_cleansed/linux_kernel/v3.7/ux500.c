static int ux500_musb_init(struct musb *musb)
{
musb->xceiv = usb_get_phy(USB_PHY_TYPE_USB2);
if (IS_ERR_OR_NULL(musb->xceiv)) {
pr_err("HS USB OTG: no transceiver configured\n");
return -ENODEV;
}
return 0;
}
static int ux500_musb_exit(struct musb *musb)
{
usb_put_phy(musb->xceiv);
return 0;
}
static int __devinit ux500_probe(struct platform_device *pdev)
{
struct musb_hdrc_platform_data *pdata = pdev->dev.platform_data;
struct platform_device *musb;
struct ux500_glue *glue;
struct clk *clk;
int musbid;
int ret = -ENOMEM;
glue = kzalloc(sizeof(*glue), GFP_KERNEL);
if (!glue) {
dev_err(&pdev->dev, "failed to allocate glue context\n");
goto err0;
}
musbid = musb_get_id(&pdev->dev, GFP_KERNEL);
if (musbid < 0) {
dev_err(&pdev->dev, "failed to allocate musb id\n");
ret = -ENOMEM;
goto err1;
}
musb = platform_device_alloc("musb-hdrc", musbid);
if (!musb) {
dev_err(&pdev->dev, "failed to allocate musb device\n");
goto err2;
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
musb->id = musbid;
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
err2:
musb_put_id(&pdev->dev, musbid);
err1:
kfree(glue);
err0:
return ret;
}
static int __devexit ux500_remove(struct platform_device *pdev)
{
struct ux500_glue *glue = platform_get_drvdata(pdev);
musb_put_id(&pdev->dev, glue->musb->id);
platform_device_del(glue->musb);
platform_device_put(glue->musb);
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
static int __init ux500_init(void)
{
return platform_driver_register(&ux500_driver);
}
static void __exit ux500_exit(void)
{
platform_driver_unregister(&ux500_driver);
}
