static void jornada720_ts_collect_data(struct jornada_ts *jornada_ts)
{
jornada_ts->x_data[0] = jornada_ssp_byte(TXDUMMY);
jornada_ts->x_data[1] = jornada_ssp_byte(TXDUMMY);
jornada_ts->x_data[2] = jornada_ssp_byte(TXDUMMY);
jornada_ts->y_data[0] = jornada_ssp_byte(TXDUMMY);
jornada_ts->y_data[1] = jornada_ssp_byte(TXDUMMY);
jornada_ts->y_data[2] = jornada_ssp_byte(TXDUMMY);
jornada_ts->x_data[3] = jornada_ssp_byte(TXDUMMY);
jornada_ts->y_data[3] = jornada_ssp_byte(TXDUMMY);
}
static int jornada720_ts_average(int coords[4])
{
int coord, high_bits = coords[3];
coord = coords[0] | ((high_bits & 0x03) << 8);
coord += coords[1] | ((high_bits & 0x0c) << 6);
coord += coords[2] | ((high_bits & 0x30) << 4);
return coord / 3;
}
static irqreturn_t jornada720_ts_interrupt(int irq, void *dev_id)
{
struct platform_device *pdev = dev_id;
struct jornada_ts *jornada_ts = platform_get_drvdata(pdev);
struct input_dev *input = jornada_ts->dev;
int x, y;
if (GPLR & GPIO_GPIO(9)) {
input_report_key(input, BTN_TOUCH, 0);
input_sync(input);
} else {
jornada_ssp_start();
if (jornada_ssp_inout(GETTOUCHSAMPLES) == TXDUMMY) {
jornada720_ts_collect_data(jornada_ts);
x = jornada720_ts_average(jornada_ts->x_data);
y = jornada720_ts_average(jornada_ts->y_data);
input_report_key(input, BTN_TOUCH, 1);
input_report_abs(input, ABS_X, x);
input_report_abs(input, ABS_Y, y);
input_sync(input);
}
jornada_ssp_end();
}
return IRQ_HANDLED;
}
static int __devinit jornada720_ts_probe(struct platform_device *pdev)
{
struct jornada_ts *jornada_ts;
struct input_dev *input_dev;
int error;
jornada_ts = kzalloc(sizeof(struct jornada_ts), GFP_KERNEL);
input_dev = input_allocate_device();
if (!jornada_ts || !input_dev) {
error = -ENOMEM;
goto fail1;
}
platform_set_drvdata(pdev, jornada_ts);
jornada_ts->dev = input_dev;
input_dev->name = "HP Jornada 7xx Touchscreen";
input_dev->phys = "jornadats/input0";
input_dev->id.bustype = BUS_HOST;
input_dev->dev.parent = &pdev->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input_dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(input_dev, ABS_X, 270, 3900, 0, 0);
input_set_abs_params(input_dev, ABS_Y, 180, 3700, 0, 0);
error = request_irq(IRQ_GPIO9,
jornada720_ts_interrupt,
IRQF_TRIGGER_RISING,
"HP7XX Touchscreen driver", pdev);
if (error) {
printk(KERN_INFO "HP7XX TS : Unable to acquire irq!\n");
goto fail1;
}
error = input_register_device(jornada_ts->dev);
if (error)
goto fail2;
return 0;
fail2:
free_irq(IRQ_GPIO9, pdev);
fail1:
platform_set_drvdata(pdev, NULL);
input_free_device(input_dev);
kfree(jornada_ts);
return error;
}
static int __devexit jornada720_ts_remove(struct platform_device *pdev)
{
struct jornada_ts *jornada_ts = platform_get_drvdata(pdev);
free_irq(IRQ_GPIO9, pdev);
platform_set_drvdata(pdev, NULL);
input_unregister_device(jornada_ts->dev);
kfree(jornada_ts);
return 0;
}
