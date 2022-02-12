void usbip_bind_usage(void)
{
printf("usage: %s", usbip_bind_usage_string);
}
static int bind_usbip(char *busid)
{
char bus_type[] = "usb";
char attr_name[] = "bind";
char sysfs_mntpath[SYSFS_PATH_MAX];
char bind_attr_path[SYSFS_PATH_MAX];
char intf_busid[SYSFS_BUS_ID_SIZE];
struct sysfs_device *busid_dev;
struct sysfs_attribute *bind_attr;
struct sysfs_attribute *bConfValue;
struct sysfs_attribute *bNumIntfs;
int i, failed = 0;
int rc, ret = -1;
rc = sysfs_get_mnt_path(sysfs_mntpath, SYSFS_PATH_MAX);
if (rc < 0) {
err("sysfs must be mounted: %s", strerror(errno));
return -1;
}
snprintf(bind_attr_path, sizeof(bind_attr_path), "%s/%s/%s/%s/%s/%s",
sysfs_mntpath, SYSFS_BUS_NAME, bus_type, SYSFS_DRIVERS_NAME,
USBIP_HOST_DRV_NAME, attr_name);
bind_attr = sysfs_open_attribute(bind_attr_path);
if (!bind_attr) {
dbg("problem getting bind attribute: %s", strerror(errno));
return -1;
}
busid_dev = sysfs_open_device(bus_type, busid);
if (!busid_dev) {
dbg("sysfs_open_device %s failed: %s", busid, strerror(errno));
goto err_close_bind_attr;
}
bConfValue = sysfs_get_device_attr(busid_dev, "bConfigurationValue");
bNumIntfs = sysfs_get_device_attr(busid_dev, "bNumInterfaces");
if (!bConfValue || !bNumIntfs) {
dbg("problem getting device attributes: %s",
strerror(errno));
goto err_close_busid_dev;
}
for (i = 0; i < atoi(bNumIntfs->value); i++) {
snprintf(intf_busid, SYSFS_BUS_ID_SIZE, "%s:%.1s.%d", busid,
bConfValue->value, i);
rc = sysfs_write_attribute(bind_attr, intf_busid,
SYSFS_BUS_ID_SIZE);
if (rc < 0) {
dbg("bind driver at %s failed", intf_busid);
failed = 1;
}
}
if (!failed)
ret = 0;
err_close_busid_dev:
sysfs_close_device(busid_dev);
err_close_bind_attr:
sysfs_close_attribute(bind_attr);
return ret;
}
static int unbind_other(char *busid)
{
char bus_type[] = "usb";
char intf_busid[SYSFS_BUS_ID_SIZE];
struct sysfs_device *busid_dev;
struct sysfs_device *intf_dev;
struct sysfs_driver *intf_drv;
struct sysfs_attribute *unbind_attr;
struct sysfs_attribute *bConfValue;
struct sysfs_attribute *bDevClass;
struct sysfs_attribute *bNumIntfs;
int i, rc;
enum unbind_status status = UNBIND_ST_OK;
busid_dev = sysfs_open_device(bus_type, busid);
if (!busid_dev) {
dbg("sysfs_open_device %s failed: %s", busid, strerror(errno));
return -1;
}
bConfValue = sysfs_get_device_attr(busid_dev, "bConfigurationValue");
bDevClass = sysfs_get_device_attr(busid_dev, "bDeviceClass");
bNumIntfs = sysfs_get_device_attr(busid_dev, "bNumInterfaces");
if (!bConfValue || !bDevClass || !bNumIntfs) {
dbg("problem getting device attributes: %s",
strerror(errno));
goto err_close_busid_dev;
}
if (!strncmp(bDevClass->value, "09", bDevClass->len)) {
dbg("skip unbinding of hub");
goto err_close_busid_dev;
}
for (i = 0; i < atoi(bNumIntfs->value); i++) {
snprintf(intf_busid, SYSFS_BUS_ID_SIZE, "%s:%.1s.%d", busid,
bConfValue->value, i);
intf_dev = sysfs_open_device(bus_type, intf_busid);
if (!intf_dev) {
dbg("could not open interface device: %s",
strerror(errno));
goto err_close_busid_dev;
}
dbg("%s -> %s", intf_dev->name, intf_dev->driver_name);
if (!strncmp("unknown", intf_dev->driver_name, SYSFS_NAME_LEN))
continue;
if (!strncmp(USBIP_HOST_DRV_NAME, intf_dev->driver_name,
SYSFS_NAME_LEN)) {
status = UNBIND_ST_USBIP_HOST;
continue;
}
intf_drv = sysfs_open_driver(bus_type, intf_dev->driver_name);
if (!intf_drv) {
dbg("could not open interface driver on %s: %s",
intf_dev->name, strerror(errno));
goto err_close_intf_dev;
}
unbind_attr = sysfs_get_driver_attr(intf_drv, "unbind");
if (!unbind_attr) {
dbg("problem getting interface driver attribute: %s",
strerror(errno));
goto err_close_intf_drv;
}
rc = sysfs_write_attribute(unbind_attr, intf_dev->bus_id,
SYSFS_BUS_ID_SIZE);
if (rc < 0) {
dbg("unbind driver at %s failed", intf_dev->bus_id);
status = UNBIND_ST_FAILED;
}
sysfs_close_driver(intf_drv);
sysfs_close_device(intf_dev);
}
goto out;
err_close_intf_drv:
sysfs_close_driver(intf_drv);
err_close_intf_dev:
sysfs_close_device(intf_dev);
err_close_busid_dev:
status = UNBIND_ST_FAILED;
out:
sysfs_close_device(busid_dev);
return status;
}
static int bind_device(char *busid)
{
int rc;
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
printf("bind device on busid %s: complete\n", busid);
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
