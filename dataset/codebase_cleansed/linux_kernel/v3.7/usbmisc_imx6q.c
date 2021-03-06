static struct usbmisc_usb_device *get_usbdev(struct device *dev)
{
int i, ret;
for (i = 0; i < USB_DEV_MAX; i++) {
if (usbmisc->usbdev[i].dev == dev)
return &usbmisc->usbdev[i];
else if (!usbmisc->usbdev[i].dev)
break;
}
if (i >= USB_DEV_MAX)
return ERR_PTR(-EBUSY);
ret = usbmisc_get_init_data(dev, &usbmisc->usbdev[i]);
if (ret)
return ERR_PTR(ret);
return &usbmisc->usbdev[i];
}
static int usbmisc_imx6q_init(struct device *dev)
{
struct usbmisc_usb_device *usbdev;
unsigned long flags;
u32 reg;
usbdev = get_usbdev(dev);
if (IS_ERR(usbdev))
return PTR_ERR(usbdev);
if (usbdev->disable_oc) {
spin_lock_irqsave(&usbmisc->lock, flags);
reg = readl(usbmisc->base + usbdev->index * 4);
writel(reg | BM_OVER_CUR_DIS,
usbmisc->base + usbdev->index * 4);
spin_unlock_irqrestore(&usbmisc->lock, flags);
}
return 0;
}
static int __devinit usbmisc_imx6q_probe(struct platform_device *pdev)
{
struct resource *res;
struct imx6q_usbmisc *data;
int ret;
if (usbmisc)
return -EBUSY;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
spin_lock_init(&data->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->base = devm_request_and_ioremap(&pdev->dev, res);
if (!data->base)
return -EADDRNOTAVAIL;
data->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(data->clk)) {
dev_err(&pdev->dev,
"failed to get clock, err=%ld\n", PTR_ERR(data->clk));
return PTR_ERR(data->clk);
}
ret = clk_prepare_enable(data->clk);
if (ret) {
dev_err(&pdev->dev,
"clk_prepare_enable failed, err=%d\n", ret);
return ret;
}
ret = usbmisc_set_ops(&imx6q_usbmisc_ops);
if (ret) {
clk_disable_unprepare(data->clk);
return ret;
}
usbmisc = data;
return 0;
}
static int __devexit usbmisc_imx6q_remove(struct platform_device *pdev)
{
usbmisc_unset_ops(&imx6q_usbmisc_ops);
clk_disable_unprepare(usbmisc->clk);
return 0;
}
int __init usbmisc_imx6q_drv_init(void)
{
return platform_driver_register(&usbmisc_imx6q_driver);
}
void __exit usbmisc_imx6q_drv_exit(void)
{
platform_driver_unregister(&usbmisc_imx6q_driver);
}
