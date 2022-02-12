static ssize_t irst_show_wakeup_events(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct acpi_device *acpi;
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *result;
acpi_status status;
acpi = to_acpi_device(dev);
status = acpi_evaluate_object(acpi->handle, "GFFS", NULL, &output);
if (!ACPI_SUCCESS(status))
return -EINVAL;
result = output.pointer;
if (result->type != ACPI_TYPE_INTEGER) {
kfree(result);
return -EINVAL;
}
return sprintf(buf, "%lld\n", result->integer.value);
}
static ssize_t irst_store_wakeup_events(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct acpi_device *acpi;
struct acpi_object_list input;
union acpi_object param;
acpi_status status;
unsigned long value;
int error;
acpi = to_acpi_device(dev);
error = kstrtoul(buf, 0, &value);
if (error)
return error;
param.type = ACPI_TYPE_INTEGER;
param.integer.value = value;
input.count = 1;
input.pointer = &param;
status = acpi_evaluate_object(acpi->handle, "SFFS", &input, NULL);
if (!ACPI_SUCCESS(status))
return -EINVAL;
return count;
}
static ssize_t irst_show_wakeup_time(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct acpi_device *acpi;
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *result;
acpi_status status;
acpi = to_acpi_device(dev);
status = acpi_evaluate_object(acpi->handle, "GFTV", NULL, &output);
if (!ACPI_SUCCESS(status))
return -EINVAL;
result = output.pointer;
if (result->type != ACPI_TYPE_INTEGER) {
kfree(result);
return -EINVAL;
}
return sprintf(buf, "%lld\n", result->integer.value);
}
static ssize_t irst_store_wakeup_time(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct acpi_device *acpi;
struct acpi_object_list input;
union acpi_object param;
acpi_status status;
unsigned long value;
int error;
acpi = to_acpi_device(dev);
error = kstrtoul(buf, 0, &value);
if (error)
return error;
param.type = ACPI_TYPE_INTEGER;
param.integer.value = value;
input.count = 1;
input.pointer = &param;
status = acpi_evaluate_object(acpi->handle, "SFTV", &input, NULL);
if (!ACPI_SUCCESS(status))
return -EINVAL;
return count;
}
static int irst_add(struct acpi_device *acpi)
{
int error = 0;
error = device_create_file(&acpi->dev, &irst_timeout_attr);
if (error)
goto out;
error = device_create_file(&acpi->dev, &irst_wakeup_attr);
if (error)
goto out_timeout;
return 0;
out_timeout:
device_remove_file(&acpi->dev, &irst_timeout_attr);
out:
return error;
}
static int irst_remove(struct acpi_device *acpi)
{
device_remove_file(&acpi->dev, &irst_wakeup_attr);
device_remove_file(&acpi->dev, &irst_timeout_attr);
return 0;
}
