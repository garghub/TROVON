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
u8 tool_action;
visorchannel_read(controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
tool_action), &tool_action, sizeof(u8));
return scnprintf(buf, PAGE_SIZE, "%u\n", tool_action);
}
static ssize_t toolaction_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
u8 tool_action;
int ret;
if (kstrtou8(buf, 10, &tool_action) != 0)
return -EINVAL;
ret = visorchannel_write(controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
tool_action),
&tool_action, sizeof(u8));
if (ret)
return ret;
return count;
}
static ssize_t boottotool_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct efi_spar_indication efi_spar_indication;
visorchannel_read(controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
efi_spar_ind), &efi_spar_indication,
sizeof(struct efi_spar_indication));
return scnprintf(buf, PAGE_SIZE, "%u\n",
efi_spar_indication.boot_to_tool);
}
static ssize_t boottotool_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int val, ret;
struct efi_spar_indication efi_spar_indication;
if (kstrtoint(buf, 10, &val) != 0)
return -EINVAL;
efi_spar_indication.boot_to_tool = val;
ret = visorchannel_write(controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
efi_spar_ind), &(efi_spar_indication),
sizeof(struct efi_spar_indication));
if (ret)
return ret;
return count;
}
static ssize_t error_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
u32 error;
visorchannel_read(controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
installation_error),
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
ret = visorchannel_write(controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
installation_error),
&error, sizeof(u32));
if (ret)
return ret;
return count;
}
static ssize_t textid_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
u32 text_id;
visorchannel_read(controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
installation_text_id),
&text_id, sizeof(u32));
return scnprintf(buf, PAGE_SIZE, "%i\n", text_id);
}
static ssize_t textid_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
u32 text_id;
int ret;
if (kstrtou32(buf, 10, &text_id) != 0)
return -EINVAL;
ret = visorchannel_write(controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
installation_text_id),
&text_id, sizeof(u32));
if (ret)
return ret;
return count;
}
static ssize_t remaining_steps_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
u16 remaining_steps;
visorchannel_read(controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
installation_remaining_steps),
&remaining_steps, sizeof(u16));
return scnprintf(buf, PAGE_SIZE, "%hu\n", remaining_steps);
}
static ssize_t remaining_steps_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
u16 remaining_steps;
int ret;
if (kstrtou16(buf, 10, &remaining_steps) != 0)
return -EINVAL;
ret = visorchannel_write(controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
installation_remaining_steps),
&remaining_steps, sizeof(u16));
if (ret)
return ret;
return count;
}
static void
bus_info_clear(void *v)
{
struct visorchipset_bus_info *p = (struct visorchipset_bus_info *) (v);
kfree(p->name);
p->name = NULL;
kfree(p->description);
p->description = NULL;
p->state.created = 0;
memset(p, 0, sizeof(struct visorchipset_bus_info));
}
static void
dev_info_clear(void *v)
{
struct visorchipset_device_info *p =
(struct visorchipset_device_info *)(v);
p->state.created = 0;
memset(p, 0, sizeof(struct visorchipset_device_info));
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
visorchipset_register_busdev_server(
struct visorchipset_busdev_notifiers *notifiers,
struct visorchipset_busdev_responders *responders,
struct ultra_vbus_deviceinfo *driver_info)
{
down(&notifier_lock);
if (!notifiers) {
memset(&busdev_server_notifiers, 0,
sizeof(busdev_server_notifiers));
serverregistered = 0;
} else {
busdev_server_notifiers = *notifiers;
serverregistered = 1;
}
if (responders)
*responders = busdev_responders;
if (driver_info)
bus_device_info_init(driver_info, "chipset", "visorchipset",
VERSION, NULL);
up(&notifier_lock);
}
void
visorchipset_register_busdev_client(
struct visorchipset_busdev_notifiers *notifiers,
struct visorchipset_busdev_responders *responders,
struct ultra_vbus_deviceinfo *driver_info)
{
down(&notifier_lock);
if (!notifiers) {
memset(&busdev_client_notifiers, 0,
sizeof(busdev_client_notifiers));
clientregistered = 0;
} else {
busdev_client_notifiers = *notifiers;
clientregistered = 1;
}
if (responders)
*responders = busdev_responders;
if (driver_info)
bus_device_info_init(driver_info, "chipset(bolts)",
"visorchipset", VERSION, NULL);
up(&notifier_lock);
}
static void
cleanup_controlvm_structures(void)
{
struct visorchipset_bus_info *bi, *tmp_bi;
struct visorchipset_device_info *di, *tmp_di;
list_for_each_entry_safe(bi, tmp_bi, &bus_info_list, entry) {
bus_info_clear(bi);
list_del(&bi->entry);
kfree(bi);
}
list_for_each_entry_safe(di, tmp_di, &dev_info_list, entry) {
dev_info_clear(di);
list_del(&di->entry);
kfree(di);
}
}
static void
chipset_init(struct controlvm_message *inmsg)
{
static int chipset_inited;
enum ultra_chipset_feature features = 0;
int rc = CONTROLVM_RESP_SUCCESS;
POSTCODE_LINUX_2(CHIPSET_INIT_ENTRY_PC, POSTCODE_SEVERITY_INFO);
if (chipset_inited) {
rc = -CONTROLVM_RESP_ERROR_ALREADY_DONE;
goto cleanup;
}
chipset_inited = 1;
POSTCODE_LINUX_2(CHIPSET_INIT_EXIT_PC, POSTCODE_SEVERITY_INFO);
features =
inmsg->cmd.init_chipset.
features & ULTRA_CHIPSET_FEATURE_PARA_HOTPLUG;
features |= ULTRA_CHIPSET_FEATURE_REPLY;
cleanup:
if (rc < 0)
cleanup_controlvm_structures();
if (inmsg->hdr.flags.response_expected)
controlvm_respond_chipset_init(&inmsg->hdr, rc, features);
}
static void
controlvm_init_response(struct controlvm_message *msg,
struct controlvm_message_header *msg_hdr, int response)
{
memset(msg, 0, sizeof(struct controlvm_message));
memcpy(&msg->hdr, msg_hdr, sizeof(struct controlvm_message_header));
msg->hdr.payload_bytes = 0;
msg->hdr.payload_vm_offset = 0;
msg->hdr.payload_max_bytes = 0;
if (response < 0) {
msg->hdr.flags.failed = 1;
msg->hdr.completion_status = (u32) (-response);
}
}
static void
controlvm_respond(struct controlvm_message_header *msg_hdr, int response)
{
struct controlvm_message outmsg;
controlvm_init_response(&outmsg, msg_hdr, response);
if (msg_hdr->id == CONTROLVM_DEVICE_CHANGESTATE &&
g_devicechangestate_packet.device_change_state.bus_no ==
g_diagpool_bus_no &&
g_devicechangestate_packet.device_change_state.dev_no ==
g_diagpool_dev_no)
outmsg.cmd = g_devicechangestate_packet;
if (outmsg.hdr.flags.test_message == 1)
return;
if (!visorchannel_signalinsert(controlvm_channel,
CONTROLVM_QUEUE_REQUEST, &outmsg)) {
return;
}
}
static void
controlvm_respond_chipset_init(struct controlvm_message_header *msg_hdr,
int response,
enum ultra_chipset_feature features)
{
struct controlvm_message outmsg;
controlvm_init_response(&outmsg, msg_hdr, response);
outmsg.cmd.init_chipset.features = features;
if (!visorchannel_signalinsert(controlvm_channel,
CONTROLVM_QUEUE_REQUEST, &outmsg)) {
return;
}
}
static void controlvm_respond_physdev_changestate(
struct controlvm_message_header *msg_hdr, int response,
struct spar_segment_state state)
{
struct controlvm_message outmsg;
controlvm_init_response(&outmsg, msg_hdr, response);
outmsg.cmd.device_change_state.state = state;
outmsg.cmd.device_change_state.flags.phys_device = 1;
if (!visorchannel_signalinsert(controlvm_channel,
CONTROLVM_QUEUE_REQUEST, &outmsg)) {
return;
}
}
void
visorchipset_save_message(struct controlvm_message *msg,
enum crash_obj_type type)
{
u32 crash_msg_offset;
u16 crash_msg_count;
if (visorchannel_read(controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
saved_crash_message_count),
&crash_msg_count, sizeof(u16)) < 0) {
POSTCODE_LINUX_2(CRASH_DEV_CTRL_RD_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
if (crash_msg_count != CONTROLVM_CRASHMSG_MAX) {
POSTCODE_LINUX_3(CRASH_DEV_COUNT_FAILURE_PC,
crash_msg_count,
POSTCODE_SEVERITY_ERR);
return;
}
if (visorchannel_read(controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
saved_crash_message_offset),
&crash_msg_offset, sizeof(u32)) < 0) {
POSTCODE_LINUX_2(CRASH_DEV_CTRL_RD_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
if (type == CRASH_BUS) {
if (visorchannel_write(controlvm_channel,
crash_msg_offset,
msg,
sizeof(struct controlvm_message)) < 0) {
POSTCODE_LINUX_2(SAVE_MSG_BUS_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
} else {
if (visorchannel_write(controlvm_channel,
crash_msg_offset +
sizeof(struct controlvm_message), msg,
sizeof(struct controlvm_message)) < 0) {
POSTCODE_LINUX_2(SAVE_MSG_DEV_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
}
}
static void
bus_responder(enum controlvm_id cmd_id, ulong bus_no, int response)
{
struct visorchipset_bus_info *p = NULL;
BOOL need_clear = FALSE;
p = findbus(&bus_info_list, bus_no);
if (!p)
return;
if (response < 0) {
if ((cmd_id == CONTROLVM_BUS_CREATE) &&
(response != (-CONTROLVM_RESP_ERROR_ALREADY_DONE)))
delbusdevices(&dev_info_list, bus_no);
} else {
if (cmd_id == CONTROLVM_BUS_CREATE)
p->state.created = 1;
if (cmd_id == CONTROLVM_BUS_DESTROY)
need_clear = TRUE;
}
if (p->pending_msg_hdr.id == CONTROLVM_INVALID)
return;
if (p->pending_msg_hdr.id != (u32)cmd_id)
return;
controlvm_respond(&p->pending_msg_hdr, response);
p->pending_msg_hdr.id = CONTROLVM_INVALID;
if (need_clear) {
bus_info_clear(p);
delbusdevices(&dev_info_list, bus_no);
}
}
static void
device_changestate_responder(enum controlvm_id cmd_id,
ulong bus_no, ulong dev_no, int response,
struct spar_segment_state response_state)
{
struct visorchipset_device_info *p = NULL;
struct controlvm_message outmsg;
p = finddevice(&dev_info_list, bus_no, dev_no);
if (!p)
return;
if (p->pending_msg_hdr.id == CONTROLVM_INVALID)
return;
if (p->pending_msg_hdr.id != cmd_id)
return;
controlvm_init_response(&outmsg, &p->pending_msg_hdr, response);
outmsg.cmd.device_change_state.bus_no = bus_no;
outmsg.cmd.device_change_state.dev_no = dev_no;
outmsg.cmd.device_change_state.state = response_state;
if (!visorchannel_signalinsert(controlvm_channel,
CONTROLVM_QUEUE_REQUEST, &outmsg))
return;
p->pending_msg_hdr.id = CONTROLVM_INVALID;
}
static void
device_responder(enum controlvm_id cmd_id, ulong bus_no, ulong dev_no,
int response)
{
struct visorchipset_device_info *p = NULL;
BOOL need_clear = FALSE;
p = finddevice(&dev_info_list, bus_no, dev_no);
if (!p)
return;
if (response >= 0) {
if (cmd_id == CONTROLVM_DEVICE_CREATE)
p->state.created = 1;
if (cmd_id == CONTROLVM_DEVICE_DESTROY)
need_clear = TRUE;
}
if (p->pending_msg_hdr.id == CONTROLVM_INVALID)
return;
if (p->pending_msg_hdr.id != (u32)cmd_id)
return;
controlvm_respond(&p->pending_msg_hdr, response);
p->pending_msg_hdr.id = CONTROLVM_INVALID;
if (need_clear)
dev_info_clear(p);
}
static void
bus_epilog(u32 bus_no,
u32 cmd, struct controlvm_message_header *msg_hdr,
int response, BOOL need_response)
{
BOOL notified = FALSE;
struct visorchipset_bus_info *bus_info = findbus(&bus_info_list,
bus_no);
if (!bus_info)
return;
if (need_response) {
memcpy(&bus_info->pending_msg_hdr, msg_hdr,
sizeof(struct controlvm_message_header));
} else {
bus_info->pending_msg_hdr.id = CONTROLVM_INVALID;
}
down(&notifier_lock);
if (response == CONTROLVM_RESP_SUCCESS) {
switch (cmd) {
case CONTROLVM_BUS_CREATE:
if (busdev_server_notifiers.bus_create) {
(*busdev_server_notifiers.bus_create) (bus_no);
notified = TRUE;
}
if ((!bus_info->flags.server) &&
busdev_client_notifiers.bus_create) {
(*busdev_client_notifiers.bus_create) (bus_no);
notified = TRUE;
}
break;
case CONTROLVM_BUS_DESTROY:
if (busdev_server_notifiers.bus_destroy) {
(*busdev_server_notifiers.bus_destroy) (bus_no);
notified = TRUE;
}
if ((!bus_info->flags.server) &&
busdev_client_notifiers.bus_destroy) {
(*busdev_client_notifiers.bus_destroy) (bus_no);
notified = TRUE;
}
break;
}
}
if (notified)
;
else
bus_responder(cmd, bus_no, response);
up(&notifier_lock);
}
static void
device_epilog(u32 bus_no, u32 dev_no, struct spar_segment_state state, u32 cmd,
struct controlvm_message_header *msg_hdr, int response,
BOOL need_response, BOOL for_visorbus)
{
struct visorchipset_busdev_notifiers *notifiers = NULL;
BOOL notified = FALSE;
struct visorchipset_device_info *dev_info =
finddevice(&dev_info_list, bus_no, dev_no);
char *envp[] = {
"SPARSP_DIAGPOOL_PAUSED_STATE = 1",
NULL
};
if (!dev_info)
return;
if (for_visorbus)
notifiers = &busdev_server_notifiers;
else
notifiers = &busdev_client_notifiers;
if (need_response) {
memcpy(&dev_info->pending_msg_hdr, msg_hdr,
sizeof(struct controlvm_message_header));
} else {
dev_info->pending_msg_hdr.id = CONTROLVM_INVALID;
}
down(&notifier_lock);
if (response >= 0) {
switch (cmd) {
case CONTROLVM_DEVICE_CREATE:
if (notifiers->device_create) {
(*notifiers->device_create) (bus_no, dev_no);
notified = TRUE;
}
break;
case CONTROLVM_DEVICE_CHANGESTATE:
if (state.alive == segment_state_running.alive &&
state.operating ==
segment_state_running.operating) {
if (notifiers->device_resume) {
(*notifiers->device_resume) (bus_no,
dev_no);
notified = TRUE;
}
}
else if (state.alive == segment_state_standby.alive &&
state.operating ==
segment_state_standby.operating) {
if (notifiers->device_pause) {
(*notifiers->device_pause) (bus_no,
dev_no);
notified = TRUE;
}
} else if (state.alive == segment_state_paused.alive &&
state.operating ==
segment_state_paused.operating) {
if (bus_no == g_diagpool_bus_no &&
dev_no == g_diagpool_dev_no) {
kobject_uevent_env
(&visorchipset_platform_device.dev.
kobj, KOBJ_ONLINE, envp);
}
}
break;
case CONTROLVM_DEVICE_DESTROY:
if (notifiers->device_destroy) {
(*notifiers->device_destroy) (bus_no, dev_no);
notified = TRUE;
}
break;
}
}
if (notified)
;
else
device_responder(cmd, bus_no, dev_no, response);
up(&notifier_lock);
}
static void
bus_create(struct controlvm_message *inmsg)
{
struct controlvm_message_packet *cmd = &inmsg->cmd;
ulong bus_no = cmd->create_bus.bus_no;
int rc = CONTROLVM_RESP_SUCCESS;
struct visorchipset_bus_info *bus_info = NULL;
bus_info = findbus(&bus_info_list, bus_no);
if (bus_info && (bus_info->state.created == 1)) {
POSTCODE_LINUX_3(BUS_CREATE_FAILURE_PC, bus_no,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_ALREADY_DONE;
goto cleanup;
}
bus_info = kzalloc(sizeof(*bus_info), GFP_KERNEL);
if (!bus_info) {
POSTCODE_LINUX_3(BUS_CREATE_FAILURE_PC, bus_no,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_KMALLOC_FAILED;
goto cleanup;
}
INIT_LIST_HEAD(&bus_info->entry);
bus_info->bus_no = bus_no;
bus_info->dev_no = cmd->create_bus.dev_count;
POSTCODE_LINUX_3(BUS_CREATE_ENTRY_PC, bus_no, POSTCODE_SEVERITY_INFO);
if (inmsg->hdr.flags.test_message == 1)
bus_info->chan_info.addr_type = ADDRTYPE_LOCALTEST;
else
bus_info->chan_info.addr_type = ADDRTYPE_LOCALPHYSICAL;
bus_info->flags.server = inmsg->hdr.flags.server;
bus_info->chan_info.channel_addr = cmd->create_bus.channel_addr;
bus_info->chan_info.n_channel_bytes = cmd->create_bus.channel_bytes;
bus_info->chan_info.channel_type_uuid =
cmd->create_bus.bus_data_type_uuid;
bus_info->chan_info.channel_inst_uuid = cmd->create_bus.bus_inst_uuid;
list_add(&bus_info->entry, &bus_info_list);
POSTCODE_LINUX_3(BUS_CREATE_EXIT_PC, bus_no, POSTCODE_SEVERITY_INFO);
cleanup:
bus_epilog(bus_no, CONTROLVM_BUS_CREATE, &inmsg->hdr,
rc, inmsg->hdr.flags.response_expected == 1);
}
static void
bus_destroy(struct controlvm_message *inmsg)
{
struct controlvm_message_packet *cmd = &inmsg->cmd;
ulong bus_no = cmd->destroy_bus.bus_no;
struct visorchipset_bus_info *bus_info;
int rc = CONTROLVM_RESP_SUCCESS;
bus_info = findbus(&bus_info_list, bus_no);
if (!bus_info)
rc = -CONTROLVM_RESP_ERROR_BUS_INVALID;
else if (bus_info->state.created == 0)
rc = -CONTROLVM_RESP_ERROR_ALREADY_DONE;
bus_epilog(bus_no, CONTROLVM_BUS_DESTROY, &inmsg->hdr,
rc, inmsg->hdr.flags.response_expected == 1);
}
static void
bus_configure(struct controlvm_message *inmsg,
struct parser_context *parser_ctx)
{
struct controlvm_message_packet *cmd = &inmsg->cmd;
ulong bus_no = cmd->configure_bus.bus_no;
struct visorchipset_bus_info *bus_info = NULL;
int rc = CONTROLVM_RESP_SUCCESS;
char s[99];
bus_no = cmd->configure_bus.bus_no;
POSTCODE_LINUX_3(BUS_CONFIGURE_ENTRY_PC, bus_no,
POSTCODE_SEVERITY_INFO);
bus_info = findbus(&bus_info_list, bus_no);
if (!bus_info) {
POSTCODE_LINUX_3(BUS_CONFIGURE_FAILURE_PC, bus_no,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_BUS_INVALID;
} else if (bus_info->state.created == 0) {
POSTCODE_LINUX_3(BUS_CONFIGURE_FAILURE_PC, bus_no,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_BUS_INVALID;
} else if (bus_info->pending_msg_hdr.id != CONTROLVM_INVALID) {
POSTCODE_LINUX_3(BUS_CONFIGURE_FAILURE_PC, bus_no,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_MESSAGE_ID_INVALID_FOR_CLIENT;
} else {
bus_info->partition_handle = cmd->configure_bus.guest_handle;
bus_info->partition_uuid = parser_id_get(parser_ctx);
parser_param_start(parser_ctx, PARSERSTRING_NAME);
bus_info->name = parser_string_get(parser_ctx);
visorchannel_uuid_id(&bus_info->partition_uuid, s);
POSTCODE_LINUX_3(BUS_CONFIGURE_EXIT_PC, bus_no,
POSTCODE_SEVERITY_INFO);
}
bus_epilog(bus_no, CONTROLVM_BUS_CONFIGURE, &inmsg->hdr,
rc, inmsg->hdr.flags.response_expected == 1);
}
static void
my_device_create(struct controlvm_message *inmsg)
{
struct controlvm_message_packet *cmd = &inmsg->cmd;
ulong bus_no = cmd->create_device.bus_no;
ulong dev_no = cmd->create_device.dev_no;
struct visorchipset_device_info *dev_info = NULL;
struct visorchipset_bus_info *bus_info = NULL;
int rc = CONTROLVM_RESP_SUCCESS;
dev_info = finddevice(&dev_info_list, bus_no, dev_no);
if (dev_info && (dev_info->state.created == 1)) {
POSTCODE_LINUX_4(DEVICE_CREATE_FAILURE_PC, dev_no, bus_no,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_ALREADY_DONE;
goto cleanup;
}
bus_info = findbus(&bus_info_list, bus_no);
if (!bus_info) {
POSTCODE_LINUX_4(DEVICE_CREATE_FAILURE_PC, dev_no, bus_no,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_BUS_INVALID;
goto cleanup;
}
if (bus_info->state.created == 0) {
POSTCODE_LINUX_4(DEVICE_CREATE_FAILURE_PC, dev_no, bus_no,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_BUS_INVALID;
goto cleanup;
}
dev_info = kzalloc(sizeof(*dev_info), GFP_KERNEL);
if (!dev_info) {
POSTCODE_LINUX_4(DEVICE_CREATE_FAILURE_PC, dev_no, bus_no,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_KMALLOC_FAILED;
goto cleanup;
}
INIT_LIST_HEAD(&dev_info->entry);
dev_info->bus_no = bus_no;
dev_info->dev_no = dev_no;
dev_info->dev_inst_uuid = cmd->create_device.dev_inst_uuid;
POSTCODE_LINUX_4(DEVICE_CREATE_ENTRY_PC, dev_no, bus_no,
POSTCODE_SEVERITY_INFO);
if (inmsg->hdr.flags.test_message == 1)
dev_info->chan_info.addr_type = ADDRTYPE_LOCALTEST;
else
dev_info->chan_info.addr_type = ADDRTYPE_LOCALPHYSICAL;
dev_info->chan_info.channel_addr = cmd->create_device.channel_addr;
dev_info->chan_info.n_channel_bytes = cmd->create_device.channel_bytes;
dev_info->chan_info.channel_type_uuid =
cmd->create_device.data_type_uuid;
dev_info->chan_info.intr = cmd->create_device.intr;
list_add(&dev_info->entry, &dev_info_list);
POSTCODE_LINUX_4(DEVICE_CREATE_EXIT_PC, dev_no, bus_no,
POSTCODE_SEVERITY_INFO);
cleanup:
if (dev_info &&
is_diagpool_channel(dev_info->chan_info.channel_type_uuid)) {
g_diagpool_bus_no = bus_no;
g_diagpool_dev_no = dev_no;
}
device_epilog(bus_no, dev_no, segment_state_running,
CONTROLVM_DEVICE_CREATE, &inmsg->hdr, rc,
inmsg->hdr.flags.response_expected == 1,
FOR_VISORBUS(dev_info->chan_info.channel_type_uuid));
}
static void
my_device_changestate(struct controlvm_message *inmsg)
{
struct controlvm_message_packet *cmd = &inmsg->cmd;
ulong bus_no = cmd->device_change_state.bus_no;
ulong dev_no = cmd->device_change_state.dev_no;
struct spar_segment_state state = cmd->device_change_state.state;
struct visorchipset_device_info *dev_info = NULL;
int rc = CONTROLVM_RESP_SUCCESS;
dev_info = finddevice(&dev_info_list, bus_no, dev_no);
if (!dev_info) {
POSTCODE_LINUX_4(DEVICE_CHANGESTATE_FAILURE_PC, dev_no, bus_no,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_DEVICE_INVALID;
} else if (dev_info->state.created == 0) {
POSTCODE_LINUX_4(DEVICE_CHANGESTATE_FAILURE_PC, dev_no, bus_no,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_DEVICE_INVALID;
}
if ((rc >= CONTROLVM_RESP_SUCCESS) && dev_info)
device_epilog(bus_no, dev_no, state,
CONTROLVM_DEVICE_CHANGESTATE, &inmsg->hdr, rc,
inmsg->hdr.flags.response_expected == 1,
FOR_VISORBUS(
dev_info->chan_info.channel_type_uuid));
}
static void
my_device_destroy(struct controlvm_message *inmsg)
{
struct controlvm_message_packet *cmd = &inmsg->cmd;
ulong bus_no = cmd->destroy_device.bus_no;
ulong dev_no = cmd->destroy_device.dev_no;
struct visorchipset_device_info *dev_info = NULL;
int rc = CONTROLVM_RESP_SUCCESS;
dev_info = finddevice(&dev_info_list, bus_no, dev_no);
if (!dev_info)
rc = -CONTROLVM_RESP_ERROR_DEVICE_INVALID;
else if (dev_info->state.created == 0)
rc = -CONTROLVM_RESP_ERROR_ALREADY_DONE;
if ((rc >= CONTROLVM_RESP_SUCCESS) && dev_info)
device_epilog(bus_no, dev_no, segment_state_running,
CONTROLVM_DEVICE_DESTROY, &inmsg->hdr, rc,
inmsg->hdr.flags.response_expected == 1,
FOR_VISORBUS(
dev_info->chan_info.channel_type_uuid));
}
static int
initialize_controlvm_payload_info(HOSTADDRESS phys_addr, u64 offset, u32 bytes,
struct controlvm_payload_info *info)
{
u8 __iomem *payload = NULL;
int rc = CONTROLVM_RESP_SUCCESS;
if (!info) {
rc = -CONTROLVM_RESP_ERROR_PAYLOAD_INVALID;
goto cleanup;
}
memset(info, 0, sizeof(struct controlvm_payload_info));
if ((offset == 0) || (bytes == 0)) {
rc = -CONTROLVM_RESP_ERROR_PAYLOAD_INVALID;
goto cleanup;
}
payload = ioremap_cache(phys_addr + offset, bytes);
if (!payload) {
rc = -CONTROLVM_RESP_ERROR_IOREMAP_FAILED;
goto cleanup;
}
info->offset = offset;
info->bytes = bytes;
info->ptr = payload;
cleanup:
if (rc < 0) {
if (payload) {
iounmap(payload);
payload = NULL;
}
}
return rc;
}
static void
destroy_controlvm_payload_info(struct controlvm_payload_info *info)
{
if (info->ptr) {
iounmap(info->ptr);
info->ptr = NULL;
}
memset(info, 0, sizeof(struct controlvm_payload_info));
}
static void
initialize_controlvm_payload(void)
{
HOSTADDRESS phys_addr = visorchannel_get_physaddr(controlvm_channel);
u64 payload_offset = 0;
u32 payload_bytes = 0;
if (visorchannel_read(controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
request_payload_offset),
&payload_offset, sizeof(payload_offset)) < 0) {
POSTCODE_LINUX_2(CONTROLVM_INIT_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
if (visorchannel_read(controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
request_payload_bytes),
&payload_bytes, sizeof(payload_bytes)) < 0) {
POSTCODE_LINUX_2(CONTROLVM_INIT_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
initialize_controlvm_payload_info(phys_addr,
payload_offset, payload_bytes,
&controlvm_payload_info);
}
int
visorchipset_chipset_ready(void)
{
kobject_uevent(&visorchipset_platform_device.dev.kobj, KOBJ_ONLINE);
return CONTROLVM_RESP_SUCCESS;
}
int
visorchipset_chipset_selftest(void)
{
char env_selftest[20];
char *envp[] = { env_selftest, NULL };
sprintf(env_selftest, "SPARSP_SELFTEST=%d", 1);
kobject_uevent_env(&visorchipset_platform_device.dev.kobj, KOBJ_CHANGE,
envp);
return CONTROLVM_RESP_SUCCESS;
}
int
visorchipset_chipset_notready(void)
{
kobject_uevent(&visorchipset_platform_device.dev.kobj, KOBJ_OFFLINE);
return CONTROLVM_RESP_SUCCESS;
}
static void
chipset_ready(struct controlvm_message_header *msg_hdr)
{
int rc = visorchipset_chipset_ready();
if (rc != CONTROLVM_RESP_SUCCESS)
rc = -rc;
if (msg_hdr->flags.response_expected && !visorchipset_holdchipsetready)
controlvm_respond(msg_hdr, rc);
if (msg_hdr->flags.response_expected && visorchipset_holdchipsetready) {
g_chipset_msg_hdr = *msg_hdr;
}
}
static void
chipset_selftest(struct controlvm_message_header *msg_hdr)
{
int rc = visorchipset_chipset_selftest();
if (rc != CONTROLVM_RESP_SUCCESS)
rc = -rc;
if (msg_hdr->flags.response_expected)
controlvm_respond(msg_hdr, rc);
}
static void
chipset_notready(struct controlvm_message_header *msg_hdr)
{
int rc = visorchipset_chipset_notready();
if (rc != CONTROLVM_RESP_SUCCESS)
rc = -rc;
if (msg_hdr->flags.response_expected)
controlvm_respond(msg_hdr, rc);
}
static BOOL
read_controlvm_event(struct controlvm_message *msg)
{
if (visorchannel_signalremove(controlvm_channel,
CONTROLVM_QUEUE_EVENT, msg)) {
if (msg->hdr.flags.test_message == 1)
return FALSE;
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
return jiffies + msecs_to_jiffies(PARAHOTPLUG_TIMEOUT_MS);
}
static struct parahotplug_request *
parahotplug_request_create(struct controlvm_message *msg)
{
struct parahotplug_request *req;
req = kmalloc(sizeof(*req), GFP_KERNEL | __GFP_NORETRY);
if (!req)
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
struct controlvm_message_packet *cmd = &req->msg.cmd;
char env_cmd[40], env_id[40], env_state[40], env_bus[40], env_dev[40],
env_func[40];
char *envp[] = {
env_cmd, env_id, env_state, env_bus, env_dev, env_func, NULL
};
sprintf(env_cmd, "SPAR_PARAHOTPLUG=1");
sprintf(env_id, "SPAR_PARAHOTPLUG_ID=%d", req->id);
sprintf(env_state, "SPAR_PARAHOTPLUG_STATE=%d",
cmd->device_change_state.state.active);
sprintf(env_bus, "SPAR_PARAHOTPLUG_BUS=%d",
cmd->device_change_state.bus_no);
sprintf(env_dev, "SPAR_PARAHOTPLUG_DEVICE=%d",
cmd->device_change_state.dev_no >> 3);
sprintf(env_func, "SPAR_PARAHOTPLUG_FUNCTION=%d",
cmd->device_change_state.dev_no & 0x7);
kobject_uevent_env(&visorchipset_platform_device.dev.kobj, KOBJ_CHANGE,
envp);
}
static void
parahotplug_process_list(void)
{
struct list_head *pos = NULL;
struct list_head *tmp = NULL;
spin_lock(&parahotplug_request_list_lock);
list_for_each_safe(pos, tmp, &parahotplug_request_list) {
struct parahotplug_request *req =
list_entry(pos, struct parahotplug_request, list);
if (!time_after_eq(jiffies, req->expiration))
continue;
list_del(pos);
if (req->msg.hdr.flags.response_expected)
controlvm_respond_physdev_changestate(
&req->msg.hdr,
CONTROLVM_RESP_ERROR_DEVICE_UDEV_TIMEOUT,
req->msg.cmd.device_change_state.state);
parahotplug_request_destroy(req);
}
spin_unlock(&parahotplug_request_list_lock);
}
static int
parahotplug_request_complete(int id, u16 active)
{
struct list_head *pos = NULL;
struct list_head *tmp = NULL;
spin_lock(&parahotplug_request_list_lock);
list_for_each_safe(pos, tmp, &parahotplug_request_list) {
struct parahotplug_request *req =
list_entry(pos, struct parahotplug_request, list);
if (req->id == id) {
list_del(pos);
spin_unlock(&parahotplug_request_list_lock);
req->msg.cmd.device_change_state.state.active = active;
if (req->msg.hdr.flags.response_expected)
controlvm_respond_physdev_changestate(
&req->msg.hdr, CONTROLVM_RESP_SUCCESS,
req->msg.cmd.device_change_state.state);
parahotplug_request_destroy(req);
return 0;
}
}
spin_unlock(&parahotplug_request_list_lock);
return -1;
}
static void
parahotplug_process_message(struct controlvm_message *inmsg)
{
struct parahotplug_request *req;
req = parahotplug_request_create(inmsg);
if (!req)
return;
if (inmsg->cmd.device_change_state.state.active) {
parahotplug_request_kickoff(req);
controlvm_respond_physdev_changestate(&inmsg->hdr,
CONTROLVM_RESP_SUCCESS,
inmsg->cmd.device_change_state.state);
parahotplug_request_destroy(req);
} else {
spin_lock(&parahotplug_request_list_lock);
list_add_tail(&req->list, &parahotplug_request_list);
spin_unlock(&parahotplug_request_list_lock);
parahotplug_request_kickoff(req);
}
}
static BOOL
handle_command(struct controlvm_message inmsg, HOSTADDRESS channel_addr)
{
struct controlvm_message_packet *cmd = &inmsg.cmd;
u64 parm_addr = 0;
u32 parm_bytes = 0;
struct parser_context *parser_ctx = NULL;
bool local_addr = false;
struct controlvm_message ackmsg;
local_addr = (inmsg.hdr.flags.test_message == 1);
if (channel_addr == 0)
return TRUE;
parm_addr = channel_addr + inmsg.hdr.payload_vm_offset;
parm_bytes = inmsg.hdr.payload_bytes;
if (parm_addr != 0 && parm_bytes != 0) {
BOOL retry = FALSE;
parser_ctx =
parser_init_byte_stream(parm_addr, parm_bytes,
local_addr, &retry);
if (!parser_ctx && retry)
return FALSE;
}
if (!local_addr) {
controlvm_init_response(&ackmsg, &inmsg.hdr,
CONTROLVM_RESP_SUCCESS);
if (controlvm_channel)
visorchannel_signalinsert(controlvm_channel,
CONTROLVM_QUEUE_ACK,
&ackmsg);
}
switch (inmsg.hdr.id) {
case CONTROLVM_CHIPSET_INIT:
chipset_init(&inmsg);
break;
case CONTROLVM_BUS_CREATE:
bus_create(&inmsg);
break;
case CONTROLVM_BUS_DESTROY:
bus_destroy(&inmsg);
break;
case CONTROLVM_BUS_CONFIGURE:
bus_configure(&inmsg, parser_ctx);
break;
case CONTROLVM_DEVICE_CREATE:
my_device_create(&inmsg);
break;
case CONTROLVM_DEVICE_CHANGESTATE:
if (cmd->device_change_state.flags.phys_device) {
parahotplug_process_message(&inmsg);
} else {
my_device_changestate(&inmsg);
g_diag_msg_hdr = inmsg.hdr;
g_devicechangestate_packet = inmsg.cmd;
break;
}
break;
case CONTROLVM_DEVICE_DESTROY:
my_device_destroy(&inmsg);
break;
case CONTROLVM_DEVICE_CONFIGURE:
if (inmsg.hdr.flags.response_expected)
controlvm_respond(&inmsg.hdr, CONTROLVM_RESP_SUCCESS);
break;
case CONTROLVM_CHIPSET_READY:
chipset_ready(&inmsg.hdr);
break;
case CONTROLVM_CHIPSET_SELFTEST:
chipset_selftest(&inmsg.hdr);
break;
case CONTROLVM_CHIPSET_STOP:
chipset_notready(&inmsg.hdr);
break;
default:
if (inmsg.hdr.flags.response_expected)
controlvm_respond(&inmsg.hdr,
-CONTROLVM_RESP_ERROR_MESSAGE_ID_UNKNOWN);
break;
}
if (parser_ctx) {
parser_done(parser_ctx);
parser_ctx = NULL;
}
return TRUE;
}
static HOSTADDRESS controlvm_get_channel_address(void)
{
u64 addr = 0;
u32 size = 0;
if (!VMCALL_SUCCESSFUL(issue_vmcall_io_controlvm_addr(&addr, &size)))
return 0;
return addr;
}
static void
controlvm_periodic_work(struct work_struct *work)
{
struct controlvm_message inmsg;
BOOL got_command = FALSE;
BOOL handle_command_failed = FALSE;
static u64 poll_count;
if (visorchipset_serverregwait && !serverregistered)
goto cleanup;
if (visorchipset_clientregwait && !clientregistered)
goto cleanup;
poll_count++;
if (poll_count >= 250)
;
else
goto cleanup;
if (visorchipset_holdchipsetready &&
(g_chipset_msg_hdr.id != CONTROLVM_INVALID)) {
if (check_chipset_events() == 1) {
controlvm_respond(&g_chipset_msg_hdr, 0);
clear_chipset_events();
memset(&g_chipset_msg_hdr, 0,
sizeof(struct controlvm_message_header));
}
}
while (visorchannel_signalremove(controlvm_channel,
CONTROLVM_QUEUE_RESPONSE,
&inmsg))
;
if (!got_command) {
if (controlvm_pending_msg_valid) {
inmsg = controlvm_pending_msg;
controlvm_pending_msg_valid = FALSE;
got_command = true;
} else {
got_command = read_controlvm_event(&inmsg);
}
}
handle_command_failed = FALSE;
while (got_command && (!handle_command_failed)) {
most_recent_message_jiffies = jiffies;
if (handle_command(inmsg,
visorchannel_get_physaddr
(controlvm_channel)))
got_command = read_controlvm_event(&inmsg);
else {
handle_command_failed = TRUE;
controlvm_pending_msg = inmsg;
controlvm_pending_msg_valid = TRUE;
}
}
parahotplug_process_list();
cleanup:
if (time_after(jiffies,
most_recent_message_jiffies + (HZ * MIN_IDLE_SECONDS))) {
if (poll_jiffies != POLLJIFFIES_CONTROLVMCHANNEL_SLOW)
poll_jiffies = POLLJIFFIES_CONTROLVMCHANNEL_SLOW;
} else {
if (poll_jiffies != POLLJIFFIES_CONTROLVMCHANNEL_FAST)
poll_jiffies = POLLJIFFIES_CONTROLVMCHANNEL_FAST;
}
queue_delayed_work(periodic_controlvm_workqueue,
&periodic_controlvm_work, poll_jiffies);
}
static void
setup_crash_devices_work_queue(struct work_struct *work)
{
struct controlvm_message local_crash_bus_msg;
struct controlvm_message local_crash_dev_msg;
struct controlvm_message msg;
u32 local_crash_msg_offset;
u16 local_crash_msg_count;
if (visorchipset_serverregwait && !serverregistered)
goto cleanup;
if (visorchipset_clientregwait && !clientregistered)
goto cleanup;
POSTCODE_LINUX_2(CRASH_DEV_ENTRY_PC, POSTCODE_SEVERITY_INFO);
msg.hdr.id = CONTROLVM_CHIPSET_INIT;
msg.cmd.init_chipset.bus_count = 23;
msg.cmd.init_chipset.switch_count = 0;
chipset_init(&msg);
if (visorchannel_read(controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
saved_crash_message_count),
&local_crash_msg_count, sizeof(u16)) < 0) {
POSTCODE_LINUX_2(CRASH_DEV_CTRL_RD_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
if (local_crash_msg_count != CONTROLVM_CRASHMSG_MAX) {
POSTCODE_LINUX_3(CRASH_DEV_COUNT_FAILURE_PC,
local_crash_msg_count,
POSTCODE_SEVERITY_ERR);
return;
}
if (visorchannel_read(controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
saved_crash_message_offset),
&local_crash_msg_offset, sizeof(u32)) < 0) {
POSTCODE_LINUX_2(CRASH_DEV_CTRL_RD_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
if (visorchannel_read(controlvm_channel,
local_crash_msg_offset,
&local_crash_bus_msg,
sizeof(struct controlvm_message)) < 0) {
POSTCODE_LINUX_2(CRASH_DEV_RD_BUS_FAIULRE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
if (visorchannel_read(controlvm_channel,
local_crash_msg_offset +
sizeof(struct controlvm_message),
&local_crash_dev_msg,
sizeof(struct controlvm_message)) < 0) {
POSTCODE_LINUX_2(CRASH_DEV_RD_DEV_FAIULRE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
if (local_crash_bus_msg.cmd.create_bus.channel_addr != 0) {
bus_create(&local_crash_bus_msg);
} else {
POSTCODE_LINUX_2(CRASH_DEV_BUS_NULL_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
if (local_crash_dev_msg.cmd.create_device.channel_addr != 0) {
my_device_create(&local_crash_dev_msg);
} else {
POSTCODE_LINUX_2(CRASH_DEV_DEV_NULL_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
POSTCODE_LINUX_2(CRASH_DEV_EXIT_PC, POSTCODE_SEVERITY_INFO);
return;
cleanup:
poll_jiffies = POLLJIFFIES_CONTROLVMCHANNEL_SLOW;
queue_delayed_work(periodic_controlvm_workqueue,
&periodic_controlvm_work, poll_jiffies);
}
static void
bus_create_response(ulong bus_no, int response)
{
bus_responder(CONTROLVM_BUS_CREATE, bus_no, response);
}
static void
bus_destroy_response(ulong bus_no, int response)
{
bus_responder(CONTROLVM_BUS_DESTROY, bus_no, response);
}
static void
device_create_response(ulong bus_no, ulong dev_no, int response)
{
device_responder(CONTROLVM_DEVICE_CREATE, bus_no, dev_no, response);
}
static void
device_destroy_response(ulong bus_no, ulong dev_no, int response)
{
device_responder(CONTROLVM_DEVICE_DESTROY, bus_no, dev_no, response);
}
void
visorchipset_device_pause_response(ulong bus_no, ulong dev_no, int response)
{
device_changestate_responder(CONTROLVM_DEVICE_CHANGESTATE,
bus_no, dev_no, response,
segment_state_standby);
}
static void
device_resume_response(ulong bus_no, ulong dev_no, int response)
{
device_changestate_responder(CONTROLVM_DEVICE_CHANGESTATE,
bus_no, dev_no, response,
segment_state_running);
}
BOOL
visorchipset_get_bus_info(ulong bus_no, struct visorchipset_bus_info *bus_info)
{
void *p = findbus(&bus_info_list, bus_no);
if (!p)
return FALSE;
memcpy(bus_info, p, sizeof(struct visorchipset_bus_info));
return TRUE;
}
BOOL
visorchipset_set_bus_context(ulong bus_no, void *context)
{
struct visorchipset_bus_info *p = findbus(&bus_info_list, bus_no);
if (!p)
return FALSE;
p->bus_driver_context = context;
return TRUE;
}
BOOL
visorchipset_get_device_info(ulong bus_no, ulong dev_no,
struct visorchipset_device_info *dev_info)
{
void *p = finddevice(&dev_info_list, bus_no, dev_no);
if (!p)
return FALSE;
memcpy(dev_info, p, sizeof(struct visorchipset_device_info));
return TRUE;
}
BOOL
visorchipset_set_device_context(ulong bus_no, ulong dev_no, void *context)
{
struct visorchipset_device_info *p =
finddevice(&dev_info_list, bus_no, dev_no);
if (!p)
return FALSE;
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
if (!p)
return NULL;
atomic_inc(&visorchipset_cache_buffers_in_use);
return p;
}
void
visorchipset_cache_free(struct kmem_cache *pool, void *p, char *fn, int ln)
{
if (!p)
return;
atomic_dec(&visorchipset_cache_buffers_in_use);
kmem_cache_free(pool, p);
}
static ssize_t chipsetready_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
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
struct device_attribute *attr,
const char *buf, size_t count)
{
uint id;
if (kstrtouint(buf, 10, &id) != 0)
return -EINVAL;
parahotplug_request_complete(id, 0);
return count;
}
static ssize_t deviceenabled_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
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
HOSTADDRESS addr;
if (!unisys_spar_platform)
return -ENODEV;
memset(&busdev_server_notifiers, 0, sizeof(busdev_server_notifiers));
memset(&busdev_client_notifiers, 0, sizeof(busdev_client_notifiers));
memset(&controlvm_payload_info, 0, sizeof(controlvm_payload_info));
memset(&livedump_info, 0, sizeof(livedump_info));
atomic_set(&livedump_info.buffers_in_use, 0);
if (visorchipset_testvnic) {
POSTCODE_LINUX_3(CHIPSET_INIT_FAILURE_PC, x, DIAG_SEVERITY_ERR);
rc = x;
goto cleanup;
}
addr = controlvm_get_channel_address();
if (addr != 0) {
controlvm_channel =
visorchannel_create_with_lock
(addr,
sizeof(struct spar_controlvm_channel_protocol),
spar_controlvm_channel_protocol_uuid);
if (SPAR_CONTROLVM_CHANNEL_OK_CLIENT(
visorchannel_get_header(controlvm_channel))) {
initialize_controlvm_payload();
} else {
visorchannel_destroy(controlvm_channel);
controlvm_channel = NULL;
return -ENODEV;
}
} else {
return -ENODEV;
}
major_dev = MKDEV(visorchipset_major, 0);
rc = visorchipset_file_init(major_dev, &controlvm_channel);
if (rc < 0) {
POSTCODE_LINUX_2(CHIPSET_INIT_FAILURE_PC, DIAG_SEVERITY_ERR);
goto cleanup;
}
memset(&g_diag_msg_hdr, 0, sizeof(struct controlvm_message_header));
memset(&g_chipset_msg_hdr, 0, sizeof(struct controlvm_message_header));
memset(&g_del_dump_msg_hdr, 0, sizeof(struct controlvm_message_header));
putfile_buffer_list_pool =
kmem_cache_create(putfile_buffer_list_pool_name,
sizeof(struct putfile_buffer_entry),
0, SLAB_HWCACHE_ALIGN, NULL);
if (!putfile_buffer_list_pool) {
POSTCODE_LINUX_2(CHIPSET_INIT_FAILURE_PC, DIAG_SEVERITY_ERR);
rc = -1;
goto cleanup;
}
if (!visorchipset_disable_controlvm) {
if (visorchipset_crash_kernel)
INIT_DELAYED_WORK(&periodic_controlvm_work,
setup_crash_devices_work_queue);
else
INIT_DELAYED_WORK(&periodic_controlvm_work,
controlvm_periodic_work);
periodic_controlvm_workqueue =
create_singlethread_workqueue("visorchipset_controlvm");
if (!periodic_controlvm_workqueue) {
POSTCODE_LINUX_2(CREATE_WORKQUEUE_FAILED_PC,
DIAG_SEVERITY_ERR);
rc = -ENOMEM;
goto cleanup;
}
most_recent_message_jiffies = jiffies;
poll_jiffies = POLLJIFFIES_CONTROLVMCHANNEL_FAST;
rc = queue_delayed_work(periodic_controlvm_workqueue,
&periodic_controlvm_work, poll_jiffies);
if (rc < 0) {
POSTCODE_LINUX_2(QUEUE_DELAYED_WORK_PC,
DIAG_SEVERITY_ERR);
goto cleanup;
}
}
visorchipset_platform_device.dev.devt = major_dev;
if (platform_device_register(&visorchipset_platform_device) < 0) {
POSTCODE_LINUX_2(DEVICE_REGISTER_FAILURE_PC, DIAG_SEVERITY_ERR);
rc = -1;
goto cleanup;
}
POSTCODE_LINUX_2(CHIPSET_INIT_SUCCESS_PC, POSTCODE_SEVERITY_INFO);
rc = 0;
cleanup:
if (rc) {
POSTCODE_LINUX_3(CHIPSET_INIT_FAILURE_PC, rc,
POSTCODE_SEVERITY_ERR);
}
return rc;
}
static void
visorchipset_exit(void)
{
POSTCODE_LINUX_2(DRIVER_EXIT_PC, POSTCODE_SEVERITY_INFO);
if (visorchipset_disable_controlvm) {
;
} else {
cancel_delayed_work(&periodic_controlvm_work);
flush_workqueue(periodic_controlvm_workqueue);
destroy_workqueue(periodic_controlvm_workqueue);
periodic_controlvm_workqueue = NULL;
destroy_controlvm_payload_info(&controlvm_payload_info);
}
if (putfile_buffer_list_pool) {
kmem_cache_destroy(putfile_buffer_list_pool);
putfile_buffer_list_pool = NULL;
}
cleanup_controlvm_structures();
memset(&g_diag_msg_hdr, 0, sizeof(struct controlvm_message_header));
memset(&g_chipset_msg_hdr, 0, sizeof(struct controlvm_message_header));
memset(&g_del_dump_msg_hdr, 0, sizeof(struct controlvm_message_header));
visorchannel_destroy(controlvm_channel);
visorchipset_file_cleanup(visorchipset_platform_device.dev.devt);
POSTCODE_LINUX_2(DRIVER_EXIT_PC, POSTCODE_SEVERITY_INFO);
}
