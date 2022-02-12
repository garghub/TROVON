int usbtv_set_regs(struct usbtv *usbtv, const u16 regs[][2], int size)
{
int ret;
int pipe = usb_rcvctrlpipe(usbtv->udev, 0);
int i;
for (i = 0; i < size; i++) {
u16 index = regs[i][0];
u16 value = regs[i][1];
ret = usb_control_msg(usbtv->udev, pipe, USBTV_REQUEST_REG,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index, NULL, 0, 0);
if (ret < 0)
return ret;
}
return 0;
}
static int usbtv_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
int ret;
int size;
struct device *dev = &intf->dev;
struct usbtv *usbtv;
if (intf->num_altsetting != 2)
return -ENODEV;
if (intf->altsetting[1].desc.bNumEndpoints != 4)
return -ENODEV;
size = usb_endpoint_maxp(&intf->altsetting[1].endpoint[0].desc);
size = (size & 0x07ff) * (((size & 0x1800) >> 11) + 1);
usbtv = kzalloc(sizeof(struct usbtv), GFP_KERNEL);
if (usbtv == NULL)
return -ENOMEM;
usbtv->dev = dev;
usbtv->udev = usb_get_dev(interface_to_usbdev(intf));
usbtv->iso_size = size;
usb_set_intfdata(intf, usbtv);
ret = usbtv_video_init(usbtv);
if (ret < 0)
goto usbtv_video_fail;
v4l2_device_get(&usbtv->v4l2_dev);
dev_info(dev, "Fushicai USBTV007 Video Grabber\n");
return 0;
usbtv_video_fail:
kfree(usbtv);
return ret;
}
static void usbtv_disconnect(struct usb_interface *intf)
{
struct usbtv *usbtv = usb_get_intfdata(intf);
usb_set_intfdata(intf, NULL);
if (!usbtv)
return;
usbtv_video_free(usbtv);
usb_put_dev(usbtv->udev);
usbtv->udev = NULL;
v4l2_device_put(&usbtv->v4l2_dev);
}
