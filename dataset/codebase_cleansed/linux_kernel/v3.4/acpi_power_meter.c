static int can_cap_in_hardware(void)
{
return force_cap_on || cap_in_hardware;
}
static int update_avg_interval(struct acpi_power_meter_resource *resource)
{
unsigned long long data;
acpi_status status;
status = acpi_evaluate_integer(resource->acpi_dev->handle, "_GAI",
NULL, &data);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _GAI"));
return -ENODEV;
}
resource->avg_interval = data;
return 0;
}
static ssize_t show_avg_interval(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct acpi_device *acpi_dev = to_acpi_device(dev);
struct acpi_power_meter_resource *resource = acpi_dev->driver_data;
mutex_lock(&resource->lock);
update_avg_interval(resource);
mutex_unlock(&resource->lock);
return sprintf(buf, "%llu\n", resource->avg_interval);
}
static ssize_t set_avg_interval(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct acpi_device *acpi_dev = to_acpi_device(dev);
struct acpi_power_meter_resource *resource = acpi_dev->driver_data;
union acpi_object arg0 = { ACPI_TYPE_INTEGER };
struct acpi_object_list args = { 1, &arg0 };
int res;
unsigned long temp;
unsigned long long data;
acpi_status status;
res = kstrtoul(buf, 10, &temp);
if (res)
return res;
if (temp > resource->caps.max_avg_interval ||
temp < resource->caps.min_avg_interval)
return -EINVAL;
arg0.integer.value = temp;
mutex_lock(&resource->lock);
status = acpi_evaluate_integer(resource->acpi_dev->handle, "_PAI",
&args, &data);
if (!ACPI_FAILURE(status))
resource->avg_interval = temp;
mutex_unlock(&resource->lock);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _PAI"));
return -EINVAL;
}
if (data)
return -EINVAL;
return count;
}
static int update_cap(struct acpi_power_meter_resource *resource)
{
unsigned long long data;
acpi_status status;
status = acpi_evaluate_integer(resource->acpi_dev->handle, "_GHL",
NULL, &data);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _GHL"));
return -ENODEV;
}
resource->cap = data;
return 0;
}
static ssize_t show_cap(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct acpi_device *acpi_dev = to_acpi_device(dev);
struct acpi_power_meter_resource *resource = acpi_dev->driver_data;
mutex_lock(&resource->lock);
update_cap(resource);
mutex_unlock(&resource->lock);
return sprintf(buf, "%llu\n", resource->cap * 1000);
}
static ssize_t set_cap(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct acpi_device *acpi_dev = to_acpi_device(dev);
struct acpi_power_meter_resource *resource = acpi_dev->driver_data;
union acpi_object arg0 = { ACPI_TYPE_INTEGER };
struct acpi_object_list args = { 1, &arg0 };
int res;
unsigned long temp;
unsigned long long data;
acpi_status status;
res = kstrtoul(buf, 10, &temp);
if (res)
return res;
temp /= 1000;
if (temp > resource->caps.max_cap || temp < resource->caps.min_cap)
return -EINVAL;
arg0.integer.value = temp;
mutex_lock(&resource->lock);
status = acpi_evaluate_integer(resource->acpi_dev->handle, "_SHL",
&args, &data);
if (!ACPI_FAILURE(status))
resource->cap = temp;
mutex_unlock(&resource->lock);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _SHL"));
return -EINVAL;
}
if (data)
return -EINVAL;
return count;
}
static int set_acpi_trip(struct acpi_power_meter_resource *resource)
{
union acpi_object arg_objs[] = {
{ACPI_TYPE_INTEGER},
{ACPI_TYPE_INTEGER}
};
struct acpi_object_list args = { 2, arg_objs };
unsigned long long data;
acpi_status status;
if (resource->trip[0] < 0 || resource->trip[1] < 0)
return 0;
arg_objs[0].integer.value = resource->trip[1];
arg_objs[1].integer.value = resource->trip[0];
status = acpi_evaluate_integer(resource->acpi_dev->handle, "_PTP",
&args, &data);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _PTP"));
return -EINVAL;
}
if (data)
return -EINVAL;
return 0;
}
static ssize_t set_trip(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct acpi_device *acpi_dev = to_acpi_device(dev);
struct acpi_power_meter_resource *resource = acpi_dev->driver_data;
int res;
unsigned long temp;
res = kstrtoul(buf, 10, &temp);
if (res)
return res;
temp /= 1000;
if (temp < 0)
return -EINVAL;
mutex_lock(&resource->lock);
resource->trip[attr->index - 7] = temp;
res = set_acpi_trip(resource);
mutex_unlock(&resource->lock);
if (res)
return res;
return count;
}
static int update_meter(struct acpi_power_meter_resource *resource)
{
unsigned long long data;
acpi_status status;
unsigned long local_jiffies = jiffies;
if (time_before(local_jiffies, resource->sensors_last_updated +
msecs_to_jiffies(resource->caps.sampling_time)) &&
resource->sensors_valid)
return 0;
status = acpi_evaluate_integer(resource->acpi_dev->handle, "_PMM",
NULL, &data);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _PMM"));
return -ENODEV;
}
resource->power = data;
resource->sensors_valid = 1;
resource->sensors_last_updated = jiffies;
return 0;
}
static ssize_t show_power(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct acpi_device *acpi_dev = to_acpi_device(dev);
struct acpi_power_meter_resource *resource = acpi_dev->driver_data;
mutex_lock(&resource->lock);
update_meter(resource);
mutex_unlock(&resource->lock);
return sprintf(buf, "%llu\n", resource->power * 1000);
}
static ssize_t show_str(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct acpi_device *acpi_dev = to_acpi_device(dev);
struct acpi_power_meter_resource *resource = acpi_dev->driver_data;
acpi_string val;
switch (attr->index) {
case 0:
val = resource->model_number;
break;
case 1:
val = resource->serial_number;
break;
case 2:
val = resource->oem_info;
break;
default:
BUG();
val = "";
}
return sprintf(buf, "%s\n", val);
}
static ssize_t show_val(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct acpi_device *acpi_dev = to_acpi_device(dev);
struct acpi_power_meter_resource *resource = acpi_dev->driver_data;
u64 val = 0;
switch (attr->index) {
case 0:
val = resource->caps.min_avg_interval;
break;
case 1:
val = resource->caps.max_avg_interval;
break;
case 2:
val = resource->caps.min_cap * 1000;
break;
case 3:
val = resource->caps.max_cap * 1000;
break;
case 4:
if (resource->caps.hysteresis == UNKNOWN_HYSTERESIS)
return sprintf(buf, "unknown\n");
val = resource->caps.hysteresis * 1000;
break;
case 5:
if (resource->caps.flags & POWER_METER_IS_BATTERY)
val = 1;
else
val = 0;
break;
case 6:
if (resource->power > resource->cap)
val = 1;
else
val = 0;
break;
case 7:
case 8:
if (resource->trip[attr->index - 7] < 0)
return sprintf(buf, "unknown\n");
val = resource->trip[attr->index - 7] * 1000;
break;
default:
BUG();
}
return sprintf(buf, "%llu\n", val);
}
static ssize_t show_accuracy(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct acpi_device *acpi_dev = to_acpi_device(dev);
struct acpi_power_meter_resource *resource = acpi_dev->driver_data;
unsigned int acc = resource->caps.accuracy;
return sprintf(buf, "%u.%u%%\n", acc / 1000, acc % 1000);
}
static ssize_t show_name(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
return sprintf(buf, "%s\n", ACPI_POWER_METER_NAME);
}
static void remove_domain_devices(struct acpi_power_meter_resource *resource)
{
int i;
if (!resource->num_domain_devices)
return;
for (i = 0; i < resource->num_domain_devices; i++) {
struct acpi_device *obj = resource->domain_devices[i];
if (!obj)
continue;
sysfs_remove_link(resource->holders_dir,
kobject_name(&obj->dev.kobj));
put_device(&obj->dev);
}
kfree(resource->domain_devices);
kobject_put(resource->holders_dir);
resource->num_domain_devices = 0;
}
static int read_domain_devices(struct acpi_power_meter_resource *resource)
{
int res = 0;
int i;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *pss;
acpi_status status;
status = acpi_evaluate_object(resource->acpi_dev->handle, "_PMD", NULL,
&buffer);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _PMD"));
return -ENODEV;
}
pss = buffer.pointer;
if (!pss ||
pss->type != ACPI_TYPE_PACKAGE) {
dev_err(&resource->acpi_dev->dev, ACPI_POWER_METER_NAME
"Invalid _PMD data\n");
res = -EFAULT;
goto end;
}
if (!pss->package.count)
goto end;
resource->domain_devices = kzalloc(sizeof(struct acpi_device *) *
pss->package.count, GFP_KERNEL);
if (!resource->domain_devices) {
res = -ENOMEM;
goto end;
}
resource->holders_dir = kobject_create_and_add("measures",
&resource->acpi_dev->dev.kobj);
if (!resource->holders_dir) {
res = -ENOMEM;
goto exit_free;
}
resource->num_domain_devices = pss->package.count;
for (i = 0; i < pss->package.count; i++) {
struct acpi_device *obj;
union acpi_object *element = &(pss->package.elements[i]);
if (element->type != ACPI_TYPE_LOCAL_REFERENCE)
continue;
resource->domain_devices[i] = NULL;
status = acpi_bus_get_device(element->reference.handle,
&resource->domain_devices[i]);
if (ACPI_FAILURE(status))
continue;
obj = resource->domain_devices[i];
get_device(&obj->dev);
res = sysfs_create_link(resource->holders_dir, &obj->dev.kobj,
kobject_name(&obj->dev.kobj));
if (res) {
put_device(&obj->dev);
resource->domain_devices[i] = NULL;
}
}
res = 0;
goto end;
exit_free:
kfree(resource->domain_devices);
end:
kfree(buffer.pointer);
return res;
}
static int register_ro_attrs(struct acpi_power_meter_resource *resource,
struct ro_sensor_template *ro)
{
struct device *dev = &resource->acpi_dev->dev;
struct sensor_device_attribute *sensors =
&resource->sensors[resource->num_sensors];
int res = 0;
while (ro->label) {
sensors->dev_attr.attr.name = ro->label;
sensors->dev_attr.attr.mode = S_IRUGO;
sensors->dev_attr.show = ro->show;
sensors->index = ro->index;
sysfs_attr_init(&sensors->dev_attr.attr);
res = device_create_file(dev, &sensors->dev_attr);
if (res) {
sensors->dev_attr.attr.name = NULL;
goto error;
}
sensors++;
resource->num_sensors++;
ro++;
}
error:
return res;
}
static int register_rw_attrs(struct acpi_power_meter_resource *resource,
struct rw_sensor_template *rw)
{
struct device *dev = &resource->acpi_dev->dev;
struct sensor_device_attribute *sensors =
&resource->sensors[resource->num_sensors];
int res = 0;
while (rw->label) {
sensors->dev_attr.attr.name = rw->label;
sensors->dev_attr.attr.mode = S_IRUGO | S_IWUSR;
sensors->dev_attr.show = rw->show;
sensors->dev_attr.store = rw->set;
sensors->index = rw->index;
sysfs_attr_init(&sensors->dev_attr.attr);
res = device_create_file(dev, &sensors->dev_attr);
if (res) {
sensors->dev_attr.attr.name = NULL;
goto error;
}
sensors++;
resource->num_sensors++;
rw++;
}
error:
return res;
}
static void remove_attrs(struct acpi_power_meter_resource *resource)
{
int i;
for (i = 0; i < resource->num_sensors; i++) {
if (!resource->sensors[i].dev_attr.attr.name)
continue;
device_remove_file(&resource->acpi_dev->dev,
&resource->sensors[i].dev_attr);
}
remove_domain_devices(resource);
resource->num_sensors = 0;
}
static int setup_attrs(struct acpi_power_meter_resource *resource)
{
int res = 0;
res = read_domain_devices(resource);
if (res)
return res;
if (resource->caps.flags & POWER_METER_CAN_MEASURE) {
res = register_ro_attrs(resource, meter_ro_attrs);
if (res)
goto error;
res = register_rw_attrs(resource, meter_rw_attrs);
if (res)
goto error;
}
if (resource->caps.flags & POWER_METER_CAN_CAP) {
if (!can_cap_in_hardware()) {
dev_err(&resource->acpi_dev->dev,
"Ignoring unsafe software power cap!\n");
goto skip_unsafe_cap;
}
if (resource->caps.configurable_cap) {
res = register_rw_attrs(resource, rw_cap_attrs);
if (res)
goto error;
} else {
res = register_ro_attrs(resource, ro_cap_attrs);
if (res)
goto error;
}
res = register_ro_attrs(resource, misc_cap_attrs);
if (res)
goto error;
}
skip_unsafe_cap:
if (resource->caps.flags & POWER_METER_CAN_TRIP) {
res = register_rw_attrs(resource, trip_attrs);
if (res)
goto error;
}
res = register_ro_attrs(resource, misc_attrs);
if (res)
goto error;
return res;
error:
remove_attrs(resource);
return res;
}
static void free_capabilities(struct acpi_power_meter_resource *resource)
{
acpi_string *str;
int i;
str = &resource->model_number;
for (i = 0; i < 3; i++, str++)
kfree(*str);
}
static int read_capabilities(struct acpi_power_meter_resource *resource)
{
int res = 0;
int i;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_buffer state = { 0, NULL };
struct acpi_buffer format = { sizeof("NNNNNNNNNNN"), "NNNNNNNNNNN" };
union acpi_object *pss;
acpi_string *str;
acpi_status status;
status = acpi_evaluate_object(resource->acpi_dev->handle, "_PMC", NULL,
&buffer);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Evaluating _PMC"));
return -ENODEV;
}
pss = buffer.pointer;
if (!pss ||
pss->type != ACPI_TYPE_PACKAGE ||
pss->package.count != 14) {
dev_err(&resource->acpi_dev->dev, ACPI_POWER_METER_NAME
"Invalid _PMC data\n");
res = -EFAULT;
goto end;
}
state.length = sizeof(struct acpi_power_meter_capabilities);
state.pointer = &resource->caps;
status = acpi_extract_package(pss, &format, &state);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Invalid data"));
res = -EFAULT;
goto end;
}
if (resource->caps.units) {
dev_err(&resource->acpi_dev->dev, ACPI_POWER_METER_NAME
"Unknown units %llu.\n",
resource->caps.units);
res = -EINVAL;
goto end;
}
str = &resource->model_number;
for (i = 11; i < 14; i++) {
union acpi_object *element = &(pss->package.elements[i]);
if (element->type != ACPI_TYPE_STRING) {
res = -EINVAL;
goto error;
}
*str = kzalloc(sizeof(u8) * (element->string.length + 1),
GFP_KERNEL);
if (!*str) {
res = -ENOMEM;
goto error;
}
strncpy(*str, element->string.pointer, element->string.length);
str++;
}
dev_info(&resource->acpi_dev->dev, "Found ACPI power meter.\n");
goto end;
error:
str = &resource->model_number;
for (i = 0; i < 3; i++, str++)
kfree(*str);
end:
kfree(buffer.pointer);
return res;
}
static void acpi_power_meter_notify(struct acpi_device *device, u32 event)
{
struct acpi_power_meter_resource *resource;
int res;
if (!device || !acpi_driver_data(device))
return;
resource = acpi_driver_data(device);
mutex_lock(&resource->lock);
switch (event) {
case METER_NOTIFY_CONFIG:
free_capabilities(resource);
res = read_capabilities(resource);
if (res)
break;
remove_attrs(resource);
setup_attrs(resource);
break;
case METER_NOTIFY_TRIP:
sysfs_notify(&device->dev.kobj, NULL, POWER_AVERAGE_NAME);
update_meter(resource);
break;
case METER_NOTIFY_CAP:
sysfs_notify(&device->dev.kobj, NULL, POWER_CAP_NAME);
update_cap(resource);
break;
case METER_NOTIFY_INTERVAL:
sysfs_notify(&device->dev.kobj, NULL, POWER_AVG_INTERVAL_NAME);
update_avg_interval(resource);
break;
case METER_NOTIFY_CAPPING:
sysfs_notify(&device->dev.kobj, NULL, POWER_ALARM_NAME);
dev_info(&device->dev, "Capping in progress.\n");
break;
default:
BUG();
}
mutex_unlock(&resource->lock);
acpi_bus_generate_netlink_event(ACPI_POWER_METER_CLASS,
dev_name(&device->dev), event, 0);
}
static int acpi_power_meter_add(struct acpi_device *device)
{
int res;
struct acpi_power_meter_resource *resource;
if (!device)
return -EINVAL;
resource = kzalloc(sizeof(struct acpi_power_meter_resource),
GFP_KERNEL);
if (!resource)
return -ENOMEM;
resource->sensors_valid = 0;
resource->acpi_dev = device;
mutex_init(&resource->lock);
strcpy(acpi_device_name(device), ACPI_POWER_METER_DEVICE_NAME);
strcpy(acpi_device_class(device), ACPI_POWER_METER_CLASS);
device->driver_data = resource;
free_capabilities(resource);
res = read_capabilities(resource);
if (res)
goto exit_free;
resource->trip[0] = resource->trip[1] = -1;
res = setup_attrs(resource);
if (res)
goto exit_free;
resource->hwmon_dev = hwmon_device_register(&device->dev);
if (IS_ERR(resource->hwmon_dev)) {
res = PTR_ERR(resource->hwmon_dev);
goto exit_remove;
}
res = 0;
goto exit;
exit_remove:
remove_attrs(resource);
exit_free:
kfree(resource);
exit:
return res;
}
static int acpi_power_meter_remove(struct acpi_device *device, int type)
{
struct acpi_power_meter_resource *resource;
if (!device || !acpi_driver_data(device))
return -EINVAL;
resource = acpi_driver_data(device);
hwmon_device_unregister(resource->hwmon_dev);
free_capabilities(resource);
remove_attrs(resource);
kfree(resource);
return 0;
}
static int acpi_power_meter_resume(struct acpi_device *device)
{
struct acpi_power_meter_resource *resource;
if (!device || !acpi_driver_data(device))
return -EINVAL;
resource = acpi_driver_data(device);
free_capabilities(resource);
read_capabilities(resource);
return 0;
}
static int __init enable_cap_knobs(const struct dmi_system_id *d)
{
cap_in_hardware = 1;
return 0;
}
static int __init acpi_power_meter_init(void)
{
int result;
if (acpi_disabled)
return -ENODEV;
dmi_check_system(pm_dmi_table);
result = acpi_bus_register_driver(&acpi_power_meter_driver);
if (result < 0)
return -ENODEV;
return 0;
}
static void __exit acpi_power_meter_exit(void)
{
acpi_bus_unregister_driver(&acpi_power_meter_driver);
}
