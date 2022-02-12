static irqreturn_t powerbutton_irq(int irq, void *_pwr)
{
struct input_dev *pwr = _pwr;
int err;
u8 value;
err = twl_i2c_read_u8(TWL_MODULE_PM_MASTER, &value, STS_HW_CONDITIONS);
if (!err) {
pm_wakeup_event(pwr->dev.parent, 0);
input_report_key(pwr, KEY_POWER, value & PWR_PWRON_IRQ);
input_sync(pwr);
} else {
dev_err(pwr->dev.parent, "twl4030: i2c error %d while reading"
" TWL4030 PM_MASTER STS_HW_CONDITIONS register\n", err);
}
return IRQ_HANDLED;
}
static int twl4030_pwrbutton_probe(struct platform_device *pdev)
{
struct input_dev *pwr;
int irq = platform_get_irq(pdev, 0);
int err;
pwr = devm_input_allocate_device(&pdev->dev);
if (!pwr) {
dev_err(&pdev->dev, "Can't allocate power button\n");
return -ENOMEM;
}
pwr->evbit[0] = BIT_MASK(EV_KEY);
pwr->keybit[BIT_WORD(KEY_POWER)] = BIT_MASK(KEY_POWER);
pwr->name = "twl4030_pwrbutton";
pwr->phys = "twl4030_pwrbutton/input0";
pwr->dev.parent = &pdev->dev;
err = devm_request_threaded_irq(&pwr->dev, irq, NULL, powerbutton_irq,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING,
"twl4030_pwrbutton", pwr);
if (err < 0) {
dev_err(&pdev->dev, "Can't get IRQ for pwrbutton: %d\n", err);
return err;
}
err = input_register_device(pwr);
if (err) {
dev_err(&pdev->dev, "Can't register power button: %d\n", err);
return err;
}
platform_set_drvdata(pdev, pwr);
return 0;
}
