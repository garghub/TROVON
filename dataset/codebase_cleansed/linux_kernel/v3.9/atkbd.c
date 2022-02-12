static bool atkbd_need_xlate(unsigned long xl_bit, unsigned char code)
{
int i;
if (code == ATKBD_RET_EMUL0 || code == ATKBD_RET_EMUL1)
return false;
for (i = 0; i < ARRAY_SIZE(xl_table); i++)
if (code == xl_table[i])
return test_bit(i, &xl_bit);
return true;
}
static void atkbd_calculate_xl_bit(struct atkbd *atkbd, unsigned char code)
{
int i;
for (i = 0; i < ARRAY_SIZE(xl_table); i++) {
if (!((code ^ xl_table[i]) & 0x7f)) {
if (code & 0x80)
__clear_bit(i, &atkbd->xl_bit);
else
__set_bit(i, &atkbd->xl_bit);
break;
}
}
}
static unsigned int atkbd_compat_scancode(struct atkbd *atkbd, unsigned int code)
{
if (atkbd->set == 3) {
if (atkbd->emul == 1)
code |= 0x100;
} else {
code = (code & 0x7f) | ((code & 0x80) << 1);
if (atkbd->emul == 1)
code |= 0x80;
}
return code;
}
static irqreturn_t atkbd_interrupt(struct serio *serio, unsigned char data,
unsigned int flags)
{
struct atkbd *atkbd = serio_get_drvdata(serio);
struct input_dev *dev = atkbd->dev;
unsigned int code = data;
int scroll = 0, hscroll = 0, click = -1;
int value;
unsigned short keycode;
dev_dbg(&serio->dev, "Received %02x flags %02x\n", data, flags);
#if !defined(__i386__) && !defined (__x86_64__)
if ((flags & (SERIO_FRAME | SERIO_PARITY)) && (~flags & SERIO_TIMEOUT) && !atkbd->resend && atkbd->write) {
dev_warn(&serio->dev, "Frame/parity error: %02x\n", flags);
serio_write(serio, ATKBD_CMD_RESEND);
atkbd->resend = true;
goto out;
}
if (!flags && data == ATKBD_RET_ACK)
atkbd->resend = false;
#endif
if (unlikely(atkbd->ps2dev.flags & PS2_FLAG_ACK))
if (ps2_handle_ack(&atkbd->ps2dev, data))
goto out;
if (unlikely(atkbd->ps2dev.flags & PS2_FLAG_CMD))
if (ps2_handle_response(&atkbd->ps2dev, data))
goto out;
if (!atkbd->enabled)
goto out;
input_event(dev, EV_MSC, MSC_RAW, code);
if (atkbd_platform_scancode_fixup)
code = atkbd_platform_scancode_fixup(atkbd, code);
if (atkbd->translated) {
if (atkbd->emul || atkbd_need_xlate(atkbd->xl_bit, code)) {
atkbd->release = code >> 7;
code &= 0x7f;
}
if (!atkbd->emul)
atkbd_calculate_xl_bit(atkbd, data);
}
switch (code) {
case ATKBD_RET_BAT:
atkbd->enabled = false;
serio_reconnect(atkbd->ps2dev.serio);
goto out;
case ATKBD_RET_EMUL0:
atkbd->emul = 1;
goto out;
case ATKBD_RET_EMUL1:
atkbd->emul = 2;
goto out;
case ATKBD_RET_RELEASE:
atkbd->release = true;
goto out;
case ATKBD_RET_ACK:
case ATKBD_RET_NAK:
if (printk_ratelimit())
dev_warn(&serio->dev,
"Spurious %s on %s. "
"Some program might be trying to access hardware directly.\n",
data == ATKBD_RET_ACK ? "ACK" : "NAK", serio->phys);
goto out;
case ATKBD_RET_ERR:
atkbd->err_count++;
dev_dbg(&serio->dev, "Keyboard on %s reports too many keys pressed.\n",
serio->phys);
goto out;
}
code = atkbd_compat_scancode(atkbd, code);
if (atkbd->emul && --atkbd->emul)
goto out;
keycode = atkbd->keycode[code];
if (keycode != ATKBD_KEY_NULL)
input_event(dev, EV_MSC, MSC_SCAN, code);
switch (keycode) {
case ATKBD_KEY_NULL:
break;
case ATKBD_KEY_UNKNOWN:
dev_warn(&serio->dev,
"Unknown key %s (%s set %d, code %#x on %s).\n",
atkbd->release ? "released" : "pressed",
atkbd->translated ? "translated" : "raw",
atkbd->set, code, serio->phys);
dev_warn(&serio->dev,
"Use 'setkeycodes %s%02x <keycode>' to make it known.\n",
code & 0x80 ? "e0" : "", code & 0x7f);
input_sync(dev);
break;
case ATKBD_SCR_1:
scroll = 1;
break;
case ATKBD_SCR_2:
scroll = 2;
break;
case ATKBD_SCR_4:
scroll = 4;
break;
case ATKBD_SCR_8:
scroll = 8;
break;
case ATKBD_SCR_CLICK:
click = !atkbd->release;
break;
case ATKBD_SCR_LEFT:
hscroll = -1;
break;
case ATKBD_SCR_RIGHT:
hscroll = 1;
break;
default:
if (atkbd->release) {
value = 0;
atkbd->last = 0;
} else if (!atkbd->softrepeat && test_bit(keycode, dev->key)) {
value = time_before(jiffies, atkbd->time) && atkbd->last == code ? 1 : 2;
} else {
value = 1;
atkbd->last = code;
atkbd->time = jiffies + msecs_to_jiffies(dev->rep[REP_DELAY]) / 2;
}
input_event(dev, EV_KEY, keycode, value);
input_sync(dev);
if (value && test_bit(code, atkbd->force_release_mask)) {
input_report_key(dev, keycode, 0);
input_sync(dev);
}
}
if (atkbd->scroll) {
if (click != -1)
input_report_key(dev, BTN_MIDDLE, click);
input_report_rel(dev, REL_WHEEL,
atkbd->release ? -scroll : scroll);
input_report_rel(dev, REL_HWHEEL, hscroll);
input_sync(dev);
}
atkbd->release = false;
out:
return IRQ_HANDLED;
}
static int atkbd_set_repeat_rate(struct atkbd *atkbd)
{
const short period[32] =
{ 33, 37, 42, 46, 50, 54, 58, 63, 67, 75, 83, 92, 100, 109, 116, 125,
133, 149, 167, 182, 200, 217, 232, 250, 270, 303, 333, 370, 400, 435, 470, 500 };
const short delay[4] =
{ 250, 500, 750, 1000 };
struct input_dev *dev = atkbd->dev;
unsigned char param;
int i = 0, j = 0;
while (i < ARRAY_SIZE(period) - 1 && period[i] < dev->rep[REP_PERIOD])
i++;
dev->rep[REP_PERIOD] = period[i];
while (j < ARRAY_SIZE(delay) - 1 && delay[j] < dev->rep[REP_DELAY])
j++;
dev->rep[REP_DELAY] = delay[j];
param = i | (j << 5);
return ps2_command(&atkbd->ps2dev, &param, ATKBD_CMD_SETREP);
}
static int atkbd_set_leds(struct atkbd *atkbd)
{
struct input_dev *dev = atkbd->dev;
unsigned char param[2];
param[0] = (test_bit(LED_SCROLLL, dev->led) ? 1 : 0)
| (test_bit(LED_NUML, dev->led) ? 2 : 0)
| (test_bit(LED_CAPSL, dev->led) ? 4 : 0);
if (ps2_command(&atkbd->ps2dev, param, ATKBD_CMD_SETLEDS))
return -1;
if (atkbd->extra) {
param[0] = 0;
param[1] = (test_bit(LED_COMPOSE, dev->led) ? 0x01 : 0)
| (test_bit(LED_SLEEP, dev->led) ? 0x02 : 0)
| (test_bit(LED_SUSPEND, dev->led) ? 0x04 : 0)
| (test_bit(LED_MISC, dev->led) ? 0x10 : 0)
| (test_bit(LED_MUTE, dev->led) ? 0x20 : 0);
if (ps2_command(&atkbd->ps2dev, param, ATKBD_CMD_EX_SETLEDS))
return -1;
}
return 0;
}
static void atkbd_event_work(struct work_struct *work)
{
struct atkbd *atkbd = container_of(work, struct atkbd, event_work.work);
mutex_lock(&atkbd->mutex);
if (!atkbd->enabled) {
schedule_delayed_work(&atkbd->event_work,
msecs_to_jiffies(100));
} else {
if (test_and_clear_bit(ATKBD_LED_EVENT_BIT, &atkbd->event_mask))
atkbd_set_leds(atkbd);
if (test_and_clear_bit(ATKBD_REP_EVENT_BIT, &atkbd->event_mask))
atkbd_set_repeat_rate(atkbd);
}
mutex_unlock(&atkbd->mutex);
}
static void atkbd_schedule_event_work(struct atkbd *atkbd, int event_bit)
{
unsigned long delay = msecs_to_jiffies(50);
if (time_after(jiffies, atkbd->event_jiffies + delay))
delay = 0;
atkbd->event_jiffies = jiffies;
set_bit(event_bit, &atkbd->event_mask);
mb();
schedule_delayed_work(&atkbd->event_work, delay);
}
static int atkbd_event(struct input_dev *dev,
unsigned int type, unsigned int code, int value)
{
struct atkbd *atkbd = input_get_drvdata(dev);
if (!atkbd->write)
return -1;
switch (type) {
case EV_LED:
atkbd_schedule_event_work(atkbd, ATKBD_LED_EVENT_BIT);
return 0;
case EV_REP:
if (!atkbd->softrepeat)
atkbd_schedule_event_work(atkbd, ATKBD_REP_EVENT_BIT);
return 0;
default:
return -1;
}
}
static inline void atkbd_enable(struct atkbd *atkbd)
{
serio_pause_rx(atkbd->ps2dev.serio);
atkbd->enabled = true;
serio_continue_rx(atkbd->ps2dev.serio);
}
static inline void atkbd_disable(struct atkbd *atkbd)
{
serio_pause_rx(atkbd->ps2dev.serio);
atkbd->enabled = false;
serio_continue_rx(atkbd->ps2dev.serio);
}
static int atkbd_activate(struct atkbd *atkbd)
{
struct ps2dev *ps2dev = &atkbd->ps2dev;
if (ps2_command(ps2dev, NULL, ATKBD_CMD_ENABLE)) {
dev_err(&ps2dev->serio->dev,
"Failed to enable keyboard on %s\n",
ps2dev->serio->phys);
return -1;
}
return 0;
}
static void atkbd_deactivate(struct atkbd *atkbd)
{
struct ps2dev *ps2dev = &atkbd->ps2dev;
if (ps2_command(ps2dev, NULL, ATKBD_CMD_RESET_DIS))
dev_err(&ps2dev->serio->dev,
"Failed to deactivate keyboard on %s\n",
ps2dev->serio->phys);
}
static int atkbd_probe(struct atkbd *atkbd)
{
struct ps2dev *ps2dev = &atkbd->ps2dev;
unsigned char param[2];
if (atkbd_reset)
if (ps2_command(ps2dev, NULL, ATKBD_CMD_RESET_BAT))
dev_warn(&ps2dev->serio->dev,
"keyboard reset failed on %s\n",
ps2dev->serio->phys);
param[0] = param[1] = 0xa5;
if (ps2_command(ps2dev, param, ATKBD_CMD_GETID)) {
param[0] = 0;
if (ps2_command(ps2dev, param, ATKBD_CMD_SETLEDS))
return -1;
atkbd->id = 0xabba;
return 0;
}
if (!ps2_is_keyboard_id(param[0]))
return -1;
atkbd->id = (param[0] << 8) | param[1];
if (atkbd->id == 0xaca1 && atkbd->translated) {
dev_err(&ps2dev->serio->dev,
"NCD terminal keyboards are only supported on non-translating controllers. "
"Use i8042.direct=1 to disable translation.\n");
return -1;
}
atkbd_deactivate(atkbd);
return 0;
}
static int atkbd_select_set(struct atkbd *atkbd, int target_set, int allow_extra)
{
struct ps2dev *ps2dev = &atkbd->ps2dev;
unsigned char param[2];
atkbd->extra = false;
if (atkbd->translated)
return 2;
if (atkbd->id == 0xaca1) {
param[0] = 3;
ps2_command(ps2dev, param, ATKBD_CMD_SSCANSET);
return 3;
}
if (allow_extra) {
param[0] = 0x71;
if (!ps2_command(ps2dev, param, ATKBD_CMD_EX_ENABLE)) {
atkbd->extra = true;
return 2;
}
}
if (atkbd_terminal) {
ps2_command(ps2dev, param, ATKBD_CMD_SETALL_MB);
return 3;
}
if (target_set != 3)
return 2;
if (!ps2_command(ps2dev, param, ATKBD_CMD_OK_GETID)) {
atkbd->id = param[0] << 8 | param[1];
return 2;
}
param[0] = 3;
if (ps2_command(ps2dev, param, ATKBD_CMD_SSCANSET))
return 2;
param[0] = 0;
if (ps2_command(ps2dev, param, ATKBD_CMD_GSCANSET))
return 2;
if (param[0] != 3) {
param[0] = 2;
if (ps2_command(ps2dev, param, ATKBD_CMD_SSCANSET))
return 2;
}
ps2_command(ps2dev, param, ATKBD_CMD_SETALL_MBR);
return 3;
}
static int atkbd_reset_state(struct atkbd *atkbd)
{
struct ps2dev *ps2dev = &atkbd->ps2dev;
unsigned char param[1];
param[0] = 0;
if (ps2_command(ps2dev, param, ATKBD_CMD_SETLEDS))
return -1;
param[0] = 0;
if (ps2_command(ps2dev, param, ATKBD_CMD_SETREP))
return -1;
return 0;
}
static void atkbd_cleanup(struct serio *serio)
{
struct atkbd *atkbd = serio_get_drvdata(serio);
atkbd_disable(atkbd);
ps2_command(&atkbd->ps2dev, NULL, ATKBD_CMD_RESET_DEF);
}
static void atkbd_disconnect(struct serio *serio)
{
struct atkbd *atkbd = serio_get_drvdata(serio);
sysfs_remove_group(&serio->dev.kobj, &atkbd_attribute_group);
atkbd_disable(atkbd);
input_unregister_device(atkbd->dev);
cancel_delayed_work_sync(&atkbd->event_work);
serio_close(serio);
serio_set_drvdata(serio, NULL);
kfree(atkbd);
}
static void atkbd_apply_forced_release_keylist(struct atkbd* atkbd,
const void *data)
{
const unsigned int *keys = data;
unsigned int i;
if (atkbd->set == 2)
for (i = 0; keys[i] != -1U; i++)
__set_bit(keys[i], atkbd->force_release_mask);
}
static unsigned int atkbd_oqo_01plus_scancode_fixup(struct atkbd *atkbd,
unsigned int code)
{
if (atkbd->translated && atkbd->emul == 1 &&
(code == 0x64 || code == 0x65 || code == 0x66)) {
atkbd->emul = 0;
code |= 0x80;
}
return code;
}
static void atkbd_set_keycode_table(struct atkbd *atkbd)
{
unsigned int scancode;
int i, j;
memset(atkbd->keycode, 0, sizeof(atkbd->keycode));
bitmap_zero(atkbd->force_release_mask, ATKBD_KEYMAP_SIZE);
if (atkbd->translated) {
for (i = 0; i < 128; i++) {
scancode = atkbd_unxlate_table[i];
atkbd->keycode[i] = atkbd_set2_keycode[scancode];
atkbd->keycode[i | 0x80] = atkbd_set2_keycode[scancode | 0x80];
if (atkbd->scroll)
for (j = 0; j < ARRAY_SIZE(atkbd_scroll_keys); j++)
if ((scancode | 0x80) == atkbd_scroll_keys[j].set2)
atkbd->keycode[i | 0x80] = atkbd_scroll_keys[j].keycode;
}
} else if (atkbd->set == 3) {
memcpy(atkbd->keycode, atkbd_set3_keycode, sizeof(atkbd->keycode));
} else {
memcpy(atkbd->keycode, atkbd_set2_keycode, sizeof(atkbd->keycode));
if (atkbd->scroll)
for (i = 0; i < ARRAY_SIZE(atkbd_scroll_keys); i++) {
scancode = atkbd_scroll_keys[i].set2;
atkbd->keycode[scancode] = atkbd_scroll_keys[i].keycode;
}
}
scancode = atkbd_compat_scancode(atkbd, ATKBD_RET_HANGEUL);
atkbd->keycode[scancode] = KEY_HANGEUL;
__set_bit(scancode, atkbd->force_release_mask);
scancode = atkbd_compat_scancode(atkbd, ATKBD_RET_HANJA);
atkbd->keycode[scancode] = KEY_HANJA;
__set_bit(scancode, atkbd->force_release_mask);
if (atkbd_platform_fixup)
atkbd_platform_fixup(atkbd, atkbd_platform_fixup_data);
}
static void atkbd_set_device_attrs(struct atkbd *atkbd)
{
struct input_dev *input_dev = atkbd->dev;
int i;
if (atkbd->extra)
snprintf(atkbd->name, sizeof(atkbd->name),
"AT Set 2 Extra keyboard");
else
snprintf(atkbd->name, sizeof(atkbd->name),
"AT %s Set %d keyboard",
atkbd->translated ? "Translated" : "Raw", atkbd->set);
snprintf(atkbd->phys, sizeof(atkbd->phys),
"%s/input0", atkbd->ps2dev.serio->phys);
input_dev->name = atkbd->name;
input_dev->phys = atkbd->phys;
input_dev->id.bustype = BUS_I8042;
input_dev->id.vendor = 0x0001;
input_dev->id.product = atkbd->translated ? 1 : atkbd->set;
input_dev->id.version = atkbd->id;
input_dev->event = atkbd_event;
input_dev->dev.parent = &atkbd->ps2dev.serio->dev;
input_set_drvdata(input_dev, atkbd);
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REP) |
BIT_MASK(EV_MSC);
if (atkbd->write) {
input_dev->evbit[0] |= BIT_MASK(EV_LED);
input_dev->ledbit[0] = BIT_MASK(LED_NUML) |
BIT_MASK(LED_CAPSL) | BIT_MASK(LED_SCROLLL);
}
if (atkbd->extra)
input_dev->ledbit[0] |= BIT_MASK(LED_COMPOSE) |
BIT_MASK(LED_SUSPEND) | BIT_MASK(LED_SLEEP) |
BIT_MASK(LED_MUTE) | BIT_MASK(LED_MISC);
if (!atkbd->softrepeat) {
input_dev->rep[REP_DELAY] = 250;
input_dev->rep[REP_PERIOD] = 33;
}
input_dev->mscbit[0] = atkbd->softraw ? BIT_MASK(MSC_SCAN) :
BIT_MASK(MSC_RAW) | BIT_MASK(MSC_SCAN);
if (atkbd->scroll) {
input_dev->evbit[0] |= BIT_MASK(EV_REL);
input_dev->relbit[0] = BIT_MASK(REL_WHEEL) |
BIT_MASK(REL_HWHEEL);
__set_bit(BTN_MIDDLE, input_dev->keybit);
}
input_dev->keycode = atkbd->keycode;
input_dev->keycodesize = sizeof(unsigned short);
input_dev->keycodemax = ARRAY_SIZE(atkbd_set2_keycode);
for (i = 0; i < ATKBD_KEYMAP_SIZE; i++) {
if (atkbd->keycode[i] != KEY_RESERVED &&
atkbd->keycode[i] != ATKBD_KEY_NULL &&
atkbd->keycode[i] < ATKBD_SPECIAL) {
__set_bit(atkbd->keycode[i], input_dev->keybit);
}
}
}
static int atkbd_connect(struct serio *serio, struct serio_driver *drv)
{
struct atkbd *atkbd;
struct input_dev *dev;
int err = -ENOMEM;
atkbd = kzalloc(sizeof(struct atkbd), GFP_KERNEL);
dev = input_allocate_device();
if (!atkbd || !dev)
goto fail1;
atkbd->dev = dev;
ps2_init(&atkbd->ps2dev, serio);
INIT_DELAYED_WORK(&atkbd->event_work, atkbd_event_work);
mutex_init(&atkbd->mutex);
switch (serio->id.type) {
case SERIO_8042_XL:
atkbd->translated = true;
case SERIO_8042:
if (serio->write)
atkbd->write = true;
break;
}
atkbd->softraw = atkbd_softraw;
atkbd->softrepeat = atkbd_softrepeat;
atkbd->scroll = atkbd_scroll;
if (atkbd->softrepeat)
atkbd->softraw = true;
serio_set_drvdata(serio, atkbd);
err = serio_open(serio, drv);
if (err)
goto fail2;
if (atkbd->write) {
if (atkbd_probe(atkbd)) {
err = -ENODEV;
goto fail3;
}
atkbd->set = atkbd_select_set(atkbd, atkbd_set, atkbd_extra);
atkbd_reset_state(atkbd);
} else {
atkbd->set = 2;
atkbd->id = 0xab00;
}
atkbd_set_keycode_table(atkbd);
atkbd_set_device_attrs(atkbd);
err = sysfs_create_group(&serio->dev.kobj, &atkbd_attribute_group);
if (err)
goto fail3;
atkbd_enable(atkbd);
if (serio->write)
atkbd_activate(atkbd);
err = input_register_device(atkbd->dev);
if (err)
goto fail4;
return 0;
fail4: sysfs_remove_group(&serio->dev.kobj, &atkbd_attribute_group);
fail3: serio_close(serio);
fail2: serio_set_drvdata(serio, NULL);
fail1: input_free_device(dev);
kfree(atkbd);
return err;
}
static int atkbd_reconnect(struct serio *serio)
{
struct atkbd *atkbd = serio_get_drvdata(serio);
struct serio_driver *drv = serio->drv;
int retval = -1;
if (!atkbd || !drv) {
dev_dbg(&serio->dev,
"reconnect request, but serio is disconnected, ignoring...\n");
return -1;
}
mutex_lock(&atkbd->mutex);
atkbd_disable(atkbd);
if (atkbd->write) {
if (atkbd_probe(atkbd))
goto out;
if (atkbd->set != atkbd_select_set(atkbd, atkbd->set, atkbd->extra))
goto out;
atkbd_set_leds(atkbd);
if (!atkbd->softrepeat)
atkbd_set_repeat_rate(atkbd);
}
atkbd->xl_bit = 0;
atkbd->emul = 0;
atkbd_enable(atkbd);
if (atkbd->write)
atkbd_activate(atkbd);
retval = 0;
out:
mutex_unlock(&atkbd->mutex);
return retval;
}
static ssize_t atkbd_attr_show_helper(struct device *dev, char *buf,
ssize_t (*handler)(struct atkbd *, char *))
{
struct serio *serio = to_serio_port(dev);
struct atkbd *atkbd = serio_get_drvdata(serio);
return handler(atkbd, buf);
}
static ssize_t atkbd_attr_set_helper(struct device *dev, const char *buf, size_t count,
ssize_t (*handler)(struct atkbd *, const char *, size_t))
{
struct serio *serio = to_serio_port(dev);
struct atkbd *atkbd = serio_get_drvdata(serio);
int retval;
retval = mutex_lock_interruptible(&atkbd->mutex);
if (retval)
return retval;
atkbd_disable(atkbd);
retval = handler(atkbd, buf, count);
atkbd_enable(atkbd);
mutex_unlock(&atkbd->mutex);
return retval;
}
static ssize_t atkbd_show_extra(struct atkbd *atkbd, char *buf)
{
return sprintf(buf, "%d\n", atkbd->extra ? 1 : 0);
}
static ssize_t atkbd_set_extra(struct atkbd *atkbd, const char *buf, size_t count)
{
struct input_dev *old_dev, *new_dev;
unsigned int value;
int err;
bool old_extra;
unsigned char old_set;
if (!atkbd->write)
return -EIO;
err = kstrtouint(buf, 10, &value);
if (err)
return err;
if (value > 1)
return -EINVAL;
if (atkbd->extra != value) {
old_dev = atkbd->dev;
old_extra = atkbd->extra;
old_set = atkbd->set;
new_dev = input_allocate_device();
if (!new_dev)
return -ENOMEM;
atkbd->dev = new_dev;
atkbd->set = atkbd_select_set(atkbd, atkbd->set, value);
atkbd_reset_state(atkbd);
atkbd_activate(atkbd);
atkbd_set_keycode_table(atkbd);
atkbd_set_device_attrs(atkbd);
err = input_register_device(atkbd->dev);
if (err) {
input_free_device(new_dev);
atkbd->dev = old_dev;
atkbd->set = atkbd_select_set(atkbd, old_set, old_extra);
atkbd_set_keycode_table(atkbd);
atkbd_set_device_attrs(atkbd);
return err;
}
input_unregister_device(old_dev);
}
return count;
}
static ssize_t atkbd_show_force_release(struct atkbd *atkbd, char *buf)
{
size_t len = bitmap_scnlistprintf(buf, PAGE_SIZE - 2,
atkbd->force_release_mask, ATKBD_KEYMAP_SIZE);
buf[len++] = '\n';
buf[len] = '\0';
return len;
}
static ssize_t atkbd_set_force_release(struct atkbd *atkbd,
const char *buf, size_t count)
{
DECLARE_BITMAP(new_mask, ATKBD_KEYMAP_SIZE);
int err;
err = bitmap_parselist(buf, new_mask, ATKBD_KEYMAP_SIZE);
if (err)
return err;
memcpy(atkbd->force_release_mask, new_mask, sizeof(atkbd->force_release_mask));
return count;
}
static ssize_t atkbd_show_scroll(struct atkbd *atkbd, char *buf)
{
return sprintf(buf, "%d\n", atkbd->scroll ? 1 : 0);
}
static ssize_t atkbd_set_scroll(struct atkbd *atkbd, const char *buf, size_t count)
{
struct input_dev *old_dev, *new_dev;
unsigned int value;
int err;
bool old_scroll;
err = kstrtouint(buf, 10, &value);
if (err)
return err;
if (value > 1)
return -EINVAL;
if (atkbd->scroll != value) {
old_dev = atkbd->dev;
old_scroll = atkbd->scroll;
new_dev = input_allocate_device();
if (!new_dev)
return -ENOMEM;
atkbd->dev = new_dev;
atkbd->scroll = value;
atkbd_set_keycode_table(atkbd);
atkbd_set_device_attrs(atkbd);
err = input_register_device(atkbd->dev);
if (err) {
input_free_device(new_dev);
atkbd->scroll = old_scroll;
atkbd->dev = old_dev;
atkbd_set_keycode_table(atkbd);
atkbd_set_device_attrs(atkbd);
return err;
}
input_unregister_device(old_dev);
}
return count;
}
static ssize_t atkbd_show_set(struct atkbd *atkbd, char *buf)
{
return sprintf(buf, "%d\n", atkbd->set);
}
static ssize_t atkbd_set_set(struct atkbd *atkbd, const char *buf, size_t count)
{
struct input_dev *old_dev, *new_dev;
unsigned int value;
int err;
unsigned char old_set;
bool old_extra;
if (!atkbd->write)
return -EIO;
err = kstrtouint(buf, 10, &value);
if (err)
return err;
if (value != 2 && value != 3)
return -EINVAL;
if (atkbd->set != value) {
old_dev = atkbd->dev;
old_extra = atkbd->extra;
old_set = atkbd->set;
new_dev = input_allocate_device();
if (!new_dev)
return -ENOMEM;
atkbd->dev = new_dev;
atkbd->set = atkbd_select_set(atkbd, value, atkbd->extra);
atkbd_reset_state(atkbd);
atkbd_activate(atkbd);
atkbd_set_keycode_table(atkbd);
atkbd_set_device_attrs(atkbd);
err = input_register_device(atkbd->dev);
if (err) {
input_free_device(new_dev);
atkbd->dev = old_dev;
atkbd->set = atkbd_select_set(atkbd, old_set, old_extra);
atkbd_set_keycode_table(atkbd);
atkbd_set_device_attrs(atkbd);
return err;
}
input_unregister_device(old_dev);
}
return count;
}
static ssize_t atkbd_show_softrepeat(struct atkbd *atkbd, char *buf)
{
return sprintf(buf, "%d\n", atkbd->softrepeat ? 1 : 0);
}
static ssize_t atkbd_set_softrepeat(struct atkbd *atkbd, const char *buf, size_t count)
{
struct input_dev *old_dev, *new_dev;
unsigned int value;
int err;
bool old_softrepeat, old_softraw;
if (!atkbd->write)
return -EIO;
err = kstrtouint(buf, 10, &value);
if (err)
return err;
if (value > 1)
return -EINVAL;
if (atkbd->softrepeat != value) {
old_dev = atkbd->dev;
old_softrepeat = atkbd->softrepeat;
old_softraw = atkbd->softraw;
new_dev = input_allocate_device();
if (!new_dev)
return -ENOMEM;
atkbd->dev = new_dev;
atkbd->softrepeat = value;
if (atkbd->softrepeat)
atkbd->softraw = true;
atkbd_set_device_attrs(atkbd);
err = input_register_device(atkbd->dev);
if (err) {
input_free_device(new_dev);
atkbd->dev = old_dev;
atkbd->softrepeat = old_softrepeat;
atkbd->softraw = old_softraw;
atkbd_set_device_attrs(atkbd);
return err;
}
input_unregister_device(old_dev);
}
return count;
}
static ssize_t atkbd_show_softraw(struct atkbd *atkbd, char *buf)
{
return sprintf(buf, "%d\n", atkbd->softraw ? 1 : 0);
}
static ssize_t atkbd_set_softraw(struct atkbd *atkbd, const char *buf, size_t count)
{
struct input_dev *old_dev, *new_dev;
unsigned int value;
int err;
bool old_softraw;
err = kstrtouint(buf, 10, &value);
if (err)
return err;
if (value > 1)
return -EINVAL;
if (atkbd->softraw != value) {
old_dev = atkbd->dev;
old_softraw = atkbd->softraw;
new_dev = input_allocate_device();
if (!new_dev)
return -ENOMEM;
atkbd->dev = new_dev;
atkbd->softraw = value;
atkbd_set_device_attrs(atkbd);
err = input_register_device(atkbd->dev);
if (err) {
input_free_device(new_dev);
atkbd->dev = old_dev;
atkbd->softraw = old_softraw;
atkbd_set_device_attrs(atkbd);
return err;
}
input_unregister_device(old_dev);
}
return count;
}
static ssize_t atkbd_show_err_count(struct atkbd *atkbd, char *buf)
{
return sprintf(buf, "%lu\n", atkbd->err_count);
}
static int __init atkbd_setup_forced_release(const struct dmi_system_id *id)
{
atkbd_platform_fixup = atkbd_apply_forced_release_keylist;
atkbd_platform_fixup_data = id->driver_data;
return 1;
}
static int __init atkbd_setup_scancode_fixup(const struct dmi_system_id *id)
{
atkbd_platform_scancode_fixup = id->driver_data;
return 1;
}
static int __init atkbd_init(void)
{
dmi_check_system(atkbd_dmi_quirk_table);
return serio_register_driver(&atkbd_drv);
}
static void __exit atkbd_exit(void)
{
serio_unregister_driver(&atkbd_drv);
}
