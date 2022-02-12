static irqreturn_t skbd_interrupt(struct serio *serio, unsigned char data,
unsigned int flags)
{
struct skbd *skbd = serio_get_drvdata(serio);
struct input_dev *dev = skbd->dev;
if (skbd->keycode[data & SKBD_KEY_MASK]) {
input_report_key(dev, skbd->keycode[data & SKBD_KEY_MASK],
!(data & SKBD_RELEASE));
input_sync(dev);
}
return IRQ_HANDLED;
}
static int skbd_connect(struct serio *serio, struct serio_driver *drv)
{
struct skbd *skbd;
struct input_dev *input_dev;
int err = -ENOMEM;
int i;
skbd = kzalloc(sizeof(struct skbd), GFP_KERNEL);
input_dev = input_allocate_device();
if (!skbd || !input_dev)
goto fail1;
skbd->serio = serio;
skbd->dev = input_dev;
snprintf(skbd->phys, sizeof(skbd->phys), "%s/input0", serio->phys);
memcpy(skbd->keycode, skbd_keycode, sizeof(skbd->keycode));
input_dev->name = "Stowaway Keyboard";
input_dev->phys = skbd->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_STOWAWAY;
input_dev->id.product = 0x0001;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &serio->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REP);
input_dev->keycode = skbd->keycode;
input_dev->keycodesize = sizeof(unsigned char);
input_dev->keycodemax = ARRAY_SIZE(skbd_keycode);
for (i = 0; i < ARRAY_SIZE(skbd_keycode); i++)
set_bit(skbd_keycode[i], input_dev->keybit);
clear_bit(0, input_dev->keybit);
serio_set_drvdata(serio, skbd);
err = serio_open(serio, drv);
if (err)
goto fail2;
err = input_register_device(skbd->dev);
if (err)
goto fail3;
return 0;
fail3: serio_close(serio);
fail2: serio_set_drvdata(serio, NULL);
fail1: input_free_device(input_dev);
kfree(skbd);
return err;
}
static void skbd_disconnect(struct serio *serio)
{
struct skbd *skbd = serio_get_drvdata(serio);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_unregister_device(skbd->dev);
kfree(skbd);
}
