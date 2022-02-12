static irqreturn_t touchit213_interrupt(struct serio *serio,
unsigned char data, unsigned int flags)
{
struct touchit213 *touchit213 = serio_get_drvdata(serio);
struct input_dev *dev = touchit213->dev;
touchit213->data[touchit213->idx] = data;
switch (touchit213->idx++) {
case 0:
if ((touchit213->data[0] & T213_FORMAT_STATUS_MASK) !=
T213_FORMAT_STATUS_BYTE) {
pr_debug("unsynchronized data: 0x%02x\n", data);
touchit213->idx = 0;
}
break;
case 4:
touchit213->idx = 0;
input_report_abs(dev, ABS_X,
(touchit213->data[1] << 7) | touchit213->data[2]);
input_report_abs(dev, ABS_Y,
(touchit213->data[3] << 7) | touchit213->data[4]);
input_report_key(dev, BTN_TOUCH,
touchit213->data[0] & T213_FORMAT_TOUCH_BIT);
input_sync(dev);
break;
}
return IRQ_HANDLED;
}
static void touchit213_disconnect(struct serio *serio)
{
struct touchit213 *touchit213 = serio_get_drvdata(serio);
input_get_device(touchit213->dev);
input_unregister_device(touchit213->dev);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_put_device(touchit213->dev);
kfree(touchit213);
}
static int touchit213_connect(struct serio *serio, struct serio_driver *drv)
{
struct touchit213 *touchit213;
struct input_dev *input_dev;
int err;
touchit213 = kzalloc(sizeof(struct touchit213), GFP_KERNEL);
input_dev = input_allocate_device();
if (!touchit213 || !input_dev) {
err = -ENOMEM;
goto fail1;
}
touchit213->serio = serio;
touchit213->dev = input_dev;
snprintf(touchit213->phys, sizeof(touchit213->phys),
"%s/input0", serio->phys);
input_dev->name = "Sahara Touch-iT213 Serial TouchScreen";
input_dev->phys = touchit213->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_TOUCHIT213;
input_dev->id.product = 0;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &serio->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input_dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(touchit213->dev, ABS_X,
T213_MIN_XC, T213_MAX_XC, 0, 0);
input_set_abs_params(touchit213->dev, ABS_Y,
T213_MIN_YC, T213_MAX_YC, 0, 0);
serio_set_drvdata(serio, touchit213);
err = serio_open(serio, drv);
if (err)
goto fail2;
err = input_register_device(touchit213->dev);
if (err)
goto fail3;
return 0;
fail3: serio_close(serio);
fail2: serio_set_drvdata(serio, NULL);
fail1: input_free_device(input_dev);
kfree(touchit213);
return err;
}
