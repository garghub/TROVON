static ssize_t show_temp(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct pci_dev *pdev = to_pci_dev(dev->parent);
long temp;
u16 tsthrhi;
s8 tsfsc;
pci_read_config_word(pdev, REG_TSTHRHI, &tsthrhi);
pci_read_config_byte(pdev, REG_TSFSC, &tsfsc);
temp = ((long)tsthrhi - tsfsc) * 500;
return sprintf(buf, "%ld\n", temp);
}
static ssize_t show_thresh(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct pci_dev *pdev = to_pci_dev(dev->parent);
int reg = to_sensor_dev_attr(devattr)->index;
long temp;
u16 tsthr;
pci_read_config_word(pdev, reg, &tsthr);
temp = tsthr * 500;
return sprintf(buf, "%ld\n", temp);
}
static ssize_t show_alarm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct pci_dev *pdev = to_pci_dev(dev->parent);
int nr = to_sensor_dev_attr(devattr)->index;
u8 ctsts;
pci_read_config_byte(pdev, REG_CTSTS, &ctsts);
return sprintf(buf, "%u\n", (unsigned int)ctsts & (1 << nr));
}
static int i5500_temp_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
int err;
struct device *hwmon_dev;
u32 tstimer;
s8 tsfsc;
err = pci_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "Failed to enable device\n");
return err;
}
pci_read_config_byte(pdev, REG_TSFSC, &tsfsc);
pci_read_config_dword(pdev, REG_TSTIMER, &tstimer);
if (tsfsc == 0x7F && tstimer == 0x07D30D40) {
dev_notice(&pdev->dev, "Sensor seems to be disabled\n");
return -ENODEV;
}
hwmon_dev = devm_hwmon_device_register_with_groups(&pdev->dev,
"intel5500", NULL,
i5500_temp_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
