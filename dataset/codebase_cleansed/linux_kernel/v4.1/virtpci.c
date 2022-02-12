static inline
int WAIT_FOR_IO_CHANNEL(struct spar_io_channel_protocol __iomem *chanptr)
{
int count = 120;
while (count > 0) {
if (SPAR_CHANNEL_SERVER_READY(&chanptr->channel_header))
return 1;
UIS_THREAD_WAIT_SEC(1);
count--;
}
return 0;
}
static int write_vbus_chp_info(struct spar_vbus_channel_protocol *chan,
struct ultra_vbus_deviceinfo *info)
{
int off;
if (!chan)
return -1;
off = sizeof(struct channel_header) + chan->hdr_info.chp_info_offset;
if (chan->hdr_info.chp_info_offset == 0) {
return -1;
}
memcpy(((u8 *)(chan)) + off, info, sizeof(*info));
return 0;
}
static int write_vbus_bus_info(struct spar_vbus_channel_protocol *chan,
struct ultra_vbus_deviceinfo *info)
{
int off;
if (!chan)
return -1;
off = sizeof(struct channel_header) + chan->hdr_info.bus_info_offset;
if (chan->hdr_info.bus_info_offset == 0)
return -1;
memcpy(((u8 *)(chan)) + off, info, sizeof(*info));
return 0;
}
static int
write_vbus_dev_info(struct spar_vbus_channel_protocol *chan,
struct ultra_vbus_deviceinfo *info, int devix)
{
int off;
if (!chan)
return -1;
off =
(sizeof(struct channel_header) +
chan->hdr_info.dev_info_offset) +
(chan->hdr_info.device_info_struct_bytes * devix);
if (chan->hdr_info.dev_info_offset == 0)
return -1;
memcpy(((u8 *)(chan)) + off, info, sizeof(*info));
return 0;
}
static int add_vbus(struct add_vbus_guestpart *addparams)
{
int ret;
struct device *vbus;
vbus = kzalloc(sizeof(*vbus), GFP_ATOMIC);
POSTCODE_LINUX_2(VPCI_CREATE_ENTRY_PC, POSTCODE_SEVERITY_INFO);
if (!vbus)
return 0;
dev_set_name(vbus, "vbus%d", addparams->bus_no);
vbus->release = virtpci_bus_release;
vbus->parent = &virtpci_rootbus_device;
vbus->bus = &virtpci_bus_type;
vbus->platform_data = (__force void *)addparams->chanptr;
ret = device_register(vbus);
if (ret) {
POSTCODE_LINUX_2(VPCI_CREATE_FAILURE_PC, POSTCODE_SEVERITY_ERR);
return 0;
}
write_vbus_chp_info(vbus->platform_data ,
&chipset_driver_info);
write_vbus_bus_info(vbus->platform_data ,
&bus_driver_info);
POSTCODE_LINUX_2(VPCI_CREATE_EXIT_PC, POSTCODE_SEVERITY_INFO);
return 1;
}
static int add_vhba(struct add_virt_guestpart *addparams)
{
int i;
struct scsi_adap_info scsi;
struct device *vbus;
unsigned char busid[BUS_ID_SIZE];
POSTCODE_LINUX_2(VPCI_CREATE_ENTRY_PC, POSTCODE_SEVERITY_INFO);
if (!WAIT_FOR_IO_CHANNEL
((struct spar_io_channel_protocol __iomem *)addparams->chanptr)) {
POSTCODE_LINUX_2(VPCI_CREATE_FAILURE_PC, POSTCODE_SEVERITY_ERR);
return 0;
}
GET_SCSIADAPINFO_FROM_CHANPTR(addparams->chanptr);
sprintf(busid, "vbus%d", addparams->bus_no);
vbus = bus_find_device(&virtpci_bus_type, NULL,
(void *)busid, match_busid);
if (!vbus)
return 0;
i = virtpci_device_add(vbus, VIRTHBA_TYPE, addparams, &scsi, NULL);
if (i) {
POSTCODE_LINUX_3(VPCI_CREATE_EXIT_PC, i,
POSTCODE_SEVERITY_INFO);
}
return i;
}
static int
add_vnic(struct add_virt_guestpart *addparams)
{
int i;
struct net_adap_info net;
struct device *vbus;
unsigned char busid[BUS_ID_SIZE];
POSTCODE_LINUX_2(VPCI_CREATE_ENTRY_PC, POSTCODE_SEVERITY_INFO);
if (!WAIT_FOR_IO_CHANNEL
((struct spar_io_channel_protocol __iomem *)addparams->chanptr)) {
POSTCODE_LINUX_2(VPCI_CREATE_FAILURE_PC, POSTCODE_SEVERITY_ERR);
return 0;
}
GET_NETADAPINFO_FROM_CHANPTR(addparams->chanptr);
sprintf(busid, "vbus%d", addparams->bus_no);
vbus = bus_find_device(&virtpci_bus_type, NULL,
(void *)busid, match_busid);
if (!vbus)
return 0;
i = virtpci_device_add(vbus, VIRTNIC_TYPE, addparams, NULL, &net);
if (i) {
POSTCODE_LINUX_3(VPCI_CREATE_EXIT_PC, i,
POSTCODE_SEVERITY_INFO);
return 1;
}
return 0;
}
static int
delete_vbus(struct del_vbus_guestpart *delparams)
{
struct device *vbus;
unsigned char busid[BUS_ID_SIZE];
sprintf(busid, "vbus%d", delparams->bus_no);
vbus = bus_find_device(&virtpci_bus_type, NULL,
(void *)busid, match_busid);
if (!vbus)
return 0;
return 1;
}
static int
delete_vbus_device(struct device *vbus, void *data)
{
struct device *dev = &virtpci_rootbus_device;
if ((data) && match_busid(vbus, (void *)BUS_ID(dev))) {
return 0;
}
device_unregister(vbus);
kfree(vbus);
return 0;
}
static int pause_vhba(struct pause_virt_guestpart *pauseparams)
{
int i;
struct scsi_adap_info scsi;
GET_SCSIADAPINFO_FROM_CHANPTR(pauseparams->chanptr);
i = virtpci_device_serverdown(NULL , VIRTHBA_TYPE,
&scsi.wwnn, NULL);
return i;
}
static int pause_vnic(struct pause_virt_guestpart *pauseparams)
{
int i;
struct net_adap_info net;
GET_NETADAPINFO_FROM_CHANPTR(pauseparams->chanptr);
i = virtpci_device_serverdown(NULL , VIRTNIC_TYPE,
NULL, net.mac_addr);
return i;
}
static int resume_vhba(struct resume_virt_guestpart *resumeparams)
{
int i;
struct scsi_adap_info scsi;
GET_SCSIADAPINFO_FROM_CHANPTR(resumeparams->chanptr);
i = virtpci_device_serverup(NULL , VIRTHBA_TYPE,
&scsi.wwnn, NULL);
return i;
}
static int
resume_vnic(struct resume_virt_guestpart *resumeparams)
{
int i;
struct net_adap_info net;
GET_NETADAPINFO_FROM_CHANPTR(resumeparams->chanptr);
i = virtpci_device_serverup(NULL , VIRTNIC_TYPE,
NULL, net.mac_addr);
return i;
}
static int delete_vhba(struct del_virt_guestpart *delparams)
{
int i;
struct scsi_adap_info scsi;
GET_SCSIADAPINFO_FROM_CHANPTR(delparams->chanptr);
i = virtpci_device_del(NULL , VIRTHBA_TYPE,
&scsi.wwnn, NULL);
if (i) {
return 1;
}
return 0;
}
static int delete_vnic(struct del_virt_guestpart *delparams)
{
int i;
struct net_adap_info net;
GET_NETADAPINFO_FROM_CHANPTR(delparams->chanptr);
i = virtpci_device_del(NULL , VIRTNIC_TYPE, NULL,
net.mac_addr);
return i;
}
static void delete_all(void)
{
int count = 0;
unsigned long flags;
struct virtpci_dev *tmpvpcidev, *nextvpcidev;
write_lock_irqsave(&vpcidev_list_lock, flags);
tmpvpcidev = vpcidev_list_head;
vpcidev_list_head = NULL;
write_unlock_irqrestore(&vpcidev_list_lock, flags);
while (tmpvpcidev) {
nextvpcidev = tmpvpcidev->next;
DELETE_ONE_VPCIDEV(tmpvpcidev);
tmpvpcidev = nextvpcidev;
count++;
}
bus_for_each_dev(&virtpci_bus_type, NULL, (void *)1,
delete_vbus_device);
}
static int delete_all_virt(enum virtpci_dev_type devtype,
struct del_vbus_guestpart *delparams)
{
int i;
unsigned char busid[BUS_ID_SIZE];
struct device *vbus;
sprintf(busid, "vbus%d", delparams->bus_no);
vbus = bus_find_device(&virtpci_bus_type, NULL,
(void *)busid, match_busid);
if (!vbus)
return 0;
if ((devtype != VIRTHBA_TYPE) && (devtype != VIRTNIC_TYPE))
return 0;
i = virtpci_device_del(vbus, devtype, NULL, NULL);
return 1;
}
static int virtpci_ctrlchan_func(struct guest_msgs *msg)
{
switch (msg->msgtype) {
case GUEST_ADD_VBUS:
return add_vbus(&msg->add_vbus);
case GUEST_ADD_VHBA:
return add_vhba(&msg->add_vhba);
case GUEST_ADD_VNIC:
return add_vnic(&msg->add_vnic);
case GUEST_DEL_VBUS:
return delete_vbus(&msg->del_vbus);
case GUEST_DEL_VHBA:
return delete_vhba(&msg->del_vhba);
case GUEST_DEL_VNIC:
return delete_vnic(&msg->del_vhba);
case GUEST_DEL_ALL_VHBAS:
return delete_all_virt(VIRTHBA_TYPE, &msg->del_all_vhbas);
case GUEST_DEL_ALL_VNICS:
return delete_all_virt(VIRTNIC_TYPE, &msg->del_all_vnics);
case GUEST_DEL_ALL_VBUSES:
delete_all();
return 1;
case GUEST_PAUSE_VHBA:
return pause_vhba(&msg->pause_vhba);
case GUEST_PAUSE_VNIC:
return pause_vnic(&msg->pause_vnic);
case GUEST_RESUME_VHBA:
return resume_vhba(&msg->resume_vhba);
case GUEST_RESUME_VNIC:
return resume_vnic(&msg->resume_vnic);
default:
return 0;
}
}
static int match_busid(struct device *dev, void *data)
{
const char *name = data;
if (strcmp(name, BUS_ID(dev)) == 0)
return 1;
return 0;
}
static const struct pci_device_id *
virtpci_match_device(const struct pci_device_id *ids,
const struct virtpci_dev *dev)
{
while (ids->vendor || ids->subvendor || ids->class_mask) {
if ((ids->vendor == dev->vendor) &&
(ids->device == dev->device))
return ids;
ids++;
}
return NULL;
}
static int virtpci_bus_match(struct device *dev, struct device_driver *drv)
{
struct virtpci_dev *virtpcidev = device_to_virtpci_dev(dev);
struct virtpci_driver *virtpcidrv = driver_to_virtpci_driver(drv);
int match = 0;
if (virtpci_match_device(virtpcidrv->id_table, virtpcidev))
match = 1;
return match;
}
static int virtpci_uevent(struct device *dev, struct kobj_uevent_env *env)
{
if (add_uevent_var(env, "VIRTPCI_VERSION=%s", VIRTPCI_VERSION))
return -ENOMEM;
return 0;
}
static void fix_vbus_dev_info(struct device *dev, int dev_no, int dev_type,
struct virtpci_driver *virtpcidrv)
{
struct device *vbus;
void *chan;
struct ultra_vbus_deviceinfo dev_info;
const char *stype;
if (!dev)
return;
if (!virtpcidrv)
return;
vbus = dev->parent;
if (!vbus)
return;
chan = vbus->platform_data;
if (!chan)
return;
switch (dev_type) {
case PCI_DEVICE_ID_VIRTHBA:
stype = "vHBA";
break;
case PCI_DEVICE_ID_VIRTNIC:
stype = "vNIC";
break;
default:
stype = "unknown";
break;
}
bus_device_info_init(&dev_info, stype,
virtpcidrv->name,
virtpcidrv->version,
virtpcidrv->vertag);
write_vbus_dev_info(chan, &dev_info, dev_no);
write_vbus_chp_info(chan, &chipset_driver_info);
write_vbus_bus_info(chan, &bus_driver_info);
}
static int virtpci_device_probe(struct device *dev)
{
struct virtpci_dev *virtpcidev = device_to_virtpci_dev(dev);
struct virtpci_driver *virtpcidrv =
driver_to_virtpci_driver(dev->driver);
const struct pci_device_id *id;
int error = 0;
POSTCODE_LINUX_2(VPCI_PROBE_ENTRY_PC, POSTCODE_SEVERITY_INFO);
if (!virtpcidrv->id_table)
return -ENODEV;
id = virtpci_match_device(virtpcidrv->id_table, virtpcidev);
if (!id)
return -ENODEV;
get_device(dev);
if (!virtpcidev->mydriver && virtpcidrv->probe) {
error = virtpcidrv->probe(virtpcidev, id);
if (!error) {
fix_vbus_dev_info(dev, virtpcidev->device_no,
virtpcidev->device, virtpcidrv);
virtpcidev->mydriver = virtpcidrv;
POSTCODE_LINUX_2(VPCI_PROBE_EXIT_PC,
POSTCODE_SEVERITY_INFO);
} else {
put_device(dev);
}
}
POSTCODE_LINUX_2(VPCI_PROBE_FAILURE_PC, POSTCODE_SEVERITY_ERR);
return error;
}
static int virtpci_device_remove(struct device *dev_)
{
struct virtpci_dev *virtpcidev = device_to_virtpci_dev(dev_);
struct virtpci_driver *virtpcidrv = virtpcidev->mydriver;
if (virtpcidrv) {
if (virtpcidrv->remove)
virtpcidrv->remove(virtpcidev);
virtpcidev->mydriver = NULL;
}
put_device(dev_);
return 0;
}
static void virtpci_bus_release(struct device *dev)
{
}
static int virtpci_device_add(struct device *parentbus, int devtype,
struct add_virt_guestpart *addparams,
struct scsi_adap_info *scsi,
struct net_adap_info *net)
{
struct virtpci_dev *virtpcidev = NULL;
struct virtpci_dev *tmpvpcidev = NULL, *prev;
unsigned long flags;
int ret;
struct spar_io_channel_protocol __iomem *io_chan = NULL;
struct device *dev;
POSTCODE_LINUX_2(VPCI_CREATE_ENTRY_PC, POSTCODE_SEVERITY_INFO);
if ((devtype != VIRTHBA_TYPE) && (devtype != VIRTNIC_TYPE)) {
POSTCODE_LINUX_3(VPCI_CREATE_FAILURE_PC, devtype,
POSTCODE_SEVERITY_ERR);
return 0;
}
virtpcidev = kzalloc(sizeof(*virtpcidev), GFP_ATOMIC);
if (!virtpcidev) {
POSTCODE_LINUX_2(MALLOC_FAILURE_PC, POSTCODE_SEVERITY_ERR);
return 0;
}
virtpcidev->devtype = devtype;
if (devtype == VIRTHBA_TYPE) {
virtpcidev->device = PCI_DEVICE_ID_VIRTHBA;
virtpcidev->scsi = *scsi;
} else {
virtpcidev->device = PCI_DEVICE_ID_VIRTNIC;
virtpcidev->net = *net;
}
virtpcidev->vendor = PCI_VENDOR_ID_UNISYS;
virtpcidev->bus_no = addparams->bus_no;
virtpcidev->device_no = addparams->device_no;
virtpcidev->queueinfo.chan = addparams->chanptr;
virtpcidev->queueinfo.send_int_if_needed = NULL;
io_chan = (struct spar_io_channel_protocol __iomem *)
virtpcidev->queueinfo.chan;
virtpcidev->intr = addparams->intr;
virtpcidev->generic_dev.bus = &virtpci_bus_type;
virtpcidev->generic_dev.parent = parentbus;
virtpcidev->generic_dev.release = virtpci_device_release;
dev_set_name(&virtpcidev->generic_dev, "%x:%x",
addparams->bus_no, addparams->device_no);
write_lock_irqsave(&vpcidev_list_lock, flags);
for (tmpvpcidev = vpcidev_list_head; tmpvpcidev;
tmpvpcidev = tmpvpcidev->next) {
if (devtype == VIRTHBA_TYPE) {
if ((tmpvpcidev->scsi.wwnn.wwnn1 == scsi->wwnn.wwnn1) &&
(tmpvpcidev->scsi.wwnn.wwnn2 == scsi->wwnn.wwnn2)) {
break;
}
} else
if (memcmp
(tmpvpcidev->net.mac_addr, net->mac_addr,
MAX_MACADDR_LEN) == 0) {
break;
}
}
if (tmpvpcidev) {
write_unlock_irqrestore(&vpcidev_list_lock, flags);
kfree(virtpcidev);
POSTCODE_LINUX_2(VPCI_CREATE_FAILURE_PC, POSTCODE_SEVERITY_ERR);
return 0;
}
if (!vpcidev_list_head) {
vpcidev_list_head = virtpcidev;
} else {
virtpcidev->next = vpcidev_list_head;
vpcidev_list_head = virtpcidev;
}
write_unlock_irqrestore(&vpcidev_list_lock, flags);
dev = &virtpcidev->generic_dev;
SPAR_CHANNEL_CLIENT_TRANSITION(addparams->chanptr,
BUS_ID(dev),
CHANNELCLI_ATTACHED, NULL);
ret = device_register(&virtpcidev->generic_dev);
if (ret) {
dev = &virtpcidev->generic_dev;
SPAR_CHANNEL_CLIENT_TRANSITION(addparams->chanptr,
BUS_ID(dev),
CHANNELCLI_DETACHED, NULL);
write_lock_irqsave(&vpcidev_list_lock, flags);
for (tmpvpcidev = vpcidev_list_head, prev = NULL;
tmpvpcidev;
prev = tmpvpcidev, tmpvpcidev = tmpvpcidev->next) {
if (tmpvpcidev == virtpcidev) {
if (prev)
prev->next = tmpvpcidev->next;
else
vpcidev_list_head = tmpvpcidev->next;
break;
}
}
write_unlock_irqrestore(&vpcidev_list_lock, flags);
kfree(virtpcidev);
return 0;
}
POSTCODE_LINUX_2(VPCI_CREATE_EXIT_PC, POSTCODE_SEVERITY_INFO);
return 1;
}
static int virtpci_device_serverdown(struct device *parentbus,
int devtype,
struct vhba_wwnn *wwnn,
unsigned char macaddr[])
{
int pausethisone = 0;
bool found = false;
struct virtpci_dev *tmpvpcidev, *prevvpcidev;
struct virtpci_driver *vpcidriver;
unsigned long flags;
int rc = 0;
if ((devtype != VIRTHBA_TYPE) && (devtype != VIRTNIC_TYPE))
return 0;
write_lock_irqsave(&vpcidev_list_lock, flags);
for (tmpvpcidev = vpcidev_list_head, prevvpcidev = NULL;
(tmpvpcidev && !found);
prevvpcidev = tmpvpcidev, tmpvpcidev = tmpvpcidev->next) {
if (tmpvpcidev->devtype != devtype)
continue;
if (devtype == VIRTHBA_TYPE) {
pausethisone =
((tmpvpcidev->scsi.wwnn.wwnn1 == wwnn->wwnn1) &&
(tmpvpcidev->scsi.wwnn.wwnn2 == wwnn->wwnn2));
} else {
pausethisone =
memcmp(tmpvpcidev->net.mac_addr, macaddr,
MAX_MACADDR_LEN) == 0;
}
if (!pausethisone)
continue;
found = true;
vpcidriver = tmpvpcidev->mydriver;
rc = vpcidriver->suspend(tmpvpcidev, 0);
}
write_unlock_irqrestore(&vpcidev_list_lock, flags);
if (!found)
return 0;
return rc;
}
static int virtpci_device_serverup(struct device *parentbus,
int devtype,
struct vhba_wwnn *wwnn,
unsigned char macaddr[])
{
int resumethisone = 0;
bool found = false;
struct virtpci_dev *tmpvpcidev, *prevvpcidev;
struct virtpci_driver *vpcidriver;
unsigned long flags;
int rc = 0;
if ((devtype != VIRTHBA_TYPE) && (devtype != VIRTNIC_TYPE))
return 0;
write_lock_irqsave(&vpcidev_list_lock, flags);
for (tmpvpcidev = vpcidev_list_head, prevvpcidev = NULL;
(tmpvpcidev && !found);
prevvpcidev = tmpvpcidev, tmpvpcidev = tmpvpcidev->next) {
if (tmpvpcidev->devtype != devtype)
continue;
if (devtype == VIRTHBA_TYPE) {
resumethisone =
((tmpvpcidev->scsi.wwnn.wwnn1 == wwnn->wwnn1) &&
(tmpvpcidev->scsi.wwnn.wwnn2 == wwnn->wwnn2));
} else {
resumethisone =
memcmp(tmpvpcidev->net.mac_addr, macaddr,
MAX_MACADDR_LEN) == 0;
}
if (!resumethisone)
continue;
found = true;
vpcidriver = tmpvpcidev->mydriver;
fix_vbus_dev_info(&tmpvpcidev->generic_dev,
tmpvpcidev->device_no,
tmpvpcidev->device, vpcidriver);
rc = vpcidriver->resume(tmpvpcidev);
}
write_unlock_irqrestore(&vpcidev_list_lock, flags);
if (!found)
return 0;
return rc;
}
static int virtpci_device_del(struct device *parentbus,
int devtype, struct vhba_wwnn *wwnn,
unsigned char macaddr[])
{
int count = 0, all = 0, delthisone;
struct virtpci_dev *tmpvpcidev, *prevvpcidev, *dellist = NULL;
unsigned long flags;
#define DEL_CONTINUE { \
prevvpcidev = tmpvpcidev;\
tmpvpcidev = tmpvpcidev->next;\
continue; \
}
if ((devtype != VIRTHBA_TYPE) && (devtype != VIRTNIC_TYPE))
return 0;
all = ((devtype == VIRTHBA_TYPE) && (!wwnn)) ||
((devtype == VIRTNIC_TYPE) && (!macaddr));
write_lock_irqsave(&vpcidev_list_lock, flags);
for (tmpvpcidev = vpcidev_list_head, prevvpcidev = NULL; tmpvpcidev;) {
if (tmpvpcidev->devtype != devtype)
DEL_CONTINUE;
if (all) {
delthisone =
(tmpvpcidev->generic_dev.parent == parentbus);
} else if (devtype == VIRTHBA_TYPE) {
delthisone =
((tmpvpcidev->scsi.wwnn.wwnn1 == wwnn->wwnn1) &&
(tmpvpcidev->scsi.wwnn.wwnn2 == wwnn->wwnn2));
} else {
delthisone =
memcmp(tmpvpcidev->net.mac_addr, macaddr,
MAX_MACADDR_LEN) == 0;
}
if (!delthisone)
DEL_CONTINUE;
if (prevvpcidev)
prevvpcidev->next = tmpvpcidev->next;
else
vpcidev_list_head = tmpvpcidev->next;
tmpvpcidev->next = dellist;
dellist = tmpvpcidev;
count++;
if (!all)
break;
if (prevvpcidev)
tmpvpcidev = prevvpcidev->next;
else
tmpvpcidev = vpcidev_list_head;
}
write_unlock_irqrestore(&vpcidev_list_lock, flags);
if (!all && (count == 0))
return 0;
while (dellist) {
tmpvpcidev = dellist->next;
DELETE_ONE_VPCIDEV(dellist);
dellist = tmpvpcidev;
}
return count;
}
static void virtpci_device_release(struct device *dev_)
{
}
static ssize_t virtpci_driver_attr_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
struct driver_attribute *dattr = attribute_to_driver_attribute(attr);
ssize_t ret = 0;
struct driver_private *dprivate = to_driver(kobj);
struct device_driver *driver = dprivate->driver;
if (dattr->show)
ret = dattr->show(driver, buf);
return ret;
}
static ssize_t virtpci_driver_attr_store(struct kobject *kobj,
struct attribute *attr,
const char *buf, size_t count)
{
struct driver_attribute *dattr = attribute_to_driver_attribute(attr);
ssize_t ret = 0;
struct driver_private *dprivate = to_driver(kobj);
struct device_driver *driver = dprivate->driver;
if (dattr->store)
ret = dattr->store(driver, buf, count);
return ret;
}
int virtpci_register_driver(struct virtpci_driver *drv)
{
int result = 0;
if (!drv->id_table)
return 1;
drv->core_driver.name = drv->name;
drv->core_driver.bus = &virtpci_bus_type;
drv->core_driver.probe = virtpci_device_probe;
drv->core_driver.remove = virtpci_device_remove;
result = driver_register(&drv->core_driver);
if (result)
return result;
drv->core_driver.p->kobj.ktype = &virtpci_driver_kobj_type;
return 0;
}
void virtpci_unregister_driver(struct virtpci_driver *drv)
{
driver_unregister(&drv->core_driver);
}
static int print_vbus(struct device *vbus, void *data)
{
struct print_vbus_info *p = (struct print_vbus_info *)data;
*p->str_pos += scnprintf(p->buf + *p->str_pos, *p->len - *p->str_pos,
"bus_id:%s\n", dev_name(vbus));
return 0;
}
static ssize_t info_debugfs_read(struct file *file, char __user *buf,
size_t len, loff_t *offset)
{
ssize_t bytes_read = 0;
int str_pos = 0;
struct virtpci_dev *tmpvpcidev;
unsigned long flags;
struct print_vbus_info printparam;
char *vbuf;
if (len > MAX_BUF)
len = MAX_BUF;
vbuf = kzalloc(len, GFP_KERNEL);
if (!vbuf)
return -ENOMEM;
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" Virtual PCI Bus devices\n");
printparam.str_pos = &str_pos;
printparam.buf = vbuf;
printparam.len = &len;
bus_for_each_dev(&virtpci_bus_type, NULL, (void *)&printparam,
print_vbus);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
"\n Virtual PCI devices\n");
read_lock_irqsave(&vpcidev_list_lock, flags);
tmpvpcidev = vpcidev_list_head;
while (tmpvpcidev) {
if (tmpvpcidev->devtype == VIRTHBA_TYPE) {
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
"[%d:%d] VHba:%08x:%08x max-config:%d-%d-%d-%d",
tmpvpcidev->bus_no,
tmpvpcidev->device_no,
tmpvpcidev->scsi.wwnn.wwnn1,
tmpvpcidev->scsi.wwnn.wwnn2,
tmpvpcidev->scsi.max.max_channel,
tmpvpcidev->scsi.max.max_id,
tmpvpcidev->scsi.max.max_lun,
tmpvpcidev->scsi.max.cmd_per_lun);
} else {
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
"[%d:%d] VNic:%pM num_rcv_bufs:%d mtu:%d",
tmpvpcidev->bus_no,
tmpvpcidev->device_no,
tmpvpcidev->net.mac_addr,
tmpvpcidev->net.num_rcv_bufs,
tmpvpcidev->net.mtu);
}
str_pos += scnprintf(vbuf + str_pos,
len - str_pos, " chanptr:%p\n",
tmpvpcidev->queueinfo.chan);
tmpvpcidev = tmpvpcidev->next;
}
read_unlock_irqrestore(&vpcidev_list_lock, flags);
str_pos += scnprintf(vbuf + str_pos, len - str_pos, "\n");
bytes_read = simple_read_from_buffer(buf, len, offset, vbuf, str_pos);
kfree(vbuf);
return bytes_read;
}
static int __init virtpci_mod_init(void)
{
int ret;
if (!unisys_spar_platform)
return -ENODEV;
POSTCODE_LINUX_2(VPCI_CREATE_ENTRY_PC, POSTCODE_SEVERITY_INFO);
ret = bus_register(&virtpci_bus_type);
if (ret) {
POSTCODE_LINUX_3(VPCI_CREATE_FAILURE_PC, ret,
POSTCODE_SEVERITY_ERR);
return ret;
}
bus_device_info_init(&bus_driver_info, "clientbus", "virtpci",
VERSION, NULL);
ret = device_register(&virtpci_rootbus_device);
if (ret) {
bus_unregister(&virtpci_bus_type);
POSTCODE_LINUX_3(VPCI_CREATE_FAILURE_PC, ret,
POSTCODE_SEVERITY_ERR);
return ret;
}
if (!uisctrl_register_req_handler(2, (void *)&virtpci_ctrlchan_func,
&chipset_driver_info)) {
POSTCODE_LINUX_2(VPCI_CREATE_FAILURE_PC, POSTCODE_SEVERITY_ERR);
device_unregister(&virtpci_rootbus_device);
bus_unregister(&virtpci_bus_type);
return -1;
}
virtpci_debugfs_dir = debugfs_create_dir("virtpci", NULL);
debugfs_create_file("info", S_IRUSR, virtpci_debugfs_dir,
NULL, &debugfs_info_fops);
POSTCODE_LINUX_2(VPCI_CREATE_EXIT_PC, POSTCODE_SEVERITY_INFO);
return 0;
}
static void __exit virtpci_mod_exit(void)
{
device_unregister(&virtpci_rootbus_device);
bus_unregister(&virtpci_bus_type);
debugfs_remove_recursive(virtpci_debugfs_dir);
}
