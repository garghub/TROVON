static ssize_t recover_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct zpci_dev *zdev = get_zdev(pdev);
int ret;
if (!device_remove_file_self(dev, attr))
return count;
pci_stop_and_remove_bus_device(pdev);
ret = zpci_disable_device(zdev);
if (ret)
return ret;
ret = zpci_enable_device(zdev);
if (ret)
return ret;
pci_rescan_bus(zdev->bus);
return count;
}
static ssize_t util_string_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t off, size_t count)
{
struct device *dev = kobj_to_dev(kobj);
struct pci_dev *pdev = to_pci_dev(dev);
struct zpci_dev *zdev = get_zdev(pdev);
return memory_read_from_buffer(buf, count, &off, zdev->util_str,
sizeof(zdev->util_str));
}
