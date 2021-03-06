static int param_set_scroll_speed(const char *val, struct kernel_param *kp) {
unsigned long speed;
if (!val || strict_strtoul(val, 0, &speed) || speed > 63)
return -EINVAL;
scroll_speed = speed;
return 0;
}
static int magicmouse_firm_touch(struct magicmouse_sc *msc)
{
int touch = -1;
int ii;
for (ii = 0; ii < msc->ntouches; ii++) {
int idx = msc->tracking_ids[ii];
if (msc->touches[idx].size < 8) {
} else if (touch >= 0) {
touch = -1;
break;
} else {
touch = idx;
}
}
return touch;
}
static void magicmouse_emit_buttons(struct magicmouse_sc *msc, int state)
{
int last_state = test_bit(BTN_LEFT, msc->input->key) << 0 |
test_bit(BTN_RIGHT, msc->input->key) << 1 |
test_bit(BTN_MIDDLE, msc->input->key) << 2;
if (emulate_3button) {
int id;
if (state == 0) {
} else if (last_state != 0) {
state = last_state;
} else if ((id = magicmouse_firm_touch(msc)) >= 0) {
int x = msc->touches[id].x;
if (x < middle_button_start)
state = 1;
else if (x > middle_button_stop)
state = 2;
else
state = 4;
}
input_report_key(msc->input, BTN_MIDDLE, state & 4);
}
input_report_key(msc->input, BTN_LEFT, state & 1);
input_report_key(msc->input, BTN_RIGHT, state & 2);
if (state != last_state)
msc->scroll_accel = SCROLL_ACCEL_DEFAULT;
}
static void magicmouse_emit_touch(struct magicmouse_sc *msc, int raw_id, u8 *tdata)
{
struct input_dev *input = msc->input;
int id, x, y, size, orientation, touch_major, touch_minor, state, down;
if (input->id.product == USB_DEVICE_ID_APPLE_MAGICMOUSE) {
id = (tdata[6] << 2 | tdata[5] >> 6) & 0xf;
x = (tdata[1] << 28 | tdata[0] << 20) >> 20;
y = -((tdata[2] << 24 | tdata[1] << 16) >> 20);
size = tdata[5] & 0x3f;
orientation = (tdata[6] >> 2) - 32;
touch_major = tdata[3];
touch_minor = tdata[4];
state = tdata[7] & TOUCH_STATE_MASK;
down = state != TOUCH_STATE_NONE;
} else {
id = (tdata[7] << 2 | tdata[6] >> 6) & 0xf;
x = (tdata[1] << 27 | tdata[0] << 19) >> 19;
y = -((tdata[3] << 30 | tdata[2] << 22 | tdata[1] << 14) >> 19);
size = tdata[6] & 0x3f;
orientation = (tdata[7] >> 2) - 32;
touch_major = tdata[4];
touch_minor = tdata[5];
state = tdata[8] & TOUCH_STATE_MASK;
down = state != TOUCH_STATE_NONE;
}
msc->tracking_ids[raw_id] = id;
msc->touches[id].x = x;
msc->touches[id].y = y;
msc->touches[id].size = size;
if (emulate_scroll_wheel) {
unsigned long now = jiffies;
int step_x = msc->touches[id].scroll_x - x;
int step_y = msc->touches[id].scroll_y - y;
switch (state) {
case TOUCH_STATE_START:
msc->touches[id].scroll_x = x;
msc->touches[id].scroll_y = y;
if (scroll_acceleration && time_before(now,
msc->scroll_jiffies + HZ / 2))
msc->scroll_accel = max_t(int,
msc->scroll_accel - 1, 1);
else
msc->scroll_accel = SCROLL_ACCEL_DEFAULT;
break;
case TOUCH_STATE_DRAG:
step_x /= (64 - (int)scroll_speed) * msc->scroll_accel;
if (step_x != 0) {
msc->touches[id].scroll_x -= step_x *
(64 - scroll_speed) * msc->scroll_accel;
msc->scroll_jiffies = now;
input_report_rel(input, REL_HWHEEL, -step_x);
}
step_y /= (64 - (int)scroll_speed) * msc->scroll_accel;
if (step_y != 0) {
msc->touches[id].scroll_y -= step_y *
(64 - scroll_speed) * msc->scroll_accel;
msc->scroll_jiffies = now;
input_report_rel(input, REL_WHEEL, step_y);
}
break;
}
}
if (down) {
msc->ntouches++;
if (msc->single_touch_id == NO_TOUCHES)
msc->single_touch_id = id;
} else if (msc->single_touch_id == id)
msc->single_touch_id = SINGLE_TOUCH_UP;
if (report_touches && down) {
input_report_abs(input, ABS_MT_TRACKING_ID, id);
input_report_abs(input, ABS_MT_TOUCH_MAJOR, touch_major << 2);
input_report_abs(input, ABS_MT_TOUCH_MINOR, touch_minor << 2);
input_report_abs(input, ABS_MT_ORIENTATION, -orientation);
input_report_abs(input, ABS_MT_POSITION_X, x);
input_report_abs(input, ABS_MT_POSITION_Y, y);
if (report_undeciphered) {
if (input->id.product == USB_DEVICE_ID_APPLE_MAGICMOUSE)
input_event(input, EV_MSC, MSC_RAW, tdata[7]);
else
input_event(input, EV_MSC, MSC_RAW, tdata[8]);
}
input_mt_sync(input);
}
}
static int magicmouse_raw_event(struct hid_device *hdev,
struct hid_report *report, u8 *data, int size)
{
struct magicmouse_sc *msc = hid_get_drvdata(hdev);
struct input_dev *input = msc->input;
int x = 0, y = 0, ii, clicks = 0, npoints;
switch (data[0]) {
case TRACKPAD_REPORT_ID:
if (size < 4 || ((size - 4) % 9) != 0)
return 0;
npoints = (size - 4) / 9;
msc->ntouches = 0;
for (ii = 0; ii < npoints; ii++)
magicmouse_emit_touch(msc, ii, data + ii * 9 + 4);
if (msc->ntouches == 0)
msc->single_touch_id = NO_TOUCHES;
clicks = data[1];
break;
case MOUSE_REPORT_ID:
if (size < 6 || ((size - 6) % 8) != 0)
return 0;
npoints = (size - 6) / 8;
msc->ntouches = 0;
for (ii = 0; ii < npoints; ii++)
magicmouse_emit_touch(msc, ii, data + ii * 8 + 6);
if (report_touches && msc->ntouches == 0)
input_mt_sync(input);
x = (int)(((data[3] & 0x0c) << 28) | (data[1] << 22)) >> 22;
y = (int)(((data[3] & 0x30) << 26) | (data[2] << 22)) >> 22;
clicks = data[3];
break;
case DOUBLE_REPORT_ID:
magicmouse_raw_event(hdev, report, data + 2, data[1]);
magicmouse_raw_event(hdev, report, data + 2 + data[1],
size - 2 - data[1]);
break;
default:
return 0;
}
if (input->id.product == USB_DEVICE_ID_APPLE_MAGICMOUSE) {
magicmouse_emit_buttons(msc, clicks & 3);
input_report_rel(input, REL_X, x);
input_report_rel(input, REL_Y, y);
} else {
input_report_key(input, BTN_MOUSE, clicks & 1);
input_report_key(input, BTN_TOUCH, msc->ntouches > 0);
input_report_key(input, BTN_TOOL_FINGER, msc->ntouches == 1);
input_report_key(input, BTN_TOOL_DOUBLETAP, msc->ntouches == 2);
input_report_key(input, BTN_TOOL_TRIPLETAP, msc->ntouches == 3);
input_report_key(input, BTN_TOOL_QUADTAP, msc->ntouches == 4);
if (msc->single_touch_id >= 0) {
input_report_abs(input, ABS_X,
msc->touches[msc->single_touch_id].x);
input_report_abs(input, ABS_Y,
msc->touches[msc->single_touch_id].y);
}
}
input_sync(input);
return 1;
}
static void magicmouse_setup_input(struct input_dev *input, struct hid_device *hdev)
{
__set_bit(EV_KEY, input->evbit);
if (input->id.product == USB_DEVICE_ID_APPLE_MAGICMOUSE) {
__set_bit(BTN_LEFT, input->keybit);
__set_bit(BTN_RIGHT, input->keybit);
if (emulate_3button)
__set_bit(BTN_MIDDLE, input->keybit);
__set_bit(EV_REL, input->evbit);
__set_bit(REL_X, input->relbit);
__set_bit(REL_Y, input->relbit);
if (emulate_scroll_wheel) {
__set_bit(REL_WHEEL, input->relbit);
__set_bit(REL_HWHEEL, input->relbit);
}
} else {
__set_bit(BTN_MOUSE, input->keybit);
__set_bit(BTN_TOOL_FINGER, input->keybit);
__set_bit(BTN_TOOL_DOUBLETAP, input->keybit);
__set_bit(BTN_TOOL_TRIPLETAP, input->keybit);
__set_bit(BTN_TOOL_QUADTAP, input->keybit);
__set_bit(BTN_TOUCH, input->keybit);
}
if (report_touches) {
__set_bit(EV_ABS, input->evbit);
input_set_abs_params(input, ABS_MT_TRACKING_ID, 0, 15, 0, 0);
input_set_abs_params(input, ABS_MT_TOUCH_MAJOR, 0, 255, 4, 0);
input_set_abs_params(input, ABS_MT_TOUCH_MINOR, 0, 255, 4, 0);
input_set_abs_params(input, ABS_MT_ORIENTATION, -31, 32, 1, 0);
if (input->id.product == USB_DEVICE_ID_APPLE_MAGICMOUSE) {
input_set_abs_params(input, ABS_MT_POSITION_X, -1100,
1358, 4, 0);
input_set_abs_params(input, ABS_MT_POSITION_Y, -1589,
2047, 4, 0);
} else {
input_set_abs_params(input, ABS_X, -2909, 3167, 4, 0);
input_set_abs_params(input, ABS_Y, -2456, 2565, 4, 0);
input_set_abs_params(input, ABS_MT_POSITION_X, -2909,
3167, 4, 0);
input_set_abs_params(input, ABS_MT_POSITION_Y, -2456,
2565, 4, 0);
}
input_set_events_per_packet(input, 60);
}
if (report_undeciphered) {
__set_bit(EV_MSC, input->evbit);
__set_bit(MSC_RAW, input->mscbit);
}
}
static int magicmouse_input_mapping(struct hid_device *hdev,
struct hid_input *hi, struct hid_field *field,
struct hid_usage *usage, unsigned long **bit, int *max)
{
struct magicmouse_sc *msc = hid_get_drvdata(hdev);
if (!msc->input)
msc->input = hi->input;
if (hi->input->id.product == USB_DEVICE_ID_APPLE_MAGICTRACKPAD &&
field->flags & HID_MAIN_ITEM_RELATIVE)
return -1;
return 0;
}
static int magicmouse_probe(struct hid_device *hdev,
const struct hid_device_id *id)
{
__u8 feature[] = { 0xd7, 0x01 };
struct magicmouse_sc *msc;
struct hid_report *report;
int ret;
msc = kzalloc(sizeof(*msc), GFP_KERNEL);
if (msc == NULL) {
hid_err(hdev, "can't alloc magicmouse descriptor\n");
return -ENOMEM;
}
msc->scroll_accel = SCROLL_ACCEL_DEFAULT;
msc->quirks = id->driver_data;
hid_set_drvdata(hdev, msc);
msc->single_touch_id = NO_TOUCHES;
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "magicmouse hid parse failed\n");
goto err_free;
}
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (ret) {
hid_err(hdev, "magicmouse hw start failed\n");
goto err_free;
}
if (msc->input)
magicmouse_setup_input(msc->input, hdev);
if (id->product == USB_DEVICE_ID_APPLE_MAGICMOUSE)
report = hid_register_report(hdev, HID_INPUT_REPORT,
MOUSE_REPORT_ID);
else {
report = hid_register_report(hdev, HID_INPUT_REPORT,
TRACKPAD_REPORT_ID);
report = hid_register_report(hdev, HID_INPUT_REPORT,
DOUBLE_REPORT_ID);
}
if (!report) {
hid_err(hdev, "unable to register touch report\n");
ret = -ENOMEM;
goto err_stop_hw;
}
report->size = 6;
ret = hdev->hid_output_raw_report(hdev, feature, sizeof(feature),
HID_FEATURE_REPORT);
if (ret != sizeof(feature)) {
hid_err(hdev, "unable to request touch data (%d)\n", ret);
goto err_stop_hw;
}
return 0;
err_stop_hw:
hid_hw_stop(hdev);
err_free:
kfree(msc);
return ret;
}
static void magicmouse_remove(struct hid_device *hdev)
{
struct magicmouse_sc *msc = hid_get_drvdata(hdev);
hid_hw_stop(hdev);
kfree(msc);
}
static int __init magicmouse_init(void)
{
int ret;
ret = hid_register_driver(&magicmouse_driver);
if (ret)
pr_err("can't register magicmouse driver\n");
return ret;
}
static void __exit magicmouse_exit(void)
{
hid_unregister_driver(&magicmouse_driver);
}
