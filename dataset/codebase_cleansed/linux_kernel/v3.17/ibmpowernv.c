static ssize_t show_sensor(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_data *sdata = container_of(devattr, struct sensor_data,
dev_attr);
ssize_t ret;
u32 x;
ret = opal_get_sensor_data(sdata->id, &x);
if (ret)
return ret;
if (sdata->type == AMBIENT_TEMP)
x *= 1000;
else if (sdata->type == POWER_INPUT)
x *= 1000000;
return sprintf(buf, "%u\n", x);
}
static int __init get_sensor_index_attr(const char *name, u32 *index,
char *attr)
{
char *hash_pos = strchr(name, '#');
char buf[8] = { 0 };
char *dash_pos;
u32 copy_len;
int err;
if (!hash_pos)
return -EINVAL;
dash_pos = strchr(hash_pos, '-');
if (!dash_pos)
return -EINVAL;
copy_len = dash_pos - hash_pos - 1;
if (copy_len >= sizeof(buf))
return -EINVAL;
strncpy(buf, hash_pos + 1, copy_len);
err = kstrtou32(buf, 10, index);
if (err)
return err;
strncpy(attr, dash_pos + 1, MAX_ATTR_LEN);
return 0;
}
static int __init create_hwmon_attr_name(struct device *dev, enum sensors type,
const char *node_name,
char *hwmon_attr_name)
{
char attr_suffix[MAX_ATTR_LEN];
char *attr_name;
u32 index;
int err;
err = get_sensor_index_attr(node_name, &index, attr_suffix);
if (err) {
dev_err(dev, "Sensor device node name '%s' is invalid\n",
node_name);
return err;
}
if (!strcmp(attr_suffix, DT_FAULT_ATTR_SUFFIX)) {
attr_name = "fault";
} else if (!strcmp(attr_suffix, DT_DATA_ATTR_SUFFIX)) {
attr_name = "input";
} else if (!strcmp(attr_suffix, DT_THRESHOLD_ATTR_SUFFIX)) {
if (type == AMBIENT_TEMP)
attr_name = "max";
else if (type == FAN)
attr_name = "min";
else
return -ENOENT;
} else {
return -ENOENT;
}
snprintf(hwmon_attr_name, MAX_ATTR_LEN, "%s%d_%s",
sensor_groups[type].name, index, attr_name);
return 0;
}
static int __init populate_attr_groups(struct platform_device *pdev)
{
struct platform_data *pdata = platform_get_drvdata(pdev);
const struct attribute_group **pgroups = pdata->attr_groups;
struct device_node *opal, *np;
enum sensors type;
opal = of_find_node_by_path("/ibm,opal/sensors");
if (!opal) {
dev_err(&pdev->dev, "Opal node 'sensors' not found\n");
return -ENODEV;
}
for_each_child_of_node(opal, np) {
if (np->name == NULL)
continue;
for (type = 0; type < MAX_SENSOR_TYPE; type++)
if (of_device_is_compatible(np,
sensor_groups[type].compatible)) {
sensor_groups[type].attr_count++;
break;
}
}
of_node_put(opal);
for (type = 0; type < MAX_SENSOR_TYPE; type++) {
sensor_groups[type].group.attrs = devm_kzalloc(&pdev->dev,
sizeof(struct attribute *) *
(sensor_groups[type].attr_count + 1),
GFP_KERNEL);
if (!sensor_groups[type].group.attrs)
return -ENOMEM;
pgroups[type] = &sensor_groups[type].group;
pdata->sensors_count += sensor_groups[type].attr_count;
sensor_groups[type].attr_count = 0;
}
return 0;
}
static int __init create_device_attrs(struct platform_device *pdev)
{
struct platform_data *pdata = platform_get_drvdata(pdev);
const struct attribute_group **pgroups = pdata->attr_groups;
struct device_node *opal, *np;
struct sensor_data *sdata;
u32 sensor_id;
enum sensors type;
u32 count = 0;
int err = 0;
opal = of_find_node_by_path("/ibm,opal/sensors");
sdata = devm_kzalloc(&pdev->dev, pdata->sensors_count * sizeof(*sdata),
GFP_KERNEL);
if (!sdata) {
err = -ENOMEM;
goto exit_put_node;
}
for_each_child_of_node(opal, np) {
if (np->name == NULL)
continue;
for (type = 0; type < MAX_SENSOR_TYPE; type++)
if (of_device_is_compatible(np,
sensor_groups[type].compatible))
break;
if (type == MAX_SENSOR_TYPE)
continue;
if (of_property_read_u32(np, "sensor-id", &sensor_id)) {
dev_info(&pdev->dev,
"'sensor-id' missing in the node '%s'\n",
np->name);
continue;
}
sdata[count].id = sensor_id;
sdata[count].type = type;
err = create_hwmon_attr_name(&pdev->dev, type, np->name,
sdata[count].name);
if (err)
goto exit_put_node;
sysfs_attr_init(&sdata[count].dev_attr.attr);
sdata[count].dev_attr.attr.name = sdata[count].name;
sdata[count].dev_attr.attr.mode = S_IRUGO;
sdata[count].dev_attr.show = show_sensor;
pgroups[type]->attrs[sensor_groups[type].attr_count++] =
&sdata[count++].dev_attr.attr;
}
exit_put_node:
of_node_put(opal);
return err;
}
static int __init ibmpowernv_probe(struct platform_device *pdev)
{
struct platform_data *pdata;
struct device *hwmon_dev;
int err;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
platform_set_drvdata(pdev, pdata);
pdata->sensors_count = 0;
err = populate_attr_groups(pdev);
if (err)
return err;
err = create_device_attrs(pdev);
if (err)
return err;
hwmon_dev = devm_hwmon_device_register_with_groups(&pdev->dev, DRVNAME,
pdata,
pdata->attr_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
static int __init ibmpowernv_init(void)
{
int err;
pdevice = platform_device_alloc(DRVNAME, 0);
if (!pdevice) {
pr_err("Device allocation failed\n");
err = -ENOMEM;
goto exit;
}
err = platform_device_add(pdevice);
if (err) {
pr_err("Device addition failed (%d)\n", err);
goto exit_device_put;
}
err = platform_driver_probe(&ibmpowernv_driver, ibmpowernv_probe);
if (err) {
pr_err("Platfrom driver probe failed\n");
goto exit_device_del;
}
return 0;
exit_device_del:
platform_device_del(pdevice);
exit_device_put:
platform_device_put(pdevice);
exit:
return err;
}
static void __exit ibmpowernv_exit(void)
{
platform_driver_unregister(&ibmpowernv_driver);
platform_device_unregister(pdevice);
}
