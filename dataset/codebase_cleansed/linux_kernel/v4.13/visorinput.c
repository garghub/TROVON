static int visorinput_open(struct input_dev *visorinput_dev)
{
struct visorinput_devdata *devdata = input_get_drvdata(visorinput_dev);
if (!devdata) {
dev_err(&visorinput_dev->dev,
"%s input_get_drvdata(%p) returned NULL\n",
__func__, visorinput_dev);
return -EINVAL;
}
dev_dbg(&visorinput_dev->dev, "%s opened\n", __func__);
mutex_lock(&devdata->lock_visor_dev);
devdata->interrupts_enabled = true;
if (devdata->paused)
goto out_unlock;
visorbus_enable_channel_interrupts(devdata->dev);
out_unlock:
mutex_unlock(&devdata->lock_visor_dev);
return 0;
}
static void visorinput_close(struct input_dev *visorinput_dev)
{
struct visorinput_devdata *devdata = input_get_drvdata(visorinput_dev);
if (!devdata) {
dev_err(&visorinput_dev->dev,
"%s input_get_drvdata(%p) returned NULL\n",
__func__, visorinput_dev);
return;
}
dev_dbg(&visorinput_dev->dev, "%s closed\n", __func__);
mutex_lock(&devdata->lock_visor_dev);
devdata->interrupts_enabled = false;
if (devdata->paused)
goto out_unlock;
visorbus_disable_channel_interrupts(devdata->dev);
out_unlock:
mutex_unlock(&devdata->lock_visor_dev);
}
static struct input_dev *
setup_client_keyboard(void *devdata,
unsigned char *keycode_table)
{
int i;
struct input_dev *visorinput_dev;
visorinput_dev = input_allocate_device();
if (!visorinput_dev)
return NULL;
visorinput_dev->name = "visor Keyboard";
visorinput_dev->phys = "visorkbd:input0";
visorinput_dev->id.bustype = BUS_VIRTUAL;
visorinput_dev->id.vendor = 0x0001;
visorinput_dev->id.product = 0x0001;
visorinput_dev->id.version = 0x0100;
visorinput_dev->evbit[0] = BIT_MASK(EV_KEY) |
BIT_MASK(EV_REP) |
BIT_MASK(EV_LED);
visorinput_dev->ledbit[0] = BIT_MASK(LED_CAPSL) |
BIT_MASK(LED_SCROLLL) |
BIT_MASK(LED_NUML);
visorinput_dev->keycode = keycode_table;
visorinput_dev->keycodesize = 1;
visorinput_dev->keycodemax = KEYCODE_TABLE_BYTES;
for (i = 1; i < visorinput_dev->keycodemax; i++)
set_bit(keycode_table[i], visorinput_dev->keybit);
for (i = 1; i < visorinput_dev->keycodemax; i++)
set_bit(keycode_table[i + KEYCODE_TABLE_BYTES],
visorinput_dev->keybit);
visorinput_dev->open = visorinput_open;
visorinput_dev->close = visorinput_close;
input_set_drvdata(visorinput_dev, devdata);
return visorinput_dev;
}
static struct input_dev *
setup_client_mouse(void *devdata )
{
struct input_dev *visorinput_dev = NULL;
int xres, yres;
struct fb_info *fb0;
visorinput_dev = input_allocate_device();
if (!visorinput_dev)
return NULL;
visorinput_dev->name = "visor Mouse";
visorinput_dev->phys = "visormou:input0";
visorinput_dev->id.bustype = BUS_VIRTUAL;
visorinput_dev->id.vendor = 0x0001;
visorinput_dev->id.product = 0x0002;
visorinput_dev->id.version = 0x0100;
visorinput_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
set_bit(BTN_LEFT, visorinput_dev->keybit);
set_bit(BTN_RIGHT, visorinput_dev->keybit);
set_bit(BTN_MIDDLE, visorinput_dev->keybit);
if (registered_fb[0]) {
fb0 = registered_fb[0];
xres = fb0->var.xres_virtual;
yres = fb0->var.yres_virtual;
} else {
xres = PIXELS_ACROSS_DEFAULT;
yres = PIXELS_DOWN_DEFAULT;
}
input_set_abs_params(visorinput_dev, ABS_X, 0, xres, 0, 0);
input_set_abs_params(visorinput_dev, ABS_Y, 0, yres, 0, 0);
visorinput_dev->open = visorinput_open;
visorinput_dev->close = visorinput_close;
input_set_drvdata(visorinput_dev, devdata);
input_set_capability(visorinput_dev, EV_REL, REL_WHEEL);
return visorinput_dev;
}
static struct visorinput_devdata *
devdata_create(struct visor_device *dev, enum visorinput_device_type devtype)
{
struct visorinput_devdata *devdata = NULL;
unsigned int extra_bytes = 0;
if (devtype == visorinput_keyboard)
extra_bytes = KEYCODE_TABLE_BYTES * 2;
devdata = kzalloc(sizeof(*devdata) + extra_bytes, GFP_KERNEL);
if (!devdata)
return NULL;
mutex_init(&devdata->lock_visor_dev);
mutex_lock(&devdata->lock_visor_dev);
devdata->dev = dev;
devdata->paused = true;
switch (devtype) {
case visorinput_keyboard:
devdata->keycode_table_bytes = extra_bytes;
memcpy(devdata->keycode_table, visorkbd_keycode,
KEYCODE_TABLE_BYTES);
memcpy(devdata->keycode_table + KEYCODE_TABLE_BYTES,
visorkbd_ext_keycode, KEYCODE_TABLE_BYTES);
devdata->visorinput_dev = setup_client_keyboard
(devdata, devdata->keycode_table);
if (!devdata->visorinput_dev)
goto cleanups_register;
break;
case visorinput_mouse:
devdata->visorinput_dev = setup_client_mouse(devdata);
if (!devdata->visorinput_dev)
goto cleanups_register;
break;
default:
break;
}
dev_set_drvdata(&dev->device, devdata);
mutex_unlock(&devdata->lock_visor_dev);
if (input_register_device(devdata->visorinput_dev)) {
input_free_device(devdata->visorinput_dev);
goto err_kfree_devdata;
}
mutex_lock(&devdata->lock_visor_dev);
devdata->paused = false;
if (devdata->interrupts_enabled)
visorbus_enable_channel_interrupts(dev);
mutex_unlock(&devdata->lock_visor_dev);
return devdata;
cleanups_register:
mutex_unlock(&devdata->lock_visor_dev);
err_kfree_devdata:
kfree(devdata);
return NULL;
}
static int
visorinput_probe(struct visor_device *dev)
{
uuid_le guid;
enum visorinput_device_type devtype;
guid = visorchannel_get_uuid(dev->visorchannel);
if (uuid_le_cmp(guid, visor_mouse_channel_uuid) == 0)
devtype = visorinput_mouse;
else if (uuid_le_cmp(guid, visor_keyboard_channel_uuid) == 0)
devtype = visorinput_keyboard;
else
return -ENODEV;
visorbus_disable_channel_interrupts(dev);
if (!devdata_create(dev, devtype))
return -ENOMEM;
return 0;
}
static void
unregister_client_input(struct input_dev *visorinput_dev)
{
if (visorinput_dev)
input_unregister_device(visorinput_dev);
}
static void
visorinput_remove(struct visor_device *dev)
{
struct visorinput_devdata *devdata = dev_get_drvdata(&dev->device);
if (!devdata)
return;
mutex_lock(&devdata->lock_visor_dev);
visorbus_disable_channel_interrupts(dev);
dev_set_drvdata(&dev->device, NULL);
mutex_unlock(&devdata->lock_visor_dev);
unregister_client_input(devdata->visorinput_dev);
kfree(devdata);
}
static void
handle_locking_key(struct input_dev *visorinput_dev,
int keycode, int desired_state)
{
int led;
switch (keycode) {
case KEY_CAPSLOCK:
led = LED_CAPSL;
break;
case KEY_SCROLLLOCK:
led = LED_SCROLLL;
break;
case KEY_NUMLOCK:
led = LED_NUML;
break;
default:
led = -1;
return;
}
if (test_bit(led, visorinput_dev->led) != desired_state) {
input_report_key(visorinput_dev, keycode, 1);
input_sync(visorinput_dev);
input_report_key(visorinput_dev, keycode, 0);
input_sync(visorinput_dev);
__change_bit(led, visorinput_dev->led);
}
}
static int
scancode_to_keycode(int scancode)
{
if (scancode > 0xff)
return visorkbd_ext_keycode[(scancode >> 8) & 0xff];
return visorkbd_keycode[scancode];
}
static int
calc_button(int x)
{
switch (x) {
case 1:
return BTN_LEFT;
case 2:
return BTN_MIDDLE;
case 3:
return BTN_RIGHT;
default:
return -EINVAL;
}
}
static void
visorinput_channel_interrupt(struct visor_device *dev)
{
struct visor_inputreport r;
int scancode, keycode;
struct input_dev *visorinput_dev;
int xmotion, ymotion, button;
int i;
struct visorinput_devdata *devdata = dev_get_drvdata(&dev->device);
if (!devdata)
return;
visorinput_dev = devdata->visorinput_dev;
while (!visorchannel_signalremove(dev->visorchannel, 0, &r)) {
scancode = r.activity.arg1;
keycode = scancode_to_keycode(scancode);
switch (r.activity.action) {
case INPUTACTION_KEY_DOWN:
input_report_key(visorinput_dev, keycode, 1);
input_sync(visorinput_dev);
break;
case INPUTACTION_KEY_UP:
input_report_key(visorinput_dev, keycode, 0);
input_sync(visorinput_dev);
break;
case INPUTACTION_KEY_DOWN_UP:
input_report_key(visorinput_dev, keycode, 1);
input_sync(visorinput_dev);
input_report_key(visorinput_dev, keycode, 0);
input_sync(visorinput_dev);
break;
case INPUTACTION_SET_LOCKING_KEY_STATE:
handle_locking_key(visorinput_dev, keycode,
r.activity.arg2);
break;
case INPUTACTION_XY_MOTION:
xmotion = r.activity.arg1;
ymotion = r.activity.arg2;
input_report_abs(visorinput_dev, ABS_X, xmotion);
input_report_abs(visorinput_dev, ABS_Y, ymotion);
input_sync(visorinput_dev);
break;
case INPUTACTION_MOUSE_BUTTON_DOWN:
button = calc_button(r.activity.arg1);
if (button < 0)
break;
input_report_key(visorinput_dev, button, 1);
input_sync(visorinput_dev);
break;
case INPUTACTION_MOUSE_BUTTON_UP:
button = calc_button(r.activity.arg1);
if (button < 0)
break;
input_report_key(visorinput_dev, button, 0);
input_sync(visorinput_dev);
break;
case INPUTACTION_MOUSE_BUTTON_CLICK:
button = calc_button(r.activity.arg1);
if (button < 0)
break;
input_report_key(visorinput_dev, button, 1);
input_sync(visorinput_dev);
input_report_key(visorinput_dev, button, 0);
input_sync(visorinput_dev);
break;
case INPUTACTION_MOUSE_BUTTON_DCLICK:
button = calc_button(r.activity.arg1);
if (button < 0)
break;
for (i = 0; i < 2; i++) {
input_report_key(visorinput_dev, button, 1);
input_sync(visorinput_dev);
input_report_key(visorinput_dev, button, 0);
input_sync(visorinput_dev);
}
break;
case INPUTACTION_WHEEL_ROTATE_AWAY:
input_report_rel(visorinput_dev, REL_WHEEL, 1);
input_sync(visorinput_dev);
break;
case INPUTACTION_WHEEL_ROTATE_TOWARD:
input_report_rel(visorinput_dev, REL_WHEEL, -1);
input_sync(visorinput_dev);
break;
default:
break;
}
}
}
static int
visorinput_pause(struct visor_device *dev,
visorbus_state_complete_func complete_func)
{
int rc;
struct visorinput_devdata *devdata = dev_get_drvdata(&dev->device);
if (!devdata) {
rc = -ENODEV;
goto out;
}
mutex_lock(&devdata->lock_visor_dev);
if (devdata->paused) {
rc = -EBUSY;
goto out_locked;
}
if (devdata->interrupts_enabled)
visorbus_disable_channel_interrupts(dev);
devdata->paused = true;
complete_func(dev, 0);
rc = 0;
out_locked:
mutex_unlock(&devdata->lock_visor_dev);
out:
return rc;
}
static int
visorinput_resume(struct visor_device *dev,
visorbus_state_complete_func complete_func)
{
int rc;
struct visorinput_devdata *devdata = dev_get_drvdata(&dev->device);
if (!devdata) {
rc = -ENODEV;
goto out;
}
mutex_lock(&devdata->lock_visor_dev);
if (!devdata->paused) {
rc = -EBUSY;
goto out_locked;
}
devdata->paused = false;
complete_func(dev, 0);
if (devdata->interrupts_enabled)
visorbus_enable_channel_interrupts(dev);
rc = 0;
out_locked:
mutex_unlock(&devdata->lock_visor_dev);
out:
return rc;
}
static int
visorinput_init(void)
{
return visorbus_register_visor_driver(&visorinput_driver);
}
static void
visorinput_cleanup(void)
{
visorbus_unregister_visor_driver(&visorinput_driver);
}
