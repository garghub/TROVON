int usb_disabled(void)
{
return nousb;
}
struct usb_host_interface *usb_find_alt_setting(
struct usb_host_config *config,
unsigned int iface_num,
unsigned int alt_num)
{
struct usb_interface_cache *intf_cache = NULL;
int i;
for (i = 0; i < config->desc.bNumInterfaces; i++) {
if (config->intf_cache[i]->altsetting[0].desc.bInterfaceNumber
== iface_num) {
intf_cache = config->intf_cache[i];
break;
}
}
if (!intf_cache)
return NULL;
for (i = 0; i < intf_cache->num_altsetting; i++)
if (intf_cache->altsetting[i].desc.bAlternateSetting == alt_num)
return &intf_cache->altsetting[i];
printk(KERN_DEBUG "Did not find alt setting %u for intf %u, "
"config %u\n", alt_num, iface_num,
config->desc.bConfigurationValue);
return NULL;
}
struct usb_interface *usb_ifnum_to_if(const struct usb_device *dev,
unsigned ifnum)
{
struct usb_host_config *config = dev->actconfig;
int i;
if (!config)
return NULL;
for (i = 0; i < config->desc.bNumInterfaces; i++)
if (config->interface[i]->altsetting[0]
.desc.bInterfaceNumber == ifnum)
return config->interface[i];
return NULL;
}
struct usb_host_interface *usb_altnum_to_altsetting(
const struct usb_interface *intf,
unsigned int altnum)
{
int i;
for (i = 0; i < intf->num_altsetting; i++) {
if (intf->altsetting[i].desc.bAlternateSetting == altnum)
return &intf->altsetting[i];
}
return NULL;
}
static int __find_interface(struct device *dev, void *data)
{
struct find_interface_arg *arg = data;
struct usb_interface *intf;
if (!is_usb_interface(dev))
return 0;
if (dev->driver != arg->drv)
return 0;
intf = to_usb_interface(dev);
return intf->minor == arg->minor;
}
struct usb_interface *usb_find_interface(struct usb_driver *drv, int minor)
{
struct find_interface_arg argb;
struct device *dev;
argb.minor = minor;
argb.drv = &drv->drvwrap.driver;
dev = bus_find_device(&usb_bus_type, NULL, &argb, __find_interface);
put_device(dev);
return dev ? to_usb_interface(dev) : NULL;
}
static int __each_dev(struct device *dev, void *data)
{
struct each_dev_arg *arg = (struct each_dev_arg *)data;
if (!is_usb_device(dev))
return 0;
return arg->fn(container_of(dev, struct usb_device, dev), arg->data);
}
int usb_for_each_dev(void *data, int (*fn)(struct usb_device *, void *))
{
struct each_dev_arg arg = {data, fn};
return bus_for_each_dev(&usb_bus_type, NULL, &arg, __each_dev);
}
static void usb_release_dev(struct device *dev)
{
struct usb_device *udev;
struct usb_hcd *hcd;
udev = to_usb_device(dev);
hcd = bus_to_hcd(udev->bus);
usb_destroy_configuration(udev);
usb_release_bos_descriptor(udev);
usb_put_hcd(hcd);
kfree(udev->product);
kfree(udev->manufacturer);
kfree(udev->serial);
kfree(udev);
}
static int usb_dev_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct usb_device *usb_dev;
usb_dev = to_usb_device(dev);
if (add_uevent_var(env, "BUSNUM=%03d", usb_dev->bus->busnum))
return -ENOMEM;
if (add_uevent_var(env, "DEVNUM=%03d", usb_dev->devnum))
return -ENOMEM;
return 0;
}
static int usb_dev_prepare(struct device *dev)
{
return 0;
}
static void usb_dev_complete(struct device *dev)
{
usb_resume_complete(dev);
}
static int usb_dev_suspend(struct device *dev)
{
return usb_suspend(dev, PMSG_SUSPEND);
}
static int usb_dev_resume(struct device *dev)
{
return usb_resume(dev, PMSG_RESUME);
}
static int usb_dev_freeze(struct device *dev)
{
return usb_suspend(dev, PMSG_FREEZE);
}
static int usb_dev_thaw(struct device *dev)
{
return usb_resume(dev, PMSG_THAW);
}
static int usb_dev_poweroff(struct device *dev)
{
return usb_suspend(dev, PMSG_HIBERNATE);
}
static int usb_dev_restore(struct device *dev)
{
return usb_resume(dev, PMSG_RESTORE);
}
static char *usb_devnode(struct device *dev,
umode_t *mode, kuid_t *uid, kgid_t *gid)
{
struct usb_device *usb_dev;
usb_dev = to_usb_device(dev);
return kasprintf(GFP_KERNEL, "bus/usb/%03d/%03d",
usb_dev->bus->busnum, usb_dev->devnum);
}
static unsigned usb_bus_is_wusb(struct usb_bus *bus)
{
struct usb_hcd *hcd = container_of(bus, struct usb_hcd, self);
return hcd->wireless;
}
struct usb_device *usb_alloc_dev(struct usb_device *parent,
struct usb_bus *bus, unsigned port1)
{
struct usb_device *dev;
struct usb_hcd *usb_hcd = bus_to_hcd(bus);
unsigned root_hub = 0;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return NULL;
if (!usb_get_hcd(usb_hcd)) {
kfree(dev);
return NULL;
}
if (usb_hcd->driver->alloc_dev && parent &&
!usb_hcd->driver->alloc_dev(usb_hcd, dev)) {
usb_put_hcd(bus_to_hcd(bus));
kfree(dev);
return NULL;
}
device_initialize(&dev->dev);
dev->dev.bus = &usb_bus_type;
dev->dev.type = &usb_device_type;
dev->dev.groups = usb_device_groups;
dev->dev.dma_mask = bus->controller->dma_mask;
set_dev_node(&dev->dev, dev_to_node(bus->controller));
dev->state = USB_STATE_ATTACHED;
dev->lpm_disable_count = 1;
atomic_set(&dev->urbnum, 0);
INIT_LIST_HEAD(&dev->ep0.urb_list);
dev->ep0.desc.bLength = USB_DT_ENDPOINT_SIZE;
dev->ep0.desc.bDescriptorType = USB_DT_ENDPOINT;
usb_enable_endpoint(dev, &dev->ep0, false);
dev->can_submit = 1;
if (unlikely(!parent)) {
dev->devpath[0] = '0';
dev->route = 0;
dev->dev.parent = bus->controller;
dev_set_name(&dev->dev, "usb%d", bus->busnum);
root_hub = 1;
} else {
if (parent->devpath[0] == '0') {
snprintf(dev->devpath, sizeof dev->devpath,
"%d", port1);
dev->route = 0;
} else {
snprintf(dev->devpath, sizeof dev->devpath,
"%s.%d", parent->devpath, port1);
if (port1 < 15)
dev->route = parent->route +
(port1 << ((parent->level - 1)*4));
else
dev->route = parent->route +
(15 << ((parent->level - 1)*4));
}
dev->dev.parent = &parent->dev;
dev_set_name(&dev->dev, "%d-%s", bus->busnum, dev->devpath);
}
dev->portnum = port1;
dev->bus = bus;
dev->parent = parent;
INIT_LIST_HEAD(&dev->filelist);
#ifdef CONFIG_PM
pm_runtime_set_autosuspend_delay(&dev->dev,
usb_autosuspend_delay * 1000);
dev->connect_time = jiffies;
dev->active_duration = -jiffies;
#endif
if (root_hub)
dev->authorized = 1;
else {
dev->authorized = !!HCD_DEV_AUTHORIZED(usb_hcd);
dev->wusb = usb_bus_is_wusb(bus) ? 1 : 0;
}
return dev;
}
struct usb_device *usb_get_dev(struct usb_device *dev)
{
if (dev)
get_device(&dev->dev);
return dev;
}
void usb_put_dev(struct usb_device *dev)
{
if (dev)
put_device(&dev->dev);
}
struct usb_interface *usb_get_intf(struct usb_interface *intf)
{
if (intf)
get_device(&intf->dev);
return intf;
}
void usb_put_intf(struct usb_interface *intf)
{
if (intf)
put_device(&intf->dev);
}
int usb_lock_device_for_reset(struct usb_device *udev,
const struct usb_interface *iface)
{
unsigned long jiffies_expire = jiffies + HZ;
if (udev->state == USB_STATE_NOTATTACHED)
return -ENODEV;
if (udev->state == USB_STATE_SUSPENDED)
return -EHOSTUNREACH;
if (iface && (iface->condition == USB_INTERFACE_UNBINDING ||
iface->condition == USB_INTERFACE_UNBOUND))
return -EINTR;
while (!usb_trylock_device(udev)) {
if (time_after(jiffies, jiffies_expire))
return -EBUSY;
msleep(15);
if (udev->state == USB_STATE_NOTATTACHED)
return -ENODEV;
if (udev->state == USB_STATE_SUSPENDED)
return -EHOSTUNREACH;
if (iface && (iface->condition == USB_INTERFACE_UNBINDING ||
iface->condition == USB_INTERFACE_UNBOUND))
return -EINTR;
}
return 0;
}
int usb_get_current_frame_number(struct usb_device *dev)
{
return usb_hcd_get_frame_number(dev);
}
int __usb_get_extra_descriptor(char *buffer, unsigned size,
unsigned char type, void **ptr)
{
struct usb_descriptor_header *header;
while (size >= sizeof(struct usb_descriptor_header)) {
header = (struct usb_descriptor_header *)buffer;
if (header->bLength < 2) {
printk(KERN_ERR
"%s: bogus descriptor, type %d length %d\n",
usbcore_name,
header->bDescriptorType,
header->bLength);
return -1;
}
if (header->bDescriptorType == type) {
*ptr = header;
return 0;
}
buffer += header->bLength;
size -= header->bLength;
}
return -1;
}
void *usb_alloc_coherent(struct usb_device *dev, size_t size, gfp_t mem_flags,
dma_addr_t *dma)
{
if (!dev || !dev->bus)
return NULL;
return hcd_buffer_alloc(dev->bus, size, mem_flags, dma);
}
void usb_free_coherent(struct usb_device *dev, size_t size, void *addr,
dma_addr_t dma)
{
if (!dev || !dev->bus)
return;
if (!addr)
return;
hcd_buffer_free(dev->bus, size, addr, dma);
}
static int usb_bus_notify(struct notifier_block *nb, unsigned long action,
void *data)
{
struct device *dev = data;
switch (action) {
case BUS_NOTIFY_ADD_DEVICE:
if (dev->type == &usb_device_type)
(void) usb_create_sysfs_dev_files(to_usb_device(dev));
else if (dev->type == &usb_if_device_type)
usb_create_sysfs_intf_files(to_usb_interface(dev));
break;
case BUS_NOTIFY_DEL_DEVICE:
if (dev->type == &usb_device_type)
usb_remove_sysfs_dev_files(to_usb_device(dev));
else if (dev->type == &usb_if_device_type)
usb_remove_sysfs_intf_files(to_usb_interface(dev));
break;
}
return 0;
}
static int usb_debugfs_init(void)
{
usb_debug_root = debugfs_create_dir("usb", NULL);
if (!usb_debug_root)
return -ENOENT;
usb_debug_devices = debugfs_create_file("devices", 0444,
usb_debug_root, NULL,
&usbfs_devices_fops);
if (!usb_debug_devices) {
debugfs_remove(usb_debug_root);
usb_debug_root = NULL;
return -ENOENT;
}
return 0;
}
static void usb_debugfs_cleanup(void)
{
debugfs_remove(usb_debug_devices);
debugfs_remove(usb_debug_root);
}
static int __init usb_init(void)
{
int retval;
if (usb_disabled()) {
pr_info("%s: USB support disabled\n", usbcore_name);
return 0;
}
usb_init_pool_max();
retval = usb_debugfs_init();
if (retval)
goto out;
usb_acpi_register();
retval = bus_register(&usb_bus_type);
if (retval)
goto bus_register_failed;
retval = bus_register_notifier(&usb_bus_type, &usb_bus_nb);
if (retval)
goto bus_notifier_failed;
retval = usb_major_init();
if (retval)
goto major_init_failed;
retval = usb_register(&usbfs_driver);
if (retval)
goto driver_register_failed;
retval = usb_devio_init();
if (retval)
goto usb_devio_init_failed;
retval = usb_hub_init();
if (retval)
goto hub_init_failed;
retval = usb_register_device_driver(&usb_generic_driver, THIS_MODULE);
if (!retval)
goto out;
usb_hub_cleanup();
hub_init_failed:
usb_devio_cleanup();
usb_devio_init_failed:
usb_deregister(&usbfs_driver);
driver_register_failed:
usb_major_cleanup();
major_init_failed:
bus_unregister_notifier(&usb_bus_type, &usb_bus_nb);
bus_notifier_failed:
bus_unregister(&usb_bus_type);
bus_register_failed:
usb_acpi_unregister();
usb_debugfs_cleanup();
out:
return retval;
}
static void __exit usb_exit(void)
{
if (usb_disabled())
return;
usb_deregister_device_driver(&usb_generic_driver);
usb_major_cleanup();
usb_deregister(&usbfs_driver);
usb_devio_cleanup();
usb_hub_cleanup();
bus_unregister_notifier(&usb_bus_type, &usb_bus_nb);
bus_unregister(&usb_bus_type);
usb_acpi_unregister();
usb_debugfs_cleanup();
}
