static int __hidpp_send_report(struct hid_device *hdev,
struct hidpp_report *hidpp_report)
{
int fields_count, ret;
switch (hidpp_report->report_id) {
case REPORT_ID_HIDPP_SHORT:
fields_count = HIDPP_REPORT_SHORT_LENGTH;
break;
case REPORT_ID_HIDPP_LONG:
fields_count = HIDPP_REPORT_LONG_LENGTH;
break;
default:
return -ENODEV;
}
hidpp_report->device_index = 0xff;
ret = hid_hw_raw_request(hdev, hidpp_report->report_id,
(u8 *)hidpp_report, fields_count, HID_OUTPUT_REPORT,
HID_REQ_SET_REPORT);
return ret == fields_count ? 0 : -1;
}
static int hidpp_send_message_sync(struct hidpp_device *hidpp,
struct hidpp_report *message,
struct hidpp_report *response)
{
int ret;
mutex_lock(&hidpp->send_mutex);
hidpp->send_receive_buf = response;
hidpp->answer_available = false;
*response = *message;
ret = __hidpp_send_report(hidpp->hid_dev, message);
if (ret) {
dbg_hid("__hidpp_send_report returned err: %d\n", ret);
memset(response, 0, sizeof(struct hidpp_report));
goto exit;
}
if (!wait_event_timeout(hidpp->wait, hidpp->answer_available,
5*HZ)) {
dbg_hid("%s:timeout waiting for response\n", __func__);
memset(response, 0, sizeof(struct hidpp_report));
ret = -ETIMEDOUT;
}
if (response->report_id == REPORT_ID_HIDPP_SHORT &&
response->fap.feature_index == HIDPP_ERROR) {
ret = response->fap.params[1];
dbg_hid("__hidpp_send_report got hidpp error %02X\n", ret);
goto exit;
}
exit:
mutex_unlock(&hidpp->send_mutex);
return ret;
}
static int hidpp_send_fap_command_sync(struct hidpp_device *hidpp,
u8 feat_index, u8 funcindex_clientid, u8 *params, int param_count,
struct hidpp_report *response)
{
struct hidpp_report *message;
int ret;
if (param_count > sizeof(message->fap.params))
return -EINVAL;
message = kzalloc(sizeof(struct hidpp_report), GFP_KERNEL);
if (!message)
return -ENOMEM;
message->report_id = REPORT_ID_HIDPP_LONG;
message->fap.feature_index = feat_index;
message->fap.funcindex_clientid = funcindex_clientid;
memcpy(&message->fap.params, params, param_count);
ret = hidpp_send_message_sync(hidpp, message, response);
kfree(message);
return ret;
}
static int hidpp_send_rap_command_sync(struct hidpp_device *hidpp_dev,
u8 report_id, u8 sub_id, u8 reg_address, u8 *params, int param_count,
struct hidpp_report *response)
{
struct hidpp_report *message;
int ret;
if ((report_id != REPORT_ID_HIDPP_SHORT) &&
(report_id != REPORT_ID_HIDPP_LONG))
return -EINVAL;
if (param_count > sizeof(message->rap.params))
return -EINVAL;
message = kzalloc(sizeof(struct hidpp_report), GFP_KERNEL);
if (!message)
return -ENOMEM;
message->report_id = report_id;
message->rap.sub_id = sub_id;
message->rap.reg_address = reg_address;
memcpy(&message->rap.params, params, param_count);
ret = hidpp_send_message_sync(hidpp_dev, message, response);
kfree(message);
return ret;
}
static void delayed_work_cb(struct work_struct *work)
{
struct hidpp_device *hidpp = container_of(work, struct hidpp_device,
work);
hidpp_connect_event(hidpp);
}
static inline bool hidpp_match_answer(struct hidpp_report *question,
struct hidpp_report *answer)
{
return (answer->fap.feature_index == question->fap.feature_index) &&
(answer->fap.funcindex_clientid == question->fap.funcindex_clientid);
}
static inline bool hidpp_match_error(struct hidpp_report *question,
struct hidpp_report *answer)
{
return (answer->fap.feature_index == HIDPP_ERROR) &&
(answer->fap.funcindex_clientid == question->fap.feature_index) &&
(answer->fap.params[0] == question->fap.funcindex_clientid);
}
static inline bool hidpp_report_is_connect_event(struct hidpp_report *report)
{
return (report->report_id == REPORT_ID_HIDPP_SHORT) &&
(report->rap.sub_id == 0x41);
}
static void hidpp_prefix_name(char **name, int name_length)
{
#define PREFIX_LENGTH 9
int new_length;
char *new_name;
if (name_length > PREFIX_LENGTH &&
strncmp(*name, "Logitech ", PREFIX_LENGTH) == 0)
return;
new_length = PREFIX_LENGTH + name_length;
new_name = kzalloc(new_length, GFP_KERNEL);
if (!new_name)
return;
snprintf(new_name, new_length, "Logitech %s", *name);
kfree(*name);
*name = new_name;
}
static char *hidpp_get_unifying_name(struct hidpp_device *hidpp_dev)
{
struct hidpp_report response;
int ret;
u8 params[1] = { DEVICE_NAME };
char *name;
int len;
ret = hidpp_send_rap_command_sync(hidpp_dev,
REPORT_ID_HIDPP_SHORT,
HIDPP_GET_LONG_REGISTER,
HIDPP_REG_PAIRING_INFORMATION,
params, 1, &response);
if (ret)
return NULL;
len = response.rap.params[1];
if (2 + len > sizeof(response.rap.params))
return NULL;
name = kzalloc(len + 1, GFP_KERNEL);
if (!name)
return NULL;
memcpy(name, &response.rap.params[2], len);
hidpp_prefix_name(&name, len + 1);
return name;
}
static int hidpp_root_get_feature(struct hidpp_device *hidpp, u16 feature,
u8 *feature_index, u8 *feature_type)
{
struct hidpp_report response;
int ret;
u8 params[2] = { feature >> 8, feature & 0x00FF };
ret = hidpp_send_fap_command_sync(hidpp,
HIDPP_PAGE_ROOT_IDX,
CMD_ROOT_GET_FEATURE,
params, 2, &response);
if (ret)
return ret;
*feature_index = response.fap.params[0];
*feature_type = response.fap.params[1];
return ret;
}
static int hidpp_root_get_protocol_version(struct hidpp_device *hidpp)
{
struct hidpp_report response;
int ret;
ret = hidpp_send_fap_command_sync(hidpp,
HIDPP_PAGE_ROOT_IDX,
CMD_ROOT_GET_PROTOCOL_VERSION,
NULL, 0, &response);
if (ret == HIDPP_ERROR_INVALID_SUBID) {
hidpp->protocol_major = 1;
hidpp->protocol_minor = 0;
return 0;
}
if (ret == HIDPP_ERROR_RESOURCE_ERROR)
return -EIO;
if (ret > 0) {
hid_err(hidpp->hid_dev, "%s: received protocol error 0x%02x\n",
__func__, ret);
return -EPROTO;
}
if (ret)
return ret;
hidpp->protocol_major = response.fap.params[0];
hidpp->protocol_minor = response.fap.params[1];
return ret;
}
static bool hidpp_is_connected(struct hidpp_device *hidpp)
{
int ret;
ret = hidpp_root_get_protocol_version(hidpp);
if (!ret)
hid_dbg(hidpp->hid_dev, "HID++ %u.%u device connected.\n",
hidpp->protocol_major, hidpp->protocol_minor);
return ret == 0;
}
static int hidpp_devicenametype_get_count(struct hidpp_device *hidpp,
u8 feature_index, u8 *nameLength)
{
struct hidpp_report response;
int ret;
ret = hidpp_send_fap_command_sync(hidpp, feature_index,
CMD_GET_DEVICE_NAME_TYPE_GET_COUNT, NULL, 0, &response);
if (ret > 0) {
hid_err(hidpp->hid_dev, "%s: received protocol error 0x%02x\n",
__func__, ret);
return -EPROTO;
}
if (ret)
return ret;
*nameLength = response.fap.params[0];
return ret;
}
static int hidpp_devicenametype_get_device_name(struct hidpp_device *hidpp,
u8 feature_index, u8 char_index, char *device_name, int len_buf)
{
struct hidpp_report response;
int ret, i;
int count;
ret = hidpp_send_fap_command_sync(hidpp, feature_index,
CMD_GET_DEVICE_NAME_TYPE_GET_DEVICE_NAME, &char_index, 1,
&response);
if (ret > 0) {
hid_err(hidpp->hid_dev, "%s: received protocol error 0x%02x\n",
__func__, ret);
return -EPROTO;
}
if (ret)
return ret;
if (response.report_id == REPORT_ID_HIDPP_LONG)
count = HIDPP_REPORT_LONG_LENGTH - 4;
else
count = HIDPP_REPORT_SHORT_LENGTH - 4;
if (len_buf < count)
count = len_buf;
for (i = 0; i < count; i++)
device_name[i] = response.fap.params[i];
return count;
}
static char *hidpp_get_device_name(struct hidpp_device *hidpp)
{
u8 feature_type;
u8 feature_index;
u8 __name_length;
char *name;
unsigned index = 0;
int ret;
ret = hidpp_root_get_feature(hidpp, HIDPP_PAGE_GET_DEVICE_NAME_TYPE,
&feature_index, &feature_type);
if (ret)
return NULL;
ret = hidpp_devicenametype_get_count(hidpp, feature_index,
&__name_length);
if (ret)
return NULL;
name = kzalloc(__name_length + 1, GFP_KERNEL);
if (!name)
return NULL;
while (index < __name_length) {
ret = hidpp_devicenametype_get_device_name(hidpp,
feature_index, index, name + index,
__name_length - index);
if (ret <= 0) {
kfree(name);
return NULL;
}
index += ret;
}
hidpp_prefix_name(&name, __name_length + 1);
return name;
}
static int hidpp_touchpad_get_raw_info(struct hidpp_device *hidpp,
u8 feature_index, struct hidpp_touchpad_raw_info *raw_info)
{
struct hidpp_report response;
int ret;
u8 *params = (u8 *)response.fap.params;
ret = hidpp_send_fap_command_sync(hidpp, feature_index,
CMD_TOUCHPAD_GET_RAW_INFO, NULL, 0, &response);
if (ret > 0) {
hid_err(hidpp->hid_dev, "%s: received protocol error 0x%02x\n",
__func__, ret);
return -EPROTO;
}
if (ret)
return ret;
raw_info->x_size = get_unaligned_be16(&params[0]);
raw_info->y_size = get_unaligned_be16(&params[2]);
raw_info->z_range = params[4];
raw_info->area_range = params[5];
raw_info->maxcontacts = params[7];
raw_info->origin = params[8];
raw_info->res = get_unaligned_be16(&params[13]) * 2 / 51;
return ret;
}
static int hidpp_touchpad_set_raw_report_state(struct hidpp_device *hidpp_dev,
u8 feature_index, bool send_raw_reports,
bool sensor_enhanced_settings)
{
struct hidpp_report response;
u8 params = send_raw_reports | (sensor_enhanced_settings << 2);
return hidpp_send_fap_command_sync(hidpp_dev, feature_index,
CMD_TOUCHPAD_SET_RAW_REPORT_STATE, &params, 1, &response);
}
static void hidpp_touchpad_touch_event(u8 *data,
struct hidpp_touchpad_raw_xy_finger *finger)
{
u8 x_m = data[0] << 2;
u8 y_m = data[2] << 2;
finger->x = x_m << 6 | data[1];
finger->y = y_m << 6 | data[3];
finger->contact_type = data[0] >> 6;
finger->contact_status = data[2] >> 6;
finger->z = data[4];
finger->area = data[5];
finger->finger_id = data[6] >> 4;
}
static void hidpp_touchpad_raw_xy_event(struct hidpp_device *hidpp_dev,
u8 *data, struct hidpp_touchpad_raw_xy *raw_xy)
{
memset(raw_xy, 0, sizeof(struct hidpp_touchpad_raw_xy));
raw_xy->end_of_frame = data[8] & 0x01;
raw_xy->spurious_flag = (data[8] >> 1) & 0x01;
raw_xy->finger_count = data[15] & 0x0f;
raw_xy->button = (data[8] >> 2) & 0x01;
if (raw_xy->finger_count) {
hidpp_touchpad_touch_event(&data[2], &raw_xy->fingers[0]);
hidpp_touchpad_touch_event(&data[9], &raw_xy->fingers[1]);
}
}
static int wtp_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
struct hidpp_device *hidpp = hid_get_drvdata(hdev);
if ((hidpp->quirks & HIDPP_QUIRK_MULTI_INPUT) &&
(field->application == HID_GD_KEYBOARD))
return 0;
return -1;
}
static void wtp_populate_input(struct hidpp_device *hidpp,
struct input_dev *input_dev, bool origin_is_hid_core)
{
struct wtp_data *wd = hidpp->private_data;
if ((hidpp->quirks & HIDPP_QUIRK_MULTI_INPUT) && origin_is_hid_core)
return;
__set_bit(EV_ABS, input_dev->evbit);
__set_bit(EV_KEY, input_dev->evbit);
__clear_bit(EV_REL, input_dev->evbit);
__clear_bit(EV_LED, input_dev->evbit);
input_set_abs_params(input_dev, ABS_MT_POSITION_X, 0, wd->x_size, 0, 0);
input_abs_set_res(input_dev, ABS_MT_POSITION_X, wd->resolution);
input_set_abs_params(input_dev, ABS_MT_POSITION_Y, 0, wd->y_size, 0, 0);
input_abs_set_res(input_dev, ABS_MT_POSITION_Y, wd->resolution);
input_set_abs_params(input_dev, ABS_MT_PRESSURE, 0, 50, 0, 0);
input_set_capability(input_dev, EV_KEY, BTN_LEFT);
if (hidpp->quirks & HIDPP_QUIRK_WTP_PHYSICAL_BUTTONS)
input_set_capability(input_dev, EV_KEY, BTN_RIGHT);
else
__set_bit(INPUT_PROP_BUTTONPAD, input_dev->propbit);
input_mt_init_slots(input_dev, wd->maxcontacts, INPUT_MT_POINTER |
INPUT_MT_DROP_UNUSED);
wd->input = input_dev;
}
static void wtp_touch_event(struct wtp_data *wd,
struct hidpp_touchpad_raw_xy_finger *touch_report)
{
int slot;
if (!touch_report->finger_id || touch_report->contact_type)
return;
slot = input_mt_get_slot_by_key(wd->input, touch_report->finger_id);
input_mt_slot(wd->input, slot);
input_mt_report_slot_state(wd->input, MT_TOOL_FINGER,
touch_report->contact_status);
if (touch_report->contact_status) {
input_event(wd->input, EV_ABS, ABS_MT_POSITION_X,
touch_report->x);
input_event(wd->input, EV_ABS, ABS_MT_POSITION_Y,
wd->flip_y ? wd->y_size - touch_report->y :
touch_report->y);
input_event(wd->input, EV_ABS, ABS_MT_PRESSURE,
touch_report->area);
}
}
static void wtp_send_raw_xy_event(struct hidpp_device *hidpp,
struct hidpp_touchpad_raw_xy *raw)
{
struct wtp_data *wd = hidpp->private_data;
int i;
for (i = 0; i < 2; i++)
wtp_touch_event(wd, &(raw->fingers[i]));
if (raw->end_of_frame &&
!(hidpp->quirks & HIDPP_QUIRK_WTP_PHYSICAL_BUTTONS))
input_event(wd->input, EV_KEY, BTN_LEFT, raw->button);
if (raw->end_of_frame || raw->finger_count <= 2) {
input_mt_sync_frame(wd->input);
input_sync(wd->input);
}
}
static int wtp_mouse_raw_xy_event(struct hidpp_device *hidpp, u8 *data)
{
struct wtp_data *wd = hidpp->private_data;
u8 c1_area = ((data[7] & 0xf) * (data[7] & 0xf) +
(data[7] >> 4) * (data[7] >> 4)) / 2;
u8 c2_area = ((data[13] & 0xf) * (data[13] & 0xf) +
(data[13] >> 4) * (data[13] >> 4)) / 2;
struct hidpp_touchpad_raw_xy raw = {
.timestamp = data[1],
.fingers = {
{
.contact_type = 0,
.contact_status = !!data[7],
.x = get_unaligned_le16(&data[3]),
.y = get_unaligned_le16(&data[5]),
.z = c1_area,
.area = c1_area,
.finger_id = data[2],
}, {
.contact_type = 0,
.contact_status = !!data[13],
.x = get_unaligned_le16(&data[9]),
.y = get_unaligned_le16(&data[11]),
.z = c2_area,
.area = c2_area,
.finger_id = data[8],
}
},
.finger_count = wd->maxcontacts,
.spurious_flag = 0,
.end_of_frame = (data[0] >> 7) == 0,
.button = data[0] & 0x01,
};
wtp_send_raw_xy_event(hidpp, &raw);
return 1;
}
static int wtp_raw_event(struct hid_device *hdev, u8 *data, int size)
{
struct hidpp_device *hidpp = hid_get_drvdata(hdev);
struct wtp_data *wd = hidpp->private_data;
struct hidpp_report *report = (struct hidpp_report *)data;
struct hidpp_touchpad_raw_xy raw;
if (!wd || !wd->input)
return 1;
switch (data[0]) {
case 0x02:
if (size < 2) {
hid_err(hdev, "Received HID report of bad size (%d)",
size);
return 1;
}
if (hidpp->quirks & HIDPP_QUIRK_WTP_PHYSICAL_BUTTONS) {
input_event(wd->input, EV_KEY, BTN_LEFT,
!!(data[1] & 0x01));
input_event(wd->input, EV_KEY, BTN_RIGHT,
!!(data[1] & 0x02));
input_sync(wd->input);
return 0;
} else {
if (size < 21)
return 1;
return wtp_mouse_raw_xy_event(hidpp, &data[7]);
}
case REPORT_ID_HIDPP_LONG:
if ((report->fap.feature_index != wd->mt_feature_index) ||
(report->fap.funcindex_clientid != EVENT_TOUCHPAD_RAW_XY))
return 1;
hidpp_touchpad_raw_xy_event(hidpp, data + 4, &raw);
wtp_send_raw_xy_event(hidpp, &raw);
return 0;
}
return 0;
}
static int wtp_get_config(struct hidpp_device *hidpp)
{
struct wtp_data *wd = hidpp->private_data;
struct hidpp_touchpad_raw_info raw_info = {0};
u8 feature_type;
int ret;
ret = hidpp_root_get_feature(hidpp, HIDPP_PAGE_TOUCHPAD_RAW_XY,
&wd->mt_feature_index, &feature_type);
if (ret)
return ret;
ret = hidpp_touchpad_get_raw_info(hidpp, wd->mt_feature_index,
&raw_info);
if (ret)
return ret;
wd->x_size = raw_info.x_size;
wd->y_size = raw_info.y_size;
wd->maxcontacts = raw_info.maxcontacts;
wd->flip_y = raw_info.origin == TOUCHPAD_RAW_XY_ORIGIN_LOWER_LEFT;
wd->resolution = raw_info.res;
if (!wd->resolution)
wd->resolution = WTP_MANUAL_RESOLUTION;
return 0;
}
static int wtp_allocate(struct hid_device *hdev, const struct hid_device_id *id)
{
struct hidpp_device *hidpp = hid_get_drvdata(hdev);
struct wtp_data *wd;
wd = devm_kzalloc(&hdev->dev, sizeof(struct wtp_data),
GFP_KERNEL);
if (!wd)
return -ENOMEM;
hidpp->private_data = wd;
return 0;
}
static void wtp_connect(struct hid_device *hdev, bool connected)
{
struct hidpp_device *hidpp = hid_get_drvdata(hdev);
struct wtp_data *wd = hidpp->private_data;
int ret;
if (!connected)
return;
if (!wd->x_size) {
ret = wtp_get_config(hidpp);
if (ret) {
hid_err(hdev, "Can not get wtp config: %d\n", ret);
return;
}
}
hidpp_touchpad_set_raw_report_state(hidpp, wd->mt_feature_index,
true, true);
}
static int hidpp_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
struct hidpp_device *hidpp = hid_get_drvdata(hdev);
if (hidpp->quirks & HIDPP_QUIRK_CLASS_WTP)
return wtp_input_mapping(hdev, hi, field, usage, bit, max);
return 0;
}
static void hidpp_populate_input(struct hidpp_device *hidpp,
struct input_dev *input, bool origin_is_hid_core)
{
if (hidpp->quirks & HIDPP_QUIRK_CLASS_WTP)
wtp_populate_input(hidpp, input, origin_is_hid_core);
}
static void hidpp_input_configured(struct hid_device *hdev,
struct hid_input *hidinput)
{
struct hidpp_device *hidpp = hid_get_drvdata(hdev);
struct input_dev *input = hidinput->input;
hidpp_populate_input(hidpp, input, true);
}
static int hidpp_raw_hidpp_event(struct hidpp_device *hidpp, u8 *data,
int size)
{
struct hidpp_report *question = hidpp->send_receive_buf;
struct hidpp_report *answer = hidpp->send_receive_buf;
struct hidpp_report *report = (struct hidpp_report *)data;
if (unlikely(mutex_is_locked(&hidpp->send_mutex))) {
if (hidpp_match_answer(question, report) ||
hidpp_match_error(question, report)) {
*answer = *report;
hidpp->answer_available = true;
wake_up(&hidpp->wait);
return 1;
}
}
if (unlikely(hidpp_report_is_connect_event(report))) {
atomic_set(&hidpp->connected,
!(report->rap.params[0] & (1 << 6)));
if ((hidpp->quirks & HIDPP_QUIRK_DELAYED_INIT) &&
(schedule_work(&hidpp->work) == 0))
dbg_hid("%s: connect event already queued\n", __func__);
return 1;
}
if (hidpp->quirks & HIDPP_QUIRK_CLASS_WTP)
return wtp_raw_event(hidpp->hid_dev, data, size);
return 0;
}
static int hidpp_raw_event(struct hid_device *hdev, struct hid_report *report,
u8 *data, int size)
{
struct hidpp_device *hidpp = hid_get_drvdata(hdev);
switch (data[0]) {
case REPORT_ID_HIDPP_LONG:
if (size != HIDPP_REPORT_LONG_LENGTH) {
hid_err(hdev, "received hid++ report of bad size (%d)",
size);
return 1;
}
return hidpp_raw_hidpp_event(hidpp, data, size);
case REPORT_ID_HIDPP_SHORT:
if (size != HIDPP_REPORT_SHORT_LENGTH) {
hid_err(hdev, "received hid++ report of bad size (%d)",
size);
return 1;
}
return hidpp_raw_hidpp_event(hidpp, data, size);
}
if (hidpp->quirks & HIDPP_QUIRK_CLASS_WTP)
return wtp_raw_event(hdev, data, size);
return 0;
}
static void hidpp_overwrite_name(struct hid_device *hdev, bool use_unifying)
{
struct hidpp_device *hidpp = hid_get_drvdata(hdev);
char *name;
if (use_unifying)
name = hidpp_get_unifying_name(hidpp);
else
name = hidpp_get_device_name(hidpp);
if (!name)
hid_err(hdev, "unable to retrieve the name of the device");
else
snprintf(hdev->name, sizeof(hdev->name), "%s", name);
kfree(name);
}
static int hidpp_input_open(struct input_dev *dev)
{
struct hid_device *hid = input_get_drvdata(dev);
return hid_hw_open(hid);
}
static void hidpp_input_close(struct input_dev *dev)
{
struct hid_device *hid = input_get_drvdata(dev);
hid_hw_close(hid);
}
static struct input_dev *hidpp_allocate_input(struct hid_device *hdev)
{
struct input_dev *input_dev = devm_input_allocate_device(&hdev->dev);
if (!input_dev)
return NULL;
input_set_drvdata(input_dev, hdev);
input_dev->open = hidpp_input_open;
input_dev->close = hidpp_input_close;
input_dev->name = hdev->name;
input_dev->phys = hdev->phys;
input_dev->uniq = hdev->uniq;
input_dev->id.bustype = hdev->bus;
input_dev->id.vendor = hdev->vendor;
input_dev->id.product = hdev->product;
input_dev->id.version = hdev->version;
input_dev->dev.parent = &hdev->dev;
return input_dev;
}
static void hidpp_connect_event(struct hidpp_device *hidpp)
{
struct hid_device *hdev = hidpp->hid_dev;
int ret = 0;
bool connected = atomic_read(&hidpp->connected);
struct input_dev *input;
char *name, *devm_name;
if (hidpp->quirks & HIDPP_QUIRK_CLASS_WTP)
wtp_connect(hdev, connected);
if (!connected || hidpp->delayed_input)
return;
if (!hidpp->protocol_major) {
ret = !hidpp_is_connected(hidpp);
if (ret) {
hid_err(hdev, "Can not get the protocol version.\n");
return;
}
}
hid_info(hdev, "HID++ %u.%u device connected.\n",
hidpp->protocol_major, hidpp->protocol_minor);
input = hidpp_allocate_input(hdev);
if (!input) {
hid_err(hdev, "cannot allocate new input device: %d\n", ret);
return;
}
name = hidpp_get_device_name(hidpp);
if (!name) {
hid_err(hdev, "unable to retrieve the name of the device");
} else {
devm_name = devm_kasprintf(&hdev->dev, GFP_KERNEL, "%s", name);
if (devm_name)
input->name = devm_name;
kfree(name);
}
hidpp_populate_input(hidpp, input, false);
ret = input_register_device(input);
if (ret)
input_free_device(input);
hidpp->delayed_input = input;
}
static int hidpp_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
struct hidpp_device *hidpp;
int ret;
bool connected;
unsigned int connect_mask = HID_CONNECT_DEFAULT;
hidpp = devm_kzalloc(&hdev->dev, sizeof(struct hidpp_device),
GFP_KERNEL);
if (!hidpp)
return -ENOMEM;
hidpp->hid_dev = hdev;
hid_set_drvdata(hdev, hidpp);
hidpp->quirks = id->driver_data;
if (hidpp->quirks & HIDPP_QUIRK_CLASS_WTP) {
ret = wtp_allocate(hdev, id);
if (ret)
goto wtp_allocate_fail;
}
INIT_WORK(&hidpp->work, delayed_work_cb);
mutex_init(&hidpp->send_mutex);
init_waitqueue_head(&hidpp->wait);
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "%s:parse failed\n", __func__);
goto hid_parse_fail;
}
hid_device_io_start(hdev);
connected = hidpp_is_connected(hidpp);
if (id->group != HID_GROUP_LOGITECH_DJ_DEVICE) {
if (!connected) {
hid_err(hdev, "Device not connected");
hid_device_io_stop(hdev);
goto hid_parse_fail;
}
hid_info(hdev, "HID++ %u.%u device connected.\n",
hidpp->protocol_major, hidpp->protocol_minor);
}
hidpp_overwrite_name(hdev, id->group == HID_GROUP_LOGITECH_DJ_DEVICE);
atomic_set(&hidpp->connected, connected);
if (connected && (hidpp->quirks & HIDPP_QUIRK_CLASS_WTP)) {
ret = wtp_get_config(hidpp);
if (ret)
goto hid_parse_fail;
}
hid_device_io_stop(hdev);
if (hidpp->quirks & HIDPP_QUIRK_DELAYED_INIT)
connect_mask &= ~HID_CONNECT_HIDINPUT;
if (hidpp->quirks & HIDPP_QUIRK_MULTI_INPUT)
connect_mask |= HID_CONNECT_HIDINPUT;
ret = hid_hw_start(hdev, connect_mask);
if (ret) {
hid_err(hdev, "%s:hid_hw_start returned error\n", __func__);
goto hid_hw_start_fail;
}
if (hidpp->quirks & HIDPP_QUIRK_DELAYED_INIT) {
hid_device_io_start(hdev);
hidpp_connect_event(hidpp);
}
return ret;
hid_hw_start_fail:
hid_parse_fail:
cancel_work_sync(&hidpp->work);
mutex_destroy(&hidpp->send_mutex);
wtp_allocate_fail:
hid_set_drvdata(hdev, NULL);
return ret;
}
static void hidpp_remove(struct hid_device *hdev)
{
struct hidpp_device *hidpp = hid_get_drvdata(hdev);
cancel_work_sync(&hidpp->work);
mutex_destroy(&hidpp->send_mutex);
hid_hw_stop(hdev);
}
