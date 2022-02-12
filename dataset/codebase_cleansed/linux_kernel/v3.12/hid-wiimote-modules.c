static void wiimod_keys_in_keys(struct wiimote_data *wdata, const __u8 *keys)
{
input_report_key(wdata->input, wiimod_keys_map[WIIPROTO_KEY_LEFT],
!!(keys[0] & 0x01));
input_report_key(wdata->input, wiimod_keys_map[WIIPROTO_KEY_RIGHT],
!!(keys[0] & 0x02));
input_report_key(wdata->input, wiimod_keys_map[WIIPROTO_KEY_DOWN],
!!(keys[0] & 0x04));
input_report_key(wdata->input, wiimod_keys_map[WIIPROTO_KEY_UP],
!!(keys[0] & 0x08));
input_report_key(wdata->input, wiimod_keys_map[WIIPROTO_KEY_PLUS],
!!(keys[0] & 0x10));
input_report_key(wdata->input, wiimod_keys_map[WIIPROTO_KEY_TWO],
!!(keys[1] & 0x01));
input_report_key(wdata->input, wiimod_keys_map[WIIPROTO_KEY_ONE],
!!(keys[1] & 0x02));
input_report_key(wdata->input, wiimod_keys_map[WIIPROTO_KEY_B],
!!(keys[1] & 0x04));
input_report_key(wdata->input, wiimod_keys_map[WIIPROTO_KEY_A],
!!(keys[1] & 0x08));
input_report_key(wdata->input, wiimod_keys_map[WIIPROTO_KEY_MINUS],
!!(keys[1] & 0x10));
input_report_key(wdata->input, wiimod_keys_map[WIIPROTO_KEY_HOME],
!!(keys[1] & 0x80));
input_sync(wdata->input);
}
static int wiimod_keys_probe(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
unsigned int i;
set_bit(EV_KEY, wdata->input->evbit);
for (i = 0; i < WIIPROTO_KEY_COUNT; ++i)
set_bit(wiimod_keys_map[i], wdata->input->keybit);
return 0;
}
static void wiimod_rumble_worker(struct work_struct *work)
{
struct wiimote_data *wdata = container_of(work, struct wiimote_data,
rumble_worker);
spin_lock_irq(&wdata->state.lock);
wiiproto_req_rumble(wdata, wdata->state.cache_rumble);
spin_unlock_irq(&wdata->state.lock);
}
static int wiimod_rumble_play(struct input_dev *dev, void *data,
struct ff_effect *eff)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
__u8 value;
if (eff->u.rumble.strong_magnitude || eff->u.rumble.weak_magnitude)
value = 1;
else
value = 0;
wdata->state.cache_rumble = value;
schedule_work(&wdata->rumble_worker);
return 0;
}
static int wiimod_rumble_probe(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
INIT_WORK(&wdata->rumble_worker, wiimod_rumble_worker);
set_bit(FF_RUMBLE, wdata->input->ffbit);
if (input_ff_create_memless(wdata->input, NULL, wiimod_rumble_play))
return -ENOMEM;
return 0;
}
static void wiimod_rumble_remove(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
unsigned long flags;
cancel_work_sync(&wdata->rumble_worker);
spin_lock_irqsave(&wdata->state.lock, flags);
wiiproto_req_rumble(wdata, 0);
spin_unlock_irqrestore(&wdata->state.lock, flags);
}
static int wiimod_battery_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct wiimote_data *wdata = container_of(psy, struct wiimote_data,
battery);
int ret = 0, state;
unsigned long flags;
if (psp == POWER_SUPPLY_PROP_SCOPE) {
val->intval = POWER_SUPPLY_SCOPE_DEVICE;
return 0;
} else if (psp != POWER_SUPPLY_PROP_CAPACITY) {
return -EINVAL;
}
ret = wiimote_cmd_acquire(wdata);
if (ret)
return ret;
spin_lock_irqsave(&wdata->state.lock, flags);
wiimote_cmd_set(wdata, WIIPROTO_REQ_SREQ, 0);
wiiproto_req_status(wdata);
spin_unlock_irqrestore(&wdata->state.lock, flags);
wiimote_cmd_wait(wdata);
wiimote_cmd_release(wdata);
spin_lock_irqsave(&wdata->state.lock, flags);
state = wdata->state.cmd_battery;
spin_unlock_irqrestore(&wdata->state.lock, flags);
val->intval = state * 100 / 255;
return ret;
}
static int wiimod_battery_probe(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
int ret;
wdata->battery.properties = wiimod_battery_props;
wdata->battery.num_properties = ARRAY_SIZE(wiimod_battery_props);
wdata->battery.get_property = wiimod_battery_get_property;
wdata->battery.type = POWER_SUPPLY_TYPE_BATTERY;
wdata->battery.use_for_apm = 0;
wdata->battery.name = kasprintf(GFP_KERNEL, "wiimote_battery_%s",
wdata->hdev->uniq);
if (!wdata->battery.name)
return -ENOMEM;
ret = power_supply_register(&wdata->hdev->dev, &wdata->battery);
if (ret) {
hid_err(wdata->hdev, "cannot register battery device\n");
goto err_free;
}
power_supply_powers(&wdata->battery, &wdata->hdev->dev);
return 0;
err_free:
kfree(wdata->battery.name);
wdata->battery.name = NULL;
return ret;
}
static void wiimod_battery_remove(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
if (!wdata->battery.name)
return;
power_supply_unregister(&wdata->battery);
kfree(wdata->battery.name);
wdata->battery.name = NULL;
}
static enum led_brightness wiimod_led_get(struct led_classdev *led_dev)
{
struct wiimote_data *wdata;
struct device *dev = led_dev->dev->parent;
int i;
unsigned long flags;
bool value = false;
wdata = hid_get_drvdata(container_of(dev, struct hid_device, dev));
for (i = 0; i < 4; ++i) {
if (wdata->leds[i] == led_dev) {
spin_lock_irqsave(&wdata->state.lock, flags);
value = wdata->state.flags & WIIPROTO_FLAG_LED(i + 1);
spin_unlock_irqrestore(&wdata->state.lock, flags);
break;
}
}
return value ? LED_FULL : LED_OFF;
}
static void wiimod_led_set(struct led_classdev *led_dev,
enum led_brightness value)
{
struct wiimote_data *wdata;
struct device *dev = led_dev->dev->parent;
int i;
unsigned long flags;
__u8 state, flag;
wdata = hid_get_drvdata(container_of(dev, struct hid_device, dev));
for (i = 0; i < 4; ++i) {
if (wdata->leds[i] == led_dev) {
flag = WIIPROTO_FLAG_LED(i + 1);
spin_lock_irqsave(&wdata->state.lock, flags);
state = wdata->state.flags;
if (value == LED_OFF)
wiiproto_req_leds(wdata, state & ~flag);
else
wiiproto_req_leds(wdata, state | flag);
spin_unlock_irqrestore(&wdata->state.lock, flags);
break;
}
}
}
static int wiimod_led_probe(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
struct device *dev = &wdata->hdev->dev;
size_t namesz = strlen(dev_name(dev)) + 9;
struct led_classdev *led;
unsigned long flags;
char *name;
int ret;
led = kzalloc(sizeof(struct led_classdev) + namesz, GFP_KERNEL);
if (!led)
return -ENOMEM;
name = (void*)&led[1];
snprintf(name, namesz, "%s:blue:p%lu", dev_name(dev), ops->arg);
led->name = name;
led->brightness = 0;
led->max_brightness = 1;
led->brightness_get = wiimod_led_get;
led->brightness_set = wiimod_led_set;
wdata->leds[ops->arg] = led;
ret = led_classdev_register(dev, led);
if (ret)
goto err_free;
if (ops->arg == 0) {
spin_lock_irqsave(&wdata->state.lock, flags);
wiiproto_req_leds(wdata, WIIPROTO_FLAG_LED1);
spin_unlock_irqrestore(&wdata->state.lock, flags);
}
return 0;
err_free:
wdata->leds[ops->arg] = NULL;
kfree(led);
return ret;
}
static void wiimod_led_remove(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
if (!wdata->leds[ops->arg])
return;
led_classdev_unregister(wdata->leds[ops->arg]);
kfree(wdata->leds[ops->arg]);
wdata->leds[ops->arg] = NULL;
}
static void wiimod_accel_in_accel(struct wiimote_data *wdata,
const __u8 *accel)
{
__u16 x, y, z;
if (!(wdata->state.flags & WIIPROTO_FLAG_ACCEL))
return;
x = accel[2] << 2;
y = accel[3] << 2;
z = accel[4] << 2;
x |= (accel[0] >> 5) & 0x3;
y |= (accel[1] >> 4) & 0x2;
z |= (accel[1] >> 5) & 0x2;
input_report_abs(wdata->accel, ABS_RX, x - 0x200);
input_report_abs(wdata->accel, ABS_RY, y - 0x200);
input_report_abs(wdata->accel, ABS_RZ, z - 0x200);
input_sync(wdata->accel);
}
static int wiimod_accel_open(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
wiiproto_req_accel(wdata, true);
spin_unlock_irqrestore(&wdata->state.lock, flags);
return 0;
}
static void wiimod_accel_close(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
wiiproto_req_accel(wdata, false);
spin_unlock_irqrestore(&wdata->state.lock, flags);
}
static int wiimod_accel_probe(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
int ret;
wdata->accel = input_allocate_device();
if (!wdata->accel)
return -ENOMEM;
input_set_drvdata(wdata->accel, wdata);
wdata->accel->open = wiimod_accel_open;
wdata->accel->close = wiimod_accel_close;
wdata->accel->dev.parent = &wdata->hdev->dev;
wdata->accel->id.bustype = wdata->hdev->bus;
wdata->accel->id.vendor = wdata->hdev->vendor;
wdata->accel->id.product = wdata->hdev->product;
wdata->accel->id.version = wdata->hdev->version;
wdata->accel->name = WIIMOTE_NAME " Accelerometer";
set_bit(EV_ABS, wdata->accel->evbit);
set_bit(ABS_RX, wdata->accel->absbit);
set_bit(ABS_RY, wdata->accel->absbit);
set_bit(ABS_RZ, wdata->accel->absbit);
input_set_abs_params(wdata->accel, ABS_RX, -500, 500, 2, 4);
input_set_abs_params(wdata->accel, ABS_RY, -500, 500, 2, 4);
input_set_abs_params(wdata->accel, ABS_RZ, -500, 500, 2, 4);
ret = input_register_device(wdata->accel);
if (ret) {
hid_err(wdata->hdev, "cannot register input device\n");
goto err_free;
}
return 0;
err_free:
input_free_device(wdata->accel);
wdata->accel = NULL;
return ret;
}
static void wiimod_accel_remove(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
if (!wdata->accel)
return;
input_unregister_device(wdata->accel);
wdata->accel = NULL;
}
static void wiimod_ir_in_ir(struct wiimote_data *wdata, const __u8 *ir,
bool packed, unsigned int id)
{
__u16 x, y;
__u8 xid, yid;
bool sync = false;
if (!(wdata->state.flags & WIIPROTO_FLAGS_IR))
return;
switch (id) {
case 0:
xid = ABS_HAT0X;
yid = ABS_HAT0Y;
break;
case 1:
xid = ABS_HAT1X;
yid = ABS_HAT1Y;
break;
case 2:
xid = ABS_HAT2X;
yid = ABS_HAT2Y;
break;
case 3:
xid = ABS_HAT3X;
yid = ABS_HAT3Y;
sync = true;
break;
default:
return;
}
if (packed) {
x = ir[1] | ((ir[0] & 0x03) << 8);
y = ir[2] | ((ir[0] & 0x0c) << 6);
} else {
x = ir[0] | ((ir[2] & 0x30) << 4);
y = ir[1] | ((ir[2] & 0xc0) << 2);
}
input_report_abs(wdata->ir, xid, x);
input_report_abs(wdata->ir, yid, y);
if (sync)
input_sync(wdata->ir);
}
static int wiimod_ir_change(struct wiimote_data *wdata, __u16 mode)
{
int ret;
unsigned long flags;
__u8 format = 0;
static const __u8 data_enable[] = { 0x01 };
static const __u8 data_sens1[] = { 0x02, 0x00, 0x00, 0x71, 0x01,
0x00, 0xaa, 0x00, 0x64 };
static const __u8 data_sens2[] = { 0x63, 0x03 };
static const __u8 data_fin[] = { 0x08 };
spin_lock_irqsave(&wdata->state.lock, flags);
if (mode == (wdata->state.flags & WIIPROTO_FLAGS_IR)) {
spin_unlock_irqrestore(&wdata->state.lock, flags);
return 0;
}
if (mode == 0) {
wdata->state.flags &= ~WIIPROTO_FLAGS_IR;
wiiproto_req_ir1(wdata, 0);
wiiproto_req_ir2(wdata, 0);
wiiproto_req_drm(wdata, WIIPROTO_REQ_NULL);
spin_unlock_irqrestore(&wdata->state.lock, flags);
return 0;
}
spin_unlock_irqrestore(&wdata->state.lock, flags);
ret = wiimote_cmd_acquire(wdata);
if (ret)
return ret;
spin_lock_irqsave(&wdata->state.lock, flags);
wiimote_cmd_set(wdata, WIIPROTO_REQ_IR1, 0);
wiiproto_req_ir1(wdata, 0x06);
spin_unlock_irqrestore(&wdata->state.lock, flags);
ret = wiimote_cmd_wait(wdata);
if (ret)
goto unlock;
if (wdata->state.cmd_err) {
ret = -EIO;
goto unlock;
}
spin_lock_irqsave(&wdata->state.lock, flags);
wiimote_cmd_set(wdata, WIIPROTO_REQ_IR2, 0);
wiiproto_req_ir2(wdata, 0x06);
spin_unlock_irqrestore(&wdata->state.lock, flags);
ret = wiimote_cmd_wait(wdata);
if (ret)
goto unlock;
if (wdata->state.cmd_err) {
ret = -EIO;
goto unlock;
}
ret = wiimote_cmd_write(wdata, 0xb00030, data_enable,
sizeof(data_enable));
if (ret)
goto unlock;
ret = wiimote_cmd_write(wdata, 0xb00000, data_sens1,
sizeof(data_sens1));
if (ret)
goto unlock;
ret = wiimote_cmd_write(wdata, 0xb0001a, data_sens2,
sizeof(data_sens2));
if (ret)
goto unlock;
switch (mode) {
case WIIPROTO_FLAG_IR_FULL:
format = 5;
break;
case WIIPROTO_FLAG_IR_EXT:
format = 3;
break;
case WIIPROTO_FLAG_IR_BASIC:
format = 1;
break;
}
ret = wiimote_cmd_write(wdata, 0xb00033, &format, sizeof(format));
if (ret)
goto unlock;
ret = wiimote_cmd_write(wdata, 0xb00030, data_fin, sizeof(data_fin));
if (ret)
goto unlock;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.flags &= ~WIIPROTO_FLAGS_IR;
wdata->state.flags |= mode & WIIPROTO_FLAGS_IR;
wiiproto_req_drm(wdata, WIIPROTO_REQ_NULL);
spin_unlock_irqrestore(&wdata->state.lock, flags);
unlock:
wiimote_cmd_release(wdata);
return ret;
}
static int wiimod_ir_open(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
return wiimod_ir_change(wdata, WIIPROTO_FLAG_IR_BASIC);
}
static void wiimod_ir_close(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
wiimod_ir_change(wdata, 0);
}
static int wiimod_ir_probe(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
int ret;
wdata->ir = input_allocate_device();
if (!wdata->ir)
return -ENOMEM;
input_set_drvdata(wdata->ir, wdata);
wdata->ir->open = wiimod_ir_open;
wdata->ir->close = wiimod_ir_close;
wdata->ir->dev.parent = &wdata->hdev->dev;
wdata->ir->id.bustype = wdata->hdev->bus;
wdata->ir->id.vendor = wdata->hdev->vendor;
wdata->ir->id.product = wdata->hdev->product;
wdata->ir->id.version = wdata->hdev->version;
wdata->ir->name = WIIMOTE_NAME " IR";
set_bit(EV_ABS, wdata->ir->evbit);
set_bit(ABS_HAT0X, wdata->ir->absbit);
set_bit(ABS_HAT0Y, wdata->ir->absbit);
set_bit(ABS_HAT1X, wdata->ir->absbit);
set_bit(ABS_HAT1Y, wdata->ir->absbit);
set_bit(ABS_HAT2X, wdata->ir->absbit);
set_bit(ABS_HAT2Y, wdata->ir->absbit);
set_bit(ABS_HAT3X, wdata->ir->absbit);
set_bit(ABS_HAT3Y, wdata->ir->absbit);
input_set_abs_params(wdata->ir, ABS_HAT0X, 0, 1023, 2, 4);
input_set_abs_params(wdata->ir, ABS_HAT0Y, 0, 767, 2, 4);
input_set_abs_params(wdata->ir, ABS_HAT1X, 0, 1023, 2, 4);
input_set_abs_params(wdata->ir, ABS_HAT1Y, 0, 767, 2, 4);
input_set_abs_params(wdata->ir, ABS_HAT2X, 0, 1023, 2, 4);
input_set_abs_params(wdata->ir, ABS_HAT2Y, 0, 767, 2, 4);
input_set_abs_params(wdata->ir, ABS_HAT3X, 0, 1023, 2, 4);
input_set_abs_params(wdata->ir, ABS_HAT3Y, 0, 767, 2, 4);
ret = input_register_device(wdata->ir);
if (ret) {
hid_err(wdata->hdev, "cannot register input device\n");
goto err_free;
}
return 0;
err_free:
input_free_device(wdata->ir);
wdata->ir = NULL;
return ret;
}
static void wiimod_ir_remove(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
if (!wdata->ir)
return;
input_unregister_device(wdata->ir);
wdata->ir = NULL;
}
static void wiimod_nunchuk_in_ext(struct wiimote_data *wdata, const __u8 *ext)
{
__s16 x, y, z, bx, by;
bx = ext[0];
by = ext[1];
bx -= 128;
by -= 128;
x = ext[2] << 2;
y = ext[3] << 2;
z = ext[4] << 2;
if (wdata->state.flags & WIIPROTO_FLAG_MP_ACTIVE) {
x |= (ext[5] >> 3) & 0x02;
y |= (ext[5] >> 4) & 0x02;
z &= ~0x4;
z |= (ext[5] >> 5) & 0x06;
} else {
x |= (ext[5] >> 2) & 0x03;
y |= (ext[5] >> 4) & 0x03;
z |= (ext[5] >> 6) & 0x03;
}
x -= 0x200;
y -= 0x200;
z -= 0x200;
input_report_abs(wdata->extension.input, ABS_HAT0X, bx);
input_report_abs(wdata->extension.input, ABS_HAT0Y, by);
input_report_abs(wdata->extension.input, ABS_RX, x);
input_report_abs(wdata->extension.input, ABS_RY, y);
input_report_abs(wdata->extension.input, ABS_RZ, z);
if (wdata->state.flags & WIIPROTO_FLAG_MP_ACTIVE) {
input_report_key(wdata->extension.input,
wiimod_nunchuk_map[WIIMOD_NUNCHUK_KEY_Z],
!(ext[5] & 0x04));
input_report_key(wdata->extension.input,
wiimod_nunchuk_map[WIIMOD_NUNCHUK_KEY_C],
!(ext[5] & 0x08));
} else {
input_report_key(wdata->extension.input,
wiimod_nunchuk_map[WIIMOD_NUNCHUK_KEY_Z],
!(ext[5] & 0x01));
input_report_key(wdata->extension.input,
wiimod_nunchuk_map[WIIMOD_NUNCHUK_KEY_C],
!(ext[5] & 0x02));
}
input_sync(wdata->extension.input);
}
static int wiimod_nunchuk_open(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.flags |= WIIPROTO_FLAG_EXT_USED;
wiiproto_req_drm(wdata, WIIPROTO_REQ_NULL);
spin_unlock_irqrestore(&wdata->state.lock, flags);
return 0;
}
static void wiimod_nunchuk_close(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.flags &= ~WIIPROTO_FLAG_EXT_USED;
wiiproto_req_drm(wdata, WIIPROTO_REQ_NULL);
spin_unlock_irqrestore(&wdata->state.lock, flags);
}
static int wiimod_nunchuk_probe(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
int ret, i;
wdata->extension.input = input_allocate_device();
if (!wdata->extension.input)
return -ENOMEM;
input_set_drvdata(wdata->extension.input, wdata);
wdata->extension.input->open = wiimod_nunchuk_open;
wdata->extension.input->close = wiimod_nunchuk_close;
wdata->extension.input->dev.parent = &wdata->hdev->dev;
wdata->extension.input->id.bustype = wdata->hdev->bus;
wdata->extension.input->id.vendor = wdata->hdev->vendor;
wdata->extension.input->id.product = wdata->hdev->product;
wdata->extension.input->id.version = wdata->hdev->version;
wdata->extension.input->name = WIIMOTE_NAME " Nunchuk";
set_bit(EV_KEY, wdata->extension.input->evbit);
for (i = 0; i < WIIMOD_NUNCHUK_KEY_NUM; ++i)
set_bit(wiimod_nunchuk_map[i],
wdata->extension.input->keybit);
set_bit(EV_ABS, wdata->extension.input->evbit);
set_bit(ABS_HAT0X, wdata->extension.input->absbit);
set_bit(ABS_HAT0Y, wdata->extension.input->absbit);
input_set_abs_params(wdata->extension.input,
ABS_HAT0X, -120, 120, 2, 4);
input_set_abs_params(wdata->extension.input,
ABS_HAT0Y, -120, 120, 2, 4);
set_bit(ABS_RX, wdata->extension.input->absbit);
set_bit(ABS_RY, wdata->extension.input->absbit);
set_bit(ABS_RZ, wdata->extension.input->absbit);
input_set_abs_params(wdata->extension.input,
ABS_RX, -500, 500, 2, 4);
input_set_abs_params(wdata->extension.input,
ABS_RY, -500, 500, 2, 4);
input_set_abs_params(wdata->extension.input,
ABS_RZ, -500, 500, 2, 4);
ret = input_register_device(wdata->extension.input);
if (ret)
goto err_free;
return 0;
err_free:
input_free_device(wdata->extension.input);
wdata->extension.input = NULL;
return ret;
}
static void wiimod_nunchuk_remove(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
if (!wdata->extension.input)
return;
input_unregister_device(wdata->extension.input);
wdata->extension.input = NULL;
}
static void wiimod_classic_in_ext(struct wiimote_data *wdata, const __u8 *ext)
{
__s8 rx, ry, lx, ly, lt, rt;
if (wdata->state.flags & WIIPROTO_FLAG_MP_ACTIVE) {
lx = ext[0] & 0x3e;
ly = ext[1] & 0x3e;
} else {
lx = ext[0] & 0x3f;
ly = ext[1] & 0x3f;
}
rx = (ext[0] >> 3) & 0x18;
rx |= (ext[1] >> 5) & 0x06;
rx |= (ext[2] >> 7) & 0x01;
ry = ext[2] & 0x1f;
rt = ext[3] & 0x1f;
lt = (ext[2] >> 2) & 0x18;
lt |= (ext[3] >> 5) & 0x07;
rx <<= 1;
ry <<= 1;
rt <<= 1;
lt <<= 1;
input_report_abs(wdata->extension.input, ABS_HAT1X, lx - 0x20);
input_report_abs(wdata->extension.input, ABS_HAT1Y, ly - 0x20);
input_report_abs(wdata->extension.input, ABS_HAT2X, rx - 0x20);
input_report_abs(wdata->extension.input, ABS_HAT2Y, ry - 0x20);
input_report_abs(wdata->extension.input, ABS_HAT3X, rt);
input_report_abs(wdata->extension.input, ABS_HAT3Y, lt);
input_report_key(wdata->extension.input,
wiimod_classic_map[WIIMOD_CLASSIC_KEY_RIGHT],
!(ext[4] & 0x80));
input_report_key(wdata->extension.input,
wiimod_classic_map[WIIMOD_CLASSIC_KEY_DOWN],
!(ext[4] & 0x40));
input_report_key(wdata->extension.input,
wiimod_classic_map[WIIMOD_CLASSIC_KEY_LT],
!(ext[4] & 0x20));
input_report_key(wdata->extension.input,
wiimod_classic_map[WIIMOD_CLASSIC_KEY_MINUS],
!(ext[4] & 0x10));
input_report_key(wdata->extension.input,
wiimod_classic_map[WIIMOD_CLASSIC_KEY_HOME],
!(ext[4] & 0x08));
input_report_key(wdata->extension.input,
wiimod_classic_map[WIIMOD_CLASSIC_KEY_PLUS],
!(ext[4] & 0x04));
input_report_key(wdata->extension.input,
wiimod_classic_map[WIIMOD_CLASSIC_KEY_RT],
!(ext[4] & 0x02));
input_report_key(wdata->extension.input,
wiimod_classic_map[WIIMOD_CLASSIC_KEY_ZL],
!(ext[5] & 0x80));
input_report_key(wdata->extension.input,
wiimod_classic_map[WIIMOD_CLASSIC_KEY_B],
!(ext[5] & 0x40));
input_report_key(wdata->extension.input,
wiimod_classic_map[WIIMOD_CLASSIC_KEY_Y],
!(ext[5] & 0x20));
input_report_key(wdata->extension.input,
wiimod_classic_map[WIIMOD_CLASSIC_KEY_A],
!(ext[5] & 0x10));
input_report_key(wdata->extension.input,
wiimod_classic_map[WIIMOD_CLASSIC_KEY_X],
!(ext[5] & 0x08));
input_report_key(wdata->extension.input,
wiimod_classic_map[WIIMOD_CLASSIC_KEY_ZR],
!(ext[5] & 0x04));
if (wdata->state.flags & WIIPROTO_FLAG_MP_ACTIVE) {
input_report_key(wdata->extension.input,
wiimod_classic_map[WIIMOD_CLASSIC_KEY_LEFT],
!(ext[1] & 0x01));
input_report_key(wdata->extension.input,
wiimod_classic_map[WIIMOD_CLASSIC_KEY_UP],
!(ext[0] & 0x01));
} else {
input_report_key(wdata->extension.input,
wiimod_classic_map[WIIMOD_CLASSIC_KEY_LEFT],
!(ext[5] & 0x02));
input_report_key(wdata->extension.input,
wiimod_classic_map[WIIMOD_CLASSIC_KEY_UP],
!(ext[5] & 0x01));
}
input_sync(wdata->extension.input);
}
static int wiimod_classic_open(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.flags |= WIIPROTO_FLAG_EXT_USED;
wiiproto_req_drm(wdata, WIIPROTO_REQ_NULL);
spin_unlock_irqrestore(&wdata->state.lock, flags);
return 0;
}
static void wiimod_classic_close(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.flags &= ~WIIPROTO_FLAG_EXT_USED;
wiiproto_req_drm(wdata, WIIPROTO_REQ_NULL);
spin_unlock_irqrestore(&wdata->state.lock, flags);
}
static int wiimod_classic_probe(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
int ret, i;
wdata->extension.input = input_allocate_device();
if (!wdata->extension.input)
return -ENOMEM;
input_set_drvdata(wdata->extension.input, wdata);
wdata->extension.input->open = wiimod_classic_open;
wdata->extension.input->close = wiimod_classic_close;
wdata->extension.input->dev.parent = &wdata->hdev->dev;
wdata->extension.input->id.bustype = wdata->hdev->bus;
wdata->extension.input->id.vendor = wdata->hdev->vendor;
wdata->extension.input->id.product = wdata->hdev->product;
wdata->extension.input->id.version = wdata->hdev->version;
wdata->extension.input->name = WIIMOTE_NAME " Classic Controller";
set_bit(EV_KEY, wdata->extension.input->evbit);
for (i = 0; i < WIIMOD_CLASSIC_KEY_NUM; ++i)
set_bit(wiimod_classic_map[i],
wdata->extension.input->keybit);
set_bit(EV_ABS, wdata->extension.input->evbit);
set_bit(ABS_HAT1X, wdata->extension.input->absbit);
set_bit(ABS_HAT1Y, wdata->extension.input->absbit);
set_bit(ABS_HAT2X, wdata->extension.input->absbit);
set_bit(ABS_HAT2Y, wdata->extension.input->absbit);
set_bit(ABS_HAT3X, wdata->extension.input->absbit);
set_bit(ABS_HAT3Y, wdata->extension.input->absbit);
input_set_abs_params(wdata->extension.input,
ABS_HAT1X, -30, 30, 1, 1);
input_set_abs_params(wdata->extension.input,
ABS_HAT1Y, -30, 30, 1, 1);
input_set_abs_params(wdata->extension.input,
ABS_HAT2X, -30, 30, 1, 1);
input_set_abs_params(wdata->extension.input,
ABS_HAT2Y, -30, 30, 1, 1);
input_set_abs_params(wdata->extension.input,
ABS_HAT3X, -30, 30, 1, 1);
input_set_abs_params(wdata->extension.input,
ABS_HAT3Y, -30, 30, 1, 1);
ret = input_register_device(wdata->extension.input);
if (ret)
goto err_free;
return 0;
err_free:
input_free_device(wdata->extension.input);
wdata->extension.input = NULL;
return ret;
}
static void wiimod_classic_remove(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
if (!wdata->extension.input)
return;
input_unregister_device(wdata->extension.input);
wdata->extension.input = NULL;
}
static void wiimod_bboard_in_keys(struct wiimote_data *wdata, const __u8 *keys)
{
input_report_key(wdata->extension.input, BTN_A,
!!(keys[1] & 0x08));
input_sync(wdata->extension.input);
}
static void wiimod_bboard_in_ext(struct wiimote_data *wdata,
const __u8 *ext)
{
__s32 val[4], tmp, div;
unsigned int i;
struct wiimote_state *s = &wdata->state;
val[0] = ext[0];
val[0] <<= 8;
val[0] |= ext[1];
val[1] = ext[2];
val[1] <<= 8;
val[1] |= ext[3];
val[2] = ext[4];
val[2] <<= 8;
val[2] |= ext[5];
val[3] = ext[6];
val[3] <<= 8;
val[3] |= ext[7];
for (i = 0; i < 4; i++) {
if (val[i] <= s->calib_bboard[i][0]) {
tmp = 0;
} else if (val[i] < s->calib_bboard[i][1]) {
tmp = val[i] - s->calib_bboard[i][0];
tmp *= 1700;
div = s->calib_bboard[i][1] - s->calib_bboard[i][0];
tmp /= div ? div : 1;
} else {
tmp = val[i] - s->calib_bboard[i][1];
tmp *= 1700;
div = s->calib_bboard[i][2] - s->calib_bboard[i][1];
tmp /= div ? div : 1;
tmp += 1700;
}
val[i] = tmp;
}
input_report_abs(wdata->extension.input, ABS_HAT0X, val[0]);
input_report_abs(wdata->extension.input, ABS_HAT0Y, val[1]);
input_report_abs(wdata->extension.input, ABS_HAT1X, val[2]);
input_report_abs(wdata->extension.input, ABS_HAT1Y, val[3]);
input_sync(wdata->extension.input);
}
static int wiimod_bboard_open(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.flags |= WIIPROTO_FLAG_EXT_USED;
wiiproto_req_drm(wdata, WIIPROTO_REQ_NULL);
spin_unlock_irqrestore(&wdata->state.lock, flags);
return 0;
}
static void wiimod_bboard_close(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.flags &= ~WIIPROTO_FLAG_EXT_USED;
wiiproto_req_drm(wdata, WIIPROTO_REQ_NULL);
spin_unlock_irqrestore(&wdata->state.lock, flags);
}
static ssize_t wiimod_bboard_calib_show(struct device *dev,
struct device_attribute *attr,
char *out)
{
struct wiimote_data *wdata = dev_to_wii(dev);
int i, j, ret;
__u16 val;
__u8 buf[24], offs;
ret = wiimote_cmd_acquire(wdata);
if (ret)
return ret;
ret = wiimote_cmd_read(wdata, 0xa40024, buf, 12);
if (ret != 12) {
wiimote_cmd_release(wdata);
return ret < 0 ? ret : -EIO;
}
ret = wiimote_cmd_read(wdata, 0xa40024 + 12, buf + 12, 12);
if (ret != 12) {
wiimote_cmd_release(wdata);
return ret < 0 ? ret : -EIO;
}
wiimote_cmd_release(wdata);
spin_lock_irq(&wdata->state.lock);
offs = 0;
for (i = 0; i < 3; ++i) {
for (j = 0; j < 4; ++j) {
wdata->state.calib_bboard[j][i] = buf[offs];
wdata->state.calib_bboard[j][i] <<= 8;
wdata->state.calib_bboard[j][i] |= buf[offs + 1];
offs += 2;
}
}
spin_unlock_irq(&wdata->state.lock);
ret = 0;
for (i = 0; i < 3; ++i) {
for (j = 0; j < 4; ++j) {
val = wdata->state.calib_bboard[j][i];
if (i == 2 && j == 3)
ret += sprintf(&out[ret], "%04x\n", val);
else
ret += sprintf(&out[ret], "%04x:", val);
}
}
return ret;
}
static int wiimod_bboard_probe(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
int ret, i, j;
__u8 buf[24], offs;
wiimote_cmd_acquire_noint(wdata);
ret = wiimote_cmd_read(wdata, 0xa40024, buf, 12);
if (ret != 12) {
wiimote_cmd_release(wdata);
return ret < 0 ? ret : -EIO;
}
ret = wiimote_cmd_read(wdata, 0xa40024 + 12, buf + 12, 12);
if (ret != 12) {
wiimote_cmd_release(wdata);
return ret < 0 ? ret : -EIO;
}
wiimote_cmd_release(wdata);
offs = 0;
for (i = 0; i < 3; ++i) {
for (j = 0; j < 4; ++j) {
wdata->state.calib_bboard[j][i] = buf[offs];
wdata->state.calib_bboard[j][i] <<= 8;
wdata->state.calib_bboard[j][i] |= buf[offs + 1];
offs += 2;
}
}
wdata->extension.input = input_allocate_device();
if (!wdata->extension.input)
return -ENOMEM;
ret = device_create_file(&wdata->hdev->dev,
&dev_attr_bboard_calib);
if (ret) {
hid_err(wdata->hdev, "cannot create sysfs attribute\n");
goto err_free;
}
input_set_drvdata(wdata->extension.input, wdata);
wdata->extension.input->open = wiimod_bboard_open;
wdata->extension.input->close = wiimod_bboard_close;
wdata->extension.input->dev.parent = &wdata->hdev->dev;
wdata->extension.input->id.bustype = wdata->hdev->bus;
wdata->extension.input->id.vendor = wdata->hdev->vendor;
wdata->extension.input->id.product = wdata->hdev->product;
wdata->extension.input->id.version = wdata->hdev->version;
wdata->extension.input->name = WIIMOTE_NAME " Balance Board";
set_bit(EV_KEY, wdata->extension.input->evbit);
set_bit(BTN_A, wdata->extension.input->keybit);
set_bit(EV_ABS, wdata->extension.input->evbit);
set_bit(ABS_HAT0X, wdata->extension.input->absbit);
set_bit(ABS_HAT0Y, wdata->extension.input->absbit);
set_bit(ABS_HAT1X, wdata->extension.input->absbit);
set_bit(ABS_HAT1Y, wdata->extension.input->absbit);
input_set_abs_params(wdata->extension.input,
ABS_HAT0X, 0, 65535, 2, 4);
input_set_abs_params(wdata->extension.input,
ABS_HAT0Y, 0, 65535, 2, 4);
input_set_abs_params(wdata->extension.input,
ABS_HAT1X, 0, 65535, 2, 4);
input_set_abs_params(wdata->extension.input,
ABS_HAT1Y, 0, 65535, 2, 4);
ret = input_register_device(wdata->extension.input);
if (ret)
goto err_file;
return 0;
err_file:
device_remove_file(&wdata->hdev->dev,
&dev_attr_bboard_calib);
err_free:
input_free_device(wdata->extension.input);
wdata->extension.input = NULL;
return ret;
}
static void wiimod_bboard_remove(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
if (!wdata->extension.input)
return;
input_unregister_device(wdata->extension.input);
wdata->extension.input = NULL;
device_remove_file(&wdata->hdev->dev,
&dev_attr_bboard_calib);
}
static void wiimod_pro_in_ext(struct wiimote_data *wdata, const __u8 *ext)
{
__s16 rx, ry, lx, ly;
lx = (ext[0] & 0xff) | ((ext[1] & 0x0f) << 8);
rx = (ext[2] & 0xff) | ((ext[3] & 0x0f) << 8);
ly = (ext[4] & 0xff) | ((ext[5] & 0x0f) << 8);
ry = (ext[6] & 0xff) | ((ext[7] & 0x0f) << 8);
input_report_abs(wdata->extension.input, ABS_X, lx - 0x800);
input_report_abs(wdata->extension.input, ABS_Y, ly - 0x800);
input_report_abs(wdata->extension.input, ABS_RX, rx - 0x800);
input_report_abs(wdata->extension.input, ABS_RY, ry - 0x800);
input_report_key(wdata->extension.input,
wiimod_pro_map[WIIMOD_PRO_KEY_RIGHT],
!(ext[8] & 0x80));
input_report_key(wdata->extension.input,
wiimod_pro_map[WIIMOD_PRO_KEY_DOWN],
!(ext[8] & 0x40));
input_report_key(wdata->extension.input,
wiimod_pro_map[WIIMOD_PRO_KEY_TL],
!(ext[8] & 0x20));
input_report_key(wdata->extension.input,
wiimod_pro_map[WIIMOD_PRO_KEY_MINUS],
!(ext[8] & 0x10));
input_report_key(wdata->extension.input,
wiimod_pro_map[WIIMOD_PRO_KEY_HOME],
!(ext[8] & 0x08));
input_report_key(wdata->extension.input,
wiimod_pro_map[WIIMOD_PRO_KEY_PLUS],
!(ext[8] & 0x04));
input_report_key(wdata->extension.input,
wiimod_pro_map[WIIMOD_PRO_KEY_TR],
!(ext[8] & 0x02));
input_report_key(wdata->extension.input,
wiimod_pro_map[WIIMOD_PRO_KEY_ZL],
!(ext[9] & 0x80));
input_report_key(wdata->extension.input,
wiimod_pro_map[WIIMOD_PRO_KEY_B],
!(ext[9] & 0x40));
input_report_key(wdata->extension.input,
wiimod_pro_map[WIIMOD_PRO_KEY_Y],
!(ext[9] & 0x20));
input_report_key(wdata->extension.input,
wiimod_pro_map[WIIMOD_PRO_KEY_A],
!(ext[9] & 0x10));
input_report_key(wdata->extension.input,
wiimod_pro_map[WIIMOD_PRO_KEY_X],
!(ext[9] & 0x08));
input_report_key(wdata->extension.input,
wiimod_pro_map[WIIMOD_PRO_KEY_ZR],
!(ext[9] & 0x04));
input_report_key(wdata->extension.input,
wiimod_pro_map[WIIMOD_PRO_KEY_LEFT],
!(ext[9] & 0x02));
input_report_key(wdata->extension.input,
wiimod_pro_map[WIIMOD_PRO_KEY_UP],
!(ext[9] & 0x01));
input_report_key(wdata->extension.input,
wiimod_pro_map[WIIMOD_PRO_KEY_THUMBL],
!(ext[10] & 0x02));
input_report_key(wdata->extension.input,
wiimod_pro_map[WIIMOD_PRO_KEY_THUMBR],
!(ext[10] & 0x01));
input_sync(wdata->extension.input);
}
static int wiimod_pro_open(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.flags |= WIIPROTO_FLAG_EXT_USED;
wiiproto_req_drm(wdata, WIIPROTO_REQ_NULL);
spin_unlock_irqrestore(&wdata->state.lock, flags);
return 0;
}
static void wiimod_pro_close(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.flags &= ~WIIPROTO_FLAG_EXT_USED;
wiiproto_req_drm(wdata, WIIPROTO_REQ_NULL);
spin_unlock_irqrestore(&wdata->state.lock, flags);
}
static int wiimod_pro_play(struct input_dev *dev, void *data,
struct ff_effect *eff)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
__u8 value;
if (eff->u.rumble.strong_magnitude || eff->u.rumble.weak_magnitude)
value = 1;
else
value = 0;
wdata->state.cache_rumble = value;
schedule_work(&wdata->rumble_worker);
return 0;
}
static int wiimod_pro_probe(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
int ret, i;
INIT_WORK(&wdata->rumble_worker, wiimod_rumble_worker);
wdata->extension.input = input_allocate_device();
if (!wdata->extension.input)
return -ENOMEM;
set_bit(FF_RUMBLE, wdata->extension.input->ffbit);
input_set_drvdata(wdata->extension.input, wdata);
if (input_ff_create_memless(wdata->extension.input, NULL,
wiimod_pro_play)) {
ret = -ENOMEM;
goto err_free;
}
wdata->extension.input->open = wiimod_pro_open;
wdata->extension.input->close = wiimod_pro_close;
wdata->extension.input->dev.parent = &wdata->hdev->dev;
wdata->extension.input->id.bustype = wdata->hdev->bus;
wdata->extension.input->id.vendor = wdata->hdev->vendor;
wdata->extension.input->id.product = wdata->hdev->product;
wdata->extension.input->id.version = wdata->hdev->version;
wdata->extension.input->name = WIIMOTE_NAME " Pro Controller";
set_bit(EV_KEY, wdata->extension.input->evbit);
for (i = 0; i < WIIMOD_PRO_KEY_NUM; ++i)
set_bit(wiimod_pro_map[i],
wdata->extension.input->keybit);
set_bit(EV_ABS, wdata->extension.input->evbit);
set_bit(ABS_X, wdata->extension.input->absbit);
set_bit(ABS_Y, wdata->extension.input->absbit);
set_bit(ABS_RX, wdata->extension.input->absbit);
set_bit(ABS_RY, wdata->extension.input->absbit);
input_set_abs_params(wdata->extension.input,
ABS_X, -0x800, 0x800, 2, 4);
input_set_abs_params(wdata->extension.input,
ABS_Y, -0x800, 0x800, 2, 4);
input_set_abs_params(wdata->extension.input,
ABS_RX, -0x800, 0x800, 2, 4);
input_set_abs_params(wdata->extension.input,
ABS_RY, -0x800, 0x800, 2, 4);
ret = input_register_device(wdata->extension.input);
if (ret)
goto err_free;
return 0;
err_free:
input_free_device(wdata->extension.input);
wdata->extension.input = NULL;
return ret;
}
static void wiimod_pro_remove(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
unsigned long flags;
if (!wdata->extension.input)
return;
input_unregister_device(wdata->extension.input);
wdata->extension.input = NULL;
cancel_work_sync(&wdata->rumble_worker);
spin_lock_irqsave(&wdata->state.lock, flags);
wiiproto_req_rumble(wdata, 0);
spin_unlock_irqrestore(&wdata->state.lock, flags);
}
static int wiimod_builtin_mp_probe(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.flags |= WIIPROTO_FLAG_BUILTIN_MP;
spin_unlock_irqrestore(&wdata->state.lock, flags);
return 0;
}
static void wiimod_builtin_mp_remove(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.flags |= WIIPROTO_FLAG_BUILTIN_MP;
spin_unlock_irqrestore(&wdata->state.lock, flags);
}
static int wiimod_no_mp_probe(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.flags |= WIIPROTO_FLAG_NO_MP;
spin_unlock_irqrestore(&wdata->state.lock, flags);
return 0;
}
static void wiimod_no_mp_remove(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.flags |= WIIPROTO_FLAG_NO_MP;
spin_unlock_irqrestore(&wdata->state.lock, flags);
}
static void wiimod_mp_in_mp(struct wiimote_data *wdata, const __u8 *ext)
{
__s32 x, y, z;
x = ext[0];
y = ext[1];
z = ext[2];
x |= (((__u16)ext[3]) << 6) & 0xff00;
y |= (((__u16)ext[4]) << 6) & 0xff00;
z |= (((__u16)ext[5]) << 6) & 0xff00;
x -= 8192;
y -= 8192;
z -= 8192;
if (!(ext[3] & 0x02))
x *= 18;
else
x *= 9;
if (!(ext[4] & 0x02))
y *= 18;
else
y *= 9;
if (!(ext[3] & 0x01))
z *= 18;
else
z *= 9;
input_report_abs(wdata->mp, ABS_RX, x);
input_report_abs(wdata->mp, ABS_RY, y);
input_report_abs(wdata->mp, ABS_RZ, z);
input_sync(wdata->mp);
}
static int wiimod_mp_open(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.flags |= WIIPROTO_FLAG_MP_USED;
wiiproto_req_drm(wdata, WIIPROTO_REQ_NULL);
__wiimote_schedule(wdata);
spin_unlock_irqrestore(&wdata->state.lock, flags);
return 0;
}
static void wiimod_mp_close(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.flags &= ~WIIPROTO_FLAG_MP_USED;
wiiproto_req_drm(wdata, WIIPROTO_REQ_NULL);
__wiimote_schedule(wdata);
spin_unlock_irqrestore(&wdata->state.lock, flags);
}
static int wiimod_mp_probe(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
int ret;
wdata->mp = input_allocate_device();
if (!wdata->mp)
return -ENOMEM;
input_set_drvdata(wdata->mp, wdata);
wdata->mp->open = wiimod_mp_open;
wdata->mp->close = wiimod_mp_close;
wdata->mp->dev.parent = &wdata->hdev->dev;
wdata->mp->id.bustype = wdata->hdev->bus;
wdata->mp->id.vendor = wdata->hdev->vendor;
wdata->mp->id.product = wdata->hdev->product;
wdata->mp->id.version = wdata->hdev->version;
wdata->mp->name = WIIMOTE_NAME " Motion Plus";
set_bit(EV_ABS, wdata->mp->evbit);
set_bit(ABS_RX, wdata->mp->absbit);
set_bit(ABS_RY, wdata->mp->absbit);
set_bit(ABS_RZ, wdata->mp->absbit);
input_set_abs_params(wdata->mp,
ABS_RX, -16000, 16000, 4, 8);
input_set_abs_params(wdata->mp,
ABS_RY, -16000, 16000, 4, 8);
input_set_abs_params(wdata->mp,
ABS_RZ, -16000, 16000, 4, 8);
ret = input_register_device(wdata->mp);
if (ret)
goto err_free;
return 0;
err_free:
input_free_device(wdata->mp);
wdata->mp = NULL;
return ret;
}
static void wiimod_mp_remove(const struct wiimod_ops *ops,
struct wiimote_data *wdata)
{
if (!wdata->mp)
return;
input_unregister_device(wdata->mp);
wdata->mp = NULL;
}
