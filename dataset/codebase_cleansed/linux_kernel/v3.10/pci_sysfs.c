static ssize_t show_fid(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct zpci_dev *zdev = get_zdev(container_of(dev, struct pci_dev, dev));
sprintf(buf, "0x%08x\n", zdev->fid);
return strlen(buf);
}
static ssize_t show_fh(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct zpci_dev *zdev = get_zdev(container_of(dev, struct pci_dev, dev));
sprintf(buf, "0x%08x\n", zdev->fh);
return strlen(buf);
}
static ssize_t show_pchid(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct zpci_dev *zdev = get_zdev(container_of(dev, struct pci_dev, dev));
sprintf(buf, "0x%04x\n", zdev->pchid);
return strlen(buf);
}
static ssize_t show_pfgid(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct zpci_dev *zdev = get_zdev(container_of(dev, struct pci_dev, dev));
sprintf(buf, "0x%02x\n", zdev->pfgid);
return strlen(buf);
}
int zpci_sysfs_add_device(struct device *dev)
{
int i, rc = 0;
for (i = 0; zpci_dev_attrs[i]; i++) {
rc = device_create_file(dev, zpci_dev_attrs[i]);
if (rc)
goto error;
}
return 0;
error:
while (--i >= 0)
device_remove_file(dev, zpci_dev_attrs[i]);
return rc;
}
void zpci_sysfs_remove_device(struct device *dev)
{
int i;
for (i = 0; zpci_dev_attrs[i]; i++)
device_remove_file(dev, zpci_dev_attrs[i]);
}
