static int option_probe(struct usb_serial *serial,
const struct usb_device_id *id)
{
struct usb_interface_descriptor *iface_desc =
&serial->interface->cur_altsetting->desc;
struct usb_device_descriptor *dev_desc = &serial->dev->descriptor;
const struct option_blacklist_info *blacklist;
if (iface_desc->bInterfaceClass == 0x08)
return -ENODEV;
blacklist = (void *)id->driver_info;
if (blacklist && test_bit(iface_desc->bInterfaceNumber,
&blacklist->reserved))
return -ENODEV;
if (dev_desc->idVendor == cpu_to_le16(SAMSUNG_VENDOR_ID) &&
dev_desc->idProduct == cpu_to_le16(SAMSUNG_PRODUCT_GT_B3730) &&
iface_desc->bInterfaceClass != USB_CLASS_CDC_DATA)
return -ENODEV;
usb_set_serial_data(serial, (void *)blacklist);
return 0;
}
static int option_attach(struct usb_serial *serial)
{
struct usb_interface_descriptor *iface_desc;
const struct option_blacklist_info *blacklist;
struct usb_wwan_intf_private *data;
data = kzalloc(sizeof(struct usb_wwan_intf_private), GFP_KERNEL);
if (!data)
return -ENOMEM;
blacklist = usb_get_serial_data(serial);
iface_desc = &serial->interface->cur_altsetting->desc;
if (!blacklist || !test_bit(iface_desc->bInterfaceNumber,
&blacklist->sendsetup)) {
data->use_send_setup = 1;
}
spin_lock_init(&data->susp_lock);
usb_set_serial_data(serial, data);
return 0;
}
static void option_release(struct usb_serial *serial)
{
struct usb_wwan_intf_private *intfdata = usb_get_serial_data(serial);
kfree(intfdata);
}
static void option_instat_callback(struct urb *urb)
{
int err;
int status = urb->status;
struct usb_serial_port *port = urb->context;
struct device *dev = &port->dev;
struct usb_wwan_port_private *portdata =
usb_get_serial_port_data(port);
dev_dbg(dev, "%s: urb %p port %p has data %p\n", __func__, urb, port, portdata);
if (status == 0) {
struct usb_ctrlrequest *req_pkt =
(struct usb_ctrlrequest *)urb->transfer_buffer;
if (!req_pkt) {
dev_dbg(dev, "%s: NULL req_pkt\n", __func__);
return;
}
if ((req_pkt->bRequestType == 0xA1) &&
(req_pkt->bRequest == 0x20)) {
int old_dcd_state;
unsigned char signals = *((unsigned char *)
urb->transfer_buffer +
sizeof(struct usb_ctrlrequest));
dev_dbg(dev, "%s: signal x%x\n", __func__, signals);
old_dcd_state = portdata->dcd_state;
portdata->cts_state = 1;
portdata->dcd_state = ((signals & 0x01) ? 1 : 0);
portdata->dsr_state = ((signals & 0x02) ? 1 : 0);
portdata->ri_state = ((signals & 0x08) ? 1 : 0);
if (old_dcd_state && !portdata->dcd_state)
tty_port_tty_hangup(&port->port, true);
} else {
dev_dbg(dev, "%s: type %x req %x\n", __func__,
req_pkt->bRequestType, req_pkt->bRequest);
}
} else if (status == -ENOENT || status == -ESHUTDOWN) {
dev_dbg(dev, "%s: urb stopped: %d\n", __func__, status);
} else
dev_dbg(dev, "%s: error %d\n", __func__, status);
if (status != -ESHUTDOWN && status != -ENOENT) {
usb_mark_last_busy(port->serial->dev);
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err)
dev_dbg(dev, "%s: resubmit intr urb failed. (%d)\n",
__func__, err);
}
}
