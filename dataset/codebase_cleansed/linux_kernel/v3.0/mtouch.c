static void mtouch_process_format_tablet(struct mtouch *mtouch)
{
struct input_dev *dev = mtouch->dev;
if (MTOUCH_FORMAT_TABLET_LENGTH == ++mtouch->idx) {
input_report_abs(dev, ABS_X, MTOUCH_GET_XC(mtouch->data));
input_report_abs(dev, ABS_Y, MTOUCH_MAX_YC - MTOUCH_GET_YC(mtouch->data));
input_report_key(dev, BTN_TOUCH, MTOUCH_GET_TOUCHED(mtouch->data));
input_sync(dev);
mtouch->idx = 0;
}
}
static void mtouch_process_response(struct mtouch *mtouch)
{
if (MTOUCH_RESPONSE_END_BYTE == mtouch->data[mtouch->idx++]) {
mtouch->idx = 0;
} else if (MTOUCH_MAX_LENGTH == mtouch->idx) {
printk(KERN_ERR "mtouch.c: too many response bytes\n");
mtouch->idx = 0;
}
}
static irqreturn_t mtouch_interrupt(struct serio *serio,
unsigned char data, unsigned int flags)
{
struct mtouch* mtouch = serio_get_drvdata(serio);
mtouch->data[mtouch->idx] = data;
if (MTOUCH_FORMAT_TABLET_STATUS_BIT & mtouch->data[0])
mtouch_process_format_tablet(mtouch);
else if (MTOUCH_RESPONSE_BEGIN_BYTE == mtouch->data[0])
mtouch_process_response(mtouch);
else
printk(KERN_DEBUG "mtouch.c: unknown/unsynchronized data from device, byte %x\n",mtouch->data[0]);
return IRQ_HANDLED;
}
static void mtouch_disconnect(struct serio *serio)
{
struct mtouch* mtouch = serio_get_drvdata(serio);
input_get_device(mtouch->dev);
input_unregister_device(mtouch->dev);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_put_device(mtouch->dev);
kfree(mtouch);
}
static int mtouch_connect(struct serio *serio, struct serio_driver *drv)
{
struct mtouch *mtouch;
struct input_dev *input_dev;
int err;
mtouch = kzalloc(sizeof(struct mtouch), GFP_KERNEL);
input_dev = input_allocate_device();
if (!mtouch || !input_dev) {
err = -ENOMEM;
goto fail1;
}
mtouch->serio = serio;
mtouch->dev = input_dev;
snprintf(mtouch->phys, sizeof(mtouch->phys), "%s/input0", serio->phys);
input_dev->name = "MicroTouch Serial TouchScreen";
input_dev->phys = mtouch->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_MICROTOUCH;
input_dev->id.product = 0;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &serio->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input_dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(mtouch->dev, ABS_X, MTOUCH_MIN_XC, MTOUCH_MAX_XC, 0, 0);
input_set_abs_params(mtouch->dev, ABS_Y, MTOUCH_MIN_YC, MTOUCH_MAX_YC, 0, 0);
serio_set_drvdata(serio, mtouch);
err = serio_open(serio, drv);
if (err)
goto fail2;
err = input_register_device(mtouch->dev);
if (err)
goto fail3;
return 0;
fail3: serio_close(serio);
fail2: serio_set_drvdata(serio, NULL);
fail1: input_free_device(input_dev);
kfree(mtouch);
return err;
}
static int __init mtouch_init(void)
{
return serio_register_driver(&mtouch_drv);
}
static void __exit mtouch_exit(void)
{
serio_unregister_driver(&mtouch_drv);
}
