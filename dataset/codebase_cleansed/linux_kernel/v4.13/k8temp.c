static struct k8temp_data *k8temp_update_device(struct device *dev)
{
struct k8temp_data *data = dev_get_drvdata(dev);
struct pci_dev *pdev = to_pci_dev(dev);
u8 tmp;
mutex_lock(&data->update_lock);
if (!data->valid
|| time_after(jiffies, data->last_updated + HZ)) {
pci_read_config_byte(pdev, REG_TEMP, &tmp);
tmp &= ~(SEL_PLACE | SEL_CORE);
pci_write_config_byte(pdev, REG_TEMP, tmp);
pci_read_config_dword(pdev, REG_TEMP, &data->temp[0][0]);
if (data->sensorsp & SEL_PLACE) {
tmp |= SEL_PLACE;
pci_write_config_byte(pdev, REG_TEMP, tmp);
pci_read_config_dword(pdev, REG_TEMP,
&data->temp[0][1]);
}
if (data->sensorsp & SEL_CORE) {
tmp &= ~SEL_PLACE;
tmp |= SEL_CORE;
pci_write_config_byte(pdev, REG_TEMP, tmp);
pci_read_config_dword(pdev, REG_TEMP,
&data->temp[1][0]);
if (data->sensorsp & SEL_PLACE) {
tmp |= SEL_PLACE;
pci_write_config_byte(pdev, REG_TEMP, tmp);
pci_read_config_dword(pdev, REG_TEMP,
&data->temp[1][1]);
}
}
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t name_show(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct k8temp_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", data->name);
}
static ssize_t show_temp(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute_2 *attr =
to_sensor_dev_attr_2(devattr);
int core = attr->nr;
int place = attr->index;
int temp;
struct k8temp_data *data = k8temp_update_device(dev);
if (data->swap_core_select && (data->sensorsp & SEL_CORE))
core = core ? 0 : 1;
temp = TEMP_FROM_REG(data->temp[core][place]) + data->temp_offset;
return sprintf(buf, "%d\n", temp);
}
static int is_rev_g_desktop(u8 model)
{
u32 brandidx;
if (model < 0x69)
return 0;
if (model == 0xc1 || model == 0x6c || model == 0x7c)
return 0;
brandidx = cpuid_ebx(0x80000001);
brandidx = (brandidx >> 9) & 0x1f;
if ((model == 0x6f || model == 0x7f) &&
(brandidx == 0x7 || brandidx == 0x9 || brandidx == 0xc))
return 0;
if (model == 0x6b &&
(brandidx == 0xb || brandidx == 0xc))
return 0;
return 1;
}
static int k8temp_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
int err;
u8 scfg;
u32 temp;
u8 model, stepping;
struct k8temp_data *data;
data = devm_kzalloc(&pdev->dev, sizeof(struct k8temp_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
model = boot_cpu_data.x86_model;
stepping = boot_cpu_data.x86_mask;
if ((model == 4 && stepping == 0) ||
(model == 5 && stepping <= 1))
return -ENODEV;
if (model >= 0x40) {
data->swap_core_select = 1;
dev_warn(&pdev->dev,
"Temperature readouts might be wrong - check erratum #141\n");
}
if (is_rev_g_desktop(model))
data->temp_offset = 21000;
pci_read_config_byte(pdev, REG_TEMP, &scfg);
scfg &= ~(SEL_PLACE | SEL_CORE);
pci_write_config_byte(pdev, REG_TEMP, scfg);
pci_read_config_byte(pdev, REG_TEMP, &scfg);
if (scfg & (SEL_PLACE | SEL_CORE)) {
dev_err(&pdev->dev, "Configuration bit(s) stuck at 1!\n");
return -ENODEV;
}
scfg |= (SEL_PLACE | SEL_CORE);
pci_write_config_byte(pdev, REG_TEMP, scfg);
pci_read_config_byte(pdev, REG_TEMP, &data->sensorsp);
if (data->sensorsp & SEL_PLACE) {
scfg &= ~SEL_CORE;
pci_write_config_byte(pdev, REG_TEMP, scfg);
pci_read_config_dword(pdev, REG_TEMP, &temp);
scfg |= SEL_CORE;
if (!((temp >> 16) & 0xff))
data->sensorsp &= ~SEL_PLACE;
}
if (data->sensorsp & SEL_CORE) {
scfg &= ~SEL_PLACE;
pci_write_config_byte(pdev, REG_TEMP, scfg);
pci_read_config_dword(pdev, REG_TEMP, &temp);
if (!((temp >> 16) & 0xff))
data->sensorsp &= ~SEL_CORE;
}
data->name = "k8temp";
mutex_init(&data->update_lock);
pci_set_drvdata(pdev, data);
err = device_create_file(&pdev->dev,
&sensor_dev_attr_temp1_input.dev_attr);
if (err)
goto exit_remove;
if (data->sensorsp & SEL_PLACE) {
err = device_create_file(&pdev->dev,
&sensor_dev_attr_temp2_input.dev_attr);
if (err)
goto exit_remove;
}
if (data->sensorsp & SEL_CORE) {
err = device_create_file(&pdev->dev,
&sensor_dev_attr_temp3_input.dev_attr);
if (err)
goto exit_remove;
if (data->sensorsp & SEL_PLACE) {
err = device_create_file(&pdev->dev,
&sensor_dev_attr_temp4_input.
dev_attr);
if (err)
goto exit_remove;
}
}
err = device_create_file(&pdev->dev, &dev_attr_name);
if (err)
goto exit_remove;
data->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
return 0;
exit_remove:
device_remove_file(&pdev->dev,
&sensor_dev_attr_temp1_input.dev_attr);
device_remove_file(&pdev->dev,
&sensor_dev_attr_temp2_input.dev_attr);
device_remove_file(&pdev->dev,
&sensor_dev_attr_temp3_input.dev_attr);
device_remove_file(&pdev->dev,
&sensor_dev_attr_temp4_input.dev_attr);
device_remove_file(&pdev->dev, &dev_attr_name);
return err;
}
static void k8temp_remove(struct pci_dev *pdev)
{
struct k8temp_data *data = pci_get_drvdata(pdev);
hwmon_device_unregister(data->hwmon_dev);
device_remove_file(&pdev->dev,
&sensor_dev_attr_temp1_input.dev_attr);
device_remove_file(&pdev->dev,
&sensor_dev_attr_temp2_input.dev_attr);
device_remove_file(&pdev->dev,
&sensor_dev_attr_temp3_input.dev_attr);
device_remove_file(&pdev->dev,
&sensor_dev_attr_temp4_input.dev_attr);
device_remove_file(&pdev->dev, &dev_attr_name);
}
