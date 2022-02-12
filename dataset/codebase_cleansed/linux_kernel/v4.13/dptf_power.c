static int dptf_power_add(struct platform_device *pdev)
{
struct acpi_device *acpi_dev;
acpi_status status;
unsigned long long ptype;
int result;
acpi_dev = ACPI_COMPANION(&(pdev->dev));
if (!acpi_dev)
return -ENODEV;
status = acpi_evaluate_integer(acpi_dev->handle, "PTYP", NULL, &ptype);
if (ACPI_FAILURE(status))
return -ENODEV;
if (ptype != 0x11)
return -ENODEV;
result = sysfs_create_group(&pdev->dev.kobj,
&dptf_power_attribute_group);
if (result)
return result;
platform_set_drvdata(pdev, acpi_dev);
return 0;
}
static int dptf_power_remove(struct platform_device *pdev)
{
sysfs_remove_group(&pdev->dev.kobj, &dptf_power_attribute_group);
return 0;
}
