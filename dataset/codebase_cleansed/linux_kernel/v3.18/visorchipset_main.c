static inline char *
NONULLSTR(char *s)
{
if (s)
return s;
return "";
}
static ssize_t toolaction_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u8 toolAction;
visorchannel_read(ControlVm_channel,
offsetof(ULTRA_CONTROLVM_CHANNEL_PROTOCOL,
ToolAction), &toolAction, sizeof(u8));
return scnprintf(buf, PAGE_SIZE, "%u\n", toolAction);
}
static ssize_t toolaction_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
u8 toolAction;
int ret;
if (kstrtou8(buf, 10, &toolAction) != 0)
return -EINVAL;
ret = visorchannel_write(ControlVm_channel,
offsetof(ULTRA_CONTROLVM_CHANNEL_PROTOCOL, ToolAction),
&toolAction, sizeof(u8));
if (ret)
return ret;
return count;
}
static ssize_t boottotool_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
ULTRA_EFI_SPAR_INDICATION efiSparIndication;
visorchannel_read(ControlVm_channel,
offsetof(ULTRA_CONTROLVM_CHANNEL_PROTOCOL,
EfiSparIndication), &efiSparIndication,
sizeof(ULTRA_EFI_SPAR_INDICATION));
return scnprintf(buf, PAGE_SIZE, "%u\n",
efiSparIndication.BootToTool);
}
static ssize_t boottotool_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int val, ret;
ULTRA_EFI_SPAR_INDICATION efiSparIndication;
if (kstrtoint(buf, 10, &val) != 0)
return -EINVAL;
efiSparIndication.BootToTool = val;
ret = visorchannel_write(ControlVm_channel,
offsetof(ULTRA_CONTROLVM_CHANNEL_PROTOCOL,
EfiSparIndication),
&(efiSparIndication),
sizeof(ULTRA_EFI_SPAR_INDICATION));
if (ret)
return ret;
return count;
}
static ssize_t error_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
u32 error;
visorchannel_read(ControlVm_channel, offsetof(
ULTRA_CONTROLVM_CHANNEL_PROTOCOL, InstallationError),
&error, sizeof(u32));
return scnprintf(buf, PAGE_SIZE, "%i\n", error);
}
static ssize_t error_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
u32 error;
int ret;
if (kstrtou32(buf, 10, &error) != 0)
return -EINVAL;
ret = visorchannel_write(ControlVm_channel,
offsetof(ULTRA_CONTROLVM_CHANNEL_PROTOCOL,
InstallationError),
&error, sizeof(u32));
if (ret)
return ret;
return count;
}
static ssize_t textid_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
u32 textId;
visorchannel_read(ControlVm_channel, offsetof(
ULTRA_CONTROLVM_CHANNEL_PROTOCOL, InstallationTextId),
&textId, sizeof(u32));
return scnprintf(buf, PAGE_SIZE, "%i\n", textId);
}
static ssize_t textid_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
u32 textId;
int ret;
if (kstrtou32(buf, 10, &textId) != 0)
return -EINVAL;
ret = visorchannel_write(ControlVm_channel,
offsetof(ULTRA_CONTROLVM_CHANNEL_PROTOCOL,
InstallationTextId),
&textId, sizeof(u32));
if (ret)
return ret;
return count;
}
static ssize_t remaining_steps_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
u16 remainingSteps;
visorchannel_read(ControlVm_channel,
offsetof(ULTRA_CONTROLVM_CHANNEL_PROTOCOL,
InstallationRemainingSteps),
&remainingSteps,
sizeof(u16));
return scnprintf(buf, PAGE_SIZE, "%hu\n", remainingSteps);
}
static ssize_t remaining_steps_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
u16 remainingSteps;
int ret;
if (kstrtou16(buf, 10, &remainingSteps) != 0)
return -EINVAL;
ret = visorchannel_write(ControlVm_channel,
offsetof(ULTRA_CONTROLVM_CHANNEL_PROTOCOL,
InstallationRemainingSteps),
&remainingSteps, sizeof(u16));
if (ret)
return ret;
return count;
}
static void
busInfo_clear(void *v)
{
VISORCHIPSET_BUS_INFO *p = (VISORCHIPSET_BUS_INFO *) (v);
if (p->procObject) {
visor_proc_DestroyObject(p->procObject);
p->procObject = NULL;
}
kfree(p->name);
p->name = NULL;
kfree(p->description);
p->description = NULL;
p->state.created = 0;
memset(p, 0, sizeof(VISORCHIPSET_BUS_INFO));
}
static void
devInfo_clear(void *v)
{
VISORCHIPSET_DEVICE_INFO *p = (VISORCHIPSET_DEVICE_INFO *) (v);
p->state.created = 0;
memset(p, 0, sizeof(VISORCHIPSET_DEVICE_INFO));
}
static u8
check_chipset_events(void)
{
int i;
u8 send_msg = 1;
for (i = 0; i < MAX_CHIPSET_EVENTS; i++)
send_msg &= chipset_events[i];
return send_msg;
}
static void
clear_chipset_events(void)
{
int i;
for (i = 0; i < MAX_CHIPSET_EVENTS; i++)
chipset_events[i] = 0;
}
void
visorchipset_register_busdev_server(VISORCHIPSET_BUSDEV_NOTIFIERS *notifiers,
VISORCHIPSET_BUSDEV_RESPONDERS *responders,
ULTRA_VBUS_DEVICEINFO *driverInfo)
{
down(&NotifierLock);
if (notifiers == NULL) {
memset(&BusDev_Server_Notifiers, 0,
sizeof(BusDev_Server_Notifiers));
serverregistered = 0;
} else {
BusDev_Server_Notifiers = *notifiers;
serverregistered = 1;
}
if (responders)
*responders = BusDev_Responders;
if (driverInfo)
bus_device_info_init(driverInfo, "chipset", "visorchipset",
VERSION, NULL);
up(&NotifierLock);
}
void
visorchipset_register_busdev_client(VISORCHIPSET_BUSDEV_NOTIFIERS *notifiers,
VISORCHIPSET_BUSDEV_RESPONDERS *responders,
ULTRA_VBUS_DEVICEINFO *driverInfo)
{
down(&NotifierLock);
if (notifiers == NULL) {
memset(&BusDev_Client_Notifiers, 0,
sizeof(BusDev_Client_Notifiers));
clientregistered = 0;
} else {
BusDev_Client_Notifiers = *notifiers;
clientregistered = 1;
}
if (responders)
*responders = BusDev_Responders;
if (driverInfo)
bus_device_info_init(driverInfo, "chipset(bolts)", "visorchipset",
VERSION, NULL);
up(&NotifierLock);
}
static void
cleanup_controlvm_structures(void)
{
VISORCHIPSET_BUS_INFO *bi, *tmp_bi;
VISORCHIPSET_DEVICE_INFO *di, *tmp_di;
list_for_each_entry_safe(bi, tmp_bi, &BusInfoList, entry) {
busInfo_clear(bi);
list_del(&bi->entry);
kfree(bi);
}
list_for_each_entry_safe(di, tmp_di, &DevInfoList, entry) {
devInfo_clear(di);
list_del(&di->entry);
kfree(di);
}
}
static void
chipset_init(CONTROLVM_MESSAGE *inmsg)
{
static int chipset_inited;
ULTRA_CHIPSET_FEATURE features = 0;
int rc = CONTROLVM_RESP_SUCCESS;
POSTCODE_LINUX_2(CHIPSET_INIT_ENTRY_PC, POSTCODE_SEVERITY_INFO);
if (chipset_inited) {
LOGERR("CONTROLVM_CHIPSET_INIT Failed: Already Done.");
rc = -CONTROLVM_RESP_ERROR_ALREADY_DONE;
goto Away;
}
chipset_inited = 1;
POSTCODE_LINUX_2(CHIPSET_INIT_EXIT_PC, POSTCODE_SEVERITY_INFO);
features =
inmsg->cmd.initChipset.
features & ULTRA_CHIPSET_FEATURE_PARA_HOTPLUG;
features |= ULTRA_CHIPSET_FEATURE_REPLY;
Away:
if (rc < 0)
cleanup_controlvm_structures();
if (inmsg->hdr.Flags.responseExpected)
controlvm_respond_chipset_init(&inmsg->hdr, rc, features);
}
static void
controlvm_init_response(CONTROLVM_MESSAGE *msg,
CONTROLVM_MESSAGE_HEADER *msgHdr, int response)
{
memset(msg, 0, sizeof(CONTROLVM_MESSAGE));
memcpy(&msg->hdr, msgHdr, sizeof(CONTROLVM_MESSAGE_HEADER));
msg->hdr.PayloadBytes = 0;
msg->hdr.PayloadVmOffset = 0;
msg->hdr.PayloadMaxBytes = 0;
if (response < 0) {
msg->hdr.Flags.failed = 1;
msg->hdr.CompletionStatus = (u32) (-response);
}
}
static void
controlvm_respond(CONTROLVM_MESSAGE_HEADER *msgHdr, int response)
{
CONTROLVM_MESSAGE outmsg;
controlvm_init_response(&outmsg, msgHdr, response);
if (msgHdr->Id == CONTROLVM_DEVICE_CHANGESTATE
&& g_DeviceChangeStatePacket.deviceChangeState.busNo ==
g_diagpoolBusNo
&& g_DeviceChangeStatePacket.deviceChangeState.devNo ==
g_diagpoolDevNo)
outmsg.cmd = g_DeviceChangeStatePacket;
if (outmsg.hdr.Flags.testMessage == 1) {
LOGINF("%s controlvm_msg=0x%x response=%d for test message",
__func__, outmsg.hdr.Id, response);
return;
}
if (!visorchannel_signalinsert(ControlVm_channel,
CONTROLVM_QUEUE_REQUEST, &outmsg)) {
LOGERR("signalinsert failed!");
return;
}
}
static void
controlvm_respond_chipset_init(CONTROLVM_MESSAGE_HEADER *msgHdr, int response,
ULTRA_CHIPSET_FEATURE features)
{
CONTROLVM_MESSAGE outmsg;
controlvm_init_response(&outmsg, msgHdr, response);
outmsg.cmd.initChipset.features = features;
if (!visorchannel_signalinsert(ControlVm_channel,
CONTROLVM_QUEUE_REQUEST, &outmsg)) {
LOGERR("signalinsert failed!");
return;
}
}
static void
controlvm_respond_physdev_changestate(CONTROLVM_MESSAGE_HEADER *msgHdr,
int response, ULTRA_SEGMENT_STATE state)
{
CONTROLVM_MESSAGE outmsg;
controlvm_init_response(&outmsg, msgHdr, response);
outmsg.cmd.deviceChangeState.state = state;
outmsg.cmd.deviceChangeState.flags.physicalDevice = 1;
if (!visorchannel_signalinsert(ControlVm_channel,
CONTROLVM_QUEUE_REQUEST, &outmsg)) {
LOGERR("signalinsert failed!");
return;
}
}
void
visorchipset_save_message(CONTROLVM_MESSAGE *msg, CRASH_OBJ_TYPE type)
{
u32 localSavedCrashMsgOffset;
u16 localSavedCrashMsgCount;
if (visorchannel_read(ControlVm_channel,
offsetof(ULTRA_CONTROLVM_CHANNEL_PROTOCOL,
SavedCrashMsgCount),
&localSavedCrashMsgCount, sizeof(u16)) < 0) {
LOGERR("failed to get Saved Message Count");
POSTCODE_LINUX_2(CRASH_DEV_CTRL_RD_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
if (localSavedCrashMsgCount != CONTROLVM_CRASHMSG_MAX) {
LOGERR("Saved Message Count incorrect %d",
localSavedCrashMsgCount);
POSTCODE_LINUX_3(CRASH_DEV_COUNT_FAILURE_PC,
localSavedCrashMsgCount,
POSTCODE_SEVERITY_ERR);
return;
}
if (visorchannel_read(ControlVm_channel,
offsetof(ULTRA_CONTROLVM_CHANNEL_PROTOCOL,
SavedCrashMsgOffset),
&localSavedCrashMsgOffset, sizeof(u32)) < 0) {
LOGERR("failed to get Saved Message Offset");
POSTCODE_LINUX_2(CRASH_DEV_CTRL_RD_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
if (type == CRASH_bus) {
if (visorchannel_write(ControlVm_channel,
localSavedCrashMsgOffset,
msg, sizeof(CONTROLVM_MESSAGE)) < 0) {
LOGERR("SAVE_MSG_BUS_FAILURE: Failed to write CrashCreateBusMsg!");
POSTCODE_LINUX_2(SAVE_MSG_BUS_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
} else {
if (visorchannel_write(ControlVm_channel,
localSavedCrashMsgOffset +
sizeof(CONTROLVM_MESSAGE), msg,
sizeof(CONTROLVM_MESSAGE)) < 0) {
LOGERR("SAVE_MSG_DEV_FAILURE: Failed to write CrashCreateDevMsg!");
POSTCODE_LINUX_2(SAVE_MSG_DEV_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
}
}
static void
bus_responder(CONTROLVM_ID cmdId, ulong busNo, int response)
{
VISORCHIPSET_BUS_INFO *p = NULL;
BOOL need_clear = FALSE;
p = findbus(&BusInfoList, busNo);
if (!p) {
LOGERR("internal error busNo=%lu", busNo);
return;
}
if (response < 0) {
if ((cmdId == CONTROLVM_BUS_CREATE) &&
(response != (-CONTROLVM_RESP_ERROR_ALREADY_DONE)))
delbusdevices(&DevInfoList, busNo);
} else {
if (cmdId == CONTROLVM_BUS_CREATE)
p->state.created = 1;
if (cmdId == CONTROLVM_BUS_DESTROY)
need_clear = TRUE;
}
if (p->pendingMsgHdr.Id == CONTROLVM_INVALID) {
LOGERR("bus_responder no pending msg");
return;
}
if (p->pendingMsgHdr.Id != (u32) cmdId) {
LOGERR("expected=%d, found=%d", cmdId, p->pendingMsgHdr.Id);
return;
}
controlvm_respond(&p->pendingMsgHdr, response);
p->pendingMsgHdr.Id = CONTROLVM_INVALID;
if (need_clear) {
busInfo_clear(p);
delbusdevices(&DevInfoList, busNo);
}
}
static void
device_changestate_responder(CONTROLVM_ID cmdId,
ulong busNo, ulong devNo, int response,
ULTRA_SEGMENT_STATE responseState)
{
VISORCHIPSET_DEVICE_INFO *p = NULL;
CONTROLVM_MESSAGE outmsg;
p = finddevice(&DevInfoList, busNo, devNo);
if (!p) {
LOGERR("internal error; busNo=%lu, devNo=%lu", busNo, devNo);
return;
}
if (p->pendingMsgHdr.Id == CONTROLVM_INVALID) {
LOGERR("device_responder no pending msg");
return;
}
if (p->pendingMsgHdr.Id != cmdId) {
LOGERR("expected=%d, found=%d", cmdId, p->pendingMsgHdr.Id);
return;
}
controlvm_init_response(&outmsg, &p->pendingMsgHdr, response);
outmsg.cmd.deviceChangeState.busNo = busNo;
outmsg.cmd.deviceChangeState.devNo = devNo;
outmsg.cmd.deviceChangeState.state = responseState;
if (!visorchannel_signalinsert(ControlVm_channel,
CONTROLVM_QUEUE_REQUEST, &outmsg)) {
LOGERR("signalinsert failed!");
return;
}
p->pendingMsgHdr.Id = CONTROLVM_INVALID;
}
static void
device_responder(CONTROLVM_ID cmdId, ulong busNo, ulong devNo, int response)
{
VISORCHIPSET_DEVICE_INFO *p = NULL;
BOOL need_clear = FALSE;
p = finddevice(&DevInfoList, busNo, devNo);
if (!p) {
LOGERR("internal error; busNo=%lu, devNo=%lu", busNo, devNo);
return;
}
if (response >= 0) {
if (cmdId == CONTROLVM_DEVICE_CREATE)
p->state.created = 1;
if (cmdId == CONTROLVM_DEVICE_DESTROY)
need_clear = TRUE;
}
if (p->pendingMsgHdr.Id == CONTROLVM_INVALID) {
LOGERR("device_responder no pending msg");
return;
}
if (p->pendingMsgHdr.Id != (u32) cmdId) {
LOGERR("expected=%d, found=%d", cmdId, p->pendingMsgHdr.Id);
return;
}
controlvm_respond(&p->pendingMsgHdr, response);
p->pendingMsgHdr.Id = CONTROLVM_INVALID;
if (need_clear)
devInfo_clear(p);
}
static void
bus_epilog(u32 busNo,
u32 cmd, CONTROLVM_MESSAGE_HEADER *msgHdr,
int response, BOOL needResponse)
{
BOOL notified = FALSE;
VISORCHIPSET_BUS_INFO *pBusInfo = findbus(&BusInfoList, busNo);
if (!pBusInfo) {
LOGERR("HUH? bad busNo=%d", busNo);
return;
}
if (needResponse) {
memcpy(&pBusInfo->pendingMsgHdr, msgHdr,
sizeof(CONTROLVM_MESSAGE_HEADER));
} else
pBusInfo->pendingMsgHdr.Id = CONTROLVM_INVALID;
down(&NotifierLock);
if (response == CONTROLVM_RESP_SUCCESS) {
switch (cmd) {
case CONTROLVM_BUS_CREATE:
if (BusDev_Server_Notifiers.bus_create) {
(*BusDev_Server_Notifiers.bus_create) (busNo);
notified = TRUE;
}
if ((!pBusInfo->flags.server) &&
BusDev_Client_Notifiers.bus_create) {
(*BusDev_Client_Notifiers.bus_create) (busNo);
notified = TRUE;
}
break;
case CONTROLVM_BUS_DESTROY:
if (BusDev_Server_Notifiers.bus_destroy) {
(*BusDev_Server_Notifiers.bus_destroy) (busNo);
notified = TRUE;
}
if ((!pBusInfo->flags.server) &&
BusDev_Client_Notifiers.bus_destroy) {
(*BusDev_Client_Notifiers.bus_destroy) (busNo);
notified = TRUE;
}
break;
}
}
if (notified)
;
else
bus_responder(cmd, busNo, response);
up(&NotifierLock);
}
static void
device_epilog(u32 busNo, u32 devNo, ULTRA_SEGMENT_STATE state, u32 cmd,
CONTROLVM_MESSAGE_HEADER *msgHdr, int response,
BOOL needResponse, BOOL for_visorbus)
{
VISORCHIPSET_BUSDEV_NOTIFIERS *notifiers = NULL;
BOOL notified = FALSE;
VISORCHIPSET_DEVICE_INFO *pDevInfo =
finddevice(&DevInfoList, busNo, devNo);
char *envp[] = {
"SPARSP_DIAGPOOL_PAUSED_STATE = 1",
NULL
};
if (!pDevInfo) {
LOGERR("HUH? bad busNo=%d, devNo=%d", busNo, devNo);
return;
}
if (for_visorbus)
notifiers = &BusDev_Server_Notifiers;
else
notifiers = &BusDev_Client_Notifiers;
if (needResponse) {
memcpy(&pDevInfo->pendingMsgHdr, msgHdr,
sizeof(CONTROLVM_MESSAGE_HEADER));
} else
pDevInfo->pendingMsgHdr.Id = CONTROLVM_INVALID;
down(&NotifierLock);
if (response >= 0) {
switch (cmd) {
case CONTROLVM_DEVICE_CREATE:
if (notifiers->device_create) {
(*notifiers->device_create) (busNo, devNo);
notified = TRUE;
}
break;
case CONTROLVM_DEVICE_CHANGESTATE:
if (state.Alive == SegmentStateRunning.Alive &&
state.Operating == SegmentStateRunning.Operating) {
if (notifiers->device_resume) {
(*notifiers->device_resume) (busNo,
devNo);
notified = TRUE;
}
}
else if (state.Alive == SegmentStateStandby.Alive &&
state.Operating ==
SegmentStateStandby.Operating) {
if (notifiers->device_pause) {
(*notifiers->device_pause) (busNo,
devNo);
notified = TRUE;
}
} else if (state.Alive == SegmentStatePaused.Alive &&
state.Operating ==
SegmentStatePaused.Operating) {
if (busNo == g_diagpoolBusNo
&& devNo == g_diagpoolDevNo) {
LOGINF("DEVICE_CHANGESTATE(DiagpoolChannel busNo=%d devNo=%d is pausing...)",
busNo, devNo);
kobject_uevent_env
(&Visorchipset_platform_device.dev.
kobj, KOBJ_ONLINE, envp);
}
}
break;
case CONTROLVM_DEVICE_DESTROY:
if (notifiers->device_destroy) {
(*notifiers->device_destroy) (busNo, devNo);
notified = TRUE;
}
break;
}
}
if (notified)
;
else
device_responder(cmd, busNo, devNo, response);
up(&NotifierLock);
}
static void
bus_create(CONTROLVM_MESSAGE *inmsg)
{
CONTROLVM_MESSAGE_PACKET *cmd = &inmsg->cmd;
ulong busNo = cmd->createBus.busNo;
int rc = CONTROLVM_RESP_SUCCESS;
VISORCHIPSET_BUS_INFO *pBusInfo = NULL;
pBusInfo = findbus(&BusInfoList, busNo);
if (pBusInfo && (pBusInfo->state.created == 1)) {
LOGERR("CONTROLVM_BUS_CREATE Failed: bus %lu already exists",
busNo);
POSTCODE_LINUX_3(BUS_CREATE_FAILURE_PC, busNo,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_ALREADY_DONE;
goto Away;
}
pBusInfo = kzalloc(sizeof(VISORCHIPSET_BUS_INFO), GFP_KERNEL);
if (pBusInfo == NULL) {
LOGERR("CONTROLVM_BUS_CREATE Failed: bus %lu kzalloc failed",
busNo);
POSTCODE_LINUX_3(BUS_CREATE_FAILURE_PC, busNo,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_KMALLOC_FAILED;
goto Away;
}
INIT_LIST_HEAD(&pBusInfo->entry);
pBusInfo->busNo = busNo;
pBusInfo->devNo = cmd->createBus.deviceCount;
POSTCODE_LINUX_3(BUS_CREATE_ENTRY_PC, busNo, POSTCODE_SEVERITY_INFO);
if (inmsg->hdr.Flags.testMessage == 1)
pBusInfo->chanInfo.addrType = ADDRTYPE_localTest;
else
pBusInfo->chanInfo.addrType = ADDRTYPE_localPhysical;
pBusInfo->flags.server = inmsg->hdr.Flags.server;
pBusInfo->chanInfo.channelAddr = cmd->createBus.channelAddr;
pBusInfo->chanInfo.nChannelBytes = cmd->createBus.channelBytes;
pBusInfo->chanInfo.channelTypeGuid = cmd->createBus.busDataTypeGuid;
pBusInfo->chanInfo.channelInstGuid = cmd->createBus.busInstGuid;
list_add(&pBusInfo->entry, &BusInfoList);
POSTCODE_LINUX_3(BUS_CREATE_EXIT_PC, busNo, POSTCODE_SEVERITY_INFO);
Away:
bus_epilog(busNo, CONTROLVM_BUS_CREATE, &inmsg->hdr,
rc, inmsg->hdr.Flags.responseExpected == 1);
}
static void
bus_destroy(CONTROLVM_MESSAGE *inmsg)
{
CONTROLVM_MESSAGE_PACKET *cmd = &inmsg->cmd;
ulong busNo = cmd->destroyBus.busNo;
VISORCHIPSET_BUS_INFO *pBusInfo;
int rc = CONTROLVM_RESP_SUCCESS;
pBusInfo = findbus(&BusInfoList, busNo);
if (!pBusInfo) {
LOGERR("CONTROLVM_BUS_DESTROY Failed: bus %lu invalid", busNo);
rc = -CONTROLVM_RESP_ERROR_BUS_INVALID;
goto Away;
}
if (pBusInfo->state.created == 0) {
LOGERR("CONTROLVM_BUS_DESTROY Failed: bus %lu already destroyed",
busNo);
rc = -CONTROLVM_RESP_ERROR_ALREADY_DONE;
goto Away;
}
Away:
bus_epilog(busNo, CONTROLVM_BUS_DESTROY, &inmsg->hdr,
rc, inmsg->hdr.Flags.responseExpected == 1);
}
static void
bus_configure(CONTROLVM_MESSAGE *inmsg, PARSER_CONTEXT *parser_ctx)
{
CONTROLVM_MESSAGE_PACKET *cmd = &inmsg->cmd;
ulong busNo = cmd->configureBus.busNo;
VISORCHIPSET_BUS_INFO *pBusInfo = NULL;
int rc = CONTROLVM_RESP_SUCCESS;
char s[99];
busNo = cmd->configureBus.busNo;
POSTCODE_LINUX_3(BUS_CONFIGURE_ENTRY_PC, busNo, POSTCODE_SEVERITY_INFO);
pBusInfo = findbus(&BusInfoList, busNo);
if (!pBusInfo) {
LOGERR("CONTROLVM_BUS_CONFIGURE Failed: bus %lu invalid",
busNo);
POSTCODE_LINUX_3(BUS_CONFIGURE_FAILURE_PC, busNo,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_BUS_INVALID;
goto Away;
}
if (pBusInfo->state.created == 0) {
LOGERR("CONTROLVM_BUS_CONFIGURE Failed: Invalid bus %lu - not created yet",
busNo);
POSTCODE_LINUX_3(BUS_CONFIGURE_FAILURE_PC, busNo,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_BUS_INVALID;
goto Away;
}
if (pBusInfo->pendingMsgHdr.Id != CONTROLVM_INVALID) {
LOGERR("CONTROLVM_BUS_CONFIGURE Failed: bus %lu MsgId=%u outstanding",
busNo, (uint) pBusInfo->pendingMsgHdr.Id);
POSTCODE_LINUX_3(BUS_CONFIGURE_FAILURE_PC, busNo,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_MESSAGE_ID_INVALID_FOR_CLIENT;
goto Away;
}
pBusInfo->partitionHandle = cmd->configureBus.guestHandle;
pBusInfo->partitionGuid = parser_id_get(parser_ctx);
parser_param_start(parser_ctx, PARSERSTRING_NAME);
pBusInfo->name = parser_string_get(parser_ctx);
visorchannel_uuid_id(&pBusInfo->partitionGuid, s);
POSTCODE_LINUX_3(BUS_CONFIGURE_EXIT_PC, busNo, POSTCODE_SEVERITY_INFO);
Away:
bus_epilog(busNo, CONTROLVM_BUS_CONFIGURE, &inmsg->hdr,
rc, inmsg->hdr.Flags.responseExpected == 1);
}
static void
my_device_create(CONTROLVM_MESSAGE *inmsg)
{
CONTROLVM_MESSAGE_PACKET *cmd = &inmsg->cmd;
ulong busNo = cmd->createDevice.busNo;
ulong devNo = cmd->createDevice.devNo;
VISORCHIPSET_DEVICE_INFO *pDevInfo = NULL;
VISORCHIPSET_BUS_INFO *pBusInfo = NULL;
int rc = CONTROLVM_RESP_SUCCESS;
pDevInfo = finddevice(&DevInfoList, busNo, devNo);
if (pDevInfo && (pDevInfo->state.created == 1)) {
LOGERR("CONTROLVM_DEVICE_CREATE Failed: busNo=%lu, devNo=%lu already exists",
busNo, devNo);
POSTCODE_LINUX_4(DEVICE_CREATE_FAILURE_PC, devNo, busNo,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_ALREADY_DONE;
goto Away;
}
pBusInfo = findbus(&BusInfoList, busNo);
if (!pBusInfo) {
LOGERR("CONTROLVM_DEVICE_CREATE Failed: Invalid bus %lu - out of range",
busNo);
POSTCODE_LINUX_4(DEVICE_CREATE_FAILURE_PC, devNo, busNo,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_BUS_INVALID;
goto Away;
}
if (pBusInfo->state.created == 0) {
LOGERR("CONTROLVM_DEVICE_CREATE Failed: Invalid bus %lu - not created yet",
busNo);
POSTCODE_LINUX_4(DEVICE_CREATE_FAILURE_PC, devNo, busNo,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_BUS_INVALID;
goto Away;
}
pDevInfo = kzalloc(sizeof(VISORCHIPSET_DEVICE_INFO), GFP_KERNEL);
if (pDevInfo == NULL) {
LOGERR("CONTROLVM_DEVICE_CREATE Failed: busNo=%lu, devNo=%lu kmaloc failed",
busNo, devNo);
POSTCODE_LINUX_4(DEVICE_CREATE_FAILURE_PC, devNo, busNo,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_KMALLOC_FAILED;
goto Away;
}
INIT_LIST_HEAD(&pDevInfo->entry);
pDevInfo->busNo = busNo;
pDevInfo->devNo = devNo;
pDevInfo->devInstGuid = cmd->createDevice.devInstGuid;
POSTCODE_LINUX_4(DEVICE_CREATE_ENTRY_PC, devNo, busNo,
POSTCODE_SEVERITY_INFO);
if (inmsg->hdr.Flags.testMessage == 1)
pDevInfo->chanInfo.addrType = ADDRTYPE_localTest;
else
pDevInfo->chanInfo.addrType = ADDRTYPE_localPhysical;
pDevInfo->chanInfo.channelAddr = cmd->createDevice.channelAddr;
pDevInfo->chanInfo.nChannelBytes = cmd->createDevice.channelBytes;
pDevInfo->chanInfo.channelTypeGuid = cmd->createDevice.dataTypeGuid;
pDevInfo->chanInfo.intr = cmd->createDevice.intr;
list_add(&pDevInfo->entry, &DevInfoList);
POSTCODE_LINUX_4(DEVICE_CREATE_EXIT_PC, devNo, busNo,
POSTCODE_SEVERITY_INFO);
Away:
if (is_diagpool_channel(pDevInfo->chanInfo.channelTypeGuid)) {
g_diagpoolBusNo = busNo;
g_diagpoolDevNo = devNo;
LOGINF("CONTROLVM_DEVICE_CREATE for DiagPool channel: busNo=%lu, devNo=%lu",
g_diagpoolBusNo, g_diagpoolDevNo);
}
device_epilog(busNo, devNo, SegmentStateRunning,
CONTROLVM_DEVICE_CREATE, &inmsg->hdr, rc,
inmsg->hdr.Flags.responseExpected == 1,
FOR_VISORBUS(pDevInfo->chanInfo.channelTypeGuid));
}
static void
my_device_changestate(CONTROLVM_MESSAGE *inmsg)
{
CONTROLVM_MESSAGE_PACKET *cmd = &inmsg->cmd;
ulong busNo = cmd->deviceChangeState.busNo;
ulong devNo = cmd->deviceChangeState.devNo;
ULTRA_SEGMENT_STATE state = cmd->deviceChangeState.state;
VISORCHIPSET_DEVICE_INFO *pDevInfo = NULL;
int rc = CONTROLVM_RESP_SUCCESS;
pDevInfo = finddevice(&DevInfoList, busNo, devNo);
if (!pDevInfo) {
LOGERR("CONTROLVM_DEVICE_CHANGESTATE Failed: busNo=%lu, devNo=%lu invalid (doesn't exist)",
busNo, devNo);
POSTCODE_LINUX_4(DEVICE_CHANGESTATE_FAILURE_PC, devNo, busNo,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_DEVICE_INVALID;
goto Away;
}
if (pDevInfo->state.created == 0) {
LOGERR("CONTROLVM_DEVICE_CHANGESTATE Failed: busNo=%lu, devNo=%lu invalid (not created)",
busNo, devNo);
POSTCODE_LINUX_4(DEVICE_CHANGESTATE_FAILURE_PC, devNo, busNo,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_DEVICE_INVALID;
}
Away:
if ((rc >= CONTROLVM_RESP_SUCCESS) && pDevInfo)
device_epilog(busNo, devNo, state, CONTROLVM_DEVICE_CHANGESTATE,
&inmsg->hdr, rc,
inmsg->hdr.Flags.responseExpected == 1,
FOR_VISORBUS(pDevInfo->chanInfo.channelTypeGuid));
}
static void
my_device_destroy(CONTROLVM_MESSAGE *inmsg)
{
CONTROLVM_MESSAGE_PACKET *cmd = &inmsg->cmd;
ulong busNo = cmd->destroyDevice.busNo;
ulong devNo = cmd->destroyDevice.devNo;
VISORCHIPSET_DEVICE_INFO *pDevInfo = NULL;
int rc = CONTROLVM_RESP_SUCCESS;
pDevInfo = finddevice(&DevInfoList, busNo, devNo);
if (!pDevInfo) {
LOGERR("CONTROLVM_DEVICE_DESTROY Failed: busNo=%lu, devNo=%lu invalid",
busNo, devNo);
rc = -CONTROLVM_RESP_ERROR_DEVICE_INVALID;
goto Away;
}
if (pDevInfo->state.created == 0) {
LOGERR("CONTROLVM_DEVICE_DESTROY Failed: busNo=%lu, devNo=%lu already destroyed",
busNo, devNo);
rc = -CONTROLVM_RESP_ERROR_ALREADY_DONE;
}
Away:
if ((rc >= CONTROLVM_RESP_SUCCESS) && pDevInfo)
device_epilog(busNo, devNo, SegmentStateRunning,
CONTROLVM_DEVICE_DESTROY, &inmsg->hdr, rc,
inmsg->hdr.Flags.responseExpected == 1,
FOR_VISORBUS(pDevInfo->chanInfo.channelTypeGuid));
}
static int
initialize_controlvm_payload_info(HOSTADDRESS phys_addr, u64 offset, u32 bytes,
CONTROLVM_PAYLOAD_INFO *info)
{
u8 __iomem *payload = NULL;
int rc = CONTROLVM_RESP_SUCCESS;
if (info == NULL) {
LOGERR("HUH ? CONTROLVM_PAYLOAD_INIT Failed : Programmer check at %s:%d",
__FILE__, __LINE__);
rc = -CONTROLVM_RESP_ERROR_PAYLOAD_INVALID;
goto Away;
}
memset(info, 0, sizeof(CONTROLVM_PAYLOAD_INFO));
if ((offset == 0) || (bytes == 0)) {
LOGERR("CONTROLVM_PAYLOAD_INIT Failed: RequestPayloadOffset=%llu RequestPayloadBytes=%llu!",
(u64) offset, (u64) bytes);
rc = -CONTROLVM_RESP_ERROR_PAYLOAD_INVALID;
goto Away;
}
payload = ioremap_cache(phys_addr + offset, bytes);
if (payload == NULL) {
LOGERR("CONTROLVM_PAYLOAD_INIT Failed: ioremap_cache %llu for %llu bytes failed",
(u64) offset, (u64) bytes);
rc = -CONTROLVM_RESP_ERROR_IOREMAP_FAILED;
goto Away;
}
info->offset = offset;
info->bytes = bytes;
info->ptr = payload;
LOGINF("offset=%llu, bytes=%lu, ptr=%p",
(u64) (info->offset), (ulong) (info->bytes), info->ptr);
Away:
if (rc < 0) {
if (payload != NULL) {
iounmap(payload);
payload = NULL;
}
}
return rc;
}
static void
destroy_controlvm_payload_info(CONTROLVM_PAYLOAD_INFO *info)
{
if (info->ptr != NULL) {
iounmap(info->ptr);
info->ptr = NULL;
}
memset(info, 0, sizeof(CONTROLVM_PAYLOAD_INFO));
}
static void
initialize_controlvm_payload(void)
{
HOSTADDRESS phys_addr = visorchannel_get_physaddr(ControlVm_channel);
u64 payloadOffset = 0;
u32 payloadBytes = 0;
if (visorchannel_read(ControlVm_channel,
offsetof(ULTRA_CONTROLVM_CHANNEL_PROTOCOL,
RequestPayloadOffset),
&payloadOffset, sizeof(payloadOffset)) < 0) {
LOGERR("CONTROLVM_PAYLOAD_INIT Failed to read controlvm channel!");
POSTCODE_LINUX_2(CONTROLVM_INIT_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
if (visorchannel_read(ControlVm_channel,
offsetof(ULTRA_CONTROLVM_CHANNEL_PROTOCOL,
RequestPayloadBytes),
&payloadBytes, sizeof(payloadBytes)) < 0) {
LOGERR("CONTROLVM_PAYLOAD_INIT Failed to read controlvm channel!");
POSTCODE_LINUX_2(CONTROLVM_INIT_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
initialize_controlvm_payload_info(phys_addr,
payloadOffset, payloadBytes,
&ControlVm_payload_info);
}
int
visorchipset_chipset_ready(void)
{
kobject_uevent(&Visorchipset_platform_device.dev.kobj, KOBJ_ONLINE);
return CONTROLVM_RESP_SUCCESS;
}
int
visorchipset_chipset_selftest(void)
{
char env_selftest[20];
char *envp[] = { env_selftest, NULL };
sprintf(env_selftest, "SPARSP_SELFTEST=%d", 1);
kobject_uevent_env(&Visorchipset_platform_device.dev.kobj, KOBJ_CHANGE,
envp);
return CONTROLVM_RESP_SUCCESS;
}
int
visorchipset_chipset_notready(void)
{
kobject_uevent(&Visorchipset_platform_device.dev.kobj, KOBJ_OFFLINE);
return CONTROLVM_RESP_SUCCESS;
}
static void
chipset_ready(CONTROLVM_MESSAGE_HEADER *msgHdr)
{
int rc = visorchipset_chipset_ready();
if (rc != CONTROLVM_RESP_SUCCESS)
rc = -rc;
if (msgHdr->Flags.responseExpected && !visorchipset_holdchipsetready)
controlvm_respond(msgHdr, rc);
if (msgHdr->Flags.responseExpected && visorchipset_holdchipsetready) {
g_ChipSetMsgHdr = *msgHdr;
LOGINF("Holding CHIPSET_READY response");
}
}
static void
chipset_selftest(CONTROLVM_MESSAGE_HEADER *msgHdr)
{
int rc = visorchipset_chipset_selftest();
if (rc != CONTROLVM_RESP_SUCCESS)
rc = -rc;
if (msgHdr->Flags.responseExpected)
controlvm_respond(msgHdr, rc);
}
static void
chipset_notready(CONTROLVM_MESSAGE_HEADER *msgHdr)
{
int rc = visorchipset_chipset_notready();
if (rc != CONTROLVM_RESP_SUCCESS)
rc = -rc;
if (msgHdr->Flags.responseExpected)
controlvm_respond(msgHdr, rc);
}
static BOOL
read_controlvm_event(CONTROLVM_MESSAGE *msg)
{
if (visorchannel_signalremove(ControlVm_channel,
CONTROLVM_QUEUE_EVENT, msg)) {
if (msg->hdr.Flags.testMessage == 1) {
LOGERR("ignoring bad CONTROLVM_QUEUE_EVENT msg with controlvm_msg_id=0x%x because Flags.testMessage is nonsensical (=1)", msg->hdr.Id);
return FALSE;
}
return TRUE;
}
return FALSE;
}
static int
parahotplug_next_id(void)
{
static atomic_t id = ATOMIC_INIT(0);
return atomic_inc_return(&id);
}
static unsigned long
parahotplug_next_expiration(void)
{
return jiffies + PARAHOTPLUG_TIMEOUT_MS * HZ / 1000;
}
static struct parahotplug_request *
parahotplug_request_create(CONTROLVM_MESSAGE *msg)
{
struct parahotplug_request *req =
kmalloc(sizeof(struct parahotplug_request),
GFP_KERNEL|__GFP_NORETRY);
if (req == NULL)
return NULL;
req->id = parahotplug_next_id();
req->expiration = parahotplug_next_expiration();
req->msg = *msg;
return req;
}
static void
parahotplug_request_destroy(struct parahotplug_request *req)
{
kfree(req);
}
static void
parahotplug_request_kickoff(struct parahotplug_request *req)
{
CONTROLVM_MESSAGE_PACKET *cmd = &req->msg.cmd;
char env_cmd[40], env_id[40], env_state[40], env_bus[40], env_dev[40],
env_func[40];
char *envp[] = {
env_cmd, env_id, env_state, env_bus, env_dev, env_func, NULL
};
sprintf(env_cmd, "SPAR_PARAHOTPLUG=1");
sprintf(env_id, "SPAR_PARAHOTPLUG_ID=%d", req->id);
sprintf(env_state, "SPAR_PARAHOTPLUG_STATE=%d",
cmd->deviceChangeState.state.Active);
sprintf(env_bus, "SPAR_PARAHOTPLUG_BUS=%d",
cmd->deviceChangeState.busNo);
sprintf(env_dev, "SPAR_PARAHOTPLUG_DEVICE=%d",
cmd->deviceChangeState.devNo >> 3);
sprintf(env_func, "SPAR_PARAHOTPLUG_FUNCTION=%d",
cmd->deviceChangeState.devNo & 0x7);
LOGINF("parahotplug_request_kickoff: state=%d, bdf=%d/%d/%d, id=%u\n",
cmd->deviceChangeState.state.Active,
cmd->deviceChangeState.busNo, cmd->deviceChangeState.devNo >> 3,
cmd->deviceChangeState.devNo & 7, req->id);
kobject_uevent_env(&Visorchipset_platform_device.dev.kobj, KOBJ_CHANGE,
envp);
}
static void
parahotplug_process_list(void)
{
struct list_head *pos = NULL;
struct list_head *tmp = NULL;
spin_lock(&Parahotplug_request_list_lock);
list_for_each_safe(pos, tmp, &Parahotplug_request_list) {
struct parahotplug_request *req =
list_entry(pos, struct parahotplug_request, list);
if (time_after_eq(jiffies, req->expiration)) {
list_del(pos);
if (req->msg.hdr.Flags.responseExpected)
controlvm_respond_physdev_changestate(
&req->msg.hdr,
CONTROLVM_RESP_ERROR_DEVICE_UDEV_TIMEOUT,
req->msg.cmd.deviceChangeState.state);
parahotplug_request_destroy(req);
}
}
spin_unlock(&Parahotplug_request_list_lock);
}
static int
parahotplug_request_complete(int id, u16 active)
{
struct list_head *pos = NULL;
struct list_head *tmp = NULL;
spin_lock(&Parahotplug_request_list_lock);
list_for_each_safe(pos, tmp, &Parahotplug_request_list) {
struct parahotplug_request *req =
list_entry(pos, struct parahotplug_request, list);
if (req->id == id) {
list_del(pos);
spin_unlock(&Parahotplug_request_list_lock);
req->msg.cmd.deviceChangeState.state.Active = active;
if (req->msg.hdr.Flags.responseExpected)
controlvm_respond_physdev_changestate(
&req->msg.hdr, CONTROLVM_RESP_SUCCESS,
req->msg.cmd.deviceChangeState.state);
parahotplug_request_destroy(req);
return 0;
}
}
spin_unlock(&Parahotplug_request_list_lock);
return -1;
}
static void
parahotplug_process_message(CONTROLVM_MESSAGE *inmsg)
{
struct parahotplug_request *req;
req = parahotplug_request_create(inmsg);
if (req == NULL) {
LOGERR("parahotplug_process_message: couldn't allocate request");
return;
}
if (inmsg->cmd.deviceChangeState.state.Active) {
parahotplug_request_kickoff(req);
controlvm_respond_physdev_changestate(&inmsg->hdr,
CONTROLVM_RESP_SUCCESS,
inmsg->cmd.
deviceChangeState.state);
parahotplug_request_destroy(req);
} else {
spin_lock(&Parahotplug_request_list_lock);
list_add_tail(&(req->list), &Parahotplug_request_list);
spin_unlock(&Parahotplug_request_list_lock);
parahotplug_request_kickoff(req);
}
}
static BOOL
handle_command(CONTROLVM_MESSAGE inmsg, HOSTADDRESS channel_addr)
{
CONTROLVM_MESSAGE_PACKET *cmd = &inmsg.cmd;
u64 parametersAddr = 0;
u32 parametersBytes = 0;
PARSER_CONTEXT *parser_ctx = NULL;
BOOL isLocalAddr = FALSE;
CONTROLVM_MESSAGE ackmsg;
isLocalAddr = (inmsg.hdr.Flags.testMessage == 1);
if (channel_addr == 0) {
LOGERR("HUH? channel_addr is 0!");
return TRUE;
}
parametersAddr = channel_addr + inmsg.hdr.PayloadVmOffset;
parametersBytes = inmsg.hdr.PayloadBytes;
if (parametersAddr != 0 && parametersBytes != 0) {
BOOL retry = FALSE;
parser_ctx =
parser_init_byteStream(parametersAddr, parametersBytes,
isLocalAddr, &retry);
if (!parser_ctx) {
if (retry) {
LOGWRN("throttling to copy payload");
return FALSE;
}
LOGWRN("parsing failed");
LOGWRN("inmsg.hdr.Id=0x%lx", (ulong) inmsg.hdr.Id);
LOGWRN("parametersAddr=0x%llx", (u64) parametersAddr);
LOGWRN("parametersBytes=%lu", (ulong) parametersBytes);
LOGWRN("isLocalAddr=%d", isLocalAddr);
}
}
if (!isLocalAddr) {
controlvm_init_response(&ackmsg, &inmsg.hdr,
CONTROLVM_RESP_SUCCESS);
if ((ControlVm_channel)
&&
(!visorchannel_signalinsert
(ControlVm_channel, CONTROLVM_QUEUE_ACK, &ackmsg)))
LOGWRN("failed to send ACK failed");
}
switch (inmsg.hdr.Id) {
case CONTROLVM_CHIPSET_INIT:
LOGINF("CHIPSET_INIT(#busses=%lu,#switches=%lu)",
(ulong) inmsg.cmd.initChipset.busCount,
(ulong) inmsg.cmd.initChipset.switchCount);
chipset_init(&inmsg);
break;
case CONTROLVM_BUS_CREATE:
LOGINF("BUS_CREATE(%lu,#devs=%lu)",
(ulong) cmd->createBus.busNo,
(ulong) cmd->createBus.deviceCount);
bus_create(&inmsg);
break;
case CONTROLVM_BUS_DESTROY:
LOGINF("BUS_DESTROY(%lu)", (ulong) cmd->destroyBus.busNo);
bus_destroy(&inmsg);
break;
case CONTROLVM_BUS_CONFIGURE:
LOGINF("BUS_CONFIGURE(%lu)", (ulong) cmd->configureBus.busNo);
bus_configure(&inmsg, parser_ctx);
break;
case CONTROLVM_DEVICE_CREATE:
LOGINF("DEVICE_CREATE(%lu,%lu)",
(ulong) cmd->createDevice.busNo,
(ulong) cmd->createDevice.devNo);
my_device_create(&inmsg);
break;
case CONTROLVM_DEVICE_CHANGESTATE:
if (cmd->deviceChangeState.flags.physicalDevice) {
LOGINF("DEVICE_CHANGESTATE for physical device (%lu,%lu, active=%lu)",
(ulong) cmd->deviceChangeState.busNo,
(ulong) cmd->deviceChangeState.devNo,
(ulong) cmd->deviceChangeState.state.Active);
parahotplug_process_message(&inmsg);
} else {
LOGINF("DEVICE_CHANGESTATE for virtual device (%lu,%lu, state.Alive=0x%lx)",
(ulong) cmd->deviceChangeState.busNo,
(ulong) cmd->deviceChangeState.devNo,
(ulong) cmd->deviceChangeState.state.Alive);
my_device_changestate(&inmsg);
g_DiagMsgHdr = inmsg.hdr;
g_DeviceChangeStatePacket = inmsg.cmd;
break;
}
break;
case CONTROLVM_DEVICE_DESTROY:
LOGINF("DEVICE_DESTROY(%lu,%lu)",
(ulong) cmd->destroyDevice.busNo,
(ulong) cmd->destroyDevice.devNo);
my_device_destroy(&inmsg);
break;
case CONTROLVM_DEVICE_CONFIGURE:
LOGINF("DEVICE_CONFIGURE(%lu,%lu)",
(ulong) cmd->configureDevice.busNo,
(ulong) cmd->configureDevice.devNo);
if (inmsg.hdr.Flags.responseExpected)
controlvm_respond(&inmsg.hdr, CONTROLVM_RESP_SUCCESS);
break;
case CONTROLVM_CHIPSET_READY:
LOGINF("CHIPSET_READY");
chipset_ready(&inmsg.hdr);
break;
case CONTROLVM_CHIPSET_SELFTEST:
LOGINF("CHIPSET_SELFTEST");
chipset_selftest(&inmsg.hdr);
break;
case CONTROLVM_CHIPSET_STOP:
LOGINF("CHIPSET_STOP");
chipset_notready(&inmsg.hdr);
break;
default:
LOGERR("unrecognized controlvm cmd=%d", (int) inmsg.hdr.Id);
if (inmsg.hdr.Flags.responseExpected)
controlvm_respond(&inmsg.hdr,
-CONTROLVM_RESP_ERROR_MESSAGE_ID_UNKNOWN);
break;
}
if (parser_ctx != NULL) {
parser_done(parser_ctx);
parser_ctx = NULL;
}
return TRUE;
}
static HOSTADDRESS controlvm_get_channel_address(void)
{
u64 addr = 0;
u32 size = 0;
if (!VMCALL_SUCCESSFUL(issue_vmcall_io_controlvm_addr(&addr, &size))) {
ERRDRV("%s - vmcall to determine controlvm channel addr failed",
__func__);
return 0;
}
INFODRV("controlvm addr=%Lx", addr);
return addr;
}
static void
controlvm_periodic_work(struct work_struct *work)
{
VISORCHIPSET_CHANNEL_INFO chanInfo;
CONTROLVM_MESSAGE inmsg;
BOOL gotACommand = FALSE;
BOOL handle_command_failed = FALSE;
static u64 Poll_Count;
if (visorchipset_serverregwait && !serverregistered)
goto Away;
if (visorchipset_clientregwait && !clientregistered)
goto Away;
memset(&chanInfo, 0, sizeof(VISORCHIPSET_CHANNEL_INFO));
Poll_Count++;
if (Poll_Count >= 250)
;
else
goto Away;
if (visorchipset_holdchipsetready
&& (g_ChipSetMsgHdr.Id != CONTROLVM_INVALID)) {
if (check_chipset_events() == 1) {
LOGINF("Sending CHIPSET_READY response");
controlvm_respond(&g_ChipSetMsgHdr, 0);
clear_chipset_events();
memset(&g_ChipSetMsgHdr, 0,
sizeof(CONTROLVM_MESSAGE_HEADER));
}
}
while (visorchannel_signalremove(ControlVm_channel,
CONTROLVM_QUEUE_RESPONSE,
&inmsg)) {
if (inmsg.hdr.PayloadMaxBytes != 0) {
LOGERR("Payload of size %lu returned @%lu with unexpected message id %d.",
(ulong) inmsg.hdr.PayloadMaxBytes,
(ulong) inmsg.hdr.PayloadVmOffset,
inmsg.hdr.Id);
}
}
if (!gotACommand) {
if (ControlVm_Pending_Msg_Valid) {
inmsg = ControlVm_Pending_Msg;
ControlVm_Pending_Msg_Valid = FALSE;
gotACommand = TRUE;
} else
gotACommand = read_controlvm_event(&inmsg);
}
handle_command_failed = FALSE;
while (gotACommand && (!handle_command_failed)) {
Most_recent_message_jiffies = jiffies;
if (handle_command(inmsg,
visorchannel_get_physaddr
(ControlVm_channel)))
gotACommand = read_controlvm_event(&inmsg);
else {
handle_command_failed = TRUE;
ControlVm_Pending_Msg = inmsg;
ControlVm_Pending_Msg_Valid = TRUE;
}
}
parahotplug_process_list();
Away:
if (time_after(jiffies,
Most_recent_message_jiffies + (HZ * MIN_IDLE_SECONDS))) {
if (Poll_jiffies != POLLJIFFIES_CONTROLVMCHANNEL_SLOW) {
LOGINF("switched to slow controlvm polling");
Poll_jiffies = POLLJIFFIES_CONTROLVMCHANNEL_SLOW;
}
} else {
if (Poll_jiffies != POLLJIFFIES_CONTROLVMCHANNEL_FAST) {
Poll_jiffies = POLLJIFFIES_CONTROLVMCHANNEL_FAST;
LOGINF("switched to fast controlvm polling");
}
}
queue_delayed_work(Periodic_controlvm_workqueue,
&Periodic_controlvm_work, Poll_jiffies);
}
static void
setup_crash_devices_work_queue(struct work_struct *work)
{
CONTROLVM_MESSAGE localCrashCreateBusMsg;
CONTROLVM_MESSAGE localCrashCreateDevMsg;
CONTROLVM_MESSAGE msg;
u32 localSavedCrashMsgOffset;
u16 localSavedCrashMsgCount;
if (visorchipset_serverregwait && !serverregistered)
goto Away;
if (visorchipset_clientregwait && !clientregistered)
goto Away;
POSTCODE_LINUX_2(CRASH_DEV_ENTRY_PC, POSTCODE_SEVERITY_INFO);
msg.hdr.Id = CONTROLVM_CHIPSET_INIT;
msg.cmd.initChipset.busCount = 23;
msg.cmd.initChipset.switchCount = 0;
chipset_init(&msg);
if (visorchannel_read(ControlVm_channel,
offsetof(ULTRA_CONTROLVM_CHANNEL_PROTOCOL,
SavedCrashMsgCount),
&localSavedCrashMsgCount, sizeof(u16)) < 0) {
LOGERR("failed to get Saved Message Count");
POSTCODE_LINUX_2(CRASH_DEV_CTRL_RD_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
if (localSavedCrashMsgCount != CONTROLVM_CRASHMSG_MAX) {
LOGERR("Saved Message Count incorrect %d",
localSavedCrashMsgCount);
POSTCODE_LINUX_3(CRASH_DEV_COUNT_FAILURE_PC,
localSavedCrashMsgCount,
POSTCODE_SEVERITY_ERR);
return;
}
if (visorchannel_read(ControlVm_channel,
offsetof(ULTRA_CONTROLVM_CHANNEL_PROTOCOL,
SavedCrashMsgOffset),
&localSavedCrashMsgOffset, sizeof(u32)) < 0) {
LOGERR("failed to get Saved Message Offset");
POSTCODE_LINUX_2(CRASH_DEV_CTRL_RD_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
if (visorchannel_read(ControlVm_channel,
localSavedCrashMsgOffset,
&localCrashCreateBusMsg,
sizeof(CONTROLVM_MESSAGE)) < 0) {
LOGERR("CRASH_DEV_RD_BUS_FAIULRE: Failed to read CrashCreateBusMsg!");
POSTCODE_LINUX_2(CRASH_DEV_RD_BUS_FAIULRE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
if (visorchannel_read(ControlVm_channel,
localSavedCrashMsgOffset +
sizeof(CONTROLVM_MESSAGE),
&localCrashCreateDevMsg,
sizeof(CONTROLVM_MESSAGE)) < 0) {
LOGERR("CRASH_DEV_RD_DEV_FAIULRE: Failed to read CrashCreateDevMsg!");
POSTCODE_LINUX_2(CRASH_DEV_RD_DEV_FAIULRE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
if (localCrashCreateBusMsg.cmd.createBus.channelAddr != 0)
bus_create(&localCrashCreateBusMsg);
else {
LOGERR("CrashCreateBusMsg is null, no dump will be taken");
POSTCODE_LINUX_2(CRASH_DEV_BUS_NULL_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
if (localCrashCreateDevMsg.cmd.createDevice.channelAddr != 0)
my_device_create(&localCrashCreateDevMsg);
else {
LOGERR("CrashCreateDevMsg is null, no dump will be taken");
POSTCODE_LINUX_2(CRASH_DEV_DEV_NULL_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
LOGINF("Bus and device ready for dumping");
POSTCODE_LINUX_2(CRASH_DEV_EXIT_PC, POSTCODE_SEVERITY_INFO);
return;
Away:
Poll_jiffies = POLLJIFFIES_CONTROLVMCHANNEL_SLOW;
queue_delayed_work(Periodic_controlvm_workqueue,
&Periodic_controlvm_work, Poll_jiffies);
}
static void
bus_create_response(ulong busNo, int response)
{
bus_responder(CONTROLVM_BUS_CREATE, busNo, response);
}
static void
bus_destroy_response(ulong busNo, int response)
{
bus_responder(CONTROLVM_BUS_DESTROY, busNo, response);
}
static void
device_create_response(ulong busNo, ulong devNo, int response)
{
device_responder(CONTROLVM_DEVICE_CREATE, busNo, devNo, response);
}
static void
device_destroy_response(ulong busNo, ulong devNo, int response)
{
device_responder(CONTROLVM_DEVICE_DESTROY, busNo, devNo, response);
}
void
visorchipset_device_pause_response(ulong busNo, ulong devNo, int response)
{
device_changestate_responder(CONTROLVM_DEVICE_CHANGESTATE,
busNo, devNo, response,
SegmentStateStandby);
}
static void
device_resume_response(ulong busNo, ulong devNo, int response)
{
device_changestate_responder(CONTROLVM_DEVICE_CHANGESTATE,
busNo, devNo, response,
SegmentStateRunning);
}
BOOL
visorchipset_get_bus_info(ulong busNo, VISORCHIPSET_BUS_INFO *busInfo)
{
void *p = findbus(&BusInfoList, busNo);
if (!p) {
LOGERR("(%lu) failed", busNo);
return FALSE;
}
memcpy(busInfo, p, sizeof(VISORCHIPSET_BUS_INFO));
return TRUE;
}
BOOL
visorchipset_set_bus_context(ulong busNo, void *context)
{
VISORCHIPSET_BUS_INFO *p = findbus(&BusInfoList, busNo);
if (!p) {
LOGERR("(%lu) failed", busNo);
return FALSE;
}
p->bus_driver_context = context;
return TRUE;
}
BOOL
visorchipset_get_device_info(ulong busNo, ulong devNo,
VISORCHIPSET_DEVICE_INFO *devInfo)
{
void *p = finddevice(&DevInfoList, busNo, devNo);
if (!p) {
LOGERR("(%lu,%lu) failed", busNo, devNo);
return FALSE;
}
memcpy(devInfo, p, sizeof(VISORCHIPSET_DEVICE_INFO));
return TRUE;
}
BOOL
visorchipset_set_device_context(ulong busNo, ulong devNo, void *context)
{
VISORCHIPSET_DEVICE_INFO *p = finddevice(&DevInfoList, busNo, devNo);
if (!p) {
LOGERR("(%lu,%lu) failed", busNo, devNo);
return FALSE;
}
p->bus_driver_context = context;
return TRUE;
}
void *
visorchipset_cache_alloc(struct kmem_cache *pool, BOOL ok_to_block,
char *fn, int ln)
{
gfp_t gfp;
void *p;
if (ok_to_block)
gfp = GFP_KERNEL;
else
gfp = GFP_ATOMIC;
gfp |= __GFP_NORETRY;
p = kmem_cache_alloc(pool, gfp);
if (!p) {
LOGERR("kmem_cache_alloc failed early @%s:%d\n", fn, ln);
return NULL;
}
atomic_inc(&Visorchipset_cache_buffers_in_use);
return p;
}
void
visorchipset_cache_free(struct kmem_cache *pool, void *p, char *fn, int ln)
{
if (!p) {
LOGERR("NULL pointer @%s:%d\n", fn, ln);
return;
}
atomic_dec(&Visorchipset_cache_buffers_in_use);
kmem_cache_free(pool, p);
}
static ssize_t chipsetready_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
char msgtype[64];
if (sscanf(buf, "%63s", msgtype) != 1)
return -EINVAL;
if (strcmp(msgtype, "CALLHOMEDISK_MOUNTED") == 0) {
chipset_events[0] = 1;
return count;
} else if (strcmp(msgtype, "MODULES_LOADED") == 0) {
chipset_events[1] = 1;
return count;
}
return -EINVAL;
}
static ssize_t devicedisabled_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
uint id;
if (kstrtouint(buf, 10, &id) != 0)
return -EINVAL;
parahotplug_request_complete(id, 0);
return count;
}
static ssize_t deviceenabled_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
uint id;
if (kstrtouint(buf, 10, &id) != 0)
return -EINVAL;
parahotplug_request_complete(id, 1);
return count;
}
static int __init
visorchipset_init(void)
{
int rc = 0, x = 0;
char s[64];
HOSTADDRESS addr;
if (!unisys_spar_platform)
return -ENODEV;
LOGINF("chipset driver version %s loaded", VERSION);
POSTCODE_LINUX_2(DRIVER_ENTRY_PC, POSTCODE_SEVERITY_INFO);
LOGINF("option - testvnic=%d", visorchipset_testvnic);
LOGINF("option - testvnicclient=%d", visorchipset_testvnicclient);
LOGINF("option - testmsg=%d", visorchipset_testmsg);
LOGINF("option - testteardown=%d", visorchipset_testteardown);
LOGINF("option - major=%d", visorchipset_major);
LOGINF("option - serverregwait=%d", visorchipset_serverregwait);
LOGINF("option - clientregwait=%d", visorchipset_clientregwait);
LOGINF("option - holdchipsetready=%d", visorchipset_holdchipsetready);
memset(&BusDev_Server_Notifiers, 0, sizeof(BusDev_Server_Notifiers));
memset(&BusDev_Client_Notifiers, 0, sizeof(BusDev_Client_Notifiers));
memset(&ControlVm_payload_info, 0, sizeof(ControlVm_payload_info));
memset(&LiveDump_info, 0, sizeof(LiveDump_info));
atomic_set(&LiveDump_info.buffers_in_use, 0);
if (visorchipset_testvnic) {
ERRDRV("testvnic option no longer supported: (status = %d)\n",
x);
POSTCODE_LINUX_3(CHIPSET_INIT_FAILURE_PC, x, DIAG_SEVERITY_ERR);
rc = x;
goto Away;
}
addr = controlvm_get_channel_address();
if (addr != 0) {
ControlVm_channel =
visorchannel_create_with_lock
(addr,
sizeof(ULTRA_CONTROLVM_CHANNEL_PROTOCOL),
UltraControlvmChannelProtocolGuid);
if (ULTRA_CONTROLVM_CHANNEL_OK_CLIENT
(visorchannel_get_header(ControlVm_channel),
NULL)) {
LOGINF("Channel %s (ControlVm) discovered",
visorchannel_id(ControlVm_channel, s));
initialize_controlvm_payload();
} else {
LOGERR("controlvm channel is invalid");
visorchannel_destroy(ControlVm_channel);
ControlVm_channel = NULL;
return -ENODEV;
}
} else {
LOGERR("no controlvm channel discovered");
return -ENODEV;
}
MajorDev = MKDEV(visorchipset_major, 0);
rc = visorchipset_file_init(MajorDev, &ControlVm_channel);
if (rc < 0) {
ERRDRV("visorchipset_file_init(MajorDev, &ControlVm_channel): error (status=%d)\n", rc);
POSTCODE_LINUX_2(CHIPSET_INIT_FAILURE_PC, DIAG_SEVERITY_ERR);
goto Away;
}
memset(&g_DiagMsgHdr, 0, sizeof(CONTROLVM_MESSAGE_HEADER));
memset(&g_ChipSetMsgHdr, 0, sizeof(CONTROLVM_MESSAGE_HEADER));
memset(&g_DelDumpMsgHdr, 0, sizeof(CONTROLVM_MESSAGE_HEADER));
Putfile_buffer_list_pool =
kmem_cache_create(Putfile_buffer_list_pool_name,
sizeof(struct putfile_buffer_entry),
0, SLAB_HWCACHE_ALIGN, NULL);
if (!Putfile_buffer_list_pool) {
ERRDRV("failed to alloc Putfile_buffer_list_pool: (status=-1)\n");
POSTCODE_LINUX_2(CHIPSET_INIT_FAILURE_PC, DIAG_SEVERITY_ERR);
rc = -1;
goto Away;
}
if (visorchipset_disable_controlvm) {
LOGINF("visorchipset_init:controlvm disabled");
} else {
if (visorchipset_crash_kernel)
INIT_DELAYED_WORK(&Periodic_controlvm_work,
setup_crash_devices_work_queue);
else
INIT_DELAYED_WORK(&Periodic_controlvm_work,
controlvm_periodic_work);
Periodic_controlvm_workqueue =
create_singlethread_workqueue("visorchipset_controlvm");
if (Periodic_controlvm_workqueue == NULL) {
ERRDRV("cannot create controlvm workqueue: (status=%d)\n",
-ENOMEM);
POSTCODE_LINUX_2(CREATE_WORKQUEUE_FAILED_PC,
DIAG_SEVERITY_ERR);
rc = -ENOMEM;
goto Away;
}
Most_recent_message_jiffies = jiffies;
Poll_jiffies = POLLJIFFIES_CONTROLVMCHANNEL_FAST;
rc = queue_delayed_work(Periodic_controlvm_workqueue,
&Periodic_controlvm_work, Poll_jiffies);
if (rc < 0) {
ERRDRV("queue_delayed_work(Periodic_controlvm_workqueue, &Periodic_controlvm_work, Poll_jiffies): error (status=%d)\n", rc);
POSTCODE_LINUX_2(QUEUE_DELAYED_WORK_PC,
DIAG_SEVERITY_ERR);
goto Away;
}
}
Visorchipset_platform_device.dev.devt = MajorDev;
if (platform_device_register(&Visorchipset_platform_device) < 0) {
ERRDRV("platform_device_register(visorchipset) failed: (status=-1)\n");
POSTCODE_LINUX_2(DEVICE_REGISTER_FAILURE_PC, DIAG_SEVERITY_ERR);
rc = -1;
goto Away;
}
LOGINF("visorchipset device created");
POSTCODE_LINUX_2(CHIPSET_INIT_SUCCESS_PC, POSTCODE_SEVERITY_INFO);
rc = 0;
Away:
if (rc) {
LOGERR("visorchipset_init failed");
POSTCODE_LINUX_3(CHIPSET_INIT_FAILURE_PC, rc,
POSTCODE_SEVERITY_ERR);
}
return rc;
}
static void
visorchipset_exit(void)
{
char s[99];
POSTCODE_LINUX_2(DRIVER_EXIT_PC, POSTCODE_SEVERITY_INFO);
if (visorchipset_disable_controlvm) {
;
} else {
cancel_delayed_work(&Periodic_controlvm_work);
flush_workqueue(Periodic_controlvm_workqueue);
destroy_workqueue(Periodic_controlvm_workqueue);
Periodic_controlvm_workqueue = NULL;
destroy_controlvm_payload_info(&ControlVm_payload_info);
}
Test_Vnic_channel = NULL;
if (Putfile_buffer_list_pool) {
kmem_cache_destroy(Putfile_buffer_list_pool);
Putfile_buffer_list_pool = NULL;
}
cleanup_controlvm_structures();
memset(&g_DiagMsgHdr, 0, sizeof(CONTROLVM_MESSAGE_HEADER));
memset(&g_ChipSetMsgHdr, 0, sizeof(CONTROLVM_MESSAGE_HEADER));
memset(&g_DelDumpMsgHdr, 0, sizeof(CONTROLVM_MESSAGE_HEADER));
LOGINF("Channel %s (ControlVm) disconnected",
visorchannel_id(ControlVm_channel, s));
visorchannel_destroy(ControlVm_channel);
visorchipset_file_cleanup();
POSTCODE_LINUX_2(DRIVER_EXIT_PC, POSTCODE_SEVERITY_INFO);
LOGINF("chipset driver unloaded");
}
