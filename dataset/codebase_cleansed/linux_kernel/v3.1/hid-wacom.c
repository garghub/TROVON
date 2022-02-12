static int wacom_battery_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct wacom_data *wdata = container_of(psy,
struct wacom_data, battery);
int power_state = batcap[wdata->battery_capacity];
int ret = 0;
switch (psp) {
case POWER_SUPPLY_PROP_PRESENT:
val->intval = 1;
break;
case POWER_SUPPLY_PROP_CAPACITY:
if (power_state == 0)
val->intval = 100;
else
val->intval = power_state;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int wacom_ac_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct wacom_data *wdata = container_of(psy, struct wacom_data, ac);
int power_state = batcap[wdata->battery_capacity];
int ret = 0;
switch (psp) {
case POWER_SUPPLY_PROP_PRESENT:
case POWER_SUPPLY_PROP_ONLINE:
if (power_state == 0)
val->intval = 1;
else
val->intval = 0;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static void wacom_poke(struct hid_device *hdev, u8 speed)
{
struct wacom_data *wdata = hid_get_drvdata(hdev);
int limit, ret;
char rep_data[2];
rep_data[0] = 0x03 ; rep_data[1] = 0x00;
limit = 3;
do {
ret = hdev->hid_output_raw_report(hdev, rep_data, 2,
HID_FEATURE_REPORT);
} while (ret < 0 && limit-- > 0);
if (ret >= 0) {
if (speed == 0)
rep_data[0] = 0x05;
else
rep_data[0] = 0x06;
rep_data[1] = 0x00;
limit = 3;
do {
ret = hdev->hid_output_raw_report(hdev, rep_data, 2,
HID_FEATURE_REPORT);
} while (ret < 0 && limit-- > 0);
if (ret >= 0) {
wdata->high_speed = speed;
return;
}
}
hid_warn(hdev, "failed to poke device, command %d, err %d\n",
rep_data[0], ret);
return;
}
static ssize_t wacom_show_speed(struct device *dev,
struct device_attribute
*attr, char *buf)
{
struct wacom_data *wdata = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%i\n", wdata->high_speed);
}
static ssize_t wacom_store_speed(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
int new_speed;
if (sscanf(buf, "%1d", &new_speed ) != 1)
return -EINVAL;
if (new_speed == 0 || new_speed == 1) {
wacom_poke(hdev, new_speed);
return strnlen(buf, PAGE_SIZE);
} else
return -EINVAL;
}
static int wacom_raw_event(struct hid_device *hdev, struct hid_report *report,
u8 *raw_data, int size)
{
struct wacom_data *wdata = hid_get_drvdata(hdev);
struct hid_input *hidinput;
struct input_dev *input;
unsigned char *data = (unsigned char *) raw_data;
int tool, x, y, rw;
if (!(hdev->claimed & HID_CLAIMED_INPUT))
return 0;
tool = 0;
hidinput = list_entry(hdev->inputs.next, struct hid_input, list);
input = hidinput->input;
if (data[0] != 0x03)
return 0;
x = le16_to_cpu(*(__le16 *) &data[2]);
y = le16_to_cpu(*(__le16 *) &data[4]);
if (data[1] & 0x90) {
switch ((data[1] >> 5) & 3) {
case 0:
tool = BTN_TOOL_PEN;
break;
case 1:
tool = BTN_TOOL_RUBBER;
break;
case 2:
case 3:
tool = BTN_TOOL_MOUSE;
break;
}
if (!(data[1] & 0x10))
tool = 0;
}
if (wdata->tool != tool) {
if (wdata->tool) {
if (wdata->tool == BTN_TOOL_MOUSE) {
input_report_key(input, BTN_LEFT, 0);
input_report_key(input, BTN_RIGHT, 0);
input_report_key(input, BTN_MIDDLE, 0);
input_report_abs(input, ABS_DISTANCE,
input_abs_get_max(input, ABS_DISTANCE));
} else {
input_report_key(input, BTN_TOUCH, 0);
input_report_key(input, BTN_STYLUS, 0);
input_report_key(input, BTN_STYLUS2, 0);
input_report_abs(input, ABS_PRESSURE, 0);
}
input_report_key(input, wdata->tool, 0);
input_sync(input);
}
wdata->tool = tool;
if (tool)
input_report_key(input, tool, 1);
}
if (tool) {
input_report_abs(input, ABS_X, x);
input_report_abs(input, ABS_Y, y);
switch ((data[1] >> 5) & 3) {
case 2:
input_report_key(input, BTN_MIDDLE, data[1] & 0x04);
rw = (data[6] & 0x01) ? -1 :
(data[6] & 0x02) ? 1 : 0;
input_report_rel(input, REL_WHEEL, rw);
case 3:
input_report_key(input, BTN_LEFT, data[1] & 0x01);
input_report_key(input, BTN_RIGHT, data[1] & 0x02);
rw = 44 - (data[6] >> 2);
if (rw < 0)
rw = 0;
else if (rw > 31)
rw = 31;
input_report_abs(input, ABS_DISTANCE, rw);
break;
default:
input_report_abs(input, ABS_PRESSURE,
data[6] | (((__u16) (data[1] & 0x08)) << 5));
input_report_key(input, BTN_TOUCH, data[1] & 0x01);
input_report_key(input, BTN_STYLUS, data[1] & 0x02);
input_report_key(input, BTN_STYLUS2, (tool == BTN_TOOL_PEN) && data[1] & 0x04);
break;
}
input_sync(input);
}
rw = data[7] & 0x03;
if (rw != wdata->butstate) {
wdata->butstate = rw;
input_report_key(input, BTN_0, rw & 0x02);
input_report_key(input, BTN_1, rw & 0x01);
input_report_key(input, BTN_TOOL_FINGER, 0xf0);
input_event(input, EV_MSC, MSC_SERIAL, 0xf0);
input_sync(input);
}
#ifdef CONFIG_HID_WACOM_POWER_SUPPLY
rw = (data[7] >> 2 & 0x07);
if (rw != wdata->battery_capacity)
wdata->battery_capacity = rw;
#endif
return 1;
}
static int wacom_probe(struct hid_device *hdev,
const struct hid_device_id *id)
{
struct hid_input *hidinput;
struct input_dev *input;
struct wacom_data *wdata;
int ret;
wdata = kzalloc(sizeof(*wdata), GFP_KERNEL);
if (wdata == NULL) {
hid_err(hdev, "can't alloc wacom descriptor\n");
return -ENOMEM;
}
hid_set_drvdata(hdev, wdata);
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
goto err_free;
}
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (ret) {
hid_err(hdev, "hw start failed\n");
goto err_free;
}
ret = device_create_file(&hdev->dev, &dev_attr_speed);
if (ret)
hid_warn(hdev,
"can't create sysfs speed attribute err: %d\n", ret);
wacom_poke(hdev, 1);
#ifdef CONFIG_HID_WACOM_POWER_SUPPLY
wdata->battery.properties = wacom_battery_props;
wdata->battery.num_properties = ARRAY_SIZE(wacom_battery_props);
wdata->battery.get_property = wacom_battery_get_property;
wdata->battery.name = "wacom_battery";
wdata->battery.type = POWER_SUPPLY_TYPE_BATTERY;
wdata->battery.use_for_apm = 0;
ret = power_supply_register(&hdev->dev, &wdata->battery);
if (ret) {
hid_warn(hdev, "can't create sysfs battery attribute, err: %d\n",
ret);
goto err_battery;
}
wdata->ac.properties = wacom_ac_props;
wdata->ac.num_properties = ARRAY_SIZE(wacom_ac_props);
wdata->ac.get_property = wacom_ac_get_property;
wdata->ac.name = "wacom_ac";
wdata->ac.type = POWER_SUPPLY_TYPE_MAINS;
wdata->ac.use_for_apm = 0;
ret = power_supply_register(&hdev->dev, &wdata->ac);
if (ret) {
hid_warn(hdev,
"can't create ac battery attribute, err: %d\n", ret);
goto err_ac;
}
#endif
hidinput = list_entry(hdev->inputs.next, struct hid_input, list);
input = hidinput->input;
__set_bit(INPUT_PROP_POINTER, input->propbit);
input->evbit[0] |= BIT(EV_KEY) | BIT(EV_ABS) | BIT(EV_REL);
__set_bit(REL_WHEEL, input->relbit);
__set_bit(BTN_TOOL_PEN, input->keybit);
__set_bit(BTN_TOUCH, input->keybit);
__set_bit(BTN_STYLUS, input->keybit);
__set_bit(BTN_STYLUS2, input->keybit);
__set_bit(BTN_LEFT, input->keybit);
__set_bit(BTN_RIGHT, input->keybit);
__set_bit(BTN_MIDDLE, input->keybit);
input->evbit[0] |= BIT(EV_MSC);
__set_bit(MSC_SERIAL, input->mscbit);
__set_bit(BTN_0, input->keybit);
__set_bit(BTN_1, input->keybit);
__set_bit(BTN_TOOL_FINGER, input->keybit);
__set_bit(BTN_TOOL_RUBBER, input->keybit);
__set_bit(BTN_TOOL_MOUSE, input->keybit);
input_set_abs_params(input, ABS_X, 0, 16704, 4, 0);
input_set_abs_params(input, ABS_Y, 0, 12064, 4, 0);
input_set_abs_params(input, ABS_PRESSURE, 0, 511, 0, 0);
input_set_abs_params(input, ABS_DISTANCE, 0, 32, 0, 0);
return 0;
#ifdef CONFIG_HID_WACOM_POWER_SUPPLY
err_ac:
power_supply_unregister(&wdata->battery);
err_battery:
device_remove_file(&hdev->dev, &dev_attr_speed);
hid_hw_stop(hdev);
#endif
err_free:
kfree(wdata);
return ret;
}
static void wacom_remove(struct hid_device *hdev)
{
#ifdef CONFIG_HID_WACOM_POWER_SUPPLY
struct wacom_data *wdata = hid_get_drvdata(hdev);
#endif
device_remove_file(&hdev->dev, &dev_attr_speed);
hid_hw_stop(hdev);
#ifdef CONFIG_HID_WACOM_POWER_SUPPLY
power_supply_unregister(&wdata->battery);
power_supply_unregister(&wdata->ac);
#endif
kfree(hid_get_drvdata(hdev));
}
static int __init wacom_init(void)
{
int ret;
ret = hid_register_driver(&wacom_driver);
if (ret)
pr_err("can't register wacom driver\n");
return ret;
}
static void __exit wacom_exit(void)
{
hid_unregister_driver(&wacom_driver);
}
