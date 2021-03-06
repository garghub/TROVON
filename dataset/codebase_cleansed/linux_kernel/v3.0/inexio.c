static void inexio_process_data(struct inexio *pinexio)
{
struct input_dev *dev = pinexio->dev;
if (INEXIO_FORMAT_LENGTH == ++pinexio->idx) {
input_report_abs(dev, ABS_X, INEXIO_GET_XC(pinexio->data));
input_report_abs(dev, ABS_Y, INEXIO_GET_YC(pinexio->data));
input_report_key(dev, BTN_TOUCH, INEXIO_GET_TOUCHED(pinexio->data));
input_sync(dev);
pinexio->idx = 0;
}
}
static irqreturn_t inexio_interrupt(struct serio *serio,
unsigned char data, unsigned int flags)
{
struct inexio* pinexio = serio_get_drvdata(serio);
pinexio->data[pinexio->idx] = data;
if (INEXIO_RESPONSE_BEGIN_BYTE&pinexio->data[0])
inexio_process_data(pinexio);
else
printk(KERN_DEBUG "inexio.c: unknown/unsynchronized data from device, byte %x\n",pinexio->data[0]);
return IRQ_HANDLED;
}
static void inexio_disconnect(struct serio *serio)
{
struct inexio* pinexio = serio_get_drvdata(serio);
input_get_device(pinexio->dev);
input_unregister_device(pinexio->dev);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_put_device(pinexio->dev);
kfree(pinexio);
}
static int inexio_connect(struct serio *serio, struct serio_driver *drv)
{
struct inexio *pinexio;
struct input_dev *input_dev;
int err;
pinexio = kzalloc(sizeof(struct inexio), GFP_KERNEL);
input_dev = input_allocate_device();
if (!pinexio || !input_dev) {
err = -ENOMEM;
goto fail1;
}
pinexio->serio = serio;
pinexio->dev = input_dev;
snprintf(pinexio->phys, sizeof(pinexio->phys), "%s/input0", serio->phys);
input_dev->name = "iNexio Serial TouchScreen";
input_dev->phys = pinexio->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_INEXIO;
input_dev->id.product = 0;
input_dev->id.version = 0x0001;
input_dev->dev.parent = &serio->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input_dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(pinexio->dev, ABS_X, INEXIO_MIN_XC, INEXIO_MAX_XC, 0, 0);
input_set_abs_params(pinexio->dev, ABS_Y, INEXIO_MIN_YC, INEXIO_MAX_YC, 0, 0);
serio_set_drvdata(serio, pinexio);
err = serio_open(serio, drv);
if (err)
goto fail2;
err = input_register_device(pinexio->dev);
if (err)
goto fail3;
return 0;
fail3: serio_close(serio);
fail2: serio_set_drvdata(serio, NULL);
fail1: input_free_device(input_dev);
kfree(pinexio);
return err;
}
static int __init inexio_init(void)
{
return serio_register_driver(&inexio_drv);
}
static void __exit inexio_exit(void)
{
serio_unregister_driver(&inexio_drv);
}
