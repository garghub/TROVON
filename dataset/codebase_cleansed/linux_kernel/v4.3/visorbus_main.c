static ssize_t version_show(struct bus_type *bus, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", VERSION);
}
static ssize_t modalias_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct visor_device *vdev;
uuid_le guid;
vdev = to_visor_device(dev);
guid = visorchannel_get_uuid(vdev->visorchannel);
return snprintf(buf, PAGE_SIZE, "visorbus:%pUl\n", &guid);
}
static int
visorbus_uevent(struct device *xdev, struct kobj_uevent_env *env)
{
struct visor_device *dev;
uuid_le guid;
dev = to_visor_device(xdev);
guid = visorchannel_get_uuid(dev->visorchannel);
if (add_uevent_var(env, "MODALIAS=visorbus:%pUl", &guid))
return -ENOMEM;
return 0;
}
static int
visorbus_match(struct device *xdev, struct device_driver *xdrv)
{
uuid_le channel_type;
int rc = 0;
int i;
struct visor_device *dev;
struct visor_driver *drv;
dev = to_visor_device(xdev);
drv = to_visor_driver(xdrv);
channel_type = visorchannel_get_uuid(dev->visorchannel);
if (visorbus_forcematch) {
rc = 1;
goto away;
}
if (visorbus_forcenomatch)
goto away;
if (!drv->channel_types)
goto away;
for (i = 0;
(uuid_le_cmp(drv->channel_types[i].guid, NULL_UUID_LE) != 0) ||
(drv->channel_types[i].name);
i++)
if (uuid_le_cmp(drv->channel_types[i].guid,
channel_type) == 0) {
rc = i + 1;
goto away;
}
away:
return rc;
}
static void
visorbus_release_busdevice(struct device *xdev)
{
struct visor_device *dev = dev_get_drvdata(xdev);
dev_set_drvdata(xdev, NULL);
kfree(dev);
}
static void
visorbus_release_device(struct device *xdev)
{
struct visor_device *dev = to_visor_device(xdev);
if (dev->periodic_work) {
visor_periodic_work_destroy(dev->periodic_work);
dev->periodic_work = NULL;
}
if (dev->visorchannel) {
visorchannel_destroy(dev->visorchannel);
dev->visorchannel = NULL;
}
kfree(dev);
}
static ssize_t DEVMAJORMINOR_ATTR(struct visor_device *dev, int slot, char *buf)
{
int maxdevnodes = ARRAY_SIZE(dev->devnodes) / sizeof(dev->devnodes[0]);
if (slot < 0 || slot >= maxdevnodes)
return 0;
return snprintf(buf, PAGE_SIZE, "%d:%d\n",
dev->devnodes[slot].major, dev->devnodes[slot].minor);
}
static ssize_t
devmajorminor_attr_show(struct kobject *kobj, struct attribute *attr, char *buf)
{
struct devmajorminor_attribute *devmajorminor_attr =
to_devmajorminor_attr(attr);
struct visor_device *dev = to_visor_device_from_kobjdevmajorminor(kobj);
ssize_t ret = 0;
if (devmajorminor_attr->show)
ret = devmajorminor_attr->show(dev,
devmajorminor_attr->slot, buf);
return ret;
}
static ssize_t
devmajorminor_attr_store(struct kobject *kobj,
struct attribute *attr, const char *buf, size_t count)
{
struct devmajorminor_attribute *devmajorminor_attr =
to_devmajorminor_attr(attr);
struct visor_device *dev = to_visor_device_from_kobjdevmajorminor(kobj);
ssize_t ret = 0;
if (devmajorminor_attr->store)
ret = devmajorminor_attr->store(dev,
devmajorminor_attr->slot,
buf, count);
return ret;
}
static int
devmajorminor_create_file(struct visor_device *dev, const char *name,
int major, int minor)
{
int maxdevnodes = ARRAY_SIZE(dev->devnodes) / sizeof(dev->devnodes[0]);
struct devmajorminor_attribute *myattr = NULL;
int x = -1, rc = 0, slot = -1;
register_devmajorminor_attributes(dev);
for (slot = 0; slot < maxdevnodes; slot++)
if (!dev->devnodes[slot].attr)
break;
if (slot == maxdevnodes) {
rc = -ENOMEM;
goto away;
}
myattr = kzalloc(sizeof(*myattr), GFP_KERNEL);
if (!myattr) {
rc = -ENOMEM;
goto away;
}
myattr->show = DEVMAJORMINOR_ATTR;
myattr->store = NULL;
myattr->slot = slot;
myattr->attr.name = name;
myattr->attr.mode = S_IRUGO;
dev->devnodes[slot].attr = myattr;
dev->devnodes[slot].major = major;
dev->devnodes[slot].minor = minor;
x = sysfs_create_file(&dev->kobjdevmajorminor, &myattr->attr);
if (x < 0) {
rc = x;
goto away;
}
kobject_uevent(&dev->device.kobj, KOBJ_ONLINE);
away:
if (rc < 0) {
kfree(myattr);
myattr = NULL;
dev->devnodes[slot].attr = NULL;
}
return rc;
}
static void
devmajorminor_remove_file(struct visor_device *dev, int slot)
{
int maxdevnodes = ARRAY_SIZE(dev->devnodes) / sizeof(dev->devnodes[0]);
struct devmajorminor_attribute *myattr = NULL;
if (slot < 0 || slot >= maxdevnodes)
return;
myattr = (struct devmajorminor_attribute *)(dev->devnodes[slot].attr);
if (!myattr)
return;
sysfs_remove_file(&dev->kobjdevmajorminor, &myattr->attr);
kobject_uevent(&dev->device.kobj, KOBJ_OFFLINE);
dev->devnodes[slot].attr = NULL;
kfree(myattr);
}
static void
devmajorminor_remove_all_files(struct visor_device *dev)
{
int i = 0;
int maxdevnodes = ARRAY_SIZE(dev->devnodes) / sizeof(dev->devnodes[0]);
for (i = 0; i < maxdevnodes; i++)
devmajorminor_remove_file(dev, i);
}
static int
register_devmajorminor_attributes(struct visor_device *dev)
{
int rc = 0, x = 0;
if (dev->kobjdevmajorminor.parent)
goto away;
x = kobject_init_and_add(&dev->kobjdevmajorminor,
&devmajorminor_kobj_type, &dev->device.kobj,
"devmajorminor");
if (x < 0) {
rc = x;
goto away;
}
kobject_uevent(&dev->kobjdevmajorminor, KOBJ_ADD);
away:
return rc;
}
static void
unregister_devmajorminor_attributes(struct visor_device *dev)
{
if (!dev->kobjdevmajorminor.parent)
return;
devmajorminor_remove_all_files(dev);
kobject_del(&dev->kobjdevmajorminor);
kobject_put(&dev->kobjdevmajorminor);
dev->kobjdevmajorminor.parent = NULL;
}
static ssize_t physaddr_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct visor_device *vdev = to_visor_device(dev);
if (!vdev->visorchannel)
return 0;
return snprintf(buf, PAGE_SIZE, "0x%Lx\n",
visorchannel_get_physaddr(vdev->visorchannel));
}
static ssize_t nbytes_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct visor_device *vdev = to_visor_device(dev);
if (!vdev->visorchannel)
return 0;
return snprintf(buf, PAGE_SIZE, "0x%lx\n",
visorchannel_get_nbytes(vdev->visorchannel));
}
static ssize_t clientpartition_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct visor_device *vdev = to_visor_device(dev);
if (!vdev->visorchannel)
return 0;
return snprintf(buf, PAGE_SIZE, "0x%Lx\n",
visorchannel_get_clientpartition(vdev->visorchannel));
}
static ssize_t typeguid_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct visor_device *vdev = to_visor_device(dev);
char s[99];
if (!vdev->visorchannel)
return 0;
return snprintf(buf, PAGE_SIZE, "%s\n",
visorchannel_id(vdev->visorchannel, s));
}
static ssize_t zoneguid_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct visor_device *vdev = to_visor_device(dev);
char s[99];
if (!vdev->visorchannel)
return 0;
return snprintf(buf, PAGE_SIZE, "%s\n",
visorchannel_zoneid(vdev->visorchannel, s));
}
static ssize_t typename_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct visor_device *vdev = to_visor_device(dev);
int i = 0;
struct bus_type *xbus = dev->bus;
struct device_driver *xdrv = dev->driver;
struct visor_driver *drv = NULL;
if (!vdev->visorchannel || !xbus || !xdrv)
return 0;
i = xbus->match(dev, xdrv);
if (!i)
return 0;
drv = to_visor_driver(xdrv);
return snprintf(buf, PAGE_SIZE, "%s\n", drv->channel_types[i - 1].name);
}
static ssize_t partition_handle_show(struct device *dev,
struct device_attribute *attr,
char *buf) {
struct visor_device *vdev = to_visor_device(dev);
u64 handle = visorchannel_get_clientpartition(vdev->visorchannel);
return snprintf(buf, PAGE_SIZE, "0x%Lx\n", handle);
}
static ssize_t partition_guid_show(struct device *dev,
struct device_attribute *attr,
char *buf) {
struct visor_device *vdev = to_visor_device(dev);
return snprintf(buf, PAGE_SIZE, "{%pUb}\n", &vdev->partition_uuid);
}
static ssize_t partition_name_show(struct device *dev,
struct device_attribute *attr,
char *buf) {
struct visor_device *vdev = to_visor_device(dev);
return snprintf(buf, PAGE_SIZE, "%s\n", vdev->name);
}
static ssize_t channel_addr_show(struct device *dev,
struct device_attribute *attr,
char *buf) {
struct visor_device *vdev = to_visor_device(dev);
u64 addr = visorchannel_get_physaddr(vdev->visorchannel);
return snprintf(buf, PAGE_SIZE, "0x%Lx\n", addr);
}
static ssize_t channel_bytes_show(struct device *dev,
struct device_attribute *attr,
char *buf) {
struct visor_device *vdev = to_visor_device(dev);
u64 nbytes = visorchannel_get_nbytes(vdev->visorchannel);
return snprintf(buf, PAGE_SIZE, "0x%Lx\n", nbytes);
}
static ssize_t channel_id_show(struct device *dev,
struct device_attribute *attr,
char *buf) {
struct visor_device *vdev = to_visor_device(dev);
int len = 0;
if (vdev->visorchannel) {
visorchannel_id(vdev->visorchannel, buf);
len = strlen(buf);
buf[len++] = '\n';
}
return len;
}
static ssize_t client_bus_info_show(struct device *dev,
struct device_attribute *attr,
char *buf) {
struct visor_device *vdev = to_visor_device(dev);
struct visorchannel *channel = vdev->visorchannel;
int i, x, remain = PAGE_SIZE;
unsigned long off;
char *p = buf;
u8 *partition_name;
struct ultra_vbus_deviceinfo dev_info;
partition_name = "";
if (channel) {
if (vdev->name)
partition_name = vdev->name;
x = snprintf(p, remain,
"Client device / client driver info for %s partition (vbus #%d):\n",
partition_name, vdev->chipset_dev_no);
p += x;
remain -= x;
x = visorchannel_read(channel,
offsetof(struct
spar_vbus_channel_protocol,
chp_info),
&dev_info, sizeof(dev_info));
if (x >= 0) {
x = vbuschannel_devinfo_to_string(&dev_info, p,
remain, -1);
p += x;
remain -= x;
}
x = visorchannel_read(channel,
offsetof(struct
spar_vbus_channel_protocol,
bus_info),
&dev_info, sizeof(dev_info));
if (x >= 0) {
x = vbuschannel_devinfo_to_string(&dev_info, p,
remain, -1);
p += x;
remain -= x;
}
off = offsetof(struct spar_vbus_channel_protocol, dev_info);
i = 0;
while (off + sizeof(dev_info) <=
visorchannel_get_nbytes(channel)) {
x = visorchannel_read(channel,
off, &dev_info, sizeof(dev_info));
if (x >= 0) {
x = vbuschannel_devinfo_to_string
(&dev_info, p, remain, i);
p += x;
remain -= x;
}
off += sizeof(dev_info);
i++;
}
}
return PAGE_SIZE - remain;
}
static ssize_t
DRIVER_ATTR_version(struct device_driver *xdrv, char *buf)
{
struct visor_driver *drv = to_visor_driver(xdrv);
return snprintf(buf, PAGE_SIZE, "%s\n", drv->version);
}
static int
register_driver_attributes(struct visor_driver *drv)
{
int rc;
struct driver_attribute version =
__ATTR(version, S_IRUGO, DRIVER_ATTR_version, NULL);
drv->version_attr = version;
rc = driver_create_file(&drv->driver, &drv->version_attr);
return rc;
}
static void
unregister_driver_attributes(struct visor_driver *drv)
{
driver_remove_file(&drv->driver, &drv->version_attr);
}
static void
dev_periodic_work(void *xdev)
{
struct visor_device *dev = xdev;
struct visor_driver *drv = to_visor_driver(dev->device.driver);
down(&dev->visordriver_callback_lock);
if (drv->channel_interrupt)
drv->channel_interrupt(dev);
up(&dev->visordriver_callback_lock);
if (!visor_periodic_work_nextperiod(dev->periodic_work))
put_device(&dev->device);
}
static void
dev_start_periodic_work(struct visor_device *dev)
{
if (dev->being_removed)
return;
get_device(&dev->device);
if (!visor_periodic_work_start(dev->periodic_work))
put_device(&dev->device);
}
static void
dev_stop_periodic_work(struct visor_device *dev)
{
if (visor_periodic_work_stop(dev->periodic_work))
put_device(&dev->device);
}
static int
visordriver_probe_device(struct device *xdev)
{
int rc;
struct visor_driver *drv;
struct visor_device *dev;
drv = to_visor_driver(xdev->driver);
dev = to_visor_device(xdev);
down(&dev->visordriver_callback_lock);
dev->being_removed = false;
wmb();
get_device(&dev->device);
if (!drv->probe) {
up(&dev->visordriver_callback_lock);
rc = -1;
goto away;
}
rc = drv->probe(dev);
if (rc < 0)
goto away;
fix_vbus_dev_info(dev);
up(&dev->visordriver_callback_lock);
rc = 0;
away:
if (rc != 0)
put_device(&dev->device);
return rc;
}
static int
visordriver_remove_device(struct device *xdev)
{
struct visor_device *dev;
struct visor_driver *drv;
dev = to_visor_device(xdev);
drv = to_visor_driver(xdev->driver);
down(&dev->visordriver_callback_lock);
dev->being_removed = true;
wmb();
if (drv) {
if (drv->remove)
drv->remove(dev);
}
up(&dev->visordriver_callback_lock);
dev_stop_periodic_work(dev);
devmajorminor_remove_all_files(dev);
put_device(&dev->device);
return 0;
}
int visorbus_register_visor_driver(struct visor_driver *drv)
{
int rc = 0;
if (busreg_rc < 0)
return -ENODEV;
drv->driver.name = drv->name;
drv->driver.bus = &visorbus_type;
drv->driver.probe = visordriver_probe_device;
drv->driver.remove = visordriver_remove_device;
drv->driver.owner = drv->owner;
rc = driver_register(&drv->driver);
if (rc < 0)
return rc;
rc = register_driver_attributes(drv);
if (rc < 0)
driver_unregister(&drv->driver);
return rc;
}
void
visorbus_unregister_visor_driver(struct visor_driver *drv)
{
unregister_driver_attributes(drv);
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
visorbus_clear_channel(struct visor_device *dev, unsigned long offset, u8 ch,
unsigned long nbytes)
{
return visorchannel_clear(dev->visorchannel, offset, ch, nbytes);
}
int
visorbus_registerdevnode(struct visor_device *dev,
const char *name, int major, int minor)
{
return devmajorminor_create_file(dev, name, major, minor);
}
void
visorbus_enable_channel_interrupts(struct visor_device *dev)
{
dev_start_periodic_work(dev);
}
void
visorbus_disable_channel_interrupts(struct visor_device *dev)
{
dev_stop_periodic_work(dev);
}
static int
create_visor_device(struct visor_device *dev)
{
int rc = -1;
u32 chipset_bus_no = dev->chipset_bus_no;
u32 chipset_dev_no = dev->chipset_dev_no;
POSTCODE_LINUX_4(DEVICE_CREATE_ENTRY_PC, chipset_dev_no, chipset_bus_no,
POSTCODE_SEVERITY_INFO);
sema_init(&dev->visordriver_callback_lock, 1);
dev->device.bus = &visorbus_type;
dev->device.groups = visorbus_channel_groups;
device_initialize(&dev->device);
dev->device.release = visorbus_release_device;
get_device(&dev->device);
dev->periodic_work =
visor_periodic_work_create(POLLJIFFIES_NORMALCHANNEL,
periodic_dev_workqueue,
dev_periodic_work,
dev, dev_name(&dev->device));
if (!dev->periodic_work) {
POSTCODE_LINUX_3(DEVICE_CREATE_FAILURE_PC, chipset_dev_no,
DIAG_SEVERITY_ERR);
goto away;
}
dev_set_name(&dev->device, "vbus%u:dev%u",
chipset_bus_no, chipset_dev_no);
rc = device_add(&dev->device);
if (rc < 0) {
POSTCODE_LINUX_3(DEVICE_ADD_PC, chipset_bus_no,
DIAG_SEVERITY_ERR);
goto away;
}
rc = register_devmajorminor_attributes(dev);
if (rc < 0) {
POSTCODE_LINUX_3(DEVICE_REGISTER_FAILURE_PC, chipset_dev_no,
DIAG_SEVERITY_ERR);
goto away_register;
}
list_add_tail(&dev->list_all, &list_all_device_instances);
return 0;
away_register:
device_unregister(&dev->device);
away:
put_device(&dev->device);
return rc;
}
static void
remove_visor_device(struct visor_device *dev)
{
list_del(&dev->list_all);
unregister_devmajorminor_attributes(dev);
put_device(&dev->device);
device_unregister(&dev->device);
}
static int
get_vbus_header_info(struct visorchannel *chan,
struct spar_vbus_headerinfo *hdr_info)
{
int rc = -1;
if (!SPAR_VBUS_CHANNEL_OK_CLIENT(visorchannel_get_header(chan)))
goto away;
if (visorchannel_read(chan, sizeof(struct channel_header), hdr_info,
sizeof(*hdr_info)) < 0) {
goto away;
}
if (hdr_info->struct_bytes < sizeof(struct spar_vbus_headerinfo))
goto away;
if (hdr_info->device_info_struct_bytes <
sizeof(struct ultra_vbus_deviceinfo)) {
goto away;
}
rc = 0;
away:
return rc;
}
static int
write_vbus_chp_info(struct visorchannel *chan,
struct spar_vbus_headerinfo *hdr_info,
struct ultra_vbus_deviceinfo *info)
{
int off = sizeof(struct channel_header) + hdr_info->chp_info_offset;
if (hdr_info->chp_info_offset == 0)
return -1;
if (visorchannel_write(chan, off, info, sizeof(*info)) < 0)
return -1;
return 0;
}
static int
write_vbus_bus_info(struct visorchannel *chan,
struct spar_vbus_headerinfo *hdr_info,
struct ultra_vbus_deviceinfo *info)
{
int off = sizeof(struct channel_header) + hdr_info->bus_info_offset;
if (hdr_info->bus_info_offset == 0)
return -1;
if (visorchannel_write(chan, off, info, sizeof(*info)) < 0)
return -1;
return 0;
}
static int
write_vbus_dev_info(struct visorchannel *chan,
struct spar_vbus_headerinfo *hdr_info,
struct ultra_vbus_deviceinfo *info, int devix)
{
int off =
(sizeof(struct channel_header) + hdr_info->dev_info_offset) +
(hdr_info->device_info_struct_bytes * devix);
if (hdr_info->dev_info_offset == 0)
return -1;
if (visorchannel_write(chan, off, info, sizeof(*info)) < 0)
return -1;
return 0;
}
static void
fix_vbus_dev_info(struct visor_device *visordev)
{
int i;
struct visor_device *bdev;
struct visor_driver *visordrv;
int bus_no = visordev->chipset_bus_no;
int dev_no = visordev->chipset_dev_no;
struct ultra_vbus_deviceinfo dev_info;
const char *chan_type_name = NULL;
struct spar_vbus_headerinfo *hdr_info;
if (!visordev->device.driver)
return;
hdr_info = (struct spar_vbus_headerinfo *)visordev->vbus_hdr_info;
if (!hdr_info)
return;
bdev = visorbus_get_device_by_id(bus_no, BUS_ROOT_DEVICE, NULL);
if (!bdev)
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
bus_device_info_init(&dev_info, chan_type_name,
visordrv->name, visordrv->version,
visordrv->vertag);
write_vbus_dev_info(bdev->visorchannel, hdr_info, &dev_info, dev_no);
write_vbus_chp_info(bdev->visorchannel, hdr_info, &chipset_driverinfo);
write_vbus_bus_info(bdev->visorchannel, hdr_info,
&clientbus_driverinfo);
}
static int
create_bus_instance(struct visor_device *dev)
{
int rc;
int id = dev->chipset_bus_no;
struct spar_vbus_headerinfo *hdr_info;
POSTCODE_LINUX_2(BUS_CREATE_ENTRY_PC, POSTCODE_SEVERITY_INFO);
hdr_info = kzalloc(sizeof(*hdr_info), GFP_KERNEL);
if (!hdr_info) {
rc = -1;
goto away;
}
dev_set_name(&dev->device, "visorbus%d", id);
dev->device.bus = &visorbus_type;
dev->device.groups = visorbus_groups;
dev->device.release = visorbus_release_busdevice;
if (device_register(&dev->device) < 0) {
POSTCODE_LINUX_3(DEVICE_CREATE_FAILURE_PC, id,
POSTCODE_SEVERITY_ERR);
rc = -1;
goto away_mem;
}
if (get_vbus_header_info(dev->visorchannel, hdr_info) >= 0) {
dev->vbus_hdr_info = (void *)hdr_info;
write_vbus_chp_info(dev->visorchannel, hdr_info,
&chipset_driverinfo);
write_vbus_bus_info(dev->visorchannel, hdr_info,
&clientbus_driverinfo);
} else {
kfree(hdr_info);
}
bus_count++;
list_add_tail(&dev->list_all, &list_all_bus_instances);
dev_set_drvdata(&dev->device, dev);
return 0;
away_mem:
kfree(hdr_info);
away:
return rc;
}
static void
remove_bus_instance(struct visor_device *dev)
{
bus_count--;
if (dev->visorchannel) {
visorchannel_destroy(dev->visorchannel);
dev->visorchannel = NULL;
}
kfree(dev->vbus_hdr_info);
list_del(&dev->list_all);
device_unregister(&dev->device);
}
static int
create_bus_type(void)
{
busreg_rc = bus_register(&visorbus_type);
return busreg_rc;
}
static void
remove_bus_type(void)
{
bus_unregister(&visorbus_type);
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
static void
chipset_bus_create(struct visor_device *dev)
{
int rc;
u32 bus_no = dev->chipset_bus_no;
POSTCODE_LINUX_3(BUS_CREATE_ENTRY_PC, bus_no, POSTCODE_SEVERITY_INFO);
rc = create_bus_instance(dev);
POSTCODE_LINUX_3(BUS_CREATE_EXIT_PC, bus_no, POSTCODE_SEVERITY_INFO);
if (rc < 0)
POSTCODE_LINUX_3(BUS_CREATE_FAILURE_PC, bus_no,
POSTCODE_SEVERITY_ERR);
else
POSTCODE_LINUX_3(CHIPSET_INIT_SUCCESS_PC, bus_no,
POSTCODE_SEVERITY_INFO);
if (chipset_responders.bus_create)
(*chipset_responders.bus_create) (dev, rc);
}
static void
chipset_bus_destroy(struct visor_device *dev)
{
remove_bus_instance(dev);
if (chipset_responders.bus_destroy)
(*chipset_responders.bus_destroy)(dev, 0);
}
static void
chipset_device_create(struct visor_device *dev_info)
{
int rc = -1;
u32 bus_no = dev_info->chipset_bus_no;
u32 dev_no = dev_info->chipset_dev_no;
POSTCODE_LINUX_4(DEVICE_CREATE_ENTRY_PC, dev_no, bus_no,
POSTCODE_SEVERITY_INFO);
rc = create_visor_device(dev_info);
if (chipset_responders.device_create)
chipset_responders.device_create(dev_info, rc);
if (rc < 0)
POSTCODE_LINUX_4(DEVICE_CREATE_FAILURE_PC, dev_no, bus_no,
POSTCODE_SEVERITY_ERR);
else
POSTCODE_LINUX_4(DEVICE_CREATE_SUCCESS_PC, dev_no, bus_no,
POSTCODE_SEVERITY_INFO);
}
static void
chipset_device_destroy(struct visor_device *dev_info)
{
remove_visor_device(dev_info);
if (chipset_responders.device_destroy)
(*chipset_responders.device_destroy) (dev_info, 0);
}
static void
pause_state_change_complete(struct visor_device *dev, int status)
{
if (!dev->pausing)
return;
dev->pausing = false;
if (!chipset_responders.device_pause)
return;
(*chipset_responders.device_pause) (dev, status);
}
static void
resume_state_change_complete(struct visor_device *dev, int status)
{
if (!dev->resuming)
return;
dev->resuming = false;
if (!chipset_responders.device_resume)
return;
(*chipset_responders.device_resume) (dev, status);
}
static void
initiate_chipset_device_pause_resume(struct visor_device *dev, bool is_pause)
{
int rc = -1, x;
struct visor_driver *drv = NULL;
void (*notify_func)(struct visor_device *dev, int response) = NULL;
if (is_pause)
notify_func = chipset_responders.device_pause;
else
notify_func = chipset_responders.device_resume;
if (!notify_func)
goto away;
drv = to_visor_driver(dev->device.driver);
if (!drv)
goto away;
if (dev->pausing || dev->resuming)
goto away;
if (is_pause) {
if (!drv->pause)
goto away;
dev->pausing = true;
x = drv->pause(dev, pause_state_change_complete);
} else {
fix_vbus_dev_info(dev);
if (!drv->resume)
goto away;
dev->resuming = true;
x = drv->resume(dev, resume_state_change_complete);
}
if (x < 0) {
if (is_pause)
dev->pausing = false;
else
dev->resuming = false;
goto away;
}
rc = 0;
away:
if (rc < 0) {
if (notify_func)
(*notify_func)(dev, rc);
}
}
static void
chipset_device_pause(struct visor_device *dev_info)
{
initiate_chipset_device_pause_resume(dev_info, true);
}
static void
chipset_device_resume(struct visor_device *dev_info)
{
initiate_chipset_device_pause_resume(dev_info, false);
}
int
visorbus_init(void)
{
int rc = 0;
POSTCODE_LINUX_3(DRIVER_ENTRY_PC, rc, POSTCODE_SEVERITY_INFO);
bus_device_info_init(&clientbus_driverinfo,
"clientbus", "visorbus",
VERSION, NULL);
rc = create_bus_type();
if (rc < 0) {
POSTCODE_LINUX_2(BUS_CREATE_ENTRY_PC, DIAG_SEVERITY_ERR);
goto away;
}
periodic_dev_workqueue = create_singlethread_workqueue("visorbus_dev");
if (!periodic_dev_workqueue) {
POSTCODE_LINUX_2(CREATE_WORKQUEUE_PC, DIAG_SEVERITY_ERR);
rc = -ENOMEM;
goto away;
}
visorchipset_register_busdev(&chipset_notifiers,
&chipset_responders,
&chipset_driverinfo);
rc = 0;
away:
if (rc)
POSTCODE_LINUX_3(CHIPSET_INIT_FAILURE_PC, rc,
POSTCODE_SEVERITY_ERR);
return rc;
}
void
visorbus_exit(void)
{
struct list_head *listentry, *listtmp;
visorchipset_register_busdev(NULL, NULL, NULL);
remove_all_visor_devices();
flush_workqueue(periodic_dev_workqueue);
destroy_workqueue(periodic_dev_workqueue);
periodic_dev_workqueue = NULL;
if (periodic_test_workqueue) {
cancel_delayed_work(&periodic_work);
flush_workqueue(periodic_test_workqueue);
destroy_workqueue(periodic_test_workqueue);
periodic_test_workqueue = NULL;
}
list_for_each_safe(listentry, listtmp, &list_all_bus_instances) {
struct visor_device *dev = list_entry(listentry,
struct visor_device,
list_all);
remove_bus_instance(dev);
}
remove_bus_type();
}
