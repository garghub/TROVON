static int get_tjmax(void)
{
u32 eax, edx;
u32 val;
int err;
err = rdmsr_safe(MSR_IA32_TEMPERATURE_TARGET, &eax, &edx);
if (err)
return err;
val = (eax >> 16) & 0xff;
if (val)
return val;
return -EINVAL;
}
static int read_temp_msr(int *temp)
{
int cpu;
u32 eax, edx;
int err;
unsigned long curr_temp_off = 0;
*temp = 0;
for_each_online_cpu(cpu) {
err = rdmsr_safe_on_cpu(cpu, MSR_IA32_THERM_STATUS, &eax,
&edx);
if (err)
goto err_ret;
else {
if (eax & 0x80000000) {
curr_temp_off = (eax >> 16) & 0x7f;
if (!*temp || curr_temp_off < *temp)
*temp = curr_temp_off;
} else {
err = -EINVAL;
goto err_ret;
}
}
}
return 0;
err_ret:
return err;
}
static int proc_thermal_get_zone_temp(struct thermal_zone_device *zone,
int *temp)
{
int ret;
ret = read_temp_msr(temp);
if (!ret)
*temp = (stored_tjmax - *temp) * 1000;
return ret;
}
static int proc_thermal_read_ppcc(struct proc_thermal_device *proc_priv)
{
int i;
acpi_status status;
struct acpi_buffer buf = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *elements, *ppcc;
union acpi_object *p;
int ret = 0;
status = acpi_evaluate_object(proc_priv->adev->handle, "PPCC",
NULL, &buf);
if (ACPI_FAILURE(status))
return -ENODEV;
p = buf.pointer;
if (!p || (p->type != ACPI_TYPE_PACKAGE)) {
dev_err(proc_priv->dev, "Invalid PPCC data\n");
ret = -EFAULT;
goto free_buffer;
}
if (!p->package.count) {
dev_err(proc_priv->dev, "Invalid PPCC package size\n");
ret = -EFAULT;
goto free_buffer;
}
for (i = 0; i < min((int)p->package.count - 1, 2); ++i) {
elements = &(p->package.elements[i+1]);
if (elements->type != ACPI_TYPE_PACKAGE ||
elements->package.count != 6) {
ret = -EFAULT;
goto free_buffer;
}
ppcc = elements->package.elements;
proc_priv->power_limits[i].index = ppcc[0].integer.value;
proc_priv->power_limits[i].min_uw = ppcc[1].integer.value;
proc_priv->power_limits[i].max_uw = ppcc[2].integer.value;
proc_priv->power_limits[i].tmin_us = ppcc[3].integer.value;
proc_priv->power_limits[i].tmax_us = ppcc[4].integer.value;
proc_priv->power_limits[i].step_uw = ppcc[5].integer.value;
}
free_buffer:
kfree(buf.pointer);
return ret;
}
static void proc_thermal_notify(acpi_handle handle, u32 event, void *data)
{
struct proc_thermal_device *proc_priv = data;
if (!proc_priv)
return;
switch (event) {
case PROC_POWER_CAPABILITY_CHANGED:
proc_thermal_read_ppcc(proc_priv);
int340x_thermal_zone_device_update(proc_priv->int340x_zone,
THERMAL_DEVICE_POWER_CAPABILITY_CHANGED);
break;
default:
dev_err(proc_priv->dev, "Unsupported event [0x%x]\n", event);
break;
}
}
static int proc_thermal_add(struct device *dev,
struct proc_thermal_device **priv)
{
struct proc_thermal_device *proc_priv;
struct acpi_device *adev;
acpi_status status;
unsigned long long tmp;
struct thermal_zone_device_ops *ops = NULL;
int ret;
adev = ACPI_COMPANION(dev);
if (!adev)
return -ENODEV;
proc_priv = devm_kzalloc(dev, sizeof(*proc_priv), GFP_KERNEL);
if (!proc_priv)
return -ENOMEM;
proc_priv->dev = dev;
proc_priv->adev = adev;
*priv = proc_priv;
ret = proc_thermal_read_ppcc(proc_priv);
if (!ret) {
ret = sysfs_create_group(&dev->kobj,
&power_limit_attribute_group);
}
if (ret)
return ret;
status = acpi_evaluate_integer(adev->handle, "_TMP", NULL, &tmp);
if (ACPI_FAILURE(status)) {
stored_tjmax = get_tjmax();
if (stored_tjmax > 0)
ops = &proc_thermal_local_ops;
}
proc_priv->int340x_zone = int340x_thermal_zone_add(adev, ops);
if (IS_ERR(proc_priv->int340x_zone)) {
ret = PTR_ERR(proc_priv->int340x_zone);
goto remove_group;
} else
ret = 0;
ret = acpi_install_notify_handler(adev->handle, ACPI_DEVICE_NOTIFY,
proc_thermal_notify,
(void *)proc_priv);
if (ret)
goto remove_zone;
return 0;
remove_zone:
int340x_thermal_zone_remove(proc_priv->int340x_zone);
remove_group:
sysfs_remove_group(&proc_priv->dev->kobj,
&power_limit_attribute_group);
return ret;
}
static void proc_thermal_remove(struct proc_thermal_device *proc_priv)
{
acpi_remove_notify_handler(proc_priv->adev->handle,
ACPI_DEVICE_NOTIFY, proc_thermal_notify);
int340x_thermal_zone_remove(proc_priv->int340x_zone);
sysfs_remove_group(&proc_priv->dev->kobj,
&power_limit_attribute_group);
}
static int int3401_add(struct platform_device *pdev)
{
struct proc_thermal_device *proc_priv;
int ret;
if (proc_thermal_emum_mode == PROC_THERMAL_PCI) {
dev_err(&pdev->dev, "error: enumerated as PCI dev\n");
return -ENODEV;
}
ret = proc_thermal_add(&pdev->dev, &proc_priv);
if (ret)
return ret;
platform_set_drvdata(pdev, proc_priv);
proc_thermal_emum_mode = PROC_THERMAL_PLATFORM_DEV;
return 0;
}
static int int3401_remove(struct platform_device *pdev)
{
proc_thermal_remove(platform_get_drvdata(pdev));
return 0;
}
static irqreturn_t proc_thermal_pci_msi_irq(int irq, void *devid)
{
struct proc_thermal_device *proc_priv;
struct pci_dev *pdev = devid;
proc_priv = pci_get_drvdata(pdev);
intel_soc_dts_iosf_interrupt_handler(proc_priv->soc_dts);
return IRQ_HANDLED;
}
static int proc_thermal_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *unused)
{
struct proc_thermal_device *proc_priv;
int ret;
if (proc_thermal_emum_mode == PROC_THERMAL_PLATFORM_DEV) {
dev_err(&pdev->dev, "error: enumerated as platform dev\n");
return -ENODEV;
}
ret = pci_enable_device(pdev);
if (ret < 0) {
dev_err(&pdev->dev, "error: could not enable device\n");
return ret;
}
ret = proc_thermal_add(&pdev->dev, &proc_priv);
if (ret) {
pci_disable_device(pdev);
return ret;
}
pci_set_drvdata(pdev, proc_priv);
proc_thermal_emum_mode = PROC_THERMAL_PCI;
if (pdev->device == PCI_DEVICE_ID_PROC_BSW_THERMAL) {
proc_priv->soc_dts = intel_soc_dts_iosf_init(
INTEL_SOC_DTS_INTERRUPT_MSI, 2, 0);
if (proc_priv->soc_dts && pdev->irq) {
ret = pci_enable_msi(pdev);
if (!ret) {
ret = request_threaded_irq(pdev->irq, NULL,
proc_thermal_pci_msi_irq,
IRQF_ONESHOT, "proc_thermal",
pdev);
if (ret) {
intel_soc_dts_iosf_exit(
proc_priv->soc_dts);
pci_disable_msi(pdev);
proc_priv->soc_dts = NULL;
}
}
} else
dev_err(&pdev->dev, "No auxiliary DTSs enabled\n");
}
return 0;
}
static void proc_thermal_pci_remove(struct pci_dev *pdev)
{
struct proc_thermal_device *proc_priv = pci_get_drvdata(pdev);
if (proc_priv->soc_dts) {
intel_soc_dts_iosf_exit(proc_priv->soc_dts);
if (pdev->irq) {
free_irq(pdev->irq, pdev);
pci_disable_msi(pdev);
}
}
proc_thermal_remove(proc_priv);
pci_disable_device(pdev);
}
static int __init proc_thermal_init(void)
{
int ret;
ret = platform_driver_register(&int3401_driver);
if (ret)
return ret;
ret = pci_register_driver(&proc_thermal_pci_driver);
return ret;
}
static void __exit proc_thermal_exit(void)
{
platform_driver_unregister(&int3401_driver);
pci_unregister_driver(&proc_thermal_pci_driver);
}
