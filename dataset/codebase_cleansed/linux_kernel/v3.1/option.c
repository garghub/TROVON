static int __init option_init(void)
{
int retval;
retval = usb_serial_register(&option_1port_device);
if (retval)
goto failed_1port_device_register;
retval = usb_register(&option_driver);
if (retval)
goto failed_driver_register;
printk(KERN_INFO KBUILD_MODNAME ": " DRIVER_VERSION ":"
DRIVER_DESC "\n");
return 0;
failed_driver_register:
usb_serial_deregister(&option_1port_device);
failed_1port_device_register:
return retval;
}
static void __exit option_exit(void)
{
usb_deregister(&option_driver);
usb_serial_deregister(&option_1port_device);
}
static int option_probe(struct usb_serial *serial,
const struct usb_device_id *id)
{
struct usb_wwan_intf_private *data;
if (serial->dev->descriptor.idVendor == DLINK_VENDOR_ID &&
serial->dev->descriptor.idProduct == DLINK_PRODUCT_DWM_652 &&
serial->interface->cur_altsetting->desc.bInterfaceClass == 0x8)
return -ENODEV;
if ((serial->dev->descriptor.idVendor == BANDRICH_VENDOR_ID ||
serial->dev->descriptor.idVendor == PIRELLI_VENDOR_ID) &&
serial->interface->cur_altsetting->desc.bInterfaceClass != 0xff)
return -ENODEV;
if (serial->dev->descriptor.idVendor == HUAWEI_VENDOR_ID &&
(serial->dev->descriptor.idProduct == HUAWEI_PRODUCT_K3765 ||
serial->dev->descriptor.idProduct == HUAWEI_PRODUCT_K4505 ||
serial->dev->descriptor.idProduct == HUAWEI_PRODUCT_K4605) &&
(serial->interface->cur_altsetting->desc.bInterfaceNumber == 1 ||
serial->interface->cur_altsetting->desc.bInterfaceNumber == 2))
return -ENODEV;
if (serial->dev->descriptor.idVendor == SAMSUNG_VENDOR_ID &&
serial->dev->descriptor.idProduct == SAMSUNG_PRODUCT_GT_B3730 &&
serial->interface->cur_altsetting->desc.bInterfaceClass != USB_CLASS_CDC_DATA)
return -ENODEV;
data = serial->private = kzalloc(sizeof(struct usb_wwan_intf_private), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->send_setup = option_send_setup;
spin_lock_init(&data->susp_lock);
data->private = (void *)id->driver_info;
return 0;
}
static enum option_blacklist_reason is_blacklisted(const u8 ifnum,
const struct option_blacklist_info *blacklist)
{
const u8 *info;
int i;
if (blacklist) {
info = blacklist->ifaceinfo;
for (i = 0; i < blacklist->infolen; i++) {
if (info[i] == ifnum)
return blacklist->reason;
}
}
return OPTION_BLACKLIST_NONE;
}
static void option_instat_callback(struct urb *urb)
{
int err;
int status = urb->status;
struct usb_serial_port *port = urb->context;
struct option_port_private *portdata = usb_get_serial_port_data(port);
dbg("%s", __func__);
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
err("%s: error %d", __func__, status);
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
struct usb_wwan_intf_private *intfdata =
(struct usb_wwan_intf_private *) serial->private;
struct option_port_private *portdata;
int ifNum = serial->interface->cur_altsetting->desc.bInterfaceNumber;
int val = 0;
dbg("%s", __func__);
if (is_blacklisted(ifNum,
(struct option_blacklist_info *) intfdata->private)
== OPTION_BLACKLIST_SENDSETUP) {
dbg("No send_setup on blacklisted interface #%d\n", ifNum);
return -EIO;
}
portdata = usb_get_serial_port_data(port);
if (portdata->dtr_state)
val |= 0x01;
if (portdata->rts_state)
val |= 0x02;
return usb_control_msg(serial->dev,
usb_rcvctrlpipe(serial->dev, 0),
0x22, 0x21, val, ifNum, NULL, 0, USB_CTRL_SET_TIMEOUT);
}
