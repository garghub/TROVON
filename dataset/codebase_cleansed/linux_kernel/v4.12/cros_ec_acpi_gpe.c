static u32 cros_ec_gpe_handler(acpi_handle gpe_device, u32 gpe_number,
void *data)
{
return ACPI_INTERRUPT_HANDLED | ACPI_REENABLE_GPE;
}
static int cros_ec_get_ec_wake_gpe(struct device *dev)
{
struct acpi_device *cros_acpi_dev;
struct acpi_device *adev;
acpi_handle handle;
acpi_status status;
int ret;
cros_acpi_dev = ACPI_COMPANION(dev);
if (!cros_acpi_dev || !cros_acpi_dev->parent ||
!cros_acpi_dev->parent->handle)
return -EINVAL;
status = acpi_get_handle(cros_acpi_dev->parent->handle, ACPI_LID_DEVICE,
&handle);
if (ACPI_FAILURE(status))
return -EINVAL;
ret = acpi_bus_get_device(handle, &adev);
if (ret)
return ret;
return adev->wakeup.gpe_number;
}
int cros_ec_acpi_install_gpe_handler(struct device *dev)
{
acpi_status status;
ec_wake_gpe = cros_ec_get_ec_wake_gpe(dev);
if (ec_wake_gpe < 0)
return ec_wake_gpe;
status = acpi_install_gpe_handler(NULL, ec_wake_gpe,
ACPI_GPE_EDGE_TRIGGERED,
&cros_ec_gpe_handler, NULL);
if (ACPI_FAILURE(status))
return -ENODEV;
dev_info(dev, "Initialized, GPE = 0x%x\n", ec_wake_gpe);
return 0;
}
void cros_ec_acpi_remove_gpe_handler(void)
{
acpi_status status;
if (ec_wake_gpe < 0)
return;
status = acpi_remove_gpe_handler(NULL, ec_wake_gpe,
&cros_ec_gpe_handler);
if (ACPI_FAILURE(status))
pr_err("failed to remove gpe handler\n");
}
void cros_ec_acpi_clear_gpe(void)
{
if (ec_wake_gpe < 0)
return;
acpi_clear_gpe(NULL, ec_wake_gpe);
}
