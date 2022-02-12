char *smscore_translate_msg(enum msg_types msgtype)
{
int i = msgtype - MSG_TYPE_BASE_VAL;
char *msg;
if (i < 0 || i >= ARRAY_SIZE(siano_msgs))
return "Unknown msg type";
msg = siano_msgs[i];
if (!*msg)
return "Unknown msg type";
return msg;
}
void smscore_set_board_id(struct smscore_device_t *core, int id)
{
core->board_id = id;
}
int smscore_led_state(struct smscore_device_t *core, int led)
{
if (led >= 0)
core->led_state = led;
return core->led_state;
}
int smscore_get_board_id(struct smscore_device_t *core)
{
return core->board_id;
}
static struct smscore_registry_entry_t *smscore_find_registry(char *devpath)
{
struct smscore_registry_entry_t *entry;
struct list_head *next;
kmutex_lock(&g_smscore_registrylock);
for (next = g_smscore_registry.next;
next != &g_smscore_registry;
next = next->next) {
entry = (struct smscore_registry_entry_t *) next;
if (!strcmp(entry->devpath, devpath)) {
kmutex_unlock(&g_smscore_registrylock);
return entry;
}
}
entry = kmalloc(sizeof(struct smscore_registry_entry_t), GFP_KERNEL);
if (entry) {
entry->mode = default_mode;
strcpy(entry->devpath, devpath);
list_add(&entry->entry, &g_smscore_registry);
} else
sms_err("failed to create smscore_registry.");
kmutex_unlock(&g_smscore_registrylock);
return entry;
}
int smscore_registry_getmode(char *devpath)
{
struct smscore_registry_entry_t *entry;
entry = smscore_find_registry(devpath);
if (entry)
return entry->mode;
else
sms_err("No registry found.");
return default_mode;
}
static enum sms_device_type_st smscore_registry_gettype(char *devpath)
{
struct smscore_registry_entry_t *entry;
entry = smscore_find_registry(devpath);
if (entry)
return entry->type;
else
sms_err("No registry found.");
return -EINVAL;
}
static void smscore_registry_setmode(char *devpath, int mode)
{
struct smscore_registry_entry_t *entry;
entry = smscore_find_registry(devpath);
if (entry)
entry->mode = mode;
else
sms_err("No registry found.");
}
static void smscore_registry_settype(char *devpath,
enum sms_device_type_st type)
{
struct smscore_registry_entry_t *entry;
entry = smscore_find_registry(devpath);
if (entry)
entry->type = type;
else
sms_err("No registry found.");
}
static void list_add_locked(struct list_head *new, struct list_head *head,
spinlock_t *lock)
{
unsigned long flags;
spin_lock_irqsave(lock, flags);
list_add(new, head);
spin_unlock_irqrestore(lock, flags);
}
int smscore_register_hotplug(hotplug_t hotplug)
{
struct smscore_device_notifyee_t *notifyee;
struct list_head *next, *first;
int rc = 0;
kmutex_lock(&g_smscore_deviceslock);
notifyee = kmalloc(sizeof(struct smscore_device_notifyee_t),
GFP_KERNEL);
if (notifyee) {
first = &g_smscore_devices;
for (next = first->next;
next != first && !rc;
next = next->next) {
struct smscore_device_t *coredev =
(struct smscore_device_t *) next;
rc = hotplug(coredev, coredev->device, 1);
}
if (rc >= 0) {
notifyee->hotplug = hotplug;
list_add(&notifyee->entry, &g_smscore_notifyees);
} else
kfree(notifyee);
} else
rc = -ENOMEM;
kmutex_unlock(&g_smscore_deviceslock);
return rc;
}
void smscore_unregister_hotplug(hotplug_t hotplug)
{
struct list_head *next, *first;
kmutex_lock(&g_smscore_deviceslock);
first = &g_smscore_notifyees;
for (next = first->next; next != first;) {
struct smscore_device_notifyee_t *notifyee =
(struct smscore_device_notifyee_t *) next;
next = next->next;
if (notifyee->hotplug == hotplug) {
list_del(&notifyee->entry);
kfree(notifyee);
}
}
kmutex_unlock(&g_smscore_deviceslock);
}
static void smscore_notify_clients(struct smscore_device_t *coredev)
{
struct smscore_client_t *client;
while (!list_empty(&coredev->clients)) {
client = (struct smscore_client_t *) coredev->clients.next;
client->onremove_handler(client->context);
}
}
static int smscore_notify_callbacks(struct smscore_device_t *coredev,
struct device *device, int arrival)
{
struct smscore_device_notifyee_t *elem;
int rc = 0;
list_for_each_entry(elem, &g_smscore_notifyees, entry) {
rc = elem->hotplug(coredev, device, arrival);
if (rc < 0)
break;
}
return rc;
}
static struct
smscore_buffer_t *smscore_createbuffer(u8 *buffer, void *common_buffer,
dma_addr_t common_buffer_phys)
{
struct smscore_buffer_t *cb;
cb = kzalloc(sizeof(struct smscore_buffer_t), GFP_KERNEL);
if (!cb) {
sms_info("kzalloc(...) failed");
return NULL;
}
cb->p = buffer;
cb->offset_in_common = buffer - (u8 *) common_buffer;
cb->phys = common_buffer_phys + cb->offset_in_common;
return cb;
}
int smscore_register_device(struct smsdevice_params_t *params,
struct smscore_device_t **coredev)
{
struct smscore_device_t *dev;
u8 *buffer;
dev = kzalloc(sizeof(struct smscore_device_t), GFP_KERNEL);
if (!dev) {
sms_info("kzalloc(...) failed");
return -ENOMEM;
}
INIT_LIST_HEAD(&dev->entry);
INIT_LIST_HEAD(&dev->clients);
INIT_LIST_HEAD(&dev->buffers);
spin_lock_init(&dev->clientslock);
spin_lock_init(&dev->bufferslock);
init_completion(&dev->version_ex_done);
init_completion(&dev->data_download_done);
init_completion(&dev->data_validity_done);
init_completion(&dev->trigger_done);
init_completion(&dev->init_device_done);
init_completion(&dev->reload_start_done);
init_completion(&dev->resume_done);
init_completion(&dev->gpio_configuration_done);
init_completion(&dev->gpio_set_level_done);
init_completion(&dev->gpio_get_level_done);
init_completion(&dev->ir_init_done);
init_waitqueue_head(&dev->buffer_mng_waitq);
dev->common_buffer_size = params->buffer_size * params->num_buffers;
dev->common_buffer = dma_alloc_coherent(NULL, dev->common_buffer_size,
&dev->common_buffer_phys,
GFP_KERNEL | GFP_DMA);
if (!dev->common_buffer) {
smscore_unregister_device(dev);
return -ENOMEM;
}
for (buffer = dev->common_buffer;
dev->num_buffers < params->num_buffers;
dev->num_buffers++, buffer += params->buffer_size) {
struct smscore_buffer_t *cb;
cb = smscore_createbuffer(buffer, dev->common_buffer,
dev->common_buffer_phys);
if (!cb) {
smscore_unregister_device(dev);
return -ENOMEM;
}
smscore_putbuffer(dev, cb);
}
sms_info("allocated %d buffers", dev->num_buffers);
dev->mode = DEVICE_MODE_NONE;
dev->board_id = SMS_BOARD_UNKNOWN;
dev->context = params->context;
dev->device = params->device;
dev->setmode_handler = params->setmode_handler;
dev->detectmode_handler = params->detectmode_handler;
dev->sendrequest_handler = params->sendrequest_handler;
dev->preload_handler = params->preload_handler;
dev->postload_handler = params->postload_handler;
dev->device_flags = params->flags;
strcpy(dev->devpath, params->devpath);
smscore_registry_settype(dev->devpath, params->device_type);
kmutex_lock(&g_smscore_deviceslock);
list_add(&dev->entry, &g_smscore_devices);
kmutex_unlock(&g_smscore_deviceslock);
*coredev = dev;
sms_info("device %p created", dev);
return 0;
}
static int smscore_sendrequest_and_wait(struct smscore_device_t *coredev,
void *buffer, size_t size, struct completion *completion) {
int rc;
if (completion == NULL)
return -EINVAL;
init_completion(completion);
rc = coredev->sendrequest_handler(coredev->context, buffer, size);
if (rc < 0) {
sms_info("sendrequest returned error %d", rc);
return rc;
}
return wait_for_completion_timeout(completion,
msecs_to_jiffies(SMS_PROTOCOL_MAX_RAOUNDTRIP_MS)) ?
0 : -ETIME;
}
static int smscore_init_ir(struct smscore_device_t *coredev)
{
int ir_io;
int rc;
void *buffer;
coredev->ir.dev = NULL;
ir_io = sms_get_board(smscore_get_board_id(coredev))->board_cfg.ir;
if (ir_io) {
sms_info("IR loading");
rc = sms_ir_init(coredev);
if (rc != 0)
sms_err("Error initialization DTV IR sub-module");
else {
buffer = kmalloc(sizeof(struct sms_msg_data2) +
SMS_DMA_ALIGNMENT,
GFP_KERNEL | GFP_DMA);
if (buffer) {
struct sms_msg_data2 *msg =
(struct sms_msg_data2 *)
SMS_ALIGN_ADDRESS(buffer);
SMS_INIT_MSG(&msg->x_msg_header,
MSG_SMS_START_IR_REQ,
sizeof(struct sms_msg_data2));
msg->msg_data[0] = coredev->ir.controller;
msg->msg_data[1] = coredev->ir.timeout;
rc = smscore_sendrequest_and_wait(coredev, msg,
msg->x_msg_header. msg_length,
&coredev->ir_init_done);
kfree(buffer);
} else
sms_err
("Sending IR initialization message failed");
}
} else
sms_info("IR port has not been detected");
return 0;
}
static int smscore_configure_board(struct smscore_device_t *coredev)
{
struct sms_board *board;
board = sms_get_board(coredev->board_id);
if (!board) {
sms_err("no board configuration exist.");
return -EINVAL;
}
if (board->mtu) {
struct sms_msg_data mtu_msg;
sms_debug("set max transmit unit %d", board->mtu);
mtu_msg.x_msg_header.msg_src_id = 0;
mtu_msg.x_msg_header.msg_dst_id = HIF_TASK;
mtu_msg.x_msg_header.msg_flags = 0;
mtu_msg.x_msg_header.msg_type = MSG_SMS_SET_MAX_TX_MSG_LEN_REQ;
mtu_msg.x_msg_header.msg_length = sizeof(mtu_msg);
mtu_msg.msg_data[0] = board->mtu;
coredev->sendrequest_handler(coredev->context, &mtu_msg,
sizeof(mtu_msg));
}
if (board->crystal) {
struct sms_msg_data crys_msg;
sms_debug("set crystal value %d", board->crystal);
SMS_INIT_MSG(&crys_msg.x_msg_header,
MSG_SMS_NEW_CRYSTAL_REQ,
sizeof(crys_msg));
crys_msg.msg_data[0] = board->crystal;
coredev->sendrequest_handler(coredev->context, &crys_msg,
sizeof(crys_msg));
}
return 0;
}
int smscore_start_device(struct smscore_device_t *coredev)
{
int rc;
int board_id = smscore_get_board_id(coredev);
int mode = smscore_registry_getmode(coredev->devpath);
if (board_id != SMS_BOARD_UNKNOWN && mode == DEVICE_MODE_NONE)
mode = sms_get_board(board_id)->default_mode;
rc = smscore_set_device_mode(coredev, mode);
if (rc < 0) {
sms_info("set device mode faile , rc %d", rc);
return rc;
}
rc = smscore_configure_board(coredev);
if (rc < 0) {
sms_info("configure board failed , rc %d", rc);
return rc;
}
kmutex_lock(&g_smscore_deviceslock);
rc = smscore_notify_callbacks(coredev, coredev->device, 1);
smscore_init_ir(coredev);
sms_info("device %p started, rc %d", coredev, rc);
kmutex_unlock(&g_smscore_deviceslock);
return rc;
}
static int smscore_load_firmware_family2(struct smscore_device_t *coredev,
void *buffer, size_t size)
{
struct sms_firmware *firmware = (struct sms_firmware *) buffer;
struct sms_msg_data4 *msg;
u32 mem_address, calc_checksum = 0;
u32 i, *ptr;
u8 *payload = firmware->payload;
int rc = 0;
firmware->start_address = le32_to_cpu(firmware->start_address);
firmware->length = le32_to_cpu(firmware->length);
mem_address = firmware->start_address;
sms_info("loading FW to addr 0x%x size %d",
mem_address, firmware->length);
if (coredev->preload_handler) {
rc = coredev->preload_handler(coredev->context);
if (rc < 0)
return rc;
}
msg = kmalloc(PAGE_SIZE, GFP_KERNEL | GFP_DMA);
if (!msg)
return -ENOMEM;
if (coredev->mode != DEVICE_MODE_NONE) {
sms_debug("sending reload command.");
SMS_INIT_MSG(&msg->x_msg_header, MSG_SW_RELOAD_START_REQ,
sizeof(struct sms_msg_hdr));
rc = smscore_sendrequest_and_wait(coredev, msg,
msg->x_msg_header.msg_length,
&coredev->reload_start_done);
if (rc < 0) {
sms_err("device reload failed, rc %d", rc);
goto exit_fw_download;
}
mem_address = *(u32 *) &payload[20];
}
for (i = 0, ptr = (u32 *)firmware->payload; i < firmware->length/4 ;
i++, ptr++)
calc_checksum += *ptr;
while (size && rc >= 0) {
struct sms_data_download *data_msg =
(struct sms_data_download *) msg;
int payload_size = min_t(int, size, SMS_MAX_PAYLOAD_SIZE);
SMS_INIT_MSG(&msg->x_msg_header, MSG_SMS_DATA_DOWNLOAD_REQ,
(u16)(sizeof(struct sms_msg_hdr) +
sizeof(u32) + payload_size));
data_msg->mem_addr = mem_address;
memcpy(data_msg->payload, payload, payload_size);
rc = smscore_sendrequest_and_wait(coredev, data_msg,
data_msg->x_msg_header.msg_length,
&coredev->data_download_done);
payload += payload_size;
size -= payload_size;
mem_address += payload_size;
}
if (rc < 0)
goto exit_fw_download;
sms_err("sending MSG_SMS_DATA_VALIDITY_REQ expecting 0x%x",
calc_checksum);
SMS_INIT_MSG(&msg->x_msg_header, MSG_SMS_DATA_VALIDITY_REQ,
sizeof(msg->x_msg_header) +
sizeof(u32) * 3);
msg->msg_data[0] = firmware->start_address;
msg->msg_data[1] = firmware->length;
msg->msg_data[2] = 0;
rc = smscore_sendrequest_and_wait(coredev, msg,
msg->x_msg_header.msg_length,
&coredev->data_validity_done);
if (rc < 0)
goto exit_fw_download;
if (coredev->mode == DEVICE_MODE_NONE) {
struct sms_msg_data *trigger_msg =
(struct sms_msg_data *) msg;
sms_debug("sending MSG_SMS_SWDOWNLOAD_TRIGGER_REQ");
SMS_INIT_MSG(&msg->x_msg_header,
MSG_SMS_SWDOWNLOAD_TRIGGER_REQ,
sizeof(struct sms_msg_hdr) +
sizeof(u32) * 5);
trigger_msg->msg_data[0] = firmware->start_address;
trigger_msg->msg_data[1] = 6;
trigger_msg->msg_data[2] = 0x200;
trigger_msg->msg_data[3] = 0;
trigger_msg->msg_data[4] = 4;
rc = smscore_sendrequest_and_wait(coredev, trigger_msg,
trigger_msg->x_msg_header.msg_length,
&coredev->trigger_done);
} else {
SMS_INIT_MSG(&msg->x_msg_header, MSG_SW_RELOAD_EXEC_REQ,
sizeof(struct sms_msg_hdr));
rc = coredev->sendrequest_handler(coredev->context, msg,
msg->x_msg_header.msg_length);
}
if (rc < 0)
goto exit_fw_download;
msleep(400);
exit_fw_download:
kfree(msg);
if (coredev->postload_handler) {
sms_debug("rc=%d, postload=0x%p", rc, coredev->postload_handler);
if (rc >= 0)
return coredev->postload_handler(coredev->context);
}
sms_debug("rc=%d", rc);
return rc;
}
static char *smscore_get_fw_filename(struct smscore_device_t *coredev,
int mode)
{
char **fw;
int board_id = smscore_get_board_id(coredev);
enum sms_device_type_st type;
type = smscore_registry_gettype(coredev->devpath);
if (type <= SMS_UNKNOWN_TYPE || type >= SMS_NUM_OF_DEVICE_TYPES)
return NULL;
if (mode <= DEVICE_MODE_NONE || mode >= DEVICE_MODE_MAX)
return NULL;
sms_debug("trying to get fw name from sms_boards board_id %d mode %d",
board_id, mode);
fw = sms_get_board(board_id)->fw;
if (!fw || !fw[mode]) {
sms_debug("cannot find fw name in sms_boards, getting from lookup table mode %d type %d",
mode, type);
return smscore_fw_lkup[type][mode];
}
return fw[mode];
}
static int smscore_load_firmware_from_file(struct smscore_device_t *coredev,
int mode,
loadfirmware_t loadfirmware_handler)
{
int rc = -ENOENT;
u8 *fw_buf;
u32 fw_buf_size;
const struct firmware *fw;
char *fw_filename = smscore_get_fw_filename(coredev, mode);
if (!fw_filename) {
sms_err("mode %d not supported on this device", mode);
return -ENOENT;
}
sms_debug("Firmware name: %s", fw_filename);
if (loadfirmware_handler == NULL && !(coredev->device_flags
& SMS_DEVICE_FAMILY2))
return -EINVAL;
rc = request_firmware(&fw, fw_filename, coredev->device);
if (rc < 0) {
sms_err("failed to open firmware file \"%s\"", fw_filename);
return rc;
}
sms_info("read fw %s, buffer size=0x%zx", fw_filename, fw->size);
fw_buf = kmalloc(ALIGN(fw->size, SMS_ALLOC_ALIGNMENT),
GFP_KERNEL | GFP_DMA);
if (!fw_buf) {
sms_err("failed to allocate firmware buffer");
rc = -ENOMEM;
} else {
memcpy(fw_buf, fw->data, fw->size);
fw_buf_size = fw->size;
rc = (coredev->device_flags & SMS_DEVICE_FAMILY2) ?
smscore_load_firmware_family2(coredev, fw_buf, fw_buf_size)
: loadfirmware_handler(coredev->context, fw_buf,
fw_buf_size);
}
kfree(fw_buf);
release_firmware(fw);
return rc;
}
void smscore_unregister_device(struct smscore_device_t *coredev)
{
struct smscore_buffer_t *cb;
int num_buffers = 0;
int retry = 0;
kmutex_lock(&g_smscore_deviceslock);
sms_ir_exit(coredev);
smscore_notify_clients(coredev);
smscore_notify_callbacks(coredev, NULL, 0);
while (1) {
while (!list_empty(&coredev->buffers)) {
cb = (struct smscore_buffer_t *) coredev->buffers.next;
list_del(&cb->entry);
kfree(cb);
num_buffers++;
}
if (num_buffers == coredev->num_buffers)
break;
if (++retry > 10) {
sms_info("exiting although not all buffers released.");
break;
}
sms_info("waiting for %d buffer(s)",
coredev->num_buffers - num_buffers);
kmutex_unlock(&g_smscore_deviceslock);
msleep(100);
kmutex_lock(&g_smscore_deviceslock);
}
sms_info("freed %d buffers", num_buffers);
if (coredev->common_buffer)
dma_free_coherent(NULL, coredev->common_buffer_size,
coredev->common_buffer, coredev->common_buffer_phys);
kfree(coredev->fw_buf);
list_del(&coredev->entry);
kfree(coredev);
kmutex_unlock(&g_smscore_deviceslock);
sms_info("device %p destroyed", coredev);
}
static int smscore_detect_mode(struct smscore_device_t *coredev)
{
void *buffer = kmalloc(sizeof(struct sms_msg_hdr) + SMS_DMA_ALIGNMENT,
GFP_KERNEL | GFP_DMA);
struct sms_msg_hdr *msg =
(struct sms_msg_hdr *) SMS_ALIGN_ADDRESS(buffer);
int rc;
if (!buffer)
return -ENOMEM;
SMS_INIT_MSG(msg, MSG_SMS_GET_VERSION_EX_REQ,
sizeof(struct sms_msg_hdr));
rc = smscore_sendrequest_and_wait(coredev, msg, msg->msg_length,
&coredev->version_ex_done);
if (rc == -ETIME) {
sms_err("MSG_SMS_GET_VERSION_EX_REQ failed first try");
if (wait_for_completion_timeout(&coredev->resume_done,
msecs_to_jiffies(5000))) {
rc = smscore_sendrequest_and_wait(
coredev, msg, msg->msg_length,
&coredev->version_ex_done);
if (rc < 0)
sms_err("MSG_SMS_GET_VERSION_EX_REQ failed second try, rc %d",
rc);
} else
rc = -ETIME;
}
kfree(buffer);
return rc;
}
static int smscore_init_device(struct smscore_device_t *coredev, int mode)
{
void *buffer;
struct sms_msg_data *msg;
int rc = 0;
buffer = kmalloc(sizeof(struct sms_msg_data) +
SMS_DMA_ALIGNMENT, GFP_KERNEL | GFP_DMA);
if (!buffer) {
sms_err("Could not allocate buffer for init device message.");
return -ENOMEM;
}
msg = (struct sms_msg_data *)SMS_ALIGN_ADDRESS(buffer);
SMS_INIT_MSG(&msg->x_msg_header, MSG_SMS_INIT_DEVICE_REQ,
sizeof(struct sms_msg_data));
msg->msg_data[0] = mode;
rc = smscore_sendrequest_and_wait(coredev, msg,
msg->x_msg_header. msg_length,
&coredev->init_device_done);
kfree(buffer);
return rc;
}
int smscore_set_device_mode(struct smscore_device_t *coredev, int mode)
{
int rc = 0;
sms_debug("set device mode to %d", mode);
if (coredev->device_flags & SMS_DEVICE_FAMILY2) {
if (mode <= DEVICE_MODE_NONE || mode >= DEVICE_MODE_MAX) {
sms_err("invalid mode specified %d", mode);
return -EINVAL;
}
smscore_registry_setmode(coredev->devpath, mode);
if (!(coredev->device_flags & SMS_DEVICE_NOT_READY)) {
rc = smscore_detect_mode(coredev);
if (rc < 0) {
sms_err("mode detect failed %d", rc);
return rc;
}
}
if (coredev->mode == mode) {
sms_info("device mode %d already set", mode);
return 0;
}
if (!(coredev->modes_supported & (1 << mode))) {
rc = smscore_load_firmware_from_file(coredev,
mode, NULL);
if (rc >= 0)
sms_info("firmware download success");
} else {
sms_info("mode %d is already supported by running firmware",
mode);
}
if (coredev->fw_version >= 0x800) {
rc = smscore_init_device(coredev, mode);
if (rc < 0)
sms_err("device init failed, rc %d.", rc);
}
} else {
if (mode <= DEVICE_MODE_NONE || mode >= DEVICE_MODE_MAX) {
sms_err("invalid mode specified %d", mode);
return -EINVAL;
}
smscore_registry_setmode(coredev->devpath, mode);
if (coredev->detectmode_handler)
coredev->detectmode_handler(coredev->context,
&coredev->mode);
if (coredev->mode != mode && coredev->setmode_handler)
rc = coredev->setmode_handler(coredev->context, mode);
}
if (rc >= 0) {
char *buffer;
coredev->mode = mode;
coredev->device_flags &= ~SMS_DEVICE_NOT_READY;
buffer = kmalloc(sizeof(struct sms_msg_data) +
SMS_DMA_ALIGNMENT, GFP_KERNEL | GFP_DMA);
if (buffer) {
struct sms_msg_data *msg = (struct sms_msg_data *) SMS_ALIGN_ADDRESS(buffer);
SMS_INIT_MSG(&msg->x_msg_header, MSG_SMS_INIT_DEVICE_REQ,
sizeof(struct sms_msg_data));
msg->msg_data[0] = mode;
rc = smscore_sendrequest_and_wait(
coredev, msg, msg->x_msg_header.msg_length,
&coredev->init_device_done);
kfree(buffer);
}
}
if (rc < 0)
sms_err("return error code %d.", rc);
else
sms_debug("Success setting device mode.");
return rc;
}
int smscore_get_device_mode(struct smscore_device_t *coredev)
{
return coredev->mode;
}
static struct
smscore_client_t *smscore_find_client(struct smscore_device_t *coredev,
int data_type, int id)
{
struct list_head *first;
struct smscore_client_t *client;
unsigned long flags;
struct list_head *firstid;
struct smscore_idlist_t *client_id;
spin_lock_irqsave(&coredev->clientslock, flags);
first = &coredev->clients;
list_for_each_entry(client, first, entry) {
firstid = &client->idlist;
list_for_each_entry(client_id, firstid, entry) {
if ((client_id->id == id) &&
(client_id->data_type == data_type ||
(client_id->data_type == 0)))
goto found;
}
}
client = NULL;
found:
spin_unlock_irqrestore(&coredev->clientslock, flags);
return client;
}
void smscore_onresponse(struct smscore_device_t *coredev,
struct smscore_buffer_t *cb) {
struct sms_msg_hdr *phdr = (struct sms_msg_hdr *) ((u8 *) cb->p
+ cb->offset);
struct smscore_client_t *client;
int rc = -EBUSY;
static unsigned long last_sample_time;
static int data_total;
unsigned long time_now = jiffies_to_msecs(jiffies);
if (!last_sample_time)
last_sample_time = time_now;
if (time_now - last_sample_time > 10000) {
sms_debug("data rate %d bytes/secs",
(int)((data_total * 1000) /
(time_now - last_sample_time)));
last_sample_time = time_now;
data_total = 0;
}
data_total += cb->size;
if ((phdr->msg_type == MSG_SMS_HO_PER_SLICES_IND) ||
(phdr->msg_type == MSG_SMS_TRANSMISSION_IND)) {
if (coredev->mode == DEVICE_MODE_DVBT_BDA)
phdr->msg_dst_id = DVBT_BDA_CONTROL_MSG_ID;
}
client = smscore_find_client(coredev, phdr->msg_type, phdr->msg_dst_id);
if (client)
rc = client->onresponse_handler(client->context, cb);
if (rc < 0) {
switch (phdr->msg_type) {
case MSG_SMS_ISDBT_TUNE_RES:
break;
case MSG_SMS_RF_TUNE_RES:
break;
case MSG_SMS_SIGNAL_DETECTED_IND:
break;
case MSG_SMS_NO_SIGNAL_IND:
break;
case MSG_SMS_SPI_INT_LINE_SET_RES:
break;
case MSG_SMS_INTERFACE_LOCK_IND:
break;
case MSG_SMS_INTERFACE_UNLOCK_IND:
break;
case MSG_SMS_GET_VERSION_EX_RES:
{
struct sms_version_res *ver =
(struct sms_version_res *) phdr;
sms_debug("Firmware id %d prots 0x%x ver %d.%d",
ver->firmware_id, ver->supported_protocols,
ver->rom_ver_major, ver->rom_ver_minor);
coredev->mode = ver->firmware_id == 255 ?
DEVICE_MODE_NONE : ver->firmware_id;
coredev->modes_supported = ver->supported_protocols;
coredev->fw_version = ver->rom_ver_major << 8 |
ver->rom_ver_minor;
complete(&coredev->version_ex_done);
break;
}
case MSG_SMS_INIT_DEVICE_RES:
complete(&coredev->init_device_done);
break;
case MSG_SW_RELOAD_START_RES:
complete(&coredev->reload_start_done);
break;
case MSG_SMS_DATA_VALIDITY_RES:
{
struct sms_msg_data *validity = (struct sms_msg_data *) phdr;
sms_err("MSG_SMS_DATA_VALIDITY_RES, checksum = 0x%x",
validity->msg_data[0]);
complete(&coredev->data_validity_done);
break;
}
case MSG_SMS_DATA_DOWNLOAD_RES:
complete(&coredev->data_download_done);
break;
case MSG_SW_RELOAD_EXEC_RES:
break;
case MSG_SMS_SWDOWNLOAD_TRIGGER_RES:
complete(&coredev->trigger_done);
break;
case MSG_SMS_SLEEP_RESUME_COMP_IND:
complete(&coredev->resume_done);
break;
case MSG_SMS_GPIO_CONFIG_EX_RES:
complete(&coredev->gpio_configuration_done);
break;
case MSG_SMS_GPIO_SET_LEVEL_RES:
complete(&coredev->gpio_set_level_done);
break;
case MSG_SMS_GPIO_GET_LEVEL_RES:
{
u32 *msgdata = (u32 *) phdr;
coredev->gpio_get_res = msgdata[1];
sms_debug("gpio level %d",
coredev->gpio_get_res);
complete(&coredev->gpio_get_level_done);
break;
}
case MSG_SMS_START_IR_RES:
complete(&coredev->ir_init_done);
break;
case MSG_SMS_IR_SAMPLES_IND:
sms_ir_event(coredev,
(const char *)
((char *)phdr
+ sizeof(struct sms_msg_hdr)),
(int)phdr->msg_length
- sizeof(struct sms_msg_hdr));
break;
case MSG_SMS_DVBT_BDA_DATA:
break;
default:
sms_debug("message %s(%d) not handled.",
smscore_translate_msg(phdr->msg_type),
phdr->msg_type);
break;
}
smscore_putbuffer(coredev, cb);
}
}
static struct smscore_buffer_t *get_entry(struct smscore_device_t *coredev)
{
struct smscore_buffer_t *cb = NULL;
unsigned long flags;
spin_lock_irqsave(&coredev->bufferslock, flags);
if (!list_empty(&coredev->buffers)) {
cb = (struct smscore_buffer_t *) coredev->buffers.next;
list_del(&cb->entry);
}
spin_unlock_irqrestore(&coredev->bufferslock, flags);
return cb;
}
struct smscore_buffer_t *smscore_getbuffer(struct smscore_device_t *coredev)
{
struct smscore_buffer_t *cb = NULL;
wait_event(coredev->buffer_mng_waitq, (cb = get_entry(coredev)));
return cb;
}
void smscore_putbuffer(struct smscore_device_t *coredev,
struct smscore_buffer_t *cb) {
wake_up_interruptible(&coredev->buffer_mng_waitq);
list_add_locked(&cb->entry, &coredev->buffers, &coredev->bufferslock);
}
static int smscore_validate_client(struct smscore_device_t *coredev,
struct smscore_client_t *client,
int data_type, int id)
{
struct smscore_idlist_t *listentry;
struct smscore_client_t *registered_client;
if (!client) {
sms_err("bad parameter.");
return -EINVAL;
}
registered_client = smscore_find_client(coredev, data_type, id);
if (registered_client == client)
return 0;
if (registered_client) {
sms_err("The msg ID already registered to another client.");
return -EEXIST;
}
listentry = kzalloc(sizeof(struct smscore_idlist_t), GFP_KERNEL);
if (!listentry) {
sms_err("Can't allocate memory for client id.");
return -ENOMEM;
}
listentry->id = id;
listentry->data_type = data_type;
list_add_locked(&listentry->entry, &client->idlist,
&coredev->clientslock);
return 0;
}
int smscore_register_client(struct smscore_device_t *coredev,
struct smsclient_params_t *params,
struct smscore_client_t **client)
{
struct smscore_client_t *newclient;
if (smscore_find_client(coredev, params->data_type,
params->initial_id)) {
sms_err("Client already exist.");
return -EEXIST;
}
newclient = kzalloc(sizeof(struct smscore_client_t), GFP_KERNEL);
if (!newclient) {
sms_err("Failed to allocate memory for client.");
return -ENOMEM;
}
INIT_LIST_HEAD(&newclient->idlist);
newclient->coredev = coredev;
newclient->onresponse_handler = params->onresponse_handler;
newclient->onremove_handler = params->onremove_handler;
newclient->context = params->context;
list_add_locked(&newclient->entry, &coredev->clients,
&coredev->clientslock);
smscore_validate_client(coredev, newclient, params->data_type,
params->initial_id);
*client = newclient;
sms_debug("%p %d %d", params->context, params->data_type,
params->initial_id);
return 0;
}
void smscore_unregister_client(struct smscore_client_t *client)
{
struct smscore_device_t *coredev = client->coredev;
unsigned long flags;
spin_lock_irqsave(&coredev->clientslock, flags);
while (!list_empty(&client->idlist)) {
struct smscore_idlist_t *identry =
(struct smscore_idlist_t *) client->idlist.next;
list_del(&identry->entry);
kfree(identry);
}
sms_info("%p", client->context);
list_del(&client->entry);
kfree(client);
spin_unlock_irqrestore(&coredev->clientslock, flags);
}
int smsclient_sendrequest(struct smscore_client_t *client,
void *buffer, size_t size)
{
struct smscore_device_t *coredev;
struct sms_msg_hdr *phdr = (struct sms_msg_hdr *) buffer;
int rc;
if (client == NULL) {
sms_err("Got NULL client");
return -EINVAL;
}
coredev = client->coredev;
if (coredev == NULL) {
sms_err("Got NULL coredev");
return -EINVAL;
}
rc = smscore_validate_client(client->coredev, client, 0,
phdr->msg_src_id);
if (rc < 0)
return rc;
return coredev->sendrequest_handler(coredev->context, buffer, size);
}
int smscore_configure_gpio(struct smscore_device_t *coredev, u32 pin,
struct smscore_config_gpio *pinconfig)
{
struct {
struct sms_msg_hdr hdr;
u32 data[6];
} msg;
if (coredev->device_flags & SMS_DEVICE_FAMILY2) {
msg.hdr.msg_src_id = DVBT_BDA_CONTROL_MSG_ID;
msg.hdr.msg_dst_id = HIF_TASK;
msg.hdr.msg_flags = 0;
msg.hdr.msg_type = MSG_SMS_GPIO_CONFIG_EX_REQ;
msg.hdr.msg_length = sizeof(msg);
msg.data[0] = pin;
msg.data[1] = pinconfig->pullupdown;
msg.data[2] = pinconfig->outputslewrate == 0 ? 3 : 0;
switch (pinconfig->outputdriving) {
case SMS_GPIO_OUTPUTDRIVING_S_16mA:
msg.data[3] = 7;
break;
case SMS_GPIO_OUTPUTDRIVING_S_12mA:
msg.data[3] = 5;
break;
case SMS_GPIO_OUTPUTDRIVING_S_8mA:
msg.data[3] = 3;
break;
case SMS_GPIO_OUTPUTDRIVING_S_4mA:
default:
msg.data[3] = 2;
break;
}
msg.data[4] = pinconfig->direction;
msg.data[5] = 0;
} else
return -EINVAL;
return coredev->sendrequest_handler(coredev->context,
&msg, sizeof(msg));
}
int smscore_set_gpio(struct smscore_device_t *coredev, u32 pin, int level)
{
struct {
struct sms_msg_hdr hdr;
u32 data[3];
} msg;
if (pin > MAX_GPIO_PIN_NUMBER)
return -EINVAL;
msg.hdr.msg_src_id = DVBT_BDA_CONTROL_MSG_ID;
msg.hdr.msg_dst_id = HIF_TASK;
msg.hdr.msg_flags = 0;
msg.hdr.msg_type = MSG_SMS_GPIO_SET_LEVEL_REQ;
msg.hdr.msg_length = sizeof(msg);
msg.data[0] = pin;
msg.data[1] = level ? 1 : 0;
msg.data[2] = 0;
return coredev->sendrequest_handler(coredev->context,
&msg, sizeof(msg));
}
static int get_gpio_pin_params(u32 pin_num, u32 *p_translatedpin_num,
u32 *p_group_num, u32 *p_group_cfg) {
*p_group_cfg = 1;
if (pin_num <= 1) {
*p_translatedpin_num = 0;
*p_group_num = 9;
*p_group_cfg = 2;
} else if (pin_num >= 2 && pin_num <= 6) {
*p_translatedpin_num = 2;
*p_group_num = 0;
*p_group_cfg = 2;
} else if (pin_num >= 7 && pin_num <= 11) {
*p_translatedpin_num = 7;
*p_group_num = 1;
} else if (pin_num >= 12 && pin_num <= 15) {
*p_translatedpin_num = 12;
*p_group_num = 2;
*p_group_cfg = 3;
} else if (pin_num == 16) {
*p_translatedpin_num = 16;
*p_group_num = 23;
} else if (pin_num >= 17 && pin_num <= 24) {
*p_translatedpin_num = 17;
*p_group_num = 3;
} else if (pin_num == 25) {
*p_translatedpin_num = 25;
*p_group_num = 6;
} else if (pin_num >= 26 && pin_num <= 28) {
*p_translatedpin_num = 26;
*p_group_num = 4;
} else if (pin_num == 29) {
*p_translatedpin_num = 29;
*p_group_num = 5;
*p_group_cfg = 2;
} else if (pin_num == 30) {
*p_translatedpin_num = 30;
*p_group_num = 8;
} else if (pin_num == 31) {
*p_translatedpin_num = 31;
*p_group_num = 17;
} else
return -1;
*p_group_cfg <<= 24;
return 0;
}
int smscore_gpio_configure(struct smscore_device_t *coredev, u8 pin_num,
struct smscore_config_gpio *p_gpio_config) {
u32 total_len;
u32 translatedpin_num = 0;
u32 group_num = 0;
u32 electric_char;
u32 group_cfg;
void *buffer;
int rc;
struct set_gpio_msg {
struct sms_msg_hdr x_msg_header;
u32 msg_data[6];
} *p_msg;
if (pin_num > MAX_GPIO_PIN_NUMBER)
return -EINVAL;
if (p_gpio_config == NULL)
return -EINVAL;
total_len = sizeof(struct sms_msg_hdr) + (sizeof(u32) * 6);
buffer = kmalloc(total_len + SMS_DMA_ALIGNMENT,
GFP_KERNEL | GFP_DMA);
if (!buffer)
return -ENOMEM;
p_msg = (struct set_gpio_msg *) SMS_ALIGN_ADDRESS(buffer);
p_msg->x_msg_header.msg_src_id = DVBT_BDA_CONTROL_MSG_ID;
p_msg->x_msg_header.msg_dst_id = HIF_TASK;
p_msg->x_msg_header.msg_flags = 0;
p_msg->x_msg_header.msg_length = (u16) total_len;
p_msg->msg_data[0] = pin_num;
if (!(coredev->device_flags & SMS_DEVICE_FAMILY2)) {
p_msg->x_msg_header.msg_type = MSG_SMS_GPIO_CONFIG_REQ;
if (get_gpio_pin_params(pin_num, &translatedpin_num, &group_num,
&group_cfg) != 0) {
rc = -EINVAL;
goto free;
}
p_msg->msg_data[1] = translatedpin_num;
p_msg->msg_data[2] = group_num;
electric_char = (p_gpio_config->pullupdown)
| (p_gpio_config->inputcharacteristics << 2)
| (p_gpio_config->outputslewrate << 3)
| (p_gpio_config->outputdriving << 4);
p_msg->msg_data[3] = electric_char;
p_msg->msg_data[4] = p_gpio_config->direction;
p_msg->msg_data[5] = group_cfg;
} else {
p_msg->x_msg_header.msg_type = MSG_SMS_GPIO_CONFIG_EX_REQ;
p_msg->msg_data[1] = p_gpio_config->pullupdown;
p_msg->msg_data[2] = p_gpio_config->outputslewrate;
p_msg->msg_data[3] = p_gpio_config->outputdriving;
p_msg->msg_data[4] = p_gpio_config->direction;
p_msg->msg_data[5] = 0;
}
rc = smscore_sendrequest_and_wait(coredev, p_msg, total_len,
&coredev->gpio_configuration_done);
if (rc != 0) {
if (rc == -ETIME)
sms_err("smscore_gpio_configure timeout");
else
sms_err("smscore_gpio_configure error");
}
free:
kfree(buffer);
return rc;
}
int smscore_gpio_set_level(struct smscore_device_t *coredev, u8 pin_num,
u8 new_level) {
u32 total_len;
int rc;
void *buffer;
struct set_gpio_msg {
struct sms_msg_hdr x_msg_header;
u32 msg_data[3];
} *p_msg;
if ((new_level > 1) || (pin_num > MAX_GPIO_PIN_NUMBER))
return -EINVAL;
total_len = sizeof(struct sms_msg_hdr) +
(3 * sizeof(u32));
buffer = kmalloc(total_len + SMS_DMA_ALIGNMENT,
GFP_KERNEL | GFP_DMA);
if (!buffer)
return -ENOMEM;
p_msg = (struct set_gpio_msg *) SMS_ALIGN_ADDRESS(buffer);
p_msg->x_msg_header.msg_src_id = DVBT_BDA_CONTROL_MSG_ID;
p_msg->x_msg_header.msg_dst_id = HIF_TASK;
p_msg->x_msg_header.msg_flags = 0;
p_msg->x_msg_header.msg_type = MSG_SMS_GPIO_SET_LEVEL_REQ;
p_msg->x_msg_header.msg_length = (u16) total_len;
p_msg->msg_data[0] = pin_num;
p_msg->msg_data[1] = new_level;
rc = smscore_sendrequest_and_wait(coredev, p_msg, total_len,
&coredev->gpio_set_level_done);
if (rc != 0) {
if (rc == -ETIME)
sms_err("smscore_gpio_set_level timeout");
else
sms_err("smscore_gpio_set_level error");
}
kfree(buffer);
return rc;
}
int smscore_gpio_get_level(struct smscore_device_t *coredev, u8 pin_num,
u8 *level) {
u32 total_len;
int rc;
void *buffer;
struct set_gpio_msg {
struct sms_msg_hdr x_msg_header;
u32 msg_data[2];
} *p_msg;
if (pin_num > MAX_GPIO_PIN_NUMBER)
return -EINVAL;
total_len = sizeof(struct sms_msg_hdr) + (2 * sizeof(u32));
buffer = kmalloc(total_len + SMS_DMA_ALIGNMENT,
GFP_KERNEL | GFP_DMA);
if (!buffer)
return -ENOMEM;
p_msg = (struct set_gpio_msg *) SMS_ALIGN_ADDRESS(buffer);
p_msg->x_msg_header.msg_src_id = DVBT_BDA_CONTROL_MSG_ID;
p_msg->x_msg_header.msg_dst_id = HIF_TASK;
p_msg->x_msg_header.msg_flags = 0;
p_msg->x_msg_header.msg_type = MSG_SMS_GPIO_GET_LEVEL_REQ;
p_msg->x_msg_header.msg_length = (u16) total_len;
p_msg->msg_data[0] = pin_num;
p_msg->msg_data[1] = 0;
rc = smscore_sendrequest_and_wait(coredev, p_msg, total_len,
&coredev->gpio_get_level_done);
if (rc != 0) {
if (rc == -ETIME)
sms_err("smscore_gpio_get_level timeout");
else
sms_err("smscore_gpio_get_level error");
}
kfree(buffer);
*level = coredev->gpio_get_res;
return rc;
}
static int __init smscore_module_init(void)
{
int rc = 0;
INIT_LIST_HEAD(&g_smscore_notifyees);
INIT_LIST_HEAD(&g_smscore_devices);
kmutex_init(&g_smscore_deviceslock);
INIT_LIST_HEAD(&g_smscore_registry);
kmutex_init(&g_smscore_registrylock);
return rc;
}
static void __exit smscore_module_exit(void)
{
kmutex_lock(&g_smscore_deviceslock);
while (!list_empty(&g_smscore_notifyees)) {
struct smscore_device_notifyee_t *notifyee =
(struct smscore_device_notifyee_t *)
g_smscore_notifyees.next;
list_del(&notifyee->entry);
kfree(notifyee);
}
kmutex_unlock(&g_smscore_deviceslock);
kmutex_lock(&g_smscore_registrylock);
while (!list_empty(&g_smscore_registry)) {
struct smscore_registry_entry_t *entry =
(struct smscore_registry_entry_t *)
g_smscore_registry.next;
list_del(&entry->entry);
kfree(entry);
}
kmutex_unlock(&g_smscore_registrylock);
sms_debug("");
}
