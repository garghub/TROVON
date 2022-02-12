static int wacom_get_report(struct hid_device *hdev, u8 type, u8 *buf,
size_t size, unsigned int retries)
{
int retval;
do {
retval = hid_hw_raw_request(hdev, buf[0], buf, size, type,
HID_REQ_GET_REPORT);
} while ((retval == -ETIMEDOUT || retval == -EAGAIN) && --retries);
if (retval < 0)
hid_err(hdev, "wacom_get_report: ran out of retries "
"(last error = %d)\n", retval);
return retval;
}
static int wacom_set_report(struct hid_device *hdev, u8 type, u8 *buf,
size_t size, unsigned int retries)
{
int retval;
do {
retval = hid_hw_raw_request(hdev, buf[0], buf, size, type,
HID_REQ_SET_REPORT);
} while ((retval == -ETIMEDOUT || retval == -EAGAIN) && --retries);
if (retval < 0)
hid_err(hdev, "wacom_set_report: ran out of retries "
"(last error = %d)\n", retval);
return retval;
}
static int wacom_raw_event(struct hid_device *hdev, struct hid_report *report,
u8 *raw_data, int size)
{
struct wacom *wacom = hid_get_drvdata(hdev);
if (size > WACOM_PKGLEN_MAX)
return 1;
memcpy(wacom->wacom_wac.data, raw_data, size);
wacom_wac_irq(&wacom->wacom_wac, size);
return 0;
}
static int wacom_open(struct input_dev *dev)
{
struct wacom *wacom = input_get_drvdata(dev);
return hid_hw_open(wacom->hdev);
}
static void wacom_close(struct input_dev *dev)
{
struct wacom *wacom = input_get_drvdata(dev);
hid_hw_close(wacom->hdev);
}
static int wacom_calc_hid_res(int logical_extents, int physical_extents,
unsigned unit, int exponent)
{
struct hid_field field = {
.logical_maximum = logical_extents,
.physical_maximum = physical_extents,
.unit = unit,
.unit_exponent = exponent,
};
return hidinput_calc_abs_res(&field, ABS_X);
}
static void wacom_feature_mapping(struct hid_device *hdev,
struct hid_field *field, struct hid_usage *usage)
{
struct wacom *wacom = hid_get_drvdata(hdev);
struct wacom_features *features = &wacom->wacom_wac.features;
struct hid_data *hid_data = &wacom->wacom_wac.hid_data;
u8 *data;
int ret;
switch (usage->hid) {
case HID_DG_CONTACTMAX:
if (!features->touch_max) {
data = kzalloc(2, GFP_KERNEL);
if (!data)
break;
data[0] = field->report->id;
ret = wacom_get_report(hdev, HID_FEATURE_REPORT,
data, 2, WAC_CMD_RETRIES);
if (ret == 2) {
features->touch_max = data[1];
} else {
features->touch_max = 16;
hid_warn(hdev, "wacom_feature_mapping: "
"could not get HID_DG_CONTACTMAX, "
"defaulting to %d\n",
features->touch_max);
}
kfree(data);
}
break;
case HID_DG_INPUTMODE:
if (usage->usage_index >= field->report_count) {
dev_err(&hdev->dev, "HID_DG_INPUTMODE out of range\n");
break;
}
hid_data->inputmode = field->report->id;
hid_data->inputmode_index = usage->usage_index;
break;
}
}
static void wacom_usage_mapping(struct hid_device *hdev,
struct hid_field *field, struct hid_usage *usage)
{
struct wacom *wacom = hid_get_drvdata(hdev);
struct wacom_features *features = &wacom->wacom_wac.features;
bool finger = WACOM_FINGER_FIELD(field);
bool pen = WACOM_PEN_FIELD(field);
if (pen)
features->device_type |= WACOM_DEVICETYPE_PEN;
else if (finger)
features->device_type |= WACOM_DEVICETYPE_TOUCH;
else
return;
if (features->type != BAMBOO_PT) {
if (finger && !features->touch_max)
features->touch_max = 1;
}
switch (usage->hid) {
case HID_GD_X:
features->x_max = field->logical_maximum;
if (finger) {
features->x_phy = field->physical_maximum;
if (features->type != BAMBOO_PT) {
features->unit = field->unit;
features->unitExpo = field->unit_exponent;
}
}
break;
case HID_GD_Y:
features->y_max = field->logical_maximum;
if (finger) {
features->y_phy = field->physical_maximum;
if (features->type != BAMBOO_PT) {
features->unit = field->unit;
features->unitExpo = field->unit_exponent;
}
}
break;
case HID_DG_TIPPRESSURE:
if (pen)
features->pressure_max = field->logical_maximum;
break;
}
if (features->type == HID_GENERIC)
wacom_wac_usage_mapping(hdev, field, usage);
}
static void wacom_post_parse_hid(struct hid_device *hdev,
struct wacom_features *features)
{
struct wacom *wacom = hid_get_drvdata(hdev);
struct wacom_wac *wacom_wac = &wacom->wacom_wac;
if (features->type == HID_GENERIC) {
if (features->touch_max > 1) {
input_mt_init_slots(wacom_wac->touch_input, wacom_wac->features.touch_max,
INPUT_MT_DIRECT);
}
}
}
static void wacom_parse_hid(struct hid_device *hdev,
struct wacom_features *features)
{
struct hid_report_enum *rep_enum;
struct hid_report *hreport;
int i, j;
rep_enum = &hdev->report_enum[HID_FEATURE_REPORT];
list_for_each_entry(hreport, &rep_enum->report_list, list) {
for (i = 0; i < hreport->maxfield; i++) {
if (hreport->field[i]->report_count < 1)
continue;
for (j = 0; j < hreport->field[i]->maxusage; j++) {
wacom_feature_mapping(hdev, hreport->field[i],
hreport->field[i]->usage + j);
}
}
}
rep_enum = &hdev->report_enum[HID_INPUT_REPORT];
list_for_each_entry(hreport, &rep_enum->report_list, list) {
if (!hreport->maxfield)
continue;
for (i = 0; i < hreport->maxfield; i++)
for (j = 0; j < hreport->field[i]->maxusage; j++)
wacom_usage_mapping(hdev, hreport->field[i],
hreport->field[i]->usage + j);
}
wacom_post_parse_hid(hdev, features);
}
static int wacom_hid_set_device_mode(struct hid_device *hdev)
{
struct wacom *wacom = hid_get_drvdata(hdev);
struct hid_data *hid_data = &wacom->wacom_wac.hid_data;
struct hid_report *r;
struct hid_report_enum *re;
if (hid_data->inputmode < 0)
return 0;
re = &(hdev->report_enum[HID_FEATURE_REPORT]);
r = re->report_id_hash[hid_data->inputmode];
if (r) {
r->field[0]->value[hid_data->inputmode_index] = 2;
hid_hw_request(hdev, r, HID_REQ_SET_REPORT);
}
return 0;
}
static int wacom_set_device_mode(struct hid_device *hdev, int report_id,
int length, int mode)
{
unsigned char *rep_data;
int error = -ENOMEM, limit = 0;
rep_data = kzalloc(length, GFP_KERNEL);
if (!rep_data)
return error;
do {
rep_data[0] = report_id;
rep_data[1] = mode;
error = wacom_set_report(hdev, HID_FEATURE_REPORT, rep_data,
length, 1);
if (error >= 0)
error = wacom_get_report(hdev, HID_FEATURE_REPORT,
rep_data, length, 1);
} while ((error < 0 || rep_data[1] != mode) && limit++ < WAC_MSG_RETRIES);
kfree(rep_data);
return error < 0 ? error : 0;
}
static int wacom_bt_query_tablet_data(struct hid_device *hdev, u8 speed,
struct wacom_features *features)
{
struct wacom *wacom = hid_get_drvdata(hdev);
int ret;
u8 rep_data[2];
switch (features->type) {
case GRAPHIRE_BT:
rep_data[0] = 0x03;
rep_data[1] = 0x00;
ret = wacom_set_report(hdev, HID_FEATURE_REPORT, rep_data, 2,
3);
if (ret >= 0) {
rep_data[0] = speed == 0 ? 0x05 : 0x06;
rep_data[1] = 0x00;
ret = wacom_set_report(hdev, HID_FEATURE_REPORT,
rep_data, 2, 3);
if (ret >= 0) {
wacom->wacom_wac.bt_high_speed = speed;
return 0;
}
}
hid_warn(hdev, "failed to poke device, command %d, err %d\n",
rep_data[0], ret);
break;
case INTUOS4WL:
if (speed == 1)
wacom->wacom_wac.bt_features &= ~0x20;
else
wacom->wacom_wac.bt_features |= 0x20;
rep_data[0] = 0x03;
rep_data[1] = wacom->wacom_wac.bt_features;
ret = wacom_set_report(hdev, HID_FEATURE_REPORT, rep_data, 2,
1);
if (ret >= 0)
wacom->wacom_wac.bt_high_speed = speed;
break;
}
return 0;
}
static int wacom_query_tablet_data(struct hid_device *hdev,
struct wacom_features *features)
{
if (hdev->bus == BUS_BLUETOOTH)
return wacom_bt_query_tablet_data(hdev, 1, features);
if (features->type == HID_GENERIC)
return wacom_hid_set_device_mode(hdev);
if (features->device_type & WACOM_DEVICETYPE_TOUCH) {
if (features->type > TABLETPC) {
return wacom_set_device_mode(hdev, 3, 4, 4);
}
else if (features->type == WACOM_24HDT || features->type == CINTIQ_HYBRID) {
return wacom_set_device_mode(hdev, 18, 3, 2);
}
else if (features->type == WACOM_27QHDT) {
return wacom_set_device_mode(hdev, 131, 3, 2);
}
else if (features->type == BAMBOO_PAD) {
return wacom_set_device_mode(hdev, 2, 2, 2);
}
} else if (features->device_type & WACOM_DEVICETYPE_PEN) {
if (features->type <= BAMBOO_PT && features->type != WIRELESS) {
return wacom_set_device_mode(hdev, 2, 2, 2);
}
}
return 0;
}
static void wacom_retrieve_hid_descriptor(struct hid_device *hdev,
struct wacom_features *features)
{
struct wacom *wacom = hid_get_drvdata(hdev);
struct usb_interface *intf = wacom->intf;
features->x_fuzz = 4;
features->y_fuzz = 4;
features->pressure_fuzz = 0;
features->distance_fuzz = 0;
if (features->type == WIRELESS) {
if (intf->cur_altsetting->desc.bInterfaceNumber == 0) {
features->device_type = WACOM_DEVICETYPE_NONE;
} else if (intf->cur_altsetting->desc.bInterfaceNumber == 2) {
features->device_type |= WACOM_DEVICETYPE_TOUCH;
features->pktlen = WACOM_PKGLEN_BBTOUCH3;
}
}
wacom_parse_hid(hdev, features);
}
static bool wacom_are_sibling(struct hid_device *hdev,
struct hid_device *sibling)
{
struct wacom *wacom = hid_get_drvdata(hdev);
struct wacom_features *features = &wacom->wacom_wac.features;
int vid = features->oVid;
int pid = features->oPid;
int n1,n2;
if (vid == 0 && pid == 0) {
vid = hdev->vendor;
pid = hdev->product;
}
if (vid != sibling->vendor || pid != sibling->product)
return false;
n1 = strrchr(hdev->phys, '.') - hdev->phys;
n2 = strrchr(sibling->phys, '.') - sibling->phys;
if (n1 != n2 || n1 <= 0 || n2 <= 0)
return false;
return !strncmp(hdev->phys, sibling->phys, n1);
}
static struct wacom_hdev_data *wacom_get_hdev_data(struct hid_device *hdev)
{
struct wacom_hdev_data *data;
list_for_each_entry(data, &wacom_udev_list, list) {
if (wacom_are_sibling(hdev, data->dev)) {
kref_get(&data->kref);
return data;
}
}
return NULL;
}
static int wacom_add_shared_data(struct hid_device *hdev)
{
struct wacom *wacom = hid_get_drvdata(hdev);
struct wacom_wac *wacom_wac = &wacom->wacom_wac;
struct wacom_hdev_data *data;
int retval = 0;
mutex_lock(&wacom_udev_list_lock);
data = wacom_get_hdev_data(hdev);
if (!data) {
data = kzalloc(sizeof(struct wacom_hdev_data), GFP_KERNEL);
if (!data) {
retval = -ENOMEM;
goto out;
}
kref_init(&data->kref);
data->dev = hdev;
list_add_tail(&data->list, &wacom_udev_list);
}
wacom_wac->shared = &data->shared;
if (wacom_wac->features.device_type & WACOM_DEVICETYPE_TOUCH)
wacom_wac->shared->touch = hdev;
else if (wacom_wac->features.device_type & WACOM_DEVICETYPE_PEN)
wacom_wac->shared->pen = hdev;
out:
mutex_unlock(&wacom_udev_list_lock);
return retval;
}
static void wacom_release_shared_data(struct kref *kref)
{
struct wacom_hdev_data *data =
container_of(kref, struct wacom_hdev_data, kref);
mutex_lock(&wacom_udev_list_lock);
list_del(&data->list);
mutex_unlock(&wacom_udev_list_lock);
kfree(data);
}
static void wacom_remove_shared_data(struct wacom *wacom)
{
struct wacom_hdev_data *data;
struct wacom_wac *wacom_wac = &wacom->wacom_wac;
if (wacom_wac->shared) {
data = container_of(wacom_wac->shared, struct wacom_hdev_data,
shared);
if (wacom_wac->shared->touch == wacom->hdev)
wacom_wac->shared->touch = NULL;
else if (wacom_wac->shared->pen == wacom->hdev)
wacom_wac->shared->pen = NULL;
kref_put(&data->kref, wacom_release_shared_data);
wacom_wac->shared = NULL;
}
}
static int wacom_led_control(struct wacom *wacom)
{
unsigned char *buf;
int retval;
unsigned char report_id = WAC_CMD_LED_CONTROL;
int buf_size = 9;
if (wacom->wacom_wac.pid) {
report_id = WAC_CMD_WL_LED_CONTROL;
buf_size = 13;
}
buf = kzalloc(buf_size, GFP_KERNEL);
if (!buf)
return -ENOMEM;
if (wacom->wacom_wac.features.type >= INTUOS5S &&
wacom->wacom_wac.features.type <= INTUOSPL) {
int ring_led = wacom->led.select[0] & 0x03;
int ring_lum = (((wacom->led.llv & 0x60) >> 5) - 1) & 0x03;
int crop_lum = 0;
unsigned char led_bits = (crop_lum << 4) | (ring_lum << 2) | (ring_led);
buf[0] = report_id;
if (wacom->wacom_wac.pid) {
wacom_get_report(wacom->hdev, HID_FEATURE_REPORT,
buf, buf_size, WAC_CMD_RETRIES);
buf[0] = report_id;
buf[4] = led_bits;
} else
buf[1] = led_bits;
}
else {
int led = wacom->led.select[0] | 0x4;
if (wacom->wacom_wac.features.type == WACOM_21UX2 ||
wacom->wacom_wac.features.type == WACOM_24HD)
led |= (wacom->led.select[1] << 4) | 0x40;
buf[0] = report_id;
buf[1] = led;
buf[2] = wacom->led.llv;
buf[3] = wacom->led.hlv;
buf[4] = wacom->led.img_lum;
}
retval = wacom_set_report(wacom->hdev, HID_FEATURE_REPORT, buf, buf_size,
WAC_CMD_RETRIES);
kfree(buf);
return retval;
}
static int wacom_led_putimage(struct wacom *wacom, int button_id, u8 xfer_id,
const unsigned len, const void *img)
{
unsigned char *buf;
int i, retval;
const unsigned chunk_len = len / 4;
buf = kzalloc(chunk_len + 3 , GFP_KERNEL);
if (!buf)
return -ENOMEM;
buf[0] = WAC_CMD_ICON_START;
buf[1] = 1;
retval = wacom_set_report(wacom->hdev, HID_FEATURE_REPORT, buf, 2,
WAC_CMD_RETRIES);
if (retval < 0)
goto out;
buf[0] = xfer_id;
buf[1] = button_id & 0x07;
for (i = 0; i < 4; i++) {
buf[2] = i;
memcpy(buf + 3, img + i * chunk_len, chunk_len);
retval = wacom_set_report(wacom->hdev, HID_FEATURE_REPORT,
buf, chunk_len + 3, WAC_CMD_RETRIES);
if (retval < 0)
break;
}
buf[0] = WAC_CMD_ICON_START;
buf[1] = 0;
wacom_set_report(wacom->hdev, HID_FEATURE_REPORT, buf, 2,
WAC_CMD_RETRIES);
out:
kfree(buf);
return retval;
}
static ssize_t wacom_led_select_store(struct device *dev, int set_id,
const char *buf, size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct wacom *wacom = hid_get_drvdata(hdev);
unsigned int id;
int err;
err = kstrtouint(buf, 10, &id);
if (err)
return err;
mutex_lock(&wacom->lock);
wacom->led.select[set_id] = id & 0x3;
err = wacom_led_control(wacom);
mutex_unlock(&wacom->lock);
return err < 0 ? err : count;
}
static ssize_t wacom_luminance_store(struct wacom *wacom, u8 *dest,
const char *buf, size_t count)
{
unsigned int value;
int err;
err = kstrtouint(buf, 10, &value);
if (err)
return err;
mutex_lock(&wacom->lock);
*dest = value & 0x7f;
err = wacom_led_control(wacom);
mutex_unlock(&wacom->lock);
return err < 0 ? err : count;
}
static ssize_t wacom_button_image_store(struct device *dev, int button_id,
const char *buf, size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct wacom *wacom = hid_get_drvdata(hdev);
int err;
unsigned len;
u8 xfer_id;
if (hdev->bus == BUS_BLUETOOTH) {
len = 256;
xfer_id = WAC_CMD_ICON_BT_XFER;
} else {
len = 1024;
xfer_id = WAC_CMD_ICON_XFER;
}
if (count != len)
return -EINVAL;
mutex_lock(&wacom->lock);
err = wacom_led_putimage(wacom, button_id, xfer_id, len, buf);
mutex_unlock(&wacom->lock);
return err < 0 ? err : count;
}
static int wacom_initialize_leds(struct wacom *wacom)
{
int error;
if (!(wacom->wacom_wac.features.device_type & WACOM_DEVICETYPE_PAD))
return 0;
switch (wacom->wacom_wac.features.type) {
case INTUOS4S:
case INTUOS4:
case INTUOS4WL:
case INTUOS4L:
wacom->led.select[0] = 0;
wacom->led.select[1] = 0;
wacom->led.llv = 10;
wacom->led.hlv = 20;
wacom->led.img_lum = 10;
error = sysfs_create_group(&wacom->hdev->dev.kobj,
&intuos4_led_attr_group);
break;
case WACOM_24HD:
case WACOM_21UX2:
wacom->led.select[0] = 0;
wacom->led.select[1] = 0;
wacom->led.llv = 0;
wacom->led.hlv = 0;
wacom->led.img_lum = 0;
error = sysfs_create_group(&wacom->hdev->dev.kobj,
&cintiq_led_attr_group);
break;
case INTUOS5S:
case INTUOS5:
case INTUOS5L:
case INTUOSPS:
case INTUOSPM:
case INTUOSPL:
wacom->led.select[0] = 0;
wacom->led.select[1] = 0;
wacom->led.llv = 32;
wacom->led.hlv = 0;
wacom->led.img_lum = 0;
error = sysfs_create_group(&wacom->hdev->dev.kobj,
&intuos5_led_attr_group);
break;
default:
return 0;
}
if (error) {
hid_err(wacom->hdev,
"cannot create sysfs group err: %d\n", error);
return error;
}
wacom_led_control(wacom);
wacom->led_initialized = true;
return 0;
}
static void wacom_destroy_leds(struct wacom *wacom)
{
if (!wacom->led_initialized)
return;
if (!(wacom->wacom_wac.features.device_type & WACOM_DEVICETYPE_PAD))
return;
wacom->led_initialized = false;
switch (wacom->wacom_wac.features.type) {
case INTUOS4S:
case INTUOS4:
case INTUOS4WL:
case INTUOS4L:
sysfs_remove_group(&wacom->hdev->dev.kobj,
&intuos4_led_attr_group);
break;
case WACOM_24HD:
case WACOM_21UX2:
sysfs_remove_group(&wacom->hdev->dev.kobj,
&cintiq_led_attr_group);
break;
case INTUOS5S:
case INTUOS5:
case INTUOS5L:
case INTUOSPS:
case INTUOSPM:
case INTUOSPL:
sysfs_remove_group(&wacom->hdev->dev.kobj,
&intuos5_led_attr_group);
break;
}
}
static int wacom_battery_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct wacom *wacom = power_supply_get_drvdata(psy);
int ret = 0;
switch (psp) {
case POWER_SUPPLY_PROP_PRESENT:
val->intval = wacom->wacom_wac.bat_connected;
break;
case POWER_SUPPLY_PROP_SCOPE:
val->intval = POWER_SUPPLY_SCOPE_DEVICE;
break;
case POWER_SUPPLY_PROP_CAPACITY:
val->intval =
wacom->wacom_wac.battery_capacity;
break;
case POWER_SUPPLY_PROP_STATUS:
if (wacom->wacom_wac.bat_charging)
val->intval = POWER_SUPPLY_STATUS_CHARGING;
else if (wacom->wacom_wac.battery_capacity == 100 &&
wacom->wacom_wac.ps_connected)
val->intval = POWER_SUPPLY_STATUS_FULL;
else if (wacom->wacom_wac.ps_connected)
val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
else
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
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
struct wacom *wacom = power_supply_get_drvdata(psy);
int ret = 0;
switch (psp) {
case POWER_SUPPLY_PROP_PRESENT:
case POWER_SUPPLY_PROP_ONLINE:
val->intval = wacom->wacom_wac.ps_connected;
break;
case POWER_SUPPLY_PROP_SCOPE:
val->intval = POWER_SUPPLY_SCOPE_DEVICE;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int wacom_initialize_battery(struct wacom *wacom)
{
static atomic_t battery_no = ATOMIC_INIT(0);
struct power_supply_config psy_cfg = { .drv_data = wacom, };
unsigned long n;
if (wacom->wacom_wac.features.quirks & WACOM_QUIRK_BATTERY) {
struct power_supply_desc *bat_desc = &wacom->battery_desc;
struct power_supply_desc *ac_desc = &wacom->ac_desc;
n = atomic_inc_return(&battery_no) - 1;
bat_desc->properties = wacom_battery_props;
bat_desc->num_properties = ARRAY_SIZE(wacom_battery_props);
bat_desc->get_property = wacom_battery_get_property;
sprintf(wacom->wacom_wac.bat_name, "wacom_battery_%ld", n);
bat_desc->name = wacom->wacom_wac.bat_name;
bat_desc->type = POWER_SUPPLY_TYPE_BATTERY;
bat_desc->use_for_apm = 0;
ac_desc->properties = wacom_ac_props;
ac_desc->num_properties = ARRAY_SIZE(wacom_ac_props);
ac_desc->get_property = wacom_ac_get_property;
sprintf(wacom->wacom_wac.ac_name, "wacom_ac_%ld", n);
ac_desc->name = wacom->wacom_wac.ac_name;
ac_desc->type = POWER_SUPPLY_TYPE_MAINS;
ac_desc->use_for_apm = 0;
wacom->battery = power_supply_register(&wacom->hdev->dev,
&wacom->battery_desc, &psy_cfg);
if (IS_ERR(wacom->battery))
return PTR_ERR(wacom->battery);
power_supply_powers(wacom->battery, &wacom->hdev->dev);
wacom->ac = power_supply_register(&wacom->hdev->dev,
&wacom->ac_desc,
&psy_cfg);
if (IS_ERR(wacom->ac)) {
power_supply_unregister(wacom->battery);
return PTR_ERR(wacom->ac);
}
power_supply_powers(wacom->ac, &wacom->hdev->dev);
}
return 0;
}
static void wacom_destroy_battery(struct wacom *wacom)
{
if (wacom->battery) {
power_supply_unregister(wacom->battery);
wacom->battery = NULL;
power_supply_unregister(wacom->ac);
wacom->ac = NULL;
}
}
static ssize_t wacom_show_speed(struct device *dev,
struct device_attribute
*attr, char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct wacom *wacom = hid_get_drvdata(hdev);
return snprintf(buf, PAGE_SIZE, "%i\n", wacom->wacom_wac.bt_high_speed);
}
static ssize_t wacom_store_speed(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct wacom *wacom = hid_get_drvdata(hdev);
u8 new_speed;
if (kstrtou8(buf, 0, &new_speed))
return -EINVAL;
if (new_speed != 0 && new_speed != 1)
return -EINVAL;
wacom_bt_query_tablet_data(hdev, new_speed, &wacom->wacom_wac.features);
return count;
}
static struct input_dev *wacom_allocate_input(struct wacom *wacom)
{
struct input_dev *input_dev;
struct hid_device *hdev = wacom->hdev;
struct wacom_wac *wacom_wac = &(wacom->wacom_wac);
input_dev = input_allocate_device();
if (!input_dev)
return NULL;
input_dev->name = wacom_wac->pen_name;
input_dev->phys = hdev->phys;
input_dev->dev.parent = &hdev->dev;
input_dev->open = wacom_open;
input_dev->close = wacom_close;
input_dev->uniq = hdev->uniq;
input_dev->id.bustype = hdev->bus;
input_dev->id.vendor = hdev->vendor;
input_dev->id.product = wacom_wac->pid ? wacom_wac->pid : hdev->product;
input_dev->id.version = hdev->version;
input_set_drvdata(input_dev, wacom);
return input_dev;
}
static void wacom_free_inputs(struct wacom *wacom)
{
struct wacom_wac *wacom_wac = &(wacom->wacom_wac);
if (wacom_wac->pen_input)
input_free_device(wacom_wac->pen_input);
if (wacom_wac->touch_input)
input_free_device(wacom_wac->touch_input);
if (wacom_wac->pad_input)
input_free_device(wacom_wac->pad_input);
wacom_wac->pen_input = NULL;
wacom_wac->touch_input = NULL;
wacom_wac->pad_input = NULL;
}
static int wacom_allocate_inputs(struct wacom *wacom)
{
struct input_dev *pen_input_dev, *touch_input_dev, *pad_input_dev;
struct wacom_wac *wacom_wac = &(wacom->wacom_wac);
pen_input_dev = wacom_allocate_input(wacom);
touch_input_dev = wacom_allocate_input(wacom);
pad_input_dev = wacom_allocate_input(wacom);
if (!pen_input_dev || !touch_input_dev || !pad_input_dev) {
wacom_free_inputs(wacom);
return -ENOMEM;
}
wacom_wac->pen_input = pen_input_dev;
wacom_wac->touch_input = touch_input_dev;
wacom_wac->touch_input->name = wacom_wac->touch_name;
wacom_wac->pad_input = pad_input_dev;
wacom_wac->pad_input->name = wacom_wac->pad_name;
return 0;
}
static void wacom_clean_inputs(struct wacom *wacom)
{
if (wacom->wacom_wac.pen_input) {
if (wacom->wacom_wac.pen_registered)
input_unregister_device(wacom->wacom_wac.pen_input);
else
input_free_device(wacom->wacom_wac.pen_input);
}
if (wacom->wacom_wac.touch_input) {
if (wacom->wacom_wac.touch_registered)
input_unregister_device(wacom->wacom_wac.touch_input);
else
input_free_device(wacom->wacom_wac.touch_input);
}
if (wacom->wacom_wac.pad_input) {
if (wacom->wacom_wac.pad_registered)
input_unregister_device(wacom->wacom_wac.pad_input);
else
input_free_device(wacom->wacom_wac.pad_input);
}
wacom->wacom_wac.pen_input = NULL;
wacom->wacom_wac.touch_input = NULL;
wacom->wacom_wac.pad_input = NULL;
wacom_destroy_leds(wacom);
}
static int wacom_register_inputs(struct wacom *wacom)
{
struct input_dev *pen_input_dev, *touch_input_dev, *pad_input_dev;
struct wacom_wac *wacom_wac = &(wacom->wacom_wac);
int error = 0;
pen_input_dev = wacom_wac->pen_input;
touch_input_dev = wacom_wac->touch_input;
pad_input_dev = wacom_wac->pad_input;
if (!pen_input_dev || !touch_input_dev || !pad_input_dev)
return -EINVAL;
error = wacom_setup_pen_input_capabilities(pen_input_dev, wacom_wac);
if (error) {
input_free_device(pen_input_dev);
wacom_wac->pen_input = NULL;
pen_input_dev = NULL;
} else {
error = input_register_device(pen_input_dev);
if (error)
goto fail_register_pen_input;
wacom_wac->pen_registered = true;
}
error = wacom_setup_touch_input_capabilities(touch_input_dev, wacom_wac);
if (error) {
input_free_device(touch_input_dev);
wacom_wac->touch_input = NULL;
touch_input_dev = NULL;
} else {
error = input_register_device(touch_input_dev);
if (error)
goto fail_register_touch_input;
wacom_wac->touch_registered = true;
}
error = wacom_setup_pad_input_capabilities(pad_input_dev, wacom_wac);
if (error) {
input_free_device(pad_input_dev);
wacom_wac->pad_input = NULL;
pad_input_dev = NULL;
} else {
error = input_register_device(pad_input_dev);
if (error)
goto fail_register_pad_input;
wacom_wac->pad_registered = true;
error = wacom_initialize_leds(wacom);
if (error)
goto fail_leds;
}
return 0;
fail_leds:
input_unregister_device(pad_input_dev);
pad_input_dev = NULL;
wacom_wac->pad_registered = false;
fail_register_pad_input:
if (touch_input_dev)
input_unregister_device(touch_input_dev);
wacom_wac->touch_input = NULL;
wacom_wac->touch_registered = false;
fail_register_touch_input:
if (pen_input_dev)
input_unregister_device(pen_input_dev);
wacom_wac->pen_input = NULL;
wacom_wac->pen_registered = false;
fail_register_pen_input:
return error;
}
static void wacom_set_default_phy(struct wacom_features *features)
{
if (features->x_resolution) {
features->x_phy = (features->x_max * 100) /
features->x_resolution;
features->y_phy = (features->y_max * 100) /
features->y_resolution;
}
}
static void wacom_calculate_res(struct wacom_features *features)
{
if (!features->unit) {
features->unit = 0x11;
features->unitExpo = -3;
}
features->x_resolution = wacom_calc_hid_res(features->x_max,
features->x_phy,
features->unit,
features->unitExpo);
features->y_resolution = wacom_calc_hid_res(features->y_max,
features->y_phy,
features->unit,
features->unitExpo);
}
static void wacom_wireless_work(struct work_struct *work)
{
struct wacom *wacom = container_of(work, struct wacom, work);
struct usb_device *usbdev = wacom->usbdev;
struct wacom_wac *wacom_wac = &wacom->wacom_wac;
struct hid_device *hdev1, *hdev2;
struct wacom *wacom1, *wacom2;
struct wacom_wac *wacom_wac1, *wacom_wac2;
int error;
wacom_destroy_battery(wacom);
hdev1 = usb_get_intfdata(usbdev->config->interface[1]);
wacom1 = hid_get_drvdata(hdev1);
wacom_wac1 = &(wacom1->wacom_wac);
wacom_clean_inputs(wacom1);
hdev2 = usb_get_intfdata(usbdev->config->interface[2]);
wacom2 = hid_get_drvdata(hdev2);
wacom_wac2 = &(wacom2->wacom_wac);
wacom_clean_inputs(wacom2);
if (wacom_wac->pid == 0) {
hid_info(wacom->hdev, "wireless tablet disconnected\n");
wacom_wac1->shared->type = 0;
} else {
const struct hid_device_id *id = wacom_ids;
hid_info(wacom->hdev, "wireless tablet connected with PID %x\n",
wacom_wac->pid);
while (id->bus) {
if (id->vendor == USB_VENDOR_ID_WACOM &&
id->product == wacom_wac->pid)
break;
id++;
}
if (!id->bus) {
hid_info(wacom->hdev, "ignoring unknown PID.\n");
return;
}
wacom_wac1->features =
*((struct wacom_features *)id->driver_data);
wacom_wac1->features.device_type |= WACOM_DEVICETYPE_PEN;
if (wacom_wac1->features.type != INTUOSHT &&
wacom_wac1->features.type != BAMBOO_PT)
wacom_wac1->features.device_type |= WACOM_DEVICETYPE_PAD;
wacom_set_default_phy(&wacom_wac1->features);
wacom_calculate_res(&wacom_wac1->features);
snprintf(wacom_wac1->pen_name, WACOM_NAME_MAX, "%s (WL) Pen",
wacom_wac1->features.name);
snprintf(wacom_wac1->pad_name, WACOM_NAME_MAX, "%s (WL) Pad",
wacom_wac1->features.name);
wacom_wac1->shared->touch_max = wacom_wac1->features.touch_max;
wacom_wac1->shared->type = wacom_wac1->features.type;
wacom_wac1->pid = wacom_wac->pid;
error = wacom_allocate_inputs(wacom1) ||
wacom_register_inputs(wacom1);
if (error)
goto fail;
if (wacom_wac1->features.touch_max ||
wacom_wac1->features.type == INTUOSHT) {
wacom_wac2->features =
*((struct wacom_features *)id->driver_data);
wacom_wac2->features.pktlen = WACOM_PKGLEN_BBTOUCH3;
wacom_set_default_phy(&wacom_wac2->features);
wacom_wac2->features.x_max = wacom_wac2->features.y_max = 4096;
wacom_calculate_res(&wacom_wac2->features);
snprintf(wacom_wac2->touch_name, WACOM_NAME_MAX,
"%s (WL) Finger",wacom_wac2->features.name);
snprintf(wacom_wac2->pad_name, WACOM_NAME_MAX,
"%s (WL) Pad",wacom_wac2->features.name);
if (wacom_wac1->features.touch_max)
wacom_wac2->features.device_type |= WACOM_DEVICETYPE_TOUCH;
if (wacom_wac1->features.type == INTUOSHT ||
wacom_wac1->features.type == BAMBOO_PT)
wacom_wac2->features.device_type |= WACOM_DEVICETYPE_PAD;
wacom_wac2->pid = wacom_wac->pid;
error = wacom_allocate_inputs(wacom2) ||
wacom_register_inputs(wacom2);
if (error)
goto fail;
if (wacom_wac1->features.type == INTUOSHT &&
wacom_wac1->features.touch_max)
wacom_wac->shared->touch_input = wacom_wac2->touch_input;
}
error = wacom_initialize_battery(wacom);
if (error)
goto fail;
}
return;
fail:
wacom_clean_inputs(wacom1);
wacom_clean_inputs(wacom2);
return;
}
void wacom_battery_work(struct work_struct *work)
{
struct wacom *wacom = container_of(work, struct wacom, work);
if ((wacom->wacom_wac.features.quirks & WACOM_QUIRK_BATTERY) &&
!wacom->battery) {
wacom_initialize_battery(wacom);
}
else if (!(wacom->wacom_wac.features.quirks & WACOM_QUIRK_BATTERY) &&
wacom->battery) {
wacom_destroy_battery(wacom);
}
}
static size_t wacom_compute_pktlen(struct hid_device *hdev)
{
struct hid_report_enum *report_enum;
struct hid_report *report;
size_t size = 0;
report_enum = hdev->report_enum + HID_INPUT_REPORT;
list_for_each_entry(report, &report_enum->report_list, list) {
size_t report_size = hid_report_len(report);
if (report_size > size)
size = report_size;
}
return size;
}
static void wacom_update_name(struct wacom *wacom)
{
struct wacom_wac *wacom_wac = &wacom->wacom_wac;
struct wacom_features *features = &wacom_wac->features;
char name[WACOM_NAME_MAX];
if ((features->type == HID_GENERIC) && !strcmp("Wacom HID", features->name)) {
if (strstr(wacom->hdev->name, "Wacom") ||
strstr(wacom->hdev->name, "wacom") ||
strstr(wacom->hdev->name, "WACOM")) {
strlcpy(name, wacom->hdev->name, sizeof(name));
while (1) {
char *gap = strstr(name, " ");
if (gap == NULL)
break;
memmove(gap, gap+1, strlen(gap));
}
if (name[strlen(name)-1] == ' ')
name[strlen(name)-1] = '\0';
} else {
snprintf(name, sizeof(name),
"%s %X", features->name, wacom->hdev->product);
}
} else {
strlcpy(name, features->name, sizeof(name));
}
snprintf(wacom_wac->pen_name, sizeof(wacom_wac->pen_name),
"%s Pen", name);
snprintf(wacom_wac->touch_name, sizeof(wacom_wac->touch_name),
"%s Finger", name);
snprintf(wacom_wac->pad_name, sizeof(wacom_wac->pad_name),
"%s Pad", name);
}
static int wacom_probe(struct hid_device *hdev,
const struct hid_device_id *id)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
struct usb_device *dev = interface_to_usbdev(intf);
struct wacom *wacom;
struct wacom_wac *wacom_wac;
struct wacom_features *features;
int error;
unsigned int connect_mask = HID_CONNECT_HIDRAW;
if (!id->driver_data)
return -EINVAL;
hdev->quirks |= HID_QUIRK_NO_INIT_REPORTS;
hdev->quirks &= ~HID_QUIRK_NOGET;
wacom = kzalloc(sizeof(struct wacom), GFP_KERNEL);
if (!wacom)
return -ENOMEM;
hid_set_drvdata(hdev, wacom);
wacom->hdev = hdev;
error = hid_parse(hdev);
if (error) {
hid_err(hdev, "parse failed\n");
goto fail_parse;
}
wacom_wac = &wacom->wacom_wac;
wacom_wac->features = *((struct wacom_features *)id->driver_data);
features = &wacom_wac->features;
features->pktlen = wacom_compute_pktlen(hdev);
if (features->pktlen > WACOM_PKGLEN_MAX) {
error = -EINVAL;
goto fail_pktlen;
}
if (features->check_for_hid_type && features->hid_type != hdev->type) {
error = -ENODEV;
goto fail_type;
}
wacom->usbdev = dev;
wacom->intf = intf;
mutex_init(&wacom->lock);
INIT_WORK(&wacom->work, wacom_wireless_work);
if (!(features->quirks & WACOM_QUIRK_NO_INPUT)) {
error = wacom_allocate_inputs(wacom);
if (error)
goto fail_allocate_inputs;
}
if (features->type == BAMBOO_PAD) {
if (features->pktlen == WACOM_PKGLEN_PENABLED) {
features->type = HID_GENERIC;
} else if ((features->pktlen != WACOM_PKGLEN_BPAD_TOUCH) &&
(features->pktlen != WACOM_PKGLEN_BPAD_TOUCH_USB)) {
error = -ENODEV;
goto fail_shared_data;
}
}
wacom_set_default_phy(features);
wacom_retrieve_hid_descriptor(hdev, features);
wacom_setup_device_quirks(wacom);
if (features->device_type == WACOM_DEVICETYPE_NONE &&
features->type != WIRELESS) {
error = features->type == HID_GENERIC ? -ENODEV : 0;
dev_warn(&hdev->dev, "Unknown device_type for '%s'. %s.",
hdev->name,
error ? "Ignoring" : "Assuming pen");
if (error)
goto fail_shared_data;
features->device_type |= WACOM_DEVICETYPE_PEN;
}
wacom_calculate_res(features);
wacom_update_name(wacom);
error = wacom_add_shared_data(hdev);
if (error)
goto fail_shared_data;
if (!(features->quirks & WACOM_QUIRK_MONITOR) &&
(features->quirks & WACOM_QUIRK_BATTERY)) {
error = wacom_initialize_battery(wacom);
if (error)
goto fail_battery;
}
if (!(features->quirks & WACOM_QUIRK_NO_INPUT)) {
error = wacom_register_inputs(wacom);
if (error)
goto fail_register_inputs;
}
if (hdev->bus == BUS_BLUETOOTH) {
error = device_create_file(&hdev->dev, &dev_attr_speed);
if (error)
hid_warn(hdev,
"can't create sysfs speed attribute err: %d\n",
error);
}
if (features->type == HID_GENERIC)
connect_mask |= HID_CONNECT_DRIVER;
error = hid_hw_start(hdev, connect_mask);
if (error) {
hid_err(hdev, "hw start failed\n");
goto fail_hw_start;
}
wacom_query_tablet_data(hdev, features);
if (features->quirks & WACOM_QUIRK_MONITOR)
error = hid_hw_open(hdev);
if (wacom_wac->features.type == INTUOSHT &&
wacom_wac->features.device_type & WACOM_DEVICETYPE_TOUCH) {
wacom_wac->shared->touch_input = wacom_wac->touch_input;
}
return 0;
fail_hw_start:
if (hdev->bus == BUS_BLUETOOTH)
device_remove_file(&hdev->dev, &dev_attr_speed);
fail_register_inputs:
wacom_clean_inputs(wacom);
wacom_destroy_battery(wacom);
fail_battery:
wacom_remove_shared_data(wacom);
fail_shared_data:
wacom_clean_inputs(wacom);
fail_allocate_inputs:
fail_type:
fail_pktlen:
fail_parse:
kfree(wacom);
hid_set_drvdata(hdev, NULL);
return error;
}
static void wacom_remove(struct hid_device *hdev)
{
struct wacom *wacom = hid_get_drvdata(hdev);
hid_hw_stop(hdev);
cancel_work_sync(&wacom->work);
wacom_clean_inputs(wacom);
if (hdev->bus == BUS_BLUETOOTH)
device_remove_file(&hdev->dev, &dev_attr_speed);
wacom_destroy_battery(wacom);
wacom_remove_shared_data(wacom);
hid_set_drvdata(hdev, NULL);
kfree(wacom);
}
static int wacom_resume(struct hid_device *hdev)
{
struct wacom *wacom = hid_get_drvdata(hdev);
struct wacom_features *features = &wacom->wacom_wac.features;
mutex_lock(&wacom->lock);
wacom_query_tablet_data(hdev, features);
wacom_led_control(wacom);
mutex_unlock(&wacom->lock);
return 0;
}
static int wacom_reset_resume(struct hid_device *hdev)
{
return wacom_resume(hdev);
}
