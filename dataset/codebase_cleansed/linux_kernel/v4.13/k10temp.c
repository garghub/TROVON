static void amd_nb_smu_index_read(struct pci_dev *pdev, unsigned int devfn,
int offset, u32 *val)
{
mutex_lock(&nb_smu_ind_mutex);
pci_bus_write_config_dword(pdev->bus, devfn,
0xb8, offset);
pci_bus_read_config_dword(pdev->bus, devfn,
0xbc, val);
mutex_unlock(&nb_smu_ind_mutex);
}
static ssize_t temp1_input_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
u32 regval;
struct pci_dev *pdev = dev_get_drvdata(dev);
if (boot_cpu_data.x86 == 0x15 && boot_cpu_data.x86_model == 0x60) {
amd_nb_smu_index_read(pdev, PCI_DEVFN(0, 0),
F15H_M60H_REPORTED_TEMP_CTRL_OFFSET,
&regval);
} else {
pci_read_config_dword(pdev, REG_REPORTED_TEMPERATURE, &regval);
}
return sprintf(buf, "%u\n", (regval >> 21) * 125);
}
static ssize_t temp1_max_show(struct device *dev,
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
pci_read_config_dword(dev_get_drvdata(dev),
REG_HARDWARE_THERMAL_CONTROL, &regval);
value = ((regval >> 16) & 0x7f) * 500 + 52000;
if (show_hyst)
value -= ((regval >> 24) & 0xf) * 500;
return sprintf(buf, "%d\n", value);
}
static umode_t k10temp_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct pci_dev *pdev = dev_get_drvdata(dev);
if (index >= 2) {
u32 reg_caps, reg_htc;
pci_read_config_dword(pdev, REG_NORTHBRIDGE_CAPABILITIES,
&reg_caps);
pci_read_config_dword(pdev, REG_HARDWARE_THERMAL_CONTROL,
&reg_htc);
if (!(reg_caps & NB_CAP_HTC) || !(reg_htc & HTC_ENABLE))
return 0;
}
return attr->mode;
}
static bool has_erratum_319(struct pci_dev *pdev)
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
static int k10temp_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
int unreliable = has_erratum_319(pdev);
struct device *dev = &pdev->dev;
struct device *hwmon_dev;
if (unreliable) {
if (!force) {
dev_err(dev,
"unreliable CPU thermal sensor; monitoring disabled\n");
return -ENODEV;
}
dev_warn(dev,
"unreliable CPU thermal sensor; check erratum 319\n");
}
hwmon_dev = devm_hwmon_device_register_with_groups(dev, "k10temp", pdev,
k10temp_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
