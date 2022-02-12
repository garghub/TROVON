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
pr_err("%s() Failed sending control message, error %d.\n",
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
pr_err("%s() Failed receiving control message, error %d.\n",
__func__, status);
}
memcpy(cp, dev->ctrlmsg, size);
}
mutex_unlock(&dev->mutex);
return status;
}
static void au0828_usb_release(struct au0828_dev *dev)
{
au0828_i2c_unregister(dev);
kfree(dev);
}
static void au0828_usb_v4l2_release(struct v4l2_device *v4l2_dev)
{
struct au0828_dev *dev =
container_of(v4l2_dev, struct au0828_dev, v4l2_dev);
v4l2_ctrl_handler_free(&dev->v4l2_ctrl_hdl);
v4l2_device_unregister(&dev->v4l2_dev);
au0828_usb_release(dev);
}
static void au0828_usb_disconnect(struct usb_interface *interface)
{
struct au0828_dev *dev = usb_get_intfdata(interface);
dprintk(1, "%s()\n", __func__);
dev->dev_state = DEV_DISCONNECTED;
au0828_rc_unregister(dev);
au0828_dvb_unregister(dev);
usb_set_intfdata(interface, NULL);
mutex_lock(&dev->mutex);
dev->usbdev = NULL;
mutex_unlock(&dev->mutex);
#ifdef CONFIG_VIDEO_AU0828_V4L2
if (AUVI_INPUT(0).type != AU0828_VMUX_UNDEFINED) {
au0828_analog_unregister(dev);
v4l2_device_disconnect(&dev->v4l2_dev);
v4l2_device_put(&dev->v4l2_dev);
return;
}
#endif
au0828_usb_release(dev);
}
static int au0828_usb_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
int ifnum;
int retval = 0;
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
pr_err("au0828: Device initialization failed.\n");
pr_err("au0828: Device must be connected to a high-speed USB 2.0 port.\n");
return -ENODEV;
}
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (dev == NULL) {
pr_err("%s() Unable to allocate memory\n", __func__);
return -ENOMEM;
}
mutex_init(&dev->lock);
mutex_lock(&dev->lock);
mutex_init(&dev->mutex);
mutex_init(&dev->dvb.lock);
dev->usbdev = usbdev;
dev->boardnr = id->driver_info;
dev->board = au0828_boards[dev->boardnr];
#ifdef CONFIG_VIDEO_AU0828_V4L2
dev->v4l2_dev.release = au0828_usb_v4l2_release;
retval = v4l2_device_register(&interface->dev, &dev->v4l2_dev);
if (retval) {
pr_err("%s() v4l2_device_register failed\n",
__func__);
mutex_unlock(&dev->lock);
kfree(dev);
return retval;
}
retval = v4l2_ctrl_handler_init(&dev->v4l2_ctrl_hdl, 4);
if (retval) {
pr_err("%s() v4l2_ctrl_handler_init failed\n",
__func__);
mutex_unlock(&dev->lock);
kfree(dev);
return retval;
}
dev->v4l2_dev.ctrl_handler = &dev->v4l2_ctrl_hdl;
#endif
au0828_write(dev, REG_600, 1 << 4);
au0828_gpio_setup(dev);
au0828_i2c_register(dev);
au0828_card_setup(dev);
#ifdef CONFIG_VIDEO_AU0828_V4L2
if (AUVI_INPUT(0).type != AU0828_VMUX_UNDEFINED)
au0828_analog_register(dev, interface);
#endif
retval = au0828_dvb_register(dev);
if (retval)
pr_err("%s() au0282_dev_register failed\n",
__func__);
au0828_rc_register(dev);
usb_set_intfdata(interface, dev);
pr_info("Registered device AU0828 [%s]\n",
dev->board.name == NULL ? "Unset" : dev->board.name);
mutex_unlock(&dev->lock);
return retval;
}
static int au0828_suspend(struct usb_interface *interface,
pm_message_t message)
{
struct au0828_dev *dev = usb_get_intfdata(interface);
if (!dev)
return 0;
pr_info("Suspend\n");
au0828_rc_suspend(dev);
au0828_v4l2_suspend(dev);
au0828_dvb_suspend(dev);
return 0;
}
static int au0828_resume(struct usb_interface *interface)
{
struct au0828_dev *dev = usb_get_intfdata(interface);
if (!dev)
return 0;
pr_info("Resume\n");
au0828_write(dev, REG_600, 1 << 4);
au0828_gpio_setup(dev);
au0828_rc_resume(dev);
au0828_v4l2_resume(dev);
au0828_dvb_resume(dev);
return 0;
}
static int __init au0828_init(void)
{
int ret;
if (au0828_debug & 1)
pr_info("%s() Debugging is enabled\n", __func__);
if (au0828_debug & 2)
pr_info("%s() USB Debugging is enabled\n", __func__);
if (au0828_debug & 4)
pr_info("%s() I2C Debugging is enabled\n", __func__);
if (au0828_debug & 8)
pr_info("%s() Bridge Debugging is enabled\n",
__func__);
if (au0828_debug & 16)
pr_info("%s() IR Debugging is enabled\n",
__func__);
pr_info("au0828 driver loaded\n");
ret = usb_register(&au0828_usb_driver);
if (ret)
pr_err("usb_register failed, error = %d\n", ret);
return ret;
}
static void __exit au0828_exit(void)
{
usb_deregister(&au0828_usb_driver);
}
