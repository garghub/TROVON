static ssize_t
show_name(struct device *dev, struct device_attribute *attr, char *buf)
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
struct device *
hwmon_device_register_with_groups(struct device *dev, const char *name,
void *drvdata,
const struct attribute_group **groups)
{
struct hwmon_device *hwdev;
int err, id;
if (name && (!strlen(name) || strpbrk(name, "-* \t\n")))
return ERR_PTR(-EINVAL);
id = ida_simple_get(&hwmon_ida, 0, 0, GFP_KERNEL);
if (id < 0)
return ERR_PTR(id);
hwdev = kzalloc(sizeof(*hwdev), GFP_KERNEL);
if (hwdev == NULL) {
err = -ENOMEM;
goto ida_remove;
}
hwdev->name = name;
hwdev->dev.class = &hwmon_class;
hwdev->dev.parent = dev;
hwdev->dev.groups = groups;
hwdev->dev.of_node = dev ? dev->of_node : NULL;
dev_set_drvdata(&hwdev->dev, drvdata);
dev_set_name(&hwdev->dev, HWMON_ID_FORMAT, id);
err = device_register(&hwdev->dev);
if (err)
goto free;
return &hwdev->dev;
free:
kfree(hwdev);
ida_remove:
ida_simple_remove(&hwmon_ida, id);
return ERR_PTR(err);
}
struct device *hwmon_device_register(struct device *dev)
{
return hwmon_device_register_with_groups(dev, NULL, NULL, NULL);
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
