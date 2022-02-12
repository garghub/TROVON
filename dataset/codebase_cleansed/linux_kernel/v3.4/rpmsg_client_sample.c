static void rpmsg_sample_cb(struct rpmsg_channel *rpdev, void *data, int len,
void *priv, u32 src)
{
int ret;
static int rx_count;
dev_info(&rpdev->dev, "incoming msg %d (src: 0x%x)\n", ++rx_count, src);
print_hex_dump(KERN_DEBUG, __func__, DUMP_PREFIX_NONE, 16, 1,
data, len, true);
if (rx_count >= MSG_LIMIT) {
dev_info(&rpdev->dev, "goodbye!\n");
return;
}
ret = rpmsg_send(rpdev, MSG, strlen(MSG));
if (ret)
dev_err(&rpdev->dev, "rpmsg_send failed: %d\n", ret);
}
static int rpmsg_sample_probe(struct rpmsg_channel *rpdev)
{
int ret;
dev_info(&rpdev->dev, "new channel: 0x%x -> 0x%x!\n",
rpdev->src, rpdev->dst);
ret = rpmsg_send(rpdev, MSG, strlen(MSG));
if (ret) {
dev_err(&rpdev->dev, "rpmsg_send failed: %d\n", ret);
return ret;
}
return 0;
}
static void __devexit rpmsg_sample_remove(struct rpmsg_channel *rpdev)
{
dev_info(&rpdev->dev, "rpmsg sample client driver is removed\n");
}
static int __init rpmsg_client_sample_init(void)
{
return register_rpmsg_driver(&rpmsg_sample_client);
}
static void __exit rpmsg_client_sample_fini(void)
{
unregister_rpmsg_driver(&rpmsg_sample_client);
}
