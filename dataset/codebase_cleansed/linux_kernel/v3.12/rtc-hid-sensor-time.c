static int hid_time_proc_event(struct hid_sensor_hub_device *hsdev,
unsigned usage_id, void *priv)
{
unsigned long flags;
struct hid_time_state *time_state = platform_get_drvdata(priv);
spin_lock_irqsave(&time_state->lock_last_time, flags);
time_state->last_time = time_state->time_buf;
spin_unlock_irqrestore(&time_state->lock_last_time, flags);
complete(&time_state->comp_last_time);
return 0;
}
static u32 hid_time_value(size_t raw_len, char *raw_data)
{
switch (raw_len) {
case 1:
return *(u8 *)raw_data;
case 2:
return *(u16 *)raw_data;
case 4:
return *(u32 *)raw_data;
default:
return (u32)(~0U);
}
}
static int hid_time_capture_sample(struct hid_sensor_hub_device *hsdev,
unsigned usage_id, size_t raw_len,
char *raw_data, void *priv)
{
struct hid_time_state *time_state = platform_get_drvdata(priv);
struct rtc_time *time_buf = &time_state->time_buf;
switch (usage_id) {
case HID_USAGE_SENSOR_TIME_YEAR:
if (raw_len == 1) {
time_buf->tm_year = *(u8 *)raw_data;
if (time_buf->tm_year < 70)
time_buf->tm_year += 100;
} else
time_buf->tm_year =
(int)hid_time_value(raw_len, raw_data)-1900;
break;
case HID_USAGE_SENSOR_TIME_MONTH:
time_buf->tm_mon = (int)hid_time_value(raw_len, raw_data)-1;
break;
case HID_USAGE_SENSOR_TIME_DAY:
time_buf->tm_mday = (int)hid_time_value(raw_len, raw_data);
break;
case HID_USAGE_SENSOR_TIME_HOUR:
time_buf->tm_hour = (int)hid_time_value(raw_len, raw_data);
break;
case HID_USAGE_SENSOR_TIME_MINUTE:
time_buf->tm_min = (int)hid_time_value(raw_len, raw_data);
break;
case HID_USAGE_SENSOR_TIME_SECOND:
time_buf->tm_sec = (int)hid_time_value(raw_len, raw_data);
break;
default:
return -EINVAL;
}
return 0;
}
static const char *hid_time_attrib_name(u32 attrib_id)
{
static const char unknown[] = "unknown";
unsigned i;
for (i = 0; i < TIME_RTC_CHANNEL_MAX; ++i) {
if (hid_time_addresses[i] == attrib_id)
return hid_time_channel_names[i];
}
return unknown;
}
static int hid_time_parse_report(struct platform_device *pdev,
struct hid_sensor_hub_device *hsdev,
unsigned usage_id,
struct hid_time_state *time_state)
{
int report_id, i;
for (i = 0; i < TIME_RTC_CHANNEL_MAX; ++i)
if (sensor_hub_input_get_attribute_info(hsdev,
HID_INPUT_REPORT, usage_id,
hid_time_addresses[i],
&time_state->info[i]) < 0)
return -EINVAL;
report_id = time_state->info[0].report_id;
if (report_id < 0) {
dev_err(&pdev->dev, "bad report ID!\n");
return -EINVAL;
}
for (i = 0; i < TIME_RTC_CHANNEL_MAX; ++i) {
if (time_state->info[i].report_id != report_id) {
dev_err(&pdev->dev,
"not all needed attributes inside the same report!\n");
return -EINVAL;
}
if (time_state->info[i].size == 3 ||
time_state->info[i].size > 4) {
dev_err(&pdev->dev,
"attribute '%s' not 8, 16 or 32 bits wide!\n",
hid_time_attrib_name(
time_state->info[i].attrib_id));
return -EINVAL;
}
if (time_state->info[i].units !=
HID_USAGE_SENSOR_UNITS_NOT_SPECIFIED &&
!(time_state->info[i].attrib_id ==
HID_USAGE_SENSOR_TIME_SECOND &&
time_state->info[i].units ==
HID_USAGE_SENSOR_UNITS_SECOND)) {
dev_err(&pdev->dev,
"attribute '%s' hasn't a unit of type 'none'!\n",
hid_time_attrib_name(
time_state->info[i].attrib_id));
return -EINVAL;
}
if (time_state->info[i].unit_expo) {
dev_err(&pdev->dev,
"attribute '%s' hasn't a unit exponent of 1!\n",
hid_time_attrib_name(
time_state->info[i].attrib_id));
return -EINVAL;
}
}
return 0;
}
static int hid_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
unsigned long flags;
struct hid_time_state *time_state =
platform_get_drvdata(to_platform_device(dev));
int ret;
INIT_COMPLETION(time_state->comp_last_time);
sensor_hub_input_attr_get_raw_value(time_state->common_attributes.hsdev,
HID_USAGE_SENSOR_TIME, hid_time_addresses[0],
time_state->info[0].report_id);
ret = wait_for_completion_killable_timeout(
&time_state->comp_last_time, HZ*6);
if (ret > 0) {
spin_lock_irqsave(&time_state->lock_last_time, flags);
*tm = time_state->last_time;
spin_unlock_irqrestore(&time_state->lock_last_time, flags);
return 0;
}
if (!ret)
return -EIO;
return ret;
}
static int hid_time_probe(struct platform_device *pdev)
{
int ret = 0;
struct hid_sensor_hub_device *hsdev = pdev->dev.platform_data;
struct hid_time_state *time_state = devm_kzalloc(&pdev->dev,
sizeof(struct hid_time_state), GFP_KERNEL);
if (time_state == NULL)
return -ENOMEM;
platform_set_drvdata(pdev, time_state);
spin_lock_init(&time_state->lock_last_time);
init_completion(&time_state->comp_last_time);
time_state->common_attributes.hsdev = hsdev;
time_state->common_attributes.pdev = pdev;
ret = hid_sensor_parse_common_attributes(hsdev,
HID_USAGE_SENSOR_TIME,
&time_state->common_attributes);
if (ret) {
dev_err(&pdev->dev, "failed to setup common attributes!\n");
return ret;
}
ret = hid_time_parse_report(pdev, hsdev, HID_USAGE_SENSOR_TIME,
time_state);
if (ret) {
dev_err(&pdev->dev, "failed to setup attributes!\n");
return ret;
}
time_state->callbacks.send_event = hid_time_proc_event;
time_state->callbacks.capture_sample = hid_time_capture_sample;
time_state->callbacks.pdev = pdev;
ret = sensor_hub_register_callback(hsdev, HID_USAGE_SENSOR_TIME,
&time_state->callbacks);
if (ret < 0) {
dev_err(&pdev->dev, "register callback failed!\n");
return ret;
}
time_state->rtc = devm_rtc_device_register(&pdev->dev,
"hid-sensor-time", &hid_time_rtc_ops,
THIS_MODULE);
if (IS_ERR_OR_NULL(time_state->rtc)) {
ret = time_state->rtc ? PTR_ERR(time_state->rtc) : -ENODEV;
time_state->rtc = NULL;
sensor_hub_remove_callback(hsdev, HID_USAGE_SENSOR_TIME);
dev_err(&pdev->dev, "rtc device register failed!\n");
}
return ret;
}
static int hid_time_remove(struct platform_device *pdev)
{
struct hid_sensor_hub_device *hsdev = pdev->dev.platform_data;
sensor_hub_remove_callback(hsdev, HID_USAGE_SENSOR_TIME);
return 0;
}
