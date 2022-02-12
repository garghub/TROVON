static ssize_t
type_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct thermal_zone_device *tz = to_thermal_zone(dev);
return sprintf(buf, "%s\n", tz->type);
}
static ssize_t
temp_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct thermal_zone_device *tz = to_thermal_zone(dev);
int temperature, ret;
ret = thermal_zone_get_temp(tz, &temperature);
if (ret)
return ret;
return sprintf(buf, "%d\n", temperature);
}
static ssize_t
mode_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct thermal_zone_device *tz = to_thermal_zone(dev);
enum thermal_device_mode mode;
int result;
if (!tz->ops->get_mode)
return -EPERM;
result = tz->ops->get_mode(tz, &mode);
if (result)
return result;
return sprintf(buf, "%s\n", mode == THERMAL_DEVICE_ENABLED ? "enabled"
: "disabled");
}
static ssize_t
mode_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct thermal_zone_device *tz = to_thermal_zone(dev);
int result;
if (!tz->ops->set_mode)
return -EPERM;
if (!strncmp(buf, "enabled", sizeof("enabled") - 1))
result = tz->ops->set_mode(tz, THERMAL_DEVICE_ENABLED);
else if (!strncmp(buf, "disabled", sizeof("disabled") - 1))
result = tz->ops->set_mode(tz, THERMAL_DEVICE_DISABLED);
else
result = -EINVAL;
if (result)
return result;
return count;
}
static ssize_t
trip_point_type_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct thermal_zone_device *tz = to_thermal_zone(dev);
enum thermal_trip_type type;
int trip, result;
if (!tz->ops->get_trip_type)
return -EPERM;
if (sscanf(attr->attr.name, "trip_point_%d_type", &trip) != 1)
return -EINVAL;
result = tz->ops->get_trip_type(tz, trip, &type);
if (result)
return result;
switch (type) {
case THERMAL_TRIP_CRITICAL:
return sprintf(buf, "critical\n");
case THERMAL_TRIP_HOT:
return sprintf(buf, "hot\n");
case THERMAL_TRIP_PASSIVE:
return sprintf(buf, "passive\n");
case THERMAL_TRIP_ACTIVE:
return sprintf(buf, "active\n");
default:
return sprintf(buf, "unknown\n");
}
}
static ssize_t
trip_point_temp_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct thermal_zone_device *tz = to_thermal_zone(dev);
int trip, ret;
int temperature;
if (!tz->ops->set_trip_temp)
return -EPERM;
if (sscanf(attr->attr.name, "trip_point_%d_temp", &trip) != 1)
return -EINVAL;
if (kstrtoint(buf, 10, &temperature))
return -EINVAL;
ret = tz->ops->set_trip_temp(tz, trip, temperature);
if (ret)
return ret;
thermal_zone_device_update(tz, THERMAL_EVENT_UNSPECIFIED);
return count;
}
static ssize_t
trip_point_temp_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct thermal_zone_device *tz = to_thermal_zone(dev);
int trip, ret;
int temperature;
if (!tz->ops->get_trip_temp)
return -EPERM;
if (sscanf(attr->attr.name, "trip_point_%d_temp", &trip) != 1)
return -EINVAL;
ret = tz->ops->get_trip_temp(tz, trip, &temperature);
if (ret)
return ret;
return sprintf(buf, "%d\n", temperature);
}
static ssize_t
trip_point_hyst_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct thermal_zone_device *tz = to_thermal_zone(dev);
int trip, ret;
int temperature;
if (!tz->ops->set_trip_hyst)
return -EPERM;
if (sscanf(attr->attr.name, "trip_point_%d_hyst", &trip) != 1)
return -EINVAL;
if (kstrtoint(buf, 10, &temperature))
return -EINVAL;
ret = tz->ops->set_trip_hyst(tz, trip, temperature);
if (!ret)
thermal_zone_set_trips(tz);
return ret ? ret : count;
}
static ssize_t
trip_point_hyst_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct thermal_zone_device *tz = to_thermal_zone(dev);
int trip, ret;
int temperature;
if (!tz->ops->get_trip_hyst)
return -EPERM;
if (sscanf(attr->attr.name, "trip_point_%d_hyst", &trip) != 1)
return -EINVAL;
ret = tz->ops->get_trip_hyst(tz, trip, &temperature);
return ret ? ret : sprintf(buf, "%d\n", temperature);
}
static ssize_t
passive_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct thermal_zone_device *tz = to_thermal_zone(dev);
int state;
if (sscanf(buf, "%d\n", &state) != 1)
return -EINVAL;
if (state && state < 1000)
return -EINVAL;
if (state && !tz->forced_passive) {
if (!tz->passive_delay)
tz->passive_delay = 1000;
thermal_zone_device_rebind_exception(tz, "Processor",
sizeof("Processor"));
} else if (!state && tz->forced_passive) {
tz->passive_delay = 0;
thermal_zone_device_unbind_exception(tz, "Processor",
sizeof("Processor"));
}
tz->forced_passive = state;
thermal_zone_device_update(tz, THERMAL_EVENT_UNSPECIFIED);
return count;
}
static ssize_t
passive_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct thermal_zone_device *tz = to_thermal_zone(dev);
return sprintf(buf, "%d\n", tz->forced_passive);
}
static ssize_t
policy_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct thermal_zone_device *tz = to_thermal_zone(dev);
char name[THERMAL_NAME_LENGTH];
int ret;
snprintf(name, sizeof(name), "%s", buf);
ret = thermal_zone_device_set_policy(tz, name);
if (!ret)
ret = count;
return ret;
}
static ssize_t
policy_show(struct device *dev, struct device_attribute *devattr, char *buf)
{
struct thermal_zone_device *tz = to_thermal_zone(dev);
return sprintf(buf, "%s\n", tz->governor->name);
}
static ssize_t
available_policies_show(struct device *dev, struct device_attribute *devattr,
char *buf)
{
return thermal_build_list_of_policies(buf);
}
static ssize_t
emul_temp_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct thermal_zone_device *tz = to_thermal_zone(dev);
int ret = 0;
int temperature;
if (kstrtoint(buf, 10, &temperature))
return -EINVAL;
if (!tz->ops->set_emul_temp) {
mutex_lock(&tz->lock);
tz->emul_temperature = temperature;
mutex_unlock(&tz->lock);
} else {
ret = tz->ops->set_emul_temp(tz, temperature);
}
if (!ret)
thermal_zone_device_update(tz, THERMAL_EVENT_UNSPECIFIED);
return ret ? ret : count;
}
static ssize_t
sustainable_power_show(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct thermal_zone_device *tz = to_thermal_zone(dev);
if (tz->tzp)
return sprintf(buf, "%u\n", tz->tzp->sustainable_power);
else
return -EIO;
}
static ssize_t
sustainable_power_store(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct thermal_zone_device *tz = to_thermal_zone(dev);
u32 sustainable_power;
if (!tz->tzp)
return -EIO;
if (kstrtou32(buf, 10, &sustainable_power))
return -EINVAL;
tz->tzp->sustainable_power = sustainable_power;
return count;
}
static umode_t thermal_zone_mode_is_visible(struct kobject *kobj,
struct attribute *attr,
int attrno)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct thermal_zone_device *tz;
tz = container_of(dev, struct thermal_zone_device, device);
if (tz->ops->get_mode)
return attr->mode;
return 0;
}
static umode_t thermal_zone_passive_is_visible(struct kobject *kobj,
struct attribute *attr,
int attrno)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct thermal_zone_device *tz;
enum thermal_trip_type trip_type;
int count, passive = 0;
tz = container_of(dev, struct thermal_zone_device, device);
for (count = 0; count < tz->trips && !passive; count++) {
tz->ops->get_trip_type(tz, count, &trip_type);
if (trip_type == THERMAL_TRIP_PASSIVE)
passive = 1;
}
if (!passive)
return attr->mode;
return 0;
}
static int create_trip_attrs(struct thermal_zone_device *tz, int mask)
{
struct attribute **attrs;
int indx;
if (tz->trips <= 0)
return -EINVAL;
tz->trip_type_attrs = kcalloc(tz->trips, sizeof(*tz->trip_type_attrs),
GFP_KERNEL);
if (!tz->trip_type_attrs)
return -ENOMEM;
tz->trip_temp_attrs = kcalloc(tz->trips, sizeof(*tz->trip_temp_attrs),
GFP_KERNEL);
if (!tz->trip_temp_attrs) {
kfree(tz->trip_type_attrs);
return -ENOMEM;
}
if (tz->ops->get_trip_hyst) {
tz->trip_hyst_attrs = kcalloc(tz->trips,
sizeof(*tz->trip_hyst_attrs),
GFP_KERNEL);
if (!tz->trip_hyst_attrs) {
kfree(tz->trip_type_attrs);
kfree(tz->trip_temp_attrs);
return -ENOMEM;
}
}
attrs = kcalloc(tz->trips * 3 + 1, sizeof(*attrs), GFP_KERNEL);
if (!attrs) {
kfree(tz->trip_type_attrs);
kfree(tz->trip_temp_attrs);
if (tz->ops->get_trip_hyst)
kfree(tz->trip_hyst_attrs);
return -ENOMEM;
}
for (indx = 0; indx < tz->trips; indx++) {
snprintf(tz->trip_type_attrs[indx].name, THERMAL_NAME_LENGTH,
"trip_point_%d_type", indx);
sysfs_attr_init(&tz->trip_type_attrs[indx].attr.attr);
tz->trip_type_attrs[indx].attr.attr.name =
tz->trip_type_attrs[indx].name;
tz->trip_type_attrs[indx].attr.attr.mode = S_IRUGO;
tz->trip_type_attrs[indx].attr.show = trip_point_type_show;
attrs[indx] = &tz->trip_type_attrs[indx].attr.attr;
snprintf(tz->trip_temp_attrs[indx].name, THERMAL_NAME_LENGTH,
"trip_point_%d_temp", indx);
sysfs_attr_init(&tz->trip_temp_attrs[indx].attr.attr);
tz->trip_temp_attrs[indx].attr.attr.name =
tz->trip_temp_attrs[indx].name;
tz->trip_temp_attrs[indx].attr.attr.mode = S_IRUGO;
tz->trip_temp_attrs[indx].attr.show = trip_point_temp_show;
if (IS_ENABLED(CONFIG_THERMAL_WRITABLE_TRIPS) &&
mask & (1 << indx)) {
tz->trip_temp_attrs[indx].attr.attr.mode |= S_IWUSR;
tz->trip_temp_attrs[indx].attr.store =
trip_point_temp_store;
}
attrs[indx + tz->trips] = &tz->trip_temp_attrs[indx].attr.attr;
if (!tz->ops->get_trip_hyst)
continue;
snprintf(tz->trip_hyst_attrs[indx].name, THERMAL_NAME_LENGTH,
"trip_point_%d_hyst", indx);
sysfs_attr_init(&tz->trip_hyst_attrs[indx].attr.attr);
tz->trip_hyst_attrs[indx].attr.attr.name =
tz->trip_hyst_attrs[indx].name;
tz->trip_hyst_attrs[indx].attr.attr.mode = S_IRUGO;
tz->trip_hyst_attrs[indx].attr.show = trip_point_hyst_show;
if (tz->ops->set_trip_hyst) {
tz->trip_hyst_attrs[indx].attr.attr.mode |= S_IWUSR;
tz->trip_hyst_attrs[indx].attr.store =
trip_point_hyst_store;
}
attrs[indx + tz->trips * 2] =
&tz->trip_hyst_attrs[indx].attr.attr;
}
attrs[tz->trips * 3] = NULL;
tz->trips_attribute_group.attrs = attrs;
return 0;
}
static void destroy_trip_attrs(struct thermal_zone_device *tz)
{
if (!tz)
return;
kfree(tz->trip_type_attrs);
kfree(tz->trip_temp_attrs);
if (tz->ops->get_trip_hyst)
kfree(tz->trip_hyst_attrs);
kfree(tz->trips_attribute_group.attrs);
}
int thermal_zone_create_device_groups(struct thermal_zone_device *tz,
int mask)
{
const struct attribute_group **groups;
int i, size, result;
size = ARRAY_SIZE(thermal_zone_attribute_groups) + 2;
groups = kcalloc(size, sizeof(*groups), GFP_KERNEL);
if (!groups)
return -ENOMEM;
for (i = 0; i < size - 2; i++)
groups[i] = thermal_zone_attribute_groups[i];
if (tz->trips) {
result = create_trip_attrs(tz, mask);
if (result) {
kfree(groups);
return result;
}
groups[size - 2] = &tz->trips_attribute_group;
}
tz->device.groups = groups;
return 0;
}
void thermal_zone_destroy_device_groups(struct thermal_zone_device *tz)
{
if (!tz)
return;
if (tz->trips)
destroy_trip_attrs(tz);
kfree(tz->device.groups);
}
static ssize_t
thermal_cooling_device_type_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct thermal_cooling_device *cdev = to_cooling_device(dev);
return sprintf(buf, "%s\n", cdev->type);
}
static ssize_t
thermal_cooling_device_max_state_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct thermal_cooling_device *cdev = to_cooling_device(dev);
unsigned long state;
int ret;
ret = cdev->ops->get_max_state(cdev, &state);
if (ret)
return ret;
return sprintf(buf, "%ld\n", state);
}
static ssize_t
thermal_cooling_device_cur_state_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct thermal_cooling_device *cdev = to_cooling_device(dev);
unsigned long state;
int ret;
ret = cdev->ops->get_cur_state(cdev, &state);
if (ret)
return ret;
return sprintf(buf, "%ld\n", state);
}
static ssize_t
thermal_cooling_device_cur_state_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct thermal_cooling_device *cdev = to_cooling_device(dev);
unsigned long state;
int result;
if (sscanf(buf, "%ld\n", &state) != 1)
return -EINVAL;
if ((long)state < 0)
return -EINVAL;
result = cdev->ops->set_cur_state(cdev, state);
if (result)
return result;
return count;
}
void thermal_cooling_device_setup_sysfs(struct thermal_cooling_device *cdev)
{
cdev->device.groups = cooling_device_attr_groups;
}
ssize_t
thermal_cooling_device_trip_point_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct thermal_instance *instance;
instance =
container_of(attr, struct thermal_instance, attr);
if (instance->trip == THERMAL_TRIPS_NONE)
return sprintf(buf, "-1\n");
else
return sprintf(buf, "%d\n", instance->trip);
}
ssize_t
thermal_cooling_device_weight_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct thermal_instance *instance;
instance = container_of(attr, struct thermal_instance, weight_attr);
return sprintf(buf, "%d\n", instance->weight);
}
ssize_t
thermal_cooling_device_weight_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct thermal_instance *instance;
int ret, weight;
ret = kstrtoint(buf, 0, &weight);
if (ret)
return ret;
instance = container_of(attr, struct thermal_instance, weight_attr);
instance->weight = weight;
return count;
}
