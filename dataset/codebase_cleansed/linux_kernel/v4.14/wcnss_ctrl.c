static int wcnss_ctrl_smd_callback(struct rpmsg_device *rpdev,
void *data,
int count,
void *priv,
u32 addr)
{
struct wcnss_ctrl *wcnss = dev_get_drvdata(&rpdev->dev);
const struct wcnss_download_nv_resp *nvresp;
const struct wcnss_version_resp *version;
const struct wcnss_msg_hdr *hdr = data;
switch (hdr->type) {
case WCNSS_VERSION_RESP:
if (count != sizeof(*version)) {
dev_err(wcnss->dev,
"invalid size of version response\n");
break;
}
version = data;
dev_info(wcnss->dev, "WCNSS Version %d.%d %d.%d\n",
version->major, version->minor,
version->version, version->revision);
complete(&wcnss->ack);
break;
case WCNSS_DOWNLOAD_NV_RESP:
if (count != sizeof(*nvresp)) {
dev_err(wcnss->dev,
"invalid size of download response\n");
break;
}
nvresp = data;
wcnss->ack_status = nvresp->status;
complete(&wcnss->ack);
break;
case WCNSS_CBC_COMPLETE_IND:
dev_dbg(wcnss->dev, "cold boot complete\n");
complete(&wcnss->cbc);
break;
default:
dev_info(wcnss->dev, "unknown message type %d\n", hdr->type);
break;
}
return 0;
}
static int wcnss_request_version(struct wcnss_ctrl *wcnss)
{
struct wcnss_msg_hdr msg;
int ret;
msg.type = WCNSS_VERSION_REQ;
msg.len = sizeof(msg);
ret = rpmsg_send(wcnss->channel, &msg, sizeof(msg));
if (ret < 0)
return ret;
ret = wait_for_completion_timeout(&wcnss->ack, WCNSS_CBC_TIMEOUT);
if (!ret) {
dev_err(wcnss->dev, "timeout waiting for version response\n");
return -ETIMEDOUT;
}
return 0;
}
static int wcnss_download_nv(struct wcnss_ctrl *wcnss, bool *expect_cbc)
{
struct wcnss_download_nv_req *req;
const struct firmware *fw;
const void *data;
ssize_t left;
int ret;
req = kzalloc(sizeof(*req) + NV_FRAGMENT_SIZE, GFP_KERNEL);
if (!req)
return -ENOMEM;
ret = request_firmware(&fw, NVBIN_FILE, wcnss->dev);
if (ret < 0) {
dev_err(wcnss->dev, "Failed to load nv file %s: %d\n",
NVBIN_FILE, ret);
goto free_req;
}
data = fw->data;
left = fw->size;
req->hdr.type = WCNSS_DOWNLOAD_NV_REQ;
req->hdr.len = sizeof(*req) + NV_FRAGMENT_SIZE;
req->last = 0;
req->frag_size = NV_FRAGMENT_SIZE;
req->seq = 0;
do {
if (left <= NV_FRAGMENT_SIZE) {
req->last = 1;
req->frag_size = left;
req->hdr.len = sizeof(*req) + left;
}
memcpy(req->fragment, data, req->frag_size);
ret = rpmsg_send(wcnss->channel, req, req->hdr.len);
if (ret < 0) {
dev_err(wcnss->dev, "failed to send smd packet\n");
goto release_fw;
}
req->seq++;
data += req->hdr.len;
left -= NV_FRAGMENT_SIZE;
} while (left > 0);
ret = wait_for_completion_timeout(&wcnss->ack, WCNSS_REQUEST_TIMEOUT);
if (!ret) {
dev_err(wcnss->dev, "timeout waiting for nv upload ack\n");
ret = -ETIMEDOUT;
} else {
*expect_cbc = wcnss->ack_status == WCNSS_ACK_COLD_BOOTING;
ret = 0;
}
release_fw:
release_firmware(fw);
free_req:
kfree(req);
return ret;
}
struct rpmsg_endpoint *qcom_wcnss_open_channel(void *wcnss, const char *name, rpmsg_rx_cb_t cb, void *priv)
{
struct rpmsg_channel_info chinfo;
struct wcnss_ctrl *_wcnss = wcnss;
strncpy(chinfo.name, name, sizeof(chinfo.name));
chinfo.src = RPMSG_ADDR_ANY;
chinfo.dst = RPMSG_ADDR_ANY;
return rpmsg_create_ept(_wcnss->channel->rpdev, cb, priv, chinfo);
}
static void wcnss_async_probe(struct work_struct *work)
{
struct wcnss_ctrl *wcnss = container_of(work, struct wcnss_ctrl, probe_work);
bool expect_cbc;
int ret;
ret = wcnss_request_version(wcnss);
if (ret < 0)
return;
ret = wcnss_download_nv(wcnss, &expect_cbc);
if (ret < 0)
return;
if (expect_cbc) {
ret = wait_for_completion_timeout(&wcnss->cbc, WCNSS_REQUEST_TIMEOUT);
if (!ret)
dev_err(wcnss->dev, "expected cold boot completion\n");
}
of_platform_populate(wcnss->dev->of_node, NULL, NULL, wcnss->dev);
}
static int wcnss_ctrl_probe(struct rpmsg_device *rpdev)
{
struct wcnss_ctrl *wcnss;
wcnss = devm_kzalloc(&rpdev->dev, sizeof(*wcnss), GFP_KERNEL);
if (!wcnss)
return -ENOMEM;
wcnss->dev = &rpdev->dev;
wcnss->channel = rpdev->ept;
init_completion(&wcnss->ack);
init_completion(&wcnss->cbc);
INIT_WORK(&wcnss->probe_work, wcnss_async_probe);
dev_set_drvdata(&rpdev->dev, wcnss);
schedule_work(&wcnss->probe_work);
return 0;
}
static void wcnss_ctrl_remove(struct rpmsg_device *rpdev)
{
struct wcnss_ctrl *wcnss = dev_get_drvdata(&rpdev->dev);
cancel_work_sync(&wcnss->probe_work);
of_platform_depopulate(&rpdev->dev);
}
