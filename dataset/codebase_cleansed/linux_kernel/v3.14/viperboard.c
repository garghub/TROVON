static int vprbrd_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct vprbrd *vb;
u16 version = 0;
int pipe, ret;
vb = kzalloc(sizeof(*vb), GFP_KERNEL);
if (vb == NULL) {
dev_err(&interface->dev, "Out of memory\n");
return -ENOMEM;
}
mutex_init(&vb->lock);
vb->usb_dev = usb_get_dev(interface_to_usbdev(interface));
usb_set_intfdata(interface, vb);
dev_set_drvdata(&vb->pdev.dev, vb);
pipe = usb_rcvctrlpipe(vb->usb_dev, 0);
ret = usb_control_msg(vb->usb_dev, pipe, VPRBRD_USB_REQUEST_MAJOR,
VPRBRD_USB_TYPE_IN, 0x0000, 0x0000, vb->buf, 1,
VPRBRD_USB_TIMEOUT_MS);
if (ret == 1)
version = vb->buf[0];
ret = usb_control_msg(vb->usb_dev, pipe, VPRBRD_USB_REQUEST_MINOR,
VPRBRD_USB_TYPE_IN, 0x0000, 0x0000, vb->buf, 1,
VPRBRD_USB_TIMEOUT_MS);
if (ret == 1) {
version <<= 8;
version = version | vb->buf[0];
}
dev_info(&interface->dev,
"version %x.%02x found at bus %03d address %03d\n",
version >> 8, version & 0xff,
vb->usb_dev->bus->busnum, vb->usb_dev->devnum);
ret = mfd_add_devices(&interface->dev, -1, vprbrd_devs,
ARRAY_SIZE(vprbrd_devs), NULL, 0, NULL);
if (ret != 0) {
dev_err(&interface->dev, "Failed to add mfd devices to core.");
goto error;
}
return 0;
error:
if (vb) {
usb_put_dev(vb->usb_dev);
kfree(vb);
}
return ret;
}
static void vprbrd_disconnect(struct usb_interface *interface)
{
struct vprbrd *vb = usb_get_intfdata(interface);
mfd_remove_devices(&interface->dev);
usb_set_intfdata(interface, NULL);
usb_put_dev(vb->usb_dev);
kfree(vb);
dev_dbg(&interface->dev, "disconnected\n");
}
