static int udl_usb_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
return drm_get_usb_dev(interface, id, &driver);
}
static void udl_usb_disconnect(struct usb_interface *interface)
{
struct drm_device *dev = usb_get_intfdata(interface);
drm_kms_helper_poll_disable(dev);
drm_connector_unplug_all(dev);
udl_fbdev_unplug(dev);
udl_drop_usb(dev);
drm_unplug_dev(dev);
}
static int __init udl_init(void)
{
return drm_usb_init(&driver, &udl_driver);
}
static void __exit udl_exit(void)
{
drm_usb_exit(&driver, &udl_driver);
}
