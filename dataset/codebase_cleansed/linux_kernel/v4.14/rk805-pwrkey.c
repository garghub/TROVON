static irqreturn_t pwrkey_fall_irq(int irq, void *_pwr)
{
struct input_dev *pwr = _pwr;
input_report_key(pwr, KEY_POWER, 1);
input_sync(pwr);
return IRQ_HANDLED;
}
static irqreturn_t pwrkey_rise_irq(int irq, void *_pwr)
{
struct input_dev *pwr = _pwr;
input_report_key(pwr, KEY_POWER, 0);
input_sync(pwr);
return IRQ_HANDLED;
}
static int rk805_pwrkey_probe(struct platform_device *pdev)
{
struct input_dev *pwr;
int fall_irq, rise_irq;
int err;
pwr = devm_input_allocate_device(&pdev->dev);
if (!pwr) {
dev_err(&pdev->dev, "Can't allocate power button\n");
return -ENOMEM;
}
pwr->name = "rk805 pwrkey";
pwr->phys = "rk805_pwrkey/input0";
pwr->id.bustype = BUS_HOST;
input_set_capability(pwr, EV_KEY, KEY_POWER);
fall_irq = platform_get_irq(pdev, 0);
if (fall_irq < 0) {
dev_err(&pdev->dev, "Can't get fall irq: %d\n", fall_irq);
return fall_irq;
}
rise_irq = platform_get_irq(pdev, 1);
if (rise_irq < 0) {
dev_err(&pdev->dev, "Can't get rise irq: %d\n", rise_irq);
return rise_irq;
}
err = devm_request_any_context_irq(&pwr->dev, fall_irq,
pwrkey_fall_irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"rk805_pwrkey_fall", pwr);
if (err < 0) {
dev_err(&pdev->dev, "Can't register fall irq: %d\n", err);
return err;
}
err = devm_request_any_context_irq(&pwr->dev, rise_irq,
pwrkey_rise_irq,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
"rk805_pwrkey_rise", pwr);
if (err < 0) {
dev_err(&pdev->dev, "Can't register rise irq: %d\n", err);
return err;
}
err = input_register_device(pwr);
if (err) {
dev_err(&pdev->dev, "Can't register power button: %d\n", err);
return err;
}
platform_set_drvdata(pdev, pwr);
device_init_wakeup(&pdev->dev, true);
return 0;
}
