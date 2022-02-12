static irqreturn_t fujitsu_interrupt(struct serio *serio,
unsigned char data, unsigned int flags)
{
struct fujitsu *fujitsu = serio_get_drvdata(serio);
struct input_dev *dev = fujitsu->dev;
if (fujitsu->idx == 0) {
if ((data & 0xf0) != 0x80)
return IRQ_HANDLED;
} else {
if (data & 0x80) {
fujitsu->idx = 0;
return IRQ_HANDLED;
}
}
fujitsu->data[fujitsu->idx++] = data;
if (fujitsu->idx == FUJITSU_LENGTH) {
input_report_abs(dev, ABS_X,
(fujitsu->data[2] << 7) | fujitsu->data[1]);
input_report_abs(dev, ABS_Y,
(fujitsu->data[4] << 7) | fujitsu->data[3]);
input_report_key(dev, BTN_TOUCH,
(fujitsu->data[0] & 0x03) != 2);
input_sync(dev);
fujitsu->idx = 0;
}
return IRQ_HANDLED;
}
static void fujitsu_disconnect(struct serio *serio)
{
struct fujitsu *fujitsu = serio_get_drvdata(serio);
input_get_device(fujitsu->dev);
input_unregister_device(fujitsu->dev);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_put_device(fujitsu->dev);
kfree(fujitsu);
}
static int fujitsu_connect(struct serio *serio, struct serio_driver *drv)
{
struct fujitsu *fujitsu;
struct input_dev *input_dev;
int err;
fujitsu = kzalloc(sizeof(struct fujitsu), GFP_KERNEL);
input_dev = input_allocate_device();
if (!fujitsu || !input_dev) {
err = -ENOMEM;
goto fail1;
}
fujitsu->serio = serio;
fujitsu->dev = input_dev;
snprintf(fujitsu->phys, sizeof(fujitsu->phys),
"%s/input0", serio->phys);
input_dev->name = "Fujitsu Serial Touchscreen";
input_dev->phys = fujitsu->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_FUJITSU;
input_dev->id.product = 0;
input_dev->id.version = 0x0100;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input_dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(input_dev, ABS_X, 0, 4096, 0, 0);
input_set_abs_params(input_dev, ABS_Y, 0, 4096, 0, 0);
serio_set_drvdata(serio, fujitsu);
err = serio_open(serio, drv);
if (err)
goto fail2;
err = input_register_device(fujitsu->dev);
if (err)
goto fail3;
return 0;
fail3:
serio_close(serio);
fail2:
serio_set_drvdata(serio, NULL);
fail1:
input_free_device(input_dev);
kfree(fujitsu);
return err;
}
static int __init fujitsu_init(void)
{
return serio_register_driver(&fujitsu_drv);
}
static void __exit fujitsu_exit(void)
{
serio_unregister_driver(&fujitsu_drv);
}
