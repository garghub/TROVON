void usb_nop_xceiv_register(void)
{
if (pd)
return;
pd = platform_device_register_simple("nop_usb_xceiv", -1, NULL, 0);
if (!pd) {
printk(KERN_ERR "Unable to register usb nop transceiver\n");
return;
}
}
void usb_nop_xceiv_unregister(void)
{
platform_device_unregister(pd);
pd = NULL;
}
static int nop_set_suspend(struct usb_phy *x, int suspend)
{
return 0;
}
static int nop_init(struct usb_phy *phy)
{
struct nop_usb_xceiv *nop = dev_get_drvdata(phy->dev);
if (!IS_ERR(nop->vcc)) {
if (regulator_enable(nop->vcc))
dev_err(phy->dev, "Failed to enable power\n");
}
if (!IS_ERR(nop->clk))
clk_enable(nop->clk);
if (!IS_ERR(nop->reset)) {
if (regulator_enable(nop->reset))
dev_err(phy->dev, "Failed to de-assert reset\n");
}
return 0;
}
static void nop_shutdown(struct usb_phy *phy)
{
struct nop_usb_xceiv *nop = dev_get_drvdata(phy->dev);
if (!IS_ERR(nop->reset)) {
if (regulator_disable(nop->reset))
dev_err(phy->dev, "Failed to assert reset\n");
}
if (!IS_ERR(nop->clk))
clk_disable(nop->clk);
if (!IS_ERR(nop->vcc)) {
if (regulator_disable(nop->vcc))
dev_err(phy->dev, "Failed to disable power\n");
}
}
static int nop_set_peripheral(struct usb_otg *otg, struct usb_gadget *gadget)
{
if (!otg)
return -ENODEV;
if (!gadget) {
otg->gadget = NULL;
return -ENODEV;
}
otg->gadget = gadget;
otg->phy->state = OTG_STATE_B_IDLE;
return 0;
}
static int nop_set_host(struct usb_otg *otg, struct usb_bus *host)
{
if (!otg)
return -ENODEV;
if (!host) {
otg->host = NULL;
return -ENODEV;
}
otg->host = host;
return 0;
}
static int nop_usb_xceiv_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct nop_usb_xceiv_platform_data *pdata = pdev->dev.platform_data;
struct nop_usb_xceiv *nop;
enum usb_phy_type type = USB_PHY_TYPE_USB2;
int err;
u32 clk_rate = 0;
bool needs_vcc = false;
bool needs_reset = false;
nop = devm_kzalloc(&pdev->dev, sizeof(*nop), GFP_KERNEL);
if (!nop)
return -ENOMEM;
nop->phy.otg = devm_kzalloc(&pdev->dev, sizeof(*nop->phy.otg),
GFP_KERNEL);
if (!nop->phy.otg)
return -ENOMEM;
if (dev->of_node) {
struct device_node *node = dev->of_node;
if (of_property_read_u32(node, "clock-frequency", &clk_rate))
clk_rate = 0;
needs_vcc = of_property_read_bool(node, "vcc-supply");
needs_reset = of_property_read_bool(node, "reset-supply");
} else if (pdata) {
type = pdata->type;
clk_rate = pdata->clk_rate;
needs_vcc = pdata->needs_vcc;
needs_reset = pdata->needs_reset;
}
nop->clk = devm_clk_get(&pdev->dev, "main_clk");
if (IS_ERR(nop->clk)) {
dev_dbg(&pdev->dev, "Can't get phy clock: %ld\n",
PTR_ERR(nop->clk));
}
if (!IS_ERR(nop->clk) && clk_rate) {
err = clk_set_rate(nop->clk, clk_rate);
if (err) {
dev_err(&pdev->dev, "Error setting clock rate\n");
return err;
}
}
if (!IS_ERR(nop->clk)) {
err = clk_prepare(nop->clk);
if (err) {
dev_err(&pdev->dev, "Error preparing clock\n");
return err;
}
}
nop->vcc = devm_regulator_get(&pdev->dev, "vcc");
if (IS_ERR(nop->vcc)) {
dev_dbg(&pdev->dev, "Error getting vcc regulator: %ld\n",
PTR_ERR(nop->vcc));
if (needs_vcc)
return -EPROBE_DEFER;
}
nop->reset = devm_regulator_get(&pdev->dev, "reset");
if (IS_ERR(nop->reset)) {
dev_dbg(&pdev->dev, "Error getting reset regulator: %ld\n",
PTR_ERR(nop->reset));
if (needs_reset)
return -EPROBE_DEFER;
}
nop->dev = &pdev->dev;
nop->phy.dev = nop->dev;
nop->phy.label = "nop-xceiv";
nop->phy.set_suspend = nop_set_suspend;
nop->phy.init = nop_init;
nop->phy.shutdown = nop_shutdown;
nop->phy.state = OTG_STATE_UNDEFINED;
nop->phy.type = type;
nop->phy.otg->phy = &nop->phy;
nop->phy.otg->set_host = nop_set_host;
nop->phy.otg->set_peripheral = nop_set_peripheral;
err = usb_add_phy_dev(&nop->phy);
if (err) {
dev_err(&pdev->dev, "can't register transceiver, err: %d\n",
err);
goto err_add;
}
platform_set_drvdata(pdev, nop);
ATOMIC_INIT_NOTIFIER_HEAD(&nop->phy.notifier);
return 0;
err_add:
if (!IS_ERR(nop->clk))
clk_unprepare(nop->clk);
return err;
}
static int nop_usb_xceiv_remove(struct platform_device *pdev)
{
struct nop_usb_xceiv *nop = platform_get_drvdata(pdev);
if (!IS_ERR(nop->clk))
clk_unprepare(nop->clk);
usb_remove_phy(&nop->phy);
return 0;
}
static int __init nop_usb_xceiv_init(void)
{
return platform_driver_register(&nop_usb_xceiv_driver);
}
static void __exit nop_usb_xceiv_exit(void)
{
platform_driver_unregister(&nop_usb_xceiv_driver);
}
