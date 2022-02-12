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
static void au0828_unregister_media_device(struct au0828_dev *dev)
{
#ifdef CONFIG_MEDIA_CONTROLLER
if (dev->media_dev) {
media_device_unregister(dev->media_dev);
media_device_cleanup(dev->media_dev);
kfree(dev->media_dev);
dev->media_dev = NULL;
}
#endif
}
static void au0828_usb_release(struct au0828_dev *dev)
{
au0828_unregister_media_device(dev);
au0828_i2c_unregister(dev);
kfree(dev);
}
static void au0828_usb_v4l2_media_release(struct au0828_dev *dev)
{
#ifdef CONFIG_MEDIA_CONTROLLER
int i;
for (i = 0; i < AU0828_MAX_INPUT; i++) {
if (AUVI_INPUT(i).type == AU0828_VMUX_UNDEFINED)
return;
media_device_unregister_entity(&dev->input_ent[i]);
}
#endif
}
static void au0828_usb_v4l2_release(struct v4l2_device *v4l2_dev)
{
struct au0828_dev *dev =
container_of(v4l2_dev, struct au0828_dev, v4l2_dev);
v4l2_ctrl_handler_free(&dev->v4l2_ctrl_hdl);
v4l2_device_unregister(&dev->v4l2_dev);
au0828_usb_v4l2_media_release(dev);
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
static int au0828_media_device_init(struct au0828_dev *dev,
struct usb_device *udev)
{
#ifdef CONFIG_MEDIA_CONTROLLER
struct media_device *mdev;
mdev = kzalloc(sizeof(*mdev), GFP_KERNEL);
if (!mdev)
return -ENOMEM;
mdev->dev = &udev->dev;
if (!dev->board.name)
strlcpy(mdev->model, "unknown au0828", sizeof(mdev->model));
else
strlcpy(mdev->model, dev->board.name, sizeof(mdev->model));
if (udev->serial)
strlcpy(mdev->serial, udev->serial, sizeof(mdev->serial));
strcpy(mdev->bus_info, udev->devpath);
mdev->hw_revision = le16_to_cpu(udev->descriptor.bcdDevice);
mdev->driver_version = LINUX_VERSION_CODE;
media_device_init(mdev);
dev->media_dev = mdev;
#endif
return 0;
}
static int au0828_create_media_graph(struct au0828_dev *dev)
{
#ifdef CONFIG_MEDIA_CONTROLLER
struct media_device *mdev = dev->media_dev;
struct media_entity *entity;
struct media_entity *tuner = NULL, *decoder = NULL;
int i, ret;
if (!mdev)
return 0;
media_device_for_each_entity(entity, mdev) {
switch (entity->function) {
case MEDIA_ENT_F_TUNER:
tuner = entity;
break;
case MEDIA_ENT_F_ATV_DECODER:
decoder = entity;
break;
}
}
if (!decoder)
return -EINVAL;
if (tuner) {
ret = media_create_pad_link(tuner, TUNER_PAD_IF_OUTPUT,
decoder, 0,
MEDIA_LNK_FL_ENABLED);
if (ret)
return ret;
}
ret = media_create_pad_link(decoder, 1, &dev->vdev.entity, 0,
MEDIA_LNK_FL_ENABLED);
if (ret)
return ret;
ret = media_create_pad_link(decoder, 2, &dev->vbi_dev.entity, 0,
MEDIA_LNK_FL_ENABLED);
if (ret)
return ret;
for (i = 0; i < AU0828_MAX_INPUT; i++) {
struct media_entity *ent = &dev->input_ent[i];
if (AUVI_INPUT(i).type == AU0828_VMUX_UNDEFINED)
break;
switch (AUVI_INPUT(i).type) {
case AU0828_VMUX_CABLE:
case AU0828_VMUX_TELEVISION:
case AU0828_VMUX_DVB:
if (!tuner)
break;
ret = media_create_pad_link(ent, 0, tuner,
TUNER_PAD_RF_INPUT,
MEDIA_LNK_FL_ENABLED);
if (ret)
return ret;
break;
case AU0828_VMUX_COMPOSITE:
case AU0828_VMUX_SVIDEO:
default:
ret = media_create_pad_link(ent, 0, decoder, 0, 0);
if (ret)
return ret;
break;
}
}
#endif
return 0;
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
retval = au0828_media_device_init(dev, usbdev);
if (retval) {
pr_err("%s() au0828_media_device_init failed\n",
__func__);
mutex_unlock(&dev->lock);
kfree(dev);
return retval;
}
#ifdef CONFIG_VIDEO_AU0828_V4L2
dev->v4l2_dev.release = au0828_usb_v4l2_release;
#ifdef CONFIG_MEDIA_CONTROLLER
dev->v4l2_dev.mdev = dev->media_dev;
#endif
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
retval = au0828_create_media_graph(dev);
if (retval) {
pr_err("%s() au0282_dev_register failed to create graph\n",
__func__);
goto done;
}
#ifdef CONFIG_MEDIA_CONTROLLER
retval = media_device_register(dev->media_dev);
#endif
done:
if (retval < 0)
au0828_usb_disconnect(interface);
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
