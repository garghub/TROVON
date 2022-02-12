static bool is_blacklisted(const u8 ifnum, enum option_blacklist_reason reason,
const struct option_blacklist_info *blacklist)
{
unsigned long num;
const unsigned long *intf_list;
if (blacklist) {
if (reason == OPTION_BLACKLIST_SENDSETUP)
intf_list = &blacklist->sendsetup;
else if (reason == OPTION_BLACKLIST_RESERVED_IF)
intf_list = &blacklist->reserved;
else {
BUG_ON(reason);
return false;
}
for_each_set_bit(num, intf_list, MAX_BL_NUM + 1) {
if (num == ifnum)
return true;
}
}
return false;
}
static int option_probe(struct usb_serial *serial,
const struct usb_device_id *id)
{
struct usb_wwan_intf_private *data;
struct option_private *priv;
struct usb_interface_descriptor *iface_desc =
&serial->interface->cur_altsetting->desc;
struct usb_device_descriptor *dev_desc = &serial->dev->descriptor;
if (dev_desc->idVendor == DLINK_VENDOR_ID &&
dev_desc->idProduct == DLINK_PRODUCT_DWM_652 &&
iface_desc->bInterfaceClass == 0x08)
return -ENODEV;
if ((dev_desc->idVendor == BANDRICH_VENDOR_ID ||
dev_desc->idVendor == PIRELLI_VENDOR_ID) &&
iface_desc->bInterfaceClass != 0xff)
return -ENODEV;
if (is_blacklisted(
iface_desc->bInterfaceNumber,
OPTION_BLACKLIST_RESERVED_IF,
(const struct option_blacklist_info *) id->driver_info))
return -ENODEV;
if (dev_desc->idVendor == SAMSUNG_VENDOR_ID &&
dev_desc->idProduct == SAMSUNG_PRODUCT_GT_B3730 &&
iface_desc->bInterfaceClass != USB_CLASS_CDC_DATA)
return -ENODEV;
data = kzalloc(sizeof(struct usb_wwan_intf_private), GFP_KERNEL);
if (!data)
return -ENOMEM;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
kfree(data);
return -ENOMEM;
}
priv->bInterfaceNumber = iface_desc->bInterfaceNumber;
data->private = priv;
if (!is_blacklisted(iface_desc->bInterfaceNumber,
OPTION_BLACKLIST_SENDSETUP,
(struct option_blacklist_info *)id->driver_info)) {
data->send_setup = option_send_setup;
}
spin_lock_init(&data->susp_lock);
usb_set_serial_data(serial, data);
return 0;
}
static void option_release(struct usb_serial *serial)
{
struct usb_wwan_intf_private *intfdata = usb_get_serial_data(serial);
struct option_private *priv = intfdata->private;
kfree(priv);
kfree(intfdata);
}
static void option_instat_callback(struct urb *urb)
{
int err;
int status = urb->status;
struct usb_serial_port *port = urb->context;
struct usb_wwan_port_private *portdata =
usb_get_serial_port_data(port);
dbg("%s: urb %p port %p has data %p", __func__, urb, port, portdata);
if (status == 0) {
struct usb_ctrlrequest *req_pkt =
(struct usb_ctrlrequest *)urb->transfer_buffer;
if (!req_pkt) {
dbg("%s: NULL req_pkt", __func__);
return;
}
if ((req_pkt->bRequestType == 0xA1) &&
(req_pkt->bRequest == 0x20)) {
int old_dcd_state;
unsigned char signals = *((unsigned char *)
urb->transfer_buffer +
sizeof(struct usb_ctrlrequest));
dbg("%s: signal x%x", __func__, signals);
old_dcd_state = portdata->dcd_state;
portdata->cts_state = 1;
portdata->dcd_state = ((signals & 0x01) ? 1 : 0);
portdata->dsr_state = ((signals & 0x02) ? 1 : 0);
portdata->ri_state = ((signals & 0x08) ? 1 : 0);
if (old_dcd_state && !portdata->dcd_state) {
struct tty_struct *tty =
tty_port_tty_get(&port->port);
if (tty && !C_CLOCAL(tty))
tty_hangup(tty);
tty_kref_put(tty);
}
} else {
dbg("%s: type %x req %x", __func__,
req_pkt->bRequestType, req_pkt->bRequest);
}
} else
dev_err(&port->dev, "%s: error %d\n", __func__, status);
if (status != -ESHUTDOWN && status != -ENOENT) {
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err)
dbg("%s: resubmit intr urb failed. (%d)",
__func__, err);
}
}
static int option_send_setup(struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
struct usb_wwan_intf_private *intfdata = usb_get_serial_data(serial);
struct option_private *priv = intfdata->private;
struct usb_wwan_port_private *portdata;
int val = 0;
portdata = usb_get_serial_port_data(port);
if (portdata->dtr_state)
val |= 0x01;
if (portdata->rts_state)
val |= 0x02;
return usb_control_msg(serial->dev, usb_rcvctrlpipe(serial->dev, 0),
0x22, 0x21, val, priv->bInterfaceNumber, NULL,
0, USB_CTRL_SET_TIMEOUT);
}
