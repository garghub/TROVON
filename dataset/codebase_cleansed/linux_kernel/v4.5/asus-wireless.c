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
return input_register_device(data->idev);
}
static int asus_wireless_remove(struct acpi_device *adev)
{
return 0;
}
