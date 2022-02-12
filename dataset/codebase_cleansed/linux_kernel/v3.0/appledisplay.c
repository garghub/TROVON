static void appledisplay_complete(struct urb *urb)
{
struct appledisplay *pdata = urb->context;
unsigned long flags;
int status = urb->status;
int retval;
switch (status) {
case 0:
break;
case -EOVERFLOW:
printk(KERN_ERR "appletouch: OVERFLOW with data "
"length %d, actual length is %d\n",
ACD_URB_BUFFER_LEN, pdata->urb->actual_length);
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dbg("%s - urb shuttingdown with status: %d",
__func__, status);
return;
default:
dbg("%s - nonzero urb status received: %d",
__func__, status);
goto exit;
}
spin_lock_irqsave(&pdata->lock, flags);
switch(pdata->urbdata[1]) {
case ACD_BTN_BRIGHT_UP:
case ACD_BTN_BRIGHT_DOWN:
pdata->button_pressed = 1;
queue_delayed_work(wq, &pdata->work, 0);
break;
case ACD_BTN_NONE:
default:
pdata->button_pressed = 0;
break;
}
spin_unlock_irqrestore(&pdata->lock, flags);
exit:
retval = usb_submit_urb(pdata->urb, GFP_ATOMIC);
if (retval) {
dev_err(&pdata->udev->dev,
"%s - usb_submit_urb failed with result %d\n",
__func__, retval);
}
}
static int appledisplay_bl_update_status(struct backlight_device *bd)
{
struct appledisplay *pdata = bl_get_data(bd);
int retval;
pdata->msgdata[0] = 0x10;
pdata->msgdata[1] = bd->props.brightness;
retval = usb_control_msg(
pdata->udev,
usb_sndctrlpipe(pdata->udev, 0),
USB_REQ_SET_REPORT,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
ACD_USB_BRIGHTNESS,
0,
pdata->msgdata, 2,
ACD_USB_TIMEOUT);
return retval;
}
static int appledisplay_bl_get_brightness(struct backlight_device *bd)
{
struct appledisplay *pdata = bl_get_data(bd);
int retval;
retval = usb_control_msg(
pdata->udev,
usb_rcvctrlpipe(pdata->udev, 0),
USB_REQ_GET_REPORT,
USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
ACD_USB_BRIGHTNESS,
0,
pdata->msgdata, 2,
ACD_USB_TIMEOUT);
if (retval < 0)
return retval;
else
return pdata->msgdata[1];
}
static void appledisplay_work(struct work_struct *work)
{
struct appledisplay *pdata =
container_of(work, struct appledisplay, work.work);
int retval;
retval = appledisplay_bl_get_brightness(pdata->bd);
if (retval >= 0)
pdata->bd->props.brightness = retval;
if (pdata->button_pressed)
schedule_delayed_work(&pdata->work, HZ / 8);
}
static int appledisplay_probe(struct usb_interface *iface,
const struct usb_device_id *id)
{
struct backlight_properties props;
struct appledisplay *pdata;
struct usb_device *udev = interface_to_usbdev(iface);
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *endpoint;
int int_in_endpointAddr = 0;
int i, retval = -ENOMEM, brightness;
char bl_name[20];
iface_desc = iface->cur_altsetting;
for (i = 0; i < iface_desc->desc.bNumEndpoints; i++) {
endpoint = &iface_desc->endpoint[i].desc;
if (!int_in_endpointAddr && usb_endpoint_is_int_in(endpoint)) {
int_in_endpointAddr = endpoint->bEndpointAddress;
break;
}
}
if (!int_in_endpointAddr) {
dev_err(&iface->dev, "Could not find int-in endpoint\n");
return -EIO;
}
pdata = kzalloc(sizeof(struct appledisplay), GFP_KERNEL);
if (!pdata) {
retval = -ENOMEM;
dev_err(&iface->dev, "Out of memory\n");
goto error;
}
pdata->udev = udev;
spin_lock_init(&pdata->lock);
INIT_DELAYED_WORK(&pdata->work, appledisplay_work);
pdata->msgdata = kmalloc(ACD_MSG_BUFFER_LEN, GFP_KERNEL);
if (!pdata->msgdata) {
retval = -ENOMEM;
dev_err(&iface->dev,
"Allocating buffer for control messages failed\n");
goto error;
}
pdata->urb = usb_alloc_urb(0, GFP_KERNEL);
if (!pdata->urb) {
retval = -ENOMEM;
dev_err(&iface->dev, "Allocating URB failed\n");
goto error;
}
pdata->urbdata = usb_alloc_coherent(pdata->udev, ACD_URB_BUFFER_LEN,
GFP_KERNEL, &pdata->urb->transfer_dma);
if (!pdata->urbdata) {
retval = -ENOMEM;
dev_err(&iface->dev, "Allocating URB buffer failed\n");
goto error;
}
usb_fill_int_urb(pdata->urb, udev,
usb_rcvintpipe(udev, int_in_endpointAddr),
pdata->urbdata, ACD_URB_BUFFER_LEN, appledisplay_complete,
pdata, 1);
if (usb_submit_urb(pdata->urb, GFP_KERNEL)) {
retval = -EIO;
dev_err(&iface->dev, "Submitting URB failed\n");
goto error;
}
snprintf(bl_name, sizeof(bl_name), "appledisplay%d",
atomic_inc_return(&count_displays) - 1);
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = 0xff;
pdata->bd = backlight_device_register(bl_name, NULL, pdata,
&appledisplay_bl_data, &props);
if (IS_ERR(pdata->bd)) {
dev_err(&iface->dev, "Backlight registration failed\n");
retval = PTR_ERR(pdata->bd);
goto error;
}
brightness = appledisplay_bl_get_brightness(pdata->bd);
if (brightness < 0) {
retval = brightness;
dev_err(&iface->dev,
"Error while getting initial brightness: %d\n", retval);
goto error;
}
pdata->bd->props.brightness = brightness;
usb_set_intfdata(iface, pdata);
printk(KERN_INFO "appledisplay: Apple Cinema Display connected\n");
return 0;
error:
if (pdata) {
if (pdata->urb) {
usb_kill_urb(pdata->urb);
if (pdata->urbdata)
usb_free_coherent(pdata->udev, ACD_URB_BUFFER_LEN,
pdata->urbdata, pdata->urb->transfer_dma);
usb_free_urb(pdata->urb);
}
if (pdata->bd && !IS_ERR(pdata->bd))
backlight_device_unregister(pdata->bd);
kfree(pdata->msgdata);
}
usb_set_intfdata(iface, NULL);
kfree(pdata);
return retval;
}
static void appledisplay_disconnect(struct usb_interface *iface)
{
struct appledisplay *pdata = usb_get_intfdata(iface);
if (pdata) {
usb_kill_urb(pdata->urb);
cancel_delayed_work(&pdata->work);
backlight_device_unregister(pdata->bd);
usb_free_coherent(pdata->udev, ACD_URB_BUFFER_LEN,
pdata->urbdata, pdata->urb->transfer_dma);
usb_free_urb(pdata->urb);
kfree(pdata->msgdata);
kfree(pdata);
}
printk(KERN_INFO "appledisplay: Apple Cinema Display disconnected\n");
}
static int __init appledisplay_init(void)
{
wq = create_singlethread_workqueue("appledisplay");
if (!wq) {
printk(KERN_ERR "appledisplay: Could not create work queue\n");
return -ENOMEM;
}
return usb_register(&appledisplay_driver);
}
static void __exit appledisplay_exit(void)
{
flush_workqueue(wq);
destroy_workqueue(wq);
usb_deregister(&appledisplay_driver);
}
