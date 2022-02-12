u32 au0828_readreg(struct au0828_dev *dev, u16 reg)
{
u8 result = 0;
recv_control_msg(dev, CMD_REQUEST_IN, 0, reg, &result, 1);
dprintk(8, "%s(0x%04x) = 0x%02x\n", __func__, reg, result);
return result;
}
u32 au0828_writereg(struct au0828_dev *dev, u16 reg, u32 val)
{
dprintk(8, "%s(0x%04x, 0x%02x)\n", __func__, reg, val);
return send_control_msg(dev, CMD_REQUEST_OUT, val, reg);
}
static int send_control_msg(struct au0828_dev *dev, u16 request, u32 value,
u16 index)
{
int status = -ENODEV;
if (dev->usbdev) {
status = usb_control_msg(dev->usbdev,
usb_sndctrlpipe(dev->usbdev, 0),
request,
USB_DIR_OUT | USB_TYPE_VENDOR |
USB_RECIP_DEVICE,
value, index, NULL, 0, 1000);
status = min(status, 0);
if (status < 0) {
printk(KERN_ERR "%s() Failed sending control message, error %d.\n",
__func__, status);
}
}
return status;
}
static int recv_control_msg(struct au0828_dev *dev, u16 request, u32 value,
u16 index, unsigned char *cp, u16 size)
{
int status = -ENODEV;
mutex_lock(&dev->mutex);
if (dev->usbdev) {
status = usb_control_msg(dev->usbdev,
usb_rcvctrlpipe(dev->usbdev, 0),
request,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index,
dev->ctrlmsg, size, 1000);
status = min(status, 0);
if (status < 0) {
printk(KERN_ERR "%s() Failed receiving control message, error %d.\n",
__func__, status);
}
memcpy(cp, dev->ctrlmsg, size);
}
mutex_unlock(&dev->mutex);
return status;
}
static void au0828_usb_disconnect(struct usb_interface *interface)
{
struct au0828_dev *dev = usb_get_intfdata(interface);
dprintk(1, "%s()\n", __func__);
au0828_dvb_unregister(dev);
#ifdef CONFIG_VIDEO_AU0828_V4L2
if (AUVI_INPUT(0).type != AU0828_VMUX_UNDEFINED)
au0828_analog_unregister(dev);
#endif
au0828_i2c_unregister(dev);
#ifdef CONFIG_VIDEO_AU0828_V4L2
v4l2_device_unregister(&dev->v4l2_dev);
#endif
usb_set_intfdata(interface, NULL);
mutex_lock(&dev->mutex);
dev->usbdev = NULL;
mutex_unlock(&dev->mutex);
kfree(dev);
}
static int au0828_usb_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
int ifnum;
#ifdef CONFIG_VIDEO_AU0828_V4L2
int retval;
#endif
struct au0828_dev *dev;
struct usb_device *usbdev = interface_to_usbdev(interface);
ifnum = interface->altsetting->desc.bInterfaceNumber;
if (ifnum != 0)
return -ENODEV;
dprintk(1, "%s() vendor id 0x%x device id 0x%x ifnum:%d\n", __func__,
le16_to_cpu(usbdev->descriptor.idVendor),
le16_to_cpu(usbdev->descriptor.idProduct),
ifnum);
if (usbdev->speed != USB_SPEED_HIGH && disable_usb_speed_check == 0) {
printk(KERN_ERR "au0828: Device initialization failed.\n");
printk(KERN_ERR "au0828: Device must be connected to a "
"high-speed USB 2.0 port.\n");
return -ENODEV;
}
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (dev == NULL) {
printk(KERN_ERR "%s() Unable to allocate memory\n", __func__);
return -ENOMEM;
}
mutex_init(&dev->lock);
mutex_lock(&dev->lock);
mutex_init(&dev->mutex);
mutex_init(&dev->dvb.lock);
dev->usbdev = usbdev;
dev->boardnr = id->driver_info;
#ifdef CONFIG_VIDEO_AU0828_V4L2
retval = v4l2_device_register(&interface->dev, &dev->v4l2_dev);
if (retval) {
printk(KERN_ERR "%s() v4l2_device_register failed\n",
__func__);
mutex_unlock(&dev->lock);
kfree(dev);
return -EIO;
}
#endif
au0828_write(dev, REG_600, 1 << 4);
au0828_gpio_setup(dev);
au0828_i2c_register(dev);
au0828_card_setup(dev);
#ifdef CONFIG_VIDEO_AU0828_V4L2
if (AUVI_INPUT(0).type != AU0828_VMUX_UNDEFINED)
au0828_analog_register(dev, interface);
#endif
au0828_dvb_register(dev);
usb_set_intfdata(interface, dev);
printk(KERN_INFO "Registered device AU0828 [%s]\n",
dev->board.name == NULL ? "Unset" : dev->board.name);
mutex_unlock(&dev->lock);
return 0;
}
static int __init au0828_init(void)
{
int ret;
if (au0828_debug & 1)
printk(KERN_INFO "%s() Debugging is enabled\n", __func__);
if (au0828_debug & 2)
printk(KERN_INFO "%s() USB Debugging is enabled\n", __func__);
if (au0828_debug & 4)
printk(KERN_INFO "%s() I2C Debugging is enabled\n", __func__);
if (au0828_debug & 8)
printk(KERN_INFO "%s() Bridge Debugging is enabled\n",
__func__);
printk(KERN_INFO "au0828 driver loaded\n");
ret = usb_register(&au0828_usb_driver);
if (ret)
printk(KERN_ERR "usb_register failed, error = %d\n", ret);
return ret;
}
static void __exit au0828_exit(void)
{
usb_deregister(&au0828_usb_driver);
}
