static irqreturn_t pm860x_onkey_handler(int irq, void *data)
{
struct pm860x_onkey_info *info = data;
int ret;
ret = pm860x_reg_read(info->i2c, PM8607_STATUS_2);
ret &= ONKEY_STATUS;
input_report_key(info->idev, KEY_POWER, ret);
input_sync(info->idev);
pm860x_set_bits(info->i2c, PM8607_WAKEUP, 3, LONG_ONKEY_EN);
return IRQ_HANDLED;
}
static int pm860x_onkey_probe(struct platform_device *pdev)
{
struct pm860x_chip *chip = dev_get_drvdata(pdev->dev.parent);
struct pm860x_onkey_info *info;
int irq, ret;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "No IRQ resource!\n");
return -EINVAL;
}
info = kzalloc(sizeof(struct pm860x_onkey_info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->chip = chip;
info->i2c = (chip->id == CHIP_PM8607) ? chip->client : chip->companion;
info->dev = &pdev->dev;
info->irq = irq;
info->idev = input_allocate_device();
if (!info->idev) {
dev_err(chip->dev, "Failed to allocate input dev\n");
ret = -ENOMEM;
goto out;
}
info->idev->name = "88pm860x_on";
info->idev->phys = "88pm860x_on/input0";
info->idev->id.bustype = BUS_I2C;
info->idev->dev.parent = &pdev->dev;
info->idev->evbit[0] = BIT_MASK(EV_KEY);
info->idev->keybit[BIT_WORD(KEY_POWER)] = BIT_MASK(KEY_POWER);
ret = input_register_device(info->idev);
if (ret) {
dev_err(chip->dev, "Can't register input device: %d\n", ret);
goto out_reg;
}
ret = request_threaded_irq(info->irq, NULL, pm860x_onkey_handler,
IRQF_ONESHOT, "onkey", info);
if (ret < 0) {
dev_err(chip->dev, "Failed to request IRQ: #%d: %d\n",
info->irq, ret);
goto out_irq;
}
platform_set_drvdata(pdev, info);
device_init_wakeup(&pdev->dev, 1);
return 0;
out_irq:
input_unregister_device(info->idev);
kfree(info);
return ret;
out_reg:
input_free_device(info->idev);
out:
kfree(info);
return ret;
}
static int pm860x_onkey_remove(struct platform_device *pdev)
{
struct pm860x_onkey_info *info = platform_get_drvdata(pdev);
free_irq(info->irq, info);
input_unregister_device(info->idev);
kfree(info);
return 0;
}
static int pm860x_onkey_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct pm860x_chip *chip = dev_get_drvdata(pdev->dev.parent);
if (device_may_wakeup(dev))
chip->wakeup_flag |= 1 << PM8607_IRQ_ONKEY;
return 0;
}
static int pm860x_onkey_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct pm860x_chip *chip = dev_get_drvdata(pdev->dev.parent);
if (device_may_wakeup(dev))
chip->wakeup_flag &= ~(1 << PM8607_IRQ_ONKEY);
return 0;
}
