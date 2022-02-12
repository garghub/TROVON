static int ehset_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
int ret = -EINVAL;
struct usb_device *dev = interface_to_usbdev(intf);
struct usb_device *hub_udev = dev->parent;
struct usb_device_descriptor *buf;
u8 portnum = dev->portnum;
u16 test_pid = le16_to_cpu(dev->descriptor.idProduct);
switch (test_pid) {
case TEST_SE0_NAK_PID:
ret = usb_control_msg(hub_udev, usb_sndctrlpipe(hub_udev, 0),
USB_REQ_SET_FEATURE, USB_RT_PORT,
USB_PORT_FEAT_TEST,
(TEST_SE0_NAK << 8) | portnum,
NULL, 0, 1000);
break;
case TEST_J_PID:
ret = usb_control_msg(hub_udev, usb_sndctrlpipe(hub_udev, 0),
USB_REQ_SET_FEATURE, USB_RT_PORT,
USB_PORT_FEAT_TEST,
(TEST_J << 8) | portnum,
NULL, 0, 1000);
break;
case TEST_K_PID:
ret = usb_control_msg(hub_udev, usb_sndctrlpipe(hub_udev, 0),
USB_REQ_SET_FEATURE, USB_RT_PORT,
USB_PORT_FEAT_TEST,
(TEST_K << 8) | portnum,
NULL, 0, 1000);
break;
case TEST_PACKET_PID:
ret = usb_control_msg(hub_udev, usb_sndctrlpipe(hub_udev, 0),
USB_REQ_SET_FEATURE, USB_RT_PORT,
USB_PORT_FEAT_TEST,
(TEST_PACKET << 8) | portnum,
NULL, 0, 1000);
break;
case TEST_HS_HOST_PORT_SUSPEND_RESUME:
msleep(15 * 1000);
ret = usb_control_msg(hub_udev, usb_sndctrlpipe(hub_udev, 0),
USB_REQ_SET_FEATURE, USB_RT_PORT,
USB_PORT_FEAT_SUSPEND, portnum,
NULL, 0, 1000);
if (ret < 0)
break;
msleep(15 * 1000);
ret = usb_control_msg(hub_udev, usb_sndctrlpipe(hub_udev, 0),
USB_REQ_CLEAR_FEATURE, USB_RT_PORT,
USB_PORT_FEAT_SUSPEND, portnum,
NULL, 0, 1000);
break;
case TEST_SINGLE_STEP_GET_DEV_DESC:
msleep(15 * 1000);
buf = kmalloc(USB_DT_DEVICE_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
USB_REQ_GET_DESCRIPTOR, USB_DIR_IN,
USB_DT_DEVICE << 8, 0,
buf, USB_DT_DEVICE_SIZE,
USB_CTRL_GET_TIMEOUT);
kfree(buf);
break;
case TEST_SINGLE_STEP_SET_FEATURE:
if (hub_udev != dev->bus->root_hub) {
dev_err(&intf->dev, "SINGLE_STEP_SET_FEATURE test only supported on root hub\n");
break;
}
ret = usb_control_msg(hub_udev, usb_sndctrlpipe(hub_udev, 0),
USB_REQ_SET_FEATURE, USB_RT_PORT,
USB_PORT_FEAT_TEST,
(6 << 8) | portnum,
NULL, 0, 60 * 1000);
break;
default:
dev_err(&intf->dev, "%s: unsupported PID: 0x%x\n",
__func__, test_pid);
}
return (ret < 0) ? ret : 0;
}
static void ehset_disconnect(struct usb_interface *intf)
{
}
