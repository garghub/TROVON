int usb_usual_ignore_device(struct usb_interface *intf)
{
struct usb_device *udev;
unsigned vid, pid, bcd;
struct ignore_entry *p;
udev = interface_to_usbdev(intf);
vid = le16_to_cpu(udev->descriptor.idVendor);
pid = le16_to_cpu(udev->descriptor.idProduct);
bcd = le16_to_cpu(udev->descriptor.bcdDevice);
for (p = ignore_ids; p->vid; ++p) {
if (p->vid == vid && p->pid == pid &&
p->bcdmin <= bcd && p->bcdmax >= bcd)
return -ENXIO;
}
return 0;
}
