static ssize_t
name_show(struct device *dev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%s\n", to_hwmon_device(dev)->name);
}
static umode_t hwmon_dev_name_is_visible(struct kobject *kobj,
struct attribute *attr, int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
if (to_hwmon_device(dev)->name == NULL)
return 0;
return attr->mode;
}
static void hwmon_dev_release(struct device *dev)
{
kfree(to_hwmon_device(dev));
}
static int hwmon_thermal_get_temp(void *data, int *temp)
{
struct hwmon_thermal_data *tdata = data;
struct hwmon_device *hwdev = tdata->hwdev;
int ret;
long t;
ret = hwdev->chip->ops->read(&hwdev->dev, hwmon_temp, hwmon_temp_input,
tdata->index, &t);
if (ret < 0)
return ret;
*temp = t;
return 0;
}
static int hwmon_thermal_add_sensor(struct device *dev,
struct hwmon_device *hwdev, int index)
{
struct hwmon_thermal_data *tdata;
tdata = devm_kzalloc(dev, sizeof(*tdata), GFP_KERNEL);
if (!tdata)
return -ENOMEM;
tdata->hwdev = hwdev;
tdata->index = index;
devm_thermal_zone_of_sensor_register(&hwdev->dev, index, tdata,
&hwmon_thermal_ops);
return 0;
}
static int hwmon_thermal_add_sensor(struct device *dev,
struct hwmon_device *hwdev, int index)
{
return 0;
}
static ssize_t hwmon_attr_show(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct hwmon_device_attribute *hattr = to_hwmon_attr(devattr);
long val;
int ret;
ret = hattr->ops->read(dev, hattr->type, hattr->attr, hattr->index,
&val);
if (ret < 0)
return ret;
return sprintf(buf, "%ld\n", val);
}
static ssize_t hwmon_attr_show_string(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct hwmon_device_attribute *hattr = to_hwmon_attr(devattr);
char *s;
int ret;
ret = hattr->ops->read_string(dev, hattr->type, hattr->attr,
hattr->index, &s);
if (ret < 0)
return ret;
return sprintf(buf, "%s\n", s);
}
static ssize_t hwmon_attr_store(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct hwmon_device_attribute *hattr = to_hwmon_attr(devattr);
long val;
int ret;
ret = kstrtol(buf, 10, &val);
if (ret < 0)
return ret;
ret = hattr->ops->write(dev, hattr->type, hattr->attr, hattr->index,
val);
if (ret < 0)
return ret;
return count;
}
static int hwmon_attr_base(enum hwmon_sensor_types type)
{
if (type == hwmon_in)
return 0;
return 1;
}
static bool is_string_attr(enum hwmon_sensor_types type, u32 attr)
{
return (type == hwmon_temp && attr == hwmon_temp_label) ||
(type == hwmon_in && attr == hwmon_in_label) ||
(type == hwmon_curr && attr == hwmon_curr_label) ||
(type == hwmon_power && attr == hwmon_power_label) ||
(type == hwmon_energy && attr == hwmon_energy_label) ||
(type == hwmon_humidity && attr == hwmon_humidity_label) ||
(type == hwmon_fan && attr == hwmon_fan_label);
}
static struct attribute *hwmon_genattr(struct device *dev,
const void *drvdata,
enum hwmon_sensor_types type,
u32 attr,
int index,
const char *template,
const struct hwmon_ops *ops)
{
struct hwmon_device_attribute *hattr;
struct device_attribute *dattr;
struct attribute *a;
umode_t mode;
char *name;
bool is_string = is_string_attr(type, attr);
if (!template)
return ERR_PTR(-ENOENT);
mode = ops->is_visible(drvdata, type, attr, index);
if (!mode)
return ERR_PTR(-ENOENT);
if ((mode & S_IRUGO) && ((is_string && !ops->read_string) ||
(!is_string && !ops->read)))
return ERR_PTR(-EINVAL);
if ((mode & S_IWUGO) && !ops->write)
return ERR_PTR(-EINVAL);
hattr = devm_kzalloc(dev, sizeof(*hattr), GFP_KERNEL);
if (!hattr)
return ERR_PTR(-ENOMEM);
if (type == hwmon_chip) {
name = (char *)template;
} else {
scnprintf(hattr->name, sizeof(hattr->name), template,
index + hwmon_attr_base(type));
name = hattr->name;
}
hattr->type = type;
hattr->attr = attr;
hattr->index = index;
hattr->ops = ops;
dattr = &hattr->dev_attr;
dattr->show = is_string ? hwmon_attr_show_string : hwmon_attr_show;
dattr->store = hwmon_attr_store;
a = &dattr->attr;
sysfs_attr_init(a);
a->name = name;
a->mode = mode;
return a;
}
static int hwmon_num_channel_attrs(const struct hwmon_channel_info *info)
{
int i, n;
for (i = n = 0; info->config[i]; i++)
n += hweight32(info->config[i]);
return n;
}
static int hwmon_genattrs(struct device *dev,
const void *drvdata,
struct attribute **attrs,
const struct hwmon_ops *ops,
const struct hwmon_channel_info *info)
{
const char * const *templates;
int template_size;
int i, aindex = 0;
if (info->type >= ARRAY_SIZE(__templates))
return -EINVAL;
templates = __templates[info->type];
template_size = __templates_size[info->type];
for (i = 0; info->config[i]; i++) {
u32 attr_mask = info->config[i];
u32 attr;
while (attr_mask) {
struct attribute *a;
attr = __ffs(attr_mask);
attr_mask &= ~BIT(attr);
if (attr >= template_size)
return -EINVAL;
a = hwmon_genattr(dev, drvdata, info->type, attr, i,
templates[attr], ops);
if (IS_ERR(a)) {
if (PTR_ERR(a) != -ENOENT)
return PTR_ERR(a);
continue;
}
attrs[aindex++] = a;
}
}
return aindex;
}
static struct attribute **
__hwmon_create_attrs(struct device *dev, const void *drvdata,
const struct hwmon_chip_info *chip)
{
int ret, i, aindex = 0, nattrs = 0;
struct attribute **attrs;
for (i = 0; chip->info[i]; i++)
nattrs += hwmon_num_channel_attrs(chip->info[i]);
if (nattrs == 0)
return ERR_PTR(-EINVAL);
attrs = devm_kcalloc(dev, nattrs + 1, sizeof(*attrs), GFP_KERNEL);
if (!attrs)
return ERR_PTR(-ENOMEM);
for (i = 0; chip->info[i]; i++) {
ret = hwmon_genattrs(dev, drvdata, &attrs[aindex], chip->ops,
chip->info[i]);
if (ret < 0)
return ERR_PTR(ret);
aindex += ret;
}
return attrs;
}
static struct device *
__hwmon_device_register(struct device *dev, const char *name, void *drvdata,
const struct hwmon_chip_info *chip,
const struct attribute_group **groups)
{
struct hwmon_device *hwdev;
struct device *hdev;
int i, j, err, id;
if (name && (!strlen(name) || strpbrk(name, "-* \t\n")))
dev_warn(dev,
"hwmon: '%s' is not a valid name attribute, please fix\n",
name);
id = ida_simple_get(&hwmon_ida, 0, 0, GFP_KERNEL);
if (id < 0)
return ERR_PTR(id);
hwdev = kzalloc(sizeof(*hwdev), GFP_KERNEL);
if (hwdev == NULL) {
err = -ENOMEM;
goto ida_remove;
}
hdev = &hwdev->dev;
if (chip) {
struct attribute **attrs;
int ngroups = 2;
if (groups)
for (i = 0; groups[i]; i++)
ngroups++;
hwdev->groups = devm_kcalloc(dev, ngroups, sizeof(*groups),
GFP_KERNEL);
if (!hwdev->groups) {
err = -ENOMEM;
goto free_hwmon;
}
attrs = __hwmon_create_attrs(dev, drvdata, chip);
if (IS_ERR(attrs)) {
err = PTR_ERR(attrs);
goto free_hwmon;
}
hwdev->group.attrs = attrs;
ngroups = 0;
hwdev->groups[ngroups++] = &hwdev->group;
if (groups) {
for (i = 0; groups[i]; i++)
hwdev->groups[ngroups++] = groups[i];
}
hdev->groups = hwdev->groups;
} else {
hdev->groups = groups;
}
hwdev->name = name;
hdev->class = &hwmon_class;
hdev->parent = dev;
hdev->of_node = dev ? dev->of_node : NULL;
hwdev->chip = chip;
dev_set_drvdata(hdev, drvdata);
dev_set_name(hdev, HWMON_ID_FORMAT, id);
err = device_register(hdev);
if (err)
goto free_hwmon;
if (dev && chip && chip->ops->read &&
chip->info[0]->type == hwmon_chip &&
(chip->info[0]->config[0] & HWMON_C_REGISTER_TZ)) {
const struct hwmon_channel_info **info = chip->info;
for (i = 1; info[i]; i++) {
if (info[i]->type != hwmon_temp)
continue;
for (j = 0; info[i]->config[j]; j++) {
if (!chip->ops->is_visible(drvdata, hwmon_temp,
hwmon_temp_input, j))
continue;
if (info[i]->config[j] & HWMON_T_INPUT)
hwmon_thermal_add_sensor(dev, hwdev, j);
}
}
}
return hdev;
free_hwmon:
kfree(hwdev);
ida_remove:
ida_simple_remove(&hwmon_ida, id);
return ERR_PTR(err);
}
struct device *
hwmon_device_register_with_groups(struct device *dev, const char *name,
void *drvdata,
const struct attribute_group **groups)
{
if (!name)
return ERR_PTR(-EINVAL);
return __hwmon_device_register(dev, name, drvdata, NULL, groups);
}
struct device *
hwmon_device_register_with_info(struct device *dev, const char *name,
void *drvdata,
const struct hwmon_chip_info *chip,
const struct attribute_group **extra_groups)
{
if (!name)
return ERR_PTR(-EINVAL);
if (chip && (!chip->ops || !chip->ops->is_visible || !chip->info))
return ERR_PTR(-EINVAL);
return __hwmon_device_register(dev, name, drvdata, chip, extra_groups);
}
struct device *hwmon_device_register(struct device *dev)
{
dev_warn(dev,
"hwmon_device_register() is deprecated. Please convert the driver to use hwmon_device_register_with_info().\n");
return __hwmon_device_register(dev, NULL, NULL, NULL, NULL);
}
void hwmon_device_unregister(struct device *dev)
{
int id;
if (likely(sscanf(dev_name(dev), HWMON_ID_FORMAT, &id) == 1)) {
device_unregister(dev);
ida_simple_remove(&hwmon_ida, id);
} else
dev_dbg(dev->parent,
"hwmon_device_unregister() failed: bad class ID!\n");
}
static void devm_hwmon_release(struct device *dev, void *res)
{
struct device *hwdev = *(struct device **)res;
hwmon_device_unregister(hwdev);
}
struct device *
devm_hwmon_device_register_with_groups(struct device *dev, const char *name,
void *drvdata,
const struct attribute_group **groups)
{
struct device **ptr, *hwdev;
if (!dev)
return ERR_PTR(-EINVAL);
ptr = devres_alloc(devm_hwmon_release, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return ERR_PTR(-ENOMEM);
hwdev = hwmon_device_register_with_groups(dev, name, drvdata, groups);
if (IS_ERR(hwdev))
goto error;
*ptr = hwdev;
devres_add(dev, ptr);
return hwdev;
error:
devres_free(ptr);
return hwdev;
}
struct device *
devm_hwmon_device_register_with_info(struct device *dev, const char *name,
void *drvdata,
const struct hwmon_chip_info *chip,
const struct attribute_group **groups)
{
struct device **ptr, *hwdev;
if (!dev)
return ERR_PTR(-EINVAL);
ptr = devres_alloc(devm_hwmon_release, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return ERR_PTR(-ENOMEM);
hwdev = hwmon_device_register_with_info(dev, name, drvdata, chip,
groups);
if (IS_ERR(hwdev))
goto error;
*ptr = hwdev;
devres_add(dev, ptr);
return hwdev;
error:
devres_free(ptr);
return hwdev;
}
static int devm_hwmon_match(struct device *dev, void *res, void *data)
{
struct device **hwdev = res;
return *hwdev == data;
}
void devm_hwmon_device_unregister(struct device *dev)
{
WARN_ON(devres_release(dev, devm_hwmon_release, devm_hwmon_match, dev));
}
static void __init hwmon_pci_quirks(void)
{
#if defined CONFIG_X86 && defined CONFIG_PCI
struct pci_dev *sb;
u16 base;
u8 enable;
sb = pci_get_device(PCI_VENDOR_ID_ATI, 0x436c, NULL);
if (sb) {
if (sb->subsystem_vendor == 0x1462 &&
sb->subsystem_device == 0x0031) {
pci_read_config_byte(sb, 0x48, &enable);
pci_read_config_word(sb, 0x64, &base);
if (base == 0 && !(enable & BIT(2))) {
dev_info(&sb->dev,
"Opening wide generic port at 0x295\n");
pci_write_config_word(sb, 0x64, 0x295);
pci_write_config_byte(sb, 0x48,
enable | BIT(2));
}
}
pci_dev_put(sb);
}
#endif
}
static int __init hwmon_init(void)
{
int err;
hwmon_pci_quirks();
err = class_register(&hwmon_class);
if (err) {
pr_err("couldn't register hwmon sysfs class\n");
return err;
}
return 0;
}
static void __exit hwmon_exit(void)
{
class_unregister(&hwmon_class);
}
