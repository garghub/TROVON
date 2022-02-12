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
static irqreturn_t acpi_gpio_irq_handler_evt(int irq, void *data)
{
struct acpi_gpio_evt_pin *evt_pin = data;
struct acpi_object_list args;
union acpi_object arg;
arg.type = ACPI_TYPE_INTEGER;
arg.integer.value = evt_pin->pin;
args.count = 1;
args.pointer = &arg;
acpi_evaluate_object(evt_pin->evt_handle, NULL, &args, NULL);
return IRQ_HANDLED;
}
static void acpi_gpio_evt_dh(acpi_handle handle, void *data)
{
}
void acpi_gpiochip_request_interrupts(struct gpio_chip *chip)
{
struct acpi_buffer buf = {ACPI_ALLOCATE_BUFFER, NULL};
struct acpi_resource *res;
acpi_handle handle, evt_handle;
struct list_head *evt_pins = NULL;
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
status = acpi_get_handle(handle, "_EVT", &evt_handle);
if (ACPI_SUCCESS(status)) {
evt_pins = kzalloc(sizeof(*evt_pins), GFP_KERNEL);
if (evt_pins) {
INIT_LIST_HEAD(evt_pins);
status = acpi_attach_data(handle, acpi_gpio_evt_dh,
evt_pins);
if (ACPI_FAILURE(status)) {
kfree(evt_pins);
evt_pins = NULL;
}
}
}
for (res = buf.pointer;
res && (res->type != ACPI_RESOURCE_TYPE_END_TAG);
res = ACPI_NEXT_RESOURCE(res)) {
irq_handler_t handler = NULL;
void *data;
if (res->type != ACPI_RESOURCE_TYPE_GPIO ||
res->data.gpio.connection_type !=
ACPI_RESOURCE_GPIO_TYPE_INT)
continue;
pin = res->data.gpio.pin_table[0];
if (pin > chip->ngpio)
continue;
irq = chip->to_irq(chip, pin);
if (irq < 0)
continue;
if (pin <= 255) {
acpi_handle ev_handle;
sprintf(ev_name, "_%c%02X",
res->data.gpio.triggering ? 'E' : 'L', pin);
status = acpi_get_handle(handle, ev_name, &ev_handle);
if (ACPI_SUCCESS(status)) {
handler = acpi_gpio_irq_handler;
data = ev_handle;
}
}
if (!handler && evt_pins) {
struct acpi_gpio_evt_pin *evt_pin;
evt_pin = kzalloc(sizeof(*evt_pin), GFP_KERNEL);
if (!evt_pin)
continue;
list_add_tail(&evt_pin->node, evt_pins);
evt_pin->evt_handle = evt_handle;
evt_pin->pin = pin;
evt_pin->irq = irq;
handler = acpi_gpio_irq_handler_evt;
data = evt_pin;
}
if (!handler)
continue;
ret = devm_request_threaded_irq(chip->dev, irq, NULL, handler,
0, "GPIO-signaled-ACPI-event",
data);
if (ret)
dev_err(chip->dev,
"Failed to request IRQ %d ACPI event handler\n",
irq);
}
}
static int acpi_find_gpio(struct acpi_resource *ares, void *data)
{
struct acpi_gpio_lookup *lookup = data;
if (ares->type != ACPI_RESOURCE_TYPE_GPIO)
return 1;
if (lookup->n++ == lookup->index && lookup->gpio < 0) {
const struct acpi_resource_gpio *agpio = &ares->data.gpio;
lookup->gpio = acpi_get_gpio(agpio->resource_source.string_ptr,
agpio->pin_table[0]);
lookup->info.gpioint =
agpio->connection_type == ACPI_RESOURCE_GPIO_TYPE_INT;
}
return 1;
}
int acpi_get_gpio_by_index(struct device *dev, int index,
struct acpi_gpio_info *info)
{
struct acpi_gpio_lookup lookup;
struct list_head resource_list;
struct acpi_device *adev;
acpi_handle handle;
int ret;
if (!dev)
return -EINVAL;
handle = ACPI_HANDLE(dev);
if (!handle || acpi_bus_get_device(handle, &adev))
return -ENODEV;
memset(&lookup, 0, sizeof(lookup));
lookup.index = index;
lookup.gpio = -ENODEV;
INIT_LIST_HEAD(&resource_list);
ret = acpi_dev_get_resources(adev, &resource_list, acpi_find_gpio,
&lookup);
if (ret < 0)
return ret;
acpi_dev_free_resource_list(&resource_list);
if (lookup.gpio >= 0 && info)
*info = lookup.info;
return lookup.gpio;
}
void acpi_gpiochip_free_interrupts(struct gpio_chip *chip)
{
acpi_handle handle;
acpi_status status;
struct list_head *evt_pins;
struct acpi_gpio_evt_pin *evt_pin, *ep;
if (!chip->dev || !chip->to_irq)
return;
handle = ACPI_HANDLE(chip->dev);
if (!handle)
return;
status = acpi_get_data(handle, acpi_gpio_evt_dh, (void **)&evt_pins);
if (ACPI_FAILURE(status))
return;
list_for_each_entry_safe_reverse(evt_pin, ep, evt_pins, node) {
devm_free_irq(chip->dev, evt_pin->irq, evt_pin);
list_del(&evt_pin->node);
kfree(evt_pin);
}
acpi_detach_data(handle, acpi_gpio_evt_dh);
kfree(evt_pins);
}
