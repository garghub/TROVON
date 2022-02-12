void usbip_unbind_usage(void)
{
printf("usage: %s", usbip_unbind_usage_string);
}
static int unbind_device(char *busid)
{
char bus_type[] = "usb";
struct sysfs_driver *usbip_host_drv;
struct sysfs_device *dev;
struct dlist *devlist;
int verified = 0;
int rc, ret = -1;
char attr_name[] = "bConfigurationValue";
char sysfs_mntpath[SYSFS_PATH_MAX];
char busid_attr_path[SYSFS_PATH_MAX];
struct sysfs_attribute *busid_attr;
char *val = NULL;
int len;
usbip_host_drv = sysfs_open_driver(bus_type, USBIP_HOST_DRV_NAME);
if (!usbip_host_drv) {
err("could not open %s driver: %s", USBIP_HOST_DRV_NAME,
strerror(errno));
return -1;
}
devlist = sysfs_get_driver_devices(usbip_host_drv);
if (!devlist) {
err("%s is not in use by any devices", USBIP_HOST_DRV_NAME);
goto err_close_usbip_host_drv;
}
dlist_for_each_data(devlist, dev, struct sysfs_device) {
if (!strncmp(busid, dev->name, strlen(busid)) &&
!strncmp(dev->driver_name, USBIP_HOST_DRV_NAME,
strlen(USBIP_HOST_DRV_NAME))) {
verified = 1;
break;
}
}
if (!verified) {
err("device on busid %s is not using %s", busid,
USBIP_HOST_DRV_NAME);
goto err_close_usbip_host_drv;
}
rc = sysfs_get_mnt_path(sysfs_mntpath, SYSFS_PATH_MAX);
if (rc < 0) {
err("sysfs must be mounted: %s", strerror(errno));
return -1;
}
snprintf(busid_attr_path, sizeof(busid_attr_path), "%s/%s/%s/%s/%s/%s",
sysfs_mntpath, SYSFS_BUS_NAME, bus_type, SYSFS_DEVICES_NAME,
busid, attr_name);
busid_attr = sysfs_open_attribute(busid_attr_path);
if (!busid_attr) {
err("could not open %s/%s: %s", busid, attr_name,
strerror(errno));
return -1;
}
if (sysfs_read_attribute(busid_attr) < 0) {
err("problem reading attribute: %s", strerror(errno));
goto err_out;
}
len = busid_attr->len;
val = malloc(len);
*val = *busid_attr->value;
sysfs_close_attribute(busid_attr);
rc = modify_match_busid(busid, 0);
if (rc < 0) {
err("unable to unbind device on %s", busid);
goto err_out;
}
busid_attr = sysfs_open_attribute(busid_attr_path);
if (!busid_attr) {
err("could not open %s/%s: %s", busid, attr_name,
strerror(errno));
return -1;
}
rc = sysfs_write_attribute(busid_attr, val, len);
if (rc < 0) {
err("problem writing attribute: %s", strerror(errno));
goto err_out;
}
sysfs_close_attribute(busid_attr);
ret = 0;
printf("unbind device on busid %s: complete\n", busid);
err_out:
free(val);
err_close_usbip_host_drv:
sysfs_close_driver(usbip_host_drv);
return ret;
}
int usbip_unbind(int argc, char *argv[])
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
ret = unbind_device(optarg);
goto out;
default:
goto err_out;
}
}
err_out:
usbip_unbind_usage();
out:
return ret;
}
