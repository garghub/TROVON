static ssize_t show_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
u32 regval;
pci_read_config_dword(to_pci_dev(dev),
REG_REPORTED_TEMPERATURE, &regval);
return sprintf(buf, "%u\n", (regval >> 21) * 125);
}
static ssize_t show_temp_max(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", 70 * 1000);
}
static ssize_t show_temp_crit(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int show_hyst = attr->index;
u32 regval;
int value;
pci_read_config_dword(to_pci_dev(dev),
REG_HARDWARE_THERMAL_CONTROL, &regval);
value = ((regval >> 16) & 0x7f) * 500 + 52000;
if (show_hyst)
value -= ((regval >> 24) & 0xf) * 500;
return sprintf(buf, "%d\n", value);
}
static ssize_t show_name(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "k10temp\n");
}
static bool __devinit has_erratum_319(struct pci_dev *pdev)
{
u32 pkg_type, reg_dram_cfg;
if (boot_cpu_data.x86 != 0x10)
return false;
pkg_type = cpuid_ebx(0x80000001) & CPUID_PKGTYPE_MASK;
if (pkg_type == CPUID_PKGTYPE_F)
return true;
if (pkg_type != CPUID_PKGTYPE_AM2R2_AM3)
return false;
pci_bus_read_config_dword(pdev->bus,
PCI_DEVFN(PCI_SLOT(pdev->devfn), 2),
REG_DCT0_CONFIG_HIGH, &reg_dram_cfg);
if (reg_dram_cfg & DDR3_MODE)
return false;
return boot_cpu_data.x86_model < 4 ||
(boot_cpu_data.x86_model == 4 && boot_cpu_data.x86_mask <= 2);
}
static int __devinit k10temp_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct device *hwmon_dev;
u32 reg_caps, reg_htc;
int unreliable = has_erratum_319(pdev);
int err;
if (unreliable && !force) {
dev_err(&pdev->dev,
"unreliable CPU thermal sensor; monitoring disabled\n");
err = -ENODEV;
goto exit;
}
err = device_create_file(&pdev->dev, &dev_attr_temp1_input);
if (err)
goto exit;
err = device_create_file(&pdev->dev, &dev_attr_temp1_max);
if (err)
goto exit_remove;
pci_read_config_dword(pdev, REG_NORTHBRIDGE_CAPABILITIES, &reg_caps);
pci_read_config_dword(pdev, REG_HARDWARE_THERMAL_CONTROL, &reg_htc);
if ((reg_caps & NB_CAP_HTC) && (reg_htc & HTC_ENABLE)) {
err = device_create_file(&pdev->dev,
&sensor_dev_attr_temp1_crit.dev_attr);
if (err)
goto exit_remove;
err = device_create_file(&pdev->dev,
&sensor_dev_attr_temp1_crit_hyst.dev_attr);
if (err)
goto exit_remove;
}
err = device_create_file(&pdev->dev, &dev_attr_name);
if (err)
goto exit_remove;
hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(hwmon_dev)) {
err = PTR_ERR(hwmon_dev);
goto exit_remove;
}
pci_set_drvdata(pdev, hwmon_dev);
if (unreliable && force)
dev_warn(&pdev->dev,
"unreliable CPU thermal sensor; check erratum 319\n");
return 0;
exit_remove:
device_remove_file(&pdev->dev, &dev_attr_name);
device_remove_file(&pdev->dev, &dev_attr_temp1_input);
device_remove_file(&pdev->dev, &dev_attr_temp1_max);
device_remove_file(&pdev->dev,
&sensor_dev_attr_temp1_crit.dev_attr);
device_remove_file(&pdev->dev,
&sensor_dev_attr_temp1_crit_hyst.dev_attr);
exit:
return err;
}
static void __devexit k10temp_remove(struct pci_dev *pdev)
{
hwmon_device_unregister(pci_get_drvdata(pdev));
device_remove_file(&pdev->dev, &dev_attr_name);
device_remove_file(&pdev->dev, &dev_attr_temp1_input);
device_remove_file(&pdev->dev, &dev_attr_temp1_max);
device_remove_file(&pdev->dev,
&sensor_dev_attr_temp1_crit.dev_attr);
device_remove_file(&pdev->dev,
&sensor_dev_attr_temp1_crit_hyst.dev_attr);
pci_set_drvdata(pdev, NULL);
}
static int __init k10temp_init(void)
{
return pci_register_driver(&k10temp_driver);
}
static void __exit k10temp_exit(void)
{
pci_unregister_driver(&k10temp_driver);
}
