static ssize_t eeh_pe_state_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct eeh_dev *edev = pci_dev_to_eeh_dev(pdev);
int state;
if (!edev || !edev->pe)
return -ENODEV;
state = eeh_ops->get_state(edev->pe, NULL);
return sprintf(buf, "0x%08x 0x%08x\n",
state, edev->pe->state);
}
static ssize_t eeh_pe_state_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct eeh_dev *edev = pci_dev_to_eeh_dev(pdev);
if (!edev || !edev->pe)
return -ENODEV;
if (!(edev->pe->state & EEH_PE_ISOLATED))
return count;
if (eeh_unfreeze_pe(edev->pe, true))
return -EIO;
return count;
}
void eeh_sysfs_add_device(struct pci_dev *pdev)
{
struct eeh_dev *edev = pci_dev_to_eeh_dev(pdev);
int rc=0;
if (!eeh_enabled())
return;
if (edev && (edev->mode & EEH_DEV_SYSFS))
return;
rc += device_create_file(&pdev->dev, &dev_attr_eeh_mode);
rc += device_create_file(&pdev->dev, &dev_attr_eeh_pe_config_addr);
rc += device_create_file(&pdev->dev, &dev_attr_eeh_pe_state);
if (rc)
pr_warn("EEH: Unable to create sysfs entries\n");
else if (edev)
edev->mode |= EEH_DEV_SYSFS;
}
void eeh_sysfs_remove_device(struct pci_dev *pdev)
{
struct eeh_dev *edev = pci_dev_to_eeh_dev(pdev);
if (!pdev->dev.kobj.sd) {
if (edev)
edev->mode &= ~EEH_DEV_SYSFS;
return;
}
device_remove_file(&pdev->dev, &dev_attr_eeh_mode);
device_remove_file(&pdev->dev, &dev_attr_eeh_pe_config_addr);
device_remove_file(&pdev->dev, &dev_attr_eeh_pe_state);
if (edev)
edev->mode &= ~EEH_DEV_SYSFS;
}
