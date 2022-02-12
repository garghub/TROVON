static int rpmsg_sample_cb(struct rpmsg_device *rpdev, void *data, int len,
void *priv, u32 src)
{
int ret;
struct instance_data *idata = dev_get_drvdata(&rpdev->dev);
dev_info(&rpdev->dev, "incoming msg %d (src: 0x%x)\n",
++idata->rx_count, src);
print_hex_dump(KERN_DEBUG, __func__, DUMP_PREFIX_NONE, 16, 1,
data, len, true);
if (idata->rx_count >= MSG_LIMIT) {
dev_info(&rpdev->dev, "goodbye!\n");
return 0;
}
ret = rpmsg_send(rpdev->ept, MSG, strlen(MSG));
if (ret)
dev_err(&rpdev->dev, "rpmsg_send failed: %d\n", ret);
return 0;
}
static int rpmsg_sample_probe(struct rpmsg_device *rpdev)
{
int ret;
struct instance_data *idata;
dev_info(&rpdev->dev, "new channel: 0x%x -> 0x%x!\n",
rpdev->src, rpdev->dst);
idata = devm_kzalloc(&rpdev->dev, sizeof(*idata), GFP_KERNEL);
if (!idata)
return -ENOMEM;
dev_set_drvdata(&rpdev->dev, idata);
ret = rpmsg_send(rpdev->ept, MSG, strlen(MSG));
if (ret) {
dev_err(&rpdev->dev, "rpmsg_send failed: %d\n", ret);
return ret;
}
return 0;
}
static void rpmsg_sample_remove(struct rpmsg_device *rpdev)
{
dev_info(&rpdev->dev, "rpmsg sample client driver is removed\n");
}
