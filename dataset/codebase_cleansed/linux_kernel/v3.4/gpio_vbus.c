static void set_vbus_draw(struct gpio_vbus_data *gpio_vbus, unsigned mA)
{
struct regulator *vbus_draw = gpio_vbus->vbus_draw;
int enabled;
if (!vbus_draw)
return;
enabled = gpio_vbus->vbus_draw_enabled;
if (mA) {
regulator_set_current_limit(vbus_draw, 0, 1000 * mA);
if (!enabled) {
regulator_enable(vbus_draw);
gpio_vbus->vbus_draw_enabled = 1;
}
} else {
if (enabled) {
regulator_disable(vbus_draw);
gpio_vbus->vbus_draw_enabled = 0;
}
}
gpio_vbus->mA = mA;
}
static int is_vbus_powered(struct gpio_vbus_mach_info *pdata)
{
int vbus;
vbus = gpio_get_value(pdata->gpio_vbus);
if (pdata->gpio_vbus_inverted)
vbus = !vbus;
return vbus;
}
static void gpio_vbus_work(struct work_struct *work)
{
struct gpio_vbus_data *gpio_vbus =
container_of(work, struct gpio_vbus_data, work);
struct gpio_vbus_mach_info *pdata = gpio_vbus->dev->platform_data;
int gpio, status;
if (!gpio_vbus->phy.otg->gadget)
return;
gpio = pdata->gpio_pullup;
if (is_vbus_powered(pdata)) {
status = USB_EVENT_VBUS;
gpio_vbus->phy.state = OTG_STATE_B_PERIPHERAL;
gpio_vbus->phy.last_event = status;
usb_gadget_vbus_connect(gpio_vbus->phy.otg->gadget);
set_vbus_draw(gpio_vbus, 100);
if (gpio_is_valid(gpio))
gpio_set_value(gpio, !pdata->gpio_pullup_inverted);
atomic_notifier_call_chain(&gpio_vbus->phy.notifier,
status, gpio_vbus->phy.otg->gadget);
} else {
if (gpio_is_valid(gpio))
gpio_set_value(gpio, pdata->gpio_pullup_inverted);
set_vbus_draw(gpio_vbus, 0);
usb_gadget_vbus_disconnect(gpio_vbus->phy.otg->gadget);
status = USB_EVENT_NONE;
gpio_vbus->phy.state = OTG_STATE_B_IDLE;
gpio_vbus->phy.last_event = status;
atomic_notifier_call_chain(&gpio_vbus->phy.notifier,
status, gpio_vbus->phy.otg->gadget);
}
}
static irqreturn_t gpio_vbus_irq(int irq, void *data)
{
struct platform_device *pdev = data;
struct gpio_vbus_mach_info *pdata = pdev->dev.platform_data;
struct gpio_vbus_data *gpio_vbus = platform_get_drvdata(pdev);
struct usb_otg *otg = gpio_vbus->phy.otg;
dev_dbg(&pdev->dev, "VBUS %s (gadget: %s)\n",
is_vbus_powered(pdata) ? "supplied" : "inactive",
otg->gadget ? otg->gadget->name : "none");
if (otg->gadget)
schedule_work(&gpio_vbus->work);
return IRQ_HANDLED;
}
static int gpio_vbus_set_peripheral(struct usb_otg *otg,
struct usb_gadget *gadget)
{
struct gpio_vbus_data *gpio_vbus;
struct gpio_vbus_mach_info *pdata;
struct platform_device *pdev;
int gpio, irq;
gpio_vbus = container_of(otg->phy, struct gpio_vbus_data, phy);
pdev = to_platform_device(gpio_vbus->dev);
pdata = gpio_vbus->dev->platform_data;
irq = gpio_to_irq(pdata->gpio_vbus);
gpio = pdata->gpio_pullup;
if (!gadget) {
dev_dbg(&pdev->dev, "unregistering gadget '%s'\n",
otg->gadget->name);
if (gpio_is_valid(gpio))
gpio_set_value(gpio, pdata->gpio_pullup_inverted);
set_vbus_draw(gpio_vbus, 0);
usb_gadget_vbus_disconnect(otg->gadget);
otg->phy->state = OTG_STATE_UNDEFINED;
otg->gadget = NULL;
return 0;
}
otg->gadget = gadget;
dev_dbg(&pdev->dev, "registered gadget '%s'\n", gadget->name);
gpio_vbus_irq(irq, pdev);
return 0;
}
static int gpio_vbus_set_power(struct usb_phy *phy, unsigned mA)
{
struct gpio_vbus_data *gpio_vbus;
gpio_vbus = container_of(phy, struct gpio_vbus_data, phy);
if (phy->state == OTG_STATE_B_PERIPHERAL)
set_vbus_draw(gpio_vbus, mA);
return 0;
}
static int gpio_vbus_set_suspend(struct usb_phy *phy, int suspend)
{
struct gpio_vbus_data *gpio_vbus;
gpio_vbus = container_of(phy, struct gpio_vbus_data, phy);
return gpio_vbus_set_power(phy, suspend ? 0 : gpio_vbus->mA);
}
static int __init gpio_vbus_probe(struct platform_device *pdev)
{
struct gpio_vbus_mach_info *pdata = pdev->dev.platform_data;
struct gpio_vbus_data *gpio_vbus;
struct resource *res;
int err, gpio, irq;
if (!pdata || !gpio_is_valid(pdata->gpio_vbus))
return -EINVAL;
gpio = pdata->gpio_vbus;
gpio_vbus = kzalloc(sizeof(struct gpio_vbus_data), GFP_KERNEL);
if (!gpio_vbus)
return -ENOMEM;
gpio_vbus->phy.otg = kzalloc(sizeof(struct usb_otg), GFP_KERNEL);
if (!gpio_vbus->phy.otg) {
kfree(gpio_vbus);
return -ENOMEM;
}
platform_set_drvdata(pdev, gpio_vbus);
gpio_vbus->dev = &pdev->dev;
gpio_vbus->phy.label = "gpio-vbus";
gpio_vbus->phy.set_power = gpio_vbus_set_power;
gpio_vbus->phy.set_suspend = gpio_vbus_set_suspend;
gpio_vbus->phy.state = OTG_STATE_UNDEFINED;
gpio_vbus->phy.otg->phy = &gpio_vbus->phy;
gpio_vbus->phy.otg->set_peripheral = gpio_vbus_set_peripheral;
err = gpio_request(gpio, "vbus_detect");
if (err) {
dev_err(&pdev->dev, "can't request vbus gpio %d, err: %d\n",
gpio, err);
goto err_gpio;
}
gpio_direction_input(gpio);
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (res) {
irq = res->start;
res->flags &= IRQF_TRIGGER_MASK;
res->flags |= IRQF_SAMPLE_RANDOM | IRQF_SHARED;
} else
irq = gpio_to_irq(gpio);
gpio = pdata->gpio_pullup;
if (gpio_is_valid(gpio)) {
err = gpio_request(gpio, "udc_pullup");
if (err) {
dev_err(&pdev->dev,
"can't request pullup gpio %d, err: %d\n",
gpio, err);
gpio_free(pdata->gpio_vbus);
goto err_gpio;
}
gpio_direction_output(gpio, pdata->gpio_pullup_inverted);
}
err = request_irq(irq, gpio_vbus_irq, VBUS_IRQ_FLAGS,
"vbus_detect", pdev);
if (err) {
dev_err(&pdev->dev, "can't request irq %i, err: %d\n",
irq, err);
goto err_irq;
}
ATOMIC_INIT_NOTIFIER_HEAD(&gpio_vbus->phy.notifier);
INIT_WORK(&gpio_vbus->work, gpio_vbus_work);
gpio_vbus->vbus_draw = regulator_get(&pdev->dev, "vbus_draw");
if (IS_ERR(gpio_vbus->vbus_draw)) {
dev_dbg(&pdev->dev, "can't get vbus_draw regulator, err: %ld\n",
PTR_ERR(gpio_vbus->vbus_draw));
gpio_vbus->vbus_draw = NULL;
}
err = usb_set_transceiver(&gpio_vbus->phy);
if (err) {
dev_err(&pdev->dev, "can't register transceiver, err: %d\n",
err);
goto err_otg;
}
return 0;
err_otg:
free_irq(irq, &pdev->dev);
err_irq:
if (gpio_is_valid(pdata->gpio_pullup))
gpio_free(pdata->gpio_pullup);
gpio_free(pdata->gpio_vbus);
err_gpio:
platform_set_drvdata(pdev, NULL);
kfree(gpio_vbus->phy.otg);
kfree(gpio_vbus);
return err;
}
static int __exit gpio_vbus_remove(struct platform_device *pdev)
{
struct gpio_vbus_data *gpio_vbus = platform_get_drvdata(pdev);
struct gpio_vbus_mach_info *pdata = pdev->dev.platform_data;
int gpio = pdata->gpio_vbus;
regulator_put(gpio_vbus->vbus_draw);
usb_set_transceiver(NULL);
free_irq(gpio_to_irq(gpio), &pdev->dev);
if (gpio_is_valid(pdata->gpio_pullup))
gpio_free(pdata->gpio_pullup);
gpio_free(gpio);
platform_set_drvdata(pdev, NULL);
kfree(gpio_vbus->phy.otg);
kfree(gpio_vbus);
return 0;
}
static int __init gpio_vbus_init(void)
{
return platform_driver_probe(&gpio_vbus_driver, gpio_vbus_probe);
}
static void __exit gpio_vbus_exit(void)
{
platform_driver_unregister(&gpio_vbus_driver);
}
