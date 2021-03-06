static irqreturn_t pm_interrupt(struct serio *serio,
unsigned char data, unsigned int flags)
{
struct pm *pm = serio_get_drvdata(serio);
struct input_dev *dev = pm->dev;
pm->data[pm->idx] = data;
if (pm->data[0] & 0x80) {
if (PM_MAX_LENGTH == ++pm->idx) {
input_report_abs(dev, ABS_X, pm->data[2] * 128 + pm->data[1]);
input_report_abs(dev, ABS_Y, pm->data[4] * 128 + pm->data[3]);
input_report_key(dev, BTN_TOUCH, !!(pm->data[0] & 0x40));
input_sync(dev);
pm->idx = 0;
}
}
return IRQ_HANDLED;
}
static void pm_disconnect(struct serio *serio)
{
struct pm *pm = serio_get_drvdata(serio);
input_get_device(pm->dev);
input_unregister_device(pm->dev);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_put_device(pm->dev);
kfree(pm);
}
static int pm_connect(struct serio *serio, struct serio_driver *drv)
{
struct pm *pm;
struct input_dev *input_dev;
int err;
pm = kzalloc(sizeof(struct pm), GFP_KERNEL);
input_dev = input_allocate_device();
if (!pm || !input_dev) {
err = -ENOMEM;
goto fail1;
}
pm->serio = serio;
pm->dev = input_dev;
snprintf(pm->phys, sizeof(pm->phys), "%s/input0", serio->phys);
input_dev->name = "Penmount Serial TouchScreen";
input_dev->phys = pm->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_PENMOUNT;
input_dev->id.product = 0;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &serio->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input_dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(pm->dev, ABS_X, 0, 0x3ff, 0, 0);
input_set_abs_params(pm->dev, ABS_Y, 0, 0x3ff, 0, 0);
serio_set_drvdata(serio, pm);
err = serio_open(serio, drv);
if (err)
goto fail2;
err = input_register_device(pm->dev);
if (err)
goto fail3;
return 0;
fail3: serio_close(serio);
fail2: serio_set_drvdata(serio, NULL);
fail1: input_free_device(input_dev);
kfree(pm);
return err;
}
static int __init pm_init(void)
{
return serio_register_driver(&pm_drv);
}
static void __exit pm_exit(void)
{
serio_unregister_driver(&pm_drv);
}
