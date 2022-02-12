static void bcm203x_complete(struct urb *urb)
{
struct bcm203x_data *data = urb->context;
struct usb_device *udev = urb->dev;
int len;
BT_DBG("udev %p urb %p", udev, urb);
if (urb->status) {
BT_ERR("URB failed with status %d", urb->status);
data->state = BCM203X_ERROR;
return;
}
switch (data->state) {
case BCM203X_LOAD_MINIDRV:
memcpy(data->buffer, "#", 1);
usb_fill_bulk_urb(urb, udev, usb_sndbulkpipe(udev, BCM203X_OUT_EP),
data->buffer, 1, bcm203x_complete, data);
data->state = BCM203X_SELECT_MEMORY;
schedule_work(&data->work);
break;
case BCM203X_SELECT_MEMORY:
usb_fill_int_urb(urb, udev, usb_rcvintpipe(udev, BCM203X_IN_EP),
data->buffer, 32, bcm203x_complete, data, 1);
data->state = BCM203X_CHECK_MEMORY;
if (usb_submit_urb(data->urb, GFP_ATOMIC) < 0)
BT_ERR("Can't submit URB");
break;
case BCM203X_CHECK_MEMORY:
if (data->buffer[0] != '#') {
BT_ERR("Memory select failed");
data->state = BCM203X_ERROR;
break;
}
data->state = BCM203X_LOAD_FIRMWARE;
case BCM203X_LOAD_FIRMWARE:
if (data->fw_sent == data->fw_size) {
usb_fill_int_urb(urb, udev, usb_rcvintpipe(udev, BCM203X_IN_EP),
data->buffer, 32, bcm203x_complete, data, 1);
data->state = BCM203X_CHECK_FIRMWARE;
} else {
len = min_t(uint, data->fw_size - data->fw_sent, 4096);
usb_fill_bulk_urb(urb, udev, usb_sndbulkpipe(udev, BCM203X_OUT_EP),
data->fw_data + data->fw_sent, len, bcm203x_complete, data);
data->fw_sent += len;
}
if (usb_submit_urb(data->urb, GFP_ATOMIC) < 0)
BT_ERR("Can't submit URB");
break;
case BCM203X_CHECK_FIRMWARE:
if (data->buffer[0] != '.') {
BT_ERR("Firmware loading failed");
data->state = BCM203X_ERROR;
break;
}
data->state = BCM203X_RESET;
break;
}
}
static void bcm203x_work(struct work_struct *work)
{
struct bcm203x_data *data =
container_of(work, struct bcm203x_data, work);
if (atomic_read(&data->shutdown))
return;
if (usb_submit_urb(data->urb, GFP_KERNEL) < 0)
BT_ERR("Can't submit URB");
}
static int bcm203x_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
const struct firmware *firmware;
struct usb_device *udev = interface_to_usbdev(intf);
struct bcm203x_data *data;
int size;
BT_DBG("intf %p id %p", intf, id);
if (intf->cur_altsetting->desc.bInterfaceNumber != 0)
return -ENODEV;
data = devm_kzalloc(&intf->dev, sizeof(*data), GFP_KERNEL);
if (!data) {
BT_ERR("Can't allocate memory for data structure");
return -ENOMEM;
}
data->udev = udev;
data->state = BCM203X_LOAD_MINIDRV;
data->urb = usb_alloc_urb(0, GFP_KERNEL);
if (!data->urb) {
BT_ERR("Can't allocate URB");
return -ENOMEM;
}
if (request_firmware(&firmware, "BCM2033-MD.hex", &udev->dev) < 0) {
BT_ERR("Mini driver request failed");
usb_free_urb(data->urb);
return -EIO;
}
BT_DBG("minidrv data %p size %zu", firmware->data, firmware->size);
size = max_t(uint, firmware->size, 4096);
data->buffer = kmalloc(size, GFP_KERNEL);
if (!data->buffer) {
BT_ERR("Can't allocate memory for mini driver");
release_firmware(firmware);
usb_free_urb(data->urb);
return -ENOMEM;
}
memcpy(data->buffer, firmware->data, firmware->size);
usb_fill_bulk_urb(data->urb, udev, usb_sndbulkpipe(udev, BCM203X_OUT_EP),
data->buffer, firmware->size, bcm203x_complete, data);
release_firmware(firmware);
if (request_firmware(&firmware, "BCM2033-FW.bin", &udev->dev) < 0) {
BT_ERR("Firmware request failed");
usb_free_urb(data->urb);
kfree(data->buffer);
return -EIO;
}
BT_DBG("firmware data %p size %zu", firmware->data, firmware->size);
data->fw_data = kmemdup(firmware->data, firmware->size, GFP_KERNEL);
if (!data->fw_data) {
BT_ERR("Can't allocate memory for firmware image");
release_firmware(firmware);
usb_free_urb(data->urb);
kfree(data->buffer);
return -ENOMEM;
}
data->fw_size = firmware->size;
data->fw_sent = 0;
release_firmware(firmware);
INIT_WORK(&data->work, bcm203x_work);
usb_set_intfdata(intf, data);
schedule_work(&data->work);
return 0;
}
static void bcm203x_disconnect(struct usb_interface *intf)
{
struct bcm203x_data *data = usb_get_intfdata(intf);
BT_DBG("intf %p", intf);
atomic_inc(&data->shutdown);
cancel_work_sync(&data->work);
usb_kill_urb(data->urb);
usb_set_intfdata(intf, NULL);
usb_free_urb(data->urb);
kfree(data->fw_data);
kfree(data->buffer);
}
