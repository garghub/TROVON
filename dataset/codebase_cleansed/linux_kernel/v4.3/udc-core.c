int usb_gadget_map_request(struct usb_gadget *gadget,
struct usb_request *req, int is_in)
{
struct device *dev = gadget->dev.parent;
if (req->length == 0)
return 0;
if (req->num_sgs) {
int mapped;
mapped = dma_map_sg(dev, req->sg, req->num_sgs,
is_in ? DMA_TO_DEVICE : DMA_FROM_DEVICE);
if (mapped == 0) {
dev_err(&gadget->dev, "failed to map SGs\n");
return -EFAULT;
}
req->num_mapped_sgs = mapped;
} else {
req->dma = dma_map_single(dev, req->buf, req->length,
is_in ? DMA_TO_DEVICE : DMA_FROM_DEVICE);
if (dma_mapping_error(dev, req->dma)) {
dev_err(dev, "failed to map buffer\n");
return -EFAULT;
}
}
return 0;
}
void usb_gadget_unmap_request(struct usb_gadget *gadget,
struct usb_request *req, int is_in)
{
if (req->length == 0)
return;
if (req->num_mapped_sgs) {
dma_unmap_sg(gadget->dev.parent, req->sg, req->num_mapped_sgs,
is_in ? DMA_TO_DEVICE : DMA_FROM_DEVICE);
req->num_mapped_sgs = 0;
} else {
dma_unmap_single(gadget->dev.parent, req->dma, req->length,
is_in ? DMA_TO_DEVICE : DMA_FROM_DEVICE);
}
}
void usb_gadget_giveback_request(struct usb_ep *ep,
struct usb_request *req)
{
if (likely(req->status == 0))
usb_led_activity(USB_LED_EVENT_GADGET);
req->complete(ep, req);
}
struct usb_ep *gadget_find_ep_by_name(struct usb_gadget *g, const char *name)
{
struct usb_ep *ep;
gadget_for_each_ep(ep, g) {
if (!strcmp(ep->name, name))
return ep;
}
return NULL;
}
int usb_gadget_ep_match_desc(struct usb_gadget *gadget,
struct usb_ep *ep, struct usb_endpoint_descriptor *desc,
struct usb_ss_ep_comp_descriptor *ep_comp)
{
u8 type;
u16 max;
int num_req_streams = 0;
if (ep->claimed)
return 0;
type = usb_endpoint_type(desc);
max = 0x7ff & usb_endpoint_maxp(desc);
if (usb_endpoint_dir_in(desc) && !ep->caps.dir_in)
return 0;
if (usb_endpoint_dir_out(desc) && !ep->caps.dir_out)
return 0;
if (max > ep->maxpacket_limit)
return 0;
if (!gadget_is_dualspeed(gadget) && usb_endpoint_maxp(desc) & (3<<11))
return 0;
switch (type) {
case USB_ENDPOINT_XFER_CONTROL:
return 0;
case USB_ENDPOINT_XFER_ISOC:
if (!ep->caps.type_iso)
return 0;
if (!gadget_is_dualspeed(gadget) && max > 1023)
return 0;
break;
case USB_ENDPOINT_XFER_BULK:
if (!ep->caps.type_bulk)
return 0;
if (ep_comp && gadget_is_superspeed(gadget)) {
num_req_streams = ep_comp->bmAttributes & 0x1f;
if (num_req_streams > ep->max_streams)
return 0;
}
break;
case USB_ENDPOINT_XFER_INT:
if (!ep->caps.type_int && !ep->caps.type_bulk)
return 0;
if (!gadget_is_dualspeed(gadget) && max > 64)
return 0;
break;
}
return 1;
}
static void usb_gadget_state_work(struct work_struct *work)
{
struct usb_gadget *gadget = work_to_gadget(work);
struct usb_udc *udc = gadget->udc;
if (udc)
sysfs_notify(&udc->dev.kobj, NULL, "state");
}
void usb_gadget_set_state(struct usb_gadget *gadget,
enum usb_device_state state)
{
gadget->state = state;
schedule_work(&gadget->work);
}
static void usb_udc_connect_control(struct usb_udc *udc)
{
if (udc->vbus)
usb_gadget_connect(udc->gadget);
else
usb_gadget_disconnect(udc->gadget);
}
void usb_udc_vbus_handler(struct usb_gadget *gadget, bool status)
{
struct usb_udc *udc = gadget->udc;
if (udc) {
udc->vbus = status;
usb_udc_connect_control(udc);
}
}
void usb_gadget_udc_reset(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
driver->reset(gadget);
usb_gadget_set_state(gadget, USB_STATE_DEFAULT);
}
static inline int usb_gadget_udc_start(struct usb_udc *udc)
{
return udc->gadget->ops->udc_start(udc->gadget, udc->driver);
}
static inline void usb_gadget_udc_stop(struct usb_udc *udc)
{
udc->gadget->ops->udc_stop(udc->gadget);
}
static void usb_udc_release(struct device *dev)
{
struct usb_udc *udc;
udc = container_of(dev, struct usb_udc, dev);
dev_dbg(dev, "releasing '%s'\n", dev_name(dev));
kfree(udc);
}
static void usb_udc_nop_release(struct device *dev)
{
dev_vdbg(dev, "%s\n", __func__);
}
int usb_add_gadget_udc_release(struct device *parent, struct usb_gadget *gadget,
void (*release)(struct device *dev))
{
struct usb_udc *udc;
int ret = -ENOMEM;
udc = kzalloc(sizeof(*udc), GFP_KERNEL);
if (!udc)
goto err1;
dev_set_name(&gadget->dev, "gadget");
INIT_WORK(&gadget->work, usb_gadget_state_work);
gadget->dev.parent = parent;
#ifdef CONFIG_HAS_DMA
dma_set_coherent_mask(&gadget->dev, parent->coherent_dma_mask);
gadget->dev.dma_parms = parent->dma_parms;
gadget->dev.dma_mask = parent->dma_mask;
#endif
if (release)
gadget->dev.release = release;
else
gadget->dev.release = usb_udc_nop_release;
ret = device_register(&gadget->dev);
if (ret)
goto err2;
device_initialize(&udc->dev);
udc->dev.release = usb_udc_release;
udc->dev.class = udc_class;
udc->dev.groups = usb_udc_attr_groups;
udc->dev.parent = parent;
ret = dev_set_name(&udc->dev, "%s", kobject_name(&parent->kobj));
if (ret)
goto err3;
udc->gadget = gadget;
gadget->udc = udc;
mutex_lock(&udc_lock);
list_add_tail(&udc->list, &udc_list);
ret = device_add(&udc->dev);
if (ret)
goto err4;
usb_gadget_set_state(gadget, USB_STATE_NOTATTACHED);
udc->vbus = true;
mutex_unlock(&udc_lock);
return 0;
err4:
list_del(&udc->list);
mutex_unlock(&udc_lock);
err3:
put_device(&udc->dev);
device_del(&gadget->dev);
err2:
put_device(&gadget->dev);
kfree(udc);
err1:
return ret;
}
int usb_add_gadget_udc(struct device *parent, struct usb_gadget *gadget)
{
return usb_add_gadget_udc_release(parent, gadget, NULL);
}
static void usb_gadget_remove_driver(struct usb_udc *udc)
{
dev_dbg(&udc->dev, "unregistering UDC driver [%s]\n",
udc->driver->function);
kobject_uevent(&udc->dev.kobj, KOBJ_CHANGE);
usb_gadget_disconnect(udc->gadget);
udc->driver->disconnect(udc->gadget);
udc->driver->unbind(udc->gadget);
usb_gadget_udc_stop(udc);
udc->driver = NULL;
udc->dev.driver = NULL;
udc->gadget->dev.driver = NULL;
}
void usb_del_gadget_udc(struct usb_gadget *gadget)
{
struct usb_udc *udc = gadget->udc;
if (!udc)
return;
dev_vdbg(gadget->dev.parent, "unregistering gadget\n");
mutex_lock(&udc_lock);
list_del(&udc->list);
mutex_unlock(&udc_lock);
if (udc->driver)
usb_gadget_remove_driver(udc);
kobject_uevent(&udc->dev.kobj, KOBJ_REMOVE);
flush_work(&gadget->work);
device_unregister(&udc->dev);
device_unregister(&gadget->dev);
}
static int udc_bind_to_driver(struct usb_udc *udc, struct usb_gadget_driver *driver)
{
int ret;
dev_dbg(&udc->dev, "registering UDC driver [%s]\n",
driver->function);
udc->driver = driver;
udc->dev.driver = &driver->driver;
udc->gadget->dev.driver = &driver->driver;
ret = driver->bind(udc->gadget, driver);
if (ret)
goto err1;
ret = usb_gadget_udc_start(udc);
if (ret) {
driver->unbind(udc->gadget);
goto err1;
}
usb_udc_connect_control(udc);
kobject_uevent(&udc->dev.kobj, KOBJ_CHANGE);
return 0;
err1:
if (ret != -EISNAM)
dev_err(&udc->dev, "failed to start %s: %d\n",
udc->driver->function, ret);
udc->driver = NULL;
udc->dev.driver = NULL;
udc->gadget->dev.driver = NULL;
return ret;
}
int usb_udc_attach_driver(const char *name, struct usb_gadget_driver *driver)
{
struct usb_udc *udc = NULL;
int ret = -ENODEV;
mutex_lock(&udc_lock);
list_for_each_entry(udc, &udc_list, list) {
ret = strcmp(name, dev_name(&udc->dev));
if (!ret)
break;
}
if (ret) {
ret = -ENODEV;
goto out;
}
if (udc->driver) {
ret = -EBUSY;
goto out;
}
ret = udc_bind_to_driver(udc, driver);
out:
mutex_unlock(&udc_lock);
return ret;
}
int usb_gadget_probe_driver(struct usb_gadget_driver *driver)
{
struct usb_udc *udc = NULL;
int ret;
if (!driver || !driver->bind || !driver->setup)
return -EINVAL;
mutex_lock(&udc_lock);
list_for_each_entry(udc, &udc_list, list) {
if (!udc->driver)
goto found;
}
pr_debug("couldn't find an available UDC\n");
mutex_unlock(&udc_lock);
return -ENODEV;
found:
ret = udc_bind_to_driver(udc, driver);
mutex_unlock(&udc_lock);
return ret;
}
int usb_gadget_unregister_driver(struct usb_gadget_driver *driver)
{
struct usb_udc *udc = NULL;
int ret = -ENODEV;
if (!driver || !driver->unbind)
return -EINVAL;
mutex_lock(&udc_lock);
list_for_each_entry(udc, &udc_list, list)
if (udc->driver == driver) {
usb_gadget_remove_driver(udc);
usb_gadget_set_state(udc->gadget,
USB_STATE_NOTATTACHED);
ret = 0;
break;
}
mutex_unlock(&udc_lock);
return ret;
}
static ssize_t usb_udc_srp_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t n)
{
struct usb_udc *udc = container_of(dev, struct usb_udc, dev);
if (sysfs_streq(buf, "1"))
usb_gadget_wakeup(udc->gadget);
return n;
}
static ssize_t usb_udc_softconn_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t n)
{
struct usb_udc *udc = container_of(dev, struct usb_udc, dev);
if (!udc->driver) {
dev_err(dev, "soft-connect without a gadget driver\n");
return -EOPNOTSUPP;
}
if (sysfs_streq(buf, "connect")) {
usb_gadget_udc_start(udc);
usb_gadget_connect(udc->gadget);
} else if (sysfs_streq(buf, "disconnect")) {
usb_gadget_disconnect(udc->gadget);
udc->driver->disconnect(udc->gadget);
usb_gadget_udc_stop(udc);
} else {
dev_err(dev, "unsupported command '%s'\n", buf);
return -EINVAL;
}
return n;
}
static ssize_t state_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct usb_udc *udc = container_of(dev, struct usb_udc, dev);
struct usb_gadget *gadget = udc->gadget;
return sprintf(buf, "%s\n", usb_state_string(gadget->state));
}
static int usb_udc_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct usb_udc *udc = container_of(dev, struct usb_udc, dev);
int ret;
ret = add_uevent_var(env, "USB_UDC_NAME=%s", udc->gadget->name);
if (ret) {
dev_err(dev, "failed to add uevent USB_UDC_NAME\n");
return ret;
}
if (udc->driver) {
ret = add_uevent_var(env, "USB_UDC_DRIVER=%s",
udc->driver->function);
if (ret) {
dev_err(dev, "failed to add uevent USB_UDC_DRIVER\n");
return ret;
}
}
return 0;
}
static int __init usb_udc_init(void)
{
udc_class = class_create(THIS_MODULE, "udc");
if (IS_ERR(udc_class)) {
pr_err("failed to create udc class --> %ld\n",
PTR_ERR(udc_class));
return PTR_ERR(udc_class);
}
udc_class->dev_uevent = usb_udc_uevent;
return 0;
}
static void __exit usb_udc_exit(void)
{
class_destroy(udc_class);
}
