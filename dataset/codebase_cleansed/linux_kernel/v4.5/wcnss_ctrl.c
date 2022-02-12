static int wcnss_ctrl_smd_callback(struct qcom_smd_device *qsdev,
const void *data,
size_t count)
{
struct wcnss_ctrl *wcnss = dev_get_drvdata(&qsdev->dev);
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
schedule_work(&wcnss->download_nv_work);
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
default:
dev_info(wcnss->dev, "unknown message type %d\n", hdr->type);
break;
}
return 0;
}
static int wcnss_request_version(struct wcnss_ctrl *wcnss)
{
struct wcnss_msg_hdr msg;
msg.type = WCNSS_VERSION_REQ;
msg.len = sizeof(msg);
return qcom_smd_send(wcnss->channel, &msg, sizeof(msg));
}
static void wcnss_download_nv(struct work_struct *work)
{
struct wcnss_ctrl *wcnss = container_of(work, struct wcnss_ctrl, download_nv_work);
struct wcnss_download_nv_req *req;
const struct firmware *fw;
const void *data;
ssize_t left;
int ret;
req = kzalloc(sizeof(*req) + NV_FRAGMENT_SIZE, GFP_KERNEL);
if (!req)
return;
ret = request_firmware(&fw, NVBIN_FILE, wcnss->dev);
if (ret) {
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
ret = qcom_smd_send(wcnss->channel, req, req->hdr.len);
if (ret) {
dev_err(wcnss->dev, "failed to send smd packet\n");
goto release_fw;
}
req->seq++;
data += req->hdr.len;
left -= NV_FRAGMENT_SIZE;
} while (left > 0);
ret = wait_for_completion_timeout(&wcnss->ack, WCNSS_REQUEST_TIMEOUT);
if (!ret)
dev_err(wcnss->dev, "timeout waiting for nv upload ack\n");
else if (wcnss->ack_status != 1)
dev_err(wcnss->dev, "nv upload response failed err: %d\n",
wcnss->ack_status);
release_fw:
release_firmware(fw);
free_req:
kfree(req);
}
static int wcnss_ctrl_probe(struct qcom_smd_device *sdev)
{
struct wcnss_ctrl *wcnss;
wcnss = devm_kzalloc(&sdev->dev, sizeof(*wcnss), GFP_KERNEL);
if (!wcnss)
return -ENOMEM;
wcnss->dev = &sdev->dev;
wcnss->channel = sdev->channel;
init_completion(&wcnss->ack);
INIT_WORK(&wcnss->download_nv_work, wcnss_download_nv);
dev_set_drvdata(&sdev->dev, wcnss);
return wcnss_request_version(wcnss);
}
