static void warrior_process_packet(struct warrior *warrior)
{
struct input_dev *dev = warrior->dev;
unsigned char *data = warrior->data;
if (!warrior->idx) return;
switch ((data[0] >> 4) & 7) {
case 1:
input_report_key(dev, BTN_TRIGGER, data[3] & 1);
input_report_key(dev, BTN_THUMB, (data[3] >> 1) & 1);
input_report_key(dev, BTN_TOP, (data[3] >> 2) & 1);
input_report_key(dev, BTN_TOP2, (data[3] >> 3) & 1);
break;
case 3:
input_report_abs(dev, ABS_X, ((data[0] & 8) << 5) - (data[2] | ((data[0] & 4) << 5)));
input_report_abs(dev, ABS_Y, (data[1] | ((data[0] & 1) << 7)) - ((data[0] & 2) << 7));
break;
case 5:
input_report_abs(dev, ABS_THROTTLE, (data[1] | ((data[0] & 1) << 7)) - ((data[0] & 2) << 7));
input_report_abs(dev, ABS_HAT0X, (data[3] & 2 ? 1 : 0) - (data[3] & 1 ? 1 : 0));
input_report_abs(dev, ABS_HAT0Y, (data[3] & 8 ? 1 : 0) - (data[3] & 4 ? 1 : 0));
input_report_rel(dev, REL_DIAL, (data[2] | ((data[0] & 4) << 5)) - ((data[0] & 8) << 5));
break;
}
input_sync(dev);
}
static irqreturn_t warrior_interrupt(struct serio *serio,
unsigned char data, unsigned int flags)
{
struct warrior *warrior = serio_get_drvdata(serio);
if (data & 0x80) {
if (warrior->idx) warrior_process_packet(warrior);
warrior->idx = 0;
warrior->len = warrior_lengths[(data >> 4) & 7];
}
if (warrior->idx < warrior->len)
warrior->data[warrior->idx++] = data;
if (warrior->idx == warrior->len) {
if (warrior->idx) warrior_process_packet(warrior);
warrior->idx = 0;
warrior->len = 0;
}
return IRQ_HANDLED;
}
static void warrior_disconnect(struct serio *serio)
{
struct warrior *warrior = serio_get_drvdata(serio);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_unregister_device(warrior->dev);
kfree(warrior);
}
static int warrior_connect(struct serio *serio, struct serio_driver *drv)
{
struct warrior *warrior;
struct input_dev *input_dev;
int err = -ENOMEM;
warrior = kzalloc(sizeof(struct warrior), GFP_KERNEL);
input_dev = input_allocate_device();
if (!warrior || !input_dev)
goto fail1;
warrior->dev = input_dev;
snprintf(warrior->phys, sizeof(warrior->phys), "%s/input0", serio->phys);
input_dev->name = "Logitech WingMan Warrior";
input_dev->phys = warrior->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_WARRIOR;
input_dev->id.product = 0x0001;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &serio->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REL) |
BIT_MASK(EV_ABS);
input_dev->keybit[BIT_WORD(BTN_TRIGGER)] = BIT_MASK(BTN_TRIGGER) |
BIT_MASK(BTN_THUMB) | BIT_MASK(BTN_TOP) | BIT_MASK(BTN_TOP2);
input_dev->relbit[0] = BIT_MASK(REL_DIAL);
input_set_abs_params(input_dev, ABS_X, -64, 64, 0, 8);
input_set_abs_params(input_dev, ABS_Y, -64, 64, 0, 8);
input_set_abs_params(input_dev, ABS_THROTTLE, -112, 112, 0, 0);
input_set_abs_params(input_dev, ABS_HAT0X, -1, 1, 0, 0);
input_set_abs_params(input_dev, ABS_HAT0Y, -1, 1, 0, 0);
serio_set_drvdata(serio, warrior);
err = serio_open(serio, drv);
if (err)
goto fail2;
err = input_register_device(warrior->dev);
if (err)
goto fail3;
return 0;
fail3: serio_close(serio);
fail2: serio_set_drvdata(serio, NULL);
fail1: input_free_device(input_dev);
kfree(warrior);
return err;
}
static int __init warrior_init(void)
{
return serio_register_driver(&warrior_drv);
}
static void __exit warrior_exit(void)
{
serio_unregister_driver(&warrior_drv);
}
