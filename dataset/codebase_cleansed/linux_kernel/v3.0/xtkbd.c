static irqreturn_t xtkbd_interrupt(struct serio *serio,
unsigned char data, unsigned int flags)
{
struct xtkbd *xtkbd = serio_get_drvdata(serio);
switch (data) {
case XTKBD_EMUL0:
case XTKBD_EMUL1:
break;
default:
if (xtkbd->keycode[data & XTKBD_KEY]) {
input_report_key(xtkbd->dev, xtkbd->keycode[data & XTKBD_KEY], !(data & XTKBD_RELEASE));
input_sync(xtkbd->dev);
} else {
printk(KERN_WARNING "xtkbd.c: Unknown key (scancode %#x) %s.\n",
data & XTKBD_KEY, data & XTKBD_RELEASE ? "released" : "pressed");
}
}
return IRQ_HANDLED;
}
static int xtkbd_connect(struct serio *serio, struct serio_driver *drv)
{
struct xtkbd *xtkbd;
struct input_dev *input_dev;
int err = -ENOMEM;
int i;
xtkbd = kmalloc(sizeof(struct xtkbd), GFP_KERNEL);
input_dev = input_allocate_device();
if (!xtkbd || !input_dev)
goto fail1;
xtkbd->serio = serio;
xtkbd->dev = input_dev;
snprintf(xtkbd->phys, sizeof(xtkbd->phys), "%s/input0", serio->phys);
memcpy(xtkbd->keycode, xtkbd_keycode, sizeof(xtkbd->keycode));
input_dev->name = "XT Keyboard";
input_dev->phys = xtkbd->phys;
input_dev->id.bustype = BUS_XTKBD;
input_dev->id.vendor = 0x0001;
input_dev->id.product = 0x0001;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &serio->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REP);
input_dev->keycode = xtkbd->keycode;
input_dev->keycodesize = sizeof(unsigned char);
input_dev->keycodemax = ARRAY_SIZE(xtkbd_keycode);
for (i = 0; i < 255; i++)
set_bit(xtkbd->keycode[i], input_dev->keybit);
clear_bit(0, input_dev->keybit);
serio_set_drvdata(serio, xtkbd);
err = serio_open(serio, drv);
if (err)
goto fail2;
err = input_register_device(xtkbd->dev);
if (err)
goto fail3;
return 0;
fail3: serio_close(serio);
fail2: serio_set_drvdata(serio, NULL);
fail1: input_free_device(input_dev);
kfree(xtkbd);
return err;
}
static void xtkbd_disconnect(struct serio *serio)
{
struct xtkbd *xtkbd = serio_get_drvdata(serio);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_unregister_device(xtkbd->dev);
kfree(xtkbd);
}
static int __init xtkbd_init(void)
{
return serio_register_driver(&xtkbd_drv);
}
static void __exit xtkbd_exit(void)
{
serio_unregister_driver(&xtkbd_drv);
}
