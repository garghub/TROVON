static void twidjoy_process_packet(struct twidjoy *twidjoy)
{
struct input_dev *dev = twidjoy->dev;
unsigned char *data = twidjoy->data;
struct twidjoy_button_spec *bp;
int button_bits, abs_x, abs_y;
button_bits = ((data[1] & 0x7f) << 7) | (data[0] & 0x7f);
for (bp = twidjoy_buttons; bp->bitmask; bp++) {
int value = (button_bits & (bp->bitmask << bp->bitshift)) >> bp->bitshift;
int i;
for (i = 0; i < bp->bitmask; i++)
input_report_key(dev, bp->buttons[i], i+1 == value);
}
abs_x = ((data[4] & 0x07) << 5) | ((data[3] & 0x7C) >> 2);
if (data[4] & 0x08) abs_x -= 256;
abs_y = ((data[3] & 0x01) << 7) | ((data[2] & 0x7F) >> 0);
if (data[3] & 0x02) abs_y -= 256;
input_report_abs(dev, ABS_X, -abs_x);
input_report_abs(dev, ABS_Y, +abs_y);
input_sync(dev);
}
static irqreturn_t twidjoy_interrupt(struct serio *serio, unsigned char data, unsigned int flags)
{
struct twidjoy *twidjoy = serio_get_drvdata(serio);
if ((data & 0x80) == 0)
twidjoy->idx = 0;
else if (twidjoy->idx == 0)
return IRQ_HANDLED;
if (twidjoy->idx < TWIDJOY_MAX_LENGTH)
twidjoy->data[twidjoy->idx++] = data;
if (twidjoy->idx == TWIDJOY_MAX_LENGTH) {
twidjoy_process_packet(twidjoy);
twidjoy->idx = 0;
}
return IRQ_HANDLED;
}
static void twidjoy_disconnect(struct serio *serio)
{
struct twidjoy *twidjoy = serio_get_drvdata(serio);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_unregister_device(twidjoy->dev);
kfree(twidjoy);
}
static int twidjoy_connect(struct serio *serio, struct serio_driver *drv)
{
struct twidjoy_button_spec *bp;
struct twidjoy *twidjoy;
struct input_dev *input_dev;
int err = -ENOMEM;
int i;
twidjoy = kzalloc(sizeof(struct twidjoy), GFP_KERNEL);
input_dev = input_allocate_device();
if (!twidjoy || !input_dev)
goto fail1;
twidjoy->dev = input_dev;
snprintf(twidjoy->phys, sizeof(twidjoy->phys), "%s/input0", serio->phys);
input_dev->name = "Handykey Twiddler";
input_dev->phys = twidjoy->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_TWIDJOY;
input_dev->id.product = 0x0001;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &serio->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input_set_abs_params(input_dev, ABS_X, -50, 50, 4, 4);
input_set_abs_params(input_dev, ABS_Y, -50, 50, 4, 4);
for (bp = twidjoy_buttons; bp->bitmask; bp++)
for (i = 0; i < bp->bitmask; i++)
set_bit(bp->buttons[i], input_dev->keybit);
serio_set_drvdata(serio, twidjoy);
err = serio_open(serio, drv);
if (err)
goto fail2;
err = input_register_device(twidjoy->dev);
if (err)
goto fail3;
return 0;
fail3: serio_close(serio);
fail2: serio_set_drvdata(serio, NULL);
fail1: input_free_device(input_dev);
kfree(twidjoy);
return err;
}
static int __init twidjoy_init(void)
{
return serio_register_driver(&twidjoy_drv);
}
static void __exit twidjoy_exit(void)
{
serio_unregister_driver(&twidjoy_drv);
}
