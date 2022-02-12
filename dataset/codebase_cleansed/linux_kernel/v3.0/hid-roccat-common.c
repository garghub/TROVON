int roccat_common_receive(struct usb_device *usb_dev, uint usb_command,
void *data, uint size)
{
char *buf;
int len;
buf = kmalloc(size, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
len = usb_control_msg(usb_dev, usb_rcvctrlpipe(usb_dev, 0),
USB_REQ_CLEAR_FEATURE,
USB_TYPE_CLASS | USB_RECIP_INTERFACE | USB_DIR_IN,
usb_command, 0, buf, size, USB_CTRL_SET_TIMEOUT);
memcpy(data, buf, size);
kfree(buf);
return ((len < 0) ? len : ((len != size) ? -EIO : 0));
}
int roccat_common_send(struct usb_device *usb_dev, uint usb_command,
void const *data, uint size)
{
char *buf;
int len;
buf = kmalloc(size, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
memcpy(buf, data, size);
len = usb_control_msg(usb_dev, usb_sndctrlpipe(usb_dev, 0),
USB_REQ_SET_CONFIGURATION,
USB_TYPE_CLASS | USB_RECIP_INTERFACE | USB_DIR_OUT,
usb_command, 0, buf, size, USB_CTRL_SET_TIMEOUT);
kfree(buf);
return ((len < 0) ? len : ((len != size) ? -EIO : 0));
}
