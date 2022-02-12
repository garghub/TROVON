static
int read_usb_vudc_device(struct udev_device *sdev, struct usbip_usb_device *dev)
{
const char *path, *name;
char filepath[SYSFS_PATH_MAX];
struct usb_device_descriptor descr;
unsigned i;
FILE *fd = NULL;
struct udev_device *plat;
const char *speed;
int ret = 0;
plat = udev_device_get_parent(sdev);
path = udev_device_get_syspath(plat);
snprintf(filepath, SYSFS_PATH_MAX, "%s/%s",
path, VUDC_DEVICE_DESCR_FILE);
fd = fopen(filepath, "r");
if (!fd)
return -1;
ret = fread((char *) &descr, sizeof(descr), 1, fd);
if (ret < 0)
return -1;
fclose(fd);
copy_descr_attr(dev, &descr, bDeviceClass);
copy_descr_attr(dev, &descr, bDeviceSubClass);
copy_descr_attr(dev, &descr, bDeviceProtocol);
copy_descr_attr(dev, &descr, bNumConfigurations);
copy_descr_attr16(dev, &descr, idVendor);
copy_descr_attr16(dev, &descr, idProduct);
copy_descr_attr16(dev, &descr, bcdDevice);
strncpy(dev->path, path, SYSFS_PATH_MAX);
dev->speed = USB_SPEED_UNKNOWN;
speed = udev_device_get_sysattr_value(sdev, "current_speed");
if (speed) {
for (i = 0; i < ARRAY_SIZE(speed_names); i++) {
if (!strcmp(speed_names[i].name, speed)) {
dev->speed = speed_names[i].speed;
break;
}
}
}
dev->bNumInterfaces = 0;
dev->bConfigurationValue = 0;
dev->busnum = 0;
name = udev_device_get_sysname(plat);
strncpy(dev->busid, name, SYSFS_BUS_ID_SIZE);
return 0;
}
static int is_my_device(struct udev_device *dev)
{
const char *driver;
driver = udev_device_get_property_value(dev, "USB_UDC_NAME");
return driver != NULL && !strcmp(driver, USBIP_DEVICE_DRV_NAME);
}
static int usbip_device_driver_open(struct usbip_host_driver *hdriver)
{
int ret;
hdriver->ndevs = 0;
INIT_LIST_HEAD(&hdriver->edev_list);
ret = usbip_generic_driver_open(hdriver);
if (ret)
err("please load " USBIP_CORE_MOD_NAME ".ko and "
USBIP_DEVICE_DRV_NAME ".ko!");
return ret;
}
