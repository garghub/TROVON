static int mxs_phy_hw_init(struct mxs_phy *mxs_phy)
{
int ret;
void __iomem *base = mxs_phy->phy.io_priv;
ret = stmp_reset_block(base + HW_USBPHY_CTRL);
if (ret)
return ret;
writel(0, base + HW_USBPHY_PWD);
writel(BM_USBPHY_CTRL_ENUTMILEVEL2 |
BM_USBPHY_CTRL_ENUTMILEVEL3,
base + HW_USBPHY_CTRL_SET);
return 0;
}
static int mxs_phy_init(struct usb_phy *phy)
{
struct mxs_phy *mxs_phy = to_mxs_phy(phy);
clk_prepare_enable(mxs_phy->clk);
return mxs_phy_hw_init(mxs_phy);
}
static void mxs_phy_shutdown(struct usb_phy *phy)
{
struct mxs_phy *mxs_phy = to_mxs_phy(phy);
writel(BM_USBPHY_CTRL_CLKGATE,
phy->io_priv + HW_USBPHY_CTRL_SET);
clk_disable_unprepare(mxs_phy->clk);
}
static int mxs_phy_suspend(struct usb_phy *x, int suspend)
{
struct mxs_phy *mxs_phy = to_mxs_phy(x);
if (suspend) {
writel(0xffffffff, x->io_priv + HW_USBPHY_PWD);
writel(BM_USBPHY_CTRL_CLKGATE,
x->io_priv + HW_USBPHY_CTRL_SET);
clk_disable_unprepare(mxs_phy->clk);
} else {
clk_prepare_enable(mxs_phy->clk);
writel(BM_USBPHY_CTRL_CLKGATE,
x->io_priv + HW_USBPHY_CTRL_CLR);
writel(0, x->io_priv + HW_USBPHY_PWD);
}
return 0;
}
static int mxs_phy_on_connect(struct usb_phy *phy,
enum usb_device_speed speed)
{
dev_dbg(phy->dev, "%s speed device has connected\n",
(speed == USB_SPEED_HIGH) ? "high" : "non-high");
if (speed == USB_SPEED_HIGH)
writel(BM_USBPHY_CTRL_ENHOSTDISCONDETECT,
phy->io_priv + HW_USBPHY_CTRL_SET);
return 0;
}
static int mxs_phy_on_disconnect(struct usb_phy *phy,
enum usb_device_speed speed)
{
dev_dbg(phy->dev, "%s speed device has disconnected\n",
(speed == USB_SPEED_HIGH) ? "high" : "non-high");
if (speed == USB_SPEED_HIGH)
writel(BM_USBPHY_CTRL_ENHOSTDISCONDETECT,
phy->io_priv + HW_USBPHY_CTRL_CLR);
return 0;
}
static int mxs_phy_probe(struct platform_device *pdev)
{
struct resource *res;
void __iomem *base;
struct clk *clk;
struct mxs_phy *mxs_phy;
int ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
dev_err(&pdev->dev,
"can't get the clock, err=%ld", PTR_ERR(clk));
return PTR_ERR(clk);
}
mxs_phy = devm_kzalloc(&pdev->dev, sizeof(*mxs_phy), GFP_KERNEL);
if (!mxs_phy) {
dev_err(&pdev->dev, "Failed to allocate USB PHY structure!\n");
return -ENOMEM;
}
mxs_phy->phy.io_priv = base;
mxs_phy->phy.dev = &pdev->dev;
mxs_phy->phy.label = DRIVER_NAME;
mxs_phy->phy.init = mxs_phy_init;
mxs_phy->phy.shutdown = mxs_phy_shutdown;
mxs_phy->phy.set_suspend = mxs_phy_suspend;
mxs_phy->phy.notify_connect = mxs_phy_on_connect;
mxs_phy->phy.notify_disconnect = mxs_phy_on_disconnect;
mxs_phy->phy.type = USB_PHY_TYPE_USB2;
ATOMIC_INIT_NOTIFIER_HEAD(&mxs_phy->phy.notifier);
mxs_phy->clk = clk;
platform_set_drvdata(pdev, mxs_phy);
ret = usb_add_phy_dev(&mxs_phy->phy);
if (ret)
return ret;
return 0;
}
static int mxs_phy_remove(struct platform_device *pdev)
{
struct mxs_phy *mxs_phy = platform_get_drvdata(pdev);
usb_remove_phy(&mxs_phy->phy);
return 0;
}
static int __init mxs_phy_module_init(void)
{
return platform_driver_register(&mxs_phy_driver);
}
static void __exit mxs_phy_module_exit(void)
{
platform_driver_unregister(&mxs_phy_driver);
}
