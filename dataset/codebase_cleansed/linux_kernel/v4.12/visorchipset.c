static ssize_t toolaction_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u8 tool_action = 0;
int err;
err = visorchannel_read(chipset_dev->controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
tool_action),
&tool_action, sizeof(u8));
if (err)
return err;
return sprintf(buf, "%u\n", tool_action);
}
static ssize_t toolaction_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
u8 tool_action;
int err;
if (kstrtou8(buf, 10, &tool_action))
return -EINVAL;
err = visorchannel_write
(chipset_dev->controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
tool_action),
&tool_action, sizeof(u8));
if (err)
return err;
return count;
}
static ssize_t boottotool_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct efi_spar_indication efi_spar_indication;
int err;
err = visorchannel_read(chipset_dev->controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
efi_spar_ind),
&efi_spar_indication,
sizeof(struct efi_spar_indication));
if (err)
return err;
return sprintf(buf, "%u\n", efi_spar_indication.boot_to_tool);
}
static ssize_t boottotool_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int val, err;
struct efi_spar_indication efi_spar_indication;
if (kstrtoint(buf, 10, &val))
return -EINVAL;
efi_spar_indication.boot_to_tool = val;
err = visorchannel_write
(chipset_dev->controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
efi_spar_ind), &(efi_spar_indication),
sizeof(struct efi_spar_indication));
if (err)
return err;
return count;
}
static ssize_t error_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
u32 error = 0;
int err;
err = visorchannel_read(chipset_dev->controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
installation_error),
&error, sizeof(u32));
if (err)
return err;
return sprintf(buf, "%i\n", error);
}
static ssize_t error_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
u32 error;
int err;
if (kstrtou32(buf, 10, &error))
return -EINVAL;
err = visorchannel_write
(chipset_dev->controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
installation_error),
&error, sizeof(u32));
if (err)
return err;
return count;
}
static ssize_t textid_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
u32 text_id = 0;
int err;
err = visorchannel_read
(chipset_dev->controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
installation_text_id),
&text_id, sizeof(u32));
if (err)
return err;
return sprintf(buf, "%i\n", text_id);
}
static ssize_t textid_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
u32 text_id;
int err;
if (kstrtou32(buf, 10, &text_id))
return -EINVAL;
err = visorchannel_write
(chipset_dev->controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
installation_text_id),
&text_id, sizeof(u32));
if (err)
return err;
return count;
}
static ssize_t remaining_steps_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
u16 remaining_steps = 0;
int err;
err = visorchannel_read(chipset_dev->controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
installation_remaining_steps),
&remaining_steps, sizeof(u16));
if (err)
return err;
return sprintf(buf, "%hu\n", remaining_steps);
}
static ssize_t remaining_steps_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
u16 remaining_steps;
int err;
if (kstrtou16(buf, 10, &remaining_steps))
return -EINVAL;
err = visorchannel_write
(chipset_dev->controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
installation_remaining_steps),
&remaining_steps, sizeof(u16));
if (err)
return err;
return count;
}
static uuid_le
parser_id_get(struct parser_context *ctx)
{
struct spar_controlvm_parameters_header *phdr = NULL;
phdr = (struct spar_controlvm_parameters_header *)(ctx->data);
return phdr->id;
}
static void parser_done(struct parser_context *ctx)
{
chipset_dev->controlvm_payload_bytes_buffered -= ctx->param_bytes;
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
value = kmalloc(value_length + 1, GFP_KERNEL);
if (!value)
return NULL;
if (value_length > 0)
memcpy(value, pscan, value_length);
((u8 *)(value))[value_length] = '\0';
return value;
}
static void *
parser_name_get(struct parser_context *ctx)
{
struct spar_controlvm_parameters_header *phdr = NULL;
phdr = (struct spar_controlvm_parameters_header *)(ctx->data);
if (phdr->name_offset + phdr->name_length > ctx->param_bytes)
return NULL;
ctx->curr = ctx->data + phdr->name_offset;
ctx->bytes_remaining = phdr->name_length;
return parser_string_get(ctx);
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
static int
controlvm_respond_chipset_init(struct controlvm_message_header *msg_hdr,
int response,
enum ultra_chipset_feature features)
{
struct controlvm_message outmsg;
controlvm_init_response(&outmsg, msg_hdr, response);
outmsg.cmd.init_chipset.features = features;
return visorchannel_signalinsert(chipset_dev->controlvm_channel,
CONTROLVM_QUEUE_REQUEST, &outmsg);
}
static int
chipset_init(struct controlvm_message *inmsg)
{
static int chipset_inited;
enum ultra_chipset_feature features = 0;
int rc = CONTROLVM_RESP_SUCCESS;
int res = 0;
if (chipset_inited) {
rc = -CONTROLVM_RESP_ALREADY_DONE;
res = -EIO;
goto out_respond;
}
chipset_inited = 1;
features = inmsg->cmd.init_chipset.features &
ULTRA_CHIPSET_FEATURE_PARA_HOTPLUG;
features |= ULTRA_CHIPSET_FEATURE_REPLY;
out_respond:
if (inmsg->hdr.flags.response_expected)
res = controlvm_respond_chipset_init(&inmsg->hdr, rc, features);
return res;
}
static int
controlvm_respond(struct controlvm_message_header *msg_hdr, int response,
struct spar_segment_state *state)
{
struct controlvm_message outmsg;
controlvm_init_response(&outmsg, msg_hdr, response);
if (outmsg.hdr.flags.test_message == 1)
return -EINVAL;
if (state) {
outmsg.cmd.device_change_state.state = *state;
outmsg.cmd.device_change_state.flags.phys_device = 1;
}
return visorchannel_signalinsert(chipset_dev->controlvm_channel,
CONTROLVM_QUEUE_REQUEST, &outmsg);
}
static int
save_crash_message(struct controlvm_message *msg, enum crash_obj_type typ)
{
u32 local_crash_msg_offset;
u16 local_crash_msg_count;
int err;
err = visorchannel_read(chipset_dev->controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
saved_crash_message_count),
&local_crash_msg_count, sizeof(u16));
if (err) {
dev_err(&chipset_dev->acpi_device->dev,
"failed to read message count\n");
return err;
}
if (local_crash_msg_count != CONTROLVM_CRASHMSG_MAX) {
dev_err(&chipset_dev->acpi_device->dev,
"invalid number of messages\n");
return -EIO;
}
err = visorchannel_read(chipset_dev->controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
saved_crash_message_offset),
&local_crash_msg_offset, sizeof(u32));
if (err) {
dev_err(&chipset_dev->acpi_device->dev,
"failed to read offset\n");
return err;
}
switch (typ) {
case CRASH_DEV:
local_crash_msg_offset += sizeof(struct controlvm_message);
err = visorchannel_write(chipset_dev->controlvm_channel,
local_crash_msg_offset,
msg,
sizeof(struct controlvm_message));
if (err) {
dev_err(&chipset_dev->acpi_device->dev,
"failed to write dev msg\n");
return err;
}
break;
case CRASH_BUS:
err = visorchannel_write(chipset_dev->controlvm_channel,
local_crash_msg_offset,
msg,
sizeof(struct controlvm_message));
if (err) {
dev_err(&chipset_dev->acpi_device->dev,
"failed to write bus msg\n");
return err;
}
break;
default:
dev_err(&chipset_dev->acpi_device->dev,
"Invalid crash_obj_type\n");
break;
}
return 0;
}
static int
controlvm_responder(enum controlvm_id cmd_id,
struct controlvm_message_header *pending_msg_hdr,
int response)
{
if (!pending_msg_hdr)
return -EIO;
if (pending_msg_hdr->id != (u32)cmd_id)
return -EINVAL;
return controlvm_respond(pending_msg_hdr, response, NULL);
}
static int
device_changestate_responder(enum controlvm_id cmd_id,
struct visor_device *p, int response,
struct spar_segment_state response_state)
{
struct controlvm_message outmsg;
u32 bus_no = p->chipset_bus_no;
u32 dev_no = p->chipset_dev_no;
if (!p->pending_msg_hdr)
return -EIO;
if (p->pending_msg_hdr->id != cmd_id)
return -EINVAL;
controlvm_init_response(&outmsg, p->pending_msg_hdr, response);
outmsg.cmd.device_change_state.bus_no = bus_no;
outmsg.cmd.device_change_state.dev_no = dev_no;
outmsg.cmd.device_change_state.state = response_state;
return visorchannel_signalinsert(chipset_dev->controlvm_channel,
CONTROLVM_QUEUE_REQUEST, &outmsg);
}
static int
bus_create(struct controlvm_message *inmsg)
{
struct controlvm_message_packet *cmd = &inmsg->cmd;
struct controlvm_message_header *pmsg_hdr = NULL;
u32 bus_no = cmd->create_bus.bus_no;
struct visor_device *bus_info;
struct visorchannel *visorchannel;
int err;
bus_info = visorbus_get_device_by_id(bus_no, BUS_ROOT_DEVICE, NULL);
if (bus_info && (bus_info->state.created == 1)) {
dev_err(&chipset_dev->acpi_device->dev,
"failed bus_create: already exists\n");
err = -EEXIST;
goto err_respond;
}
bus_info = kzalloc(sizeof(*bus_info), GFP_KERNEL);
if (!bus_info) {
err = -ENOMEM;
goto err_respond;
}
INIT_LIST_HEAD(&bus_info->list_all);
bus_info->chipset_bus_no = bus_no;
bus_info->chipset_dev_no = BUS_ROOT_DEVICE;
if (uuid_le_cmp(cmd->create_bus.bus_inst_uuid, spar_siovm_uuid) == 0) {
err = save_crash_message(inmsg, CRASH_BUS);
if (err)
goto err_free_bus_info;
}
if (inmsg->hdr.flags.response_expected == 1) {
pmsg_hdr = kzalloc(sizeof(*pmsg_hdr),
GFP_KERNEL);
if (!pmsg_hdr) {
err = -ENOMEM;
goto err_free_bus_info;
}
memcpy(pmsg_hdr, &inmsg->hdr,
sizeof(struct controlvm_message_header));
bus_info->pending_msg_hdr = pmsg_hdr;
}
visorchannel = visorchannel_create(cmd->create_bus.channel_addr,
cmd->create_bus.channel_bytes,
GFP_KERNEL,
cmd->create_bus.bus_data_type_uuid);
if (!visorchannel) {
err = -ENOMEM;
goto err_free_pending_msg;
}
bus_info->visorchannel = visorchannel;
err = chipset_bus_create(bus_info);
if (err)
goto err_destroy_channel;
return 0;
err_destroy_channel:
visorchannel_destroy(visorchannel);
err_free_pending_msg:
kfree(bus_info->pending_msg_hdr);
err_free_bus_info:
kfree(bus_info);
err_respond:
if (inmsg->hdr.flags.response_expected == 1)
controlvm_responder(inmsg->hdr.id, &inmsg->hdr, err);
return err;
}
static int
bus_destroy(struct controlvm_message *inmsg)
{
struct controlvm_message_packet *cmd = &inmsg->cmd;
struct controlvm_message_header *pmsg_hdr = NULL;
u32 bus_no = cmd->destroy_bus.bus_no;
struct visor_device *bus_info;
int err;
bus_info = visorbus_get_device_by_id(bus_no, BUS_ROOT_DEVICE, NULL);
if (!bus_info) {
err = -ENODEV;
goto err_respond;
}
if (bus_info->state.created == 0) {
err = -ENOENT;
goto err_respond;
}
if (bus_info->pending_msg_hdr) {
err = -EEXIST;
goto err_respond;
}
if (inmsg->hdr.flags.response_expected == 1) {
pmsg_hdr = kzalloc(sizeof(*pmsg_hdr), GFP_KERNEL);
if (!pmsg_hdr) {
err = -ENOMEM;
goto err_respond;
}
memcpy(pmsg_hdr, &inmsg->hdr,
sizeof(struct controlvm_message_header));
bus_info->pending_msg_hdr = pmsg_hdr;
}
chipset_bus_destroy(bus_info);
return 0;
err_respond:
if (inmsg->hdr.flags.response_expected == 1)
controlvm_responder(inmsg->hdr.id, &inmsg->hdr, err);
return err;
}
static int
bus_configure(struct controlvm_message *inmsg,
struct parser_context *parser_ctx)
{
struct controlvm_message_packet *cmd = &inmsg->cmd;
u32 bus_no;
struct visor_device *bus_info;
int err = 0;
bus_no = cmd->configure_bus.bus_no;
bus_info = visorbus_get_device_by_id(bus_no, BUS_ROOT_DEVICE, NULL);
if (!bus_info) {
err = -EINVAL;
goto err_respond;
} else if (bus_info->state.created == 0) {
err = -EINVAL;
goto err_respond;
} else if (bus_info->pending_msg_hdr) {
err = -EIO;
goto err_respond;
}
err = visorchannel_set_clientpartition
(bus_info->visorchannel,
cmd->configure_bus.guest_handle);
if (err)
goto err_respond;
if (parser_ctx) {
bus_info->partition_uuid = parser_id_get(parser_ctx);
bus_info->name = parser_name_get(parser_ctx);
}
if (inmsg->hdr.flags.response_expected == 1)
controlvm_responder(inmsg->hdr.id, &inmsg->hdr, err);
return 0;
err_respond:
dev_err(&chipset_dev->acpi_device->dev,
"bus_configured exited with err: %d\n", err);
if (inmsg->hdr.flags.response_expected == 1)
controlvm_responder(inmsg->hdr.id, &inmsg->hdr, err);
return err;
}
static int
my_device_create(struct controlvm_message *inmsg)
{
struct controlvm_message_packet *cmd = &inmsg->cmd;
struct controlvm_message_header *pmsg_hdr = NULL;
u32 bus_no = cmd->create_device.bus_no;
u32 dev_no = cmd->create_device.dev_no;
struct visor_device *dev_info = NULL;
struct visor_device *bus_info;
struct visorchannel *visorchannel;
int err;
bus_info = visorbus_get_device_by_id(bus_no, BUS_ROOT_DEVICE, NULL);
if (!bus_info) {
dev_err(&chipset_dev->acpi_device->dev,
"failed to get bus by id: %d\n", bus_no);
err = -ENODEV;
goto err_respond;
}
if (bus_info->state.created == 0) {
dev_err(&chipset_dev->acpi_device->dev,
"bus not created, id: %d\n", bus_no);
err = -EINVAL;
goto err_respond;
}
dev_info = visorbus_get_device_by_id(bus_no, dev_no, NULL);
if (dev_info && (dev_info->state.created == 1)) {
dev_err(&chipset_dev->acpi_device->dev,
"failed to get bus by id: %d/%d\n", bus_no, dev_no);
err = -EEXIST;
goto err_respond;
}
dev_info = kzalloc(sizeof(*dev_info), GFP_KERNEL);
if (!dev_info) {
err = -ENOMEM;
goto err_respond;
}
dev_info->chipset_bus_no = bus_no;
dev_info->chipset_dev_no = dev_no;
dev_info->inst = cmd->create_device.dev_inst_uuid;
dev_info->device.parent = &bus_info->device;
visorchannel =
visorchannel_create_with_lock(cmd->create_device.channel_addr,
cmd->create_device.channel_bytes,
GFP_KERNEL,
cmd->create_device.data_type_uuid);
if (!visorchannel) {
dev_err(&chipset_dev->acpi_device->dev,
"failed to create visorchannel: %d/%d\n",
bus_no, dev_no);
err = -ENOMEM;
goto err_free_dev_info;
}
dev_info->visorchannel = visorchannel;
dev_info->channel_type_guid = cmd->create_device.data_type_uuid;
if (uuid_le_cmp(cmd->create_device.data_type_uuid,
spar_vhba_channel_protocol_uuid) == 0) {
err = save_crash_message(inmsg, CRASH_DEV);
if (err)
goto err_destroy_visorchannel;
}
if (inmsg->hdr.flags.response_expected == 1) {
pmsg_hdr = kzalloc(sizeof(*pmsg_hdr), GFP_KERNEL);
if (!pmsg_hdr) {
err = -ENOMEM;
goto err_destroy_visorchannel;
}
memcpy(pmsg_hdr, &inmsg->hdr,
sizeof(struct controlvm_message_header));
dev_info->pending_msg_hdr = pmsg_hdr;
}
err = chipset_device_create(dev_info);
if (err)
goto err_destroy_visorchannel;
return 0;
err_destroy_visorchannel:
visorchannel_destroy(visorchannel);
err_free_dev_info:
kfree(dev_info);
err_respond:
if (inmsg->hdr.flags.response_expected == 1)
controlvm_responder(inmsg->hdr.id, &inmsg->hdr, err);
return err;
}
static int
my_device_changestate(struct controlvm_message *inmsg)
{
struct controlvm_message_packet *cmd = &inmsg->cmd;
struct controlvm_message_header *pmsg_hdr = NULL;
u32 bus_no = cmd->device_change_state.bus_no;
u32 dev_no = cmd->device_change_state.dev_no;
struct spar_segment_state state = cmd->device_change_state.state;
struct visor_device *dev_info;
int err = 0;
dev_info = visorbus_get_device_by_id(bus_no, dev_no, NULL);
if (!dev_info) {
err = -ENODEV;
goto err_respond;
}
if (dev_info->state.created == 0) {
err = -EINVAL;
goto err_respond;
}
if (dev_info->pending_msg_hdr) {
err = -EIO;
goto err_respond;
}
if (inmsg->hdr.flags.response_expected == 1) {
pmsg_hdr = kzalloc(sizeof(*pmsg_hdr), GFP_KERNEL);
if (!pmsg_hdr) {
err = -ENOMEM;
goto err_respond;
}
memcpy(pmsg_hdr, &inmsg->hdr,
sizeof(struct controlvm_message_header));
dev_info->pending_msg_hdr = pmsg_hdr;
}
if (state.alive == segment_state_running.alive &&
state.operating == segment_state_running.operating)
err = chipset_device_resume(dev_info);
else if (state.alive == segment_state_standby.alive &&
state.operating == segment_state_standby.operating)
err = chipset_device_pause(dev_info);
if (err)
goto err_respond;
return 0;
err_respond:
dev_err(&chipset_dev->acpi_device->dev, "failed: %d\n", err);
if (inmsg->hdr.flags.response_expected == 1)
controlvm_responder(inmsg->hdr.id, &inmsg->hdr, err);
return err;
}
static int
my_device_destroy(struct controlvm_message *inmsg)
{
struct controlvm_message_packet *cmd = &inmsg->cmd;
struct controlvm_message_header *pmsg_hdr = NULL;
u32 bus_no = cmd->destroy_device.bus_no;
u32 dev_no = cmd->destroy_device.dev_no;
struct visor_device *dev_info;
int err;
dev_info = visorbus_get_device_by_id(bus_no, dev_no, NULL);
if (!dev_info) {
err = -ENODEV;
goto err_respond;
}
if (dev_info->state.created == 0) {
err = -EINVAL;
goto err_respond;
}
if (dev_info->pending_msg_hdr) {
err = -EIO;
goto err_respond;
}
if (inmsg->hdr.flags.response_expected == 1) {
pmsg_hdr = kzalloc(sizeof(*pmsg_hdr), GFP_KERNEL);
if (!pmsg_hdr) {
err = -ENOMEM;
goto err_respond;
}
memcpy(pmsg_hdr, &inmsg->hdr,
sizeof(struct controlvm_message_header));
dev_info->pending_msg_hdr = pmsg_hdr;
}
chipset_device_destroy(dev_info);
return 0;
err_respond:
if (inmsg->hdr.flags.response_expected == 1)
controlvm_responder(inmsg->hdr.id, &inmsg->hdr, err);
return err;
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
req = kmalloc(sizeof(*req), GFP_KERNEL);
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
controlvm_respond(
&req->msg.hdr, CONTROLVM_RESP_SUCCESS,
&req->msg.cmd.device_change_state.state);
parahotplug_request_destroy(req);
return 0;
}
}
spin_unlock(&parahotplug_request_list_lock);
return -EINVAL;
}
static ssize_t devicedisabled_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned int id;
int err;
if (kstrtouint(buf, 10, &id))
return -EINVAL;
err = parahotplug_request_complete(id, 0);
if (err < 0)
return err;
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
return kobject_uevent_env(&chipset_dev->acpi_device->dev.kobj,
KOBJ_CHANGE, envp);
}
static int
parahotplug_process_message(struct controlvm_message *inmsg)
{
struct parahotplug_request *req;
int err;
req = parahotplug_request_create(inmsg);
if (!req)
return -ENOMEM;
if (inmsg->cmd.device_change_state.state.active) {
err = parahotplug_request_kickoff(req);
if (err)
goto err_respond;
controlvm_respond(&inmsg->hdr, CONTROLVM_RESP_SUCCESS,
&inmsg->cmd.device_change_state.state);
parahotplug_request_destroy(req);
return 0;
}
spin_lock(&parahotplug_request_list_lock);
list_add_tail(&req->list, &parahotplug_request_list);
spin_unlock(&parahotplug_request_list_lock);
err = parahotplug_request_kickoff(req);
if (err)
goto err_respond;
return 0;
err_respond:
controlvm_respond(&inmsg->hdr, err,
&inmsg->cmd.device_change_state.state);
return err;
}
static int
chipset_ready_uevent(struct controlvm_message_header *msg_hdr)
{
int res;
res = kobject_uevent(&chipset_dev->acpi_device->dev.kobj,
KOBJ_ONLINE);
if (msg_hdr->flags.response_expected)
controlvm_respond(msg_hdr, res, NULL);
return res;
}
static int
chipset_selftest_uevent(struct controlvm_message_header *msg_hdr)
{
char env_selftest[20];
char *envp[] = { env_selftest, NULL };
int res;
sprintf(env_selftest, "SPARSP_SELFTEST=%d", 1);
res = kobject_uevent_env(&chipset_dev->acpi_device->dev.kobj,
KOBJ_CHANGE, envp);
if (msg_hdr->flags.response_expected)
controlvm_respond(msg_hdr, res, NULL);
return res;
}
static int
chipset_notready_uevent(struct controlvm_message_header *msg_hdr)
{
int res;
res = kobject_uevent(&chipset_dev->acpi_device->dev.kobj,
KOBJ_OFFLINE);
if (msg_hdr->flags.response_expected)
controlvm_respond(msg_hdr, res, NULL);
return res;
}
static int unisys_vmcall(unsigned long tuple, unsigned long param)
{
int result = 0;
unsigned int cpuid_eax, cpuid_ebx, cpuid_ecx, cpuid_edx;
unsigned long reg_ebx;
unsigned long reg_ecx;
reg_ebx = param & 0xFFFFFFFF;
reg_ecx = param >> 32;
cpuid(0x00000001, &cpuid_eax, &cpuid_ebx, &cpuid_ecx, &cpuid_edx);
if (!(cpuid_ecx & 0x80000000))
return -EPERM;
__asm__ __volatile__(".byte 0x00f, 0x001, 0x0c1" : "=a"(result) :
"a"(tuple), "b"(reg_ebx), "c"(reg_ecx));
if (result)
goto error;
return 0;
error:
switch (result) {
case VMCALL_RESULT_INVALID_PARAM:
return -EINVAL;
case VMCALL_RESULT_DATA_UNAVAILABLE:
return -ENODEV;
default:
return -EFAULT;
}
}
static unsigned int
issue_vmcall_io_controlvm_addr(u64 *control_addr, u32 *control_bytes)
{
chipset_dev->controlvm_addr.physaddr = virt_to_phys(
&chipset_dev->controlvm_addr.params);
chipset_dev->controlvm_addr.err = unisys_vmcall(VMCALL_CONTROLVM_ADDR,
chipset_dev->controlvm_addr.physaddr);
if (chipset_dev->controlvm_addr.err)
return chipset_dev->controlvm_addr.err;
*control_addr = chipset_dev->controlvm_addr.params.address;
*control_bytes = chipset_dev->controlvm_addr.params.channel_bytes;
return 0;
}
static u64 controlvm_get_channel_address(void)
{
u64 addr = 0;
u32 size = 0;
if (issue_vmcall_io_controlvm_addr(&addr, &size))
return 0;
return addr;
}
static void
setup_crash_devices_work_queue(struct work_struct *work)
{
struct controlvm_message local_crash_bus_msg;
struct controlvm_message local_crash_dev_msg;
struct controlvm_message msg;
u32 local_crash_msg_offset;
u16 local_crash_msg_count;
msg.hdr.id = CONTROLVM_CHIPSET_INIT;
msg.cmd.init_chipset.bus_count = 23;
msg.cmd.init_chipset.switch_count = 0;
chipset_init(&msg);
if (visorchannel_read(chipset_dev->controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
saved_crash_message_count),
&local_crash_msg_count, sizeof(u16)) < 0) {
dev_err(&chipset_dev->acpi_device->dev,
"failed to read channel\n");
return;
}
if (local_crash_msg_count != CONTROLVM_CRASHMSG_MAX) {
dev_err(&chipset_dev->acpi_device->dev,
"invalid count\n");
return;
}
if (visorchannel_read(chipset_dev->controlvm_channel,
offsetof(struct spar_controlvm_channel_protocol,
saved_crash_message_offset),
&local_crash_msg_offset, sizeof(u32)) < 0) {
dev_err(&chipset_dev->acpi_device->dev,
"failed to read channel\n");
return;
}
if (visorchannel_read(chipset_dev->controlvm_channel,
local_crash_msg_offset,
&local_crash_bus_msg,
sizeof(struct controlvm_message)) < 0) {
dev_err(&chipset_dev->acpi_device->dev,
"failed to read channel\n");
return;
}
if (visorchannel_read(chipset_dev->controlvm_channel,
local_crash_msg_offset +
sizeof(struct controlvm_message),
&local_crash_dev_msg,
sizeof(struct controlvm_message)) < 0) {
dev_err(&chipset_dev->acpi_device->dev,
"failed to read channel\n");
return;
}
if (!local_crash_bus_msg.cmd.create_bus.channel_addr) {
dev_err(&chipset_dev->acpi_device->dev,
"no valid create_bus message\n");
return;
}
bus_create(&local_crash_bus_msg);
if (!local_crash_dev_msg.cmd.create_device.channel_addr) {
dev_err(&chipset_dev->acpi_device->dev,
"no valid create_device message\n");
return;
}
my_device_create(&local_crash_dev_msg);
}
void
bus_create_response(struct visor_device *bus_info, int response)
{
if (response >= 0)
bus_info->state.created = 1;
controlvm_responder(CONTROLVM_BUS_CREATE, bus_info->pending_msg_hdr,
response);
kfree(bus_info->pending_msg_hdr);
bus_info->pending_msg_hdr = NULL;
}
void
bus_destroy_response(struct visor_device *bus_info, int response)
{
controlvm_responder(CONTROLVM_BUS_DESTROY, bus_info->pending_msg_hdr,
response);
kfree(bus_info->pending_msg_hdr);
bus_info->pending_msg_hdr = NULL;
}
void
device_create_response(struct visor_device *dev_info, int response)
{
if (response >= 0)
dev_info->state.created = 1;
controlvm_responder(CONTROLVM_DEVICE_CREATE, dev_info->pending_msg_hdr,
response);
kfree(dev_info->pending_msg_hdr);
dev_info->pending_msg_hdr = NULL;
}
void
device_destroy_response(struct visor_device *dev_info, int response)
{
controlvm_responder(CONTROLVM_DEVICE_DESTROY, dev_info->pending_msg_hdr,
response);
kfree(dev_info->pending_msg_hdr);
dev_info->pending_msg_hdr = NULL;
}
void
device_pause_response(struct visor_device *dev_info,
int response)
{
device_changestate_responder(CONTROLVM_DEVICE_CHANGESTATE,
dev_info, response,
segment_state_standby);
kfree(dev_info->pending_msg_hdr);
dev_info->pending_msg_hdr = NULL;
}
void
device_resume_response(struct visor_device *dev_info, int response)
{
device_changestate_responder(CONTROLVM_DEVICE_CHANGESTATE,
dev_info, response,
segment_state_running);
kfree(dev_info->pending_msg_hdr);
dev_info->pending_msg_hdr = NULL;
}
static struct parser_context *
parser_init_byte_stream(u64 addr, u32 bytes, bool local, bool *retry)
{
int allocbytes = sizeof(struct parser_context) + bytes;
struct parser_context *ctx;
*retry = false;
allocbytes++;
if ((chipset_dev->controlvm_payload_bytes_buffered + bytes)
> MAX_CONTROLVM_PAYLOAD_BYTES) {
*retry = true;
return NULL;
}
ctx = kzalloc(allocbytes, GFP_KERNEL);
if (!ctx) {
*retry = true;
return NULL;
}
ctx->allocbytes = allocbytes;
ctx->param_bytes = bytes;
ctx->curr = NULL;
ctx->bytes_remaining = 0;
ctx->byte_stream = false;
if (local) {
void *p;
if (addr > virt_to_phys(high_memory - 1))
goto err_finish_ctx;
p = __va((unsigned long)(addr));
memcpy(ctx->data, p, bytes);
} else {
void *mapping = memremap(addr, bytes, MEMREMAP_WB);
if (!mapping)
goto err_finish_ctx;
memcpy(ctx->data, mapping, bytes);
memunmap(mapping);
}
ctx->byte_stream = true;
chipset_dev->controlvm_payload_bytes_buffered += ctx->param_bytes;
return ctx;
err_finish_ctx:
parser_done(ctx);
return NULL;
}
static int
handle_command(struct controlvm_message inmsg, u64 channel_addr)
{
struct controlvm_message_packet *cmd = &inmsg.cmd;
u64 parm_addr;
u32 parm_bytes;
struct parser_context *parser_ctx = NULL;
bool local_addr;
struct controlvm_message ackmsg;
int err = 0;
local_addr = (inmsg.hdr.flags.test_message == 1);
if (channel_addr == 0)
return -EINVAL;
parm_addr = channel_addr + inmsg.hdr.payload_vm_offset;
parm_bytes = inmsg.hdr.payload_bytes;
if (parm_addr && parm_bytes) {
bool retry = false;
parser_ctx =
parser_init_byte_stream(parm_addr, parm_bytes,
local_addr, &retry);
if (!parser_ctx && retry)
return -EAGAIN;
}
if (!local_addr) {
controlvm_init_response(&ackmsg, &inmsg.hdr,
CONTROLVM_RESP_SUCCESS);
err = visorchannel_signalinsert(chipset_dev->controlvm_channel,
CONTROLVM_QUEUE_ACK,
&ackmsg);
if (err)
return err;
}
switch (inmsg.hdr.id) {
case CONTROLVM_CHIPSET_INIT:
err = chipset_init(&inmsg);
break;
case CONTROLVM_BUS_CREATE:
err = bus_create(&inmsg);
break;
case CONTROLVM_BUS_DESTROY:
err = bus_destroy(&inmsg);
break;
case CONTROLVM_BUS_CONFIGURE:
err = bus_configure(&inmsg, parser_ctx);
break;
case CONTROLVM_DEVICE_CREATE:
err = my_device_create(&inmsg);
break;
case CONTROLVM_DEVICE_CHANGESTATE:
if (cmd->device_change_state.flags.phys_device) {
err = parahotplug_process_message(&inmsg);
} else {
err = my_device_changestate(&inmsg);
break;
}
break;
case CONTROLVM_DEVICE_DESTROY:
err = my_device_destroy(&inmsg);
break;
case CONTROLVM_DEVICE_CONFIGURE:
if (inmsg.hdr.flags.response_expected)
controlvm_respond(&inmsg.hdr, CONTROLVM_RESP_SUCCESS,
NULL);
break;
case CONTROLVM_CHIPSET_READY:
err = chipset_ready_uevent(&inmsg.hdr);
break;
case CONTROLVM_CHIPSET_SELFTEST:
err = chipset_selftest_uevent(&inmsg.hdr);
break;
case CONTROLVM_CHIPSET_STOP:
err = chipset_notready_uevent(&inmsg.hdr);
break;
default:
err = -ENOMSG;
if (inmsg.hdr.flags.response_expected)
controlvm_respond(&inmsg.hdr,
-CONTROLVM_RESP_ID_UNKNOWN, NULL);
break;
}
if (parser_ctx) {
parser_done(parser_ctx);
parser_ctx = NULL;
}
return err;
}
static int
read_controlvm_event(struct controlvm_message *msg)
{
int err;
err = visorchannel_signalremove(chipset_dev->controlvm_channel,
CONTROLVM_QUEUE_EVENT, msg);
if (err)
return err;
if (msg->hdr.flags.test_message == 1)
return -EINVAL;
return 0;
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
controlvm_respond(
&req->msg.hdr,
CONTROLVM_RESP_DEVICE_UDEV_TIMEOUT,
&req->msg.cmd.device_change_state.state);
parahotplug_request_destroy(req);
}
spin_unlock(&parahotplug_request_list_lock);
}
static void
controlvm_periodic_work(struct work_struct *work)
{
struct controlvm_message inmsg;
int count = 0;
int err;
do {
err = visorchannel_signalremove(chipset_dev->controlvm_channel,
CONTROLVM_QUEUE_RESPONSE,
&inmsg);
} while ((!err) && (++count < CONTROLVM_MESSAGE_MAX));
if (err != -EAGAIN)
goto schedule_out;
if (chipset_dev->controlvm_pending_msg_valid) {
inmsg = chipset_dev->controlvm_pending_msg;
chipset_dev->controlvm_pending_msg_valid = false;
err = 0;
} else {
err = read_controlvm_event(&inmsg);
}
while (!err) {
chipset_dev->most_recent_message_jiffies = jiffies;
err = handle_command(inmsg,
visorchannel_get_physaddr
(chipset_dev->controlvm_channel));
if (err == -EAGAIN) {
chipset_dev->controlvm_pending_msg = inmsg;
chipset_dev->controlvm_pending_msg_valid = true;
break;
}
err = read_controlvm_event(&inmsg);
}
parahotplug_process_list();
schedule_out:
if (time_after(jiffies, chipset_dev->most_recent_message_jiffies +
(HZ * MIN_IDLE_SECONDS))) {
if (chipset_dev->poll_jiffies !=
POLLJIFFIES_CONTROLVMCHANNEL_SLOW)
chipset_dev->poll_jiffies =
POLLJIFFIES_CONTROLVMCHANNEL_SLOW;
} else {
if (chipset_dev->poll_jiffies !=
POLLJIFFIES_CONTROLVMCHANNEL_FAST)
chipset_dev->poll_jiffies =
POLLJIFFIES_CONTROLVMCHANNEL_FAST;
}
schedule_delayed_work(&chipset_dev->periodic_controlvm_work,
chipset_dev->poll_jiffies);
}
static int
visorchipset_init(struct acpi_device *acpi_device)
{
int err = -ENODEV;
u64 addr;
uuid_le uuid = SPAR_CONTROLVM_CHANNEL_PROTOCOL_UUID;
struct visorchannel *controlvm_channel;
chipset_dev = kzalloc(sizeof(*chipset_dev), GFP_KERNEL);
if (!chipset_dev)
goto error;
addr = controlvm_get_channel_address();
if (!addr)
goto error;
acpi_device->driver_data = chipset_dev;
chipset_dev->acpi_device = acpi_device;
chipset_dev->poll_jiffies = POLLJIFFIES_CONTROLVMCHANNEL_FAST;
controlvm_channel = visorchannel_create_with_lock(addr,
0, GFP_KERNEL, uuid);
if (!controlvm_channel)
goto error_free_chipset_dev;
chipset_dev->controlvm_channel = controlvm_channel;
err = sysfs_create_groups(&chipset_dev->acpi_device->dev.kobj,
visorchipset_dev_groups);
if (err < 0)
goto error_destroy_channel;
if (!SPAR_CONTROLVM_CHANNEL_OK_CLIENT(
visorchannel_get_header(controlvm_channel)))
goto error_delete_groups;
if (is_kdump_kernel())
INIT_DELAYED_WORK(&chipset_dev->periodic_controlvm_work,
setup_crash_devices_work_queue);
else
INIT_DELAYED_WORK(&chipset_dev->periodic_controlvm_work,
controlvm_periodic_work);
chipset_dev->most_recent_message_jiffies = jiffies;
chipset_dev->poll_jiffies = POLLJIFFIES_CONTROLVMCHANNEL_FAST;
schedule_delayed_work(&chipset_dev->periodic_controlvm_work,
chipset_dev->poll_jiffies);
err = visorbus_init();
if (err < 0)
goto error_cancel_work;
return 0;
error_cancel_work:
cancel_delayed_work_sync(&chipset_dev->periodic_controlvm_work);
error_delete_groups:
sysfs_remove_groups(&chipset_dev->acpi_device->dev.kobj,
visorchipset_dev_groups);
error_destroy_channel:
visorchannel_destroy(chipset_dev->controlvm_channel);
error_free_chipset_dev:
kfree(chipset_dev);
error:
dev_err(&acpi_device->dev, "failed with error %d\n", err);
return err;
}
static int
visorchipset_exit(struct acpi_device *acpi_device)
{
visorbus_exit();
cancel_delayed_work_sync(&chipset_dev->periodic_controlvm_work);
sysfs_remove_groups(&chipset_dev->acpi_device->dev.kobj,
visorchipset_dev_groups);
visorchannel_destroy(chipset_dev->controlvm_channel);
kfree(chipset_dev);
return 0;
}
static __init int visorutil_spar_detect(void)
{
unsigned int eax, ebx, ecx, edx;
if (boot_cpu_has(X86_FEATURE_HYPERVISOR)) {
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
