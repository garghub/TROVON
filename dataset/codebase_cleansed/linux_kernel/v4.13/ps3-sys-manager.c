static void __maybe_unused _dump_sm_header(
const struct ps3_sys_manager_header *h, const char *func, int line)
{
pr_debug("%s:%d: version: %xh\n", func, line, h->version);
pr_debug("%s:%d: size: %xh\n", func, line, h->size);
pr_debug("%s:%d: payload_size: %xh\n", func, line, h->payload_size);
pr_debug("%s:%d: service_id: %xh\n", func, line, h->service_id);
pr_debug("%s:%d: request_tag: %xh\n", func, line, h->request_tag);
}
static int ps3_sys_manager_write(struct ps3_system_bus_device *dev,
const struct ps3_sys_manager_header *header, const void *payload)
{
int result;
BUG_ON(header->version != 1);
BUG_ON(header->size != 16);
BUG_ON(header->payload_size != 8 && header->payload_size != 16);
BUG_ON(header->service_id > 8);
result = ps3_vuart_write(dev, header,
sizeof(struct ps3_sys_manager_header));
if (!result)
result = ps3_vuart_write(dev, payload, header->payload_size);
return result;
}
static int ps3_sys_manager_send_attr(struct ps3_system_bus_device *dev,
enum ps3_sys_manager_attr attr)
{
struct ps3_sys_manager_header header;
struct {
u8 version;
u8 reserved_1[3];
u32 attribute;
} payload;
BUILD_BUG_ON(sizeof(payload) != 8);
dev_dbg(&dev->core, "%s:%d: %xh\n", __func__, __LINE__, attr);
memset(&header, 0, sizeof(header));
header.version = 1;
header.size = 16;
header.payload_size = 16;
header.service_id = PS3_SM_SERVICE_ID_SET_ATTR;
memset(&payload, 0, sizeof(payload));
payload.version = 1;
payload.attribute = attr;
return ps3_sys_manager_write(dev, &header, &payload);
}
static int ps3_sys_manager_send_next_op(struct ps3_system_bus_device *dev,
enum ps3_sys_manager_next_op op,
enum ps3_sys_manager_wake_source wake_source)
{
struct ps3_sys_manager_header header;
struct {
u8 version;
u8 type;
u8 gos_id;
u8 reserved_1;
u32 wake_source;
u8 reserved_2[8];
} payload;
BUILD_BUG_ON(sizeof(payload) != 16);
dev_dbg(&dev->core, "%s:%d: (%xh)\n", __func__, __LINE__, op);
memset(&header, 0, sizeof(header));
header.version = 1;
header.size = 16;
header.payload_size = 16;
header.service_id = PS3_SM_SERVICE_ID_SET_NEXT_OP;
memset(&payload, 0, sizeof(payload));
payload.version = 3;
payload.type = op;
payload.gos_id = 3;
payload.wake_source = wake_source;
return ps3_sys_manager_write(dev, &header, &payload);
}
static int ps3_sys_manager_send_request_shutdown(
struct ps3_system_bus_device *dev)
{
struct ps3_sys_manager_header header;
struct {
u8 version;
u8 type;
u8 gos_id;
u8 reserved_1[13];
} payload;
BUILD_BUG_ON(sizeof(payload) != 16);
dev_dbg(&dev->core, "%s:%d\n", __func__, __LINE__);
memset(&header, 0, sizeof(header));
header.version = 1;
header.size = 16;
header.payload_size = 16;
header.service_id = PS3_SM_SERVICE_ID_REQUEST;
memset(&payload, 0, sizeof(payload));
payload.version = 1;
payload.type = 1;
payload.gos_id = 0;
return ps3_sys_manager_write(dev, &header, &payload);
}
static int ps3_sys_manager_send_response(struct ps3_system_bus_device *dev,
u64 status)
{
struct ps3_sys_manager_header header;
struct {
u8 version;
u8 reserved_1[3];
u8 status;
u8 reserved_2[11];
} payload;
BUILD_BUG_ON(sizeof(payload) != 16);
dev_dbg(&dev->core, "%s:%d: (%s)\n", __func__, __LINE__,
(status ? "nak" : "ack"));
memset(&header, 0, sizeof(header));
header.version = 1;
header.size = 16;
header.payload_size = 16;
header.service_id = PS3_SM_SERVICE_ID_RESPONSE;
memset(&payload, 0, sizeof(payload));
payload.version = 1;
payload.status = status;
return ps3_sys_manager_write(dev, &header, &payload);
}
static int ps3_sys_manager_handle_event(struct ps3_system_bus_device *dev)
{
int result;
struct {
u8 version;
u8 type;
u8 reserved_1[2];
u32 value;
u8 reserved_2[8];
} event;
BUILD_BUG_ON(sizeof(event) != 16);
result = ps3_vuart_read(dev, &event, sizeof(event));
BUG_ON(result && "need to retry here");
if (event.version != 1) {
dev_dbg(&dev->core, "%s:%d: unsupported event version (%u)\n",
__func__, __LINE__, event.version);
return -EIO;
}
switch (event.type) {
case PS3_SM_EVENT_POWER_PRESSED:
dev_dbg(&dev->core, "%s:%d: POWER_PRESSED (%s)\n",
__func__, __LINE__,
(event.value == PS3_SM_BUTTON_EVENT_SOFT ? "soft"
: "hard"));
ps3_sm_force_power_off = 1;
wmb();
kill_cad_pid(SIGINT, 1);
break;
case PS3_SM_EVENT_POWER_RELEASED:
dev_dbg(&dev->core, "%s:%d: POWER_RELEASED (%u ms)\n",
__func__, __LINE__, event.value);
break;
case PS3_SM_EVENT_RESET_PRESSED:
dev_dbg(&dev->core, "%s:%d: RESET_PRESSED (%s)\n",
__func__, __LINE__,
(event.value == PS3_SM_BUTTON_EVENT_SOFT ? "soft"
: "hard"));
ps3_sm_force_power_off = 0;
wmb();
kill_cad_pid(SIGINT, 1);
break;
case PS3_SM_EVENT_RESET_RELEASED:
dev_dbg(&dev->core, "%s:%d: RESET_RELEASED (%u ms)\n",
__func__, __LINE__, event.value);
break;
case PS3_SM_EVENT_THERMAL_ALERT:
dev_dbg(&dev->core, "%s:%d: THERMAL_ALERT (zone %u)\n",
__func__, __LINE__, event.value);
pr_info("PS3 Thermal Alert Zone %u\n", event.value);
break;
case PS3_SM_EVENT_THERMAL_CLEARED:
dev_dbg(&dev->core, "%s:%d: THERMAL_CLEARED (zone %u)\n",
__func__, __LINE__, event.value);
break;
default:
dev_dbg(&dev->core, "%s:%d: unknown event (%u)\n",
__func__, __LINE__, event.type);
return -EIO;
}
return 0;
}
static int ps3_sys_manager_handle_cmd(struct ps3_system_bus_device *dev)
{
int result;
struct {
u8 version;
u8 type;
u8 reserved_1[14];
} cmd;
BUILD_BUG_ON(sizeof(cmd) != 16);
dev_dbg(&dev->core, "%s:%d\n", __func__, __LINE__);
result = ps3_vuart_read(dev, &cmd, sizeof(cmd));
BUG_ON(result && "need to retry here");
if (result)
return result;
if (cmd.version != 1) {
dev_dbg(&dev->core, "%s:%d: unsupported cmd version (%u)\n",
__func__, __LINE__, cmd.version);
return -EIO;
}
if (cmd.type != PS3_SM_CMD_SHUTDOWN) {
dev_dbg(&dev->core, "%s:%d: unknown cmd (%u)\n",
__func__, __LINE__, cmd.type);
return -EIO;
}
ps3_sys_manager_send_response(dev, 0);
return 0;
}
static int ps3_sys_manager_handle_msg(struct ps3_system_bus_device *dev)
{
int result;
struct ps3_sys_manager_header header;
result = ps3_vuart_read(dev, &header,
sizeof(struct ps3_sys_manager_header));
if (result)
return result;
if (header.version != 1) {
dev_dbg(&dev->core, "%s:%d: unsupported header version (%u)\n",
__func__, __LINE__, header.version);
dump_sm_header(&header);
goto fail_header;
}
BUILD_BUG_ON(sizeof(header) != 16);
if (header.size != 16 || (header.payload_size != 8
&& header.payload_size != 16)) {
dump_sm_header(&header);
BUG();
}
switch (header.service_id) {
case PS3_SM_SERVICE_ID_EXTERN_EVENT:
dev_dbg(&dev->core, "%s:%d: EVENT\n", __func__, __LINE__);
return ps3_sys_manager_handle_event(dev);
case PS3_SM_SERVICE_ID_COMMAND:
dev_dbg(&dev->core, "%s:%d: COMMAND\n", __func__, __LINE__);
return ps3_sys_manager_handle_cmd(dev);
case PS3_SM_SERVICE_ID_REQUEST_ERROR:
dev_dbg(&dev->core, "%s:%d: REQUEST_ERROR\n", __func__,
__LINE__);
dump_sm_header(&header);
break;
default:
dev_dbg(&dev->core, "%s:%d: unknown service_id (%u)\n",
__func__, __LINE__, header.service_id);
break;
}
goto fail_id;
fail_header:
ps3_vuart_clear_rx_bytes(dev, 0);
return -EIO;
fail_id:
ps3_vuart_clear_rx_bytes(dev, header.payload_size);
return -EIO;
}
static void ps3_sys_manager_fin(struct ps3_system_bus_device *dev)
{
ps3_sys_manager_send_request_shutdown(dev);
pr_emerg("System Halted, OK to turn off power\n");
while (ps3_sys_manager_handle_msg(dev)) {
lv1_pause(0);
}
while (1) {
lv1_pause(1);
}
}
static void ps3_sys_manager_final_power_off(struct ps3_system_bus_device *dev)
{
BUG_ON(!dev);
dev_dbg(&dev->core, "%s:%d\n", __func__, __LINE__);
ps3_vuart_cancel_async(dev);
ps3_sys_manager_send_next_op(dev, PS3_SM_NEXT_OP_SYS_SHUTDOWN,
user_wake_sources);
ps3_sys_manager_fin(dev);
}
static void ps3_sys_manager_final_restart(struct ps3_system_bus_device *dev)
{
BUG_ON(!dev);
dev_dbg(&dev->core, "%s:%d\n", __func__, __LINE__);
if (ps3_sm_force_power_off) {
dev_dbg(&dev->core, "%s:%d: forcing poweroff\n",
__func__, __LINE__);
ps3_sys_manager_final_power_off(dev);
}
ps3_vuart_cancel_async(dev);
ps3_sys_manager_send_attr(dev, 0);
ps3_sys_manager_send_next_op(dev, PS3_SM_NEXT_OP_SYS_REBOOT,
user_wake_sources);
ps3_sys_manager_fin(dev);
}
int ps3_sys_manager_get_wol(void)
{
pr_debug("%s:%d\n", __func__, __LINE__);
return (user_wake_sources & PS3_SM_WAKE_W_O_L) != 0;
}
void ps3_sys_manager_set_wol(int state)
{
static DEFINE_MUTEX(mutex);
mutex_lock(&mutex);
pr_debug("%s:%d: %d\n", __func__, __LINE__, state);
if (state)
user_wake_sources |= PS3_SM_WAKE_W_O_L;
else
user_wake_sources &= ~PS3_SM_WAKE_W_O_L;
mutex_unlock(&mutex);
}
static void ps3_sys_manager_work(struct ps3_system_bus_device *dev)
{
ps3_sys_manager_handle_msg(dev);
ps3_vuart_read_async(dev, PS3_SM_RX_MSG_LEN_MIN);
}
static int ps3_sys_manager_probe(struct ps3_system_bus_device *dev)
{
int result;
struct ps3_sys_manager_ops ops;
dev_dbg(&dev->core, "%s:%d\n", __func__, __LINE__);
ops.power_off = ps3_sys_manager_final_power_off;
ops.restart = ps3_sys_manager_final_restart;
ops.dev = dev;
ps3_sys_manager_register_ops(&ops);
result = ps3_sys_manager_send_attr(dev, PS3_SM_ATTR_ALL);
BUG_ON(result);
result = ps3_vuart_read_async(dev, PS3_SM_RX_MSG_LEN_MIN);
BUG_ON(result);
return result;
}
static int ps3_sys_manager_remove(struct ps3_system_bus_device *dev)
{
dev_dbg(&dev->core, "%s:%d\n", __func__, __LINE__);
return 0;
}
static void ps3_sys_manager_shutdown(struct ps3_system_bus_device *dev)
{
dev_dbg(&dev->core, "%s:%d\n", __func__, __LINE__);
}
static int __init ps3_sys_manager_init(void)
{
if (!firmware_has_feature(FW_FEATURE_PS3_LV1))
return -ENODEV;
return ps3_vuart_port_driver_register(&ps3_sys_manager);
}
