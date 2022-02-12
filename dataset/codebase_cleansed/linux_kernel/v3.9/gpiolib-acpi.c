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
static irqreturn_t acpi_gpio_irq_handler(int irq, void *data)
{
acpi_handle handle = data;
acpi_evaluate_object(handle, NULL, NULL, NULL);
return IRQ_HANDLED;
}
void acpi_gpiochip_request_interrupts(struct gpio_chip *chip)
{
struct acpi_buffer buf = {ACPI_ALLOCATE_BUFFER, NULL};
struct acpi_resource *res;
acpi_handle handle, ev_handle;
acpi_status status;
unsigned int pin;
int irq, ret;
char ev_name[5];
if (!chip->dev || !chip->to_irq)
return;
handle = ACPI_HANDLE(chip->dev);
if (!handle)
return;
status = acpi_get_event_resources(handle, &buf);
if (ACPI_FAILURE(status))
return;
for (res = buf.pointer;
res && (res->type != ACPI_RESOURCE_TYPE_END_TAG);
res = ACPI_NEXT_RESOURCE(res)) {
if (res->type != ACPI_RESOURCE_TYPE_GPIO ||
res->data.gpio.connection_type !=
ACPI_RESOURCE_GPIO_TYPE_INT)
continue;
pin = res->data.gpio.pin_table[0];
if (pin > chip->ngpio)
continue;
sprintf(ev_name, "_%c%02X",
res->data.gpio.triggering ? 'E' : 'L', pin);
status = acpi_get_handle(handle, ev_name, &ev_handle);
if (ACPI_FAILURE(status))
continue;
irq = chip->to_irq(chip, pin);
if (irq < 0)
continue;
ret = devm_request_threaded_irq(chip->dev, irq, NULL,
acpi_gpio_irq_handler,
0,
"GPIO-signaled-ACPI-event",
ev_handle);
if (ret)
dev_err(chip->dev,
"Failed to request IRQ %d ACPI event handler\n",
irq);
}
}
