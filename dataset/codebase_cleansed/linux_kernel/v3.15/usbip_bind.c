void usbip_bind_usage(void)
{
printf("usage: %s", usbip_bind_usage_string);
}
static int bind_usbip(char *busid)
{
char attr_name[] = "bind";
char bind_attr_path[SYSFS_PATH_MAX];
int rc = -1;
snprintf(bind_attr_path, sizeof(bind_attr_path), "%s/%s/%s/%s/%s/%s",
SYSFS_MNT_PATH, SYSFS_BUS_NAME, SYSFS_BUS_TYPE,
SYSFS_DRIVERS_NAME, USBIP_HOST_DRV_NAME, attr_name);
rc = write_sysfs_attribute(bind_attr_path, busid, strlen(busid));
if (rc < 0) {
err("error binding device %s to driver: %s", busid,
strerror(errno));
return -1;
}
return 0;
}
static int unbind_other(char *busid)
{
enum unbind_status status = UNBIND_ST_OK;
char attr_name[] = "unbind";
char unbind_attr_path[SYSFS_PATH_MAX];
int rc = -1;
struct udev *udev;
struct udev_device *dev;
const char *driver;
const char *bDevClass;
udev = udev_new();
dev = udev_device_new_from_subsystem_sysname(udev, "usb", busid);
if (!dev) {
dbg("unable to find device with bus ID %s", busid);
goto err_close_busid_dev;
}
bDevClass = udev_device_get_sysattr_value(dev, "bDeviceClass");
if (!bDevClass) {
dbg("unable to get bDevClass device attribute");
goto err_close_busid_dev;
}
if (!strncmp(bDevClass, "09", strlen(bDevClass))) {
dbg("skip unbinding of hub");
goto err_close_busid_dev;
}
driver = udev_device_get_driver(dev);
if (!driver) {
goto out;
}
if (!strncmp(USBIP_HOST_DRV_NAME, driver,
strlen(USBIP_HOST_DRV_NAME))) {
status = UNBIND_ST_USBIP_HOST;
goto out;
}
snprintf(unbind_attr_path, sizeof(unbind_attr_path), "%s/%s/%s/%s/%s/%s",
SYSFS_MNT_PATH, SYSFS_BUS_NAME, SYSFS_BUS_TYPE,
SYSFS_DRIVERS_NAME, driver, attr_name);
rc = write_sysfs_attribute(unbind_attr_path, busid, strlen(busid));
if (rc < 0) {
err("error unbinding device %s from driver", busid);
goto err_close_busid_dev;
}
goto out;
err_close_busid_dev:
status = UNBIND_ST_FAILED;
out:
udev_device_unref(dev);
udev_unref(udev);
return status;
}
static int bind_device(char *busid)
{
int rc;
struct udev *udev;
struct udev_device *dev;
udev = udev_new();
dev = udev_device_new_from_subsystem_sysname(udev, "usb", busid);
if (!dev) {
err("device with the specified bus ID does not exist");
return -1;
}
udev_unref(udev);
rc = unbind_other(busid);
if (rc == UNBIND_ST_FAILED) {
err("could not unbind driver from device on busid %s", busid);
return -1;
} else if (rc == UNBIND_ST_USBIP_HOST) {
err("device on busid %s is already bound to %s", busid,
USBIP_HOST_DRV_NAME);
return -1;
}
rc = modify_match_busid(busid, 1);
if (rc < 0) {
err("unable to bind device on %s", busid);
return -1;
}
rc = bind_usbip(busid);
if (rc < 0) {
err("could not bind device to %s", USBIP_HOST_DRV_NAME);
modify_match_busid(busid, 0);
return -1;
}
info("bind device on busid %s: complete", busid);
return 0;
}
int usbip_bind(int argc, char *argv[])
{
static const struct option opts[] = {
{ "busid", required_argument, NULL, 'b' },
{ NULL, 0, NULL, 0 }
};
int opt;
int ret = -1;
for (;;) {
opt = getopt_long(argc, argv, "b:", opts, NULL);
if (opt == -1)
break;
switch (opt) {
case 'b':
ret = bind_device(optarg);
goto out;
default:
goto err_out;
}
}
err_out:
usbip_bind_usage();
out:
return ret;
}
