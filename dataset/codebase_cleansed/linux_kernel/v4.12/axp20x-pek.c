static struct axp20x_pek_ext_attr *get_axp_ext_attr(struct device_attribute *attr)
{
return container_of(attr, struct dev_ext_attribute, attr)->var;
}
static ssize_t axp20x_show_ext_attr(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct axp20x_pek *axp20x_pek = dev_get_drvdata(dev);
struct axp20x_pek_ext_attr *axp20x_ea = get_axp_ext_attr(attr);
unsigned int val;
int ret, i;
ret = regmap_read(axp20x_pek->axp20x->regmap, AXP20X_PEK_KEY, &val);
if (ret != 0)
return ret;
val &= axp20x_ea->mask;
val >>= ffs(axp20x_ea->mask) - 1;
for (i = 0; i < 4; i++)
if (val == axp20x_ea->p_time[i].idx)
val = axp20x_ea->p_time[i].time;
return sprintf(buf, "%u\n", val);
}
static ssize_t axp20x_store_ext_attr(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct axp20x_pek *axp20x_pek = dev_get_drvdata(dev);
struct axp20x_pek_ext_attr *axp20x_ea = get_axp_ext_attr(attr);
char val_str[20];
size_t len;
int ret, i;
unsigned int val, idx = 0;
unsigned int best_err = UINT_MAX;
val_str[sizeof(val_str) - 1] = '\0';
strncpy(val_str, buf, sizeof(val_str) - 1);
len = strlen(val_str);
if (len && val_str[len - 1] == '\n')
val_str[len - 1] = '\0';
ret = kstrtouint(val_str, 10, &val);
if (ret)
return ret;
for (i = 3; i >= 0; i--) {
unsigned int err;
err = abs(axp20x_ea->p_time[i].time - val);
if (err < best_err) {
best_err = err;
idx = axp20x_ea->p_time[i].idx;
}
if (!err)
break;
}
idx <<= ffs(axp20x_ea->mask) - 1;
ret = regmap_update_bits(axp20x_pek->axp20x->regmap,
AXP20X_PEK_KEY,
axp20x_ea->mask, idx);
if (ret != 0)
return -EINVAL;
return count;
}
static irqreturn_t axp20x_pek_irq(int irq, void *pwr)
{
struct input_dev *idev = pwr;
struct axp20x_pek *axp20x_pek = input_get_drvdata(idev);
if (irq == axp20x_pek->irq_dbf)
input_report_key(idev, KEY_POWER, true);
else if (irq == axp20x_pek->irq_dbr)
input_report_key(idev, KEY_POWER, false);
input_sync(idev);
return IRQ_HANDLED;
}
static void axp20x_remove_sysfs_group(void *_data)
{
struct device *dev = _data;
sysfs_remove_group(&dev->kobj, &axp20x_attribute_group);
}
static int axp20x_pek_probe_input_device(struct axp20x_pek *axp20x_pek,
struct platform_device *pdev)
{
struct axp20x_dev *axp20x = axp20x_pek->axp20x;
struct input_dev *idev;
int error;
axp20x_pek->irq_dbr = platform_get_irq_byname(pdev, "PEK_DBR");
if (axp20x_pek->irq_dbr < 0) {
dev_err(&pdev->dev, "No IRQ for PEK_DBR, error=%d\n",
axp20x_pek->irq_dbr);
return axp20x_pek->irq_dbr;
}
axp20x_pek->irq_dbr = regmap_irq_get_virq(axp20x->regmap_irqc,
axp20x_pek->irq_dbr);
axp20x_pek->irq_dbf = platform_get_irq_byname(pdev, "PEK_DBF");
if (axp20x_pek->irq_dbf < 0) {
dev_err(&pdev->dev, "No IRQ for PEK_DBF, error=%d\n",
axp20x_pek->irq_dbf);
return axp20x_pek->irq_dbf;
}
axp20x_pek->irq_dbf = regmap_irq_get_virq(axp20x->regmap_irqc,
axp20x_pek->irq_dbf);
axp20x_pek->input = devm_input_allocate_device(&pdev->dev);
if (!axp20x_pek->input)
return -ENOMEM;
idev = axp20x_pek->input;
idev->name = "axp20x-pek";
idev->phys = "m1kbd/input2";
idev->dev.parent = &pdev->dev;
input_set_capability(idev, EV_KEY, KEY_POWER);
input_set_drvdata(idev, axp20x_pek);
error = devm_request_any_context_irq(&pdev->dev, axp20x_pek->irq_dbr,
axp20x_pek_irq, 0,
"axp20x-pek-dbr", idev);
if (error < 0) {
dev_err(&pdev->dev, "Failed to request dbr IRQ#%d: %d\n",
axp20x_pek->irq_dbr, error);
return error;
}
error = devm_request_any_context_irq(&pdev->dev, axp20x_pek->irq_dbf,
axp20x_pek_irq, 0,
"axp20x-pek-dbf", idev);
if (error < 0) {
dev_err(&pdev->dev, "Failed to request dbf IRQ#%d: %d\n",
axp20x_pek->irq_dbf, error);
return error;
}
error = input_register_device(idev);
if (error) {
dev_err(&pdev->dev, "Can't register input device: %d\n",
error);
return error;
}
return 0;
}
static bool axp20x_pek_should_register_input(struct axp20x_pek *axp20x_pek,
struct platform_device *pdev)
{
unsigned long long hrv = 0;
acpi_status status;
if (IS_ENABLED(CONFIG_INPUT_SOC_BUTTON_ARRAY) &&
axp20x_pek->axp20x->variant == AXP288_ID) {
status = acpi_evaluate_integer(ACPI_HANDLE(pdev->dev.parent),
"_HRV", NULL, &hrv);
if (ACPI_FAILURE(status))
dev_err(&pdev->dev, "Failed to get PMIC hardware revision\n");
if (hrv == 3 && (acpi_dev_present("INTCFD9", NULL, -1) ||
acpi_dev_present("ACPI0011", NULL, -1)))
return false;
}
return true;
}
static bool axp20x_pek_should_register_input(struct axp20x_pek *axp20x_pek,
struct platform_device *pdev)
{
return true;
}
static int axp20x_pek_probe(struct platform_device *pdev)
{
struct axp20x_pek *axp20x_pek;
int error;
axp20x_pek = devm_kzalloc(&pdev->dev, sizeof(struct axp20x_pek),
GFP_KERNEL);
if (!axp20x_pek)
return -ENOMEM;
axp20x_pek->axp20x = dev_get_drvdata(pdev->dev.parent);
if (axp20x_pek_should_register_input(axp20x_pek, pdev)) {
error = axp20x_pek_probe_input_device(axp20x_pek, pdev);
if (error)
return error;
}
error = sysfs_create_group(&pdev->dev.kobj, &axp20x_attribute_group);
if (error) {
dev_err(&pdev->dev, "Failed to create sysfs attributes: %d\n",
error);
return error;
}
error = devm_add_action(&pdev->dev,
axp20x_remove_sysfs_group, &pdev->dev);
if (error) {
axp20x_remove_sysfs_group(&pdev->dev);
dev_err(&pdev->dev, "Failed to add sysfs cleanup action: %d\n",
error);
return error;
}
platform_set_drvdata(pdev, axp20x_pek);
return 0;
}
