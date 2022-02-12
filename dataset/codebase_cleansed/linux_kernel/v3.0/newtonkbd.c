static irqreturn_t nkbd_interrupt(struct serio *serio,
unsigned char data, unsigned int flags)
{
struct nkbd *nkbd = serio_get_drvdata(serio);
if (nkbd->keycode[data & NKBD_KEY]) {
input_report_key(nkbd->dev, nkbd->keycode[data & NKBD_KEY], data & NKBD_PRESS);
input_sync(nkbd->dev);
}
else if (data == 0xe7)
printk(KERN_INFO "input: %s on %s\n", nkbd->dev->name, serio->phys);
return IRQ_HANDLED;
}
static int nkbd_connect(struct serio *serio, struct serio_driver *drv)
{
struct nkbd *nkbd;
struct input_dev *input_dev;
int err = -ENOMEM;
int i;
nkbd = kzalloc(sizeof(struct nkbd), GFP_KERNEL);
input_dev = input_allocate_device();
if (!nkbd || !input_dev)
goto fail1;
nkbd->serio = serio;
nkbd->dev = input_dev;
snprintf(nkbd->phys, sizeof(nkbd->phys), "%s/input0", serio->phys);
memcpy(nkbd->keycode, nkbd_keycode, sizeof(nkbd->keycode));
input_dev->name = "Newton Keyboard";
input_dev->phys = nkbd->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_NEWTON;
input_dev->id.product = 0x0001;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &serio->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REP);
input_dev->keycode = nkbd->keycode;
input_dev->keycodesize = sizeof(unsigned char);
input_dev->keycodemax = ARRAY_SIZE(nkbd_keycode);
for (i = 0; i < 128; i++)
set_bit(nkbd->keycode[i], input_dev->keybit);
clear_bit(0, input_dev->keybit);
serio_set_drvdata(serio, nkbd);
err = serio_open(serio, drv);
if (err)
goto fail2;
err = input_register_device(nkbd->dev);
if (err)
goto fail3;
return 0;
fail3: serio_close(serio);
fail2: serio_set_drvdata(serio, NULL);
fail1: input_free_device(input_dev);
kfree(nkbd);
return err;
}
static void nkbd_disconnect(struct serio *serio)
{
struct nkbd *nkbd = serio_get_drvdata(serio);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_unregister_device(nkbd->dev);
kfree(nkbd);
}
static int __init nkbd_init(void)
{
return serio_register_driver(&nkbd_drv);
}
static void __exit nkbd_exit(void)
{
serio_unregister_driver(&nkbd_drv);
}
