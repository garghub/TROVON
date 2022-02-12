static irqreturn_t max8925_onkey_handler(int irq, void *data)
{
struct max8925_onkey_info *info = data;
int ret, event;
ret = max8925_reg_read(info->i2c, MAX8925_ON_OFF_STATUS);
if (ret & SW_INPUT)
event = 1;
else
event = 0;
input_report_key(info->idev, KEY_POWER, event);
input_sync(info->idev);
dev_dbg(info->dev, "onkey event:%d\n", event);
max8925_set_bits(info->i2c, MAX8925_SYSENSEL,
HARDRESET_EN, HARDRESET_EN);
return IRQ_HANDLED;
}
static int __devinit max8925_onkey_probe(struct platform_device *pdev)
{
struct max8925_chip *chip = dev_get_drvdata(pdev->dev.parent);
struct max8925_onkey_info *info;
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
info = kzalloc(sizeof(struct max8925_onkey_info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->i2c = chip->i2c;
info->dev = &pdev->dev;
irq[0] += chip->irq_base;
irq[1] += chip->irq_base;
error = request_threaded_irq(irq[0], NULL, max8925_onkey_handler,
IRQF_ONESHOT, "onkey-down", info);
if (error < 0) {
dev_err(chip->dev, "Failed to request IRQ: #%d: %d\n",
irq[0], error);
goto out;
}
error = request_threaded_irq(irq[1], NULL, max8925_onkey_handler,
IRQF_ONESHOT, "onkey-up", info);
if (error < 0) {
dev_err(chip->dev, "Failed to request IRQ: #%d: %d\n",
irq[1], error);
goto out_irq;
}
info->idev = input_allocate_device();
if (!info->idev) {
dev_err(chip->dev, "Failed to allocate input dev\n");
error = -ENOMEM;
goto out_input;
}
info->idev->name = "max8925_on";
info->idev->phys = "max8925_on/input0";
info->idev->id.bustype = BUS_I2C;
info->idev->dev.parent = &pdev->dev;
info->irq[0] = irq[0];
info->irq[1] = irq[1];
info->idev->evbit[0] = BIT_MASK(EV_KEY);
info->idev->keybit[BIT_WORD(KEY_POWER)] = BIT_MASK(KEY_POWER);
error = input_register_device(info->idev);
if (error) {
dev_err(chip->dev, "Can't register input device: %d\n", error);
goto out_reg;
}
platform_set_drvdata(pdev, info);
return 0;
out_reg:
input_free_device(info->idev);
out_input:
free_irq(info->irq[1], info);
out_irq:
free_irq(info->irq[0], info);
out:
kfree(info);
return error;
}
static int __devexit max8925_onkey_remove(struct platform_device *pdev)
{
struct max8925_onkey_info *info = platform_get_drvdata(pdev);
free_irq(info->irq[0], info);
free_irq(info->irq[1], info);
input_unregister_device(info->idev);
kfree(info);
platform_set_drvdata(pdev, NULL);
return 0;
}
