struct device *hwmon_device_register(struct device *dev)
{
struct device *hwdev;
int id, err;
again:
if (unlikely(idr_pre_get(&hwmon_idr, GFP_KERNEL) == 0))
return ERR_PTR(-ENOMEM);
spin_lock(&idr_lock);
err = idr_get_new(&hwmon_idr, NULL, &id);
spin_unlock(&idr_lock);
if (unlikely(err == -EAGAIN))
goto again;
else if (unlikely(err))
return ERR_PTR(err);
id = id & MAX_ID_MASK;
hwdev = device_create(hwmon_class, dev, MKDEV(0, 0), NULL,
HWMON_ID_FORMAT, id);
if (IS_ERR(hwdev)) {
spin_lock(&idr_lock);
idr_remove(&hwmon_idr, id);
spin_unlock(&idr_lock);
}
return hwdev;
}
void hwmon_device_unregister(struct device *dev)
{
int id;
if (likely(sscanf(dev_name(dev), HWMON_ID_FORMAT, &id) == 1)) {
device_unregister(dev);
spin_lock(&idr_lock);
idr_remove(&hwmon_idr, id);
spin_unlock(&idr_lock);
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
if (sb &&
(sb->subsystem_vendor == 0x1462 &&
sb->subsystem_device == 0x0031)) {
pci_read_config_byte(sb, 0x48, &enable);
pci_read_config_word(sb, 0x64, &base);
if (base == 0 && !(enable & BIT(2))) {
dev_info(&sb->dev,
"Opening wide generic port at 0x295\n");
pci_write_config_word(sb, 0x64, 0x295);
pci_write_config_byte(sb, 0x48, enable | BIT(2));
}
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
