static int
proc_info_vbus_open(struct inode *inode, struct file *filp)
{
struct bus_info *bus = PDE_DATA(inode);
return single_open(filp, proc_info_vbus_show, bus);
}
static void
init_msg_header(CONTROLVM_MESSAGE *msg, U32 id, uint rsp, uint svr)
{
memset(msg, 0, sizeof(CONTROLVM_MESSAGE));
msg->hdr.Id = id;
msg->hdr.Flags.responseExpected = rsp;
msg->hdr.Flags.server = svr;
}
static void
create_bus_proc_entries(struct bus_info *bus)
{
bus->proc_dir = proc_mkdir(bus->name, uislib_proc_vbus_dir);
if (!bus->proc_dir) {
LOGERR("failed to create /proc/uislib/vbus/%s directory",
bus->name);
return;
}
bus->proc_info = proc_create_data("info", 0, bus->proc_dir,
&proc_info_vbus_fops, bus);
if (!bus->proc_info) {
LOGERR("failed to create /proc/uislib/vbus/%s/info", bus->name);
remove_proc_entry(bus->name, uislib_proc_vbus_dir);
bus->proc_dir = NULL;
return;
}
SET_PROC_OWNER(bus->proc_info, THIS_MODULE);
}
static __iomem void *
init_vbus_channel(U64 channelAddr, U32 channelBytes, int isServer)
{
void *rc = NULL;
void __iomem *pChan = uislib_ioremap_cache(channelAddr, channelBytes);
if (!pChan) {
LOGERR("CONTROLVM_BUS_CREATE error: ioremap_cache of channelAddr:%Lx for channelBytes:%llu failed",
(unsigned long long) channelAddr,
(unsigned long long) channelBytes);
rc = NULL;
goto Away;
}
if (isServer) {
memset_io(pChan, 0, channelBytes);
if (!ULTRA_VBUS_CHANNEL_OK_SERVER(channelBytes, NULL)) {
ERRDRV("%s channel cannot be used", __func__);
uislib_iounmap(pChan);
rc = NULL;
goto Away;
}
ULTRA_VBUS_init_channel(pChan, channelBytes);
} else {
if (!ULTRA_VBUS_CHANNEL_OK_CLIENT(pChan, NULL)) {
ERRDRV("%s channel cannot be used", __func__);
uislib_iounmap(pChan);
rc = NULL;
goto Away;
}
}
rc = pChan;
Away:
return rc;
}
static int
create_bus(CONTROLVM_MESSAGE *msg, char *buf)
{
U32 busNo, deviceCount;
struct bus_info *tmp, *bus;
size_t size;
if (MaxBusCount == BusListCount) {
LOGERR("CONTROLVM_BUS_CREATE Failed: max buses:%d already created\n",
MaxBusCount);
POSTCODE_LINUX_3(BUS_CREATE_FAILURE_PC, MaxBusCount,
POSTCODE_SEVERITY_ERR);
return CONTROLVM_RESP_ERROR_MAX_BUSES;
}
busNo = msg->cmd.createBus.busNo;
deviceCount = msg->cmd.createBus.deviceCount;
POSTCODE_LINUX_4(BUS_CREATE_ENTRY_PC, busNo, deviceCount,
POSTCODE_SEVERITY_INFO);
size =
sizeof(struct bus_info) +
(deviceCount * sizeof(struct device_info *));
bus = kzalloc(size, GFP_ATOMIC);
if (!bus) {
LOGERR("CONTROLVM_BUS_CREATE Failed: kmalloc for bus failed.\n");
POSTCODE_LINUX_3(BUS_CREATE_FAILURE_PC, busNo,
POSTCODE_SEVERITY_ERR);
return CONTROLVM_RESP_ERROR_KMALLOC_FAILED;
}
if (msg->hdr.Flags.testMessage) {
bus->guestHandle = 0;
bus->busNo = busNo;
bus->localVnic = 1;
} else
bus->busNo = bus->guestHandle = busNo;
sprintf(bus->name, "%d", (int) bus->busNo);
bus->deviceCount = deviceCount;
bus->device =
(struct device_info **) ((char *) bus + sizeof(struct bus_info));
bus->busInstGuid = msg->cmd.createBus.busInstGuid;
bus->busChannelBytes = 0;
bus->pBusChannel = NULL;
read_lock(&BusListLock);
for (tmp = BusListHead; tmp; tmp = tmp->next) {
if (tmp->busNo == bus->busNo)
break;
}
read_unlock(&BusListLock);
if (tmp) {
LOGERR("CONTROLVM_BUS_CREATE Failed: bus %d already exists.\n",
bus->busNo);
POSTCODE_LINUX_3(BUS_CREATE_FAILURE_PC, bus->busNo,
POSTCODE_SEVERITY_ERR);
kfree(bus);
return CONTROLVM_RESP_ERROR_ALREADY_DONE;
}
if ((msg->cmd.createBus.channelAddr != 0)
&& (msg->cmd.createBus.channelBytes != 0)) {
bus->busChannelBytes = msg->cmd.createBus.channelBytes;
bus->pBusChannel =
init_vbus_channel(msg->cmd.createBus.channelAddr,
msg->cmd.createBus.channelBytes,
msg->hdr.Flags.server);
}
if (!msg->hdr.Flags.server) {
struct guest_msgs cmd;
cmd.msgtype = GUEST_ADD_VBUS;
cmd.add_vbus.busNo = busNo;
cmd.add_vbus.chanptr = bus->pBusChannel;
cmd.add_vbus.deviceCount = deviceCount;
cmd.add_vbus.busTypeGuid = msg->cmd.createBus.busDataTypeGuid;
cmd.add_vbus.busInstGuid = msg->cmd.createBus.busInstGuid;
if (!VirtControlChanFunc) {
LOGERR("CONTROLVM_BUS_CREATE Failed: virtpci callback not registered.");
POSTCODE_LINUX_3(BUS_CREATE_FAILURE_PC, bus->busNo,
POSTCODE_SEVERITY_ERR);
kfree(bus);
return CONTROLVM_RESP_ERROR_VIRTPCI_DRIVER_FAILURE;
}
if (!VirtControlChanFunc(&cmd)) {
LOGERR("CONTROLVM_BUS_CREATE Failed: virtpci GUEST_ADD_VBUS returned error.");
POSTCODE_LINUX_3(BUS_CREATE_FAILURE_PC, bus->busNo,
POSTCODE_SEVERITY_ERR);
kfree(bus);
return
CONTROLVM_RESP_ERROR_VIRTPCI_DRIVER_CALLBACK_ERROR;
}
}
create_bus_proc_entries(bus);
write_lock(&BusListLock);
if (!BusListHead)
BusListHead = bus;
else {
bus->next = BusListHead;
BusListHead = bus;
}
BusListCount++;
write_unlock(&BusListLock);
POSTCODE_LINUX_3(BUS_CREATE_EXIT_PC, bus->busNo,
POSTCODE_SEVERITY_INFO);
return CONTROLVM_RESP_SUCCESS;
}
static int
destroy_bus(CONTROLVM_MESSAGE *msg, char *buf)
{
int i;
struct bus_info *bus, *prev = NULL;
U32 busNo;
busNo = msg->cmd.destroyBus.busNo;
read_lock(&BusListLock);
for (bus = BusListHead; bus; prev = bus, bus = bus->next) {
if (bus->busNo == busNo) {
for (i = 0; i < bus->deviceCount; i++) {
if (bus->device[i] != NULL) {
LOGERR("CONTROLVM_BUS_DESTROY Failed: device %i attached to bus %d.",
i, busNo);
read_unlock(&BusListLock);
return CONTROLVM_RESP_ERROR_BUS_DEVICE_ATTACHED;
}
}
read_unlock(&BusListLock);
if (!msg->hdr.Flags.server) {
struct guest_msgs cmd;
cmd.msgtype = GUEST_DEL_VBUS;
cmd.del_vbus.busNo = busNo;
if (!VirtControlChanFunc) {
LOGERR("CONTROLVM_BUS_DESTROY Failed: virtpci callback not registered.");
return CONTROLVM_RESP_ERROR_VIRTPCI_DRIVER_FAILURE;
}
if (!VirtControlChanFunc(&cmd)) {
LOGERR("CONTROLVM_BUS_DESTROY Failed: virtpci GUEST_DEL_VBUS returned error.");
return CONTROLVM_RESP_ERROR_VIRTPCI_DRIVER_CALLBACK_ERROR;
}
}
write_lock(&BusListLock);
if (prev)
prev->next = bus->next;
else
BusListHead = bus->next;
BusListCount--;
write_unlock(&BusListLock);
break;
}
}
if (!bus) {
LOGERR("CONTROLVM_BUS_DESTROY Failed: failed to find bus %d.\n",
busNo);
read_unlock(&BusListLock);
return CONTROLVM_RESP_ERROR_ALREADY_DONE;
}
if (bus->proc_info) {
remove_proc_entry("info", bus->proc_dir);
bus->proc_info = NULL;
}
if (bus->proc_dir) {
remove_proc_entry(bus->name, uislib_proc_vbus_dir);
bus->proc_dir = NULL;
}
if (bus->pBusChannel) {
uislib_iounmap(bus->pBusChannel);
bus->pBusChannel = NULL;
}
kfree(bus);
return CONTROLVM_RESP_SUCCESS;
}
static int
create_device(CONTROLVM_MESSAGE *msg, char *buf)
{
struct device_info *dev;
struct bus_info *bus;
U32 busNo, devNo;
int result = CONTROLVM_RESP_SUCCESS;
U64 minSize = MIN_IO_CHANNEL_SIZE;
ReqHandlerInfo_t *pReqHandler;
busNo = msg->cmd.createDevice.busNo;
devNo = msg->cmd.createDevice.devNo;
POSTCODE_LINUX_4(DEVICE_CREATE_ENTRY_PC, devNo, busNo,
POSTCODE_SEVERITY_INFO);
dev = kzalloc(sizeof(struct device_info), GFP_ATOMIC);
if (!dev) {
LOGERR("CONTROLVM_DEVICE_CREATE Failed: kmalloc for dev failed.\n");
POSTCODE_LINUX_4(DEVICE_CREATE_FAILURE_PC, devNo, busNo,
POSTCODE_SEVERITY_ERR);
return CONTROLVM_RESP_ERROR_KMALLOC_FAILED;
}
dev->channelTypeGuid = msg->cmd.createDevice.dataTypeGuid;
dev->intr = msg->cmd.createDevice.intr;
dev->channelAddr = msg->cmd.createDevice.channelAddr;
dev->busNo = busNo;
dev->devNo = devNo;
sema_init(&dev->interrupt_callback_lock, 1);
sprintf(dev->devid, "vbus%u:dev%u", (unsigned) busNo, (unsigned) devNo);
if (msg->hdr.Flags.testMessage)
dev->chanptr = (void __iomem *)__va(dev->channelAddr);
else {
pReqHandler = ReqHandlerFind(dev->channelTypeGuid);
if (pReqHandler)
minSize = pReqHandler->min_channel_bytes;
if (minSize > msg->cmd.createDevice.channelBytes) {
LOGERR("CONTROLVM_DEVICE_CREATE Failed: channel size is too small, channel size:0x%lx, required size:0x%lx",
(ulong) msg->cmd.createDevice.channelBytes,
(ulong) minSize);
POSTCODE_LINUX_4(DEVICE_CREATE_FAILURE_PC, devNo, busNo,
POSTCODE_SEVERITY_ERR);
result = CONTROLVM_RESP_ERROR_CHANNEL_SIZE_TOO_SMALL;
goto Away;
}
dev->chanptr =
uislib_ioremap_cache(dev->channelAddr,
msg->cmd.createDevice.channelBytes);
if (!dev->chanptr) {
LOGERR("CONTROLVM_DEVICE_CREATE Failed: ioremap_cache of channelAddr:%Lx for channelBytes:%llu failed",
dev->channelAddr,
msg->cmd.createDevice.channelBytes);
result = CONTROLVM_RESP_ERROR_IOREMAP_FAILED;
POSTCODE_LINUX_4(DEVICE_CREATE_FAILURE_PC, devNo, busNo,
POSTCODE_SEVERITY_ERR);
goto Away;
}
}
dev->devInstGuid = msg->cmd.createDevice.devInstGuid;
dev->channelBytes = msg->cmd.createDevice.channelBytes;
read_lock(&BusListLock);
for (bus = BusListHead; bus; bus = bus->next) {
if (bus->busNo == busNo) {
if (devNo >= bus->deviceCount) {
LOGERR("CONTROLVM_DEVICE_CREATE Failed: device (%d) >= deviceCount (%d).",
devNo, bus->deviceCount);
result = CONTROLVM_RESP_ERROR_MAX_DEVICES;
POSTCODE_LINUX_4(DEVICE_CREATE_FAILURE_PC,
devNo, busNo,
POSTCODE_SEVERITY_ERR);
read_unlock(&BusListLock);
goto Away;
}
if (bus->device[devNo]) {
LOGERR("CONTROLVM_DEVICE_CREATE Failed: device %d is already exists.",
devNo);
POSTCODE_LINUX_4(DEVICE_CREATE_FAILURE_PC,
devNo, busNo,
POSTCODE_SEVERITY_ERR);
result = CONTROLVM_RESP_ERROR_ALREADY_DONE;
read_unlock(&BusListLock);
goto Away;
}
read_unlock(&BusListLock);
if (!msg->hdr.Flags.server) {
struct guest_msgs cmd;
if (!memcmp
(&dev->channelTypeGuid,
&UltraVhbaChannelProtocolGuid,
sizeof(GUID))) {
WAIT_FOR_VALID_GUID(((CHANNEL_HEADER
__iomem *) (dev->
chanptr))->
Type);
if (!ULTRA_VHBA_CHANNEL_OK_CLIENT
(dev->chanptr, NULL)) {
LOGERR("CONTROLVM_DEVICE_CREATE Failed:[CLIENT]VHBA dev %d chan invalid.",
devNo);
POSTCODE_LINUX_4
(DEVICE_CREATE_FAILURE_PC,
devNo, busNo,
POSTCODE_SEVERITY_ERR);
result = CONTROLVM_RESP_ERROR_CHANNEL_INVALID;
goto Away;
}
cmd.msgtype = GUEST_ADD_VHBA;
cmd.add_vhba.chanptr = dev->chanptr;
cmd.add_vhba.busNo = busNo;
cmd.add_vhba.deviceNo = devNo;
cmd.add_vhba.devInstGuid =
dev->devInstGuid;
cmd.add_vhba.intr = dev->intr;
} else
if (!memcmp
(&dev->channelTypeGuid,
&UltraVnicChannelProtocolGuid,
sizeof(GUID))) {
WAIT_FOR_VALID_GUID(((CHANNEL_HEADER
__iomem *) (dev->
chanptr))->
Type);
if (!ULTRA_VNIC_CHANNEL_OK_CLIENT
(dev->chanptr, NULL)) {
LOGERR("CONTROLVM_DEVICE_CREATE Failed: VNIC[CLIENT] dev %d chan invalid.",
devNo);
POSTCODE_LINUX_4
(DEVICE_CREATE_FAILURE_PC,
devNo, busNo,
POSTCODE_SEVERITY_ERR);
result = CONTROLVM_RESP_ERROR_CHANNEL_INVALID;
goto Away;
}
cmd.msgtype = GUEST_ADD_VNIC;
cmd.add_vnic.chanptr = dev->chanptr;
cmd.add_vnic.busNo = busNo;
cmd.add_vnic.deviceNo = devNo;
cmd.add_vnic.devInstGuid =
dev->devInstGuid;
cmd.add_vhba.intr = dev->intr;
} else {
LOGERR("CONTROLVM_DEVICE_CREATE Failed: unknown channelTypeGuid.\n");
POSTCODE_LINUX_4
(DEVICE_CREATE_FAILURE_PC, devNo,
busNo, POSTCODE_SEVERITY_ERR);
result = CONTROLVM_RESP_ERROR_CHANNEL_TYPE_UNKNOWN;
goto Away;
}
if (!VirtControlChanFunc) {
LOGERR("CONTROLVM_DEVICE_CREATE Failed: virtpci callback not registered.");
POSTCODE_LINUX_4
(DEVICE_CREATE_FAILURE_PC, devNo,
busNo, POSTCODE_SEVERITY_ERR);
result = CONTROLVM_RESP_ERROR_VIRTPCI_DRIVER_FAILURE;
goto Away;
}
if (!VirtControlChanFunc(&cmd)) {
LOGERR("CONTROLVM_DEVICE_CREATE Failed: virtpci GUEST_ADD_[VHBA||VNIC] returned error.");
POSTCODE_LINUX_4
(DEVICE_CREATE_FAILURE_PC, devNo,
busNo, POSTCODE_SEVERITY_ERR);
result = CONTROLVM_RESP_ERROR_VIRTPCI_DRIVER_CALLBACK_ERROR;
goto Away;
}
}
bus->device[devNo] = dev;
POSTCODE_LINUX_4(DEVICE_CREATE_SUCCESS_PC, devNo, busNo,
POSTCODE_SEVERITY_INFO);
return CONTROLVM_RESP_SUCCESS;
}
}
read_unlock(&BusListLock);
LOGERR("CONTROLVM_DEVICE_CREATE Failed: failed to find bus %d.", busNo);
POSTCODE_LINUX_4(DEVICE_CREATE_FAILURE_PC, devNo, busNo,
POSTCODE_SEVERITY_ERR);
result = CONTROLVM_RESP_ERROR_BUS_INVALID;
Away:
if (!msg->hdr.Flags.testMessage) {
uislib_iounmap(dev->chanptr);
dev->chanptr = NULL;
}
kfree(dev);
return result;
}
static int
pause_device(CONTROLVM_MESSAGE *msg)
{
U32 busNo, devNo;
struct bus_info *bus;
struct device_info *dev;
struct guest_msgs cmd;
busNo = msg->cmd.deviceChangeState.busNo;
devNo = msg->cmd.deviceChangeState.devNo;
read_lock(&BusListLock);
for (bus = BusListHead; bus; bus = bus->next) {
if (bus->busNo == busNo) {
if (devNo >= bus->deviceCount) {
LOGERR("CONTROLVM_DEVICE_CHANGESTATE:pause Failed: device(%d) >= deviceCount(%d).",
devNo, bus->deviceCount);
read_unlock(&BusListLock);
return CONTROLVM_RESP_ERROR_DEVICE_INVALID;
}
dev = bus->device[devNo];
if (!dev) {
LOGERR("CONTROLVM_DEVICE_CHANGESTATE:pause Failed: device %d does not exist.",
devNo);
read_unlock(&BusListLock);
return CONTROLVM_RESP_ERROR_ALREADY_DONE;
}
read_unlock(&BusListLock);
if (!memcmp
(&dev->channelTypeGuid,
&UltraVhbaChannelProtocolGuid, sizeof(GUID))) {
cmd.msgtype = GUEST_PAUSE_VHBA;
cmd.pause_vhba.chanptr = dev->chanptr;
} else
if (!memcmp
(&dev->channelTypeGuid,
&UltraVnicChannelProtocolGuid,
sizeof(GUID))) {
cmd.msgtype = GUEST_PAUSE_VNIC;
cmd.pause_vnic.chanptr = dev->chanptr;
} else {
LOGERR("CONTROLVM_DEVICE_CHANGESTATE:pause Failed: unknown channelTypeGuid.\n");
return
CONTROLVM_RESP_ERROR_CHANNEL_TYPE_UNKNOWN;
}
if (!VirtControlChanFunc) {
LOGERR("CONTROLVM_DEVICE_CHANGESTATE Failed: virtpci callback not registered.");
return
CONTROLVM_RESP_ERROR_VIRTPCI_DRIVER_FAILURE;
}
if (!VirtControlChanFunc(&cmd)) {
LOGERR("CONTROLVM_DEVICE_CHANGESTATE:pause Failed: virtpci GUEST_PAUSE_[VHBA||VNIC] returned error.");
return CONTROLVM_RESP_ERROR_VIRTPCI_DRIVER_CALLBACK_ERROR;
}
break;
}
}
if (!bus) {
LOGERR("CONTROLVM_DEVICE_CHANGESTATE:pause Failed: bus %d does not exist",
busNo);
read_unlock(&BusListLock);
return CONTROLVM_RESP_ERROR_BUS_INVALID;
}
return CONTROLVM_RESP_SUCCESS;
}
static int
resume_device(CONTROLVM_MESSAGE *msg)
{
U32 busNo, devNo;
struct bus_info *bus;
struct device_info *dev;
struct guest_msgs cmd;
busNo = msg->cmd.deviceChangeState.busNo;
devNo = msg->cmd.deviceChangeState.devNo;
read_lock(&BusListLock);
for (bus = BusListHead; bus; bus = bus->next) {
if (bus->busNo == busNo) {
if (devNo >= bus->deviceCount) {
LOGERR("CONTROLVM_DEVICE_CHANGESTATE:resume Failed: device(%d) >= deviceCount(%d).",
devNo, bus->deviceCount);
read_unlock(&BusListLock);
return CONTROLVM_RESP_ERROR_DEVICE_INVALID;
}
dev = bus->device[devNo];
if (!dev) {
LOGERR("CONTROLVM_DEVICE_CHANGESTATE:resume Failed: device %d does not exist.",
devNo);
read_unlock(&BusListLock);
return CONTROLVM_RESP_ERROR_ALREADY_DONE;
}
read_unlock(&BusListLock);
if (!memcmp(&dev->channelTypeGuid,
&UltraVhbaChannelProtocolGuid,
sizeof(GUID))) {
cmd.msgtype = GUEST_RESUME_VHBA;
cmd.resume_vhba.chanptr = dev->chanptr;
} else
if (!memcmp(&dev->channelTypeGuid,
&UltraVnicChannelProtocolGuid,
sizeof(GUID))) {
cmd.msgtype = GUEST_RESUME_VNIC;
cmd.resume_vnic.chanptr = dev->chanptr;
} else {
LOGERR("CONTROLVM_DEVICE_CHANGESTATE:resume Failed: unknown channelTypeGuid.\n");
return
CONTROLVM_RESP_ERROR_CHANNEL_TYPE_UNKNOWN;
}
if (!VirtControlChanFunc) {
LOGERR("CONTROLVM_DEVICE_CHANGESTATE Failed: virtpci callback not registered.");
return
CONTROLVM_RESP_ERROR_VIRTPCI_DRIVER_FAILURE;
}
if (!VirtControlChanFunc(&cmd)) {
LOGERR("CONTROLVM_DEVICE_CHANGESTATE:resume Failed: virtpci GUEST_RESUME_[VHBA||VNIC] returned error.");
return CONTROLVM_RESP_ERROR_VIRTPCI_DRIVER_CALLBACK_ERROR;
}
break;
}
}
if (!bus) {
LOGERR("CONTROLVM_DEVICE_CHANGESTATE:resume Failed: bus %d does not exist",
busNo);
read_unlock(&BusListLock);
return CONTROLVM_RESP_ERROR_BUS_INVALID;
}
return CONTROLVM_RESP_SUCCESS;
}
static int
destroy_device(CONTROLVM_MESSAGE *msg, char *buf)
{
U32 busNo, devNo;
struct bus_info *bus;
struct device_info *dev;
struct guest_msgs cmd;
busNo = msg->cmd.destroyDevice.busNo;
devNo = msg->cmd.destroyDevice.devNo;
read_lock(&BusListLock);
LOGINF("destroy_device called for busNo=%u, devNo=%u", busNo, devNo);
for (bus = BusListHead; bus; bus = bus->next) {
if (bus->busNo == busNo) {
if (devNo >= bus->deviceCount) {
LOGERR("CONTROLVM_DEVICE_DESTORY Failed: device(%d) >= deviceCount(%d).",
devNo, bus->deviceCount);
read_unlock(&BusListLock);
return CONTROLVM_RESP_ERROR_DEVICE_INVALID;
}
dev = bus->device[devNo];
if (!dev) {
LOGERR("CONTROLVM_DEVICE_DESTROY Failed: device %d does not exist.",
devNo);
read_unlock(&BusListLock);
return CONTROLVM_RESP_ERROR_ALREADY_DONE;
}
read_unlock(&BusListLock);
if (!memcmp
(&dev->channelTypeGuid,
&UltraVhbaChannelProtocolGuid, sizeof(GUID))) {
cmd.msgtype = GUEST_DEL_VHBA;
cmd.del_vhba.chanptr = dev->chanptr;
} else
if (!memcmp
(&dev->channelTypeGuid,
&UltraVnicChannelProtocolGuid,
sizeof(GUID))) {
cmd.msgtype = GUEST_DEL_VNIC;
cmd.del_vnic.chanptr = dev->chanptr;
} else {
LOGERR("CONTROLVM_DEVICE_DESTROY Failed: unknown channelTypeGuid.\n");
return
CONTROLVM_RESP_ERROR_CHANNEL_TYPE_UNKNOWN;
}
if (!VirtControlChanFunc) {
LOGERR("CONTROLVM_DEVICE_DESTORY Failed: virtpci callback not registered.");
return
CONTROLVM_RESP_ERROR_VIRTPCI_DRIVER_FAILURE;
}
if (!VirtControlChanFunc(&cmd)) {
LOGERR("CONTROLVM_DEVICE_DESTROY Failed: virtpci GUEST_DEL_[VHBA||VNIC] returned error.");
return CONTROLVM_RESP_ERROR_VIRTPCI_DRIVER_CALLBACK_ERROR;
}
if (dev->polling) {
LOGINF("calling uislib_disable_channel_interrupts");
uislib_disable_channel_interrupts(busNo, devNo);
}
if (!msg->hdr.Flags.testMessage) {
LOGINF("destroy_device, doing iounmap");
uislib_iounmap(dev->chanptr);
}
kfree(dev);
bus->device[devNo] = NULL;
break;
}
}
if (!bus) {
LOGERR("CONTROLVM_DEVICE_DESTROY Failed: bus %d does not exist",
busNo);
read_unlock(&BusListLock);
return CONTROLVM_RESP_ERROR_BUS_INVALID;
}
return CONTROLVM_RESP_SUCCESS;
}
static int
init_chipset(CONTROLVM_MESSAGE *msg, char *buf)
{
POSTCODE_LINUX_2(CHIPSET_INIT_ENTRY_PC, POSTCODE_SEVERITY_INFO);
MaxBusCount = msg->cmd.initChipset.busCount;
PlatformNumber = msg->cmd.initChipset.platformNumber;
PhysicalDataChan = 0;
if (!msg->hdr.Flags.testMessage)
WAIT_ON_CALLBACK(VirtControlChanFunc);
chipset_inited = 1;
POSTCODE_LINUX_2(CHIPSET_INIT_EXIT_PC, POSTCODE_SEVERITY_INFO);
return CONTROLVM_RESP_SUCCESS;
}
static int
stop_chipset(CONTROLVM_MESSAGE *msg, char *buf)
{
if (BusListHead) {
LOGERR("CONTROLVM_CHIPSET_STOP: BusListHead is not NULL");
return CONTROLVM_RESP_ERROR_CHIPSET_STOP_FAILED_BUS;
}
if (BusListCount) {
LOGERR("CONTROLVM_CHIPSET_STOP: BusListCount != 0");
return CONTROLVM_RESP_ERROR_CHIPSET_STOP_FAILED_BUS;
}
return visorchipset_chipset_notready();
}
static int
delete_bus_glue(U32 busNo)
{
CONTROLVM_MESSAGE msg;
init_msg_header(&msg, CONTROLVM_BUS_DESTROY, 0, 0);
msg.cmd.destroyBus.busNo = busNo;
if (destroy_bus(&msg, NULL) != CONTROLVM_RESP_SUCCESS) {
LOGERR("destroy_bus failed. busNo=0x%x\n", busNo);
return 0;
}
return 1;
}
static int
delete_device_glue(U32 busNo, U32 devNo)
{
CONTROLVM_MESSAGE msg;
init_msg_header(&msg, CONTROLVM_DEVICE_DESTROY, 0, 0);
msg.cmd.destroyDevice.busNo = busNo;
msg.cmd.destroyDevice.devNo = devNo;
if (destroy_device(&msg, NULL) != CONTROLVM_RESP_SUCCESS) {
LOGERR("destroy_device failed. busNo=0x%x devNo=0x%x\n", busNo,
devNo);
return 0;
}
return 1;
}
int
uislib_client_inject_add_bus(U32 busNo, GUID instGuid,
U64 channelAddr, ulong nChannelBytes)
{
CONTROLVM_MESSAGE msg;
LOGINF("enter busNo=0x%x\n", busNo);
POSTCODE_LINUX_3(CHIPSET_INIT_ENTRY_PC, busNo, POSTCODE_SEVERITY_INFO);
if (!chipset_inited) {
init_msg_header(&msg, CONTROLVM_CHIPSET_INIT, 0, 0);
msg.cmd.initChipset.busCount = 23;
msg.cmd.initChipset.switchCount = 0;
if (init_chipset(&msg, NULL) != CONTROLVM_RESP_SUCCESS) {
LOGERR("init_chipset failed.\n");
return 0;
}
LOGINF("chipset initialized\n");
POSTCODE_LINUX_3(CHIPSET_INIT_EXIT_PC, busNo,
POSTCODE_SEVERITY_INFO);
}
POSTCODE_LINUX_3(BUS_CREATE_ENTRY_PC, busNo, POSTCODE_SEVERITY_WARNING);
init_msg_header(&msg, CONTROLVM_BUS_CREATE, 0, 0);
msg.cmd.createBus.busNo = busNo;
msg.cmd.createBus.deviceCount = 23;
msg.cmd.createBus.channelAddr = channelAddr;
msg.cmd.createBus.channelBytes = nChannelBytes;
if (create_bus(&msg, NULL) != CONTROLVM_RESP_SUCCESS) {
LOGERR("create_bus failed.\n");
POSTCODE_LINUX_3(BUS_CREATE_FAILURE_PC, busNo,
POSTCODE_SEVERITY_ERR);
return 0;
}
POSTCODE_LINUX_3(BUS_CREATE_EXIT_PC, busNo, POSTCODE_SEVERITY_INFO);
return 1;
}
int
uislib_client_inject_del_bus(U32 busNo)
{
return delete_bus_glue(busNo);
}
int
uislib_client_inject_pause_vhba(U32 busNo, U32 devNo)
{
CONTROLVM_MESSAGE msg;
int rc;
init_msg_header(&msg, CONTROLVM_DEVICE_CHANGESTATE, 0, 0);
msg.cmd.deviceChangeState.busNo = busNo;
msg.cmd.deviceChangeState.devNo = devNo;
msg.cmd.deviceChangeState.state = SegmentStateStandby;
rc = pause_device(&msg);
if (rc != CONTROLVM_RESP_SUCCESS) {
LOGERR("VHBA pause_device failed. busNo=0x%x devNo=0x%x\n",
busNo, devNo);
return rc;
}
return 0;
}
int
uislib_client_inject_resume_vhba(U32 busNo, U32 devNo)
{
CONTROLVM_MESSAGE msg;
int rc;
init_msg_header(&msg, CONTROLVM_DEVICE_CHANGESTATE, 0, 0);
msg.cmd.deviceChangeState.busNo = busNo;
msg.cmd.deviceChangeState.devNo = devNo;
msg.cmd.deviceChangeState.state = SegmentStateRunning;
rc = resume_device(&msg);
if (rc != CONTROLVM_RESP_SUCCESS) {
LOGERR("VHBA resume_device failed. busNo=0x%x devNo=0x%x\n",
busNo, devNo);
return rc;
}
return 0;
}
int
uislib_client_inject_add_vhba(U32 busNo, U32 devNo,
U64 phys_chan_addr, U32 chan_bytes,
int is_test_addr, GUID instGuid,
struct InterruptInfo *intr)
{
CONTROLVM_MESSAGE msg;
LOGINF(" enter busNo=0x%x devNo=0x%x\n", busNo, devNo);
POSTCODE_LINUX_4(VHBA_CREATE_ENTRY_PC, devNo, busNo,
POSTCODE_SEVERITY_INFO);
init_msg_header(&msg, CONTROLVM_DEVICE_CREATE, 0, 0);
if (is_test_addr)
msg.hdr.Flags.testMessage = 1;
msg.cmd.createDevice.busNo = busNo;
msg.cmd.createDevice.devNo = devNo;
msg.cmd.createDevice.devInstGuid = instGuid;
if (intr)
msg.cmd.createDevice.intr = *intr;
else
memset(&msg.cmd.createDevice.intr, 0,
sizeof(struct InterruptInfo));
msg.cmd.createDevice.channelAddr = phys_chan_addr;
if (chan_bytes < MIN_IO_CHANNEL_SIZE) {
LOGERR("wrong channel size.chan_bytes = 0x%x IO_CHANNEL_SIZE= 0x%x\n",
chan_bytes, (unsigned int) MIN_IO_CHANNEL_SIZE);
POSTCODE_LINUX_4(VHBA_CREATE_FAILURE_PC, chan_bytes,
MIN_IO_CHANNEL_SIZE, POSTCODE_SEVERITY_ERR);
return 0;
}
msg.cmd.createDevice.channelBytes = chan_bytes;
msg.cmd.createDevice.dataTypeGuid = UltraVhbaChannelProtocolGuid;
if (create_device(&msg, NULL) != CONTROLVM_RESP_SUCCESS) {
LOGERR("VHBA create_device failed.\n");
POSTCODE_LINUX_4(VHBA_CREATE_FAILURE_PC, devNo, busNo,
POSTCODE_SEVERITY_ERR);
return 0;
}
POSTCODE_LINUX_4(VHBA_CREATE_SUCCESS_PC, devNo, busNo,
POSTCODE_SEVERITY_INFO);
return 1;
}
int
uislib_client_inject_del_vhba(U32 busNo, U32 devNo)
{
return delete_device_glue(busNo, devNo);
}
int
uislib_client_inject_add_vnic(U32 busNo, U32 devNo,
U64 phys_chan_addr, U32 chan_bytes,
int is_test_addr, GUID instGuid,
struct InterruptInfo *intr)
{
CONTROLVM_MESSAGE msg;
LOGINF(" enter busNo=0x%x devNo=0x%x\n", busNo, devNo);
POSTCODE_LINUX_4(VNIC_CREATE_ENTRY_PC, devNo, busNo,
POSTCODE_SEVERITY_INFO);
init_msg_header(&msg, CONTROLVM_DEVICE_CREATE, 0, 0);
if (is_test_addr)
msg.hdr.Flags.testMessage = 1;
msg.cmd.createDevice.busNo = busNo;
msg.cmd.createDevice.devNo = devNo;
msg.cmd.createDevice.devInstGuid = instGuid;
if (intr)
msg.cmd.createDevice.intr = *intr;
else
memset(&msg.cmd.createDevice.intr, 0,
sizeof(struct InterruptInfo));
msg.cmd.createDevice.channelAddr = phys_chan_addr;
if (chan_bytes < MIN_IO_CHANNEL_SIZE) {
LOGERR("wrong channel size.chan_bytes = 0x%x IO_CHANNEL_SIZE= 0x%x\n",
chan_bytes, (unsigned int) MIN_IO_CHANNEL_SIZE);
POSTCODE_LINUX_4(VNIC_CREATE_FAILURE_PC, chan_bytes,
MIN_IO_CHANNEL_SIZE, POSTCODE_SEVERITY_ERR);
return 0;
}
msg.cmd.createDevice.channelBytes = chan_bytes;
msg.cmd.createDevice.dataTypeGuid = UltraVnicChannelProtocolGuid;
if (create_device(&msg, NULL) != CONTROLVM_RESP_SUCCESS) {
LOGERR("VNIC create_device failed.\n");
POSTCODE_LINUX_4(VNIC_CREATE_FAILURE_PC, devNo, busNo,
POSTCODE_SEVERITY_ERR);
return 0;
}
POSTCODE_LINUX_4(VNIC_CREATE_SUCCESS_PC, devNo, busNo,
POSTCODE_SEVERITY_INFO);
return 1;
}
int
uislib_client_inject_pause_vnic(U32 busNo, U32 devNo)
{
CONTROLVM_MESSAGE msg;
int rc;
init_msg_header(&msg, CONTROLVM_DEVICE_CHANGESTATE, 0, 0);
msg.cmd.deviceChangeState.busNo = busNo;
msg.cmd.deviceChangeState.devNo = devNo;
msg.cmd.deviceChangeState.state = SegmentStateStandby;
rc = pause_device(&msg);
if (rc != CONTROLVM_RESP_SUCCESS) {
LOGERR("VNIC pause_device failed. busNo=0x%x devNo=0x%x\n",
busNo, devNo);
return -1;
}
return 0;
}
int
uislib_client_inject_resume_vnic(U32 busNo, U32 devNo)
{
CONTROLVM_MESSAGE msg;
int rc;
init_msg_header(&msg, CONTROLVM_DEVICE_CHANGESTATE, 0, 0);
msg.cmd.deviceChangeState.busNo = busNo;
msg.cmd.deviceChangeState.devNo = devNo;
msg.cmd.deviceChangeState.state = SegmentStateRunning;
rc = resume_device(&msg);
if (rc != CONTROLVM_RESP_SUCCESS) {
LOGERR("VNIC resume_device failed. busNo=0x%x devNo=0x%x\n",
busNo, devNo);
return -1;
}
return 0;
}
int
uislib_client_inject_del_vnic(U32 busNo, U32 devNo)
{
return delete_device_glue(busNo, devNo);
}
static int
uislib_client_add_vnic(U32 busNo)
{
BOOL busCreated = FALSE;
int devNo = 0;
GUID dummyGuid = GUID0;
CONTROLVM_MESSAGE msg;
init_msg_header(&msg, CONTROLVM_BUS_CREATE, 0, 0);
msg.hdr.Flags.testMessage = 1;
msg.cmd.createBus.busNo = busNo;
msg.cmd.createBus.deviceCount = 4;
msg.cmd.createBus.channelAddr = 0;
msg.cmd.createBus.channelBytes = 0;
if (create_bus(&msg, NULL) != CONTROLVM_RESP_SUCCESS) {
LOGERR("client create_bus failed");
return 0;
}
busCreated = TRUE;
init_msg_header(&msg, CONTROLVM_DEVICE_CREATE, 0, 0);
msg.hdr.Flags.testMessage = 1;
msg.cmd.createDevice.busNo = busNo;
msg.cmd.createDevice.devNo = devNo;
msg.cmd.createDevice.devInstGuid = dummyGuid;
memset(&msg.cmd.createDevice.intr, 0, sizeof(struct InterruptInfo));
msg.cmd.createDevice.channelAddr = PhysicalDataChan;
msg.cmd.createDevice.channelBytes = MIN_IO_CHANNEL_SIZE;
msg.cmd.createDevice.dataTypeGuid = UltraVnicChannelProtocolGuid;
if (create_device(&msg, NULL) != CONTROLVM_RESP_SUCCESS) {
LOGERR("client create_device failed");
goto AwayCleanup;
}
return 1;
AwayCleanup:
if (busCreated) {
init_msg_header(&msg, CONTROLVM_BUS_DESTROY, 0, 0);
msg.hdr.Flags.testMessage = 1;
msg.cmd.destroyBus.busNo = busNo;
if (destroy_bus(&msg, NULL) != CONTROLVM_RESP_SUCCESS)
LOGERR("client destroy_bus failed.\n");
}
return 0;
}
static int
uislib_client_delete_vnic(U32 busNo)
{
int devNo = 0;
CONTROLVM_MESSAGE msg;
init_msg_header(&msg, CONTROLVM_DEVICE_DESTROY, 0, 0);
msg.hdr.Flags.testMessage = 1;
msg.cmd.destroyDevice.busNo = busNo;
msg.cmd.destroyDevice.devNo = devNo;
if (destroy_device(&msg, NULL) != CONTROLVM_RESP_SUCCESS) {
LOGERR("client destroy_device failed.\n");
}
init_msg_header(&msg, CONTROLVM_BUS_DESTROY, 0, 0);
msg.hdr.Flags.testMessage = 1;
msg.cmd.destroyBus.busNo = busNo;
if (destroy_bus(&msg, NULL) != CONTROLVM_RESP_SUCCESS)
LOGERR("client destroy_bus failed.\n");
return 1;
}
void *
uislib_cache_alloc(struct kmem_cache *cur_pool, char *fn, int ln)
{
void *p = kmem_cache_alloc(cur_pool, GFP_ATOMIC | __GFP_NORETRY);
if (p == NULL) {
LOGERR("uislib_malloc failed to alloc uiscmdrsp @%s:%d",
fn, ln);
return NULL;
}
return p;
}
void
uislib_cache_free(struct kmem_cache *cur_pool, void *p, char *fn, int ln)
{
if (p == NULL) {
LOGERR("uislib_free NULL pointer @%s:%d", fn, ln);
return;
}
kmem_cache_free(cur_pool, p);
}
static ssize_t
vnic_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
int action = 0xffff, busNo = 0, i, result = 0;
char buf[4];
char direction;
if (count >= ARRAY_SIZE(buf))
return -EINVAL;
if (copy_from_user(buf, buffer, count)) {
LOGERR("echo > /proc/uislib/vnic copy_from_user ****FAILED.\n");
return -EFAULT;
}
i = sscanf(buf, "%d%c", &action, &direction);
if (i != 2) {
LOGERR("unable to parse vnic proc parameters.\n");
return -EFAULT;
}
if ((direction != '-') && (direction != '+')) {
LOGERR("unable to determine whether to add or delete vnic\n");
return -EFAULT;
}
switch (action) {
case 0:
busNo = 0;
if (direction == '+')
result = uislib_client_add_vnic(busNo);
else
result = uislib_client_delete_vnic(busNo);
if (!result) {
LOGERR("echo 0%c > /proc/uislib/vnic failed (client end)",
direction);
return -EFAULT;
}
return count;
default:
break;
}
LOGERR("USAGE: echo <action><direction (up/down)> > /proc/uislib/vnic");
LOGERR(" ");
LOGERR("Client Syntax");
LOGERR("-------------");
LOGERR("0+ ==> add vnic");
LOGERR("0- ==> delete vnic");
LOGERR(" ");
return count;
}
static ssize_t
chipset_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
int i, action = 0xffff;
char buf[4];
CONTROLVM_MESSAGE msg;
if (count >= ARRAY_SIZE(buf))
return -EINVAL;
memset(&msg, 0, sizeof(CONTROLVM_MESSAGE));
if (copy_from_user(buf, buffer, count)) {
LOGERR("copy_from_user ****FAILED.\n");
return -EFAULT;
}
if (chipset_inited) {
LOGINF("Chipset already initialized\n");
return -EFAULT;
}
i = sscanf(buf, "%x", &action);
switch (action) {
case 1:
init_msg_header(&msg, CONTROLVM_CHIPSET_INIT, 0, 0);
msg.hdr.Flags.testMessage = 0;
msg.cmd.initChipset.busCount = 23;
msg.cmd.initChipset.switchCount = 23;
if (init_chipset(&msg, NULL) != CONTROLVM_RESP_SUCCESS) {
LOGERR("init_chipset failed.\n");
return 0;
}
return 1;
case 2:
init_msg_header(&msg, CONTROLVM_CHIPSET_INIT, 0, 0);
msg.hdr.Flags.testMessage = 1;
msg.cmd.initChipset.busCount = 23;
msg.cmd.initChipset.switchCount = 23;
if (init_chipset(&msg, NULL) != CONTROLVM_RESP_SUCCESS) {
LOGERR("init_chipset failed.\n");
return 0;
}
return 1;
default:
break;
}
LOGERR("usage: 1 ==> init_chipset client\n");
LOGERR("usage: 2 ==> init_chipset test\n");
return -EFAULT;
}
static int
info_proc_read_helper(char **buff, int *buff_len)
{
int i, tot = 0;
struct bus_info *bus;
if (PLINE("\nBuses:\n") < 0)
goto err_done;
read_lock(&BusListLock);
for (bus = BusListHead; bus; bus = bus->next) {
if (PLINE(" bus=0x%p, busNo=%d, deviceCount=%d\n",
bus, bus->busNo, bus->deviceCount) < 0)
goto err_done_unlock;
if (PLINE(" Devices:\n") < 0)
goto err_done_unlock;
for (i = 0; i < bus->deviceCount; i++) {
if (bus->device[i]) {
if (PLINE(" busNo %d, device[%i]: 0x%p, chanptr=0x%p, swtch=0x%p\n",
bus->busNo, i, bus->device[i],
bus->device[i]->chanptr,
bus->device[i]->swtch) < 0)
goto err_done_unlock;
if (PLINE(" first_busy_cnt=%llu, moved_to_tail_cnt=%llu, last_on_list_cnt=%llu\n",
bus->device[i]->first_busy_cnt,
bus->device[i]->moved_to_tail_cnt,
bus->device[i]->last_on_list_cnt) < 0)
goto err_done_unlock;
}
}
}
read_unlock(&BusListLock);
if (PLINE("UisUtils_Registered_Services: %d\n",
atomic_read(&UisUtils_Registered_Services)) < 0)
goto err_done;
if (PLINE("cycles_before_wait %llu wait_cycles:%llu\n",
cycles_before_wait, wait_cycles) < 0)
goto err_done;
if (PLINE("tot_wakeup_cnt %llu:tot_wait_cnt %llu:tot_schedule_cnt %llu\n",
tot_wakeup_cnt, tot_wait_cnt, tot_schedule_cnt) < 0)
goto err_done;
if (PLINE("en_smart_wakeup %d\n", en_smart_wakeup) < 0)
goto err_done;
if (PLINE("tot_moved_to_tail_cnt %llu\n", tot_moved_to_tail_cnt) < 0)
goto err_done;
return tot;
err_done_unlock:
read_unlock(&BusListLock);
err_done:
return -1;
}
static ssize_t
info_proc_read(struct file *file, char __user *buf, size_t len, loff_t *offset)
{
char *temp;
int totalBytes = 0;
int remaining_bytes = PROC_READ_BUFFER_SIZE;
if (ProcReadBuffer == NULL) {
DBGINF("ProcReadBuffer == NULL; allocating buffer.\n.");
ProcReadBuffer = vmalloc(PROC_READ_BUFFER_SIZE);
if (ProcReadBuffer == NULL) {
LOGERR("failed to allocate buffer to provide proc data.\n");
return -ENOMEM;
}
}
temp = ProcReadBuffer;
if ((*offset == 0) || (!ProcReadBufferValid)) {
DBGINF("calling info_proc_read_helper.\n");
totalBytes = info_proc_read_helper(&temp, &remaining_bytes);
ProcReadBufferValid = 1;
} else
totalBytes = strlen(ProcReadBuffer);
return simple_read_from_buffer(buf, len, offset,
ProcReadBuffer, totalBytes);
}
static ssize_t
platformnumber_proc_read(struct file *file, char __user *buf,
size_t len, loff_t *offset)
{
int length = 0;
char *vbuf;
loff_t pos = *offset;
if (pos < 0)
return -EINVAL;
if (pos > 0 || !len)
return 0;
vbuf = kzalloc(len, GFP_KERNEL);
if (!vbuf)
return -ENOMEM;
length = sprintf(vbuf, "%d\n", PlatformNumber);
if (copy_to_user(buf, vbuf, length)) {
kfree(vbuf);
return -EFAULT;
}
kfree(vbuf);
*offset += length;
return length;
}
static int
proc_info_vbus_show(struct seq_file *m, void *v)
{
struct bus_info *bus = m->private;
int i, devInfoCount, x;
char buf[999];
if (bus == NULL)
return 0;
seq_printf(m, "Client device / client driver info for %s partition (vbus #%d):\n",
bus->partitionName, bus->busNo);
if ((bus->busChannelBytes == 0) || (bus->pBusChannel == NULL))
return 0;
devInfoCount =
(bus->busChannelBytes -
sizeof(ULTRA_VBUS_CHANNEL_PROTOCOL)) /
sizeof(ULTRA_VBUS_DEVICEINFO);
x = VBUSCHANNEL_devInfoToStringBuffer(&bus->pBusChannel->ChpInfo, buf,
sizeof(buf) - 1, -1);
buf[x] = '\0';
seq_printf(m, "%s", buf);
x = VBUSCHANNEL_devInfoToStringBuffer(&bus->pBusChannel->BusInfo,
buf, sizeof(buf) - 1, -1);
buf[x] = '\0';
seq_printf(m, "%s", buf);
for (i = 0; i < devInfoCount; i++) {
x = VBUSCHANNEL_devInfoToStringBuffer(&bus->pBusChannel->
DevInfo[i], buf,
sizeof(buf) - 1, i);
if (x > 0) {
buf[x] = '\0';
seq_printf(m, "%s", buf);
}
}
return 0;
}
static ssize_t
bus_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
int server_flag = 0;
int i, action = 0xffff, result;
char buf[16];
CONTROLVM_MESSAGE msg;
U32 busNo, deviceCount;
if (count >= ARRAY_SIZE(buf))
return -EINVAL;
memset(&msg, 0, sizeof(CONTROLVM_MESSAGE));
if (copy_from_user(buf, buffer, count)) {
LOGERR("echo > /proc/uislib/bus: copy_from_user ****FAILED.");
return -EFAULT;
}
i = sscanf(buf, "%x-%d-%d", &action, &busNo, &deviceCount);
switch (action) {
case 0:
if (i != 2)
break;
init_msg_header(&msg, CONTROLVM_BUS_DESTROY, 0, server_flag);
msg.cmd.destroyBus.busNo = busNo;
result = destroy_bus(&msg, NULL);
if (result != CONTROLVM_RESP_SUCCESS) {
LOGERR("echo 0-%d > /proc/uislib/bus {CONTROLVM_BUS_DESTROY Failed} Result(%d)",
busNo, result);
return -EFAULT;
}
return count;
case 1:
if (i != 3)
break;
init_msg_header(&msg, CONTROLVM_BUS_CREATE, 0, server_flag);
msg.cmd.createBus.busNo = busNo;
msg.cmd.createBus.deviceCount = deviceCount;
result = create_bus(&msg, NULL);
if (result != CONTROLVM_RESP_SUCCESS) {
LOGERR("echo 1-%d-%d > /proc/uislib/bus {CONTROLVM_BUS_CREATE Failed} Result(%d)",
busNo, deviceCount, result);
return -EFAULT;
}
return count;
default:
break;
}
LOGERR("USAGE: echo <action>-<busNo>... > /proc/uislib/bus");
LOGERR(" ");
LOGERR("Destruct Syntax ControlVM Message Id");
LOGERR("--------------- ---------------------");
LOGERR("0-<busNo> ==> CONTROLVM_BUS_DESTROY");
LOGERR(" ");
LOGERR("Construct Syntax ControlVM Message Id");
LOGERR("----------------------- -------------------- ");
LOGERR("1-<busNo>-<deviceCount> ==> CONTROLVM_BUS_CREATE");
return -EFAULT;
}
static ssize_t
uislib_proc_read_writeonly(struct file *file, char __user *buffer,
size_t count, loff_t *ppos)
{
return 0;
}
static ssize_t
dev_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
int server_flag = 0;
CONTROLVM_MESSAGE msg;
U32 busNo, devNo;
char buf[32];
unsigned int chanptr;
int type, i, action = 0xffff, result;
if (count >= ARRAY_SIZE(buf))
return -EINVAL;
if (copy_from_user(buf, buffer, count)) {
LOGERR("echo > /proc/uislib/device: copy_from_user ****FAILED.");
return -EFAULT;
}
i = sscanf(buf, "%x-%d-%d-%x-%d",
&action, &busNo, &devNo, &chanptr, &type);
switch (action) {
case 0:
if (i != 3)
break;
init_msg_header(&msg, CONTROLVM_DEVICE_DESTROY, 0, server_flag);
msg.cmd.destroyDevice.busNo = busNo;
msg.cmd.destroyDevice.devNo = devNo;
result = destroy_device(&msg, NULL);
if (result != CONTROLVM_RESP_SUCCESS) {
LOGERR("echo 0-%d-%d > /proc/uislib/device {CONTROLVM_DEVICE_DESTROY Failed} Result(%d)",
busNo, devNo, result);
return -EFAULT;
}
return count;
case 1:
if (i != 5)
break;
init_msg_header(&msg, CONTROLVM_DEVICE_CREATE, 0, server_flag);
msg.cmd.createDevice.busNo = busNo;
msg.cmd.createDevice.devNo = devNo;
msg.cmd.createDevice.channelAddr = __pa(chanptr);
msg.cmd.createDevice.channelBytes = MIN_IO_CHANNEL_SIZE;
if (type == 0)
msg.cmd.createDevice.dataTypeGuid =
UltraVhbaChannelProtocolGuid;
else if (type == 1)
msg.cmd.createDevice.dataTypeGuid =
UltraVnicChannelProtocolGuid;
else {
LOGERR("echo 1-%d-%d-%x-<type> > /proc/uislib/devce failed: invalid device type %d.",
busNo, devNo, chanptr, type);
return -EFAULT;
}
result = create_device(&msg, NULL);
if (result != CONTROLVM_RESP_SUCCESS) {
if (type == 0)
LOGERR("echo 1-%d-%d-%x-0 > /proc/uislib/device {CONTROLVM_DEVICE_CREATE[vHBA] Failed} Result(%d)",
busNo, devNo, chanptr, result);
else
LOGERR("echo 1-%d-%d-%x-1 > /proc/uislib/device {CONTROLVM_DEVICE_CREATE[vNIC] Failed} Result(%d)",
busNo, devNo, chanptr, result);
return -EFAULT;
}
default:
break;
}
LOGERR("USAGE: echo <action>-<busNo>-<devNo>... > /proc/uislib/device");
LOGERR(" ");
LOGERR("Destruct Syntax ControlVM Message Id");
LOGERR("----------------- ------------------------");
LOGERR("0-<busNo>-<devNo> ==> CONTROLVM_DEVICE_DESTROY");
LOGERR(" ");
LOGERR("Construct Syntax ControlVM Message Id");
LOGERR
("---------------------------------- ----------------------- ");
LOGERR
("1-<busNo>-<devNo>-<chanptr>-<type> ==> CONTROLVM_DEVICE_CREATE");
LOGERR(" <type = 0>: vHBA");
LOGERR(" <type = 1>: vNIC");
LOGERR(" ");
return -EFAULT;
}
static ssize_t
cycles_before_wait_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
char buf[16];
#define CYCLES_BEFORE_WAIT_USE_ERROR { \
LOGERR("Incorrect Call Home Input.\n"); \
pr_info("Please pass Call Home Event Parameters in the form:\n"); \
pr_info("EventID Category Type[parameter1][parameter2][parameter3][parameter4][parameter5][parameter6]\n"); \
return -EFAULT; \
}
if (count >= ARRAY_SIZE(buf))
return -EINVAL;
if (count == 0)
CYCLES_BEFORE_WAIT_USE_ERROR;
if (copy_from_user(buf, buffer, count)) {
LOGERR("copy_from_user failed.\n");
return -EFAULT;
}
buf[count - 1] = '\0';
if (sscanf(buf, "%lld", &cycles_before_wait) != 1)
CYCLES_BEFORE_WAIT_USE_ERROR;
return count;
}
static ssize_t
reset_counts_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
char buf[16];
unsigned long long new_value;
struct bus_info *bus;
int i;
#define RESET_COUNTS_USE_ERROR { \
LOGERR("Incorrect reset_counts Input.\n"); \
pr_info("Please pass the new value for the counters:\n"); \
pr_info("e.g. echo 0 > reset_counts\n"); \
return -EFAULT; \
}
if (count >= ARRAY_SIZE(buf))
return -EINVAL;
if (count == 0)
RESET_COUNTS_USE_ERROR;
if (copy_from_user(buf, buffer, count)) {
LOGERR("copy_from_user failed.\n");
return -EFAULT;
}
buf[count - 1] = '\0';
if (sscanf(buf, "%llu", &new_value) != 1)
RESET_COUNTS_USE_ERROR;
read_lock(&BusListLock);
for (bus = BusListHead; bus; bus = bus->next) {
for (i = 0; i < bus->deviceCount; i++) {
if (bus->device[i]) {
bus->device[i]->first_busy_cnt = new_value;
bus->device[i]->moved_to_tail_cnt = new_value;
bus->device[i]->last_on_list_cnt = new_value;
}
}
}
read_unlock(&BusListLock);
tot_moved_to_tail_cnt = new_value;
tot_wait_cnt = new_value;
tot_wakeup_cnt = new_value;
tot_schedule_cnt = new_value;
return count;
}
static ssize_t
smart_wakeup_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
char buf[16];
int new_value;
#define SMART_WAKEUP_USE_ERROR { \
LOGERR("Incorrect smart_wakeup Input 0 disables smart_wakeup, and 1 enables smart_wakeup.\n"); \
pr_info("echo 0 > smart_wakeup\n"); \
pr_info("echo 1 > smart_wakeup\n"); \
return -EFAULT; \
}
if (count >= ARRAY_SIZE(buf))
return -EINVAL;
if (count == 0)
SMART_WAKEUP_USE_ERROR;
if (copy_from_user(buf, buffer, count)) {
LOGERR("copy_from_user failed.\n");
return -EFAULT;
}
buf[count - 1] = '\0';
if (sscanf(buf, "%d", &new_value) != 1)
SMART_WAKEUP_USE_ERROR;
en_smart_wakeup = new_value;
return count;
}
static ssize_t
test_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
int i, action = 0xffff;
char buf[16];
CONTROLVM_MESSAGE msg;
S64 vrtc_offset;
if (count >= ARRAY_SIZE(buf))
return -EINVAL;
memset(&msg, 0, sizeof(CONTROLVM_MESSAGE));
if (copy_from_user(buf, buffer, count)) {
LOGERR("copy_from_user ****FAILED.\n");
return -EFAULT;
}
i = sscanf(buf, "%x", &action);
switch (action) {
case 6:
msg.hdr.Id = CONTROLVM_CHIPSET_STOP;
msg.hdr.Flags.responseExpected = 1;
stop_chipset(&msg, NULL);
break;
case 7:
vrtc_offset = 0;
LOGERR("about to issue QUERY vrtc_offset=%LX", vrtc_offset);
vrtc_offset = Issue_VMCALL_QUERY_GUEST_VIRTUAL_TIME_OFFSET();
LOGERR("result is vrtc_offset=%LX", vrtc_offset);
break;
case 8:
vrtc_offset = 60;
LOGERR("about to increase physical time by 0x%LX seconds",
vrtc_offset);
vrtc_offset = Issue_VMCALL_UPDATE_PHYSICAL_TIME(vrtc_offset);
break;
case 9:
vrtc_offset = -60;
LOGERR("about to decrease physical time by 0x%LX seconds",
vrtc_offset);
vrtc_offset = Issue_VMCALL_UPDATE_PHYSICAL_TIME(vrtc_offset);
break;
default:
LOGERR("usage: 6 for CHIPSET_STOP\n");
LOGERR(" 7 for VMCALL_QUERY_GUEST_VIRTUAL_TIME_OFFSET()\n");
LOGERR(" 8 for VMCALL_UPDATE_PHYSICAL_TIME(60)\n");
LOGERR(" 9 for VMCALL_UPDATE_PHYSICAL_TIME(-60)\n");
return -EFAULT;
break;
}
return count;
}
static struct device_info *
find_dev(U32 busNo, U32 devNo)
{
struct bus_info *bus;
struct device_info *dev = NULL;
read_lock(&BusListLock);
for (bus = BusListHead; bus; bus = bus->next) {
if (bus->busNo == busNo) {
if (devNo >= bus->deviceCount) {
LOGERR("%s bad busNo, devNo=%d,%d",
__func__,
(int) (busNo), (int) (devNo));
goto Away;
}
dev = bus->device[devNo];
if (!dev)
LOGERR("%s bad busNo, devNo=%d,%d",
__func__,
(int) (busNo), (int) (devNo));
goto Away;
}
}
Away:
read_unlock(&BusListLock);
return dev;
}
static int
Process_Incoming(void *v)
{
unsigned long long cur_cycles, old_cycles, idle_cycles, delta_cycles;
struct list_head *new_tail = NULL;
int i;
UIS_DAEMONIZE("dev_incoming");
for (i = 0; i < 16; i++) {
old_cycles = get_cycles();
wait_event_timeout(Wakeup_Polling_Device_Channels,
0, POLLJIFFIES_NORMAL);
cur_cycles = get_cycles();
if (wait_cycles == 0) {
wait_cycles = (cur_cycles - old_cycles);
} else {
if (wait_cycles < (cur_cycles - old_cycles))
wait_cycles = (cur_cycles - old_cycles);
}
}
LOGINF("wait_cycles=%llu", wait_cycles);
cycles_before_wait = wait_cycles;
idle_cycles = 0;
Go_Polling_Device_Channels = 0;
while (1) {
struct list_head *lelt, *tmp;
struct device_info *dev = NULL;
LOCKSEM_UNINTERRUPTIBLE(&Lock_Polling_Device_Channels);
new_tail = NULL;
list_for_each_safe(lelt, tmp, &List_Polling_Device_Channels) {
int rc = 0;
dev = list_entry(lelt, struct device_info,
list_polling_device_channels);
LOCKSEM_UNINTERRUPTIBLE(&dev->interrupt_callback_lock);
if (dev->interrupt)
rc = dev->interrupt(dev->interrupt_context);
else
continue;
UNLOCKSEM(&dev->interrupt_callback_lock);
if (rc) {
idle_cycles = 0;
if (new_tail == NULL) {
dev->first_busy_cnt++;
if (!
(list_is_last
(lelt,
&List_Polling_Device_Channels))) {
new_tail = lelt;
dev->moved_to_tail_cnt++;
} else
dev->last_on_list_cnt++;
}
}
if (Incoming_ThreadInfo.should_stop)
break;
}
if (new_tail != NULL) {
tot_moved_to_tail_cnt++;
list_move_tail(new_tail, &List_Polling_Device_Channels);
}
UNLOCKSEM(&Lock_Polling_Device_Channels);
cur_cycles = get_cycles();
delta_cycles = cur_cycles - old_cycles;
old_cycles = cur_cycles;
if (Incoming_ThreadInfo.should_stop)
break;
if (en_smart_wakeup == 0xFF) {
LOGINF("en_smart_wakeup set to 0xff, to force exiting process_incoming");
break;
}
if (idle_cycles > cycles_before_wait) {
Go_Polling_Device_Channels = 0;
tot_wait_cnt++;
wait_event_timeout(Wakeup_Polling_Device_Channels,
Go_Polling_Device_Channels,
POLLJIFFIES_NORMAL);
Go_Polling_Device_Channels = 1;
} else {
tot_schedule_cnt++;
schedule();
idle_cycles = idle_cycles + delta_cycles;
}
}
DBGINF("exiting.\n");
complete_and_exit(&Incoming_ThreadInfo.has_stopped, 0);
}
static BOOL
Initialize_incoming_thread(void)
{
if (Incoming_Thread_Started)
return TRUE;
if (!uisthread_start(&Incoming_ThreadInfo,
&Process_Incoming, NULL, "dev_incoming")) {
LOGERR("uisthread_start Initialize_incoming_thread ****FAILED");
return FALSE;
}
Incoming_Thread_Started = TRUE;
return TRUE;
}
void
uislib_enable_channel_interrupts(U32 busNo, U32 devNo,
int (*interrupt)(void *),
void *interrupt_context)
{
struct device_info *dev;
dev = find_dev(busNo, devNo);
if (!dev) {
LOGERR("%s busNo=%d, devNo=%d", __func__, (int) (busNo),
(int) (devNo));
return;
}
LOCKSEM_UNINTERRUPTIBLE(&Lock_Polling_Device_Channels);
Initialize_incoming_thread();
dev->interrupt = interrupt;
dev->interrupt_context = interrupt_context;
dev->polling = TRUE;
list_add_tail(&(dev->list_polling_device_channels),
&List_Polling_Device_Channels);
UNLOCKSEM(&Lock_Polling_Device_Channels);
}
void
uislib_disable_channel_interrupts(U32 busNo, U32 devNo)
{
struct device_info *dev;
dev = find_dev(busNo, devNo);
if (!dev) {
LOGERR("%s busNo=%d, devNo=%d", __func__, (int) (busNo),
(int) (devNo));
return;
}
LOCKSEM_UNINTERRUPTIBLE(&Lock_Polling_Device_Channels);
list_del(&dev->list_polling_device_channels);
dev->polling = FALSE;
dev->interrupt = NULL;
UNLOCKSEM(&Lock_Polling_Device_Channels);
}
static void
do_wakeup_polling_device_channels(struct work_struct *dummy)
{
if (!Go_Polling_Device_Channels) {
Go_Polling_Device_Channels = 1;
wake_up(&Wakeup_Polling_Device_Channels);
}
}
void
uislib_force_channel_interrupt(U32 busNo, U32 devNo)
{
if (en_smart_wakeup == 0)
return;
if (Go_Polling_Device_Channels)
return;
tot_wakeup_cnt++;
schedule_work(&Work_wakeup_polling_device_channels);
}
static int __init
uislib_mod_init(void)
{
LOGINF("MONITORAPIS");
LOGINF("sizeof(struct uiscmdrsp):%lu bytes\n",
(ulong) sizeof(struct uiscmdrsp));
LOGINF("sizeof(struct phys_info):%lu\n",
(ulong) sizeof(struct phys_info));
LOGINF("sizeof(uiscmdrsp_scsi):%lu\n",
(ulong) sizeof(struct uiscmdrsp_scsi));
LOGINF("sizeof(uiscmdrsp_net):%lu\n",
(ulong) sizeof(struct uiscmdrsp_net));
LOGINF("sizeof(CONTROLVM_MESSAGE):%lu bytes\n",
(ulong) sizeof(CONTROLVM_MESSAGE));
LOGINF("sizeof(ULTRA_CONTROLVM_CHANNEL_PROTOCOL):%lu bytes\n",
(ulong) sizeof(ULTRA_CONTROLVM_CHANNEL_PROTOCOL));
LOGINF("sizeof(CHANNEL_HEADER):%lu bytes\n",
(ulong) sizeof(CHANNEL_HEADER));
LOGINF("sizeof(ULTRA_IO_CHANNEL_PROTOCOL):%lu bytes\n",
(ulong) sizeof(ULTRA_IO_CHANNEL_PROTOCOL));
LOGINF("SIZEOF_CMDRSP:%lu bytes\n", SIZEOF_CMDRSP);
LOGINF("SIZEOF_PROTOCOL:%lu bytes\n", SIZEOF_PROTOCOL);
BusListHead = NULL;
BusListCount = MaxBusCount = 0;
rwlock_init(&BusListLock);
VirtControlChanFunc = NULL;
POSTCODE_LINUX_2(DRIVER_ENTRY_PC, POSTCODE_SEVERITY_INFO);
uislib_proc_dir = proc_mkdir(DIR_PROC_ENTRY, NULL);
uislib_proc_vbus_dir = proc_mkdir(DIR_VBUS_PROC_ENTRY, uislib_proc_dir);
vnic_proc_entry = proc_create(VNIC_PROC_ENTRY_FN, 0, uislib_proc_dir,
&proc_vnic_fops);
SET_PROC_OWNER(vnic_proc_entry, THIS_MODULE);
chipset_proc_entry =
proc_create(CHIPSET_PROC_ENTRY_FN, 0, uislib_proc_dir,
&proc_chipset_fops);
SET_PROC_OWNER(chipset_proc_entry, THIS_MODULE);
info_proc_entry = proc_create(INFO_PROC_ENTRY_FN, 0, uislib_proc_dir,
&proc_info_fops);
SET_PROC_OWNER(info_proc_entry, THIS_MODULE);
platformnumber_proc_entry =
proc_create(PLATFORMNUMBER_PROC_ENTRY_FN, 0, uislib_proc_dir,
&proc_platformnumber_fops);
SET_PROC_OWNER(platformnumberinfo_proc_entry, THIS_MODULE);
cycles_before_wait_proc_entry =
proc_create(CYCLES_BEFORE_WAIT_PROC_ENTRY_FN, 0, uislib_proc_dir,
&proc_cycles_before_wait_fops);
SET_PROC_OWNER(cycles_before_wait_proc_entry, THIS_MODULE);
reset_counts_proc_entry =
proc_create(RESET_COUNTS_PROC_ENTRY_FN, 0, uislib_proc_dir,
&proc_reset_counts_fops);
SET_PROC_OWNER(reset_counts_proc_entry, THIS_MODULE);
smart_wakeup_proc_entry =
proc_create(SMART_WAKEUP_PROC_ENTRY_FN, 0, uislib_proc_dir,
&proc_smart_wakeup_fops);
SET_PROC_OWNER(smart_wakeup_proc_entry, THIS_MODULE);
#ifdef UISLIB_TEST_PROC
test_proc_entry = proc_create(TEST_PROC_ENTRY_FN, 0, uislib_proc_dir,
&proc_test_fops);
SET_PROC_OWNER(test_proc_entry, THIS_MODULE);
bus_proc_entry = proc_create(BUS_PROC_ENTRY_FN, 0, uislib_proc_dir,
&proc_bus_fops);
SET_PROC_OWNER(bus_proc_entry, THIS_MODULE);
dev_proc_entry = proc_create(DEV_PROC_ENTRY_FN, 0, uislib_proc_dir,
&proc_dev_fops);
SET_PROC_OWNER(dev_proc_entry, THIS_MODULE);
#endif
POSTCODE_LINUX_3(DRIVER_EXIT_PC, 0, POSTCODE_SEVERITY_INFO);
return 0;
}
static void __exit
uislib_mod_exit(void)
{
if (disable_proc_entry)
remove_proc_entry(DISABLE_PROC_ENTRY_FN, uislib_proc_dir);
if (cycles_before_wait_proc_entry)
remove_proc_entry(CYCLES_BEFORE_WAIT_PROC_ENTRY_FN,
uislib_proc_dir);
if (reset_counts_proc_entry)
remove_proc_entry(RESET_COUNTS_PROC_ENTRY_FN, uislib_proc_dir);
if (smart_wakeup_proc_entry)
remove_proc_entry(SMART_WAKEUP_PROC_ENTRY_FN, uislib_proc_dir);
if (ctrlchan_proc_entry)
remove_proc_entry(CTRLCHAN_PROC_ENTRY_FN, uislib_proc_dir);
if (pmem_proc_entry)
remove_proc_entry(PMEM_PROC_ENTRY_FN, uislib_proc_dir);
if (info_proc_entry)
remove_proc_entry(INFO_PROC_ENTRY_FN, uislib_proc_dir);
if (switch_proc_entry)
remove_proc_entry(SWITCH_PROC_ENTRY_FN, uislib_proc_dir);
if (extport_proc_entry)
remove_proc_entry(EXTPORT_PROC_ENTRY_FN, uislib_proc_dir);
if (platformnumber_proc_entry)
remove_proc_entry(PLATFORMNUMBER_PROC_ENTRY_FN,
uislib_proc_dir);
if (bus_proc_entry)
remove_proc_entry(BUS_PROC_ENTRY_FN, uislib_proc_dir);
if (dev_proc_entry)
remove_proc_entry(DEV_PROC_ENTRY_FN, uislib_proc_dir);
if (vnic_proc_entry)
remove_proc_entry(VNIC_PROC_ENTRY_FN, uislib_proc_dir);
if (chipset_proc_entry)
remove_proc_entry(CHIPSET_PROC_ENTRY_FN, uislib_proc_dir);
if (uislib_proc_vbus_dir)
remove_proc_entry(DIR_VBUS_PROC_ENTRY, uislib_proc_dir);
if (uislib_proc_dir)
remove_proc_entry(DIR_PROC_ENTRY, NULL);
if (ProcReadBuffer) {
vfree(ProcReadBuffer);
ProcReadBuffer = NULL;
}
DBGINF("goodbye.\n");
return;
}
