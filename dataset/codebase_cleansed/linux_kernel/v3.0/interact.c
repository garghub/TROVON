static int interact_read_packet(struct gameport *gameport, int length, u32 *data)
{
unsigned long flags;
unsigned char u, v;
unsigned int t, s;
int i;
i = 0;
data[0] = data[1] = data[2] = 0;
t = gameport_time(gameport, INTERACT_MAX_START);
s = gameport_time(gameport, INTERACT_MAX_STROBE);
local_irq_save(flags);
gameport_trigger(gameport);
v = gameport_read(gameport);
while (t > 0 && i < length) {
t--;
u = v; v = gameport_read(gameport);
if (v & ~u & 0x40) {
data[0] = (data[0] << 1) | ((v >> 4) & 1);
data[1] = (data[1] << 1) | ((v >> 5) & 1);
data[2] = (data[2] << 1) | ((v >> 7) & 1);
i++;
t = s;
}
}
local_irq_restore(flags);
return i;
}
static void interact_poll(struct gameport *gameport)
{
struct interact *interact = gameport_get_drvdata(gameport);
struct input_dev *dev = interact->dev;
u32 data[3];
int i;
interact->reads++;
if (interact_read_packet(interact->gameport, interact->length, data) < interact->length) {
interact->bads++;
} else {
for (i = 0; i < 3; i++)
data[i] <<= INTERACT_MAX_LENGTH - interact->length;
switch (interact->type) {
case INTERACT_TYPE_HHFX:
for (i = 0; i < 4; i++)
input_report_abs(dev, interact_abs_hhfx[i], (data[i & 1] >> ((i >> 1) << 3)) & 0xff);
for (i = 0; i < 2; i++)
input_report_abs(dev, ABS_HAT0Y - i,
((data[1] >> ((i << 1) + 17)) & 1) - ((data[1] >> ((i << 1) + 16)) & 1));
for (i = 0; i < 8; i++)
input_report_key(dev, interact_btn_hhfx[i], (data[0] >> (i + 16)) & 1);
for (i = 0; i < 4; i++)
input_report_key(dev, interact_btn_hhfx[i + 8], (data[1] >> (i + 20)) & 1);
break;
case INTERACT_TYPE_PP8D:
for (i = 0; i < 2; i++)
input_report_abs(dev, interact_abs_pp8d[i],
((data[0] >> ((i << 1) + 20)) & 1) - ((data[0] >> ((i << 1) + 21)) & 1));
for (i = 0; i < 8; i++)
input_report_key(dev, interact_btn_pp8d[i], (data[1] >> (i + 16)) & 1);
break;
}
}
input_sync(dev);
}
static int interact_open(struct input_dev *dev)
{
struct interact *interact = input_get_drvdata(dev);
gameport_start_polling(interact->gameport);
return 0;
}
static void interact_close(struct input_dev *dev)
{
struct interact *interact = input_get_drvdata(dev);
gameport_stop_polling(interact->gameport);
}
static int interact_connect(struct gameport *gameport, struct gameport_driver *drv)
{
struct interact *interact;
struct input_dev *input_dev;
__u32 data[3];
int i, t;
int err;
interact = kzalloc(sizeof(struct interact), GFP_KERNEL);
input_dev = input_allocate_device();
if (!interact || !input_dev) {
err = -ENOMEM;
goto fail1;
}
interact->gameport = gameport;
interact->dev = input_dev;
gameport_set_drvdata(gameport, interact);
err = gameport_open(gameport, drv, GAMEPORT_MODE_RAW);
if (err)
goto fail1;
i = interact_read_packet(gameport, INTERACT_MAX_LENGTH * 2, data);
if (i != 32 || (data[0] >> 24) != 0x0c || (data[1] >> 24) != 0x02) {
err = -ENODEV;
goto fail2;
}
for (i = 0; interact_type[i].length; i++)
if (interact_type[i].id == (data[2] >> 16))
break;
if (!interact_type[i].length) {
printk(KERN_WARNING "interact.c: Unknown joystick on %s. [len %d d0 %08x d1 %08x i2 %08x]\n",
gameport->phys, i, data[0], data[1], data[2]);
err = -ENODEV;
goto fail2;
}
gameport_set_poll_handler(gameport, interact_poll);
gameport_set_poll_interval(gameport, 20);
snprintf(interact->phys, sizeof(interact->phys), "%s/input0", gameport->phys);
interact->type = i;
interact->length = interact_type[i].length;
input_dev->name = interact_type[i].name;
input_dev->phys = interact->phys;
input_dev->id.bustype = BUS_GAMEPORT;
input_dev->id.vendor = GAMEPORT_ID_VENDOR_INTERACT;
input_dev->id.product = interact_type[i].id;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &gameport->dev;
input_set_drvdata(input_dev, interact);
input_dev->open = interact_open;
input_dev->close = interact_close;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
for (i = 0; (t = interact_type[interact->type].abs[i]) >= 0; i++) {
if (i < interact_type[interact->type].b8)
input_set_abs_params(input_dev, t, 0, 255, 0, 0);
else
input_set_abs_params(input_dev, t, -1, 1, 0, 0);
}
for (i = 0; (t = interact_type[interact->type].btn[i]) >= 0; i++)
__set_bit(t, input_dev->keybit);
err = input_register_device(interact->dev);
if (err)
goto fail2;
return 0;
fail2: gameport_close(gameport);
fail1: gameport_set_drvdata(gameport, NULL);
input_free_device(input_dev);
kfree(interact);
return err;
}
static void interact_disconnect(struct gameport *gameport)
{
struct interact *interact = gameport_get_drvdata(gameport);
input_unregister_device(interact->dev);
gameport_close(gameport);
gameport_set_drvdata(gameport, NULL);
kfree(interact);
}
static int __init interact_init(void)
{
return gameport_register_driver(&interact_drv);
}
static void __exit interact_exit(void)
{
gameport_unregister_driver(&interact_drv);
}
