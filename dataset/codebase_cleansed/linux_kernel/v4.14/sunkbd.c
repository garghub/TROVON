static irqreturn_t sunkbd_interrupt(struct serio *serio,
unsigned char data, unsigned int flags)
{
struct sunkbd *sunkbd = serio_get_drvdata(serio);
if (sunkbd->reset <= -1) {
sunkbd->reset = data;
wake_up_interruptible(&sunkbd->wait);
goto out;
}
if (sunkbd->layout == -1) {
sunkbd->layout = data;
wake_up_interruptible(&sunkbd->wait);
goto out;
}
switch (data) {
case SUNKBD_RET_RESET:
schedule_work(&sunkbd->tq);
sunkbd->reset = -1;
break;
case SUNKBD_RET_LAYOUT:
sunkbd->layout = -1;
break;
case SUNKBD_RET_ALLUP:
break;
default:
if (!sunkbd->enabled)
break;
if (sunkbd->keycode[data & SUNKBD_KEY]) {
input_report_key(sunkbd->dev,
sunkbd->keycode[data & SUNKBD_KEY],
!(data & SUNKBD_RELEASE));
input_sync(sunkbd->dev);
} else {
printk(KERN_WARNING
"sunkbd.c: Unknown key (scancode %#x) %s.\n",
data & SUNKBD_KEY,
data & SUNKBD_RELEASE ? "released" : "pressed");
}
}
out:
return IRQ_HANDLED;
}
static int sunkbd_event(struct input_dev *dev,
unsigned int type, unsigned int code, int value)
{
struct sunkbd *sunkbd = input_get_drvdata(dev);
switch (type) {
case EV_LED:
serio_write(sunkbd->serio, SUNKBD_CMD_SETLED);
serio_write(sunkbd->serio,
(!!test_bit(LED_CAPSL, dev->led) << 3) |
(!!test_bit(LED_SCROLLL, dev->led) << 2) |
(!!test_bit(LED_COMPOSE, dev->led) << 1) |
!!test_bit(LED_NUML, dev->led));
return 0;
case EV_SND:
switch (code) {
case SND_CLICK:
serio_write(sunkbd->serio, SUNKBD_CMD_NOCLICK - value);
return 0;
case SND_BELL:
serio_write(sunkbd->serio, SUNKBD_CMD_BELLOFF - value);
return 0;
}
break;
}
return -1;
}
static int sunkbd_initialize(struct sunkbd *sunkbd)
{
sunkbd->reset = -2;
serio_write(sunkbd->serio, SUNKBD_CMD_RESET);
wait_event_interruptible_timeout(sunkbd->wait, sunkbd->reset >= 0, HZ);
if (sunkbd->reset < 0)
return -1;
sunkbd->type = sunkbd->reset;
if (sunkbd->type == 4) {
sunkbd->layout = -2;
serio_write(sunkbd->serio, SUNKBD_CMD_LAYOUT);
wait_event_interruptible_timeout(sunkbd->wait,
sunkbd->layout >= 0, HZ / 4);
if (sunkbd->layout < 0)
return -1;
if (sunkbd->layout & SUNKBD_LAYOUT_5_MASK)
sunkbd->type = 5;
}
return 0;
}
static void sunkbd_reinit(struct work_struct *work)
{
struct sunkbd *sunkbd = container_of(work, struct sunkbd, tq);
wait_event_interruptible_timeout(sunkbd->wait, sunkbd->reset >= 0, HZ);
serio_write(sunkbd->serio, SUNKBD_CMD_SETLED);
serio_write(sunkbd->serio,
(!!test_bit(LED_CAPSL, sunkbd->dev->led) << 3) |
(!!test_bit(LED_SCROLLL, sunkbd->dev->led) << 2) |
(!!test_bit(LED_COMPOSE, sunkbd->dev->led) << 1) |
!!test_bit(LED_NUML, sunkbd->dev->led));
serio_write(sunkbd->serio,
SUNKBD_CMD_NOCLICK - !!test_bit(SND_CLICK, sunkbd->dev->snd));
serio_write(sunkbd->serio,
SUNKBD_CMD_BELLOFF - !!test_bit(SND_BELL, sunkbd->dev->snd));
}
static void sunkbd_enable(struct sunkbd *sunkbd, bool enable)
{
serio_pause_rx(sunkbd->serio);
sunkbd->enabled = enable;
serio_continue_rx(sunkbd->serio);
}
static int sunkbd_connect(struct serio *serio, struct serio_driver *drv)
{
struct sunkbd *sunkbd;
struct input_dev *input_dev;
int err = -ENOMEM;
int i;
sunkbd = kzalloc(sizeof(struct sunkbd), GFP_KERNEL);
input_dev = input_allocate_device();
if (!sunkbd || !input_dev)
goto fail1;
sunkbd->serio = serio;
sunkbd->dev = input_dev;
init_waitqueue_head(&sunkbd->wait);
INIT_WORK(&sunkbd->tq, sunkbd_reinit);
snprintf(sunkbd->phys, sizeof(sunkbd->phys), "%s/input0", serio->phys);
serio_set_drvdata(serio, sunkbd);
err = serio_open(serio, drv);
if (err)
goto fail2;
if (sunkbd_initialize(sunkbd) < 0) {
err = -ENODEV;
goto fail3;
}
snprintf(sunkbd->name, sizeof(sunkbd->name),
"Sun Type %d keyboard", sunkbd->type);
memcpy(sunkbd->keycode, sunkbd_keycode, sizeof(sunkbd->keycode));
input_dev->name = sunkbd->name;
input_dev->phys = sunkbd->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_SUNKBD;
input_dev->id.product = sunkbd->type;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &serio->dev;
input_set_drvdata(input_dev, sunkbd);
input_dev->event = sunkbd_event;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_LED) |
BIT_MASK(EV_SND) | BIT_MASK(EV_REP);
input_dev->ledbit[0] = BIT_MASK(LED_CAPSL) | BIT_MASK(LED_COMPOSE) |
BIT_MASK(LED_SCROLLL) | BIT_MASK(LED_NUML);
input_dev->sndbit[0] = BIT_MASK(SND_CLICK) | BIT_MASK(SND_BELL);
input_dev->keycode = sunkbd->keycode;
input_dev->keycodesize = sizeof(unsigned char);
input_dev->keycodemax = ARRAY_SIZE(sunkbd_keycode);
for (i = 0; i < ARRAY_SIZE(sunkbd_keycode); i++)
__set_bit(sunkbd->keycode[i], input_dev->keybit);
__clear_bit(KEY_RESERVED, input_dev->keybit);
sunkbd_enable(sunkbd, true);
err = input_register_device(sunkbd->dev);
if (err)
goto fail4;
return 0;
fail4: sunkbd_enable(sunkbd, false);
fail3: serio_close(serio);
fail2: serio_set_drvdata(serio, NULL);
fail1: input_free_device(input_dev);
kfree(sunkbd);
return err;
}
static void sunkbd_disconnect(struct serio *serio)
{
struct sunkbd *sunkbd = serio_get_drvdata(serio);
sunkbd_enable(sunkbd, false);
input_unregister_device(sunkbd->dev);
serio_close(serio);
serio_set_drvdata(serio, NULL);
kfree(sunkbd);
}
