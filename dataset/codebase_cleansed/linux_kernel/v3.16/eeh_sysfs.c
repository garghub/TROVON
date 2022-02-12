void eeh_sysfs_add_device(struct pci_dev *pdev)
{
struct eeh_dev *edev = pci_dev_to_eeh_dev(pdev);
int rc=0;
if (!eeh_enabled())
return;
if (edev && (edev->mode & EEH_DEV_SYSFS))
return;
rc += device_create_file(&pdev->dev, &dev_attr_eeh_mode);
rc += device_create_file(&pdev->dev, &dev_attr_eeh_config_addr);
rc += device_create_file(&pdev->dev, &dev_attr_eeh_pe_config_addr);
if (rc)
printk(KERN_WARNING "EEH: Unable to create sysfs entries\n");
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
device_remove_file(&pdev->dev, &dev_attr_eeh_config_addr);
device_remove_file(&pdev->dev, &dev_attr_eeh_pe_config_addr);
if (edev)
edev->mode &= ~EEH_DEV_SYSFS;
}
