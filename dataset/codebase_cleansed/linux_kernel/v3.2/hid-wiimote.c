static inline bool wiimote_cmd_pending(struct wiimote_data *wdata, int cmd,
__u32 opt)
{
return wdata->state.cmd == cmd && wdata->state.opt == opt;
}
static inline void wiimote_cmd_complete(struct wiimote_data *wdata)
{
wdata->state.cmd = WIIPROTO_REQ_NULL;
complete(&wdata->state.ready);
}
static inline int wiimote_cmd_acquire(struct wiimote_data *wdata)
{
return mutex_lock_interruptible(&wdata->state.sync) ? -ERESTARTSYS : 0;
}
static inline void wiimote_cmd_set(struct wiimote_data *wdata, int cmd,
__u32 opt)
{
INIT_COMPLETION(wdata->state.ready);
wdata->state.cmd = cmd;
wdata->state.opt = opt;
}
static inline void wiimote_cmd_release(struct wiimote_data *wdata)
{
mutex_unlock(&wdata->state.sync);
}
static inline int wiimote_cmd_wait(struct wiimote_data *wdata)
{
int ret;
ret = wait_for_completion_interruptible_timeout(&wdata->state.ready, HZ);
if (ret < 0)
return -ERESTARTSYS;
else if (ret == 0)
return -EIO;
else
return 0;
}
static ssize_t wiimote_hid_send(struct hid_device *hdev, __u8 *buffer,
size_t count)
{
__u8 *buf;
ssize_t ret;
if (!hdev->hid_output_raw_report)
return -ENODEV;
buf = kmemdup(buffer, count, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = hdev->hid_output_raw_report(hdev, buf, count, HID_OUTPUT_REPORT);
kfree(buf);
return ret;
}
static void wiimote_worker(struct work_struct *work)
{
struct wiimote_data *wdata = container_of(work, struct wiimote_data,
worker);
unsigned long flags;
spin_lock_irqsave(&wdata->qlock, flags);
while (wdata->head != wdata->tail) {
spin_unlock_irqrestore(&wdata->qlock, flags);
wiimote_hid_send(wdata->hdev, wdata->outq[wdata->tail].data,
wdata->outq[wdata->tail].size);
spin_lock_irqsave(&wdata->qlock, flags);
wdata->tail = (wdata->tail + 1) % WIIMOTE_BUFSIZE;
}
spin_unlock_irqrestore(&wdata->qlock, flags);
}
static void wiimote_queue(struct wiimote_data *wdata, const __u8 *buffer,
size_t count)
{
unsigned long flags;
__u8 newhead;
if (count > HID_MAX_BUFFER_SIZE) {
hid_warn(wdata->hdev, "Sending too large output report\n");
return;
}
spin_lock_irqsave(&wdata->qlock, flags);
memcpy(wdata->outq[wdata->head].data, buffer, count);
wdata->outq[wdata->head].size = count;
newhead = (wdata->head + 1) % WIIMOTE_BUFSIZE;
if (wdata->head == wdata->tail) {
wdata->head = newhead;
schedule_work(&wdata->worker);
} else if (newhead != wdata->tail) {
wdata->head = newhead;
} else {
hid_warn(wdata->hdev, "Output queue is full");
}
spin_unlock_irqrestore(&wdata->qlock, flags);
}
static inline void wiiproto_keep_rumble(struct wiimote_data *wdata, __u8 *cmd1)
{
if (wdata->state.flags & WIIPROTO_FLAG_RUMBLE)
*cmd1 |= 0x01;
}
static void wiiproto_req_rumble(struct wiimote_data *wdata, __u8 rumble)
{
__u8 cmd[2];
rumble = !!rumble;
if (rumble == !!(wdata->state.flags & WIIPROTO_FLAG_RUMBLE))
return;
if (rumble)
wdata->state.flags |= WIIPROTO_FLAG_RUMBLE;
else
wdata->state.flags &= ~WIIPROTO_FLAG_RUMBLE;
cmd[0] = WIIPROTO_REQ_RUMBLE;
cmd[1] = 0;
wiiproto_keep_rumble(wdata, &cmd[1]);
wiimote_queue(wdata, cmd, sizeof(cmd));
}
static void wiiproto_req_leds(struct wiimote_data *wdata, int leds)
{
__u8 cmd[2];
leds &= WIIPROTO_FLAGS_LEDS;
if ((wdata->state.flags & WIIPROTO_FLAGS_LEDS) == leds)
return;
wdata->state.flags = (wdata->state.flags & ~WIIPROTO_FLAGS_LEDS) | leds;
cmd[0] = WIIPROTO_REQ_LED;
cmd[1] = 0;
if (leds & WIIPROTO_FLAG_LED1)
cmd[1] |= 0x10;
if (leds & WIIPROTO_FLAG_LED2)
cmd[1] |= 0x20;
if (leds & WIIPROTO_FLAG_LED3)
cmd[1] |= 0x40;
if (leds & WIIPROTO_FLAG_LED4)
cmd[1] |= 0x80;
wiiproto_keep_rumble(wdata, &cmd[1]);
wiimote_queue(wdata, cmd, sizeof(cmd));
}
static __u8 select_drm(struct wiimote_data *wdata)
{
__u8 ir = wdata->state.flags & WIIPROTO_FLAGS_IR;
if (ir == WIIPROTO_FLAG_IR_BASIC) {
if (wdata->state.flags & WIIPROTO_FLAG_ACCEL)
return WIIPROTO_REQ_DRM_KAIE;
else
return WIIPROTO_REQ_DRM_KIE;
} else if (ir == WIIPROTO_FLAG_IR_EXT) {
return WIIPROTO_REQ_DRM_KAI;
} else if (ir == WIIPROTO_FLAG_IR_FULL) {
return WIIPROTO_REQ_DRM_SKAI1;
} else {
if (wdata->state.flags & WIIPROTO_FLAG_ACCEL)
return WIIPROTO_REQ_DRM_KA;
else
return WIIPROTO_REQ_DRM_K;
}
}
static void wiiproto_req_drm(struct wiimote_data *wdata, __u8 drm)
{
__u8 cmd[3];
if (drm == WIIPROTO_REQ_NULL)
drm = select_drm(wdata);
cmd[0] = WIIPROTO_REQ_DRM;
cmd[1] = 0;
cmd[2] = drm;
wiiproto_keep_rumble(wdata, &cmd[1]);
wiimote_queue(wdata, cmd, sizeof(cmd));
}
static void wiiproto_req_status(struct wiimote_data *wdata)
{
__u8 cmd[2];
cmd[0] = WIIPROTO_REQ_SREQ;
cmd[1] = 0;
wiiproto_keep_rumble(wdata, &cmd[1]);
wiimote_queue(wdata, cmd, sizeof(cmd));
}
static void wiiproto_req_accel(struct wiimote_data *wdata, __u8 accel)
{
accel = !!accel;
if (accel == !!(wdata->state.flags & WIIPROTO_FLAG_ACCEL))
return;
if (accel)
wdata->state.flags |= WIIPROTO_FLAG_ACCEL;
else
wdata->state.flags &= ~WIIPROTO_FLAG_ACCEL;
wiiproto_req_drm(wdata, WIIPROTO_REQ_NULL);
}
static void wiiproto_req_ir1(struct wiimote_data *wdata, __u8 flags)
{
__u8 cmd[2];
cmd[0] = WIIPROTO_REQ_IR1;
cmd[1] = flags;
wiiproto_keep_rumble(wdata, &cmd[1]);
wiimote_queue(wdata, cmd, sizeof(cmd));
}
static void wiiproto_req_ir2(struct wiimote_data *wdata, __u8 flags)
{
__u8 cmd[2];
cmd[0] = WIIPROTO_REQ_IR2;
cmd[1] = flags;
wiiproto_keep_rumble(wdata, &cmd[1]);
wiimote_queue(wdata, cmd, sizeof(cmd));
}
static void wiiproto_req_wmem(struct wiimote_data *wdata, bool eeprom,
__u32 offset, const __u8 *buf, __u8 size)
{
__u8 cmd[22];
if (size > 16 || size == 0) {
hid_warn(wdata->hdev, "Invalid length %d wmem request\n", size);
return;
}
memset(cmd, 0, sizeof(cmd));
cmd[0] = WIIPROTO_REQ_WMEM;
cmd[2] = (offset >> 16) & 0xff;
cmd[3] = (offset >> 8) & 0xff;
cmd[4] = offset & 0xff;
cmd[5] = size;
memcpy(&cmd[6], buf, size);
if (!eeprom)
cmd[1] |= 0x04;
wiiproto_keep_rumble(wdata, &cmd[1]);
wiimote_queue(wdata, cmd, sizeof(cmd));
}
static int wiimote_cmd_write(struct wiimote_data *wdata, __u32 offset,
const __u8 *wmem, __u8 size)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&wdata->state.lock, flags);
wiimote_cmd_set(wdata, WIIPROTO_REQ_WMEM, 0);
wiiproto_req_wreg(wdata, offset, wmem, size);
spin_unlock_irqrestore(&wdata->state.lock, flags);
ret = wiimote_cmd_wait(wdata);
if (!ret && wdata->state.cmd_err)
ret = -EIO;
return ret;
}
static int wiimote_battery_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct wiimote_data *wdata = container_of(psy,
struct wiimote_data, battery);
int ret = 0, state;
unsigned long flags;
ret = wiimote_cmd_acquire(wdata);
if (ret)
return ret;
spin_lock_irqsave(&wdata->state.lock, flags);
wiimote_cmd_set(wdata, WIIPROTO_REQ_SREQ, 0);
wiiproto_req_status(wdata);
spin_unlock_irqrestore(&wdata->state.lock, flags);
ret = wiimote_cmd_wait(wdata);
state = wdata->state.cmd_battery;
wiimote_cmd_release(wdata);
if (ret)
return ret;
switch (psp) {
case POWER_SUPPLY_PROP_CAPACITY:
val->intval = state * 100 / 255;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int wiimote_init_ir(struct wiimote_data *wdata, __u16 mode)
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
static enum led_brightness wiimote_leds_get(struct led_classdev *led_dev)
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
static void wiimote_leds_set(struct led_classdev *led_dev,
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
static int wiimote_ff_play(struct input_dev *dev, void *data,
struct ff_effect *eff)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
__u8 value;
unsigned long flags;
if (eff->u.rumble.strong_magnitude || eff->u.rumble.weak_magnitude)
value = 1;
else
value = 0;
spin_lock_irqsave(&wdata->state.lock, flags);
wiiproto_req_rumble(wdata, value);
spin_unlock_irqrestore(&wdata->state.lock, flags);
return 0;
}
static int wiimote_input_open(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
return hid_hw_open(wdata->hdev);
}
static void wiimote_input_close(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
hid_hw_close(wdata->hdev);
}
static int wiimote_accel_open(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
int ret;
unsigned long flags;
ret = hid_hw_open(wdata->hdev);
if (ret)
return ret;
spin_lock_irqsave(&wdata->state.lock, flags);
wiiproto_req_accel(wdata, true);
spin_unlock_irqrestore(&wdata->state.lock, flags);
return 0;
}
static void wiimote_accel_close(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
wiiproto_req_accel(wdata, false);
spin_unlock_irqrestore(&wdata->state.lock, flags);
hid_hw_close(wdata->hdev);
}
static int wiimote_ir_open(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
int ret;
ret = hid_hw_open(wdata->hdev);
if (ret)
return ret;
ret = wiimote_init_ir(wdata, WIIPROTO_FLAG_IR_BASIC);
if (ret) {
hid_hw_close(wdata->hdev);
return ret;
}
return 0;
}
static void wiimote_ir_close(struct input_dev *dev)
{
struct wiimote_data *wdata = input_get_drvdata(dev);
wiimote_init_ir(wdata, 0);
hid_hw_close(wdata->hdev);
}
static void handler_keys(struct wiimote_data *wdata, const __u8 *payload)
{
input_report_key(wdata->input, wiiproto_keymap[WIIPROTO_KEY_LEFT],
!!(payload[0] & 0x01));
input_report_key(wdata->input, wiiproto_keymap[WIIPROTO_KEY_RIGHT],
!!(payload[0] & 0x02));
input_report_key(wdata->input, wiiproto_keymap[WIIPROTO_KEY_DOWN],
!!(payload[0] & 0x04));
input_report_key(wdata->input, wiiproto_keymap[WIIPROTO_KEY_UP],
!!(payload[0] & 0x08));
input_report_key(wdata->input, wiiproto_keymap[WIIPROTO_KEY_PLUS],
!!(payload[0] & 0x10));
input_report_key(wdata->input, wiiproto_keymap[WIIPROTO_KEY_TWO],
!!(payload[1] & 0x01));
input_report_key(wdata->input, wiiproto_keymap[WIIPROTO_KEY_ONE],
!!(payload[1] & 0x02));
input_report_key(wdata->input, wiiproto_keymap[WIIPROTO_KEY_B],
!!(payload[1] & 0x04));
input_report_key(wdata->input, wiiproto_keymap[WIIPROTO_KEY_A],
!!(payload[1] & 0x08));
input_report_key(wdata->input, wiiproto_keymap[WIIPROTO_KEY_MINUS],
!!(payload[1] & 0x10));
input_report_key(wdata->input, wiiproto_keymap[WIIPROTO_KEY_HOME],
!!(payload[1] & 0x80));
input_sync(wdata->input);
}
static void handler_accel(struct wiimote_data *wdata, const __u8 *payload)
{
__u16 x, y, z;
if (!(wdata->state.flags & WIIPROTO_FLAG_ACCEL))
return;
x = payload[2] << 2;
y = payload[3] << 2;
z = payload[4] << 2;
x |= (payload[0] >> 5) & 0x3;
y |= (payload[1] >> 4) & 0x2;
z |= (payload[1] >> 5) & 0x2;
input_report_abs(wdata->accel, ABS_RX, x - 0x200);
input_report_abs(wdata->accel, ABS_RY, y - 0x200);
input_report_abs(wdata->accel, ABS_RZ, z - 0x200);
input_sync(wdata->accel);
}
static void __ir_to_input(struct wiimote_data *wdata, const __u8 *ir,
bool packed, __u8 xid, __u8 yid)
{
__u16 x, y;
if (!(wdata->state.flags & WIIPROTO_FLAGS_IR))
return;
if (packed) {
x = ir[1] << 2;
y = ir[2] << 2;
x |= ir[0] & 0x3;
y |= (ir[0] >> 2) & 0x3;
} else {
x = ir[0] << 2;
y = ir[1] << 2;
x |= (ir[2] >> 4) & 0x3;
y |= (ir[2] >> 6) & 0x3;
}
input_report_abs(wdata->ir, xid, x);
input_report_abs(wdata->ir, yid, y);
}
static void handler_status(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
wiiproto_req_drm(wdata, WIIPROTO_REQ_NULL);
if (wiimote_cmd_pending(wdata, WIIPROTO_REQ_SREQ, 0)) {
wdata->state.cmd_battery = payload[5];
wiimote_cmd_complete(wdata);
}
}
static void handler_data(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
}
static void handler_return(struct wiimote_data *wdata, const __u8 *payload)
{
__u8 err = payload[3];
__u8 cmd = payload[2];
handler_keys(wdata, payload);
if (wiimote_cmd_pending(wdata, cmd, 0)) {
wdata->state.cmd_err = err;
wiimote_cmd_complete(wdata);
} else if (err) {
hid_warn(wdata->hdev, "Remote error %hhu on req %hhu\n", err,
cmd);
}
}
static void handler_drm_KA(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
handler_accel(wdata, payload);
}
static void handler_drm_KE(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
}
static void handler_drm_KAI(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
handler_accel(wdata, payload);
ir_to_input0(wdata, &payload[5], false);
ir_to_input1(wdata, &payload[8], false);
ir_to_input2(wdata, &payload[11], false);
ir_to_input3(wdata, &payload[14], false);
input_sync(wdata->ir);
}
static void handler_drm_KEE(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
}
static void handler_drm_KIE(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
ir_to_input0(wdata, &payload[2], false);
ir_to_input1(wdata, &payload[4], true);
ir_to_input2(wdata, &payload[7], false);
ir_to_input3(wdata, &payload[9], true);
input_sync(wdata->ir);
}
static void handler_drm_KAE(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
handler_accel(wdata, payload);
}
static void handler_drm_KAIE(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
handler_accel(wdata, payload);
ir_to_input0(wdata, &payload[5], false);
ir_to_input1(wdata, &payload[7], true);
ir_to_input2(wdata, &payload[10], false);
ir_to_input3(wdata, &payload[12], true);
input_sync(wdata->ir);
}
static void handler_drm_E(struct wiimote_data *wdata, const __u8 *payload)
{
}
static void handler_drm_SKAI1(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
wdata->state.accel_split[0] = payload[2];
wdata->state.accel_split[1] = (payload[0] >> 1) & (0x10 | 0x20);
wdata->state.accel_split[1] |= (payload[1] << 1) & (0x40 | 0x80);
ir_to_input0(wdata, &payload[3], false);
ir_to_input1(wdata, &payload[12], false);
input_sync(wdata->ir);
}
static void handler_drm_SKAI2(struct wiimote_data *wdata, const __u8 *payload)
{
__u8 buf[5];
handler_keys(wdata, payload);
wdata->state.accel_split[1] |= (payload[0] >> 5) & (0x01 | 0x02);
wdata->state.accel_split[1] |= (payload[1] >> 3) & (0x04 | 0x08);
buf[0] = 0;
buf[1] = 0;
buf[2] = wdata->state.accel_split[0];
buf[3] = payload[2];
buf[4] = wdata->state.accel_split[1];
handler_accel(wdata, buf);
ir_to_input2(wdata, &payload[3], false);
ir_to_input3(wdata, &payload[12], false);
input_sync(wdata->ir);
}
static int wiimote_hid_event(struct hid_device *hdev, struct hid_report *report,
u8 *raw_data, int size)
{
struct wiimote_data *wdata = hid_get_drvdata(hdev);
struct wiiproto_handler *h;
int i;
unsigned long flags;
bool handled = false;
if (size < 1)
return -EINVAL;
spin_lock_irqsave(&wdata->state.lock, flags);
for (i = 0; handlers[i].id; ++i) {
h = &handlers[i];
if (h->id == raw_data[0] && h->size < size) {
h->func(wdata, &raw_data[1]);
handled = true;
}
}
if (!handled)
hid_warn(hdev, "Unhandled report %hhu size %d\n", raw_data[0],
size);
spin_unlock_irqrestore(&wdata->state.lock, flags);
return 0;
}
static void wiimote_leds_destroy(struct wiimote_data *wdata)
{
int i;
struct led_classdev *led;
for (i = 0; i < 4; ++i) {
if (wdata->leds[i]) {
led = wdata->leds[i];
wdata->leds[i] = NULL;
led_classdev_unregister(led);
kfree(led);
}
}
}
static int wiimote_leds_create(struct wiimote_data *wdata)
{
int i, ret;
struct device *dev = &wdata->hdev->dev;
size_t namesz = strlen(dev_name(dev)) + 9;
struct led_classdev *led;
char *name;
for (i = 0; i < 4; ++i) {
led = kzalloc(sizeof(struct led_classdev) + namesz, GFP_KERNEL);
if (!led) {
ret = -ENOMEM;
goto err;
}
name = (void*)&led[1];
snprintf(name, namesz, "%s:blue:p%d", dev_name(dev), i);
led->name = name;
led->brightness = 0;
led->max_brightness = 1;
led->brightness_get = wiimote_leds_get;
led->brightness_set = wiimote_leds_set;
ret = led_classdev_register(dev, led);
if (ret) {
kfree(led);
goto err;
}
wdata->leds[i] = led;
}
return 0;
err:
wiimote_leds_destroy(wdata);
return ret;
}
static struct wiimote_data *wiimote_create(struct hid_device *hdev)
{
struct wiimote_data *wdata;
int i;
wdata = kzalloc(sizeof(*wdata), GFP_KERNEL);
if (!wdata)
return NULL;
wdata->input = input_allocate_device();
if (!wdata->input)
goto err;
wdata->hdev = hdev;
hid_set_drvdata(hdev, wdata);
input_set_drvdata(wdata->input, wdata);
wdata->input->open = wiimote_input_open;
wdata->input->close = wiimote_input_close;
wdata->input->dev.parent = &wdata->hdev->dev;
wdata->input->id.bustype = wdata->hdev->bus;
wdata->input->id.vendor = wdata->hdev->vendor;
wdata->input->id.product = wdata->hdev->product;
wdata->input->id.version = wdata->hdev->version;
wdata->input->name = WIIMOTE_NAME;
set_bit(EV_KEY, wdata->input->evbit);
for (i = 0; i < WIIPROTO_KEY_COUNT; ++i)
set_bit(wiiproto_keymap[i], wdata->input->keybit);
set_bit(FF_RUMBLE, wdata->input->ffbit);
if (input_ff_create_memless(wdata->input, NULL, wiimote_ff_play))
goto err_input;
wdata->accel = input_allocate_device();
if (!wdata->accel)
goto err_input;
input_set_drvdata(wdata->accel, wdata);
wdata->accel->open = wiimote_accel_open;
wdata->accel->close = wiimote_accel_close;
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
wdata->ir = input_allocate_device();
if (!wdata->ir)
goto err_ir;
input_set_drvdata(wdata->ir, wdata);
wdata->ir->open = wiimote_ir_open;
wdata->ir->close = wiimote_ir_close;
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
spin_lock_init(&wdata->qlock);
INIT_WORK(&wdata->worker, wiimote_worker);
spin_lock_init(&wdata->state.lock);
init_completion(&wdata->state.ready);
mutex_init(&wdata->state.sync);
return wdata;
err_ir:
input_free_device(wdata->accel);
err_input:
input_free_device(wdata->input);
err:
kfree(wdata);
return NULL;
}
static void wiimote_destroy(struct wiimote_data *wdata)
{
wiimote_leds_destroy(wdata);
power_supply_unregister(&wdata->battery);
input_unregister_device(wdata->accel);
input_unregister_device(wdata->ir);
input_unregister_device(wdata->input);
cancel_work_sync(&wdata->worker);
hid_hw_stop(wdata->hdev);
kfree(wdata);
}
static int wiimote_hid_probe(struct hid_device *hdev,
const struct hid_device_id *id)
{
struct wiimote_data *wdata;
int ret;
wdata = wiimote_create(hdev);
if (!wdata) {
hid_err(hdev, "Can't alloc device\n");
return -ENOMEM;
}
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "HID parse failed\n");
goto err;
}
ret = hid_hw_start(hdev, HID_CONNECT_HIDRAW);
if (ret) {
hid_err(hdev, "HW start failed\n");
goto err;
}
ret = input_register_device(wdata->accel);
if (ret) {
hid_err(hdev, "Cannot register input device\n");
goto err_stop;
}
ret = input_register_device(wdata->ir);
if (ret) {
hid_err(hdev, "Cannot register input device\n");
goto err_ir;
}
ret = input_register_device(wdata->input);
if (ret) {
hid_err(hdev, "Cannot register input device\n");
goto err_input;
}
wdata->battery.properties = wiimote_battery_props;
wdata->battery.num_properties = ARRAY_SIZE(wiimote_battery_props);
wdata->battery.get_property = wiimote_battery_get_property;
wdata->battery.name = "wiimote_battery";
wdata->battery.type = POWER_SUPPLY_TYPE_BATTERY;
wdata->battery.use_for_apm = 0;
ret = power_supply_register(&wdata->hdev->dev, &wdata->battery);
if (ret) {
hid_err(hdev, "Cannot register battery device\n");
goto err_battery;
}
ret = wiimote_leds_create(wdata);
if (ret)
goto err_free;
hid_info(hdev, "New device registered\n");
spin_lock_irq(&wdata->state.lock);
wiiproto_req_leds(wdata, WIIPROTO_FLAG_LED1);
spin_unlock_irq(&wdata->state.lock);
return 0;
err_free:
wiimote_destroy(wdata);
return ret;
err_battery:
input_unregister_device(wdata->input);
wdata->input = NULL;
err_input:
input_unregister_device(wdata->ir);
wdata->ir = NULL;
err_ir:
input_unregister_device(wdata->accel);
wdata->accel = NULL;
err_stop:
hid_hw_stop(hdev);
err:
input_free_device(wdata->ir);
input_free_device(wdata->accel);
input_free_device(wdata->input);
kfree(wdata);
return ret;
}
static void wiimote_hid_remove(struct hid_device *hdev)
{
struct wiimote_data *wdata = hid_get_drvdata(hdev);
hid_info(hdev, "Device removed\n");
wiimote_destroy(wdata);
}
static int __init wiimote_init(void)
{
int ret;
ret = hid_register_driver(&wiimote_hid_driver);
if (ret)
pr_err("Can't register wiimote hid driver\n");
return ret;
}
static void __exit wiimote_exit(void)
{
hid_unregister_driver(&wiimote_hid_driver);
}
