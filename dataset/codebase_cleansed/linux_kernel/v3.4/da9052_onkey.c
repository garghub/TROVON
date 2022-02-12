static void da9052_onkey_query(struct da9052_onkey *onkey)
{
int key_stat;
key_stat = da9052_reg_read(onkey->da9052, DA9052_EVENT_B_REG);
if (key_stat < 0) {
dev_err(onkey->da9052->dev,
"Failed to read onkey event %d\n", key_stat);
} else {
key_stat &= DA9052_EVENTB_ENONKEY;
input_report_key(onkey->input, KEY_POWER, key_stat);
input_sync(onkey->input);
}
if (key_stat)
schedule_delayed_work(&onkey->work, msecs_to_jiffies(50));
}
static void da9052_onkey_work(struct work_struct *work)
{
struct da9052_onkey *onkey = container_of(work, struct da9052_onkey,
work.work);
da9052_onkey_query(onkey);
}
static irqreturn_t da9052_onkey_irq(int irq, void *data)
{
struct da9052_onkey *onkey = data;
da9052_onkey_query(onkey);
return IRQ_HANDLED;
}
static int __devinit da9052_onkey_probe(struct platform_device *pdev)
{
struct da9052 *da9052 = dev_get_drvdata(pdev->dev.parent);
struct da9052_onkey *onkey;
struct input_dev *input_dev;
int irq;
int error;
if (!da9052) {
dev_err(&pdev->dev, "Failed to get the driver's data\n");
return -EINVAL;
}
irq = platform_get_irq_byname(pdev, "ONKEY");
if (irq < 0) {
dev_err(&pdev->dev,
"Failed to get an IRQ for input device, %d\n", irq);
return -EINVAL;
}
onkey = kzalloc(sizeof(*onkey), GFP_KERNEL);
input_dev = input_allocate_device();
if (!onkey || !input_dev) {
dev_err(&pdev->dev, "Failed to allocate memory\n");
error = -ENOMEM;
goto err_free_mem;
}
onkey->input = input_dev;
onkey->da9052 = da9052;
onkey->irq = irq;
INIT_DELAYED_WORK(&onkey->work, da9052_onkey_work);
input_dev->name = "da9052-onkey";
input_dev->phys = "da9052-onkey/input0";
input_dev->dev.parent = &pdev->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY);
__set_bit(KEY_POWER, input_dev->keybit);
error = request_threaded_irq(onkey->irq, NULL, da9052_onkey_irq,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"ONKEY", onkey);
if (error < 0) {
dev_err(onkey->da9052->dev,
"Failed to register ONKEY IRQ %d, error = %d\n",
onkey->irq, error);
goto err_free_mem;
}
error = input_register_device(onkey->input);
if (error) {
dev_err(&pdev->dev, "Unable to register input device, %d\n",
error);
goto err_free_irq;
}
platform_set_drvdata(pdev, onkey);
return 0;
err_free_irq:
free_irq(onkey->irq, onkey);
cancel_delayed_work_sync(&onkey->work);
err_free_mem:
input_free_device(input_dev);
kfree(onkey);
return error;
}
static int __devexit da9052_onkey_remove(struct platform_device *pdev)
{
struct da9052_onkey *onkey = platform_get_drvdata(pdev);
free_irq(onkey->irq, onkey);
cancel_delayed_work_sync(&onkey->work);
input_unregister_device(onkey->input);
kfree(onkey);
return 0;
}
