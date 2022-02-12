static void mce_kbd_rx_timeout(unsigned long data)
{
struct mce_kbd_dec *mce_kbd = (struct mce_kbd_dec *)data;
int i;
unsigned char maskcode;
IR_dprintk(2, "timer callback clearing all keys\n");
for (i = 0; i < 7; i++) {
maskcode = kbd_keycodes[MCIR2_MASK_KEYS_START + i];
input_report_key(mce_kbd->idev, maskcode, 0);
}
for (i = 0; i < MCIR2_MASK_KEYS_START; i++)
input_report_key(mce_kbd->idev, kbd_keycodes[i], 0);
}
static enum mce_kbd_mode mce_kbd_mode(struct mce_kbd_dec *data)
{
switch (data->header & MCIR2_MODE_MASK) {
case MCIR2_KEYBOARD_HEADER:
return MCIR2_MODE_KEYBOARD;
case MCIR2_MOUSE_HEADER:
return MCIR2_MODE_MOUSE;
default:
return MCIR2_MODE_UNKNOWN;
}
}
static void ir_mce_kbd_process_keyboard_data(struct input_dev *idev,
u32 scancode)
{
u8 keydata = (scancode >> 8) & 0xff;
u8 shiftmask = scancode & 0xff;
unsigned char keycode, maskcode;
int i, keystate;
IR_dprintk(1, "keyboard: keydata = 0x%02x, shiftmask = 0x%02x\n",
keydata, shiftmask);
for (i = 0; i < 7; i++) {
maskcode = kbd_keycodes[MCIR2_MASK_KEYS_START + i];
if (shiftmask & (1 << i))
keystate = 1;
else
keystate = 0;
input_report_key(idev, maskcode, keystate);
}
if (keydata) {
keycode = kbd_keycodes[keydata];
input_report_key(idev, keycode, 1);
} else {
for (i = 0; i < MCIR2_MASK_KEYS_START; i++)
input_report_key(idev, kbd_keycodes[i], 0);
}
}
static void ir_mce_kbd_process_mouse_data(struct input_dev *idev, u32 scancode)
{
u8 xdata = (scancode >> 7) & 0x7f;
u8 ydata = (scancode >> 14) & 0x7f;
int x, y;
bool right = scancode & 0x40;
bool left = scancode & 0x20;
if (xdata & 0x40)
x = -((~xdata & 0x7f) + 1);
else
x = xdata;
if (ydata & 0x40)
y = -((~ydata & 0x7f) + 1);
else
y = ydata;
IR_dprintk(1, "mouse: x = %d, y = %d, btns = %s%s\n",
x, y, left ? "L" : "", right ? "R" : "");
input_report_rel(idev, REL_X, x);
input_report_rel(idev, REL_Y, y);
input_report_key(idev, BTN_LEFT, left);
input_report_key(idev, BTN_RIGHT, right);
}
static int ir_mce_kbd_decode(struct rc_dev *dev, struct ir_raw_event ev)
{
struct mce_kbd_dec *data = &dev->raw->mce_kbd;
u32 scancode;
unsigned long delay;
if (!(dev->raw->enabled_protocols & RC_TYPE_MCE_KBD))
return 0;
if (!is_timing_event(ev)) {
if (ev.reset)
data->state = STATE_INACTIVE;
return 0;
}
if (!geq_margin(ev.duration, MCIR2_UNIT, MCIR2_UNIT / 2))
goto out;
again:
IR_dprintk(2, "started at state %i (%uus %s)\n",
data->state, TO_US(ev.duration), TO_STR(ev.pulse));
if (!geq_margin(ev.duration, MCIR2_UNIT, MCIR2_UNIT / 2))
return 0;
switch (data->state) {
case STATE_INACTIVE:
if (!ev.pulse)
break;
if (!eq_margin(ev.duration, MCIR2_PREFIX_PULSE, MCIR2_UNIT))
break;
data->state = STATE_HEADER_BIT_START;
data->count = 0;
data->header = 0;
return 0;
case STATE_HEADER_BIT_START:
if (geq_margin(ev.duration, MCIR2_MAX_LEN, MCIR2_UNIT / 2))
break;
data->header <<= 1;
if (ev.pulse)
data->header |= 1;
data->count++;
data->state = STATE_HEADER_BIT_END;
return 0;
case STATE_HEADER_BIT_END:
if (!is_transition(&ev, &dev->raw->prev_ev))
break;
decrease_duration(&ev, MCIR2_BIT_END);
if (data->count != MCIR2_HEADER_NBITS) {
data->state = STATE_HEADER_BIT_START;
goto again;
}
switch (mce_kbd_mode(data)) {
case MCIR2_MODE_KEYBOARD:
data->wanted_bits = MCIR2_KEYBOARD_NBITS;
break;
case MCIR2_MODE_MOUSE:
data->wanted_bits = MCIR2_MOUSE_NBITS;
break;
default:
IR_dprintk(1, "not keyboard or mouse data\n");
goto out;
}
data->count = 0;
data->body = 0;
data->state = STATE_BODY_BIT_START;
goto again;
case STATE_BODY_BIT_START:
if (geq_margin(ev.duration, MCIR2_MAX_LEN, MCIR2_UNIT / 2))
break;
data->body <<= 1;
if (ev.pulse)
data->body |= 1;
data->count++;
data->state = STATE_BODY_BIT_END;
return 0;
case STATE_BODY_BIT_END:
if (!is_transition(&ev, &dev->raw->prev_ev))
break;
if (data->count == data->wanted_bits)
data->state = STATE_FINISHED;
else
data->state = STATE_BODY_BIT_START;
decrease_duration(&ev, MCIR2_BIT_END);
goto again;
case STATE_FINISHED:
if (ev.pulse)
break;
switch (data->wanted_bits) {
case MCIR2_KEYBOARD_NBITS:
scancode = data->body & 0xffff;
IR_dprintk(1, "keyboard data 0x%08x\n", data->body);
if (dev->timeout)
delay = usecs_to_jiffies(dev->timeout / 1000);
else
delay = msecs_to_jiffies(100);
mod_timer(&data->rx_timeout, jiffies + delay);
ir_mce_kbd_process_keyboard_data(data->idev, scancode);
break;
case MCIR2_MOUSE_NBITS:
scancode = data->body & 0x1fffff;
IR_dprintk(1, "mouse data 0x%06x\n", scancode);
ir_mce_kbd_process_mouse_data(data->idev, scancode);
break;
default:
IR_dprintk(1, "not keyboard or mouse data\n");
goto out;
}
data->state = STATE_INACTIVE;
input_sync(data->idev);
return 0;
}
out:
IR_dprintk(1, "failed at state %i (%uus %s)\n",
data->state, TO_US(ev.duration), TO_STR(ev.pulse));
data->state = STATE_INACTIVE;
input_sync(data->idev);
return -EINVAL;
}
static int ir_mce_kbd_register(struct rc_dev *dev)
{
struct mce_kbd_dec *mce_kbd = &dev->raw->mce_kbd;
struct input_dev *idev;
int i, ret;
idev = input_allocate_device();
if (!idev)
return -ENOMEM;
snprintf(mce_kbd->name, sizeof(mce_kbd->name),
"MCE IR Keyboard/Mouse (%s)", dev->driver_name);
strlcat(mce_kbd->phys, "/input0", sizeof(mce_kbd->phys));
idev->name = mce_kbd->name;
idev->phys = mce_kbd->phys;
set_bit(EV_KEY, idev->evbit);
set_bit(EV_REP, idev->evbit);
for (i = 0; i < sizeof(kbd_keycodes); i++)
set_bit(kbd_keycodes[i], idev->keybit);
set_bit(EV_REL, idev->evbit);
set_bit(REL_X, idev->relbit);
set_bit(REL_Y, idev->relbit);
set_bit(BTN_LEFT, idev->keybit);
set_bit(BTN_RIGHT, idev->keybit);
set_bit(EV_MSC, idev->evbit);
set_bit(MSC_SCAN, idev->mscbit);
setup_timer(&mce_kbd->rx_timeout, mce_kbd_rx_timeout,
(unsigned long)mce_kbd);
input_set_drvdata(idev, mce_kbd);
#if 0
idev->dev.parent = &dev->dev;
#endif
ret = input_register_device(idev);
if (ret < 0) {
input_free_device(idev);
return -EIO;
}
mce_kbd->idev = idev;
return 0;
}
static int ir_mce_kbd_unregister(struct rc_dev *dev)
{
struct mce_kbd_dec *mce_kbd = &dev->raw->mce_kbd;
struct input_dev *idev = mce_kbd->idev;
del_timer_sync(&mce_kbd->rx_timeout);
input_unregister_device(idev);
return 0;
}
static int __init ir_mce_kbd_decode_init(void)
{
ir_raw_handler_register(&mce_kbd_handler);
printk(KERN_INFO "IR MCE Keyboard/mouse protocol handler initialized\n");
return 0;
}
static void __exit ir_mce_kbd_decode_exit(void)
{
ir_raw_handler_unregister(&mce_kbd_handler);
}
