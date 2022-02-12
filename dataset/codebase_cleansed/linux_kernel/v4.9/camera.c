static const struct gb_camera_fmt_info *gb_camera_get_format_info(u16 gb_fmt)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(gb_fmt_info); i++) {
if (gb_fmt_info[i].gb_format == gb_fmt)
return &gb_fmt_info[i];
}
return NULL;
}
static int gb_camera_operation_sync_flags(struct gb_connection *connection,
int type, unsigned int flags,
void *request, size_t request_size,
void *response, size_t *response_size)
{
struct gb_operation *operation;
int ret;
operation = gb_operation_create_flags(connection, type, request_size,
*response_size, flags,
GFP_KERNEL);
if (!operation)
return -ENOMEM;
if (request_size)
memcpy(operation->request->payload, request, request_size);
ret = gb_operation_request_send_sync(operation);
if (ret) {
dev_err(&connection->hd->dev,
"%s: synchronous operation of type 0x%02x failed: %d\n",
connection->name, type, ret);
} else {
*response_size = operation->response->payload_size;
if (operation->response->payload_size)
memcpy(response, operation->response->payload,
operation->response->payload_size);
}
gb_operation_put(operation);
return ret;
}
static int gb_camera_get_max_pkt_size(struct gb_camera *gcam,
struct gb_camera_configure_streams_response *resp)
{
unsigned int max_pkt_size = 0;
unsigned int i;
for (i = 0; i < resp->num_streams; i++) {
struct gb_camera_stream_config_response *cfg = &resp->config[i];
const struct gb_camera_fmt_info *fmt_info;
unsigned int pkt_size;
fmt_info = gb_camera_get_format_info(cfg->format);
if (!fmt_info) {
gcam_err(gcam, "unsupported greybus image format: %d\n",
cfg->format);
return -EIO;
}
if (fmt_info->bpp == 0) {
pkt_size = le32_to_cpu(cfg->max_pkt_size);
if (pkt_size == 0) {
gcam_err(gcam,
"Stream %u: invalid zero maximum packet size\n",
i);
return -EIO;
}
} else {
pkt_size = le16_to_cpu(cfg->width) * fmt_info->bpp / 8;
if (pkt_size != le32_to_cpu(cfg->max_pkt_size)) {
gcam_err(gcam,
"Stream %u: maximum packet size mismatch (%u/%u)\n",
i, pkt_size, cfg->max_pkt_size);
return -EIO;
}
}
max_pkt_size = max(pkt_size, max_pkt_size);
}
return max_pkt_size;
}
static const int gb_camera_configure_streams_validate_response(
struct gb_camera *gcam,
struct gb_camera_configure_streams_response *resp,
unsigned int nstreams)
{
unsigned int i;
if (resp->padding[0] || resp->padding[1]) {
gcam_err(gcam, "response padding != 0\n");
return -EIO;
}
if (resp->num_streams > nstreams) {
gcam_err(gcam, "got #streams %u > request %u\n",
resp->num_streams, nstreams);
return -EIO;
}
for (i = 0; i < resp->num_streams; i++) {
struct gb_camera_stream_config_response *cfg = &resp->config[i];
if (cfg->padding) {
gcam_err(gcam, "stream #%u padding != 0\n", i);
return -EIO;
}
}
return 0;
}
static int gb_camera_set_intf_power_mode(struct gb_camera *gcam, u8 intf_id,
bool hs)
{
struct gb_svc *svc = gcam->connection->hd->svc;
int ret;
if (hs)
ret = gb_svc_intf_set_power_mode(svc, intf_id,
GB_SVC_UNIPRO_HS_SERIES_A,
GB_SVC_UNIPRO_FAST_MODE, 2, 2,
GB_SVC_SMALL_AMPLITUDE,
GB_SVC_NO_DE_EMPHASIS,
GB_SVC_UNIPRO_FAST_MODE, 2, 2,
GB_SVC_PWRM_RXTERMINATION |
GB_SVC_PWRM_TXTERMINATION, 0,
NULL, NULL);
else
ret = gb_svc_intf_set_power_mode(svc, intf_id,
GB_SVC_UNIPRO_HS_SERIES_A,
GB_SVC_UNIPRO_SLOW_AUTO_MODE,
2, 1,
GB_SVC_SMALL_AMPLITUDE,
GB_SVC_NO_DE_EMPHASIS,
GB_SVC_UNIPRO_SLOW_AUTO_MODE,
2, 1,
0, 0,
NULL, NULL);
return ret;
}
static int gb_camera_set_power_mode(struct gb_camera *gcam, bool hs)
{
struct gb_interface *intf = gcam->connection->intf;
struct gb_svc *svc = gcam->connection->hd->svc;
int ret;
ret = gb_camera_set_intf_power_mode(gcam, intf->interface_id, hs);
if (ret < 0) {
gcam_err(gcam, "failed to set module interface to %s (%d)\n",
hs ? "HS" : "PWM", ret);
return ret;
}
ret = gb_camera_set_intf_power_mode(gcam, svc->ap_intf_id, hs);
if (ret < 0) {
gb_camera_set_intf_power_mode(gcam, intf->interface_id, !hs);
gcam_err(gcam, "failed to set AP interface to %s (%d)\n",
hs ? "HS" : "PWM", ret);
return ret;
}
return 0;
}
static int gb_camera_setup_data_connection(struct gb_camera *gcam,
struct gb_camera_configure_streams_response *resp,
struct gb_camera_csi_params *csi_params)
{
struct ap_csi_config_request csi_cfg;
struct gb_connection *conn;
unsigned int clk_freq;
int ret;
conn = gb_connection_create_offloaded(gcam->bundle, gcam->data_cport_id,
GB_CONNECTION_FLAG_NO_FLOWCTRL |
GB_CONNECTION_FLAG_CDSI1);
if (IS_ERR(conn))
return PTR_ERR(conn);
gcam->data_connection = conn;
gb_connection_set_data(conn, gcam);
ret = gb_connection_enable(conn);
if (ret)
goto error_conn_destroy;
ret = gb_camera_set_power_mode(gcam, true);
if (ret < 0)
goto error_conn_disable;
memset(&csi_cfg, 0, sizeof(csi_cfg));
csi_cfg.csi_id = 1;
csi_cfg.flags = 0;
csi_cfg.num_lanes = GB_CAMERA_CSI_NUM_DATA_LANES;
clk_freq = resp->data_rate / 2 / GB_CAMERA_CSI_NUM_DATA_LANES;
clk_freq = clamp(clk_freq + GB_CAMERA_CSI_CLK_FREQ_MARGIN,
GB_CAMERA_CSI_CLK_FREQ_MIN,
GB_CAMERA_CSI_CLK_FREQ_MAX);
csi_cfg.csi_clk_freq = clk_freq;
ret = gb_camera_get_max_pkt_size(gcam, resp);
if (ret < 0) {
ret = -EIO;
goto error_power;
}
csi_cfg.max_pkt_size = ret;
ret = gb_hd_output(gcam->connection->hd, &csi_cfg,
sizeof(csi_cfg),
GB_APB_REQUEST_CSI_TX_CONTROL, false);
if (ret < 0) {
gcam_err(gcam, "failed to start the CSI transmitter\n");
goto error_power;
}
if (csi_params) {
csi_params->clk_freq = csi_cfg.csi_clk_freq;
csi_params->num_lanes = csi_cfg.num_lanes;
}
return 0;
error_power:
gb_camera_set_power_mode(gcam, false);
error_conn_disable:
gb_connection_disable(gcam->data_connection);
error_conn_destroy:
gb_connection_destroy(gcam->data_connection);
gcam->data_connection = NULL;
return ret;
}
static void gb_camera_teardown_data_connection(struct gb_camera *gcam)
{
struct ap_csi_config_request csi_cfg;
int ret;
memset(&csi_cfg, 0, sizeof(csi_cfg));
csi_cfg.csi_id = 1;
ret = gb_hd_output(gcam->connection->hd, &csi_cfg,
sizeof(csi_cfg),
GB_APB_REQUEST_CSI_TX_CONTROL, false);
if (ret < 0)
gcam_err(gcam, "failed to stop the CSI transmitter\n");
gb_camera_set_power_mode(gcam, false);
gb_connection_disable(gcam->data_connection);
gb_connection_destroy(gcam->data_connection);
gcam->data_connection = NULL;
}
static int gb_camera_capabilities(struct gb_camera *gcam,
u8 *capabilities, size_t *size)
{
int ret;
ret = gb_pm_runtime_get_sync(gcam->bundle);
if (ret)
return ret;
mutex_lock(&gcam->mutex);
if (!gcam->connection) {
ret = -EINVAL;
goto done;
}
ret = gb_camera_operation_sync_flags(gcam->connection,
GB_CAMERA_TYPE_CAPABILITIES,
GB_OPERATION_FLAG_SHORT_RESPONSE,
NULL, 0,
(void *)capabilities, size);
if (ret)
gcam_err(gcam, "failed to retrieve capabilities: %d\n", ret);
done:
mutex_unlock(&gcam->mutex);
gb_pm_runtime_put_autosuspend(gcam->bundle);
return ret;
}
static int gb_camera_configure_streams(struct gb_camera *gcam,
unsigned int *num_streams,
unsigned int *flags,
struct gb_camera_stream_config *streams,
struct gb_camera_csi_params *csi_params)
{
struct gb_camera_configure_streams_request *req;
struct gb_camera_configure_streams_response *resp;
unsigned int nstreams = *num_streams;
unsigned int i;
size_t req_size;
size_t resp_size;
int ret;
if (nstreams > GB_CAMERA_MAX_STREAMS)
return -EINVAL;
req_size = sizeof(*req) + nstreams * sizeof(req->config[0]);
resp_size = sizeof(*resp) + nstreams * sizeof(resp->config[0]);
req = kmalloc(req_size, GFP_KERNEL);
resp = kmalloc(resp_size, GFP_KERNEL);
if (!req || !resp) {
kfree(req);
kfree(resp);
return -ENOMEM;
}
req->num_streams = nstreams;
req->flags = *flags;
req->padding = 0;
for (i = 0; i < nstreams; ++i) {
struct gb_camera_stream_config_request *cfg = &req->config[i];
cfg->width = cpu_to_le16(streams[i].width);
cfg->height = cpu_to_le16(streams[i].height);
cfg->format = cpu_to_le16(streams[i].format);
cfg->padding = 0;
}
mutex_lock(&gcam->mutex);
ret = gb_pm_runtime_get_sync(gcam->bundle);
if (ret)
goto done_skip_pm_put;
if (!gcam->connection) {
ret = -EINVAL;
goto done;
}
ret = gb_camera_operation_sync_flags(gcam->connection,
GB_CAMERA_TYPE_CONFIGURE_STREAMS,
GB_OPERATION_FLAG_SHORT_RESPONSE,
req, req_size,
resp, &resp_size);
if (ret < 0)
goto done;
ret = gb_camera_configure_streams_validate_response(gcam, resp,
nstreams);
if (ret < 0)
goto done;
*flags = resp->flags;
*num_streams = resp->num_streams;
for (i = 0; i < resp->num_streams; ++i) {
struct gb_camera_stream_config_response *cfg = &resp->config[i];
streams[i].width = le16_to_cpu(cfg->width);
streams[i].height = le16_to_cpu(cfg->height);
streams[i].format = le16_to_cpu(cfg->format);
streams[i].vc = cfg->virtual_channel;
streams[i].dt[0] = cfg->data_type[0];
streams[i].dt[1] = cfg->data_type[1];
streams[i].max_size = le32_to_cpu(cfg->max_size);
}
if ((resp->flags & GB_CAMERA_CONFIGURE_STREAMS_ADJUSTED) ||
(req->flags & GB_CAMERA_CONFIGURE_STREAMS_TEST_ONLY))
goto done;
if (gcam->state == GB_CAMERA_STATE_CONFIGURED) {
gb_camera_teardown_data_connection(gcam);
gcam->state = GB_CAMERA_STATE_UNCONFIGURED;
gb_pm_runtime_put_noidle(gcam->bundle);
}
if (resp->num_streams == 0)
goto done;
gb_pm_runtime_get_noresume(gcam->bundle);
ret = gb_camera_setup_data_connection(gcam, resp, csi_params);
if (ret < 0) {
memset(req, 0, sizeof(*req));
gb_operation_sync(gcam->connection,
GB_CAMERA_TYPE_CONFIGURE_STREAMS,
req, sizeof(*req),
resp, sizeof(*resp));
*flags = 0;
*num_streams = 0;
gb_pm_runtime_put_noidle(gcam->bundle);
goto done;
}
gcam->state = GB_CAMERA_STATE_CONFIGURED;
done:
gb_pm_runtime_put_autosuspend(gcam->bundle);
done_skip_pm_put:
mutex_unlock(&gcam->mutex);
kfree(req);
kfree(resp);
return ret;
}
static int gb_camera_capture(struct gb_camera *gcam, u32 request_id,
unsigned int streams, unsigned int num_frames,
size_t settings_size, const void *settings)
{
struct gb_camera_capture_request *req;
size_t req_size;
int ret;
if (settings_size > GB_CAMERA_MAX_SETTINGS_SIZE)
return -EINVAL;
req_size = sizeof(*req) + settings_size;
req = kmalloc(req_size, GFP_KERNEL);
if (!req)
return -ENOMEM;
req->request_id = cpu_to_le32(request_id);
req->streams = streams;
req->padding = 0;
req->num_frames = cpu_to_le16(num_frames);
memcpy(req->settings, settings, settings_size);
mutex_lock(&gcam->mutex);
if (!gcam->connection) {
ret = -EINVAL;
goto done;
}
ret = gb_operation_sync(gcam->connection, GB_CAMERA_TYPE_CAPTURE,
req, req_size, NULL, 0);
done:
mutex_unlock(&gcam->mutex);
kfree(req);
return ret;
}
static int gb_camera_flush(struct gb_camera *gcam, u32 *request_id)
{
struct gb_camera_flush_response resp;
int ret;
mutex_lock(&gcam->mutex);
if (!gcam->connection) {
ret = -EINVAL;
goto done;
}
ret = gb_operation_sync(gcam->connection, GB_CAMERA_TYPE_FLUSH, NULL, 0,
&resp, sizeof(resp));
if (ret < 0)
goto done;
if (request_id)
*request_id = le32_to_cpu(resp.request_id);
done:
mutex_unlock(&gcam->mutex);
return ret;
}
static int gb_camera_request_handler(struct gb_operation *op)
{
struct gb_camera *gcam = gb_connection_get_data(op->connection);
struct gb_camera_metadata_request *payload;
struct gb_message *request;
if (op->type != GB_CAMERA_TYPE_METADATA) {
gcam_err(gcam, "Unsupported unsolicited event: %u\n", op->type);
return -EINVAL;
}
request = op->request;
if (request->payload_size < sizeof(*payload)) {
gcam_err(gcam, "Wrong event size received (%zu < %zu)\n",
request->payload_size, sizeof(*payload));
return -EINVAL;
}
payload = request->payload;
gcam_dbg(gcam, "received metadata for request %u, frame %u, stream %u\n",
payload->request_id, payload->frame_number, payload->stream);
return 0;
}
static unsigned int gb_camera_mbus_to_gb(enum v4l2_mbus_pixelcode mbus_code)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(gb_fmt_info); i++) {
if (gb_fmt_info[i].mbus_code == mbus_code)
return gb_fmt_info[i].gb_format;
}
return gb_fmt_info[0].gb_format;
}
static enum v4l2_mbus_pixelcode gb_camera_gb_to_mbus(u16 gb_fmt)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(gb_fmt_info); i++) {
if (gb_fmt_info[i].gb_format == gb_fmt)
return gb_fmt_info[i].mbus_code;
}
return gb_fmt_info[0].mbus_code;
}
static ssize_t gb_camera_op_capabilities(void *priv, char *data, size_t len)
{
struct gb_camera *gcam = priv;
size_t capabilities_len = len;
int ret;
ret = gb_camera_capabilities(gcam, data, &capabilities_len);
if (ret)
return ret;
return capabilities_len;
}
static int gb_camera_op_configure_streams(void *priv, unsigned int *nstreams,
unsigned int *flags, struct gb_camera_stream *streams,
struct gb_camera_csi_params *csi_params)
{
struct gb_camera *gcam = priv;
struct gb_camera_stream_config *gb_streams;
unsigned int gb_flags = 0;
unsigned int gb_nstreams = *nstreams;
unsigned int i;
int ret;
if (gb_nstreams > GB_CAMERA_MAX_STREAMS)
return -EINVAL;
gb_streams = kzalloc(gb_nstreams * sizeof(*gb_streams), GFP_KERNEL);
if (!gb_streams)
return -ENOMEM;
for (i = 0; i < gb_nstreams; i++) {
gb_streams[i].width = streams[i].width;
gb_streams[i].height = streams[i].height;
gb_streams[i].format =
gb_camera_mbus_to_gb(streams[i].pixel_code);
}
if (*flags & GB_CAMERA_IN_FLAG_TEST)
gb_flags |= GB_CAMERA_CONFIGURE_STREAMS_TEST_ONLY;
ret = gb_camera_configure_streams(gcam, &gb_nstreams,
&gb_flags, gb_streams, csi_params);
if (ret < 0)
goto done;
if (gb_nstreams > *nstreams) {
ret = -EINVAL;
goto done;
}
*flags = 0;
if (gb_flags & GB_CAMERA_CONFIGURE_STREAMS_ADJUSTED)
*flags |= GB_CAMERA_OUT_FLAG_ADJUSTED;
for (i = 0; i < gb_nstreams; i++) {
streams[i].width = gb_streams[i].width;
streams[i].height = gb_streams[i].height;
streams[i].vc = gb_streams[i].vc;
streams[i].dt[0] = gb_streams[i].dt[0];
streams[i].dt[1] = gb_streams[i].dt[1];
streams[i].max_size = gb_streams[i].max_size;
streams[i].pixel_code =
gb_camera_gb_to_mbus(gb_streams[i].format);
}
*nstreams = gb_nstreams;
done:
kfree(gb_streams);
return ret;
}
static int gb_camera_op_capture(void *priv, u32 request_id,
unsigned int streams, unsigned int num_frames,
size_t settings_size, const void *settings)
{
struct gb_camera *gcam = priv;
return gb_camera_capture(gcam, request_id, streams, num_frames,
settings_size, settings);
}
static int gb_camera_op_flush(void *priv, u32 *request_id)
{
struct gb_camera *gcam = priv;
return gb_camera_flush(gcam, request_id);
}
static ssize_t gb_camera_debugfs_capabilities(struct gb_camera *gcam,
char *buf, size_t len)
{
struct gb_camera_debugfs_buffer *buffer =
&gcam->debugfs.buffers[GB_CAMERA_DEBUGFS_BUFFER_CAPABILITIES];
size_t size = 1024;
unsigned int i;
u8 *caps;
int ret;
caps = kmalloc(size, GFP_KERNEL);
if (!caps)
return -ENOMEM;
ret = gb_camera_capabilities(gcam, caps, &size);
if (ret < 0)
goto done;
buffer->length = 0;
for (i = 0; i < size; i += 16) {
unsigned int nbytes = min_t(unsigned int, size - i, 16);
buffer->length += sprintf(buffer->data + buffer->length,
"%*ph\n", nbytes, caps + i);
}
done:
kfree(caps);
return ret;
}
static ssize_t gb_camera_debugfs_configure_streams(struct gb_camera *gcam,
char *buf, size_t len)
{
struct gb_camera_debugfs_buffer *buffer =
&gcam->debugfs.buffers[GB_CAMERA_DEBUGFS_BUFFER_STREAMS];
struct gb_camera_stream_config *streams;
unsigned int nstreams;
unsigned int flags;
unsigned int i;
char *token;
int ret;
token = strsep(&buf, ";");
if (token == NULL)
return -EINVAL;
ret = kstrtouint(token, 10, &nstreams);
if (ret < 0)
return ret;
if (nstreams > GB_CAMERA_MAX_STREAMS)
return -EINVAL;
token = strsep(&buf, ";");
if (token == NULL)
return -EINVAL;
ret = kstrtouint(token, 10, &flags);
if (ret < 0)
return ret;
streams = kzalloc(nstreams * sizeof(*streams), GFP_KERNEL);
if (!streams)
return -ENOMEM;
for (i = 0; i < nstreams; ++i) {
struct gb_camera_stream_config *stream = &streams[i];
token = strsep(&buf, ";");
if (token == NULL) {
ret = -EINVAL;
goto done;
}
ret = kstrtouint(token, 10, &stream->width);
if (ret < 0)
goto done;
token = strsep(&buf, ";");
if (token == NULL)
goto done;
ret = kstrtouint(token, 10, &stream->height);
if (ret < 0)
goto done;
token = strsep(&buf, ";");
if (token == NULL)
goto done;
ret = kstrtouint(token, 16, &stream->format);
if (ret < 0)
goto done;
}
ret = gb_camera_configure_streams(gcam, &nstreams, &flags, streams,
NULL);
if (ret < 0)
goto done;
buffer->length = sprintf(buffer->data, "%u;%u;", nstreams, flags);
for (i = 0; i < nstreams; ++i) {
struct gb_camera_stream_config *stream = &streams[i];
buffer->length += sprintf(buffer->data + buffer->length,
"%u;%u;%u;%u;%u;%u;%u;",
stream->width, stream->height,
stream->format, stream->vc,
stream->dt[0], stream->dt[1],
stream->max_size);
}
ret = len;
done:
kfree(streams);
return ret;
}
static ssize_t gb_camera_debugfs_capture(struct gb_camera *gcam,
char *buf, size_t len)
{
unsigned int request_id;
unsigned int streams_mask;
unsigned int num_frames;
char *token;
int ret;
token = strsep(&buf, ";");
if (token == NULL)
return -EINVAL;
ret = kstrtouint(token, 10, &request_id);
if (ret < 0)
return ret;
token = strsep(&buf, ";");
if (token == NULL)
return -EINVAL;
ret = kstrtouint(token, 16, &streams_mask);
if (ret < 0)
return ret;
token = strsep(&buf, ";");
if (token == NULL)
return -EINVAL;
ret = kstrtouint(token, 10, &num_frames);
if (ret < 0)
return ret;
ret = gb_camera_capture(gcam, request_id, streams_mask, num_frames, 0,
NULL);
if (ret < 0)
return ret;
return len;
}
static ssize_t gb_camera_debugfs_flush(struct gb_camera *gcam,
char *buf, size_t len)
{
struct gb_camera_debugfs_buffer *buffer =
&gcam->debugfs.buffers[GB_CAMERA_DEBUGFS_BUFFER_FLUSH];
unsigned int req_id;
int ret;
ret = gb_camera_flush(gcam, &req_id);
if (ret < 0)
return ret;
buffer->length = sprintf(buffer->data, "%u", req_id);
return len;
}
static ssize_t gb_camera_debugfs_read(struct file *file, char __user *buf,
size_t len, loff_t *offset)
{
const struct gb_camera_debugfs_entry *op = file->private_data;
struct gb_camera *gcam = file->f_inode->i_private;
struct gb_camera_debugfs_buffer *buffer;
ssize_t ret;
if (!(op->mask & S_IWUGO)) {
ret = op->execute(gcam, NULL, 0);
if (ret < 0)
return ret;
}
buffer = &gcam->debugfs.buffers[op->buffer];
return simple_read_from_buffer(buf, len, offset, buffer->data,
buffer->length);
}
static ssize_t gb_camera_debugfs_write(struct file *file,
const char __user *buf, size_t len,
loff_t *offset)
{
const struct gb_camera_debugfs_entry *op = file->private_data;
struct gb_camera *gcam = file->f_inode->i_private;
ssize_t ret;
char *kbuf;
if (len > 1024)
return -EINVAL;
kbuf = kmalloc(len + 1, GFP_KERNEL);
if (!kbuf)
return -ENOMEM;
if (copy_from_user(kbuf, buf, len)) {
ret = -EFAULT;
goto done;
}
kbuf[len] = '\0';
ret = op->execute(gcam, kbuf, len);
done:
kfree(kbuf);
return ret;
}
static int gb_camera_debugfs_open(struct inode *inode, struct file *file)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(gb_camera_debugfs_entries); ++i) {
const struct gb_camera_debugfs_entry *entry =
&gb_camera_debugfs_entries[i];
if (!strcmp(file->f_path.dentry->d_iname, entry->name)) {
file->private_data = (void *)entry;
break;
}
}
return 0;
}
static int gb_camera_debugfs_init(struct gb_camera *gcam)
{
struct gb_connection *connection = gcam->connection;
char dirname[27];
unsigned int i;
snprintf(dirname, 27, "camera-%u.%u", connection->intf->interface_id,
gcam->bundle->id);
gcam->debugfs.root = debugfs_create_dir(dirname, gb_debugfs_get());
if (IS_ERR(gcam->debugfs.root)) {
gcam_err(gcam, "debugfs root create failed (%ld)\n",
PTR_ERR(gcam->debugfs.root));
return PTR_ERR(gcam->debugfs.root);
}
gcam->debugfs.buffers = vmalloc(sizeof(*gcam->debugfs.buffers) *
GB_CAMERA_DEBUGFS_BUFFER_MAX);
if (!gcam->debugfs.buffers)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(gb_camera_debugfs_entries); ++i) {
const struct gb_camera_debugfs_entry *entry =
&gb_camera_debugfs_entries[i];
struct dentry *dentry;
gcam->debugfs.buffers[i].length = 0;
dentry = debugfs_create_file(entry->name, entry->mask,
gcam->debugfs.root, gcam,
&gb_camera_debugfs_ops);
if (IS_ERR(dentry)) {
gcam_err(gcam,
"debugfs operation %s create failed (%ld)\n",
entry->name, PTR_ERR(dentry));
return PTR_ERR(dentry);
}
}
return 0;
}
static void gb_camera_debugfs_cleanup(struct gb_camera *gcam)
{
debugfs_remove_recursive(gcam->debugfs.root);
vfree(gcam->debugfs.buffers);
}
static void gb_camera_cleanup(struct gb_camera *gcam)
{
gb_camera_debugfs_cleanup(gcam);
mutex_lock(&gcam->mutex);
if (gcam->data_connection) {
gb_connection_disable(gcam->data_connection);
gb_connection_destroy(gcam->data_connection);
gcam->data_connection = NULL;
}
if (gcam->connection) {
gb_connection_disable(gcam->connection);
gb_connection_destroy(gcam->connection);
gcam->connection = NULL;
}
mutex_unlock(&gcam->mutex);
}
static void gb_camera_release_module(struct kref *ref)
{
struct gb_camera_module *cam_mod =
container_of(ref, struct gb_camera_module, refcount);
kfree(cam_mod->priv);
}
static int gb_camera_probe(struct gb_bundle *bundle,
const struct greybus_bundle_id *id)
{
struct gb_connection *conn;
struct gb_camera *gcam;
u16 mgmt_cport_id = 0;
u16 data_cport_id = 0;
unsigned int i;
int ret;
if (bundle->num_cports != 2)
return -ENODEV;
for (i = 0; i < bundle->num_cports; ++i) {
struct greybus_descriptor_cport *desc = &bundle->cport_desc[i];
switch (desc->protocol_id) {
case GREYBUS_PROTOCOL_CAMERA_MGMT:
mgmt_cport_id = le16_to_cpu(desc->id);
break;
case GREYBUS_PROTOCOL_CAMERA_DATA:
data_cport_id = le16_to_cpu(desc->id);
break;
default:
return -ENODEV;
}
}
if (!mgmt_cport_id || !data_cport_id)
return -ENODEV;
gcam = kzalloc(sizeof(*gcam), GFP_KERNEL);
if (!gcam)
return -ENOMEM;
mutex_init(&gcam->mutex);
gcam->bundle = bundle;
gcam->state = GB_CAMERA_STATE_UNCONFIGURED;
gcam->data_cport_id = data_cport_id;
conn = gb_connection_create(bundle, mgmt_cport_id,
gb_camera_request_handler);
if (IS_ERR(conn)) {
ret = PTR_ERR(conn);
goto error;
}
gcam->connection = conn;
gb_connection_set_data(conn, gcam);
ret = gb_connection_enable(conn);
if (ret)
goto error;
ret = gb_camera_debugfs_init(gcam);
if (ret < 0)
goto error;
gcam->module.priv = gcam;
gcam->module.ops = &gb_cam_ops;
gcam->module.interface_id = gcam->connection->intf->interface_id;
gcam->module.release = gb_camera_release_module;
ret = gb_camera_register(&gcam->module);
if (ret < 0)
goto error;
greybus_set_drvdata(bundle, gcam);
gb_pm_runtime_put_autosuspend(gcam->bundle);
return 0;
error:
gb_camera_cleanup(gcam);
kfree(gcam);
return ret;
}
static void gb_camera_disconnect(struct gb_bundle *bundle)
{
struct gb_camera *gcam = greybus_get_drvdata(bundle);
int ret;
ret = gb_pm_runtime_get_sync(bundle);
if (ret)
gb_pm_runtime_get_noresume(bundle);
gb_camera_cleanup(gcam);
gb_camera_unregister(&gcam->module);
}
static int gb_camera_suspend(struct device *dev)
{
struct gb_bundle *bundle = to_gb_bundle(dev);
struct gb_camera *gcam = greybus_get_drvdata(bundle);
if (gcam->data_connection)
gb_connection_disable(gcam->data_connection);
gb_connection_disable(gcam->connection);
return 0;
}
static int gb_camera_resume(struct device *dev)
{
struct gb_bundle *bundle = to_gb_bundle(dev);
struct gb_camera *gcam = greybus_get_drvdata(bundle);
int ret;
ret = gb_connection_enable(gcam->connection);
if (ret) {
gcam_err(gcam, "failed to enable connection: %d\n", ret);
return ret;
}
if (gcam->data_connection) {
ret = gb_connection_enable(gcam->data_connection);
if (ret) {
gcam_err(gcam,
"failed to enable data connection: %d\n", ret);
return ret;
}
}
return 0;
}
