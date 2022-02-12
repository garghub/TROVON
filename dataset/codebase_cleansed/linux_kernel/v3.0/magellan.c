static int magellan_crunch_nibbles(unsigned char *data, int count)
{
static unsigned char nibbles[16] = "0AB3D56GH9:K<MN?";
do {
if (data[count] == nibbles[data[count] & 0xf])
data[count] = data[count] & 0xf;
else
return -1;
} while (--count);
return 0;
}
static void magellan_process_packet(struct magellan* magellan)
{
struct input_dev *dev = magellan->dev;
unsigned char *data = magellan->data;
int i, t;
if (!magellan->idx) return;
switch (magellan->data[0]) {
case 'd':
if (magellan->idx != 25) return;
if (magellan_crunch_nibbles(data, 24)) return;
for (i = 0; i < 6; i++)
input_report_abs(dev, magellan_axes[i],
(data[(i << 2) + 1] << 12 | data[(i << 2) + 2] << 8 |
data[(i << 2) + 3] << 4 | data[(i << 2) + 4]) - 32768);
break;
case 'k':
if (magellan->idx != 4) return;
if (magellan_crunch_nibbles(data, 3)) return;
t = (data[1] << 1) | (data[2] << 5) | data[3];
for (i = 0; i < 9; i++) input_report_key(dev, magellan_buttons[i], (t >> i) & 1);
break;
}
input_sync(dev);
}
static irqreturn_t magellan_interrupt(struct serio *serio,
unsigned char data, unsigned int flags)
{
struct magellan* magellan = serio_get_drvdata(serio);
if (data == '\r') {
magellan_process_packet(magellan);
magellan->idx = 0;
} else {
if (magellan->idx < MAGELLAN_MAX_LENGTH)
magellan->data[magellan->idx++] = data;
}
return IRQ_HANDLED;
}
static void magellan_disconnect(struct serio *serio)
{
struct magellan* magellan = serio_get_drvdata(serio);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_unregister_device(magellan->dev);
kfree(magellan);
}
static int magellan_connect(struct serio *serio, struct serio_driver *drv)
{
struct magellan *magellan;
struct input_dev *input_dev;
int err = -ENOMEM;
int i;
magellan = kzalloc(sizeof(struct magellan), GFP_KERNEL);
input_dev = input_allocate_device();
if (!magellan || !input_dev)
goto fail1;
magellan->dev = input_dev;
snprintf(magellan->phys, sizeof(magellan->phys), "%s/input0", serio->phys);
input_dev->name = "LogiCad3D Magellan / SpaceMouse";
input_dev->phys = magellan->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_MAGELLAN;
input_dev->id.product = 0x0001;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &serio->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
for (i = 0; i < 9; i++)
set_bit(magellan_buttons[i], input_dev->keybit);
for (i = 0; i < 6; i++)
input_set_abs_params(input_dev, magellan_axes[i], -360, 360, 0, 0);
serio_set_drvdata(serio, magellan);
err = serio_open(serio, drv);
if (err)
goto fail2;
err = input_register_device(magellan->dev);
if (err)
goto fail3;
return 0;
fail3: serio_close(serio);
fail2: serio_set_drvdata(serio, NULL);
fail1: input_free_device(input_dev);
kfree(magellan);
return err;
}
static int __init magellan_init(void)
{
return serio_register_driver(&magellan_drv);
}
static void __exit magellan_exit(void)
{
serio_unregister_driver(&magellan_drv);
}
