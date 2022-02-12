static ssize_t
name_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct thermal_hwmon_device *hwmon = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", hwmon->type);
}
static ssize_t
temp_input_show(struct device *dev, struct device_attribute *attr, char *buf)
{
int temperature;
int ret;
struct thermal_hwmon_attr *hwmon_attr
= container_of(attr, struct thermal_hwmon_attr, attr);
struct thermal_hwmon_temp *temp
= container_of(hwmon_attr, struct thermal_hwmon_temp,
temp_input);
struct thermal_zone_device *tz = temp->tz;
ret = thermal_zone_get_temp(tz, &temperature);
if (ret)
return ret;
return sprintf(buf, "%d\n", temperature);
}
static ssize_t
temp_crit_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct thermal_hwmon_attr *hwmon_attr
= container_of(attr, struct thermal_hwmon_attr, attr);
struct thermal_hwmon_temp *temp
= container_of(hwmon_attr, struct thermal_hwmon_temp,
temp_crit);
struct thermal_zone_device *tz = temp->tz;
int temperature;
int ret;
ret = tz->ops->get_trip_temp(tz, 0, &temperature);
if (ret)
return ret;
return sprintf(buf, "%d\n", temperature);
}
static struct thermal_hwmon_device *
thermal_hwmon_lookup_by_type(const struct thermal_zone_device *tz)
{
struct thermal_hwmon_device *hwmon;
mutex_lock(&thermal_hwmon_list_lock);
list_for_each_entry(hwmon, &thermal_hwmon_list, node)
if (!strcmp(hwmon->type, tz->type)) {
mutex_unlock(&thermal_hwmon_list_lock);
return hwmon;
}
mutex_unlock(&thermal_hwmon_list_lock);
return NULL;
}
static struct thermal_hwmon_temp *
thermal_hwmon_lookup_temp(const struct thermal_hwmon_device *hwmon,
const struct thermal_zone_device *tz)
{
struct thermal_hwmon_temp *temp;
mutex_lock(&thermal_hwmon_list_lock);
list_for_each_entry(temp, &hwmon->tz_list, hwmon_node)
if (temp->tz == tz) {
mutex_unlock(&thermal_hwmon_list_lock);
return temp;
}
mutex_unlock(&thermal_hwmon_list_lock);
return NULL;
}
static bool thermal_zone_crit_temp_valid(struct thermal_zone_device *tz)
{
int temp;
return tz->ops->get_crit_temp && !tz->ops->get_crit_temp(tz, &temp);
}
int thermal_add_hwmon_sysfs(struct thermal_zone_device *tz)
{
struct thermal_hwmon_device *hwmon;
struct thermal_hwmon_temp *temp;
int new_hwmon_device = 1;
int result;
hwmon = thermal_hwmon_lookup_by_type(tz);
if (hwmon) {
new_hwmon_device = 0;
goto register_sys_interface;
}
hwmon = kzalloc(sizeof(*hwmon), GFP_KERNEL);
if (!hwmon)
return -ENOMEM;
INIT_LIST_HEAD(&hwmon->tz_list);
strlcpy(hwmon->type, tz->type, THERMAL_NAME_LENGTH);
hwmon->device = hwmon_device_register(NULL);
if (IS_ERR(hwmon->device)) {
result = PTR_ERR(hwmon->device);
goto free_mem;
}
dev_set_drvdata(hwmon->device, hwmon);
result = device_create_file(hwmon->device, &dev_attr_name);
if (result)
goto free_mem;
register_sys_interface:
temp = kzalloc(sizeof(*temp), GFP_KERNEL);
if (!temp) {
result = -ENOMEM;
goto unregister_name;
}
temp->tz = tz;
hwmon->count++;
snprintf(temp->temp_input.name, sizeof(temp->temp_input.name),
"temp%d_input", hwmon->count);
temp->temp_input.attr.attr.name = temp->temp_input.name;
temp->temp_input.attr.attr.mode = 0444;
temp->temp_input.attr.show = temp_input_show;
sysfs_attr_init(&temp->temp_input.attr.attr);
result = device_create_file(hwmon->device, &temp->temp_input.attr);
if (result)
goto free_temp_mem;
if (thermal_zone_crit_temp_valid(tz)) {
snprintf(temp->temp_crit.name,
sizeof(temp->temp_crit.name),
"temp%d_crit", hwmon->count);
temp->temp_crit.attr.attr.name = temp->temp_crit.name;
temp->temp_crit.attr.attr.mode = 0444;
temp->temp_crit.attr.show = temp_crit_show;
sysfs_attr_init(&temp->temp_crit.attr.attr);
result = device_create_file(hwmon->device,
&temp->temp_crit.attr);
if (result)
goto unregister_input;
}
mutex_lock(&thermal_hwmon_list_lock);
if (new_hwmon_device)
list_add_tail(&hwmon->node, &thermal_hwmon_list);
list_add_tail(&temp->hwmon_node, &hwmon->tz_list);
mutex_unlock(&thermal_hwmon_list_lock);
return 0;
unregister_input:
device_remove_file(hwmon->device, &temp->temp_input.attr);
free_temp_mem:
kfree(temp);
unregister_name:
if (new_hwmon_device) {
device_remove_file(hwmon->device, &dev_attr_name);
hwmon_device_unregister(hwmon->device);
}
free_mem:
if (new_hwmon_device)
kfree(hwmon);
return result;
}
void thermal_remove_hwmon_sysfs(struct thermal_zone_device *tz)
{
struct thermal_hwmon_device *hwmon;
struct thermal_hwmon_temp *temp;
hwmon = thermal_hwmon_lookup_by_type(tz);
if (unlikely(!hwmon)) {
dev_dbg(&tz->device, "hwmon device lookup failed!\n");
return;
}
temp = thermal_hwmon_lookup_temp(hwmon, tz);
if (unlikely(!temp)) {
dev_dbg(&tz->device, "temperature input lookup failed!\n");
return;
}
device_remove_file(hwmon->device, &temp->temp_input.attr);
if (thermal_zone_crit_temp_valid(tz))
device_remove_file(hwmon->device, &temp->temp_crit.attr);
mutex_lock(&thermal_hwmon_list_lock);
list_del(&temp->hwmon_node);
kfree(temp);
if (!list_empty(&hwmon->tz_list)) {
mutex_unlock(&thermal_hwmon_list_lock);
return;
}
list_del(&hwmon->node);
mutex_unlock(&thermal_hwmon_list_lock);
device_remove_file(hwmon->device, &dev_attr_name);
hwmon_device_unregister(hwmon->device);
kfree(hwmon);
}
