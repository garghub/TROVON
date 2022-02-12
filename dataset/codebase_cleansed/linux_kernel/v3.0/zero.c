struct usb_request *alloc_ep_req(struct usb_ep *ep)
{
struct usb_request *req;
req = usb_ep_alloc_request(ep, GFP_ATOMIC);
if (req) {
req->length = buflen;
req->buf = kmalloc(buflen, GFP_ATOMIC);
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
struct usb_ep *in, struct usb_ep *out)
{
disable_ep(cdev, in);
disable_ep(cdev, out);
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
int gcnum;
struct usb_gadget *gadget = cdev->gadget;
int id;
id = usb_string_id(cdev);
if (id < 0)
return id;
strings_dev[STRING_MANUFACTURER_IDX].id = id;
device_desc.iManufacturer = id;
id = usb_string_id(cdev);
if (id < 0)
return id;
strings_dev[STRING_PRODUCT_IDX].id = id;
device_desc.iProduct = id;
id = usb_string_id(cdev);
if (id < 0)
return id;
strings_dev[STRING_SERIAL_IDX].id = id;
device_desc.iSerialNumber = id;
setup_timer(&autoresume_timer, zero_autoresume, (unsigned long) cdev);
if (loopdefault) {
loopback_add(cdev, autoresume != 0);
sourcesink_add(cdev, autoresume != 0);
} else {
sourcesink_add(cdev, autoresume != 0);
loopback_add(cdev, autoresume != 0);
}
gcnum = usb_gadget_controller_number(gadget);
if (gcnum >= 0)
device_desc.bcdDevice = cpu_to_le16(0x0200 + gcnum);
else {
pr_warning("%s: controller '%s' not recognized\n",
longname, gadget->name);
device_desc.bcdDevice = cpu_to_le16(0x9999);
}
INFO(cdev, "%s, version: " DRIVER_VERSION "\n", longname);
snprintf(manufacturer, sizeof manufacturer, "%s %s with %s",
init_utsname()->sysname, init_utsname()->release,
gadget->name);
return 0;
}
static int zero_unbind(struct usb_composite_dev *cdev)
{
del_timer_sync(&autoresume_timer);
return 0;
}
static int __init init(void)
{
return usb_composite_probe(&zero_driver, zero_bind);
}
static void __exit cleanup(void)
{
usb_composite_unregister(&zero_driver);
}
