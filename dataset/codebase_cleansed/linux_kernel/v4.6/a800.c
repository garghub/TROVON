static int a800_power_ctrl(struct dvb_usb_device *d, int onoff)
{
return 0;
}
static int a800_identify_state(struct usb_device *udev, struct dvb_usb_device_properties *props,
struct dvb_usb_device_description **desc, int *cold)
{
*cold = udev->descriptor.iManufacturer != 1;
return 0;
}
static int a800_rc_query(struct dvb_usb_device *d, u32 *event, int *state)
{
int ret;
u8 *key = kmalloc(5, GFP_KERNEL);
if (!key)
return -ENOMEM;
if (usb_control_msg(d->udev,usb_rcvctrlpipe(d->udev,0),
0x04, USB_TYPE_VENDOR | USB_DIR_IN, 0, 0, key, 5,
2000) != 5) {
ret = -ENODEV;
goto out;
}
dvb_usb_nec_rc_key_to_event(d,key,event,state);
if (key[0] != 0)
deb_rc("key: %*ph\n", 5, key);
ret = 0;
out:
kfree(key);
return ret;
}
static int a800_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return dvb_usb_device_init(intf, &a800_properties,
THIS_MODULE, NULL, adapter_nr);
}
