static void tsc_process_data(struct tsc_ser *ptsc)
{
struct input_dev *dev = ptsc->dev;
u8 *data = ptsc->data;
u32 x;
u32 y;
x = ((data[1] & 0x03) << 8) | data[2];
y = ((data[3] & 0x03) << 8) | data[4];
input_report_abs(dev, ABS_X, x);
input_report_abs(dev, ABS_Y, y);
input_report_key(dev, BTN_TOUCH, 1);
input_sync(dev);
}
static irqreturn_t tsc_interrupt(struct serio *serio,
unsigned char data, unsigned int flags)
{
struct tsc_ser *ptsc = serio_get_drvdata(serio);
struct input_dev *dev = ptsc->dev;
ptsc->data[ptsc->idx] = data;
switch (ptsc->idx++) {
case 0:
if (unlikely((data & 0x3e) != 0x10)) {
dev_dbg(&serio->dev,
"unsynchronized packet start (0x%02x)\n", data);
ptsc->idx = 0;
} else if (!(data & 0x01)) {
input_report_key(dev, BTN_TOUCH, 0);
input_sync(dev);
ptsc->idx = 0;
}
break;
case 1:
case 3:
if (unlikely(data & 0xfc)) {
dev_dbg(&serio->dev,
"unsynchronized data 0x%02x at offset %d\n",
data, ptsc->idx - 1);
ptsc->idx = 0;
}
break;
case 4:
tsc_process_data(ptsc);
ptsc->idx = 0;
break;
}
return IRQ_HANDLED;
}
static int tsc_connect(struct serio *serio, struct serio_driver *drv)
{
struct tsc_ser *ptsc;
struct input_dev *input_dev;
int error;
ptsc = kzalloc(sizeof(struct tsc_ser), GFP_KERNEL);
input_dev = input_allocate_device();
if (!ptsc || !input_dev) {
error = -ENOMEM;
goto fail1;
}
ptsc->serio = serio;
ptsc->dev = input_dev;
snprintf(ptsc->phys, sizeof(ptsc->phys), "%s/input0", serio->phys);
input_dev->name = "TSC-10/25/40 Serial TouchScreen";
input_dev->phys = ptsc->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_TSC40;
input_dev->id.product = 40;
input_dev->id.version = 0x0001;
input_dev->dev.parent = &serio->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
__set_bit(BTN_TOUCH, input_dev->keybit);
input_set_abs_params(ptsc->dev, ABS_X, 0, 0x3ff, 0, 0);
input_set_abs_params(ptsc->dev, ABS_Y, 0, 0x3ff, 0, 0);
input_set_abs_params(ptsc->dev, ABS_PRESSURE, 0, 0, 0, 0);
serio_set_drvdata(serio, ptsc);
error = serio_open(serio, drv);
if (error)
goto fail2;
error = input_register_device(ptsc->dev);
if (error)
goto fail3;
return 0;
fail3:
serio_close(serio);
fail2:
serio_set_drvdata(serio, NULL);
fail1:
input_free_device(input_dev);
kfree(ptsc);
return error;
}
static void tsc_disconnect(struct serio *serio)
{
struct tsc_ser *ptsc = serio_get_drvdata(serio);
serio_close(serio);
input_unregister_device(ptsc->dev);
kfree(ptsc);
serio_set_drvdata(serio, NULL);
}
static int __init tsc_ser_init(void)
{
return serio_register_driver(&tsc_drv);
}
static void __exit tsc_exit(void)
{
serio_unregister_driver(&tsc_drv);
}
