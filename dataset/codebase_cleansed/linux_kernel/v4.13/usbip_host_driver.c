static int is_my_device(struct udev_device *dev)
{
const char *driver;
driver = udev_device_get_driver(dev);
return driver != NULL && !strcmp(driver, USBIP_HOST_DRV_NAME);
}
static int usbip_host_driver_open(struct usbip_host_driver *hdriver)
{
int ret;
hdriver->ndevs = 0;
INIT_LIST_HEAD(&hdriver->edev_list);
ret = usbip_generic_driver_open(hdriver);
if (ret)
err("please load " USBIP_CORE_MOD_NAME ".ko and "
USBIP_HOST_DRV_NAME ".ko!");
return ret;
}
