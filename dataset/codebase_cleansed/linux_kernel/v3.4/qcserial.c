static int qcprobe(struct usb_serial *serial, const struct usb_device_id *id)
{
struct usb_wwan_intf_private *data;
struct usb_host_interface *intf = serial->interface->cur_altsetting;
int retval = -ENODEV;
__u8 nintf;
__u8 ifnum;
bool is_gobi1k = id->driver_info ? true : false;
dbg("%s", __func__);
dbg("Is Gobi 1000 = %d", is_gobi1k);
nintf = serial->dev->actconfig->desc.bNumInterfaces;
dbg("Num Interfaces = %d", nintf);
ifnum = intf->desc.bInterfaceNumber;
dbg("This Interface = %d", ifnum);
data = kzalloc(sizeof(struct usb_wwan_intf_private),
GFP_KERNEL);
if (!data)
return -ENOMEM;
spin_lock_init(&data->susp_lock);
switch (nintf) {
case 1:
if (serial->interface->num_altsetting == 2)
intf = &serial->interface->altsetting[1];
else if (serial->interface->num_altsetting > 2)
break;
if (intf->desc.bNumEndpoints == 2 &&
usb_endpoint_is_bulk_in(&intf->endpoint[0].desc) &&
usb_endpoint_is_bulk_out(&intf->endpoint[1].desc)) {
dbg("QDL port found");
if (serial->interface->num_altsetting == 1) {
retval = 0;
break;
}
retval = usb_set_interface(serial->dev, ifnum, 1);
if (retval < 0) {
dev_err(&serial->dev->dev,
"Could not set interface, error %d\n",
retval);
retval = -ENODEV;
kfree(data);
}
}
break;
case 3:
case 4:
if (ifnum == 1 && !is_gobi1k) {
dbg("Gobi 2K+ DM/DIAG interface found");
retval = usb_set_interface(serial->dev, ifnum, 0);
if (retval < 0) {
dev_err(&serial->dev->dev,
"Could not set interface, error %d\n",
retval);
retval = -ENODEV;
kfree(data);
}
} else if (ifnum == 2) {
dbg("Modem port found");
retval = usb_set_interface(serial->dev, ifnum, 0);
if (retval < 0) {
dev_err(&serial->dev->dev,
"Could not set interface, error %d\n",
retval);
retval = -ENODEV;
kfree(data);
}
} else if (ifnum==3 && !is_gobi1k) {
dbg("Gobi 2K+ NMEA GPS interface found");
retval = usb_set_interface(serial->dev, ifnum, 0);
if (retval < 0) {
dev_err(&serial->dev->dev,
"Could not set interface, error %d\n",
retval);
retval = -ENODEV;
kfree(data);
}
}
break;
default:
dev_err(&serial->dev->dev,
"unknown number of interfaces: %d\n", nintf);
kfree(data);
retval = -ENODEV;
}
if (retval != -ENODEV)
usb_set_serial_data(serial, data);
return retval;
}
static void qc_release(struct usb_serial *serial)
{
struct usb_wwan_intf_private *priv = usb_get_serial_data(serial);
dbg("%s", __func__);
usb_wwan_release(serial);
usb_set_serial_data(serial, NULL);
kfree(priv);
}
