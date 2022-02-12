static ssize_t modalias_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct visor_device *vdev;
uuid_le guid;
vdev = to_visor_device(dev);
guid = visorchannel_get_uuid(vdev->visorchannel);
return sprintf(buf, "visorbus:%pUl\n", &guid);
}
static int
visorbus_uevent(struct device *xdev, struct kobj_uevent_env *env)
{
struct visor_device *dev;
uuid_le guid;
dev = to_visor_device(xdev);
guid = visorchannel_get_uuid(dev->visorchannel);
return add_uevent_var(env, "MODALIAS=visorbus:%pUl", &guid);
}
static int
visorbus_match(struct device *xdev, struct device_driver *xdrv)
{
uuid_le channel_type;
int i;
struct visor_device *dev;
struct visor_driver *drv;
dev = to_visor_device(xdev);
drv = to_visor_driver(xdrv);
channel_type = visorchannel_get_uuid(dev->visorchannel);
if (!drv->channel_types)
return 0;
for (i = 0;
(uuid_le_cmp(drv->channel_types[i].guid, NULL_UUID_LE) != 0) ||
(drv->channel_types[i].name);
i++)
if (uuid_le_cmp(drv->channel_types[i].guid,
channel_type) == 0)
return i + 1;
return 0;
}
static void
visorbus_release_busdevice(struct device *xdev)
{
struct visor_device *dev = dev_get_drvdata(xdev);
debugfs_remove(dev->debugfs_client_bus_info);
debugfs_remove_recursive(dev->debugfs_dir);
kfree(dev);
}
static void
visorbus_release_device(struct device *xdev)
{
struct visor_device *dev = to_visor_device(xdev);
if (dev->visorchannel) {
visorchannel_destroy(dev->visorchannel);
dev->visorchannel = NULL;
}
kfree(dev);
}
static ssize_t physaddr_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct visor_device *vdev = to_visor_device(dev);
return sprintf(buf, "0x%llx\n",
visorchannel_get_physaddr(vdev->visorchannel));
}
static ssize_t nbytes_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct visor_device *vdev = to_visor_device(dev);
return sprintf(buf, "0x%lx\n",
visorchannel_get_nbytes(vdev->visorchannel));
}
static ssize_t clientpartition_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct visor_device *vdev = to_visor_device(dev);
return sprintf(buf, "0x%llx\n",
visorchannel_get_clientpartition(vdev->visorchannel));
}
static ssize_t typeguid_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct visor_device *vdev = to_visor_device(dev);
char typeid[LINESIZE];
return sprintf(buf, "%s\n",
visorchannel_id(vdev->visorchannel, typeid));
}
static ssize_t zoneguid_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct visor_device *vdev = to_visor_device(dev);
char zoneid[LINESIZE];
return sprintf(buf, "%s\n",
visorchannel_zoneid(vdev->visorchannel, zoneid));
}
static ssize_t typename_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
int i = 0;
struct bus_type *xbus = dev->bus;
struct device_driver *xdrv = dev->driver;
struct visor_driver *drv = NULL;
if (!xbus || !xdrv)
return 0;
i = xbus->match(dev, xdrv);
if (!i)
return 0;
drv = to_visor_driver(xdrv);
return sprintf(buf, "%s\n", drv->channel_types[i - 1].name);
}
static ssize_t partition_handle_show(struct device *dev,
struct device_attribute *attr,
char *buf) {
struct visor_device *vdev = to_visor_device(dev);
u64 handle = visorchannel_get_clientpartition(vdev->visorchannel);
return sprintf(buf, "0x%llx\n", handle);
}
static ssize_t partition_guid_show(struct device *dev,
struct device_attribute *attr,
char *buf) {
struct visor_device *vdev = to_visor_device(dev);
return sprintf(buf, "{%pUb}\n", &vdev->partition_uuid);
}
static ssize_t partition_name_show(struct device *dev,
struct device_attribute *attr,
char *buf) {
struct visor_device *vdev = to_visor_device(dev);
return sprintf(buf, "%s\n", vdev->name);
}
static ssize_t channel_addr_show(struct device *dev,
struct device_attribute *attr,
char *buf) {
struct visor_device *vdev = to_visor_device(dev);
u64 addr = visorchannel_get_physaddr(vdev->visorchannel);
return sprintf(buf, "0x%llx\n", addr);
}
static ssize_t channel_bytes_show(struct device *dev,
struct device_attribute *attr,
char *buf) {
struct visor_device *vdev = to_visor_device(dev);
u64 nbytes = visorchannel_get_nbytes(vdev->visorchannel);
return sprintf(buf, "0x%llx\n", nbytes);
}
static ssize_t channel_id_show(struct device *dev,
struct device_attribute *attr,
char *buf) {
struct visor_device *vdev = to_visor_device(dev);
int len = 0;
visorchannel_id(vdev->visorchannel, buf);
len = strlen(buf);
buf[len++] = '\n';
return len;
}
static void
vbuschannel_print_devinfo(struct ultra_vbus_deviceinfo *devinfo,
struct seq_file *seq, int devix)
{
if (!isprint(devinfo->devtype[0]))
return;
if (devix >= 0)
seq_printf(seq, "[%d]", devix);
else
seq_puts(seq, " ");
seq_printf(seq, "%-*.*s ", (int)sizeof(devinfo->devtype),
(int)sizeof(devinfo->devtype), devinfo->devtype);
seq_printf(seq, "%-*.*s ", (int)sizeof(devinfo->drvname),
(int)sizeof(devinfo->drvname), devinfo->drvname);
seq_printf(seq, "%.*s\n", (int)sizeof(devinfo->infostrs),
devinfo->infostrs);
}
static int client_bus_info_debugfs_show(struct seq_file *seq, void *v)
{
struct visor_device *vdev = seq->private;
struct visorchannel *channel = vdev->visorchannel;
int i;
unsigned long off;
struct ultra_vbus_deviceinfo dev_info;
if (!channel)
return 0;
seq_printf(seq,
"Client device / client driver info for %s partition (vbus #%u):\n",
((vdev->name) ? (char *)(vdev->name) : ""),
vdev->chipset_bus_no);
if (visorchannel_read(channel,
offsetof(struct spar_vbus_channel_protocol,
chp_info),
&dev_info, sizeof(dev_info)) >= 0)
vbuschannel_print_devinfo(&dev_info, seq, -1);
if (visorchannel_read(channel,
offsetof(struct spar_vbus_channel_protocol,
bus_info),
&dev_info, sizeof(dev_info)) >= 0)
vbuschannel_print_devinfo(&dev_info, seq, -1);
off = offsetof(struct spar_vbus_channel_protocol, dev_info);
i = 0;
while (off + sizeof(dev_info) <= visorchannel_get_nbytes(channel)) {
if (visorchannel_read(channel, off, &dev_info,
sizeof(dev_info)) >= 0)
vbuschannel_print_devinfo(&dev_info, seq, i);
off += sizeof(dev_info);
i++;
}
return 0;
}
static int client_bus_info_debugfs_open(struct inode *inode, struct file *file)
{
return single_open(file, client_bus_info_debugfs_show,
inode->i_private);
}
static void
dev_periodic_work(unsigned long __opaque)
{
struct visor_device *dev = (struct visor_device *)__opaque;
struct visor_driver *drv = to_visor_driver(dev->device.driver);
drv->channel_interrupt(dev);
mod_timer(&dev->timer, jiffies + POLLJIFFIES_NORMALCHANNEL);
}
static int
dev_start_periodic_work(struct visor_device *dev)
{
if (dev->being_removed || dev->timer_active)
return -EINVAL;
get_device(&dev->device);
dev->timer.expires = jiffies + POLLJIFFIES_NORMALCHANNEL;
add_timer(&dev->timer);
dev->timer_active = true;
return 0;
}
static void
dev_stop_periodic_work(struct visor_device *dev)
{
if (!dev->timer_active)
return;
del_timer_sync(&dev->timer);
dev->timer_active = false;
put_device(&dev->device);
}
static int
visordriver_remove_device(struct device *xdev)
{
struct visor_device *dev;
struct visor_driver *drv;
dev = to_visor_device(xdev);
drv = to_visor_driver(xdev->driver);
mutex_lock(&dev->visordriver_callback_lock);
dev->being_removed = true;
if (drv->remove)
drv->remove(dev);
mutex_unlock(&dev->visordriver_callback_lock);
dev_stop_periodic_work(dev);
put_device(&dev->device);
return 0;
}
void
visorbus_unregister_visor_driver(struct visor_driver *drv)
{
driver_unregister(&drv->driver);
}
int
visorbus_read_channel(struct visor_device *dev, unsigned long offset,
void *dest, unsigned long nbytes)
{
return visorchannel_read(dev->visorchannel, offset, dest, nbytes);
}
int
visorbus_write_channel(struct visor_device *dev, unsigned long offset,
void *src, unsigned long nbytes)
{
return visorchannel_write(dev->visorchannel, offset, src, nbytes);
}
int
visorbus_enable_channel_interrupts(struct visor_device *dev)
{
struct visor_driver *drv = to_visor_driver(dev->device.driver);
if (!drv->channel_interrupt) {
dev_err(&dev->device, "%s no interrupt function!\n", __func__);
return -ENOENT;
}
return dev_start_periodic_work(dev);
}
void
visorbus_disable_channel_interrupts(struct visor_device *dev)
{
dev_stop_periodic_work(dev);
}
static int
create_visor_device(struct visor_device *dev)
{
int err;
u32 chipset_bus_no = dev->chipset_bus_no;
u32 chipset_dev_no = dev->chipset_dev_no;
mutex_init(&dev->visordriver_callback_lock);
dev->device.bus = &visorbus_type;
dev->device.groups = visorbus_channel_groups;
device_initialize(&dev->device);
dev->device.release = visorbus_release_device;
get_device(&dev->device);
setup_timer(&dev->timer, dev_periodic_work, (unsigned long)dev);
err = dev_set_name(&dev->device, "vbus%u:dev%u",
chipset_bus_no, chipset_dev_no);
if (err)
goto err_put;
err = device_add(&dev->device);
if (err < 0)
goto err_put;
list_add_tail(&dev->list_all, &list_all_device_instances);
return 0;
err_put:
put_device(&dev->device);
dev_err(&dev->device, "Creating visor device failed. %d\n", err);
return err;
}
static void
remove_visor_device(struct visor_device *dev)
{
list_del(&dev->list_all);
put_device(&dev->device);
device_unregister(&dev->device);
}
static int
get_vbus_header_info(struct visorchannel *chan,
struct spar_vbus_headerinfo *hdr_info)
{
int err;
if (!spar_check_channel(visorchannel_get_header(chan),
spar_vbus_channel_protocol_uuid,
"vbus",
sizeof(struct spar_vbus_channel_protocol),
SPAR_VBUS_CHANNEL_PROTOCOL_VERSIONID,
SPAR_VBUS_CHANNEL_PROTOCOL_SIGNATURE))
return -EINVAL;
err = visorchannel_read(chan, sizeof(struct channel_header), hdr_info,
sizeof(*hdr_info));
if (err < 0)
return err;
if (hdr_info->struct_bytes < sizeof(struct spar_vbus_headerinfo))
return -EINVAL;
if (hdr_info->device_info_struct_bytes <
sizeof(struct ultra_vbus_deviceinfo))
return -EINVAL;
return 0;
}
static void
write_vbus_chp_info(struct visorchannel *chan,
struct spar_vbus_headerinfo *hdr_info,
struct ultra_vbus_deviceinfo *info)
{
int off = sizeof(struct channel_header) + hdr_info->chp_info_offset;
if (hdr_info->chp_info_offset == 0)
return;
visorchannel_write(chan, off, info, sizeof(*info));
}
static void
write_vbus_bus_info(struct visorchannel *chan,
struct spar_vbus_headerinfo *hdr_info,
struct ultra_vbus_deviceinfo *info)
{
int off = sizeof(struct channel_header) + hdr_info->bus_info_offset;
if (hdr_info->bus_info_offset == 0)
return;
visorchannel_write(chan, off, info, sizeof(*info));
}
static void
write_vbus_dev_info(struct visorchannel *chan,
struct spar_vbus_headerinfo *hdr_info,
struct ultra_vbus_deviceinfo *info, unsigned int devix)
{
int off =
(sizeof(struct channel_header) + hdr_info->dev_info_offset) +
(hdr_info->device_info_struct_bytes * devix);
if (hdr_info->dev_info_offset == 0)
return;
visorchannel_write(chan, off, info, sizeof(*info));
}
static void bus_device_info_init(
struct ultra_vbus_deviceinfo *bus_device_info_ptr,
const char *dev_type, const char *drv_name)
{
memset(bus_device_info_ptr, 0, sizeof(struct ultra_vbus_deviceinfo));
snprintf(bus_device_info_ptr->devtype,
sizeof(bus_device_info_ptr->devtype),
"%s", (dev_type) ? dev_type : "unknownType");
snprintf(bus_device_info_ptr->drvname,
sizeof(bus_device_info_ptr->drvname),
"%s", (drv_name) ? drv_name : "unknownDriver");
snprintf(bus_device_info_ptr->infostrs,
sizeof(bus_device_info_ptr->infostrs), "kernel ver. %s",
utsname()->release);
}
static void
fix_vbus_dev_info(struct visor_device *visordev)
{
int i;
struct visor_device *bdev;
struct visor_driver *visordrv;
u32 bus_no = visordev->chipset_bus_no;
u32 dev_no = visordev->chipset_dev_no;
struct ultra_vbus_deviceinfo dev_info;
const char *chan_type_name = NULL;
struct spar_vbus_headerinfo *hdr_info;
if (!visordev->device.driver)
return;
bdev = visorbus_get_device_by_id(bus_no, BUS_ROOT_DEVICE, NULL);
if (!bdev)
return;
hdr_info = (struct spar_vbus_headerinfo *)bdev->vbus_hdr_info;
if (!hdr_info)
return;
visordrv = to_visor_driver(visordev->device.driver);
for (i = 0; visordrv->channel_types[i].name; i++) {
if (memcmp(&visordrv->channel_types[i].guid,
&visordev->channel_type_guid,
sizeof(visordrv->channel_types[i].guid)) == 0) {
chan_type_name = visordrv->channel_types[i].name;
break;
}
}
bus_device_info_init(&dev_info, chan_type_name, visordrv->name);
write_vbus_dev_info(bdev->visorchannel, hdr_info, &dev_info, dev_no);
write_vbus_chp_info(bdev->visorchannel, hdr_info, &chipset_driverinfo);
write_vbus_bus_info(bdev->visorchannel, hdr_info,
&clientbus_driverinfo);
}
static int
visordriver_probe_device(struct device *xdev)
{
int res;
struct visor_driver *drv;
struct visor_device *dev;
drv = to_visor_driver(xdev->driver);
dev = to_visor_device(xdev);
if (!drv->probe)
return -ENODEV;
mutex_lock(&dev->visordriver_callback_lock);
dev->being_removed = false;
res = drv->probe(dev);
if (res >= 0) {
get_device(&dev->device);
fix_vbus_dev_info(dev);
}
mutex_unlock(&dev->visordriver_callback_lock);
return res;
}
int visorbus_register_visor_driver(struct visor_driver *drv)
{
if (!initialized)
return -ENODEV;
drv->driver.name = drv->name;
drv->driver.bus = &visorbus_type;
drv->driver.probe = visordriver_probe_device;
drv->driver.remove = visordriver_remove_device;
drv->driver.owner = drv->owner;
return driver_register(&drv->driver);
}
static int
create_bus_instance(struct visor_device *dev)
{
int id = dev->chipset_bus_no;
int err;
struct spar_vbus_headerinfo *hdr_info;
hdr_info = kzalloc(sizeof(*hdr_info), GFP_KERNEL);
if (!hdr_info)
return -ENOMEM;
dev_set_name(&dev->device, "visorbus%d", id);
dev->device.bus = &visorbus_type;
dev->device.groups = visorbus_groups;
dev->device.release = visorbus_release_busdevice;
dev->debugfs_dir = debugfs_create_dir(dev_name(&dev->device),
visorbus_debugfs_dir);
dev->debugfs_client_bus_info =
debugfs_create_file("client_bus_info", 0440,
dev->debugfs_dir, dev,
&client_bus_info_debugfs_fops);
dev_set_drvdata(&dev->device, dev);
err = get_vbus_header_info(dev->visorchannel, hdr_info);
if (err < 0)
goto err_debugfs_dir;
err = device_register(&dev->device);
if (err < 0)
goto err_debugfs_dir;
list_add_tail(&dev->list_all, &list_all_bus_instances);
dev->vbus_hdr_info = (void *)hdr_info;
write_vbus_chp_info(dev->visorchannel, hdr_info,
&chipset_driverinfo);
write_vbus_bus_info(dev->visorchannel, hdr_info,
&clientbus_driverinfo);
return 0;
err_debugfs_dir:
debugfs_remove_recursive(dev->debugfs_dir);
kfree(hdr_info);
dev_err(&dev->device, "create_bus_instance failed: %d\n", err);
return err;
}
static void
remove_bus_instance(struct visor_device *dev)
{
if (dev->visorchannel) {
visorchannel_destroy(dev->visorchannel);
dev->visorchannel = NULL;
}
kfree(dev->vbus_hdr_info);
list_del(&dev->list_all);
device_unregister(&dev->device);
}
static void
remove_all_visor_devices(void)
{
struct list_head *listentry, *listtmp;
list_for_each_safe(listentry, listtmp, &list_all_device_instances) {
struct visor_device *dev = list_entry(listentry,
struct visor_device,
list_all);
remove_visor_device(dev);
}
}
int
chipset_bus_create(struct visor_device *dev)
{
int err;
err = create_bus_instance(dev);
if (err < 0)
return err;
bus_create_response(dev, err);
return 0;
}
void
chipset_bus_destroy(struct visor_device *dev)
{
remove_bus_instance(dev);
bus_destroy_response(dev, 0);
}
int
chipset_device_create(struct visor_device *dev_info)
{
int err;
err = create_visor_device(dev_info);
if (err < 0)
return err;
device_create_response(dev_info, err);
return 0;
}
void
chipset_device_destroy(struct visor_device *dev_info)
{
remove_visor_device(dev_info);
device_destroy_response(dev_info, 0);
}
static void
pause_state_change_complete(struct visor_device *dev, int status)
{
if (!dev->pausing)
return;
dev->pausing = false;
device_pause_response(dev, status);
}
static void
resume_state_change_complete(struct visor_device *dev, int status)
{
if (!dev->resuming)
return;
dev->resuming = false;
device_resume_response(dev, status);
}
static int
initiate_chipset_device_pause_resume(struct visor_device *dev, bool is_pause)
{
int err;
struct visor_driver *drv = NULL;
drv = to_visor_driver(dev->device.driver);
if (!drv)
return -ENODEV;
if (dev->pausing || dev->resuming)
return -EBUSY;
if (is_pause) {
if (!drv->pause)
return -EINVAL;
dev->pausing = true;
err = drv->pause(dev, pause_state_change_complete);
} else {
fix_vbus_dev_info(dev);
if (!drv->resume)
return -EINVAL;
dev->resuming = true;
err = drv->resume(dev, resume_state_change_complete);
}
return err;
}
int
chipset_device_pause(struct visor_device *dev_info)
{
int err;
err = initiate_chipset_device_pause_resume(dev_info, true);
if (err < 0) {
dev_info->pausing = false;
return err;
}
return 0;
}
int
chipset_device_resume(struct visor_device *dev_info)
{
int err;
err = initiate_chipset_device_pause_resume(dev_info, false);
if (err < 0) {
dev_info->resuming = false;
return err;
}
return 0;
}
int
visorbus_init(void)
{
int err;
visorbus_debugfs_dir = debugfs_create_dir("visorbus", NULL);
if (!visorbus_debugfs_dir)
return -ENOMEM;
bus_device_info_init(&clientbus_driverinfo, "clientbus", "visorbus");
err = bus_register(&visorbus_type);
if (err < 0)
return err;
initialized = true;
bus_device_info_init(&chipset_driverinfo, "chipset", "visorchipset");
return 0;
}
void
visorbus_exit(void)
{
struct list_head *listentry, *listtmp;
remove_all_visor_devices();
list_for_each_safe(listentry, listtmp, &list_all_bus_instances) {
struct visor_device *dev = list_entry(listentry,
struct visor_device,
list_all);
remove_bus_instance(dev);
}
bus_unregister(&visorbus_type);
initialized = false;
debugfs_remove_recursive(visorbus_debugfs_dir);
}
