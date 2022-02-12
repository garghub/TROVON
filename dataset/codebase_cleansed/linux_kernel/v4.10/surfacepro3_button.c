static void surface_button_notify(struct acpi_device *device, u32 event)
{
struct surface_button *button = acpi_driver_data(device);
struct input_dev *input;
int key_code = KEY_RESERVED;
bool pressed = false;
switch (event) {
case SURFACE_BUTTON_NOTIFY_PRESS_POWER:
pressed = true;
case SURFACE_BUTTON_NOTIFY_RELEASE_POWER:
key_code = KEY_POWER;
break;
case SURFACE_BUTTON_NOTIFY_PRESS_HOME:
pressed = true;
case SURFACE_BUTTON_NOTIFY_RELEASE_HOME:
key_code = KEY_LEFTMETA;
break;
case SURFACE_BUTTON_NOTIFY_PRESS_VOLUME_UP:
pressed = true;
case SURFACE_BUTTON_NOTIFY_RELEASE_VOLUME_UP:
key_code = KEY_VOLUMEUP;
break;
case SURFACE_BUTTON_NOTIFY_PRESS_VOLUME_DOWN:
pressed = true;
case SURFACE_BUTTON_NOTIFY_RELEASE_VOLUME_DOWN:
key_code = KEY_VOLUMEDOWN;
break;
case SURFACE_BUTTON_NOTIFY_TABLET_MODE:
dev_warn_once(&device->dev, "Tablet mode is not supported\n");
break;
default:
dev_info_ratelimited(&device->dev,
"Unsupported event [0x%x]\n", event);
break;
}
input = button->input;
if (key_code == KEY_RESERVED)
return;
if (pressed)
pm_wakeup_event(&device->dev, 0);
if (button->suspended)
return;
input_report_key(input, key_code, pressed?1:0);
input_sync(input);
}
static int surface_button_suspend(struct device *dev)
{
struct acpi_device *device = to_acpi_device(dev);
struct surface_button *button = acpi_driver_data(device);
button->suspended = true;
return 0;
}
static int surface_button_resume(struct device *dev)
{
struct acpi_device *device = to_acpi_device(dev);
struct surface_button *button = acpi_driver_data(device);
button->suspended = false;
return 0;
}
static int surface_button_add(struct acpi_device *device)
{
struct surface_button *button;
struct input_dev *input;
const char *hid = acpi_device_hid(device);
char *name;
int error;
if (strncmp(acpi_device_bid(device), SURFACE_BUTTON_OBJ_NAME,
strlen(SURFACE_BUTTON_OBJ_NAME)))
return -ENODEV;
button = kzalloc(sizeof(struct surface_button), GFP_KERNEL);
if (!button)
return -ENOMEM;
device->driver_data = button;
button->input = input = input_allocate_device();
if (!input) {
error = -ENOMEM;
goto err_free_button;
}
name = acpi_device_name(device);
strcpy(name, SURFACE_BUTTON_DEVICE_NAME);
snprintf(button->phys, sizeof(button->phys), "%s/buttons", hid);
input->name = name;
input->phys = button->phys;
input->id.bustype = BUS_HOST;
input->dev.parent = &device->dev;
input_set_capability(input, EV_KEY, KEY_POWER);
input_set_capability(input, EV_KEY, KEY_LEFTMETA);
input_set_capability(input, EV_KEY, KEY_VOLUMEUP);
input_set_capability(input, EV_KEY, KEY_VOLUMEDOWN);
error = input_register_device(input);
if (error)
goto err_free_input;
dev_info(&device->dev,
"%s [%s]\n", name, acpi_device_bid(device));
return 0;
err_free_input:
input_free_device(input);
err_free_button:
kfree(button);
return error;
}
static int surface_button_remove(struct acpi_device *device)
{
struct surface_button *button = acpi_driver_data(device);
input_unregister_device(button->input);
kfree(button);
return 0;
}
