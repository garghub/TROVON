static irqreturn_t max8925_onkey_handler(int irq, void *data)
{
struct max8925_onkey_info *info = data;
int state;
state = max8925_reg_read(info->i2c, MAX8925_ON_OFF_STATUS);
input_report_key(info->idev, KEY_POWER, state & SW_INPUT);
input_sync(info->idev);
dev_dbg(info->dev, "onkey state:%d\n", state);
max8925_set_bits(info->i2c, MAX8925_SYSENSEL,
HARDRESET_EN, HARDRESET_EN);
return IRQ_HANDLED;
}
static int max8925_onkey_probe(struct platform_device *pdev)
{
struct max8925_chip *chip = dev_get_drvdata(pdev->dev.parent);
struct max8925_onkey_info *info;
struct input_dev *input;
int irq[2], error;
irq[0] = platform_get_irq(pdev, 0);
if (irq[0] < 0) {
dev_err(&pdev->dev, "No IRQ resource!\n");
return -EINVAL;
}
irq[1] = platform_get_irq(pdev, 1);
if (irq[1] < 0) {
dev_err(&pdev->dev, "No IRQ resource!\n");
return -EINVAL;
}
info = devm_kzalloc(&pdev->dev, sizeof(struct max8925_onkey_info),
GFP_KERNEL);
if (!info)
return -ENOMEM;
input = devm_input_allocate_device(&pdev->dev);
if (!input)
return -ENOMEM;
info->idev = input;
info->i2c = chip->i2c;
info->dev = &pdev->dev;
info->irq[0] = irq[0];
info->irq[1] = irq[1];
input->name = "max8925_on";
input->phys = "max8925_on/input0";
input->id.bustype = BUS_I2C;
input->dev.parent = &pdev->dev;
input_set_capability(input, EV_KEY, KEY_POWER);
error = devm_request_threaded_irq(&pdev->dev, irq[0], NULL,
max8925_onkey_handler, IRQF_ONESHOT,
"onkey-down", info);
if (error < 0) {
dev_err(chip->dev, "Failed to request IRQ: #%d: %d\n",
irq[0], error);
return error;
}
error = devm_request_threaded_irq(&pdev->dev, irq[1], NULL,
max8925_onkey_handler, IRQF_ONESHOT,
"onkey-up", info);
if (error < 0) {
dev_err(chip->dev, "Failed to request IRQ: #%d: %d\n",
irq[1], error);
return error;
}
error = input_register_device(info->idev);
if (error) {
dev_err(chip->dev, "Can't register input device: %d\n", error);
return error;
}
platform_set_drvdata(pdev, info);
device_init_wakeup(&pdev->dev, 1);
return 0;
}
static int __maybe_unused max8925_onkey_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct max8925_onkey_info *info = platform_get_drvdata(pdev);
struct max8925_chip *chip = dev_get_drvdata(pdev->dev.parent);
if (device_may_wakeup(dev)) {
chip->wakeup_flag |= 1 << info->irq[0];
chip->wakeup_flag |= 1 << info->irq[1];
}
return 0;
}
static int __maybe_unused max8925_onkey_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct max8925_onkey_info *info = platform_get_drvdata(pdev);
struct max8925_chip *chip = dev_get_drvdata(pdev->dev.parent);
if (device_may_wakeup(dev)) {
chip->wakeup_flag &= ~(1 << info->irq[0]);
chip->wakeup_flag &= ~(1 << info->irq[1]);
}
return 0;
}
