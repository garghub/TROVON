static ssize_t ixgbe_hwmon_show_location(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hwmon_attr *ixgbe_attr = container_of(attr, struct hwmon_attr,
dev_attr);
return sprintf(buf, "loc%u\n",
ixgbe_attr->sensor->location);
}
static ssize_t ixgbe_hwmon_show_temp(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hwmon_attr *ixgbe_attr = container_of(attr, struct hwmon_attr,
dev_attr);
unsigned int value;
ixgbe_attr->hw->mac.ops.get_thermal_sensor_data(ixgbe_attr->hw);
value = ixgbe_attr->sensor->temp;
value *= 1000;
return sprintf(buf, "%u\n", value);
}
static ssize_t ixgbe_hwmon_show_cautionthresh(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hwmon_attr *ixgbe_attr = container_of(attr, struct hwmon_attr,
dev_attr);
unsigned int value = ixgbe_attr->sensor->caution_thresh;
value *= 1000;
return sprintf(buf, "%u\n", value);
}
static ssize_t ixgbe_hwmon_show_maxopthresh(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hwmon_attr *ixgbe_attr = container_of(attr, struct hwmon_attr,
dev_attr);
unsigned int value = ixgbe_attr->sensor->max_op_thresh;
value *= 1000;
return sprintf(buf, "%u\n", value);
}
static int ixgbe_add_hwmon_attr(struct ixgbe_adapter *adapter,
unsigned int offset, int type) {
int rc;
unsigned int n_attr;
struct hwmon_attr *ixgbe_attr;
n_attr = adapter->ixgbe_hwmon_buff->n_hwmon;
ixgbe_attr = &adapter->ixgbe_hwmon_buff->hwmon_list[n_attr];
switch (type) {
case IXGBE_HWMON_TYPE_LOC:
ixgbe_attr->dev_attr.show = ixgbe_hwmon_show_location;
snprintf(ixgbe_attr->name, sizeof(ixgbe_attr->name),
"temp%u_label", offset + 1);
break;
case IXGBE_HWMON_TYPE_TEMP:
ixgbe_attr->dev_attr.show = ixgbe_hwmon_show_temp;
snprintf(ixgbe_attr->name, sizeof(ixgbe_attr->name),
"temp%u_input", offset + 1);
break;
case IXGBE_HWMON_TYPE_CAUTION:
ixgbe_attr->dev_attr.show = ixgbe_hwmon_show_cautionthresh;
snprintf(ixgbe_attr->name, sizeof(ixgbe_attr->name),
"temp%u_max", offset + 1);
break;
case IXGBE_HWMON_TYPE_MAX:
ixgbe_attr->dev_attr.show = ixgbe_hwmon_show_maxopthresh;
snprintf(ixgbe_attr->name, sizeof(ixgbe_attr->name),
"temp%u_crit", offset + 1);
break;
default:
rc = -EPERM;
return rc;
}
ixgbe_attr->sensor =
&adapter->hw.mac.thermal_sensor_data.sensor[offset];
ixgbe_attr->hw = &adapter->hw;
ixgbe_attr->dev_attr.store = NULL;
ixgbe_attr->dev_attr.attr.mode = S_IRUGO;
ixgbe_attr->dev_attr.attr.name = ixgbe_attr->name;
sysfs_attr_init(&ixgbe_attr->dev_attr.attr);
adapter->ixgbe_hwmon_buff->attrs[n_attr] = &ixgbe_attr->dev_attr.attr;
++adapter->ixgbe_hwmon_buff->n_hwmon;
return 0;
}
static void ixgbe_sysfs_del_adapter(struct ixgbe_adapter *adapter)
{
}
void ixgbe_sysfs_exit(struct ixgbe_adapter *adapter)
{
ixgbe_sysfs_del_adapter(adapter);
}
int ixgbe_sysfs_init(struct ixgbe_adapter *adapter)
{
struct hwmon_buff *ixgbe_hwmon;
struct device *hwmon_dev;
unsigned int i;
int rc = 0;
if (adapter->hw.mac.ops.init_thermal_sensor_thresh == NULL) {
goto exit;
}
if (adapter->hw.mac.ops.init_thermal_sensor_thresh(&adapter->hw))
goto exit;
ixgbe_hwmon = devm_kzalloc(&adapter->pdev->dev, sizeof(*ixgbe_hwmon),
GFP_KERNEL);
if (ixgbe_hwmon == NULL) {
rc = -ENOMEM;
goto exit;
}
adapter->ixgbe_hwmon_buff = ixgbe_hwmon;
for (i = 0; i < IXGBE_MAX_SENSORS; i++) {
if (adapter->hw.mac.thermal_sensor_data.sensor[i].location == 0)
continue;
rc = ixgbe_add_hwmon_attr(adapter, i, IXGBE_HWMON_TYPE_CAUTION);
if (rc)
goto exit;
rc = ixgbe_add_hwmon_attr(adapter, i, IXGBE_HWMON_TYPE_LOC);
if (rc)
goto exit;
rc = ixgbe_add_hwmon_attr(adapter, i, IXGBE_HWMON_TYPE_TEMP);
if (rc)
goto exit;
rc = ixgbe_add_hwmon_attr(adapter, i, IXGBE_HWMON_TYPE_MAX);
if (rc)
goto exit;
}
ixgbe_hwmon->groups[0] = &ixgbe_hwmon->group;
ixgbe_hwmon->group.attrs = ixgbe_hwmon->attrs;
hwmon_dev = devm_hwmon_device_register_with_groups(&adapter->pdev->dev,
"ixgbe",
ixgbe_hwmon,
ixgbe_hwmon->groups);
if (IS_ERR(hwmon_dev))
rc = PTR_ERR(hwmon_dev);
exit:
return rc;
}
