static void
pcf50633_input_irq(int irq, void *data)
{
struct pcf50633_input *input;
int onkey_released;
input = data;
onkey_released = pcf50633_reg_read(input->pcf, PCF50633_REG_OOCSTAT)
& PCF50633_OOCSTAT_ONKEY;
if (irq == PCF50633_IRQ_ONKEYF && !onkey_released)
input_report_key(input->input_dev, KEY_POWER, 1);
else if (irq == PCF50633_IRQ_ONKEYR && onkey_released)
input_report_key(input->input_dev, KEY_POWER, 0);
input_sync(input->input_dev);
}
static int __devinit pcf50633_input_probe(struct platform_device *pdev)
{
struct pcf50633_input *input;
struct input_dev *input_dev;
int ret;
input = kzalloc(sizeof(*input), GFP_KERNEL);
if (!input)
return -ENOMEM;
input_dev = input_allocate_device();
if (!input_dev) {
kfree(input);
return -ENOMEM;
}
platform_set_drvdata(pdev, input);
input->pcf = dev_to_pcf50633(pdev->dev.parent);
input->input_dev = input_dev;
input_dev->name = "PCF50633 PMU events";
input_dev->id.bustype = BUS_I2C;
input_dev->evbit[0] = BIT(EV_KEY) | BIT(EV_PWR);
set_bit(KEY_POWER, input_dev->keybit);
ret = input_register_device(input_dev);
if (ret) {
input_free_device(input_dev);
kfree(input);
return ret;
}
pcf50633_register_irq(input->pcf, PCF50633_IRQ_ONKEYR,
pcf50633_input_irq, input);
pcf50633_register_irq(input->pcf, PCF50633_IRQ_ONKEYF,
pcf50633_input_irq, input);
return 0;
}
static int __devexit pcf50633_input_remove(struct platform_device *pdev)
{
struct pcf50633_input *input = platform_get_drvdata(pdev);
pcf50633_free_irq(input->pcf, PCF50633_IRQ_ONKEYR);
pcf50633_free_irq(input->pcf, PCF50633_IRQ_ONKEYF);
input_unregister_device(input->input_dev);
kfree(input);
return 0;
}
