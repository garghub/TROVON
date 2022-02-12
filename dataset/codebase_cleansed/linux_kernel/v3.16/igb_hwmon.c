static ssize_t igb_hwmon_show_location(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hwmon_attr *igb_attr = container_of(attr, struct hwmon_attr,
dev_attr);
return sprintf(buf, "loc%u\n",
igb_attr->sensor->location);
}
static ssize_t igb_hwmon_show_temp(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hwmon_attr *igb_attr = container_of(attr, struct hwmon_attr,
dev_attr);
unsigned int value;
igb_attr->hw->mac.ops.get_thermal_sensor_data(igb_attr->hw);
value = igb_attr->sensor->temp;
value *= 1000;
return sprintf(buf, "%u\n", value);
}
static ssize_t igb_hwmon_show_cautionthresh(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hwmon_attr *igb_attr = container_of(attr, struct hwmon_attr,
dev_attr);
unsigned int value = igb_attr->sensor->caution_thresh;
value *= 1000;
return sprintf(buf, "%u\n", value);
}
static ssize_t igb_hwmon_show_maxopthresh(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hwmon_attr *igb_attr = container_of(attr, struct hwmon_attr,
dev_attr);
unsigned int value = igb_attr->sensor->max_op_thresh;
value *= 1000;
return sprintf(buf, "%u\n", value);
}
static int igb_add_hwmon_attr(struct igb_adapter *adapter,
unsigned int offset, int type)
{
int rc;
unsigned int n_attr;
struct hwmon_attr *igb_attr;
n_attr = adapter->igb_hwmon_buff->n_hwmon;
igb_attr = &adapter->igb_hwmon_buff->hwmon_list[n_attr];
switch (type) {
case IGB_HWMON_TYPE_LOC:
igb_attr->dev_attr.show = igb_hwmon_show_location;
snprintf(igb_attr->name, sizeof(igb_attr->name),
"temp%u_label", offset + 1);
break;
case IGB_HWMON_TYPE_TEMP:
igb_attr->dev_attr.show = igb_hwmon_show_temp;
snprintf(igb_attr->name, sizeof(igb_attr->name),
"temp%u_input", offset + 1);
break;
case IGB_HWMON_TYPE_CAUTION:
igb_attr->dev_attr.show = igb_hwmon_show_cautionthresh;
snprintf(igb_attr->name, sizeof(igb_attr->name),
"temp%u_max", offset + 1);
break;
case IGB_HWMON_TYPE_MAX:
igb_attr->dev_attr.show = igb_hwmon_show_maxopthresh;
snprintf(igb_attr->name, sizeof(igb_attr->name),
"temp%u_crit", offset + 1);
break;
default:
rc = -EPERM;
return rc;
}
igb_attr->sensor =
&adapter->hw.mac.thermal_sensor_data.sensor[offset];
igb_attr->hw = &adapter->hw;
igb_attr->dev_attr.store = NULL;
igb_attr->dev_attr.attr.mode = S_IRUGO;
igb_attr->dev_attr.attr.name = igb_attr->name;
sysfs_attr_init(&igb_attr->dev_attr.attr);
adapter->igb_hwmon_buff->attrs[n_attr] = &igb_attr->dev_attr.attr;
++adapter->igb_hwmon_buff->n_hwmon;
return 0;
}
static void igb_sysfs_del_adapter(struct igb_adapter *adapter)
{
}
void igb_sysfs_exit(struct igb_adapter *adapter)
{
igb_sysfs_del_adapter(adapter);
}
int igb_sysfs_init(struct igb_adapter *adapter)
{
struct hwmon_buff *igb_hwmon;
struct i2c_client *client;
struct device *hwmon_dev;
unsigned int i;
int rc = 0;
if (adapter->hw.mac.ops.init_thermal_sensor_thresh == NULL)
goto exit;
rc = (adapter->hw.mac.ops.init_thermal_sensor_thresh(&adapter->hw));
if (rc)
goto exit;
igb_hwmon = devm_kzalloc(&adapter->pdev->dev, sizeof(*igb_hwmon),
GFP_KERNEL);
if (!igb_hwmon) {
rc = -ENOMEM;
goto exit;
}
adapter->igb_hwmon_buff = igb_hwmon;
for (i = 0; i < E1000_MAX_SENSORS; i++) {
if (adapter->hw.mac.thermal_sensor_data.sensor[i].location == 0)
continue;
rc = igb_add_hwmon_attr(adapter, i, IGB_HWMON_TYPE_CAUTION);
if (rc)
goto exit;
rc = igb_add_hwmon_attr(adapter, i, IGB_HWMON_TYPE_LOC);
if (rc)
goto exit;
rc = igb_add_hwmon_attr(adapter, i, IGB_HWMON_TYPE_TEMP);
if (rc)
goto exit;
rc = igb_add_hwmon_attr(adapter, i, IGB_HWMON_TYPE_MAX);
if (rc)
goto exit;
}
client = i2c_new_device(&adapter->i2c_adap, &i350_sensor_info);
if (client == NULL) {
dev_info(&adapter->pdev->dev,
"Failed to create new i2c device.\n");
rc = -ENODEV;
goto exit;
}
adapter->i2c_client = client;
igb_hwmon->groups[0] = &igb_hwmon->group;
igb_hwmon->group.attrs = igb_hwmon->attrs;
hwmon_dev = devm_hwmon_device_register_with_groups(&adapter->pdev->dev,
client->name,
igb_hwmon,
igb_hwmon->groups);
if (IS_ERR(hwmon_dev)) {
rc = PTR_ERR(hwmon_dev);
goto err;
}
goto exit;
err:
igb_sysfs_del_adapter(adapter);
exit:
return rc;
}
