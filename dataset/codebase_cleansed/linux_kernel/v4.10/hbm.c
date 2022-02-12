static const char *mei_hbm_status_str(enum mei_hbm_status status)
{
#define MEI_HBM_STATUS(status) case MEI_HBMS_##status: return #status
switch (status) {
MEI_HBM_STATUS(SUCCESS);
MEI_HBM_STATUS(CLIENT_NOT_FOUND);
MEI_HBM_STATUS(ALREADY_EXISTS);
MEI_HBM_STATUS(REJECTED);
MEI_HBM_STATUS(INVALID_PARAMETER);
MEI_HBM_STATUS(NOT_ALLOWED);
MEI_HBM_STATUS(ALREADY_STARTED);
MEI_HBM_STATUS(NOT_STARTED);
default: return "unknown";
}
#undef MEI_HBM_STATUS
}
static const char *mei_cl_conn_status_str(enum mei_cl_connect_status status)
{
#define MEI_CL_CS(status) case MEI_CL_CONN_##status: return #status
switch (status) {
MEI_CL_CS(SUCCESS);
MEI_CL_CS(NOT_FOUND);
MEI_CL_CS(ALREADY_STARTED);
MEI_CL_CS(OUT_OF_RESOURCES);
MEI_CL_CS(MESSAGE_SMALL);
MEI_CL_CS(NOT_ALLOWED);
default: return "unknown";
}
#undef MEI_CL_CCS
}
const char *mei_hbm_state_str(enum mei_hbm_state state)
{
#define MEI_HBM_STATE(state) case MEI_HBM_##state: return #state
switch (state) {
MEI_HBM_STATE(IDLE);
MEI_HBM_STATE(STARTING);
MEI_HBM_STATE(STARTED);
MEI_HBM_STATE(ENUM_CLIENTS);
MEI_HBM_STATE(CLIENT_PROPERTIES);
MEI_HBM_STATE(STOPPED);
default:
return "unknown";
}
#undef MEI_HBM_STATE
}
static int mei_cl_conn_status_to_errno(enum mei_cl_connect_status status)
{
switch (status) {
case MEI_CL_CONN_SUCCESS: return 0;
case MEI_CL_CONN_NOT_FOUND: return -ENOTTY;
case MEI_CL_CONN_ALREADY_STARTED: return -EBUSY;
case MEI_CL_CONN_OUT_OF_RESOURCES: return -EBUSY;
case MEI_CL_CONN_MESSAGE_SMALL: return -EINVAL;
case MEI_CL_CONN_NOT_ALLOWED: return -EBUSY;
default: return -EINVAL;
}
}
void mei_hbm_idle(struct mei_device *dev)
{
dev->init_clients_timer = 0;
dev->hbm_state = MEI_HBM_IDLE;
}
void mei_hbm_reset(struct mei_device *dev)
{
mei_me_cl_rm_all(dev);
mei_hbm_idle(dev);
}
static inline void mei_hbm_hdr(struct mei_msg_hdr *hdr, size_t length)
{
hdr->host_addr = 0;
hdr->me_addr = 0;
hdr->length = length;
hdr->msg_complete = 1;
hdr->reserved = 0;
hdr->internal = 0;
}
static inline
void mei_hbm_cl_hdr(struct mei_cl *cl, u8 hbm_cmd, void *buf, size_t len)
{
struct mei_hbm_cl_cmd *cmd = buf;
memset(cmd, 0, len);
cmd->hbm_cmd = hbm_cmd;
cmd->host_addr = mei_cl_host_addr(cl);
cmd->me_addr = mei_cl_me_id(cl);
}
static inline
int mei_hbm_cl_write(struct mei_device *dev, struct mei_cl *cl,
u8 hbm_cmd, u8 *buf, size_t len)
{
struct mei_msg_hdr mei_hdr;
mei_hbm_hdr(&mei_hdr, len);
mei_hbm_cl_hdr(cl, hbm_cmd, buf, len);
return mei_write_message(dev, &mei_hdr, buf);
}
static inline
bool mei_hbm_cl_addr_equal(struct mei_cl *cl, struct mei_hbm_cl_cmd *cmd)
{
return mei_cl_host_addr(cl) == cmd->host_addr &&
mei_cl_me_id(cl) == cmd->me_addr;
}
static inline
struct mei_cl *mei_hbm_cl_find_by_cmd(struct mei_device *dev, void *buf)
{
struct mei_hbm_cl_cmd *cmd = (struct mei_hbm_cl_cmd *)buf;
struct mei_cl *cl;
list_for_each_entry(cl, &dev->file_list, link)
if (mei_hbm_cl_addr_equal(cl, cmd))
return cl;
return NULL;
}
int mei_hbm_start_wait(struct mei_device *dev)
{
int ret;
if (dev->hbm_state > MEI_HBM_STARTING)
return 0;
mutex_unlock(&dev->device_lock);
ret = wait_event_timeout(dev->wait_hbm_start,
dev->hbm_state != MEI_HBM_STARTING,
mei_secs_to_jiffies(MEI_HBM_TIMEOUT));
mutex_lock(&dev->device_lock);
if (ret == 0 && (dev->hbm_state <= MEI_HBM_STARTING)) {
dev->hbm_state = MEI_HBM_IDLE;
dev_err(dev->dev, "waiting for mei start failed\n");
return -ETIME;
}
return 0;
}
int mei_hbm_start_req(struct mei_device *dev)
{
struct mei_msg_hdr mei_hdr;
struct hbm_host_version_request start_req;
const size_t len = sizeof(struct hbm_host_version_request);
int ret;
mei_hbm_reset(dev);
mei_hbm_hdr(&mei_hdr, len);
memset(&start_req, 0, len);
start_req.hbm_cmd = HOST_START_REQ_CMD;
start_req.host_version.major_version = HBM_MAJOR_VERSION;
start_req.host_version.minor_version = HBM_MINOR_VERSION;
dev->hbm_state = MEI_HBM_IDLE;
ret = mei_write_message(dev, &mei_hdr, &start_req);
if (ret) {
dev_err(dev->dev, "version message write failed: ret = %d\n",
ret);
return ret;
}
dev->hbm_state = MEI_HBM_STARTING;
dev->init_clients_timer = MEI_CLIENTS_INIT_TIMEOUT;
mei_schedule_stall_timer(dev);
return 0;
}
static int mei_hbm_enum_clients_req(struct mei_device *dev)
{
struct mei_msg_hdr mei_hdr;
struct hbm_host_enum_request enum_req;
const size_t len = sizeof(struct hbm_host_enum_request);
int ret;
mei_hbm_hdr(&mei_hdr, len);
memset(&enum_req, 0, len);
enum_req.hbm_cmd = HOST_ENUM_REQ_CMD;
enum_req.flags |= dev->hbm_f_dc_supported ?
MEI_HBM_ENUM_F_ALLOW_ADD : 0;
enum_req.flags |= dev->hbm_f_ie_supported ?
MEI_HBM_ENUM_F_IMMEDIATE_ENUM : 0;
ret = mei_write_message(dev, &mei_hdr, &enum_req);
if (ret) {
dev_err(dev->dev, "enumeration request write failed: ret = %d.\n",
ret);
return ret;
}
dev->hbm_state = MEI_HBM_ENUM_CLIENTS;
dev->init_clients_timer = MEI_CLIENTS_INIT_TIMEOUT;
mei_schedule_stall_timer(dev);
return 0;
}
static int mei_hbm_me_cl_add(struct mei_device *dev,
struct hbm_props_response *res)
{
struct mei_me_client *me_cl;
const uuid_le *uuid = &res->client_properties.protocol_name;
mei_me_cl_rm_by_uuid(dev, uuid);
me_cl = kzalloc(sizeof(struct mei_me_client), GFP_KERNEL);
if (!me_cl)
return -ENOMEM;
mei_me_cl_init(me_cl);
me_cl->props = res->client_properties;
me_cl->client_id = res->me_addr;
me_cl->tx_flow_ctrl_creds = 0;
mei_me_cl_add(dev, me_cl);
return 0;
}
static int mei_hbm_add_cl_resp(struct mei_device *dev, u8 addr, u8 status)
{
struct mei_msg_hdr mei_hdr;
struct hbm_add_client_response resp;
const size_t len = sizeof(struct hbm_add_client_response);
int ret;
dev_dbg(dev->dev, "adding client response\n");
mei_hbm_hdr(&mei_hdr, len);
memset(&resp, 0, sizeof(struct hbm_add_client_response));
resp.hbm_cmd = MEI_HBM_ADD_CLIENT_RES_CMD;
resp.me_addr = addr;
resp.status = status;
ret = mei_write_message(dev, &mei_hdr, &resp);
if (ret)
dev_err(dev->dev, "add client response write failed: ret = %d\n",
ret);
return ret;
}
static int mei_hbm_fw_add_cl_req(struct mei_device *dev,
struct hbm_add_client_request *req)
{
int ret;
u8 status = MEI_HBMS_SUCCESS;
BUILD_BUG_ON(sizeof(struct hbm_add_client_request) !=
sizeof(struct hbm_props_response));
ret = mei_hbm_me_cl_add(dev, (struct hbm_props_response *)req);
if (ret)
status = !MEI_HBMS_SUCCESS;
if (dev->dev_state == MEI_DEV_ENABLED)
schedule_work(&dev->bus_rescan_work);
return mei_hbm_add_cl_resp(dev, req->me_addr, status);
}
int mei_hbm_cl_notify_req(struct mei_device *dev,
struct mei_cl *cl, u8 start)
{
struct mei_msg_hdr mei_hdr;
struct hbm_notification_request req;
const size_t len = sizeof(struct hbm_notification_request);
int ret;
mei_hbm_hdr(&mei_hdr, len);
mei_hbm_cl_hdr(cl, MEI_HBM_NOTIFY_REQ_CMD, &req, len);
req.start = start;
ret = mei_write_message(dev, &mei_hdr, &req);
if (ret)
dev_err(dev->dev, "notify request failed: ret = %d\n", ret);
return ret;
}
static inline enum mei_cb_file_ops notify_res_to_fop(struct mei_hbm_cl_cmd *cmd)
{
struct hbm_notification_response *rs =
(struct hbm_notification_response *)cmd;
return mei_cl_notify_req2fop(rs->start);
}
static void mei_hbm_cl_notify_start_res(struct mei_device *dev,
struct mei_cl *cl,
struct mei_hbm_cl_cmd *cmd)
{
struct hbm_notification_response *rs =
(struct hbm_notification_response *)cmd;
cl_dbg(dev, cl, "hbm: notify start response status=%d\n", rs->status);
if (rs->status == MEI_HBMS_SUCCESS ||
rs->status == MEI_HBMS_ALREADY_STARTED) {
cl->notify_en = true;
cl->status = 0;
} else {
cl->status = -EINVAL;
}
}
static void mei_hbm_cl_notify_stop_res(struct mei_device *dev,
struct mei_cl *cl,
struct mei_hbm_cl_cmd *cmd)
{
struct hbm_notification_response *rs =
(struct hbm_notification_response *)cmd;
cl_dbg(dev, cl, "hbm: notify stop response status=%d\n", rs->status);
if (rs->status == MEI_HBMS_SUCCESS ||
rs->status == MEI_HBMS_NOT_STARTED) {
cl->notify_en = false;
cl->status = 0;
} else {
cl->status = -EINVAL;
}
}
static void mei_hbm_cl_notify(struct mei_device *dev,
struct mei_hbm_cl_cmd *cmd)
{
struct mei_cl *cl;
cl = mei_hbm_cl_find_by_cmd(dev, cmd);
if (cl)
mei_cl_notify(cl);
}
static int mei_hbm_prop_req(struct mei_device *dev, unsigned long start_idx)
{
struct mei_msg_hdr mei_hdr;
struct hbm_props_request prop_req;
const size_t len = sizeof(struct hbm_props_request);
unsigned long addr;
int ret;
addr = find_next_bit(dev->me_clients_map, MEI_CLIENTS_MAX, start_idx);
if (addr == MEI_CLIENTS_MAX) {
dev->hbm_state = MEI_HBM_STARTED;
mei_host_client_init(dev);
return 0;
}
mei_hbm_hdr(&mei_hdr, len);
memset(&prop_req, 0, sizeof(struct hbm_props_request));
prop_req.hbm_cmd = HOST_CLIENT_PROPERTIES_REQ_CMD;
prop_req.me_addr = addr;
ret = mei_write_message(dev, &mei_hdr, &prop_req);
if (ret) {
dev_err(dev->dev, "properties request write failed: ret = %d\n",
ret);
return ret;
}
dev->init_clients_timer = MEI_CLIENTS_INIT_TIMEOUT;
mei_schedule_stall_timer(dev);
return 0;
}
int mei_hbm_pg(struct mei_device *dev, u8 pg_cmd)
{
struct mei_msg_hdr mei_hdr;
struct hbm_power_gate req;
const size_t len = sizeof(struct hbm_power_gate);
int ret;
if (!dev->hbm_f_pg_supported)
return -EOPNOTSUPP;
mei_hbm_hdr(&mei_hdr, len);
memset(&req, 0, len);
req.hbm_cmd = pg_cmd;
ret = mei_write_message(dev, &mei_hdr, &req);
if (ret)
dev_err(dev->dev, "power gate command write failed.\n");
return ret;
}
static int mei_hbm_stop_req(struct mei_device *dev)
{
struct mei_msg_hdr mei_hdr;
struct hbm_host_stop_request req;
const size_t len = sizeof(struct hbm_host_stop_request);
mei_hbm_hdr(&mei_hdr, len);
memset(&req, 0, len);
req.hbm_cmd = HOST_STOP_REQ_CMD;
req.reason = DRIVER_STOP_REQUEST;
return mei_write_message(dev, &mei_hdr, &req);
}
int mei_hbm_cl_flow_control_req(struct mei_device *dev, struct mei_cl *cl)
{
const size_t len = sizeof(struct hbm_flow_control);
u8 buf[len];
cl_dbg(dev, cl, "sending flow control\n");
return mei_hbm_cl_write(dev, cl, MEI_FLOW_CONTROL_CMD, buf, len);
}
static int mei_hbm_add_single_tx_flow_ctrl_creds(struct mei_device *dev,
struct hbm_flow_control *fctrl)
{
struct mei_me_client *me_cl;
int rets;
me_cl = mei_me_cl_by_id(dev, fctrl->me_addr);
if (!me_cl) {
dev_err(dev->dev, "no such me client %d\n", fctrl->me_addr);
return -ENOENT;
}
if (WARN_ON(me_cl->props.single_recv_buf == 0)) {
rets = -EINVAL;
goto out;
}
me_cl->tx_flow_ctrl_creds++;
dev_dbg(dev->dev, "recv flow ctrl msg ME %d (single) creds = %d.\n",
fctrl->me_addr, me_cl->tx_flow_ctrl_creds);
rets = 0;
out:
mei_me_cl_put(me_cl);
return rets;
}
static void mei_hbm_cl_tx_flow_ctrl_creds_res(struct mei_device *dev,
struct hbm_flow_control *fctrl)
{
struct mei_cl *cl;
if (!fctrl->host_addr) {
mei_hbm_add_single_tx_flow_ctrl_creds(dev, fctrl);
return;
}
cl = mei_hbm_cl_find_by_cmd(dev, fctrl);
if (cl) {
cl->tx_flow_ctrl_creds++;
cl_dbg(dev, cl, "flow control creds = %d.\n",
cl->tx_flow_ctrl_creds);
}
}
int mei_hbm_cl_disconnect_req(struct mei_device *dev, struct mei_cl *cl)
{
const size_t len = sizeof(struct hbm_client_connect_request);
u8 buf[len];
return mei_hbm_cl_write(dev, cl, CLIENT_DISCONNECT_REQ_CMD, buf, len);
}
int mei_hbm_cl_disconnect_rsp(struct mei_device *dev, struct mei_cl *cl)
{
const size_t len = sizeof(struct hbm_client_connect_response);
u8 buf[len];
return mei_hbm_cl_write(dev, cl, CLIENT_DISCONNECT_RES_CMD, buf, len);
}
static void mei_hbm_cl_disconnect_res(struct mei_device *dev, struct mei_cl *cl,
struct mei_hbm_cl_cmd *cmd)
{
struct hbm_client_connect_response *rs =
(struct hbm_client_connect_response *)cmd;
cl_dbg(dev, cl, "hbm: disconnect response status=%d\n", rs->status);
if (rs->status == MEI_CL_DISCONN_SUCCESS)
cl->state = MEI_FILE_DISCONNECT_REPLY;
cl->status = 0;
}
int mei_hbm_cl_connect_req(struct mei_device *dev, struct mei_cl *cl)
{
const size_t len = sizeof(struct hbm_client_connect_request);
u8 buf[len];
return mei_hbm_cl_write(dev, cl, CLIENT_CONNECT_REQ_CMD, buf, len);
}
static void mei_hbm_cl_connect_res(struct mei_device *dev, struct mei_cl *cl,
struct mei_hbm_cl_cmd *cmd)
{
struct hbm_client_connect_response *rs =
(struct hbm_client_connect_response *)cmd;
cl_dbg(dev, cl, "hbm: connect response status=%s\n",
mei_cl_conn_status_str(rs->status));
if (rs->status == MEI_CL_CONN_SUCCESS)
cl->state = MEI_FILE_CONNECTED;
else {
cl->state = MEI_FILE_DISCONNECT_REPLY;
if (rs->status == MEI_CL_CONN_NOT_FOUND) {
mei_me_cl_del(dev, cl->me_cl);
if (dev->dev_state == MEI_DEV_ENABLED)
schedule_work(&dev->bus_rescan_work);
}
}
cl->status = mei_cl_conn_status_to_errno(rs->status);
}
static void mei_hbm_cl_res(struct mei_device *dev,
struct mei_hbm_cl_cmd *rs,
enum mei_cb_file_ops fop_type)
{
struct mei_cl *cl;
struct mei_cl_cb *cb, *next;
cl = NULL;
list_for_each_entry_safe(cb, next, &dev->ctrl_rd_list.list, list) {
cl = cb->cl;
if (cb->fop_type != fop_type)
continue;
if (mei_hbm_cl_addr_equal(cl, rs)) {
list_del_init(&cb->list);
break;
}
}
if (!cl)
return;
switch (fop_type) {
case MEI_FOP_CONNECT:
mei_hbm_cl_connect_res(dev, cl, rs);
break;
case MEI_FOP_DISCONNECT:
mei_hbm_cl_disconnect_res(dev, cl, rs);
break;
case MEI_FOP_NOTIFY_START:
mei_hbm_cl_notify_start_res(dev, cl, rs);
break;
case MEI_FOP_NOTIFY_STOP:
mei_hbm_cl_notify_stop_res(dev, cl, rs);
break;
default:
return;
}
cl->timer_count = 0;
wake_up(&cl->wait);
}
static int mei_hbm_fw_disconnect_req(struct mei_device *dev,
struct hbm_client_connect_request *disconnect_req)
{
struct mei_cl *cl;
struct mei_cl_cb *cb;
cl = mei_hbm_cl_find_by_cmd(dev, disconnect_req);
if (cl) {
cl_warn(dev, cl, "fw disconnect request received\n");
cl->state = MEI_FILE_DISCONNECTING;
cl->timer_count = 0;
cb = mei_cl_enqueue_ctrl_wr_cb(cl, 0, MEI_FOP_DISCONNECT_RSP,
NULL);
if (!cb)
return -ENOMEM;
}
return 0;
}
static int mei_hbm_pg_enter_res(struct mei_device *dev)
{
if (mei_pg_state(dev) != MEI_PG_OFF ||
dev->pg_event != MEI_PG_EVENT_WAIT) {
dev_err(dev->dev, "hbm: pg entry response: state mismatch [%s, %d]\n",
mei_pg_state_str(mei_pg_state(dev)), dev->pg_event);
return -EPROTO;
}
dev->pg_event = MEI_PG_EVENT_RECEIVED;
wake_up(&dev->wait_pg);
return 0;
}
void mei_hbm_pg_resume(struct mei_device *dev)
{
pm_request_resume(dev->dev);
}
static int mei_hbm_pg_exit_res(struct mei_device *dev)
{
if (mei_pg_state(dev) != MEI_PG_ON ||
(dev->pg_event != MEI_PG_EVENT_WAIT &&
dev->pg_event != MEI_PG_EVENT_IDLE)) {
dev_err(dev->dev, "hbm: pg exit response: state mismatch [%s, %d]\n",
mei_pg_state_str(mei_pg_state(dev)), dev->pg_event);
return -EPROTO;
}
switch (dev->pg_event) {
case MEI_PG_EVENT_WAIT:
dev->pg_event = MEI_PG_EVENT_RECEIVED;
wake_up(&dev->wait_pg);
break;
case MEI_PG_EVENT_IDLE:
dev->pg_event = MEI_PG_EVENT_RECEIVED;
mei_hbm_pg_resume(dev);
break;
default:
WARN(1, "hbm: pg exit response: unexpected pg event = %d\n",
dev->pg_event);
return -EPROTO;
}
return 0;
}
static void mei_hbm_config_features(struct mei_device *dev)
{
dev->hbm_f_pg_supported = 0;
if (dev->version.major_version > HBM_MAJOR_VERSION_PGI)
dev->hbm_f_pg_supported = 1;
if (dev->version.major_version == HBM_MAJOR_VERSION_PGI &&
dev->version.minor_version >= HBM_MINOR_VERSION_PGI)
dev->hbm_f_pg_supported = 1;
if (dev->version.major_version >= HBM_MAJOR_VERSION_DC)
dev->hbm_f_dc_supported = 1;
if (dev->version.major_version >= HBM_MAJOR_VERSION_IE)
dev->hbm_f_ie_supported = 1;
if (dev->version.major_version >= HBM_MAJOR_VERSION_DOT)
dev->hbm_f_dot_supported = 1;
if (dev->version.major_version >= HBM_MAJOR_VERSION_EV)
dev->hbm_f_ev_supported = 1;
if (dev->version.major_version >= HBM_MAJOR_VERSION_FA)
dev->hbm_f_fa_supported = 1;
if (dev->version.major_version >= HBM_MAJOR_VERSION_OS)
dev->hbm_f_os_supported = 1;
}
bool mei_hbm_version_is_supported(struct mei_device *dev)
{
return (dev->version.major_version < HBM_MAJOR_VERSION) ||
(dev->version.major_version == HBM_MAJOR_VERSION &&
dev->version.minor_version <= HBM_MINOR_VERSION);
}
int mei_hbm_dispatch(struct mei_device *dev, struct mei_msg_hdr *hdr)
{
struct mei_bus_message *mei_msg;
struct hbm_host_version_response *version_res;
struct hbm_props_response *props_res;
struct hbm_host_enum_response *enum_res;
struct hbm_add_client_request *add_cl_req;
int ret;
struct mei_hbm_cl_cmd *cl_cmd;
struct hbm_client_connect_request *disconnect_req;
struct hbm_flow_control *fctrl;
BUG_ON(hdr->length >= sizeof(dev->rd_msg_buf));
mei_read_slots(dev, dev->rd_msg_buf, hdr->length);
mei_msg = (struct mei_bus_message *)dev->rd_msg_buf;
cl_cmd = (struct mei_hbm_cl_cmd *)mei_msg;
if (dev->hbm_state == MEI_HBM_IDLE) {
dev_dbg(dev->dev, "hbm: state is idle ignore spurious messages\n");
return 0;
}
switch (mei_msg->hbm_cmd) {
case HOST_START_RES_CMD:
dev_dbg(dev->dev, "hbm: start: response message received.\n");
dev->init_clients_timer = 0;
version_res = (struct hbm_host_version_response *)mei_msg;
dev_dbg(dev->dev, "HBM VERSION: DRIVER=%02d:%02d DEVICE=%02d:%02d\n",
HBM_MAJOR_VERSION, HBM_MINOR_VERSION,
version_res->me_max_version.major_version,
version_res->me_max_version.minor_version);
if (version_res->host_version_supported) {
dev->version.major_version = HBM_MAJOR_VERSION;
dev->version.minor_version = HBM_MINOR_VERSION;
} else {
dev->version.major_version =
version_res->me_max_version.major_version;
dev->version.minor_version =
version_res->me_max_version.minor_version;
}
if (!mei_hbm_version_is_supported(dev)) {
dev_warn(dev->dev, "hbm: start: version mismatch - stopping the driver.\n");
dev->hbm_state = MEI_HBM_STOPPED;
if (mei_hbm_stop_req(dev)) {
dev_err(dev->dev, "hbm: start: failed to send stop request\n");
return -EIO;
}
break;
}
mei_hbm_config_features(dev);
if (dev->dev_state != MEI_DEV_INIT_CLIENTS ||
dev->hbm_state != MEI_HBM_STARTING) {
dev_err(dev->dev, "hbm: start: state mismatch, [%d, %d]\n",
dev->dev_state, dev->hbm_state);
return -EPROTO;
}
if (mei_hbm_enum_clients_req(dev)) {
dev_err(dev->dev, "hbm: start: failed to send enumeration request\n");
return -EIO;
}
wake_up(&dev->wait_hbm_start);
break;
case CLIENT_CONNECT_RES_CMD:
dev_dbg(dev->dev, "hbm: client connect response: message received.\n");
mei_hbm_cl_res(dev, cl_cmd, MEI_FOP_CONNECT);
break;
case CLIENT_DISCONNECT_RES_CMD:
dev_dbg(dev->dev, "hbm: client disconnect response: message received.\n");
mei_hbm_cl_res(dev, cl_cmd, MEI_FOP_DISCONNECT);
break;
case MEI_FLOW_CONTROL_CMD:
dev_dbg(dev->dev, "hbm: client flow control response: message received.\n");
fctrl = (struct hbm_flow_control *)mei_msg;
mei_hbm_cl_tx_flow_ctrl_creds_res(dev, fctrl);
break;
case MEI_PG_ISOLATION_ENTRY_RES_CMD:
dev_dbg(dev->dev, "hbm: power gate isolation entry response received\n");
ret = mei_hbm_pg_enter_res(dev);
if (ret)
return ret;
break;
case MEI_PG_ISOLATION_EXIT_REQ_CMD:
dev_dbg(dev->dev, "hbm: power gate isolation exit request received\n");
ret = mei_hbm_pg_exit_res(dev);
if (ret)
return ret;
break;
case HOST_CLIENT_PROPERTIES_RES_CMD:
dev_dbg(dev->dev, "hbm: properties response: message received.\n");
dev->init_clients_timer = 0;
if (dev->dev_state != MEI_DEV_INIT_CLIENTS ||
dev->hbm_state != MEI_HBM_CLIENT_PROPERTIES) {
dev_err(dev->dev, "hbm: properties response: state mismatch, [%d, %d]\n",
dev->dev_state, dev->hbm_state);
return -EPROTO;
}
props_res = (struct hbm_props_response *)mei_msg;
if (props_res->status) {
dev_err(dev->dev, "hbm: properties response: wrong status = %d %s\n",
props_res->status,
mei_hbm_status_str(props_res->status));
return -EPROTO;
}
mei_hbm_me_cl_add(dev, props_res);
if (mei_hbm_prop_req(dev, props_res->me_addr + 1))
return -EIO;
break;
case HOST_ENUM_RES_CMD:
dev_dbg(dev->dev, "hbm: enumeration response: message received\n");
dev->init_clients_timer = 0;
enum_res = (struct hbm_host_enum_response *) mei_msg;
BUILD_BUG_ON(sizeof(dev->me_clients_map)
< sizeof(enum_res->valid_addresses));
memcpy(dev->me_clients_map, enum_res->valid_addresses,
sizeof(enum_res->valid_addresses));
if (dev->dev_state != MEI_DEV_INIT_CLIENTS ||
dev->hbm_state != MEI_HBM_ENUM_CLIENTS) {
dev_err(dev->dev, "hbm: enumeration response: state mismatch, [%d, %d]\n",
dev->dev_state, dev->hbm_state);
return -EPROTO;
}
dev->hbm_state = MEI_HBM_CLIENT_PROPERTIES;
if (mei_hbm_prop_req(dev, 0))
return -EIO;
break;
case HOST_STOP_RES_CMD:
dev_dbg(dev->dev, "hbm: stop response: message received\n");
dev->init_clients_timer = 0;
if (dev->hbm_state != MEI_HBM_STOPPED) {
dev_err(dev->dev, "hbm: stop response: state mismatch, [%d, %d]\n",
dev->dev_state, dev->hbm_state);
return -EPROTO;
}
dev->dev_state = MEI_DEV_POWER_DOWN;
dev_info(dev->dev, "hbm: stop response: resetting.\n");
return -EPROTO;
break;
case CLIENT_DISCONNECT_REQ_CMD:
dev_dbg(dev->dev, "hbm: disconnect request: message received\n");
disconnect_req = (struct hbm_client_connect_request *)mei_msg;
mei_hbm_fw_disconnect_req(dev, disconnect_req);
break;
case ME_STOP_REQ_CMD:
dev_dbg(dev->dev, "hbm: stop request: message received\n");
dev->hbm_state = MEI_HBM_STOPPED;
if (mei_hbm_stop_req(dev)) {
dev_err(dev->dev, "hbm: stop request: failed to send stop request\n");
return -EIO;
}
break;
case MEI_HBM_ADD_CLIENT_REQ_CMD:
dev_dbg(dev->dev, "hbm: add client request received\n");
if (dev->hbm_state <= MEI_HBM_ENUM_CLIENTS ||
dev->hbm_state >= MEI_HBM_STOPPED) {
dev_err(dev->dev, "hbm: add client: state mismatch, [%d, %d]\n",
dev->dev_state, dev->hbm_state);
return -EPROTO;
}
add_cl_req = (struct hbm_add_client_request *)mei_msg;
ret = mei_hbm_fw_add_cl_req(dev, add_cl_req);
if (ret) {
dev_err(dev->dev, "hbm: add client: failed to send response %d\n",
ret);
return -EIO;
}
dev_dbg(dev->dev, "hbm: add client request processed\n");
break;
case MEI_HBM_NOTIFY_RES_CMD:
dev_dbg(dev->dev, "hbm: notify response received\n");
mei_hbm_cl_res(dev, cl_cmd, notify_res_to_fop(cl_cmd));
break;
case MEI_HBM_NOTIFICATION_CMD:
dev_dbg(dev->dev, "hbm: notification\n");
mei_hbm_cl_notify(dev, cl_cmd);
break;
default:
BUG();
break;
}
return 0;
}
