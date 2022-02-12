static int ebook_send_state(struct acpi_device *device)
{
struct ebook_switch *button = acpi_driver_data(device);
unsigned long long state;
acpi_status status;
status = acpi_evaluate_integer(device->handle, "EBK", NULL, &state);
if (ACPI_FAILURE(status))
return -EIO;
input_report_switch(button->input, SW_TABLET_MODE, !state);
input_sync(button->input);
return 0;
}
static void ebook_switch_notify(struct acpi_device *device, u32 event)
{
switch (event) {
case ACPI_FIXED_HARDWARE_EVENT:
case XO15_EBOOK_NOTIFY_STATUS:
ebook_send_state(device);
break;
default:
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Unsupported event [0x%x]\n", event));
break;
}
}
static int ebook_switch_resume(struct device *dev)
{
return ebook_send_state(to_acpi_device(dev));
}
static int ebook_switch_add(struct acpi_device *device)
{
struct ebook_switch *button;
struct input_dev *input;
const char *hid = acpi_device_hid(device);
char *name, *class;
int error;
button = kzalloc(sizeof(struct ebook_switch), GFP_KERNEL);
if (!button)
return -ENOMEM;
device->driver_data = button;
button->input = input = input_allocate_device();
if (!input) {
error = -ENOMEM;
goto err_free_button;
}
name = acpi_device_name(device);
class = acpi_device_class(device);
if (strcmp(hid, XO15_EBOOK_HID)) {
pr_err("Unsupported hid [%s]\n", hid);
error = -ENODEV;
goto err_free_input;
}
strcpy(name, XO15_EBOOK_DEVICE_NAME);
sprintf(class, "%s/%s", XO15_EBOOK_CLASS, XO15_EBOOK_SUBCLASS);
snprintf(button->phys, sizeof(button->phys), "%s/button/input0", hid);
input->name = name;
input->phys = button->phys;
input->id.bustype = BUS_HOST;
input->dev.parent = &device->dev;
input->evbit[0] = BIT_MASK(EV_SW);
set_bit(SW_TABLET_MODE, input->swbit);
error = input_register_device(input);
if (error)
goto err_free_input;
ebook_send_state(device);
if (device->wakeup.flags.valid) {
acpi_enable_gpe(device->wakeup.gpe_device,
device->wakeup.gpe_number);
device_set_wakeup_enable(&device->dev, true);
}
return 0;
err_free_input:
input_free_device(input);
err_free_button:
kfree(button);
return error;
}
static int ebook_switch_remove(struct acpi_device *device, int type)
{
struct ebook_switch *button = acpi_driver_data(device);
input_unregister_device(button->input);
kfree(button);
return 0;
}
