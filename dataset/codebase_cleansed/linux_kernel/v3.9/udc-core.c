int usb_gadget_map_request(struct usb_gadget *gadget,
struct usb_request *req, int is_in)
{
if (req->length == 0)
return 0;
if (req->num_sgs) {
int mapped;
mapped = dma_map_sg(&gadget->dev, req->sg, req->num_sgs,
is_in ? DMA_TO_DEVICE : DMA_FROM_DEVICE);
if (mapped == 0) {
dev_err(&gadget->dev, "failed to map SGs\n");
return -EFAULT;
}
req->num_mapped_sgs = mapped;
} else {
req->dma = dma_map_single(&gadget->dev, req->buf, req->length,
is_in ? DMA_TO_DEVICE : DMA_FROM_DEVICE);
if (dma_mapping_error(&gadget->dev, req->dma)) {
dev_err(&gadget->dev, "failed to map buffer\n");
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
dma_unmap_sg(&gadget->dev, req->sg, req->num_mapped_sgs,
is_in ? DMA_TO_DEVICE : DMA_FROM_DEVICE);
req->num_mapped_sgs = 0;
} else {
dma_unmap_single(&gadget->dev, req->dma, req->length,
is_in ? DMA_TO_DEVICE : DMA_FROM_DEVICE);
}
}
static inline int usb_gadget_udc_start(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
return gadget->ops->udc_start(gadget, driver);
}
static inline void usb_gadget_udc_stop(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
gadget->ops->udc_stop(gadget, driver);
}
static void usb_udc_release(struct device *dev)
{
struct usb_udc *udc;
udc = container_of(dev, struct usb_udc, dev);
dev_dbg(dev, "releasing '%s'\n", dev_name(dev));
kfree(udc);
}
int usb_add_gadget_udc(struct device *parent, struct usb_gadget *gadget)
{
struct usb_udc *udc;
int ret = -ENOMEM;
udc = kzalloc(sizeof(*udc), GFP_KERNEL);
if (!udc)
goto err1;
device_initialize(&udc->dev);
udc->dev.release = usb_udc_release;
udc->dev.class = udc_class;
udc->dev.groups = usb_udc_attr_groups;
udc->dev.parent = parent;
ret = dev_set_name(&udc->dev, "%s", kobject_name(&parent->kobj));
if (ret)
goto err2;
udc->gadget = gadget;
mutex_lock(&udc_lock);
list_add_tail(&udc->list, &udc_list);
ret = device_add(&udc->dev);
if (ret)
goto err3;
mutex_unlock(&udc_lock);
return 0;
err3:
list_del(&udc->list);
mutex_unlock(&udc_lock);
err2:
put_device(&udc->dev);
err1:
return ret;
}
static void usb_gadget_remove_driver(struct usb_udc *udc)
{
dev_dbg(&udc->dev, "unregistering UDC driver [%s]\n",
udc->gadget->name);
kobject_uevent(&udc->dev.kobj, KOBJ_CHANGE);
usb_gadget_disconnect(udc->gadget);
udc->driver->disconnect(udc->gadget);
udc->driver->unbind(udc->gadget);
usb_gadget_udc_stop(udc->gadget, NULL);
udc->driver = NULL;
udc->dev.driver = NULL;
}
void usb_del_gadget_udc(struct usb_gadget *gadget)
{
struct usb_udc *udc = NULL;
mutex_lock(&udc_lock);
list_for_each_entry(udc, &udc_list, list)
if (udc->gadget == gadget)
goto found;
dev_err(gadget->dev.parent, "gadget not registered.\n");
mutex_unlock(&udc_lock);
return;
found:
dev_vdbg(gadget->dev.parent, "unregistering gadget\n");
list_del(&udc->list);
mutex_unlock(&udc_lock);
if (udc->driver)
usb_gadget_remove_driver(udc);
kobject_uevent(&udc->dev.kobj, KOBJ_REMOVE);
device_unregister(&udc->dev);
}
static int udc_bind_to_driver(struct usb_udc *udc, struct usb_gadget_driver *driver)
{
int ret;
dev_dbg(&udc->dev, "registering UDC driver [%s]\n",
driver->function);
udc->driver = driver;
udc->dev.driver = &driver->driver;
ret = driver->bind(udc->gadget, driver);
if (ret)
goto err1;
ret = usb_gadget_udc_start(udc->gadget, driver);
if (ret) {
driver->unbind(udc->gadget);
goto err1;
}
usb_gadget_connect(udc->gadget);
kobject_uevent(&udc->dev.kobj, KOBJ_CHANGE);
return 0;
err1:
dev_err(&udc->dev, "failed to start %s: %d\n",
udc->driver->function, ret);
udc->driver = NULL;
udc->dev.driver = NULL;
return ret;
}
int udc_attach_driver(const char *name, struct usb_gadget_driver *driver)
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
if (sysfs_streq(buf, "connect")) {
usb_gadget_udc_start(udc->gadget, udc->driver);
usb_gadget_connect(udc->gadget);
} else if (sysfs_streq(buf, "disconnect")) {
usb_gadget_disconnect(udc->gadget);
usb_gadget_udc_stop(udc->gadget, udc->driver);
} else {
dev_err(dev, "unsupported command '%s'\n", buf);
return -EINVAL;
}
return n;
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
