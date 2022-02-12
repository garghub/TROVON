void eeh_sysfs_add_device(struct pci_dev *pdev)
{
int rc=0;
rc += device_create_file(&pdev->dev, &dev_attr_eeh_mode);
rc += device_create_file(&pdev->dev, &dev_attr_eeh_config_addr);
rc += device_create_file(&pdev->dev, &dev_attr_eeh_pe_config_addr);
rc += device_create_file(&pdev->dev, &dev_attr_eeh_check_count);
rc += device_create_file(&pdev->dev, &dev_attr_eeh_false_positives);
rc += device_create_file(&pdev->dev, &dev_attr_eeh_freeze_count);
if (rc)
printk(KERN_WARNING "EEH: Unable to create sysfs entries\n");
}
void eeh_sysfs_remove_device(struct pci_dev *pdev)
{
device_remove_file(&pdev->dev, &dev_attr_eeh_mode);
device_remove_file(&pdev->dev, &dev_attr_eeh_config_addr);
device_remove_file(&pdev->dev, &dev_attr_eeh_pe_config_addr);
device_remove_file(&pdev->dev, &dev_attr_eeh_check_count);
device_remove_file(&pdev->dev, &dev_attr_eeh_false_positives);
device_remove_file(&pdev->dev, &dev_attr_eeh_freeze_count);
}
