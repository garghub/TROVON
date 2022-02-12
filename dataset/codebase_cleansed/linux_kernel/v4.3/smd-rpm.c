int qcom_rpm_smd_write(struct qcom_smd_rpm *rpm,
int state,
u32 type, u32 id,
void *buf,
size_t count)
{
static unsigned msg_id = 1;
int left;
int ret;
struct {
struct qcom_rpm_header hdr;
struct qcom_rpm_request req;
u8 payload[count];
} pkt;
if (WARN_ON(sizeof(pkt) >= 256))
return -EINVAL;
mutex_lock(&rpm->lock);
pkt.hdr.service_type = RPM_SERVICE_TYPE_REQUEST;
pkt.hdr.length = sizeof(struct qcom_rpm_request) + count;
pkt.req.msg_id = msg_id++;
pkt.req.flags = BIT(state);
pkt.req.type = type;
pkt.req.id = id;
pkt.req.data_len = count;
memcpy(pkt.payload, buf, count);
ret = qcom_smd_send(rpm->rpm_channel, &pkt, sizeof(pkt));
if (ret)
goto out;
left = wait_for_completion_timeout(&rpm->ack, RPM_REQUEST_TIMEOUT);
if (!left)
ret = -ETIMEDOUT;
else
ret = rpm->ack_status;
out:
mutex_unlock(&rpm->lock);
return ret;
}
static int qcom_smd_rpm_callback(struct qcom_smd_device *qsdev,
const void *data,
size_t count)
{
const struct qcom_rpm_header *hdr = data;
const struct qcom_rpm_message *msg;
struct qcom_smd_rpm *rpm = dev_get_drvdata(&qsdev->dev);
const u8 *buf = data + sizeof(struct qcom_rpm_header);
const u8 *end = buf + hdr->length;
char msgbuf[32];
int status = 0;
u32 len;
if (hdr->service_type != RPM_SERVICE_TYPE_REQUEST ||
hdr->length < sizeof(struct qcom_rpm_message)) {
dev_err(&qsdev->dev, "invalid request\n");
return 0;
}
while (buf < end) {
msg = (struct qcom_rpm_message *)buf;
switch (msg->msg_type) {
case RPM_MSG_TYPE_MSG_ID:
break;
case RPM_MSG_TYPE_ERR:
len = min_t(u32, ALIGN(msg->length, 4), sizeof(msgbuf));
memcpy_fromio(msgbuf, msg->message, len);
msgbuf[len - 1] = 0;
if (!strcmp(msgbuf, "resource does not exist"))
status = -ENXIO;
else
status = -EINVAL;
break;
}
buf = PTR_ALIGN(buf + 2 * sizeof(u32) + msg->length, 4);
}
rpm->ack_status = status;
complete(&rpm->ack);
return 0;
}
static int qcom_smd_rpm_probe(struct qcom_smd_device *sdev)
{
struct qcom_smd_rpm *rpm;
rpm = devm_kzalloc(&sdev->dev, sizeof(*rpm), GFP_KERNEL);
if (!rpm)
return -ENOMEM;
mutex_init(&rpm->lock);
init_completion(&rpm->ack);
rpm->rpm_channel = sdev->channel;
dev_set_drvdata(&sdev->dev, rpm);
return of_platform_populate(sdev->dev.of_node, NULL, NULL, &sdev->dev);
}
static void qcom_smd_rpm_remove(struct qcom_smd_device *sdev)
{
of_platform_depopulate(&sdev->dev);
}
static int __init qcom_smd_rpm_init(void)
{
return qcom_smd_driver_register(&qcom_smd_rpm_driver);
}
static void __exit qcom_smd_rpm_exit(void)
{
qcom_smd_driver_unregister(&qcom_smd_rpm_driver);
}
