static ssize_t show_power(struct device *dev,
struct device_attribute *attr, char *buf)
{
u32 val, tdp_limit, running_avg_range;
s32 running_avg_capture;
u64 curr_pwr_watts;
struct pci_dev *f4 = to_pci_dev(dev);
struct fam15h_power_data *data = dev_get_drvdata(dev);
pci_bus_read_config_dword(f4->bus, PCI_DEVFN(PCI_SLOT(f4->devfn), 5),
REG_TDP_RUNNING_AVERAGE, &val);
running_avg_capture = (val >> 4) & 0x3fffff;
running_avg_capture = sign_extend32(running_avg_capture, 21);
running_avg_range = (val & 0xf) + 1;
pci_bus_read_config_dword(f4->bus, PCI_DEVFN(PCI_SLOT(f4->devfn), 5),
REG_TDP_LIMIT3, &val);
tdp_limit = val >> 16;
curr_pwr_watts = ((u64)(tdp_limit +
data->base_tdp)) << running_avg_range;
curr_pwr_watts -= running_avg_capture;
curr_pwr_watts *= data->tdp_to_watts;
curr_pwr_watts = (curr_pwr_watts * 15625) >> (10 + running_avg_range);
return sprintf(buf, "%u\n", (unsigned int) curr_pwr_watts);
}
static ssize_t show_power_crit(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct fam15h_power_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", data->processor_pwr_watts);
}
static ssize_t show_name(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "fam15h_power\n");
}
static bool __devinit fam15h_power_is_internal_node0(struct pci_dev *f4)
{
u32 val;
pci_bus_read_config_dword(f4->bus, PCI_DEVFN(PCI_SLOT(f4->devfn), 3),
REG_NORTHBRIDGE_CAP, &val);
if ((val & BIT(29)) && ((val >> 30) & 3))
return false;
return true;
}
static void tweak_runavg_range(struct pci_dev *pdev)
{
u32 val;
if (!pci_match_id(affected_device, pdev))
return;
pci_bus_read_config_dword(pdev->bus,
PCI_DEVFN(PCI_SLOT(pdev->devfn), 5),
REG_TDP_RUNNING_AVERAGE, &val);
if ((val & 0xf) != 0xe)
return;
val &= ~0xf;
val |= 0x9;
pci_bus_write_config_dword(pdev->bus,
PCI_DEVFN(PCI_SLOT(pdev->devfn), 5),
REG_TDP_RUNNING_AVERAGE, val);
}
static int fam15h_power_resume(struct pci_dev *pdev)
{
tweak_runavg_range(pdev);
return 0;
}
static void __devinit fam15h_power_init_data(struct pci_dev *f4,
struct fam15h_power_data *data)
{
u32 val;
u64 tmp;
pci_read_config_dword(f4, REG_PROCESSOR_TDP, &val);
data->base_tdp = val >> 16;
tmp = val & 0xffff;
pci_bus_read_config_dword(f4->bus, PCI_DEVFN(PCI_SLOT(f4->devfn), 5),
REG_TDP_LIMIT3, &val);
data->tdp_to_watts = ((val & 0x3ff) << 6) | ((val >> 10) & 0x3f);
tmp *= data->tdp_to_watts;
if ((tmp >> 16) >= 256)
dev_warn(&f4->dev, "Bogus value for ProcessorPwrWatts "
"(processor_pwr_watts>=%u)\n",
(unsigned int) (tmp >> 16));
data->processor_pwr_watts = (tmp * 15625) >> 10;
}
static int __devinit fam15h_power_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct fam15h_power_data *data;
struct device *dev;
int err;
tweak_runavg_range(pdev);
if (!fam15h_power_is_internal_node0(pdev)) {
err = -ENODEV;
goto exit;
}
data = kzalloc(sizeof(struct fam15h_power_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
fam15h_power_init_data(pdev, data);
dev = &pdev->dev;
dev_set_drvdata(dev, data);
err = sysfs_create_group(&dev->kobj, &fam15h_power_attr_group);
if (err)
goto exit_free_data;
data->hwmon_dev = hwmon_device_register(dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_group;
}
return 0;
exit_remove_group:
sysfs_remove_group(&dev->kobj, &fam15h_power_attr_group);
exit_free_data:
kfree(data);
exit:
return err;
}
static void __devexit fam15h_power_remove(struct pci_dev *pdev)
{
struct device *dev;
struct fam15h_power_data *data;
dev = &pdev->dev;
data = dev_get_drvdata(dev);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&dev->kobj, &fam15h_power_attr_group);
dev_set_drvdata(dev, NULL);
kfree(data);
}
