static irqreturn_t pwrkey_press_irq(int irq, void *_pwr)
{
struct input_dev *pwr = _pwr;
input_report_key(pwr, KEY_POWER, 1);
input_sync(pwr);
return IRQ_HANDLED;
}
static irqreturn_t pwrkey_release_irq(int irq, void *_pwr)
{
struct input_dev *pwr = _pwr;
input_report_key(pwr, KEY_POWER, 0);
input_sync(pwr);
return IRQ_HANDLED;
}
static int pmic8xxx_pwrkey_suspend(struct device *dev)
{
struct pmic8xxx_pwrkey *pwrkey = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
enable_irq_wake(pwrkey->key_press_irq);
return 0;
}
static int pmic8xxx_pwrkey_resume(struct device *dev)
{
struct pmic8xxx_pwrkey *pwrkey = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
disable_irq_wake(pwrkey->key_press_irq);
return 0;
}
static int pmic8xxx_pwrkey_probe(struct platform_device *pdev)
{
struct input_dev *pwr;
int key_release_irq = platform_get_irq(pdev, 0);
int key_press_irq = platform_get_irq(pdev, 1);
int err;
unsigned int delay;
unsigned int pon_cntl;
struct regmap *regmap;
struct pmic8xxx_pwrkey *pwrkey;
u32 kpd_delay;
bool pull_up;
if (of_property_read_u32(pdev->dev.of_node, "debounce", &kpd_delay))
kpd_delay = 0;
pull_up = of_property_read_bool(pdev->dev.of_node, "pull-up");
if (kpd_delay > 62500) {
dev_err(&pdev->dev, "invalid power key trigger delay\n");
return -EINVAL;
}
regmap = dev_get_regmap(pdev->dev.parent, NULL);
if (!regmap) {
dev_err(&pdev->dev, "failed to locate regmap for the device\n");
return -ENODEV;
}
pwrkey = devm_kzalloc(&pdev->dev, sizeof(*pwrkey), GFP_KERNEL);
if (!pwrkey)
return -ENOMEM;
pwrkey->key_press_irq = key_press_irq;
pwr = devm_input_allocate_device(&pdev->dev);
if (!pwr) {
dev_dbg(&pdev->dev, "Can't allocate power button\n");
return -ENOMEM;
}
input_set_capability(pwr, EV_KEY, KEY_POWER);
pwr->name = "pmic8xxx_pwrkey";
pwr->phys = "pmic8xxx_pwrkey/input0";
delay = (kpd_delay << 10) / USEC_PER_SEC;
delay = 1 + ilog2(delay);
err = regmap_read(regmap, PON_CNTL_1, &pon_cntl);
if (err < 0) {
dev_err(&pdev->dev, "failed reading PON_CNTL_1 err=%d\n", err);
return err;
}
pon_cntl &= ~PON_CNTL_TRIG_DELAY_MASK;
pon_cntl |= (delay & PON_CNTL_TRIG_DELAY_MASK);
if (pull_up)
pon_cntl |= PON_CNTL_PULL_UP;
else
pon_cntl &= ~PON_CNTL_PULL_UP;
err = regmap_write(regmap, PON_CNTL_1, pon_cntl);
if (err < 0) {
dev_err(&pdev->dev, "failed writing PON_CNTL_1 err=%d\n", err);
return err;
}
err = devm_request_irq(&pdev->dev, key_press_irq, pwrkey_press_irq,
IRQF_TRIGGER_RISING,
"pmic8xxx_pwrkey_press", pwr);
if (err) {
dev_err(&pdev->dev, "Can't get %d IRQ for pwrkey: %d\n",
key_press_irq, err);
return err;
}
err = devm_request_irq(&pdev->dev, key_release_irq, pwrkey_release_irq,
IRQF_TRIGGER_RISING,
"pmic8xxx_pwrkey_release", pwr);
if (err) {
dev_err(&pdev->dev, "Can't get %d IRQ for pwrkey: %d\n",
key_release_irq, err);
return err;
}
err = input_register_device(pwr);
if (err) {
dev_err(&pdev->dev, "Can't register power key: %d\n", err);
return err;
}
platform_set_drvdata(pdev, pwrkey);
device_init_wakeup(&pdev->dev, 1);
return 0;
}
static int pmic8xxx_pwrkey_remove(struct platform_device *pdev)
{
device_init_wakeup(&pdev->dev, 0);
return 0;
}
