static int udl_driver_set_busid(struct drm_device *d, struct drm_master *m)
{
return 0;
}
static int udl_usb_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(interface);
struct drm_device *dev;
int r;
dev = drm_dev_alloc(&driver, &interface->dev);
if (!dev)
return -ENOMEM;
r = drm_dev_register(dev, (unsigned long)udev);
if (r)
goto err_free;
usb_set_intfdata(interface, dev);
DRM_INFO("Initialized udl on minor %d\n", dev->primary->index);
return 0;
err_free:
drm_dev_unref(dev);
return r;
}
static void udl_usb_disconnect(struct usb_interface *interface)
{
struct drm_device *dev = usb_get_intfdata(interface);
drm_kms_helper_poll_disable(dev);
udl_fbdev_unplug(dev);
udl_drop_usb(dev);
drm_unplug_dev(dev);
}
