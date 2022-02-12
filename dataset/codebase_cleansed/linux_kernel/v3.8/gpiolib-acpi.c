static int acpi_gpiochip_find(struct gpio_chip *gc, void *data)
{
if (!gc->dev)
return false;
return ACPI_HANDLE(gc->dev) == data;
}
int acpi_get_gpio(char *path, int pin)
{
struct gpio_chip *chip;
acpi_handle handle;
acpi_status status;
status = acpi_get_handle(NULL, path, &handle);
if (ACPI_FAILURE(status))
return -ENODEV;
chip = gpiochip_find(handle, acpi_gpiochip_find);
if (!chip)
return -ENODEV;
if (!gpio_is_valid(chip->base + pin))
return -EINVAL;
return chip->base + pin;
}
