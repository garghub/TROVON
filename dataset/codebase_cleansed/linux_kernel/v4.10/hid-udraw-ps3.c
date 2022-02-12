static int clamp_accel(int axis, int offset)
{
axis = clamp(axis,
accel_limits[offset].min,
accel_limits[offset].max);
axis = (axis - accel_limits[offset].min) /
((accel_limits[offset].max -
accel_limits[offset].min) * 0xFF);
return axis;
}
static int udraw_raw_event(struct hid_device *hdev, struct hid_report *report,
u8 *data, int len)
{
struct udraw *udraw = hid_get_drvdata(hdev);
int touch;
int x, y, z;
if (len != 27)
return 0;
if (data[11] == 0x00)
touch = TOUCH_NONE;
else if (data[11] == 0x40)
touch = TOUCH_PEN;
else if (data[11] == 0x80)
touch = TOUCH_FINGER;
else
touch = TOUCH_TWOFINGER;
input_report_key(udraw->joy_input_dev, BTN_WEST, data[0] & 1);
input_report_key(udraw->joy_input_dev, BTN_SOUTH, !!(data[0] & 2));
input_report_key(udraw->joy_input_dev, BTN_EAST, !!(data[0] & 4));
input_report_key(udraw->joy_input_dev, BTN_NORTH, !!(data[0] & 8));
input_report_key(udraw->joy_input_dev, BTN_SELECT, !!(data[1] & 1));
input_report_key(udraw->joy_input_dev, BTN_START, !!(data[1] & 2));
input_report_key(udraw->joy_input_dev, BTN_MODE, !!(data[1] & 16));
x = y = 0;
switch (data[2]) {
case 0x0:
y = -127;
break;
case 0x1:
y = -127;
x = 127;
break;
case 0x2:
x = 127;
break;
case 0x3:
y = 127;
x = 127;
break;
case 0x4:
y = 127;
break;
case 0x5:
y = 127;
x = -127;
break;
case 0x6:
x = -127;
break;
case 0x7:
y = -127;
x = -127;
break;
default:
break;
}
input_report_abs(udraw->joy_input_dev, ABS_X, x);
input_report_abs(udraw->joy_input_dev, ABS_Y, y);
input_sync(udraw->joy_input_dev);
x = y = 0;
if (touch != TOUCH_NONE) {
if (data[15] != 0x0F)
x = data[15] * 256 + data[17];
if (data[16] != 0x0F)
y = data[16] * 256 + data[18];
}
if (touch == TOUCH_FINGER) {
udraw->last_one_finger_x = x;
udraw->last_one_finger_y = y;
udraw->last_two_finger_x = -1;
udraw->last_two_finger_y = -1;
} else if (touch == TOUCH_TWOFINGER) {
if (udraw->last_two_finger_x == -1) {
udraw->last_two_finger_x = x;
udraw->last_two_finger_y = y;
x = udraw->last_one_finger_x;
y = udraw->last_one_finger_y;
} else {
x = x - (udraw->last_two_finger_x
- udraw->last_one_finger_x);
y = y - (udraw->last_two_finger_y
- udraw->last_one_finger_y);
}
}
if (touch == TOUCH_FINGER || touch == TOUCH_TWOFINGER) {
input_report_key(udraw->touch_input_dev, BTN_TOUCH, 1);
input_report_key(udraw->touch_input_dev, BTN_TOOL_FINGER,
touch == TOUCH_FINGER);
input_report_key(udraw->touch_input_dev, BTN_TOOL_DOUBLETAP,
touch == TOUCH_TWOFINGER);
input_report_abs(udraw->touch_input_dev, ABS_X, x);
input_report_abs(udraw->touch_input_dev, ABS_Y, y);
} else {
input_report_key(udraw->touch_input_dev, BTN_TOUCH, 0);
input_report_key(udraw->touch_input_dev, BTN_TOOL_FINGER, 0);
input_report_key(udraw->touch_input_dev, BTN_TOOL_DOUBLETAP, 0);
}
input_sync(udraw->touch_input_dev);
if (touch == TOUCH_PEN) {
int level;
level = clamp(data[13] - PRESSURE_OFFSET,
0, MAX_PRESSURE);
input_report_key(udraw->pen_input_dev, BTN_TOUCH, (level != 0));
input_report_key(udraw->pen_input_dev, BTN_TOOL_PEN, 1);
input_report_abs(udraw->pen_input_dev, ABS_PRESSURE, level);
input_report_abs(udraw->pen_input_dev, ABS_X, x);
input_report_abs(udraw->pen_input_dev, ABS_Y, y);
} else {
input_report_key(udraw->pen_input_dev, BTN_TOUCH, 0);
input_report_key(udraw->pen_input_dev, BTN_TOOL_PEN, 0);
input_report_abs(udraw->pen_input_dev, ABS_PRESSURE, 0);
}
input_sync(udraw->pen_input_dev);
x = (data[19] + (data[20] << 8));
x = clamp_accel(x, AXIS_X);
y = (data[21] + (data[22] << 8));
y = clamp_accel(y, AXIS_Y);
z = (data[23] + (data[24] << 8));
z = clamp_accel(z, AXIS_Z);
input_report_abs(udraw->accel_input_dev, ABS_X, x);
input_report_abs(udraw->accel_input_dev, ABS_Y, y);
input_report_abs(udraw->accel_input_dev, ABS_Z, z);
input_sync(udraw->accel_input_dev);
return 0;
}
static int udraw_open(struct input_dev *dev)
{
struct udraw *udraw = input_get_drvdata(dev);
return hid_hw_open(udraw->hdev);
}
static void udraw_close(struct input_dev *dev)
{
struct udraw *udraw = input_get_drvdata(dev);
hid_hw_close(udraw->hdev);
}
static struct input_dev *allocate_and_setup(struct hid_device *hdev,
const char *name)
{
struct input_dev *input_dev;
input_dev = devm_input_allocate_device(&hdev->dev);
if (!input_dev)
return NULL;
input_dev->name = name;
input_dev->phys = hdev->phys;
input_dev->dev.parent = &hdev->dev;
input_dev->open = udraw_open;
input_dev->close = udraw_close;
input_dev->uniq = hdev->uniq;
input_dev->id.bustype = hdev->bus;
input_dev->id.vendor = hdev->vendor;
input_dev->id.product = hdev->product;
input_dev->id.version = hdev->version;
input_set_drvdata(input_dev, hid_get_drvdata(hdev));
return input_dev;
}
static bool udraw_setup_touch(struct udraw *udraw,
struct hid_device *hdev)
{
struct input_dev *input_dev;
input_dev = allocate_and_setup(hdev, DEVICE_NAME " Touchpad");
if (!input_dev)
return false;
input_dev->evbit[0] = BIT(EV_ABS) | BIT(EV_KEY);
input_set_abs_params(input_dev, ABS_X, 0, RES_X, 1, 0);
input_abs_set_res(input_dev, ABS_X, RES_X / WIDTH);
input_set_abs_params(input_dev, ABS_Y, 0, RES_Y, 1, 0);
input_abs_set_res(input_dev, ABS_Y, RES_Y / HEIGHT);
set_bit(BTN_TOUCH, input_dev->keybit);
set_bit(BTN_TOOL_FINGER, input_dev->keybit);
set_bit(BTN_TOOL_DOUBLETAP, input_dev->keybit);
set_bit(INPUT_PROP_POINTER, input_dev->propbit);
udraw->touch_input_dev = input_dev;
return true;
}
static bool udraw_setup_pen(struct udraw *udraw,
struct hid_device *hdev)
{
struct input_dev *input_dev;
input_dev = allocate_and_setup(hdev, DEVICE_NAME " Pen");
if (!input_dev)
return false;
input_dev->evbit[0] = BIT(EV_ABS) | BIT(EV_KEY);
input_set_abs_params(input_dev, ABS_X, 0, RES_X, 1, 0);
input_abs_set_res(input_dev, ABS_X, RES_X / WIDTH);
input_set_abs_params(input_dev, ABS_Y, 0, RES_Y, 1, 0);
input_abs_set_res(input_dev, ABS_Y, RES_Y / HEIGHT);
input_set_abs_params(input_dev, ABS_PRESSURE,
0, MAX_PRESSURE, 0, 0);
set_bit(BTN_TOUCH, input_dev->keybit);
set_bit(BTN_TOOL_PEN, input_dev->keybit);
set_bit(INPUT_PROP_POINTER, input_dev->propbit);
udraw->pen_input_dev = input_dev;
return true;
}
static bool udraw_setup_accel(struct udraw *udraw,
struct hid_device *hdev)
{
struct input_dev *input_dev;
input_dev = allocate_and_setup(hdev, DEVICE_NAME " Accelerometer");
if (!input_dev)
return false;
input_dev->evbit[0] = BIT(EV_ABS);
input_set_abs_params(input_dev, ABS_X, -512, 512, 0, 0);
input_set_abs_params(input_dev, ABS_Y, -512, 512, 0, 0);
input_set_abs_params(input_dev, ABS_Z, -512, 512, 0, 0);
set_bit(INPUT_PROP_ACCELEROMETER, input_dev->propbit);
udraw->accel_input_dev = input_dev;
return true;
}
static bool udraw_setup_joypad(struct udraw *udraw,
struct hid_device *hdev)
{
struct input_dev *input_dev;
input_dev = allocate_and_setup(hdev, DEVICE_NAME " Joypad");
if (!input_dev)
return false;
input_dev->evbit[0] = BIT(EV_KEY) | BIT(EV_ABS);
set_bit(BTN_SOUTH, input_dev->keybit);
set_bit(BTN_NORTH, input_dev->keybit);
set_bit(BTN_EAST, input_dev->keybit);
set_bit(BTN_WEST, input_dev->keybit);
set_bit(BTN_SELECT, input_dev->keybit);
set_bit(BTN_START, input_dev->keybit);
set_bit(BTN_MODE, input_dev->keybit);
input_set_abs_params(input_dev, ABS_X, -127, 127, 0, 0);
input_set_abs_params(input_dev, ABS_Y, -127, 127, 0, 0);
udraw->joy_input_dev = input_dev;
return true;
}
static int udraw_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
struct udraw *udraw;
int ret;
udraw = devm_kzalloc(&hdev->dev, sizeof(struct udraw), GFP_KERNEL);
if (!udraw)
return -ENOMEM;
udraw->hdev = hdev;
udraw->last_two_finger_x = -1;
udraw->last_two_finger_y = -1;
hid_set_drvdata(hdev, udraw);
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
return ret;
}
if (!udraw_setup_joypad(udraw, hdev) ||
!udraw_setup_touch(udraw, hdev) ||
!udraw_setup_pen(udraw, hdev) ||
!udraw_setup_accel(udraw, hdev)) {
hid_err(hdev, "could not allocate interfaces\n");
return -ENOMEM;
}
ret = input_register_device(udraw->joy_input_dev) ||
input_register_device(udraw->touch_input_dev) ||
input_register_device(udraw->pen_input_dev) ||
input_register_device(udraw->accel_input_dev);
if (ret) {
hid_err(hdev, "failed to register interfaces\n");
return ret;
}
ret = hid_hw_start(hdev, HID_CONNECT_HIDRAW | HID_CONNECT_DRIVER);
if (ret) {
hid_err(hdev, "hw start failed\n");
return ret;
}
return 0;
}
