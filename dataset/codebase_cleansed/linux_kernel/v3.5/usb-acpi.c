static int usb_acpi_check_upc(struct usb_device *udev, acpi_handle handle)
{
acpi_status status;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *upc;
int ret = 0;
status = acpi_evaluate_object(handle, "_UPC", NULL, &buffer);
if (ACPI_FAILURE(status))
return -ENODEV;
upc = buffer.pointer;
if (!upc || (upc->type != ACPI_TYPE_PACKAGE)
|| upc->package.count != 4) {
ret = -EINVAL;
goto out;
}
if (upc->package.elements[0].integer.value)
udev->removable = USB_DEVICE_REMOVABLE;
else
udev->removable = USB_DEVICE_FIXED;
out:
kfree(upc);
return ret;
}
static int usb_acpi_check_pld(struct usb_device *udev, acpi_handle handle)
{
acpi_status status;
struct acpi_pld pld;
status = acpi_get_physical_device_location(handle, &pld);
if (ACPI_FAILURE(status))
return -ENODEV;
if (pld.user_visible)
udev->removable = USB_DEVICE_REMOVABLE;
else
udev->removable = USB_DEVICE_FIXED;
return 0;
}
static int usb_acpi_find_device(struct device *dev, acpi_handle *handle)
{
struct usb_device *udev;
struct device *parent;
acpi_handle *parent_handle;
if (!is_usb_device(dev))
return -ENODEV;
udev = to_usb_device(dev);
parent = dev->parent;
parent_handle = DEVICE_ACPI_HANDLE(parent);
if (!parent_handle)
return -ENODEV;
*handle = acpi_get_child(parent_handle, udev->portnum);
if (!*handle)
return -ENODEV;
if (usb_acpi_check_pld(udev, *handle) != 0)
usb_acpi_check_upc(udev, *handle);
return 0;
}
int usb_acpi_register(void)
{
return register_acpi_bus_type(&usb_acpi_bus);
}
void usb_acpi_unregister(void)
{
unregister_acpi_bus_type(&usb_acpi_bus);
}
