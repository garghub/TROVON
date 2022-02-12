static int hda_bus_match(struct device *dev, struct device_driver *drv)
{
struct hdac_device *hdev = dev_to_hdac_dev(dev);
struct hdac_driver *hdrv = drv_to_hdac_driver(drv);
if (hdev->type != hdrv->type)
return 0;
if (hdrv->match)
return hdrv->match(hdev, hdrv);
return 1;
}
static int __init hda_bus_init(void)
{
return bus_register(&snd_hda_bus_type);
}
static void __exit hda_bus_exit(void)
{
bus_unregister(&snd_hda_bus_type);
}
