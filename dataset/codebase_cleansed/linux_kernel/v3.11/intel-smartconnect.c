static int smartconnect_acpi_init(struct acpi_device *acpi)
{
struct acpi_object_list input;
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *result;
union acpi_object param;
acpi_status status;
status = acpi_evaluate_object(acpi->handle, "GAOS", NULL, &output);
if (!ACPI_SUCCESS(status))
return -EINVAL;
result = output.pointer;
if (result->type != ACPI_TYPE_INTEGER) {
kfree(result);
return -EINVAL;
}
if (result->integer.value & 0x1) {
param.type = ACPI_TYPE_INTEGER;
param.integer.value = 0;
input.count = 1;
input.pointer = &param;
dev_info(&acpi->dev, "Disabling Intel Smart Connect\n");
status = acpi_evaluate_object(acpi->handle, "SAOS", &input,
NULL);
}
kfree(result);
return 0;
}
static int smartconnect_init(void)
{
return acpi_bus_register_driver(&smartconnect_driver);
}
static void smartconnect_exit(void)
{
acpi_bus_unregister_driver(&smartconnect_driver);
}
