static void hampshire_process_data(struct hampshire *phampshire)
{
struct input_dev *dev = phampshire->dev;
if (HAMPSHIRE_FORMAT_LENGTH == ++phampshire->idx) {
input_report_abs(dev, ABS_X, HAMPSHIRE_GET_XC(phampshire->data));
input_report_abs(dev, ABS_Y, HAMPSHIRE_GET_YC(phampshire->data));
input_report_key(dev, BTN_TOUCH,
HAMPSHIRE_GET_TOUCHED(phampshire->data));
input_sync(dev);
phampshire->idx = 0;
}
}
static irqreturn_t hampshire_interrupt(struct serio *serio,
unsigned char data, unsigned int flags)
{
struct hampshire *phampshire = serio_get_drvdata(serio);
phampshire->data[phampshire->idx] = data;
if (HAMPSHIRE_RESPONSE_BEGIN_BYTE & phampshire->data[0])
hampshire_process_data(phampshire);
else
dev_dbg(&serio->dev, "unknown/unsynchronized data: %x\n",
phampshire->data[0]);
return IRQ_HANDLED;
}
static void hampshire_disconnect(struct serio *serio)
{
struct hampshire *phampshire = serio_get_drvdata(serio);
input_get_device(phampshire->dev);
input_unregister_device(phampshire->dev);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_put_device(phampshire->dev);
kfree(phampshire);
}
static int hampshire_connect(struct serio *serio, struct serio_driver *drv)
{
struct hampshire *phampshire;
struct input_dev *input_dev;
int err;
phampshire = kzalloc(sizeof(struct hampshire), GFP_KERNEL);
input_dev = input_allocate_device();
if (!phampshire || !input_dev) {
err = -ENOMEM;
goto fail1;
}
phampshire->serio = serio;
phampshire->dev = input_dev;
snprintf(phampshire->phys, sizeof(phampshire->phys),
"%s/input0", serio->phys);
input_dev->name = "Hampshire Serial TouchScreen";
input_dev->phys = phampshire->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_HAMPSHIRE;
input_dev->id.product = 0;
input_dev->id.version = 0x0001;
input_dev->dev.parent = &serio->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input_dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(phampshire->dev, ABS_X,
HAMPSHIRE_MIN_XC, HAMPSHIRE_MAX_XC, 0, 0);
input_set_abs_params(phampshire->dev, ABS_Y,
HAMPSHIRE_MIN_YC, HAMPSHIRE_MAX_YC, 0, 0);
serio_set_drvdata(serio, phampshire);
err = serio_open(serio, drv);
if (err)
goto fail2;
err = input_register_device(phampshire->dev);
if (err)
goto fail3;
return 0;
fail3: serio_close(serio);
fail2: serio_set_drvdata(serio, NULL);
fail1: input_free_device(input_dev);
kfree(phampshire);
return err;
}
