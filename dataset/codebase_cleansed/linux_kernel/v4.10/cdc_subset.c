static int always_connected (struct usbnet *dev)
{
return 0;
}
static void m5632_recover(struct usbnet *dev)
{
struct usb_device *udev = dev->udev;
struct usb_interface *intf = dev->intf;
int r;
r = usb_lock_device_for_reset(udev, intf);
if (r < 0)
return;
usb_reset_device(udev);
usb_unlock_device(udev);
}
static int dummy_prereset(struct usb_interface *intf)
{
return 0;
}
static int dummy_postreset(struct usb_interface *intf)
{
return 0;
}
