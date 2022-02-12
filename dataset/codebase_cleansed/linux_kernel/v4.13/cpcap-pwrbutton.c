static irqreturn_t powerbutton_irq(int irq, void *_button)
{
struct cpcap_power_button *button = _button;
int val;
val = cpcap_sense_virq(button->regmap, irq);
if (val < 0) {
dev_err(button->dev, "irq read failed: %d", val);
return IRQ_HANDLED;
}
pm_wakeup_event(button->dev, 0);
input_report_key(button->idev, KEY_POWER, val);
input_sync(button->idev);
return IRQ_HANDLED;
}
static int cpcap_power_button_probe(struct platform_device *pdev)
{
struct cpcap_power_button *button;
int irq = platform_get_irq(pdev, 0);
int err;
button = devm_kmalloc(&pdev->dev, sizeof(*button), GFP_KERNEL);
if (!button)
return -ENOMEM;
button->idev = devm_input_allocate_device(&pdev->dev);
if (!button->idev)
return -ENOMEM;
button->regmap = dev_get_regmap(pdev->dev.parent, NULL);
if (!button->regmap)
return -ENODEV;
button->dev = &pdev->dev;
button->idev->name = "cpcap-pwrbutton";
button->idev->phys = "cpcap-pwrbutton/input0";
button->idev->dev.parent = button->dev;
input_set_capability(button->idev, EV_KEY, KEY_POWER);
err = devm_request_threaded_irq(&pdev->dev, irq, NULL,
powerbutton_irq, IRQF_ONESHOT, "cpcap_pwrbutton", button);
if (err < 0) {
dev_err(&pdev->dev, "IRQ request failed: %d\n", err);
return err;
}
err = input_register_device(button->idev);
if (err) {
dev_err(&pdev->dev, "Input register failed: %d\n", err);
return err;
}
device_init_wakeup(&pdev->dev, true);
return 0;
}
