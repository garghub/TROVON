static int qcom_glink_ssr_callback(struct rpmsg_device *rpdev,
void *data, int len, void *priv, u32 addr)
{
struct cleanup_done_msg *msg = data;
struct glink_ssr *ssr = dev_get_drvdata(&rpdev->dev);
if (len < sizeof(*msg)) {
dev_err(ssr->dev, "message too short\n");
return -EINVAL;
}
if (le32_to_cpu(msg->version) != 0)
return -EINVAL;
if (le32_to_cpu(msg->response) != GLINK_SSR_CLEANUP_DONE)
return 0;
if (le32_to_cpu(msg->seq_num) != ssr->seq_num) {
dev_err(ssr->dev, "invalid sequence number of response\n");
return -EINVAL;
}
complete(&ssr->completion);
return 0;
}
static int qcom_glink_ssr_notify(struct notifier_block *nb, unsigned long event,
void *data)
{
struct glink_ssr *ssr = container_of(nb, struct glink_ssr, nb);
struct do_cleanup_msg msg;
char *ssr_name = data;
int ret;
ssr->seq_num++;
reinit_completion(&ssr->completion);
memset(&msg, 0, sizeof(msg));
msg.command = cpu_to_le32(GLINK_SSR_DO_CLEANUP);
msg.seq_num = cpu_to_le32(ssr->seq_num);
msg.name_len = cpu_to_le32(strlen(ssr_name));
strlcpy(msg.name, ssr_name, sizeof(msg.name));
ret = rpmsg_send(ssr->ept, &msg, sizeof(msg));
if (ret < 0)
dev_err(ssr->dev, "failed to send cleanup message\n");
ret = wait_for_completion_timeout(&ssr->completion, HZ);
if (!ret)
dev_err(ssr->dev, "timeout waiting for cleanup done message\n");
return NOTIFY_DONE;
}
static int qcom_glink_ssr_probe(struct rpmsg_device *rpdev)
{
struct glink_ssr *ssr;
ssr = devm_kzalloc(&rpdev->dev, sizeof(*ssr), GFP_KERNEL);
if (!ssr)
return -ENOMEM;
init_completion(&ssr->completion);
ssr->dev = &rpdev->dev;
ssr->ept = rpdev->ept;
ssr->nb.notifier_call = qcom_glink_ssr_notify;
dev_set_drvdata(&rpdev->dev, ssr);
return qcom_register_ssr_notifier(&ssr->nb);
}
static void qcom_glink_ssr_remove(struct rpmsg_device *rpdev)
{
struct glink_ssr *ssr = dev_get_drvdata(&rpdev->dev);
qcom_unregister_ssr_notifier(&ssr->nb);
}
