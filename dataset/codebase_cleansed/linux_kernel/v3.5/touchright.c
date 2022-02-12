static irqreturn_t tr_interrupt(struct serio *serio,
unsigned char data, unsigned int flags)
{
struct tr *tr = serio_get_drvdata(serio);
struct input_dev *dev = tr->dev;
tr->data[tr->idx] = data;
if ((tr->data[0] & TR_FORMAT_STATUS_MASK) == TR_FORMAT_STATUS_BYTE) {
if (++tr->idx == TR_LENGTH) {
input_report_abs(dev, ABS_X,
(tr->data[1] << 5) | (tr->data[2] >> 1));
input_report_abs(dev, ABS_Y,
(tr->data[3] << 5) | (tr->data[4] >> 1));
input_report_key(dev, BTN_TOUCH,
tr->data[0] & TR_FORMAT_TOUCH_BIT);
input_sync(dev);
tr->idx = 0;
}
}
return IRQ_HANDLED;
}
static void tr_disconnect(struct serio *serio)
{
struct tr *tr = serio_get_drvdata(serio);
input_get_device(tr->dev);
input_unregister_device(tr->dev);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_put_device(tr->dev);
kfree(tr);
}
static int tr_connect(struct serio *serio, struct serio_driver *drv)
{
struct tr *tr;
struct input_dev *input_dev;
int err;
tr = kzalloc(sizeof(struct tr), GFP_KERNEL);
input_dev = input_allocate_device();
if (!tr || !input_dev) {
err = -ENOMEM;
goto fail1;
}
tr->serio = serio;
tr->dev = input_dev;
snprintf(tr->phys, sizeof(tr->phys), "%s/input0", serio->phys);
input_dev->name = "Touchright Serial TouchScreen";
input_dev->phys = tr->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_TOUCHRIGHT;
input_dev->id.product = 0;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &serio->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input_dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(tr->dev, ABS_X, TR_MIN_XC, TR_MAX_XC, 0, 0);
input_set_abs_params(tr->dev, ABS_Y, TR_MIN_YC, TR_MAX_YC, 0, 0);
serio_set_drvdata(serio, tr);
err = serio_open(serio, drv);
if (err)
goto fail2;
err = input_register_device(tr->dev);
if (err)
goto fail3;
return 0;
fail3: serio_close(serio);
fail2: serio_set_drvdata(serio, NULL);
fail1: input_free_device(input_dev);
kfree(tr);
return err;
}
