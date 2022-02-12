void usb_nop_xceiv_register(void)
{
if (pd)
return;
pd = platform_device_register_simple("usb_phy_gen_xceiv", -1, NULL, 0);
if (IS_ERR(pd)) {
pr_err("Unable to register generic usb transceiver\n");
pd = NULL;
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
static void nop_reset_set(struct usb_phy_gen_xceiv *nop, int asserted)
{
int value;
if (!gpio_is_valid(nop->gpio_reset))
return;
value = asserted;
if (nop->reset_active_low)
value = !value;
gpio_set_value_cansleep(nop->gpio_reset, value);
if (!asserted)
usleep_range(10000, 20000);
}
int usb_gen_phy_init(struct usb_phy *phy)
{
struct usb_phy_gen_xceiv *nop = dev_get_drvdata(phy->dev);
if (!IS_ERR(nop->vcc)) {
if (regulator_enable(nop->vcc))
dev_err(phy->dev, "Failed to enable power\n");
}
if (!IS_ERR(nop->clk))
clk_prepare_enable(nop->clk);
nop_reset_set(nop, 0);
return 0;
}
void usb_gen_phy_shutdown(struct usb_phy *phy)
{
struct usb_phy_gen_xceiv *nop = dev_get_drvdata(phy->dev);
nop_reset_set(nop, 1);
if (!IS_ERR(nop->clk))
clk_disable_unprepare(nop->clk);
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
int usb_phy_gen_create_phy(struct device *dev, struct usb_phy_gen_xceiv *nop,
struct usb_phy_gen_xceiv_platform_data *pdata)
{
enum usb_phy_type type = USB_PHY_TYPE_USB2;
int err;
u32 clk_rate = 0;
bool needs_vcc = false;
nop->reset_active_low = true;
if (dev->of_node) {
struct device_node *node = dev->of_node;
enum of_gpio_flags flags = 0;
if (of_property_read_u32(node, "clock-frequency", &clk_rate))
clk_rate = 0;
needs_vcc = of_property_read_bool(node, "vcc-supply");
nop->gpio_reset = of_get_named_gpio_flags(node, "reset-gpios",
0, &flags);
if (nop->gpio_reset == -EPROBE_DEFER)
return -EPROBE_DEFER;
nop->reset_active_low = flags & OF_GPIO_ACTIVE_LOW;
} else if (pdata) {
type = pdata->type;
clk_rate = pdata->clk_rate;
needs_vcc = pdata->needs_vcc;
nop->gpio_reset = pdata->gpio_reset;
} else {
nop->gpio_reset = -1;
}
nop->phy.otg = devm_kzalloc(dev, sizeof(*nop->phy.otg),
GFP_KERNEL);
if (!nop->phy.otg)
return -ENOMEM;
nop->clk = devm_clk_get(dev, "main_clk");
if (IS_ERR(nop->clk)) {
dev_dbg(dev, "Can't get phy clock: %ld\n",
PTR_ERR(nop->clk));
}
if (!IS_ERR(nop->clk) && clk_rate) {
err = clk_set_rate(nop->clk, clk_rate);
if (err) {
dev_err(dev, "Error setting clock rate\n");
return err;
}
}
nop->vcc = devm_regulator_get(dev, "vcc");
if (IS_ERR(nop->vcc)) {
dev_dbg(dev, "Error getting vcc regulator: %ld\n",
PTR_ERR(nop->vcc));
if (needs_vcc)
return -EPROBE_DEFER;
}
if (gpio_is_valid(nop->gpio_reset)) {
unsigned long gpio_flags;
if (nop->reset_active_low)
gpio_flags = GPIOF_OUT_INIT_LOW;
else
gpio_flags = GPIOF_OUT_INIT_HIGH;
err = devm_gpio_request_one(dev, nop->gpio_reset,
gpio_flags, dev_name(dev));
if (err) {
dev_err(dev, "Error requesting RESET GPIO %d\n",
nop->gpio_reset);
return err;
}
}
nop->dev = dev;
nop->phy.dev = nop->dev;
nop->phy.label = "nop-xceiv";
nop->phy.set_suspend = nop_set_suspend;
nop->phy.state = OTG_STATE_UNDEFINED;
nop->phy.type = type;
nop->phy.otg->phy = &nop->phy;
nop->phy.otg->set_host = nop_set_host;
nop->phy.otg->set_peripheral = nop_set_peripheral;
ATOMIC_INIT_NOTIFIER_HEAD(&nop->phy.notifier);
return 0;
}
static int usb_phy_gen_xceiv_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct usb_phy_gen_xceiv *nop;
int err;
nop = devm_kzalloc(dev, sizeof(*nop), GFP_KERNEL);
if (!nop)
return -ENOMEM;
err = usb_phy_gen_create_phy(dev, nop, dev_get_platdata(&pdev->dev));
if (err)
return err;
nop->phy.init = usb_gen_phy_init;
nop->phy.shutdown = usb_gen_phy_shutdown;
err = usb_add_phy_dev(&nop->phy);
if (err) {
dev_err(&pdev->dev, "can't register transceiver, err: %d\n",
err);
return err;
}
platform_set_drvdata(pdev, nop);
return 0;
}
static int usb_phy_gen_xceiv_remove(struct platform_device *pdev)
{
struct usb_phy_gen_xceiv *nop = platform_get_drvdata(pdev);
usb_remove_phy(&nop->phy);
return 0;
}
static int __init usb_phy_gen_xceiv_init(void)
{
return platform_driver_register(&usb_phy_gen_xceiv_driver);
}
static void __exit usb_phy_gen_xceiv_exit(void)
{
platform_driver_unregister(&usb_phy_gen_xceiv_driver);
}
