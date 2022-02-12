static void dynapro_process_data(struct dynapro *pdynapro)
{
struct input_dev *dev = pdynapro->dev;
if (DYNAPRO_FORMAT_LENGTH == ++pdynapro->idx) {
input_report_abs(dev, ABS_X, DYNAPRO_GET_XC(pdynapro->data));
input_report_abs(dev, ABS_Y, DYNAPRO_GET_YC(pdynapro->data));
input_report_key(dev, BTN_TOUCH,
DYNAPRO_GET_TOUCHED(pdynapro->data));
input_sync(dev);
pdynapro->idx = 0;
}
}
static irqreturn_t dynapro_interrupt(struct serio *serio,
unsigned char data, unsigned int flags)
{
struct dynapro *pdynapro = serio_get_drvdata(serio);
pdynapro->data[pdynapro->idx] = data;
if (DYNAPRO_RESPONSE_BEGIN_BYTE & pdynapro->data[0])
dynapro_process_data(pdynapro);
else
dev_dbg(&serio->dev, "unknown/unsynchronized data: %x\n",
pdynapro->data[0]);
return IRQ_HANDLED;
}
static void dynapro_disconnect(struct serio *serio)
{
struct dynapro *pdynapro = serio_get_drvdata(serio);
input_get_device(pdynapro->dev);
input_unregister_device(pdynapro->dev);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_put_device(pdynapro->dev);
kfree(pdynapro);
}
static int dynapro_connect(struct serio *serio, struct serio_driver *drv)
{
struct dynapro *pdynapro;
struct input_dev *input_dev;
int err;
pdynapro = kzalloc(sizeof(struct dynapro), GFP_KERNEL);
input_dev = input_allocate_device();
if (!pdynapro || !input_dev) {
err = -ENOMEM;
goto fail1;
}
pdynapro->serio = serio;
pdynapro->dev = input_dev;
snprintf(pdynapro->phys, sizeof(pdynapro->phys),
"%s/input0", serio->phys);
input_dev->name = "Dynapro Serial TouchScreen";
input_dev->phys = pdynapro->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_DYNAPRO;
input_dev->id.product = 0;
input_dev->id.version = 0x0001;
input_dev->dev.parent = &serio->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input_dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(pdynapro->dev, ABS_X,
DYNAPRO_MIN_XC, DYNAPRO_MAX_XC, 0, 0);
input_set_abs_params(pdynapro->dev, ABS_Y,
DYNAPRO_MIN_YC, DYNAPRO_MAX_YC, 0, 0);
serio_set_drvdata(serio, pdynapro);
err = serio_open(serio, drv);
if (err)
goto fail2;
err = input_register_device(pdynapro->dev);
if (err)
goto fail3;
return 0;
fail3: serio_close(serio);
fail2: serio_set_drvdata(serio, NULL);
fail1: input_free_device(input_dev);
kfree(pdynapro);
return err;
}
static int __init dynapro_init(void)
{
return serio_register_driver(&dynapro_drv);
}
static void __exit dynapro_exit(void)
{
serio_unregister_driver(&dynapro_drv);
}
