static u64 asus_wireless_method(acpi_handle handle, const char *method,
int param)
{
struct acpi_object_list p;
union acpi_object obj;
acpi_status s;
u64 ret;
acpi_handle_debug(handle, "Evaluating method %s, parameter %#x\n",
method, param);
obj.type = ACPI_TYPE_INTEGER;
obj.integer.value = param;
p.count = 1;
p.pointer = &obj;
s = acpi_evaluate_integer(handle, (acpi_string) method, &p, &ret);
if (ACPI_FAILURE(s))
acpi_handle_err(handle,
"Failed to eval method %s, param %#x (%d)\n",
method, param, s);
acpi_handle_debug(handle, "%s returned %#x\n", method, (uint) ret);
return ret;
}
static enum led_brightness led_state_get(struct led_classdev *led)
{
struct asus_wireless_data *data;
int s;
data = container_of(led, struct asus_wireless_data, led);
s = asus_wireless_method(acpi_device_handle(data->adev), "HSWC",
ASUS_WIRELESS_LED_STATUS);
if (s == ASUS_WIRELESS_LED_ON)
return LED_FULL;
return LED_OFF;
}
static void led_state_update(struct work_struct *work)
{
struct asus_wireless_data *data;
data = container_of(work, struct asus_wireless_data, led_work);
asus_wireless_method(acpi_device_handle(data->adev), "HSWC",
data->led_state);
}
static void led_state_set(struct led_classdev *led,
enum led_brightness value)
{
struct asus_wireless_data *data;
data = container_of(led, struct asus_wireless_data, led);
data->led_state = value == LED_OFF ? ASUS_WIRELESS_LED_OFF :
ASUS_WIRELESS_LED_ON;
queue_work(data->wq, &data->led_work);
}
static void asus_wireless_notify(struct acpi_device *adev, u32 event)
{
struct asus_wireless_data *data = acpi_driver_data(adev);
dev_dbg(&adev->dev, "event=%#x\n", event);
if (event != 0x88) {
dev_notice(&adev->dev, "Unknown ASHS event: %#x\n", event);
return;
}
input_report_key(data->idev, KEY_RFKILL, 1);
input_report_key(data->idev, KEY_RFKILL, 0);
input_sync(data->idev);
}
static int asus_wireless_add(struct acpi_device *adev)
{
struct asus_wireless_data *data;
int err;
data = devm_kzalloc(&adev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
adev->driver_data = data;
data->idev = devm_input_allocate_device(&adev->dev);
if (!data->idev)
return -ENOMEM;
data->idev->name = "Asus Wireless Radio Control";
data->idev->phys = "asus-wireless/input0";
data->idev->id.bustype = BUS_HOST;
data->idev->id.vendor = PCI_VENDOR_ID_ASUSTEK;
set_bit(EV_KEY, data->idev->evbit);
set_bit(KEY_RFKILL, data->idev->keybit);
err = input_register_device(data->idev);
if (err)
return err;
data->adev = adev;
data->wq = create_singlethread_workqueue("asus_wireless_workqueue");
if (!data->wq)
return -ENOMEM;
INIT_WORK(&data->led_work, led_state_update);
data->led.name = "asus-wireless::airplane";
data->led.brightness_set = led_state_set;
data->led.brightness_get = led_state_get;
data->led.flags = LED_CORE_SUSPENDRESUME;
data->led.max_brightness = 1;
err = devm_led_classdev_register(&adev->dev, &data->led);
if (err)
destroy_workqueue(data->wq);
return err;
}
static int asus_wireless_remove(struct acpi_device *adev)
{
struct asus_wireless_data *data = acpi_driver_data(adev);
if (data->wq)
destroy_workqueue(data->wq);
return 0;
}
