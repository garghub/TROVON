static int
visorchipset_open(struct inode *inode, struct file *file)
{
unsigned minor_number = iminor(inode);
if (minor_number)
return -ENODEV;
file->private_data = NULL;
return 0;
}
static int
visorchipset_release(struct inode *inode, struct file *file)
{
return 0;
}
static void visorchipset_dev_release(struct device *dev)
{
}
static struct parser_context *
parser_init_byte_stream(u64 addr, u32 bytes, bool local, bool *retry)
{
int allocbytes = sizeof(struct parser_context) + bytes;
struct parser_context *rc = NULL;
struct parser_context *ctx = NULL;
if (retry)
*retry = false;
allocbytes++;
if ((controlvm_payload_bytes_buffered + bytes)
> MAX_CONTROLVM_PAYLOAD_BYTES) {
if (retry)
*retry = true;
rc = NULL;
goto cleanup;
}
ctx = kzalloc(allocbytes, GFP_KERNEL | __GFP_NORETRY);
if (!ctx) {
if (retry)
*retry = true;
rc = NULL;
goto cleanup;
}
ctx->allocbytes = allocbytes;
ctx->param_bytes = bytes;
ctx->curr = NULL;
ctx->bytes_remaining = 0;
ctx->byte_stream = false;
if (local) {
void *p;
if (addr > virt_to_phys(high_memory - 1)) {
rc = NULL;
goto cleanup;
}
p = __va((unsigned long)(addr));
memcpy(ctx->data, p, bytes);
} else {
void *mapping = memremap(addr, bytes, MEMREMAP_WB);
if (!mapping) {
rc = NULL;
goto cleanup;
}
memcpy(ctx->data, mapping, bytes);
memunmap(mapping);
}
ctx->byte_stream = true;
rc = ctx;
cleanup:
if (rc) {
controlvm_payload_bytes_buffered += ctx->param_bytes;
} else {
if (ctx) {
parser_done(ctx);
ctx = NULL;
}
}
return rc;
}
static uuid_le
parser_id_get(struct parser_context *ctx)
{
struct spar_controlvm_parameters_header *phdr = NULL;
if (!ctx)
return NULL_UUID_LE;
phdr = (struct spar_controlvm_parameters_header *)(ctx->data);
return phdr->id;
}
static void
parser_param_start(struct parser_context *ctx,
enum PARSER_WHICH_STRING which_string)
{
struct spar_controlvm_parameters_header *phdr = NULL;
if (!ctx)
return;
phdr = (struct spar_controlvm_parameters_header *)(ctx->data);
switch (which_string) {
case PARSERSTRING_INITIATOR:
ctx->curr = ctx->data + phdr->initiator_offset;
ctx->bytes_remaining = phdr->initiator_length;
break;
case PARSERSTRING_TARGET:
ctx->curr = ctx->data + phdr->target_offset;
ctx->bytes_remaining = phdr->target_length;
break;
case PARSERSTRING_CONNECTION:
ctx->curr = ctx->data + phdr->connection_offset;
ctx->bytes_remaining = phdr->connection_length;
break;
case PARSERSTRING_NAME:
ctx->curr = ctx->data + phdr->name_offset;
ctx->bytes_remaining = phdr->name_length;
break;
default:
break;
}
}
static void parser_done(struct parser_context *ctx)
{
if (!ctx)
return;
controlvm_payload_bytes_buffered -= ctx->param_bytes;
kfree(ctx);
}
static void *
parser_string_get(struct parser_context *ctx)
{
u8 *pscan;
unsigned long nscan;
int value_length = -1;
void *value = NULL;
int i;
if (!ctx)
return NULL;
pscan = ctx->curr;
nscan = ctx->bytes_remaining;
if (nscan == 0)
return NULL;
if (!pscan)
return NULL;
for (i = 0, value_length = -1; i < nscan; i++)
if (pscan[i] == '\0') {
value_length = i;
break;
}
if (value_length < 0)
value_length = nscan;
value = kmalloc(value_length + 1, GFP_KERNEL | __GFP_NORETRY);
if (!value)
return NULL;
if (value_length > 0)
memcpy(value, pscan, value_length);
((u8 *)(value))[value_length] = '\0';
return value;
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
if (kstrtou8(buf, 10, &tool_action))
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
if (kstrtoint(buf, 10, &val))
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
if (kstrtou32(buf, 10, &error))
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
if (kstrtou32(buf, 10, &text_id))
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
if (kstrtou16(buf, 10, &remaining_steps))
return -EINVAL;
ret = visorchannel_write(controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
installation_remaining_steps),
&remaining_steps, sizeof(u16));
if (ret)
return ret;
return count;
}
static int match_visorbus_dev_by_id(struct device *dev, void *data)
{
struct visor_device *vdev = to_visor_device(dev);
struct visor_busdev *id = data;
u32 bus_no = id->bus_no;
u32 dev_no = id->dev_no;
if ((vdev->chipset_bus_no == bus_no) &&
(vdev->chipset_dev_no == dev_no))
return 1;
return 0;
}
struct visor_device *visorbus_get_device_by_id(u32 bus_no, u32 dev_no,
struct visor_device *from)
{
struct device *dev;
struct device *dev_start = NULL;
struct visor_device *vdev = NULL;
struct visor_busdev id = {
.bus_no = bus_no,
.dev_no = dev_no
};
if (from)
dev_start = &from->device;
dev = bus_find_device(&visorbus_type, dev_start, (void *)&id,
match_visorbus_dev_by_id);
if (dev)
vdev = to_visor_device(dev);
return vdev;
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
visorchipset_register_busdev(
struct visorchipset_busdev_notifiers *notifiers,
struct visorchipset_busdev_responders *responders,
struct ultra_vbus_deviceinfo *driver_info)
{
down(&notifier_lock);
if (!notifiers) {
memset(&busdev_notifiers, 0,
sizeof(busdev_notifiers));
visorbusregistered = 0;
} else {
busdev_notifiers = *notifiers;
visorbusregistered = 1;
}
if (responders)
*responders = busdev_responders;
if (driver_info)
bus_device_info_init(driver_info, "chipset", "visorchipset",
VERSION, NULL);
up(&notifier_lock);
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
msg->hdr.completion_status = (u32)(-response);
}
}
static void
controlvm_respond(struct controlvm_message_header *msg_hdr, int response)
{
struct controlvm_message outmsg;
controlvm_init_response(&outmsg, msg_hdr, response);
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
static void
save_crash_message(struct controlvm_message *msg, enum crash_obj_type typ)
{
u32 local_crash_msg_offset;
u16 local_crash_msg_count;
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
if (typ == CRASH_BUS) {
if (visorchannel_write(controlvm_channel,
local_crash_msg_offset,
msg,
sizeof(struct controlvm_message)) < 0) {
POSTCODE_LINUX_2(SAVE_MSG_BUS_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
} else {
local_crash_msg_offset += sizeof(struct controlvm_message);
if (visorchannel_write(controlvm_channel,
local_crash_msg_offset,
msg,
sizeof(struct controlvm_message)) < 0) {
POSTCODE_LINUX_2(SAVE_MSG_DEV_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
}
}
static void
bus_responder(enum controlvm_id cmd_id,
struct controlvm_message_header *pending_msg_hdr,
int response)
{
if (!pending_msg_hdr)
return;
if (pending_msg_hdr->id != (u32)cmd_id)
return;
controlvm_respond(pending_msg_hdr, response);
}
static void
device_changestate_responder(enum controlvm_id cmd_id,
struct visor_device *p, int response,
struct spar_segment_state response_state)
{
struct controlvm_message outmsg;
u32 bus_no = p->chipset_bus_no;
u32 dev_no = p->chipset_dev_no;
if (!p->pending_msg_hdr)
return;
if (p->pending_msg_hdr->id != cmd_id)
return;
controlvm_init_response(&outmsg, p->pending_msg_hdr, response);
outmsg.cmd.device_change_state.bus_no = bus_no;
outmsg.cmd.device_change_state.dev_no = dev_no;
outmsg.cmd.device_change_state.state = response_state;
if (!visorchannel_signalinsert(controlvm_channel,
CONTROLVM_QUEUE_REQUEST, &outmsg))
return;
}
static void
device_responder(enum controlvm_id cmd_id,
struct controlvm_message_header *pending_msg_hdr,
int response)
{
if (!pending_msg_hdr)
return;
if (pending_msg_hdr->id != (u32)cmd_id)
return;
controlvm_respond(pending_msg_hdr, response);
}
static void
bus_epilog(struct visor_device *bus_info,
u32 cmd, struct controlvm_message_header *msg_hdr,
int response, bool need_response)
{
bool notified = false;
struct controlvm_message_header *pmsg_hdr = NULL;
if (!bus_info) {
pmsg_hdr = msg_hdr;
goto away;
}
if (bus_info->pending_msg_hdr) {
response = -CONTROLVM_RESP_ERROR_MESSAGE_ID_INVALID_FOR_CLIENT;
pmsg_hdr = bus_info->pending_msg_hdr;
goto away;
}
if (need_response) {
pmsg_hdr = kzalloc(sizeof(*pmsg_hdr), GFP_KERNEL);
if (!pmsg_hdr) {
response = -CONTROLVM_RESP_ERROR_KMALLOC_FAILED;
goto away;
}
memcpy(pmsg_hdr, msg_hdr,
sizeof(struct controlvm_message_header));
bus_info->pending_msg_hdr = pmsg_hdr;
}
down(&notifier_lock);
if (response == CONTROLVM_RESP_SUCCESS) {
switch (cmd) {
case CONTROLVM_BUS_CREATE:
if (busdev_notifiers.bus_create) {
(*busdev_notifiers.bus_create) (bus_info);
notified = true;
}
break;
case CONTROLVM_BUS_DESTROY:
if (busdev_notifiers.bus_destroy) {
(*busdev_notifiers.bus_destroy) (bus_info);
notified = true;
}
break;
}
}
away:
if (notified)
;
else
bus_responder(cmd, pmsg_hdr, response);
up(&notifier_lock);
}
static void
device_epilog(struct visor_device *dev_info,
struct spar_segment_state state, u32 cmd,
struct controlvm_message_header *msg_hdr, int response,
bool need_response, bool for_visorbus)
{
struct visorchipset_busdev_notifiers *notifiers;
bool notified = false;
struct controlvm_message_header *pmsg_hdr = NULL;
notifiers = &busdev_notifiers;
if (!dev_info) {
pmsg_hdr = msg_hdr;
goto away;
}
if (dev_info->pending_msg_hdr) {
response = -CONTROLVM_RESP_ERROR_MESSAGE_ID_INVALID_FOR_CLIENT;
pmsg_hdr = dev_info->pending_msg_hdr;
goto away;
}
if (need_response) {
pmsg_hdr = kzalloc(sizeof(*pmsg_hdr), GFP_KERNEL);
if (!pmsg_hdr) {
response = -CONTROLVM_RESP_ERROR_KMALLOC_FAILED;
goto away;
}
memcpy(pmsg_hdr, msg_hdr,
sizeof(struct controlvm_message_header));
dev_info->pending_msg_hdr = pmsg_hdr;
}
down(&notifier_lock);
if (response >= 0) {
switch (cmd) {
case CONTROLVM_DEVICE_CREATE:
if (notifiers->device_create) {
(*notifiers->device_create) (dev_info);
notified = true;
}
break;
case CONTROLVM_DEVICE_CHANGESTATE:
if (state.alive == segment_state_running.alive &&
state.operating ==
segment_state_running.operating) {
if (notifiers->device_resume) {
(*notifiers->device_resume) (dev_info);
notified = true;
}
}
else if (state.alive == segment_state_standby.alive &&
state.operating ==
segment_state_standby.operating) {
if (notifiers->device_pause) {
(*notifiers->device_pause) (dev_info);
notified = true;
}
}
break;
case CONTROLVM_DEVICE_DESTROY:
if (notifiers->device_destroy) {
(*notifiers->device_destroy) (dev_info);
notified = true;
}
break;
}
}
away:
if (notified)
;
else
device_responder(cmd, pmsg_hdr, response);
up(&notifier_lock);
}
static void
bus_create(struct controlvm_message *inmsg)
{
struct controlvm_message_packet *cmd = &inmsg->cmd;
u32 bus_no = cmd->create_bus.bus_no;
int rc = CONTROLVM_RESP_SUCCESS;
struct visor_device *bus_info;
struct visorchannel *visorchannel;
bus_info = visorbus_get_device_by_id(bus_no, BUS_ROOT_DEVICE, NULL);
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
INIT_LIST_HEAD(&bus_info->list_all);
bus_info->chipset_bus_no = bus_no;
bus_info->chipset_dev_no = BUS_ROOT_DEVICE;
POSTCODE_LINUX_3(BUS_CREATE_ENTRY_PC, bus_no, POSTCODE_SEVERITY_INFO);
visorchannel = visorchannel_create(cmd->create_bus.channel_addr,
cmd->create_bus.channel_bytes,
GFP_KERNEL,
cmd->create_bus.bus_data_type_uuid);
if (!visorchannel) {
POSTCODE_LINUX_3(BUS_CREATE_FAILURE_PC, bus_no,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_KMALLOC_FAILED;
kfree(bus_info);
bus_info = NULL;
goto cleanup;
}
bus_info->visorchannel = visorchannel;
if (uuid_le_cmp(cmd->create_bus.bus_inst_uuid, spar_siovm_uuid) == 0) {
dump_vhba_bus = bus_no;
save_crash_message(inmsg, CRASH_BUS);
}
POSTCODE_LINUX_3(BUS_CREATE_EXIT_PC, bus_no, POSTCODE_SEVERITY_INFO);
cleanup:
bus_epilog(bus_info, CONTROLVM_BUS_CREATE, &inmsg->hdr,
rc, inmsg->hdr.flags.response_expected == 1);
}
static void
bus_destroy(struct controlvm_message *inmsg)
{
struct controlvm_message_packet *cmd = &inmsg->cmd;
u32 bus_no = cmd->destroy_bus.bus_no;
struct visor_device *bus_info;
int rc = CONTROLVM_RESP_SUCCESS;
bus_info = visorbus_get_device_by_id(bus_no, BUS_ROOT_DEVICE, NULL);
if (!bus_info)
rc = -CONTROLVM_RESP_ERROR_BUS_INVALID;
else if (bus_info->state.created == 0)
rc = -CONTROLVM_RESP_ERROR_ALREADY_DONE;
bus_epilog(bus_info, CONTROLVM_BUS_DESTROY, &inmsg->hdr,
rc, inmsg->hdr.flags.response_expected == 1);
}
static void
bus_configure(struct controlvm_message *inmsg,
struct parser_context *parser_ctx)
{
struct controlvm_message_packet *cmd = &inmsg->cmd;
u32 bus_no;
struct visor_device *bus_info;
int rc = CONTROLVM_RESP_SUCCESS;
bus_no = cmd->configure_bus.bus_no;
POSTCODE_LINUX_3(BUS_CONFIGURE_ENTRY_PC, bus_no,
POSTCODE_SEVERITY_INFO);
bus_info = visorbus_get_device_by_id(bus_no, BUS_ROOT_DEVICE, NULL);
if (!bus_info) {
POSTCODE_LINUX_3(BUS_CONFIGURE_FAILURE_PC, bus_no,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_BUS_INVALID;
} else if (bus_info->state.created == 0) {
POSTCODE_LINUX_3(BUS_CONFIGURE_FAILURE_PC, bus_no,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_BUS_INVALID;
} else if (bus_info->pending_msg_hdr) {
POSTCODE_LINUX_3(BUS_CONFIGURE_FAILURE_PC, bus_no,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_MESSAGE_ID_INVALID_FOR_CLIENT;
} else {
visorchannel_set_clientpartition(bus_info->visorchannel,
cmd->configure_bus.guest_handle);
bus_info->partition_uuid = parser_id_get(parser_ctx);
parser_param_start(parser_ctx, PARSERSTRING_NAME);
bus_info->name = parser_string_get(parser_ctx);
POSTCODE_LINUX_3(BUS_CONFIGURE_EXIT_PC, bus_no,
POSTCODE_SEVERITY_INFO);
}
bus_epilog(bus_info, CONTROLVM_BUS_CONFIGURE, &inmsg->hdr,
rc, inmsg->hdr.flags.response_expected == 1);
}
static void
my_device_create(struct controlvm_message *inmsg)
{
struct controlvm_message_packet *cmd = &inmsg->cmd;
u32 bus_no = cmd->create_device.bus_no;
u32 dev_no = cmd->create_device.dev_no;
struct visor_device *dev_info = NULL;
struct visor_device *bus_info;
struct visorchannel *visorchannel;
int rc = CONTROLVM_RESP_SUCCESS;
bus_info = visorbus_get_device_by_id(bus_no, BUS_ROOT_DEVICE, NULL);
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
dev_info = visorbus_get_device_by_id(bus_no, dev_no, NULL);
if (dev_info && (dev_info->state.created == 1)) {
POSTCODE_LINUX_4(DEVICE_CREATE_FAILURE_PC, dev_no, bus_no,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_ALREADY_DONE;
goto cleanup;
}
dev_info = kzalloc(sizeof(*dev_info), GFP_KERNEL);
if (!dev_info) {
POSTCODE_LINUX_4(DEVICE_CREATE_FAILURE_PC, dev_no, bus_no,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_KMALLOC_FAILED;
goto cleanup;
}
dev_info->chipset_bus_no = bus_no;
dev_info->chipset_dev_no = dev_no;
dev_info->inst = cmd->create_device.dev_inst_uuid;
dev_info->device.parent = &bus_info->device;
POSTCODE_LINUX_4(DEVICE_CREATE_ENTRY_PC, dev_no, bus_no,
POSTCODE_SEVERITY_INFO);
visorchannel =
visorchannel_create_with_lock(cmd->create_device.channel_addr,
cmd->create_device.channel_bytes,
GFP_KERNEL,
cmd->create_device.data_type_uuid);
if (!visorchannel) {
POSTCODE_LINUX_4(DEVICE_CREATE_FAILURE_PC, dev_no, bus_no,
POSTCODE_SEVERITY_ERR);
rc = -CONTROLVM_RESP_ERROR_KMALLOC_FAILED;
kfree(dev_info);
dev_info = NULL;
goto cleanup;
}
dev_info->visorchannel = visorchannel;
dev_info->channel_type_guid = cmd->create_device.data_type_uuid;
if (uuid_le_cmp(cmd->create_device.data_type_uuid,
spar_vhba_channel_protocol_uuid) == 0)
save_crash_message(inmsg, CRASH_DEV);
POSTCODE_LINUX_4(DEVICE_CREATE_EXIT_PC, dev_no, bus_no,
POSTCODE_SEVERITY_INFO);
cleanup:
device_epilog(dev_info, segment_state_running,
CONTROLVM_DEVICE_CREATE, &inmsg->hdr, rc,
inmsg->hdr.flags.response_expected == 1, 1);
}
static void
my_device_changestate(struct controlvm_message *inmsg)
{
struct controlvm_message_packet *cmd = &inmsg->cmd;
u32 bus_no = cmd->device_change_state.bus_no;
u32 dev_no = cmd->device_change_state.dev_no;
struct spar_segment_state state = cmd->device_change_state.state;
struct visor_device *dev_info;
int rc = CONTROLVM_RESP_SUCCESS;
dev_info = visorbus_get_device_by_id(bus_no, dev_no, NULL);
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
device_epilog(dev_info, state,
CONTROLVM_DEVICE_CHANGESTATE, &inmsg->hdr, rc,
inmsg->hdr.flags.response_expected == 1, 1);
}
static void
my_device_destroy(struct controlvm_message *inmsg)
{
struct controlvm_message_packet *cmd = &inmsg->cmd;
u32 bus_no = cmd->destroy_device.bus_no;
u32 dev_no = cmd->destroy_device.dev_no;
struct visor_device *dev_info;
int rc = CONTROLVM_RESP_SUCCESS;
dev_info = visorbus_get_device_by_id(bus_no, dev_no, NULL);
if (!dev_info)
rc = -CONTROLVM_RESP_ERROR_DEVICE_INVALID;
else if (dev_info->state.created == 0)
rc = -CONTROLVM_RESP_ERROR_ALREADY_DONE;
if ((rc >= CONTROLVM_RESP_SUCCESS) && dev_info)
device_epilog(dev_info, segment_state_running,
CONTROLVM_DEVICE_DESTROY, &inmsg->hdr, rc,
inmsg->hdr.flags.response_expected == 1, 1);
}
static int
initialize_controlvm_payload_info(u64 phys_addr, u64 offset, u32 bytes,
struct visor_controlvm_payload_info *info)
{
u8 *payload = NULL;
int rc = CONTROLVM_RESP_SUCCESS;
if (!info) {
rc = -CONTROLVM_RESP_ERROR_PAYLOAD_INVALID;
goto cleanup;
}
memset(info, 0, sizeof(struct visor_controlvm_payload_info));
if ((offset == 0) || (bytes == 0)) {
rc = -CONTROLVM_RESP_ERROR_PAYLOAD_INVALID;
goto cleanup;
}
payload = memremap(phys_addr + offset, bytes, MEMREMAP_WB);
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
memunmap(payload);
payload = NULL;
}
}
return rc;
}
static void
destroy_controlvm_payload_info(struct visor_controlvm_payload_info *info)
{
if (info->ptr) {
memunmap(info->ptr);
info->ptr = NULL;
}
memset(info, 0, sizeof(struct visor_controlvm_payload_info));
}
static void
initialize_controlvm_payload(void)
{
u64 phys_addr = visorchannel_get_physaddr(controlvm_channel);
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
static int
visorchipset_chipset_ready(void)
{
kobject_uevent(&visorchipset_platform_device.dev.kobj, KOBJ_ONLINE);
return CONTROLVM_RESP_SUCCESS;
}
static int
visorchipset_chipset_selftest(void)
{
char env_selftest[20];
char *envp[] = { env_selftest, NULL };
sprintf(env_selftest, "SPARSP_SELFTEST=%d", 1);
kobject_uevent_env(&visorchipset_platform_device.dev.kobj, KOBJ_CHANGE,
envp);
return CONTROLVM_RESP_SUCCESS;
}
static int
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
static bool
read_controlvm_event(struct controlvm_message *msg)
{
if (visorchannel_signalremove(controlvm_channel,
CONTROLVM_QUEUE_EVENT, msg)) {
if (msg->hdr.flags.test_message == 1)
return false;
return true;
}
return false;
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
struct list_head *pos;
struct list_head *tmp;
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
struct list_head *pos;
struct list_head *tmp;
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
static bool
handle_command(struct controlvm_message inmsg, u64 channel_addr)
{
struct controlvm_message_packet *cmd = &inmsg.cmd;
u64 parm_addr;
u32 parm_bytes;
struct parser_context *parser_ctx = NULL;
bool local_addr;
struct controlvm_message ackmsg;
local_addr = (inmsg.hdr.flags.test_message == 1);
if (channel_addr == 0)
return true;
parm_addr = channel_addr + inmsg.hdr.payload_vm_offset;
parm_bytes = inmsg.hdr.payload_bytes;
if (parm_addr && parm_bytes) {
bool retry = false;
parser_ctx =
parser_init_byte_stream(parm_addr, parm_bytes,
local_addr, &retry);
if (!parser_ctx && retry)
return false;
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
return true;
}
static inline unsigned int
issue_vmcall_io_controlvm_addr(u64 *control_addr, u32 *control_bytes)
{
struct vmcall_io_controlvm_addr_params params;
int result = VMCALL_SUCCESS;
u64 physaddr;
physaddr = virt_to_phys(&params);
ISSUE_IO_VMCALL(VMCALL_IO_CONTROLVM_ADDR, physaddr, result);
if (VMCALL_SUCCESSFUL(result)) {
*control_addr = params.address;
*control_bytes = params.channel_bytes;
}
return result;
}
static u64 controlvm_get_channel_address(void)
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
bool got_command = false;
bool handle_command_failed = false;
static u64 poll_count;
if (visorchipset_visorbusregwait && !visorbusregistered)
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
controlvm_pending_msg_valid = false;
got_command = true;
} else {
got_command = read_controlvm_event(&inmsg);
}
}
handle_command_failed = false;
while (got_command && (!handle_command_failed)) {
most_recent_message_jiffies = jiffies;
if (handle_command(inmsg,
visorchannel_get_physaddr
(controlvm_channel)))
got_command = read_controlvm_event(&inmsg);
else {
handle_command_failed = true;
controlvm_pending_msg = inmsg;
controlvm_pending_msg_valid = true;
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
schedule_delayed_work(&periodic_controlvm_work, poll_jiffies);
}
static void
setup_crash_devices_work_queue(struct work_struct *work)
{
struct controlvm_message local_crash_bus_msg;
struct controlvm_message local_crash_dev_msg;
struct controlvm_message msg;
u32 local_crash_msg_offset;
u16 local_crash_msg_count;
if (visorchipset_visorbusregwait && !visorbusregistered)
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
if (local_crash_bus_msg.cmd.create_bus.channel_addr) {
bus_create(&local_crash_bus_msg);
} else {
POSTCODE_LINUX_2(CRASH_DEV_BUS_NULL_FAILURE_PC,
POSTCODE_SEVERITY_ERR);
return;
}
if (local_crash_dev_msg.cmd.create_device.channel_addr) {
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
schedule_delayed_work(&periodic_controlvm_work, poll_jiffies);
}
static void
bus_create_response(struct visor_device *bus_info, int response)
{
if (response >= 0)
bus_info->state.created = 1;
bus_responder(CONTROLVM_BUS_CREATE, bus_info->pending_msg_hdr,
response);
kfree(bus_info->pending_msg_hdr);
bus_info->pending_msg_hdr = NULL;
}
static void
bus_destroy_response(struct visor_device *bus_info, int response)
{
bus_responder(CONTROLVM_BUS_DESTROY, bus_info->pending_msg_hdr,
response);
kfree(bus_info->pending_msg_hdr);
bus_info->pending_msg_hdr = NULL;
}
static void
device_create_response(struct visor_device *dev_info, int response)
{
if (response >= 0)
dev_info->state.created = 1;
device_responder(CONTROLVM_DEVICE_CREATE, dev_info->pending_msg_hdr,
response);
kfree(dev_info->pending_msg_hdr);
dev_info->pending_msg_hdr = NULL;
}
static void
device_destroy_response(struct visor_device *dev_info, int response)
{
device_responder(CONTROLVM_DEVICE_DESTROY, dev_info->pending_msg_hdr,
response);
kfree(dev_info->pending_msg_hdr);
dev_info->pending_msg_hdr = NULL;
}
static void
visorchipset_device_pause_response(struct visor_device *dev_info,
int response)
{
device_changestate_responder(CONTROLVM_DEVICE_CHANGESTATE,
dev_info, response,
segment_state_standby);
kfree(dev_info->pending_msg_hdr);
dev_info->pending_msg_hdr = NULL;
}
static void
device_resume_response(struct visor_device *dev_info, int response)
{
device_changestate_responder(CONTROLVM_DEVICE_CHANGESTATE,
dev_info, response,
segment_state_running);
kfree(dev_info->pending_msg_hdr);
dev_info->pending_msg_hdr = NULL;
}
static ssize_t chipsetready_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
char msgtype[64];
if (sscanf(buf, "%63s", msgtype) != 1)
return -EINVAL;
if (!strcmp(msgtype, "CALLHOMEDISK_MOUNTED")) {
chipset_events[0] = 1;
return count;
} else if (!strcmp(msgtype, "MODULES_LOADED")) {
chipset_events[1] = 1;
return count;
}
return -EINVAL;
}
static ssize_t devicedisabled_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned int id;
if (kstrtouint(buf, 10, &id))
return -EINVAL;
parahotplug_request_complete(id, 0);
return count;
}
static ssize_t deviceenabled_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned int id;
if (kstrtouint(buf, 10, &id))
return -EINVAL;
parahotplug_request_complete(id, 1);
return count;
}
static int
visorchipset_mmap(struct file *file, struct vm_area_struct *vma)
{
unsigned long physaddr = 0;
unsigned long offset = vma->vm_pgoff << PAGE_SHIFT;
u64 addr = 0;
if (offset & (PAGE_SIZE - 1))
return -ENXIO;
switch (offset) {
case VISORCHIPSET_MMAP_CONTROLCHANOFFSET:
vma->vm_flags |= VM_IO;
if (!*file_controlvm_channel)
return -ENXIO;
visorchannel_read(*file_controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
gp_control_channel),
&addr, sizeof(addr));
if (!addr)
return -ENXIO;
physaddr = (unsigned long)addr;
if (remap_pfn_range(vma, vma->vm_start,
physaddr >> PAGE_SHIFT,
vma->vm_end - vma->vm_start,
(vma->vm_page_prot))) {
return -EAGAIN;
}
break;
default:
return -ENXIO;
}
return 0;
}
static inline s64 issue_vmcall_query_guest_virtual_time_offset(void)
{
u64 result = VMCALL_SUCCESS;
u64 physaddr = 0;
ISSUE_IO_VMCALL(VMCALL_QUERY_GUEST_VIRTUAL_TIME_OFFSET, physaddr,
result);
return result;
}
static inline int issue_vmcall_update_physical_time(u64 adjustment)
{
int result = VMCALL_SUCCESS;
ISSUE_IO_VMCALL(VMCALL_UPDATE_PHYSICAL_TIME, adjustment, result);
return result;
}
static long visorchipset_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
u64 adjustment;
s64 vrtc_offset;
switch (cmd) {
case VMCALL_QUERY_GUEST_VIRTUAL_TIME_OFFSET:
vrtc_offset = issue_vmcall_query_guest_virtual_time_offset();
if (copy_to_user((void __user *)arg, &vrtc_offset,
sizeof(vrtc_offset))) {
return -EFAULT;
}
return 0;
case VMCALL_UPDATE_PHYSICAL_TIME:
if (copy_from_user(&adjustment, (void __user *)arg,
sizeof(adjustment))) {
return -EFAULT;
}
return issue_vmcall_update_physical_time(adjustment);
default:
return -EFAULT;
}
}
static int
visorchipset_file_init(dev_t major_dev, struct visorchannel **controlvm_channel)
{
int rc = 0;
file_controlvm_channel = controlvm_channel;
cdev_init(&file_cdev, &visorchipset_fops);
file_cdev.owner = THIS_MODULE;
if (MAJOR(major_dev) == 0) {
rc = alloc_chrdev_region(&major_dev, 0, 1, "visorchipset");
if (rc < 0)
return rc;
} else {
rc = register_chrdev_region(major_dev, 1, "visorchipset");
if (rc < 0)
return rc;
}
rc = cdev_add(&file_cdev, MKDEV(MAJOR(major_dev), 0), 1);
if (rc < 0) {
unregister_chrdev_region(major_dev, 1);
return rc;
}
return 0;
}
static int
visorchipset_init(struct acpi_device *acpi_device)
{
int rc = 0;
u64 addr;
uuid_le uuid = SPAR_CONTROLVM_CHANNEL_PROTOCOL_UUID;
addr = controlvm_get_channel_address();
if (!addr)
return -ENODEV;
memset(&busdev_notifiers, 0, sizeof(busdev_notifiers));
memset(&controlvm_payload_info, 0, sizeof(controlvm_payload_info));
controlvm_channel = visorchannel_create_with_lock(addr, 0,
GFP_KERNEL, uuid);
if (!controlvm_channel)
return -ENODEV;
if (SPAR_CONTROLVM_CHANNEL_OK_CLIENT(
visorchannel_get_header(controlvm_channel))) {
initialize_controlvm_payload();
} else {
visorchannel_destroy(controlvm_channel);
controlvm_channel = NULL;
return -ENODEV;
}
major_dev = MKDEV(visorchipset_major, 0);
rc = visorchipset_file_init(major_dev, &controlvm_channel);
if (rc < 0) {
POSTCODE_LINUX_2(CHIPSET_INIT_FAILURE_PC, DIAG_SEVERITY_ERR);
goto cleanup;
}
memset(&g_chipset_msg_hdr, 0, sizeof(struct controlvm_message_header));
if (is_kdump_kernel())
INIT_DELAYED_WORK(&periodic_controlvm_work,
setup_crash_devices_work_queue);
else
INIT_DELAYED_WORK(&periodic_controlvm_work,
controlvm_periodic_work);
most_recent_message_jiffies = jiffies;
poll_jiffies = POLLJIFFIES_CONTROLVMCHANNEL_FAST;
schedule_delayed_work(&periodic_controlvm_work, poll_jiffies);
visorchipset_platform_device.dev.devt = major_dev;
if (platform_device_register(&visorchipset_platform_device) < 0) {
POSTCODE_LINUX_2(DEVICE_REGISTER_FAILURE_PC, DIAG_SEVERITY_ERR);
rc = -ENODEV;
goto cleanup;
}
POSTCODE_LINUX_2(CHIPSET_INIT_SUCCESS_PC, POSTCODE_SEVERITY_INFO);
rc = visorbus_init();
cleanup:
if (rc) {
POSTCODE_LINUX_3(CHIPSET_INIT_FAILURE_PC, rc,
POSTCODE_SEVERITY_ERR);
}
return rc;
}
static void
visorchipset_file_cleanup(dev_t major_dev)
{
if (file_cdev.ops)
cdev_del(&file_cdev);
file_cdev.ops = NULL;
unregister_chrdev_region(major_dev, 1);
}
static int
visorchipset_exit(struct acpi_device *acpi_device)
{
POSTCODE_LINUX_2(DRIVER_EXIT_PC, POSTCODE_SEVERITY_INFO);
visorbus_exit();
cancel_delayed_work_sync(&periodic_controlvm_work);
destroy_controlvm_payload_info(&controlvm_payload_info);
memset(&g_chipset_msg_hdr, 0, sizeof(struct controlvm_message_header));
visorchannel_destroy(controlvm_channel);
visorchipset_file_cleanup(visorchipset_platform_device.dev.devt);
platform_device_unregister(&visorchipset_platform_device);
POSTCODE_LINUX_2(DRIVER_EXIT_PC, POSTCODE_SEVERITY_INFO);
return 0;
}
static __init uint32_t visorutil_spar_detect(void)
{
unsigned int eax, ebx, ecx, edx;
if (cpu_has_hypervisor) {
cpuid(UNISYS_SPAR_LEAF_ID, &eax, &ebx, &ecx, &edx);
return (ebx == UNISYS_SPAR_ID_EBX) &&
(ecx == UNISYS_SPAR_ID_ECX) &&
(edx == UNISYS_SPAR_ID_EDX);
} else {
return 0;
}
}
static int init_unisys(void)
{
int result;
if (!visorutil_spar_detect())
return -ENODEV;
result = acpi_bus_register_driver(&unisys_acpi_driver);
if (result)
return -ENODEV;
pr_info("Unisys Visorchipset Driver Loaded.\n");
return 0;
}
static void exit_unisys(void)
{
acpi_bus_unregister_driver(&unisys_acpi_driver);
}
