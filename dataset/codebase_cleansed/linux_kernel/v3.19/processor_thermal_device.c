static int proc_thermal_add(struct device *dev,
struct proc_thermal_device **priv)
{
struct proc_thermal_device *proc_priv;
struct acpi_device *adev;
acpi_status status;
struct acpi_buffer buf = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *elements, *ppcc;
union acpi_object *p;
int i;
int ret;
adev = ACPI_COMPANION(dev);
if (!adev)
return -ENODEV;
status = acpi_evaluate_object(adev->handle, "PPCC", NULL, &buf);
if (ACPI_FAILURE(status))
return -ENODEV;
p = buf.pointer;
if (!p || (p->type != ACPI_TYPE_PACKAGE)) {
dev_err(dev, "Invalid PPCC data\n");
ret = -EFAULT;
goto free_buffer;
}
if (!p->package.count) {
dev_err(dev, "Invalid PPCC package size\n");
ret = -EFAULT;
goto free_buffer;
}
proc_priv = devm_kzalloc(dev, sizeof(*proc_priv), GFP_KERNEL);
if (!proc_priv) {
ret = -ENOMEM;
goto free_buffer;
}
proc_priv->dev = dev;
proc_priv->adev = adev;
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
*priv = proc_priv;
ret = sysfs_create_group(&dev->kobj,
&power_limit_attribute_group);
free_buffer:
kfree(buf.pointer);
return ret;
}
void proc_thermal_remove(struct proc_thermal_device *proc_priv)
{
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
return 0;
}
static void proc_thermal_pci_remove(struct pci_dev *pdev)
{
proc_thermal_remove(pci_get_drvdata(pdev));
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
