static int smartconnect_acpi_init(struct acpi_device *acpi)
{
unsigned long long value;
acpi_status status;
status = acpi_evaluate_integer(acpi->handle, "GAOS", NULL, &value);
if (ACPI_FAILURE(status))
return -EINVAL;
if (value & 0x1) {
dev_info(&acpi->dev, "Disabling Intel Smart Connect\n");
status = acpi_execute_simple_method(acpi->handle, "SAOS", 0);
}
return 0;
}
