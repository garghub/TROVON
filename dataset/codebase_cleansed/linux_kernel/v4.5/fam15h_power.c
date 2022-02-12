static ssize_t show_power(struct device *dev,
struct device_attribute *attr, char *buf)
{
u32 val, tdp_limit, running_avg_range;
s32 running_avg_capture;
u64 curr_pwr_watts;
struct fam15h_power_data *data = dev_get_drvdata(dev);
struct pci_dev *f4 = data->pdev;
pci_bus_read_config_dword(f4->bus, PCI_DEVFN(PCI_SLOT(f4->devfn), 5),
REG_TDP_RUNNING_AVERAGE, &val);
if (boot_cpu_data.x86 == 0x15 && boot_cpu_data.x86_model >= 0x60) {
running_avg_capture = val >> 4;
running_avg_capture = sign_extend32(running_avg_capture, 27);
} else {
running_avg_capture = (val >> 4) & 0x3fffff;
running_avg_capture = sign_extend32(running_avg_capture, 21);
}
running_avg_range = (val & 0xf) + 1;
pci_bus_read_config_dword(f4->bus, PCI_DEVFN(PCI_SLOT(f4->devfn), 5),
REG_TDP_LIMIT3, &val);
if (boot_cpu_data.x86 == 0x15 && boot_cpu_data.x86_model >= 0x60)
tdp_limit = val >> 16;
else
tdp_limit = (val >> 16) & 0x1fff;
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
static int fam15h_power_init_attrs(struct pci_dev *pdev,
struct fam15h_power_data *data)
{
int n = FAM15H_MIN_NUM_ATTRS;
struct attribute **fam15h_power_attrs;
struct cpuinfo_x86 *c = &boot_cpu_data;
if (c->x86 == 0x15 &&
(c->x86_model <= 0xf ||
(c->x86_model >= 0x60 && c->x86_model <= 0x7f)))
n += 1;
fam15h_power_attrs = devm_kcalloc(&pdev->dev, n,
sizeof(*fam15h_power_attrs),
GFP_KERNEL);
if (!fam15h_power_attrs)
return -ENOMEM;
n = 0;
fam15h_power_attrs[n++] = &dev_attr_power1_crit.attr;
if (c->x86 == 0x15 &&
(c->x86_model <= 0xf ||
(c->x86_model >= 0x60 && c->x86_model <= 0x7f)))
fam15h_power_attrs[n++] = &dev_attr_power1_input.attr;
data->group.attrs = fam15h_power_attrs;
return 0;
}
static bool should_load_on_this_node(struct pci_dev *f4)
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
static int fam15h_power_init_data(struct pci_dev *f4,
struct fam15h_power_data *data)
{
u32 val, eax, ebx, ecx, edx;
u64 tmp;
int ret;
pci_read_config_dword(f4, REG_PROCESSOR_TDP, &val);
data->base_tdp = val >> 16;
tmp = val & 0xffff;
pci_bus_read_config_dword(f4->bus, PCI_DEVFN(PCI_SLOT(f4->devfn), 5),
REG_TDP_LIMIT3, &val);
data->tdp_to_watts = ((val & 0x3ff) << 6) | ((val >> 10) & 0x3f);
tmp *= data->tdp_to_watts;
if ((tmp >> 16) >= 256)
dev_warn(&f4->dev,
"Bogus value for ProcessorPwrWatts (processor_pwr_watts>=%u)\n",
(unsigned int) (tmp >> 16));
data->processor_pwr_watts = (tmp * 15625) >> 10;
ret = fam15h_power_init_attrs(f4, data);
if (ret)
return ret;
cpuid(0x80000007, &eax, &ebx, &ecx, &edx);
if (!(edx & BIT(12)))
return 0;
data->cpu_pwr_sample_ratio = ecx;
if (rdmsrl_safe(MSR_F15H_CU_MAX_PWR_ACCUMULATOR, &tmp)) {
pr_err("Failed to read max compute unit power accumulator MSR\n");
return -ENODEV;
}
data->max_cu_acc_power = tmp;
return 0;
}
static int fam15h_power_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct fam15h_power_data *data;
struct device *dev = &pdev->dev;
struct device *hwmon_dev;
int ret;
tweak_runavg_range(pdev);
if (!should_load_on_this_node(pdev))
return -ENODEV;
data = devm_kzalloc(dev, sizeof(struct fam15h_power_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
ret = fam15h_power_init_data(pdev, data);
if (ret)
return ret;
data->pdev = pdev;
data->groups[0] = &data->group;
hwmon_dev = devm_hwmon_device_register_with_groups(dev, "fam15h_power",
data,
&data->groups[0]);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
