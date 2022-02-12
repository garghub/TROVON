static inline
int WAIT_FOR_IO_CHANNEL(ULTRA_IO_CHANNEL_PROTOCOL __iomem *chanptr)
{
int count = 120;
while (count > 0) {
if (ULTRA_CHANNEL_SERVER_READY(&chanptr->ChannelHeader))
return 1;
UIS_THREAD_WAIT_SEC(1);
count--;
}
return 0;
}
static int write_vbus_chpInfo(ULTRA_VBUS_CHANNEL_PROTOCOL *chan,
ULTRA_VBUS_DEVICEINFO *info)
{
int off;
if (!chan) {
LOGERR("vbus channel not present");
return -1;
}
off = sizeof(ULTRA_CHANNEL_PROTOCOL) + chan->HdrInfo.chpInfoByteOffset;
if (chan->HdrInfo.chpInfoByteOffset == 0) {
LOGERR("vbus channel not used, because chpInfoByteOffset == 0");
return -1;
}
memcpy(((u8 *) (chan)) + off, info, sizeof(*info));
return 0;
}
static int write_vbus_busInfo(ULTRA_VBUS_CHANNEL_PROTOCOL *chan,
ULTRA_VBUS_DEVICEINFO *info)
{
int off;
if (!chan) {
LOGERR("vbus channel not present");
return -1;
}
off = sizeof(ULTRA_CHANNEL_PROTOCOL) + chan->HdrInfo.busInfoByteOffset;
if (chan->HdrInfo.busInfoByteOffset == 0) {
LOGERR("vbus channel not used, because busInfoByteOffset == 0");
return -1;
}
memcpy(((u8 *) (chan)) + off, info, sizeof(*info));
return 0;
}
static int
write_vbus_devInfo(ULTRA_VBUS_CHANNEL_PROTOCOL *chan,
ULTRA_VBUS_DEVICEINFO *info, int devix)
{
int off;
if (!chan) {
LOGERR("vbus channel not present");
return -1;
}
off =
(sizeof(ULTRA_CHANNEL_PROTOCOL) +
chan->HdrInfo.devInfoByteOffset) +
(chan->HdrInfo.deviceInfoStructBytes * devix);
if (chan->HdrInfo.devInfoByteOffset == 0) {
LOGERR("vbus channel not used, because devInfoByteOffset == 0");
return -1;
}
memcpy(((u8 *) (chan)) + off, info, sizeof(*info));
return 0;
}
static int add_vbus(struct add_vbus_guestpart *addparams)
{
int ret;
struct device *vbus;
vbus = kzalloc(sizeof(struct device), GFP_ATOMIC);
POSTCODE_LINUX_2(VPCI_CREATE_ENTRY_PC, POSTCODE_SEVERITY_INFO);
if (!vbus)
return 0;
dev_set_name(vbus, "vbus%d", addparams->busNo);
vbus->release = virtpci_bus_release;
vbus->parent = &virtpci_rootbus_device;
vbus->bus = &virtpci_bus_type;
vbus->platform_data = (__force void *)addparams->chanptr;
ret = device_register(vbus);
if (ret) {
LOGERR("device_register FAILED:%d\n", ret);
POSTCODE_LINUX_2(VPCI_CREATE_FAILURE_PC, POSTCODE_SEVERITY_ERR);
return 0;
}
write_vbus_chpInfo(vbus->platform_data ,
&Chipset_DriverInfo);
write_vbus_busInfo(vbus->platform_data , &Bus_DriverInfo);
LOGINF("Added vbus %d; device %s created successfully\n",
addparams->busNo, BUS_ID(vbus));
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
((ULTRA_IO_CHANNEL_PROTOCOL __iomem *) addparams->chanptr)) {
LOGERR("Timed out. Channel not ready\n");
POSTCODE_LINUX_2(VPCI_CREATE_FAILURE_PC, POSTCODE_SEVERITY_ERR);
return 0;
}
GET_SCSIADAPINFO_FROM_CHANPTR(addparams->chanptr);
GET_BUS_DEV(addparams->bus_no);
LOGINF("Adding vhba wwnn:%x:%x config:%d-%d-%d-%d chanptr:%p\n",
scsi.wwnn.wwnn1, scsi.wwnn.wwnn2,
scsi.max.max_channel, scsi.max.max_id, scsi.max.max_lun,
scsi.max.cmd_per_lun, addparams->chanptr);
i = virtpci_device_add(vbus, VIRTHBA_TYPE, addparams, &scsi, NULL);
if (i) {
LOGINF("Added vhba wwnn:%x:%x chanptr:%p\n", scsi.wwnn.wwnn1,
scsi.wwnn.wwnn2, addparams->chanptr);
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
((ULTRA_IO_CHANNEL_PROTOCOL __iomem *) addparams->chanptr)) {
LOGERR("Timed out, channel not ready\n");
POSTCODE_LINUX_2(VPCI_CREATE_FAILURE_PC, POSTCODE_SEVERITY_ERR);
return 0;
}
GET_NETADAPINFO_FROM_CHANPTR(addparams->chanptr);
GET_BUS_DEV(addparams->bus_no);
LOGINF("Adding vnic macaddr:%02x:%02x:%02x:%02x:%02x:%02x rcvbufs:%d mtu:%d chanptr:%p%pUL\n",
net.mac_addr[0], net.mac_addr[1], net.mac_addr[2], net.mac_addr[3],
net.mac_addr[4], net.mac_addr[5], net.num_rcv_bufs, net.mtu,
addparams->chanptr, &net.zoneGuid);
i = virtpci_device_add(vbus, VIRTNIC_TYPE, addparams, NULL, &net);
if (i) {
LOGINF("Added vnic macaddr:%02x:%02x:%02x:%02x:%02x:%02x\n",
net.mac_addr[0], net.mac_addr[1], net.mac_addr[2],
net.mac_addr[3], net.mac_addr[4], net.mac_addr[5]);
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
GET_BUS_DEV(delparams->bus_no);
LOGINF("Deleting %s\n", BUS_ID(vbus));
if (delete_vbus_device(vbus, NULL))
return 0;
LOGINF("Deleted vbus %d\n", delparams->bus_no);
return 1;
}
static int
delete_vbus_device(struct device *vbus, void *data)
{
int checkforroot = (data != NULL);
struct device *pDev = &virtpci_rootbus_device;
if ((checkforroot) && match_busid(vbus, (void *) BUS_ID(pDev))) {
LOGINF("skipping root bus\n");
return 0;
}
LOGINF("Calling unregister for %s\n", BUS_ID(vbus));
device_unregister(vbus);
kfree(vbus);
LOGINF("VBus unregister and freed\n");
return 0;
}
static int pause_vhba(struct pause_virt_guestpart *pauseparams)
{
int i;
struct scsi_adap_info scsi;
GET_SCSIADAPINFO_FROM_CHANPTR(pauseparams->chanptr);
LOGINF("Pausing vhba wwnn:%x:%x\n", scsi.wwnn.wwnn1, scsi.wwnn.wwnn2);
i = virtpci_device_serverdown(NULL , VIRTHBA_TYPE,
&scsi.wwnn, NULL);
if (i)
LOGINF("Paused vhba wwnn:%x:%x\n", scsi.wwnn.wwnn1,
scsi.wwnn.wwnn2);
return i;
}
static int pause_vnic(struct pause_virt_guestpart *pauseparams)
{
int i;
struct net_adap_info net;
GET_NETADAPINFO_FROM_CHANPTR(pauseparams->chanptr);
LOGINF("Pausing vnic macaddr:%02x:%02x:%02x:%02x:%02x:%02x\n",
net.mac_addr[0], net.mac_addr[1], net.mac_addr[2],
net.mac_addr[3], net.mac_addr[4], net.mac_addr[5]);
i = virtpci_device_serverdown(NULL , VIRTNIC_TYPE,
NULL, net.mac_addr);
if (i) {
LOGINF(" Paused vnic macaddr:%02x:%02x:%02x:%02x:%02x:%02x\n",
net.mac_addr[0], net.mac_addr[1], net.mac_addr[2],
net.mac_addr[3], net.mac_addr[4], net.mac_addr[5]);
}
return i;
}
static int resume_vhba(struct resume_virt_guestpart *resumeparams)
{
int i;
struct scsi_adap_info scsi;
GET_SCSIADAPINFO_FROM_CHANPTR(resumeparams->chanptr);
LOGINF("Resuming vhba wwnn:%x:%x\n", scsi.wwnn.wwnn1, scsi.wwnn.wwnn2);
i = virtpci_device_serverup(NULL , VIRTHBA_TYPE,
&scsi.wwnn, NULL);
if (i)
LOGINF("Resumed vhba wwnn:%x:%x\n", scsi.wwnn.wwnn1,
scsi.wwnn.wwnn2);
return i;
}
static int
resume_vnic(struct resume_virt_guestpart *resumeparams)
{
int i;
struct net_adap_info net;
GET_NETADAPINFO_FROM_CHANPTR(resumeparams->chanptr);
LOGINF("Resuming vnic macaddr:%02x:%02x:%02x:%02x:%02x:%02x\n",
net.mac_addr[0], net.mac_addr[1], net.mac_addr[2],
net.mac_addr[3], net.mac_addr[4], net.mac_addr[5]);
i = virtpci_device_serverup(NULL , VIRTNIC_TYPE,
NULL, net.mac_addr);
if (i) {
LOGINF(" Resumed vnic macaddr:%02x:%02x:%02x:%02x:%02x:%02x\n",
net.mac_addr[0], net.mac_addr[1], net.mac_addr[2],
net.mac_addr[3], net.mac_addr[4], net.mac_addr[5]);
}
return i;
}
static int delete_vhba(struct del_virt_guestpart *delparams)
{
int i;
struct scsi_adap_info scsi;
GET_SCSIADAPINFO_FROM_CHANPTR(delparams->chanptr);
LOGINF("Deleting vhba wwnn:%x:%x\n", scsi.wwnn.wwnn1, scsi.wwnn.wwnn2);
i = virtpci_device_del(NULL , VIRTHBA_TYPE,
&scsi.wwnn, NULL);
if (i) {
LOGINF("Deleted vhba wwnn:%x:%x\n", scsi.wwnn.wwnn1,
scsi.wwnn.wwnn2);
return 1;
}
return 0;
}
static int delete_vnic(struct del_virt_guestpart *delparams)
{
int i;
struct net_adap_info net;
GET_NETADAPINFO_FROM_CHANPTR(delparams->chanptr);
LOGINF("Deleting vnic macaddr:%02x:%02x:%02x:%02x:%02x:%02x\n",
net.mac_addr[0], net.mac_addr[1], net.mac_addr[2],
net.mac_addr[3], net.mac_addr[4], net.mac_addr[5]);
i = virtpci_device_del(NULL , VIRTNIC_TYPE, NULL,
net.mac_addr);
if (i) {
LOGINF("Deleted vnic macaddr:%02x:%02x:%02x:%02x:%02x:%02x\n",
net.mac_addr[0], net.mac_addr[1], net.mac_addr[2],
net.mac_addr[3], net.mac_addr[4], net.mac_addr[5]);
}
return i;
}
static void delete_all(void)
{
int count = 0;
unsigned long flags;
struct virtpci_dev *tmpvpcidev, *nextvpcidev;
write_lock_irqsave(&VpcidevListLock, flags);
tmpvpcidev = VpcidevListHead;
VpcidevListHead = NULL;
write_unlock_irqrestore(&VpcidevListLock, flags);
while (tmpvpcidev) {
nextvpcidev = tmpvpcidev->next;
DELETE_ONE_VPCIDEV(tmpvpcidev);
tmpvpcidev = nextvpcidev;
count++;
}
LOGINF("Deleted %d vhbas/vnics.\n", count);
if (bus_for_each_dev
(&virtpci_bus_type, NULL, (void *) 1, delete_vbus_device))
LOGERR("delete of all vbus failed\n");
}
static int delete_all_virt(VIRTPCI_DEV_TYPE devtype, struct del_vbus_guestpart *delparams)
{
int i;
unsigned char busid[BUS_ID_SIZE];
struct device *vbus;
GET_BUS_DEV(delparams->bus_no);
if ((devtype != VIRTHBA_TYPE) && (devtype != VIRTNIC_TYPE)) {
LOGERR("**** FAILED to delete all devices; devtype:%d not vhba:%d or vnic:%d\n",
devtype, VIRTHBA_TYPE, VIRTNIC_TYPE);
return 0;
}
LOGINF("Deleting all %s in vbus %s\n",
devtype == VIRTHBA_TYPE ? "vhbas" : "vnics", busid);
i = virtpci_device_del(vbus, devtype, NULL, NULL);
if (i > 0)
LOGINF("Deleted %d %s\n", i,
devtype == VIRTHBA_TYPE ? "vhbas" : "vnics");
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
LOGERR("invalid message type %d.\n", msg->msgtype);
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
DBGINF("ids->vendor:%x dev->vendor:%x ids->device:%x dev->device:%x\n",
ids->vendor, dev->vendor, ids->device, dev->device);
if ((ids->vendor == dev->vendor)
&& (ids->device == dev->device))
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
DBGINF("In virtpci_bus_match dev->bus_id:%s drv->name:%s\n",
dev->bus_id, drv->name);
if (virtpci_match_device(virtpcidrv->id_table, virtpcidev))
match = 1;
DBGINF("returning match:%d\n", match);
return match;
}
static int virtpci_uevent(struct device *dev, struct kobj_uevent_env *env)
{
DBGINF("In virtpci_hotplug\n");
if (add_uevent_var(env, "VIRTPCI_VERSION=%s", VIRTPCI_VERSION))
return -ENOMEM;
return 0;
}
static int virtpci_device_suspend(struct device *dev, pm_message_t state)
{
DBGINF("In virtpci_device_suspend -NYI ****\n");
return 0;
}
static int virtpci_device_resume(struct device *dev)
{
DBGINF("In virtpci_device_resume -NYI ****\n");
return 0;
}
static void fix_vbus_devInfo(struct device *dev, int devNo, int devType,
struct virtpci_driver *virtpcidrv)
{
struct device *vbus;
void *pChan;
ULTRA_VBUS_DEVICEINFO devInfo;
const char *stype;
if (!dev) {
LOGERR("%s dev is NULL", __func__);
return;
}
if (!virtpcidrv) {
LOGERR("%s driver is NULL", __func__);
return;
}
vbus = dev->parent;
if (!vbus) {
LOGERR("%s dev has no parent bus", __func__);
return;
}
pChan = vbus->platform_data;
if (!pChan) {
LOGERR("%s dev bus has no channel", __func__);
return;
}
switch (devType) {
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
bus_device_info_init(&devInfo, stype,
virtpcidrv->name,
virtpcidrv->version,
virtpcidrv->vertag);
write_vbus_devInfo(pChan, &devInfo, devNo);
write_vbus_chpInfo(pChan, &Chipset_DriverInfo);
write_vbus_busInfo(pChan, &Bus_DriverInfo);
}
static int virtpci_device_probe(struct device *dev)
{
struct virtpci_dev *virtpcidev = device_to_virtpci_dev(dev);
struct virtpci_driver *virtpcidrv =
driver_to_virtpci_driver(dev->driver);
const struct pci_device_id *id;
int error = 0;
LOGINF("In virtpci_device_probe dev:%p virtpcidev:%p virtpcidrv:%p\n",
dev, virtpcidev, virtpcidrv);
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
fix_vbus_devInfo(dev, virtpcidev->deviceNo,
virtpcidev->device, virtpcidrv);
virtpcidev->mydriver = virtpcidrv;
POSTCODE_LINUX_2(VPCI_PROBE_EXIT_PC,
POSTCODE_SEVERITY_INFO);
} else
put_device(dev);
}
POSTCODE_LINUX_2(VPCI_PROBE_FAILURE_PC, POSTCODE_SEVERITY_ERR);
return error;
}
static int virtpci_device_remove(struct device *dev_)
{
struct virtpci_dev *virtpcidev = device_to_virtpci_dev(dev_);
struct virtpci_driver *virtpcidrv = virtpcidev->mydriver;
LOGINF("In virtpci_device_remove bus_id:%s dev_:%p virtpcidev:%p dev->driver:%p drivername:%s\n",
BUS_ID(dev_), dev_, virtpcidev, dev_->driver,
dev_->driver->name);
if (virtpcidrv) {
if (virtpcidrv->remove)
virtpcidrv->remove(virtpcidev);
virtpcidev->mydriver = NULL;
}
DBGINF("calling putdevice\n");
put_device(dev_);
DBGINF("Leaving\n");
return 0;
}
static void virtpci_bus_release(struct device *dev)
{
DBGINF("In virtpci_bus_release\n");
}
static int virtpci_device_add(struct device *parentbus, int devtype,
struct add_virt_guestpart *addparams,
struct scsi_adap_info *scsi,
struct net_adap_info *net )
{
struct virtpci_dev *virtpcidev = NULL;
struct virtpci_dev *tmpvpcidev = NULL, *prev;
unsigned long flags;
int ret;
ULTRA_IO_CHANNEL_PROTOCOL __iomem *pIoChan = NULL;
struct device *pDev;
LOGINF("virtpci_device_add parentbus:%p chanptr:%p\n", parentbus,
addparams->chanptr);
POSTCODE_LINUX_2(VPCI_CREATE_ENTRY_PC, POSTCODE_SEVERITY_INFO);
if ((devtype != VIRTHBA_TYPE) && (devtype != VIRTNIC_TYPE)) {
LOGERR("**** FAILED to add device; devtype:%d not vhba:%d or vnic:%d\n",
devtype, VIRTHBA_TYPE, VIRTNIC_TYPE);
POSTCODE_LINUX_3(VPCI_CREATE_FAILURE_PC, devtype,
POSTCODE_SEVERITY_ERR);
return 0;
}
virtpcidev = kzalloc(sizeof(struct virtpci_dev), GFP_ATOMIC);
if (virtpcidev == NULL) {
LOGERR("can't add device - malloc FALLED\n");
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
virtpcidev->busNo = addparams->bus_no;
virtpcidev->deviceNo = addparams->device_no;
virtpcidev->queueinfo.chan = addparams->chanptr;
virtpcidev->queueinfo.send_int_if_needed = NULL;
pIoChan = (ULTRA_IO_CHANNEL_PROTOCOL __iomem *)
virtpcidev->queueinfo.chan;
virtpcidev->intr = addparams->intr;
virtpcidev->generic_dev.bus = &virtpci_bus_type;
virtpcidev->generic_dev.parent = parentbus;
virtpcidev->generic_dev.release = virtpci_device_release;
dev_set_name(&virtpcidev->generic_dev, "%x:%x",
addparams->bus_no, addparams->device_no);
write_lock_irqsave(&VpcidevListLock, flags);
for (tmpvpcidev = VpcidevListHead; tmpvpcidev;
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
write_unlock_irqrestore(&VpcidevListLock, flags);
kfree(virtpcidev);
LOGERR("**** FAILED vhba/vnic already exists in the list\n");
POSTCODE_LINUX_2(VPCI_CREATE_FAILURE_PC, POSTCODE_SEVERITY_ERR);
return 0;
}
if (!VpcidevListHead)
VpcidevListHead = virtpcidev;
else {
virtpcidev->next = VpcidevListHead;
VpcidevListHead = virtpcidev;
}
write_unlock_irqrestore(&VpcidevListLock, flags);
pDev = &virtpcidev->generic_dev;
ULTRA_CHANNEL_CLIENT_TRANSITION(addparams->chanptr,
BUS_ID(pDev),
CHANNELCLI_ATTACHED, NULL);
DBGINF("registering device:%p with bus_id:%s\n",
&virtpcidev->generic_dev, virtpcidev->generic_dev.bus_id);
ret = device_register(&virtpcidev->generic_dev);
if (ret) {
LOGERR("device_register returned %d\n", ret);
pDev = &virtpcidev->generic_dev;
ULTRA_CHANNEL_CLIENT_TRANSITION(addparams->chanptr,
BUS_ID(pDev),
CHANNELCLI_DETACHED, NULL);
write_lock_irqsave(&VpcidevListLock, flags);
for (tmpvpcidev = VpcidevListHead, prev = NULL;
tmpvpcidev;
prev = tmpvpcidev, tmpvpcidev = tmpvpcidev->next) {
if (tmpvpcidev == virtpcidev) {
if (prev)
prev->next = tmpvpcidev->next;
else
VpcidevListHead = tmpvpcidev->next;
break;
}
}
write_unlock_irqrestore(&VpcidevListLock, flags);
kfree(virtpcidev);
return 0;
}
LOGINF("Added %s:%d:%d &virtpcidev->generic_dev:%p\n",
(devtype == VIRTHBA_TYPE) ? "virthba" : "virtnic",
addparams->bus_no, addparams->device_no,
&virtpcidev->generic_dev);
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
if ((devtype != VIRTHBA_TYPE) && (devtype != VIRTNIC_TYPE)) {
LOGERR("**** FAILED to pause device; devtype:%d not vhba:%d or vnic:%d\n",
devtype, VIRTHBA_TYPE, VIRTNIC_TYPE);
return 0;
}
write_lock_irqsave(&VpcidevListLock, flags);
for (tmpvpcidev = VpcidevListHead, prevvpcidev = NULL;
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
write_unlock_irqrestore(&VpcidevListLock, flags);
if (!found) {
LOGERR("**** FAILED to find vhba/vnic in the list\n");
return 0;
}
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
if ((devtype != VIRTHBA_TYPE) && (devtype != VIRTNIC_TYPE)) {
LOGERR("**** FAILED to resume device; devtype:%d not vhba:%d or vnic:%d\n",
devtype, VIRTHBA_TYPE, VIRTNIC_TYPE);
return 0;
}
write_lock_irqsave(&VpcidevListLock, flags);
for (tmpvpcidev = VpcidevListHead, prevvpcidev = NULL;
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
fix_vbus_devInfo(&tmpvpcidev->generic_dev, tmpvpcidev->deviceNo,
tmpvpcidev->device, vpcidriver);
rc = vpcidriver->resume(tmpvpcidev);
}
write_unlock_irqrestore(&VpcidevListLock, flags);
if (!found) {
LOGERR("**** FAILED to find vhba/vnic in the list\n");
return 0;
}
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
if ((devtype != VIRTHBA_TYPE) && (devtype != VIRTNIC_TYPE)) {
LOGERR("**** FAILED to delete device; devtype:%d not vhba:%d or vnic:%d\n",
devtype, VIRTHBA_TYPE, VIRTNIC_TYPE);
return 0;
}
all = ((devtype == VIRTHBA_TYPE) && (wwnn == NULL)) ||
((devtype == VIRTNIC_TYPE) && (macaddr == NULL));
write_lock_irqsave(&VpcidevListLock, flags);
for (tmpvpcidev = VpcidevListHead, prevvpcidev = NULL; tmpvpcidev;) {
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
VpcidevListHead = tmpvpcidev->next;
tmpvpcidev->next = dellist;
dellist = tmpvpcidev;
count++;
if (!all)
break;
if (prevvpcidev)
tmpvpcidev = prevvpcidev->next;
else
tmpvpcidev = VpcidevListHead;
}
write_unlock_irqrestore(&VpcidevListLock, flags);
if (!all && (count == 0)) {
LOGERR("**** FAILED to find vhba/vnic in the list\n");
return 0;
}
while (dellist) {
tmpvpcidev = dellist->next;
DELETE_ONE_VPCIDEV(dellist);
dellist = tmpvpcidev;
}
return count;
}
static void virtpci_device_release(struct device *dev_)
{
LOGINF("In virtpci_device_release:%p - NOT YET IMPLEMENTED\n", dev_);
}
static ssize_t virtpci_driver_attr_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
struct driver_attribute *dattr = attribute_to_driver_attribute(attr);
ssize_t ret = 0;
struct driver_private *dprivate = to_driver(kobj);
struct device_driver *driver;
if (dprivate != NULL)
driver = dprivate->driver;
else
driver = NULL;
DBGINF("In virtpci_driver_attr_show driver->name:%s\n", driver->name);
if (driver) {
if (dattr->show)
ret = dattr->show(driver, buf);
}
return ret;
}
static ssize_t virtpci_driver_attr_store(struct kobject *kobj,
struct attribute *attr,
const char *buf, size_t count)
{
struct driver_attribute *dattr = attribute_to_driver_attribute(attr);
ssize_t ret = 0;
struct driver_private *dprivate = to_driver(kobj);
struct device_driver *driver;
if (dprivate != NULL)
driver = dprivate->driver;
else
driver = NULL;
DBGINF("In virtpci_driver_attr_store driver->name:%s\n", driver->name);
if (driver) {
if (dattr->store)
ret = dattr->store(driver, buf, count);
}
return ret;
}
int virtpci_register_driver(struct virtpci_driver *drv)
{
int result = 0;
DBGINF("In virtpci_register_driver\n");
if (drv->id_table == NULL) {
LOGERR("id_table missing\n");
return 1;
}
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
DBGINF("In virtpci_unregister_driver drv:%p\n", drv);
driver_unregister(&drv->core_driver);
DBGINF("Leaving\n");
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
if (bus_for_each_dev(&virtpci_bus_type, NULL,
(void *) &printparam, print_vbus))
LOGERR("Failed to find bus\n");
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
"\n Virtual PCI devices\n");
read_lock_irqsave(&VpcidevListLock, flags);
tmpvpcidev = VpcidevListHead;
while (tmpvpcidev) {
if (tmpvpcidev->devtype == VIRTHBA_TYPE) {
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
"[%d:%d] VHba:%08x:%08x max-config:%d-%d-%d-%d",
tmpvpcidev->busNo, tmpvpcidev->deviceNo,
tmpvpcidev->scsi.wwnn.wwnn1,
tmpvpcidev->scsi.wwnn.wwnn2,
tmpvpcidev->scsi.max.max_channel,
tmpvpcidev->scsi.max.max_id,
tmpvpcidev->scsi.max.max_lun,
tmpvpcidev->scsi.max.cmd_per_lun);
} else {
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
"[%d:%d] VNic:%02x:%02x:%02x:%02x:%02x:%02x num_rcv_bufs:%d mtu:%d",
tmpvpcidev->busNo, tmpvpcidev->deviceNo,
tmpvpcidev->net.mac_addr[0],
tmpvpcidev->net.mac_addr[1],
tmpvpcidev->net.mac_addr[2],
tmpvpcidev->net.mac_addr[3],
tmpvpcidev->net.mac_addr[4],
tmpvpcidev->net.mac_addr[5],
tmpvpcidev->net.num_rcv_bufs,
tmpvpcidev->net.mtu);
}
str_pos += scnprintf(vbuf + str_pos,
len - str_pos, " chanptr:%p\n",
tmpvpcidev->queueinfo.chan);
tmpvpcidev = tmpvpcidev->next;
}
read_unlock_irqrestore(&VpcidevListLock, flags);
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
LOGERR("bus_register ****FAILED:%d\n", ret);
POSTCODE_LINUX_3(VPCI_CREATE_FAILURE_PC, ret,
POSTCODE_SEVERITY_ERR);
return ret;
}
DBGINF("bus_register successful\n");
bus_device_info_init(&Bus_DriverInfo, "clientbus", "virtpci",
VERSION, NULL);
ret = device_register(&virtpci_rootbus_device);
if (ret) {
LOGERR("device_register FAILED:%d\n", ret);
bus_unregister(&virtpci_bus_type);
POSTCODE_LINUX_3(VPCI_CREATE_FAILURE_PC, ret,
POSTCODE_SEVERITY_ERR);
return ret;
}
DBGINF("device_register successful ret:%x\n", ret);
if (!uisctrl_register_req_handler(2, (void *) &virtpci_ctrlchan_func,
&Chipset_DriverInfo)) {
LOGERR("uisctrl_register_req_handler ****FAILED.\n");
POSTCODE_LINUX_2(VPCI_CREATE_FAILURE_PC, POSTCODE_SEVERITY_ERR);
device_unregister(&virtpci_rootbus_device);
bus_unregister(&virtpci_bus_type);
return -1;
}
LOGINF("successfully registered virtpci_ctrlchan_func (0x%p) as callback.\n",
(void *) &virtpci_ctrlchan_func);
virtpci_debugfs_dir = debugfs_create_dir("virtpci", NULL);
debugfs_create_file("info", S_IRUSR, virtpci_debugfs_dir,
NULL, &debugfs_info_fops);
LOGINF("Leaving\n");
POSTCODE_LINUX_2(VPCI_CREATE_EXIT_PC, POSTCODE_SEVERITY_INFO);
return 0;
}
static void __exit virtpci_mod_exit(void)
{
LOGINF("virtpci_mod_exit...\n");
if (!uisctrl_register_req_handler(2, NULL, NULL))
LOGERR("uisctrl_register_req_handler ****FAILED.\n");
device_unregister(&virtpci_rootbus_device);
bus_unregister(&virtpci_bus_type);
debugfs_remove_recursive(virtpci_debugfs_dir);
LOGINF("Leaving\n");
}
