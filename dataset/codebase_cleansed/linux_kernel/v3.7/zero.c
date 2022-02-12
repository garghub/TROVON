struct usb_request *alloc_ep_req(struct usb_ep *ep, int len)
{
struct usb_request *req;
req = usb_ep_alloc_request(ep, GFP_ATOMIC);
if (req) {
if (len)
req->length = len;
else
req->length = buflen;
req->buf = kmalloc(req->length, GFP_ATOMIC);
if (!req->buf) {
usb_ep_free_request(ep, req);
req = NULL;
}
}
return req;
}
void free_ep_req(struct usb_ep *ep, struct usb_request *req)
{
kfree(req->buf);
usb_ep_free_request(ep, req);
}
static void disable_ep(struct usb_composite_dev *cdev, struct usb_ep *ep)
{
int value;
if (ep->driver_data) {
value = usb_ep_disable(ep);
if (value < 0)
DBG(cdev, "disable %s --> %d\n",
ep->name, value);
ep->driver_data = NULL;
}
}
void disable_endpoints(struct usb_composite_dev *cdev,
struct usb_ep *in, struct usb_ep *out,
struct usb_ep *iso_in, struct usb_ep *iso_out)
{
disable_ep(cdev, in);
disable_ep(cdev, out);
if (iso_in)
disable_ep(cdev, iso_in);
if (iso_out)
disable_ep(cdev, iso_out);
}
static void zero_autoresume(unsigned long _c)
{
struct usb_composite_dev *cdev = (void *)_c;
struct usb_gadget *g = cdev->gadget;
if (!cdev->config)
return;
if (g->speed != USB_SPEED_UNKNOWN) {
int status = usb_gadget_wakeup(g);
INFO(cdev, "%s --> %d\n", __func__, status);
}
}
static void zero_suspend(struct usb_composite_dev *cdev)
{
if (cdev->gadget->speed == USB_SPEED_UNKNOWN)
return;
if (autoresume) {
mod_timer(&autoresume_timer, jiffies + (HZ * autoresume));
DBG(cdev, "suspend, wakeup in %d seconds\n", autoresume);
} else
DBG(cdev, "%s\n", __func__);
}
static void zero_resume(struct usb_composite_dev *cdev)
{
DBG(cdev, "%s\n", __func__);
del_timer(&autoresume_timer);
}
static int __init zero_bind(struct usb_composite_dev *cdev)
{
int status;
status = usb_string_ids_tab(cdev, strings_dev);
if (status < 0)
return status;
device_desc.iManufacturer = strings_dev[USB_GADGET_MANUFACTURER_IDX].id;
device_desc.iProduct = strings_dev[USB_GADGET_PRODUCT_IDX].id;
device_desc.iSerialNumber = strings_dev[USB_GADGET_SERIAL_IDX].id;
setup_timer(&autoresume_timer, zero_autoresume, (unsigned long) cdev);
if (loopdefault) {
loopback_add(cdev, autoresume != 0);
sourcesink_add(cdev, autoresume != 0);
} else {
sourcesink_add(cdev, autoresume != 0);
loopback_add(cdev, autoresume != 0);
}
usb_composite_overwrite_options(cdev, &coverwrite);
INFO(cdev, "%s, version: " DRIVER_VERSION "\n", longname);
return 0;
}
static int zero_unbind(struct usb_composite_dev *cdev)
{
del_timer_sync(&autoresume_timer);
return 0;
}
static int __init init(void)
{
return usb_composite_probe(&zero_driver);
}
static void __exit cleanup(void)
{
usb_composite_unregister(&zero_driver);
}
