static int usage_id_cmp(const void *p1, const void *p2)
{
if (*(int *)p1 < *(int *)p2)
return -1;
if (*(int *)p1 > *(int *)p2)
return 1;
return 0;
}
static ssize_t enable_sensor_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct hid_sensor_custom *sensor_inst = platform_get_drvdata(pdev);
return sprintf(buf, "%d\n", sensor_inst->enable);
}
static int set_power_report_state(struct hid_sensor_custom *sensor_inst,
bool state)
{
int power_val = -1;
int report_val = -1;
u32 power_state_usage_id;
u32 report_state_usage_id;
int ret;
if (state) {
power_state_usage_id =
HID_USAGE_SENSOR_PROP_POWER_STATE_D0_FULL_POWER_ENUM;
report_state_usage_id =
HID_USAGE_SENSOR_PROP_REPORTING_STATE_ALL_EVENTS_ENUM;
} else {
power_state_usage_id =
HID_USAGE_SENSOR_PROP_POWER_STATE_D4_POWER_OFF_ENUM;
report_state_usage_id =
HID_USAGE_SENSOR_PROP_REPORTING_STATE_NO_EVENTS_ENUM;
}
if (sensor_inst->power_state)
power_val = hid_sensor_get_usage_index(sensor_inst->hsdev,
sensor_inst->power_state->attribute.report_id,
sensor_inst->power_state->attribute.index,
power_state_usage_id);
if (sensor_inst->report_state)
report_val = hid_sensor_get_usage_index(sensor_inst->hsdev,
sensor_inst->report_state->attribute.report_id,
sensor_inst->report_state->attribute.index,
report_state_usage_id);
if (power_val >= 0) {
power_val +=
sensor_inst->power_state->attribute.logical_minimum;
ret = sensor_hub_set_feature(sensor_inst->hsdev,
sensor_inst->power_state->attribute.report_id,
sensor_inst->power_state->attribute.index,
sizeof(power_val),
&power_val);
if (ret) {
hid_err(sensor_inst->hsdev->hdev,
"Set power state failed\n");
return ret;
}
}
if (report_val >= 0) {
report_val +=
sensor_inst->report_state->attribute.logical_minimum;
ret = sensor_hub_set_feature(sensor_inst->hsdev,
sensor_inst->report_state->attribute.report_id,
sensor_inst->report_state->attribute.index,
sizeof(report_val),
&report_val);
if (ret) {
hid_err(sensor_inst->hsdev->hdev,
"Set report state failed\n");
return ret;
}
}
return 0;
}
static ssize_t enable_sensor_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct platform_device *pdev = to_platform_device(dev);
struct hid_sensor_custom *sensor_inst = platform_get_drvdata(pdev);
int value;
int ret = -EINVAL;
if (kstrtoint(buf, 0, &value) != 0)
return -EINVAL;
mutex_lock(&sensor_inst->mutex);
if (value && !sensor_inst->enable) {
ret = sensor_hub_device_open(sensor_inst->hsdev);
if (ret)
goto unlock_state;
ret = set_power_report_state(sensor_inst, true);
if (ret) {
sensor_hub_device_close(sensor_inst->hsdev);
goto unlock_state;
}
sensor_inst->enable = true;
} else if (!value && sensor_inst->enable) {
ret = set_power_report_state(sensor_inst, false);
sensor_hub_device_close(sensor_inst->hsdev);
sensor_inst->enable = false;
}
unlock_state:
mutex_unlock(&sensor_inst->mutex);
if (ret < 0)
return ret;
return count;
}
static ssize_t show_value(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct hid_sensor_custom *sensor_inst = platform_get_drvdata(pdev);
struct hid_sensor_hub_attribute_info *attribute;
int index, usage, field_index;
char name[HID_CUSTOM_NAME_LENGTH];
bool feature = false;
bool input = false;
int value = 0;
if (sscanf(attr->attr.name, "feature-%d-%x-%s", &index, &usage,
name) == 3) {
feature = true;
field_index = index + sensor_inst->input_field_count;
} else if (sscanf(attr->attr.name, "input-%d-%x-%s", &index, &usage,
name) == 3) {
input = true;
field_index = index;
} else
return -EINVAL;
if (!strncmp(name, "value", strlen("value"))) {
u32 report_id;
int ret;
attribute = &sensor_inst->fields[field_index].attribute;
report_id = attribute->report_id;
if (feature) {
u8 values[HID_CUSTOM_MAX_FEATURE_BYTES];
int len = 0;
u64 value = 0;
int i = 0;
ret = sensor_hub_get_feature(sensor_inst->hsdev,
report_id,
index,
sizeof(values), values);
if (ret < 0)
return ret;
while (i < ret) {
if (i + attribute->size > ret) {
len += snprintf(&buf[len],
PAGE_SIZE - len,
"%d ", values[i]);
break;
}
switch (attribute->size) {
case 2:
value = (u64) *(u16 *)&values[i];
i += attribute->size;
break;
case 4:
value = (u64) *(u32 *)&values[i];
i += attribute->size;
break;
case 8:
value = *(u64 *)&values[i];
i += attribute->size;
break;
default:
value = (u64) values[i];
++i;
break;
}
len += snprintf(&buf[len], PAGE_SIZE - len,
"%lld ", value);
}
len += snprintf(&buf[len], PAGE_SIZE - len, "\n");
return len;
} else if (input)
value = sensor_hub_input_attr_get_raw_value(
sensor_inst->hsdev,
sensor_inst->hsdev->usage,
usage, report_id,
SENSOR_HUB_SYNC);
} else if (!strncmp(name, "units", strlen("units")))
value = sensor_inst->fields[field_index].attribute.units;
else if (!strncmp(name, "unit-expo", strlen("unit-expo")))
value = sensor_inst->fields[field_index].attribute.unit_expo;
else if (!strncmp(name, "size", strlen("size")))
value = sensor_inst->fields[field_index].attribute.size;
else if (!strncmp(name, "minimum", strlen("minimum")))
value = sensor_inst->fields[field_index].attribute.
logical_minimum;
else if (!strncmp(name, "maximum", strlen("maximum")))
value = sensor_inst->fields[field_index].attribute.
logical_maximum;
else if (!strncmp(name, "name", strlen("name"))) {
struct hid_custom_usage_desc *usage_desc;
usage_desc = bsearch(&usage, hid_custom_usage_desc_table,
ARRAY_SIZE(hid_custom_usage_desc_table),
sizeof(struct hid_custom_usage_desc),
usage_id_cmp);
if (usage_desc)
return snprintf(buf, PAGE_SIZE, "%s\n",
usage_desc->desc);
else
return sprintf(buf, "not-specified\n");
} else
return -EINVAL;
return sprintf(buf, "%d\n", value);
}
static ssize_t store_value(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct platform_device *pdev = to_platform_device(dev);
struct hid_sensor_custom *sensor_inst = platform_get_drvdata(pdev);
int index, field_index, usage;
char name[HID_CUSTOM_NAME_LENGTH];
int value;
if (sscanf(attr->attr.name, "feature-%d-%x-%s", &index, &usage,
name) == 3) {
field_index = index + sensor_inst->input_field_count;
} else
return -EINVAL;
if (!strncmp(name, "value", strlen("value"))) {
u32 report_id;
int ret;
if (kstrtoint(buf, 0, &value) != 0)
return -EINVAL;
report_id = sensor_inst->fields[field_index].attribute.
report_id;
ret = sensor_hub_set_feature(sensor_inst->hsdev, report_id,
index, sizeof(value), &value);
} else
return -EINVAL;
return count;
}
static int hid_sensor_capture_sample(struct hid_sensor_hub_device *hsdev,
unsigned usage_id, size_t raw_len,
char *raw_data, void *priv)
{
struct hid_sensor_custom *sensor_inst = platform_get_drvdata(priv);
struct hid_sensor_sample header;
if (sensor_inst->input_skip_sample) {
hid_err(sensor_inst->hsdev->hdev, "Skipped remaining data\n");
return 0;
}
hid_dbg(sensor_inst->hsdev->hdev, "%s received %d of %d\n", __func__,
(int) (sensor_inst->input_report_recd_size + raw_len),
sensor_inst->input_report_size);
if (!test_bit(0, &sensor_inst->misc_opened))
return 0;
if (!sensor_inst->input_report_recd_size) {
int required_size = sizeof(struct hid_sensor_sample) +
sensor_inst->input_report_size;
header.usage_id = hsdev->usage;
header.raw_len = sensor_inst->input_report_size;
header.timestamp = ktime_get_real_ns();
if (kfifo_avail(&sensor_inst->data_fifo) >= required_size) {
kfifo_in(&sensor_inst->data_fifo,
(unsigned char *)&header,
sizeof(header));
} else
sensor_inst->input_skip_sample = true;
}
if (kfifo_avail(&sensor_inst->data_fifo) >= raw_len)
kfifo_in(&sensor_inst->data_fifo, (unsigned char *)raw_data,
raw_len);
sensor_inst->input_report_recd_size += raw_len;
return 0;
}
static int hid_sensor_send_event(struct hid_sensor_hub_device *hsdev,
unsigned usage_id, void *priv)
{
struct hid_sensor_custom *sensor_inst = platform_get_drvdata(priv);
if (!test_bit(0, &sensor_inst->misc_opened))
return 0;
sensor_inst->input_report_recd_size = 0;
sensor_inst->input_skip_sample = false;
wake_up(&sensor_inst->wait);
return 0;
}
static int hid_sensor_custom_add_field(struct hid_sensor_custom *sensor_inst,
int index, int report_type,
struct hid_report *report,
struct hid_field *field)
{
struct hid_sensor_custom_field *sensor_field;
void *fields;
fields = krealloc(sensor_inst->fields,
(sensor_inst->sensor_field_count + 1) *
sizeof(struct hid_sensor_custom_field), GFP_KERNEL);
if (!fields) {
kfree(sensor_inst->fields);
return -ENOMEM;
}
sensor_inst->fields = fields;
sensor_field = &sensor_inst->fields[sensor_inst->sensor_field_count];
sensor_field->attribute.usage_id = sensor_inst->hsdev->usage;
if (field->logical)
sensor_field->attribute.attrib_id = field->logical;
else
sensor_field->attribute.attrib_id = field->usage[0].hid;
sensor_field->attribute.index = index;
sensor_field->attribute.report_id = report->id;
sensor_field->attribute.units = field->unit;
sensor_field->attribute.unit_expo = field->unit_exponent;
sensor_field->attribute.size = (field->report_size / 8);
sensor_field->attribute.logical_minimum = field->logical_minimum;
sensor_field->attribute.logical_maximum = field->logical_maximum;
if (report_type == HID_FEATURE_REPORT)
snprintf(sensor_field->group_name,
sizeof(sensor_field->group_name), "feature-%x-%x",
sensor_field->attribute.index,
sensor_field->attribute.attrib_id);
else if (report_type == HID_INPUT_REPORT) {
snprintf(sensor_field->group_name,
sizeof(sensor_field->group_name),
"input-%x-%x", sensor_field->attribute.index,
sensor_field->attribute.attrib_id);
sensor_inst->input_field_count++;
sensor_inst->input_report_size += (field->report_size *
field->report_count) / 8;
}
memset(&sensor_field->hid_custom_attribute_group, 0,
sizeof(struct attribute_group));
sensor_inst->sensor_field_count++;
return 0;
}
static int hid_sensor_custom_add_fields(struct hid_sensor_custom *sensor_inst,
struct hid_report_enum *report_enum,
int report_type)
{
int i;
int ret;
struct hid_report *report;
struct hid_field *field;
struct hid_sensor_hub_device *hsdev = sensor_inst->hsdev;
list_for_each_entry(report, &report_enum->report_list, list) {
for (i = 0; i < report->maxfield; ++i) {
field = report->field[i];
if (field->maxusage &&
((field->usage[0].collection_index >=
hsdev->start_collection_index) &&
(field->usage[0].collection_index <
hsdev->end_collection_index))) {
ret = hid_sensor_custom_add_field(sensor_inst,
i,
report_type,
report,
field);
if (ret)
return ret;
}
}
}
return 0;
}
static int hid_sensor_custom_add_attributes(struct hid_sensor_custom
*sensor_inst)
{
struct hid_sensor_hub_device *hsdev = sensor_inst->hsdev;
struct hid_device *hdev = hsdev->hdev;
int ret = -1;
int i, j;
for (j = 0; j < HID_REPORT_TYPES; ++j) {
if (j == HID_OUTPUT_REPORT)
continue;
ret = hid_sensor_custom_add_fields(sensor_inst,
&hdev->report_enum[j], j);
if (ret)
return ret;
}
for (i = 0; i < sensor_inst->sensor_field_count; ++i) {
j = 0;
while (j < HID_CUSTOM_TOTAL_ATTRS &&
hid_custom_attrs[j].name) {
struct device_attribute *device_attr;
device_attr = &sensor_inst->fields[i].sd_attrs[j];
snprintf((char *)&sensor_inst->fields[i].attr_name[j],
HID_CUSTOM_NAME_LENGTH, "%s-%s",
sensor_inst->fields[i].group_name,
hid_custom_attrs[j].name);
sysfs_attr_init(&device_attr->attr);
device_attr->attr.name =
(char *)&sensor_inst->fields[i].attr_name[j];
device_attr->attr.mode = hid_custom_attrs[j].mode;
device_attr->show = show_value;
if (hid_custom_attrs[j].mode & S_IWUSR)
device_attr->store = store_value;
sensor_inst->fields[i].attrs[j] = &device_attr->attr;
++j;
}
sensor_inst->fields[i].attrs[j] = NULL;
sensor_inst->fields[i].hid_custom_attribute_group.attrs =
sensor_inst->fields[i].attrs;
sensor_inst->fields[i].hid_custom_attribute_group.name =
sensor_inst->fields[i].group_name;
ret = sysfs_create_group(&sensor_inst->pdev->dev.kobj,
&sensor_inst->fields[i].
hid_custom_attribute_group);
if (ret)
break;
if (sensor_inst->fields[i].attribute.attrib_id ==
HID_USAGE_SENSOR_PROY_POWER_STATE)
sensor_inst->power_state = &sensor_inst->fields[i];
else if (sensor_inst->fields[i].attribute.attrib_id ==
HID_USAGE_SENSOR_PROP_REPORT_STATE)
sensor_inst->report_state = &sensor_inst->fields[i];
}
return ret;
}
static void hid_sensor_custom_remove_attributes(struct hid_sensor_custom *
sensor_inst)
{
int i;
for (i = 0; i < sensor_inst->sensor_field_count; ++i)
sysfs_remove_group(&sensor_inst->pdev->dev.kobj,
&sensor_inst->fields[i].
hid_custom_attribute_group);
kfree(sensor_inst->fields);
}
static ssize_t hid_sensor_custom_read(struct file *file, char __user *buf,
size_t count, loff_t *f_ps)
{
struct hid_sensor_custom *sensor_inst;
unsigned int copied;
int ret;
sensor_inst = container_of(file->private_data,
struct hid_sensor_custom, custom_dev);
if (count < sizeof(struct hid_sensor_sample))
return -EINVAL;
do {
if (kfifo_is_empty(&sensor_inst->data_fifo)) {
if (file->f_flags & O_NONBLOCK)
return -EAGAIN;
ret = wait_event_interruptible(sensor_inst->wait,
!kfifo_is_empty(&sensor_inst->data_fifo));
if (ret)
return ret;
}
ret = kfifo_to_user(&sensor_inst->data_fifo, buf, count,
&copied);
if (ret)
return ret;
} while (copied == 0);
return copied;
}
static int hid_sensor_custom_release(struct inode *inode, struct file *file)
{
struct hid_sensor_custom *sensor_inst;
sensor_inst = container_of(file->private_data,
struct hid_sensor_custom, custom_dev);
clear_bit(0, &sensor_inst->misc_opened);
return 0;
}
static int hid_sensor_custom_open(struct inode *inode, struct file *file)
{
struct hid_sensor_custom *sensor_inst;
sensor_inst = container_of(file->private_data,
struct hid_sensor_custom, custom_dev);
if (test_and_set_bit(0, &sensor_inst->misc_opened))
return -EBUSY;
return nonseekable_open(inode, file);
}
static unsigned int hid_sensor_custom_poll(struct file *file,
struct poll_table_struct *wait)
{
struct hid_sensor_custom *sensor_inst;
unsigned int mask = 0;
sensor_inst = container_of(file->private_data,
struct hid_sensor_custom, custom_dev);
poll_wait(file, &sensor_inst->wait, wait);
if (!kfifo_is_empty(&sensor_inst->data_fifo))
mask = POLLIN | POLLRDNORM;
return mask;
}
static int hid_sensor_custom_dev_if_add(struct hid_sensor_custom *sensor_inst)
{
int ret;
ret = kfifo_alloc(&sensor_inst->data_fifo, HID_CUSTOM_FIFO_SIZE,
GFP_KERNEL);
if (ret)
return ret;
init_waitqueue_head(&sensor_inst->wait);
sensor_inst->custom_dev.minor = MISC_DYNAMIC_MINOR;
sensor_inst->custom_dev.name = dev_name(&sensor_inst->pdev->dev);
sensor_inst->custom_dev.fops = &hid_sensor_custom_fops,
ret = misc_register(&sensor_inst->custom_dev);
if (ret) {
kfifo_free(&sensor_inst->data_fifo);
return ret;
}
return 0;
}
static void hid_sensor_custom_dev_if_remove(struct hid_sensor_custom
*sensor_inst)
{
wake_up(&sensor_inst->wait);
misc_deregister(&sensor_inst->custom_dev);
kfifo_free(&sensor_inst->data_fifo);
}
static int hid_sensor_custom_probe(struct platform_device *pdev)
{
struct hid_sensor_custom *sensor_inst;
struct hid_sensor_hub_device *hsdev = pdev->dev.platform_data;
int ret;
sensor_inst = devm_kzalloc(&pdev->dev, sizeof(*sensor_inst),
GFP_KERNEL);
if (!sensor_inst)
return -ENOMEM;
sensor_inst->callbacks.capture_sample = hid_sensor_capture_sample;
sensor_inst->callbacks.send_event = hid_sensor_send_event;
sensor_inst->callbacks.pdev = pdev;
sensor_inst->hsdev = hsdev;
sensor_inst->pdev = pdev;
mutex_init(&sensor_inst->mutex);
platform_set_drvdata(pdev, sensor_inst);
ret = sensor_hub_register_callback(hsdev, hsdev->usage,
&sensor_inst->callbacks);
if (ret < 0) {
dev_err(&pdev->dev, "callback reg failed\n");
return ret;
}
ret = sysfs_create_group(&sensor_inst->pdev->dev.kobj,
&enable_sensor_attr_group);
if (ret)
goto err_remove_callback;
ret = hid_sensor_custom_add_attributes(sensor_inst);
if (ret)
goto err_remove_group;
ret = hid_sensor_custom_dev_if_add(sensor_inst);
if (ret)
goto err_remove_attributes;
return 0;
err_remove_attributes:
hid_sensor_custom_remove_attributes(sensor_inst);
err_remove_group:
sysfs_remove_group(&sensor_inst->pdev->dev.kobj,
&enable_sensor_attr_group);
err_remove_callback:
sensor_hub_remove_callback(hsdev, hsdev->usage);
return ret;
}
static int hid_sensor_custom_remove(struct platform_device *pdev)
{
struct hid_sensor_custom *sensor_inst = platform_get_drvdata(pdev);
struct hid_sensor_hub_device *hsdev = pdev->dev.platform_data;
hid_sensor_custom_dev_if_remove(sensor_inst);
hid_sensor_custom_remove_attributes(sensor_inst);
sysfs_remove_group(&sensor_inst->pdev->dev.kobj,
&enable_sensor_attr_group);
sensor_hub_remove_callback(hsdev, hsdev->usage);
return 0;
}
