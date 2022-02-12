static irqreturn_t e3x0_button_release_handler(int irq, void *data)
{
struct input_dev *idev = data;
input_report_key(idev, KEY_POWER, 0);
input_sync(idev);
return IRQ_HANDLED;
}
static irqreturn_t e3x0_button_press_handler(int irq, void *data)
{
struct input_dev *idev = data;
input_report_key(idev, KEY_POWER, 1);
pm_wakeup_event(idev->dev.parent, 0);
input_sync(idev);
return IRQ_HANDLED;
}
static int __maybe_unused e3x0_button_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
if (device_may_wakeup(dev))
enable_irq_wake(platform_get_irq_byname(pdev, "press"));
return 0;
}
static int __maybe_unused e3x0_button_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
if (device_may_wakeup(dev))
disable_irq_wake(platform_get_irq_byname(pdev, "press"));
return 0;
}
static int e3x0_button_probe(struct platform_device *pdev)
{
struct input_dev *input;
int irq_press, irq_release;
int error;
irq_press = platform_get_irq_byname(pdev, "press");
if (irq_press < 0) {
dev_err(&pdev->dev, "No IRQ for 'press', error=%d\n",
irq_press);
return irq_press;
}
irq_release = platform_get_irq_byname(pdev, "release");
if (irq_release < 0) {
dev_err(&pdev->dev, "No IRQ for 'release', error=%d\n",
irq_release);
return irq_release;
}
input = devm_input_allocate_device(&pdev->dev);
if (!input)
return -ENOMEM;
input->name = "NI Ettus Research USRP E3x0 Button Driver";
input->phys = "e3x0_button/input0";
input->dev.parent = &pdev->dev;
input_set_capability(input, EV_KEY, KEY_POWER);
error = devm_request_irq(&pdev->dev, irq_press,
e3x0_button_press_handler, 0,
"e3x0-button", input);
if (error) {
dev_err(&pdev->dev, "Failed to request 'press' IRQ#%d: %d\n",
irq_press, error);
return error;
}
error = devm_request_irq(&pdev->dev, irq_release,
e3x0_button_release_handler, 0,
"e3x0-button", input);
if (error) {
dev_err(&pdev->dev, "Failed to request 'release' IRQ#%d: %d\n",
irq_release, error);
return error;
}
error = input_register_device(input);
if (error) {
dev_err(&pdev->dev, "Can't register input device: %d\n", error);
return error;
}
platform_set_drvdata(pdev, input);
device_init_wakeup(&pdev->dev, 1);
return 0;
}
static int e3x0_button_remove(struct platform_device *pdev)
{
device_init_wakeup(&pdev->dev, 0);
return 0;
}
