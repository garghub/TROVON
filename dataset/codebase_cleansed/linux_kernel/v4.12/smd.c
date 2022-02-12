static int qcom_smd_qrtr_callback(struct rpmsg_device *rpdev,
void *data, int len, void *priv, u32 addr)
{
struct qrtr_smd_dev *qdev = dev_get_drvdata(&rpdev->dev);
int rc;
if (!qdev)
return -EAGAIN;
rc = qrtr_endpoint_post(&qdev->ep, data, len);
if (rc == -EINVAL) {
dev_err(qdev->dev, "invalid ipcrouter packet\n");
rc = 0;
}
return rc;
}
static int qcom_smd_qrtr_send(struct qrtr_endpoint *ep, struct sk_buff *skb)
{
struct qrtr_smd_dev *qdev = container_of(ep, struct qrtr_smd_dev, ep);
int rc;
rc = skb_linearize(skb);
if (rc)
goto out;
rc = rpmsg_send(qdev->channel, skb->data, skb->len);
out:
if (rc)
kfree_skb(skb);
else
consume_skb(skb);
return rc;
}
static int qcom_smd_qrtr_probe(struct rpmsg_device *rpdev)
{
struct qrtr_smd_dev *qdev;
int rc;
qdev = devm_kzalloc(&rpdev->dev, sizeof(*qdev), GFP_KERNEL);
if (!qdev)
return -ENOMEM;
qdev->channel = rpdev->ept;
qdev->dev = &rpdev->dev;
qdev->ep.xmit = qcom_smd_qrtr_send;
rc = qrtr_endpoint_register(&qdev->ep, QRTR_EP_NID_AUTO);
if (rc)
return rc;
dev_set_drvdata(&rpdev->dev, qdev);
dev_dbg(&rpdev->dev, "Qualcomm SMD QRTR driver probed\n");
return 0;
}
static void qcom_smd_qrtr_remove(struct rpmsg_device *rpdev)
{
struct qrtr_smd_dev *qdev = dev_get_drvdata(&rpdev->dev);
qrtr_endpoint_unregister(&qdev->ep);
dev_set_drvdata(&rpdev->dev, NULL);
}
