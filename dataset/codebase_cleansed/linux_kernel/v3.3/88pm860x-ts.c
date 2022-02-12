static irqreturn_t pm860x_touch_handler(int irq, void *data)
{
struct pm860x_touch *touch = data;
struct pm860x_chip *chip = touch->chip;
unsigned char buf[MEAS_LEN];
int x, y, pen_down;
int z1, z2, rt = 0;
int ret;
ret = pm860x_bulk_read(touch->i2c, MEAS_TSIX_1, MEAS_LEN, buf);
if (ret < 0)
goto out;
pen_down = buf[1] & (1 << 6);
x = ((buf[0] & 0xFF) << 4) | (buf[1] & 0x0F);
y = ((buf[2] & 0xFF) << 4) | (buf[3] & 0x0F);
z1 = ((buf[4] & 0xFF) << 4) | (buf[5] & 0x0F);
z2 = ((buf[6] & 0xFF) << 4) | (buf[7] & 0x0F);
if (pen_down) {
if ((x != 0) && (z1 != 0) && (touch->res_x != 0)) {
rt = z2 / z1 - 1;
rt = (rt * touch->res_x * x) >> ACCURATE_BIT;
dev_dbg(chip->dev, "z1:%d, z2:%d, rt:%d\n",
z1, z2, rt);
}
input_report_abs(touch->idev, ABS_X, x);
input_report_abs(touch->idev, ABS_Y, y);
input_report_abs(touch->idev, ABS_PRESSURE, rt);
input_report_key(touch->idev, BTN_TOUCH, 1);
dev_dbg(chip->dev, "pen down at [%d, %d].\n", x, y);
} else {
input_report_abs(touch->idev, ABS_PRESSURE, 0);
input_report_key(touch->idev, BTN_TOUCH, 0);
dev_dbg(chip->dev, "pen release\n");
}
input_sync(touch->idev);
out:
return IRQ_HANDLED;
}
static int pm860x_touch_open(struct input_dev *dev)
{
struct pm860x_touch *touch = input_get_drvdata(dev);
int data, ret;
data = MEAS_PD_EN | MEAS_TSIX_EN | MEAS_TSIY_EN
| MEAS_TSIZ1_EN | MEAS_TSIZ2_EN;
ret = pm860x_set_bits(touch->i2c, MEAS_EN3, data, data);
if (ret < 0)
goto out;
return 0;
out:
return ret;
}
static void pm860x_touch_close(struct input_dev *dev)
{
struct pm860x_touch *touch = input_get_drvdata(dev);
int data;
data = MEAS_PD_EN | MEAS_TSIX_EN | MEAS_TSIY_EN
| MEAS_TSIZ1_EN | MEAS_TSIZ2_EN;
pm860x_set_bits(touch->i2c, MEAS_EN3, data, 0);
}
static int __devinit pm860x_touch_probe(struct platform_device *pdev)
{
struct pm860x_chip *chip = dev_get_drvdata(pdev->dev.parent);
struct pm860x_platform_data *pm860x_pdata = \
pdev->dev.parent->platform_data;
struct pm860x_touch_pdata *pdata = NULL;
struct pm860x_touch *touch;
int irq, ret;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "No IRQ resource!\n");
return -EINVAL;
}
if (!pm860x_pdata) {
dev_err(&pdev->dev, "platform data is missing\n");
return -EINVAL;
}
pdata = pm860x_pdata->touch;
if (!pdata) {
dev_err(&pdev->dev, "touchscreen data is missing\n");
return -EINVAL;
}
touch = kzalloc(sizeof(struct pm860x_touch), GFP_KERNEL);
if (touch == NULL)
return -ENOMEM;
dev_set_drvdata(&pdev->dev, touch);
touch->idev = input_allocate_device();
if (touch->idev == NULL) {
dev_err(&pdev->dev, "Failed to allocate input device!\n");
ret = -ENOMEM;
goto out;
}
touch->idev->name = "88pm860x-touch";
touch->idev->phys = "88pm860x/input0";
touch->idev->id.bustype = BUS_I2C;
touch->idev->dev.parent = &pdev->dev;
touch->idev->open = pm860x_touch_open;
touch->idev->close = pm860x_touch_close;
touch->chip = chip;
touch->i2c = (chip->id == CHIP_PM8607) ? chip->client : chip->companion;
touch->irq = irq + chip->irq_base;
touch->res_x = pdata->res_x;
input_set_drvdata(touch->idev, touch);
ret = request_threaded_irq(touch->irq, NULL, pm860x_touch_handler,
IRQF_ONESHOT, "touch", touch);
if (ret < 0)
goto out_irq;
__set_bit(EV_ABS, touch->idev->evbit);
__set_bit(ABS_X, touch->idev->absbit);
__set_bit(ABS_Y, touch->idev->absbit);
__set_bit(ABS_PRESSURE, touch->idev->absbit);
__set_bit(EV_SYN, touch->idev->evbit);
__set_bit(EV_KEY, touch->idev->evbit);
__set_bit(BTN_TOUCH, touch->idev->keybit);
input_set_abs_params(touch->idev, ABS_X, 0, 1 << ACCURATE_BIT, 0, 0);
input_set_abs_params(touch->idev, ABS_Y, 0, 1 << ACCURATE_BIT, 0, 0);
input_set_abs_params(touch->idev, ABS_PRESSURE, 0, 1 << ACCURATE_BIT,
0, 0);
ret = input_register_device(touch->idev);
if (ret < 0) {
dev_err(chip->dev, "Failed to register touch!\n");
goto out_rg;
}
platform_set_drvdata(pdev, touch);
return 0;
out_rg:
free_irq(touch->irq, touch);
out_irq:
input_free_device(touch->idev);
out:
kfree(touch);
return ret;
}
static int __devexit pm860x_touch_remove(struct platform_device *pdev)
{
struct pm860x_touch *touch = platform_get_drvdata(pdev);
input_unregister_device(touch->idev);
free_irq(touch->irq, touch);
platform_set_drvdata(pdev, NULL);
kfree(touch);
return 0;
}
