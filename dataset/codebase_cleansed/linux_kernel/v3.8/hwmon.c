struct device *hwmon_device_register(struct device *dev)
{
struct device *hwdev;
int id;
id = ida_simple_get(&hwmon_ida, 0, 0, GFP_KERNEL);
if (id < 0)
return ERR_PTR(id);
hwdev = device_create(hwmon_class, dev, MKDEV(0, 0), NULL,
HWMON_ID_FORMAT, id);
if (IS_ERR(hwdev))
ida_simple_remove(&hwmon_ida, id);
return hwdev;
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
hwmon_pci_quirks();
hwmon_class = class_create(THIS_MODULE, "hwmon");
if (IS_ERR(hwmon_class)) {
pr_err("couldn't create sysfs class\n");
return PTR_ERR(hwmon_class);
}
return 0;
}
static void __exit hwmon_exit(void)
{
class_destroy(hwmon_class);
}
