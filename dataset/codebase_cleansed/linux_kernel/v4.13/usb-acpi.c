bool usb_acpi_power_manageable(struct usb_device *hdev, int index)
{
acpi_handle port_handle;
int port1 = index + 1;
port_handle = usb_get_hub_port_acpi_handle(hdev,
port1);
if (port_handle)
return acpi_bus_power_manageable(port_handle);
else
return false;
}
int usb_acpi_set_power_state(struct usb_device *hdev, int index, bool enable)
{
struct usb_hub *hub = usb_hub_to_struct_hub(hdev);
struct usb_port *port_dev;
acpi_handle port_handle;
unsigned char state;
int port1 = index + 1;
int error = -EINVAL;
if (!hub)
return -ENODEV;
port_dev = hub->ports[port1 - 1];
port_handle = (acpi_handle) usb_get_hub_port_acpi_handle(hdev, port1);
if (!port_handle)
return error;
if (enable)
state = ACPI_STATE_D0;
else
state = ACPI_STATE_D3_COLD;
error = acpi_bus_set_power(port_handle, state);
if (!error)
dev_dbg(&port_dev->dev, "acpi: power was set to %d\n", enable);
else
dev_dbg(&port_dev->dev, "acpi: power failed to be set\n");
return error;
}
static enum usb_port_connect_type usb_acpi_get_connect_type(acpi_handle handle,
struct acpi_pld_info *pld)
{
enum usb_port_connect_type connect_type = USB_PORT_CONNECT_TYPE_UNKNOWN;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *upc;
acpi_status status;
status = acpi_evaluate_object(handle, "_UPC", NULL, &buffer);
upc = buffer.pointer;
if (!upc || (upc->type != ACPI_TYPE_PACKAGE)
|| upc->package.count != 4) {
goto out;
}
if (upc->package.elements[0].integer.value)
if (pld->user_visible)
connect_type = USB_PORT_CONNECT_TYPE_HOT_PLUG;
else
connect_type = USB_PORT_CONNECT_TYPE_HARD_WIRED;
else if (!pld->user_visible)
connect_type = USB_PORT_NOT_USED;
out:
kfree(upc);
return connect_type;
}
static struct acpi_device *usb_acpi_find_port(struct acpi_device *parent,
int raw)
{
struct acpi_device *adev;
if (!parent)
return NULL;
list_for_each_entry(adev, &parent->children, node) {
if (acpi_device_adr(adev) == raw)
return adev;
}
return acpi_find_child_device(parent, raw, false);
}
static struct acpi_device *usb_acpi_find_companion(struct device *dev)
{
struct usb_device *udev;
struct acpi_device *adev;
acpi_handle *parent_handle;
if (is_usb_device(dev)) {
udev = to_usb_device(dev);
if (udev->parent)
return NULL;
adev = ACPI_COMPANION(dev->parent);
return acpi_find_child_device(adev, 0, false);
} else if (is_usb_port(dev)) {
struct usb_port *port_dev = to_usb_port(dev);
int port1 = port_dev->portnum;
struct acpi_pld_info *pld;
acpi_handle *handle;
acpi_status status;
udev = to_usb_device(dev->parent->parent);
if (!udev->parent) {
struct usb_hcd *hcd = bus_to_hcd(udev->bus);
int raw;
raw = usb_hcd_find_raw_port_number(hcd, port1);
adev = usb_acpi_find_port(ACPI_COMPANION(&udev->dev),
raw);
if (!adev)
return NULL;
} else {
parent_handle =
usb_get_hub_port_acpi_handle(udev->parent,
udev->portnum);
if (!parent_handle)
return NULL;
acpi_bus_get_device(parent_handle, &adev);
adev = usb_acpi_find_port(adev, port1);
if (!adev)
return NULL;
}
handle = adev->handle;
status = acpi_get_physical_device_location(handle, &pld);
if (ACPI_FAILURE(status) || !pld)
return adev;
port_dev->location = USB_ACPI_LOCATION_VALID
| pld->group_token << 8 | pld->group_position;
port_dev->connect_type = usb_acpi_get_connect_type(handle, pld);
ACPI_FREE(pld);
return adev;
}
return NULL;
}
static bool usb_acpi_bus_match(struct device *dev)
{
return is_usb_device(dev) || is_usb_port(dev);
}
int usb_acpi_register(void)
{
return register_acpi_bus_type(&usb_acpi_bus);
}
void usb_acpi_unregister(void)
{
unregister_acpi_bus_type(&usb_acpi_bus);
}
