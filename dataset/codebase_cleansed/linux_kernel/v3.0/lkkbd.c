static unsigned char *response_name(unsigned char value)
{
int i;
for (i = 0; i < ARRAY_SIZE(lk_response); i++)
if (lk_response[i].value == value)
return lk_response[i].name;
return "<unknown>";
}
static unsigned char volume_to_hw(int volume_percent)
{
unsigned char ret = 0;
if (volume_percent < 0)
volume_percent = 0;
if (volume_percent > 100)
volume_percent = 100;
if (volume_percent >= 0)
ret = 7;
if (volume_percent >= 13)
ret = 6;
if (volume_percent >= 25)
ret = 5;
if (volume_percent >= 38)
ret = 4;
if (volume_percent >= 50)
ret = 3;
if (volume_percent >= 63)
ret = 2;
if (volume_percent >= 75)
ret = 1;
if (volume_percent >= 88)
ret = 0;
ret |= 0x80;
return ret;
}
static void lkkbd_detection_done(struct lkkbd *lk)
{
int i;
lk->keycode[0xb1] = KEY_COMPOSE;
switch (lk->id[4]) {
case 1:
strlcpy(lk->name, "DEC LK201 keyboard", sizeof(lk->name));
if (lk201_compose_is_alt)
lk->keycode[0xb1] = KEY_LEFTALT;
break;
case 2:
strlcpy(lk->name, "DEC LK401 keyboard", sizeof(lk->name));
break;
default:
strlcpy(lk->name, "Unknown DEC keyboard", sizeof(lk->name));
printk(KERN_ERR
"lkkbd: keyboard on %s is unknown, please report to "
"Jan-Benedict Glaw <jbglaw@lug-owl.de>\n", lk->phys);
printk(KERN_ERR "lkkbd: keyboard ID'ed as:");
for (i = 0; i < LK_NUM_IGNORE_BYTES; i++)
printk(" 0x%02x", lk->id[i]);
printk("\n");
break;
}
printk(KERN_INFO "lkkbd: keyboard on %s identified as: %s\n",
lk->phys, lk->name);
switch (lk->id[2]) {
case 0x00:
break;
case LK_STUCK_KEY:
printk(KERN_ERR "lkkbd: Stuck key on keyboard at %s\n",
lk->phys);
break;
case LK_SELFTEST_FAILED:
printk(KERN_ERR
"lkkbd: Selftest failed on keyboard at %s, "
"keyboard may not work properly\n", lk->phys);
break;
default:
printk(KERN_ERR
"lkkbd: Unknown error %02x on keyboard at %s\n",
lk->id[2], lk->phys);
break;
}
if (lk->id[2] == LK_STUCK_KEY && lk->id[3] != 0)
printk(KERN_ERR
"Scancode of stuck key is 0x%02x, keycode is 0x%04x\n",
lk->id[3], lk->keycode[lk->id[3]]);
}
static irqreturn_t lkkbd_interrupt(struct serio *serio,
unsigned char data, unsigned int flags)
{
struct lkkbd *lk = serio_get_drvdata(serio);
struct input_dev *input_dev = lk->dev;
unsigned int keycode;
int i;
DBG(KERN_INFO "Got byte 0x%02x\n", data);
if (lk->ignore_bytes > 0) {
DBG(KERN_INFO "Ignoring a byte on %s\n", lk->name);
lk->id[LK_NUM_IGNORE_BYTES - lk->ignore_bytes--] = data;
if (lk->ignore_bytes == 0)
lkkbd_detection_done(lk);
return IRQ_HANDLED;
}
switch (data) {
case LK_ALL_KEYS_UP:
for (i = 0; i < ARRAY_SIZE(lkkbd_keycode); i++)
input_report_key(input_dev, lk->keycode[i], 0);
input_sync(input_dev);
break;
case 0x01:
DBG(KERN_INFO "Got 0x01, scheduling re-initialization\n");
lk->ignore_bytes = LK_NUM_IGNORE_BYTES;
lk->id[LK_NUM_IGNORE_BYTES - lk->ignore_bytes--] = data;
schedule_work(&lk->tq);
break;
case LK_METRONOME:
case LK_OUTPUT_ERROR:
case LK_INPUT_ERROR:
case LK_KBD_LOCKED:
case LK_KBD_TEST_MODE_ACK:
case LK_PREFIX_KEY_DOWN:
case LK_MODE_CHANGE_ACK:
case LK_RESPONSE_RESERVED:
DBG(KERN_INFO "Got %s and don't know how to handle...\n",
response_name(data));
break;
default:
keycode = lk->keycode[data];
if (keycode != KEY_RESERVED) {
input_report_key(input_dev, keycode,
!test_bit(keycode, input_dev->key));
input_sync(input_dev);
} else {
printk(KERN_WARNING
"%s: Unknown key with scancode 0x%02x on %s.\n",
__FILE__, data, lk->name);
}
}
return IRQ_HANDLED;
}
static void lkkbd_toggle_leds(struct lkkbd *lk)
{
struct serio *serio = lk->serio;
unsigned char leds_on = 0;
unsigned char leds_off = 0;
CHECK_LED(lk, leds_on, leds_off, LED_CAPSL, LK_LED_SHIFTLOCK);
CHECK_LED(lk, leds_on, leds_off, LED_COMPOSE, LK_LED_COMPOSE);
CHECK_LED(lk, leds_on, leds_off, LED_SCROLLL, LK_LED_SCROLLLOCK);
CHECK_LED(lk, leds_on, leds_off, LED_SLEEP, LK_LED_WAIT);
if (leds_on != 0) {
serio_write(serio, LK_CMD_LED_ON);
serio_write(serio, leds_on);
}
if (leds_off != 0) {
serio_write(serio, LK_CMD_LED_OFF);
serio_write(serio, leds_off);
}
}
static void lkkbd_toggle_keyclick(struct lkkbd *lk, bool on)
{
struct serio *serio = lk->serio;
if (on) {
DBG("%s: Activating key clicks\n", __func__);
serio_write(serio, LK_CMD_ENABLE_KEYCLICK);
serio_write(serio, volume_to_hw(lk->keyclick_volume));
serio_write(serio, LK_CMD_ENABLE_CTRCLICK);
serio_write(serio, volume_to_hw(lk->ctrlclick_volume));
} else {
DBG("%s: Deactivating key clicks\n", __func__);
serio_write(serio, LK_CMD_DISABLE_KEYCLICK);
serio_write(serio, LK_CMD_DISABLE_CTRCLICK);
}
}
static int lkkbd_event(struct input_dev *dev,
unsigned int type, unsigned int code, int value)
{
struct lkkbd *lk = input_get_drvdata(dev);
switch (type) {
case EV_LED:
lkkbd_toggle_leds(lk);
return 0;
case EV_SND:
switch (code) {
case SND_CLICK:
lkkbd_toggle_keyclick(lk, value);
return 0;
case SND_BELL:
if (value != 0)
serio_write(lk->serio, LK_CMD_SOUND_BELL);
return 0;
}
break;
default:
printk(KERN_ERR "%s(): Got unknown type %d, code %d, value %d\n",
__func__, type, code, value);
}
return -1;
}
static void lkkbd_reinit(struct work_struct *work)
{
struct lkkbd *lk = container_of(work, struct lkkbd, tq);
int division;
serio_write(lk->serio, LK_CMD_REQUEST_ID);
serio_write(lk->serio, LK_CMD_SET_DEFAULTS);
lkkbd_toggle_leds(lk);
serio_write(lk->serio, LK_CMD_ENABLE_LK401);
for (division = 1; division <= 14; division++)
serio_write(lk->serio,
LK_CMD_SET_MODE(LK_MODE_UPDOWN, division));
serio_write(lk->serio, LK_CMD_ENABLE_BELL);
serio_write(lk->serio, volume_to_hw(lk->bell_volume));
lkkbd_toggle_keyclick(lk, test_bit(SND_CLICK, lk->dev->snd));
if (test_bit(SND_BELL, lk->dev->snd))
serio_write(lk->serio, LK_CMD_SOUND_BELL);
}
static int lkkbd_connect(struct serio *serio, struct serio_driver *drv)
{
struct lkkbd *lk;
struct input_dev *input_dev;
int i;
int err;
lk = kzalloc(sizeof(struct lkkbd), GFP_KERNEL);
input_dev = input_allocate_device();
if (!lk || !input_dev) {
err = -ENOMEM;
goto fail1;
}
lk->serio = serio;
lk->dev = input_dev;
INIT_WORK(&lk->tq, lkkbd_reinit);
lk->bell_volume = bell_volume;
lk->keyclick_volume = keyclick_volume;
lk->ctrlclick_volume = ctrlclick_volume;
memcpy(lk->keycode, lkkbd_keycode, sizeof(lk->keycode));
strlcpy(lk->name, "DEC LK keyboard", sizeof(lk->name));
snprintf(lk->phys, sizeof(lk->phys), "%s/input0", serio->phys);
input_dev->name = lk->name;
input_dev->phys = lk->phys;
input_dev->id.bustype = BUS_RS232;
input_dev->id.vendor = SERIO_LKKBD;
input_dev->id.product = 0;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &serio->dev;
input_dev->event = lkkbd_event;
input_set_drvdata(input_dev, lk);
__set_bit(EV_KEY, input_dev->evbit);
__set_bit(EV_LED, input_dev->evbit);
__set_bit(EV_SND, input_dev->evbit);
__set_bit(EV_REP, input_dev->evbit);
__set_bit(LED_CAPSL, input_dev->ledbit);
__set_bit(LED_SLEEP, input_dev->ledbit);
__set_bit(LED_COMPOSE, input_dev->ledbit);
__set_bit(LED_SCROLLL, input_dev->ledbit);
__set_bit(SND_BELL, input_dev->sndbit);
__set_bit(SND_CLICK, input_dev->sndbit);
input_dev->keycode = lk->keycode;
input_dev->keycodesize = sizeof(lk->keycode[0]);
input_dev->keycodemax = ARRAY_SIZE(lk->keycode);
for (i = 0; i < LK_NUM_KEYCODES; i++)
__set_bit(lk->keycode[i], input_dev->keybit);
__clear_bit(KEY_RESERVED, input_dev->keybit);
serio_set_drvdata(serio, lk);
err = serio_open(serio, drv);
if (err)
goto fail2;
err = input_register_device(lk->dev);
if (err)
goto fail3;
serio_write(lk->serio, LK_CMD_POWERCYCLE_RESET);
return 0;
fail3: serio_close(serio);
fail2: serio_set_drvdata(serio, NULL);
fail1: input_free_device(input_dev);
kfree(lk);
return err;
}
static void lkkbd_disconnect(struct serio *serio)
{
struct lkkbd *lk = serio_get_drvdata(serio);
input_get_device(lk->dev);
input_unregister_device(lk->dev);
serio_close(serio);
serio_set_drvdata(serio, NULL);
input_put_device(lk->dev);
kfree(lk);
}
static int __init lkkbd_init(void)
{
return serio_register_driver(&lkkbd_drv);
}
static void __exit lkkbd_exit(void)
{
serio_unregister_driver(&lkkbd_drv);
}
