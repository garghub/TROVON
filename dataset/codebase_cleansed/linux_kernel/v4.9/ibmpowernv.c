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
if (sdata->type == TEMP)
x *= 1000;
else if (sdata->type == POWER_INPUT)
x *= 1000000;
return sprintf(buf, "%u\n", x);
}
static ssize_t show_label(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_data *sdata = container_of(devattr, struct sensor_data,
dev_attr);
return sprintf(buf, "%s\n", sdata->label);
}
static int __init get_logical_cpu(int hwcpu)
{
int cpu;
for_each_possible_cpu(cpu)
if (get_hard_smp_processor_id(cpu) == hwcpu)
return cpu;
return -ENOENT;
}
static void __init make_sensor_label(struct device_node *np,
struct sensor_data *sdata,
const char *label)
{
u32 id;
size_t n;
n = snprintf(sdata->label, sizeof(sdata->label), "%s", label);
if (!of_property_read_u32(np, "ibm,pir", &id)) {
int cpuid = get_logical_cpu(id);
if (cpuid >= 0)
n += snprintf(sdata->label + n,
sizeof(sdata->label) - n, " %d",
cpuid);
else
n += snprintf(sdata->label + n,
sizeof(sdata->label) - n, " phy%d", id);
}
if (!of_property_read_u32(np, "ibm,chip-id", &id))
n += snprintf(sdata->label + n, sizeof(sdata->label) - n,
" %d", id & 0xffff);
}
static int get_sensor_index_attr(const char *name, u32 *index, char *attr)
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
static const char *convert_opal_attr_name(enum sensors type,
const char *opal_attr)
{
const char *attr_name = NULL;
if (!strcmp(opal_attr, DT_FAULT_ATTR_SUFFIX)) {
attr_name = "fault";
} else if (!strcmp(opal_attr, DT_DATA_ATTR_SUFFIX)) {
attr_name = "input";
} else if (!strcmp(opal_attr, DT_THRESHOLD_ATTR_SUFFIX)) {
if (type == TEMP)
attr_name = "max";
else if (type == FAN)
attr_name = "min";
}
return attr_name;
}
static const char *parse_opal_node_name(const char *node_name,
enum sensors type, u32 *index)
{
char attr_suffix[MAX_ATTR_LEN];
const char *attr_name;
int err;
err = get_sensor_index_attr(node_name, index, attr_suffix);
if (err)
return ERR_PTR(err);
attr_name = convert_opal_attr_name(type, attr_suffix);
if (!attr_name)
return ERR_PTR(-ENOENT);
return attr_name;
}
static int get_sensor_type(struct device_node *np)
{
enum sensors type;
const char *str;
for (type = 0; type < MAX_SENSOR_TYPE; type++) {
if (of_device_is_compatible(np, sensor_groups[type].compatible))
return type;
}
if (!of_device_is_compatible(np, "ibm,opal-sensor"))
return MAX_SENSOR_TYPE;
if (of_property_read_string(np, "sensor-type", &str))
return MAX_SENSOR_TYPE;
for (type = 0; type < MAX_SENSOR_TYPE; type++)
if (!strcmp(str, sensor_groups[type].name))
return type;
return MAX_SENSOR_TYPE;
}
static u32 get_sensor_hwmon_index(struct sensor_data *sdata,
struct sensor_data *sdata_table, int count)
{
int i;
if (sdata->opal_index != INVALID_INDEX) {
for (i = 0; i < count; i++)
if (sdata_table[i].opal_index == sdata->opal_index &&
sdata_table[i].type == sdata->type)
return sdata_table[i].hwmon_index;
}
return ++sensor_groups[sdata->type].hwmon_index;
}
static int populate_attr_groups(struct platform_device *pdev)
{
struct platform_data *pdata = platform_get_drvdata(pdev);
const struct attribute_group **pgroups = pdata->attr_groups;
struct device_node *opal, *np;
enum sensors type;
opal = of_find_node_by_path("/ibm,opal/sensors");
for_each_child_of_node(opal, np) {
const char *label;
if (np->name == NULL)
continue;
type = get_sensor_type(np);
if (type == MAX_SENSOR_TYPE)
continue;
sensor_groups[type].attr_count++;
if (!of_property_read_string(np, "label", &label))
sensor_groups[type].attr_count++;
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
static void create_hwmon_attr(struct sensor_data *sdata, const char *attr_name,
ssize_t (*show)(struct device *dev,
struct device_attribute *attr,
char *buf))
{
snprintf(sdata->name, MAX_ATTR_LEN, "%s%d_%s",
sensor_groups[sdata->type].name, sdata->hwmon_index,
attr_name);
sysfs_attr_init(&sdata->dev_attr.attr);
sdata->dev_attr.attr.name = sdata->name;
sdata->dev_attr.attr.mode = S_IRUGO;
sdata->dev_attr.show = show;
}
static int create_device_attrs(struct platform_device *pdev)
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
const char *attr_name;
u32 opal_index;
const char *label;
if (np->name == NULL)
continue;
type = get_sensor_type(np);
if (type == MAX_SENSOR_TYPE)
continue;
if (of_property_read_u32(np, "sensor-id", &sensor_id) &&
of_property_read_u32(np, "sensor-data", &sensor_id)) {
dev_info(&pdev->dev,
"'sensor-id' missing in the node '%s'\n",
np->name);
continue;
}
sdata[count].id = sensor_id;
sdata[count].type = type;
attr_name = parse_opal_node_name(np->name, type, &opal_index);
if (IS_ERR(attr_name)) {
attr_name = "input";
opal_index = INVALID_INDEX;
}
sdata[count].opal_index = opal_index;
sdata[count].hwmon_index =
get_sensor_hwmon_index(&sdata[count], sdata, count);
create_hwmon_attr(&sdata[count], attr_name, show_sensor);
pgroups[type]->attrs[sensor_groups[type].attr_count++] =
&sdata[count++].dev_attr.attr;
if (!of_property_read_string(np, "label", &label)) {
sdata[count].type = type;
sdata[count].opal_index = sdata[count - 1].opal_index;
sdata[count].hwmon_index = sdata[count - 1].hwmon_index;
make_sensor_label(np, &sdata[count], label);
create_hwmon_attr(&sdata[count], "label", show_label);
pgroups[type]->attrs[sensor_groups[type].attr_count++] =
&sdata[count++].dev_attr.attr;
}
}
exit_put_node:
of_node_put(opal);
return err;
}
static int ibmpowernv_probe(struct platform_device *pdev)
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
